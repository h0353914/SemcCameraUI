from __future__ import annotations

import json
import re
import sys
from pathlib import Path
import time
from typing import Optional

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))

from SemcCameraUI.tools_Common.test_camera.key import ClickTarget  # noqa: E402
from SemcCameraUI.tools_Common.adb import Adb  # noqa: E402

ADB = Adb()


# ------------------------------------------------------------
# UiAgent broadcast 設定（用於透過 am broadcast 與 UiAgent 互動）
# ------------------------------------------------------------
UIAGENT_PKG = "com.example.uiagent"
UIAGENT_RCV = ".UiAgentCmdReceiver"
UIAGENT_ACTION = "com.example.uiagent.CMD"


# ------------------------------------------------------------
# 低階：透過 am broadcast 發送命令並解析返回的 result-data
# ------------------------------------------------------------
def _escape_shell_arg(s: str) -> str:
    """將字符串用引號包圍以保護特殊字符。"""
    # 在 adb shell am broadcast 中，用雙引號包圍字符串可以保護大多數特殊字符
    # 但需要轉義內部的雙引號和反斜杠
    s = s.replace("\\", "\\\\")  # 反斜杠需要轉義
    s = s.replace('"', '\\"')  # 雙引號需要轉義
    return f'"{s}"'


def _broadcast(
    *,
    cmd: str,
    rid: Optional[str] = None,
    text: Optional[str] = None,
    desc: Optional[str] = None,
    timeout_ms: Optional[int] = None,
    pick: Optional[str] = None,
    index: Optional[int] = None,
    x1: Optional[int] = None,
    y1: Optional[int] = None,
    x2: Optional[int] = None,
    y2: Optional[int] = None,
    duration_ms: Optional[int] = None,
) -> dict:
    """使用 adb shell am broadcast 呼叫 UiAgentService（純 UiAgent 方案）。

    回傳：解析後的 JSON dict（來自 setResultData）
    """

    args: list[str] = [
        "shell",
        "am",
        "broadcast",
        "-n",
        f"{UIAGENT_PKG}/{UIAGENT_RCV}",
        "-a",
        UIAGENT_ACTION,
        "--es",
        "cmd",
        cmd,
    ]

    if rid:
        args += ["--es", "rid", rid]
    if text:
        args += ["--es", "text", _escape_shell_arg(text)]
    if desc:
        args += ["--es", "desc", _escape_shell_arg(desc)]
    if timeout_ms is not None:
        args += ["--ei", "timeout_ms", str(int(timeout_ms))]
    if pick is not None:
        args += ["--es", "pick", _escape_shell_arg(str(pick))]
    if index is not None:
        args += ["--ei", "index", str(int(index))]
    if x1 is not None:
        args += ["--ei", "x1", str(int(x1))]
    if y1 is not None:
        args += ["--ei", "y1", str(int(y1))]
    if x2 is not None:
        args += ["--ei", "x2", str(int(x2))]
    if y2 is not None:
        args += ["--ei", "y2", str(int(y2))]
    if duration_ms is not None:
        args += ["--ei", "duration_ms", str(int(duration_ms))]

    p = ADB.run(args, check=True)
    out = (p.stdout or "") + "\n" + (p.stderr or "")

    # am broadcast 會輸出： data="{...}"
    # 使用 DOTALL 模式以支援多行，並使用非貪心匹配
    m = re.search(r'data="(.+?)"(?:\s|$)', out, re.DOTALL)
    if not m:
        raise RuntimeError(f"UiAgent: no result data\n{out}")

    try:
        json_str = m.group(1)
        # 處理 JSON 字串中的實際換行符（不是轉義的 \n）
        # 將實際換行符轉換為 \n 轉義序列
        json_str = json_str.replace("\n", "\\n").replace("\r", "\\r")
        return json.loads(json_str)
    except Exception as e:
        # 顯示完整的 JSON 字串以便除錯
        raise RuntimeError(f"UiAgent: invalid JSON\n{m.group(1)}") from e


