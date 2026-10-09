#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cUnit.h"
#include "nDrawRasterizerState.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
struct MtFloat3x4;
struct MtFloat4;
struct MtFloat4x4;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cConvexBoundingVolume;
class cDraw;
namespace nDraw { struct RASTERIZER_DESC; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class Texture; }
class uLight;

// Declarations
class uShadow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using size_t = _Sizet;
using u64 = __uint64_t;
using uintptr = __uintptr_t;

class uShadow : public cUnit
{
public:
    enum SHADOW_MAP_TYPE
    {
        SHADOW_DEPTH_MAP = 0,
        SHADOW_VARIANCE_MAP = 1,
    };
    enum PCF_FILTER
    {
        PCF_BILINEAR_2x2 = 0,
        PCF_BILINEAR_3x3 = 1,
        PCF_BILINEAR_4x4 = 2,
    };
    enum VSM_BLUR_TYPE
    {
        VSM_BLUR_GAUS_5x5 = 0,
        VSM_BLUR_GAUS_7x7 = 1,
        VSM_BLUR_GAUS_9x9 = 2,
        VSM_BLUR_GAUS_11x11 = 3,
        VSM_BLUR_BOX_5x5 = 4,
        VSM_BLUR_BOX_9x9 = 5,
        VSM_BLUR_BOX_13x13 = 6,
    };
    enum MANAGED_TYPE
    {
        MANAGED_TYPE_DISABLE = 0,
        MANAGED_TYPE_CULLING = 1,
        MANAGED_TYPE_ALLOCATION_CULLING = 2,
    };
    enum SHADOW_TYPE
    {
        SHADOW_TYPE_LSM = 0,
        SHADOW_TYPE_SSM = 1,
        SHADOW_TYPE_UNIFORM = 2,
        SHADOW_TYPE_SPOT = 3,
        SHADOW_TYPE_POINT = 4,
    };
public:
    class MyDTI;
    struct DynamicState;
    struct ShadowMap;
    struct ShadowReceiveParam;
    struct ShadowViewIndependentReceiveState;
    class cHardwareDispCtrlShadow;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DynamicState
    {
    public:
        u32 mShadowGroup;  // offset: 0x0
        f32 mShadowDepthBias;  // offset: 0x4
        f32 mShadowSlopeScaledDepthBias;  // offset: 0x8
        f32 mShadowViewDistance;  // offset: 0xc
        f32 mNearClipDistance;  // offset: 0x10
        f32 mAlphaThreshold;  // offset: 0x14
        f32 mBorderGradation;  // offset: 0x18
    };
public:
    struct ShadowMap
    {
    public:
        enum DrawMode
        {
            DrawModeNormal = 0,
            DrawModeStaticOnly = 1,
            DrawModeDynamicOnly = 2,
        };
    public:
        nDraw::Texture* shadowMap;  // offset: 0x0
        nDraw::Texture* depthStencil;  // offset: 0x8
        MtMatrix view;  // offset: 0x10
        MtMatrix proj;  // offset: 0x50
        MtRect viewport;  // offset: 0x90
        bool clearShadowMap;  // offset: 0xa0
        MtVector3* frustumVertices;  // offset: 0xa8
        DrawMode drawMode;  // offset: 0xb0
    };
public:
    struct alignas(8) ShadowReceiveParam
    {
    public:
        MtFloat3 lightPos;  // offset: 0x0
        f32 lightRangeInverse;  // offset: 0xc
        f32 distanceBias;  // offset: 0x10
        MtFloat3 lightDir;  // offset: 0x14
        MtFloat4 range;  // offset: 0x20
        MtFloat4x4 projectNear;  // offset: 0x30
        MtFloat4x4 projectMiddle;  // offset: 0x70
        MtFloat4x4 projectFar;  // offset: 0xb0
        MtFloat2 distanceAttn;  // offset: 0xf0
        MtFloat2 angularAttn;  // offset: 0xf8
        MtFloat2 cubeFaceOffset;  // offset: 0x100
        MtFloat2 cubeFaceScale;  // offset: 0x108
        MtFloat4 mapSize;  // offset: 0x110
        MtFloat3x4 rangeMat;  // offset: 0x120
        f32 faceIncreaseAttn;  // offset: 0x150
        f32 faceDecreaseAttn;  // offset: 0x154
        f32 distanceScaledDepthBias;  // offset: 0x158
        f32 varianceEpsilon;  // offset: 0x15c
        f32 pmaxPower;  // offset: 0x160
        f32 nearPlane;  // offset: 0x164
        f32 attn;  // offset: 0x168
    };
public:
    struct ShadowViewIndependentReceiveState
    {
    public:
        SO_HANDLE FShadowReceive;  // offset: 0x0
        SO_HANDLE FShadowReceiveRT;  // offset: 0x4
        SO_HANDLE FShadowMultiReceiveRT;  // offset: 0x8
        SO_HANDLE FShadowFilter;  // offset: 0xc
        SO_HANDLE FShadowFilterPoint;  // offset: 0x10
        SO_HANDLE FShadowLightFace;  // offset: 0x14
        SO_HANDLE FShadowReceiveAttn;  // offset: 0x18
        SO_HANDLE SSShadowVariance;  // offset: 0x1c
    };
public:
    class cHardwareDispCtrlShadow : public cUnit::cHardwareDispCtrl
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
        cHardwareDispCtrlShadow();
        cHardwareDispCtrlShadow(cUnit* pOwner);
        // Address: 0x01b64410 - 0x01b64411 (1 bytes)
        virtual ~cHardwareDispCtrlShadow() {}
        virtual void update();  // vtable slot 7
        virtual bool isDispOperateHard();  // vtable slot 8
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
    uShadow();
    virtual ~uShadow();
    virtual void setup();  // vtable slot 6
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    void setupReceiver(cDraw* pdraw, bool enableFrustum, bool enableLimitRange);
    virtual bool isShadowed(const MtSphere& boundary) const;  // vtable slot 24
    void setShadowReceiveState(cDraw* pdraw, u32 slot);
    static void setNullShadowReceiveState(cDraw* pdraw, u32 slot);
    void setShadowDepthBias(f32 b);
    f32 getShadowDepthBias() const;
    f32 getShadowDistanceScaledDepthBias() const;
    void setShadowDistanceScaledDepthBias(f32 b);
    f32 getShadowSlopeScaledDepthBias() const;
    void setShadowSlopeScaledDepthBias(f32 b);
    f32 getShadowViewDistance() const;
    void setShadowViewDistance(f32 distance);
    const MtVector4& getShadowViewSize() const;
    void setShadowViewSize(const MtVector4&);
    f32 getBackforwardViewDistance() const;
    void setBackforwardViewDistance(f32 v);
    f32 getAlphaThreshold() const;
    void setAlphaThreshold(f32);
    u32 getShadowType() const;
    void setShadowMapType(u32 type);
    u32 getShadowMapType() const;
    void setPCFType(u32 p);
    u32 getPCFType() const;
    void setMapSize(u32 size);
    u32 getMapSize() const;
    u32 getMapSizeTrue() const;
    void setDispersion(f32 d);
    f32 getDispersion() const;
    void setVSMBlurType(u32 t);
    u32 getVSMBlurType() const;
    void setStandBy(bool s);
    bool getStandBy() const;
    u32 getShadowGroup() const;
    void setShadowGroup(u32);
    bool isLimitRangeEnable() const;
    void setLimitRangeEnable(bool enable);
    virtual bool getLimitRangeOBB(MtOBB* obb) const;  // vtable slot 25
    // Address: 0x01b0a9d0 - 0x01b0a9d1 (1 bytes)
    virtual void setLimitRangeOBB(const MtOBB& obb) {}  // vtable slot 26
    bool isMappedTo(uLight* light) const;
    bool isMappedToLight() const;
    void setMappedToLight(bool mappedToLight);
    bool isDeferredShadow() const;
    void setDeferredShadow(bool);
    void setTargetLight(uLight* plight);
    void setTargetLightEnable(bool e);
    void setManagedType(u32 type);
    u32 getManagedType() const;
    bool isManagedEnable() const;
    f32 getPriorityBias() const;
    virtual MtSphere getBoundingSphere() const;  // vtable slot 27
    void setShadowMapCacheEnable(bool enable);
    bool isShadowMapCacheEnable() const;
    bool getShadowMapCacheEnable() const;
    void invalidateShadowMapCache(u32 delayFrame);
    bool isValidShadowMapCache() const;
    void setNearClipDistance(f32 distance);
    f32 getNearClipDistance() const;
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
    void reflectSystemValueUpdateMapSize();
    void reflectSystemValueUpdateShadowViewDistance();
protected:
    void createCommonProperty(MtPropertyList& s);
    MtUI* createCommonUI(MtProperty& prop);
    void setFrustum(cDraw* pdraw, const MtMatrix& view, const MtMatrix& proj, f32 f);
    void drawCaster(cDraw* pdraw, ShadowMap& shadowMap);
    void drawInvolvingCaster(cDraw* pdraw, ShadowMap& shadowMap, cUnit* * pInvolveArray, u32& arrayNum, MtSphere& involve_sphere, bool first);
    void drawReceiver(cDraw* pdraw);
    void setupBlurConstant(cDraw* pdraw, u32 size, const MtVector4& uv_min, const MtVector4& uv_max);
    void makeMipMapSubLevel(cDraw* pdraw, nDraw::Texture* ptexture, nDraw::Texture* ptemp, SO_HANDLE func, u32 flag);
    void updateLimitRange();
    void setupTargetLightLimitRange(uLight* light);
    void beginManaged(cDraw* pdraw);
    void checkValidShadowMapCache();
    virtual void createShadowMap() = 0;  // vtable slot 28
    void releaseShadowMap();
    void setCacheIdOffset(uintptr offset);
    uintptr getCacheIdOffset() const;
    uintptr getCacheId() const;
private:
    // Address: 0x01b0aa00 - 0x01b0aa01 (1 bytes)
    virtual void releaseShadowMapSub() {}  // vtable slot 29
    void setupReceiverCommonConstant(ShadowReceiveParam& param) const;
    void setupLimitRange(cDraw* pdraw, bool enable, SO_HANDLE destHandle);
    void setupMultiShadow(cDraw* pdraw);
    // Address: 0x01b64520 - 0x01b64521 (1 bytes)
    virtual void drawSub(cDraw* pdraw) {}  // vtable slot 30
    virtual void setupCasterDrawContext(cDraw* pdraw);  // vtable slot 31
    void drawBlur(cDraw* pdraw, nDraw::Texture* pdepth, const MtRect& rect);
    // Address: 0x01b0aa10 - 0x01b0aa11 (1 bytes)
    virtual void makeMipMap(cDraw* pdraw, nDraw::Texture* pdepth, nDraw::Texture* ptemp) {}  // vtable slot 32
    void setupManaged(u32 viewNum);
    virtual bool getBoundingVolume(cConvexBoundingVolume* * volume) const;  // vtable slot 33
    // Address: 0x01b0aa30 - 0x01b0aa31 (1 bytes)
    virtual void setShadowCasterFrustum(cDraw* pdraw, const MtVector3* frustumVertices) const {}  // vtable slot 34
    virtual void beginBranchCaster(cDraw* pdraw, ShadowMap& shadowMap);  // vtable slot 35
    void beginDrawCaster(cDraw* pdraw, nDraw::Texture* pdepth, nDraw::Texture* pDepthStencil, const MtMatrix& vm, const MtMatrix& pm, const MtRect& vp, bool clear);
    void endDrawCaster(cDraw* pdraw, ShadowMap& shadowMap);
    virtual bool checkValidShadowMapCacheSub();  // vtable slot 36
    // Address: 0x01b64530 - 0x01b64531 (1 bytes)
    virtual void setupViewIndependentReceiveState(ShadowViewIndependentReceiveState& state) const {}  // vtable slot 37
    // Address: 0x01b64540 - 0x01b64541 (1 bytes)
    virtual void setupViewDependentReceiveState(cDraw* pdraw, ShadowReceiveParam& param, bool enableFrustum) {}  // vtable slot 38
    void setBlurParam();
    void setGaussianFilter();
    void setBoxFilter();
    void releaseCashID();
    bool isDrawShadowMapCache();
public:
    bool getTargetLightEnable();
    uLight* getTargetLight();
    virtual cUnit::cHardwareDispCtrl* createHardwareDispCtrl();  // vtable slot 23
    void setPS3DisableMode(bool set);
    void setPS4DisableMode(bool set);
    void setPCDisableMode(bool set);
    bool getPS3DisableMode();
    bool getPS4DisableMode();
    bool getPCDisableMode();
protected:
    nDraw::Texture* mpDepthMap;  // offset: 0x48
    nDraw::Texture* mpTempMap;  // offset: 0x50
    nDraw::Texture* mpDepthTempMap;  // offset: 0x58
    nDraw::Texture* mpDepthStencil;  // offset: 0x60
    nDraw::Texture* mpDepthMapCache;  // offset: 0x68
    nDraw::Texture* mpDepthStencilCache;  // offset: 0x70
    f32 mShadowViewDistance;  // offset: 0x78
    MtVector4 mShadowViewSize;  // offset: 0x80
    f32 mBackforwardViewDistance;  // offset: 0x90
    u32 mShadowType;  // offset: 0x94
    u32 mShadowMapType;  // offset: 0x98
    uLight* mpTargetLight;  // offset: 0xa0
    bool mTargetLightEnable;  // offset: 0xa8
    u32 mMapSize;  // offset: 0xac
    bool mStandBy;  // offset: 0xb0
    bool mInitialized;  // offset: 0xb1
    bool mComparisonEnable;  // offset: 0xb2
    bool mDrawEnable;  // offset: 0xb3
    f32 mShadowAttn;  // offset: 0xb4
private:
    f32 mGaussianFilterWeights[11];  // offset: 0xb8
    f32 mDispersion;  // offset: 0xe4
    u32 mShadowGroup;  // offset: 0xe8
    f32 mShadowDepthBias;  // offset: 0xec
    f32 mShadowSlopeScaledDepthBias;  // offset: 0xf0
    f32 mShadowDistanceScaledDepthBias;  // offset: 0xf4
    f32 mNearClipDistance;  // offset: 0xf8
    f32 mAlphaThreshold;  // offset: 0xfc
    f32 mBorderGradation;  // offset: 0x100
    u32 mPCFType;  // offset: 0x104
    u32 mVSMBlurType;  // offset: 0x108
    f32 mPmaxPower;  // offset: 0x10c
    f32 mVarianceEpsilon;  // offset: 0x110
    nDraw::RasterizerState* mpRasterizerState[3];  // offset: 0x118
    nDraw::RASTERIZER_DESC mRasterizerDesc[3];  // offset: 0x130
    u32 mManagedType;  // offset: 0x160
    f32 mPriorityBias;  // offset: 0x164
    uintptr mCacheID;  // offset: 0x168
    uintptr mCacheIDOffset;  // offset: 0x170
    bool mLimitRangeEnable;  // offset: 0x178
    bool mMappedToLight;  // offset: 0x179
    bool mDeferredShadow;  // offset: 0x17a
    bool mValidShadowMapCache;  // offset: 0x17b
    bool mShadowMapCacheEnable;  // offset: 0x17c
    bool mDrawCache;  // offset: 0x17d
    u32 mCacheCounter;  // offset: 0x180
    u32 mShadowMapCacheSceneHash;  // offset: 0x184
    DynamicState mStateCache;  // offset: 0x188
    u32 mMapSizeOriginal;  // offset: 0x1a4
    f32 mShadowViewDistanceOriginal;  // offset: 0x1a8
    bool mIsPS3Disable;  // offset: 0x1ac
    bool mIsPS4Disable;  // offset: 0x1ad
    bool mIsPCDisable;  // offset: 0x1ae
public:
    static MyDTI DTI;
};
