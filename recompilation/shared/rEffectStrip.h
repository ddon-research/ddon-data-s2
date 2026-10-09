#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class uModel;

// Declarations
class rEffectStrip;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rEffectStrip : public cResource
{
public:
    enum STRIP_FLAG
    {
        STRIP_FLAG_ORDER = 1,
        STRIP_FLAG_REVERSE = 2,
        STRIP_FLAG_NORM_OFF = 4,
        STRIP_FLAG_PATH_LOOP = 8,
        STRIP_FLAG_CENTER_FIX = 16,
        STRIP_FLAG_ALL_PARTS = 32,
        STRIP_FLAG_SKINING = 64,
    };
public:
    class MyDTI;
    struct PARTS_PARAM;
    struct VERTEX_PARAM;
    struct INDEX_PARAM;
    struct EFS_HEADER;
public:
    using PARTS_PARAM = rEffectStrip::PARTS_PARAM;
    using VERTEX_PARAM = rEffectStrip::VERTEX_PARAM;
    using INDEX_PARAM = rEffectStrip::INDEX_PARAM;
    using EFS_HEADER = rEffectStrip::EFS_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PARTS_PARAM
    {
    public:
        u32 VertexNum;  // offset: 0x0
        u32 IndexNum;  // offset: 0x4
    };
public:
    struct VERTEX_PARAM
    {
    public:
        MtFloat3 Pos;  // offset: 0x0
        union
        {
        public:
            u32 BlendIndices;  // offset: 0x0
            struct
            {
            public:
                u32 BlendIndex0 : 8;  // offset: 0x0
                u32 BlendIndex1 : 8;  // offset: 0x0
                u32 BlendIndex2 : 8;  // offset: 0x0
                u32 BlendIndex3 : 8;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0xc
        MtFloat3 Norm;  // offset: 0x10
        union
        {
        public:
            u32 BlendWeights;  // offset: 0x0
            struct
            {
            public:
                u32 BlendWeight0 : 8;  // offset: 0x0
                u32 BlendWeight1 : 8;  // offset: 0x0
                u32 BlendWeight2 : 8;  // offset: 0x0
                u32 BlendWeight3 : 8;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x1c
    };
public:
    struct INDEX_PARAM
    {
    public:
        u32 VertexNo0 : 16;  // offset: 0x0
        u32 VertexNo1 : 16;  // offset: 0x0
        u32 VertexNo2 : 16;  // offset: 0x4
        u32 IndexParam3206 : 16;  // offset: 0x4
    };
public:
    struct EFS_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        u32 EfsHeader320c;  // offset: 0xc
        u32 PartsNum;  // offset: 0x10
        u32 JointNum;  // offset: 0x14
        u32 TotalVertexNum;  // offset: 0x18
        u32 TotalIndexNum;  // offset: 0x1c
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
    rEffectStrip();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getPartsNum() const;
    PARTS_PARAM* getPartsParam(u32 PartsNo);
    VERTEX_PARAM* getVertexParamTop(PARTS_PARAM* pPartsParam);
    VERTEX_PARAM* getVertexParamTop(u32 PartsNo);
    INDEX_PARAM* getIndexParamTop(PARTS_PARAM* pPartsParam);
    INDEX_PARAM* getIndexParamTop(u32 PartsNo);
    u32 getResourceSize() const;
    u32 getTotalVertexNum() const;
    u32 getTotalIndexNum() const;
    bool calcVertex(u32 PartsNo, u32 VertexNo, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcVertex(u32 PartsNo, u32 VertexNo, MtVector3* pPos, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathLinearVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathLinearVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, f32 Rate, MtVector3* pPos, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathHermiteVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathHermiteVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, f32 Rate, MtVector3* pPos, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathSplineVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, u32 VertexNo3, u32 Node, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcPathSplineVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, u32 VertexNo3, u32 Node, f32 Rate, MtVector3* pPos, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcModelVertex(u32 PartsNo, u32 IndexNo, f32 Rate0, f32 Rate1, f32 Rate2, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcVertices(u32 PartsNo, MtVector3* PosArray, MtVector3* NormArray, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcVertices(u32 PartsNo, MtVector3* PosArray, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcVertices(u32 PartsNo, MtVector3* PosArray, MtVector3* NormArray, u32* VertexNoArray, u32 ArrayNum, const MtVector3& Ofs, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    bool calcVertices(u32 PartsNo, MtVector3* PosArray, u32* VertexNoArray, u32 ArrayNum, uModel* pModelUnit, u32 ModelJointNo, const MtVector3& Scale);
    void getVertex(u32 PartsNo, u32 VertexNo, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Scale);
    void getVertex(u32 PartsNo, u32 VertexNo, MtVector3* pPos, const MtVector3& Scale);
    void getPathLinearVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Scale);
    void getPathLinearVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, f32 Rate, MtVector3* pPos, const MtVector3& Scale);
    void getPathHermiteVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Scale);
    void getPathHermiteVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, f32 Rate, MtVector3* pPos, const MtVector3& Scale);
    void getPathSplineVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, u32 VertexNo3, u32 Node, f32 Rate, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Scale);
    void getPathSplineVertex(u32 PartsNo, u32 VertexNo0, u32 VertexNo1, u32 VertexNo2, u32 VertexNo3, u32 Node, f32 Rate, MtVector3* pPos, const MtVector3& Scale);
    void getModelVertex(u32 PartsNo, u32 IndexNo, f32 Rate0, f32 Rate1, f32 Rate2, MtVector3* pPos, MtVector3* pNorm, const MtVector3& Scale);
    void getVertices(u32 PartsNo, MtVector3* PosArray, MtVector3* NormArray, const MtVector3& Scale);
    void getVertices(u32 PartsNo, MtVector3* PosArray, const MtVector3& Scale);
    void getVertices(u32 PartsNo, MtVector3* PosArray, MtVector3* NormArray, u32* VertexNoArray, u32 ArrayNum, const MtVector3& Scale);
    void getVertices(u32 PartsNo, MtVector3* PosArray, u32* VertexNoArray, u32 ArrayNum, const MtVector3& Scale);
protected:
    virtual ~rEffectStrip();
    bool allocMemory(u32 ParamBuffSize, EFS_HEADER* pHeader);
    MtMatrix calcBlendVertexWorldMatrix(uModel* pModelUnit, const MtMatrix* pImat, const u8* pJointIndexTbl, VERTEX_PARAM* pVertexParam, const MtVector3& Scale);
private:
    void constructParam();
    void destructParam();
protected:
    u8* mpParamBuff;  // offset: 0x70
    u32 mParamBuffSize;  // offset: 0x78
    u32 mPartsNum;  // offset: 0x7c
    u32 mJointNum;  // offset: 0x80
    u32 mTotalVertexNum;  // offset: 0x84
    u32 mTotalIndexNum;  // offset: 0x88
public:
    static MyDTI DTI;
protected:
    static const u32 EFS_MAGIC = 5457477;
    static const u32 EFS_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK12rEffectStrip5MyDTI11newInstanceEv at 0x011f46b0-0x011f46fa, code DWARF attributes to no inlined copy
inline rEffectStrip::rEffectStrip() {
    this->mTotalIndexNum = static_cast<u32>(0);
    this->mJointNum = static_cast<u32>(0);
    this->mTotalVertexNum = static_cast<u32>(0);
    this->mParamBuffSize = static_cast<u32>(0);
    this->mPartsNum = static_cast<u32>(0);
    this->mpParamBuff = static_cast<u8*>(nullptr);
    this->::cResource::mAttr = static_cast<u32>(22);
}
