#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "rSoundSource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtFileStream;
class MtObject;
class MtStream;
class rSoundStreamSourcePackage;

// Declarations
class rSoundSourceAT9;
class rSoundSourceStreamAT9;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundSourceAT9 : public rSoundSource
{
public:
    class MyDTI;
    struct FACT_CHUNK;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct FACT_CHUNK
    {
    public:
        u32 TotalSamples;  // offset: 0x0
        u32 InputAndOverlapDelaySamples;  // offset: 0x4
        u32 EncoderDelaySamples;  // offset: 0x8
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
    rSoundSourceAT9();
    virtual ~rSoundSourceAT9();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual const MtDTI* getDTINative() const;  // vtable slot 34
    virtual bool checkNativeEncodeParameter(const u32 encodeParam) const;  // vtable slot 35
    virtual bool load(MtStream& in);  // vtable slot 11
    bool setFileStream(MtFileStream& in);
    bool setBuffer(void* pbuf, MtStream& in);
protected:
    bool initAT9(MtStream& in);
private:
    u32 mEncodeParam;  // offset: 0x13c
public:
    static const u32 AT9_NATIVEFILEVERSION = 1;
    static const u32 CHUNK_TAG_ENCODEPARAM = 1885564517;
    static MyDTI DTI;
};

class rSoundSourceStreamAT9 : public rSoundSourceAT9
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
    rSoundSourceStreamAT9();
    virtual ~rSoundSourceStreamAT9();
    virtual const MtDTI* getDTINative() const;  // vtable slot 34
    virtual bool prepareToBuffer();  // vtable slot 17
    bool open();
    bool close();
    u32 seek(u32 pos, u32* pid);
    u32 read(void* pdest, u32 size, u32* pid);
    rSoundStreamSourcePackage* getSourcePackage() const;
    u32 getPackageFileOffset();
private:
    u32 mPackageFileOffset;  // offset: 0x140
    rSoundStreamSourcePackage* mpStreamSourcePackage;  // offset: 0x148
public:
    static MyDTI DTI;
};
