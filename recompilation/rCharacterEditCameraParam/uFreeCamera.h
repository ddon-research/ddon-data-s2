#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/uCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class uCoord;

// Declarations
class uFreeCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uFreeCamera : public uCamera
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
    uFreeCamera();
    virtual ~uFreeCamera();
    virtual void move();  // vtable slot 9
    // Address: 0x01ad3060 - 0x01ad3061 (1 bytes)
    virtual void sync() {}  // vtable slot 11
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtMatrix getViewMat();  // vtable slot 25
    virtual MtMatrix getProjMat();  // vtable slot 26
    virtual MtVector3 getWorldTargetPos();  // vtable slot 24
    void setParentCoordUnit(uCoord* parent, const s32 joint_no);
    void setTargetCoordUnit(uCoord* target, const s32 joint_no);
    void setControlPad(s32);
    s32 setControlPad();
    void setControlSpeed(const MtVector3&);
    const MtVector3& getControlSpeed();
    bool isPadControl();
    void setPadControl(bool);
protected:
    uCoord* mpParent;  // offset: 0xb0
    s32 mParentNo;  // offset: 0xb8
    uCoord* mpTarget;  // offset: 0xc0
    s32 mTargetNo;  // offset: 0xc8
    s32 mControlPad;  // offset: 0xcc
    MtVector3 mControlSpeed;  // offset: 0xd0
    bool mPadControl;  // offset: 0xe0
public:
    static MyDTI DTI;
};
