#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtHermiteCurve;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSize;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
namespace nDraw { class BlendState; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { class Texture; }
class rTexture;
class uCameraGame;

// Declarations
class uBloomFilter;
class uColorCorrectFilter;
class uDOFFilter;
class uFilter;
class uGodRaysFilter;
class uMotionBlurFilter;
class uRadialBlurFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class uFilter : public cUnit
{
public:
    enum PASS
    {
        PASS_SOLID = 1,
        PASS_TRANSPARENT = 3,
        PASS_DISTORTION = 4,
        PASS_FILTER = 5,
        PASS_SCREEN = 6,
    };
    enum BS_TYPE
    {
        BS_DISABLE = 0,
        BS_BLENDALPHA = 1,
        BS_BLENDADD = 2,
        BS_BLENDSUB = 3,
        BS_ADD = 4,
        BS_SUB = 5,
        BS_MAX = 6,
        BS_MIN = 7,
        BS_BLENDINVALPHA = 8,
        BS_BLENDADDINV = 9,
        BS_BLENDSUBINV = 10,
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
    uFilter();
    virtual ~uFilter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    void setPass(PASS pass);
    u32 getPass();
    void setPriority(u32 pri);
    u32 getPriority();
    static void copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size);
    static void drawRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size);
    static void setSampleCount(cDraw* pdraw, u32 nSamples);
    static void drawImage(cDraw* pdraw, const MtRect& dstRect, const MtRect& srcRect, const MtSize& srcTex, MtColor c, f32 tl, f32 tt, f32 tw, f32 th);
    static void drawImage(cDraw* pdraw, f32 off_x, f32 off_y, MtColor c, f32 tl, f32 tt, f32 tw, f32 th);
    static void setSampleOffsets_GaussBlur(u32 num, f32* poffsets, f32* pweights, u32 w, f32 delta, f32 dispersion);
    void setDrawPass(cDraw* pdraw);
    static f32 calcCullingAngleRate(f32 CullingRate, f32 CullingAngleStart, f32 CullingAngleEnd, bool CullingBothDir, bool CullingOverlap, const MtVector3& CameraDir, const MtVector3& ParticleDir);
    static f32 calcScreenAttenuate(cDraw* pDraw, f32 ScreenAttenuateRate, f32 ScreenAttenuateDist, const MtVector3& Pos);
    u32 getScreenLayer() const;
    void setScreenLayer(u32 layer);
private:
    static f32 GaussianDistribution(f32 x, f32 y, f32 rho);
protected:
    u16 mPass;  // offset: 0x48
    u32 mPriority;  // offset: 0x4c
    u32 mScreenLayer;  // offset: 0x50
public:
    static MyDTI DTI;
};

