#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraGame.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamImpBase;
class uCameraGame;

// Declarations
class cCamExParamPhoto;
class cCamImpPhoto;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamPhoto : public cCamExParam
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
    cCamExParamPhoto();
    virtual ~cCamExParamPhoto();
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
public:
    static MyDTI DTI;
};

class cCamImpPhoto : public cCamImpBase
{
public:
    enum
    {
        PHOTO_MOVE_TYPE_NORMAL = 0,
        PHOTO_MOVE_TYPE_X = 1,
        PHOTO_MOVE_TYPE_Y = 2,
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
    cCamImpPhoto();
    virtual ~cCamImpPhoto();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
protected:
    void ctrlPhoto(MtVector3& camPos);
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamPhoto* mpParamPhoto;  // offset: 0xb0
    f32 mResetAngX;  // offset: 0xb8
    f32 mResetAngY;  // offset: 0xbc
    f32 mInitAngX;  // offset: 0xc0
    f32 mInitAngY;  // offset: 0xc4
    f32 mAngYOld;  // offset: 0xc8
    f32 mAngXOld;  // offset: 0xcc
    bool mIsFlipX;  // offset: 0xd0
    f32 mPhotoOffsetX;  // offset: 0xd4
    f32 mPhotoOffsetY;  // offset: 0xd8
    f32 mPhotoOffsetXNow;  // offset: 0xdc
    f32 mPhotoOffsetYNow;  // offset: 0xe0
    f32 mPhotoOffsetXOld;  // offset: 0xe4
    f32 mPhotoOffsetYOld;  // offset: 0xe8
    MtVector3 mCamPosOld;  // offset: 0xf0
    MtVector3 mTarPosOld;  // offset: 0x100
    f32 mPhotoDistance;  // offset: 0x110
    MtVector3 mPhotoTargetPos;  // offset: 0x120
    f32 mPhotoDistanceOld;  // offset: 0x130
    u32 mPhotoMoveType;  // offset: 0x134
    bool mMoveSuccess;  // offset: 0x138
public:
    static MyDTI DTI;
};

inline void* cCamExParamPhoto::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpPhoto::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
