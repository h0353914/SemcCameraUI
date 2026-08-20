#!/usr/bin/env python3
import argparse
from dataclasses import dataclass
from datetime import datetime
import logging
from pathlib import Path
import re
import sys
import tempfile
import threading
import time

ROOT = Path(__file__).resolve().parents[1]  # /home/h/lineageos/device/sony/SemcCameraUI
TEST_CAMERA_DIR = Path(__file__).resolve().parent  # ./test_camera


sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(TEST_CAMERA_DIR))

import uiagent_client as uiagent_client  # noqa: E402
import uiagent_instrumentation_client as uiagent_instrumentation_client  # noqa: E402
from key import ClickTarget, load_click_targets  # noqa: E402
from uiagent_instrumentation_client import UiAgentInstrumentationClient  # noqa: E402
from parse_args import parse_args  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402
from tools_Common.push_common import push  # noqa: E402
from uiagent_client import (  # noqa: E402
    Field,
    WaitTargetNotFoundError,
    click_child_rid,
    click_then_appear,
    click_then_disappear,
    exists,
    field_by_rid,
    list_all_elements_with_class,
    wait_exists,
    wait_then_click,
)


SAVE_TIMEOUT = 10000
TIMEOUT = 5000
S_TIMEOUT = 500
L_TIMEOUT = 9000
LL_TIMEOUT = 30000
PACKAGE_NAME = "com.sonyericsson.android.camera"
APP_VERSION = "2.2.2.A.0.15"


# ------------------------------------------------------------
# 類別定義
# ------------------------------------------------------------


class TestSession:  # 管理這次測試的 session 資料夾結構
    def __init__(self, base_dir: Path):
        self.log_dir = base_dir  # 所有測試共用的 log 目錄
        self.session_dir = self._create_session_dir()  # 建立這次的 session 目錄
        self.main_log = self.session_dir / "main.log"  # 主 log 檔案路徑
        self.adb_log_path = self.session_dir / "adb_full.log"  # adb log 檔案路徑
        self.round_dir = None
        self.test_dir = None

    def _create_session_dir(self) -> Path:
        """創建以時間戳命名的 session 目錄"""
        ts = datetime.now().strftime(
            "%Y%m%d_%H%M%S"
        )  # 格式化當前時間為 YYYYMMDD_HHMMSS
        session_dir = self.log_dir / ts
        session_dir.mkdir(parents=True, exist_ok=True)
        return session_dir

    def create_round_dir(self, round_no: int) -> Path:
        """創建以輪數命名的子目錄"""
        round_dir = self.session_dir / f"round_{round_no}"
        round_dir.mkdir(parents=True, exist_ok=True)
        return round_dir

    def create_test_dir(self, test_key: str) -> Path:
        """創建以測試名稱命名的子目錄"""
        test_dir = self.session_dir / f"test_{test_key}"
        test_dir.mkdir(parents=True, exist_ok=True)
        return test_dir


class TestResources:  # 建立 adb、logger、ui 等共用資源的實例，並提供給測試流程使用
    def __init__(self, adb: Adb, session: TestSession):
        self.adb = adb
        self.session = session

        self.ui: Ui = Ui(self.adb)  # 建立 UI 實例
        self.logger = LoggerFactory.create(session.session_dir)
        self.adb_log = AdbLogCapture(adb, self.logger, session.session_dir)


class Ui:
    def __init__(self, adb):
        self.adb = adb
        self.key_path = TEST_CAMERA_DIR / "key.json"
        self.target_map = self._load_target_map()
        self.android_version = int(
            self.adb.shell(
                "getprop ro.build.version.release", check=True
            ).stdout.strip()
        )

    def _load_target_map(self) -> dict[str, ClickTarget]:
        targets = load_click_targets(self.key_path)
        return {ct.key_name: ct for ct in targets}

    def __getitem__(self, key):
        return self.target_map[key]

    def get(self, key, default=None):
        return self.target_map.get(key, default)

    def _resolve(self, target):
        if isinstance(target, str):
            return self.target_map[target]
        return target

    def click_then_appear(self, click, appear, **kwargs):
        return click_then_appear(
            self.adb,
            self._resolve(click),
            self._resolve(appear),
            **kwargs,
        )

    def click_then_disappear(self, click, disappear, **kwargs):
        return click_then_disappear(
            self.adb,
            self._resolve(click),
            self._resolve(disappear),
            **kwargs,
        )

    def wait_exists(self, key, **kwargs):
        return wait_exists(self.adb, self._resolve(key), **kwargs)

    def exists(self, key):
        return exists(self.adb, self._resolve(key))

    def wait_then_click(self, key, **kwargs):
        return wait_then_click(self.adb, self._resolve(key), **kwargs)

    def click_child_rid(self, rid, **kwargs):
        return click_child_rid(self.adb, rid, **kwargs)

    def field_by_rid(self, key, field):
        return field_by_rid(self.adb, self._resolve(key), field)


# ------------------------------------------------------------
# 類別定義
# ------------------------------------------------------------


@dataclass
class TestCase:
    key: str
    func: callable
    name: str
    alias: str
    check_saved: bool


