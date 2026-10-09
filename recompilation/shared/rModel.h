#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cResource.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtStream;
class MtUI;
class MtVector3;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Material; }
namespace nDraw { class VertexBuffer; }
class rMaterial;
class rTexture;
class uSimSoftBody;

// Declarations
class rModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class rModel : public cResource
{
    // inferred: uSimSoftBody::getTargetVertexBuffer names rModel::mpVertexBuffer
    friend class uSimSoftBody;
public:
    class MyDTI;
    struct JOINT_INFO;
    struct PRIMITIVE_INFO;
    struct BOUNDARY_INFO;
    struct PARTS_INFO;
    struct MODEL_INFO;
    struct MATERIAL_NAME;
    struct RECALCNORMAL_INFO;
    struct MODEL_HDR;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct JOINT_INFO
    {
    public:
        u32 no : 8;  // offset: 0x0
        u32 parent : 8;  // offset: 0x0
        u32 symmetry : 8;  // offset: 0x0
        u32 reserved : 8;  // offset: 0x0
        f32 radius;  // offset: 0x4
        f32 length;  // offset: 0x8
        MtFloat3 offset;  // offset: 0xc
    };
public:
    struct PRIMITIVE_INFO
    {
    public:
        enum LOD
        {
            LOD_HIGH = 1,
            LOD_MID = 2,
            LOD_LOW = 4,
        };
    public:
        u32 draw_mode : 16;  // offset: 0x0
        u32 vertex_num : 16;  // offset: 0x0
        u32 parts_no : 12;  // offset: 0x4
        u32 material_no : 12;  // offset: 0x4
        u32 lod : 8;  // offset: 0x4
        u32 disp : 1;  // offset: 0x8
        u32 shape : 1;  // offset: 0x8
        u32 sort : 1;  // offset: 0x8
        u32 weight_num : 5;  // offset: 0x8
        u32 alphapri : 8;  // offset: 0x8
        u32 vertex_stride : 8;  // offset: 0x8
        u32 topology : 6;  // offset: 0x8
        u32 binormal_flip : 1;  // offset: 0x8
        u32 bridge : 1;  // offset: 0x8
        u32 vertex_ofs;  // offset: 0xc
        u32 vertex_base;  // offset: 0x10
        SO_HANDLE inputlayout;  // offset: 0x14
        u32 index_ofs;  // offset: 0x18
        u32 index_num;  // offset: 0x1c
        u32 index_base;  // offset: 0x20
        u32 envelope : 8;  // offset: 0x24
        u32 boundary_num : 8;  // offset: 0x24
        u32 connect_id : 16;  // offset: 0x24
        u32 min_index : 16;  // offset: 0x28
        u32 max_index : 16;  // offset: 0x28
        rModel::BOUNDARY_INFO* boundary;  // offset: 0x30
    };
public:
    struct BOUNDARY_INFO
    {
    public:
        u32 joint;  // offset: 0x0
        u32 reserved[3];  // offset: 0x4
        MtSphere sphere;  // offset: 0x10
        MtAABB aabb;  // offset: 0x20
        MtOBB obb;  // offset: 0x40
    };
public:
    struct PARTS_INFO
    {
    public:
        u32 no;  // offset: 0x0
        u32 reserved[3];  // offset: 0x4
        MtSphere boundary;  // offset: 0x10
    };
public:
    struct MODEL_INFO
    {
    public:
        s32 middist;  // offset: 0x0
        s32 lowdist;  // offset: 0x4
        u32 light_group;  // offset: 0x8
        u16 memory;  // offset: 0xc
        u16 reserved;  // offset: 0xe
    };
public:
    struct MATERIAL_NAME
    {
    public:
        MT_CHAR name[128];  // offset: 0x0
    };
public:
    struct RECALCNORMAL_INFO
    {
    public:
        u16 width;  // offset: 0x0
        u16 height;  // offset: 0x2
        u32* map_vertex_base;  // offset: 0x8
        u32 triangle_num;  // offset: 0x10
        nDraw::VertexBuffer* triangle;  // offset: 0x18
        nDraw::VertexBuffer* vertex_to_index;  // offset: 0x20
    };
public:
    struct MODEL_HDR
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 jnt_num;  // offset: 0x6
        u16 primitive_num;  // offset: 0x8
        u16 material_num;  // offset: 0xa
        u32 vertex_num;  // offset: 0xc
        u32 index_num;  // offset: 0x10
        u32 polygon_num;  // offset: 0x14
        u32 vertexbuf_size;  // offset: 0x18
        u32 texture_num;  // offset: 0x1c
        u32 parts_num;  // offset: 0x20
        u32 padding1;  // offset: 0x24
        size_t joint_info;  // offset: 0x28
        size_t parts_info;  // offset: 0x30
        size_t material_info;  // offset: 0x38
        size_t primitive_info;  // offset: 0x40
        size_t vertex_data;  // offset: 0x48
        size_t index_data;  // offset: 0x50
        size_t rcn_data;  // offset: 0x58
        MtSphere bounding_sphere;  // offset: 0x60
        MtAABB bounding_box;  // offset: 0x70
        rModel::MODEL_INFO modelinfo;  // offset: 0x90
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
    rModel();
    virtual bool loadEnd();  // vtable slot 10
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    MODEL_INFO* getModelInfo();
    f32 getQuantPosScale() const;
    const MtVector3& getQuantPosOffset() const;
    const JOINT_INFO* getJointInfo() const;
    u32 getJointNum() const;
    const MtMatrix* getJointLocalMatrix() const;
    const MtMatrix* getJointInverseMatrix() const;
    const u8* getJointTable();
    const MtSphere& getBoundingSphere();
    const MtAABB& getBoundingBox();
    nDraw::VertexBuffer* getVertexBuffer() const;
    nDraw::IndexBuffer* getIndexBuffer() const;
    u32 getMaterialNum() const;
    virtual const nDraw::Material* getMaterial(u32 index) const;  // vtable slot 16
    MT_CTSTR getMaterialName(u32 index);
    virtual rMaterial* getMaterialResource();  // vtable slot 17
    u32 getPrimitiveNum() const;
    const PRIMITIVE_INFO* getPrimitives() const;
    u32 getPrimitiveIndexFromParts(u32 parts_no);
    u32 getPartsNum();
    const PARTS_INFO* getParts() const;
    bool getRCNEnable();
    const RECALCNORMAL_INFO& getRCNInfo() const;
    u32 getRCNWidth();
    u32 getRCNHeight();
protected:
    virtual ~rModel();
    static rTexture* createTexture(MT_CTSTR path);
    void initMaterial();
private:
    void* memAlloc(u32 sz);
    void memFree(void* p_addr);
public:
    bool isSeparateStride(const u32 bstride, const u32 stride) const;
protected:
    JOINT_INFO* mJointInfo;  // offset: 0x70
    u32 mJointNum;  // offset: 0x78
    MtMatrix* mLmat;  // offset: 0x80
    MtMatrix* mImat;  // offset: 0x88
    PRIMITIVE_INFO* mPrimitiveInfo;  // offset: 0x90
    u32 mPrimitiveNum;  // offset: 0x98
    BOUNDARY_INFO* mBoundaryInfo;  // offset: 0xa0
    u32 mEnvelopeNum;  // offset: 0xa8
    u32 mMaterialNum;  // offset: 0xac
    u32 mPolygonNum;  // offset: 0xb0
    u32 mVertexNum;  // offset: 0xb4
    u32 mIndexNum;  // offset: 0xb8
    u32 mPartsNum;  // offset: 0xbc
    PARTS_INFO* mPartsInfo;  // offset: 0xc0
    u32 mVertexBufsize;  // offset: 0xc8
    nDraw::IndexBuffer* mpIndexBuffer;  // offset: 0xd0
    nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0xd8
    f32 mQuantPosScale;  // offset: 0xe0
    MtSphere mBoundingSphere;  // offset: 0xf0
    MtAABB mBoundingBox;  // offset: 0x100
    MODEL_INFO mModelInfo;  // offset: 0x120
    nDraw::Material* mpMaterialsStack[4];  // offset: 0x130
    MtVector3 mQuantPosOffset;  // offset: 0x150
    u8 mJointTable[256];  // offset: 0x160
    rMaterial* mpMaterial;  // offset: 0x260
    nDraw::Material* * mpMaterials;  // offset: 0x268
    MATERIAL_NAME* mMaterialName;  // offset: 0x270
    RECALCNORMAL_INFO mRCNInfo;  // offset: 0x278
public:
    static const u32 MAX_PARTS = 512;
    static const u32 RMODEL_MATERIALPTR_STACK_NUM = 4;
    static MyDTI DTI;
protected:
    static const s32 BASE_VERSION = 209;
    static const s32 DATA_VERSION = 210;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline const rModel::JOINT_INFO* rModel::getJointInfo() const {
    return this->mJointInfo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rModel::getJointNum() const {
    return this->mJointNum;
}
