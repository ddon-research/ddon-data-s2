#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cDelegate.h"
#include "sCollision.h"
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
class cpIKCtrl;
class rCnsIK;
class uModel;

// Declarations
class uCnsDDOIK;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsDDOIK : public uConstraint
{
public:
    enum LIMIT_MODE
    {
        LIMIT_MODE_LAST_POSE = 0,
        LIMIT_MODE_CLOSER_ANGLE = 1,
    };
    enum COLLISION_MODE
    {
        COLLISION_MODE_FOOT = 0,
    };
    enum EFFECTOR_BEHAVIOR
    {
        EFFECTOR_BEHAVIOR_CHILD = 0,
        EFFECTOR_BEHAVIOR_KEEP_ORIGINAL_ANGLE = 1,
    };
    enum LIMIT_COORDINATE
    {
        LIMIT_COORDINATE_MOTION = 0,
        LIMIT_COORDINATE_BASE_POSE = 1,
    };
    enum EFF_CTRL
    {
        EC_TRANS_OFFSET = 1,
        EC_ROT_OFFSET = 2,
        EC_TRANS_SCALE = 4,
        EC_ORIGIN_MOT = 8,
    };
    enum IK_STATUS
    {
        IK_STATUS_EFF_TOUCH_GROUND = 1,
        IK_STATUS_EFF_OVERSTRETCH = 2,
        IK_STATUS_EFF_CLOSE_GROUND = 4,
        IK_STATUS_EFF_ROT_LERP = 8,
    };
public:
    class MyDTI;
    class JointInfo;
    class uCnsJoint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class uCnsJoint : public uConstraint
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
        // Address: 0x01ad37d0 - 0x01ad37d1 (1 bytes)
        virtual void update() {}  // vtable slot 30
        // Address: 0x01ad37e0 - 0x01ad37e1 (1 bytes)
        virtual void remove() {}  // vtable slot 31
        virtual void adjust(uModel::Joint* pJoint, uModel* pModel);  // vtable slot 29
        uCnsJoint();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        // Address: 0x01ad37f0 - 0x01ad37f1 (1 bytes)
        virtual void setResource(cResource* pRes) {}  // vtable slot 32
        virtual cResource* getResource();  // vtable slot 33
    public:
        uCnsDDOIK* mpCnsIK;  // offset: 0x98
        uCnsDDOIK::JointInfo* mpJointInfo;  // offset: 0xa0
        bool mIsEffector;  // offset: 0xa8
        static MyDTI DTI;
    };
public:
    class JointInfo : public MtObject
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
        JointInfo();
        virtual ~JointInfo();
        bool setJntNo(s32 JntNo);
        s32 getJntNo() const;
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        void setJntNoForProperty(s32 JntNo);
    public:
        MtMatrix mWMat;  // offset: 0x10
        MtMatrix mIKWMat;  // offset: 0x50
        MtMatrix mMat;  // offset: 0x90
        MtMatrix mLMat;  // offset: 0xd0
        MtMatrix mRotMat;  // offset: 0x110
        MtMatrix mCnvMat;  // offset: 0x150
        MtVector3 mScl;  // offset: 0x190
        f32 mSclDir;  // offset: 0x1a0
        f32 mOffset;  // offset: 0x1a4
        f32 mScaleOffset;  // offset: 0x1a8
    protected:
        s32 mJntNo;  // offset: 0x1ac
        uCnsDDOIK::uCnsJoint mCnsJoint;  // offset: 0x1b0
        uModel::Joint* mpJoint;  // offset: 0x260
        uCnsDDOIK* mpCnsIK;  // offset: 0x268
        MtVector3 mLastV;  // offset: 0x270
    public:
        s32 mIdx;  // offset: 0x280
        f32 mLen;  // offset: 0x284
        bool mIsEffector;  // offset: 0x288
        bool mIsLimit;  // offset: 0x289
        f32 mRotMin;  // offset: 0x28c
        f32 mRotMax;  // offset: 0x290
        bool mReverse;  // offset: 0x294
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
    MtVector3 calcUpVectorArmR();
    MtVector3 calcUpVectorArmL();
    MtVector3 calcUpVectorLeg();
