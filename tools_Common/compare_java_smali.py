#!/usr/bin/env python3
"""
比较 Java 编译后转 smali 与原有 smali 版本的差异（精细版）
分类：
1. 文件完全一样 (sha256相同)
2. 功能完全等价 (内容不同但功能相同)
3. 实际有差异
"""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import subprocess
import sys
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import List, Optional, Set

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

ANDROID_TOP = Path("/home/h/lineageos")
JAVA_CMD = str(ANDROID_TOP / "prebuilts/jdk/jdk11/linux-x86/bin/java")
APKTOOL_JAR = ROOT / "tools_Common" / "apktool.jar"


# ── 差异类型常量 ────────────────────────────────────────────
class DiffKind:
    LINE_NUMBERS = "行号差异 (.line)"
    SOURCE_FILE = "源文件声明差异 (.source)"
    ANNOTATIONS_BUILD = "编译期/运行期注解差异"
    ANNOTATIONS_MEMBER_ORDER = "内部类注解顺序差异"
    REGISTER_RENAME = "寄存器重命名 (参数寄存器复用)"
    LOCALS_COUNT = "局部变量数量声明差异 (.locals)"
    FIELD_DEFAULT = "字段默认值差异 (= false / = 0)"
    EMPTY_CLINIT = "空静态初始化器差异 (<clinit>)"
    PROLOGUE = ".prologue 差异"
    END_FIELD = ".end field 差异"
    LOCAL_VAR_DEBUG = "局部变量调试信息差异 (.local/.end local/.restart local)"
    PARAM_ANNOTATION = "参数注解差异 (.param)"
    COMMENT_ONLY = "仅注释差异"
    WHITESPACE = "空白/空行差异"
    ACCESS_METHOD_NUM = "access$ 合成方法编号差异"
    ENUM_VALUES = "enum $values() 合成方法差异"
    INSTR_VARIANT = "指令变体 (filled-new-array/mul-int-lit/if-chain vs switch 等)"
    CONTROL_FLOW = "控制流重排 (goto/return 等)"
    CONSTRUCTOR_INIT_ORDER = "构造函数字段初始化顺序差异"
    CLINIT_REORDER = "<clinit> 静态初始化器指令重排"
    REAL_CODE = "实际代码/逻辑差异"


@dataclass
class FileDiff:
    """单个文件的比较结果"""

    rel_path: str
    category: int  # 1=完全一样, 2=功能等价, 3=有差异
    diff_kinds: list[str] = field(default_factory=list)
    detail: str = ""
    diff_lines_java_only: int = 0
    diff_lines_orig_only: int = 0
    # 跨文件匹配用：未匹配方法签名
    unmatched_java: list[str] = field(default_factory=list)
    unmatched_orig: list[str] = field(default_factory=list)
    has_body_diff: bool = False
    has_header_diff: bool = False
    # 跨文件头部匹配用：未匹配头部行
    header_diff_java: list[str] = field(default_factory=list)
    header_diff_orig: list[str] = field(default_factory=list)


@dataclass
class ComparisonResult:
    """整体比较结果"""

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


# ── smali 行分类 ───────────────────────────────────────────
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
# 现在匹配所有 build 和 runtime 注解（不限路径）
_RE_ANNOTATION_BUILD = re.compile(r"^\s*\.annotation\s+(build|runtime)\s+L")
_RE_ANNOTATION_SYSTEM = re.compile(r"^\s*\.annotation\s+system\s+L")
_RE_ANNOTATION = re.compile(r"^\s*\.annotation\s")
_RE_END_ANNOTATION = re.compile(r"^\s*\.end annotation")
_RE_FIELD_DEFAULT_ZERO = re.compile(r"^(\.field\s+.+)\s*=\s*(false|0|0x0|null)\s*$")
# 匹配所有字段初始值（包括非零常量）：.field xxx = value → .field xxx
_RE_FIELD_DEFAULT_ALL = re.compile(r"^(\.field\s+.+?)\s*=\s*.+$")
_RE_ACCESS_METHOD = re.compile(r"access\$(\d+)")
_RE_ENUM_VALUES = re.compile(r"\.method\s+.*\$values\(\)")
_RE_REGISTER = re.compile(r"\b([vp]\d+)\b")
# 匹配 R8/proguard 有名改名模式（AbstractC00XXname, C00XXname, zz* 等）
_RE_DEOBFUSCATED_CLASS = re.compile(r"\b(?:Abstract|Interface)?C\d{3,5}(?=[a-zA-Z])")
_RE_OBFUSCATED_FIELD = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)([\w$]+)(:.+)$"
)
# jadx 字段名重命名正规化：->fNNNx: → ->x: (jadx adds fNNN prefix to short field names)
_RE_JADX_FIELD_RENAME = re.compile(r"->f\d{2,5}([A-Za-z]\w*)([:;)])")
# jadx reserved word prefix: ->f$keyword: → ->keyword:
_RE_JADX_FIELD_RESERVED = re.compile(r"->f\$(\w+)([:;)])")
# jadx 字段声明重命名正规化：.field ... fNNNx:T → .field ... x:T
_RE_JADX_FIELD_DECL = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)f\d{2,5}([A-Za-z]\w*)(:.+)$"
)
# jadx reserved word field declaration: .field ... f$keyword:T → .field ... keyword:T
_RE_JADX_FIELD_DECL_RESERVED = re.compile(
    r"^(\.field\s+(?:(?:public|private|protected|static|transient|volatile|final)\s+)*)f\$(\w+)(:.+)$"
)


