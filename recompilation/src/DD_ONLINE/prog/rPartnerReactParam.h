#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cPartnerReactParam;
class rPartnerReactParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using size_t = _Sizet;
using u32 = unsigned int;

class cPartnerReactParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 4,
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
    cPartnerReactParam();
    virtual ~cPartnerReactParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isNmlAct();
    u32 getActNo();
    s16 getNpcMotNo();
    s16 getNpcMotNo2();
    s16 getNpcMotNo3();
    s16 getNpcMotNo4();
public:
    bool mIsNmlAct;  // offset: 0x8
    u32 mActNo;  // offset: 0xc
    s16 mNpcMotNo;  // offset: 0x10
    s16 mNpcMotNo2;  // offset: 0x12
    s16 mNpcMotNo3;  // offset: 0x14
    s16 mNpcMotNo4;  // offset: 0x16
    static MyDTI DTI;
};

class rPartnerReactParam : public rTbl2<cPartnerReactParam>
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
    virtual bool loadData(MtDataReader& in, cPartnerReactParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cPartnerReactParam::cPartnerReactParam() {
    this->mIsNmlAct = false;
    this->mActNo = 0;
    this->mNpcMotNo = -1;
    this->mNpcMotNo2 = -1;
    this->mNpcMotNo3 = -1;
    this->mNpcMotNo4 = -1;
}
