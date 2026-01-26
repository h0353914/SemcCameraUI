from pathlib import Path
import shutil
import subprocess
from typing import Optional


def resolve_adb_path(adb_arg: str, serial: Optional[str]) -> str:
    """
    挑一個「真的能用」的 adb。

    優先順序：
      1) 使用者指定 adb_arg（CLI --adb 或 env ADB）
      2) 常見 WSL Windows adb.exe：/mnt/f/Android/platform-tools/adb.exe
      3) PATH 內的 adb（shutil.which）
      4) /usr/bin/adb

    可用的定義：
      - 能跑 `adb devices` 且 returncode == 0
      - 未指定 serial：看到任一 "\tdevice"
      - 指定 serial：找到該序號且狀態含 device
    """

    def can_see_device(adb_path: str) -> bool:
        """這個 adb_path 是否能看見目標裝置（或任一裝置）。"""
        try:
            p = subprocess.run(
                [adb_path, "devices"],
                text=True,
                capture_output=True,
                timeout=5,
            )
        except Exception:
            return False

        if p.returncode != 0:
            return False

        # 只保留裝置列表（排除 "List of devices attached" 那行）
        device_lines = [
            ln.strip()
            for ln in p.stdout.splitlines()
            if ln.strip() and not ln.lower().startswith("list of devices")
        ]

        if serial:
            # 例：0123456789ABCDEF\tdevice
            return any(
                ln.startswith(serial + "\t") and "device" in ln.split()
                for ln in device_lines
            )

        return any("\tdevice" in ln for ln in device_lines)

    # 候選 adb（依優先順序）
    candidates: list[str] = [
        adb_arg,  # 可能是空字串
        "/mnt/f/Android/platform-tools/adb.exe",
        shutil.which("adb") or "",
        "/usr/bin/adb",
    ]

    seen: set[str] = set()
    for c in candidates:
        if not c or c in seen:
            continue
        seen.add(c)

        # 若是絕對路徑但檔案不存在，直接跳過（避免 subprocess 慢錯）
        if Path(c).is_absolute() and not Path(c).exists():
            continue

        if can_see_device(c):
            return c

    # 全部都不行：退回使用者指定（若有），不然就交給 PATH 的 "adb"
    return adb_arg or "adb"


