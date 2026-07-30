package com.example.uiagent

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.util.Log

/**
 * "方案 B"：透過 `adb shell am broadcast` 與 UiAgent 溝通。
 *
 * 目的：避免 WSL/Windows 的 127.0.0.1 / adb forward 造成的 ConnectionRefused。
 *
 * PC 端範例：
 *   # 檢查按鈕是否存在
 *   adb shell am broadcast -a com.example.uiagent.CMD --es cmd exists_rid --es rid com.sonyericsson.android.camera:id/main_button
 *
 *   # 點擊
 *   adb shell am broadcast -a com.example.uiagent.CMD --es cmd click_rid --es rid com.sonyericsson.android.camera:id/main_button
 *
 *   # 等待出現（最多 1200ms）
 *   adb shell am broadcast -a com.example.uiagent.CMD --es cmd wait_exists_rid --es rid com.sonyericsson.android.camera:id/main_button --ei timeout_ms 1200
 *
 *   # 列出目前畫面所有 resource-id（viewIdResourceName）
 *   adb shell am broadcast -a com.example.uiagent.CMD --es cmd list_rids
 *
 * 回傳：透過 Broadcast result-data 回一段 JSON 字串。
 * `am broadcast` 會印出：
 *   data="{...}"
 */
class UiAgentCmdReceiver : BroadcastReceiver() {

    companion object {
        private const val TAG = "UiAgentCmdReceiver"
        const val ACTION_CMD = "com.example.uiagent.CMD"
        // 新版客戶端使用 ACTION_UIAGENT；保留相容性。
        const val ACTION_UIAGENT = "com.example.uiagent.UIAGENT"

        // 需在背景執行緒執行的指令集合（含手勢派發或輪詢等待）。
        private val ASYNC_CMDS = setOf(
            "click_rid", "click_desc", "click_text", "click_text_contains",
            "click_rid_text", "click_rid_content_desc",
            "wait_exists_rid", "wait_exists_rid_content_desc", "wait_exists_rid_text",
            "wait_exists_text",
            "wait_not_exists_rid", "wait_not_exists_rid_content_desc", "wait_not_exists_rid_text",
            "wait_not_exists_text",
            "click_child_under_rid", "swipe"
        )
    }

    override fun onReceive(context: Context, intent: Intent) {
        // Accept both legacy and current action strings.
        val act = intent.action ?: ""
        if (act != ACTION_CMD && act != ACTION_UIAGENT) return

        val cmd = intent.getStringExtra("cmd") ?: ""
        val rid = intent.getStringExtra("rid") ?: ""
        val desc = intent.getStringExtra("desc") ?: ""
        val text = intent.getStringExtra("text") ?: ""
        val pick = intent.getStringExtra("pick") ?: "left"
        val index = intent.getIntExtra("index", 0)
        val timeoutMs = (intent.getIntExtra("timeout_ms", 1200)).coerceIn(50, 10000)
        val x1 = intent.getIntExtra("x1", 0)
        val y1 = intent.getIntExtra("y1", 0)
        val x2 = intent.getIntExtra("x2", 0)
        val y2 = intent.getIntExtra("y2", 0)
        val durationMs = (intent.getIntExtra("duration_ms", 300)).coerceIn(50, 2000).toLong()

        // 某些指令（tap 手勢派發、輪詢等待）不可阻塞主 Looper，
        // 否則手勢回呼會停頓導致逾時，需透過 goAsync() 移到背景執行緒。
        if (cmd in ASYNC_CMDS) {
            val pending = goAsync()
            Thread {
                val t0 = System.nanoTime()
                val resp = runCommand(cmd, rid, desc, text, pick, index, timeoutMs, t0, x1, y1, x2, y2, durationMs)
                pending.resultData = resp
                pending.finish()
            }.start()
            return
        }

        val t0 = System.nanoTime()
        setResultData(runCommand(cmd, rid, desc, text, pick, index, timeoutMs, t0, x1, y1, x2, y2, durationMs))
    }

