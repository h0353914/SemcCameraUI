#!/usr/bin/env python3
"""
UiAgent Instrumentation 客戶端 - 透過 Instrumentation/UiAutomation 存取系統權限對話框。

使用方式：
1. 啟動 Instrumentation 測試服務（保持運行）：
   python uiagent_instrumentation_client.py start

2. 發送命令：
   python uiagent_instrumentation_client.py list_elements
   python uiagent_instrumentation_client.py click_rid com.android.permissioncontroller:id/permission_allow_one_time_button

3. 停止服務：
   python uiagent_instrumentation_client.py stop
"""

from __future__ import annotations

import json
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Optional

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))

from SemcCameraUI.tools_Common.adb import Adb  # noqa: E402

ADB = Adb()


class UiAgentInstrumentationClient:
    """UiAgent Instrumentation 客戶端"""

    INSTRUMENTATION_PACKAGE = "com.example.uiagent.uiautomation.test"
    INSTRUMENTATION_CLASS = "com.example.uiagent.uiautomation.test.UiAutomationInstrumentation"
    INSTRUMENTATION_RUNNER = "androidx.test.runner.AndroidJUnitRunner"
    ACTION_CMD = "com.example.uiagent.uiautomation.UIAUTOMATION_CMD"

    def __init__(self):
        self.instrumentation_process: Optional[subprocess.Popen] = None

    def start_instrumentation_service(self, background: bool = True) -> bool:
        """
        啟動 Instrumentation 測試服務（保持運行以接收命令）。

        Args:
            background: 是否在背景運行
        """
        print("啟動 Instrumentation 測試服務...")

        # 建構命令
        cmd = [ADB.adb_path]
        if ADB.serial:
            cmd += ["-s", ADB.serial]
        cmd += [
            "shell",
            "am",
            "instrument",
            "-w",
            "-e",
            "class",
            f"{self.INSTRUMENTATION_CLASS}#startUiAutomationService",
            f"{self.INSTRUMENTATION_PACKAGE}/{self.INSTRUMENTATION_RUNNER}",
        ]

        if background:
            # 背景運行
            self.instrumentation_process = subprocess.Popen(
                cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )
            print("✓ Instrumentation 服務已在背景啟動")
            print("  行程 PID:", self.instrumentation_process.pid)

            # 等待服務啟動
            time.sleep(2)
            return True
        else:
            # 前台運行（阻塞）
            result = subprocess.run(cmd)
            return result.returncode == 0

    def stop_instrumentation_service(self):
        """停止 Instrumentation 測試服務"""
        if self.instrumentation_process:
            print("停止 Instrumentation 服務...")
            self.instrumentation_process.terminate()
            try:
                self.instrumentation_process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.instrumentation_process.kill()
            print("✓ 服務已停止")

        # 強制停止裝置上的 instrumentation
        ADB.run(
            ["shell", "am", "force-stop", self.INSTRUMENTATION_PACKAGE],
            check=False,
        )

    def send_command(self, cmd: str, **extras) -> dict:
        """
        發送命令到 Instrumentation 服務。

        Args:
            cmd: 命令名稱
            **extras: 額外參數

        Returns:
            dict: 命令回應
        """
        # 建構 broadcast 命令
        args = [
            "shell",
            "am",
            "broadcast",
            "-a",
            self.ACTION_CMD,
            "--es",
            "cmd",
            cmd,
        ]

        # 新增額外參數
        for key, value in extras.items():
            if isinstance(value, bool):
                args += ["--ez", key, str(value).lower()]
            elif isinstance(value, int):
                args += ["--ei", key, str(value)]
            else:
                args += ["--es", key, str(value)]

        # 發送命令
        result = ADB.run(args, check=True)
        output = result.stdout or ""

        # 解析回應
        match = re.search(r'data="(.*)"', output)
        if not match:
            return {"ok": False, "error": "no_response", "raw_output": output}

        try:
            return json.loads(match.group(1))
        except json.JSONDecodeError as e:
            return {"ok": False, "error": "invalid_json", "message": str(e)}

    def ping(self) -> bool:
        """測試連線"""
        resp = self.send_command("ping")
        return resp.get("ok", False)

    def list_elements(self) -> list[dict]:
        """列出所有 UI 元素（包括權限對話框）"""
        resp = self.send_command("list_elements")
        if not resp.get("ok"):
            return []
        return resp.get("elements", [])

    def find_permission_buttons(self) -> dict:
        """尋找權限對話框按鈕"""
        resp = self.send_command("find_permission_buttons")
        if not resp.get("ok"):
            return {}
        return resp.get("buttons", {})

    def exists_rid(self, rid: str) -> bool:
        """檢查 resource-id 是否存在"""
        resp = self.send_command("exists_rid", rid=rid)
        return resp.get("exists", False)

    def exists_text(self, text: str, exact: bool = True) -> bool:
        """檢查文字是否存在"""
        resp = self.send_command("exists_text", text=text, exact=exact)
        return resp.get("exists", False)

    def click_rid(self, rid: str) -> bool:
        """透過 resource-id 點擊"""
        resp = self.send_command("click_rid", rid=rid)
        return resp.get("clicked", False)

    def click_text(self, text: str, exact: bool = True) -> bool:
        """透過文字點擊"""
        resp = self.send_command("click_text", text=text, exact=exact)
        return resp.get("clicked", False)

    def click_permission_button(self, button_type: str) -> bool:
        """
        點擊權限對話框按鈕。

        Args:
            button_type: 按鈕類型
                - "allow" / "allow_foreground": 使用應用程式時
                - "allow_once": 僅允許這一次
                - "deny": 不允許
        """
        button_rids = {
            "allow": "com.android.permissioncontroller:id/permission_allow_foreground_only_button",
            "allow_foreground": "com.android.permissioncontroller:id/permission_allow_foreground_only_button",
            "allow_once": "com.android.permissioncontroller:id/permission_allow_one_time_button",
            "deny": "com.android.permissioncontroller:id/permission_deny_button",
        }

        rid = button_rids.get(button_type)
        if not rid:
            print(f"未知的按鈕類型: {button_type}")
            return False

        return self.click_rid(rid)


