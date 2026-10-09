#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "rModel.h"
#include "uModel.h"

// Forward declarations
class BakedQueue;
class MtAABB;
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtSphere;
class MtVector3;
class MtVector4;
class cDDMaterialCtrl;
class cDraw;
class cpBakeJoint;
namespace nDraw { class CommandCache; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Material; }
namespace nDraw { class VertexBuffer; }
class rDeformWeightMap;
class rModel;
class uCustomSimSoftBody;
class uModel;

// Declarations
class cBakeModel;
class cBakeModelEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cBakeModel : public MtObject
{
    // inferred: cDDMaterialCtrl::setCommonState names cBakeModel::mMaterialNum
    friend class cDDMaterialCtrl;
    // inferred: uCustomSimSoftBody::hasTarget names cBakeModel::mpModel
    friend class uCustomSimSoftBody;
public:
    enum STAT
    {
        S_BUILD_START = 1,
        S_BAKED = 2,
        S_POLY_NORMAL = 4,
        S_PART_QUANT = 8,
        S_UNIT_QUANT = 16,
        S_MASTER = 32,
    };
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    cBakeModel();
    virtual void initialize();  // vtable slot 6
    virtual ~cBakeModel();
    virtual void finalize();  // vtable slot 7
    u32 getState() const;
    bool setModel(rModel* pmod, bool material_flag);
    rModel* getModel() const;
    nDraw::VertexBuffer* getVertexBuffer() const;
    f32 getQuantPosScale() const;
    const MtVector4 getQuantPosOffset() const;
    const MtAABB getBoundingBox() const;
    void buildJointIndexTable(uModel* pumodel);
    bool buildBakeJointsVertex(cpBakeJoint* pcallback, uModel* pumodel, bool isSoftBody);
    bool rebuildQuantPos(cpBakeJoint* pcallback, const MtAABB& aabb, bool isSoftBody);
    void updateMaterial(f32 dt);
    void updateMaterial(f32 dt, bool alpha);
    void resetMaterial(u32 index);
    nDraw::Material* getMaterial(u32 index);
    void setMaterial(nDraw::Material* pmaterial, u32 index);
    nDraw::Material* * getMaterials();
    nDraw::Material* * getNukiMaterials();
    u32 getMaterialNum();
    u8 getModJointIndex(u32 res_index) const;
    nDraw::IndexBuffer* getIndexBuffer() const;
    rModel::PRIMITIVE_INFO* getPrimitives() const;
    u32 getPrimitiveNum() const;
    void cullingCommandCache(uModel* pumodel, cDraw* pdraw, nDraw::CommandCache* pcache, s32 basecullmask, u32 lod);
    void deleteNukiMaterials();
    void createNukiMaterials();
    void copyNukiMaterial(u32 index);
    // Address: 0x01950d40 - 0x01950d41 (1 bytes)
    virtual void udpatePtr() {}  // vtable slot 8
protected:
    virtual u32 callDrawPrimWrapper(cDraw* pdraw, u32 primIdx, u32 step, u32 lodidx);  // vtable slot 9
    // Address: 0x01950bf0 - 0x01950bf1 (1 bytes)
    virtual void resetSoftBodyStream(cDraw* pdraw) {}  // vtable slot 10
    virtual void drawIndexedPolymorphic(u32 i, cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, bool edge);  // vtable slot 11
    virtual void setTransparencySortPolymorphic(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, uModel* pumodel);  // vtable slot 12
    virtual bool checkSoftBodyResource();  // vtable slot 13
public:
    virtual bool convertSoftBody();  // vtable slot 14
    void setHair();
    bool isHair() const;
    void setConvertJointTable(uModel* punit);
    f32* getConvertJointTable();
    void releaseCommandCacheArray(const u32);
    void setCommandCacheArray(const u32, nDraw::CommandCache*);
    void setCommandCacheLOD(const u32, u32);
    void setCommandCacheThread(const u32, s32);
    nDraw::CommandCache* getCommandCacheArray(const u32) const;
    u32 getCommandCacheLOD(const u32) const;
    s32 getCommandCacheThread(const u32) const;
    void issueBakingModel(cDraw* pdraw, uModel* pCallerUnit, const MtVector3& cpos, u32 lod, s32 basecullmask, s32 shadow_cullmask, f32 vdist, u32 vpri, u32 spri);
    void issueBakedModel(cDraw* pdraw, uModel* pCallerUnit, const MtVector3& cpos, u32 lod, s32 basecullmask, s32 shadow_cullmask, f32 vdist, u32 vpri, u32 spri);
protected:
    u32 mStat;  // offset: 0x8
    rModel* mpModel;  // offset: 0x10
    nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0x18
    nDraw::IndexBuffer* mpIndexBuffer;  // offset: 0x20
    u8* mpTempVertexBuffer;  // offset: 0x28
    u32 mTempVertexBufferSize;  // offset: 0x30
    rModel::PRIMITIVE_INFO* mpPrimitiveInfo;  // offset: 0x38
    u32 mPrimitiveInfoNum;  // offset: 0x40
    nDraw::Material* * mpaMaterials;  // offset: 0x48
    nDraw::Material* * mpaNukiMaterials;  // offset: 0x50
    u32 mMaterialNum;  // offset: 0x58
    MtAABB mAABB;  // offset: 0x60
    f32 mQuantPosScale;  // offset: 0x80
    alignas(16) u8 mOrgToMod[256];  // offset: 0x90
    MtVector4 mQuantPosOffset;  // offset: 0x190
    f32 mConvertJointForCE[256];  // offset: 0x1a0
    bool mIsHair;  // offset: 0x5a0
    nDraw::CommandCache* mpCommandCache[96];  // offset: 0x5a8
    u32 mCacheLOD[96];  // offset: 0x8a8
    s32 mCacheThread[96];  // offset: 0xa28
public:
    static MyDTI DTI;
};

