#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.apk_workflow import run_apk_workflow  # noqa: E402
from tools_Common.build_smali_common import build_smali_app  # noqa: E402
from tools_Common.sign_common import sign_and_report_apk  # noqa: E402

SOURCE_FOLDER_NAME = "CameraPanorama"
OUTPUT_NAME = "CameraPanorama-release"
PACKAGE = "com.sonyericsson.android.camera3d"
APK_PATH = ROOT / "out/priv-app" / OUTPUT_NAME / f"{OUTPUT_NAME}.apk"


def main():
    args = parse_args(f"Build and push {OUTPUT_NAME}")

    def build() -> None:
        build_smali_app(
            SOURCE_FOLDER_NAME,
            source_folder_name=SOURCE_FOLDER_NAME,
            output_apk=OUTPUT_NAME,
        )
        sign_and_report_apk(APK_PATH)

    run_apk_workflow(
        args=args,
        output_name=OUTPUT_NAME,
        package=PACKAGE,
        build=build,
    )


if __name__ == "__main__":
    main()
