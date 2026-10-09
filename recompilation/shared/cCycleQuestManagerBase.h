#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cCycleQuestSubCategoryManager.h"
#include "cQuestManagerBase.h"
#include "nQuest.h"

// Forward declarations
class CDataQuestContentsSituationInfoDetail;
class CDataQuestEnemyInfo;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestProcessState;
class MtAllocator;
class MtDTI;
class MtObject;
class cCycleQuestSubCategoryManager;
class cQuestTask;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cCycleContentsSituationInfo; }
class uGUIMissionResult;

// Declarations
class cCycleQuestManagerBase;

// Type aliases from DWARF
using CycleQuestSubCategoryManagerArray = MtTypedArray<cCycleQuestSubCategoryManager>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestContentsSituationInfoDetailVec = MtTypedArray<CDataQuestContentsSituationInfoDetail>;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cCycleQuestManagerBase : public cQuestManagerBase
{
public:
    enum
    {
        R0_NONE = 0,
        R0_INITIALIZE = 1,
        R0_DEMO = 2,
        R0_START = 3,
        R0_MAIN = 4,
        R0_CLEAR = 5,
        R0_FAILED = 6,
        R0_INTERRUPT = 7,
        R0_END = 8,
        R0_RESULT = 9,
        R0_FINALIZE = 10,
    };
    enum R1_RESULT
    {
        R1_RESULT_DISP_WAIT_START = 0,
        R1_RESULT_DISP_TIME_WAIT = 1,
        R1_RESULT_DISP_MAIN = 2,
        R1_RESULT_DISP_EXIT = 3,
        R1_RESULT_DISP_EXIT_END = 4,
    };
    enum
    {
        CYCLE_PURPOSE_NUM = 3,
    };
    enum R1_DEMO
    {
        R1_DEMO_INIT = 0,
        R1_DEMO_MOVE = 1,
        R1_DEMO_INIT_AFTER_JUMP = 2,
        R1_DEMO_WAIT_AFTER_JUMP = 3,
        R1_DEMO_MOVE_AFTER_JUMP = 4,
        R1_DEMO_WAIT_AREA_JUMP = 5,
    };
    enum R1_MAIN
    {
        R1_MAIN_INIT = 0,
        R1_MAIN_MOVE = 1,
    };
public:
    class MyDTI;
    class cDieEmInfo;
    class cExtraPoint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDieEmInfo : public MtObject
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
        cCycleQuestManagerBase::cDieEmInfo& operator++();
        cCycleQuestManagerBase::cDieEmInfo operator++(int);
        u32 getEmId() const;
        u32 getDieNum() const;
        cDieEmInfo(u32 emId);
    protected:
        u32 mEmId;  // offset: 0x8
        u32 mDieNum;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cExtraPoint : public MtObject
    {
    public:
        cExtraPoint(u32 exPtNo);
        virtual ~cExtraPoint();
    public:
        u32 mExtraPointNo;  // offset: 0x8
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
    u8 getRno0() const;
    u8 getRno1() const;
    bool isResultDispEnd() const;
    bool isDemoNow() const;
    bool isPlayNow() const;
    bool isPlayNowAll() const;
    bool isPlayEnd() const;
    nQuest::SCHEDULE_ID getMainTaskScheduleId() const;
    nQuest::QUEST_ID getMainTaskQuestId() const;
protected:
    void setRno0(u8 r0);
    void setRno0(u8 r0, u8 r1);
    void setRno1(u8 r1);
public:
    u32 getCyclePurposeMaxNum() const;
    u32 getCyclePurposeNum() const;
    s32 getCyclePurposeNo(u32 idx) const;
    void addCyclePurposeNo(u32 purposeNo);
    void removeCyclePurposeNo(u32 purposeNo);
    void reqPlayStartDemo();
    void reqPlayStartDemoAfterJump();
    void reqPlayStart();
    void setRoutineEnd();
    void requestInterruptCycleQuest();
protected:
    void setRoutineStart();
public:
    void routineInitialize();
    void routineDemo();
    void routineStart();
    void routineMain();
    void routineClear();
    void routineFailed();
    void routineInterrupt();
    void routineEnd();
    void routineResult();
    void routineFinalize();
protected:
    virtual void mainInit();  // vtable slot 18
    virtual void mainMove();  // vtable slot 19
    virtual void initResult();  // vtable slot 20
    virtual bool moveWaitResult();  // vtable slot 21
    virtual bool drawResult();  // vtable slot 22
public:
    void setJumpStartPos(u32 StartPos);
    u32 getJumpStartPos();
    virtual u32 getMainStageNo(nQuest::SCHEDULE_ID) const = 0;  // vtable slot 23
    virtual s32 getReturnStageNo() const;  // vtable slot 24
    virtual u32 getReturnStartPosNo() const;  // vtable slot 25
    virtual bool isStartDemo() const;  // vtable slot 26
    virtual u32 getStartDemoStageNo() const;  // vtable slot 27
    virtual u32 getStartDemoNo() const;  // vtable slot 28
    bool isFinish() const;
    bool isClear() const;
    bool isInterrupt() const;
    bool isFailed() const;
    bool isRoutineCycleMain() const;
    void clearCycleQuest();
    void interruptCycleQuest();
    void failedCycleQuest();
    virtual nQuest::CYCLE_CONTENTS_CATEGORY getCycleContentsCategory() const;  // vtable slot 29
    u32 getSubCategoryNum() const;
    nQuest::SCHEDULE_ID getNowHoldingCycleContentsScheduleId() const;
    nQuest::SCHEDULE_ID getCycleContentsScheduleId(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    void setCycleContentsScheduleId(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, nQuest::SCHEDULE_ID scheduleId);
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriod(u32 idx) const;
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriodFromSubCategory(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriodFromScheduleId(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriodFromQuestId(nQuest::QUEST_ID questId) const;
    void setCycleContentsPeriod(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, nQuest::CYCLE_CONTENTS_PERIOD period);
    void setCycleContentsPeriod(nQuest::SCHEDULE_ID cycleContentsScheduleId, nQuest::CYCLE_CONTENTS_PERIOD period);
    bool getCategoryInfo(nQuest::SCHEDULE_ID cycleContentsScheduleId, nQuest::CYCLE_CONTENTS_CATEGORY& category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY& subCategory) const;
    nQuest::SCHEDULE_ID getCycleContentsScheduleIdFromSituation(nQuest::SCHEDULE_ID situationScheduleId);
    bool isAcceptReward() const;
    void setAcceptReward(bool isAcceptReward);
    bool isRewardNothing() const;
    void setRewardNothing(bool isRewardNothing);
    bool isDispRewardMessage() const;
    void setDispRewardMessage(bool isDispRewardMessage);
    u32 getCycleContentsPoint() const;
    void setFailedQuestAnnounce(u32 commonDialog);
    MT_CTSTR getPlaySituationName() const;
    bool isDistEnable(nQuest::SCHEDULE_ID cycleContentsScheduleId) const;
    cCycleQuestSubCategoryManager* getSubCategoryMgr(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    cCycleQuestSubCategoryManager* getSubCategoryMgr(nQuest::SCHEDULE_ID cycleContentsScheduleId) const;
    virtual u32 getQuestNum() const;  // vtable slot 6
    virtual cQuestTask* getQuestTask(u32 index) const;  // vtable slot 7
    virtual cQuestTask* getQuestTask(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 8
    virtual cQuestTask* getQuestTask(nQuest::QUEST_ID questId) const;  // vtable slot 9
    virtual void release();  // vtable slot 13
    virtual void move();  // vtable slot 14
    bool registMainTask(nQuest::SCHEDULE_ID cycleContentsScheduleId, nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList);
    void notifyLeaveParty();
    void callbackCycleContentsEnable(nQuest::SCHEDULE_ID cycleContentsScheduleId, bool isEnable);
    void deleteTaskWithoutMainTaskAll();
    void deleteTaskWithoutMainTask(nQuest::SCHEDULE_ID cycleContentsScheduleId);
    virtual void deleteQuestTask(cQuestTask* pTask);  // vtable slot 10
    bool isEndFlowNow();
protected:
    void resetFlag();
    void calcResultPoint();
    void callbackGetCycleContentsPointList(u32 errorCode);
public:
    virtual u32 getEnemyResultPoint(u32 enemyId);  // vtable slot 30
    const MtTypedArray<cDieEmInfo>& getDieEnemeyInfoList() const;
    void addDieEmInfo(u32 emId);
    u32 getExtraPointListNum() const;
    u32 getExtraPoint() const;
    bool hasExtraPoint(u32 exPtNo) const;
    void addExtraPoint(u32 exPtNo);
    const nQuest::cCycleContentsSituationInfo* getSituationInfo(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::SCHEDULE_ID getScheduleIdFromNoticeType(nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    nQuest::CYCLE_CONTENTS_NOTICE_TYPE getNoticeType(nQuest::SCHEDULE_ID scheduleId) const;
    bool isDistributeSubCategory(nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    bool isThereInPeriod(nQuest::CYCLE_CONTENTS_PERIOD period) const;
    bool isThereInPeriod(nQuest::CYCLE_CONTENTS_PERIOD period, nQuest::SCHEDULE_ID csid) const;
    u32 getCycleContentsScheduleIdFromQuestScheduleId(nQuest::SCHEDULE_ID ScheduleId);
    void registSituationInfo(nQuest::SCHEDULE_ID cycleContentsScheduleId, const QuestContentsSituationInfoDetailVec& list);
    void setDistributSituation(void* pPacket);
    void addTaskInfo(cQuestTask* pTask, nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory);
    nQuest::QUEST_ID getQuestId(u32 period, u32 situationNo, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    cCycleQuestManagerBase(MT_CTSTR managerName);
    virtual ~cCycleQuestManagerBase();
protected:
    CycleQuestSubCategoryManagerArray mSubCategory;  // offset: 0x30
    MtTypedArray<cDieEmInfo> mDieEmInfo;  // offset: 0x50
    MtTypedArray<cExtraPoint> mExtraPointList;  // offset: 0x70
    uGUIMissionResult* mpGUIResult;  // offset: 0x90
    nQuest::SCHEDULE_ID mPlayCycleContentsScheduleId;  // offset: 0x98
    nQuest::QUEST_ID mPlaySituationQuestId;  // offset: 0xa8
    u32 mNowResultPoint;  // offset: 0xb8
    u32 mNowResultPointEx;  // offset: 0xbc
    s32 mCyclePurpose[3];  // offset: 0xc0
    f32 mWaitResult;  // offset: 0xcc
    u8 mR0;  // offset: 0xd0
    u8 mR1;  // offset: 0xd1
    u8 mNextR0;  // offset: 0xd2
    u8 mNextR1;  // offset: 0xd3
    bool mIsLeader;  // offset: 0xd4
    bool mIsClear;  // offset: 0xd5
    bool mIsInterrupt;  // offset: 0xd6
    bool mIsFailed;  // offset: 0xd7
    bool mIsStart;  // offset: 0xd8
    bool mHasPointList;  // offset: 0xd9
    bool mIsAcceptReward;  // offset: 0xda
    bool mIsRewardNothing;  // offset: 0xdb
    bool mIsDispRewardMessage;  // offset: 0xdc
    f32 mStartWaitTimer;  // offset: 0xe0
    u32 mStartPos;  // offset: 0xe4
public:
    static MyDTI DTI;
};
