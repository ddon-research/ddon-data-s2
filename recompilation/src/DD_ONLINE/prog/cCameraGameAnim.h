#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cCamInterporate.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraBase.h"
#include "uCameraGame.h"

#include "cCameraGameLock.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamExParam;
class cCamExParamAnimTar;
class cCamImpBase;
class cCamInterporateRange;
class cCamInterporateRangeAng;
class cCameraSeqInfo;
class uBaseModel;
class uCameraGame;
class uCoord;
class uHuman;

// Declarations
class cCamExParamAnim;
class cCamExParamAnim2;
class cCamImpAnim;
class cCamImpAnimTar;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class cCamExParamAnim : public cCamExParam
{
public:
    enum OPTION
    {
        OP_END_ANIMATION = 1,
        OP_CAM2TARGET_BASE = 2,
        OP_STAY_INIT = 4,
        OP_PL_EDIT_ADJ_CAM = 8,
        OP_PL_EDIT_ADJ_TAR = 16,
        OP_FOLLOW_INTER = 32,
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamAnim();
    virtual ~cCamExParamAnim();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    u32 mOptionFlag;  // offset: 0x1d4
    MtArray mCameraInfoList;  // offset: 0x1d8
    static MyDTI DTI;
};

class cCamExParamAnimTar : public cCamExParamLockCore<cCamExParamAnim>
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamAnimTar();
    virtual ~cCamExParamAnimTar();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
public:
    static MyDTI DTI;
};

inline cCamExParamAnimTar::cCamExParamAnimTar() {
    this->::cCamExParam::mType = static_cast<nCameraGame::CAMERA_TYPE>(11);
}

class cCamExParamAnim2 : public cCamExParamAnim
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamAnim2();
    virtual ~cCamExParamAnim2();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    static MyDTI DTI;
};

class cCamImpAnim : public cCamImpBase
{
public:
    class MyDTI;
    struct CAM_ANIM_HDR;
    struct HERMITE_PARAM;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CAM_ANIM_HDR
    {
    public:
        u32 mVersion;  // offset: 0x0
        u32 mAvailable;  // offset: 0x4
        f32 mTimeMax;  // offset: 0x8
        u32 mParamNum;  // offset: 0xc
    };
public:
    struct HERMITE_PARAM
    {
    public:
        f32 value;  // offset: 0x0
        f32 handleL;  // offset: 0x4
        f32 handleR;  // offset: 0x8
        u32 rate;  // offset: 0xc
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
    cCamImpAnim();
    virtual ~cCamImpAnim();
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    uintptr HermiteExport(u32 seqNum, const cCameraSeqInfo* seqList, u8* pAnimDatBuff);
    void calcRealAddress(CAM_ANIM_HDR* pHdr);
    s32 getAnimationParam(f32 time, cCameraSeqInfo& reInfo, f32& rate);
    void setSequenceData(cCameraSeqInfo* pData);
    void makeAnimationData();
    void setAnimationData(const MtArray& list);
    u32 getSeqNum() const;
    f32 getAnimationTime() const;
    virtual f32 adjustAddPlayerHeight(f32 addHeight);  // vtable slot 8
private:
    void calcTargetMatrix(MtMatrix& mat, const MtMatrix& ofsMat, const uCoord* pTarget, s32 joint);
    void calcTargetMatrix(MtMatrix& mat, const MtMatrix& ofsMat, const MtMatrix& initMat, const MtMatrix& initJointMat, s32 joint);
    void updateInitMat(bool isRotate);
    bool isHumanEditAdjTarget(const uBaseModel* pTarget);
    void calcHumanEditAdjustVec(uHuman* pPlayerBase, MtVector3& vec);
private:
    const cCamExParamAnim* mpParamAnim;  // offset: 0xb0
    CAM_ANIM_HDR* mpData;  // offset: 0xb8
    u8 mBuffer[4128];  // offset: 0xc0
    cCameraSeqInfo mSequence[32];  // offset: 0x10e0
    u32 mSeqNum;  // offset: 0x1ce0
    f32 mTimer;  // offset: 0x1ce4
    bool mIsFirstSet;  // offset: 0x1ce8
    MtMatrix mInitMat;  // offset: 0x1cf0
    MtMatrix mInitJointMat;  // offset: 0x1d30
    s16 mQuake;  // offset: 0x1d70
    f32 mNearBlurLimit;  // offset: 0x1d74
    f32 mFarBlurLimit;  // offset: 0x1d78
    f32 mNear;  // offset: 0x1d7c
    f32 mFar;  // offset: 0x1d80
    f32 mFocal;  // offset: 0x1d84
    f32 mAimNearBlurLimit;  // offset: 0x1d88
    f32 mAimFarBlurLimit;  // offset: 0x1d8c
    f32 mAimNear;  // offset: 0x1d90
    f32 mAimFar;  // offset: 0x1d94
    f32 mAimFocal;  // offset: 0x1d98
    bool mMotionBlur;  // offset: 0x1d9c
    bool mInvalidAdjust;  // offset: 0x1d9d
    bool mInvAdjCam;  // offset: 0x1d9e
    bool mInvAdjTar;  // offset: 0x1d9f
protected:
    MtVector3 mAdjVecCam;  // offset: 0x1da0
    MtVector3 mAdjVecTar;  // offset: 0x1db0
public:
    static MyDTI DTI;
protected:
    static const u32 BUFFER_SIZE = 4128;
    static const u32 SEQ_INFO_MAX = 32;
};

class cCamImpAnimTar : public cCamImpAnim
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
    cCamImpAnimTar();
    virtual ~cCamImpAnimTar();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
private:
    bool calcAnimTarPos(MtVector3& lockonPos);
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamAnimTar* mpParamAnimTar;  // offset: 0x1dc0
    bool mIsInitMarginInter;  // offset: 0x1dc8
    cCamInterporateRangeAng mInterLockX;  // offset: 0x1dd0
    cCamInterporateRangeAng mInterLockY;  // offset: 0x1de8
    cCamInterporateRange mInterLockPos;  // offset: 0x1e00
public:
    static MyDTI DTI;
};

inline void* cCamExParamAnim::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamExParamAnim2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cCamExParamAnim2::cCamExParamAnim2() {
    this->::cCamExParam::mType = static_cast<nCameraGame::CAMERA_TYPE>(18);
}

inline void* cCamImpAnim::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpAnimTar::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cCamExParamAnim::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cCamExParamAnim::DTI);
}

inline MtAllocator* cCamExParamAnim2::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cCamExParamAnim2::DTI);
}

inline void cCamImpAnim::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCamImpAnim::DTI)->memFree(p_addr);
}

inline void cCamImpAnimTar::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCamImpAnimTar::DTI)->memFree(p_addr);
}
