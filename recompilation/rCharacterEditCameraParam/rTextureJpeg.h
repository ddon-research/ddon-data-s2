#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/rTexture.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class rTextureJpeg;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTextureJpeg : public rTexture
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static rTextureJpeg* createTextureJpeg(void* pJpegBuff, u32 buffSize, JOBHANDLE& jobHandle);
    static void deleteTextureJpeg(rTextureJpeg* pTextureJpeg);
    bool isJpegDecodedFailed();
    void setJpegDecodedFailed(bool f);
protected:
    rTextureJpeg(void* pJpegBuff, u32 buffSize);
    virtual ~rTextureJpeg();
    void decodeJpeg(u32 meaningless);
    bool decodeJpeg();
    void endDecoding(s32& ret) const;
protected:
    void* mpJpegBuffer;  // offset: 0x108
    u32 mJpegBufferSize;  // offset: 0x110
    bool mIsJpegDecodedFailed;  // offset: 0x114
public:
    static MyDTI DTI;
};
