from __future__ import annotations

from dataclasses import dataclass
import os
import shutil
import subprocess
from pathlib import Path
from typing import Iterable, Optional

ANDROID_TOP = Path("/home/h/lineageos")
DEFAULT_ANDROID_SDK = Path.home() / "Android" / "Sdk"

REPO_ROOT = Path(__file__).resolve().parents[1]
PRIV_APP_DIR = REPO_ROOT / "out/priv-app"

# 用 ROM tree 的 signapk + platform key（跟你 push script log 的來源一致）
DEFAULT_JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")
SIGNAPK_JAR = ANDROID_TOP / "out/host/linux-x86/framework/signapk.jar"
PLATFORM_PEM = ANDROID_TOP / "build/target/product/security/platform.x509.pem"
PLATFORM_PK8 = ANDROID_TOP / "build/target/product/security/platform.pk8"

CONSCRYPT_LIB_DIR = ANDROID_TOP / "out/host/linux-x86/lib64"

@dataclass(frozen=True)
class JavaBuildError(RuntimeError):
    task: str
    returncode: int
    stdout: str
    stderr: str

    def __str__(self) -> str:
        details = self.stderr.strip() or self.stdout.strip() or "未知錯誤"
        return f"Gradle build failed (task={self.task}, exit={self.returncode}): {details}"


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
    print(f"執行 Gradle 程式: {' '.join(gradle_cmd)} (cwd={project_dir})")
    print("=" * 80)
    return subprocess.run(
        gradle_cmd,
        cwd=project_dir,
        env=env,
        text=True,
    )


def _sign_apk(
    in_apk: Path,
    out_apk: Path,
    *,
    java_cmd: str = DEFAULT_JAVA_CMD,
    signapk_jar: Path = SIGNAPK_JAR,
    platform_pem: Path = PLATFORM_PEM,
    platform_pk8: Path = PLATFORM_PK8,
    min_sdk: int = 4,
    java_library_path: Optional[Path] = None,
) -> None:
    if not signapk_jar.exists():
        raise FileNotFoundError(f"signapk.jar not found: {signapk_jar}")
    if not platform_pem.exists():
        raise FileNotFoundError(f"platform.x509.pem not found: {platform_pem}")
    if not platform_pk8.exists():
        raise FileNotFoundError(f"platform.pk8 not found: {platform_pk8}")
    if not in_apk.exists():
        raise FileNotFoundError(f"input apk not found: {in_apk}")

    cmd = [java_cmd]
    if java_library_path:
        cmd.append(f"-Djava.library.path={java_library_path}")
    cmd += [
        "-jar",
        str(signapk_jar),
        "-a",
        str(min_sdk),
        str(platform_pem),
        str(platform_pk8),
        str(in_apk),
        str(out_apk),
    ]

    print("=" * 80)
    print("簽名 APK...")
    print("執行命令:")
    print(" ".join(cmd))
    print("=" * 80)
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        if result.stdout:
            print("STDOUT:", result.stdout)
        if result.stderr:
            print("STDERR:", result.stderr)
        raise ApkSignError(
            returncode=result.returncode,
            stdout=result.stdout or "",
            stderr=result.stderr or "",
        )
    print("✓ APK 簽名完成")
    print("=" * 80)


def build_java_app(
    folder_name: str,
    source_dir: Optional[Path] = None,
    output_dir: Optional[Path] = None,
    apk_output: Optional[Path] = None,
    build_task: str = ":app:assembleRelease",
    build_args: Optional[Iterable[str]] = None,
    build_executable: Optional[str] = None,
    env_overrides: Optional[dict[str, str]] = None,
    *,
    # 你指定：編譯 > 簽名 > 複製到 out/priv-app/...；所以預設直接簽
    sign: bool = True,
    java_library_path: Optional[Path] = None,
    output_name: Optional[str] = None,
) -> Path:
    """
    統一邏輯（以 out/priv-app 為 canonical）：
      - 編譯
      - 簽名（signapk，預設開）
      - 複製到 out/priv-app/<output_name>/<output_name>.apk
      - 若提供 output_dir，再複製一次到 <output_dir>/<output_name>/<output_name>.apk
    """
    if java_library_path is None:
        java_library_path = CONSCRYPT_LIB_DIR

    if source_dir is None:
        source_dir = REPO_ROOT / "App_java" / folder_name
    project_dir = source_dir.resolve()

    output_name_final = output_name or folder_name
    
    # canonical 位置：永遠 out/priv-app
    canonical_dir = PRIV_APP_DIR / output_name_final
    canonical_dir.mkdir(parents=True, exist_ok=True)
    canonical_apk = canonical_dir / f"{output_name_final}.apk"

    print(f"處理資料夾: {project_dir}\n輸出到 {canonical_apk}")

    gradle_cmd = [_resolve_gradle_executable(project_dir, build_executable), build_task]
    if build_args:
        gradle_cmd.extend(build_args)

    print(f"\n{'=' * 80}")
    print(f"開始編譯應用: {folder_name}")
    print(f"{'=' * 80}\n")
    result = _run_gradle(project_dir, gradle_cmd, _prepare_env(env_overrides))
    print(f"\n{'=' * 80}")
    if result.returncode != 0:
        print(f"✗ 編譯失敗 (退出代碼: {result.returncode})")
        print(f"{'=' * 80}")
        raise JavaBuildError(
            task=build_task,
            returncode=result.returncode,
            stdout="",
            stderr="",
        )
    print(f"✓ 編譯成功")
    print(f"{'=' * 80}\n")

    candidate_apk = apk_output or _default_apk_output(project_dir, build_task)

    # 你指定：不要掃描取最新；找不到就直接 fail
    if not candidate_apk.exists():
        raise FileNotFoundError(f"找不到編譯輸出 APK：{candidate_apk}")

    print(f"{'=' * 80}")
    print(f"編譯產物: {candidate_apk.name}")
    print(f"{'=' * 80}\n")

    # 編譯 > 簽名 > 再複製到 canonical
    if sign:
        tmp_signed = canonical_apk.with_suffix(".apk.signed.tmp")
        _sign_apk(
            candidate_apk,
            tmp_signed,
            java_library_path=java_library_path,
        )
        shutil.move(str(tmp_signed), str(canonical_apk))
        print(f"✓ 已簽名 APK (canonical): {canonical_apk}\n")
    else:
        shutil.copy2(candidate_apk, canonical_apk)
        print(f"✓ Java APK 編譯完成（未簽名）: {canonical_apk}\n")

    # output_dir：額外 copy 一份（跟 smali common 行為一致）
    if output_dir:
        copy_dir = Path(output_dir) / output_name_final
        copy_dir.mkdir(parents=True, exist_ok=True)
        copied_apk = copy_dir / f"{output_name_final}.apk"
        shutil.copy2(canonical_apk, copied_apk)
        print(f"✓ 複製 APK 到 {copied_apk}\n")

    print(f"{'=' * 80}")
    print(f"✓ 完成: {folder_name}")
    print(f"{'=' * 80}\n")

    return canonical_apk
