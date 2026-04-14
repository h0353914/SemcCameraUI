# AGENTS_so.md

Native SO 模組開發規範。適用於 `Libcacao/` 和所有 .so 相關開發。

---

## 返回主文件

參見 [AGENTS.md](AGENTS.md) 查看通用規範。

---

# 1. 專案結構

Native SO 相關主要位於 `Libcacao/` 與 `tools_Libcacao/`：

```
Libcacao/
 ├─ Android.bp
 ├─ libcacao_client/
 │  ├─ Android.bp
 │  ├─ include/
 │  └─ src/
 ├─ libcacao_process_ctrl_gateway/
 ├─ libcacao_service/
 ├─ libimageprocessorjni/
 ├─ prebuilts/
 └─ version_scripts/

tools_Libcacao/
 ├─ build_push_libcacao.py
 └─ refs/
	├─ so_32/
	└─ so_64/
```

---

# 2. .so 編譯 推送 功能測試

### 編譯

```bash
python tools_Libcacao/build_push_libcacao.py -b
```

### 推送

```bash
python tools_Libcacao/build_push_libcacao.py -r
```

### 功能測試

```bash
python test_camera/test_camera.py -c
```
---


# 3. Ghidra MCP 使用規範

專案可透過 Ghidra MCP 對 .so 進行反編譯分析。

### 連線資訊

```
無頭:   http://172.18.48.1:8091  (支援任意 .so)
```

### 載入二進制文件

```bash
curl -X POST -d "file=xxxx.so" http://172.18.48.1:8091/load_program
```

### 運行自動分析

自動識別函數、字符串、資料型別：

```bash
curl -X POST http://172.18.48.1:8091/run_analysis
```

### 檔案存放

- `SemcCameraUI/` 掛載在 `/projects/`
- 相對路徑逐轉為 `/projects/relative/path`