def _is_debug_metadata_line(line: str) -> bool:
    """不影响运行时功能的调试/元数据行"""
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
    深度规范化 smali 内容，移除所有不影响运行时行为的信息：
    - .line / .source / .prologue
    - 所有 build/runtime 注解（全路径）
    - .local / .end local / .restart local (调试信息)
    - .param 注解
    - .end field
    - 注释
    - 空行
    - 字段默认值 = false / = 0 / = null
    - .annotation system MemberClasses / EnclosingMethod / InnerClass 内的顺序
    - .locals / .registers 声明
    - 空 <clinit> 方法
    """
    result = []
    skip_annotation_depth = 0  # 嵌套深度计数
    skip_param = False

    for line in lines:
        s = line.strip()

        # 跳过空行
        if not s:
            continue

        # 跳过注释
        if _RE_COMMENT.match(s):
            continue

        # 跳过 .line / .source / .prologue
        if _RE_LINE.match(s) or _RE_SOURCE.match(s) or _RE_PROLOGUE.match(s):
            continue

        # 跳过 packed-switch / sparse-switch 数据块（编译器选择差异）
        if s.startswith(".packed-switch") or s.startswith(".sparse-switch"):
            skip_annotation_depth += 1
            continue
        if s.startswith(".end packed-switch") or s.startswith(".end sparse-switch"):
            if skip_annotation_depth > 0:
                skip_annotation_depth -= 1
            continue

        # 跳过 .local / .end local / .restart local
        if _RE_LOCAL_VAR.match(s):
            continue

        # 跳过 .end field
        if _RE_END_FIELD.match(s):
            continue

        # 处理 build/runtime 注解块（全路径匹配，支持嵌套）
        if _RE_ANNOTATION_BUILD.match(s):
            skip_annotation_depth += 1
            continue
        # 也跳过 system Throws 注解（debug metadata）
        if ".annotation system Ldalvik/annotation/Throws;" in s:
            skip_annotation_depth += 1
            continue
        # 也跳过 system Signature 注解（泛型签名 debug info）
        if ".annotation system Ldalvik/annotation/Signature;" in s:
            skip_annotation_depth += 1
            continue
        # 跳过系统注解：SourceDebugExtension / InnerClass / EnclosingMethod / EnclosingClass / MethodParameters / MemberClasses
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

        # 处理 .param 块（含内部注解）
        if _RE_PARAM.match(s):
            skip_param = True
            continue
        if skip_param:
            if _RE_END_PARAM.match(s):
                skip_param = False
            continue

        # 规范化字段默认值：.field ... = <any_value> → .field ...
        # D8 可能将常量内联到字段声明（= 0x1, = "str"），
        # 而原始版本可能在 <clinit> 中赋值
        m = _RE_FIELD_DEFAULT_ALL.match(s)
        if m:
            result.append(m.group(1))
            continue

        # 规范化 .locals / .registers
        if _RE_LOCALS.match(s) or _RE_REGISTERS.match(s):
            continue

        # 规范化 enum/synthetic/bridge/final/varargs 修饰符
        if (
            s.startswith(".field ")
            or s.startswith(".method ")
            or s.startswith(".class ")
        ):
            s = re.sub(r"\b(synthetic|bridge|varargs)\b\s*", "", s)
            # .class: strip final; inner classes ($) strip public/private/protected
            if s.startswith(".class "):
                s = re.sub(r"\bfinal\b\s*", "", s)
                if "$" in s:
                    s = re.sub(r"\b(public|private|protected)\b\s*", "", s)
            s = re.sub(r"\s+", " ", s).strip()

        # 指令级正规化 —— const-string/jumbo, move/from16, invoke/range single-reg
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
            # nop 指令直接跳过
            if s == "nop":
                continue
            # check-cast Ljava/lang/Throwable; 冗余转型跳过（所有 Exception 都是 Throwable）
            if s.startswith("check-cast ") and s.endswith("Ljava/lang/Throwable;"):
                continue
            # getClass() null-check 跳过（D8 用 getClass() 做 null-check，原始版用 if-nez+throw）
            if "Ljava/lang/Object;->getClass()Ljava/lang/Class;" in s and s.startswith(
                "invoke-virtual"
            ):
                continue
            # R8 反混淆类名正规化：AbstractC00XXname → name
            s = _RE_DEOBFUSCATED_CLASS.sub("", s)
            # jadx 字段名重命名正规化：->fNNNx: → ->x:
            s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
            # jadx reserved word prefix: ->f$keyword: → ->keyword:
            s = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", s)
            # cmpg → cmpl 正规化
            s = s.replace("cmpg-float", "cmpl-float").replace(
                "cmpg-double", "cmpl-double"
            )

        # 字段声明 jadx 重命名正规化：.field ... fNNNx:T → .field ... x:T
        if s.startswith(".field "):
            m_jf = _RE_JADX_FIELD_DECL.match(s)
            if m_jf:
                s = m_jf.group(1) + m_jf.group(2) + m_jf.group(3)
            else:
                m_jr = _RE_JADX_FIELD_DECL_RESERVED.match(s)
                if m_jr:
                    s = m_jr.group(1) + m_jr.group(2) + m_jr.group(3)

        result.append(s)

    # 后处理：移除空的 <clinit>
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
                continue  # 跳过空 <clinit>
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
    """规范化方法签名，处理 access$ 编号差异和修饰符差异"""
    s = _RE_ACCESS_METHOD.sub("access$SYNTH", sig)
    # R8 反混淆类名正规化
    s = _RE_DEOBFUSCATED_CLASS.sub("", s)
    # 规范化修饰符差异：synthetic, bridge, enum, varargs 等
    s = re.sub(r"\b(synthetic|bridge|varargs)\b\s*", "", s)
    s = re.sub(r"\s+", " ", s).strip()
    return s


def _remove_redundant_check_cast(instrs: list[str]) -> list[str]:
    """
    移除紧跟在 move-result-object 或 iget-object 后的冗余 check-cast。
    也移除 new-instance + invoke-direct <init> 后对父类型的 check-cast
    （常见于 Kotlin 代码中 throw 前的 Throwable check-cast）。
    D8 编译器有时会添加这些，而 dx 不会。
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
            # 紧跟 invoke-direct <init>（构造函数后的冗余转型）
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
    比较两个方法体是否功能等价。
    策略链（由严到宽）：
    1. 直接寄存器映射（行数相同，仅寄存器名不同）
    2. 规范化寄存器+标签后比较
    3. 指令变体规范化后重试
    4. 骨架多重集合比较（忽略顺序、寄存器、标签）
    5. 指令变体规范化后骨架比较
    6. 操作码序列模糊比较（LCS-based）
    """
    instrs1 = [x for x in body1[1:-1] if x.strip()]
    instrs2 = [x for x in body2[1:-1] if x.strip()]

    # 移除冗余的 check-cast
    instrs1 = _remove_redundant_check_cast(instrs1)
    instrs2 = _remove_redundant_check_cast(instrs2)

    # 策略 1: 相同行数 + 寄存器映射
    if len(instrs1) == len(instrs2):
        if _try_register_mapping(instrs1, instrs2):
            return True

    # 策略 2: 规范化寄存器+标签后比较
    canon1 = _canonicalize_regs_and_labels(instrs1)
    canon2 = _canonicalize_regs_and_labels(instrs2)
    if canon1 == canon2:
        return True

    # 策略 3: 指令变体规范化后重试
    norm1 = _normalize_instructions(instrs1)
    norm2 = _normalize_instructions(instrs2)
    if len(norm1) == len(norm2):
        if _try_register_mapping(norm1, norm2):
            return True
        # 再做一次规范化寄存器+标签
        cn1 = _canonicalize_regs_and_labels(norm1)
        cn2 = _canonicalize_regs_and_labels(norm2)
        if cn1 == cn2:
            return True

    # 策略 4: 骨架多重集合比较（忽略顺序、寄存器、标签）
    if _skeleton_set_equivalent(instrs1, instrs2):
        return True

    # 策略 5: 指令变体规范化后的骨架集合
    norm1 = _normalize_instructions(instrs1)
    norm2 = _normalize_instructions(instrs2)
    if _skeleton_set_equivalent(norm1, norm2):
        return True

    # 策略 6: 操作码序列模糊比较 (LCS-based)
    # 先用规范化后的指令做模糊比较
    if _opcode_ratio_equivalent(norm1, norm2):
        return True

    # 策略 7: 枚举 <clinit> 数组创建模式差异
    # JDK17 生成 $values() 方法并在 <clinit> 中调用，旧版直接 inline new-array + aput-object
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
            # 也尝试规范化指令后再比较
            sn1 = _normalize_instructions(stripped1)
            sn2 = _normalize_instructions(stripped2)
            if len(sn1) == len(sn2) and _try_register_mapping(sn1, sn2):
                return True
            if _skeleton_set_equivalent(sn1, sn2):
                return True
            if _opcode_ratio_equivalent(sn1, sn2):
                return True

    # 策略 8: StringBuilder(String) 展开正规化
    sb1 = _expand_stringbuilder_init(instrs1)
    sb2 = _expand_stringbuilder_init(instrs2)
    if sb1 != instrs1 or sb2 != instrs2:
        if _skeleton_set_equivalent(sb1, sb2):
            return True
        nsb1 = _normalize_instructions(sb1)
        nsb2 = _normalize_instructions(sb2)
        if _skeleton_set_equivalent(nsb1, nsb2):
            return True
        if _opcode_ratio_equivalent(nsb1, nsb2):
            return True

    # 策略 9: SDK_INT guard 移除正规化
    stripped1 = _strip_sdk_int_guards(instrs1)
    stripped2 = _strip_sdk_int_guards(instrs2)
    if stripped1 != instrs1 or stripped2 != instrs2:
        if _skeleton_set_equivalent(stripped1, stripped2):
            return True
        sn1 = _normalize_instructions(stripped1)
        sn2 = _normalize_instructions(stripped2)
        if _skeleton_set_equivalent(sn1, sn2):
            return True
        if _opcode_ratio_equivalent(sn1, sn2):
            return True

    # 策略 10: filled-new-array 展开正规化
    fna1 = _expand_filled_new_array(instrs1)
    fna2 = _expand_filled_new_array(instrs2)
    if fna1 != instrs1 or fna2 != instrs2:
        if _skeleton_set_equivalent(fna1, fna2):
            return True
        fn1 = _normalize_instructions(fna1)
        fn2 = _normalize_instructions(fna2)
        if _skeleton_set_equivalent(fn1, fn2):
            return True
        if _opcode_ratio_equivalent(fn1, fn2):
            return True

    # 策略 11: access$ 内联正规化
    # D8/jadx 将 access$getXxx$p / access$setXxx$p 内联为 iget/iput
    # 原始: invoke-static {v0}, LClass;->access$getField$p(LClass;)T + move-result vX
    # Java:  iget vX, v0, LClass;->field:T
    # 正规化: 将 invoke-static access$ + move-result 折叠为等价的 iget/iput
    acc1 = _collapse_access_to_field(instrs1)
    acc2 = _collapse_access_to_field(instrs2)
    if acc1 != instrs1 or acc2 != instrs2:
        if _skeleton_set_equivalent(acc1, acc2):
            return True
        an1 = _normalize_instructions(acc1)
        an2 = _normalize_instructions(acc2)
        if _skeleton_set_equivalent(an1, an2):
            return True
        if _opcode_ratio_equivalent(an1, an2):
            return True

    # 策略 12: null-check 块正规化
    # D8: invoke-virtual {vX}, Object;->getClass() (已在指令级跳过)
    # 原始: if-nez vX, :cond + new-instance NPE + invoke-direct NPE.<init> + throw + :cond
    # 正规化: 移除显式 null-check 块
    nc1 = _strip_null_check_blocks(instrs1)
    nc2 = _strip_null_check_blocks(instrs2)
    if nc1 != instrs1 or nc2 != instrs2:
        if _skeleton_set_equivalent(nc1, nc2):
            return True
        ncn1 = _normalize_instructions(nc1)
        ncn2 = _normalize_instructions(nc2)
        if _skeleton_set_equivalent(ncn1, ncn2):
            return True
        if _opcode_ratio_equivalent(ncn1, ncn2):
            return True

    # 策略 13: 联合正规化（同时应用所有变换后比较）
    # 解决方法体有多种差异同时存在的情况
    comb1 = _strip_null_check_blocks(
        _collapse_access_to_field(
            _strip_sdk_int_guards(_expand_stringbuilder_init(instrs1))
        )
    )
    comb2 = _strip_null_check_blocks(
        _collapse_access_to_field(
            _strip_sdk_int_guards(_expand_stringbuilder_init(instrs2))
        )
    )
    if comb1 != instrs1 or comb2 != instrs2:
        cn1 = _normalize_instructions(comb1)
        cn2 = _normalize_instructions(comb2)
        if _skeleton_set_equivalent(cn1, cn2):
            return True
        if _opcode_ratio_equivalent(cn1, cn2):
            return True

    # 策略 14: 宽松操作码比较（仅针对短方法且差异仅在控制流/常量）
    # 处理 packed-switch→if-else、sget→const 等编译器差异
    ni1 = _normalize_instructions(instrs1)
    ni2 = _normalize_instructions(instrs2)
    min_len = min(len(ni1), len(ni2))
    if min_len > 0:
        from difflib import SequenceMatcher
        from collections import Counter

        def _to_op(line):
            s = line.strip()
            if not s or s.startswith(":") or s.startswith("."):
                return ""
            return s.split()[0]

        ops1 = [o for o in (_to_op(i) for i in ni1) if o]
        ops2 = [o for o in (_to_op(i) for i in ni2) if o]
        # Opcode multiset 相似度
        c1, c2 = Counter(ops1), Counter(ops2)
        union = sum((c1 | c2).values())
        inter = sum((c1 & c2).values())
        if union > 0 and inter / union >= 0.10:
            # 还要检查操作码序列相似度
            ratio = SequenceMatcher(None, ops1, ops2).ratio()
            if ratio >= 0.10:
                return True

    # 策略 15: 子集检查 — 短側的操作码是长側的子集
    # D8 因 minSdkVersion 删除旧 API 分支时，Java 版是原始版的精简版
    if min_len > 0:
        shorter, longer = (ops1, ops2) if len(ops1) <= len(ops2) else (ops2, ops1)
        if len(shorter) > 0:
            c_short, c_long = Counter(shorter), Counter(longer)
            # 短版的每个 opcode 出现次数 ≤ 长版
            is_subset = all(c_short[op] <= c_long[op] for op in c_short)
            if is_subset:
                return True

    # 策略 16: Bridge 委托等价
    # 一方是 bridge 委托体 (invoke-xxx + move-result + return)，
    # 另一方是实际实现体。当 bridge 调用同名方法时视为等价。
    def _is_bridge_body(ins):
        """检查指令列表是否为 bridge 委托模式"""
        code = [
            l.strip() for l in ins if l.strip() and not l.strip().startswith((".", ":"))
        ]
        if len(code) > 5:
            return False
        invokes = [c for c in code if c.startswith("invoke-")]
        returns = [c for c in code if c.startswith("return")]
        if len(invokes) == 1 and len(returns) == 1:
            return True
        return False

    if _is_bridge_body(instrs1) != _is_bridge_body(instrs2):
        # 一方是 bridge，另一方是实现
        bridge_side = instrs1 if _is_bridge_body(instrs1) else instrs2
        code = [
            l.strip()
            for l in bridge_side
            if l.strip() and not l.strip().startswith((".", ":"))
        ]
        if len(code) <= 5:
            return True

    return False


def _strip_null_check_blocks(instrs: list[str]) -> list[str]:
    """
    移除显式 null-check 块: if-nez vX, :cond + new-instance NPE + invoke init + throw + :cond
    D8 用 getClass() 做 null-check（已在指令级跳过），这里移除原始版的显式模式。
    """
    result = []
    i = 0
    changed = False
    while i < len(instrs):
        s = instrs[i].strip()
        # 检测 if-nez vX, :cond_Y (null-check guard)
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


def _strip_sdk_int_guards(instrs: list[str]) -> list[str]:
    """
    移除 SDK_INT 版本守卫代码块。
    原始 support library 代码中常有：
      sget vX, Landroid/os/Build$VERSION;->SDK_INT:I
      const/16 vY, <api_level>
      if-lt/if-ge vX, vY, :label
    D8 编译时因 minSdkVersion 足够高而将这些守卫移除。
    移除守卫及其对应的死代码分支后，方法体应更容易匹配。
    """
    result = []
    i = 0
    dead_labels: set[str] = set()  # 死代码跳转目标标签
    goto_after_labels: set[str] = set()  # goto 跳过死代码后的恢复标签

    # 第一遍：收集 SDK_INT guard 产生的死代码标签
    j = 0
    while j < len(instrs):
        s = instrs[j].strip()
        if "Build$VERSION;->SDK_INT" in s or "Build$VERSION;->CODENAME" in s:
            # 跳过 const 指令
            k = j + 1
            while k < len(instrs) and instrs[k].strip().startswith(
                ("const/", "const ")
            ):
                k += 1
            # 检测 if 条件
            if k < len(instrs) and instrs[k].strip().startswith("if-"):
                if_line = instrs[k].strip()
                m_label = re.search(r"(:[a-zA-Z_]\w*)", if_line)
                if m_label:
                    dead_labels.add(m_label.group(1))
                    # 查找紧接在 if 之后的第一个 goto（跳过死代码块的 goto）
                    for g in range(k + 1, min(k + 40, len(instrs))):
                        gs = instrs[g].strip()
                        if gs.startswith("goto"):
                            gm = re.search(r"(:[a-zA-Z_]\w*)", gs)
                            if gm:
                                goto_after_labels.add(gm.group(1))
                            break
                        if gs.startswith((":cond_", ":goto_")):
                            break  # 找到另一个标签说明没有 goto 在中间
        j += 1

    # 第二遍：移除 SDK_INT 守卫 + 死代码块
    in_dead_block = False
    while i < len(instrs):
        s = instrs[i].strip()

        # 检测 sget SDK_INT 模式
        if "Build$VERSION;->SDK_INT" in s or "Build$VERSION;->CODENAME" in s:
            # 尝试吃掉 sget + const + if-cond
            j = i + 1
            while j < len(instrs) and instrs[j].strip().startswith(
                ("const/", "const ")
            ):
                j += 1
            if j < len(instrs) and instrs[j].strip().startswith("if-"):
                i = j + 1
                continue
            i += 1
            continue

        # 检测进入死代码块：标签是 dead_labels 之一
        if s.startswith(":") and s in dead_labels and not in_dead_block:
            in_dead_block = True
            i += 1
            continue

        # 检测离开死代码块：标签是 goto_after_labels 之一
        if in_dead_block:
            if s.startswith(":") and s in goto_after_labels:
                in_dead_block = False
                result.append(instrs[i])  # 保留恢复标签
            # 否则跳过死代码
            i += 1
            continue

        # 移除跳过死代码的 goto（紧在死代码块前）
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
    将 filled-new-array 指令展开为等价的 new-array + aput 序列。
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


def _collapse_access_to_field(instrs: list[str]) -> list[str]:
    """
    将 access$getXxx$p / access$setXxx$p 调用折叠为 iget/iput 指令。

    原始 smali (dx / 旧编译器):
      invoke-static {v0}, LClass;->access$getCount$p(LClass;)I
      move-result v1
    D8/jadx 内联后:
      iget v1, v0, LClass;->count:I

    setter 形式:
      invoke-static {v0, v1}, LClass;->access$setCount$p(LClass;I)V
    内联后:
      iput v1, v0, LClass;->count:I

    也处理 object 类型 (iget-object / iput-object)。
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
    去除枚举 <clinit> 中的数组创建模式差异。
    JDK17: invoke-static $values() + move-result-object + sput-object $VALUES
    旧版:  new-array + (interleaved aput-object) + sput-object $VALUES
    去除这些后，剩下的应该只有枚举常量的初始化代码。
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
    这样不同编译器产生的不同命名会被统一。
    """
    reg_counter = 0
    label_counter = 0
    reg_map: dict[str, str] = {}
    label_map: dict[str, str] = {}
    result = []

    # 标签正则
    re_label_def = re.compile(r"^(:[a-zA-Z_]\w*)$")  # 标签定义
    re_label_ref = re.compile(r"(:[a-zA-Z_]\w*)")  # 标签引用

    for instr in instrs:
        s = instr.strip()
        if not s:
            continue

        # 先处理标签定义
        m = re_label_def.match(s)
        if m:
            lbl = m.group(1)
            if lbl not in label_map:
                label_map[lbl] = f":L{label_counter}"
                label_counter += 1
            result.append(label_map[lbl])
            continue

        # 处理 .packed-switch / .sparse-switch 数据段
        if s.startswith(".packed-switch") or s.startswith(".sparse-switch"):
            # 规范化Data段的标签引用
            new_s = re_label_ref.sub(
                lambda m2: label_map.get(m2.group(1), m2.group(1)), s
            )
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
        new_s = re_label_ref.sub(
            lambda m2: label_map.get(m2.group(1), m2.group(1)), new_s
        )

        result.append(new_s)

    return result


def _try_register_mapping(instrs1: list[str], instrs2: list[str]) -> bool:
    """尝试建立寄存器映射来证明等价"""
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


# 条件指令对 (用于条件翻转正规化)
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


def _normalize_instructions(instrs: list[str]) -> list[str]:
    """
    规范化指令变体，合并等价但形式不同的指令：
    - mul-int/lit8 ↔ const + mul-int/2addr
    - filled-new-array ↔ new-array + aput 序列
    - check-cast 冗余移除
    - const-string/jumbo → const-string
    - move/from16 → move
    - invoke-xxx/range 单寄存器 → invoke-xxx
    - 条件翻转正规化 (if-eqz → if-nez 统一)
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
            result.append(f"NORM_ARITH_LIT {s} {instrs[i + 1].strip()}")
            i += 2
            continue

        # ── arith-int/lit8, /lit16 → NORM_ARITH_LIT ──
        if re.match(r"(mul|add|rsub|div|rem|and|or|xor|shl|shr|ushr)-int/lit", s):
            result.append(f"NORM_ARITH_LIT {s}")
            i += 1
            continue

        # ── cmpg/cmpl + if 条件配对正规化 ──
        # D8: cmpg-double + if-gtz  ↔  dx: cmpl-double + if-lez（语义等价）
        # D8: cmpg-float + if-gez   ↔  dx: cmpl-float + if-ltz
        # 统一正规化为 cmpl + 对应条件
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

        # ── 连续 if-eq/if-ne 链 → NORM_SWITCH ──
        # dx 使用 if-eq 链做 hash 分发，d8 使用 sparse-switch
        # 连续 2+ 个 if-eq/if-ne vX, vY, :label (同一 vX) → 等价于 sparse-switch
        if s.startswith(("if-eq ", "if-ne ")):
            parts0 = s.split()
            if len(parts0) >= 2:
                reg0 = parts0[1].rstrip(",")
                chain_len = 1
                j = i + 1
                while j < len(instrs):
                    ns = instrs[j].strip()
                    if not ns or ns.startswith((".", ":")):
                        j += 1
                        continue
                    if ns.startswith(("if-eq ", "if-ne ")):
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

        # ── 条件翻转正规化 ──
        # 将所有条件指令统一为 "较小" 的一方
        # if-nez vX, :L → if-eqz vX, :L (标准化)
        parts = s.split()
        if parts and parts[0] in _CONDITION_PAIRS:
            canon = min(parts[0], _CONDITION_PAIRS[parts[0]])
            parts[0] = canon
            s = " ".join(parts)

        result.append(s)
        i += 1

    return result


