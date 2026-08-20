#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.apk_workflow import run_apk_workflow  # noqa: E402


def main():
    run_apk_workflow(
        build_kind="smali",
        source_dir=ROOT / "App_smali/ArtFilterCamera-xhdpi",
        output_apk_name="ArtFilterCamera-xhdpi-release",
        package_name="com.sonyericsson.android.addoncamera.artfilter",
    )


if __name__ == "__main__":
    main()
