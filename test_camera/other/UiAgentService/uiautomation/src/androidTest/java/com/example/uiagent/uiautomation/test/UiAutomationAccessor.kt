package com.example.uiagent.uiautomation.test

import android.app.UiAutomation
import android.util.Log
import android.view.accessibility.AccessibilityNodeInfo

/**
 * UiAutomation 存取器 — 獨立於 AccessibilityService 的 UI 自動化模組。
 *
 * 本類別專門透過 Instrumentation/UiAutomation API 存取系統層級 UI，
 * 包含 AccessibilityService 無法存取的權限對話框等元素。
 *
 * 重要：請勿在 AccessibilityService 的 Context 中使用本類別！
 */
class UiAutomationAccessor(private val uiAutomation: UiAutomation) {

    companion object {
        private const val TAG = "UiAutomationAccessor"
    }

    /**
     * 取得目前活動視窗的根節點。
     */
    fun getRootInActiveWindow(): AccessibilityNodeInfo? {
        return try {
            uiAutomation.rootInActiveWindow
        } catch (e: Exception) {
            Log.e(TAG, "Failed to get root node", e)
            null
        }
    }

    /**
     * 遞迴尋找指定 resource-id 的節點。
     */
    fun findNodeByResourceId(resourceId: String): AccessibilityNodeInfo? {
        // 方法 1：在活動視窗中尋找
        val root = getRootInActiveWindow()
        if (root != null) {
            val result = findNodeByResourceIdRecursive(root, resourceId)
            if (result != null) return result
            root.recycle()
        }

        // 方法 2：在所有視窗中尋找
        try {
            for (window in uiAutomation.windows) {
                val windowRoot = window.root ?: continue
                val result = findNodeByResourceIdRecursive(windowRoot, resourceId)
                if (result != null) {
                    windowRoot.recycle()
                    return result
                }
                windowRoot.recycle()
            }
        } catch (e: Exception) {
            Log.w(TAG, "Failed to search all windows: ${e.message}")
        }

        return null
    }

