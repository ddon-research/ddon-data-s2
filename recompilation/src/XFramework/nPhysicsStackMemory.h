#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { class StackMemory; }

// Type aliases from DWARF
using u32 = unsigned int;
using u8 = unsigned char;

namespace nPhysics {
    class StackMemory
    {
    public:
        struct MEMORY_BLOCK;
    public:
        struct MEMORY_BLOCK
        {
        public:
            u32 UsedSize;  // offset: 0x0
            void* StartAddress;  // offset: 0x8
            u32 ResultSize;  // offset: 0x10
            void* ResultAddress;  // offset: 0x18
        };
    public:
        StackMemory();
        ~StackMemory();
        void create(const u32 memory_size, const u32 stack_size);
        void clear();
        void* push(const u32 size, const u32 alignment);
        void pop(void* address);
    private:
        u8* mMemoryAddress;  // offset: 0x0
        u32 mMemorySize;  // offset: 0x8
        u32 mUsedMemorySize;  // offset: 0xc
        MEMORY_BLOCK* mMemoryBlock;  // offset: 0x10
        MEMORY_BLOCK* mCurrentMemoryBlock;  // offset: 0x18
        u32 mStackSize;  // offset: 0x20
    };
}  // namespace nPhysics
