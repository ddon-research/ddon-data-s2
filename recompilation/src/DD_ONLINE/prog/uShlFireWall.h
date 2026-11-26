#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "nDDOUtility.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cShlParamFireWallCtrl;
class uShlFireWallCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamFireWallCtrl : public cShlParamBase
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    cShlParamFireWallCtrl();
    virtual ~cShlParamFireWallCtrl();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 laserDist;  // offset: 0x160
    f32 laserRange;  // offset: 0x164
    f32 laserHeight;  // offset: 0x168
    f32 wallInter;  // offset: 0x16c
    f32 wallRandom;  // offset: 0x170
    f32 wait_0;  // offset: 0x174
    f32 wait_1;  // offset: 0x178
    f32 wait_2;  // offset: 0x17c
    f32 wait_3;  // offset: 0x180
    s32 shlNoWall;  // offset: 0x184
    s32 epvNoLight;  // offset: 0x188
    s32 seNoLoopL;  // offset: 0x18c
    s32 seNoLoopC;  // offset: 0x190
    s32 seNoLoopR;  // offset: 0x194
    s32 seNoLoopStopL;  // offset: 0x198
    s32 seNoLoopStopC;  // offset: 0x19c
    s32 seNoLoopStopR;  // offset: 0x1a0
    s32 seNoYochoL;  // offset: 0x1a4
    s32 seNoYochoR;  // offset: 0x1a8
    static MyDTI DTI;
};

class uShlFireWallCtrl : public uShlBase
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
    const cShlParamFireWallCtrl* getShlParam() const;
    uShlFireWallCtrl();
    virtual ~uShlFireWallCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
private:
    nDDOUtility::cRNSpline<8> mSpline;  // offset: 0x2ab0
    f32 mFrame;  // offset: 0x2c50
    u32 mRNoFireWall;  // offset: 0x2c54
    u32 mWallNum;  // offset: 0x2c58
    f32 mWaitFrame;  // offset: 0x2c5c
    MtVector3 mWallPos[10];  // offset: 0x2c60
    f32 mWallWait[10];  // offset: 0x2d00
public:
    static MyDTI DTI;
    static const u32 MAX_WALL_NUM = 10;
    static const f32 laserDist;
    static const f32 laserRange;
    static const f32 laserHeight;
};

inline void* cShlParamFireWallCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamFireWallCtrl::cShlParamFireWallCtrl() {
    this->laserDist = 0.0f;
    this->laserRange = 500.0f;
    this->laserHeight = 0.0f;
    this->wallInter = 200.0f;
    this->wallRandom = 6.0f;
    this->wait_0 = 40.0f;
    this->wait_1 = 19.0f;
    this->wait_2 = 48.0f;
    this->wait_3 = 200.0f;
    this->seNoYochoL = -1;
    this->seNoYochoR = -1;
    this->seNoLoopStopC = -1;
    this->seNoLoopStopR = -1;
    this->seNoLoopR = -1;
    this->seNoLoopStopL = -1;
    this->seNoLoopL = -1;
    this->seNoLoopC = -1;
    this->shlNoWall = -1;
    this->epvNoLight = -1;
}

inline void* uShlFireWallCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
