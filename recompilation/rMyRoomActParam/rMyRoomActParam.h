#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cMyRoomActParam;
class rMyRoomActParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cMyRoomActParam : public MtObject
{
public:
    enum
    {
        COND_NOTHING = 0,
        COND_NOT_FIRST = 1,
    };
    enum ResStatus
    {
        DATA_VERSION = 14,
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
    cMyRoomActParam();
    // Address: 0x01a9d5e0 - 0x01a9d5e1 (1 bytes)
    virtual ~cMyRoomActParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u16 getWaypoint();
    MtVector3 getPos();
    f32 getAngleY();
    u16 getNpcMotNo();
    u16 getStartIdx();
    u32 getNeedOM();
    u32 getNeedOM2();
    u32 getNeedOM3();
    u32 getNeedOM4();
    u32 getNeedOM5();
    s16 getMessage();
    u16 getCondition();
    s16 getLinkActNo();
    u16 getLinkActLv();
    s16 getChangeEquip();
    bool isGriffin();
    bool isNotAvoid();
    bool isSingle();
public:
    MtVector3 mPos;  // offset: 0x10
    f32 mAngleY;  // offset: 0x20
    u16 mWaypoint;  // offset: 0x24
    u16 mNpcMotNo;  // offset: 0x26
    u16 mStartIdx;  // offset: 0x28
    u32 mNeedOM;  // offset: 0x2c
    s16 mMessage;  // offset: 0x30
    u16 mCondition;  // offset: 0x32
    s16 mLinkActNo;  // offset: 0x34
    u16 mLinkActLv;  // offset: 0x36
    s16 mChangeEquip;  // offset: 0x38
    bool mIsGriffin;  // offset: 0x3a
    bool mIsNotAvoid;  // offset: 0x3b
    bool mIsSingle;  // offset: 0x3c
    u32 mNeedOM2;  // offset: 0x40
    u32 mNeedOM3;  // offset: 0x44
    u32 mNeedOM4;  // offset: 0x48
    u32 mNeedOM5;  // offset: 0x4c
    static MyDTI DTI;
};

class rMyRoomActParam : public rTbl2<cMyRoomActParam>
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
    virtual bool loadData(MtDataReader& in, cMyRoomActParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
