#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCommonU32;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataAreaBonus;
class CDataAreaInfoList;
class CDataBorderRewardRecord;
class CDataContentsPlayEnd;
class CDataCycleContentsExtraReward;
class CDataCycleContentsNews;
class CDataCycleContentsNewsDetail;
class CDataCycleContentsNoticeData;
class CDataCycleContentsPlayEnd;
class CDataCycleContentsRank;
class CDataCycleContentsReward;
class CDataCycleContentsRewardRecord;
class CDataCycleContentsStateList;
class CDataDeliveredItem;
class CDataDeliveredItemRecord;
class CDataDeliveryItem;
class CDataEndContentsGroup;
class CDataExpiredQuestList;
class CDataFortDefenseNoticeData;
class CDataGetRewardBoxItem;
class CDataLightQuestDetail;
class CDataLightQuestList;
class CDataLightQuestOrderList;
class CDataLotQuestList;
class CDataLotQuestOrderList;
class CDataMainQuestList;
class CDataMainQuestOrderList;
class CDataOrderConditionInfo;
class CDataPartyQuestProgressInfo;
class CDataPriorityQuest;
class CDataPriorityQuestSetting;
class CDataQuestAnnounce;
class CDataQuestCommand;
class CDataQuestContents;
class CDataQuestContentsSituationInfo;
class CDataQuestContentsSituationInfoDetail;
class CDataQuestDefine;
class CDataQuestEnemyInfo;
class CDataQuestFlag;
class CDataQuestIdScheduleId;
class CDataQuestKeyItemPoint;
class CDataQuestKeyItemPointRecord;
class CDataQuestLayoutFlag;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestList;
class CDataQuestLog;
class CDataQuestOrderConditionParam;
class CDataQuestOrderList;
class CDataQuestPartyBonusInfo;
class CDataQuestPhaseEvent;
class CDataQuestPhaseEventParam;
class CDataQuestPointDetail;
class CDataQuestPointDetailRecord;
class CDataQuestProcessState;
class CDataQuestProgressWork;
class CDataQuestSetInfo;
class CDataQuestTalkInfo;
class CDataRaidBossNoticeData;
class CDataRankingRewardRecord;
class CDataRecommendedQuestInfoList;
class CDataRewardAbility;
class CDataRewardBoxItem;
class CDataRewardBoxRecord;
class CDataRewardItem;
class CDataRewardItemDetail;
class CDataRewardJobValue;
class CDataRewardWalletPoint;
class CDataSetQuestDetail;
class CDataSetQuestInfoList;
class CDataSetQuestList;
class CDataSetQuestOpenDate;
class CDataSetQuestOrderList;
class CDataTimeGainQuestList;
class CDataTimeLimitedQuestList;
class CDataTimeLimitedQuestOrderList;
class CDataTutorialQuestList;
class CDataTutorialQuestOrderList;
class CDataWorldManageQuestList;
class CDataWorldManageQuestOrderList;

// Type aliases from DWARF
using CCycleContentsNoticeData = CDataCycleContentsNoticeData;
using CLightQuestDetail = CDataLightQuestDetail;
using CQuestContents = CDataQuestContents;
using CQuestList = CDataQuestList;
using CQuestLog = CDataQuestLog;
using CQuestOrderList = CDataQuestOrderList;
using CQuestPointDetail = CDataQuestPointDetail;
using CSetQuestDetail = CDataSetQuestDetail;
using CSetQuestInfoList = CDataSetQuestInfoList;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using b8 = bool;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataAreaBonus : public CPacketDataBase
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
    explicit CDataAreaBonus();
    explicit CDataAreaBonus(u32, u16, u16, u16, u16);
public:
    u32 m_unAreaId;  // offset: 0x8
    u16 m_usGoldRatio;  // offset: 0xc
    u16 m_usExpRatio;  // offset: 0xe
    u16 m_usRimRatio;  // offset: 0x10
    u16 m_usAreaPointRatio;  // offset: 0x12
    static MyDTI DTI;
};

class CDataAreaInfoList : public CPacketDataBase
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
    explicit CDataAreaInfoList();
    explicit CDataAreaInfoList(u32, u8, u8, u8, b8);
public:
    u32 m_unAreaId;  // offset: 0x8
    u8 m_ucWeather;  // offset: 0xc
    u8 m_ucUndiscoveredQuestNum;  // offset: 0xd
    u8 m_ucHighDiffcultyQuestNum;  // offset: 0xe
    b8 m_bIsBonus;  // offset: 0xf
    static MyDTI DTI;
};

class CDataCycleContentsNewsDetail : public CPacketDataBase
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
    explicit CDataCycleContentsNewsDetail();
    explicit CDataCycleContentsNewsDetail(u32, u32, u16, u8);
public:
    u32 m_unQuestId;  // offset: 0x8
    u32 m_unBaseLevel;  // offset: 0xc
    u16 m_usContentJoinItemRank;  // offset: 0x10
    u8 m_ucSituationLevel;  // offset: 0x12
    static MyDTI DTI;
};

class CDataCycleContentsRank : public CPacketDataBase
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
    explicit CDataCycleContentsRank();
    explicit CDataCycleContentsRank(u8, u32, u32, u64);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unRank;  // offset: 0xc
    u32 m_unScore;  // offset: 0x10
    u64 m_ullUpdateDate;  // offset: 0x18
    static MyDTI DTI;
};

class CDataCycleContentsRewardRecord : public CPacketDataBase
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
    explicit CDataCycleContentsRewardRecord();
    explicit CDataCycleContentsRewardRecord(u64, b8);
public:
    u64 m_ullRecvMaxDate;  // offset: 0x8
    b8 m_bIsExistExtraReward;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCycleContentsStateList : public CPacketDataBase
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
    explicit CDataCycleContentsStateList();
    explicit CDataCycleContentsStateList(u32, u8, u32, u8);
