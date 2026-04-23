from __future__ import annotations

import json
import re
import sys
from pathlib import Path
import time
from typing import Optional
from contextlib import contextmanager

ROOT = Path(__file__).resolve().parents[1]  # /home/h/lineageos/device/sony/SemcCameraUI
TEST_CAMERA_DIR = Path(__file__).resolve().parent  # /SemcCameraUI/test_camera
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(TEST_CAMERA_DIR))

from tools_Common.adb import Adb  # noqa: E402
from key import ClickTarget  # noqa: E402

TIMEOUT: int = 5000


# ------------------------------------------------------------
# 自定義例外類別
# ------------------------------------------------------------
class WaitTargetNotFoundError(Exception): ...


class ClickFailedError(Exception): ...


class InvalidClickTargetError(Exception): ...


# ------------------------------------------------------------
# 低階 API（直接對 UiAgent 發送命令）
# ------------------------------------------------------------
def click_rid_desc(adb: Adb, rid: str, content_desc: str) -> bool:
    """觸發 rid + content_desc 所對應元件的點擊事件"""
    resp = _broadcast(adb, cmd="click_rid_content_desc", rid=rid, desc=content_desc)
    return bool(resp.get("clicked", False))


def click_rid_text(adb: Adb, rid: str, text: str) -> bool:
    """觸發 rid + text 所對應元件的點擊事件"""
    resp = _broadcast(adb, cmd="click_rid_text", rid=rid, text=text)
    return bool(resp.get("clicked", False))


def click_rid(adb: Adb, rid: str) -> bool:
    """觸發 rid 所對應元件的點擊事件"""
    resp = _broadcast(adb, cmd="click_rid", rid=rid)
    return bool(resp.get("clicked", False))


def click_text(adb: Adb, text: str) -> bool:
    """觸發 text 所對應元件的點擊事件"""
    resp = _broadcast(adb, cmd="click_text", text=text)
    return bool(resp.get("clicked", False))


def exists_rid_desc(adb: Adb, rid: str, content_desc: str) -> bool:
    """查詢指定 rid + content_desc 的元件是否存在"""
    resp = _broadcast(adb, cmd="exists_rid_content_desc", rid=rid, desc=content_desc)
    return bool(resp.get("exists", False))


def exists_rid_text(adb: Adb, rid: str, text: str) -> bool:
    """查詢指定 rid + text 的元件是否存在"""
    resp = _broadcast(adb, cmd="exists_rid_text", rid=rid, text=text)
    return bool(resp.get("exists", False))


def exists_rid(adb: Adb, rid: str) -> bool:
    """查詢指定 rid 的元件是否存在"""
    resp = _broadcast(adb, cmd="exists_rid", rid=rid)
    return bool(resp.get("exists", False))


def exists_text(adb: Adb, text: str) -> bool:
    """查詢指定 text 的元件是否存在"""
    resp = _broadcast(adb, cmd="exists_text", text=text)
    return bool(resp.get("exists", False))


def wait_exists_rid_desc(
    adb: Adb, rid: str, content_desc: str, timeout_ms: int = TIMEOUT
) -> bool:
    """等待 rid + content_desc 元件出現，直到超時"""
    resp = _broadcast(
        adb,
        cmd="wait_exists_rid_content_desc",
        rid=rid,
        desc=content_desc,
        timeout_ms=timeout_ms,
    )
    return bool(resp.get("exists", False))


def wait_exists_rid_text(
    adb: Adb, rid: str, text: str, timeout_ms: int = TIMEOUT
) -> bool:
    """等待 rid + text 元件出現，直到超時"""
    resp = _broadcast(
        adb,
        cmd="wait_exists_rid_text",
        rid=rid,
        text=text,
        timeout_ms=timeout_ms,
    )
    return bool(resp.get("exists", False))


def wait_exists_rid(adb: Adb, rid: str, timeout_ms: int = TIMEOUT) -> bool:
    """等待 rid 元件出現，直到超時"""
    resp = _broadcast(adb, cmd="wait_exists_rid", rid=rid, timeout_ms=timeout_ms)
    return bool(resp.get("exists", False))


def wait_exists_text(adb: Adb, text: str, timeout_ms: int = TIMEOUT) -> bool:
    """等待 text 元件出現，直到超時"""
    resp = _broadcast(adb, cmd="wait_exists_text", text=text, timeout_ms=timeout_ms)
    return bool(resp.get("exists", False))


def wait_not_exists_rid_desc(
    adb: Adb, rid: str, content_desc: str, timeout_ms: int = TIMEOUT
) -> bool:
    """等待 rid + content_desc 元件消失，直到超時"""
    resp = _broadcast(
        adb,
        cmd="wait_not_exists_rid_content_desc",
        rid=rid,
        desc=content_desc,
        timeout_ms=timeout_ms,
    )
    return bool(resp.get("not_exists", False))


def wait_not_exists_rid_text(
    adb: Adb, rid: str, text: str, timeout_ms: int = TIMEOUT
) -> bool:
    """等待 rid + text 元件消失，直到超時"""
    resp = _broadcast(
        adb,
        cmd="wait_not_exists_rid_text",
        rid=rid,
        text=text,
        timeout_ms=timeout_ms,
    )
    return bool(resp.get("not_exists", False))


