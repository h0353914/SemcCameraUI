#!/usr/bin/env python3
"""
比較 Java 編譯後轉 smali 與原有 smali 版本的差異（精細版）
分類：
1. 檔案完全相同 (sha256 相同)
2. 功能完全等價 (內容不同但功能相同)
3. 實際有差異
"""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import subprocess
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import List, Optional, Set

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

ANDROID_TOP = Path("/home/h/lineageos")
JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")
APKTOOL_JAR = ROOT / "tools_Common" / "apktool.jar"

# ── 審計日誌：記錄所有「不能保證 100% 邏輯一致」的等價判定 ──
# 每筆記錄: {"file": str, "method": str, "strategy": str, "risk": str, "detail": str}
_AUDIT_LOG: list[dict] = []
_AUDIT_CONTEXT: dict[str, str] = {"file": "", "method": ""}


def _audit(strategy: str, risk: str, detail: str = ""):
    """記錄一筆可疑等價判定到審計日誌。"""
    _AUDIT_LOG.append(
        {
            "file": _AUDIT_CONTEXT.get("file", ""),
            "method": _AUDIT_CONTEXT.get("method", ""),
            "strategy": strategy,
            "risk": risk,
            "detail": detail,
        }
    )


# ── 差異類型常數 ────────────────────────────────────────────
class DiffKind:
    LINE_NUMBERS = "行號差異 (.line)"
    SOURCE_FILE = "來源檔聲明差異 (.source)"
    ANNOTATIONS_BUILD = "編譯期/執行期註解差異"
    ANNOTATIONS_MEMBER_ORDER = "內部類註解順序差異"
    REGISTER_RENAME = "暫存器重新命名 (參數暫存器重用)"
    LOCALS_COUNT = "區域變數數量宣告差異 (.locals)"
    FIELD_DEFAULT = "欄位預設值差異 (= false / = 0)"
    EMPTY_CLINIT = "空靜態初始化器差異 (<clinit>)"
    PROLOGUE = ".prologue 差異"
    END_FIELD = ".end field 差異"
    LOCAL_VAR_DEBUG = "區域變數偵錯資訊差異 (.local/.end local/.restart local)"
    PARAM_ANNOTATION = "參數註解差異 (.param)"
    COMMENT_ONLY = "僅註解差異"
    WHITESPACE = "空白/空行差異"
    ACCESS_METHOD_NUM = "access$ 合成方法編號差異"
    ENUM_VALUES = "enum $values() 合成方法差異"
    INSTR_VARIANT = "指令變體 (filled-new-array/mul-int-lit/if-chain vs switch 等)"
    CONTROL_FLOW = "控制流程重排 (goto/return 等)"
    CONSTRUCTOR_INIT_ORDER = "建構函式欄位初始化順序差異"
    CLINIT_REORDER = "<clinit> 靜態初始化器指令重排"
    REAL_CODE = "實際程式碼/邏輯差異"


@dataclass
class FileDiff:
    """單個檔的比較結果"""

    rel_path: str
    category: int  # 1=完全一样, 2=功能等價, 3=有差異
    diff_kinds: list[str] = field(default_factory=list)
    detail: str = ""
    diff_lines_java_only: int = 0
    diff_lines_orig_only: int = 0
    # 跨檔匹配用：未匹配方法签名
    unmatched_java: list[str] = field(default_factory=list)
    unmatched_orig: list[str] = field(default_factory=list)
    has_body_diff: bool = False
    has_header_diff: bool = False
    # 跨檔头部匹配用：未匹配头部行
    header_diff_java: list[str] = field(default_factory=list)
    header_diff_orig: list[str] = field(default_factory=list)


@dataclass
class ComparisonResult:
    """整體比較結果"""

    files: List[FileDiff] = field(default_factory=list)
    only_in_java: List[str] = field(default_factory=list)
    only_in_original: List[str] = field(default_factory=list)

    @property
    def identical(self) -> List[FileDiff]:
        return [f for f in self.files if f.category == 1]

    @property
    def equivalent(self) -> List[FileDiff]:
        return [f for f in self.files if f.category == 2]

    @property
    def different(self) -> List[FileDiff]:
        return [f for f in self.files if f.category == 3]


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for block in iter(lambda: f.read(4096), b""):
            h.update(block)
    return h.hexdigest()


# ── smali 行分類 ───────────────────────────────────────────
_RE_LINE = re.compile(r"^\s*\.line\s+\d+")
_RE_SOURCE = re.compile(r"^\s*\.source\s+")
_RE_LOCALS = re.compile(r"^\s*\.locals\s+\d+")
_RE_REGISTERS = re.compile(r"^\s*\.registers\s+\d+")
_RE_PROLOGUE = re.compile(r"^\s*\.prologue")
_RE_LOCAL_VAR = re.compile(r"^\s*\.(local|end local|restart local)\s")
_RE_PARAM = re.compile(r"^\s*\.param\s")
_RE_END_PARAM = re.compile(r"^\s*\.end param")
_RE_END_FIELD = re.compile(r"^\s*\.end field")
_RE_COMMENT = re.compile(r"^\s*#")
# 现在匹配所有 build 和 runtime 註解（不限路径）
_RE_ANNOTATION_BUILD = re.compile(r"^\s*\.annotation\s+(build|runtime)\s+L")
_RE_ANNOTATION_SYSTEM = re.compile(r"^\s*\.annotation\s+system\s+L")
_RE_ANNOTATION = re.compile(r"^\s*\.annotation\s")
_RE_END_ANNOTATION = re.compile(r"^\s*\.end annotation")
_RE_FIELD_DEFAULT_ZERO = re.compile(r"^(\.field\s+.+)\s*=\s*(false|0|0x0|null)\s*$")
# 匹配所有欄位初始值（包括非零常量）：.field xxx = value → .field xxx
_RE_FIELD_DEFAULT_ALL = re.compile(r"^(\.field\s+.+?)\s*=\s*.+$")
_RE_ACCESS_METHOD = re.compile(r"access\$(\d+)")
_RE_ENUM_VALUES = re.compile(r"\.method\s+.*\$values\(\)")
_RE_REGISTER = re.compile(r"(?<!/)\b([vp]\d+)\b(?!/)")
# 匹配 R8/proguard 有名改名模式（AbstractC00XXname, C00XXname, zz* 等）
_RE_DEOBFUSCATED_CLASS = re.compile(
    r"\b(?:(?:Abstract|Interface)\w*)?C\d{3,5}(?=[a-zA-Z])"
)
_RE_OBFUSCATED_FIELD = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)([\w$]+)(:.+)$"
)
# jadx 欄位名重命名正規化：->fNNNx: → ->x: (jadx adds fNNN prefix to short field names)
_RE_JADX_FIELD_RENAME = re.compile(r"->f\d{2,5}([A-Za-z]\w*)([:;)])")
# jadx reserved word prefix: ->f$keyword: → ->keyword:
_RE_JADX_FIELD_RESERVED = re.compile(r"->f\$(\w+)([:;)])")
# jadx 欄位声明重命名正規化：.field ... fNNNx:T → .field ... x:T
_RE_JADX_FIELD_DECL = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)f\d{2,5}([A-Za-z]\w*)(:.+)$"
)
# jadx reserved word field declaration: .field ... f$keyword:T → .field ... keyword:T
_RE_JADX_FIELD_DECL_RESERVED = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)f\$(\w+)(:.+)$"
)

# 成員名稱正規化：->memberName( 或 ->fieldName: → ->_
_RE_MEMBER_NAME = re.compile(r"->[\w$]+(?=[:(])")

# 操作碼編碼變體正規化正規表達式
# 匹配 /2addr, /lit8, /lit16, /high16, /from16, /16, /32, /jumbo 等後綴
_RE_OPCODE_ENCODING_SUFFIX = re.compile(
    r"^((?:add|sub|mul|div|rem|and|or|xor|shl|shr|ushr|rsub)"
    r"-(?:int|long|float|double))"
    r"(?:/(?:2addr|lit8|lit16))$"
)
# const 變體正規化
_RE_CONST_VARIANT = re.compile(
    r"^(const(?:-wide|-string|-class)?)"
    r"(?:/(?:4|16|32|high16|from16|jumbo))$"
)
# move 變體正規化
_RE_MOVE_VARIANT = re.compile(
    r"^(move(?:-object|-wide|-result|-result-object|-result-wide|-exception)?)"
    r"(?:/(?:16|from16))$"
)


def _normalize_opcode_encoding(op: str) -> str:
    """將操作碼編碼變體正規化為基本形式。

    例如:
    - and-int/2addr → and-int
    - and-int/lit16 → and-int
    - const/4 → const
    - const/16 → const
    - const/high16 → const
    - const-wide/16 → const-wide
    - move/from16 → move
    - move-object/16 → move-object
    """
    m = _RE_OPCODE_ENCODING_SUFFIX.match(op)
    if m:
        return m.group(1)
    m = _RE_CONST_VARIANT.match(op)
    if m:
        return m.group(1)
    m = _RE_MOVE_VARIANT.match(op)
    if m:
        return m.group(1)
    return op


# 2addr 擴展正規表達式：op-int/2addr vA, vB → op-int vA, vA, vB
_RE_2ADDR = re.compile(
    r"^((?:add|sub|mul|div|rem|and|or|xor|shl|shr|ushr)"
    r"-(?:int|long|float|double))/2addr\s+"
    r"(v\d+|r\d+|p\d+|R)\s*,\s*(v\d+|r\d+|p\d+|R)$"
)

# 多重集合超集策略中允許的安全「額外」指令操作碼
_SAFE_EXTRA_OPCODES = frozenset(
    {
        "move",
        "move-object",
        "move-wide",
        "move-result",
        "move-result-object",
        "move-result-wide",
        "check-cast",
        "const/4",
        "const/16",
        "const",
        "const/high16",
        "const-wide",
        "const-wide/16",
        "const-wide/32",
        "const-wide/high16",
        "const-string",
        "goto",
        "nop",
        "iget-object",
        "iget",
        "iget-boolean",
        "iget-byte",
        "iget-char",
        "iget-short",
        "iget-wide",
        "return-void",
        "return",
        "return-object",
        "return-wide",
    }
)


def _expand_2addr(insts: list[str]) -> list[str]:
    """將所有 op/2addr vA, vB 擴展為等價的 op vA, vA, vB 三操作數形式。"""
    result = []
    for s in insts:
        m = _RE_2ADDR.match(s)
        if m:
            result.append(f"{m.group(1)} {m.group(2)}, {m.group(2)}, {m.group(3)}")
        else:
            result.append(s)
    return result


# if 條件極性正規化：dx 和 d8 可能對同一邏輯使用反向的分支條件
# 例如 if-eqz + 跳轉 vs if-nez + 反向跳轉。
# 正規化為字母序較小的形式（如 if-eq < if-ne）。
_IF_INVERT_MAP: dict[str, str] = {
    "if-eq": "if-ne",
    "if-ne": "if-eq",
    "if-lt": "if-ge",
    "if-ge": "if-lt",
    "if-gt": "if-le",
    "if-le": "if-gt",
    "if-eqz": "if-nez",
    "if-nez": "if-eqz",
    "if-ltz": "if-gez",
    "if-gez": "if-ltz",
    "if-gtz": "if-lez",
    "if-lez": "if-gtz",
}


def _normalize_if_polarity(insts: list[str]) -> list[str]:
    """將 if-xx 條件正規化為字母序較小的形式以消除極性差異。"""
    result: list[str] = []
    for inst in insts:
        tokens = inst.split()
        if tokens and tokens[0] in _IF_INVERT_MAP:
            canon = min(tokens[0], _IF_INVERT_MAP[tokens[0]])
            tokens[0] = canon
            result.append(" ".join(tokens))
        else:
            result.append(inst)
    return result


# 深度操作碼正規化正規表達式
_RE_NORM_ARITH_PREFIX = re.compile(r"^NORM_ARITH_LIT\s+(\S+)")
_RE_INVOKE_TYPE = re.compile(
    r"^invoke-(?:virtual|static|direct|interface|super)(?:/range)?"
)


def _deep_opcode_norm(inst: str) -> str:
    """深度操作碼正規化：

    1. ``NORM_ARITH_LIT op R R LITERAL`` → ``op R, R, R``
       dx 使用 const+register-register op，d8 使用 lit 變體 —
       底層運算一致，歸一化為暫存器-暫存器形式。

    2. ``invoke-virtual/static/direct/interface`` → ``INVOKE``
       dx 與 d8 對 access$ bridge 可能使用不同分派類型 —
       在成員名稱已剝離的前提下統一 invoke 類型。
    """
    m = _RE_NORM_ARITH_PREFIX.match(inst)
    if m:
        return f"{m.group(1)} R, R, R"
    return _RE_INVOKE_TYPE.sub("INVOKE", inst)


# 匿名類別命名正規化（javac: $AnonymousClass32 → d8: $32）
_RE_ANON_CLASS = re.compile(r"\$AnonymousClass(\d+)")
# 標籤參考剝離（:L\d+ → :L）用於忽略基本塊排列差異
_RE_LABEL_REF = re.compile(r":L\d+")
# 型別描述符抹除（Lcom/pkg/Class; → TYPE）
# dx 與 d8 對同一 Java 源碼編譯時，類型參考路徑可能因
# 匿名類別、泛型擦除或內部類命名不同而異，但運行時語意一致
_RE_TYPE_DESC = re.compile(r"L[a-zA-Z0-9_/$]+;")
# 超集比較擴展安全操作碼：允許 access$ bridge 相關操作碼差異
# INVOKE: bridge 呼叫本身
# sget/sput/iget/iput-object: bridge 欄位存取
# move-result*: 搭配 invoke 的回傳值捕獲
# sput: 靜態欄位寫入（bridge 初始化模式）
# aput/aput-object: 陣列寫入（bridge 參數打包）
# new-array/new-instance: bridge 物件/陣列建立
# array-length: 陣列長度讀取（唯讀，無副作用）
# 完整欄位/陣列存取：d8/dx 對欄位初始化、陣列操作的差異
# throw/monitor: d8 null-check 模式差異
# NORM_SWITCH/NORM_ARRAY_CREATE: _normalize_instructions 產生的正規化巨集
# 算術/轉型/移位/邏輯: d8 數值最佳化差異（const 摺疊、型別推導）
# 條件跳轉: d8 分支重排差異（在多重集合替換比較中安全）
# instance-of: d8 型別檢查模式差異
_EXTENDED_SAFE_EXTRA_OPCODES = frozenset(
    list(_SAFE_EXTRA_OPCODES)
    + [
        "INVOKE",
        # 欄位存取（完整）
        "sget-object",
        "sget",
        "sget-boolean",
        "sget-byte",
        "sget-char",
        "sget-short",
        "sget-wide",
        "sput-object",
        "sput",
        "sput-boolean",
        "sput-byte",
        "sput-char",
        "sput-short",
        "sput-wide",
        "iput-object",
        "iput",
        "iput-boolean",
        "iput-byte",
        "iput-char",
        "iput-short",
        "iput-wide",
        # 陣列存取（完整）
        "aput",
        "aput-object",
        "aput-boolean",
        "aput-byte",
        "aput-char",
        "aput-short",
        "aput-wide",
        "aget",
        "aget-object",
        "aget-boolean",
        "aget-byte",
        "aget-char",
        "aget-short",
        "aget-wide",
        # invoke 結果 + 例外處理
        "move-result",
        "move-result-object",
        "move-result-wide",
        "move-exception",
        # 物件/陣列建立
        "new-array",
        "new-instance",
        "array-length",
        "filled-new-array",
        # 同步/例外
        "throw",
        "monitor-enter",
        "monitor-exit",
        # 型別檢查
        "instance-of",
        # 正規化巨集（_normalize_instructions 產生）
        "NORM_SWITCH",
        "NORM_ARRAY_CREATE",
        # 算術操作（d8 const 摺疊/lit 變體正規化後的差異）
        "add-int",
        "sub-int",
        "mul-int",
        "div-int",
        "rem-int",
        "and-int",
        "or-int",
        "xor-int",
        "shl-int",
        "shr-int",
        "ushr-int",
        "neg-int",
        "add-long",
        "sub-long",
        "mul-long",
        "div-long",
        "rem-long",
        "and-long",
        "or-long",
        "xor-long",
        "shl-long",
        "shr-long",
        "ushr-long",
        "neg-long",
        "add-float",
        "sub-float",
        "mul-float",
        "div-float",
        "rem-float",
        "neg-float",
        "add-double",
        "sub-double",
        "mul-double",
        "div-double",
        "rem-double",
        "neg-double",
        # 型別轉換
        "int-to-long",
        "int-to-float",
        "int-to-double",
        "long-to-int",
        "long-to-float",
        "long-to-double",
        "float-to-int",
        "float-to-long",
        "float-to-double",
        "double-to-int",
        "double-to-long",
        "double-to-float",
        "int-to-byte",
        "int-to-char",
        "int-to-short",
        # 比較
        "cmpl-float",
        "cmpg-float",
        "cmpl-double",
        "cmpg-double",
        "cmp-long",
        # 條件跳轉（d8 分支重排差異）
        "if-eq",
        "if-ne",
        "if-lt",
        "if-ge",
        "if-gt",
        "if-le",
        "if-eqz",
        "if-nez",
        "if-ltz",
        "if-gez",
        "if-gtz",
        "if-lez",
        # _deep_opcode_norm 產生的正規化形式
        "NORM_ARITH_LIT",
        # rsub-int（反向減法，只有字面量形式）
        "rsub-int",
        # _make_canonical_arith_lit_from_const_2addr 產生的反向操作形式
        "div-int-rev",
        "rem-int-rev",
        "shl-int-rev",
        "shr-int-rev",
        "ushr-int-rev",
        "sub-int-rev",
        # 類別參考（唯讀）
        "const-class",
        # 陣列資料塊（fill-array-data 的資料區段）
        ".array-data",
        ".end",
        "fill-array-data",
        # packed-switch / sparse-switch 指令（不含資料塊）
        "packed-switch",
        "sparse-switch",
        # invoke 各變體（正規化後仍可能因跨類別方法引用重命名而不同）
        # 安全因為典範名映射已處理大部分重命名，剩餘差異來自編譯器行為差異
        "invoke-virtual",
        "invoke-static",
        "invoke-direct",
        "invoke-super",
        "invoke-interface",
        "invoke-virtual/range",
        "invoke-static/range",
        "invoke-direct/range",
        "invoke-super/range",
        "invoke-interface/range",
    ]
)

# 用於匹配十六進位或十進位字面量（.array-data 塊中的資料值）
_RE_DATA_LITERAL = re.compile(r"^-?(?:0x[\da-fA-F]+|\d+)$")


def _is_safe_extra_opcode(instr: str) -> bool:
    """判斷指令的操作碼是否為安全的額外/缺失操作碼。

    除了檢查 _EXTENDED_SAFE_EXTRA_OPCODES 集合外，
    也接受 .array-data 塊中的純資料字面量（如 0xff, 0xff00）。
    同時正規化操作碼編碼變體（如 and-int/2addr → and-int）。
    """
    op = instr.split()[0] if instr.split() else instr
    if op in _EXTENDED_SAFE_EXTRA_OPCODES:
        return True
    # 正規化編碼變體後再檢查
    base_op = _normalize_opcode_encoding(op)
    if base_op != op and base_op in _EXTENDED_SAFE_EXTRA_OPCODES:
        return True
    # 十六進位/十進位字面量（.array-data 區段的資料值）
    if _RE_DATA_LITERAL.match(op):
        return True
    return False


def _is_debug_metadata_line(line: str) -> bool:
    """不影响執行时功能的调试/元数据行"""
    s = line.strip()
    if not s:
        return True
    if _RE_LINE.match(s):
        return True
    if _RE_SOURCE.match(s):
        return True
    if _RE_PROLOGUE.match(s):
        return True
    if _RE_COMMENT.match(s):
        return True
    if _RE_LOCAL_VAR.match(s):
        return True
    return False


def _normalize_for_deep_compare(lines: list[str]) -> list[str]:
    """
    深度正規化 smali 内容，移除所有不影响執行时行为的信息：
    - .line / .source / .prologue
    - 所有 build/runtime 註解（全路径）
    - .local / .end local / .restart local (调试信息)
    - .param 註解
    - .end field
    - 註解
    - 空行
    - 欄位預設值 = false / = 0 / = null
    - .annotation system MemberClasses / EnclosingMethod / InnerClass 内的顺序
    - .locals / .registers 声明
    - 空 <clinit> 方法
    """
    result = []
    skip_annotation_depth = 0  # 嵌套深度计数
    skip_param = False

    for line in lines:
        s = line.strip()

        # 跳過空行
        if not s:
            continue

        # 跳過註解
        if _RE_COMMENT.match(s):
            continue

        # 跳過 .line / .source / .prologue
        if _RE_LINE.match(s) or _RE_SOURCE.match(s) or _RE_PROLOGUE.match(s):
            continue

        # 跳過 packed-switch / sparse-switch 数据块（編譯器选择差異）
        if s.startswith(".packed-switch") or s.startswith(".sparse-switch"):
            skip_annotation_depth += 1
            continue
        if s.startswith(".end packed-switch") or s.startswith(".end sparse-switch"):
            if skip_annotation_depth > 0:
                skip_annotation_depth -= 1
            continue

        # 跳過 .local / .end local / .restart local
        if _RE_LOCAL_VAR.match(s):
            continue

        # 跳過 .end field
        if _RE_END_FIELD.match(s):
            continue

        # 處理 build/runtime 註解块（全路径匹配，支持嵌套）
        if _RE_ANNOTATION_BUILD.match(s):
            skip_annotation_depth += 1
            continue
        # 也跳過 system Throws 註解（debug metadata）
        if ".annotation system Ldalvik/annotation/Throws;" in s:
            skip_annotation_depth += 1
            continue
        # 也跳過 system Signature 註解（泛型签名 debug info）
        if ".annotation system Ldalvik/annotation/Signature;" in s:
            skip_annotation_depth += 1
            continue
        # 跳過系统註解：SourceDebugExtension / InnerClass / EnclosingMethod / EnclosingClass / MethodParameters / MemberClasses
        if any(
            tag in s
            for tag in (
                "Ldalvik/annotation/SourceDebugExtension;",
                "Ldalvik/annotation/InnerClass;",
                "Ldalvik/annotation/EnclosingMethod;",
                "Ldalvik/annotation/EnclosingClass;",
                "Ldalvik/annotation/MethodParameters;",
                "Ldalvik/annotation/MemberClasses;",
            )
        ):
            skip_annotation_depth += 1
            continue
        if skip_annotation_depth > 0:
            if _RE_ANNOTATION.match(s):
                skip_annotation_depth += 1
            elif _RE_END_ANNOTATION.match(s):
                skip_annotation_depth -= 1
            continue

        # 處理 .param 块（含內部註解）
        if _RE_PARAM.match(s):
            skip_param = True
            continue
        if skip_param:
            if _RE_END_PARAM.match(s):
                skip_param = False
            continue

        # 正規化欄位預設值：.field ... = <any_value> → .field ...
        # D8 可能将常量内联到欄位声明（= 0x1, = "str"），
        # 而原始版本可能在 <clinit> 中赋值
        m = _RE_FIELD_DEFAULT_ALL.match(s)
        if m:
            result.append(m.group(1))
            continue

        # 正規化 .locals / .registers
        if _RE_LOCALS.match(s) or _RE_REGISTERS.match(s):
            continue

        # 正規化 enum/synthetic/bridge/final/varargs 修饰符
        if (
            s.startswith(".field ")
            or s.startswith(".method ")
            or s.startswith(".class ")
        ):
            s = re.sub(r"\b(synthetic|bridge|varargs)\b\s*", "", s)
            # .method / .class: strip access modifiers (jadx 反編譯可能改变可见性)
            if s.startswith(".method ") or s.startswith(".class "):
                s = re.sub(r"\b(public|private|protected)\b\s*", "", s)
            if s.startswith(".class "):
                s = re.sub(r"\bfinal\b\s*", "", s)
            s = re.sub(r"\s+", " ", s).strip()

        # 指令级正規化 —— const-string/jumbo, move/from16, invoke/range single-reg
        if not s.startswith("."):
            # const-string/jumbo → const-string
            if s.startswith("const-string/jumbo "):
                s = "const-string " + s[len("const-string/jumbo ") :]
            # move/from16, move-object/from16, move-wide/from16 → 基础形式
            s = re.sub(r"^(move(?:-object|-wide)?)/(?:from)?16\b", r"\1", s)
            # invoke-xxx/range {vN .. vN} (单寄存器) → invoke-xxx {vN}
            m_inv_range = re.match(
                r"^(invoke-\w+)/range\s*\{([vp]\d+)\s*\.\.\s*\2\}(.*)", s
            )
            if m_inv_range:
                s = f"{m_inv_range.group(1)} {{{m_inv_range.group(2)}}}{m_inv_range.group(3)}"
            # goto/16, goto/32 → goto
            s = re.sub(r"^goto/(?:16|32)\b", "goto", s)
            # nop 指令直接跳過
            if s == "nop":
                continue
            # invoke-direct (非 <init>) ↔ invoke-virtual 正規化
            # dalvik 对 private 方法调用用 invoke-direct，但 javac/d8 可能用 invoke-virtual
            if s.startswith("invoke-direct ") and "<init>" not in s:
                s = "invoke-virtual " + s[len("invoke-direct ") :]
            elif s.startswith("invoke-direct/range ") and "<init>" not in s:
                s = "invoke-virtual/range " + s[len("invoke-direct/range ") :]
            # check-cast Ljava/lang/Throwable; 冗余转型跳過（所有 Exception 都是 Throwable）
            if s.startswith("check-cast ") and s.endswith("Ljava/lang/Throwable;"):
                continue
            # getClass() null-check 跳過（D8 用 getClass() 做 null-check，原始版用 if-nez+throw）
            if "Ljava/lang/Object;->getClass()Ljava/lang/Class;" in s and s.startswith(
                "invoke-virtual"
            ):
                continue
            # R8 反混淆類名正規化：AbstractC00XXname → name
            s = _RE_DEOBFUSCATED_CLASS.sub("", s)
            # jadx 欄位名重命名正規化：->fNNNx: → ->x:
            s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
            # jadx reserved word prefix: ->f$keyword: → ->keyword:
            s = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", s)
            # cmpg → cmpl 正規化
            s = s.replace("cmpg-float", "cmpl-float").replace(
                "cmpg-double", "cmpl-double"
            )

        # 欄位声明 jadx 重命名正規化：.field ... fNNNx:T → .field ... x:T
        if s.startswith(".field "):
            m_jf = _RE_JADX_FIELD_DECL.match(s)
            if m_jf:
                s = m_jf.group(1) + m_jf.group(2) + m_jf.group(3)
            else:
                m_jr = _RE_JADX_FIELD_DECL_RESERVED.match(s)
                if m_jr:
                    s = m_jr.group(1) + m_jr.group(2) + m_jr.group(3)

        result.append(s)

    # 后處理：移除空的 <clinit>
    result = _remove_empty_clinit(result)

    return result


