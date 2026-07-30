# UI Agent Service (Android 14 friendly)

最小可用「常駐 UI Agent」：

- Foreground Service 常駐（Android 14 友善）
- AccessibilityService 讀取其他 app 的 UI，並做 exists/click
- PC 端透過 `adb forward` 連到裝置端 Local (abstract) socket

## 使用

1) 安裝後打開 app  
2) 點 **Open Accessibility Settings** → 開啟 UI Agent 的無障礙服務  
3) 點 **Start Agent Service**

## PC 端

```bash
adb forward tcp:27183 localabstract:uiagent27183
```

送一行 JSON（以 \n 結尾），回一行 JSON：

- exists by resource-id
```json
{"cmd":"exists_rid","rid":"com.sonyericsson.android.camera:id/main_button"}
```

- click by resource-id
```json
{"cmd":"click_rid","rid":"com.sonyericsson.android.camera:id/main_button"}
```

- exists by content-desc
```json
{"cmd":"exists_desc","desc":"Photo"}
```

- click by content-desc
```json
{"cmd":"click_desc","desc":"Photo"}
```

- wait for resource-id exists
```json
{"cmd":"wait_exists_rid","rid":"com.sonyericsson.android.camera:id/main_button","timeout_ms":1200}
```

- swipe (從 x1,y1 滑到 x2,y2)
```json
{"cmd":"swipe","x1":500,"y1":1000,"x2":500,"y2":500,"duration_ms":300}
```

## Python 測試

```bash
python3 - <<'PY'
import socket
s=socket.create_connection(("127.0.0.1",27183))
s.sendall(b'{"cmd":"exists_rid","rid":"com.sonyericsson.android.camera:id/main_button"}\n')
print(s.recv(4096).decode())
s.close()
PY
```

## 注意
- 必須手動啟用 Accessibility Service（系統限制）
- `rid` 請用完整格式 `com.pkg:id/name`
