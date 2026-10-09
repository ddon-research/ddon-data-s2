#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "rModel.h"
#include "uSimSoftBody.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtSphere;
class MtVector3;
class MtVector4;
class cBakeModelEx;
class cDraw;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class VertexBuffer; }

// Declarations
class uCustomSimSoftBody;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCustomSimSoftBody : public uSimSoftBody
{
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
    uCustomSimSoftBody();
    virtual ~uCustomSimSoftBody();
    virtual void draw(cDraw* pdraw);  // vtable slot 12
protected:
    // Address: 0x01ad3d70 - 0x01ad3d71 (1 bytes)
    virtual void setNullTarget() {}  // vtable slot 24
    virtual bool hasTarget() const;  // vtable slot 25
    virtual bool isTargetEnable() const;  // vtable slot 26
    virtual nDraw::VertexBuffer* getTargetVertexBuffer() const;  // vtable slot 27
    virtual nDraw::IndexBuffer* getTargetIndexBuffer() const;  // vtable slot 28
    virtual const rModel::PRIMITIVE_INFO* getTargetPrimitives() const;  // vtable slot 29
    virtual u32 getTargetPrimitiveNum() const;  // vtable slot 30
    virtual u32 getTargetJointNum() const;  // vtable slot 31
    virtual bool isTargetPartsDisp(u32 no) const;  // vtable slot 32
    virtual const MtVector3& getTargetPos() const;  // vtable slot 33
    virtual void setTargetCommonState(cDraw* pdraw);  // vtable slot 41
    virtual const MtMatrix& getTargetJointMatrix(s32 jointIndex) const;  // vtable slot 37
    virtual const MtSphere& getTargetBoundingSphere() const;  // vtable slot 43
    virtual void getTargetBoundingAABB(MtAABB& aabb) const;  // vtable slot 44
    virtual void getTargetTightBoundingAABB(MtAABB& aabb) const;  // vtable slot 45
    virtual void createSkinningMatrix(MtVector4* pdst, u32 jnt_num);  // vtable slot 46
public:
    void setBakeModel(cBakeModelEx* target);
    nDraw::VertexBuffer* * getSoftBodyVB();
    u32 getSoftBodyVBstride();
    u32 getVbufNo();
    void setPause(bool);
    bool isPause();
    virtual bool isDivideDelete() const;  // vtable slot 48
    virtual bool isDeleteComplete() const;  // vtable slot 49
    void setDeleteComplete(bool f);
public:
    cBakeModelEx* mpBakeModel;  // offset: 0xe68
    bool mIsPause;  // offset: 0xe70
    bool mIsDeleteComplete;  // offset: 0xe71
    bool mBakeRebuildComplete;  // offset: 0xe72
    static MyDTI DTI;
};
