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
    ClickTarget,
    load_click_targets,
)
from uiagent_client import (  # noqa: E402
    ClickFailedError,
    WaitTargetNotFoundError,
    click_child_rid,
    click_child_under_rid,
    click_then_appear,
    click_then_disappear,
    exists,
    query_elements,
    wait_exists,
    wait_then_click,
)
from uiagent_instrumentation_client import (  # noqa: E402
    UiAgentInstrumentationClient,
)
from tools_Common.adb import Adb  # noqa: E402

TIMEOUT = 5000
S_TIMEOUT = 500
L_TIMEOUT = 7000
CAMERA_PACKAGE_NAME = "com.sonyericsson.android.camera"


# ------------------------------------------------------------
# 失敗後的檢查函式
# ------------------------------------------------------------
def check_error_ui(adb: Adb, click_map, *, timeout_ms=TIMEOUT) -> str | None:
    """
    檢查是否有錯誤對話框
    回傳錯誤訊息（有的話），否則回傳 None
    """
    if wait_exists(adb, click_map["錯誤"], timeout_ms=timeout_ms, raise_on_fail=False):
        results = query_elements(adb, click_map["錯誤"].resource_id)
        text = (results.text if results else "") or ""
        return text
    return None


def check_camera_ui(adb: Adb, click_map, *, timeout_ms=TIMEOUT) -> bool:
    return wait_exists(
        adb, click_map["模式"], timeout_ms=timeout_ms, raise_on_fail=False
    )


def check_camera_running(adb: Adb) -> bool:
    result = adb.shell(f"pidof {CAMERA_PACKAGE_NAME}", check=False)
    return bool(result.stdout and result.stdout.strip())


def check_all(adb, click_map, *, timeout_ms=TIMEOUT, interval_ms=200):
    deadline = time.monotonic() + timeout_ms / 1000

    running = False
    ui_ok = False
    err_msg = None

    while time.monotonic() < deadline:
        if not running:
            running = check_camera_running(adb)

        if not ui_ok:
            ui_ok = check_camera_ui(adb, click_map)

        if err_msg is None:
            err_msg = check_error_ui(adb, click_map)

        # 一旦有錯誤就立刻結束
        if err_msg:
            break

        # 全部都 OK 提早結束
        if running and ui_ok:
            break

        time.sleep(interval_ms / 1000)

    return {
        "running": running,
        "ui_ok": ui_ok,
        "error": err_msg,
    }


# ------------------------------------------------------------
# 測試流程函式
# ------------------------------------------------------------
def test_photo(adb: Adb, click_map) -> None:
    """拍照測試流程"""
    print("測試拍照模式...")

    click_camera_mode(adb, click_map, mode="main", param="photo")  # 切到拍照模式

    print("拍照中...")
    click_then_disappear(adb, click_map["B_拍照鍵"], click_map["B_模式通用"])
    wait_exists(adb, click_map["B_模式通用"])


def test_video(adb: Adb, click_map) -> None:
    """錄影測試流程"""
    print("測試錄影模式...")

    click_camera_mode(adb, click_map, mode="main", param="video")  # 切到錄影模式

    print("開始錄影...")
    click_then_appear(adb, click_map["B_錄影鍵"], click_map["B_停止錄影"])

    wait_record_time(adb, click_map, target_sec=4)  # 等待錄影至少 4 秒

    print("停止錄影...")
    click_then_appear(
        adb, click_map["B_停止錄影"], click_map["B_錄影鍵"], timeout_ms=8000
    )


def test_photo_settings(adb: Adb, click_map) -> bool:
    """測試拍照設定是否存在"""
    print("測試拍照設定...")
    click_camera_mode(adb, click_map, mode="main", param="photo")  # 切到拍照模式

    click_then_appear(adb, click_map["B_設定"], click_map["ANCHOR_設定選單"])

    # 所有設定選項清單
    settings_check = [
        ("靜態影像尺寸", click_map["S_靜態影像尺寸"]),
        ("預拍功能", click_map["S_預拍功能"]),
        ("物件追蹤", click_map["S_物件追蹤"]),
        ("自動拍攝", click_map["S_自動拍攝"]),
        ("失真校正", click_map["S_失真校正"]),
    ]
    result = True
    for name, target in settings_check:
        exists_result = exists(adb, target)
        print(f"  {name}\t: {'✓ 存在' if exists_result else '✗ 不存在'}")
        if exists_result and result:
            result = True
        else:
            result = False

    click_then_disappear(adb, click_map["B_設定"], click_map["ANCHOR_設定選單"])
    if not result:
        raise RuntimeError("部分拍照設定選項不存在")
    return result


