#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "uCnsIK.h"
#include "uCnsLookAt.h"
#include "uCnsMatrix.h"
#include "uConstraint.h"
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
class cDraw;
class cResource;
class rFullbodyIKHuman2;
class uCnsIK;
class uCnsLookAt;
class uCnsMatrix;

// Declarations
class uFullbodyIKHuman2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uFullbodyIKHuman2 : public uModel
{
public:
    enum FBIK_JOINT
    {
        JT_CENTER = 0,
        JT_RIGHT_SHOULDER = 11,
        JT_RIGHT_ELBOW = 12,
        JT_RIGHT_HAND = 13,
        JT_LEFT_SHOULDER = 21,
        JT_LEFT_ELBOW = 22,
        JT_LEFT_HAND = 23,
        JT_RIGHT_THIGH = 30,
        JT_RIGHT_KNEE = 31,
        JT_RIGHT_FOOT = 32,
        JT_LEFT_THIGH = 40,
        JT_LEFT_KNEE = 41,
        JT_LEFT_FOOT = 42,
        JT_HEAD = 51,
        JT_NECK = 50,
        JT_RIGHT_COLLAR = 10,
        JT_LEFT_COLLAR = 20,
        JT_SPINE0 = 60,
        JT_SPINE1 = 61,
        JT_SPINE2 = 62,
        JT_SPINE3 = 63,
        JT_SPINE4 = 64,
        JT_UPPER_BODY = 1,
        JT_LOWER_BODY = 3,
        JT_CHEST = 2,
        JT_LOOK_AT = 70,
        JT_NULL = 255,
    };
    enum FBIK_JOINT_IDX
    {
        IDX_CENTER = 0,
        IDX_RIGHT_SHOULDER = 1,
        IDX_RIGHT_ELBOW = 2,
        IDX_RIGHT_HAND = 3,
        IDX_LEFT_SHOULDER = 4,
        IDX_LEFT_ELBOW = 5,
        IDX_LEFT_HAND = 6,
        IDX_RIGHT_THIGH = 7,
        IDX_RIGHT_KNEE = 8,
        IDX_RIGHT_FOOT = 9,
        IDX_LEFT_THIGH = 10,
        IDX_LEFT_KNEE = 11,
        IDX_LEFT_FOOT = 12,
        IDX_HEAD = 13,
        IDX_NECK = 14,
        IDX_RIGHT_COLLAR = 15,
        IDX_LEFT_COLLAR = 16,
        IDX_SPINE0 = 17,
        IDX_SPINE1 = 18,
        IDX_SPINE2 = 19,
        IDX_SPINE3 = 20,
        IDX_SPINE4 = 21,
        IDX_UPPER_BODY = 22,
        IDX_LOWER_BODY = 23,
        IDX_CHEST = 24,
        IDX_LOOK_AT = 25,
        IDX_NULL = 26,
        IDX_FBIK_JOINT_MAX = 27,
        IDX_FBIK_INVALID = -1,
    };
    enum STATE
    {
        S_RIGHT_HAND_PULLBODY = 1,
        S_LEFT_HAND_PULLBODY = 2,
        S_RIGHT_FOOT_PULLBODY = 4,
        S_LEFT_FOOT_PULLBODY = 8,
        S_WAIST_HEIGHT_LIMIT = 16,
    };
public:
    class MyDTI;
    class Node;
    class uCnsUpVectorCalc;
    class uCnsFBIKMatrix;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Node : public MtObject
    {
        friend class uFullbodyIKHuman2;
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
        Node();
        virtual ~Node() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MtMatrix getOrgMatrix();
        void setBlend(f32);
        f32 getBlend();
        void addBlend(f32);
        void setActive(bool);
        bool isActive();
        void setResist(f32);
        f32 getResist();
        MtVector3 getPos();
        MtVector3 getOrgPos();
    public:
        f32 mBlend;  // offset: 0x8
        MtMatrix mEff;  // offset: 0x10
        MtMatrix mWMat;  // offset: 0x50
        MtMatrix mOrgMat;  // offset: 0x90
        MtVector3 mEffOffset;  // offset: 0xd0
        uModel* mpEffTgtModel;  // offset: 0xe0
        u32 mEffTgtJntNo;  // offset: 0xe8
        f32 mResist;  // offset: 0xec
        bool mActive;  // offset: 0xf0
        bool mRotate;  // offset: 0xf1
        bool mEffTgtAlign;  // offset: 0xf2
    protected:
        bool mAssigned;  // offset: 0xf3
        u32 mJntNo;  // offset: 0xf4
        u32 mFBIKJntNo;  // offset: 0xf8
        uModel* mpModel;  // offset: 0x100
    public:
        static MyDTI DTI;
    };
public:
    class uCnsUpVectorCalc : public uConstraint
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
        uCnsUpVectorCalc();
        virtual ~uCnsUpVectorCalc();
        virtual void draw(cDraw* pDraw);  // vtable slot 12
        virtual void setResource(cResource* pRes);  // vtable slot 32
        virtual cResource* getResource();  // vtable slot 33
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool setJoint(u32 JntNo);
        u32 getJoint();
        void set(uModel* pModel, u32 JntNo, uCnsIK* pCnsIK, u32 IKType, u32 Pri);
        virtual void adjust(uModel::Joint* pJnt, uModel* pModel);  // vtable slot 29
        virtual void remove();  // vtable slot 31
        virtual void update();  // vtable slot 30
    private:
        void setJointForProperty(u32 JntNo);
    protected:
        u32 mJoint;  // offset: 0x94
        uFullbodyIKHuman2* mpFBIKModel;  // offset: 0x98
        uCnsIK* mpCnsIK;  // offset: 0xa0
        u32 mIKType;  // offset: 0xa8
    public:
        static MyDTI DTI;
    };
