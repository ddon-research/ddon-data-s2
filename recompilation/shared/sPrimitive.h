#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtPrimitive2D.h"
#include "cBlendState.h"
#include "cPrimTagList.h"
#include "cSystem.h"
#include "nDraw.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtUI;
class MtVector4;
class cBlendState;
class cDraw;
class cPrim;
class cPrimBufferManager;
class cPrimTagManager;
class cPrimTexHandle;
class cPrimTexHandleManager;
class cUnit;
namespace nDraw { class Texture; }
namespace nPrim { struct Material; }
namespace nPrim { struct MetaDataHeader; }
namespace nPrim { struct Texture; }

// Declarations
class sPrimitive;

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
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sPrimitive : public cSystem
{
    // inferred: cPrimTexHandle::reserveTexture names sPrimitive::mpInstance
    friend class cPrimTexHandle;
public:
    enum ePrimStencilFunc
    {
        STENCIL_FUNC_EQ = 0,
        STENCIL_FUNC_NEQ = 1,
        MAX_PRIM_STENCIL_FUNC = 2,
    };
    enum ePrimType
    {
        TYPE_NULL = 0,
        TYPE_WORLD = 1,
        TYPE_SCREEN = 2,
        MAX_PRIM_TYPE = 3,
    };
    enum ePrimSysState
    {
        STATE_UNINITIALIZED = 0,
        STATE_READY = 1,
        STATE_TERMINATED = 2,
    };
    enum LAYOUTMODE
    {
        LAYOUT_NONE = 0,
        LAYOUT_STRETCH = 1,
        LAYOUT_PANSCAN = 2,
        LAYOUT_LETTERBOX = 3,
    };
    enum eSceneClamp
    {
        SCR_UV_NONE = 0,
        SCR_UV_CLIP = 1,
        SCR_UV_SMOOTH = 2,
    };
    enum FUNC_PRIM_FOG
    {
        PRIM_FOG_OFF = 0,
        PRIM_FOG_COLOR = 1,
        PRIM_FOG_ALPHA = 2,
        PRIM_FOG_BLEND = 3,
        MAX_PRIM_FOG = 4,
    };
    enum FUNC_PRIM_EX
    {
        PRIM_EX_NONE = 0,
        PRIM_EX_OCCLUSION = 1,
        PRIM_EX_VOLUME = 2,
        PRIM_EX_REFRACT = 3,
        PRIM_EX_DEPTH_VOLUME = 4,
        PRIM_EX_PARALLAX = 5,
        PRIM_EX_OCCLUSION_NOVTF = 6,
        PRIM_EX_UV_CLAMP = 7,
        PRIM_EX_INV_VOLUME = 8,
        PRIM_EX_BLUR = 9,
        PRIM_EX_Z_REFRACT = 10,
        PRIM_EX_Z_REFRACT_EX = 11,
        PRIM_EX_DISTORTION = 12,
        MAX_PRIM_EX = 13,
    };
public:
    class MyDTI;
    struct DivTag;
    struct DrawInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DivTag
    {
    public:
        cPrimTagList::IndexTag* p_tag;  // offset: 0x0
        cPrimTagList::IndexTag* p_work;  // offset: 0x8
        u32 first;  // offset: 0x10
        u32 last;  // offset: 0x14
    };
public:
    struct DrawInfo
    {
    public:
        u32 base_priority;  // offset: 0x0
        cPrimTagList::IndexTag* p_tags;  // offset: 0x8
        u32 tag_num;  // offset: 0x10
        bool use_vscr;  // offset: 0x14
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
    cPrim* getCPrim(cDraw* p_draw, ePrimType type, cUnit* p_unit);
    cPrim* getCPrim(cDraw* p_draw, nDraw::PASS_TYPE pass, cUnit* p_unit);
    virtual void begin();  // vtable slot 10
    virtual void end();  // vtable slot 11
    // Address: 0x01ba37b0 - 0x01ba37b1 (1 bytes)
    virtual void move() {}  // vtable slot 7
    virtual s32 beginBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw, bool use_vscr);  // vtable slot 12
    virtual s32 endBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw);  // vtable slot 13
    virtual void initPrimitiveSys(u32 vb_size, u32 tag_size);  // vtable slot 14
    virtual void termPrimitiveSys();  // vtable slot 15
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    ePrimSysState getState() const;
    bool isMultiThreadDraw() const;
    void enableMultiThreadDraw(bool);
    bool isDrawPrimitive() const;
    void enableDrawPrimitive(bool);
    bool isAutoReduction() const;
    bool isOcclusionVTF() const;
    void enableAutoReduction(bool);
    void setReductionDistance(u32);
    u32 getReductionDistance() const;
    cPrimTexHandleManager* getPrimTexHandleManager() const;
    cBlendState* getPrimBlendState();
    nDraw::Texture* getDistortion() const;
    void setDistortion(nDraw::Texture* p_tex);
    u32 getDepthDiv() const;
    void setDepthDiv(u32);
    bool isVolumeBlend() const;
    void enableVolumeBlend(bool);
    bool isParallax() const;
    void enableParallax(bool);
    float getSceneUVClampRange() const;
    void setSceneUVClampRange(float);
    u32 getSceneUVClampType() const;
    void setSceneUVClampType(u32);
    void setDepthBlendDistance(f32 near_sz, f32 near_ez, f32 far_sz, f32 far_ez);
    MtVector4 getDepthBlend();
    void setVolumeScale(f32 scale);
    f32 getVolumeScale();
    void setIntensityScale(f32);
    f32 getIntensityScale();
    void setParallaxScale(f32 scale);
    f32 getParallaxScale();
    u32 getParallaxMinLoop() const;
    void setParallaxMinLoop(u32);
    u32 getParallaxMaxLoop() const;
    void setParallaxMaxLoop(u32);
    f32 getParallaxFadeStart() const;
    void setParallaxFadeStart(f32);
    f32 getParallaxFadeEnd() const;
    void setParallaxFadeEnd(f32);
    f32 getRefractZBlur() const;
    void setRefractZBlur(f32);
    f32 getRefractZThreshold() const;
    void setRefractZThreshold(f32);
    u32 getPrimModelLtNum() const;
    void setPrimModelLtNum(u32);
    f32 getPrimAlphaClip() const;
    void setPrimAlphaClip(f32);
    f32 getDepthCmpLimit() const;
    void setDepthCmpLimit(f32);
    u32 reserveTex(nPrim::Texture* * p_tex, u32* idx, u32 num_tex);
    u32 reserveBuffer(void* * ptr, u32 size);
    ePrimStencilFunc getPrimStencilFunc() const;
    void setPrimStencilFunc(ePrimStencilFunc);
    u8 getPrimStencilRef() const;
    void setPrimStencilRef(u8);
    u32 getScreenPassLayer() const;
    void setScreenPassLayer(u32);
    void setScreenLayout(LAYOUTMODE);
    LAYOUTMODE getScreenLayout();
    u32 getVirtualScreenWidth() const;
    void setVirtualScreenWidth(u32);
    u32 getVirtualScreenHeight() const;
    void setVirtualScreenHeight(u32);
    static sPrimitive* createInstance(u32 vb_size, u32 tag_size);
    static void deleteInstance();
    static sPrimitive* getInstance();
