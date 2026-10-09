#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataCommonU32;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataAreaBaseInfo;
class CDataAreaQuestHint;
class CDataAreaRank;
class CDataAreaSpotSet;
class CDataReleaseAreaInfoSet;
class CDataRewardItemInfo;
class CDataSpotEnemyInfo;
class CDataSpotInfo;
class CDataSpotItemInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SpotEnemyInfoVec = MtTypedArray<CDataSpotEnemyInfo>;
using SpotItemInfoVec = MtTypedArray<CDataSpotItemInfo>;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataAreaBaseInfo : public CPacketDataBase
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
    explicit CDataAreaBaseInfo();
    explicit CDataAreaBaseInfo(u32 in_AreaID, u32 in_Rank, u32 in_CurrentPoint, u32 in_NextPoint, u32 in_WeekPoint, b8 in_CanRankUp, u32 in_ClanAreaPoint, u32 in_ClanAreaPointBorder, b8 in_CanReceiveSupply);
public:
    u32 m_unAreaID;  // offset: 0x8
    u32 m_unRank;  // offset: 0xc
    u32 m_unCurrentPoint;  // offset: 0x10
    u32 m_unNextPoint;  // offset: 0x14
    u32 m_unWeekPoint;  // offset: 0x18
    b8 m_bCanRankUp;  // offset: 0x1c
    u32 m_unClanAreaPoint;  // offset: 0x20
    u32 m_unClanAreaPointBorder;  // offset: 0x24
    b8 m_bCanReceiveSupply;  // offset: 0x28
    static MyDTI DTI;
};

class CDataAreaQuestHint : public CPacketDataBase
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
    explicit CDataAreaQuestHint();
    explicit CDataAreaQuestHint(u32, u32, b8);
public:
    u32 m_unScheduleID;  // offset: 0x8
    u32 m_unPrice;  // offset: 0xc
    b8 m_bIsSold;  // offset: 0x10
    static MyDTI DTI;
};

class CDataAreaRank : public CPacketDataBase
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
    explicit CDataAreaRank();
    explicit CDataAreaRank(u32, u32);
public:
    u32 m_unAreaID;  // offset: 0x8
    u32 m_unRank;  // offset: 0xc
    static MyDTI DTI;
};

class CDataAreaSpotSet : public CPacketDataBase
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
    explicit CDataAreaSpotSet();
    explicit CDataAreaSpotSet(u32, u32);
public:
    u32 m_unAreaId;  // offset: 0x8
    u32 m_unSpotId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataReleaseAreaInfoSet : public CPacketDataBase
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
    explicit CDataReleaseAreaInfoSet();
    explicit CDataReleaseAreaInfoSet(u32, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unAreaID;  // offset: 0x8
    MtTypedArray<CDataCommonU32> m_ReleaseList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataRewardItemInfo : public CPacketDataBase
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
    explicit CDataRewardItemInfo();
    explicit CDataRewardItemInfo(u32, u32, u8);
public:
    u32 m_unIndex;  // offset: 0x8
    u32 m_ulItemId;  // offset: 0xc
    u8 m_ucNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataSpotEnemyInfo : public CPacketDataBase
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
    explicit CDataSpotEnemyInfo();
    explicit CDataSpotEnemyInfo(u32, u8);
public:
    u32 m_unEnemyID;  // offset: 0x8
    u8 m_ucEnemyLv;  // offset: 0xc
    static MyDTI DTI;
};

class CDataSpotItemInfo : public CPacketDataBase
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
    explicit CDataSpotItemInfo();
    explicit CDataSpotItemInfo(u32, u8);
public:
    u32 m_unItemId;  // offset: 0x8
    u8 m_ucPawnTakeRate;  // offset: 0xc
    static MyDTI DTI;
};

class CDataSpotInfo : public CPacketDataBase
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
    explicit CDataSpotInfo();
    explicit CDataSpotInfo(u32, u32, u32, b8, b8, const SpotEnemyInfoVec&, const SpotItemInfoVec&, u32);
public:
    u32 m_unSpotID;  // offset: 0x8
    u32 m_unTextIndex;  // offset: 0xc
    u32 m_unStageID;  // offset: 0x10
    b8 m_bIsRelease;  // offset: 0x14
    b8 m_bIsNew;  // offset: 0x15
    SpotEnemyInfoVec m_SpotEnemyInfoList;  // offset: 0x18
    SpotItemInfoVec m_SpotItemInfoList;  // offset: 0x38
    u32 m_unQuickPartyPopularity;  // offset: 0x58
    static MyDTI DTI;
};
