#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtCapsule;
class MtDTI;
class MtMatrix;
class MtOBB;
class MtPropertyList;
class MtSphere;
class cAttackParam;
class cCollIndex;
class cCollNode;
class cpObjCollisionBase;
class cpPawnThink;
class rAttackParam;
class rCollNode;
class uDDOModel;

// Declarations
class cHitNode;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHitNode : public MtObject
{
    // inferred: cpObjCollisionBase::killNode names cHitNode::mKillReq
    friend class cpObjCollisionBase;
    // inferred: cpPawnThink::setModeOff names cHitNode::mKillReq
    friend class cpPawnThink;
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
    cHitNode();
    virtual ~cHitNode();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    rCollNode* getCollNodeRes() const;
    rAttackParam* getAttackParamRes() const;
    const cCollNode* getCollNode() const;
    const cAttackParam* getAttackParam() const;
    cAttackParam* getAttackParamFromAttackNo(u32 no) const;
    const cCollIndex* getCollIndex() const;
    void setSCollisionNodeAttr(u32 attr);
    void setAttackParam(const cAttackParam* pAttackParam);
    void setAttackParamFromAttackNo(u32 no);
    void setAttackParamRes(rAttackParam* mpr);
    bool isMotionSync() const;
    void setMotionSync(bool);
    cpObjCollisionBase* getObjCollision() const;
    u32 getGeomNum();
    const MtSphere* getSphere(u32 index) const;
    void setSphere(u32 index, const MtSphere& sphere);
    const MtCapsule* getCapsule(u32 index) const;
    void setCapsule(u32 index, const MtCapsule& capsule);
    const MtOBB* getOBB(u32 index) const;
    void setOBB(u32 index, const MtOBB& obb);
    void updateNode();
    u32 getUID() const;
    void kill();
    bool isNodeActive() const;
    void setNodeActive(bool active);
    void resetHitNode();
    u32 getOwnerUnique() const;
    uDDOModel* getOwnerUnit() const;
public:
    MtMatrix mWmat;  // offset: 0x10
    MtArray mGeomArray;  // offset: 0x50
protected:
    u32 mUID;  // offset: 0x70
    cpObjCollisionBase* mpObjCollision;  // offset: 0x78
    sCollision::Node* mpNode;  // offset: 0x80
    rCollNode* mpCollNodeRes;  // offset: 0x88
    rAttackParam* mpAttackParamRes;  // offset: 0x90
    cCollIndex* mpCollIndex;  // offset: 0x98
    cCollNode* mpCollNode;  // offset: 0xa0
    cAttackParam* mpAttackParam;  // offset: 0xa8
    cAttackParam* mpOrgAttackParam;  // offset: 0xb0
    s32 mSeqNo;  // offset: 0xb8
    bool mMotionSync;  // offset: 0xbc
    bool mKillReq;  // offset: 0xbd
    bool mIsActive;  // offset: 0xbe
public:
    static MyDTI DTI;
    static const u32 INVALID_OWNER_ID = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
inline const cCollNode* cHitNode::getCollNode() const {
    return this->mpCollNode;
}

// Inline, no code of its own: checked where it is inlined.
inline const cAttackParam* cHitNode::getAttackParam() const {
    return this->mpAttackParam;
}