protected:
    virtual void drawJob(cDraw* p_draw, DrawInfo* p_info);  // vtable slot 16
    virtual u32 changeMaterial(cDraw* p_draw, const nPrim::Material& new_mat, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* new_header);  // vtable slot 17
    virtual u32 drawPrimitive(cDraw* p_draw, cPrimTagList::IndexTag* p_tag, u32 num, u32 v_num, u32 i_num);  // vtable slot 18
    virtual void setDrawState(cDraw* p_draw, const nPrim::Material& material);  // vtable slot 19
    virtual void setBlendState(cDraw* p_draw, const nPrim::Material& material, u32 fog);  // vtable slot 20
    virtual void setMetaData(cDraw* p_draw, const nPrim::Material& material, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* new_header);  // vtable slot 21
    virtual void clearTag();  // vtable slot 22
    void sortTags(uintptr param);
    void mergeTag(cPrimTagList::IndexTag* in_data, cPrimTagList::IndexTag* temp, s32 lt, s32 md, s32 rt);
    u32 drawTags(cDraw* p_draw, u32 disp_lv, const nPrim::Material& mat, cPrimTagList::IndexTag* p_tag, u32 num, u32 vnum, u32 inum, u32 base_priority, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* curr_header, bool reduction, u32 r_dist);
    u32 setPrimitiveExtFunc(cDraw* p_draw, const nPrim::Material& mat);
    u32 setPrimitiveFogFunc(cDraw* p_draw, const nPrim::Material& mat, u32 ex);
    void setPrimitiveDepthBlendFunc(cDraw* p_draw, const nPrim::Material& mat);
    u32 setPrimitiveTexFunc(cDraw* p_draw, const nPrim::Material& mat, u32 ex);
    void setPrimitiveTechnique(cDraw* p_draw, const nPrim::Material& mat);
    sPrimitive();
    sPrimitive(u32 vb_size, u32 tag_size);
    virtual ~sPrimitive();
