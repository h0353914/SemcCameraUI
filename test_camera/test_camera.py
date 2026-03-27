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
            "st": "photo_settings",
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
        choices=["photo", "video", "slow_motion", "photo_settings"],
        default=["photo", "video", "slow_motion", "photo_settings"],
        help="測試模式 (可多選): photo (p), video (v), slow_motion (s), photo_settings (st) (預設: photo video)",
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
    # 同時停止 cameracommon，確保清除緩存的 cacao 會話狀態
    ADB.shell("am force-stop com.sonymobile.cameracommon", check=False)
    import time

    time.sleep(1)  # 等待 CacaoService 清理 client session


def is_camera_running() -> bool:
    """檢查相機app是否還在運行。"""
    result = ADB.shell(f"pidof {CAMERA_PACKAGE_NAME}", check=False)
    if not bool(result.stdout and result.stdout.strip()):
        sys.exit("⚠️ 無法檢測到相機app，請檢查是否閃退或未啟動。")


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

    deadline = time.monotonic() + timeout_ms / 1000
    success = False

    while time.monotonic() < deadline:
        new_count = get_dcim_file_count()
        print(f"當前 DCIM 檔案數量: {new_count}")

        if new_count > file_count:
            file_count = new_count
            success = True
            break  # 找到新檔案就算成功

        time.sleep(interval_ms / 1000)

    return success


def _check_ready_and_saved(click_map, save_timeout=3000) -> bool:
    """檢查模式是否恢復 + 檔案是否儲存，每次都掃描，結果有一次失敗就 False"""
    ready = wait_exists(click_map["模式"], timeout_ms=5000)
    print(f"模式按鈕恢復: {'✓' if ready else '✗'}")

    saved = has_saved(timeout_ms=save_timeout)
    result = ready and saved

    print(f"檢查結果: {result}")
    return result


def test_photo(click_map) -> bool:
    """拍照測試流程"""
    print("\n========== 開始拍照測試 ==========")
    global file_count

    click_camera_mode(pick="left")

    print("拍照中...")
    t_start = time.monotonic()

    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)
    result = _check_ready_and_saved(click_map)

    capture_latency_ms = (time.monotonic() - t_start) * 1000

    print(f"拍照結果: {result}")
    print(f"📊 拍照延遲: {capture_latency_ms:.0f}ms (快門到儲存完成)")
    print("========== 拍照測試完成 ==========")

    return result


def test_video(click_map) -> bool:
    """錄影測試流程"""
    print("\n========== 開始錄影測試 ==========")
    global file_count

    print("切到錄影模式...")
    click_camera_mode(pick="right")
    time.sleep(1)

    print("開始錄影...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)

    time.sleep(7)

    print("停止錄影...")
    t_start = time.monotonic()
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)

    result = _check_ready_and_saved(click_map)
    elapsed_ms = (time.monotonic() - t_start) * 1000

    print(f"錄影結果: {result}")
    print(f"📊 錄影總耗時 (含儲存): {elapsed_ms:.0f}ms")

    return result


def test_slow_motion(click_map) -> bool:
    """慢動作測試流程"""
    print("\n========== 開始慢動作測試 ==========")
    global file_count

    print("切到慢動作模式...")
    wait_then_click(click_map["模式"], timeout_ms=2000)
    wait_then_click(click_map["慢動作"], timeout_ms=5000)

    time.sleep(0.5)

    wait_then_click(click_map["設定"], timeout_ms=2000)
    wait_then_click(click_map["慢動作模式"], timeout_ms=2000)
    wait_then_click(click_map["慢動作僅一次"], timeout_ms=2000)

    print("第一次慢動作拍攝中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)

    result = _check_ready_and_saved(click_map)

    print(f"第一次慢動作拍攝結果: {result}")

    print("第二次慢動作拍攝中...")
    wait_then_click(click_map["拍照鍵"], timeout_ms=5000)

    result = _check_ready_and_saved(click_map)

    print(f"第二次慢動作拍攝結果: {result}")

    print("========== 慢動作測試完成 ==========")

    return result


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
    print("\n========== 開始測試設定選項 ==========")

    SLEEP_SHORT = 0.5  # 短暫等待時間

    if not wait_exists(click_map["錄影拍照切換"], timeout_ms=2000):
        wait_then_click(click_map["模式"], timeout_ms=2000)

    # 確保在拍照模式
    click_camera_mode(pick="left")  # 切到拍照模式
    wait_exists(click_map["模式"], timeout_ms=5000)

    # 點擊設定按鈕
    def open_settings():
        print("點擊設定...")
        wait_then_click(click_map["設定"], timeout_ms=2000)
        time.sleep(SLEEP_SHORT)

    open_settings()

    # 所有設定選項清單
    settings_check = [
        ("靜態影像尺寸", click_map.get("靜態影像尺寸")),
        ("預拍功能", click_map.get("預拍功能")),
        ("物件追蹤", click_map.get("物件追蹤")),
        ("自動拍攝", click_map.get("自動拍攝")),
        ("失真校正", click_map.get("失真校正")),
    ]

    result = True

    for name, target in settings_check:
        exists = wait_exists(target, timeout_ms=1500)

        if name == "靜態影像尺寸" and not exists:
            print("再次嘗試點擊設定...")
            open_settings()
            exists = wait_exists(target, timeout_ms=1500)

        print(f"  {name}\t: {'✓ 存在' if exists else '✗ 不存在'}")

        if not exists:
            result = False

    open_settings()  # 關閉設定

    print(f"設定選項測試結果: {result}")
    print("========== 測試設定選項完成 ==========")

    return result


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

    # [PERF] 測量相機啟動到 UI 就緒的時間
    t_launch = time.monotonic()
    ready = wait_exists(
        click_targets_map["模式"], timeout_ms=7000
    )  # 等待模式按鈕出現，代表相機已準備好
    t_ready = time.monotonic()
    startup_ms = (t_ready - t_launch) * 1000
    print(
        f"📊 相機啟動到 UI 就緒: {startup_ms:.0f}ms (模式按鈕出現{'✓' if ready else '✗'})"
    )

    if not ready:
        print("⚠️ 相機 UI 未就緒，模式按鈕未出現。")


    file_count = get_dcim_file_count()  # 記錄 /sdcard/DCIM/  檔案數量
    print(f"當前 DCIM 檔案數量: {file_count}")
    # 根據模式選擇測試流程
    result = True

    tests = {
        "photo": test_photo,
        "video": test_video,
        "photo_settings": test_photo_settings,
        "slow_motion": test_slow_motion,
    }

    for mode in args.mode:
        if result and mode in tests:
            is_camera_running()
            result = tests[mode](click_targets_map)
            print()

    print("\n測試結果: " + ("✅ 全部通過" if result else "❌ 有項目失敗"))
    # if not result:
    #     pass
    # click_targets_map("無法啟動相機")
    # stop_camera()  # 停止相機應用程式


if __name__ == "__main__":
    main()
