#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "cDelegate.h"
#include "cGeneralPointPtr.h"
#include "cStaminaCtrl.h"
#include "cpIKCtrl.h"
#include "nAbility.h"
#include "nAction.h"
#include "nCharacterData.h"
#include "nDDOModel.h"
#include "nDDOUtility.h"
#include "nEnemy.h"
#include "nHuman.h"
#include "nHumanMsg.h"
#include "nObjCollision.h"
#include "nRegionStatus.h"
#include "rItemList.h"
#include "rJumpParamTbl.h"
#include "sCollision.h"
#include "sItemManager.h"
#include "sPadExt.h"
#include "uCharacter.h"
#include "uCnsBowUpper.h"
#include "uCnsTurnUpper.h"
#include "uDDOModel.h"
#include "uJobEquip.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtColor;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtVector3;
class cAttackParam;
class cBlowShrinkDmInfo;
class cCollNode;
class cContextInstHm;
class cContextPlayerInfo;
class cDamageSeInfo;
class cDraw;
class cEfcHandle;
class cEquipData;
class cGeneralPointPtr;
class cHitGeom;
class cHitInfo;
class cHitInfoAfter;
class cHumanActBase;
class cHumanActSetNpcMotMyRoom;
class cHumanActSetNpcMotion;
class cJumpParam;
class cJumpParamCtrl;
class cOcdDamageInfo;
class cOcdInfo;
class cPlActWpnBow;
class cPlActWpnBowBase;
class cShlConditionInfo;
class cShlNotifyInfo;
class cStaminaCtrl;
class cStaminaDecList;
class cUnitDieInfo;
class cpBakeJointHuman;
class cpChantCommand;
class cpCharacterEdit;
class cpHmHeadCtrl;
class cpHumanWarpCtrl;
class cpItemThrow;
class cpJob01;
class cpJob02;
class cpJob03;
class cpJob04;
class cpJob05;
class cpJob06;
class cpJob07;
class cpJob08;
class cpJob09;
class cpJob10;
class cpJobBase;
class cpKeyCommand;
class cpMotionFilter;
class cpTransparencyCtrl;
namespace nHumanBow { struct stNetData; }
namespace nKeyCommand { struct stGenericParam; }
namespace nKeyCommand { struct stKeyCommand; }
class rAdjustParam;
class rAttackParam;
class rCharacterEdit;
class rJumpParamTbl;
class rMagicChantParam;
class rModel;
class rMotionList;
class rMotionParam;
class rObjCollision;
class rSoundRequest;
class rStaminaDecTbl;
class sGame;
class uCnsBowUpper;
class uCnsTurnUpper;
class uDDOModel;
class uJobEquip;
class uModel;
class uShlBase;

// Declarations
class uHuman;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uHuman : public uCharacter
{
    // inferred: cHumanActBase::final names uHuman::mIsBeforeAttackHit
    friend class cHumanActBase;
    // inferred: cHumanActSetNpcMotMyRoom::final names uHuman::mIsBeforeAttackHit
    friend class cHumanActSetNpcMotMyRoom;
    // inferred: cHumanActSetNpcMotion::final names uHuman::mIsBeforeAttackHit
    friend class cHumanActSetNpcMotion;
    // inferred: cJumpParamCtrl::updatePadAdjustPos names uHuman::mJumpParam.mAddMoveSpeedXZ
    friend class cJumpParamCtrl;
    // inferred: cPlActWpnBow::moveLow_Walk names uHuman::mIsBowJumpEnable
    friend class cPlActWpnBow;
    // inferred: cPlActWpnBowBase::final names uHuman::mIsBowAim
    friend class cPlActWpnBowBase;
    // inferred: cpJob02::update names uHuman::mCameraExPos.x
    friend class cpJob02;
    // inferred: cpJob05::callbackCatch_Shl names uHuman::mpClimbEnemy
    friend class cpJob05;
    // inferred: sGame::initPlayerUnit names uHuman::mSex
    friend class sGame;
public:
    enum CLIMB_JOLT_TYPE
    {
        CLIMB_JOLT_NONE = 0,
        CLIMB_JOLT_SMALL = 1,
        CLIMB_JOLT_MIDDLE = 2,
        CLIMB_JOLT_LARGE = 3,
    };
    enum CS_CHANGE_STATE
    {
        CS_CHANGE_STATE_DEFAULT = 0,
        CS_CHANGE_STATE_REQUEST = 1,
        CS_CHANGE_STATE_BEFORE_RELOAD = 2,
        CS_CHANGE_STATE_LOAD_ARCHIVE = 3,
        CS_CHANGE_STATE_RELOAD = 4,
    };
    enum CS_CHANGE_GUI_STATE
    {
        CS_CHANGE_GUI_STATE_DEFAULT = 0,
        CS_CHANGE_GUI_STATE_PRE_DISP = 1,
        CS_CHANGE_GUI_STATE_CHANGE_REQUEST = 2,
        CS_CHANGE_GUI_STATE_DISP = 3,
    };
    enum SHIFT_CIRCLE_INDEX
    {
        SHIFT_CIRCLE_HEAL = 0,
        SHIFT_CIRCLE_SAINT = 1,
        SHIFT_CIRCLE_ATTACK = 2,
        SHIFT_CIRCLE_DEFENCE = 3,
        SHIFT_CIRCLE_IRON = 4,
        SHIFT_CIRCLE_SOLACE = 5,
        SHIFT_CIRCLE_STAMINA = 6,
        SHIFT_CIRCLE_SPIRIT = 7,
        SHIFT_CIRCLE_MAX = 8,
    };
    enum FRIGHT_BOARD_JUMP_STAT
    {
        FRIGHT_BOARD_JUMP_NONE = 0,
        FRIGHT_BOARD_JUMP_LAND = 1,
        FRIGHT_BOARD_JUMP_AIR = 2,
    };
    enum
    {
        GOLD_WARP_NONE = 0,
        GOLD_WARP_START = 1,
        GOLD_WARP_FADE = 2,
    };
    enum
    {
        HM_FRAME_DAMAGE_HISTORY = 5,
    };
    enum
    {
        INSTANT_DIE_NONE = 0,
        INSTANT_DIE_START = 1,
        INSTANT_DIE_FADE = 2,
    };
    enum
    {
        HUGEBLE_NONE = 0,
        HUGEBLE_START = 1,
        HUGEBLE_FADE = 2,
        HUGEBLE_DEAD = 3,
    };
    enum
    {
        BAPHOMET_WARP_NONE = 0,
        BAPHOMET_WARP_REQUEST = 1,
        BAPHOMET_WARP_PRE_START = 2,
        BAPHOMET_WARP_START_WAIT = 3,
        BAPHOMET_WARP_START = 4,
        BAPHOMET_WARP_FADE = 5,
        BAPHOMET_WARP_FADE_END = 6,
    };
public:
    class MyDTI;
    class cEnemyClimbInfo;
    class UkemiInfo;
    class cAutoRunInfo;
    class cReqIKInfo;
    class cWallJumpInfo;
    struct stAbilityVsEnemy;
    struct stAbilitySkillUp;
    class cHealSeCaller;
    class cLimitActCtrl;
    class cBlendMotionCtrl;
    struct stEnchantInfo;
public:
    using InfoArray = nDDOUtility::cArray<uHuman::cReqIKInfo, 5>;
    using CMD_FUNC = void(MtObject::*)();
    using u32Array = nDDOUtility::cArray<unsigned int, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cEnemyClimbInfo : public MtObject
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
        cEnemyClimbInfo();
        void init();
        void copyCapsule(const MtCapsule* cap);
        void copyCapsulefromSphere(const MtSphere* sphere);
    public:
        bool mIsValid;  // offset: 0x8
        bool mIsMultiAlign;  // offset: 0x9
        bool mChainBusy;  // offset: 0xa
        bool mIsClimbActive;  // offset: 0xb
        bool mIsStop[4];  // offset: 0xc
        u32 mShape;  // offset: 0x10
        MtCapsule mCap;  // offset: 0x20
        MtVector3 mOffset0;  // offset: 0x50
        MtVector3 mOffset1;  // offset: 0x60
        uDDOModel* mpModel;  // offset: 0x70
        s32 mJoint0;  // offset: 0x78
        s32 mJoint1;  // offset: 0x7c
        MtMatrix mStableLMat;  // offset: 0x80
        MtMatrix mStableWMat;  // offset: 0xc0
        MtVector3 mStableCapLDir;  // offset: 0x100
        MtMatrix mOrgCapMat;  // offset: 0x110
        MtMatrix mCurrentCapMat;  // offset: 0x150
        MtVector3 mTgtPos;  // offset: 0x190
        MtQuaternion mTgtQuat;  // offset: 0x1a0
        f32 mBlend;  // offset: 0x1b0
        bool mAutoMove;  // offset: 0x1b4
        bool mCantAutoMove;  // offset: 0x1b5
        MtVector3 mMoveVec;  // offset: 0x1c0
        MtVector3 mStandSVel;  // offset: 0x1d0
        MtVector3 mStandSVelOld;  // offset: 0x1e0
        f32 mStandSTimer;  // offset: 0x1f0
        s32 mCapsuleChanged;  // offset: 0x1f4
        MtVector3 mChainPlaneNormal;  // offset: 0x200
        MtVector3 mChainPlanePos;  // offset: 0x210
        MtVector3 mChainRootPos;  // offset: 0x220
        MtVector3 mChainWaistPos;  // offset: 0x230
        MtVector3 mChainRFootPos;  // offset: 0x240
        MtVector3 mChainLFootPos;  // offset: 0x250
        MtVector3 mChainWaistVel;  // offset: 0x260
        MtVector3 mChainRFootVel;  // offset: 0x270
        MtVector3 mChainLFootVel;  // offset: 0x280
        f32 mChainRLegLen;  // offset: 0x290
        f32 mChainLLegLen;  // offset: 0x294
        u32 mSeqIndexNo;  // offset: 0x298
        u16 mGroupNo;  // offset: 0x29c
        u16 mNodeNo;  // offset: 0x29e
        u32 mNodeAttr;  // offset: 0x2a0
        bool mFlgUseFit;  // offset: 0x2a4
        f32 mGeomRadius;  // offset: 0x2a8
        static MyDTI DTI;
    };
