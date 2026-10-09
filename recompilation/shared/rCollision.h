#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "MtPrimitive3D.h"
#include "cResource.h"
#include "nCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColorF;
class MtDTI;
class MtDataReader;
struct MtFloat3;
class MtGeometry;
class MtMatrix;
class MtObject;
class MtQuaternion;
class MtRange;
class MtStream;
class MtTriangle;
class MtVector3;
class MtVector4;
class cBVHCollision;
class cGridCollision;
class cGridCollisionRegistInfo;
namespace nCollision { struct ScrMaterialInfo; }
namespace nCollisionUtil { struct LoadBuffer; }

// Declarations
class rCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using u32 = unsigned int;
using uintptr = __uintptr_t;
namespace nCollision { using TRAVERSE_CALLBACK = u32(MtObject::*)(uintptr, u32, uintptr); }
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class rCollision : public cResource
{
public:
    enum ADJACENT_TYPE
    {
        ADJACENT_TYPE_NONE = 0,
        ADJACENT_TYPE_ENABLE_FLAT = 1,
        ADJACENT_TYPE_ENABLE_CONVEX = 2,
        ADJACENT_TYPE_ENABLE_CONCAVE = 4,
    };
public:
    class MyDTI;
    struct Header;
    struct PartsInfo;
    struct MaterialInfo;
    class Leaf;
    struct Triangle;
    struct Vertex;
    struct CopyWorkData;
    struct MaterialList;
public:
    using COPY_FUNC = void(MtObject::*)(rCollision&, u32, const MtMatrix&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Header
    {
    public:
        void getBoundingAABB(MtAABB&);
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        u8 Id[4];  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 SpaceDivisionTypeParts;  // offset: 0x8
        u32 SpaceDivisionTypeTriangle;  // offset: 0xc
        u16 PartsInfoNum;  // offset: 0x10
        u16 MaterialInfoNum;  // offset: 0x12
        u32 TotalLeafNum;  // offset: 0x14
        u32 TotalTriangleNum;  // offset: 0x18
        u32 TotalVertexNum;  // offset: 0x1c
        u32 TotalModifyNum;  // offset: 0x20
        u32 _padding[3];  // offset: 0x24
        MtAABB TotalAABB;  // offset: 0x30
    };
public:
    struct PartsInfo
    {
    public:
        void getBoundingAABB(MtAABB& out) const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        MtAABB bv;  // offset: 0x0
        cBVHCollision* pBvh;  // offset: 0x20
        cGridCollision* pGrid;  // offset: 0x28
        cGridCollisionRegistInfo* pGridRegistInfo;  // offset: 0x30
        u32 LeafIndex;  // offset: 0x38
        u16 LeafNum;  // offset: 0x3c
        u32 TriangleIndex;  // offset: 0x40
        u16 TriangleNum;  // offset: 0x44
        u32 VertexIndex;  // offset: 0x48
        u16 VertexNum;  // offset: 0x4c
        u32 Id;  // offset: 0x50
    };
public:
    struct MaterialInfo : public nCollision::ScrMaterialInfo
    {
    public:
        rCollision::MaterialInfo& operator=(const nCollision::ScrMaterialInfo&);
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    };
public:
    class Leaf
    {
    public:
        bool isPairPolygonLeaf() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        u16 TriangleIndex[2];  // offset: 0x0
        u8 CommonUseVertexIndex[2];  // offset: 0x4
        u8 NoCommonVertexIndex[2];  // offset: 0x6
        u16 MaterialIndex;  // offset: 0x8
    };
public:
    struct Triangle
    {
    public:
        const MtVector3& getNormalByVector3() const;
        const MtVector4& getNormalByVector4() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        MtFloat3 normal;  // offset: 0x0
        u16 vert_index[3];  // offset: 0xc
        u16 material_index;  // offset: 0x12
        u32 attribute[1];  // offset: 0x14
        u8 adjustParam[3];  // offset: 0x18
        u8 reserved;  // offset: 0x1b
        u32 PhysicsReserved;  // offset: 0x1c
    };
public:
    struct Vertex
    {
    public:
        const MtVector3& castToVector3() const;
        const MtVector4& castToVector4() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
        u32 attribute;  // offset: 0xc
    };
public:
    struct CopyWorkData
    {
    public:
        rCollision* pSource;  // offset: 0x0
        const MtMatrix* pMatrix;  // offset: 0x8
        MtRange TargetRange;  // offset: 0x10
        rCollision::COPY_FUNC pCopyFunc;  // offset: 0x18
    };
public:
    struct MaterialList
    {
    public:
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        char name[8];  // offset: 0x0
        MtColorF color;  // offset: 0x10
        u32 attribute;  // offset: 0x20
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
    rCollision();
    virtual ~rCollision();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void clear();  // vtable slot 15
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rCollision* makeCopyTrans(MT_CTSTR ResourcePath, const MtVector3& trans, bool FlgMultiThread);
    rCollision* makeCopyRotTrans(MT_CTSTR ResourcePath, const MtQuaternion& qt, const MtVector3& trans, bool FlgMultiThread);
    rCollision* makeCopyScaleRotTrans(MT_CTSTR ResourcePath, const MtVector3& scale, const MtQuaternion& qt, const MtVector3& trans, bool FlgMultiThread);
    u32 getSpaceDivisionTypeParts() const;
    u32 getSpaceDivisionTypeTriangle() const;
    u32 getPartsInfoSize() const;
    u32 getMaterialInfoSize() const;
    u32 getTriangleSize() const;
    u32 getVertexSize() const;
    u32 getLeafSize() const;
    u8 getRSbcMagicID() const;
    u32 getPartsLeafNum(u32) const;
    u32 getPartsLeafNum(PartsInfo&) const;
    u32 getPartsTriangleNum(u32 PartsIndex) const;
    u32 getPartsTriangleNum(PartsInfo& info) const;
    u32 getPartsVertexNum(u32) const;
    u32 getPartsVertexNum(PartsInfo&) const;
    u32 getPartsInfoFromTriangleIndexFromRoot(u32 TriangleIndexFromRoot) const;
    u32 getTriangleIndex(u32, u32) const;
    u32 getTriangleIndex(const PartsInfo*, u32) const;
    void getTriangle(MtTriangle& TriangleOut, u32 PartsIndex, u32 TriangleIndex) const;
    void getTriangle(MtTriangle&, u32, const Triangle&) const;
    void getTriangle(MtTriangle&, const PartsInfo&, u32) const;
    void getTriangle(MtTriangle& TriangleOut, const PartsInfo& RMeshInfo, const Triangle& RTriangle) const;
    void getTriangle(MtTriangle& TriangleOut, u32 TriangleIndexFromRoot) const;
    const MtVector3& getTriangleNormal(u32 PartsIndex, u32 TriangleIndex) const;
    const MtVector3& getTriangleNormal(const Triangle& tri) const;
    const MtVector3& getTriangleNormal(u32 TriangleIndexFromRoot) const;
    void getBoundingAABB(MtAABB&) const;
    const MtAABB& getBoundingAABBDirect() const;
    void getPartsAABB(MtAABB&, u32) const;
    const MtAABB& getPartsAABBDirect(u32) const;
    const MaterialInfo* getMaterialInfoPtr(u32) const;
    const MaterialInfo* getTriangleMaterialInfoPtr(const Triangle& RTri) const;
    const MaterialInfo* getTriangleMaterialInfoPtr(u32 PartsIndex, u32 TriangleIndex) const;
    const MaterialInfo* getTriangleMaterialInfoPtr(u32 TriangleIndexFromRoot) const;
    cBVHCollision* getBvh();
    const Header* getHeaderPtrConst() const;
    const PartsInfo* getPartsInfoPtrConst() const;
    const MaterialInfo* getMaterialInfoPtrConst() const;
    const Triangle* getTrianglePtrConst() const;
    const Vertex* getVertexPtrConst() const;
    const Vertex& getVertexConst(u32, u32) const;
    const PartsInfo* getPartsInfoPtrConst(u32 PartsIndex) const;
    const Leaf* getRootLeafPtrConst(u32 PartsIndex) const;
    const Leaf* getLeafPtrConst(u32 PartsIndex, u32 LeafIndex) const;
    void getLeafTriangleInfo(u16*, u32&, u32, u32) const;
    const Triangle* getRootTrianglePtrConst(u32 PartsIndex) const;
    const Triangle* getRootTrianglePtrConst(const PartsInfo&) const;
    const Triangle* getTrianglePtrConst(const PartsInfo&, u32) const;
    const Triangle& getTriangleConst(u32 PartsIndex, u32 TriangleIndex) const;
    const Vertex* getRootVertexPtrConst(u32) const;
    const Vertex* getRootVertexPtrConst(const PartsInfo& RPartsInfo) const;
    u32 traversePartsSpaceDivision(const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex);
    u32 traversePartsSpaceDivisionOnce(const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex);
    u32 traverseTriangleSpaceDivision(u32 PartsIndex, const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex);
    u32 traverseTriangleSpaceDivisionOnce(u32 PartsIndex, const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex);
    u32 getSpaceSplitTypeParts();
    u32 getSpaceSplitTypeTriangle();
protected:
    bool loadCore(MtDataReader& r, bool FlgEndianChange);
    rCollision* makeCopyCore(MT_CTSTR ResourcePath, const MtMatrix& mat, bool FlgMultiThread);
    bool copy(rCollision& src, const MtMatrix& mat, bool FlgMultiThread);
    void copyMultiThread(rCollision& src, const MtMatrix& mat, COPY_FUNC func, u32 TargetNum);
    void copyMultiThreadJob(uintptr WorkDataPtr);
    bool copyParts(rCollision& src, u32 TargetPartsIndex, const MtMatrix& mat);
    void copyVertex(rCollision& src, u32 TargetVertexIndex, const MtMatrix& mat);
    void copyTriangle(rCollision& src, u32 TargetTriangleIndex, const MtMatrix& mat);
    void copyLeaf(rCollision& src, u32 TargetLeafIndex, const MtMatrix& mat);
    void copyHeader(rCollision& src, const MtMatrix& mat);
    void setPartsInfoSize(u32 size);
    void setMaterialInfoSize(u32 size);
    void setLeafSize(u32 size);
    void setTriangleSize(u32 size);
    void setVertexSize(u32 size);
    void releasePartsBroadPhaseData();
    void makePartsInfoUI();
    void makeMaterialInfoUI();
    bool bulkAllocateMemoryAll(const Header& LoadHeaderInfo, u32 BroadPhaseInsideWorkSize, nCollisionUtil::LoadBuffer& AllocateResult);
    bool isBulkAllocateMemoryAll() const;
    u32 getUsedMemorySize() const;
    u32 getPartsMemorySize() const;
    u32 getTriangleMemorySize() const;
    u32 getVertexMemorySize() const;
    Header* getHeaderPtr();
    PartsInfo* getPartsInfoPtr();
    MaterialInfo* getMaterialInfoPtr();
    Triangle* getTrianglePtr();
    Vertex* getVertexPtr();
    PartsInfo* getPartsInfoPtr(u32 PartsIndex);
    Leaf* getRootLeafPtr(u32);
    Triangle* getRootTrianglePtr(u32 PartsIndex);
    Triangle* getRootTrianglePtr(PartsInfo& RPartsInfo);
    Vertex* getRootVertexPtr(u32 PartsIndex);
    Vertex* getRootVertexPtr(PartsInfo& RPartsInfo);
    Triangle* getTrianglePtr(PartsInfo&, u32);
    Triangle& getTriangle(u32, u32);
    MaterialInfo* getMaterialInfoPtr(u32 MaterialIndex);
    u32 getTriangleMaterialInfoID(PartsInfo&, u32);
    MaterialInfo* getTriangleMaterialInfoPtr(PartsInfo&, u32);
    MaterialInfo* getTriangleMaterialInfoPtr(const Triangle*);
    Vertex& getVertex(u32, u32);
public:
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    Header mHeader;  // offset: 0x70
    cBVHCollision* mpBvh;  // offset: 0xc0
    cGridCollision* mpGrid;  // offset: 0xc8
    cGridCollisionRegistInfo* mpGridRegistInfo;  // offset: 0xd0
    PartsInfo* mpPartsInfo;  // offset: 0xd8
    MaterialInfo* mpMaterialInfo;  // offset: 0xe0
    Leaf* mpLeaf;  // offset: 0xe8
    Triangle* mpTriangle;  // offset: 0xf0
    Vertex* mpVertex;  // offset: 0xf8
    u32* mpSbcModifyClassIDArray;  // offset: 0x100
public:
    static MyDTI DTI;
    static const u32 SBC_MAIN_VERSION;
    static const u32 SBC_SUB_VERSION_PARTS_ID_ANALYZEMODE_RMODEL;
    static const u32 SBC_MAIN_VERSION_SURPLUS_PARAM;
    static const u16 INVALID_INDEX = 65535;
    static const u32 ANALIZE_TREE_LEVEL;
    static const u32 MATERIAL_USER_ATTRIBUTE_NUM = 4;
    static const u32 TRIANGLE_ATTRIBUTE_NUM = 1;
};