protected:
    bool setupJointInfo(uModel* pModel, JointInfo* JointInfoTbl, s32 Num, uConstraint::DIRECTION DirVector, uConstraint::DIRECTION UpVector);
    void calcLocalMatrix(uModel* pModel, JointInfo* JointInfoTbl, s32 Num);
    f32 solve2BoneIK(f32 LenA, f32 LenB, f32 LenC);
    void calc1BoneIK(JointInfo& JointInfo0, MtVector3& EffDir, MtMatrix& BaseIKMat);
    void calc2BoneIK(JointInfo& JointInfo0, JointInfo& JointInfo1, JointInfo& JointInfo2, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat);
    void calc3BoneIK(JointInfo& JointInfo0, JointInfo& JointInfo1, JointInfo& JointInfo2, JointInfo& JointInfo3, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat);
    virtual bool limitEffector(MtMatrix& BaseIKMat, MtVector3& EffDir, MtVector3& EffPos, MtVector3& EffUp, MtVector3* pLastVBase, const MtMatrix& BaseWMat, f32 PitchMin, f32 PitchMax, f32 RotMin, f32 RotMax, f32 DistMin, f32 DistMax);  // vtable slot 39
    virtual bool limit(MtMatrix& Mat, const MtMatrix& PMat, f32 min, f32 max, MtVector3* pLastV);  // vtable slot 40
    virtual s32 checkGround(MtVector3& Pos, sCollision::TriangleInfo* pTriInfo);  // vtable slot 41
    void updateJointNum();
    MtVector3 getUpVector();
    MtVector3 calcUpVectorArm(const MtVector3& InnerUpOffset, const MtVector3& OuterUpOffset, f32 ip_sign);