# Logger（只負責使用）
class Logger:
    def __init__(self, logger: logging.Logger, log_file: Path):
        self._logger = logger
        self.log_file = log_file

    def info(self, msg: str):
        self._logger.info(msg)

    def error(self, msg: str):
        self._logger.error(msg)

    def debug(self, msg: str):
        self._logger.debug(msg)

    def exception(self, msg):
        self._logger.exception(msg)


# LoggerFactory（只負責建立）
class LoggerFactory:
    @staticmethod
    def create(session_dir: Path) -> Logger:
        log_file = session_dir / "main.log"

        logger = logging.getLogger(f"session_{session_dir.name}")
        logger.setLevel(logging.DEBUG)

        # 避免重複 handler
        if logger.handlers:
            logger.handlers.clear()

        # file handler
        fh = logging.FileHandler(log_file, encoding="utf-8")
        fh.setLevel(logging.DEBUG)

        # console handler
        ch = logging.StreamHandler()
        ch.setLevel(logging.INFO)

        # formatter
        file_formatter = logging.Formatter(
            "%(asctime)s - %(name)s - %(levelname)s - %(message)s",
            datefmt="%Y-%m-%d %H:%M:%S",
        )
        console_formatter = logging.Formatter("%(message)s")

        fh.setFormatter(file_formatter)
        ch.setFormatter(console_formatter)

        logger.addHandler(fh)
        logger.addHandler(ch)

        return Logger(logger, log_file)


@dataclass(frozen=True)  # frozen建立後不可修改
class TestConfig:
    rounds: int  # 測試輪數
    interval: float  # 輪與輪之間 delay


class TestContext:  # 負責管理 adb、logger、ui、camera controller 等共用資源
    def __init__(self, adb: Adb, log_dir: Path, config: TestConfig):
        self.adb: Adb = adb
        self.config = config
        self.session = TestSession(log_dir)  # session layer
        self.resources = TestResources(adb, self.session)  # resource layer
        self.camera: CameraController = CameraController(
            self.resources.ui, self.resources.logger, self.adb
        )
        self.state: TestState = TestState(
            self.adb, self.resources.logger
        )  # 建立測試狀態實例


class TestRunner:  # 負責管理測試流程，包含輪數、目前測試、開始/結束測試等
    def __init__(self, ctx: TestContext):
        self.ctx = ctx
        self.round = 0  # 目前測試的輪數
        self.test: TestCase | None = None  # 目前測試的 TestCase

    def _inter_round_delay(self):
        """每次測試之間的間隔"""
        interval = self.ctx.config.interval
        while interval > 0:
            self.ctx.resources.logger.debug(f"等待{interval:.1f} 秒")
            time.sleep(0.1)  # 固定每 0.1 秒
            interval -= 0.1

    def start(self):
        self.ctx.resources.adb_log.start()  # 開始 adb log 捕獲

    def start_round(self, round_no: int):
        """開始下一輪測試"""
        self.round = round_no
        self._inter_round_delay()
        self.ctx.resources.logger.info(f"開始第 {self.round} 輪測試")

    def end_round(self, success: bool):
        if success:
            self.ctx.resources.logger.info(f"第 {self.round} 輪測試結果: ✅")
        else:
            self.ctx.resources.logger.error(f"第 {self.round} 輪測試結果: ❌")

    def start_test(self, test: TestCase):
        """開始下一個測試"""
        self.test = test
        self.ctx.resources.logger.info(f"開始{self.test.key}測試")
        self.ctx.state.reset_baseline()

    def end_test(self):
        """結束目前測試"""
        self.ctx.resources.logger.info(f"結束{self.test.key}測試")

    def stop(self):
        self.ctx.resources.adb_log.stop()  # 停止所有 adb log 捕獲
        self.ctx.resources.logger.info(
            f"測試結束，adb log 和診斷資料已儲存到 {self.ctx.session.session_dir}"
        )


