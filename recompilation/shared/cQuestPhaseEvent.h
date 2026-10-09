#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cQuestPhaseState;

// Declarations
class cQuestPhaseEvent;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseEvent : public MtObject
{
public:
    class MyDTI;
    class cParam;
public:
    using ParamArray = MtTypedArray<cQuestPhaseEvent::cParam>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParam : public MtObject
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
        u32 getType() const;
        u32 getIndex() const;
        u32 getValue() const;
        cParam();
        cParam(u32 type, u32 idx, u32 value);
        virtual ~cParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mType;  // offset: 0x8
        u32 mIdx;  // offset: 0xc
        u32 mValue;  // offset: 0x10
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
    static u32 getParamValue(const ParamArray& paramList, u32 type, u32 index);
    static bool isValidParam(const ParamArray& paramList, u32 type, u32 index);
    static bool callPhaseEvent(cQuestPhaseState* pState, cQuestPhaseEvent* pEvent, const ParamArray& paramList);
    static void callPhaseEventCancel(cQuestPhaseState* pState, cQuestPhaseEvent* pEvent, const ParamArray& paramList);
    static bool phaseEventSetupDividePlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventDicideDividePlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    static void phaseEventCancelDicideDividePlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventDicideDividePlayerEx(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventEnemyAddGoodOcd(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventEnemyResetGoodOcd(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventReturnPlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    static void phaseEventCancelReturnPlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    static bool phaseEventExistDividePlayer(cQuestPhaseState* pState, const ParamArray& paramList);
    const ParamArray& getParamList() const;
    void addParam(u32 type, u32 idx, u32 value);
    u32 getEventId() const;
    cQuestPhaseEvent();
    cQuestPhaseEvent(u32 eventId);
    virtual ~cQuestPhaseEvent();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    ParamArray mParamList;  // offset: 0x8
    u32 mEventId;  // offset: 0x28
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cQuestPhaseEvent::getEventId() const {
    return this->mEventId;
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestPhaseEvent::cQuestPhaseEvent() {
    this->mEventId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestPhaseEvent::cParam::cParam() {
    this->mType = static_cast<u32>(0);
    this->mIdx = static_cast<u32>(0);
    this->mValue = static_cast<u32>(0);
}