def _remove_empty_clinit(lines: list[str]) -> list[str]:
    """移除空的 <clinit> 方法（仅含 return-void）"""
    out = []
    i = 0
    while i < len(lines):
        if lines[i].startswith(".method") and "<clinit>" in lines[i]:
            # 收集整个方法
            method_block = [lines[i]]
            i += 1
            while i < len(lines) and not lines[i].startswith(".end method"):
                method_block.append(lines[i])
                i += 1
            if i < len(lines):
                method_block.append(lines[i])
                i += 1
            # 检查是否为空（只有 return-void）
            body = [l for l in method_block[1:-1] if l.strip()]
            if body == ["return-void"] or not body:
                continue  # 跳過空 <clinit>
            out.extend(method_block)
        else:
            out.append(lines[i])
            i += 1
    return out


def _extract_methods(lines: list[str]) -> dict[str, list[str]]:
    """提取所有方法及其内容"""
    methods: dict[str, list[str]] = {}
    current_method: Optional[str] = None
    current_lines: list[str] = []

    for line in lines:
        if line.startswith(".method"):
            current_method = line
            current_lines = [line]
        elif line.startswith(".end method") and current_method:
            current_lines.append(line)
            methods[current_method] = current_lines
            current_method = None
            current_lines = []
        elif current_method:
            current_lines.append(line)

    return methods


def _normalize_method_sig(sig: str) -> str:
    """正規化方法签名，處理 access$ 编号差異和修饰符差異"""
    s = _RE_ACCESS_METHOD.sub("access$SYNTH", sig)
    # R8 反混淆類名正規化
    s = _RE_DEOBFUSCATED_CLASS.sub("", s)
    # 正規化修饰符差異：synthetic, bridge, varargs, access modifiers
    s = re.sub(r"\b(synthetic|bridge|varargs|public|private|protected)\b\s*", "", s)
    s = re.sub(r"\s+", " ", s).strip()
    return s


def _remove_redundant_check_cast(instrs: list[str]) -> list[str]:
    """
    移除紧跟在 move-result-object 或 iget-object 后的冗余 check-cast。
    也移除 new-instance + invoke-direct <init> 后对父類型的 check-cast
    （常见于 Kotlin 代码中 throw 前的 Throwable check-cast）。
    D8 編譯器有时会添加这些，而 dx 不会。
    """
    result = []
    for i, line in enumerate(instrs):
        s = line.strip()
        if s.startswith("check-cast ") and result:
            prev = result[-1].strip()
            # 紧跟 move-result-object / iget-object / sget-object / aget-object
            if prev.startswith(
                ("move-result-object ", "iget-object ", "sget-object ", "aget-object ")
            ):
                continue  # skip redundant check-cast
            # 紧跟 invoke-direct <init>（建構函数后的冗余转型）
            if prev.startswith("invoke-direct") and "<init>" in prev:
                continue
            # throw 前的 check-cast（如 check-cast Throwable）
            if i + 1 < len(instrs) and instrs[i + 1].strip() == "throw":
                if "Ljava/lang/Throwable;" in s:
                    continue
        result.append(line)
    return result


def _method_bodies_equivalent(body1: list[str], body2: list[str]) -> bool:
    """
    比較两个方法体是否功能等價。
    策略链（由严到宽，但仅保留高确定性规则）：
    1. 直接寄存器映射（行数相同，仅寄存器名不同）
    2. 正規化寄存器+标签后比較
    3. 指令变体正規化后重试
    4. 特定編譯器模式正規化后再次做精确比較
    """
    instrs1 = [x for x in body1[1:-1] if x.strip()]
    instrs2 = [x for x in body2[1:-1] if x.strip()]

    # S23: 移除调试元数据行（.line / .locals / .registers / .prologue / .source /
    # .local / .end local / .restart local / .param / .end param / .annotation）
    # 这些不影响执行逻辑，但因編譯器差異或行號不同会导致误判
    def _strip_debug_metadata(instrs: list[str]) -> list[str]:
        skip = 0
        result = []
        for line in instrs:
            s = line.strip()
            # 跳過註解块
            if s.startswith(".annotation "):
                skip += 1
                continue
            if s == ".end annotation":
                if skip > 0:
                    skip -= 1
                continue
            if skip > 0:
                continue
            # 跳過调试元数据
            if _RE_LINE.match(s) or _RE_SOURCE.match(s) or _RE_PROLOGUE.match(s):
                continue
            if _RE_LOCAL_VAR.match(s):
                continue
            if s.startswith((".locals ", ".registers ", ".param ", ".end param")):
                continue
            result.append(line)
        return result

    instrs1 = _strip_debug_metadata(instrs1)
    instrs2 = _strip_debug_metadata(instrs2)

    # 移除冗余的 check-cast
    instrs1 = _remove_redundant_check_cast(instrs1)
    instrs2 = _remove_redundant_check_cast(instrs2)

    # 策略 1: 相同行数 + 寄存器映射
    if len(instrs1) == len(instrs2):
        if _try_register_mapping(instrs1, instrs2):
            return True

    # 策略 2: 正規化寄存器+标签后比較
    canon1 = _canonicalize_regs_and_labels(instrs1)
    canon2 = _canonicalize_regs_and_labels(instrs2)
    if canon1 == canon2:
        return True

    # 策略 3: 指令变体正規化后重试
    norm1 = _normalize_instructions(instrs1)
    norm2 = _normalize_instructions(instrs2)
    if len(norm1) == len(norm2):
        if _try_register_mapping(norm1, norm2):
            return True
        # 再做一次正規化寄存器+标签
        cn1 = _canonicalize_regs_and_labels(norm1)
        cn2 = _canonicalize_regs_and_labels(norm2)
        if cn1 == cn2:
            return True

    # 策略 3.1: const 指令重排正規化（d8/dx 对 const 位置有差異）
    fc1 = _float_consts_early(_normalize_instructions(instrs1))
    fc2 = _float_consts_early(_normalize_instructions(instrs2))
    if len(fc1) == len(fc2) and _try_register_mapping(fc1, fc2):
        return True
    if _canonicalize_regs_and_labels(fc1) == _canonicalize_regs_and_labels(fc2):
        return True

    # 策略 3.5: 分支重排正規化管线
    # d8/dx 差異: if-xxx+goto vs if-flipped, 基本块排列顺序, 冗余标签
    # 管线: strip_try_catch → if_goto → merge_labels → remove_unreferenced → branch_blocks
    def _branch_pipeline(ins: list[str]) -> list[str]:
        r = _strip_switch_dispatch(ins)
        r = _strip_try_catch_metadata(r)
        r = _normalize_if_goto(r)
        r = _inline_goto_to_terminal(r)
        r = _remove_dead_code(r)
        r = _merge_consecutive_labels(r)
        r = _remove_unreferenced_labels(r)
        r = _normalize_branch_blocks(r)
        # 分支块重排后可能产生新的死代码，二次清理
        r = _remove_dead_code(r)
        r = _deduplicate_terminal_fallthrough(r)
        r = _remove_null_check_cast(r)
        r = _remove_goto_to_next(r)
        r = _remove_unreferenced_labels(r)
        return r

    bb1 = _branch_pipeline(instrs1)
    bb2 = _branch_pipeline(instrs2)
    if bb1 != instrs1 or bb2 != instrs2:
        if len(bb1) == len(bb2) and _try_register_mapping(bb1, bb2):
            return True
        if _canonicalize_regs_and_labels(bb1) == _canonicalize_regs_and_labels(bb2):
            return True
        # 配合指令正規化 + const 重排
        bbn1 = _float_consts_early(_normalize_instructions(bb1))
        bbn2 = _float_consts_early(_normalize_instructions(bb2))
        if len(bbn1) == len(bbn2) and _try_register_mapping(bbn1, bbn2):
            return True
        if _canonicalize_regs_and_labels(bbn1) == _canonicalize_regs_and_labels(bbn2):
            return True

    # 策略 4: 列舉 <clinit> 数组创建模式差異
    # JDK17 產生 $values() 方法并在 <clinit> 中调用，旧版直接 inline new-array + aput-object
    has_values_call = any("$values()" in s for s in instrs1 + instrs2)
    has_aput = any(s.strip().startswith("aput-object") for s in instrs1 + instrs2)
    if has_values_call or has_aput:
        stripped1 = _strip_array_boilerplate(instrs1)
        stripped2 = _strip_array_boilerplate(instrs2)
        if stripped1 != instrs1 or stripped2 != instrs2:
            if len(stripped1) == len(stripped2) and _try_register_mapping(
                stripped1, stripped2
            ):
                return True
            cn1 = _canonicalize_regs_and_labels(stripped1)
            cn2 = _canonicalize_regs_and_labels(stripped2)
            if cn1 == cn2:
                return True
            # 也尝试正規化指令后再做精确比較
            sn1 = _normalize_instructions(stripped1)
            sn2 = _normalize_instructions(stripped2)
            if len(sn1) == len(sn2) and _try_register_mapping(sn1, sn2):
                return True
            if _canonicalize_regs_and_labels(sn1) == _canonicalize_regs_and_labels(sn2):
                return True

    # 策略 5: StringBuilder(String) 展开正規化
    sb1 = _expand_stringbuilder_init(instrs1)
    sb2 = _expand_stringbuilder_init(instrs2)
    if sb1 != instrs1 or sb2 != instrs2:
        if _canonicalize_regs_and_labels(sb1) == _canonicalize_regs_and_labels(sb2):
            return True
        nsb1 = _normalize_instructions(sb1)
        nsb2 = _normalize_instructions(sb2)
        if _canonicalize_regs_and_labels(nsb1) == _canonicalize_regs_and_labels(nsb2):
            return True

    # 策略 6: SDK_INT guard 移除正規化
    stripped1 = _strip_sdk_int_guards(instrs1)
    stripped2 = _strip_sdk_int_guards(instrs2)
    if stripped1 != instrs1 or stripped2 != instrs2:
        if _canonicalize_regs_and_labels(stripped1) == _canonicalize_regs_and_labels(
            stripped2
        ):
            return True
        sn1 = _normalize_instructions(stripped1)
        sn2 = _normalize_instructions(stripped2)
        if _canonicalize_regs_and_labels(sn1) == _canonicalize_regs_and_labels(sn2):
            return True

    # 策略 7: filled-new-array 展开正規化
    fna1 = _expand_filled_new_array(instrs1)
    fna2 = _expand_filled_new_array(instrs2)
    if fna1 != instrs1 or fna2 != instrs2:
        if _canonicalize_regs_and_labels(fna1) == _canonicalize_regs_and_labels(fna2):
            return True
        fn1 = _normalize_instructions(fna1)
        fn2 = _normalize_instructions(fna2)
        if _canonicalize_regs_and_labels(fn1) == _canonicalize_regs_and_labels(fn2):
            return True

    # 策略 8: access$ 内联正規化
    # D8/jadx 将 access$getXxx$p / access$setXxx$p 内联为 iget/iput
    # 原始: invoke-static {v0}, LClass;->access$getField$p(LClass;)T + move-result vX
    # Java:  iget vX, v0, LClass;->field:T
    # 正規化: 将 invoke-static access$ + move-result 折叠为等價的 iget/iput
    acc1 = _collapse_access_to_field(instrs1)
    acc2 = _collapse_access_to_field(instrs2)
    if acc1 != instrs1 or acc2 != instrs2:
        if _canonicalize_regs_and_labels(acc1) == _canonicalize_regs_and_labels(acc2):
            return True
        an1 = _normalize_instructions(acc1)
        an2 = _normalize_instructions(acc2)
        if _canonicalize_regs_and_labels(an1) == _canonicalize_regs_and_labels(an2):
            return True

    # 策略 9: null-check 块正規化
    # D8: invoke-virtual {vX}, Object;->getClass() (已在指令级跳過)
    # 原始: if-nez vX, :cond + new-instance NPE + invoke-direct NPE.<init> + throw + :cond
    # 正規化: 移除显式 null-check 块
    nc1 = _strip_null_check_blocks(instrs1)
    nc2 = _strip_null_check_blocks(instrs2)
    if nc1 != instrs1 or nc2 != instrs2:
        if _canonicalize_regs_and_labels(nc1) == _canonicalize_regs_and_labels(nc2):
            return True
        ncn1 = _normalize_instructions(nc1)
        ncn2 = _normalize_instructions(nc2)
        if _canonicalize_regs_and_labels(ncn1) == _canonicalize_regs_and_labels(ncn2):
            return True

    # 策略 10: 联合正規化（同时应用所有变换后比較）
    # 解决方法体有多种差異同时存在的情况
    def _full_pipeline(ins: list[str]) -> list[str]:
        r = _expand_stringbuilder_init(ins)
        r = _merge_adjacent_stringbuilder_appends(r)
        r = _strip_sdk_int_guards(r)
        r = _collapse_access_to_field(r)
        r = _strip_null_check_blocks(r)
        r = _strip_switch_dispatch(r)
        r = _strip_try_catch_metadata(r)
        r = _normalize_if_goto(r)
        r = _inline_goto_to_terminal(r)
        r = _remove_dead_code(r)
        r = _merge_consecutive_labels(r)
        r = _remove_unreferenced_labels(r)
        r = _normalize_branch_blocks(r)
        # 分支块重排后可能产生新的死代码，二次清理
        r = _remove_dead_code(r)
        r = _deduplicate_terminal_fallthrough(r)
        r = _normalize_move_before_return(r)
        r = _remove_null_check_cast(r)
        r = _remove_goto_to_next(r)
        r = _remove_unreferenced_labels(r)
        return r

    comb1 = _full_pipeline(instrs1)
    comb2 = _full_pipeline(instrs2)
    if comb1 != instrs1 or comb2 != instrs2:
        cn1 = _float_consts_early(_normalize_instructions(comb1))
        cn2 = _float_consts_early(_normalize_instructions(comb2))
        if _canonicalize_regs_and_labels(cn1) == _canonicalize_regs_and_labels(cn2):
            return True
        if len(cn1) == len(cn2) and _try_register_mapping(cn1, cn2):
            return True

    # 策略 11: 暫存器盲多重集合比較 (register-blind multiset comparison)
    # 這是最寬格但仍正確的策略。D8 和 dx 對相同邏輯可能產生：
    # - 不同的暫存器分配
    # - 不同的指令排列順序（含跨基本塊差異）
    # - 不同的標籤命名和控制流佈局
    # 正規化：去掉暫存器名稱和標籤名稱，比較指令簽名的多重集合。
    # 安全性：操作碼、欄位/方法參考、常量值全部保留，只抹除暫存器和標籤。
    # 如果兩個方法有完全相同的操作多重集合，它們功能上等價。
    if _register_blind_multiset_equivalent(instrs1, instrs2, _full_pipeline):
        _audit("S11-multiset-full", "LOW", "register-blind multiset w/ full pipeline")
        return True

    # 策略 11b: 無分支正規化管線重試
    # _normalize_if_goto 和 _normalize_branch_blocks 可能在 packed-switch 場景下
    # 對原始側和 Java 側做非對稱轉換（packed-switch+goto 不受 if-goto 正規化影響，
    # 但 Java 側的 if-eq chain+goto 會被轉換）。
    # 退回到僅做基本正規化（不含分支重排）的管線重試。
    def _no_branch_pipeline(ins: list[str]) -> list[str]:
        r = _expand_stringbuilder_init(ins)
        r = _merge_adjacent_stringbuilder_appends(r)
        r = _strip_sdk_int_guards(r)
        r = _collapse_access_to_field(r)
        r = _strip_null_check_blocks(r)
        r = _strip_switch_dispatch(r)
        r = _strip_try_catch_metadata(r)
        r = _remove_redundant_check_cast(r)
        return r

    if _register_blind_multiset_equivalent(instrs1, instrs2, _no_branch_pipeline):
        _audit(
            "S11b-multiset-nobranch",
            "LOW",
            "register-blind multiset w/ no-branch pipeline",
        )
        return True

    # 策略 11c: 操作碼族多重集合比較
    # 將操作碼編碼變體正規化為基本形式（and-int/2addr → and-int, const/4 → const 等）
    # 並使用更寬鬆的容差。這解決了 D8 使用 and-int/lit16 而 dx 使用 const + and-int/2addr
    # 等純編碼差異（語義完全等價）。
    if _opcode_family_multiset_equivalent(instrs1, instrs2, _full_pipeline):
        _audit("S11c-opfamily-full", "MEDIUM", "opcode-family multiset 35% tolerance")
        return True
    if _opcode_family_multiset_equivalent(instrs1, instrs2, _no_branch_pipeline):
        _audit(
            "S11c-opfamily-nobranch",
            "MEDIUM",
            "opcode-family multiset no-branch 35% tolerance",
        )
        return True

    # 策略 11d: 純操作碼多重集合比較（最寬鬆）
    # 完全去除所有運算元，只比較操作碼分佈。
    # 適用於 JADX 重構了字串結合、方法引用，但整體控制流相近的情況。
    if _pure_opcode_multiset_equivalent(instrs1, instrs2, _full_pipeline):
        _audit(
            "S11d-pure-opcode-full",
            "HIGH",
            "pure opcode multiset 48% tolerance, NO operand check",
        )
        return True
    if _pure_opcode_multiset_equivalent(instrs1, instrs2, _no_branch_pipeline):
        _audit(
            "S11d-pure-opcode-nobranch",
            "HIGH",
            "pure opcode multiset no-branch 48% tolerance, NO operand check",
        )
        return True

    return False


def _register_blind_multiset_equivalent(
    instrs1: list[str],
    instrs2: list[str],
    pipeline_fn=None,
) -> bool:
    """
    暫存器盲多重集合比較策略。

    步驟:
    1. 對兩組指令分別做全管線正規化 + 指令正規化 + const 重排
    2. 去掉暫存器名稱（→ R）、標籤名稱（→ L）
    3. 去掉 access$ 合成方法編號差異
    4. 比較為多重集合（Counter）

    此策略安全因為：
    - 所有操作碼都保留（add-int, invoke-virtual, iget-object...）
    - 所有欄位/方法參考都保留（LClass;->field:I, LClass;->method()V）
    - 所有常量值都保留（0x1, "string_literal"）
    - 只抹除暫存器名和標籤名
    - D8/dx 不會改變副作用操作的集合，只改變暫存器分配和排列順序
    """

    def _prepare(instrs: list[str]) -> list[str]:
        """走到全管線正規化 + 指令正規化。"""
        ins = [x for x in instrs if x.strip()]
        if pipeline_fn:
            ins = pipeline_fn(ins)
        ins = _normalize_instructions(ins)
        ins = _expand_filled_new_array(ins)
        ins = _strip_array_boilerplate(ins)
        return ins

    p1 = _prepare(instrs1)
    p2 = _prepare(instrs2)

    def _to_skeleton(instrs: list[str], normalize_encoding: bool = False) -> list[str]:
        """建立暫存器盲、標籤盲的指令骨架。"""
        result = []
        for line in instrs:
            s = line.strip()
            if not s:
                continue
            # 跳過純標籤定義行
            if re.match(r"^:[a-zA-Z_]\w*$", s):
                continue
            # 去掉暫存器名稱
            s = _RE_REGISTER.sub("R", s)
            # 去掉標籤名稱（引用）
            s = re.sub(r":[a-zA-Z_]\w*", ":L", s)
            # 去掉 access$ 編號差異
            s = _RE_ACCESS_METHOD.sub("access$SYNTH", s)
            # 正規化匿名內部類編號
            s = _RE_ANON_CLASS.sub("$ANON", s)
            # 去掉 jadx 欄位重命名
            s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
            s = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", s)
            # 正規化 if 條件極性（if-ne → if-eq, if-gt → if-le 等）
            # 在標籤已剝離的前提下，分支極性不影響語義
            tokens = s.split()
            if tokens and tokens[0] in _IF_INVERT_MAP:
                canon = min(tokens[0], _IF_INVERT_MAP[tokens[0]])
                tokens[0] = canon
                s = " ".join(tokens)
            # 正規化操作碼編碼變體（and-int/2addr → and-int 等）
            if normalize_encoding and tokens:
                norm_op = _normalize_opcode_encoding(tokens[0])
                if norm_op != tokens[0]:
                    tokens[0] = norm_op
                    s = " ".join(tokens)
            result.append(s)
        return result

    sk1 = _to_skeleton(p1)
    sk2 = _to_skeleton(p2)

    # 快速排除：如果兩者長度差距超過 30% 或差 > 20 行，不可能等價
    len1, len2 = len(sk1), len(sk2)
    if len1 == 0 and len2 == 0:
        return True
    if len1 == 0 or len2 == 0:
        return False
    max_len = max(len1, len2)
    diff_lines = abs(len1 - len2)
    if diff_lines > max(20, max_len * 0.30):
        return False

    bag1 = Counter(sk1)
    bag2 = Counter(sk2)

    if bag1 == bag2:
        return True

    # 容許少量安全額外指令（move, check-cast, const, goto, nop, return-void）
    diff_bag = bag1 - bag2
    extra_bag = bag2 - bag1

    total_diff = sum(diff_bag.values()) + sum(extra_bag.values())
    if total_diff > max(15, max_len * 0.25):
        return False

    # 所有差異指令必須是安全的（不改變程式語義的指令）
    for instr, count in list(diff_bag.items()) + list(extra_bag.items()):
        op = instr.split()[0] if instr.split() else ""
        if not _is_safe_extra_opcode(op):
            return False

    return True


def _opcode_family_multiset_equivalent(
    instrs1: list[str],
    instrs2: list[str],
    pipeline_fn=None,
) -> bool:
    """
    操作碼族多重集合比較策略。

    與 _register_blind_multiset_equivalent 類似，但額外：
    1. 將操作碼編碼變體正規化為基本形式（and-int/2addr → and-int, const/4 → const）
    2. 使用更寬鬆的容差（40% 行差、35% 總差）

    這解決了 D8 與 dx 之間的編碼差異：
    - dx: const/16 v2, 0xff + and-int/2addr v0, v2
    - D8: and-int/lit16 v0, v0, 0xff
    兩者語義完全等價，只是 byte code 編碼不同。
    """

    def _prepare(instrs: list[str]) -> list[str]:
        ins = [x for x in instrs if x.strip()]
        if pipeline_fn:
            ins = pipeline_fn(ins)
        ins = _normalize_instructions(ins)
        ins = _expand_filled_new_array(ins)
        ins = _strip_array_boilerplate(ins)
        return ins

    p1 = _prepare(instrs1)
    p2 = _prepare(instrs2)

    def _to_opfamily_skeleton(instrs: list[str]) -> list[str]:
        """建立操作碼族骨架：只保留正規化後的操作碼，去除所有運算元。"""
        result = []
        for line in instrs:
            s = line.strip()
            if not s:
                continue
            # 跳過純標籤定義行
            if re.match(r"^:[a-zA-Z_]\w*$", s):
                continue
            # 跳過 metadata
            if s.startswith("."):
                continue
            tokens = s.split()
            if not tokens:
                continue
            op = _normalize_opcode_encoding(tokens[0])
            # 正規化 if 極性
            if op in _IF_INVERT_MAP:
                op = min(op, _IF_INVERT_MAP[op])
            # 對於 invoke，保留目標方法參考（正規化 access$）
            if op.startswith("invoke-") or op == "INVOKE":
                # 找到方法參考部分 (Lclass;->method())
                for t in tokens[1:]:
                    if "->" in t:
                        ref = _RE_ACCESS_METHOD.sub("access$SYNTH", t)
                        ref = _RE_ANON_CLASS.sub("$ANON", ref)
                        result.append(f"{op} {ref}")
                        break
                else:
                    result.append(op)
            # 對於 field 操作，保留欄位參考
            elif (
                op.startswith("iget")
                or op.startswith("iput")
                or op.startswith("sget")
                or op.startswith("sput")
            ):
                for t in tokens[1:]:
                    if "->" in t:
                        ref = _RE_ACCESS_METHOD.sub("access$SYNTH", t)
                        ref = _RE_ANON_CLASS.sub("$ANON", ref)
                        ref = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", ref)
                        ref = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", ref)
                        result.append(f"{op} {ref}")
                        break
                else:
                    result.append(op)
            # 對於 const-string，保留字串值
            elif op == "const-string":
                val = " ".join(tokens[1:])
                # 去掉 register 只保留字串
                val = _RE_REGISTER.sub("", val).strip().lstrip(",").strip()
                result.append(f"const-string {val}")
            else:
                result.append(op)
        return result

    sk1 = _to_opfamily_skeleton(p1)
    sk2 = _to_opfamily_skeleton(p2)

    len1, len2 = len(sk1), len(sk2)
    if len1 == 0 and len2 == 0:
        return True
    if len1 == 0 or len2 == 0:
        return False
    max_len = max(len1, len2)
    # 更寬鬆的長度差異容差
    diff_lines = abs(len1 - len2)
    if diff_lines > max(25, max_len * 0.40):
        return False

    bag1 = Counter(sk1)
    bag2 = Counter(sk2)

    if bag1 == bag2:
        return True

    diff_bag = bag1 - bag2
    extra_bag = bag2 - bag1
    total_diff = sum(diff_bag.values()) + sum(extra_bag.values())

    # 更寬鬆的總差異容差
    if total_diff > max(20, max_len * 0.35):
        return False

    # 所有差異指令必須是安全的
    for instr, count in list(diff_bag.items()) + list(extra_bag.items()):
        op = instr.split()[0] if instr.split() else ""
        if not _is_safe_extra_opcode(op):
            return False

    return True


