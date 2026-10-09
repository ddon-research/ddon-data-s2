#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "rModel.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cBakeModel;
class cDDMaterialCtrl;
class cDraw;
class cpBakeJoint;
namespace nDraw { class CommandCache; }
namespace nDraw { class Material; }
class rMaterial;
class rModel;
class uCustomSimSoftBody;
class uSimSoftBody;

// Declarations
class uBaseModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using uintptr = __uintptr_t;

class uBaseModel : public uCoord
{
    // inferred: cBakeModel::buildJointIndexTable names uBaseModel::mpModel
    friend class cBakeModel;
    // inferred: cDDMaterialCtrl::setCommonState names uBaseModel::mMaterialNum
    friend class cDDMaterialCtrl;
    // inferred: cpBakeJoint::setOriginalEnvelope names uBaseModel::mpModel
    friend class cpBakeJoint;
    // inferred: uCustomSimSoftBody::hasTarget names uBaseModel::mpModel
    friend class uCustomSimSoftBody;
    // inferred: uSimSoftBody::getTargetLODLevel calls uBaseModel::getLODLevel
    friend class uSimSoftBody;
public:
    enum VFCULL_LEVEL
    {
        VFCULL_NONE = 0,
        VFCULL_LEVEL1 = 1,
        VFCULL_LEVEL2 = 2,
        VFCULL_LEVEL3 = 3,
        _VFCULL_LEVEL_S32_ = 2147483647,
    };
    enum LOD_TYPE
    {
        LOD_AUTO = -1,
        LOD_HIGH = 1,
        LOD_MEDIUM = 2,
        LOD_LOW = 4,
        _LOD_TYPE_S32_ = 2147483647,
    };
    enum SHADER_QUALITY
    {
        SHADER_AUTO = -1,
        SHADER_HIGH = 0,
        SHADER_MEDIUM = 1,
        SHADER_LOW = 2,
        _SHADER_QUALITY_S32_ = 2147483647,
    };
    enum CACHE_MODE
    {
        CACHE_NONE = 0,
        CACHE_LEVEL1 = 1,
        __CACHE_MODE__U32 = -1,
    };
    enum CACHE_TYPE
    {
        CACHE_DEFAULT = 0,
        CACHE_SHADOW0_RECV = 1,
        CACHE_SHADOW0_CAST = 2,
        CACHE_SHADOW1_RECV = 3,
        CACHE_SHADOW1_CAST = 4,
        MAX_CACHE = 96,
    };
    enum LIGHT_ATTR
    {
        LIGHT_PARTS_CULLING = 1,
        LIGHT_PARENT_RECIVER = 2,
        LIGHT_SHADOW_REGION = 4,
    };
public:
    class MyDTI;
    struct CACHE;
    struct CACHE_ID;
    class CACHE_OP;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CACHE_ID
    {
    public:
        uintptr cache_id;  // offset: 0x0
        union
        {
        public:
            u32 cache_key;  // offset: 0x0
            struct
            {
            public:
                u32 cb_material : 2;  // offset: 0x0
                u32 type : 3;  // offset: 0x0
                u32 view : 4;  // offset: 0x0
                u32 lod : 3;  // offset: 0x0
                u32 detail : 5;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x8
    };
public:
    class CACHE_OP
    {
    public:
        bool operator()(const uBaseModel::CACHE& a, const uBaseModel::CACHE& b) const;
        static s32 compare(const void*, const void*);
    };
public:
    struct CACHE
    {
    public:
        nDraw::CommandCache* p_command;  // offset: 0x0
        uBaseModel::CACHE_ID id;  // offset: 0x8
        u32 limit_detect;  // offset: 0x18
        u32 lock_key;  // offset: 0x1c
        u32 update_key;  // offset: 0x20
        static const u32 LOCK_KEY = 60969;
        static const u32 UNLOCK_KEY = 48815;
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
    uBaseModel();
    virtual ~uBaseModel();
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    // Address: 0x01b0a590 - 0x01b0a591 (1 bytes)
    virtual void sync() {}  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void cancelState(cDraw* pdraw);  // vtable slot 28
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setModel(rModel* pmod);  // vtable slot 29
    rModel* getModel() const;
    void setMaterialData(rMaterial* pmat);
    rMaterial* getMaterialData();
    virtual void updateWorldMatrix();  // vtable slot 26
    void updateBoundary();
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    bool isPartsDisp(u32 no) const;
    void setPartsDisp(bool disp, u32 no);
    void setPartsDispAll(bool disp);
    const MtSphere& getBoundingSphere() const;
    const MtOBB& getBoundingBox() const;
    void setVFCullLevel(VFCULL_LEVEL level);
    VFCULL_LEVEL getVFCullLevel() const;
    s32 getZPrepassDist() const;
    void setZPrepassDist(s32 dist);
    u32 getDrawPriority() const;
    virtual bool isPrioAttrTransparency(cDraw* pDraw);  // vtable slot 30
    virtual u32 getAddTransparentDrawPriority();  // vtable slot 31
    void setDrawPriority(u32 v);
    s32 getPriorityBias() const;
    void setPriorityBias(s32 b);
    LOD_TYPE getLODType() const;
    void setLODType(LOD_TYPE lod);
    SHADER_QUALITY getShaderQuality() const;
    void setShaderQuality(SHADER_QUALITY q);
    u32 getMaterialNum() const;
    nDraw::Material* getMaterial(u32 index);
    void resetMaterial(u32 index);
    void resetAllMaterial();
    void setMaterial(nDraw::Material* pmaterial, u32 index);
    void updateMaterial();
    void setTransparency(f32 v);
    f32 getTransparency();
    void setDissolveEnable(bool enable);
    bool getDissolveEnable();
    void setFixPosition(bool v);
    bool isFixPosition();
    void setShaderAttributes(bool enable);
    bool isShaderAttributes();
    bool isMatrixPalletEnable();
    void setFlatTransparency(bool v);
    bool isFlatTransparency() const;
    void clearCommandCache();
    CACHE_MODE getCacheMode();
    void setCacheMode(CACHE_MODE v);
    void setLightGroup(u32 group);
    u32 getLightGroup() const;
    void setLightAttr(u32 attr);
    u32 getLightAttr() const;
    void setMaxLightNum(u32 n);
    u32 getMaxLightNum() const;
    const MtSphere& getLightReciver() const;
    void setLightReciver(f32);
    s32 setupShadow(cDraw* pdraw);
    void setMultiShadowReceive(bool enable);
    bool isMultiShadowReceive() const;
    void setMaxNumGroup0MultiShadowReceive(u32 n);
    u32 getMaxNumGroup0MultiShadowReceive() const;
    void setMaxNumGroup1MultiShadowReceive(u32 n);
    u32 getMaxNumGroup1MultiShadowReceive() const;
    void setLODDist(LOD_TYPE type, f32 dist);
    f32 getLODDist(LOD_TYPE);
    u32 getDebugFlags() const;
    void setDebugFlags(u32 f);
    u32 isViewDraw(u32) const;
    bool isAllViewCulling() const;
    u32 getViewDraw() const;
protected:
    void transDebug(rModel* pmod);
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    virtual void drawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);  // vtable slot 33
    void setPrimState(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp);
    virtual void cullingCommandCache(cDraw* pdraw, nDraw::CommandCache* pcache, rModel* pmod, s32 basecullmask, u32 lod);  // vtable slot 34
    MtVector3 calcBaseCenterPos();
    s32 cullingModel(cDraw* pdraw);
    s32 cullingNonSkin(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, s32 basecullmask);
    virtual u32 getLODLevel(s32 dist);  // vtable slot 35
    u32 getShaderLevel(s32);
    void orViewDraw(u32 f);
    void norViewDraw(u32 f);
    void updateViewDraw();
    bool isVtxDisplacementExp();
private:
    u32 getPartsModelNum();
    void setPartsModelNum(u32);
    u32 getPartsNum();
    void setPartsNum(u32);
    void setMaterialNum(u32);
    void releaseMaterial();
    void setVtxDisplacementWave(bool enable);
    bool isVtxDisplacementWave();
    void setVtxDisplacementExp(bool enable);
    f32 fVtxDispPseudoNoise(const MtVector3& t);
    f32 fVtxDispPerlinNoiseTurbulence(const MtVector3& p, u32 octaves, f32 lacunarity, f32 gain);
public:
    void traceCommandCache(CACHE* pcache);
    void updateCommandCache();
    virtual u32 getUseCommandCacheNum();  // vtable slot 20
    virtual u32 getUseMaxCommandCacheNum();  // vtable slot 21
protected:
    CACHE_TYPE getCommandCache(cDraw* pdraw);
    bool drawCommandCache(u32 cache, cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 cullmask, s32 shadow_cullmask);
public:
    void requestCommandCacheOff();
    void updateCommandCacheLevel();
    void setRCNEnable(bool isEnable);
    bool isRCNEnable();
    void setFromTextureCalcTangent(bool isEnable);
    bool isFromTextureCalcTangent();
    void setMaterialIndexDirect(bool isEnable);
    bool isMaterialIndexDirect();
    virtual u32 getHitLightToModel();  // vtable slot 36
private:
    void setMaxLightNum();
public:
    bool mbFilpShadowCast;  // offset: 0x110
    s32 mIgnoreFilpShadowPartNo;  // offset: 0x114
protected:
    rModel* mpModel;  // offset: 0x118
    rMaterial* mpMaterialData;  // offset: 0x120
    nDraw::Material* * mpMaterials;  // offset: 0x128
    u32 mMaterialNum;  // offset: 0x130
    u32 mLightGroup;  // offset: 0x134
    u32 mLightAttr : 4;  // offset: 0x138
    u32 mMultiShadowReceive : 1;  // offset: 0x138
    u32 mMaxNumGroup0MultiShadowReceive : 2;  // offset: 0x138
    u32 mMaxNumGroup1MultiShadowReceive : 2;  // offset: 0x138
    u32 mVtxDisplacementWaveEnable : 1;  // offset: 0x138
    u32 mVtxDisplacementExpEnable : 1;  // offset: 0x138
    u32 mReserved : 20;  // offset: 0x138
    u32 mFlatTransparency : 1;  // offset: 0x138
    s32 mVFCullLevel : 6;  // offset: 0x13c
    u32 mVFCullScale : 1;  // offset: 0x13c
    u32 mVFCullRotate : 1;  // offset: 0x13c
    u32 mVFCullTranslate : 1;  // offset: 0x13c
    s32 mLODType : 4;  // offset: 0x13c
    s32 mDebugFlags : 8;  // offset: 0x13c
    s32 mShaderQuality : 4;  // offset: 0x13c
    u32 mMaxLightNum : 4;  // offset: 0x13c
    u32 mShaderAttributes : 1;  // offset: 0x13c
    u32 mDissolveEnable : 1;  // offset: 0x13c
    u32 mFixPosition : 1;  // offset: 0x13c
    u32 mDrawPriority;  // offset: 0x140
    u32 mPartsDisp[16];  // offset: 0x144
    s32 mZPrepassDist;  // offset: 0x184
    s32 mPriorityBias;  // offset: 0x188
    f32 mTransparency;  // offset: 0x18c
    f32 mLODLowDist;  // offset: 0x190
    f32 mLODMidDist;  // offset: 0x194
    u32 mMaterialAnimationFlag;  // offset: 0x198
    u32 mViewDraw : 16;  // offset: 0x19c
    u32 mViewDrawNew : 16;  // offset: 0x19c
    u32 mViewDrawUpdate : 1;  // offset: 0x1a0
    u32 mMatrixPalletEnable : 1;  // offset: 0x1a0
    u32 mViewDrawReserved : 30;  // offset: 0x1a0
    nDraw::Material* mpMaterialStack[4];  // offset: 0x1a8
    MtSphere mBoundingSphere;  // offset: 0x1d0
    MtOBB mBoundingBox;  // offset: 0x1e0
    MtSphere mLightReciver;  // offset: 0x230
    MtVector4 mAmbientMask;  // offset: 0x240
    u32 mCacheMode;  // offset: 0x250
    u32 mPrevPartsDisp[16];  // offset: 0x254
    u32 mPartsDispMax;  // offset: 0x294
    CACHE mCache[96];  // offset: 0x298
    s32 mTailCacheNum;  // offset: 0x1198
    u32 mUseCacheNum;  // offset: 0x119c
    u32 mMsxUseCacheNum;  // offset: 0x11a0
    u32 mMaterialCBuffer;  // offset: 0x11a4
private:
    bool mCommandCacheOffOld;  // offset: 0x11a8
    bool mCommandCacheOffNow;  // offset: 0x11a9
protected:
    bool mIsRCNEnable;  // offset: 0x11aa
    bool mIsFromTextureCalcTangent;  // offset: 0x11ab
    bool mMaterialIndexDirect;  // offset: 0x11ac
public:
    static MyDTI DTI;
    static const u32 MAX_PARTSMODEL = 16;
protected:
    static const u32 MATERIAL_STACK_NUM = 4;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 uBaseModel::getTransparency() {
    return this->mTransparency;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 uBaseModel::getLightGroup() const {
    return this->mLightGroup;
}
