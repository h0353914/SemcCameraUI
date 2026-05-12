from pathlib import Path
import shutil
import subprocess
from typing import Optional
from datetime import datetime


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

    # 全部都不行：優先回退到專案規範的 adb.exe（即使暫時看不到裝置）
    preferred_adb = "/mnt/f/Android/platform-tools/adb.exe"
    if Path(preferred_adb).exists():
        return preferred_adb

    # 再退回使用者指定（若有），不然交給 PATH 的 "adb"
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
            "wait-for-device",
        }

        if not self.serial and args and args[0] not in skip_device_check:
            serials = self.devices(timeout=10)
            if len(serials) == 0:
                raise SystemExit(
                    "ADB 錯誤：未偵測到任何已連線的裝置。\n請確認裝置已就緒"
                )

            elif len(serials) > 1:
                raise SystemExit(
                    "ADB 錯誤：偵測到多個裝置（more than one device/emulator）。\n"
                    f"目前可用裝置：{', '.join(serials)}\n"
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

    def wait_for_boot(
        self,
        *,
        timeout: int = 300,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """
        等到 sys.boot_completed 為 '1' 才返回。

        實作：先用 adb wait-for-device 確認基本的連線，
        再輪詢 getprop sys.boot_completed 直到值為 '1' 或 超時。

        參數：
            timeout: 最長等待秒數（預設 300 秒）
            check: 是否在超時時拋出異常

        回傳：
            最後一次 getprop 的執行結果（包含 returncode / stdout）
        """
        # 先等 wait-for-device（帳面timeout要夠大，因為boot期間會等很久）
        wait_result = self.run(["wait-for-device"], timeout=timeout, check=False)
        if wait_result.returncode != 0:
            if check:
                raise RuntimeError(
                    f"wait_for_device 失敗（可能是連線或超時）\n"
                    f"exit: {wait_result.returncode}"
                )
            return wait_result

        # 輪詢 boot_completed
        start = datetime.now()
        poll_interval = 3  # 每幾秒查一次

        while True:
            elapsed = (datetime.now() - start).total_seconds()
            if elapsed >= timeout:
                if check:
                    raise TimeoutError(f"等待 boot_completed 超時（{timeout} 秒）")
                break

            prop_result = self.shell(
                "getprop sys.boot_completed",
                timeout=10,
                check=False,
            )

            if prop_result.returncode == 0:
                value = (prop_result.stdout or "").strip()
                if value == "1":
                    # 完成，馬上返回最後結果
                    return prop_result

            # 還沒好，sleep 一下再查
            remaining = timeout - elapsed
            sleep_time = min(poll_interval, remaining)
            if sleep_time > 0:
                import time

                time.sleep(sleep_time)

        # timeout 時回傳最後一次 prop 結果（returncode非0 時才有意义）
        return prop_result

    def get_setting_secure(
        self,
        key: str,
        *,
        timeout: int = 10,
    ) -> str:
        """讀取 secure settings（等同 `settings get secure <key>`）"""
        p = self.shell(f"settings get secure {key}", timeout=timeout, check=False)
        return (p.stdout or "").strip()

    def root(
        self,
        *,
        timeout: int = 30,
        check: bool = False,
    ) -> subprocess.CompletedProcess[str]:
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

    def pull(
        self,
        remote: str,
        local: str,
        *,
        timeout: int = 120,
        check: bool = True,
    ) -> subprocess.CompletedProcess[str]:
        """adb pull <remote> <local>（從裝置拉取檔案到本地，二進位安全）"""
        p = self.run(["pull", remote, local], timeout=timeout, check=check)
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

    def get_device_mode(self) -> str:
        """偵測裝置模式（userdebug 或 user）。"""
        result = self.shell("getprop ro.build.type", check=False)
        build_type = (result.stdout or "").strip()

        return build_type or "user"

    # ============================================================
    # logcat 擷取
    # ============================================================

    def clear_logcat(self) -> None:
        """清除 logcat 緩衝區"""
        self.run(["logcat", "-c"], check=False)

    def start_log_capture(self, log_path: Path, *, extra_args: list[str] | None = None):
        cmd = self._base_cmd() + ["logcat", "-v", "threadtime"]

        if extra_args:
            cmd += extra_args

        log_file = log_path.open("w", encoding="utf-8")

        proc = subprocess.Popen(
            cmd,
            stdout=log_file,
            stderr=subprocess.STDOUT,
        )

        proc._log_file = log_file  # 綁定

        return proc

    @staticmethod
    def stop_log_capture(proc: subprocess.Popen[str]) -> None:
        if proc.poll() is None:
            proc.terminate()
            try:
                proc.wait(timeout=3)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait(timeout=3)

        # ✔ 關 log file
        log_file = getattr(proc, "_log_file", None)
        if log_file and not log_file.closed:
            log_file.close()

    def screenshot(
        self,
        save_path: Optional[str] = None,
        *,
        timeout: int = 30,
        check: bool = True,
    ) -> str:
        """
        擷取裝置螢幕截圖並儲存到本地檔案。

        參數：
            save_path: 儲存位置（絕對路徑或相對路徑）。
                     若不提供，預設儲存至 SemcCameraUI/.tmp/screenshot_<timestamp>.png
            timeout: 命令執行逾時（秒）
            check: 執行失敗時是否拋出異常

        回傳：
            儲存成功的檔案絕對路徑

        範例：
            adb_client.screenshot()  # 儲存至 .tmp/screenshot_<timestamp>.png
            adb_client.screenshot("/tmp/my_screenshot.png")  # 儲存至指定路徑
        """
        # 若未指定路徑，使用預設位置 SemcCameraUI/.tmp/screenshot_<timestamp>.png
        if not save_path:
            tmp_dir = Path(__file__).parent.parent / ".tmp"
            tmp_dir.mkdir(parents=True, exist_ok=True)
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S_%f")[:-3]
            save_path = str(tmp_dir / f"screenshot_{timestamp}.png")

        save_path_obj = Path(save_path)

        # 建立父目錄（若不存在）
        save_path_obj.parent.mkdir(parents=True, exist_ok=True)

        # 執行截圖命令，直接輸出二進制 PNG 數據
        try:
            result = self.exec_out(
                ["screencap", "-p"],
                timeout=timeout,
                check=False,
            )

            if result.returncode != 0:
                if check:
                    raise RuntimeError(
                        f"截圖失敗\n"
                        f"exit: {result.returncode}\n"
                        f"stderr:\n{result.stderr.strip()}"
                    )
                return ""

            # exec-out 回傳的是二進制數據（字串編碼方式）
            # 需要以二進制模式寫入
            if result.stdout:
                # 將 stdout 轉為字節，移除 CRLF 後寫入
                png_data = (
                    result.stdout.encode("latin1")
                    if isinstance(result.stdout, str)
                    else result.stdout
                )
                with open(save_path_obj, "wb") as f:
                    f.write(png_data)

                print(f"截圖已儲存：{save_path_obj.absolute()}")
                return str(save_path_obj.absolute())
            else:
                if check:
                    raise RuntimeError("截圖命令無輸出")
                return ""

        except subprocess.TimeoutExpired:
            if check:
                raise RuntimeError(f"截圖命令逾時（{timeout}秒）")
            return ""
