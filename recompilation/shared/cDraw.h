#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "nDraw.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtColorF;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtOBB;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSize;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cInstancingCulling;
namespace nDraw { class BlendState; }
namespace nDraw { class CommandCache; }
namespace nDraw { class ConstantTable; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { class DepthStencilView; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Material; }
namespace nDraw { struct OBJECT; }
namespace nDraw { struct OBJECT_INFO; }
namespace nDraw { class Query; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class RenderTargetView; }
namespace nDraw { struct SHADER; }
namespace nDraw { struct SHADER_STATE; }
namespace nDraw { class Scene; }
namespace nDraw { struct TECHNIQUE; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }

// Declarations
class cDraw;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class cDraw : public MtObject
{
    // inferred: cInstancingCulling::beginRecord names cDraw::mJobThreadIndex
    friend class cInstancingCulling;
public:
    enum ENTRY_STATE
    {
        ES_CONSTANT_SET = 2,
        ES_IMMEDIATE_SET = 4,
        ES_DRAW = 8,
        ES_DRAW_CANCEL = 16,
        ES_MATERIAL = 32,
        ES_MATERIAL_CANCEL = 64,
        ES_MATERIAL_MULTIPASS = 128,
        ES_COMMAND_CACHE = 256,
        ES_STATE_DISABLE = 30,
    };
public:
    class MyDTI;
    struct TAG;
    struct CMD;
    struct GEOM_STATE;
    struct CONTEXT;
    struct TARGET_STATE;
    struct VIEWPORT;
    struct DRAW_STATE;
    struct SHADER_STATE;
    struct MISC_STATE;
    struct BRANCH_STATE;
    struct CMD_BRANCH;
    struct STATE_CUE;
    struct SORT_WORK;
    struct MARGE_WORK;
    struct CMD_QUERY;
    struct CMD_DRAW_BASE;
    struct CMD_NOP;
    struct CMD_RESOLVE;
    struct CMD_DRAW;
    struct CMD_CLEAR;
    struct CMD_DRAW_INDEXED;
    struct CMD_MARKER;
    struct CMD_DRAW_INDEXED_INSTANCED;
    struct CMD_DRAW_INSTANCED;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TAG
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 pri : 27;  // offset: 0x0
                u32 pass : 5;  // offset: 0x0
            };  // offset: 0x0
            u32 cmdpri;  // offset: 0x0
        };  // offset: 0x0
        cDraw::CMD* pcmd;  // offset: 0x8
    };
public:
    struct CMD
    {
    public:
        enum TYPE
        {
            T_DRAW = 0,
            T_DRAW_INDEXED = 1,
            T_DRAW_INSTANCED = 2,
            T_DRAW_INDEXED_INSTANCED = 3,
            T_CLEAR = 4,
            T_RESOLVE = 5,
            T_BRANCH = 6,
            T_QUERY = 7,
            T_MARKER = 8,
            T_SYNC = 9,
            T_NOP = 10,
            T_FLUSH = 11,
            T_DRAW_INDEXED_TESSELLATE = 12,
            T_CALLBACK = 13,
        };
    public:
        u32 cache_no : 15;  // offset: 0x0
        u32 draw_cancel : 1;  // offset: 0x0
        u32 type : 4;  // offset: 0x0
        u32 statept : 12;  // offset: 0x0
    };
public:
    struct GEOM_STATE
    {
    public:
        nDraw::VertexBuffer* pvbuf[4];  // offset: 0x0
        u8 stride[4];  // offset: 0x20
        u32 offset[4];  // offset: 0x24
        bool instance[4];  // offset: 0x34
        nDraw::IndexBuffer* pibuf;  // offset: 0x38
        u32 modified;  // offset: 0x40
    };
public:
    struct VIEWPORT
    {
    public:
        MtRect r[4];  // offset: 0x0
        u32 count;  // offset: 0x40
        static const u32 MAX_COUNT = 4;
    };
