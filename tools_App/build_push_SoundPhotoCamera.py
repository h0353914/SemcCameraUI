#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402
from tools_Common.build_smali_common import build_smali_app  # noqa: E402
from tools_Common.push_common import push_apk, copy_compiled_file  # noqa: E402
from tools_Common.sign_common import sign_and_report_apk  # noqa: E402


ANDROID_TOP = Path("/home/h/lineageos")
REPO_ROOT_PRIV_APP = ROOT / "out/priv-app"
PRIV_APP_DIR = ANDROID_TOP / "vendor/sony/yoshino-common/proprietary/system/priv-app"

SOURCE_FOLDER_NAME = "SoundPhotoCamera-xhdpi"
OUTPUT_NAME = "SoundPhotoCamera-xhdpi-release"
PACKAGE = "com.sonymobile.android.addoncamera.soundphoto"

out = [
    REPO_ROOT_PRIV_APP / OUTPUT_NAME / f"{OUTPUT_NAME}.apk",
    PRIV_APP_DIR / OUTPUT_NAME / f"{OUTPUT_NAME}.apk",
]


def main():
    args = parse_args(f"Build and push {OUTPUT_NAME}")

    apk_path = None

    if args.build:
        apk_path = build_smali_app(
            SOURCE_FOLDER_NAME,
            source_folder_name=SOURCE_FOLDER_NAME,
            output_name=OUTPUT_NAME,
        )
        sign_and_report_apk(apk_path)

    if args.copy:
        copy_compiled_file(
            apk_path if args.build else None,
            out,
        )

    if args.push:
        push_apk(
            OUTPUT_NAME,
            force_stop_package=PACKAGE,
            device_serial=args.device,
        )
        if args.reboot:
            adb = Adb(serial=args.device) if args.device else Adb()
            adb.reboot()


if __name__ == "__main__":
    main()