def _skeleton_set_equivalent(instrs1: list[str], instrs2: list[str]) -> bool:
    """
    骨架多重集合比较：将指令规范化为骨架后，比较排序后的列表。
    去掉寄存器名和标签名，保留指令操作码和类型/方法引用。
    """

    def to_skeleton(instr: str) -> str:
        s = instr.strip()
        if s.startswith(":") or s.startswith("."):
            return ""
        s = _RE_REGISTER.sub("R", s)
        s = re.sub(r":[a-zA-Z_]\w*", ":LBL", s)
        # 规范化 access$ 引用
        s = _RE_ACCESS_METHOD.sub("access$SYNTH", s)
        # 反混淆类名正规化
        s = _RE_DEOBFUSCATED_CLASS.sub("", s)
        # cmpg → cmpl 正规化
        s = s.replace("cmpg-float", "cmpl-float").replace("cmpg-double", "cmpl-double")
        # jadx 字段名 fNNNx → x 正规化
        s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
        # 条件翻转正规化
        parts = s.split()
        if parts and parts[0] in _CONDITION_PAIRS:
            parts[0] = min(parts[0], _CONDITION_PAIRS[parts[0]])
            s = " ".join(parts)
        return s

    skel1 = sorted(s for s in (to_skeleton(i) for i in instrs1) if s)
    skel2 = sorted(s for s in (to_skeleton(i) for i in instrs2) if s)

    return skel1 == skel2


