#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceSha256Context;

// Type aliases from DWARF
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

struct SceSha256Context
{
public:
    uint32_t h[8];  // offset: 0x0
    uint8_t initialized;  // offset: 0x20
    uint8_t pad[3];  // offset: 0x21
    uint16_t usRemains;  // offset: 0x24
    uint16_t usComputed;  // offset: 0x26
    uint64_t ullTotalLen;  // offset: 0x28
    uint8_t buf[64];  // offset: 0x30
    uint8_t result[32];  // offset: 0x70
};
