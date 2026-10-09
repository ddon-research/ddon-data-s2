#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtPrimitive3D.h"
#include "cUnit.h"
#include "nCollision.h"
#include "rDynamicSbc.h"
#include "sCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtTriangle;
class MtUI;
class MtVector3;
class MtVector4;
class cBVHCollision;
class cDraw;
namespace nCollision { struct ScrMaterialInfo; }
namespace nCollision { class cScrCommonFilter; }
class rDynamicSbc;
class uModel;

// Declarations
class uDynamicSbc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uDynamicSbc : public cUnit
{
public:
    class MyDTI;
    struct CpuSkiningJobInfo;
    class cPartsInfo;
    class cBvhJobInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CpuSkiningJobInfo
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
        u32 StartVertexIdx;  // offset: 0x0
        u32 EndVertexIdx;  // offset: 0x4
    };
public:
    class cBvhJobInfo
    {
    public:
        cBvhJobInfo();
        ~cBvhJobInfo();
        void allocateBvh(MtObject* _pObj, u32 _PartsNo, u32 _RootTriangleIndex, u32 _TriangleNum);
        cBVHCollision* getBvhPtr();
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
    public:
        cBVHCollision* mpBvh;  // offset: 0x0
        MtAABB* mpTriangleAABB;  // offset: 0x8
        u32 mPartsNo;  // offset: 0x10
        u32 mRootTriangleIndex;  // offset: 0x14
        u32 mTriangleNum;  // offset: 0x18
    };
public:
    class cPartsInfo
    {
    public:
        cPartsInfo();
        ~cPartsInfo();
        uDynamicSbc::cBvhJobInfo& getBvhInfo(u32 BvhIndex);
        const uDynamicSbc::cBvhJobInfo& getBvhInfoConst(u32 BvhIndex) const;
        u32 getBvhInfoNum() const;
    public:
        u32 mPartsID;  // offset: 0x0
        uDynamicSbc::cBvhJobInfo mBvhInfo[2];  // offset: 0x8
        u32 mBvhInfoNum;  // offset: 0x48
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
    uDynamicSbc();
    virtual ~uDynamicSbc();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setOwner(uModel* pmod, rDynamicSbc* pUseDynamicSbc);  // vtable slot 24
    virtual uModel* getOwner();  // vtable slot 25
    void updateCollision(bool FlgRunPhase0, bool FlgRunPhase1, bool FlgRunPhase2, bool FlgRunExecute);
    void updateVertex();
    void updateVertexMultiThread(bool FlgRunExecute);
    void updateVertexMultiThreadDelay();
    cPartsInfo& getPartsInfo(u32 PartsIndex);
    const cPartsInfo& getPartsInfoConst(u32 PartsIndex) const;
    u32 getPartsInfoNum() const;
    bool isPartsActiveByIndex(u32 PartsIndex) const;
    bool isPartsActiveByID(u32 PartsID) const;
    cBVHCollision& getBvh(u32 PartsIndex, u32 BVHIndex);
    u32 getBvhNum(u32 PartsIndex) const;
    const MtAABB& getBoundingAABB() const;
    MtTriangle getTriangle(u32) const;
    MtTriangle getTriangle(u32 PartsIndex, u32 BvhIndex, u32 TriIndex) const;
    MtAABB& getTriangleAABB(u32 PartsIndex, u32 BvhIndex, u32 TriIndex);
    const MtAABB& getTriangleAABBConst(u32, u32, u32) const;
    MtVector3 getTriangleNormal(u32 PartsIndex, u32 BvhIndex, u32 TriIndex) const;
    bool isUse();
    rDynamicSbc* getStaticData();
    void setStaticData(rDynamicSbc* pRDSbc);
    rDynamicSbc* getResource();
    const rDynamicSbc* getResourceConst() const;
    const nCollision::ScrMaterialInfo& getMaterialInfoConst(u32 PartsIndex, u32 BvhIndex, u32 TriIndex) const;
    u32 getSbcType() const;
    void setSbcType(u32 set);
    u32 getSbcGroup() const;
    u8 getSbcGroupIndex() const;
    void setSbcGroup(u8 GroupIndex);
    bool isSbcHitTarget(u32 TargetType, u32 TargetGroup) const;
    bool isMultiThread() const;
    void setMultiThread(bool set);
    static void copyModelDataUtil(uModel& OutputModel, uModel& InputModel);
protected:
    void runCheckEnableOwner();
    void setOwnerUI(uModel* pmod);
    uModel* getOwnerUI();
    void updateCollisionJob(u32 JobInfo);
    void updateVertexBefore();
    void updateVertexJob(u32 JobID);
    void clear();
    void makeDynamicCollisionData();
    void makeDynamicCollisionWorkData();
    MtVector4& getSkinningBuffer(u32 BufferID);
    MtVector3& getSkinX(u32 VertexID);
    rDynamicSbc::VertexJointInfo& getVertexJointInfo(u32);
    MtVector4& getStaticVertexPosition(u32);
protected:
    uModel* mpOwner;  // offset: 0x48
    rDynamicSbc* mpStaticData;  // offset: 0x50
    MtVector4* mpSkinningBuffer;  // offset: 0x58
    MtAABB mBoundingAABB;  // offset: 0x60
    MtVector3* mpSkinX;  // offset: 0x80
    CpuSkiningJobInfo mCpuSkinningInfo[3];  // offset: 0x88
    cPartsInfo* mpPartsInfo;  // offset: 0xa0
    u32 mPartsNum;  // offset: 0xa8
    nCollision::cScrCommonFilter mScrFilter;  // offset: 0xb0
    sCollision::cSbcSkinMesh::cRegisterInfo* mpRegisterInfo;  // offset: 0xc8
    bool mFlgPartsActive[256];  // offset: 0xd0
    bool mFlgSetup;  // offset: 0x1d0
    bool mFlgMultiThread;  // offset: 0x1d1
public:
    static MyDTI DTI;
    static const u32 BVH_DIVIDE_NUM = 2;
    static const u32 CPU_SKINNING_DIVIDE_NUM = 2;
    static const u32 MIN_BVH_TRIANGLE_NUM = 1000;
};
