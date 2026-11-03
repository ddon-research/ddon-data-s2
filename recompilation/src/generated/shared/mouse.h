#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceMouseData;

// Type aliases from DWARF
using __int32_t = int;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

struct SceMouseData
{
public:
    uint64_t timestamp;  // offset: 0x0
    bool connected;  // offset: 0x8
    uint32_t buttons;  // offset: 0xc
    int32_t xAxis;  // offset: 0x10
    int32_t yAxis;  // offset: 0x14
    int32_t wheel;  // offset: 0x18
    int32_t tilt;  // offset: 0x1c
    uint8_t reserve[8];  // offset: 0x20
};
