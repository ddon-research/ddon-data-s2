#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class MtVector3;
class MtVector4;

// Declarations
class rFreeF32Tbl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class rFreeF32Tbl : public cResource
{
public:
    enum
    {
        DATA_VERSION = 2,
        HEADER_SIZE = 8,
    };
public:
    class MyDTI;
    struct stHeader;
    struct stTag;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTag
    {
    public:
        u32 Tag;  // offset: 0x0
        u32 Type;  // offset: 0x4
        f32* pVal;  // offset: 0x8
    };
public:
    struct stHeader
    {
    public:
        u32 Version;  // offset: 0x0
        u32 TagNum;  // offset: 0x4
        rFreeF32Tbl::stTag Tags[1];  // offset: 0x8
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
    rFreeF32Tbl();
    virtual ~rFreeF32Tbl();
private:
    void allocMem(u32 size);
    void freeMem();
public:
    virtual f32 getIndexF32(u32 idx, f32 def);  // vtable slot 16
    virtual MtVector3 getIndexVec3(u32 idx, const MtVector3& def);  // vtable slot 17
    virtual MtVector4 getIndexVec4(u32 idx, const MtVector4& def);  // vtable slot 18
    f32 getTagF32(u32 tag, f32 def);
    MtVector3 getTagVec3(u32 tag, const MtVector3& def);
    MtVector4 getTagVec4(u32 tag, const MtVector4& def);
    f32 getTagF32(MT_CTSTR tag, f32 def);
    MtVector3 getTagVec3(MT_CTSTR tag, const MtVector3& def);
    MtVector4 getTagVec4(MT_CTSTR tag, const MtVector4& def);
private:
    virtual u32 getTagIndex(u32 tag);  // vtable slot 19
    f32* getIndexTop(u32 idx);
public:
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
private:
    stHeader* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
};
