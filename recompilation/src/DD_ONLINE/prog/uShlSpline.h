#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "nDDOUtility.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cShlParamSpline;
class uShlSpline;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamSpline : public cShlParamBase
{
public:
    enum
    {
        SO_HIT_SHL_OBJ_HIT = 1,
        SO_HIT_SHL_FLOOR_HIT = 2,
        SO_TURN_MOVE_VEC = 4,
        SO_NODE_SET_PROGRAM = 8,
        SO_SHL_SPLINE_LOOP = 16,
        SO_SHL_TARGET_PARABOLA = 32,
        SO_SHL_TOP_SLOW = 64,
        SO_SHL_USE_MY_NODE = 128,
        SO_SHL_FOLLOW_ME = 256,
        SO_SHL_PARENT_DIRECTION = 512,
        SO_SHL_END_STOP = 1024,
        SO_SHL_PARABOLA_X = 2048,
        SO_SPLINE_DEFAULT = 7,
    };
public:
    class MyDTI;
    class cSplineShlNodeParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSplineShlNodeParam : public MtObject
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
        cSplineShlNodeParam();
        virtual ~cSplineShlNodeParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtVector3 mOffset;  // offset: 0x10
        static MyDTI DTI;
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
    cShlParamSpline();
    virtual ~cShlParamSpline();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    bool isUIHide_putTypeParaboraHeight() const;
    bool isUIHide_putTypeTopSlow() const;
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addnodeList(const cShlParamSpline* pParam);  // vtable slot 12
public:
    f32 spd;  // offset: 0x160
    f32 spdMax;  // offset: 0x164
    f32 spdAccel;  // offset: 0x168
    f32 topSpeed;  // offset: 0x16c
    bool isValidLimit;  // offset: 0x170
    f32 limitDist;  // offset: 0x174
    f32 limitAngle;  // offset: 0x178
    bool isUpValidLimit;  // offset: 0x17c
    f32 limitUpAngle;  // offset: 0x180
    u32 dieFlag;  // offset: 0x184
    s32 hitShlNo;  // offset: 0x188
    s32 floorHitShlNo;  // offset: 0x18c
    u32 shlOptionSpline;  // offset: 0x190
    f32 followTime;  // offset: 0x194
    f32 parabolaHeight;  // offset: 0x198
    f32 mhokan;  // offset: 0x19c
    s32 epvNoScrHit;  // offset: 0x1a0
    cShlParamBase::HIT_MARK_TYPE scrHitEfType;  // offset: 0x1a4
    s32 seNoScrHit;  // offset: 0x1a8
    MtVector3 offset;  // offset: 0x1b0
    MtVector3 offsetRnd;  // offset: 0x1c0
    f32 mParabolaXAng;  // offset: 0x1d0
    MtArray nodeList;  // offset: 0x1d8
    static MyDTI DTI;
};

class uShlSpline : public uShlBase
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
    const cShlParamSpline* getShlParam() const;
    uShlSpline();
    virtual ~uShlSpline();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
protected:
    bool isDie();
    virtual void movePos();  // vtable slot 186
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    f32 getSpeed() const;
    void setSpeed(f32);
    f32 getSpeedAccel() const;
    void setSpeedAccel(f32);
    f32 getSpeedMax() const;
    void setSpeedMax(f32);
    void checkScr();
private:
    void setScrHitEfct(const MtVector3& pos, f32 scale);
public:
    void setSplineNode(nDDOUtility::cRNSpline<8>& spline);
private:
    f32 mTopReduce;  // offset: 0x2ab0
    MtMatrix mOldMat;  // offset: 0x2ac0
protected:
    bool mIsGoal;  // offset: 0x2b00
    bool mIsFirst;  // offset: 0x2b01
    f32 mSpeedZ;  // offset: 0x2b04
    f32 mSpeedAccel;  // offset: 0x2b08
    f32 mSpeedMax;  // offset: 0x2b0c
    f32 mDistance;  // offset: 0x2b10
    f32 mEndTimer;  // offset: 0x2b14
    nDDOUtility::cRNSpline<8> mSpline;  // offset: 0x2b20
public:
    static MyDTI DTI;
};

inline void* cShlParamSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamSpline::cShlParamSpline() {
    this->isValidLimit = false;
    this->spdAccel = 0.0f;
    this->topSpeed = 0.0f;
    this->spd = 0.0f;
    this->spdMax = 0.0f;
    this->limitDist = 200.0f;
    this->limitAngle = 45.0f;
    this->isUpValidLimit = false;
    this->limitUpAngle = 45.0f;
    this->dieFlag = 7;
    this->hitShlNo = -1;
    this->floorHitShlNo = -1;
    this->shlOptionSpline = 7;
    this->followTime = 90.0f;
    this->parabolaHeight = 500.0f;
    this->mhokan = 1.0f;
    this->epvNoScrHit = -1;
    this->scrHitEfType = static_cast<cShlParamBase::HIT_MARK_TYPE>(0);
    this->seNoScrHit = -1;
    this->mParabolaXAng = 0.0f;
    this->offsetRnd.z = 0.0f;
    this->offsetRnd.pad_ = 0.0f;
    this->offsetRnd.x = 0.0f;
    this->offsetRnd.y = 0.0f;
    this->offset.z = 0.0f;
    this->offset.pad_ = 0.0f;
    this->offset.x = 0.0f;
    this->offset.y = 0.0f;
    this->nodeList.mAutoDelete = true;
}

inline void* cShlParamSpline::cSplineShlNodeParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamSpline::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamSpline::DTI)->memAlloc(sz, align, ::cShlParamSpline::DTI.::MtDTI::getID());
}

inline void cShlParamSpline::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamSpline::DTI)->memFree(p_addr);
}

inline MtAllocator* cShlParamSpline::cSplineShlNodeParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cShlParamSpline::cSplineShlNodeParam::DTI);
}

inline cShlParamSpline::cSplineShlNodeParam::cSplineShlNodeParam() {
    this->mOffset = ::MtVector3::Zero;
}

inline void uShlSpline::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlSpline::DTI)->memFree(p_addr);
}
