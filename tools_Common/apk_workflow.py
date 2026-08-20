"""共用的 APK 編譯 / 簽名 / 推送流程。

各 `tools_App_*/build_push_*.py` 只負責描述模組（來源目錄、輸出檔名、套件名、
安裝位置），實際的階段流程統一由 `run_apk_workflow()` 驅動。
"""

from contextlib import contextmanager
from pathlib import Path, PurePosixPath
from typing import Generator, Literal

from .adb import Adb
from .parse_args import parse_args
from .push_common import push
from .build_smali_common import build_smali_app
from .sign_common import sign_and_report_apk
from .build_java_common import build_java_app

ANDROID_TOP = Path("/home/h/lineageos")
REPO_ROOT = Path(__file__).resolve().parents[1]

# 裝置上的安裝根目錄：system 模式直接寫入 /，magisk 模式寫入模組目錄
DEVICE_SYSTEM_ROOT = PurePosixPath("/")
DEVICE_MAGISK_ROOT = PurePosixPath("/data/adb/modules/sony_camera")


def print_section(title: str) -> None:
    line = "=" * 50
    print(f"\n{line}\n{title}\n{line}")


def print_kv(key: str, value) -> None:
    print(f"{key:<8} : {value}")


def _display_path(path: Path) -> Path:
    """盡量以相對於 Android 原始碼根目錄／本 repo 的形式顯示路徑。"""
    for root in (ANDROID_TOP, REPO_ROOT):
        try:
            return path.relative_to(root)
        except ValueError:
            continue
    return path


@contextmanager
def _stage(title: str, label: str) -> Generator[None, None, None]:
    """印出階段標題；階段內失敗時補上錯誤訊息再往上拋。"""
    print_section(title)
    try:
        yield
    except Exception as exc:
        print(f"\n✗ {label}失敗: {exc}")
        raise


def _require_apk(out_apk: Path) -> None:
    if not out_apk.exists():
        raise FileNotFoundError(
            f"找不到 APK：{_display_path(out_apk)}（請先加上 -b 編譯）"
        )


def run_apk_workflow(
    *,
    build_kind: Literal["java", "smali"],
    source_dir: Path | str,
    output_apk_name: str,
    package_name: str,
    system_subdir: Literal["app", "priv-app"] = "priv-app",
    magisk: bool = False,
    build_task: str | list[str] = ":app:assembleRelease",
) -> None:
    """解析 CLI 參數後，依旗標依序執行 編譯 → 簽名 → 推送 → 重啟。

    Args:
        build_kind: "java" 走 Gradle，"smali" 走 apktool。
        source_dir: 模組來源目錄（絕對路徑），由呼叫端明確指定。
        output_apk_name: 輸出 APK 檔名（不含 .apk），同時也是裝置上的目錄名。
        system_subdir: 裝置上要推到 /system/app 還是 /system/priv-app。非特權
            系統 app（例如沒有 privileged="true" 的 android_app_import）要用
            "app"；預設 "priv-app"。
        magisk: 推到 Magisk 模組目錄而非直接覆蓋 /system。
        build_task: Java 模式的 Gradle 任務。
    """
    if build_kind not in ("java", "smali"):
        raise ValueError(f"未知的 build_kind: {build_kind!r}（可用：java / smali）")

    args = parse_args(f"Build and push {output_apk_name}", enable_copy=False)

    source_dir = Path(source_dir)

    # out/ 底下的路徑刻意與裝置上的路徑一致，方便對照
    system_app_path = (
        Path("system") / system_subdir / output_apk_name / f"{output_apk_name}.apk"
    )
    out_apk = REPO_ROOT / "out" / system_app_path
    device_root = DEVICE_MAGISK_ROOT if magisk else DEVICE_SYSTEM_ROOT
    device_apk_path = device_root / system_app_path

    do_build = getattr(args, "build", False)
    do_sign = getattr(args, "sign", False)
    do_push = getattr(args, "push", False)
    do_reboot = getattr(args, "reboot", False)
    device = getattr(args, "device", None)

    _adb: Adb | None = None

    def get_adb() -> Adb:
        nonlocal _adb
        if _adb is None:
            _adb = Adb(serial=device)
        return _adb

    if do_build:
        out_apk.parent.mkdir(parents=True, exist_ok=True)

        print_section("🚀 編譯任務開始")
        print_kv("編譯模式", "Java" if build_kind == "java" else "Smali")
        print_kv("編譯目錄", _display_path(source_dir))
        print_kv("輸出檔案", _display_path(out_apk))
        print_kv("安裝模式", "magisk" if magisk else "system")
        print_kv("推送目錄", device_apk_path.parent)

        with _stage("⚙️ 執行編譯", "編譯"):
            if build_kind == "java":
                compiled_apk = build_java_app(
                    source_dir=source_dir,
                    output_apk=out_apk,
                    build_task=build_task,
                )
            else:
                compiled_apk = build_smali_app(
                    source_dir=source_dir,
                    output_apk=out_apk,
                )
            print(f"\n✓ 編譯成功: {_display_path(compiled_apk or out_apk)}")

    if do_sign:
        with _stage("🔐 APK 簽名", "簽名"):
            print_kv("目標模組", _display_path(source_dir))
            _require_apk(out_apk)
            sign_and_report_apk(out_apk)
            print(f"\n✓ 簽名成功: {_display_path(out_apk)}")

    if do_push:
        with _stage("📲 推送到裝置", "推送"):
            print_kv("裝置", device or "自動選擇")
            print_kv("來源", _display_path(out_apk))
            print_kv("目的地", device_apk_path)

            _require_apk(out_apk)
            push_apk(
                local_apk_path=out_apk,
                device_apk_path=device_apk_path,
                adb=get_adb(),
                force_stop_package=package_name,
            )
            print(f"\n✓ 推送成功: {output_apk_name}")

    if do_reboot:
        print_section("🔄 重啟裝置")
        get_adb().reboot()
        print("\n✓ 已送出重啟指令")


def push_apk(
    *,
    local_apk_path: str | Path,
    device_apk_path: str | PurePosixPath,
    adb: Adb,
    force_stop_package: str | None = None,
) -> None:
    """推送 APK 到裝置指定路徑；userdebug 模式會先清掉舊的 oat 目錄。"""
    device_apk_path = PurePosixPath(device_apk_path)

    if force_stop_package:
        print(f"強制停止套件: {force_stop_package}")
        try:
            adb.shell(f"am force-stop {force_stop_package}", check=False)
        except Exception as exc:
            print(f"強制停止失敗: {exc}")

    # 舊的 oat 會讓系統沿用先前編譯的 dex，必須一併移除
    if adb.get_device_mode() == "userdebug":
        oat_dir = device_apk_path.parent / "oat"
        result = adb.shell(
            f"[ -d '{oat_dir}' ] && su -c 'rm -rf {oat_dir}' && echo 'removed' || true",
            check=False,
        )
        if "removed" in (result.stdout or ""):
            print(f"已移除: {oat_dir}")

    push(local_apk_path, str(device_apk_path), adb=adb)
