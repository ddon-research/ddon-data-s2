#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cArcLoader.h"
#include "cOmControl.h"
#include "rCollision.h"
#include "rEventParam.h"
#include "rObjCollision.h"
#include "rSoundRequest.h"
#include "res_ptr.h"
#include "sCollision.h"
#include "sUnitManager.h"
#include "uOmInstancing.h"

// Forward declarations
class CDataOmData;
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtQuaternion;
class MtSphere;
class MtVector3;
class cOmControl;
class cOmParam;
class cOmTreeControl;
namespace nQuest { class QUEST_ID; }
class rArchive;
class rCollision;
class rGatheringItem;
class rObjCollision;
class rOmKey;
class rOmLoadList;
class rOmParam;
class rRenderTargetTexture;
class rShlParamList;
class rSoundRequest;
class uBaseModel;
class uCharacter;
class uDDOModel;
class uOmShell;
class uOmSwingInstancing;
class uScreenSpace;

// Declarations
class sOmManager;

// Type aliases from DWARF
using COmData = CDataOmData;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using cArcLoader01 = cArcLoader<1>;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sOmManager : public sUnitManager
{
public:
    enum
    {
        WARP_TYPE_NONE = 0,
        WARP_TYPE_OM = 1,
        WARP_TYPE_SCE = 2,
    };
public:
    class MyDTI;
    class cOmArcLoader;
    struct InstanceAreaGuardITData;
    class cWarpData;
    class cClanEmblemTextureCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cOmArcLoader : public MtObject
    {
    public:
        enum
        {
            LOAD_PRIO_SYS = 0,
            LOAD_PRIO_DEF = 1,
            LOAD_PRIO_LOW = 10,
        };
        enum
        {
            RNO_NONE = 0,
            RNO_INIT = 1,
            RNO_MOVE = 2,
            RNO_ARC_ENABLE = 3,
            RNO_FAILED = 4,
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
        cOmArcLoader();
        virtual ~cOmArcLoader();
        void move();
        static bool sortFunc(const sOmManager::cOmArcLoader* pa, const sOmManager::cOmArcLoader* pb, u32);
        void reqLoad(s32 omID, f32 len, u32 prio);
        bool isEnableArc() const;
        bool isFailed() const;
        void releaseArc();
        s32 getRefCnt() const;
        void addRefCnt();
        void decRefCnt();
    public:
        s32 mOmID;  // offset: 0x8
        cArcLoader01 mArc;  // offset: 0x10
        f32 mLoadLength;  // offset: 0x50
        u32 mLoadPrio;  // offset: 0x54
        u8 mRnoArc;  // offset: 0x58
        s32 mRefCnt;  // offset: 0x5c
        static MyDTI DTI;
    };
public:
    struct InstanceAreaGuardITData
    {
    public:
        u32 mInsSyncNum;  // offset: 0x0
        u32 mInsSyncUID[2048];  // offset: 0x4
    };
public:
    class cWarpData : public MtObject
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
        cWarpData();
        // Address: 0x01ac8930 - 0x01ac8931 (1 bytes)
        virtual ~cWarpData() {}
    public:
        u16 mType;  // offset: 0x8
        s16 mNextStageNo;  // offset: 0xa
        s16 mNextStartPos;  // offset: 0xc
        MtObject* mpOwner;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cClanEmblemTextureCtrl : public MtObject
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
        cClanEmblemTextureCtrl();
        virtual ~cClanEmblemTextureCtrl();
        void init();
        void setup();
        bool loadRenderTargetTexture();
        bool createScreenSpace();
        bool linkRttToScreenSpace();
        void release();
    private:
        rRenderTargetTexture* mpRenderTargetTexture;  // offset: 0x8
        uScreenSpace* mpScreenSpace;  // offset: 0x10
    public:
        static MyDTI DTI;
        static const MT_CTSTR CLAN_EMBLEM_RTT_FILEPATH;
        static const u32 CLAN_EMBLEM_TEXTURE_SIZE;
        static const u32 CLAN_EMBLEM_RENDER_TARGET_VIEW;
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
private:
    void releaseOmArcLoader(s32 omID, u32 thisID);
    bool addOmArcLoader(s32 omID, u32 thisID, f32 len, u32 prio, bool bOmIns);
    s32 findLoader(s32 omID);
public:
    bool isEnableArc(s32 omID);
    void addOmArcLoaderLock(s32 omID, u32 thisID, f32 len, u32 prio, bool bOmIns);
    void releaseOmArcLoaderLock(s32 omID, u32 thisID);
    void moveOmArcLoader();
    void releaseOmArcLoaderAll();
    u32 getArcLoaderNum() const;
    void setArcLoaderNum(u32);
    u32 getEnableArcNum() const;
    void setEnableArcNum(u32);
    cOmControl* createOmCtrl(s32 omID, bool isQuest, u32 questNo, s32 stageNo);
    void releaseOmCtrl(cOmControl* pctrl);
    cOmControl* getOmCtrl(u32 uniqueId);
    cOmControl* getOmCtrlFromIndex(u32 index);
    void getOmCtrlGrp(cOmControl* * pout, u32& out_num, u32 group);
    u32 getOmCtrlNum();
    void setOmCtrlNum(u32);
    static bool sortControl(const cOmControl* pa, const cOmControl* pb, u32);
    void moveControl();
    void linkControl(cOmControl* pctrl);
    void moveLink();
    void linkLink(cOmControl* pctrl);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    cOmControl* createOmInsCtrl(s32 omID);
    void releaseOmInsCtrl(cOmControl* pctrl);
    uOmSwingInstancing* getOmInsUnit(s32 omID);
    uOmSwingInstancing* createOmInsUnit(s32 omID);
    void deleteOmInsUnit(uOmSwingInstancing* puins);
    void setOmInsCtrlNum(u32);
    void setOmInsUnitNum(u32);
    void setOmInsNum(u32);
    cOmTreeControl* createTreeInsCtrl(s32 omID);
    void releaseTreeInsCtrl(cOmTreeControl* pctrl);
    uOmSwingInstancing* getTreeInsUnit(s32 omID);
    uOmSwingInstancing* createTreeInsUnit(s32 omID);
    void deleteTreeInsUnit(uOmSwingInstancing* puins);
    void setTreeInsCtrlNum(u32);
    void setTreeInsUnitNum(u32);
    void setTreeInsNum(u32);
    bool isCreatableUnit();
    void fadeIn(f32 frame);
    void moveBell();
    bool isDoor(u32 uniqueId);
    bool isCanOpenDoor(u32 uniqueId);
    bool isKeyDoor(u32 uniqueId);
    bool isCloseDoor(u32 uniqueId);
    bool isCloseBlock(u32 uniqueId);
    bool isOpenEndDoor(u32 uniqueId);
    bool isOpenEndDoorHalf(u32 uniqueId);
    bool isOnMyPLElfSW(u32 uniqueId);
    bool isOpenedElfSW(u32 uniqueId);
    bool isBreakable(u32 uniqueId);
    bool isInside(u32 uniqueId);
    bool isPullLever(u32 uniqueID);
    bool isUseItem(u32 uniqueID);
    void setOpenDoor(u32 uniqueId);
    bool isOpenRoad(u32 uniqueID);
    u32 getLadderHeight(u32 uniqueID);
    sCollision::SBC_HANDLE getSBCHandle(u32 uniqueId, u32 type, u32 index);
    bool isInsideGrp(u32 group, const MtSphere& sh, bool isall);
    bool isInAtkOm(const MtVector3& realPos, f32 length);
    u32 getAtkOmPosNum();
    const MtVector3& getAtkOmPosNum(u32 index);
    void moveAtkOmPos();
    cOmControl* getTarasuk();
    void setTarasukSBCPartsOff(cOmControl* pctrl);
    void setSBC(cOmControl* pctrl, bool sbc_on);
    void setSBCPosAngle(cOmControl* pctrl, MtVector3& sbc_pos, MtVector3& sbc_angle);
    void setSBCPosQuat(cOmControl* pctrl, MtVector3& sbc_pos, MtQuaternion& sbc_quat);
    bool getActiveSBC(cOmControl* pctrl, u32 partsNo);
    void setMoveFloor(u32 type);
    void resetMoveFloor();
    bool isMoveFloorNow();
    void moveMoveFloorNow();
    MtVector3 getOmRealPos(u32 index);
    u32 getOmMapIcon(u32 index);
    bool isClosedByCtrl(cOmControl* pctrl);
    bool isCtrled(uCharacter* puc);
    bool isCtrled(cOmControl* pctrl);
    s32 isCtrledEM(uCharacter* puc);
    void getOmMapErase(u32 index, MtVector3& out_pos, MtVector3& out_rot, MtVector3& out_scale);
    void getOmBadStatus(u32 index, MtVector3& out_pos, f32& out_radius, f32& out_height);
    void callBackUseItemReq(void* param);
    u32 getGatherGrp(cOmControl* pctrl);
    void loadNyoro();
    void releaseNyoro();
    bool addBad(u32 omID, s32& pitch);
    void deleteBad(u32 omID);
    void startCutscene(const MtTypedArray<cEventParam::cOmList>* pomlist);
    void endCutscene();
    void moveCutscene();
    bool isLoadEndCutscene();
    void callBackInsSync(const COmData& data);
    void callBackInsSyncExchange(const COmData& data, u32 valOld);
    void callBackInsSyncAll(const MtTypedArray<CDataOmData>& omlist);
    void moveInsSync();
    u32 getInsSyncNum() const;
    void setInsSyncNum(u32 NewValue);
    u32 getInsSyncUID(u32 index) const;
    void setInsSyncUID(u32 NewValue, u32 index);
    bool isDoneGimmick(u32 in_uid);
    virtual uBaseModel* getLayoutUnit(u32 uniqueId);  // vtable slot 15
    u32 getUnitNum();
    void setUnitNum(u32);
    void setEventAQCScale(f32 v);
    void setDefaultAQCScale();
    void initAQC();
    void finalAQC();
    void moveAQC();
    void setUnitGroup(bool flag, s32 omNo, u32 setGroup);
    void setUnitGroup(bool flag, uBaseModel* pMdl, u32 setGroup);
    void setOMPResource(rOmParam* pr);
    rOmParam* getOMPResource();
    void setOMKResource(rOmKey* pr);
    rOmKey* getOMKResource();
    void getKeyTypeColor(s32 omID, u32 keyNo, u32& out_type, u32& out_color, MtVector3& out_ofs);
    void loadCommonRes();
    void releasCommonRes();
    cOmParam* findOmParam(s32 omID);
    bool hasFxLight(s32 omID);
    void setSHLResource(rShlParamList* pr);
    rShlParamList* getSHLResource();
    sOmManager();
    virtual ~sOmManager();
    virtual void init();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void clear();  // vtable slot 11
    virtual void move();  // vtable slot 7
    void releaseAllOmCtrlDirect();
    void moveParallel(uintptr interlockAddr);
    void startStageInit();
    bool isStageInitOK();
    u32 getGatheringItem(u32 type, u32* buff, u32 buff_size);
    bool isQuestFlag(cOmControl* pctrl, u32 flagNo) const;
    bool isQuestFlag(cOmControl* pctrl, u32 flagNo, nQuest::QUEST_ID questId) const;
    f32 getDiffuseTime() const;
    f32 getDiffuseIntensityMax() const;
    f32 getDiffuseIntensityMin() const;
    void initShell();
    void moveShell();
    void finalShell();
    void setShell(const MtVector3& pos, uDDOModel* pudmg);
    void add603000(cOmControl* pctrl);
    void remove603000(cOmControl* pctrl);
    MtVector3 getPos603000();
    cOmControl* get603000();
    void setOmCtrlFreq(u32 frame);
    void resetOmCtrlFreq();
    void initWarpList();
    void releaseWarpList();
    f32 getWarpDist(cWarpData* data, MtVector3& pos);
    void addWarpList(MtObject* owner);
    void deleteWarpList(MtObject* owner);
    void moveWarpList();
    void addWarpArcLoader(s32 stageNo, s32 startPos);
    void addWarpArcLoaderSub(u32 omID);
    void decWarpArcLoader();
    void eraseWarpArcLoader();
    static sOmManager* getInstance();
public:
    MtTypedArray<cOmArcLoader> mArcLoader;  // offset: 0xa0
    bool mbSortLoader;  // offset: 0xc0
    bool mbTimeSplit;  // offset: 0xc1
    MtTypedArray<cOmControl> mRefOmCtrlArray;  // offset: 0xc8
    MtTypedArray<cOmControl> mAddOmCtrlArray;  // offset: 0xe8
    MtTypedArray<cOmControl> mDelOmCtrlArray;  // offset: 0x108
    MtTypedArray<cOmControl> mFastOmCtrlArray;  // offset: 0x128
    bool mbDeleteAll;  // offset: 0x148
    u32 mOmCtrlCnt;  // offset: 0x14c
    u32 mOmCtrlFreq;  // offset: 0x150
    bool mbPLStopEnable;  // offset: 0x154
    bool mbPLStop;  // offset: 0x155
    f32 mPLStopLen;  // offset: 0x158
    f32 mPLNoZoneLen;  // offset: 0x15c
    u32 mOmInsCnt;  // offset: 0x160
    u32 mOmInsFreq;  // offset: 0x164
    MtTypedArray<cOmControl> mOmIns;  // offset: 0x168
    MtTypedArray<cOmControl> mDelOmIns;  // offset: 0x188
    MtTypedArray<uOmSwingInstancing> mpuOmIns;  // offset: 0x1a8
    u32 mTreeInsCnt;  // offset: 0x1c8
    u32 mTreeInsFreq;  // offset: 0x1cc
    MtTypedArray<cOmTreeControl> mTreeIns;  // offset: 0x1d0
    MtTypedArray<uOmSwingInstancing> mpuTreeIns;  // offset: 0x1f0
    f32 mFadeFrame;  // offset: 0x210
    u32 mRnoFade;  // offset: 0x214
    f32 mBellTimer;  // offset: 0x218
    bool mbBell;  // offset: 0x21c
    u32 mAtkOmPosNum;  // offset: 0x220
    MtVector3 mAtkOmPos[128];  // offset: 0x230
    bool mbMoveFloor[3];  // offset: 0xa30
    bool mbMoveFloorReset;  // offset: 0xa33
    bool mbMoveFloorNow;  // offset: 0xa34
    cArcLoader01 mArcNyoro;  // offset: 0xa38
    bool mbLoadNyoro;  // offset: 0xa78
    u32 mBadNum;  // offset: 0xa7c
    u32 mBadOmID[5];  // offset: 0xa80
    bool mbCutscene;  // offset: 0xa94
    u32 mCutsceneLoadFrame;  // offset: 0xa98
    s32 mCutsceneLoadOMID[64];  // offset: 0xa9c
    u32 mCutsceneLoadOMIDNum;  // offset: 0xb9c
    s32 mCutsceneMoveOMID[64];  // offset: 0xba0
    u32 mCutsceneMoveOMIDNum;  // offset: 0xca0
    const MtTypedArray<cEventParam::cOmList>* mpCutSceneOmList;  // offset: 0xca8
private:
    InstanceAreaGuardITData mInstanceAreaData;  // offset: 0xcb0
public:
    u32 mInsSyncVal[2048];  // offset: 0x2cb4
    bool mbEnableUnitKill;  // offset: 0x4cb4
    f32 mLoadLength;  // offset: 0x4cb8
    f32 mAQCKillLength;  // offset: 0x4cbc
    f32 mAQCScale;  // offset: 0x4cc0
    f32 mAQCLODScale;  // offset: 0x4cc4
    bool mbAQCtrl;  // offset: 0x4cc8
    f32 mOMDispLimitLength;  // offset: 0x4ccc
    f32 mOMDispLength;  // offset: 0x4cd0
    f32 mGrassDispLength;  // offset: 0x4cd4
    f32 mInsDispLimitLength;  // offset: 0x4cd8
    f32 mInsDispLength;  // offset: 0x4cdc
    bool mbSaveAQCScale;  // offset: 0x4ce0
    f32 mSaveAQCScale;  // offset: 0x4ce4
    u32 mCameraFrame;  // offset: 0x4ce8
    f32 mCameraYawDiff;  // offset: 0x4cec
    f32 mCameraYawDiffMin;  // offset: 0x4cf0
    f32 mCameraYawDiffMax;  // offset: 0x4cf4
    f32 mCameraYawPer;  // offset: 0x4cf8
    MtVector3 mCameraYaw[2];  // offset: 0x4d00
    f32 mInsLODDist[3];  // offset: 0x4d20
    f32 mInsLODDistPan[3];  // offset: 0x4d2c
    bool mbBaseArea;  // offset: 0x4d38
    rOmParam* mprOmParam;  // offset: 0x4d40
    rArchive* mprGameCommon;  // offset: 0x4d48
    rOmKey* mprOmKey;  // offset: 0x4d50
    res_ptr<rCollision> mprSbc[4];  // offset: 0x4d58
    sCollision::SBC_HANDLE mhSbc[4];  // offset: 0x4d78
    res_ptr<rSoundRequest> mprSRQR;  // offset: 0x4d88
    res_ptr<rSoundRequest> mprPRT;  // offset: 0x4d90
    res_ptr<rObjCollision> mprPRTCol;  // offset: 0x4d98
    rGatheringItem* mprGatheringItem;  // offset: 0x4da0
    rShlParamList* mprShlParamList;  // offset: 0x4da8
    u32 mMoveType;  // offset: 0x4db0
    u32 mLoadFrame;  // offset: 0x4db4
    u32 mDelayCount;  // offset: 0x4db8
    bool mbLoadArc;  // offset: 0x4dbc
    bool mbLoadStart;  // offset: 0x4dbd
    bool mbLoadEnd;  // offset: 0x4dbe
    bool mbLoadStop;  // offset: 0x4dbf
    f32 mDiffuseTime;  // offset: 0x4dc0
    f32 mDiffuseIntensityMax;  // offset: 0x4dc4
    f32 mDiffuseIntensityMin;  // offset: 0x4dc8
    MtHermiteCurve mAxisY;  // offset: 0x4dcc
    MtHermiteCurve mRoll;  // offset: 0x4e0c
    MtHermiteCurve mAxisZ;  // offset: 0x4e4c
    f32 mAxisYScale;  // offset: 0x4e8c
    f32 mRollScale;  // offset: 0x4e90
    f32 mAxisZScale;  // offset: 0x4e94
    f32 mAxisZRndScale;  // offset: 0x4e98
    f32 mDelayTimeScale;  // offset: 0x4e9c
    u32 mHitShellNum;  // offset: 0x4ea0
    uOmShell* mpuShell[64];  // offset: 0x4ea8
    u32 m60300Num;  // offset: 0x50a8
    cOmControl* mpCtrl603000[4];  // offset: 0x50b0
    MtVector3 mTorque;  // offset: 0x50d0
    f32 mTorqueTime;  // offset: 0x50e0
    MtTypedArray<cWarpData> mWarpList;  // offset: 0x50e8
    cWarpData* mpWarpNearest;  // offset: 0x5108
    MtTypedArray<cOmArcLoader> mWarpArcLoader;  // offset: 0x5110
    rOmLoadList* mpOmLoadList;  // offset: 0x5130
    cClanEmblemTextureCtrl mCETC;  // offset: 0x5138
    static MyDTI DTI;
    static const u32 ATK_OM_POS_MAX = 128;
    static const u32 BadMax = 5;
    static const u32 InsSyncMax = 2048;
    static const u32 CAM_FRAME_MAX = 2;
    static const u32 WALL_SBC_NUM = 4;
    static const u32 ShellMax = 64;
    static const u32 OM603000Max = 4;
private:
    static sOmManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 sOmManager::getDiffuseTime() const {
    return this->mDiffuseTime;
}

// Inline, no code of its own: checked where it is inlined.
inline sOmManager* sOmManager::getInstance() {
    return ::sOmManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sOmManager::cWarpData::cWarpData() {
    this->mType = static_cast<u16>(0);
    this->mNextStageNo = static_cast<s16>(-1);
    this->mNextStartPos = static_cast<s16>(0);
    this->mpOwner = static_cast<MtObject*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline sOmManager::cClanEmblemTextureCtrl::cClanEmblemTextureCtrl() {
    this->mpScreenSpace = static_cast<uScreenSpace*>(nullptr);
    this->mpRenderTargetTexture = static_cast<rRenderTargetTexture*>(nullptr);
}
