#!/usr/bin/env python3
"""構建 Sony Camera Signature Bypass Xposed 模組"""

import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools_Common.adb import Adb  # noqa: E402

# App_xposed/build_xposed_module.py
MODULE_DIR = Path(__file__).resolve().parent
APK_OUTPUT = MODULE_DIR / "app/build/outputs/apk/release/app-release.apk"
PACKAGE = "com.sony.camera.signaturebypass"


def _gradle_cmd() -> str:
    gradlew = MODULE_DIR / "gradlew"
    if gradlew.exists():
        return str(gradlew)
    return "gradle"


def build_module() -> bool:
    """構建 Xposed 模組 APK"""
    gradle = _gradle_cmd()
    print("🔨 構建 Xposed 模組...")

    subprocess.run([gradle, "clean"], cwd=MODULE_DIR, check=False)
    r = subprocess.run([gradle, "assembleRelease"], cwd=MODULE_DIR)
    if r.returncode != 0:
        print("❌ 構建失敗")
        return False

    if not APK_OUTPUT.exists():
        print(f"❌ APK 未找到: {APK_OUTPUT}")
        return False

    sha = subprocess.run(
        ["sha1sum", str(APK_OUTPUT)], capture_output=True, text=True
    )
    sha1 = sha.stdout.split()[0] if sha.returncode == 0 else "?"
    print(f"✅ 構建成功  {APK_OUTPUT.name}  SHA1: {sha1}")
    return True


def install_module(device_serial: str | None = None) -> bool:
    """安裝模組到設備"""
    if not APK_OUTPUT.exists():
        print(f"❌ APK 不存在，請先構建: python3 {Path(__file__).name} -b")
        return False

    adb = Adb(serial=device_serial)
    print(f"📲 安裝到設備... (adb: {adb.adb_path})")

    result = adb.run(["install", "-r", str(APK_OUTPUT)], check=False)
    if result.returncode != 0:
        print(f"❌ 安裝失敗\n{result.stdout}\n{result.stderr}")
        return False

    print("✅ 安裝成功")
    print("\n📝 後續步驟:")
    print("   1. LSPosed Manager → 啟用模組")
    print("   2. 勾選作用域: 系統框架 (android)")
    print("   3. 重啟設備")
    return True


def check_logs(device_serial: str | None = None) -> None:
    """檢查模組日誌（logcat + LSPosed 日誌文件）"""
    adb = Adb(serial=device_serial)

    # 1. LSPosed 模組日誌（最可靠）
    print("── LSPosed 模組日誌 ──")
    r = adb.shell(
        "su -c 'cat /data/adb/lspd/log/modules_*.log 2>/dev/null'",
        check=False,
    )
    lspd_lines = [
        ln for ln in (r.stdout or "").splitlines() if "SonyCameraBypass" in ln
    ]
    if lspd_lines:
        for ln in lspd_lines[-15:]:
            print(ln)
    else:
        print("（無）")

    # 2. LSPosed verbose 日誌
    print("\n── LSPosed verbose 日誌 ──")
    r = adb.shell(
        "su -c 'cat /data/adb/lspd/log/verbose_*.log 2>/dev/null'",
        check=False,
    )
    verbose_lines = [
        ln
        for ln in (r.stdout or "").splitlines()
        if "SonyCameraBypass" in ln or "signaturebypass" in ln
    ]
    if verbose_lines:
        for ln in verbose_lines[-10:]:
            print(ln)
    else:
        print("（無）")

    # 3. logcat（補充）
    print("\n── logcat ──")
    r = adb.run(["logcat", "-d"], check=False, timeout=15)
    logcat_lines = [
        ln for ln in (r.stdout or "").splitlines() if "SonyCameraBypass" in ln
    ]
    if logcat_lines:
        for ln in logcat_lines[-10:]:
            print(ln)
    else:
        print("（無 SonyCameraBypass）")

    if not lspd_lines and not verbose_lines and not logcat_lines:
        print("\n⚠️  完全未找到模組日誌")
        print("   可能原因: 模組未啟用 / 未重啟 / LSPosed 未安裝")


def main():
    parser = argparse.ArgumentParser(
        description="構建 Sony Camera Signature Bypass Xposed 模組"
    )
    parser.add_argument("-b", "--build", action="store_true", help="只構建模組")
    parser.add_argument("-i", "--install", action="store_true", help="只安裝模組到設備")
    parser.add_argument("-l", "--logs", action="store_true", help="檢查模組日誌")
    parser.add_argument("-d", "--device", type=str, help="指定設備序列號")
    args = parser.parse_args()

    # 無旗標時預設構建+安裝
    if not (args.build or args.install or args.logs):
        args.build = True
        args.install = True

    ok = True

    if args.build:
        ok = build_module()

    if ok and args.install:
        ok = install_module(args.device)

    if args.logs:
        check_logs(args.device)

    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
