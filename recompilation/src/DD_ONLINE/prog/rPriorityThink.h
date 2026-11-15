#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cAIObject.h"
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
class cAIPawnOrderParam;
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
class cPrioThkCmdAddAnimalCoop;
class cPrioThkCmdAddAnimalProtect;
class cPrioThkCmdAddBase;
class cPrioThkCmdAddBreakTarget;
class cPrioThkCmdAddCoreNearTarget;
class cPrioThkCmdAddEnemy;
class cPrioThkCmdAddEnemyClimb;
class cPrioThkCmdAddEnemyHp;
class cPrioThkCmdAddEnemyRange;
class cPrioThkCmdAddErosionRequest;
class cPrioThkCmdAddEvaluation;
class cPrioThkCmdAddHiPrioEnemy;
class cPrioThkCmdAddParty;
class cPrioThkCmdAddPartyAction;
class cPrioThkCmdAddPartyHp;
class cPrioThkCmdAddPartyHpForShift;
class cPrioThkCmdAddPartyOcd;
class cPrioThkCmdAddPartyStamina;
class cPrioThkCmdAddPartyStatus;
class cPrioThkCmdConCureSpot;
class cPrioThkCmdConEventOmElf;
class cPrioThkCmdConFollowArea;
class cPrioThkCmdConHealFountain;
class cPrioThkCmdConHealSpot;
class cPrioThkCmdConSpot;
class cPrioThkCmdConSpotExt;
class cPrioThkCmdFilTargetStatus;
class cPrioThkCmdIsAction;
class cPrioThkCmdIsAutoSituation;
class cPrioThkCmdIsBakuensen;
class cPrioThkCmdIsBase;
class cPrioThkCmdIsBattle;
class cPrioThkCmdIsBattleAct;
class cPrioThkCmdIsCanErosionRescue;
class cPrioThkCmdIsCanSetEmotion;
class cPrioThkCmdIsDamage;
class cPrioThkCmdIsDanger;
class cPrioThkCmdIsEnableArea;
class cPrioThkCmdIsEvaluation;
class cPrioThkCmdIsFollowEnable;
class cPrioThkCmdIsGuardBit;
class cPrioThkCmdIsHp;
class cPrioThkCmdIsImpactForce;
class cPrioThkCmdIsLanternOff;
class cPrioThkCmdIsLanternOn;
class cPrioThkCmdIsMasterDead;
class cPrioThkCmdIsNotice;
class cPrioThkCmdIsOrder;
class cPrioThkCmdIsOtherFlag;
class cPrioThkCmdIsPartyJob;
class cPrioThkCmdIsReleaseAlchemy;
class cPrioThkCmdIsReload;
class cPrioThkCmdIsShl;
class cPrioThkCmdIsStageNo;
class cPrioThkCmdIsStageType;
class cPrioThkCmdIsStamina;
class cPrioThkCmdIsStandOffTime;
class cPrioThkCmdIsStatus;
class cPrioThkCmdIsStatusCounter;
class cPrioThkCmdIsStatusEx;
class cPrioThkCmdIsTalkWithPl;
class cPrioThkCmdIsTarget;
class cPrioThkCmdRetActGoldBurst;
class cPrioThkCmdRetActGroup;
class cPrioThkCmdRetActInter;
class cPrioThkCmdRetActInterTarget;
class cPrioThkCmdRetCureAct;
class cPrioThkCmdRetDispersion;
class cPrioThkCmdRetEnemyTable;
class cPrioThkCmdRetFollow;
class cPrioThkCmdRetFreeParam;
class cPrioThkCmdRetGoto;
class cPrioThkCmdRetHealAct;
class cPrioThkCmdRetNoMoveJump;
class cPrioThkCmdRetOrder;
class cPrioThkCmdRetRouteInfo;
class cPrioThkCmdRetStaminaHealAct;
class cPrioThkCmdRetSupport;
class cPrioThkCode;
class cPrioThkIO;
class rPriorityThink;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnOcdArray = nDDOUtility::cArray<unsigned int, 16>;
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

