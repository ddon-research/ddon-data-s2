#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtSynchronize.h"
#include "cOmControl.h"
#include "cSplitBase.h"
#include "cStageEpvCtrl.h"
#include "cUnit.h"
#include "cZoneIndoorHandle.h"
#include "nStage.h"
#include "nZoneUnitCtrl.h"
#include "rStageJoint.h"
#include "sCollision.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtVector3;
class cArcLoaderBase;
class cDraw;
class cOmTreeControl;
class cSplitArc;
class cSplitBgm;
class cSplitLot;
class cStageEpvCtrl;
class cZoneIndoorHandle;
class rNavigationMesh;
class rPlantTree;
class rScheduler;
class rSoundAreaInfo;
class rStageJoint;
class rZone;
struct stStageSplitData;
class uGrassReceiver;
class uScheduler;
class uScrollCollisionGeometry;
class uSoundGenerator;
class uSoundOcclusion;
class uSoundTrigger;

// Declarations
class uStageJointCtrl;
class uStageJointMdl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using s32 = int;
using size_t = _Sizet;
using u64 = __uint64_t;
using u8 = unsigned char;

class uStageJointMdl : public uCoord
{
public:
    enum
    {
        SBC_STATUS_NONE = 0,
        SBC_STATUS_LOADING = 1,
        SBC_STATUS_COMPLETE = 2,
        SBC_STATUS_NO_SBC = 3,
        SBC_STATUS_MAX_NO = 4,
    };
public:
    class MyDTI;
    struct TileCoordAndDirection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TileCoordAndDirection
    {
    public:
        enum
        {
            Z_MINUS_ONE = 1,
            Z_PLUS_ONE = 2,
            X_MINUS_ONE = 4,
            X_PLUS_ONE = 8,
        };
    public:
        TileCoordAndDirection(u32 in_z, u32 in_x, u32 in_playerAreaDirection);
    public:
        u32 z;  // offset: 0x0
        u32 x;  // offset: 0x4
        u32 playerAreaDirection;  // offset: 0x8
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
    uStageJointMdl();
    uStageJointMdl(uStageJointCtrl* parent, s32 areaNo, const rStageJoint::Info* areaInfo);
    void initializeVariables();
    virtual ~uStageJointMdl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    s32 getAreaNo() const;
    void loadResource();
    void setResource();
    bool isSetResource();
    bool isSetTree();
    sCollision::SBC_HANDLE getSbcHandleScr(u32 idx);
    sCollision::SBC_HANDLE getSbcHandleEff(u32 idx);
    uScheduler* getLightSdl() const;
    rSoundAreaInfo* getSoundAreaInfo();
    void setSoundTrigger(rZone* pZone, const MtVector3& pos);
    void setSoundGenerator(rZone* pZone, const MtVector3& pos);
    void setSoundOcclusion(rZone* pZone, const MtVector3& pos);
    uSoundOcclusion* getSoundOcclusion();
    void updateGrassReceiver();
    bool isPersistentArea() const;
protected:
    bool isResourceUsage();
    u32 getSbcStatus() const;
    void setSbcStatus(u32 st);
    void movePlantTree();
    bool initPlantTree(rPlantTree* pRes);
    void releaseInstancing();
    void reserveSbcReposition();
    void finishSbcReposition();
private:
    const rStageJoint::Info* mpInfo;  // offset: 0x110
    rScheduler* mpMdlRsrc;  // offset: 0x118
    uScheduler* mpMdlSchdl;  // offset: 0x120
    rScheduler* mpLightSdlRsrc;  // offset: 0x128
    uScheduler* mpLightSchdl;  // offset: 0x130
    rPlantTree* mpPlantTree;  // offset: 0x138
    sCollision::SBC_HANDLE mScrSbcHandle[3];  // offset: 0x140
    sCollision::SBC_HANDLE mEffSbcHandle[3];  // offset: 0x14c
    s32 mAreaNo;  // offset: 0x158
    TICKET mArcTicket;  // offset: 0x160
    bool mIsSetResource;  // offset: 0x168
    bool mIsSetTree;  // offset: 0x169
    u8 mTreeRno;  // offset: 0x16a
    u32 mSbcStatus;  // offset: 0x16c
    uStageJointCtrl* mpParent;  // offset: 0x170
    MtTypedArray<cOmTreeControl> mOmCtrl;  // offset: 0x178
    cStageEpvCtrl mStageEpvCtrl;  // offset: 0x1a0
    rSoundAreaInfo* mpSoundAreaInfo;  // offset: 0x250
    uSoundTrigger* mpSoundTrigger;  // offset: 0x258
    uSoundGenerator* mpSoundGenerator;  // offset: 0x260
    uSoundOcclusion* mpSoundOcclusion;  // offset: 0x268
    rZone* mpEfcColorZone;  // offset: 0x270
    rZone* mpEfcCtrlZone;  // offset: 0x278
    u32 mEfcColorHandle;  // offset: 0x280
    u32 mEfcCtrlHandle;  // offset: 0x284
    cZoneIndoorHandle mIndoorZoneHandle;  // offset: 0x288
    u32 mLightAndFogZoneHandle;  // offset: 0x29c
    u32 mZoneUnitCtrlHandle[3];  // offset: 0x2a0
    u32 mZoneStatusHandle;  // offset: 0x2ac
    u32 mGrassReceiverTime;  // offset: 0x2b0
    uGrassReceiver* mpGrassReceiver;  // offset: 0x2b8
    MtArray mSceArray;  // offset: 0x2c0
    uScrollCollisionGeometry* mpSbcGeometry;  // offset: 0x2e0
public:
    static MyDTI DTI;
};

class uStageJointCtrl : public cUnit
{
public:
    enum
    {
        SPLIT_NUM_X = 3,
        SPLIT_NUM_Z = 3,
        SPLIT_NUM = 9,
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
    uStageJointCtrl();
    virtual ~uStageJointCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setResource(s32 stageNo);
    uStageJointMdl* getPersistentMdl() const;
    void setPersistentMdl(uStageJointMdl*);
    s32 getPlayerCurrentAreaNo() const;
    s32 getNowX() const;
    s32 getNowZ() const;
    MT_CTSTR getMdlSdlPath(s32 areaNo);
    MT_CTSTR getScrSbcPath(s32 areaNo, u32 idx);
    MT_CTSTR getEffSbcPath(s32 areaNo, u32 idx);
    MT_CTSTR getLightSdlPath(s32 areaNo);
    MT_CTSTR getPlantTreePath(s32 areaNo);
    MT_CTSTR getEpvPath(s32 areaNo);
    MT_CTSTR getSndInfoPath(s32 areaNo);
    u64 getEfcColorZone(s32 areaNo) const;
    u64 getEfcCtrlZone(s32 areaNo) const;
    u64 getIndoorZoneScr(s32 areaNo) const;
    u64 getIndoorZoneEfc(s32 areaNo) const;
    u64 getLightAndFogZone(s32 areaNo) const;
    u64 getZoneUnitCtrl(s32 areaNo, ZONE_UNIT_CTRL_TYPE type) const;
    u64 getZoneStatus(s32 areaNo) const;
    bool calcJointArea(const MtVector3& pos, s32& outX, s32& outZ);
    u32 getArcTag(s32 areaNo);
    bool isSetup();
    void sbcSetMatrix();
    bool isSbc(s32 x, s32 z);
    bool isSbc(s32 areaNo);
    cSplitBgm* getSplitBgmInfo();
    cSplitBgm* getSplitBgmInfo(const MtVector3& targetPos);
    rStageJoint* getJointArea() const;
    const stStageSplitData* getSplitData();
    u32 getSplitNumX() const;
    u32 getSplitNumZ() const;
    f32 getSplitLengthX() const;
    f32 getSplitLengthZ() const;
    f32 getSplitStartPosX() const;
    f32 getSplitStartPosZ() const;
    void setBlockArcLoad(s32 stageNo, MtVector3& plPos);
    bool isBlockArcLoadOk();
    s32 getInsideAreaNo(MtVector3& realPos);
    uSoundOcclusion* getSoundOcclusion();
    void stopMoveUnitLight(bool sleep);
    void releaseAllMdlInstancing();
protected:
    void updateXZ();
    bool createStageMdl(const MtVector3& pos, bool isBlocking);
    void removeJointMdlsOutsideLoadedArea(const MtStlVector<int, MtStlAllocator<int> >& loadedAreas);
    void addJointMdlsInsideLoadedArea(const MtStlVector<int, MtStlAllocator<int> >& loadedAreas, bool isBlocking);
    void updateStageMdl(bool isBlocking, bool update);
    void updateNaviMesh(bool isBlocking, bool update);
    void updatePlayerCurrentArea();
    MtStlVector<int, MtStlAllocator<int> > getJointAreaList(s32 areaX, s32 areaZ);
private:
    bool isSplitLot(s32 x, s32 z);
    s32 getSplitLotStatus(s32 x, s32 z);
    cSplitLot* getSplitLot(s32 x, s32 z);
    MtVector3 getMyPlayerPos();
    bool checkPlayerRange(s32 x, s32 z);
    bool checkPlayerRangePos(s32 x, s32 z, MtVector3& pos) const;
    void calcEnableSplitAreaRange(s32 areaX, s32 areaZ, s32& xmin, s32& xmax, s32& zmin, s32& zmax) const;
    bool updateLot(bool isBlocking, bool update);
    void setLotResource();
    bool isSetResourceSplitLot(s32 x, s32 z, bool update);
    bool updateArc(bool isBlocking, bool update);
    bool isBlockArcLoadOk(s32 x, s32 z);
private:
    s32 mPlayerCurrentAreaNo;  // offset: 0x48
    s32 mNowX;  // offset: 0x4c
    s32 mNowZ;  // offset: 0x50
    s32 mOldX;  // offset: 0x54
    s32 mOldZ;  // offset: 0x58
    bool mIsSetup;  // offset: 0x5c
    MtTypedArray<uStageJointMdl> mJointMdlAry;  // offset: 0x60
    uStageJointMdl* mpPersistentMdl;  // offset: 0x80
    rStageJoint* mpJointArea;  // offset: 0x88
    s32 mNaviMeshArea;  // offset: 0x90
    rNavigationMesh* mpNaviMesh;  // offset: 0x98
    stStageSplitData mSplitData;  // offset: 0xa0
    MtTypedArray<cSplitLot> mSplitLotAry;  // offset: 0xb8
    MtTypedArray<cSplitArc> mSplitArcAry;  // offset: 0xd8
    MtCriticalSection mCS;  // offset: 0xf8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline s32 uStageJointCtrl::getPlayerCurrentAreaNo() const {
    return this->mPlayerCurrentAreaNo;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline uScheduler* uStageJointMdl::getLightSdl() const {
    return this->mpLightSchdl;
}
