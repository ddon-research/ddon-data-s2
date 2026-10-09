#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cArcLoader.h"
#include "cContextInterface.h"
#include "cUnit.h"
#include "cpLayout.h"
#include "nNetMsgData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cContextCharacter;
class cContextInstance;
class cContextInterface;
class cGroupParam;
class cPlayerLoadManager;
class cTagArcLoad;
class cpErosionEnemySmall;
class cpLayout;
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }
namespace nNetBase { class cNetBase; }
namespace nNetMsgData { struct stNetPos; }
class rArchive;
class sSetManager;
class uControlNpc;
class uDDOModel;
class uNpc;
class uPlayer;

// Declarations
class uControl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uControl : public cUnit
{
    // inferred: cPlayerLoadManager::loadRequest names uControl::mCtrlType
    friend class cPlayerLoadManager;
    // inferred: cpErosionEnemySmall::setupBeforeContext names uControl::mCtrlType
    friend class cpErosionEnemySmall;
    // inferred: sSetManager::createCharacterInstance names uControl::mCtrlType
    friend class sSetManager;
    // inferred: uControlNpc::setPawnId names uControl::mContextInterface.mpContextInstance
    friend class uControlNpc;
    // inferred: uNpc::isAttend names uControl::mCtrlType
    friend class uNpc;
    // inferred: uPlayer::kill names uControl::mpContextInst
    friend class uPlayer;
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
    uControl();
    virtual ~uControl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static uControl* createControl(u8 ctrlType, u32 gitk, u32 uniqId);
    bool isPlayer();
    bool isPawn();
    bool isNpc();
    bool isEnemy();
    bool isOmModel();
    void setSelfDeleteContextInst(bool Set);
    void sendMasterParam();
protected:
    bool initialize(u32 gitk, u32 uniqId);
public:
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void sync();  // vtable slot 11
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void connectModel(uDDOModel* pModel);
    void disconnectModel(bool IsKillModel);
    void reconnectModel(uDDOModel* pModel);
    void setCtrlType(u8 ctrlType);
    s32 getCtrlType();
    bool isMaster();
    uDDOModel* getObjModel();
    nNetBase::cNetBase* getNetRpc();
    cContextCharacter* getContext();
    cContextInstance* getContextInst();
    void setContextInst(cContextInstance* pContextInst);
    void resetContextInterface();
    void releaseContextInst();
    cContextInterface& getContextInterface();
    bool isCommunicate();
    void setIsCommunicate(bool f);
    void updateBossCondSendInterval();
private:
    void saveNetMessage();
    void sendSaveNetMessage();
    void releaseSaveNetMessage();
    void updateSendInterval();
    void sendNetMessage();
public:
    bool isFirstReceive();
    void onFirstReceive();
    bool isSaveSendAct();
private:
    void offFirstReceive();
    bool isUpdateAction();
    void setIsUpdateAction(bool);
public:
    void setOwner(uDDOModel* pOwner);
    void setUnitInfo(u32 Gitk, u32 UniqueId, u32 UnitId);
    void setNpcId(s32 NpcId);
    u32 getUniqueId();
    u32 getUnitId();
    void setDispEnable(bool Disp);
    bool isDispEnable();
    virtual s32 getNpcId();  // vtable slot 24
    u32 getGitk();
    u32 getLoadPriority() const;
    void setLoadPriority(u32 Priority);
    u32 getPriorityNo() const;
    void setPriorityNo(u32 PriorityNo);
    u32 getBtlBgmReqNo() const;
    void setBtlBgmReqNo(u32);
    bool isAdvantageBgm() const;
    void setIsAdvantageBgm(bool flag);
    bool isBloodEnemy() const;
    void setBloodEnemy(bool flag);
    u32 getNamedParamsId() const;
    void setNamedParamsId(u32 id);
    void setForcePeriodic(nNetMsgData::nCtrl::NET_MSG_ID msgId);
    void setLayoutId(const nLayout::stLayoutID& layoutID);
    const nLayout::stLayoutID getLayoutId() const;
    void setSetNo(s32 no);
    s32 getSetNo() const;
    void setSplitId(const nLayout::stSplitID& splitID);
    const nLayout::stSplitID getSplitId() const;
    void setGroupParam(const cGroupParam* pParam);
    const cGroupParam* getGroupParam() const;
    void setQuestId(u32 QuestId);
    u32 getQuestId();
    MtVector3 getNetPos();
    void setNetPos(MtVector3& Pos);
    f32 getNetDir();
    void setNetDir(f32 Dir);
    MtVector3 getSetPos() const;
    void setSetPos(const MtVector3& pos);
    f32 getSetDir() const;
    void setSetDir(f32 dir);
    void setUnitMove(bool flag);
    bool getUnitMove();
    void setUnitDraw(bool flag);
    bool getUnitDraw();
    bool fadeUnit();
    void setFadeOut();
    bool isFadeOut();
    void setDisableDispTimer(f32 Timer);
    bool isInDisableDispTime();
    void setForceDispTimer(f32 Timer);
    bool isInForceDispTime();
protected:
    void updateArcLoad();
public:
    bool startArcLoad(u32 AddTag);
    void setupArcLoad();
    bool startArcLoad();
    void addArcTag(u32 AddTag);
    virtual bool isArcLoadFinish();  // vtable slot 25
    bool isArcLoadStart();
    rArchive* getArcPtr(u32 idx);
    u32 getArcTagId(u32 idx);
    u8 getArcNum();
    void releaseArchive();
    void finishLoadArcPl();
protected:
    nNetBase::cNetBase* mpNetRpc;  // offset: 0x48
    uDDOModel* mpModel;  // offset: 0x50
    cContextCharacter* mpContext;  // offset: 0x58
    cContextInstance* mpContextInst;  // offset: 0x60
private:
    u8 mCtrlType;  // offset: 0x68
    bool mIsCommunicate;  // offset: 0x69
    bool mIsFirstReceive;  // offset: 0x6a
    bool mIsUpdateAction;  // offset: 0x6b
    nNetMsgData::nCtrl::NET_MSG_ID mForcePeriodic;  // offset: 0x6c
    f32 mSendActIntervalTimer;  // offset: 0x70
    bool mIsSaveSendAct;  // offset: 0x74
    f32 mCorePointSendInterval;  // offset: 0x78
    f32 mBossCondSendInterval;  // offset: 0x7c
    bool mIsSelfDeleteContextInst;  // offset: 0x80
    cContextInterface mContextInterface;  // offset: 0x88
    u32 mAfterEnemyGroupNum;  // offset: 0xa0
    u32 mAfterEnemyStatusGroup[16];  // offset: 0xa4
    u32 mAfterEnemyStatusSubGroup[16];  // offset: 0xe4
    u64 mAfterEnemyBitCtrlCollision;  // offset: 0x128
    u8 mAfterEnemyCtrlRegionSelectNo;  // offset: 0x130
    u64 mAfterEnemyBitCtrlParts;  // offset: 0x138
    u64 mAfterEnemyBitCtrlWorkRate;  // offset: 0x140
    u64 mAfterEnemyBitCtrlScale;  // offset: 0x148
    u64 mAfterEnemyBitCtrlMontage;  // offset: 0x150
    u32 mAfterEnemyBitCtrlSyncBit;  // offset: 0x158
protected:
    u32 mBattleBgmReqNo;  // offset: 0x15c
    u32 mNamedParamsId;  // offset: 0x160
    bool mIsAdvantageBgm;  // offset: 0x164
    bool mIsBloodEnemy;  // offset: 0x165
    bool mIsFadeOut;  // offset: 0x166
    f32 mFadeTimer;  // offset: 0x168
    bool mIsDisp;  // offset: 0x16c
    u32 mGitk;  // offset: 0x170
    u32 mUniqueId;  // offset: 0x174
    u32 mUnitId;  // offset: 0x178
    s32 mNpcId;  // offset: 0x17c
    cpLayout mLayout;  // offset: 0x180
    nNetMsgData::stNetPos mSetPos;  // offset: 0x1f0
    f32 mSetDir;  // offset: 0x208
    u32 mLoadPriority;  // offset: 0x20c
    u32 mPriorityNo;  // offset: 0x210
    bool mUnitMove;  // offset: 0x214
    bool mUnitDraw;  // offset: 0x215
    f32 mDisableDispTimer;  // offset: 0x218
    f32 mForceDispTimer;  // offset: 0x21c
    bool mIsArcLoadEnd;  // offset: 0x220
    bool mIsArcLoadRequest;  // offset: 0x221
    cTagArcLoad mArcLoadMgr;  // offset: 0x228
public:
    static MyDTI DTI;
private:
    static const u32 LOW_PRIORITY_ACT_INTERVAL = 30;
    static const f32 COREPOINT_INTERVAL;
    static const u32 BOSS_CONDITION_INTERVAL = 90;
};

// Inline, no code of its own: checked where it is inlined.
inline uDDOModel* uControl::getObjModel() {
    return this->mpModel;
}

// Inline, no code of its own: checked where it is inlined.
inline cContextCharacter* uControl::getContext() {
    return this->mpContext;
}

// Inline, no code of its own: checked where it is inlined.
inline cContextInstance* uControl::getContextInst() {
    return this->mpContextInst;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 uControl::getUniqueId() {
    return this->mUniqueId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 uControl::getUnitId() {
    return this->mUnitId;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uControl::isFadeOut() {
    return this->mIsFadeOut;
}
