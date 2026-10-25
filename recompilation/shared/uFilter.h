#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtHermiteCurve;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSize;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class BlendState; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { class Texture; }
class rTexture;
class uCameraGame;

// Declarations
class uColorCorrectFilter;
class uDOFFilter;
class uFilter;
class uMotionBlurFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
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
        // Address: 0x01b5eb60 - 0x01b5eb61 (1 bytes)
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
    // inferred: uCameraGame::setDOFFilterNearBlurLimit names uDOFFilter::mNearBlurLimit
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
