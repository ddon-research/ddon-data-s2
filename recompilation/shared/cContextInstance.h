#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cContext.h"
#include "cContextPlayerInfo.h"
#include "cCorePointMsg.h"
#include "cEquipData.h"
#include "cPlayerLoadManager.h"
#include "nActionManager.h"
#include "nCharacterData.h"
#include "nDDOGame.h"
#include "nDDOUtility.h"
#include "nNetMsgData.h"
#include "nObjCondition.h"
#include "nOcdMsg.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cArcLoaderBase;
class cContextInterface;
class cContextPlayerInfo;
class cCorePointMsg;
class cEquipData;
class cItemParam;
class cPlayerLoadManager;
namespace nActionManager { struct stActExParam; }
namespace nCharacterData { struct stCharacterName; }
namespace nCharacterData { struct stEquipData; }
namespace nNetMsgData { struct stNetPos; }
namespace nObjCondition { struct stOcdActiveData; }
namespace nObjCondition { struct stOcdActiveMsg; }
class rCharacterEdit;

// Declarations
class cContextInstChar;
class cContextInstHm;
class cContextInstance;

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using cAIPawnTalkMotSituationArray = nDDOUtility::cArray<unsigned short, 10>;
using cAIPawnTalkSituationFlag = nDDOUtility::cBitSet<46>;
using cAIPawnTalkWordPartyArray = nDDOUtility::cArray<unsigned int, 8>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cContextInstance : public cContext
{
    // inferred: cContextInterface::setNetPos calls cContextInstance::setNetPos
    friend class cContextInterface;
public:
    enum
    {
        ATTR_VALID = 1,
        ATTR_SYNC = 2,
        ATTR_CREATE = 4,
        ATTR_PARTY_SYNC = 8,
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
    cContextInstance();
    virtual ~cContextInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    cContextInstance& operator=(const cContextInstance&);
    bool isValid() const;
    bool isSync(bool isPartySync) const;
    bool isCreateFirst() const;
    void onValid();
    void onSync();
    void onCreate();
    void onPartySync();
    void offPartySync();
    void clearValid();
private:
    MtVector3 getNetPos() const;
    const nNetMsgData::stNetPos& getNetRealPos() const;
    void setNetPos(const MtVector3& pos);
    void setNetRealPos(const nNetMsgData::stNetPos& pos);
    f32 getNetDir() const;
    void setNetDir(f32 dir);
    s32 getStageNo() const;
    void setStageNo(s32 StageNo);
    u32 getUniqueId() const;
    void setUniqueId(u32 UniqueId);
    bool getMasterChangeFlag() const;
    void setMasterChangeFlag(bool flg);
    s32 getMasterIndex() const;
    void setMasterIndex(s32 index);
    s32 getMainEncountArea() const;
    void setMainEncountArea(s32 encountArea);
    bool getSendChangeMaster() const;
    void setSendChangeMaster(bool flg);
    bool getSetWaitFlag() const;
    void setSetWaitFlag(bool flg);
    u8 getCatchType() const;
    void setCatchType(u8 type);
    u32 getCatchTargetUID() const;
    void setCatchTargetUID(u32 uid);
    u32 getCatchJointNo() const;
    void setCatchJointNo(u32 no);
    u32 getQuestId() const;
    void setQuestId(u32 QuestId);
protected:
    u8 mIsValid;  // offset: 0x20
    nNetMsgData::stNetPos mNetPos;  // offset: 0x28
    f32 mNetDir;  // offset: 0x40
    s32 mStageNo;  // offset: 0x44
    u32 mUniqueId;  // offset: 0x48
    bool mMasterChangeFlag;  // offset: 0x4c
    s32 mMasterIndex;  // offset: 0x50
    s32 mMainEncountArea;  // offset: 0x54
    bool mSendChangeMaster;  // offset: 0x58
    bool mSetWaitFlag;  // offset: 0x59
    u32 mQuestId;  // offset: 0x5c
    u8 mCatchType;  // offset: 0x60
    u8 mCatchJointNo;  // offset: 0x61
    u32 mCatchTargetUid;  // offset: 0x64
public:
    static MyDTI DTI;
};

class cContextInstChar : public cContextInstance
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
    cContextInstChar();
    virtual ~cContextInstChar();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    cContextInstChar& operator=(const cContextInstChar&);
private:
    u8 getActReqPrio() const;
    void setActReqPrio(u8 prio);
    u32 getActNo(u32 idx) const;
    void setActNo(u32 idx, u32 no);
    u32 getActFreeWork() const;
    void setActFreeWork(u32 work);
    f32 getMoveSpeed() const;
    void setMoveSpeed(f32 speed);
    f32 getMoveAngle() const;
    void setMoveAngle(f32 angle);
    u16 getCommonWork() const;
    void setCommonWork(u16 work);
    void addCommonWork(u16 work);
    void subCommonWork(u16 work);
    bool isCommonWork(u16 work) const;
    u16 getCustomWork() const;
    void setCustomWork(u16 work);
    void addCustomWork(u16 work);
    void subCustomWork(u16 work);
    bool isCustomWork(u16 work) const;
    MtVector3 getCliffPos() const;
    const nNetMsgData::stNetPos& getCliffRealPos() const;
    void setCliffPos(const MtVector3& pos);
    const MtVector3& getCliffNormal() const;
    void setCliffNormal(const MtVector3& vec);
    MtVector3 getCliffStartPos() const;
    const nNetMsgData::stNetPos& getCliffStartRealPos() const;
    void setCliffStartPos(const MtVector3& pos);
    MtVector3 getCliffStartOldPos() const;
    const nNetMsgData::stNetPos& getCliffStartOldRealPos() const;
    void setCliffStartOldPos(const MtVector3& pos);
    u32 getTargetUid() const;
    void setTargetUid(const u32 uid);
    MtVector3 getTargetPos() const;
    const nNetMsgData::stNetPos& getTargetRealPos() const;
    void setTargetPos(const MtVector3& pos);
    MtVector3 getWallClimbPos() const;
    const nNetMsgData::stNetPos& getWallClimbRealPos() const;
    void setWallClimbPos(const MtVector3& pos);
    const MtVector3& getWallClimbNormal() const;
    void setWallClimbNormal(const MtVector3& normal);
    MtVector3 getWallClimbLandPos() const;
    const nNetMsgData::stNetPos& getWallClimbLandRealPos() const;
    void setWallClimbLandPos(const MtVector3& pos);
    void setActExParam(u32 idx, const nActionManager::stActExParam* pSrc);
    const nActionManager::stActExParam* getActParam(u32 idx) const;
    u32 getClimbEnemyUId() const;
    void setClimbEnemyUId(u32 no);
    s32 getClimbEnemyJointNo() const;
    void setClimbEnemyJointNo(s32 no);
    const MtVector3& getClimbEnemyJointOffset() const;
    void setClimbEnemyJointOffset(const MtVector3& offset);
    u16 getClimbNodeIndex() const;
    void setClimbNodeIndex(u16 NodeIndex);
    u16 getClimbGeomIndex() const;
    void setClimbGeomIndex(u16 GeomIndex);
    void setIsInjured(const bool flg);
    bool isInjured() const;
    void setIsLost(const bool flg);
    bool isLost() const;
    void setIsRescue(const bool flg);
    bool isRescue() const;
    void setIsReturnTerritory(const bool flg);
    bool isReturnTerritory() const;
    u16 getActAtkAdjustUniqueId() const;
    void setActAtkAdjustUniqueId(u16 uid);
    u32 getOcdActiveMsgNum() const;
    const nObjCondition::stOcdActiveMsg& getOcdActiveMsg(u32 index) const;
    void addOcdActiveMsg(const nObjCondition::stOcdActiveMsg& msg);
    void makeOcdMsgArray();
    void resetOcdMsgArray();
    const nObjCondition::stOcdActiveData& getOcdActiveData(u32 OcdUID) const;
    const nObjCondition::stOcdActiveData& getOcdActiveData(u32 bank, u32 index) const;
    void setOcdActiveData(u32 OcdUID, const nObjCondition::stOcdActiveData& data, bool isTimerReset);
    void setOcdActiveData(u32 bank, u32 index, const nObjCondition::stOcdActiveData& data, bool isTimerReset);
    void resetOcdActiveDataAll(bool isImmuneReset);
    void resetOcdActiveDataGoodStatus();
    bool isOcdActive(u32 OcdUID) const;
    bool isOcdActive(u32 bank, u32 index) const;
    f32 getOcdActiveTimer(u32 OcdUID) const;
    f32 getOcdActiveTimer(u32 bank, u32 index) const;
    void setOcdActiveTimer(u32 OcdUID, f32 timer);
    void setOcdActiveTimer(u32 bank, u32 index, f32 timer);
    void setOcdAllTimerResetFlag(bool flag);
    bool isOcdAllTimerReset() const;
    void setOcdTimerResetFlag(u32 OcdUID, bool flag);
    void setOcdTimerResetFlag(u32 bank, u32 index, bool flag);
    bool isOcdTimerReset(u32 OcdUID) const;
    bool isOcdTimerReset(u32 bank, u32 index) const;
    void resetOcdTimerReset();
    bool isDead(u32 i) const;
    void setIsDead(bool isDead, u32 i);
    HP_DATATYPE getHp(u32 i) const;
    void setHp(HP_DATATYPE hp, u32 i);
    HP_DATATYPE getHpMax(u32 i) const;
    void setHpMax(HP_DATATYPE hpMax, u32 i);
    HP_DATATYPE getHpRaid(u32 i) const;
    void setHpRaid(HP_DATATYPE hp, u32 i);
    bool getIsDeadCheatCheck(u32 i) const;
    void setIsDeadCheatCheck(bool isDead, u32 i);
    HP_DATATYPE getHpCheatCheck(u32 i) const;
    void setHpCheatCheck(HP_DATATYPE hp, u32 i);
    HP_DATATYPE getHpMaxCheatCheck(u32 i) const;
    void setHpMaxCheatCheck(HP_DATATYPE hpMax, u32 i);
    HP_DATATYPE getHpWhite() const;
    void setHpWhite(HP_DATATYPE hp);
    void setUseRegionBit(u16 useBit);
    u16 getUseRegionBit() const;
    bool isUseRegion(u32 regionNo) const;
    bool isHpMax_calc() const;
    void setHpMax_calc(bool flag);
    s32 getLv() const;
    void setLv(s32 lv);
    f32 getShakeEndurance() const;
    void setShakeEndurance(f32 endurance);
    f32 getRageShrinkEndurance() const;
    void setRageShrinkEndurance(f32 endurance);
    f32 getEnchantRate() const;
    void setEnchantRate(f32 rate);
    f32 getAilmentDamage() const;
    void setAilmentDamage(f32 ailment);
    u32 getStateLive() const;
    void setStateLive(u32 state);
    bool isStateLiveChange() const;
    void setStateLiveChange(bool flg);
    u32 getEnemyStatusGroupNum() const;
    void setEnemyStatusGroupNum(u32 groupNum);
    bool addEnemyStatusGroup(u32 group, u32 subGroup);
    u32 getEnemyStatusGroup(u32 idx) const;
    void setEnemyStatusGroup(u32 idx, u32 group);
    void setEnemyStatusSubGroup(u32 idx, u32 subGroup);
    u32 getEnemyStatusSubGroup(u32 idx) const;
    void setEnemyBitReceive(bool enable);
    bool isEnemyBitReceive() const;
    void setEnemyBitCtrlCollision(u64 bit);
    u64 getEnemyBitCtrlCollision() const;
    void setEnemyCtrRegionSelectNo(u8 selectNo);
    u8 getEnemyCtrRegionSelectNo() const;
    void setEnemyBitCtrParts(u64 bit);
    u64 getEnemyBitCtrParts() const;
    void setEnemyWorkRate(u64 bit);
    u64 getEnemyWorkRate() const;
    void setEnemyScale(u64 bit);
    u64 getEnemyScale() const;
    void setEnemyBitCtrlMontage(u64 bit);
    u64 getEnemyBitCtrlMontage() const;
    void setEnemyBitCtrlSyncBit(u32 bit);
    u32 getEnemyBitCtrlSyncBit() const;
    bool isEnemyStatusChange() const;
    void setEnemyStatusChange(bool enable);
    bool getEnemyWaitting() const;
    void setEnemyWaitting(bool enable);
    bool isEnemyWaittingChange() const;
    void setEnemyWaittingChange(bool enable);
    bool getEnemyStartWait() const;
    void setEnemyStartWait(bool enable);
    bool isEnemyStartWaitChange() const;
    void setEnemyStartWaitChange(bool enable);
    void copyCorePointMsgArray(const MtTypedArray<cCorePointMsg>& msgArray);
    void addCorePointMsg(const cCorePointMsg* pSrc);
    void eraseCprePointMsgAll();
    u32 getUnSendedCorePointMsgNum() const;
    cCorePointMsg* getUnSendedTopCorePointMsg() const;
    u32 getCorePointMsgNum() const;
    cCorePointMsg* getCorePointMsg(u32 index) const;
    void eraseCorePointMsg(u32 index);
    u32 getMontageFixNo() const;
    void setMontageFixNo(u32 fixNo);
    u32 getMontageRandom() const;
    void setMontageRandom(u32 rand);
protected:
    u32 getPRegionNum() const;
    void setDummyU32(u32);
private:
    HP_DATATYPE getHpPrivate(u32 index) const;
    void setHpPrivate(HP_DATATYPE NewValue, u32 index);
    HP_DATATYPE getHpMaxPrivate(u32 index) const;
    void setHpMaxPrivate(HP_DATATYPE NewValue, u32 index);
    HP_DATATYPE getHpRaidPrivate(u32 index) const;
    void setHpRaidPrivate(HP_DATATYPE NewValue, u32 index);
    bool getIsDeadPrivate(u32 index) const;
    void setIsDeadPrivate(bool NewValue, u32 index);
    u16 getUseRegionBitPrivate() const;
    void setUseRegionBitPrivate(u16 NewValue);
    bool getIsHpMax_calcPrivate() const;
    void setIsHpMax_calcPrivate(bool NewValue);
    HP_DATATYPE getHpWhitePrivate() const;
    void setHpWhitePrivate(HP_DATATYPE NewValue);
    s32 getLvPrivate() const;
    void setLvPrivate(s32 NewValue);
    HP_DATATYPE getHpPrivateCheatCheck(u32 index) const;
    void setHpPrivateCheatCheck(HP_DATATYPE NewValue, u32 index);
    HP_DATATYPE getHpMaxPrivateCheatCheck(u32 index) const;
    void setHpMaxPrivateCheatCheck(HP_DATATYPE NewValue, u32 index);
    bool getIsDeadPrivateCheatCheck(u32 index) const;
    void setIsDeadPrivateCheatCheck(bool NewValue, u32 index);
private:
    u8 mActReqPrio;  // offset: 0x68
    u32 mActNo[8];  // offset: 0x6c
    u32 mActFreeWork;  // offset: 0x8c
    nActionManager::stActExParam mActExParam[8];  // offset: 0x90
    u16 mActAtkAdjustUniqueId;  // offset: 0x1b0
    f32 mMoveSpeed;  // offset: 0x1b4
    f32 mMoveAngle;  // offset: 0x1b8
    u16 mCommonWork;  // offset: 0x1bc
    u16 mCustomWork;  // offset: 0x1be
    MtVector3 mCliffNormal;  // offset: 0x1c0
    nNetMsgData::stNetPos mCliffPos;  // offset: 0x1d0
    nNetMsgData::stNetPos mCliffStartPos;  // offset: 0x1e8
    nNetMsgData::stNetPos mCliffStartOldPos;  // offset: 0x200
    nNetMsgData::stNetPos mWallClimbPos;  // offset: 0x218
    MtVector3 mWallClimbNormal;  // offset: 0x230
    nNetMsgData::stNetPos mWallClimbLandPos;  // offset: 0x240
    u32 mTargetUid;  // offset: 0x258
    nNetMsgData::stNetPos mTargetPos;  // offset: 0x260
    u32 mClimbEnemyUId;  // offset: 0x278
    s32 mClimbEnemyJointNo;  // offset: 0x27c
    MtVector3 mClimbEnemyJointOffset;  // offset: 0x280
    u16 mClimbEnemyNodeIndex;  // offset: 0x290
    u16 mClimbEnemyGeomIndex;  // offset: 0x292
    bool mIsInjured;  // offset: 0x294
    bool mIsLost;  // offset: 0x295
    bool mIsRescue;  // offset: 0x296
    bool mIsReturnTerritory;  // offset: 0x297
    u32 mStateLive;  // offset: 0x298
    bool mIsStateLiveChange;  // offset: 0x29c
    nObjCondition::stOcdActiveMsg mOcdActiveMsgArray[75];  // offset: 0x29d
    u32 mOcdActiveMsgNum;  // offset: 0x380
    nObjCondition::stOcdActiveData mOcdActiveData[7][32];  // offset: 0x384
    f32 mOcdActiveTimer[7][32];  // offset: 0x544
    bool mOcdAllTimerResetFlag;  // offset: 0x8c4
    u32 mOcdTimerResetBit[7];  // offset: 0x8c8
    HP_DATATYPE mHp_pri[10];  // offset: 0x8e8
    HP_DATATYPE mHpMax_pri[10];  // offset: 0x938
    HP_DATATYPE mHpRaid_pri[10];  // offset: 0x988
    bool mIsDead_pri[10];  // offset: 0x9d8
    u16 mUseRegionBit_pri;  // offset: 0x9e2
    bool mIsHpMax_calc_pri;  // offset: 0x9e4
    bool mIsDeadCheatCheck_pri[10];  // offset: 0x9e5
    HP_DATATYPE mHpCheatCheck_pri[10];  // offset: 0x9f0
    HP_DATATYPE mHpMaxCheatCheck_pri[10];  // offset: 0xa40
    HP_DATATYPE mHpWhite_pri;  // offset: 0xa90
    s32 mLv_pri;  // offset: 0xa98
    f32 mShakeEndurance;  // offset: 0xa9c
    f32 mRageShrinkEndurance;  // offset: 0xaa0
    f32 mEnchantRate;  // offset: 0xaa4
    f32 mAilmentDamage;  // offset: 0xaa8
    u32 mEnemyStatusGroupNoNum;  // offset: 0xaac
    u32 mEnemyStatusGroupNo[16];  // offset: 0xab0
    u32 mEnemyStatusSubGroupNo[16];  // offset: 0xaf0
    bool mIsEnemyBitReceive;  // offset: 0xb30
    u64 mEnemyBitCtrlCollision;  // offset: 0xb38
    u8 mEnemyCtrlRegionSelectNo;  // offset: 0xb40
    u64 mEnemyBitCtrlParts;  // offset: 0xb48
    u64 mEnemyBitCtrlWorkRate;  // offset: 0xb50
    u64 mEnemyBitCtrlScale;  // offset: 0xb58
    bool mIsEnemyStatusChange;  // offset: 0xb60
    u64 mEnemyBitCtrlMontage;  // offset: 0xb68
    u32 mEnemyBitCtrlSyncBit;  // offset: 0xb70
    bool mIsEnemyWaitting;  // offset: 0xb74
    bool mIsEnemyWaittingChange;  // offset: 0xb75
    bool mIsEnemyStartWait;  // offset: 0xb76
    bool mIsEnemyStartWaitChange;  // offset: 0xb77
    u32 mMontageFixNo;  // offset: 0xb78
    u32 mMontageRandom;  // offset: 0xb7c
    MtTypedArray<cCorePointMsg> mCorePointMsgArray;  // offset: 0xb80
public:
    static MyDTI DTI;
};

