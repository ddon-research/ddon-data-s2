#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cAIGrid.h"
#include "../../XFramework/cAIObject.h"
#include "cGeneralPointPtr.h"
#include "cpInput.h"
#include "../../generated/shared/nDDOGame.h"
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
class cAIPawnSkillParamNode;
class cAITargetInfo;
class cAITargetInfoArray;
class cGeneralPoint;
class cGeneralPointPtr;
class cPawnEnableArea;
struct stMoveAngleRet;
class uBaseModel;
class uCharacter;
class uCoord;
class uDDOModel;
class uHuman;

// Declarations
class cPawnActInterActArrow;
class cPawnActInterActArrowChange;
class cPawnActInterActBindAnchor;
class cPawnActInterActChant;
class cPawnActInterActChargeMove;
class cPawnActInterActCircleCancel;
class cPawnActInterActElementArrow;
class cPawnActInterActElementChange;
class cPawnActInterActEnchant;
class cPawnActInterActLight;
class cPawnActInterActMedalChange;
class cPawnActInterActNo;
class cPawnActInterActProvoke;
class cPawnActInterActRapid;
class cPawnActInterAtkHerald;
class cPawnActInterAutoMotion;
class cPawnActInterBase;
class cPawnActInterBreak;
class cPawnActInterCliffClimb;
class cPawnActInterClimbBegin;
class cPawnActInterCommon;
class cPawnActInterDamage;
class cPawnActInterDisableMgr;
class cPawnActInterEnemyClimb;
class cPawnActInterEnemyClimbAttack;
class cPawnActInterEnemyClimbMove;
class cPawnActInterEscape;
class cPawnActInterEscapeNotice;
class cPawnActInterFree;
class cPawnActInterGuard;
class cPawnActInterGuardCancel;
class cPawnActInterHold;
class cPawnActInterHoldWait;
class cPawnActInterIO;
class cPawnActInterIfLen;
class cPawnActInterIn;
class cPawnActInterLantern;
class cPawnActInterMove;
class cPawnActInterMoveAlchemyTrap;
class cPawnActInterMoveEnergySpot;
class cPawnActInterMoveJump;
class cPawnActInterMoveLightingAnchor;
class cPawnActInterMoveReksElement;
class cPawnActInterRecover;
class cPawnActInterReload;
class cPawnActInterRot;
class cPawnActInterSearchCorePoint;
class cPawnActInterSearchMaskPoint;
class cPawnActInterStandOff;
class cPawnActInterStandOffHmEm;
class cPawnActInterTalkToPl;
class cPawnActInterWait;
class cPawnActInterWaitFootwork;
class cPawnActInterWarp;
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
using cAIPawnOrderFlag = nDDOUtility::cBitSet<256>;
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

