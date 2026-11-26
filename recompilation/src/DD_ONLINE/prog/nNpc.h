#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nNpc { struct voiceLoadTbl; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;

namespace nNpc {
    struct voiceLoadTbl
    {
    public:
        u32 Type;  // offset: 0x0
        MT_CTSTR Tag;  // offset: 0x8
    };
}  // namespace nNpc
