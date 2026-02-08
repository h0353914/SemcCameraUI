#!/usr/bin/env python3
from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.push_common import push_so, copy_compiled_file

LINEAGE_ROOT = Path.home() / "lineageos"
LUNCH_TARGET = "lineage_poplar_kddi-ap2a-userdebug"
PRODUCT_NAME = "poplar_kddi"

# module name（不含 .so）
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
    """推送分階段的 library 到設備。"""
    for arch in ("lib64", "lib"):
        arch_dir = out_root / arch
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
                push_so(lib_path.name, arch=arch, local_path=lib_path, device_serial=device_serial)
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
    ap.add_argument(
        "-d",
        "--device",
        type=str,
        help="Specify device serial number",
    )
    args = ap.parse_args()
    do_build = args.build or not (args.build or args.push)
    do_push = args.push or not (args.build or args.push)

    repo_root = Path(__file__).resolve().parents[1]
    out_root = repo_root / "out"
    libcacao_root = repo_root / "Libcacao"
    product_out = LINEAGE_ROOT / "out" / "target" / "product" / PRODUCT_NAME
    
    if not product_out.exists():
        raise SystemExit(f"[ERR] 找不到 product out：{product_out}")

    # 配置路徑
    paths = {
        "sys64": product_out / "system" / "lib64",
        "sys32": product_out / "system" / "lib",
        "out64": out_root / "lib64",
        "out32": out_root / "lib",
        "preb64": libcacao_root / "prebuilts" / "lib64",
        "preb32": libcacao_root / "prebuilts" / "lib",
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

        # 複製 wrapper .so 檔案
        for module in WRAPPER_MODULES:
            so = module + ".so"
            # 區分 _real 和非 _real 的來源位置
            if "_real" in module:
                # _real 檔案從 prebuilts 複製
                src_keys = [("64-bit", "preb64", "out64"), ("32-bit", "preb32", "out32")]
            else:
                # wrapper 檔案從 system 複製
                src_keys = [("64-bit", "sys64", "out64"), ("32-bit", "sys32", "out32")]
            
            for arch, src_key, out_key in src_keys:
                src = paths[src_key] / so
                if src.exists():
                    copy_compiled_file(src, paths[out_key] / so)
                else:
                    print(f"[WARN] 缺少 {arch} {module}：{src}")

        # 複製其他 *_real.so 檔案（已包含在上面迴圈中）

        print(f"\n[DONE] staged to {out_root}")
        print(f"       64-bit: {paths['out64']}")
        print(f"       32-bit: {paths['out32']}")
    else:
        print("[INFO] Skipping build/stage step")

    if do_push:
        push_staged_libs(out_root, device_serial=args.device)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
