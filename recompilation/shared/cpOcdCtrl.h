#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cEffectCycleCtrl.h"
#include "cOcdCache.h"
#include "cOcdInfo.h"
#include "cOcdMsgCtrl2.h"
#include "cpComponent.h"
#include "nAction.h"
#include "nDDOShader.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cCyclePartReqInfo;
class cEffectCycleCtrl;
class cHitInfo;
class cHitInfoAfter;
class cOcdBase;
class cOcdCache;
class cOcdCustomReqInfo;
class cOcdImmuneParam;
class cOcdImmuneParamRes;
class cOcdInfo;
class cOcdMsgCtrl2;
class cOcdStatusParam;
class cOcdStatusParamRes;
class cShlConditionInfo;
class cUnitDieInfo;
class cpShakeCtrl;
class rOcdElectricParam;
class rOcdImmuneParamRes;
class rOcdStatusParamRes;
class uDDOModel;

// Declarations
class cpOcdCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cOcdActiveReqArray = nDDOUtility::cArray<nDDOUtility::cArray<bool, 32>, 7>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpOcdCtrl : public cpComponent
{
    // inferred: cpShakeCtrl::shake names cpOcdCtrl::mOcdActiveBit[1]
    friend class cpShakeCtrl;
public:
    enum OCD_EFFECT_CATEGORY
    {
        EFFECT_CATEGORY_INVALID = 0,
        EFFECT_CATEGORY_INIT = 1,
        EFFECT_CATEGORY_REST = 1,
        EFFECT_CATEGORY_BOTTOM = 2,
        EFFECT_CATEGORY_D = 2,
        EFFECT_CATEGORY_C = 3,
        EFFECT_CATEGORY_B = 4,
        EFFECT_CATEGORY_A = 5,
        EFFECT_CATEGORY_NUM = 6,
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
    cpOcdCtrl();
    virtual ~cpOcdCtrl();
    virtual void setup();  // vtable slot 6
    void before();
    void update();
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void kill();  // vtable slot 8
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void callbackDie(cUnitDieInfo& dieInfo);
    void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);
    void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);
    void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);
    void addOcdDamage(u32 OcdUID, f32 damage, nObjCondition::OCD_REASON reason, f32 cacheTime);
    void callbackApplyDamageVisual(cHitInfoAfter* pHitInfo);
    void callbackHitShlCondition_Catch(u32 OcdUID, const cShlConditionInfo* pInfo);
    void callbackAltitudeFall();
    void callbackAltitudeFallLand();
    void callbackSetCaught();
    void callbackChecked_Give(cHitInfoAfter* pHitInfo);
    void callbackChecked_Cure(cHitInfoAfter* pHitInfo);
    void callbackChecked(cHitInfo* pHitInfo);
    uDDOModel* getDDOModel() const;
    void setOcdList(u32 bank, cOcdInfo* pList, u32 length);
    void setStatusCommonParamRes(rOcdStatusParamRes* pRes);
    const cOcdStatusParamRes* getOcdStatusParamResData(u32 OcdUID);
    void setStatusParamRes(rOcdStatusParamRes* pRes);
    void setImmuneParamRes(rOcdImmuneParamRes* pRes);
    rOcdImmuneParamRes* getImmuneParamRes();
    const cOcdImmuneParamRes* getImmuneParamResData(u32 OcdUID);
    bool isInvalidOcdID(u32 OcdUID) const;
    bool isInvalidBankIndex(u32 bank, u32 index) const;
    MtTypedArray<cOcdInfo>& getOcdList(u32 bank);
    cOcdBase* getObjCondition(u32 OcdUID);
    u32 getMainReaction();
    u32 getFallReaction();
    void setWarpReactionStartTiming();
    void setInvalid(bool flag);
    bool isInvalid() const;
private:
    void setupStatusParam();
    void calcOcdDamage(cHitInfoAfter* pHitInfo);
    f32 calcOcdIrAdj(cHitInfoAfter* pHitInfo) const;
    f32 calcOcdFinalAdj(cHitInfoAfter* pHitInfo) const;
    void applyOcdDamage(cHitInfoAfter* pHitInfo);
    void checkAnnihilation(cOcdInfo* pOcdInfo);
    void checkTimerEndNextOcd(cOcdInfo* pOcdInfo);
    cOcdInfo* getOcdInfo(u32 OcdUID) const;
    void checkReqestOcdMode(cOcdInfo* pOcdInfo);
    nObjCondition::OCD_MODE_REQ_RESULT checkOcdInit(const cOcdInfo* pOcdInfo);
    nObjCondition::OCD_MODE_REQ_RESULT checkOcdFinal(const cOcdInfo* pOcdInfo, bool time_end);
    nObjCondition::OCD_MODE_REQ_RESULT checkOcdMultiInit(const cOcdInfo* pOcdInfo);
    bool isReqActionInit(const cOcdInfo* pOcdInfo);
    bool isReqActionEnd(const cOcdInfo* pOcdInfo);
    void applyReqResult(cOcdInfo* pOcdInfo, bool isCallFunction);
    void callInit(cOcdInfo* pOcdInfo, bool initFlag);
    void callFinal(cOcdInfo* pOcdInfo);
    void callMulti(cOcdInfo* pOcdInfo, bool initFlag);
    void reqOcdActionInit(cOcdInfo* pOcdInfo, bool initFlag);
    void reqOcdActionEnd(cOcdInfo* pOcdInfo);
    void checkOcdRequest(bool isCallFunction);
