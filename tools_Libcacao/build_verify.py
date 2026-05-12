#!/usr/bin/env python3
"""
驗證 libcacao 模組的腳本

功能：
1. 檢查原版正常 (--original, -O)
2. 檢查編譯版正常 (--compiled, -C)
3. 預設兩個都執行

可選模組（預設全部）：
    libimageprocessorjni, libcacao_client, libcacao_service, libcacao_process_ctrl_gateway

使用方式：
    python build_verify.py              # 預設：檢查原版 + 編譯版
    python build_verify.py -O         # 只檢查原版
    python build_verify.py -C        # 只檢查編譯版
    python build_verify.py -C -m libimageprocessorjni  # 只編譯指定模組
"""

import argparse
import subprocess
import sys
from pathlib import Path
import time

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.adb import Adb  # noqa: E402

# # 支援的模組
MODULES = [
    "libimageprocessorjni",
    "libcacao_client",
    "libcacao_service",
    "libcacao_process_ctrl_gateway",
]

DEFAULT_MODULES = {"libimageprocessorjni"}

BUILD_SCRIPT = SEMCCAMERA_ROOT / "tools_Libcacao" / "build_push_libcacao_9.py"
TEST_SCRIPT = SEMCCAMERA_ROOT / "test_camera" / "test_camera.py"

# 相機測試會不斷產生照片/影片，長時間跑下來 DCIM 內檔案數量爆增，
# 曾實際觀察到 SlowMotionPathBuilder 因為找不到不重複的檔名重試 10 次後
# 拋出 NullPointerException 讓相機 App 直接崩潰（與 Libcacao 無關，純粹是
# 檔名空間被塞滿），因此每次測試前清空這兩個資料夾，避免跨次測試累積。



def run_python(script: Path, *args: str) -> subprocess.CompletedProcess:
    """執行 Python 腳本"""
    cmd = [sys.executable, str(script)] + list(args)
    print(f"\n{'=' * 60}")
    print(f"[RUN] {' '.join(cmd)}")
    print(f"{'=' * 60}")
    return subprocess.run(cmd, check=True)


def run_test_camera(adb: Adb, serial: str | None = None) -> tuple[bool, Path | None]:
    """執行相機測試"""
    adb_serial = ["-s", serial] if serial else []
    cmd = [sys.executable, str(TEST_SCRIPT), "-c"] + adb_serial
    print(f"\n{'=' * 60}")
    print(f"[RUN] {' '.join(cmd)}")
    print(f"{'=' * 60}")
    result = subprocess.run(cmd)

    # 取得最新的 log 目錄（由 timestamp 命名）
    log_dir = SEMCCAMERA_ROOT / ".tmp"
    sessions = sorted(log_dir.iterdir(), key=lambda p: p.name, reverse=True)
    latest_log: Path | None = sessions[0] if sessions else None

    return result.returncode == 0, latest_log


def check_original(adb: Adb, serial: str | None = None) -> tuple[bool, Path | None]:
    """檢查原版正常"""
    print("\n" + "=" * 60)
    print("[STEP 1/3] 還原原版 .so")
    print("=" * 60)

    run_python(BUILD_SCRIPT, "-re", "-r")

    print("\n" + "=" * 60)
    print("[STEP 2/3] 等待設備重啟")
    print("=" * 60)

    adb.wait_for_boot()

    print("\n" + "=" * 60)
    print("[STEP 3/3] 執行相機測試")
    print("=" * 60)

    return run_test_camera(adb, serial)


def check_compiled(
    adb: Adb,
    modules: list[str] | None = None,
    serial: str | None = None,
) -> tuple[bool, Path | None]:
    """檢查編譯版正常"""
    print("\n" + "=" * 60)
    print("[STEP 1/4] 還原原版 .so（清除之前狀態）")
    print("=" * 60)

    run_python(BUILD_SCRIPT, "-re")

    print("\n" + "=" * 60)
    print(f"[STEP 2/4] 編譯模組: {', '.join(modules)}")
    print("=" * 60)

    time.sleep(2)  # 等待 2 秒

    run_python(BUILD_SCRIPT, "-r", "-m", *modules)

    print("\n" + "=" * 60)
    print("[STEP 3/4] 等待設備重啟")
    print("=" * 60)

    adb.wait_for_boot()

    print("\n" + "=" * 60)
    print("[STEP 4/4] 執行相機測試")
    print("=" * 60)

    return run_test_camera(adb, serial)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Automate taking a photo with the stock camera app."
    )
    parser.add_argument(
        "--original",
        "-O",
        action="store_true",
        help="只檢查原版正常",
    )
    parser.add_argument(
        "--compiled",
        "-C",
        action="store_true",
        help="只檢查編譯版正常",
    )
    parser.add_argument(
        "--module",
        "-m",
        nargs="+",
        metavar="MODULE",
        help=f"只編譯指定模組（預設全部）\n可用: {', '.join(MODULES)}",
    )
    parser.add_argument(
        "--device",
        "-s",
        metavar="SERIAL",
        default=None,
        help="ADB 設備序列號（預設使用第一個已連接設備）",
    )
    return parser.parse_args()


def main() -> int:

    args = parse_args()
    adb = Adb(serial=args.device)

    print(f"\n{'#' * 60}")
    print("# libcacao 驗證腳本")
    print(f"{'#' * 60}")

    # 決定執行模式
    run_original = True  # 預設執行，除非明確指定只執行編譯版
    run_compiled = True  # 預設執行，除非明確指定只執行原版

    if args.original:
        run_original = True
        run_compiled = False
    if args.compiled:
        run_original = False
        run_compiled = True

    selected_modules = args.module if args.module else DEFAULT_MODULES

    # 測試結果
    result_original: bool | None = None
    result_compiled: bool | None = None
    log_original: Path | None = None
    log_compiled: Path | None = None

    try:
        if run_original:
            print(f"\n{'#' * 60}")
            print("# [模式 1] 檢查原版正常")
            print(f"{'#' * 60}")
            result_original, log_original = check_original(adb, args.device)

        if run_compiled:
            print(f"\n{'#' * 60}")
            print("# [模式 2] 檢查編譯版正常")
            print(f"# 編譯模組: {', '.join(selected_modules)}")
            print(f"{'#' * 60}")
            result_compiled, log_compiled = check_compiled(
                adb, selected_modules, args.device
            )

        # === 顯示結果摘要 ===
        print(f"\n{'#' * 60}")
        print("# 測試結果摘要")
        print(f"{'#' * 60}")
        print()

        if run_original:
            status = "✅ 成功" if result_original else "❌ 失敗"
            log_path = str(log_original) if log_original else "無"
            print(f"# 原版: {status}")
            print(f"# 原版 Log: {log_path}")

        if run_compiled:
            status = "✅ 成功" if result_compiled else "❌ 失敗"
            log_path = str(log_compiled) if log_compiled else "無"
            print(f"# 編譯版: {status}")
            print(f"# 編譯版 Log: {log_path}")

        print()
        print(f"{'#' * 60}")

        # 判斷是否全部通過
        all_pass = (not run_original or result_original is True) and (
            not run_compiled or result_compiled is True
        )
        return 0 if all_pass else 1

    except subprocess.CalledProcessError as exc:
        print(f"\n[ERR] 命令執行失敗: {exc}")
        return 1
    except Exception as exc:
        print(f"\n[ERR] {exc}")
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
