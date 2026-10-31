#pragma once

#include <cstdint>
#include <cstddef>

namespace MtMemoryAllocator {
    enum AppAllocator
    {
        TEST_UNIT = 24,
        BROWSER = 25,
        DDO_MAX_ALLOCATOR = 26,
    };
}  // namespace MtMemoryAllocator
