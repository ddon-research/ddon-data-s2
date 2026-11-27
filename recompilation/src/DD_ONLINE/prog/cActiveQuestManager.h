#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"

// Forward declarations
class CDataPriorityQuest;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cActiveQuestManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using PriorityQuestVec = MtTypedArray<CDataPriorityQuest>;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cActiveQuestManager : public cQuestFunctionManagerBase
{
public:
    class MyDTI;
    class cActiveQuestData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cActiveQuestData : public MtObject
    {
        friend class cActiveQuestManager;
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
        nQuest::SCHEDULE_ID getScheduleId(u32 idx) const;
        void setScheduleId(u32 idx, nQuest::SCHEDULE_ID scheduleId);
        void init(u32 characterId);
        void reset();
        cActiveQuestData();
        virtual ~cActiveQuestData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mCharacterId;  // offset: 0x8
        u32 mScheduleId[3];  // offset: 0xc
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
    bool isActiveQuest(nQuest::SCHEDULE_ID scheduleId) const;
    bool isActiveQuest(nQuest::SCHEDULE_ID scheduleId, u32* pIdx, s32 dispType) const;
    nQuest::ACTIVE_QUEST_TYPE getActiveQuestDispType() const;
    cActiveQuestData* getActiveQuestDataFromType(nQuest::ACTIVE_QUEST_TYPE dispType) const;
    u32 getActiveQuestFromCharacterId(u32 characterId, u32 idx) const;
    nQuest::SCHEDULE_ID getActiveQuest(u32 idx) const;
    nQuest::SCHEDULE_ID getActiveQuest(nQuest::ACTIVE_QUEST_TYPE dispType, u32 idx) const;
    bool setActiveQuest(nQuest::SCHEDULE_ID scheduleId);
    void callbackRequestSetActiveQuest();
    u32 getActiveQuestNum() const;
    u32 getActiveQuestNum(nQuest::ACTIVE_QUEST_TYPE dispType) const;
protected:
    cActiveQuestData* getActiveQuestData(u32 characterId) const;
    cActiveQuestData* getBlankActiveQuestData() const;
public:
    void requestGetActiveQuest();
    void cancelActiveQuest(nQuest::SCHEDULE_ID scheduleId);
    void deleteActiveQuest(u32 characterId);
    void deleteActiveQuestAll();
    void callbackNoticeSetActiveQuest(u32 characterId, const PriorityQuestVec& priorityQuestList);
    virtual void release();  // vtable slot 6
    bool isEnableRequest() const;
    bool isEnableRequestNum() const;
    void registActiveQuestList(const PriorityQuestVec& priorityQuestList);
protected:
    void callbackGetActiveQuest(u32 errorCode);
    void callbackSetActiveQuest(u32 errorCode);
    void callbackCancelActiveQuest(u32 errorCode);
public:
    cActiveQuestManager();
    virtual ~cActiveQuestManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    cActiveQuestData* mpActiveQuestList;  // offset: 0x8
    bool mIsRequestEnable;  // offset: 0x10
    u32 mRequestNum;  // offset: 0x14
public:
    static MyDTI DTI;
};

inline void* cActiveQuestManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cActiveQuestManager::cActiveQuestData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cActiveQuestManager::cActiveQuestData::cActiveQuestData() {
    this->mScheduleId[1] = 0;
    this->mScheduleId[2] = 0;
    this->mCharacterId = 0;
    this->mScheduleId[0] = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cActiveQuestManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cActiveQuestManager::DTI);
}

inline void cActiveQuestManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cActiveQuestManager::DTI)->memFree(p_addr);
}

inline void* cActiveQuestManager::cActiveQuestData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cActiveQuestManager::cActiveQuestData::DTI)->memAlloc(sz, align, ::cActiveQuestManager::cActiveQuestData::DTI.::MtDTI::getID());
}

inline void cActiveQuestManager::cActiveQuestData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cActiveQuestManager::cActiveQuestData::DTI)->memFree(p_addr);
}

inline void cActiveQuestManager::cActiveQuestData::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cActiveQuestManager::cActiveQuestData::DTI)->memFree(p_addr);
}
