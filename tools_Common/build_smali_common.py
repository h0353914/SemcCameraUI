from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import shutil
import subprocess

REPO_ROOT = Path(__file__).resolve().parents[1]
PRIV_APP_DIR = REPO_ROOT / "out/priv-app"

ANDROID_TOP = Path("/home/h/lineageos")
APKTOOL_JAR = REPO_ROOT / "tools_Common" / "apktool.jar"
DEFAULT_JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")


@dataclass(frozen=True)
class ApktoolBuildError(RuntimeError):
    cmd: list[str]
    returncode: int
    stdout: str
    stderr: str

    def __str__(self) -> str:
        details = self.stderr.strip() or self.stdout.strip() or "未知錯誤"
        return f"apktool 打包失敗 (exit={self.returncode}): {details}"


def build_smali_app(
    folder_name: str,
    source_folder_name: str | None = None,
    output_name: str | None = None,
) -> Path:
    source_folder = source_folder_name or folder_name
    output_name_final = output_name or folder_name
    
    target_folder = REPO_ROOT / "App_smali" / source_folder
    build_dir = PRIV_APP_DIR / output_name_final
    build_dir.mkdir(parents=True, exist_ok=True)

    output_apk = build_dir / f"{output_name_final}.apk"
    print(f"處理資料夾: {target_folder} \n打包到 {output_apk}")

    # Run apktool build to generate the APK from smali resources.
    result = _run_apktool(target_folder, output_apk, DEFAULT_JAVA_CMD)
    if result.returncode != 0:
        raise ApktoolBuildError(
            cmd=result.args if isinstance(result.args, list) else [str(result.args)],
            returncode=result.returncode,
            stdout=result.stdout or "",
            stderr=result.stderr or "",
        )

    print(f"apktool 打包完成: {output_apk}")
    return output_apk


def _run_apktool(
    source_dir: Path, output_apk: Path, java_executable: str
) -> subprocess.CompletedProcess[str]:
    """Run apktool to build the APK."""
    if not APKTOOL_JAR.exists():
        raise FileNotFoundError(f"apktool.jar not found: {APKTOOL_JAR}")

    cmd = [
        java_executable,
        "-jar",
        str(APKTOOL_JAR),
        "b",
        str(source_dir),
        "-o",
        str(output_apk),
    ]
    return subprocess.run(cmd, capture_output=True, text=True)
