#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cHumanActBow.h"
#include "cpJobBase.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtVector3;
class cEfcHandle;
class cHitInfo;
class cHitInfoAfter;
class rSoundRequest;
class uAimCheck;
class uJobEquip;
class uShlBase;

// Declarations
class cpJob03;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJob03 : public cpJobBase
{
public:
    enum CHANGE_REASON
    {
        REASON_NONE = 0,
        REASON_NORMAL = 1,
        REASON_RESET = 2,
        REASON_REJECT = 3,
    };
    enum
    {
        RELOAD_TYPE_NONE = 0,
        RELOAD_TYPE_NORMAL = 1,
        RELOAD_TYPE_ACTIVE = 2,
        RELOAD_TYPE_JUST = 3,
        RELOAD_TYPE_FAILED = 4,
    };
public:
    class MyDTI;
    class uLineCtrlUnit;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class uLineCtrlUnit : public uDDOModel
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
        uLineCtrlUnit();
        virtual ~uLineCtrlUnit();
        virtual void kill();  // vtable slot 16
        virtual void updateMatrix();  // vtable slot 71
    public:
        MtVector3 mLinePos[2];  // offset: 0x2470
        MtMatrix mLinePosMat[2];  // offset: 0x2490
        cEfcHandle* mpEfcHandle;  // offset: 0x2510
        bool mIsCalcUpdateWorldMatrix;  // offset: 0x2518
        static MyDTI DTI;
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
    cpJob03();
    virtual ~cpJob03();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void before();  // vtable slot 15
    virtual void callbackUpdateAfter();  // vtable slot 17
    virtual void after();  // vtable slot 18
    virtual void reset();  // vtable slot 20
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea();  // vtable slot 22
    virtual void setupCustomData(u32 csId, u32 index);  // vtable slot 23
    virtual void callbackCreateShl(uShlBase* pShl);  // vtable slot 52
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 45
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 39
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    virtual void callbackEquipJob(nCharacterData::EQUIP_SLOT_TYPE category);  // vtable slot 53
    virtual void callbackOcdSeal();  // vtable slot 51
    CHANGE_REASON getChangeReason() const;
    u32 getArrowNum() const;
    void setArrowNum(u32 NewValue);
    u32 getArrowNumMax() const;
    void setArrowNumMax(u32 NewValue);
    void setChangeReson(CHANGE_REASON reason);
    void shotArrow(u32 num);
    void reloadBegin();
    void reloadMove();
    void reloadEnd();
    bool isReloadEnd() const;
    bool isJustShot();
    void setIsJustShot(bool flag);
    void changeArrowType();
    void setArrowEquipType(u32 type);
    u32 getArrowEquipType();
    u32 getArrowType(u32 uId);
    void setShotArrowType(u32 type);
    u32 getShotArrowType() const;
    u32 getReloadType();
    f32 getReloadTime();
    f32 getReloadTimeMax();
    f32 getActiveReloadTime();
    f32 getActiveReloadLast();
    f32 getJustReloadTime();
    bool isReloadCheck();
    void requestMoveSpline();
    bool isMoveSpline();
    bool isEnableUpShot() const;
    void setKeepAdjustSpecialArrow(u32 arrowType);
    f32 getBlurreAcc() const;
    const MtVector3& getShotUpShotPos() const;
    const MtVector3& getShotUpTargetPos() const;
    rSoundRequest* getShlCstmSe(u32 index);
    rSoundRequest* getShlCommonSe();
    f32 getPawnRange() const;
    void setPawnRange(f32 range);
    f32 getRangeSpeed();
    f32 getRangeMax() const;
    f32 getRangeMin() const;
    bool isUpShotLandHit() const;
    void setAimCheckUnit(uAimCheck* pAim);
    uAimCheck* getAimCheckUnit();
    static u32 convArrowTypeFromId(u32 id);
    static u32 getArrowId(u32 arrowType);
    bool isActiveReloadTime() const;
    bool isJustReloadTime() const;
    void setCriticalRangeData(f32 len, f32 nearlen, f32 farlen);
    f32 getTargetLength() const;
    f32 getCriticalNear() const;
    f32 getCriticalFar() const;
    void setAccurate(f32 rate);
    f32 getAccurate() const;
    MtVector3 getShotUpVecXZ() const;
    void setReserveCustomSkill(cPlActWpnBow::SKILL_TYPE type);
    cPlActWpnBow::SKILL_TYPE getReserveCustomSkill() const;
    void setCs05Eff(bool isEnable, f32 rate);
    void useSpecialArrow(u32 useNum);
    void setCS14BowStance(bool flg);
    void clearCS14RendaInfo();
    void updateCS14RendaInfo(bool renda_start, bool turn_start, u32 lv, u32 count, f32 timer);
    bool getCS14StartRenda() const;
    bool getCS14StartTurn() const;
    u32 getCS14RendaLv() const;
    u32 getCS14RendaCount() const;
    f32 getCS14RendaRemainTime() const;
    void setCS14BeforeChargeLv(u32 lv);
private:
    void calcShotSpline();
    void calcSplineNode(f32 range, const MtVector3& targetVec);
    void calcTargetLine(const MtVector3& base, MtVector3& target);
    virtual void callbackCSChange();  // vtable slot 54
public:
    uJobEquip* mpArrowMod;  // offset: 0x58
private:
    u32 mArrowNum_Gi;  // offset: 0x60
    u32 mArrowNumMax_Gi;  // offset: 0x64
public:
    u32 mArrowEquipType;  // offset: 0x68
    u32 mArrowType;  // offset: 0x6c
    u32 mShotArrowType;  // offset: 0x70
    u32 mReloadType;  // offset: 0x74
    f32 mReloadTime;  // offset: 0x78
    f32 mReloadTimeMax;  // offset: 0x7c
    f32 mActiveReloadTime;  // offset: 0x80
    f32 mActiveReloadLast;  // offset: 0x84
    f32 mJustReloadTime;  // offset: 0x88
    f32 mCs05EffRate;  // offset: 0x8c
    bool mIsReloadCheck;  // offset: 0x90
    bool mIsReloadEnd;  // offset: 0x91
    bool mIsJustShot;  // offset: 0x92
    bool mIsMoveSpline;  // offset: 0x93
    bool mIsLandHit;  // offset: 0x94
    bool mIsCs05Eff;  // offset: 0x95
    bool mIsHitFallHit;  // offset: 0x96
    bool mMoveSplineWait;  // offset: 0x97
    bool mIsArrowNoneEff;  // offset: 0x98
    bool mIsUpShotCalcEnd;  // offset: 0x99
    nDDOUtility::cRNSpline<8> mSpline;  // offset: 0xa0
    f32 mRangeMin;  // offset: 0x240
    f32 mRangeDefault;  // offset: 0x244
    f32 mRangeMax;  // offset: 0x248
    f32 mRangeNow;  // offset: 0x24c
    f32 mRangePawn;  // offset: 0x250
    f32 mRangeSpeed;  // offset: 0x254
    f32 mBlurreAcc;  // offset: 0x258
    f32 mBlurreRad;  // offset: 0x25c
    MtVector3 mShotUpTopPos;  // offset: 0x260
    MtVector3 mShotUpUnderPos;  // offset: 0x270
    MtVector3 mShotUpBasePos;  // offset: 0x280
    MtVector3 mShotUpTargetPos;  // offset: 0x290
    MtVector3 mShotUpShotPos;  // offset: 0x2a0
    MtVector3 mShotUpVecXZ;  // offset: 0x2b0
    f32 mTargetLength;  // offset: 0x2c0
    f32 mCriticalNear;  // offset: 0x2c4
    f32 mCriticalFar;  // offset: 0x2c8
    f32 mAccurate;  // offset: 0x2cc
    cPlActWpnBow::SKILL_TYPE mReserveCustomSkill;  // offset: 0x2d0
    uLineCtrlUnit* mpLandEfcUnit;  // offset: 0x2d8
    uLineCtrlUnit* mpLandHitEfcUnit;  // offset: 0x2e0
    uLineCtrlUnit* mpCs05EfcUnit;  // offset: 0x2e8
    nDDOUtility::cArray<rSoundRequest*, 4> mpCstmSkillShlSeList;  // offset: 0x2f0
    rSoundRequest* mpShlCommonSe;  // offset: 0x310
    uAimCheck* mpAimCheck;  // offset: 0x318
    cEfcHandle* mpEfcBakuretsu;  // offset: 0x320
    CHANGE_REASON mChangeReason;  // offset: 0x328
private:
    bool mCS14BowStance;  // offset: 0x32c
    bool mCS14StartRenda;  // offset: 0x32d
    bool mCS14StartTurn;  // offset: 0x32e
    u32 mCS14RendaLv;  // offset: 0x330
    u32 mCS14RendaCount;  // offset: 0x334
    f32 mCS14RendaRemainTime;  // offset: 0x338
    u32 mCS14BeforeChargeLv;  // offset: 0x33c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cpJob03::getArrowNum() const {
    return this->mArrowNum_Gi;
}

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* cpJob03::getShlCommonSe() {
    return this->mpShlCommonSe;
}