class TestState:  # 負責管理測試過程中的狀態，例如 DCIM 的 baseline 檔案數量，以及檢查是否有新檔案產生
    # 判斷副檔名對應的媒體型別，用來決定要怎麼驗證內容是否合法
    PHOTO_EXTS = (".jpg", ".jpeg")
    VIDEO_EXTS = ".mp4"

    def __init__(self, adb: Adb, logger: LoggerFactory):
        self.adb = adb
        self.logger = logger
        self.baseline = 0
        self.known_files: set[str] = set()  # 已經看過（數量+內容都確認過）的檔案集合

    def reset_baseline(self):
        """重置 DCIM baseline 基準檔案數量與已知檔案集合"""
        self.known_files = set(self._list_dcim_files())
        self.baseline = len(self.known_files)

    def get_dcim_file_count(self) -> int:
        """取得 /sdcard/DCIM/ 下所有檔案數量，包含子資料夾"""
        return len(self._list_dcim_files())

    def _list_dcim_files(self) -> list[str]:
        """取得 /sdcard/DCIM/ 下所有檔案的完整路徑列表，包含子資料夾"""
        result = self.adb.shell("find /sdcard/DCIM -type f", check=False)
        stdout = (result.stdout or "").strip()  # 取得標準輸出並去除首尾空白
        return stdout.splitlines() if stdout else []  # 以換行分割成列表，若為空則回傳[]

    def _get_remote_file_size(self, remote_path: str) -> int | None:
        """用 stat 取得裝置上檔案目前大小，取不到回傳 None"""
        result = self.adb.shell(f"stat -c %s '{remote_path}'", check=False)
        stdout = (result.stdout or "").strip()
        try:
            return int(stdout)
        except ValueError:
            return None

    def _wait_file_size_stable(
        self, remote_path: str, *, checks: int = 5, interval_s: float = 0.3
    ) -> bool:
        """等待檔案大小連續讀取都不再變化，避免在存檔寫入到一半時就去驗證內容。
        取不到大小（例如 stat 失敗）視為不穩定，直接回傳 False。"""
        last_size = self._get_remote_file_size(remote_path)
        if last_size is None:
            return False
        for _ in range(checks):
            time.sleep(interval_s)
            size = self._get_remote_file_size(remote_path)
            if size is None or size != last_size:
                last_size = size
                continue
            return True
        return False

    def _pull_bytes(self, remote_path: str) -> bytes | None:
        """把裝置上的檔案完整拉到本地暫存檔並讀成 bytes，失敗回傳 None"""
        with tempfile.TemporaryDirectory() as tmp_dir:
            local_path = Path(tmp_dir) / Path(remote_path).name
            result = self.adb.pull(remote_path, str(local_path), check=False)
            if result.returncode != 0 or not local_path.exists():
                return None
            return local_path.read_bytes()

    def _validate_media_file(self, remote_path: str) -> bool:
        """驗證新產生的照片/影片檔案內容是否合法（不是全零/損毀的空 buffer）。
        非照片/影片副檔名（例如縮圖、.pending 暫存檔）不驗證，直接視為合法。"""
        lower = remote_path.lower()
        is_photo = lower.endswith(self.PHOTO_EXTS)
        is_video = lower.endswith(self.VIDEO_EXTS)
        if not is_photo and not is_video:
            return True

        if not self._wait_file_size_stable(remote_path):
            self.logger.error(f"檔案大小一直不穩定，判定存檔失敗: {remote_path}")
            return False

        data = self._pull_bytes(remote_path)
        if data is None:
            self.logger.error(f"驗證檔案失敗，無法從裝置拉取: {remote_path}")
            return False

        if len(data) < 64:
            self.logger.error(f"檔案過小，判定損毀: {remote_path} ({len(data)} bytes)")
            return False

        if is_photo:
            # 合法 JPEG 必須以 SOI marker (0xFFD8) 開頭、且結尾附近要有 EOI
            # marker (0xFFD9)。全零 buffer（曾發生過的真實 bug：buffer 尚未
            # 寫入 JPEG 資料就被提前 queue 回 Surface）兩者都不會有。
            if data[:2] != b"\xff\xd8":
                self.logger.error(f"照片缺少合法 JPEG 開始標記: {remote_path}")
                return False
            if b"\xff\xd9" not in data[-65536:]:
                self.logger.error(f"照片結尾附近找不到 JPEG 結束標記: {remote_path}")
                return False
        else:
            # 合法 MP4/3GP 檔案的第 4~7 byte 固定是 'ftyp' box type。
            if data[4:8] != b"ftyp":
                self.logger.error(f"影片缺少合法 MP4 'ftyp' box: {remote_path}")
                return False

        return True

    def wait_for_new_file(self, timeout_ms: int = SAVE_TIMEOUT) -> bool:
        """檢查 DCIM 是否新增檔案，且新增的照片/影片檔案內容必須合法"""
        self.logger.info(f"當前 DCIM 檔案數量: {self.baseline}")
        deadline = time.monotonic() + timeout_ms / 1000

        while time.monotonic() < deadline:
            after_files = self._list_dcim_files()
            new_count = len(after_files)

            if new_count > self.baseline:
                new_files = [f for f in after_files if f not in self.known_files]
                self.logger.info(f"當前 DCIM 檔案數量: {new_count}")
                if not all(self._validate_media_file(f) for f in new_files):
                    return False
                self.known_files = set(after_files)  # 更新已知檔案集合，避免重複驗證
                self.baseline = new_count
                return True
            time.sleep(0.1)
        return False


class AdbLogCapture:
    def __init__(self, adb, logger, session_dir):
        self.adb = adb
        self.logger = logger
        self.session_dir = session_dir
        self.proc = None  # 線程實例，啟動後會有值

        self._file_pos = 0  # 用於快照功能，記錄上次切片的檔案位置
        self.full_log_path: Path | None = None

    def start(self):
        """只啟動一次 logcat stream"""
        self.adb.clear_logcat()
        out_path = self.session_dir / "adb_full.log"
        self.full_log_path = out_path
        self.logger.info(f"開始 adb log : {out_path}")
        self.proc = self.adb.start_log_capture(out_path)

    def dump(self, name: str):
        """切片保存"""
        out_path = self.session_dir / f"adb_{name}.log"
        self.logger.info(f"快照 adb log : {out_path}")

        with open(self.full_log_path, "r", encoding="utf-8") as f:
            lines = f.readlines()
            new_lines = lines[self._file_pos :]
            self._file_pos = len(lines)  # 更新切片位置

        with open(out_path, "w", encoding="utf-8") as f:
            f.writelines(new_lines)

    def stop(self):
        if self.proc:
            self.adb.stop_log_capture(self.proc)
            self.logger.info("停止 adb log")


