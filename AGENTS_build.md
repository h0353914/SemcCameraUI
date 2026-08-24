# 編譯專用設定

LineageOS / AOSP 編譯（`m` / `mm` / `mma`）前必須設定的環境變數。適用於 `camera/cacao/` 等 Native 編譯（`tools_Libcacao/build_push_libcacao.py`）。

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

# 4. 編譯輸出要檢查有沒有出現 `->`：代表指令下錯了

`m` / `mm` 開頭如果印出類似這樣的東西：

```
[100% 1/1] bootstrap blueprint
environment variables changed value:
   CC_WRAPPER ("" -> "/usr/bin/ccache")
   TARGET_RELEASE ("ap4a" -> "bp1a")
   USE_CCACHE ("" -> "1")
```

`"舊值" -> "新值"` 這個箭頭格式，代表 Soong 偵測到跟**上一次呼叫**用的環境變數/`lunch` 設定不一樣（例如 `TARGET_RELEASE` 這次是 `bp1a`、上次卻是 `ap4a`），於是整個 `out/soong` 判定快取失效，觸發全樹重新分析（`soong_build` 會吃到滿記憶體、跑上好幾分鐘，不是單純重編那一兩個模組而已）。

**看到這個輸出就代表這次或上一次的指令下錯了**，通常是：
- `lunch` 打的不是 3.1 節那個 `lineage_poplar-bp1a-userdebug`（release 打成別的，例如 `ap4a`）
- 忘記在 `source build/envsetup.sh && lunch ...` 之前就 export 好 `CCACHE_EXEC=/usr/bin/ccache` 跟 `USE_CCACHE=1`

看到就要停下來，照第 3.1 節的指令重下一次，不要讓它在錯的設定上繼續編下去（編出來的產物設定也會是錯的）。

# 5. 檢查方式

編譯開始後可用以下指令確認 ccache 是否生效（cache hit 應隨編譯次數增加）：

```bash
ccache -s
```
