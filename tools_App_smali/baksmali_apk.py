#!/usr/bin/env python3
import os
import sys
from pathlib import Path
import subprocess

android_top = Path("/home/h/lineageos")
java_cmd = os.path.join(android_top, "prebuilts/jdk/jdk11/linux-x86/bin/java")

if len(sys.argv) < 2:
    print("用法: python3 baksmali_apk.py <apk_file_path> [output_dir]")
    sys.exit(1)

apk_file = sys.argv[1]

# ===== 新增：可指定輸出資料夾 =====
if len(sys.argv) >= 3:
    folder_path = Path(sys.argv[2])
else:
    folder_path = Path(apk_file).parent / Path(apk_file).stem
# =================================

# 建立資料夾
folder_path.mkdir(parents=True, exist_ok=True)

print(f"輸出資料夾: {folder_path}")
print(f"處理 APK: {apk_file}")

# apktool 路徑
apktool_path = os.path.join(
    os.path.dirname(__file__), "..", "tools_Common", "apktool.jar"
)

# 執行 apktool
apktool_cmd = [
    java_cmd,
    "-jar",
    apktool_path,
    "d",
    apk_file,
    "-o",
    str(folder_path),
    "-f",  # 強制覆蓋輸出資料夾（如果已存在）
]

result = subprocess.run(
    apktool_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
)

if result.returncode == 0:
    print(f"apktool 反編譯完成: {folder_path}")
else:
    print("apktool 反編譯失敗:")
    print(result.stderr)
