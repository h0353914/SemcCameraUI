package com.example.uiagent

import android.accessibilityservice.AccessibilityService
import android.accessibilityservice.GestureDescription
import android.content.Context
import android.graphics.Path
import android.graphics.Rect
import android.os.Handler
import android.os.HandlerThread
import android.os.Looper
import android.provider.Settings
import android.text.TextUtils
import android.util.Log
import android.view.accessibility.AccessibilityEvent
import android.view.accessibility.AccessibilityNodeInfo
import java.util.concurrent.CountDownLatch
import java.util.concurrent.TimeUnit

/**
 * UiAgent 無障礙服務核心 — 提供以 Broadcast 驅動的 UI 自動化能力。
 *
 * 架構概述：
 * - 本服務在系統無障礙框架下執行，持有對 UI 元素樹（AccessibilityNodeInfo）的存取權。
 * - 所有對外操作（存在檢查、點擊、滑動）皆由 [UiAgentCmdReceiver] 轉發過來，
 *   透過靜態 [instance] 欄位取得目前執行的服務實例。
 * - 手勢派發（dispatchGesture）必須在主執行緒排程，但回呼在 [gestureHandler] 執行緒送達，
 *   因此使用 [CountDownLatch] 讓呼叫端同步等待結果，避免阻塞主 Looper。
 *
 * 執行緒模型：
 * - 主執行緒（MainLooper）：排程 dispatchGesture 呼叫。
 * - gestureThread（HandlerThread）：接收 GestureResultCallback 回呼。
 * - BroadcastReceiver/Thread：呼叫本服務的公開方法，透過 CountDownLatch 等待。
 */
class UiAgentAccessibilityService : AccessibilityService() {

    // dispatchGesture 的回呼會在你傳入的 Handler 執行緒上送達。
    // 使用獨立的 HandlerThread，讓 BroadcastReceiver / binder 呼叫路徑
    // 可以安全地同步等待，而不會造成主執行緒 Looper 死鎖。
    private var gestureThread: HandlerThread? = null
    private var gestureHandler: Handler? = null
    private var mainHandler: Handler? = null

    companion object {
        /**
         * 目前正在執行中的服務實例（@Volatile 保證跨執行緒可見性）。
         * 服務連線時設定，服務銷毀時清除。
         * 外部呼叫方（如 [UiAgentCmdReceiver]）透過此欄位存取服務功能。
         */
        @Volatile
        var instance: UiAgentAccessibilityService? = null

        /**
         * 檢查本服務是否已在系統無障礙設定中啟用。
         *
         * 實作說明：先確認全域的 ACCESSIBILITY_ENABLED=1，
         * 再比對 ENABLED_ACCESSIBILITY_SERVICES 清單中是否含有本服務的完整名稱。
         */
        fun isEnabled(ctx: Context): Boolean {
            val enabled = Settings.Secure.getInt(
                ctx.contentResolver,
                Settings.Secure.ACCESSIBILITY_ENABLED,
                0
            ) == 1
            if (!enabled) return false

            val setting = Settings.Secure.getString(
                ctx.contentResolver,
                Settings.Secure.ENABLED_ACCESSIBILITY_SERVICES
            ) ?: return false

            val expected = ctx.packageName + "/" + UiAgentAccessibilityService::class.java.name
            val parts = setting.split(':')
            return parts.any { TextUtils.equals(it, expected) }
        }
    }

    override fun onServiceConnected() {
        // 記錄服務實例，讓外部（CmdReceiver）可直接呼叫本服務的方法
        instance = this

        mainHandler = Handler(Looper.getMainLooper())

        // 啟動（或重啟）手勢回呼執行緒；先安全退出舊的避免洩漏
        gestureThread?.quitSafely()
        gestureThread = HandlerThread("uiagent-gesture").apply { start() }
        gestureHandler = Handler(gestureThread!!.looper)
    }

    override fun onDestroy() {
        // 清除靜態引用並停止手勢執行緒，防止記憶體洩漏
        instance = null

        gestureThread?.quitSafely()
        gestureThread = null
        gestureHandler = null
        mainHandler = null
        super.onDestroy()
    }

    override fun onAccessibilityEvent(event: AccessibilityEvent?) {
        // 不需要監聽事件；所有操作都是由外部 Broadcast 指令驅動（on-demand）
    }

