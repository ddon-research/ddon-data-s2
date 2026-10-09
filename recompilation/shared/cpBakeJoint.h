#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cpComponent.h"
#include "sBakingJointOrder.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtVector4;
class cDraw;
class cUnit;
class rBakeJoint;
class uModel;

// Declarations
class cpBakeJoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpBakeJoint : public cpComponent
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
    bool getJointBakeFlag(u32 index);
    void setJointBakeFlag(bool flag, u32 index);
    u32 getBakeJointNum();
    u32 getSkinJointNum() const;
    void setSkinJointNum(u32 num);
    virtual void setBakeMotion(uModel*) = 0;  // vtable slot 15
    u8 getOrgJointIndex(u32 skin_index) const;
    u8 getOldOrgJointIndex(u32) const;
    u8 getSkinJointIndex(u32 index) const;
    u8 getBakeJointIndex(u32 index);
    u32 getBakeJointSkinIndex(u32 index);
    u8* getBakeJoint();
    u8* getSkinJoint();
    void writeBakedQuantPosAndOffset(f32& scale, MtVector4& offset);
    MtMatrix* getInverseMatrix();
    virtual bool setRenewalEnvelope();  // vtable slot 16
    virtual bool setOriginalEnvelope();  // vtable slot 17
    cUnit* getOwnerUnit();
    void setResource(rBakeJoint* pRes);
    rBakeJoint* getResource();
    bool chkJointForEditDelete(u32 jntNo);
    bool buildJointIndexTable();
    u32 getCERefJntNo(u32 SrcJntNo);
    cpBakeJoint();
    virtual ~cpBakeJoint();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void upadatePtr();  // vtable slot 18
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setupComponentPtr();  // vtable slot 12
    void bake();
    void drawBake(cDraw* pdraw);
    bool isBaked();
    void requestBake();
    void releaseBake();
    bool isReleaseBakeRequest();
protected:
    virtual bool initBake();  // vtable slot 19
public:
    u32 mSkinJointNum;  // offset: 0x50
    alignas(16) u8 mSkinToOrg[256];  // offset: 0x60
    u8 mOrgToSkin[256];  // offset: 0x160
    u8 mToParent[256];  // offset: 0x260
    u8 mOldSkinToOrg[256];  // offset: 0x360
    MtAABB mAABB;  // offset: 0x460
    MtMatrix* mpImat;  // offset: 0x480
    MtMatrix mImat[256];  // offset: 0x490
    f32 mQuantPosScale;  // offset: 0x4490
    MtVector4 mQuantPosOffset;  // offset: 0x44a0
    rBakeJoint* mpResource;  // offset: 0x44b0
    bool mIsBaked;  // offset: 0x44b8
    sBakingJointOrder::BAKE_HANDLE mHandle;  // offset: 0x44bc
protected:
    uModel* mpModel;  // offset: 0x44c0
    bool mBakeReq;  // offset: 0x44c8
    bool mBakeReleaseReq;  // offset: 0x44c9
    bool mIsDDOModel;  // offset: 0x44ca
public:
    static MyDTI DTI;
};
