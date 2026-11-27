#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "nDDOUtility.h"
#include "nNet.h"
#include "nQuest.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtString;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cQuestSyncDataManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestSyncDataManager : public MtObject
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
    void clear(bool IsLeaveParty);
    void reset();
    void onFlagMySelf();
    void offFlagMySelf();
    void offFlagMySelfAll();
    void startCheckSync(u32 ScheduleId);
    bool isSuccessSync();
    bool checkFlagMyself();
    void setSyncData(u32 ScheduleId, u32 ProcessNo, u32 BlockNo, u32 FlagNo);
    bool checkSyncData(u32 ScheduleId, u32 ProcessNo, u32 BlockNo);
    cQuestSyncDataManager();
    virtual ~cQuestSyncDataManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    nQuest::SCHEDULE_ID mQuestScheduleId;  // offset: 0x8
    u32 mProcessNo;  // offset: 0x18
    u32 mBlockNo;  // offset: 0x1c
    nDDOUtility::cBitSet<8> mPartyFlag;  // offset: 0x20
    s32 mOnMemberNum;  // offset: 0x24
    nNetSv::PARTY_SYNC_FLAG mFlagNo;  // offset: 0x28
    MtString mMemberState;  // offset: 0x30
    bool mIsMyself;  // offset: 0x38
public:
    static MyDTI DTI;
};

inline void* cQuestSyncDataManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
