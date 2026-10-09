#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOGame.h"
#include "nDDOModel.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtPropertyList;

// Declarations
namespace nHumanBow { class cBowActParam; }
namespace nHumanBow { struct stNetData; }

namespace nHumanBow {
    enum BOW_ACT_KIND
    {
        BOW_ACT_NORMAL = 0,
        BOW_ACT_MAGIC = 1,
        BOW_ACT_KIND_NUM = 2,
    };
}  // namespace nHumanBow

namespace nHumanBow {
    enum MGC_BOW_CHARGE_LV
    {
        MGC_BOW_CHARGE_0 = 0,
        MGC_BOW_CHARGE_1 = 1,
        MGC_BOW_CHARGE_2 = 2,
        MGC_BOW_CHARGE_JUST = 3,
    };
}  // namespace nHumanBow

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nHumanBow {
    class cBowActParam : public ::MtObject
    {
    public:
        enum SHOOT_TYPE
        {
            SHOOT_BOW = 0,
            SHOOT_FALL = 1,
        };
        enum SHOOT_DIR_TYPE
        {
            SHOOT_DIR_CAMERA = 0,
            SHOOT_DIR_BOW = 1,
        };
        enum ASJ_PARAM_TYPE
        {
            ASJ_PARAM_NONE = -1,
            ASJ_PARAM_0 = 0,
            ASJ_PARAM_1 = 1,
            ASJ_PARAM_2 = 2,
            ASJ_PARAM_3 = 3,
        };
        enum CS_FILTER
        {
            CS_FILTER_NONE = 0,
            CS_FILTER_EFCT_0 = 1,
        };
        enum SE_TYPE
        {
            SE_SKILL = 0,
            SE_CMN = 1,
        };
        enum
        {
            JUMP_TYPE_F = 0,
            JUMP_TYPE_V = 1,
            JUMP_TYPE_NUM = 2,
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
            EO_CHARGE_END_FIN = 1,
            EO_CHARGE_EF_WPN = 2,
            EO_CMN_ARROWS_EFCT = 4,
            EO_CMN_SHOT_CONST_PL = 8,
            EO_SCOPE_EFF_COMMON = 16,
        };
        enum
        {
            LOCKON_CONTINUE = 1,
            LOCKON_SHL_SET_SL_NUM = 2,
            LOCKON_AUTO_CMC = 4,
            LOCKON_PL_CMC = 8,
            LOCKON_NO_NUM_OVER = 16,
            LOCKON_NO_LOCK_SHOT_ONE = 32,
            LOCKON_JUST_OFFSET = 64,
        };
        enum
        {
            ABILITY_FLAG_NO369 = 1,
            ABILITY_FLAG_NO374 = 2,
            ABILITY_FLAG_NO375 = 4,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cBowActParam();
        virtual ~cBowActParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createPropertyCmn(MtPropertyList& s);  // vtable slot 6
        virtual void createPropertyAct(MtPropertyList& s);  // vtable slot 7
        virtual void createPropertyMotion(MtPropertyList& s);  // vtable slot 8
        virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 9
        const nHumanBow::cBowActParam& operator=(const nHumanBow::cBowActParam& r);
        u32 getWalkMotionLow(u32) const;
        u32 getWalkMotionUp(u32) const;
        u32 getRunMotionLow(u32) const;
        u32 getRunMotionUp(u32) const;
        u32 getWalkShotMotion(u32) const;
        u32 getRunShotMotion(u32) const;
    public:
        s32 cameraNoA;  // offset: 0x8
        s32 cameraNoB;  // offset: 0xc
        s32 cameraShotA;  // offset: 0x10
        s32 cameraShotB;  // offset: 0x14
        s32 cameraNoCharge;  // offset: 0x18
        f32 camShotEndFrame;  // offset: 0x1c
        SHOOT_TYPE shootType;  // offset: 0x20
        SHOOT_DIR_TYPE shootDirType;  // offset: 0x24
        f32 shootDelayTime;  // offset: 0x28
        f32 criticalDisNear;  // offset: 0x2c
        f32 criticalDisFar;  // offset: 0x30
        f32 chargeFrames[5];  // offset: 0x34
        f32 chargeJustFrames[5];  // offset: 0x48
        s8 chargeArrowUseNum[5];  // offset: 0x5c
        s8 defaultOceArrowUseNum;  // offset: 0x61
        u32 maxChargeLv;  // offset: 0x64
        u32 usableLv;  // offset: 0x68
        u32 customId;  // offset: 0x6c
        s32 staminaId;  // offset: 0x70
        s32 staminaWaitId;  // offset: 0x74
        bool isStaminaRecoverDisable;  // offset: 0x78
        bool isFastReload;  // offset: 0x79
        bool isFastExplosionReload;  // offset: 0x7a
        bool isRestArrowAllUse;  // offset: 0x7b
        bool isOcdAdjust;  // offset: 0x7c
        f32 changeSpeed;  // offset: 0x80
        f32 shotWait;  // offset: 0x84
        f32 chargeBgnFrameShot;  // offset: 0x88
        f32 chargeBgnFrameChange;  // offset: 0x8c
        f32 checkLength;  // offset: 0x90
        nDDOModel::LOCKON_TARGET_TYPE lockOnType;  // offset: 0x94
        u32 lockOnNum;  // offset: 0x98
        u32 lockOnFlag;  // offset: 0x9c
        bool isLockOnContinue;  // offset: 0xa0
        bool isSlaveNoCreateShl;  // offset: 0xa1
        bool isNetWorkShl;  // offset: 0xa2
        bool isJustShot;  // offset: 0xa3
        bool isClacMatrix;  // offset: 0xa4
        bool isArrowNumScale;  // offset: 0xa5
        f32 fallCircleRadius;  // offset: 0xa8
        f32 mgcChargeSpeed;  // offset: 0xac
        f32 mgcBonusRate;  // offset: 0xb0
        f32 mgcCharge1;  // offset: 0xb4
        f32 mgcCharge2;  // offset: 0xb8
        f32 mgcChargeNearRate;  // offset: 0xbc
        f32 mgcChargeFarRate;  // offset: 0xc0
        f32 mgcChargeJustFrame;  // offset: 0xc4
        f32 mgcChargeRateHumanEnemy;  // offset: 0xc8
        f32 addHealHate;  // offset: 0xcc
        bool mgcNoUseDamageAdjust;  // offset: 0xd0
        bool isCoreSearch;  // offset: 0xd1
        u32 coreSearchRadius;  // offset: 0xd4
        u32 coreSearchNodeNo;  // offset: 0xd8
        MtArray shootCtrlList;  // offset: 0xe0
        f32 accurateWait;  // offset: 0x100
        f32 accurateWalk;  // offset: 0x104
        f32 accurateRun;  // offset: 0x108
        f32 accurateJump;  // offset: 0x10c
        f32 accurateFall;  // offset: 0x110
        ASJ_PARAM_TYPE asjParamType;  // offset: 0x114
        u32 asjOption;  // offset: 0x118
        u32 abilityFlag;  // offset: 0x11c
        bool isShotRetNml;  // offset: 0x120
        bool isWalk;  // offset: 0x121
        bool isRun;  // offset: 0x122
        bool isMovingJump;  // offset: 0x123
        bool isVJump;  // offset: 0x124
        bool isMovingShot;  // offset: 0x125
        bool isAirShot;  // offset: 0x126
        bool isShootingJump;  // offset: 0x127
        bool isChangeMot;  // offset: 0x128
        bool isDispAimSight;  // offset: 0x129
        bool isUpperRotXFix;  // offset: 0x12a
        bool isArrowCamera;  // offset: 0x12b
        bool isAITactics;  // offset: 0x12c
        bool isCmcPosUse;  // offset: 0x12d
        bool isEndStamina0Wait;  // offset: 0x12e
        bool isParabolaLine;  // offset: 0x12f
        bool isFallCircle;  // offset: 0x130
        bool isNoAir;  // offset: 0x131
        u8 motBgn_Up;  // offset: 0x132
        u8 motBgn_Low;  // offset: 0x133
        u8 motEnd_Up;  // offset: 0x134
        u8 motEnd_Low;  // offset: 0x135
        u8 motTurnL;  // offset: 0x136
        u8 motTurnR;  // offset: 0x137
        u8 motJumpBgn[2];  // offset: 0x138
        u8 motJumpNow[2];  // offset: 0x13a
        u8 motJumpEnd[2];  // offset: 0x13c
        u8 motFall;  // offset: 0x13e
        u8 motWait_Low;  // offset: 0x13f
        u8 motWait_Up;  // offset: 0x140
        u8 motWaitShot_Up;  // offset: 0x141
        u8 motWaitShot_Low;  // offset: 0x142
        u8 motRunShotL;  // offset: 0x143
        u8 motChange_UpWait;  // offset: 0x144
        u8 motChange_Up[4];  // offset: 0x145
        u8 motChange_Low;  // offset: 0x149
        u8 motFinishShot_Up;  // offset: 0x14a
        u8 motFinishShot_Low;  // offset: 0x14b
        s8 epvIndex;  // offset: 0x14c
        s8 epvNoCharge;  // offset: 0x14d
        s8 epvNoChargeComp;  // offset: 0x14e
        s8 epvNoChargeStart;  // offset: 0x14f
        s8 epvIndexSkill;  // offset: 0x150
        s8 epvNoShot;  // offset: 0x151
        s8 epvNoChargeShotCs[5];  // offset: 0x152
        s8 epvNoChargeCompCs[5];  // offset: 0x157
        s8 epvNoFilter;  // offset: 0x15c
        s8 epvNoScope;  // offset: 0x15d
        s8 epvNoJustShot;  // offset: 0x15e
        CS_FILTER cmnCSFilter;  // offset: 0x160
        u32 efOption;  // offset: 0x164
        SE_TYPE seType;  // offset: 0x168
        s16 seNoShot;  // offset: 0x16c
        s16 seNoChargeBgn;  // offset: 0x16e
        s16 seNoChargeCmp[5];  // offset: 0x170
        s16 seNoChargeEnd;  // offset: 0x17a
        s16 seNoSkillBgn;  // offset: 0x17c
        s16 seNoSkillEnd;  // offset: 0x17e
        s16 seNoLockOn;  // offset: 0x180
        s16 seNoScopeBgn;  // offset: 0x182
        s16 seNoScopeEnd;  // offset: 0x184
        u32 seOption;  // offset: 0x188
        nDDOGame::ELEMENT_TYPE castType;  // offset: 0x18c
        u8 motWalk_Low[4];  // offset: 0x190
        u8 motRun_Low[4];  // offset: 0x194
        u8 motWalk_Up[4];  // offset: 0x198
        u8 motRun_Up[4];  // offset: 0x19c
        u8 motWalkShot[4];  // offset: 0x1a0
        u8 motRunShot[4];  // offset: 0x1a4
        static MyDTI DTI;
        static const u32 CHARGE_LV_NUM = 5;
        static const f32 CIRCLE_DEFAULT_RADIUS;
    };
}  // namespace nHumanBow

namespace nHumanBow {
    struct stNetData
    {
    public:
        enum TYPE
        {
            TYPE_LOW = 0,
            TYPE_UP = 1,
            TYPE_PERIOD = 2,
        };
        enum
        {
            BOW_BIT_CHARGE_0 = 1,
            BOW_BIT_CHARGE_1 = 2,
            BOW_BIT_CHARGE_2 = 4,
            BOW_BIT_CHARGE_JUST = 8,
            BOW_BIT_CS11_SPEED_1 = 16,
            BOW_BIT_CS11_SPEED_2 = 32,
            BOW_BIT_CS11_SPEED_3 = 64,
            BOW_BIT_CS11_FINISH = 128,
            BOW_BIT_ALL = 15,
        };
        enum
        {
            MGC_BOW_BIT_CHARGE_0 = 1,
            MGC_BOW_BIT_CHARGE_1 = 2,
            MGC_BOW_BIT_CHARGE_2 = 4,
            MGC_BOW_BIT_CHARGE_JUST = 8,
            MGC_BOW_BIT_OCD_ADJUST = 16,
            MGC_BOW_BIT_MGC_CHARGE = 32,
            MGC_BOW_BIT_ABI_374 = 64,
            MGC_BOW_BIT_ABI_375 = 128,
            MGC_BOW_BIT_ALL = 223,
        };
    public:
        stNetData();
        stNetData(u32 _data);
        u8 getType() const;
        void setType(u8 type);
        u8 getActNo() const;
        void setActNo(u8 no);
        u8 getBowNetBit() const;
        void setBowNetBit(u8 bit);
        u8 getSkillType() const;
        void setSkillType(u8 type);
        bool isAimPos() const;
        void setAimPosUse(bool b);
    public:
        u8 mType;  // offset: 0x0
        u8 mActNo;  // offset: 0x1
        u8 mSkillType;  // offset: 0x2
        u8 mBowNetBit;  // offset: 0x3
        u8 mShlShotNum;  // offset: 0x4
        u8 mArrowNum;  // offset: 0x5
        u32 mTargetUId[4];  // offset: 0x8
        u32 mLockOnID[4];  // offset: 0x18
        bool mIsAimPos;  // offset: 0x28
        bool mIsArrowNum;  // offset: 0x29
        bool mIsShlShotNum;  // offset: 0x2a
        bool mIsFirstFrame;  // offset: 0x2b
    };
}  // namespace nHumanBow
