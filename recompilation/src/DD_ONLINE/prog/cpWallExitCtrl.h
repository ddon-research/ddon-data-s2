#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cWallHitInfo;
class uDDOModel;

// Declarations
class cpWallExitCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpWallExitCtrl : public cpComponent
{
public:
    enum WALL_STATE
    {
        STATE_NONE = 0,
        STATE_ACTIVE_INIT = 1,
        STATE_ACTIVE_MOVE = 2,
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
    cpWallExitCtrl();
    virtual ~cpWallExitCtrl() {}
    virtual void setup();  // vtable slot 6
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    void callbackHitWall_Init(cWallHitInfo& hitInfo);
    void callbackHitWall_Move(cWallHitInfo& hitInfo);
    void callbackHitWall_Final(cWallHitInfo& hitInfo);
private:
    void resetWallInfo();
    void updateWallExit(cWallHitInfo& hitInfo);
    bool isIgnoreWallExit(cWallHitInfo& hitInfo) const;
private:
    WALL_STATE mWallState;  // offset: 0x50
    uDDOModel* mpModel;  // offset: 0x58
    f32 mWallHitTimer;  // offset: 0x60
    f32 mWallExitFrame;  // offset: 0x64
    f32 mMoveDir;  // offset: 0x68
    f32 mExitSpeed;  // offset: 0x6c
    f32 mExitSpeedMax;  // offset: 0x70
    f32 mExitAdd;  // offset: 0x74
public:
    static MyDTI DTI;
};

inline void* cpWallExitCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpWallExitCtrl::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpWallExitCtrl::DTI);
}

inline void cpWallExitCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpWallExitCtrl::DTI)->memFree(p_addr);
}
