#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "rConstraint.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class uConstraint;

// Declarations
class rCnsIK;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rCnsIK : public rConstraint
{
public:
    class MyDTI;
    class JointInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s32 mJntNo;  // offset: 0x8
        f32 mRotMin;  // offset: 0xc
        f32 mRotMax;  // offset: 0x10
        f32 mOffset;  // offset: 0x14
        f32 mScaleOffset;  // offset: 0x18
        bool mReverse;  // offset: 0x1c
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
    rCnsIK();
    virtual ~rCnsIK();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copyUnitProperty(uConstraint* pSrcUnit);  // vtable slot 16
protected:
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    JointInfo mJoint[16];  // offset: 0x78
    s32 mJointNum;  // offset: 0x278
    s32 mDir;  // offset: 0x27c
    s32 mUp;  // offset: 0x280
    s32 mFitDir;  // offset: 0x284
    s32 mFitUp;  // offset: 0x288
    bool mEffectorLimitEnable;  // offset: 0x28c
    f32 mEffPitchMin;  // offset: 0x290
    f32 mEffPitchMax;  // offset: 0x294
    f32 mEffRotMin;  // offset: 0x298
    f32 mEffRotMax;  // offset: 0x29c
    f32 mEffDistMin;  // offset: 0x2a0
    f32 mEffDistMax;  // offset: 0x2a4
    bool mJointLimitEnable;  // offset: 0x2a8
    bool mCollisionEnable;  // offset: 0x2a9
    f32 mHeelOffset;  // offset: 0x2ac
    f32 mHeelHeight;  // offset: 0x2b0
    bool mFit;  // offset: 0x2b4
    f32 mCheckGroundLengthUpper;  // offset: 0x2b8
    f32 mCheckGroundLengthLower;  // offset: 0x2bc
    f32 mGroundLevel;  // offset: 0x2c0
    s32 mCollisionMode;  // offset: 0x2c4
    bool mGroundDistAdapt;  // offset: 0x2c8
    s32 mEffLimitMode;  // offset: 0x2cc
    s32 mJointLimitMode;  // offset: 0x2d0
    s32 mEffectorBehavior;  // offset: 0x2d4
    f32 mMotionFitDist;  // offset: 0x2d8
    bool mMotionFitDisable;  // offset: 0x2dc
    s32 mLimitCoord;  // offset: 0x2e0
    MtVector3 mLimitCoordOffset;  // offset: 0x2f0
    bool mEffectorTargetModel;  // offset: 0x300
    u32 mEffectorTargetJointNo;  // offset: 0x304
    bool mEffectorTargetModelEnable;  // offset: 0x308
    bool mUpVectorTargetModel;  // offset: 0x309
    u32 mUpVectorTargetJointNo;  // offset: 0x30c
    bool mUpVectorTargetModelEnable;  // offset: 0x310
    u32 mEffectorControl;  // offset: 0x314
    MtMatrix mOffsetMat;  // offset: 0x320
    MtFloat3 mTransScale;  // offset: 0x360
    MtFloat3 mCenterPosOffset;  // offset: 0x36c
    s32 mCenterRefJntNo;  // offset: 0x378
    bool mUseScale;  // offset: 0x37c
    static MyDTI DTI;
    static const u32 DATA_VERSION = 4;
    static const s32 JOINT_MAX = 16;
};
