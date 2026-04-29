import re
import subprocess
import sys
from pathlib import Path


def run_cmd(cmd, cwd, shell=False):
    """執行命令"""
    result = subprocess.run(cmd, cwd=cwd, shell=shell, capture_output=True, text=True)
    return result


def process_apk(apk_path, version, tag):
    """處理單個 APK"""
    base_dir = Path("/home/h/lineageos/device/sony/SemcCameraUI")
    app_smali_dir = base_dir / "App_smali" / "SemcCameraUI-xxhdpi"
    tools_dir = base_dir / "tools_App"

    print(f"\n{'=' * 70}")
    print(f"📦 開始處理: {apk_path.name}")
    print(f"   版本: {version} | TAG: {tag}")
    print(f"{'=' * 70}")

    # 分支名稱
    branch_name = f"ref/smali-{version}-{tag}"

    try:
        # 1. 建立 orphan 分支
        print("\n[1/7] 建立 orphan 分支...")
        result = run_cmd(
            ["git", "checkout", "--orphan", branch_name], cwd=app_smali_dir
        )
        if result.returncode != 0:
            print(f"❌ 失敗: {result.stderr}")
            return False
        print(f"✅ 分支 {branch_name} 已建立")

        # 2. 清空目錄
        print("[2/7] 清空工作目錄...")
        result = run_cmd(["git", "rm", "-rf", "."], cwd=app_smali_dir)
        print("✅ 工作目錄已清空")

        # 3. Cherry-pick 初始提交
        print("[3/7] Cherry-pick 初始提交...")
        result = run_cmd(["git", "cherry-pick", "421e5366c7"], cwd=app_smali_dir)
        if result.returncode == 0:
            print("✅ Cherry-pick 成功")
        else:
            print(f"⚠️  Cherry-pick 狀態: {result.stderr}")

        # 4. Decompile APK
        print("[4/7] Decompile APK (請稍候...)...")
        temp_dir = app_smali_dir / "1111"
        result = run_cmd(
            [
                sys.executable,
                str(tools_dir / "baksmali_apk.py"),
                str(apk_path),
                str(temp_dir),
            ],
            cwd=app_smali_dir,
        )
        if result.returncode != 0:
            print(f"❌ Decompile 失敗: {result.stderr}")
            return False
        print("✅ Decompile 完成")

        # 5. 移動檔案
        print("[5/7] 移動檔案...")
        result = run_cmd("mv 1111/* . && rm -rf 1111", cwd=app_smali_dir, shell=True)
        print("✅ 檔案已移動")

        # 6. Git 提交
        print("[6/7] Git 提交...")
        run_cmd(["git", "add", "."], cwd=app_smali_dir)
        commit_msg = f"import: decompiled SemcCameraUI {version} ({tag})"
        result = run_cmd(["git", "commit", "-m", commit_msg], cwd=app_smali_dir)
        if result.returncode != 0:
            print(f"❌ 提交失敗: {result.stderr}")
            return False
        print(f"✅ 提交: {commit_msg}")

        # 7. 推送到遠端
        print("[7/7] 推送到遠端...")
        result = run_cmd(
            ["git", "push", "-u", "origin", branch_name], cwd=app_smali_dir
        )
        if result.returncode != 0:
            print(f"❌ 推送失敗: {result.stderr}")
            return False
        print(f"✅ 推送成功: origin/{branch_name}")

        return True

    except Exception as e:
        print(f"❌ 異常錯誤: {e}")
        return False


# 主程式
base_dir = Path("/home/h/lineageos/device/sony/SemcCameraUI")
apk_dir = base_dir / ".tmp"

# 掃描 APK 檔案
apk_files = sorted(apk_dir.glob("*.apk"))
configs = []

tag_mapping = {
    28: "a9",
    30: "a11",
    31: "a11",
}

for apk_path in apk_files:
    match = re.search(r"camera_(.+?)-\d+_minAPI(\d+)", apk_path.name)
    if match:
        version = match.group(1)
        api = int(match.group(2))

        tag = tag_mapping.get(api, f"api{api}")
        configs.append((apk_path, version, tag))

# configs.append((apk_dir / "2.4.2.A.0.15.apk", "2.4.2.A.0.15", "a9"))

print(f"🎯 開始處理 {len(configs)} 個 APK...\n")

success_count = 0
for apk_path, version, tag in configs:
    if process_apk(apk_path, version, tag):
        success_count += 1

print(f"\n{'=' * 70}")
print(f"✅ 完成! {success_count}/{len(configs)} 個 APK 成功處理")
print(f"{'=' * 70}")
