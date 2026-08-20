#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.apk_workflow import run_apk_workflow


def main():
    run_apk_workflow(
        build_kind="java",
        source_dir=ROOT / "App_smali/app-scan3d",
        output_apk_name="app-scan3d-release",
        package_name="com.sonymobile.scan3d",
        system_subdir="app",
    )


if __name__ == "__main__":
    main()
