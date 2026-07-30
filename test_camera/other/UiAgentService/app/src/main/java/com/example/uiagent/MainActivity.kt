package com.example.uiagent

import android.content.Intent
import android.os.Bundle
import android.provider.Settings
import android.widget.Button
import android.widget.TextView
import androidx.activity.ComponentActivity

/**
 * UiAgent 主 Activity — 提供無障礙服務的狀態顯示與設定入口。
 *
 * 功能說明：
 * - 顯示 [UiAgentAccessibilityService] 目前是否已開啟。
 * - 提供按鈕直接跳轉至系統無障礙設定頁面，讓使用者手動啟用服務。
 *
 * 注意：本 Activity 僅為管理介面，實際 UI 自動化操作由
 * [UiAgentAccessibilityService] 與 [UiAgentCmdReceiver] 負責。
 */
class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val tvStatus = findViewById<TextView>(R.id.tvStatus)
        val btnAcc = findViewById<Button>(R.id.btnAccessibility)

        // 更新畫面上顯示的無障礙服務啟用狀態
        fun refresh() {
            val acc = UiAgentAccessibilityService.isEnabled(this)
            val accText = if (acc) getString(R.string.enabled) else getString(R.string.disabled)
            tvStatus.text = getString(R.string.status_lines, accText)
        }

        refresh()

        // 點擊後跳轉至系統無障礙設定，讓使用者手動開啟 UiAgentAccessibilityService
        btnAcc.setOnClickListener {
            startActivity(Intent(Settings.ACTION_ACCESSIBILITY_SETTINGS))
        }
    }
}
