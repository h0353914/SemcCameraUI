from argparse import Namespace
from pathlib import Path
from typing import Literal

from .adb import Adb
from .push_common import copy_compiled_file, push_apk
from .build_smali_common import build_smali_app
from .sign_common import sign_and_report_apk
from .build_java_common import build_java_app

ANDROID_TOP = Path("/home/h/lineageos")
REPO_ROOT = Path(__file__).resolve().parents[1]

REPO_ROOT_PRIV_APP = REPO_ROOT / "out/priv-app"
PRIV_APP_DIR = ANDROID_TOP / "vendor/sony/yoshino-common/proprietary/system/priv-app"


def print_section(title: str):
    line = "=" * 50
    print(f"\n{line}\n{title}\n{line}")


def print_kv(key: str, value):
    print(f"{key:<8} : {value}")


def run_apk_workflow(
    *,
    args: Namespace,
    build_kind: Literal["java", "smali"],
    module_name: str,
    output_name: str,
    package_name: str,
) -> None:
    output_apk = REPO_ROOT_PRIV_APP / output_name / f"{output_name}.apk"
    copy_targets = [PRIV_APP_DIR / output_name / f"{output_name}.apk"]  # 只對smali有效

    base_dir = "App_java" if build_kind == "java" else "App_smali"
    source_dir = REPO_ROOT / base_dir / module_name

    if args.build:
        output_apk.parent.mkdir(parents=True, exist_ok=True)

        print_section("🚀 編譯任務開始")
        print_kv("模組名稱", module_name)
        print_kv("編譯模式", "Java" if build_kind == "java" else "Smali")
        print_kv("來源目錄", source_dir.relative_to(ANDROID_TOP))
        print_kv("輸出檔案", output_apk.relative_to(ANDROID_TOP))

        print_section("⚙️ 執行編譯")
        try:
            if build_kind == "java":
                compiled_apk = build_java_app(
                    source_dir=source_dir,
                    output_apk=output_apk,
                    build_task=":app:assembleRelease",
                )
            else:
                compiled_apk = build_smali_app(
                    source_dir=source_dir,
                    output_apk=output_apk,
                )
            print(f"\n✓ 編譯成功: {compiled_apk}")
        except Exception as e:
            print(f"\n✗ 編譯失敗: {e}")
            raise

        # === 簽名階段 ===
    if args.sign:
        print_section("🔐 APK 簽名")
        try:
            print_kv("目標模組", source_dir.relative_to(ANDROID_TOP))
            sign_and_report_apk(output_apk)
            print(f"\n✓ 簽名成功: {output_apk.relative_to(ANDROID_TOP)}")
        except Exception as e:
            print(f"\n✗ 簽名失敗: {e}")
            raise

        print("\n" + "=" * 50 + "\n")
        # === 複製階段 ===

    if args.copy and getattr(args, "copy", False):
        print_section("📦 複製輸出檔案")
        try:
            print_kv("來源", output_apk.relative_to(ANDROID_TOP))
            print_kv("目標", copy_targets[0].relative_to(ANDROID_TOP))
            copy_compiled_file(output_apk, copy_targets)
            print(f"\n✓ 複製成功: {copy_targets[0].relative_to(ANDROID_TOP)}")
        except Exception as e:
            print(f"\n✗ 複製失敗: {e}")
            raise

    if args.push:
        print_section("📲 推送到裝置")
        try:
            adb = Adb(serial=args.device)
            print_kv("裝置", args.device or "自動選擇")
            print_kv("套件", package_name)
            print_kv("APK", output_apk.name)

            push_apk(output_name, force_stop_package=package_name, adb=adb)

            print(f"\n✓ 推送成功: {output_name}")

        except Exception as e:
            print(f"\n✗ 推送失敗: {e}")
            raise

    if args.reboot:
        print_section("🔄 重啟裝置")
        adb.reboot()
        print("\n✓ 已送出重啟指令")