public:
    u32 m_unCycleContentsScheduleId;  // offset: 0x8
    u8 m_ucCategory;  // offset: 0xc
    u32 m_unCategoryType;  // offset: 0x10
    u8 m_ucState;  // offset: 0x14
    static MyDTI DTI;
};

class CDataDeliveredItem : public CPacketDataBase
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
    explicit CDataDeliveredItem();
    explicit CDataDeliveredItem(u32, u16, u16);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usItemNum;  // offset: 0xc
    u16 m_usNeedNum;  // offset: 0xe
    static MyDTI DTI;
};

class CDataDeliveredItemRecord : public CPacketDataBase
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
    explicit CDataDeliveredItemRecord();
    explicit CDataDeliveredItemRecord(u32, u32, u16, const MtTypedArray<CDataDeliveredItem>&);
public:
    u32 m_unCharacterId;  // offset: 0x8
    u32 m_unQuestScheduleId;  // offset: 0xc
    u16 m_usProcessNo;  // offset: 0x10
    MtTypedArray<CDataDeliveredItem> m_DeliveredItemList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataDeliveryItem : public CPacketDataBase
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
    explicit CDataDeliveryItem();
    explicit CDataDeliveryItem(u32, u16);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataExpiredQuestList : public CPacketDataBase
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
    explicit CDataExpiredQuestList();
    explicit CDataExpiredQuestList(u32, u32);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataGetRewardBoxItem : public CPacketDataBase
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
    explicit CDataGetRewardBoxItem();
    explicit CDataGetRewardBoxItem(const char* in_strUID);
public:
    MtString m_wstrUID;  // offset: 0x8
    static MyDTI DTI;
};

class CDataLightQuestDetail : public CPacketDataBase
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
    explicit CDataLightQuestDetail();
    explicit CDataLightQuestDetail(u32, u32, u32, u32, u32, u32);
public:
    u32 m_unAreaId;  // offset: 0x8
    u32 m_unBaseAreaPoint;  // offset: 0xc
    u32 m_unGetCP;  // offset: 0x10
    u32 m_unOrderLimit;  // offset: 0x14
    u32 m_unClearNum;  // offset: 0x18
    u32 m_unBoardType;  // offset: 0x1c
    static MyDTI DTI;
};

class CDataOrderConditionInfo : public CPacketDataBase
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
    explicit CDataOrderConditionInfo();
    explicit CDataOrderConditionInfo(u32 in_QuestScheduleId, b8 in_CanProgress);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    b8 m_bCanProgress;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestAnnounce : public CPacketDataBase
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
    explicit CDataQuestAnnounce();
    explicit CDataQuestAnnounce(u32);
public:
    u32 m_unAnnounceNo;  // offset: 0x8
    static MyDTI DTI;
};

class CDataQuestCommand : public CPacketDataBase
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
    explicit CDataQuestCommand();
    explicit CDataQuestCommand(u16, s32, s32, s32, s32);
public:
    u16 m_usCommand;  // offset: 0x8
    s32 m_nParam01;  // offset: 0xc
    s32 m_nParam02;  // offset: 0x10
    s32 m_nParam03;  // offset: 0x14
    s32 m_nParam04;  // offset: 0x18
    static MyDTI DTI;
};

class CDataQuestContents : public CPacketDataBase
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
    explicit CDataQuestContents();
    explicit CDataQuestContents(u8, s32, s32, s32, s32);
public:
    u8 m_ucType;  // offset: 0x8
    s32 m_nParam01;  // offset: 0xc
    s32 m_nParam02;  // offset: 0x10
    s32 m_nParam03;  // offset: 0x14
    s32 m_nParam04;  // offset: 0x18
    static MyDTI DTI;
};

class CDataQuestContentsSituationInfo : public CPacketDataBase
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
    explicit CDataQuestContentsSituationInfo();
    explicit CDataQuestContentsSituationInfo(u32, u32);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestDefine : public CPacketDataBase
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
    explicit CDataQuestDefine();
    explicit CDataQuestDefine(u8, u8, u8, u16);
public:
    u8 m_ucOrderMaxNum;  // offset: 0x8
    u8 m_ucChargeAddOrderNum;  // offset: 0x9
    u8 m_ucRewardBoxMaxNum;  // offset: 0xa
    u16 m_usCycleContentsPlaydataRemainDay;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestEnemyInfo : public CPacketDataBase
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
    explicit CDataQuestEnemyInfo();
    explicit CDataQuestEnemyInfo(u32, u16, b8);
public:
    u32 m_unGroupId;  // offset: 0x8
    u16 m_usLv;  // offset: 0xc
    b8 m_bIsPartyRecommend;  // offset: 0xe
    static MyDTI DTI;
};

class CDataQuestFlag : public CPacketDataBase
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
    explicit CDataQuestFlag();
    explicit CDataQuestFlag(u32);
public:
    u32 m_unFlagId;  // offset: 0x8
    static MyDTI DTI;
};

class CDataQuestIdScheduleId : public CPacketDataBase
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
    explicit CDataQuestIdScheduleId();
    explicit CDataQuestIdScheduleId(u32, u32);
public:
    u32 m_unQuestId;  // offset: 0x8
    u32 m_unQuestScheduleId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestKeyItemPoint : public CPacketDataBase
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
    explicit CDataQuestKeyItemPoint();
    explicit CDataQuestKeyItemPoint(u8, u16);
public:
    u8 m_ucPointID;  // offset: 0x8
    u16 m_usPoint;  // offset: 0xa
    static MyDTI DTI;
};

