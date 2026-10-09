#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"
#include "nMotion.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtQuaternion;
class MtStream;
class MtVector3;
namespace nMotion { struct CURVE_PARAM; }
namespace nMotion { struct MOTION_PARAM; }

// Declarations
class rCameraList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rCameraList : public cResource
{
public:
    class MyDTI;
    struct CAMERA_LIST_HDR;
    class CAMERA_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CAMERA_LIST_HDR
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 camera_num;  // offset: 0x6
        rCameraList::CAMERA_INFO* pcamera[1];  // offset: 0x8
    };
public:
    class CAMERA_INFO
    {
    public:
        MtVector3 getPos(f32 f) const;
        MtVector3 getTarget(f32 f) const;
        MtQuaternion getQuat(f32 f) const;
        f32 getFov(f32 f) const;
        const nMotion::MOTION_PARAM* getPos() const;
        const nMotion::MOTION_PARAM* getTarget() const;
        const nMotion::MOTION_PARAM* getQuat() const;
        const nMotion::CURVE_PARAM* getFov() const;
        u32 getFovType() const;
        u32 getFrameNum() const;
        s32 getUserData(u32) const;
    public:
        s32 userdata[8];  // offset: 0x0
        u32 frame_num;  // offset: 0x20
        u32 fovtype;  // offset: 0x24
        f32 aspect;  // offset: 0x28
        u32 padding;  // offset: 0x2c
        nMotion::MOTION_PARAM mot_pos;  // offset: 0x30
        nMotion::MOTION_PARAM mot_target;  // offset: 0x60
        nMotion::MOTION_PARAM mot_quat;  // offset: 0x90
        nMotion::CURVE_PARAM mot_fov;  // offset: 0xc0
        static const u32 MAX_USER_DATA = 8;
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
    rCameraList();
    virtual ~rCameraList();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    u32 getCameraNum() const;
    const CAMERA_INFO* getCameraInfo(u32 index) const;
protected:
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    CAMERA_LIST_HDR* mpHdr;  // offset: 0x70
public:
    static MyDTI DTI;
    static const u16 DATA_VERSION = 5;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK11rCameraList5MyDTI11newInstanceEv at 0x011c2090-0x011c20bd, code DWARF attributes to no inlined copy
inline rCameraList::rCameraList() {
    this->::cResource::mAttr = static_cast<u32>(18);
    this->mpHdr = static_cast<rCameraList::CAMERA_LIST_HDR*>(nullptr);
}
