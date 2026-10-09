#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtStream;
class MtString;
class MtTime;

// Declarations
class BitReader;
class BitWriter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class BitReader
{
private:
    BitReader& operator=(const BitReader&);
    u32 alphaDecode();
    u32 gammaDecode();
public:
    BitReader(MtStream& in);
    ~BitReader();
    u32 streamPos() const;
    u32 bitPos() const;
    bool isEliasDelta() const;
    void isEliasDelta(bool);
    void fillBuffer();
    u32 readBit();
    bool readBool();
    u32 readU32(u32 nBits);
    void alignBits();
    u64 readU64();
    u32 readU32();
    u32 readRawU32();
    u16 readU16();
    u8 readU8();
    u8 readRawU8();
    s64 readS64();
    s32 readS32();
    s16 readS16();
    s8 readS8();
    f32 readF32();
    f64 readF64();
    u32 readString(MT_STR buf, u32 bufmax);
    MtString readString();
    u64 readEliasU64();
    u32 readEliasU32();
    u16 readEliasU16();
    u8 readEliasU8();
    s64 readEliasS64();
    s32 readEliasS32();
    s16 readEliasS16();
    s8 readEliasS8();
    void readBytes(void* pdst, u32 nBytes);
    BitReader& operator>>(bool&);
    BitReader& operator>>(u64&);
    BitReader& operator>>(u32&);
    BitReader& operator>>(u16&);
    BitReader& operator>>(u8&);
    BitReader& operator>>(s64&);
    BitReader& operator>>(s32&);
    BitReader& operator>>(s16&);
    BitReader& operator>>(s8&);
    BitReader& operator>>(f32&);
    BitReader& operator>>(f64&);
    BitReader& operator>>(MtTime&);
    BitReader& operator>>(MtString&);
private:
    MtStream& mStream;  // offset: 0x0
    u32 mBitPos;  // offset: 0x8
    u8 mBits[8];  // offset: 0xc
    bool mIsEliasDelta;  // offset: 0x14
    u32 mBytesInBuffer;  // offset: 0x18
    static const u32 BUFFER = 8;
};

class BitWriter
{
public:
    BitWriter(MtStream& out);
    BitWriter& operator=(const BitWriter&);
    u32 streamPos() const;
    u32 bitPos() const;
    bool isEliasDelta() const;
    void isEliasDelta(bool);
    BitWriter& operator<<(bool);
    BitWriter& operator<<(u64);
    BitWriter& operator<<(u32);
    BitWriter& operator<<(u16);
    BitWriter& operator<<(u8);
    BitWriter& operator<<(s64);
    BitWriter& operator<<(s32);
    BitWriter& operator<<(s16);
    BitWriter& operator<<(s8);
    BitWriter& operator<<(f32);
    BitWriter& operator<<(f64);
    BitWriter& operator<<(MT_CTSTR);
    BitWriter& operator<<(const MtTime&);
    void writeU32(u32 val, u32 nBits);
    void writeBit(u32 val);
    void writeBool(bool val);
    void writeU64(u64 n);
    void writeU32(u32 n);
    void writeRawU32(u32 n);
    void writeU16(u16 n);
    void writeU8(u8 n);
    void writeRawU8(u8 n);
    void writeS64(s64 n);
    void writeS32(s32 n);
    void writeS16(s16 n);
    void writeS8(s8 n);
    void writeF32(f32 n);
    void writeF64(f64 n);
    void writeString(MT_CTSTR str);
    void writeEliasU64(u64 val);
    void writeEliasU32(u32 val);
    void writeEliasU16(u16 val);
    void writeEliasU8(u8 val);
    void writeEliasS64(s64 val);
    void writeEliasS32(s32 val);
    void writeEliasS16(s16 val);
    void writeEliasS8(s8 val);
    void writeBytes(const void* psrc, u32 nBytes);
    void flushBits();
private:
    u32 bsr(u32 v);
    u32 bsr64(u64 v);
    u32 bitcount(u64 v);
    void alphaEncode(u32 v);
    void gammaEncode(u32 v);
private:
    MtStream& mStream;  // offset: 0x0
    u32 mBitPos;  // offset: 0x8
    u8 mBits[64];  // offset: 0xc
    bool mIsEliasDelta;  // offset: 0x4c
    static const u32 BUFFER = 64;
};
