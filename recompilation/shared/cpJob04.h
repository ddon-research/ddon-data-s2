#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cpJobBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;
class cOcdInfo;
class uBaseModel;
class uDDOModel;
class uShlBase;

// Declarations
class cpJob04;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpJob04 : public cpJobBase
{
public:
    enum CUSTOM_WORK_NORMAL_CURCLE_TYPE
    {
        CUSTOM_WORK_NORMAL_NONE = 0,
        CUSTOM_WORK_NORMAL_HEAL = 2,
        CUSTOM_WORK_NORMAL_SAINT = 4,
    };
    enum CUSTOM_WORK_CUSTOM_CURCLE_TYPE
    {
        CUSTOM_WORK_CUSTOM_NONE = 0,
        CUSTOM_WORK_CUSTOM_ATTACK = 2,
        CUSTOM_WORK_CUSTOM_DEFENCE = 4,
        CUSTOM_WORK_CUSTOM_IRON = 8,
        CUSTOM_WORK_CUSTOM_SOLACE = 16,
    };
    enum
    {
        FIELD_TYPE_ATTACK = 1,
        FIELD_TYPE_DEFENCE = 2,
        FIELD_TYPE_HEAL = 4,
        FIELD_TYPE_SOUL = 8,
        FIELD_TYPE_IRON = 16,
        FIELD_TYPE_SAINT = 32,
        FIELD_TYPE_SOLACE = 64,
        FIELD_TYPE_BLAST = 128,
    };
    enum
    {
        NORMAL_CIRCLE_INDEX = 0,
        NORMAL_CIRCLE_HEAL = 0,
        NORMAL_CIRCLE_SAINT = 1,
        NORMAL_CIRCLE_NUM = 2,
        CUSTOM_CIRCLE_INDEX = 2,
        CUSTOM_CIRCLE_ATTACK = 2,
        CUSTOM_CIRCLE_DEFENCE = 3,
        CUSTOM_CIRCLE_IRON = 4,
        CUSTOM_CIRCLE_SOLACE = 5,
        CUSTOM_CIRCLE_NUM = 6,
        ALL_CIRCLE_NUM = 6,
    };
    enum
    {
        GUARD_BIT_01 = 1,
        GUARD_BIT_02 = 2,
        GUARD_BIT_03 = 4,
        GUARD_BIT_04 = 8,
        GUARD_BIT_05 = 16,
    };
public:
    class MyDTI;
    struct stCircleAction;
public:
    using CIRCLE_PARAM = cpJob04::stCircleAction;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCircleAction
    {
    public:
        u32 SkillID;  // offset: 0x0
        u32 FieldBit;  // offset: 0x4
        u32 DeleteBit;  // offset: 0x8
        u32 BeginAct;  // offset: 0xc
        u32 ShotAct;  // offset: 0x10
        u32 EndAct;  // offset: 0x14
        u32 EndAirAct;  // offset: 0x18
        u32 ClimbAct;  // offset: 0x1c
        u32 StaminaNo;  // offset: 0x20
        u32 ShlGroup;  // offset: 0x24
        u32 ShlIndex;  // offset: 0x28
        u32 ShlIndexLv2;  // offset: 0x2c
        u32 ShiftDeleteBit;  // offset: 0x30
        u32 ShiftShlIndex;  // offset: 0x34
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
    cpJob04();
    virtual ~cpJob04();
    virtual void setup();  // vtable slot 6
    virtual void setupJobData();  // vtable slot 21
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    void circleProc();
    virtual void after();  // vtable slot 18
    virtual void notifyDeleteShell(s32 work);  // vtable slot 56
    virtual void callbackHitLand();  // vtable slot 31
    virtual void callbackDamage(cHitInfo* pHitLocalInfo);  // vtable slot 33
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag);  // vtable slot 32
    virtual void callbackDie();  // vtable slot 50
    virtual void callbackOcdSeal();  // vtable slot 51
    void excuteSoulBomb();
    void ReduceStamina(u32 index, u32 number);
    void circleHateProc();
    bool checkFeildBitFlg(u32 bit);
    void setFeildBitFlg(u32 bit, bool flg);
    u8 getFeildBit() const;
    void setFeildBit(u32 bit);
    bool checkShiftBitFlg(u32 bit);
    void setShiftBitFlg(u32 bit, bool flg);
    u8 getShiftBit() const;
    void seBothBitFlg(u32 bit, bool flg);
    void BeginCircleShift();
    void FinishCircleShift();
    void checkRangeCircleShiftAll();
    s32 checkShortRangeProc(MtTypedArray<uShlBase> shl_array);
    void setCirclePartyAll(u32 group, u32 index, u32 type);
    void reqCircleBitShl(u32 group, u32 index, u32 id);
    bool checkShiftConditions(uBaseModel* pUit, u32 shlId);
    void limitCircleAllAct(u32 act);
    void unLimitCircleAllAct();
    void limitCircleAllActAir(u32 act);
    void unLimitCircleAllActAir();
    void setIsShortChargeFlg(bool flg);
    bool getIsShortChargeFlg() const;
    void setIsHealSpot(bool flg);
    bool getIsHealSpot() const;
    void setHealSpotTimer(u32 skillLev);
    void killHealSpot();
    void setIsCureSpot(bool flg);
    bool getIsCureSpot() const;
    void setCureSpotTimer(u32 skillLev);
    void killCureSpot();
    bool isEnergySpot();
    void setEnergySpotFlg(bool flg);
    void setEnergySpotTimer(u32 skillLev);
    void KillEnergySpot();
    void createNormalCircle(const CIRCLE_PARAM& data);
    void deleteNormalCircle(const CIRCLE_PARAM& data);
    void createNormalShiftCircle(const CIRCLE_PARAM& data);
    void deleteNormalShiftCircle(const CIRCLE_PARAM& data);
    void createCustomCircle(const CIRCLE_PARAM& data);
    void deleteCustomCircle(const CIRCLE_PARAM& data);
    void createCustomShiftCircle(const CIRCLE_PARAM& data);
    void deleteCustomShiftCircle(const CIRCLE_PARAM& data);
    void deleteAtherNormalCircle(const CIRCLE_PARAM& data);
    void deleteAtherCustomCircle(const CIRCLE_PARAM& data);
    void circleEnd(u32 act);
    void circleEndAir(u32 act);
    void normalCircleActionProc(u32 act);
    void customCircleActionProc(u32 act);
    void climbCircleActionProc(u32 act);
    bool isHealingCircle();
    void setHealingCircleFlg(bool flg);
    void deleteHealingCircle();
    bool isShiftHealingCircle();
    void setShiftHealingCircleFlg(bool flg);
    void createShiftHealingCircle();
    void deleteShiftHealingCircle();
    bool isAttackCircle();
    void setAttackCircleFlg(bool flg);
    void deleteAttackCircle();
    bool isShiftAttackCircle();
    void setShiftAttackCircleFlg(bool flg);
    void createShiftAttackCircle();
    void deleteShiftAttackCircle();
    bool isDefenceCircle();
    void setDefenceCircleFlg(bool flg);
    void deleteDefenceCircle();
    bool isShiftDefenceCircle();
    void setShiftDefenceCircleFlg(bool flg);
    void createShiftDefenceCircle();
    void deleteShiftDefenceCircle();
    bool isIronField();
    void setIronFieldFlg(bool flg);
    void deleteIronField();
    bool isShiftIronCircle();
    void setShiftIronCircleFlg(bool flg);
    void createShiftIronCircle();
    void deleteShiftIronCircle();
    bool isSaintgCircle();
    void setSaintCircleFlg(bool flg);
    void deleteSaintCircle();
    bool isShiftSaintCircle();
    void setShiftSaintCircleFlg(bool flg);
    void createShiftSaintCircle();
    void deleteShiftSaintCircle();
    bool isSolaceCircle();
    void setSolaceCircleFlg(bool flg);
    void deleteSolaceCircle();
    bool isShiftSolaceCircle();
    void setShiftSolaceCircleFlg(bool flg);
    void createShiftSolaceCircle();
    void deleteShiftSolaceCircle();
    bool isSoulFull();
    void setSoulFullFlg(bool flg);
    void deleteSoulFull();
    bool isGuardBits();
    void setGuardBits(u32 isLv2);
    void hitNoticeGuardBit();
    u32 getGuardBitNum() const;
    u32 cheackGuardBit();
    bool cheackIsLiveGuardBit(u32 id);
    void deleteGuardBit();
    bool isBlastOption();
    void setBlastOption(bool flg);
    void deleteBlastOption();
    const uDDOModel* getOptionShl();
    const uDDOModel* getOptionBigShl();
    const uDDOModel* getOptionBigShlSecond();
    void resetHealHateInterval();
    bool isCanFloating();
    void setCanFloating(bool flg);
    s32 getAirChantCount() const;
    void addgeAirChantCount();
    void killAllCircle();
    void clearAllCircle();
    void clearCustomCircle();
    void shlHitCountTutorialFlg(s32 id);
    bool canEndureInClimb();
    bool isCanCircleShiftAct();
    bool isActiveShiftNormalCircle();
    bool isActiveShiftCustomCircle();
private:
    bool mCanFloating;  // offset: 0x58
    bool mClearFloating;  // offset: 0x59
    s8 mReservationEffectKillFlg;  // offset: 0x5a
    u32 mCircleFlgs;  // offset: 0x5c
    u32 mShiftFlgs;  // offset: 0x60
    f32 mShiftCheckTimer;  // offset: 0x64
    bool mIsHealSpot;  // offset: 0x68
    f32 mHealSpotTimer;  // offset: 0x6c
    bool mIsCureSpot;  // offset: 0x70
    f32 mCureSpotTimer;  // offset: 0x74
    bool mIsEnergySpot;  // offset: 0x78
    f32 mEnergySpotTimer;  // offset: 0x7c
    bool isCheckGuard;  // offset: 0x80
    bool mIsReadyKillBit;  // offset: 0x81
    u8 mGuardBitFlgs;  // offset: 0x82
    s32 mGuardBitProtectTimes;  // offset: 0x84
    s32 mNowGuardTimes;  // offset: 0x88
    bool mIsShortCharge;  // offset: 0x8c
    s32 mAirChantCount;  // offset: 0x90
    s32 tutorialSkillCount01;  // offset: 0x94
    u32 mReservationNum[5];  // offset: 0x98
    f32 mHealHateInterval;  // offset: 0xac
public:
    static MyDTI DTI;
    static const s8 GUARD_BIT_MAX = 5;
};