class cPrioThkCmdAddBase : public cPrioThkCmd
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
    cPrioThkCmdAddBase();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
protected:
    void addResultAllEnemy(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    bool mFilter;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdAddBreakTarget : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddBreakTarget();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPrioThkCmdAddCoreNearTarget : public cPrioThkCmdAddBase
{
public:
    enum
    {
        TARGET_TYPE_ALL = 0,
        TARGET_TYPE_NONE_JOB08_CS11_EM = 1,
        TARGET_TYPE_NUM = 2,
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
    cPrioThkCmdAddCoreNearTarget();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mTargetType;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdAddEnemy : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddEnemy();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mHpRateMin;  // offset: 0xc
    f32 mHpRateMax;  // offset: 0x10
    f32 mLenXZMin;  // offset: 0x14
    f32 mLenXZMax;  // offset: 0x18
    u32 mAddSortType;  // offset: 0x1c
    static MyDTI DTI;
};

class cPrioThkCmdAddEnemyClimb : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddEnemyClimb();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdAddEnemyHp : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddEnemyHp();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    bool mIsMax;  // offset: 0x9
    static MyDTI DTI;
};

class cPrioThkCmdAddEnemyRange : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddEnemyRange();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    bool mIsFar;  // offset: 0x9
    static MyDTI DTI;
};

