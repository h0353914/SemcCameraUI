# CMakeLists.txt — Libcacao 四個 .so 的獨立 CMake 建置
# 用於 Gradle externalNativeBuild，以 Android NDK toolchain 編譯
#
# 依賴標頭來源（依照 LineageOS lineage-16.0 default.xml 清單）：
#   frameworks/native   → LineageOS/android_frameworks_native   @ lineage-16.0
#   system/core         → LineageOS/android_system_core         @ lineage-16.0
#   hardware/libhardware→ LineageOS/android_hardware_libhardware @ lineage-16.0
#   system/libhidl      → platform/system/libhidl (AOSP)        @ android-9.0.0_r46
#   system/libhwbinder  → LineageOS/android_system_libhwbinder  @ lineage-16.0
#   hardware/interfaces → LineageOS/android_hardware_interfaces  @ lineage-16.0
#   bionic              → LineageOS/android_bionic               @ lineage-16.0
#
# 兩種使用模式（自動偵測）：
#
#   模式 A — 本地 sysroot（推薦，不需要完整 AOSP 樹）：
#     先執行 python tools_Libcacao/fetch_sysroot.py 下載標頭到 tools_Libcacao/sysroot/
#     HIDL C++ 標頭由 hidl-gen 生成至 sysroot/hidl-gen/
#     CMake 自動偵測 tools_Libcacao/sysroot/ 目錄，或以 -DLIBCACAO_SYSROOT=<path> 指定
#
#   模式 B — 完整 LineageOS 原始碼樹：
#     需要 LINEAGE_ROOT 已有完整 checkout 並執行過 Soong 建置
#     HIDL C++ 標頭取自 out/soong/.intermediates/
#     以 -DLIBCACAO_SYSROOT=~/lineageos 指定（與 LINEAGE_ROOT 相同）

cmake_minimum_required(VERSION 3.10)
project(libcacao C CXX ASM)

# ── C++ 標準設定（Android 9 對應 C++17）─────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 與 Android 系統庫兼容：系統庫（libbinder 等）用 -fno-rtti 編譯，無 typeinfo 匯出
# 我們也用 -fno-rtti 避免 typeinfo for android::IBinder 等 undefined symbol
add_compile_options(-fno-rtti)
# 使用設備平台的 libc++ ABI namespace（std::__1），確保與 HIDL inline template 符號相容
# 設備系統庫（libhidlbase, IBase 等）用平台 libc++（std::__1）編譯
# NDK 預設用 std::__ndk1，會導致 getDebugInfo 等函數 mangling 不符而連結失敗
add_compile_definitions(_LIBCPP_ABI_NAMESPACE=__1)
# 強制使用 lld（支援 --pack-dyn-relocs=none 等現代 linker flags）
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=lld")

