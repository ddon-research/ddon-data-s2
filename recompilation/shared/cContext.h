#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cDamageMsg.h"
#include "nHumanBow.h"
#include "nHumanMsg.h"
#include "nNetMsgData.h"
#include "nOcdMsg.h"
#include "nRegionStatus.h"
#include "nShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class cContextInstance;
class cContextInterface;
class cDamageMsg;
namespace nHuman { struct stShellRequestInfo; }
namespace nHuman { struct stShellRequestMsg; }
namespace nHumanBow { struct stNetData; }
namespace nNetMsgData { struct stNetPos; }
namespace nObjCondition { struct stHolyAbsorpReqInfo; }
namespace nObjCondition { struct stHolyAbsorpReqMsg; }
namespace nObjCondition { struct stOcdActiveMsg; }
namespace nRegionStatus { struct stCorePointSlaveMsg; }
namespace nShlBase { class cShlStickContextInfo; }

// Declarations
class cContext;
class cContextCharacter;

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
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cContext : public MtObject
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
    cContext();
    virtual ~cContext();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset() = 0;  // vtable slot 6
    cContext* getNext();
    cContext* getPrev();
    u8 getId();
    void setId(u8 id);
private:
    u8 mId;  // offset: 0x8
    cContext* mpPrev;  // offset: 0x10
    cContext* mpNext;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cContextCharacter : public cContext
{
    // inferred: cContextInterface::setPosReceiveTime names cContextCharacter::mPosReceiveTime
    friend class cContextInterface;
public:
    class MyDTI;
    struct stActSendDataBuff;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stActSendDataBuff
    {
    public:
        nNetMsgData::stNetPos mNetPos;  // offset: 0x0
        f32 mMoveSpeed;  // offset: 0x18
        f32 mMoveAngle;  // offset: 0x1c
        f32 mNetDir;  // offset: 0x20
        u32 mActNo[8];  // offset: 0x24
        u8 mActReqPrio;  // offset: 0x44
        u16 mActAtkAdjustUniqueId;  // offset: 0x46
        u32 mActFreeWork;  // offset: 0x48
        HP_DATATYPE mHp[10];  // offset: 0x50
        HP_DATATYPE mHpWhite;  // offset: 0xa0
        u16 mCommonWork;  // offset: 0xa8
        u16 mCustomWork;  // offset: 0xaa
        u32 mOcdActiveMsgNum;  // offset: 0xac
        nObjCondition::stOcdActiveMsg mOcdActiveMsgArray[75];  // offset: 0xb0
        u32 mTargetUid;  // offset: 0x194
        MtVector3 mTargetPos;  // offset: 0x1a0
        f32 mShakeEndurance;  // offset: 0x1b0
        f32 mRageShrinkEndurance;  // offset: 0x1b4
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
    cContextCharacter();
    virtual ~cContextCharacter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    // Address: 0x01961790 - 0x01961791 (1 bytes)
    virtual void reset() {}  // vtable slot 6
private:
    t64 getPosReceiveTime() const;
    void setPosReceiveTime(t64 time);
    s32 getPosReceiveInterval() const;
    void setPosReceiveInterval(s32 interval);
    bool getIsReqAction(u32 idx) const;
    void clrIsReqAction(u32 idx);
    void setIsReqAction(u32 idx);
    u64 getAttackParamUIDForDmVec() const;
    void setAttackParamUIDForDmVec(u64 uID);
    f32 getAttackBasePhys() const;
    void setAttackBasePhys(f32 attack);
    f32 getAttackBaseMagic() const;
    void setAttackBaseMagic(f32 attack);
    f32 getAttackWepPhys() const;
    void setAttackWepPhys(f32 attack);
    f32 getAttackWepMagic() const;
    void setAttackWepMagic(f32 attack);
    f32 getDefenceBasePhys() const;
    void setDefenceBasePhys(f32 deffence);
    f32 getDefenceBaseMagic() const;
    void setDefenceBaseMagic(f32 deffence);
    f32 getDefenceWepPhys() const;
    void setDefenceWepPhys(f32 deffence);
    f32 getDefenceWepMagic() const;
    void setDefenceWepMagic(f32 deffence);
    f32 getPower() const;
    void setPower(f32 power);
    f32 getWeight() const;
    void setWeight(f32 power);
    f32 getShrinkWep() const;
    void setShrinkWep(f32 shrink);
    f32 getBlowWep() const;
    void setBlowWep(f32 blow);
    f32 getDownBase() const;
    void setDownBase(f32 down);
    f32 getDownWep() const;
    void setDownWep(f32 down);
    f32 getShakeBase() const;
    void setShakeBase(f32 shake);
    f32 getGuardAttackBase() const;
    void setGuardAttackBase(f32 guard);
    f32 getGuardDefenceBase() const;
    void setGuardDefenceBase(f32 guard);
    f32 getGuardDefenceWep() const;
    void setGuardDefenceWep(f32 guard);
    u32 getWeaponType() const;
    void setWeaponType(u32 type);
    u32 getWeaponTypeSe() const;
    void setWeaponTypeSe(u32 type);
    u32 getBodySize() const;
    void setBodySize(u32 size);
    bool isServerDamage() const;
    void setIsServerDamage();
    void clrIsServerDamage();
    MtTypedArray<cDamageMsg>* getServerDamageMsgArray();
    const cDamageMsg* getServerDamageMsgTop() const;
    void eraseServerDamageMsgTop();
    void addServerDamageMsg(const cDamageMsg* pSrc);
    void clearServerDamageMsg();
    u32 getServerDamageMsgNum() const;
    bool isSlaveDamage() const;
    void setIsSlaveDamage();
    void clrIsSlaveDamage();
    MtTypedArray<cDamageMsg>* getDamageMsgArray();
    const cDamageMsg* getDamageMsgTop() const;
    void eraseDamageMsgTop();
    void addDamageMsg(const cDamageMsg* pSrc);
    void clearDamageMsg();
    u32 getDamageMsgNum() const;
    u32 getAttackUID() const;
    void setAttackUID(u32 uid);
    u64 getAttackParamUID() const;
    void setAttackParamUID(u64 uid);
    u64 getDfdCollNodeUID() const;
    void setDfdCollNodeUID(u64 uid);
    MtVector3 getDamageDir() const;
    void setDamageDir(const MtVector3& damage_dir);
    u32 getAttackAttr() const;
    void setAttackAttr(u32 attack_attr);
    u32 getShlOwnerUID() const;
    void setShlOwnerUID(u32 uid);
    u16 getAtkAdjustUniqueId() const;
    void setAtkAdjustUniqueId(u16 uid);
    f32 getDamage() const;
    void setDamage(f32 damage);
    bool isCatchHit() const;
    void setIsCatchHit();
    void clrIsCatchHit();
    bool isCaughtResult() const;
    void setIsCaughtResult();
    void clrIsCaughtResult();
    u8 getCatchResult() const;
    void setCatchResult(u8 result);
    MtVector3 getCatchHitPos() const;
    void setCatchHitPos(MtVector3& vec);
    bool getIsOmReleasePut() const;
    void setIsOmReleasePut(bool flg);
    bool getIsOmReleaseThrow() const;
    void setIsOmReleaseThrow(bool flg);
    MtVector3 getOmReleasePos() const;
    const nNetMsgData::stNetPos& getOmReleaseRealPos() const;
    void setOmReleasePos(const MtVector3& pos);
    f32 getOmReleaseAngle() const;
    void setOmReleaseAngle(const f32 angle);
    MtQuaternion getOmReleaseQuat() const;
    void setOmReleaseQuat(const MtQuaternion& quat);
    void setIsInstantDead(bool b);
    bool isIsInstantDead() const;
    u32 getShlDelte() const;
    void setShlDelte(u32 bit);
    u32 getShlNetSts(u32 index) const;
    bool isShlNetSts(u32 sts, u32 index) const;
    void setShlNetSts(u32 sts, u32 index);
    u32 getShlUniqueId(u32 index) const;
    void setShlUniqueId(u32 uid, u32 index);
    u32 getShlTargetUId(u32 index) const;
    void setShlTargetUId(u32 uid, u32 index);
    s32 getShlGroup(u32 index) const;
    void setShlGroup(s32 group, u32 index);
    s32 getShlIndex(u32 index) const;
    void setShlIndex(s32 shl_index, u32 index);
    bool isShlReqSlave(u32 index) const;
    void setIsShlReqSlave(bool flg, u32 index);
    bool isShotReqNoAct() const;
    void setIsShotReqNoAct(bool flg);
    MtVector3 getShlPos(u32 index) const;
    const nNetMsgData::stNetPos& getShlRealPos(u32 index) const;
    void setShlPos(const MtVector3& pos, u32 index);
    MtVector3 getShlTarget(u32 index) const;
    const nNetMsgData::stNetPos& getShlTargetRealPos(u32 index) const;
    void setShlTarget(const MtVector3& pos, u32 index);
    MtVector3 getShlDir(u32 index) const;
    void setShlDir(const MtVector3& dir, u32 index);
    u8 getShlLockOnId(u8 index) const;
    void setShlLockOnId(u8 id, u32 index);
    u8 getShlShotReceiveNum() const;
    void setShlShotReceiveNum(u8 num);
    void setIsStickCreateControl(bool flg);
    bool isStickCreateControl() const;
    void setStickShlUniqueId(u32 id);
    u32 getStickShlUniqueId() const;
    void setStickUniqueId(u32 id);
    u32 getStickUniqueId() const;
    void setStickJointNo(u32 sts);
    u8 getStickJointNo() const;
    void setStickShlGroup(u32 no);
    u8 getStickShlGroup() const;
    void setStickShlIndex(u32 no);
    u8 getStickShlIndex() const;
    MtVector3 getStickJointOffset() const;
    void setStickJointOffset(const MtVector3& offset);
    MtVector3 getStickDirection() const;
    void setStickDirection(const MtVector3& dir);
    void setIsShlKillSync(bool flg);
    bool isShlKillSync() const;
    void setIsShlSlaveKill(bool flg);
    bool isShlSlaveKill() const;
    void setSlaveKillSyncSts(u8 bit);
    u8 getSlaveKillSyncSts() const;
    bool isBowUpActUpdate() const;
    nHumanBow::stNetData& popBowUpNetData();
    void pushBowUpNetData(const nHumanBow::stNetData& d);
    void pushBowLockOnInfo(u32 index, u32 uid, u32 lockId);
    void popBowLockOnInfo(u32 index, u32& uid, u32& lockId);
    bool isBowLowActUpdate() const;
    nHumanBow::stNetData& popBowLowNetData();
    void pushBowLowNetData(const nHumanBow::stNetData& d);
    bool isBowPeriodUpdate() const;
    nHumanBow::stNetData& popBowPeriodNetData();
    void pushBowPeriodNetData(const nHumanBow::stNetData& d);
    const MtVector3& getBowNetAimPos() const;
    void setBowNetAimPos(const MtVector3& pos);
    f32 getBowMoveRadian() const;
    void setBowMoveRadian(f32 rad);
    u32 getBowNetUpdateFlag() const;
    void setBowNetUpdateFlag(u32 flag);
    const nRegionStatus::stCorePointSlaveMsg& getCorePointSlaveMsg(u32 index) const;
    void addCorePointSlaveMsg(const nRegionStatus::stCorePointSlaveMsg& src);
    void clearCorePointSlaveMsg(u32 index);
    void clearCorePointSlaveMsgAll();
    void clearCorePointSlaveMsgTop();
    const nRegionStatus::stCorePointSlaveMsg& getCorePointSlaveMsgTop() const;
    u32 getCorePointSlaveMsgNum() const;
    bool isSendCorePointSlaveFlag_On() const;
    void sendCorePointSlaveFlag_On();
    void sendCorePointSlaveFlag_Off();
    const nObjCondition::stHolyAbsorpReqInfo& getAbsorpReqInfoTop() const;
    void clearAbsorpReqInfoTop();
    const nObjCondition::stHolyAbsorpReqInfo& getAbsorpReqInfo(u32 index) const;
    void registAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    u32 getAbsorpReqNum() const;
    void clearAbsorpReq(u32 index);
    void clearAbsorpReqArray();
    bool isAbsorpNetFlagOn() const;
    void cancelAbsorpNetFlag();
    void absorpNetFlagOn();
    const nObjCondition::stHolyAbsorpReqInfo& getSoulAbsorpReqInfoTop() const;
    void clearSoulAbsorpReqInfoTop();
    const nObjCondition::stHolyAbsorpReqInfo& getSoulAbsorpReqInfo(u32 index) const;
    void registSoulAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    u32 getSoulAbsorpReqNum() const;
    void clearSoulAbsorpReq(u32 index);
    void clearSoulAbsorpReqArray();
    bool isSoulAbsorpNetFlagOn() const;
    void cancelSoulAbsorpNetFlag();
    void soulAbsorpNetFlagOn();
    const nHuman::stShellRequestInfo& getShellRequestInfoTop() const;
    void clearShellRequestInfoTop();
    const nHuman::stShellRequestInfo& getShellRequestInfo(u32 index) const;
    void registShellRequestMsg(const nHuman::stShellRequestMsg& srcMsg);
    u32 getShellRequestInfoNum() const;
    void clearShellRequestInfo(u32 index);
    void clearShellRequestInfoArray();
    bool isShellRequestNetFlagOn() const;
    void cancelShellRequestNetFlag();
    void shellRequestNetFlagOn();
    u16 getCommonWork() const;
    void setCommonWork(u16 work);
    void addCommonWork(u16 work);
    void subCommonWork(u16 work);
    bool isCommonWork(u16) const;
    u16 getCustomWork() const;
    void setCustomWork(u16 work);
    void addCustomWork(u16 work);
    void subCustomWork(u16 work);
    bool isCustomWork(u16) const;
    void addShlStickInfo(nShlBase::cShlStickContextInfo* pInfo);
    void requestShlStickInfoContext();
    bool isReqStickShl() const;
public:
    void copySendData(cContextInstance* pInst);
    const stActSendDataBuff& getSendDataBuff() const;
private:
    t64 mPosReceiveTime;  // offset: 0x20
    s32 mPosReceiveInterval;  // offset: 0x28
    u32 mIsReqAction;  // offset: 0x2c
    u64 mAttackParamUIDForDmVec;  // offset: 0x30
    f32 mAttackBasePhys;  // offset: 0x38
    f32 mAttackBaseMagic;  // offset: 0x3c
    f32 mAttackWepPhys;  // offset: 0x40
    f32 mAttackWepMagic;  // offset: 0x44
    f32 mDefenceBasePhys;  // offset: 0x48
    f32 mDefenceBaseMagic;  // offset: 0x4c
    f32 mDefenceWepPhys;  // offset: 0x50
    f32 mDefenceWepMagic;  // offset: 0x54
    f32 mPower;  // offset: 0x58
    f32 mWeight;  // offset: 0x5c
    f32 mShrinkWep;  // offset: 0x60
    f32 mBlowWep;  // offset: 0x64
    f32 mDownBase;  // offset: 0x68
    f32 mDownWep;  // offset: 0x6c
    f32 mShakeBase;  // offset: 0x70
    f32 mGuardAttackBase;  // offset: 0x74
    f32 mGuardDefenceBase;  // offset: 0x78
    f32 mGuardDefenceWep;  // offset: 0x7c
    u32 mWeaponType;  // offset: 0x80
    u32 mWeaponTypeSe;  // offset: 0x84
    u32 mBodySize;  // offset: 0x88
    bool mIsServerDamaged;  // offset: 0x8c
    MtTypedArray<cDamageMsg> mServerDamageMsgArray;  // offset: 0x90
    bool mIsSlaveDamaged;  // offset: 0xb0
    MtTypedArray<cDamageMsg> mDamageMsgArray;  // offset: 0xb8
    u32 mAttackerUID;  // offset: 0xd8
    u64 mAttackParamUID;  // offset: 0xe0
    u64 mDfdCollNodeUID;  // offset: 0xe8
    f32 mDamage;  // offset: 0xf0
    u32 mShlOwnerID;  // offset: 0xf4
    u16 mAtkAdjustUniqueId;  // offset: 0xf8
    MtVector3 mDamageDir;  // offset: 0x100
    u32 mAttackAttr;  // offset: 0x110
    bool mIsCatchHit;  // offset: 0x114
    bool mIsCaughtResult;  // offset: 0x115
    u8 mCatchResult;  // offset: 0x116
    MtVector3 mCatchHitPos;  // offset: 0x120
    bool mIsOmReleasePut;  // offset: 0x130
    bool mIsOmReleaseThrow;  // offset: 0x131
    nNetMsgData::stNetPos mOmReleasePos;  // offset: 0x138
    f32 mOmReleaseAngle;  // offset: 0x150
    MtQuaternion mOmReleaseQuat;  // offset: 0x160
    bool mIsInstantDead;  // offset: 0x170
    u32 mShlDelete;  // offset: 0x174
    u32 mShlNetSts[8];  // offset: 0x178
    u32 mShlUniqueId[8];  // offset: 0x198
    s32 mShlGroup[8];  // offset: 0x1b8
    s32 mShlIndex[8];  // offset: 0x1d8
    nNetMsgData::stNetPos mShlPos[8];  // offset: 0x1f8
    nNetMsgData::stNetPos mShlTarget[8];  // offset: 0x2b8
    u32 mShlTargetUId[8];  // offset: 0x378
    MtVector3 mShlDir[8];  // offset: 0x3a0
    u8 mShlLockOnId[8];  // offset: 0x420
    u8 mShlShotReceiveNum;  // offset: 0x428
    bool mIsShlReqSlave[8];  // offset: 0x429
    bool mIsShotReqNoAct;  // offset: 0x431
    bool mIsStickCreateControl;  // offset: 0x432
    u32 mStickShlUniqueId;  // offset: 0x434
    u32 mStickUniqueId;  // offset: 0x438
    u8 mStickJointNo;  // offset: 0x43c
    u8 mStickShlGroup;  // offset: 0x43d
    u8 mStickShlIndex;  // offset: 0x43e
    MtVector3 mStickJointOffset;  // offset: 0x440
    MtVector3 mStickDirection;  // offset: 0x450
    MtTypedArray<nShlBase::cShlStickContextInfo> mShlStickInfoArray;  // offset: 0x460
    bool mIsShlKillSync;  // offset: 0x480
    bool mIsShlSlaveKill;  // offset: 0x481
    u8 mShlSlaveKillSyncSts;  // offset: 0x482
    u32 mBowNetUpdateFlag;  // offset: 0x484
    f32 mMoveBowRadian;  // offset: 0x488
    nHumanBow::stNetData mBowNetDataUp;  // offset: 0x48c
    nHumanBow::stNetData mBowNetDataLow;  // offset: 0x4b8
    nHumanBow::stNetData mBowNetDataPeriod;  // offset: 0x4e4
    MtVector3 mBowNetAimPos;  // offset: 0x510
    nRegionStatus::stCorePointSlaveMsg mCorePointSlaveMsg[8];  // offset: 0x520
    bool mIsSendCorePointSlaveMsg;  // offset: 0x550
    nObjCondition::stHolyAbsorpReqInfo mAbsorpReqArray[8];  // offset: 0x554
    bool mISendHolyAbsorpMsg;  // offset: 0x5d4
    nObjCondition::stHolyAbsorpReqInfo mSoulAbsorpReqArray[8];  // offset: 0x5d8
    bool mISendSoulAbsorpMsg;  // offset: 0x658
    nHuman::stShellRequestInfo mSheRequestArray[8];  // offset: 0x65c
    bool mIsSendShlRequestMsg;  // offset: 0x6fc
    stActSendDataBuff mSendDataBuff;  // offset: 0x700
public:
    static MyDTI DTI;
};
