#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtString.h"
#include "cSystem.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtDTI;
class MtHermiteCurve;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class MtVector4;
class cCoGrass;
class cDraw;
class cGrassOutsourcing;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }

// Declarations
class sGrass;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using MT_MFUNCPTRU32 = void(MtObject::*)(void*, u32);
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;

class sGrass : public cSystem
{
public:
    enum LOD
    {
        LOD_HIGH = 0,
        LOD_MIDDLE = 1,
        LOD_LOW = 2,
        LOD_AUTO = 3,
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
    virtual ~sGrass();
    static sGrass* createInstance();
    static void deleteInstance();
    static sGrass* getInstance();
    void addGrass(MtObject* pgrass);
    void removeGrass(MtObject* pgrass);
    MtArray* getGrass();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void begin();
    void end();
    u32 getWindMask();
    void setWindMask(u32);
    void addMark(MtObject* p_obj);
    void delMark(MtObject* p_obj);
    void setMark(cDraw* pdraw, const MtAABB& boundary);
    f32 getUnitMeter() const;
    bool isForcedFade() const;
    f32 getFadeBeginDistance() const;
    f32 getFadeEndDistance() const;
    void setForcedFade(bool);
    void setFadeBeginDistance(f32);
    void setFadeEndDistance(f32);
    bool isForcedFadeCurve() const;
    const MtHermiteCurve& getFadeCurve() const;
    void setForcedFadeCurve(bool);
    void setFadeCurve(const MtHermiteCurve&);
    bool isForcedVisiblePercent() const;
    void setForcedVisiblePercent(bool);
    f32 getVisiblePercent() const;
    void setVisiblePercent(f32);
    bool isMoreSmoothFade() const;
    void setMoreSmoothFade(bool);
    bool isResourceOverrideVisiblePercent() const;
    bool isResourceOverrideClusterSize() const;
    void setResourceOverrideVisiblePercent(bool);
    void setResourceOverrideClusterSize(bool);
    f32 getResourceVisiblePercent() const;
    f32 getResourceClusterSize() const;
    void setResourceVisiblePercent(f32);
    void setResourceClusterSize(f32);
private:
    void initGeometry();
    void releaseGeometry();
public:
    bool isAlphaToCoverageEnable() const;
    void setAlphaToCoverageEnable(bool);
    void setIndexBuffer(cDraw* pdraw) const;
    void setPointIndexBuffer(cDraw* pdraw) const;
    void set6IndexBuffer(cDraw* pdraw) const;
    void set64IndexBuffer(cDraw* pdraw) const;
    void set62IndexBuffer(cDraw* pdraw) const;
    void set6PointIndexBuffer(cDraw* pdraw) const;
    void set4VertexBuffer(cDraw* pdraw) const;
    u32 getLOD() const;
    f32 getLODBeginDistance() const;
    f32 getLODEndDistance() const;
    void setLOD(u32);
    void setLODBeginDistance(f32);
    void setLODEndDistance(f32);
    u32 getLOD(f32 dist);
    void initLightMask();
    void releaseLightMask();
    nDraw::Texture* getLightMaskMap() const;
    nDraw::Texture* getDepthMap() const;
    f32 getLightMaskMargine() const;
    f32 getBias() const;
    u32 getSize() const;
    MtVector4 getHalfSize() const;
    MtVector4 getHalfPixel() const;
    f32 getLightMaskBlendFactor() const;
    void setLightMaskBlendFactor(f32);
    const MtMatrix& getPoinViewProj(u32 vno) const;
    cCoGrass* getCoprocessor();
    void setOutsourcing(cGrassOutsourcing*);
    void flush();
    bool isFlushed() const;
    void setOutputPath(const MtString&);
    const MtString& getOutputPath() const;
    void setSBCOffset(const MtVector3&);
    const MtVector3& getSBCOffset() const;
    void setNoCulling(const bool);
    bool getNoCulling() const;
private:
    void traverseGrassUnit(MT_MFUNCPTRU32 pUnitFoundFunc);
    void foundUnitFunctionGrassActive(void* pGrassUnit, u32);
    void foundUnitFunctionGrassVisiblePercentMulValue(void* pGrassUnit, u32);
    void foundUnitFunctionGrassModeMinValue(void* pGrassUnit, u32);
    void foundUnitFunctionGrassFadeBeginDistanceMulValue(void* pGrassUnit, u32);
    void foundUnitFunctionGrassFadeEndDistanceMulValue(void* pGrassUnit, u32);
    void foundUnitFunctionGrassNearClipDistanceMulValue(void* pGrassUnit, u32);
public:
    bool isActiveGrassMulValue() const;
    void setActiveGrassMulValue(bool NewActiveGrassMulValue);
    f32 getGrassVisiblePercentMulValue() const;
    void setGrassVisiblePercentMulValue(f32 NewGrassVisiblePercentMulValue);
    u32 getGrassModeMinValue() const;
    void setGrassModeMinValue(u32 NewGrassModeMinValue);
    f32 getGrassFadeBeginDistanceMulValue() const;
    void setGrassFadeBeginDistanceMulValue(f32 NewFadeInDistanceMulValue);
    f32 getGrassFadeEndDistanceMulValue() const;
    void setGrassFadeEndDistanceMulValue(f32 NewFadeOutDistanceMulValue);
    f32 getGrassNearClipDistanceMulValue() const;
    void setGrassNearClipDistanceMulValue(f32 NewNearClipDistanceMulValue);
private:
    sGrass();
private:
    MtArray mGrass;  // offset: 0x18
    u32 mWindMask;  // offset: 0x38
    MtArray mMark;  // offset: 0x40
    f32 mUnitMeter;  // offset: 0x60
    bool mForcedFade;  // offset: 0x64
    f32 mFadeBeginDistance;  // offset: 0x68
    f32 mFadeEndDistance;  // offset: 0x6c
    bool mForcedFadeCurve;  // offset: 0x70
    MtHermiteCurve mFadeCurve;  // offset: 0x74
    bool mForcedVisiblePercent;  // offset: 0xb4
    f32 mVisiblePercent;  // offset: 0xb8
    bool mMoreSmoothFade;  // offset: 0xbc
    bool mResourceOverrideVisiblePercent;  // offset: 0xbd
    bool mResourceOverrideClusterSize;  // offset: 0xbe
    f32 mResourceVisiblePercent;  // offset: 0xc0
    f32 mResourceClusterSize;  // offset: 0xc4
    nDraw::IndexBuffer* mpIndexBuffer;  // offset: 0xc8
    nDraw::IndexBuffer* mpPointIndexBuffer;  // offset: 0xd0
    nDraw::IndexBuffer* mp62IndexBuffer;  // offset: 0xd8
    nDraw::IndexBuffer* mp64IndexBuffer;  // offset: 0xe0
    nDraw::IndexBuffer* mp6IndexBuffer;  // offset: 0xe8
    nDraw::IndexBuffer* mp6PointIndexBuffer;  // offset: 0xf0
    nDraw::VertexBuffer* mp4VertexBuffer;  // offset: 0xf8
    u32 mLOD;  // offset: 0x100
    f32 mLODBeginDistance;  // offset: 0x104
    f32 mLODEndDistance;  // offset: 0x108
    bool mUseAlphaToCoverage;  // offset: 0x10c
    nDraw::Texture* mpTarget;  // offset: 0x110
    nDraw::Texture* mpDepth;  // offset: 0x118
    f32 mLightMaskMargine;  // offset: 0x120
    f32 mPointMapBias;  // offset: 0x124
    u32 mPointMapSize;  // offset: 0x128
    MtVector4 mPointMapHalfSize;  // offset: 0x130
    MtVector4 mPointMapHalfPixel;  // offset: 0x140
    f32 mLightMaskBlendFactor;  // offset: 0x150
    MtMatrix mPointViewProj[8];  // offset: 0x160
    bool mFlush;  // offset: 0x360
    MtString mOutputPath;  // offset: 0x368
    MtVector3 mSBCOffset;  // offset: 0x370
    bool mNoCulling;  // offset: 0x380
    bool mIsActiveGrassMulValue;  // offset: 0x381
    f32 mGrassVisiblePercentMulValue;  // offset: 0x384
    u32 mGrassModeMinValue;  // offset: 0x388
    f32 mGrassFadeBeginDistanceMulValue;  // offset: 0x38c
    f32 mGrassFadeEndDistanceMulValue;  // offset: 0x390
    f32 mGrassNearClipDistanceMulValue;  // offset: 0x394
public:
    static MyDTI DTI;
private:
    static const u32 DEFAULT_WIND_MASK = 1;
    static const u32 MAX_MARK_UNIT = 512;
    static const u32 MAX_MARK = 8;
public:
    static const u32 QUAD_VERTEX_OFFSET = 4;
    static const u32 QUAD_INDEX_OFFSET = 6;
    static const u32 QUAD_VERTEX_COUNT = 10922;
    static const u32 QUAD_MAX_INDEX = 65532;
    static const u32 QUAD_MAX_VERTEX = 43688;
    static const u32 CHAIN_VERTEX_OFFSET = 8;
    static const u32 CHAIN_INDEX_OFFSET = 18;
    static const u32 CHAIN_VERTEX_COUNT = 3640;
    static const u32 CHAIN_MAX_INDEX = 65520;
    static const u32 CHAIN_MAX_VERTEX = 29120;
    static const u32 CHAIN_MID_INDEX_OFFSET = 12;
    static const u32 CHAIN_MID_VERTEX_COUNT = 5460;
    static const u32 CHAIN_MID_MAX_INDEX = 65520;
    static const u32 CHAIN_MID_MAX_VERTEX = 43680;
    static const u32 CHAIN_LOW_INDEX_OFFSET = 6;
    static const u32 CHAIN_LOW_VERTEX_COUNT = 10921;
    static const u32 CHAIN_LOW_MAX_INDEX = 65526;
    static const u32 CHAIN_LOW_MAX_VERTEX = 87368;
private:
    static sGrass* mpInstance;
};

inline void* sGrass::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sGrass* sGrass::getInstance() {
    return ::sGrass::mpInstance;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sGrass::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sGrass::DTI)->memFree(p_addr);
}
