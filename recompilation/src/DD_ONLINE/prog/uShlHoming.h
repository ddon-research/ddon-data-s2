#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamHoming;
class cShlParamJob08CS12Npc;
class uShlHoming;
class uShlJob08CS12Npc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamHoming : public cShlParamSpeed
{
public:
    enum HOMING_TYPE
    {
        HT_SAME_TARGET = 0,
        HT_HOMING_MOVE = 1,
        HT_HOMING_MOVE_ROT = 2,
        HT_OWNER_TARGET = 3,
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamHoming();
    virtual ~cShlParamHoming();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isSpecifyTargetPos;  // offset: 0x1ed
    f32 hmgRad;  // offset: 0x1f0
    f32 hmgRadFrame;  // offset: 0x1f4
    f32 hmgBgnDist;  // offset: 0x1f8
    f32 hmgEndTargetDist;  // offset: 0x1fc
    f32 hmgEndRad;  // offset: 0x200
    f32 hmgEndFrame;  // offset: 0x204
    f32 hmgEndWaitHmgRad;  // offset: 0x208
    f32 hmgEndWaitSpdMax;  // offset: 0x20c
    f32 hmgEndWaitEndFrame;  // offset: 0x210
    f32 hmgEndHmgRad;  // offset: 0x214
    f32 hmgEndSpdMax;  // offset: 0x218
    HOMING_TYPE hmgType;  // offset: 0x21c
    f32 hmInitSpd;  // offset: 0x220
    f32 hmAccel;  // offset: 0x224
    f32 hmMaxSpped;  // offset: 0x228
    f32 hmHmgRad;  // offset: 0x22c
    f32 hmEndTargetDist;  // offset: 0x230
    f32 hmEndRad;  // offset: 0x234
    f32 hmRotate;  // offset: 0x238
    bool hmIsRotateRndFlip;  // offset: 0x23c
    s32 seNoHoming;  // offset: 0x240
    f32 homingSeDeg;  // offset: 0x244
    static MyDTI DTI;
};

class cShlParamJob08CS12Npc : public cShlParamHoming
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
    cShlParamJob08CS12Npc();
    virtual ~cShlParamJob08CS12Npc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 objHitShlNo;  // offset: 0x248
    static MyDTI DTI;
};

class uShlHoming : public uShlSpeed
{
public:
    enum HOMING_PHASE
    {
        HP_BGN = 0,
        HP_NOW = 1,
        HP_END = 2,
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
    const cShlParamHoming* getShlParam() const;
    uShlHoming();
    virtual ~uShlHoming();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void homingPosMove(f32 spd);  // vtable slot 190
    const MtVector3& getHomingPos() const;
    void setHomingPos(const MtVector3&);
    const MtVector3& getHomingMoveVec() const;
    void setHomingMoveVec(const MtVector3&);
    void addExHomingRadAdd(f32 rad);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
protected:
    virtual void movePosSub(f32 speed);  // vtable slot 186
    virtual void moveSpeedSub();  // vtable slot 187
    bool isEffectiveLockOnHoming();
private:
    HOMING_PHASE mHmgPhase;  // offset: 0x2b88
    f32 mHomingRad;  // offset: 0x2b8c
    f32 mHomingRadAdd;  // offset: 0x2b90
    f32 mHomingFrame;  // offset: 0x2b94
    u32 mHomingEndFlag;  // offset: 0x2b98
    f32 mHomingEndFrame;  // offset: 0x2b9c
    MtVector3 mHomingPos;  // offset: 0x2ba0
    HOMING_PHASE mHMHmgPhase;  // offset: 0x2bb0
    MtVector3 mHomingMoveVec;  // offset: 0x2bc0
    f32 mHMSpeed;  // offset: 0x2bd0
    f32 mHomingRadSE;  // offset: 0x2bd4
    f32 mExHomingRadAdd;  // offset: 0x2bd8
public:
    static MyDTI DTI;
};

class uShlJob08CS12Npc : public uShlHoming
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
    const cShlParamJob08CS12Npc* getShlParam() const;
    uShlJob08CS12Npc();
    virtual ~uShlJob08CS12Npc();
    virtual void updateSub();  // vtable slot 175
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
public:
    static MyDTI DTI;
};

inline void* cShlParamHoming::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamHoming::cShlParamHoming() : isSpecifyTargetPos(false), hmgRad(0.0f), hmgRadFrame(0.0f), hmgBgnDist(0.0f), hmgEndTargetDist(0.0f), hmgEndRad(0.0f), hmgEndFrame(0.0f), hmgEndWaitHmgRad(-1.0f), hmgEndWaitSpdMax(-1.0f), hmgEndWaitEndFrame(-1.0f), hmgEndHmgRad(-1.0f), hmgEndSpdMax(-1.0f), hmgType(static_cast<cShlParamHoming::HOMING_TYPE>(0)), hmInitSpd(0.0f), hmAccel(0.0f), hmMaxSpped(0.0f), hmHmgRad(0.0f), hmEndTargetDist(0.0f), hmEndRad(0.0f), hmRotate(0.0f), hmIsRotateRndFlip(false), seNoHoming(-1), homingSeDeg(30.0f) {
}

inline void* cShlParamJob08CS12Npc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob08CS12Npc::cShlParamJob08CS12Npc() : objHitShlNo(-1) {
}

inline void* uShlHoming::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlJob08CS12Npc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob08CS12Npc::uShlJob08CS12Npc() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* uShlHoming::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlHoming::DTI)->memAlloc(sz, align, ::uShlHoming::DTI.::MtDTI::getID());
}

inline void uShlHoming::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlHoming::DTI)->memFree(p_addr);
}

inline void* uShlJob08CS12Npc::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob08CS12Npc::DTI)->memAlloc(sz, align, ::uShlJob08CS12Npc::DTI.::MtDTI::getID());
}

inline void uShlJob08CS12Npc::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob08CS12Npc::DTI)->memFree(p_addr);
}

inline const cShlParamJob08CS12Npc* uShlJob08CS12Npc::getShlParam() const {
    return static_cast<const cShlParamJob08CS12Npc*>(this->::uShlBase::mpShlParam2);
}
