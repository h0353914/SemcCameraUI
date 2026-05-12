from __future__ import annotations

from dataclasses import dataclass
import os
import shutil
import subprocess
from pathlib import Path
from typing import Optional


ANDROID_TOP = Path("/home/h/lineageos")
DEFAULT_ANDROID_SDK = Path.home() / "Android" / "Sdk"

REPO_ROOT = Path(__file__).resolve().parents[1]

# 用 ROM tree 的 signapk + platform key（跟你 push script log 的來源一致）
DEFAULT_JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")
SIGNAPK_JAR = ANDROID_TOP / "out/host/linux-x86/framework/signapk.jar"
PLATFORM_PEM = ANDROID_TOP / "build/target/product/security/platform.x509.pem"
PLATFORM_PK8 = ANDROID_TOP / "build/target/product/security/platform.pk8"

CONSCRYPT_LIB_DIR = ANDROID_TOP / "out/host/linux-x86/lib64"  # 簽名依賴


@dataclass(frozen=True)
class JavaBuildError(RuntimeError):
    task: str
    returncode: int
    stdout: str
    stderr: str

    def __str__(self) -> str:
        details = self.stderr.strip() or self.stdout.strip() or "未知錯誤"
        return (
            f"Gradle build failed (task={self.task}, exit={self.returncode}): {details}"
        )


@dataclass(frozen=True)
class ApkSignError(RuntimeError):
    returncode: int
    stdout: str
    stderr: str

    def __str__(self) -> str:
        details = self.stderr.strip() or self.stdout.strip() or "未知錯誤"
        return f"signapk failed (exit={self.returncode}): {details}"


def _prepare_env(additions: Optional[dict[str, str]] = None) -> dict[str, str]:
    env = os.environ.copy()
    if DEFAULT_ANDROID_SDK.exists():
        env.setdefault("ANDROID_HOME", str(DEFAULT_ANDROID_SDK))
        env.setdefault("ANDROID_SDK_ROOT", str(DEFAULT_ANDROID_SDK))
    if additions:
        env.update(additions)
    return env


def _resolve_gradle_executable(project_dir: Path, custom: Optional[str]) -> str:
    if custom:
        return custom
    gradlew = project_dir / "gradlew"
    if gradlew.exists():
        return str(gradlew)
    return "gradle"


def _default_apk_output(project_dir: Path, build_task: str) -> Path:
    """
    你指定：release 預設改用 app-release-unsigned.apk
    並移除掃描 outputs/apk/<variant>/*.apk 取最新的 fallback。
    """
    variant = "debug" if "debug" in build_task.lower() else "release"
    name = "app-debug.apk" if variant == "debug" else "app-release-unsigned.apk"
    return project_dir / "app" / "build" / "outputs" / "apk" / variant / name


def _run_gradle(
    project_dir: Path,
    gradle_cmd: list[str],
    env: dict[str, str],
) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        gradle_cmd,
        cwd=project_dir,
        env=env,
        text=True,
    )


def build_java_app(
    source_dir: Path,
    output_apk: Optional[Path] = None,
    build_task: str | list[str] = ":app:assembleRelease",
) -> Optional[Path]:
    """
    執行 Gradle 任務，並可選擇性地複製輸出 APK。

    Args:
        source_dir: 專案根目錄（含 gradlew）
        output_apk: 複製目標路徑；為 None 時跳過複製（適用於多任務情境）
        build_task: 單個或多個 Gradle 任務名稱

    Returns:
        output_apk（已複製），或 None（未指定 output_apk 時）

    Raises:
        JavaBuildError: 若 Gradle 執行失敗
        FileNotFoundError: 若 output_apk 指定但找不到編譯輸出
    """
    if isinstance(build_task, str):
        tasks = [build_task]
    else:
        tasks = build_task

    gradle_cmd = [_resolve_gradle_executable(source_dir, None)] + tasks
    result = _run_gradle(source_dir, gradle_cmd, _prepare_env())
    if result.returncode != 0:
        raise JavaBuildError(
            task=", ".join(tasks),
            returncode=result.returncode,
            stdout="",
            stderr="",
        )

    if output_apk is None:
        return None

    # 使用第一個非 clean 任務決定 variant
    primary_task = next((t for t in tasks if t != "clean"), tasks[0])
    candidate_apk = _default_apk_output(source_dir, primary_task)
    if not candidate_apk.exists():
        raise FileNotFoundError(f"找不到編譯輸出 APK：{candidate_apk}")

    # 複製到輸出位置
    output_apk.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(str(candidate_apk), str(output_apk))

    return output_apk
