#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
class cQuestPhaseState;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseState : public MtObject
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
    static void setWarpPlayerStageNoStartPos(cQuestPhaseState* pState, u32 stageNo, u32 startPosNo);
    static void getWarpPlayerStageNoStartPos(cQuestPhaseState* pState, u32& stageNo, u32& startPosNo);
    static void setWarpPlayerId(cQuestPhaseState* pState, u32 playerId);
    static void setDivideCharacterId(cQuestPhaseState* pState, u32 characterId, u32 index);
    static void resetWarpPlayerId(cQuestPhaseState* pState);
    static u32 getWarpPlayerId(cQuestPhaseState* pState);
    static bool isDividePlayer(cQuestPhaseState* pState, u32 characterId);
    static void setAddEnemyGcd(cQuestPhaseState* pState);
    static void resetAddEnemyGcd(cQuestPhaseState* pState);
    static u32 getLevelEnemyGcd(cQuestPhaseState* pState);
    static void setReturnPlayerId(cQuestPhaseState* pState, u32 pId1, u32 pId2, u32 pId3);
    static void resetReturnPlayerId(cQuestPhaseState* pState);
    static bool isReturnPlayer(cQuestPhaseState* pState, u32 characterId);
    static bool isDispAnnounce(cQuestPhaseState* pState);
    static void returnPlayer(cQuestPhaseState* pState, u32 characterId);
    static void setDivideSetup(cQuestPhaseState* pState);
    static void resetDivideSetup(cQuestPhaseState* pState);
    static bool isDivideSetup(cQuestPhaseState* pState);
    static void setWarpPlayer(cQuestPhaseState* pState);
    static void resetWarpPlayer(cQuestPhaseState* pState);
    static bool isWarpPlayer(cQuestPhaseState* pState);
    static void setDivideSuccess(cQuestPhaseState* pState, u32 characterId, bool isSuccess);
    static bool isDivideSuccess(cQuestPhaseState* pState);
    static bool isDivideProcess(cQuestPhaseState* pState);
    static bool isReturnPlayer(cQuestPhaseState* pState);
    static void setExistDividePlayer(cQuestPhaseState* pState, bool isExist);
    static bool isExistDividePlayer(cQuestPhaseState* pState);
    static bool hasRequestedWarpPlayer(cQuestPhaseState* pState, u32 characterId);
    static void requestWarpPlayer(cQuestPhaseState* pState, u32 characterId);
    static bool isFinishedEnemyDivideAction(cQuestPhaseState* pState);
    static void finishEnemyDivideAction(cQuestPhaseState* pState);
    static void callbackLeaveParty(cQuestPhaseState* pState, u32 characterId);
    virtual u32 getType() const;  // vtable slot 6
    cQuestPhaseState();
    virtual ~cQuestPhaseState();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    static MyDTI DTI;
};
