#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cBlendState.h"
#include "cSystem.h"
#include "nDraw.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtColorF;
class MtDTI;
struct MtFloat3;
struct MtFloat4;
class MtMatrix;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class MtVector4;
class cBlendState;
class cDraw;
class cParticleManager;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class VertexBuffer; }
namespace nPrim { struct Material; }
namespace nPrim { struct Rect; }
class rTexture;

// Declarations
class sGpuParticle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class sGpuParticle : public cSystem
{
    // inferred: cParticleManager::~cParticleManager names sGpuParticle::mpInstance
    friend class cParticleManager;
public:
    class MyDTI;
    class Context;
    struct Particle;
    class PacketBuffer;
    class ContextInfParticle;
    class StaticBuffer;
    class ContextParticle;
    class ContextPoint;
    class ContextLine;
    class ContextPolyline;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Context
    {
    public:
        enum MODE
        {
            MODE_NULL = 0,
            MODE_BATCH = 1,
            MODE_BURST = 2,
        };
        enum eState
        {
            UNALLOCATED = 0,
            READY = 1,
            NO_MEMORY = 2,
        };
    public:
        struct DrawCtx;
        struct LvCorrection;
    public:
        struct LvCorrection
        {
        public:
            LvCorrection(f32 i_min, f32 i_max, s32 i_att, MtFloat3 col);
        public:
            f32 lv_min;  // offset: 0x0
            f32 lv_max;  // offset: 0x4
            s32 atten;  // offset: 0x8
            MtFloat3 color_const;  // offset: 0xc
        };
    public:
        struct DrawCtx
        {
        public:
            u32 used;  // offset: 0x0
            u32 drawn;  // offset: 0x4
            sGpuParticle::Context::eState buffer_state;  // offset: 0x8
            rTexture* p_texture;  // offset: 0x10
            MtPoint tex_basepos;  // offset: 0x18
            u32 tex_size;  // offset: 0x20
            u32 tex_row;  // offset: 0x24
            u32 tex_total;  // offset: 0x28
            void* p_vtx_buffer;  // offset: 0x30
            void* p_current_ptr;  // offset: 0x38
            u32 vtx_buffer_ofs;  // offset: 0x40
            u16* p_idx_buffer;  // offset: 0x48
            u16* p_current_idx;  // offset: 0x50
            u32 idx_buffer_ofs;  // offset: 0x58
            void* p_temp_vb;  // offset: 0x60
            u32 temp_vb_size;  // offset: 0x68
            u16* p_temp_ib;  // offset: 0x70
            u32 temp_ib_size;  // offset: 0x78
            sGpuParticle::Context::LvCorrection lv_correction;  // offset: 0x7c
        };
    public:
        MODE getMode() const;
        u32 getCapacity() const;
        void changeCapacity(u32);
        virtual s32 setTexture(cDraw* p_draw, rTexture* p_tex, const MtPoint& base_pos, u32 size, u32 row_num, u32 total_num);  // vtable slot 0
        virtual s32 allocateParticle(cDraw*) = 0;  // vtable slot 1
        virtual s32 setParticle(cDraw*, const sGpuParticle::Particle&) = 0;  // vtable slot 2
        virtual s32 drawParticleArray(cDraw*, nDraw::PASS_TYPE, u32, const nPrim::Material&, s32) = 0;  // vtable slot 3
        static void* operator new(size_t sz);
        static void* operator new[](size_t);
        static void operator delete(void* p_addr);
        static void operator delete[](void*);
        u32 getDrawNum() const;
        u32 getDrawNum(u32) const;
        s32 setLvCorrection(cDraw* p_draw, const LvCorrection& lv_corr);
    protected:
        Context(MODE mode, u32 max_num);
        virtual ~Context();
        virtual void update(cDraw* p_draw);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual void setFogFunc(cDraw* p_draw, bool fog_enable, u32 bs_idx);  // vtable slot 8
        void reset(DrawCtx* p_ctx, bool release_temp);
        DrawCtx* getDrawCtx(cDraw* p_draw);
    protected:
        sGpuParticle::Context* mpNext;  // offset: 0x8
        sGpuParticle::Context* mpPrev;  // offset: 0x10
        MODE mMode;  // offset: 0x18
        u32 mMaxCapacity;  // offset: 0x1c
        u32 mNewMaxCapacity;  // offset: 0x20
        DrawCtx mDrawCtx[6];  // offset: 0x28
    };
public:
    struct Particle
    {
    public:
        Particle(const MtFloat3& i_pos, const MtColor& i_color, u32 i_scale, u32 i_index, u32 i_intensity, u32 i_rot);
        Particle(const MtFloat3&, const MtColor&, u32, u32, u32, s32, s32, u32);
        Particle(const MtFloat3& i_pos, const MtFloat3& i_dir, const MtColor& i_color, u32 i_scale, u32 i_intensity);
        Particle(const MtFloat3&, const MtColor&, u32, f32);
        void setPosition(const MtFloat3& i_pos);
        void setLineVec(const MtFloat3& i_vec);
        MtFloat3 getLineVec();
        void setColor(const MtColor& col);
        void setScale(u32 scl);
        void setLineScl(u32 scl);
        void setIndex(u32 idx);
        void setIntensity(u32 int_v);
        void setLineInt(u32 int_v);
        void setUvScale(s32 u_scl, s32 v_scl);
        void setUvScale(f32, f32);
        void setRotation(u32 rot);
        void setPolylineIntensity(u32 int_v);
        void setPolylineScale(f32 scl);
        void setPolylineTexCoord(s32 u, s32 v);
        void setPolylineTangent(const MtVector3& tangent);
        void setPolylineWidth(float width);
    public:
        MtFloat3 pos;  // offset: 0x0
        MtColor color;  // offset: 0xc
        union
        {
        public:
            struct
            {
            public:
                u32 scale : 16;  // offset: 0x0
                u32 index : 16;  // offset: 0x0
                u32 hdr_intensity : 16;  // offset: 0x4
                u32 rotation : 16;  // offset: 0x4
                s16 texcoord_scale[2];  // offset: 0x8
                u32 reserved;  // offset: 0xc
            };  // offset: 0x0
            struct
            {
            public:
                f32 line_vec[3];  // offset: 0x0
                u32 line_scl : 16;  // offset: 0xc
                u32 line_int : 16;  // offset: 0xc
            };  // offset: 0x0
            struct
            {
            public:
                u32 pl_intensity : 16;  // offset: 0x0
                u32 pl_width : 16;  // offset: 0x0
                s16 pl_texcoord[2];  // offset: 0x4
                u32 pl_tangent_x : 8;  // offset: 0x8
                u32 pl_tangent_y : 8;  // offset: 0x8
                u32 pl_tangent_z : 8;  // offset: 0x8
                u32 pl_reserved : 8;  // offset: 0x8
                f32 pl_scale;  // offset: 0xc
            };  // offset: 0x0
        };  // offset: 0x10
    };
public:
    class PacketBuffer
    {
    public:
        PacketBuffer(u32 vb_size, u32 ib_size, u32 tvb_size, u32 tib_size);
        ~PacketBuffer();
        void* allocVertexBuffer(u32 size, u32* offset);
        u16* allocIndexBuffer(u32 size, u32* offset);
        nDraw::VertexBuffer* getVertexBuffer() const;
        nDraw::IndexBuffer* getIndexBuffer() const;
        void prepare();
        void swap();
        static void* operator new(size_t sz);
        static void* operator new[](size_t);
        static void operator delete(void* p_addr);
        static void operator delete[](void*);
        u32 getVBSize() const;
        u32 getIBSize() const;
        u32 getUsedVBSize() const;
        u32 getUsedIBSize() const;
        void* allocTempVertexBuffer(u32 size);
        u16* allocTempIndexBuffer(u32 size);
        u32 getTempVBSize() const;
        u32 getTempIBSize() const;
        u32 getUsedTempVBSize() const;
        u32 getUsedTempIBSize() const;
    private:
        u32 mCurrentIdx;  // offset: 0x0
        u32 mCurrentIIdx;  // offset: 0x4
        u32 mVBSize;  // offset: 0x8
        u32 mUsedVBSize;  // offset: 0xc
        u32 mVBOffset;  // offset: 0x10
        nDraw::VertexBuffer* mpVB[3];  // offset: 0x18
        bool mVBMapStatus[3];  // offset: 0x30
        void* mpCurrentVB;  // offset: 0x38
        u32 mIBSize;  // offset: 0x40
        u32 mUsedIBSize;  // offset: 0x44
        u32 mIBOffset;  // offset: 0x48
        nDraw::IndexBuffer* mpIB[3];  // offset: 0x50
        bool mIBMapStatus[3];  // offset: 0x68
        u16* mpCurrentIB;  // offset: 0x70
        void* mpTempVB;  // offset: 0x78
        void* mpCurrTempVB;  // offset: 0x80
        u32 mTempVBSize;  // offset: 0x88
        u32 mUsedTempVBSize;  // offset: 0x8c
        void* mpTempIB;  // offset: 0x90
        u16* mpCurrTempIB;  // offset: 0x98
        u32 mTempIBSize;  // offset: 0xa0
        u32 mUsedTempIBSize;  // offset: 0xa4
    };
public:
    class ContextInfParticle : public sGpuParticle::Context
    {
    public:
        enum PATH_TYPE
        {
            PATH_SPLINE = 0,
            PATH_BEZIER = 1,
        };
        enum COLOR_TYPE
        {
            VERTEX_COLOR = 0,
            CONSTANT_COLOR = 1,
            BLEND_CONSTANT_COLOR = 2,
            NODE_COLOR = 3,
            BLEND_NODE_COLOR = 4,
        };
        enum PATTERN_TYPE
        {
            PATTERN_CONSTANT = 0,
            PATTERN_PARTICLE = 1,
            PATTERN_ANIMATE = 2,
        };
    public:
        struct Particle;
        struct Vertex;
    public:
        struct Particle
        {
        public:
            Particle(const MtFloat3& ipos, const MtColor& icolor, s16 isize, u16 ibirth, u16 ilife, u16 itshift, u8 itex, u8 ipat_num, f32 irot, u16 iint);
        public:
            MtFloat3 pos;  // offset: 0x0
            MtColor color;  // offset: 0xc
            s16 size;  // offset: 0x10
            u16 birth;  // offset: 0x12
            u16 life;  // offset: 0x14
            u16 time_shift;  // offset: 0x16
            u8 tex_coord;  // offset: 0x18
            u8 pattern_num;  // offset: 0x19
            f32 rotation;  // offset: 0x1c
            u16 intensity;  // offset: 0x20
        };
    public:
        struct alignas(8) Vertex
        {
        public:
            s16 position[4];  // offset: 0x0
            u32 color;  // offset: 0x8
            s16 scale[2];  // offset: 0xc
            u16 life[2];  // offset: 0x10
            u32 tex_coord : 8;  // offset: 0x14
            u32 rotation : 8;  // offset: 0x14
            u32 reserved : 8;  // offset: 0x14
            u32 pat_num : 8;  // offset: 0x14
            u16 time_shift;  // offset: 0x18
            u16 intensity;  // offset: 0x1a
        };
    public:
        virtual s32 allocateParticle(cDraw* p_draw);  // vtable slot 1
        virtual s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle);  // vtable slot 2
        virtual s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 num, const nPrim::Material& material, s32 depth);  // vtable slot 3
        s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 start, u32 num, const nPrim::Material& material, s32 depth);
        s32 setParticle(const Particle& particle);
        s32 clearParticle();
        u32 getVertexNum() const;
        u32 getIndexNum() const;
        f32 getLoopLength() const;
        void setLoopLength(f32 length);
        void updateLoop(f32 tm);
        const MtFloat3 getPath(u32) const;
        void setPath(u32 idx, const MtFloat3& path);
        MtFloat3 getBoundingBox(u32) const;
        void setBoundingBox(u32 idx, const MtFloat3& bb);
        MtColorF getNodeColor(u32) const;
        void setNodeColor(u32 idx, const MtColorF& color);
        void reset(f32);
        virtual s32 setTexture(cDraw* p_draw, rTexture* p_tex, const MtPoint& base_pos, u32 size, u32 row_num, u32 total_num);  // vtable slot 0
        s32 setTexture(rTexture* p_tex, const MtFloat4& rect, u32 row_num, u32 col_num, u32 pattern_num);
        PATH_TYPE getPathType() const;
        void setPathType(PATH_TYPE type);
        COLOR_TYPE getColorType() const;
        void setColorType(COLOR_TYPE type);
        MtMatrix getWorldMatrix() const;
        void setWorldMatrix(const MtMatrix& wm);
        PATTERN_TYPE getPatternType() const;
        void setPatternType(PATTERN_TYPE type);
        const sGpuParticle::Context::LvCorrection& getLvCorrection() const;
        s32 setLvCorrection(const sGpuParticle::Context::LvCorrection&);
        u32 getPatternConst() const;
        void setPatternConst(u32);
        f32 getIntensityScale() const;
        void setIntensityScale(f32);
        const MtFloat4& getPatternRect() const;
        void setPatternRect(const MtFloat4&);
        bool isRandomizePosition() const;
        void enableRandomizePosition(bool);
    private:
        ContextInfParticle(u32 max_num);
        virtual ~ContextInfParticle();
        u16 convertToUShort(u16 val) const;
    private:
        sGpuParticle::StaticBuffer* mpBuffer;  // offset: 0x3b8
        u32 mVertexNum;  // offset: 0x3c0
        u32 mIndexNum;  // offset: 0x3c4
        u32 mCurrentVertexNum;  // offset: 0x3c8
        u32 mCurrentIndexNum;  // offset: 0x3cc
        u32 mCurrentIndex;  // offset: 0x3d0
        f32 mLoopLength;  // offset: 0x3d4
        f32 mCurrentLoop;  // offset: 0x3d8
        f32 mIntensityScale;  // offset: 0x3dc
        f32 mParticlePath[4][4];  // offset: 0x3e0
        f32 mBoundingBox[4][4];  // offset: 0x420
        f32 mNodeColor[4][4];  // offset: 0x460
        f32 mWorldMatrix[4][4];  // offset: 0x4a0
        bool mRandomizePos;  // offset: 0x4e0
        rTexture* mpTexture;  // offset: 0x4e8
        u32 mTextureRowNum;  // offset: 0x4f0
        u32 mTextureColNum;  // offset: 0x4f4
        u32 mTexturePaternNum;  // offset: 0x4f8
        PATH_TYPE mPathType;  // offset: 0x4fc
        COLOR_TYPE mColorType;  // offset: 0x500
        PATTERN_TYPE mPatternType;  // offset: 0x504
        u32 mPatternConst;  // offset: 0x508
        MtFloat4 mPatternRect;  // offset: 0x50c
        MtColor mConstantColor;  // offset: 0x51c
    };
