#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "cResPath.h"
#include "cZoneIndoorHandle.h"
#include "cZoneUnitCtrl.h"
#include "nLayout.h"
#include "rAIFSM.h"
#include "rCollision.h"
#include "res_ptr.h"
#include "sCollision.h"

// Forward declarations
class ItemGetInfo;
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtMatrix;
class MtOBB;
class MtQuaternion;
class MtVector3;
class cGatherItemList;
class cGroupParam;
class cOmParam;
class cZoneIndoorHandle;
class cZoneUnitCtrl;
class cpOmGather;
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }
class rAIFSM;
class rCollision;
class uBaseModel;
class uOmSimple;
class uSoundGenerator;

// Declarations
class cOmControl;
class cOmTreeControl;
struct stInsValue;

// Type aliases from DWARF
using InsValue = stInsValue;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using uintptr = __uintptr_t;

class cOmTreeControl : public MtObject
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
    cOmTreeControl();
    virtual ~cOmTreeControl();
    void move();
    void moveArc(bool isIns);
    void reqLoadOmArc(f32 len, bool bOmIns);
    void releaseOmArc();
    f32 getLoadLength();
    f32 getKillLength();
    void createInsUnit();
    void reqkillInsUnit();
    void killInsUnit();
    void initSbc();
    void eraseSbc();
    void moveSbc();
    bool hasSBC();
    void updateSbc(MtMatrix& mtx);
public:
    bool mbEnableArc;  // offset: 0x8
    bool mbOmInsAdd;  // offset: 0x9
    res_ptr<rCollision> mprSbc[2][2];  // offset: 0x10
    sCollision::SBC_HANDLE mhSbc[2][2];  // offset: 0x30
    bool mbEnableSBC;  // offset: 0x40
    MtVector3 mPos;  // offset: 0x50
    MtQuaternion mQuat;  // offset: 0x60
    cZoneUnitCtrl mZoneUnitCtrl;  // offset: 0x70
    u32 mhZoneScr;  // offset: 0x90
    u32 mhZoneEfc;  // offset: 0x94
    s32 mOmID;  // offset: 0x98
    const cOmParam* mpOmParam;  // offset: 0xa0
    uintptr mUniqueId;  // offset: 0xa8
    bool mbDirty;  // offset: 0xb0
    u32 mDirtyCount;  // offset: 0xb4
    static MyDTI DTI;
    static MtCriticalSection mCS;
    static const u32 InvalidOmID = 0;
};

