// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtDataReader.h"
#include "MtAllocator.h"
#include "MtMath.h"
#include "MtMemory.h"
#include "MtStream.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtDataReader::MtDataReader(MtStream& in, u32 bufsiz) : mStream(in) {
    u32 t0 = in.getLength();
    mBufsizMax = (((bufsiz <= 4096u) ? 4096u : bufsiz) < t0) ? ((bufsiz <= 4096u) ? 4096u : bufsiz) : t0;
    mSeekPt = 0;
    mBufsiz = 0;
    if (((((bufsiz <= 4096u) ? 4096u : bufsiz) < t0) ? ((bufsiz <= 4096u) ? 4096u : bufsiz) : t0) <= 4096u) {
        mBuffer = &mLocalBuffer[0];
    } else {
        mBuffer = static_cast<u8*>(MtMemory::mpAllocatorType[7]->memAlloc(bufsiz, 128u));
    }
}

MtDataReader::~MtDataReader() {
    if (mBuffer != (&mLocalBuffer[0])) {
        MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(mBuffer));
    }
    mStream.seek(static_cast<s32>(mSeekPt - mBufsiz), MtStream::ORG_CURRENT);
}

__attribute__((weak)) u32 MtDataReader::readString(MT_STR buf, u32 bufmax) {
        u32 len = 0;
        s8 c = static_cast<s8>(readU8());
        while (c != 0) {
            if (len < bufmax - 1) {
                buf[len++] = c;
            }
            c = static_cast<s8>(readU8());
        }
        buf[len] = 0;
        return len;
}

__attribute__((weak)) u16 MtDataReader::readU16() {
        if (mSeekPt + 1u >= mBufsiz && !refill()) {
            return 0;
        }
        u16 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) u32 MtDataReader::readU32() {
        if (mSeekPt + 3u >= mBufsiz && !refill()) {
            return 0;
        }
        u32 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) u64 MtDataReader::readU64() {
        if (mSeekPt + 7u >= mBufsiz && !refill()) {
            return 0;
        }
        u64 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

size_t MtDataReader::readUPtr() {
    return readU64();
}

__attribute__((weak)) s16 MtDataReader::readS16() {
        if (mSeekPt + 1u >= mBufsiz && !refill()) {
            return 0;
        }
        s16 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) s32 MtDataReader::readS32() {
        if (mSeekPt + 3u >= mBufsiz && !refill()) {
            return 0;
        }
        s32 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) s64 MtDataReader::readS64() {
        if (mSeekPt + 7u >= mBufsiz && !refill()) {
            return 0;
        }
        s64 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

size_t MtDataReader::readSPtr() {
    return static_cast<size_t>(readS64());
}

__attribute__((weak)) f32 MtDataReader::readF32() {
        if (mSeekPt + 3u >= mBufsiz && !refill()) {
            return 0;
        }
        f32 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) f64 MtDataReader::readF64() {
        if (mSeekPt + 7u >= mBufsiz && !refill()) {
            return 0;
        }
        f64 n;
        __builtin_memcpy(&n, mBuffer + mSeekPt, sizeof(n));
        mSeekPt += sizeof(n);
        return n;
}

__attribute__((weak)) MtFloat2 MtDataReader::readV2() {
        if (mSeekPt + 7u >= mBufsiz && !refill()) {
            return MtFloat2::Zero;
        }
        union { u32 i; f32 f; } ifu;
        MtFloat2 v;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.x = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.y = ifu.f;
        mSeekPt += 4;
        return v;
}

__attribute__((weak)) MtFloat3 MtDataReader::readV3() {
        if (mSeekPt + 11u >= mBufsiz && !refill()) {
            return MtFloat3::Zero;
        }
        union { u32 i; f32 f; } ifu;
        MtFloat3 v;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.x = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.y = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.z = ifu.f;
        mSeekPt += 4;
        return v;
}

__attribute__((weak)) MtFloat4 MtDataReader::readV4() {
        if (mSeekPt + 15u >= mBufsiz && !refill()) {
            return MtFloat4::Zero;
        }
        union { u32 i; f32 f; } ifu;
        MtFloat4 v;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.x = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.y = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.z = ifu.f;
        mSeekPt += 4;
        __builtin_memcpy(&ifu, mBuffer + mSeekPt, sizeof(ifu));
        v.w = ifu.f;
        mSeekPt += 4;
        return v;
}

u32 MtDataReader::read(void* ptr, u32 bytes) {
    u32 rb = bytes;
    if ((bytes + mSeekPt) < mBufsiz) {
        memcpy(ptr, static_cast<const void*>(&mBuffer[mSeekPt]), bytes);
        mSeekPt = bytes + mSeekPt;
    } else {
        u32 p = mBufsiz - mSeekPt;
        if (mBufsiz == 0) {
            mBufsiz = mBufsizMax;
        }
        memcpy(ptr, static_cast<const void*>(&mBuffer[mSeekPt]), static_cast<size_t>(p));
        rb = p + mStream.read(static_cast<char*>(ptr) + p, bytes - p);
        mBufsiz = mStream.read(static_cast<void*>(mBuffer), mBufsiz);
        mSeekPt = 0;
    }
    return rb;
}

__attribute__((weak)) void MtDataReader::align(u32 n) {
        u32 pos = MtDataReader::getPosition() & (n - 1);
        if (pos != 0) {
            for (u32 i = 0; i < n - pos; i++) {
                readU8();
            }
        }
}

__attribute__((weak)) void MtDataReader::skip(u32 bytes) {
        for (u32 i = 0; i < bytes; i++) {
            readU8();
        }
}

void MtDataReader::flush() {
    mStream.flush();
}

u32 MtDataReader::getPosition() {
    return (mStream.getPosition() - mBufsiz) + mSeekPt;
}

u32 MtDataReader::seek(s32 offset, MtStream::SEEK_ORIGIN origin) {
    MtStream& t0 = mStream;
    unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&t0) + 0)) + 160);
    if (origin == MtStream::ORG_CURRENT) {
        u32 t2 = t0.getPosition();
        u32 t3 = t0.seek(static_cast<s32>(((offset - mBufsiz) + mSeekPt) + t2), MtStream::ORG_BEGIN);
        mBufsiz = 0;
        mSeekPt = 0;
        return t3;
    } else {
        u32 t4 = t0.seek(offset, origin);
        mBufsiz = 0;
        mSeekPt = 0;
        return t4;
    }
}

bool MtDataReader::refill() {
    u32 p = mBufsiz - mSeekPt;
    if (mBufsiz == 0) {
        mBufsiz = mBufsizMax;
    }
    for (u32 i = 0; p != i; i += 1u) {
        mBuffer[i] = mBuffer[i + mSeekPt];
    }
    mBufsiz = p + mStream.read(static_cast<void*>(&mBuffer[p]), mBufsiz - p);
    mSeekPt = 0;
    return mBufsiz != 0;
}

