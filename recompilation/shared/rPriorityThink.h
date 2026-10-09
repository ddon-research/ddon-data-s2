#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cAIObject.h"
#include "cGeneralPoint.h"
#include "nDDOUtility.h"
#include "nPawn.h"
#include "rPawnAI.h"
#include "rTbl2.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtVector3;
class cAIGrid;
class cAITargetInfoArray;
class cGeneralPoint;
class cPawnAIAction;
class cPawnActInterDisableMgr;
class cPawnEnableArea;
class uCharacter;
class uDDOModel;
class uEnemy;

// Declarations
class cPrioThkCmd;
class cPrioThkCode;
class cPrioThkIO;
class rPriorityThink;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnOrderFlag = nDDOUtility::cBitSet<256>;
using cAIPawnOrderGroupArray = nDDOUtility::cArray<unsigned int, 3>;
using cAIPawnOrderTypeFlag = nDDOUtility::cBitSet<4>;
using cAIPawnStateCounter = nDDOUtility::cArray<float, 17>;
using cAIPawnTalkSituationFlag = nDDOUtility::cBitSet<46>;
using cPrioThkOtherFlag = nDDOUtility::cBitSet<6>;
using cPrioThkRetActFlag = nDDOUtility::cBitSet<2>;
using cPrioThkStatusFlag = nDDOUtility::cBitSet<64>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrioThkCmd : public cAIResource
{
public:
    class MyDTI;
    class cTmpResultIO;
    class cTmpResult;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTmpResult : public MtObject
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
        cTmpResult();
    public:
        s32 mRate;  // offset: 0x8
        cGeneralPoint* mpTarget;  // offset: 0x10
        cPawnAIAction* mpPawnAct;  // offset: 0x18
        cAIPawnActionGroupFlag mActGroupFlag;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cTmpResultIO
    {
    public:
        cTmpResultIO();
    public:
        MtTypedArray<cPrioThkCmd::cTmpResult> mResult;  // offset: 0x0
        s32 mPrio;  // offset: 0x20
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
    cPrioThkCmd();
    virtual ~cPrioThkCmd();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader&);  // vtable slot 7
    virtual void save(MtDataWriter&);  // vtable slot 8
protected:
    cGeneralPoint* findNearGeneralPoint(MtTypedArray<cGeneralPoint>& src, uDDOModel& owner, f32 maxLen);
    cPawnAIAction* findActInterfaceFromIDEnable(cPrioThkIO& io, uDDOModel& owner, u32 id);
    void findActInterfaceFromGroupEnable(MtTypedArray<cPawnAIAction>* pDst, cPrioThkIO& io, uDDOModel& owner, u32 group);
    void findActInterfaceFromGroupEnable(MtTypedArray<cPawnAIAction>* pDst, cPrioThkIO& io, uDDOModel& owner, const cAIPawnActionGroupFlag& group);
    u32 getEnablePawnActID(cPrioThkIO& io, uDDOModel& owner, MT_CTSTR name);
    void findEnableActID(cPrioThkIO& io, uDDOModel& owner, cTmpResultIO& dst, MtTypedArray<cPawnAIAction>& actTbl, MtTypedArray<cGeneralPoint>& target);
    void findEnableActID(cPrioThkIO& io, uDDOModel& owner, cTmpResultIO& dst, MtTypedArray<cPawnAIAction>& actTbl, cGeneralPoint* pTarget);
    void addEnableActID(cPrioThkIO& io, uDDOModel& owner, cTmpResultIO& dst, cPawnAIAction* pAct, MtTypedArray<cGeneralPoint> target);
    void addEnableActID(cPrioThkIO& io, uDDOModel& owner, cTmpResultIO& dst, cPawnAIAction* pAct, cGeneralPoint* pTarget, s32 prio, const cAIPawnActionGroupFlag* pFlag);
    void calcDoAction(cPrioThkIO& io, uCharacter& owner, cTmpResultIO& dst, MtTypedArray<cPawnAIAction>& actTbl, bool isSupport);
    void createFollowAreaTargetDefalt(cPrioThkIO& io, uDDOModel& owner);
    cTmpResult* lotEnableActID(cTmpResultIO& src);
    bool isEnableStageWarp(cPrioThkIO& io, uDDOModel& owner);
    void searchPartyOtherPlayer(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst);
    void searchPartyPawn(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst);
    bool isEnablePrioThkStatusFlag(const cPrioThkStatusFlag& flag, uDDOModel& target);
    bool isLanternEquip(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isLanternOn(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isLanternOnMaster(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isOcdWepTimer(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isOcdWepMaster(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isOcdOilAndSpreadTimer(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isOcdAlmostOilOwner(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    bool isEnableActInterAttackPre(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterMeStamina(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    void doPrioThkRetActFlag(cPrioThkIO& io, uDDOModel& owner, const cPrioThkRetActFlag& flag);
    bool isEnableActInterSupportPre(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportNearEm(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeHp(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeFgageStack(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeNoElmGuard(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeNoCircle(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeNoField(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeNoSpot(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeArrowChange(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeGuardBits(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportMeForcegageInsufficiency(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportPartyNoEnchant(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportPartyNoElmC(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportOrderElm(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportOrderNoAttackOff(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportSameElemWithOrder(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
    bool isEnableActInterSupportAfter(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtWeakKuzushi(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtWeakElm(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtHold(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtNoBadPhysAtk(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtNoBadPhysDef(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtNoOcdc(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    bool isEnableActInterSupportTgtOcdImmunity(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const;
    void getProperTarget(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst, cPawnAIAction* pAct, bool isSupport);
    void getProperTargetTarget(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst, bool(*checkFunc)(uCharacter&));
    bool isEnableActInterSupportMeMedalChange(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const;
public:
    static uDDOModel* getGeneralPointOwner(cGeneralPoint* pGp);
    static uCharacter* getGeneralPointOwnerCharacter(cGeneralPoint* pGp);
    static uEnemy* getGeneralPointOwnerEnemy(cGeneralPoint* pGp);
public:
    static MyDTI DTI;
};

class cPrioThkCode : public cAIResource
{
public:
    enum
    {
        FLAG_NONE = 0,
        FLAG_DISABLE_PL_DEAD = 1,
        FLAG_SHUFFLE = 2,
        FLAG_FILL = -1,
    };
    enum
    {
        DATA_VERSION = 47,
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
    cPrioThkCode();
    virtual ~cPrioThkCode();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner);  // vtable slot 6
    static u32 convID(MT_CTSTR name);
    static cPrioThkCode* findCode(rPriorityThink* pPrioThink, u32 id);
    bool getDisablePlDead() const;
    bool getShuffle() const;
public:
    MtTypedArray<cPrioThkCmd> mCommands;  // offset: 0x8
    s32 mPrio;  // offset: 0x28
    u32 mID;  // offset: 0x2c
    cAIPawnOrderFlag mDisableOrder;  // offset: 0x30
    cAIPawnOrderTypeFlag mDisableTypeFlag;  // offset: 0x50
    u32 mCodeFlag;  // offset: 0x54
    static MyDTI DTI;
};

class cPrioThkIO : public cAIObject
{
public:
    enum
    {
        RESULT_TYPE_NONE = 0,
        RESULT_TYPE_TARGET_POINT = 1,
        RESULT_TYPE_TARGET_POS = 2,
        RESULT_TYPE_TARGET_NONE = 3,
        RESULT_TYPE_NUM = 4,
    };
    enum
    {
        DATA_ID_NONE = 0,
        DATA_ID_STANDOFFTIME = 1,
        DATA_ID_NUM = 2,
    };
    enum
    {
        PRIO_THINK_PRIO_DEF = 0,
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
    cPrioThkIO();
    void clearResultAll();
    void clearResultCode();
    void clearResultExec();
    void resetResultNowThink();
    f32 getDataF32(u32 dataType, f32 def);
public:
    MtTypedArray<cPawnAIAction> mAIActions;  // offset: 0x8
    cPawnActInterDisableMgr* mpAIActInterDisableMgr;  // offset: 0x28
    MtVector3 mBaseFollowAreaOfsPos;  // offset: 0x30
    f32 mBaseFollowAreaAngle;  // offset: 0x40
    cPawnEnableArea mBaseFollowAreaEnable;  // offset: 0x48
    cPawnEnableArea mBaseFollowAreaTarget;  // offset: 0x68
    uCharacter* mpMasterCharacter;  // offset: 0x88
    cAITargetInfoArray* mpPartyInfoArray;  // offset: 0x90
    cAITargetInfoArray* mpEnemyInfoArray;  // offset: 0x98
    cAITargetInfoArray* mpAnimalInfoArray;  // offset: 0xa0
    cAITargetInfoArray* mpOmInfoArray;  // offset: 0xa8
    uCharacter* mpNpc;  // offset: 0xb0
    f32 mStandOffTime;  // offset: 0xb8
    u32 mThinkBattleStatus;  // offset: 0xbc
    cAIPawnOrderGroupArray mAIPawnOaderID;  // offset: 0xc0
    cAIGrid* mpGridNotice;  // offset: 0xd0
    cAIGrid* mpGridDanger;  // offset: 0xd8
    cAIPawnTalkSituationFlag mAIPawnTalkSituationFlag;  // offset: 0xe0
    uDDOModel* mpCheckHitUnit;  // offset: 0xe8
    cAIPawnStateCounter mAIPawnStateCounter;  // offset: 0xf0
    u32 mActiveOrderId;  // offset: 0x134
    u32 mDisableNotice;  // offset: 0x138
    f32 mArrowChgIntervalTimer;  // offset: 0x13c
    f32 mNoMoveOnFrame;  // offset: 0x140
    cPrioThkOtherFlag mPrioThkOtherFlag;  // offset: 0x144
    s32 mCtrlPrioThinkPrio;  // offset: 0x148
    u32 mResultType;  // offset: 0x14c
    MtTypedArray<cGeneralPoint> mResultTarget;  // offset: 0x150
    MtVector3 mResultTargetRealPos;  // offset: 0x170
    f32 mResultRange;  // offset: 0x180
    u32 mResultActInterID;  // offset: 0x184
    f32 mResultTargetFrame;  // offset: 0x188
    f32 mResultActBreakDisableTime;  // offset: 0x18c
    bool mResultOrderAction;  // offset: 0x190
    bool mResultActEndOrderClear;  // offset: 0x191
    MtTypedArray<uDDOModel> mResultFailedTarget;  // offset: 0x198
    u32 mResultReqFlag;  // offset: 0x1b8
    cAIPawnActionGroupFlag mResultReqGroup;  // offset: 0x1bc
    nDDOUtility::cArray<float, 4> mResultFreeParamF32;  // offset: 0x1cc
    u32 mResultFollowType;  // offset: 0x1dc
    MtVector3 mResultFollowOfsPos;  // offset: 0x1e0
    f32 mResultFollowAngle;  // offset: 0x1f0
    cPawnEnableArea mResultFollowAreaEnable;  // offset: 0x1f8
    cPawnEnableArea mResultFollowAreaTarget;  // offset: 0x218
    u32 mResultNowThinkID;  // offset: 0x238
    f32 mActionCureArrowWaitTimer;  // offset: 0x23c
    f32 mActionMedalChgWaitTimer;  // offset: 0x240
    f32 mActionSpiritStoneHealWaitTimer;  // offset: 0x244
    f32 mActionSpiritStoneHealStaminaWaitTimer;  // offset: 0x248
    f32 mActionSpiritStoneSupWaitTimer;  // offset: 0x24c
    f32 mErosionRescueCoolDownTimer;  // offset: 0x250
    f32 mSearchMaskEffectTimer;  // offset: 0x254
    f32 mReceiveErosionRescueCoolDownTimer;  // offset: 0x258
    static MyDTI DTI;
};

class rPriorityThink : public rTbl2<cPrioThkCode>
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
    rPriorityThink();
    virtual ~rPriorityThink();
    virtual bool loadData(MtDataReader& in, cPrioThkCode* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cPrioThkCmd::cPrioThkCmd() {
}

// Inline, no code of its own: checked where it is inlined.
inline rPriorityThink::rPriorityThink() {
}
