import argparse
from pathlib import Path
import re
import sys
import threading
import time

ROOT = Path(__file__).resolve().parents[1]  # /home/h/lineageos/device/sony/SemcCameraUI
TEST_CAMERA_DIR = Path(__file__).resolve().parent  # ./test_camera
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(TEST_CAMERA_DIR))

from test_camera import get_camera_mode, get_click_map
import uiagent_client as uiagent_client  # noqa: E402
import uiagent_instrumentation_client as uiagent_instrumentation_client  # noqa: E402
from key import (  # noqa: E402
    load_click_targets,
)
from uiagent_client import (  # noqa: E402
    ClickFailedError,
    WaitTargetNotFoundError,
    click_child_under_rid,
    click_then_appear,
    click_then_disappear,
    exists,
    query_elements,
    wait_exists,
    wait_then_click,
)
from uiagent_instrumentation_client import (  # noqa: E402
    UiAgentInstrumentationClient,
)
from tools_Common.adb import Adb  # noqa: E402

adb = Adb()

click_map = get_click_map()
print(get_camera_mode(adb, click_map))