class CameraController:
    def __init__(self, ui, logger, adb):
        self.ui = ui
        self.logger = logger
        self.adb = adb

    def launch_camera(self, app="com.sonyericsson.android.camera") -> None:
        """Launch Sony camera app."""
        self.logger.info("啟動相機應用程式...")

        self.adb.shell(
            f"am start -W -n {app}/.CameraActivity",
            check=True,
        )

    def stop_camera(self) -> None:
        self.logger.info("停止相機應用程式...")
        self.adb.shell(f"am force-stop {PACKAGE_NAME}", check=False)

    def check_camera_ui_ready(self, timeout_ms: int = TIMEOUT) -> None:
        """檢查相機 UI 是否就緒，沒有就拋出 Error"""
        self.ui.wait_exists("B_模式通用", timeout_ms=timeout_ms)
        self.ui.wait_exists("B_設定", timeout_ms=timeout_ms)

    def ensure_camera_ui_ready(self, timeout=L_TIMEOUT):
        """檢查相機 UI 是否就緒，，失敗會重啟相機重試一次"""
        try:
            self.check_camera_ui_ready(timeout_ms=timeout)
        except WaitTargetNotFoundError:
            self.stop_camera()
            time.sleep(1)
            self.launch_camera()
            return self.check_camera_ui_ready(timeout_ms=timeout)

    def try_check_camera_ui_ready(self, timeout=L_TIMEOUT) -> bool:
        """檢查相機 UI 是否就緒，並回傳"""
        try:
            self.check_camera_ui_ready(timeout_ms=timeout)
            return True
        except WaitTargetNotFoundError:
            return False

    def time_to_sec(self, t: str) -> int:
        m, s = map(int, t.split(":"))
        return m * 60 + s

    def wait_record_time(self, target_sec=4, timeout_sec=10):
        self.ui.wait_exists("STATE_錄影計時")  # 等待錄影計時出現

        start = time.time()
        while True:
            # ⏱ 超時檢查
            if time.time() - start > timeout_sec:
                raise TimeoutError(f"錄影超時 {timeout_sec} 秒")

            text = self.ui.field_by_rid("STATE_錄影計時", Field.TEXT)
            self.logger.debug(f"錄影計時: {text}")
            print(f"\r錄影計時: {text}", end="", flush=True)

            if self.time_to_sec(text) >= target_sec:
                print()  # 換行
                break

    def click_camera_mode(self, *, mode: str, param: str) -> None:
        self.ui.wait_exists("B_模式通用", timeout_ms=TIMEOUT)  # 確認模式按鈕存在
        for _ in range(10):  # 最多嘗試 10 次確認模式
            current_mode, current_param = self.get_camera_mode()
            if (
                current_mode == mode
                and current_param == param
                and self.ui.exists("B_模式通用")
            ):
                return

            self.dispatch(current_mode, mode, param)

        raise RuntimeError(f"切換模式失敗，未成功切到 {mode}/{param}")

    def get_transition(self, current_mode, target):
        """根據當前模式和目標模式決定要執行的操作"""
        action = TRANSITIONS.get((current_mode, target))
        if not action:
            raise ValueError(f"Unknown transition: ({current_mode}, {target})")
        return action

    def dispatch(self, current_mode, target_mode, target_param):
        """根據當前模式和目標模式決定要執行的操作"""
        if current_mode != target_mode:
            action = self.get_transition(current_mode, target_mode)
            action(self.ui)
            return

        action = self.get_transition(current_mode, target_param)
        action(self.ui, target_param)

    def get_camera_mode(self):

        mode = None
        param = None
        if self.ui.exists("STATE_慢動作模式"):  # 如果在慢動作模式
            mode = "slow"
            current_text = self.ui.field_by_rid(
                "STATE_慢動作模式", Field.TEXT
            )  # 取得慢動作模式
            param = SLOW_STATE_TO_KEY.get(current_text)
        else:  # 如果在一般模式
            mode = "main"
            current_text = self.ui.field_by_rid(
                "B_快門通用", Field.DESC
            )  # 取得快門模式
            param = VIDEO_MODES_TO_KEY.get(current_text)

        if not param:
            raise RuntimeError(
                f"無法識別的模式參數，mode: {mode}, text: {current_text}"
            )
        return mode, param


# ------------------------------------------------------------
# 失敗後的診斷函式
# ------------------------------------------------------------
def check_error_ui(ui, *, timeout_ms=TIMEOUT) -> tuple[str, str] | None:
    """
    回傳 (title, message)
    """
    state_title = ui.get("STATE_錯誤標題")
    state_msg = ui.get("STATE_錯誤訊息")

    # 如果 key 不存在，無法檢查錯誤 UI
    if state_title is None or state_msg is None:
        return None

    if not ui.wait_exists(state_title, timeout_ms=timeout_ms, raise_on_fail=False):
        return None

    title = field_by_rid(ui.adb, state_title, Field.TEXT, raise_on_fail=False)
    msg = field_by_rid(ui.adb, state_msg, Field.TEXT, raise_on_fail=False)

    return title, msg


