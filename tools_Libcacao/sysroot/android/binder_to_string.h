/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file binder_to_string.h
 * @brief Helper for parcelable.
 *
 * NOTE: This is a sysroot shim for API28 compatibility.
 * Excludes NDK binder includes which require Android API29+.
 */

#pragma once

#include <codecvt>
#include <locale>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <type_traits>

#if __has_include(<utils/StrongPointer.h>)
#include <utils/StrongPointer.h>
#define HAS_STRONG_POINTER
#endif

#if __has_include(<utils/String16.h>)
#include <utils/String16.h>
#define HAS_STRING16
#endif

// NOTE: Intentionally NOT including <android/binder_ibinder.h> to avoid API29+ dependency.
// HAS_NDK_INTERFACE is NOT defined.

// TODO: some things include libbinder without having access to libbase. This is
// due to frameworks/native/include, which symlinks to libbinder headers, so even
// though we don't use it here, we detect a different header, so that we are more
// confident libbase will be included
#if __has_include(<binder/RpcSession.h>)
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#define HAS_CPP_INTERFACE
#endif

namespace android {
namespace internal {

// ToString is a utility to generate string representation for various AIDL-supported types.
template <typename _T>
std::string ToString(const _T& t);

namespace details {

// Truthy if _T has toString() method.
template <typename _T>
class HasToStringMethod {
    template <typename _U>
    static auto _test(int) -> decltype(std::declval<_U>().toString(), std::true_type());
    template <typename _U>
    static std::false_type _test(...);

   public:
    enum { value = decltype(_test<_T>(0))::value };
};

// Truthy if _T has a overloaded toString(T)
template <typename _T>
class HasToStringFunction {
    template <typename _U>
    static auto _test(int) -> decltype(toString(std::declval<_U>()), std::true_type());
    template <typename _U>
    static std::false_type _test(...);

   public:
    enum { value = decltype(_test<_T>(0))::value };
};

template <typename T, template <typename...> typename U>
struct IsInstantiationOf : std::false_type {};

template <template <typename...> typename U, typename... Args>
struct IsInstantiationOf<U<Args...>, U> : std::true_type {};

// Truthy if _T is like a pointer: one of sp/optional/shared_ptr
template <typename _T>
class IsPointerLike {
    template <typename _U>
    static std::enable_if_t<
#ifdef HAS_STRONG_POINTER
            IsInstantiationOf<_U, sp>::value ||
#endif
                    IsInstantiationOf<_U, std::optional>::value ||
                    IsInstantiationOf<_U, std::unique_ptr>::value ||
                    IsInstantiationOf<_U, std::shared_ptr>::value,
            std::true_type>
    _test(int);
    template <typename _U>
    static std::false_type _test(...);

   public:
    enum { value = decltype(_test<_T>(0))::value };
};

// Truthy if _T is like a container
template <typename _T>
class IsIterable {
    template <typename _U>
    static auto _test(int)
            -> decltype(begin(std::declval<_U>()), end(std::declval<_U>()), std::true_type());
    template <typename _U>
    static std::false_type _test(...);

   public:
    enum { value = decltype(_test<_T>(0))::value };
};

template <typename _T>
struct TypeDependentFalse {
    enum { value = false };
};

}  // namespace details

template <typename _T>
std::string ToString(const _T& t) {
    if constexpr (std::is_same_v<bool, _T>) {
        return t ? "true" : "false";
    } else if constexpr (std::is_same_v<char16_t, _T>) {
        _Pragma("clang diagnostic push")
                _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"");
        return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>().to_bytes(t);
        _Pragma("clang diagnostic pop");
    } else if constexpr (std::is_arithmetic_v<_T>) {
        return std::to_string(t);
    } else if constexpr (std::is_same_v<std::string, _T>) {
        return t;
#ifdef HAS_CPP_INTERFACE
    } else if constexpr (std::is_base_of_v<IInterface, _T>) {
        std::stringstream ss;
        ss << "interface:" << std::hex << &t;
        return ss.str();
    } else if constexpr (std::is_same_v<IBinder, _T>) {
        std::stringstream ss;
        ss << "binder:" << std::hex << &t;
        return ss.str();
#endif
#ifdef HAS_STRING16
    } else if constexpr (std::is_same_v<String16, _T>) {
        std::stringstream out;
        out << t;
        return out.str();
#endif
    } else if constexpr (details::IsPointerLike<_T>::value || std::is_pointer_v<_T>) {
        if (!t) return "(null)";
        std::stringstream out;
        out << ToString(*t);
        return out.str();
    } else if constexpr (details::HasToStringMethod<_T>::value) {
        return t.toString();
    } else if constexpr (details::HasToStringFunction<_T>::value) {
        return toString(t);
    } else if constexpr (details::IsIterable<_T>::value) {
        std::stringstream out;
        bool first = true;
        out << "[";
        for (const auto& e : t) {
            if (first) {
                first = false;
            } else {
                out << ", ";
            }
            out << ToString<typename _T::value_type>(e);
        }
        out << "]";
        return out.str();
    } else {
        static_assert(details::TypeDependentFalse<_T>::value, "no toString implemented, huh?");
    }
}

}  // namespace internal
}  // namespace android

#ifdef HAS_STRONG_POINTER
#undef HAS_STRONG_POINTER
#endif

#ifdef HAS_STRING16
#undef HAS_STRING16
#endif

#ifdef HAS_CPP_INTERFACE
#undef HAS_CPP_INTERFACE
#endif
