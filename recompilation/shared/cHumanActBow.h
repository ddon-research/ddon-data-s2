#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cCamInterporate.h"
#include "cHumanAction.h"
#include "cJumpParamCtrl.h"
#include "cpInput.h"
#include "cpShlShotCtrl.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtVector3;
class cCamInterporateVec3;
class cEfcHandle;
class cJumpParamCtrl;
namespace nHumanBow { class cBowActParam; }
namespace nHumanBow { struct stNetData; }
class rEffectProvider;
class uAimCheck;
class uCmc;
class uCoord;
class uCorePointSearch;
class uDDOModel;
class uShlBase;

// Declarations
class cPlActWpnBow;
class cPlActWpnBowBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cCamInterporateF32 = cCamInterporate<float>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cPlActWpnBowBase : public cHumanActBase
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
    cPlActWpnBowBase();
    virtual ~cPlActWpnBowBase();
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
protected:
    bool isEnableWalk();
    bool isBowEnd();
    void setBowAction(s32 act);
    void setMotion(u32 type, u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed);
    f32 getMotionFrame(s32 type, s32 nextMotNo);
    bool isPlayer();
protected:
    s32 motType;  // offset: 0x44
    bool mIsAimWall;  // offset: 0x48
    MtVector3 mAimPos;  // offset: 0x50
    bool mIsMgcBowJustOffset;  // offset: 0x60
    bool mIsFirstFrame;  // offset: 0x61
    bool mIsFirstRecv;  // offset: 0x62
    f32 mMoveRadian;  // offset: 0x64
    f32 mNetPosLengthSq;  // offset: 0x68
    f32 mSkillTime;  // offset: 0x6c
    cJumpParamCtrl mJumpParamCtrl;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const f32 mSlaveRunDistance;
    static const f32 mSlaveWalkDistance;
    static const f32 mSlaveWaitDistance;
    static const f32 mCustomBeginTime;
};