    private fun findNodeByResourceIdRecursive(
        node: AccessibilityNodeInfo,
        resourceId: String
    ): AccessibilityNodeInfo? {
        try {
            if (node.viewIdResourceName == resourceId) {
                return node
            }

            for (i in 0 until node.childCount) {
                val child = node.getChild(i) ?: continue
                val result = findNodeByResourceIdRecursive(child, resourceId)
                if (result != null) return result
                child.recycle()
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error in findNodeByResourceIdRecursive", e)
        }

        return null
    }

    /**
     * 尋找包含指定文字的節點。
     */
    fun findNodeByText(text: String, exact: Boolean = true): AccessibilityNodeInfo? {
        // 方法 1：在活動視窗中尋找
        val root = getRootInActiveWindow()
        if (root != null) {
            val result = findNodeByTextRecursive(root, text, exact)
            if (result != null) return result
            root.recycle()
        }

        // 方法 2：在所有視窗中尋找
        try {
            for (window in uiAutomation.windows) {
                val windowRoot = window.root ?: continue
                val result = findNodeByTextRecursive(windowRoot, text, exact)
                if (result != null) {
                    windowRoot.recycle()
                    return result
                }
                windowRoot.recycle()
            }
        } catch (e: Exception) {
            Log.w(TAG, "Failed to search all windows: ${e.message}")
        }

        return null
    }

    private fun findNodeByTextRecursive(
        node: AccessibilityNodeInfo,
        text: String,
        exact: Boolean
    ): AccessibilityNodeInfo? {
        try {
            val nodeText = node.text?.toString() ?: ""
            val match = if (exact) {
                nodeText == text
            } else {
                nodeText.contains(text)
            }

            if (match) return node

            for (i in 0 until node.childCount) {
                val child = node.getChild(i) ?: continue
                val result = findNodeByTextRecursive(child, text, exact)
                if (result != null) return result
                child.recycle()
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error in findNodeByTextRecursive", e)
        }

        return null
    }

    /**
     * 透過 resource-id 點擊節點。
     */
    fun clickByResourceId(resourceId: String): Boolean {
        val node = findNodeByResourceId(resourceId) ?: run {
            Log.w(TAG, "Node not found: $resourceId")
            return false
        }

        return try {
            val result = if (node.isClickable) {
                node.performAction(AccessibilityNodeInfo.ACTION_CLICK)
            } else {
                Log.w(TAG, "Node is not clickable: $resourceId")
                false
            }
            node.recycle()
            result
        } catch (e: Exception) {
            Log.e(TAG, "Error clicking node: $resourceId", e)
            false
        }
    }

    /**
     * 透過文字點擊節點。
     */
    fun clickByText(text: String, exact: Boolean = true): Boolean {
        val node = findNodeByText(text, exact) ?: run {
            Log.w(TAG, "Node not found with text: $text")
            return false
        }

        return try {
            val result = if (node.isClickable) {
                node.performAction(AccessibilityNodeInfo.ACTION_CLICK)
            } else {
                Log.w(TAG, "Node is not clickable with text: $text")
                false
            }
            node.recycle()
            result
        } catch (e: Exception) {
            Log.e(TAG, "Error clicking node with text: $text", e)
            false
        }
    }

    /**
     * 列出所有 UI 元素。
     */
    fun listAllElements(): List<Map<String, String>> {
        val elements = mutableListOf<Map<String, String>>()

        // 方法 1：嘗試活動視窗
        val root = getRootInActiveWindow()
        if (root != null) {
            Log.d(TAG, "Found active window root")
            listAllElementsRecursive(root, elements)
            root.recycle()
        } else {
            Log.w(TAG, "Active window root is null")
        }

        // 方法 2：嘗試所有視窗（Android 8+）
        try {
            val windows = uiAutomation.windows
            Log.d(TAG, "Trying to access ${windows.size} windows")

            for (i in 0 until windows.size) {
                try {
                    val window = windows[i]
                    val windowRoot = window.root
                    if (windowRoot != null) {
                        Log.d(TAG, "Window[$i]: ${window.title} - found root")
                        listAllElementsRecursive(windowRoot, elements)
                        windowRoot.recycle()
                    } else {
                        Log.d(TAG, "Window[$i]: ${window.title} - root is null")
                    }
                } catch (e: Exception) {
                    Log.w(TAG, "Error accessing window[$i]: ${e.message}")
                }
            }
        } catch (e: Exception) {
            Log.w(TAG, "Failed to access all windows: ${e.message}")
            // getWindows() 在舊版 Android 可能不可用
        }

        Log.d(TAG, "Found ${elements.size} total elements")
        return elements
    }

    private fun listAllElementsRecursive(
        node: AccessibilityNodeInfo,
        elements: MutableList<Map<String, String>>
    ) {
        try {
            val rid = node.viewIdResourceName
            val text = node.text?.toString() ?: ""
            val desc = node.contentDescription?.toString() ?: ""

            if (rid != null || text.isNotEmpty() || desc.isNotEmpty()) {
                val item = mutableMapOf<String, String>()
                if (rid != null) item["rid"] = rid
                if (text.isNotEmpty()) item["text"] = text
                if (desc.isNotEmpty()) item["desc"] = desc
                elements.add(item)
            }

            for (i in 0 until node.childCount) {
                val child = node.getChild(i) ?: continue
                listAllElementsRecursive(child, elements)
                child.recycle()
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error in listAllElementsRecursive", e)
        }
    }

    /**
     * 尋找權限對話框按鈕。
     */
    fun findPermissionDialogButtons(): Map<String, Map<String, String>> {
        val buttons = mutableMapOf<String, Map<String, String>>()

        val buttonIds = mapOf(
            "allow_foreground" to "com.android.permissioncontroller:id/permission_allow_foreground_only_button",
            "allow_once" to "com.android.permissioncontroller:id/permission_allow_one_time_button",
            "deny" to "com.android.permissioncontroller:id/permission_deny_button",
            "allow" to "com.android.permissioncontroller:id/permission_allow_button"
        )

        for ((type, id) in buttonIds) {
            val node = findNodeByResourceId(id)
            if (node != null) {
                val info = mapOf(
                    "rid" to id,
                    "text" to (node.text?.toString() ?: "")
                )
                buttons[type] = info
                node.recycle()
            }
        }

        return buttons
    }

    /**
     * 檢查 resource-id 是否存在。
     */
    fun existsByResourceId(resourceId: String): Boolean {
        val node = findNodeByResourceId(resourceId)
        if (node != null) {
            node.recycle()
            return true
        }
        return false
    }

    /**
     * 檢查文字是否存在。
     */
    fun existsByText(text: String, exact: Boolean = true): Boolean {
        val node = findNodeByText(text, exact)
        if (node != null) {
            node.recycle()
            return true
        }
        return false
    }
}
