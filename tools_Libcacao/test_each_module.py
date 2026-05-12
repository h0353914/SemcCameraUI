#!/usr/bin/env python3
"""
逐一測試每個 libcacao 模組的相容性


使用方式：
  python tools_Libcacao/test_each_module.py [-d <serial>]
"""

import argparse
import datetime
import json
import subprocess
import sys
import threading
import time
from pathlib import Path

SEMCCAMERA_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(SEMCCAMERA_ROOT))

from tools_Common.adb import Adb  # noqa: E402

BUILD_PUSH_SCRIPT = SEMCCAMERA_ROOT / "tools_Libcacao" / "build_push_libcacao_9.py"
TEST_CAMERA_SCRIPT = SEMCCAMERA_ROOT / "test_camera" / "test_camera.py"
PYTHON = sys.executable
LOG_DIR = SEMCCAMERA_ROOT / ".tmp"

# ── ADB logcat 全域狀態 ────────────────────────────────────────
_logcat_process: subprocess.Popen | None = None
_logcat_lines: list[str] = []
_logcat_lock = threading.Lock()
_logcat_stop_event = threading.Event()
_logcat_adb_path: str = ""


def _logcat_reader(log_path: Path) -> None:
    """背景執行緒：持續讀取 logcat stdout 並寫入檔案與記憶體緩衝"""
    global _logcat_process, _logcat_lines
    if _logcat_process is None:
        return
    try:
        for raw_line in iter(_logcat_process.stdout.readline, ""):
            if _logcat_stop_event.is_set():
                break
            line = raw_line.rstrip("\n")
            timestamp = datetime.datetime.now().strftime("%H:%M:%S.%f")[:-3]
            stamped = f"{timestamp} {line}"
            with _logcat_lock:
                _logcat_lines.append(stamped)
            with open(log_path, "a", encoding="utf-8") as f:
                f.write(stamped + "\n")
    except Exception:
        pass


def start_logcat(adb: Adb) -> Path:
    """啟動後台 adb logcat（只擷取 libcacao 相關 tag）"""
    global _logcat_process, _logcat_stop_event, _logcat_adb_path
    stop_logcat()

    logcat_path = (
        LOG_DIR / f"logcat_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
    )
    _logcat_stop_event.clear()

    cmd = [adb.adb_path]
    if adb.serial:
        cmd += ["-s", adb.serial]
    cmd += [
        "logcat",
        "-v",
        "threadtime",
    ]

    _logcat_process = subprocess.Popen(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
        text=True,
        bufsize=1,
    )
    _logcat_adb_path = adb.adb_path

    t = threading.Thread(target=_logcat_reader, args=(logcat_path,), daemon=True)
    t.start()
    print(f"[LOG] adb logcat 已開始 → {logcat_path}")
    return logcat_path


def stop_logcat() -> list[str]:
    """停止 logcat 並回傳所有已收集的行"""
    global _logcat_process, _logcat_stop_event
    if _logcat_process is not None:
        _logcat_stop_event.set()
        try:
            _logcat_process.terminate()
            _logcat_process.wait(timeout=5)
        except Exception:
            _logcat_process.kill()
        _logcat_process = None

    with _logcat_lock:
        lines = list(_logcat_lines)
    return lines


def flush_logcat(label: str, serial: str | None = None) -> Path:
    """將目前的 logcat 寫入一個階段檔並回傳其路徑"""
    lines = stop_logcat()
    path = (
        LOG_DIR
        / f"logcat_{label}_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
    )
    with open(path, "w", encoding="utf-8") as f:
        for ln in lines:
            f.write(ln + "\n")
    print(f"[LOG] logcat 已儲存 → {path} ({len(lines)} 行)")
    # 重新啟動 logcat（不清除）
    global _logcat_process, _logcat_stop_event, _logcat_adb_path
    if _logcat_adb_path:
        _logcat_stop_event.clear()
        cmd = [_logcat_adb_path]
        if serial:
            cmd += ["-s", serial]
        cmd += ["logcat", "-v", "threadtime"]
        _logcat_process = subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
            bufsize=1,
        )
        t = threading.Thread(target=_logcat_reader, args=(path,), daemon=True)
        t.start()
    return path


MODULES = [
    ("libcacao_service", ["armeabi-v7a"]),
    ("libimageprocessorjni", ["armeabi-v7a", "arm64-v8a"]),
    ("libcacao_process_ctrl_gateway", ["armeabi-v7a"]),
    ("libcacao_client", ["armeabi-v7a", "arm64-v8a"]),
]

WAIT_AFTER_BOOT_SEC = 10
BOOT_TIMEOUT_SEC = 240


def wait_for_boot(adb: Adb) -> bool:
    """等待裝置 adb 連線並完全開機（sys.boot_completed == 1）"""
    print("[WAIT] 等待裝置 ADB 連線與開機完成...")
    try:
        adb.wait_for_boot(timeout=BOOT_TIMEOUT_SEC, check=True)
        print("[OK] 裝置已開機完成")
    except Exception as exc:
        print(f"[ERR] 等待開機失敗: {exc}")
        return False

    # ── 裝置已連線，立即啟動 logcat ─────────────────────────────
    start_logcat(adb)
    return True


