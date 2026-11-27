#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cResource.h"
#include "nDrawShader.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
namespace nDraw { struct SHADER_CODE; }
namespace nDraw { struct SHADER_INPUT; }
namespace nDraw { struct SHADER_KEY; }

// Declarations
class rShaderCache;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class rShaderCache : public cResource
{
public:
    class MyDTI;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 major_version;  // offset: 0x4
        u16 minor_version;  // offset: 0x6
        u64 id;  // offset: 0x8
        u32 shader_version;  // offset: 0x10
        u32 padding1;  // offset: 0x14
        nDraw::SHADER_INPUT ia;  // offset: 0x18
        nDraw::SHADER_CODE vs;  // offset: 0x38
        nDraw::SHADER_CODE ps;  // offset: 0x48
        nDraw::SHADER_CODE gs;  // offset: 0x58
        nDraw::SHADER_CODE hs;  // offset: 0x68
        nDraw::SHADER_CODE ds;  // offset: 0x78
        nDraw::SHADER_CODE cs;  // offset: 0x88
        u32 hash[5];  // offset: 0x98
        u32 padding2;  // offset: 0xac
        nDraw::SHADER_KEY shader_key;  // offset: 0xb0
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
    rShaderCache();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    nDraw::SHADER_CODE* getVSCode() const;
    nDraw::SHADER_CODE* getPSCode() const;
    nDraw::SHADER_CODE* getGSCode() const;
    nDraw::SHADER_CODE* getHSCode() const;
    nDraw::SHADER_CODE* getDSCode() const;
    nDraw::SHADER_CODE* getCSCode() const;
    nDraw::SHADER_INPUT* getInput() const;
    u64 getID() const;
protected:
    virtual ~rShaderCache();
    bool remappingShaderKey(nDraw::SHADER_KEY* pskey);
    virtual bool load(MtStream& in);  // vtable slot 11
protected:
    HEADER* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u16 MINOR_VERSION = 36;
};

inline void* rShaderCache::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rShaderCache::rShaderCache() {
    this->::cResource::mAttr = 16;
    this->mpHeader = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* rShaderCache::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rShaderCache::DTI)->memAlloc(sz, align, ::rShaderCache::DTI.::MtDTI::mID);
}

inline void rShaderCache::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rShaderCache::DTI)->memFree(p_addr);
}