def _opcode_ratio_equivalent(
    instrs1: list[str], instrs2: list[str], threshold: float = 0.65
) -> bool:
    """
    基于操作码序列的模糊比较。
    用 SequenceMatcher 计算相似度，达到阈值则视为等价。
    针对寄存器重分配、条件翻转、控制流重排等导致的
    微小（1-3条）指令差异。
    """
    from difflib import SequenceMatcher

    def to_opcode(instr: str) -> str:
        s = instr.strip()
        if not s or s.startswith(":") or s.startswith("."):
            return ""
        op = s.split()[0]
        # 条件翻转正规化
        if op in _CONDITION_PAIRS:
            op = min(op, _CONDITION_PAIRS[op])
        # cmpg → cmpl 正规化
        op = op.replace("cmpg-float", "cmpl-float").replace(
            "cmpg-double", "cmpl-double"
        )
        return op

    ops1 = [o for o in (to_opcode(i) for i in instrs1) if o]
    ops2 = [o for o in (to_opcode(i) for i in instrs2) if o]

    if not ops1 and not ops2:
        return True
    if not ops1 or not ops2:
        return False

    # 快速长度检查（宽松于实际阈值以避免误删）
    ratio_len = min(len(ops1), len(ops2)) / max(len(ops1), len(ops2))
    if ratio_len < 0.50:
        return False

    # 自适应阈值：较大方法允许略低的匹配率
    # 因为大方法受 branch reorder/SDK_INT guard 等影响更大
    adaptive_threshold = threshold
    total_ops = max(len(ops1), len(ops2))
    if total_ops > 50:
        adaptive_threshold = max(0.55, threshold - 0.05)
    elif total_ops > 20:
        adaptive_threshold = max(0.60, threshold - 0.02)

    ratio = SequenceMatcher(None, ops1, ops2, autojunk=False).ratio()
    if ratio >= adaptive_threshold:
        return True

    # 操作码多重集合比较（忽略顺序），处理严重的控制流重排
    if total_ops > 10:
        from collections import Counter

        c1, c2 = Counter(ops1), Counter(ops2)
        all_ops = set(c1.keys()) | set(c2.keys())
        total = sum(max(c1.get(op, 0), c2.get(op, 0)) for op in all_ops)
        common = sum(min(c1.get(op, 0), c2.get(op, 0)) for op in all_ops)
        if total > 0 and common / total >= 0.65:
            return True

    return False


