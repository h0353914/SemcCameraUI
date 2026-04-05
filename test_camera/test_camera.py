#!/usr/bin/env python3
import argparse
import os
from pathlib import Path
import re
import subprocess
import sys
import threading
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

import uiagent_client as uiagent_client  # noqa: E402
import uiagent_instrumentation_client as uiagent_instrumentation_client  # noqa: E402
from key import (  # noqa: E402
    load_click_targets,
)
from uiagent_client import (  # noqa: E402
    click,
    click_child_under_rid,
    exists,
    is_uiagent_installed,
    wait_exists,
    wait_then_click,
)
from uiagent_instrumentation_client import (  # noqa: E402
    UiAgentInstrumentationClient,
)
from SemcCameraUI.tools_Common.adb import Adb  # noqa: E402


UI_AGENT_DIR = Path(__file__).resolve().parents[1] / "UiAgentService"
UI_AGENT_APK = (
    UI_AGENT_DIR / "app" / "build" / "outputs" / "apk" / "debug" / "app-debug.apk"
)
ANDROID_SDK = Path.home() / "Android" / "Sdk"
UIAGENT_ACCESSIBILITY_COMPONENT = (
    "com.example.uiagent/com.example.uiagent.UiAgentAccessibilityService"
)
CAMERA_PACKAGE_NAME = "com.sonyericsson.android.camera"


def build_uiagent() -> None:
    print("UiAgentService APK 不存在，開始編譯...")
    env = os.environ.copy()
    env["ANDROID_HOME"] = str(ANDROID_SDK)
    env["ANDROID_SDK_ROOT"] = str(ANDROID_SDK)

    subprocess.run(
        ["./gradlew", ":app:assembleDebug"],
        cwd=UI_AGENT_DIR,
        env=env,
        check=True,
    )


def install_uiagent() -> None:
    print("正在安裝 UiAgentService...")
    ADB.run(["install", "-r", str(UI_AGENT_APK)])


def ensure_uiagent_available() -> None:
    if is_uiagent_installed():
        return

    if not UI_AGENT_APK.exists():
        build_uiagent()

    if not UI_AGENT_APK.exists():
        raise FileNotFoundError(f"無法找到 {UI_AGENT_APK}")

    install_uiagent()


def ensure_uiagent_accessibility_or_prompt() -> None:
    component = UIAGENT_ACCESSIBILITY_COMPONENT

    enabled_flag = ADB.get_setting_secure("accessibility_enabled")
    services = ADB.get_setting_secure("enabled_accessibility_services")

    enabled_flag = (enabled_flag or "").strip()
    services = (services or "").strip()
    services_norm = "" if (not services or services.lower() == "null") else services
    parts = [p for p in services_norm.split(":") if p]

    is_enabled = enabled_flag == "1"
    in_services = component in parts

    if is_enabled and in_services:
        return

    print("⚠️ UiAgent 無障礙服務尚未啟用，請手動開啟。")

    # 方便：直接跳到無障礙設定頁（不保證所有 ROM 都一樣，但通常可用）
    ADB.shell("am start -a android.settings.ACCESSIBILITY_SETTINGS", check=False)

    # 直接中止，避免後面 exists/click 沒作用讓你誤判
    raise SystemExit("")


def launch_camera() -> None:
    """Launch the stock Sony camera app so we can interact with its UI."""
    print("啟動相機應用程式...\n")
    ADB.shell(
        "am start -a android.media.action.STILL_IMAGE_CAMERA -p com.sonyericsson.android.camera",
        check=True,
    )
    time.sleep(0.5)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Automate taking a photo with the stock camera app."
    )
    parser.add_argument(
        "--clear-data",
        "-c",
        dest="clear_data",
        action="store_true",
        help="Clear the camera app data before interacting with it (default: do nothing).",
    )
    parser.add_argument(
        "--device",
        "-d",
        dest="device",
        type=str,
        help="Specify the device serial number to connect to (optional).",
    )

    def mode_mapping(value):
        # 定義縮寫與完整名稱的對應表
        mapping = {
            "p": "photo",
            "v": "video",
            "s": "slow_motion",
            "sm": "slow_motion",
            "st": "photo_settings",
        }
        # 如果輸入在對應表中，回傳完整名稱；否則回傳原值讓 choices 檢查
        return mapping.get(value.lower(), value)

    parser.add_argument(
        "--mode",
        "-m",
        dest="mode",
        type=mode_mapping,  # argparse 會對傳入的每個值執行此函式
        nargs="+",  # 關鍵：允許輸入多個值，結果會存為 list
        choices=["photo", "video", "slow_motion", "photo_settings"],
        default=["photo", "video", "slow_motion", "photo_settings"],
        help="測試模式 (可多選): photo (p), video (v), slow_motion (s), photo_settings (st), photo_stability (ps) (預設: photo video)",
    )

    def positive_int(value):
        ivalue = int(value)
        if ivalue < 1:
            raise argparse.ArgumentTypeError("次數必須 >= 1")
        return ivalue

    parser.add_argument(
        "--count",  # 長參數
        "-n",  # 短參數
        dest="count",  # 存放在 args.count
        type=positive_int,
        default=1,
        help="測試運行次數 (>=1，預設: 1)",
    )
    parser.add_argument(
        "--force_stop",  # 長參數
        "-f",  # 短參數
        dest="force_stop",  # 存放在 args.force_stop
        default=False,
        action="store_true",
        help="強制停止相機應用程式 (預設: False)",
    )
    parser.add_argument(
        "--interval",
        "-t",
        type=float,
        default=0,
        help="每次測試之間的間隔秒數，預設 0 秒",
    )
    return parser.parse_args()


