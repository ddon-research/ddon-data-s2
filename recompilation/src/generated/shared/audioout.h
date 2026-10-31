#pragma once

#include <cstdint>
#include <cstddef>

// Type aliases from DWARF
using __int16_t = short;
using __uint16_t = unsigned short;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using int16_t = __int16_t;
using uint16_t = __uint16_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

typedef struct
{
public:
    uint16_t output;  // offset: 0x0
    uint8_t channel;  // offset: 0x2
    uint8_t reserved8_1[1];  // offset: 0x3
    int16_t volume;  // offset: 0x4
    uint16_t rerouteCounter;  // offset: 0x6
    uint64_t flag;  // offset: 0x8
    uint64_t reserved64[2];  // offset: 0x10
} SceAudioOutPortState;
