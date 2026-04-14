#!/usr/bin/env python3
"""
Get all UI elements from the current screen using UiAgent.

This script retrieves all resource-ids and their details from the current
screen displayed on the Android device.
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

from test_camera.uiagent_client import (  # noqa: E402
    is_uiagent_installed,
    list_rids,
    list_all_elements,
    list_all_elements_with_class,
)
from tools_Common.adb import Adb  # noqa: E402


def get_all_elements(adb: Adb) -> dict:
    """
    Get all UI elements from the current screen.

    Returns:
        dict: Contains:
            - rids: List of all resource-ids on the screen
            - count: Total number of elements found
            - status: Operation status ("success" or "error")
            - message: Status message or error description
    """
    try:
        # Check if UiAgent is installed
        if not is_uiagent_installed(adb):
            return {
                "status": "error",
                "message": "UiAgent is not installed on the device",
                "elements": [],
                "count": 0,
            }

        # Get all elements (rid + text) from the current screen
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


def get_all_elements_with_details(adb: Adb) -> dict:
    """
    Get all UI elements with detailed information.

    Returns:
        dict: Contains detailed information about each element including
              position, size, and other properties if available.
    """
    try:
        if not is_uiagent_installed(adb):
            return {
                "status": "error",
                "message": "UiAgent is not installed on the device",
                "elements": [],
            }

        # Get all rids
        rids = list_rids(adb, dedupe=True)

        # Build element list with details
        elements = []
        for rid in rids:
            element = {
                "resource_id": rid,
                "exists": True,  # We know it exists since we got it from list_rids
            }
            elements.append(element)

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


def get_all_elements_with_class(adb: Adb) -> dict:
    """
    Get all UI elements with class information.

    Returns:
        dict: Contains:
            - elements: List of all elements with resource_id, text, and class
            - count: Total number of elements found
            - status: Operation status ("success" or "error")
            - message: Status message or error description
    """
    try:
        # Check if UiAgent is installed
        if not is_uiagent_installed(adb):
            return {
                "status": "error",
                "message": "UiAgent is not installed on the device",
                "elements": [],
                "count": 0,
            }

        # Get all elements with class information from the current screen
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
    """
    Pretty print the elements information.

    Args:
        elements_info: Dictionary returned from get_all_elements()
    """
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
    elements_info: dict, output_file: str = "screen_elements.json"
) -> bool:
    """
    Save the elements information to a JSON file.

    Args:
        elements_info: Dictionary returned from get_all_elements()
        output_file: Path to save the JSON file

    Returns:
        bool: True if successful, False otherwise
    """
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
    """Main entry point."""
    import argparse

    parser = argparse.ArgumentParser(
        description="Get all UI elements from current Android screen"
    )
    parser.add_argument(
        "--details",
        action="store_true",
        help="Get detailed information for each element",
    )
    parser.add_argument(
        "--save", type=str, default=None, help="Save results to JSON file"
    )
    parser.add_argument("--quiet", action="store_true", help="Suppress console output")

    args = parser.parse_args()
    adb = Adb()

    # Get elements
    if args.details:
        elements_info = get_all_elements_with_details(adb)
    else:
        elements_info = get_all_elements(adb)

    # Print results
    if not args.quiet:
        if args.details and "elements" in elements_info:
            print(json.dumps(elements_info, indent=2, ensure_ascii=False))
        else:
            print_elements(elements_info)

    # Save to file if requested
    if args.save:
        save_elements_to_json(elements_info, args.save)

    # Return success status
    return 0 if elements_info.get("status") == "success" else 1


if __name__ == "__main__":
    sys.exit(main())
