#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "nMotion.h"
#include "uCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
namespace nMotion { struct CPARAM_WORK; }
namespace nMotion { struct MPARAM_WORK; }
class rCameraList;
class uCoord;

// Declarations
class uMotionCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uMotionCamera : public uCamera
{
public:
    enum FOV_TYPE
    {
        FOV_VERT = 0,
        FOV_HORZ = 1,
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
    uMotionCamera();
    virtual ~uMotionCamera();
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void setCameraList(rCameraList* pcam);
    rCameraList* getCameraList();
    virtual MtMatrix getViewMat();  // vtable slot 25
    virtual MtMatrix getProjMat();  // vtable slot 26
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getCutNo();
    void setCutNo(u32 no);
    void setRepeat(bool);
    void setCutRepeat(bool);
    f32 getFrame();
    void setFrame(f32 v);
    f32 getFrameMax();
    void setOffsetPos(const MtVector3&);
    const MtVector3& getOffsetPos() const;
    f32 getSpeed();
    void setSpeed(f32);
    f32 getRoll();
    void setRoll(f32);
    const MtVector3& getTrackPos() const;
    const MtVector3& getTrackTarget() const;
    void setParentCoordUnit(uCoord* parent, const s32 joint_no);
protected:
    MtVector3 mOffsetPos;  // offset: 0xb0
    MtVector3 mTrackPos;  // offset: 0xc0
    MtVector3 mTrackTarget;  // offset: 0xd0
    f32 mZoom;  // offset: 0xe0
    f32 mRoll;  // offset: 0xe4
    u32 mCut;  // offset: 0xe8
    f32 mFrame;  // offset: 0xec
    f32 mSpeed;  // offset: 0xf0
    u32 mFovType;  // offset: 0xf4
    bool mTrackLink;  // offset: 0xf8
    bool mRepeat;  // offset: 0xf9
    bool mCutRepeat;  // offset: 0xfa
    bool mShowPath;  // offset: 0xfb
    bool mShowLineOfSight;  // offset: 0xfc
    rCameraList* mpCameraList;  // offset: 0x100
    uCoord* mpParent;  // offset: 0x108
    s32 mParentNo;  // offset: 0x110
    u32 mPrevCut;  // offset: 0x114
    nMotion::MPARAM_WORK mMot_work_pos;  // offset: 0x118
    nMotion::MPARAM_WORK mMot_work_target;  // offset: 0x138
    nMotion::MPARAM_WORK mMot_work_quat;  // offset: 0x158
    nMotion::CPARAM_WORK mMot_work_fov;  // offset: 0x178
public:
    static MyDTI DTI;
protected:
    static const u32 UNDEF_CUT = 4294967295;
};

inline void* uMotionCamera::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rCameraList* uMotionCamera::getCameraList() {
    return this->mpCameraList;
}