struct stInsValue
{
public:
    struct Data;
public:
    struct Data
    {
    public:
        Data();
    public:
        union
        {
        public:
            u32 mU32;  // offset: 0x0
            struct
            {
            public:
                u32 mOneTime : 1;  // offset: 0x0
                u32 mRno : 5;  // offset: 0x0
                u32 mOpposite : 1;  // offset: 0x0
                u32 mEnd : 1;  // offset: 0x0
                u32 mMemberIndex : 4;  // offset: 0x0
                u32 mUseItem : 1;  // offset: 0x0
                u32 mNoUseItem : 1;  // offset: 0x0
                u32 mReturn : 1;  // offset: 0x0
                u32 mGimmick : 1;  // offset: 0x0
                u32 mRemain : 16;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x0
    };
public:
    stInsValue();
    u32 getOneTime() const;
    void setOneTime(u32);
    u32 getRno() const;
    void setRno(u32);
    u32 getOpposite() const;
    void setOpposite(u32);
    u32 getEnd() const;
    void setEnd(u32);
    u32 getRemain() const;
    void setRemain(u32);
    u32 getMemberIndex() const;
    void setMemberIndex(u32);
    u32 getUseItem() const;
    void setUseItem(u32);
    u32 getNoUseItem() const;
    void setNoUseItem(u32);
    u32 getReturn() const;
    void setReturn(u32);
    u32 getGimmick() const;
    void setGimmick(u32);
    u32 getU32() const;
    void setU32(u32 NewValue);
private:
    Data mData;  // offset: 0x0
};

class cOmControl : public MtObject
{
public:
    enum
    {
        RNO_STATE_ENABLE = 0,
        RNO_STATE_REQ_DEL = 1,
        RNO_STATE_DEL_WAIT = 2,
        RNO_STATE_NUM = 3,
    };
    enum
    {
        TC_NONE = 0,
        TC_NEXT = 1,
        TC_OK = 2,
        TC_EM_KILL = 3,
        TC_EMG_KILL = 4,
        TC_EMG_ADD = 5,
        TC_END = 6,
    };
public:
    class MyDTI;
    struct CommunicateData;
    class InputLot;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CommunicateData
    {
    public:
        bool mbReceive;  // offset: 0x0
        bool mbUseItem;  // offset: 0x1
        bool mbWarpReq;  // offset: 0x2
        bool mbWarpOK;  // offset: 0x3
    };
public:
    class InputLot : public MtObject
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
        InputLot();
        virtual ~InputLot();
    public:
        s32 mOmID;  // offset: 0x8
        uintptr mUniqueId;  // offset: 0x10
        MtVector3 mPos;  // offset: 0x20
        MtQuaternion mQuat;  // offset: 0x30
        MtVector3 mScale;  // offset: 0x40
        bool mbOffAutoEFF;  // offset: 0x50
        bool mbOffOnlyAutoEFF;  // offset: 0x51
        bool mbOpenFlag;  // offset: 0x52
        bool mbEnableSyncLight;  // offset: 0x53
        bool mbEnableZone;  // offset: 0x54
        u32 mInitMtnNo;  // offset: 0x58
        u32 mAreaMasterNo;  // offset: 0x5c
        u32 mWarpPointId;  // offset: 0x60
        u32 mKeyNo;  // offset: 0x64
        u32 mQuestFlag;  // offset: 0x68
        u16 mAreaReleaseNo;  // offset: 0x6c
        bool mAreaReleaseON;  // offset: 0x6e
        bool mAreaReleaseOFF;  // offset: 0x6f
        nLayout::stLayoutID mLayoutId;  // offset: 0x70
        s32 mSetNo;  // offset: 0x74
        cGroupParam* mpGroupParam;  // offset: 0x78
        nLayout::stSplitID mSplitId;  // offset: 0x80
        bool mbPRT;  // offset: 0x84
        MtVector3 mPRTPos;  // offset: 0x90
        f32 mPRTScale;  // offset: 0xa0
        u32 mQuestID;  // offset: 0xa4
        u32 mStageNo[3];  // offset: 0xa8
        u32 mStartPosNo[3];  // offset: 0xb4
        u32 mQuestNo[3];  // offset: 0xc0
        u32 mQuestFlagNo[3];  // offset: 0xcc
        u32 mSpotId[3];  // offset: 0xd8
        bool mIsQuest;  // offset: 0xe4
        u32 mQuestId;  // offset: 0xe8
        u32 mUID[4];  // offset: 0xec
        u32 mTransition[4];  // offset: 0xfc
        u32 mState[4];  // offset: 0x10c
        s32 mCamEvNo[4];  // offset: 0x11c
        cResPath<rAIFSM> mrFSMCam[4];  // offset: 0x130
        s32 mAddGroupNo;  // offset: 0x150
        s32 mAddSubGroupNo;  // offset: 0x154
        f32 mRange;  // offset: 0x158
        u32 mGrp;  // offset: 0x15c
        bool mIsAll;  // offset: 0x160
        bool mIsOneTime;  // offset: 0x161
        u32 mGatheringType;  // offset: 0x164
        bool mIsGatherEnemy;  // offset: 0x168
        u32 mGatherEnemyUID;  // offset: 0x16c
        u32 mBreakUID;  // offset: 0x170
        f32 mBadRadius;  // offset: 0x174
        f32 mBadHeight;  // offset: 0x178
        MtVector3 mBadPos;  // offset: 0x180
        u32 mBreakHitNum;  // offset: 0x190
        u32 mDropId;  // offset: 0x194
        u32 mPLCount;  // offset: 0x198
        f32 mFallHeight;  // offset: 0x19c
        u32 mTextNo;  // offset: 0x1a0
        u32 mTextQuestNo;  // offset: 0x1a4
        u32 mTextType;  // offset: 0x1a8
        bool mbReqLever;  // offset: 0x1ac
        s32 mLeverCamEvNo;  // offset: 0x1b0
        cResPath<rAIFSM> mFSMCamEv;  // offset: 0x1b8
        u32 mListStat;  // offset: 0x1c0
        u32 mBoardID;  // offset: 0x1c4
        u32 mHeight;  // offset: 0x1c8
        u32 mKeyItemNo;  // offset: 0x1cc
        u32 mWallType;  // offset: 0x1d0
        MtOBB mNavOBB;  // offset: 0x1e0
        MtVector3 mNavOBBExtent;  // offset: 0x230
        u32 mStoneLevel;  // offset: 0x240
        bool mbWaitBowlOfLife;  // offset: 0x244
        bool mbFullBowlOfLife;  // offset: 0x245
        bool mbSetEM;  // offset: 0x246
        bool mbInvisible;  // offset: 0x247
        u32 mHealType;  // offset: 0x248
        bool mbNoSbc;  // offset: 0x24c
        bool mbMyQuest;  // offset: 0x24d
        MtVector3 mWarpPos[4];  // offset: 0x250
        static MyDTI DTI;
        static const u32 MAX_UNIT_NUM = 4;
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
    cOmControl();
    virtual ~cOmControl();
    void move();
    bool isEnableCtrl() const;
    void reqKillCtrl();
    bool waitKillCtrl();
    void initLot();
    MtVector3 getWorldPos() const;
    void moveArc(bool isIns);
    void reqLoadOmArc(f32 len, bool bOmIns);
    void releaseOmArc();
    bool isDisableTimeSplit();
    void moveTimeSplit();
    uBaseModel* getUnit() const;
    void createUnit();
    void killUnit();
    void reqkillUnit();
    f32 getKillLength();
    f32 getLoadLength();
    void createInsUnit();
    void killInsUnit();
    void reqkillInsUnit();
    void initSbc();
    void eraseSbc();
private:
    void moveSbc();
public:
    bool hasSBC();
    void updateSbc(MtMatrix& mtx);
    void setActiveSbc(bool act, u32 type, u32 index, u32 parts);
    void setActiveScrSbc(bool act);
    void setActiveEfcSbc(bool act);
    void setActiveAllSbc(bool act);
    void setActiveAllSbcParts(bool act);
    sCollision::SBC_HANDLE getSbcHandleScr();
    sCollision::SBC_HANDLE getSbcHandleEfc();
    const cOmParam* getOmParam() const;
    u32 getOmID() const;
    uintptr getOmUID() const;
    u32 getCtrlState();
    void setCtrlState(u32 v);
    void moveCtrl();
    void moveCtrlEmKill();
    void moveCtrlNext(cOmControl* ph);
    void moveLink();
    bool isReceive() const;
    void setReceive(bool NewValue);
    bool isUseItem() const;
    void setUseItem(bool NewValue);
    bool isWarpReq() const;
    void setWarpReq(bool NewValue);
    bool isWarpOK() const;
    void setWarpOK(bool NewValue);
    void sendPacket(InsValue packet);
    void exchangePacket(InsValue packet);
    cGatherItemList* getGatherItemList();
    u32 getItemGetInfoNum();
    ItemGetInfo* getItemGetInfo(u32 idx);
    void setGatherUseItemBreak(bool isBreak);
    bool isGatherUseItemBreak();
    cpOmGather* getcpOmGather();
    void moveMapIcon();
    void initZone();
    void eraseZone();
    bool isNoZone(bool isLoad);
    bool isNoZonePL(bool isLoad);
public:
    u32 mRnoState;  // offset: 0x8
    u32 mCtrlType;  // offset: 0xc
    u32 mCtrlRno;  // offset: 0x10
    bool mIsQuest;  // offset: 0x14
    u32 mQuestNo;  // offset: 0x18
    s32 mStageNo;  // offset: 0x1c
    bool mbEnableArc;  // offset: 0x20
    bool mbMoveArc;  // offset: 0x21
    f32 mLoadLen;  // offset: 0x24
    bool mbDisableTimeSplit;  // offset: 0x28
    u32 mRnoTS;  // offset: 0x2c
    uBaseModel* mpuModel;  // offset: 0x30
    uOmSimple* mpuModel2;  // offset: 0x38
    uSoundGenerator* mpuSndGen;  // offset: 0x40
    bool mbOmIns;  // offset: 0x48
    bool mbTree;  // offset: 0x49
    bool mbOmInsAdd;  // offset: 0x4a
    res_ptr<rCollision> mprSbc[2][2];  // offset: 0x50
    sCollision::SBC_HANDLE mhSbc[2][2];  // offset: 0x70
    bool mbEnableSBC;  // offset: 0x80
    bool mbDirty;  // offset: 0x81
    u32 mDirtyCount;  // offset: 0x84
    s32 mOmID;  // offset: 0x88
    const cOmParam* mpOmParam;  // offset: 0x90
    bool mbHasCtrl;  // offset: 0x98
    u32 mCtrlState;  // offset: 0x9c
    bool mbHasLink;  // offset: 0xa0
private:
    CommunicateData mCommunicateData;  // offset: 0xa1
public:
    InsValue mPacket;  // offset: 0xa8
    u32 mRnoIns;  // offset: 0xac
    bool mbSaveInsSync;  // offset: 0xb0
    cOmControl* mpCtrlBreak;  // offset: 0xb8
    bool mbBreak;  // offset: 0xc0
    bool mbCalledItemBreak;  // offset: 0xc1
    bool mbItemBreak;  // offset: 0xc2
    bool mbItemUsed;  // offset: 0xc3
    bool mbMapNone;  // offset: 0xc4
    bool mbBeacon;  // offset: 0xc5
    u32 mbBeaconTime;  // offset: 0xc8
    s32 mMapIcon;  // offset: 0xcc
    InputLot mLot;  // offset: 0xd0
    cZoneUnitCtrl mZoneUnitCtrl;  // offset: 0x360
    cZoneIndoorHandle mhZone;  // offset: 0x380
    s8 mFloorGroupNo;  // offset: 0x394
    static MyDTI DTI;
    static MtCriticalSection mCS;
    static const u32 InvalidOmID = 0;
};
