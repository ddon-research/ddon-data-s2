#pragma once

#include <cstdint>
#include <cstddef>

namespace MtMemoryAllocator {
    enum FrameworkAllocator
    {
        RESOURCE = 12,
        SYSTEM = 13,
        UNIT = 14,
        AREA = 15,
        SOUND = 16,
        PHYSICS = 17,
        NETWORK = 18,
        AI = 19,
        EFFECT = 20,
        GUI = 21,
        INSTANCING = 22,
        VIRTUAL_EXTEND = 23,
        APP_ALLOCATOR = 24,
    };
}  // namespace MtMemoryAllocator
