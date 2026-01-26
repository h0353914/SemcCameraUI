#!/usr/bin/env python3

from pathlib import Path

from .adb import Adb

REPO_ROOT = Path(__file__).resolve().parents[1]
PRIV_APP_DIR = REPO_ROOT / "out/priv-app"
OUT_SO_DIR = REPO_ROOT / "out/so"
ADB_PRIV_APP_DIR = "/system/priv-app"
ADB_LIB_DIR = "/system/lib"
ADB_LIB64_DIR = "/system/lib64"

DEFAULT_ADB = Adb()


def _run_adb_commands(adb: Adb, commands: list[list[str]]) -> None:
    base_cmd = [adb.adb_path] + (["-s", adb.serial] if adb.serial else [])

    for args in commands:
        cmd_display = " ".join(base_cmd + args)
        print(f"Executing: {cmd_display}")
        try:
            result = adb.run(args, check=False)
        except Exception as exc:
            print(str(exc))
            print(f"Command failed: {cmd_display}")
            break

        if result.stdout:
            print(result.stdout.strip())
        if result.stderr:
            print(result.stderr.strip())
        if result.returncode != 0:
            print(f"Command failed: {cmd_display}")
            break


def push(
    local_source, remote_destination: str, *, adb: Adb | None = None, reboot=False
):
    adb_client = adb or DEFAULT_ADB
    local_path = Path(local_source)
    if not local_path.exists():
        raise FileNotFoundError(f"{local_path} does not exist")

    commands = [
        ["devices"],
        ["root"],
        ["remount"],
        ["push", str(local_path), remote_destination],
    ]

    if reboot:
        commands.append(["reboot"])

    _run_adb_commands(adb_client, commands)


def push_apk(
    folder_name,
    force_stop_package: str | None = None,
    reboot=False,
    adb: Adb | None = None,
    device_serial: str | None = None,
):
    local_apk_path = PRIV_APP_DIR / folder_name / f"{folder_name}.apk"
    remote_path = f"{ADB_PRIV_APP_DIR}/{folder_name}/{folder_name}.apk"

    adb_client = adb or DEFAULT_ADB
    if device_serial:
        adb_client = Adb(serial=device_serial)
    push(local_apk_path, remote_path, adb=adb_client, reboot=reboot)

    if force_stop_package:
        try:
            print(f"Attempting to force-stop package: {force_stop_package}")
            p = adb_client.shell(f"am force-stop {force_stop_package}", check=False)
            if p.stdout:
                print(p.stdout.strip())
            if p.stderr:
                print(p.stderr.strip())
        except Exception as exc:
            print(f"Force-stop failed: {exc}")


def push_so(
    lib_name: str,
    arch: str = "lib64",
    *,
    remote_dir: str | None = None,
    reboot=False,
    adb: Adb | None = None,
):
    adb_client = adb or DEFAULT_ADB
    if arch not in ("lib", "lib64"):
        raise ValueError("arch must be either 'lib' or 'lib64'")

    local_path = OUT_SO_DIR / arch / lib_name
    if not local_path.exists():
        raise FileNotFoundError(f"{local_path} does not exist")

    remote_base = remote_dir or (ADB_LIB64_DIR if arch == "lib64" else ADB_LIB_DIR)
    remote_path = f"{remote_base.rstrip('/')}/{lib_name}"

    push(local_path, remote_path, adb=adb_client, reboot=reboot)
