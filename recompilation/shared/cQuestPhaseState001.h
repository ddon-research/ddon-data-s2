#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cQuestPhaseState.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cQuestPhaseState001;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseState001 : public cQuestPhaseState
{
public:
    enum QUEST_PHASE_STATE_001_PARAM
    {
        RETURN_PLAYER_NUM = 3,
        ENEMY_GCD_MAX = 3,
    };
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
    void setWarpPlayerStageNoStartPos(u32 stageNo, u32 startPosNo);
    void getWarpPlayerStageNoStartPos(u32& stageNo, u32& startPos) const;
    void resetWarpPlayerStageNoStartPos();
    void setWarpPlayerId(u32 id);
    u32 getWarpPlayerId() const;
    void resetWarpPlayerId();
    void setAddEnemyGcd();
    void resetAddEnemyGcd();
    u32 getLevelEnemyGcd() const;
    void setReturnPlayerId(u32 plId1, u32 plId2, u32 plId3);
    void returnPlayer(u32 characterId);
    u32 getReturnPlayerId(u32 index) const;
    void resetReturnPlayerId();
    bool isReturnPlayer(u32 characterId) const;
    void setDivideSetup(bool isSetup);
    bool isDivideSetup() const;
    void setWarpPlayer(bool isWarp);
    bool isWarpPlayer() const;
    void setDivideSuccess(bool isSuccess);
    bool isDivideSuccess() const;
    bool isDivideProcess() const;
    bool isReturnPlayer() const;
    bool isDispAnnounce() const;
    bool isExistDividePlayer() const;
    void setExistDividePlayer(bool isExist);
    bool hasRequestedWarpPlayer();
    void requestWarpPlayer();
    cQuestPhaseState001();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    u32 mDivideStageNo;  // offset: 0x8
    u32 mDivideStartPosNo;  // offset: 0xc
    u32 mPlayerId;  // offset: 0x10
    u32 mReturnPlayerId[3];  // offset: 0x14
    u32 mEnemyParamGcd;  // offset: 0x20
    bool mIsDivideSetup;  // offset: 0x24
    bool mIsWarpPlayer;  // offset: 0x25
    bool mIsDivideSuccess;  // offset: 0x26
    bool mIsReturnPlayer;  // offset: 0x27
    bool mIsDispAnnounce;  // offset: 0x28
    bool mExistDividePlayer;  // offset: 0x29
    bool mHasRequestedWarpPlayer;  // offset: 0x2a
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cQuestPhaseState001::cQuestPhaseState001() {
    this->mHasRequestedWarpPlayer = false;
    this->mIsDispAnnounce = false;
    this->mExistDividePlayer = false;
    this->mEnemyParamGcd = static_cast<u32>(0);
    this->mIsDivideSetup = false;
    this->mIsWarpPlayer = false;
    this->mIsDivideSuccess = false;
    this->mIsReturnPlayer = false;
    this->mReturnPlayerId[1] = static_cast<unsigned int>(0);
    this->mReturnPlayerId[2] = static_cast<unsigned int>(0);
    this->mPlayerId = static_cast<u32>(0);
    this->mReturnPlayerId[0] = static_cast<unsigned int>(0);
    this->mDivideStageNo = static_cast<u32>(0);
    this->mDivideStartPosNo = static_cast<u32>(0);
}
