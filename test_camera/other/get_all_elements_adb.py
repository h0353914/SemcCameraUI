#!/usr/bin/env python3
"""
Get all UI elements from the current screen using adb dumpsys.

This script retrieves all resource-ids and their details from the current
screen displayed on the Android device using adb window dump commands,
without requiring UiAgent service to be installed.
"""

from __future__ import annotations

import json
import sys
import tempfile
import xml.etree.ElementTree as ET
from pathlib import Path
from typing import Optional

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from tools_Common.adb import Adb  # noqa: E402


def get_window_dump(adb: Adb) -> Optional[str]:
    """
    Get the window hierarchy dump from the device using uiautomator dump.

    Returns:
        str: XML content of the window hierarchy, or None if unable to retrieve.
    """
    try:
        # Use uiautomator dump to get the window hierarchy as XML
        # The dump file is created at /sdcard/window_dump.xml
        p = adb.shell("uiautomator dump /sdcard/window_dump.xml", check=True)
        
        # Pull the file from device
        with tempfile.TemporaryDirectory() as tmpdir:
            tmp_path = Path(tmpdir) / "window_dump.xml"
            adb.run(["pull", "/sdcard/window_dump.xml", str(tmp_path)], check=True)
            
            if tmp_path.exists():
                return tmp_path.read_text()
        
        return None
    except Exception as e:
        print(f"Error retrieving window dump: {e}", file=sys.stderr)
        return None


def parse_window_dump(xml_content: str) -> list[dict]:
    """
    Parse the window hierarchy XML and extract all elements with resource-ids.

    Args:
        xml_content: XML string from uiautomator dump

    Returns:
        list: List of dicts containing resource-id and text for each UI element
    """
    elements = []
    
    try:
        root = ET.fromstring(xml_content)
        
        # Walk through all elements in the hierarchy
        for elem in root.iter():
            # Look for resource-id and text attributes
            resource_id = elem.get("resource-id", "").strip()
            text = elem.get("text", "").strip()
            
            # Include elements with resource-id, with or without text
            if resource_id:
                element_data = {
                    "resource_id": resource_id,
                    "text": text,
                    "class": elem.get("class", "").strip(),
                    "content_desc": elem.get("content-desc", "").strip(),
                    "bounds": elem.get("bounds", "").strip(),
                }
                elements.append(element_data)
    
    except ET.ParseError as e:
        print(f"Error parsing XML: {e}", file=sys.stderr)
        return []
    
    return elements


def get_all_elements(adb: Adb) -> dict:
    """
    Get all UI elements from the current screen via adb.

    Returns:
        dict: Contains:
            - elements: List of all elements with resource_id and text
            - count: Total number of elements found
            - status: Operation status ("success" or "error")
            - message: Status message or error description
    """
    try:
        # Retrieve the window dump
        xml_content = get_window_dump(adb)
        
        if not xml_content:
            return {
                "status": "error",
                "message": "Failed to retrieve window dump from device",
                "elements": [],
                "count": 0,
            }
        
        # Parse the XML to extract elements
        elements = parse_window_dump(xml_content)
        
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
            "elements": [],
            "count": 0,
        }


def get_all_elements_with_details(adb: Adb) -> dict:
    """
    Get all UI elements with detailed information.

    Returns:
        dict: Contains detailed information about each element including
              position, size, bounds, and other properties.
    """
    try:
        # Retrieve the window dump
        xml_content = get_window_dump(adb)
        
        if not xml_content:
            return {
                "status": "error",
                "message": "Failed to retrieve window dump from device",
                "elements": [],
            }
        
        # Parse the XML to extract elements with all details
        elements = parse_window_dump(xml_content)
        
        return {
            "status": "success",
            "message": f"Retrieved details for {len(elements)} elements",
            "elements": elements,
            "count": len(elements),
        }
    
    except Exception as e:
        return {
            "status": "error",
            "message": f"Error retrieving element details: {str(e)}",
            "elements": [],
        }


def get_resource_ids(adb: Adb) -> list[str]:
    """
    Get a deduplicated list of all resource-ids on the current screen.

    Returns:
        list: List of unique resource-ids
    """
    result = get_all_elements(adb)
    
    if result["status"] != "success":
        return []
    
    # Extract unique resource-ids
    rids = set()
    for elem in result["elements"]:
        rid = elem.get("resource_id", "").strip()
        if rid:
            rids.add(rid)
    
    return sorted(list(rids))


def print_elements(elements: list[dict]) -> None:
    """Pretty print the elements list."""
    print(json.dumps(elements, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    adb = Adb()
    result = get_all_elements(adb)
    
    if result["status"] == "success":
        print(f"✓ Found {result['count']} elements")
        print("\nElements:")
        print_elements(result["elements"])
    else:
        print(f"✗ Error: {result['message']}")
        sys.exit(1)
