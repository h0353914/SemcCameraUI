package com.sony.camera.signaturebypass

import android.content.pm.PackageManager
import de.robv.android.xposed.IXposedHookLoadPackage
import de.robv.android.xposed.XC_MethodHook
import de.robv.android.xposed.XposedBridge
import de.robv.android.xposed.XposedHelpers
import de.robv.android.xposed.callbacks.XC_LoadPackage

/**
 * LSPosed/EdXposed Module - Sony Camera 簽名 + 權限檢查繞過
 *
 * Hook PackageManagerService 中所有簽名比對方法，
 * Hook 權限檢查方法來繞過 IMAGE_PROCESSOR 權限限制。
 * 只要涉及 com.sonyericsson.android.camera 就回傳成功。
 */
class SignatureBypassHook : IXposedHookLoadPackage {

    companion object {
        private const val TAG = "GlobalSigBypass"
        private const val PMS = "com.android.server.pm.PackageManagerService"
        private const val AMS = "com.android.server.am.ActivityManagerService"
        private const val CONTEXT_IMPL = "android.app.ContextImpl"
        // TARGET_PERMISSION = "com.sonymobile.permission.IMAGE_PROCESSOR" // 不再限制特定應用
        private const val SIGNATURE_MATCH = 0
        private const val PERMISSION_GRANTED = PackageManager.PERMISSION_GRANTED
    }

    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        if (lpparam.packageName != "android") return

        XposedBridge.log("$TAG: handleLoadPackage  processName=${lpparam.processName}")

        try {
            val pmsClass = XposedHelpers.findClass(PMS, lpparam.classLoader)
            
            // Hook 簽名檢查 - 全域繞過
            XposedHelpers.findAndHookMethod(
                pmsClass,
                "checkSignatures",
                String::class.java,
                String::class.java,
                object : XC_MethodHook() {
                    override fun beforeHookedMethod(param: MethodHookParam) {
                        val pkg1 = param.args[0] as? String
                        val pkg2 = param.args[1] as? String
                        XposedBridge.log("$TAG: checkSignatures($pkg1, $pkg2) → MATCH (global bypass)")
                        param.result = SIGNATURE_MATCH
                    }
                }
            )
            XposedBridge.log("$TAG: hooked checkSignatures(String, String) - GLOBAL")
            
            // Hook 其他檢查方法
            hookCheckUidSignatures(pmsClass)
            hookCheckUidPermission(pmsClass)
            
            // Hook ActivityManagerService 權限檢查
            try {
                val amsClass = XposedHelpers.findClass(AMS, lpparam.classLoader)
                hookAmsCheckPermission(amsClass)
            } catch (e: Throwable) {
                XposedBridge.log("$TAG: AMS hook 跳過（可能不存在）: ${e.message}")
            }
            
            // Hook ContextImpl 權限檢查
            try {
                val contextClass = XposedHelpers.findClass(CONTEXT_IMPL, lpparam.classLoader)
                hookContextCheckPermission(contextClass)
            } catch (e: Throwable) {
                XposedBridge.log("$TAG: ContextImpl hook 跳過（可能不存在）: ${e.message}")
            }
            
        } catch (e: Throwable) {
            XposedBridge.log("$TAG: Hook 初始化失敗: ${e.message}")
        }
    }

    /** Hook checkUidSignatures(int uid1, int uid2) */
    private fun hookCheckUidSignatures(pmsClass: Class<*>) {
        try {
            XposedHelpers.findAndHookMethod(
                pmsClass,
                "checkUidSignatures",
                Int::class.javaPrimitiveType,
                Int::class.javaPrimitiveType,
                object : XC_MethodHook() {
                    override fun beforeHookedMethod(param: MethodHookParam) {
                        val uid1 = param.args[0] as Int
                        val uid2 = param.args[1] as Int
                        XposedBridge.log("$TAG: checkUidSignatures($uid1, $uid2) → MATCH (global bypass)")
                        param.result = SIGNATURE_MATCH
                    }
                }
            )
            XposedBridge.log("$TAG: hooked checkUidSignatures(int, int)")
        } catch (e: Throwable) {
            XposedBridge.log("$TAG: checkUidSignatures hook 不可用（${e.message}）")
        }
    }
    
    /** Hook PackageManagerService.checkUidPermission() - 權限檢查 */
    private fun hookCheckUidPermission(pmsClass: Class<*>) {
        try {
            XposedHelpers.findAndHookMethod(
                pmsClass,
                "checkUidPermission",
                String::class.java,  // permission
                Int::class.javaPrimitiveType,  // uid
                object : XC_MethodHook() {
                    override fun beforeHookedMethod(param: MethodHookParam) {
                        val permission = param.args[0] as? String ?: return
                        val uid = param.args[1] as? Int ?: return
                        // 全域繞過 IMAGE_PROCESSOR 權限檢查
                        XposedBridge.log("$TAG: checkUidPermission($permission, uid=$uid) → GRANTED (global bypass)")
                        param.result = PERMISSION_GRANTED
                    }
                }
            )
            XposedBridge.log("$TAG: hooked PMS.checkUidPermission(String, int)")
        } catch (e: Throwable) {
            XposedBridge.log("$TAG: PMS.checkUidPermission hook 失敗: ${e.message}")
        }
    }
    
    /** Hook ActivityManagerService.checkPermission() - 運行時權限檢查 */
    private fun hookAmsCheckPermission(amsClass: Class<*>) {
        try {
            XposedHelpers.findAndHookMethod(
                amsClass,
                "checkPermission",
                String::class.java,  // permission
                Int::class.javaPrimitiveType,  // pid
                Int::class.javaPrimitiveType,  // uid
                object : XC_MethodHook() {
                    override fun beforeHookedMethod(param: MethodHookParam) {
                        val permission = param.args[0] as? String ?: return
                        val uid = param.args[2] as? Int ?: return
                        XposedBridge.log("$TAG: AMS.checkPermission($permission, uid=$uid) → GRANTED (global bypass)")
                        param.result = PERMISSION_GRANTED
                    }
                }
            )
            XposedBridge.log("$TAG: hooked AMS.checkPermission(String, int, int)")
        } catch (e: Throwable) {
            XposedBridge.log("$TAG: AMS.checkPermission hook 失敗: ${e.message}")
        }
    }
    
    /** Hook ContextImpl.checkPermission() - Context 層級權限檢查 */
    private fun hookContextCheckPermission(contextClass: Class<*>) {
        try {
            XposedHelpers.findAndHookMethod(
                contextClass,
                "checkPermission",
                String::class.java,  // permission
                Int::class.javaPrimitiveType,  // pid
                Int::class.javaPrimitiveType,  // uid
                object : XC_MethodHook() {
                    override fun beforeHookedMethod(param: MethodHookParam) {
                        val permission = param.args[0] as? String ?: return
                        val uid = param.args[2] as? Int ?: return
                        XposedBridge.log("$TAG: ContextImpl.checkPermission($permission, uid=$uid) → GRANTED (global bypass)")
                        param.result = PERMISSION_GRANTED
                    }
                }
            )
            XposedBridge.log("$TAG: hooked ContextImpl.checkPermission(String, int, int)")
        } catch (e: Throwable) {
            XposedBridge.log("$TAG: ContextImpl.checkPermission hook 失敗: ${e.message}")
        }
    }
}

