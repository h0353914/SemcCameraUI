// Android 9 相容性實作：提供 Android 14 新增的 HIDL/utils 方法的 weak symbol 定義
// 這些方法在 Android 9 的系統庫中不存在，需補充以通過連結

#include <hidl/Status.h>
#include <utils/RefBase.h>

namespace android {
namespace hardware {
namespace details {
    // onValueRetrieval()：Android 14 在 Return<T>::operator T() 中呼叫，Android 9 無此符號
    // NO-OP 實作（等同 Android 9 行為：不做錯誤斷言）
    __attribute__((weak)) void return_status::onValueRetrieval() const {}
} // namespace details
} // namespace hardware

// incStrongRequireStrong()：Android 14 sp<T> 移動語義中呼叫，Android 9 無此符號
// 等同於普通的 incStrong，無額外檢查（Android 9 行為）
__attribute__((weak)) void RefBase::incStrongRequireStrong(const void* id) const {
    incStrong(id);
}

} // namespace android

