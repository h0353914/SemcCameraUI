# Sony Camera Signature Bypass - LSPosed/EdXposed 模組

## 📋 功能說明

此模組用於繞過 Sony 相機 (`com.sonyericsson.android.camera`) 的簽名檢查和運行時權限檢查，讓修改過的 APK 可以正常安裝和運行，並解決 IMAGE_PROCESSOR 權限拒絕問題。

### 核心功能

**簽名檢查繞過：**
- Hook `PackageManagerService.checkSignatures(String, String)`
- Hook `PackageManagerService.checkUidSignatures(int, int)`

**運行時權限檢查繞過：**
- Hook `PackageManagerService.checkUidPermission(String, int)` - 包安裝時的權限授予
- Hook `ActivityManagerService.checkPermission(String, int, int)` - 運行時權限檢查
- Hook `ContextImpl.checkPermission(String, int, int)` - Context 層級權限檢查

**針對權限：**
- `com.sonymobile.permission.IMAGE_PROCESSOR` - BypassCamera 需要的 signature-level 權限

**作用範圍：**
- 只針對 `com.sonyericsson.android.camera` (UID 10067) 繞過檢查
- 不影響其他應用的簽名和權限驗證
- 適用於 Android 9 (API 28) 及更高版本

## 📦 構建

```bash
# 構建 + 安裝
python3 App_xposed/build_xposed_module.py

# 只構建
python3 App_xposed/build_xposed_module.py -b

# 只安裝
python3 App_xposed/build_xposed_module.py -i

# 查日誌
python3 App_xposed/build_xposed_module.py -l

# 指定設備
python3 App_xposed/build_xposed_module.py -d SERIAL
```

## 📲 啟用

1. 安裝 APK 至設備
2. 開啟 **LSPosed Manager** → 啟用模組
3. 勾選作用域: **系統框架 (android)**
4. 重啟設備

## 🐛 調試

```bash
# 查看模組日誌（含 LSPosed 日誌文件）
python3 App_xposed/build_xposed_module.py -l

# 手動查看
adb shell su -c 'cat /data/adb/lspd/log/modules_*.log'
adb logcat | grep SonyCameraBypass
```

### 預期輸出

**安裝時：**
```
SonyCameraBypass: handleLoadPackage  processName=android
SonyCameraBypass: hooked checkSignatures(String, String)
SonyCameraBypass: hooked checkUidSignatures(int, int)
SonyCameraBypass: hooked PMS.checkUidPermission(String, int)
SonyCameraBypass: hooked AMS.checkPermission(String, int, int)
SonyCameraBypass: hooked ContextImpl.checkPermission(String, int, int)
SonyCameraBypass: 所有 Hook 已就位
```

**運行時：**
```
SonyCameraBypass: checkSignatures(com.sonyericsson.android.camera, ...) → MATCH
SonyCameraBypass: checkUidPermission(com.sonymobile.permission.IMAGE_PROCESSOR, uid=10067) → GRANTED
SonyCameraBypass: AMS.checkPermission(com.sonymobile.permission.IMAGE_PROCESSOR, uid=10067) → GRANTED
```

## 📁 結構

```
App_xposed/
├── build_xposed_module.py              # 構建/安裝/日誌腳本
├── build.gradle.kts                    # 項目構建配置
├── settings.gradle.kts
├── gradle.properties
└── app/
    ├── build.gradle.kts                # App 構建配置 + debug 簽名
    └── src/main/
        ├── AndroidManifest.xml         # Xposed 模組聲明
        ├── assets/xposed_init          # Xposed 入口
        ├── java/.../SignatureBypassHook.kt  # Hook 實現
        └── res/values/strings.xml      # scope = android
```
