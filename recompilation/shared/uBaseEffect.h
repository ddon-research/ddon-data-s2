#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cEffect.h"
#include "rEffectAnim.h"
#include "rEffectList.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPoint;
class MtProperty;
class MtQuaternion;
class MtUI;
class MtVector3;
class cDraw;
class cEffectTransparency;
class cParticleManager;
class cUnit;
namespace nPrim { struct Material; }
class rEffectList;

// Declarations
class uBaseEffect;

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

class uBaseEffect : public uCoord
{
    // inferred: cParticleManager::setup names uBaseEffect::mTimeInterpolationRate
    friend class cParticleManager;
public:
    enum BASE_STATUS
    {
        STATUS_INIT = 1,
        STATUS_SLEEP = 2,
        STATUS_SCHEDULER = 4,
        STATUS_EVENT = 8,
        STATUS_RESTART = 16,
        STATUS_FINISH = 32,
        STATUS_TIMER_CONTROL = 64,
        STATUS_TEX_OMIT = 128,
        STATUS_VB_INVALID = 256,
        STATUS_NO_FOG = 512,
        STATUS_BASE_RESERVED_1 = 1024,
        STATUS_BASE_RESERVED_2 = 2048,
        STATUS_SUBCLASS_RESERVED = 16773120,
        STATUS_NO_RESOURCE = 16777216,
        STATUS_MALLOC_ERROR = 33554432,
        STATUS_IMPROPER_RESOURCE = 67108864,
        STATUS_GPU_MALLOC_ERROR = 134217728,
        STATUS_DRAW_BUFFER_OVER = 268435456,
        STATUS_ERROR = 520093696,
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
    uBaseEffect();
    virtual ~uBaseEffect();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void updateWorldMatrix();  // vtable slot 26
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setParent(uCoord* pParent, s32 ParentNo);  // vtable slot 24
    virtual void setEffectParent(uCoord* pParent);  // vtable slot 28
    void setParentNo(s32 ParentNo);
    virtual bool getSleepMode() const;  // vtable slot 29
    virtual void setSleepMode(bool Mode);  // vtable slot 30
    bool getSchedulerMode() const;
    void setSchedulerMode(bool Mode);
    bool getEventMode() const;
    void setEventMode(bool Mode);
    bool getTimerControlMode() const;
    void setTimerControlMode(bool Mode);
    bool getTextureOmitMode() const;
    void setTextureOmitMode(bool Mode);
    bool getVBInvalidMode() const;
    void setVBInvalidMode(bool Mode);
    bool getNoFogMode() const;
    void setNoFogMode(bool Mode);
    virtual bool getRestartFlag() const;  // vtable slot 31
    virtual void setRestartFlag(bool Flag);  // vtable slot 32
    f32 getDeltaTimeCoef() const;
    void setDeltaTimeCoef(f32 DeltaTimeCoef);
    u32 getTimer() const;
    void setTimer(u32 Timer);
    u32 getLoopFrame() const;
    void setLoopFrame(u32 LoopFrame);
    u32 getKillNo() const;
    void setKillNo(u32 KillNo);
    u32 getExclusionTrait() const;
    void setExclusionTrait(u32 ExclusionTrait);
    u32 getCullingGroup() const;
    void setCullingGroup(u32 Group);
    u32 getAxisType() const;
    void setAxisType(u32 AxisType);
    u32 getRelationType() const;
    void setRelationType(u32 RelationType);
    u32 getEndType() const;
    void setEndType(u32 EndType);
    rEffectList* getEffectList();
    virtual void setEffectList(rEffectList* pEffectList);  // vtable slot 33
    MtVector3 getOfs() const;
    void setOfs(const MtVector3& Ofs);
    MtVector3 getDir() const;
    void setDir(const MtVector3& Dir);
    void setQuatParentOfs(const MtQuaternion& Quat, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order);
    void setQuatPos(const MtQuaternion& Quat, const MtVector3& Pos, u32 Order);
    void setWmatOfs(const MtMatrix& Wmat, const MtVector3& Ofs, u32 Order);
    void setDirParentOfs(const MtVector3& Dir, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order, u32 AxisType);
    void setDirPos(const MtVector3& Dir, const MtVector3& Pos, u32 Order, u32 AxisType);
    u32 getParticleVolume() const;
    void setParticleVolume(u32 Volume);
    void setParticleVolumeDirect(u32);
    u32 getFilterVolume() const;
    void setFilterVolume(u32 Volume);
    u32 getLifeFrameVolume() const;
    void setLifeFrameVolume(u32 Volume);
    u32 getBoundaryType() const;
    void setBoundaryType(u32 BoundaryType);
    bool isBoundaryEnable() const;
    u32 getBoundaryResult() const;
    void setDummyU32(u32);
    virtual void doFinish();  // vtable slot 34
    virtual void doRestart();  // vtable slot 35
    virtual void doClear();  // vtable slot 36
    virtual void doKeepHoldOff();  // vtable slot 37
    const MtMatrix& getWorldMatrixBase() const;
    u32 getStatus() const;
    f32 getDeltaTimeRate() const;
    f32 getTimeInterpolationRate() const;
    s32 getIntTimeInterpolationRate() const;
    u32 getLoopNum() const;
    void setRelationParent(cUnit* pUnit);
    f32 getTransparency() const;
    f32 getViewTransparency(u32 ViewportNo) const;
    void setTransparency(f32 Rate);
    void setViewTransparency(f32, u32);
    const cEffectTransparency& getTransparencyParam() const;
    bool isColorControlEnable() const;
    MtColor calcBlendColor(const MtColor& Color, const MtColor& OrgColor);
    u32 getColorID() const;
    bool isParentModel() const;
    u32 getPrimAttribute(rEffectList::EFL_PARTICLE_COMMON* pParticleParam) const;
    u32 calcRand();
    static nPrim::Material getPrimMaterial(u32 BlendState, u32 AnimFlag, u32 PrimAttribute);
    static nPrim::Material addPrimMaterialAttribute(const nPrim::Material& BaseMaterial, u32 AnimFlag);
    static void calcPolygonVertexPos(MtVector3* pPos, u32 PolygonFixType, u32 RotAxisType, const MtPoint& PatCenter, const f32* pDistortRate, const MtMatrix& Wmat, f32 Width, f32 Height, rEffectAnim::SEQ_PAT* pSeqPat, u32 AnimFlag);
protected:
    void constructBaseEffect();
    void destructBaseEffect();
    virtual void restart();  // vtable slot 38
    bool finish();
    virtual void updateDeltaTimeRate();  // vtable slot 39
    virtual bool checkRelation();  // vtable slot 40
    bool checkEnd();
    u32 updateBoundaryControl();
    bool isCulling(cDraw* pDraw) const;
    void updateLoopNum();
    u32 calcAnimFlag(u32 AnimFlag, u32* pRandCtr);
    MtColor calcSrcColor(MtColor* pResColor, u32 ColorFlag, u32* pRandCtr);
private:
    void applyUnitParam();
    bool isBoundaryCulling(u32 ViewportNo) const;
protected:
    u32 mStatus;  // offset: 0x110
    rEffectList* mpEffectList;  // offset: 0x118
    f32 mBaseFps;  // offset: 0x120
    f32 mDeltaTimeRate;  // offset: 0x124
    f32 mDeltaTimeCoef;  // offset: 0x128
    f32 mTimeInterpolationRate;  // offset: 0x12c
    s32 mIntTimeInterpolationRate;  // offset: 0x130
    u32 mTimer;  // offset: 0x134
    u32 mLoopNum : 16;  // offset: 0x138
    u32 mLoopFrame : 16;  // offset: 0x138
    u32 mKillNo : 16;  // offset: 0x13c
    u32 mExclusionTrait : 8;  // offset: 0x13c
    u32 mAxisType : 4;  // offset: 0x13c
    u32 mRelationType : 4;  // offset: 0x13c
    u32 mEndType : 4;  // offset: 0x140
    u32 mCullingGroup : 4;  // offset: 0x140
    u32 mParticleVolume : 4;  // offset: 0x140
    u32 mFilterVolume : 4;  // offset: 0x140
    u32 mLifeFrameVolume : 4;  // offset: 0x140
    u32 mBoundaryType : 4;  // offset: 0x140
    u32 mCreateFlag : 1;  // offset: 0x140
    u32 mParentDisableFlag : 1;  // offset: 0x140
    u32 mParentModelFlag : 1;  // offset: 0x140
    u32 mBoundaryFlag : 1;  // offset: 0x140
    u32 mBoundaryResult : 4;  // offset: 0x140
    cUnit* mpRelationParent;  // offset: 0x148
    MtMatrix mWmatBase;  // offset: 0x150
    MtVector3 mOfs;  // offset: 0x190
    MtVector3 mDir;  // offset: 0x1a0
    cEffectTransparency mTransparencyParam;  // offset: 0x1b0
public:
    static MyDTI DTI;
};