def main():
    """命令列介面"""
    import argparse

    parser = argparse.ArgumentParser(description="UiAgent Instrumentation 客戶端")
    subparsers = parser.add_subparsers(dest="command", help="命令")

    # start 命令
    start_parser = subparsers.add_parser("start", help="啟動 Instrumentation 服務")
    start_parser.add_argument(
        "--foreground", action="store_true", help="前台運行（阻塞）"
    )

    # stop 命令
    subparsers.add_parser("stop", help="停止 Instrumentation 服務")

    # ping 命令
    subparsers.add_parser("ping", help="測試連線")

    # list_elements 命令
    subparsers.add_parser("list_elements", help="列出所有 UI 元素")

    # find_buttons 命令
    subparsers.add_parser("find_buttons", help="尋找權限對話框按鈕")

    # click_rid 命令
    click_rid_parser = subparsers.add_parser("click_rid", help="透過 resource-id 點擊")
    click_rid_parser.add_argument("rid", help="resource-id")

    # click_text 命令
    click_text_parser = subparsers.add_parser("click_text", help="透過文字點擊")
    click_text_parser.add_argument("text", help="文字")

    # click_permission 命令
    click_perm_parser = subparsers.add_parser("click_permission", help="點擊權限按鈕")
    click_perm_parser.add_argument(
        "button",
        choices=["allow", "allow_once", "deny"],
        help="按鈕類型",
    )

    args = parser.parse_args()

    client = UiAgentInstrumentationClient()

    try:
        if args.command == "start":
            client.start_instrumentation_service(background=not args.foreground)

        elif args.command == "stop":
            client.stop_instrumentation_service()

        elif args.command == "ping":
            if client.ping():
                print("✓ 連線成功")
            else:
                print("✗ 連線失敗")

        elif args.command == "list_elements":
            elements = client.list_elements()
            print(f"找到 {len(elements)} 個元素：")
            for i, elem in enumerate(elements, 1):
                print(f"  {i}. rid={elem.get('rid', '')} text={elem.get('text', '')} desc={elem.get('desc', '')}")

        elif args.command == "find_buttons":
            buttons = client.find_permission_buttons()
            print(f"找到 {len(buttons)} 個權限按鈕：")
            for btn_type, info in buttons.items():
                print(f"  {btn_type}: {info.get('text')} ({info.get('rid')})")

        elif args.command == "click_rid":
            if client.click_rid(args.rid):
                print(f"✓ 成功點擊: {args.rid}")
            else:
                print(f"✗ 點擊失敗: {args.rid}")

        elif args.command == "click_text":
            if client.click_text(args.text):
                print(f"✓ 成功點擊: {args.text}")
            else:
                print(f"✗ 點擊失敗: {args.text}")

        elif args.command == "click_permission":
            if client.click_permission_button(args.button):
                print(f"✓ 成功點擊權限按鈕: {args.button}")
            else:
                print(f"✗ 點擊失敗: {args.button}")

        else:
            parser.print_help()

    except KeyboardInterrupt:
        print("\n使用者中斷")
        if args.command == "start":
            client.stop_instrumentation_service()


if __name__ == "__main__":
    main()
