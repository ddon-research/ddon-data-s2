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
class CDataLotQuestOrderList;
class MtAllocator;
class MtDTI;
class MtObject;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cPawnQuestManager;

// Type aliases from DWARF
using LotQuestOrderListVec = MtTypedArray<CDataLotQuestOrderList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cPawnQuestManager : public cQuestManagerBase
{
public:
    enum
    {
        TALK_TYPE_NORMAL = -1,
        TALK_TYPE_CLEAR = 0,
    };
    enum
    {
        TYPE_NONE = 0,
        TYPE_BATTLE = 1,
        TYPE_DELIVER = 2,
        TYPE_PHOTO = 3,
    };
public:
    class MyDTI;
    class cPawnQuestInfo;
public:
    using PawnQuestInfoArray = MtTypedArray<cPawnQuestManager::cPawnQuestInfo>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPawnQuestInfo : public MtObject
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
        u32 getItemId() const;
        u32 getItemNum() const;
        u32 getEnemyGroupId() const;
        u32 getEnemyLv() const;
        u32 getEnemyNum() const;
        u8 getType() const;
        void setEnemyInfo(u32 enemyGroupId, u32 enemyLv, u32 enemyNum);
        void setDeliverInfo(u32 itemId, u32 itemNum);
        cPawnQuestInfo();
        cPawnQuestInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId);
        cPawnQuestInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u8 type, u32 param01, u32 param02, u32 param03, u32 param04);
        virtual ~cPawnQuestInfo();
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x18
        u32 mParam01;  // offset: 0x28
        u32 mParam02;  // offset: 0x2c
        u32 mParam03;  // offset: 0x30
        u8 mType;  // offset: 0x34
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
    cPawnQuestInfo* getPawnQuestInfo(nQuest::QUEST_ID questId) const;
    cPawnQuestInfo* getPawnQuestInfo(nQuest::SCHEDULE_ID scheduleId) const;
    void switchTalk(s8 type);
    s8 getSwitchTalkType() const;
    bool hasSwitchTalk() const;
    virtual void getQuestList();  // vtable slot 15
    virtual void release();  // vtable slot 13
    virtual void registQuestList();  // vtable slot 12
    void registTask(const LotQuestOrderListVec& list);
    void requestOrderQuest(nQuest::SCHEDULE_ID scheduleId);
    void callbackOrder(u32 errorCode);
    cPawnQuestManager();
    virtual ~cPawnQuestManager();
protected:
    PawnQuestInfoArray mPawnQuestInfoList;  // offset: 0x30
    s8 mSwtichTalkType;  // offset: 0x50
    bool mIsReqOrderQuest;  // offset: 0x51
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cPawnQuestManager::cPawnQuestInfo::cPawnQuestInfo() {
    this->mParam01 = static_cast<u32>(0);
    this->mParam02 = static_cast<u32>(0);
    this->mParam03 = static_cast<u32>(0);
    this->mType = static_cast<u8>(3);
}
