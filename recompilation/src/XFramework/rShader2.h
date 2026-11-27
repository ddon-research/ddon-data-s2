#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtStream;
class MtUI;
namespace nDraw { struct OBJECT; }
namespace nDraw { struct VARIABLE; }

// Declarations
class rShader2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rShader2 : public cResource
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
        u32 shader_version;  // offset: 0x8
        u32 object_num;  // offset: 0xc
        MT_CHAR* string_pool;  // offset: 0x10
        nDraw::OBJECT* pobjects[1];  // offset: 0x18
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
    rShader2();
    virtual ~rShader2();
    static u16 getMajorVersion();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void clear();  // vtable slot 15
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    const nDraw::OBJECT* * getObjects() const;
    u32 getObjectNum() const;
    u32 getShaderVersion();
protected:
    void freeVariable(nDraw::VARIABLE* pval);
    void freeStatement(void* pstt);
    void mapVariables(nDraw::VARIABLE* vals, u32 num);
    void mapStatement(void* pstt);
    void mapInitValues(u32* pinitvalues, nDraw::VARIABLE* pval);
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    HEADER* mpHeader;  // offset: 0x70
    nDraw::OBJECT* * mpObjects;  // offset: 0x78
    u32 mObjectNum;  // offset: 0x80
    u32 mCRC32;  // offset: 0x84
public:
    static MyDTI DTI;
protected:
    static const u32 MINOR_VERSION = 33;
};

inline void* rShader2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rShader2::rShader2() {
    this->::cResource::mAttr = 16;
    this->mObjectNum = 0;
    this->mpObjects = nullptr;
    this->mpHeader = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* rShader2::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rShader2::DTI)->memAlloc(sz, align, ::rShader2::DTI.::MtDTI::mID);
}

inline void rShader2::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rShader2::DTI)->memFree(p_addr);
}
