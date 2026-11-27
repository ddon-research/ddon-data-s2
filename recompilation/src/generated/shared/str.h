#pragma once

#include <cstdint>
#include <cstddef>

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;

namespace via {
    namespace str {

        size_t length(MT_CTSTR str);
        s32 compare(MT_CTSTR sourceStr1, MT_CTSTR sourceStr2);

    }  // namespace str
}  // namespace via
