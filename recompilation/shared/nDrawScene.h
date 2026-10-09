#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "nDraw.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtUI;
namespace nDraw { class DepthStencilView; }
namespace nDraw { class RenderTargetView; }
namespace nDraw { class Texture; }
class sRender;

// Declarations
namespace nDraw { struct SCENE_DESC; }
namespace nDraw { class Scene; }

namespace nDraw {
    enum ANTIALIAS_ALT_TYPE
    {
        ANTIALIAS_ALT_NONE = 0,
        ANTIALIAS_ALT_FXAA = 1,
        ANTIALIAS_ALT_FXAA3 = 2,
        ANTIALIAS_ALT_FXAA3HQ = 3,
        __ANTIALIAS_ALT_TYPE__U32 = -1,
    };
}  // namespace nDraw

namespace nDraw {
    enum ANTIALIAS_TYPE
    {
        ANTIALIAS_NONE = 0,
        ANTIALIAS_MSAA2X = 1,
        ANTIALIAS_MSAA4X = 2,
        ANTIALIAS_MSAA8X = 3,
        ANTIALIAS_MSAA4X_8Q = 4,
        ANTIALIAS_MSAA8X_8Q = 5,
        ANTIALIAS_MSAA4X_16Q = 6,
        ANTIALIAS_MSAA8X_16Q = 7,
        ANTIALIAS_MSAA8X_32Q = 8,
        __ANTIALIAS_TYPE__U32 = -1,
    };
}  // namespace nDraw

namespace nDraw {
    enum DEFERRED_LIGHTING_HDR_TYPE
    {
        DL_HDR_INTEGER = 0,
        DL_HDR_FLOAT = 1,
        DL_HDR_FLOAT_PRECISION = 2,
        DL_HDR_INTEGER_LOG = 3,
    };
}  // namespace nDraw

namespace nDraw {
    enum DEFERRED_LIGHTING_LIGHT_TYPE
    {
        DL_LIGHT_MONOCHROME_SPECULAR = 0,
        DL_LIGHT_APPROXIMATE_SPECULAR = 1,
        DL_LIGHT_SEPARATE_SPECULAR = 2,
    };
}  // namespace nDraw

namespace nDraw {
    enum DEFERRED_LIGHTING_NORMAL_TYPE
    {
        DL_NORMAL_SPHEREMAP = 0,
        DL_NORMAL_SPHEREMAP_LUT = 1,
    };
}  // namespace nDraw

namespace nDraw {
    enum DEFERRED_LIGHTING_TRANSPARENT_TYPE
    {
        DL_TRANSPARENT_SIZE_QUARTER_LAYER_4 = 0,
        DL_TRANSPARENT_SIZE_QUARTER_LAYER_1 = 1,
        DL_TRANSPARENT_SIZE_FULL_LAYER_1 = 2,
    };
}  // namespace nDraw

namespace nDraw {
    enum HDR_TYPE
    {
        HDR_NONE = 0,
        HDR_DEFAULT = 1,
        HDR_FLOAT = 2,
        __HDR_TYPE__U32 = -1,
    };
}  // namespace nDraw

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    struct SCENE_DESC
    {
    public:
        SCENE_DESC();
    public:
        u32 width;  // offset: 0x0
        u32 height;  // offset: 0x4
        nDraw::HDR_TYPE hdr_type;  // offset: 0x8
        nDraw::ANTIALIAS_TYPE aa_type;  // offset: 0xc
        u32 scene_attr;  // offset: 0x10
        f32 hdr_emphasis;  // offset: 0x14
        MtColor clear_color;  // offset: 0x18
        nDraw::DEFERRED_LIGHTING_LIGHT_TYPE dl_light;  // offset: 0x1c
        nDraw::DEFERRED_LIGHTING_HDR_TYPE dl_hdr;  // offset: 0x20
        nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE dl_transparent;  // offset: 0x24
    };
}  // namespace nDraw

