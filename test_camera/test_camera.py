#!/usr/bin/env python3
import argparse
from pathlib import Path
import re
import sys
import threading
import time

ROOT = Path(__file__).resolve().parents[1]  # /home/h/lineageos/device/sony/SemcCameraUI
TEST_CAMERA_DIR = Path(__file__).resolve().parent  # ./test_camera
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(TEST_CAMERA_DIR))

import uiagent_client as uiagent_client  # noqa: E402
import uiagent_instrumentation_client as uiagent_instrumentation_client  # noqa: E402
from key import (  # noqa: E402
    load_click_targets,
)
from uiagent_client import (  # noqa: E402
    ClickFailedError,
    WaitTargetNotFoundError,
    click_child_under_rid,
    query_elements,
    wait_exists,
    wait_then_click,
)
from uiagent_instrumentation_client import (  # noqa: E402
    UiAgentInstrumentationClient,
)
from tools_Common.adb import Adb  # noqa: E402


CAMERA_PACKAGE_NAME = "com.sonyericsson.android.camera"


def ensure_uiagent_ready(adb: Adb) -> None:

    component = "com.example.uiagent/com.example.uiagent.UiAgentAccessibilityService"

    enabled_flag = adb.get_setting_secure("accessibility_enabled")
    services = adb.get_setting_secure("enabled_accessibility_services")

    is_enabled = enabled_flag == "1"
    in_services = services and component in services.split(":")

    if is_enabled and in_services:
        return

    print("⚠️ UiAgent 無障礙服務尚未安裝或是啟用，請安裝或是啟用。")
    # 直接中止，避免後面 exists/click 沒作用讓你誤判
    raise SystemExit("")


def launch_camera(adb: Adb) -> None:
    """Launch the stock Sony camera app so we can interact with its UI."""
    print("啟動相機應用程式...\n")
    adb.shell(
        "am start -a android.media.action.STILL_IMAGE_CAMERA -p com.sonyericsson.android.camera",
        check=True,
    )
    time.sleep(0.5)


