#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cQuestManagerBase.h"

// Forward declarations
class CDataSetQuestList;
class CDataSetQuestOrderList;
class MtAllocator;
class MtDTI;
class MtObject;
class cQuestTask;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cSetQuestManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SetQuestListVec = MtTypedArray<CDataSetQuestList>;
using SetQuestOrderListVec = MtTypedArray<CDataSetQuestOrderList>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSetQuestManager : public cQuestManagerBase
{
public:
    class MyDTI;
    class cMemberInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMemberInfo : public MtObject
    {
        friend class cSetQuestManager;
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
        u32 getSetQuestDistributeId() const;
        void init(u32 characterId, u32 setQuestDistId);
        void update(u32 setQuestDistId);
        void reset();
        cMemberInfo();
        virtual ~cMemberInfo();
    protected:
        u32 mCharacterId;  // offset: 0x8
        u32 mSetQuestDistributeId;  // offset: 0xc
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
    void getQuestList(u32 setQstDistId);
    virtual void registQuestList();  // vtable slot 12
    void registTask(u32 distId, const SetQuestListVec& list);
    void registTask(const SetQuestOrderListVec& list);
    virtual void callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty);  // vtable slot 16
    virtual void cancelWaitOrder(cQuestTask* pTask, bool& isReqCancel);  // vtable slot 17
    void callbackGetSetQuestList(u32 characterId, u32 setQuestDistId);
    void resetPartyMemberInfo();
    void resetPartyMemberInfo(u32 characterId);
    void callbackGetAreaQuestInfoList(u32 errorCode);
protected:
    virtual void getQuestList();  // vtable slot 15
public:
    cSetQuestManager();
    virtual ~cSetQuestManager();
protected:
    cMemberInfo* mpMemberInfo;  // offset: 0x30
    u32 mSetQstDistId;  // offset: 0x38
public:
    static MyDTI DTI;
};

inline void* cSetQuestManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cSetQuestManager::cMemberInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cSetQuestManager::cMemberInfo::cMemberInfo() {
    this->mCharacterId = 0;
    this->mSetQuestDistributeId = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cSetQuestManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cSetQuestManager::DTI);
}

inline void cSetQuestManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSetQuestManager::DTI)->memFree(p_addr);
}

inline void* cSetQuestManager::cMemberInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cSetQuestManager::cMemberInfo::DTI)->memAlloc(sz, align, ::cSetQuestManager::cMemberInfo::DTI.::MtDTI::getID());
}

inline void cSetQuestManager::cMemberInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSetQuestManager::cMemberInfo::DTI)->memFree(p_addr);
}

inline void cSetQuestManager::cMemberInfo::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSetQuestManager::cMemberInfo::DTI)->memFree(p_addr);
}