def prepare_device() -> None:
    ADB.shell("input keyevent KEYCODE_WAKEUP", check=True)  # 喚醒裝置
    ADB.shell("wm dismiss-keyguard", check=True)  # 解鎖裝置


def ensure_uiagent_ready() -> None:
    ensure_uiagent_available()  # 確認 UiAgent 已安裝
    ensure_uiagent_accessibility_or_prompt()  # 確認無障礙服務已啟用


def reset_camera_state() -> None:
    print(f"清除 {CAMERA_PACKAGE_NAME} 的資料...")
    ADB.shell(f"pm clear {CAMERA_PACKAGE_NAME}", check=False)


def handle_permission_dialog():
    """處理相機權限彈窗，嘗試點擊允許"""

    print("嘗試處理權限彈窗（按下允許）...")
    client = UiAgentInstrumentationClient()
    client.start_instrumentation_service(background=True)
    try:
        deadline = time.monotonic() + 4
        while time.monotonic() < deadline:
            if client.exists_rid(
                "com.android.permissioncontroller:id/permission_allow_foreground_only_button"
            ):
                break
            if client.exists_rid(
                "com.android.permissioncontroller:id/permission_allow_one_time_button"
            ):
                break
            if client.exists_rid(
                "com.android.permissioncontroller:id/permission_allow_button"
            ):
                break
            time.sleep(0.3)

        for _ in range(5):
            if client.click_permission_button("allow_foreground"):
                continue
            if client.click_permission_button("allow_once"):
                continue
            if client.click_rid(
                "com.android.permissioncontroller:id/permission_allow_button"
            ):
                continue
            client.click_text("允許", exact=False)
            client.click_text("允許檔案存取", exact=False)
    finally:
        # 非同步停止
        threading.Thread(
            target=client.stop_instrumentation_service, daemon=True
        ).start()


def stop_camera(force_stop=False) -> None:
    print("停止相機應用程式...")
    if force_stop:
        clear_all_task_stacks()
    else:
        ADB.shell(f"am force-stop {CAMERA_PACKAGE_NAME}", check=False)
    time.sleep(0.5)  # 等待 CacaoService 清理 client session


def clear_all_task_stacks() -> None:
    """清理所有後台 task stack"""
    result = ADB.shell("am stack list", check=False)
    stdout = (result.stdout or "").strip()

    if not stdout:
        return

    # 解析 taskId= 的值
    task_ids = re.findall(r"taskId=(\d+)", stdout)

    if not task_ids:
        return

    # 移除每個 task stack
    for task_id in task_ids:
        ADB.shell(f"am stack remove {task_id}", check=False)


def get_dcim_file_count() -> int:
    """取得 /sdcard/DCIM/ 下所有檔案數量，包含子資料夾"""
    result = ADB.shell("find /sdcard/DCIM -type f | wc -l", check=False)
    stdout = (result.stdout or "").strip()
    if not stdout:
        return 0
    try:
        return int(stdout)
    except ValueError:
        print(f"警告：解析 DCIM 檔案數失敗，輸出: {stdout}")
        return 0


def has_saved(timeout_ms: int = 3000, interval_ms: int = 200) -> bool:
    """檢查 DCIM 是否新增檔案，每次掃描都印出數量，找到新檔案就 True"""
    global file_count
    print(f"當前 DCIM 檔案數量: {file_count}")
    deadline = time.monotonic() + timeout_ms / 1000
    success = False

    while time.monotonic() < deadline:
        new_count = get_dcim_file_count()

        if new_count > file_count:
            file_count = new_count
            success = True
            print(f"當前 DCIM 檔案數量: {new_count}")
            break
        time.sleep(interval_ms / 1000)

    return success


