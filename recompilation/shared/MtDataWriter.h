#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtStream.h"

// Forward declarations
struct MtFloat3;
struct MtFloat4;
class MtStream;
class cEditParam;
class cStorageDataEdit;

// Declarations
class MtDataWriter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
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

class MtDataWriter
{
    // inferred: cEditParam::save names MtDataWriter::mSeekPt
    friend class cEditParam;
    // inferred: cStorageDataEdit::save names MtDataWriter::mSeekPt
    friend class cStorageDataEdit;
public:
    struct Frame;
    struct Label;
public:
    struct Frame
    {
    public:
        u32 base;  // offset: 0x0
        u32 pt;  // offset: 0x4
        u32 offset;  // offset: 0x8
    };
public:
    struct Label
    {
    public:
        const void* address;  // offset: 0x0
        u32 offset : 31;  // offset: 0x8
        u32 backtrack : 1;  // offset: 0x8
    };
public:
    MtDataWriter(MtStream& out, u32 bufsiz, u32 labelsiz);
    virtual ~MtDataWriter();
    void writeU8(u8 n);
    void writeS8(s8 n);
    virtual void writeU16(u16 n);  // vtable slot 2
    virtual void writeU32(u32 n);  // vtable slot 3
    virtual void writeU64(u64 n);  // vtable slot 4
    virtual void writeS16(s16 n);  // vtable slot 5
    virtual void writeS32(s32 n);  // vtable slot 6
    virtual void writeS64(s64 n);  // vtable slot 7
    virtual void writeF32(f32 n);  // vtable slot 8
    virtual void writeF64(f64 n);  // vtable slot 9
    virtual void writeUPtr(uintptr n);  // vtable slot 10
    virtual void writeSPtr(intptr n);  // vtable slot 11
    void writeV3(const MtFloat3& ft3);
    void writeV4(const MtFloat4& ft4);
    void writeString(MT_CTSTR str);
    virtual u32 write(const void* ptr, u32 bytes);  // vtable slot 12
    void write16(const void* ptr, u32 bytes);
    void write32(const void* ptr, u32 bytes);
    virtual void writeFormat(const void* ptr, MT_CTSTR format, u32 count);  // vtable slot 13
    virtual void flush();  // vtable slot 14
    virtual u32 getPosition();  // vtable slot 15
    virtual u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);  // vtable slot 16
    virtual bool addLabel(const void* addr);  // vtable slot 17
    virtual void writeLabel(const void* addr);  // vtable slot 18
    void pushLabel();
    void popLabel();
    void align(u32 n);
    virtual u32 getLength();  // vtable slot 19
    bool isWritable() const;
protected:
    virtual void setU32(u32 bufofs, u32 value);  // vtable slot 20
    virtual void setU64(u32 bufofs, u64 value);  // vtable slot 21
    const MtDataWriter& operator=(const MtDataWriter&);
protected:
    MtStream& mStream;  // offset: 0x8
    u8* mBuffer;  // offset: 0x10
    u32 mSeekPt;  // offset: 0x18
    u32 mBufsiz;  // offset: 0x1c
    u32 mBufsizMax;  // offset: 0x20
    Frame mFrameStack[64];  // offset: 0x24
    Frame* mFrame;  // offset: 0x328
    s32 mFramePt;  // offset: 0x330
    Label* mLabel;  // offset: 0x338
    u32 mLabelMax;  // offset: 0x340
public:
    static const s32 DEFAULT_BUFFERSIZE = 4096;
    static const s32 DEFAULT_LABELSIZE = 4096;
protected:
    static const s32 FRAME_MAX = 64;
};
