#!/usr/bin/env python3
from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.push_common import push_so

LINEAGE_ROOT = Path.home() / "lineageos"
LUNCH_TARGET = "lineage_poplar_kddi-ap2a-userdebug"
PRODUCT_NAME = "poplar_kddi"

# 你要從 Soong out/system/lib* 拿到的 wrapper 產物檔名
WRAPPER_SOS = [
    "libcacao_client.so",
    "libcacao_service.so",
    "libimageprocessorjni.so",
    "libcacao_process_ctrl_gateway.so",
]

# module name（不含 .so）
WRAPPER_MODULES = [
    "libcacao_client",
    "libcacao_service",
    "libimageprocessorjni",
    "libcacao_process_ctrl_gateway",
    "libcacao_client_real",
    "libcacao_service_real",
    "libcacao_process_ctrl_gateway_real",
]


def run_bash(cmd: str, cwd: Path) -> None:
    print(f"\n[RUN] cwd={cwd}\n{cmd}\n")
    subprocess.run(["bash", "-lc", cmd], cwd=str(cwd), check=True)


def ensure_dir(p: Path) -> None:
    p.mkdir(parents=True, exist_ok=True)


def copy_file(src: Path, dst: Path) -> None:
    ensure_dir(dst.parent)
    shutil.copy2(src, dst)
    print(f"[COPY] {src} -> {dst}")


def copy_glob(src_dir: Path, pattern: str, dst_dir: Path) -> int:
    if not src_dir.exists():
        return 0
    ensure_dir(dst_dir)
    n = 0
    for p in sorted(src_dir.glob(pattern)):
        if p.is_file():
            copy_file(p, dst_dir / p.name)
            n += 1
    return n


def push_staged_libs(out_root: Path) -> None:
    so_root = out_root / "so"
    if not so_root.exists():
        print(f"[WARN] staged library directory missing: {so_root}")
        return
    for arch in ("lib64", "lib"):
        arch_dir = so_root / arch
        if not arch_dir.exists():
            print(f"[WARN] no staged {arch} directory at {arch_dir}")
            continue
        libs = sorted(p for p in arch_dir.glob("*.so") if p.is_file())
        if not libs:
            print(f"[WARN] staged {arch} directory is empty: {arch_dir}")
            continue
        for lib_path in libs:
            print(f"[PUSH] {arch}/{lib_path.name}")
            try:
                push_so(lib_path.name, arch=arch)
            except Exception as exc:  # pragma: no cover - best effort push
                print(f"[WARN] failed to push {lib_path.name}: {exc}")


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Soong build Libcacao wrappers and stage wrappers + *_real.so into SemcCameraApp/out"
    )
    ap.add_argument(
        "-b",
        "--build",
        action="store_true",
        help="Only stage the Libcacao wrappers",
    )
    ap.add_argument(
        "-p",
        "--push",
        action="store_true",
        help="Only push the staged libraries to the device",
    )
    ap.add_argument(
        "--skip-build",
        action="store_true",
        help="只複製，不呼叫 Soong build",
    )
    ap.add_argument("--jobs", type=int, default=0, help="m -jN（0 = 讓 m 自己決定）")
    args = ap.parse_args()
    do_build = args.build or not (args.build or args.push)
    do_push = args.push or not (args.build or args.push)
    repo_root = Path(__file__).resolve().parents[1]
    out_root = repo_root / "out"
    libcacao_root = repo_root / "Libcacao"
    preb32 = libcacao_root / "prebuilts" / "lib"
    preb64 = libcacao_root / "prebuilts" / "lib64"
    product_out = LINEAGE_ROOT / "out" / "target" / "product" / PRODUCT_NAME
    if not product_out.exists():
        raise SystemExit(f"[ERR] 找不到 product out：{product_out}")
    sys64 = product_out / "system" / "lib64"
    sys32 = product_out / "system" / "lib"
    out_so64 = out_root / "so" / "lib64"
    out_so32 = out_root / "so" / "lib"
    print("[INFO] LINEAGE_ROOT =", LINEAGE_ROOT)
    print("[INFO] LUNCH        =", LUNCH_TARGET)
    print("[INFO] PRODUCT      =", PRODUCT_NAME)
    print("[INFO] product_out  =", product_out)
    print("[INFO] repo_root    =", repo_root)
    print("[INFO] out_root     =", out_root)
    print("[INFO] sys64        =", sys64)
    print("[INFO] sys32        =", sys32)
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
        ensure_dir(out_so64)
        ensure_dir(out_so32)
        if not sys64.exists():
            print(f"[WARN] 找不到 system/lib64：{sys64}")
        if not sys32.exists():
            print(f"[WARN] 找不到 system/lib：{sys32}")
        for so in WRAPPER_SOS:
            src64 = sys64 / so
            if src64.exists():
                copy_file(src64, out_so64 / so)
            else:
                print(f"[WARN] 缺少 64-bit wrapper（只查 system/lib64）：{src64}")
            src32 = sys32 / so
            if src32.exists():
                copy_file(src32, out_so32 / so)
            else:
                print(f"[WARN] 缺少 32-bit wrapper（只查 system/lib）：{src32}")
        n64 = copy_glob(preb64, "*_real.so", out_so64)
        n32 = copy_glob(preb32, "*_real.so", out_so32)
        print(f"[REAL] copied: 64-bit={n64}, 32-bit={n32}")
        if n64 == 0:
            print(f"[WARN] prebuilts/lib64 沒有 *_real.so：{preb64}")
        if n32 == 0:
            print(f"[WARN] prebuilts/lib 沒有 *_real.so：{preb32}")
        print("\n[DONE] staged to", out_root)
        print("       64-bit:", out_so64)
        print("       32-bit:", out_so32)
    else:
        print("[INFO] Skipping build/stage step")
    if do_push:
        push_staged_libs(out_root)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
