# AGENTS.md

## 📱 專案概述

**SemcCameraUI** 是 LineageOS Sony 設備的相機應用模組化專案，涵蓋：
- **Java 應用層**：相機主程式與功能模組
- **Native SO 模組**：圖像處理、Cacao 服務
- **Smali 反編譯**：現有應用的修改與逆向分析

本專案需要 Java、C/C++（Native）、Smali（字節碼）等多語言協作開發。

---

## 📋 各類型規範索引

不同模組的詳細規範請參考：
- **[Java 專案規範](AGENTS_java.md)** — Web 應用、Gradle 構建、APK 簽名
- **[SO 模組規範](AGENTS_so.md)** — Native 開發、反編譯實作、Ghidra 分析

---

# 1. 語言規則

* 所有回覆、註解與文件使用繁體中文（台灣）

---

# 2. 暫存檔案規範

* 所有暫存檔案與 log 必須放在：`SemcCameraUI/.tmp/`
* 嚴禁使用 `/tmp` 或系統暫存目錄

範例：

```
# 正確
log_path = "SemcCameraUI/.tmp/camera.log"
# 禁止
log_path = "/tmp/camera.log"
```

---

# 3. 專案結構

```
SemcCameraUI/
 ├─ .tmp/                      # 所有 log 與暫存檔
 ├─ tools_Common/
 │  └─ adb.py                  # ADB 封裝
 ├─ test_camera/
 │  └─ test_camera.py          # 測試腳本
 ├─ tools_Libcacao/
 │  ├─ build_push_libcacao.py  # Libcacao編譯腳本 
 │  └─ refs/                   # 原版so         
 ├─ App_java/                  # Java 應用層
 ├─ App_smali/                 # Smali 反編譯應用
 └─ Libcacao/                  # Native SO 模組
```

---

# 4. ADB 工具規範

* 優先使用 `SemcCameraUI/tools_Common/adb.py` 提供的 `Adb` 類別
* 所有指令必須使用 `/mnt/f/Android/platform-tools/adb.exe` 的 adb
* 避免直接用系統其他 adb 或 subprocess 呼叫

---

# 5. 測試與修改流程

1. 程式編譯成功
2. 執行 test_camera.py -c 進行功能測試
3. 若測試通過 → 進入下一步

---

# 6. 反編譯規則

* 必須遵守本文件所有規則
* 不得使用 `/tmp`
* 所有修改，依照原始實作
* 所有邏輯都100%符合原版
* 不得添加原版沒有的函數（空判斷、回退等），除非是相容 Android 14 的措施
* 開發期間可暫時加入註解與 debug log，但最終提交前必須清理；最後保留的 log 只能是原始版本既有的輸出