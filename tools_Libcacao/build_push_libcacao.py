#!/usr/bin/env python3
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
    else:
        print("[INFO] 跳過 build/stage 步驟")

    if do_push:
        push_staged_libs(out_root, device_serial=args.device)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
