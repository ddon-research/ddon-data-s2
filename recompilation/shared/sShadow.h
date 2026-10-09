#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "MtPrimitive3D.h"
#include "cSystem.h"
#include "sCamera.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtDTI;
class MtFrustum;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSphere;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class OcclusionQuery; }
namespace nDraw { class Texture; }
class uShadow;

// Declarations
class cShadowPriorityState;
class sShadow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using MT_MFUNCPTRU32 = void(MtObject::*)(void*, u32);
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using uintptr = __uintptr_t;

class sShadow : public cSystem
{
public:
    enum RESOURCE_TYPE
    {
        RESOURCE_TYPE_SPOT = 0,
        RESOURCE_TYPE_POINT = 1,
        RESOURCE_TYPE_MAX_NUM = 2,
    };
public:
    class MyDTI;
    class ResourceGroup;
    class Resource;
    class ViewConsistentResource;
    struct SharedTexture;
    class Bundle;
    class Node;
    class Context;
    class Parameter;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Resource : public MtObject
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u32 getShadowMapSize() const;
        u32 getShadowMapType() const;
        nDraw::Texture* getDepthMap() const;
        nDraw::Texture* getTempMap() const;
        nDraw::Texture* getDepthStencilMap() const;
        bool isDirty() const;
        void clearDirty();
    private:
        Resource();
        // Address: 0x01ba7780 - 0x01ba7781 (1 bytes)
        virtual ~Resource() {}
        void release();
    private:
        u32 mShadowMapSize;  // offset: 0x8
        u32 mShadowMapType;  // offset: 0xc
        nDraw::Texture* mDepthMap;  // offset: 0x10
        nDraw::Texture* mTempMap;  // offset: 0x18
        nDraw::Texture* mDepthStencilMap;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class ViewConsistentResource : public MtObject
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u32 getShadowMapSize() const;
        u32 getShadowMapType() const;
        nDraw::Texture* getDepthMapCache() const;
        nDraw::Texture* getDepthStencilMapCache() const;
        u32 getResourceType() const;
    private:
        ViewConsistentResource();
        // Address: 0x01ba77d0 - 0x01ba77d1 (1 bytes)
        virtual ~ViewConsistentResource() {}
        void release();
    private:
        u32 mShadowMapSize;  // offset: 0x8
        u32 mShadowMapType;  // offset: 0xc
        nDraw::Texture* mDepthMapCache;  // offset: 0x10
        nDraw::Texture* mDepthStencilMapCache;  // offset: 0x18
        u32 mResourceType;  // offset: 0x20
        bool mUsed;  // offset: 0x24
        u32 mIndex;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    struct SharedTexture
    {
    public:
        nDraw::Texture* mRenderTarget;  // offset: 0x0
        nDraw::Texture* mDepthStencil;  // offset: 0x8
    };
public:
    class Bundle
    {
    public:
        void Initialize();
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void setPriority(f32 priority);
        f32 getPriority() const;
        void setNode(sShadow::Node* node);
        sShadow::Node* getNode() const;
        uShadow* getShadowUnit() const;
        void setResourceIndex(u32 index);
        u32 getResourceIndex() const;
    private:
        f32 mPriority;  // offset: 0x0
        sShadow::Node* mpNode;  // offset: 0x8
        u32 mResourceIndex;  // offset: 0x10
    };
public:
    class Node : public MtObject
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
        Node();
        virtual ~Node();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setShadowUnit(uShadow* unit);
        uShadow* getShadowUnit() const;
        f32 getShadowAttenuation(u32 viewNum) const;
        f32 getPriority(u32 viewNum) const;
        void updatePriority(const sShadow& system, const sShadow::Context& context, u32 viewNum);
        bool isExecution(u32 viewNum) const;
        void notifyAllocateResource(u32 viewNum);
        bool takeBackResource(const sShadow& system, u32 viewNum, sShadow::Node* node);
        void updateState(const sShadow& system, u32 viewNum);
        cShadowPriorityState* getPriorityState(u32 viewNum) const;
        void issueOcclusionQuery(const sShadow& system, cDraw* pdraw, u32 viewNum);
        void setMark(bool on);
        bool isMark() const;
        void allocateVCRes();
        void releaseVCRes();
        const sShadow::ViewConsistentResource* getVCResource() const;
    private:
        cShadowPriorityState* createState(uShadow* unit, u32 viewNum) const;
    private:
        uShadow* mpShadow;  // offset: 0x8
        cShadowPriorityState* mpState[8];  // offset: 0x10
        sShadow::ViewConsistentResource* mpVCResource;  // offset: 0x50
        bool mMark;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
public:
    class Context
    {
    public:
        ~Context();
        void updateView(u32 viewNum);
        bool isValid() const;
        u32 getViewNum() const;
        s32 getFrameCount() const;
        const MtRect& getRegion() const;
        const MtMatrix& getViewMat() const;
        const MtMatrix& getProjMat() const;
        const MtMatrix& getViewProjMat() const;
        f32 getNearClipDistance() const;
        f32 getViewDistance(const MtVector3& worldPos) const;
        const MtVector3& getCameraPos() const;
        bool isOutsideFrustum(const MtSphere& sphere) const;
        const MtOBB& getProjectionScreenOBB() const;
    private:
        Context();
    private:
        bool mValid;  // offset: 0x0
        u32 mViewNum;  // offset: 0x4
        MtRect mRegion;  // offset: 0x8
        MtMatrix mView;  // offset: 0x20
        MtMatrix mProj;  // offset: 0x60
        MtMatrix mViewProj;  // offset: 0xa0
        f32 mNearClip;  // offset: 0xe0
        MtVector3 mCameraPos;  // offset: 0xf0
        MtFrustum mFrustum;  // offset: 0x100
        MtOBB mProjectionScreenObb;  // offset: 0x170
    };
public:
    class Parameter
    {
    public:
        Parameter();
        ~Parameter();
        u32 getShadowMapSize() const;
        u32 getShadowMapType() const;
        nDraw::Texture* getDepthMap() const;
        nDraw::Texture* getTempMap() const;
        nDraw::Texture* getDepthStencilMap() const;
        nDraw::Texture* getDepthMapCache() const;
        nDraw::Texture* getDepthStencilMapCache() const;
        f32 getAttenuation() const;
        bool isExecution() const;
    private:
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
    private:
        u32 mViewNum;  // offset: 0x0
        const sShadow::Node* mpNode;  // offset: 0x8
        const sShadow::Resource* mpResource;  // offset: 0x10
    };
public:
    class ResourceGroup : public MtObject
    {
        // inferred: sShadow::getSpotShadowMapSize names sShadow::mResourceGroup[0].mShadowMapSize
        friend class sShadow;
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
        ResourceGroup();
        virtual ~ResourceGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setSystem(sShadow* system);
        void setResourceType(sShadow::RESOURCE_TYPE type);
        sShadow::RESOURCE_TYPE getResourceType() const;
        void setResourceNumber(u32 num);
        u32 getResourceNumber() const;
        void setShadowMapSize(u32 size);
        void reflectSystemValueUpdateMapSize();
        u32 getShadowMapSize() const;
        void setShadowMapType(u32 type);
        u32 getShadowMapType() const;
        void setShadowMapCacheEnable(bool enable);
        bool isShadowMapCacheEnable() const;
        void setCacheEnabledViewNumber(u32 num);
        u32 getCacheEnabledViewNumber() const;
        void acquireResources();
        void releaseResources();
        const sShadow::Resource* getResource(u32 index) const;
        sShadow::ViewConsistentResource* allocateVCResource();
        void releaseVCResource(sShadow::ViewConsistentResource* resource);
        bool isDirty() const;
        void clearDirty();
    private:
        void setResource(sShadow::Resource*, u32 index);
    private:
        sShadow* mSystem;  // offset: 0x8
        u32 mResourceType;  // offset: 0x10
        u32 mResourceNum;  // offset: 0x14
        u32 mShadowMapSizeOriginal;  // offset: 0x18
        u32 mShadowMapSize;  // offset: 0x1c
        u32 mShadowMapType;  // offset: 0x20
        bool mShadowMapCacheEnable;  // offset: 0x24
        bool mInitialized;  // offset: 0x25
        sShadow::Resource* mResources[16];  // offset: 0x28
        sShadow::ViewConsistentResource* mResViewConsistent[32];  // offset: 0xa8
        u32 mCachedViewNum;  // offset: 0x1a8
        u32 mVcrIndex;  // offset: 0x1ac
        u32 mAllocTable[32];  // offset: 0x1b0
        sShadow::SharedTexture mSharedTexture;  // offset: 0x230
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
    static sShadow* createInstance();
    static void deleteInstance();
    static sShadow* getInstance();
    static uintptr AllocShadowCacheID(const uintptr req_cache_id);
    static void FreeShadowCacheID(const uintptr cache_id);
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void attach(uShadow* unit);
    void detach(uShadow* unit);
    bool requestResource(u32 viewNum, const uShadow* unit, Parameter& param);
    bool queryExecution(u32 viewNum, const uShadow* unit, f32& attenuation);
    void issueOcclusionQuery(cDraw* pdraw, const uShadow* unit);
    void setupManagedShadow(cDraw* pdraw);
    void setResourceNumber(u32 num);
    u32 getResourceNumber() const;
    void setCacheEnabledViewNumber(u32 num);
    u32 getCacheEnabledViewNumber() const;
    void setManagementEnable(bool);
    bool isManagementEnable() const;
    void setQueryEnable(bool);
    bool isQueryEnable() const;
    bool isQueryDispEnable() const;
    void setQueryFrameLatencyTolerance(u32);
    u32 getQueryFrameLatencyTolerance() const;
    void setQueryVisibleThresholdPixelNumber(u32);
    u32 getQueryVisibleThresholdPixelNumber() const;
    void setFadeDistance(f32 distance);
    f32 getFadeDistance() const;
    void setVisibleDistance(f32 distance);
    f32 getVisibleDistance() const;
    void setAttenuationDelta(f32);
    f32 getAttenuationDelta() const;
    void setBlendWeightPriority(f32);
    f32 getBlendWeightPriority() const;
    void setThresholdPriorityDelta(f32);
    f32 getThresholdPriorityDelta() const;
    void invalidateAllShadowMapCache();
    void setShadowMapCacheEnable(bool enable);
    bool isShadowMapCacheEnable() const;
    void setContinuousShadowMapCacheValidation(bool enable);
    bool isContinuousShadowMapCacheValidation() const;
    void setToleranceFrameLengthUpdateShadowMapCache(u32 frameLength);
    u32 getToleranceFrameNumberUpdateShadowMapCache() const;
    u32 getShadowMapCacheSceneHash(u32 viewNum, u32 shadowGroup);
    void setShadowMapSize(RESOURCE_TYPE rtype, u32 size);
    u32 getShadowMapSize(RESOURCE_TYPE rtype) const;
    void setShadowMapType(RESOURCE_TYPE rtype, u32 type);
    u32 getShadowMapType(RESOURCE_TYPE rtype) const;
    uintptr allocShadowCacheID(const uintptr req_cache_id);
    void freeShadowCacheID(const uintptr cache_id);
    bool isActiveShadowMulValue() const;
    void setActiveShadowMulValue(bool NewIsActiveShadowMulValue);
    f32 getShadowSizeMulValue() const;
    void setShadowSizeMulValue(f32 NewShadowSizeMulValue);
    f32 getShadowViewDistanceMulValue() const;
    void setShadowViewDistanceMulValue(f32 NewShadowDistanceMulValue);
protected:
    sShadow(const u32 MaxCacheIDList);
    virtual ~sShadow();
private:
    void acquireResources();
    void releaseResources();
    const Resource* getResource(const Bundle& bundle);
    void updateShadowMapCache(u32 viewNum);
    bool isViewportValid(sCamera::VIEWPORT_NO num);
    static void allocateSpotShadowMap(u32 shadowMapType, u32 mapSize, nDraw::Texture* * depthMap, nDraw::Texture* * tempMap, nDraw::Texture* * depthStencil, bool cache, SharedTexture& sharedTexture, u32& rt_offset, u32& ds_offset, bool scratch, u32& rtOffsetScratch, u32& dsOffsetScratch);
    static void allocatePointShadowMap(u32 shadowMapType, u32 mapSize, nDraw::Texture* * depthMap, nDraw::Texture* * tempMap, nDraw::Texture* * depthStencil, bool cache, SharedTexture& sharedTexture, u32& rt_offset, u32& ds_offset, bool scratch, u32& rtOffsetScratch, u32& dsOffsetScratch);
    static void allocateSpotSharedTexture(u32 mapNum, SharedTexture& sharedTexture, u32 shadowMapType, u32 mapSize, bool cache, u32 cachedViewNum, bool scratch, u32& rtOffsetScratch, u32& dsOffsetScratch);
    static void allocatePointSharedTexture(u32 mapNum, SharedTexture& sharedTexture, u32 shadowMapType, u32 mapSize, bool cache, u32 cachedViewNum, bool scratch, u32& rtOffsetScratch, u32& dsOffsetScratch);
    Node* getNode(u32 index);
    void setNode(Node* unit, u32 index);
    u32 getNodeNum();
    void setNodeNum(u32 num);
    void setSpotShadowMapSize(u32 size);
    u32 getSpotShadowMapSize() const;
    void setSpotShadowMapType(u32 type);
    u32 getSpotShadowMapType() const;
    void setPointShadowMapSize(u32 size);
    u32 getPointShadowMapSize() const;
    void setPointShadowMapType(u32 type);
    u32 getPointShadowMapType() const;
    ViewConsistentResource* allocateVCResource(const Node& node);
    void releaseVCResource(ViewConsistentResource* resource);
    void releaseAllNodeVCResource();
    void traverseShadowUnit(MT_MFUNCPTRU32 pUnitFoundFunc);
    void foundUnitFunctionShadowActive(void* pShadowUnit, u32);
    void foundUnitFunctionShadowMapSizeMulValue(void* pShadowUnit, u32);
    void foundUnitFunctionShadowDistanceMulValue(void* pShadowUnit, u32);
public:
    f32 getCommonPointShadowDistanceBias();
    bool isCommonPointShadowDistanceBias();
    bool isRestoreShadowMapUseResolve();
    bool isRestoreShadowMapCacheEnable();
private:
    uintptr* mpShadowCacheIDList;  // offset: 0x18
    uintptr mShadowCacheIDRandParam;  // offset: 0x20
    const u32 mShadowCacheIDListMax;  // offset: 0x28
    MtArray mNodes;  // offset: 0x30
    ResourceGroup mResourceGroup[2];  // offset: 0x50
    u32 mResourceNum;  // offset: 0x4d0
    u32 mCacheEnabledViewNumber;  // offset: 0x4d4
    Bundle mBundleLists[2][8][16];  // offset: 0x4d8
    Context mContext;  // offset: 0x1ce0
    u32 mCurrentFrameCount;  // offset: 0x1ea0
    bool mManagementEnable;  // offset: 0x1ea4
    bool mQueryEnable;  // offset: 0x1ea5
    bool mQueryDispEnable;  // offset: 0x1ea6
    u32 mQueryFrameLatencyTolerance;  // offset: 0x1ea8
    u32 mQueryVisibleThresholdPixelNumber;  // offset: 0x1eac
    f32 mFadeDistance;  // offset: 0x1eb0
    f32 mVisibleDistance;  // offset: 0x1eb4
    f32 mAttenuationDelta;  // offset: 0x1eb8
    f32 mBlendWeightPriority;  // offset: 0x1ebc
    f32 mThresholdPriorityDelta;  // offset: 0x1ec0
    bool mShadowMapCacheEnable;  // offset: 0x1ec4
    bool mContinuousShadowMapCacheValidation;  // offset: 0x1ec5
    u32 mToleranceFrameLengthUpdateShadowMapCache;  // offset: 0x1ec8
    u32 mShadowMapCacheSceneHash[8][2];  // offset: 0x1ecc
    bool mIsActiveShadowMulValue;  // offset: 0x1f0c
    f32 mShadowSizeMulValue;  // offset: 0x1f10
    f32 mShadowDistanceMulValue;  // offset: 0x1f14
    f32 mCommonPointShadowDistanceBias;  // offset: 0x1f18
    bool mCommonPointShadowDistanceBiasEnable;  // offset: 0x1f1c
    bool mRestoreShadowMapUseResolve;  // offset: 0x1f1d
    bool mRestoreShadowMapCacheEnable;  // offset: 0x1f1e
public:
    static MyDTI DTI;
    static const f32 PRIORITY_MIN;
    static const f32 PRIORITY_MAX;
    static const u32 MAX_RESOURCE_NUM = 16;
    static const u32 MAX_SUPPORT_VIEW_NUM = 2;
    static const u32 MAX_VIEW_CONSISTENT_RESOURCE_NUM = 32;
    static const u32 MAX_CACHEID_LIST = 64;
    static const u32 CREATE_CACHEID_BITSHIFT = 6;
private:
    static const u32 RESOURCE_INDEX_NULL = 4294967295;
    static const u32 MAX_FRAME_NUM = 2;
    static sShadow* mpInstance;
};

class cShadowPriorityState : public MtObject
{
public:
    enum MESSAGE
    {
        MESSAGE_ALLOC = 0,
        MESSAGE_REQUEST_FADE_OUT = 1,
    };
    enum STATE
    {
        STATE_NO_ALLOC = 0,
        STATE_VISIBLE_ALLOC = 1,
        STATE_FADEIN = 2,
        STATE_FADEOUT = 3,
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
    cShadowPriorityState();
    virtual ~cShadowPriorityState();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    f32 getAttenuation() const;
    f32 getAttenuationDistance() const;
    f32 getPriority() const;
    bool isExecution() const;
    void updatePriority(const sShadow& system, const sShadow::Context& context, uShadow* unit, u32 viewNum);
    bool takeBackResource(const sShadow& system, cShadowPriorityState* state);
    void notifyMessage(MESSAGE message);
    void updateState(const sShadow& system, uShadow* unit);
    void issueOcclusionQuery(const sShadow& system, cDraw* pdraw, const uShadow* unit);
private:
    f32 getPriorityProjectionArea(const sShadow::Context& context, const MtAABB& aabb) const;
    bool getVisiblePixelCount(u32& count, s32& frame);
    bool isVisibleCurrentFrame() const;
    bool isVisibleOcclusion() const;
    bool isVisibleTriggerCurrentFrame(const sShadow& system) const;
private:
    f32 mPriority;  // offset: 0x8
    f32 mAttenuationDistance;  // offset: 0xc
    f32 mAttenuationFade;  // offset: 0x10
    u32 mState;  // offset: 0x14
    u32 mVisibleHistory;  // offset: 0x18
    u32 mOcclusionVisibleHistory;  // offset: 0x1c
    u32 mIntersectNearPlaneHistory;  // offset: 0x20
    u32 mFrameLastOcclusion;  // offset: 0x24
    bool mNotificationAlloc;  // offset: 0x28
    bool mRequestFadeout;  // offset: 0x29
    nDraw::OcclusionQuery* mpOcclusionQuery;  // offset: 0x30
public:
    static MyDTI DTI;
private:
    static const s32 OCCLUSION_LATENCY_FRAME_MAX = 8;
    static const f32 ATTENUATION_THRESHOLD_TAKE_BACK;
};
