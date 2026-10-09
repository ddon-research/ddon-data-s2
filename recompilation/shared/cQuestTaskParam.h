#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtTime.h"
#include "nQuest.h"

// Forward declarations
class CDataLightQuestDetail;
class CDataQuestList;
class CDataQuestOrderConditionParam;
class CDataQuestOrderList;
class CDataRewardItem;
class CDataSetQuestDetail;
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtTime;
class MtUI;
class cContextInstHm;
namespace nQuest { class cFixRewardData; }
namespace nQuest { class cOrderCondition; }
namespace nQuest { class cRepeatBonus; }
namespace nQuest { class cRewardData; }

// Declarations
class cQuestTaskParam;

// Type aliases from DWARF
using CLightQuestDetail = CDataLightQuestDetail;
using CQuestList = CDataQuestList;
using CQuestOrderList = CDataQuestOrderList;
using CSetQuestDetail = CDataSetQuestDetail;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestOrderConditionParamVec = MtTypedArray<CDataQuestOrderConditionParam>;
using RewardItemVec = MtTypedArray<CDataRewardItem>;
using _Sizet = long unsigned int;
namespace nQuest { using OrderConditionArray = MtTypedArray<nQuest::cOrderCondition>; }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cQuestTaskParam : public MtObject
{
public:
    enum TASK_STATE
    {
        TASK_STATE_HELPER = 0,
        TASK_STATE_ERROR = 1,
        TASK_STATE_REQUEST_CANCEL = 2,
        TASK_STATE_ERASE = 3,
        TASK_STATE_FORCE_DELETE = 4,
        TASK_STATE_PRE_WAIT_DELIVER = 5,
        TASK_STATE_WAIT_DELIVER = 6,
        TASK_STATE_CHECK_TOUCH_NPC = 7,
        TASK_STATE_WAIT_ORDER = 8,
        TASK_STATE_MY_MAIN_QUEST = 9,
        TASK_STATE_LEADER_QUEST = 10,
        TASK_STATE_HELPER_OLD = 11,
        TASK_STATE_MAX_NUM = 32,
    };
    enum
    {
        FIX_RWD_NUM = 8,
        RND_RWD_TBL_NUM = 3,
        SLCT_RWD_NUM = 1,
    };
public:
    class MyDTI;
    class cQuestPoint;
public:
    using QuestPointArray = MtTypedArray<cQuestTaskParam::cQuestPoint>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuestPoint : public MtObject
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
        cQuestPoint();
        cQuestPoint(u32 idx, s32 value);
        virtual ~cQuestPoint();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mIdx;  // offset: 0x8
        s32 mValue;  // offset: 0xc
        static MyDTI DTI;
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
    nQuest::QUEST_TYPE getQuestType() const;
    cQuestTaskParam& setQuestType(nQuest::QUEST_TYPE questType);
    cQuestTaskParam& setDistributionParams(const CQuestList& param);
    cQuestTaskParam& setDistributionParams(const CQuestOrderList& param);
    cQuestTaskParam& setDistributionParams(u32 baseLevel, u32 itemRankAvg, u32 orderNpcId, u32 areaId, const MtTime& endDistributionData, const QuestOrderConditionParamVec& orderConditionList, u32 exp, u32 gold, u32 rim, const RewardItemVec& fixedRewardItemList, const RewardItemVec& selectRewardItemList);
    cQuestTaskParam& setSetQuestDetail(const CSetQuestDetail& detail);
    cQuestTaskParam& setLightQuestDetail(const CLightQuestDetail& detail);
    cQuestTaskParam& setQuestLogDetail(const u32& clearNum);
    bool hasHint() const;
    void buyHint();
    bool isEnableCancel() const;
    cQuestTaskParam& setEnableCancel(bool isEnableCancel);
    bool isTutorialGuide() const;
    cQuestTaskParam& setTutorialGuide(bool isTutorialGuide);
    cQuestTaskParam& setRandomRewardNum(u32 num);
    cQuestTaskParam& setChargeRewardNum(u32 num);
    cQuestTaskParam& setProgressBonusNum(u32 num);
    cQuestTaskParam& setAreaId(u32 areaId);
protected:
    cQuestTaskParam& setRepeatBonus(nQuest::REPEAT_BONUS_TYPE type, u32 param, u32 num);
    cQuestTaskParam& setSelectReward(const RewardItemVec& itemList);
    cQuestTaskParam& setFixReward(const RewardItemVec& itemList);
public:
    void resetParam();
    void setKeyItemPoint(u32 idx, u32 pt);
    u32 getKeyItemPoint(u32 idx) const;
    void setRandom(u32 idx, s32 value);
    bool hasRandom(u32 idx) const;
    s32 getRandom(u32 idx) const;
    void resetRandom(u32 idx);
    void setTimer(u32 idx, s32 sec);
    bool hasTimer(u32 idx) const;
    s32 getTimer(u32 idx) const;
    void endTimer(u32 idx);
    void resetTimer(u32 idx);
    u32 getOrderConditionNum() const;
    u32 getOrderConditionType(u32 Idx) const;
    MT_CTSTR getOrderConditionParamMessage(u32 idx, u32 paramIdx) const;
    u32 getOrderConditionParam(u32 idx, u32 paramIdx) const;
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderList() const;
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderList(const cContextInstHm* pCtxt) const;
    bool loadOrderConditionQuest();
    void resetOrderCondition();
    void addOrderCondition(u32 Type, s32 Param1, s32 Param2);
    void updateOrderConditionMsg();
    cQuestTaskParam& onTaskState(TASK_STATE taskState);
    cQuestTaskParam& offTaskState(TASK_STATE taskState);
    bool checkTaskState(u32 questState) const;
    bool isEndDistribution() const;
    cQuestTaskParam& setEndDistributionData(const MtTime& endDistributionData);
    const MtTime& getEndDistributionData();
    u32 getBaseLevel() const;
    bool isDiscovery() const;
    cQuestTaskParam& setDiscovery(bool isDiscovery);
    u32 getNpcId() const;
    cQuestTaskParam& setNpcId(u32 npcId);
    u32 getClearNum() const;
    cQuestTaskParam& setClearNum(u32 clearNum);
    nQuest::REPEAT_BONUS_TYPE getRepeatBonusType() const;
    u32 getRepeatBonusParam() const;
    u32 getNextRepeatBonusNum() const;
    u32 getAreaId() const;
    u32 getAreaPoint() const;
    u32 getExp() const;
    u32 getGold() const;
    u32 getRim() const;
    u32 getUndiscoverItemId() const;
    u32 getUndiscoverExp() const;
    u32 getUndiscoverGold() const;
    u32 getUndiscoverRim() const;
    u16 getOrderLimit() const;
    u32 getCP() const;
    u32 getBoardType() const;
    const nQuest::cFixRewardData* getSelectReward(u32 idx) const;
    const nQuest::cRewardData* getFixReward(u32 idx) const;
    const nQuest::cRewardData* getRandomReward(u32 idx) const;
    u32 getRandomRewardNum() const;
    u32 getChargeRewardNum() const;
    u32 getProgressBonusNum() const;
    cQuestTaskParam();
    virtual ~cQuestTaskParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
protected:
    nQuest::cFixRewardData mSelectReward[1];  // offset: 0x8
    nQuest::cRewardData mFixReward[8];  // offset: 0x60
    nQuest::cRewardData mRandomReward[3];  // offset: 0xe0
    nQuest::cRepeatBonus mRepeatBonus;  // offset: 0x110
    QuestPointArray mKeyItemPoint;  // offset: 0x128
    QuestPointArray mRandomValue;  // offset: 0x148
    QuestPointArray mTimer;  // offset: 0x168
    nQuest::OrderConditionArray mOrderConditions;  // offset: 0x188
    MtTime mEndDistributionData;  // offset: 0x1a8
    u32 mTaskStatus;  // offset: 0x1b0
    u32 mItemRankAvg;  // offset: 0x1b4
    u32 mAreaPoint;  // offset: 0x1b8
    u32 mExp;  // offset: 0x1bc
    u32 mGold;  // offset: 0x1c0
    u32 mRim;  // offset: 0x1c4
    u32 mUndiscoveryExp;  // offset: 0x1c8
    u32 mUndiscoveryGold;  // offset: 0x1cc
    u32 mUndiscoveryRim;  // offset: 0x1d0
    u32 mUndiscoveryItemId;  // offset: 0x1d4
    u16 mNpcId;  // offset: 0x1d8
    u16 mClearNum;  // offset: 0x1da
    u16 mOrderLimit;  // offset: 0x1dc
    u32 mGetCP;  // offset: 0x1e0
    u8 mBoardType;  // offset: 0x1e4
    u8 mQuestType;  // offset: 0x1e5
    u8 mBaseLevel;  // offset: 0x1e6
    u8 mAreaId;  // offset: 0x1e7
    u8 mRandomRewardNum;  // offset: 0x1e8
    u8 mChargeRewardNum;  // offset: 0x1e9
    u8 mProgressBonusNum;  // offset: 0x1ea
    bool mIsDiscovery;  // offset: 0x1eb
    bool mHasHint;  // offset: 0x1ec
    bool mEnableCancel;  // offset: 0x1ed
    bool mIsTutorialGuide;  // offset: 0x1ee
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cQuestTaskParam::cQuestPoint::cQuestPoint() {
    this->mIdx = static_cast<u32>(0);
    this->mValue = static_cast<s32>(0);
}
