#!/usr/bin/env python3
"""
使用 UiAgent 取得目前畫面上的所有 UI 元件。
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from test_camera.uiagent_client import (  # noqa: E402
    list_all_elements,
    list_all_elements_with_class,
)
from tools_Common.adb import Adb  # noqa: E402

TMP_DIR = ROOT / ".tmp"


def elements_to_key_format(elements: list[dict]) -> dict:
    """
    將 elements 清單轉換成 key.json 格式。

    格式：key 為 resource_id，value 為文字或詳細物件
    """
    result = {}

    for i, elem in enumerate(elements, 1):
        rid = elem.get("rid", "").strip()
        text = elem.get("text", "").strip()
        desc = elem.get("desc", "").strip()
        cls = elem.get("class", "").strip()
        bounds = elem.get("bounds", "").strip()

        obj = {}
        if rid:
            obj["rid"] = rid
        if text:
            obj["text"] = text
        if desc:
            obj["desc"] = desc
        if cls:
            obj["class"] = cls
        if bounds:
            obj["bounds"] = bounds
        result[i] = obj if obj else rid

    return result


def auto_save_key_file(elements: list[dict]) -> bool:
    """
    自動儲存 elements 為 .tmp/elements_key.json（key.json 格式）。
    """
    try:
        TMP_DIR.mkdir(exist_ok=True)
        key_data = elements_to_key_format(elements)

        key_file = TMP_DIR / "elements_key.json"
        key_file.write_text(
            json.dumps(key_data, indent=2, ensure_ascii=False), encoding="utf-8"
        )
        return True
    except Exception as e:
        print(f"自動儲存 key.json 失敗: {e}", file=sys.stderr)
        return False


def get_all_elements(adb: Adb) -> dict:
    """
    取得目前畫面上所有 UI 元件（rid + text + desc + bounds）。

    Returns:
        dict: status / message / elements / count
    """
    try:
        elements = list_all_elements(adb)

        return {
            "status": "success",
            "message": f"Found {len(elements)} elements on screen",
            "elements": elements,
            "count": len(elements),
        }

    except Exception as e:
        return {
            "status": "error",
            "message": f"Error retrieving elements: {str(e)}",
            "rids": [],
            "count": 0,
        }


def get_all_elements_with_class(adb: Adb) -> dict:
    """
    取得目前畫面上所有 UI 元件，含 class 資訊。

    Returns:
        dict: status / message / elements / count
    """
    try:
        elements = list_all_elements_with_class(adb)

        return {
            "status": "success",
            "message": f"Found {len(elements)} elements on screen (with class)",
            "elements": elements,
            "count": len(elements),
        }

    except Exception as e:
        return {
            "status": "error",
            "message": f"Error retrieving elements with class: {str(e)}",
            "elements": [],
            "count": 0,
        }


def print_elements(elements_info: dict) -> None:
    """格式化印出元件資訊。"""
    print("\n" + "=" * 100)
    print("UI Elements from Current Screen")
    print("=" * 100)

    print(f"Status: {elements_info.get('status', 'unknown').upper()}")
    print(f"Message: {elements_info.get('message', 'N/A')}")
    print(f"Total Elements: {elements_info.get('count', 0)}")

    elements = elements_info.get("elements", [])
    if elements:
        print("\nElements:")
        print("-" * 100)
        for i, it in enumerate(elements, 1):
            rid = it.get("rid", "")
            txt = it.get("text", "")
            desc = it.get("desc", "")
            bounds = it.get("bounds", "")
            cls = it.get("class", "")

            # Extract range info
            range_cur = it.get("range_cur")
            range_min = it.get("range_min")
            range_max = it.get("range_max")
            range_type = it.get("range_type")

            print(f"No. {i}")
            print(f"  Content-Desc: {desc}")
            print(f"  Text: {txt}")
            print(f"  Resource ID: {rid}")
            print(f"  Class: {cls}")
            print(f"  Bounds: {bounds}")

            if range_cur is not None:
                print(
                    f"  Range: current={range_cur}, min={range_min}, max={range_max}, type={range_type}"
                )

            print()

    print("=" * 100 + "\n")


def save_elements_to_json(
    elements_info: dict, output_file: str = ".tmp/screen_elements.json"
) -> bool:
    """將元件資訊儲存為 JSON 檔案。"""
    try:
        output_path = Path(output_file)
        with open(output_path, "w", encoding="utf-8") as f:
            json.dump(elements_info, f, indent=2, ensure_ascii=False)
        print(f"✓ Elements saved to: {output_path.resolve()}")
        return True
    except Exception as e:
        print(f"✗ Failed to save elements: {str(e)}")
        return False


def main():
    """CLI 入口點。"""
    import argparse

    parser = argparse.ArgumentParser(
        description="取得目前 Android 畫面上的所有 UI 元件"
    )
    parser.add_argument(
        "--class",
        dest="with_class",
        action="store_true",
        help="同時取得每個元件的 class 資訊",
    )
    parser.add_argument("--save", type=str, default=None, help="將結果儲存為 JSON 檔案")
    parser.add_argument("--quiet", action="store_true", help="不輸出至 console")

    args = parser.parse_args()
    adb = Adb()

    if args.with_class:
        elements_info = get_all_elements_with_class(adb)
    else:
        elements_info = get_all_elements(adb)

    if not args.quiet:
        print_elements(elements_info)

    # 預設自動儲存為 key.json 格式
    if elements_info.get("status") == "success" and elements_info.get("elements"):
        auto_save_key_file(elements_info["elements"])

    # 若指定 --save，則額外儲存
    if args.save:
        save_elements_to_json(elements_info, args.save)

    return 0 if elements_info.get("status") == "success" else 1


if __name__ == "__main__":
    sys.exit(main())
