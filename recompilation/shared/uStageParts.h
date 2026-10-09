#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtSynchronize.h"
#include "cPartsGroupList.h"
#include "cSplitBase.h"
#include "cStageEpvCtrl.h"
#include "cUnit.h"
#include "cZoneIndoorHandle.h"
#include "nZoneUnitCtrl.h"
#include "rStageCustomParts.h"
#include "rStageCustomPartsEx.h"
#include "sCollision.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtVector3;
class cAISvNavPathFinding;
class cArcLoaderBase;
class cDraw;
class cPartsGroupList;
class cSplitArc;
class cSplitBgm;
class cSplitLot;
class cStageEpvCtrl;
class cZoneIndoorHandle;
class rNavigationMesh;
class rOccluderEx;
class rScheduler;
class rSoundAreaInfo;
class rStageCustom;
class rZone;
class uGrassReceiver;
class uScheduler;
class uScrollCollisionGeometry;
class uSoundGenerator;
class uSoundOcclusion;
class uSoundTrigger;

// Declarations
class uStagePartsCtrl;
class uStagePartsMdl;

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

class uStagePartsMdl : public uCoord
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
    uStagePartsMdl(uStagePartsCtrl* parent, s32 index, s32 areaNo, bool isBlocking);
    virtual ~uStagePartsMdl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    s32 getAreaIdx() const;
    s32 getAreaNo() const;
    void loadResource();
    void setResource();
    bool isSetResource();
    uScheduler* getLightSdl() const;
    rSoundAreaInfo* getSoundAreaInfo();
    rNavigationMesh* getNaviMesh();
    s32 getNaviMeshHandle() const;
    void setSoundTrigger(rZone* pZone, const MtVector3& pos);
    void setSoundGenerator(rZone* pZone, const MtVector3& pos);
    void setSoundOcclusion(rZone* pZone, const MtVector3& pos);
    uSoundOcclusion* getSoundOcclusion();
    void updateGrassReceiver();
protected:
    bool isResourceUsage();
    bool isCollisionUsage();
    void setCollisionType();
private:
    void setNavigationMesh();
    void releaseNavigationMesh();
private:
    rScheduler* mpSdlRsrc;  // offset: 0x110
    uScheduler* mpScrSchdl;  // offset: 0x118
    rScheduler* mpLightSdlRsrc;  // offset: 0x120
    uScheduler* mpLightSchdl;  // offset: 0x128
    sCollision::SBC_HANDLE mScrSbcHandle[3];  // offset: 0x130
    sCollision::SBC_HANDLE mEffSbcHandle[3];  // offset: 0x13c
    cStageEpvCtrl mStageEpvCtrl;  // offset: 0x150
    s32 mAreaIdx;  // offset: 0x200
    s32 mAreaNo;  // offset: 0x204
    TICKET mArcTicket;  // offset: 0x208
    bool mIsBlocking;  // offset: 0x210
    bool mIsSetResource;  // offset: 0x211
    uStagePartsCtrl* mpParent;  // offset: 0x218
    rNavigationMesh* mpNaviMesh;  // offset: 0x220
    s32 mNavMeshSetHandle;  // offset: 0x228
    rZone* mpEfcColorZone;  // offset: 0x230
    rZone* mpEfcCtrlZone;  // offset: 0x238
    u32 mEfcColorHandle;  // offset: 0x240
    u32 mEfcCtrlHandle;  // offset: 0x244
    cZoneIndoorHandle mIndoorZoneHandle;  // offset: 0x248
    u32 mLightAndFogZoneHandle;  // offset: 0x25c
    u32 mZoneUnitCtrlHandle[3];  // offset: 0x260
    u32 mZoneStatusHandle;  // offset: 0x26c
    rSoundAreaInfo* mpSoundAreaInfo;  // offset: 0x270
    uSoundTrigger* mpSoundTrigger;  // offset: 0x278
    uSoundGenerator* mpSoundGenerator;  // offset: 0x280
    uSoundOcclusion* mpSoundOcclusion;  // offset: 0x288
    u32 mGrassReceiverTime;  // offset: 0x290
    uGrassReceiver* mpGrassReceiver;  // offset: 0x298
    uScrollCollisionGeometry* mpSbcGeometry;  // offset: 0x2a0
