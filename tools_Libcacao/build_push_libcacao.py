#!/usr/bin/env python3
"""
build_push_libcacao.py  ─  Soong 編譯 Libcacao wrapper 並部署到設備

流程：
  1. (可選) 清除 Soong 中間檔案快取 (--clean)，避免切換分支後部署舊版 wrapper
  2. 呼叫 Soong `m` 編譯所有 wrapper 模組與 prebuilt _real.so
  3. 將編譯產物複製到 SemcCameraUI/out/{lib,lib64}/
  4. (可選) 驗證 staged .so 是否包含預期符號 (--verify)
  5. 推送到設備 /system/lib{,64}/

重要（main_test 分支 GOT hook）：
  - libcacao_client wrapper：Parcel GOT hook (parcel_got_hook.h)
    攔截 Android-9 blob 中的 Parcel ctor/dtor，修復 Android-14
    Parcel layout 溢位問題（104→120 bytes / 52→60 bytes）。
  - libimageprocessorjni / libcacao_process_ctrl_gateway wrapper：
    Surface alloc GOT hook (surface_alloc_hook.h)
    攔截 operator new()，將 Android-9 硬編碼的 Surface 分配大小
    (0xE70/0x788) 自動加大為 Android-14 的 0x2500，修復 heap overflow。

  如果 Soong 快取了舊分支的 .o，部署的 wrapper 將不含 GOT hook，
  導致執行時閃退。切換分支後請加 --clean 重新編譯。
"""
from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.push_common import push_so, copy_compiled_file  # noqa: E402

LINEAGE_ROOT = Path.home() / "lineageos"
LUNCH_TARGET = "lineage_poplar_kddi-ap2a-userdebug"
PRODUCT_NAME = "poplar_kddi"

# ── Soong 模組名稱（不含 .so） ──
# 前 4 個是 wrapper（由本專案 C++ 原始碼編譯），後 4 個是 prebuilt _real.so
WRAPPER_MODULES = [
    "libcacao_client",
    "libcacao_service",
    "libimageprocessorjni",
    "libcacao_process_ctrl_gateway",
    "libcacao_client_real",
    "libcacao_service_real",
    "libimageprocessorjni_real",
    "libcacao_process_ctrl_gateway_real",
]

# 只有 wrapper 模組（非 _real）需要清除快取
WRAPPER_ONLY_MODULES = [m for m in WRAPPER_MODULES if "_real" not in m]

# Soong 中間檔案根目錄下可能包含 libcacao 快取的子路徑
# Soong 會在多個路徑下產生中間檔案（取決於 Android.bp 位置）
SOONG_INTERMEDIATE_GLOBS = [
    "device/sony/SemcCameraUI/Libcacao",
    "device/sony/SemcCameraApp/Libcacao",
    "device/sony/libcacao_wrappers",
]


def run_bash(cmd: str, cwd: Path) -> None:
    """在 bash -l 中執行命令，失敗時拋出異常"""
    print(f"\n[RUN] cwd={cwd}\n{cmd}\n")
    subprocess.run(["bash", "-lc", cmd], cwd=str(cwd), check=True)


def copy_glob(src_dir: Path, pattern: str, dst_dir: Path) -> int:
    """複製符合 pattern 的檔案到目錄。"""
    if not src_dir.exists():
        return 0
    files = [p for p in sorted(src_dir.glob(pattern)) if p.is_file()]
    for f in files:
        copy_compiled_file(f, dst_dir / f.name)
    return len(files)


def clean_soong_intermediates() -> None:
    """清除 Soong 中間檔案快取，強制下次編譯重新從原始碼生成 .o

    當切換 git 分支（如 main → main_test）後，Soong 可能仍使用舊分支的
    快取 .o 檔案，導致部署的 wrapper .so 不包含新分支的程式碼變更。
    此函式會刪除所有已知路徑下的 libcacao 中間檔案。
    """
    soong_inter = LINEAGE_ROOT / "out" / "soong" / ".intermediates"
    if not soong_inter.exists():
        print("[CLEAN] Soong intermediates 目錄不存在，跳過")
        return

    removed = 0
    for glob_prefix in SOONG_INTERMEDIATE_GLOBS:
        target_dir = soong_inter / glob_prefix
        if target_dir.exists():
            print(f"[CLEAN] 刪除: {target_dir}")
            shutil.rmtree(target_dir, ignore_errors=True)
            removed += 1

    # 同時清除 product out 中的舊 wrapper .so（避免 Soong 認為不需要重建）
    product_out = LINEAGE_ROOT / "out" / "target" / "product" / PRODUCT_NAME
    for d in ("system/lib", "system/lib64"):
        lib_dir = product_out / d
        if not lib_dir.exists():
            continue
        for module in WRAPPER_ONLY_MODULES:
            so_path = lib_dir / f"{module}.so"
            if so_path.exists():
                print(f"[CLEAN] 刪除: {so_path}")
                so_path.unlink()
                removed += 1

    if removed == 0:
        print("[CLEAN] 沒有找到需要清理的快取")
    else:
        print(f"[CLEAN] 已清除 {removed} 個項目")


