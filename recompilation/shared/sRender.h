#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtPerformance.h"
#include "MtPrimitive2D.h"
#include "MtThread.h"
#include "MtType.h"
#include "cDraw.h"
#include "cSystem.h"
#include "lwgfxcontext.h"
#include "nDraw.h"
#include "nDrawScene.h"
#include "regs.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPerformance;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSize;
class MtUI;
struct _SceKernelEventFlag;
struct _SceKernelSema;
class cDraw;
class cUnit;
namespace nDraw { class BlendState; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { class DepthStencilView; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { struct InputLayouts; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class RenderTargetView; }
namespace nDraw { class Resource; }
namespace nDraw { struct SCENE_DESC; }
namespace nDraw { class SamplerState; }
namespace nDraw { class Scene; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nPS4 { class PixelShaderObject; }
namespace nPS4 { class VertexShaderObject; }
struct pthread;
class sApp;
namespace sce { namespace Gnm { class ClipControl; } }
namespace sce { namespace Gnmx { class LightweightGfxContext; } }
class uMotionBlurFilter;

// Declarations
class sRender;

// Type aliases from DWARF
using DWORD = unsigned int;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using SO_HANDLE = u32;
using SceKernelEventFlag = _SceKernelEventFlag*;
using SceKernelSema = _SceKernelSema*;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
namespace nDraw { using DeviceContext = sce::Gnmx::LightweightGfxContext; }
namespace nDraw { using HConstantBuffer = void*; }
namespace nDraw { using HCore = void*; }
namespace nDraw { using HDevice = void*; }
namespace nDraw { using HDeviceContext = nDraw::DeviceContext*; }
namespace nDraw { using HIndexBuffer = void*; }
namespace nDraw { using HInputLayout = nDraw::InputLayouts*; }
namespace nDraw { using HPixelShader = nPS4::PixelShaderObject*; }
namespace nDraw { using HVertexBuffer = void*; }
namespace nDraw { using HVertexShader = nPS4::VertexShaderObject*; }
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sRender : public cSystem
{
    // inferred: cUnit::isPossibleDrawFromDrawBuffer names sRender::mpInstance
    friend class cUnit;
    // inferred: sApp::execute names sRender::mpInstance
    friend class sApp;
    // inferred: uMotionBlurFilter::draw names sRender::mpInstance
    friend class uMotionBlurFilter;
public:
    enum FRAME_CACHE_STATE
    {
        FRAME_CACHE_NONE = 0,
        FRAME_CACHE_SETUP = 1,
        FRAME_CACHE_KEEP = 2,
    };
    enum TILED_PRIORITY
    {
        TILED_PRI_TOP = 0,
        TILED_PRI_NORMAL = 1,
        TILED_PRI_NO_BIND = 2,
        TILED_PRI_FORCE_DWORD = -1,
    };
    enum SS_STATE
    {
        SS_NONE = 0,
        SS_WAITING = 1,
        SS_EXECUTE = 2,
        SS_RESOLVE = 3,
        SS_EXPORT = 4,
        SS_EXPORT_SUCCESS = 5,
        SS_SUCCESS = 6,
        SS_FAILED = 7,
        SS_MAX_NUM = 8,
    };
    enum SCREENSHOT_RESULT
    {
        SCREENSHOT_OK = 0,
        SCREENSHOT_FAILED = 1,
        SCREENSHOT_PROCESSING = 2,
    };
    enum DRAW_FILTER
    {
        DRAW_FILTER_AMBIENTOCCLUSION = 0,
        DRAW_FILTER_BLOOM = 1,
        DRAW_FILTER_BLUR = 2,
        DRAW_FILTER_BOKEH = 3,
        DRAW_FILTER_CHROMATICABERRATION = 4,
        DRAW_FILTER_COLORCORRECT = 5,
        DRAW_FILTER_CROSSFADE = 6,
        DRAW_FILTER_DOF = 7,
        DRAW_FILTER_EDGEANTIALIASING = 8,
        DRAW_FILTER_FISHEYE = 9,
        DRAW_FILTER_GODRAYS = 10,
        DRAW_FILTER_HAZE = 11,
        DRAW_FILTER_IMAGEPLANE = 12,
        DRAW_FILTER_MOTIONBLUR = 13,
        DRAW_FILTER_OUTLINE = 14,
        DRAW_FILTER_RADIALBLUR = 15,
        DRAW_FILTER_TANGENTBLUR = 16,
        DRAW_FILTER_TVNOISE = 17,
        DRAW_FILTER_TONEMAPCONTROL = 18,
        DRAW_FILTER_VOLUMENOISE = 19,
        DRAW_FILTER_NUM = 20,
    };
    enum DRAW_FOG
    {
        DRAW_FOG_COLORFOG = 0,
        DRAW_FOG_LIGHTSCATTERINGFOG = 1,
        DRAW_FOG_NUM = 2,
    };
    enum EXPORT_RESULT
    {
        EXPORT_OK = 0,
        EXPORT_FAILED = 1,
        EXPORT_PROCESSED = 2,
    };
    enum RENDERMODE_FLAGS
    {
        RM_D2 = 1,
        RM_D4 = 2,
        RM_D5 = 4,
        RM_VSYNC = 8,
        RM_ENTRY_SERIAL = 128,
        RM_ENTRY_NEXTFRAME = 256,
        RM_SRGB_DISABLE = 512,
        RM_HDPLUS = 1024,
    };
    enum ASPECT_TYPE
    {
        ASPECT_DEFAULT = 0,
        ASPECT_4_3 = 1,
        ASPECT_16_9 = 2,
        ASPECT_16_10 = 3,
    };
    enum
    {
        CONTEXT_NUM = 2,
        PARALLEL_EXECUTE_MAX_NUM = 5,
        DISPLAY_BUFFER_NUM = 3,
        DCB_BUFFER_MAX_NUM = 2,
        DCB_BUFFER_SIZE = 16777216,
        RESOURCE_BUFFER_SIZE = 33554432,
        RING_BUFFER_SIZE = 4194304,
    };
    enum INTERVAL_TYPE
    {
        INTERVAL_IMMEDIATE = 0,
        INTERVAL_ONE = 1,
        INTERVAL_TWO = 2,
        INTERVAL_THREE = 3,
        MAX_INTERVAL = 4,
    };
    enum
    {
        SCALE_MODE_LETTERBOX = 0,
        SCALE_MODE_FULLSCREEN = 1,
        SCALE_MODE_PANSCAN = 2,
    };
    enum DEVICERESET_MODE
    {
        DEVICERESET_NONE = 0,
        DEVICERESET_CHANGEMODE = 1,
        DEVICERESET_REFRESHRATE = 2,
        DEVICERESET_RESIZE = 4,
        DEVICERESET_RESUME = 16,
        DEVICERESET_PRESENTINTERVAL = 32,
        DEVICERESET_HDRLEVEL = 64,
        DEVICERESET_MSAALEVEL = 128,
        DEVICERESET_SLIMODE = 256,
        DEVICERESET_MINIMIZE = 1024,
        DEVICERESET_RSX_RESOLUTION = 2048,
    };
    enum EXPORT_TYPE
    {
        EXPORT_FILE = 0,
        EXPORT_MEMORY = 1,
    };
public:
    class MyDTI;
    struct SCRATCH_INFO;
    struct CAPS;
    struct DISPLAYMODE_INFO;
    struct RenderContext;
    struct ParallelExecuteContext;
    struct EXPORT_THREAD_PARAM;
    class PhotoExportThread;
    struct RENDER_STATE;
    struct COMMAND_STATE;
    struct DETAIL_CONTROL_MODE;
public:
    using TargetState = cDraw::TARGET_STATE;
    using DrawState = cDraw::DRAW_STATE;
    using ShaderState = cDraw::SHADER_STATE;
    using GeomState = cDraw::GEOM_STATE;
    using DrawTag = cDraw::TAG;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SCRATCH_INFO
    {
    public:
        MT_CTSTR pool;  // offset: 0x0
        MT_CTSTR name;  // offset: 0x8
        nDraw::Texture* ptex;  // offset: 0x10
    };
public:
    struct CAPS
    {
    public:
        enum VTF_TYPE
        {
            VTF_R16F = 1,
            VTF_A16B16G16R16F = 2,
            VTF_R32F = 4,
            VTF_A32B32G32R32F = 8,
            VTF_R2VB = 16,
            VTF_MASK = 15,
        };
        enum RT_FORMAT
        {
            RT_A8R8G8B8 = 1,
            RT_A16B16G16R16F = 2,
            RT_A2B10G10R10 = 4,
            RT_B10G11R11F = 8,
        };
    public:
        MT_CHAR name[256];  // offset: 0x0
        MT_CTSTR devicename;  // offset: 0x100
        u32 video_memory;  // offset: 0x108
        u16 vs_version;  // offset: 0x10c
        u16 ps_version;  // offset: 0x10e
        bool puredevice;  // offset: 0x110
        bool gamma;  // offset: 0x111
        bool hdr_blend;  // offset: 0x112
        bool hdr_filtering;  // offset: 0x113
        bool pow2;  // offset: 0x114
        u16 hdr_msaa;  // offset: 0x116
        u16 ldr_msaa;  // offset: 0x118
        u16 mdr_msaa;  // offset: 0x11a
        u16 hdr_csaa;  // offset: 0x11c
        u16 ldr_csaa;  // offset: 0x11e
        u32 mdr_csaa;  // offset: 0x120
        u32 vtf;  // offset: 0x124
        u32 rtf;  // offset: 0x128
    };
public:
    struct DISPLAYMODE_INFO
    {
    public:
        MT_CHAR name[64];  // offset: 0x0
        MT_CHAR hz[16];  // offset: 0x40
        u32 w;  // offset: 0x50
        u32 h;  // offset: 0x54
        f32 refreshrate;  // offset: 0x58
    };
public:
    struct RenderContext
    {
    public:
        nDraw::DeviceContext context;  // offset: 0x0
        void* dcbBuffer;  // offset: 0xcb00
        void* resourceBuffer;  // offset: 0xcb08
        void* globalResourceTable;  // offset: 0xcb10
    };
public:
    struct ParallelExecuteContext
    {
    public:
        ScePthread mThreadHandle;  // offset: 0x0
        sRender::RenderContext* mpRenderContext;  // offset: 0x8
        cDraw::TAG* mpTag;  // offset: 0x10
        u32 mTagNum;  // offset: 0x18
        u32 mNo;  // offset: 0x1c
    };
public:
    struct EXPORT_THREAD_PARAM
    {
    public:
        u32 type;  // offset: 0x0
        MT_CTSTR dir;  // offset: 0x8
        MT_CTSTR file;  // offset: 0x10
        void* memory;  // offset: 0x18
        u32 success;  // offset: 0x20
        u32 size;  // offset: 0x24
    };
public:
    class PhotoExportThread : public MtThread
    {
    public:
        PhotoExportThread(void* pcontext);
        virtual ~PhotoExportThread();
        virtual void execute(void* pcontext);  // vtable slot 6
    };
public:
    struct COMMAND_STATE
    {
    public:
        MT_CTSTR name;  // offset: 0x0
        sRender::DrawTag* ptag;  // offset: 0x8
        sRender::DrawTag* ptag_end;  // offset: 0x10
    };
public:
    struct DETAIL_CONTROL_MODE
    {
    public:
        enum DECL
        {
            STANDARD = 0,
            AGGRESSIVE = 1,
            MAX = 2,
        };
    };
public:
    struct RENDER_STATE
    {
    public:
        u32 inversez : 1;  // offset: 0x0
        u32 atest_ref : 8;  // offset: 0x0
        u32 atest_func : 16;  // offset: 0x0
        u32 atest_enable : 1;  // offset: 0x0
        u32 zpass_exec : 1;  // offset: 0x0
        u32 onepass_exec : 1;  // offset: 0x0
        u32 scull : 2;  // offset: 0x0
        u32 zprepass_enable : 1;  // offset: 0x0
        u32 onepass_zpass_enable : 1;  // offset: 0x0
        nDraw::HDeviceContext pdevice;  // offset: 0x8
        sRender::TargetState* ptstate;  // offset: 0x10
        sRender::DrawState* pdstate;  // offset: 0x18
        sRender::ShaderState* psstate;  // offset: 0x20
        sRender::GeomState* pgstate;  // offset: 0x28
        nDraw::BlendState* pblend;  // offset: 0x30
        nDraw::RasterizerState* prasterizer;  // offset: 0x38
        nDraw::DepthStencilState* pdepthstencil;  // offset: 0x40
        nDraw::HVertexShader pvs;  // offset: 0x48
        nDraw::HPixelShader pps;  // offset: 0x50
        nDraw::HInputLayout playout;  // offset: 0x58
        nDraw::HIndexBuffer pibuf;  // offset: 0x60
        nDraw::HVertexBuffer pvbuf[4];  // offset: 0x68
        u32 vstride[4];  // offset: 0x88
        u32 voffset[4];  // offset: 0x98
        MtRect viewport[4];  // offset: 0xa8
        MtRect scissor;  // offset: 0xe8
        nDraw::RenderTargetView* ptarget[4];  // offset: 0xf8
        nDraw::DepthStencilView* pdepth;  // offset: 0x118
        nDraw::SamplerState* pvssamplers[16];  // offset: 0x120
        nDraw::SamplerState* ppssamplers[16];  // offset: 0x1a0
        nDraw::Texture* pvstextures[16];  // offset: 0x220
        nDraw::Texture* ppstextures[16];  // offset: 0x2a0
        nDraw::HConstantBuffer pvscbuffers[16];  // offset: 0x320
        nDraw::HConstantBuffer ppscbuffers[16];  // offset: 0x3a0
        nDraw::SamplerState* pgssamplers[16];  // offset: 0x420
        nDraw::Texture* pgstextures[16];  // offset: 0x4a0
        nDraw::HConstantBuffer pgscbuffers[16];  // offset: 0x520
        nDraw::SamplerState* phssamplers[16];  // offset: 0x5a0
        nDraw::SamplerState* pdssamplers[16];  // offset: 0x620
        nDraw::SamplerState* pcssamplers[16];  // offset: 0x6a0
        nDraw::Texture* phstextures[16];  // offset: 0x720
        nDraw::Texture* pdstextures[16];  // offset: 0x7a0
        nDraw::Texture* pcstextures[16];  // offset: 0x820
        nDraw::HConstantBuffer phscbuffers[16];  // offset: 0x8a0
        nDraw::HConstantBuffer pdscbuffers[16];  // offset: 0x920
        nDraw::HConstantBuffer pcscbuffers[16];  // offset: 0x9a0
        sRender::COMMAND_STATE cs[1024];  // offset: 0xa20
        s32 cs_pt;  // offset: 0x6a20
        u32 max_vertex;  // offset: 0x6a24
        MtColor blendfactor;  // offset: 0x6a28
        u32 wait_addr[4];  // offset: 0x6a2c
        u32 wait_addr_pt;  // offset: 0x6a3c
        u32 index_offset;  // offset: 0x6a40
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
    sRender(u32 rendermode_flags, u32 cmdbufsize, u32 ringbufsize, u32 tempvertexbufsize, u32 tempindexbufsize, nDraw::HDR_TYPE hdrtype, nDraw::ANTIALIAS_TYPE aatype, u32 scene_flags);
    virtual ~sRender();
    void begin();
    void end();
    void wait();
    void sync();
    virtual void setup();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void beforeMove();
    void setFrameSkip(bool);
    bool isFrameSkip();
    bool isRendering();
    static sRender* getInstance();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    uintptr getThreadID();
    void redraw();
    const CAPS& getCaps();
    u32 getProtectedResourceNum();
    nDraw::HDevice getDevice();
    nDraw::HDeviceContext getDeviceContext();
    u32 getDeviceReset() const;
    u32 isDeviceReset();
    void setAspectType(u32 v);
    u32 getAspectType();
    void setScaleMode(u32 scaleMode);
    u32 getScaleMode();
    f32 getDACGamma();
    void setDACGamma(f32 v);
    void setPresentInterval(u32 interval);
    void setPresentThreshold(u32 t);
    u32 getPresentInterval();
    u32 getPresentThreshold();
    void setPresentWidth(u32 w);
    void setPresentHeight(u32 h);
    u32 getPresentWidth() const;
    u32 getPresentHeight() const;
    MtRect getPresentRect() const;
    virtual void setFullScreenMode(bool fullscreen, const MtSize& base_sz, bool force);  // vtable slot 11
    bool isFullScreenMode();
    bool isSaveInstanceDrawCount() const;
    void setSaveInstanceDrawCount(bool);
    bool isDrawFilter(DRAW_FILTER TargetFilter) const;
    void setDrawFilter(bool, DRAW_FILTER);
    bool isDrawFog(DRAW_FOG TargetFog) const;
    void setDrawFog(bool, DRAW_FOG);
    nDraw::Scene* getPrimaryScene();
    nDraw::HDR_TYPE getHDRType();
    void setHDRType(nDraw::HDR_TYPE type);
    nDraw::ANTIALIAS_TYPE getAntiAliasType() const;
    void setAntiAliasType(nDraw::ANTIALIAS_TYPE type);
    MT_CTSTR getAntiAliasTypeName() const;
    nDraw::ANTIALIAS_ALT_TYPE getAntiAliasAltType() const;
    void setAntiAliasAltType(nDraw::ANTIALIAS_ALT_TYPE type);
    u32 getSceneAttribute();
    void setSceneAttribute(u32 v);
    f32 getHDREmphasis();
    void setHDREmphasis(f32 v);
    MtSize getScreenSize();
    f32 getAdjustAspectRate();
    nDraw::DEFERRED_LIGHTING_LIGHT_TYPE getDeferredLightingLightType() const;
    void setDeferredLightingLightType(nDraw::DEFERRED_LIGHTING_LIGHT_TYPE type);
    nDraw::DEFERRED_LIGHTING_HDR_TYPE getDeferredLightingHDRType() const;
    void setDeferredLightingHDRType(nDraw::DEFERRED_LIGHTING_HDR_TYPE type);
    nDraw::DEFERRED_LIGHTING_NORMAL_TYPE getDeferredLightingNormalEncodeType() const;
    void setDeferredLightingNormalEncodeType(nDraw::DEFERRED_LIGHTING_NORMAL_TYPE type);
    nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE getDeferredLightingTransparentType() const;
    void setDeferredLightingTransparentType(nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE type);
    bool isDeferredLightingHybridLighting() const;
    void setDeferredLightingHybridLighting(bool);
    bool isDeferredLightingForcedForwardRendering() const;
    void setDeferredLightingForcedForwardRendering(bool);
    f32 getDeferredLightingDiffuseLuminanceThreshold() const;
    void setDeferredLightingDiffuseLuminanceThreshold(f32);
    bool isDeferredLightingFadeOutLighting() const;
    void setDeferredLightingFadeOutLighting(bool);
    f32 getDeferredLightingFadeOutLightingDistance() const;
    void setDeferredLightingFadeOutLightingDistance(f32 distance);
    f32 getDeferredLightingLodThreshold() const;
    void setDeferredLightingLodThreshold(f32);
    f32 getDeferredLightingLogRangeCoeffEncode() const;
    void setDeferredLightingLogRangeCoeffEncode(f32);
    f32 getDeferredLightingLogRangeCoeffDecode() const;
    bool isTangentRendering() const;
    void setTangentRendering(bool);
    f32 getHalfLambertBlendCoeff() const;
    void setHalfLambertBlendCoeff(f32 coeff);
    f32 getRenderFps();
    s64 getRenderPeformanceCounter() const;
    bool isSRGBEnable() const;
    void setSLI(bool v);
    bool isSLI() const;
    void setStereo(bool v);
    bool isStereo() const;
    f32 getPersRate() const;
    void setPersRate(f32);
    u32 getWbFlag() const;
    u32 getFrameCount() const;
    void* allocDrawBuffer(u32 size);
    void* allocVertexBuffer(u32 size);
    void* allocIndexBuffer(u32 size);
    nDraw::VertexBuffer* getVertexBuffer();
    nDraw::IndexBuffer* getIndexBuffer();
    u32 getCommandBufferUsedSize() const;
    u32 getVertexBufferUsedSize() const;
    u32 getIndexBufferUsedSize() const;
    void* getVertexBufferTop();
    void* getIndexBufferTop();
    void beginFrameCache();
    void endFrameCache();
    void drawFrameCache(cDraw* pdraw, const MtRect* pdrect, const MtRect* psrect);
    u32 getSkinningBorder() const;
    u32 getSkinningBorderEx() const;
    bool isParallelRendering();
    nDraw::FEATURE_LV getFeatureLevel() const;
    void setFeatureLevel(nDraw::FEATURE_LV);
    void resetDevice();
    void setMipLODBias(f32 v);
    f32 getMipLODBias() const;
    bool isCommandBuffer(void* ptr);
    void setParallelExecuteNum(u32 num);
    u32 getParallelExecuteNum() const;
    nDraw::Texture* getBackBuffer() const;
    MtSize getBackBufferSize();
    void makeMipMapSubLevel(cDraw* pdraw, nDraw::Texture* ptexture, nDraw::Texture* ptemp, SO_HANDLE func, bool clear_min_level, MtColor clear_color);
    void copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size, bool duplicateFor3DStereo, bool drawBkBuf);
private:
    void applyGammaCurve(f32 gf);
    static void* rendering(void* pArg);
    void init(u32 rendermode_flags, u32 ringbufsize);
    void updateFrameCache(cDraw* pdraw);
    void flush();
    void execute2(u32 parallelNo);
    void beginRendering();
    void endRendering();
    void addProtectResource(nDraw::Resource* pres);
    nDraw::Texture* addScratchTexture(MT_CTSTR pool, MT_CTSTR name, nDraw::Texture* ptex, u32* poffset);
    void removeScratchTexture(nDraw::Texture* ptex);
    void setTargetState(RENDER_STATE& rs, cDraw::TARGET_STATE* pts);
    void setDrawState(RENDER_STATE& rs, cDraw::DRAW_STATE* pds);
    void setGeomState(RENDER_STATE& rs, cDraw::GEOM_STATE* pgs, u32 start);
    void setShaderState(RENDER_STATE& rs, cDraw::SHADER_STATE* pss);
    void setBranch(RENDER_STATE& rs, cDraw::CMD_BRANCH* pbranch);
    void initRenderState(RENDER_STATE& rs, u32 parallelNo);
    void finalRenderState(RENDER_STATE& rs, u32 parallelNo);
    cDraw::TAG* getNextTag(RENDER_STATE& rs);
    cDraw::TAG* nextTag(RENDER_STATE& rs);
    void setViewports(RENDER_STATE& rs, u32 num, const MtRect* prects);
    void clearWaitAddr(RENDER_STATE& rs);
    bool findWaitAddr(RENDER_STATE& rs, u32 addr);
    void addWaitAddr(RENDER_STATE& rs, u32 addr);
    void invalidateWaitAddr(RENDER_STATE& rs, u32 addr);
    static void notifyBeginRendering(DWORD);
    static void notifyEndRendering(DWORD);
    void createCaps();
    void createDisplayModeInfo();
    nDraw::SCENE_DESC createSceneDesc() const;
public:
    void drawBackBuffer(cDraw* pdraw, u32 display_no);
    void performanceMarker(RENDER_STATE& rs, const cDraw::CMD_MARKER* p_cmd);
    void performanceBeginEvent(RENDER_STATE& rs, const MtColor& color, MT_CTSTR name);
    void performanceEndEvent(RENDER_STATE& rs);
    void performanceSetMarker(RENDER_STATE& rs, const MtColor& color, MT_CTSTR name);
protected:
    s32 getResolution();
    void setResolution(s32 v);
    s32 getRefreshRate();
    void setRefreshRate(s32 v);
    void endProtect();
    void setRenderFps(f32);
public:
    void tiledPriorityWrapper(TILED_PRIORITY);
    void tiledPriorityEndWrapper();
    u32 getTempVertexBufSize() const;
    u32 getUsedTempVertexBufSize() const;
    u32 getTempIndexBufSize() const;
    u32 getUsedTempIndexBufSize() const;
    u32 getDrawBufSize() const;
    u32 getUsedDrawBufSize() const;
    f32 getUsedDrawBufParcent() const;
    virtual bool isPossibleDrawFromDrawBuffer();  // vtable slot 12
private:
    s32 initVideoOut();
    s32 termVideoOut();
    void resetContext();
    s32 submitAndFlip(u32 videoOutHandle, u32 rtIndex, u32 flipMode, s64 flipArg, u32 parallelNo);
    s32 submit(u32 parallelNo);
    u32 serializeTags(cDraw::TAG* pdst, u32 dst_num, const cDraw::TAG* psrc, u32 src_num);
    u32 serializeTagsRecursive(u32 cur_index, cDraw::TAG* pdst, u32 dst_num, const cDraw::TAG* psrc, u32 src_num);
    void distributeTags(cDraw::TAG* ptag, u32 tag_num);
    static void* renderingSub(void* pArg);
public:
    bool beginScreenShot();
    bool setScreenShotTrigger();
    SCREENSHOT_RESULT screenShotResult();
    u32 getJpgSize();
    u32 outputJpg(void* pout);
    bool endScreenShot();
private:
    void initPhotoExport();
    void destroyPhotoExport();
public:
    void photoExportThreadMain(EXPORT_THREAD_PARAM* th_param);
    void setPhotoExportTriggerFromMemory(void* pdata, u32 size);
    EXPORT_RESULT photoExportResult();
    void setPhotoExportParam(MT_CTSTR photo_title, MT_CTSTR game_title, MT_CTSTR comment);
private:
    bool resolveScreenShot(cDraw* pdraw);
    void finishScreenShot();
    void clearScreenShotJpgBuff();
public:
    void resetFlipBeforeCallback();
    void setFlipBeforeCallBack(MtObject* pparent, MT_MFUNC pcallback);
    void callFlipBeforeCallBack();
    void setRenderDetailControl(bool b);
    bool getRenderDetailControl();
    f32 getRenderDetailUpper();
    f32 getRenderDetailDowner();
    u32 getRenderDetailLevel();
    bool getRenderDetailChanged();
    void setRenderDetailControlFramerates(DETAIL_CONTROL_MODE::DECL mode);
    void calcRenderDetailLevel();
    void setShaderStateOptimizeZero(RENDER_STATE& rs, cDraw::SHADER_STATE* pss);
    // Address: 0x01ba6be0 - 0x01ba6be1 (1 bytes)
    virtual void rsxSyncBackEnd(cDraw* pDraw) {}  // vtable slot 13
protected:
    bool mIsDrawFilterArray[20];  // offset: 0x11
    bool mIsDrawFogArray[2];  // offset: 0x25
    bool mRendering;  // offset: 0x27
    bool mFrameSkip;  // offset: 0x28
    bool mFullScreenMode;  // offset: 0x29
    bool mDisableRendering;  // offset: 0x2a
    bool mParallelTrans;  // offset: 0x2b
    bool mParallelRendering;  // offset: 0x2c
    bool mParallelRenderingActive[2];  // offset: 0x2d
    f32 mPersRate;  // offset: 0x30
    u32 mRenderModeFlags;  // offset: 0x34
    bool mConnectDrawCall;  // offset: 0x38
    bool mSRGBEnable;  // offset: 0x39
    nDraw::FEATURE_LV mFeatureLevel;  // offset: 0x3c
    MtPerformance mPerf;  // offset: 0x40
    nDraw::HDevice mpDevice;  // offset: 0xa0
    nDraw::HDeviceContext mpDeviceContext;  // offset: 0xa8
    nDraw::HCore mpCore;  // offset: 0xb0
    MtRect mPresentRect;  // offset: 0xb8
    MtSize mScreenSize;  // offset: 0xc8
    MtSize mDisplaySize;  // offset: 0xd0
    ScePthread mThreadHandle;  // offset: 0xd8
    uintptr mThreadID;  // offset: 0xe0
    SceKernelSema mRenderEvent;  // offset: 0xe8
    SceKernelSema mSyncEvent;  // offset: 0xf0
    f32 mDACGamma;  // offset: 0xf8
    bool mUpdateGamma;  // offset: 0xfc
    bool mDynamicTrans;  // offset: 0xfd
    bool mExit;  // offset: 0xfe
    u32 mScaleMode;  // offset: 0x100
    u32 mAspectType;  // offset: 0x104
    nDraw::ANTIALIAS_TYPE mAntiAliasType;  // offset: 0x108
    nDraw::ANTIALIAS_ALT_TYPE mAntiAliasAltType;  // offset: 0x10c
    nDraw::HDR_TYPE mHDRType;  // offset: 0x110
    u32 mSceneAttribute;  // offset: 0x114
    u32 mSkinningBorder;  // offset: 0x118
    u32 mSkinningBorderEx;  // offset: 0x11c
    f32 mMipLODBias;  // offset: 0x120
    nDraw::DEFERRED_LIGHTING_LIGHT_TYPE mDeferredLightingLightType;  // offset: 0x124
    nDraw::DEFERRED_LIGHTING_HDR_TYPE mDeferredLightingHDRType;  // offset: 0x128
    bool mDeferredLightingHybridLighting;  // offset: 0x12c
    bool mDeferredLightingForcedForwardRendering;  // offset: 0x12d
    nDraw::DEFERRED_LIGHTING_NORMAL_TYPE mDeferredLightingNormalType;  // offset: 0x130
    nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE mDeferredLightingTransparentType;  // offset: 0x134
    f32 mDeferredLightingDiffuseLuminanceThreshold;  // offset: 0x138
    bool mDeferredLightingFadeOutLighting;  // offset: 0x13c
    f32 mDeferredLightingFadeOutLightingDistance;  // offset: 0x140
    f32 mDeferredLightingLodThreshold;  // offset: 0x144
    f32 mDeferredLightingLogRangeCoeffEncode;  // offset: 0x148
    bool mTangentRendering;  // offset: 0x14c
    f32 mHalfLambertBlendCoeff;  // offset: 0x150
    u32 mTrilinearThreshold;  // offset: 0x154
    f32 mAnisotropyBias;  // offset: 0x158
    cDraw mDraw;  // offset: 0x160
    u32 mWbFlag;  // offset: 0x92f90
    u32 mFrameCount;  // offset: 0x92f94
    u8* mpDrawBuffer[3];  // offset: 0x92f98
    s32 mDrawBufferPt;  // offset: 0x92fb0
    u32 mDrawBufferSize;  // offset: 0x92fb4
    cDraw::TAG mDrawTagBuffer[2][262144];  // offset: 0x92fb8
    cDraw::TAG mDrawTagBufferSerial[2][262144];  // offset: 0x892fb8
    cDraw::TAG* mpDrawTags[2];  // offset: 0x1092fb8
    u32 mDrawTagNum[2];  // offset: 0x1092fc8
    u32 mDrawTotalTagNum;  // offset: 0x1092fd0
    nDraw::VertexBuffer* mpTempVertexBuf[3];  // offset: 0x1092fd8
    nDraw::IndexBuffer* mpTempIndexBuf[3];  // offset: 0x1092ff0
    u8* mpTempVertexBufTop;  // offset: 0x1093008
    u16* mpTempIndexBufTop;  // offset: 0x1093010
    u32 mTempVertexBufSize;  // offset: 0x1093018
    u32 mTempIndexBufSize;  // offset: 0x109301c
    s32 mTempVertexBufPt;  // offset: 0x1093020
    s32 mTempIndexBufPt;  // offset: 0x1093024
    nDraw::Texture* mpScratchTexture;  // offset: 0x1093028
    MtSize mBackBufferSize;  // offset: 0x1093030
    nDraw::Scene* mpPrimaryScene;  // offset: 0x1093038
    nDraw::Texture* mpBackBuffer;  // offset: 0x1093040
    nDraw::Texture* mpFrameCacheBuffer;  // offset: 0x1093048
    u32 mPresentInterval;  // offset: 0x1093050
    u32 mPresentThreshold;  // offset: 0x1093054
    FRAME_CACHE_STATE mFrameCacheState;  // offset: 0x1093058
    s64 mRenderCounter;  // offset: 0x1093060
    s64 mRenderTime;  // offset: 0x1093068
    bool mSLI;  // offset: 0x1093070
    bool mStereo;  // offset: 0x1093071
    u32 mDeviceReset;  // offset: 0x1093074
    f32 mRefreshRate;  // offset: 0x1093078
    u32 mRingBufSize;  // offset: 0x109307c
    u32 mVSGPRCount;  // offset: 0x1093080
    u32 mIsDeviceReset;  // offset: 0x1093084
    bool mIsSaveInstanceDrawCount;  // offset: 0x1093088
    MtPerformance mPerformance;  // offset: 0x1093090
    u32 mFence[2];  // offset: 0x10930f0
    nDraw::Resource* mpProtectResources[8192];  // offset: 0x10930f8
    SCRATCH_INFO mpScratchTextures[512];  // offset: 0x10a30f8
    u32 mProtectResourceNum;  // offset: 0x10a60f8
    u32 mScratchTextureNum;  // offset: 0x10a60fc
    CAPS mCaps;  // offset: 0x10a6100
    DISPLAYMODE_INFO mDisplayModeInfo[256];  // offset: 0x10a6230
    u32 mDisplayModeNum;  // offset: 0x10abe30
    MT_ENUM mResolutionList[257];  // offset: 0x10abe38
    MT_ENUM mRefreshRateList[33];  // offset: 0x10ace48
private:
    TILED_PRIORITY mTiledPriority;  // offset: 0x10ad058
    RenderContext mRenderContext[2][5];  // offset: 0x10ad060
    nDraw::Texture* mpDisplayBuffers[3];  // offset: 0x112bf50
    sce::Gnm::ClipControl mClipControl;  // offset: 0x112bf68
public:
    s32 mVideoOutHandle;  // offset: 0x112bf6c
private:
    u32* mpDrawSyncLabel;  // offset: 0x112bf70
    u32 mSyncFrame;  // offset: 0x112bf78
    void* mpTimestampStart;  // offset: 0x112bf80
    void* mpTimestampEnd;  // offset: 0x112bf88
    bool mIsSubmit;  // offset: 0x112bf90
    bool mIsDisableSubmit;  // offset: 0x112bf91
    void* mpEsGsRingBuffer;  // offset: 0x112bf98
    void* mpGsVsRingBuffer;  // offset: 0x112bfa0
    ParallelExecuteContext mParallelExecuteContext[5];  // offset: 0x112bfa8
    SceKernelEventFlag mParallelExecuteEventFlag;  // offset: 0x112c048
    u32 mParallelExecuteNum;  // offset: 0x112c050
    u32 mParallelExecuteNumActive[2];  // offset: 0x112c054
public:
    EXPORT_THREAD_PARAM mExportParam;  // offset: 0x112c060
private:
    volatile bool mPhotoExportInitialized;  // offset: 0x112c088
    volatile bool mPollingCallback;  // offset: 0x112c089
    volatile bool mPhotoExportCallbackSuccess;  // offset: 0x112c08a
    MT_CHAR mPhotoExportPhotoTitle[1024];  // offset: 0x112c08b
    MT_CHAR mPhotoExportGameTitle[1024];  // offset: 0x112c48b
    MT_CHAR mPhotoExportComment[1024];  // offset: 0x112c88b
public:
    PhotoExportThread* mpExportThread;  // offset: 0x112cc90
private:
    nDraw::Texture* mpScreenShotTexture;  // offset: 0x112cc98
    SS_STATE mSSState;  // offset: 0x112cca0
    SCREENSHOT_RESULT mSSResult;  // offset: 0x112cca4
    void* mJpgBuffer;  // offset: 0x112cca8
    u32 mJpgBufferSize;  // offset: 0x112ccb0
public:
    MtObject* mpFlipBeforeInstance;  // offset: 0x112ccb8
    MT_MFUNC mpFlipBeforeCallBack;  // offset: 0x112ccc0
    bool mRenderDetailControlEnable;  // offset: 0x112ccd0
    u32 mRenderDetail;  // offset: 0x112ccd4
    u32 mBeforeRenderDetail;  // offset: 0x112ccd8
    u32 mRenderDetailInterval;  // offset: 0x112ccdc
    bool mbRenderDetailChanged;  // offset: 0x112cce0
    f32 mRenderDetailUpper;  // offset: 0x112cce4
    f32 mRenderDetailDowner;  // offset: 0x112cce8
    static MyDTI DTI;
    static const u32 RESET_INDEX = 65535;
    static const u32 MAX_TEMPBUF = 3;
private:
    static const u32 CDRAW_MAX_BRANCHES = 1024;
    static const u32 MAX_WAITADDR = 4;
protected:
    static sRender* mpInstance;
    static const s32 RENDER_PROCESSOR = 5;
    static const s32 MIN_SCRATCHSIZE = 9216000;
    static const u32 MAX_DRAWTAG = 262144;
    static const s32 MAX_RENDERTIME_LOG = 3;
    static const u32 MAX_PROTECTRESOURCE = 8192;
    static const u32 MAX_SCRATCHTEXTURE = 512;
    static const u32 MAX_DISPLAYMODELIST = 256;
    static const u32 MAX_REFRESHRATELIST = 32;
private:
    static s32 mPhotoExportThreadActive;
    static s32 mSSTrigger;
};
