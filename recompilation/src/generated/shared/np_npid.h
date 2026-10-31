#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceNpId;
struct SceNpOnlineId;

// Type aliases from DWARF
using __uint8_t = unsigned char;
using uint8_t = __uint8_t;

struct SceNpOnlineId
{
public:
    char data[16];  // offset: 0x0
    char term;  // offset: 0x10
    char dummy[3];  // offset: 0x11
};

struct SceNpId
{
public:
    SceNpOnlineId handle;  // offset: 0x0
    uint8_t opt[8];  // offset: 0x14
    uint8_t reserved[8];  // offset: 0x1c
};
