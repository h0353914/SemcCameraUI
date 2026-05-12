#!/usr/bin/env python3
"""
編譯並推送 libcacao 相關 .so 到設備 (CMake + NDK 方式)
用於 CMake + 原生 NDK 編譯，不依賴 Gradle
"""

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.push_common import push  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402

LINEAGE_ROOT = Path.home() / "lineageos"
PRODUCT_NAME = "poplar_kddi"
NDK_VERSION = "21.4.7075529"
NDK_ROOT = Path.home() / "Android" / "Sdk" / "ndk" / NDK_VERSION

# ── 編譯的模組名稱（不含 .so 前綴） ──
MODULES = [
    ("libcacao_client", ["armeabi-v7a", "arm64-v8a"]),
    ("libcacao_service", ["armeabi-v7a"]),
    ("libimageprocessorjni", ["armeabi-v7a", "arm64-v8a"]),
    ("libcacao_process_ctrl_gateway", ["armeabi-v7a"]),
]


# MAGISK_MODULE_DIR = "/data/adb/modules/sony_camera"
MAGISK_MODULE_DIR = ""
MAGISK_LIB_DIR = f"{MAGISK_MODULE_DIR}/system/lib"
MAGISK_LIB64_DIR = f"{MAGISK_MODULE_DIR}/system/lib64"

# ── 原版 .so 參考目錄 ──
REFS_32 = SEMCCAMERA_ROOT / "tools_Libcacao" / "refs" / "so_32"
REFS_64 = SEMCCAMERA_ROOT / "tools_Libcacao" / "refs" / "so_64"


def restore_original_libs(out_root: Path) -> None:
    """從 refs 目錄還原原版 .so 到 staged 目錄"""
    if out_root.exists():
        print(f"[INFO] 清除 staged 目錄: {out_root}")
        shutil.rmtree(out_root)

    lib64_dir = out_root / "lib64"
    lib32_dir = out_root / "lib"

    lib64_dir.mkdir(parents=True, exist_ok=True)
    lib32_dir.mkdir(parents=True, exist_ok=True)

    modules_64 = {f"{name}.so" for name, abis in MODULES if "arm64-v8a" in abis}
    modules_32 = {f"{name}.so" for name, abis in MODULES if "armeabi-v7a" in abis}

    # ── 還原 64-bit ──
    restored_64 = 0
    if REFS_64.exists():
        all_64 = list(REFS_64.glob("*.so"))
        for so_file in all_64:
            if so_file.name not in modules_64:
                continue
            dest = lib64_dir / so_file.name
            shutil.copy2(so_file, dest)
            print(f"[RESTORE] {so_file.name} → lib64/")
            restored_64 += 1

    # ── 還原 32-bit ──
    restored_32 = 0
    if REFS_32.exists():
        all_32 = list(REFS_32.glob("*.so"))
        for so_file in all_32:
            if so_file.name not in modules_32:
                continue
            dest = lib32_dir / so_file.name
            shutil.copy2(so_file, dest)
            print(f"[RESTORE] {so_file.name} → lib/")
            restored_32 += 1

    print(f"\n[DONE] 還原至 {out_root}")
    print(f"       64-bit: {lib64_dir} ({restored_64} 個)")
    print(f"       32-bit: {lib32_dir} ({restored_32} 個)")


def push_staged_libs(
    adb: Adb,
    out_root: Path,
    module_filter: set[str] | None = None,
) -> None:
    """推送 staged 的 .so 到 Magisk 模塊目錄（繞過 dm-verity）

    Args:
        module_filter: 若指定，只推送名稱在集合中的模組（不含 .so 副檔名）
    """

    if module_filter:
        print(f"[FILTER] 只推送模組: {', '.join(sorted(module_filter))}")

    sources: list[Path] = []
    destinations: list[str] = []

    for arch in ("lib64", "lib"):
        arch_dir = out_root / arch
        if not arch_dir.exists():
            print(f"[WARN] staged {arch} 目錄不存在: {arch_dir}")
            continue
        libs = sorted(p for p in arch_dir.glob("*.so") if p.is_file())
        if not libs:
            print(f"[WARN] staged {arch} 目錄是空的: {arch_dir}")
            continue

        remote_dir = f"{MAGISK_LIB64_DIR if arch == 'lib64' else MAGISK_LIB_DIR}"
        for lib_path in libs:
            if module_filter and lib_path.stem not in module_filter:
                continue
            sources.append(lib_path)
            destinations.append(f"{remote_dir}/{lib_path.name}")

    if not sources:
        print("[WARN] 沒有檔案需要推送")
        return

    print(f"[PUSH] 推送 {len(sources)} 個檔案到 {MAGISK_LIB_DIR} / {MAGISK_LIB64_DIR}")
    push(sources, destinations, adb=adb)


