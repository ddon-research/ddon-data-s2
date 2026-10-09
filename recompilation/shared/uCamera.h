#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class MtVector4;
class uDOFFilter;

// Declarations
class uCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uCamera : public cUnit
{
    // inferred: uDOFFilter::setNear names uCamera::mNearPlane
    friend class uDOFFilter;
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
    uCamera();
    virtual ~uCamera();
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setCameraPos(const MtVector3& pos);
    void setTargetPos(const MtVector3& target);
    void setCameraUp(const MtVector3& up);
    MtVector3 getWorldPos();
    MtVector3 getWorldPosFast() const;
    virtual MtVector3 getWorldTargetPos();  // vtable slot 24
    MtVector3 getWorldTargetPosFast() const;
    const MtVector3& getCameraPos() const;
    const MtVector3& getTargetPos() const;
    const MtVector3& getCameraUp() const;
    void setFarPlane(f32 f);
    void setNearPlane(f32 n);
    f32 getFarPlane() const;
    f32 getNearPlane() const;
    void setFov(f32 fov);
    f32 getFov() const;
    void getNearPosition(MtVector4* pdst);
    f32 getAspect() const;
    void setAspect(f32 a);
    virtual MtMatrix getViewMat() = 0;  // vtable slot 25
    virtual MtMatrix getProjMat() = 0;  // vtable slot 26
protected:
    f32 mFarPlane;  // offset: 0x48
    f32 mNearPlane;  // offset: 0x4c
    f32 mAspect;  // offset: 0x50
    f32 mFov;  // offset: 0x54
    MtVector3 mCameraPos;  // offset: 0x60
    MtVector3 mCameraUp;  // offset: 0x70
    MtVector3 mTargetPos;  // offset: 0x80
    MtVector3 mWorldCameraPos;  // offset: 0x90
    MtVector3 mWorldTargetPos;  // offset: 0xa0
public:
    static MyDTI DTI;
};