class cPrioThkCmdAddErosionRequest : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddErosionRequest();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPrioThkCmdAddEvaluation : public cPrioThkCmdAddBase
{
public:
    enum
    {
        TARGET_TYPE_MINE = 0,
        TARGET_TYPE_OTHER = 1,
        TARGET_TYPE_NUM = 2,
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
    cPrioThkCmdAddEvaluation();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    bool isEvaTarget(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, uCharacter* pChar);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mTargetType;  // offset: 0xc
    f32 mEveValueMin;  // offset: 0x10
    f32 mEveValueMax;  // offset: 0x14
    static MyDTI DTI;
};

class cPrioThkCmdAddHiPrioEnemy : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddHiPrioEnemy();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mRemoveFlgs;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdAddParty : public cPrioThkCmdAddBase
{
public:
    enum
    {
        TARGET_PARTY_MINE = 1,
        TARGET_PARTY_MASTER = 2,
        TARGET_PARTY_OTHER_PARTY = 4,
        TARGET_PARTY_PARTY_NPC = 8,
        TARGET_PARTY_OTHER_NPC = 16,
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
    cPrioThkCmdAddParty();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    void checkSub(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, uCharacter* pChar);
protected:
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    bool isTargetParty(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mTargetPartyFlag;  // offset: 0xc
    f32 mTargetRange;  // offset: 0x10
    u32 mAddSortType;  // offset: 0x14
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyAction : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyAction();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mDoActNo;  // offset: 0x18
    s32 mDoActNoJob;  // offset: 0x1c
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyHp : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyHp();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mHpRateMin;  // offset: 0x18
    f32 mHpRateMax;  // offset: 0x1c
    f32 mWhiteHpRateMin;  // offset: 0x20
    f32 mWhiteHpRateMax;  // offset: 0x24
    bool mWhiteNoZero;  // offset: 0x28
    f32 mTargetDistanceMin;  // offset: 0x2c
    f32 mTargetDistanceY;  // offset: 0x30
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyHpForShift : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyHpForShift();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mHpRateMin;  // offset: 0x18
    f32 mHpRateMax;  // offset: 0x1c
    f32 mWhiteHpRateMin;  // offset: 0x20
    f32 mWhiteHpRateMax;  // offset: 0x24
    bool mWhiteNoZero;  // offset: 0x28
    f32 mTargetDistanceMin;  // offset: 0x2c
    f32 mTargetDistanceY;  // offset: 0x30
    f32 mStaminaRateMin;  // offset: 0x34
    f32 mStaminaRateMax;  // offset: 0x38
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyOcd : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyOcd();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cAIPawnOcdArray mEnableOcd;  // offset: 0x18
    cAIPawnOcdArray mDisableOcd;  // offset: 0x58
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyStamina : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyStamina();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mStaminaRateMin;  // offset: 0x18
    f32 mStaminaRateMax;  // offset: 0x1c
    bool mIgnoreTired;  // offset: 0x20
    static MyDTI DTI;
};

class cPrioThkCmdAddPartyStatus : public cPrioThkCmdAddParty
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
    cPrioThkCmdAddPartyStatus();
    virtual u32 checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 9
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cPrioThkStatusFlag mPrioThkStatusFlag;  // offset: 0x18
    static MyDTI DTI;
};

class cPrioThkCmdConCureSpot : public cPrioThkCmd
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
    cPrioThkCmdConCureSpot();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdConEventOmElf : public cPrioThkCmd
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
    cPrioThkCmdConEventOmElf();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdConFollowArea : public cPrioThkCmd
{
public:
    enum
    {
        POS_TYPE_MASTER = 0,
        POS_TYPE_TARGET = 1,
        POS_TYPE_PRECAUTION = 2,
        POS_TYPE_NUM = 3,
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
    cPrioThkCmdConFollowArea();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mAreaType;  // offset: 0x8
    cPawnEnableArea mAreaEnable;  // offset: 0x10
    u32 mAreaPosType;  // offset: 0x30
    f32 mAreaPosOfsZ;  // offset: 0x34
    bool mNoContinue;  // offset: 0x38
    static MyDTI DTI;
};

class cPrioThkCmdConHealFountain : public cPrioThkCmd
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
    cPrioThkCmdConHealFountain();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdConHealSpot : public cPrioThkCmd
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
    cPrioThkCmdConHealSpot();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdConSpot : public cPrioThkCmd
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
    cPrioThkCmdConSpot();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mShlId;  // offset: 0x8
    f32 mLength;  // offset: 0xc
    f32 mFollowRange;  // offset: 0x10
    static MyDTI DTI;
};

class cPrioThkCmdConSpotExt : public cPrioThkCmd
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
    cPrioThkCmdConSpotExt();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mShlId;  // offset: 0x8
    f32 mLength;  // offset: 0xc
    f32 mThroughLength;  // offset: 0x10
    f32 mFollowRange;  // offset: 0x14
    static MyDTI DTI;
};

class cPrioThkCmdFilTargetStatus : public cPrioThkCmd
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
    cPrioThkCmdFilTargetStatus();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cPrioThkStatusFlag mPrioThkStatusFlag;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdIsBase : public cPrioThkCmd
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
    cPrioThkCmdIsBase();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    bool isRet() const;
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    bool mIs;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdIsBattle : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsBattle();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsBattleAct : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsBattleAct();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsCanErosionRescue : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsCanErosionRescue();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsCanSetEmotion : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsCanSetEmotion();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsDamage : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsDamage();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsDanger : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsDanger();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    bool isDangerGridCheck(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cAIGrid* pGrid);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mRange;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsEnableArea : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsEnableArea();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsEvaluation : public cPrioThkCmdIsBase
{
public:
    enum
    {
        TARGET_TYPE_MINE = 0,
        TARGET_TYPE_OTHER = 1,
        TARGET_TYPE_NUM = 2,
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
    cPrioThkCmdIsEvaluation();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mTargetType;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsFollowEnable : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsFollowEnable();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsGuardBit : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsGuardBit();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mCheckGuardBitNum;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsHp : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsHp();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mHpMin;  // offset: 0xc
    f32 mHpMax;  // offset: 0x10
    static MyDTI DTI;
};

class cPrioThkCmdIsImpactForce : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsImpactForce();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsLanternOff : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsLanternOff();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsLanternOn : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsLanternOn();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsMasterDead : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsMasterDead();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsNotice : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsNotice();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mNoticeFlag;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsOrder : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsOrder();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cAIPawnOrderFlag mOrderFlag;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsOtherFlag : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsOtherFlag();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cPrioThkOtherFlag mCheckPrioThkOtherFlag;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsPartyJob : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsPartyJob();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsReleaseAlchemy : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsReleaseAlchemy();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsReload : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsReload();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    s32 mUnderNum;  // offset: 0xc
    f32 mUnderRate;  // offset: 0x10
    static MyDTI DTI;
};

class cPrioThkCmdIsShl : public cPrioThkCmdIsBase
{
public:
    enum
    {
        CHK_TYPE_ALL = 0,
        CHK_TYPE_PL = 1,
        CHK_TYPE_EM = 2,
        CHK_TYPE_MINE = 3,
        CHK_TYPE_NUM = 4,
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
    cPrioThkCmdIsShl();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mShlId;  // offset: 0xc
    f32 mLength;  // offset: 0x10
    u32 mChkType;  // offset: 0x14
    static MyDTI DTI;
};

class cPrioThkCmdIsStageNo : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStageNo();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    s32 mStageNo;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsStageType : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStageType();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mStageTypeFlag;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsStamina : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStamina();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    f32 mStaminaMin;  // offset: 0xc
    f32 mStaminaMax;  // offset: 0x10
    static MyDTI DTI;
};

class cPrioThkCmdIsStandOffTime : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStandOffTime();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsStatus : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStatus();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cPrioThkStatusFlag mPrioThkStatusFlag;  // offset: 0xc
    bool mCheckTargetMaster;  // offset: 0x14
    static MyDTI DTI;
};