# ------------------------------------------------------------
# 檢查是否安裝
# ------------------------------------------------------------
def is_uiagent_installed() -> bool:
    """檢查裝置上是否已安裝 UiAgentService（Broadcast 版）。"""
    package = UIAGENT_PKG
    p = ADB.run(["shell", "cmd", "package", "list", "packages", package], check=True)
    out = p.stdout or ""
    target = f"package:{package}"
    for line in out.splitlines():
        if line.strip() == target:
            return True
    return False


# ------------------------------------------------------------
# 高階 API（封裝常用 UiAgent 指令）
# ------------------------------------------------------------
def ping() -> dict:
    """發送 ping 命令以驗證 UiAgent 連線"""
    return _broadcast(cmd="ping")


def exists_rid(rid: str) -> bool:
    """查詢指定 rid 的元件是否存在"""
    resp = _broadcast(cmd="exists_rid", rid=rid)
    return bool(resp.get("exists", False))


def click_rid(target: ClickTarget) -> bool:
    """觸發 target 所對應元件的點擊事件"""
    rid = target.resource_id
    if not rid:
        raise ValueError(f"ClickTarget {target.key_name!r} has no resource_id")

    if target.text:
        resp = _broadcast(cmd="click_rid_text", rid=rid, text=target.text)
    elif target.content_desc:
        resp = _broadcast(
            cmd="click_rid_content_desc", rid=rid, desc=target.content_desc
        )
    else:
        resp = _broadcast(cmd="click_rid", rid=rid)
    return bool(resp.get("clicked", False))


def exists_text(text: str) -> bool:
    """查詢指定 text 的元件是否存在"""
    resp = _broadcast(cmd="exists_text", text=text)
    return bool(resp.get("exists", False))


def exists_rid_content_desc(rid: str, content_desc: str) -> bool:
    """查詢指定 rid + content_desc 的元件是否存在"""
    resp = _broadcast(cmd="exists_rid_content_desc", rid=rid, desc=content_desc)
    return bool(resp.get("exists", False))


def click_rid_content_desc(rid: str, content_desc: str) -> bool:
    """觸發 rid + content_desc 所對應元件的點擊事件"""
    resp = _broadcast(cmd="click_rid_content_desc", rid=rid, desc=content_desc)
    return bool(resp.get("clicked", False))


def wait_exists_rid_content_desc(
    rid: str, content_desc: str, timeout_ms: int = 1200
) -> bool:
    """等待 rid + content_desc 元件出現，直到超時"""
    resp = _broadcast(
        cmd="wait_exists_rid_content_desc",
        rid=rid,
        desc=content_desc,
        timeout_ms=timeout_ms,
    )
    return bool(resp.get("exists", False))


def click_text(text: str) -> bool:
    """觸發 text 所對應元件的點擊事件"""
    resp = _broadcast(cmd="click_text", text=text)
    return bool(resp.get("clicked", False))


def wait_exists_rid(rid: str, timeout_ms: int = 1200) -> bool:
    """等待 rid 元件出現，直到超時"""
    resp = _broadcast(cmd="wait_exists_rid", rid=rid, timeout_ms=timeout_ms)
    return bool(resp.get("exists", False))


def list_rids(*, dedupe: bool = True) -> list[str]:
    """從 UiAgent 取得「目前畫面所有 resource-id（rid）」清單。"""
    resp = _broadcast(cmd="list_rids")
    rids = resp.get("rids", [])
    if not isinstance(rids, list):
        raise RuntimeError(f"UiAgent: invalid rids type: {type(rids)}")

    out: list[str] = []
    seen: set[str] = set()
    for it in rids:
        if not isinstance(it, str):
            continue
        s = it.strip()
        if not s:
            continue
        if dedupe:
            if s in seen:
                continue
            seen.add(s)
        out.append(s)
    return out


def list_texts(*, dedupe: bool = True) -> list[str]:
    """從 UiAgent 取得「目前畫面所有 text」清單。"""
    resp = _broadcast(cmd="list_texts")
    texts = resp.get("texts", [])
    if not isinstance(texts, list):
        raise RuntimeError(f"UiAgent: invalid texts type: {type(texts)}")

    out: list[str] = []
    seen: set[str] = set()
    for it in texts:
        if not isinstance(it, str):
            continue
        s = it.strip()
        if not s:
            continue
        if dedupe:
            if s in seen:
                continue
            seen.add(s)
        out.append(s)
    return out


