#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cQuestManagerBase.h"
#include "nQuest.h"

// Forward declarations
class CDataQuestEnemyInfo;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestProcessState;
class CDataTimeGainQuestList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cQuestTask;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cEndContentsGroupQuestInfo; }

// Declarations
class cEndContentsManager;

// Type aliases from DWARF
using CTimeGainQuestList = CDataTimeGainQuestList;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nQuest { using EndContentsGroupQuestInfoArray = MtTypedArray<nQuest::cEndContentsGroupQuestInfo>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cEndContentsManager : public cQuestManagerBase
{
public:
    enum
    {
        END_CONTENTS_PURPOSE_NUM = 3,
    };
    enum
    {
        R0_NONE = 0,
        R0_INITIALIZE = 1,
        R0_DEMO = 2,
        R0_START = 3,
        R0_MAIN = 4,
        R0_CLEAR = 5,
        R0_INTERRUPT = 6,
        R0_FAILED = 7,
        R0_END = 8,
        R0_EXIT = 9,
    };
    enum R1_DEMO
    {
        R1_DEMO_INIT = 0,
        R1_DEMO_MOVE = 1,
        R1_DEMO_INIT_AFTER_JUMP = 2,
        R1_DEMO_WAIT_AFTER_JUMP = 3,
        R1_DEMO_MOVE_AFTER_JUMP = 4,
    };
    enum
    {
        R1_END_START = 0,
        R1_END_WAIT = 1,
        R1_END_WAIT_TIME = 2,
        R1_END_END = 3,
        R1_END_FADE_START_WAIT = 4,
    };
public:
    class MyDTI;
    class cEndContentsGroupInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cEndContentsGroupInfo
    {
    public:
        u32 getGroupNo() const;
        u32 getEntryNpcId() const;
        cEndContentsGroupInfo();
        cEndContentsGroupInfo(s32 GroupNo, s32 NpcId);
        virtual ~cEndContentsGroupInfo();
    protected:
        u32 mEndContentsGroupNo;  // offset: 0x8
        u32 mEntryNpcId;  // offset: 0xc
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
    bool isPlayNow() const;
    bool isPlayEnd() const;
    bool isDispPurpose() const;
    bool isDispTimer() const;
    nQuest::SCHEDULE_ID getMainTaskScheduleId() const;
    nQuest::QUEST_ID getMainTaskQuestId() const;
    u32 getEndContentsGroupNo(u32 NpcId);
    u32 getEndContentsEntryNpcId(u32 GroupNo);
protected:
    void setRno0(u8 r0);
    void setRno0(u8 r0, u8 r1);
    void setRno1(u8 r1);
public:
    u32 getEndContentsPurposeMaxNum() const;
    u32 getEndContentsPurposeNum() const;
    s32 getEndContentsPurposeNo(u32 idx) const;
    void addEndContentsPurposeNo(u32 purposeNo);
    void removeEndContentsPurposeNo(u32 purposeNo);
    bool isFinish() const;
    bool isClear() const;
    bool isInterrupt() const;
    bool isFailed() const;
    bool isExit() const;
    void clearEndContents();
    void interruptEndContents();
    void failedEndContents();
    void exitEndContents();
    void reqPlayStartDemo();
    void reqPlayStartDemoAfterJump();
    void reqPlayStart();
    void reset();
    virtual void move();  // vtable slot 14
    bool registMainTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList);
    bool registMainTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList);
    void notifyLeaveParty();
    void moveEndContentsInitialize();
    void moveEndContentsDemo();
    void moveEndContentsStart();
    void moveEndContentsMain();
    void moveEndContentsClear();
    void moveEndContentsInterrupt();
    void moveEndContentsFailed();
    void moveEndContentsEnd();
    void moveEndContentsExit();
    virtual void deleteQuestTask(cQuestTask* pTask);  // vtable slot 10
    virtual void callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty);  // vtable slot 16
    void getClearTimeStr(MtString& rStr);
protected:
    void resetFlag();
public:
    virtual u32 getQuestManagerType() const;  // vtable slot 11
    u32 getMainStageNo(u32 questId) const;
    u32 getMainStageStartPos() const;
    void setMainStageStartPos(u32 startPos);
    u32 getReturnStageNo() const;
    u32 getQuestId() const;
    void setQuestId(u32 id);
    u32 getScheduleId() const;
    void setScheduleId(u32 id);
    void setPlayStartQuestId(nQuest::QUEST_ID questId);
    s32 getEndContentsListIndex() const;
    void setEndContentsListIndex(s32 index);
    void addDistEndContents(const CTimeGainQuestList* pQuestList);
    void resetDistEndContentsList();
    nQuest::QUEST_ID getDistEndContentsQuestId(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::cEndContentsGroupQuestInfo* getEndContentsGroupQuestInfo() const;
    nQuest::cEndContentsGroupQuestInfo* getEndContentsGroupQuestInfo(nQuest::SCHEDULE_ID scheduleId) const;
    bool isEndFlowNow();
protected:
    u32 getStartDemoStageNo(nQuest::QUEST_ID questId) const;
    u32 getStartDemoNo(nQuest::QUEST_ID questId) const;
    virtual void getQuestList();  // vtable slot 15
public:
    void setRoutineStart();
    void setRoutineEnd();
    cEndContentsManager();
    virtual ~cEndContentsManager();
protected:
    nQuest::EndContentsGroupQuestInfoArray mDistEndContentsList;  // offset: 0x30
    nQuest::QUEST_ID mPlayStartQuestId;  // offset: 0x50
    cEndContentsGroupInfo mEndContentsGroupInfo[4];  // offset: 0x60
    cQuestTask* mpMainTask;  // offset: 0xa0
    u32 mQuestId;  // offset: 0xa8
    u32 mScheduleId;  // offset: 0xac
    s32 mEndContentsPurpose[3];  // offset: 0xb0
    s32 mContentsListIndex;  // offset: 0xbc
    f32 mWaitTimer;  // offset: 0xc0
    u8 mRno0;  // offset: 0xc4
    u8 mRno1;  // offset: 0xc5
    u8 mNextR0;  // offset: 0xc6
    u8 mNextR1;  // offset: 0xc7
    bool mIsLeader;  // offset: 0xc8
    bool mIsClear;  // offset: 0xc9
    bool mIsInterrupt;  // offset: 0xca
    bool mIsFailed;  // offset: 0xcb
    bool mIsExit;  // offset: 0xcc
    bool mIsStart;  // offset: 0xcd
    f32 mStartWaitTimer;  // offset: 0xd0
    u32 mStartPos;  // offset: 0xd4
public:
    static MyDTI DTI;
};