class CDataQuestKeyItemPointRecord : public CPacketDataBase
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
    explicit CDataQuestKeyItemPointRecord();
    explicit CDataQuestKeyItemPointRecord(u32, u16, const MtTypedArray<CDataQuestKeyItemPoint>&);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u16 m_usProcessNo;  // offset: 0xc
    MtTypedArray<CDataQuestKeyItemPoint> m_QuestKeyItemPointList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestLayoutFlag : public CPacketDataBase
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
    explicit CDataQuestLayoutFlag();
    explicit CDataQuestLayoutFlag(u32);
public:
    u32 m_unFlagId;  // offset: 0x8
    static MyDTI DTI;
};

class CDataQuestOrderConditionParam : public CPacketDataBase
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
    explicit CDataQuestOrderConditionParam();
    explicit CDataQuestOrderConditionParam(u32, s32, s32);
public:
    u32 m_unType;  // offset: 0x8
    s32 m_nParam01;  // offset: 0xc
    s32 m_nParam02;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestPartyBonusInfo : public CPacketDataBase
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
    explicit CDataQuestPartyBonusInfo();
    explicit CDataQuestPartyBonusInfo(u32, u32, u16, u16, u16, u16, u32, b8);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    u16 m_usGoldRatio;  // offset: 0x10
    u16 m_usExpRatio;  // offset: 0x12
    u16 m_usRimRatio;  // offset: 0x14
    u16 m_usAreaPointRatio;  // offset: 0x16
    u32 m_unDorb;  // offset: 0x18
    b8 m_bIsReceived;  // offset: 0x1c
    static MyDTI DTI;
};

class CDataQuestPhaseEventParam : public CPacketDataBase
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
    explicit CDataQuestPhaseEventParam();
    explicit CDataQuestPhaseEventParam(u32, u32, u32);
public:
    u32 m_unType;  // offset: 0x8
    u32 m_unIndex;  // offset: 0xc
    u32 m_unValue;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestPointDetailRecord : public CPacketDataBase
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
    explicit CDataQuestPointDetailRecord();
    explicit CDataQuestPointDetailRecord(u32, u32);
public:
    u32 m_unQuestPointRecordId;  // offset: 0x8
    u32 m_unPoint;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestProgressWork : public CPacketDataBase
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
    explicit CDataQuestProgressWork();
    explicit CDataQuestProgressWork(u32, s32, s32, s32, s32);
public:
    u32 m_unCommandNo;  // offset: 0x8
    s32 m_nWork01;  // offset: 0xc
    s32 m_nWork02;  // offset: 0x10
    s32 m_nWork03;  // offset: 0x14
    s32 m_nWork04;  // offset: 0x18
    static MyDTI DTI;
};

class CDataQuestSetInfo : public CPacketDataBase
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
    explicit CDataQuestSetInfo();
    explicit CDataQuestSetInfo(u32, u32);
public:
    u32 m_unStageNo;  // offset: 0x8
    u32 m_unGroupId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataQuestTalkInfo : public CPacketDataBase
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
    explicit CDataQuestTalkInfo();
    explicit CDataQuestTalkInfo(u32, u16, b8);
public:
    u32 m_unTalkNo;  // offset: 0x8
    u16 m_usNpcId;  // offset: 0xc
    b8 m_bIsOneOnly;  // offset: 0xe
    static MyDTI DTI;
};

class CDataRewardAbility : public CPacketDataBase
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
    explicit CDataRewardAbility();
    explicit CDataRewardAbility(u32);
public:
    u32 m_unAbilityNo;  // offset: 0x8
    static MyDTI DTI;
};

class CDataRewardBoxItem : public CPacketDataBase
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
    explicit CDataRewardBoxItem();
    explicit CDataRewardBoxItem(u32 in_ItemId, u16 in_Num, const char* in_strUID, u8 in_Type, b8 in_IsCharge, b8 in_IsHelp);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    MtString m_wstrUID;  // offset: 0x10
    u8 m_ucType;  // offset: 0x18
    b8 m_bIsCharge;  // offset: 0x19
    b8 m_bIsHelp;  // offset: 0x1a
    static MyDTI DTI;
};

class CDataRewardBoxRecord : public CPacketDataBase
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
    explicit CDataRewardBoxRecord();
    explicit CDataRewardBoxRecord(u32, u32, const MtTypedArray<CDataRewardBoxItem>&);
public:
    u32 m_unListNo;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    MtTypedArray<CDataRewardBoxItem> m_RewardItemList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataRewardItem : public CPacketDataBase
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
    explicit CDataRewardItem();
    explicit CDataRewardItem(u32, u16);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataRewardItemDetail : public CPacketDataBase
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
    explicit CDataRewardItemDetail();
    explicit CDataRewardItemDetail(u32, u16, u8);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    u8 m_ucType;  // offset: 0xe
    static MyDTI DTI;
};

class CDataRewardJobValue : public CPacketDataBase
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
    explicit CDataRewardJobValue();
    explicit CDataRewardJobValue(u8, u32, u32);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unAddPoint;  // offset: 0xc
    u32 m_unExtraBonusPoint;  // offset: 0x10
    static MyDTI DTI;
};

class CDataRewardWalletPoint : public CPacketDataBase
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
    explicit CDataRewardWalletPoint();
    explicit CDataRewardWalletPoint(u8, u32, u32);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unAddPoint;  // offset: 0xc
    u32 m_unExtraBonusPoint;  // offset: 0x10
    static MyDTI DTI;
};

class CDataSetQuestDetail : public CPacketDataBase
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
    explicit CDataSetQuestDetail();
    explicit CDataSetQuestDetail(u32, u32, u32, u32, u16, u16, u16, u16, u16, u8, u8, u8, u8, u8, b8);
