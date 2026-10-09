#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;

// Declarations
namespace MtCollisionUtil { class MtLocalBlockAllocator; }

// Type aliases from DWARF
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace MtCollisionUtil {
    class MtLocalBlockAllocator
    {
    public:
        struct BlockInfo;
    public:
        struct BlockInfo
        {
        public:
            u32 BlockNum;  // offset: 0x0
            u16 Used;  // offset: 0x4
            u16 AvailSize;  // offset: 0x6
        };
    public:
        MtLocalBlockAllocator();
        ~MtLocalBlockAllocator();
        bool reservationMemory(MtAllocator* pAllocator, u32 MemorySize, u32 BlockSize);
        void* memAlloc(u32 size);
        bool extendAlloc(void* * ppAddr, u32 NowSize, u32 AddSize);
        void memFree(void* padr);
        void dumpByTrace();
    protected:
        MtCriticalSection mCS;  // offset: 0x0
        u8* mpBuffer;  // offset: 0x8
        u32 mBufferSize;  // offset: 0x10
        BlockInfo* mpBlockInfo;  // offset: 0x18
        MtAllocator* mpAllocator;  // offset: 0x20
        u32 mBlockSize;  // offset: 0x28
        u32 mBlockNum;  // offset: 0x2c
        u32 mAllocIndex;  // offset: 0x30
    public:
        static const u16 BLOCK_NOUSE = 0;
        static const u16 BLOCK_USE = 1;
    };
}  // namespace MtCollisionUtil