public:
    class StaticBuffer
    {
    public:
        StaticBuffer(u32 vb_size, u32 ib_size);
        ~StaticBuffer();
        nDraw::VertexBuffer* getVertexBuffer() const;
        nDraw::IndexBuffer* getIndexBuffer() const;
        u32 getVertexBufferSize() const;
        u32 getIndexBufferSize() const;
        void* mapVertexBuffer();
        void* mapIndexBuffer();
        void updateVertexBuffer();
        void updateIndexBuffer();
        void update();
        static void* operator new(size_t sz);
        static void* operator new[](size_t);
        static void operator delete(void* p_addr);
        static void operator delete[](void*);
    private:
        nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0x0
        nDraw::IndexBuffer* mpIndexBuffer;  // offset: 0x8
        void* mpTempVertexBuffer;  // offset: 0x10
        u32 mTempVertexBufferSize;  // offset: 0x18
        void* mpTempIndexBuffer;  // offset: 0x20
        u32 mTempIndexBufferSize;  // offset: 0x28
    };
public:
    class ContextParticle : public sGpuParticle::Context
    {
    public:
        virtual s32 allocateParticle(cDraw* p_draw);  // vtable slot 1
        virtual s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle);  // vtable slot 2
        virtual s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 num, const nPrim::Material& material, s32 depth);  // vtable slot 3
    private:
        ContextParticle(u32 max_num);
        virtual ~ContextParticle();
        s32 allocateBuffer(sGpuParticle::Context::DrawCtx* p_ctx);
    };
