#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cQuestPhaseComponent.h"
#include "cQuestPhaseState.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cQuestPhaseCpDivide;

// Declarations
class cQuestPhaseState002;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseState002 : public cQuestPhaseState
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
    virtual u32 getType() const;  // vtable slot 6
    void getDivideStage(u32& stageNo, u32& startPosNo) const;
    void setDivideStage(u32 stageNo, u32 startPosNo);
    bool isDivideSetup() const;
    void setDivideSetup(bool isSetup);
    u32 getDivideCharacterId(u32 index) const;
    bool isDividePlayer(u32 characterId) const;
    void setDivideCharacterId(u32 characterId, u32 index);
    bool isReturnPlayer() const;
    bool isReturnPlayer(u32 characterId) const;
    u32 getReturnCharacterId(u32 index) const;
    void setReturnCharacterId(u32 characterId, u32 index);
    bool isNoReturnPlayer() const;
    void returnPlayer(u32 characterId);
    bool isDividePlayer() const;
    void dividePlayer(u32 characterId);
    bool hasSucceededDivide() const;
    bool hasSucceededDivide(u32 characterId) const;
    bool existsDividePlayer() const;
    void setExistDividePlayer(bool exists);
    bool hasRequestedWarpPlayer(u32 characterId);
    void requestWarpPlayer(u32 characterId);
    bool isFinishedEnemyAction() const;
    void finishEnemyAction();
    void callbackLeaveParty(u32 characterId);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    cQuestPhaseCpDivide mDivideComponent;  // offset: 0x8
public:
    static MyDTI DTI;
};