def build_cmake(libcacao_root: Path, sysroot_path: Path):
    """
    使用 CMake + NDK 編譯所有模組
    CMakeLists.txt now lives in tools_Libcacao/
    """
    tools_root = libcacao_root.parent / "tools_Libcacao"
    build_root = libcacao_root / "build"

    # 清除舊的構建目錄
    if build_root.exists():
        print(f"[INFO] 清除舊的編譯目錄: {build_root}")
        shutil.rmtree(build_root)

    build_root.mkdir(parents=True, exist_ok=True)

    # ── 編譯每個 ABI ──
    for abi in ["armeabi-v7a", "arm64-v8a"]:
        abi_build_dir = build_root / abi / "Release"
        abi_build_dir.mkdir(parents=True, exist_ok=True)

        # 檢查工具鏈文件
        toolchain_file = NDK_ROOT / "build" / "cmake" / "android.toolchain.cmake"
        if not toolchain_file.exists():
            raise SystemExit(f"[ERR] 找不到 NDK 工具鏈: {toolchain_file}")

        cmake_cmd = [
            "cmake",
            "-DCMAKE_TOOLCHAIN_FILE=" + str(toolchain_file),
            "-DANDROID_ABI=" + abi,
            "-DANDROID_PLATFORM=android-28",
            "-DANDROID_STL=none",
            "-DCMAKE_BUILD_TYPE=Release",
            "-DLINEAGE_ROOT=" + str(LINEAGE_ROOT),
            "-DPRODUCT_NAME=" + PRODUCT_NAME,
            "-DLIBCACAO_SYSROOT=" + str(sysroot_path),
            str(tools_root),  # CMakeLists.txt now in tools_Libcacao/
        ]

        print(f"\n[CMAKE] {abi}")
        print(f"  dir: {abi_build_dir}")
        subprocess.run(cmake_cmd, cwd=str(abi_build_dir), check=True)

        # 構建
        print(f"[BUILD] {abi}")
        subprocess.run(
            ["cmake", "--build", ".", "--config", "Release", "-j8"],
            cwd=str(abi_build_dir),
            check=True,
        )


def _strip_so(so_path: Path) -> None:
    """Strip debug info from a shared library using NDK strip"""
    import subprocess

    ndk_root = Path.home() / "Android" / "Sdk" / "ndk" / NDK_VERSION
    # 根據 ABI 選擇對應的 strip 工具
    # 從檔案路徑判斷是 32-bit 還是 64-bit
    parent = so_path.parent.name
    if parent == "lib64":
        strip_tool = (
            ndk_root
            / "toolchains"
            / "aarch64-linux-android-4.9"
            / "prebuilt"
            / "linux-x86_64"
            / "bin"
            / "aarch64-linux-android-strip"
        )
    else:
        strip_tool = (
            ndk_root
            / "toolchains"
            / "arm-linux-androideabi-4.9"
            / "prebuilt"
            / "linux-x86_64"
            / "bin"
            / "arm-linux-androideabi-strip"
        )
    if strip_tool.exists():
        result = subprocess.run(
            [str(strip_tool), "-s", str(so_path)], capture_output=True, text=True
        )
        if result.returncode == 0:
            print(f"[STRIP] {so_path.name} ({so_path.stat().st_size} bytes)")
        else:
            print(f"[WARN] Strip failed for {so_path.name}: {result.stderr.strip()}")
    else:
        print(f"[WARN] Strip tool not found: {strip_tool}")