public:
    class ContextPoint : public sGpuParticle::Context
    {
    public:
        virtual s32 setTexture(cDraw* p_draw, rTexture* p_tex, const MtPoint& base_pos, u32 size, u32 row_num, u32 total_num);  // vtable slot 0
        virtual s32 allocateParticle(cDraw* p_draw);  // vtable slot 1
        virtual s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle);  // vtable slot 2
        virtual s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 num, const nPrim::Material& material, s32 depth);  // vtable slot 3
    private:
        ContextPoint(u32 max_num);
        virtual ~ContextPoint();
    };
public:
    class ContextLine : public sGpuParticle::Context
    {
    public:
        virtual s32 setTexture(cDraw* p_draw, rTexture* p_tex, const MtPoint& base_pos, u32 size, u32 row_num, u32 total_num);  // vtable slot 0
        virtual s32 allocateParticle(cDraw* p_draw);  // vtable slot 1
        virtual s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle);  // vtable slot 2
        s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle0, const sGpuParticle::Particle& particle1);
        virtual s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 num, const nPrim::Material& material, s32 depth);  // vtable slot 3
    private:
        ContextLine(u32 max_num);
        virtual ~ContextLine();
    };
public:
    class ContextPolyline : public sGpuParticle::Context
    {
    public:
        struct PolylineCtx;
    public:
        struct PolylineCtx
        {
        public:
            u32 num_idx;  // offset: 0x0
            u32 max_idx;  // offset: 0x4
            u32 num_vtx;  // offset: 0x8
            u32 max_vtx;  // offset: 0xc
            u32 current_idx;  // offset: 0x10
            sGpuParticle::Context::DrawCtx* p_ctx;  // offset: 0x18
        };
    public:
        virtual s32 allocateParticle(cDraw* p_draw);  // vtable slot 1
        virtual s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle& particle);  // vtable slot 2
        s32 setParticle(cDraw* p_draw, const sGpuParticle::Particle* particle, u32 num, const nPrim::Rect& rect);
        s32 setParticle(cDraw*, const sGpuParticle::Particle*, u32);
        virtual s32 drawParticleArray(cDraw* p_draw, nDraw::PASS_TYPE pass, u32 num, const nPrim::Material& material, s32 depth);  // vtable slot 3
    private:
        ContextPolyline(u32 max_num);
        virtual ~ContextPolyline();
        s32 allocateBuffer(PolylineCtx* p_ctx);
        virtual void update(cDraw* p_draw);  // vtable slot 6
        virtual void update();  // vtable slot 7
        void reset(PolylineCtx* p_ctx, bool release_temp);
        void calcTexCoord(MtVector4* tc1, MtVector4* tc2, const nPrim::Rect& rect);
        PolylineCtx* getPolyLineCtx(cDraw* p_draw);
    private:
        PolylineCtx mPolyLineCtx[6];  // offset: 0x3b8
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
    static sGpuParticle* getInstance();
    static sGpuParticle* createInstance(u32 vb_size, u32 ib_size);
    static void deleteInstance();
    virtual void begin();  // vtable slot 10
    virtual void end();  // vtable slot 11
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    void resizeBuffer(u32, u32);
    void resizeBuffer(u32, u32, u32, u32);
    Context* createContextParticle(u32 max_num);
    Context* createContextPoint(u32 max_num);
    Context* createContextLine(u32 max_num);
    Context* createContextPolyline(u32 max_num);
    Context* createContextInfParticle(u32 max_num);
    void destroyContext(Context* p_context);
    cBlendState* getBlendState();
    void setDepthBlendDistance(f32 near_sz, f32 near_ez, f32 far_sz, f32 far_ez);
    MtVector4 getDepthBlend() const;
    f32 getAlphaClip() const;
    void setAlphaClip(f32);
    void setReductionDistance(u32);
    u32 getReductionDistance() const;
    bool isAutoReduction() const;
    void enableAutoReduction(bool);
    bool isDrawParticle() const;
    void enableDrawParticle(bool);
    u32 getUsedVBSize() const;
    u32 getUsedIBSize() const;
    u32 getUsedTempVBSize() const;
    u32 getUsedTempIBSize() const;
