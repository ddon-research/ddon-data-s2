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
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;

// Declarations
class rVertices;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rVertices : public cResource
{
public:
    class MyDTI;
    struct VTS_HEADER;
public:
    using VTS_HEADER = rVertices::VTS_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct VTS_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        u32 VertexNum;  // offset: 0xc
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
    rVertices();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getVertexNum() const;
    MtVector3 getVertex(u32 No);
    u32 getResourceSize() const;
    void setDummyU32(u32);
    void setDummyF32(f32);
protected:
    virtual ~rVertices();
    bool allocMemory(u32 ParamBuffSize);
private:
    void constructParam();
    void destructParam();
    void freeMemory();
protected:
    u8* mpParamBuff;  // offset: 0x70
    u32 mParamBuffSize;  // offset: 0x78
    u32 mVertexNum;  // offset: 0x7c
public:
    static MyDTI DTI;
protected:
    static const u32 VTS_MAGIC = 5461078;
    static const u32 VTS_VERSION;
};

inline void* rVertices::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rVertices::rVertices() {
    this->mParamBuffSize = 0;
    this->mVertexNum = 0;
    this->mpParamBuff = nullptr;
    this->::cResource::mAttr = 22;
}

inline u32 rVertices::getVertexNum() const {
    return this->mVertexNum;
}

inline u32 rVertices::getResourceSize() const {
    return this->mParamBuffSize + 128u;
}
