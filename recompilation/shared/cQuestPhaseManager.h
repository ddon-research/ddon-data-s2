#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestPhaseEvent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cQuestPhaseEvent;
class cQuestPhaseState;

// Declarations
class cQuestPhaseManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using QuestPhaseEventArray = MtTypedArray<cQuestPhaseEvent>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseManager : public cQuestFunctionManagerBase
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
    cQuestPhaseState* getQuestPhaseState() const;
    u32 getPhaseId();
    virtual void move();  // vtable slot 7
    void callbackQuestPhaseNotice(void* pPacket);
    virtual void release();  // vtable slot 6
    cQuestPhaseManager();
    virtual ~cQuestPhaseManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
protected:
    QuestPhaseEventArray mEventList;  // offset: 0x8
    cQuestPhaseState* mpState;  // offset: 0x28
    u32 mPhaseId;  // offset: 0x30
public:
    static MyDTI DTI;
};
