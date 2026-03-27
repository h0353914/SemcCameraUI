# AGENTS.md

SemcCameraUI 專案 AI 開發規則與工作流程。所有 AI coding assistant 在產生程式碼時必須遵守。

---

# 1. 語言規則

* 所有回覆、註解與文件使用繁體中文（台灣）

---

# 2. 暫存檔案規範

* 所有暫存檔案與 log 必須放在：`SemcCameraUI/.tmp/`
* 嚴禁使用 `/tmp` 或系統暫存目錄

範例：

```python
# 正確
log_path = "SemcCameraUI/.tmp/camera.log"
# 禁止
log_path = "/tmp/camera.log"
```

---

# 3. 反編譯實作規範

* 所有實作必須 100% 參照原始 .so 邏輯
* 不可自行改變行為或簡化邏輯
* 可增加註解與暫時 debug log，但最終提交前必須清理，僅保留原始 .so 本身的 log

---

# 4. 專案結構

```
SemcCameraUI/
 ├─ .tmp/                 # 所有 log 與暫存檔
 ├─ tools_Common/
 │   └─ adb.py            # ADB 封裝
 ├─ test_camera.py        # 基礎測試腳本
```

---

# 5. ADB 工具規範

* 優先使用 `SemcCameraUI/tools_Common/adb.py` 提供的 `Adb` 類別
* 所有指令必須使用 `/mnt/f/Android/platform-tools/adb.exe` 的 adb
* 避免直接用系統其他 adb 或 subprocess 呼叫

---

# 6. Ghidra MCP 使用規範

專案可透過 Ghidra MCP 對 .so 進行反編譯分析。

用法參考 ghidra/ghidra-mcp/docs

呼叫 MCP：

curl http://172.18.48.1:xxxx/check_connection 有用就能用

32bit:http://172.18.48.1:8089    libimageprocessorjni.so
64bit:http://172.18.48.1:8090    libimageprocessorjni.so
無頭: http://172.18.48.1:8091

只有"無頭"可以載入任意so 
SemcCameraUI/ 掛載在 /projects/
Load a binary
curl -X POST -d "file=xxxx.so" http://172.18.48.1:8091/load_program
Run auto-analysis (identifies functions, strings, data types)
curl -X POST http://172.18.48.1:8091/run_analysis

---

# 7. 測試與修改流程

1. 程式可以編譯成功
2. 應用程式不閃退
3. 相機開啟不卡頓
4. 在以上條件成立後才進行功能測試
5. test_camera.py 全部測試都要通過

---

# 8. AI 生成程式碼規則

* 必須遵守本文件所有規則
* 不得使用 `/tmp`
* 不得改變原始 .so 行為
* 若無法確定，保持與原始實作一致

---

# 9. 遵守優先順序

1. 原始 .so 行為
2. AGENTS.md
3. 專案既有程式碼
4. 新生成程式碼

# 10. 修改方法
1.檢查目前變更是否與原版一致
2.修復到 test_camera.py -d QV70A5XA11  -c 能通過

QV700WMR11 編譯機
QV70A5XA11 參考機 
多使用 Ghidra MCP