def verify_wrapper_symbols(so_path: Path) -> bool:
    """驗證 wrapper .so 是否包含 GOT hook 相關的動態符號

    main_test 分支的 wrapper 編譯後應包含:
    - libcacao_client: dlopen/dlsym/mprotect（Parcel GOT hook）
    - libimageprocessorjni / libcacao_process_ctrl_gateway:
      dlsym/mprotect（Surface alloc GOT hook）

    如果缺少這些符號，表示 Soong 使用了舊快取。
    """
    if not so_path.exists():
        return True  # 不存在的檔案不驗證

    try:
        result = subprocess.run(
            ["readelf", "-sD", "--wide", str(so_path)],
            capture_output=True, text=True, timeout=10,
        )
        symbols = set()
        for line in result.stdout.splitlines():
            parts = line.split()
            # readelf 輸出格式: Num: Value Size Type Bind Vis Ndx Name[@VER (N)]
            # Name 在 index 7，可能帶版本標記如 "dlopen@LIBC (5)"
            if len(parts) >= 8:
                raw = parts[7]
                name = raw.split("@")[0]
                if name and not name.startswith("("):
                    symbols.add(name)

        # 根據模組名判斷需要驗證的符號
        name = so_path.name
        if "libcacao_client" in name:
            expected = {"dlopen", "dlsym", "mprotect"}
            desc = "Parcel GOT hook"
        elif "libimageprocessorjni" in name or "libcacao_process_ctrl_gateway" in name:
            expected = {"dlsym", "mprotect"}
            desc = "Surface alloc GOT hook"
        else:
            return True  # 不需要驗證的模組

        missing = expected - symbols
        if missing:
            print(f"[VERIFY] ⚠️  {name} 缺少符號: {missing}")
            print(f"[VERIFY]    可能 Soong 使用了舊快取，建議加 --clean 重新編譯（{desc}）")
            return False
        else:
            size = so_path.stat().st_size
            print(f"[VERIFY] ✅ {name} 包含 {desc} 符號 (size={size})")
            return True
    except (subprocess.TimeoutExpired, FileNotFoundError):
        print("[VERIFY] ⚠️  無法執行 readelf，跳過驗證")
        return True