public:
    struct DRAW_STATE
    {
    public:
        MtColor blendfactor;  // offset: 0x0
        u32 stencilref : 8;  // offset: 0x4
        u32 clockwise : 1;  // offset: 0x4
        u32 scull : 2;  // offset: 0x4
        u32 dbtest : 1;  // offset: 0x4
        u32 modified : 20;  // offset: 0x4
        nDraw::BlendState* pbstate;  // offset: 0x8
        nDraw::DepthStencilState* pdstate;  // offset: 0x10
        nDraw::RasterizerState* prstate;  // offset: 0x18
    };
public:
    struct SHADER_STATE
    {
    public:
        u32 modified : 1;  // offset: 0x0
        u32 modifiedcrc : 1;  // offset: 0x0
        u32 atc : 1;  // offset: 0x0
        u32 atest_func : 8;  // offset: 0x0
        u32 atest_ref : 8;  // offset: 0x0
        u32 atest_rop : 1;  // offset: 0x0
        u32 atest_enable : 1;  // offset: 0x0
        u32 topology : 8;  // offset: 0x0
        u32 padd : 3;  // offset: 0x0
        u32 tech_index : 16;  // offset: 0x4
        u32 tech_pass : 16;  // offset: 0x4
        const nDraw::SHADER* pshader;  // offset: 0x8
        void* resources[1];  // offset: 0x10
    };
public:
    struct MISC_STATE
    {
    public:
        MtFloat3 lod_base_pos;  // offset: 0x0
        u32 occ_no : 7;  // offset: 0xc
        u32 occ_autoupdate : 1;  // offset: 0xc
        u32 auto_zpass : 1;  // offset: 0xc
        u32 disable_gbuffer : 1;  // offset: 0xc
        u32 disable_stretch : 1;  // offset: 0xc
        u32 limit_detect : 1;  // offset: 0xc
        u32 shader_faild : 1;  // offset: 0xc
        u32 reserved : 20;  // offset: 0x10
    };
public:
    struct BRANCH_STATE
    {
    public:
        MT_CTSTR name;  // offset: 0x0
        u32 tag_pt;  // offset: 0x8
    };
public:
    struct CMD_BRANCH : public cDraw::CMD
    {
    public:
        MT_CTSTR name;  // offset: 0x8
        cDraw::TAG* tags;  // offset: 0x10
        u32 tag_num;  // offset: 0x18
    };
public:
    struct STATE_CUE
    {
    public:
        u32 index : 31;  // offset: 0x0
        u32 layout : 1;  // offset: 0x0
        nDraw::SHADER_STATE state;  // offset: 0x8
    };
public:
    struct SORT_WORK
    {
    public:
        cDraw::TAG* tags;  // offset: 0x0
        u32 tag_num;  // offset: 0x8
        cDraw::TAG* dtags;  // offset: 0x10
    };
public:
    struct MARGE_WORK
    {
    public:
        cDraw::SORT_WORK* sorts;  // offset: 0x0
        u32 sort_num;  // offset: 0x8
        cDraw::TAG* dtags;  // offset: 0x10
    };
public:
    struct CMD_QUERY : public cDraw::CMD
    {
    public:
        enum MODE
        {
            MODE_BEGIN = 0,
            MODE_END = 1,
        };
    public:
        u32 mode;  // offset: 0x4
        nDraw::Query* pquery;  // offset: 0x8
    };
public:
    struct CMD_DRAW_BASE : public cDraw::CMD
    {
    public:
        cDraw::TARGET_STATE* ptstate;  // offset: 0x8
        cDraw::DRAW_STATE* pdstate;  // offset: 0x10
        cDraw::SHADER_STATE* psstate;  // offset: 0x18
        cDraw::GEOM_STATE* pgstate;  // offset: 0x20
    };
public:
    struct CMD_NOP : public cDraw::CMD
    {
    };
public:
    struct CMD_RESOLVE : public cDraw::CMD
    {
    public:
        nDraw::Texture* ptarget;  // offset: 0x8
        u32 subresource;  // offset: 0x10
        u32 flags;  // offset: 0x14
        MtRect src;  // offset: 0x18
        MtPoint dest;  // offset: 0x28
        cDraw::CMD_DRAW* pdraw;  // offset: 0x30
    };
public:
    struct CMD_DRAW : public cDraw::CMD_DRAW_BASE
    {
    public:
        u32 vertex_count;  // offset: 0x28
        u32 vertex_start;  // offset: 0x2c
    };