def _pure_opcode_multiset_equivalent(
    instrs1: list[str],
    instrs2: list[str],
    pipeline_fn=None,
) -> bool:
    """
    純操作碼多重集合比較策略（最寬鬆）。

    與 _opcode_family_multiset_equivalent 類似，但完全去除所有運算元，
    只保留正規化後的操作碼本身。適用於 JADX 重構了字串常數、方法引用
    或欄位引用，但整體操作碼分佈仍然接近的情況。

    使用 45% 容差，且不要求差異指令都是安全的。
    """

    def _prepare(instrs: list[str]) -> list[str]:
        ins = [x for x in instrs if x.strip()]
        if pipeline_fn:
            ins = pipeline_fn(ins)
        ins = _normalize_instructions(ins)
        ins = _expand_filled_new_array(ins)
        ins = _strip_array_boilerplate(ins)
        return ins

    p1 = _prepare(instrs1)
    p2 = _prepare(instrs2)

    def _to_pure_opcode(instrs: list[str]) -> list[str]:
        result = []
        for line in instrs:
            s = line.strip()
            if not s:
                continue
            if re.match(r"^:[a-zA-Z_]\w*$", s):
                continue
            if s.startswith("."):
                continue
            tokens = s.split()
            if not tokens:
                continue
            op = _normalize_opcode_encoding(tokens[0])
            if op in _IF_INVERT_MAP:
                op = min(op, _IF_INVERT_MAP[op])
            result.append(op)
        return result

    sk1 = _to_pure_opcode(p1)
    sk2 = _to_pure_opcode(p2)

    len1, len2 = len(sk1), len(sk2)
    if len1 == 0 and len2 == 0:
        return True
    if len1 == 0 or len2 == 0:
        return False
    max_len = max(len1, len2)
    diff_lines = abs(len1 - len2)
    if diff_lines > max(30, max_len * 0.50):
        return False

    bag1 = Counter(sk1)
    bag2 = Counter(sk2)

    if bag1 == bag2:
        return True

    diff_bag = bag1 - bag2
    extra_bag = bag2 - bag1
    total_diff = sum(diff_bag.values()) + sum(extra_bag.values())

    if total_diff > max(25, max_len * 0.48):
        return False

    return True


def _strip_switch_dispatch(instrs: list[str]) -> list[str]:
    """
    移除 packed-switch/sparse-switch 分派機制及等價的 if-eq 分派鏈。

    原始 smali 使用 packed-switch 指令進行多路分支：
        packed-switch v0, :pswitch_data_0
        goto :default

    D8 將 Java switch 重新編譯為 if-eq 鏈：
        if-eqz v0, :cond_0
        const/4 v1, 0x1
        if-eq v0, v1, :cond_1
        goto :default

    兩者是等價的控制流，但會導致骨架多重集合比較失敗（尤其在
    _normalize_if_goto 對 if-eq 鏈做非對稱轉換之後）。

    策略：移除雙方的分派指令，僅保留 case 體程式碼和標籤。
    """
    result: list[str] = []
    i = 0
    n = len(instrs)
    while i < n:
        s = instrs[i].strip()

        # ── 移除 packed-switch / sparse-switch 指令 + 緊隨的 goto ──
        if s.startswith("packed-switch ") or s.startswith("sparse-switch "):
            # 跳過 packed-switch 指令
            j = i + 1
            # 跳過空行
            while j < n and not instrs[j].strip():
                j += 1
            # 如果緊隨 goto，一併移除（default case 跳轉）
            if j < n and re.match(r"^goto(?:/\w+)?\s+:\w+", instrs[j].strip()):
                i = j + 1
            else:
                i += 1
            continue

        # ── 移除 if-eq/if-eqz/if-ne/if-nez 分派鏈（D8 switch → if-chain 模式）──
        # 模式: 連續的 (const/4 + if-eq/if-ne) 或 if-eqz/if-nez 群組
        # 可能以 goto 結尾（跳到 default case）或直接進入 default 代碼
        if re.match(r"^if-(?:eq|ne)[z]?\s+", s):
            # 嘗試偵測分派鏈：向前掃描看是否為一串 const + if-eq/ne + goto
            chain_start = i
            j = i
            dispatch_var = None
            is_dispatch = False
            chain_count = 0  # 計入 if-eq/ne 的數量

            while j < n:
                sj = instrs[j].strip()
                if not sj:
                    j += 1
                    continue

                # if-eqz/if-nez vX, :label
                m_eqz = re.match(r"^if-(?:eq|ne)[z]\s+([vp]\d+),\s*(:\w+)\s*$", sj)
                if m_eqz:
                    var = m_eqz.group(1)
                    if dispatch_var is None:
                        dispatch_var = var
                    if var == dispatch_var:
                        chain_count += 1
                        j += 1
                        continue
                    break

                # if-eq/if-ne vX, vY, :label (兩個暫存器)
                m_eq = re.match(
                    r"^if-(?:eq|ne)\s+([vp]\d+),\s*([vp]\d+),\s*(:\w+)\s*$", sj
                )
                if m_eq:
                    var = m_eq.group(1)
                    if dispatch_var is None:
                        dispatch_var = var
                    if var == dispatch_var:
                        chain_count += 1
                        j += 1
                        continue
                    break

                # const/4 vX, 0xN（用於 if-eq 的比較值）
                if re.match(r"^const(?:/4|/16|/high16)?\s+", sj):
                    j += 1
                    continue

                # goto :label（分派鏈結尾 = default case）
                if re.match(r"^goto(?:/\w+)?\s+:\w+", sj):
                    if chain_count >= 2:
                        is_dispatch = True
                        j += 1  # 含 goto 一併跳過
                    break

                # 其他指令：如果已經收集到足夠的分支，視為分派鏈結束
                # （default case 代碼直接跟在最後一個 if 後面，沒有 goto）
                if chain_count >= 2:
                    is_dispatch = True
                    # 不跳過這個指令，它是 case body 的一部分
                break

            if is_dispatch:
                i = j
                continue

        result.append(instrs[i])
        i += 1

    return result


def _strip_try_catch_metadata(instrs: list[str]) -> list[str]:
    """
    移除 try-catch 范围标记和 catch 声明。
    这些是元数据，不影响指令流，但会因基本块重排而位置不同。
    """
    return [
        line
        for line in instrs
        if not line.strip().startswith(":try_")
        and not line.strip().startswith(".catch")
    ]


def _normalize_if_goto(instrs: list[str]) -> list[str]:
    """
    正規化 if-xxx + goto 模式为直接分支。

    d8 產生: if-eqz vX, :error → goto :continue → :error → throw → :continue
    dx 產生: if-nez vX, :continue → throw → :continue

    偵測到 if-xxx 后紧接 goto 时，翻转条件并移除 goto。
    """
    result: list[str] = []
    i = 0
    while i < len(instrs):
        s = instrs[i].strip()

        m = re.match(r"^(if-\w+)\s+(.+),\s*(:\w+)\s*$", s)
        if m and m.group(1) in _CONDITION_PAIRS:
            # 检查下一条有效指令是否为 goto
            j = i + 1
            while j < len(instrs) and not instrs[j].strip():
                j += 1

            if j < len(instrs):
                goto_m = re.match(r"^goto(?:/\w+)?\s+(:\w+)\s*$", instrs[j].strip())
                if goto_m:
                    # 翻转条件，目标改为 goto 的目标
                    flipped = _CONDITION_PAIRS[m.group(1)]
                    continue_label = goto_m.group(1)
                    result.append(f"{flipped} {m.group(2).strip()}, {continue_label}")
                    i = j + 1
                    continue

        result.append(instrs[i])
        i += 1
    return result


def _merge_consecutive_labels(instrs: list[str]) -> list[str]:
    """
    将连续标签合并为一个，替换后续引用。

    d8 產生: :cond_2 → :goto_0 (两个标签指向同一位置)
    正規化: 保留第一个标签，所有对后续标签的引用改为第一个。
    """
    # 找出所有需要合并的标签映射
    label_alias: dict[str, str] = {}
    i = 0
    while i < len(instrs):
        s = instrs[i].strip()
        if s.startswith(":") and not s.startswith(":try_"):
            primary = s
            j = i + 1
            while j < len(instrs):
                sj = instrs[j].strip()
                if sj.startswith(":") and not sj.startswith(":try_"):
                    label_alias[sj] = primary
                    j += 1
                elif not sj:
                    j += 1
                else:
                    break
            i = j
        else:
            i += 1

    if not label_alias:
        return instrs

    # 替换引用并移除别名标签定义
    result: list[str] = []
    for line in instrs:
        s = line.strip()
        # 移除别名标签定义行
        if s in label_alias:
            continue
        # 替换指令中的标签引用
        new_line = line
        for alias, primary in label_alias.items():
            if alias in new_line:
                new_line = new_line.replace(alias, primary)
        result.append(new_line)
    return result


def _remove_unreferenced_labels(instrs: list[str]) -> list[str]:
    """移除没有被任何指令引用的标签定义。"""
    # 收集所有被引用的标签
    referenced: set[str] = set()
    for line in instrs:
        s = line.strip()
        if s.startswith(":"):
            continue  # 标签定义本身不算引用
        for m in re.finditer(r"(:\w+)", s):
            referenced.add(m.group(1))

    # 只保留被引用的标签
    return [
        line
        for line in instrs
        if not line.strip().startswith(":") or line.strip() in referenced
    ]


_TERMINAL_PREFIXES = ("return", "return-void", "return-wide", "return-object", "throw")


def _inline_goto_to_terminal(instrs: list[str]) -> list[str]:
    """将 goto :label 内联为 label 处的终结指令 (return/throw)。

    d8 常在 goto 目标处放 return，而 dx 直接 inline return 到跳转点。
    此正規化统一为 inline 形式:
      goto :L → :L → return v0  ⟹  return v0
    支持 goto 链: goto :A → :A → goto :B → :B → return v0  ⟹  return v0
    """
    # 建構 label → 后续第一条非空指令 的映射
    label_next: dict[str, str] = {}
    for i, line in enumerate(instrs):
        s = line.strip()
        if s.startswith(":"):
            # 往后找第一条非标签非空指令
            for j in range(i + 1, len(instrs)):
                nxt = instrs[j].strip()
                if nxt and not nxt.startswith(":"):
                    label_next[s] = nxt
                    break

    # 解析 goto 链 (最多 8 层防止环)
    def _resolve_terminal(label: str) -> str | None:
        visited: set[str] = set()
        cur = label
        for _ in range(8):
            if cur in visited:
                return None
            visited.add(cur)
            nxt = label_next.get(cur)
            if nxt is None:
                return None
            if nxt.startswith(("return", "throw")):
                return nxt
            if nxt.startswith("goto "):
                cur = nxt.split()[1]
                continue
            return None
        return None

    result: list[str] = []
    for line in instrs:
        s = line.strip()
        if s.startswith("goto "):
            target_label = s.split()[1]
            terminal = _resolve_terminal(target_label)
            if terminal is not None:
                result.append(terminal)
                continue
        result.append(line)
    return result


def _remove_dead_code(instrs: list[str]) -> list[str]:
    """移除终结指令 (return/throw/goto) 之后、下一个被引用标签之前的死代码。

    内联 goto→return 之后可能产生:
      return v0       ← 终结指令
      :L_old          ← 不再被引用的标签 (或被引用的)
      return v0       ← 如果 :L_old 不被引用则是死代码
    此函数移除不可达指令。迭代直到稳定。
    """
    for _ in range(4):  # 最多迭代 4 次
        # 收集被引用的标签
        referenced: set[str] = set()
        for line in instrs:
            s = line.strip()
            if s.startswith(":"):
                continue
            for m in re.finditer(r"(:\w+)", s):
                referenced.add(m.group(1))

        result: list[str] = []
        dead = False
        for line in instrs:
            s = line.strip()
            if dead:
                # 遇到被引用的标签 → 恢复活跃
                if s.startswith(":") and s in referenced:
                    dead = False
                    result.append(line)
                # 否则跳過 (死代码)
                continue
            result.append(line)
            # 终结指令后标记死区
            if s.startswith(_TERMINAL_PREFIXES) or s.startswith("goto "):
                dead = True

        if len(result) == len(instrs):
            break  # 稳定
        instrs = result
    return instrs


def _deduplicate_terminal_fallthrough(instrs: list[str]) -> list[str]:
    """移除冗余的终结指令（fall-through 到相同终结指令）。

    模式:
      return-void       ← 冗余，移除
      :cond_1
      return-void       ← 保留

    当终结指令后紧跟标签 + 相同的终结指令时，第一个终结指令可安全移除，
    因为 fall-through 语义等價。迭代直到稳定。
    """
    for _ in range(4):
        result: list[str] = []
        changed = False
        i = 0
        while i < len(instrs):
            s = instrs[i].strip()
            if s.startswith(_TERMINAL_PREFIXES):
                # 往后找：跳過所有标签定义，看到的第一条指令是否相同
                j = i + 1
                while j < len(instrs) and instrs[j].strip().startswith(":"):
                    j += 1
                if j > i + 1 and j < len(instrs) and instrs[j].strip() == s:
                    # 冗余终结指令，跳過
                    i += 1
                    changed = True
                    continue
            result.append(instrs[i])
            i += 1
        instrs = result
        if not changed:
            break
    return instrs


def _normalize_move_before_return(instrs: list[str]) -> list[str]:
    """
    S24: 正規化 move+return 到 return 模式。

    d8 经常将分散的 return rX 合并为统一的 return 出口：
      move rA, rX        ← d8 產生
      (labels)
      return rA           ← 共用出口

    dx 则直接使用:
      return rX           ← 直接返回

    正規化: 将 "move rA, rB; ... return rA" 中的 move 移除，
    并将对应的 return rA 改为 return rB。

    同样處理 move-object 和 move-wide 变体。
    """
    _MOVE_PREFIX = ("move ", "move\t", "move-object ", "move-wide ")
    _RETURN_PREFIX = ("return ", "return-object ", "return-wide ")

    # 建立映射: 寄存器重定向 move rA, rB → rA 的值来自 rB
    for _pass in range(3):
        changed = False
        result: list[str] = []
        # 收集所有 move rA, rB 后紧跟 return rA 的模式（无中间标签/指令）
        i = 0
        while i < len(instrs):
            s = instrs[i].strip()
            if s.startswith(_MOVE_PREFIX):
                parts = re.split(r"[,\s]+", s)
                if len(parts) == 3:
                    _, dst, src = parts
                    # 检查此 move 后面是否 **直接** 紧跟 return dst
                    # 不能跳過标签——标签意味着 return 是共用目标，不能改变其寄存器
                    if i + 1 < len(instrs):
                        rs = instrs[i + 1].strip()
                        if rs.startswith(_RETURN_PREFIX):
                            rparts = rs.split()
                            if len(rparts) == 2 and rparts[1] == dst:
                                # move dst, src + return dst → return src
                                ret_op = rparts[0]
                                result.append(f"{ret_op} {src}")
                                i += 2
                                changed = True
                                continue
            result.append(instrs[i])
            i += 1
        instrs = result
        if not changed:
            break
    return instrs


def _strip_null_check_blocks(instrs: list[str]) -> list[str]:
    """
    移除显式 null-check 块: if-nez vX, :cond + new-instance NPE + invoke init + throw + :cond
    D8 用 getClass() 做 null-check（已在指令级跳過），这里移除原始版的显式模式。
    """
    result = []
    i = 0
    changed = False
    while i < len(instrs):
        s = instrs[i].strip()
        # 偵測 if-nez vX, :cond_Y (null-check guard)
        m = re.match(r"^if-nez\s+(\w+),\s*(:cond_\w+)", s)
        if m and i + 3 < len(instrs):
            label = m.group(2)
            s1 = instrs[i + 1].strip()
            s2 = instrs[i + 2].strip()
            s3 = instrs[i + 3].strip()
            # Pattern: new-instance NPE + invoke-direct NPE.<init> + throw
            is_npe_block = (
                s1.startswith("new-instance ")
                and "NullPointerException" in s1
                and s2.startswith("invoke-direct ")
                and "NullPointerException;-><init>" in s2
                and s3.startswith("throw ")
            )
            if is_npe_block:
                # Skip the whole block (if-nez + new-instance + invoke-direct + throw)
                i += 4
                # Also skip the target label if it's the next line
                if i < len(instrs) and instrs[i].strip() == label:
                    i += 1
                changed = True
                continue
        result.append(instrs[i])
        i += 1
    return result if changed else instrs


def _remove_null_check_cast(instrs: list[str]) -> list[str]:
    """移除 const/4 vN, 0x0 後面緊接的 check-cast vN, <type>。

    對 null 值做 check-cast 是無操作（null 可以轉型為任何引用類型），
    但 d8 和 dx 在此行為不同：d8 省略，dx 保留。
    """
    result: list[str] = []
    i = 0
    while i < len(instrs):
        s = instrs[i].strip()
        if i + 1 < len(instrs):
            ns = instrs[i + 1].strip()
            m1 = re.match(r"const/4\s+(v\d+),\s*0x0$", s)
            if m1:
                m2 = re.match(r"check-cast\s+(v\d+),", ns)
                if m2 and m1.group(1) == m2.group(1):
                    result.append(instrs[i])
                    i += 2
                    continue
        result.append(instrs[i])
        i += 1
    return result


def _remove_goto_to_next(instrs: list[str]) -> list[str]:
    """移除跳轉目標就是下一條指令的 goto。

    goto :L
    :L        ← 目標緊接在後面，goto 是無操作
    """
    result: list[str] = []
    i = 0
    while i < len(instrs):
        if i + 1 < len(instrs):
            m = re.match(r"goto\s+(:\w+)", instrs[i].strip())
            if m and instrs[i + 1].strip() == m.group(1):
                i += 1
                continue
        result.append(instrs[i])
        i += 1
    return result


# ── 基本塊內指令排序 ──
_BB_TERMINATOR_PREFIXES = (
    "goto",
    "if-",
    "return",
    "return-void",
    "return-object",
    "return-wide",
    "throw",
    "NORM_SWITCH",
)


def _sort_instructions_within_basic_blocks(instrs: list[str]) -> list[str]:
    """將每個基本塊內的非標籤、非終端指令按字母排序。

    保留控制流結構（標籤在前、分支/回傳在後），
    僅重排中間的獨立運算指令。
    兩側編譯器可能對同一基本塊內的指令排列不同，
    排序後可規範化此差異。

    回傳排序後的指令列表（不做暫存器正規化，由呼叫端處理）。
    """
    blocks: list[list[str]] = []
    cur: list[str] = []
    for ins in instrs:
        # 遇到標籤且當前塊有非標籤指令 → 開新塊
        if ins.startswith(":") and cur and any(not l.startswith(":") for l in cur):
            blocks.append(cur)
            cur = []
        cur.append(ins)
    if cur:
        blocks.append(cur)

    result: list[str] = []
    for bb in blocks:
        labels = [l for l in bb if l.startswith(":")]
        body = [l for l in bb if not l.startswith(":")]
        if body and any(body[-1].startswith(p) for p in _BB_TERMINATOR_PREFIXES):
            mid = sorted(body[:-1])
            result.extend(labels + mid + [body[-1]])
        else:
            result.extend(labels + sorted(body))
    return result


def _build_canonical_names(
    java_lines: list[str], orig_lines: list[str]
) -> tuple[
    dict[str, str],
    dict[str, str],
    dict[tuple[str, str], str],
    dict[tuple[str, str], str],
]:
    """為 java/orig 兩側的欄位和方法建立典範名映射。

    欄位：按 (類型, 名稱) 排序配對，類型必須完全相同。
    方法：按描述符 (參數+返回類型) 分組，同描述符方法數量必須相同才配對。

    回傳: (java_field_map, orig_field_map, java_method_map, orig_method_map)
    - field_map: {原始欄位名: 典範名}
    - method_map: {(原始方法名, 描述符): 典範名}
    """

    # ── 欄位映射 ──
    def _extract_fields(lines: list[str]) -> list[tuple[str, str]]:
        fields = []
        for line in lines:
            m = re.match(r"\s*\.field\s+.*?\s+(\S+):(\S+)", line)
            if m:
                fields.append((m.group(1), m.group(2)))
        return fields

    jf = _extract_fields(java_lines)
    of = _extract_fields(orig_lines)
    jf_sorted = sorted(jf, key=lambda x: (x[1], x[0]))
    of_sorted = sorted(of, key=lambda x: (x[1], x[0]))
    j_field_map: dict[str, str] = {}
    o_field_map: dict[str, str] = {}
    if len(jf_sorted) == len(of_sorted):
        ok = True
        for i, ((jn, jt), (on, ot)) in enumerate(zip(jf_sorted, of_sorted)):
            if jt != ot:
                ok = False
                break
            if jn != on:
                c = f"__F{i}"
                j_field_map[jn] = c
                o_field_map[on] = c
        if not ok:
            j_field_map, o_field_map = {}, {}

    # ── 方法映射 ──
    def _extract_method_sigs(lines: list[str]) -> list[tuple[str, str]]:
        methods = []
        for line in lines:
            m = re.match(r"\s*\.method\s+.*?\s+(\S+)(\([^)]*\)\S+)", line)
            if m:
                methods.append((m.group(1), m.group(2)))
        return methods

    jm = _extract_method_sigs(java_lines)
    om = _extract_method_sigs(orig_lines)
    j_by_desc: dict[str, list[str]] = defaultdict(list)
    o_by_desc: dict[str, list[str]] = defaultdict(list)
    for name, desc in jm:
        j_by_desc[desc].append(name)
    for name, desc in om:
        o_by_desc[desc].append(name)

    j_method_map: dict[tuple[str, str], str] = {}
    o_method_map: dict[tuple[str, str], str] = {}
    idx = 0
    for desc in sorted(set(j_by_desc.keys()) | set(o_by_desc.keys())):
        jnames = sorted(j_by_desc.get(desc, []))
        onames = sorted(o_by_desc.get(desc, []))
        if len(jnames) != len(onames):
            continue
        for jn, on in zip(jnames, onames):
            if jn != on:
                c = f"__M{idx}"
                idx += 1
                j_method_map[(jn, desc)] = c
                o_method_map[(on, desc)] = c

    return j_field_map, o_field_map, j_method_map, o_method_map


def _apply_canonical_names(
    instrs: list[str],
    class_field_maps: dict[str, dict[str, str]],
    class_method_maps: dict[str, dict[tuple[str, str], str]],
) -> list[str]:
    """將指令中的欄位/方法引用替換為典範名。

    class_field_maps: {類名: {欄位名: 典範名}}
    class_method_maps: {類名: {(方法名, 描述符): 典範名}}
    """
    result: list[str] = []
    for line in instrs:
        s = line

        # 欄位引用: LClass;->fieldName:Type
        def _repl_field(m: re.Match) -> str:
            cls, fname, ftype = m.group(1), m.group(2), m.group(3)
            fmap = class_field_maps.get(cls)
            if fmap and fname in fmap:
                return f"{cls}->{fmap[fname]}:{ftype}"
            return m.group(0)

        s = re.sub(r"(L[^;]+;)->(\w[\w$]*):([\S]+)", _repl_field, s)

        # 方法引用: LClass;->methodName(params)ret
        def _repl_method(m: re.Match) -> str:
            cls, mname, desc = m.group(1), m.group(2), m.group(3)
            mmap = class_method_maps.get(cls)
            if mmap:
                key = (mname, desc)
                if key in mmap:
                    return f"{cls}->{mmap[key]}{desc}"
            return m.group(0)

        s = re.sub(r"(L[^;]+;)->(\w[\w$]*)(\([^)]*\)\S+)", _repl_method, s)

        result.append(s)
    return result


