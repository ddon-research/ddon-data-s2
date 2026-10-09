#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "MtRandom.h"
#include "cSystem.h"
#include "cWind.h"
#include "sCollision.h"
#include "sUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRandom;
class MtRangeF;
class MtSize;
class MtUI;
class MtVector3;
class cParticleManager;
class cWind;
namespace nDraw { class Material; }
class rTexture;
class uBaseEffect;
class uEffect;
class uEffect2D;
class uMultiFilter;
class uSimpleEffect;

// Declarations
class sEffect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sEffect : public cSystem
{
    // inferred: cParticleManager::~cParticleManager names sEffect::mpInstance
    friend class cParticleManager;
    // inferred: uBaseEffect::updateDeltaTimeRate names sEffect::mpInstance
    friend class uBaseEffect;
    // inferred: uEffect::updateDrawBuffSize names sEffect::mpInstance
    friend class uEffect;
public:
    class MyDTI;
    class MultiFilterControl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class MultiFilterControl
    {
        // inferred: sEffect::getMultiBlurFilterDrawPriority names sEffect::mMultiBlurFilterControl.mDrawPriority
        friend class sEffect;
    public:
        void init(u32 FilterType);
        void setup();
        void setFilter(void* pParam, rTexture* pTexture);
        u32 getFilterPass() const;
        void setFilterPass(u32 FilterPass);
        u32 getFilterNum() const;
        void setFilterNum(u32 FilterNum);
        u32 getDrawMax() const;
        void setDrawMax(u32 DrawMax);
        u32 getDrawPriority() const;
        void setDrawPriority(u32 DrawPriority);
    private:
        bool setupMultiFilter(uMultiFilter* pFilter, u32 No);
        void updateMultiFilter(uMultiFilter* pFilter);
    private:
        uMultiFilter* mpFilter[8];  // offset: 0x0
        u32 mFilterType : 8;  // offset: 0x40
        u32 mFilterPass : 8;  // offset: 0x40
        u32 mFilterNum : 8;  // offset: 0x40
        u32 mDrawMax : 8;  // offset: 0x40
        u32 mDrawPriority;  // offset: 0x44
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
    sEffect();
    virtual ~sEffect();
    static sEffect* getInstance();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 10
    u32 getRandomU32(u32 EventMode);
    u32 getEventRandomSeed() const;
    void setEventRandomSeed(u32 Seed);
    virtual MOVE_LINE getEffectMoveLine() const;  // vtable slot 11
    virtual MOVE_LINE getEffectEventMoveLine() const;  // vtable slot 12
    virtual MOVE_LINE getEffectToolUnitMoveLine() const;  // vtable slot 13
    virtual MOVE_LINE getEffectToolUnitEventMoveLine() const;  // vtable slot 14
    virtual MOVE_LINE getEffectModelMoveLine() const;  // vtable slot 15
    virtual MOVE_LINE getEffectModelEventMoveLine() const;  // vtable slot 16
    virtual MOVE_LINE getEffectMultiFilterMoveLine() const;  // vtable slot 17
    virtual MOVE_LINE getEffectFilterMoveLine() const;  // vtable slot 18
    virtual MOVE_LINE getEffectFilterEventMoveLine() const;  // vtable slot 19
    virtual u64 getEffectFilterUnitGroupBit() const;  // vtable slot 20
    virtual MOVE_LINE getEffectLightMoveLine() const;  // vtable slot 21
    virtual MOVE_LINE getEffectLightEventMoveLine() const;  // vtable slot 22
    virtual MOVE_LINE getEffectAdhesionMoveLine() const;  // vtable slot 23
    virtual MOVE_LINE getEffectAdhesionEventMoveLine() const;  // vtable slot 24
    virtual MOVE_LINE getEffectForceMoveLine() const;  // vtable slot 25
    virtual MOVE_LINE getEffectForceEventMoveLine() const;  // vtable slot 26
    virtual bool isValidMaterial(const nDraw::Material* pMaterial) const;  // vtable slot 27
    MtVector3 getForceVec() const;
    void setForceVec(const MtVector3& ForceVec);
    MtVector3 getForceDir() const;
    void setForceDir(const MtVector3& ForceDir);
    f32 getForcePower() const;
    void setForcePower(f32 ForcePower);
    const sCollision::Param getCollisionParam() const;
    u32 getCollisionType() const;
    u32 getCollisionFilter() const;
    virtual u32 getAdhesionCollisionType() const;  // vtable slot 28
    virtual u32 getAdhesionCollisionFilter() const;  // vtable slot 29
    u8* getTempBuff(u32 ThreadIndex);
    u8* getTempBuff(u32 ThreadIndex, u32 TempBuffSize);
    u32 getTempBuffSize() const;
    void setDummyU32(u32);
    void setDummyF32(f32);
    f32 getFps();
    f32 getEffectFps() const;
    void setEffectFps(f32 Fps);
    bool isEffectFpsEnable() const;
    void setEffectFpsEnable(bool Flag);
    MtSize getDefaultScreenSize() const;
    void setDefaultScreenSize(const MtSize& DefaultScreenSize);
    u32 getDefaultSizeAdjustType() const;
    void setDefaultSizeAdjustType(u32 DefaultSizeAdjustType);
    u32 getTimer() const;
    bool isOcclusionParticleDraw() const;
    void setOcclusionParticleDraw(bool Mode);
    void setEffectVolume(u32 Volume);
    u32 getEffectVolume() const;
    bool getDecreaseParticle() const;
    u32 getParticleVolume(u32 Volume) const;
    bool isWindMove() const;
    void setWindMove(bool);
    bool isWindDeltaTimeActive() const;
    void setWindDeltaTimeActive(bool);
    f32 getWindDeltaTime() const;
    void setWindDeltaTime(f32);
    cWind* getWind();
    virtual uEffect* newEffect();  // vtable slot 30
    virtual uEffect2D* newEffect2D();  // vtable slot 31
    virtual uSimpleEffect* newSimpleEffect();  // vtable slot 32
    u32 getKillNoMin() const;
    u32 getKillNoMax() const;
    void setKillNoMin(u32 KillNoMin);
    void setKillNoMax(u32 KillNoMax);
    bool checkKillNo(u32 KillNo);
    MtRangeF getLODDist(u32 LODType) const;
    MtRangeF getLODHMLDist() const;
    MtRangeF getLODHMMDist() const;
    MtRangeF getLODHHMDist() const;
    MtRangeF getLODLMHDist() const;
    MtRangeF getLODMMHDist() const;
    MtRangeF getLODMHHDist() const;
    void setLODDist(const MtRangeF& Dist, u32 LODType);
    void setLODHMLDist(const MtRangeF& Dist);
    void setLODHMMDist(const MtRangeF& Dist);
    void setLODHHMDist(const MtRangeF& Dist);
    void setLODLMHDist(const MtRangeF& Dist);
    void setLODMMHDist(const MtRangeF& Dist);
    void setLODMHHDist(const MtRangeF& Dist);
    u32 getDefaultLODType() const;
    void setDefaultLODType(u32);
    u32 getLODSkipMask(u32 LODType, f32 Dist) const;
    u32 getExclusionTrait() const;
    void setExclusionTrait(u32);
    u32 getUnitNo();
    bool getLifeRateCurveFlag() const;
    void setLifeRateCurveFlag(bool LifeRateCurveFlag);
    bool isVibrationEnable() const;
    void setVibrationEnable(bool);
    u32 getChildUnitLevel() const;
    void setChildUnitLevel(u32);
    f32 getCullingDist(u32 No) const;
    f32 getCullingDistSq(u32 No) const;
    void setCullingDist(f32 Dist, u32 No);
    u32 getCullingDistTblNum() const;
    u32 getMultiBlurFilterDrawPriority() const;
    void setMultiBlurFilterDrawPriority(u32 DrawPriority);
    u32 getMultiBlurFilterPass() const;
    void setMultiBlurFilterPass(u32 FilterPass);
    u32 getMultiBlurFilterNum() const;
    void setMultiBlurFilterNum(u32 FilterNum);
    u32 getMultiBlurFilterDrawMax() const;
    void setMultiBlurFilterDrawMax(u32 FilterDrawMax);
    void setMultiBlurFilter(void* pParam, rTexture* pAlphaMap);
    u32 getMultiColorCorrectFilterDrawPriority() const;
    void setMultiColorCorrectFilterDrawPriority(u32 DrawPriority);
    u32 getMultiColorCorrectFilterPass() const;
    void setMultiColorCorrectFilterPass(u32 FilterPass);
    u32 getMultiColorCorrectFilterNum() const;
    void setMultiColorCorrectFilterNum(u32 FilterNum);
    u32 getMultiColorCorrectFilterDrawMax() const;
    void setMultiColorCorrectFilterDrawMax(u32 FilterDrawMax);
    void setMultiColorCorrectFilter(void* pParam);
    u32 getMultiGodRaysFilterDrawPriority() const;
    void setMultiGodRaysFilterDrawPriority(u32 DrawPriority);
    u32 getMultiGodRaysFilterPass() const;
    void setMultiGodRaysFilterPass(u32 FilterPass);
    u32 getMultiGodRaysFilterNum() const;
    void setMultiGodRaysFilterNum(u32 FilterNum);
    u32 getMultiGodRaysFilterDrawMax() const;
    void setMultiGodRaysFilterDrawMax(u32 FilterDrawMax);
    void setMultiGodRaysFilter(void* pParam);
    u32 getMultiBloomFilterDrawPriority() const;
    void setMultiBloomFilterDrawPriority(u32 DrawPriority);
    u32 getMultiBloomFilterPass() const;
    void setMultiBloomFilterPass(u32 FilterPass);
    u32 getMultiBloomFilterNum() const;
    void setMultiBloomFilterNum(u32 FilterNum);
    u32 getMultiBloomFilterDrawMax() const;
    void setMultiBloomFilterDrawMax(u32 FilterDrawMax);
    void setMultiBloomFilter(void* pParam);
    f32 getLensFlareScale(u32 View) const;
    void setLensFlareScale(f32, u32);
    void setLensFlareScaleAll(f32 Scale);
    u32 getAdhesionLimitMax();
    void setAdhesionLimitMax(u32 Max);
    void addAdhesionLimitCount();
    void subtractAdhesionLimitCount();
    u32 isCreateAdhesion();
    void setAdhesionDivideMax(u32 Max);
    u32 getAdhesionDivideMax() const;
protected:
    void initRandom();
    void allocTempBuff(u32 TempBuffSize);
    void setCollisionParamType(u32 Type);
    void setCollisionParamFilter(u32 Filter);
    void setCollisionParamCallback(MtObject*, const sCollision::CONTACT_CALLBACK, const u32);
private:
    void freeTempBuff();
private:
    u32 mEventRandomSeed;  // offset: 0x14
    MtRandom mEventRandom;  // offset: 0x18
    f32 mEffectFps;  // offset: 0x28
    bool mEffectFpsEnable;  // offset: 0x2c
    MtSize mDefaultScreenSize;  // offset: 0x30
    u32 mDefaultSizeAdjustType;  // offset: 0x38
    MtVector3 mForceVec;  // offset: 0x40
    MtVector3 mForceDir;  // offset: 0x50
    f32 mForcePower;  // offset: 0x60
    u32 mTimer;  // offset: 0x64
    sCollision::Param mCollisionParam;  // offset: 0x70
    u8* mpTempBuff;  // offset: 0x190
    u32 mTempBuffSize;  // offset: 0x198
    bool mOcclusionParticleDraw;  // offset: 0x19c
    u32 mParticleVolume;  // offset: 0x1a0
    bool mWindMove;  // offset: 0x1a4
    bool mWindDeltaTimeActive;  // offset: 0x1a5
    f32 mWindDeltaTime;  // offset: 0x1a8
    cWind mWind;  // offset: 0x1b0
    u32 mKillNoMin : 16;  // offset: 0x230
    u32 mKillNoMax : 16;  // offset: 0x230
    f32 mLODDist[6][2];  // offset: 0x234
    u32 mDefaultLODType;  // offset: 0x264
    u32 mExclusionTrait;  // offset: 0x268
    u32 mUnitNo;  // offset: 0x26c
    bool mLifeRateCurveFlag;  // offset: 0x270
    bool mVibrationEnable;  // offset: 0x271
    u32 mChildUnitLevel;  // offset: 0x274
    f32 mCullingDist[8][2];  // offset: 0x278
    MultiFilterControl mMultiBlurFilterControl;  // offset: 0x2b8
    MultiFilterControl mMultiColorCorrectFilterControl;  // offset: 0x300
    MultiFilterControl mMultiGodRaysFilterControl;  // offset: 0x348
    MultiFilterControl mMultiBloomFilterControl;  // offset: 0x390
    f32 mLensFlareScale[8];  // offset: 0x3d8
    u32 mAdhesionLimitMax;  // offset: 0x3f8
    u32 mAdhesionLimitCount;  // offset: 0x3fc
    u32 mAdhesionDivideMax : 8;  // offset: 0x400
public:
    static const u32 CHILD_UNIT_LEVEL_MAX;
    static MyDTI DTI;
protected:
    static sEffect* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sEffect* sEffect::getInstance() {
    return ::sEffect::mpInstance;
}
