#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceSaveDataIcon;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using __uint8_t = unsigned char;
using size_t = _Sizet;
using uint8_t = __uint8_t;

struct SceSaveDataIcon
{
public:
    void* buf;  // offset: 0x0
    size_t bufSize;  // offset: 0x8
    size_t dataSize;  // offset: 0x10
    uint8_t reserved[32];  // offset: 0x18
};
