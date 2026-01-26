from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import subprocess


REPO_ROOT = Path(__file__).resolve().parents[1]

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
    source_dir: Path,
    output_apk: Path,
) -> Path:
    result = _run_apktool(source_dir, output_apk, DEFAULT_JAVA_CMD)
    if result.returncode != 0:
        raise ApktoolBuildError(
            cmd=result.args if isinstance(result.args, list) else [str(result.args)],
            returncode=result.returncode,
            stdout=result.stdout or "",
            stderr=result.stderr or "",
        )
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