def check_camera_running(adb: Adb) -> bool:
    result = adb.shell(f"pidof {PACKAGE_NAME}", check=False)
    return bool(result.stdout and result.stdout.strip())


def check_all(context, *, timeout_ms=TIMEOUT, interval_ms=200):
    ui = context.resources.ui
    camera: CameraController = context.camera
    deadline = time.monotonic() + timeout_ms / 1000

    running = False
    ui_ok = False
    title = None
    msg = None

    while time.monotonic() < deadline:
        if not running:
            running = check_camera_running(ui.adb)

        if not ui_ok:
            ui_ok = camera.try_check_camera_ui_ready()

        if msg is None:
            err = check_error_ui(ui)
            if err is not None:
                title, msg = err

        # 一旦有錯誤就立刻結束
        if title and msg:
            break

        # 全部都 OK 提早結束
        if running and ui_ok:
            break

        time.sleep(interval_ms / 1000)

    return {
        "running": running,
        "ui_ok": ui_ok,
        "error_title": title,
        "error_msg": msg,
    }


# ------------------------------------------------------------
# 測試流程函式
# ------------------------------------------------------------
def test_settings_base(context: TestContext, mode, param, settings_check) -> bool:
    ui = context.resources.ui
    logger = context.resources.logger
    logger.info(f"測試{param}設定...")
    context.camera.click_camera_mode(mode=mode, param=param)

    ui.click_then_appear("B_設定", "ANCHOR_設定選單")

    missing = []

    for name, key in settings_check:
        exists_result = ui.exists(key)

        logger.info(f"  {name}\t: {'✓ 存在' if exists_result else '✗ 不存在'}")

        if not exists_result:
            missing.append(name)

    ui.click_then_disappear("B_設定", "ANCHOR_設定選單")

    if missing:
        raise RuntimeError(f"部分設定選項不存在: {', '.join(missing)}")

    return True


def test_photo(context) -> None:
    """拍照測試流程"""
    ui = context.resources.ui
    logger = context.resources.logger

    logger.info("測試拍照模式...")
    logger.info("切換到拍照模式...")
    context.camera.click_camera_mode(mode="main", param="photo")  # 切到拍照模式

    logger.info("按下快門...")
    ui.click_then_disappear("B_拍照鍵", "B_模式通用")
    ui.wait_exists("B_模式通用", timeout_ms=SAVE_TIMEOUT)  # 等待快門鍵重新出現


def test_video(context) -> None:
    """錄影測試流程"""
    ui = context.resources.ui
    logger = context.resources.logger

    logger.info("測試錄影模式...")
    logger.info("切換到錄影模式...")
    context.camera.click_camera_mode(mode="main", param="video")  # 切到錄影模式

    logger.info("按下快門...")
    ui.click_then_appear("B_錄影鍵", "B_停止錄影")

    logger.info("開始錄影...")
    context.camera.wait_record_time(target_sec=2)  # 等待錄影至少 2 秒

    logger.info("停止錄影...")
    ui.click_then_appear("B_停止錄影", "B_錄影鍵", timeout_ms=SAVE_TIMEOUT)


# 「一般設定」區塊，拍照/錄影/手動模式共用
GENERAL_SETTINGS_CHECK = [
    ("儲存地點", "S_儲存地點"),
    ("觸控拍攝", "S_觸控拍攝"),
    ("格狀線條", "S_格狀線條"),
    ("自動相片預覽", "S_自動相片預覽"),
    ("使用相機鍵連拍", "S_使用相機鍵連拍"),
    ("設定音量鍵的其他功能", "S_設定音量鍵的其他功能"),
    ("資料儲存", "S_資料儲存"),
    ("使用相機鍵啟動", "S_使用相機鍵啟動"),
    ("說明", "S_說明"),
    ("重設設定", "S_重設設定"),
]


def test_photo_settings(context) -> bool:
    """測試拍照設定是否存在"""
    # 所有設定選項清單
    settings_check = [
        ("靜態影像尺寸", "S_靜態影像尺寸"),
        ("預拍功能", "S_預拍功能"),
        ("物件追蹤", "S_物件追蹤"),
        ("自動拍攝", "S_自動拍攝"),
        ("失真校正", "S_失真校正"),
        *GENERAL_SETTINGS_CHECK,
    ]
    return test_settings_base(
        context, mode="main", param="photo", settings_check=settings_check
    )


def test_video_settings(context) -> bool:
    """測試錄影設定是否存在"""

    # 所有設定選項清單
    settings_check = [
        ("影片大小", "S_影片大小"),
        ("物件追蹤", "S_物件追蹤"),
        ("自動拍攝", "S_自動拍攝(影片)"),
        ("SteadyShot™", "S_SteadyShot™"),
        ("檔案格式(4K)", "S_檔案格式(4K)"),
        *GENERAL_SETTINGS_CHECK,
    ]
    return test_settings_base(
        context, mode="main", param="video", settings_check=settings_check
    )


def test_slow_base(context: TestContext, param) -> bool:
    """慢動作測試流程"""
    context.resources.logger.info(f"切到慢動作({param})...")
    context.camera.click_camera_mode(mode="slow", param=param)


