#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtPrimitive3D.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtSphere;
class MtVector3;
class rEmWeakSafe;
class uDDOModel;

// Declarations
class cpWallMaria;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpWallMaria : public cpComponent
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
    cpWallMaria();
    virtual ~cpWallMaria();
    virtual void setup();  // vtable slot 6
    virtual void after();  // vtable slot 15
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void onWallMaria();
    void offWallMaria();
    bool isEnableWallMaria() const;
    const MtVector3& getPushVelocity() const;
    void setResource(rEmWeakSafe* pRes);
    void setSphereScale(const f32 scale);
private:
    bool mIsEnableWallMaria;  // offset: 0x50
    bool mIsOldPosEnable;  // offset: 0x51
    s32 mParentJntNo;  // offset: 0x54
    s32 mSafeJntNo;  // offset: 0x58
    MtSphere mSphere;  // offset: 0x60
    MtSphere mSphereSafe;  // offset: 0x70
    MtVector3 mOldPos;  // offset: 0x80
    MtVector3 mPushVel;  // offset: 0x90
    MtVector3 mOffset;  // offset: 0xa0
    uDDOModel* mpModel;  // offset: 0xb0
    rEmWeakSafe* mpWeakSafe;  // offset: 0xb8
public:
    static MyDTI DTI;
};

inline void* cpWallMaria::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpWallMaria::onWallMaria() {
    this->mIsEnableWallMaria = true;
}