class Adb:
    """薄封裝：自動帶上 adb 路徑 +（可選）-s serial，並統一錯誤輸出。

    當不提供 `adb_path`（或提供空字串）時，會呼叫 `resolve_adb_path("", serial)`
    以自動挑選可用的 adb 實作；否則直接使用提供的路徑。
    """

    def __init__(self, adb_path: Optional[str] = None, serial: Optional[str] = None):
        if not adb_path:
            adb_path = resolve_adb_path("", serial)
        self.adb_path = adb_path
        self.serial = serial

    def _base_cmd(self) -> list[str]:
        # adb [-s SERIAL]
        cmd = [self.adb_path]
        if self.serial:
            cmd += ["-s", self.serial]
        return cmd

    def _print_result(self, result: subprocess.CompletedProcess[str]) -> None:
        """自動打印 result 的 stdout 和 stderr"""
        if result.stdout:
            print(result.stdout.strip())
        if result.stderr:
            print(result.stderr.strip())

    def _parse_device_serials(self, output: str) -> list[str]:
        device_lines = [
            ln.strip()
            for ln in output.splitlines()
            if ln.strip() and not ln.lower().startswith("list of devices")
        ]
        serials: list[str] = []
        for ln in device_lines:
            parts = ln.split("\t")
            if parts:
                serial = parts[0].strip()
                if serial:
                    serials.append(serial)
        return serials

    def run(
        self, args: list[str], *, timeout: int = 60, check: bool = True
    ) -> subprocess.CompletedProcess[str]:
        """跑任意 adb 子命令，例如 run(['devices']) / run(['push', ...])"""
        skip_device_check = {
            "connect",
            "devices",
            "disconnect",
            "help",
            "kill-server",
            "start-server",
            "version",
        }

        if not self.serial and args and args[0] not in skip_device_check:
            serials = self.devices(timeout=10)
            if len(serials) != 1:
                raise SystemExit(
                    "ADB 錯誤：偵測到多個裝置（more than one device/emulator）。\n"
                    f"目前可用裝置：{', '.join(serials)}\n"
                    "請使用 --device / -d 指定序號後再重試，或先只保留一台裝置。"
                )

        cmd = self._base_cmd() + args
        result = subprocess.run(cmd, text=True, capture_output=True, timeout=timeout)

        if not check or result.returncode == 0:
            return result

        raise RuntimeError(
            "ADB command failed\n"
            f"exit: {result.returncode}\n"
            f"cmd: {' '.join(cmd)}\n"
            f"stdout:\n{result.stdout.strip()}\n"
            f"stderr:\n{result.stderr.strip()}"
        )

    def shell(
        self,
        command: str,
        *,
        timeout: int = 60,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb shell "<command>"（注意：這裡是單字串形式）"""
        return self.run(["shell", command], timeout=timeout, check=check)

    def exec_out(
        self,
        args: list[str],
        *,
        timeout: int = 60,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb exec-out <args...>（常用於抓螢幕/輸出不走 CRLF）"""
        return self.run(["exec-out", *args], timeout=timeout, check=check)

    def wait_for_device(
        self,
        *,
        timeout: int = 60,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb wait-for-device"""
        return self.run(["wait-for-device"], timeout=timeout, check=check)

    def get_setting_secure(
        self,
        key: str,
        *,
        timeout: int = 10,
    ) -> str:
        """讀取 secure settings（等同 `settings get secure <key>`）"""
        p = self.shell(f"settings get secure {key}", timeout=timeout, check=False)
        return (p.stdout or "").strip()

    def is_userdebug_or_eng(self, *, timeout: int = 5) -> bool:
        """判斷目前裝置是否為 userdebug / eng build"""
        p = self.shell("getprop ro.build.type", timeout=timeout, check=False)
        t = (p.stdout or "").strip().lower()
        return t in ("userdebug", "eng")

    def root(
        self,
        *,
        timeout: int = 30,
        check: bool = False,
    ) -> subprocess.CompletedProcess[str]:
        """只在 userdebug / eng 裝置上才嘗試 adb root"""
        if not self.is_userdebug_or_eng():
            # 模擬一個 CompletedProcess，保持呼叫端行為一致
            return subprocess.CompletedProcess(
                args=[self.adb_path, "root"],
                returncode=0,
                stdout="skip adb root (user build)\n",
                stderr="",
            )

        p = self.run(["root"], timeout=timeout, check=check)
        self._print_result(p)
        return p

    def remount(
        self,
        *,
        timeout: int = 30,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb remount（重新掛載 /system 為可寫）"""
        p = self.run(["remount"], timeout=timeout, check=check)
        self._print_result(p)
        return p

    def reboot(
        self,
        target: str = "",
        *,
        timeout: int = 30,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb reboot [target]（重啟裝置，target 可為 bootloader / recovery / ""）"""
        args = ["reboot"]
        if target:
            args.append(target)
        p = self.run(args, timeout=timeout, check=check)
        self._print_result(p)
        return p

    def push(
        self,
        local: str,
        remote: str,
        *,
        timeout: int = 120,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb push <local> <remote>（推送本地檔案到裝置）"""
        p = self.run(["push", local, remote], timeout=timeout, check=check)
        self._print_result(p)
        return p

    def devices_result(
        self,
        *,
        timeout: int = 10,
        check: bool = True,
        print_output: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """執行 adb devices，回傳原始結果"""
        result = self.run(["devices"], timeout=timeout, check=check)
        if print_output:
            self._print_result(result)
        return result

    def devices(
        self,
        *,
        timeout: int = 10,
    ) -> list[str]:
        """回傳目前已連線裝置的序號列表"""
        result = self.devices_result(timeout=timeout, print_output=False)
        return self._parse_device_serials(result.stdout)

    def sha1sum(self, remote_path: str) -> str:
        """在裝置上計算檔案的 SHA1（使用 `sha1sum` 命令）"""
        p = self.shell(f"sha1sum {remote_path}", check=False)
        if p.returncode != 0:
            return ""
        # sha1sum 輸出格式：<sha1>  /<path>
        return p.stdout.strip().split()[0]
