#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cQuestManagerBase.h"

// Forward declarations
class CDataTutorialQuestList;
class CDataTutorialQuestOrderList;
class MtAllocator;
class MtDTI;
class MtObject;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cTutorialQuestManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TutorialQuestListVec = MtTypedArray<CDataTutorialQuestList>;
using TutorialQuestOrderListVec = MtTypedArray<CDataTutorialQuestOrderList>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cTutorialQuestManager : public cQuestManagerBase
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
    virtual u32 getQuestManagerType() const;  // vtable slot 11
    void getQuestList(u32 stageNo);
    virtual void registQuestList();  // vtable slot 12
    virtual void callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty);  // vtable slot 16
    void registTask(const TutorialQuestListVec& list);
    void registTask(const TutorialQuestOrderListVec& list);
    virtual void release();  // vtable slot 13
protected:
    virtual void getQuestList() {}  // vtable slot 15
public:
    cTutorialQuestManager();
    virtual ~cTutorialQuestManager() {}
protected:
    u32 mStageNo;  // offset: 0x2c
public:
    static MyDTI DTI;
};

inline void* cTutorialQuestManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cTutorialQuestManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cTutorialQuestManager::DTI);
}

inline void cTutorialQuestManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cTutorialQuestManager::DTI)->memFree(p_addr);
}
