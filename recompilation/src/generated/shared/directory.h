#pragma once

#include <cstdint>
#include <cstddef>

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

namespace io {
    namespace directory {

        bool exist(MT_CTSTR src);
        bool create(MT_CTSTR src);
        bool remove(MT_CTSTR src);

    }  // namespace directory
}  // namespace io
