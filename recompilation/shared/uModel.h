#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "nMotion.h"
#include "rModel.h"
#include "uBaseModel.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtColor;
class MtDTI;
class MtEaseCurve;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cBakeModel;
class cBakeModelEx;
class cDraw;
class cpBakeJoint;
class cpMotionRate;
namespace nDraw { class CommandCache; }
namespace nDraw { class Material; }
namespace nDraw { class Texture; }
namespace nMotion { struct KEYFRAME_INFO; }
namespace nMotion { struct MOTION_INFO; }
namespace nMotion { struct MPARAM_WORK; }
namespace nMotion { struct SEQUENCE_INFO; }
class rModel;
class rMotionList;
class uConstraint;
class uDDOModel;
class uSimSoftBody;

// Declarations
class uModel;

enum MOT_TYPE
{
    MOT_BASE = 0,
    MOT_BLEND1 = 1,
    MOT_BLEND2 = 2,
    MOT_BLEND3 = 3,
    MOT_BLEND4 = 4,
    MOT_BLEND5 = 5,
    MOT_BLEND6 = 6,
    MOT_BLEND7 = 7,
    MOT_TYPE_NUM = 8,
    MOT_TYPE_UNDEF = -1,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class uModel : public uBaseModel
{
    // inferred: cBakeModel::buildJointIndexTable names uModel::mJointTable
    friend class cBakeModel;
    // inferred: cBakeModelEx::getJointFromIndex names uModel::mJoint
    friend class cBakeModelEx;
    // inferred: cpBakeJoint::setRenewalEnvelope names uModel::mEnvelopeHandle
    friend class cpBakeJoint;
    // inferred: cpMotionRate::saveMotionSpeed names uModel::mMotion[0].mSpeed
    friend class cpMotionRate;
    // inferred: uSimSoftBody::updateTargetBoundary calls uModel::updateBoundary
    friend class uSimSoftBody;
public:
    enum UPDATE_WORLD_MATRIX_MODE
    {
        UPDWM_DEFAULT = 0,
        UPDWM_PRE_UPDATE = 1,
        UPDWM_DISABLE_CONSTRAINT = 2,
        UPDWM_NULL_MATRIX = 4,
        UPDWM_ENABLE_SCALE = 0,
    };
    enum MODEL_STATUS
    {
        S_JOINT_READY = 1,
    };
    enum INTER_STATE
    {
        IS_SKIP_QUAT = 1,
        IS_SKIP_TRANS = 2,
        IS_SKIP_SCALE = 4,
        IS_SET = 8,
        IS_SETTED = 16,
        IS_SKIP_MASK = 7,
        IS_DISABLE = 32,
        IS_KEEP_FLAG = 32,
        SHIFT_PEAK_TO_SKIP = 4,
        SHFIT_USE_TO_SKIP = 0,
    };
    enum MJOINT_STATE
    {
        MJS_USE_QUAT = 1,
        MJS_USE_TRANS = 2,
        MJS_USE_SCALE = 4,
        MJS_USE_BIK = 8,
        MJS_PEAK_QUAT = 16,
        MJS_PEAK_TRANS = 32,
        MJS_PEAK_SCALE = 64,
        MJS_USE_MASK = 15,
        MJS_PEAK_MASK = 112,
    };
public:
    class MyDTI;
    class Joint;
    class Constraint;
    class Motion;
    struct MJOINT_WORK;
    struct InterpolationJoint;
    class JointDAGNode;
public:
    using CalcWMatFunction = void(uModel::*)(uModel::Joint*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Joint : public MtObject
    {
    public:
        enum ATTRIBUTE
        {
            A_DISABLE_MOTION = 1,
            A_IK_CORRECT = 2,
            A_IK_TRIGGER = 4,
            A_INVERSE_ROTATE = 8,
            A_SKIN = 16,
            A_DISABLE_CALC_WMAT = 32,
            A_DISABLE_INTERPOLATE = 64,
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
        Joint();
        virtual ~Joint();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        const MtQuaternion& getQuat() const;
        void setQuat(const MtQuaternion& quat);
        const MtVector3& getScale();
        void setScale(const MtVector3& scale);
        MtVector3 getWorldPos() const;
        void setWorldPos(const MtVector3& pos);
        const MtVector3& getPos() const;
        void setPos(const MtVector3& pos);
        const MtMatrix& getWorldMat() const;
        void setWorldMat(const MtMatrix& mat);
        MtMatrix getLocalMat() const;
        void setLocalMat(const MtMatrix& mat);
        void inverseCalcLMat(uModel* pModel, bool Scale);
        u32 getAttr() const;
        u32 isAttr(u32 attr) const;
        void setAttr(u32 attr);
        uModel::Joint* getParentJoint();
        u32 getParentIndex() const;
        void setParentIndex(u32 index);
        u32 getSymmetryIndex() const;
        void setSymmetryIndex(u32 index);
        u32 getNo() const;
        void setNo(u32 no);
        u32 getType() const;
        void setType(u32 type);
        f32 getLength() const;
        void setLength(f32);
        void setConstraint(uModel::Constraint* pc);
        uModel::Constraint* getConstraint();
        u32 getConstraintNum();
        const MtVector3& getOffset() const;
        void setOffset(const MtVector3&);
        u32 getChildNum() const;
        bool isLeaf();
        u32 getChildJoint(uModel::Joint* * ppJoint);
        u8 getCalcNo();
        void setPreUpdate(bool);
        bool isPreUpdate();
        uModel* getModel();
        void setShaderAttributes(MtColor);
        MtColor getShaderAttributes();
    public:
        uModel::Constraint* mpConstraint;  // offset: 0x8
        f32 mLength;  // offset: 0x10
        u32 mDepth;  // offset: 0x14
        MtMatrix mWmat;  // offset: 0x20
        MtVector3 mOffset;  // offset: 0x60
        MtQuaternion mQuat;  // offset: 0x70
        MtVector3 mScale;  // offset: 0x80
        MtVector3 mTrans;  // offset: 0x90
        u32 mAttr : 8;  // offset: 0xa0
        u32 mParentIndex : 8;  // offset: 0xa0
        u32 mType : 8;  // offset: 0xa0
        u32 mNo : 8;  // offset: 0xa0
        u32 mSymmetryIndex : 8;  // offset: 0xa4
        u32 mChildNum : 8;  // offset: 0xa4
        u32 mPreUpdate : 1;  // offset: 0xa4
        u32 mCalcFlag : 1;  // offset: 0xa4
        u32 mReserved : 14;  // offset: 0xa4
    protected:
        uModel* mpModel;  // offset: 0xa8
        MtColor mShaderAttributes;  // offset: 0xb0
    public:
        static MyDTI DTI;
    };
public:
    class Constraint : public MtObject
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
        virtual void adjust(uModel::Joint*, uModel*) = 0;  // vtable slot 6
        virtual u32 getDependentJointNum();  // vtable slot 7
        virtual uModel::Joint* getDependentJoint(u32 idx);  // vtable slot 8
        virtual uConstraint* getUConstraint();  // vtable slot 9
        virtual uModel::Constraint* getNextConstraint();  // vtable slot 10
        virtual uModel::Constraint* getPrevConstraint();  // vtable slot 11
    public:
        static MyDTI DTI;
    };
public:
    class Motion : public MtObject
    {
        // inferred: cpMotionRate::saveMotionSpeed names uModel::mMotion[0].mSpeed
        friend class cpMotionRate;
        // inferred: uDDOModel::getMotionNo names uModel::Motion::mMotionNo
        friend class uDDOModel;
    public:
        enum ATTRIBUTE
        {
            A_NULL_TRANS_OFF = 1,
            A_FIRST_TRANS_ON = 2,
            A_LOOP_OFF = 4,
            A_ADD_TRANS_OFF = 8,
            A_STOP = 16,
            A_NULL_TRANS_FIX = 32,
            A_ENABLE_SCALE = 64,
            A_NULL_ANGLE_FIX = 128,
            A_SYMMETRY = 256,
            A_NULL_ONLY = 512,
            A_PREV_TRANS_ON = 1024,
            A_INTEGER_FRAME = 2048,
            A_ADD_ROT_OFF = 4096,
            A_NULL_TRANS_FIX_SCALE = 8192,
            A_SCALE_INHERIT_OFF = 16384,
            A_NULL_SYMMETRY = 32768,
            A_CONTINUE_TRANS = 65536,
            A_CONTINUE_FRAME = 131072,
            A_ADD_BLEND = 262144,
            A_BASE_MOT = 524288,
            A_SCALE_INHERIT_WDIR = 1048576,
            A_DISABLE_SEQ_NEXTEND = 2097152,
            A_CONTINUE = 196608,
            A_AUTO_CLEAR_FLAG = 1065024,
            A_SCALE_FLAGS = 1065024,
            A_MODE_FLAG_MASK = -16777216,
            A_MODE_CONSTRAINT = 16777216,
            A_MODE_BUILTINIK = 33554432,
            A_MODE_NOSCALE = 67108864,
            A_MODE_DISABLE_CALCJWM = 134217728,
            A_MODE_JOINT_IDENTITY = 268435456,
            A_MODE_SET_MOTION = 536870912,
            A_MODE_EX = -2147483648,
            A_MOTEX_FLAGS = -2113912512,
        };
        enum STATE
        {
            S_MOTION_NEXT_END = 1,
            S_SETUP = 2,
            S_MOTION_END = 4,
            S_INTERPOLATE = 256,
            S_PROTECT_STATE = 65282,
        };
    public:
        class MyDTI;
        struct KeyFrameData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct KeyFrameData
        {
        public:
            u32 index;  // offset: 0x0
            union
            {
            public:
                u32 value;  // offset: 0x0
                s32 value_s32;  // offset: 0x0
                f32 value_f32;  // offset: 0x0
            };  // offset: 0x4
            union
            {
            public:
                u32 prev_value;  // offset: 0x0
                s32 prev_value_s32;  // offset: 0x0
                f32 prev_value_f32;  // offset: 0x0
            };  // offset: 0x8
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        Motion();
        virtual ~Motion();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        f32 getInterRate() const;
        void setInterRate(f32);
        f32 getInterCount() const;
        void setInterCount(f32);
        void setMotionNo(u32 no);
        u32 getMotionNo() const;
        f32 getFrame() const;
        void setFrame(f32 frame);
    private:
        f32 getFramePrivate() const;
        void setFramePrivate(f32 NewValue);
        u16 getMotionNoPrivate() const;
        void setMotionNoPrivate(u16 NewValue);
    public:
        f32 getPrevFrame() const;
        void setPrevFrame(f32);
        f32 getLoopFrame() const;
        void setLoopFrame(f32 frame);
        u32 getState() const;
        u32 isState(u32 state) const;
        bool isMotionEnd() const;
        bool isMotionNextEnd() const;
        void setState(u32 state);
        void orState(u32);
        void norState(u32 state);
        u32 getAttr() const;
        u32 isAttr(u32) const;
        void setAttr(u32 attr);
        f32 getInterFrame() const;
        void setInterFrame(f32);
        f32 getBlendRate() const;
        void setBlendRate(f32 rate);
        f32 getSpeed() const;
        void setSpeed(f32 NewValue);
        f32 getFrameMax() const;
        const MtEaseCurve& getInterCurve() const;
        void setInterCurve(const MtEaseCurve&);
        u32 getSequence(u32 page) const;
        u32 getPrevSequence(u32 page) const;
        u32 calcSequence(u32 page, s32 minframe, s32 maxframe);
        void setSequence(u32 page, u32 seq);
        void setPrevSequence(u32, u32);
        u32 getSequenceWork(u32 page, u32 index) const;
        const MtVector3& getPrevTrans() const;
        void setPrevTrans(const MtVector3&);
        const MtQuaternion& getPrevQuat() const;
        void setPrevQuat(const MtQuaternion&);
        void setBaseTrans(const MtVector3&);
        const MtVector3& getBaseTrans() const;
        void setBaseQuat(const MtQuaternion&);
        const MtQuaternion& getBaseQuat() const;
        uModel::MJOINT_WORK* getJoint(u32 index);
        void setJointBlendWeight(u32, f32);
        u32 getKeyFrameNum() const;
        void setKeyFrameNum(u32);
        u32 getKeyFrameType(u32 idx) const;
        bool hasKeyFrame(u32 idx) const;
        u16 getKeyFrameWork(u32 idx) const;
        void setKeyFrameWork(u16 i, u32 idx);
        u32 getKeyFrame(u32 idx) const;
        void setKeyFrame(u32 v, u32 idx);
        u32 getPrevKeyFrame(u32 idx) const;
        void setPrevKeyFrame(u32 v, u32 idx);
        s32 getKeyFrameS32(u32 idx) const;
        f32 getKeyFrameF32(u32 idx) const;
        s32 getPrevKeyFrameS32(u32 idx) const;
        void setPrevKeyFrameS32(s32 s, u32 idx);
        f32 getPrevKeyFrameF32(u32 idx) const;
        void setPrevKeyFrameF32(f32 f, u32 idx);
        void calcKeyFrame(f32 frame);
    protected:
        u16 mMotionNo;  // offset: 0x8
        u16 mState;  // offset: 0xa
        u16 mPrevState;  // offset: 0xc
        u16 mDmy;  // offset: 0xe
        u32 mAttr;  // offset: 0x10
        f32 mStartFrame;  // offset: 0x14
        f32 mCarryFrame;  // offset: 0x18
        f32 mPrevDeltaFrame;  // offset: 0x1c
        MtQuaternion mCarryQuat;  // offset: 0x20
        MtVector3 mCarryTrans;  // offset: 0x30
        f32 mInterFrame;  // offset: 0x40
        f32 mInterCount;  // offset: 0x44
        f32 mBlend;  // offset: 0x48
        f32 mFrame;  // offset: 0x4c
        f32 mPrevFrame;  // offset: 0x50
        f32 mFrameMax;  // offset: 0x54
        f32 mLoopFrame;  // offset: 0x58
        f32 mSpeed;  // offset: 0x5c
        f32 mInterRate;  // offset: 0x60
    public:
        f32 mNowFrame;  // offset: 0x64
        f32 mNextFrame;  // offset: 0x68
    protected:
        MtEaseCurve mInterCurve;  // offset: 0x6c
        MtQuaternion mPrevQuat;  // offset: 0x80
        MtQuaternion mBaseQuat;  // offset: 0x90
        MtQuaternion mNullQuat;  // offset: 0xa0
        MtVector3 mPrevTrans;  // offset: 0xb0
        MtVector3 mBaseTrans;  // offset: 0xc0
        MtVector3 mNullTrans;  // offset: 0xd0
        nMotion::MPARAM_WORK mTransParam;  // offset: 0xe0
        nMotion::MPARAM_WORK mQuatParam;  // offset: 0x100
        nMotion::SEQUENCE_INFO* mpSeqInfo[4];  // offset: 0x120
        u32 mSequence[4];  // offset: 0x140
        u32 mPrevSequence[4];  // offset: 0x150
        uModel::MJOINT_WORK* mJoint;  // offset: 0x160
        u32 mKeyFrameNum;  // offset: 0x168
        nMotion::KEYFRAME_INFO* mpKeyFrameInfo;  // offset: 0x170
        KeyFrameData* mpKeyFrameData;  // offset: 0x178
    public:
        static MyDTI DTI;
        static const u32 S_FRAME_END = 1;
    };
public:
    struct MJOINT_WORK
    {
    public:
        nMotion::MPARAM_WORK mQuatParam;  // offset: 0x0
        nMotion::MPARAM_WORK mTransParam;  // offset: 0x20
        nMotion::MPARAM_WORK mScaleParam;  // offset: 0x40
        u32 mState;  // offset: 0x60
    };
public:
    struct InterpolationJoint
    {
    public:
        u32 mMotType;  // offset: 0x0
        u32 mState;  // offset: 0x4
        MtQuaternion mQuat;  // offset: 0x10
        MtVector3 mTrans;  // offset: 0x20
        MtVector3 mScale;  // offset: 0x30
    };
public:
    class JointDAGNode : public MtObject
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
        JointDAGNode();
        virtual ~JointDAGNode();
    public:
        MtArray mLink;  // offset: 0x8
        uModel::Joint* mpJnt;  // offset: 0x28
        u32 mDepth;  // offset: 0x30
        bool mVisit;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uModel();
    virtual ~uModel();
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void move();  // vtable slot 9
    // Address: 0x01ac7e80 - 0x01ac7e81 (1 bytes)
    virtual void sync() {}  // vtable slot 11
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void updateLocalMatrix();  // vtable slot 25
    virtual void updateWorldMatrix();  // vtable slot 26
    virtual void updateWorldMatrixEx(u32 flag);  // vtable slot 37
    void updateJointWorldMatrix(const u8* jointTable, const u32 jointNum, const u32 updateWorldMode);
    virtual const MtMatrix& getWorldMatrix(s32 parent_no) const;  // vtable slot 27
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setModel(rModel* pmod);  // vtable slot 29
    u32 getModelStatus();
    void setPreUpdate(Joint* pJnt);
    void clearJointDepth();
    void calcJointDepth();
    void calcJointDependency();
    void sortJointByDepth();
    u32 getJointNum() const;
    Joint* getJointFromIndex(u32 index);
    const Joint* getJointFromIndex(u32 index) const;
    Joint* getJointFromNo(u32 no);
    const Joint* getJointFromNo(u32 no) const;
    u32 getJointIndexFromNo(u32 no) const;
    const MtMatrix& getJointBaseMatrixFromIndex(u32 index) const;
    const MtMatrix& getJointBaseMatrixFromNo(u32 no) const;
    const MtMatrix& getJointInvBaseMatrixFromIndex(u32 index) const;
    const MtMatrix& getJointInvBaseMatrixFromNo(u32) const;
    void initJointLocalMatrix();
    const u8* getJointDepthTable() const;
    u32 getEnvelopeHandle() const;
    void setEnvelopeHandle(u32 env_handle);
    f32 getMotionBlurDist() const;
    void setMotionBlurDist(f32);
    f32 getMotionBlurLimite() const;
    void setMotionBlurLimite(f32);
    void setMotionList(rMotionList* pmot, u32 bank);
    rMotionList* getMotionList(u32 bank);
    const rMotionList* getMotionList(u32) const;
    virtual bool setMotion(u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);  // vtable slot 38
    virtual bool setMotionEx(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);  // vtable slot 39
    void moveMotion();
    Motion* getMotion(MOT_TYPE s);
    const Motion* getMotion(MOT_TYPE s) const;
    u32 getMotionState(MOT_TYPE) const;
    bool isMotionEnd(MOT_TYPE s) const;
    bool isMotionNextEnd(MOT_TYPE s) const;
    u32 getSequence(u32 page, MOT_TYPE s) const;
    u32 getPrevSequence(u32 page, MOT_TYPE s) const;
    u16 getSequenceWork(u32 page, u32 index, MOT_TYPE s) const;
    u32 getKeyFrameType(u32, MOT_TYPE) const;
    s32 getKeyFrameS32(u32, MOT_TYPE) const;
    f32 getKeyFrameF32(u32 idx, MOT_TYPE s) const;
    s32 getPrevKeyFrameS32(u32, MOT_TYPE) const;
    f32 getPrevKeyFrameF32(u32, MOT_TYPE) const;
    u16 getKeyFrameWork(u32 idx, MOT_TYPE s) const;
    nMotion::MOTION_INFO* getMotionInfo(u32 mot_no);
    void setBlendNum(u32 n);
    u32 getBlendNum() const;
    bool getShowJointNo() const;
    void updateJointDependency();
    void setNullTransScale(const MtVector3&);
    const MtVector3& getDeltaPos() const;
    const MtQuaternion getDeltaQuat() const;
    void calcNullParam(f32 Frame, MtVector3* pPos, MtQuaternion* pQuat);
    virtual void recomputeLocalMatrix();  // vtable slot 40
    u32 getKeyFrameNum() const;
    InterpolationJoint* getInterpolationJointFromIndex(u32 i);
    const InterpolationJoint* getInterpolationJointFromIndex(u32 i) const;
    InterpolationJoint* getInterpolationJointFromNo(u32 n);
    const InterpolationJoint* getInterpolationJointFromNo(u32 n) const;
    u32 getMotionCalcFlag() const;
    void setEnableConstraint(bool enable);
    bool isEnableConstraint() const;
    void setCalcJointWorldMatrix(bool enable);
    bool isCalcJointWorldMatrix() const;
    void setJointInitIdentity(bool enable);
    bool isJointInitIdentity() const;
    void setEnableJointScale(bool enable);
    bool isEnableJoitScale() const;
    void setMorphWeight(f32, u32);
    f32 getMorphWeight(u32);
protected:
    void modelResourceReloadCheck();
    void updateShaderAttributes();
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    void updateBoundary();
    void calcJointDependDepth(Joint* pJnt);
    u32 calcJointDependDepthSub(Constraint* pCns);
    void interpolateMotion();
    void updateWorldMatrixSub(bool ConstraintEnable, bool PreUpdate);
    void calcConstraint();
    void calcWMat(Joint* pwk);
    void calcWMatScaleInherit(Joint* pwk);
    void calcWMatScaleGlobal(Joint* pwk);
    void calcWMatNoScale(Joint* pwk);
    void calcWMatScale(Joint* pwk, u32 attr);
    void transSkinDebug(rModel* pmod);
    virtual void drawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);  // vtable slot 33
    s32 cullingSkin(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, s32 basecullmask);
    virtual void cullingCommandCache(cDraw* pdraw, nDraw::CommandCache* pcache, rModel* pmod, s32 basecullmask, u32 lod);  // vtable slot 34
    void updateMotionParam();
    void checkUpdateMotResource(u32 i);
    void setupMotionParam(MOT_TYPE src, u32 mot_no);
    void setupMotionParam(MOT_TYPE src, nMotion::MOTION_INFO* pinfo);
    void calcSymmetry(MtVector3* ptrans, MtQuaternion* pquat);
    void calcSymmetry(Joint* pJnt, MtVector3* ptrans, MtQuaternion* pquat);
public:
    virtual bool adjustHand(Joint* pjnt, const MtVector3& world_rootpos);  // vtable slot 41
    virtual bool adjustFoot(Joint* pjnt, const MtVector3& world_rootpos);  // vtable slot 42
    bool isFootAdjust();
    void setFootAdjust(bool f);
    bool isAnkleAdjust();
    void setAnkleAdjust(bool f);
    f32 getHeelHeight();
    void setHeelHeight(f32);
    void setBasePlane(const MtVector4&);
    void setWaistOffset(f32);
    f32 getWaistOffset();
    f32 getWaistAdjustFactor();
    f32 getWaistAdjustSpeed();
    MtEaseCurve getWaistAdjustCurve();
    void setWaistAdjust(f32, f32, MtEaseCurve);
    u32 getFootAdjustType() const;
    void setFootAdjustType(u32);
    u32 getFootAdjustFilter() const;
    void setFootAdjustFilter(u32);
    u32 getFootAdjustGroupBit() const;
    void setFootAdjustGroupBit(u32);
protected:
    void calcBuiltInIK();
    void calcIkHand(const MtMatrix& nullmat, u32 jnt_no, f32 rotrev, bool old, bool frontup);
    void calcIkHand2(const MtMatrix& nullmat, u32 jnt_no, f32 rotrev, bool frontup);
    void calcIkHand7(const MtMatrix& nullmat, u32 jnt_no, f32 rotrev, bool hand_flag, bool frontup);
    void calcIkFoot(const MtMatrix& nullmat, u32 jnt_no, f32 uprev, f32 rotrev);
    void calcIkFoot2(const MtMatrix& nullmat, u32 jnt_no, f32 uprev, f32 rotrev, bool frontup);
    void calcIkFoot3(const MtMatrix& nullmat, u32 jnt_no, f32 rotrev);
    void calcIkFoot7(const MtMatrix& nullmat, u32 jnt_no, f32 uprev, f32 rotrev);
    void calcIkFoot8(const MtMatrix& nullmat, u32 jnt_no, f32 uprev, f32 rotrev);
    void calcIk(const MtMatrix& nullmat, u32 jnt_no, u32 type);
    void calcIk2(const MtMatrix& nullmat, u32 jnt_no, u32 type);
    void updateIKParam();
    Joint* getJointFromIndexForProp(u32 index);
    rMotionList* getMotionListProp(u32 bank);
    Motion& getMotionProp(u32);
private:
    u32 getMotionListNum() const;
    void setMotionListNum(u32);
protected:
    void initRCN();
    void clearRCN();
    void updateRCN(cDraw* pdraw);
    void updatePosition(cDraw* pdraw);
    void updateNormal(cDraw* pdraw, SO_HANDLE write_channel);
    void updateNormal(cDraw* pdraw);
public:
    void superSetCommonStateCalller(cDraw* pdraw);
protected:
    bool isInterpolating();
    void updateMotionFrame();
    void updateMotionNullParam();
    void updateMotionJointParam();
    void updateMotionJointParamEx();
    void updateFrame();
    void setupMotion();
protected:
    MtSphere mPrevBoundingSphere[2];  // offset: 0x11b0
    u32 mJointNum;  // offset: 0x11d0
    Joint* mJoint;  // offset: 0x11d8
    const u8* mJointTable;  // offset: 0x11e0
    u8* mJointDepthTable;  // offset: 0x11e8
    u32 mModelStatus;  // offset: 0x11f0
    u32 mBlendNum;  // offset: 0x11f4
    u32 mMotionCalcFlag;  // offset: 0x11f8
    u32 mMotionInterpolateAttr;  // offset: 0x11fc
    Motion mMotion[8];  // offset: 0x1200
    s32 mMotionBlurSetup;  // offset: 0x1e00
    f32 mMotionBlurDist;  // offset: 0x1e04
    f32 mMotionBlurLimite;  // offset: 0x1e08
    u32 mEnvelopeHandle;  // offset: 0x1e0c
    u32 mEnvelopeNum;  // offset: 0x1e10
    uModel* mpSkinMeshCollisionPtr;  // offset: 0x1e18
    MtVector3 mNullTransScale;  // offset: 0x1e20
    MtVector3 mDeltaPos;  // offset: 0x1e30
    MtQuaternion mDeltaQuat;  // offset: 0x1e40
    InterpolationJoint* mpInterpolationJoint;  // offset: 0x1e50
    rMotionList* mpMotionList[16];  // offset: 0x1e58
    u32 mKeyFrameNum;  // offset: 0x1ed8
    bool mShowJointNo;  // offset: 0x1edc
    bool mUpdateJointDependencyReq;  // offset: 0x1edd
    bool mUpdateNormal;  // offset: 0x1ede
    f32 mMorphWeight[4];  // offset: 0x1ee0
    nDraw::Texture* mpShaderAttributes[2];  // offset: 0x1ef0
    MtVector4 mBasePlane;  // offset: 0x1f00
    f32 mWaistOffset;  // offset: 0x1f10
    f32 mWaistAdjustFactor;  // offset: 0x1f14
    f32 mWaistAdjust;  // offset: 0x1f18
    MtEaseCurve mWaistAdjustCurve;  // offset: 0x1f1c
    f32 mWaistAdjustSpeed;  // offset: 0x1f24
    f32 mHeelHeight;  // offset: 0x1f28
    f32 mRotInverseWeight;  // offset: 0x1f2c
    u32 mFootAdjustType;  // offset: 0x1f30
    u32 mFootAdjustFilter;  // offset: 0x1f34
    u32 mFootAdjustGroupBit;  // offset: 0x1f38
    bool mAnkleAdjust;  // offset: 0x1f3c
    bool mFootAdjust;  // offset: 0x1f3d
    bool mCalcBuiltInIKReq;  // offset: 0x1f3e
private:
    nDraw::Texture* mpPositionMap;  // offset: 0x1f40
    nDraw::Texture* mpNormalMap;  // offset: 0x1f48
    nDraw::Texture* mpTangentMap;  // offset: 0x1f50
    nDraw::Texture* mpNormalSubMap;  // offset: 0x1f58
public:
    static const s32 MAX_MOTIONLIST = 16;
    static MyDTI DTI;
    static const s32 MAX_JOINT = 256;
protected:
    static const u8 mDefaultJointTable[256];
    static const u32 MAX_MORPH_WEIGHT = 4;
    static const u32 MAX_RECALCVBUF = 2;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 uModel::getEnvelopeHandle() const {
    return this->mEnvelopeHandle;
}
