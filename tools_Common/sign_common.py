from __future__ import annotations

import os
import shutil
import subprocess
import tempfile
from pathlib import Path
from typing import Optional

ANDROID_TOP = Path("/home/h/lineageos")
REPO_DIR = Path(__file__).resolve().parent
DEFAULT_JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")


def _abs_from_tool(path_fragment: str) -> Path:
    base = REPO_DIR
    candidate = Path(path_fragment)
    if not candidate.is_absolute():
        candidate = base / path_fragment
    return Path(os.path.normpath(str(candidate)))


def _resolve_java_executable(custom_path: Optional[str]) -> str:
    candidate = custom_path or DEFAULT_JAVA_CMD
    resolved = Path(candidate)
    if candidate and resolved.exists():
        return str(resolved)
    system_java = shutil.which("java")
    return system_java or "java"


def _find_signing_resources() -> tuple[Path, Path, Path, Optional[Path]]:
    signapk_jar = _abs_from_tool("/home/h/lineageos/out/host/linux-x86/framework/signapk.jar")
    if not signapk_jar.exists():
        raise FileNotFoundError(f"signapk.jar not found: {signapk_jar}")

    pub_key = _abs_from_tool("/home/h/lineageos/build/target/product/security/platform.x509.pem")
    priv_key = _abs_from_tool("/home/h/lineageos/build/target/product/security/platform.pk8")
    if not pub_key.exists() or not priv_key.exists():
        raise FileNotFoundError(
            f"Platform keys not found. Expected:\n  {pub_key}\n  {priv_key}"
        )

    conscrypt_so = _abs_from_tool("/home/h/lineageos/out/host/linux-x86/lib64/libconscrypt_openjdk_jni.so")
    if not conscrypt_so.exists():
        conscrypt_so = _abs_from_tool("/home/h/lineageos/prebuilts/sdk/tools/linux/lib64/libconscrypt_openjdk_jni.so")
        if not conscrypt_so.exists():
            conscrypt_so = None

    return signapk_jar, pub_key, priv_key, conscrypt_so


def _prepare_conscrypt_dir(conscrypt_so: Optional[Path]) -> Path:
    conscrypt_dir = Path(tempfile.mkdtemp(prefix="conscrypt_lib_"))
    if conscrypt_so:
        for lib_name in (
            "libconscrypt_openjdk_jni-linux-x86_64.so",
            "libconscrypt_openjdk_jni.so",
        ):
            os.symlink(conscrypt_so, conscrypt_dir / lib_name)
    return conscrypt_dir


def sign_apk(
    *,
    apk_in: Optional[str] = None,
    apk_out: Optional[str] = None,
    alignment: int = 4,
    java_executable: Optional[str] = None,
) -> str:
    fallback_apk = _abs_from_tool("../apk_out/SemcCameraUI-xxhdpi-release.apk")
    target_apk = Path(apk_in or fallback_apk).resolve()
    if not target_apk.is_file():
        raise FileNotFoundError(f"Input APK not found: {target_apk}")

    resolved_java = _resolve_java_executable(java_executable)
    signapk_jar, pub_key, priv_key, conscrypt_so = _find_signing_resources()
    tmp_out = Path(apk_out).resolve() if apk_out else target_apk.with_suffix(target_apk.suffix + ".signed.tmp")

    conscrypt_dir = _prepare_conscrypt_dir(conscrypt_so)
    try:
        cmd = [
            resolved_java,
            f"-Djava.library.path={conscrypt_dir}",
            "-jar",
            str(signapk_jar),
            "-a",
            str(alignment),
            str(pub_key),
            str(priv_key),
            str(target_apk),
            str(tmp_out),
        ]

        print("Executing:")
        print(" ".join(cmd))
        result = subprocess.run(cmd, text=True, capture_output=True)
        if result.stdout:
            print(result.stdout.rstrip())
        if result.stderr:
            print(result.stderr.rstrip())
        if result.returncode != 0:
            raise subprocess.CalledProcessError(result.returncode, cmd)

    finally:
        shutil.rmtree(conscrypt_dir)

    final_apk = Path(apk_out).resolve() if apk_out else target_apk
    if apk_out:
        print(f"Signed APK: {final_apk}")
        return str(final_apk)

    shutil.move(str(tmp_out), str(target_apk))
    print(f"Signed APK (in-place): {final_apk}")
    return str(final_apk)


def sign_and_report_apk(apk_path: Path, java_executable: Optional[str] = None) -> Path:
    signed_apk = Path(sign_apk(apk_in=str(apk_path), java_executable=java_executable))
    print(f"簽署完成: {signed_apk}")
    return signed_apk
