#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cpJobBase.h"
#include "nCharacterData.h"
#include "nDDOGame.h"
#include "nHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cCollNode;
class cContextInterface;
class cHitInfo;
class cHitInfoAfter;
class cShlNotifyInfo;
class uHuman;
class uShlBase;

// Declarations
class cpJob05;

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

class cpJob05 : public cpJobBase
{
    // inferred: uHuman::checkGuardModeCancel names cpJob05::mGuardModeNoCancelTimer
    friend class uHuman;
public:
    enum CHANGE_ELEMENT_MODE
    {
        CE_MODE_A = 0,
        CE_MODE_B = 1,
    };
    enum eElementGuardShlIndex
    {
        eEGSIndexOffsetLv2 = 12,
        eEGSIndexOffsetJust = 6,
    };
    enum GUARD_COLL_INDEX
    {
        GUARD_COLL_MANUAL_GUARD = 2,
        GUARD_COLL_SAINT_WALL_LV1 = 16,
        GUARD_COLL_SAINT_WALL_LV2 = 17,
    };
public:
    class MyDTI;
    class ForceGaugeInfo;
    class cSaintWallInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class ForceGaugeInfo : public MtObject
    {
        // inferred: cpJob05::setGuardChargeMax names cpJob05::mForceGauge.mGaugeMax_Gi
        friend class cpJob05;
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
        ForceGaugeInfo();
        // Address: 0x01a5b360 - 0x01a5b361 (1 bytes)
        virtual ~ForceGaugeInfo() {}
        void reset();
        f32 getStockSize() const;
        s32 getNowStock() const;
        void setGaugeMax(f32 max);
        void addNowGauge(f32 addValue);
        bool isEmpty() const;
        bool isCompleteChage() const;
        bool isNoStock() const;
    private:
        f32 getGaugeMax_Gi() const;
        void setGaugeMax_Gi(f32 NewValue);
        s32 getStockMax_Gi() const;
        void setStockMax_Gi(s32 NewValue);
        f32 getNowGauge_Gi() const;
        void setNowGauge_Gi(f32 NewValue);
    private:
        f32 mGaugeMax_Gi;  // offset: 0x8
        s32 mStockMax_Gi;  // offset: 0xc
        f32 mNowGauge_Gi;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cSaintWallInfo
    {
    public:
        enum WALL_LEVEL
        {
            WL_1 = 0,
            WL_2 = 1,
        };
    public:
        cSaintWallInfo();
        ~cSaintWallInfo();
        void clear();
    public:
        WALL_LEVEL mLevel;  // offset: 0x0
        bool mIsActive;  // offset: 0x4
        bool mIsDefense;  // offset: 0x5
        f32 mTimer;  // offset: 0x8
        bool mIsGuardEff;  // offset: 0xc
        bool mIsGuardLoopEff;  // offset: 0xd
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
    cpJob05();
    virtual ~cpJob05();
    virtual void setup();  // vtable slot 6
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void after();  // vtable slot 18
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void init();  // vtable slot 19
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea();  // vtable slot 22
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 26
    virtual void callbackGuard_make(cHitInfo* pHitInfo);  // vtable slot 27
    virtual void callbackGuard_calc(cHitInfo* pHitInfo);  // vtable slot 28
    virtual void callbackGuardEffect(cHitInfo* pHitInfo);  // vtable slot 29
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 38
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    virtual void callbackAttackTest_ShlNotify(cHitInfo* pHitInfo);  // vtable slot 35
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo);  // vtable slot 49
    void chargeGuardGageCalc(cHitInfo* pHitInfo);
    virtual void callbackOcdSeal();  // vtable slot 51
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 57
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 58
    bool isGuardMode() const;
private:
    void setElementType(f32 angle);
    void readContext(cContextInterface& Con);
    void writeContext(cContextInterface& Con);
    void updateElementOutline();
    void updateGuardInfo();
    void updateSaintWall();
    bool callSaintWallLoopEffect(u64 syncFlag, u32 ElementNo);
    void checkGCAction();
    bool isJustGuard() const;
public:
    void setTmpElementType(nDDOGame::ELEMENT_TYPE type);
    bool changeElement(CHANGE_ELEMENT_MODE mode);
    nDDOGame::ELEMENT_TYPE getEnchantType();
    bool isElementGuard() const;
    bool isElementChangeAction() const;
    nHuman::HM_SKILL_LV getElementChangeLV() const;
    nDDOGame::ELEMENT_TYPE getElementType() const;
    nDDOGame::ELEMENT_TYPE getTmpElementType() const;
    void resetTmpElementType();
    void resetGuardCharge();
    f32 getGuardCharge() const;
    s32 getGuardChargeStock() const;
    s32 getGuardChargeStockMax() const;
    f32 getGuardChargeMax() const;
    void setGuardChargeMax(f32 max);
    bool isCompleteGuardCharge() const;
    f32 getGuardStockSize() const;
    bool isGuardChargeEmpty() const;
    bool checkGuardCharge() const;
    void addGuardCharge(f32 add, bool isNoEff);
    void subGuardChargeStockSize(f32 stockNum);
    void subGuardChage(f32 sub);
    bool isButtonNagaoshi(u32 inputType) const;
    bool isEnableElementChange() const;
    virtual void callbackEquipJob(nCharacterData::EQUIP_SLOT_TYPE category);  // vtable slot 53
    void calcEquipParam();
    bool checkSkillLevel(s32 ActNo, nHuman::HM_SKILL_LV skillLv) const;
    void setupSaintWall(nHuman::HM_SKILL_LV SkillLv, f32 Timer);
    bool isSaintWall() const;
    bool cheakSequence(uHuman& human, u32 bit, u32 seqPage, u32& work);
    void setHateAttackMinimumMoveTime(f32 time);
    bool isCanHateAttackEnd();
    void setGuardModeNoCancelTimer(f32 time);
    bool isGuardModeCancelEnable() const;
    void setTransActTimer(f32 timer);
    f32 getTransActTimer() const;
    bool isCanStunShieldCounter() const;
    void clearCanStunShieldCounter();
    bool isForceAnchorSuccess() const;
    void clearForceAnchorSuccess();
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 24
    void reqestSe_CS08_12_Init(nHuman::CUSTOM_SKILL_ENUM skillID);
    void reqestSe_CS08_12_Loop();
private:
    void checkSe_CS08_12();
    void endSe_CS08_12();
public:
    bool isCanAttackCS13() const;
    bool isCS13AdvAttack() const;
    bool isCS13BtnReleased(const bool check_trg);
    bool isCS13UseSpCamera() const;
    void setCanAttackCS13(bool flg);
    void setCS13AdjAttack(bool flg);
    void setCS13UseSpCamera(bool flg);
    void storeLightShl(uShlBase* pShl);
    uShlBase* getLightShl() const;
    void clearLightShl();
private:
    virtual void callbackCSChange();  // vtable slot 54
private:
    nDDOGame::ELEMENT_TYPE mEnchantType;  // offset: 0x58
    nDDOGame::ELEMENT_TYPE mEnchantTypeOld;  // offset: 0x5c
    nDDOGame::ELEMENT_TYPE mTmpEnchantType;  // offset: 0x60
    bool mIsElementGuardEff;  // offset: 0x64
    bool mIsElementChangeAction;  // offset: 0x65
    ForceGaugeInfo mForceGauge;  // offset: 0x68
    f32 mSlowRate;  // offset: 0x80
    f32 mSlowTime;  // offset: 0x84
    f32 mTransActTime;  // offset: 0x88
    f32 mElemChangeInterval;  // offset: 0x8c
    f32 mRightUpButtonTimer;  // offset: 0x90
    f32 mRBButtonTimer;  // offset: 0x94
    bool mIsElementalGuard;  // offset: 0x98
    cSaintWallInfo mSaintWallInfo;  // offset: 0x9c
    f32 mHateAttackMinimumMoveTimer;  // offset: 0xac
    bool mIsGuardMode;  // offset: 0xb0
    f32 mJustGuardTimer;  // offset: 0xb4
    f32 mGuardModeNoCancelTimer;  // offset: 0xb8
    f32 mTransActTimer;  // offset: 0xbc
    f32 mOutlineTimer;  // offset: 0xc0
    bool mIsCanStunShieldCounter;  // offset: 0xc4
    bool mIsForceAnchorSuccess;  // offset: 0xc5
    u32 mTargetUID_CS08_12;  // offset: 0xc8
    bool mIsCallSeInit;  // offset: 0xcc
    bool mIsCallSeLoop;  // offset: 0xcd
    nHuman::CUSTOM_SKILL_ENUM mCallSeCustomId;  // offset: 0xd0
    bool mFlgCanAttackCS13;  // offset: 0xd4
    bool mFlgCS13AdvAttack;  // offset: 0xd5
    bool mIsGuardImpactMode;  // offset: 0xd6
    bool mIsUseSpCamera;  // offset: 0xd7
    uShlBase* mpShlLight;  // offset: 0xd8
public:
    static MyDTI DTI;
private:
    static const u32 INVALID_TARGET_ID_CS08 = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cPawnActInterActElementChange::updateInter at 0x43ede9-0x43edef; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it; 1 of its copies unread: a parameter in memory or a frame slot at the entry (026 plan-P80, ruling D-C4), so approximate at most
inline void cpJob05::setTmpElementType(nDDOGame::ELEMENT_TYPE type) {
    this->mTmpEnchantType = type;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it; 4 of its copies unread: a parameter in memory or a frame slot at the entry (026 plan-P80, ruling D-C4), so approximate at most
inline nDDOGame::ELEMENT_TYPE cpJob05::getElementType() const {
    return this->mEnchantType;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cStateJob05ElementChange::move at 0x57df1e-0x57df25; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cpJob05::resetTmpElementType() {
    this->mTmpEnchantType = static_cast<nDDOGame::ELEMENT_TYPE>(1);
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it
inline void cpJob05::setGuardChargeMax(f32 max) {
    this->mForceGauge.mGaugeMax_Gi = max;
    this->mForceGauge.mStockMax_Gi = static_cast<int>(max / 1000.0f);
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cStateJob05Provoke::init at 0x57e584-0x57e58c; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cpJob05::setHateAttackMinimumMoveTime(f32 time) {
    this->mHateAttackMinimumMoveTimer = time;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cJob05Custom10::init at 0x2ad7dd-0x2ad7e4; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cpJob05::clearCanStunShieldCounter() {
    this->mIsCanStunShieldCounter = false;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cJob05LightBase_Loop::init at 0x2a96d8-0x2a96df; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cpJob05::storeLightShl(uShlBase* pShl) {
    this->mpShlLight = pShl;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cJob05LightBase_Loop::move at 0x2aa022-0x2aa029; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline uShlBase* cpJob05::getLightShl() const {
    return this->mpShlLight;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in cJob05LightBase_Loop::final at 0x2aa45c-0x2aa467; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cpJob05::clearLightShl() {
    this->mpShlLight = nullptr;
}

// Inline, no code of its own: checked where it is inlined.
inline cpJob05::ForceGaugeInfo::ForceGaugeInfo() {
    this->mGaugeMax_Gi = 0.0f;
    this->mStockMax_Gi = 0;
    this->mNowGauge_Gi = 0.0f;
}