public:
    uCnsDDOIK();
    virtual ~uCnsDDOIK();
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createSCollisionParam(MtPropertyList& s);  // vtable slot 42
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void drawPitch(MtMatrix& BaseWMat, f32 Pitch, f32 PitchMin, f32 PitchMax, f32 RotMin, f32 RotMax, f32 DistMin, f32 DistMax, bool Detail);
    virtual void adjust(uModel::Joint* pJoint, uModel* pModel);  // vtable slot 29
    virtual void update();  // vtable slot 30
    virtual void remove();  // vtable slot 31
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num);  // vtable slot 37
    virtual void evSetJoint(MtProperty& prop);  // vtable slot 38
    virtual void setModel(uModel* pModel);  // vtable slot 35
    void setCnsIKRes(rCnsIK* pCnsIKRes);
    rCnsIK* getCnsIKRes();
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    void setEnableScale(bool flg);
    bool isEnableScale();
    void setEffectorPosEnable(bool Enable);
    bool getEffectorPosEnable() const;
    void setEffectorRotEnable(bool);
    bool getEffectorRotEnable() const;
    void setEffectorTargetModelEnable(bool);
    bool getEffectorTargetModelEnable() const;
    void setEffectorTargetModel(uModel* pModel);
    uModel* getEffectorTargetModel();
    void setEffectorTargetJointNo(u32 JntNo);
    u32 getEffectorTargetJointNo() const;
    void setUpVectorPosEnable(bool);
    bool getUpVectorPosEnable() const;
    void setUpVectorTargetModelEnable(bool);
    bool getUpVectorTargetModelEnable() const;
    void setUpVectorTargetModel(uModel* pModel);
    uModel* getUpVectorTargetModel() const;
    void setUpVectorTargetJointNo(u32 JntNo);
    u32 getUpVectorTargetJointNo() const;
    bool setJoint0(s32);
    s32 getJoint0() const;
    bool setJoint1(s32);
    s32 getJoint1() const;
    bool setJoint2(s32);
    s32 getJoint2() const;
    bool setJoint(s32, s32);
    s32 getJoint(s32) const;
    JointInfo* getJointInfo(s32 Idx);
    void setJointInfo(JointInfo* pJointInfo, s32 Idx);
    void setJointInfoNum(s32 Num);
    s32 getJointInfoNum();
    void setDir(uConstraint::DIRECTION Dir);
    uConstraint::DIRECTION getDir() const;
    void setUp(uConstraint::DIRECTION Up);
    uConstraint::DIRECTION getUp() const;
    void setFitDir(s32 dir);
    s32 getFitDir() const;
    void setFitUp(s32 up);
    s32 getFitUp();
    f32 getEffPitchMin() const;
    void setEffPitchMin(f32 EffPitchMin);
    f32 getEffPitchMax() const;
    void setEffPitchMax(f32 EffPitchMax);
    f32 getEffRotMin() const;
    void setEffRotMin(f32 EffRotMin);
    f32 getEffRotMax() const;
    void setEffRotMax(f32 EffRotMax);
    f32 getEffDistMin() const;
    void setEffDistMin(f32 EffDistMin);
    f32 getEffDistMax() const;
    void setEffDistMax(f32 EffDistMax);
    f32 getJointRotMin(s32) const;
    void setJointRotMin(s32 Idx, f32 JointRotMin);
    f32 getJointRotMax(s32) const;
    void setJointRotMax(s32 Idx, f32 JointRotMax);
    f32 getHeelOffset() const;
    void setHeelOffset(f32 HeelOffset);
    f32 getHeelHeight() const;
    void setHeelHeight(f32 HeelHeight);
    bool getFit() const;
    void setFit(bool Fit);
    bool isGroundDistAdapt() const;
    void setGroundDistAdapt(bool flg);
    f32 getGroundDistAdaptLastGroundHeight();
    void setGroundDistAdaptLastGroundHeight(f32);
    bool isGroundDistAdaptLastGroundHit();
    void clearGroundDistAdaptLastGroundHit();
    f32 getCheckGroundLengthUpper() const;
    void setCheckGroundLengthUpper(f32 CheckGroundLengthUpper);
    f32 getCheckGroundLengthLower() const;
    void setCheckGroundLengthLower(f32 CheckGroundLengthLower);
    f32 getGroundLevel() const;
    void setGroundLevel(f32 GroundLevel);
    bool isEffectorLimitEnable() const;
    bool isEffectorLimitDisable() const;
    void setEffectorLimitEnable(bool Enable);
    bool isJointLimitEnable() const;
    bool isJointLimitDisable() const;
    void setJointLimitEnable(bool Enable);
    bool isCollisionEnable() const;
    void setCollisionEnable(bool Enable);
    LIMIT_MODE getEffLimitMode() const;
    void setEffLimitMode(LIMIT_MODE EffLimitMode);
    LIMIT_MODE getJointLimitMode() const;
    void setJointLimitMode(LIMIT_MODE JointLimitMode);
    COLLISION_MODE getCollisionMode() const;
    void setCollisionMode(COLLISION_MODE CollisionMode);
    EFFECTOR_BEHAVIOR getEffectorBehavior() const;
    void setEffectorBehavior(EFFECTOR_BEHAVIOR EffectorBehavior);
    f32 getMotionFitDist() const;
    void setMotionFitDist(f32 dist);
    bool getMotionFitDisable() const;
    void setMotionFitDisable(bool disable);
    s32 getLimitCoord() const;
    MtVector3 getLimitCoordOffset() const;
    void setLimitCoordOffset(const MtVector3&);
    bool isEffCtrlTransScaleDisable() const;
    bool isEffCtrlOffsetDisable() const;
    virtual u32 getDependentJointNum();  // vtable slot 26
    virtual uModel::Joint* getDependentJoint(u32 Idx);  // vtable slot 27
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void drawDebug();
    virtual void setPri(u32 Pri);  // vtable slot 28
    void set(uModel* pModel, rCnsIK* pCnsIKRes);
    u32 getStatus();
    void setEffectorControl(u32);
    u32 getEffectorContorl() const;
    void setOffsetMatrix(const MtMatrix&);
    MtMatrix getOffsetMatrix() const;
    void setCenterRefJntNo(s32);
    s32 getCenterRefJntNo() const;
    void setCenterPosOffset(const MtVector3&);
    MtVector3 getCenterPosOffset() const;
    void setTransScale(const MtVector3&);
    MtVector3 getTransScale() const;
    void setEffectorPos(const MtVector3& Pos);
    MtVector3 getEffectorPos();
    void setEffectorRot(const MtMatrix& mat);
    void setEffectorMat(const MtMatrix& mat);
    MtMatrix getEffectorMat();
    void setEffectorPos(uModel* pModel, u32 JntNo);
    void setUpVectorPos(const MtVector3& Pos);
    MtVector3 getUpVectorPos();
    void setUpVectorPos(uModel* pModel, u32 JntNo);
    void setCollisionParam(sCollision::Param&);
    u32 getGroundStat();
    const sCollision::TriangleInfo* getTriangleInfo();
    u32 getFindIntersectionResult() const;
    virtual MtUI* createSCollisionUI(MtProperty& prop);  // vtable slot 43