def push_staged_libs(out_root: Path, device_serial: str | None = None) -> None:
    """推送 staged 的 .so 到設備 /system/lib{,64}/"""
    for arch in ("lib64", "lib"):
        arch_dir = out_root / arch
        if not arch_dir.exists():
            print(f"[WARN] staged {arch} 目錄不存在: {arch_dir}")
            continue
        libs = sorted(p for p in arch_dir.glob("*.so") if p.is_file())
        if not libs:
            print(f"[WARN] staged {arch} 目錄是空的: {arch_dir}")
            continue
        for lib_path in libs:
            print(f"[PUSH] {arch}/{lib_path.name}")
            try:
                push_so(lib_path.name, arch=arch, local_path=lib_path, device_serial=device_serial)
            except Exception as exc:
                print(f"[WARN] 推送 {lib_path.name} 失敗: {exc}")


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Soong 編譯 Libcacao wrapper 並部署到設備。\n"
                    "切換 git 分支後建議加 --clean 避免 Soong 快取問題。",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "-b",
        "--build",
        action="store_true",
        help="只執行編譯 + 複製（不推送到設備）",
    )
    ap.add_argument(
        "-p",
        "--push",
        action="store_true",
        help="只推送已 staged 的 .so 到設備（不重新編譯）",
    )
    ap.add_argument(
        "-s",
        "--skip-build",
        action="store_true",
        help="只複製，不呼叫 Soong build",
    )
    ap.add_argument(
        "-c",
        "--clean",
        action="store_true",
        help="編譯前清除 Soong 快取（切換分支後必須使用，避免部署舊版 wrapper）",
    )
    ap.add_argument(
        "-v",
        "--verify",
        action="store_true",
        help="編譯後驗證 wrapper .so 是否包含 GOT hook 符號",
    )
    ap.add_argument("--jobs", type=int, default=0, help="m -jN（0 = 讓 m 自己決定）")
    ap.add_argument(
        "-d",
        "--device",
        type=str,
        help="指定設備序號",
    )
    args = ap.parse_args()

    # 預設行為：同時 build + push；指定 -b/-p 則只執行對應步驟
    do_build = args.build or not (args.build or args.push)
    do_push = args.push or not (args.build or args.push)

    repo_root = Path(__file__).resolve().parents[1]
    out_root = repo_root / "out"
    libcacao_root = repo_root / "Libcacao"
    product_out = LINEAGE_ROOT / "out" / "target" / "product" / PRODUCT_NAME
    
    if not product_out.exists():
        raise SystemExit(f"[ERR] 找不到 product out：{product_out}")

    # ── 路徑配置 ──
    paths = {
        "sys64": product_out / "system" / "lib64",    # Soong 編譯產出 (64-bit)
        "sys32": product_out / "system" / "lib",      # Soong 編譯產出 (32-bit)
        "out64": out_root / "lib64",                   # 本地 staged 目錄 (64-bit)
        "out32": out_root / "lib",                     # 本地 staged 目錄 (32-bit)
        "preb64": libcacao_root / "prebuilts" / "lib64",  # prebuilt _real.so (64-bit)
        "preb32": libcacao_root / "prebuilts" / "lib",    # prebuilt _real.so (32-bit)
    }

    print(f"[INFO] LINEAGE_ROOT = {LINEAGE_ROOT}")
    print(f"[INFO] LUNCH        = {LUNCH_TARGET}")
    print(f"[INFO] PRODUCT      = {PRODUCT_NAME}")
    print(f"[INFO] product_out  = {product_out}")
    print(f"[INFO] repo_root    = {repo_root}")
    print(f"[INFO] out_root     = {out_root}")

    # ── 清除 Soong 快取（--clean）──
    if args.clean:
        clean_soong_intermediates()

    if do_build:
        if not args.skip_build:
            modules = " ".join(WRAPPER_MODULES)
            jobs = f"-j{args.jobs}" if args.jobs else ""
            m_command = " ".join(part for part in ("m", jobs, modules) if part)
            run_bash(
                f"""
            set -e
            source build/envsetup.sh
            lunch {LUNCH_TARGET}
            {m_command}
            """.strip(),
                cwd=LINEAGE_ROOT,
            )

        # ── 複製 wrapper / _real .so 到 staged 目錄 ──
        for module in WRAPPER_MODULES:
            so = module + ".so"
            if "_real" in module:
                # _real 檔案從 prebuilts 複製（不需要 Soong 編譯）
                src_keys = [("64-bit", "preb64", "out64"), ("32-bit", "preb32", "out32")]
            else:
                # wrapper 檔案從 Soong 編譯產出複製
                src_keys = [("64-bit", "sys64", "out64"), ("32-bit", "sys32", "out32")]
            
            for arch, src_key, out_key in src_keys:
                src = paths[src_key] / so
                if src.exists():
                    copy_compiled_file(src, paths[out_key] / so)
                else:
                    print(f"[WARN] 缺少 {arch} {module}：{src}")

        print(f"\n[DONE] staged 至 {out_root}")
        print(f"       64-bit: {paths['out64']}")
        print(f"       32-bit: {paths['out32']}")

        # ── 驗證 wrapper .so（--verify 或 --clean 時自動驗證）──
        if args.verify or args.clean:
            print("\n[VERIFY] 驗證 wrapper .so 是否包含 GOT hook 符號...")
            # 驗證所有含 GOT hook 的 wrapper
            for module in WRAPPER_ONLY_MODULES:
                for arch in ("lib64", "lib"):
                    so = paths[f"out{'64' if arch == 'lib64' else '32'}"] / f"{module}.so"
                    if so.exists():
                        verify_wrapper_symbols(so)
    else:
        print("[INFO] 跳過 build/stage 步驟")

    if do_push:
        push_staged_libs(out_root, device_serial=args.device)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
