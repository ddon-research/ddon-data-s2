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
class MtMatrix;
class MtObject;
class MtStream;
class MtVector4;
namespace nCollision { struct ScrMaterialInfo; }

// Declarations
class rDynamicSbc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rDynamicSbc : public cResource
{
public:
    class MyDTI;
    struct Triangle;
    struct VertexJointInfo;
    struct JointInfo;
    struct PartsInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Triangle
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    public:
        u64 v0 : 16;  // offset: 0x0
        u64 v1 : 16;  // offset: 0x0
        u64 v2 : 16;  // offset: 0x0
        u64 MaterialIndex : 16;  // offset: 0x0
    };
public:
    struct VertexJointInfo
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    public:
        u32 j0 : 8;  // offset: 0x0
        u32 j1 : 8;  // offset: 0x0
        u32 j2 : 8;  // offset: 0x0
        u32 j3 : 8;  // offset: 0x0
    };
public:
    struct JointInfo
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    public:
        MtMatrix BasePoseInverseMatrix;  // offset: 0x0
        u32 JointNo;  // offset: 0x40
    };
public:
    struct PartsInfo
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    public:
        u32 PartsID;  // offset: 0x0
        u32* pTriangleIndex;  // offset: 0x8
        u32 TriangleNum;  // offset: 0x10
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
    rDynamicSbc();
    virtual ~rDynamicSbc();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    u32 getTriangleNum() const;
    u32 getVertexNum() const;
    u32 getPartsInfoNum() const;
    u32 getJointNum() const;
    const VertexJointInfo& getVertexJointInfoConst(u32 VertexID) const;
    const MtVector4& getVertexPositionConst(u32 VtxID) const;
    const MtVector4& getVertexWeightConst(u32 VtxID) const;
    const Triangle& getTriangleConst(u32 triNo) const;
    const nCollision::ScrMaterialInfo& getMaterialInfoConst(u32 triNo) const;
    const PartsInfo& getPartsInfoConst(u32 PartsNo) const;
    const Triangle& getTriangleConst(u32, u32) const;
    const nCollision::ScrMaterialInfo& getMaterialInfoConst(u32, u32) const;
    VertexJointInfo& getVertexJointInfo(u32);
    MtVector4& getVertexPosition(u32);
    Triangle& getTriangle(u32 triNo);
    nCollision::ScrMaterialInfo& getMaterialInfo(u32 triNo);
    PartsInfo& getPartsInfo(u32 PartsNo);
    Triangle& getTriangle(u32 PartsNo, u32 triNo);
    nCollision::ScrMaterialInfo& getMaterialInfo(u32, u32);
    JointInfo& getJointInfo(u32 JointNo);
    u32 getJointIndexFromNo(u32 no);
protected:
    void* memAlloc(size_t size);
    void memFree(void* p_addr);
protected:
    Triangle* mpTriList;  // offset: 0x70
    VertexJointInfo* mpVertexJointInfo;  // offset: 0x78
    MtVector4* mpVertexPos;  // offset: 0x80
    MtVector4* mpVertexWeight;  // offset: 0x88
    u32 mVertexNum;  // offset: 0x90
    u32 mTriangleNum;  // offset: 0x94
    JointInfo* mpJointInfo;  // offset: 0x98
    u32 mJointNum;  // offset: 0xa0
    nCollision::ScrMaterialInfo* mpMaterialInfo;  // offset: 0xa8
    u32 mMaterialNum;  // offset: 0xb0
    PartsInfo* mpPartsList;  // offset: 0xb8
    u32 mPartsNum;  // offset: 0xc0
    u8 mJointTable[256];  // offset: 0xc4
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION;
    static const u32 MAX_MODEL_PARTS_NUM = 256;
};