def run_cmd(cmd: list, label: str) -> tuple[bool, str]:
    """執行子命令，回傳 (是否成功, 輸出摘要)"""
    print(f"\n[RUN] {label}")
    print(f"      {' '.join(str(c) for c in cmd)}")
    result = subprocess.run(cmd, text=True, capture_output=True)
    combined = (result.stdout or "") + (result.stderr or "")
    # 印出輸出讓使用者看見
    if result.stdout.strip():
        print(result.stdout.rstrip())
    if result.stderr.strip():
        print(result.stderr.rstrip(), file=sys.stderr)
    success = result.returncode == 0
    print(f"[{'OK' if success else 'FAIL'}] {label} (exit={result.returncode})")
    # 只取最後幾行作為摘要以免 JSON 過大
    summary_lines = combined.strip().splitlines()[-10:]
    return success, "\n".join(summary_lines)


def restore_and_maybe_reboot(adb: Adb, do_reboot: bool, label: str) -> dict:
    """
    還原原版 .so，可選是否重啟。
    回傳 dict：{ "restore_ok", "boot_ok", "output_summary" }
    """
    result_dict: dict = {
        "restore_ok": False,
        "boot_ok": False,
        "output_summary": {},
    }
    cmd = [PYTHON, str(BUILD_PUSH_SCRIPT), "-re"]
    if do_reboot:
        cmd.append("-r")
    if adb.serial:
        cmd += ["-d", adb.serial]
    ok, out = run_cmd(cmd, label)
    result_dict["restore_ok"] = ok
    result_dict["output_summary"]["restore"] = out
    if not ok:
        return result_dict
    if do_reboot:
        if not wait_for_boot(adb):
            return result_dict
        result_dict["boot_ok"] = True
    return result_dict