def wait_not_exists_rid(adb: Adb, rid: str, timeout_ms: int = TIMEOUT) -> bool:
    """等待 rid 元件消失，直到超時"""
    resp = _broadcast(adb, cmd="wait_not_exists_rid", rid=rid, timeout_ms=timeout_ms)
    return bool(resp.get("not_exists", False))


def wait_not_exists_text(adb: Adb, text: str, timeout_ms: int = TIMEOUT) -> bool:
    """等待 text 元件消失，直到超時"""
    resp = _broadcast(adb, cmd="wait_not_exists_text", text=text, timeout_ms=timeout_ms)
    return bool(resp.get("not_exists", False))


# ------------------------------------------------------------
# 中階 API（根據 ClickTarget 的欄位自動選擇適合的 handler）
# ------------------------------------------------------------
HANDLERS = {
    "click": {
        "rid_desc": click_rid_desc,
        "rid_text": click_rid_text,
        "rid": click_rid,
        "text": click_text,
    },
    "exists": {
        "rid_desc": exists_rid_desc,
        "rid_text": exists_rid_text,
        "rid": exists_rid,
        "text": exists_text,
    },
    "wait": {
        "rid_desc": wait_exists_rid_desc,
        "rid_text": wait_exists_rid_text,
        "rid": wait_exists_rid,
        "text": wait_exists_text,
    },
    "wait_not_exists": {
        "rid_desc": wait_not_exists_rid_desc,
        "rid_text": wait_not_exists_rid_text,
        "rid": wait_not_exists_rid,
        "text": wait_not_exists_text,
    },
}


def run_handler(adb: Adb, mode: str, target: ClickTarget, timeout_ms=None):
    handlers = HANDLERS.get(mode)  # 根據 mode 決定執行的函數
    if not handlers:
        raise ValueError(f"Unknown mode: {mode}")

    # 解析 target 的 selector，決定要呼叫哪個 handler 以及傳哪些參數
    func, kwargs = resolve_selectors(target, handlers)

    if not func:
        raise ValueError("Invalid target: no selector matched")

    if timeout_ms is not None:  # 有傳入 timeout_ms
        kwargs["timeout_ms"] = timeout_ms  # 加入 timeout_ms 參數到 kwargs 中
    return func(adb, **kwargs)  # **kwargs展開


def resolve_selectors(target: ClickTarget, handlers: dict):
    if target.rid and target.desc:
        return handlers["rid_desc"], {
            "rid": target.rid,
            "content_desc": target.desc,
        }
    elif target.rid and target.text:
        return handlers["rid_text"], {
            "rid": target.rid,
            "text": target.text,
        }
    elif target.rid:
        return handlers["rid"], {
            "rid": target.rid,
        }
    elif target.text:
        return handlers["text"], {
            "text": target.text,
        }
    raise ValueError("Invalid target: no selector matched")


def click(adb: Adb, target: ClickTarget, raise_on_fail: bool = True) -> bool:
    """觸發 target 所對應元件的點擊事件"""
    result = False
    result = run_handler(adb, "click", target)
    if not result and raise_on_fail:
        raise ClickFailedError(f"❌ 點擊失敗: {target.key_name}")
    return result


def exists(adb: Adb, target: ClickTarget) -> bool:
    """查詢元件是否存在。"""
    result = run_handler(adb, "exists", target)
    return result


def wait_exists(
    adb: Adb,
    target: ClickTarget,
    timeout_ms: int = TIMEOUT,
    raise_on_fail: bool = True,
) -> bool:
    """等待元件出現。"""
    if run_handler(adb, "wait", target, timeout_ms=timeout_ms):
        return True
    if raise_on_fail:
        raise WaitTargetNotFoundError(
            f"❌ 目標未出現: {target.key_name}, timeout={timeout_ms}ms"
        )
    return False


def wait_not_exists(
    adb: Adb,
    target: ClickTarget,
    timeout_ms: int = TIMEOUT,
    raise_on_fail: bool = True,
) -> bool:
    """等待元件消失。"""
    if run_handler(adb, "wait_not_exists", target, timeout_ms=timeout_ms):
        return True
    if raise_on_fail:
        raise WaitTargetNotFoundError(
            f"❌ 目標未消失: {target.key_name}, timeout={timeout_ms}ms"
        )
    return False


def wait_then_click(
    adb: Adb,
    click_target: ClickTarget,
    timeout_ms: int = TIMEOUT,
    raise_on_fail: bool = True,
) -> bool:
    """先等待元件出現，再執行點擊"""
    w = wait_exists(
        adb, click_target, timeout_ms=timeout_ms, raise_on_fail=raise_on_fail
    )
    c = click(adb, click_target, raise_on_fail=raise_on_fail)
    return w and c


def click_then_appear(
    adb: Adb,
    A: ClickTarget,
    B: ClickTarget,
    timeout_ms=TIMEOUT,
) -> None:
    try:
        wait_exists(adb, A, timeout_ms=timeout_ms)
        click(adb, A)
        wait_exists(adb, B, timeout_ms=timeout_ms)
    except Exception as e:
        raise RuntimeError(f"{A.key_name} → {B.key_name} transition failed") from e


