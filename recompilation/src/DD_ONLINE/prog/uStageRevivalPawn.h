#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEfcHandle;
class uControlNpc;
class uGUISystemMsg;

// Declarations
class uStageRevivalPawn;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uStageRevivalPawn : public cUnit
{
public:
    enum
    {
        R0_WAIT_CREATE_CTRL = 0,
        R0_REVIVAL_LOST_PAWN = 1,
        R0_LOST_PAWN = 2,
        R0_LOST_PAWN_LIST = 3,
        R1_REQUEST_WAIT = 0,
        R1_REVIVE_PAWN_WAIT = 1,
        R1_REVIVE_PAWN = 2,
        R1_NET_ERROR = 3,
        KILL_NPC_WAIT = 0,
        KILL_NPC_REQ_START = 1,
        KILL_NPC_START_WAIT = 2,
        KILL_NPC_FADE_START = 3,
        KILL_NPC_FADE_WAIT = 4,
        KILL_NPC_FADE_FINISH = 5,
        KILL_NPC_EFFECT_FINISH = 6,
        KILL_NPC_FINISH = 7,
        NPC_PAWN1 = 0,
        NPC_PAWN2 = 1,
        NPC_PAWN3 = 2,
        NPC_PAWN4 = 3,
        NPC_PAWN5 = 4,
        NPC_PAWN6 = 5,
        NPC_PAWN7 = 6,
        NPC_PAWN8 = 7,
        NPC_PAWN9 = 8,
        NPC_PAWN10 = 9,
        NPC_BATTLE_PAWN = 10,
        NPC_PAWN_NUM = 11,
        MY_PAWN_NUM = 10,
        PAWN_MOT_SUCCESS_WAIT = 12,
        PAWN_MOT_FAILED_WAIT = 13,
        PAWN_MOT_SUCCESS_GREETING = 15,
        PAWN_MOT_FAILED_GREETING = 16,
        ENEMY_GROUP = 3,
    };
public:
    class MyDTI;
    struct GuardITDataU32;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct GuardITDataU32
    {
    public:
        u32 NpcId;  // offset: 0x0
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
    uStageRevivalPawn();
    virtual ~uStageRevivalPawn();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getRevivalNpcId() const;
    void reqRevivalNpcId(u32 id);
    bool isReviveFinish();
private:
    void getMyPawnInfo();
    void getLostPawnInfo();
    void watchLostPawnNpc();
    void moveRevivalLostPawn();
    void reqKillNpc(u32 index);
    bool isKillNpc(u32 index);
    u32 getSlotMyPawn(u32 pawnId);
    uControlNpc* getCtrlNpc(s32 npcid);
    void setDispNpc(s32 npcid, bool flag);
    u32 getReqRevivalNpcIdPrivate() const;
    void setReqRevivalNpcIdPrivate(u32 NewValue);
    u32 getRevivingNpcIdPrivate() const;
    void setRevivingNpcIdPrivate(u32 NewValue);
    u32 getRevivalNpcIdPrivate() const;
    void setRevivalNpcIdPrivate(u32 NewValue);
private:
    u8 mRno0;  // offset: 0x48
    u8 mRno1;  // offset: 0x49
    u32 mIndex;  // offset: 0x4c
    u32 mLostPawnNum;  // offset: 0x50
    u8 mKillNpc[11];  // offset: 0x54
    u32 mPawnID[11];  // offset: 0x60
    u32 mMyPawnID[10];  // offset: 0x8c
    GuardITDataU32 mReqRevivalNpcId;  // offset: 0xb4
    GuardITDataU32 mRevivingNpcId;  // offset: 0xb8
    bool mIsRevive[11];  // offset: 0xbc
    bool mIsBattlePawn;  // offset: 0xc7
    bool mIsEnemyLifeArea;  // offset: 0xc8
    bool mIsThinkBattle;  // offset: 0xc9
    bool mIsLostPawnInfo;  // offset: 0xca
    bool mIsMyPawnInfo;  // offset: 0xcb
    bool mNoLostPawn;  // offset: 0xcc
    uControlNpc* mpCtrlNpc;  // offset: 0xd0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xd8
    f32 mMesTimer;  // offset: 0xe0
    f32 mWaitTimer;  // offset: 0xe4
    cEfcHandle* mpHandle;  // offset: 0xe8
    cEfcHandle* mpRevHandle[11];  // offset: 0xf0
    GuardITDataU32 mRevivalNpcId;  // offset: 0x148
public:
    static MyDTI DTI;
};
