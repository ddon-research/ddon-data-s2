// The harness's field dump (024 T991): a generated driver walks the loaded
// table through its own accessors (`getDataNum`, `getData(i)`) and writes
// each record's fields as JSON, with the offset each field has on the host,
// so the report can check the host layout against DWARF's before it
// compares a value. Included by a driver before the bundle's headers. It
// never interprets file bytes: it prints what the root's `load` stored.
#pragma once

#include <cstdio>
#include <cstring>
#include <string>
#include <type_traits>
#include <utility>

#include "runtime.h"

// Whether `T` has the table accessors the dump walks.
template <class T, class = void>
struct ddon_is_table : std::false_type {};
template <class T>
struct ddon_is_table<T, std::void_t<decltype(std::declval<T&>().getDataNum()),
                                    decltype(std::declval<T&>().getData(0u))>>
    : std::true_type {};

// One field as JSON: its name, its offset on the host, and its value.
// Integers and enums are decimal text (64 bits stay exact), floats their
// bits and text, a bool `true`/`false`; any other type is `unprinted`.
template <class T>
void ddon_dump_field(std::string& out, const char* name, const void* record, const T& value) {
    long offset = static_cast<long>(reinterpret_cast<const char*>(&value) -
                                    static_cast<const char*>(record));
    out += "{\"name\":\"";
    out += name;
    out += "\",\"offset\":";
    out += std::to_string(offset);
    out += ",\"size\":";
    out += std::to_string(sizeof(T));
    if constexpr (std::is_same_v<T, bool>) {
        out += ",\"kind\":\"bool\",\"value\":";
        out += value ? "true" : "false";
    } else if constexpr (std::is_enum_v<T> || std::is_integral_v<T>) {
        using Integer = std::conditional_t<std::is_enum_v<T>, std::underlying_type<T>,
                                           std::common_type<T>>;
        using U = typename Integer::type;
        out += std::is_enum_v<T> ? ",\"kind\":\"enum\"" : "";
        if constexpr (std::is_signed_v<U>) {
            out += std::is_enum_v<T> ? "" : ",\"kind\":\"signed\"";
            out += ",\"value\":\"" + std::to_string(static_cast<long long>(value)) + "\"";
        } else {
            out += std::is_enum_v<T> ? "" : ",\"kind\":\"unsigned\"";
            out += ",\"value\":\"" + std::to_string(static_cast<unsigned long long>(value)) + "\"";
        }
    } else if constexpr (std::is_floating_point_v<T>) {
        unsigned long long bits = 0;
        std::memcpy(&bits, &value, sizeof(T) < sizeof bits ? sizeof(T) : sizeof bits);
        // The longest text is 24 + 16 hex digits + 11 + a 24-character
        // `%.17g` (`-1.2345678901234567e-300`) + the quote: 76 bytes. 64 cut
        // the closing quote off `-0.80000001192092896` (027 plan-P1).
        char text[128];
        std::snprintf(text, sizeof text, ",\"kind\":\"float\",\"bits\":\"%llx\",\"value\":\"%.17g\"",
                      bits, static_cast<double>(value));
        out += text;
    } else {
        out += ",\"kind\":\"unprinted\"";
    }
    out += "}";
}
