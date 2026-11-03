#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nEnemyID.h"
#include "../../generated/shared/nHuman.h"
#include "uHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cAttackParam;
class cCollNode;
class cDraw;
class cEfcHandle;
namespace cEvaluationName { class cEvaluation; }
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class cResource;
class cpErosionEnemySmall;
class rChildRegionStatusParam;
class rHumanEnemyParam;
class rMotionList;
class rParentRegionStatusParam;
class rShlParamList;

// Declarations
class uHumanEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uHumanEnemy : public uHuman
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
    uHumanEnemy();
    virtual ~uHumanEnemy();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void before();
    void after();
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void setupBeforeContext(bool initSet);  // vtable slot 46
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void registResource(bool initSet, u32 tagId);  // vtable slot 205
    void registResourceCore(u32 resType, cResource* pResource, bool initSet);
    void setStartThinkTbl(u32 no);
    u32 getStartThinkTbl() const;
    nEnemy::ENEMY_ID getEnemyEnumID() const;
    void setEnemyEnumID(nEnemy::ENEMY_ID id);
    virtual u32 getEnemyID() const;  // vtable slot 187
    void setEnemyID(u32 id);
    static nHuman::JOB_ENUM getJobIDFromEmID(u32 emID);
    nHuman::JOB_ENUM getJobIDFromEmID() const;
    virtual u32 getThinkMode();  // vtable slot 188
    virtual void setThinkMode(u32 thinkMode);  // vtable slot 189
    virtual cEvaluationName::cEvaluation* getEvaluation();  // vtable slot 190
    u32 getShieldStagger() const;
    u32 getHmEmWepAtk() const;
    u32 getHmEmWepMAtk() const;
    rHumanEnemyParam* getHumanEnemyParam() const;
private:
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    void setHumanEnemyParam();
    virtual bool checkCalc(const cAttackParam* pAtkParam);  // vtable slot 172
public:
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 89
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 93
    virtual void callbackShrink(cHitInfoAfter* pHitInfo);  // vtable slot 106
    virtual void callbackBlow(cHitInfoAfter* pHitInfo);  // vtable slot 107
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual void callbackHealedAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 96
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 149
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 156
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 143
    u32 getGuardCounterCnt() const;
    void setGuardCounterCnt(u32);
    u32 getShrinkCnt() const;
    void resetShrinkCnt();
    void setIsBloodOrbEff(bool flg);
    bool isBloodOrbEff() const;
    bool isEnemyThought() const;
    bool isEnemyPawn() const;
    void disableMontageRandom();
    bool isMontageRandom() const;
protected:
    cpErosionEnemySmall* getErosionEnemySmall() const;
private:
    u32 mEnemyID;  // offset: 0x376c
    nEnemy::ENEMY_ID mEnemyResID;  // offset: 0x3770
    u32 mThinkMode;  // offset: 0x3774
    u32 mShieldStagger;  // offset: 0x3778
    f32 mHmEmWepAtk;  // offset: 0x377c
    f32 mHmEmWepMAtk;  // offset: 0x3780
    u32 mGuardCounterCnt;  // offset: 0x3784
    u32 mShrinkCnt;  // offset: 0x3788
    u32 mResetAtkCnt;  // offset: 0x378c
    u32 mResetActNo;  // offset: 0x3790
    f32 mShrinkCntResetTimer;  // offset: 0x3794
    bool mIsMontageRandom;  // offset: 0x3798
    u32 mThinkTbl_Select;  // offset: 0x379c
    cEfcHandle* mpEmEffect;  // offset: 0x37a0
    cHitNode* mpDamageNode;  // offset: 0x37a8
    rHumanEnemyParam* mprHumanEnemyParam;  // offset: 0x37b0
    rMotionList* mprHmEmComMotion;  // offset: 0x37b8
    rMotionList* mprHmEmAtkMotion;  // offset: 0x37c0
    rShlParamList* mprHmEmShlParamList;  // offset: 0x37c8
    rParentRegionStatusParam* mprHmEmPRegion;  // offset: 0x37d0
    rChildRegionStatusParam* mprHmEmCRegion;  // offset: 0x37d8
    bool mIsBloodOrbEff;  // offset: 0x37e0
protected:
    cpErosionEnemySmall* mpErosionEnemySmall;  // offset: 0x37e8
public:
    static MyDTI DTI;
};

inline void* uHumanEnemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uHumanEnemy::setStartThinkTbl(u32 no) {
    this->mThinkTbl_Select = no;
}

inline cpErosionEnemySmall* uHumanEnemy::getErosionEnemySmall() const {
    return this->mpErosionEnemySmall;
}