public:
    u32 m_unImageId;  // offset: 0x8
    u32 m_unClearCount;  // offset: 0xc
    u32 m_unClearCharacterNum;  // offset: 0x10
    u32 m_unBaseAreaPoint;  // offset: 0x14
    u16 m_usUndiscoveryGoldRatio;  // offset: 0x18
    u16 m_usUndiscoveryExpRatio;  // offset: 0x1a
    u16 m_usUndiscoveryRimRatio;  // offset: 0x1c
    u16 m_usLeaderCompleteNum;  // offset: 0x1e
    u16 m_usRepeatRewardType;  // offset: 0x20
    u8 m_ucRepeatRewardValue;  // offset: 0x22
    u8 m_ucRepeatRewardCompleteNum;  // offset: 0x23
    u8 m_ucRandomRewardNum;  // offset: 0x24
    u8 m_ucChargeRewardNum;  // offset: 0x25
    u8 m_ucProgressBonusNum;  // offset: 0x26
    b8 m_bIsDiscovery;  // offset: 0x27
    static MyDTI DTI;
};

class CDataBorderRewardRecord : public CPacketDataBase
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
    explicit CDataBorderRewardRecord();
    explicit CDataBorderRewardRecord(u32, u32, u32, u32, u32, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataRewardAbility>&);
public:
    u32 m_unScore;  // offset: 0x8
    u32 m_unGold;  // offset: 0xc
    u32 m_unExp;  // offset: 0x10
    u32 m_unRim;  // offset: 0x14
    u32 m_unBorb;  // offset: 0x18
    MtTypedArray<CDataRewardItem> m_RewardItemList;  // offset: 0x20
    MtTypedArray<CDataRewardAbility> m_RewardAbilityList;  // offset: 0x40
    static MyDTI DTI;
};

class CDataContentsPlayEnd : public CPacketDataBase
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
    explicit CDataContentsPlayEnd();
    explicit CDataContentsPlayEnd(u32, u32, u32, u32, const MtTypedArray<CDataRewardItemDetail>&);
public:
    u32 m_unGold;  // offset: 0x8
    u32 m_unExp;  // offset: 0xc
    u32 m_unRim;  // offset: 0x10
    u32 m_unPlayTimeMillSec;  // offset: 0x14
    MtTypedArray<CDataRewardItemDetail> m_RewardItemDetailList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataCycleContentsExtraReward : public CPacketDataBase
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
    explicit CDataCycleContentsExtraReward();
    explicit CDataCycleContentsExtraReward(u8, const MtTypedArray<CDataRewardAbility>&);
public:
    u8 m_ucType;  // offset: 0x8
    MtTypedArray<CDataRewardAbility> m_RewardAbilityList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCycleContentsNews : public CPacketDataBase
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
    explicit CDataCycleContentsNews();
    explicit CDataCycleContentsNews(u32, u64, u64, u8, u32, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataCycleContentsNewsDetail>&, const MtTypedArray<CDataCycleContentsRank>&, u32, u32, b8);
public:
    u32 m_unCycleContentsScheduleId;  // offset: 0x8
    u64 m_ullBegin;  // offset: 0x10
    u64 m_ullEnd;  // offset: 0x18
    u8 m_ucCategory;  // offset: 0x20
    u32 m_unCategoryType;  // offset: 0x24
    MtTypedArray<CDataRewardItem> m_RewardItemList;  // offset: 0x28
    MtTypedArray<CDataCycleContentsNewsDetail> m_DetailList;  // offset: 0x48
    MtTypedArray<CDataCycleContentsRank> m_CycleContentsRankList;  // offset: 0x68
    u32 m_unTotalPoint;  // offset: 0x88
    u32 m_unPlayNum;  // offset: 0x8c
    b8 m_bIsCreateRanking;  // offset: 0x90
    static MyDTI DTI;
};

class CDataCycleContentsReward : public CPacketDataBase
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
    explicit CDataCycleContentsReward();
    explicit CDataCycleContentsReward(u8, const MtTypedArray<CDataRewardWalletPoint>&, const MtTypedArray<CDataRewardJobValue>&, const MtTypedArray<CDataRewardAbility>&);
public:
    u8 m_ucType;  // offset: 0x8
    MtTypedArray<CDataRewardWalletPoint> m_RewardWalletPointList;  // offset: 0x10
    MtTypedArray<CDataRewardJobValue> m_RewardJobValueList;  // offset: 0x30
    MtTypedArray<CDataRewardAbility> m_RewardAbilityList;  // offset: 0x50
    static MyDTI DTI;
};

class CDataPriorityQuest : public CPacketDataBase
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
    explicit CDataPriorityQuest();
    explicit CDataPriorityQuest(u32, u32, const MtTypedArray<CDataQuestAnnounce>&, const MtTypedArray<CDataQuestProgressWork>&);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    MtTypedArray<CDataQuestAnnounce> m_QuestAnnounceList;  // offset: 0x10
    MtTypedArray<CDataQuestProgressWork> m_WorkList;  // offset: 0x30
    static MyDTI DTI;
};

class CDataPriorityQuestSetting : public CPacketDataBase
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
    explicit CDataPriorityQuestSetting();
    explicit CDataPriorityQuestSetting(u32, const MtTypedArray<CDataPriorityQuest>&);
public:
    u32 m_unCharacterId;  // offset: 0x8
    MtTypedArray<CDataPriorityQuest> m_PriorityQuestList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestContentsSituationInfoDetail : public CPacketDataBase
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
    explicit CDataQuestContentsSituationInfoDetail();
    explicit CDataQuestContentsSituationInfoDetail(u32, u32, u32, u16, u8, const MtTypedArray<CDataQuestOrderConditionParam>&, const MtTypedArray<CDataRewardItem>&, u32, b8);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    u32 m_unBaseLevel;  // offset: 0x10
    u16 m_usContentJoinItemRank;  // offset: 0x14
    u8 m_ucNoticeType;  // offset: 0x16
    MtTypedArray<CDataQuestOrderConditionParam> m_QuestOrderConditionParamList;  // offset: 0x18
    MtTypedArray<CDataRewardItem> m_RewardItemList;  // offset: 0x38
    u32 m_unClearTimePointBonus;  // offset: 0x58
    b8 m_bIsEnable;  // offset: 0x5c
    static MyDTI DTI;
};