    override fun onInterrupt() {
        // 服務被中斷時不需要額外處理
    }

    /** 判斷指定 viewIdResourceName 的節點是否存在於當前畫面任一視窗。 */
    fun existsByViewId(fullRid: String): Boolean {
        val roots = getWindowRoots()
        return findFirstByViewIdInRoots(roots, fullRid) != null
    }

    /** 對指定 viewIdResourceName 的節點執行點擊；找不到時回傳 false。 */
    fun clickByViewId(fullRid: String): Boolean {
        val roots = getWindowRoots()
        val node = findFirstByViewIdInRoots(roots, fullRid) ?: return false
        return performClickUpTree(node)
    }

    /** 對同時符合 viewId 且 text/hintText 相符的節點執行點擊。 */
    fun clickByViewIdAndText(fullRid: String, text: String): Boolean {
        Log.d("UiAgent", "clickByViewIdAndText: rid=$fullRid, text=$text")
        val roots = getWindowRoots()
        val node = findFirstByViewIdAndTextInRoots(roots, fullRid, text)
        if (node == null) {
            Log.d("UiAgent", "clickByViewIdAndText: node NOT found")
            return false
        }
        Log.d("UiAgent", "clickByViewIdAndText: node found, clicking...")
        return performClickUpTree(node)
    }

