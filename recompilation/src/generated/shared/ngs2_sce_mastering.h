#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "ngs2_system.h"

// Forward declarations
struct SceNgs2RackOption;

// Declarations
struct SceNgs2MasteringRackOption;

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;

struct SceNgs2MasteringRackOption
{
public:
    SceNgs2RackOption rackOption;  // offset: 0x0
    uint32_t maxChannels;  // offset: 0x80
    uint32_t numPeakMeterBlocks;  // offset: 0x84
};
