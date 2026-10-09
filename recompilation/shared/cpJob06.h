#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cGeneralPointPtr.h"
#include "cpJobBase.h"
#include "nHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cEfcHandle;
class cGeneralPointPtr;
class cHitInfo;
class cHitInfoAfter;
class uDDOModel;

// Declarations
class cpJob06;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJob06 : public cpJobBase
{
public:
    enum
    {
        CS12_SIZE_1M = 0,
        CS12_SIZE_3M = 1,
        CS12_SIZE_5M = 2,
        CS12_SIZE_7M = 3,
        CS12_SIZE_10M = 4,
        CS12_SIZE_15M = 5,
        CS12_SIZE_20M = 6,
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
    cpJob06();
    virtual ~cpJob06();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void after();  // vtable slot 18
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void reset();  // vtable slot 20
    virtual void setupJobData();  // vtable slot 21
    virtual void callbackHitLand();  // vtable slot 31
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 43
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    void updateAimEffect(u32 elem, const MtVector3& pos);
    void killAimEffect();
    void setDir(const MtVector3& dir);
    bool isCanShotMagicShot(bool level);
    bool isCanChantBackStep();
    bool isCanChantCancel();
    bool isCanFloating();
    void setCanFloating(bool flg);
    void shlHitCountTutorialFlg(s32 id);
    s32 getAirChantCount();
    void addgeAirChantCount();
    bool checkSkillLevel(s32 ActNo, nHuman::HM_SKILL_LV skillLv) const;
private:
    void checkCheatMgcBigDamage();
public:
    f32 getCS01LastShotRate();
    void setCS01LastShotRate(f32 val);
    f32 getCS13LastShotRate();
    void setCS13LastShotRate(f32 val);
    void clearReqKillCS13LandEffect();
    bool getIsPressAttack2();
    void setIsPressAttack2(bool val);
    f32 getCS14LastShotRate();
    void setCS14LastShotRate(f32 val);
    void requestCS12Effect(const MtVector3& pos);
    void killCS12Effect();
    void updateCS12Effect();
    void setCS12EffectSize(s32 val);
    void setCS12EffectScale(f32 val);
    void setCS12EffectPos(const MtVector3& pos);
    const MtVector3& getCS12EffectPos();
    s32 getPrminentSphereSize();
    void setPrminentSphereSize(s32 valu);
    s32 getCS12SizeLevel(s32 size, bool isLv2);
    void setIsCanCS12Shot(bool flg);
    bool getIsCanCS12Shot();
    void pawnControlCS12(const MtVector3& target_pos);
    bool isExistAnchor();
    void callChainLight();
    void updateChainLight();
    void finishChainLight();
    void callAnchorLightning(u32 level);
    void finishAnchorLightning();
    void killCS14Shl();
    void initCS14Timer(u32 lavel);
    void decreaseCS14Timer();
    f32 getCS14Timer();
    bool isCS14Range();
    uDDOModel* getCS14Anchor();
    bool isExistIceBarrett();
    void killIceBarrett();
    void getIceBarrettPos(MtVector3* ret);
    u32 getIceRemainingBullets();
    void resetIceRemainingBullets(bool isLv2);
    void decreaseIceRemainingBullets(bool isAll);
    void setIsCanShotIceShot(bool flg);
    bool getIsCanShotIceShot();
    void setCS13TopDir(const MtVector3&);
    const MtVector3& getCS13TopDir();
    void setIceShotBeforeLockMode(bool flg);
    bool getIceShotBeforeLockMode();
    cGeneralPointPtr getBeforeMagicTarget();
    void setBeforeMagicTarget(cGeneralPointPtr tgt);
    bool isCanDispTargetMark();
private:
    bool mCanFloating;  // offset: 0x58
    bool mClearFloating;  // offset: 0x59
    s32 mAirChantCount;  // offset: 0x5c
    s32 tutorialSkillCount01;  // offset: 0x60
    s32 tutorialSkillCount02;  // offset: 0x64
    cEfcHandle* mpEfcHandle;  // offset: 0x68
    uDDOModel* mpAimEfcUnit;  // offset: 0x70
    f32 mCheckInterval;  // offset: 0x78
    f32 mCS01LastShotRate;  // offset: 0x7c
    f32 mCS13LastShotRate;  // offset: 0x80
    bool mReqKillCS13LandEffect;  // offset: 0x84
    bool mIsPressAttack2;  // offset: 0x85
    f32 mCS14LastShotRate;  // offset: 0x88
    bool mIsCS12Effect;  // offset: 0x8c
    bool mIsCanCS12Shot;  // offset: 0x8d
    s32 mShotPrminentSphereSize;  // offset: 0x90
    s32 mCS12Timer;  // offset: 0x94
    MtVector3 mCS12Pos;  // offset: 0xa0
    uDDOModel* mpEfcCS12Unit;  // offset: 0xb0
    cEfcHandle* mEfcCS12Hnd;  // offset: 0xb8
    uDDOModel* mpEfcCS14Unit;  // offset: 0xc0
    cEfcHandle* mEfcCS14Hnd;  // offset: 0xc8
    cEfcHandle* mEfcCS14AnchorHnd;  // offset: 0xd0
    bool mIsCS14Effect;  // offset: 0xd8
    bool mIsCS14AnchorEffect;  // offset: 0xd9
    f32 mCS14UseTime;  // offset: 0xdc
    bool mIsCanShotIceShot;  // offset: 0xe0
    bool mIceShotBeforeLockMode;  // offset: 0xe1
    u32 mIceRemainingBullets;  // offset: 0xe4
    MtVector3 mCS13TopDir;  // offset: 0xf0
    cGeneralPointPtr mBeforeMagicTarget;  // offset: 0x100
public:
    static MyDTI DTI;
};
