#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.apk_workflow import run_apk_workflow  # noqa: E402

MODULE_NAME = "SoundPhotoCamera-xhdpi"
OUTPUT_NAME = "SoundPhotoCamera-xhdpi-release"
PACKAGE_NAME = "com.sonymobile.android.addoncamera.soundphoto"


def main():
    args = parse_args(f"Build and push {OUTPUT_NAME}")

    run_apk_workflow(
        args=args,
        build_kind="smali",
        module_name=MODULE_NAME,
        output_name=OUTPUT_NAME,
        package_name=PACKAGE_NAME,
    )


if __name__ == "__main__":
    main()
