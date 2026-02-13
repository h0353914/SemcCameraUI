# SemcCameraUI - GitHub Copilot 自訂指示

## 專案概述

**專案類型**: Android 相機應用程式（混合 Java、Kotlin、Smali 和 JNI）

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

## 反編譯參考規範

**參考 Commit**: `65d95135e34d64399cd4afdb436df657a7dcc037`

**重要限制**:
- 此 commit 中的反編譯 Java 原始檔案**僅供參考**
- 直接使用這些檔案**無法編譯**
- 所有最終實作必須 100% 參照 Smali 版本邏輯

## Java 版本修改規範

### 邏輯一致性要求（關鍵）

修改 Java 代碼時必須遵循以下原則:

1. **100% 符合 Smali 版邏輯**
   - 所有實作細節必須與 Smali 版本完全一致
   - 方法調用順序必須相同
   - 邏輯流程必須一致

2. **參考資料使用方式**
   - 參考 commit `65d95135e34d64399cd4afdb436df657a7dcc037` 理解結構
   - 不可直接使用反編譯的 Java 檔案
   - 使用 Smali 版本進行比較驗證

3. **問題處理原則**
   - 如果發現 Smali 版邏輯有問題,仍需 100% 符合 Smali 版
   - 往上修正,不要給出「改用 Smali 版」的結論

### 測試和調試流程

**測試腳本建立**:
- 建立測試腳本時參考 `test_camera.py`
- 基本測試使用拍照測試腳本

**修改後檢查清單**:
1. ✓ 能編譯成功
2. ✓ 應用不閃退
3. ✓ 開啟不卡頓
4. ✓ 在以上基礎上才開始功能測試

**重要提醒**:
- Java 版換 Smali 版後**必須重啟手機**
- 可以加入暫時 log 協助偵錯
- 測試完成後**必須移除所有 log**
- 所有 log 檔案必須放在 `SemcCameraUI/.tmp/`

## 代碼風格指南

### Java/Kotlin 代碼

- 遵循 Smali 可能的原始風格
- 從 Smali 反推 Java 時保持代碼可讀性
- 邏輯必須完全一致

### Gradle 配置

- 使用 Kotlin DSL (`build.gradle.kts`) 進行新配置
- 在 `dependencies` 區塊中明確指定依賴版本
- 遵循語意版本控制 (Semantic Versioning)

### Smali 代碼

- 保持原始反編譯結構的完整性
- 註解修改的部分以供追蹤
- 遵循 Dalvik 字節碼規範

## 提交和文檔規範

- 使用清晰、簡潔的代碼註解
- 說明 Smali 對應關係和邏輯轉換
- 註明為何採用特定實作方式

## 性能要求

- 優化性能和記憶體使用
- 確保 Java 版本與 Smali 版本功能完全等價