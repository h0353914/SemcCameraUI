# AGENTS_java.md

Java 應用層開發規範。適用於 `App_java/` 和所有 APK 相關開發。

---

## 返回主文件

參見 [AGENTS.md](AGENTS.md) 查看通用規範。

---

# 1. 專案結構

Java 應用層位於 `App_java/` 目錄，相關構建與推送腳本位於 `tools_App/` 目錄。

```
App_java/
 └─ SemcCameraUI-xxhdpi/
     ├─ Android.bp              # Soong 構建文件
     ├─ build.gradle.kts        # Gradle 構建文件
     ├─ gradle.properties       # Gradle 屬性
     ├─ gradlew                 # Gradle 包裝腳本
     ├─ settings.gradle.kts     # Gradle 設定
     ├─ app/                    # 主應用模組
     └─ gradle/                 # Gradle 相關檔案

tools_App/
 ├─ build_java_common.py        # Java 編譯共用流程
 ├─ build_java_push_SemcCameraUI-xxhdpi.py
 └─ ...                         # 其他應用相關腳本
```

構建與推送統一使用 `tools_App/build_java_push_SemcCameraUI-xxhdpi.py`，但使用不同參數。

---

# 2. java 編譯 推送 功能測試

### 編譯

```bash
python tools_App/build_java_push_SemcCameraUI-xxhdpi.py -b
```

### 推送

```bash
python tools_App/build_java_push_SemcCameraUI-xxhdpi.py -p
```

### 功能測試

```bash
python test_camera/test_camera.py -c
```