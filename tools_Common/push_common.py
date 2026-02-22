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


def _is_userdebug(adb: Adb) -> bool:
    """
    偵測裝置是否為 userdebug 模式。

    Returns:
        True 如果是 userdebug，False 如果是 user 或其他模式
    """
    try:
        result = adb.shell("getprop ro.build.type", check=False)
        build_type = result.stdout.strip() if result.stdout else ""
        is_debug = build_type == "userdebug"
        print(f"Device build type: {build_type} (userdebug: {is_debug})")
        return is_debug
    except Exception as exc:
        print(f"Failed to detect build type: {exc}")
        return False


def _push_with_su(
    adb: Adb,
    local_path: Path,
    remote_destination: str,
) -> bool:
    """
    使用 su 權限推送檔案到裝置。

    對於 non-userdebug 裝置，先推送到 /data/local/tmp，
    然後使用 su 移動到目標位置。會自動重新掛載 /system 為可寫。

    Returns:
        True 如果推送成功，False 如果失敗
    """

    temp_remote = f"/data/local/tmp/{local_path.name}"

    # 步驟1: 推送到臨時目錄
    print(f"Pushing to temporary location: {temp_remote}")
    try:
        result = adb.run(["push", str(local_path), temp_remote], check=False)
        if result.returncode != 0:
            print("Failed to push to temporary location")
            if result.stderr:
                print(result.stderr.strip())
            return False
        if result.stdout:
            print(result.stdout.strip())
    except Exception as exc:
        print(f"Push to temporary location failed: {exc}")
        return False

    # 步驟2: 使用 su 重新掛載 /system 為可寫
    print("Remounting /system as writable with su")
    try:
        remount_cmd = "su -c 'mount -o rw,remount,rw /system || mount -o rw,remount,rw /'"
        result = adb.shell(remount_cmd, check=False)
        if result.stdout:
            print(result.stdout.strip())
        if result.returncode != 0 and result.stderr:
            print(f"Warning: Remount may have failed: {result.stderr.strip()}")
    except Exception as exc:
        print(f"Warning: Remount failed: {exc}")

    # 步驟3: 建立目標目錄並移動檔案
    print(f"Moving to target location with su: {remote_destination}")
    try:
        # 建立目標目錄
        target_dir = remote_destination.rsplit("/", 1)[0]
        mkdir_cmd = f"su -c 'mkdir -p {target_dir}'"
        result = adb.shell(mkdir_cmd, check=False)
        if result.returncode != 0 and result.stderr:
            print(f"Warning: Failed to create directory: {result.stderr.strip()}")

        # 移動檔案
        mv_cmd = f"su -c 'mv {temp_remote} {remote_destination}'"
        result = adb.shell(mv_cmd, check=False)
        if result.returncode != 0:
            print("Failed to move file to target location")
            if result.stderr:
                print(result.stderr.strip())
            return False

        # 設定權限
        chmod_cmd = f"su -c 'chmod 644 {remote_destination}'"
        result = adb.shell(chmod_cmd, check=False)
        if result.stdout:
            print(result.stdout.strip())

        print(f"Successfully pushed to {remote_destination} using su")
        return True
    except Exception as exc:
        print(f"Move with su failed: {exc}")
        return False


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

    # 偵測是否為 userdebug 模式
    is_userdebug = _is_userdebug(adb_client)

    if is_userdebug:
        # userdebug 模式：使用 root 和 remount 推送
        commands = [
            ["devices"],
            ["root"],
            ["remount"],
            ["push", str(local_path), remote_destination],
        ]

        if reboot:
            commands.append(["reboot"])

        _run_adb_commands(adb_client, commands)
    else:
        # user 模式：使用 su 推送
        print("Device is not userdebug, using su to push file")
        commands = [
            ["devices"],
        ]
        _run_adb_commands(adb_client, commands)

        success = _push_with_su(adb_client, local_path, remote_destination)
        if not success:
            raise RuntimeError(
                f"Failed to push {local_path} to {remote_destination} using su"
            )

        if reboot:
            print("Rebooting device")
            try:
                adb_client.run(["reboot"], check=False)
            except Exception as exc:
                print(f"Reboot failed: {exc}")


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
        local_apk_path,
        remote_path,
        adb=adb_client,
        reboot=reboot,
        device_serial=device_serial,
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
