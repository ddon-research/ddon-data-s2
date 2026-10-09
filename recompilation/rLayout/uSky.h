#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cUnit.h"
#include "uFog.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
class rSky;
class rStarCatalog;
class rTexture;
class sWeatherManager;

// Declarations
class uSky;
class uSkyFog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uSky : public cUnit
{
    // inferred: sWeatherManager::setWeatherMoonEnable names uSky::mMoonEnable
    friend class sWeatherManager;
public:
    enum NORTH_AXIS
    {
        NA_PLUS_Z = 0,
        NA_MINUS_Z = 1,
        NA_PLUS_X = 2,
        NA_MINUS_X = 3,
    };
public:
    class MyDTI;
    struct SKY_CBUFFER;
    struct SKYFOG_CBUFFER;
    struct StarVertex;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SKY_CBUFFER
    {
    public:
        MtFloat3 mRayleighScatteringK;  // offset: 0x0
        f32 mAtmosphereHeight;  // offset: 0xc
        MtFloat3 mRayleighScatteringPhaseK;  // offset: 0x10
        f32 mAtmosphereAverageDensityHeight;  // offset: 0x1c
        MtFloat3 mMieScatteringK;  // offset: 0x20
        f32 mAerosolHeight;  // offset: 0x2c
        MtFloat3 mMieScatteringPhaseK;  // offset: 0x30
        f32 mAerosolAverageDensityHeight;  // offset: 0x3c
        MtFloat3 mRayleighSecondaryScatteringK;  // offset: 0x40
        f32 mEarthRadius;  // offset: 0x4c
        MtFloat3 mMieSecondaryScatteringK;  // offset: 0x50
        f32 mOpticalDepthMapSize;  // offset: 0x5c
        MtFloat3 mSunColor;  // offset: 0x60
        f32 mStarrySkyIntensity;  // offset: 0x6c
        MtFloat3 mSunDirection;  // offset: 0x70
        f32 mStarrySkyBlendFactor;  // offset: 0x7c
        MtFloat2 mScatterMapSize;  // offset: 0x80
        MtFloat2 mEccentricity;  // offset: 0x88
        MtFloat2 mCloudEccentricity;  // offset: 0x90
        f32 mCloudHeightMax;  // offset: 0x98
        f32 mCloudHeightMin;  // offset: 0x9c
        f32 mCloudScatteringK;  // offset: 0xa0
        f32 mCloudScatteringPhaseK;  // offset: 0xa4
        f32 mCloudSecondaryScatteringK;  // offset: 0xa8
        f32 mHeightOffset;  // offset: 0xac
    };
public:
    struct alignas(16) SKYFOG_CBUFFER
    {
    public:
        MtFloat3 mSunColor;  // offset: 0x0
        f32 padding0;  // offset: 0xc
        MtFloat3 mSunDirection;  // offset: 0x10
        f32 padding1;  // offset: 0x1c
        MtFloat3 mCombinedScatteringK;  // offset: 0x20
        f32 padding2;  // offset: 0x2c
        MtFloat3 mInverseCombinedScatteringK;  // offset: 0x30
        f32 padding3;  // offset: 0x3c
        MtFloat3 mRayleighScatteringPhaseK;  // offset: 0x40
        f32 padding4;  // offset: 0x4c
        MtFloat3 mMieScatteringPhaseK;  // offset: 0x50
        f32 padding5;  // offset: 0x5c
        MtFloat2 mEccentricity;  // offset: 0x60
    };
public:
    struct StarVertex
    {
    public:
        MtFloat3 pos;  // offset: 0x0
        MtFloat3 color;  // offset: 0xc
        MtFloat2 offset;  // offset: 0x18
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
    uSky(u32 depth_map_width, u32 depth_map_height);
    virtual ~uSky();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    rSky* getResource() const;
    void setResource(rSky* pres);
    u32 getNorthAxis() const;
    void setNorthAxis(NORTH_AXIS n);
    u32 getHour() const;
    void setHour(u32 h);
    u32 getMinute() const;
    void setMinute(u32 m);
    u32 getSecond() const;
    void setSecond(u32 s);
    u32 getTime() const;
    void setTime(u32 t);
    MtVector3 getMieScattering() const;
    void setMieScattering(const MtVector3& ms);
    f32 getCloudScattering() const;
    void setCloudScattering(f32 cs);
    f32 getMieDensity() const;
    void setMieDensity(f32 d);
    f32 getCloudiness() const;
    void setCloudiness(f32 c);
    f32 getCloudEccentricity() const;
    void setCloudEccentricity(f32 c);
    f32 getCloudHeight() const;
    void setCloudHeight(f32 h);
    f32 getCloudThickness() const;
    void setCloudThickness(f32 t);
    MtVector3 getRayleighScatteringK() const;
    MtVector3 getMieScatteringK() const;
    f32 getCloudScatteringK() const;
    MtVector3 getSunScatteredColor(f32 h) const;
    MtVector3 getAmbientColor(f32 h, f32 scale) const;
    MtVector3 getSunDirection() const;
    nDraw::Texture* getRayleighDepthMap() const;
    nDraw::Texture* getMieDepthMap() const;
    void setFogConstantBuffer(cDraw* pdraw);
    bool getUseFog() const;
    void setUseFog(bool u);
    u32 getFogUnitLine() const;
    void setFogUnitLine(u32 l);
    MtVector3 getFogSunColorScale() const;
    void setFogSunColorScale(const MtVector3& s);
    f32 getFogRayleighScale() const;
    void setFogRayleighScale(f32 s);
    f32 getFogMieScale() const;
    void setFogMieScale(f32 s);
    u32 getSubScenePriority() const;
    void setSubScenePriority(u32 p);
    rStarCatalog* getStarCatalog() const;
    void setStarCatalog(rStarCatalog* pres);
    u32 getStarRandomSeed() const;
    void setStarRandomSeed(u32 seed);
    MtVector3 getMoonScatteredColor(f32 h) const;
    f32 getHeightOffset() const;
    void setHeightOffset(f32 offset);
protected:
    virtual MtVector3 getBaseSunColor() const;  // vtable slot 24
    void createBuffer();
    void setStarTexture(rTexture* pRes);
    void setStarIntensity(f32 starIntensity);
    void setStarSize(f32 starSize);
    void setStarrySkyIntensity(f32 starrySkyIntensity);
    void setStarTwinkleAmplitude(f32 starTwinkleAmplitude);
    void setStarCount(u32 cnt);
    void createStarProtected();
    void setMoonEnable(bool b);
    bool getMoonEnable() const;
    MtVector3& MoonDirection();
    MtMatrix& MoonRotMat();
    MtMatrix& RotMat();
    MtMatrix& SunRotMat();
private:
    void setConstantBuffer(cDraw* pdraw);
    void drawDepthMap(cDraw* pdraw);
    void draw1stPass(cDraw* pdraw);
    void draw2ndPass(cDraw* pdraw);
protected:
    virtual void drawSun(cDraw* pdraw);  // vtable slot 25
private:
    void setupConstantBuffer();
    void setupBlurParam(cDraw* pdraw);
    MtVector3 getOutScatter(f32 h, const MtVector3& light_dir) const;
    MtFloat2 getCrossPoint(const MtFloat2& begin, const MtFloat2& dir, f32 r) const;
    f32 getOpticalDepth(const MtFloat2& begin, const MtFloat2& dir, f32 t, f32 earth_radius, f32 atmosphere_height, f32 average_height) const;
    u32 getStarNum() const;
    void setStarNum(u32 num);
    void createStar();
    void drawStar(cDraw* pdraw);
    MtFloat3 getRGBFromK(f32 T, f32 Y) const;
    virtual void drawMoon(cDraw* pdraw);  // vtable slot 26
    virtual MtVector3 getSunDirforMoon();  // vtable slot 27
    u32 getDivX() const;
    void setDivX(u32 d);
    u32 getDivY() const;
    void setDivY(u32 d);
private:
    alignas(16) SKY_CBUFFER mConstantBuffer[2];  // offset: 0x50
    SKYFOG_CBUFFER mFogConstantBuffer[2];  // offset: 0x1b0
    rSky* mpResource;  // offset: 0x290
    nDraw::Texture* mpRayleighDepthMap;  // offset: 0x298
    nDraw::Texture* mpMieDepthMap;  // offset: 0x2a0
    nDraw::Texture* mpRayleighScatterMap;  // offset: 0x2a8
    nDraw::Texture* mpMieScatterMap;  // offset: 0x2b0
    nDraw::Texture* mpCloudScatterMap;  // offset: 0x2b8
    nDraw::Texture* mpCloudScatterTempMap;  // offset: 0x2c0
    nDraw::VertexBuffer* mpVertex;  // offset: 0x2c8
    nDraw::IndexBuffer* mpIndex;  // offset: 0x2d0
    bool mUpdateMap;  // offset: 0x2d8
    MtMatrix mRotMat;  // offset: 0x2e0
    MtVector3 mSunDirection;  // offset: 0x320
    MtMatrix mSunRotMat;  // offset: 0x330
    MtVector3 mAmbientColor;  // offset: 0x370
    MtVector3 mMieScattering;  // offset: 0x380
    f32 mMieDensity;  // offset: 0x390
    f32 mEccentricity;  // offset: 0x394
    f32 mCloudScattering;  // offset: 0x398
    f32 mCloudEccentricity;  // offset: 0x39c
    f32 mCloudiness;  // offset: 0x3a0
    f32 mCloudThickness;  // offset: 0x3a4
    f32 mCloudHeight;  // offset: 0x3a8
    f32 mHeightOffset;  // offset: 0x3ac
    MtVector3 mRayleighScatteringK;  // offset: 0x3b0
    MtVector3 mMieScatteringK;  // offset: 0x3c0
    f32 mCloudScatteringK;  // offset: 0x3d0
    f32 mLastEarthRadius;  // offset: 0x3d4
    f32 mLastAtmosphereHeight;  // offset: 0x3d8
    f32 mLastAtmosphereAverageDensityHeight;  // offset: 0x3dc
    f32 mLastAerosolHeight;  // offset: 0x3e0
    f32 mLastAerosolAverageDensityHeight;  // offset: 0x3e4
    u32 mLoopCount;  // offset: 0x3e8
    u32 mPreComputeLoopCount;  // offset: 0x3ec
    u32 mLightLine;  // offset: 0x3f0
    u32 mFogLine;  // offset: 0x3f4
    u32 mNorthAxis;  // offset: 0x3f8
    u32 mTime;  // offset: 0x3fc
    bool mUseFog;  // offset: 0x400
    uSkyFog* mpFogUnit;  // offset: 0x408
    u32 mFogUnitLine;  // offset: 0x410
    MtVector3 mFogSunColorScale;  // offset: 0x420
    f32 mFogRayleighScale;  // offset: 0x430
    f32 mFogMieScale;  // offset: 0x434
    u32 mConstantBufferFlag;  // offset: 0x438
    u32 mSubScenePriority;  // offset: 0x43c
    u32 mStarRandomSeed;  // offset: 0x440
    u32 mStarNum;  // offset: 0x444
    nDraw::VertexBuffer* mpStarVertexBuffer;  // offset: 0x448
    nDraw::IndexBuffer* mpStarIndexBuffer;  // offset: 0x450
    rTexture* mpStarTexture;  // offset: 0x458
    f32 mStarSize;  // offset: 0x460
    f32 mStarIntensity;  // offset: 0x464
    rStarCatalog* mpStarCatalog;  // offset: 0x468
    nDraw::Texture* mpStarrySkyColorTexture;  // offset: 0x470
    f32 mStarrySkyIntensity;  // offset: 0x478
    f32 mTwinkleAmplitude;  // offset: 0x47c
    bool mMoonEnable;  // offset: 0x480
    MtVector3 mMoonDirection;  // offset: 0x490
    MtVector3 mMoonColor;  // offset: 0x4a0
    MtMatrix mMoonRotMat;  // offset: 0x4b0
    u32 mDivX;  // offset: 0x4f0
    u32 mDivY;  // offset: 0x4f4
    bool mCorrectHorizon;  // offset: 0x4f8
public:
    static MyDTI DTI;
};

class uSkyFog : public uFog
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
    uSkyFog(uSky* psky);
    virtual ~uSkyFog();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setState(cDraw* pdraw);  // vtable slot 24
private:
    uSky* mpSkyUnit;  // offset: 0x1c0
public:
    static MyDTI DTI;
};
