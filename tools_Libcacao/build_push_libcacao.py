#!/usr/bin/env python3
import shutil
import subprocess
import sys
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))


from tools_Common.parse_args import parse_args  # noqa: E402
from tools_Common.push_common import copy_compiled_file, push_so_list  # noqa: E402
from tools_Common.adb import Adb  # noqa: E402

LINEAGE_ROOT = Path.home() / "lineageos"
LUNCH_TARGET = "lineage_poplar_kddi-ap2a-userdebug"
PRODUCT_NAME = "poplar_kddi"

# ── Soong 模組名稱（不含 .so） ──
SOONG_MODULES = [
    "libcacao_client",
    "libcacao_service",
    "libimageprocessorjni",
    "libcacao_process_ctrl_gateway",
]


def push_staged_libs(adb: Adb, out_root: Path) -> None:
    """推送 staged 的 .so 到設備 /system/lib{,64}/（使用清單批量推送）"""
    for arch in ("lib64", "lib"):
        arch_dir = out_root / arch
        if not arch_dir.exists():
            print(f"[WARN] staged {arch} 目錄不存在: {arch_dir}")
            continue
        libs = sorted(p for p in arch_dir.glob("*.so") if p.is_file())
        if not libs:
            print(f"[WARN] staged {arch} 目錄是空的: {arch_dir}")
            continue

        # 使用清單批量推送
        lib_names = [lib_path.name for lib_path in libs]
        print(f"[PUSH] 推送 {len(lib_names)} 個檔案到 {arch}")
        try:
            push_so_list(
                lib_names,
                arch=arch,
                local_paths=libs,
                adb=adb,
            )
        except Exception as exc:
            print(f"[WARN] 推送失敗: {exc}")


def build(paths):
    modules = " ".join(SOONG_MODULES).strip()
    cmd = f"""
        set -e
        source build/envsetup.sh
        lunch {LUNCH_TARGET}
        m {modules}
        """
    print(f"\n[RUN] cwd={LINEAGE_ROOT}\n{cmd}\n")
    subprocess.run(["bash", "-lc", cmd], cwd=str(LINEAGE_ROOT), check=True)


def copy(paths, out_root):

    # ── 複製 wrapper / _real .so 到 staged 目錄 ──

    if out_root.exists():
        print(f"[INFO] 清除 out 目錄：{out_root}")
        shutil.rmtree(out_root)
        out_root.mkdir(parents=True, exist_ok=True)

    for module in SOONG_MODULES:
        so = module + ".so"

        # wrapper 檔案（以及 CUSTOM_COMPILED_REAL 中的 _real 模組）從 Soong 編譯產出複製
        src_keys = [("sys64", "out64"), ("sys32", "out32")]

        for src_key, out_key in src_keys:
            src = paths[src_key] / so
            if src.exists():
                copy_compiled_file(src, paths[out_key] / so)

    print(f"\n[DONE] staged 至 {out_root}")
    print(f"       64-bit: {paths['out64']}")
    print(f"       32-bit: {paths['out32']}")


def main() -> int:
    args = parse_args("編譯並推送 libcacao 相關的 .so 到設備。", enable_sign=False)
    adb = Adb(serial=args.device)

    print("編譯" if args.build else "", end="")
    print("推送" if args.push else "", end="")

    repo_root = Path(__file__).resolve().parents[1]
    out_root = repo_root / "out"

    product_out = LINEAGE_ROOT / "out" / "target" / "product" / PRODUCT_NAME
    paths = {
        "sys64": product_out / "system" / "lib64",  # Soong 編譯產出 (64-bit)
        "sys32": product_out / "system" / "lib",  # Soong 編譯產出 (32-bit)
        "out64": out_root / "lib64",  # 本地 staged 目錄 (64-bit)
        "out32": out_root / "lib",  # 本地 staged 目錄 (32-bit)
    }

    if not product_out.exists():
        raise SystemExit(f"[ERR] 找不到 product out：{product_out}")

    if args.build:
        build(paths)
    if args.copy:
        copy(paths, out_root)
    if args.push:
        push_staged_libs(adb, out_root)
        if not args.reboot:
            return 0
        print("\n[INFO] 正在重啟設備...")
        try:
            adb.reboot(check=False)
        except Exception as exc:
            print(f"[WARN] 重啟失敗: {exc}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
