#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct MT_ENUM;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;

struct MT_ENUM
{
public:
    MT_CTSTR name;  // offset: 0x0
    s32 value;  // offset: 0x8
};
