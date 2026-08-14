# AGENTS_java.md

Java 應用層開發規範。適用於 `camera/apps/`（`camera` submodule 內）和所有 APK 相關開發。

---

## 返回主文件

參見 [AGENTS.md](AGENTS.md) 查看通用規範。

---

# 1. 專案結構

Java 應用層位於 `camera/apps/`（`camera` 這個 submodule 內），相關構建與推送腳本位於 `tools_App_java/` 目錄。

```
camera/apps/
 ├─ SemcCameraUI/
 │   ├─ Android.bp              # Soong 構建文件
 │   ├─ build.gradle.kts        # Gradle 構建文件
 │   ├─ gradle.properties       # Gradle 屬性
 │   ├─ gradlew                 # Gradle 包裝腳本
 │   ├─ settings.gradle.kts     # Gradle 設定
 │   ├─ app/                    # 主應用模組
 │   └─ gradle/                 # Gradle 相關檔案
 └─ CameraPanorama/              # 同上結構

tools_App_java/
 ├─ build_push_SemcCameraUI-xxhdpi.py
 ├─ build_push_CameraPanorama.py
 └─ ...                         # 其他應用相關腳本
```

構建與推送統一使用 `tools_App_java/build_push_<app>.py`，但使用不同參數（`-b` 編譯、`-p` 推送、`-s` 簽名、`-r` 重啟）。

---

# 2. Git 分支說明

`camera/apps/SemcCameraUI` 中的主要分支：

| 分支名 | 說明 |
|-------------------------------------------|-------------------------- |
| `2.2.2.A.0.15_smali_a9`                   | 重新打包版                 |
| `2.2.2.A.0.15_smali_a14`                  | 重新打包版，相容 Android 14 |
| `2.2.2.A.0.15_java_a14`                   | 反編譯版，相容 Android 14   |
| `2.2.2.A.0.15_java_a9`                    | 反編譯版，基礎版本          |
| `2.9.2.A.0.10_smali_sdk34_reference-only` | 參考用最新版               |

---

# 3. java 編譯 推送 功能測試

### 編譯

```bash
python tools_App_java/build_push_SemcCameraUI-xxhdpi.py -b
```

### 推送

```bash
python tools_App_java/build_push_SemcCameraUI-xxhdpi.py -p
```

### 功能測試

```bash
python test_camera/test_camera.py -c
```