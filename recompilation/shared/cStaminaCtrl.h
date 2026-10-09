#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOUtility.h"
#include "nStamina.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class cContextPlayerInfo;
class cStaminaDecList;
class uDDOModel;
class uHuman;

// Declarations
class cStaminaCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cStaminaCtrl : public MtObject
{
public:
    enum OVERRIDE_PRIO
    {
        PRIO_MIN = 0,
        PRIO_NORMAL = 1,
        PRIO_MAX = -1,
    };
public:
    class MyDTI;
    struct stOverRideParam;
    struct stProcParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stProcParam
    {
    public:
        stProcParam();
        bool convertFromSequence(uHuman& owner, cStaminaCtrl& stmnCtrl, const cContextPlayerInfo& context, u32 SeqIndex);
        bool convertFromExternalRequest(uHuman& owner, const cStaminaCtrl::stProcParam& procParam, const cContextPlayerInfo& context);
    public:
        f32 mStamina;  // offset: 0x0
        nStamina::VALUE_TYPE mVType;  // offset: 0x4
        nStamina::UPDATE_TYPE mUType;  // offset: 0x8
        nStamina::CONTINUATION_TYPE mCType;  // offset: 0xc
        u32 mStaminaType;  // offset: 0x10
    };
public:
    struct stOverRideParam
    {
    public:
        stOverRideParam();
        void clearRequest();
    public:
        bool mIsRequested;  // offset: 0x0
        cStaminaCtrl::stProcParam mProcParam;  // offset: 0x4
        cStaminaCtrl::OVERRIDE_PRIO mPriority;  // offset: 0x18
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
    cStaminaCtrl();
    virtual ~cStaminaCtrl();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void update(uHuman& owner);
    void requestExternalUpdate(f32 stamina, nStamina::VALUE_TYPE vType, nStamina::UPDATE_TYPE uType, nStamina::CONTINUATION_TYPE cType, u32 staminaType, OVERRIDE_PRIO prio);
    void setSleepDecrease(bool sleep);
    void requestStopRecover();
    f32 getExtRecoveryRate() const;
    void setExtRecoveryRate(f32);
    void addExtRecoveryRate(f32);
    f32 getExtDecreaseRate() const;
    void setExtDecreaseRate(f32 rate);
    void addExtDecreaseRate(f32 rate);
    f32 calcStaminaTemporarily(uHuman& owner, f32 calcStamina, nStamina::VALUE_TYPE vType, nStamina::UPDATE_TYPE uType, nStamina::CONTINUATION_TYPE cType, u32 staminaType);
protected:
    bool decreaseStamina(uHuman& owner, f32& stamina, const stProcParam& procParam, const cContextPlayerInfo& context, f32 decreaseRate);
    bool decreaseStaminaSequence(uHuman& owner, f32& stamina, const stProcParam& procParam, const cContextPlayerInfo& context, f32 decreaseRate);
    bool recoveryStamina(uHuman& owner, f32& stamina, const stProcParam& procParam, const cContextPlayerInfo& context, f32 recoveryRate);
    bool recoveryStaminaSequence(uHuman& owner, f32& stamina, const stProcParam& procParam, const cContextPlayerInfo& context, f32 recoveryRate);
    cStaminaDecList* getStaminaDecList(const uHuman& owner, u32 work);
    bool checkUpdateThroughSequence(uHuman& owner);
    bool checkUpdateThroughReq(uHuman& owner, OVERRIDE_PRIO prio);
    void calcRateFromWeight(uHuman& owner, f32 weight, f32& recoveryRate, f32& decreaseRate);
private:
    void clearRequestParam();
public:
    void setOwner(uDDOModel* pOwner);
    void setJumpSTRecoverSlow();
private:
    nDDOUtility::cArray<stOverRideParam, 16> mRequestFluctuationList;  // offset: 0x8
    u32 mFocusIndex;  // offset: 0x1c8
    bool mSleepDecrease;  // offset: 0x1cc
    bool mSleepRecover;  // offset: 0x1cd
    f32 mJumpRecoverSlowTime;  // offset: 0x1d0
    bool mIsJumpRecoverSlow;  // offset: 0x1d4
    f32 mExtRecoveryRate;  // offset: 0x1d8
    f32 mExtDecreaseRate;  // offset: 0x1dc
    uDDOModel* mpOwner;  // offset: 0x1e0
public:
    static MyDTI DTI;
};