def click_camera_mode(click_map, *, mod: str) -> bool:
    """
    切換 Sony 相機模式（拍照 / 錄影）。

    mod:
      - "p" → 拍照模式
      - "v" → 錄影模式
    """
    pick_map = {
        "p": "left",
        "v": "right",
    }
    pick = pick_map.get(mod.lower(), mod)

    滑塊 = click_map["錄影拍照滑塊"]
    if not wait_exists(滑塊, timeout_ms=2000):
        if exists(click_map["關閉色彩和亮度調整"]):
            click(click_map["關閉色彩和亮度調整"])
        else:
            open_settings(click_map)
            if wait_exists(click_map["慢動作模式"], timeout_ms=1000):
                wait_then_click(click_map["模式"], timeout_ms=2000)
    time.sleep(0.1)
    return click_child_under_rid(
        rid=滑塊.resource_id,
        pick=pick,
        index=0,
    )


def open_settings(click_map):
    print("點擊設定...")
    wait_then_click(click_map["設定"], timeout_ms=2000)
    time.sleep(0.5)


def test_photo(click_map) -> bool:
    """拍照測試流程"""
    print("切到拍照模式...")
    click_camera_mode(click_map, mod="p")  # 切到拍照模式

    print("拍照中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)


def test_video(click_map) -> bool:
    """錄影測試流程"""
    print("切到錄影模式...")
    click_camera_mode(click_map, mod="v")  # 切到錄影模式

    time.sleep(1)
    print("開始錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)

    time.sleep(7)
    print("停止錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)


def test_slow_motion(click_map) -> bool:
    """慢動作測試流程"""
    print("切到慢動作模式...")
    wait_then_click(click_map["模式"], timeout_ms=2000)
    wait_then_click(click_map["慢動作"], timeout_ms=5000)
    time.sleep(0.5)
    open_settings(click_map)
    if not wait_then_click(click_map["慢動作模式"], timeout_ms=2000):
        print("❌ 慢動作模式不存在，程式終止。")
        return
    wait_then_click(click_map["慢動作僅一次"], timeout_ms=2000)

    print("第一次慢動作拍攝中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)


# def test_t(click_map) -> bool:
#     """色彩與亮度滑動測試"""
#     wait_then_click(click_map["色彩和亮度"], timeout_ms=2000)

#     print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
#     print(f"Swipe: {swipe(540, 1365, 215, 1365)}")

#     wait_then_click(click_map["關閉色彩和亮度調整"], timeout_ms=2000)

#     wait_then_click(click_map["色彩和亮度"], timeout_ms=2000)

#     print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
#     print(f"Swipe: {swipe(540, 1365, 215, 1365)}")

#     return True


def test_photo_settings(click_map) -> bool:
    """測試拍照設定是否存在"""
    click_camera_mode(click_map, mod="p")  # 切到拍照模式
    open_settings(click_map)  # 點擊設定按鈕

    # 所有設定選項清單
    settings_check = [
        ("靜態影像尺寸", click_map["靜態影像尺寸"]),
        ("預拍功能", click_map["預拍功能"]),
        ("物件追蹤", click_map["物件追蹤"]),
        ("自動拍攝", click_map["自動拍攝"]),
        ("失真校正", click_map["失真校正"]),
    ]

    result = True
    for name, target in settings_check:
        exists = wait_exists(target, timeout_ms=1500)

        if name == "靜態影像尺寸" and not exists:
            print("再次嘗試點擊設定...")
            open_settings(click_map)
            exists = wait_exists(target, timeout_ms=1500)

        print(f"  {name}\t: {'✓ 存在' if exists else '✗ 不存在'}")

        if not exists:
            result = False

    open_settings(click_map)  # 關閉設定

    return result


def check_camera_running() -> None:
    """
    檢查相機是否正在運行。
    若未運行則直接退出程式。
    """
    result = ADB.shell(f"pidof {CAMERA_PACKAGE_NAME}", check=False)
    if not bool(result.stdout and result.stdout.strip()):
        raise RuntimeError("無法檢測到相機app正在運行 ❌")


def check_camera_ui(click_map, *, timeout_ms=6000) -> None:
    """
    同時非阻塞等待錯誤對話框與模式按鈕。
    發現錯誤先記錄，最後統一處理。
    """
    errors = []
    start_time = time.time()
    timeout_s = timeout_ms / 1000.0

    found_error = False
    found_mode = False

    while time.time() - start_time < timeout_s:
        # 檢查錯誤對話框
        if not found_error and wait_exists(click_map["錯誤"], timeout_ms=0):
            errors.append("發現錯誤對話框，程式終止 ❌")
            found_error = True

        # 檢查模式按鈕
        if not found_mode and wait_exists(click_map["模式"], timeout_ms=0):
            found_mode = True

        # 如果兩個都檢查完，就提前結束迴圈
        if found_error and found_mode:
            break

    # 超時後仍未找到模式按鈕
    if not found_mode:
        errors.append("模式按鈕未出現，UI 可能未回覆或初始化異常，程式終止 ❌")

    if errors:
        raise RuntimeError(f"\n{'\n'.join(errors)}")


def get_click_map():
    key_path = Path(__file__).parent / "key.json"  # load keys
    click_targets = load_click_targets(key_path)  # load click targets
    click_map = {ct.key_name: ct for ct in click_targets}
    return click_map


def countdown(total_seconds):
    while total_seconds > 0:
        print(f"等待{total_seconds:.1f} 秒", end="\r")
        time.sleep(0.1)  # 固定每 0.1 秒
        total_seconds -= 0.1


def run_camera_test_flow(args, tests, click_map):
    if args.clear_data:
        reset_camera_state()
    stop_camera(args.force_stop)  # 停止相機應用程式
    launch_camera()  # 啟動相機應用程式

    if args.clear_data:
        handle_permission_dialog()  # 處理權限彈窗

    # 手動啟動相機會出現 "儲存地點否" 腳本啟動相機不會出現。

    try:
        check_camera_running()
        check_camera_ui(click_map, timeout_ms=2000)
    except RuntimeError as e:
        print(f"初始化失敗: {e}")
        return False
    
    for mode in args.mode:
        result = True
        cfg = tests[mode]
        print(f"========== 開始{cfg['name']}測試 ========== ")
        try:
            t_start = time.monotonic()

            test_ok = cfg["func"](click_map)
            if cfg["check_saved"]:  # photo_settings 模式不測試儲存
                result = has_saved()
            else:
                result = test_ok

            elapsed = time.monotonic() - t_start
            label = "儲存" if cfg["check_saved"] else ""
            if result:
                print(f"{label}結果: ✅ (耗時: {elapsed:.2f}s)")
            else:
                raise RuntimeError(f"{label}結果: ❌")
        except RuntimeError as e:
            print(f"模式 {mode} {e}")
            result = False

        try:
            check_camera_running()
            check_camera_ui(click_map)
        except RuntimeError as e:
            print(f"模式 {mode} {e}")
            result = False

        print(f"========== 結束 {cfg['name']} 測試 ==========")
        if not result:
            return False
    
    return result


def main() -> None:
    global file_count
    global ADB
    args = parse_args()
    ADB = Adb(serial=args.device)

    # # 更新依賴的模塊中的 ADB 實例
    uiagent_client.ADB = ADB
    uiagent_instrumentation_client.ADB = ADB

    tests = {
        "photo": {
            "func": test_photo,
            "name": "拍照",
            "check_saved": True,
        },
        "video": {
            "func": test_video,
            "name": "錄影",
            "check_saved": True,
        },
        "photo_settings": {
            "func": test_photo_settings,
            "name": "拍照設定選項",
            "check_saved": False,
        },
        "slow_motion": {
            "func": test_slow_motion,
            "name": "慢動作",
            "check_saved": True,
        },
    }

    click_map = get_click_map()
    ensure_uiagent_ready()  # 確認 UiAgent 已安裝且無障礙服務已啟用
    # stop_camera(args.force_stop)  # 停止相機應用程式
    prepare_device()  # 喚醒並解鎖裝置

    file_count = get_dcim_file_count()  # 記錄 /sdcard/DCIM/  檔案數量
    print(f"當前 DCIM 檔案數量: {file_count}")

    n = args.count
    for n in range(args.count):
        print("-" * 10, "開始第", n + 1, "輪測試", "-" * 10)
        if not run_camera_test_flow(args, tests, click_map):
            print(f"第 {n + 1} 輪測試結果: 失敗 ❌ ")
            sys.exit(1)
        print(f"第 {n + 1} 輪測試結果: 通過 ✅ ")
        print()
        countdown(args.interval)

    print("🎉 所有測試完成，結果: 通過 ✅ ")


if __name__ == "__main__":
    main()
