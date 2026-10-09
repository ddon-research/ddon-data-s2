#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nCastUtility.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "nHumanBow.h"
#include "nJobParam.h"
#include "sUnitManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cAreaHit;
class cContextInstHm;
class cOcdStatusParamRes;
namespace nHumanBow { class cBowActParam; }
namespace nJobParam { class cJobInfo; }
class rAdjustParam;
class rBowActParamList;
class rOcdStatusParamRes;
class rPrologueHmStatus;
class sEffectExt;
class sOmManager;
class uBaseModel;
class uDDOModel;
class uHuman;
class uPlayer;

// Declarations
class sPlayerManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sPlayerManager : public sUnitManager
{
    // inferred: cAreaHit::move names sPlayerManager::mpInstance
    friend class cAreaHit;
    // inferred: sEffectExt::getZoneCheckPos names sPlayerManager::mpInstance
    friend class sEffectExt;
    // inferred: sOmManager::isCreatableUnit names sPlayerManager::mpMyPlayer
    friend class sOmManager;
public:
    enum
    {
        PL_LOAD_STATUS_NONE = 0,
        PL_LOAD_STATUS_INIT = 1,
        PL_LOAD_STATUS_BAKE_RELEASE_WAIT = 2,
        PL_LOAD_STATUS_LOAD_WAIT = 3,
        PL_LOAD_STATUS_LOAD_WAIT2 = 4,
        PL_LOAD_STATUS_LOAD_DONE = 5,
    };
    enum
    {
        CHECK_PW_CHG_AREA_NONE = 0,
        CHECK_PW_CHG_AREA_RECOVER = 1,
        CHECK_PW_CHG_AREA_LOST = 2,
        CHECK_PW_CHG_AREA_NUM = 3,
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
    sPlayerManager();
    virtual ~sPlayerManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    virtual void clear();  // vtable slot 11
    virtual void reset();  // vtable slot 6
    void initGame();
    virtual void releaseUnit(uBaseModel* p);  // vtable slot 13
    virtual void releaseUnit(u32 uniqId);  // vtable slot 14
    static sPlayerManager* getInstance();
    estUnitType<uDDOModel, void> createUnit(u32 unique_id, u32 unit_id, bool isPawn);
    uHuman* getPlayerParty(s32 memberIndex);
    uHuman* getPlayer(const cContextInstHm* pCtx);
    uHuman* getPlayerCharacterId(u32 characterId, u32 pawnId);
    cContextInstHm* getContext(uHuman* pPl);
    void playerSyncLoad();
    static void playerSyncLoadCoreSub(cContextInstHm* pContext);
    virtual void returnTicket(u32 uniqId);  // vtable slot 17
    uPlayer* getMyPlayer() const;
    void registerMyPlayer(uPlayer* pPl);
    void setWeakeningTimer(f32 time);
    f32 getWeakeningTimer();
    void updateWeakeningTimer();
    void updateCalcStatus();
    void loadResource();
    void releaseResource();
    u32 getWarpCheatCntHm() const;
    void setWarpCheatCntHm(u32 NewValue);
    u32 getWarpCheatCntEm() const;
    void setWarpCheatCntEm(u32 NewValue);
    void setIsLobbyJoin(bool flg);
    bool isLobbyJoin() const;
    void setIsCheckHpMaxOver(bool flg);
    bool isCheckHpMaxOver() const;
    void onOnsenFlag(uHuman* pHm, nHuman::ONSEN_TYPE onsenType);
    bool isOnsenTime(nHuman::ONSEN_TYPE onsenType, uHuman* pHm) const;
    bool isOnsenTimeMyPlayer(nHuman::ONSEN_TYPE onsenType) const;
    void resetOnsenFlag();
    u32 getPlWartLength() const;
    u32 getEmWartLength() const;
    const nHumanBow::cBowActParam* getBowActParam(nHumanBow::BOW_ACT_KIND kind, u32 index) const;
    void createBowActParamList(nHumanBow::BOW_ACT_KIND kind);
private:
    void updatePawn();
public:
    uHuman* getMyPawn(u32& cur, u32 pawnType);
    void updatePawnFarLost();
    void updatePawnLobbyHeal();
    bool isPawnFarLost(const cContextInstHm* pInst);
    void callbackPawnChangeArea(bool isLobby);
    void callbackPawnChangeAreaRecoverOcd(bool isLobby);
    void callbackPawnChangeAreaLost(bool isLobby);
    u32 checkPawnChangeAreaState(const cContextInstHm* pInst, bool isLobby);
    void applyPrologueStatus();
    void recoveryPrologueStatus();
    void createPrologueHmStatus();
    void releasePrologueHmStatus();
    void callBackArrowUseReq(void* param);
    void callBackItemThrowCheck(void* param);
    void callBackItemThrowUseReq(void* param);
    u32 getAbility227Hp() const;
    f32 getHpAbilityHighBorder() const;
    f32 getStaminaAbilityHighBorder() const;
    f32 getWeightMax() const;
    f32 getHumanAdjustParam(u32 index) const;
    bool isEnableNewBattleFlow() const;
    const cOcdStatusParamRes* getOcdStatusParamRes(u32 OcdUID) const;
    bool isItemSeal(const uHuman* pHuman) const;
    bool isItemSealMyPlayer() const;
    void callbackDeadEnemy();
    void registCSLoadWait(const u32 char_id);
private:
    void updateCSLoadWait();
    void initCSLoadWait();
private:
    uPlayer* mpMyPlayer;  // offset: 0xa0
    bool mIsLobbyJoin;  // offset: 0xa8
    bool mIsCheckHpMaxOver;  // offset: 0xa9
    f32 mWeakeningTimer;  // offset: 0xac
    u32 mIsOnsenTime[2][4];  // offset: 0xb0
    u32 mWarpCheatCntHm;  // offset: 0xd0
    u32 mWarpCheatCntEm;  // offset: 0xd4
public:
    f32 mSendInterval;  // offset: 0xd8
    u32 mPlWarpLength;  // offset: 0xdc
    u32 mEmWarpLength;  // offset: 0xe0
    nDDOUtility::cArray<rBowActParamList*, 2> mprActBowParamList;  // offset: 0xe8
private:
    nJobParam::cJobInfo mPrologueBackUpJobInfo;  // offset: 0xf8
    u32 mPrologueBackUpCustomSkill[2];  // offset: 0x168
    rPrologueHmStatus* mprPrologueHmStatus;  // offset: 0x170
    rAdjustParam* mprHumanAdjustParam;  // offset: 0x178
    rOcdStatusParamRes* mprHumanStatusParam;  // offset: 0x180
    rAdjustParam* mprNewBattleFlow;  // offset: 0x188
    u32 mLoadWaitCharId[8];  // offset: 0x190
    static sPlayerManager* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sPlayerManager* sPlayerManager::getInstance() {
    return ::sPlayerManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline uPlayer* sPlayerManager::getMyPlayer() const {
    return this->mpMyPlayer;
}