class CDataQuestLayoutFlagSetInfo : public CPacketDataBase
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
    explicit CDataQuestLayoutFlagSetInfo();
    explicit CDataQuestLayoutFlagSetInfo(u32, const MtTypedArray<CDataQuestSetInfo>&);
public:
    u32 m_unLayoutFlagNo;  // offset: 0x8
    MtTypedArray<CDataQuestSetInfo> m_SetInfoList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestLog : public CPacketDataBase
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
    explicit CDataQuestLog();
    explicit CDataQuestLog(const MtTypedArray<CDataQuestAnnounce>&, const MtTypedArray<CDataQuestTalkInfo>&);
public:
    MtTypedArray<CDataQuestAnnounce> m_QuestAnnounceList;  // offset: 0x8
    MtTypedArray<CDataQuestTalkInfo> m_QuestTalkInfoList;  // offset: 0x28
    static MyDTI DTI;
};

class CDataQuestPhaseEvent : public CPacketDataBase
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
    explicit CDataQuestPhaseEvent();
    explicit CDataQuestPhaseEvent(u32, const MtTypedArray<CDataQuestPhaseEventParam>&);
public:
    u32 m_unEventId;  // offset: 0x8
    MtTypedArray<CDataQuestPhaseEventParam> m_Params;  // offset: 0x10
    static MyDTI DTI;
};

class CDataQuestPointDetail : public CPacketDataBase
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
    explicit CDataQuestPointDetail();
    explicit CDataQuestPointDetail(const MtTypedArray<CDataQuestPointDetailRecord>&, const MtTypedArray<CDataQuestPointDetailRecord>&, const MtTypedArray<CDataQuestPointDetailRecord>&, const MtTypedArray<CDataQuestPointDetailRecord>&);
public:
    MtTypedArray<CDataQuestPointDetailRecord> m_QuestPointList;  // offset: 0x8
    MtTypedArray<CDataQuestPointDetailRecord> m_QuestEnemyPointList;  // offset: 0x28
    MtTypedArray<CDataQuestPointDetailRecord> m_QuestRegionBreakPointList;  // offset: 0x48
    MtTypedArray<CDataQuestPointDetailRecord> m_QuestDeliveryPointList;  // offset: 0x68
    static MyDTI DTI;
};

class CDataQuestProcessState : public CPacketDataBase
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
    explicit CDataQuestProcessState();
    explicit CDataQuestProcessState(u16, u16, u16, const MtTypedArray<CDataQuestProgressWork>&, const MtTypedArray<MtTypedArray<CDataQuestCommand> >&, const MtTypedArray<CDataQuestCommand>&);
public:
    u16 m_usProcessNo;  // offset: 0x8
    u16 m_usSequenceNo;  // offset: 0xa
    u16 m_usBlockNo;  // offset: 0xc
    MtTypedArray<CDataQuestProgressWork> m_WorkList;  // offset: 0x10
    MtTypedArray<MtTypedArray<CDataQuestCommand> > m_CheckCommandList;  // offset: 0x30
    MtTypedArray<CDataQuestCommand> m_ResultCommandList;  // offset: 0x50
    static MyDTI DTI;
};

class CDataRankingRewardRecord : public CPacketDataBase
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
    explicit CDataRankingRewardRecord();
    explicit CDataRankingRewardRecord(u32, u32, u32, u32, u32, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataRewardAbility>&);
public:
    u32 m_unRank;  // offset: 0x8
    u32 m_unGold;  // offset: 0xc
    u32 m_unExp;  // offset: 0x10
    u32 m_unRim;  // offset: 0x14
    u32 m_unBorb;  // offset: 0x18
    MtTypedArray<CDataRewardItem> m_RewardItemList;  // offset: 0x20
    MtTypedArray<CDataRewardAbility> m_RewardAbilityList;  // offset: 0x40
    static MyDTI DTI;
};

class CDataSetQuestInfoList : public CPacketDataBase
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
    explicit CDataSetQuestInfoList();
    explicit CDataSetQuestInfoList(u32, u32, u64, u32, u32, u16, u32, u32, u32, u32, u32, const MtTypedArray<CDataCommonU32>&, u8, u8, u16, b8, const MtTypedArray<CDataQuestEnemyInfo>&, const MtTypedArray<CDataQuestLayoutFlagSetInfo>&, const MtTypedArray<CDataDeliveryItem>&);
public:
    u32 m_unQuestScheduleId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    u64 m_ullEndDistributionDate;  // offset: 0x10
    u32 m_unImageId;  // offset: 0x18
    u32 m_unBaseLevel;  // offset: 0x1c
    u16 m_usContentJoinItemRank;  // offset: 0x20
    u32 m_unDiscoverRewardItemId;  // offset: 0x24
    u32 m_unDiscoverRewardBonusGold;  // offset: 0x28
    u32 m_unDiscoverRewardBonusExp;  // offset: 0x2c
    u32 m_unDiscoverRewardBonusRim;  // offset: 0x30
    u32 m_unQuickPartyPopularity;  // offset: 0x34
    MtTypedArray<CDataCommonU32> m_SelectRewardItemIdList;  // offset: 0x38
    u8 m_ucRandomRewardNum;  // offset: 0x58
    u8 m_ucChargeRewardNum;  // offset: 0x59
    u16 m_usCompleteNum;  // offset: 0x5a
    b8 m_bIsDiscovery;  // offset: 0x5c
    MtTypedArray<CDataQuestEnemyInfo> m_QuestEnemyInfoList;  // offset: 0x60
    MtTypedArray<CDataQuestLayoutFlagSetInfo> m_QuestLayoutFlagSetInfoList;  // offset: 0x80
    MtTypedArray<CDataDeliveryItem> m_DeliveryItemList;  // offset: 0xa0
    static MyDTI DTI;
};

