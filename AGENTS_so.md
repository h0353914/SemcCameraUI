# AGENTS_so.md

Native SO 模組開發規範。適用於 `camera/cacao/`（`camera` submodule 內）和所有 .so 相關開發。

---

## 返回主文件

參見 [AGENTS.md](AGENTS.md) 查看通用規範。

---

# 1. 專案結構

Native SO 相關主要位於 `camera/cacao/`（`camera` submodule 內）與 `tools_Libcacao/`：

```
camera/cacao/
 ├─ Android.bp
 ├─ libcacao_client/
 │  ├─ Android.bp
 │  ├─ include/
 │  └─ src/
 ├─ libcacao_process_ctrl_gateway/
 │  ├─ Android.bp
 │  ├─ include/
 │  └─ src/
 ├─ libcacao_service/
 .
 .
 .
 ├─ libimageprocessorjni/
 ├─ prebuilts/
 └─ version_scripts/

ghidra/
 └─ ghidra-mcp     

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
無頭1:   http://localhost:8091  (載入原版_32)
無頭2:   http://localhost:8092  (載入原版_64)
無頭1:   http://localhost:8093  (載入編譯_32)
無頭2:   http://localhost:8094  (載入編譯_64)
```

### 載入二進制文件

```bash
curl -X POST -d "file=xxxx.so" http://localhost:809x/load_program
```

無頭 API 工作流程（可直接用版）

1. Load binary

```bash
curl -X POST \
  -H "Authorization: Bearer abc123456" \
  -H "Content-Type: application/json" \
  -d '{
    "file": "/projects/tools_Libcacao/refs/so_32/libimageprocessorjni.so"
  }' \
  http://localhost:8091/load_program
```

2. Run auto-analysis

```bash
curl -X POST \
  -H "Authorization: Bearer abc123456" \
  http://localhost:8091/run_analysis
```

3. List functions

```bash
curl -X GET \
  -H "Authorization: Bearer abc123456" \
  "http://localhost:8091/list_functions?limit=20"
```

4. Decompile function

```bash
curl -X GET \
  -H "Authorization: Bearer abc123456" \
  "http://localhost:8091/decompile_function?address=0x401000"
```

5. Get metadata

```bash
curl -X GET \
  -H "Authorization: Bearer abc123456" \
  http://localhost:8091/get_metadata
```

### 檔案存放

- `SemcCameraUI/` 掛載在 `/projects/`
- 相對路徑逐轉為 `/projects/relative/path`