class cContextInstHm : public cContextInstChar
{
    // inferred: cContextInterface::isPlayer names cContextInstHm::mHumanType
    friend class cContextInterface;
public:
    enum
    {
        HM_TYPE_PLAYER = 0,
        HM_TYPE_PAWN = 1,
        HM_TYPE_HUMAN_ENEMY = 2,
        HM_TYPE_NUM = 3,
    };
    enum
    {
        PAWN_TYPE_NONE = 0,
        PAWN_TYPE_MAIN = 1,
        PAWN_TYPE_SUPPORT = 2,
        PAWN_TYPE_NUM = 3,
    };
    enum CONTEXT_TYPE
    {
        CONTEXT_TYPE_NONE = 0,
        CONTEXT_TYPE_PARTY = 1,
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
    cContextInstHm();
    virtual ~cContextInstHm();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    cContextInstHm& operator=(const cContextInstHm&);
    void entryParty();
    void removeParty();
private:
    u8 getIndex() const;
    void setIndex(u8 index);
    u8 getOnlineStatus() const;
    void setOnlineStatus(u8 status);
    f32 getLostTime() const;
    void setLostTime(f32 time);
    void subLostTime();
    u32 getSex() const;
    void setSex(u32 sex);
    u32 getColor() const;
    void setColor(u32);
    rCharacterEdit* getCharacterEdit() const;
    s32 getFloorGroupNo() const;
    void setFloorGroupNo(const s32 no);
    s32 getStartPosNo() const;
    void setStartPosNo(const s32 no);
    const CHAR_NAME& getName() const;
    void setName(const CHAR_NAME& name);
    MT_CTSTR getFirstName() const;
    void setFirstName(MT_CTSTR name);
    MT_CTSTR getLastName() const;
    void setLastName(MT_CTSTR name);
    MT_CTSTR getClanNickName() const;
    void setClanNickName(MT_CTSTR name);
    u8 getJob() const;
    void setJob(u8);
    const cEquipData& getContextEquip() const;
    cEquipData& getContextEquip();
    u16 getEquipData(u8 category, u8 type, bool isMarge) const;
    void setEquipData(u8 category, cItemParam* pItem, u8 type);
    void setEquipFromCharData(const nCharacterData::stEquipData& Data);
    s32 getPlayerLoadWeapon() const;
    void setPlayerLoadWeapon(s32 wp);
    s32 getPlayerLoadStatus() const;
    void setPlayerLoadStatus(s32 status);
    TICKET getWeaponArcTicket() const;
    void setWeaponArcTicket(TICKET ticket);
    cPlayerLoadManager& getPlayerLoadMgr();
    u8 getHumanType() const;
    void setHumanType(u8 type);
    u8 getPawnType() const;
    void setPawnType(u8 type);
    u32 getCharId() const;
    void setCharId(u32 charId);
    u32 getPawnId() const;
    void setPawnId(u32 pawnId);
    s32 getMemberIndex() const;
    void setMemberIndex(s32 memberIndex);
    s32 getEncountArea(u32 index) const;
    const s32* getEncountAreaBuff() const;
    void setEncountArea(s32* areaArray, s32 num);
    MtVector3 getLastSafePos() const;
    const nNetMsgData::stNetPos& getLastSafeRealPos() const;
    void setLastSafePos(const MtVector3& pos);
    void setLastSafeRealPos(const nNetMsgData::stNetPos& pos);
    u16 getPawnAutoMotion(u32 situation) const;
    void setPawnAutoMotion(u32 situation, u16 val);
    u16 getPawnPersonality() const;
    void setPawnPersonality(u16 val);
    u16 getPawnTalkLv() const;
    void setPawnTalkLv(u16 val);
    s32 getPawnTalkCharId(u32 idx) const;
    void setPawnTalkCharId(u32 idx, s32 charId);
    bool getPawnTalkSituationFlag(u32 flag) const;
    void setPawnTalkSituationFlag(u32 flag, bool on);
    cContextPlayerInfo& getContextPlayerInfo();
    const cContextPlayerInfo& getContextPlayerInfoConst() const;
    u8 getReviveStock() const;
    void setReviveStock(u8 num);
    s32 getReviveType() const;
    void setReviveType(s32 type);
    MtVector3 getPosFreeMarker(u32 idx) const;
    void setPosFreeMarker(const MtVector3& vPos, u32 idx);
    s32 getStageNoFreeMarker(u32 idx) const;
    void setStageNoFreeMarker(s32 sStageNo, u32 idx);
    s32 getGroupNoFreeMarker(u32 idx) const;
    void setGroupNoFreeMarker(s32 sGroupNo, u32 idx);
    void setHmRandom(u32 random);
    u32 getHmRandom() const;
    void setHmEmEditType(u8 random);
    u8 getHmEmEditType() const;
    void setHmEmPresetId(u32 id);
    u8 getHmEmPresetId() const;
    void setHmEmId(u32 id);
    u32 getHmEmId() const;
    bool isReturnPrepare() const;
    void setIsReturnPrepare(bool flag);
    bool isAreaChangePrepare() const;
    void setIsAreaChangePrepare(bool flag);
    bool isReqSetLostAction() const;
    void reqSetLostAction(bool flag);
    s32 getOldGaugeContextType() const;
    void setOldGaugeContextType(s32 type);
    bool isSyncCustomSkillGroup() const;
    void setIsSyncCustomSkillGroup(bool flg);
    void setElementGuardTime(f32 time);
    f32 getElementGuardTime() const;
    bool isAbility098() const;
    void setIsAbility098(bool flag);
    bool isGutsDisable() const;
    void setIsGutsDisable(bool flag);
    bool isAbility370() const;
    void setIsAbility370(bool flag);
    void setElementCoverRate(f32 rate);
    f32 getElementCoverRate() const;
    void setElementCoverType(nDDOGame::ELEMENT_TYPE type);
    nDDOGame::ELEMENT_TYPE getElementCoverType() const;
    void setElementCoverDamageRate(f32 rate);
    f32 getElementCoverDamageRate() const;
public:
    f32 getFJobWork0() const;
    void setFJobWork0(f32 NewValue);
    f32 getFJobWork1() const;
    void setFJobWork1(f32 NewValue);
    s32 getSJobWork0() const;
    void setSJobWork0(s32 NewValue);
    s32 getSJobWork1() const;
    void setSJobWork1(s32 NewValue);
private:
    u8 mIndex;  // offset: 0xba0
    u8 mOnlineStatus;  // offset: 0xba1
    u8 mSex;  // offset: 0xba2
    u8 mColor;  // offset: 0xba3
    u8 mJob;  // offset: 0xba4
    cEquipData mEquip;  // offset: 0xba8
    rCharacterEdit* mpCharacterEdit;  // offset: 0x1e10
    s32 mFloorGroupNo;  // offset: 0x1e18
    s32 mStartPosNo;  // offset: 0x1e1c
    CHAR_NAME mName;  // offset: 0x1e20
    MT_CHAR mClanNickName[4];  // offset: 0x1e36
    f32 mLostTime;  // offset: 0x1e3c
    s32 mPlayerLoadWeapon;  // offset: 0x1e40
    s32 mPlayerLoadStatus;  // offset: 0x1e44
    TICKET mWeaponArcTicket;  // offset: 0x1e48
    cPlayerLoadManager mLoadMgr;  // offset: 0x1e50
    u8 mHumanType;  // offset: 0x29e8
    u8 mPawnType;  // offset: 0x29e9
    u32 mCharId;  // offset: 0x29ec
    u32 mPawnId;  // offset: 0x29f0
    s32 mMemberIndex;  // offset: 0x29f4
    s32 mEncountArea[3];  // offset: 0x29f8
    nNetMsgData::stNetPos mSafePos;  // offset: 0x2a08
    cAIPawnTalkMotSituationArray mPawnAutoMotion;  // offset: 0x2a20
    cAIPawnTalkWordPartyArray mPawnTalkCharId;  // offset: 0x2a34
    cAIPawnTalkSituationFlag mPawnTalkSituationFlag;  // offset: 0x2a54
    cContextPlayerInfo mPlayerInfo;  // offset: 0x2a60
    u8 mReviveStock;  // offset: 0x40f8
    s32 mReviveType;  // offset: 0x40fc
    MtVector3 mPosFreeMarker[3];  // offset: 0x4100
    s32 mStageNoFreeMarker[3];  // offset: 0x4130
    s32 mGroupNoFreeMarker[3];  // offset: 0x413c
    u32 mHmRandom;  // offset: 0x4148
    u8 mHmEmEditType;  // offset: 0x414c
    u32 mHmEmPresetId;  // offset: 0x4150
    u32 mHmEmId;  // offset: 0x4154
    bool mIsAbility098;  // offset: 0x4158
    bool mIsGutsDisable;  // offset: 0x4159
    bool mIsAbility370;  // offset: 0x415a
    bool mIsReturnPrepare;  // offset: 0x415b
    bool mIsAreaChangePrepare;  // offset: 0x415c
    bool mReqSetLostAction;  // offset: 0x415d
    bool mIsSyncCustomSkillGroup;  // offset: 0x415e
    s32 mOldGaugeContextType;  // offset: 0x4160
    f32 mFJobWork0;  // offset: 0x4164
    f32 mFJobWork1;  // offset: 0x4168
    s32 mSJobWork0;  // offset: 0x416c
    s32 mSJobWork1;  // offset: 0x4170
public:
    f32 mElementGuardTime;  // offset: 0x4174
    f32 mElementCoverRate;  // offset: 0x4178
    f32 mElementCoverDamageRate;  // offset: 0x417c
    nDDOGame::ELEMENT_TYPE mElementCoverType;  // offset: 0x4180
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: a bit-test accessor's polarity, true when its bits are set: none of its 34 DWARF copies materializes its result
inline bool cContextInstance::isValid() const {
    return (this->mIsValid & static_cast<u8>(1)) != static_cast<u8>(0);
}