    private fun runCommand(
        cmd: String,       // 指令名稱（如 "click_rid"、"wait_exists_rid"）
        rid: String,       // viewIdResourceName（完整格式如 "com.pkg:id/name"）
        desc: String,      // contentDescription
        text: String,      // node.text 或 hintText
        pick: String,      // clickClickableChildUnderViewId 的選取策略（"left"|"right"|"index"）
        index: Int,        // pick="index" 時的 0-based 序號
        timeoutMs: Int,    // wait_* 系列指令的輪詢逾時（毫秒）
        t0: Long,          // 用於計算 elapsed_ms 的開始時間戳（nanoTime）
        x1: Int = 0,       // swipe 起點 x
        y1: Int = 0,       // swipe 起點 y
        x2: Int = 0,       // swipe 終點 x
        y2: Int = 0,       // swipe 終點 y
        durationMs: Long = 300, // swipe 持續時間（毫秒）
    ): String {
        val acc = UiAgentAccessibilityService.instance
        if (acc == null) {
            return "{\"ok\":false,\"error\":\"accessibility_not_enabled\"}"
        }

        return try {
            when (cmd) {
                "ping" -> {
                    "{\"ok\":true,\"cmd\":\"ping\",\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_rid" -> {
                    val ex = acc.existsByViewId(rid)
                    "{\"ok\":true,\"cmd\":\"exists_rid\",\"rid\":${jsonQuote(rid)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_rid" -> {
                    val clicked = acc.clickByViewId(rid)
                    "{\"ok\":true,\"cmd\":\"click_rid\",\"rid\":${jsonQuote(rid)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_rid_text" -> {
                    val clicked = acc.clickByViewIdAndText(rid, text)
                    "{\"ok\":true,\"cmd\":\"click_rid_text\",\"rid\":${jsonQuote(rid)},\"text\":${jsonQuote(text)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_rid_text" -> {
                    val ex = acc.existsByViewIdAndText(rid, text)
                    "{\"ok\":true,\"cmd\":\"exists_rid_text\",\"rid\":${jsonQuote(rid)},\"text\":${jsonQuote(text)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_rid_content_desc" -> {
                    val ex = acc.existsByViewIdAndDesc(rid, desc)
                    "{\"ok\":true,\"cmd\":\"exists_rid_content_desc\",\"rid\":${jsonQuote(rid)},\"desc\":${jsonQuote(desc)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_rid_content_desc" -> {
                    val clicked = acc.clickByViewIdAndDesc(rid, desc)
                    "{\"ok\":true,\"cmd\":\"click_rid_content_desc\",\"rid\":${jsonQuote(rid)},\"desc\":${jsonQuote(desc)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_exists_rid_content_desc" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewIdAndDesc(rid, desc)
                    while (!ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewIdAndDesc(rid, desc)
                    }
                    "{\"ok\":true,\"cmd\":\"wait_exists_rid_content_desc\",\"rid\":${jsonQuote(rid)},\"desc\":${jsonQuote(desc)},\"exists\":$ex,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_exists_rid_text" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewIdAndText(rid, text)
                    while (!ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewIdAndText(rid, text)
                    }
                    "{\"ok\":true,\"cmd\":\"wait_exists_rid_text\",\"rid\":${jsonQuote(rid)},\"text\":${jsonQuote(text)},\"exists\":$ex,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_desc" -> {
                    val ex = acc.existsByDesc(desc)
                    "{\"ok\":true,\"cmd\":\"exists_desc\",\"desc\":${jsonQuote(desc)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_desc" -> {
                    val clicked = acc.clickByDesc(desc)
                    "{\"ok\":true,\"cmd\":\"click_desc\",\"desc\":${jsonQuote(desc)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_text" -> {
                    val ex = acc.existsByTextEquals(text)
                    "{\"ok\":true,\"cmd\":\"exists_text\",\"text\":${jsonQuote(text)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_text" -> {
                    val clicked = acc.clickByTextEquals(text)
                    "{\"ok\":true,\"cmd\":\"click_text\",\"text\":${jsonQuote(text)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "exists_text_contains" -> {
                    val ex = acc.existsByTextContains(text)
                    "{\"ok\":true,\"cmd\":\"exists_text_contains\",\"text\":${jsonQuote(text)},\"exists\":$ex,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_text_contains" -> {
                    val clicked = acc.clickByTextContains(text)
                    "{\"ok\":true,\"cmd\":\"click_text_contains\",\"text\":${jsonQuote(text)},\"clicked\":$clicked,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_exists_rid" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewId(rid)
                    while (!ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewId(rid)
                    }
                    "{\"ok\":true,\"cmd\":\"wait_exists_rid\",\"rid\":${jsonQuote(rid)},\"exists\":$ex,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_exists_text" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByTextEquals(text)
                    while (!ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByTextEquals(text)
                    }
                    "{\"ok\":true,\"cmd\":\"wait_exists_text\",\"text\":${jsonQuote(text)},\"exists\":$ex,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_not_exists_rid_content_desc" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewIdAndDesc(rid, desc)
                    while (ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewIdAndDesc(rid, desc)
                    }
                    val notExists = !ex
                    "{\"ok\":true,\"cmd\":\"wait_not_exists_rid_content_desc\",\"rid\":${jsonQuote(rid)},\"desc\":${jsonQuote(desc)},\"not_exists\":$notExists,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_not_exists_rid_text" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewIdAndText(rid, text)
                    while (ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewIdAndText(rid, text)
                    }
                    val notExists = !ex
                    "{\"ok\":true,\"cmd\":\"wait_not_exists_rid_text\",\"rid\":${jsonQuote(rid)},\"text\":${jsonQuote(text)},\"not_exists\":$notExists,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_not_exists_rid" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByViewId(rid)
                    while (ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByViewId(rid)
                    }
                    val notExists = !ex
                    "{\"ok\":true,\"cmd\":\"wait_not_exists_rid\",\"rid\":${jsonQuote(rid)},\"not_exists\":$notExists,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "wait_not_exists_text" -> {
                    val end = System.currentTimeMillis() + timeoutMs
                    var ex = acc.existsByTextEquals(text)
                    while (ex && System.currentTimeMillis() < end) {
                        Thread.sleep(50)
                        ex = acc.existsByTextEquals(text)
                    }
                    val notExists = !ex
                    "{\"ok\":true,\"cmd\":\"wait_not_exists_text\",\"text\":${jsonQuote(text)},\"not_exists\":$notExists,\"timeout_ms\":$timeoutMs,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "click_child_under_rid" -> {
                    val m = acc.clickClickableChildUnderViewId(rid, pick, index)
                    val clicked = (m["clicked"] as? Boolean) ?: false
                    val x = m["x"] as? Int
                    val y = m["y"] as? Int
                    val count = m["count"] as? Int
                    val chosen = m["chosen"] as? Int
                    val err = m["error"] as? String

                    val sb = StringBuilder()
                    sb.append("{\"ok\":true,\"cmd\":\"click_child_under_rid\",\"rid\":")
                    sb.append(jsonQuote(rid))
                    sb.append(",\"pick\":")
                    sb.append(jsonQuote(pick))
                    sb.append(",\"index\":")
                    sb.append(index)
                    sb.append(",\"clicked\":")
                    sb.append(clicked)
                    if (x != null) sb.append(",\"x\":").append(x)
                    if (y != null) sb.append(",\"y\":").append(y)
                    if (count != null) sb.append(",\"count\":").append(count)
                    if (chosen != null) sb.append(",\"chosen\":").append(chosen)
                    if (err != null) sb.append(",\"note\":").append(jsonQuote(err))
                    sb.append(",\"elapsed_ms\":").append(elapsedMs(t0))
                    sb.append('}')
                    sb.toString()
                }
                "list_rids" -> {
                    val rids = acc.listAllViewIds()
                    "{\"ok\":true,\"cmd\":\"list_rids\",\"count\":${rids.size},\"rids\":${jsonArray(rids)},\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "list_windows" -> {
                    val ws = acc.listWindowsBrief()
                    "{\"ok\":true,\"cmd\":\"list_windows\",\"count\":${ws.size},\"windows\":${jsonArray(ws)},\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "list_texts" -> {
                    val ts = acc.listAllTexts()
                    "{\"ok\":true,\"cmd\":\"list_texts\",\"count\":${ts.size},\"texts\":${jsonArray(ts)},\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "list_descs" -> {
                    val ds = acc.listAllDescs()
                    "{\"ok\":true,\"cmd\":\"list_descs\",\"count\":${ds.size},\"descs\":${jsonArray(ds)},\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                "list_all_elements" -> {
                    elementsToJson("list_all_elements", acc.listAllElements(), t0)
                }
                "list_all_elements_with_class" -> {
                    elementsToJson("list_all_elements_with_class", acc.listAllElementsWithClass(), t0)
                }
                "swipe" -> {
                    val swiped = acc.swipe(x1, y1, x2, y2, durationMs)
                    "{\"ok\":true,\"cmd\":\"swipe\",\"x1\":$x1,\"y1\":$y1,\"x2\":$x2,\"y2\":$y2,\"duration_ms\":$durationMs,\"swiped\":$swiped,\"elapsed_ms\":${elapsedMs(t0)}}"
                }
                else -> {
                    "{\"ok\":false,\"error\":\"unknown_cmd\",\"cmd\":${jsonQuote(cmd)}}"
                }
            }
        } catch (t: Throwable) {
            Log.e(TAG, "cmd failed: $cmd", t)
            "{\"ok\":false,\"error\":${jsonQuote(t.toString())}}"
        }
    }

    /** 計算從 [t0]（nanoTime）到現在經過的毫秒數，用於回傳 elapsed_ms。 */
    private fun elapsedMs(t0: Long): Long = (System.nanoTime() - t0) / 1_000_000L

    /** 將字串安全轉義為 JSON 字串字面值（含雙引號），僅處理反斜線與雙引號。 */
    private fun jsonQuote(s: String): String {
        val esc = s.replace("\\", "\\\\").replace("\"", "\\\"")
        return "\"$esc\""
    }

    /** 將字串清單序列化為 JSON 陣列字串（`["a","b",...]`）。 */
    private fun jsonArray(items: List<String>): String {
        val sb = StringBuilder()
        sb.append('[')
        for (i in items.indices) {
            if (i != 0) sb.append(',')
            sb.append(jsonQuote(items[i]))
        }
        sb.append(']')
        return sb.toString()
    }

    /**
     * 將元素清單序列化為 JSON 回應字串（list_all_elements 與 list_all_elements_with_class 共用）。
     */
    private fun elementsToJson(cmd: String, items: List<Map<String, String>>, t0: Long): String {
        val sb = StringBuilder()
        sb.append("{\"ok\":true,\"cmd\":")
        sb.append(jsonQuote(cmd))
        sb.append(",\"count\":${items.size},\"elements\":[")
        for (i in items.indices) {
            if (i != 0) sb.append(',')
            val m = items[i]
            sb.append('{')
            var first = true
            for (key in listOf("rid", "text", "desc", "class", "bounds")) {
                val v = m[key] ?: continue
                if (!first) sb.append(',')
                sb.append(jsonQuote(key)).append(':').append(jsonQuote(v))
                first = false
            }
            val rCur = m["range_cur"]
            if (rCur != null) {
                if (!first) sb.append(',')
                sb.append("\"range_cur\":").append(rCur)
                sb.append(",\"range_min\":").append(m["range_min"])
                sb.append(",\"range_max\":").append(m["range_max"])
                sb.append(",\"range_type\":").append(m["range_type"])
            }
            sb.append('}')
        }
        sb.append("],\"elapsed_ms\":${elapsedMs(t0)}}")
        return sb.toString()
    }
}
