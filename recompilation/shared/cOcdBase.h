#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cEfcHandle.h"
#include "cOcdCache.h"
#include "cOcdParamRes.h"
#include "nAbility.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nObjCondition.h"
#include "nOcdMsg.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cEfcHandle;
class cHitInfoAfter;
class cOcdCache;
class cOcdCustomReqInfo;
class cOcdImmuneParamRes;
class cOcdInfo;
class cOcdPriorityParam;
class cOcdStatusParamRes;
class cShlConditionInfo;
class cpOcdCtrl;
class uDDOModel;

// Declarations
class cOcdBase;
class cOcdImmuneParam;
class cOcdStatusParam;

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

class cOcdImmuneParam : public MtObject
{
    // inferred: cOcdBase::applyCustomRequest names cOcdBase::mImmuneParam.mImmuneLv
    friend class cOcdBase;
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
    cOcdImmuneParam();
    // Address: 0x01a43920 - 0x01a43921 (1 bytes)
    virtual ~cOcdImmuneParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setImmuneParamFromRes(const cOcdImmuneParamRes* pImmuneRes);
    void resetImmuneParam();
    f32 getImmuneRate() const;
    u32 getImmuneLv() const;
    u32 getImmuneLvMax() const;
    void setImmuneRate(f32);
    void setImmuneLv(u32 lv);
    void setImmuneLvMax(u32 lvMax);
private:
    f32 mImmuneRate;  // offset: 0x8
    u32 mImmuneLv;  // offset: 0xc
    u32 mImmuneLvMax;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cOcdStatusParam : public MtObject
{
    // inferred: cOcdBase::isEffective names cOcdBase::mStatusParam.mIsEffective
    friend class cOcdBase;
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
    cOcdStatusParam();
    // Address: 0x01a43930 - 0x01a43931 (1 bytes)
    virtual ~cOcdStatusParam() {}
    void setParamFromRes(const cOcdStatusParamRes* pStatusRes);
    void resetParam();
    void resetCureParam();
    void resetActiveTime();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isEffective() const;
    f32 getEndurance() const;
    f32 getEnduranceMax() const;
    f32 getAccumulationValue() const;
    bool isTimeRecover() const;
    f32 getActiveTime() const;
    f32 getActiveTimeMax() const;
    f32 getCureWaitTime() const;
    f32 getCureWaitTimeMax() const;
    f32 getCureValue() const;
    f32 getFreeParam0() const;
    f32 getFreeParam1() const;
    bool isMultiApply() const;
    bool isMultiNumLimit() const;
    u32 getMultiApplyNum() const;
    u32 getMultiApplyNumMax() const;
    void setEndurance(f32 endurance);
    void setEnduranceMax(f32 EnduranceMax);
    void setAccumulationValue(f32 value);
    void setIsTimeRecover(bool);
    void setActiveTime(f32 ActiveTime);
    void setActiveTimeMax(f32 ActiveTimeMax);
    void setCureWaitTime(f32 time);
    void setCureWaitTimeMax(f32);
    void setCureValue(f32 CureValue);
    void setFreeParam0(f32 FreeParam0);
    void setFreeParam1(f32 FreeParam1);
    void setIsMultiApply(bool);
    void setIsMultiNumLimit(bool);
    void setMultiApplyNum(u32 multiNum);
    void setSystemParamFromRes(const cOcdPriorityParam* pData);
    void decreaseMultiApplyNum();
    f32 getEnduranceCheatCheck() const;
    f32 getEnduranceMaxCheatCheck() const;
    f32 getActiveTimeCheatCheck() const;
    f32 getActiveTimeMaxCheatCheck() const;
    f32 getCureValueCheatCheck() const;
    f32 getFreeParam0CheatCheck() const;
    f32 getFreeParam1CheatCheck() const;
private:
    void setEnduranceCheatCheck(f32 value);
    void setEnduranceMaxCheatCheck(f32 value);
    void setActiveTimeCheatCheck(f32 value);
    void setActiveTimeMaxCheatCheck(f32 value);
    void setCureValueCheatCheck(f32 value);
    void setFreeParam0CheatCheck(f32 value);
    void setFreeParam1CheatCheck(f32 value);
    f32 getEndurancePrivate() const;
    void setEndurancePrivate(f32 NewValue);
    f32 getEnduranceMaxPrivate() const;
    void setEnduranceMaxPrivate(f32 NewValue);
    f32 getActiveTimePrivate() const;
    void setActiveTimePrivate(f32 NewValue);
    f32 getActiveTimeMaxPrivate() const;
    void setActiveTimeMaxPrivate(f32 NewValue);
    f32 getCureValuePrivate() const;
    void setCureValuePrivate(f32 NewValue);
    f32 getFreeParam0Private() const;
    void setFreeParam0Private(f32 NewValue);
    f32 getFreeParam1Private() const;
    void setFreeParam1Private(f32 NewValue);
    f32 getEnduranceCheatCheckPrivate() const;
    void setEnduranceCheatCheckPrivate(f32 NewValue);
    f32 getEnduranceMaxCheatCheckPrivate() const;
    void setEnduranceMaxCheatCheckPrivate(f32 NewValue);
    f32 getActiveTimeCheatCheckPrivate() const;
    void setActiveTimeCheatCheckPrivate(f32 NewValue);
    f32 getActiveTimeMaxCheatCheckPrivate() const;
    void setActiveTimeMaxCheatCheckPrivate(f32 NewValue);
    f32 getCureValueCheatCheckPrivate() const;
    void setCureValueCheatCheckPrivate(f32 NewValue);
    f32 getFreeParam0CheatCheckPrivate() const;
    void setFreeParam0CheatCheckPrivate(f32 NewValue);
    f32 getFreeParam1CheatCheckPrivate() const;
    void setFreeParam1CheatCheckPrivate(f32 NewValue);
private:
    bool mIsEffective;  // offset: 0x8
    f32 mEndurance;  // offset: 0xc
    f32 mEnduranceMax;  // offset: 0x10
    f32 mAccumulationValue;  // offset: 0x14
    bool mIsTimeRecover;  // offset: 0x18
    f32 mActiveTime;  // offset: 0x1c
    f32 mActiveTimeMax;  // offset: 0x20
    f32 mCureWaitTime;  // offset: 0x24
    f32 mCureWaitTimeMax;  // offset: 0x28
    f32 mCureValue;  // offset: 0x2c
    f32 mFreeParam0;  // offset: 0x30
    f32 mFreeParam1;  // offset: 0x34
    bool mIsMultiApply;  // offset: 0x38
    bool mIsMultiNumLimit;  // offset: 0x39
    u32 mMultiApplyNum;  // offset: 0x3c
    u32 mMultiApplyNumMax;  // offset: 0x40
    f32 mEnduranceCheatCheck;  // offset: 0x44
    f32 mEnduranceMaxCheatCheck;  // offset: 0x48
    f32 mActiveTimeCheatCheck;  // offset: 0x4c
    f32 mActiveTimeMaxCheatCheck;  // offset: 0x50
    f32 mCureValueCheatCheck;  // offset: 0x54
    f32 mFreeParam0CheatCheck;  // offset: 0x58
    f32 mFreeParam1CheatCheck;  // offset: 0x5c
public:
    static MyDTI DTI;
};

class cOcdBase : public MtObject
{
public:
    enum OCD_CURE_MODE
    {
        OCD_CURE_WAIT = 0,
        OCD_CURE_MOVE = 1,
        OCD_CURE_NONE = 2,
    };
public:
    class MyDTI;
public:
    using cOcdBadNonDamageList = nDDOUtility::cArray<bool, 31>;
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
    cOcdBase();
    virtual ~cOcdBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 7
    virtual void updateEfcHandle();  // vtable slot 8
    virtual void init(bool initFlag);  // vtable slot 9
    virtual void move();  // vtable slot 10
    virtual void final();  // vtable slot 11
    virtual void multiInit(bool initFlag);  // vtable slot 12
    virtual void resetParam();  // vtable slot 13
    virtual void update();  // vtable slot 14
    virtual bool isEnableInit() const;  // vtable slot 15
    virtual bool isEnableMove() const;  // vtable slot 16
    virtual bool isEnableFinal() const;  // vtable slot 17
    virtual bool isEnableMoveAfter() const;  // vtable slot 18
    virtual bool isEnableMultiInit() const;  // vtable slot 19
    virtual bool isEnableEndAction() const;  // vtable slot 20
    bool isEffective() const;
    void setStatusParamRes(const cOcdStatusParamRes& data);
    void setImuuneParamRes(const cOcdImmuneParamRes& data);
    void applyImmuneNormal(u32 immuneLv);
    void applyImmuneBoost(u32 immuneLv);
    void setOcdActiveCache(const cOcdCache& cache);
    const cOcdCache& getOcdActiveCache() const;
    virtual void callbackDamage(cHitInfoAfter* pHitInfo);  // vtable slot 21
    // Address: 0x01a42b10 - 0x01a42b11 (1 bytes)
    virtual void callbackDamage_make(cHitInfoAfter* pHitInfo) {}  // vtable slot 22
    virtual void addOcdDamage(f32 damage, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isAddAccumulation, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);  // vtable slot 23
    virtual void callbackHitShlCondition_Catch(const cShlConditionInfo* pShlInfo);  // vtable slot 24
    // Address: 0x01a42b20 - 0x01a42b21 (1 bytes)
    virtual void callbackAltitudeFall() {}  // vtable slot 25
    // Address: 0x01a42b30 - 0x01a42b31 (1 bytes)
    virtual void callbackAltitudeFallLand() {}  // vtable slot 26
    // Address: 0x01a428a0 - 0x01a428a1 (1 bytes)
    virtual void callbackSetCaught() {}  // vtable slot 27
    void resetActiveTimer();
    cOcdStatusParam* getOcdStatusParam();
    const cOcdStatusParam* getOcdStatusParamOriginal();
    const cOcdStatusParamRes* getOcdStatusParamRes();
    cOcdImmuneParam* getOcdImmuneParam();
    void setNonInifOST(u64);
    void addNonInifOST(u64 OST);
    void setRequreInifOST(u64);
    void addRequreInifOST(u64);
    void checkCheatOcd();
protected:
    void checkCheatOcdCore(const f32 value, const f32 valueCheck, const f32 checkDiff);
    bool isActive() const;
    void requestCure(u32 OcdUID);
    void reqChangeOcdMode(nObjCondition::OCD_REQ_MODE mode, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);
    void setupImmune();
    virtual void applyCustomRequest(const cOcdCustomReqInfo& info);  // vtable slot 28
    virtual void applyCustomRequestMulti(const cOcdCustomReqInfo& info);  // vtable slot 29
    bool isCustomRequest() const;
    nObjCondition::OCD_IMMUNE_MODE getImmuneMode() const;
    void setActiveTimerRateByAbility(nAbility::ABILITY_ID AbilityId);
    void setActiveTimerRate(f32 rate);
    f32 getActiveTimerRate() const;
    void clearActiveTimerRate();
private:
    void reCalcEnduranceMax();
    void checkEnduranceCure();
    void updateActiveTimer();
    void enduranceReset();
public:
    void callOcdEffectInit();
    void callOcdEffectFinal();
protected:
    bool isEffetCallNone() const;
    void callOcdDamageOutLineSe(u32 OcdUID);
    void registOcdShader(u32 OcdUID);
    void requestOcdSeInit(u32 OcdUID);
    s32 getOcdInitSeReqNo(u32 OcdUID) const;
    void requestOcdSeEnd(u32 OcdUID);
    s32 getOcdEndSeReqNo(u32 OcdUID) const;
    s32 getOcdSeOffset() const;
    s32 getCenterJointNo() const;
    void setOcdReqParam(const cOcdCache& cache);
    void clearOcdReqParam();
    const cOcdCache& getOcdReqParam() const;
public:
    void addOcdBadNonDamageList(nObjCondition::OCD_BAD_TYPE type);
    bool isOcdBadNonDamageEnable();
protected:
    cOcdStatusParamRes mStatusParamRes;  // offset: 0x8
    cOcdStatusParam mStatusParam;  // offset: 0x48
    cOcdStatusParam mStatusParamOrignal;  // offset: 0xa8
    cOcdImmuneParam mImmuneParam;  // offset: 0x108
    bool mIsEndReaction;  // offset: 0x120
    nObjCondition::OCD_IMMUNE_MODE mImmuneMode;  // offset: 0x124
    u64 mNonInitOST;  // offset: 0x128
    u64 mRequreOST;  // offset: 0x130
    u32 mOcdUID;  // offset: 0x138
    cpOcdCtrl* mpOcdCtrl;  // offset: 0x140
    uDDOModel* mpModel;  // offset: 0x148
    cOcdInfo* mpOwner;  // offset: 0x150
private:
    f32 mActiveTimerRate;  // offset: 0x158
    cOcdCache mOcdActiveCache;  // offset: 0x160
    OCD_CURE_MODE mCureMode;  // offset: 0x178
protected:
    MtTypedArray<cEfcHandle> mEfcHandle;  // offset: 0x180
    bool mFlgCallInitFinishlEffect;  // offset: 0x1a0
    cOcdCache mOcdReqParam;  // offset: 0x1a8
private:
    cOcdBadNonDamageList mOcdBadNonDamageList;  // offset: 0x1c0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cOcdImmuneParam::cOcdImmuneParam() {
    this->mImmuneRate = 1.0f;
    this->mImmuneLv = static_cast<u32>(0);
    this->mImmuneLvMax = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cOcdStatusParam::cOcdStatusParam() {
    this->mIsEffective = false;
    this->mEndurance = 1000.0f;
    this->mEnduranceCheatCheck = 1000.0f;
    this->mEnduranceMax = 1000.0f;
    this->mEnduranceMaxCheatCheck = 1000.0f;
    this->mAccumulationValue = 0.0f;
    this->mIsTimeRecover = true;
    this->mActiveTime = 120.0f;
    this->mActiveTimeMax = 120.0f;
    this->mActiveTimeCheatCheck = 120.0f;
    this->mActiveTimeMaxCheatCheck = 120.0f;
    this->mCureWaitTime = 5.0f;
    this->mCureWaitTimeMax = 5.0f;
    this->mCureValue = 0.5f;
    this->mCureValueCheatCheck = 0.5f;
    this->mFreeParam0CheatCheck = 0.0f;
    this->mFreeParam1CheatCheck = 0.0f;
    this->mIsMultiApply = false;
    this->mIsMultiNumLimit = false;
    this->mFreeParam0 = 0.0f;
    this->mFreeParam1 = 0.0f;
    this->mMultiApplyNum = static_cast<u32>(4);
    this->mMultiApplyNumMax = static_cast<u32>(4);
}

// Inline, no code of its own: checked where it is inlined.
inline bool cOcdStatusParam::isMultiApply() const {
    return this->mIsMultiApply;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParam::getActiveTimeMaxPrivate() const {
    return this->mActiveTimeMax;
}