class CDataSetQuestOpenDate : public CPacketDataBase
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
    explicit CDataSetQuestOpenDate();
    explicit CDataSetQuestOpenDate(u64, u32, const CSetQuestInfoList&);
public:
    u64 m_ullOpenDate;  // offset: 0x8
    u32 m_unAreaId;  // offset: 0x10
    CSetQuestInfoList m_SetQuestInfo;  // offset: 0x18
    static MyDTI DTI;
};

class CDataCycleContentsNoticeData : public CPacketDataBase
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
    explicit CDataCycleContentsNoticeData();
    explicit CDataCycleContentsNoticeData(u32, u32, u32, u32, u64, u8, u8, u8, b8, b8, const MtTypedArray<CDataQuestProcessState>&);
public:
    u32 m_unCycleContentsScheduleId;  // offset: 0x8
    u32 m_unQuestScheduleId;  // offset: 0xc
    u32 m_unQuestId;  // offset: 0x10
    u32 m_unCategoryType;  // offset: 0x14
    u64 m_ullEnd;  // offset: 0x18
    u8 m_ucNoticeType;  // offset: 0x20
    u8 m_ucIsSystemNotice;  // offset: 0x21
    u8 m_ucPartyMemberNum;  // offset: 0x22
    b8 m_bIsPlay;  // offset: 0x23
    b8 m_bIsGetReward;  // offset: 0x24
    MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x28
    static MyDTI DTI;
};

class CDataCycleContentsPlayEnd : public CPacketDataBase
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
    explicit CDataCycleContentsPlayEnd();
    explicit CDataCycleContentsPlayEnd(u32, u32, u32, u32, u32, u32, u32, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataRewardItem>&, const CQuestPointDetail&, u32, u32, u32, u16, u16, u16, u8, u32, u32, u32, b8, b8, b8);
public:
    u32 m_unGold;  // offset: 0x8
    u32 m_unExp;  // offset: 0xc
    u32 m_unRim;  // offset: 0x10
    u32 m_unDorb;  // offset: 0x14
    u32 m_unJobPoint;  // offset: 0x18
    u32 m_unExtraExp;  // offset: 0x1c
    u32 m_unExtraJobPoint;  // offset: 0x20
    MtTypedArray<CDataRewardItem> m_RewardItemList;  // offset: 0x28
    MtTypedArray<CDataRewardItem> m_RegionBreakRewardItemList;  // offset: 0x48
    CQuestPointDetail m_QuestPointDetail;  // offset: 0x68
    u32 m_unQuestPointGrandTotal;  // offset: 0xf0
    u32 m_unQuestPointTotal;  // offset: 0xf4
    u32 m_unExtraQuestPointTotal;  // offset: 0xf8
    u16 m_usQuestPointChargeBonusRatio;  // offset: 0xfc
    u16 m_usClearTimeBonusRatio;  // offset: 0xfe
    u16 m_usPenaltyNum;  // offset: 0x100
    u8 m_ucPenaltyRatio;  // offset: 0x102
    u32 m_unQuestPointTechnical;  // offset: 0x104
    u32 m_unMaxQuestPointTechnical;  // offset: 0x108
    u32 m_unTimePoint;  // offset: 0x10c
    b8 m_bHasRegionBreakReward;  // offset: 0x110
    b8 m_bIsUpdateTechnicalScore;  // offset: 0x111
    b8 m_bIsCreateRanking;  // offset: 0x112
    static MyDTI DTI;
};

class CDataFortDefenseNoticeData : public CPacketDataBase
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
    explicit CDataFortDefenseNoticeData();
    explicit CDataFortDefenseNoticeData(const CCycleContentsNoticeData&);
public:
    CCycleContentsNoticeData m_Common;  // offset: 0x8
    static MyDTI DTI;
};

class CDataQuestList : public CPacketDataBase
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
    explicit CDataQuestList();
    explicit CDataQuestList(u32, u32, u32, u32, u16, u32, u32, u32, u32, u32, u32, u64, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataQuestOrderConditionParam>&, const CQuestLog&, const MtTypedArray<CDataQuestFlag>&, const MtTypedArray<CDataQuestLayoutFlag>&, const MtTypedArray<CDataQuestProcessState>&, const MtTypedArray<CDataQuestEnemyInfo>&, const MtTypedArray<CDataQuestLayoutFlagSetInfo>&, const MtTypedArray<CDataDeliveryItem>&, b8);
