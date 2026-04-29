#!/usr/bin/env python3
import sys

from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.apk_workflow import run_apk_workflow  # noqa: E402

MODULE_NAME = "SemcCameraUI-xxhdpi"
OUTPUT_NAME = "SemcCameraUI-xxhdpi-release"
PACKAGE_NAME = "com.sonyericsson.android.camera"


def main():
    args = parse_args("Build and push SemcCameraUI-xxhdpi APK.", enable_copy=False)

    run_apk_workflow(
        args=args,
        build_kind="java",
        module_name=MODULE_NAME,
        output_name=OUTPUT_NAME,
        package_name=PACKAGE_NAME,
    )


if __name__ == "__main__":
    main()