public:
    class UkemiInfo
    {
    public:
        UkemiInfo();
    public:
        f32 mTimer;  // offset: 0x0
        u32 mTmpActNo;  // offset: 0x4
        bool mIsActive;  // offset: 0x8
    };
public:
    class cAutoRunInfo
    {
    public:
        enum eRunType
        {
            eRunTypeStraight = 0,
            eRunTypeHoming = 1,
        };
    public:
        cAutoRunInfo();
        void clear();
        void clearRequest();
        void setActive();
        void setTransRequest();
        void update(f32 deltaTime);
    public:
        bool mIsActive;  // offset: 0x0
        bool mIsTranseRequest;  // offset: 0x1
        f32 mIsRequesetTimer;  // offset: 0x4
        eRunType mRunType;  // offset: 0x8
        uDDOModel* mpTarget;  // offset: 0x10
        uDDOModel* mpOwner;  // offset: 0x18
    };
public:
    class cReqIKInfo
    {
    public:
        void clear();
    public:
        bool mIsActive;  // offset: 0x0
        MtMatrix mEffector;  // offset: 0x10
        nIKCtrl::EFF_BEHAVIOR mBehavior;  // offset: 0x50
    };
public:
    class cWallJumpInfo
    {
    public:
        cWallJumpInfo();
        void clear(uHuman& owner);
    public:
        sCollision::TriangleInfo mTriInfo;  // offset: 0x0
        u32 mContact;  // offset: 0xd0
        bool mIsChecked;  // offset: 0xd4
        MtVector3 mMoveDir;  // offset: 0xe0
        bool mIsJumped;  // offset: 0xf0
    };
public:
    struct stAbilityVsEnemy
    {
    public:
        nEnemy::ENEMY_CATEGORY mEnemyCategory;  // offset: 0x0
        nAbility::ABILITY_ID mAbilityId;  // offset: 0x4
    };
public:
    struct stAbilitySkillUp
    {
    public:
        nAbility::ABILITY_ID mAbilityId;  // offset: 0x0
        u32 mAttackId;  // offset: 0x4
        nHuman::JOB_ENUM mJobId;  // offset: 0x8
        u32 mAbilityFlg;  // offset: 0xc
    };
