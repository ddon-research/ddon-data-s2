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
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cResource;
class rCnsMatrix;
class uModel;

// Declarations
class uCnsMatrix;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsMatrix : public uConstraint
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
    uCnsMatrix();
    virtual ~uCnsMatrix();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    virtual void adjust(uModel::Joint* pJnt, uModel* pModel);  // vtable slot 29
    virtual void remove();  // vtable slot 31
    virtual void update();  // vtable slot 30
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num);  // vtable slot 37
    void set(uModel* pModel, u32 JntNo, u32 Pri);
    void set(uModel* pModel, rCnsMatrix* pRes);
    bool setJoint(u32 JntNo);
    u32 getJoint();
    void setMatrix(MtMatrix& Mat);
    MtMatrix getMatrix();
protected:
    void setJointForProperty(u32 JntNo);
public:
    bool mPos;  // offset: 0x92
    bool mRot;  // offset: 0x93
protected:
    rCnsMatrix* mpCnsMatrixRes;  // offset: 0x98
    s32 mJoint;  // offset: 0xa0
    MtMatrix mMat;  // offset: 0xb0
public:
    static MyDTI DTI;
};

inline void* uCnsMatrix::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uCnsMatrix::getJoint() {
    return static_cast<u32>(this->mJoint);
}