public:
    class uCnsFBIKMatrix : public uConstraint
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
        uCnsFBIKMatrix();
        virtual ~uCnsFBIKMatrix();
        virtual void draw(cDraw* pDraw);  // vtable slot 12
        virtual void setResource(cResource* pRes);  // vtable slot 32
        virtual cResource* getResource();  // vtable slot 33
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool setJoint(u32 JntNo);
        u32 getJoint();
        void set(uModel* pModel, u32 DstJntNo, uModel* pFBIKModel, u32 SrcJntNo, u32 Pri);
        virtual void adjust(uModel::Joint* pJnt, uModel* pModel);  // vtable slot 29
        virtual void remove();  // vtable slot 31
        virtual void update();  // vtable slot 30
        void setMatrix(MtMatrix&);
        MtMatrix getMatrix();
    private:
        void setJointForProperty(u32 JntNo);
    public:
        bool mPos;  // offset: 0x92
        bool mRot;  // offset: 0x93
    protected:
        u32 mJoint;  // offset: 0x94
        MtMatrix mMat;  // offset: 0xa0
        MtVector3 mScl;  // offset: 0xe0
        uModel* mpFBIKModel;  // offset: 0xf0
        u32 mFBIKJntNo;  // offset: 0xf8
    public:
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
    uFullbodyIKHuman2();
    virtual ~uFullbodyIKHuman2();
    void init(uModel* pModel, rFullbodyIKHuman2* pFBIKRes);
    void assignJoint(u32 jnt_no, FBIK_JOINT fbik_joint);
    void setTargetModel(uModel* pModel);
    uModel* getTargetModel();
    void setResource(rFullbodyIKHuman2* pRes);
    rFullbodyIKHuman2* getResource();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void updateFullbodyIK();
    virtual void updateTargetModel(bool Update);  // vtable slot 43
    static FBIK_JOINT_IDX getFBIKJointIndexFromNo(FBIK_JOINT FBIKJntNo);
    static FBIK_JOINT getFBIKJointNoFromIndex(FBIK_JOINT_IDX FBIKJntIdx);
    Node* getNode(FBIK_JOINT JointNo);
    void setPri(u32 Pri);
    u32 getPri();
    void setUpdateTargetModel(bool);
    bool getUpdateTargetModel();
    MtMatrix getRightHandNullMatrix(bool align_org_rot);
    MtMatrix getLeftHandNullMatrix(bool align_org_rot);
    MtMatrix getRightFootNullMatrix(bool align_org_rot);
    MtMatrix getLeftFootNullMatrix(bool align_org_rot);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void setIteration(u32);
    u32 getIteration();
    void setSpineHandleLength(f32);
    f32 getSpineHandleLength();
    void setUpperBodyRotRate(f32);
    f32 getUpperBodyRotRate();
    void setUpperBodyTransRate(f32);
    f32 getUpperBodyTransRate();
    void setUpperBodySyncRate(f32);
    f32 getUpperBodySyncRate();
    void setLowerBodyRotRate(f32);
    f32 getLowerBodyRotRate();
    void setLowerBodyTransRate(f32);
    f32 getLowerBodyTransRate();
    void setLowerBodySyncRate(f32);
    f32 getLowerBodySyncRate();
    void setHeadLookAtRate(f32);
    f32 getHeadLookAtRate();
    void setUpperBodyLookAtRate(f32);
    f32 getUpperBodyLookAtRate();
    void setLowerBodyLookAtRate(f32);
    f32 getLowerBodyLookAtRate();
    void setWaistHeightLimit(f32);
    f32 getWaistHeightLimit();
    u32 getState();
