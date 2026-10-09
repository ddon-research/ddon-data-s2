#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class rDeformWeightMap;
class rSoundPhysicsSoftBody;
class uDDOModel;
class uEnemy;
class uModel;
class uSimSoftBody;

// Declarations
class cpSoftBody;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;

class cpSoftBody : public cpComponent
{
    // inferred: uEnemy::callbackMoveFreeze_Off names cpSoftBody::mIsStop
    friend class uEnemy;
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
    cpSoftBody();
    virtual ~cpSoftBody();
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void update();
    void release();
    bool setSoftBody(uModel* pOwner, ARC_TAGID ArcTagId, s32 SearchId, u32 Mode);
    bool setSoftBody(uModel* pOwner, MT_CTSTR Path, u32 Mode);
    bool setSoftBody(uModel* pOwner, rDeformWeightMap* pDWM, u32 Mode);
    bool isSoftBodyDraw();
    void draw(cDraw* pDraw);
    void setSoundPhysicsSoftBody(uModel* pOwner, MT_CTSTR Path);
    rDeformWeightMap* getSoftBodyResource();
protected:
    void setSimSoftBody(uSimSoftBody* pUnit);
    void setSoftBodyResource(rDeformWeightMap* pRes);
public:
    virtual void setActive(bool isFlag);  // vtable slot 13
    bool isActive();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    uModel* getOwnerModel();
    bool isUsageSoftBody();
    uSimSoftBody* getSimSoftBody();
    void setColliderType(u32);
    void setScrCollision(bool);
    void setObjCollision(bool);
    void setResetRestart(bool);
    void setNCollision(bool);
    void setImageSpaceCollision(bool);
    void setGrassWind(bool isFlag);
    void restartSimulation(u32 LoopNum);
    void setWorldCoeffTrans(f32);
    f32 getWorldCoeffTrans();
    void setWorldCoeffRot(f32);
    f32 getWorldCoeffRot();
    void setSimCulling(bool isSimCulling);
    bool isSimCulling(bool);
    void setBaseJointNo(s32);
    s32 getBaseJonitNo();
    void setPause(bool isPause);
    void setApproxScrCollision(bool);
    void setUse8Weight(bool);
    bool isUse8Weight();
    void setSameFrameFirstUpdateLimit(bool);
    bool isSameFrameFirstUpdateLimit();
protected:
    uSimSoftBody* mpSimSoftBody;  // offset: 0x50
    uModel* mpOwnerModel;  // offset: 0x58
    uDDOModel* mpOwnerDDOModel;  // offset: 0x60
    rDeformWeightMap* mprDeformWeightMap;  // offset: 0x68
    rSoundPhysicsSoftBody* mprSoundPhysicsSoftBody;  // offset: 0x70
    u32 mCollisionGroup;  // offset: 0x78
    u32 mMaxIterate;  // offset: 0x7c
    u32 mColliderType;  // offset: 0x80
    f32 mNCGlobalWeight;  // offset: 0x84
    f32 mWorldCoeffTrans;  // offset: 0x88
    f32 mWorldCoeffRot;  // offset: 0x8c
    s32 mBaseJointNo;  // offset: 0x90
    bool mIsUpdateFrame;  // offset: 0x94
    bool mIsScrCollision;  // offset: 0x95
    bool mIsResetRestart;  // offset: 0x96
    bool mIsGrassWind;  // offset: 0x97
    bool mIsNCollision;  // offset: 0x98
    bool mIsObjCollision;  // offset: 0x99
    bool mIsISCollision;  // offset: 0x9a
    bool mIsApproxScrCollision;  // offset: 0x9b
    bool mIsSimCulling;  // offset: 0x9c
    bool mIsUse8Weight;  // offset: 0x9d
    bool mIsActive;  // offset: 0x9e
    bool mIsCreateSoftBodyResource;  // offset: 0x9f
    bool mIsCreateCollisionResource;  // offset: 0xa0
    bool mIsStop;  // offset: 0xa1
    bool mIsStopOld;  // offset: 0xa2
    bool mIsCollisionActive;  // offset: 0xa3
    bool mIsCollisionDisp;  // offset: 0xa4
    bool mIsResetRestartSave;  // offset: 0xa5
    bool mIsFirstUpdate;  // offset: 0xa6
    bool mIsSameFrameFirstUpdateLimit;  // offset: 0xa7
public:
    static MyDTI DTI;
};
