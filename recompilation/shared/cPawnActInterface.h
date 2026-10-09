#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cAIGrid.h"
#include "cAIObject.h"
#include "cGeneralPointPtr.h"
#include "cpInput.h"
#include "nDDOUtility.h"
#include "nPawn.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtVector3;
class cAIGrid;
class cAITargetInfo;
class cAITargetInfoArray;
class cGeneralPoint;
class cGeneralPointPtr;
class cPawnActInterDisableMgr;
class cPawnEnableArea;
struct stMoveAngleRet;
class uBaseModel;
class uCharacter;
class uDDOModel;

// Declarations
class cPawnActInterBase;
class cPawnActInterBreak;
class cPawnActInterCommon;
class cPawnActInterIO;
class cPawnActInterIn;
class cPawnActInterWaitFootwork;
class cPawnActInterface;
struct stMoveAngleCtrl;

enum ACTINTER_CODERET
{
    ACTINTER_CODERET_END = 0,
    ACTINTER_CODERET_BREAK = 1,
    ACTINTER_CODERET_CONTINUE = 2,
    ACTINTER_CODERET_NUM = 3,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnOrderGroupArray = nDDOUtility::cArray<unsigned int, 3>;
using cPawnAIActCancelFlag = nDDOUtility::cBitSet<22>;
using cPawnAIActComCtrlFlag = nDDOUtility::cBitSet<11>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cPawnActInterBase : public MtObject
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
    cPawnActInterBase();
    virtual ~cPawnActInterBase();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void endInter();  // vtable slot 8
    virtual void load(MtDataReader& r);  // vtable slot 9
    virtual void save(MtDataWriter& w);  // vtable slot 10
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
protected:
    uBaseModel* findUnit(u32 uid);
    uCharacter* findNearPartyMember(cPawnActInterIO& param, uCharacter& owner, f32 max, f32 min, bool once);
    bool moveActionGoto(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos, f32 range, f32 speed);
    bool moveActionGoto(cPawnActInterIO& param, uCharacter& owner, const cPawnEnableArea& area, f32 range, u32 targetIdx, f32 speed);
    bool moveCmnAngle(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos);
    f32 calcTargetAngle(const MtVector3& ownerPos, cPawnActInterIO& param, f32 def, u32 targetIdx);
    f32 calcMoveSpeed(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos);
    bool calcMoveSpeedFromInParam(f32* pDst, cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos);
    bool calcMoveActionGoto(cPawnActInterIO& param, uCharacter& owner, MtVector3* pDstOfsPos, const cPawnEnableArea& area, f32 range, u32 targetIdx, f32 speed);
    bool checkNoMove(uCharacter& owner, cPawnActInterIO& param);
    bool isEnableTargetArea(const MtVector3& ownerPos, cPawnActInterIO& param, const cPawnEnableArea& area, u32 targetIdx, bool def) const;
    bool isEnableMoveAngle(uCharacter& owner, f32 angle, f32 len);
    bool isEnableMove(cPawnActInterIO& param, uCharacter& owner) const;
    bool isEnableGuard(cPawnActInterIO& param, uCharacter& owner);
    bool isEnableEmClimbContinue(cPawnActInterIO& param, uCharacter& owner) const;
    bool isEnableEmClimbContinue(uCharacter& owner, uDDOModel* pTarget) const;
    bool isEnableSkillRange(cPawnActInterIO& param, uCharacter& owner, u32 actNo) const;
    bool isFookWorkActionNo(u32 actNo, uCharacter& owner) const;
    bool isCompActNo(uCharacter& owner, u32 jobId, u32 doActNo, u32 actNo) const;
    static void getActionBtn(cPawnActInterIO& param, uCharacter& owner, u32 actNo, cpInput::unBtnInfo& dstTrg, cpInput::unBtnInfo& dstOn, bool isReady);
    static s32 getGuardActNo(cPawnActInterIO& param, uCharacter& owner);
    static f32 getGuardActCheckAngleY(cPawnActInterIO& param, uCharacter& owner);
    static bool isGuardAction(cPawnActInterIO& param, uCharacter& owner);
    static bool isReadyAction(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    static void setResultActNo(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    static void setResultActNo(cPawnActInterIO& param, uCharacter& owner, u32 actNo, f32 angle);
    static void setResultActNo(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const MtVector3& pos);
    static void setResultActNoHold(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    static void setResultActNoHold(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const MtVector3& pos);
    static void setResultActNoHold(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const f32 angle);
    static void setResultActNoReady(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    static void setResultActNoReady(cPawnActInterIO& param, uCharacter& owner, u32 actNo, f32 angle);
    static void setResultActNoReady(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const MtVector3& pos);
    static void setResultAngle(cPawnActInterIO& param, uCharacter& owner, f32 angle);
    static void setResultAngle(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos);
    static void setResultMove(cPawnActInterIO& param, uCharacter& owner, f32 angle, f32 speed);
    static void setResultWarp(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos);
    static void setResultMoveInfo(cPawnActInterIO& param, uCharacter& owner, f32 angle, f32 speed);
    MtVector3 calcBowNetAimPos(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos);
    void setResultBowNetAimPos(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos, bool upShot);
    void setResultMagLockOnTarget(cPawnActInterIO& param, uCharacter& owner, cGeneralPoint* pTarget);
    static void reqDrawnSword(cPawnActInterIO& param, bool drawn);
    static u64 convInputTrg(uCharacter& owner, u64 btn);
    u32 getRouteInfo(MtVector3* pDstPos, uCharacter& owner);
    u32 getNoticeFlag(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos);
    bool moveActionGotoRouteInfoAction(cPawnActInterIO& param, uCharacter& owner);
    bool moveActionGotoOpenDoor(cPawnActInterIO& param, uCharacter& owner, f32 angle);
    bool moveActionGotoOmBreak(cPawnActInterIO& param, uCharacter& owner, f32 angle);
    bool moveActionGotoLadder(cPawnActInterIO& param, uCharacter& owner, const stMoveAngleRet& ret);
    f32 moveActionGotoEscapeLadder(cPawnActInterIO& param, uCharacter& owner, const stMoveAngleRet& ret);
    bool moveArrowChange(cPawnActInterIO& param, uCharacter& owner, u32 arrowGroup, u32& localRno);
public:
    static void setResultActNoPos(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const MtVector3& pos, bool isReady, bool isForceOn);
    static void setResultActNoInput(cPawnActInterIO& param, uCharacter& owner, u32 actNo, f32 angle, bool useAngle, bool isReady, bool isForceOn);
    static void setResultBtnDirect(cPawnActInterIO& param, uCharacter& owner, cpInput::unBtnInfo btnOn, cpInput::unBtnInfo btnTrg);
public:
    f32 mLifeFrame;  // offset: 0x8
    u32 mDisableNotice;  // offset: 0xc
    static MyDTI DTI;
};

class cPawnActInterBreak : public cPawnActInterBase
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
    cPawnActInterBreak();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    cPawnAIActComCtrlFlag mComFlag;  // offset: 0x10
    u32 mComOrderID;  // offset: 0x14
    static MyDTI DTI;
};

class cPawnActInterCommon : public cPawnActInterBase
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
    cPawnActInterCommon();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    void resetParam();
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    cPawnAIActCancelFlag mCancelFlag;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterIn
{
public:
    cPawnActInterIn();
    void clearPawnActInterIn();
public:
    nDDOUtility::cArray<MtVector3, 4> mTargetRealPos;  // offset: 0x0
    nDDOUtility::cArray<cGeneralPointPtr, 4> mTargetGeneralPoint;  // offset: 0x40
    nDDOUtility::cArray<unsigned int, 4> mTargetUID;  // offset: 0x80
    nDDOUtility::cArray<float, 4> mTargetRange;  // offset: 0x90
    nDDOUtility::cArray<unsigned int, 4> mTargetEnableAngleType;  // offset: 0xa0
    u32 mTargetType;  // offset: 0xb0
    u32 mTargetNum;  // offset: 0xb4
    f32 mTargetFrame;  // offset: 0xb8
    u32 mFollowAreaType;  // offset: 0xbc
    cPawnEnableArea mFollowAreaTarget;  // offset: 0xc0
    cPawnEnableArea mFollowAreaEnable;  // offset: 0xe0
    MtVector3 mFollowAreaOfsPos;  // offset: 0x100
    f32 mFollowAreaAngle;  // offset: 0x110
    u32 mThinkBattleStatus;  // offset: 0x114
    cAIPawnOrderGroupArray mAIPawnOaderID;  // offset: 0x118
    bool mAIPawnOrderCancel;  // offset: 0x124
    bool mAIPawnNoMove;  // offset: 0x125
    u32 mGroupThinkID;  // offset: 0x128
    u32 mActionBase;  // offset: 0x12c
    u32 mActionAttr;  // offset: 0x130
    u32 mActionRequestFlag;  // offset: 0x134
    f32 mActionLimitFrame;  // offset: 0x138
    u32 mPawnActionID;  // offset: 0x13c
    cAIPawnActionGroupFlag mPawnActGroupFlag;  // offset: 0x140
    f32 mActionArrowChgWaitTimer;  // offset: 0x150
    f32 mActionMedalChgWaitTimer;  // offset: 0x154
    f32 mActionCureArrowWaitTimer;  // offset: 0x158
    f32 mActionSpiritStoneHealWaitTimer;  // offset: 0x15c
    f32 mActionSpiritStoneSupWaitTimer;  // offset: 0x160
    f32 mErosionRescueCoolDownTimer;  // offset: 0x164
    f32 mReceiveErosionRescueCoolDownTimer;  // offset: 0x168
    u32 mActChgCount;  // offset: 0x16c
    nDDOUtility::cArray<float, 4> mFreeParamF32;  // offset: 0x170
    cPawnActInterDisableMgr* mpPawnActInterDisableMgr;  // offset: 0x180
    cAIGrid* mpOwnerNoticeGrid;  // offset: 0x188
    cAIGrid* mpOwnerTraceDisableGrid;  // offset: 0x190
    cAIGrid* mpOwnerDangerGrid;  // offset: 0x198
    cAIGrid* mpOwnerHealingArrowGrid;  // offset: 0x1a0
    uCharacter* mpMasterCharacter;  // offset: 0x1a8
    cAITargetInfoArray* mpPartyList;  // offset: 0x1b0
    cAITargetInfoArray* mpEnemyList;  // offset: 0x1b8
    uDDOModel* mpCheckHitUnit;  // offset: 0x1c0
    uDDOModel* mpAttackTestHitUnit;  // offset: 0x1c8
    cAIPawnActionGroupFlag mPawnTgtEnemyFlag;  // offset: 0x1d0
    f32 mActBreakDisableTime;  // offset: 0x1e0
    bool mUseNpcAvoid;  // offset: 0x1e4
    u32 mChantNextActNo;  // offset: 0x1e8
    f32 mClimbEnemyYorokeStart;  // offset: 0x1ec
    f32 mFlgEscapeThink;  // offset: 0x1f0
};

class cPawnActInterWaitFootwork : public cPawnActInterBase
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
    cPawnActInterWaitFootwork();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

struct stMoveAngleCtrl
{
public:
    void clearMvCtrl();
public:
    f32 wallTime;  // offset: 0x0
    f32 wallAngleY;  // offset: 0x4
    f32 wallChkTime;  // offset: 0x8
    f32 forceTraceTime;  // offset: 0xc
};

class cPawnActInterIO
{
public:
    enum
    {
        LADDER_CTRL_NONE = 0,
        LADDER_CTRL_UP = 1,
        LADDER_CTRL_DN = 2,
        LADDER_NUM = 3,
    };
public:
    using cFreeU32Array = nDDOUtility::cArray<unsigned int, 8>;
    using cFreeF32Array = nDDOUtility::cArray<float, 8>;
    using cFreeVecArray = nDDOUtility::cArray<MtVector3, 3>;
    using cFreeGridArray = nDDOUtility::cArray<cAIGrid, 2>;
    using cUserU32Array = nDDOUtility::cArray<unsigned int, 4>;
public:
    bool calcTargetOfsPos(MtVector3* pDstOfsPos, u32 targetIdx);
    f32 getTargetAngle(u32 targetIdx);
    f32 getTargetRange(u32 targetIdx);
    u32 getTargetEnableAngleType(u32 targetIdx);
    uDDOModel* getTargetUnitDDO(u32 targetIdx);
    uCharacter* getTargetUnitCharacter(u32 targetIdx);
    uBaseModel* getTargetUnitBaseModel(u32 targetIdx);
    cGeneralPoint* getTargetGeneralPoint(u32 targetIdx);
    cAITargetInfo* getNearEnemyTargetInfo(const MtVector3& pos, f32 maxLen);
    cAITargetInfo* getNearEnemyTargetInfoAttack(const MtVector3& pos, f32 maxLen);
    cAITargetInfo* getNearEnemyTargetInfoAttackLv(const MtVector3& pos, f32 maxLen);
    void allocFreeGpPtrArray(u32 num);
    void releaseFreeGpPtrArray();
    u32 getFreeGpPtrNum() const;
    cGeneralPoint* getFreeGpPtr(u32 idx);
    void setFreeGpPtr(u32 idx, cGeneralPoint* pGp);
private:
    static bool checkFunAttack(cAITargetInfo* pTarget, void* pParam);
    static bool checkFunAttackLv(cAITargetInfo* pTarget, void* pParam);
public:
    cPawnActInterIn mInParam;  // offset: 0x0
    f32 mLifeFrameCode;  // offset: 0x200
    f32 mLifeFrameAll;  // offset: 0x204
    cFreeU32Array mFreeU32;  // offset: 0x208
    cFreeF32Array mFreeF32;  // offset: 0x228
    cFreeVecArray mFreeRealPos;  // offset: 0x250
    cFreeGridArray mFreeGrid;  // offset: 0x280
    cGeneralPointPtr* mpFreeGPPtrArray;  // offset: 0x300
    u32 mFreeGPPtrNum;  // offset: 0x308
    cUserU32Array mUserU32;  // offset: 0x30c
    cPawnEnableArea mUserEnableArea;  // offset: 0x320
    stMoveAngleCtrl mMoveActionGotoCtrl;  // offset: 0x340
    bool mBowAimInit;  // offset: 0x350
    u32 mOnLadder;  // offset: 0x354
    s32 mAIRetActNoReq;  // offset: 0x358
    u32 mAIRetPawnSituation;  // offset: 0x35c
    bool mAIRetEnableFall;  // offset: 0x360
    bool mAIRetUseTrace;  // offset: 0x361
    bool mAIRetDrawnSword;  // offset: 0x362
    bool mAIRetPaySword;  // offset: 0x363
    bool mAIRetReqWarp;  // offset: 0x364
    bool mAIRetJustGuard;  // offset: 0x365
    bool mAIRetNormalGuard;  // offset: 0x366
    bool mAIRetOrderClear;  // offset: 0x367
    bool mAIRetOrderActEnd;  // offset: 0x368
    bool mAIRetForceChgArrowTime;  // offset: 0x369
    cpInput::unBtnInfo mAIRetBtnInfo;  // offset: 0x370
    cpInput::stMoveInfo mAIRetMoveInfo;  // offset: 0x380
    MtVector3 mAIRetWarpRealPos;  // offset: 0x3f0
    u32 mAIRetDisableNotice;  // offset: 0x400
    u32 mAIReqTraceRet;  // offset: 0x404
    f32 mAIRetAngle;  // offset: 0x408
    s32 mAIRetActNo;  // offset: 0x40c
    f32 mAIRetMoveSpeed;  // offset: 0x410
    MtVector3 mAIRetTargetOfsPos;  // offset: 0x420
    u32 mAIRetTargetUID;  // offset: 0x430
    bool mAiRetUseNoAvoidPos;  // offset: 0x434
    MtVector3 mAIRetNoAvoidPos;  // offset: 0x440
    u32 mAIRetJob06ChantActNo;  // offset: 0x450
    bool mAIRetEscapeThink;  // offset: 0x454
    bool mAIRetCanNotLightingAnchorEle;  // offset: 0x455
    bool mAIRetCanNotGoldBurst;  // offset: 0x456
    bool mAIRetCanNotClimb;  // offset: 0x457
    bool mAIRetNoUseMoveNoJump;  // offset: 0x458
};

class cPawnActInterface : public cAIObject
{
public:
    enum CTRL_FLAG
    {
        CTRL_FLAG_SETUP = 0,
        CTRL_FLAG_INIT = 1,
        CTRL_FLAG_UPDATE_END = 2,
        CTRL_FLAG_BREAK = 3,
        CTRL_FLAG_NUM = 4,
    };
    enum OPT_FLAG
    {
        OPT_FLAG_AUTO_DRAW_SWORD = 0,
        OPT_FLAG_NUM = 1,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<4>;
    using cCtrlFlag = nDDOUtility::cBitSet<4>;
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
    cPawnActInterface();
    virtual ~cPawnActInterface();
    void updateActInterface(uCharacter& owner);
    void updateActInterfaceAfter(uCharacter& owner);
    void resetActInter();
    bool isActInterEndOrBreak();
    bool isActInterEnd();
    bool isActInterBreak();
    cPawnActInterIO& actInterIO();
    const cPawnActInterIO& actInterIO() const;
    void addPawnActInterPre(cPawnActInterBase* pCode);
    void addPawnActInter(cPawnActInterBase* pCode);
    cOptFlag& actInterOptFlag();
    void reqBreakActInter();
private:
    void resetActInterCode();
    void resetActInterResult();
    void updateActInterfacePre(cPawnActInterIO& param, uCharacter& owner);
    void updateActInterfaceCore(cPawnActInterIO& param, uCharacter& owner);
    void updateAutoWeaponMode(cPawnActInterIO& param, uCharacter& owner);
    cPawnActInterBase* getActiveActInter();
    bool checkObjStatus(uCharacter& owner, u32 ost);
    bool updateLifeTimer(uCharacter& owner);
    bool isEnableRequestAction(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    void breakActInterCode(cPawnActInterBase* pInter);
    void disableActIter();
    void updateBeforeInput(uCharacter& owner);
    void updateAfterInput(uCharacter& owner);
private:
    cPawnActInterIO mActInterIO;  // offset: 0x10
    MtTypedArray<cPawnActInterBase> mActIntersPre;  // offset: 0x470
    MtTypedArray<cPawnActInterBase> mActIntersMain;  // offset: 0x490
    cOptFlag mActInterOptFlag;  // offset: 0x4b0
    u32 mActInterStep;  // offset: 0x4b4
    cCtrlFlag mActInterNowCtrl;  // offset: 0x4b8
    bool mActInterUpdate;  // offset: 0x4bc
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cPawnActInterBase::cPawnActInterBase() {
    this->mLifeFrame = 150.0f;
    this->mDisableNotice = static_cast<u32>(0);
}
