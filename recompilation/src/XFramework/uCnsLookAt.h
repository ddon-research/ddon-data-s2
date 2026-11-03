#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "uConstraint.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cResource;
class rCnsLookAt;
class uModel;

// Declarations
class uCnsLookAt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsLookAt : public uConstraint
{
public:
    enum TYPE
    {
        T_UP = 15,
        T_DIR = 240,
        T_UP_IDX = 3840,
        T_UP_X = 1,
        T_UP_Y = 2,
        T_UP_Z = 4,
        T_UP_N = 8,
        T_DIR_X = 16,
        T_DIR_Y = 32,
        T_DIR_Z = 64,
        T_DIR_N = 128,
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
    uCnsLookAt();
    virtual ~uCnsLookAt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void adjust(uModel::Joint* pJnt, uModel* pModel);  // vtable slot 29
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    virtual void remove();  // vtable slot 31
    virtual void update();  // vtable slot 30
    virtual u32 getDependentJointNum();  // vtable slot 26
    virtual uModel::Joint* getDependentJoint(u32 Idx);  // vtable slot 27
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num);  // vtable slot 37
    void set(uModel* pModel, rCnsLookAt* pRes, uModel* pTargetModel);
    void setCnsLookAtRes(rCnsLookAt* pRes);
    rCnsLookAt* getCnsLookAtRes();
    bool setJoint(u32 JntNo);
    u32 getJoint();
    void setTargetPos(const MtVector3& pos);
    const MtVector3& getTaretPos();
    MtVector3 getTargetWPos();
    void setTargetWPos(const MtVector3& pos);
    void setTargetModel(uModel* pModel);
    uModel* getTargetModel();
    void setTargetJoint(u32 JntNo);
    u32 getTargetJoint();
    void setDirection(u32 dir);
    u32 getDirection();
    void setUpvector(u32 up);
    u32 getUpvector();
protected:
    void setDir(u32 dir);
    void setUp(u32 up);
    void setJointForProperty(u32 JntNo);
protected:
    uModel* mpTargetModel;  // offset: 0x98
    MtVector3 mTargetPos;  // offset: 0xa0
    MtVector3 mTargetWPos;  // offset: 0xb0
    rCnsLookAt* mpCnsLookAtRes;  // offset: 0xc0
    u32 mDir : 8;  // offset: 0xc8
    u32 mUp : 8;  // offset: 0xc8
    u32 mJoint : 8;  // offset: 0xc8
    u32 mTargetJointNo : 8;  // offset: 0xc8
    u32 mType;  // offset: 0xcc
public:
    static MyDTI DTI;
};

inline void* uCnsLookAt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uCnsLookAt::getJoint() {
    return this->mJoint;
}

inline u32 uCnsLookAt::getTargetJoint() {
    return this->mTargetJointNo;
}

inline u32 uCnsLookAt::getDirection() {
    return this->mDir;
}

inline u32 uCnsLookAt::getUpvector() {
    return this->mUp;
}