protected:
    void calcFullbodyIK();
    void prepare();
    void calc();
    void finish();
    Node* getNode(FBIK_JOINT_IDX idx);
    void copyJointMatrix(FBIK_JOINT_IDX fbik_jnt_idx, FBIK_JOINT_IDX fbik_alt_jnt_idx);
    void setEffector(Node* pNode);
    u32 getAssignedJointNum();
    void setAssignedJointNum(u32 n);
    Node* getAssignedJoint(u32 idx);
    void setAssignedJoint(Node* node, u32 idx);
    u32 getEffectorJointNum();
    void setEffectorJointNum(u32 n);
    Node* getEffectorJoint(u32 idx);
    void setEffectorJoint(Node* node, u32 idx);
    static MtMatrix makeRotMatrix(const MtVector3& v1, const MtVector3& v2, f32 rate);
    virtual void recomputeLocalMatrix();  // vtable slot 40
    MtQuaternion makeRotQuat(const MtVector3& start, const MtVector3& end, f32 blend) const;
    MtVector3 calcRotQuat(const MtVector3& end, const MtVector3& start, const MtQuaternion& quat) const;
protected:
    Node mNode[27];  // offset: 0x1f60
    uCnsIK mRArm;  // offset: 0x3c10
    uCnsIK mLArm;  // offset: 0x4b30
    uCnsIK mRLeg;  // offset: 0x5a50
    uCnsIK mLLeg;  // offset: 0x6970
    uCnsUpVectorCalc mRArmUpVectorCalc;  // offset: 0x7890
    uCnsUpVectorCalc mLArmUpVectorCalc;  // offset: 0x7940
    uCnsUpVectorCalc mRLegUpVectorCalc;  // offset: 0x79f0
    uCnsUpVectorCalc mLLegUpVectorCalc;  // offset: 0x7aa0
    uCnsMatrix mChest;  // offset: 0x7b50
    uCnsMatrix mCenter;  // offset: 0x7c40
    uCnsMatrix mUpperBody;  // offset: 0x7d30
    uCnsMatrix mLowerBody;  // offset: 0x7e20
    uCnsMatrix mSpine0;  // offset: 0x7f10
    uCnsMatrix mSpine1;  // offset: 0x8000
    uCnsMatrix mSpine2;  // offset: 0x80f0
    uCnsMatrix mSpine3;  // offset: 0x81e0
    uCnsMatrix mSpine4;  // offset: 0x82d0
    uCnsMatrix mRHand;  // offset: 0x83c0
    uCnsMatrix mLHand;  // offset: 0x84b0
    uCnsMatrix mRFoot;  // offset: 0x85a0
    uCnsMatrix mLFoot;  // offset: 0x8690
    uCnsMatrix mRCollar;  // offset: 0x8780
    uCnsMatrix mLCollar;  // offset: 0x8870
    uCnsLookAt mLookAt;  // offset: 0x8960
    u32 mPri;  // offset: 0x8a30
    u32 mIteration;  // offset: 0x8a34
    f32 mSpineHandleLength;  // offset: 0x8a38
    f32 mUpperBodyRotRate;  // offset: 0x8a3c
    f32 mUpperBodyTransRate;  // offset: 0x8a40
    f32 mUpperBodySyncRate;  // offset: 0x8a44
    f32 mLowerBodyRotRate;  // offset: 0x8a48
    f32 mLowerBodyTransRate;  // offset: 0x8a4c
    f32 mLowerBodySyncRate;  // offset: 0x8a50
    f32 mHeadLookAtRate;  // offset: 0x8a54
    f32 mUpperBodyLookAtRate;  // offset: 0x8a58
    f32 mLowerBodyLookAtRate;  // offset: 0x8a5c
    f32 mWaistHeightLimit;  // offset: 0x8a60
    uModel* mpTargetModel;  // offset: 0x8a68
    rFullbodyIKHuman2* mpResource;  // offset: 0x8a70
    MtMatrix mUpperBodyMat;  // offset: 0x8a80
    MtMatrix mLowerBodyMat;  // offset: 0x8ac0
    MtMatrix mCenterMat;  // offset: 0x8b00
    MtMatrix mNeckOffset;  // offset: 0x8b40
    MtMatrix mChestOffset;  // offset: 0x8b80
    MtMatrix mRCollarOffset;  // offset: 0x8bc0
    MtMatrix mLCollarOffset;  // offset: 0x8c00
    MtMatrix mUpperBodyOffset;  // offset: 0x8c40
    MtMatrix mLowerBodyOffset;  // offset: 0x8c80
    MtMatrix mSpine0Offset;  // offset: 0x8cc0
    MtMatrix mSpine1Offset;  // offset: 0x8d00
    MtMatrix mSpine2Offset;  // offset: 0x8d40
    MtMatrix mSpine3Offset;  // offset: 0x8d80
    MtMatrix mSpine4Offset;  // offset: 0x8dc0
    MtMatrix mRHandNullOffset;  // offset: 0x8e00
    MtMatrix mLHandNullOffset;  // offset: 0x8e40
    MtMatrix mRFootNullOffset;  // offset: 0x8e80
    MtMatrix mLFootNullOffset;  // offset: 0x8ec0
    bool mTrunkDebugDisplay;  // offset: 0x8f00
    f32 mRCollarRotBlend;  // offset: 0x8f04
    f32 mLCollarRotBlend;  // offset: 0x8f08
    f32 mRCollarUpBlend;  // offset: 0x8f0c
    f32 mRCollarDownBlend;  // offset: 0x8f10
    f32 mRCollarFrontBlend;  // offset: 0x8f14
    f32 mRCollarBackBlend;  // offset: 0x8f18
    f32 mLCollarUpBlend;  // offset: 0x8f1c
    f32 mLCollarDownBlend;  // offset: 0x8f20
    f32 mLCollarFrontBlend;  // offset: 0x8f24
    f32 mLCollarBackBlend;  // offset: 0x8f28
    bool mUseSpineRot;  // offset: 0x8f2c
    f32 mSpineUpperRotRate;  // offset: 0x8f30
    f32 mSpine0RotRate;  // offset: 0x8f34
    f32 mSpine1RotRate;  // offset: 0x8f38
    f32 mSpine2RotRate;  // offset: 0x8f3c
    f32 mSpine3RotRate;  // offset: 0x8f40
    f32 mSpine4RotRate;  // offset: 0x8f44
    bool mLookAtWorldCoordRot;  // offset: 0x8f48
    uCnsFBIKMatrix mCnsFBIKMatrix[27];  // offset: 0x8f50
    u32 mState;  // offset: 0xaa50
    bool mUpdateTargetModel;  // offset: 0xaa54
public:
    static MyDTI DTI;
    static const u32 ASSIGN_JOINT_NUM = 24;
};

inline void* uFullbodyIKHuman2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uModel* uFullbodyIKHuman2::getTargetModel() {
    return this->mpTargetModel;
}

inline rFullbodyIKHuman2* uFullbodyIKHuman2::getResource() {
    return this->mpResource;
}

inline void* uFullbodyIKHuman2::Node::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uFullbodyIKHuman2::uCnsUpVectorCalc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uFullbodyIKHuman2::uCnsUpVectorCalc::getJoint() {
    return this->mJoint;
}

inline void* uFullbodyIKHuman2::uCnsFBIKMatrix::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uFullbodyIKHuman2::uCnsFBIKMatrix::getJoint() {
    return this->mJoint;
}
