#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class uDDOModel;

// Declarations
class cpRotateCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpRotateCtrl : public cpComponent
{
    // inferred: uDDOModel::setDefaultRotateSpeed names cpRotateCtrl::mDefaultInterSpeed
    friend class uDDOModel;
public:
    enum INTER_MODE
    {
        INTER_MODE_NORMAL = 0,
        INTER_MODE_GAME_DELTATIME = 1,
        INTER_MODE_NUM = 2,
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
    cpRotateCtrl();
    virtual ~cpRotateCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void update();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setInterMode(INTER_MODE mode);
    void setFinalQuat(const MtQuaternion& FinalQuat, f32 speed);
    void setFinalQuatByFrame(const MtQuaternion& FinalQuat, f32 frame);
    void setFinalAngleY(f32 AngleY, f32 speed);
    void setFinalAngleYByFrame(f32 AngleY, f32 frame);
    void setFinalDir(const MtVector3& dir, f32 speed);
    void setFinalDirByFrame(const MtVector3& dir, f32 frame);
    void setFinalAimPos(const MtVector3& from, const MtVector3& to, f32 speed);
    void setFinalAimPosByFrame(const MtVector3& from, const MtVector3& to, f32 frame);
    void setSpeed(f32 speed);
    void setSpeedByFrame(f32 frame);
    const MtQuaternion& getFinalQuat();
    f32 getFinalAngleY();
    void setDefaultInterFrame(f32 InterFrame);
    f32 getDefaultInterFrame();
    void setDefaultInterSpeed(f32 InterSpeed);
    f32 getDefaultInterSpeed();
    void setInterSpeed(f32 InterSpeed);
    f32 getInterSpeed() const;
    bool isBusy();
    void setBusy(bool enable);
protected:
    f32 convertFrameToSpeed(const MtQuaternion& FinalQuat, f32 frame);
    f32 calcDiffAngle(const MtQuaternion& quat, const MtQuaternion& quat2) const;
public:
    uDDOModel* mpModel;  // offset: 0x50
protected:
    MtQuaternion mFinalQuat;  // offset: 0x60
    MtQuaternion mLastQuat;  // offset: 0x70
    f32 mInterSpeed;  // offset: 0x80
    f32 mDefaultInterFrame;  // offset: 0x84
    f32 mDefaultInterSpeed;  // offset: 0x88
    bool mIsBusy;  // offset: 0x8c
    INTER_MODE mInterMode;  // offset: 0x90
    f32 mAngleDiffThreshold;  // offset: 0x94
public:
    bool mDisableReset;  // offset: 0x98
    static MyDTI DTI;
};
