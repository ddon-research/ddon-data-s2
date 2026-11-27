#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cCycleQuestManagerBase.h"
#include "nQuest.h"

// Forward declarations
class CDataClearTimePointBonus;
class CDataHasRegionBreakReward;
class CDataRaidBossEnemyParam;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cNamedParam;
namespace nQuest { class SCHEDULE_ID; }
class uCharacter;

// Declarations
class cCycle04QuestManager;

// Type aliases from DWARF
using CRaidBossEnemyParam = CDataRaidBossEnemyParam;
using ClearTimePointBonusVec = MtTypedArray<CDataClearTimePointBonus>;
using HasRegionBreakRewardVec = MtTypedArray<CDataHasRegionBreakReward>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCycle04QuestManager : public cCycleQuestManagerBase
{
public:
    class MyDTI;
    class cClearTimeBonus;
    class cRegionBreakReward;
public:
    using ClearTimeBonusArray = MtTypedArray<cCycle04QuestManager::cClearTimeBonus>;
    using RegionBreakRewardArray = MtTypedArray<cCycle04QuestManager::cRegionBreakReward>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cClearTimeBonus : public MtObject
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
        u32 getSeconds() const;
        u32 getRatio() const;
        cClearTimeBonus();
        cClearTimeBonus(u32 seconds, u32 ratio);
        virtual ~cClearTimeBonus();
        virtual void createProerty(MtPropertyList& s);  // vtable slot 6
    protected:
        u32 mSeconds;  // offset: 0x8
        u32 mRatio;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cRegionBreakReward : public MtObject
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
        u32 getRegionNo() const;
        cRegionBreakReward();
        cRegionBreakReward(u32 regionNo);
    protected:
        u32 mRegionNo;  // offset: 0x8
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
    virtual u32 getMainStageNo(nQuest::SCHEDULE_ID cycleContentsScheduleId) const;  // vtable slot 23
    virtual nQuest::CYCLE_CONTENTS_CATEGORY getCycleContentsCategory() const;  // vtable slot 29
    void callbackPhase(void* pPacket);
    void setClearTimeBonus(const ClearTimePointBonusVec& clearTimePointBonus);
    u32 getCleraTimeBonusRatio(f32 timer) const;
    void setRaidBossEnemyParam(const CRaidBossEnemyParam& enemyParam);
    void setRaidBossHasRegionBreakReward(const HasRegionBreakRewardVec& regionBreakRewardList);
    cNamedParam* getRaidBossEnemyParam(u32 raidBossId) const;
    virtual u32 getStartDemoStageNo() const;  // vtable slot 27
    virtual u32 getStartDemoNo() const;  // vtable slot 28
    void calcResultPointEx();
    void callbackBreakRegion(uCharacter* pCharacter, u32 regionNo);
    cCycle04QuestManager();
    virtual ~cCycle04QuestManager();
protected:
    ClearTimeBonusArray mClearTimeBonusList;  // offset: 0xe8
    RegionBreakRewardArray mRegionBreakRewardList;  // offset: 0x108
    cNamedParam* mpRaidBossEnemyParam;  // offset: 0x128
    u32 mRaidBossId;  // offset: 0x130
    f32 mRaidBossPlayEndDist;  // offset: 0x134
public:
    static MyDTI DTI;
};

inline void* cCycle04QuestManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCycle04QuestManager::cClearTimeBonus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cCycle04QuestManager::cClearTimeBonus::getSeconds() const {
    return this->mSeconds;
}

inline cCycle04QuestManager::cClearTimeBonus::cClearTimeBonus() {
    this->mSeconds = 0;
    this->mRatio = 0;
}

inline void* cCycle04QuestManager::cRegionBreakReward::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cCycle04QuestManager::cRegionBreakReward::cRegionBreakReward() {
    this->mRegionNo = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cCycle04QuestManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::DTI);
}

inline void cCycle04QuestManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::DTI)->memFree(p_addr);
}

inline void* cCycle04QuestManager::cClearTimeBonus::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::cClearTimeBonus::DTI)->memAlloc(sz, align, ::cCycle04QuestManager::cClearTimeBonus::DTI.::MtDTI::getID());
}

inline void cCycle04QuestManager::cClearTimeBonus::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::cClearTimeBonus::DTI)->memFree(p_addr);
}

inline void* cCycle04QuestManager::cRegionBreakReward::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::cRegionBreakReward::DTI)->memAlloc(sz, align, ::cCycle04QuestManager::cRegionBreakReward::DTI.::MtDTI::getID());
}

inline void cCycle04QuestManager::cRegionBreakReward::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCycle04QuestManager::cRegionBreakReward::DTI)->memFree(p_addr);
}
