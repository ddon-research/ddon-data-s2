#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtStream.h"

// Forward declarations
class MtMemoryStream;
class MtStream;

// Declarations
namespace nNetwork { class Coder; }
namespace nNetwork { class Decoder; }

// Type aliases from DWARF
using __int64_t = long int;
using __intptr_t = __int64_t;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using f64 = double;
using intptr = __intptr_t;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

namespace nNetwork {
    class Coder
    {
    public:
        Coder(void* buffer, u32 bufsiz);
        Coder(MtStream& stream);
        virtual ~Coder();
        bool isOverflow() const;
        void writeU8(u8 n);
        void writeS8(s8 n);
        void writeU16(u16 n);
        void writeU32(u32 n);
        void writeU64(u64 n);
        void writeS16(s16);
        void writeS32(s32 n);
        void writeS64(s64);
        void writeF32(f32 n);
        void writeF64(f64 n);
        void writeUPtr(uintptr);
        void writeSPtr(intptr);
        void write(const void* data_ptr, u32 data_size);
        void writeU32V(u32 val);
        void writeU64V(u64 val);
        void flushBit();
        void writeBit32(u32 bit, u32 width);
        void writeBit64(u64 bit, u32 width);
    private:
        MtStream& mStream;  // offset: 0x8
        MtMemoryStream mMemory;  // offset: 0x10
        u32 mBitOffset;  // offset: 0x38
        u8 mTempBuffer;  // offset: 0x3c
        bool mIsOverflow;  // offset: 0x3d
    };
}  // namespace nNetwork

namespace nNetwork {
    class Decoder
    {
    public:
        Decoder(void* buffer, u32 bufsiz);
        Decoder(MtStream& stream);
        ~Decoder();
        bool isDrain() const;
        u8 readU8();
        s8 readS8();
        u16 readU16();
        u32 readU32();
        u64 readU64();
        s16 readS16();
        s32 readS32();
        s64 readS64();
        f32 readF32();
        f64 readF64();
        u32 read(void* data_ptr, u32 data_size);
        u32 seek(u32 offset);
        void flushBit();
        u32 readU32V();
        u64 readU64V();
        u32 readBit32(u32 width);
        u64 readBit64(u32 width);
    private:
        void readBit();
    private:
        MtStream& mStream;  // offset: 0x0
        MtMemoryStream mMemory;  // offset: 0x8
        u32 mBitOffset;  // offset: 0x30
        u8 mTempBuffer;  // offset: 0x34
        bool mIsDrain;  // offset: 0x35
    };
}  // namespace nNetwork
