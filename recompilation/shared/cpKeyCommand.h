#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cDelegate.h"
#include "cGeneralPointPtr.h"
#include "cpInput.h"
#include "cpThinkBase.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "sPadExt.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtQuaternion;
class MtVector3;
class cGeneralPointPtr;
class cpInput;
class cpJob10;
namespace nKeyCommand { struct stGenericParam; }
namespace nKeyCommand { struct stKeyCommand; }
namespace nKeyCommand { struct stKeyCommandForFunction; }
class uDDOModel;
class uHuman;

// Declarations
class cpKeyCommand;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpKeyCommand : public cpThinkBase
{
    // inferred: cpJob10::checkCanEndBoost names cpKeyCommand::mIsCanceled
    friend class cpJob10;
    // inferred: uHuman::backupCommandTblList names cpKeyCommand::mpCommandTbl[0]
    friend class uHuman;
public:
    enum ACT_CHECK_CMD_PRI
    {
        CHECK_CMD_PRI_NONE = 0,
        CHECK_CMD_PRI_ACT = 1,
        CHECK_CMD_PRI_OCD = 2,
        CHECK_CMD_PRI_SYS = 3,
        CHECK_CMD_PRI_MAX = 4,
    };
    enum
    {
        CTRL_BREAK_REPETITION = 1,
        CTRL_BREAK_CHECK = 2,
    };
public:
    class MyDTI;
    struct stActNoSet;
public:
    using FuncCmdTbl = nDDOUtility::cArray<nKeyCommand::stKeyCommandForFunction*, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stActNoSet
    {
    public:
        stActNoSet();
        void init();
    public:
        u32 mActNo;  // offset: 0x0
        u32 mCancelSeq;  // offset: 0x4
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
    cpKeyCommand();
    virtual ~cpKeyCommand();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void move();  // vtable slot 7
    void setMotionType(MOT_TYPE type);
    void setSequencePage(u32);
    u32 callbackGetAction();
    MtQuaternion callbackGetQuat(u32 actNo);
    void callbackUpdate();
    void callbackClearReserveAct();
    void setCommandTbl(s32 bank, nKeyCommand::stKeyCommand* pTbl);
    nKeyCommand::stKeyCommand* getCommandTbl(s32 bank) const;
    void setFuncCmdTbl(s32 bank, nKeyCommand::stKeyCommandForFunction* pTbl);
    nKeyCommand::stKeyCommandForFunction* getFuncCmdTbl(s32) const;
    cpInput* getCpInput();
    bool IsCanceled();
    bool checkCustomHoldOFF(s32 CustomSkillID, bool check_lr);
    bool checkCustomContinueTrg(s32 CustomSkillID);
    bool checkFuryAndCharge(u8 chargeLevel, u8 furyLevel, bool justRelease);
    s32 getLeftStickAngle();
    s32 getLeftStickAngleEx();
    s32 getLeftStickRelativeAngle() const;
    s32 getLeftStickRelativeAngleFB() const;
    void setActiveCheckCommand(bool flag, ACT_CHECK_CMD_PRI prio);
    bool isActiveCheckCommand() const;
    s32 checkKeyCommandFunction();
    virtual f32 getAngleY();  // vtable slot 15
    virtual f32 getAngleYActBegin(u32 actNo);  // vtable slot 16
    virtual f32 getMoveSpeed();  // vtable slot 17
    virtual u32 getMoveType();  // vtable slot 18
    virtual f32 getMoveLvLX();  // vtable slot 19
    bool checkCommandForActPltAN(u32 uActNoSearch, sPadExt::PAD_BTN_TYPE* pBtn);
    bool checkCommandForActPltCS(bool bMainWeapon, nHuman::CUSTOM_SKILL_PALLET csplt, sPadExt::PAD_BTN_TYPE* pBtn, u32 actNo);
    bool checkCommandForActPltEX(u32 funcType, sPadExt::PAD_BTN_TYPE* pBtn);
    cpInput::unBtnInfo getCstmBtnInfoTrg();
protected:
    u32 checkCommand();
    u32 checkCommandTbl(nKeyCommand::stKeyCommand* pTbl);
    bool checkCommandTblSub(nKeyCommand::stKeyCommand* pTbl, u32& ActNo, bool check_break);
    bool checkLastAction(nKeyCommand::stKeyCommand* pTbl);
    bool checkButtonType(nKeyCommand::stKeyCommand* pTbl);
    bool checkMoveType(nKeyCommand::stKeyCommand* pTbl);
    bool checkObjStatus(nKeyCommand::stKeyCommand* pTbl);
    bool checkObjStatusNone(nKeyCommand::stKeyCommand* pTbl);
    bool checkReserveCancelSequence(nKeyCommand::stKeyCommand* pTbl);
    bool checkMenuUI(nKeyCommand::stKeyCommand* pTbl);
    bool checkCancelSequence(nKeyCommand::stKeyCommand* pTbl);
    bool checkAttr(nKeyCommand::stKeyCommand* pTbl);
    bool checkCondition(nKeyCommand::stKeyCommand* pTbl);
    bool checkSpInput(nKeyCommand::stKeyCommand* pTbl);
    bool checkOcdSeal(nKeyCommand::stKeyCommand* pTbl);
    bool checkCsChange(nKeyCommand::stKeyCommand* pTbl);
    bool checkCancelSequence(u32 cancelSequcence);
    s32 checkCommandTbl(nKeyCommand::stKeyCommandForFunction* pTbl);
    bool checkButtonType(nKeyCommand::stKeyCommandForFunction* pTbl);
    bool checkCondition(nKeyCommand::stKeyCommandForFunction* pTbl);
    bool checkButtonTypeSub(u32 PressType, u32 InputType, s32 CustomSkillID);
    bool getActPltButtonType(u32 inputType, sPadExt::PAD_BTN_TYPE* pBtn);
    void turnAndLockOn(u32 ActNo, f32 limitAngle);
    void turnAndLockOn2();
    void checkLimitAngle(MtVector3& targetDir, const MtVector3& curDir, f32 limitAngle);
public:
    void clearAttackLockOnTarget();
    const cGeneralPointPtr& getAttackLockOnTarget() const;
    s32 getBeforeUseCustomSkillId() const;
    bool checkKeyCommandFunctionActPallet(nHuman::FUNC_TBL_NO func, sPadExt::PAD_BTN_TYPE* pBtn, u32 num);
    void setCustomSkillBtnInfo(s32 skill_id, nHuman::CUSTOM_SKILL_PALLET pallet, bool is_right, cpInput::unBtnInfo info);
public:
    cDelegate_3<bool, unsigned int, unsigned int, MOT_TYPE> checkSequence;  // offset: 0x50
    cDelegate_0<bool> checkCndCliffHang;  // offset: 0x68
    cDelegate_0<bool> checkCndCliffClimb;  // offset: 0x80
    cDelegate_0<bool> checkCndCliffFall;  // offset: 0x98
    cDelegate_0<bool> checkCndNotDash;  // offset: 0xb0
    cDelegate_0<bool> checkCndWallClimbStart;  // offset: 0xc8
    cDelegate_0<bool> checkCndMugenJump;  // offset: 0xe0
    cDelegate_0<bool> checkCndDashJumpToDash;  // offset: 0xf8
    cDelegate_0<bool> checkCndEvasionEnable;  // offset: 0x110
    cDelegate_1<bool, int> isLimitedAction;  // offset: 0x128
    cDelegate_0<bool> checkGuardCharge;  // offset: 0x140
    cDelegate_0<unsigned int> checkCndJoltGrade;  // offset: 0x158
    cDelegate_0<bool> isBattleModel;  // offset: 0x170
    cDelegate_1<bool, nKeyCommand::stGenericParam&> checkCndFunc;  // offset: 0x188
protected:
    uDDOModel* mpModel;  // offset: 0x1a0
    cpInput* mpInput;  // offset: 0x1a8
    u32 mMotType;  // offset: 0x1b0
    u32 mSeqPage;  // offset: 0x1b4
    u8 mCtrlFlag;  // offset: 0x1b8
    bool mIsCanceled;  // offset: 0x1b9
    ACT_CHECK_CMD_PRI mActCheckCmdPriority;  // offset: 0x1bc
    bool mIsActiveCheckCommand;  // offset: 0x1c0
    s32 mBeforeCustomSkillID;  // offset: 0x1c4
    nHuman::CUSTOM_SKILL_PALLET mBeforeCustumPallet;  // offset: 0x1c8
    nHuman::CUSTOM_SKILL_PALLET mTempCustumPallet;  // offset: 0x1cc
    bool mBeforeCustomIsRight;  // offset: 0x1d0
    cpInput::unBtnInfo mCstmBtnInfoTrg;  // offset: 0x1d8
    u32 mBeforeCustomPressType;  // offset: 0x1e0
    cpInput::unBtnInfo mCstmBtnInfoRel;  // offset: 0x1e8
    cpInput::unBtnInfo mCstmBtnInfoOn;  // offset: 0x1f0
    cpInput::unBtnInfo mCstmBtnInfoOff;  // offset: 0x1f8
    MtQuaternion mKeyCommandFinalQuat;  // offset: 0x200
    nKeyCommand::stKeyCommand* mpCommandTbl[8];  // offset: 0x210
    stActNoSet mReserveActNoSet;  // offset: 0x250
    FuncCmdTbl mpFuncCmdTbl;  // offset: 0x258
    cGeneralPointPtr mAttackLockOnTarget;  // offset: 0x298
public:
    static MyDTI DTI;
    static const s32 TBL_MAX = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline cpInput* cpKeyCommand::getCpInput() {
    return this->mpInput;
}
