#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpJobBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cBlowShrinkDmInfo;
class cHitInfo;
class cHitInfoAfter;
class uDDOModel;

// Declarations
class cpJob07;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cpJob07 : public cpJobBase
{
public:
    enum
    {
        FURY_LEVEL_0 = 0,
        FURY_LEVEL_1 = 1,
        FURY_LEVEL_2 = 2,
        FURY_LEVEL_NUM = 3,
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
    u8 getFuryLevel_Gi() const;
    void setFuryLevel_Gi(u8 NewValue);
    u8 getOldFuryLevel_Gi() const;
    void setOldFuryLevel_Gi(u8 NewValue);
    f32 getBattleFury_Gi() const;
    void setBattleFury_Gi(f32 NewValue);
    cpJob07();
    virtual ~cpJob07();
    virtual void setup();  // vtable slot 6
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea();  // vtable slot 22
    virtual void init();  // vtable slot 19
    virtual void update();  // vtable slot 16
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackDamage(cHitInfo* pHitLocalInfo);  // vtable slot 33
    virtual void callbackDamageTest(cHitInfo* pHitInfo);  // vtable slot 36
    virtual void callbackCaughtTest(cHitInfo* pHitInfo);  // vtable slot 37
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 38
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 39
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 40
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 41
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 42
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 43
    virtual void callbackDie();  // vtable slot 50
    virtual void callbackHitLand();  // vtable slot 31
    void shlHitCountTutorialFlg();
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 58
    f32 getBattleFury();
    u8 getFuryLevel();
    void payFury(u8 charge);
    void setActiveEndure(bool flg);
    void setCanAttackL(bool flg);
    bool IsCanAttackL() const;
    void setIsChargeJust(bool flg);
    bool IsChargeJust() const;
    void setMemoryChargeLv(s32 lv);
    s32 isMemoryChargeLv() const;
    void initCanDivineCounter();
    bool checkCanDivineCounter() const;
    bool IsEndureSuccess() const;
    void resetIsEndureSuccess();
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 24
    void replaceHitInfo_CUSTOM_12(cHitInfo* pHitInfo);
    void replaceHitInfo_CUSTOM_11(cHitInfo* pHitInfo);
    void replaceHitInfo_CUSTOM_14(cHitInfo* pHitInfo);
    void NoticeAttitudeOfFury();
    bool IsCanAttitudeOfFury();
    f32 getAttitudeOfFuryTimer() const;
    f32 getAttitudeOfFuryTimerMax() const;
    f32 getAttitudeOfFuryIncreaseFuryParam();
    bool checkCndEnableDelayCombo() const;
    bool checkCndIsAttitudeOfFury() const;
    bool checkCndIsSuccessEndure() const;
    bool checkCndCheckAttackS() const;
    bool checkCndCustom14Plus() const;
    void setIsAttackHitDownEnemy(bool flg = false);
    bool isAttackHitDownEnemy();
    void resetFuryGaugerTime();
private:
    void FuryNetProc();
    void FuryDecreaseProc();
    void FuryLevelEffectProc();
private:
    bool mActiveEndure;  // offset: 0x58
    u8 mFuryLevel_Gi;  // offset: 0x59
    u8 mOldFuryLevel_Gi;  // offset: 0x5a
    f32 mBattleFury_Gi;  // offset: 0x5c
    f32 mFuryTimer;  // offset: 0x60
    f32 mDecreaseFury;  // offset: 0x64
public:
    bool mIsEffectActive;  // offset: 0x68
    bool mIsOutLineActive;  // offset: 0x69
    u16 mOutLineCount;  // offset: 0x6a
    bool mIsFuryChargeEffectActive;  // offset: 0x6c
    bool mIsCanAttackL;  // offset: 0x6d
    bool mIsChargeJust;  // offset: 0x6e
    s32 mMemoryChargeLv;  // offset: 0x70
    bool mIsEndureSuccess;  // offset: 0x74
    bool mIsCanAttitudeOfFury;  // offset: 0x75
    f32 mAttitudeOfFuryTimer;  // offset: 0x78
    bool mIsCanDivineCounter;  // offset: 0x7c
    bool mIsAttackHitDownEnemy;  // offset: 0x7d
    static MyDTI DTI;
    static const u16 MAXFURY = 1000;
};

inline void* cpJob07::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u8 cpJob07::getFuryLevel_Gi() const {
    return this->mFuryLevel_Gi;
}

inline f32 cpJob07::getBattleFury_Gi() const {
    return this->mBattleFury_Gi;
}

inline void cpJob07::setBattleFury_Gi(f32 NewValue) {
    this->mBattleFury_Gi = NewValue;
}

inline f32 cpJob07::getBattleFury() {
    return this->mBattleFury_Gi;
}

inline void cpJob07::initCanDivineCounter() {
    this->mIsCanDivineCounter = false;
}

inline void cpJob07::resetIsEndureSuccess() {
    this->mIsEndureSuccess = false;
}

inline void cpJob07::setIsAttackHitDownEnemy(bool flg) {
    this->mIsAttackHitDownEnemy = false;
}