class cPrioThkCmdIsStatusCounter : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStatusCounter();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    s32 mStateID;  // offset: 0xc
    f32 mStateTime;  // offset: 0x10
    static MyDTI DTI;
};

class cPrioThkCmdIsStatusEx : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsStatusEx();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    s32 mCheckID;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsTalkWithPl : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsTalkWithPl();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsTarget : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsTarget();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetActGoldBurst : public cPrioThkCmd
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
    cPrioThkCmdRetActGoldBurst();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cPrioThkRetActFlag mRetActFlag;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetActGroup : public cPrioThkCmd
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
    cPrioThkCmdRetActGroup();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mActionInterfaceGroup;  // offset: 0x8
    u32 mReqTargetType;  // offset: 0xc
    u32 mReqTargetFrameType;  // offset: 0x10
    f32 mReqTargetFrame;  // offset: 0x14
    MtVector3 mReqTargetRealPos;  // offset: 0x20
    cPrioThkRetActFlag mRetActFlag;  // offset: 0x30
    bool mReqUseEmChecker;  // offset: 0x34
    static MyDTI DTI;
};

class cPrioThkCmdRetActInter : public cPrioThkCmd
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
    cPrioThkCmdRetActInter();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mActionInterfaceID;  // offset: 0x8
    u32 mReqTargetType;  // offset: 0xc
    u32 mReqTargetFrameType;  // offset: 0x10
    f32 mReqTargetFrame;  // offset: 0x14
    MtVector3 mReqTargetRealPos;  // offset: 0x20
    cPrioThkRetActFlag mRetActFlag;  // offset: 0x30
    static MyDTI DTI;
};