protected:
    u32 mState;  // offset: 0x14
    u32 mScreenLayout;  // offset: 0x18
    u32 mVirtualScrW;  // offset: 0x1c
    u32 mVirtualScrH;  // offset: 0x20
    cPrim* mpPrim[6];  // offset: 0x28
    DivTag mDivTag[6];  // offset: 0x58
    u32 mNumOfPrim;  // offset: 0xe8
    cPrimTexHandleManager* mpTexHandleMgr;  // offset: 0xf0
    cPrimBufferManager* mpBufferMgr;  // offset: 0xf8
    cPrimTagManager* mpTagManager;  // offset: 0x100
    nDraw::Texture* mpDistortionTex;  // offset: 0x108
    cBlendState mBlendState;  // offset: 0x110
    u32 mReductionDist;  // offset: 0x1a0
    f32 mNearStart;  // offset: 0x1a4
    f32 mNearEnd;  // offset: 0x1a8
    f32 mFarStart;  // offset: 0x1ac
    f32 mFarEnd;  // offset: 0x1b0
    f32 mVolumeScale;  // offset: 0x1b4
    f32 mIntensityScale;  // offset: 0x1b8
    f32 mParallaxScale;  // offset: 0x1bc
    f32 mParallaxFadeStart;  // offset: 0x1c0
    f32 mParallaxFadeEnd;  // offset: 0x1c4
    u32 mParallaxMinLoop;  // offset: 0x1c8
    u32 mParallaxMaxLoop;  // offset: 0x1cc
    u32 mPrimModelLtNum;  // offset: 0x1d0
    f32 mPrimAlphaClip;  // offset: 0x1d4
    f32 mDepthCmpLimit;  // offset: 0x1d8
    MtSize mScreenSize;  // offset: 0x1e0
    ePrimStencilFunc mPrimStencilFunc;  // offset: 0x1e8
    u8 mPrimStencilRef;  // offset: 0x1ec
    bool mUseMTDraw;  // offset: 0x1ed
    bool mParallaxEnable;  // offset: 0x1ee
    bool mVolumeEnable;  // offset: 0x1ef
    bool mAutoReduction;  // offset: 0x1f0
    bool mOcclusionVTF;  // offset: 0x1f1
    bool mDrawPrimitive;  // offset: 0x1f2
    u32 mDepthDiv;  // offset: 0x1f4
    f32 mRefractZBlur;  // offset: 0x1f8
    f32 mRefractZThreshold;  // offset: 0x1fc
    u32 mScreenPassLayer;  // offset: 0x200
    float mSceneClampRange;  // offset: 0x204
    u32 mSceneClampType;  // offset: 0x208
public:
    static MyDTI DTI;
protected:
    static sPrimitive* mpInstance;
};
