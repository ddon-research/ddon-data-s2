#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { class Thread; }

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using u32 = unsigned int;
using uintptr = __uintptr_t;

namespace nPhysics {
    class Thread
    {
    private:
        Thread();
        ~Thread();
        static void addID(const uintptr id);
    public:
        static u32 getIndex(const uintptr id);
    private:
        static const u32 MAX_THREAD = 256;
        static u32 mNumThreadID;
        static uintptr mThreadID[256];
    };
}  // namespace nPhysics

inline nPhysics::Thread::Thread() {
}
