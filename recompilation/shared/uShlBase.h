#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtString.h"
#include "cEfcHandle.h"
#include "cGeneralPointPtr.h"
#include "cpLockOn.h"
#include "cpShlShotCtrl.h"
#include "nShlBase.h"
#include "nShlStick.h"
#include "sCollision.h"
#include "sEffectExt.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cEfcHandle;
class cGeneralPoint;
class cGeneralPointPtr;
class cHitGeom;
class cHitInfo;
class cHitNode;
class cShlGroupParam;
class cUnit;
namespace nShlBase { struct stShlEfctParam; }
namespace nShlBase { struct stShlSEParam; }
namespace nShlStick { class cStickObjectCtrl; }
class rEffectProvider;
class rSoundRequest;
class uBaseModel;
class uCoord;

// Declarations
class cShlParamBase;
class uShlBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cShlParamBase : public MtObject
{
public:
    enum SET_TYPE
    {
        SET_TYPE_NORMAL = 0,
        SET_TYPE_GROUND = 1,
        SET_TYPE_GROUND_DIR = 2,
    };
    enum CAM_RES_TYPE
    {
        CAM_RES_CMN = 0,
        CAM_RES_MW = 1,
        CAM_RES_SW = 2,
    };
    enum RESOURCE_TYPE
    {
        RESOURCE_TYPE_0 = 0,
        RESOURCE_TYPE_1 = 1,
        RESOURCE_TYPE_CMN = 2,
        RESOURCE_TYPE_NONE = 3,
        RESOURCE_TYPE_JOB_SHARE = 4,
    };
    enum HIT_MARK_TYPE
    {
        HIT_MARK_TYPE_NORMAL = 0,
        HIT_MARK_TYPE_INV_MOVE = 1,
        HIT_MARK_TYPE_AXIS_Y = 2,
        HIT_MARK_TYPE_HIT_NORMAL = 3,
        HIT_MARK_TYPE_LAND_NORMAL_MOVE = 4,
    };
    enum
    {
        SAO_NONE = 0,
        SAO_ID_0154 = 2,
        SAO_ID_0156 = 4,
        SAO_ID_0034 = 8,
        SAO_ID_0153 = 16,
        SAO_ID_0155 = 32,
        SAO_ID_0205 = 64,
        SAO_ID_0362 = 128,
        SAO_ID_0378 = 256,
        SAO_ID_0372 = 512,
    };
    enum
    {
        SO_NONE = 0,
        SO_FIND_GROUND_MOVE = 1,
        SO_OBJ_HIT_KILL = 4,
        SO_NO_CREATE_SLAVE = 8,
        SO_SLAVE_KILL_SYNC = 16,
        SO_NO_USE_KEEP_ATK_ADJUST = 32,
        SO_HIT_ONLY_OWNER = 64,
        SO_NO_HIT_OWNER = 128,
        SO_INHERIT_STICK_INFO = 256,
        SO_INHERIT_MATLIX = 512,
        SO_NO_DAMAGE_FROM_SHLID = 1024,
        SO_NO_HIT_TO_SHLID = 2048,
        SO_NOTIFY_ATTACK_TEST = 4096,
        SO_DIE_PARENT_DEAD = 8192,
        SO_BIT_DELETE = 65536,
        SO_BIT_ENCHANT = 131072,
        SO_BIT_CONDITION = 262144,
        SO_BIT_PARENT_DELTA_TIME = 524288,
        SO_BIT_OWNER_DAMAGE_DIE = 1048576,
        SO_BIT_CAN_BE_LOCKED = 2097152,
        SO_BIT_DIE_SHL_IS_NOW_TRUE = 4194304,
        SO_BIT_NO_DIE_CS_CHANGE = 8388608,
        SO_BIT_BREAK_SHL_CREATE_NOW = 16777216,
        SO_DEFAULT = 8192,
    };
    enum
    {
        EO_NONE = 0,
        EO_PARENT_OWNER = 1,
        EO_SHOT_CONST = 2,
        EO_SHL_CONST = 4,
        EO_HIT_CONST = 8,
        EO_FINISH_CONST = 16,
        EO_ORIGIN_ONER = 32,
        EO_TIME_DIE_FRAME = 64,
        EO_HIT_EF_NO_N_ELEM = 128,
        EO_PL_ONLY = 256,
        EO_HIDE_TALK = 512,
        EO_BASE_END = 5,
        EO_DEFAULT = 20,
    };
    enum
    {
        SVO_USE_PLAYER_RES = 1,
        SVO_SHOT_VIB_DISTANCE = 2,
        SVO_HIT_VIB_DISTANCE = 4,
        SVO_END_VIB_DISTANCE = 8,
        SVO_MYPLAYER_ONLY_SHOT = 16,
        SVO_MYPLAYER_ONLY_HIT = 32,
        SVO_MYPLAYER_ONLY_END = 64,
        SVO_DEFAULT = 0,
    };
    enum
    {
        SEO_NONE = 0,
        SEO_SHOT_OWNER = 2,
        SEO_ADD_ELEMENT_LOOP_LV1 = 1,
        SEO_ADD_ELEMENT_LOOP_LV2 = 4,
        SEO_ADD_ELEMENT_SHOT_LV1 = 8,
        SEO_ADD_ELEMENT_SHOT_LV2 = 16,
        SEO_CALL_HIT_TEST = 32,
        SEO_SHOT_LOOP_OWNER = 64,
    };
    enum
    {
        SHL_DAMAGE_ATTR_NONE = 0,
        SHL_DAMAGE_ATTR_PHYSICAL = 1,
        SHL_DAMAGE_ATTR_MAGIC = 2,
        SHL_DAMAFE_ATTR_DEFAULT = 1,
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamBase();
    virtual ~cShlParamBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyCollision(MtPropertyList& s);  // vtable slot 7
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void createPropertyModel(MtPropertyList& s);  // vtable slot 10
    virtual void copy(const cShlParamBase* pParam);  // vtable slot 11
protected:
    nShlBase::SHL_AXIS getShlAxis() const;
private:
    MT_CTSTR getModelPath() const;
    void setModelPath(const MtString&);
    void setGroupParam(const cShlGroupParam* pGroup);
public:
    const cShlGroupParam* getGroupParam() const;
public:
    nShlBase::SHL_AXIS axis;  // offset: 0x8
    SET_TYPE shlSetType;  // offset: 0xc
    f32 groundCkHeight;  // offset: 0x10
    f32 groundOfs;  // offset: 0x14
    MtVector3 rotSpd;  // offset: 0x20
    bool isNoUseScale;  // offset: 0x30
    f32 scale;  // offset: 0x34
    f32 initWaitFrame;  // offset: 0x38
    CAM_RES_TYPE camResType;  // offset: 0x3c
    s32 cameraNo;  // offset: 0x40
    nShlBase::LIMIT_ID limitID;  // offset: 0x44
    nShlBase::SHL_ID shlID;  // offset: 0x48
    u32 shlOption;  // offset: 0x4c
    u32 shlAbilityOption;  // offset: 0x50
    u32 shlDeleteBit;  // offset: 0x54
    nShlBase::SHL_ID noDamageShlID;  // offset: 0x58
    nShlBase::SHL_ID noHitShlID;  // offset: 0x5c
    bool isTimeDie;  // offset: 0x60
    f32 dieFrame;  // offset: 0x64
    s32 shlNoDie;  // offset: 0x68
    f32 findGroundHeight;  // offset: 0x6c
    f32 dieFramePutTypeEx;  // offset: 0x70
    bool isBreak;  // offset: 0x74
    s32 shlNoBreak;  // offset: 0x78
    s32 dmgShlNo;  // offset: 0x7c
    f32 dmgShlInterval;  // offset: 0x80
    u32 damageAttr;  // offset: 0x84
    bool isUseHitGroup;  // offset: 0x88
    u32 hitGroup;  // offset: 0x8c
    bool isAtkFlgKibakuNoHit;  // offset: 0x90
    bool isShotWallCheck;  // offset: 0x91
    s32 shotWallJnt;  // offset: 0x94
    f32 changeActToDieFrame;  // offset: 0x98
    s32 seq_0;  // offset: 0x9c
    s32 at_0;  // offset: 0xa0
    s32 shared_uid_0;  // offset: 0xa4
    f32 colTimer_0;  // offset: 0xa8
    s32 seq_1;  // offset: 0xac
    s32 at_1;  // offset: 0xb0
    s32 shared_uid_1;  // offset: 0xb4
    f32 colTimer_1;  // offset: 0xb8
    s32 seq_2;  // offset: 0xbc
    s32 at_2;  // offset: 0xc0
    s32 shared_uid_2;  // offset: 0xc4
    nShlBase::NOTICE_SHL_ID noticeType;  // offset: 0xc8
    f32 noticeTime;  // offset: 0xcc
    s32 maxHitCount;  // offset: 0xd0
    bool isMaxHitDie;  // offset: 0xd4
    s32 colCustomId;  // offset: 0xd8
    u8 criticalBit;  // offset: 0xdc
    RESOURCE_TYPE epvResType;  // offset: 0xe0
    s32 epvIndex;  // offset: 0xe4
    s32 epvNoShot;  // offset: 0xe8
    s32 epvNoShl;  // offset: 0xec
    s32 epvNoHit;  // offset: 0xf0
    s32 epvNoFinish;  // offset: 0xf4
    s32 epvNoCheckIn;  // offset: 0xf8
    f32 epvCheckInterval;  // offset: 0xfc
    HIT_MARK_TYPE hitMarkType;  // offset: 0x100
    u32 efOption;  // offset: 0x104
    s32 padVib;  // offset: 0x108
    s32 padVibHit;  // offset: 0x10c
    s32 padVibEnd;  // offset: 0x110
    u32 padVibOption;  // offset: 0x114
    RESOURCE_TYPE seResType;  // offset: 0x118
    RESOURCE_TYPE seHitResType;  // offset: 0x11c
    s32 seNoShot;  // offset: 0x120
    s32 seNoHit;  // offset: 0x124
    s32 seNoLoop;  // offset: 0x128
    s32 seNoLoopStop;  // offset: 0x12c
    s32 seLoopJoint;  // offset: 0x130
    s32 seNoFinish;  // offset: 0x134
    s32 seNoCheckIn;  // offset: 0x138
    f32 seCheckInterval;  // offset: 0x13c
    u32 seOption;  // offset: 0x140
    bool isUseModel;  // offset: 0x144
    MtString modelResPath;  // offset: 0x148
    u32 modelDrawMode;  // offset: 0x150
    f32 groundCkUnderHeight;  // offset: 0x154
private:
    const cShlGroupParam* pGroupParam;  // offset: 0x158
public:
    static MyDTI DTI;
};

class uShlBase : public uDDOModel
{
public:
    enum SIGNAL
    {
        SIGNAL_NONE = 0,
        SIGNAL_KILL = 1,
        SIGNAL_BUTTON_ON = 2,
        SIGNAL_FORCE_KILL = 3,
    };
    enum
    {
        HIT_RESULT_NONE = 0,
        HIT_RESULT_OBJ = 1,
        HIT_RESULT_SCR = 2,
        HIT_RESULT_WATER = 4,
        HIT_RESULT_GUARD = 8,
        HIT_RESULT_ATTACK_TEST = 16,
    };
    enum
    {
        HIT_OP_NONE = 0,
        HIT_OP_MULTI = 1,
    };
    enum
    {
        SHL_CHECK_IN_EFC_MAX = 8,
    };
    enum
    {
        SHL_CHECK_IN_SE_MAX = 8,
    };
    enum
    {
        VIB_TYPE_SHOT = 0,
        VIB_TYPE_HIT = 1,
        VIB_TYPE_END = 2,
    };
public:
    class MyDTI;
    struct efcInControl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct efcInControl
    {
    public:
        u32 uId;  // offset: 0x0
        f32 clearTimer;  // offset: 0x4
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
    const cShlParamBase* getShlParam() const;
    uShlBase();
    virtual ~uShlBase();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void before();  // vtable slot 173
    virtual void update();  // vtable slot 174
    virtual void updateSub();  // vtable slot 175
    virtual void after();  // vtable slot 176
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void updateMatrix();  // vtable slot 71
    virtual void setMaster(bool is_master);  // vtable slot 66
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 88
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackHeal(cHitInfo* pHitInfo);  // vtable slot 127
    virtual void callbackGuarded(cHitInfo* pHitInfo);  // vtable slot 79
    bool canHitObj(const uDDOModel* pUnit);
    virtual bool callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom);  // vtable slot 144
    void setInitWait(f32);
    void setShotCoord(const MtVector3& pos, const MtVector3& dir, const MtVector3& up, nShlBase::SHL_AXIS axis);
    void setShotCoord(const MtVector3& pos, const MtVector3& dir);
    void setShotCoord(const MtVector3& pos, const MtVector3& dir, const MtMatrix& mat);
    void setAngle(const MtVector3& main, const MtVector3& up, const MtVector3& up2, nShlBase::SHL_AXIS axis);
    void setAngle(const MtMatrix& mat);
    void setDir(const MtVector3& dir);
    nShlBase::SHL_ID getShlId() const;
    void setOwnerSignal(s32 signal, f32 wait);
    s32 getOwnerSignal() const;
    const MtVector3& getInitPos() const;
    const MtVector3& getTargetPos() const;
    void setTargetPos(const MtVector3& pos);
    void setParentTarget(const uDDOModel* pParent, s32 joint, const MtMatrix& wMat);
    void setParentTarget(const uDDOModel* pParent, const MtMatrix& wMat, const MtVector3& scale, s32 defJoint);
    void setParentTargetLocal(const uDDOModel* pParent, s32 joint, const MtMatrix& lMat);
    void setParentTargetInherit(const uShlBase* pParentShl);
    void setDieFrameRate(f32);
    void setEnchant(uDDOModel* pEnchantOwner, u32 attr);
    u32 getHitResultFlag() const;
    void setOnlyTarget(const uBaseModel*);
    const uBaseModel* getOnlyTarget() const;
    void setNoHitTarget(const uDDOModel*);
    const uDDOModel* getNoHitTarget() const;
    static f32 calcSpeed(f32 spd, f32 accel, f32 max, f32 deltaTime);
    void inheritParent(uShlBase* pParent);
    MtVector3 getMatMainDir() const;
    MtVector3 getMatUpDir() const;
    MtVector3 getMatSubDir() const;
    bool isShlOption(u32 flag) const;
    bool isShlAbilityOption(u32 flag) const;
    void skipShotEffect();
    void requestKill();
    bool isRequestKill() const;
protected:
    void init();
    virtual void initSub();  // vtable slot 177
    virtual void setShlEfct();  // vtable slot 178
    void setMuzzle(const MtVector3& dir, const MtVector3& pos, f32 scale);
    void setHitMark(const MtVector3& pos, f32 scale);
    void setFinishEfct();
    virtual void requestShotSE();  // vtable slot 179
    void requestHitSE();
    void requestLoopSE();
    void requestLoopStopSE();
    void requestCmnCastSE(s32 no);
    void cameraOff();
    void cameraOffNever();
    bool isCollisionWall(sCollision::TriangleInfo& info, const MtVector3& pos, const MtVector3& posOld, u32* intercect);
    void setCollision();
    virtual void setCollisionSub(s32 seqNo, s32 groupNo, s32 attackNo, s32 shared_uid);  // vtable slot 180
    void setNoticeCollision();
    virtual u32 getCollisionIndex() const;  // vtable slot 181
    f32 homingPos(MtVector3& moveVec, const MtVector3& targetPos, f32 rad);
    f32 homingDir(MtVector3& moveVec, const MtVector3& targetVec, f32 rad);
    uBaseModel* getHitTarget();
    uDDOModel* getHitTargetObjMdl();
    static u32 getMatIndexMain(u32 axis);
    static u32 getMatIndexUp(u32 axis);
    static u32 getMatIndexSub(u32 axis);
    const MtVector3& getWorldOffset() const;
    virtual void calcMoveVector(MtVector3& vec, s32 joint);  // vtable slot 182
    void clearHitUnitList();
    s32 getEpvIndex() const;
private:
    void updateLockOnTarget();
public:
    void setShlParent(uDDOModel* pParent);
    uDDOModel* getParent();
    void setOwner(uDDOModel* pOwner);
    uDDOModel* getOwner();
    const uDDOModel* getOwner() const;
    bool isInherit() const;
    nShlBase::LIMIT_ID getLimitID() const;
    const cGeneralPoint* getLockOnTarget() const;
    void setTargetUId(u32 uid);
    void setLockOnIndex(s32 index);
    const cpLockOn::cLockOnTarget& getCustomLockOnTarget() const;
    f32 getTimer() const;
    void setTimer(f32);
    const MtVector3& getShlMoveDir() const;
    const MtVector3& getHitPos() const;
    f32 getDamage() const;
    void setInitParamScale(f32);
    void setAngleOffset(f32, f32, f32);
    u32 getElement() const;
    void setElement(u32 elem);
    uDDOModel* getEnchantOwner();
    u32 getHitLandMaterial() const;
    void initLookPos();
    const MtVector3& getLookPos() const;
    bool isPlEmFlip() const;
    void setIsPlEmFlip(bool);
    u32 getFriendCategory() const;
    void setFriendCategory(u32);
    u32 getFree00() const;
    void setFree00(u32);
    u16 getAtkAdjustUniqueId() const;
    void setAtkAdjustUniqueId(const u16 uniqueId);
    bool isSlaveShlCreateEnable();
    uShlBase* createNextShl(u32 index, u32 shotSts, bool isNow);
    void addShlDamage(cHitInfo* pHitInfo);
    virtual void executeAddDamage();  // vtable slot 183
    MT_CTSTR getEpvPath();
    MT_CTSTR getSePath();
    void addExtendDieDist(f32 dist);
    void addExtendCriDist(f32 dist);
    void addExtendDieTime(f32 frame);
    void setExCollisionPos(u32, const MtVector3&);
    bool isEffectiveLockOn() const;
protected:
    void requestSE(s32 reqNo, const MtVector3& pos);
    void requestSE(s32 reqNo, uCoord* pCoord);
    void requestSE(s32 reqNo, uCoord* pCoord, s32 joint);
    void requestSE(rSoundRequest* pRes, s32 reqNo, const MtVector3& pos);
    cEfcHandle* setEffect(s32 epvNo);
    cEfcHandle* setEffect(s32 epvNo, const MtVector3& pos);
    cEfcHandle* setEffect(s32 epvNo, sEffectExt::EfcParam& param);
    cEfcHandle* setE2DEffect(s32 epvNo);
    uDDOModel* getEfctParent();
    void requestShlVibration(u32 type);
public:
    const nShlStick::cStickObjectCtrl& getStickObjCtrl() const;
    void setSitckObjectData(const nShlStick::cStickObjectCtrl& ctrl);
    void setShlParam(const cShlParamBase* pParam);
    u32 getShlParamGroup() const;
    void setShlParamGroup(u32 index);
    u32 getShlParamIndex() const;
    void setShlParamIndex(u32 index);
    void setShlShotReqInfo(cpShlShotCtrl::cShlShotReqInfo& info);
protected:
    const cShlParamBase* getShlParamBase() const;
    rEffectProvider* getEpvResource();
    rSoundRequest* getSeResource();
    void setEpvResource(rEffectProvider* pRes);
    void setSeResource(rSoundRequest* pRes);
    // Address: 0x01b0b2a0 - 0x01b0b2a1 (1 bytes)
    virtual void eventCreatedBreakShl(uShlBase& shl) {}  // vtable slot 184
public:
    virtual u32 getHitLightToModel();  // vtable slot 36
    virtual bool isOwnerCatch() const;  // vtable slot 185
    void adjustDirToTarget(const cGeneralPoint* pTarget, const MtVector3& initVec, f32 rate);
    void adjustDirToMove();
private:
    u32 mRoutine;  // offset: 0x246c
    f32 mInitWait;  // offset: 0x2470
    u16 mAtkAdjustUniqueId;  // offset: 0x2474
protected:
    uDDOModel* mpParent;  // offset: 0x2478
    uDDOModel* mpOwner;  // offset: 0x2480
    nShlBase::SHL_ID mShlId;  // offset: 0x2488
    s32 mOwnerSignal;  // offset: 0x248c
    f32 mOwnerSignalWait;  // offset: 0x2490
    f32 mInitParamScale;  // offset: 0x2494
    rEffectProvider* mprEpv;  // offset: 0x2498
    rSoundRequest* mprSE;  // offset: 0x24a0
    uDDOModel* mpEnchantOwner;  // offset: 0x24a8
    u32 mElement;  // offset: 0x24b0
    f32 mTimer;  // offset: 0x24b4
    f32 dieFrameRate;  // offset: 0x24b8
    f32 mDamage;  // offset: 0x24bc
    f32 mDamageCameraReqFrame;  // offset: 0x24c0
    f32 mDamageLimit;  // offset: 0x24c4
    bool mIsBreakSlaveSync;  // offset: 0x24c8
    MtVector3 mInitPos;  // offset: 0x24d0
    MtVector3 mInterPos;  // offset: 0x24e0
    MtVector3 mRotSpeed;  // offset: 0x24f0
    MtVector3 mShlMoveDir;  // offset: 0x2500
    MtVector3 mLRotation;  // offset: 0x2510
    MtMatrix mMoveMat;  // offset: 0x2520
    u32 mTargetUId;  // offset: 0x2560
    s32 mLockOnIndex;  // offset: 0x2564
    cGeneralPointPtr mLockOnTarget;  // offset: 0x2568
    MtVector3 mTargetPos;  // offset: 0x2580
    cpLockOn::cLockOnTarget mCstmLockOnTarget;  // offset: 0x2590
    const uDDOModel* mpParentTarget;  // offset: 0x2630
    bool mIsTargetParent;  // offset: 0x2638
    s32 mParentJoint;  // offset: 0x263c
    MtMatrix mParentLocalMat;  // offset: 0x2640
    u32 mMaterialFlag;  // offset: 0x2680
    u32 mLandMaterialFlag;  // offset: 0x2684
    u32 mWallEffAttr;  // offset: 0x2688
    cEfcHandle* mpEfcHandle;  // offset: 0x2690
    MtTypedArray<cEfcHandle> mEnchantEfcHandle;  // offset: 0x2698
    efcInControl mCheckInEfcCtrl[8];  // offset: 0x26b8
    efcInControl mCheckInSeCtrl[8];  // offset: 0x26f8
    u32 mHitResultFlag;  // offset: 0x2738
    u32 mHitEfctFlag;  // offset: 0x273c
    MtVector3 mHitPos;  // offset: 0x2740
    MtVector3 mHitNormal;  // offset: 0x2750
    s32 mHitJoint;  // offset: 0x2760
    MtMatrix mHitJointMat;  // offset: 0x2770
    u32 mHitRegionId;  // offset: 0x27b0
    uBaseModel* mpHitTarget;  // offset: 0x27b8
    uDDOModel* mpHitTargetObjMdl;  // offset: 0x27c0
    cHitNode* mpAtkNode;  // offset: 0x27c8
    cHitNode* mpNoticeNode;  // offset: 0x27d0
    bool mIsCreateColOnce;  // offset: 0x27d8
    bool mIsNoticeOnce;  // offset: 0x27d9
    f32 mNoticeTime;  // offset: 0x27dc
    const uBaseModel* mpOnlyTarget;  // offset: 0x27e0
    const uDDOModel* mpNoHitTarget;  // offset: 0x27e8
    const cUnit* mpHitUnits[8];  // offset: 0x27f0
    f32 mHitUnitTimer[8];  // offset: 0x2830
    u32 mHitCount[8];  // offset: 0x2850
    u32 mHitOption;  // offset: 0x2870
    u32 mFriendCategory;  // offset: 0x2874
    bool mIsPlEmFlip;  // offset: 0x2878
    bool mIsEffectFinish;  // offset: 0x2879
    bool mIsRequestLoopStopSE;  // offset: 0x287a
    bool mIsCameraOff;  // offset: 0x287b
    bool mIsCameraOffNever;  // offset: 0x287c
    bool mIsInherit;  // offset: 0x287d
    bool mIsKillReq;  // offset: 0x287e
    bool mIsKillWait;  // offset: 0x287f
    bool mIsCreateDamageShl;  // offset: 0x2880
    f32 mDamageShlIntervalTime;  // offset: 0x2884
    u32 mExCollisionFlag;  // offset: 0x2888
    MtVector3 mExCollisionPos;  // offset: 0x2890
    MtVector3 mLookPos;  // offset: 0x28a0
    MtVector3 mAngleOffset;  // offset: 0x28b0
    MtVector3 mWorldOffset;  // offset: 0x28c0
    MtVector3 mParentPosOld;  // offset: 0x28d0
    u32 mFree00;  // offset: 0x28e0
    s32 mCreateSeqNo;  // offset: 0x28e4
    f32 mExtendDieDist;  // offset: 0x28e8
    f32 mExtendCriDist;  // offset: 0x28ec
    f32 mExtendDieTime;  // offset: 0x28f0
    u32 mOwnerInitAct;  // offset: 0x28f4
    cpShlShotCtrl::cShlShotReqInfo mShotReqInfo;  // offset: 0x2900
    bool mIsSkipShotEffect;  // offset: 0x29d0
private:
    s32 mParamGroup;  // offset: 0x29d4
    s32 mParamIndex;  // offset: 0x29d8
    const cShlParamBase* mpShlParam2;  // offset: 0x29e0
    const nShlBase::stShlEfctParam* mpEfctParamTbl;  // offset: 0x29e8
    const nShlBase::stShlSEParam* mpSEParamTbl;  // offset: 0x29f0
protected:
    nShlStick::cStickObjectCtrl mStickObjCtrl;  // offset: 0x2a00
public:
    static MyDTI DTI;
    static const u32 MAX_HIT_UNIT = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline uDDOModel* uShlBase::getOwner() {
    return this->mpOwner;
}

// Inline, no code of its own: checked where it is inlined.
inline const cShlParamBase* uShlBase::getShlParamBase() const {
    return this->mpShlParam2;
}
