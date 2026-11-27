#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nWeapon.h"
#include "../../XFramework/sCollision.h"
#include "uShlBase.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cShlParamBase;
class rSoundRequest;
class uCharacterBase;

// Declarations
class cShlParamArrow;
class cShlParamArrowInc;
class uShlArrow;
class uShlArrowInc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamArrow : public cShlParamSpeed
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
    cShlParamArrow();
    virtual ~cShlParamArrow();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool canExplode;  // offset: 0x1ed
    bool isRepelled;  // offset: 0x1ee
    f32 repelledDist;  // offset: 0x1f0
    s32 seNoMatHitSE;  // offset: 0x1f4
    u32 explodeShlType;  // offset: 0x1f8
    bool useModel;  // offset: 0x1fc
    static MyDTI DTI;
};

class cShlParamArrowInc : public cShlParamBase
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
    cShlParamArrowInc();
    virtual ~cShlParamArrowInc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlArrow : public uShlSpeed
{
public:
    enum ROUTINE
    {
        R_NORMAL = 0,
        R_RESTRICT = 1,
        R_SOFTEN = 2,
    };
    enum EPV_EXPLOSIVE
    {
        EPV_INDEX_EXPLOSIVE = 4,
        EPV_ID_EXPLOSIVE = 19,
    };
    enum SHL_EXPLOSIVE
    {
        SHL_PARAM_GRP_EXPLOSIVE = 7,
        SHL_PARAM_IDX_EXPLOSIVE_S = 0,
        SHL_PARAM_IDX_EXPLOSIVE_L = 5,
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
    const cShlParamArrow* getShlParam() const;
    uShlArrow();
    virtual ~uShlArrow();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void after();  // vtable slot 176
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    nWeapon::ARROW_TYPE getArrowType() const;
    void setArrowType(nWeapon::ARROW_TYPE type);
protected:
    virtual void floorHit(const MtVector3& hitPos);  // vtable slot 188
    virtual void setShlEfct();  // vtable slot 178
    virtual void requestShotSE();  // vtable slot 179
private:
    void setSPShl();
    void setRoutine(ROUTINE);
    void requestSpLandHitSE(sCollision::TriangleInfo* info);
    bool isRepelledDist() const;
    void setWaterHitEfct(const MtVector3& pos);
private:
    ROUTINE mRoutine;  // offset: 0x2b88
    f32 mTimer;  // offset: 0x2b8c
    u32 mExplosionLv;  // offset: 0x2b90
    u32 mExplosionType;  // offset: 0x2b94
    nWeapon::ARROW_TYPE mArrowType;  // offset: 0x2b98
    rSoundRequest* mprSECmn;  // offset: 0x2ba0
    uCharacterBase* mpHitAbsorbTarget;  // offset: 0x2ba8
    cEfcHandle* mpEfcExplosionHandle;  // offset: 0x2bb0
public:
    static MyDTI DTI;
};

class uShlArrowInc : public uShlBase
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
    const cShlParamArrowInc* getShlParam() const;
    uShlArrowInc();
    virtual ~uShlArrowInc();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
public:
    static MyDTI DTI;
};

inline void* cShlParamArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamArrow::cShlParamArrow() {
    this->canExplode = true;
    this->isRepelled = false;
    this->repelledDist = 1800.0f;
    this->seNoMatHitSE = -1;
    this->explodeShlType = 2;
    this->useModel = true;
}

inline void* cShlParamArrowInc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamArrowInc::cShlParamArrowInc() {
}

inline void* uShlArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlArrow::uShlArrow() {
    this->mArrowType = static_cast<nWeapon::ARROW_TYPE>(0);
    this->mExplosionLv = 0;
    this->mExplosionType = 0;
    this->mRoutine = static_cast<uShlArrow::ROUTINE>(0);
    this->mTimer = 0.0f;
    this->mpEfcExplosionHandle = nullptr;
    this->mpHitAbsorbTarget = nullptr;
    this->mprSECmn = nullptr;
}

inline void uShlArrow::setArrowType(nWeapon::ARROW_TYPE type) {
    this->mArrowType = type;
}

inline void* uShlArrowInc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlArrowInc::uShlArrowInc() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamArrow::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamArrow::DTI)->memAlloc(sz, align, ::cShlParamArrow::DTI.::MtDTI::getID());
}

inline void* cShlParamArrowInc::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamArrowInc::DTI)->memAlloc(sz, align, ::cShlParamArrowInc::DTI.::MtDTI::getID());
}

inline void* uShlArrow::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlArrow::DTI)->memAlloc(sz, align, ::uShlArrow::DTI.::MtDTI::getID());
}

inline void uShlArrow::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlArrow::DTI)->memFree(p_addr);
}

inline void* uShlArrowInc::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlArrowInc::DTI)->memAlloc(sz, align, ::uShlArrowInc::DTI.::MtDTI::getID());
}

inline void uShlArrowInc::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlArrowInc::DTI)->memFree(p_addr);
}