def test_slow_single(context) -> bool:
    """慢動作測試流程"""
    ui = context.resources.ui
    test_slow_base(context, param="single")

    context.resources.logger.info("按下快門...")
    ui.click_then_disappear("B_快門通用", "B_模式通用")
    ui.wait_exists("B_模式通用", timeout_ms=SAVE_TIMEOUT)


def test_slow_960(context) -> bool:
    """慢動作測試流程"""
    ui = context.resources.ui
    logger = context.resources.logger
    test_slow_base(context, param="960")

    logger.info("按下快門...")
    ui.click_then_appear("B_快門通用", "B_960停止錄影")

    logger.info("開始錄影...")
    context.camera.wait_record_time(target_sec=2)  # 等待錄影至少 2 秒

    logger.info("慢動作拍照...")
    ui.click_then_appear(
        "B_快門通用",
        ClickTarget(rid=ui["STATE_慢動作提示"].rid, text="已錄製慢動作"),
    )
    logger.info("繼續錄影...")
    context.camera.wait_record_time(target_sec=5)  # 等待錄影至少 5 秒

    logger.info("停止錄影...")
    ui.click_then_appear("B_960停止錄影", "B_快門通用", timeout_ms=SAVE_TIMEOUT)


def test_slow_120(context) -> bool:
    """慢動作測試流程"""
    ui = context.resources.ui
    logger = context.resources.logger
    test_slow_base(context, param="120")

    logger.info("按下快門...")
    ui.click_then_appear("B_快門通用", "B_停止錄影")

    logger.info("開始錄影...")
    context.camera.wait_record_time(target_sec=3)  # 等待錄影至少 3 秒

    logger.info("停止錄影...")
    ui.wait_then_click("B_停止錄影")
    handle_permission_dialog(context)  # 暫時

    if context.state.wait_for_new_file():
        logger.info("暫存結果: ✅")
    else:
        logger.error("暫存結果: ❌")
        raise RuntimeError("慢動作(120fps)錄影失敗，未找到新檔案")

    logger.info("套用慢動作...")
    ui.click_then_appear("B_120套用", "B_120取消")
    ui.wait_exists("B_快門通用", timeout_ms=SAVE_TIMEOUT)


# ------------------------------------------------------------
# 模式切換相關函式
# ------------------------------------------------------------


def to_slow(ui):
    ui.click_then_appear("B_模式選單", "O_模式_慢動作")
    ui.click_then_appear("O_模式_慢動作", "B_返回拍照")


def to_main(ui):
    ui.click_then_appear("B_返回拍照", "B_模式選單")


def main_switch(ui, video_mode):
    cfg = VIDEO_MODES.get(video_mode)
    if not cfg:
        raise ValueError(f"未知 video mode: {video_mode}")
    pick = cfg.get("button")
    ui.click_child_rid(ui["UI_模式切換滑塊"].rid, pick=pick)


