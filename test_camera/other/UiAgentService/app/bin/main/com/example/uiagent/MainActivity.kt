package com.example.uiagent

import android.content.Intent
import android.os.Bundle
import android.provider.Settings
import android.widget.Button
import android.widget.TextView
import androidx.activity.ComponentActivity

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val tvStatus = findViewById<TextView>(R.id.tvStatus)
        val btnAcc = findViewById<Button>(R.id.btnAccessibility)

        fun refresh() {
            val acc = UiAgentAccessibilityService.isEnabled(this)
            val accText = if (acc) getString(R.string.enabled) else getString(R.string.disabled)
            tvStatus.text = getString(R.string.status_lines, accText)
        }

        refresh()

        btnAcc.setOnClickListener {
            startActivity(Intent(Settings.ACTION_ACCESSIBILITY_SETTINGS))
        }
    }
}