class cPawnActInterCliffClimb : public cPawnActInterBase
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
    cPawnActInterCliffClimb();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterClimbBegin : public cPawnActInterBase
{
public:
    enum
    {
        FLAG_OFF = 0,
        FLAG_ON = 1,
        FLAG_NUM = 2,
    };
    enum
    {
        FREEU32_FLAG_AIR = 0,
        FREEU32_NUM = 1,
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
    cPawnActInterClimbBegin();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
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

class cPawnActInterDamage : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_ACT_TYPE = 0,
        FREEU32_ACT_TYPE_FREE = 1,
        FREEU32_NUM = 2,
    };
    enum
    {
        FREEF32_WAIT_FRAME = 0,
        FREEF32_NUM = 1,
    };
    enum
    {
        ACT_TYPE_NONE = 0,
        ACT_TYPE_ENGETSU = 1,
        ACT_TYPE_KAMAE = 2,
        ACT_TYPE_TAIMA = 3,
        ACT_TYPE_GOLD_BODY = 4,
        ACT_TYPE_JOB10CS02 = 5,
        ACT_TYPE_NUM = 6,
    };
    enum
    {
        ACT_FREE_GOLD_BODY_BEGIN = 0,
        ACT_FREE_GOLD_BODY_CONTINUE = 1,
        ACT_FREE_GOLD_BODY_END = 2,
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
    cPawnActInterDamage();
    virtual ~cPawnActInterDamage();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool isUseEngetsu(cPawnActInterIO& param, uCharacter& owner);
    bool isUseKamae(cPawnActInterIO& param, uCharacter& owner);
    bool isUseUkemi(cPawnActInterIO& param, uCharacter& owner);
    void updateInterEngetsu(cPawnActInterIO& param, uCharacter& owner);
    void updateInterKamae(cPawnActInterIO& param, uCharacter& owner);
    void updateInterUkemi(cPawnActInterIO& param, uCharacter& owner);
    f32 getUseSkillRate(cPawnActInterIO& param, uCharacter& owner);
    bool checkUseSkillStamina(cPawnActInterIO& param, uCharacter& owner);
    bool isUseTaima(cPawnActInterIO& param, uCharacter& owner);
    void updateInterTaima(cPawnActInterIO& param, uCharacter& owner);
    bool isUseGoldBody(cPawnActInterIO& param, uCharacter& owner);
    void updateInterGoldBody(cPawnActInterIO& param, uCharacter& owner);
    bool isEndGoldbody(cPawnActInterIO& param, uCharacter& owner);
    bool isUseJob10CS02(cPawnActInterIO& param, uCharacter& owner);
    void updateInterJob10CS02(cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterDisableMgr : public cAIObject
{
public:
    class MyDTI;
    class cNode;
public:
    using cNodes = nDDOUtility::cArray<cPawnActInterDisableMgr::cNode, 16>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cNode
    {
    public:
        cNode();
    public:
        cGeneralPointPtr mpTargetGP;  // offset: 0x0
        uCoord* mpTargetUnit;  // offset: 0x10
        u32 mPwActId;  // offset: 0x18
        f32 mDisableTimer;  // offset: 0x1c
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
    cPawnActInterDisableMgr();
    void updatePawnActInterDisableMgr(f32 deltaTime);
    void updatePtr();
    bool isDisableActInter(u32 pwActId, cGeneralPoint* pTarget);
    bool isDisableActInter(u32 pwActId, uCoord* pTarget);
    bool isDisableActInter(u32 pwActId);
    void addDisableActInter(u32 pwActId, cGeneralPoint* pTarget, f32 timer);
    void addDisableActInter(u32 pwActId, uCoord* pTarget, f32 timer);
    void addDisableActInter(u32 pwActId, f32 timer);
private:
    cNode* getNewNode();
    void clearNode(cNode& node);
    void updateNode(cNode& node, f32 deltaTime);
public:
    cNodes mNodes;  // offset: 0x8
    static MyDTI DTI;
};

class cPawnActInterEnemyClimb : public cPawnActInterBase
{
public:
    enum
    {
        ENEMY_STATUS_NONE = 0,
        ENEMY_STATUS_NORMAL = 1,
        ENEMY_STATUS_ANGER = 2,
        ENEMY_STATUS_NOT_CHANCE = 3,
    };
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        RNO_HANG = 0,
        RNO_HANG_WAIT = 1,
        RNO_NUM = 2,
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
    cPawnActInterEnemyClimb();
    virtual ~cPawnActInterEnemyClimb();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mEnemyStatus;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterEnemyClimbAttack : public cPawnActInterBase
{
public:
    enum
    {
        EM_CLIMB_TYPE_ATK = 0,
        EM_CLIMB_TYPE_SHAC = 1,
        EM_CLIMB_TYPE_NUM = 2,
    };
    enum
    {
        EM_CLIMB_TRG_ONE = 0,
        EM_CLIMB_TRG_RAPID = 1,
        EM_CLIMB_TRG_HOLD = 2,
        EM_CLIMB_TRG_CHARGE = 3,
        EM_CLIMB_CUSTOM_SKILL = 4,
        EM_CLIMB_CUSTOM_SKILL_RAPID = 5,
    };
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_OLD_ACT = 1,
        FREEU32_NUM = 2,
    };
    enum
    {
        FREEF32_CHARGE_TIME = 0,
        FREEF32_NUM = 1,
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
    cPawnActInterEnemyClimbAttack();
    virtual ~cPawnActInterEnemyClimbAttack();
private:
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool isEndClimbAttack(cPawnActInterIO& param, uCharacter& owner);
    bool isCSRapidEnd(cPawnActInterIO& param, uCharacter& owner, u32 action_no);
    bool isRapidEnd(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    u32 mType;  // offset: 0x10
    u32 mTrgType;  // offset: 0x14
    bool mClimbTargetOnly;  // offset: 0x18
    bool mIsUseUpGradeSkill;  // offset: 0x19
public:
    static MyDTI DTI;
};

class cPawnActInterEnemyClimbMove : public cPawnActInterBase
{
public:
    enum
    {
        FREEF32_ADJUST_FRAME = 0,
        FREEF32_SHUFFLE_FRAME = 1,
        FREEF32_HIT_LAND_FRAME = 2,
        FREEF32_NUM = 3,
    };
    enum
    {
        FREEU32_OLD_IS_V = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        FREEVEC_MV_INFO = 0,
        FREEVEC_NUM = 1,
    };
    enum OPT_FLAG
    {
        OPT_FLAG_GOLD_BURST = 0,
        OPT_FLAG_CONSIDER_ATTACK_POS = 1,
        OPT_FLAG_CONSIDER_HIT_LAND = 2,
        OPT_FLAG_NUM = 3,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<3>;
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
    cPawnActInterEnemyClimbMove();
    virtual ~cPawnActInterEnemyClimbMove();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    ACTINTER_CODERET updateMoveInfo(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos);
    bool calcGoalHangPos(cPawnActInterIO& param, uCharacter& owner, MtVector3* pPos);
    bool isEnableGoalHangPos(cPawnActInterIO& param, uCharacter& owner, MtVector3& targetPos, f32 range);
    bool isEnableGoalHangNode(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    cOptFlag mOptFlag;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cPawnActInterEscape : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        RNO_WAIT = 0,
        RNO_ESCAPE = 1,
        RNO_END_WAIT = 2,
        RNO_NUM = 3,
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
    cPawnActInterEscape();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    f32 mAngle;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cPawnActInterEscapeNotice : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_ACT_TYPE = 0,
        FREEU32_IS_ACT_NOTICE = 1,
        FREEU32_ACT_TYPE_OLD = 2,
        FREEU32_ACT_TYPE_FREE = 3,
        FREEU32_NUM = 4,
    };
    enum
    {
        FREEF32_NOTICE_CNT = 0,
        FREEF32_SAFE_HOLD_TM = 1,
        FREEU32_JUMP_CHECK_NG_TIMER = 2,
        FREEF32_NUM = 3,
    };
    enum
    {
        FREEVEC_SAFE_HOLD_POS = 0,
        FREEVEC_NUM = 1,
    };
    enum
    {
        ACT_TYPE_NONE = 0,
        ACT_TYPE_MOVE = 1,
        ACT_TYPE_DASH = 2,
        ACT_TYPE_JUMP = 3,
        ACT_TYPE_GUARD = 4,
        ACT_TYPE_JUST_GUARD = 5,
        ACT_TYPE_CHARIOT_MOVE = 6,
        ACT_TYPE_EVASION = 7,
        ACT_TYPE_BACKSTEP = 8,
        ACT_TYPE_SORASHI_KIRI = 9,
        ACT_TYPE_KAESHI_KERI = 10,
        ACT_TYPE_KAWASHI_KIRI = 11,
        ACT_TYPE_SHIELD_DODGE = 12,
        ACT_TYPE_NAGASHI_ANSATSU = 13,
        ACT_TYPE_STUN_SHIELD = 14,
        ACT_TYPE_MUSHIN_KIRI = 15,
        ACT_TYPE_ENDURE = 16,
        ACT_TYPE_TAIMA = 17,
        ACT_TYPE_CENTURION_SPIKE = 18,
        ACT_TYPE_AVOID_ALCHEMY = 19,
        ACT_TYPE_GOLD_BODY = 20,
        ACT_TYPE_JOB01_CS14 = 21,
        ACT_TYPE_JOB05_CS13 = 22,
        ACT_TYPE_AIR_TRAP = 23,
        ACT_TYPE_JOB10KAIHI = 24,
        ACT_TYPE_NUM = 25,
    };
    enum
    {
        ACT_NOTICE_INIT = 0,
        ACT_NOTICE_01 = 1,
        ACT_NOTICE_02 = 2,
        ACT_NOTICE_NUM = 3,
    };
    enum
    {
        ACT_FREE_CENTURION_BEGIN = 0,
        ACT_FREE_CENTURION_STEP2 = 1,
        ACT_FREE_CENTURION_END = 2,
        ACT_FREE_CENTURION_NUM = 3,
    };
    enum
    {
        ACT_FREE_KAWASHI_KIRI_BEGIN = 0,
        ACT_FREE_KAWASHI_KIRI_STEP2 = 1,
        ACT_FREE_KAWASHI_KIRI_END = 2,
        ACT_FREE_KAWASHI_KIRI_NUM = 3,
    };
    enum
    {
        ACT_FREE_GOLD_BODY_BEGIN = 0,
        ACT_FREE_GOLD_BODY_CONTINUE = 1,
        ACT_FREE_GOLD_BODY_END = 2,
    };
    enum
    {
        ACT_FREE_SHORYUTATE_BEGIN = 0,
        ACT_FREE_SHORYUTATE_SUCCESS = 1,
        ACT_FREE_SHORYUTATE_STRIKE = 2,
    };
    enum
    {
        ACT_FREE_GUARD_IMPACT_BEGIN = 0,
        ACT_FREE_GUARD_IMPACT_ACTION_WAIT = 1,
        ACT_FREE_GUARD_IMPACT_CONTINUE = 2,
        ACT_FREE_GUARD_IMPACT_END = 3,
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
    cPawnActInterEscapeNotice();
    virtual ~cPawnActInterEscapeNotice();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    void updateTypeMove(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeDash(cPawnActInterIO& param, uCharacter& owner);
    bool updateTypeJump(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeGuard(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeJustGuard(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeBackStep(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeActCommon(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    bool isEndTypeCenturionSpike(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscapeType(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscapeTypeNotice1(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscapeTypeNotice2(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice1Dash(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice1BackStep(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice1CenturionSpike(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice1MushinKiri(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2Counter(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2Atemi(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2GardNormal(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2NormalEscape(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscapeTypeNotice1GuardImpact(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    bool calcEscapeSafePos(cPawnActInterIO& param, uCharacter& owner, MtVector3& tar_pos, bool check_jump, bool is_dush_now);
    bool lotUseSkill(u32 lv, f32 lv1to10, f32 lv11to20, f32 lv21to30, f32 lv32over, bool use_npc);
    void updateTypeEvasion(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeSorashiKiri(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeKaeshiKiri(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeCenturionSpike(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeChariotMove(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeStunShield(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscaleTypeNotice2GardCustom(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    void updateTypeShieldDodge(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeEndure(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeKawashiKiri(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeMushinKiri(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeTaima(cPawnActInterIO& param, uCharacter& owner);
    bool isEndTypeKawashiKiri(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscaleTypeNotice2NormalSp(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2Taima(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    void updateTypeNagashiAnsatsu(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeAvoidAlchemy(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeGoldBody(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscaleTypeNotice2NormalAvoidAlchemy(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    u32 calcEscaleTypeNotice2GoldBody(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    bool isEndTypeGoldBody(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeShoryutate(cPawnActInterIO& param, uCharacter& owner);
    bool isEndTypeShoryutate(cPawnActInterIO& param, uCharacter& owner);
    void updateTypeGuardImpact(cPawnActInterIO& param, uCharacter& owner);
    bool isEndGuardImpact(cPawnActInterIO& param, uCharacter& owner);
    u32 calcEscaleTypeNotice2DolsTrap(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag);
    void updateTypeDolsTrap(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    u32 mNoticeFlag;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cPawnActInterFree : public cPawnActInterBase
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
    cPawnActInterFree();
    virtual ~cPawnActInterFree();
public:
    static MyDTI DTI;
};

class cPawnActInterGuard : public cPawnActInterBase
{
public:
    enum OPT_FLAG
    {
        OPT_FLAG_NML_GUARD = 0,
        OPT_FLAG_JUST_GUARD = 1,
        OPT_FLAG_MOVE = 2,
        OPT_FLAG_NUM = 3,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<3>;
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
    cPawnActInterGuard();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    cOptFlag mOptFlag;  // offset: 0x10
    f32 mMinGuardTime;  // offset: 0x14
public:
    static MyDTI DTI;
};

class cPawnActInterGuardCancel : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_COUNT = 0,
        FREEU32_GC_ACT_TYPE = 1,
        FREEU32_NUM = 2,
    };
    enum
    {
        GC_ACT_TYPE_NONE = 0,
        GC_ACT_TYPE_GC_HATE_ATTACK = 1,
        GC_ACT_TYPE_GC_BACK_STEP = 2,
        GC_ACT_TYPE_NUM = 3,
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
    cPawnActInterGuardCancel();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    u32 calcGcActType(cPawnActInterIO& param, uCharacter& owner);
    bool isAutoGuard(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateTypeGCHate(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateTypeGCBackStep(cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterHold : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        RNO_HOLD = 0,
        RNO_HOLD_WAIT = 1,
        RNO_NUM = 2,
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
    cPawnActInterHold();
    virtual ~cPawnActInterHold();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterHoldWait : public cPawnActInterBase
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
    cPawnActInterHoldWait();
    virtual ~cPawnActInterHoldWait();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterIfLen : public cPawnActInterBase
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
    cPawnActInterIfLen();
    virtual ~cPawnActInterIfLen();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    cPawnEnableArea mEnableArea;  // offset: 0x10
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

class cPawnActInterLantern : public cPawnActInterBase
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
    cPawnActInterLantern();
    virtual ~cPawnActInterLantern();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    bool mOnLantern;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterMove : public cPawnActInterBase
{
public:
    enum
    {
        POS_TYPE_TARGET_NEAR = 0,
        POS_TYPE_ENABLEAREA_RAND = 1,
        POS_TYPE_ENABLEAREA_NEAR = 2,
        POS_TYPE_TARGET_NEAR_EX = 3,
        POS_TYPE_TARGET_NEAR_EX_BASE_ACT = 4,
        POS_TYPE_TARGET_NEAR_EX_USE_HEALING = 5,
        POS_TYPE_NUM = 6,
    };
    enum OPT_FLAG
    {
        OPT_FLAG_ON_READY = 0,
        OPT_FLAG_AIR_SKIP = 1,
        OPT_FLAG_WALK = 2,
        OPT_FLAG_DIR_NEAR_EM = 3,
        OPT_FLAG_RUN = 4,
        OPT_FLAG_ENABLE_WIRE = 5,
        OPT_FLAG_ENABLE_HIKIYOSE = 6,
        OPT_FLAG_TGT_NO_MV_BREAK = 7,
        OPT_FLAG_TGT_AWAY_FROM_FRIEND = 8,
        OPT_FLAG_CONSIDER_QUICK_CHARGE = 9,
        OPT_FLAG_GOLD_BURST = 10,
        OPT_FLAG_QUICK_CHARGE = 11,
        OPT_FLAG_NUM = 12,
    };
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_USE_WIRE = 1,
        FREEU32_USE_GRID = 2,
        FREEU32_USE_ADV_MOVE_AREA = 3,
        FREEU32_NUM = 4,
    };
    enum
    {
        FREEGRID_ENABLE_RANGE = 0,
        FREEGRID_GOTO_GRID = 1,
        FREEGRID_NUM = 2,
    };
    enum
    {
        FREEF32_MV_ANGLE = 0,
        FREEF32_MV_TIMER = 1,
        FREEF32_MV_RANGE = 2,
        FREEF32_MV_TGT_CNT = 3,
        FREEF32_MV_CK_MV_END = 4,
        FREEF32_NUM = 5,
    };
    enum
    {
        FREEVEC_MV_GOTO_POS = 0,
        FREEVEC_MV_GRID_OLD = 1,
        FREEVEC_MV_TGT_OLD = 2,
        FREEVEC_NUM = 3,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MOVE = 1,
        RNO_NUM = 2,
    };
    enum
    {
        RNO_EX_INIT = 0,
        RNO_EX_CALC_ROUTE = 1,
        RNO_EX_ROUTE_LOOP = 2,
        RNO_EX_ROUTE_END = 3,
        RNO_EX_MOVE_LINER = 4,
        RNO_EX_MOVE_WIRE = 5,
        RNO_EX_MOVE_HIKIYOSE = 6,
        RNO_EX_NUM = 7,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<12>;
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
    cPawnActInterMove();
    virtual ~cPawnActInterMove();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual ACTINTER_CODERET updateInterEx(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 13
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    bool isEnableHealingArrowTraceEnd(cPawnActInterIO& param, uCharacter& owner, const MtVector3& target, const MtVector3& base_pos);
private:
    void updateInterReady(cPawnActInterIO& param, uCharacter& owner);
    bool calcFollowEnableArea(MtVector3* pDst, cPawnActInterIO& param, uCharacter& owner);
    MtVector3 getMoveTargetPos(cPawnActInterIO& param, uCharacter& owner);
    MtVector3 calcFollowBattlePos(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    bool isEnableActInterTargetHikiyose(uCharacter& owner, cGeneralPoint* pTarget) const;
    ACTINTER_CODERET updateInterHikiyose(cPawnActInterIO& param, uCharacter& owner, const MtVector3& tgtPos);
    ACTINTER_CODERET updateInterWire(cPawnActInterIO& param, uCharacter& owner, const MtVector3& tgtPos);
public:
    u32 mMovePosType;  // offset: 0x10
    s32 mEnableRangeActNo;  // offset: 0x14
    f32 mNearRange;  // offset: 0x18
    cOptFlag mOptFlag;  // offset: 0x1c
    static MyDTI DTI;
};

class cPawnActInterMoveAlchemyTrap : public cPawnActInterBase
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
    cPawnActInterMoveAlchemyTrap();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterMoveEnergySpot : public cPawnActInterBase
{
public:
    enum
    {
        FREEF32_WAIT_FRAME = 0,
        FREEF32_NUM = 1,
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
    cPawnActInterMoveEnergySpot();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterMoveJump : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_FLAG_AIR = 0,
        FREEU32_AIR_START = 1,
        FREEU32_NUM = 2,
    };
    enum
    {
        FREEF32_TIMER = 0,
        FREEF32_NUM = 1,
    };
    enum
    {
        FLAG_OFF = 0,
        FLAG_ON = 1,
        FLAG_NUM = 2,
    };
    enum
    {
        JUMP_FLAG_AIR_END = 1,
        JUMP_FLAG_BACK = 2,
        JUMP_FLAG_GRAND_NO_CHECK = 4,
        JUMP_FLAG_DISMOUNT = 8,
        JUMP_FLAG_END_HEIGHT_NEAR = 16,
        JUMP_FLAG_GRAND_CHECK_NEXT_ACTION = 32,
        JUMP_FLAG_NUM = 33,
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
    cPawnActInterMoveJump();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    u32 mJumpFlag;  // offset: 0x10
    f32 mHeightCheckLow;  // offset: 0x14
    f32 mHeightCheckHigh;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cPawnActInterMoveLightingAnchor : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        FREEGRID_ENABLE_RANGE = 0,
        FREEGRID_GOTO_GRID = 1,
        FREEGRID_NUM = 2,
    };
    enum
    {
        FREEVEC_MV_GOTO_POS = 0,
        FREEVEC_MV_TARGET_POS = 1,
        FREEVEC_NUM = 2,
    };
    enum
    {
        FREEF32_TARGET_UPDATE_TIME = 0,
        FREEF32_NUM = 1,
    };
    enum
    {
        RESULT_FIND_FAILED = 0,
        RESULT_FIND_FINISH = 1,
        RESULT_FIND_SUCCESS = 2,
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
    cPawnActInterMoveLightingAnchor();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    u32 calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterMoveReksElement : public cPawnActInterBase
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
    cPawnActInterMoveReksElement();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterRecover : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_OLD_ACT = 1,
        FREEU32_NUM = 2,
    };
    enum
    {
        RNO_MV = 0,
        RNO_DIR = 1,
        RNO_TOUCH = 2,
        RNO_NUM = 3,
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
    cPawnActInterRecover();
    virtual ~cPawnActInterRecover();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
private:
    bool isEndCheck(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    bool mIsTargetErosion;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterReload : public cPawnActInterBase
{
public:
    enum
    {
        FREEF32_RELOAD_TIME = 0,
        FREEF32_RELOAD_TIMING = 1,
        FREEF32_NUM = 2,
    };
    enum
    {
        FREEU32_DO_CMD = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        RELOAD_TYPE_NORMAL = 0,
        RELOAD_TYPE_ACTIVE = 1,
        RELOAD_TYPE_LV = 2,
        RELOAD_TYPE_NUM = 3,
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
    cPawnActInterReload();
    virtual ~cPawnActInterReload();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mReloadType;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterRot : public cPawnActInterBase
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
    cPawnActInterRot();
    virtual ~cPawnActInterRot();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterSearchCorePoint : public cPawnActInterBase
{
public:
    enum OPT_CORE_SEARCH_FLAG
    {
        OPT_CORE_SEARCH_FLAG_ONE_SEARCH = 0,
        OPT_CORE_EMPTY = 1,
        OPT_CORE_SEARCH_FLAG_NUM = 2,
    };
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_OLD_NUM = 1,
        FREEU32_LOCKON_ID = 2,
        FREEU32_NUM = 3,
    };
    enum
    {
        LOCKON_ID_BEGIN_NONE = 2147483647,
    };
    enum
    {
        FREEF32_TIMER = 0,
        FREEF32_NUM = 1,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<2>;
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
    cPawnActInterSearchCorePoint();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
private:
    ACTINTER_CODERET updateInterJob04(cPawnActInterIO& param, uCharacter& owner);
    bool isEncActionJob04(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateInterJob08(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateInterJob10(cPawnActInterIO& param, uCharacter& owner);
    u32 getActiveCorePointNum(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    cOptFlag mOptFlag;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterSearchMaskPoint : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_OLD_NUM = 1,
        FREEU32_LOCKON_ID = 2,
        FREEU32_NUM = 3,
    };
    enum
    {
        LOCKON_ID_BEGIN_NONE = 2147483647,
    };
    enum
    {
        FREEF32_TIMER = 0,
        FREEF32_NUM = 1,
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
    cPawnActInterSearchMaskPoint();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
private:
    ACTINTER_CODERET updateInterJob04(cPawnActInterIO& param, uCharacter& owner);
    bool isEncActionJob04(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateInterJob08(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateInterJob10(cPawnActInterIO& param, uCharacter& owner);
    u32 getActiveCorePointNum(cPawnActInterIO& param, uCharacter& owner);
    u32 getActiveCorePointAllNum(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    static MyDTI DTI;
};

class cPawnActInterStandOff : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        FREEF32_FRM_COUNT = 0,
        FREEF32_WAIT_FRAME = 1,
        FREEF32_ANGLE = 2,
        FREEF32_WANDER_FRAME = 3,
        FREEF32_SAFE_HOLD_TM = 4,
        FREEF32_NUM = 5,
    };
    enum
    {
        FREEVEC_SAFE_HOLD_POS = 0,
        FREEVEC_NUM = 1,
    };
    enum
    {
        RNO_MOVE_INIT = 0,
        RNO_MOVE_TO = 1,
        RNO_HOMING = 2,
        RNO_WAIT_INIT = 3,
        RNO_WAIT = 4,
        RNO_WANDER_INIT = 5,
        RNO_WANDER_RESET = 6,
        RNO_WANDER = 7,
        RNO_FRONT_INIT = 8,
        RNO_FRONT_MOVE = 9,
        RNO_BACK_INIT = 10,
        RNO_BACK_MOVE = 11,
        RNO_END = 12,
    };
    enum
    {
        GRID_ENABLE_RANGE = 0,
        GRID_NUM = 1,
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
    cPawnActInterStandOff();
    virtual ~cPawnActInterStandOff();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    MtVector3 calcStandOffPos(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    f32 mStandOffFrame;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterStandOffHmEm : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_MV_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        FREEF32_FRM_COUNT = 0,
        FREEF32_WAIT_FRAME = 1,
        FREEF32_NUM = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_HOMING = 1,
        RNO_WAIT_INIT = 2,
        RNO_WAIT = 3,
        RNO_WANDER_INIT = 4,
        RNO_WANDER_RESET = 5,
        RNO_WANDER = 6,
        RNO_END = 7,
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
    cPawnActInterStandOffHmEm();
    virtual ~cPawnActInterStandOffHmEm();
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    bool mRoateR;  // offset: 0x10
    f32 mStandOffFrame;  // offset: 0x14
    static MyDTI DTI;
};

class cPawnActInterTalkToPl : public cPawnActInterBase
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
    cPawnActInterTalkToPl();
private:
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterWait : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        RNO_WAIT = 0,
        RNO_MOVE = 1,
    };
    enum
    {
        FREEVEC_MV_GOTO_POS = 0,
        FREEVEC_NUM = 1,
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
    cPawnActInterWait();
    virtual ~cPawnActInterWait();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    bool mOrderClear;  // offset: 0x10
    f32 mWaitTime;  // offset: 0x14
    static MyDTI DTI;
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

class cPawnActInterWarp : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
    };
    enum
    {
        FREEF32_TIME = 0,
        FREEF32_NUM = 1,
    };
    enum
    {
        RNO_WAIT = 0,
        RNO_MOVE = 1,
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
    cPawnActInterWarp();
    virtual ~cPawnActInterWarp();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
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

class cPawnActInterActArrowChange : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEU32_NUM = 1,
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
    cPawnActInterActArrowChange();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mArrowActGroup;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterActMedalChange : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO = 0,
        FREEF32 = 1,
        FREEU32_NUM = 2,
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
    cPawnActInterActMedalChange();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
private:
    bool moveMedalChange(cPawnActInterIO& param, uCharacter& owner, u32 medalgroup, u32& localRno, f32& time);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mMedalActGroup;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterActNo : public cPawnActInterBase
{
public:
    enum
    {
        DOACT_TYPE_ACT_NO = 0,
        DOACT_TYPE_USER_IDX = 1,
        DOACT_TYPE_BASE_ACT_NO = 2,
        DOACT_TYPE_NUM = 3,
    };
    enum OPT_FLAG
    {
        OPT_FLAG_COMBO = 0,
        OPT_FLAG_LAND_END = 1,
        OPT_FLAG_ON_NOSEQ = 2,
        OPT_FLAG_NO_CHARGE = 3,
        OPT_FLAG_NO_ANGLE = 4,
        OPT_FLAG_ANGLE_ALL_WAY = 5,
        OPT_FLAG_CHARGE_MAG_WAV = 6,
        OPT_FLAG_MOVE_WAIT_CHARGE = 7,
        OPT_FLAG_ADD_ACT_LV06 = 8,
        OPT_FLAG_MSG_EX = 9,
        OPT_FLAG_NO_MSG_TGT_SELF = 10,
        OPT_FLAG_ONLY_TARGET_DOWN = 11,
        OPT_FLAG_GOLD_BURST = 12,
        OPT_FLAG_KAENGOROMO_CANCEL = 13,
        OPT_FLAG_NO_TGT_CHANGE_DOWN = 14,
        OPT_FLAG_NOT_AT_BOOST = 15,
        OPT_FLAG_NOW_SP_BOOST = 16,
        OPT_FLAG_SUP_COOLDOWN = 17,
        OPT_FLAG_SPIRIT_BARRIER_CHRARGED = 18,
        OPT_FLAG_NO_DISP_SPIRIT_BARRIER = 19,
        OPT_FLAG_ENABLE_SPIRIT_ANCHOR = 20,
        OPT_FLAG_EMPTY = 21,
        OPT_FLAG_NUM = 22,
    };
    enum
    {
        FREEU32_MSG_ON = 0,
        FREEU32_RNO = 1,
        FREEU32_OLD_ACT = 2,
        FREEU32_ACT_COUNT = 3,
        FREEU32_NUM = 4,
    };
    enum
    {
        FREEF32_COMBO_LOOP_TIME = 0,
        FREEF32_CNG_TIME = 1,
        FREEF32_FREE_TIME = 2,
        FREEF32_NUM = 3,
    };
    enum
    {
        MSG_OFF = 0,
        MSG_ON = 1,
    };
    enum
    {
        RNO_DIR = 0,
        RNO_READY = 1,
        RNO_ATK_INIT = 2,
        RNO_ATK_HIT_WAIT = 3,
        RNO_ATK = 4,
        RNO_COMBO = 5,
        RNO_CHARGE = 6,
        RNO_WAIT_INIT = 7,
        RNO_WAIT_NOSEQ = 8,
        RNO_WAIT = 9,
        RNO_NUM = 10,
    };
    enum
    {
        ENDSP_RET_NONE = 0,
        ENDSP_RET_END = 1,
        ENDSP_RET_CONTINUE = 2,
        ENDSP_RET_NUM = 3,
    };
public:
    class MyDTI;
public:
    using cOptFlag = nDDOUtility::cBitSet<22>;
    using checkEndSpFunc = u32(cPawnActInterActNo::*)(cPawnActInterIO&, uCharacter&);
    using endWaitSpFunc = bool(cPawnActInterActNo::*)(cPawnActInterIO&, uCharacter&);
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
    cPawnActInterActNo();
    virtual ~cPawnActInterActNo();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual bool isEnableActInterSpecial(uCharacter& owner) const;  // vtable slot 13
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
protected:
    u32 getDoActionNo(u32 baseActNo) const;
    virtual u32 getDoActionNo(cPawnActInterIO& param, uCharacter& owner) const;  // vtable slot 14
    u32 getDoActionNoCore() const;
    bool isEnableDoAction(cPawnActInterIO& param, uCharacter& owner) const;
    bool isEndCheck(cPawnActInterIO& param, uCharacter& owner);
    bool isComboEndCheck(cPawnActInterIO& param, uCharacter& owner) const;
    bool isNoneTarget(cPawnActInterIO& param, uCharacter& owner);
    void updateMessage(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    u32 checkEndCheckSpAttract(cPawnActInterIO& param, uCharacter& owner);
    u32 checkEndCheckSpCatapult(cPawnActInterIO& param, uCharacter& owner);
    u32 checkEndCheckJob03CS14(cPawnActInterIO& param, uCharacter& owner);
    void endWaitSp(cPawnActInterIO& param, uCharacter& owner) const;
    bool endWaitSpCatapult(cPawnActInterIO& param, uCharacter& owner) const;
    bool endWaitSpCatapultJump(cPawnActInterIO& param, uCharacter& owner) const;
    f32 getAddChargeTime(cPawnActInterIO& param, uCharacter& owner);
    bool isChageMagWave(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos);
    bool isJustChargeAct(cPawnActInterIO& param, uCharacter& owner);
    bool getArrowUpActNo(cPawnActInterIO& param, uCharacter& owner, u32* pDstNo);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mDoActType;  // offset: 0x10
    u32 mDoActNo;  // offset: 0x14
    u32 mDoAutoSituation;  // offset: 0x18
    f32 mDoEndMinFrame;  // offset: 0x1c
    cOptFlag mOptFlag;  // offset: 0x20
    static MyDTI DTI;
};

class cPawnActInterActProvoke : public cPawnActInterActNo
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
    cPawnActInterActProvoke();
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterActRapid : public cPawnActInterActNo
{
public:
    enum
    {
        JOB01CT03_BEGIN_NUM = 0,
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
    cPawnActInterActRapid();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool isLoopEnd(cPawnActInterIO& param, uCharacter& owner, bool& check_end);
public:
    static MyDTI DTI;
};

class cPawnActInterAtkHerald : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO0 = 0,
    };
    enum
    {
        RNO_REQ_ACT = 0,
        RNO_WAIT = 1,
        RNO_END = 2,
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
    cPawnActInterAtkHerald();
    virtual ~cPawnActInterAtkHerald();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mDoActNo;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnActInterAutoMotion : public cPawnActInterBase
{
public:
    enum
    {
        FREEU32_RNO0 = 0,
        FREEU32_LOT_MOT = 1,
        FREEU32_LOT_MV = 2,
        FREEU32_LOT_UID = 3,
        FREEU32_NUM = 4,
    };
    enum
    {
        FREEF32_MV_ANGLE = 0,
        FREEF32_LOOP_CNT = 1,
        FREEF32_NUM = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MV = 1,
        RNO_ANGLE = 2,
        RNO_ACT = 3,
        RNO_LOOP = 4,
        RNO_END = 5,
    };
    enum
    {
        FREEVEC_POS = 0,
        FREEVEC_NUM = 1,
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
    cPawnActInterAutoMotion();
private:
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    ACTINTER_CODERET updateInterPlRange(cPawnActInterIO& param, uCharacter& owner, f32 range);
    ACTINTER_CODERET updateInterArea(cPawnActInterIO& param, uCharacter& owner);
    ACTINTER_CODERET updateInterFindParty(cPawnActInterIO& param, uCharacter& owner);
    uCharacter* lotPartyPlayer(cPawnActInterIO& param, uCharacter& owner);
    uCharacter* lotPartyFindParty(cPawnActInterIO& param, uCharacter& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mAutoMotSituation;  // offset: 0x10
    bool mSetEmotion;  // offset: 0x14
    static MyDTI DTI;
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

class cPawnActInterActArrow : public cPawnActInterActNo
{
public:
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_JUST_FLAG = 5,
        FREEU32_JUST_ARROW_CHG_RNO = 6,
        FREEU32_NUM = 7,
    };
    enum
    {
        RNO_DIR = 0,
        RNO_READY = 1,
        RNO_CHG = 2,
        RNO_RELOAD = 3,
        RNO_ATK = 4,
        RNO_CHARGE = 5,
        RNO_CHARGE_ATK = 6,
        RNO_WAIT = 7,
        RNO_FINISH_WAIT = 8,
        RNO_NUM = 9,
    };
    enum
    {
        FREEF32_RELOAD_TIME = 3,
        FREEF32_CHARGE_TIME = 4,
        FREEF32_ADJUST_RANGE_TIME = 5,
        FREEF32_WAIT = 6,
        FREEF32_NUM = 7,
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
    cPawnActInterActArrow();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    bool isNeedArrowReload(cPawnActInterIO& param, uCharacter& owner);
    bool isMoveChargeAct(uCharacter& owner);
public:
    static MyDTI DTI;
};

class cPawnActInterActBindAnchor : public cPawnActInterActNo
{
public:
    enum
    {
        TYPE_BIND_ANCHOR = 0,
        TYPE_CIRCLE_SHIFT = 1,
        TYPE_HANDOFGOD = 2,
        TYPE_LIGHTING_ANCHOR = 3,
        TYPE_ICE_SPEAR = 4,
        TYPE_ICE_SPEAR_2 = 5,
        TYPE_AREA_SUPPORT = 6,
        TYPE_CIRCLE_SHIFT_MASK_POINT = 7,
        TYPE_NUM = 8,
    };
    enum
    {
        FREEU32_OLD_ORDER_ENABLE = 4,
        FREEU32_SUB_RNO = 5,
        FREEU32_ICE_SPEAR_HOLD = 6,
        FREEU32_NUM = 7,
    };
    enum
    {
        FREEF32_HOLD_TIME = 3,
        FREEF32_LA_OUT_RANGE_TIME = 4,
        FREEF32_IS_SHOOT_WAIT_TIME = 5,
        FREEF32_LA_HOLD_TIME = 6,
        FREEF32_NUM = 7,
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
    cPawnActInterActBindAnchor();
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    bool isEnableActInterPreCircleShift(uCharacter& owner) const;
    bool isEnableActInterTargetBindAnchor(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;
    bool isEnableActInterPreAreaSupport(uCharacter& owner) const;
    ACTINTER_CODERET updateContinueCircleShift(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueCircleShiftMaskPoint(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueBindAnchor(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueHandsOfGod(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueLightingAnchor(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueIceSpear(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    ACTINTER_CODERET updateContinueAreaSupport(cPawnActInterIO& param, uCharacter& owner, u32 actNo);
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mType;  // offset: 0x24
    f32 mHoldTime;  // offset: 0x28
    cAIPawnOrderFlag mEnableOrder;  // offset: 0x2c
    bool mIsEndDanger;  // offset: 0x4c
    f32 mStaminaRateMin;  // offset: 0x50
    f32 mStaminaRateMax;  // offset: 0x54
    static MyDTI DTI;
};

class cPawnActInterActChant : public cPawnActInterActNo
{
public:
    enum
    {
        CHANT_FLAG_SAVE_CHANT_ACT = 2,
        CHANT_FLAG_CHANT_NEXT = 4,
    };
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_CHANT_NEXT_RNO = 5,
        FREEU32_NUM = 6,
    };
    enum
    {
        RNO_DIR = 0,
        RNO_CHANT_INIT = 1,
        RNO_CHANT_WAIT = 2,
        RNO_MULTI_LOCK_ON = 3,
        RNO_MAGIC_INIT = 4,
        RNO_MAGIC_WAIT = 5,
        RNO_MAGIC_CONTINUED = 6,
        RNO_NUM = 7,
    };
    enum
    {
        FREEF32_MOVE_CORRECT_TIME = 3,
        FREEF32_NUM = 4,
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
    cPawnActInterActChant();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
private:
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual u32 getDoActionNo(cPawnActInterIO& param, uCharacter& owner) const;  // vtable slot 14
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    u32 mChantFlag;  // offset: 0x24
public:
    static MyDTI DTI;
};

class cPawnActInterActChargeMove : public cPawnActInterActNo
{
public:
    enum
    {
        FREEF32_USE_COUNTER = 3,
        FREEF32_WALK_INVALID = 4,
        FREEF32_WALK_COUNT = 5,
        FREEF32_NUM = 6,
    };
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_WALK_TYPE = 5,
        FREEU32_NUM = 6,
    };
    enum WALK_TYPE
    {
        WALK_TYPE_FRONT = 0,
        WALK_TYPE_BACK = 1,
        WALK_TYPE_NONE = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_DIR = 1,
        RNO_CHARGE_INIT = 2,
        RNO_CHARGE_WAIT = 3,
        RNO_CHARGE_END = 4,
        RNO_NUM = 5,
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
    cPawnActInterActChargeMove();
private:
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    f32 mUseTime;  // offset: 0x24
    static MyDTI DTI;
};

class cPawnActInterActCircleCancel : public cPawnActInterActNo
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
    cPawnActInterActCircleCancel();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterActElementArrow : public cPawnActInterActNo
{
public:
    enum
    {
        FREEF32_RELOAD_TIME = 3,
        FREEF32_CHARGE_TIME = 4,
        FREEF32_NUM = 5,
    };
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_NUM = 5,
    };
    enum
    {
        RNO_DIR = 0,
        RNO_READY = 1,
        RNO_CHG = 2,
        RNO_ATK = 3,
        RNO_CHARGE = 4,
        RNO_CHARGE_ATK = 5,
        RNO_JUST_CHARGE = 6,
        RNO_NUM = 7,
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
    cPawnActInterActElementArrow();
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPawnActInterActElementChange : public cPawnActInterActNo
{
public:
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_NUM = 5,
    };
    enum
    {
        RNO_ATK_INIT = 0,
        RNO_ATK = 1,
        RNO_NUM = 2,
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
    cPawnActInterActElementChange();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    u32 mElementType;  // offset: 0x24
    static MyDTI DTI;
};

class cPawnActInterActEnchant : public cPawnActInterActNo
{
public:
    enum
    {
        ENCHANT_NORMAL = 0,
        ENCHANT_TYPE_FRIEND_TGT_NO_ENCHANT_ELEM = 1,
        ENCHANT_TYPE_USE_ELEMENT_TYPE = 2,
    };
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_ENCHANT = 5,
        FREEU32_NUM = 6,
    };
    enum
    {
        FREEF32_TIME = 3,
        FREEF32_NUM = 4,
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
    cPawnActInterActEnchant();
    virtual bool isEnableActInterPre(uCharacter& owner) const;  // vtable slot 11
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
private:
    bool updateEnchantSelect(cPawnActInterIO& param, uCharacter& owner, u32& rno, f32& time);
    bool updateEnchantSelectSubJob05(cPawnActInterIO& param, uHuman& owner, u32& rno, f32& time);
    bool updateEnchantSelectSubJob09(cPawnActInterIO& param, uHuman& owner, u32& rno, f32& time);
    nDDOGame::ELEMENT_TYPE getUseElementType(cPawnActInterIO& param, uHuman& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
private:
    u32 mEnchantType;  // offset: 0x24
    u32 mElementType;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cPawnActInterActLight : public cPawnActInterActNo
{
public:
    enum
    {
        FREEF32_USE_COUNTER = 3,
        FREEF32_WALK_INVALID = 4,
        FREEF32_WALK_COUNT = 5,
        FREEF32_NUM = 6,
    };
    enum
    {
        FREEU32_RNO = 4,
        FREEU32_WALK_TYPE = 5,
        FREEU32_NUM = 6,
    };
    enum WALK_TYPE
    {
        WALK_TYPE_FRONT = 0,
        WALK_TYPE_BACK = 1,
        WALK_TYPE_NONE = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_DIR = 1,
        RNO_LIGHT_INIT = 2,
        RNO_LIGHT_WAIT = 3,
        RNO_LIGHT_END = 4,
        RNO_NUM = 5,
    };
    enum
    {
        SKILL_OCD = 0,
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
    cPawnActInterActLight();
private:
    virtual bool isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;  // vtable slot 12
    virtual ACTINTER_CODERET initInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 6
    virtual ACTINTER_CODERET updateInter(cPawnActInterIO& param, uCharacter& owner);  // vtable slot 7
    u32 getAddOcd(uCharacter& owner, const cAIPawnSkillParamNode* pNode, s32 actNo) const;
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    f32 mUseTime;  // offset: 0x24
    static MyDTI DTI;
};

inline void* cPawnActInterActArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActArrowChange::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterActArrowChange::cPawnActInterActArrowChange() {
    this->mArrowActGroup = 0;
}

inline void* cPawnActInterActBindAnchor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActChant::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActChargeMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActCircleCancel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActElementArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActElementChange::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActEnchant::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActLight::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActMedalChange::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterActMedalChange::cPawnActInterActMedalChange() {
    this->mMedalActGroup = 0;
}

inline void* cPawnActInterActNo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cPawnActInterActNo::getDoActionNoCore() const {
    return this->mDoActNo;
}

inline void* cPawnActInterActProvoke::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterActRapid::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterAtkHerald::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterAtkHerald::cPawnActInterAtkHerald() {
    this->mDoActNo = 0xFFFFFFFF;
}

inline void* cPawnActInterAutoMotion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterAutoMotion::cPawnActInterAutoMotion() {
    this->mAutoMotSituation = 0;
    this->mSetEmotion = true;
}

inline void* cPawnActInterBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterBase::cPawnActInterBase() {
    this->mLifeFrame = 150.0f;
    this->mDisableNotice = 0;
}

inline void* cPawnActInterBreak::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterCliffClimb::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterCliffClimb::cPawnActInterCliffClimb() {
}

inline void* cPawnActInterClimbBegin::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterClimbBegin::cPawnActInterClimbBegin() {
}

inline void* cPawnActInterCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterDamage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterDamage::cPawnActInterDamage() {
}

inline void* cPawnActInterDisableMgr::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterEnemyClimb::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterEnemyClimb::cPawnActInterEnemyClimb() {
    this->mEnemyStatus = 0;
}

inline void* cPawnActInterEnemyClimbAttack::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterEnemyClimbAttack::cPawnActInterEnemyClimbAttack() {
    this->mClimbTargetOnly = true;
    this->mType = 0;
    this->mTrgType = 1;
    this->mIsUseUpGradeSkill = false;
}

inline void* cPawnActInterEnemyClimbMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterEscape::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterEscape::cPawnActInterEscape() {
    this->mAngle = 0.0f;
}

inline void* cPawnActInterEscapeNotice::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterEscapeNotice::cPawnActInterEscapeNotice() {
    this->mNoticeFlag = 1;
}

inline void* cPawnActInterFree::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterFree::cPawnActInterFree() {
}

inline void* cPawnActInterGuard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterGuardCancel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterGuardCancel::cPawnActInterGuardCancel() {
}

inline void* cPawnActInterHold::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterHold::cPawnActInterHold() {
}

inline void* cPawnActInterHoldWait::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterHoldWait::cPawnActInterHoldWait() {
}

inline void* cPawnActInterIfLen::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterIfLen::cPawnActInterIfLen() {
    this->mEnableArea.mMinXZ = 0.0f;
    this->mEnableArea.mMaxXZ = 700.0f;
    this->mEnableArea.mMinY = -500.0f;
    this->mEnableArea.mMaxY = 500.0f;
}

inline void* cPawnActInterLantern::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterLantern::cPawnActInterLantern() {
    this->mOnLantern = false;
}

inline void* cPawnActInterMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterMoveAlchemyTrap::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterMoveAlchemyTrap::cPawnActInterMoveAlchemyTrap() {
}

inline void* cPawnActInterMoveEnergySpot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterMoveEnergySpot::cPawnActInterMoveEnergySpot() {
}

inline void* cPawnActInterMoveJump::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterMoveJump::cPawnActInterMoveJump() {
    this->mJumpFlag = 0;
    this->mHeightCheckLow = 0.0f;
    this->mHeightCheckHigh = 100.0f;
}

inline void* cPawnActInterMoveLightingAnchor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterMoveLightingAnchor::cPawnActInterMoveLightingAnchor() {
}

inline void* cPawnActInterMoveReksElement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterMoveReksElement::cPawnActInterMoveReksElement() {
}

inline void* cPawnActInterRecover::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterRecover::cPawnActInterRecover() {
    this->mIsTargetErosion = false;
}

inline void* cPawnActInterReload::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterReload::cPawnActInterReload() {
    this->mReloadType = 0;
}

inline void* cPawnActInterRot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterRot::cPawnActInterRot() {
}

inline void* cPawnActInterSearchCorePoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterSearchMaskPoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterSearchMaskPoint::cPawnActInterSearchMaskPoint() {
}

inline void* cPawnActInterStandOff::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterStandOff::cPawnActInterStandOff() {
    this->mStandOffFrame = 120.0f;
}

inline void* cPawnActInterStandOffHmEm::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterStandOffHmEm::cPawnActInterStandOffHmEm() {
    this->mStandOffFrame = 120.0f;
    this->mRoateR = false;
}

inline void* cPawnActInterTalkToPl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterTalkToPl::cPawnActInterTalkToPl() {
}

inline void* cPawnActInterWait::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterWait::cPawnActInterWait() {
    this->mOrderClear = false;
    this->mWaitTime = -1.0f;
}

inline void* cPawnActInterWaitFootwork::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPawnActInterWarp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPawnActInterWarp::cPawnActInterWarp() {
}

inline void* cPawnActInterface::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
