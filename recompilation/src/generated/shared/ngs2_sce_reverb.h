#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceNgs2ReverbI3DL2Param;

// Type aliases from DWARF
using __int32_t = int;
using __uint32_t = unsigned int;
using int32_t = __int32_t;
using uint32_t = __uint32_t;

struct SceNgs2ReverbI3DL2Param
{
public:
    float wet;  // offset: 0x0
    float dry;  // offset: 0x4
    int32_t room;  // offset: 0x8
    int32_t roomHF;  // offset: 0xc
    uint32_t reflectionPattern;  // offset: 0x10
    float decayTime;  // offset: 0x14
    float decayHFRatio;  // offset: 0x18
    int32_t reflections;  // offset: 0x1c
    float reflectionsDelay;  // offset: 0x20
    int32_t reverb;  // offset: 0x24
    float reverbDelay;  // offset: 0x28
    float diffusion;  // offset: 0x2c
    float density;  // offset: 0x30
    float HFReference;  // offset: 0x34
    uint32_t reserve[8];  // offset: 0x38
};
