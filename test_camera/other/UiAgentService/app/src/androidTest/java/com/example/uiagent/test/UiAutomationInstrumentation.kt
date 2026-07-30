package com.example.uiagent.test

import android.app.Instrumentation
import android.app.UiAutomation
import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.test.platform.app.InstrumentationRegistry
import androidx.test.ext.junit.runners.AndroidJUnit4
import org.junit.Test
import org.junit.runner.RunWith

/**
 * Instrumentation 測試類別，透過 UiAutomation API 存取系統權限對話框等受限 UI。
 *
 * 運行方式：
 *   adb shell am instrument -w -e class com.example.uiagent.test.UiAutomationInstrumentation com.example.uiagent.test/androidx.test.runner.AndroidJUnitRunner
 *
 * 或透過 broadcast 觸發特定操作：
 *   adb shell am broadcast -a com.example.uiagent.UIAUTOMATION_CMD --es cmd list_elements
 */
@RunWith(AndroidJUnit4::class)
class UiAutomationInstrumentation {

    companion object {
        private const val TAG = "UiAutomationInstr"

        // 用於從外部觸發 UiAutomation 操作的 broadcast action
        const val ACTION_UIAUTOMATION_CMD = "com.example.uiagent.UIAUTOMATION_CMD"
    }

    private fun getInstrumentation(): Instrumentation {
        return InstrumentationRegistry.getInstrumentation()
    }

    private fun getUiAutomation(): UiAutomation {
        return getInstrumentation().uiAutomation
    }

    @Test
    fun startUiAutomationService() {
        Log.d(TAG, "UiAutomation service started")

        // 建立 UiAutomation 輔助類別實例
        val uiAutomation = getUiAutomation()
        val helper = UiAutomationAccessor(uiAutomation)

        // 啟動監聽器，等待來自 broadcast 的指令
        val receiver = UiAutomationCmdReceiver(helper)
        val context = getInstrumentation().targetContext

        // 註冊 broadcast receiver
        val filter = android.content.IntentFilter(ACTION_UIAUTOMATION_CMD)
        try {
            // Android 12+ 需要指定 flag
            context.registerReceiver(
                receiver, 
                filter, 
                android.content.Context.RECEIVER_EXPORTED
            )
        } catch (e: Exception) {
            // Android 11 及以下版本
            try {
                context.registerReceiver(receiver, filter)
            } catch (e2: Exception) {
                Log.e(TAG, "Failed to register receiver: ${e2.message}")
                throw e2
            }
        }

        Log.d(TAG, "UiAutomation command receiver registered successfully")
        Log.d(TAG, "Ready to accept commands via: adb shell am broadcast -a $ACTION_UIAUTOMATION_CMD --es cmd <command>")

        // 保持執行直到手動停止
        // 透過 synchronized 區塊保持測試執行
        synchronized(this) {
            try {
                // 10 分鐘後自動逾時
                (this as Object).wait(10 * 60 * 1000)
            } catch (e: InterruptedException) {
                Log.d(TAG, "UiAutomation service interrupted")
            }
        }
        
        // 清理
        try {
            context.unregisterReceiver(receiver)
            Log.d(TAG, "Receiver unregistered")
        } catch (e: Exception) {
            Log.e(TAG, "Failed to unregister receiver: ${e.message}")
        }
    }

    @Test
    fun testListAllElements() {
        val uiAutomation = getUiAutomation()
        val helper = UiAutomationAccessor(uiAutomation)

        val elements = helper.listAllElements()
        Log.d(TAG, "Found ${elements.size} elements")

        elements.forEachIndexed { index, element ->
            Log.d(TAG, "[$index] rid=${element["rid"]} text=${element["text"]} desc=${element["desc"]}")
        }
    }

    @Test
    fun testFindPermissionButtons() {
        val uiAutomation = getUiAutomation()
        val helper = UiAutomationAccessor(uiAutomation)

        val buttons = helper.findPermissionDialogButtons()
        Log.d(TAG, "Found ${buttons.size} permission dialog buttons")

        buttons.forEach { (type, info) ->
            Log.d(TAG, "$type: rid=${info["rid"]} text=${info["text"]}")
        }
    }

    @Test
    fun testClickPermissionButton() {
        val uiAutomation = getUiAutomation()
        val helper = UiAutomationAccessor(uiAutomation)

        // 測試點擊「僅允許一次」按鈕
        val clicked = helper.clickByResourceId(
            "com.android.permissioncontroller:id/permission_allow_one_time_button"
        )

        Log.d(TAG, "Click result: $clicked")
    }
}