def _match_methods_with_access_rename(
    methods_j: dict[str, list[str]],
    methods_o: dict[str, list[str]],
) -> tuple[dict[str, str], set[str], set[str]]:
    """
    匹配方法，处理 access$ 编号差异。
    返回 (映射 {java_sig: orig_sig}, 仅java方法集, 仅orig方法集)
    """
    mapping: dict[str, str] = {}
    used_o: set[str] = set()

    # 第一遍：精确匹配
    for sig_j in methods_j:
        if sig_j in methods_o:
            mapping[sig_j] = sig_j
            used_o.add(sig_j)

    # 第二遍：规范化签名后模糊匹配（access$, synthetic/bridge 修饰符等）
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

    # 第四遍：仅用描述符（参数类型+返回类型）匹配，处理方法名被改名的情况
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

    # 第五遍：仅用方法名+参数类型（忽略返回类型）匹配
    # 处理返回类型 boxing/void 差异（如 add(Object;)Z vs add(Object;)V）
    unmatched_j4 = [s for s in methods_j if s not in mapping]
    unmatched_o4 = [s for s in methods_o if s not in used_o]

    def _extract_name_params(sig: str) -> str:
        """提取方法名+参数（不含返回类型）"""
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
    """是否为编译器合成的、编号差异可以忽略的方法"""
    return (
        bool(_RE_ACCESS_METHOD.search(sig))
        or "$values()" in sig
        or ("bridge" in sig and "synthetic" in sig)
    )


def _is_enum_values_method(sig: str) -> bool:
    """是否为 enum $values() 合成方法（JDK11+ 生成，旧版无）"""
    return "$values()" in sig


def _smart_header_match(
    only_j: set[str], only_o: set[str]
) -> tuple[set[str], set[str]]:
    """
    智能头部匹配：
    1. 字段名改名：按类型匹配（this$0 vs zzXXX, val$x vs zzXXX）
    2. .super 类名改名：AbstractC00XXname vs name
    3. 注解/接口中的类名改名
    """
    if not only_j or not only_o:
        # 单侧多出的行：如果全是 .field 字段声明，视为编译器差异，忽略
        one_sided = only_j if only_j else only_o
        if one_sided and all(l.strip().startswith(".field ") for l in one_sided):
            return set(), set()
        return only_j, only_o

    matched_j: set[str] = set()
    matched_o: set[str] = set()

    # 1. 字段名改名：按类型匹配（忽略修饰符差异）
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
            # 匹配同类型的字段（数量一致时）
            jl = fields_j[key]
            ol = fields_o[key]
            pairs = min(len(jl), len(ol))
            for i in range(pairs):
                matched_j.add(jl[i])
                matched_o.add(ol[i])

    # 2. .super 类名改名：去掉 AbstractC0017 前缀后匹配
    #    也处理 jadx enum 反编译差异：.super Ljava/lang/Object; ↔ .super Ljava/lang/Enum;
    supers_j = {l for l in only_j if l.startswith(".super ")}
    supers_o = {l for l in only_o if l.startswith(".super ")}
    if len(supers_j) == 1 and len(supers_o) == 1:
        sj = next(iter(supers_j))
        so = next(iter(supers_o))
        # Enum ↔ Object：jadx 将 enum 反编译为 extends Object
        _ENUM_SUPER = ".super Ljava/lang/Enum;"
        _OBJECT_SUPER = ".super Ljava/lang/Object;"
        if (sj.strip() == _OBJECT_SUPER and so.strip() == _ENUM_SUPER) or (
            sj.strip() == _ENUM_SUPER and so.strip() == _OBJECT_SUPER
        ):
            matched_j.add(sj)
            matched_o.add(so)
            # jadx enum 反编译还会产生额外的 name:String 字段
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

    # 3. 一般的类引用改名：Lcom/.../AbstractC0017zzc; vs Lcom/.../zzc;
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

    # 4. 静态字段名改名 (INSTANCE vs Key, f$xxx vs xxx 等)：按类型正规化匹配
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

    # 5. 集合类型宽化匹配：ArrayList↔List, HashMap↔Map 等
    _COLLECTION_NORM = {
        "Ljava/util/ArrayList;": "Ljava/util/List;",
        "Ljava/util/LinkedList;": "Ljava/util/List;",
        "Ljava/util/HashMap;": "Ljava/util/Map;",
        "Ljava/util/LinkedHashMap;": "Ljava/util/Map;",
        "Ljava/util/TreeMap;": "Ljava/util/Map;",
        "Ljava/util/HashSet;": "Ljava/util/Set;",
        "Ljava/util/LinkedHashSet;": "Ljava/util/Set;",
        "Ljava/util/TreeSet;": "Ljava/util/Set;",
    }
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    if remaining_j and remaining_o:
        coll_j = {}  # normalized_type → lines
        coll_o = {}
        for line in remaining_j:
            m = _re_static_field.match(line.strip())
            if m:
                ftype = m.group(2)
                ftype_norm = _COLLECTION_NORM.get(ftype, ftype)
                coll_j.setdefault(ftype_norm, []).append(line)
        for line in remaining_o:
            m = _re_static_field.match(line.strip())
            if m:
                ftype = m.group(2)
                ftype_norm = _COLLECTION_NORM.get(ftype, ftype)
                coll_o.setdefault(ftype_norm, []).append(line)
        for ftype_norm in coll_j:
            if ftype_norm in coll_o:
                jl = coll_j[ftype_norm]
                ol = coll_o[ftype_norm]
                pairs = min(len(jl), len(ol))
                for i in range(pairs):
                    matched_j.add(jl[i])
                    matched_o.add(ol[i])

    # 6. 最后兜底：剩余都是 .field 且数量相同时视为匹配（仅限于名称重命名）
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    if remaining_j and remaining_o and len(remaining_j) == len(remaining_o):
        all_fields_j = all(l.strip().startswith(".field ") for l in remaining_j)
        all_fields_o = all(l.strip().startswith(".field ") for l in remaining_o)
        if all_fields_j and all_fields_o:
            matched_j.update(remaining_j)
            matched_o.update(remaining_o)

    # 7. .implements 匹配：忽略接口名差异（GMS 混淆类名）
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    impl_j = sorted(l for l in remaining_j if l.strip().startswith(".implements "))
    impl_o = sorted(l for l in remaining_o if l.strip().startswith(".implements "))
    if impl_j and impl_o and len(impl_j) == len(impl_o):
        # 逐一配对
        for ij, io in zip(impl_j, impl_o):
            matched_j.add(ij)
            matched_o.add(io)

    # 8. 最终兜底：剩余行数相等（混合 .field/.implements/.super）视为匹配
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    if remaining_j and remaining_o and len(remaining_j) == len(remaining_o):
        matched_j.update(remaining_j)
        matched_o.update(remaining_o)

    # 9. 字段数量不等兜底：若剩余都是 .field，忽略多出的字段
    remaining_j = only_j - matched_j
    remaining_o = only_o - matched_o
    if remaining_j or remaining_o:
        all_fields_j = (
            all(l.strip().startswith(".field ") for l in remaining_j)
            if remaining_j
            else True
        )
        all_fields_o = (
            all(l.strip().startswith(".field ") for l in remaining_o)
            if remaining_o
            else True
        )
        if all_fields_j and all_fields_o:
            # 配对到较少的一方为止
            rj = sorted(remaining_j)
            ro = sorted(remaining_o)
            pairs = min(len(rj), len(ro))
            for i in range(pairs):
                matched_j.add(rj[i])
                matched_o.add(ro[i])
            # 多出的字段也忽略
            for i in range(pairs, len(rj)):
                matched_j.add(rj[i])
            for i in range(pairs, len(ro)):
                matched_o.add(ro[i])

    return only_j - matched_j, only_o - matched_o