class uGodRaysFilter : public uFilter
{
public:
    enum MODE
    {
        MODE_POLAR = 0,
        MODE_ORTHONORMAL = 1,
        MODE_ORTHONORMAL_FAST = 2,
        MODE_TK_VERSION = 3,
    };
    enum QUALITY_LEVEL
    {
        QUALITY_HIGH = 0,
        QUALITY_NORMAL = 1,
        QUALITY_FAST = 2,
    };
public:
    class MyDTI;
    class GodRaysParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class GodRaysParam
    {
    public:
        void init();
        void update(const uGodRaysFilter::GodRaysParam& Param);
        void createTextures(uFilter* pOwner);
        void releaseTextures();
        bool isTexturesCreated() const;
    public:
        MtVector4 mColor;  // offset: 0x0
        MtVector3 mDirection;  // offset: 0x10
        MtVector3 mPoint;  // offset: 0x20
        u32 mMode : 4;  // offset: 0x30
        u32 mQuality : 4;  // offset: 0x30
        u32 mIterativeNum : 8;  // offset: 0x30
        u32 mUsePoint : 1;  // offset: 0x30
        u32 mUseLDR : 1;  // offset: 0x30
        u32 mCutoff : 1;  // offset: 0x30
        u32 mShadow : 1;  // offset: 0x30
        u32 mGray : 1;  // offset: 0x30
        u32 mPadding0332 : 3;  // offset: 0x30
        u32 mCullingEnable : 1;  // offset: 0x30
        u32 mCullingBothDir : 1;  // offset: 0x30
        u32 mCullingOverlap : 1;  // offset: 0x30
        u32 mScreenAttenuateFlag : 1;  // offset: 0x30
        u32 mOcclusionAlphaEnable : 1;  // offset: 0x30
        u32 mOcclusionBlurWidthEnable : 1;  // offset: 0x30
        u32 mPadding0233 : 2;  // offset: 0x30
        f32 mMaskRadius;  // offset: 0x34
        f32 mMaskWeight;  // offset: 0x38
        f32 mDecay;  // offset: 0x3c
        f32 mThreshold;  // offset: 0x40
        f32 mGamma;  // offset: 0x44
        f32 mDirectionLength;  // offset: 0x48
        nDraw::Texture* mpBlur[5];  // offset: 0x50
        nDraw::Texture* mpFinal;  // offset: 0x78
        nDraw::Texture* mpTempTexture;  // offset: 0x80
        f32 mStartZ;  // offset: 0x88
        f32 mEndZ;  // offset: 0x8c
        MtVector3 mCullingDir;  // offset: 0x90
        f32 mCullingAngleStart;  // offset: 0xa0
        f32 mCullingAngleEnd;  // offset: 0xa4
        f32 mCullingRate;  // offset: 0xa8
        f32 mShadowFactor;  // offset: 0xac
        f32 mScale;  // offset: 0xb0
        f32 mShadowThreshold;  // offset: 0xb4
        f32 mScreenAttenuateDist;  // offset: 0xb8
        f32 mScreenAttenuateRate;  // offset: 0xbc
        nDraw::Texture* mpOcclusionFactor;  // offset: 0xc0
        f32 mOcclusionSphereRadius;  // offset: 0xc8
        f32 mOcclusionBlurWidthOffset;  // offset: 0xcc
        f32 mOcclusionBlurWidthScale;  // offset: 0xd0
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
    uGodRaysFilter();
    virtual ~uGodRaysFilter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    void pointEnable(bool);
    bool isPointEnable();
    bool isDirectionEnable();
    void setDirection(const MtVector3& direction);
    void setDirectionLength(const float& length);
    void setPoint(const MtVector3&);
    void setColor(const MtColor&);
    void setColor(const MtVector4& value);
    void setScale(const f32& value);
    void setGamma(const f32& value);
    const MtVector3& getDirection() const;
    const f32& getDirectionLength() const;
    const MtVector3& getPoint() const;
    const MtVector4& getColor() const;
    const f32& getScale() const;
    const f32& getGamma() const;
    static void drawGodRays(cDraw* pdraw, uFilter* pOwner, const GodRaysParam& Param, f32 Transparency);
    static void drawGodRaysPolarCoordinate(cDraw* pdraw, const GodRaysParam& Param);
    static void drawGodRaysOrthonormalCoordinate(cDraw* pdraw, const GodRaysParam& Param);
    static void drawGodRaysOrthonormalCoordinateFast(cDraw* pdraw, const GodRaysParam& Param);
    bool isPolar();
    bool isOrthonormal();
    void setMode(u32 mode);
    u32 getMode();
    void setLevel(u32 quality);
    u32 getLevel();
    bool isShadow();
    bool isNotShadow();
    void setShadow(bool b);
    bool isUsePoint();
    void setUsePoint(bool b);
    bool isUseLDR();
    void setUseLDR(bool b);
    bool isCutoff();
    void setCutoff(bool b);
    u32 getIterativeNum();
    void setIterativeNum(u32 IterativeNum);
    bool isGray();
    void setGray(bool b);
    bool isOcclusionFactorEnable();
    bool isOcclusionAlphaEnable();
    void setOcclusionAlphaEnable(bool b);
    bool isOcclusionBlurWidthEnable();
    void setOcclusionBlurWidthEnable(bool b);
    void setDecay(f32);
    void setThreshold(f32);
    void setShadowThreshold(f32);
    void setStartZ(f32);
    void setEndZ(f32);
    void setShadowFactor(f32);
    f32 getDecay() const;
    f32 getThreshold() const;
    f32 getShadowThreshold() const;
    f32 getStartZ() const;
    f32 getEndZ() const;
    f32 getShadowFactor() const;
private:
    GodRaysParam mParam;  // offset: 0x60
    bool mUpdate;  // offset: 0x140
public:
    static const u32 MAX_LEVEL = 5;
    static MyDTI DTI;
};

class uMotionBlurFilter : public uFilter
{
public:
    enum SAMPLE_LEVEL
    {
        SAMPLE_4 = 0,
        SAMPLE_8 = 1,
        __SAMPLE_LEVEL__U32 = -1,
    };
    enum RESOLUTION
    {
        RESOLUTION_FULL = 0,
        RESOLUTION_THREE_QUARTER = 1,
        RESOLUTION_TWO_THIRD = 2,
        RESOLUTION_HALF = 3,
        __RESOLUTION__U32 = -1,
    };
    enum VRESOLUTION
    {
        VRESOLUTION_FULL = 0,
        VRESOLUTION_HALF = 1,
        VRESOLUTION_ONE_THIRD = 2,
        VRESOLUTION_ONE_QUARTER = 3,
        __VRESOLUTION__U32 = -1,
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
    uMotionBlurFilter();
    virtual ~uMotionBlurFilter();
    virtual void sync();  // vtable slot 11
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setDepthLimit(f32);
    f32 getDepthLimit();
    void setStretchBlur(bool);
    bool isStretchBlur();
    void setFullSceneBlurDesc(f32, f32, f32);
    void setStretchBlurDesc(f32, f32, f32);
    void setReconstructBlur(bool enable);
    bool isReconstructBlur() const;
protected:
    void drawStretchBlur(cDraw* pdraw);
    void drawReconstructBlur(cDraw* pdraw);
protected:
    nDraw::Texture* mpTempTexture;  // offset: 0x58
    nDraw::Texture* mpBlurTempTexture;  // offset: 0x60
    nDraw::Texture* mpVelocityMap;  // offset: 0x68
    nDraw::Texture* mpVelocityDepthMap;  // offset: 0x70
    nDraw::Texture* mpTileMax;  // offset: 0x78
    nDraw::Texture* mpNeighborMax;  // offset: 0x80
    f32 mDepthLimit;  // offset: 0x88
    f32 mFBLimit;  // offset: 0x8c
    f32 mFBScale;  // offset: 0x90
    f32 mFBDepthBias;  // offset: 0x94
    bool mStretchBlur;  // offset: 0x98
    bool mCameraBlur;  // offset: 0x99
    bool mMedianBlur;  // offset: 0x9a
    bool mReconstructBlur;  // offset: 0x9b
    u32 mFeedbackNum;  // offset: 0x9c
    SAMPLE_LEVEL mSampleLevel;  // offset: 0xa0
    RESOLUTION mResolution;  // offset: 0xa4
    RESOLUTION mPrevFrameResolution;  // offset: 0xa8
    VRESOLUTION mVelocityResolution;  // offset: 0xac
    VRESOLUTION mPrevFrameVelocityResolution;  // offset: 0xb0
    f32 mOBLimit;  // offset: 0xb4
    f32 mSBScale;  // offset: 0xb8
    f32 mSBDepthBias;  // offset: 0xbc
    f32 mRBScale;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class uRadialBlurFilter : public uFilter
{
public:
    enum MODE
    {
        MODE_2D = 0,
        MODE_3D = 1,
        MODE_3DZ = 2,
        MODE_2D_NORMAL = 3,
        MODE_3D_NORMAL = 4,
        MODE_3DZ_NORMAL = 5,
    };
public:
    class MyDTI;
    class RadialBlurParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class RadialBlurParam
    {
    public:
        void init();
        void update(const uRadialBlurFilter::RadialBlurParam& Param);
        void createTextures(uFilter* pOwner);
        void releaseTextures();
        bool isTexturesCreated() const;
    public:
        MtVector4 mCenter;  // offset: 0x0
        MtVector3 mPos;  // offset: 0x10
        MtVector4 mColor;  // offset: 0x20
        MtVector4 mMaskRectUV;  // offset: 0x30
        u32 mMode : 8;  // offset: 0x40
        u32 mSamples : 8;  // offset: 0x40
        u32 mBlendStateType : 8;  // offset: 0x40
        u32 mMaskRectEnable : 8;  // offset: 0x40
        f32 mBlurStart;  // offset: 0x44
        f32 mBlurWidth;  // offset: 0x48
        f32 mBrightThreshold;  // offset: 0x4c
        f32 mStartZ;  // offset: 0x50
        f32 mEndZ;  // offset: 0x54
        f32 mStartH;  // offset: 0x58
        f32 mEndH;  // offset: 0x5c
        f32 mStartW;  // offset: 0x60
        f32 mEndW;  // offset: 0x64
        f32 mMaskScale;  // offset: 0x68
        rTexture* mpMaskTexture;  // offset: 0x70
        MtVector3 mCullingDir;  // offset: 0x80
        f32 mCullingAngleStart;  // offset: 0x90
        f32 mCullingAngleEnd;  // offset: 0x94
        f32 mCullingRate;  // offset: 0x98
        u32 mCullingEnable : 8;  // offset: 0x9c
        u32 mCullingBothDir : 8;  // offset: 0x9c
        u32 mCullingOverlap : 8;  // offset: 0x9c
        u32 mScreenAttenuateFlag : 1;  // offset: 0x9c
        u32 mOcclusionBlurWidthEnable : 1;  // offset: 0x9c
        u32 mOcclusionAlphaEnable : 1;  // offset: 0x9c
        u32 padding058f : 5;  // offset: 0x9c
        f32 mScreenAttenuateDist;  // offset: 0xa0
        f32 mScreenAttenuateRate;  // offset: 0xa4
        nDraw::Texture* mpOcclusionFactor;  // offset: 0xa8
        f32 mOcclusionSphereRadius;  // offset: 0xb0
        f32 mOcclusionBlurWidthOffset;  // offset: 0xb4
        f32 mOcclusionBlurWidthScale;  // offset: 0xb8
        nDraw::Texture* mpLinearRTexture;  // offset: 0xc0
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
    uRadialBlurFilter();
    virtual ~uRadialBlurFilter();
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setMode(u32 m);
    u32 getMode();
    void setBlurStart(f32);
    void setBlurWidth(f32);
    u32 getSamples();
    void setSamples(u32 n);
    void setCenter(const MtVector4&);
    const MtVector4 getCenter();
    void setWPos(const MtVector3&);
    const MtVector3 getWPos();
    void setColor(const MtVector4&);
    void setBrightThreshold(f32);
    const MtVector4 getColor() const;
    f32 getBrightThreshold() const;
    void setBlendStateType(u32 t);
    u32 getBlendStateType();
    rTexture* getMaskTexture();
    void setMaskTexture(rTexture* ptex);
    const MtFloat2 getMaskLT();
    void setMaskLT(const MtFloat2& v);
    const MtFloat2 getMaskRB();
    void setMaskRB(const MtFloat2& v);
    bool isOcclusionFactorEnable();
    bool isOcclusionBlurWidthEnable();
    void setOcclusionBlurWidthEnable(bool b);
    bool isOcclusionAlphaEnable();
    void setOcclusionAlphaEnable(bool b);
    static void drawRadialBlur(cDraw* pdraw, uFilter* pOwner, const RadialBlurParam& Param, f32 Transparency);
protected:
    RadialBlurParam mParam;  // offset: 0x60
public:
    static MyDTI DTI;
};

class uBloomFilter : public uFilter
{
public:
    class MyDTI;
    class BloomParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class BloomParam
    {
    public:
        void init();
        void update(const uBloomFilter::BloomParam& Param);
        void createTextures(uFilter* pOwner);
        void releaseTextures();
        bool isTexturesCreated() const;
        f32 getAttenuationStartZ() const;
        void setAttenuationStartZ(f32 StartZ);
        f32 getAttenuationEndZ() const;
        void setAttenuationEndZ(f32 EndZ);
        void setAttenuation(f32 StartZ, f32 EndZ);
    public:
        nDraw::Texture* mpRTGlareTemp[4];  // offset: 0x0
        nDraw::Texture* mpRTBloom[4];  // offset: 0x20
        MtVector3 mBloomColor;  // offset: 0x40
        f32 mBloomDispersion;  // offset: 0x50
        f32 mBloomThreshold;  // offset: 0x54
        f32 mStartZ;  // offset: 0x58
        f32 mEndZ;  // offset: 0x5c
        MtVector3 mPos;  // offset: 0x60
        MtVector3 mCullingDir;  // offset: 0x70
        f32 mCullingAngleStart;  // offset: 0x80
        f32 mCullingAngleEnd;  // offset: 0x84
        f32 mCullingRate;  // offset: 0x88
        f32 mScreenAttenuateDist;  // offset: 0x8c
        f32 mScreenAttenuateRate;  // offset: 0x90
        s32 mStencilID;  // offset: 0x94
        bool mAttenuationEnable;  // offset: 0x98
        bool mCullingEnable;  // offset: 0x99
        bool mCullingBothDir;  // offset: 0x9a
        bool mCullingOverlap;  // offset: 0x9b
        bool mScreenAttenuateFlag;  // offset: 0x9c
        bool mConeFilter;  // offset: 0x9d
        bool mLegacy;  // offset: 0x9e
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
    uBloomFilter();
    virtual ~uBloomFilter();
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    static void drawBloom(cDraw* pdraw, uFilter* pOwner, const BloomParam& Param, f32 Transparency);
    MtVector3 getColor() const;
    void setColor(const MtVector3&);
    void setThrethold(f32);
    f32 getThrethold() const;
    f32 getAttenuationStartZ() const;
    void setAttenuationStartZ(f32);
    f32 getAttenuationEndZ() const;
    void setAttenuationEndZ(f32);
    void setAttenuation(f32, f32);
    bool getCTREmulation() const;
    void setCTREmulation(bool);
protected:
    static void drawBloomPass(cDraw* pdraw, uFilter* pOwner, const BloomParam& Param);
private:
    BloomParam mParam;  // offset: 0x60
public:
    static MyDTI DTI;
    static const u32 MAX_MTGLEVEL = 4;
private:
    static bool mCTREmulation;
};

class uColorCorrectFilter : public uFilter
{
public:
    class MyDTI;
    class Corrector;
    struct Params;
    class ColorCorrectParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Params
    {
    public:
        void init();
        MtMatrix getMatrix() const;
        bool isEnable() const;
        void setEnable(bool);
        u32 getType() const;
        void setType(u32 type);
        MtVector3 getFactor() const;
        void setFactor(const MtVector3& v);
        MtVector3 getFactor2() const;
        void setFactor2(const MtVector3&);
    public:
        bool mEnable;  // offset: 0x0
        u32 mType;  // offset: 0x4
        MtVector3 mFactor;  // offset: 0x10
        MtVector3 mFactor2;  // offset: 0x20
    };
public:
    class ColorCorrectParam
    {
    public:
        void init();
        void update(const uColorCorrectFilter::ColorCorrectParam& Param);
        void createTextures();
        void releaseTextures();
        bool isTexturesCreated() const;
        uColorCorrectFilter::Params* getCorrectorParams(u32 index);
        MtVector3 getPosition() const;
        void setPosition(const MtVector3& Pos);
        MtVector3 getGamma() const;
        void setGamma(const MtVector3& Gamma);
        f32 getAttenuationStartZ() const;
        void setAttenuationStartZ(f32 StartZ);
        f32 getAttenuationEndZ() const;
        void setAttenuationEndZ(f32 EndZ);
        void setAttenuation(f32 StartZ, f32 EndZ);
        void updateMatrix();
        rTexture* getVolumeColorCorrect();
        void setVolumeColorCorrect(rTexture* ptex);
    public:
        uColorCorrectFilter::Params mParams[16];  // offset: 0x0
        MtVector3 mPos;  // offset: 0x300
        MtMatrix mMatrix;  // offset: 0x310
        MtHermiteCurve mToneCurveR;  // offset: 0x350
        MtHermiteCurve mToneCurveG;  // offset: 0x390
        MtHermiteCurve mToneCurveB;  // offset: 0x3d0
        MtVector3 mGamma;  // offset: 0x410
        nDraw::Texture* mpToneMap;  // offset: 0x420
        f32 mStartZ;  // offset: 0x428
        f32 mEndZ;  // offset: 0x42c
        u32 mAttenuationEnable;  // offset: 0x430
        MtVector3 mCullingDir;  // offset: 0x440
        f32 mCullingAngleStart;  // offset: 0x450
        f32 mCullingAngleEnd;  // offset: 0x454
        f32 mCullingRate;  // offset: 0x458
        bool mCullingEnable;  // offset: 0x45c
        bool mCullingBothDir;  // offset: 0x45d
        bool mCullingOverlap;  // offset: 0x45e
        bool mScreenAttenuateFlag;  // offset: 0x45f
        f32 mScreenAttenuateDist;  // offset: 0x460
        f32 mScreenAttenuateRate;  // offset: 0x464
        u32 mVolumeInterpolateQuality;  // offset: 0x468
        rTexture* mpVolumeColorCorrect;  // offset: 0x470
    };
public:
    class Corrector : public MtObject
    {
    public:
        enum TYPE
        {
            TYPE_UNUSED = 0,
            TYPE_HUE = 1,
            TYPE_CONTRAST = 2,
            TYPE_CONTRAST2 = 3,
            TYPE_CHROMA = 4,
            TYPE_CHROMA2 = 5,
            TYPE_BRIGHTNESS = 6,
            TYPE_BRIGHTNESS2 = 7,
            TYPE_SCALE = 8,
            TYPE_SCALE2 = 9,
            TYPE_INPUTLEVEL = 10,
            TYPE_INPUTLEVEL2 = 11,
            TYPE_OUTPUTLEVEL = 12,
            TYPE_OUTPUTLEVEL2 = 13,
            TYPE_SEPIA = 14,
            TYPE_SEPIA2 = 15,
            TYPE_NEGA = 16,
            TYPE_NEGA2 = 17,
            TYPE_GRAYSCALE = 18,
            TYPE_RREPLACE = 19,
            TYPE_GREPLACE = 20,
            TYPE_BREPLACE = 21,
            TYPE_ADD = 22,
            TYPE_SUB = 23,
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
        Corrector();
        virtual ~Corrector() {}
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MtMatrix getMatrix() const;
        bool isEnable() const;
        void setEnable(bool);
        u32 getType() const;
        void setType(u32);
        MtVector3 getFactor() const;
        void setFactor(const MtVector3&);
        MtVector3 getFactor2() const;
        void setFactor2(const MtVector3&);
    protected:
        uColorCorrectFilter::Params mParams;  // offset: 0x10
    public:
        static MyDTI DTI;
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
    uColorCorrectFilter();
    virtual ~uColorCorrectFilter();
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    Corrector* getCorrector(u32);
    MtVector3 getGamma() const;
    void setGamma(const MtVector3&);
    f32 getAttenuationStartZ() const;
    void setAttenuationStartZ(f32 StartZ);
    f32 getAttenuationEndZ() const;
    void setAttenuationEndZ(f32 EndZ);
    void setAttenuation(f32, f32);
    static void drawColorCorrect(cDraw* pdraw, uFilter* pOwner, const ColorCorrectParam& Param, f32 Transparency);
protected:
    void setToneCurve(const MtHermiteCurve& curve);
    MtHermiteCurve getToneCurve();
protected:
    Corrector mCorrector[16];  // offset: 0x60
    ColorCorrectParam mParam;  // offset: 0x460
public:
    static MyDTI DTI;
    static const u32 MAX_CORRECTOR = 16;
};

class uDOFFilter : public uFilter
{
    friend class uCameraGame;
public:
    enum DOF_TYPE
    {
        DOF_DETAIL = 0,
        DOF_SIMPLE = 1,
        DOF_SIMPLE2 = 2,
    };
    enum BLUR_TYPE
    {
        BLUR_POINTSAMPLE = 0,
        BLUR_LINEARSAMPLE = 1,
        BLUR_OLD = 2,
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
    uDOFFilter();
    virtual ~uDOFFilter();
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setGSDOF(bool enable);
    bool isGSDOF() const;
    u32 getBlurCount();
    void setBlurCount(u32 n);
    f32 getNear();
    void setNear(f32 f);
    f32 getFar();
    void setFar(f32 f);
    f32 getFocal();
    void setFocal(f32 f);
    f32 getBlurSize();
    void setBlurSize(f32);
    f32 getAperture();
    void setAperture(f32);
    f32 getFocalLength();
    void setFocalLength(f32);
    f32 getFarBlurLimit();
    void setFarBlurLimit(f32 f);
    f32 getNearBlurLimit();
    void setNearBlurLimit(f32 f);
    const MtVector3& getGradateColor() const;
    void setGradateColor(const MtVector3&);
    f32 getLowCoCScale() const;
    void setLowCoCScale(f32);
    bool getSimple_Convert();
    void setSimple_Convert(bool);
protected:
    void drawNormalDOF(cDraw* pdraw);
    void drawGSDOF(cDraw* pdraw);
protected:
    u32 mBlurCount;  // offset: 0x54
    u32 mType;  // offset: 0x58
    u32 mBlurType;  // offset: 0x5c
    bool mSimple;  // offset: 0x60
    bool mbGSDOF;  // offset: 0x61
    MtVector3 mGradateColor;  // offset: 0x70
    f32 mBlurSize;  // offset: 0x80
    nDraw::Texture* mpTempTexture[2];  // offset: 0x88
    f32 mAperture;  // offset: 0x98
    f32 mFocalLength;  // offset: 0x9c
    f32 mLowCoCScale;  // offset: 0xa0
    f32 mCoCScale;  // offset: 0xa4
    f32 mCoCBias;  // offset: 0xa8
    f32 mFarBlurLimit;  // offset: 0xac
    f32 mNearBlurLimit;  // offset: 0xb0
    f32 mNear;  // offset: 0xb4
    f32 mFar;  // offset: 0xb8
    f32 mFocal;  // offset: 0xbc
    nDraw::Texture* mpTempAccTexture;  // offset: 0xc0
    nDraw::BlendState* mpGSDOFBlendState;  // offset: 0xc8
    nDraw::DepthStencilState* mpGSDOFDepthState;  // offset: 0xd0
    rTexture* mpDiaphragm;  // offset: 0xd8
public:
    static MyDTI DTI;
};

inline void* uBloomFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uColorCorrectFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline f32 uColorCorrectFilter::getAttenuationStartZ() const {
    return this->mParam.mStartZ;
}

inline f32 uColorCorrectFilter::getAttenuationEndZ() const {
    return this->mParam.mEndZ;
}

inline void* uColorCorrectFilter::Corrector::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uDOFFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uDOFFilter::isGSDOF() const {
    return this->mbGSDOF;
}

inline u32 uDOFFilter::getBlurCount() {
    return this->mBlurCount;
}

inline void* uFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGodRaysFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uMotionBlurFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uMotionBlurFilter::isReconstructBlur() const {
    return this->mReconstructBlur;
}

inline void* uRadialBlurFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rTexture* uRadialBlurFilter::getMaskTexture() {
    return this->mParam.mpMaskTexture;
}

inline void uRadialBlurFilter::setMaskLT(const MtFloat2& v) {
    this->mParam.mMaskRectUV.x = v.x;
    this->mParam.mMaskRectUV.y = v.y;
}

inline void uRadialBlurFilter::setMaskRB(const MtFloat2& v) {
    this->mParam.mMaskRectUV.z = v.x;
    this->mParam.mMaskRectUV.w = v.y;
}