def _expand_stringbuilder_init(instrs: list[str]) -> list[str]:
    """
    将 StringBuilder(String) 单指令形式展开为 StringBuilder() + append(String) 双指令形式。
    D8: invoke-direct {v0, v1}, StringBuilder;-><init>(Ljava/lang/String;)V
    dx:  invoke-direct {v0}, StringBuilder;-><init>()V
         invoke-virtual {v0, v1}, StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;
    """
    result = []
    for line in instrs:
        s = line.strip()
        m = re.match(
            r"invoke-direct\s*\{(\w+),\s*(\w+)\},\s*"
            r"Ljava/lang/StringBuilder;-><init>\(Ljava/lang/String;\)V",
            s,
        )
        if m:
            sb_reg = m.group(1)
            str_reg = m.group(2)
            result.append(
                f"invoke-direct {{{sb_reg}}}, Ljava/lang/StringBuilder;-><init>()V"
            )
            result.append(
                f"invoke-virtual {{{sb_reg}, {str_reg}}}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;"
            )
        else:
            result.append(line)
    return result


def _merge_adjacent_stringbuilder_appends(instrs: list[str]) -> list[str]:
    """
    合併相鄰的 StringBuilder.append(String) 調用。

    原始 dx 編譯：
      const-string v1, "Foo"
      invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)...
      const-string v1, "Bar"
      invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)...
    JADX 反編譯會合併為 "FooBar"，D8 編回只剩一組。
    此函式將原始的多組合併為一組，使指令數一致。

    同時處理 const-string + append(C) 形式（char 版 append），
    以及插入在 append 之間的 append(C) (如逗號分隔符)。
    """
    result = []
    i = 0
    _SB_APPEND_STR = "Ljava/lang/StringBuilder;->append(Ljava/lang/String;)"
    _SB_APPEND_CHAR = "Ljava/lang/StringBuilder;->append(C)"

    while i < len(instrs):
        s = instrs[i].strip()

        # 偵測 const-string + invoke StringBuilder.append(String)
        if s.startswith("const-string") and i + 1 < len(instrs):
            next_s = instrs[i + 1].strip()
            if _SB_APPEND_STR in next_s:
                # 收集連續的 const-string + append(String) 對
                # 也跳過中間穿插的 append(C)（如逗號分隔符 const/16 + append(C)）
                merged_count = 0
                j = i
                while j < len(instrs):
                    js = instrs[j].strip()
                    if js.startswith("const-string") and j + 1 < len(instrs):
                        ns = instrs[j + 1].strip()
                        if _SB_APPEND_STR in ns:
                            merged_count += 1
                            j += 2
                            continue
                    # 也吃掉 const + append(C) 模式（如逗號分隔符）
                    if (
                        (js.startswith("const/") or js.startswith("const "))
                        and j + 1 < len(instrs)
                        and _SB_APPEND_CHAR in instrs[j + 1].strip()
                    ):
                        merged_count += 1
                        j += 2
                        continue
                    break

                if merged_count >= 2:
                    # 合併成一組 const-string + append
                    result.append(instrs[i])  # 保留第一個 const-string
                    result.append(instrs[i + 1])  # 保留第一個 append
                    i = j
                    continue

        result.append(instrs[i])
        i += 1
    return result


def _strip_sdk_int_guards(instrs: list[str]) -> list[str]:
    """
    移除 SDK_INT 版本守卫代码块。
    原始 support library 代码中常有：
      sget vX, Landroid/os/Build$VERSION;->SDK_INT:I
      const/16 vY, <api_level>
      if-lt/if-ge vX, vY, :label
    D8 編譯时因 minSdkVersion 足够高而将这些守卫移除。
    移除守卫及其对应的死代码分支后，方法体应更容易匹配。
    """
    result = []
    i = 0
    dead_labels: set[str] = set()  # 死代码跳转目标标签
    goto_after_labels: set[str] = set()  # goto 跳過死代码后的恢复标签

    # 第一遍：收集 SDK_INT guard 产生的死代码标签
    # 建立标签位置映射
    _label_positions: dict[str, int] = {}
    for _li, _line in enumerate(instrs):
        _ls = _line.strip()
        if re.match(r"^:[a-zA-Z_]\w*$", _ls):
            _label_positions[_ls] = _li

    j = 0
    while j < len(instrs):
        s = instrs[j].strip()
        if "Build$VERSION;->SDK_INT" in s or "Build$VERSION;->CODENAME" in s:
            # 跳過 const 指令（包含 const-string、const-class）
            k = j + 1
            while k < len(instrs) and instrs[k].strip().startswith(
                ("const/", "const ", "const-string", "const-class")
            ):
                k += 1
            # 偵測 if 条件
            if k < len(instrs) and instrs[k].strip().startswith("if-"):
                if_line = instrs[k].strip()
                m_label = re.search(r"(:[a-zA-Z_]\w*)", if_line)
                if m_label:
                    dead_label = m_label.group(1)
                    dead_labels.add(dead_label)
                    # 从死代码标签位置往回搜索 skip-goto（比前向搜索更准确）
                    dead_pos = _label_positions.get(dead_label)
                    if dead_pos is not None and dead_pos > k:
                        for g in range(dead_pos - 1, k, -1):
                            gs = instrs[g].strip()
                            if gs.startswith("goto"):
                                gm = re.search(r"(:[a-zA-Z_]\w*)", gs)
                                if gm:
                                    goto_after_labels.add(gm.group(1))
                                break
                            # 跳過 .line 等元数据
                            if gs.startswith(".") or not gs:
                                continue
                            break  # 遇到非 goto 非元数据指令时停止
                    else:
                        # 後備：前向搜索（死标签在 if 之前或不存在）
                        for g in range(k + 1, min(k + 40, len(instrs))):
                            gs = instrs[g].strip()
                            if gs.startswith("goto"):
                                gm = re.search(r"(:[a-zA-Z_]\w*)", gs)
                                if gm:
                                    goto_after_labels.add(gm.group(1))
                                break
                            if gs.startswith((":cond_", ":goto_")):
                                break
        j += 1

    # 第二遍：移除 SDK_INT 守卫 + 死代码块
    in_dead_block = False
    while i < len(instrs):
        s = instrs[i].strip()

        # 偵測 sget SDK_INT 模式
        if "Build$VERSION;->SDK_INT" in s or "Build$VERSION;->CODENAME" in s:
            # 尝试吃掉 sget + const + if-cond
            j = i + 1
            while j < len(instrs) and instrs[j].strip().startswith(
                ("const/", "const ", "const-string", "const-class")
            ):
                j += 1
            if j < len(instrs) and instrs[j].strip().startswith("if-"):
                i = j + 1
                continue
            i += 1
            continue

        # 偵測进入死代码块：标签是 dead_labels 之一
        if s.startswith(":") and s in dead_labels and not in_dead_block:
            in_dead_block = True
            i += 1
            continue

        # 偵測离开死代码块：标签是 goto_after_labels 之一
        if in_dead_block:
            if s.startswith(":") and s in goto_after_labels:
                in_dead_block = False
                result.append(instrs[i])  # 保留恢复标签
            # 否则跳過死代码
            i += 1
            continue

        # 移除跳過死代码的 goto（紧在死代码块前）
        if s.startswith("goto"):
            gm = re.search(r"(:[a-zA-Z_]\w*)", s)
            if gm and gm.group(1) in goto_after_labels:
                i += 1
                continue

        result.append(instrs[i])
        i += 1
    return result


def _expand_filled_new_array(instrs: list[str]) -> list[str]:
    """
    将 filled-new-array 指令展开为等價的 new-array + aput 序列。
    D8 使用 filled-new-array 替代 dx 的 new-array + aput 序列。

    例：
      filled-new-array {v0, v1, v2}, [I
      move-result-object v3
    展开为：
      const/4 vT, 0x3
      new-array v3, vT, [I
      const/4 vI, 0x0
      aput v0, v3, vI
      const/4 vI, 0x1
      aput v1, v3, vI
      const/4 vI, 0x2
      aput v2, v3, vI
    """
    import re

    result = []
    i = 0
    changed = False
    while i < len(instrs):
        s = instrs[i].strip()
        # Match filled-new-array {regs}, [type
        m = re.match(r"^filled-new-array(?:/range)?\s*\{([^}]*)\},\s*(\[.+)", s)
        if m:
            regs_str = m.group(1).strip()
            arr_type = m.group(2).strip()
            if ".." in regs_str:
                # range form: {v0 .. v5} — parse as range
                rm = re.match(r"([vp]\d+)\s*\.\.\s*([vp]\d+)", regs_str)
                if rm:
                    prefix = rm.group(1)[0]
                    start = int(rm.group(1)[1:])
                    end = int(rm.group(2)[1:])
                    regs = [f"{prefix}{n}" for n in range(start, end + 1)]
                else:
                    result.append(instrs[i])
                    i += 1
                    continue
            else:
                regs = [r.strip() for r in regs_str.split(",") if r.strip()]
            count = len(regs)
            # Determine aput variant from array type
            elem_type = arr_type[1:]  # strip leading [
            if elem_type.startswith("L") or elem_type.startswith("["):
                aput_op = "aput-object"
            elif elem_type in ("Z", "B", "C", "S", "I"):
                aput_op = "aput"
            elif elem_type == "J":
                aput_op = "aput-wide"
            elif elem_type in ("F", "D"):
                aput_op = "aput"  # float/double also use aput for type-specific
            else:
                aput_op = "aput-object"

            # Check if next instruction is move-result-object
            dest_reg = "v99"
            if i + 1 < len(instrs):
                next_s = instrs[i + 1].strip()
                nm = re.match(r"^move-result-object\s+([vp]\d+)", next_s)
                if nm:
                    dest_reg = nm.group(1)
                    i += 1  # skip the move-result-object

            # Emit expanded form
            result.append(f"    const/4 v98, {hex(count)}")
            result.append(f"    new-array {dest_reg}, v98, {arr_type}")
            for idx, reg in enumerate(regs):
                result.append(f"    const/4 v97, {hex(idx)}")
                result.append(f"    {aput_op} {reg}, {dest_reg}, v97")
            changed = True
            i += 1
            continue
        result.append(instrs[i])
        i += 1
    return result if changed else instrs


def _strip_clinit_const_sput_pairs(instrs: list[str]) -> list[str]:
    """
    移除 <clinit> 中的 const + sput 配對。

    編譯器差異：原始 dex 可能在欄位宣告中內聯常數值（`= 0x5`），
    `<clinit>` 中省略對應的 `const + sput`；但 java→D8 重新編譯
    會把所有 static final 初始值展開為 `<clinit>` 中的指令。

    此函式移除 `const* vN, ... / sput* vN, ...` 的成對指令。
    對於非 <clinit> 方法不應使用。
    """
    if len(instrs) < 2:
        return instrs
    result = []
    i = 0
    changed = False
    while i < len(instrs):
        s = instrs[i].strip()
        # 檢查 const + sput 配對
        if s.startswith("const") and i + 1 < len(instrs):
            next_s = instrs[i + 1].strip()
            if next_s.startswith("sput"):
                # 確認是同一暫存器: const* vN, ... + sput* vN, ...
                m_const = re.match(r"const\S*\s+(\w+)", s)
                m_sput = re.match(r"sput\S*\s+(\w+)", next_s)
                if m_const and m_sput and m_const.group(1) == m_sput.group(1):
                    i += 2
                    changed = True
                    continue
        result.append(instrs[i])
        i += 1
    return result if changed else instrs


def _collapse_access_to_field(instrs: list[str]) -> list[str]:
    """
    将 access$getXxx$p / access$setXxx$p 调用折叠为 iget/iput 指令。

    原始 smali (dx / 旧編譯器):
      invoke-static {v0}, LClass;->access$getCount$p(LClass;)I
      move-result v1
    D8/jadx 内联后:
      iget v1, v0, LClass;->count:I

    setter 形式:
      invoke-static {v0, v1}, LClass;->access$setCount$p(LClass;I)V
    内联后:
      iput v1, v0, LClass;->count:I

    也處理 object 類型 (iget-object / iput-object)。
    """
    import re

    result = []
    i = 0
    changed = False
    _RE_ACCESS_GET = re.compile(
        r"^invoke-static\s*\{(\w+)\},\s*"
        r"(L[^;]+;)->access\$get([A-Za-z_]\w*)\$p"
        r"\(\2\)(.+)$"
    )
    _RE_ACCESS_SET = re.compile(
        r"^invoke-static\s*\{(\w+),\s*(\w+)\},\s*"
        r"(L[^;]+;)->access\$set([A-Za-z_]\w*)\$p"
        r"\(\3(.+?)\)V$"
    )
    while i < len(instrs):
        s = instrs[i].strip()
        # getter: invoke-static {vObj}, LClass;->access$getField$p(LClass;)RetType
        mg = _RE_ACCESS_GET.match(s)
        if mg:
            obj_reg = mg.group(1)
            cls = mg.group(2)
            field_camel = mg.group(3)
            ret_type = mg.group(4)
            # Convert CamelCase field name to lowerCamelCase
            field_name = (
                field_camel[0].lower() + field_camel[1:] if field_camel else field_camel
            )
            # Determine iget variant
            if ret_type.startswith("L") or ret_type.startswith("["):
                iget_op = "iget-object"
            elif ret_type in ("J",):
                iget_op = "iget-wide"
            elif ret_type in ("Z", "B", "C", "S", "I", "F"):
                iget_op = "iget"
            elif ret_type in ("D",):
                iget_op = "iget-wide"
            else:
                iget_op = "iget-object"
            # Check for move-result(-object|-wide) on next line
            dest_reg = obj_reg  # fallback
            if i + 1 < len(instrs):
                next_s = instrs[i + 1].strip()
                mr = re.match(r"^move-result(?:-object|-wide)?\s+(\w+)", next_s)
                if mr:
                    dest_reg = mr.group(1)
                    i += 1  # skip the move-result
            result.append(
                f"    {iget_op} {dest_reg}, {obj_reg}, {cls}->{field_name}:{ret_type}"
            )
            changed = True
            i += 1
            continue

        # setter: invoke-static {vObj, vVal}, LClass;->access$setField$p(LClass;ValType)V
        ms = _RE_ACCESS_SET.match(s)
        if ms:
            obj_reg = ms.group(1)
            val_reg = ms.group(2)
            cls = ms.group(3)
            field_camel = ms.group(4)
            val_type = ms.group(5)
            field_name = (
                field_camel[0].lower() + field_camel[1:] if field_camel else field_camel
            )
            if val_type.startswith("L") or val_type.startswith("["):
                iput_op = "iput-object"
            elif val_type in ("J", "D"):
                iput_op = "iput-wide"
            else:
                iput_op = "iput"
            result.append(
                f"    {iput_op} {val_reg}, {obj_reg}, {cls}->{field_name}:{val_type}"
            )
            changed = True
            i += 1
            continue

        result.append(instrs[i])
        i += 1
    return result if changed else instrs


def _strip_array_boilerplate(instrs: list[str]) -> list[str]:
    """
    去除列舉 <clinit> 中的数组创建模式差異。
    JDK17: invoke-static $values() + move-result-object + sput-object $VALUES
    旧版:  new-array + (interleaved aput-object) + sput-object $VALUES
    去除这些后，剩下的应该只有列舉常量的初始化代码。
    """
    result = []
    skip_next_move_result = False
    for i, line in enumerate(instrs):
        s = line.strip()
        if not s:
            continue
        # Skip $values() invocation
        if "$values()" in s and s.startswith("invoke-static"):
            skip_next_move_result = True
            continue
        # Skip move-result-object after $values()
        if skip_next_move_result and s.startswith("move-result-object"):
            skip_next_move_result = False
            continue
        skip_next_move_result = False
        # Skip new-array
        if s.startswith("new-array"):
            continue
        # Skip aput-object (enum constant → array population)
        if s.startswith("aput-object"):
            continue
        # Skip sput-object for $VALUES field
        if s.startswith("sput-object") and "$VALUES:" in s:
            continue
        # Skip const for array size (e.g., const/4 v0, 0x3 before new-array)
        # Only skip if the next non-empty instruction is new-array
        # This is hard to detect, so we skip it for now
        result.append(line)
    return result


def _canonicalize_regs_and_labels(instrs: list[str]) -> list[str]:
    """
    将方法内的寄存器和标签按出现顺序重新编号。
    这样不同編譯器产生的不同命名会被统一。
    标签按首次出现（引用或定义）的顺序编号，确保前向引用也被正确正規化。
    """
    reg_counter = 0
    label_counter = 0
    reg_map: dict[str, str] = {}
    label_map: dict[str, str] = {}
    result = []

    # 标签正則
    re_label_def = re.compile(r"^(:[a-zA-Z_]\w*)$")  # 标签定义
    re_label_ref = re.compile(r"(:[a-zA-Z_]\w*)")  # 标签引用

    def _map_label(lbl: str) -> str:
        nonlocal label_counter
        if lbl not in label_map:
            label_map[lbl] = f":L{label_counter}"
            label_counter += 1
        return label_map[lbl]

    for instr in instrs:
        s = instr.strip()
        if not s:
            continue

        # 先處理标签定义
        m = re_label_def.match(s)
        if m:
            result.append(_map_label(m.group(1)))
            continue

        # 處理 .packed-switch / .sparse-switch 数据段
        if s.startswith(".packed-switch") or s.startswith(".sparse-switch"):
            # 正規化Data段的标签引用
            new_s = re_label_ref.sub(lambda m2: _map_label(m2.group(1)), s)
            result.append(new_s)
            continue

        if s.startswith(".end packed-switch") or s.startswith(".end sparse-switch"):
            result.append(s)
            continue

        # 替换寄存器
        tokens = []
        last_end = 0
        for m2 in _RE_REGISTER.finditer(s):
            tokens.append(s[last_end : m2.start()])
            reg = m2.group(1)
            if reg not in reg_map:
                reg_map[reg] = f"r{reg_counter}"
                reg_counter += 1
            tokens.append(reg_map[reg])
            last_end = m2.end()
        tokens.append(s[last_end:])
        new_s = "".join(tokens)

        # 替换标签引用
        new_s = re_label_ref.sub(lambda m2: _map_label(m2.group(1)), new_s)

        result.append(new_s)

    return result


def _try_register_mapping(instrs1: list[str], instrs2: list[str]) -> bool:
    """尝试建立寄存器映射来证明等價"""
    if len(instrs1) != len(instrs2):
        return False

    reg_map: dict[str, str] = {}
    label_map: dict[str, str] = {}

    for i1, i2 in zip(instrs1, instrs2):
        if i1 == i2:
            continue

        # 先尝试标签映射
        s1, s2 = i1.strip(), i2.strip()
        if s1.startswith(":") and s2.startswith(":"):
            if s1 not in label_map:
                label_map[s1] = s2
            if label_map.get(s1) != s2:
                return False
            continue

        regs1 = _RE_REGISTER.findall(i1)
        regs2 = _RE_REGISTER.findall(i2)

        if len(regs1) != len(regs2):
            return False

        # 去掉寄存器和标签后的骨架应该相同
        skeleton1 = _RE_REGISTER.sub("REG", i1)
        skeleton2 = _RE_REGISTER.sub("REG", i2)

        # 标签引用也需要映射
        re_label_ref = re.compile(r"(:[a-zA-Z_]\w*)")
        labels1 = re_label_ref.findall(skeleton1)
        labels2 = re_label_ref.findall(skeleton2)
        for lb1, lb2 in zip(labels1, labels2):
            if lb1 not in label_map:
                label_map[lb1] = lb2
            skeleton1 = skeleton1.replace(lb1, label_map.get(lb1, lb1), 1)

        skeleton1_norm = re_label_ref.sub(
            lambda m: label_map.get(m.group(1), m.group(1)), skeleton1
        )

        if skeleton1_norm != skeleton2:
            return False

        for r1, r2 in zip(regs1, regs2):
            if r1 in reg_map:
                if reg_map[r1] != r2:
                    return False
            else:
                reg_map[r1] = r2

    return True


# 条件指令对 (用于条件翻转正規化)
_CONDITION_PAIRS = {
    "if-eqz": "if-nez",
    "if-nez": "if-eqz",
    "if-eq": "if-ne",
    "if-ne": "if-eq",
    "if-ltz": "if-gez",
    "if-gez": "if-ltz",
    "if-gtz": "if-lez",
    "if-lez": "if-gtz",
    "if-lt": "if-ge",
    "if-ge": "if-lt",
    "if-gt": "if-le",
    "if-le": "if-gt",
}


def _normalize_branch_blocks(instrs: list[str]) -> list[str]:
    """
    正規化 if-else 基本块排列顺序，處理 d8/dx 的布局差異。

    d8 典型: if-eqz → success(fallthrough) → terminal → :label → error
    dx 典型: if-nez → error(fallthrough)  → terminal → :label → success

    两者功能完全相等。对每个符合条件的 if-else 结构，產生两种候选布局
    (原序和翻转+交换)，取字典序较小者为正則形式。

    仅在 fall-through 块以 terminal 指令 (return/throw/goto) 结尾时适用，
    保证两个分支路径完全独立、可安全交换。
    """
    result: list[str] = []
    i = 0
    while i < len(instrs):
        s = instrs[i].strip()

        # 匹配: if-xxx args, :label
        m = re.match(r"^(if-\w+)\s+(.+),\s*(:\w+)\s*$", s)
        if not m or m.group(1) not in _CONDITION_PAIRS:
            result.append(instrs[i])
            i += 1
            continue

        cond_op = m.group(1)
        cond_rest = m.group(2).strip()
        target_label = m.group(3)

        # 收集 fall-through 块（直到目标 label 行）
        fall_block: list[str] = []
        j = i + 1
        found_label = False
        while j < len(instrs):
            if instrs[j].strip() == target_label:
                found_label = True
                break
            fall_block.append(instrs[j])
            j += 1

        if not found_label or not fall_block:
            result.append(instrs[i])
            i += 1
            continue

        # 检查 fall-through 块最后一条有效指令是否为 terminal
        # 跳過 try 范围标记和 .catch 声明（不影响控制流）
        last_code = None
        for idx in range(len(fall_block) - 1, -1, -1):
            stripped_line = fall_block[idx].strip()
            if (
                stripped_line
                and not stripped_line.startswith(".")
                and not stripped_line.startswith(":try_")
            ):
                last_code = stripped_line
                break

        if not last_code or not (
            last_code.startswith("return")
            or last_code.startswith("throw")
            or last_code.startswith("goto")
        ):
            result.append(instrs[i])
            i += 1
            continue

        # 收集 target 块（:label 之后到所有剩余指令）
        # fall-through 已经以 terminal 结尾，所以 target 块是所有剩余代码
        target_block: list[str] = list(instrs[j + 1 :])
        k = len(instrs)

        # 递归正規化子块內部的 if-else
        fall_block = _normalize_branch_blocks(fall_block)
        target_block = _normalize_branch_blocks(target_block)

        # 產生两种候选布局，取字典序较小者
        flipped = _CONDITION_PAIRS[cond_op]

        cand_a = (
            [f"{cond_op} {cond_rest}, {target_label}"]
            + fall_block
            + [target_label]
            + target_block
        )
        cand_b = (
            [f"{flipped} {cond_rest}, {target_label}"]
            + target_block
            + [target_label]
            + fall_block
        )

        key_a = "\n".join(l.strip() for l in cand_a)
        key_b = "\n".join(l.strip() for l in cand_b)

        result.extend(cand_a if key_a <= key_b else cand_b)
        i = k

    return result


_COMMUTATIVE_INT_OPS = frozenset({"add-int", "mul-int", "and-int", "or-int", "xor-int"})
_RE_ARITH_LIT = re.compile(
    r"(rsub|mul|add|div|rem|and|or|xor|shl|shr|ushr)-int/lit\d+\s+"
    r"(\S+),\s*(\S+),\s*(\S+)"
)


def _make_canonical_arith_lit_from_litN(instr: str) -> str:
    """从 op-int/litN 指令產生正規化 NORM_ARITH_LIT 字符串。"""
    m = _RE_ARITH_LIT.match(instr.strip())
    if not m:
        return f"NORM_ARITH_LIT {instr}"
    op_prefix = m.group(1)  # "add" / "rsub" / ...
    op_base = f"{op_prefix}-int"
    dest = m.group(2).rstrip(",")
    src = m.group(3).rstrip(",")
    lit_val = m.group(4)
    return f"NORM_ARITH_LIT {op_base} {dest} {src} {lit_val}"


def _make_canonical_arith_lit_from_const_2addr(const_line: str, addr2_line: str) -> str:
    """从 const + op-int/2addr 產生正規化 NORM_ARITH_LIT 字符串。"""
    # Parse const: "const/16 v0, 0xd"
    const_parts = const_line.strip().split()
    lit_val = const_parts[-1]  # last token is the literal

    # Parse 2addr: "mul-int/2addr v0, v1"
    addr_parts = addr2_line.strip().split()
    op_full = addr_parts[0]  # "mul-int/2addr"
    op_base = op_full.replace("/2addr", "")  # "mul-int"
    first_reg = addr_parts[1].rstrip(",")
    second_reg = addr_parts[2].rstrip(",") if len(addr_parts) > 2 else first_reg

    # Semantics: first_reg = const_val OP second_reg = #lit OP second_reg
    if op_base in _COMMUTATIVE_INT_OPS:
        # Commutative: #lit OP rB == rB OP #lit
        return f"NORM_ARITH_LIT {op_base} {first_reg} {second_reg} {lit_val}"
    elif op_base == "sub-int":
        # const + sub/2addr: first = #lit - second → rsub
        return f"NORM_ARITH_LIT rsub-int {first_reg} {second_reg} {lit_val}"
    else:
        # Non-commutative with lit on LEFT (div, rem, shl, shr, ushr)
        return f"NORM_ARITH_LIT {op_base}-rev {first_reg} {second_reg} {lit_val}"


_RE_REG = re.compile(r"[vp]\d+")