class cBakeModelEx : public cBakeModel
{
public:
    void setCallBackModel(cpBakeJoint* pcallback, uModel* pcallerunit);
    cBakeModelEx();
    virtual void initialize();  // vtable slot 6
    virtual void finalize();  // vtable slot 7
    bool isEnable();
    bool isMove();
    u32 getJointNum();
    bool isPartsDisp(u32 no);
    const MtVector3& getPos();
    const MtMatrix& getWorldNullMatrix();
    const uModel::Joint* getJointFromIndex(s32 jointIndex);
    const MtSphere& getBoundingSphere();
    void setCustomSimSoftBody(MT_CTSTR path, BakedQueue* pbq, uModel* mpCallerUnit);
    uCustomSimSoftBody* getCustomSimSoftBody();
    virtual u32 callDrawPrimWrapper(cDraw* pdraw, u32 primIdx, u32 step, u32 lodidx);  // vtable slot 9
    virtual void resetSoftBodyStream(cDraw* pdraw);  // vtable slot 10
    virtual bool checkSoftBodyResource();  // vtable slot 13
    virtual void drawIndexedPolymorphic(u32 i, cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, bool edge);  // vtable slot 11
    virtual void setTransparencySortPolymorphic(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, uModel* pumodel);  // vtable slot 12
    virtual void udpatePtr();  // vtable slot 8
    virtual bool convertSoftBody();  // vtable slot 14
    void disableSoftBody(bool f);
    void issueBakedSoftModel(cDraw* pdraw, uModel* pCallerUnit, const MtVector3& cpos, u32 lod, s32 basecullmask, s32 shadow_cullmask, f32 vdist, u32 vpri, u32 spri);
public:
    cpBakeJoint* mpCallBack;  // offset: 0xba8
    uModel* mpCallerUnit;  // offset: 0xbb0
    bool mDisableSoftBody;  // offset: 0xbb8
    uCustomSimSoftBody* mpCustomSoftBody;  // offset: 0xbc0
    rDeformWeightMap* mpDeformWeightMap;  // offset: 0xbc8
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rModel* cBakeModel::getModel() const {
    return this->mpModel;
}

// Inline, no code of its own: checked where it is inlined.
inline nDraw::VertexBuffer* cBakeModel::getVertexBuffer() const {
    return this->mpVertexBuffer;
}

// Inline, no code of its own: checked where it is inlined.
inline nDraw::IndexBuffer* cBakeModel::getIndexBuffer() const {
    return this->mpIndexBuffer;
}

// Inline, no code of its own: checked where it is inlined.
inline rModel::PRIMITIVE_INFO* cBakeModel::getPrimitives() const {
    return this->mpPrimitiveInfo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cBakeModel::getPrimitiveNum() const {
    return this->mPrimitiveInfoNum;
}
