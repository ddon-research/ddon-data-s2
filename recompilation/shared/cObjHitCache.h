#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cHitGeom;
class cHitNode;
class uDDOModel;

// Declarations
class cObjHitCache;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cObjHitCache : public MtObject
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
    cObjHitCache();
    void clear();
    void copy(const cObjHitCache* pSrc, bool copy_node);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void resetHitCache();
public:
    u64 mPri;  // offset: 0x8
    u32 mUID;  // offset: 0x10
    f32 mTimer;  // offset: 0x14
    f32 mAge;  // offset: 0x18
    s32 mLinkID;  // offset: 0x1c
    u32 mAtkAttr;  // offset: 0x20
    u32 mDfdAttr;  // offset: 0x24
    cHitNode* mpAtkNode;  // offset: 0x28
    cHitNode* mpDfdNode;  // offset: 0x30
    cHitGeom* mpAtkGeom;  // offset: 0x38
    cHitGeom* mpDfdGeom;  // offset: 0x40
    uDDOModel* mpAtkModel;  // offset: 0x48
    uDDOModel* mpDfdModel;  // offset: 0x50
    static MyDTI DTI;
};
