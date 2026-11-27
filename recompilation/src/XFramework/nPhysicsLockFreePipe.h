#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { template <unsigned int buffer_size_log2> class LockFreePipe; }

// Type aliases from DWARF
using u32 = unsigned int;
using u8 = unsigned char;

namespace nPhysics {
    template <unsigned int buffer_size_log2>
    class LockFreePipe
    {
    public:
        LockFreePipe();
        ~LockFreePipe();
        bool read(void* output, const u32 size);
        bool write(const void* input, const u32 size);
        void reset();
    private:
        volatile u32 mReadOffset;  // offset: 0x0
        volatile u32 mWriteOffset;  // offset: 0x4
        alignas(16) u8 mBuffer[4096];  // offset: 0x10
        static const u32 BUFFER_SIZE_LOG2 = 12;
        static const u32 BUFFER_SIZE = 4096;
        static const u32 BUFFER_SIZE_MASK = 4095;
    };
}  // namespace nPhysics