# NDK 21 預設加 -Wl,--no-undefined，會導致 HIDL inline template 函數連結失敗
# （IMapper::tryGetService 等在 shared lib 中，但 --no-undefined 不允許任何 undef）
# 移除後改用 --allow-shlib-undefined 處理，與原版 Android.bp 行為一致
string(REPLACE "-Wl,--no-undefined" "" CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

# ── 配置參數（由 Gradle 透過 cmake.arguments 傳入）──────
if(NOT DEFINED LINEAGE_ROOT)
    set(LINEAGE_ROOT "$ENV{HOME}/lineageos")
endif()
if(NOT DEFINED PRODUCT_NAME)
    set(PRODUCT_NAME "poplar_kddi")
endif()

set(PRODUCT_OUT "${LINEAGE_ROOT}/out/target/product/${PRODUCT_NAME}")
set(TOOLS_LIBCACAO_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIBCACAO_SRC "${TOOLS_LIBCACAO_DIR}/../camera/cacao")
set(REPO_ROOT "${LIBCACAO_SRC}")  # 相容性：保持與原始 CMakeLists.txt 相同的引用

# ABI 相關路徑
# 連結庫使用 refs/so_64 / refs/so_32（Android 9 原版 .so），確保與設備 ABI 相容
# （PRODUCT_OUT 含 Android 14 libs，符號簽名不同，不可用於連結目標）
if(ANDROID_ABI STREQUAL "arm64-v8a")
    set(SYSTEM_LIB    "${TOOLS_LIBCACAO_DIR}/refs/so_64")
    set(PREBUILTS_LIB "${LIBCACAO_SRC}/prebuilts/lib64")
else()
    set(SYSTEM_LIB    "${TOOLS_LIBCACAO_DIR}/refs/so_32")
    set(PREBUILTS_LIB "${LIBCACAO_SRC}/prebuilts/lib")
endif()

# ══════════════════════════════════════════════════════════
# 混合模式標頭策略：
#   android-base/    → LINEAGE_ROOT（含 borrowed_fd；fdsan 函數為 __weak__ symbol，API28 safe）
#   HybridInterface.h→ sysroot/ (lineage-16.0，LINEAGE_ROOT 已移除)
#   其餘所有標頭      → LINEAGE_ROOT (/home/h/lineageos/)
#   HIDL C++ 標頭    → LINEAGE_ROOT out/soong/.intermediates/
# ══════════════════════════════════════════════════════════
set(_L16 "${TOOLS_LIBCACAO_DIR}/sysroot")
if(NOT EXISTS "${_L16}/system/libhidl_l16/transport/token/1.0/utils/include")
    message(FATAL_ERROR
        "[libcacao] 找不到 lineage-16.0 HybridInterface 標頭: ${_L16}/system/libhidl_l16/transport/token/1.0/utils/include\n"
        "請先執行: python tools_Libcacao/fetch_sysroot.py"
    )
endif()
message(STATUS "[libcacao] lineage-16.0 sysroot: ${_L16}")
message(STATUS "[libcacao] 其餘標頭使用 LINEAGE_ROOT: ${LINEAGE_ROOT}")

set(_SOONG_INT "${LINEAGE_ROOT}/out/soong/.intermediates")

# NDK C++ 標頭路徑（ANDROID_STL=none 不自動加入，需手動指定）
set(_NDK_CXX_INCLUDE "${ANDROID_NDK}/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/c++/v1")

# ── 全域包含目錄 ─────────────────────────────────────────
include_directories(
    # NDK libc++ 標頭（ANDROID_STL=none 時需手動加入）
    ${_NDK_CXX_INCLUDE}
    # sysroot shims（最前面：覆蓋 API29+ 相容問題）
    # android-base/unique_fd.h → sysroot shim（borrowed_fd，無 fdsan，API28 safe）
    # android/binder_to_string.h → sysroot shim（無 NDK binder API29+ 依賴）
    ${_L16}

    # android-base（除 unique_fd.h 外）→ LINEAGE_ROOT
    ${LINEAGE_ROOT}/system/libbase/include

    # frameworks/native → sysroot lineage-16.0
    # 注意：sysroot 標頭已修補：
    #   gui/Surface.h → 加入第 3 個參數 surfaceControlHandle (default nullptr)
    #   binder/IMemory.h → 加入 unsecurePointer() = pointer()
    ${_L16}/frameworks/native/include
    # frameworks/native gui/ui/nativewindow/nativebase → sysroot lineage-16.0（避免 AIDL/API29+ 依賴）
    ${_L16}/frameworks/native/libs/binder/include
    ${_L16}/frameworks/native/libs/gui/include
    ${_L16}/frameworks/native/libs/ui/include
    ${_L16}/frameworks/native/libs/nativewindow/include
    ${_L16}/frameworks/native/libs/nativebase/include

    # system/core → LINEAGE_ROOT
    ${LINEAGE_ROOT}/system/core/include
    ${LINEAGE_ROOT}/system/core/libutils/include
    ${LINEAGE_ROOT}/system/core/libcutils/include

    # system/logging/liblog → LINEAGE_ROOT (log/log.h)
    ${LINEAGE_ROOT}/system/logging/liblog/include

    # hardware/libhardware → LINEAGE_ROOT
    ${LINEAGE_ROOT}/hardware/libhardware/include

    # system/libhidl → LINEAGE_ROOT（hidl_enum_values 變數模板，Soong 生成標頭相容）
    ${LINEAGE_ROOT}/system/libhidl/base/include
    ${LINEAGE_ROOT}/system/libhidl/transport/include
    # HybridInterface.h → lineage-16.0 sysroot（LINEAGE_ROOT 已不提供此標頭）
    ${_L16}/system/libhidl_l16/transport/token/1.0/utils/include

    # system/libfmq → LINEAGE_ROOT (fmq/MQDescriptorBase.h)
    ${LINEAGE_ROOT}/system/libfmq/base

    # system/libhwbinder → LINEAGE_ROOT
    ${LINEAGE_ROOT}/system/libhwbinder/include

    # 本地模組標頭（不受 sysroot 影響）
    ${REPO_ROOT}/libcacao_client/include
    ${REPO_ROOT}/libcacao_service/include
    ${REPO_ROOT}/libcacao_process_ctrl_gateway/include
    ${REPO_ROOT}/libimageprocessorjni/include
)

# ── HIDL 生成標頭 → LINEAGE_ROOT Soong intermediates ────
include_directories(
    # bufferqueue@1.0, bufferqueue@2.0
    ${_SOONG_INT}/hardware/interfaces/graphics/bufferqueue/1.0/android.hardware.graphics.bufferqueue@1.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/graphics/bufferqueue/2.0/android.hardware.graphics.bufferqueue@2.0_genc++_headers/gen
    # android.hardware.media@1.0 (依賴自 bufferqueue@1.0)
    ${_SOONG_INT}/hardware/interfaces/media/1.0/android.hardware.media@1.0_genc++_headers/gen
    # graphics mapper, allocator, common 1.0 + 1.1
    ${_SOONG_INT}/hardware/interfaces/graphics/mapper/2.0/android.hardware.graphics.mapper@2.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/graphics/allocator/2.0/android.hardware.graphics.allocator@2.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/graphics/common/1.0/android.hardware.graphics.common@1.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/graphics/common/1.1/android.hardware.graphics.common@1.1_genc++_headers/gen
    # camera common, provider
    # provider@2.4 的生成標頭本身 #include device@1.0 / device@3.2，必須一併加入
    ${_SOONG_INT}/hardware/interfaces/camera/common/1.0/android.hardware.camera.common@1.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/camera/provider/2.4/android.hardware.camera.provider@2.4_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/camera/device/1.0/android.hardware.camera.device@1.0_genc++_headers/gen
    ${_SOONG_INT}/hardware/interfaces/camera/device/3.2/android.hardware.camera.device@3.2_genc++_headers/gen
    # hidl base, manager
    ${_SOONG_INT}/system/libhidl/transport/base/1.0/android.hidl.base@1.0_genc++_headers/gen
    ${_SOONG_INT}/system/libhidl/transport/manager/1.0/android.hidl.manager@1.0_genc++_headers/gen
)

# ── 預建系統庫輔助函式 ────────────────────────────────────
# 建立 IMPORTED SHARED 目標，指向 PRODUCT_OUT 的系統庫存根
# 若庫檔不存在（例如 sysroot 模式），則建立虛擬 INTERFACE 庫
function(add_system_lib varname)
    if(EXISTS "${SYSTEM_LIB}/${varname}.so")
        add_library(${varname} SHARED IMPORTED)
        set_target_properties(${varname} PROPERTIES
            IMPORTED_LOCATION "${SYSTEM_LIB}/${varname}.so"
        )
    else()
        # sysroot 模式：無預編譯庫，建立虛擬 INTERFACE 庫以連結庫名稱
        if(NOT TARGET ${varname})
            add_library(${varname} INTERFACE)
            target_link_libraries(${varname} INTERFACE ${varname})
        endif()
    endif()
endfunction()

# 建立 IMPORTED SHARED 目標，指向本地 prebuilts/
function(add_prebuilt_lib varname filename)
    if(EXISTS "${PREBUILTS_LIB}/${filename}.so")
        add_library(${varname} SHARED IMPORTED)
        set_target_properties(${varname} PROPERTIES
            IMPORTED_LOCATION "${PREBUILTS_LIB}/${filename}.so"
        )
    else()
        # sysroot 模式：無預建庫，建立虛擬 INTERFACE 庫
        if(NOT TARGET ${varname})
            add_library(${varname} INTERFACE)
            target_link_libraries(${varname} INTERFACE ${filename})
        endif()
    endif()
endfunction()

# 建立 IMPORTED SHARED 目標，HIDL 庫名含 @ 符號（CMake 不允許 @ 在 target 名）
function(add_hidl_lib varname filename)
    # 先找 system/lib，再找 system_ext/lib（HIDL transport 庫有時放在 system_ext）
    set(_HIDL_PATH "")
    if(EXISTS "${SYSTEM_LIB}/${filename}.so")
        set(_HIDL_PATH "${SYSTEM_LIB}/${filename}.so")
    elseif(EXISTS "${PRODUCT_OUT}/system/system_ext/lib/${filename}.so")
        if(ANDROID_ABI STREQUAL "arm64-v8a")
            if(EXISTS "${PRODUCT_OUT}/system/system_ext/lib64/${filename}.so")
                set(_HIDL_PATH "${PRODUCT_OUT}/system/system_ext/lib64/${filename}.so")
            else()
                set(_HIDL_PATH "${PRODUCT_OUT}/system/system_ext/lib/${filename}.so")
            endif()
        else()
            set(_HIDL_PATH "${PRODUCT_OUT}/system/system_ext/lib/${filename}.so")
        endif()
    endif()
    if(_HIDL_PATH)
        add_library(${varname} SHARED IMPORTED)
        set_target_properties(${varname} PROPERTIES
            IMPORTED_LOCATION "${_HIDL_PATH}"
        )
    else()
        # sysroot 模式：無預編譯 HIDL 庫，建立虛擬 INTERFACE 庫以連結 HIDL 庫名稱
        if(NOT TARGET ${varname})
            add_library(${varname} INTERFACE)
            target_link_libraries(${varname} INTERFACE ${filename})
        endif()
    endif()
endfunction()

function(add_vendor_hidl_lib varname filename)
    if(EXISTS "${PREBUILTS_LIB}/${filename}.so")
        add_library(${varname} SHARED IMPORTED)
        set_target_properties(${varname} PROPERTIES
            IMPORTED_LOCATION "${PREBUILTS_LIB}/${filename}.so"
        )
    else()
        # sysroot 模式：無 vendor HIDL 庫，建立虛擬 INTERFACE 庫
        if(NOT TARGET ${varname})
            add_library(${varname} INTERFACE)
            target_link_libraries(${varname} INTERFACE ${filename})
        endif()
    endif()
endfunction()

# ── 系統庫 (refs/so_{32,64}/) ───────────────────────────
# libc++：使用設備原版 libc++.so（std::__1 namespace），與 HIDL 系統庫 ABI 相容
if(EXISTS "${SYSTEM_LIB}/libc++.so")
    add_library(libcxx_shared SHARED IMPORTED)
    set_target_properties(libcxx_shared PROPERTIES
        IMPORTED_LOCATION "${SYSTEM_LIB}/libc++.so"
    )
else()
    add_library(libcxx_shared INTERFACE)
    target_link_libraries(libcxx_shared INTERFACE c++)
endif()
add_system_lib(libbinder)
add_system_lib(libutils)
add_system_lib(libcutils)
# libgui: 優先用 prebuilts（設備的 .so，有正確的 2-arg Surface ctor），而非 lineageos build
add_prebuilt_lib(libgui libgui)
add_system_lib(libui)
add_system_lib(libhidlbase)
add_system_lib(libhidltransport)
add_system_lib(libhardware)
add_system_lib(libandroid)

# HIDL 介面庫（含 @ 版本號，用 alias 命名）
add_hidl_lib(hw_graphics_mapper_2_0  "android.hardware.graphics.mapper@2.0")
add_hidl_lib(hw_graphics_alloc_2_0   "android.hardware.graphics.allocator@2.0")
add_hidl_lib(hw_graphics_common_1_0  "android.hardware.graphics.common@1.0")
add_hidl_lib(hw_camera_common_1_0    "android.hardware.camera.common@1.0")
add_hidl_lib(hw_camera_provider_2_4  "android.hardware.camera.provider@2.4")
add_hidl_lib(hidl_base_1_0           "android.hidl.base@1.0")
add_hidl_lib(hidl_manager_1_0        "android.hidl.manager@1.0")

# ── vendor 預建庫 (prebuilts/lib{64}/) ───────────────────
add_prebuilt_lib(libcacao_pal "libcacao_pal")
add_vendor_hidl_lib(somc_cacao_3_0    "vendor.somc.hardware.camera.cacao@3.0")
add_vendor_hidl_lib(somc_cacao_3_1    "vendor.somc.hardware.camera.cacao@3.1")
add_vendor_hidl_lib(somc_provider_1_0 "vendor.somc.hardware.camera.provider@1.0")

# ── Android 9 相容性靜態庫 ───────────────────────────────
# 提供 onValueRetrieval() 的 weak symbol 定義
# Android 14 LINEAGE_ROOT 標頭在 Return<T>::operator T() 中呼叫此函數
# 但 Android 9 的 libhidlbase.so 沒有此符號，需 weak symbol 填補
add_library(hidl_compat STATIC
    "${TOOLS_LIBCACAO_DIR}/sysroot/hidl_compat.cpp"
)

# ══════════════════════════════════════════════════════════
# 1. libcacao_process_ctrl_gateway（armeabi-v7a 32-bit only）
# ══════════════════════════════════════════════════════════
if(ANDROID_ABI STREQUAL "armeabi-v7a")

    add_library(libcacao_process_ctrl_gateway SHARED
        ${REPO_ROOT}/libcacao_process_ctrl_gateway/src/ProcessCtrlGatewayBase.cpp
        ${REPO_ROOT}/libcacao_process_ctrl_gateway/src/ProcessCtrlGateway.cpp
        ${REPO_ROOT}/libcacao_process_ctrl_gateway/src/aeabi_helpers.c
    )

    target_compile_options(libcacao_process_ctrl_gateway PRIVATE
        -Os
        -fno-exceptions
        -fno-lto
        -fno-inline-small-functions
        -fno-inline-functions
        -fno-slp-vectorize
        -fno-vectorize
        -fno-unwind-tables
        -fno-asynchronous-unwind-tables
        -mfpu=vfpv3-d16
        -DLIBCACAO_SOONG_BUILD
        -DLIBCACAO_USE_LINEAGE14_HEADERS
    )

    # CMake 3.10 兼容性：使用 target_link_libraries 傳遞 linker flags 和相依庫
    target_link_libraries(libcacao_process_ctrl_gateway PRIVATE
        -Wl,--pack-dyn-relocs=none
        -Wl,--allow-shlib-undefined
        libcxx_shared
        hidl_compat
        "-Wl,--version-script,${REPO_ROOT}/libcacao_process_ctrl_gateway/libcacao_process_ctrl_gateway.map.txt"
        hidl_base_1_0
        hidl_manager_1_0
        hw_camera_common_1_0
        hw_camera_provider_2_4
        hw_graphics_alloc_2_0
        libhidlbase
        libhidltransport
        libandroid
        libutils
        libbinder
        libgui
        log
        libcutils
        libcacao_pal
        libcacao_client
        somc_cacao_3_0
        somc_cacao_3_1
        somc_provider_1_0
    )

    set_target_properties(libcacao_process_ctrl_gateway PROPERTIES
        OUTPUT_NAME "cacao_process_ctrl_gateway"
    )

    # ══════════════════════════════════════════════════════
    # 2. libcacao_service（armeabi-v7a 32-bit only）
    # ══════════════════════════════════════════════════════
    add_library(libcacao_service SHARED
        ${REPO_ROOT}/libcacao_service/src/CacaoService.cpp
    )

    target_compile_options(libcacao_service PRIVATE
        -Os
        -fno-function-sections
        -fno-data-sections
        -fno-inline-small-functions
        -fno-inline-functions
        -fno-slp-vectorize
        -fno-vectorize
        -mfpu=vfpv3-d16
        # 確保模板實例化的 weak symbols 被導出到動態符號表（原版 ABI 相容）
        -fvisibility=default
    )

    # CMake 3.10 兼容性：使用 target_link_libraries 傳遞 linker flags 和相依庫
    target_link_libraries(libcacao_service PRIVATE
        -Wl,--pack-dyn-relocs=none
        -Wl,--allow-shlib-undefined
        libcxx_shared
        hidl_compat
        "-Wl,--version-script,${REPO_ROOT}/libcacao_service/libcacao_service.map.txt"
        hidl_base_1_0
        
        hw_camera_common_1_0
        hw_camera_provider_2_4
        hw_graphics_alloc_2_0
        libhidlbase
        libhidltransport
        libandroid
        libutils
        libui
        libbinder
        libcutils
        log
        libcacao_client
        libcacao_process_ctrl_gateway
        somc_cacao_3_0
        somc_cacao_3_1
        somc_provider_1_0
    )

    set_target_properties(libcacao_service PROPERTIES
        OUTPUT_NAME "cacao_service"
    )

endif() # armeabi-v7a only

# ══════════════════════════════════════════════════════════
# 3. libcacao_client（armeabi-v7a + arm64-v8a）
# ══════════════════════════════════════════════════════════
add_library(libcacao_client SHARED
    ${REPO_ROOT}/libcacao_client/src/ICacaoService.cpp
    ${REPO_ROOT}/libcacao_client/src/ICacao.cpp
    ${REPO_ROOT}/libcacao_client/src/ICacaoClient.cpp
    ${REPO_ROOT}/libcacao_client/src/ICacaoProcessCallback.cpp
    ${REPO_ROOT}/libcacao_client/src/Cacao.cpp
    ${REPO_ROOT}/libcacao_client/src/SharedBuffer_ObjectBase.cpp
    ${REPO_ROOT}/libcacao_client/src/ImageBuf.cpp
    ${REPO_ROOT}/libcacao_client/src/ProcessFactory.cpp
)

target_compile_options(libcacao_client PRIVATE
    -Os
    -Wno-unused-parameter
)

if(ANDROID_ABI STREQUAL "arm64-v8a")
    set(CACAO_CLIENT_MAP
        "${REPO_ROOT}/libcacao_client/libcacao_client_arm64.map.txt")
else()
    set(CACAO_CLIENT_MAP
        "${REPO_ROOT}/libcacao_client/libcacao_client_arm.map.txt")
endif()

# CMake 3.10 兼容性：使用 target_link_libraries 傳遞 linker flags 和相依庫
target_link_libraries(libcacao_client PRIVATE
    -Wl,--pack-dyn-relocs=none
    -Wl,--allow-shlib-undefined
    libcxx_shared
    hidl_compat
    "-Wl,--version-script,${CACAO_CLIENT_MAP}"
    libbinder
    libcutils
    libutils
    log
    libhardware
    libhidlbase
    libandroid
    hw_graphics_mapper_2_0
    hw_graphics_alloc_2_0
    hw_graphics_common_1_0
    hidl_base_1_0
    hidl_manager_1_0
    libcacao_pal
)

set_target_properties(libcacao_client PROPERTIES
    OUTPUT_NAME "cacao_client"
)

# ══════════════════════════════════════════════════════════
# 4. libimageprocessorjni（armeabi-v7a + arm64-v8a）
# ══════════════════════════════════════════════════════════
add_library(libimageprocessorjni SHARED
    ${REPO_ROOT}/libimageprocessorjni/src/BypassCamera.cpp
    ${REPO_ROOT}/libimageprocessorjni/src/BypassCameraPhoto.cpp
    ${REPO_ROOT}/libimageprocessorjni/src/BypassCameraVideo.cpp
    ${REPO_ROOT}/libimageprocessorjni/src/BypassCameraBurst.cpp
    ${REPO_ROOT}/libimageprocessorjni/src/BypassCameraBurstBufferManager.cpp
    ${REPO_ROOT}/libimageprocessorjni/src/Caps.cpp
)

target_compile_options(libimageprocessorjni PRIVATE
    -Wall
    -Wno-unused-parameter
    -Wno-unused-variable
    -Wno-sign-compare
    -fvisibility=default
    -DLIBCACAO_SOONG_BUILD
    -fno-inline
)

# CMake 3.10 兼容性：使用 target_link_libraries 傳遞 linker flags 和相依庫
target_link_libraries(libimageprocessorjni PRIVATE
    -Wl,--pack-dyn-relocs=none
    -Wl,--allow-shlib-undefined
    libcxx_shared
    hidl_compat
    -Wl,--no-as-needed
    "-Wl,--version-script,${REPO_ROOT}/libimageprocessorjni/libimageprocessorjni.map.txt"
    libcacao_client
    libbinder
    libgui
    libutils
    libcutils
    log
    dl
    hw_graphics_alloc_2_0
)

set_target_properties(libimageprocessorjni PROPERTIES
    OUTPUT_NAME "imageprocessorjni"
)

# ══════════════════════════════════════════════════════════
# 5. libsomc_chokoballpal（armeabi-v7a 32-bit only）
#
# 從原廠 vendor/lib/libsomc_chokoballpal.so 重建。把 cammw_util 的
# shared-memory buffer 包成 android::GraphicBuffer 交給上層。
#
# 注意事項：
#   * 一定要 --pack-dyn-relocs=none。Android 9 的 linker 不認得 DT_RELR
#     （Android 11 才加入），會印 "unused DT entry: unknown (type 0x24 ...)"
#     然後整批相對重定位不套用，vtable/GOT 是垃圾，一進 CkbService thread
#     就 SIGSEGV。實機踩過。
#   * cammw_util_shmem_* 由 libcammw.so 提供（A9 原廠的 libcammw.so 直接
#     匯出這組符號），DT_NEEDED 與原版一致。
#   * -fno-rtti：原版 vtable 的 typeinfo slot 是 0。
# ══════════════════════════════════════════════════════════
if(ANDROID_ABI STREQUAL "armeabi-v7a")
    add_system_lib(libcammw)

    add_library(libsomc_chokoballpal SHARED
        ${REPO_ROOT}/libsomc_chokoballpal/src/ckb_pal_buf.cpp
    )

    target_include_directories(libsomc_chokoballpal PRIVATE
        ${REPO_ROOT}/libsomc_chokoballpal/include
    )

    # -fno-exceptions / -fno-unwind-tables：原版是把 libunwind_llvm 靜態連進去
    # 才有 _Unwind_Resume / __aeabi_unwind_cpp_pr0/1，A9 的 libc++.so 與 libc.so
    # 都不提供這些符號。我們不靜態連 libunwind，就得把 unwinding 需求拿掉，
    # 否則載入時解析不到。（libcacao_process_ctrl_gateway 也是同樣處理）
    target_compile_options(libsomc_chokoballpal PRIVATE
        -Os
        -fno-rtti
        -fno-exceptions
        -fno-unwind-tables
        -fno-asynchronous-unwind-tables
        -fno-lto
        -mfpu=vfpv3-d16
    )

    target_link_libraries(libsomc_chokoballpal PRIVATE
        -Wl,--pack-dyn-relocs=none
        -Wl,--allow-shlib-undefined
        libcxx_shared
        libui
        libutils
        log
        libcammw
    )

    # CMake 會自動加 lib 前綴，改回原版檔名／SONAME
    set_target_properties(libsomc_chokoballpal PROPERTIES
        OUTPUT_NAME "somc_chokoballpal"
    )
endif()
