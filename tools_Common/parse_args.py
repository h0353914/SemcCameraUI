# tools_Common/parse_args.py
import argparse
from argparse import Namespace


def parse_args(
    description: str = None,
    *,
    enable_build=True,
    enable_push=True,
    enable_copy=True,
    enable_device=True,
    enable_reboot=True,
    enable_sign=True,
    extra_args=None,
) -> Namespace:
    ap = argparse.ArgumentParser(
        description=description or "",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )

    # ── mode ──────────────────────────────
    if enable_build:
        ap.add_argument("-b", "--build", action="store_true", help="只編譯")

    if enable_push:
        ap.add_argument("-p", "--push", action="store_true", help="只推送")

    if enable_copy:
        ap.add_argument("-c", "--copy", action="store_true", help="只複製到out")

    # ── 其他參數 ──────────────────────────────
    if enable_device:
        ap.add_argument("-d", "--device", type=str, help="指定設備序號")

    if enable_reboot:
        ap.add_argument(
            "-r", "--reboot", action="store_true", help="推送完成後重啟設備"
        )

    if enable_sign:
        ap.add_argument(
            "-s", "--sign", action="store_true", help="簽名 APK"
        )

    # ── 額外參數 ──────────────────────────────
    if extra_args:
        extra_args(ap)

    args = ap.parse_args()

    # ── mode 判斷 ────────────────────────────
    has_build = getattr(args, "build", False)
    has_push = getattr(args, "push", False)
    has_copy = getattr(args, "copy", False)
    has_device = getattr(args, "device", None)
    has_reboot = getattr(args, "reboot", False)
    has_sign = getattr(args, "sign", False)

    any_mode = has_build or has_push or has_copy or has_sign

    # device / reboot 只能在 push 或無 mode 使用 ──
    if has_device or has_reboot: #有 device 或 reboot
        if not (has_push or not any_mode): # 沒有 push 且有任意 mode
            ap.error("--device / --reboot 只能在包含 --push 或不指定 mode 時使用")

    # 沒有指定任何 mode，預設為全做
    if not any_mode:
        args.build = True
        args.push = True
        args.copy = True
        args.sign = True
    return args