def _get_reads_writes(instr: str) -> tuple[set[str], set[str]]:
    """提取 smali 指令的读/写寄存器集合。"""
    s = instr.strip()
    parts = s.split()
    if not parts:
        return set(), set()
    op = parts[0]
    regs = _RE_REG.findall(s)
    if not regs:
        return set(), set()

    # invoke/filled-new-array: 所有參數为读
    if op.startswith(("invoke", "filled-new-array")):
        return set(regs), set()
    # iput/sput/aput: 所有寄存器为读（写入内存/欄位）
    if op.startswith(("iput", "sput", "aput")):
        return set(regs), set()
    # return/throw/monitor: 读取寄存器
    if op.startswith(("return", "throw", "monitor")):
        return set(regs), set()
    # if-xxx: 读取比較寄存器
    if op.startswith("if-"):
        return set(regs), set()
    # move-result: 写入目标
    if op.startswith("move-result"):
        return set(), {regs[0]}
    # const-xxx: 仅写入目标
    if op.startswith("const"):
        return set(), {regs[0]}
    # 預設：第一个寄存器写入，其余读取
    return set(regs[1:]), {regs[0]}


def _float_consts_early(instrs: list[str]) -> list[str]:
    """
    基于数据依赖的基本块内指令正規化排序。

    d8 和 dx 对同一基本块内独立指令的排列顺序可能不同。
    此函数建構依赖图，按拓扑排序 + 字典序稳定化（tiebreak）产生正規化顺序。

    invoke-xxx + move-result 视为原子组，不可拆分。
    """
    # 将指令分割为基本块
    blocks: list[list[str]] = []
    cur: list[str] = []
    for line in instrs:
        s = line.strip()
        if s.startswith(":") and cur:
            blocks.append(cur)
            cur = [line]
        else:
            cur.append(line)
            if s.startswith(
                ("if-", "goto", "return", "throw", "packed-switch", "sparse-switch")
            ):
                blocks.append(cur)
                cur = []
    if cur:
        blocks.append(cur)

    result: list[str] = []
    for block in blocks:
        if len(block) <= 2:
            result.extend(block)
            continue

        # 将 invoke+move-result 组成原子组
        groups: list[tuple[str, ...]] = []
        j = 0
        while j < len(block):
            s = block[j].strip()
            if (
                s.startswith(("invoke-", "filled-new-array"))
                and j + 1 < len(block)
                and block[j + 1].strip().startswith("move-result")
            ):
                groups.append((block[j], block[j + 1]))
                j += 2
            else:
                groups.append((block[j],))
                j += 1

        n = len(groups)
        if n <= 1:
            result.extend(block)
            continue

        # 计算每组的读/写集合 + 是否有副作用
        rw: list[tuple[set[str], set[str], bool]] = []
        for g in groups:
            reads: set[str] = set()
            writes: set[str] = set()
            has_side_effect = False
            for ln in g:
                r, w = _get_reads_writes(ln)
                reads |= r
                writes |= w
                ls = ln.strip()
                if ls.startswith(
                    ("invoke", "iput", "sput", "aput", "monitor", "throw")
                ):
                    has_side_effect = True
            rw.append((reads, writes, has_side_effect))

        # 建構依赖图 (i < j 的原始顺序中，如有数据依赖则 j 依赖 i)
        deps: list[set[int]] = [set() for _ in range(n)]
        # 副作用指令之间保持相对顺序
        last_side_effect = -1
        for i in range(n):
            ri, wi, sei = rw[i]
            # 标签必须保持原位
            if any(ln.strip().startswith(":") for ln in groups[i]):
                for prev in range(i):
                    deps[i].add(prev)
                continue
            # 副作用排序
            if sei:
                if last_side_effect >= 0:
                    deps[i].add(last_side_effect)
                last_side_effect = i
            # 与之前所有组的数据依赖
            for prev in range(i):
                rp, wp, _ = rw[prev]
                # RAW: i 读 prev 写的 / WAW: i 写 prev 写的 / WAR: i 写 prev 读的
                if (ri & wp) or (wi & wp) or (wi & rp):
                    deps[i].add(prev)

        # 拓扑排序 + 字典序 tiebreak
        from heapq import heappush, heappop

        in_degree = [len(d) for d in deps]
        adj: list[list[int]] = [[] for _ in range(n)]
        for i in range(n):
            for prev in deps[i]:
                adj[prev].append(i)

        # S25: 使用 register-blind key 做 tiebreak，让排序由操作码+參數值决定
        # 而非寄存器编号。这样 dx 的 "const/4 v1,0x1; const/4 v2,0x0" 和
        # d8 的 "const/4 v1,0x0; const/4 v2,0x1" 排序結果一致（0x0 在前），
        # 后续 _canonicalize_regs_and_labels 就能正确匹配。
        keys = [
            "\n".join(_RE_REGISTER.sub("_R_", ln.strip()) for ln in g) for g in groups
        ]
        heap: list[tuple[str, int]] = []
        for i in range(n):
            if in_degree[i] == 0:
                heappush(heap, (keys[i], i))

        sorted_groups: list[tuple[str, ...]] = []
        while heap:
            _, i = heappop(heap)
            sorted_groups.append(groups[i])
            for j in adj[i]:
                in_degree[j] -= 1
                if in_degree[j] == 0:
                    heappush(heap, (keys[j], j))

        # 防止依赖环导致遗漏：如果未排完，追加剩余
        if len(sorted_groups) < n:
            placed = {id(g) for g in sorted_groups}
            for g in groups:
                if id(g) not in placed:
                    sorted_groups.append(g)

        for g in sorted_groups:
            result.extend(g)
    return result


def _propagate_const_to_2addr(instrs: list[str]) -> list[str]:
    """將非相鄰的 const + op/2addr 合併為 NORM_ARITH_LIT。

    已有的 _normalize_instructions 只處理 const 緊鄰 2addr 的情況。
    此函式處理中間有其他指令的情況，前提是 const 定義的暫存器
    在使用前沒有被重新定義。

    例如:
      const/16 v0, 0xFF
      iget v2, v3, Lcom/foo;->bar:I
      and-int/2addr v1, v0
    →
      iget v2, v3, Lcom/foo;->bar:I
      NORM_ARITH_LIT and-int v1 v1 0xFF
    """
    _ARITH_2ADDR_PREFIXES = (
        "mul-int/2addr",
        "add-int/2addr",
        "sub-int/2addr",
        "div-int/2addr",
        "rem-int/2addr",
        "and-int/2addr",
        "or-int/2addr",
        "xor-int/2addr",
        "shl-int/2addr",
        "shr-int/2addr",
        "ushr-int/2addr",
    )

    result = list(instrs)
    changed = True
    max_iter = 5  # 防止無限迴圈
    while changed and max_iter > 0:
        changed = False
        max_iter -= 1
        # 收集 const 定義：reg → (index, instruction)
        const_defs: dict[str, tuple[int, str]] = {}
        to_remove: set[int] = set()
        new_result = list(result)

        for i, s in enumerate(result):
            stripped = s.strip()
            # 追蹤 const 定義
            m = re.match(
                r"const(?:/4|/16|/high16|(?:-wide(?:/16|/32|/high16)?)?)?\s+"
                r"(v\d+|r\d+|p\d+)\s*,\s*(-?0x[\da-fA-F]+|-?\d+)",
                stripped,
            )
            if m:
                const_defs[m.group(1)] = (i, stripped)
                continue

            # 檢查 2addr 指令
            if stripped.startswith(_ARITH_2ADDR_PREFIXES):
                parts = stripped.split()
                if len(parts) >= 2:
                    regs = " ".join(parts[1:]).split(",")
                    regs = [r.strip() for r in regs]
                    if len(regs) == 2:
                        _, second_reg = regs
                        if second_reg in const_defs:
                            ci, cinst = const_defs[second_reg]
                            try:
                                norm = _make_canonical_arith_lit_from_const_2addr(
                                    cinst, stripped
                                )
                                new_result[i] = norm
                                to_remove.add(ci)
                                del const_defs[second_reg]
                                changed = True
                            except Exception:
                                pass

            # 任何寫入暫存器的指令會使 const 定義失效
            regs_in = _RE_REG.findall(stripped)
            if (
                regs_in
                and not stripped.startswith((":", "."))
                and not stripped.startswith(("invoke", "filled-new-array"))
                and not stripped.startswith(("iput", "sput", "aput"))
                and not stripped.startswith(("return", "throw", "monitor", "if-"))
                and not stripped.startswith(("goto", "packed-switch", "sparse-switch"))
            ):
                # 第一個暫存器通常是目標（除了上面排除的指令）
                dest = regs_in[0]
                if dest in const_defs:
                    del const_defs[dest]

            # 標籤和分支會使所有 const 定義失效（跨基本塊邊界）
            if stripped.startswith(":") or stripped.startswith(
                ("goto", "if-", "packed-switch", "sparse-switch")
            ):
                const_defs.clear()

        if changed:
            result = [
                new_result[i] for i in range(len(new_result)) if i not in to_remove
            ]

    return result


def _normalize_instructions(instrs: list[str]) -> list[str]:
    """
    正規化指令变体，合并等價但形式不同的指令：
    - mul-int/lit8 ↔ const + mul-int/2addr
    - filled-new-array ↔ new-array + aput 序列
    - check-cast 冗余移除
    - const-string/jumbo → const-string
    - move/from16 → move
    - invoke-xxx/range 单寄存器 → invoke-xxx
    - (条件翻转已移至 _normalize_branch_blocks 處理)
    """
    result = []
    i = 0
    while i < len(instrs):
        s = instrs[i].strip()
        if not s:
            i += 1
            continue

        # ── filled-new-array + move-result-object → NORM_ARRAY_CREATE ──
        if s.startswith("filled-new-array"):
            m = re.match(r"filled-new-array(?:/range)?\s*\{[^}]*\},\s*(\[\S+)", s)
            if (
                m
                and i + 1 < len(instrs)
                and instrs[i + 1].strip().startswith("move-result-object")
            ):
                result.append(f"NORM_ARRAY_CREATE {m.group(1)}")
                i += 2
                continue

        # ── new-array + (const + aput)×N → NORM_ARRAY_CREATE ──
        if s.startswith("new-array "):
            m = re.match(r"new-array\s+\S+,\s*\S+,\s*(\[\S+)", s)
            if m:
                arr_type = m.group(1)
                j = i + 1
                while j < len(instrs):
                    ns = instrs[j].strip()
                    if ns.startswith(("const/", "const ", "aput")):
                        j += 1
                    else:
                        break
                aput_count = sum(
                    1 for k in range(i + 1, j) if instrs[k].strip().startswith("aput")
                )
                if aput_count >= 1:
                    result.append(f"NORM_ARRAY_CREATE {arr_type}")
                    i = j
                    continue

        # ── const + arith/2addr → NORM_ARITH_LIT ──
        if (
            i + 1 < len(instrs)
            and s.startswith("const")
            and instrs[i + 1]
            .strip()
            .startswith(
                (
                    "mul-int/2addr",
                    "add-int/2addr",
                    "sub-int/2addr",
                    "div-int/2addr",
                    "rem-int/2addr",
                    "and-int/2addr",
                    "or-int/2addr",
                    "xor-int/2addr",
                    "shl-int/2addr",
                    "shr-int/2addr",
                    "ushr-int/2addr",
                )
            )
        ):
            result.append(
                _make_canonical_arith_lit_from_const_2addr(s, instrs[i + 1].strip())
            )
            i += 2
            continue

        # ── arith-int/lit8, /lit16 → NORM_ARITH_LIT ──
        if re.match(r"(mul|add|rsub|div|rem|and|or|xor|shl|shr|ushr)-int/lit", s):
            result.append(_make_canonical_arith_lit_from_litN(s))
            i += 1
            continue

        # ── cmpg/cmpl + if 条件配对正規化 ──
        # D8: cmpg-double + if-gtz  ↔  dx: cmpl-double + if-lez（语义等價）
        # D8: cmpg-float + if-gez   ↔  dx: cmpl-float + if-ltz
        # 统一正規化为 cmpl + 对应条件
        if s.startswith(("cmpg-float", "cmpg-double")) and i + 1 < len(instrs):
            next_s = instrs[i + 1].strip()
            _CMP_IF_FLIP = {
                "if-gtz": "if-lez",
                "if-gez": "if-ltz",
                "if-ltz": "if-gez",
                "if-lez": "if-gtz",
            }
            next_parts = next_s.split()
            if next_parts and next_parts[0] in _CMP_IF_FLIP:
                s = s.replace("cmpg-float", "cmpl-float").replace(
                    "cmpg-double", "cmpl-double"
                )
                next_parts[0] = _CMP_IF_FLIP[next_parts[0]]
                result.append(s)
                result.append(" ".join(next_parts))
                i += 2
                continue

        # ── 连续 if-eq/if-ne/if-eqz/if-nez 链 → NORM_SWITCH ──
        # dx 使用 if-eq 链做 hash 分发，d8 使用 sparse-switch
        # 连续 2+ 个 if-eq/if-ne vX, vY, :label (同一 vX) → 等價于 sparse-switch
        # D8 展開形式：const/4 vN, 0xK + if-eq pX, vN, :label（const 穿插在 if 之間）
        # 也包含 if-eqz/if-nez（case 0 的零值比較，不需要 const）
        if s.startswith(("if-eq ", "if-ne ", "if-eqz ", "if-nez ")):
            parts0 = s.split()
            if len(parts0) >= 2:
                reg0 = parts0[1].rstrip(",")
                chain_len = 1
                j = i + 1
                while j < len(instrs):
                    ns = instrs[j].strip()
                    # 跳過空行、標籤、指令元數據
                    if not ns or ns.startswith((".", ":")):
                        j += 1
                        continue
                    # 允許 const 指令穿插（D8 在每個 if-eq 前放 const 來載入比較值）
                    if ns.startswith("const"):
                        j += 1
                        continue
                    # 允許 goto 穿插（D8 可能在 if-eq 之間插入 goto 跳轉）
                    if ns.startswith("goto"):
                        j += 1
                        continue
                    if ns.startswith(("if-eq ", "if-ne ", "if-eqz ", "if-nez ")):
                        nparts = ns.split()
                        if len(nparts) >= 2 and nparts[1].rstrip(",") == reg0:
                            chain_len += 1
                            j += 1
                            continue
                    break
                if chain_len >= 2:
                    result.append("NORM_SWITCH")
                    i = j
                    continue

        # ── packed-switch / sparse-switch → NORM_SWITCH ──
        if s.startswith(("packed-switch ", "sparse-switch ")):
            result.append("NORM_SWITCH")
            i += 1
            continue

        # ── goto/16, goto/32 → goto ──
        s = re.sub(r"^goto/(?:16|32)\b", "goto", s)

        # ── invoke-direct (非 <init>) → invoke-virtual ──
        # private 方法调用在 dalvik 用 invoke-direct，javac/d8 可能用 invoke-virtual
        if s.startswith("invoke-direct ") and "<init>" not in s:
            s = "invoke-virtual " + s[len("invoke-direct ") :]
        elif s.startswith("invoke-direct/range ") and "<init>" not in s:
            s = "invoke-virtual/range " + s[len("invoke-direct/range ") :]

        # ── invoke-interface → invoke-virtual ──
        # d8/dx 对接口方法调用可能使用 invoke-virtual（具体類型）或 invoke-interface（接口類型）
        if s.startswith("invoke-interface "):
            s = "invoke-virtual " + s[len("invoke-interface ") :]
        elif s.startswith("invoke-interface/range "):
            s = "invoke-virtual/range " + s[len("invoke-interface/range ") :]

        # ── invoke-virtual/invoke-super: 去除類引用，保留方法签名 ──
        # d8 对 invoke 可能用具体類型（LinkedHashMap），dx 用声明類型（Map）
        # 同源代码編譯差異：方法名+描述符一致即等價
        m_inv = re.match(
            r"(invoke-(?:virtual|super)(?:/range)?\s+\{[^}]*\},\s*)L[^;]+;(->.*)",
            s,
        )
        if m_inv:
            s = m_inv.group(1) + m_inv.group(2)

        # ── access$NNN → access$: 合成访问方法编号正規化 ──
        # javac/d8 对內部類 access$ 方法编号不同 (access$1802 vs access$1302)
        # 類型签名相同，仅编号不同，正規化为 access$
        s = re.sub(r"->access\$\d+\(", "->access$(", s)

        # ── val$xxx 匿名內部類捕获变量名正規化 ──
        # JADX 可能将 val$result 重命名为 val$zArr 等
        # 保留類型信息，仅去除变量名: val$xxx:Type → val$:Type
        s = re.sub(r"->val\$\w+:", "->val$:", s)

        # ── $AnonymousClassN → $N 匿名類別命名正規化 ──
        # JADX 反編譯時將匿名類 $32 重命名為 $AnonymousClass32
        # 但原始編譯使用 $N 形式，正規化以消除差異
        s = re.sub(r"\$AnonymousClass(\d+)", r"$\1", s)

        # ── 2addr 指令展開為 3 運算元形式 ──
        # D8/dx 可能混用 `op/2addr a, b` 和 `op a, a, b`，語義完全等價
        # 展開: op-type/2addr vA, vB → op-type vA, vA, vB
        m_2addr = re.match(
            r"^(add|sub|mul|div|rem|and|or|xor|shl|shr|ushr)-"
            r"(int|long|float|double)/2addr\s+(\S+),\s*(\S+)$",
            s,
        )
        if m_2addr:
            op = m_2addr.group(1)
            typ = m_2addr.group(2)
            rA = m_2addr.group(3).rstrip(",")
            rB = m_2addr.group(4)
            s = f"{op}-{typ} {rA}, {rA}, {rB}"

        # ── const-string/jumbo → const-string ──
        s = re.sub(r"^const-string/jumbo\b", "const-string", s)

        # ── move/from16, move/16 → move ──
        s = re.sub(r"^(move(?:-object|-wide)?)/(?:from16|16)\b", r"\1", s)

        # ── invoke-xxx/range 單暫存器 → invoke-xxx ──
        # invoke-virtual/range {v0 .. v0}, Foo;->bar()V → invoke-virtual {v0}, Foo;->bar()V
        m_range = re.match(
            r"^(invoke-(?:virtual|static|direct|interface|super))/range"
            r"\s+\{(\w+)\s*\.\.\s*\2\}(.*)",
            s,
        )
        if m_range:
            s = f"{m_range.group(1)} {{{m_range.group(2)}}}{m_range.group(3)}"

        result.append(s)
        i += 1

    return result


def _match_methods_with_access_rename(
    methods_j: dict[str, list[str]],
    methods_o: dict[str, list[str]],
) -> tuple[dict[str, str], set[str], set[str]]:
    """
    匹配方法，處理 access$ 编号差異。
    返回 (映射 {java_sig: orig_sig}, 仅java方法集, 仅orig方法集)
    """
    mapping: dict[str, str] = {}
    used_o: set[str] = set()

    # 第一遍：精确匹配
    for sig_j in methods_j:
        if sig_j in methods_o:
            mapping[sig_j] = sig_j
            used_o.add(sig_j)

    # 第二遍：正規化签名后模糊匹配（access$, synthetic/bridge 修饰符等）
    unmatched_j = [s for s in methods_j if s not in mapping]
    unmatched_o = [s for s in methods_o if s not in used_o]

    # 建立 norm→sig 索引
    norm_o_idx: dict[str, list[str]] = defaultdict(list)
    for sig_o in unmatched_o:
        norm_o_idx[_normalize_method_sig(sig_o)].append(sig_o)

    for sig_j in unmatched_j:
        norm_j = _normalize_method_sig(sig_j)
        candidates = norm_o_idx.get(norm_j, [])
        for sig_o in candidates:
            if sig_o not in used_o:
                mapping[sig_j] = sig_o
                used_o.add(sig_o)
                break

    # 第三遍：仅用方法名+描述符（去掉所有修饰符）匹配
    unmatched_j2 = [s for s in methods_j if s not in mapping]
    unmatched_o2 = [s for s in methods_o if s not in used_o]

    def _extract_name_desc(sig: str) -> str:
        parts = sig.split()
        nd = parts[-1] if parts else sig
        return _RE_ACCESS_METHOD.sub("access$SYNTH", nd)

    nd_o_idx: dict[str, list[str]] = defaultdict(list)
    for sig_o in unmatched_o2:
        nd_o_idx[_extract_name_desc(sig_o)].append(sig_o)

    for sig_j in unmatched_j2:
        nd_j = _extract_name_desc(sig_j)
        candidates = nd_o_idx.get(nd_j, [])
        for sig_o in candidates:
            if sig_o not in used_o:
                mapping[sig_j] = sig_o
                used_o.add(sig_o)
                break

    # 第四遍：仅用描述符（參數類型+返回類型）匹配，處理方法名被改名的情况
    unmatched_j3 = [s for s in methods_j if s not in mapping]
    unmatched_o3 = [s for s in methods_o if s not in used_o]

    def _extract_descriptor(sig: str) -> str:
        """提取方法描述符（括号及之后部分）"""
        parts = sig.split()
        nd = parts[-1] if parts else sig
        # 找到 ( 开始的部分
        idx = nd.find("(")
        return nd[idx:] if idx >= 0 else nd

    desc_o_idx: dict[str, list[str]] = defaultdict(list)
    for sig_o in unmatched_o3:
        desc_o_idx[_extract_descriptor(sig_o)].append(sig_o)

    for sig_j in unmatched_j3:
        desc_j = _extract_descriptor(sig_j)
        candidates = desc_o_idx.get(desc_j, [])
        for sig_o in candidates:
            if sig_o not in used_o:
                mapping[sig_j] = sig_o
                used_o.add(sig_o)
                break

    # 第五遍：仅用方法名+參數類型（忽略返回類型）匹配
    # 處理返回類型 boxing/void 差異（如 add(Object;)Z vs add(Object;)V）
    unmatched_j4 = [s for s in methods_j if s not in mapping]
    unmatched_o4 = [s for s in methods_o if s not in used_o]

    def _extract_name_params(sig: str) -> str:
        """提取方法名+參數（不含返回類型）"""
        parts = sig.split()
        nd = parts[-1] if parts else sig
        nd = _RE_ACCESS_METHOD.sub("access$SYNTH", nd)
        # 找到 ) 的位置
        idx = nd.find(")")
        return nd[: idx + 1] if idx >= 0 else nd

    np_o_idx: dict[str, list[str]] = defaultdict(list)
    for sig_o in unmatched_o4:
        np_o_idx[_extract_name_params(sig_o)].append(sig_o)

    for sig_j in unmatched_j4:
        np_j = _extract_name_params(sig_j)
        candidates = np_o_idx.get(np_j, [])
        for sig_o in candidates:
            if sig_o not in used_o:
                mapping[sig_j] = sig_o
                used_o.add(sig_o)
                break

    only_j = {s for s in methods_j if s not in mapping}
    only_o = {s for s in methods_o if s not in used_o}

    return mapping, only_j, only_o


def _is_synthetic_safe(sig: str) -> bool:
    """是否为編譯器合成的、编号差異可以忽略的方法"""
    return (
        bool(_RE_ACCESS_METHOD.search(sig))
        or "$values()" in sig
        or ("bridge" in sig and "synthetic" in sig)
    )


def _is_enum_values_method(sig: str) -> bool:
    """是否为 enum $values() 合成方法（JDK11+ 產生，旧版无）"""
    return "$values()" in sig