public:
    static MyDTI DTI;
};

class uStagePartsCtrl : public cUnit
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
    uStagePartsCtrl();
    virtual ~uStagePartsCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setResource(s32 stageNo);
    u32 getArcTag(s32 areaNo);
    void setBlockArcLoad(s32 stageNo, const MtVector3& plPos);
    bool isBlockArcLoadOk();
    void addAndLoadSplitArc(const s32 stageNo, const s32 splitX, const s32 splitZ);
    bool isSetup();
    MtVector3 getMyPlayerPos() const;
    s32 getAreaNo(u32 idx) const;
    f32 getAreaDelta() const;
    f32 getAreaOffsetY() const;
    s32 getDepth(u32 idx) const;
    bool isSbc(const s32 x, const s32 z) const;
    bool isEmptyArea(const u32 areaIdx) const;
    bool isAreaWithinSomePartsDistance(const s32 areaIdx, const s32 originAreaIdx, const s32 partDistance) const;
    rStageCustomParts::Info* getInfo(s32 areaNo) const;
    u32 getAreaSize(u32 areaNo) const;
    u32 getAreaType(u32 areaNo) const;
    f32 getAreaOffsetZ(u32 areaNo) const;
    bool calcPartsAreaLazy(const MtVector3& pos, s32& outx, s32& outz);
    bool calcPartsArea(const MtVector3& pos, s32& outX, s32& outZ) const;
    bool getPartsEdgePos(u32 partsIdx, MtVector3& start_pos, MtVector3& end_pos) const;
    s32 getPartsIndexNo(const MtVector3& pos) const;
    s32 getPartsGroupNo(const MtVector3& pos) const;
    s32 getPartsGroupNo(s32 partsIndex) const;
    MtVector3 getStartPos(u32 areaIdx) const;
    u32 getPartsNum() const;
    MT_CTSTR getMdlSdlPath(s32 areaNo) const;
    MT_CTSTR getScrSbcPath(s32 areaNo, u32 idx) const;
    MT_CTSTR getEffSbcPath(s32 areaNo, u32 idx) const;
    MT_CTSTR getLightSdlPath(s32 areaNo) const;
    MT_CTSTR getEpvPath(s32 areaNo) const;
    MT_CTSTR getNavPath(s32 areaNo) const;
    MT_CTSTR getOccluderPath(s32 areaNo) const;
    u64 getEfcColorZone(s32 areaNo) const;
    u64 getEfcCtrlZone(s32 areaNo) const;
    u64 getIndoorZoneScr(s32 areaNo) const;
    u64 getIndoorZoneEfc(s32 areaNo) const;
    u64 getLightAndFogZone(s32 areaNo) const;
    u64 getZoneUnitCtrl(s32 areaNo, ZONE_UNIT_CTRL_TYPE type) const;
    u64 getZoneStatus(s32 areaNo) const;
    u64 getSoundAreaInfo(s32 areaNo) const;
    cSplitBgm* getSplitBgmInfo() const;
    cSplitBgm* getSplitBgmInfo(const MtVector3& targetPos) const;
    uSoundOcclusion* getSoundOcclusion() const;
    s32 getPartsIndexNo(cAISvNavPathFinding* pNavPath);
    void stopMoveUnitLight(bool sleep);
    s32 getNowX() const;
    s32 getNowZ() const;
    bool isLightFogZone() const;
    rStageCustomPartsEx::ColorFog* getColorFog() const;
    rStageCustomPartsEx::HemiSphLight* getHemiSphLight() const;
    rStageCustomPartsEx::InfiLight* getInfiLight() const;
protected:
    void updateXZ();
    void updateStageMdl(bool isBlocking, bool update);
    bool updateLot(bool isBlocking, bool update);
    void updateArc(bool isBlocking, bool update);
    void updateLightFog(bool isBlocking, bool update);
    void updateOccluder(bool isBlocking, bool update);
