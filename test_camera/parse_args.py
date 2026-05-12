#!/usr/bin/env python3
import argparse
from dataclasses import dataclass


# ------------------------------------------------------------
# 參數解析
# ------------------------------------------------------------
def positive_int(value):
    ivalue = int(value)
    if ivalue < 1:
        raise argparse.ArgumentTypeError("次數必須 >= 1")
    return ivalue


def parse_args(tests) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Automate taking a photo with the stock camera app."
    )
    parser.add_argument(
        "--clear-data",
        "-c",
        dest="clear_data",
        action="store_true",
        help="Clear the camera app data before interacting with it (default: do nothing).",
    )
    parser.add_argument(
        "--device",
        "-d",
        dest="device",
        type=str,
        help="Specify the device serial number to connect to (optional).",
    )

    def build_help(tests):
        parts = []
        for test in tests:
            parts.append(f"{test.key} ({test.alias})")

        modes_str = ", ".join(parts)
        return f"測試模式 (可多選): {modes_str} (預設: 全測)"

    def mode_mapping(value):
        value = value.lower()
        for test in tests:
            if value == test.key or value == test.alias:
                return test.key
        return value  # 讓 argparse 的 choices 來處理錯誤提示

    choices = [test.key for test in tests]
    default = choices.copy()
    parser.add_argument(
        "--mode",
        "-m",
        dest="mode",
        type=mode_mapping,  # argparse 會對傳入的每個值執行此函式
        nargs="+",  # 關鍵：允許輸入多個值，結果會存為 list
        choices=choices,
        default=default,
        help=build_help(tests),
    )

    parser.add_argument(
        "--count",  # 長參數
        "-n",  # 短參數
        dest="count",  # 存放在 args.count
        type=positive_int,
        default=1,
        help="測試運行次數 (>=1，預設: 1)",
    )
    parser.add_argument(
        "--force_stop",  # 長參數
        "-f",  # 短參數
        dest="force_stop",  # 存放在 args.force_stop
        default=False,
        action="store_true",
        help="使用替代方案停止相機（清除所有 task stack）而非 am force-stop（預設: False）",
    )
    parser.add_argument(
        "--interval",
        "-t",
        type=float,
        default=0,
        help="每次測試之間的間隔秒數，預設 0 秒",
    )
    return parser.parse_args()