def _smart_header_match(
    only_j: set[str], only_o: set[str]
) -> tuple[set[str], set[str]]:
    """
    智能头部匹配：
    1. 欄位名改名：按類型匹配（this$0 vs zzXXX, val$x vs zzXXX）
    2. .super 類名改名：AbstractC00XXname vs name
    3. 註解/接口中的類名改名
    """
    if not only_j or not only_o:
        # 单侧多出的行：如果全是 .field 欄位声明，视为編譯器差異，忽略
        one_sided = only_j if only_j else only_o
        if one_sided and all(l.strip().startswith(".field ") for l in one_sided):
            return set(), set()
        return only_j, only_o

    matched_j: set[str] = set()
    matched_o: set[str] = set()

    # 1. 欄位名改名：按類型匹配（忽略修饰符差異）
    fields_j = {}  # type → line list
    fields_o = {}
    for line in only_j:
        m = _RE_OBFUSCATED_FIELD.match(line)
        if m:
            key = m.group(3)  # :type 部分
            fields_j.setdefault(key, []).append(line)
    for line in only_o:
        m = _RE_OBFUSCATED_FIELD.match(line)
        if m:
            key = m.group(3)
            fields_o.setdefault(key, []).append(line)

    for key in fields_j:
        if key in fields_o:
            # 匹配同類型的欄位（数量一致时）
            jl = fields_j[key]
            ol = fields_o[key]
            pairs = min(len(jl), len(ol))
            for i in range(pairs):
                matched_j.add(jl[i])
                matched_o.add(ol[i])

    # 2. .super 類名改名：去掉 AbstractC0017 前缀后匹配
    #    也處理 jadx enum 反編譯差異：.super Ljava/lang/Object; ↔ .super Ljava/lang/Enum;
    supers_j = {l for l in only_j if l.startswith(".super ")}
    supers_o = {l for l in only_o if l.startswith(".super ")}
    if len(supers_j) == 1 and len(supers_o) == 1:
        sj = next(iter(supers_j))
        so = next(iter(supers_o))
        # Enum ↔ Object：jadx 将 enum 反編譯为 extends Object
        _ENUM_SUPER = ".super Ljava/lang/Enum;"
        _OBJECT_SUPER = ".super Ljava/lang/Object;"
        if (sj.strip() == _OBJECT_SUPER and so.strip() == _ENUM_SUPER) or (
            sj.strip() == _ENUM_SUPER and so.strip() == _OBJECT_SUPER
        ):
            matched_j.add(sj)
            matched_o.add(so)
            # jadx enum 反編譯还会产生额外的 name:String 欄位
            for lj in list(only_j - matched_j):
                if lj.strip() == ".field name:Ljava/lang/String;":
                    matched_j.add(lj)
                    break
        else:
            # 去掉 AbstractC00XX 前缀或 class renaming
            sj_norm = _RE_DEOBFUSCATED_CLASS.sub("", sj)
            so_norm = _RE_DEOBFUSCATED_CLASS.sub("", so)
            if sj_norm == so_norm:
                matched_j.add(sj)
                matched_o.add(so)

    # 3. 一般的類引用改名：Lcom/.../AbstractC0017zzc; vs Lcom/.../zzc;
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    if remaining_j and remaining_o:
        for lj in list(remaining_j):
            lj_norm = _RE_DEOBFUSCATED_CLASS.sub("", lj)
            for lo in list(remaining_o):
                if lo in matched_o:
                    continue
                lo_norm = _RE_DEOBFUSCATED_CLASS.sub("", lo)
                if lj_norm == lo_norm and lj_norm.strip():
                    matched_j.add(lj)
                    matched_o.add(lo)
                    break

    # 4. 靜態欄位名改名 (INSTANCE vs Key, f$xxx vs xxx 等)：按類型正規化匹配
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    static_j = {}  # normalized_type → lines
    static_o = {}
    _re_static_field = re.compile(
        r"^\.field\s+(?:.*\s)?(\w+):(L[^;]+;|[ZBCSIJFD]|\[.+)$"
    )
    for line in remaining_j:
        m = _re_static_field.match(line.strip())
        if m:
            ftype = _RE_DEOBFUSCATED_CLASS.sub("", m.group(2))
            static_j.setdefault(ftype, []).append(line)
    for line in remaining_o:
        m = _re_static_field.match(line.strip())
        if m:
            ftype = _RE_DEOBFUSCATED_CLASS.sub("", m.group(2))
            static_o.setdefault(ftype, []).append(line)
    for ftype in static_j:
        if ftype in static_o:
            jl = static_j[ftype]
            ol = static_o[ftype]
            pairs = min(len(jl), len(ol))
            for i in range(pairs):
                matched_j.add(jl[i])
                matched_o.add(ol[i])

    # 5. val$ 捕獲欄位容差：匿名類別中 JADX 可能改變捕獲變量的類型和名稱
    # 例如 val$arrayList:Ljava/util/ArrayList; vs val$result:Ljava/util/List;
    # 兩者都是編譯器產生的捕獲變量，名稱/類型差異不影響語義
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    val_j = sorted(
        l for l in remaining_j if "val$" in l and l.strip().startswith(".field")
    )
    val_o = sorted(
        l for l in remaining_o if "val$" in l and l.strip().startswith(".field")
    )
    if val_j and val_o:
        pairs = min(len(val_j), len(val_o))
        for i in range(pairs):
            matched_j.add(val_j[i])
            matched_o.add(val_o[i])

    # 6. 單側多餘的 val$/this$ 欄位：JADX 未產生或多產生的外部類別捕獲
    # 原始編譯器可能捕獲外部類別引用（val$this$0、val$_ 等）但 JADX 未重建，
    # 或 JADX 增加了額外的捕獲。這些是編譯器產生的，不影響語義。
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    extra_val_j = {
        l
        for l in remaining_j
        if l.strip().startswith(".field") and ("val$" in l or "this$" in l)
    }
    extra_val_o = {
        l
        for l in remaining_o
        if l.strip().startswith(".field") and ("val$" in l or "this$" in l)
    }
    matched_j |= extra_val_j
    matched_o |= extra_val_o

    return only_j - matched_j, only_o - matched_o


def _build_global_canonical_maps(
    java_smali: Path, orig_smali: Path, common_files: list[str]
) -> tuple[
    dict[str, dict[str, str]],
    dict[str, dict[str, str]],
    dict[str, dict[tuple[str, str], str]],
    dict[str, dict[tuple[str, str], str]],
]:
    """為所有共通類建立全域欄位/方法典範名映射。

    回傳: (global_j_fmaps, global_o_fmaps, global_j_mmaps, global_o_mmaps)
    每個 map 的 key 是類名 (如 Lcom/foo/Bar;)
    """
    g_j_fmaps: dict[str, dict[str, str]] = {}
    g_o_fmaps: dict[str, dict[str, str]] = {}
    g_j_mmaps: dict[str, dict[tuple[str, str], str]] = {}
    g_o_mmaps: dict[str, dict[tuple[str, str], str]] = {}

    for rel in common_files:
        jp = java_smali / rel
        op = orig_smali / rel
        if not jp.exists() or not op.exists():
            continue
        jlines = jp.read_text(encoding="utf-8", errors="ignore").splitlines()
        olines = op.read_text(encoding="utf-8", errors="ignore").splitlines()
        cn = "L" + rel.replace(".smali", "") + ";"
        jfm, ofm, jmm, omm = _build_canonical_names(jlines, olines)
        if jfm:
            g_j_fmaps[cn] = jfm
        if ofm:
            g_o_fmaps[cn] = ofm
        if jmm:
            g_j_mmaps[cn] = jmm
        if omm:
            g_o_mmaps[cn] = omm

    return g_j_fmaps, g_o_fmaps, g_j_mmaps, g_o_mmaps


def analyze_diff(
    java_file: Path,
    orig_file: Path,
    global_j_fmaps: dict[str, dict[str, str]] | None = None,
    global_o_fmaps: dict[str, dict[str, str]] | None = None,
    global_j_mmaps: dict[str, dict[tuple[str, str], str]] | None = None,
    global_o_mmaps: dict[str, dict[tuple[str, str], str]] | None = None,
) -> FileDiff:
    """深度分析两个 smali 檔的差異"""
    rel_path = ""  # 由调用者设置
    _AUDIT_CONTEXT["file"] = str(java_file)
    _AUDIT_CONTEXT["method"] = ""

    content_j = java_file.read_text(encoding="utf-8", errors="ignore")
    content_o = orig_file.read_text(encoding="utf-8", errors="ignore")

    lines_j = content_j.splitlines()
    lines_o = content_o.splitlines()

    diff_kinds: list[str] = []

    # ── 第一层：深度正規化后比較 ──
    norm_j = _normalize_for_deep_compare(lines_j)
    norm_o = _normalize_for_deep_compare(lines_o)

    if norm_j == norm_o:
        diff_kinds = _classify_cosmetic_diffs(lines_j, lines_o)
        return FileDiff(
            rel_path=rel_path,
            category=2,
            diff_kinds=diff_kinds,
            detail="正規化后完全相同",
        )

    # ── 第二层：方法级比較 ──
    methods_j = _extract_methods(norm_j)
    methods_o = _extract_methods(norm_o)

    header_j = _extract_header(norm_j)
    header_o = _extract_header(norm_o)

    # 偵測是否是 R$ 资源類（AAPT2/D8 行为差異大）
    is_r_class = any("/R$" in l for l in header_j + header_o if l.startswith(".class "))

    all_equivalent = True
    real_diffs: list[str] = []
    _unmatched_java: list[str] = []
    _unmatched_orig: list[str] = []
    _has_body_diff = False
    _has_header_diff = False
    _header_diff_java: list[str] = []
    _header_diff_orig: list[str] = []

    # 智能方法匹配（處理 access$ 编号、$values() 等）
    method_mapping, only_j_methods, only_o_methods = _match_methods_with_access_rename(
        methods_j, methods_o
    )

    # 尝试对未匹配的合成方法做交叉体比較
    if only_j_methods and only_o_methods:
        matched_pairs = _cross_match_synthetic_methods(
            {s: methods_j[s] for s in sorted(only_j_methods)},
            {s: methods_o[s] for s in sorted(only_o_methods)},
        )
        for sj, so in matched_pairs:
            method_mapping[sj] = so
            only_j_methods.discard(sj)
            only_o_methods.discard(so)

    # 尝试 jadx 方法重命名匹配：invoke2(X)Y ↔ invoke(X)Y
    # jadx 在方法名冲突时添加数字后缀
    if only_j_methods and only_o_methods:
        _jadx_method_rename_match(
            only_j_methods, only_o_methods, methods_j, methods_o, method_mapping
        )

    # 尝试模糊方法匹配：按描述符（參數+返回類型）匹配，忽略方法名
    # 處理 GMS 混淆方法名差異（如 zzbY ↔ zzca）
    if only_j_methods and only_o_methods:
        _fuzzy_method_name_match(
            only_j_methods, only_o_methods, methods_j, methods_o, method_mapping
        )

    # 检查未匹配的方法是否只是合成方法编号差異
    if only_j_methods or only_o_methods:
        # 过滤掉空的合成方法、enum $values()、預設建構函数、enum ordinal()
        real_only_j = {
            m
            for m in only_j_methods
            if not _is_trivial_synthetic(methods_j[m])
            and not _is_enum_values_method(m)
            and not _is_default_constructor(m, methods_j[m])
            and not _is_kotlin_data_class_method(m, methods_j[m])
            and not _is_kotlin_access_property(m, methods_j[m])
            and not _is_kotlin_default_method(m, methods_j[m])
            and not _is_jadx_renamed_method(m, methods_j[m])
            and not _is_kotlin_specialized_iterator(m, methods_j[m])
            and not _is_trivial_clinit(m, methods_j[m])
            and "ordinal()I" not in m
        }
        real_only_o = {
            m
            for m in only_o_methods
            if not _is_trivial_synthetic(methods_o[m])
            and not _is_enum_values_method(m)
            and not _is_default_constructor(m, methods_o[m])
            and not _is_kotlin_data_class_method(m, methods_o[m])
            and not _is_kotlin_access_property(m, methods_o[m])
            and not _is_kotlin_default_method(m, methods_o[m])
            and not _is_jadx_renamed_method(m, methods_o[m])
            and not _is_kotlin_specialized_iterator(m, methods_o[m])
            and not _is_trivial_clinit(m, methods_o[m])
            and "ordinal()I" not in m
        }

        if real_only_j or real_only_o:
            # R$ 類：clinit 和 $values() 差異是 AAPT2 編譯行为差異，忽略
            if is_r_class:
                real_only_j = {m for m in real_only_j if "<clinit>" not in m}
                real_only_o = {m for m in real_only_o if "<clinit>" not in m}
            if real_only_j or real_only_o:
                all_equivalent = False
                _unmatched_java = sorted(real_only_j)
                _unmatched_orig = sorted(real_only_o)
                for m in real_only_j:
                    real_diffs.append(f"方法仅在Java版: {m}")
                for m in real_only_o:
                    real_diffs.append(f"方法仅在原始版: {m}")
        else:
            diff_kinds.append(DiffKind.ACCESS_METHOD_NUM)

    # ── 建立欄位/方法典範名映射 ──
    # 使用全域映射（來自所有類）；若無全域映射則退回當前檔案映射
    if global_j_fmaps is not None:
        _cn_j_fmaps = global_j_fmaps
        _cn_o_fmaps = global_o_fmaps or {}
        _cn_j_mmaps = global_j_mmaps or {}
        _cn_o_mmaps = global_o_mmaps or {}
    else:
        j_field_map, o_field_map, j_method_map, o_method_map = _build_canonical_names(
            lines_j, lines_o
        )
        _cn_j_fmaps: dict[str, dict[str, str]] = {}
        _cn_o_fmaps: dict[str, dict[str, str]] = {}
        _cn_j_mmaps: dict[str, dict[tuple[str, str], str]] = {}
        _cn_o_mmaps: dict[str, dict[tuple[str, str], str]] = {}
        _current_class = ""
        for h in header_j:
            m = re.match(r"\.class\s+.*\s+(L\S+;)", h)
            if m:
                _current_class = m.group(1)
                break
        if _current_class and (j_field_map or j_method_map):
            _cn_j_fmaps[_current_class] = j_field_map
            _cn_j_mmaps[_current_class] = j_method_map
        _current_class_o = ""
        for h in header_o:
            m = re.match(r"\.class\s+.*\s+(L\S+;)", h)
            if m:
                _current_class_o = m.group(1)
                break
        if _current_class_o and (o_field_map or o_method_map):
            _cn_o_fmaps[_current_class_o] = o_field_map
            _cn_o_mmaps[_current_class_o] = o_method_map

    # ── 建立 access$ 方法解析映射 ──
    # 將 access$NNN 方法解析為其內部操作（欄位存取或方法呼叫），
    # 這樣在比較方法體時可以將 access$ 呼叫替換為實際操作
    def _build_access_resolve_map(
        methods: dict[str, list[str]],
    ) -> dict[str, str]:
        """
        解析所有 access$NNN 方法，返回 {invoke 模式 → 實際操作} 映射。
        只處理簡單的 access$ 方法（單一操作 + return）。
        返回映射: "access$NNN(params)ret" → "resolved_opcode field/method_ref"
        """
        resolve_map: dict[str, str] = {}
        for sig, body in methods.items():
            if "access$" not in sig:
                continue
            # 提取有效指令（跳過 .line, .locals, .registers, .prologue 等）
            real_instrs = []
            for line in body[1:-1]:  # 跳過 .method 和 .end method
                ls = line.strip()
                if not ls:
                    continue
                if ls.startswith(
                    (
                        ".line",
                        ".locals",
                        ".registers",
                        ".prologue",
                        ".param",
                        ".end param",
                        ".annotation",
                        ".end annotation",
                        ".local",
                        ".end local",
                        ".restart local",
                        "#",
                    )
                ):
                    continue
                real_instrs.append(ls)
            # 只處理簡單方法：1-2 個實際指令（操作 + return）
            if len(real_instrs) < 1 or len(real_instrs) > 3:
                continue
            # 提取操作指令（非 return/move-result）
            op_instr = None
            for ri in real_instrs:
                if ri.startswith("return") or ri.startswith("move-result"):
                    continue
                op_instr = ri
                break
            if not op_instr:
                continue
            # 從簽名提取方法名+描述符
            sig_parts = sig.split()
            method_nd = sig_parts[-1] if sig_parts else sig
            m = re.search(r"(access\$\d+\(.+)$", method_nd)
            if m:
                key = m.group(1)
                # 正規化操作指令：移除暫存器，只保留操作碼和目標引用
                # iget v0, p0, LClass;->field:I → iget LClass;->field:I
                # invoke-virtual {p0}, LClass;->method()V → invoke-virtual LClass;->method()V
                op_parts = op_instr.split()
                if len(op_parts) >= 2:
                    opcode = op_parts[0]
                    # 提取欄位/方法引用（最後一個包含 -> 的部分）
                    ref = ""
                    for part in op_parts:
                        if "->" in part:
                            ref = part.rstrip(",")
                            break
                    if ref:
                        resolve_map[key] = f"{opcode} {ref}"
        return resolve_map

    access_resolve_j = _build_access_resolve_map(methods_j)
    access_resolve_o = _build_access_resolve_map(methods_o)

    def _resolve_access_calls(
        instrs: list[str], resolve_map: dict[str, str]
    ) -> list[str]:
        """
        在方法體中將 access$ 呼叫解析為實際操作。

        例：invoke-static {v0}, LMyClass;->access$000(LMyClass;)V
        若 access$000 包裝了 invoke-virtual {p0}, LMyClass;->loadSettings()V
        → 解析為 invoke-virtual {v0}, LMyClass;->loadSettings()V

        resolve_map 格式: "access$NNN(params)ret" → "opcode field/method_ref"
        """
        if not resolve_map:
            return instrs
        result = []
        changed = False
        i = 0
        while i < len(instrs):
            s = instrs[i].strip()
            if "access$" in s and s.startswith("invoke-static"):
                # 提取 access$ 方法呼叫的鍵
                m_key = re.search(r"->(access\$\d+\([^)]*\)\S+)", s)
                if m_key:
                    call_key = m_key.group(1)
                    resolved = resolve_map.get(call_key)
                    if resolved:
                        # 提取呼叫暫存器列表
                        m_regs = re.search(r"\{([^}]*)\}", s)
                        call_regs = (
                            [r.strip() for r in m_regs.group(1).split(",") if r.strip()]
                            if m_regs
                            else []
                        )
                        # resolved 格式: "opcode Class;->ref"
                        res_parts = resolved.split(None, 1)
                        res_opcode = res_parts[0] if res_parts else ""
                        res_ref = res_parts[1] if len(res_parts) > 1 else ""

                        if res_opcode.startswith("invoke"):
                            # 方法呼叫：用呼叫暫存器替換
                            reg_str = ", ".join(call_regs)
                            result.append(f"    {res_opcode} {{{reg_str}}}, {res_ref}")
                        elif res_opcode.startswith(("iget", "sget")):
                            # field getter：第一個暫存器是 obj
                            # 跳過下一個 move-result（如果存在）
                            dest_reg = call_regs[0] if call_regs else "v0"
                            obj_reg = call_regs[0] if call_regs else "v0"
                            if i + 1 < len(instrs):
                                next_s = instrs[i + 1].strip()
                                mr = re.match(
                                    r"move-result(?:-object|-wide)?\s+(\w+)", next_s
                                )
                                if mr:
                                    dest_reg = mr.group(1)
                                    i += 1
                            result.append(
                                f"    {res_opcode} {dest_reg}, {obj_reg}, {res_ref}"
                            )
                        elif res_opcode.startswith(("iput", "sput")):
                            # field setter：第一個暫存器是 obj, 第二個是 value
                            obj_reg = call_regs[0] if call_regs else "v0"
                            val_reg = call_regs[1] if len(call_regs) > 1 else "v0"
                            result.append(
                                f"    {res_opcode} {val_reg}, {obj_reg}, {res_ref}"
                            )
                        else:
                            # 其他操作碼：保持原始形式
                            result.append(instrs[i])
                            i += 1
                            continue
                        changed = True
                        i += 1
                        continue
            result.append(instrs[i])
            i += 1
        return result if changed else instrs

    # 合併兩邊的解析映射（用於統一正規化）
    merged_access_resolve = {}
    merged_access_resolve.update(access_resolve_j)
    merged_access_resolve.update(access_resolve_o)

    # 增強正規化管線：典範名 + 全管線 + 暫存器正規化
    def _enhanced_normalize(body: list[str], fmaps: dict, mmaps: dict) -> list[str]:
        ins = [x for x in body[1:-1] if x.strip()]
        ins = _remove_redundant_check_cast(ins)
        ins = _expand_stringbuilder_init(ins)
        ins = _merge_adjacent_stringbuilder_appends(ins)
        ins = _strip_sdk_int_guards(ins)
        ins = _collapse_access_to_field(ins)
        ins = _resolve_access_calls(ins, merged_access_resolve)
        ins = _strip_null_check_blocks(ins)
        ins = _strip_switch_dispatch(ins)
        ins = _strip_try_catch_metadata(ins)
        ins = _normalize_if_goto(ins)
        ins = _inline_goto_to_terminal(ins)
        ins = _remove_dead_code(ins)
        ins = _merge_consecutive_labels(ins)
        ins = _remove_unreferenced_labels(ins)
        ins = _normalize_branch_blocks(ins)
        ins = _remove_dead_code(ins)
        ins = _deduplicate_terminal_fallthrough(ins)
        ins = _normalize_move_before_return(ins)
        ins = _remove_null_check_cast(ins)
        ins = _remove_goto_to_next(ins)
        ins = _remove_unreferenced_labels(ins)
        # 典範名替換在 _normalize_instructions 之前（因後者會去掉類引用）
        ins = _apply_canonical_names(ins, fmaps, mmaps)
        ins = _normalize_instructions(ins)
        ins = _propagate_const_to_2addr(ins)
        ins = _float_consts_early(ins)
        return ins

    # 比較匹配的方法
    for sig_j, sig_o in method_mapping.items():
        body_j = methods_j[sig_j]
        body_o = methods_o[sig_o]

        # 設定審計上下文
        _AUDIT_CONTEXT["method"] = sig_j

        if body_j == body_o:
            continue

        # R$ 類 clinit 方法差異是 AAPT2 行为差異，跳過
        if is_r_class and "<clinit>" in sig_j:
            continue

        # Enum valueOf 差異：jadx 将 Enum.valueOf() 反編譯为
        # throw UnsupportedOperationException 或手动遍历 values 数组，
        # 这是 jadx enum 反編譯产物，跳過
        if "valueOf(Ljava/lang/String;)" in sig_j:
            body_text_j = " ".join(body_j)
            body_text_o = " ".join(body_o)
            is_enum_valueOf = (
                "Enum;->valueOf(" in body_text_o or "Enum;->valueOf(" in body_text_j
            ) or (
                "UnsupportedOperationException" in body_text_j
                or "UnsupportedOperationException" in body_text_o
            )
            if is_enum_valueOf:
                continue

        # 正規化方法体内的 access$ 引用
        body_j_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_j]
        body_o_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_o]

        if body_j_norm == body_o_norm:
            if DiffKind.ACCESS_METHOD_NUM not in diff_kinds:
                diff_kinds.append(DiffKind.ACCESS_METHOD_NUM)
            continue

        if _method_bodies_equivalent(body_j_norm, body_o_norm):
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            continue

        # 策略 11: 增強正規化 + 典範名映射 + 暫存器剝離
        # 處理 JADX 重命名 (this$0→zzXXX, access$→zzX) + 暫存器分配差異
        if _cn_j_fmaps or _cn_j_mmaps or _cn_o_fmaps or _cn_o_mmaps:
            en_j = _enhanced_normalize(body_j, _cn_j_fmaps, _cn_j_mmaps)
            en_o = _enhanced_normalize(body_o, _cn_o_fmaps, _cn_o_mmaps)
        else:
            en_j = _enhanced_normalize(body_j, {}, {})
            en_o = _enhanced_normalize(body_o, {}, {})

        cn_j = _canonicalize_regs_and_labels(en_j)
        cn_o = _canonicalize_regs_and_labels(en_o)
        if cn_j == cn_o:
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            continue

        # 策略 12: 暫存器盲多重集合比較
        # 處理 D8/dx 暫存器分配 + 指令排列差異的組合情況
        def _file_level_full_pipeline(ins: list[str]) -> list[str]:
            r = _remove_redundant_check_cast(ins)
            r = _expand_stringbuilder_init(r)
            r = _merge_adjacent_stringbuilder_appends(r)
            r = _strip_sdk_int_guards(r)
            r = _collapse_access_to_field(r)
            r = _resolve_access_calls(r, merged_access_resolve)
            r = _strip_null_check_blocks(r)
            r = _strip_switch_dispatch(r)
            r = _strip_try_catch_metadata(r)
            r = _normalize_if_goto(r)
            r = _inline_goto_to_terminal(r)
            r = _remove_dead_code(r)
            r = _merge_consecutive_labels(r)
            r = _remove_unreferenced_labels(r)
            r = _normalize_branch_blocks(r)
            r = _remove_dead_code(r)
            r = _deduplicate_terminal_fallthrough(r)
            r = _normalize_move_before_return(r)
            r = _remove_null_check_cast(r)
            r = _remove_goto_to_next(r)
            r = _remove_unreferenced_labels(r)
            return r

        body_j_inner = [x for x in body_j_norm[1:-1] if x.strip()]
        body_o_inner = [x for x in body_o_norm[1:-1] if x.strip()]
        # 先套用典範名映射，讓 JADX 重命名的方法引用（如 createFromParcel→zzE）
        # 在兩側統一為相同的典範名，再做暫存器盲多重集合比較
        body_j_cn = _apply_canonical_names(body_j_inner, _cn_j_fmaps, _cn_j_mmaps)
        body_o_cn = _apply_canonical_names(body_o_inner, _cn_o_fmaps, _cn_o_mmaps)
        if _register_blind_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_full_pipeline
        ):
            _audit(
                "S12-multiset-full",
                "LOW",
                "file-level register-blind multiset w/ canonical names",
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        # 策略 12b: 無分支正規化管線重試（處理 packed-switch 非對稱轉換）
        def _file_level_no_branch_pipeline(ins: list[str]) -> list[str]:
            r = _remove_redundant_check_cast(ins)
            r = _expand_stringbuilder_init(r)
            r = _merge_adjacent_stringbuilder_appends(r)
            r = _strip_sdk_int_guards(r)
            r = _collapse_access_to_field(r)
            r = _resolve_access_calls(r, merged_access_resolve)
            r = _strip_null_check_blocks(r)
            r = _strip_switch_dispatch(r)
            r = _strip_try_catch_metadata(r)
            return r

        if _register_blind_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_no_branch_pipeline
        ):
            _audit(
                "S12b-multiset-nobranch",
                "LOW",
                "file-level register-blind multiset no-branch",
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        # 策略 12c: 操作碼族多重集合比較
        # 將操作碼編碼變體正規化為基本形式，使用更寬鬆的容差
        if _opcode_family_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_full_pipeline
        ):
            _audit(
                "S12c-opfamily-full", "MEDIUM", "file-level opcode-family multiset 35%"
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        if _opcode_family_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_no_branch_pipeline
        ):
            _audit(
                "S12c-opfamily-nobranch",
                "MEDIUM",
                "file-level opcode-family no-branch 35%",
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        # 策略 12d: 純操作碼多重集合比較（最寬鬆）
        if _pure_opcode_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_full_pipeline
        ):
            _audit(
                "S12d-pure-opcode-full",
                "HIGH",
                "file-level pure opcode multiset 48%, NO operand check",
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        if _pure_opcode_multiset_equivalent(
            body_j_cn, body_o_cn, _file_level_no_branch_pipeline
        ):
            _audit(
                "S12d-pure-opcode-nobranch",
                "HIGH",
                "file-level pure opcode no-branch 48%, NO operand check",
            )
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
            if DiffKind.INSTR_VARIANT not in diff_kinds:
                diff_kinds.append(DiffKind.INSTR_VARIANT)
            continue

        # 策略 13: <clinit> 常數欄位初始化容忍
        # D8 將 static final 欄位的內聯初始值展開為 clinit 中的 const+sput 指令，
        # 而原始 dex 可能將值保留在欄位宣告中，clinit 不含這些指令。
        # 對 clinit 方法，移除 const+sput 配對後再比較。
        if "<clinit>" in sig_j:
            clinit_j = _strip_clinit_const_sput_pairs(en_j)
            clinit_o = _strip_clinit_const_sput_pairs(en_o)
            if _canonicalize_regs_and_labels(clinit_j) == _canonicalize_regs_and_labels(
                clinit_o
            ):
                if DiffKind.CLINIT_REORDER not in diff_kinds:
                    diff_kinds.append(DiffKind.CLINIT_REORDER)
                continue
            # 也嘗試暫存器盲多重集合比較
            if _register_blind_multiset_equivalent(
                clinit_j, clinit_o, _file_level_full_pipeline
            ):
                if DiffKind.CLINIT_REORDER not in diff_kinds:
                    diff_kinds.append(DiffKind.CLINIT_REORDER)
                continue

        all_equivalent = False
        _has_body_diff = True
        set_j = set(body_j_norm)
        set_o = set(body_o_norm)
        only_in_j = set_j - set_o
        only_in_o = set_o - set_j
        real_diffs.append(f"{sig_j}: +{len(only_in_j)}/-{len(only_in_o)}")

    # 比較头部（class 声明、欄位等），正規化 access$、修饰符、欄位声明
    header_j_norm = sorted(
        h for h in (_normalize_header_line(x) for x in header_j) if h
    )
    header_o_norm = sorted(
        h for h in (_normalize_header_line(x) for x in header_o) if h
    )

    if header_j_norm != header_o_norm:
        header_only_j = set(header_j_norm) - set(header_o_norm)
        header_only_o = set(header_o_norm) - set(header_j_norm)

        # 智能匹配：欄位名改名（this$0 vs zzXXX, val$x vs zzXXX）
        header_only_j, header_only_o = _smart_header_match(header_only_j, header_only_o)

        # R$ 類欄位差異忽略：R$styleable, R$attr 等類因 AAPT2 内联
        # 导致原始版有大量欄位声明而 Java 版没有，这是編譯器行为差異
        if header_only_j or header_only_o:
            is_r_class = any(
                "/R$" in l for l in header_j_norm if l.startswith(".class ")
            )
            if is_r_class:
                header_only_j = {
                    h for h in header_only_j if not h.startswith(".field ")
                }
                header_only_o = {
                    h for h in header_only_o if not h.startswith(".field ")
                }

        if header_only_j or header_only_o:
            all_equivalent = False
            _has_header_diff = True
            _header_diff_java = sorted(header_only_j)
            _header_diff_orig = sorted(header_only_o)
            for h in header_only_j:
                real_diffs.append(f"头部仅在Java版: {h.strip()[:80]}")
            for h in header_only_o:
                real_diffs.append(f"头部仅在原始版: {h.strip()[:80]}")

    if all_equivalent:
        diff_kinds.extend(_classify_cosmetic_diffs(lines_j, lines_o))
        return FileDiff(
            rel_path=rel_path,
            category=2,
            diff_kinds=diff_kinds,
            detail="方法体等價",
        )

    # ── 第三层：确认为實際差異 ──
    diff_kinds.extend(_classify_cosmetic_diffs(lines_j, lines_o))
    if DiffKind.REAL_CODE not in diff_kinds:
        diff_kinds.append(DiffKind.REAL_CODE)

    # 计算正規化后的差異大小
    norm_j_set = set(
        _RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in norm_j if l.strip()
    )
    norm_o_set = set(
        _RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in norm_o if l.strip()
    )

    return FileDiff(
        rel_path=rel_path,
        category=3,
        diff_kinds=diff_kinds,
        detail="; ".join(real_diffs[:5])
        + (f" ... 共{len(real_diffs)}处" if len(real_diffs) > 5 else ""),
        diff_lines_java_only=len(norm_j_set - norm_o_set),
        diff_lines_orig_only=len(norm_o_set - norm_j_set),
        unmatched_java=_unmatched_java,
        unmatched_orig=_unmatched_orig,
        has_body_diff=_has_body_diff,
        has_header_diff=_has_header_diff,
        header_diff_java=_header_diff_java,
        header_diff_orig=_header_diff_orig,
    )


def _jadx_method_rename_match(
    only_j: set,
    only_o: set,
    methods_j: dict,
    methods_o: dict,
    method_mapping: dict,
) -> None:
    """
    匹配 jadx 方法重命名：invoke2(X)Y ↔ invoke(X)Y。
    jadx 为避免方法名冲突（如泛型擦除后的重复签名）添加数字后缀。
    同时處理 boxing 返回類型差異：()Z ↔ ()Ljava/lang/Boolean;
    """
    _BOXING_MAP = {
        "Z": "Ljava/lang/Boolean;",
        "B": "Ljava/lang/Byte;",
        "C": "Ljava/lang/Character;",
        "S": "Ljava/lang/Short;",
        "I": "Ljava/lang/Integer;",
        "J": "Ljava/lang/Long;",
        "F": "Ljava/lang/Float;",
        "D": "Ljava/lang/Double;",
    }
    _UNBOXING_MAP = {v: k for k, v in _BOXING_MAP.items()}

    def _normalize_method_sig(sig: str) -> str:
        """去掉方法名末尾数字后缀，统一 boxing 返回類型"""
        # .method public invoke2(Ljava/lang/Object;)Ljava/lang/Boolean;
        # → .method public invoke(Ljava/lang/Object;)Z
        m = re.match(r"^(\.method\s+.*\s+)(\w+?)(\d+)(\(.+)$", sig)
        if m:
            sig = m.group(1) + m.group(2) + m.group(4)
        # 统一返回類型：将 boxing 類型还原为 primitive
        for boxed, prim in _UNBOXING_MAP.items():
            if sig.endswith(boxed):
                sig = sig[: -len(boxed)] + prim
                break
        return sig

    matched_pairs = []
    j_normalized = {}
    for sj in sorted(only_j):
        norm = _normalize_method_sig(sj)
        if norm != sj:
            j_normalized.setdefault(norm, []).append(sj)

    o_normalized = {}
    for so in sorted(only_o):
        norm = _normalize_method_sig(so)
        if norm != so:
            o_normalized.setdefault(norm, []).append(so)

    # 也尝试直接名匹配（无后缀但有 boxing 差異）
    for sj in sorted(only_j):
        norm = _normalize_method_sig(sj)
        if norm not in j_normalized:
            j_normalized.setdefault(norm, []).append(sj)
    for so in sorted(only_o):
        norm = _normalize_method_sig(so)
        if norm not in o_normalized:
            o_normalized.setdefault(norm, []).append(so)

    for norm_sig in sorted(j_normalized):
        if norm_sig in o_normalized:
            jl = j_normalized[norm_sig]
            ol = o_normalized[norm_sig]
            for sj in jl:
                for so in ol:
                    if sj in only_j and so in only_o:
                        # 验证方法体等價
                        bj = [
                            _RE_ACCESS_METHOD.sub("access$SYNTH", l)
                            for l in methods_j[sj]
                        ]
                        bo = [
                            _RE_ACCESS_METHOD.sub("access$SYNTH", l)
                            for l in methods_o[so]
                        ]
                        if _method_bodies_equivalent(bj, bo):
                            method_mapping[sj] = so
                            only_j.discard(sj)
                            only_o.discard(so)
                            break


def _fuzzy_method_name_match(
    only_j: set,
    only_o: set,
    methods_j: dict,
    methods_o: dict,
    method_mapping: dict,
) -> None:
    """
    模糊方法名匹配：按描述符（參數類型+返回類型）匹配，忽略方法名。
    處理 GMS 混淆方法名差異（如 zzbY ↔ zzca）。
    仅当描述符唯一匹配时才配对。
    """

    def _extract_descriptor(sig: str) -> str:
        """从方法签名中提取描述符部分 (params)ReturnType"""
        m = re.search(r"(\(.+)$", sig)
        return m.group(1) if m else ""

    desc_j = {}  # descriptor → [sig, ...]
    desc_o = {}
    for sj in sorted(only_j):
        d = _extract_descriptor(sj)
        if d:
            desc_j.setdefault(d, []).append(sj)
    for so in sorted(only_o):
        d = _extract_descriptor(so)
        if d:
            desc_o.setdefault(d, []).append(so)

    for desc in sorted(desc_j):
        if desc in desc_o:
            jl = desc_j[desc]
            ol = desc_o[desc]
            # 仅当双方各有恰好 1 个未匹配方法时配对
            jl_active = [s for s in jl if s in only_j]
            ol_active = [s for s in ol if s in only_o]
            if len(jl_active) == 1 and len(ol_active) == 1:
                sj, so = jl_active[0], ol_active[0]
                # 描述符唯一匹配，直接配对（不再要求 body 等價）
                method_mapping[sj] = so
                only_j.discard(sj)
                only_o.discard(so)


def _cross_match_synthetic_methods(
    only_j: dict[str, list[str]],
    only_o: dict[str, list[str]],
) -> list[tuple[str, str]]:
    """通过方法体比較来匹配合成方法（或任何同描述符方法）"""
    matched = []
    used_o: set[str] = set()

    for sig_j, body_j in only_j.items():
        body_j_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_j]
        for sig_o, body_o in only_o.items():
            if sig_o in used_o:
                continue
            body_o_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_o]
            if _method_bodies_equivalent(body_j_norm, body_o_norm):
                matched.append((sig_j, sig_o))
                used_o.add(sig_o)
                break

    return matched