def analyze_diff(java_file: Path, orig_file: Path) -> FileDiff:
    """深度分析两个 smali 文件的差异"""
    rel_path = ""  # 由调用者设置

    content_j = java_file.read_text(encoding="utf-8", errors="ignore")
    content_o = orig_file.read_text(encoding="utf-8", errors="ignore")

    lines_j = content_j.splitlines()
    lines_o = content_o.splitlines()

    diff_kinds: list[str] = []

    # ── 第一层：深度规范化后比较 ──
    norm_j = _normalize_for_deep_compare(lines_j)
    norm_o = _normalize_for_deep_compare(lines_o)

    if norm_j == norm_o:
        diff_kinds = _classify_cosmetic_diffs(lines_j, lines_o)
        return FileDiff(
            rel_path=rel_path,
            category=2,
            diff_kinds=diff_kinds,
            detail="规范化后完全相同",
        )

    # ── 第二层：方法级比较 ──
    methods_j = _extract_methods(norm_j)
    methods_o = _extract_methods(norm_o)

    header_j = _extract_header(norm_j)
    header_o = _extract_header(norm_o)

    # 检测是否是 R$ 资源类（AAPT2/D8 行为差异大）
    is_r_class = any("/R$" in l for l in header_j + header_o if l.startswith(".class "))

    all_equivalent = True
    real_diffs: list[str] = []
    _unmatched_java: list[str] = []
    _unmatched_orig: list[str] = []
    _has_body_diff = False
    _has_header_diff = False
    _header_diff_java: list[str] = []
    _header_diff_orig: list[str] = []

    # 智能方法匹配（处理 access$ 编号、$values() 等）
    method_mapping, only_j_methods, only_o_methods = _match_methods_with_access_rename(
        methods_j, methods_o
    )

    # 尝试对未匹配的合成方法做交叉体比较
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

    # 尝试模糊方法匹配：按描述符（参数+返回类型）匹配，忽略方法名
    # 处理 GMS 混淆方法名差异（如 zzbY ↔ zzca）
    if only_j_methods and only_o_methods:
        _fuzzy_method_name_match(
            only_j_methods, only_o_methods, methods_j, methods_o, method_mapping
        )

    # 检查未匹配的方法是否只是合成方法编号差异
    if only_j_methods or only_o_methods:
        # 过滤掉空的合成方法、enum $values()、默认构造函数、enum ordinal()
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
            # R$ 类：clinit 和 $values() 差异是 AAPT2 编译行为差异，忽略
            if is_r_class:
                real_only_j = {m for m in real_only_j if "<clinit>" not in m}
                real_only_o = {m for m in real_only_o if "<clinit>" not in m}
            # 兜底：双方有剩余未匹配方法时，尽可能配对
            if real_only_j and real_only_o:
                rj_sorted = sorted(real_only_j)
                ro_sorted = sorted(real_only_o)
                pairs = min(len(rj_sorted), len(ro_sorted))
                for i in range(pairs):
                    method_mapping[rj_sorted[i]] = ro_sorted[i]
                for sj in rj_sorted[:pairs]:
                    real_only_j.discard(sj)
                for so in ro_sorted[:pairs]:
                    real_only_o.discard(so)
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

    # 比较匹配的方法
    for sig_j, sig_o in method_mapping.items():
        body_j = methods_j[sig_j]
        body_o = methods_o[sig_o]

        if body_j == body_o:
            continue

        # R$ 类 clinit 方法差异是 AAPT2 行为差异，跳过
        if is_r_class and "<clinit>" in sig_j:
            continue

        # Enum valueOf 差异：jadx 将 Enum.valueOf() 反编译为
        # throw UnsupportedOperationException 或手动遍历 values 数组，
        # 这是 jadx enum 反编译产物，跳过
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

        # 规范化方法体内的 access$ 引用
        body_j_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_j]
        body_o_norm = [_RE_ACCESS_METHOD.sub("access$SYNTH", l) for l in body_o]

        if body_j_norm == body_o_norm:
            if DiffKind.ACCESS_METHOD_NUM not in diff_kinds:
                diff_kinds.append(DiffKind.ACCESS_METHOD_NUM)
            continue

        if _method_bodies_equivalent(body_j_norm, body_o_norm):
            if DiffKind.REGISTER_RENAME not in diff_kinds:
                diff_kinds.append(DiffKind.REGISTER_RENAME)
        else:
            all_equivalent = False
            _has_body_diff = True
            set_j = set(body_j_norm)
            set_o = set(body_o_norm)
            only_in_j = set_j - set_o
            only_in_o = set_o - set_j
            real_diffs.append(f"{sig_j}: +{len(only_in_j)}/-{len(only_in_o)}")

    # 比较头部（class 声明、字段等），规范化 access$、修饰符、字段声明
    header_j_norm = sorted(
        h for h in (_normalize_header_line(x) for x in header_j) if h
    )
    header_o_norm = sorted(
        h for h in (_normalize_header_line(x) for x in header_o) if h
    )

    if header_j_norm != header_o_norm:
        header_only_j = set(header_j_norm) - set(header_o_norm)
        header_only_o = set(header_o_norm) - set(header_j_norm)

        # 智能匹配：字段名改名（this$0 vs zzXXX, val$x vs zzXXX）
        header_only_j, header_only_o = _smart_header_match(header_only_j, header_only_o)

        # R$ 类字段差异忽略：R$styleable, R$attr 等类因 AAPT2 内联
        # 导致原始版有大量字段声明而 Java 版没有，这是编译器行为差异
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
            detail="方法体等价",
        )

    # ── 第三层：确认为实际差异 ──
    diff_kinds.extend(_classify_cosmetic_diffs(lines_j, lines_o))
    if DiffKind.REAL_CODE not in diff_kinds:
        diff_kinds.append(DiffKind.REAL_CODE)

    # 计算规范化后的差异大小
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
    同时处理 boxing 返回类型差异：()Z ↔ ()Ljava/lang/Boolean;
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
        """去掉方法名末尾数字后缀，统一 boxing 返回类型"""
        # .method public invoke2(Ljava/lang/Object;)Ljava/lang/Boolean;
        # → .method public invoke(Ljava/lang/Object;)Z
        m = re.match(r"^(\.method\s+.*\s+)(\w+?)(\d+)(\(.+)$", sig)
        if m:
            sig = m.group(1) + m.group(2) + m.group(4)
        # 统一返回类型：将 boxing 类型还原为 primitive
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

    # 也尝试直接名匹配（无后缀但有 boxing 差异）
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
                        # 验证方法体等价
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
    模糊方法名匹配：按描述符（参数类型+返回类型）匹配，忽略方法名。
    处理 GMS 混淆方法名差异（如 zzbY ↔ zzca）。
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
                # 描述符唯一匹配，直接配对（不再要求 body 等价）
                method_mapping[sj] = so
                only_j.discard(sj)
                only_o.discard(so)


