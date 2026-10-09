#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cGridCollision.h"
#include "cResource.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat3;
class MtGeometry;
class MtObject;
class MtStream;
class MtTriangle;
class MtVector3;
class cGridCollision;
class cGridCollisionRegistInfo;
namespace nCollision { struct ScrMaterialInfo; }

// Declarations
class rCollisionHeightField;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class rCollisionHeightField : public cResource
{
public:
    enum
    {
        CELL_VERTEX_INDEX_L = 0,
        CELL_VERTEX_INDEX_T = 1,
        CELL_VERTEX_INDEX_R = 2,
        CELL_VERTEX_INDEX_B = 3,
        CELL_VERTEX_INDEX_NUM = 4,
    };
    enum
    {
        CELL_VERTEX_LT = 0,
        CELL_VERTEX_LB = 1,
        CELL_VERTEX_RT = 2,
        CELL_VERTEX_RB = 3,
        CELL_VERTEX_NUM = 4,
    };
public:
    class MyDTI;
    class cCellGroup;
    struct TraverseInfoForScr;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCellGroup
    {
    public:
        cCellGroup();
        ~cCellGroup();
        bool load(MtDataReader& fin);
        bool save(MtDataWriter& fout);
        const MtVector3& getPolygonNormal(u32 TriangleIndex) const;
    public:
        MtFloat3 mPolygonNormal0;  // offset: 0x0
        u16 mMaterialIndex[2];  // offset: 0xc
        MtFloat3 mPolygonNormal1;  // offset: 0x10
        bool mFlgActive[2];  // offset: 0x1c
        bool mFlgFlat;  // offset: 0x1e
        bool mFlgFlatAndPlaneXZ;  // offset: 0x1f
        cGridCollisionRegistInfo mGridRegistInfo;  // offset: 0x20
        s16 mVertexIndex[4];  // offset: 0xe0
        bool mFlgSplitDefault;  // offset: 0xe8
    };
public:
    struct TraverseInfoForScr
    {
    public:
        MtObject* pCallbackOwner;  // offset: 0x0
        cGridCollision::TRAVERSE_CALLBACK pCallbackFunction;  // offset: 0x8
        u32 UserParam;  // offset: 0x18
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
    rCollisionHeightField();
    virtual ~rCollisionHeightField();
    virtual bool load(MtStream& r);  // vtable slot 11
    virtual bool save(MtStream& w);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 traverse(const MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, cGridCollision::TRAVERSE_CALLBACK pCallbackFunction, uintptr CallbackParam, u32 ThreadIndex);
    bool isEqualRefCountTargetGrid(u32 GridIndexX, u32 GridIndexZ, uintptr TraverseCallback_SytemParam);
    MtVector3 getVertex(u32 VertexIndexX, u32 VertexIndexZ);
    MtVector3 getVertex(u32 GridIndexX, u32 GridIndexZ, u32 VertexIndex);
    void getGridRect(MtVector3& RectLT, MtVector3& RectLB, MtVector3& RectRT, MtVector3& RectRB, u32 GridIndexX, u32 GridIndexZ);
    MtTriangle getGridTriangle(u32 GridIndexX, u32 GridIndexZ, u32 TriangleIndex);
    bool isActiveGridTriangle(u32 GridIndexX, u32 GridIndexZ, u32 TriangleIndex);
    const MtVector3& getGridTriangleNormal(u32 GridIndexX, u32 GridIndexZ, u32 TriangleIndex);
    nCollision::ScrMaterialInfo& getGridMaterial(u32 GridIndexX, u32 GridIndexZ, u32 TriangleIndex);
    nCollision::ScrMaterialInfo& getGridMaterial(u32 MaterialIndex) const;
    u32 getGridInCellGroupIndex(u32 GridIndexX, u32 GridIndexZ) const;
    MtVector3 getCellGroupVertex(u32 GridIndexX, u32 GridIndexZ, u32 VertexIndex);
    MtVector3 getCellGroupVertex(u32 CellGroupIndex, u32 VertexIndex);
    void getCellGroupRect(MtVector3& RectLT, MtVector3& RectLB, MtVector3& RectRT, MtVector3& RectRB, u32 CellGroupIndex);
    MtTriangle getCellGroupTriangle(u32 CellGroupIndex, u32 TriangleIndex);
    void getCellGroupTriangleAndRect(MtTriangle& triA, MtTriangle& triB, MtVector3& RectLT, MtVector3& RectLB, MtVector3& RectRT, MtVector3& RectRB, u32 CellGroupIndex);
    bool isActiveCellGroupTriangle(u32 CellGroupIndex, u32 TriangleIndex);
    const MtVector3& getCellGroupTriangleNormal(u32 CellGroupIndex, u32 TriangleIndex);
    nCollision::ScrMaterialInfo& getCellGroupMaterial(u32 CellGrpupIndex, u32 TriangleIndex);
    const cCellGroup& getCellGroup(u32 GridIndexX, u32 GridIndexZ) const;
    const cCellGroup& getCellGroup(u32 CellGroupIndex) const;
    const MtAABB& getBoundingAABB() const;
    u32 getGridNumX() const;
    u32 getGridNumZ() const;
    void* memAlloc(size_t s);
    void memFree(void* padr);
    size_t memSize(void*);
protected:
    u32 callbackGridForTraverseScrCollision(u32 x, u32 z, u32 LeafID, u32 UserParam, u32 SystemParam);
    void drawCallback(uintptr param);
    u32 getVertexID(u32 VertexIndexX, u32 VertexIndexZ) const;
    cCellGroup& getCellGroupForInside(u32 GridIndexX, u32 GridIndexZ);
    cCellGroup& getCellGroupForInside(u32 CellGroupIndex);
    void allocateNativeMemoryCell(u32 CelllNum);
    void allocateNativeMemoryVertexHeight(u32 VertexNum);
    void allocateNativeMemoryMaterial(u32 MaterialNum);
    MtAABB getBoundingAABBForUI();
    u32 getGridNumX_ForUI();
    u32 getGridNumZ_ForUI();
    void setDummyAABB(const MtAABB&);
    void setDummyU32(u32);
protected:
    u32 mMagic;  // offset: 0x70
    u32 mVersion;  // offset: 0x74
    cGridCollision* mpGridCollision;  // offset: 0x78
    cCellGroup* mpCellGroupArray;  // offset: 0x80
    u32 mCellGroupNum;  // offset: 0x88
    nCollision::ScrMaterialInfo* mpMaterialArray;  // offset: 0x90
    u32 mMaterialNum;  // offset: 0x98
    f32* mpVertexHeightArray;  // offset: 0xa0
    u32 mVertexNum;  // offset: 0xa8
    u8* mpGridSpletType;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const u32 MAGIC;
    static const u32 VERSION;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK21rCollisionHeightField5MyDTI11newInstanceEv at 0x01207fc0-0x01208034, code DWARF attributes to no inlined copy
inline rCollisionHeightField::rCollisionHeightField() {
    this->::cResource::mAttr = static_cast<u32>(18);
    this->mpMaterialArray = static_cast<nCollision::ScrMaterialInfo*>(nullptr);
    this->mpVertexHeightArray = static_cast<f32*>(nullptr);
    this->mMaterialNum = static_cast<u32>(0);
    this->mVertexNum = static_cast<u32>(0);
    this->mCellGroupNum = static_cast<u32>(0);
    this->mpCellGroupArray = static_cast<rCollisionHeightField::cCellGroup*>(nullptr);
    this->mpGridCollision = static_cast<cGridCollision*>(nullptr);
    this->mMagic = static_cast<u32>(0);
    this->mVersion = static_cast<u32>(0);
}