    /** 判斷同時符合 viewId 且 text 相符的節點是否存在。 */
    fun existsByViewIdAndText(fullRid: String, text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByViewIdAndText(r, fullRid, text) != null) return true
        }
        return false
    }

    /** 判斷同時符合 viewId 且 contentDescription 相符的節點是否存在。 */
    fun existsByViewIdAndDesc(fullRid: String, desc: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByViewIdAndDesc(r, fullRid, desc) != null) return true
        }
        return false
    }

    /** 對同時符合 viewId 且 contentDescription 相符的節點執行點擊。 */
    fun clickByViewIdAndDesc(fullRid: String, desc: String): Boolean {
        Log.d("UiAgent", "clickByViewIdAndDesc: rid=$fullRid, desc=$desc")
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByViewIdAndDesc(r, fullRid, desc)
            if (node != null) {
                Log.d("UiAgent", "clickByViewIdAndDesc: node found, clicking...")
                return performClickUpTree(node)
            }
        }
        Log.d("UiAgent", "clickByViewIdAndDesc: node NOT found")
        return false
    }

    /** 判斷 contentDescription 完全相符的節點是否存在。 */
    fun existsByDesc(desc: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByContentDesc(r, desc) != null) return true
        }
        return false
    }

    /** 對 contentDescription 完全相符的節點執行點擊。 */
    fun clickByDesc(desc: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByContentDesc(r, desc)
            if (node != null) return performClickUpTree(node)
        }
        return false
    }

    /** 判斷 text/hintText/contentDescription 完全相符的節點是否存在。 */
    fun existsByTextEquals(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByText(r, text, contains = false) != null) return true
        }
        return false
    }

    /** 對 text 完全相符的節點執行點擊。 */
    fun clickByTextEquals(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByText(r, text, contains = false)
            if (node != null) return performClickUpTree(node)
        }
        return false
    }

    /** 判斷 text 包含指定字串（不分大小寫）的節點是否存在。 */
    fun existsByTextContains(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByText(r, text, contains = true) != null) return true
        }
        return false
    }

    /** 對 text 包含指定字串的節點執行點擊。 */
    fun clickByTextContains(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByText(r, text, contains = true)
            if (node != null) return performClickUpTree(node)
        }
        return false
    }

    /**
     * 執行滑動手勢（從 x1,y1 滑到 x2,y2）。
     *
     * @param x1 起點 x 座標
     * @param y1 起點 y 座標
     * @param x2 終點 x 座標
     * @param y2 終點 y 座標
     * @param durationMs 滑動持續時間（毫秒），預設 300ms
     * @return 是否成功執行滑動
     */
    fun swipe(x1: Int, y1: Int, x2: Int, y2: Int, durationMs: Long = 300): Boolean {
        return dispatchSwipe(x1.toFloat(), y1.toFloat(), x2.toFloat(), y2.toFloat(), durationMs)
    }

    /**
     * 列出目前 service 能看到的所有 window（供除錯用）。
     *
     * 內容為「可讀字串」清單，方便用 adb 直接看：
     * - type / layer / active / focused
     * - root.packageName / root.className
     */
    fun listWindowsBrief(): List<String> {
        val out = ArrayList<String>()
        val ws = try {
            windows
        } catch (_: Throwable) {
            null
        }

        if (!ws.isNullOrEmpty()) {
            for (w in ws) {
                val r = w?.root
                val pkg = r?.packageName?.toString() ?: ""
                val cls = r?.className?.toString() ?: ""
                val line = "type=${w.type} layer=${w.layer} active=${w.isActive} focused=${w.isFocused} pkg=$pkg cls=$cls"
                out.add(line)
            }
        }

        val ria = rootInActiveWindow
        if (ria != null) {
            val pkg = ria.packageName?.toString() ?: ""
            val cls = ria.className?.toString() ?: ""
            out.add("rootInActiveWindow pkg=$pkg cls=$cls")
        }

        return out
    }

    /**
     * 列出目前畫面所有 node.text（去重排序，供除錯用）。
     *
     * 注意：很多系統對話框的按鈕可能沒有 viewId，但通常會有 text。
     */
    fun listAllTexts(): List<String> {
        val out = LinkedHashSet<String>()
        for (r in getWindowRoots()) {
            collectTexts(r, out)
        }
        return out.toList().sorted()
    }

    /**
     * 列出目前畫面所有 node.contentDescription（去重排序，供除錯用）。
     */
    fun listAllDescs(): List<String> {
        val out = LinkedHashSet<String>()
        for (r in getWindowRoots()) {
            collectDescs(r, out)
        }
        return out.toList().sorted()
    }

    /**
     * 用「上層 resource-id」去找到其子樹內的 clickable node，並以座標 tap。
     *
     * 典型用途：某些可點按鈕本體沒有 viewIdResourceName（rid），但其上層容器有。
     * 例如 camera 的 mode_icons 底下兩顆模式按鈕。
     *
     * @param parentRid 上層容器的 viewIdResourceName（完整 rid）
     * @param pick 選取策略："left" | "right" | "index"
     * @param index pick="index" 時使用（0-based）
     * @return map: clicked, x, y, count, chosen
     */
    fun clickClickableChildUnderViewId(
        parentRid: String,
        pick: String,
        index: Int,
    ): Map<String, Any> {
        val roots = getWindowRoots()
        val parent = findFirstByViewIdInRoots(roots, parentRid)
            ?: return mapOf("clicked" to false, "error" to "parent_not_found")

        val items = ArrayList<ClickableItem>()
        collectClickableChildren(parent, items)

        if (items.isEmpty()) {
            return mapOf("clicked" to false, "error" to "no_clickable_children", "count" to 0)
        }

        val p = pick.trim().lowercase()
        val chosen: ClickableItem? = when (p) {
            "right" -> items.maxByOrNull { it.cx }
            "index" -> items.getOrNull(index)
            else -> items.minByOrNull { it.cx } // left (default)
        }

        if (chosen == null) {
            return mapOf(
                "clicked" to false,
                "error" to "index_out_of_range",
                "count" to items.size,
            )
        }

        val ok = dispatchTap(chosen.cx.toFloat(), chosen.cy.toFloat())
        return mapOf(
            "clicked" to ok,
            "x" to chosen.cx,
            "y" to chosen.cy,
            "count" to items.size,
            "chosen" to chosen.order,
        )
    }

    /**
     * 取得「目前畫面」中所有非空的 viewIdResourceName。
     *
     * 注意：
     * - 這是 Accessibility Node tree 的掃描結果，不是 uiautomator dump。
     * - 會去重 (Set) 並排序，讓結果穩定可比較。
     * - 系統對話框（例如 PermissionController）常常不在 rootInActiveWindow 的樹上，
     *   所以這裡會優先掃描 service.windows 內每個 window 的 root。
     */
    fun listAllViewIds(): List<String> {
        val out = LinkedHashSet<String>()
        val ws = try {
            windows
        } catch (_: Throwable) {
            null
        }

        if (!ws.isNullOrEmpty()) {
            for (w in ws) {
                val r = w?.root ?: continue
                collectViewIds(r, out)
            }
        }

        // 追加掃 rootInActiveWindow，避免剛切換 app / 彈窗時只看到 SystemUI。
        val root = rootInActiveWindow
        if (root != null) {
            collectViewIds(root, out)
        }
        return out.toList().sorted()
    }

    // ---- helpers (保留「唯一一套」避免 Kotlin overload/conflict) ----

    private data class ClickableItem(
        val cx: Int,
        val cy: Int,
        val order: Int,
    )

    private fun getWindowRoots(): List<AccessibilityNodeInfo> {
        val out = ArrayList<AccessibilityNodeInfo>()
        val ws = try {
            windows
        } catch (_: Throwable) {
            null
        }

        if (!ws.isNullOrEmpty()) {
            for (w in ws) {
                val r = w?.root ?: continue
                out.add(r)
            }
        }

        // 永遠再補 rootInActiveWindow：某些情境 windows 只會回 SystemUI。
        val r = rootInActiveWindow
        if (r != null) out.add(r)

        return out
    }

    private fun findFirstByViewIdInRoots(
        roots: List<AccessibilityNodeInfo>,
        fullRid: String,
    ): AccessibilityNodeInfo? {
        for (r in roots) {
            val hit = findFirstByViewId(r, fullRid)
            if (hit != null) return hit
        }
        return null
    }

    private fun findFirstByViewIdAndTextInRoots(
        roots: List<AccessibilityNodeInfo>,
        fullRid: String,
        text: String,
    ): AccessibilityNodeInfo? {
        for (r in roots) {
            val hit = findFirstByViewIdAndText(r, fullRid, text)
            if (hit != null) return hit
        }
        return null
    }

    private fun collectClickableChildren(parent: AccessibilityNodeInfo, out: MutableList<ClickableItem>) {
        // Walk subtree and collect nodes that are clickable and have non-empty bounds.
        // Keep a stable order (preorder) so pick="index" is deterministic.
        var seq = 0

        fun walk(n: AccessibilityNodeInfo) {
            for (i in 0 until n.childCount) {
                val c = n.getChild(i) ?: continue
                val r = Rect()
                c.getBoundsInScreen(r)
                if (c.isClickable && !r.isEmpty) {
                    out.add(ClickableItem(r.centerX(), r.centerY(), seq))
                    seq += 1
                }
                walk(c)
            }
        }

        walk(parent)
    }

    private fun performClickUpTree(node: AccessibilityNodeInfo): Boolean {
        // 策略 1：從 node 本身向上遍歷，找到第一個可點擊的祖先並執行 ACTION_CLICK
        var n: AccessibilityNodeInfo? = node
        while (n != null) {
            if (n.isClickable) {
                if (n.performAction(AccessibilityNodeInfo.ACTION_CLICK)) {
                    return true
                }
                // 節點可點擊但 ACTION_CLICK 失敗 → 繼續向上，最終再用手勢兜底
            }
            n = n.parent
        }

        // 策略 2：如果所有祖先的 ACTION_CLICK 均失敗，退回以座標 tap 手勢點擊原節點中心
        val r = Rect()
        node.getBoundsInScreen(r)
        if (r.isEmpty) return false

        val cx = r.centerX().toFloat()
        val cy = r.centerY().toFloat()
        return dispatchTap(cx, cy)
    }

    /** 以 60ms 的短暫觸控手勢 tap 指定座標。 */
    private fun dispatchTap(x: Float, y: Float): Boolean {
        val path = Path().apply { moveTo(x, y) }
        val stroke = GestureDescription.StrokeDescription(path, 0, 60)
        val gesture = GestureDescription.Builder().addStroke(stroke).build()
        return dispatchGestureSync(gesture, waitMs = 900)
    }

    /** 以直線路徑執行滑動手勢，持續時間 [durationMs] 毫秒。 */
    private fun dispatchSwipe(x1: Float, y1: Float, x2: Float, y2: Float, durationMs: Long): Boolean {
        val path = Path().apply {
            moveTo(x1, y1)
            lineTo(x2, y2)
        }
        val stroke = GestureDescription.StrokeDescription(path, 0, durationMs)
        val gesture = GestureDescription.Builder().addStroke(stroke).build()
        val waitMs = (durationMs + 500).coerceAtMost(2000)
        return dispatchGestureSync(gesture, waitMs)
    }

    /**
     * 統一的手勢派發實作。
     * dispatchGesture 必須在主執行緒呼叫，此函式負責排程並同步等待結果。
     *
     * @param gesture 要派發的手勢描述
     * @param waitMs  等待完成/取消的最長時間（毫秒）
     */
    private fun dispatchGestureSync(gesture: GestureDescription, waitMs: Long): Boolean {
        val doneLatch = CountDownLatch(1)
        val acceptLatch = CountDownLatch(1)
        var ok = false
        var accepted = false

        val mh = mainHandler ?: return false

        mh.post {
            accepted = dispatchGesture(
                gesture,
                object : AccessibilityService.GestureResultCallback() {
                    override fun onCompleted(gestureDescription: GestureDescription) {
                        ok = true
                        doneLatch.countDown()
                    }

                    override fun onCancelled(gestureDescription: GestureDescription) {
                        ok = false
                        doneLatch.countDown()
                    }
                },
                gestureHandler
            )
            acceptLatch.countDown()
            if (!accepted) {
                // 手勢立即被系統拒絕（例如螢幕已鎖定），確保等待的執行緒能正常解除封鎖
                doneLatch.countDown()
            }
        }

        acceptLatch.await(250, TimeUnit.MILLISECONDS)
        if (!accepted) return false

        doneLatch.await(waitMs, TimeUnit.MILLISECONDS)
        return ok
    }

    // ---- 私有搜尋 helpers（統一一套實作，避免 Kotlin overload 衝突） ----

    /**
     * 以前序深度優先（preorder DFS）在節點樹中尋找第一個 viewIdResourceName 完全相符的節點。
     */
    private fun findFirstByViewId(root: AccessibilityNodeInfo, fullRid: String): AccessibilityNodeInfo? {
        if (fullRid == root.viewIdResourceName) return root
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByViewId(c, fullRid)
            if (hit != null) return hit
        }
        return null
    }

    /** 在節點樹中尋找 contentDescription 完全相符的第一個節點。 */
    private fun findFirstByContentDesc(root: AccessibilityNodeInfo, desc: String): AccessibilityNodeInfo? {
        val cd = root.contentDescription?.toString()
        if (cd == desc) return root
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByContentDesc(c, desc)
            if (hit != null) return hit
        }
        return null
    }

    /**
     * 在節點樹中尋找 viewId 且 text/hintText 均相符的第一個節點。
     * text 比對前會對兩端去除空白（trim）以提高容錯性。
     */
    private fun findFirstByViewIdAndText(
        root: AccessibilityNodeInfo,
        fullRid: String,
        text: String,
    ): AccessibilityNodeInfo? {
        val nodeRid = root.viewIdResourceName
        if (fullRid == nodeRid) {
            val txt = root.text?.toString()?.trim() ?: ""
            val hnt = root.hintText?.toString()?.trim() ?: ""
            val target = text.trim()
            if (txt == target || hnt == target) {
                return root
            }
        }
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByViewIdAndText(c, fullRid, text)
            if (hit != null) return hit
        }
        return null
    }

    /** 在節點樹中尋找 viewId 且 contentDescription 均相符的第一個節點。 */
    private fun findFirstByViewIdAndDesc(
        root: AccessibilityNodeInfo,
        fullRid: String,
        desc: String,
    ): AccessibilityNodeInfo? {
        val nodeRid = root.viewIdResourceName
        if (fullRid == nodeRid) {
            val cd = root.contentDescription?.toString()
            if (cd == desc) {
                return root
            }
        }
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByViewIdAndDesc(c, fullRid, desc)
            if (hit != null) return hit
        }
        return null
    }

    /**
     * 在節點樹中依 text/hintText/contentDescription 尋找節點。
     *
     * @param q       搜尋字串
     * @param contains true = 包含比對（不分大小寫）；false = 精確比對
     *
     * 實作說明：某些系統 UI（特別是 PermissionController 的對話框）按鈕文字
     * 可能放在 contentDescription 或 hintText，因此這裡三個欄位一起比對。
     */
    private fun findFirstByText(
        root: AccessibilityNodeInfo,
        q: String,
        contains: Boolean,
    ): AccessibilityNodeInfo? {
        val qq = q.trim()
        if (qq.isNotEmpty()) {
            val candidates = ArrayList<String>(3)
            val t = root.text?.toString()?.trim()
            if (!t.isNullOrEmpty()) candidates.add(t)
            val cd = root.contentDescription?.toString()?.trim()
            if (!cd.isNullOrEmpty()) candidates.add(cd)
            val ht = root.hintText?.toString()?.trim()
            if (!ht.isNullOrEmpty()) candidates.add(ht)

            for (s in candidates) {
                if (!contains) {
                    if (s == qq) return root
                } else {
                    if (s.contains(qq, ignoreCase = true)) return root
                }
            }
        }

        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByText(c, q, contains)
            if (hit != null) return hit
        }
        return null
    }

    /** 遞迴收集節點樹中所有非空的 viewIdResourceName，寫入 [out] 集合。 */
    private fun collectViewIds(root: AccessibilityNodeInfo, out: MutableSet<String>) {
        val rid = root.viewIdResourceName
        if (!rid.isNullOrEmpty()) {
            out.add(rid)
        }
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            collectViewIds(c, out)
        }
    }

    /** 遞迴收集節點樹中所有非空的 text 與 hintText，寫入 [out] 集合。 */
    private fun collectTexts(root: AccessibilityNodeInfo, out: MutableSet<String>) {
        val t = root.text?.toString()?.trim()
        if (!t.isNullOrEmpty()) out.add(t)
        val ht = root.hintText?.toString()?.trim()
        if (!ht.isNullOrEmpty()) out.add(ht)
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            collectTexts(c, out)
        }
    }

    /** 遞迴收集節點樹中所有非空的 contentDescription，寫入 [out] 集合。 */
    private fun collectDescs(root: AccessibilityNodeInfo, out: MutableSet<String>) {
        val cd = root.contentDescription?.toString()?.trim()
        if (!cd.isNullOrEmpty()) out.add(cd)
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            collectDescs(c, out)
        }
    }

    /**
     * 列出目前畫面所有 [rid, text] 組合清單。
     */
    fun listAllElements(): List<Map<String, String>> = collectElements(includeClass = false)

    /**
     * 列出目前畫面所有 [rid, text, class] 組合清單。
     */
    fun listAllElementsWithClass(): List<Map<String, String>> = collectElements(includeClass = true)

    /**
     * 收集目前所有視窗的 UI 元素清單（含去重）。
     *
     * 每個元素以 Map 呈現，鍵值包含：rid、text、desc、bounds，
     * 以及選填的 class、range_cur/min/max/type（RangeInfo 節點，如 SeekBar）。
     * 以「rid|text|desc|cls|bounds|range」組成唯一鍵，過濾完全重複的節點。
     *
     * @param includeClass 是否在結果中附帶 className 欄位
     */
    private fun collectElements(includeClass: Boolean): List<Map<String, String>> {
        val out = ArrayList<Map<String, String>>()
        val roots = getWindowRoots()
        val seen = HashSet<String>()

        fun walk(n: AccessibilityNodeInfo) {
            val rid = n.viewIdResourceName ?: ""
            val txt = (n.text?.toString()?.trim() ?: "").ifEmpty { n.hintText?.toString()?.trim() ?: "" }
            val desc = n.contentDescription?.toString()?.trim() ?: ""
            val cls = if (includeClass) n.className?.toString()?.trim() ?: "" else ""

            val rect = Rect()
            n.getBoundsInScreen(rect)
            val bounds = "[${rect.left},${rect.top}][${rect.right},${rect.bottom}]"

            val range = n.rangeInfo
            val rangeInfoStr = if (range != null) "${range.current}|${range.min}|${range.max}|${range.type}" else ""

            if (rid.isNotEmpty() || txt.isNotEmpty() || desc.isNotEmpty() || cls.isNotEmpty() || range != null) {
                val key = "$rid|$txt|$desc|$cls|$bounds|$rangeInfoStr"
                if (seen.add(key)) {
                    val map = HashMap<String, String>()
                    if (rid.isNotEmpty()) map["rid"] = rid
                    if (txt.isNotEmpty()) map["text"] = txt
                    if (desc.isNotEmpty()) map["desc"] = desc
                    if (cls.isNotEmpty()) map["class"] = cls
                    map["bounds"] = bounds
                    if (range != null) {
                        map["range_cur"] = range.current.toString()
                        map["range_min"] = range.min.toString()
                        map["range_max"] = range.max.toString()
                        map["range_type"] = range.type.toString()
                    }
                    out.add(map)
                }
            }

            for (i in 0 until n.childCount) {
                val c = n.getChild(i) ?: continue
                walk(c)
            }
        }

        for (r in roots) walk(r)
        return out
    }
}