public:
    u32 m_unKeyId;  // offset: 0x8
    u32 m_unQuestScheduleId;  // offset: 0xc
    u32 m_unQuestId;  // offset: 0x10
    u32 m_unBaseLevel;  // offset: 0x14
    u16 m_usContentJoinItemRank;  // offset: 0x18
    u32 m_unBaseGold;  // offset: 0x1c
    u32 m_unBaseExp;  // offset: 0x20
    u32 m_unBaseRim;  // offset: 0x24
    u32 m_unOrderNpcId;  // offset: 0x28
    u32 m_unNameMsgId;  // offset: 0x2c
    u32 m_unDetailMsgId;  // offset: 0x30
    u64 m_ullEndDistributionDate;  // offset: 0x38
    MtTypedArray<CDataRewardItem> m_FixedRewardItemList;  // offset: 0x40
    MtTypedArray<CDataRewardItem> m_FixedRewardSelectItemList;  // offset: 0x60
    MtTypedArray<CDataQuestOrderConditionParam> m_QuestOrderConditionParamList;  // offset: 0x80
    CQuestLog m_QuestLog;  // offset: 0xa0
    MtTypedArray<CDataQuestFlag> m_QuestFlagList;  // offset: 0xe8
    MtTypedArray<CDataQuestLayoutFlag> m_QuestLayoutFlagList;  // offset: 0x108
    MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x128
    MtTypedArray<CDataQuestEnemyInfo> m_QuestEnemyInfoList;  // offset: 0x148
    MtTypedArray<CDataQuestLayoutFlagSetInfo> m_QuestLayoutFlagSetInfoList;  // offset: 0x168
    MtTypedArray<CDataDeliveryItem> m_DeliveryItemList;  // offset: 0x188
    b8 m_bIsClientOrder;  // offset: 0x1a8
    static MyDTI DTI;
};

class CDataQuestOrderList : public CPacketDataBase
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
    explicit CDataQuestOrderList();
    explicit CDataQuestOrderList(u32, u32, u32, u32, u32, u16, u32, u32, u32, u32, u32, u32, u64, u64, const MtTypedArray<CDataRewardItem>&, const MtTypedArray<CDataRewardItem>&, const CQuestLog&, const MtTypedArray<CDataQuestFlag>&, const MtTypedArray<CDataQuestLayoutFlag>&, const MtTypedArray<CDataQuestProcessState>&, const MtTypedArray<CDataQuestOrderConditionParam>&, const MtTypedArray<CDataQuestEnemyInfo>&, const MtTypedArray<CDataQuestLayoutFlagSetInfo>&, b8, b8, b8);
public:
    u32 m_unKeyId;  // offset: 0x8
    u32 m_unQuestScheduleId;  // offset: 0xc
    u32 m_unQuestId;  // offset: 0x10
    u32 m_unAreaId;  // offset: 0x14
    u32 m_unBaseLevel;  // offset: 0x18
    u16 m_usContentJoinItemRank;  // offset: 0x1c
    u32 m_unBaseGold;  // offset: 0x20
    u32 m_unBaseExp;  // offset: 0x24
    u32 m_unBaseRim;  // offset: 0x28
    u32 m_unOrderNpcId;  // offset: 0x2c
    u32 m_unNameMsgId;  // offset: 0x30
    u32 m_unDetailMsgId;  // offset: 0x34
    u64 m_ullOrderDate;  // offset: 0x38
    u64 m_ullEndDistributionDate;  // offset: 0x40
    MtTypedArray<CDataRewardItem> m_FixedRewardItemList;  // offset: 0x48
    MtTypedArray<CDataRewardItem> m_FixedRewardSelectItemList;  // offset: 0x68
    CQuestLog m_QuestLog;  // offset: 0x88
    MtTypedArray<CDataQuestFlag> m_QuestFlagList;  // offset: 0xd0
    MtTypedArray<CDataQuestLayoutFlag> m_QuestLayoutFlagList;  // offset: 0xf0
    MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x110
    MtTypedArray<CDataQuestOrderConditionParam> m_QuestOrderConditionParamList;  // offset: 0x130
    MtTypedArray<CDataQuestEnemyInfo> m_QuestEnemyInfoList;  // offset: 0x150
    MtTypedArray<CDataQuestLayoutFlagSetInfo> m_QuestLayoutFlagSetInfoList;  // offset: 0x170
    b8 m_bIsClientOrder;  // offset: 0x190
    b8 m_bIsEnable;  // offset: 0x191
    b8 m_bCanProgress;  // offset: 0x192
    static MyDTI DTI;
};

class CDataRaidBossNoticeData : public CPacketDataBase
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
    explicit CDataRaidBossNoticeData();
    explicit CDataRaidBossNoticeData(const CCycleContentsNoticeData&, u32, u32);
public:
    CCycleContentsNoticeData m_Common;  // offset: 0x8
    u32 m_unRaidBossType;  // offset: 0x50
    u32 m_unPlayTimeSec;  // offset: 0x54
    static MyDTI DTI;
};

class CDataRecommendedQuestInfoList : public CPacketDataBase
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
    explicit CDataRecommendedQuestInfoList();
    explicit CDataRecommendedQuestInfoList(u32, const CSetQuestInfoList&);
public:
    u32 m_unAreaId;  // offset: 0x8
    CSetQuestInfoList m_SetQuestInfo;  // offset: 0x10
    static MyDTI DTI;
};

class CDataSetQuestList : public CPacketDataBase
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
    explicit CDataSetQuestList();
    explicit CDataSetQuestList(const CQuestList&, const CSetQuestDetail&);
public:
    CQuestList m_Param;  // offset: 0x8
    CSetQuestDetail m_Detail;  // offset: 0x1b8
    static MyDTI DTI;
};

class CDataSetQuestOrderList : public CPacketDataBase
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
    explicit CDataSetQuestOrderList();
    explicit CDataSetQuestOrderList(u32, const CQuestOrderList&, const CSetQuestDetail&);
public:
    u32 m_unDistributeId;  // offset: 0x8
    CQuestOrderList m_Param;  // offset: 0x10
    CSetQuestDetail m_Detail;  // offset: 0x1a8
    static MyDTI DTI;
};

class CDataTimeGainQuestList : public CPacketDataBase
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
    explicit CDataTimeGainQuestList();
    explicit CDataTimeGainQuestList(const CQuestList&, u32, b8, b8, b8, b8, u8, const MtTypedArray<CDataRewardItemDetail>&);