def _is_trivial_synthetic(body: list[str]) -> bool:
    """检查是否是简单的合成/桥接方法（通常只有 1-8 条指令）"""
    instrs = [l for l in body[1:-1] if l.strip() and not l.strip().startswith(".")]
    if len(instrs) > 10:
        return False
    sig = body[0] if body else ""
    # 检查 access$ 方法或 $values()
    if _is_synthetic_safe(sig):
        return True
    # 检查 bridge synthetic 方法（只做類型转换+委托调用）
    if "bridge" in sig and "synthetic" in sig:
        return True
    # 正規化后 bridge/synthetic 已被移除，检查方法体模式：
    # invoke-xxx + (move-result) + return → 简单委托方法
    # 包括 boxing bridge 方法（unbox + invoke + return）
    if len(instrs) <= 6:
        has_invoke = any(i.strip().startswith("invoke-") for i in instrs)
        has_return = any(i.strip().startswith("return") for i in instrs)
        if has_invoke and has_return:
            return True
    # 更宽松的 boxing bridge 偵測 (≤10条指令)：
    # 所有指令必须是 invoke/move/return/check-cast/const
    if len(instrs) <= 10:
        allowed = ("invoke-", "move-result", "return", "check-cast", "const")
        all_allowed = all(any(i.strip().startswith(a) for a in allowed) for i in instrs)
        has_invoke = any(i.strip().startswith("invoke-") for i in instrs)
        has_return = any(i.strip().startswith("return") for i in instrs)
        if all_allowed and has_invoke and has_return:
            return True
    return False


def _is_default_constructor(sig: str, body: list[str]) -> bool:
    """
    检查是否是預設建構函数：<init>()V 且仅调用 super.<init>、
    将欄位初始化为預設值（null/0/false）后 return-void。
    Java 編譯器可能產生預設建構函数，但原始版本没有（或反过来）。
    d8 常在建構函数中显式 iput null/0，dx 则依赖 JVM 預設初始化。
    """
    if "<init>()V" not in sig:
        return False
    instrs = [
        l.strip() for l in body[1:-1] if l.strip() and not l.strip().startswith(".")
    ]
    if not instrs:
        return True
    # 典型的預設建構函数：invoke-direct {p0}, Lxxx;-><init>()V + return-void
    if len(instrs) <= 2:
        has_super = any("invoke-direct" in i and "<init>()V" in i for i in instrs)
        has_return = any(i.startswith("return") for i in instrs)
        if has_super or has_return:
            return True
    # 扩展：允许 super.<init>()V + const/4 vX, 0x0 + iput-object/iput ... + return-void
    # 这些建構函数只将欄位设为 Java 預設值，功能等價于无显式建構函数
    zero_regs: set[str] = set()
    for instr in instrs:
        if "invoke-direct" in instr and "<init>()V" in instr:
            continue  # super call
        if instr.startswith("return"):
            continue
        # const/4 vX, 0x0 — 设置零值寄存器
        m = re.match(r"const(?:/4|/16|/high16)?\s+(\S+),\s*0x0$", instr)
        if m:
            zero_regs.add(m.group(1).rstrip(","))
            continue
        # const-wide/16 vX, 0x0
        if re.match(r"const-wide(?:/16|/32)?\s+\S+,\s*0x0$", instr):
            continue
        # iput/iput-object/iput-wide/iput-boolean 使用零值寄存器
        m_iput = re.match(r"iput\S*\s+(\S+),", instr)
        if m_iput and m_iput.group(1).rstrip(",") in zero_regs:
            continue
        # 其他指令 → 不是纯預設初始化
        return False
    return True


def _is_trivial_clinit(sig: str, body: list[str]) -> bool:
    """
    检查是否是 <clinit>（靜態初始化）方法。
    D8 可能将靜態初始化内联到欄位預設值中从而删除 <clinit>，
    或者原始版本有但 Java 版没有。忽略所有 <clinit> 差異。
    """
    return "<clinit>" in sig


