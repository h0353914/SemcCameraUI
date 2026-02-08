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
    local_source: str | Path,
    remote_destination: str,
    *,
    adb: Adb | None = None,
    reboot=False,
    device_serial: str | None = None,
):
    if device_serial:
        adb_client = Adb(serial=device_serial)
    else:
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
    folder_name: str,
    force_stop_package: str | None = None,
    reboot=False,
    adb: Adb | None = None,
    device_serial: str | None = None,
):
    local_apk_path = PRIV_APP_DIR / folder_name / f"{folder_name}.apk"
    remote_path = f"{ADB_PRIV_APP_DIR}/{folder_name}/{folder_name}.apk"

    if device_serial:
        adb_client = Adb(serial=device_serial)
    else:
        adb_client = adb or DEFAULT_ADB

    push(
        local_apk_path, remote_path, adb=adb_client, reboot=reboot, device_serial=device_serial
    )

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
    local_path: str | Path | None = None,
    remote_dir: str | None = None,
    reboot=False,
    adb: Adb | None = None,
    device_serial: str | None = None,
):
    if arch not in ("lib", "lib64"):
        raise ValueError("arch must be either 'lib' or 'lib64'")

    # 如果提供了自訂的 local_path，使用它；否則使用預設的 OUT_SO_DIR
    if local_path is None:
        local_path = OUT_SO_DIR / arch / lib_name
    else:
        local_path = Path(local_path)
    
    if not local_path.exists():
        raise FileNotFoundError(f"{local_path} does not exist")

    remote_base = remote_dir or (ADB_LIB64_DIR if arch == "lib64" else ADB_LIB_DIR)
    remote_path = f"{remote_base.rstrip('/')}/{lib_name}"

    push(local_path, remote_path, adb=adb, reboot=reboot, device_serial=device_serial)


def copy_compiled_file(
    source: str | Path,
    destinations: str | Path | list[str | Path],
    *,
    create_dirs=True,
):
    """
    複製編譯的檔案到一個或多個目的地位置。
    
    Args:
        source: 原始檔案路徑
        destinations: 目的地路徑，可以是單個路徑或路徑列表
        create_dirs: 如果目的地目錄不存在，是否建立它們（預設為 True）
    
    Raises:
        FileNotFoundError: 如果源檔案不存在
    """
    import shutil
    
    source_path = Path(source)
    if not source_path.exists():
        raise FileNotFoundError(f"{source_path} does not exist")
    
    if not isinstance(destinations, list):
        destinations = [destinations]
    
    for dest in destinations:
        dest_path = Path(dest)
        
        if create_dirs:
            dest_path.parent.mkdir(parents=True, exist_ok=True)
        
        print(f"Copying: {source_path} -> {dest_path}")
        try:
            if source_path.is_file():
                shutil.copy2(source_path, dest_path)
            else:
                shutil.copytree(source_path, dest_path, dirs_exist_ok=True)
            print(f"Successfully copied to {dest_path}")
        except Exception as exc:
            print(f"Failed to copy to {dest_path}: {exc}")