public:
    struct CMD_CLEAR : public cDraw::CMD
    {
    public:
        u32 flags;  // offset: 0x4
        f32 depth;  // offset: 0x8
        u32 stencil;  // offset: 0xc
        f32 color[4];  // offset: 0x10
        cDraw::CMD_DRAW* pdraw;  // offset: 0x20
    };
public:
    struct CMD_DRAW_INDEXED : public cDraw::CMD_DRAW_BASE
    {
    public:
        u32 index_count;  // offset: 0x28
        u32 index_start;  // offset: 0x2c
        u32 index_offset;  // offset: 0x30
    };
public:
    struct CMD_MARKER : public cDraw::CMD
    {
    public:
        u32 mark_type;  // offset: 0x4
        MT_CTSTR marker;  // offset: 0x8
        MtColor color;  // offset: 0x10
    };
public:
    struct CMD_DRAW_INDEXED_INSTANCED : public cDraw::CMD_DRAW_BASE
    {
    public:
        u32 index_count;  // offset: 0x28
        u32 index_start;  // offset: 0x2c
        u32 index_offset;  // offset: 0x30
        u32 instance_count;  // offset: 0x34
        u32 instance_start;  // offset: 0x38
    };
public:
    struct CMD_DRAW_INSTANCED : public cDraw::CMD_DRAW_BASE
    {
    public:
        u32 vertex_count;  // offset: 0x28
        u32 vertex_start;  // offset: 0x2c
        u32 instance_count;  // offset: 0x30
        u32 instance_start;  // offset: 0x34
    };
public:
    struct TARGET_STATE
    {
    public:
        nDraw::RenderTargetView* ptargets[4];  // offset: 0x0
        nDraw::DepthStencilView* pdepthstencil;  // offset: 0x20
        u32 num : 3;  // offset: 0x28
        u32 modified : 1;  // offset: 0x28
        u32 rtflags : 12;  // offset: 0x28
        u32 reserved : 16;  // offset: 0x28
        cDraw::VIEWPORT viewport;  // offset: 0x2c
        MtRect rviewport;  // offset: 0x70
        MtRect scissor;  // offset: 0x80
        MtRect rscissor;  // offset: 0x90
        u32 target_width : 16;  // offset: 0xa0
        u32 target_height : 16;  // offset: 0xa0
    };