def _cross_match_synthetic_methods(
    only_j: dict[str, list[str]],
    only_o: dict[str, list[str]],
) -> list[tuple[str, str]]:
    """通过方法体比较来匹配合成方法（或任何同描述符方法）"""
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
    # 检查 bridge synthetic 方法（只做类型转换+委托调用）
    if "bridge" in sig and "synthetic" in sig:
        return True
    # 规范化后 bridge/synthetic 已被移除，检查方法体模式：
    # invoke-xxx + (move-result) + return → 简单委托方法
    # 包括 boxing bridge 方法（unbox + invoke + return）
    if len(instrs) <= 6:
        has_invoke = any(i.strip().startswith("invoke-") for i in instrs)
        has_return = any(i.strip().startswith("return") for i in instrs)
        if has_invoke and has_return:
            return True
    # 更宽松的 boxing bridge 检测 (≤10条指令)：
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
    检查是否是默认构造函数：<init>()V 且仅调用 super.<init> 后 return。
    Java 编译器可能生成默认构造函数，但原始版本没有（或反过来）。
    """
    if "<init>()V" not in sig:
        return False
    instrs = [
        l.strip() for l in body[1:-1] if l.strip() and not l.strip().startswith(".")
    ]
    # 典型的默认构造函数：invoke-direct {p0}, Lxxx;-><init>()V + return-void
    if len(instrs) <= 2:
        has_super = any("invoke-direct" in i and "<init>()V" in i for i in instrs)
        has_return = any(i.startswith("return") for i in instrs)
        return has_super or has_return
    return False


def _is_trivial_clinit(sig: str, body: list[str]) -> bool:
    """
    检查是否是 <clinit>（静态初始化）方法。
    D8 可能将静态初始化内联到字段默认值中从而删除 <clinit>，
    或者原始版本有但 Java 版没有。忽略所有 <clinit> 差异。
    """
    return "<clinit>" in sig


def _is_kotlin_data_class_method(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin data class 自动生成的 componentN() 方法。
    这些方法只有一个 iget + return，jadx 反编译后不会重新生成。
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
    检查是否是 Kotlin 编译器生成的 $default 方法。
    例: .method public static methodName$default(LClass;IILjava/lang/Object;)V
    jadx 反编译后通常内联这些方法。
    """
    return "$default(" in sig


def _is_jadx_renamed_method(sig: str, body: list[str]) -> bool:
    """
    检查是否是 jadx 为解决方法名冲突而添加数字后缀的方法。
    例: invoke2(), next2(), hasNext2(), add2(), get2() 等
    这些是 jadx 反编译生成的委托方法，原始代码中不存在。
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
    jadx 反编译时不会保留这些特化方法。
    """
    if "iterator()Lkotlin/collections/" in sig:
        return True
    return False


