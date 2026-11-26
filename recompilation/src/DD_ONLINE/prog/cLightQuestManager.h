#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cQuestManagerBase.h"
#include "nQuest.h"

// Forward declarations
class CDataLightQuestList;
class CDataLightQuestOrderList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cLightQuestManager;

// Type aliases from DWARF
using CLightQuestList = CDataLightQuestList;
using CLightQuestOrderList = CDataLightQuestOrderList;
using LightQuestOrderListVec = MtTypedArray<CDataLightQuestOrderList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLightQuestManager : public cQuestManagerBase
{
public:
    class MyDTI;
    class cLightQuestInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLightQuestInfo : public MtObject
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
        cLightQuestInfo();
        cLightQuestInfo(nQuest::SCHEDULE_ID scheduleId, nQuest::QUEST_ID questId);
        virtual ~cLightQuestInfo();
    public:
        MtString mOrderMsg;  // offset: 0x8
        MtString mPurpose;  // offset: 0x10
        nQuest::QUEST_ID mQuestId;  // offset: 0x18
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
        u32 mEnemyGroupId;  // offset: 0x38
        u32 mItemId;  // offset: 0x3c
        u32 mEnemyLevel;  // offset: 0x40
        u32 mNum;  // offset: 0x44
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
    void setQuestBoardBaseId(u32 boardBaseId);
    bool hasLightQuestInfo(nQuest::SCHEDULE_ID scheduleId) const;
    cLightQuestInfo* getLightQuestInfo(nQuest::SCHEDULE_ID scheduleId) const;
    cLightQuestInfo* getLightQuestInfo(nQuest::QUEST_ID questId) const;
    u32 getLightQuestTargetNumNow(nQuest::SCHEDULE_ID scheduleId) const;
    bool isFinishedQuesetOrder() const;
    bool isFinishedGpComplete() const;
    u32 getGpCompleteErrorCode() const;
    bool isGpComplete() const;
    u32 getCompleteGp() const;
    u32 getNotCompleteQuestNum() const;
    virtual void move();  // vtable slot 14
    virtual void getQuestList();  // vtable slot 15
    void registTask(const LightQuestOrderListVec& list);
    void requestOrderQuest(nQuest::SCHEDULE_ID scheduleId);
    void callbackOrder(u32 errorCode);
    void requestGpComplete();
    void callbackGpComplete(u32 errorCode);
protected:
    void callbackGetLightQuestList(u32 errorCode);
    void addLightQuestInfo(nQuest::SCHEDULE_ID scheduleId, nQuest::QUEST_ID questId, CLightQuestList* pNode);
    void addLightQuestInfo(nQuest::SCHEDULE_ID scheduleId, nQuest::QUEST_ID questId, CLightQuestOrderList* pNode);
    void forceDeleteNotOrder();
public:
    cLightQuestManager();
    virtual ~cLightQuestManager();
protected:
    MtTypedArray<cLightQuestInfo> mLightQuestInfo;  // offset: 0x30
    u32 mQuestBoardBaseId;  // offset: 0x50
    bool mIsReqOrderQuest;  // offset: 0x54
    u32 mCompleteGp;  // offset: 0x58
    bool mIsGpComplete;  // offset: 0x5c
    bool mIsReqGpComplete;  // offset: 0x5d
    u32 mNotCompleteQuestNum;  // offset: 0x60
    u32 mGpCompleteErrorCode;  // offset: 0x64
public:
    static MyDTI DTI;
};

inline void* cLightQuestManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool cLightQuestManager::isFinishedGpComplete() const {
    return this->mIsReqGpComplete;
}

inline u32 cLightQuestManager::getGpCompleteErrorCode() const {
    return this->mGpCompleteErrorCode;
}

inline bool cLightQuestManager::isGpComplete() const {
    return this->mIsGpComplete;
}

inline u32 cLightQuestManager::getCompleteGp() const {
    return this->mCompleteGp;
}

inline u32 cLightQuestManager::getNotCompleteQuestNum() const {
    return this->mNotCompleteQuestNum;
}

inline void* cLightQuestManager::cLightQuestInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cLightQuestManager::cLightQuestInfo::cLightQuestInfo() {
    this->mEnemyLevel = 0;
    this->mNum = 0;
    this->mEnemyGroupId = 0;
    this->mItemId = 0;
}
