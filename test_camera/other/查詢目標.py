#!/usr/bin/env python3
"""查詢指定 resource-id 的 UI 元件資訊。"""
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from test_camera.uiagent_client import query_elements  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402


adb = Adb()


print(
    query_elements(adb, rid="com.sonyericsson.android.camera:id/hint_text_message")
)
print()

print(
    query_elements(
        adb,
        rid="com.sonyericsson.android.camera:id/mode_switch_animation_name"
    )
)
