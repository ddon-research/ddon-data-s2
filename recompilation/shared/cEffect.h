#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtAABB;
class MtVector3;
class cUnit;
class uBaseEffect;

// Declarations
class cEffectTransparency;
class cSynchronization;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class cEffectTransparency
{
    // inferred: uBaseEffect::getTransparency names uBaseEffect::mTransparencyParam.mTransparency[0]
    friend class uBaseEffect;
public:
    cEffectTransparency();
    cEffectTransparency(f32);
    cEffectTransparency(const cEffectTransparency& Param);
    f32 getTransparency() const;
    f32 getViewTransparency(u32 ViewportNo) const;
    void setTransparency(f32 Rate);
    void setViewTransparency(f32, u32);
    void applyTransparency(f32 Value);
    void applyViewTransparency(f32, u32);
    void copyParam(const cEffectTransparency& OrgParam);
private:
    f32 mTransparency[8];  // offset: 0x0
};

class cSynchronization
{
public:
    class BoundaryParam;
public:
    class BoundaryParam
    {
    public:
        BoundaryParam();
        ~BoundaryParam();
        u32 updateDrawView(u32 DrawView);
        void enable(const cSynchronization::BoundaryParam& Param);
        void disable();
    private:
        bool isBoundaryCulling(u32 ViewportNo);
    public:
        MtVector3 mPos;  // offset: 0x0
        MtAABB mBox;  // offset: 0x10
        f32 mRadius;  // offset: 0x30
        f32 mDistanceSQ;  // offset: 0x34
        u32 mRadiusEnable : 8;  // offset: 0x38
        u32 mBoxEnable : 8;  // offset: 0x38
        u32 mDistanceEnable : 8;  // offset: 0x38
        u32 mType : 8;  // offset: 0x38
        u32 mPadding323c;  // offset: 0x3c
    };
public:
    cSynchronization();
    ~cSynchronization();
    void init(cUnit* pParent);
    void update(u32 DrawMode, u32 DrawView);
    void enableCulling(const MtVector3& Pos, f32 DistSq);
    void disableCulling();
    void enableBoundary(const BoundaryParam& Param);
    void disableBoundary();
    bool isRelation() const;
    void updateDraw(cUnit* pUnit);
private:
    cUnit* mpParent;  // offset: 0x0
    u32 mDrawMode : 16;  // offset: 0x8
    u32 mDrawView : 16;  // offset: 0x8
    u32 mCullingFlag;  // offset: 0xc
    f32 mCullingDistSq;  // offset: 0x10
    MtVector3 mCullingPos;  // offset: 0x20
    BoundaryParam mBoundaryParam;  // offset: 0x30
};
