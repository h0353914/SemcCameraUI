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
## 反編譯參考規範

**重要限制**:
- 所有最終實作必須 100% 參照 原版so 邏輯

## 專案結構

**ADB 工具**:
- ADB 封裝庫: `SemcCameraUI/tools_Common/adb.py`
  - 提供 `Adb` 類別：自動帶上 adb 路徑 + 可選的 `-s serial`
  - 提供 `resolve_adb_path()` 函式：智能挑選可用的 adb 實作

### ADB 路徑

**WSL Windows ADB**：`/mnt/f/Android/platform-tools/adb.exe`

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
- 所有 log 檔案必須放在 `SemcCameraUI/.tmp/`