def click_then_disappear(
    adb: Adb,
    A: ClickTarget,
    B: ClickTarget,
    timeout_ms=TIMEOUT,
) -> None:
    try:
        wait_exists(adb, A, timeout_ms=timeout_ms)
        click(adb, A)
        wait_not_exists(adb, B, timeout_ms=timeout_ms)
    except Exception as e:
        raise RuntimeError(f"{A.key_name} → {B.key_name} transition failed") from e


def click_child_rid(adb, rid, **kwargs):
    ok = click_child_under_rid(adb, rid, **kwargs)
    if not ok:
        raise RuntimeError(f"click_child_under_rid failed: {rid}, {kwargs}")


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
    adb: Adb,
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

    p = adb.run(args, check=True)
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
# 高階 API（封裝常用 UiAgent 指令）
# ------------------------------------------------------------
def ping(adb: Adb) -> dict:
    """發送 ping 命令以驗證 UiAgent 連線"""
    return _broadcast(adb, cmd="ping")


def list_rids(adb: Adb, *, dedupe: bool = True) -> list[str]:
    """從 UiAgent 取得「目前畫面所有 resource-id（rid）」清單。"""
    resp = _broadcast(adb, cmd="list_rids")
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


def list_texts(adb: Adb, *, dedupe: bool = True) -> list[str]:
    """從 UiAgent 取得「目前畫面所有 text」清單。"""
    resp = _broadcast(adb, cmd="list_texts")
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


def list_all_elements(adb: Adb) -> list[dict[str, str]]:
    """從 UiAgent 取得「目前畫面所有元件」的 rid 與 text 配對清單。"""
    resp = _broadcast(adb, cmd="list_all_elements")
    elements = resp.get("elements", [])
    if not isinstance(elements, list):
        raise RuntimeError(f"UiAgent: invalid elements type: {type(elements)}")
    return elements


def list_all_elements_with_class(adb: Adb) -> list[dict[str, str]]:
    """從 UiAgent 取得「目前畫面所有元件」的 rid、text 及 class 資訊。"""
    resp = _broadcast(adb, cmd="list_all_elements_with_class")
    elements = resp.get("elements", [])
    if not isinstance(elements, list):
        raise RuntimeError(f"UiAgent: invalid elements type: {type(elements)}")
    return elements


# ------------------------------------------------------------
# 只用 UiAgent：用上層 rid 找子樹 clickable 按鈕
# ------------------------------------------------------------
def click_child_under_rid(
    adb: Adb,
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
        adb,
        cmd="click_child_under_rid",
        rid=rid,
        pick=pick,
        index=index,
    )
    return bool(resp.get("clicked", False))


def swipe(adb: Adb, x1: int, y1: int, x2: int, y2: int, duration_ms: int = 300) -> bool:
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
        adb,
        cmd="swipe",
        x1=x1,
        y1=y1,
        x2=x2,
        y2=y2,
        duration_ms=duration_ms,
    )
    return bool(resp.get("swiped", False))


# ------------------------------------------------------------
# 查詢畫面上的元件並返回 ClickTarget 陣列
# ------------------------------------------------------------
def query_elements(
    adb: Adb,
    rid: Optional[str] = None,
    *,
    text: Optional[str] = None,
    desc: Optional[str] = None,
    class_name: Optional[str] = None,
) -> ClickTarget:
    """查詢目前畫面上的元件，根據提供的欄位進行篩選，返回符合條件的 ClickTarget 陣列。

    Args:
        rid: 要查詢的 Resource ID（支援模糊匹配）
        text: 要查詢的 Text（支援模糊匹配）
        desc: 要查詢的 Content-Desc（支援模糊匹配）
        class_name: 要查詢的 Class（支援模糊匹配）

    Returns:
        符合條件的 ClickTarget 陣列（key_name 由 rid 或 text 或 desc 組成）
    """
    if not any([rid, text, desc, class_name]):
        raise ValueError(
            "至少需要提供一個查詢欄位 (resource_id, text, desc, class_name)"
        )

    elements = list_all_elements_with_class(adb)
    results: list[ClickTarget] = []

    for i, elem in enumerate(elements):
        _rid = elem.get("rid", "").strip()
        _text = elem.get("text", "").strip()
        _desc = elem.get("desc", "").strip()
        _cls = elem.get("class", "").strip()

        # 檢查是否符合查詢條件
        match = True

        if rid is not None:
            if rid != _rid:
                match = False

        if text is not None:
            if text != _text:
                match = False

        if desc is not None:
            if desc != _desc:
                match = False

        if class_name is not None:
            if class_name != _cls:
                match = False

        if not match:
            continue

        results.append(
            ClickTarget(
                key_name="query",
                rid=_rid if _rid else None,
                text=_text if _text else None,
                desc=_desc if _desc else None,
            )
        )
    if results:
        return results[0]
    else:
        raise RuntimeError(f"查詢目標不唯一: {results}")
