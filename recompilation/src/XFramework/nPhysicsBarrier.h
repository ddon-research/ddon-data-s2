#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { class Barrier; }

// Type aliases from DWARF
using s32 = int;

namespace nPhysics {
    class Barrier
    {
    public:
        Barrier();
        ~Barrier();
        void initialize();
        void setTotalCount(const s32 total_count);
        void sync(const s32 id);
    };
}  // namespace nPhysics
