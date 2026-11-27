#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class MtVector4;
class cEfcHandle;

// Declarations
class cShlParamBreath;
class uShlBreath;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamBreath : public cShlParamBase
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
    cShlParamBreath();
    virtual ~cShlParamBreath();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyCollision(MtPropertyList& s);  // vtable slot 7
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    MtMatrix FireMatrix;  // offset: 0x160
    s32 mHitEpvIndex;  // offset: 0x1a0
    s32 mHitEpvNo;  // offset: 0x1a4
    f32 mHitStartSize;  // offset: 0x1a8
    f32 mHitLimitSize;  // offset: 0x1ac
    f32 mHitSizeChangeStartDist;  // offset: 0x1b0
    f32 mHitStepDist;  // offset: 0x1b4
    f32 mHitStepSize;  // offset: 0x1b8
    f32 dieDist;  // offset: 0x1bc
    u32 dieFlag;  // offset: 0x1c0
    f32 dirAdjustDist;  // offset: 0x1c4
    s32 hitShlNo;  // offset: 0x1c8
    s32 floorHitShlNo;  // offset: 0x1cc
    bool isEnchantShotSE;  // offset: 0x1d0
    s32 epvNoScrHit;  // offset: 0x1d4
    cShlParamBase::HIT_MARK_TYPE scrHitEfType;  // offset: 0x1d8
    s32 epvNoHitSlow;  // offset: 0x1dc
    s32 seNoScrHit;  // offset: 0x1e0
    s32 seNoHitSlow;  // offset: 0x1e4
    s32 seNoHitSlowStop;  // offset: 0x1e8
    f32 limitAngle;  // offset: 0x1ec
    bool mNoneLockOnShopType;  // offset: 0x1f0
    static MyDTI DTI;
};

class uShlBreath : public uShlBase
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
    const cShlParamBreath* getShlParam() const;
    uShlBreath();
    virtual ~uShlBreath();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
protected:
    bool isDie();
    void movePos();
    virtual void movePosSub(f32 Parabola) {}  // vtable slot 186
    virtual void moveParabolaSub() {}  // vtable slot 187
    virtual u32 getCollisionIndex() const;  // vtable slot 181
    virtual void floorHit(const MtVector3& hitPos) {}  // vtable slot 188
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void updateCollision();
    void checkScr();
private:
    void setScrHitEfct(const MtVector3& pos, f32 scale);
private:
    MtVector3 mStartPos;  // offset: 0x2ab0
    cEfcHandle* mpEpvHitHandle;  // offset: 0x2ac0
    s32 mHitEpvIndex;  // offset: 0x2ac8
    s32 mHitEpvNo;  // offset: 0x2acc
    s32 mHitSeqNo;  // offset: 0x2ad0
    MtVector4 mEpvCollPosList[8];  // offset: 0x2ae0
    cEfcHandle* mpHitSlowEfcHandle;  // offset: 0x2b60
    f32 mHitSlowEfctWait;  // offset: 0x2b68
    s32 mHitAdjustCount;  // offset: 0x2b6c
    bool mFirstCollisionEntry;  // offset: 0x2b70
public:
    static MyDTI DTI;
};

inline void* cShlParamBreath::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamBreath::cShlParamBreath() : FireMatrix(MtMatrix::Identity), mHitEpvIndex(-1), mHitEpvNo(-1), mHitStartSize(1.0f), mHitLimitSize(1.0f), mHitSizeChangeStartDist(0.0f), mHitStepDist(1.0f), mHitStepSize(0.0f), dieDist(0.0f), dieFlag(7u), dirAdjustDist(-1.0f), hitShlNo(-1), floorHitShlNo(-1), isEnchantShotSE(false), epvNoScrHit(-1), scrHitEfType(static_cast<cShlParamBase::HIT_MARK_TYPE>(0)), epvNoHitSlow(-1), seNoScrHit(-1), seNoHitSlow(-1), seNoHitSlowStop(-1), limitAngle(90.0f), mNoneLockOnShopType(false) {
}

inline void* uShlBreath::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlBreath::uShlBreath() {
    this->mpEpvHitHandle = nullptr;
    this->mHitEpvIndex = -1;
    this->mHitEpvNo = -1;
    this->mHitSeqNo = -1;
    this->mHitSlowEfctWait = 0.0f;
    this->mHitAdjustCount = 0;
    this->mpHitSlowEfcHandle = nullptr;
    this->mFirstCollisionEntry = true;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamBreath::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamBreath::DTI)->memAlloc(sz, align, ::cShlParamBreath::DTI.::MtDTI::getID());
}

inline void* uShlBreath::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlBreath::DTI)->memAlloc(sz, align, ::uShlBreath::DTI.::MtDTI::getID());
}

inline void uShlBreath::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlBreath::DTI)->memFree(p_addr);
}

inline const cShlParamBreath* uShlBreath::getShlParam() const {
    return static_cast<const cShlParamBreath*>(this->::uShlBase::mpShlParam2);
}