public:
    struct CONTEXT
    {
    public:
        cDraw::TARGET_STATE tstate;  // offset: 0x0
        cDraw::DRAW_STATE dstate;  // offset: 0xa8
        cDraw::GEOM_STATE gstate;  // offset: 0xc8
        cDraw::SHADER_STATE sstate;  // offset: 0x110
        u32 pass : 5;  // offset: 0x128
        u32 priority : 27;  // offset: 0x128
        u32 view : 8;  // offset: 0x12c
        u32 techpass : 8;  // offset: 0x12c
        u32 drawmode : 16;  // offset: 0x12c
        u32 drawmask_and : 16;  // offset: 0x130
        u32 drawmask_equal : 16;  // offset: 0x130
        u32 encode_targets;  // offset: 0x134
        u32 convert_type;  // offset: 0x138
        u32 override_pass : 5;  // offset: 0x13c
        u32 pri_ofs : 27;  // offset: 0x13c
        f32 transparency;  // offset: 0x140
        uintptr cacheId;  // offset: 0x148
        bool limit_enable;  // offset: 0x150
        u32 limit_begin;  // offset: 0x154
        u32 limit_end;  // offset: 0x158
        cDraw::MISC_STATE mstate;  // offset: 0x15c
        cDraw::DRAW_STATE* pdstate;  // offset: 0x170
        cDraw::SHADER_STATE* psstate;  // offset: 0x178
        cDraw::GEOM_STATE* pgstate;  // offset: 0x180
        cDraw::TARGET_STATE* ptstate;  // offset: 0x188
        cDraw::SHADER_STATE* pzsstate;  // offset: 0x190
        cDraw::TARGET_STATE* pztstate;  // offset: 0x198
        cDraw::DRAW_STATE* pzdstate;  // offset: 0x1a0
        cDraw::SHADER_STATE* pbf_zsstate;  // offset: 0x1a8
        cDraw::TARGET_STATE* pbf_ztstate;  // offset: 0x1b0
        cDraw::DRAW_STATE* pbf_zdstate;  // offset: 0x1b8
        SO_HANDLE layouts[4];  // offset: 0x1c0
        SO_HANDLE technique;  // offset: 0x1d0
        SO_HANDLE dmytechnique;  // offset: 0x1d4
        nDraw::Scene* pscene;  // offset: 0x1d8
        nDraw::RenderTargetView* pztarget;  // offset: 0x1e0
        nDraw::DepthStencilView* pzdepthstencil;  // offset: 0x1e8
        void* pglobalcb[6];  // offset: 0x1f0
        nDraw::SHADER_STATE states[4096];  // offset: 0x220
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
    cDraw();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void scatterCommand(cDraw* subdraw, u32 num);
    void gatherCommand(cDraw* subdraw, u32 num);
    void setScene(nDraw::Scene* pscene);
    void beginScene(nDraw::Scene* pscene, nDraw::DRAW_MODE mode, MT_CTSTR name);
    void endScene();
    void beginBranch(nDraw::DRAW_MODE drawmode, MT_CTSTR name);
    void endBranch();
    void beginMaterial(nDraw::Material* pm);
    void endMaterial();
    void beginCommandCache();
    nDraw::CommandCache* endCommandCache(u32& dst_cachenum);
    void pushContext(bool allstates);
    void popContext(bool allstates);
    void initContext();
    void setDrawPass(nDraw::PASS_TYPE pass, bool force);
    void setDrawMode(nDraw::DRAW_MODE mode);
    void setDrawModeCullMask(u32 andMask, u32 equalMask);
    void setOverrideDrawPass(nDraw::PASS_TYPE pass);
    void setDrawPriority(u32 pri);
    void setDrawPriorityOffset(u32 ofs);
    void setDrawView(nDraw::DRAW_VIEW view);
    void setRenderTarget(nDraw::RenderTargetView* ptarget, nDraw::DepthStencilView* pds, u32 rtflags, u32 offset);
    void setRenderTargets(u32 num, nDraw::RenderTargetView* * ptargets, nDraw::DepthStencilView* pds, u32 rtflags, u32 offset);
    void setViewport(const MtRect& viewport);
    void setViewports(u32 count, const MtRect* viewports);
    void setScissorRect(const MtRect& rect);
    void setConstantBuffer(SO_HANDLE handle, const nDraw::ConstantTable* pct, u32 block_num);
    nDraw::ConstantTable* beginConstantBuffer(SO_HANDLE handle, bool initialize);
    void endConstantBuffer(SO_HANDLE handle);
    nDraw::ConstantTable* newConstantBuffer(SO_HANDLE handle);
    nDraw::ConstantTable* duplicateConstantBuffer(SO_HANDLE handle);
    void setFunction(SO_HANDLE handle, SO_HANDLE function_handle);
    void setSamplerState(SO_HANDLE handle, SO_HANDLE sampler_handle);
    void setTexture(SO_HANDLE handle, nDraw::Texture* ptex);
    void setBlendState(SO_HANDLE handle, MtColor blendfactor);
    void setBlendState(nDraw::BlendState* pbs, MtColor blendfactor);
    void setDepthStencilState(SO_HANDLE handle, u8 stencilref);
    void setDepthStencilState(nDraw::DepthStencilState* pds, u8 stencilref);
    void setRasterizerState(SO_HANDLE handle);
    void setRasterizerState(nDraw::RasterizerState* prs);
    void setInputLayout(SO_HANDLE handle, u32 slot);
    void setCacheId(uintptr cacheId);
    uintptr getCacheId();
    void setVertexBuffer(u32 slot, nDraw::VertexBuffer* pvbuf, u32 stride, u32 offset);
    void setIndexBuffer(nDraw::IndexBuffer* pibuf, u32 offset);
    void setTechnique(SO_HANDLE handle, s32 pass, SO_HANDLE dmytechnique);
    void setPrimitiveTopology(nDraw::PRIMITIVE_TOPOLOGY topology);
    void setAlphaTest(bool enable, nDraw::COMPARISON_FUNC cmpfunc, u8 ref, bool rop_test);
    void setClockwise(bool clockwise);
    void setOcclusion(bool autoupdate);
    void setAutoZPass(bool enable);
    void setGBufferPass(bool);
    void setStretch(bool enable);
    void setEarlyStencilCulling(nDraw::EARLY_STENCIL_CULLING scull);
    void setDepthBoundsTest(bool, f32, f32);
    void setTransparency(f32 v);
    void disableDepthWrite();
    void clear(u32 clear_flags, const MtColorF& color, f32 depth, u32 stencil);
    void clearOutside(u32 clear_flags, const MtColorF& color, f32 depth, u32 stencil);
    void resolve(nDraw::Texture* ptarget, u32 resolve_flags, u32 subresource);
    void resolve(const MtRect& src, const MtPoint& dest, nDraw::Texture* ptarget, u32 resolve_flags, u32 subresource);
    void beginQuery(nDraw::Query* pquery);
    void endQuery(nDraw::Query* pquery);
    void beginLimit(nDraw::PASS_TYPE begin_pass, u32 begin_priority, nDraw::PASS_TYPE end_pass, u32 end_priority);
    bool endLimit();
    u32 beginDraw();
    void endDraw();
    void draw(u32 vertex_count, u32 start_vertex_location);
    void drawIndexed(u32 index_count, u32 start_index_location, u32 index_base);
    void drawInstanced(u32 vertex_count_per_instance, u32 instance_count, u32 start_vertex_location, u32 instance_start_location);
    void drawIndexedInstanced(u32 index_count_per_instance, u32 instance_count, u32 start_index_location, u32 index_base, u32 instance_start_location);
    void* drawUP(u32 vertex_count, u32 stride);
    void* drawIndexedUP(u32 index_base, u32 vertex_count, u32 index_count, u32 stride, u16* * ppibuf);
    bool drawCommandCache(nDraw::CommandCache* pcmdlist, bool bcopy);
    u32 getDrawMode() const;
    nDraw::PASS_TYPE getDrawPass() const;
    u32 getDrawPriority() const;
    u32 getDrawPriorityOffset() const;
    u32 getJobThreadIndex() const;
    const MtSize getRenderTargetSize() const;
    nDraw::Scene* getScene() const;
    MtRect getViewport() const;
    MtRect getReductionViewport() const;
    nDraw::Texture* getTexture(SO_HANDLE handle) const;
    const nDraw::ConstantTable* getConstantBuffer(SO_HANDLE handle) const;
    nDraw::DRAW_VIEW getDrawView() const;
    SO_HANDLE getFunction(SO_HANDLE handle);
    bool isClockwise();
    SO_HANDLE getTechnique();
    u32 getTechniquePass();
    bool isGBufferPass();
    bool isStretch();
    f32 getTransparency();
    nDraw::RenderTargetView* getRenderTarget(u32 slot);
    nDraw::DepthStencilView* getDepthStencil();
    s32 intersectAABB(const MtAABB& a);
    s32 intersectAABB(const MtAABB& a, s32 cullmask);
    s32 intersectOBB(const MtOBB& obb);
    s32 intersectOBB(const MtOBB& obb, s32 cullmask);
    s32 intersectSphere(const MtSphere& a);
    s32 intersectSphere(const MtSphere& a, s32 cullmask);
    bool cullingAABB(const MtAABB& a);
    bool cullingOBB(const MtOBB& obb);
    bool cullingSphere(const MtSphere& a);
    void setupOcclusion(const MtMatrix& view_projection, const MtMatrix& view_projection_inverse);
    void setupScene(const MtMatrix& view, const MtMatrix& projection, const MtRect& viewport, f32 target_dist);
    const MtMatrix& getViewProjMat();
    const MtMatrix& getViewProjInveseMat();
    const MtMatrix& getViewMat();
    const MtMatrix& getProjMat();
    const MtMatrix& getViewInverseMat();
    const MtMatrix& getProjInverseMat();
    const MtFloat3& getCameraPos();
    const MtFloat3& getCameraDir();
    f32 getCameraNearClip();
    f32 getCameraTargetDist();
    const MtVector4* getViewFrustum();
    MtVector4 getSVPosition(const MtVector3& world_pos);
    void setLODBase(const MtVector3& pos);
    f32 getLODDistance(const MtVector3& world_pos);
    f32 getViewDistance(const MtVector3& world_pos);
    u32 getTransparentPriority(f32 view_dist);
    bool isDrawModeCullMask(u32 drawmode);
    void* allocBuf(size_t size);
    void perfMarker(const MtColor& color, MT_CTSTR name);
    void perfMarkerBegin(const MtColor& color, MT_CTSTR name);
    void perfMarkerEnd();
    void flush();
    bool isLimited();
    bool isShaderFailed() const;
private:
    void duplicateCommandForBackFace();
protected:
    void init();
    void beginCommand(TAG* tags, u32 max_tag);
    u32 endCommand();
    void addState(u32 index);
    void addLayout(u32 index);
    bool setupDraw(const nDraw::TECHNIQUE* ptech, u32 tech_pass);
    TAG* getTags();
    u32 getTagNum();
    const u32& getTotalTagNum() const;
    TAG* sortCommand(TAG* tag, s32 n, TAG* work);
    u8* allocVBuf(u32 size);
    u16* allocIBuf(u32 size);
    void nextBuffer(size_t size);
    void nextVBuffer(u32 size);
    void nextIBuffer(u32 size);
    TAG* entryTag(CMD* pcmd);
    void sortJob(SORT_WORK* pwk);
    void margeJob(MARGE_WORK* pwk);
private:
    void notifyEndDrawToSystem();
protected:
    u32 mObjectNum;  // offset: 0x8
    const nDraw::OBJECT* * mpObjects;  // offset: 0x10
    const nDraw::OBJECT_INFO* mObjectInfos;  // offset: 0x18
    const nDraw::SHADER_STATE* mDefaultStates;  // offset: 0x20
    u8* mpBuffer;  // offset: 0x28
    u8* mpBufferEnd;  // offset: 0x30
    u8* mpVBuffer;  // offset: 0x38
    u8* mpVBufferTop;  // offset: 0x40
    u8* mpVBufferEnd;  // offset: 0x48
    u16* mpIBuffer;  // offset: 0x50
    u16* mpIBufferTop;  // offset: 0x58
    u16* mpIBufferEnd;  // offset: 0x60
    TAG* mTags;  // offset: 0x68
    u32 mTagNum;  // offset: 0x70
    u32 mMaxTag;  // offset: 0x74
    u32 mTagSize;  // offset: 0x78
    TAG* mTempTags;  // offset: 0x80
    u32 mJobThreadIndex;  // offset: 0x88
    u32 mES;  // offset: 0x8c
    u32 mDrawTagPt;  // offset: 0x90
    u32 mMaterialTagPt;  // offset: 0x94
    u32 mMaterialPass;  // offset: 0x98
    u32 mStateCuePt;  // offset: 0x9c
    u32 mCacheTag;  // offset: 0xa0
    u32 mCachePt;  // offset: 0xa4
    nDraw::Material* mpMaterial;  // offset: 0xa8
    GEOM_STATE mGStateUP;  // offset: 0xb0
    u32 mVertexStartUP;  // offset: 0xf8
    GEOM_STATE* mpGStateUP;  // offset: 0x100
    CONTEXT mContext;  // offset: 0x108
    CONTEXT mContextStack[5];  // offset: 0x10328
    BRANCH_STATE mBranchStack[5];  // offset: 0x60dc8
    u32 mStackPt;  // offset: 0x60e18
    CMD_BRANCH* mpBranches[1024];  // offset: 0x60e20
    u32 mBranchNum;  // offset: 0x62e20
    STATE_CUE mStateCue[8192];  // offset: 0x62e28
    u32 mTotalTagNum;  // offset: 0x92e28
public:
    static MyDTI DTI;
    static const u32 MAX_STACK = 5;
protected:
    static const u32 MAX_BRANCHES = 1024;
    static const u32 MAX_SORT_DIV = 8;
    static const u32 MAX_SORT_JOB = 256;
    static const u32 MIN_SORT_NUM = 1024;
    static const u32 MAX_STATE_CUE = 8192;
};
