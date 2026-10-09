#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cQuestTask.h"

// Forward declarations
class CDataQuestEnemyInfo;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestList;
class CDataQuestOrderList;
class CDataQuestProcessState;
class MtAllocator;
class MtDTI;
class cQuestTask;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cQuestManagerBase;

// Type aliases from DWARF
using CQuestList = CDataQuestList;
using CQuestOrderList = CDataQuestOrderList;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestTaskArray = MtTypedArray<cQuestTask>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestManagerBase : public MtObject
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
    virtual u32 getQuestNum() const;  // vtable slot 6
    u32 getQuestOrderNum() const;
    virtual cQuestTask* getQuestTask(u32 index) const;  // vtable slot 7
    virtual cQuestTask* getQuestTask(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 8
    virtual cQuestTask* getQuestTask(nQuest::QUEST_ID questId) const;  // vtable slot 9
    bool hasEndDistributionQuest() const;
    void cancelQuestNotOrder();
    void cancelQuestNotOrderEndDistribution();
    virtual void deleteQuestTask(cQuestTask* pTask);  // vtable slot 10
    void initStage();
protected:
    cQuestTask* newInstanceTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 keyId);
    void addTask(cQuestTask* pTask);
    void updateQuestTask(cQuestTask* pTask);
public:
    bool isUpdateIndexList() const;
    virtual u32 getQuestManagerType() const = 0;  // vtable slot 11
    // Address: 0x019636c0 - 0x019636c1 (1 bytes)
    virtual void registQuestList() {}  // vtable slot 12
    virtual void release();  // vtable slot 13
    void deleteQuestAll(bool isCancel);
    virtual void move();  // vtable slot 14
    virtual void getQuestList();  // vtable slot 15
    bool registTask(const CQuestList& param, const MtTypedArray<CDataQuestProcessState>& processList, cQuestTask* * ppTask);
    bool registTask(const CQuestOrderList& param, cQuestTask* * ppTask);
    bool registTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList, cQuestTask* * ppTask);
    bool registTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, cQuestTask* * ppTask);
    bool registHelperTask(const CQuestOrderList& param, cQuestTask* * ppTask);
    void noticeDecideDeliverItem(nQuest::SCHEDULE_ID scheduleId);
    void callbackReloadMasterData();
    virtual void callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty);  // vtable slot 16
    virtual void cancelWaitOrder(cQuestTask* pTask, bool& isReqCancel);  // vtable slot 17
protected:
    void callbackGetQuestList(u32 errorCode);
public:
    cQuestManagerBase(MT_CTSTR managerName);
    virtual ~cQuestManagerBase();
protected:
    QuestTaskArray mQuestTask;  // offset: 0x8
    bool mIsReqGetQuestList;  // offset: 0x28
public:
    static MyDTI DTI;
};
