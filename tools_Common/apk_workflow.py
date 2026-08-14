from argparse import Namespace
from pathlib import Path
from typing import Literal

from .adb import Adb
from .push_common import push
from .build_smali_common import build_smali_app
from .sign_common import sign_and_report_apk
from .build_java_common import build_java_app

ANDROID_TOP = Path("/home/h/lineageos")
REPO_ROOT = Path(__file__).resolve().parents[1]

REPO_OUT_PRIV_APP_DIR = REPO_ROOT / "out/priv-app"
DEVICE_SYSTEM_PRIV_APP_DIR = "/system/priv-app"
DEVICE_MAGISK_PRIV_APP_DIR = "/data/adb/modules/sony_camera/system/priv-app"


def print_section(title: str):
    line = "=" * 50
    print(f"\n{line}\n{title}\n{line}")


def print_kv(key: str, value):
    print(f"{key:<8} : {value}")


def _rel_to_android_top(path: Path) -> Path | str:
    try:
        return path.relative_to(ANDROID_TOP)
    except ValueError:
        return path


def run_apk_workflow(
    *,
    args: Namespace,
    build_kind: Literal["java", "smali"],
    module_name: str,
    output_name: str,
    package_name: str,
) -> None:
    output_apk = REPO_OUT_PRIV_APP_DIR / output_name / f"{output_name}.apk"

    base_dir = "App_java" if build_kind == "java" else "App_smali"
    source_dir = REPO_ROOT / base_dir / module_name

    if args.build:
        output_apk.parent.mkdir(parents=True, exist_ok=True)

        print_section("🚀 編譯任務開始")
        print_kv("模組名稱", module_name)
        print_kv("編譯模式", "Java" if build_kind == "java" else "Smali")
        print_kv("來源目錄", _rel_to_android_top(source_dir))
        print_kv("輸出檔案", _rel_to_android_top(output_apk))

        print_section("⚙️ 執行編譯")
        try:
            if build_kind == "java":
                compiled_apk = build_java_app(
                    source_dir=source_dir,
                    output_apk=output_apk,
                    build_task=":app:assembleRelease",
                )
            else:
                compiled_apk = build_smali_app(
                    source_dir=source_dir,
                    output_apk=output_apk,
                )
            print(f"\n✓ 編譯成功: {compiled_apk}")
        except Exception as e:
            print(f"\n✗ 編譯失敗: {e}")
            raise

        # === 簽名階段 ===
    if args.sign:
        print_section("🔐 APK 簽名")
        try:
            print_kv("目標模組", _rel_to_android_top(source_dir))
            sign_and_report_apk(output_apk)
            print(f"\n✓ 簽名成功: {_rel_to_android_top(output_apk)}")
        except Exception as e:
            print(f"\n✗ 簽名失敗: {e}")
            raise

        print("\n" + "=" * 50 + "\n")
        # === 複製階段 ===

    if args.push:
        print_section("📲 推送到裝置")
        try:
            adb = Adb(serial=args.device)
            print_kv("裝置", args.device or "自動選擇")
            print_kv("套件", package_name)
            print_kv("APK", output_apk.name)

            push_apk(output_name, force_stop_package=package_name, adb=adb)

            print(f"\n✓ 推送成功: {output_name}")

        except Exception as e:
            print(f"\n✗ 推送失敗: {e}")
            raise

    if args.reboot:
        print_section("🔄 重啟裝置")
        adb.reboot()
        print("\n✓ 已送出重啟指令")


def push_apk(
    folder_name: str,
    force_stop_package: str | None = None,
    *,
    adb: Adb,
):
    """
    推送 APK 到 system/priv-app 目錄。

    Args:
        folder_name: APK 資料夾名稱（同時作為檔名）
        force_stop_package: 推送後強制停止的套件名稱（可選）
        adb: Adb 實例
    """
    apk_path = Path(folder_name) / f"{folder_name}.apk"
    local_apk_path = REPO_OUT_PRIV_APP_DIR / apk_path
    device_system_apk_path = f"{DEVICE_SYSTEM_PRIV_APP_DIR}/{apk_path}"  ##
    device_magisk_apk_path = f"{DEVICE_MAGISK_PRIV_APP_DIR}/{apk_path}"  ##

    # 停止相關套件
    if force_stop_package:
        try:
            print(f"強制停止套件: {force_stop_package}")
            adb.shell(f"am force-stop {force_stop_package}", check=False)
        except Exception as exc:
            print(f"強制停止失敗: {exc}")

    # 根據裝置模式決定推送位置
    mode = adb.get_device_mode()
    print(f"推送模式: {mode}")

    if mode == "userdebug":
        # 清理目標目錄中的 oat 資料夾
        oat_dir = f"{DEVICE_SYSTEM_PRIV_APP_DIR}/{folder_name}/oat"
        result = adb.shell(
            f"[ -d {oat_dir} ] && su -c 'rm -rf {oat_dir}' && echo 'removed' || true",
            check=False,
        )
        if "removed" in (result.stdout or ""):
            print(f"已移除: {oat_dir}")

        push(local_apk_path, device_system_apk_path, adb=adb)
    else:
        push(local_apk_path, device_magisk_apk_path, adb=adb)