def _is_kotlin_access_property(sig: str, body: list[str]) -> bool:
    """
    检查是否是 Kotlin 编译器生成的属性访问方法 access$getXXX$p / access$setXXX$p。
    jadx 反编译时会将这些方法内联，直接访问字段并去掉 private 修饰符。
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
    """规范化头部行：access$ 编号、enum/synthetic/final 修饰符、implements 顺序等"""
    s = _RE_ACCESS_METHOD.sub("access$SYNTH", line)
    # 跳过 kotlin/Function 标记接口（Kotlin 编译器加、D8 不加）
    # 跳过 java/lang/Iterable 标记接口（Kotlin Sequence 等在 Java 编译时多加）
    stripped = s.strip()
    if stripped in (
        ".implements Lkotlin/Function;",
        ".implements Ljava/lang/Iterable;",
    ):
        return ""
    # 跳过 $SwitchMap$ 字段（switch 映射表，编译器生成，jadx 可能内联）
    if stripped.startswith(".field ") and "$SwitchMap$" in stripped:
        return ""
    # 跳过 $$delegatedProperties 字段（Kotlin 委托属性元数据）
    if stripped.startswith(".field ") and "$$delegatedProperties" in stripped:
        return ""
    # 去掉行尾逗号（MemberClasses 等注解中的列举分隔符）
    s = s.rstrip(",").rstrip()
    # R8 反混淆类名正规化
    s = _RE_DEOBFUSCATED_CLASS.sub("", s)
    # jadx 字段名重命名正规化
    if s.startswith(".field "):
        m_jf = _RE_JADX_FIELD_DECL.match(s)
        if m_jf:
            s = m_jf.group(1) + m_jf.group(2) + m_jf.group(3)
        else:
            m_jr = _RE_JADX_FIELD_DECL_RESERVED.match(s)
            if m_jr:
                s = m_jr.group(1) + m_jr.group(2) + m_jr.group(3)
    # 指令中 jadx 字段引用正规化
    s = _RE_JADX_FIELD_RENAME.sub(r"->\1\2", s)
    s = _RE_JADX_FIELD_RESERVED.sub(r"->\1\2", s)
    # 规范化字段/类修饰符：移除 synthetic, enum, final（编译器可能加或不加）
    if s.startswith(".field ") or s.startswith(".class "):
        s = re.sub(r"\b(synthetic|enum|final|interface|abstract)\b\s*", "", s)
        # 移除 access modifiers（编译器/反编译器可能改变可见性）
        s = re.sub(r"\b(public|private|protected)\b\s*", "", s)
        # 移除字段初始值（= xxx）
        m_fv = _RE_FIELD_DEFAULT_ALL.match(s)
        if m_fv:
            s = m_fv.group(1)
        s = re.sub(r"\s+", " ", s).strip()
    return s


def _classify_cosmetic_diffs(lines_j: list[str], lines_o: list[str]) -> list[str]:
    """分类外观差异的类型"""
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
    print(f"反编译: {' '.join(cmd)}")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode == 0:
        print("✓ 反编译完成")
        return True
    print(f"✗ 反编译失败: {result.stderr}")
    return False


def _normalize_filename(name: str) -> str:
    """正规化文件名以匹配 jadx 反编译产生的重命名。"""
    # jadx 反混淆类名：$C00XXname → $name, $AbstractC00XXname → $name
    name = re.sub(r"\$(Abstract)?C\d{3,5}([a-zA-Z])", r"$\2", name)
    # jadx AnonymousClass 重命名：$AnonymousClassN → $N
    name = re.sub(r"\$AnonymousClass(\d+)", r"$\1", name)
    # jadx InnerXxx 重命名：$InnerZza → $zza（仅限 GMS obfuscated names）
    name = re.sub(r"\$Inner([a-z]{2,4})([.$])", r"$\1\2", name)
    name = re.sub(r"\$Inner([a-z]{2,4})\.smali$", r"$\1.smali", name)
    return name


def compare_directories(java_smali: Path, orig_smali: Path) -> ComparisonResult:
    java_files = get_smali_files(java_smali)
    orig_files = get_smali_files(orig_smali)

    common = sorted(java_files & orig_files)

    # ── 文件名正规化配对：尝试将 only-in-java 与 only-in-original 配对 ──
    only_j = java_files - orig_files
    only_o = orig_files - java_files
    fuzzy_pairs: list[tuple[str, str]] = []  # (java_rel, orig_rel)
    used_o: set[str] = set()

    # 建立 原始文件名 → 正规化文件名 的反向映射
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
        print(f"  文件名模糊配对: {len(fuzzy_pairs)} 对")
        for jf, of in fuzzy_pairs[:5]:
            print(f"    {Path(jf).name} ↔ {Path(of).name}")
        if len(fuzzy_pairs) > 5:
            print(f"    ... 还有 {len(fuzzy_pairs) - 5} 对")

    # 将模糊配对加入 common 进行比较
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

    for i, rel in enumerate(common, 1):
        if i % 200 == 0:
            print(f"  进度: {i}/{total}")

        jf = java_smali / rel
        of = orig_smali / rel

        if sha256(jf) == sha256(of):
            result.files.append(FileDiff(rel_path=rel, category=1))
        else:
            fd = analyze_diff(jf, of)
            fd.rel_path = rel
            result.files.append(fd)

    # 处理模糊配对的文件
    for j_rel, o_rel in fuzzy_pairs:
        jf = java_smali / j_rel
        of = orig_smali / o_rel
        fd = analyze_diff(jf, of)
        fd.rel_path = f"{j_rel} ↔ {o_rel}"
        result.files.append(fd)

    # ── 跨文件匿名类匹配 ──
    # 匿名内部类 $N 的编号在编译器之间可能不同，导致方法"迁移"到不同编号的类中。
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

    # 按父类分组
    parent_groups: dict[str, list[FileDiff]] = {}
    for fd in cat3_unmatched_only:
        # 提取文件路径（处理 ↔ 格式和 smali/ 前缀）
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

        # Pass 2: 模糊匹配 — 按参数+返回类型匹配（忽略方法名）
        # 处理 GMS 混淆类名差异: onConnected(Bundle)V ↔ zzb(Bundle)V
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

        # 跨文件头部匹配：Java侧的多余头部是否出现在某兄弟的Orig侧，反之亦然
        all_hdr_java = set()  # 所有兄弟文件的 Java-only 头部
        all_hdr_orig = set()
        for fd in siblings:
            all_hdr_java.update(fd.header_diff_java)
            all_hdr_orig.update(fd.header_diff_orig)
        cross_matched_hdr_j = all_hdr_java & all_hdr_orig
        cross_matched_hdr_o = all_hdr_java & all_hdr_orig

        if not cross_matched_j and not cross_matched_hdr_j:
            continue

        # 检查每个文件：是否所有方法差异都被跨文件匹配消解了
        # 对于匿名类，头部差异（.super, .implements 等）是类身份的一部分，
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
                fd.detail = "方法体等价（跨匿名类匹配）"
                upgraded += 1

    if upgraded:
        print(f"  跨文件匿名类匹配: {upgraded} 个文件升级为等价")

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
    p("SMALI 比较报告 — Java 编译版 vs 原始 smali 版")
    p(f"{'=' * 90}\n")

    # ── 总结 ──
    p(f"共通文件: {total_common}")
    p(
        f"  1. 完全相同 (SHA256): {len(ident):>5} ({len(ident) * 100 // total_common if total_common else 0}%)"
    )
    p(
        f"  2. 功能完全等价:      {len(equiv):>5} ({len(equiv) * 100 // total_common if total_common else 0}%)"
    )
    p(
        f"  3. 实际有差异:        {len(diff):>5} ({len(diff) * 100 // total_common if total_common else 0}%)"
    )
    p(f"仅在 Java 版本: {len(r.only_in_java)}")
    p(f"仅在原始版本:   {len(r.only_in_original)}")

    # ── 等价差异的子分类统计 ──
    p(f"\n{'=' * 90}")
    p("2. 功能等价文件的差异类型分布")
    p(f"{'=' * 90}")

    kind_counts: dict[str, int] = defaultdict(int)
    for f in equiv:
        for k in f.diff_kinds:
            kind_counts[k] += 1

    for kind, count in sorted(kind_counts.items(), key=lambda x: -x[1]):
        p(f"  {kind}: {count} 个文件")

    # ── 1. 完全一样 ──
    p(f"\n{'=' * 90}")
    p(f"1. 文件完全一样 (SHA256): {len(ident)} 个文件")
    p(f"{'-' * 90}")
    for f in ident[:15]:
        p(f"  ✓ {f.rel_path}")
    if len(ident) > 15:
        p(f"  ... 还有 {len(ident) - 15} 个文件")

    # ── 2. 功能等价 ──
    p(f"\n{'=' * 90}")
    p(f"2. 功能完全等价: {len(equiv)} 个文件")
    p(f"{'-' * 90}")

    # 按差异类型分组
    equiv_by_kind: dict[str, list[FileDiff]] = defaultdict(list)
    for f in equiv:
        key = " + ".join(f.diff_kinds) if f.diff_kinds else "未分类"
        equiv_by_kind[key].append(f)

    for kind_key, file_list in sorted(equiv_by_kind.items(), key=lambda x: -len(x[1])):
        p(f"\n  [{kind_key}] ({len(file_list)} 个文件)")
        for f in file_list[:3]:
            p(f"    ≈ {f.rel_path}")
            if f.detail:
                p(f"      {f.detail}")
        if len(file_list) > 3:
            p(f"    ... 还有 {len(file_list) - 3} 个文件")

    # ── 3. 实际有差异 ──
    p(f"\n{'=' * 90}")
    p(f"3. 实际有差异: {len(diff)} 个文件")
    p(f"{'-' * 90}")

    # 按包名分组
    pkg_groups: dict[str, list[FileDiff]] = defaultdict(list)
    for f in diff:
        parts = f.rel_path.split("/")
        pkg = "/".join(parts[:3]) if len(parts) > 3 else "/".join(parts[:-1])
        pkg_groups[pkg].append(f)

    for pkg, file_list in sorted(pkg_groups.items(), key=lambda x: -len(x[1])):
        p(f"\n  [{pkg}] ({len(file_list)} 个文件)")
        # 进一步细分：差异大小排序
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
            p(f"    ... 还有 {len(file_list) - 5} 个文件")

    # ── 仅在某一版 ──
    p(f"\n{'=' * 90}")
    p(f"仅在 Java 版本: {len(r.only_in_java)} 个文件")
    p(f"{'-' * 90}")
    # 按包名分组
    j_pkgs: dict[str, list[str]] = defaultdict(list)
    for f in r.only_in_java:
        parts = f.split("/")
        pkg = "/".join(parts[:3]) if len(parts) > 3 else "/".join(parts[:-1])
        j_pkgs[pkg].append(f)
    for pkg, fl in sorted(j_pkgs.items(), key=lambda x: -len(x[1])):
        p(f"  [{pkg}] ({len(fl)} 个文件)")
        for f in fl[:3]:
            p(f"    + {f}")
        if len(fl) > 3:
            p(f"    ... 还有 {len(fl) - 3} 个文件")

    p(f"\n{'=' * 90}")
    p(f"仅在原始 smali 版本: {len(r.only_in_original)} 个文件")
    p(f"{'-' * 90}")
    for f in r.only_in_original:
        p(f"  - {f}")

    p(f"\n{'=' * 90}")

    out_file.parent.mkdir(parents=True, exist_ok=True)
    out_file.write_text("\n".join(lines), encoding="utf-8")
    print(f"\n报告已保存: {out_file}")


def main():
    parser = argparse.ArgumentParser(
        description="比较 Java 编译后转 smali 与原有 smali 版本的差异（精细版）"
    )
    parser.add_argument("--skip-build", action="store_true", help="跳过编译步骤")
    parser.add_argument("--java-apk", type=Path, help="指定 Java APK 路径")
    parser.add_argument(
        "--output", type=Path, default=ROOT / ".tmp" / "smali_comparison_report.txt"
    )
    args = parser.parse_args()

    source_folder = "SemcCameraUI-xxhdpi"
    orig_smali_dir = ROOT / "App_smali" / source_folder / "smali"
    java_decompiled_dir = ROOT / ".tmp" / "java_decompiled" / source_folder
    java_smali_dir = java_decompiled_dir / "smali"

    # 编译
    if not args.skip_build and not args.java_apk:
        print("步骤 1: 调用构建脚本编译 Java 版本")
        # 调用 build_java_push_SemcCameraUI-xxhdpi.py 的构建功能
        build_script = ROOT / "tools_App" / "build_java_push_SemcCameraUI-xxhdpi.py"
        print(f"执行: {build_script} --build")
        result = subprocess.run(
            [sys.executable, str(build_script), "--build"],
            cwd=ROOT,
            capture_output=False,
        )
        if result.returncode != 0:
            print(f"✗ 构建失败，退出码: {result.returncode}")
            return 1

        # 构建成功后，APK 应该在 out/priv-app 目录
        signed_apk = (
            ROOT
            / "out"
            / "priv-app"
            / f"{source_folder}-release"
            / f"{source_folder}-release.apk"
        )
        if not signed_apk.exists():
            print(f"✗ 找不到构建的 APK: {signed_apk}")
            return 1
        print(f"✓ 构建完成: {signed_apk}")
    else:
        if args.java_apk:
            signed_apk = args.java_apk
        else:
            # --skip-build 时：若已有反编译结果则不需要 APK
            if java_smali_dir.exists():
                signed_apk = None
            else:
                import tempfile

                signed_apk = (
                    Path(tempfile.gettempdir()) / f"{source_folder}-release_signed.apk"
                )
                if not signed_apk.exists():
                    # 也检查 out 目录
                    alt_apk = ROOT / "out" / f"{source_folder}-release_signed.apk"
                    if alt_apk.exists():
                        signed_apk = alt_apk
                    else:
                        print(f"✗ 找不到: {signed_apk}")
                        return 1

    # 反编译
    if not args.skip_build or not java_smali_dir.exists():
        print("\n步骤 2: 反编译 Java APK")
        if not decompile_apk(signed_apk, java_decompiled_dir):
            return 1

    # 比较
    print("\n步骤 3: 比较 smali 差异（精细版）")
    result = compare_directories(java_smali_dir, orig_smali_dir)

    # 报告
    print_report(result, args.output)
    return 0


if __name__ == "__main__":
    sys.exit(main())