private:
    void uStageCustomCtrlSetup();
    void uStageCustomCtrlMove();
    void uStageCustomCtrlDraw(cDraw* pDraw);
    void uStageCustomCtrlKill();
    void uStageCustomCtrlSetResource(s32 stageNo);
    void uStageCustomCtrlSetBlockArcLoad(s32 stageNo, const MtVector3& plPos);
    void uStageCustomCtrlUpdateStageMdl(bool isBlocking, bool update);
    void uStageCustomCtrlUpdateArc(bool isBlocking, bool update);
    bool uStageCustomCtrlUpdateLot(bool isBlocking, bool update);
    void uStageCustomCtrlUpdateLightFog(bool isBlocking, bool update);
    void uStageCustomCtrlUpdateOccluder(bool isBlocking, bool update);
    u32 uStageCustomCtrlGetCustomAreaList(const s32 areaZ, s32* list, const u32 list_max);
    bool uStageCustomCtrlIsSplitBlockArcLoadOk(s32 x, s32 z);
    cSplitLot* uStageCustomCtrlGetSplitLot(s32 x, s32 z);
    bool uStageCustomCtrlIsSplitLot(s32 x, s32 z);
    void uStageCustomCtrlSetLotResource();
protected:
    s32 mNowX;  // offset: 0x48
    s32 mNowZ;  // offset: 0x4c
    s32 mCurrentPartZStart;  // offset: 0x50
    s32 mCurrentPartZEnd;  // offset: 0x54
    s32 mOldX;  // offset: 0x58
    s32 mOldZ;  // offset: 0x5c
    s32 mStartX;  // offset: 0x60
    s32 mStartZ;  // offset: 0x64
    f32 mOffsetY;  // offset: 0x68
    MtVector3 mOffset;  // offset: 0x70
    MtTypedArray<uStagePartsMdl> mPartsDataAry;  // offset: 0x80
    bool mIsSetup;  // offset: 0xa0
    bool mIsReqJump;  // offset: 0xa1
    bool mIsLightFogZone;  // offset: 0xa2
    rStageCustomPartsEx::ColorFog* mpColorFog;  // offset: 0xa8
    rStageCustomPartsEx::HemiSphLight* mpHemiSphereLight;  // offset: 0xb0
    rStageCustomPartsEx::InfiLight* mpInfinityLight;  // offset: 0xb8
    rScheduler* mpFltrRsrc;  // offset: 0xc0
    uScheduler* mpFltrSchdl;  // offset: 0xc8
    MtTypedArray<cSplitLot> mSplitLotAry;  // offset: 0xd0
    MtTypedArray<cSplitArc> mSplitArcAry;  // offset: 0xf0
    MtCriticalSection mCS;  // offset: 0x110
    MtTypedArray<cPartsGroupList> mPartsGroupSm;  // offset: 0x118
    MtTypedArray<cPartsGroupList> mPartsGroupOm;  // offset: 0x138
    rOccluderEx* mpOccluder;  // offset: 0x158
    rStageCustom* mpStageResource;  // offset: 0x160
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline s32 uStagePartsCtrl::getNowZ() const {
    return this->mNowZ;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uStagePartsCtrl::isLightFogZone() const {
    return this->mIsLightFogZone;
}

// Inline, no code of its own: checked where it is inlined.
inline rStageCustomPartsEx::HemiSphLight* uStagePartsCtrl::getHemiSphLight() const {
    return this->mpHemiSphereLight;
}

// Inline, no code of its own: checked where it is inlined.
inline rStageCustomPartsEx::InfiLight* uStagePartsCtrl::getInfiLight() const {
    return this->mpInfinityLight;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 uStagePartsMdl::getAreaIdx() const {
    return this->mAreaIdx;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool uStagePartsMdl::isSetResource() {
    return this->mIsSetResource;
}

// Inline, no code of its own: checked where it is inlined.
inline uSoundOcclusion* uStagePartsMdl::getSoundOcclusion() {
    return this->mpSoundOcclusion;
}
