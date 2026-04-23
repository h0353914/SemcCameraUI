#!/usr/bin/env python3
"""
使用 adb uiautomator dump 取得目前畫面上的所有 UI 元件，
不需要安裝 UiAgent 服務。
"""

from __future__ import annotations

import json
import sys
import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Optional

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from test_camera.other.get_all_elements import auto_save_key_file
from tools_Common.adb import Adb  # noqa: E402

TMP_DIR = ROOT / ".tmp"




def get_window_dump(adb: Adb) -> Optional[str]:
    """從裝置取得視窗層級資訊（XML）。"""
    try:
        adb.shell("uiautomator dump /sdcard/window_dump.xml", check=True)

        TMP_DIR.mkdir(exist_ok=True)
        tmp_path = TMP_DIR / "window_dump.xml"
        adb.run(["pull", "/sdcard/window_dump.xml", str(tmp_path)], check=True)

        if tmp_path.exists():
            return tmp_path.read_text()

        return None
    except Exception as e:
        print(f"取得 window dump 失敗: {e}", file=sys.stderr)
        return None


def parse_window_dump(xml_content: str) -> list[dict]:
    """解析 XML 內容，提取所有含 resource-id 的 UI 元件。"""
    elements = []

    try:
        root = ET.fromstring(xml_content)

        for elem in root.iter():
            resource_id = elem.get("resource-id", "").strip()
            text = elem.get("text", "").strip()

            if resource_id:
                elements.append({
                    "rid": resource_id,
                    "text": text,
                    "class": elem.get("class", "").strip(),
                    "desc": elem.get("content-desc", "").strip(),
                    "bounds": elem.get("bounds", "").strip(),
                })

    except ET.ParseError as e:
        print(f"XML 解析失敗: {e}", file=sys.stderr)
        return []

    return elements


def get_all_elements(adb: Adb) -> dict:
    """經由 adb 取得目前畫面上所有 UI 元件。

    Returns:
        dict: status / message / elements / count
    """
    try:
        xml_content = get_window_dump(adb)

        if not xml_content:
            return {
                "status": "error",
                "message": "無法從裝置取得 window dump",
                "elements": [],
                "count": 0,
            }

        elements = parse_window_dump(xml_content)

        return {
            "status": "success",
            "message": f"共發現 {len(elements)} 個元件",
            "elements": elements,
            "count": len(elements),
        }

    except Exception as e:
        return {
            "status": "error",
            "message": f"取得元件失敗: {str(e)}",
            "elements": [],
            "count": 0,
        }


def get_resource_ids(adb: Adb) -> list[str]:
    """取得目前畫面上所有不重複的 resource-id 清單。"""
    result = get_all_elements(adb)

    if result["status"] != "success":
        return []

    rids = {elem.get("rid", "").strip() for elem in result["elements"]}
    rids.discard("")
    return sorted(rids)


def print_elements(elements: list[dict]) -> None:
    """格式化印出元件清單。"""
    print(json.dumps(elements, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(
        description="經由 adb uiautomator dump 取得 UI 元件"
    )
    parser.add_argument(
        "--rids-only", action="store_true", help="僅印出不重複的 resource-id 清單"
    )
    parser.add_argument(
        "--save",
        type=str,
        default=None,
        help="將結果儲存為 JSON 檔案（預設: .tmp/screen_elements_adb.json）",
    )
    args = parser.parse_args()
    adb = Adb()

    if args.rids_only:
        rids = get_resource_ids(adb)
        print(json.dumps(rids, indent=2, ensure_ascii=False))
    else:
        result = get_all_elements(adb)
        if result["status"] == "success":
            # 預設自動儲存為 key.json 格式
            if result.get("elements"):
                auto_save_key_file(result["elements"])
            
            if not args.save:
                print_elements(result["elements"])
            else:
                save_path = Path(args.save)
                save_path.parent.mkdir(exist_ok=True)
                save_path.write_text(
                    json.dumps(result, indent=2, ensure_ascii=False), encoding="utf-8"
                )
                print(f"已儲存至: {save_path.resolve()}")
        else:
            print(f"錯誤: {result['message']}", file=sys.stderr)
            sys.exit(1)
