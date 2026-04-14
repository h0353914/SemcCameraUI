from __future__ import annotations

from dataclasses import dataclass
import sys
from typing import Iterable, Optional
import json
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1]  # other -> test_camera -> tools
sys.path.insert(0, str(TOOLS_DIR))


@dataclass(frozen=True)
class ClickTarget:
    """
    一個 UI 定義（resource_id 版本）：
    - 只保留 resource_id
    - content-desc / bounds 一律忽略
    """

    key_name: str
    resource_id: Optional[str]
    text: Optional[str] = None
    content_desc: Optional[str] = None
    

def load_label_defs(path: Path) -> list[ClickTarget]:
    """
    讀取 key.json（key:value 格式），轉成 ClickTarget。
    """
    if not path.exists():
        raise FileNotFoundError(f"label json not found: {path}")

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    defs: list[ClickTarget] = []

    if not isinstance(data, dict):
        raise ValueError("label json must be an object")

    for key_name, val in data.items():
        key_name = str(key_name or "")
        
        rid = None
        text = None
        cd = None

        if isinstance(val, str):
            rid = val.strip() or None
        elif isinstance(val, dict):
            rid = val.get("resource_id")
            text = val.get("text")
            cd = val.get("content_desc")
        
        # 如果完全沒有識別資訊就跳過
        if not any([rid, text, cd]):
            continue

        defs.append(
            ClickTarget(
                key_name=key_name,
                resource_id=rid,
                text=text,
                content_desc=cd,
            )
        )

    return defs




def find_click_target(key_name: str, targets: Iterable[ClickTarget]) -> ClickTarget:
    """
    只回傳「指定 key_name 對應的 ClickTarget」。

    假設：
    - 走到這裡代表「邏輯上應該只有一個 target」
    - 不負責確認 UI 上是否真的存在
    - UI 點不到是上層 click / adb 的責任
    """
    candidates = [t for t in targets if t.key_name == key_name]

    if not candidates:
        raise LookupError(f"No ClickTarget with resource_id for key_name={key_name!r}")

    if len(candidates) > 1:
        raise LookupError(f"Multiple ClickTargets found for key_name={key_name!r}")

    return candidates[0]


def load_click_targets(key_path: Path) -> set[ClickTarget]:
    """
    從指定的 key.json 載入 label 定義並展開成可點擊目標集合
    """
    label_defs = load_label_defs(key_path)
    return set(label_defs)
