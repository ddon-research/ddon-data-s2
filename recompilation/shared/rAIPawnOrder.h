#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cAIObject.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cAIPawnOrderParam;
class rAIPawnOrder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIPawnOrderParam : public cAIResource
{
public:
    enum
    {
        DATA_VERSION = 15,
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
    cAIPawnOrderParam();
    virtual ~cAIPawnOrderParam();
    bool isOrderFlag(u32 bit) const;
    bool isOrderActCancelFlag(u32 bit) const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mID;  // offset: 0x8
    u32 mOrderType;  // offset: 0xc
    u32 mOrderGroup;  // offset: 0x10
    u32 mOrderCategory;  // offset: 0x14
    f32 mEnableFrame;  // offset: 0x18
    u32 mOrderSpID;  // offset: 0x1c
    u32 mOrderAttrFlag;  // offset: 0x20
    u32 mOrderAttrActID;  // offset: 0x24
    cAIPawnActionGroupFlag mOrderAttrActGroup;  // offset: 0x28
    u32 mActionCancelFlag;  // offset: 0x38
    static MyDTI DTI;
};

class rAIPawnOrder : public rTbl2<cAIPawnOrderParam>
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
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    virtual bool loadData(MtDataReader& in, cAIPawnOrderParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