class cPlActWpnBow : public cPlActWpnBowBase
{
public:
    enum SKILL_TYPE
    {
        SKILL_TYPE_NONE = -1,
        SKILL_TYPE_0 = 0,
        SKILL_TYPE_1 = 1,
        SKILL_TYPE_2 = 2,
        SKILL_TYPE_3 = 3,
        SKILL_CUSTOM_END = 3,
        SKILL_TYPE_NORMAL_2 = 4,
        SKILL_TYPE_NORMAL_CHANGE = 5,
        SKILL_TYPE_SHIJIMA = 6,
        SKILL_TYPE_NUM = 7,
    };
    enum SHL_SET_ROUTINE
    {
        SHL_SET_NOW = 0,
        SHL_SET_END = 1,
    };
    enum LOW_ACT_NO
    {
        LOW_ACT_WAIT = 0,
        LOW_ACT_WALK = 1,
        LOW_ACT_RUN = 2,
        LOW_ACT_TURN = 3,
        LOW_ACT_JUMP_BGN = 4,
        LOW_ACT_JUMP = 5,
        LOW_ACT_FALL = 6,
        LOW_ACT_LAND = 7,
        LOW_ACT_NUM = 8,
    };
    enum TURN_TYPE
    {
        TURN_LEFT = 0,
        TURN_RIGHT = 1,
    };
    enum JUMP_TYPE
    {
        JUMP_TYPE_F = 0,
        JUMP_TYPE_V = 1,
        JUMP_TYPE_NUM = 2,
    };
    enum UP_ACT_NO
    {
        UP_ACT_BGN = 0,
        UP_ACT_WAIT = 1,
        UP_ACT_RELOAD = 2,
        UP_ACT_CUSTOMSKILL = 3,
        UP_ACT_SHOT = 4,
        UP_ACT_CHANGE = 5,
        UP_ACT_END = 6,
        UP_ACT_NUM = 7,
    };
    enum
    {
        ACT_WORK_JUST_RELOAD = 65536,
        ACT_WORK_BGN_SKILL_TYPE_0 = 131072,
        ACT_WORK_BGN_SKILL_TYPE_1 = 262144,
        ACT_WORK_BGN_SKILL_TYPE_2 = 524288,
        ACT_WORK_BGN_SKILL_TYPE_3 = 1048576,
    };
    enum
    {
        MOVE_DIR_F = 0,
        MOVE_DIR_B = 1,
        MOVE_DIR_R = 2,
        MOVE_DIR_L = 3,
        MOVE_DIR_NUM = 4,
    };
    enum
    {
        MOVE_TYPE_WALK = 0,
        MOVE_TYPE_RUN = 1,
    };
    enum L_CHECK
    {
        L_CHECK_FALL = 0,
        L_CHECK_JUMP = 1,
        L_CHECK_WALK = 2,
        L_CHECK_RUN = 3,
        L_CHECK_WAIT = 4,
        L_CHECK_TURN = 5,
        L_CHECK_LAND = 6,
        LOW_CHECK_NUM = 7,
    };
    enum
    {
        UP_CHECK_END = 0,
        UP_CHECK_RELOAD = 1,
        UP_CHECK_HUNTER_CS07 = 2,
        UP_CHECK_CHANGE = 3,
        UP_CHECK_SHOT = 4,
        UP_CHECK_WAIT = 5,
        UP_CHECK_NUM = 6,
    };
    enum
    {
        UP_ACT2_CHANGE_INIT = 0,
        UP_ACT2_CHANGE_LOOP = 1,
        UP_ACT2_CHANGE_LOOP2 = 2,
    };
public:
    template <typename ACT_TYPE> struct stCheckTbl;
    class MyDTI;
    struct stActTbl;
public:
    using ActFunc = void(cPlActWpnBow::*)();
    using stLowCheckTbl = cPlActWpnBow::stCheckTbl<cPlActWpnBow::LOW_ACT_NO>;
    using CheckFunc = bool(cPlActWpnBow::*)();
    using stUpCheckTbl = cPlActWpnBow::stCheckTbl<cPlActWpnBow::UP_ACT_NO>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stActTbl
    {
    public:
        bool checkNetOption(u32) const;
    public:
        cPlActWpnBow::ActFunc pInitFunc;  // offset: 0x0
        cPlActWpnBow::ActFunc pMoveFunc;  // offset: 0x10
        cPlActWpnBow::ActFunc pFinalFunc;  // offset: 0x20
        u32 checkActBit;  // offset: 0x30
        u32 cancelActBit;  // offset: 0x34
        u32 netOpFlag;  // offset: 0x38
    };
public:
    template <typename ACT_TYPE>
    struct stCheckTbl
    {
    public:
        ACT_TYPE actNo;  // offset: 0x0
        cPlActWpnBow::CheckFunc pCheckFunc;  // offset: 0x8
        u32 cancelSeq;  // offset: 0x18
        bool isCheckSlave;  // offset: 0x1c
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
    cPlActWpnBow();
    virtual ~cPlActWpnBow();
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 13
private:
    nHuman::CUSTOM_SKILL_ENUM getCustomSkillId(SKILL_TYPE skillType);
    void checkLow();
    bool checkLow_Walk();
    bool checkLow_Turn();
    bool checkLow_Run();
    bool checkLow_Wait();
    bool checkLow_Jump();
    bool checkLow_Fall();
    bool checkLow_Land();
    void moveLow();
    void initLow_Wait();
    void moveLow_Wait();
    void initLow_Turn();
    void moveLow_Turn();
    void initLow_Walk();
    void moveLow_Walk();
    void initLow_Run();
    void moveLow_Run();
    void initLow_JumpBgn();
    void moveLow_JumpBgn();
    void initLow_Jump();
    void moveLow_Jump();
    void initLow_Fall();
    void moveLow_Fall();
    void initLow_Land();
    void moveLow_Land();
    void finalLow_Land();
    void setLowAction(LOW_ACT_NO actNo);
    void setLowActReq(LOW_ACT_NO actNo);
    void setLowActEnd();
    bool isLowActEnd() const;
    const stActTbl& getLowActParam() const;
    void moveShijimScopeFilter();
    void requestScopeSeBgn();
    void requestScopeSeEnd();
public:
    bool isLowActUpdate() const;
    LOW_ACT_NO getLowActNo() const;
protected:
    void checkUp();
    bool checkUp_Wait();
    bool checkUp_Shot();
    bool checkUp_Change();
    bool checkUp_End();
    bool checkUp_Reload();
    bool checkUp_CustomSkill();
    void moveCharge();
    void moveUp();
    void initUp_Bgn();
    void moveUp_Bgn();
    void initUp_Wait();
    void moveUp_Wait();
    void finalUp_Wait();
    void initUp_Shot();
    void moveUp_Shot();
    void finalUp_Shot();
    void shotRetNml();
    void initup_Change();
    void moveUp_Change();
    void initUp_End();
    void moveUp_End();
    void initUp_Reload();
    void moveUp_Reload();
    void initUp_CustomSkill();
    void moveUp_CustomSkill();
    virtual void initUp_ShotSub();  // vtable slot 18
    u32 getUpRoutine() const;
    void setUpRoutine(UP_ACT_NO routine, u32 routine2);
    void setUpAction(UP_ACT_NO actNo);
    void setUpActReq(UP_ACT_NO actNo);
    void setUpActEnd();
    bool isUpActEnd() const;
    const stActTbl& getUpActParam() const;
    u32 getUpperRoutine2() const;
    void setUpperRoutine2(u32);
public:
    bool isUpActUpdate() const;
    UP_ACT_NO getUpActNo() const;
    SKILL_TYPE getTrgForceCancelCustomSkillType();
    nHumanBow::stNetData getNetDataUp() const;
    nHumanBow::stNetData getNetDataLow() const;
    nHumanBow::stNetData getNetDataPeriod() const;
    void receiveNetDataUp(u32 _data);
    void receiveNetDataLow(u32 _data);
    void receiveNetDataPeriod(u32 _data);
    SKILL_TYPE getSelectedSkillType() const;
protected:
    const nHumanBow::cBowActParam* getActParam() const;
    void calcTargetPos();
    void setShl(s32 group, s32 no, f32 degX, f32 degY, f32 wait);
    virtual bool canSetShl();  // vtable slot 19
    // Address: 0x01993c30 - 0x01993c31 (1 bytes)
    virtual void setShlSub(uShlBase* pShl, const MtVector3& shootVec, cpShlShotCtrl::cShlShotReqInfo& shotInfo) {}  // vtable slot 20
    virtual void setShlSubAfter(uShlBase* pShl);  // vtable slot 21
    bool canShot() const;
    uCmc* getAliveCmc() const;
    const nHumanBow::cBowActParam* searchBowActParam(s32 actIndex);
    rEffectProvider* getCmnEpvResource();
    u32 getElementMaterialFlag();
    cEfcHandle* setEffect(rEffectProvider* prEpv, s32 index, s32 no);
    cEfcHandle* setEffect(rEffectProvider* prEpv, s32 index, s32 no, uDDOModel* pParent);
    cEfcHandle* setEffect(rEffectProvider* prEpv, s32 index, s32 no, const MtVector3& pos, f32 scale);
    void requestSkillSE(s32 no);
    void requestSkillSE(s32 no, const MtVector3& pos);
    void requestSkillSE(s32 no, uCoord* pCoord, s32 joint);
    void requestCmnSE(s32 no);
    void requestCmnSE(s32 no, const MtVector3& pos);
    void requestCmnSE(s32 no, uCoord* pCoord, s32 joint);
    void requestCastSE(s32 no);
    void setShotEfct();
    virtual bool canBowActEnd();  // vtable slot 22
    void setLowerWaitMotion();
    void setUpperWaitMotion();
    void setUpperShotMotion(bool isFrameContinue, bool forcible, const nHumanBow::cBowActParam* pActParam);
    void setUpperChangeMotion(bool isFrameContinue, bool forcible);
    void setUpperMotion(u32 center, u32 up, u32 down, f32 hokan, bool forcible, f32 frame, f32 speed, bool isNoFinish);
    void setLowerMotion(const u8* motTbl, f32 hokan, bool forcible, bool baseSet);
    void shlSetReq();
    void shlSetMove();
    void shlSetEnd();
    void setShlLevel();
    void initCharge();
    void initChargeEfct();
    void endCharge();
    bool isChargeComp() const;
    u32 getChargeLv() const;
    virtual f32 getChargeFrame() const;  // vtable slot 23
    void changeChargeEfct(s32 no);
    void changeFilterEfct(s32 no);
    u32 getShlSetNum() const;
    rEffectProvider* getEpvCmn();
    rEffectProvider* getEpvSkill();
    void setChargeCompEfct();
    bool isJumpMove() const;
    f32 getAccurate();
    virtual f32 getAccurateAdd();  // vtable slot 24
    void calcShootVec(MtVector3& vec, f32 degX, f32 degY);
    f32 getMoveSpeed();
    f32 getMoveMotionSpeed();
    virtual u32 getShlElement();  // vtable slot 25
    u32 getBowCameraNo();
    u32 getCameraPresetNo();
    virtual void checkCriticalRange();  // vtable slot 26
    u32 getNoArrowMotNo();
    void requestMgcBowKamaeSe();
    void stopMgcBowKamaeSe();
    void requestKamaeEffect();
private:
    // Address: 0x01993c50 - 0x01993c51 (1 bytes)
    virtual void evEnd() {}  // vtable slot 27
    // Address: 0x01993c60 - 0x01993c61 (1 bytes)
    virtual void evSkillChanged() {}  // vtable slot 28
    // Address: 0x01993c70 - 0x01993c71 (1 bytes)
    virtual void evShlSetEnd() {}  // vtable slot 29
    // Address: 0x01993c80 - 0x01993c81 (1 bytes)
    virtual void moveUpSub() {}  // vtable slot 30
    void setupSkillChange(bool isChAction, bool isNoEffect);
    bool isOnMotSeq(MOT_TYPE type, u32 seq);
    bool isTriShootButton();
    bool isTriReloadButton();
    bool canMove();
    bool canCharge();
    bool reserveSkillChange(bool forceCheck);
    SKILL_TYPE getReserveSkillType();
    void clearReserve();
    void dispAimSight();
    void checkJob03CS05Scale();
    void requestBowCamera();
    f32 getBgnMotionSpeed();
    void explosionReload(MOT_TYPE type);
private:
    const nHumanBow::cBowActParam* mpNmlActParam;  // offset: 0x78
    const nHumanBow::cBowActParam* mpNml2ActParam;  // offset: 0x80
    const nHumanBow::cBowActParam* mpShijimaParam;  // offset: 0x88
    nDDOUtility::cArray<const nHumanBow::cBowActParam*, 4> mCSActParamPtrs;  // offset: 0x90
    nDDOUtility::cArray<const nHumanBow::cBowActParam*, 2> mNMActParamPtrs;  // offset: 0xb0
    const nHumanBow::cBowActParam* mpActParam;  // offset: 0xc0
    const nHumanBow::cBowActParam* mpActParamTemp;  // offset: 0xc8
    bool mIsInit;  // offset: 0xd0
    uAimCheck* mpAimCheck;  // offset: 0xd8
    uCorePointSearch* mpCoreSearch;  // offset: 0xe0
    f32 mTimer;  // offset: 0xe8
    bool mIsLowerMotReset;  // offset: 0xec
    MtVector3 mOldCameraVec;  // offset: 0xf0
    MtMatrix mInitMat;  // offset: 0x100
    f32 mInitAngY;  // offset: 0x140
    u32 mMoveDir;  // offset: 0x144
    u32 mMoveType;  // offset: 0x148
    bool mIsShotRsv;  // offset: 0x14c
    SKILL_TYPE mRsvSkillType;  // offset: 0x150
    cpInput::unBtnInfo mRsvBtnInfo;  // offset: 0x158
    bool mIsShijimaEff;  // offset: 0x160
    bool mIsReloadRsv;  // offset: 0x161
    bool mIsFallEnd;  // offset: 0x162
    bool mIsCustomBegin;  // offset: 0x163
    bool mIsEndMotion;  // offset: 0x164
    u32 mEndMotUp;  // offset: 0x168
    u32 mEndMotLow;  // offset: 0x16c
    f32 mBlurreAcc;  // offset: 0x170
    f32 mIdealAccurate;  // offset: 0x174
    f32 mMoveUpBgnTimer;  // offset: 0x178
    cCamInterporateF32 mInterAccurate;  // offset: 0x180
    SKILL_TYPE mSelectedSkillType;  // offset: 0x198
    f32 mShlSetFrame;  // offset: 0x19c
    u32 mShlSetLv;  // offset: 0x1a0
    SHL_SET_ROUTINE mShlSetRoutine;  // offset: 0x1a4
    f32 mShlAtckAdd;  // offset: 0x1a8
    bool mSlaveShotJust;  // offset: 0x1ac
    MtVector3 mLandMarkPos;  // offset: 0x1b0
    f32 mLMPadVibInter;  // offset: 0x1c0
    u32 mCameraType;  // offset: 0x1c4
    u32 mUseArrowNum;  // offset: 0x1c8
    rEffectProvider* mprEpvCmn;  // offset: 0x1d0
    rEffectProvider* mprEpvSkill;  // offset: 0x1d8
    u32 mChargeLv;  // offset: 0x1e0
    bool mIsChargeComp;  // offset: 0x1e4
    cEfcHandle* mpEfcHandleCharge;  // offset: 0x1e8
    cEfcHandle* mpEfcHandleChargeSkill;  // offset: 0x1f0
    cEfcHandle* mpEfcHandleLandMark;  // offset: 0x1f8
    cEfcHandle* mpEfcHandleFilter;  // offset: 0x200
    cEfcHandle* mpEfcSpecial;  // offset: 0x208
    cCamInterporateVec3 mInterCmcAimPos;  // offset: 0x210
    f32 mCmcAimPosInterRate;  // offset: 0x250
    u32 mJob03Cs11ShotNum;  // offset: 0x254
    f32 mJob03Cs11ShotMotSpeed;  // offset: 0x258
    f32 mJob03Cs11ShotAddMotSpeed;  // offset: 0x25c
    bool mIsFinishShot;  // offset: 0x260
    bool mIsMissShot;  // offset: 0x261
protected:
    cEfcHandle* mpEfcKamaeHandle;  // offset: 0x268
    u32 mShlSetNum;  // offset: 0x270
    f32 mDispAimSightDelay;  // offset: 0x274
    u8 mBowNetBit;  // offset: 0x278
    u8 mBowNetBitLow;  // offset: 0x279
    u8 mSlaveShotNum;  // offset: 0x27a
private:
    LOW_ACT_NO mLowActNo;  // offset: 0x27c
    LOW_ACT_NO mLowActNoOld;  // offset: 0x280
    LOW_ACT_NO mLowActNoOld2;  // offset: 0x284
    bool mIsLowActEnd;  // offset: 0x288
    bool mIsLowUpdate;  // offset: 0x289
    bool mIsLowActReq;  // offset: 0x28a
    LOW_ACT_NO mLowActReqNo;  // offset: 0x28c
    bool mIsCheckLand;  // offset: 0x290
    TURN_TYPE mTurnType;  // offset: 0x294
    f32 mTurnNow;  // offset: 0x298
    f32 mTurnFrame;  // offset: 0x29c
    JUMP_TYPE mJumpType;  // offset: 0x2a0
    f32 mJumpInitMoveRad;  // offset: 0x2a4
protected:
    bool isShotBgnCharge;  // offset: 0x2a8
    bool mIsChargeReset;  // offset: 0x2a9
private:
    UP_ACT_NO mUpActNo;  // offset: 0x2ac
    UP_ACT_NO mUpActNoOld;  // offset: 0x2b0
    bool mIsUpActEnd;  // offset: 0x2b4
    bool mIsUpUpdate;  // offset: 0x2b5
    bool mIsUpActReq;  // offset: 0x2b6
    UP_ACT_NO mUpActReqNo;  // offset: 0x2b8
    u32 mUpRoutine;  // offset: 0x2bc
    u32 mUpRoutine2;  // offset: 0x2c0
    f32 mNetPeriodFrame;  // offset: 0x2c4
public:
    static MyDTI DTI;
private:
    static const u32 FAR_CAMETA_OFFSET;
public:
    static stActTbl lowActTbl[8];
    static stLowCheckTbl lowCheckTbl[7];
protected:
    static stActTbl upActTbl[7];
    static stUpCheckTbl upCheckTbl[6];
private:
    static const f32 NET_PERIOD_INTERVAL;
};

// Inline, no code of its own: checked where it is inlined.
inline const nHumanBow::cBowActParam* cPlActWpnBow::getActParam() const {
    return this->mpActParam;
}
