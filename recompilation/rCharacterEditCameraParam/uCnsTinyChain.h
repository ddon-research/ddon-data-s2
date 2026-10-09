#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtGeomCapsule.h"
#include "../shared/MtGeomSphere.h"
#include "../shared/MtMath.h"
#include "../shared/sCollision.h"
#include "uCnsGroup.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
struct MtContact;
class MtDTI;
class MtGeomCapsule;
class MtGeomSphere;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cResource;
namespace nChain { struct ColInfo; }
class rChainCol;
class rCnsTinyChain;
class uModel;

// Declarations
class uCnsTinyChain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class uCnsTinyChain : public uCnsGroup
{
public:
    enum SHAPE
    {
        SHAPE_NONE = 0,
        SHAPE_SPHERE = 1,
        SHAPE_CAPSULE = 2,
        SHAPE_OBB = 3,
    };
    enum ATTR
    {
        ATTR_DEFAULT = 0,
        ATTR_CALC_MASK = 65535,
        ATTR_SOLVER_MVAR = 1,
        ATTR_FREEZE = 2,
        ATTR_SCROLL_TRANS = 4,
        ATTR_SCROLL_ROT = 8,
        ATTR_SOLVE_ALLFRAME = 16,
        ATTR_VIRTUAL_GROUND = 32,
        ATTR_SCENE_WIND = 64,
        ATTR_USE_WORLDMAT = 128,
        ATTR_UPPARAM_AT_DISABLE = 256,
        ATTR_ENABLE_TIMESCALE = 512,
        ATTR_SCALE_EX = 1024,
        ATTR_ROT_EX = 2048,
        ATTR_JOINT_SCALE = 4096,
        ATTR_DISABLE_MASK = 16711680,
        ATTR_COLLISION_DISABLE = 65536,
        ATTR_COLLIDER_DISABLE = 131072,
        ATTR_ANGLELIMIT_DISABLE = 262144,
        ATTR_FRICTION_DISABLE = 524288,
        ATTR_REFLECTION_DISABLE = 1048576,
        ATTR_STRETCH_DISABLE = 2097152,
        ATTR_TRANS_INTER_DISABLE = 4194304,
        ATTR_CHAIN_DISABLE = 8388608,
        ATTR_SYSTEM_MASK = -268435456,
        ATTR_ADJUST_AFTER = 268435456,
    };
    enum HIT
    {
        HIT_SELF = 1,
        HIT_OBJECT = 2,
        HIT_SCROLL = 4,
        HIT_ANGLE = 8,
        HIT_SCROLL_SP = 16,
        HIT_COLLIDER = 32,
    };
public:
    class MyDTI;
    class cChainGroup;
    class cChainNode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cChainGroup : public uCnsGroup::cGroup
    {
    public:
        enum ATTR
        {
            ATTR_DEFAULT = 0,
            ATTR_COLLISION_MASK = 255,
            ATTR_COLLISION_SELF = 1,
            ATTR_COLLISION_CHAIN = 2,
            ATTR_COLLISION_MODEL = 4,
            ATTR_COLLISION_SCROLL = 8,
            ATTR_COLLISION_COLLIDER = 16,
            ATTR_ENTRY_COLLIDER = 32,
            ATTR_SCROLL_TRAVERSE = 64,
            ATTR_FORCE_MASK = 16776960,
            ATTR_ANGLE_LIMIT = 256,
            ATTR_FORCE_SPRING = 512,
            ATTR_NO_ELASTIC = 1024,
            ATTR_NO_FORCE = 2048,
            ATTR_SIMPLEX = 4096,
            ATTR_FORCE_LIMIT = 8192,
            ATTR_SYMMETRY = 16384,
            ATTR_REACT = 32768,
            ATTR_FORCE_SPRING2 = 65536,
            ATTR_STRETCH_REVERSE = 131072,
            ATTR_SHRIVEL = 262144,
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
        cChainGroup(uCnsTinyChain* pCnsChain, u32 idx);
        virtual ~cChainGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void applyWorldOffset(const MtVector3& offset);
        uModel* getModel();
        virtual void init();  // vtable slot 12
        virtual void reset();  // vtable slot 13
        virtual u32 getDependentJointNum(u32 idx);  // vtable slot 10
        virtual void adjust(u32 idx, uModel::Joint* pJnt, uModel* pMod);  // vtable slot 9
        void calcOffset();
        void updateNode();
        void updateRotate();
        void resetParam();
    protected:
        virtual uCnsGroup::cNode* createNode(u32 idx);  // vtable slot 14
        virtual void resetNodeRef();  // vtable slot 15
        f32 getStepTime();
        f32 getBaseStepTime();
        void accumulateForce();
        void solveFriction(const MtVector3& pos, MtVector3& old, const MtVector3& v);
        void solveReflect(const MtVector3& pos, MtVector3& old, const MtVector3& v);
        void solveStretch();
        void solveAngleLimit();
        void solveAngleLimit2();
        void solveChainCollision(uCnsTinyChain::cChainGroup* pColList);
        void subChainColSphere(uCnsTinyChain::cChainNode& node, uCnsTinyChain::cChainNode* * ppChainNodes, u32 startIdx, u32 num);
        void subChainColCapsule(uCnsTinyChain::cChainNode& node, uCnsTinyChain::cChainNode& nodeNext, uCnsTinyChain::cChainNode* * ppChainNodes, u32 startIdx, u32 num);
        void solveSelfCollision();
        void solveModelCollision();
        void modelColSphere(u32 idx);
        void modelColCapsule(u32 idx);
        void solveScrollCollision();
        void solveColliderCollision();
        void dragSphere(uCnsTinyChain::cChainNode& node, const MtVector3& drag);
        void dragSphereEx(uCnsTinyChain::cChainNode& node, const MtVector3& drag);
        void dragCapsule(uCnsTinyChain::cChainNode& node0, uCnsTinyChain::cChainNode& node1, f32 rsq, const MtVector3& drag, const MtVector3* pContactPos);
        void dragCapsuleEx(uCnsTinyChain::cChainNode& node0, uCnsTinyChain::cChainNode& node1, f32 rsq, const MtVector3& drag, const MtVector3* pContactPos);
        void updateColliderNode();
    public:
        u32 getAttr();
        void setAttr(u32);
        u32 getAttrForce();
        void setAttrForce(u32 attr);
        u32 getAttrCollision();
        void setAttrCollision(u32 attr);
        uCnsTinyChain::cChainNode* getChainNode(u32);
        sCollision::Node* getColNode();
        void addForce(const MtVector3&, const u32);
        f32 getChainLength();
        bool isScale();
        bool isNScale();
        bool isScaleEx();
        bool isJointScale();
        f32 getScale();
    public:
        u32 mAttr;  // offset: 0x2c
        u32 mColAttribute;  // offset: 0x30
        u32 mColGroup;  // offset: 0x34
        u32 mColType;  // offset: 0x38
        MtVector3 mGravity;  // offset: 0x40
        f32 mDamping;  // offset: 0x50
        f32 mTransForceCoef;  // offset: 0x54
        f32 mSpringCoef;  // offset: 0x58
        f32 mWindCoef;  // offset: 0x5c
        f32 mFrictionCoef;  // offset: 0x60
        f32 mReflectCoef;  // offset: 0x64
        f32 mLimitForce;  // offset: 0x68
    private:
        uCnsTinyChain* mpCnsChain;  // offset: 0x70
        uCnsTinyChain::cChainNode* * mppChainNodes;  // offset: 0x78
    protected:
        MtVector4 mOffset;  // offset: 0x80
        MtMatrix mRootMat;  // offset: 0x90
        f32 mLength;  // offset: 0xd0
        sCollision::Node mColNode;  // offset: 0xe0
        bool mResetColliderNode;  // offset: 0x1c0
        bool mUseScale;  // offset: 0x1c1
    public:
        static MyDTI DTI;
    };
public:
    class cChainNode : public uCnsGroup::cNode
    {
    public:
        enum LIMIT_MODE
        {
            LIMIT_MODE_NONE = 0,
            LIMIT_MODE_3D = 1,
            LIMIT_MODE_2D = 2,
        };
        enum ATTACH
        {
            ATTACH_NONE = 0,
            ATTACH_CONST = 1,
            ATTACH_TARGET = 2,
            ATTACH_REFJOINT = 3,
        };
        enum CALC
        {
            CALC_MATRIX = 1,
            CALC_MPOS = 2,
        };
        enum ROT_MODE
        {
            ROT_CHILD = 0,
            ROT_ORIGIN = 1,
        };
        enum ATTR
        {
            ATTR_SPRING_DISABLE = 1,
            ATTR_ANGLELIMIT_DISABLE = 2,
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
        cChainNode(uCnsTinyChain::cChainGroup* pChainGroup, u32 idx);
        virtual ~cChainNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
        void setAttr(u32 attr);
        u32 getAttr() const;
        void setMatrix(const MtMatrix&);
        const MtMatrix& getMatirx() const;
        void setTargetPos(const MtVector3&);
        MtVector3 getTargetPos() const;
        void setOldPos(const MtVector3&);
        const MtVector3& getOldPos() const;
        void setAttach(u32 attach);
        u32 getAttach() const;
        void setRotMode(u32 mode);
        u32 getRotMode() const;
        void setRefJointNo(u32 no);
        u32 getRefJointNo() const;
        void setLen(f32 len);
        f32 getLen() const;
        void setElasticCoef(f32);
        f32 getElasticCoef() const;
        void setMass(f32);
        f32 getMass() const;
        void setWindCoef(f32);
        f32 getWindCoef() const;
        void setAngleMode(u32 mode);
        u32 getAngleMode() const;
        void setAxis(const MtMatrix&);
        MtMatrix getAxis() const;
        void setAxisZXY(const MtVector3&);
        MtVector3 getAxisZXY();
        void setAngleLimit(f32 lim);
        f32 getAngleLimit() const;
        void setAngleLimitRad(f32 lim);
        f32 getAngleLimitRad() const;
        bool isEnableAngleLimit();
        void setR(f32);
        f32 getR() const;
        void setShapeObject(u32 shape);
        u32 getShapeObject() const;
        void setShapeScroll(u32 shape);
        u32 getShapeScroll() const;
        u32 getHit() const;
        void addForce(const MtVector3&);
    protected:
        void addHitFlg(u32 flg);
        void resetHitFlg();
    public:
        u32 mResReserved : 8;  // offset: 0xc
        u32 mAttr : 8;  // offset: 0xc
        u32 mAttach : 8;  // offset: 0xc
        u32 mRotMode : 8;  // offset: 0xc
        u32 mAngleMode : 8;  // offset: 0x10
        u32 mRefJntNo : 8;  // offset: 0x10
        u32 mShapeObject : 8;  // offset: 0x10
        u32 mShapeScroll : 8;  // offset: 0x10
        f32 mR;  // offset: 0x14
        f32 mAngleLimit;  // offset: 0x18
        MtMatrix mAngleAxis;  // offset: 0x20
        f32 mMass;  // offset: 0x60
        f32 mElasticCoef;  // offset: 0x64
        f32 mWindCoef;  // offset: 0x68
    protected:
        uCnsTinyChain::cChainGroup* mpChainGroup;  // offset: 0x70
        MtMatrix mMat;  // offset: 0x80
        MtVector3 mOld;  // offset: 0xc0
        MtVector3 mCollAdjust;  // offset: 0xd0
        MtGeomCapsule mGeomCapsule;  // offset: 0xe0
        MtGeomSphere mGeomSphere;  // offset: 0x120
        MtVector3 mPrevPos;  // offset: 0x140
        MtQuaternion mQuat;  // offset: 0x150
        MtVector3 mMotPos;  // offset: 0x160
        MtVector3 mDir;  // offset: 0x170
        f32 mLen;  // offset: 0x180
        f32 mCLen;  // offset: 0x184
        f32 mLimitD;  // offset: 0x188
        f32 mLimitR;  // offset: 0x18c
        u32 mCalc;  // offset: 0x190
        u32 mHit;  // offset: 0x194
        MtVector3 mJointScale;  // offset: 0x1a0
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
    uCnsTinyChain();
    virtual ~uCnsTinyChain();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& abusolute_offset);  // vtable slot 15
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    void setCnsTinyChainRes(rCnsTinyChain* pRes);
    rCnsTinyChain* getCnsTinyChainRes();
    // Address: 0x01b68370 - 0x01b68371 (1 bytes)
    virtual void adjust(uModel::Joint* pjnt, uModel* pmod) {}  // vtable slot 29
    virtual u32 getDependentJointNum();  // vtable slot 26
    virtual uModel::Joint* getDependentJoint(u32 idx);  // vtable slot 27
    virtual bool preupdate();  // vtable slot 40
    virtual void reset();  // vtable slot 39
    void adjustChain(uModel::Joint* pjnt, uModel* pmod);
    bool isAdjustCalculate();
    void setTinyChain(uModel*, rCnsTinyChain*);
    void setTinyChainModelCollision(uModel*, rChainCol*);
    void setStabilizeNum(s32 num);
    void warp(const MtMatrix& before, const MtMatrix& after);
    void warpChain();
    void restart();
    sCollision::Param* getCollisionSbcParam();
    void chainMove();
    virtual void setConstraintEnable(bool flg);  // vtable slot 25
    void resetChainParam();
    cChainGroup* getChainGroup(u32 idx);
    void setModelColRes(rChainCol* pres);
    rChainCol* getModelColRes();
    void setModelCol(uModel* pModel);
    uModel* getModelCol();
    void setAttr(u32);
    u32 getAttr() const;
    void setGravityScaling(f32);
    f32 getGravityScaling();
    void setGlobalTransForceCoef(f32);
    f32 getGlobalTransForceCoef() const;
    void setGlobalDamping(f32);
    f32 getGlobalDamping() const;
    void setSpringScaling(f32);
    f32 getSpringScaling() const;
    void setReflectScaling(f32);
    f32 getReflectScaling() const;
    void setTimeScale(f32);
    f32 getTimeScale() const;
    bool isScale() const;
    bool isNScale() const;
    f32 getScale() const;
    void setGroundLevel(f32);
    f32 getGroundLevel();
    void setTransParent(uModel* parent_model_ptr);
    uModel* getTransParent();
protected:
    virtual uCnsGroup::cGroup* createGroup(u32 idx);  // vtable slot 41
    virtual void resetGroupRef();  // vtable slot 42
    bool checkStore(f32& store, f32 cost);
    void calcCost();
    f32 _calcCost(u32 solveNum);
public:
    u32 getModelColNum() const;
protected:
    const nChain::ColInfo* getModelColData(u32 idx);
    const MtSphere getSphere(const nChain::ColInfo& data);
    const MtCapsule getCapsule(const nChain::ColInfo& data);
    const MtOBB getOBB(const nChain::ColInfo& data);
public:
    virtual void registCollider();  // vtable slot 45
    virtual void callBackObjectCollision(sCollision::CALLBACK_MODE Mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, uintptr Param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited);  // vtable slot 46
public:
    u32 mAttr;  // offset: 0xac
    f32 mStepTime;  // offset: 0xb0
    f32 mGravityScaling;  // offset: 0xb4
    f32 mGlobalTransForceCoef;  // offset: 0xb8
    f32 mGlobalDamping;  // offset: 0xbc
    f32 mSpringScaling;  // offset: 0xc0
    f32 mWindScaling;  // offset: 0xc4
    f32 mReflectScaling;  // offset: 0xc8
    u8 mSolveStrNum;  // offset: 0xcc
    u8 mSolveAngNum;  // offset: 0xcd
    u8 mSolveMdlColNum;  // offset: 0xce
    u8 mSolveSelColNum;  // offset: 0xcf
    u8 mSolveScrColNum;  // offset: 0xd0
    u8 mSolveChnColNum;  // offset: 0xd1
    u8 mReserved[2];  // offset: 0xd2
private:
    rCnsTinyChain* mpResource;  // offset: 0xd8
    cChainGroup* * mppChainGroups;  // offset: 0xe0
public:
    u32 mStabilizeNum;  // offset: 0xe8
    rChainCol* mpModelColRes;  // offset: 0xf0
    uModel* mpModelCol;  // offset: 0xf8
    f32 mModelColScale;  // offset: 0x100
    uModel* mpTransParent;  // offset: 0x108
    MtMatrix mTransParentMat;  // offset: 0x110
    MtMatrix mTransParentMatOld;  // offset: 0x150
    f32 mTransParentBlend;  // offset: 0x190
    sCollision::Param mSbcParam;  // offset: 0x1a0
    f32 mGroundLevel;  // offset: 0x2c0
    f32 mTimeScale;  // offset: 0x2c4
    f32 mTimeScaleOld;  // offset: 0x2c8
    f32 mTimeCoef;  // offset: 0x2cc
    MtVector3 mLocalWind;  // offset: 0x2d0
    MtVector3 mWindAmp[5];  // offset: 0x2e0
    u32 mWindCycle[5];  // offset: 0x330
    u32 mWindNum;  // offset: 0x344
    u32 mCalcCounter;  // offset: 0x348
protected:
    f32 mActTime;  // offset: 0x34c
    f32 mCalcStepTime;  // offset: 0x350
    f32 mCalcStepTimeOld;  // offset: 0x354
    u32 mSolveMaxNum;  // offset: 0x358
    f32 mCostStr;  // offset: 0x35c
    f32 mCostAng;  // offset: 0x360
    f32 mCostObj;  // offset: 0x364
    f32 mCostSel;  // offset: 0x368
    f32 mCostScr;  // offset: 0x36c
    f32 mCostChn;  // offset: 0x370
    u32 mDependJointNum;  // offset: 0x374
    u8* mpDependJoints;  // offset: 0x378
    f32 mScale;  // offset: 0x380
    MtMatrix mPrevModelNullMat;  // offset: 0x390
    u8 mRestart;  // offset: 0x3d0
    bool mAfterEnable;  // offset: 0x3d1
    bool mPrevEnable;  // offset: 0x3d2
    bool mIsScale;  // offset: 0x3d3
    bool mIsNScale;  // offset: 0x3d4
    bool mWarpFlag;  // offset: 0x3d5
public:
    static MyDTI DTI;
    static const f32 DefaultStepTime;
    static const f32 DeltaTimeMax;
    static const u32 MaxWindNum = 5;
};
