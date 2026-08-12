# 編譯專用設定

LineageOS / AOSP 編譯（`m` / `mm` / `mma`）前必須設定的環境變數。適用於 `Libcacao/` 等 Native 編譯（`tools_Libcacao/build_push_libcacao.py`）。

---

## 返回主文件

參見 [AGENTS.md](AGENTS.md) 查看通用規範。

---

# 1. 為什麼需要這份設定

未正確設定以下環境變數時，ccache 不會生效，導致每次編譯都是全量重編，耗時極長。
編譯前務必確認以下變數已套用「正確值」，而非空值或錯誤值。

# 2. 必要環境變數

| 變數名稱 | 錯誤 / 預設值 | 正確值 |
|---|---|---|
| `CCACHE_EXEC` | （空） | `/usr/bin/ccache` |
| `USE_CCACHE` | （空） | `1` |

**務必用 `CCACHE_EXEC`，不要只設 `CC_WRAPPER`。**
原因：`build/soong/ui/build/sandbox_linux.go` 的 ninja nsjail sandbox 只在偵測到
`CCACHE_EXEC` 環境變數時，才會把 ccache 的 `cache_dir`（`~/.cache/ccache`）以
`-B`（read-write）掛進沙箱；只設 `CC_WRAPPER` 的話，`~/.cache/ccache` 在沙箱內仍是
唯讀，編到一半就會出現：

```
ccache: error: failed to create temporary file for ~/.cache/ccache/tmp/xxx: Read-only file system
```

`CC_WRAPPER` 會由 `build/make/core/ccache.mk` 依 `CCACHE_EXEC` 自動推導，不必手動設定。

# 3. 套用方式

在執行 `source build/envsetup.sh && lunch ... && m ...` 之前，先 export：

```bash
export CCACHE_EXEC=/usr/bin/ccache
export USE_CCACHE=1
```

或在呼叫 `tools_Libcacao/build_push_libcacao.py -b` 之前，於 shell 環境中先設定好這兩個變數，確保子行程（`subprocess.run(["bash", "-lc", cmd], ...)`）繼承正確值。

# 3.1 全系統編譯指令（正確版）

`lunch` 的 product 是 `lineage_poplar`，release 是 `bp1a`：

```bash
. build/envsetup.sh
lunch lineage_poplar-bp1a-userdebug
make bacon -j10
```

* 全系統打包（生成 `bacon` OTA/rom 包）必須用 `make bacon`，不是單純的 `m`。
* `-j10` 為既定平行編譯數，不要自行更改。

# 4. 檢查方式

編譯開始後可用以下指令確認 ccache 是否生效（cache hit 應隨編譯次數增加）：

```bash
ccache -s
```