def main() -> int:
    ap = argparse.ArgumentParser(description="逐一測試 libcacao 各模組相容性")
    ap.add_argument("-d", "--device", type=str, help="指定 ADB 設備序號")
    args = ap.parse_args()

    LOG_DIR.mkdir(parents=True, exist_ok=True)
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    log_file = LOG_DIR / f"test_each_module_{timestamp}.json"

    adb = Adb(serial=args.device)
    results: list[dict] = []

    # ── 前置：還原原版 + 重啟 + 基準測試（只做一次） ────────────────
    print(f"\n{'=' * 60}")
    print("[BASELINE] 還原原版並執行基準測試")
    print(f"{'=' * 60}")

    baseline: dict = {
        "restore_ok": False,
        "boot_ok": False,
        "test_ok": False,
        "output_summary": {},
    }

    br = restore_and_maybe_reboot(adb, True, "[BASELINE] 還原原版並重啟")
    baseline["restore_ok"] = br["restore_ok"]
    baseline["boot_ok"] = br["boot_ok"]
    baseline["output_summary"]["restore"] = br["output_summary"]["restore"]
    if not br["restore_ok"]:
        print("[ERR] 原版還原失敗，中止所有測試")
        _save(log_file, {"baseline": baseline, "modules": []})
        return 1
    if not br["boot_ok"]:
        print("[ERR] 還原後等待開機逾時，中止所有測試")
        _save(log_file, {"baseline": baseline, "modules": []})
        return 1

    print(f"[WAIT] 等待 {WAIT_AFTER_BOOT_SEC} 秒讓相機服務初始化（原版）...")
    time.sleep(WAIT_AFTER_BOOT_SEC)

    test_cmd = [PYTHON, str(TEST_CAMERA_SCRIPT), "-c"]
    if args.device:
        test_cmd += ["-d", args.device]
    ok, out = run_cmd(test_cmd, "[BASELINE] 原版基準測試")
    baseline["test_ok"] = ok
    baseline["output_summary"]["test"] = out
    baseline["logcat_path"] = str(flush_logcat("baseline_test", args.device))
    _save(log_file, {"baseline": baseline, "modules": results})
    if not ok:
        print("[ERR] 原版基準測試失敗，中止所有測試")
        return 1

    print("[OK] 原版基準測試通過，開始逐模組測試")

    for idx, (module_name, abis) in enumerate(MODULES):
        i = idx + 1
        print(f"\n{'=' * 60}")
        print(f"[MODULE {i}/{len(MODULES)}] {module_name}  ({', '.join(abis)})")
        print(f"{'=' * 60}")

        entry: dict = {
            "index": i,
            "module": module_name,
            "abis": abis,
            "restore_ok": False,
            "build_push_ok": False,
            "boot_after_push_ok": False,
            "test_ok": False,
            "error": None,
            "output_summary": {},
        }

        try:
            # ── 步驟 1：還原原版 .so（不重啟） ────────────────────────
            br = restore_and_maybe_reboot(adb, False, f"[{i}] 還原原版（不重啟）")
            entry["restore_ok"] = br["restore_ok"]
            entry["output_summary"]["restore"] = br["output_summary"]["restore"]
            if not br["restore_ok"]:
                entry["error"] = "restore 失敗"
                results.append(entry)
                _save(log_file, results)
                continue

            # ── 步驟 2：編譯 + 複製 + 推送單一模組 + 重啟 ────────────
            push_cmd = [
                PYTHON,
                str(BUILD_PUSH_SCRIPT),
                "-b",
                "-c",
                "-p",
                "-r",
                "-m",
                module_name,
            ]
            if args.device:
                push_cmd += ["-d", args.device]
            ok, out = run_cmd(push_cmd, f"[{i}] 編譯並推送 {module_name} 後重啟")
            entry["build_push_ok"] = ok
            entry["output_summary"]["build_push"] = out
            if not ok:
                entry["error"] = "build/copy/push 失敗"
                results.append(entry)
                _save(log_file, results)
                continue

            # ── 步驟 3：等待裝置重啟完成 ────────────────────────────
            if not wait_for_boot(adb):
                entry["error"] = "推送後等待開機逾時"
                results.append(entry)
                _save(log_file, results)
                continue
            entry["boot_after_push_ok"] = True

            # ── 步驟 4：等待相機服務初始化 ──────────────────────────
            print(f"[WAIT] 等待 {WAIT_AFTER_BOOT_SEC} 秒讓相機服務初始化...")
            time.sleep(WAIT_AFTER_BOOT_SEC)

            # ── 步驟 5：執行相機功能測試 ────────────────────────────
            test_cmd = [PYTHON, str(TEST_CAMERA_SCRIPT), "-c"]
            if args.device:
                test_cmd += ["-d", args.device]
            ok, out = run_cmd(test_cmd, f"[{i}] 相機功能測試")
            entry["test_ok"] = ok
            entry["output_summary"]["test"] = out
            entry["logcat_path"] = str(
                flush_logcat(f"module{i}_{module_name}", args.device)
            )

        except Exception as exc:
            entry["error"] = str(exc)
            print(f"[ERR] 例外: {exc}")

        results.append(entry)
        _save(log_file, {"baseline": baseline, "modules": results})

    # ── 最後：還原原版 + 重啟 + 基準測試 ─────────────────────────────
    print(f"\n{'=' * 60}")
    print("[FINAL] 還原原版 + 重啟 + 基準測試（最後確認）")
    print(f"{'=' * 60}")

    final_baseline: dict = {
        "restore_ok": False,
        "boot_ok": False,
        "test_ok": False,
        "output_summary": {},
    }

    br = restore_and_maybe_reboot(adb, True, "[FINAL] 還原原版並重啟")
    final_baseline["restore_ok"] = br["restore_ok"]
    final_baseline["boot_ok"] = br["boot_ok"]
    final_baseline["output_summary"]["restore"] = br["output_summary"]["restore"]
    if not br["restore_ok"]:
        print("[ERR] 最後還原失敗")
    elif not br["boot_ok"]:
        print("[ERR] 最後還原後等待開機逾時")
    else:
        print(f"[WAIT] 等待 {WAIT_AFTER_BOOT_SEC} 秒讓相機服務初始化（最後）...")
        time.sleep(WAIT_AFTER_BOOT_SEC)
        test_cmd = [PYTHON, str(TEST_CAMERA_SCRIPT), "-c"]
        if args.device:
            test_cmd += ["-d", args.device]
        ok, out = run_cmd(test_cmd, "[FINAL] 最後基準測試")
        final_baseline["test_ok"] = ok
        final_baseline["output_summary"]["test"] = out
        final_baseline["logcat_path"] = str(
            flush_logcat("final_baseline", args.device)
        )

    _save(log_file, {"baseline": baseline, "modules": results, "final_baseline": final_baseline})

    # ── 最終摘要 ──────────────────────────────────────────────────
    print(f"\n{'=' * 60}")
    print("[SUMMARY] 測試結果摘要")
    print(f"{'=' * 60}")
    print(f"  [原版基準] {'✓ 通過' if baseline['test_ok'] else '✗ 失敗'}")
    if final_baseline["test_ok"]:
        print("  [最終還原] ✓ 通過")
    else:
        print(f"  [最終還原] ✗ {'失敗' if not final_baseline['restore_ok'] else '基準測試失敗'}")
    for r in results:
        status = "✓" if r["test_ok"] else "✗"
        err_hint = f"  ← {r['error']}" if r["error"] else ""
        print(f"  [{status}] {r['index']}. {r['module']}{err_hint}")

    all_ok = all(r["test_ok"] for r in results) and final_baseline["test_ok"]

    # ── 停止 logcat ──────────────────────────────────────────────
    final_lines = stop_logcat()
    final_log_path = (
        LOG_DIR
        / f"logcat_final_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
    )
    with open(final_log_path, "w", encoding="utf-8") as f:
        for ln in final_lines:
            f.write(ln + "\n")
    print(f"[LOG] logcat 已停止並儲存 → {final_log_path} ({len(final_lines)} 行)")

    print(f"\n[LOG] 完整結果已儲存至 {log_file}")
    return 0 if all_ok else 1


def _save(path: Path, data: dict | list) -> None:
    """儲存 JSON 結果（中間也會存）"""
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


if __name__ == "__main__":
    raise SystemExit(main())
