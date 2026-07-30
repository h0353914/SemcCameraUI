#!/usr/bin/env python3

import os
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402
from tools_Common.build_java_common import build_java_app  # noqa: E402
from tools_Common.push_common import install_apk  # noqa: E402


SCRIPT_DIR = Path(__file__).resolve().parent

# APK 列表定義
APK_FILES = [
    (
        SCRIPT_DIR / "app/build/outputs/apk/debug/app-debug.apk",
        "主 APK（無障礙服務）",
    ),
    (
        SCRIPT_DIR / "uiautomation/build/outputs/apk/debug/uiautomation-debug.apk",
        "UiAutomation 主 APK",
    ),
    (
        SCRIPT_DIR
        / "uiautomation/build/outputs/apk/androidTest/debug/uiautomation-debug-androidTest.apk",
        "Instrumentation 測試 APK",
    ),
]

GRADLE_TASKS = [
    ":app:assembleDebug",
    ":uiautomation:assembleDebug",
    ":uiautomation:assembleDebugAndroidTest",
]


def main():
    """編譯 UiAgentService Android 應用（主 APK 與 UiAutomation 測試 APK）"""

    args = parse_args(
        "編譯 UiAgentService Android 應用",
        enable_push=True,
        enable_copy=False,
        enable_device=True,
        enable_reboot=False,
    )
    adb = Adb(serial=args.device)

    try:
        os.chdir(SCRIPT_DIR)

        if args.build:
            print("=" * 50)
            print("開始編譯 APK...")
            build_java_app(SCRIPT_DIR, build_task=GRADLE_TASKS)
            print("=" * 50)
            print("編譯成功！")

        if args.push:
            print("=" * 50)
            print("開始安裝 APK...")
            for apk_path, apk_name in APK_FILES:
                if not apk_path.exists():
                    print(f"⚠️  警告：找不到 {apk_path}，跳過安裝")
                    continue
                print(f"安裝 {apk_name}...")
                install_apk(apk_path, adb=adb)
                print(f"✓ {apk_name} 安裝成功")
            print("=" * 50)
            print("✓ 所有 APK 安裝成功！")

    except subprocess.CalledProcessError as e:
        print("=" * 50)
        print(f"編譯失敗：退出碼 {e.returncode}")
        sys.exit(1)
    except FileNotFoundError:
        print("錯誤：找不到 gradlew 腳本。請確保在 UiAgentService 目錄中。")
        sys.exit(1)


if __name__ == "__main__":
    main()
