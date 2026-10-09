#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtStream.h"

// Forward declarations
struct MtFloat2;
struct MtFloat3;
struct MtFloat4;
class MtStream;

// Declarations
class MtDataReader;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class MtDataReader
{
public:
    MtDataReader(MtStream& in, u32 bufsiz);
    virtual ~MtDataReader();
    u8 readU8();
    s8 readS8();
    u32 readString(MT_STR buf, u32 bufmax);
    virtual u16 readU16();  // vtable slot 2
    virtual u32 readU32();  // vtable slot 3
    virtual u64 readU64();  // vtable slot 4
    virtual size_t readUPtr();  // vtable slot 5
    virtual s16 readS16();  // vtable slot 6
    virtual s32 readS32();  // vtable slot 7
    virtual s64 readS64();  // vtable slot 8
    virtual size_t readSPtr();  // vtable slot 9
    virtual f32 readF32();  // vtable slot 10
    virtual f64 readF64();  // vtable slot 11
    virtual MtFloat2 readV2();  // vtable slot 12
    virtual MtFloat3 readV3();  // vtable slot 13
    virtual MtFloat4 readV4();  // vtable slot 14
    virtual u32 read(void* ptr, u32 bytes);  // vtable slot 15
    void align(u32 n);
    void skip(u32 bytes);
    void flush();
    u32 getPosition();
    u32 getLength();
    u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);
    bool isReadable() const;
protected:
    bool refill();
    const MtDataReader& operator=(const MtDataReader&);
protected:
    MtStream& mStream;  // offset: 0x8
    u8* mBuffer;  // offset: 0x10
    u32 mSeekPt;  // offset: 0x18
    u32 mBufsiz;  // offset: 0x1c
    u32 mBufsizMax;  // offset: 0x20
    u8 mLocalBuffer[4096];  // offset: 0x24
public:
    static const s32 DEFAULT_BUFFERSIZE = 4096;
};

// Inline, no code of its own: checked where it is inlined.
inline u8 MtDataReader::readU8() {
    if (this->mSeekPt >= this->mBufsiz) {
        if (this->::MtDataReader::refill() != false) {
            u8 n = this->mBuffer[this->mSeekPt];
            this->mSeekPt = this->mSeekPt + static_cast<u32>(1);
            return n;
        } else {
            return static_cast<u8>(0);
        }
    } else {
        u8 n = this->mBuffer[this->mSeekPt];
        this->mSeekPt = this->mSeekPt + static_cast<u32>(1);
        return n;
    }
}