def test_slow_base(adb: Adb, click_map, param) -> bool:
    """慢動作測試流程"""
    print(f"切到慢動作({param})...")
    click_camera_mode(adb, click_map, mode="slow", param=param)


def test_slow_single(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""
    test_slow_base(adb, click_map, param="single")

    click_then_disappear(adb, click_map["B_快門通用"], click_map["B_模式通用"])
    wait_exists(adb, click_map["B_模式通用"])


def test_slow_960(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""
    test_slow_base(adb, click_map, param="960")

    print("開始錄影...")
    click_then_appear(adb, click_map["B_快門通用"], click_map["B_960停止錄影"])

    wait_record_time(adb, click_map, target_sec=2)  # 等待錄影至少 2 秒

    print("慢動作拍照...")
    click_then_disappear(adb, click_map["B_快門通用"], click_map["STATE_錄影計時"])

    wait_record_time(adb, click_map, target_sec=6)  # 等待錄影至少 6 秒

    print("停止錄影...")
    click_then_appear(
        adb, click_map["B_960停止錄影"], click_map["B_快門通用"], timeout_ms=8000
    )


def test_slow_120(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""
    test_slow_base(adb, click_map, param="120")

    print("開始錄影...")
    click_then_appear(adb, click_map["B_快門通用"], click_map["B_停止錄影"])

    wait_record_time(adb, click_map, target_sec=4)  # 等待錄影至少 4 秒
    print("停止錄影...")
    click_then_appear(
        adb, click_map["B_停止錄影"], click_map["B_快門通用"], timeout_ms=8000
    )


# ------------------------------------------------------------
# 共用函式
# ------------------------------------------------------------


def wait_record_time(adb, click_map, target_sec=4, timeout_sec=10):
    wait_exists(adb, click_map["STATE_錄影計時"])  # 等待錄影計時出現，確認開始錄影

    start = time.time()
    while True:
        # ⏱ 超時檢查
        if time.time() - start > timeout_sec:
            raise TimeoutError(f"錄影超時 {timeout_sec} 秒")

        text = get_text(adb, click_map["STATE_錄影計時"])
        print(f"錄影計時: {text} ", end="\r")

        if time_to_sec(text) >= target_sec:
            print()  # 換行
            break


def time_to_sec(t: str) -> int:
    m, s = map(int, t.split(":"))
    return m * 60 + s


def to_slow(adb, click_map):
    click_then_appear(adb, click_map["B_模式選單"], click_map["O_模式_慢動作"])
    click_then_appear(adb, click_map["O_模式_慢動作"], click_map["B_返回拍照"])


def to_main(adb, click_map):
    click_then_appear(adb, click_map["B_返回拍照"], click_map["B_模式選單"])


def main_switch(adb, click_map, video_mode):
    cfg = VIDEO_MODES.get(video_mode)
    if not cfg:
        raise ValueError(f"未知 video mode: {video_mode}")
    pick = cfg.get("button")
    click_child_rid(adb, click_map["UI_模式切換滑塊"].rid, pick=pick)


def slow_switch(adb, click_map, slow_mode):
    click_then_appear(adb, click_map["B_設定"], click_map["ANCHOR_設定選單"])
    click_then_appear(adb, click_map["S_慢動作"], click_map["S_慢動作"])
    cfg = SLOW_MODES.get(slow_mode)
    if not cfg:
        raise ValueError(f"未知 slow mode: {slow_mode}")
    click_then_disappear(
        adb,
        ClickTarget(
            rid=click_map["S_慢動作"].rid,
            text=cfg.get("button"),
        ),
        click_map["ANCHOR_設定選單"],
    )


TRANSITIONS = {
    # --- 跨 mode ---
    ("main", "slow"): to_slow,
    ("slow", "main"): to_main,
    # --- main 內 ---
    ("main", "video"): main_switch,
    ("main", "photo"): main_switch,
    # --- slow 內 ---
    ("slow", "960"): slow_switch,
    ("slow", "120"): slow_switch,
    ("slow", "single"): slow_switch,
}


def get_transition(current_mode, target):
    action = TRANSITIONS.get((current_mode, target))
    if not action:
        raise ValueError(f"Unknown transition: ({current_mode}, {target})")
    return action


def dispatch(adb, click_map, current_mode, target_mode, target_param):

    if current_mode != target_mode:
        action = get_transition(current_mode, target_mode)
        action(adb, click_map)
        return

    action = get_transition(current_mode, target_param)
    action(adb, click_map, target_param)


def click_camera_mode(adb: Adb, click_map, *, mode: str, param: str) -> None:
    wait_exists(adb, click_map["B_模式通用"], timeout_ms=TIMEOUT)  # 確認模式按鈕存在
    for _ in range(10):  # 最多嘗試 10 次確認模式
        current_mode, current_param = get_camera_mode(adb, click_map)
        if current_mode == mode and current_param == param:
            return

        dispatch(adb, click_map, current_mode, mode, param)

    raise RuntimeError(f"切換模式失敗，未成功切到 {mode}/{param}")


VIDEO_MODES = {
    "video": {
        "state": "錄製",
        "button": "right",
    },
    "photo": {
        "state": "相機鍵",
        "button": "left",
    },
}


SLOW_MODES = {
    "960": {
        "state": "超級慢動作",
        "button": "超級慢動作",
    },
    "120": {
        "state": "慢動作",
        "button": "慢動作",
    },
    "single": {
        "state": "超級慢動作(單拍)",  # 狀態名稱
        "button": "超級慢(僅限一次)",  # 按鈕名稱
    },
}
VIDEO_MODES_TO_KEY = {v["state"]: k for k, v in VIDEO_MODES.items()}
SLOW_STATE_TO_KEY = {v["state"]: k for k, v in SLOW_MODES.items()}


def get_camera_mode(adb, click_map):
    mode = None
    param = None
    if exists(adb, click_map["STATE_慢動作模式"]):  # 如果在慢動作模式
        mode = "slow"
        current_text = get_text(adb, click_map["STATE_慢動作模式"])  # 取得慢動作模式
        param = SLOW_STATE_TO_KEY.get(current_text)
    else:  # 如果在一般模式
        mode = "main"
        current_text = get_desc(adb, click_map["B_快門通用"])  # 取得快門模式
        param = VIDEO_MODES_TO_KEY.get(current_text)

    if not param:
        raise RuntimeError(f"無法識別的模式參數，mode: {mode}, text: {current_text}")
    return mode, param


def get_text(adb, target) -> str:
    """用rid取得指定文字"""
    if not exists(adb, target):
        raise WaitTargetNotFoundError(f"找不到目標: {target.key_name}")
    results = query_elements(adb, target.rid)
    text = (getattr(results, "text", "") or "").strip()
    return text


def get_desc(adb, target) -> str:
    """用rid取得指定描述"""
    if not exists(adb, target):
        raise WaitTargetNotFoundError(f"找不到目標: {target.key_name}")
    results = query_elements(adb, target.rid)
    desc = (getattr(results, "desc", "") or "").strip()
    return desc


def stop_camera(adb: Adb, force_stop=False) -> None:
    print("停止相機應用程式...")
    if force_stop:
        clear_all_task_stacks(adb)
    else:
        adb.shell(f"am force-stop {CAMERA_PACKAGE_NAME}", check=False)


def has_saved(adb: Adb, timeout_ms: int = 8000) -> bool:
    """檢查 DCIM 是否新增檔案，每次掃描都印出數量，找到新檔案就 True"""
    global file_count
    print(f"當前 DCIM 檔案數量: {file_count}")
    deadline = time.monotonic() + timeout_ms / 1000
    result = False

    while time.monotonic() < deadline:
        new_count = get_dcim_file_count(adb)

        if new_count > file_count:
            file_count = new_count
            result = True
            print(f"當前 DCIM 檔案數量: {new_count}")
            break
        time.sleep(0.1)

    return result


# ------------------------------------------------------------
# 參數解析
# ------------------------------------------------------------
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


# ------------------------------------------------------------
# 測試流程函式(待修改)
# ------------------------------------------------------------


def 切換慢動作模式(adb: Adb, click_map, 慢動作模式, timeout_ms=TIMEOUT) -> None:
    """切換慢動作模式"""

    def _取得目前慢動作模式() -> str:
        """取得目前慢動作模式"""
        wait_exists(adb, click_map["慢動作模式"], timeout_ms=0, raise_on_fail=False)
        results = query_elements(adb, click_map["慢動作模式"].resource_id)
        mode = (getattr(results, "text", "") or "").strip()
        return mode

    def _等待切換完成() -> bool:

        deadline = time.monotonic() + timeout_ms / 1000

        while time.monotonic() < deadline:
            mode = _取得目前慢動作模式()

            if mode == 慢動作模式:
                return True
            time.sleep(0.1)
        return False

    print(f"開始切到慢動作({慢動作模式})...")

    mode = _取得目前慢動作模式()
    if mode == 慢動作模式:
        print("已經在目標模式，略過切換")
        return

    # open_settings(adb, click_map)
    wait_then_click(adb, click_map["慢動作模式選單"], timeout_ms=timeout_ms)
    wait_then_click(adb, click_map[慢動作模式], timeout_ms=timeout_ms)

    if _等待切換完成():
        print("成功切換慢動作模式")
        return
    raise RuntimeError(f"切換慢動作模式失敗，未在 {timeout_ms}ms 內切到 {慢動作模式}")


def test_slow_motion_base1(adb: Adb, click_map, 慢動作模式="慢動作僅一次") -> bool:
    """慢動作測試流程"""
    print(f"切到慢動作({慢動作模式})...")

    wait_then_click(adb, click_map["模式"])
    wait_then_click(adb, click_map["慢動作"])
    # 手動啟動相機會出現 "教學" 腳本啟動相機方式不會出現才正常。
    wait_exists(adb, click_map["慢動作模式"])  # 確認已切到慢動作模式
    results = query_elements(adb, click_map["慢動作模式"].resource_id)  # 取得慢動作模式
    mode = results.text if results else ""
    if mode != "慢動作模式":  # 確認慢動作模式
        raise RuntimeError(f"未切到預期的慢動作模式，當前模式: {mode}")

    # open_settings(adb, click_map)
    try:
        wait_then_click(adb, click_map["慢動作模式選單"])
    except WaitTargetNotFoundError as e:
        print(f"{e} 慢動作模式不存在")
        return

    wait_then_click(adb, click_map[慢動作模式])

    print("第一次慢動作拍攝中...")
    wait_then_click(adb, click_map["B_拍照鍵"])


def test_super_960_once(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""

    test_slow_single(adb, click_map, 慢動作模式="慢動作僅一次")


def test_slow_motion(adb: Adb, click_map) -> bool:
    """慢動作測試流程"""
    # results = query_elements(click_map["慢動作"].resource_id)#慢動作模式判斷
    # Text = (results[0].text if results else "") or ""

    print("切到慢動作模式...")
    wait_then_click(adb, click_map["模式"])
    wait_then_click(adb, click_map["慢動作"])
    time.sleep(0.5)

    # open_settings(adb, click_map)
    try:
        wait_then_click(adb, click_map["慢動作模式選單"])
    except WaitTargetNotFoundError as e:
        print(f"{e} 慢動作模式不存在")
        return

    wait_then_click(adb, click_map["慢動作僅一次"])

    print("第一次慢動作拍攝中...")
    wait_then_click(adb, click_map["B_拍照鍵"])


# def test_t(click_map) -> bool:
#     """色彩與亮度滑動測試"""
#     wait_then_click(click_map["色彩和亮度"])

#     print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
#     print(f"Swipe: {swipe(540, 1365, 215, 1365)}")

#     wait_then_click(click_map["關閉色彩和亮度調整"])

#     wait_then_click(click_map["色彩和亮度"])

#     print(f"Swipe: {swipe(540, 1214, 215, 1214)}")
#     print(f"Swipe: {swipe(540, 1365, 215, 1365)}")

#     return True
# ------------------------------------------------------------


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


def launch_camera(adb: Adb, app="com.sonyericsson.android.camera") -> None:
    """Launch the stock Sony camera app so we can interact with its UI."""
    print("啟動相機應用程式...\n")
    adb.shell(
        f"am start -a android.media.action.STILL_IMAGE_CAMERA -p {app}",
        check=True,
    )


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
        if not client.wait_then_click(click_map["允許檔案存取"], raise_on_fail=False):
            client.wait_then_click(click_map["全部允許"], raise_on_fail=False)
    finally:
        threading.Thread(
            target=client.stop_instrumentation_service, daemon=True
        ).start()


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
            result = False
            print(f"模式 {mode} {e}")
            diag = check_all(adb, click_map)
            print("----- 診斷結果 -----")
            print(f"{'Camera running':<18}    : {'✅' if diag['running'] else '❌'}")
            print(f"{'UI 正常':<18}  : {'✅' if diag['ui_ok'] else '❌'}")
            print(f"{'錯誤訊息':<18}: {diag['error'] or '無'}")
        except Exception as e:
            result = False
            print(f"模式 {mode} 發生未預期錯誤: {e}")
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
        "photo_settings": {
            "func": test_photo_settings,
            "name": "拍照設定選項",
            "check_saved": False,
            "alias": "st",
        },
        "video": {
            "func": test_video,
            "name": "錄影",
            "check_saved": True,
            "alias": "v",
        },
        "slow_single": {
            "func": test_slow_single,
            "name": "超級慢動作(單拍)",
            "check_saved": True,
            "alias": "so",
        },
        "slow_960": {
            "func": test_slow_960,
            "name": "超級慢動作",
            "check_saved": True,
            "alias": "s960",
        },
        # "slow_120": {
        #     "func": test_slow_120,
        #     "name": "慢動作",
        #     "check_saved": True,
        #     "alias": "s120",
        # },
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
