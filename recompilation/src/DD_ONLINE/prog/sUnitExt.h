#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../XFramework/sUnit.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cUnit;
class uCharacterEdit;
class uCharacterEditBase;
class uDDOModel;

// Declarations
class sUnitExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sUnitExt : public sUnit
{
    friend class uCharacterEdit;
    friend class uCharacterEditBase;
public:
    enum eMoveLine
    {
        ML_PREPROCESS = 0,
        ML_SCHEDULER = 1,
        ML_SCHEDULER_SUB = 2,
        ML_FILTER = 3,
        ML_SCR = 4,
        ML_SCR_SUB = 5,
        ML_CTRL = 6,
        ML_OBJ_BIG_EM = 7,
        ML_OBJ_BIG_EM_SUB1 = 8,
        ML_PLAYER = 9,
        ML_NPC_AI = 10,
        ML_EM_NPC = 11,
        ML_EM2 = 12,
        ML_ALL_SUB1 = 13,
        ML_ALL_SUB2 = 14,
        ML_ID_CAM_SOUND = 15,
        ML_ID_SUB_EFF_CTRL = 16,
        ML_UI_PMNT = 17,
        ML_UI_AREA1 = 18,
        ML_UI_AREA2 = 19,
        ML_UI_AREA3 = 20,
        ML_EFFECT = 21,
        ML_EFFECT_SUB = 22,
        ML_LIGHT = 23,
        ML_FADE = 24,
        ML_FADE_SCHEDULER = 25,
        ML_FADE_FILTER = 26,
        ML_POSTPROCESS = 27,
        ML_UI_AREA4 = 28,
        ML_NUM = 29,
        ML_NPC = 11,
        ML_SHELL = 13,
        ML_SOUND_GENERATOR = 15,
        ML_INTEL = 10,
        ML_OBJ = 7,
        ML_OBJ_SUB1 = 8,
        ML_OBJ_SUB2 = 8,
        ML_PLAYER_SUB1 = 13,
        ML_PLAYER_SUB2 = 14,
        ML_CMC = 9,
        ML_CMC_SUB1 = 13,
        ML_CMC_SUB2 = 14,
        ML_ENEMY = 11,
        ML_ENEMY_SUB1 = 13,
        ML_ENEMY_SUB2 = 14,
        ML_OBJ2 = 13,
        ML_OBJ2_SUB1 = 14,
        ML_OBJ2_SUB2 = 14,
        ML_CAMERA = 15,
        ML_EFFECT_CTRL = 28,
        ML_NO_ORDER = 127,
    };
    enum
    {
        UG_PREPROCESS = 16,
        UG_SCHEDULER = 17,
        UG_SCHEDULER_SUB = 18,
        UG_FILTER = 19,
        UG_SCR = 20,
        UG_SCR_SUB = 21,
        UG_OBJ = 22,
        UG_OBJ_SUB1 = 23,
        UG_OBJ_SUB2 = 24,
        UG_PLAYER = 25,
        UG_PLAYER_SUB1 = 26,
        UG_PLAYER_SUB2 = 27,
        UG_CMC = 28,
        UG_CMC_SUB1 = 29,
        UG_NPC = 30,
        UG_ENEMY = 31,
        UG_ENEMY_SUB1 = 32,
        UG_ENEMY_SUB2 = 33,
        UG_OBJ2 = 34,
        UG_OBJ2_SUB1 = 35,
        UG_OBJ2_SUB2 = 36,
        UG_CAMERA = 37,
        UG_EFFECT_CTRL = 38,
        UG_EFFECT = 39,
        UG_EFFECT_SUB = 40,
        UG_LIGHT = 41,
        UG_UI_MAIN = 42,
        UG_UI_SUB = 43,
        UG_UNUSED1 = 44,
        UG_UNUSED2 = 45,
        UG_UNUSED3 = 46,
        UG_UNUSED4 = 47,
        UG_UNUSED5 = 48,
        UG_FADE = 49,
        UG_FADE_SCHEDULER = 50,
        UG_FADE_FILTER = 51,
        UG_POSTPROCESS = 52,
        UG_SHELL1 = 53,
        UG_SHELL2 = 54,
        UG_STOP_EVENT = 55,
        UG_EFFECT_UNIT = 56,
        UG_PAUSE = 57,
        UG_STAGE_SETUP_WAIT = 58,
        UG_STOP_FSM_EVENT = 59,
        UG_PAUSE_SYSTEM = 60,
        DEFAULT_GROUP_COUNT_EXT = 61,
        UG_SOUND_GENERATOR = 49,
        UG_SHELL = 34,
    };
public:
    class MyDTI;
    class cCommandCacheResetFromUsageDifference;
public:
    using TRAVERSE_CALLBACK_FUNC = void(MtObject::*)(cUnit&, void*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCommandCacheResetFromUsageDifference
    {
    public:
        cCommandCacheResetFromUsageDifference();
        ~cCommandCacheResetFromUsageDifference();
        void init();
        void move();
    private:
        void updateCommandCacheNum();
    private:
        f32 mInterval;  // offset: 0x0
        u32 mUseNum;  // offset: 0x4
        u32 mMaxNum;  // offset: 0x8
    public:
        static const u32 CACHE_RESET_DIFFERENCE_NUM;
        static const f32 CACHE_RESET_INTERVAL_FRAME;
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
    sUnitExt(u32 line_num, u32 group_num);
    virtual ~sUnitExt();
    virtual void move();  // vtable slot 7
    virtual void move(MOVE_LINE n);  // vtable slot 14
    virtual MT_CTSTR getLineName(MOVE_LINE n);  // vtable slot 12
    virtual MT_CTSTR getGroupName(u32 group);  // vtable slot 20
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void unitAllUpdatePtr();
    void unitAllUpdatePtrSingle();
    void traverseUnit(MtObject* pCallbackFunctionOwner, TRAVERSE_CALLBACK_FUNC pCallbackFunction, void* pUserData, const MtDTI& TargetDTI, bool IsCheckParentDTI, bool IsLock, s32 TargetMoveLine);
protected:
    virtual void evAddUnit(cUnit& unit);  // vtable slot 22
    virtual void evRemoveUnit(cUnit& unit);  // vtable slot 23
public:
    bool getCommandCacheFlag();
    void setCommandCacheFlag(bool set);
    virtual void forceFlushDrawCommandCache();  // vtable slot 18
    virtual void setForceFlushDrawCommandCacheCount(u32 set);  // vtable slot 19
    virtual u32 getMoveLineId(u32 index);  // vtable slot 24
    virtual u32 getNextMoveLineId(u32 lineId);  // vtable slot 25
    virtual u32 getPrevMoveLineId(u32 lineId);  // vtable slot 26
    virtual u32 getLastMoveLineId();  // vtable slot 27
    virtual u32 getMoveLineOrder(u32 lineId);  // vtable slot 28
private:
    bool mIsEffectHandleFastMode;  // offset: 0x372d90
    MtTypedArray<uDDOModel> mDDOModelArray;  // offset: 0x372d98
    bool mIsUseCommandCache;  // offset: 0x372db8
    s32 mForceFlushDrawCommandCacheCountDown;  // offset: 0x372dbc
    u32 mMoveLineOrderSearchTbl[29];  // offset: 0x372dc0
    cCommandCacheResetFromUsageDifference mCCRFUD;  // offset: 0x372e34
public:
    static MyDTI DTI;
    static const u64 GROUP_NONE = 0;
    static const u64 SYSTEM_GROUP_0 = 1;
    static const u64 SYSTEM_GROUP_1 = 2;
    static const u64 SYSTEM_GROUP_2 = 4;
    static const u64 SYSTEM_GROUP_3 = 8;
    static const u64 SYSTEM_GROUP_4 = 16;
    static const u64 SYSTEM_GROUP_5 = 32;
    static const u64 SYSTEM_GROUP_6 = 64;
    static const u64 SYSTEM_GROUP_7 = 128;
    static const u64 SYSTEM_GROUP_8 = 256;
    static const u64 SYSTEM_GROUP_9 = 512;
    static const u64 SYSTEM_GROUP_10 = 1024;
    static const u64 SYSTEM_GROUP_11 = 2048;
    static const u64 SYSTEM_GROUP_12 = 4096;
    static const u64 SYSTEM_GROUP_13 = 8192;
    static const u64 SYSTEM_GROUP_14 = 16384;
    static const u64 SYSTEM_GROUP_15 = 32768;
    static const u64 GROUP_PREPROCESS = 65536;
    static const u64 GROUP_SCHEDULER = 131072;
    static const u64 GROUP_SCHEDULER_SUB = 262144;
    static const u64 GROUP_FILTER = 524288;
    static const u64 GROUP_SCR = 1048576;
    static const u64 GROUP_SCR_SUB = 2097152;
    static const u64 GROUP_OBJ = 4194304;
    static const u64 GROUP_OBJ_SUB1 = 8388608;
    static const u64 GROUP_OBJ_SUB2 = 16777216;
    static const u64 GROUP_PLAYER = 33554432;
    static const u64 GROUP_PLAYER_SUB1 = 67108864;
    static const u64 GROUP_PLAYER_SUB2 = 134217728;
    static const u64 GROUP_CMC = 268435456;
    static const u64 GROUP_CMC_SUB1 = 536870912;
    static const u64 GROUP_NPC = 1073741824;
    static const u64 GROUP_ENEMY = 2147483648;
    static const u64 GROUP_ENEMY_SUB1 = 4294967296;
    static const u64 GROUP_ENEMY_SUB2 = 8589934592;
    static const u64 GROUP_OBJ2 = 17179869184;
    static const u64 GROUP_OBJ2_SUB1 = 34359738368;
    static const u64 GROUP_OBJ2_SUB2 = 68719476736;
    static const u64 GROUP_CAMERA = 137438953472;
    static const u64 GROUP_EFFECT_CTRL = 274877906944;
    static const u64 GROUP_EFFECT = 549755813888;
    static const u64 GROUP_EFFECT_SUB = 1099511627776;
    static const u64 GROUP_LIGHT = 2199023255552;
    static const u64 GROUP_UI_MAIN = 4398046511104;
    static const u64 GROUP_UI_SUB = 8796093022208;
    static const u64 GROUP_UI_UNUSED1 = 17592186044416;
    static const u64 GROUP_UI_UNUSED2 = 35184372088832;
    static const u64 GROUP_UI_UNUSED3 = 70368744177664;
    static const u64 GROUP_UI_UNUSED4 = 140737488355328;
    static const u64 GROUP_UI_UNUSED5 = 281474976710656;
    static const u64 GROUP_FADE = 562949953421312;
    static const u64 GROUP_FADE_SCHEDULER = 1125899906842624;
    static const u64 GROUP_FADE_FILTER = 2251799813685248;
    static const u64 GROUP_POSTPROCESS = 4503599627370496;
    static const u64 GROUP_SHELL1 = 9007199254740992;
    static const u64 GROUP_SHELL2 = 18014398509481984;
    static const u64 GROUP_STOP_EVENT = 36028797018963968;
    static const u64 GROUP_EFFECT_UNIT = 72057594037927936;
    static const u64 GROUP_PAUSE = 144115188075855872;
    static const u64 GROUP_STAGE_SETUP_WAIT = 288230376151711744;
    static const u64 GROUP_STOP_FSM_EVENT = 576460752303423488;
    static const u64 GROUP_PAUSE_SYSTEM = 1152921504606846976;
    static const u64 GPT_PREPROCESS;
    static const u64 GPT_SCHEDULER;
    static const u64 GPT_SCHEDULER_SUB;
    static const u64 GPT_FILTER;
    static const u64 GPT_SCR;
    static const u64 GPT_SCR_SUB;
    static const u64 GPT_OBJ;
    static const u64 GPT_OBJ_SUB1;
    static const u64 GPT_OBJ_SUB2;
    static const u64 GPT_PLAYER;
    static const u64 GPT_PLAYER_SUB1;
    static const u64 GPT_PLAYER_SUB2;
    static const u64 GPT_CMC;
    static const u64 GPT_CMC_SUB1;
    static const u64 GPT_NPC;
    static const u64 GPT_ENEMY;
    static const u64 GPT_ENEMY_SUB1;
    static const u64 GPT_ENEMY_SUB2;
    static const u64 GPT_OBJ2;
    static const u64 GPT_OBJ2_SUB1;
    static const u64 GPT_OBJ2_SUB2;
    static const u64 GPT_CAMERA;
    static const u64 GPT_EFFECT_CTRL;
    static const u64 GPT_EFFECT;
    static const u64 GPT_EFFECT_NOPAUSE;
    static const u64 GPT_EFFECT_SUB;
    static const u64 GPT_LIGHT;
    static const u64 GPT_LIGHT_NOPAUSE;
    static const u64 GPT_UI_MAIN;
    static const u64 GPT_UI_SUB;
    static const u64 GPT_UI_NOSTOP;
    static const u64 GPT_FADE;
    static const u64 GPT_FADE_SCHEDULER;
    static const u64 GPT_FADE_FILTER;
    static const u64 GPT_POSTPROCESS;
    static const u64 GPT_SOUND;
    static const u64 GPT_SHELL1;
    static const u64 GPT_SHELL2;
    static const u64 GPT_SUB_ALL1;
    static const u64 GPT_SUB_ALL2;
    static const u64 GPT_ID_SYSTEM;
private:
    static const u32 mMoveLineOrderTbl[];
};

inline void* sUnitExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool sUnitExt::getCommandCacheFlag() {
    return this->mIsUseCommandCache;
}

inline void sUnitExt::setCommandCacheFlag(bool set) {
    this->mIsUseCommandCache = set;
    this->::sUnit::mbDrawCommandCacheEnableUpdate = set;
}

inline sUnitExt::cCommandCacheResetFromUsageDifference::~cCommandCacheResetFromUsageDifference() {
}