class cPrioThkCmdRetActInterTarget : public cPrioThkCmd
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
    cPrioThkCmdRetActInterTarget();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mActionInterfaceID;  // offset: 0x8
    cPrioThkRetActFlag mRetActFlag;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdRetCureAct : public cPrioThkCmd
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
    cPrioThkCmdRetCureAct();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    void checkResultOrderCure(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkCureSpot(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkCureArrow(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkJob10AreaSupport(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetDispersion : public cPrioThkCmd
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
    cPrioThkCmdRetDispersion();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetEnemyTable : public cPrioThkCmd
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
    cPrioThkCmdRetEnemyTable();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mPawnActionGroup;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetFollow : public cPrioThkCmd
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
    cPrioThkCmdRetFollow();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mReqMoveType;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetFreeParam : public cPrioThkCmd
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
    cPrioThkCmdRetFreeParam();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    nDDOUtility::cArray<float, 4> mFreeParamF32;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetGoto : public cPrioThkCmd
{
public:
    enum
    {
        MOVE_TYPE_AUTO = 0,
        MOVE_TYPE_WALK = 1,
        MOVE_TYPE_RUN = 2,
        MOVE_TYPE_DASH = 3,
        MOVE_TYPE_NUM = 4,
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
    cPrioThkCmdRetGoto();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mReqTargetType;  // offset: 0x8
    MtVector3 mReqTargetRealPos;  // offset: 0x10
    f32 mReqTargetRange;  // offset: 0x20
    u32 mReqMoveType;  // offset: 0x24
    static MyDTI DTI;
};

class cPrioThkCmdRetHealAct : public cPrioThkCmd
{
public:
    enum
    {
        FLAG_DISABLE_HEAL_ARROW = 0,
        FLAG_HEALING_PRIO_HIGH = 1,
        FLAG_HEALING_PRIO_MIDDLE = 2,
        FLAG_HEALING_PRIO_LOW = 3,
        FLAG_NUM = 4,
    };
public:
    class MyDTI;
public:
    using cFlag = nDDOUtility::cBitSet<4>;
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
    cPrioThkCmdRetHealAct();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    void checkResultOrderHeal(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingSpot(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealing(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealArrow(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealArrow2(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealArrowCS13(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealingMe(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealingSpiritAreaHigh(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingSpiritBitHigh(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingSpiritAreaMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingSpiritBitMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingPointHigh(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealingPointMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    cFlag mPrioThkHealActFlag;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetNoMoveJump : public cPrioThkCmd
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
    cPrioThkCmdRetNoMoveJump();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetOrder : public cPrioThkCmd
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
    cPrioThkCmdRetOrder();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    void findPawnAIAction(cPrioThkIO& io, uDDOModel& owner, MtTypedArray<cPawnAIAction>& dst, const cAIPawnOrderParam* pPrm);
public:
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mOrderGroup;  // offset: 0x8
    static MyDTI DTI;
};

class cPrioThkCmdRetRouteInfo : public cPrioThkCmd
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
    cPrioThkCmdRetRouteInfo();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetStaminaHealAct : public cPrioThkCmd
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
    cPrioThkCmdRetStaminaHealAct();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
private:
    void checkResultOrderHeal(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);
    u32 checkHealEnergySpot(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealHuruwaseArrow(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
    u32 checkHealJob10NormalSup(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget);
public:
    static MyDTI DTI;
};

class cPrioThkCmdRetSupport : public cPrioThkCmd
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
    cPrioThkCmdRetSupport();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
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

class cPrioThkCmdAddAnimalCoop : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddAnimalCoop();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdAddAnimalProtect : public cPrioThkCmdAddBase
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
    cPrioThkCmdAddAnimalProtect();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

class cPrioThkCmdIsAction : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsAction();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mActNo;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsAutoSituation : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsAutoSituation();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
    virtual void load(MtDataReader& r);  // vtable slot 7
public:
    u32 mAutoSituation;  // offset: 0xc
    static MyDTI DTI;
};

class cPrioThkCmdIsBakuensen : public cPrioThkCmdIsBase
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
    cPrioThkCmdIsBakuensen();
    virtual u32 check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code);  // vtable slot 6
public:
    static MyDTI DTI;
};

inline void* cPrioThkCmd::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmd::cPrioThkCmd() {
}

inline void* cPrioThkCmd::cTmpResult::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdAddAnimalCoop::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddAnimalCoop::cPrioThkCmdAddAnimalCoop() {
}

inline void* cPrioThkCmdAddAnimalProtect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddAnimalProtect::cPrioThkCmdAddAnimalProtect() {
}

inline void* cPrioThkCmdAddBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddBase::cPrioThkCmdAddBase() {
    this->mFilter = false;
}

inline void* cPrioThkCmdAddBreakTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddBreakTarget::cPrioThkCmdAddBreakTarget() {
}

inline void* cPrioThkCmdAddCoreNearTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddCoreNearTarget::cPrioThkCmdAddCoreNearTarget() {
    this->mTargetType = 0;
}

inline void* cPrioThkCmdAddEnemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddEnemy::cPrioThkCmdAddEnemy() {
    this->mHpRateMin = 0.0f;
    this->mHpRateMax = 1.0f;
    this->mLenXZMin = 0.0f;
    this->mLenXZMax = 0.0f;
    this->mAddSortType = 0;
}

inline void* cPrioThkCmdAddEnemyClimb::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddEnemyClimb::cPrioThkCmdAddEnemyClimb() {
}

inline void* cPrioThkCmdAddEnemyHp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddEnemyHp::cPrioThkCmdAddEnemyHp() {
    this->mIsMax = false;
}

inline void* cPrioThkCmdAddEnemyRange::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddEnemyRange::cPrioThkCmdAddEnemyRange() {
    this->mIsFar = false;
}

inline void* cPrioThkCmdAddErosionRequest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddErosionRequest::cPrioThkCmdAddErosionRequest() {
}

inline void* cPrioThkCmdAddEvaluation::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddEvaluation::cPrioThkCmdAddEvaluation() {
    this->mTargetType = 1;
    this->mEveValueMin = 0.0f;
    this->mEveValueMax = 250.0f;
}

inline void* cPrioThkCmdAddHiPrioEnemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddHiPrioEnemy::cPrioThkCmdAddHiPrioEnemy() {
    this->mRemoveFlgs = 0;
}

inline void* cPrioThkCmdAddParty::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddParty::cPrioThkCmdAddParty() {
    this->mTargetPartyFlag = 0;
    this->mTargetRange = 3000.0f;
    this->mAddSortType = 0;
}

inline void* cPrioThkCmdAddPartyAction::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddPartyAction::cPrioThkCmdAddPartyAction() {
    this->mDoActNo = 0xFFFFFFFF;
    this->mDoActNoJob = 255;
}

inline void* cPrioThkCmdAddPartyHp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddPartyHp::cPrioThkCmdAddPartyHp() {
    this->mHpRateMin = 0.0f;
    this->mHpRateMax = 1.0f;
    this->mWhiteHpRateMin = 0.0f;
    this->mWhiteHpRateMax = 1.0f;
    this->mWhiteNoZero = false;
    this->mTargetDistanceMin = -1.0f;
    this->mTargetDistanceY = -1.0f;
}

inline void* cPrioThkCmdAddPartyHpForShift::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddPartyHpForShift::cPrioThkCmdAddPartyHpForShift() {
    this->mHpRateMin = 0.0f;
    this->mHpRateMax = 1.0f;
    this->mWhiteHpRateMin = 0.0f;
    this->mWhiteHpRateMax = 1.0f;
    this->mWhiteNoZero = false;
    this->mTargetDistanceMin = -1.0f;
    this->mTargetDistanceY = -1.0f;
    this->mStaminaRateMin = 0.0f;
    this->mStaminaRateMax = 1.0f;
}

inline void* cPrioThkCmdAddPartyOcd::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddPartyOcd::cPrioThkCmdAddPartyOcd() : mEnableOcd(), mDisableOcd() {
}

inline void* cPrioThkCmdAddPartyStamina::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdAddPartyStamina::cPrioThkCmdAddPartyStamina() {
    this->mStaminaRateMin = 0.0f;
    this->mStaminaRateMax = 1.0f;
    this->mIgnoreTired = false;
}

inline void* cPrioThkCmdAddPartyStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdConCureSpot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConCureSpot::cPrioThkCmdConCureSpot() {
}

inline void* cPrioThkCmdConEventOmElf::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConEventOmElf::cPrioThkCmdConEventOmElf() {
}

inline void* cPrioThkCmdConFollowArea::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdConHealFountain::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConHealFountain::cPrioThkCmdConHealFountain() {
}

inline void* cPrioThkCmdConHealSpot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConHealSpot::cPrioThkCmdConHealSpot() {
}

inline void* cPrioThkCmdConSpot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConSpot::cPrioThkCmdConSpot() {
    this->mShlId = 0;
    this->mLength = 2000.0f;
    this->mFollowRange = 200.0f;
}

inline void* cPrioThkCmdConSpotExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdConSpotExt::cPrioThkCmdConSpotExt() {
    this->mShlId = 0;
    this->mLength = 2000.0f;
    this->mThroughLength = 500.0f;
    this->mFollowRange = 200.0f;
}

inline void* cPrioThkCmdFilTargetStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdIsAction::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsAction::cPrioThkCmdIsAction() {
    this->mActNo = 0;
}

inline void* cPrioThkCmdIsAutoSituation::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsAutoSituation::cPrioThkCmdIsAutoSituation() {
    this->mAutoSituation = 0;
}

inline void* cPrioThkCmdIsBakuensen::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsBakuensen::cPrioThkCmdIsBakuensen() {
}

inline void* cPrioThkCmdIsBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsBase::cPrioThkCmdIsBase() {
    this->mIs = true;
}

inline bool cPrioThkCmdIsBase::isRet() const {
    return this->mIs;
}

inline void* cPrioThkCmdIsBattle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsBattle::cPrioThkCmdIsBattle() {
}

inline void* cPrioThkCmdIsBattleAct::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsBattleAct::cPrioThkCmdIsBattleAct() {
}

inline void* cPrioThkCmdIsCanErosionRescue::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsCanErosionRescue::cPrioThkCmdIsCanErosionRescue() {
}

inline void* cPrioThkCmdIsCanSetEmotion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsCanSetEmotion::cPrioThkCmdIsCanSetEmotion() {
}

inline void* cPrioThkCmdIsDamage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsDamage::cPrioThkCmdIsDamage() {
}

inline void* cPrioThkCmdIsDanger::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsDanger::cPrioThkCmdIsDanger() {
    this->mRange = 0.0f;
}

inline void* cPrioThkCmdIsEnableArea::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsEnableArea::cPrioThkCmdIsEnableArea() {
}

inline void* cPrioThkCmdIsEvaluation::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsEvaluation::cPrioThkCmdIsEvaluation() {
    this->mTargetType = 0;
}

inline void* cPrioThkCmdIsFollowEnable::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsFollowEnable::cPrioThkCmdIsFollowEnable() {
}

inline void* cPrioThkCmdIsGuardBit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsGuardBit::cPrioThkCmdIsGuardBit() {
    this->mCheckGuardBitNum = 0;
}

inline void* cPrioThkCmdIsHp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsHp::cPrioThkCmdIsHp() {
    this->mHpMin = 0.0f;
    this->mHpMax = 1.0f;
}

inline void* cPrioThkCmdIsImpactForce::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsImpactForce::cPrioThkCmdIsImpactForce() {
}

inline void* cPrioThkCmdIsLanternOff::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsLanternOff::cPrioThkCmdIsLanternOff() {
}

inline void* cPrioThkCmdIsLanternOn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsLanternOn::cPrioThkCmdIsLanternOn() {
}

inline void* cPrioThkCmdIsMasterDead::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsMasterDead::cPrioThkCmdIsMasterDead() {
}

inline void* cPrioThkCmdIsNotice::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsNotice::cPrioThkCmdIsNotice() {
    this->mNoticeFlag = 7;
}

inline void* cPrioThkCmdIsOrder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdIsOtherFlag::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdIsPartyJob::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsPartyJob::cPrioThkCmdIsPartyJob() {
}

inline void* cPrioThkCmdIsReleaseAlchemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsReleaseAlchemy::cPrioThkCmdIsReleaseAlchemy() {
}

inline void* cPrioThkCmdIsReload::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsReload::cPrioThkCmdIsReload() {
    this->mUnderNum = 8;
    this->mUnderRate = 0.3f;
}

inline void* cPrioThkCmdIsShl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsShl::cPrioThkCmdIsShl() {
    this->mShlId = 0;
    this->mLength = 2000.0f;
    this->mChkType = 0;
}

inline void* cPrioThkCmdIsStageNo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStageNo::cPrioThkCmdIsStageNo() {
    this->mStageNo = 0;
}

inline void* cPrioThkCmdIsStageType::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStageType::cPrioThkCmdIsStageType() {
    this->mStageTypeFlag = 0;
}

inline void* cPrioThkCmdIsStamina::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStamina::cPrioThkCmdIsStamina() {
    this->mStaminaMin = 0.0f;
    this->mStaminaMax = 1.0f;
}

inline void* cPrioThkCmdIsStandOffTime::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStandOffTime::cPrioThkCmdIsStandOffTime() {
}

inline void* cPrioThkCmdIsStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdIsStatusCounter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStatusCounter::cPrioThkCmdIsStatusCounter() {
    this->mStateID = 0;
    this->mStateTime = 0.0f;
}

inline void* cPrioThkCmdIsStatusEx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsStatusEx::cPrioThkCmdIsStatusEx() {
    this->mCheckID = 0;
}

inline void* cPrioThkCmdIsTalkWithPl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsTalkWithPl::cPrioThkCmdIsTalkWithPl() {
}

inline void* cPrioThkCmdIsTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdIsTarget::cPrioThkCmdIsTarget() {
}

inline void* cPrioThkCmdRetActGoldBurst::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetActGroup::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetActInter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetActInterTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetCureAct::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetCureAct::cPrioThkCmdRetCureAct() {
}

inline void* cPrioThkCmdRetDispersion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetDispersion::cPrioThkCmdRetDispersion() {
}

inline void* cPrioThkCmdRetEnemyTable::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetEnemyTable::cPrioThkCmdRetEnemyTable() {
    this->mPawnActionGroup = 33;
}

inline void* cPrioThkCmdRetFollow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetFollow::cPrioThkCmdRetFollow() {
    this->mReqMoveType = 0;
}

inline void* cPrioThkCmdRetFreeParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetFreeParam::cPrioThkCmdRetFreeParam() : mFreeParamF32() {
}

inline void* cPrioThkCmdRetGoto::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetHealAct::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkCmdRetNoMoveJump::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetNoMoveJump::cPrioThkCmdRetNoMoveJump() {
}

inline void* cPrioThkCmdRetOrder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetOrder::cPrioThkCmdRetOrder() {
    this->mOrderGroup = 0;
}

inline void* cPrioThkCmdRetRouteInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetRouteInfo::cPrioThkCmdRetRouteInfo() {
}

inline void* cPrioThkCmdRetStaminaHealAct::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetStaminaHealAct::cPrioThkCmdRetStaminaHealAct() {
}

inline void* cPrioThkCmdRetSupport::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrioThkCmdRetSupport::cPrioThkCmdRetSupport() {
}

inline void* cPrioThkCode::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cPrioThkIO::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rPriorityThink::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rPriorityThink::rPriorityThink() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cPrioThkCode::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cPrioThkCode::DTI)->memFree(p_addr);
}

inline void* cPrioThkCode::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cPrioThkCode::DTI)->memAlloc(sz, align, ::cPrioThkCode::DTI.::MtDTI::getID());
}
