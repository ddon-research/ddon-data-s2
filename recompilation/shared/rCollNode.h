#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class rCollGeom;

// Declarations
class cCollNode;
class rCollNode;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cCollNode : public MtObject
{
public:
    enum
    {
        INDEX_UID = 0,
    };
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
    cCollNode();
    virtual ~cCollNode();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isColNodeFlagAnd(u32) const;
    bool isColNodeFlagOr(u32) const;
    u32 getAttr() const;
public:
    rCollGeom* mpCollGeom;  // offset: 0x8
    u16 mNodeID;  // offset: 0x10
    u16 mIndex;  // offset: 0x12
    u32 mColNodeFlag;  // offset: 0x14
    u32 mHitCollisionFlag;  // offset: 0x18
protected:
    u32 mAttr;  // offset: 0x1c
public:
    static MyDTI DTI;
    static const u16 DATA_VERSION = 110;
};

class rCollNode : public rTbl2<cCollNode>
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
    rCollNode();
    virtual ~rCollNode();
    virtual bool loadData(MtDataReader& in, cCollNode* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    u32 mUParam32[4];  // offset: 0x7c
    u64 mUParam64[2];  // offset: 0x90
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCollNode::cCollNode() {
    this->mHitCollisionFlag = static_cast<u32>(0);
    this->mAttr = static_cast<u32>(0);
    this->mNodeID = static_cast<u16>(0);
    this->mIndex = static_cast<u16>(0);
    this->mColNodeFlag = static_cast<u32>(0);
    this->mpCollGeom = static_cast<rCollGeom*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32 cCollNode::getAttr() const {
    return this->mAttr;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rCollNode::rCollNode() {
    this->mUParam32[2] = static_cast<unsigned int>(0);
    this->mUParam32[3] = static_cast<unsigned int>(0);
    this->mUParam32[0] = static_cast<unsigned int>(0);
    this->mUParam32[1] = static_cast<unsigned int>(0);
    this->mUParam64[1] = static_cast<long unsigned int>(0);
    this->mUParam64[0] = static_cast<long unsigned int>(0);
}
