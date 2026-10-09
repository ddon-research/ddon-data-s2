#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cQuestManagerBase.h"
#include "nQuest.h"

// Forward declarations
class CDataFortDefenseNoticeData;
class CDataQuestContentsSituationInfo;
class CDataQuestContentsSituationInfoDetail;
class CDataQuestEnemyInfo;
class CDataQuestLayoutFlagSetInfo;
class CDataQuestProcessState;
class CDataRaidBossNoticeData;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cCycleQuestManagerBase;
class cQuestTask;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cCycleContentsSituationInfo; }

// Declarations
class cCycleQuestSubCategoryManager;

// Type aliases from DWARF
using FortDefenseNoticeDataVec = MtTypedArray<CDataFortDefenseNoticeData>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestContentsSituationInfoDetailVec = MtTypedArray<CDataQuestContentsSituationInfoDetail>;
using QuestContentsSituationInfoVec = MtTypedArray<CDataQuestContentsSituationInfo>;
using RaidBossNoticeDataVec = MtTypedArray<CDataRaidBossNoticeData>;
using _Sizet = long unsigned int;
namespace nQuest { using CycleContentsSituationInfoArray = MtTypedArray<nQuest::cCycleContentsSituationInfo>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCycleQuestSubCategoryManager : public cQuestManagerBase
{
public:
    class MyDTI;
    class cCycleContentsTaskInfo;
public:
    using CycleContentsTaskInfArray = MtTypedArray<cCycleQuestSubCategoryManager::cCycleContentsTaskInfo>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCycleContentsTaskInfo : public MtObject
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
        nQuest::QUEST_ID getQuestId() const;
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::CYCLE_CONTENTS_NOTICE_TYPE getNoticeType() const;
        bool isEmpty() const;
        void update();
        cCycleContentsTaskInfo();
        cCycleContentsTaskInfo(cQuestTask* pTask, nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType);
        virtual ~cCycleContentsTaskInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        cQuestTask* mpTask;  // offset: 0x8
        nQuest::CYCLE_CONTENTS_NOTICE_TYPE mNoticeType;  // offset: 0x10
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
    virtual u32 getQuestManagerType() const;  // vtable slot 11
    void setParent(cCycleQuestManagerBase* pParent);
    nQuest::SCHEDULE_ID getScheduleIdFromNoticeType(nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType) const;
    nQuest::QUEST_ID getQuestId(u32 period, u32 situationNo) const;
    void setSubCategoryType(nQuest::CYCLE_CONTENTS_SUB_CATEGORY type);
    nQuest::CYCLE_CONTENTS_SUB_CATEGORY getSubCategoryType() const;
    nQuest::CYCLE_CONTENTS_NOTICE_TYPE getNoticeType(nQuest::SCHEDULE_ID scheduleId) const;
    const nQuest::CycleContentsSituationInfoArray& getSituationInfoArray() const;
    nQuest::SCHEDULE_ID getCycleContentsScheduleId() const;
    void setCycleContentsScheduleId(nQuest::SCHEDULE_ID scheduleId);
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriod() const;
    void setCycleContentsPeriod(nQuest::CYCLE_CONTENTS_PERIOD period);
    bool isDistEnable() const;
    void callbackCycleContentsEnable(bool isEnable);
    void setDistributeSituation(QuestContentsSituationInfoVec& list);
    void registTask(const FortDefenseNoticeDataVec& noticeDataList);
    void registTask(const RaidBossNoticeDataVec& noticeDataList);
    void deleteTaskWithoutMainTask();
    void registSituationInfo(const QuestContentsSituationInfoDetailVec& list);
    bool registMainTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList);
    cQuestTask* getMainTask() const;
    void addTaskInfo(cQuestTask* pTask, nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType);
    cCycleQuestSubCategoryManager();
    virtual ~cCycleQuestSubCategoryManager();
    virtual void move();  // vtable slot 14
    virtual void release();  // vtable slot 13
protected:
    CycleContentsTaskInfArray mTaskInfo;  // offset: 0x30
    nQuest::CycleContentsSituationInfoArray mSituationInfo;  // offset: 0x50
    cCycleQuestManagerBase* mpParent;  // offset: 0x70
    cQuestTask* mpMainTask;  // offset: 0x78
    nQuest::SCHEDULE_ID mCycleContentsScheduleId;  // offset: 0x80
    nQuest::CYCLE_CONTENTS_PERIOD mCycleContentsPeriod;  // offset: 0x90
    s32 mSubCategoryType;  // offset: 0x94
    bool mIsDistEnable;  // offset: 0x98
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::cCycleContentsTaskInfo() {
    this->mpTask = static_cast<cQuestTask*>(nullptr);
    this->mNoticeType = static_cast<nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(0);
}
