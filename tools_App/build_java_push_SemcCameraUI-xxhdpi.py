#!/usr/bin/env python3
import argparse
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.build_java_common import build_java_app  # noqa: E402
from tools_Common.push_common import push_apk  # noqa: E402

ANDROID_TOP = Path("/home/h/lineageos")
PRIV_APP_DIR = ANDROID_TOP / "vendor/sony/yoshino-common/proprietary/system/priv-app"

SOURCE_FOLDER_NAME = "SemcCameraUI-xxhdpi"
OUTPUT_NAME = "SemcCameraUI-xxhdpi-release"
reboot = False
PACKAGE = "com.sonyericsson.android.camera"


def main():
    parser = argparse.ArgumentParser(description=f"Build and push {OUTPUT_NAME}")
    parser.add_argument(
        "-b", "--build", action="store_true", help="Only build and sign the APK"
    )
    parser.add_argument(
        "-p", "--push", action="store_true", help="Only push the APK to the device"
    )
    parser.add_argument(
        "-d",
        "--device",
        type=str,
        default="QV70A5XA11",
        help="Specify device serial number",
    )
    args = parser.parse_args()

    # Default logic: if no arguments, do both
    do_build = args.build or not (args.build or args.push)
    do_push = args.push or not (args.build or args.push)

    if do_build:
        build_java_app(
            SOURCE_FOLDER_NAME,
            source_dir=ROOT / "App_java" / SOURCE_FOLDER_NAME,
            output_dir=PRIV_APP_DIR,
            output_name=OUTPUT_NAME,
            # build_task=":app:assembleRelease",
            build_task=":app:assembleRelease",
        )

    if do_push:
        push_apk(
            OUTPUT_NAME,
            force_stop_package=PACKAGE,
            reboot=reboot,
            device_serial=args.device,
        )


if __name__ == "__main__":
    main()
