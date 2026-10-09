#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

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

// Inline, no code of its own: checked where it is inlined.
inline cPartnerReactParam::cPartnerReactParam() {
    this->mIsNmlAct = false;
    this->mActNo = static_cast<u32>(0);
    this->mNpcMotNo = static_cast<s16>(-1);
    this->mNpcMotNo2 = static_cast<s16>(-1);
    this->mNpcMotNo3 = static_cast<s16>(-1);
    this->mNpcMotNo4 = static_cast<s16>(-1);
}