protected:
    MtMatrix mEffectorMat;  // offset: 0xa0
    MtVector3 mLastVBase;  // offset: 0xe0
    rCnsIK* mpCnsIKRes;  // offset: 0xf0
    u32 mStatus;  // offset: 0xf8
    s32 mJointNum;  // offset: 0xfc
    s32 mEffNo;  // offset: 0x100
    u32 mFindIntersectionResult;  // offset: 0x104
    sCollision::TriangleInfo mTriInfo;  // offset: 0x110
    bool mIsLimitBase;  // offset: 0x1e0
    union
    {
    public:
        uConstraint::DIRECTION mDir;  // offset: 0x0
        s32 mDirProp;  // offset: 0x0
    };  // offset: 0x1e4
    union
    {
    public:
        uConstraint::DIRECTION mUp;  // offset: 0x0
        s32 mUpProp;  // offset: 0x0
    };  // offset: 0x1e8
    s32 mFitUp;  // offset: 0x1ec
    s32 mFitDir;  // offset: 0x1f0
    JointInfo mJointInfo[4];  // offset: 0x200
    bool mEffectorLimitEnable;  // offset: 0xc80
    f32 mEffPitchMin;  // offset: 0xc84
    f32 mEffPitchMax;  // offset: 0xc88
    f32 mEffDistMin;  // offset: 0xc8c
    f32 mEffDistMax;  // offset: 0xc90
    f32 mEffRotMin;  // offset: 0xc94
    f32 mEffRotMax;  // offset: 0xc98
    bool mJointLimitEnable;  // offset: 0xc9c
    bool mCollisionEnable;  // offset: 0xc9d
    f32 mHeelOffset;  // offset: 0xca0
    f32 mHeelHeight;  // offset: 0xca4
    bool mFit;  // offset: 0xca8
    bool mGroundDistAdapt;  // offset: 0xca9
    f32 mCheckGroundLengthUpper;  // offset: 0xcac
    f32 mCheckGroundLengthLower;  // offset: 0xcb0
    MtVector3 mGroundNormal;  // offset: 0xcc0
    f32 mGroundDistance;  // offset: 0xcd0
    f32 mGroundLevel;  // offset: 0xcd4
    u32 mCollisionType;  // offset: 0xcd8
    u32 mCollisionFilter;  // offset: 0xcdc
    union
    {
    public:
        uCnsDDOIK::LIMIT_MODE mEffLimitMode;  // offset: 0x0
        s32 mEffLimitModeProp;  // offset: 0x0
    };  // offset: 0xce0
    union
    {
    public:
        uCnsDDOIK::LIMIT_MODE mJointLimitMode;  // offset: 0x0
        s32 mJointLimitModeProp;  // offset: 0x0
    };  // offset: 0xce4
    union
    {
    public:
        uCnsDDOIK::COLLISION_MODE mCollisionMode;  // offset: 0x0
        s32 mCollisionModeProp;  // offset: 0x0
    };  // offset: 0xce8
    union
    {
    public:
        uCnsDDOIK::EFFECTOR_BEHAVIOR mEffectorBehavior;  // offset: 0x0
        s32 mEffectorBehaviorProp;  // offset: 0x0
    };  // offset: 0xcec
    union
    {
    public:
        uCnsDDOIK::LIMIT_COORDINATE mLimitCoord;  // offset: 0x0
        s32 mLimitCoordProp;  // offset: 0x0
    };  // offset: 0xcf0
    MtVector3 mLimitCoordOffset;  // offset: 0xd00
    u32 mEffectorControl;  // offset: 0xd10
    MtMatrix mOffsetMat;  // offset: 0xd20
    MtVector3 mTransScale;  // offset: 0xd60
    MtVector3 mCenterPosOffset;  // offset: 0xd70
    s32 mCenterRefJntNo;  // offset: 0xd80
    sCollision::Param mCollisionParam;  // offset: 0xd90
    f32 mEffRelWeightNear;  // offset: 0xeb0
    f32 mEffRelWeightFar;  // offset: 0xeb4
    f32 mEffRelWeightNearDist;  // offset: 0xeb8
    f32 mEffRelWeightFarDist;  // offset: 0xebc
    f32 mMotionFitDist;  // offset: 0xec0
    bool mMotionFitDisable;  // offset: 0xec4
public:
    MtVector3 mEffectorPos;  // offset: 0xed0
    MtVector3 mUpVectorPos;  // offset: 0xee0
    uModel* mpEffectorTargetModel;  // offset: 0xef0
    u32 mEffectorTargetJointNo;  // offset: 0xef8
    uModel* mpUpVectorTargetModel;  // offset: 0xf00
    u32 mUpVectorTargetJointNo;  // offset: 0xf08
    f32 mLastGroundHeight;  // offset: 0xf0c
    bool mLastGroundHit;  // offset: 0xf10
    bool mEffectorPosEnable;  // offset: 0xf11
    bool mEffectorRotEnable;  // offset: 0xf12
    bool mUpVectorPosEnable;  // offset: 0xf13
    bool mEffectorTargetModelEnable;  // offset: 0xf14
    bool mUpVectorTargetModelEnable;  // offset: 0xf15
    bool mUseScale;  // offset: 0xf16
    cDelegate_0<MtVector3> callbackCalcUpVector;  // offset: 0xf18
    cpIKCtrl* mpIKCtrl;  // offset: 0xf30
    static MyDTI DTI;
    static const s32 JOINT_NONE = -1;
    static const s32 JOINT_MAX = 4;
};
