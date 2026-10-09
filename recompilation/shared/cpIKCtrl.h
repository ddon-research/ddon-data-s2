#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class rCnsIK;
class rFullbodyIKHuman2;
class rIKCtrl;
class uCnsDDOIK;
class uCnsIKHandle;
class uCnsIKTarget;
class uFullbodyIKHumanDDO;
class uModel;

// Declarations
class cIKHandle;
class cpIKCtrl;

namespace nIKCtrl {
    enum EFF_BEHAVIOR
    {
        EB_ROT_MOTION = 0,
        EB_ROT_EFFECTOR = 1,
    };
}  // namespace nIKCtrl

namespace nIKCtrl {
    enum IK_TYPE
    {
        R_ARM = 0,
        L_ARM = 1,
        R_LEG = 2,
        L_LEG = 3,
        CNS_IK_NUM = 4,
        CENTER = 4,
        IK_TYPE_NUM = 5,
    };
}  // namespace nIKCtrl

namespace nIKCtrl {
    enum MODEL_TYPE
    {
        TWO_LEG = 0,
        FOUR_LEG = 1,
    };
}  // namespace nIKCtrl

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cIKHandle : public MtObject
{
    // inferred: cpIKCtrl::checkResetIKHandle names cpIKCtrl::mIKHandle[0].mType
    friend class cpIKCtrl;
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
    cIKHandle();
    virtual ~cIKHandle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setIKActive(bool active);
    bool isIKActive();
    nIKCtrl::IK_TYPE getType();
    void setEffector(const MtMatrix& mat);
    void setEffector(const MtQuaternion& quat, const MtVector3& pos);
    MtMatrix& getEffector();
    void setOffset(const MtVector3& offset);
    MtVector3 getOffset();
    void setIKTarget(uModel* pModel, u32 JntNo, u32 Pri);
    uModel* getTargetModel();
    void setTargetJointDef(u32 JntNo);
    void setTargetJoint(u32 JntNo, u32 Pri);
    u32 getTargetJoint();
    void setEffectorJoint(u32);
    u32 getEffectorJoint();
    void setBehavior(nIKCtrl::EFF_BEHAVIOR behavior);
    u32 getBehavior();
    void setCnsIKBlend(f32 blend, f32 blendSpeed);
    void setCnsIKBlendWeight(f32 blend);
    void resetToFinalBlend();
    f32 getCnsIKBlend() const;
    f32 getCnsIKBlendWight() const;
    uCnsDDOIK* getCnsIK();
    uCnsIKTarget* getCnsIKTarget();
    void updatePtr();
protected:
    u32 mBehavior;  // offset: 0x8
    bool mActive;  // offset: 0xc
    nIKCtrl::IK_TYPE mType;  // offset: 0x10
    f32 mBlend;  // offset: 0x14
    f32 mBlendSpeed;  // offset: 0x18
    f32 mResist;  // offset: 0x1c
    MtMatrix mEff;  // offset: 0x20
    MtVector3 mOffset;  // offset: 0x60
    uModel* mpTargetModel;  // offset: 0x70
    u32 mTargetJntNo;  // offset: 0x78
    u32 mJntNo;  // offset: 0x7c
    cpIKCtrl* mpIKCtrl;  // offset: 0x80
    uCnsDDOIK* mpCnsIK;  // offset: 0x88
    uCnsIKTarget* mpIKTarget;  // offset: 0x90
public:
    static MyDTI DTI;
};

class cpIKCtrl : public cpComponent
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
    cpIKCtrl();
    virtual ~cpIKCtrl();
    void init();
    virtual void setActive(bool active);  // vtable slot 13
    bool isActive();
    void setFBIKActive(bool);
    bool isFBIKActive();
    bool isIKCtrlActive();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void after();  // vtable slot 15
    virtual void compMoveAfter();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setCnsIKRes(nIKCtrl::IK_TYPE type, rCnsIK* pRes);
    rCnsIK* getCnsIKRes(nIKCtrl::IK_TYPE type);
    void setFBIKRes(rFullbodyIKHuman2* pRes);
    rFullbodyIKHuman2* getFBIKRes();
    void setResource(rIKCtrl* pRes);
    rIKCtrl* getResource();
    cIKHandle* getIKHandle(nIKCtrl::IK_TYPE type);
    uCnsDDOIK* getCnsIK(nIKCtrl::IK_TYPE);
    void checkResetIKHandle();
    void updateIKHandle();
    void updateChestMatrix(MtMatrix& Result);
    void enableConstraint(bool enable);
    void deleteConstraint();
    void resetToFinalBlend();
    static MtMatrix makeRotMatrix(const MtVector3& v1, const MtVector3& v2, f32 rate);
    static MtVector3 calcUpVectorArm(const MtMatrix& BaseMat, const MtMatrix& BaseMatOrg, const MtMatrix& RootMat, const MtMatrix& RootMatOrg, const MtVector3& EffPos, const MtVector3& EffPosOrg, const MtVector3& InnerUpOffset, const MtVector3& OuterUpOffset, f32 ip_sign);
    static MtVector3 calcUpVectorLeg(const MtMatrix& RootMat, const MtMatrix& RootMatOrg, const MtVector3& EffPos, const MtVector3& EffPosOrg, f32 sign);
protected:
    void updateIKBlend();
    void updateIKBlend(cIKHandle* pIKHandle);
    void updateEffector();
    void updateIKHandle(cIKHandle* pIKHandle);
    void resetIKHandle();
    void createConstraint(bool UseFBIK);
public:
    MtMatrix mChestMat;  // offset: 0x50
protected:
    bool mFBIKActive;  // offset: 0x90
    nIKCtrl::MODEL_TYPE mModelType;  // offset: 0x94
    uModel* mpModel;  // offset: 0x98
    cIKHandle mIKHandle[5];  // offset: 0xa0
    uCnsIKHandle* mpCnsIKHandle[5];  // offset: 0x3c0
    uCnsIKTarget* mpCnsIKTarget[5];  // offset: 0x3e8
    uCnsDDOIK* mpCnsIK[4];  // offset: 0x410
    uFullbodyIKHumanDDO* mpFBIK;  // offset: 0x430
    rIKCtrl* mpResource;  // offset: 0x438
    bool mIsReset;  // offset: 0x440
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpIKCtrl::isIKCtrlActive() {
    return this->::cpComponent::mActive;
}
