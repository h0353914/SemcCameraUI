#!/usr/bin/env python3
"""
Push 工具模組 - 負責推送檔案到 Android 裝置

分為兩種模式：
- userdebug：使用 root + remount 直接推送
- user：使用 su 先推到 /data/local/tmp 再移動
"""

from pathlib import Path
import shutil

from .adb import Adb

# ============== 常數 ==============
REPO_ROOT = Path(__file__).resolve().parents[1]
PRIV_APP_DIR = REPO_ROOT / "out/priv-app"
OUT_SO_DIR = REPO_ROOT / "out/so"


# ============== 內部實作 ==============


def _push_user(
    adb: Adb,
    sources: list[Path],
    destinations: list[str],
):
    """user 模式：使用 su 推送"""
    print("user 模式 使用 su 推送檔案")
    print("Executing: devices")
    adb.devices_result(check=False)

    # 使用 su 重新掛載 /system 為可寫
    print("Remounting /system as writable with su")
    adb.shell(
        "su -c 'mount -o rw,remount,rw /system '",
        check=False,
    )

    for local_path, remote_path in zip(sources, destinations):
        temp_remote = f"/data/local/tmp/{local_path.name}"
        # 推送到臨時目錄
        print(f"Pushing to temporary location: {temp_remote}")
        result = adb.push(str(local_path), temp_remote, check=False)
        if result.returncode != 0:
            raise RuntimeError(f"Failed to push {local_path} to {temp_remote}")

        # 建立目標目錄並複製檔案（mv 無法跨掛載點移動）
        print(f"Copying to target location with su: {remote_path}")
        target_dir = remote_path.rsplit("/", 1)[0]
        adb.shell(f"su -c 'mkdir -p {target_dir}'", check=False)

        cp_cmd = f"su -c 'cp {temp_remote} {remote_path}'"
        result = adb.shell(cp_cmd, check=False)
        if result.returncode != 0:
            raise RuntimeError(
                f"Failed to copy {local_path} to {remote_path}: "
                + (result.stderr or "").strip()
            )

        # 刪除暫存檔
        adb.shell(f"su -c 'rm {temp_remote}'", check=False)

        adb.shell(f"su -c 'chmod 644 {remote_path}'", check=False)
        print(f"Successfully pushed to {remote_path} using su")


def _push_userdebug(
    adb: Adb,
    sources: list[Path],
    destinations: list[str],
):
    """userdebug 模式：使用 root 和 remount 推送"""
    print("Executing: devices")
    adb.devices_result(check=False)

    print("Executing: root")
    adb.root(check=False)

    print("Executing: remount")
    adb.remount(check=False)

    for local_path, remote_path in zip(sources, destinations):
        print(f"Executing: push {local_path} {remote_path}")
        adb.push(str(local_path), remote_path, check=False)


# ============== 核心推送 ==============


def push(
    local_source: str | Path | list[str | Path],
    remote_destination: str | list[str],
    *,
    adb: Adb,
):
    """
    推送單個或多個檔案到裝置。

    會自動偵測裝置模式（userdebug/user）並選擇適合的推送方式。

    Args:
        local_source: 單個檔案路徑或路徑清單
        remote_destination: 對應的遠端目標路徑或路徑清單
        adb: Adb 實例

    Raises:
        FileNotFoundError: 如果本地檔案不存在
        RuntimeError: 如果推送失敗
    """
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

    # 決定推送模式
    mode = adb.get_device_mode()
    print(f"推送模式: {mode}")

    if mode == "userdebug":
        _push_userdebug(adb, sources, destinations)
    else:
        _push_user(adb, sources, destinations)


# ============== 便捷推送 ==============


def push_lib(
    lib_name: str,
    arch: str = "lib64",
    *,
    local_path: str | Path | None = None,
    remote_dir: str,
    adb: Adb,
):
    """
    推送單個 .so 檔案到裝置。

    Args:
        lib_name: .so 檔名
        arch: 架構（'lib' 或 'lib64'）
        local_path: 自訂本地路徑（預設為 OUT_SO_DIR/<arch>/<lib_name>）
        remote_dir: 自訂遠端目錄（預設為 /system/lib64 或 /system/lib）
        adb: Adb 實例

    Raises:
        ValueError: 如果 arch 不是 'lib' 或 'lib64'
        FileNotFoundError: 如果本地檔案不存在
    """
    if arch not in ("lib", "lib64"):
        raise ValueError("arch must be either 'lib' or 'lib64'")

    if local_path is None:
        local_path = OUT_SO_DIR / arch / lib_name
    else:
        local_path = Path(local_path)

    if not local_path.exists():
        raise FileNotFoundError(f"{local_path} does not exist")

    remote_base = remote_dir
    remote_path = f"{remote_base.rstrip('/')}/{lib_name}"

    push(local_path, remote_path, adb=adb)


def push_lib_list(
    lib_names: list[str],
    arch: str = "lib64",
    *,
    local_paths: list[str | Path] | None = None,
    remote_dir: str | None = None,
    adb: Adb,
):
    """
    推送多個 .so 檔案到裝置。

    Args:
        lib_names: .so 檔名清單
        arch: 架構（'lib' 或 'lib64'）
        local_paths: 本地路徑清單（若為 None 使用預設的 OUT_SO_DIR）
        remote_dir: 遠端目錄
        adb: Adb 實例

    Raises:
        ValueError: 如果 arch 不是 'lib' 或 'lib64'，或路徑數量不符
        FileNotFoundError: 如果本地檔案不存在
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
    remote_base = remote_dir
    remote_paths = [f"{remote_base.rstrip('/')}/{lib_name}" for lib_name in lib_names]

    push(local_paths_list, remote_paths, adb=adb)


# ============== 檔案複製 ==============


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


# ============== APK 安裝 ==============


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
