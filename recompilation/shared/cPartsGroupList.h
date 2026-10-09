#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "rLayout.h"
#include "rLayoutGroupParam.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cGroupParam;
class rLayoutGroupParamList;

// Declarations
class cPartsGroupList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPartsGroupList : public MtObject
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
    cPartsGroupList();
    virtual ~cPartsGroupList();
    u32 getPartsGroup() const;
    u32 getAreaNo() const;
    void setGroupTop(u32 group);
    u32 getGroupTop() const;
    void setOffset(MtVector3& ofs);
    MtVector3 getOffset() const;
    void init(u32 partsGroup, u32 layerNo, u32 areaNo, rLayout::TYPE lotType);
    u32 getGroupNum() const;
    MtTypedArray<cGroupParam>& getGroup();
    bool isEnable();
private:
    u32 mPartsGroup;  // offset: 0x8
    u32 mAreaNo;  // offset: 0xc
    rLayout::TYPE mLotType;  // offset: 0x10
    u32 mGroupTop;  // offset: 0x14
    MtVector3 mOffset;  // offset: 0x20
    rLayoutGroupParamList* mpGroupParamList;  // offset: 0x30
    MtTypedArray<cGroupParam> mGroupList;  // offset: 0x38
public:
    static MyDTI DTI;
};
