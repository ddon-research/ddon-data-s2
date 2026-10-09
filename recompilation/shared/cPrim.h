#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cPrimObj.h"
#include "cPrimTagList.h"
#include "cPrimTexHandle.h"
#include "nDraw.h"
#include "nPrim.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtColorF;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cPrimBuffer;
class cPrimTagList;
class cPrimTexHandle;
namespace nDraw { class Texture; }
namespace nPrim { struct DepthOrder; }
namespace nPrim { struct FRect; }
namespace nPrim { struct Material; }
namespace nPrim { struct MetaDataHeader; }
namespace nPrim { struct Rect; }
namespace nPrim { struct Texture; }
namespace nPrim { struct Vertex; }
namespace nPrim { struct VertexFormat; }
class rModel;
class rTexture;

// Declarations
class cPrim;

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

class cPrim : public cPrimObj
{
public:
    enum SpriteStatus
    {
        NONE = 0,
        BEGIN_SPRITE = 1,
        DRAW_SPRITE = 2,
        END_SPRITE = 3,
        SPRITE_ERR = 2147483647,
    };
    enum SpriteAttr
    {
        WRITE_NO_COLOR = 0,
        WRITE_RGBA = 1,
        WRITE_RGB = 2,
    };
public:
    class MyDTI;
    struct ObjState;
    struct Sprite;
    struct SmoothEdge;
    struct UVOffset;
    struct PrimCamera;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ObjState
    {
    public:
        bool use_vscr;  // offset: 0x0
        rModel* p_model;  // offset: 0x8
        cDraw* p_draw;  // offset: 0x10
    };
public:
    struct Sprite
    {
    public:
        Sprite();
    public:
        cPrim::SpriteStatus stat;  // offset: 0x0
        nPrim::DepthOrder z_order;  // offset: 0x4
        bool tex_changed;  // offset: 0x8
        nDraw::Texture* last_tex;  // offset: 0x10
        u32 last_attr;  // offset: 0x18
        nPrim::Material last_mat;  // offset: 0x20
        bool use_vscr;  // offset: 0x28
    };
public:
    struct SmoothEdge
    {
    public:
        enum Type
        {
            NONE = 0,
            DEFAULT = 1,
            INVERSE = 2,
            VERTEX_NORMAL = 3,
            VERTEX_NORMAL_INVERSE = 4,
        };
    public:
        SmoothEdge();
        SmoothEdge(u32 i_type, f32 i_min, f32 i_max);
    public:
        u32 type;  // offset: 0x0
        f32 min_v;  // offset: 0x4
        f32 max_v;  // offset: 0x8
    };
public:
    struct UVOffset
    {
    public:
        UVOffset();
        ~UVOffset();
        void addOffset(const MtFloat2& uv);
    public:
        MtFloat2 offset[4];  // offset: 0x0
        u32 offset_num;  // offset: 0x20
    };
public:
    struct PrimCamera
    {
    public:
        PrimCamera();
        PrimCamera(const MtVector3&, const MtVector3&, const MtVector3&, f32, f32, f32);
        cPrim::PrimCamera& operator=(const cPrim::PrimCamera&);
    public:
        MtVector3 pos;  // offset: 0x0
        MtVector3 up;  // offset: 0x10
        MtVector3 target;  // offset: 0x20
        f32 near_v;  // offset: 0x30
        f32 far_v;  // offset: 0x34
        f32 fov;  // offset: 0x38
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
    cPrim();
    virtual ~cPrim();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    s32 push(bool use_vscr);
    s32 pop();
    cPrimTagList* getPrimTagList() const;
    void setTagMemory(u32 n_tags, cPrimTagList::PrimTag* p_tag, cPrimTagList::IndexTag* p_itag);
    cPrimBuffer* getPrimBuffer() const;
    cDraw* getCDraw() const;
    void setCDraw(cDraw* p_draw);
    const MtVector4& getViewVector() const;
    void setViewVector(const MtVector4& vv);
    const MtMatrix& getViewMatrix() const;
    void setViewMatrix(const MtMatrix& mm);
    u32 getDispLevel() const;
    void setDispLevel(u32 dl);
    u32 getSubPriority() const;
    void setSubPriority(u32 sp);
    rModel* getModel() const;
    void setModel(rModel* mp);
    u32 getModelMat() const;
    void setModelMat(u32);
    s32 calcDepthOrder(const MtVector3& pos) const;
    s32 calcDepthOrder2D(f32 depth) const;
    u32 setTexture(rTexture* p_bm, rTexture* p_nm, rTexture* p_mm, rTexture* p_am);
    u32 setTexture(nDraw::Texture* p_tb, rTexture* p_nm, rTexture* p_mm, rTexture* p_am);
    nPrim::Texture* getCurrentTexture() const;
    u32 getCurrentTexHandle() const;
    void clear();
    void sortTags(uintptr param);
    bool isUseVScr() const;
    s32 drawLineF(const MtVector3&, const MtVector3&, const MtColor&, const nPrim::Material&, s32, s32, u32);
    s32 drawLineG(const MtVector3&, const MtVector3&, const MtColor&, const MtColor&, const nPrim::Material&, s32, s32, u32);
    s32 drawLineFT(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32, s32, u32);
    s32 drawLineGT(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32, s32, u32);
    s32 drawLineStripF(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 drawLineStripG(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 drawLineStripFT(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 drawLineStripGT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 drawPolyF3(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32, s32, u32);
    s32 drawPolyF4(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32, s32, u32);
    s32 drawPolyG3(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 drawPolyG4(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Vertex& p4, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 drawPolyFT3(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawPolyFT4(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Vertex& p4, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawPolyGT3(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawPolyGT4(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Vertex& p4, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawPolyStripF(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 drawPolyStripG(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 drawPolyStripFT(const nPrim::Vertex* p_array, const u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawPolyStripGT(const nPrim::Vertex* p_array, const u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, bool norm_tg);
    s32 drawParticle(const MtVector3& pos, u32 volume, const nPrim::Rect& rect, const MtColor& color, u32 hdr_intensity, f32 scale, f32 aspect_ratio, const nPrim::Material& material, u32 rot, s32 zofs, s32 depth);
    s32 drawParticleEx(const MtVector3& pos, const MtPoint& center_pos, u32 volume, const nPrim::Rect& rect, const MtColor& color, u32 hdr_intensity, f32 scale, f32 aspect_ratio, const nPrim::Material& material, u32 rot, s32 zofs, s32 depth);
    s32 drawParticleNT(const MtVector3& pos, u32 volume, const nPrim::Rect& rect, const MtFloat2& size, const MtColor& color, u32 hdr_intensity, const nPrim::Material& material, u32 rot, s32 zofs, s32 depth);
    s32 drawParticleExNT(const MtVector3& pos, const MtFloat2& center_pos, u32 volume, const nPrim::Rect& rect, const MtFloat2& size, const MtColor& color, u32 hdr_intensity, const nPrim::Material& material, u32 rot, s32 zofs, s32 depth);
    s32 drawPolyLineF(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 draw2DPolyLineF(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32);
    s32 drawPolyLineG(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 draw2DPolyLineG(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32);
    s32 drawPolyLineFT(const nPrim::Vertex*, u32, const nPrim::Rect&, const nPrim::Material&, s32, s32, u32);
    s32 draw2DPolyLineFT(const nPrim::Vertex*, u32, const nPrim::Rect&, const nPrim::Material&, s32, s32);
    s32 drawPolyLineGT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Rect& rect, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume);
    s32 draw2DPolyLineGT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Rect& rect, const nPrim::Material& material, s32 zofs, s32 depth);
    s32 drawPolyLineFT(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32, u32);
    s32 draw2DPolyLineFT(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32);
    s32 drawPolyLineGT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 zofs, s32 depth, u32 volume, f32 texofs);
    s32 draw2DPolyLineGT(const nPrim::Vertex*, u32, const nPrim::Material&, s32, s32);
    s32 draw2DLineF(const MtVector3&, const MtVector3&, const MtColor&, const nPrim::Material&, s32);
    s32 draw2DLineG(const MtVector3&, const MtVector3&, const MtColor&, const MtColor&, const nPrim::Material&, s32);
    s32 draw2DPolyF3(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyF4(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DSprite(f32, f32, f32, const nPrim::Rect&, const MtColor&, const nPrim::Material&, s32, u32);
    s32 draw2DStretchSprite(const nPrim::FRect&, f32, const nPrim::Rect&, const MtColor&, const nPrim::Material&, s32, u32);
    s32 draw2DSpriteEx(f32 x, f32 y, f32 z, const MtPoint& center_pos, const nPrim::Rect& rect, const MtColor& color, f32 scale, const nPrim::Material& material, u32 rot, s32 depth, u32 hdr_intensity);
    s32 drawLensFlare(f32 x, f32 y, f32 z, const MtPoint& center_pos, const nPrim::Rect& rect, const MtColor& color, f32 scale, const nPrim::Material& material, u32 rot, s32 depth, u32 hdr_intensity, u32 occ);
    s32 draw2DStretchSpriteEx(const nPrim::FRect& dest, f32 z, const MtPoint& center_pos, const nPrim::Rect& rect, const MtColor& color, const nPrim::Material& material, u32 rot, s32 depth, u32 hdr_intensity);
    s32 draw2DFillRect(f32, f32, f32, f32, f32, const MtColor&, const nPrim::Material&, s32, u32);
    s32 draw2DLineFT(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DLineGT(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DLineStripF(const nPrim::Vertex*, u32, const nPrim::Material&, s32);
    s32 draw2DLineStripG(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 depth);
    s32 draw2DLineStripFT(const nPrim::Vertex*, u32, const nPrim::Material&, s32);
    s32 draw2DLineStripGT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 depth);
    s32 draw2DPolyG3(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyG4(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyFT3(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyFT4(const nPrim::Vertex& p1, const nPrim::Vertex& p2, const nPrim::Vertex& p3, const nPrim::Vertex& p4, const nPrim::Material& material, s32 depth);
    s32 draw2DPolyGT3(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyGT4(const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Vertex&, const nPrim::Material&, s32);
    s32 draw2DPolyStripF(const nPrim::Vertex*, u32, const nPrim::Material&, s32);
    s32 draw2DPolyStripFT(const nPrim::Vertex* p_array, u32 vnum, const nPrim::Material& material, s32 depth);
    s32 draw2DPolyStripG(const nPrim::Vertex*, u32, const nPrim::Material&, s32);
    s32 draw2DPolyStripGT(const nPrim::Vertex*, u32, const nPrim::Material&, s32);
    s32 setLight(const MtVector3& wpos, u32 group);
    s32 setOcclusion(const MtVector3& wpos, f32 radius);
    s32 setLensFlare(const MtVector3& wpos, f32 radius, f32 scl_limit, f32 radial_dist, f32 min_int, f32 max_int);
    s32 setFresnel(f32 factor, f32 bias, f32 refl_coef);
    s32 setUVClamp(const MtVector4& range);
    s32 setShadeLight(const MtVector3& lt_pos, f32 range, f32 att, const MtColorF& shd_color, u32 type);
    s32 setCloudAttr(const MtVector3& sun_dir, const MtFloat2& h_range, const MtColor& h_color0, const MtColor& h_color1, const MtColorF& dir_cmin, const MtColorF& dir_cmed, const MtColorF& dir_cmax);
    s32 setLvCorrection(f32 lv_min, f32 lv_max, s32 atten, MtFloat3 col_const);
    s32 setModel(cDraw* p_draw, rModel* p_model, const MtSphere& boundary, u32 light_group, u32 shadow_group, s32 priority_bias, const SmoothEdge& smooth_edge);
    s32 drawModel(cDraw* p_draw, u32 primitive_no, const MtMatrix& matrix, const MtColor& color, u32 intensity, const nPrim::Material& material, u32 volume, f32 envmap_power, const UVOffset& uvoffset, u32 shadow_group);
    s32 draw2DModelImmediate(cDraw* p_draw, const MtRect& rect, u32 primitive_no, const MtMatrix& matrix, const MtColor& color, u32 intensity, const nPrim::Material& material, u32 volume, f32 envmap_power, const UVOffset& uvoffset, const PrimCamera& cam, bool clear_z, u32 depth);
    s32 begin2DModel(cDraw* p_draw, rModel* p_model, const MtSphere& boundary, const u32 light_group, const PrimCamera& cam, u32 depth);
    s32 end2DModel(cDraw* p_draw);
    s32 draw2DModel(cDraw* p_draw, const MtRect& rect, u32 primitive_no, const MtMatrix& matrix, const MtColor& color, u32 intensity, const nPrim::Material& material, u32 volume, f32 envmap_power, const UVOffset& uvoffset, bool clear_z);
    s32 beginSprite(u32 priority, bool use_vscr);
    s32 endSprite();
    s32 clear(bool rt_color, const MtColor& clear_color, bool rt_depth, f32 clear_depth);
    s32 clearC(const MtColor&);
    s32 clearZ(f32);
    s32 setSpritePriority(u32 priority);
    s32 setSpriteTex(rTexture* p_bm);
    s32 setSpriteTexHandle(nDraw::Texture* p_tex);
    s32 drawSprite(const nPrim::Vertex& pos0, const nPrim::Vertex& pos1, const nPrim::Material& mat, u32 attr);
    s32 drawSpriteMask(const nPrim::Vertex&, const nPrim::Vertex&, u8, const nPrim::Material&);
    s32 drawSprite3F(const nPrim::Vertex& pos0, const nPrim::Vertex& pos1, const nPrim::Vertex& pos2, const nPrim::Material& mat, u32 attr);
    s32 drawSprite3G(const nPrim::Vertex& pos0, const nPrim::Vertex& pos1, const nPrim::Vertex& pos2, const nPrim::Material& mat, u32 attr);
    s32 drawSprite4F(const nPrim::Vertex& pos0, const nPrim::Vertex& pos1, const nPrim::Vertex& pos2, const nPrim::Vertex& pos3, const nPrim::Material& mat, u32 attr);
    s32 drawSprite4G(const nPrim::Vertex& pos0, const nPrim::Vertex& pos1, const nPrim::Vertex& pos2, const nPrim::Vertex& pos3, const nPrim::Material& mat, u32 attr);
    s32 setAlphaTest(bool enable, nDraw::COMPARISON_FUNC cmpfunc, u8 ref, bool rop_test);
    s32 drawCloudBillboard(const MtVector3& gen_pos, const MtVector3& local_pos, f32 size, f32 asp, f32 alpha, const nPrim::Rect& rect, const nPrim::Material& material, s32 depth);
    s32 drawCloudParticle(const MtVector3& gen_pos, const MtVector3& pos0, const MtVector3& pos1, const MtVector3& pos2, const MtVector3& pos3, f32 alpha, const nPrim::Rect& rect, const nPrim::Material& material, s32 depth);
private:
    void* getMetaData(const nPrim::Material& mat);
    s32 writeToBuffer(void* p_vb, u32 vb_size, const nPrim::Material& material, u32 prim_type, s32 order, u32 vtx_cnt, u32 idx_cnt);
    s32 writeToBuffer(void*, u32, const nPrim::Material&, u32, nPrim::DepthOrder, u32, u32);
    void initPrim();
    void setModelCmn(cDraw* p_draw, rModel* p_model, const MtSphere& boundary, const u32 light_group);
    void setModelShadowCast(cDraw* p_draw, rModel* p_model, u32 shadow_group);
    void drawModelCmn(cDraw* p_draw, u32 primitive_no, const MtMatrix& matrix, const MtColor& color, u32 intensity, const nPrim::Material& material, u32 volume, f32 envmap_power, const UVOffset& uvoffset);
    void drawModelShadowCast(cDraw* p_draw, u32 primitive_no, const MtMatrix& matrix, u32 shadow_group);
    s32 draw2DModelCmn(cDraw* p_draw, u32 primitive_no, const MtMatrix& matrix, const MtColor& color, u32 intensity, const nPrim::Material& material, u32 volume, f32 envmap_power, const UVOffset& uvoffset, u32 depth, bool clear_z);
    void applyTexCoordAttr(nPrim::VertexFormat* vv, const nPrim::Material& mat, const nPrim::Rect& rect) const;
    void applyTexCoordAttr(MtVector4* tc1, MtVector4* tc2, const nPrim::Material& mat, const nPrim::Rect& rect) const;
    u32 convertToUShort(f32 fv) const;
    u32 convertToChar(f32 fv) const;
    u32 convertToRotation(u32 rot) const;
    u32 convertToNtSpr(s32 iv) const;
    u32 convertToPolyLineW(f32 fv) const;
    u32 convertToPolyLineTangent(f32 fv) const;
    u32 convertToVolumeBlend(u32 vol) const;
    u32 convertToVolumeBlendNT(u32 vol) const;
    u32 convertToNormFloat(f32 fv) const;
    u32 convertToColor(u32 color) const;
    u32 convertToZOffset(s32 zofs) const;
    u32 convertToSprSize(s32 sz) const;
    u32 convertToSprRatio(f32 ratio) const;
    void applyNormPolylineTexCoord(nPrim::VertexFormat* vtx, const nPrim::Material& mat, const nPrim::Vertex* i_vtx, u32 num, f32 texofs) const;
    void setupLightMask(cDraw* p_draw);
    void mergeTag(cPrimTagList::IndexTag* in_data, cPrimTagList::IndexTag* temp, s32 lt, s32 md, s32 rt);
    ObjState* getCurrentState();
    void changeSpriteState(cDraw* p_draw, const nPrim::Material& mat, u32 attr);
    void changeSpriteBlendState(cDraw* p_draw, const nPrim::Material& mat, u32 attr);
    void changeSpriteDrawState(cDraw* p_draw, const nPrim::Material& mat);
    void changeSpriteSamplerState(cDraw* p_draw, const nPrim::Material& mat);
    bool clipParticle(const MtVector3& z_pos);
private:
    cPrimTagList* mpPrimTagList;  // offset: 0x8
    cPrimBuffer* mpPrimBuffer;  // offset: 0x10
    ObjState mStack[6];  // offset: 0x18
    u32 mCurrentStack;  // offset: 0xa8
    MtVector4 mViewVec;  // offset: 0xb0
    rModel* mpModel;  // offset: 0xc0
    nPrim::Texture mTexture;  // offset: 0xc8
    u32 mDispLevel;  // offset: 0xf0
    u32 mSubPriority;  // offset: 0xf4
    u32 mModelMaterial;  // offset: 0xf8
    u32 mCurrentTexHandle;  // offset: 0xfc
    u32 m2DModelDepth;  // offset: 0x100
    s32 mModelPriorityBias;  // offset: 0x104
    nPrim::MetaDataHeader mMetaData;  // offset: 0x108
    void* mpMetaData;  // offset: 0x148
    bool mMetaDataChanged;  // offset: 0x150
    MtMatrix mViewMatrix;  // offset: 0x160
    MtMatrix mSave2DView;  // offset: 0x1a0
    MtMatrix mSave2DProj;  // offset: 0x1e0
    MtRect mSave2DViewport;  // offset: 0x220
    MtMatrix mCurrent2DView;  // offset: 0x230
    MtMatrix mCurrent2DProj;  // offset: 0x270
    Sprite mSprite;  // offset: 0x2b0
    cPrimTexHandle mTexHandle;  // offset: 0x2e0
    SmoothEdge mSmoothEdge;  // offset: 0x300
public:
    static MyDTI DTI;
};