def list_all_elements() -> list[dict[str, str]]:
    """從 UiAgent 取得「目前畫面所有元件」的 rid 與 text 配對清單。"""
    resp = _broadcast(cmd="list_all_elements")
    elements = resp.get("elements", [])
    if not isinstance(elements, list):
        raise RuntimeError(f"UiAgent: invalid elements type: {type(elements)}")
    return elements


# ------------------------------------------------------------
# 只用 UiAgent：用上層 rid 找子樹 clickable 按鈕
# ------------------------------------------------------------
def click_child_under_rid(
    rid: str,
    *,
    pick: str = "left",
    index: int = 0,
) -> bool:
    """用「上層 resource-id」去點沒有 resource-id 的子按鈕（純 UiAgent）。

    pick：
    - left  : 選 x 最小（最左）
    - right : 選 x 最大（最右）
    - index : 依 service 掃描順序選第 index 個 (0-based)
    """
    resp = _broadcast(
        cmd="click_child_under_rid",
        rid=rid,
        pick=pick,
        index=index,
    )
    return bool(resp.get("clicked", False))


def swipe(x1: int, y1: int, x2: int, y2: int, duration_ms: int = 300) -> bool:
    """執行滑動手勢（從 x1,y1 滑到 x2,y2）。

    Args:
        x1: 起點 x 座標
        y1: 起點 y 座標
        x2: 終點 x 座標
        y2: 終點 y 座標
        duration_ms: 滑動持續時間（毫秒），預設 300ms

    Returns:
        是否成功執行滑動
    """
    resp = _broadcast(
        cmd="swipe",
        x1=x1,
        y1=y1,
        x2=x2,
        y2=y2,
        duration_ms=duration_ms,
    )
    return bool(resp.get("swiped", False))


# ------------------------------------------------------------
# ClickTarget 相容層（你目前的測試流程常用）
# ------------------------------------------------------------
def click(target: ClickTarget) -> bool:
    """優先使用 resource_id + text，或 resource_id + content_desc，或單獨使用其中之一進行點擊。"""
    if target.resource_id:
        return click_rid(target)
    elif target.text:
        return click_text(target.text)
    else:
        raise ValueError(
            f"ClickTarget {target.key_name!r} has no identification (rid/text/content_desc)"
        )


def exists(target: ClickTarget) -> bool:
    """查詢元件是否存在。"""
    if target.resource_id and target.content_desc:
        return exists_rid_content_desc(target.resource_id, target.content_desc)
    if target.resource_id:
        return exists_rid(target.resource_id)
    if target.text:
        return exists_text(target.text)
    return False


def wait_exists(target: ClickTarget, timeout_ms: int = 3000) -> bool:
    """等待元件出現。"""
    if target.resource_id and target.content_desc:
        return wait_exists_rid_content_desc(
            target.resource_id, target.content_desc, timeout_ms=timeout_ms
        )
    if target.resource_id:
        return wait_exists_rid(target.resource_id, timeout_ms=timeout_ms)
    # 目前 UiAgent 尚未提供 wait_exists_text，若有需要需在 Service 補上
    if target.text:
        # 暫時用 loop 模擬，或者直接調用 exists
        deadline = time.monotonic() + timeout_ms / 1000.0
        while time.monotonic() < deadline:
            if exists_text(target.text):
                return True
            time.sleep(0.2)
        return False

    raise ValueError(
        f"ClickTarget {target.key_name!r} has no identification (rid/text/content_desc)"
    )


def wait_then_click(
    wait_target: ClickTarget,
    click_target: Optional[ClickTarget] = None,
    timeout_ms: int = 3000,
) -> bool:
    """先等待 wait_target 出現，再點擊 click_target。"""
    if click_target is None:
        click_target = wait_target
    return_value = wait_exists(wait_target, timeout_ms=timeout_ms)
    print(f"等待 {wait_target.key_name} 出現?", return_value)
    if return_value:
        print(f"點擊{wait_target.key_name} {click(click_target)}")
        return True
    print(f"點擊{wait_target.key_name} 失敗...")


def click_if_exists(click_target: ClickTarget) -> bool:
    if exists(click_target):
        click(click_target)
        return True
    return False
