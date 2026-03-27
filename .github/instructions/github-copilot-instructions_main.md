# SemcCameraUI - GitHub Copilot 自訂指示

**回覆語言**: 繁體中文（台灣）

## 檔案系統規範

### 暫存資料夾規則

**指定暫存位置**: `SemcCameraUI/.tmp`

**強制要求**:
- ✓ 所有新腳本的 log 檔案都放置於此
- ✓ 所有暫存檔案都放置於此
- ✗ **嚴格禁止**將任何檔案放到 `/tmp` 目錄
- ✗ **嚴格禁止**使用系統臨時目錄

**違規範例** (禁止):
```python
# ❌ 禁止
log_path = "/tmp/camera.log"
temp_file = "/tmp/test.txt"
```

**正確範例**:
```python
# ✓ 正確
log_path = "SemcCameraUI/.tmp/camera.log"
temp_file = "SemcCameraUI/.tmp/test.txt"
```

## 專案結構

### 源代碼位置

- **Java 版本**: `SemcCameraUI/App_java/SemcCameraUI-xxhdpi`
- **Smali 版本**: `SemcCameraUI/App_smali/SemcCameraUI-xxhdpi`
- **原生代碼**: `SemcCameraUI/Libcacao/` (C/C++ 代碼和 JNI 綁定)

### 工具和腳本

**反編譯和編譯工具**:
- ApkTool/Baksmali: `SemcCameraUI/tools_Common/apktool.jar`

**編譯腳本**:
- Java 版編譯推送: `SemcCameraUI/tools_App/build_java_push_SemcCameraUI-xxhdpi.py`
- Smali 版編譯推送: `SemcCameraUI/tools_App/build_push_SemcCameraUI-xxhdpi.py`

**測試和調試工具**:
- 畫面點擊查看庫: `SemcCameraUI/tools_Common/test_camera/uiagent_client.py`
- 相機拍照測試腳本: `SemcCameraUI/tools_Common/test_camera/test_camera.py` (基本測試使用)

**ADB 工具**:
- ADB 封裝庫: `SemcCameraUI/tools_Common/adb.py`
  - 提供 `Adb` 類別：自動帶上 adb 路徑 + 可選的 `-s serial`
  - 提供 `resolve_adb_path()` 函式：智能挑選可用的 adb 實作

### ADB 路徑

**WSL Windows ADB**：`/mnt/f/Android/platform-tools/adb.exe`

### 測試和調試流程

**測試腳本建立**:
- 建立測試腳本時參考 `test_camera.py`
- 基本測試可使用拍照測試腳本

**修改後檢查清單**:
1. ✓ 能編譯成功
2. ✓ 應用不閃退
3. ✓ 開啟不卡頓

**重要提醒**:
- Java 版換 Smali 版後**必須重啟手機**
- 可以加入暫時 log 協助偵錯
- 測試完成後**必須移除所有 log**
- 所有 log 檔案必須放在 `SemcCameraUI/.tmp/`