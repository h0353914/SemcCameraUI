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
import android.view.accessibility.AccessibilityEvent
import android.view.accessibility.AccessibilityNodeInfo
import java.util.concurrent.CountDownLatch
import java.util.concurrent.TimeUnit

class UiAgentAccessibilityService : AccessibilityService() {

    // dispatchGesture callbacks are delivered on the Handler thread you pass in.
    // We use a dedicated HandlerThread so we can safely wait synchronously
    // (e.g. from BroadcastReceiver / binder call paths) without deadlocking
    // the main thread/looper.
    private var gestureThread: HandlerThread? = null
    private var gestureHandler: Handler? = null
    private var mainHandler: Handler? = null

    companion object {
        @Volatile
        var instance: UiAgentAccessibilityService? = null

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
        instance = this

        mainHandler = Handler(Looper.getMainLooper())

        // Start (or restart) the gesture callback thread.
        gestureThread?.quitSafely()
        gestureThread = HandlerThread("uiagent-gesture").apply { start() }
        gestureHandler = Handler(gestureThread!!.looper)
    }

    override fun onDestroy() {
        instance = null

        gestureThread?.quitSafely()
        gestureThread = null
        gestureHandler = null
        mainHandler = null
        super.onDestroy()
    }

    override fun onAccessibilityEvent(event: AccessibilityEvent?) {
        // no-op; operate on-demand via socket commands
    }

    override fun onInterrupt() {
        // no-op
    }

    fun existsByViewId(fullRid: String): Boolean {
        val roots = getWindowRoots()
        return findFirstByViewIdInRoots(roots, fullRid) != null
    }

    fun clickByViewId(fullRid: String): Boolean {
        val roots = getWindowRoots()
        val node = findFirstByViewIdInRoots(roots, fullRid) ?: return false
        return performClickUpTree(node)
    }

    fun existsByDesc(desc: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByContentDesc(r, desc) != null) return true
        }
        return false
    }

    fun clickByDesc(desc: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByContentDesc(r, desc)
            if (node != null) return performClickUpTree(node)
        }
        return false
    }

    fun existsByTextEquals(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByText(r, text, contains = false) != null) return true
        }
        return false
    }

    fun clickByTextEquals(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByText(r, text, contains = false)
            if (node != null) return performClickUpTree(node)
        }
        return false
    }

    fun existsByTextContains(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            if (findFirstByText(r, text, contains = true) != null) return true
        }
        return false
    }

    fun clickByTextContains(text: String): Boolean {
        val roots = getWindowRoots()
        for (r in roots) {
            val node = findFirstByText(r, text, contains = true)
            if (node != null) return performClickUpTree(node)
        }
        return false
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
        // 1) Prefer ACTION_CLICK on a clickable ancestor (including self)
        var n: AccessibilityNodeInfo? = node
        while (n != null) {
            if (n.isClickable) {
                if (n.performAction(AccessibilityNodeInfo.ACTION_CLICK)) {
                    return true
                }
                // Clickable but action failed -> keep walking up, then fallback to gesture.
            }
            n = n.parent
        }

        // 2) Fallback: tap the original node bounds center using dispatchGesture
        val r = Rect()
        node.getBoundsInScreen(r)
        if (r.isEmpty) return false

        val cx = r.centerX().toFloat()
        val cy = r.centerY().toFloat()
        return dispatchTap(cx, cy)
    }

    private fun dispatchTap(x: Float, y: Float): Boolean {
        val path = Path().apply { moveTo(x, y) }
        val stroke = GestureDescription.StrokeDescription(path, 0, 60)
        val gesture = GestureDescription.Builder().addStroke(stroke).build()

        val doneLatch = CountDownLatch(1)
        val acceptLatch = CountDownLatch(1)
        var ok = false
        var accepted = false

        // dispatchGesture is safest when invoked on the main looper.
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
                // Ensure waiters are released even if gesture was rejected immediately.
                doneLatch.countDown()
            }
        }

        // Wait briefly for the dispatchGesture() call to run.
        acceptLatch.await(250, TimeUnit.MILLISECONDS)
        if (!accepted) return false

        // Wait for completion/cancel up to ~900ms.
        doneLatch.await(900, TimeUnit.MILLISECONDS)
        return ok
    }

    private fun findFirstByViewId(root: AccessibilityNodeInfo, fullRid: String): AccessibilityNodeInfo? {
        if (fullRid == root.viewIdResourceName) return root
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            val hit = findFirstByViewId(c, fullRid)
            if (hit != null) return hit
        }
        return null
    }

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

    private fun findFirstByText(
        root: AccessibilityNodeInfo,
        q: String,
        contains: Boolean,
    ): AccessibilityNodeInfo? {
        val qq = q.trim()
        if (qq.isNotEmpty()) {
            // 某些系統 UI（特別是 permission dialog）按鈕文字可能放在
            // contentDescription 或 hintText，因此這裡一起比對。
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

    private fun collectDescs(root: AccessibilityNodeInfo, out: MutableSet<String>) {
        val cd = root.contentDescription?.toString()?.trim()
        if (!cd.isNullOrEmpty()) out.add(cd)
        for (i in 0 until root.childCount) {
            val c = root.getChild(i) ?: continue
            collectDescs(c, out)
        }
    }
}
