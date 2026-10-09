#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cUnit.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class MtVector4;
class cResource;
class uModel;

// Declarations
class uConstraint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uConstraint : public cUnit
{
public:
    enum PRI
    {
        DEFAULT_PRI = 1000,
    };
    enum ADIR
    {
        ADIR_NEGATIVE = 4,
        ADIR_AXIS_MASK = 3,
        ADIR_X = 1,
        ADIR_Y = 2,
        ADIR_Z = 3,
        ADIR_NX = 5,
        ADIR_NY = 6,
        ADIR_NZ = 7,
        __ADIR__U32 = -1,
    };
    enum DIRECTION
    {
        X = 0,
        Y = 1,
        Z = 2,
        NX = 3,
        NY = 4,
        NZ = 5,
    };
public:
    class MyDTI;
    class cConstraint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cConstraint : public uModel::Constraint
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
        virtual void adjust(uModel::Joint* pjnt, uModel* pmod);  // vtable slot 6
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual u32 getDependentJointNum();  // vtable slot 7
        virtual uModel::Joint* getDependentJoint(u32 idx);  // vtable slot 8
        virtual uConstraint* getUConstraint();  // vtable slot 9
        virtual uModel::Constraint* getNextConstraint();  // vtable slot 10
        virtual uModel::Constraint* getPrevConstraint();  // vtable slot 11
    public:
        uConstraint* mpParent;  // offset: 0x8
        static MyDTI DTI;
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
    uConstraint();
    virtual ~uConstraint();
    void initMember();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01ad3450 - 0x01ad3451 (1 bytes)
    virtual void createPropertyMenu(MtPropertyList& s) {}  // vtable slot 24
    void setBlend(f32 Blend, f32 Speed);
    void setBlendWeight(f32 blend);
    f32 getBlend() const;
    f32 getBlendSpeed() const;
    f32 getBlendWeight() const;
    void setIgnoreRate(bool);
    virtual void setConstraintEnable(bool flg);  // vtable slot 25
    bool isConstraintEnable() const;
    void setEnable(bool flg);
    bool getEnable() const;
    virtual u32 getDependentJointNum();  // vtable slot 26
    virtual uModel::Joint* getDependentJoint(u32 idx);  // vtable slot 27
    void calcSRT(uModel::Joint* pJoint, uModel* pModel);
    void calcSRT(uModel::Joint* pJoint, uModel* pModel, const MtMatrix& LMat);
    void calcSRT(uModel::Joint* pJoint, uModel* pModel, const MtQuaternion& q, MtVector3& t, MtVector3& s);
    void calcSRT(MtMatrix& Dst, MtMatrix& LMat, MtMatrix& PMat);
    MtMatrix getBaseLocalMatrix(uModel* pModel, u32 jnt_no);
    MtMatrix getBaseWorldMatrix(uModel* pModel, u32 jnt_no);
    bool setConstraint(uModel::Joint* pJnt);
    bool setConstraint(uModel* pModel, s32 JntNo);
    bool removeConstraint();
    bool removeConstraint(uModel::Joint* dmy);
    bool removeConstraint(uModel* pModel, s32 JntNo);
    void sortByPri();
    virtual void setPri(u32 Pri);  // vtable slot 28
    u32 getPri() const;
    static bool checkJointNo(uModel* pModel, s32 JntNo);
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void adjust(uModel::Joint*, uModel*) = 0;  // vtable slot 29
    virtual void kill();  // vtable slot 16
    // Address: 0x01b67100 - 0x01b67101 (1 bytes)
    virtual void update() {}  // vtable slot 30
    // Address: 0x01b67110 - 0x01b67111 (1 bytes)
    virtual void remove() {}  // vtable slot 31
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource() = 0;  // vtable slot 33
    virtual uModel* getModel();  // vtable slot 34
    virtual void setModel(uModel* pModel);  // vtable slot 35
    virtual void setModelUpdate(uModel* pModel);  // vtable slot 36
    // Address: 0x01ad3810 - 0x01ad3811 (1 bytes)
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num) {}  // vtable slot 37
    // Address: 0x01ad34a0 - 0x01ad34a1 (1 bytes)
    virtual void evSetJoint(MtProperty& prop) {}  // vtable slot 38
    static void setRotateVectorXY(MtMatrix& mtx, const MtVector3& DirX, const MtVector3& UpY, const MtVector4& Pos);
    static void setRotateVectorXZ(MtMatrix& mtx, const MtVector3& DirX, const MtVector3& UpZ, const MtVector4& Pos);
    static void setRotateVectorYX(MtMatrix& mtx, const MtVector3& DirY, const MtVector3& UpX, const MtVector4& Pos);
    static void setRotateVectorYZ(MtMatrix& mtx, const MtVector3& DirY, const MtVector3& UpZ, const MtVector4& Pos);
    static void setRotateVectorZX(MtMatrix& mtx, const MtVector3& DirZ, const MtVector3& UpX, const MtVector4& Pos);
    static void setRotateVectorZY(MtMatrix& mtx, const MtVector3& DirZ, const MtVector3& UpY, const MtVector4& Pos);
    static void setRotateVector(MtMatrix& mtx, const u32 dir, const u32 up, const MtVector3& dirVec, const MtVector3& upVec, const MtVector4& Pos);
public:
    cConstraint mConstraint;  // offset: 0x48
    uConstraint* mpPrevCns;  // offset: 0x58
    uConstraint* mpNextCns;  // offset: 0x60
    uModel::Joint* mpParentJnt;  // offset: 0x68
    f32 mBlendWeight;  // offset: 0x70
    u32 mID;  // offset: 0x74
    s32 mOrder;  // offset: 0x78
    u32 mPri;  // offset: 0x7c
    uModel* mpModel;  // offset: 0x80
    f32 mBlendSpeed;  // offset: 0x88
    f32 mBlend;  // offset: 0x8c
    bool mIgnoreRate;  // offset: 0x90
    bool mEnable;  // offset: 0x91
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 uConstraint::getBlendWeight() const {
    return this->mBlendWeight;
}