public:
    class cHealSeCaller : public MtObject
    {
        // inferred: uHuman::callbackHealedAfter_apply_slave names uHuman::mHealSeCaller.mIsHp
        friend class uHuman;
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
        cHealSeCaller();
        virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
        void reset();
        void update(uHuman& owner);
        void requestHealSe(uHuman& owner);
        bool isHeal() const;
        void setIsHeal(bool flg);
        bool isStamina() const;
        void setIsStamina(bool flg);
    private:
        f32 mTimer;  // offset: 0x8
        u32 mSeNo;  // offset: 0xc
        bool mIsHp;  // offset: 0x10
        bool mIsStamina;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
public:
    class cLimitActCtrl : public MtObject
    {
    public:
        class MyDTI;
        struct stInfo;
    public:
        using LimitActList = nDDOUtility::cArray<uHuman::cLimitActCtrl::stInfo, 16>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stInfo
        {
        public:
            s32 mActID;  // offset: 0x0
            bool mIsLimited;  // offset: 0x4
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
        cLimitActCtrl();
        virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
        bool isLimited(s32 actID);
        void setLimitedActInfo(s32 actID, bool isLimited);
        void clearAll();
    private:
        LimitActList mLimitActList;  // offset: 0x8
    public:
        static MyDTI DTI;
        static const u32 LimitActNum = 16;
    };
public:
    class cBlendMotionCtrl : public MtObject
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
        cBlendMotionCtrl();
        virtual ~cBlendMotionCtrl();
        void setBlendMotion(uHuman& Owner, u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed, f32 endhokan);
        void cancelBlendMotion(uHuman& Owner);
        void update(uHuman& Owner);
        uModel::Motion* getBlendMotion(uHuman& Owner);
        bool getMotionParam(uHuman& Owner, u32& motNo, u32& attr, f32& frame, f32& speed);
        bool isMotionEnd() const;
        bool isActive() const;
    private:
        bool mIsMotionEnd;  // offset: 0x8
        bool mIsActive;  // offset: 0x9
        f32 mEndHokan;  // offset: 0xc
    public:
        static MyDTI DTI;
    private:
        static const u32 CTRL_BANK = 1;
    };
public:
    struct stEnchantInfo
    {
    public:
        u32 mEnchantColUID;  // offset: 0x0
        f32 mEnchantIntervalTime;  // offset: 0x4
        bool mEnchantArea;  // offset: 0x8
        bool mEnchantAreaOld;  // offset: 0x9
        bool mCanReEnchant;  // offset: 0xa
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
    uHuman();
    virtual ~uHuman();
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void callbackUpdateAfter();  // vtable slot 73
    virtual void moveAfter();  // vtable slot 10
    virtual void sync();  // vtable slot 11
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void resetPos(const MtVector3& pos);  // vtable slot 59
    virtual u32 getLODLevel(s32 dist);  // vtable slot 35
    void before();
    void update();
    void after();
    void callbackHpZero();
    virtual u32 actionConvert(u32 actNo);  // vtable slot 173
    virtual void setupContextParam();  // vtable slot 47
    virtual void setupBeforeContext(bool initSet);  // vtable slot 46
    void setContextCalcParam(bool initSet);
    virtual void setupContextEnemyClimb(bool recvFlag);  // vtable slot 52
    void setEnemyClimbPivot(const MtVector3& pivot);
    virtual void updateMatrix();  // vtable slot 71
    virtual void calcWorldMatrix(u32 mode, bool debug_disp, MtColor col);  // vtable slot 186
    virtual void updateWorldMatrix();  // vtable slot 26
    virtual void updateObjStatus();  // vtable slot 69
    virtual void checkKeyCmdFunc();  // vtable slot 72
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 74
    virtual void callbackReplaceHitInfo_Def(cHitInfo* pHitInfo);  // vtable slot 75
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 78
    virtual void callbackGuarded(cHitInfo* pHitInfo);  // vtable slot 79
    virtual void callbackGuard_make(cHitInfo* pHitInfo);  // vtable slot 100
    virtual void callbackGuard_calc(cHitInfo* pHitInfo);  // vtable slot 101
    virtual void callbackGuard_apply(cHitInfo* pHitInfo);  // vtable slot 102
    virtual void callbackDie(cUnitDieInfo& dieInfo);  // vtable slot 133
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 88
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 89
    void callbackMoveBegin();
    void callbackAfterUpdateMotion();
    virtual bool callbackHealedAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 98
    virtual bool callbackHealedAfter_apply_slave(cHitInfoAfter* pHitInfo);  // vtable slot 99
    virtual void makeHealedAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 147
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 91
    virtual void callbackDamageAfter_calcEnd(cHitInfoAfter* pHitInfo);  // vtable slot 94
    void damageJobAdj(cHitInfoAfter* pHitInfo);
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 95
    virtual void callbackFlick(cHitInfoAfter* pHitInfo);  // vtable slot 105
    virtual void callbackShrink(cHitInfoAfter* pHitInfo);  // vtable slot 106
    virtual void callbackBlow(cHitInfoAfter* pHitInfo);  // vtable slot 107
    virtual bool callbackShake(cHitInfoAfter* pHitInfo);  // vtable slot 109
    virtual void callbackQuake(cHitInfoAfter* pHitInfo);  // vtable slot 111
    virtual void callbackStorm(cHitInfoAfter* pHitInfo);  // vtable slot 110
    virtual bool isEnableStorm(cHitInfoAfter* pHitInfo);  // vtable slot 112
    virtual bool isEnableQuake(cHitInfoAfter* pHitInfo);  // vtable slot 113
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
    virtual void callbackAttackTest_ShlNotify(cHitInfo* pHitInfo);  // vtable slot 195
    virtual void callbackDamageTest(cHitInfo* pHitInfo);  // vtable slot 86
    virtual void callbackCaughtTest(cHitInfo* pHitInfo);  // vtable slot 122
    virtual void callbackWinTarget(cHitInfoAfter* pHitInfo);  // vtable slot 184
    virtual void callbackAttackEnd(cHitInfoAfter* pHitInfo);  // vtable slot 117
    void playAttackReaction(cHitInfoAfter* pHitInfo);
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual void callbackCatch(cHitInfo* pHitInfo);  // vtable slot 118
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo);  // vtable slot 119
private:
    void callbackCatch_Sub(const cAttackParam* pAttackParam, uDDOModel* pDfdModel, MtVector3& hitPos);
public:
    virtual void callbackHitLand();  // vtable slot 175
    virtual void callbackFall();  // vtable slot 176
    virtual void callbackAltitudeFall();  // vtable slot 177
    virtual void callbackAltitudeFallLand();  // vtable slot 178
    virtual void callbackCreateShl(uShlBase* pShl);  // vtable slot 168
    virtual void callbackLostEnd(bool setupFlag);  // vtable slot 136
    virtual void callbackRescue(u32 unitParam, u32 touchType);  // vtable slot 137
    void callbackOcdSeal();
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag);  // vtable slot 145
    void callbackExceptiveAirShrink(cHitInfoAfter* pHitInfo);
    virtual void callbackEquip(nCharacterData::EQUIP_SLOT_TYPE category, nCharacterData::EQUIP_TYPE type);  // vtable slot 196
    virtual void notifyDeleteShell(s32 work);  // vtable slot 68
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 143
    virtual bool callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom);  // vtable slot 144
    virtual void callbackBeginEvent();  // vtable slot 197
    virtual void hitInstantDeath(bool isFall, bool isWall);  // vtable slot 63
    virtual void setHugebleDeath();  // vtable slot 64
    virtual void initCharacterEdit();  // vtable slot 198
    void initCharacterEditCommon(rCharacterEdit* pRes);
    void updateCharacterEdit();
    void initBake();
    bool isBaked();
    void initIK();
    bool updateArmIK();
    void updateClimbIK();
    void calcSetSitEmoHandPos();
    virtual void initHeadCtrl();  // vtable slot 199
    virtual void updateHeadCtrl();  // vtable slot 200
    virtual void initLegCtrl();  // vtable slot 201
    virtual void updateLegCtrl();  // vtable slot 202
    virtual void initShakeCtrl();  // vtable slot 203
    virtual void updateShakeCtrl();  // vtable slot 204
    void requestIK(nIKCtrl::IK_TYPE ikType, const MtVector3& pos, f32 blendrate);
    void requestIK(nIKCtrl::IK_TYPE ikType, const MtMatrix& mat, f32 blendrate);
    void updateTargetCursorOffset();
    uDDOModel* getTouchSelectTarget() const;
    uDDOModel* getLastTouchTarget() const;
    void setIsCanDash(bool flag);
    bool isCanDash();
    bool isCanNowDash();
    void setIsCanMove(bool);
    bool isCanMove();
    bool isCanNowMove();
    void onFixSafePos();
    void offFixSafePos();
    void setIsCanRun(bool);
    bool isCanRun();
    bool isCanNowRun();
    bool isCanShlConst() const;
    void onCanShlConst();
    void offCanShlConst();
    void setIsAgainDash(bool flag);
    bool isAgainDash() const;
    void setSlipSlope(bool flag);
    bool isSlipSlope() const;
    void setIsAirCatchUse(bool flag);
    bool isAirCatchUse();
    void setIsDispErosionIcon(bool flag);
    bool isDispErosionIcon();
    void setIsActivedUkemi(bool);
    bool isIsActivedUkemi();
    bool isPoisonPond();
    bool isOilPond();
    bool isNowEmotion();
    bool isNowEmotionLoop();
    bool isContinuousCallEmotion(u32 ReqActNo);
    bool checkGuardCharge();
    bool checkClimbEndure();
    bool isFootWork() const;
    bool isLimitedHealingCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedAttackCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedDefenceCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedGuardBit(nKeyCommand::stGenericParam& param);
    bool isLimitedSoulFull(nKeyCommand::stGenericParam& param);
    bool isLimitedIronCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedSaintCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedSolaceCircle(nKeyCommand::stGenericParam& param);
    bool isLimitedBlastOption(nKeyCommand::stGenericParam& param);
    bool isCantBoostSpirit(nKeyCommand::stGenericParam& param);
    bool isNowBoosting(nKeyCommand::stGenericParam& param);
    bool isEnableTransUkemiAction(nKeyCommand::stGenericParam& param);
    bool isJob02Cs11End(nKeyCommand::stGenericParam& param);
    bool isDeleteAllCircle(nKeyCommand::stGenericParam& param);
    void checkEnableTransUkemi();
    bool checkCanCounter(cHitInfoAfter& HitInfo);
    bool isBattleModel();
    bool isBringOM();
    bool isInvolveOCDAction();
    void enableWpnNullInter(bool Inter);
    void callbackPreSetMotion(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
    void callbackfindwall(sCollision::TriangleInfo& info);
    void callbackfindcliff(sCollision::TriangleInfo& info);
    bool transWallClimb();
    bool transWallClimbSub(const sCollision::TriangleInfo& info, f32 height);
    bool transDashJumpCliff();
    void correctFallPreventionPos(const MtVector3& pos);
    virtual void callbackReqOcdEndAction(u32 actNo, nAction::ACT_PRIO priority);  // vtable slot 146
    bool isDamage() const;
    void setClimbEndureCancel(bool flag);
    bool isClimbEndureCancel();
    void requestClimbEnd();
    void requestVanishEffect(bool isOldPos);
    void moveLandActJudge();
    f32 getMoveRateInWater();
    bool isUseMoveRateInWate();
    bool isSessionLost();
    bool checkScrSafePos(const MtVector3& checkPos, const MtVector3& old, bool isCapsule);
    u16 getMainWepElementType();
    u16 getSubWepElementType();
protected:
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 70
public:
    void addSpecialEquipArray(uDDOModel* pMod);
    void eraceSpecialEquipArray(uDDOModel* pMod);
    void clearSpecialEquipArray();
    uDDOModel* getSpecialEquipArray(u32 index);
    u32 getSpecialEquipArrayLength();
    void addEnchantEquipArray(uJobEquip* pMod);
    void clearEnchantEquipArray();
    uJobEquip* getEnchantEquipArray(u32 index);
    u32 getEnchantEquipArrayLength();
    void addHealHate(f32 add);
    bool isBowAim() const;
    void setIsBowAim(bool flg);
    bool isBowAimUpWait() const;
    void setIsBowAimUpWait(bool flg);
    s32 getBowSkillType();
    u32 getCustomSkillIdFromBowSkillType(u32 skillType, sPadExt::PAD_BTN_TYPE* pBtn);
    bool isPawnCanShot() const;
    void setIsPawnCanShot(bool flg);
    u32 getBowCustomId() const;
    void setBowCustomId(u32 id);
    bool isDispAimSight();
    void setIsDispAimSight(bool flg);
    bool isHittingShortCharge();
    void setIsHittingShortCharge(bool flg);
    bool isRescuing();
    void setIsRescuing(bool flg);
    bool isFinishBlow();
    void setIsFinishBlow(bool flg);
    void setEmotionTimer(f32 val);
    f32 getEmotionTimer();
    void setCliffDisableTimer(f32 time);
    void setIsTouchTypeNone(bool flg);
    void checkOcdTouchTypeFromRecoverDC();
    void startStraightAutoRun();
    void startHomingAutoRun(uDDOModel* pTarget);
    void requestStraightAutoRun();
    void requestHomingAutoRun(uDDOModel* pTarget);
    bool isCanHomingAutoRun();
    void cancelAutoRun();
    bool isAutoRun();
    void LimitAutoRun();
    void unLimitAutoRun();
    void setupStraightAutoRun();
    const uDDOModel* getAutoRunTarget() const;
    bool isEnableNormalJump() const;
private:
    void checkRequestIK();
    void setupIKEffectorSimple(nIKCtrl::IK_TYPE ikType);
    void deleteAllCircle();
    void deleteHealingCircle();
    void deleteAttackCircle();
    void deleteDefenceCircle();
    void deleteGuardBit();
    void deleteSoulFull();
    void deleteIronCircle();
    void deleteSaintCircle();
    void deleteSolaceCircle();
    void deleteBlastOption();
    void dispNoSpirit();
    void endReqJobSpecial();
    void deleteJob02cs11();
    void startBlowUKEMIAcsept();
    void checkTransEngetsuGiri();
    void checkOnDefaultTouchType();
public:
    void setDrawingSword(bool flg);
    bool isActDrawingSword() const;
    void setIsActDrawingSword(bool flg);
    void backupCommandTblList();
    void recoverCommandTblList();
    void actLimitItemMode(bool isLimit);
    bool cheakNearGround();
    void searchCorepoint(cHitInfo* pHitInfo);
    bool isCorepoint(cHitInfo* pHitInfo, nRegionStatus::CORE_POINT_TYPE coreType);
    void setBowUpperEnable(const bool enable);
    bool isBowUpperEnable() const;
    void setBowUpperDir(const MtVector3& dir);
    const MtVector3& getBowUpperDir();
    void setTurnUpperEnable(const bool enable);
    bool isTurnUpperEnable() const;
    void setTurnUpperDir(const MtVector3& dir);
    const MtVector3& getTurnUpperDir();
    void clearTurnUpperInfo();
    void setTurnUpperSpeed(const f32 speed);
    bool isCliffHang() const;
    bool isCliffClimb() const;
    void setIsCliffClimb(bool flg);
    bool isCliffClimbShort() const;
    void setIsNoGuardedHajikare(bool flg);
    bool isNoGuardedHajikare() const;
    void setIsNoStorem(bool flg);
    bool isNoStorm() const;
    void setIsNoQuake(bool flg);
    bool isNoNoQuake() const;
    void setIsObjPushOff(bool flg);
    void setDashTurnDir(const MtVector3& dir);
    MtVector3 getDashTurnDir() const;
    void setIsPhotoModeDisable(bool flag);
    bool isPhotoModeDisable() const;
    bool isOldCommonWork(u16);
    bool isOldCustomWork(u16 work);
    void checkCancellableAction();
    bool isCancellableAction();
    bool isCanCustomCancelAction();
    bool isCanUseSCM();
    void setIsBeforeAttackHit(bool flg);
    bool isBeforeAttackHit();
    void setIsBeforeGuarded(bool flg);
    bool isBeforeGuarded();
    void setIsCanNextCustmSkillLevel(bool flg);
    bool isCanNextCustmSkillLevel() const;
    void setIsRecevedDamage(bool flg);
    bool isRecevedDamage();
    bool isTiring();
    void setIsCanSetEmotion(bool flg);
    bool isCanSetEmotion();
    void setStopStaminaRecoverFlg(bool flg);
    bool isStopStaminaRecoverFlg();
    void setIsForceEndTraceAutoRun(bool flg);
    bool isForceEndTraceAutoRun() const;
    void setSex(const u32 sex);
    u32 getSex() const;
    nHuman::JOB_ENUM getJob() const;
    u32 getJobIndex() const;
    void setInitJob(nHuman::JOB_ENUM);
    void setJobChange(const nHuman::JOB_ENUM job, bool isCsSet);
    nHuman::HUMAN_JOB_ROLE getJobRole();
    bool isMeleeJob();
    void createEquipUnit();
    void createWeaponUnit();
    void createArmorUnit();
    void createGunUnit();
    void createEquipUnit(const cContextInstHm* pContext);
    void createWeaponUnit(const cContextInstHm* pContext);
    void createArmorUnit(const cContextInstHm* pContext);
    void createGunUnit(const cContextInstHm* pContext);
    void updateWaterEff();
    nHuman::HM_SKILL_LV getCustomSkillLv(const nHuman::CUSTOM_SKILL_ENUM id) const;
    nHuman::HM_SKILL_LV getCustomSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::CUSTOM_SKILL_ENUM id) const;
    void setCustomSkillLv(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void setCustomSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::CUSTOM_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    nHuman::HM_SKILL_LV getNormalSkillLv(const nHuman::GROW_NORMAL_SKILL_ENUM id) const;
    nHuman::HM_SKILL_LV getNormalSkillLvJob(const nHuman::JOB_ENUM, const nHuman::GROW_NORMAL_SKILL_ENUM) const;
    void setNormalSkillLv(const nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void setNormalSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void setCustomSkillPalletL(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group);
    void setCustomSkillPalletR(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group);
    nHuman::CUSTOM_SKILL_ENUM getCustomSkillPalletL(nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group) const;
    nHuman::CUSTOM_SKILL_ENUM getCustomSkillPalletR(nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group) const;
    void setAbilityLevel(u32, u32);
    u32 getAbilityLevel(u32);
    u32 getCustomEffectEpvIndex(nHuman::CUSTOM_SKILL_ENUM skillID);
    cpJobBase* getJobComponent() const;
    bool getCustomSkillPalletFromSkillID(const nHuman::CUSTOM_SKILL_ENUM skillID, nHuman::CUSTOM_SKILL_PALLET& palletNo, bool& isRightPallet);
    void setComParam(rAdjustParam* pParam);
    void setJobParam(rAdjustParam* pParam);
    f32 getComAdjustParam(u32 index) const;
    f32 getJobAdjustParam(u32 index) const;
    void setStaminaDecTbl(u32 bank, rStaminaDecTbl* pParam);
    cStaminaDecList* getStaminaDecList(u32 bank, u32 tblIndex) const;
    bool requestStaminaUpdate(nHuman::STMN_TBL_BANK bank, u32 listIndex, u32 paramIndex, bool isDeltaTime);
    void setJumpParamTbl(u32 bank, rJumpParamTbl* pParam);
    void setJumpParam(u32 bank, u32 JumpParamIndex);
    cJumpParam* getJumpParam();
    void setMagicChantParam(rMagicChantParam* pParam);
    rMagicChantParam* getMagicChantParam() const;
    void deleteMagicChantParam();
    s32 getClimbJointNo() const;
    void setClimbJointNo(const s32 no);
    u32 getClimbEnemyUId() const;
    void setClimbEnemyUId(const u32 id);
    const MtVector3& getClimbJointOffset() const;
    void setClimbJointOffset(const MtVector3& offset);
    u16 getClimbNodeIndex() const;
    void setClimbNodeIndex(u16 NodeIndex);
    u16 getClimbGeomIndex() const;
    void setClimbGeomIndex(u16 GeomIndex);
    uDDOModel* getClimbEnemy() const;
    void setClimbEnemy(uDDOModel* pmod);
    void initEnemyClimbInfo();
    cEnemyClimbInfo* getEnemyClimbInfo();
    bool isTrodden() const;
    void setTrodden(bool isTrodden);
    f32 getTroddenAngleY() const;
    void setTroddenAngleY(f32);
    bool checkCliffHang();
    bool checkClimbWall();
    bool checkCndCliffClimb();
    bool checkCndCliffFall();
    bool checkCndNotDash();
    bool checkCndWallClimbStart();
    bool checkCndEvasionEnable();
    u32 checkCndJoltGrade();
    void checkSlipSlope();
    void checkWaterResist();
    bool checkCndEnableDelayCombo() const;
    bool checkCndButtonNagaoshi(u32 inputType) const;
    bool checkSkillLevel(s32 ActNo, nHuman::HM_SKILL_LV skillLv) const;
    bool checkSecondJump(s32 ActNo) const;
    bool checkWallJump(s32 ActNo);
    bool checkWallJumpAction(u32 ActNo);
    bool checkGuardModeCancel();
    bool checkEnableMenuUIAct();
    bool cheackCanReqOcd(u32 id);
    virtual void effectCondistionFromScr();  // vtable slot 183
    virtual void setMaster(bool is_master);  // vtable slot 66
    void setMotionSeResource(rSoundRequest* pResource, u32 motSeType);
    void setCustomSkillData();
    void setCstmMotionList(nHuman::CUSTOM_SKILL_ENUM skillID);
    void resetCstmMotionList();
    void setCstmMotionListJobBank2(nHuman::CUSTOM_SKILL_ENUM skillID);
    void resetCstmMotionListJobBank2();
    bool isSetCstmMotionList(nHuman::CUSTOM_SKILL_ENUM skillID);
    void setCstmCollision(nHuman::CUSTOM_SKILL_ENUM skillID);
    void resetCstmCollision();
    void setCstmMotionSe(nHuman::CUSTOM_SKILL_ENUM skillID);
    rSoundRequest* getCstmMotionSe(nHuman::CUSTOM_SKILL_ENUM skillID);
    void resetCstmMotionSe();
    rSoundRequest* getCommonShlSe();
    rSoundRequest* getCstmShlSe(nHuman::CUSTOM_SKILL_ENUM skillID);
    rAttackParam* getCustomSKillAttackParam(nHuman::CUSTOM_SKILL_ENUM skillID);
    void moveTouchStart();
    void moveTouchEnd();
    bool checkTouch(bool bChkInput) const;
    bool checkReleaseTouch();
    void moveTouchCheckEnableTarget();
    void moveTouchChangeTarget();
    void requestTouchReleaseEventEnd();
    void callbackGatherEnd();
    void selectPawnTouchTarget(cHitInfo* pHitInfo);
    MtVector3 getCameraExPos() const;
    void setCameraExPos(const MtVector3& pos);
    uJobEquip* getWireModel() const;
    bool isTouchActStop() const;
    bool isTouchNow() const;
    bool checkSeqCntMotionEnd(u32 type);
    bool isPawnTouchEnableTarget(uDDOModel* pTarget);
    bool isNpcTouchEnableTarget(uDDOModel* pTarget);
    bool isHajikareNow() const;
    bool isGuardBreakNow() const;
    void setVanishEffect(nHuman::VANISH_EFFECT effectType);
    nHuman::VANISH_EFFECT getVanishEffect();
    void callVanishEffect(nHuman::VANISH_EFFECT effectType);
    void setFingerMotion();
    void setBaseAtMotion(rMotionList* pMot);
    void setBaseAtMotion2(rMotionList* pMot);
    void setBaseAtMotionParam(rMotionParam* pMotParam);
    void setIsOmTiming(bool flg);
    bool getIsOmTiming();
private:
    virtual bool checkCalc(const cAttackParam* pAtkParam);  // vtable slot 172
    bool isNowJobCompEnable() const;
    void calcWhiteGage(cHitInfoAfter* pHitInfo);
public:
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 149
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 150
    void makeAdjustDownChanceCommon(cHitInfoAfter* pInfo);
    virtual void makeDamageDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 151
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 152
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 156
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    void makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo);
    void makeOcdWepAttackInfo(cHitInfoAfter* pHitInfo);
    void makeOcdAttackInfoCore(cOcdDamageInfo& ocdDamageInfo, cEquipData& equipData, rItemList::rItemParam& item, nCharacterData::EQUIP_SLOT_TYPE category);
    virtual void makeOcdDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 157
    void decideAttacklElemnt(cHitInfoAfter* pHitInfo);
    void decideAttacklElemntCore(cOcdDamageInfo& ocdDamageInfo, const cAttackParam& AttackParam);
    void decideGuardAttacklElemnt(cOcdDamageInfo& ocdDamageInfo, const cAttackParam& AttackParam, uDDOModel* pAttacker);
    u16 getEquipID(nCharacterData::EQUIP_SLOT_TYPE category, nCharacterData::EQUIP_TYPE type);
    virtual void makeGuardAttackInfo(cHitInfo* pHitInfo);  // vtable slot 158
    virtual void makeGuardDefenceInfo(cHitInfo* pHitInfo);  // vtable slot 159
    f32 calcStaminaDamage(const cHitInfo* pHitInfo) const;
    virtual void makeHitSeInfo_Attack(cDamageSeInfo* pSeInfo);  // vtable slot 163
    virtual bool healHp(HP_DATATYPE healHp, bool isWhiteHeal, u32 regionNo);  // vtable slot 170
    void healStaminaItem(f32 healStamina);
    virtual void applyHealVisual(cHitInfoAfter* pHitInfo, nObjCollision::CALC_DAMADE_MODE* mode);  // vtable slot 161
    void adjustAbilityUpdate();
    void adjustAbilityDamageAttackInfo(cHitInfoAfter* pHitInfo);
    void adjustAbilityDamageDefenceInfo(cHitInfoAfter* pHitInfo);
    void adjustAbilityElementAttackInfo(cHitInfoAfter* pHitInfo);
    void adjustAbilityHealAttackInfo(cHitInfoAfter* pHitInfo);
    void setTakeSpa(bool take);
    bool isTakeSpa() const;
    void setTakeHealHPSpa(bool take);
    bool isTakeHealHPSpa() const;
    void setTankerTargetedByEnemy();
    bool getTankerIsTargetedByEnemy();
    bool getTankerIsTargetedByEnemyOld();
    u32 getActionLoopNum() const;
    void setActionLoopNum(u32 num);
    cContextPlayerInfo* getContextPlayerInfo() const;
    void resetContext();
    bool isLimitedAction(s32 actID);
    void setLimitedActInfo(s32 actID, bool isLimited);
    void setBlendMotion(u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed, f32 endhokan);
    uModel::Motion* getBlendMotion();
    void cancelBlendMotion();
    bool getBlendMotionParam(u32& motNo, u32& attr, f32& frame, f32& speed);
    bool isBlendMotionEnd() const;
    bool isBlendMotionActive() const;
    cStaminaCtrl& getStaminaCtrl();
    void initInstantDeath();
    void startInstantDie();
    void startHugeble();
    void initBaphometWarp();
    void startBaphometWarp();
    void reqBaphometWarpEffect(const MtVector3& ef_pos, const bool is_start);
    void requestBaphometWarp(const MtVector3& tar_pos, const f32& tar_angle, bool is_come_back);
    void callbackWarpInStage();
    void startChangeTrp(f32 initTrp, f32 endTrp, f32 frame);
    void startChangeTrp(f32 endTrp, f32 frame);
    void setTrp(f32 trp);
    bool isActiveTrp();
    void callEffectUseHealItem();
    void resetRotationY();
    void setScrCapsuleWallClimb();
    void resetScrCapsule();
    void involvedCondition(u32 condition, bool isCatch, u8 type, cShlConditionInfo coninfo);
    void setEnemyClimbJoltType(CLIMB_JOLT_TYPE type);
    CLIMB_JOLT_TYPE getEnemyClimbJoltType() const;
    bool requestThrowItem(u32 id, MT_CTSTR uid);
    bool isItemMode() const;
    void onItemMode();
    void offItemMode();
    uModel* getItemModel() const;
    MT_CTSTR getNowThrowItemUId() const;
    MT_CTSTR getThrowItemUId() const;
    u32 getThrowItemId() const;
    void changeCommandItemTbl();
    void releaseItemModel();
    void setThrowItemId(u32 itemID);
    void createItemOmModel();
private:
    void moveFallInstantDie();
    void moveInstantDie();
    void moveHugeble();
    void moveGoldWarp();
    void moveInsuranceWarp();
    void setSafePosDie();
    void setSafePosDown();
    void setSafePosFootWork();
    void checkItemMode();
    void checkSafeZone();
    void checkDeadConsistency();
    void checkStaminaOut();
    void moveBaphometWarp();
    void moveCliffFallCheck();
    void updateEnchantColInfo();
    void updateEnchantColInfoCore(u32 i);
    bool registerEnchantUid(u32 uid, f32 interval_time);
public:
    bool isActiveBitEffect(u32 i);
    f32 getCircleShiftTimer();
    void updateCircleBit();
    void killCircleBit(u32 id);
    void reqCircleBitShell(u8 type);
    u32 getActiveShiftCircleValue(u32 id);
    void killOcdImuneEfct(u32 id);
    bool cheackActiveCircleBit(u32 type);
    void addActiveCircleBit(u32 type);
    void reduceActiveCircleBit(u32 type);
    void clearActiveCircleBit();
    void checkLadder(uDDOModel* pLadder, u16 uid);
    bool isSafeZone() const;
    bool isSafeZoneOld() const;
    void requestHumanCommonEffect(u32 index, u32 element);
    void requestJustEffect();
    void resetZoneState();
    void addZoneState(nHuman::HUMAN_ZONE_STATE state);
    bool checkZoneState(nHuman::HUMAN_ZONE_STATE state);
    void setShellBloodOrb(const MtVector3& pos);
    bool checkOcdActConsistency(u32 ocdId);
    void setIsCliffCheckAct(bool flg);
    void setIsCliffCheckNoMove(bool flg);
    virtual void setTouch(uDDOModel* pUnit, bool isTouchSave);  // vtable slot 166
    void setPawnTalkTouch(uDDOModel* pReqOwner);
    f32 getCliffPivotOffsetY();
    f32 getWallClimbCheckHeight();
    f32 getWallClimbPivotOffsetY();
    f32 getHeightScaleRate();
    f32 getHeightScaleValue();
    void onLandActJudge();
    void callLevelUpDraw(u32 level);
    void setEndDieAction();
    void requestHumanHighPriorityAction(u32 actNo);
    bool isClosePosCheck();
    rModel* getRPickel();
    rModel* getRAxa();
    bool isShotDead();
    void setShotDead(bool flg);
    bool isUseLockOn();
    void setUseLockOn(bool flg);
    bool getForwardLeg();
    bool isUsingDamageProtect();
    void onUsingDamageProtect();
    void offUsingDamageProtect();
    void setDamageProtectPercent(f32 per);
    bool isMagicShotting();
    void setMagicShotting(bool flg);
    bool isLockOnTarget();
    void setIsLockOnTarget(bool flg);
    cGeneralPointPtr getMagicTarget();
    void setMagicTarget(cGeneralPointPtr tgt);
private:
    void LeadToInvincible();
public:
    void setInvincibleTime(f32 time);
    void addInvincibleTime(f32 time);
    f32 getInvincibleTime() const;
    u32 convertJobCommonMotion(u32 motNo, bool isBattle);
    bool isEventEndWaitSet();
    bool isEventBusy() const;
    void setIsBowJumpEnable(bool flg);
    bool isBowJumpEnable() const;
    bool isBowUpActUpdate();
    nHumanBow::stNetData popBowUpNetData();
    void pushBowUpNetData(const nHumanBow::stNetData& d);
    void pushBowLockOnInfo(u32 index, u32 uid, u32 lockId);
    bool isBowLowActUpdate();
    nHumanBow::stNetData popBowLowNetData();
    void pushBowLowNetData(const nHumanBow::stNetData& d);
    bool isBowPeriodUpdate();
    nHumanBow::stNetData popBowPeriodNetData();
    void pushBowPeriodNetData(const nHumanBow::stNetData& d);
    const MtVector3& getBowNetAimPos();
    void setBowNetAimPos(const MtVector3& pos);
    f32 getBowMoveRadian();
    void setBowMoveRadian(f32 rad);
private:
    bool checkCndCliffHang();
public:
    void setActionWorkFlag(bool flag);
    void clearActionWorkFlag();
    bool getActionWorkFlag() const;
    bool isCustomSync() const;
    void onCustomSync();
    void offCustomSync();
protected:
    virtual void draw(cDraw* pDraw);  // vtable slot 12
public:
    bool isCanJob09FrightBoardAir() const;
    bool isCanJob09FrightBoardLand() const;
    void setJob09FrightBoardAir();
    void setJob09FrightBoardLand();
    bool isJob09FrightBoardAir() const;
    nHuman::HM_SKILL_LV getFrightBoardLv() const;
    void countupJob09FrightBoardAir();
    u32 getJob09AirFrightBoardCount() const;
    uShlBase* getFrightBoard() const;
    bool checkSupJob10InParty();
    bool isBakeWep() const;
    s32 getBakeWepEnchantEffecyJoint() const;
    void setBakeWepEnchantFinish(bool flg);
    bool isBakeWepEnchantFinish() const;
private:
    void updateBakeWepEnchant();
public:
    void requestUseStaminaItem();
    bool isUseStaminaItem() const;
private:
    void updateAwakeningBracelet();
public:
    bool isAwakeningActive(nDDOModel::AWAKENING_BRACELET_TYPE type);
    void setDeadEffect();
    void endDeadEffect();
    void updateDeadEffectPos();
    cEfcHandle* getDeadEffectHandle() const;
    void requestCraftEnchantMode(uDDOModel* pTarget, bool isForceMain);
    void connectCraftEnchantMode();
private:
    f32 getCheckCheatInvTime() const;
    void setCheckCheatInvTime(f32 NewValue);
    void checkCheatInvTime();
    f32 getCheckCheatAddVelTime() const;
    void setCheckCheatAddVelTime(f32 NewValue);
    void checkCheatAddVelocity();
public:
    f32 getCheckCheatChageNow_Gi() const;
    void setCheckCheatChageNow_Gi(f32 NewValue);
    void checkCheatChageBefore();
    void checkCheatChageUpdateAfter();
    void checkCalcCharge();
    void setPawnEscapeInvincible();
    bool isCsChanging();
    void requestChangeCS();
    void requestChangeCSSlave(const nHuman::CUSTOM_SKILL_GROUP group);
    void requestLoadCSSlave();
    void requestChangeCSGUIPreDisp();
    bool isCanCsChangeAction();
private:
    void updateCsChange();
    void updateCsChangeSubKeyCommand();
    void updateCsChangeSubProg();
    void updateCsChangeSubGUI();
public:
    bool isReceiveErosionRescue() const;
    void setReceiveErosionRescue(bool flg);
    void setErosionRescueTimer(f32);
    const MtVector3& getStartErosionRescueDir();
    void clearNeedErosionRespawnTime();
    f32 getNeedErosionRespawnTime();
    f32 getMaxErosionRespawnTimer();
    u32 getJobErosionRescueCost();
    void setupErosionRescue();
    void moveRecoverErosion();
    bool isErosionRescuing();
    void setErosionIsRescuing(bool flg);
    bool isNowErosion();
    bool checkSetErosionTouch();
    void requestOneWayWarp(const MtVector3& realPos, const f32 angle);
    const cpHumanWarpCtrl* getHumanWarpCtrl();
    bool isCanOpenGameMenu() const;
    bool isDashAction() const;
    void requestSafePosSetLand();
protected:
    u32 mSex;  // offset: 0x265c
    bool mIsDamage;  // offset: 0x2660
    u32 mClimbEnemyUId;  // offset: 0x2664
    s32 mClimbJointNo;  // offset: 0x2668
    MtVector3 mClimbJointOffset;  // offset: 0x2670
    u16 mClimbNodeIndex;  // offset: 0x2680
    u16 mClimbGeomIndex;  // offset: 0x2682
    bool mIsExecuteTouch;  // offset: 0x2684
    bool mIsSelectNpcOm;  // offset: 0x2685
    bool mIsSelectPtm;  // offset: 0x2686
    bool mIsTouchTypeNone;  // offset: 0x2687
    uDDOModel* mpTouchSelectTarget;  // offset: 0x2688
    uDDOModel* mpLastTouchTarget;  // offset: 0x2690
    MtTypedArray<uDDOModel> mTouchArray;  // offset: 0x2698
    MtTypedArray<uDDOModel> mTouchNpcOmArray;  // offset: 0x26b8
    MtTypedArray<uDDOModel> mTouchPtmArray;  // offset: 0x26d8
    f32 mTouchLength;  // offset: 0x26f8
    f32 mEmotionTimer;  // offset: 0x26fc
    f32 mOcdFromScrShakeTimer;  // offset: 0x2700
    u32 mBowCustomId;  // offset: 0x2704
    bool mIsActDrawingSword;  // offset: 0x2708
    bool mIsCanMove;  // offset: 0x2709
    bool mIsCanMoveOld;  // offset: 0x270a
    bool mIsCanRun;  // offset: 0x270b
    bool mIsCanRunOld;  // offset: 0x270c
    bool mIsCanDash;  // offset: 0x270d
    bool mIsCanDashOld;  // offset: 0x270e
    bool mIsAgainDash;  // offset: 0x270f
    bool mIsSlipSlope;  // offset: 0x2710
    bool mIsBowAim;  // offset: 0x2711
    bool mIsBowAimUpWait;  // offset: 0x2712
    bool mIsPawnCanShot;  // offset: 0x2713
    bool mIsDispAimSight;  // offset: 0x2714
    bool mIsFinishBlow;  // offset: 0x2715
    bool mIsFixSafePos;  // offset: 0x2716
    bool mIsCanShlConst;  // offset: 0x2717
    bool mIsAirCatchUse;  // offset: 0x2718
    bool mIsOmTiming;  // offset: 0x2719
    bool mIsEnableClimbEndureCancel;  // offset: 0x271a
    bool mIsHittingShortCharge;  // offset: 0x271b
    bool mIsRescuing;  // offset: 0x271c
    bool mIsDispErosionIcon;  // offset: 0x271d
    bool mIsActivedUkemi;  // offset: 0x271e
    bool mIsPoisonPond;  // offset: 0x271f
    bool mIsOilPond;  // offset: 0x2720
    MtVector3 mCameraExPos;  // offset: 0x2730
    MtVector3 mDashTurnDir;  // offset: 0x2740
    MtVector3 mWarpBeforePos;  // offset: 0x2750
    bool mIsOldEnableUI;  // offset: 0x2760
    f32 mUICloseJumpTimer;  // offset: 0x2764
    f32 mMoveRateInWater;  // offset: 0x2768
    bool mIsUseMoveRateInWate;  // offset: 0x276c
    u32 mFrameDamageCnt;  // offset: 0x2770
    HP_DATATYPE mHpDamageCalcHp;  // offset: 0x2778
    nDDOUtility::cArray<float, 5> mFrameDamageHistory;  // offset: 0x2780
    f32 mOldLeverSpeed;  // offset: 0x2794
    cEnemyClimbInfo mEnemyClimbInfo;  // offset: 0x27a0
    rAdjustParam* mprComParam;  // offset: 0x2a50
    rAdjustParam* mprJobParam;  // offset: 0x2a58
    uDDOModel* mpClimbEnemy;  // offset: 0x2a60
    bool mIsTrodden;  // offset: 0x2a68
    f32 mTroddenAngleY;  // offset: 0x2a6c
    MtVector3 mOldJnt0Pos;  // offset: 0x2a70
    MtVector3 mOldJnt08Pos;  // offset: 0x2a80
    MtVector3 mOldJnt12Pos;  // offset: 0x2a90
    f32 mWaterRippleTimer;  // offset: 0x2aa0
    f32 mWaterDobonWpTimer;  // offset: 0x2aa4
    f32 mCliffDisableTimer;  // offset: 0x2aa8
    nHuman::VANISH_EFFECT mVanishEffectType;  // offset: 0x2aac
    UkemiInfo mUkemiInfo;  // offset: 0x2ab0
    MtTypedArray<uDDOModel> mSpecialEquipArray;  // offset: 0x2ac0
    MtTypedArray<uJobEquip> mEnchantEquipArray;  // offset: 0x2ae0
public:
    cpCharacterEdit* mpCharacterEdit;  // offset: 0x2b00
    cpMotionFilter* mpMotionFilter;  // offset: 0x2b08
    cpHmHeadCtrl* mpHmHeadCtrl;  // offset: 0x2b10
    cpBakeJointHuman* mpBakeJoint;  // offset: 0x2b18
    cpTransparencyCtrl* mpTransparencyCtrl;  // offset: 0x2b20
    cpItemThrow* mpItemThrow;  // offset: 0x2b28
private:
    uCnsBowUpper mCnsBowUpper;  // offset: 0x2b30
    uCnsTurnUpper mCnsTurnUpper;  // offset: 0x2c20
    cAutoRunInfo mAutoRunInfo;  // offset: 0x2d20
    bool mIsForceEndTraceAutoRun;  // offset: 0x2d40
    InfoArray mReqIKInfo;  // offset: 0x2d50
public:
    cpChantCommand* mpChantCommand;  // offset: 0x2f30
    cpJob01* mpJob01;  // offset: 0x2f38
    cpJob02* mpJob02;  // offset: 0x2f40
    cpJob03* mpJob03;  // offset: 0x2f48
    cpJob04* mpJob04;  // offset: 0x2f50
    cpJob05* mpJob05;  // offset: 0x2f58
    cpJob06* mpJob06;  // offset: 0x2f60
    cpJob08* mpJob08;  // offset: 0x2f68
    cpJob07* mpJob07;  // offset: 0x2f70
    cpJob09* mpJob09;  // offset: 0x2f78
    cpJob10* mpJob10;  // offset: 0x2f80
    cpKeyCommand* mpKeyCommand;  // offset: 0x2f88
    nDDOUtility::cArray<nKeyCommand::stKeyCommand*, 4> mCommandTblList;  // offset: 0x2f90
    sItemManager::cItemBag* mpItemBag;  // offset: 0x2fb0
    cWallJumpInfo mWallJumpInfo;  // offset: 0x2fc0
private:
    u16 mOldCommonWork;  // offset: 0x30c0
    u16 mOldCustomWork;  // offset: 0x30c2
    bool mIsTouchActStop;  // offset: 0x30c4
    bool mIsCliffHang;  // offset: 0x30c5
    bool mIsCliffClimb;  // offset: 0x30c6
    bool mIsCliffClimbShort;  // offset: 0x30c7
    bool mIsCancellableAction;  // offset: 0x30c8
    bool mIsBeforeAttackHit;  // offset: 0x30c9
    bool mIsBeforeGuarded;  // offset: 0x30ca
    bool mIsNoGuardedHajikare;  // offset: 0x30cb
    bool mIsNoStorm;  // offset: 0x30cc
    bool mIsNoQuake;  // offset: 0x30cd
    bool mCanNextCustmSkillLevel;  // offset: 0x30ce
    bool mIsRecevedDamage;  // offset: 0x30cf
    bool mIsTiring;  // offset: 0x30d0
    bool mIsCanSetEmotion;  // offset: 0x30d1
    bool mIsObjPushOff;  // offset: 0x30d2
    bool mStopStaminaRecoverFlg;  // offset: 0x30d3
    bool mIsPhotoModeDisable;  // offset: 0x30d4
public:
    nDDOUtility::cArray<cpJobBase*, 10> mJobCompArray;  // offset: 0x30d8
    rMagicChantParam* mprMagicChantParam;  // offset: 0x3128
protected:
    rMotionList* mpBaseAtMotionList;  // offset: 0x3130
    rMotionList* mpBaseAtMotionList2;  // offset: 0x3138
    rMotionParam* mpBaseAtMotionParam;  // offset: 0x3140
    nDDOUtility::cArray<rMotionList*, 4> mpCstmSkillMotionList;  // offset: 0x3148
    nDDOUtility::cArray<rMotionList*, 4> mpCstmSkillMotionList2;  // offset: 0x3168
    nDDOUtility::cArray<rMotionParam*, 4> mpCstmSkillMotionParam;  // offset: 0x3188
    nDDOUtility::cArray<rObjCollision*, 4> mpCstmSkillCollisonList;  // offset: 0x31a8
    nDDOUtility::cArray<rAttackParam*, 4> mpCstmSkillAtkParamList;  // offset: 0x31c8
    nDDOUtility::cArray<rSoundRequest*, 4> mpCstmSkillMotionSeList;  // offset: 0x31e8
    nDDOUtility::cArray<rStaminaDecTbl*, 2> mprStaminaDecTbl;  // offset: 0x3208
    cStaminaCtrl mStaminaCtrl;  // offset: 0x3218
    nDDOUtility::cArray<rJumpParamTbl*, 2> mpJumpParamTbl;  // offset: 0x3400
    cJumpParam mJumpParam;  // offset: 0x3410
    cContextPlayerInfo* mpContextPlayerInfo;  // offset: 0x3440
public:
    cDelegate_1<void, uDDOModel*> delegateGuard;  // offset: 0x3448
    f32 mAbiId0163Interval;  // offset: 0x3460
private:
    u32 mActionLoopNum;  // offset: 0x3464
protected:
    cHealSeCaller mHealSeCaller;  // offset: 0x3468
private:
    cLimitActCtrl mLimitActCtrl;  // offset: 0x3480
    cBlendMotionCtrl mBlendMotionCtrl;  // offset: 0x3508
    bool mIsInstantDeath;  // offset: 0x3518
    bool mIsInstantDeathFall;  // offset: 0x3519
    f32 mInstantDeathFallTimer;  // offset: 0x351c
    f32 mInsuranceTimer;  // offset: 0x3520
    u32 mInstantDieRno;  // offset: 0x3524
    u32 mHugebleRno;  // offset: 0x3528
    u32 mGoldWarpRno;  // offset: 0x352c
    u32 mBaphometWarpRno;  // offset: 0x3530
    f32 mBaphometWarpTime;  // offset: 0x3534
    MtVector3 mBaphometWarpPos;  // offset: 0x3540
    f32 mBaphometWarpAng;  // offset: 0x3550
    bool mFlgBaphmetWarpComeBack;  // offset: 0x3554
    bool mIsCliffCheckAct;  // offset: 0x3555
    bool mIsCliffCheckNoMove;  // offset: 0x3556
    f32 mHumitodomariTimer;  // offset: 0x3558
    bool mIsSafeZone;  // offset: 0x355c
    bool mIsSafeZoneOld;  // offset: 0x355d
    rModel* mprModPickel;  // offset: 0x3560
    rModel* mprModAxa;  // offset: 0x3568
    bool mIsArrowDisp;  // offset: 0x3570
    bool mIsLandActJudge;  // offset: 0x3571
    bool mIsShotDead;  // offset: 0x3572
    bool mIsUseLockOn;  // offset: 0x3573
    bool mIsLockOnTarget;  // offset: 0x3574
    bool mIsMagicShotting;  // offset: 0x3575
    cGeneralPointPtr mMagicTarget;  // offset: 0x3578
    bool mIsUsingDamageProtect;  // offset: 0x3588
    f32 mDamageProtectPercent;  // offset: 0x358c
    CLIMB_JOLT_TYPE mClimbJoltType;  // offset: 0x3590
    f32 mInvincibleTime;  // offset: 0x3594
    f32 mAbility227EffTime;  // offset: 0x3598
    bool mIsTakeSpa;  // offset: 0x359c
    bool mIsTakeHealHPSpa;  // offset: 0x359d
    bool mIsTakeHealHPSpaOld;  // offset: 0x359e
    f32 mSpaHealInterval;  // offset: 0x35a0
    bool mIsJob05CS11InArea;  // offset: 0x35a4
    bool mIsJob05CS11InAreaOld;  // offset: 0x35a5
    u32 mZoneState;  // offset: 0x35a8
    nDDOUtility::cArray<stEnchantInfo, 16> mEnchantColList;  // offset: 0x35ac
    s32 mEnchaColUidListIndex;  // offset: 0x366c
    s32 mEnchaColUidListBottom;  // offset: 0x3670
    f32 mCircleCount;  // offset: 0x3674
    nDDOUtility::cArray<unsigned int, 8> mActiveCircleCount;  // offset: 0x3678
    nDDOUtility::cArray<bool, 8> mIsActiveBitEffect;  // offset: 0x3698
    bool mIsActiveBitRangeEffect;  // offset: 0x36a0
    bool mIsEnableAnyBits;  // offset: 0x36a1
    bool mIsEnableAnyBitsOld;  // offset: 0x36a2
    cEfcHandle* mpOcdImuneEftHand;  // offset: 0x36a8
    bool mIsInvi;  // offset: 0x36b0
    bool mIsBowJumpEnable;  // offset: 0x36b1
    bool mActionWorkFlag;  // offset: 0x36b2
    bool mIsCustomSync;  // offset: 0x36b3
protected:
    bool mIsUpdateAbility;  // offset: 0x36b4
    bool mTankerTargetedByEnemy;  // offset: 0x36b5
    bool mTankerTargetedByEnemyOld;  // offset: 0x36b6
private:
    bool mCanJob09FrightBoardJump;  // offset: 0x36b7
    bool mCanJob09FrightBoardJumpOld;  // offset: 0x36b8
    u32 mJob09FrightBoardStat;  // offset: 0x36bc
    nHuman::HM_SKILL_LV mFrightBoardLv;  // offset: 0x36c0
    u32 mJob09AirFrightBoardCount;  // offset: 0x36c4
    uShlBase* mpFrightBoard;  // offset: 0x36c8
    bool mIsJob10HarfOcdImn;  // offset: 0x36d0
    bool mFlgBakeWepEnchantFinish;  // offset: 0x36d1
    bool mIsRequestUseStaminaItem;  // offset: 0x36d2
    bool mIsUseStaminaItem;  // offset: 0x36d3
    nDDOModel::AWAKENING_BRACELET_TYPE mAwakeningBraceletType;  // offset: 0x36d4
    u32 mAwakeningColor;  // offset: 0x36d8
    cEfcHandle* mpAwakeningHand;  // offset: 0x36e0
    cEfcHandle* mpAwakeningKirakira;  // offset: 0x36e8
    cEfcHandle* mpDeadEffect;  // offset: 0x36f0
    f32 mCheckCheatInvTime;  // offset: 0x36f8
    f32 mCheckCheatAddVelTime;  // offset: 0x36fc
    f32 mCheckCheatChargeInterval;  // offset: 0x3700
    f32 mCheckCheatChageNow_Gi;  // offset: 0x3704
    CS_CHANGE_STATE mCsChangeState;  // offset: 0x3708
    CS_CHANGE_GUI_STATE mCsChangeGUIState;  // offset: 0x370c
    f32 mPushCsChangeButtonFrame;  // offset: 0x3710
    f32 mCsChangeGuiTimer;  // offset: 0x3714
    nHuman::CUSTOM_SKILL_GROUP mSlaveReqCSGroup;  // offset: 0x3718
    bool mIsReceiveErosionRescue;  // offset: 0x371c
    bool mIsErosionRescuing;  // offset: 0x371d
    bool misErosionOld;  // offset: 0x371e
    u32Array mUniqueId;  // offset: 0x3720
    f32 mNeedErosionRespawnTimer;  // offset: 0x3740
    f32 mMaxErosionRespawnTimer;  // offset: 0x3744
    f32 mErosionRescueTimerRate;  // offset: 0x3748
    MtVector3 mStartErosionRescueDir;  // offset: 0x3750
    cpHumanWarpCtrl* mpHumanWarpCtrl;  // offset: 0x3760
public:
    f32 mWireTurnRotate;  // offset: 0x3768
    static MyDTI DTI;
private:
    static CMD_FUNC mpCmdFuncTbl[18];
public:
    static const MtVector3 mScrCapsuleUnder;
    static const MtVector3 mScrCapsuleTop;
    static const f32 mScrCapsuleRad;
    static const stAbilityVsEnemy mAbilityVsEnemyAttackTable[];
    static const stAbilityVsEnemy mAbilityVsEnemyDefenceTable[];
    static const stAbilitySkillUp mAbilitySkillupTable[];
    static const f32 mWarpDrawStartFrame;
private:
    static const u32 AddCircleCountValue = 5;
    static const u16 MAX_EROSION_NUM = 8;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool uHuman::isCanSetEmotion() {
    return this->mIsCanSetEmotion;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 uHuman::getClimbJointNo() const {
    return this->mClimbJointNo;
}

// Inline, no code of its own: checked where it is inlined.
inline cContextPlayerInfo* uHuman::getContextPlayerInfo() const {
    return this->mpContextPlayerInfo;
}

// Inline, no code of its own: checked where it is inlined.
inline uHuman::cHealSeCaller::cHealSeCaller() {
    this->mTimer = 0.0f;
    this->mSeNo = static_cast<u32>(4294967295);
    this->mIsHp = false;
    this->mIsStamina = false;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool uHuman::cHealSeCaller::isStamina() const {
    return this->mIsStamina;
}

// Inline, no code of its own: checked where it is inlined.
inline uHuman::cBlendMotionCtrl::cBlendMotionCtrl() {
    this->mIsMotionEnd = false;
    this->mIsActive = false;
    this->mEndHokan = -1.0f;
}
