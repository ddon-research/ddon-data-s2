#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceRtcTick;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using uint64_t = __uint64_t;

struct SceRtcTick
{
public:
    uint64_t tick;  // offset: 0x0
};
