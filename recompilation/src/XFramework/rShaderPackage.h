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
class MtPropertyList;
class MtStream;
namespace nDraw { struct SHADER; }
namespace nDraw { struct SHADER_CODE; }
namespace nDraw { struct SHADER_INPUT; }
namespace nDraw { struct SHADER_PARAM; }

// Declarations
class rShaderPackage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class rShaderPackage : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    struct CORE;
    struct SHADER_TABLE;
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
        u32 shader_version;  // offset: 0x4
        u16 version;  // offset: 0x8
        u16 shader_num;  // offset: 0xa
        u16 vs_num;  // offset: 0xc
        u16 ps_num;  // offset: 0xe
        u16 gs_num;  // offset: 0x10
        u16 ia_num;  // offset: 0x12
        u32 table_num;  // offset: 0x14
        u32 resource_num;  // offset: 0x18
        u32 body_size;  // offset: 0x1c
        uintptr body_offset;  // offset: 0x20
    };
public:
    struct CORE
    {
    public:
        nDraw::SHADER_PARAM* params;  // offset: 0x0
        SO_HANDLE* resources;  // offset: 0x8
        nDraw::SHADER_INPUT* ia_list;  // offset: 0x10
        nDraw::SHADER_CODE* vs_list;  // offset: 0x18
        nDraw::SHADER_CODE* ps_list;  // offset: 0x20
        nDraw::SHADER_CODE* gs_list;  // offset: 0x28
        rShaderPackage::SHADER_TABLE* tables;  // offset: 0x30
        rShaderPackage::SHADER_TABLE* ptable[4096];  // offset: 0x38
        nDraw::SHADER shaders[1];  // offset: 0x8038
    };
public:
    struct SHADER_TABLE
    {
    public:
        u64 id;  // offset: 0x0
        u32 next;  // offset: 0x8
        u32 index : 31;  // offset: 0xc
        u32 conflict : 1;  // offset: 0xc
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
    rShaderPackage();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const nDraw::SHADER* getShader(u64 id) const;
    const nDraw::SHADER* getShader(u32 id) const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    virtual ~rShaderPackage();
    void* memAlloc(u32);
    void memFree(void*);
private:
    static u32 getTableSize();
    const SHADER_TABLE* getTableHead(u32 index);
    const SHADER_TABLE* getTableByIndex(u32 index);
    const nDraw::SHADER* getShaderFromTableByIndex(u32 index) const;
    bool isExist(u32 id) const;
protected:
    HEADER mHeader;  // offset: 0x70
    CORE* mpCore;  // offset: 0x98
    u8* mpBody;  // offset: 0xa0
public:
    static MyDTI DTI;
protected:
    static const u32 TABLE_SIZE = 4096;
    static const u32 DATA_VERSION = 36;
};

inline void* rShaderPackage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rShaderPackage::rShaderPackage() {
    this->::cResource::mAttr = 16;
    this->mpBody = nullptr;
    this->mpCore = nullptr;
    this->mHeader.body_offset = 0;
    this->mHeader.resource_num = 0;
    this->mHeader.body_size = 0;
    this->mHeader.gs_num = 0;
    this->mHeader.ia_num = 0;
    this->mHeader.table_num = 0;
    this->mHeader.version = 0;
    this->mHeader.shader_num = 0;
    this->mHeader.vs_num = 0;
    this->mHeader.ps_num = 0;
    this->mHeader.magic = 0;
    this->mHeader.shader_version = 0;
}
