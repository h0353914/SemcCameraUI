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

**ADB 工具**:
- ADB 封裝庫: `SemcCameraUI/tools_Common/adb.py`
  - 提供 `Adb` 類別：自動帶上 adb 路徑 + 可選的 `-s serial`
  - 提供 `resolve_adb_path()` 函式：智能挑選可用的 adb 實作

### ADB 路徑

**WSL Windows ADB**：`/mnt/f/Android/platform-tools/adb.exe`

**重要提醒**:
- 所有 log 檔案必須放在 `SemcCameraUI/.tmp/`