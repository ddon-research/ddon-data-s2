#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceNpTrophyFlagArray;

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpTrophyFlagMask = uint32_t;

struct SceNpTrophyFlagArray
{
public:
    SceNpTrophyFlagMask flagBits[4];  // offset: 0x0
};