def parse_args(tests) -> argparse.Namespace:
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

    def build_help(tests, default):
        parts = []
        for test in tests:
            alias = tests[test]["alias"]
            if alias:
                parts.append(f"{test} ({alias})")
            else:
                parts.append(test)

        modes_str = ", ".join(parts)
        default_str = " ".join(default)
        return f"測試模式 (可多選): {modes_str} (預設: {default_str})"

    def mode_mapping(value):
        value = value.lower()
        for test in tests:
            if value == test or value == tests[test]["alias"]:
                return test
        return value  # 讓 argparse 的 choices 來處理錯誤提示

    choices = list(tests.keys())
    default = choices.copy()
    parser.add_argument(
        "--mode",
        "-m",
        dest="mode",
        type=mode_mapping,  # argparse 會對傳入的每個值執行此函式
        nargs="+",  # 關鍵：允許輸入多個值，結果會存為 list
        choices=choices,
        default=default,
        help=build_help(tests, default),
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


def prepare_device(adb: Adb) -> None:
    adb.shell("input keyevent KEYCODE_WAKEUP", check=True)  # 喚醒裝置
    adb.shell("wm dismiss-keyguard", check=True)  # 解鎖裝置


def reset_camera_state(adb: Adb) -> None:
    print(f"清除 {CAMERA_PACKAGE_NAME} 的資料...")
    adb.shell(f"pm clear {CAMERA_PACKAGE_NAME}", check=False)


def handle_permission_dialog(adb: Adb, click_map) -> None:
    """處理相機權限彈窗，嘗試點擊允許"""

    print("嘗試處理權限彈窗（按下允許）...")
    client = UiAgentInstrumentationClient(adb)
    client.start_instrumentation_service(background=True)

    try:
        if not client.wait_then_click(click_map["使用期間允許"], raise_on_fail=False):
            return
        client.wait_then_click(click_map["使用期間允許"])
        if not client.wait_then_click(
            click_map["允許檔案存取"], timeout_ms=1000, raise_on_fail=False
        ):
            client.wait_then_click(click_map["全部允許"], raise_on_fail=False)
    finally:
        threading.Thread(
            target=client.stop_instrumentation_service, daemon=True
        ).start()


def stop_camera(adb: Adb, force_stop=False) -> None:
    print("停止相機應用程式...")
    if force_stop:
        clear_all_task_stacks(adb)
    else:
        adb.shell(f"am force-stop {CAMERA_PACKAGE_NAME}", check=False)
    time.sleep(0.5)  # 等待 CacaoService 清理 client session


def clear_all_task_stacks(adb: Adb) -> None:
    """清理所有後台 task stack"""
    result = adb.shell("am stack list", check=False)
    stdout = (result.stdout or "").strip()

    if not stdout:
        return

    # 解析 taskId= 的值
    task_ids = re.findall(r"taskId=(\d+)", stdout)

    if not task_ids:
        return

    # 移除每個 task stack
    for task_id in task_ids:
        adb.shell(f"am stack remove {task_id}", check=False)


def get_dcim_file_count(adb: Adb) -> int:
    """取得 /sdcard/DCIM/ 下所有檔案數量，包含子資料夾"""
    result = adb.shell("find /sdcard/DCIM -type f | wc -l", check=False)
    stdout = (result.stdout or "").strip()
    if not stdout:
        return 0
    try:
        return int(stdout)
    except ValueError:
        print(f"警告：解析 DCIM 檔案數失敗，輸出: {stdout}")
        return 0


def has_saved(adb: Adb, timeout_ms: int = 5000, interval_ms: int = 200) -> bool:
    """檢查 DCIM 是否新增檔案，每次掃描都印出數量，找到新檔案就 True"""
    global file_count
    print(f"當前 DCIM 檔案數量: {file_count}")
    deadline = time.monotonic() + timeout_ms / 1000
    success = False

    while time.monotonic() < deadline:
        new_count = get_dcim_file_count(adb)

        if new_count > file_count:
            file_count = new_count
            success = True
            print(f"當前 DCIM 檔案數量: {new_count}")
            break
        time.sleep(interval_ms / 1000)

    return success


def ensure_camera_mode_ui(adb: Adb, click_map):
    # 嘗試切換回照相錄影模式，因為慢動作模式下沒有拍照錄影滑塊
    if wait_then_click(
        adb, click_map["關閉色彩和亮度調整"], timeout_ms=0, raise_on_fail=False
    ):
        return

    open_settings(adb, click_map)

    if wait_exists(adb, click_map["慢動作模式"], timeout_ms=1000, raise_on_fail=False):
        wait_then_click(adb, click_map["模式"], timeout_ms=2000)


def click_camera_mode(adb: Adb, click_map, *, mod: str) -> bool:
    pick = {"p": "left", "v": "right"}.get(mod.lower(), mod)
    滑塊 = click_map["錄影拍照滑塊"]

    if not wait_exists(
        adb, 滑塊, timeout_ms=2000, raise_on_fail=False
    ):  # 如果滑塊不存在
        ensure_camera_mode_ui(adb, click_map)  # 嘗試切換回照相錄影模式

    time.sleep(0.1)
    return click_child_under_rid(adb, 滑塊.resource_id, pick=pick, index=0)


def open_settings(adb: Adb, click_map, timeout_ms=3000) -> None:
    print("點擊設定...")

    start_time = time.time()
    timeout_s = timeout_ms / 1000
    last_error = None
    while time.time() - start_time < timeout_s:
        try:
            wait_then_click(adb, click_map["設定"], timeout_ms=0)
            wait_exists(adb, click_map["一般設定"], timeout_ms=0)
            return
        except WaitTargetNotFoundError as e:
            print("無法偵測到設定，重試...")
            last_error = e
        except ClickFailedError as e:
            print("點擊設定失敗，重試...")
            last_error = e
        time.sleep(0.1)

    if last_error:
        raise last_error
    raise RuntimeError(f"開啟設定失敗（無明確例外），timeout={timeout_ms}ms")


def test_photo(adb: Adb, click_map) -> bool:
    """拍照測試流程"""
    print("切到拍照模式...")
    click_camera_mode(adb, click_map, mod="p")  # 切到拍照模式

    print("拍照中...")
    wait_then_click(adb, click_map["拍照鍵"], timeout_ms=5000)


def test_video(adb: Adb, click_map) -> bool:
    """錄影測試流程"""
    print("切到錄影模式...")
    click_camera_mode(adb, click_map, mod="v")  # 切到錄影模式

    time.sleep(1)
    print("開始錄影...")
    wait_then_click(adb, click_map["拍照鍵"], timeout_ms=5000)

    time.sleep(7)
    print("停止錄影...")
    wait_then_click(adb, click_map["拍照鍵"], timeout_ms=5000)


def dismiss_tutorial(adb: Adb, click_map) -> None:
    """嘗試關閉教學頁面（跳過教學或知道了）"""
    if wait_exists(adb, click_map["跳過教學"], timeout_ms=2000, raise_on_fail=False):
        print("跳過教學...")
        wait_then_click(adb, click_map["跳過教學"], timeout_ms=1000)
        time.sleep(0.3)
    elif wait_exists(adb, click_map["知道了"], timeout_ms=500, raise_on_fail=False):
        print("點擊知道了...")
        wait_then_click(adb, click_map["知道了"], timeout_ms=1000)
        time.sleep(0.3)


def test_slow_motion(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""
    # results = query_elements(click_map["慢動作"].resource_id)#慢動作模式判斷
    # Text = (results[0].text if results else "") or ""

    print("切到慢動作模式...")
    wait_then_click(adb, click_map["模式"], timeout_ms=3000)
    wait_then_click(adb, click_map["慢動作"], timeout_ms=5000)
    time.sleep(0.5)

    dismiss_tutorial(adb, click_map)

    open_settings(adb, click_map)
    try:
        wait_then_click(adb, click_map["慢動作模式"], timeout_ms=3000)
    except WaitTargetNotFoundError as e:
        print(f"{e} 慢動作模式不存在")
        return

    wait_then_click(adb, click_map["慢動作僅一次"], timeout_ms=3000)

    dismiss_tutorial(adb, click_map)

    print("第一次慢動作拍攝中...")
    wait_then_click(adb, click_map["拍照鍵"], timeout_ms=5000)


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


def test_photo_settings(adb: Adb, click_map) -> bool:
    """測試拍照設定是否存在"""
    click_camera_mode(adb, click_map, mod="p")  # 切到拍照模式

    open_settings(adb, click_map)  # 點擊設定按鈕

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
        exists = wait_exists(adb, target, timeout_ms=1500)

        if name == "靜態影像尺寸" and not exists:
            print("再次嘗試點擊設定...")
            open_settings(adb, click_map)
            exists = wait_exists(adb, target, timeout_ms=1500)

        print(f"  {name}\t: {'✓ 存在' if exists else '✗ 不存在'}")

        if not exists:
            result = False

    open_settings(adb, click_map)  # 關閉設定

    return result


def check_camera_running(adb: Adb) -> None:
    """
    檢查相機是否正在運行。
    若未運行則直接退出程式。
    """
    result = adb.shell(f"pidof {CAMERA_PACKAGE_NAME}", check=False)
    if not bool(result.stdout and result.stdout.strip()):
        raise RuntimeError("無法檢測到相機app正在運行 ❌")


def check_camera_ui(adb: Adb, click_map, *, timeout_ms=6000) -> None:
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
        if not found_error and wait_exists(
            adb, click_map["錯誤"], timeout_ms=0, raise_on_fail=False
        ):
            errors.append("發現錯誤對話框")
            results = query_elements(adb, click_map["錯誤"].resource_id)
            Text = (results[0].text if results else "") or ""
            errors.append(f"錯誤訊息: {Text}")
            found_error = True

        # 檢查模式按鈕
        if not found_mode and wait_exists(
            adb, click_map["模式"], timeout_ms=0, raise_on_fail=False
        ):
            found_mode = True

        # 如果兩個都檢查完，就提前結束迴圈
        if found_error and found_mode:
            break

    # 超時後仍未找到模式按鈕
    if not found_mode:
        errors.append("模式按鈕未出現，UI 可能未回覆或初始化異常，程式終止 ❌")
    if errors:
        raise RuntimeError(f"\n\n{'\n'.join(errors)}\n")


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


def run_camera_test_flow(adb: Adb, args, tests, click_map):
    if args.clear_data:
        reset_camera_state(adb)
    stop_camera(adb, args.force_stop)  # 停止相機應用程式
    launch_camera(adb)  # 啟動相機應用程式

    if args.clear_data:
        handle_permission_dialog(adb, click_map)  # 處理權限彈窗

    # 手動啟動相機會出現 "儲存地點否" 腳本啟動相機不會出現。
    wait_then_click(adb, click_map["儲存地點否"], timeout_ms=1000, raise_on_fail=False)

    for mode in args.mode:
        result = True
        cfg = tests[mode]
        print(f"========== 開始{cfg['name']}測試 ========== ")
        try:
            t_start = time.monotonic()

            test_ok = cfg["func"](adb, click_map)
            if cfg["check_saved"]:  # photo_settings 模式不測試儲存
                result = has_saved(adb)
            else:
                result = test_ok

            elapsed = time.monotonic() - t_start
            label = "儲存" if cfg["check_saved"] else ""
            if result:
                print(f"{label}結果: ✅ (耗時: {elapsed:.2f}s)")
            else:
                raise RuntimeError(f"{label}結果: ❌")
        except (RuntimeError, WaitTargetNotFoundError, ClickFailedError) as e:
            print(f"模式 {mode} {e}")
            result = False
            check_camera_running(adb)
            check_camera_ui(adb, click_map)
        finally:
            print(f"========== 結束 {cfg['name']} 測試 ==========")
            if not result:
                return False
    return result


def main() -> None:
    global file_count

    tests = {
        "photo": {
            "func": test_photo,
            "name": "拍照",
            "check_saved": True,
            "alias": "p",
        },
        "video": {
            "func": test_video,
            "name": "錄影",
            "check_saved": True,
            "alias": "v",
        },
        "photo_settings": {
            "func": test_photo_settings,
            "name": "拍照設定選項",
            "check_saved": False,
            "alias": "st",
        },
        "slow_motion": {
            "func": test_slow_motion,
            "name": "超級慢動作(單拍)",
            "check_saved": True,
            "alias": "sm",
        },
    }

    args = parse_args(tests)
    adb = Adb(serial=args.device)

    click_map = get_click_map()
    ensure_uiagent_ready(adb)  # 確認 UiAgent 已安裝且無障礙服務已啟用

    prepare_device(adb)  # 喚醒並解鎖裝置

    file_count = get_dcim_file_count(adb)  # 記錄 /sdcard/DCIM/  檔案數量
    print(f"當前 DCIM 檔案數量: {file_count}")

    n = args.count
    for n in range(args.count):
        print("-" * 10, "開始第", n + 1, "輪測試", "-" * 10)
        if not run_camera_test_flow(adb, args, tests, click_map):
            print(f"第 {n + 1} 輪測試結果: 失敗 ❌ ")
            sys.exit(1)
        print(f"第 {n + 1} 輪測試結果: 通過 ✅ ")
        print()
        countdown(args.interval)

    print("🎉 所有測試完成，結果: 通過 ✅ ")


if __name__ == "__main__":
    main()
