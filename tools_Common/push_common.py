#!/usr/bin/env python3

from pathlib import Path

from .adb import Adb

REPO_ROOT = Path(__file__).resolve().parents[1]
PRIV_APP_DIR = REPO_ROOT / "out/priv-app"
OUT_SO_DIR = REPO_ROOT / "out/so"
ADB_PRIV_APP_DIR = "/system/priv-app"
ADB_LIB_DIR = "/system/lib"
ADB_LIB64_DIR = "/system/lib64"


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
        result = adb.push(str(local_path), temp_remote, check=False)
        if result.returncode != 0:
            print("Failed to push to temporary location")
            return False
    except Exception as exc:
        print(f"Push to temporary location failed: {exc}")
        return False

    # 步驟2: 使用 su 重新掛載 /system 為可寫
    print("Remounting /system as writable with su")
    try:
        remount_cmd = (
            "su -c 'mount -o rw,remount,rw /system || mount -o rw,remount,rw /'"
        )
        result = adb.shell(remount_cmd, check=False)
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

        print(f"Successfully pushed to {remote_destination} using su")
        return True
    except Exception as exc:
        print(f"Move with su failed: {exc}")
        return False


def push(
    local_source: str | Path | list[str | Path],
    remote_destination: str | list[str],
    *,
    adb: Adb,
):
    """
    推送單個或多個執行檔案到裝置。

    Args:
        local_source: 單個檔案路徑或路徑清單
        remote_destination: 對應的遠端目標路徑或路徑清單
        adb: Adb 實例

    Raises:
        FileNotFoundError: 如果本地檔案不存在
        RuntimeError: 如果推送失敗
    """
    adb_client = adb

    # 規範化至清單格式
    if isinstance(local_source, (str, Path)):
        sources = [Path(local_source)]
        destinations = (
            [remote_destination]
            if isinstance(remote_destination, str)
            else remote_destination
        )
    else:
        sources = [Path(s) for s in local_source]
        destinations = (
            remote_destination
            if isinstance(remote_destination, list)
            else [remote_destination]
        )

    # 檢查檔案存在且路徑配對
    for src in sources:
        if not src.exists():
            raise FileNotFoundError(f"{src} does not exist")

    if len(sources) != len(destinations):
        raise ValueError(
            f"Mismatch: {len(sources)} sources but {len(destinations)} destinations"
        )

    # 偵測是否為 userdebug 模式（只需偵測一次）
    is_userdebug = _is_userdebug(adb_client)

    if is_userdebug:
        # userdebug 模式：使用 root 和 remount 推送
        print("Executing: devices")
        adb_client.devices_result(check=False)

        print("Executing: root")
        adb_client.root(check=False)

        print("Executing: remount")
        adb_client.remount(check=False)

        # 推送所有檔案
        for local_path, remote_path in zip(sources, destinations):
            print(f"Executing: push {local_path} {remote_path}")
            adb_client.push(str(local_path), remote_path, check=False)
    else:
        # user 模式：使用 su 推送
        print("Device is not userdebug, using su to push files")
        print("Executing: devices")
        adb_client.devices_result(check=False)

        # 推送所有檔案
        for local_path, remote_path in zip(sources, destinations):
            success = _push_with_su(adb_client, local_path, remote_path)
            if not success:
                raise RuntimeError(
                    f"Failed to push {local_path} to {remote_path} using su"
                )


def push_apk(
    folder_name: str,
    force_stop_package: str | None = None,
    *,
    adb: Adb,
):
    local_apk_path = PRIV_APP_DIR / folder_name / f"{folder_name}.apk"
    remote_path = f"{ADB_PRIV_APP_DIR}/{folder_name}/{folder_name}.apk"

    adb_client = adb

    push(
        local_apk_path,
        remote_path,
        adb=adb_client,
    )

    if force_stop_package:
        try:
            print(f"Attempting to force-stop package: {force_stop_package}")
            adb_client.shell(f"am force-stop {force_stop_package}", check=False)
        except Exception as exc:
            print(f"Force-stop failed: {exc}")


def push_so(
    lib_name: str,
    arch: str = "lib64",
    *,
    local_path: str | Path | None = None,
    remote_dir: str | None = None,
    adb: Adb,
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

    push(local_path, remote_path, adb=adb)


def push_so_list(
    lib_names: list[str],
    arch: str = "lib64",
    *,
    local_paths: list[str | Path] | None = None,
    remote_dir: str | None = None,
    adb: Adb,
):
    """
    推送多個 .so 到裝置。

    Args:
        lib_names: .so 檔名清單
        arch: 架構（'lib' 或 'lib64'）
        local_paths: 本地路徑清單（若為 None 使用預設的 OUT_SO_DIR）
        remote_dir: 遠端目錄
        adb: Adb 實例
    """
    if arch not in ("lib", "lib64"):
        raise ValueError("arch must be either 'lib' or 'lib64'")

    # 決定本地路徑
    if local_paths is None:
        local_paths_list = [OUT_SO_DIR / arch / lib_name for lib_name in lib_names]
    else:
        if len(local_paths) != len(lib_names):
            raise ValueError(
                f"Mismatch: {len(lib_names)} lib_names but {len(local_paths)} local_paths"
            )
        local_paths_list = [Path(p) for p in local_paths]

    # 確認所有檔案存在
    for path in local_paths_list:
        if not path.exists():
            raise FileNotFoundError(f"{path} does not exist")

    # 決定遠端路徑
    remote_base = remote_dir or (ADB_LIB64_DIR if arch == "lib64" else ADB_LIB_DIR)
    remote_paths = [f"{remote_base.rstrip('/')}/{lib_name}" for lib_name in lib_names]

    push(local_paths_list, remote_paths, adb=adb)


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

        if source_path.resolve() == dest_path.resolve():
            print(f"Skipping copy to same path: {dest_path}")
            continue

        print(f"Copying: {source_path} -> {dest_path}")
        try:
            if source_path.is_file():
                shutil.copy2(source_path, dest_path)
            else:
                shutil.copytree(source_path, dest_path, dirs_exist_ok=True)
            print(f"Successfully copied to {dest_path}")
        except Exception as exc:
            print(f"Failed to copy to {dest_path}: {exc}")


def install_apk(
    apk_path: str | Path,
    *,
    adb: Adb,
    force_stop_package: str | None = None,
    timeout: int = 120,
) -> None:
    """
    使用 adb install -r 安裝 APK 到設備。

    Args:
        apk_path: 本地 APK 檔案路徑
        adb: Adb 實例
        force_stop_package: 安裝前強制停止的套件名稱（可選）
        timeout: 超時秒數

    Raises:
        FileNotFoundError: 如果 APK 不存在
        RuntimeError: 如果安裝失敗
    """
    apk = Path(apk_path)
    if not apk.exists():
        raise FileNotFoundError(f"找不到 APK：{apk}")

    if force_stop_package:
        try:
            adb.shell(f"am force-stop {force_stop_package}", check=False)
        except Exception as exc:
            print(f"Force-stop failed: {exc}")

    print(f"Installing: {apk.name}")
    result = adb.run(["install", "-r", str(apk)], check=False, timeout=timeout)
    if result.returncode != 0:
        err = (result.stderr or result.stdout or "").strip()
        raise RuntimeError(f"安裝失敗 ({apk.name}): {err}")
