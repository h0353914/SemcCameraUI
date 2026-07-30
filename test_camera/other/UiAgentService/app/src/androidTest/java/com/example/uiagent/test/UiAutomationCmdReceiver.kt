package com.example.uiagent.test

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.util.Log
import org.json.JSONArray
import org.json.JSONObject

/**
 * UiAutomation 指令接收器 — 透過 Broadcast 接收指令並執行。
 *
 * 運行方式：
 *   1. 先啟動 Instrumentation 測試保持執行
 *   2. 發送 broadcast 指令：
 *      adb shell am broadcast -a com.example.uiagent.UIAUTOMATION_CMD --es cmd list_elements
 *      adb shell am broadcast -a com.example.uiagent.UIAUTOMATION_CMD --es cmd click_rid --es rid <resource-id>
 */
class UiAutomationCmdReceiver(
    private val accessor: UiAutomationAccessor
) : BroadcastReceiver() {

    companion object {
        private const val TAG = "UiAutomationCmdRcv"
    }

    override fun onReceive(context: Context, intent: Intent) {
        val cmd = intent.getStringExtra("cmd") ?: return
        val rid = intent.getStringExtra("rid") ?: ""
        val text = intent.getStringExtra("text") ?: ""
        val exact = intent.getBooleanExtra("exact", true)

        Log.d(TAG, "Received command: $cmd")

        val t0 = System.nanoTime()
        val response = when (cmd) {
            "ping" -> {
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "ping")
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "list_elements" -> {
                val elements = accessor.listAllElements()
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "list_elements")
                    put("count", elements.size)
                    put("elements", JSONArray(elements.map { JSONObject(it) }))
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "find_permission_buttons" -> {
                val buttons = accessor.findPermissionDialogButtons()
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "find_permission_buttons")
                    put("count", buttons.size)
                    put("buttons", JSONObject(buttons.mapValues { JSONObject(it.value) }))
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "exists_rid" -> {
                val exists = accessor.existsByResourceId(rid)
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "exists_rid")
                    put("rid", rid)
                    put("exists", exists)
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "exists_text" -> {
                val exists = accessor.existsByText(text, exact)
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "exists_text")
                    put("text", text)
                    put("exact", exact)
                    put("exists", exists)
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "click_rid" -> {
                val clicked = accessor.clickByResourceId(rid)
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "click_rid")
                    put("rid", rid)
                    put("clicked", clicked)
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            "click_text" -> {
                val clicked = accessor.clickByText(text, exact)
                JSONObject().apply {
                    put("ok", true)
                    put("cmd", "click_text")
                    put("text", text)
                    put("exact", exact)
                    put("clicked", clicked)
                    put("elapsed_ms", elapsedMs(t0))
                }
            }

            else -> {
                JSONObject().apply {
                    put("ok", false)
                    put("error", "unknown_cmd")
                    put("cmd", cmd)
                }
            }
        }

        // 將結果寫入 resultData
        resultData = response.toString()
        Log.d(TAG, "Response: $response")
    }

    private fun elapsedMs(t0: Long): Long = (System.nanoTime() - t0) / 1_000_000L
}