private:
    void initialize(u32 vb_size, u32 ib_size, u32 tvb_size, u32 tib_size);
    void* allocVertexBuffer(u32 size, u32* offset);
    u16* allocIndexBuffer(u32 size, u32* offset);
    void* allocTemporaryVertexBuffer(u32 size);
    u16* allocTemporaryIndexBuffer(u32 size);
    s32 allocBuffer(void* * p_vb, u32 vb_size, u32* vb_offset, u16* * p_ib, u32 ib_size, u32* ib_offset);
    s32 allocTempBuffer(void* * p_vb, u32 vb_size, u16* * p_ib, u32 ib_size);
    void addToContextChain(Context* p_ctx);
    sGpuParticle();
    sGpuParticle(u32 vb_size, u32 ib_size);
    virtual ~sGpuParticle();
private:
    f32 mNearStart;  // offset: 0x14
    f32 mNearEnd;  // offset: 0x18
    f32 mFarStart;  // offset: 0x1c
    f32 mFarEnd;  // offset: 0x20
    f32 mAlphaClip;  // offset: 0x24
    u32 mReductionDist;  // offset: 0x28
    bool mAutoReduction;  // offset: 0x2c
    Context* mpContextList;  // offset: 0x30
    Context* mpContextTail;  // offset: 0x38
    cBlendState mBlendState;  // offset: 0x40
    PacketBuffer* mpPacketBuffer;  // offset: 0xd0
    u32 mNewVBSize;  // offset: 0xd8
    u32 mNewIBSize;  // offset: 0xdc
    u32 mNewTempVBSize;  // offset: 0xe0
    u32 mNewTempIBSize;  // offset: 0xe4
    u32 mVBSize;  // offset: 0xe8
    u32 mIBSize;  // offset: 0xec
    u32 mTotalVBSize;  // offset: 0xf0
    u32 mTotalIBSize;  // offset: 0xf4
    u32 mUsedVBSize;  // offset: 0xf8
    u32 mUsedIBSize;  // offset: 0xfc
    u32 mTempVBSize;  // offset: 0x100
    u32 mTempIBSize;  // offset: 0x104
    u32 mUsedTempVBSize;  // offset: 0x108
    u32 mUsedTempIBSize;  // offset: 0x10c
    u32 mContextCount;  // offset: 0x110
    u32 mContextDrawNum;  // offset: 0x114
    bool mDrawParticle;  // offset: 0x118
public:
    static MyDTI DTI;
private:
    static sGpuParticle* mpInstance;
};