def copy_binaries(libcacao_root: Path, out_root: Path):
    """
    複製編譯產出的 .so 到 staged 目錄
    """
    if out_root.exists():
        print(f"[INFO] 清除 staged 目錄: {out_root}")
        shutil.rmtree(out_root)

    build_root = libcacao_root / "build"
    lib64_dir = out_root / "lib64"
    lib32_dir = out_root / "lib"

    lib64_dir.mkdir(parents=True, exist_ok=True)
    lib32_dir.mkdir(parents=True, exist_ok=True)

    # ── 複製 arm64-v8a 到 lib64 ──
    arm64_build = build_root / "arm64-v8a" / "Release"
    if arm64_build.exists():
        for so_file in arm64_build.glob("*.so"):
            dest = lib64_dir / so_file.name
            print(f"[COPY] {so_file.name} → lib64/")
            shutil.copy2(so_file, dest)
            # Strip debug info
            _strip_so(dest)

    # ── 複製 armeabi-v7a 到 lib ──
    arm32_build = build_root / "armeabi-v7a" / "Release"
    if arm32_build.exists():
        for so_file in arm32_build.glob("*.so"):
            dest = lib32_dir / so_file.name
            print(f"[COPY] {so_file.name} → lib/")
            shutil.copy2(so_file, dest)
            # Strip debug info
            _strip_so(dest)

    print(f"\n[DONE] staged 至 {out_root}")
    print(f"       64-bit: {lib64_dir} ({len(list(lib64_dir.glob('*.so')))} 個)")
    print(f"       32-bit: {lib32_dir} ({len(list(lib32_dir.glob('*.so')))} 個)")


def main() -> int:
    def extra_restore_args(ap: argparse.ArgumentParser):
        ap.add_argument(
            "--restore",
            "-re",
            action="store_true",
            help="從 refs 目錄還原原版 .so（忽略編譯）",
        )
        ap.add_argument(
            "--module",
            "-m",
            nargs="+",
            metavar="MODULE",
            help=(
                "只推送指定模組名稱（不含 .so 前綴），可指定多個，預設全推。\n"
                "可用模組: " + ", ".join(name for name, _ in MODULES)
            ),
        )

    args = parse_args(
        "編譯並推送 libcacao 相關的 .so 到設備 (CMake + NDK)",
        enable_sign=False,
        extra_args=extra_restore_args,
    )
    adb = Adb(serial=args.device)

    libcacao_root = SEMCCAMERA_ROOT / "Libcacao"
    tools_root = SEMCCAMERA_ROOT / "tools_Libcacao"
    out_root = SEMCCAMERA_ROOT / "out"
    sysroot_path = tools_root / "sysroot"

    # 檢查必要目錄
    if not libcacao_root.exists():
        raise SystemExit(f"[ERR] 找不到 Libcacao 目錄: {libcacao_root}")

    if not sysroot_path.exists():
        raise SystemExit(
            f"[ERR] 找不到 sysroot: {sysroot_path}\n"
            "請先執行: python tools_Libcacao/fetch_sysroot.py"
        )

    if not NDK_ROOT.exists():
        raise SystemExit(f"[ERR] 找不到 NDK: {NDK_ROOT}")

    # --restore 是獨立模式，關閉其他編譯相關操作
    if args.restore:
        args.build = False
        args.copy = False

    action = ""
    if args.restore:
        action += "還原 "
    if args.build:
        action += "編譯 "
    if args.copy:
        action += "複製 "
    if args.push:
        action += "推送 "

    print(f"\n{'=' * 60}")
    print("[libcacao] CMake + NDK 編譯系統")
    print(f"{'=' * 60}")
    print(f"[ACT] {action if action else '查詢'}")
    print(f"[NDK] {NDK_ROOT}")
    print(f"[LIB] {libcacao_root}")
    print(f"[OUT] {out_root}")
    print(f"{'=' * 60}\n")

    module_filter: set[str] | None = None
    if getattr(args, "module", None):
        valid_names = {name for name, _ in MODULES}
        unknown = set(args.module) - valid_names
        if unknown:
            raise SystemExit(
                f"[ERR] 未知模組: {', '.join(sorted(unknown))}\n"
                f"可用模組: {', '.join(sorted(valid_names))}"
            )
        module_filter = set(args.module)

    try:
        if args.restore:
            restore_original_libs(out_root)
        if args.build:
            build_cmake(libcacao_root, sysroot_path)

        if args.copy:
            copy_binaries(libcacao_root, out_root)

        if args.push:
            push_staged_libs(adb, out_root, module_filter)
            if not args.reboot:
                return 0
            print("\n[INFO] 正在重啟設備...")
            try:
                adb.reboot(check=False)
            except Exception as exc:
                print(f"[WARN] 重啟失敗: {exc}")

        return 0

    except Exception as exc:
        print(f"\n[ERR] {exc}")
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
