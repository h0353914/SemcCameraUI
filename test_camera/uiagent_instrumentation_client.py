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

ROOT = Path(__file__).resolve().parents[1]  # /home/h/lineageos/device/sony/SemcCameraUI
TEST_CAMERA_DIR = Path(__file__).resolve().parent  # /home/h/lineageos/device/sony/SemcCameraUI/test_camera
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(TEST_CAMERA_DIR))

from tools_Common.adb import Adb  # noqa: E402
from key import ClickTarget  # noqa: E402


class UiAgentInstrumentationClient:
    """UiAgent Instrumentation 客戶端"""

    INSTRUMENTATION_PACKAGE = "com.example.uiagent.uiautomation.test"
    INSTRUMENTATION_CLASS = (
        "com.example.uiagent.uiautomation.test.UiAutomationInstrumentation"
    )
    INSTRUMENTATION_RUNNER = "androidx.test.runner.AndroidJUnitRunner"
    ACTION_CMD = "com.example.uiagent.uiautomation.UIAUTOMATION_CMD"

    def __init__(self, adb: Adb):
        self.adb = adb
        self.instrumentation_process: Optional[subprocess.Popen] = None

    def start_instrumentation_service(self, background: bool = True) -> bool:
        """
        啟動 Instrumentation 測試服務（保持運行以接收命令）。

        Args:
            background: 是否在背景運行
        """
        print("啟動 Instrumentation 測試服務...")

        # 建構命令
        cmd = [self.adb.adb_path]
        if self.adb.serial:
            cmd += ["-s", self.adb.serial]
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
        self.adb.run(
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
        result = self.adb.run(args, check=True)
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

    def wait_exists(self, target: ClickTarget, timeout_ms: int = 3000) -> bool:
        """等待 ClickTarget 出現"""
        deadline = time.monotonic() + timeout_ms / 1000.0
        while time.monotonic() < deadline:
            if target.resource_id and self.exists_rid(target.resource_id):
                return True
            if target.text and self.exists_text(target.text):
                return True
            time.sleep(0.2)
        return False

    def wait_then_click(
        self,
        wait_target: ClickTarget,
        click_target: Optional[ClickTarget] = None,
        timeout_ms: int = 3000,
        raise_on_fail: bool = True,
    ) -> bool:
        """先等待 wait_target 出現，再點擊 click_target（若未指定則點擊 wait_target）"""
        if click_target is None:
            click_target = wait_target
        return_value = self.wait_exists(wait_target, timeout_ms=timeout_ms)
        print(f"等待 {wait_target.key_name} 出現?", return_value)
        if return_value:
            if click_target.resource_id:
                return_value = self.click_rid(click_target.resource_id)
            elif click_target.text:
                return_value = self.click_text(click_target.text)
            print(f"點擊{wait_target.key_name} {return_value}")
            return return_value
        if raise_on_fail:
            raise RuntimeError(f"❌ 目標未出現: {wait_target.key_name}, timeout={timeout_ms}ms")
        return False

    def click_permission_button(self, button_type: str) -> bool:
        """
        點擊權限對話框按鈕。

        Args:
            button_type: 按鈕類型 ("allow_foreground", "allow_once", "deny" 等)
        """
        buttons = self.find_permission_buttons()
        rid = buttons.get(button_type)
        if rid:
            return self.click_rid(rid)
        return False
