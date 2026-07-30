package com.example.uiagent

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent

/**
 * Compatibility receiver.
 * Some clients send explicit broadcasts to `com.example.uiagent/.UiAgentReceiver`.
 * Delegates to [UiAgentCmdReceiver] which handles the command protocol and sets result-data.
 */
class UiAgentReceiver : BroadcastReceiver() {
    private val impl = UiAgentCmdReceiver()

    override fun onReceive(context: Context, intent: Intent) {
        impl.onReceive(context, intent)
    }
}