public:
    void reqOcdApply(u32 OcdUID, nObjCondition::OCD_REASON reason, f32 cacheTime, u32 option, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);
    void reqOcdApplyForce(u32 OcdUID, nObjCondition::OCD_REASON reason, f32 cacheTime);
    void reqOcdApplyCustom(u32 OcdUID, const cOcdCustomReqInfo& reqInfo, nObjCondition::OCD_REASON reason, f32 cacheTime, s32 priority);
    void reqOcdCure(u32 OcdUID);
    void reqOcdCureForce(u32 OcdUID);
    void reqOcdChargeClear(u32 OcdUID);
    bool isOcdActive(u32 OcdUID) const;
    bool isOcdActiveOld(u32 OcdUID) const;
    bool isOcdApplyAble(u32 OcdUID);
    bool isOcdEndAble(u32 OcdUID);
    bool isOcdAlreadyRequest(u32 OcdUID);
    void resetActiveTimer(u32 OcdUID);
    cOcdStatusParam* getStatusParam(u32 OcdUID);
    const cOcdStatusParam* getStatusParamOriginal(u32 OcdUID);
    cOcdImmuneParam* getImmuneParam(u32 OcdUID);
    f32 getOcdFreeParam(u32 OcdUID, u32 index);
    void setOcdSystemFlag(u32 flag);
    void addOcdSystemFlag(u32 flag);
    void removeOcdSystemFlag(u32 flag);
    bool isOcdSystemFlagActive(nObjCondition::OCD_SYSTEM_FLAG flag) const;
    void cancelOcdReqest();
    void cancelOcdReqest(u32 OcdUID);
    void callOcdEffect_Init(u32 OcdUID);
    void callOcdEffect_End(u32 OcdUID);
    bool isRecoverEnd() const;
    bool isUseSleepChangeTime() const;
    bool isCallKill() const;
    void notifyReceiveMsg(bool recvFlag);
private:
    void callInit(u32 OcdUID, bool initFlag);
    void callFinal(u32 OcdUID);
    void callMulti(u32 OcdUID, bool initFlag);
    void callbackReceiveActive(u32 OcdUID, bool initFlag, bool isAction);
    u32 checkResetActOcd(const cOcdActiveReqArray& activeArray) const;
public:
    void setOcdElectricRes(rOcdElectricParam* pResOcdElec);
    rOcdElectricParam* getOcdElectricRes() const;
private:
    void checkHolyAbsorpVisual(cHitInfoAfter* pHitInfo);
public:
    void registOcdShader(nDDOShader::SHADER_MODE_ENUM shaderType, u32 priority, s32 lv);
    bool checkOcdDamageCache(const cOcdCache& newChach);
    void clearOcdDamageCache(nObjCondition::OCD_REASON reason);
private:
    OCD_EFFECT_CATEGORY getOcdEffectCategory(u32 OcdUID) const;
    s32 getOcdEffectCategory(OCD_EFFECT_CATEGORY category) const;
    void setupOcdCycleEffect();
    void updateOcdCycleEffect();
    void callOcdShader();
    void resetOcdShaderInfo();
    s32 getOcdSeOffset() const;
    s32 getCenterJointNo() const;
    void updateOcdActiveBit();
public:
    void notifyMoveFreeze();
private:
    void checkBadOcdEndEffect();
    void checkMoveFreeze();
    void clearMoveFreeze();
    void checkCheckOcd();
public:
    u32 getOcdActiveBit(u32 bank) const;
    u32 getOcdActiveNum(u32 bank) const;
    f32 getOcdEndurance(u32 OcdUID);
    f32 getOcdEnduranceMax(u32 OcdUID);
    f32 getOcdAccumulation(u32 OcdUID);
    bool isOCDapplyContinue();
private:
    MtTypedArray<cOcdInfo> mOcdList[7];  // offset: 0x50
    u32 mMainActionNo;  // offset: 0x130
    nAction::ACT_PRIO mMainActPriority;  // offset: 0x134
    u8 mReactionStartTiming;  // offset: 0x138
    u8 mTimerStartTiming;  // offset: 0x139
    uDDOModel* mpModel;  // offset: 0x140
    rOcdStatusParamRes* mpOcdStatusCommonParamRes;  // offset: 0x148
    rOcdStatusParamRes* mpOcdStatusParamRes;  // offset: 0x150
    rOcdImmuneParamRes* mpOcdImmuneParamRes;  // offset: 0x158
    u32 mOcdSystemFlag;  // offset: 0x160
    bool mIsInvalid;  // offset: 0x164
    bool mIsCallKill;  // offset: 0x165
    cOcdMsgCtrl2 mOcdMsgCtrl2;  // offset: 0x168
    rOcdElectricParam* mpOcdElectricParam;  // offset: 0x348
    nDDOUtility::cArray<cCyclePartReqInfo, 6> mCycleEffectReqInfo;  // offset: 0x350
    cEffectCycleCtrl mEffectCycleCtrl;  // offset: 0x470
    nDDOShader::SHADER_MODE_ENUM mOcdShaderType;  // offset: 0x4a8
    u32 mShaderPriority;  // offset: 0x4ac
    s32 mOcdShaderLv;  // offset: 0x4b0
    nDDOUtility::cArray<cOcdCache, 3> mOcdDamageCacheArray;  // offset: 0x4b8
    u32 mOcdActiveBit[7];  // offset: 0x500
    u32 mOcdActiveBitOld[7];  // offset: 0x51c
    bool mIsMoveFreeze;  // offset: 0x538
    bool mIsMoveFreezeOld;  // offset: 0x539
    bool mIsOCDapplyContinue;  // offset: 0x53a
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpOcdCtrl::isInvalid() const {
    return this->mIsInvalid;
}