def slow_switch(ui, slow_mode):
    ui.click_then_appear("B_設定", "ANCHOR_設定選單")
    ui.click_then_appear("S_慢動作", "S_慢動作")
    cfg = SLOW_MODES.get(slow_mode)
    if not cfg:
        raise ValueError(f"未知 slow mode: {slow_mode}")
    ui.click_then_disappear(
        ClickTarget(
            rid=ui["S_慢動作"].rid,
            text=cfg.get("button"),
        ),
        ui["ANCHOR_設定選單"],
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


# ------------------------------------------------------------
# 共用函式
# ------------------------------------------------------------


def check_app_version(context: TestContext, *, enforce: bool = False) -> None:
    logger = context.resources.logger
    result = context.adb.shell(f"dumpsys package {PACKAGE_NAME}", check=False)
    output = (result.stdout or "").strip()
    match = re.search(r"versionName=(\S+)", output)
    version = match.group(1) if match else "無法解析"
    if enforce and version != APP_VERSION:
        logger.error(f"app 版本不符：預期 {APP_VERSION}，實際 {version}")
        raise RuntimeError(
            f"app 版本不符：預期 {APP_VERSION}，實際 {version} \
                \n請重新運行 build_push_SemcCameraUI-xxhdpi"
        )
    logger.info(f"目前 app 版本：{version}（預期 {APP_VERSION}）")


# ------------------------------------------------------------
# 清理資料相關函式
# ------------------------------------------------------------


def reset_camera_state(context) -> None:
    context.resources.logger.info(f"清除 {PACKAGE_NAME} 的資料...")
    context.adb.shell(f"pm clear {PACKAGE_NAME}", check=False)


def skip_setup_wizard(context) -> None:
    """推送預設 shared_preferences 跳過教學頁面（需裝置有 su）。"""
    src = TEST_CAMERA_DIR / "tutorial.xml"
    dst = f"/data/data/{PACKAGE_NAME}/shared_prefs/tutorial.xml"

    context.resources.logger.info(f"推送 shared_preferences: {src.name}")
    push(str(src), dst, adb=context.adb)


def handle_permission_dialog(context) -> None:
    """處理相機權限彈窗，嘗試點擊允許"""
    ui = context.resources.ui

    context.resources.logger.info("嘗試處理權限彈窗（按下允許）...")
    if ui.android_version <= 9:
        handle_permission_dialog_9(context)
    else:
        handle_permission_dialog_11(context)


def handle_permission_dialog_9(context):
    ui = context.resources.ui
    for _ in range(3):
        if not ui.wait_then_click("B_允許檔案存取", raise_on_fail=False):
            break

    # if ui.wait_exists("B_儲存地點否", timeout_ms=2000, raise_on_fail=False):
    #     context.resources.logger.error("偵測到異常 UI：儲存地點")
    #     raise RuntimeError("權限彈窗處理失敗，出現儲存地點選項")


def handle_permission_dialog_11(context):
    ui = context.resources.ui

    client = UiAgentInstrumentationClient(ui.adb)
    client.start_instrumentation_service(background=True)

    for _ in range(2):
        if client.wait_then_click(ui["B_使用期間允許"], raise_on_fail=False):
            break

    for key in ["B_允許檔案存取", "B_全部允許"]:
        if client.wait_then_click(ui[key], raise_on_fail=False):
            break

    threading.Thread(target=client.stop_instrumentation_service, daemon=True).start()


# ------------------------------------------------------------
# 初始化相關函式
# ------------------------------------------------------------


def ensure_uiagent_ready(adb: Adb) -> bool:
    component = "com.example.uiagent/com.example.uiagent.UiAgentAccessibilityService"

    enabled_flag = adb.get_setting_secure("accessibility_enabled")
    services = adb.get_setting_secure("enabled_accessibility_services")

    is_enabled = enabled_flag == "1"
    in_services = bool(services) and component in services.split(":")

    return is_enabled and in_services


def ensure_boot_completed(adb: Adb) -> bool:
    result = adb.shell("getprop sys.boot_completed", timeout=10, check=False)
    return result.stdout.strip() == "1"


def wait_ready(context: TestContext, timeout_ms=LL_TIMEOUT) -> None:
    adb = context.adb
    logger = context.resources.logger
    deadline = time.monotonic() + timeout_ms / 1000

    while time.monotonic() < deadline:
        if not ensure_boot_completed(adb):
            time.sleep(0.5)
            continue
        if not ensure_uiagent_ready(adb):
            time.sleep(0.5)
            continue
        logger.info("裝置已準備好")
        return

    logger.error("⚠️ 初始化失敗，裝置未準備好")
    # 直接中止，避免後面 exists/click 沒作用讓你誤判
    raise SystemExit(1)


# ------------------------------------------------------------
# 未整理的函式
# ------------------------------------------------------------


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


def prepare_device(context: TestContext) -> None:
    context.adb.shell("input keyevent KEYCODE_WAKEUP", check=True)  # 喚醒裝置
    context.adb.shell("wm dismiss-keyguard", check=True)  # 解鎖裝置


def handle_overheat(context: TestContext, error_msg, delay=180):
    state = context.resources.ui.wait_exists(
        "STATE_過熱", timeout_ms=10, raise_on_fail=False
    )
    result = error_msg == "相機將暫時關閉以便冷卻。" or state
    if result:
        context.resources.logger.error(f"偵測到過熱保護觸發，等待 {delay} 秒後重試...")
        context.camera.stop_camera()  # 停止相機應用程式
        time.sleep(delay)
    return result


def dump_ui_tree(context: TestContext, session_dir):
    diagnosis_path = session_dir / "diagnosis.txt"
    with open(diagnosis_path, "w", encoding="utf-8") as f:
        elements = list_all_elements_with_class(
            context.resources.ui.adb
        )  # 列出所有元素
        f.write(str(elements))
    context.resources.logger.error(f"已將當前 UI 元素列表輸出到 {diagnosis_path}")


def print_diag(context: TestContext, diag):
    logger = context.resources.logger

    logger.error("----- 診斷結果 -----")
    logger.error(f"{'Camera running':<18}: {'✅' if diag['running'] else '❌'}")
    logger.error(f"{'UI 正常':<18}: {'✅' if diag['ui_ok'] else '❌'}")
    logger.error(f"{'錯誤標題':<18}: {diag['error_title'] or '無'}")
    logger.error(f"{'錯誤訊息':<18}: {diag['error_msg'] or '無'}")


TESTS = [
    TestCase(
        key="photo",
        func=test_photo,
        name="拍照",
        check_saved=True,
        alias="p",
    ),
    TestCase(
        key="photo_settings",
        func=test_photo_settings,
        name="拍照設定選項",
        check_saved=False,
        alias="st",
    ),
    TestCase(
        key="video",
        func=test_video,
        name="錄影",
        check_saved=True,
        alias="v",
    ),
    TestCase(
        key="video_settings",
        func=test_video_settings,
        name="錄影設定選項",
        check_saved=False,
        alias="vst",
    ),
    TestCase(
        key="slow_single",
        func=test_slow_single,
        name="超級慢動作(單拍)",
        check_saved=True,
        alias="so",
    ),
    TestCase(
        key="slow_960",
        func=test_slow_960,
        name="超級慢動作",
        check_saved=True,
        alias="s960",
    ),
    TestCase(
        key="slow_120",
        func=test_slow_120,
        name="慢動作",
        check_saved=True,
        alias="s120",
    ),
]
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


def resolve_tests(tests, args_mods):
    mode_map = {}
    for t in tests:
        mode_map[t.key] = t
        mode_map[t.alias] = t

    return [mode_map[m] for m in args_mods]


def run_camera_test_flow(
    context: TestContext,
    args,
    tests,
    max_retry=5,
) -> None:

    def try_mode_attempt(mode, delay=0) -> bool:
        """執行一次 mode 測試嘗試。成功回傳 True；判定為過熱、可重試回傳 False；
        其他失敗直接 raise RuntimeError。"""
        label = "儲存" if mode.check_saved else ""  # 有check_saved就=儲存
        try:
            t_start = time.monotonic()  # 記錄開始時間
            camera.check_camera_ui_ready(timeout_ms=LL_TIMEOUT)  # 確認 UI 就緒

            logger.info("相機 UI 已準備好")

            test_ok = mode.func(context)
            if mode.check_saved:  # photo_settings 模式不測試儲存
                result = state.wait_for_new_file()
            else:
                result = test_ok
            elapsed = time.monotonic() - t_start  # 計算耗時

            if result:
                logger.info(f"{label}結果: ✅ (耗時 {elapsed:.2f}s)")
                return True

            raise RuntimeError(f"{label}結果: ❌")
        except Exception as e:
            diag = check_all(context)

            if handle_overheat(context, diag["error_msg"], delay=delay):
                camera.launch_camera()  # 啟動相機
                return False  # 過熱，可重試
            else:
                logger.info(f"{label}結果: ❌")
                print_diag(context, diag)  # 印出診斷結果
                dump_ui_tree(
                    context, context.session.session_dir
                )  # 將 UI 列表輸出到 txt，方便分析
                raise RuntimeError(f"模式 {mode.name} 測試失敗") from e

    ui: Ui = context.resources.ui
    camera: CameraController = context.camera
    state: TestState = context.state
    logger: Logger = context.resources.logger

    if args.clear_data:
        reset_camera_state(context)  # 清除相機資料
        skip_setup_wizard(context)  # 推送預設 shared_preferences 跳過教學頁面

    if ui.android_version <= 9:
        ui.wait_then_click("B_原型確定", timeout_ms=2000, raise_on_fail=False)

    camera.launch_camera()  # 啟動相機

    # if args.clear_data:
    #     handle_permission_dialog(context)  # 處理權限彈窗

    test_list = resolve_tests(tests, args.mode)

    idx = 0
    n = 1
    retreated = False  # 標記是否已回退過，避免無限迴圈
    while idx < len(test_list):
        mode = test_list[idx]

        logger.info(f"========== {mode.name} 第 {n}/{max_retry} 次 ==========")

        if try_mode_attempt(mode, 60 + 80 * (n - 1)):
            idx += 1  # 移動到下一個測試項目
            retreated = False  # 重置回退標記
            n = 1  # 重置重試次數
            continue
        else:
            # 如果啟動退回模式，並且不是第一個測試，並且沒回退過，就退到前一個測試
            if args.retreat and idx > 0 and not retreated:
                idx = idx - 1  # 回退到前一個測試項目
                mode = test_list[idx]
                retreated = True  # 標記已回退

            n = n + 1  # 增加重試次數
            if n > max_retry:
                raise RuntimeError(f"模式 {mode.name} 測試失敗")

    context.resources.logger.info(f"========== 結束 {mode.name} 測試 ==========")


def main() -> None:
    args = parse_args(TESTS)
    config = TestConfig(rounds=args.count, interval=args.interval)

    adb = Adb(serial=args.device)
    context = TestContext(adb, ROOT / ".tmp", config)
    state: TestState = context.state
    logger: Logger = context.resources.logger
    camera: CameraController = context.camera
    runner = TestRunner(context)

    runner.start()  # 測試前的初始化，開始 adb log 捕獲（整個 session 只啟動一次）

    try:
        adb.shell("rm -rf /sdcard/DCIM/*", check=False)  # 清空媒體檔案

        state.reset_baseline()  # 設定 DCIM baseline 基準檔案數量
        logger.info(f"當前 DCIM 檔案數量: {state.baseline}")

        wait_ready(context)  # 確認已就緒
        camera.stop_camera()  # 停止相機應用程式
        prepare_device(context)  # 喚醒並解鎖裝置

        check_app_version(context)  # 檢查 app 版本

        for round_no in range(1, args.count + 1):  # 測試幾次
            runner.start_round(round_no)

            success = False
            try:
                run_camera_test_flow(context, args, TESTS)
                success = True
            except Exception as e:
                logger.exception(e)  # 把 完整堆疊資訊 也記錄到 log 中，方便分析
            finally:
                camera.stop_camera()  # 停止相機應用程式

            runner.end_round(success)
            if not success:
                sys.exit(1)  # try/finally 仍會執行，確保 runner.stop() 被呼叫

        logger.info("🎉 所有測試完成，結果: 通過 ✅")
    finally:
        runner.stop()  # 停止 adb log 捕獲，確保背景行程被清乾淨


if __name__ == "__main__":
    main()