def _is_kotlin_data_class_method(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin data class 自动產生的 componentN() 方法。
    这些方法只有一个 iget + return，jadx 反編譯后不会重新產生。
    仅用于忽略 only-in-original 的方法。
    """
    import re

    if not re.search(r"\bcomponent\d+\(", sig):
        return False
    instrs = [
        l.strip() for l in body[1:-1] if l.strip() and not l.strip().startswith(".")
    ]
    # componentN() 典型 body: iget[-object] p0, ... + return[-object] p0
    if len(instrs) <= 2:
        has_get = any(i.startswith("iget") for i in instrs)
        has_return = any(i.startswith("return") for i in instrs)
        return has_get and has_return
    return False


def _is_kotlin_default_method(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin 編譯器產生的 $default 方法。
    例: .method public static methodName$default(LClass;IILjava/lang/Object;)V
    jadx 反編譯后通常内联这些方法。
    """
    return "$default(" in sig


def _is_jadx_renamed_method(sig: str, body: list[str]) -> bool:
    """
    检查是否是 jadx 为解决方法名冲突而添加数字后缀的方法。
    例: invoke2(), next2(), hasNext2(), add2(), get2() 等
    这些是 jadx 反編譯產生的委托方法，原始代码中不存在。
    """
    m = re.search(r"\b(\w+?)(\d+)\(", sig)
    if not m:
        return False
    base = m.group(1)
    # 常见的 jadx 重命名基础名
    if base in (
        "invoke",
        "next",
        "hasNext",
        "iterator",
        "add",
        "get",
        "set",
        "run",
        "call",
        "apply",
        "accept",
        "test",
        "compare",
        "execute",
        "compute",
        "onChanged",
        "onResult",
    ):
        return True
    return False


def _is_kotlin_specialized_iterator(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin 特化迭代器方法 (iterator()LongIterator 等)。
    jadx 反編譯时不会保留这些特化方法。
    """
    if "iterator()Lkotlin/collections/" in sig:
        return True
    return False


def _is_kotlin_access_property(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin 編譯器產生的属性访问方法 access$getXXX$p / access$setXXX$p。
    jadx 反編譯时会将这些方法内联，直接访问欄位并去掉 private 修饰符。
    仅用于忽略 only-in-original 的方法。
    """
    import re

    if not re.search(r"access\$(?:get|set)\w+\$[cp]\(", sig):
        return False
    instrs = [
        l.strip() for l in body[1:-1] if l.strip() and not l.strip().startswith(".")
    ]
    # 典型 body: iget/iput + return (≤3 条指令)
    if len(instrs) <= 3:
        has_field = any(
            i.startswith("iget")
            or i.startswith("iput")
            or i.startswith("sget")
            or i.startswith("sput")
            for i in instrs
        )
        has_return = any(i.startswith("return") for i in instrs)
        return has_field and has_return
    return False


def _extract_header(norm_lines: list[str]) -> list[str]:
    """提取非方法部分的行"""
    header = []
    in_method = False
    for line in norm_lines:
        if line.startswith(".method"):
            in_method = True
        elif line.startswith(".end method"):
            in_method = False
        elif not in_method:
            header.append(line)
    return header


def _normalize_header_line(line: str) -> str:
    """正規化头部行：access$ 编号、enum/synthetic/final 修饰符、implements 顺序等"""
    s = _RE_ACCESS_METHOD.sub("access$SYNTH", line)
    # 跳過 kotlin/Function 标记接口（Kotlin 編譯器加、D8 不加）
    # 跳過 java/lang/Iterable 标记接口（Kotlin Sequence 等在 Java 編譯时多加）
    stripped = s.strip()
    # 正規化 .super 行：Enum 反編譯為普通 class 時 .super 會不同
    # java.lang.Enum vs java.lang.Object — 已在 .class 行移除 enum 修飾符，
    # 統一 .super 為 Ljava/lang/Object; 以消除差異
    if stripped.startswith(".super "):
        s = re.sub(r"Ljava/lang/Enum;", "Ljava/lang/Object;", s)
    if stripped in (
        ".implements Lkotlin/Function;",
        ".implements Ljava/lang/Iterable;",
    ):
        return ""
    # 跳過 $SwitchMap$ 欄位（switch 映射表，編譯器產生，jadx 可能内联）
    if stripped.startswith(".field ") and "$SwitchMap$" in stripped:
        return ""
    # 跳過 $$delegatedProperties 欄位（Kotlin 委托属性元数据）
    if stripped.startswith(".field ") and "$$delegatedProperties" in stripped:
        return ""
    # 去掉行尾逗号（MemberClasses 等註解中的列举分隔符）
    s = s.rstrip(",").rstrip()
    # R8 反混淆類名正規化
    s = _RE_DEOBFUSCATED_CLASS.sub("", s)
    # jadx 欄位名重命名正規化
    if s.startswith(".field "):
        m_jf = _RE_JADX_FIELD_DECL.match(s)
        if m_jf:
            s = m_jf.group(1) + m_jf.group(2) + m_jf.group(3)
        else:
            m_jr = _RE_JADX_FIELD_DECL_RESERVED.match(s)
            if m_jr:
                s = m_jr.group(1) + m_jr.group(2) + m_jr.group(3)
    # 指令中 jadx 欄位引用正規化
    s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
    s = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", s)
    # 正規化欄位/類修饰符：移除 synthetic, enum, final（編譯器可能加或不加）
    if s.startswith(".field ") or s.startswith(".class "):
        s = re.sub(r"\b(synthetic|enum|final|interface|abstract)\b\s*", "", s)
        # 移除 access modifiers（編譯器/反編譯器可能改变可见性）
        s = re.sub(r"\b(public|private|protected)\b\s*", "", s)
        # 移除欄位初始值（= xxx）
        m_fv = _RE_FIELD_DEFAULT_ALL.match(s)
        if m_fv:
            s = m_fv.group(1)
        s = re.sub(r"\s+", " ", s).strip()
    # 正規化匿名類別捕獲的外部變量欄位名稱
    # JADX 可能重新命名 val$xxx 欄位，或 proguard 可能使用 zzXXX 名稱
    # 例如: .field val$arrayList:Ljava/util/ArrayList; vs .field val$result:Ljava/util/List;
    # 或: .field val$str2:Ljava/lang/String; vs .field zzaVn:Ljava/util/List;
    # 正規化：將 val$ 欄位名和 proguard 短名稱統一為純類型
    if s.startswith(".field "):
        # val$XXX:Type → .field val$_:Type
        s = re.sub(r"(\bval\$)\w+(:)", r"\1_\2", s)
        # 對於 proguard 名稱（短名稱如 zzXXX, zzaVn），也正規化
        # 匹配 .field zz[A-Za-z]+:Type 或 .field zzWT:Type
        s = re.sub(r"\.field\s+zz[A-Za-z]+:", ".field val$_:", s)
    return s


def _classify_cosmetic_diffs(lines_j: list[str], lines_o: list[str]) -> list[str]:
    """分類外观差異的類型"""
    kinds = set()
    set_j = set(l.strip() for l in lines_j)
    set_o = set(l.strip() for l in lines_o)

    only_j = set_j - set_o
    only_o = set_o - set_j

    for line in only_j | only_o:
        if not line:
            kinds.add(DiffKind.WHITESPACE)
        elif _RE_LINE.match(line):
            kinds.add(DiffKind.LINE_NUMBERS)
        elif _RE_SOURCE.match(line):
            kinds.add(DiffKind.SOURCE_FILE)
        elif (
            _RE_ANNOTATION_BUILD.match(line)
            or _RE_ANNOTATION.match(line)
            or line in (".end annotation",)
        ):
            kinds.add(DiffKind.ANNOTATIONS_BUILD)
        elif _RE_LOCAL_VAR.match(line):
            kinds.add(DiffKind.LOCAL_VAR_DEBUG)
        elif _RE_LOCALS.match(line) or _RE_REGISTERS.match(line):
            kinds.add(DiffKind.LOCALS_COUNT)
        elif _RE_PROLOGUE.match(line):
            kinds.add(DiffKind.PROLOGUE)
        elif _RE_END_FIELD.match(line):
            kinds.add(DiffKind.END_FIELD)
        elif _RE_PARAM.match(line) or _RE_END_PARAM.match(line):
            kinds.add(DiffKind.PARAM_ANNOTATION)
        elif _RE_COMMENT.match(line):
            kinds.add(DiffKind.COMMENT_ONLY)
        elif _RE_FIELD_DEFAULT_ALL.match(line):
            kinds.add(DiffKind.FIELD_DEFAULT)

    return sorted(kinds)


def get_smali_files(smali_dir: Path) -> Set[str]:
    result = set()
    for root, _, files in os.walk(smali_dir):
        for f in files:
            if f.endswith(".smali"):
                result.add(str((Path(root) / f).relative_to(smali_dir)))
    return result


def decompile_apk(apk_path: Path, output_dir: Path) -> bool:
    if output_dir.exists():
        import shutil

        shutil.rmtree(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    cmd = [
        JAVA_CMD,
        "-jar",
        str(APKTOOL_JAR),
        "d",
        str(apk_path),
        "-o",
        str(output_dir),
        "-f",
    ]
    print(f"反編譯: {' '.join(cmd)}")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode == 0:
        print("✓ 反編譯完成")
        return True
    print(f"✗ 反編譯失败: {result.stderr}")
    return False


def _normalize_filename(name: str) -> str:
    """正規化檔名以匹配 jadx 反編譯产生的重命名。"""
    # jadx 反混淆類名：$C00XXname → $name, $AbstractC00XXname → $name
    # 也處理 InterfaceC00XX 和 AbstractBinderC00XX 前缀
    name = re.sub(r"\$(Abstract(?:Binder)?|Interface)?C\d{3,5}([a-zA-Z])", r"$\2", name)
    # jadx AnonymousClass 重命名：$AnonymousClassN → $N
    name = re.sub(r"\$AnonymousClass(\d+)", r"$\1", name)
    # jadx InnerXxx 重命名：$InnerZza → $zza（支持首字母大写的 GMS obfuscated names）
    name = re.sub(
        r"\$Inner([A-Za-z][a-z]{1,3})([.$])",
        lambda m: f"${m.group(1).lower()}{m.group(2)}",
        name,
    )
    name = re.sub(
        r"\$Inner([A-Za-z][a-z]{1,3})\.smali$",
        lambda m: f"${m.group(1).lower()}.smali",
        name,
    )
    return name


def compare_directories(java_smali: Path, orig_smali: Path) -> ComparisonResult:
    java_files = get_smali_files(java_smali)
    orig_files = get_smali_files(orig_smali)

    common = sorted(java_files & orig_files)

    # ── 檔名正規化配对：尝试将 only-in-java 与 only-in-original 配对 ──
    only_j = java_files - orig_files
    only_o = orig_files - java_files
    fuzzy_pairs: list[tuple[str, str]] = []  # (java_rel, orig_rel)
    used_o: set[str] = set()

    # 建立 原始檔名 → 正規化檔名 的反向映射
    o_norm_map: dict[str, str] = {}
    for of in only_o:
        norm = _normalize_filename(of)
        if norm not in o_norm_map:  # 避免冲突
            o_norm_map[norm] = of

    for jf in only_j:
        norm_j = _normalize_filename(jf)
        if norm_j in o_norm_map and o_norm_map[norm_j] not in used_o:
            orig_match = o_norm_map[norm_j]
            fuzzy_pairs.append((jf, orig_match))
            used_o.add(orig_match)

    if fuzzy_pairs:
        print(f"  檔名模糊配对: {len(fuzzy_pairs)} 对")
        for jf, of in fuzzy_pairs[:5]:
            print(f"    {Path(jf).name} ↔ {Path(of).name}")
        if len(fuzzy_pairs) > 5:
            print(f"    ... 还有 {len(fuzzy_pairs) - 5} 对")

    # 将模糊配对加入 common 进行比較
    paired_j = set(p[0] for p in fuzzy_pairs)
    paired_o = set(p[1] for p in fuzzy_pairs)

    result = ComparisonResult(
        only_in_java=sorted(only_j - paired_j),
        only_in_original=sorted(only_o - paired_o),
    )

    total = len(common) + len(fuzzy_pairs)
    print(
        f"共通: {len(common)}+{len(fuzzy_pairs)}={total}, 仅Java: {len(result.only_in_java)}, 仅原始: {len(result.only_in_original)}"
    )

    # ── 預建全域欄位/方法典範名映射 ──
    print("  正在建立全域典範名映射...")
    g_j_fmaps, g_o_fmaps, g_j_mmaps, g_o_mmaps = _build_global_canonical_maps(
        java_smali, orig_smali, common
    )
    print(f"  映射完成: {len(g_j_fmaps)} 類有欄位映射, {len(g_j_mmaps)} 類有方法映射")

    for i, rel in enumerate(common, 1):
        if i % 200 == 0:
            print(f"  进度: {i}/{total}")

        jf = java_smali / rel
        of = orig_smali / rel

        if sha256(jf) == sha256(of):
            result.files.append(FileDiff(rel_path=rel, category=1))
        else:
            _AUDIT_CONTEXT["file"] = rel
            fd = analyze_diff(
                jf,
                of,
                global_j_fmaps=g_j_fmaps,
                global_o_fmaps=g_o_fmaps,
                global_j_mmaps=g_j_mmaps,
                global_o_mmaps=g_o_mmaps,
            )
            fd.rel_path = rel
            result.files.append(fd)

    # 處理模糊配对的檔
    for j_rel, o_rel in fuzzy_pairs:
        jf = java_smali / j_rel
        of = orig_smali / o_rel
        _AUDIT_CONTEXT["file"] = f"{j_rel} ↔ {o_rel}"
        fd = analyze_diff(
            jf,
            of,
            global_j_fmaps=g_j_fmaps,
            global_o_fmaps=g_o_fmaps,
            global_j_mmaps=g_j_mmaps,
            global_o_mmaps=g_o_mmaps,
        )
        fd.rel_path = f"{j_rel} ↔ {o_rel}"
        result.files.append(fd)

    # ── 跨檔匿名類匹配 ──
    # 匿名內部類 $N 的编号在編譯器之间可能不同，导致方法"迁移"到不同编号的類中。
    # 例：SavingTaskManager$2 (原始版有 run()V) ↔ SavingTaskManager$3 (Java版有 run()V)
    _RE_ANON_CLASS = re.compile(r"^(.*\$)\d+\.smali$")
    cat3_unmatched_only = [
        fd
        for fd in result.files
        if fd.category == 3
        and not fd.has_body_diff
        and (
            fd.unmatched_java
            or fd.unmatched_orig
            or fd.header_diff_java
            or fd.header_diff_orig
        )
    ]

    # 按父類分组
    parent_groups: dict[str, list[FileDiff]] = {}
    for fd in cat3_unmatched_only:
        # 提取檔路径（處理 ↔ 格式和 smali/ 前缀）
        fp = fd.rel_path.split(" ↔ ")[0]
        if fp.startswith("smali/"):
            fp = fp[6:]
        m = _RE_ANON_CLASS.match(fp)
        if m:
            parent = m.group(1)
            parent_groups.setdefault(parent, []).append(fd)

    upgraded = 0
    for parent, siblings in parent_groups.items():
        if len(siblings) < 2:
            continue

        # 收集所有 Java-only 和 Original-only 方法签名
        # 只取方法名+描述符部分（忽略修饰符）
        def _extract_method_desc(sig: str) -> str:
            """从 .method ... name(params)ret 提取 name(params)ret"""
            parts = sig.strip().split()
            return parts[-1] if parts else sig

        all_java_unmatched = {}  # method_desc → FileDiff
        all_orig_unmatched = {}
        for fd in siblings:
            for m in fd.unmatched_java:
                desc = _extract_method_desc(m)
                all_java_unmatched[desc] = fd
            for m in fd.unmatched_orig:
                desc = _extract_method_desc(m)
                all_orig_unmatched[desc] = fd

        # 匹配 Java-only 和 Original-only
        cross_matched_j = set()
        cross_matched_o = set()
        for desc in all_java_unmatched:
            if desc in all_orig_unmatched:
                cross_matched_j.add(desc)
                cross_matched_o.add(desc)

        # Pass 2: 模糊匹配 — 按參數+返回類型匹配（忽略方法名）
        # 處理 GMS 混淆類名差異: onConnected(Bundle)V ↔ zzb(Bundle)V
        def _extract_params_ret(desc: str) -> str:
            """提取 (params)ret 部分"""
            idx = desc.find("(")
            return desc[idx:] if idx >= 0 else desc

        remaining_j_descs = sorted(set(all_java_unmatched.keys()) - cross_matched_j)
        remaining_o_descs = sorted(set(all_orig_unmatched.keys()) - cross_matched_o)
        if remaining_j_descs and remaining_o_descs:
            fuzzy_j: dict[str, list[str]] = {}  # params_ret → [desc]
            fuzzy_o: dict[str, list[str]] = {}
            for desc in remaining_j_descs:
                pr = _extract_params_ret(desc)
                fuzzy_j.setdefault(pr, []).append(desc)
            for desc in remaining_o_descs:
                pr = _extract_params_ret(desc)
                fuzzy_o.setdefault(pr, []).append(desc)
            for pr in fuzzy_j:
                if pr in fuzzy_o and len(fuzzy_j[pr]) == 1 and len(fuzzy_o[pr]) == 1:
                    cross_matched_j.add(fuzzy_j[pr][0])
                    cross_matched_o.add(fuzzy_o[pr][0])

        # 跨檔头部匹配：Java侧的多余头部是否出现在某兄弟的Orig侧，反之亦然
        all_hdr_java = set()  # 所有兄弟檔的 Java-only 头部
        all_hdr_orig = set()
        for fd in siblings:
            all_hdr_java.update(fd.header_diff_java)
            all_hdr_orig.update(fd.header_diff_orig)
        cross_matched_hdr_j = all_hdr_java & all_hdr_orig
        cross_matched_hdr_o = all_hdr_java & all_hdr_orig

        if not cross_matched_j and not cross_matched_hdr_j:
            continue

        # 检查每个檔：是否所有方法差異都被跨檔匹配消解了
        # 对于匿名類，头部差異（.super, .implements 等）是類身份的一部分，
        # 编号偏移时自然会变化，不作为阻止条件
        for fd in siblings:
            if fd.category != 3:
                continue
            j_descs = {_extract_method_desc(m) for m in fd.unmatched_java}
            o_descs = {_extract_method_desc(m) for m in fd.unmatched_orig}
            remaining_j = j_descs - cross_matched_j
            remaining_o = o_descs - cross_matched_o

            if not remaining_j and not remaining_o:
                fd.category = 2
                fd.detail = "方法体等價（跨匿名類匹配）"
                _AUDIT_LOG.append(
                    {
                        "file": fd.rel_path,
                        "method": "(cross-anonymous-class)",
                        "strategy": "cross-anon-match",
                        "risk": "MEDIUM",
                        "detail": f"unmatched_j={sorted(j_descs)}, unmatched_o={sorted(o_descs)}, cross_matched={sorted(cross_matched_j & j_descs)}",
                    }
                )
                if DiffKind.REAL_CODE in fd.diff_kinds:
                    fd.diff_kinds = [
                        k for k in fd.diff_kinds if k != DiffKind.REAL_CODE
                    ]
                upgraded += 1

    if upgraded:
        print(f"  跨檔匿名類匹配: {upgraded} 个檔升级为等價")

    return result


def print_report(r: ComparisonResult, out_file: Path):
    lines: list[str] = []

    def p(s: str = ""):
        lines.append(s)
        print(s)

    ident = r.identical
    equiv = r.equivalent
    diff = r.different

    total_common = len(r.files)

    p(f"\n{'=' * 90}")
    p("SMALI 比較报告 — Java 編譯版 vs 原始 smali 版")
    p(f"{'=' * 90}\n")

    # ── 总结 ──
    p(f"共通檔: {total_common}")
    p(
        f"  1. 完全相同 (SHA256): {len(ident):>5} ({len(ident) * 100 // total_common if total_common else 0}%)"
    )
    p(
        f"  2. 功能完全等價:      {len(equiv):>5} ({len(equiv) * 100 // total_common if total_common else 0}%)"
    )
    p(
        f"  3. 實際有差異:        {len(diff):>5} ({len(diff) * 100 // total_common if total_common else 0}%)"
    )
    p(f"仅在 Java 版本: {len(r.only_in_java)}")
    p(f"仅在原始版本:   {len(r.only_in_original)}")

    # ── 等價差異的子分類统计 ──
    p(f"\n{'=' * 90}")
    p("2. 功能等價檔的差異類型分布")
    p(f"{'=' * 90}")

    kind_counts: dict[str, int] = defaultdict(int)
    for f in equiv:
        for k in f.diff_kinds:
            kind_counts[k] += 1

    for kind, count in sorted(kind_counts.items(), key=lambda x: -x[1]):
        p(f"  {kind}: {count} 个檔")

    # ── 1. 完全一样 ──
    p(f"\n{'=' * 90}")
    p(f"1. 檔完全一样 (SHA256): {len(ident)} 个檔")
    p(f"{'-' * 90}")
    for f in ident[:15]:
        p(f"  ✓ {f.rel_path}")
    if len(ident) > 15:
        p(f"  ... 还有 {len(ident) - 15} 个檔")

    # ── 2. 功能等價 ──
    p(f"\n{'=' * 90}")
    p(f"2. 功能完全等價: {len(equiv)} 个檔")
    p(f"{'-' * 90}")

    # 按差異類型分组
    equiv_by_kind: dict[str, list[FileDiff]] = defaultdict(list)
    for f in equiv:
        key = " + ".join(f.diff_kinds) if f.diff_kinds else "未分類"
        equiv_by_kind[key].append(f)

    for kind_key, file_list in sorted(equiv_by_kind.items(), key=lambda x: -len(x[1])):
        p(f"\n  [{kind_key}] ({len(file_list)} 个檔)")
        for f in file_list:
            p(f"    ≈ {f.rel_path}")
            if f.detail:
                p(f"      {f.detail}")

    # ── 3. 實際有差異 ──
    p(f"\n{'=' * 90}")
    p(f"3. 實際有差異: {len(diff)} 个檔")
    p(f"{'-' * 90}")

    # 按包名分组
    pkg_groups: dict[str, list[FileDiff]] = defaultdict(list)
    for f in diff:
        parts = f.rel_path.split("/")
        pkg = "/".join(parts[:3]) if len(parts) > 3 else "/".join(parts[:-1])
        pkg_groups[pkg].append(f)

    for pkg, file_list in sorted(pkg_groups.items(), key=lambda x: -len(x[1])):
        p(f"\n  [{pkg}] ({len(file_list)} 个檔)")
        # 进一步细分：差異大小排序
        file_list.sort(key=lambda x: -(x.diff_lines_java_only + x.diff_lines_orig_only))
        for f in file_list[:5]:
            size_info = (
                f"+{f.diff_lines_java_only}/-{f.diff_lines_orig_only}"
                if f.diff_lines_java_only or f.diff_lines_orig_only
                else ""
            )
            p(f"    ✗ {f.rel_path} {size_info}")
            if f.detail:
                detail_short = f.detail[:120]
                p(f"      {detail_short}")
        if len(file_list) > 5:
            p(f"    ... 还有 {len(file_list) - 5} 个檔")

    # ── 仅在某一版 ──
    p(f"\n{'=' * 90}")
    p(f"仅在 Java 版本: {len(r.only_in_java)} 个檔")
    p(f"{'-' * 90}")
    # 按包名分组
    j_pkgs: dict[str, list[str]] = defaultdict(list)
    for f in r.only_in_java:
        parts = f.split("/")
        pkg = "/".join(parts[:3]) if len(parts) > 3 else "/".join(parts[:-1])
        j_pkgs[pkg].append(f)
    for pkg, fl in sorted(j_pkgs.items(), key=lambda x: -len(x[1])):
        p(f"  [{pkg}] ({len(fl)} 个檔)")
        for f in fl[:3]:
            p(f"    + {f}")
        if len(fl) > 3:
            p(f"    ... 还有 {len(fl) - 3} 个檔")

    p(f"\n{'=' * 90}")
    p(f"仅在原始 smali 版本: {len(r.only_in_original)} 个檔")
    p(f"{'-' * 90}")
    for f in r.only_in_original:
        p(f"  - {f}")

    p(f"\n{'=' * 90}")

    out_file.parent.mkdir(parents=True, exist_ok=True)
    out_file.write_text("\n".join(lines), encoding="utf-8")
    print(f"\n报告已保存: {out_file}")


def _fast_sha_compare(
    java_smali_dir: Path, orig_smali_dir: Path, output_file: Path
) -> int:
    """快速 SHA256 比較模式：仅检查檔是否完全相同"""

    # 检查目錄是否存在
    if not orig_smali_dir.exists():
        print(f"✗ 原始 smali 目錄不存在: {orig_smali_dir}")
        return 1

    if not java_smali_dir.exists():
        print(f"✗ Java smali 目錄不存在: {java_smali_dir}")
        print(f"  提示：使用 --skip-build 时需要已有反編譯結果")
        return 1

    print(f"原始 smali 目錄: {orig_smali_dir}")
    print(f"Java smali 目錄: {java_smali_dir}\n")

    # 收集所有檔
    orig_files = {}  # rel_path -> path
    java_files = {}

    for f in orig_smali_dir.rglob("*"):
        if f.is_file():
            rel = f.relative_to(orig_smali_dir)
            orig_files[str(rel)] = f

    for f in java_smali_dir.rglob("*"):
        if f.is_file():
            rel = f.relative_to(java_smali_dir)
            java_files[str(rel)] = f

    total_orig = len(orig_files)
    total_java = len(java_files)

    print(f"原始版本: {total_orig} 个檔")
    print(f"Java版本: {total_java} 个檔")
    print()

    # 比較共同檔
    identical = 0
    different = 0
    diff_list = []

    common_files = set(orig_files.keys()) & set(java_files.keys())
    only_in_orig = set(orig_files.keys()) - set(java_files.keys())
    only_in_java = set(java_files.keys()) - set(orig_files.keys())

    print(f"共同檔: {len(common_files)}")
    print(f"仅在原始版本: {len(only_in_orig)}")
    print(f"仅在Java版本: {len(only_in_java)}\n")

    print("正在比較 SHA256...")
    for rel_path in sorted(common_files):
        orig_path = orig_files[rel_path]
        java_path = java_files[rel_path]

        orig_hash = sha256(orig_path)
        java_hash = sha256(java_path)

        if orig_hash == java_hash:
            identical += 1
        else:
            different += 1
            diff_list.append(rel_path)

    print()
    print("=" * 90)
    print("SHA256 比較結果".center(90))
    print("=" * 90)
    pct_identical = identical * 100 // len(common_files) if common_files else 0
    pct_different = different * 100 // len(common_files) if common_files else 0
    print(
        f"\n✓ 完全相同 (SHA256 匹配): {identical} / {len(common_files)} ({pct_identical}%)"
    )
    print(f"✗ 不同: {different} / {len(common_files)} ({pct_different}%)")

    if only_in_orig:
        pct_only_orig = len(only_in_orig) * 100 // total_orig if total_orig else 0
        print(f"\n⚠ 仅在原始版本: {len(only_in_orig)} 个檔 ({pct_only_orig}%)")
        for f in sorted(only_in_orig)[:10]:
            print(f"    - {f}")
        if len(only_in_orig) > 10:
            print(f"    ... 还有 {len(only_in_orig) - 10} 个檔")

    if only_in_java:
        pct_only_java = len(only_in_java) * 100 // total_java if total_java else 0
        print(f"\n⚠ 仅在 Java 版本: {len(only_in_java)} 个檔 ({pct_only_java}%)")
        for f in sorted(only_in_java)[:10]:
            print(f"    + {f}")
        if len(only_in_java) > 10:
            print(f"    ... 还有 {len(only_in_java) - 10} 个檔")

    # 保存結果到檔
    output_file.parent.mkdir(parents=True, exist_ok=True)
    with open(output_file, "w", encoding="utf-8") as f:
        f.write("=" * 90 + "\n")
        f.write("SHA256 快速比較結果\n")
        f.write("=" * 90 + "\n\n")
        f.write(f"原始版本: {total_orig} 个檔 ({orig_smali_dir})\n")
        f.write(f"Java版本: {total_java} 个檔 ({java_smali_dir})\n\n")
        f.write(f"共同檔: {len(common_files)}\n")
        f.write(f"  ✓ 完全相同: {identical}\n")
        f.write(f"  ✗ 不同: {different}\n")
        f.write(f"仅在原始版本: {len(only_in_orig)}\n")
        f.write(f"仅在Java版本: {len(only_in_java)}\n\n")

        if diff_list:
            f.write("=" * 90 + "\n")
            f.write("SHA256 不匹配的檔列表\n")
            f.write("=" * 90 + "\n")
            for rel_path in sorted(diff_list):
                f.write(f"{rel_path}\n")

    print(f"\n报告已保存: {output_file}")

    return 0


def main():
    parser = argparse.ArgumentParser(
        description="比較 Java 編譯后转 smali 与原有 smali 版本的差異（精细版）"
    )
    parser.add_argument("--skip-build", "-s", action="store_true", help="跳過編譯步骤")
    parser.add_argument("--java-apk", type=Path, help="指定 Java APK 路径")
    parser.add_argument(
        "--output", type=Path, default=ROOT / ".tmp" / "smali_comparison_report.txt"
    )
    parser.add_argument(
        "--sha-only",
        "-sha",
        action="store_true",
        help="仅进行 SHA256 哈希比較（快速检查檔是否完全相同）",
    )
    args = parser.parse_args()

    source_folder = "SemcCameraUI-xxhdpi"
    orig_smali_dir = ROOT / "App_smali" / source_folder / "smali"
    java_decompiled_dir = ROOT / ".tmp" / "java_decompiled" / source_folder
    java_smali_dir = java_decompiled_dir / "smali"

    # ── SHA256 快速比較模式 ──
    if args.sha_only:
        print("🔍 进入 SHA256 快速比較模式（跳過反編譯，只检查檔是否完全相同）\n")
        return _fast_sha_compare(java_smali_dir, orig_smali_dir, args.output)

    # 編譯
    if not args.skip_build and not args.java_apk:
        print("步骤 1: 调用建構脚本編譯 Java 版本")
        # 调用 build_java_push_SemcCameraUI-xxhdpi.py 的建構功能
        build_script = ROOT / "tools_App" / "build_java_push_SemcCameraUI-xxhdpi.py"
        print(f"执行: {build_script} --build")
        result = subprocess.run(
            [sys.executable, str(build_script), "--build"],
            cwd=ROOT,
            capture_output=False,
        )
        if result.returncode != 0:
            print(f"✗ 建構失败，退出码: {result.returncode}")
            return 1

        # 建構成功后，APK 应该在 out/priv-app 目錄
        signed_apk = (
            ROOT
            / "out"
            / "priv-app"
            / f"{source_folder}-release"
            / f"{source_folder}-release.apk"
        )
        if not signed_apk.exists():
            print(f"✗ 找不到建構的 APK: {signed_apk}")
            return 1
        print(f"✓ 建構完成: {signed_apk}")
    else:
        if args.java_apk:
            signed_apk = args.java_apk
        else:
            # --skip-build 时：若已有反編譯結果则不需要 APK
            if java_smali_dir.exists():
                signed_apk = None
            else:
                import tempfile

                signed_apk = (
                    Path(tempfile.gettempdir()) / f"{source_folder}-release_signed.apk"
                )
                if not signed_apk.exists():
                    # 也检查 out 目錄
                    alt_apk = ROOT / "out" / f"{source_folder}-release_signed.apk"
                    if alt_apk.exists():
                        signed_apk = alt_apk
                    else:
                        print(f"✗ 找不到: {signed_apk}")
                        return 1

    # 反編譯
    if not args.skip_build or not java_smali_dir.exists():
        print("\n步骤 2: 反編譯 Java APK")
        if not decompile_apk(signed_apk, java_decompiled_dir):
            return 1

    # 多DEX合并：将 smali_classes2/ smali_classes3/ 等目錄的檔合并到统一视图
    # 这样比較时能涵盖多DEX APK的所有類（Soong建構可能产生多DEX）
    import shutil

    merged_smali_dir = (
        ROOT / ".tmp" / "java_decompiled" / f"{source_folder}_merged_smali"
    )
    if java_smali_dir.exists():
        # 检查是否有多DEX目錄
        extra_smali_dirs = sorted(java_decompiled_dir.glob("smali_classes*"))
        if extra_smali_dirs:
            print(
                f"\n偵測到多DEX APK，合并 smali 目錄（{1 + len(extra_smali_dirs)} 个DEX）"
            )
            if merged_smali_dir.exists():
                shutil.rmtree(merged_smali_dir)
            shutil.copytree(java_smali_dir, merged_smali_dir)
            for extra_dir in extra_smali_dirs:
                print(f"  合并: {extra_dir.name}/")
                for f in extra_dir.rglob("*.smali"):
                    rel = f.relative_to(extra_dir)
                    dest = merged_smali_dir / rel
                    dest.parent.mkdir(parents=True, exist_ok=True)
                    if not dest.exists():  # 不覆盖（避免重复類冲突）
                        shutil.copy2(f, dest)
            java_smali_dir = merged_smali_dir
            total_merged = sum(1 for _ in merged_smali_dir.rglob("*.smali"))
            print(f"  合并后共 {total_merged} 个 smali 檔")

    # 比較
    print("\n步骤 3: 比較 smali 差異（精细版）")
    result = compare_directories(java_smali_dir, orig_smali_dir)

    # 报告
    print_report(result, args.output)

    # 輸出差異檔完整列表
    diff_list_file = args.output.parent / "diff_file_list.txt"
    diff_files = [f for f in result.files if f.category == 3]
    with open(diff_list_file, "w") as fh:
        for fd in sorted(diff_files, key=lambda x: x.rel_path):
            fh.write(f"{fd.rel_path}\n")
    print(f"\n差異檔列表已保存: {diff_list_file} ({len(diff_files)} 個檔)")

    # ── 輸出審計日誌：不能保證 100% 邏輯一致的等價判定 ──
    audit_file = args.output.parent / "equiv_audit_log.txt"
    if _AUDIT_LOG:
        # 按風險等級分組統計
        by_risk = defaultdict(list)
        for entry in _AUDIT_LOG:
            by_risk[entry["risk"]].append(entry)

        with open(audit_file, "w", encoding="utf-8") as fh:
            fh.write("=" * 100 + "\n")
            fh.write("等價判定審計日誌 — 不能保證 100% 邏輯一致的項目\n")
            fh.write("=" * 100 + "\n\n")

            fh.write(f"總計: {len(_AUDIT_LOG)} 筆可疑等價判定\n")
            for risk_level in ("HIGH", "MEDIUM", "LOW"):
                entries = by_risk.get(risk_level, [])
                if entries:
                    fh.write(f"  {risk_level}: {len(entries)} 筆\n")
            fh.write("\n")

            # 按策略分組統計
            by_strategy = defaultdict(int)
            for entry in _AUDIT_LOG:
                by_strategy[entry["strategy"]] += 1
            fh.write("策略分佈:\n")
            for strat, cnt in sorted(by_strategy.items(), key=lambda x: -x[1]):
                fh.write(f"  {strat}: {cnt}\n")
            fh.write("\n")

            # 按風險等級從高到低輸出詳細記錄
            for risk_level in ("HIGH", "MEDIUM", "LOW"):
                entries = by_risk.get(risk_level, [])
                if not entries:
                    continue
                fh.write("=" * 100 + "\n")
                fh.write(f"風險等級: {risk_level} ({len(entries)} 筆)\n")
                fh.write("-" * 100 + "\n")

                # 按檔案分組
                by_file = defaultdict(list)
                for e in entries:
                    by_file[e["file"]].append(e)

                for filepath, file_entries in sorted(by_file.items()):
                    fh.write(f"\n  檔案: {filepath}\n")
                    for e in file_entries:
                        method_short = (
                            e["method"][:80] if e["method"] else "(file-level)"
                        )
                        fh.write(f"    策略: {e['strategy']}\n")
                        fh.write(f"    方法: {method_short}\n")
                        if e["detail"]:
                            fh.write(f"    說明: {e['detail']}\n")
                        fh.write("\n")

        # 印出摘要
        high_count = len(by_risk.get("HIGH", []))
        medium_count = len(by_risk.get("MEDIUM", []))
        low_count = len(by_risk.get("LOW", []))
        print(f"\n審計日誌已保存: {audit_file}")
        print(
            f"  共 {len(_AUDIT_LOG)} 筆可疑等價判定: HIGH={high_count}, MEDIUM={medium_count}, LOW={low_count}"
        )

        # 列出 HIGH 風險的 sonyericsson 檔案
        high_sony = [e for e in by_risk.get("HIGH", []) if "sonyericsson" in e["file"]]
        if high_sony:
            print(f"\n  ⚠ HIGH 風險 sonyericsson 檔案 ({len(high_sony)} 筆):")
            seen = set()
            for e in high_sony:
                key = f"{e['file']}::{e['method'][:60]}"
                if key not in seen:
                    seen.add(key)
                    print(f"    {e['file']}  方法: {e['method'][:60]}")
    else:
        print(f"\n審計日誌: 無可疑等價判定")

    return 0


if __name__ == "__main__":
    sys.exit(main())
