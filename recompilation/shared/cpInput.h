#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cDelegate.h"
#include "cLeverGacha.h"
#include "cpComponent.h"
#include "nDDOUtility.h"
#include "nKeyCustom.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cLeverGacha;
class uDDOModel;

// Declarations
class cpInput;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cpInput : public cpComponent
{
public:
    enum KEY_CMD_DEF
    {
        KCD_NONE = -1,
        KCD_NEUTRAL = 0,
        KCD_FRONT = 1,
        KCD_LEFT = 2,
        KCD_RIGHT = 3,
        KCD_BACK = 4,
        KCD_MAX = 5,
        KCD_END = 5,
    };
    enum STICK_ANGLE_TYPE
    {
        LV_NONE = 0,
        LV_UP = 1,
        LV_DOWN = 2,
        LV_RIGHT = 3,
        LV_LEFT = 4,
        LV_UP_RIGHT = 5,
        LV_UP_LEFT = 6,
        LV_DOWN_RIGHT = 7,
        LV_DOWN_LEFT = 8,
    };
    enum
    {
        MV_NONE = 0,
        MV_WALK = 1,
        MV_RUN = 2,
    };
public:
    class MyDTI;
    struct stBtnInfo;
    union unBtnInfo;
    struct stMoveInfo;
    struct stChantInfo;
    class cRendaInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    union unBtnInfo
    {
    public:
        struct
        {
        public:
            u64 attack1 : 1;  // offset: 0x0
            u64 attack2 : 1;  // offset: 0x0
            u64 mainWeapon : 1;  // offset: 0x0
            u64 subWeapon : 1;  // offset: 0x0
            u64 customSkill0 : 1;  // offset: 0x0
            u64 customSkill1 : 1;  // offset: 0x0
            u64 customSkill2 : 1;  // offset: 0x0
            u64 customSkill3 : 1;  // offset: 0x0
            u64 special0 : 1;  // offset: 0x0
            u64 special1 : 1;  // offset: 0x0
            u64 special2 : 1;  // offset: 0x0
            u64 special3 : 1;  // offset: 0x0
            u64 touch : 1;  // offset: 0x0
            u64 jump : 1;  // offset: 0x0
            u64 dash : 1;  // offset: 0x0
            u64 lift : 1;  // offset: 0x0
            u64 holdWpn : 1;  // offset: 0x0
            u64 shoot : 1;  // offset: 0x0
            u64 shootUp : 1;  // offset: 0x0
            u64 chgMode : 1;  // offset: 0x0
            u64 escape : 1;  // offset: 0x0
            u64 keyUp : 1;  // offset: 0x0
            u64 keyRight : 1;  // offset: 0x0
            u64 keyDown : 1;  // offset: 0x0
            u64 keyLeft : 1;  // offset: 0x0
            u64 camReset : 1;  // offset: 0x0
            u64 csWait0 : 1;  // offset: 0x0
            u64 csWait1 : 1;  // offset: 0x0
            u64 csWait2 : 1;  // offset: 0x0
            u64 csWait3 : 1;  // offset: 0x0
            u64 holdBow : 1;  // offset: 0x0
            u64 autoRun : 1;  // offset: 0x0
            u64 catapult : 1;  // offset: 0x0
            u64 catapultCancel : 1;  // offset: 0x0
            u64 actCancel : 1;  // offset: 0x0
            u64 decide : 1;  // offset: 0x0
            u64 cancel : 1;  // offset: 0x0
            u64 climbJolt : 1;  // offset: 0x0
            u64 lockMode : 1;  // offset: 0x0
            u64 csChange : 1;  // offset: 0x0
            u64 padTrigger : 1;  // offset: 0x0
            u64 csDerive0 : 1;  // offset: 0x0
            u64 csDerive1 : 1;  // offset: 0x0
            u64 csDerive2 : 1;  // offset: 0x0
            u64 csDerive3 : 1;  // offset: 0x0
        };  // offset: 0x0
        u64 raw;  // offset: 0x0
    };
public:
    struct stMoveInfo
    {
    public:
        s32 type;  // offset: 0x0
        f32 angle;  // offset: 0x4
        MtVector3 dir;  // offset: 0x10
        f32 speed;  // offset: 0x20
        MtVector3 relativeDir;  // offset: 0x30
        f32 relativeAngle;  // offset: 0x40
        MtVector3 camera_dir;  // offset: 0x50
        f32 lvLX;  // offset: 0x60
        f32 lvLY;  // offset: 0x64
        f32 lvRX;  // offset: 0x68
        f32 lvRY;  // offset: 0x6c
    };
public:
    struct stChantInfo
    {
    public:
        f32 mvX;  // offset: 0x0
        f32 mvY;  // offset: 0x4
        f32 length;  // offset: 0x8
    };
public:
    class cRendaInfo
    {
    public:
        enum DECISION_TYPE
        {
            DEC_NONE = 0,
            DEC_SUCCESS = 1,
            DEC_FAILED = 2,
        };
    public:
        cRendaInfo();
        void init();
        void startup(f32 TimeLimit, u32 MaxCount, cpInput::unBtnInfo btnInfo, f32 TimerSpeed);
        void restartup(f32 TimeLimit, u32 now_count, u32 MaxCount, cpInput::unBtnInfo btnInfo, f32 TimerSpeed);
        u32 getDecisionType() const;
        void updateRendacheck(const cpInput::stBtnInfo& btnInfo, const uDDOModel* pModel);
        bool isSuccess() const;
        bool isFailed() const;
        u32 getNowRendaCount() const;
    private:
        bool mIsActive;  // offset: 0x0
        f32 mTimeLimit;  // offset: 0x4
        f32 mTimer;  // offset: 0x8
        f32 mTimerSpeed;  // offset: 0xc
        u32 mCountMax;  // offset: 0x10
        u32 mCount;  // offset: 0x14
        cpInput::unBtnInfo mBtnInfo;  // offset: 0x18
        DECISION_TYPE mDecisionType;  // offset: 0x20
    };
public:
    struct stBtnInfo
    {
    public:
        cpInput::unBtnInfo trg;  // offset: 0x0
        cpInput::unBtnInfo on;  // offset: 0x8
        cpInput::unBtnInfo rel;  // offset: 0x10
        cpInput::unBtnInfo old;  // offset: 0x18
        cpInput::unBtnInfo tgl;  // offset: 0x20
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
    cpInput();
    virtual ~cpInput();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void updateInput();
    STICK_ANGLE_TYPE getLeftStickAngle() const;
    STICK_ANGLE_TYPE getRightStickAngle() const;
    STICK_ANGLE_TYPE getLeftStickRelativeAngle() const;
    STICK_ANGLE_TYPE getLeftStickRelativeAngleFB() const;
    STICK_ANGLE_TYPE getLeftStickAngleEx() const;
    void startRendaCheck(f32 TimeLimit, u32 MaxCount, unBtnInfo btnInfo, f32 TimerSpeed);
    void restartRendaCheck(f32 TimeLimit, u32 now_count, u32 MaxCount, unBtnInfo btnInfo, f32 TimerSpeed);
    void endRendaCheck();
    bool isRendaSuccess() const;
    bool isRendaFailed() const;
    u32 getDecisionType();
    void resetPadOnTrg();
    void initLeverGacha(s32 count);
    bool checkLeverGacha();
    bool isLeverGachaSuccess();
    void updateKeyCmdStack();
    bool checkCommandList(const KEY_CMD_DEF* pCheckCmdList);
    void startupCheckCommand();
    void setupToggleSetting();
    void updateBtnInfoToggle(nKeyCustom::KB_CUSTOM kb);
    void clearBowTggle();
private:
    s64 updateBtnInfoToggleSub(nKeyCustom::KB_CUSTOM kb, u64 trg, u64 tglSetting, u64 tgl);
    void initKeyCmdStack();
public:
    uDDOModel* mpModel;  // offset: 0x50
    cDelegate_1<void, cpInput*> updateInputInfo;  // offset: 0x58
    stBtnInfo mBtnInfo;  // offset: 0x70
    stBtnInfo mOldBtnInfo;  // offset: 0x98
    stMoveInfo mMoveInfo;  // offset: 0xc0
    stChantInfo mChantInfo;  // offset: 0x130
    cRendaInfo mRendaInfo;  // offset: 0x140
    cLeverGacha mLeverGacha;  // offset: 0x168
    bool mUsePad;  // offset: 0x198
    bool mUseKeybord;  // offset: 0x199
    unBtnInfo mToggleSetting;  // offset: 0x1a0
    s32 mToggleSeesaw[2];  // offset: 0x1a8
private:
    nDDOUtility::cArray<KEY_CMD_DEF, 16> mKeyCmdStack;  // offset: 0x1b0
    KEY_CMD_DEF mOldKeyCmd;  // offset: 0x1f0
    u32 mForcus;  // offset: 0x1f4
    u32 mCheckStartIndex;  // offset: 0x1f8
public:
    static MyDTI DTI;
};