namespace nDraw {
    class Scene : public nDraw::Resource
    {
        // inferred: sRender::getHDREmphasis names nDraw::Scene::mHDREmphasis
        friend class ::sRender;
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        Scene(nDraw::SCENE_DESC desc);
        nDraw::RenderTargetView* getRenderTargetView(nDraw::PASS_TYPE pass, u32 target) const;
        nDraw::DepthStencilView* getDepthStencilView(nDraw::PASS_TYPE pass) const;
        nDraw::Texture* getTexture(nDraw::PASS_TYPE pass) const;
        nDraw::Texture* getDepthTexture() const;
        nDraw::Texture* getBackFaceDepthTexture() const;
        nDraw::Texture* getStencilTexture() const;
        nDraw::Texture* getHDRTexture() const;
        nDraw::Texture* getHDRQTexture() const;
        nDraw::Texture* getTangentTexture() const;
        MtSize getSize() const;
        MtColor getClearColor() const;
        void setClearColor(MtColor c);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setHDREmphasis(f32 v);
        f32 getHDREmphasis();
        nDraw::HDR_TYPE getHDRType() const;
        nDraw::ANTIALIAS_TYPE getAntiAliasType() const;
        u32 getAttributes() const;
        nDraw::DEFERRED_LIGHTING_LIGHT_TYPE getDeferredLightingLightType() const;
        nDraw::DEFERRED_LIGHTING_HDR_TYPE getDeferredLightingHDRType() const;
        nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE getDeferredLightingTransparentType() const;
        nDraw::Texture* getSceneReductionTex() const;
        nDraw::Texture* getDepthReductionTex() const;
        bool isUseReduction() const;
        nDraw::Texture* getTempDistortionTex() const;
    protected:
        virtual ~Scene();
    private:
        void getLightAccumulationFormat(nDraw::FORMAT_TYPE& format, u32& miscFlags);
        u32 setupAntiAliasType(nDraw::ANTIALIAS_TYPE type, nDraw::FORMAT_TYPE format);
    protected:
        u32 mAttributes;  // offset: 0x14
        f32 mHDREmphasis;  // offset: 0x18
        nDraw::Texture* mpRTView[25][4];  // offset: 0x20
        nDraw::Texture* mpDSView[25];  // offset: 0x340
        nDraw::Texture* mpTexture[25];  // offset: 0x408
        nDraw::Texture* mpDepthStencil;  // offset: 0x4d0
        nDraw::Texture* mpDepthStencilRO;  // offset: 0x4d8
        nDraw::Texture* mpRTDepthStencil;  // offset: 0x4e0
        nDraw::Texture* mpStencil;  // offset: 0x4e8
        nDraw::Texture* mpDepth;  // offset: 0x4f0
        nDraw::Texture* mpZPrepassDummy;  // offset: 0x4f8
        nDraw::Texture* mpOcclusionTexture;  // offset: 0x500
        nDraw::Texture* mpRTMainTarget2;  // offset: 0x508
        nDraw::Texture* mpRTDepthStencil2;  // offset: 0x510
        nDraw::Texture* mpMainTarget2;  // offset: 0x518
        nDraw::Texture* mpDepthStencil2;  // offset: 0x520
        nDraw::Texture* mpDepthStencilReduction;  // offset: 0x528
        nDraw::Texture* mpRTMainTarget;  // offset: 0x530
        nDraw::Texture* mpRTPostTarget;  // offset: 0x538
        nDraw::Texture* mpMainTarget;  // offset: 0x540
        nDraw::Texture* mpMainTargetReduction;  // offset: 0x548
        nDraw::Texture* mpPostTarget;  // offset: 0x550
        nDraw::Texture* mpLightMask;  // offset: 0x558
        nDraw::Texture* mpAmbientMask;  // offset: 0x560
        nDraw::Texture* mpHDRTarget;  // offset: 0x568
        nDraw::Texture* mpHDRQTarget;  // offset: 0x570
        nDraw::Texture* mpBlendTarget;  // offset: 0x578
        nDraw::Texture* mpHDRDepthStencil;  // offset: 0x580
        nDraw::Texture* mpGBuffer;  // offset: 0x588
        nDraw::Texture* mpLightAccumulation0;  // offset: 0x590
        nDraw::Texture* mpLightAccumulation1;  // offset: 0x598
        nDraw::Texture* mpLightAccumulationTexture;  // offset: 0x5a0
        nDraw::Texture* mpGBufferTrans;  // offset: 0x5a8
        nDraw::Texture* mpDSFBufferTrans;  // offset: 0x5b0
        nDraw::Texture* mpLightAccumulationTrans0;  // offset: 0x5b8
        nDraw::Texture* mpLightAccumulationTrans1;  // offset: 0x5c0
        nDraw::Texture* mpLightAccumulationTransTexture;  // offset: 0x5c8
        nDraw::Texture* mpDepthStencilTrans;  // offset: 0x5d0
        nDraw::Texture* mpBackFaceDepthStencil;  // offset: 0x5d8
        nDraw::Texture* mpTempDistortionTex;  // offset: 0x5e0
        nDraw::Texture* mpTanBuffer;  // offset: 0x5e8
        MtColor mClearColor;  // offset: 0x5f0
        nDraw::HDR_TYPE mHDRType;  // offset: 0x5f4
        nDraw::ANTIALIAS_TYPE mAntiAliasType;  // offset: 0x5f8
        nDraw::DEFERRED_LIGHTING_LIGHT_TYPE mDeferredLightingLightType;  // offset: 0x5fc
        nDraw::DEFERRED_LIGHTING_HDR_TYPE mDeferredLightingHDRType;  // offset: 0x600
        nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE mDeferredLightingTransparentType;  // offset: 0x604
        bool mReduction;  // offset: 0x608
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
