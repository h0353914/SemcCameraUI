#!/usr/bin/env python3
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402
from tools_Common.build_java_common import build_java_app  # noqa: E402
from tools_Common.push_common import push_apk, copy_compiled_file  # noqa: E402

ANDROID_TOP = Path("/home/h/lineageos")
REPO_ROOT_PRIV_APP = ROOT / "out/priv-app"
PRIV_APP_DIR = ANDROID_TOP / "vendor/sony/yoshino-common/proprietary/system/priv-app"

SOURCE_FOLDER_NAME = "SemcCameraUI-xxhdpi"
OUTPUT_NAME = "SemcCameraUI-xxhdpi-release"
PACKAGE = "com.sonyericsson.android.camera"

out = [
    REPO_ROOT_PRIV_APP / OUTPUT_NAME / f"{OUTPUT_NAME}.apk",
    PRIV_APP_DIR / OUTPUT_NAME / f"{OUTPUT_NAME}.apk",
]


def main():
    args = parse_args("Build and push SemcCameraUI-xxhdpi APK.")

    signed_apk = None
    if args.build:
        signed_apk = build_java_app(
            SOURCE_FOLDER_NAME,
            source_dir=ROOT / "App_java" / SOURCE_FOLDER_NAME,
            output_name=OUTPUT_NAME,
            build_task=":app:assembleRelease",
        )

    if args.copy:
        copy_compiled_file(
            signed_apk,
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
