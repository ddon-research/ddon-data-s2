#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cCamInterporate.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraGame.h"
#include "../../XFramework/uMotionCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamExParamMotTar;
class cCamImpBase;
class cCamInterporateRange;
class cCamInterporateRangeAng;
class uCameraGame;
class uHuman;
class uMotionCamera;

// Declarations
class cCamExParamMot;
class cCamImpMot;
class cCamImpMotTar;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamMot : public cCamExParam
{
public:
    enum OPTION
    {
        OP_END_MOTION = 1,
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
    cCamExParamMot();
    virtual ~cCamExParamMot();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    u32 mCutNo;  // offset: 0x1d4
    f32 mStartFrame;  // offset: 0x1d8
    u32 mOptionFlag;  // offset: 0x1dc
    static MyDTI DTI;
};

class cCamImpMot : public cCamImpBase
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
    cCamImpMot();
    virtual ~cCamImpMot();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
private:
    void calcHumanEditAdjustVec(uHuman* pPlayerBase, MtVector3& vec);
    void updateInitMat(bool isRotate);
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamMot* mpParamMot;  // offset: 0xb0
    uMotionCamera mMotCamera;  // offset: 0xc0
    MtMatrix mInitMat;  // offset: 0x260
    MtVector3 mAdjVecCam;  // offset: 0x2a0
    MtVector3 mAdjVecTar;  // offset: 0x2b0
public:
    static MyDTI DTI;
};

class cCamImpMotTar : public cCamImpMot
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
    cCamImpMotTar();
    virtual ~cCamImpMotTar();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamMotTar* mpParamMotTar;  // offset: 0x2c0
    bool mIsInitMarginInter;  // offset: 0x2c8
    cCamInterporateRangeAng mInterLockX;  // offset: 0x2d0
    cCamInterporateRangeAng mInterLockY;  // offset: 0x2e8
    cCamInterporateRange mInterLockPos;  // offset: 0x300
public:
    static MyDTI DTI;
};

inline void* cCamExParamMot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpMot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpMotTar::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
