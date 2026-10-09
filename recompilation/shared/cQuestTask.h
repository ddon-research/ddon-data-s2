#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cQuestTaskParam.h"
#include "nDDOUtility.h"
#include "nQuest.h"
#include "sQuestManagerExt.h"

// Forward declarations
class CDataLightQuestDetail;
class CDataQuestCommand;
class CDataQuestEnemyInfo;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestList;
class CDataQuestOrderList;
class CDataQuestProcessState;
class CDataQuestSetInfo;
class CDataSetQuestDetail;
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtTime;
class cQuestManagerBase;
class cQuestTaskParam;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class QuestCommandList; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class TargetEnemyInfoArray; }
namespace nQuest { class cDeliverTargetInfo; }
namespace nQuest { class cFixRewardData; }
namespace nQuest { class cQuestCommand; }
namespace nQuest { class cQuestDeliverRequestInfo; }
namespace nQuest { class cRewardData; }
namespace nQuest { class cTalkData; }
class uControl;

// Declarations
class cQuestPersonalData;
class cQuestTask;

// Type aliases from DWARF
using CLightQuestDetail = CDataLightQuestDetail;
using CQuestList = CDataQuestList;
using CQuestOrderList = CDataQuestOrderList;
using CQuestProcessState = CDataQuestProcessState;
using CSetQuestDetail = CDataSetQuestDetail;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestCommandVec = MtTypedArray<CDataQuestCommand>;
using QuestCommandVecVec = MtTypedArray<MtTypedArray<CDataQuestCommand> >;
using _Sizet = long unsigned int;
using f32 = float;
namespace nQuest { using QuestCommandGroupList = MtTypedArray<nQuest::QuestCommandList>; }
namespace nQuest { using TalkDataArray = MtTypedArray<nQuest::cTalkData>; }
namespace nQuest { using TargetEnemyInfoArrayArray = MtTypedArray<nQuest::TargetEnemyInfoArray>; }
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cQuestTask : public MtObject
{
public:
    enum PERSONAL_DATA_TYPE
    {
        PERSONAL_DATA_TYPE_MYSELF = 0,
        PERSONAL_DATA_TYPE_PARTY = 1,
        PERSONAL_DATA_TYPE_LEADER = 2,
    };
    enum BOOL_MEMBER
    {
        BOOL_IS_PROGRESS_WAIT_ORDER = 0,
        BOOL_IS_DECIDE_DELIVER_ITEM = 1,
        BOOL_IS_LOAD_RESOURCE = 2,
        BOOL_IS_LOGIN = 3,
        BOOL_IS_CALL_CLEAR_ANNOUNCE = 4,
        BOOL_PLAYS_EVENT = 5,
        BOOL_CAN_PROGRESS_OLD = 6,
        BOOL_IS_DIST_ENABLE = 7,
        BOOL_CAN_PROGRESS_LEADER = 8,
        BOOL_HAS_RECIEVED_CAN_PROGRESS_LEADER = 9,
        BOOL_IS_ENABLE_ORDER_OLD = 10,
        BOOL_IS_CYCLE_PHASE_QUEST = 11,
        BOOL_IS_VALID_OLD = 12,
        BOOL_IS_LOGIN_FIRST = 13,
        BOOL_IS_REQ_ORDER_WAIT_ORDER = 14,
        BOOL_IS_FINISHED_EVENT = 15,
        BOOL_IS_MATCH_SAY = 16,
        BOOL_MEMBER_NUM = 32,
    };
public:
    class MyDTI;
    class cQuestOmTargetData;
    class cLayoutFlagInfo;
    class cEnemyGroupInfo;
    class cLeaderQuestProgress;
    class cDeliveryItemInfo;
    class cQuestProcess;
public:
    using QuestLayoutFlagArray = MtTypedArray<cQuestTask::cLayoutFlagInfo>;
    using EnemyGroupIdArray = MtTypedArray<cQuestTask::cEnemyGroupInfo>;
    using LeaderQuestProgressArray = MtTypedArray<cQuestTask::cLeaderQuestProgress>;
    using DeliveryItemArray = MtTypedArray<cQuestTask::cDeliveryItemInfo>;
    using QuestNoticeInfo = nDDOUtility::cBitSet<64>;
    using QuestProcessArray = MtTypedArray<cQuestTask::cQuestProcess>;
    using TaskBoolMember = nDDOUtility::cBitSet<32>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuestOmTargetData : public MtObject
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
    public:
        s32 mStageNo;  // offset: 0x8
        s32 mGrpNo;  // offset: 0xc
        s32 mSetNo;  // offset: 0x10
        u32 mQuestId;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    class cLayoutFlagInfo : public MtObject
    {
    public:
        class MyDTI;
        class cSetInfo;
    public:
        using cSetInfoList = MtTypedArray<cQuestTask::cLayoutFlagInfo::cSetInfo>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cSetInfo : public MtObject
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
            cSetInfo();
            cSetInfo(u32 groupId, u32 stageNo);
            virtual ~cSetInfo();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        public:
            u32 mGroupId;  // offset: 0x8
            u32 mStageNo;  // offset: 0xc
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
        cLayoutFlagInfo();
        cLayoutFlagInfo(u32 flagNo, MtTypedArray<CDataQuestSetInfo>& setInfoList);
        virtual ~cLayoutFlagInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mFlagNo;  // offset: 0x8
        cSetInfoList mSetInfoList;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cEnemyGroupInfo : public MtObject
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
        u32 getEnemyGroupId() const;
        u32 getEnemyLevel() const;
        bool isPartyRecommanded() const;
        cEnemyGroupInfo();
        cEnemyGroupInfo(u32 enemyGroupId, u32 enemyLevel, bool isPartyRecommanded);
        virtual ~cEnemyGroupInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mEnemyGroupId;  // offset: 0x8
        u32 mEnemyLevel;  // offset: 0xc
        bool mIsPartyRecommanded;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cLeaderQuestProgress : public MtObject
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
        u32 getCharacterId() const;
        u32 getProcessNo() const;
        u32 getBlockNo() const;
        cLeaderQuestProgress();
        cLeaderQuestProgress(u32 characterId, u32 processNo, u32 blockNo);
        virtual ~cLeaderQuestProgress();
    protected:
        u32 mCharacterId;  // offset: 0x8
        u32 mProcessNo;  // offset: 0xc
        u32 mBlockNo;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cDeliveryItemInfo : public MtObject
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
        u32 getItemId() const;
        u32 getItemNum() const;
        cDeliveryItemInfo();
        cDeliveryItemInfo(u32 itemId, u32 itemNum);
        virtual ~cDeliveryItemInfo();
    protected:
        u32 mItemId;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cQuestProcess : public MtObject
    {
    public:
        enum
        {
            STATUS_EXECUTE_COMMAND = 0,
            STATUS_QUEST_PROGRESS = 1,
            STATUS_WAIT_PROGRESS = 2,
            STATUS_PROCESS_END = 3,
            STATUS_ERROR = 4,
        };
        enum
        {
            TARGET_ENEMY_MARKER_TYPE_DEFAULT = 0,
            TARGET_ENEMY_MARKER_TYPE_NONE = 1,
            TARGET_ENEMY_MARKER_TYPE_GM_MAIN = 2,
            TARGET_ENEMY_MARKER_TYPE_GM_SUB = 3,
            TARGET_ENEMY_MARKER_TYPE_NUM = 4,
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
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void operator delete(void* p_addr);
        static void usage();
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        const nQuest::cDeliverTargetInfo* getDeliverTargetInfo() const;
        u32 getDeliverNpcId() const;
        nQuest::cQuestDeliverRequestInfo* getDeliverRequestInfo() const;
        void setDieEmNum(u32 dieEmNum);
        u32 getDieEmNum();
        void notifyKilledTargetEnemySetGroup(u32 flagNo, u32 stageNo, u32 groupNo);
        u8 getStatus() const;
        void notifyFulfillDeliverItem(u32 npcId);
    protected:
        bool removeKilledTargetEnemy(u32 flagNo, u32 stageNo, u32 groupNo);
    public:
        void resetProgressParam();
        bool isEndProcess() const;
        bool isExecuteCommand() const;
        bool isWaitProgress() const;
        u16 getProcessNo() const;
        cQuestTask::cQuestProcess& setProcessNo(u16 processNo);
        s32 getCurrentBlockNo() const;
        void setCurrentBlockNo(u16);
        u32 getPrtUniqueId() const;
    protected:
        cQuestTask* getQuestTask() const;
        cQuestManagerBase* getQuestManager() const;
        bool isCheckLeaderOnly() const;
    public:
        virtual void move();  // vtable slot 6
        cQuestTask::cQuestProcess& updateProcessState(const CQuestProcessState* pProcess);
        cQuestTask::cQuestProcess& setupProcessState(const CQuestProcessState* pProcess);
        void leaderQuestProgress(u32 characterId);
        bool createTargetEnemyInfo();
    protected:
        void moveExecuteCommand();
        void moveQuestProgress();
        void moveWaitProgress();
        void moveProcessEnd();
        void moveError();
        void setupProcessStateBefore();
        void initCommand(const nQuest::cQuestCommand* pCommand);
        void finalCommand(const nQuest::cQuestCommand* pCommand);
        void copyResultCommandList(const QuestCommandVec& resultCommandList);
        void copyCheckCommandList(const QuestCommandVecVec& checkCommandList);
        bool executeProcess();
        void callbackProgress(u32 errorCode);
        void addMarkerAtTargetEnemyInfo(nQuest::TargetEnemyInfoArray& targetEnemeyInfoArray);
        bool checkTalkNpcCore(s32 StageNo, s32 NpcId);
        bool checkNewTalkNpcCore(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
    public:
        bool executeResultCommand(const nQuest::cQuestCommand* pCommand);
        void addMarker();
        void executeResultCommand();
    protected:
        bool executeCheckCommand(const nQuest::cQuestCommand* pCommand);
        bool executeCheckCommand();
        bool executeCommandListGroup(const nQuest::QuestCommandGroupList& cmdListGroup, bool(cQuestTask::cQuestProcess::*pExecuteFunc)(const nQuest::cQuestCommand*));
        bool executeCommandList(const nQuest::QuestCommandList& cmdList, bool(cQuestTask::cQuestProcess::*pExecuteFunc)(const nQuest::cQuestCommand*));
        void addMarker(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtLayoutNpc(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtQuestNpc(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtNpcUnit(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtEnemyEncountArea(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtEnemyEncountAreaGmMain(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtEnemyEncountAreaGmSub(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtScenario(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtQuestOm(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtLayoutOm(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtStage(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtPrt(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtWhiteDragon(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtQuestBoard(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtWarpPoint(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtArchibald(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtWarehouse(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtMyRoomRimStone(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtMyRoomPartner(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtClanQuestBoard(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtPhoto(const nQuest::cQuestCommand* pCommand) const;
        void addMarkerAtRenten(const nQuest::cQuestCommand* pCommand) const;
        void updateDeliverItemInfo(u32 itemId, u32 itemNum);
        void deleteCommandList(nQuest::QuestCommandList& commandList);
        void deleteCommandList(nQuest::QuestCommandGroupList& commandListVec);
    public:
        cQuestProcess(cQuestTask* pParent);
        cQuestProcess(const cQuestTask::cQuestProcess& obj);
        virtual ~cQuestProcess();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool checkTalkNpc(s32 stageNo, s32 npcId, s32 param03, s32 param04);
        bool checkDieEnemy(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkSceHitIn(s32 stageNo, s32 sceNo, s32 param03, s32 param04);
        bool checkHaveItem(s32 itemId, s32 itemNum, s32 param03, s32 param04);
        bool checkDeliverItem(s32 itemId, s32 itemNum, s32 npcId, s32 msgNo);
        bool checkEmDieLight(s32 enemyId, s32 enemyLv, s32 enemyNum, s32 param04);
        bool checkQstFlagOn(s32 questId, s32 flagNo, s32 param03, s32 param04);
        bool checkQstFlagOff(s32 questId, s32 flagNo, s32 param03, s32 param04);
        bool checkMyQstFlagOn(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkMyQstFlagOff(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkPadding00(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkPadding01(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkPadding02(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkStageNo(s32 stageNo, s32 param02, s32 param03, s32 param04);
        bool checkEventEnd(s32 stageNo, s32 eventNo, s32 param03, s32 param04);
        bool checkPrt(s32 stageNo, s32 x, s32 y, s32 z);
        bool checkClearcount(s32 minCount, s32 maxCount, s32 param03, s32 param04);
        bool checkSceFlagOn(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkSceFlagOff(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkTouchActToNpc(s32 stageNo, s32 npcId, s32 param03, s32 param04);
        bool checkOrderDecide(s32 npcId, s32 param02, s32 param03, s32 param04);
        bool checkIsEndCycle(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsInterruptCycle(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsFailedCycle(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsEndResult(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkNpcTalkAndOrderUi(s32 stageNo, s32 npcId, s32 noOrderGroupSerial, s32 param04);
        bool checkNpcTouchAndOrderUi(s32 stageNo, s32 npcId, s32 noOrderGroupSerial, s32 param04);
        bool checkStageNoNotEq(s32 stageNo, s32 param02, s32 param03, s32 param04);
        bool checkWarlevel(s32 warLevel, s32 param02, s32 param03, s32 param04);
        bool checkTalkNpcWithoutMarker(s32 stageNo, s32 npcId, s32 param03, s32 param04);
        bool checkHaveMoney(s32 gold, s32 type, s32 param03, s32 param04);
        bool checkSetQuestClearNum(s32 clearNum, s32 areaId, s32 param03, s32 param04);
        bool checkMakeCraft(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkPlayEmotion(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsEndTimer(s32 timerNo, s32 param02, s32 param03, s32 param04);
        bool checkIsEnemyFound(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkRandomEq(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkRandomNotEq(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkRandomLess(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkRandomNotGreater(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkRandomGreater(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkRandomNotLess(s32 randomNo, s32 value, s32 param03, s32 param04);
        bool checkClearcount02(s32 div, s32 value, s32 param03, s32 param04);
        bool checkIngameTimeRangeEq(s32 minTime, s32 maxTime, s32 param03, s32 param04);
        bool checkIngameTimeRangeNotEq(s32 minTime, s32 maxTime, s32 param03, s32 param04);
        bool checkPlHp(s32 hpRate, s32 type, s32 param03, s32 param04);
        bool checkEmHpNotLess(s32 stageNo, s32 groupNo, s32 setNo, s32 hpRate);
        bool checkEmHpLess(s32 stageNo, s32 groupNo, s32 setNo, s32 hpRate);
        bool checkWeatherEq(s32 weatherId, s32 param02, s32 param03, s32 param04);
        bool checkWeatherNotEq(s32 weatherId, s32 param02, s32 param03, s32 param04);
        bool checkPlJobEq(s32 jobId, s32 param02, s32 param03, s32 param04);
        bool checkPlJobNotEq(s32 jobId, s32 param02, s32 param03, s32 param04);
        bool checkPlSexEq(s32 sex, s32 param02, s32 param03, s32 param04);
        bool checkPlSexNotEq(s32 sex, s32 param02, s32 param03, s32 param04);
        bool checkSceHitOut(s32 stageNo, s32 sceNo, s32 param03, s32 param04);
        bool checkWaitOrder(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOmSetTouch(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkOmReleaseTouch(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkJobLevelNotLess(s32 checkType, s32 level, s32 param03, s32 param04);
        bool checkJobLevelLess(s32 checkType, s32 level, s32 param03, s32 param04);
        bool checkMyQstFlagOnFromFsm(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkSceHitInWithoutMarker(s32 stageNo, s32 sceNo, s32 param03, s32 param04);
        bool checkSceHitOutWithoutMarker(s32 stageNo, s32 sceNo, s32 param03, s32 param04);
        bool checkKeyItemPoint(s32 idx, s32 num, s32 param03, s32 param04);
        bool checkIsNotEndTimer(s32 timerNo, s32 param02, s32 param03, s32 param04);
        bool checkIsMainQuestClear(s32 questId, s32 param02, s32 param03, s32 param04);
        bool checkDogmaOrb(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsEnemyFoundForOrder(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsTutorialFlagOn(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkQuestOmSetTouch(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkQuestOmReleaseTouch(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkNewTalkNpc(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkNewTalkNpcWithoutMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsTutorialQuestClear(s32 questId, s32 param02, s32 param03, s32 param04);
        bool checkIsMainQuestOrder(s32 questId, s32 param02, s32 param03, s32 param04);
        bool checkIsTutorialQuestOrder(s32 questId, s32 param02, s32 param03, s32 param04);
        bool checkIsTouchPawnDungeonOm(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsOpenDoorOmQuestSet(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkEmDieForRandomDungeon(s32 stageNo, s32 enemyId, s32 enemyNum, s32 param04);
        bool checkNpcHpNotLess(s32 stageNo, s32 groupNo, s32 setNo, s32 hpRate);
        bool checkNpcHpLess(s32 stageNo, s32 groupNo, s32 setNo, s32 hpRate);
        bool checkIsEnemyFoundWithoutMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsEventBoardAccepted(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkWorldManageQuestFlagOn(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool checkWorldManageQuestFlagOff(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool checkTouchEventBoard(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenEntryRaidBoss(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOepnEntryFortDefense(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkDiePlayer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkPartyNumNotLessWtihoutPawn(s32 partyMemberNum, s32 param02, s32 param03, s32 param04);
        bool checkPartyNumNotLessWithPawn(s32 partyMemberNum, s32 param02, s32 param03, s32 param04);
        bool checkLostMainPawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkSpTalkNpc(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOepnJobMaster(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkTouchRimStone(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkGetAchievement(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkDummyNotProgress(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkDieRaidBoss(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkCycleTimerZero(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkCycleTimer(s32 timeSec, s32 param02, s32 param03, s32 param04);
        bool checkQuestNpcTalkAndOrderUi(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkQuestNpcTouchAndOrderUi(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsFoundRaidBoss(s32 stageNo, s32 groupNo, s32 setNo, s32 enemyId);
        bool checkQuestOmSetTouchWithoutMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkQuestOmReleaseTouchWithoutMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkTutorialTalkNpc(s32 stageNo, s32 npcId, s32 param03, s32 param04);
        bool checkIsLogin(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsPlayEndFirstSeasonEndCredit(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsKilledTargetEnemySetGroup(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkIsKilledTargetEmSetGrpNoMarker(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkIsLeftCycleTimer(s32 timeSec, s32 param02, s32 param03, s32 param04);
        bool checkOmEndText(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkQuestOmEndText(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkOpenAreaMaster(s32 areaId, s32 param02, s32 param03, s32 param04);
        bool checkHaveItemAllBag(s32 itemId, s32 itemNum, s32 param03, s32 param04);
        bool checkOpenNewspaper(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenQuestBoard(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkStageNoWithoutMarker(s32 stageNo, s32 param02, s32 param03, s32 param04);
        bool checkTalkQuestNpcUnitMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkTouchQuestNpcUnitMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsExistSecondPawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOrderJobTutorialQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOpenWarehouse(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsMyquestLayoutFlagOn(s32 FlagNo, s32 param02, s32 param03, s32 param04);
        bool checkIsMyquestLayoutFlagOff(s32 FlagNo, s32 param02, s32 param03, s32 param04);
        bool checkIsOpenWarehouseReward(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOrderLightQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOrderWorldQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsLostMainPawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsFullOrderQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsBadStatus(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkCheckAreaRank(s32 AreaId, s32 AreaRank, s32 param03, s32 param04);
        bool checkPadding133(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkEnablePartyWarp(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsHugeble(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsDownEnemy(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenAreaMasterSupplies(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenEntryBoard(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkNoticeInterruptContents(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenRetrySelect(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsPlWeakening(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkNoticePartyInvite(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsKilledAreaBoss(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsPartyReward(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsFullBag(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenCraftExam(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkLevelUpCraft(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsClearLightQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenJobMasterReward(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkTouchActQuestNpc(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsLeaderAndJoinPawn(s32 pawnNum, s32 param02, s32 param03, s32 param04);
        bool checkIsAcceptLightQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsReleaseWarpPoint(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsSetPlayerSkill(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOrderMyQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsNotOrderMyQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkHasMypawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsFavoriteWarpPoint(s32 warpPointId, s32 param02, s32 param03, s32 param04);
        bool checkCraft(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsKilledTargetEnemySetGroupGmMain(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkIsKilledTargetEnemySetGroupGmSub(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool checkHasUsedKey(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsCycleFlagOffPeriod(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsEnemyFoundGmMain(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsEnemyFoundGmSub(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsLoginBugFixedOnly(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsSearchClan(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOpenAreaListUi(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsReleaseWarpPointAnyone(s32 warpPointId, s32 param02, s32 param03, s32 param04);
        bool checkDevidePlayer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkNowPhase(s32 phaseId, s32 param02, s32 param03, s32 param04);
        bool checkIsReleasePortal(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsGetAppraiseItem(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsSetPartnerPawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsPresentPartnerPawn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsReleaseMyRoom(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsExistDividePlayer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkNotDividePlayer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsGatherPartyInStage(s32 stageNo, s32 param02, s32 param03, s32 param04);
        bool checkIsFinishedEnemyDivideAction(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOpenDoorOmQuestSetNoMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 questId);
        bool checkIsFinishedEventOrderNum(s32 stageNo, s32 eventNo, s32 param03, s32 param04);
        bool checkIsPresentPartnerPawnNoMarker(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOmBrokenLayout(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsOmBrokenQuest(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsHoldingPeriodCycleContents(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsNotHoldingPeriodCycleContents(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsResetInstanceArea(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkCheckMoonAge(s32 moonAgeStart, s32 moonAgeEnd, s32 param03, s32 param04);
        bool checkIsOrderPawnQuest(s32 orderGroupSerial, s32 noOrderGroupSerial, s32 param03, s32 param04);
        bool checkIsTakePictures(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsStageForMainQuest(s32 stageNo, s32 param02, s32 param03, s32 param04);
        bool checkIsReleasePawnExpedition(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkOpenPpMode(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkPpNotLess(s32 point, s32 param02, s32 param03, s32 param04);
        bool checkOpenPpShop(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkTouchClanBoard(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOneOffGather(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsOmBrokenLayoutNoMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkIsOmBrokenQuestNoMarker(s32 stageNo, s32 groupNo, s32 setNo, s32 param04);
        bool checkKeyItemPointEq(s32 idx, s32 num, s32 param03, s32 param04);
        bool checkIsEmotion(s32 actNo, s32 param02, s32 param03, s32 param04);
        bool checkIsEquipColor(s32 color, s32 param02, s32 param03, s32 param04);
        bool checkIsEquip(s32 itemId, s32 param02, s32 param03, s32 param04);
        bool checkIsTakePicturesNpc(s32 stageNo, s32 npcId01, s32 npcId02, s32 npcId03);
        bool checkSayMessage(s32 param01, s32 param02, s32 param03, s32 param04);
        bool checkIsTakePicturesWithoutPawn(s32 stageNo, s32 x, s32 y, s32 z);
        bool checkIsLinkageEnemyFlag(s32 stageNo, s32 groupNo, s32 setNo, s32 flagNo);
        bool checkIsLinkageEnemyFlagOff(s32 stageNo, s32 groupNo, s32 setNo, s32 flagNo);
        bool checkIsReleaseSecretRoom(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultLotOn(s32 stageNo, s32 lotNo, s32 param03, s32 param04);
        bool resultLotOff(s32 stageNo, s32 lotNo, s32 param03, s32 param04);
        bool resultHandItem(s32 itemId, s32 itemNum, s32 param03, s32 param04);
        bool resultSetAnnounce(s32 announceType, s32 param02, s32 param03, s32 param04);
        bool resultUpdateAnnounce(s32 type, s32 param02, s32 param03, s32 param04);
        bool resultChangeMessage(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultQstFlagOn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultMyQstFlagOn(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool resultGlobalFlagOn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultQstTalkChg(s32 npcId, s32 msgNo, s32 param03, s32 param04);
        bool resultQstTalkDel(s32 npcId, s32 param02, s32 param03, s32 param04);
        bool resultStageJump(s32 stageNo, s32 startPos, s32 param03, s32 param04);
        bool resultEventExec(s32 stageNo, s32 eventNo, s32 jumpStageNo, s32 jumpStartPosNo);
        bool resultCallMessage(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultPrt(s32 stageNo, s32 x, s32 y, s32 z);
        bool resultQstLayoutFlagOn(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool resultQstLayoutFlagOff(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool resultQstSceFlagOn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultQstDogmaOrb(s32 orbNum, s32 param02, s32 param03, s32 param04);
        bool resultGotoMainPwanEdit(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultAddFsmNpcList(s32 npcId, s32 param02, s32 param03, s32 param04);
        bool resultEndCycle(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultAddCycleTimer(s32 sec, s32 param02, s32 param03, s32 param04);
        bool resultAddMarkerAtItem(s32 stageNo, s32 x, s32 y, s32 z);
        bool resultAddMarkerAtDest(s32 stageNo, s32 x, s32 y, s32 z);
        bool resultAddResultPoint(s32 tableIndex, s32 param02, s32 param03, s32 param04);
        bool resultPushImteToPlBag(s32 itemId, s32 itemNum, s32 param03, s32 param04);
        bool resultStartTimer(s32 timerNo, s32 sec, s32 param03, s32 param04);
        bool resultSetRandom(s32 randomNo, s32 minValue, s32 maxValue, s32 resultValue);
        bool resultResetRandom(s32 randomNo, s32 param02, s32 param03, s32 param04);
        bool resultBgmRequest(s32 type, s32 bgmId, s32 param03, s32 param04);
        bool resultBgmStop(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultSetWaypoint(s32 npcId, s32 waypointNo0, s32 waypointNo1, s32 waypointNo2);
        bool resultForceTalkQuest(s32 npcId, s32 groupSerial, s32 param03, s32 param04);
        bool resultTutorialDialog(s32 guideNo, s32 param02, s32 param03, s32 param04);
        bool resultAddKeyItemPoint(s32 keyItemIdx, s32 pointNum, s32 param03, s32 param04);
        bool resultDontSaveProcess(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultInterruptCycleContents(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultQuestEvaluationPoint(s32 point, s32 param02, s32 param03, s32 param04);
        bool resultCheckOrderCondition(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultWorldManageLayoutFlagOn(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool resultWorldManageLayoutFlagOff(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool resultPlayEndingForFirstSeason(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultAddCyclePurpose(s32 announceNo, s32 type, s32 param03, s32 param04);
        bool resultRemoveCyclePurpose(s32 announceNo, s32 param02, s32 param03, s32 param04);
        bool resultUpdateAnnounceDirect(s32 announceNo, s32 type, s32 param03, s32 param04);
        bool resultSetCheckPoint(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultReturnCheckPoint(s32 processNo, s32 param02, s32 param03, s32 param04);
        bool resultCallGeneralAnnounce(s32 type, s32 msgNo, s32 param03, s32 param04);
        bool resultTutorialEnemyInvincibleOff(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultSetDiePlayerReturnPos(s32 stageNo, s32 startPos, s32 outSceNo, s32 param04);
        bool resultWorldManageQuestFlagOn(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool resultWorldManageQuestFlagOff(s32 flagNo, s32 questId, s32 param03, s32 param04);
        bool resultReturnCheckPointEx(s32 processNo, s32 param02, s32 param03, s32 param04);
        bool resultResetCheckPoint(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultResetDiePlayerReturnPos(s32 stageNo, s32 startPos, s32 param03, s32 param04);
        bool resultSetBarricade(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultResetBarricade(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultTutorialEnemyInvincibleOn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultResetTutorialFlag(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultStartContentsTimer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultMyQstFlagOff(s32 flagNo, s32 param02, s32 param03, s32 param04);
        bool resultPlayCameraEvent(s32 stageNo, s32 eventNo, s32 param03, s32 param04);
        bool resultEndEndQuest(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultReturnAnnounce(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultAddEndContentsPurpose(s32 announceNo, s32 type, s32 param03, s32 param04);
        bool resultRemoveEndContentsPurpose(s32 announceNo, s32 param02, s32 param03, s32 param04);
        bool resultStopCycleTimer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultRestartCycleTimer(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultAddAreaPoint(s32 AreaId, s32 AddPoint, s32 param03, s32 param04);
        bool resultLayoutFlagRandomOn(s32 FlanNo1, s32 FlanNo2, s32 FlanNo3, s32 ResultNo);
        bool resultSetDeliverInfo(s32 stageNo, s32 npcId, s32 groupSerial, s32 param04);
        bool resultSetDeliverInfoQuest(s32 stageNo, s32 groupNo, s32 setNo, s32 groupSerial);
        bool resultBgmRequestFix(s32 type, s32 bgmId, s32 param03, s32 param04);
        bool resultEventExecCont(s32 stageNo, s32 eventNo, s32 jumpStageNo, s32 jumpStartPosNo);
        bool resultPlPadOff(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultPlPadOn(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultEnableGetSetQuestList(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultStartMissionAnnounce(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultStageAnnounce(s32 type, s32 num, s32 param03, s32 param04);
        bool resultReleaseAnnounce(s32 id, s32 param02, s32 param03, s32 param04);
        bool resultButtonGuideFlagOn(s32 buttonGuideNo, s32 param02, s32 param03, s32 param04);
        bool resultButtonGuideFlagOff(s32 buttonGuideNo, s32 param02, s32 param03, s32 param04);
        bool resultAreaJumpFadeContinue(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultExeEventAfterStageJump(s32 stageNo, s32 eventNo, s32 startPos, s32 param04);
        bool resultExeEventAfterStageJumpContinue(s32 stageNo, s32 eventNo, s32 startPos, s32 param04);
        bool resultPlayMessage(s32 groupNo, s32 waitTime, s32 param03, s32 param04);
        bool resultStopMessage(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultDecideDivideArea(s32 stageNo, s32 startPosNo, s32 param03, s32 param04);
        bool resultShiftPhase(s32 phaseId, s32 param02, s32 param03, s32 param04);
        bool resultReleaseMyRoom(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultDivideSuccess(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultDivideFailed(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultSetProgressBonus(s32 rewardRank, s32 param02, s32 param03, s32 param04);
        bool resultRefreshOmKeyDisp(s32 param01, s32 param02, s32 param03, s32 param04);
        bool resultSwitchPawnQuestTalk(s32 type, s32 param02, s32 param03, s32 param04);
        bool resultLinkageEnemyFlagOn(s32 stageNo, s32 groupNo, s32 setNo, s32 flagId);
        bool resultLinkageEnemyFlagOff(s32 stageNo, s32 groupNo, s32 setNo, s32 flagId);
    protected:
        nQuest::TargetEnemyInfoArrayArray mTargetEnemyInfo;  // offset: 0x8
        nQuest::TargetEnemyInfoArrayArray mKilledTargetEnemyInfo;  // offset: 0x28
        nQuest::QuestCommandList mResultCommandList;  // offset: 0x48
        nQuest::QuestCommandGroupList mCheckCommandGourpList;  // offset: 0x70
        nQuest::cQuestDeliverRequestInfo* mpDeliverRequestInfo;  // offset: 0x90
        cQuestTask* mpParent;  // offset: 0x98
        nQuest::cDeliverTargetInfo* mpDeliverTargetInfo;  // offset: 0xa0
        u32 mPrtUniqueId;  // offset: 0xa8
        u32 mDieEmNum;  // offset: 0xac
        u32 mDeliverNpcId;  // offset: 0xb0
        s16 mCurrentBlockNo;  // offset: 0xb4
        u16 mProcessNo;  // offset: 0xb6
        u8 mStatus;  // offset: 0xb8
        u8 mTargetEnemyMarkerType;  // offset: 0xb9
        bool mIsFirst;  // offset: 0xba
        bool mNowSceHit;  // offset: 0xbb
        bool mIsReturnCheckPoint;  // offset: 0xbc
        bool mIsLeaderOnly;  // offset: 0xbd
    public:
        static MyDTI DTI;
        static const u32 LEADER_ONLY_COMMAND_CHECK_TABLE[];
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
    void setTaskParam(u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList);
    void setTaskParam(const CQuestList& param);
    void setTaskParam(const CQuestList& param, const MtTypedArray<CDataQuestProcessState>& processList);
    void setTaskParam(const CQuestOrderList& param);
    void setHasDiscovered(bool isDiscovery);
    void setTaskParamForParty(const CQuestOrderList& param);
    void setTaskParamForParty(const CQuestList& param, const MtTypedArray<CDataQuestProcessState>& processList);
    void setEnemyInfoParam(const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList);
    void setLayoutFlagSetInfoList(const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList);
    void setSetQuestDetail(const CSetQuestDetail& detail, u32 areaId);
    void setLightQuestDetail(const CLightQuestDetail& detail);
    void setQuestLogDetail(const u32& clearNum);
    u32 getClearNum() const;
    u32 getOrderNpcId() const;
    const MtTime& getEndDistributionData();
    u32 getOrderConditionNum() const;
    u32 getOrderConditionType(u32 Idx) const;
    MT_CTSTR getOrderConditionMessage(u32 idx) const;
    MT_CTSTR getOrderConditionParamMessage(u32 idx, u32 paramIdx) const;
    u32 getOrderConditionParam(u32 idx, u32 paramIdx) const;
    u32 getBaseLevel() const;
    bool isDiscovery() const;
    bool isEndDistribution() const;
    bool isEnableCancel() const;
    void setEnableCancel(bool isEnableCancel);
    bool isTutorialGuide() const;
    void setTutorialGuide(bool isTutorialGuide);
    nQuest::REPEAT_BONUS_TYPE getRepeatBonusType() const;
    u32 getRepeatBonusParam() const;
    u32 getNextRepeatBonusNum() const;
    u32 getAreaId() const;
    u32 getRewardAreaPoint() const;
    u32 getRewardExp() const;
    u32 getRewardGold() const;
    u32 getRewardRim() const;
    u32 getUndiscoverItemId() const;
    u32 getUndiscoverRewardExp() const;
    u32 getUndiscoverRewardGold() const;
    u32 getUndiscoverRewardRim() const;
    const nQuest::cFixRewardData* getSelectReward(u32 idx) const;
    const nQuest::cRewardData* getFixReward(u32 idx) const;
    const nQuest::cRewardData* getRandomReward(u32 idx) const;
    u32 getRandomRewardNum() const;
    u32 getChargeRewardNum() const;
    void setRandomRewardNum(u32 Num);
    void setChargeRewardNum(u32 Num);
    u32 getProgressBonusNum() const;
    void setProgressBonusNum(u32 Num);
    u16 getOrderLimit() const;
    u32 getCP() const;
    u32 getOriginalCP() const;
    bool isClanQuest() const;
    bool isClanClear();
    u32 getBoardType() const;
protected:
    cQuestTaskParam& getTaskParam();
public:
    nQuest::cTalkData* getTalkData(u32 npcId) const;
    void addTalkData(u32 npcId, u32 groupSerial);
    void removeTalkData(u32 npcId);
    void resetDispOrderUI();
    void setKeyItemPoint(u32 idx, u32 pt);
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderList() const;
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderListMySelf() const;
    bool loadOrderConditionQuest();
    void resetOrderCondition();
    void addOrderCondition(u32 type, u32 param1, u32 param2);
    void updateOrderConditionMsg();
    bool isOrder() const;
    bool isMyOrder() const;
    bool isWaitDeliver() const;
    bool isPreWaitDeliver() const;
    bool isDelete() const;
    void setErase(bool isErased);
    bool isClear() const;
    bool isClearMySelf() const;
    bool isCancelMySelf() const;
    bool isReqCancel() const;
    bool isError() const;
    bool isWaitOrder() const;
    bool isHelper() const;
    void setHelperCopyMyData(bool isHelp);
    void setHelper(bool isHelp);
    void setHelper(bool isHelp, bool isDeletePersonalData);
    void pushHelper();
    bool isHelperOld() const;
    u32 getLastErrorCode() const;
    bool mustCheckTouchNpc() const;
    void setLeaderQuest(bool isLeaderQuest);
    bool isLeaderQuest() const;
    bool isMyMainQuest() const;
    bool isValid() const;
    void setLeaderOrder(bool isOrder);
    void orderQuest();
    void forceDelete();
    void updateState();
    void updateState(bool isDeletePersonalData);
    void myMainQuest();
    cQuestManagerBase* getQuestManager() const;
    nQuest::QUEST_ID getQuestId() const;
    u32 getQuestIdU32() const;
    nQuest::SCHEDULE_ID getScheduleId() const;
    u32 getScheduleIdU32() const;
    nQuest::QUEST_TYPE getQuestType() const;
    void overwriteEnemyDieNumForLight(u32 emDieNum);
    u32 getEnemyDieNumForLight() const;
    bool isSoloQuest() const;
    bool isPartyQuest() const;
    void setCyclePhaseQuest(bool isCyclePhaseQuest);
    bool isProgressBonus() const;
    void addProcessState(const CQuestProcessState* pProcess);
    void addProcessState(const CQuestProcessState* pProcess, bool isOverWrite);
    void addProcessStateForParty(const CQuestProcessState* pProcess);
    u32 getBlockNo(u32 processNo) const;
    s32 getPurpose() const;
    s32 getPurpose(u32 idx) const;
    s32 getPurposeForParty() const;
    u32 getPurposeLogNum() const;
protected:
    void pushPurposeAuto(u32 purposeNo);
    void pushPurpose(u32 purposeNo);
    void pushPurposeForParty(u32 purposeNo);
    void popPurposeForParty();
    void resetPurposeForParty();
    void incrPurposeForParty();
public:
    nQuest::cQuestDeliverRequestInfo* getDeliverRequestInfo() const;
    nQuest::cQuestDeliverRequestInfo* getDeliverRequestInfoMySelf() const;
    bool isDeliverNpc(uControl* pCtrl) const;
    s32 getRequestDeliverProcessNo(uControl* pCtrl) const;
    s32 getLastDecideDeliverBlockNo() const;
    void setLastDecideDeliverBlockNo(s32 blockNo);
    s32 getCurrentDeliverBlockNo() const;
    void setCurrentDeliverBlockNo(s32 blockNo);
    u32 getDeliveryItemInfoNum() const;
    u32 getDeliveryItemId(u32 idx) const;
    u32 getDeliveryItemNum(u32 idx) const;
    bool isDecideDeliverItem() const;
    void notifyDecideDeliverItem(u32 npcId);
    void notifyFulfillDeliverItem(u32 npcId);
    void notifyQuestTimer(u32 timerNo);
    bool isProgressWaitOrder() const;
    u32 getWaitOrderProcessNo() const;
    void orderWaitOrder();
    void offProgressWaitOrder();
    bool isFinishedOrderWaitOrder() const;
    void callbackStartWaitOrder(u32 processNo);
    void callbackEndWaitOrder();
    void onWaitOrder();
    void offWaitOrder();
    bool isFlag(u32 flagNo) const;
    bool isMyFlag(u32 flagNo) const;
    bool isFlagFsm(u32 flagNo) const;
    bool isLayoutFlag(u32 flagNo) const;
    void onFlag(u32 flagNo);
    void onFlagFsm(u32 flagNo);
    void onLayoutFlag(u32 flagNo);
    void onMyFlag(u32 flagNo);
    void onMyFlagFsm(u32 flagNo);
    void onMyLayoutFlag(u32 flagNo);
    void offFlag(u32 flagNo);
    void offFlagFsm(u32 flagNo);
    void offLayoutFlag(u32 flagNo);
    void offMyFlag(u32 flagNo);
    void offMyFlagFsm(u32 flagNo);
    void offMyLayoutFlag(u32 flagNo);
    u32 getFlagNum() const;
    u32 getLayoutFlagNum() const;
    u32 getFlagNo(u32 idx) const;
    u32 getLayoutFlagNo(u32 idx) const;
    void deleteMyFlags();
    void deleteFlagFsm();
    void move();
protected:
    void moveProcessBefore();
    void moveProcess();
    void moveProcessAfter();
public:
    bool canProgress() const;
    bool hasHint() const;
    void buyHint();
    bool playsEvent() const;
    void setPlaysEvent(bool plays);
    u32 getPrtUniqueId() const;
    void setIsDistEnable(bool isEnable);
    bool createTargetEnemyInfo();
    bool progresses() const;
    bool canProgressLeader() const;
    void setCanProgressLeader(bool canProgress);
    void resetCanProgressLeader();
    bool isCallClearAnnounce() const;
    u32 getKeyId() const;
protected:
    bool canMove() const;
    cQuestPersonalData* getPersonalData(PERSONAL_DATA_TYPE personalData);
    cQuestPersonalData* getPersonalData(PERSONAL_DATA_TYPE personalData) const;
public:
    void requestCancel();
    void resetQuestCancelParam();
    void callbackOrder();
    void callbackClear();
    void callbackCancel(u32 errorCode);
    void callbackLeaderCancel();
    void loadResource();
    void resetLoginInfo();
    bool isLogin() const;
    void notifyKilledTargetEnemySetGroup(u32 processNo, u32 flagNo, u32 stageNo, u32 groupNo);
    void leaderQuestProgress(u16 processNo, u16 blockNo, u32 characterId);
    void onCallClearAnnounce();
    void matchSayMessage();
    void addOmTargetData(s32 stageNo, s32 groupNo, s32 setNo, u32 questId);
    void eraseOmTargetData(s32 stageNo, s32 groupNo, s32 setNo, u32 questId);
    bool isTargetOm(s32 stageNo, s32 groupNo, s32 setNo) const;
    bool isTargetOm(s32 stageNo, s32 groupNo, s32 setNo, u32 questSeq) const;
    void notifyNoticeInfo(nDDOUtility::cBitSet<64> noticeInfo, sQuestManagerExt::cTouchOmInfo* touchOmInfo, u32* pClearSetQuestAreaId);
    u32 getTargetEnemyGroupNum() const;
    u32 getTargetEnemyGroupId(u32 idx) const;
    u32 getTargetEnemyLevel(u32 idx) const;
    bool includsPartyRecommandedEnemy() const;
    bool hasEnemyInfo(u32 enemyGroupId, u32 enemyLv);
    bool isTargetEnemyFlag(u32 flagNo) const;
    bool isTargetEnemySetGroup(u32 stageNo, u32 groupNo) const;
    bool createTargetEnemyInfo(u32 flagNo, nQuest::TargetEnemyInfoArray& targetEnemyInfo);
    void pushLeaderQuestProgress(u32 characterId, u32 processNo, u32 blockNo);
    void removeLeaderQuestProgress(u32 processNo, u32 blockNo);
    cQuestTask();
    cQuestTask(cQuestManagerBase* pParent, u32 questType, nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 keyId);
    virtual ~cQuestTask();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    MtTypedArray<cQuestOmTargetData> mOmTarget;  // offset: 0x8
protected:
    QuestLayoutFlagArray mLayoutFlagArray;  // offset: 0x28
    EnemyGroupIdArray mEnemyGroupIdArray;  // offset: 0x48
    LeaderQuestProgressArray mLeaderQuestProgressQueue;  // offset: 0x68
    DeliveryItemArray mDeliveryItemArray;  // offset: 0x88
    cQuestTaskParam mTaskParam;  // offset: 0xa8
    QuestNoticeInfo mNoticeInfo;  // offset: 0x298
    sQuestManagerExt::cTouchOmInfo* mpTouchOmInfo;  // offset: 0x2a0
    cQuestPersonalData* mpMyData;  // offset: 0x2a8
    cQuestPersonalData* mpLeaderData;  // offset: 0x2b0
    cQuestManagerBase* mpParent;  // offset: 0x2b8
    TaskBoolMember mBoolMember;  // offset: 0x2c0
    nQuest::QUEST_ID mQuestId;  // offset: 0x2c8
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x2d8
    u32 mDeliverDecideNpcId;  // offset: 0x2e8
    u32 mKeyId;  // offset: 0x2ec
    u32 mErrorCode;  // offset: 0x2f0
    f32 mNextProgressTime;  // offset: 0x2f4
    u16 mErrorNum;  // offset: 0x2f8
    u8 mClearSetQuestAreaId[4];  // offset: 0x2fa
    s8 mProgressProcessNo;  // offset: 0x2fe
    u8 mClearSetQuestAreaIdRefIdx;  // offset: 0x2ff
    u8 mWaitOrderProcessNo;  // offset: 0x300
public:
    static MyDTI DTI;
};

class cQuestPersonalData : public MtObject
{
    // inferred: cQuestTask::onFlag calls cQuestPersonalData::onFlag
    friend class cQuestTask;
public:
    class MyDTI;
    class cQuestPurpose;
    class cQuestFlag;
public:
    using QuestPurposeArray = MtTypedArray<cQuestPersonalData::cQuestPurpose>;
    using QuestFlagArray = MtTypedArray<cQuestPersonalData::cQuestFlag>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuestPurpose : public MtObject
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
        u32 getPurposeNo() const;
        cQuestPurpose();
        cQuestPurpose(u32 purposeNo);
        virtual ~cQuestPurpose();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mPurposeNo;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cQuestFlag : public MtObject
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
        u32 getFlagNo() const;
        cQuestFlag();
        cQuestFlag(u32 flagNo);
        virtual ~cQuestFlag();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mFlagNo;  // offset: 0x8
    public:
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
    s32 getPurpose() const;
    s32 getPurpose(u32 idx) const;
    u32 getPurposeNum() const;
    void deletePurpose();
    void resetPurpose();
    void incrPurpose();
    void pushPurpose(u32 purposeNo);
    void popPurpose();
    void addMarker();
    bool isEndProcess(u32 processNo) const;
    cQuestTask* getQuestTask() const;
    cQuestPersonalData& setParent(cQuestTask* pTask);
    nQuest::cQuestDeliverRequestInfo* getDeliverRequestInfo() const;
    bool isDeliverNpc(uControl* pCtrl) const;
    s32 getRequestDeliverProcessNo(uControl* pCtrl) const;
    s32 getCurrentBlockNo(u32 processNo) const;
    cQuestTask::cQuestProcess* getProcess(u32 processNo) const;
    bool isFlag(u32 flagNo) const;
    bool isFlagFsm(u32 flagNo) const;
    bool isLayoutFlag(u32 flagNo) const;
    void onFlag(u32 flagNo);
    void onFlagFsm(u32 flagNo);
    void onLayoutFlag(u32 flagNo);
    void offFlag(u32 flagNo);
    void offFlagFsm(u32 flagNo);
    void offLayoutFlag(u32 flagNo);
    void deleteFlags();
    void deleteFlagFsm();
    u32 getFlagNum() const;
    u32 getLayoutFlagNum() const;
    u32 getFlagNo(u32 idx) const;
    u32 getLayoutFlagNo(u32 idx) const;
    nQuest::cTalkData* getTalkData(u32 npcId);
    void addTalkData(u32 npcId, u32 groupSerial);
    void removeTalkData(u32 npcId);
    void resetDispOrderUI();
    bool hasOrdered() const;
    void setIsOrder(bool isOrder);
    void cancel();
    bool isCancel() const;
    bool isClear() const;
    void clear();
    bool isDelete() const;
    bool hasProcessInitialized() const;
    cQuestTask::PERSONAL_DATA_TYPE getPersonalDataType() const;
    void setPersonalDataType(cQuestTask::PERSONAL_DATA_TYPE type);
    u32 getPrtUniqueId() const;
    bool createTargetEnemyInfo();
    void notifyFulfillDeliverItem(u32 npcId);
    u32 getBlockNo(u32 processNo) const;
    s32 getLastDecideDeliverBlockNo() const;
    void setLastDecideDeliverBlockNo(s32 blockNo);
    s32 getCurrentDeliverBlockNo() const;
    void setCurrentDeliverBlockNo(s32 blockNo);
protected:
    cQuestTask::cQuestProcess* getDeliverProcess(uControl* pCtrl) const;
    cQuestFlag* getFlag(u32 flagNo, const QuestFlagArray& flags) const;
    bool isFlag(u32 flagNo, const QuestFlagArray& flags) const;
    void onFlag(u32 flagNo, QuestFlagArray& flags);
    void offFlag(u32 flagNo, QuestFlagArray& flags);
    void deleteFlags(QuestFlagArray& flags);
public:
    void move();
    void executeResult();
    void addProcess(const CQuestProcessState* pProcessState);
    void addProcessForHelper(const CQuestProcessState* pProcessState);
    void overwriteEnemyDieNumForLight(u32 emDieNum);
    u32 getEnemyDieNumForLight() const;
    cQuestPersonalData();
    cQuestPersonalData(const cQuestPersonalData& obj);
    virtual ~cQuestPersonalData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    cQuestTask::QuestProcessArray mProcessList;  // offset: 0x8
    QuestPurposeArray mAnnounceLog;  // offset: 0x28
    nQuest::TalkDataArray mTalkData;  // offset: 0x48
    QuestFlagArray mQuestFlag;  // offset: 0x68
    QuestFlagArray mQuestFlagFsm;  // offset: 0x88
    QuestFlagArray mQuestLayoutFlag;  // offset: 0xa8
    cQuestTask* mpParent;  // offset: 0xc8
    cQuestTask::PERSONAL_DATA_TYPE mPersonalDataType;  // offset: 0xd0
    s32 mLastDecideDeliverBlockNo;  // offset: 0xd4
    s32 mCurrentDeliverBlockNo;  // offset: 0xd8
    bool mIsEndProcess0;  // offset: 0xdc
    bool mIsClear;  // offset: 0xdd
    bool mIsCancel;  // offset: 0xde
    bool mIsOrder;  // offset: 0xdf
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cQuestPersonalData::hasOrdered() const {
    return this->mIsOrder;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cQuestPersonalData::isCancel() const {
    return this->mIsCancel;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cQuestPersonalData::isClear() const {
    return this->mIsClear;
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestPersonalData::cQuestPurpose::cQuestPurpose() {
    this->mPurposeNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestPersonalData::cQuestFlag::cQuestFlag() {
    this->mFlagNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cQuestTask::cLayoutFlagInfo::cLayoutFlagInfo() {
    this->mFlagNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestTask::cLayoutFlagInfo::cSetInfo::cSetInfo() {
    this->mGroupId = static_cast<u32>(0);
    this->mStageNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cQuestTask::cEnemyGroupInfo::getEnemyGroupId() const {
    return this->mEnemyGroupId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cQuestTask::cEnemyGroupInfo::getEnemyLevel() const {
    return this->mEnemyLevel;
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestTask::cEnemyGroupInfo::cEnemyGroupInfo() {
    this->mEnemyGroupId = static_cast<u32>(0);
    this->mEnemyLevel = static_cast<u32>(0);
    this->mIsPartyRecommanded = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestTask::cLeaderQuestProgress::cLeaderQuestProgress() {
    this->mCharacterId = static_cast<u32>(0);
    this->mProcessNo = static_cast<u32>(0);
    this->mBlockNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cQuestTask::cDeliveryItemInfo::getItemId() const {
    return this->mItemId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cQuestTask::cDeliveryItemInfo::getItemNum() const {
    return this->mItemNum;
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestTask::cDeliveryItemInfo::cDeliveryItemInfo() {
    this->mItemId = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestTask* cQuestTask::cQuestProcess::getQuestTask() const {
    return this->mpParent;
}
