#!/usr/bin/env python3
import argparse
import os
from pathlib import Path
import subprocess
import sys
import time
from typing import Iterable

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))

import SemcCameraUI.tools_Common.test_camera.uiagent_client as uiagent_client  # noqa: E402
import SemcCameraUI.tools_Common.test_camera.uiagent_instrumentation_client as uiagent_instrumentation_client  # noqa: E402
from SemcCameraUI.tools_Common.test_camera.key import (  # noqa: E402
    ClickTarget,
    load_click_targets,
)
from SemcCameraUI.tools_Common.test_camera.uiagent_client import (  # noqa: E402
    click_child_under_rid,
    click_if_exists,
    is_uiagent_installed,
    swipe,
    wait_exists,
    wait_exists_rid,
    wait_then_click,
)
from SemcCameraUI.tools_Common.test_camera.uiagent_instrumentation_client import (  # noqa: E402
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


def click_camera_mode(*, pick: str) -> bool:
    """
    切換 Sony 相機模式（拍照 / 錄影）。

    pick:
      - "left"  → 拍照模式
      - "right" → 錄影模式
    """
    rid = "com.sonyericsson.android.camera:id/application_navigator"
    wait_exists_rid(rid=rid)
    return click_child_under_rid(
        rid=rid,
        pick=pick,
        index=0,
    )


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
    print("啟動相機應用程式...")
    ADB.shell(
        "am start -a android.media.action.STILL_IMAGE_CAMERA -p com.sonyericsson.android.camera",
        check=True,
    )
    time.sleep(0.5)


def parse_args() -> argparse.Namespace:
    def mode_mapping(value):
        # 定義縮寫與完整名稱的對應表
        mapping = {
            "p": "photo",
            "v": "video",
            "s": "slow_motion",
            "sm": "slow_motion",
            "t": "test_t",
        }
        # 如果輸入在對應表中，回傳完整名稱；否則回傳原值讓 choices 檢查
        return mapping.get(value.lower(), value)

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
    parser.add_argument(
        "--mode",
        "-m",
        dest="mode",
        type=mode_mapping,  # argparse 會對傳入的每個值執行此函式
        nargs="+",  # 關鍵：允許輸入多個值，結果會存為 list
        choices=["photo", "video", "slow_motion", "test_t"],
        default=["photo", "video"],
        help="測試模式 (可多選): photo (p), video (v), slow_motion (s) (預設: photo video)",
    )
    return parser.parse_args()


def prepare_device() -> None:
    ADB.shell("input keyevent KEYCODE_WAKEUP", check=True)  # 喚醒裝置
    ADB.shell("wm dismiss-keyguard", check=True)  # 解鎖裝置


def ensure_uiagent_ready() -> None:
    ensure_uiagent_available()  # 確認 UiAgent 已安裝
    ensure_uiagent_accessibility_or_prompt()  # 確認無障礙服務已啟用


def reset_camera_state(click_targets: Iterable[ClickTarget]) -> None:
    print(f"清除 {CAMERA_PACKAGE_NAME} 的資料...")
    ADB.shell(f"pm clear {CAMERA_PACKAGE_NAME}", check=False)

    launch_camera()

    print("嘗試處理權限彈窗（按下允許）...")
    # 使用 UiAgentInstrumentationClient 方式
    client = UiAgentInstrumentationClient()
    client.start_instrumentation_service(background=True)
    try:
        # 等待權限對話框出現（最多 8 秒）
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
                time.sleep(0.4)
                continue
            if client.click_permission_button("allow_once"):
                time.sleep(0.4)
                continue
            if client.click_rid(
                "com.android.permissioncontroller:id/permission_allow_button"
            ):
                time.sleep(0.4)
                continue
            client.click_text("允許", exact=False)
            client.click_text("允許檔案存取", exact=False)
            time.sleep(0.4)
    finally:
        client.stop_instrumentation_service()


def stop_camera() -> None:
    ADB.shell(f"am force-stop {CAMERA_PACKAGE_NAME}", check=False)


def test_photo(click_map) -> None:
    """拍照測試流程。"""
    print("\n========== 開始拍照測試 ==========")
    global file_count

    # 確保在拍照模式
    click_camera_mode(pick="left")  # 切到拍照模式

    # 拍照
    print("拍照中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)
    wait_exists(click_map["模式"], timeout_ms=5000)
    result = has_saved(timeout_ms=3000)
    print(f"拍照結果: {result}")
    print("========== 拍照測試完成 ==========")


def test_video(click_map) -> None:
    """錄影測試流程。"""
    print("\n========== 開始錄影測試 ==========")
    global file_count

    # 切到錄影模式
    print("切到錄影模式...")
    click_camera_mode(pick="right")
    time.sleep(1)

    # 第一次錄影
    print("開始第一次錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)  # 開始錄影
    time.sleep(10)
    print("停止第一次錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=3000)  # 停止錄影
    time.sleep(3)
    result1 = has_saved(timeout_ms=3000)
    print(f"第一次錄影結果: {result1}")
    print()

    # 第二次錄影（測試是否卡住）
    print("開始第二次錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)  # 開始錄影
    time.sleep(10)
    print("停止第二次錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=3000)  # 停止錄影
    result2 = has_saved(timeout_ms=3000)
    print(f"第二次錄影結果: {result2}")
    print("========== 錄影測試完成 ==========")


def test_slow_motion(click_map) -> None:
    """慢動作測試流程：點模式 → 點慢動作 → 設定 → 選僅一次慢動作模式 → 按下拍照鍵 → 檢查檔案。"""
    global file_count
    print("\n========== 開始慢動作測試 ==========")

    print("切到慢動作模式...")
    print("切到僅一次...")
    wait_then_click(click_map["模式"], timeout_ms=2000)
    wait_then_click(click_map["慢動作"], timeout_ms=3000)
    # wait_then_click(click_map["跳過教學"], timeout_ms=2000)
    time.sleep(0.5)
    wait_then_click(click_map["設定"], timeout_ms=2000)
    wait_then_click(click_map["慢動作模式"], timeout_ms=2000)
    wait_then_click(click_map["慢動作僅一次"], timeout_ms=2000)

    # 拍照
    print("慢動作拍照中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)
    wait_exists(click_map["模式"], timeout_ms=5000)
    result = has_saved(timeout_ms=3000)
    拍照結果 = wait_exists(click_map["模式"], timeout_ms=5000)
    print(f"慢動作拍照結果: {result and 拍照結果}")
    print("========== 慢動作測試完成 ==========")


def test_t(click_map) -> None:
    wait_then_click(click_map["色彩和亮度"], timeout_ms=2000)
    print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
    print(f"Swipe: {swipe(540, 1365, 215, 1365)}")
    wait_then_click(click_map["關閉色彩和亮度調整"], timeout_ms=2000)

    wait_then_click(click_map["色彩和亮度"], timeout_ms=2000)
    print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
    print(f"Swipe: {swipe(540, 1365, 215, 1365)}")


def has_saved(timeout_ms: int = 3000, interval_ms: int = 200):
    """檢查是否有新照片儲存。"""
    global file_count
    deadline = time.monotonic() + timeout_ms / 1000.0

    while time.monotonic() < deadline:
        new_file_count = get_dcim_file_count()  # 記錄 /sdcard/DCIM/  檔案數量
        if new_file_count > file_count:
            file_count = new_file_count
            print(f"當前 DCIM 檔案數量: {file_count}")
            return True
        time.sleep(interval_ms / 1000.0)
    return False


def get_dcim_file_count() -> int:
    """取得 /sdcard/DCIM/ 下所有檔案數量，包含子資料夾。

    回傳整數（找不到資料夾或解析錯誤時回傳 0）。
    """
    # 使用 find 列出所有檔案並計數（在設備上執行）
    result = ADB.shell("find /sdcard/DCIM -type f | wc -l", check=False)
    stdout = (result.stdout or "").strip()
    if not stdout:
        return 0
    try:
        return int(stdout)
    except ValueError:
        print(f"警告：解析 DCIM 檔案數失敗，輸出: {stdout}")
        return 0


def main() -> None:
    global file_count
    global ADB
    args = parse_args()
    ADB = Adb(serial=args.device)

    # # 更新依賴的模塊中的 ADB 實例
    uiagent_client.ADB = ADB
    uiagent_instrumentation_client.ADB = ADB

    key_path = Path(__file__).parent / "key.json"  # load keys
    click_targets = load_click_targets(key_path)  # load click targets
    click_targets_map = {ct.key_name: ct for ct in click_targets}

    ensure_uiagent_ready()  # 確認 UiAgent 已安裝且無障礙服務已啟用
    stop_camera()  # 停止相機應用程式
    prepare_device()  # 喚醒並解鎖裝置
    if args.clear_data:
        reset_camera_state(click_targets)
    else:
        launch_camera()

    # 等待並點擊 SetupWizard 的「否」按鈕（如果存在）
    # wait_exists(click_targets_map["儲存地點否"], timeout_ms=500)
    click_if_exists(click_targets_map["儲存地點否"])

    wait_exists(
        click_targets_map["模式"], timeout_ms=7000
    )  # 等待模式按鈕出現，代表相機已準備好
    file_count = get_dcim_file_count()  # 記錄 /sdcard/DCIM/  檔案數量
    print(f"當前 DCIM 檔案數量: {file_count}")
    # 根據模式選擇測試流程
    if "photo" in args.mode:
        test_photo(click_targets_map)
    if "video" in args.mode:
        test_video(click_targets_map)
    if "slow_motion" in args.mode:
        test_slow_motion(click_targets_map)
    if "test_t" in args.mode:
        test_t(click_targets_map)

    print("\n測試完成！")
    # stop_camera()  # 停止相機應用程式


if __name__ == "__main__":
    main()