public:
    CQuestList m_Param;  // offset: 0x8
    u32 m_unPlayTimeSec;  // offset: 0x1b8
    b8 m_bIsNoTimeup;  // offset: 0x1bc
    b8 m_bIsJoinCharacter;  // offset: 0x1bd
    b8 m_bIsJoinPawn;  // offset: 0x1be
    b8 m_bIsJoinSupportPawn;  // offset: 0x1bf
    u8 m_ucJoinPawnNum;  // offset: 0x1c0
    MtTypedArray<CDataRewardItemDetail> m_RewardItemDetailList;  // offset: 0x1c8
    static MyDTI DTI;
};

class CDataTimeLimitedQuestList : public CPacketDataBase
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
    explicit CDataTimeLimitedQuestList();
    explicit CDataTimeLimitedQuestList(const CQuestList&, u32, u32);
public:
    CQuestList m_Param;  // offset: 0x8
    u32 m_unBannerId;  // offset: 0x1b8
    u32 m_unTextId;  // offset: 0x1bc
    static MyDTI DTI;
};

class CDataTimeLimitedQuestOrderList : public CPacketDataBase
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
    explicit CDataTimeLimitedQuestOrderList();
    explicit CDataTimeLimitedQuestOrderList(const CQuestOrderList&);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    static MyDTI DTI;
};

class CDataTutorialQuestList : public CPacketDataBase
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
    explicit CDataTutorialQuestList();
    explicit CDataTutorialQuestList(const CQuestList&, u8);
public:
    CQuestList m_Param;  // offset: 0x8
    u8 m_ucEnableCancel;  // offset: 0x1b8
    static MyDTI DTI;
};

class CDataTutorialQuestOrderList : public CPacketDataBase
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
    explicit CDataTutorialQuestOrderList();
    explicit CDataTutorialQuestOrderList(const CQuestOrderList&, u8);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    u8 m_ucEnableCancel;  // offset: 0x1a0
    static MyDTI DTI;
};

class CDataWorldManageQuestList : public CPacketDataBase
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
    explicit CDataWorldManageQuestList();
    explicit CDataWorldManageQuestList(const CQuestList&, u8);
public:
    CQuestList m_Param;  // offset: 0x8
    u8 m_ucIsTutorialGuide;  // offset: 0x1b8
    static MyDTI DTI;
};

class CDataWorldManageQuestOrderList : public CPacketDataBase
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
    explicit CDataWorldManageQuestOrderList();
    explicit CDataWorldManageQuestOrderList(const CQuestOrderList&, u8);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    u8 m_ucIsTutorialGuide;  // offset: 0x1a0
    static MyDTI DTI;
};

class CDataEndContentsGroup : public CPacketDataBase
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
    explicit CDataEndContentsGroup();
    explicit CDataEndContentsGroup(const MtTypedArray<CDataTimeGainQuestList>&);
public:
    MtTypedArray<CDataTimeGainQuestList> m_TimeGainQuestList;  // offset: 0x8
    static MyDTI DTI;
};

class CDataLightQuestList : public CPacketDataBase
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
    explicit CDataLightQuestList();
    explicit CDataLightQuestList(const CQuestList&, const CLightQuestDetail&, const CQuestContents&);
public:
    CQuestList m_Param;  // offset: 0x8
    CLightQuestDetail m_Detail;  // offset: 0x1b8
    CQuestContents m_Contents;  // offset: 0x1d8
    static MyDTI DTI;
};

class CDataLightQuestOrderList : public CPacketDataBase
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
    explicit CDataLightQuestOrderList();
    explicit CDataLightQuestOrderList(const CQuestOrderList&, const CLightQuestDetail&);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    CLightQuestDetail m_Detail;  // offset: 0x1a0
    static MyDTI DTI;
};

class CDataLotQuestList : public CPacketDataBase
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
    explicit CDataLotQuestList();
    explicit CDataLotQuestList(const CQuestList&, const CQuestContents&);
public:
    CQuestList m_Param;  // offset: 0x8
    CQuestContents m_Contents;  // offset: 0x1b8
    static MyDTI DTI;
};

class CDataLotQuestOrderList : public CPacketDataBase
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
    explicit CDataLotQuestOrderList();
    explicit CDataLotQuestOrderList(const CQuestOrderList&, u8);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    u8 m_ucLotQuestType;  // offset: 0x1a0
    static MyDTI DTI;
};

class CDataMainQuestList : public CPacketDataBase
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
    explicit CDataMainQuestList();
    explicit CDataMainQuestList(const CQuestList&);
public:
    CQuestList m_Param;  // offset: 0x8
    static MyDTI DTI;
};

class CDataMainQuestOrderList : public CPacketDataBase
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
    explicit CDataMainQuestOrderList();
    explicit CDataMainQuestOrderList(const CQuestOrderList&);
public:
    CQuestOrderList m_Param;  // offset: 0x8
    static MyDTI DTI;
};

class CDataPartyQuestProgressInfo : public CPacketDataBase
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
    explicit CDataPartyQuestProgressInfo();
    explicit CDataPartyQuestProgressInfo(const MtTypedArray<CDataQuestOrderList>&, const MtTypedArray<CDataQuestIdScheduleId>&, const MtTypedArray<CDataDeliveredItemRecord>&, const MtTypedArray<CDataQuestKeyItemPointRecord>&);
public:
    MtTypedArray<CDataQuestOrderList> m_QuestOrderList;  // offset: 0x8
    MtTypedArray<CDataQuestIdScheduleId> m_SoloQuestOrderList;  // offset: 0x28
    MtTypedArray<CDataDeliveredItemRecord> m_DeliveredItemRecordList;  // offset: 0x48
    MtTypedArray<CDataQuestKeyItemPointRecord> m_QuestKeyItemPointRecordList;  // offset: 0x68
    static MyDTI DTI;
};
