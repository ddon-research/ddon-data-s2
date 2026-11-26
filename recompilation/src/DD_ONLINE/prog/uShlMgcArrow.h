#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "nHumanBow.h"
#include "uShlHoming.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamJob08CS13;
class cShlParamMgcArrow;
class uShlJob08CS13;
class uShlMgcArrow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamMgcArrow : public cShlParamHoming
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
    cShlParamMgcArrow();
    virtual ~cShlParamMgcArrow();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isHitCheckNextShl;  // offset: 0x248
    bool isHitScrSameShl;  // offset: 0x249
    s32 hitcheckShl_charge0;  // offset: 0x24c
    s32 hitcheckShl_charge1;  // offset: 0x250
    s32 hitcheckShl_charge2;  // offset: 0x254
    s32 hitcheckShl_just;  // offset: 0x258
    u32 mgcArrowhitAttr;  // offset: 0x25c
    bool isHitScrNextShl;  // offset: 0x260
    s32 hitScrShl_charge0;  // offset: 0x264
    s32 hitScrShl_charge1;  // offset: 0x268
    s32 hitScrShl_charge2;  // offset: 0x26c
    s32 hitScrShl_just;  // offset: 0x270
    bool isUndeadShl;  // offset: 0x274
    s32 undeadShl_charge0;  // offset: 0x278
    s32 undeadShl_charge1;  // offset: 0x27c
    s32 undeadShl_charge2;  // offset: 0x280
    s32 undeadShl_just;  // offset: 0x284
    bool isCoreShl;  // offset: 0x288
    s32 coreShl_charge0;  // offset: 0x28c
    s32 coreShl_charge1;  // offset: 0x290
    s32 coreShl_charge2;  // offset: 0x294
    s32 coreShl_just;  // offset: 0x298
    bool isLevelScale;  // offset: 0x29c
    f32 scale1;  // offset: 0x2a0
    f32 scale2;  // offset: 0x2a4
    f32 scale3;  // offset: 0x2a8
    f32 scale4;  // offset: 0x2ac
    f32 scale5;  // offset: 0x2b0
    f32 scale6;  // offset: 0x2b4
    f32 scale7;  // offset: 0x2b8
    f32 scale8;  // offset: 0x2bc
    f32 scale9;  // offset: 0x2c0
    f32 scale10;  // offset: 0x2c4
    bool isCs11;  // offset: 0x2c8
    s32 epvNoCs11Miss;  // offset: 0x2cc
    s32 seNoCs11Success;  // offset: 0x2d0
    s32 seNoCs11Miss;  // offset: 0x2d4
    static MyDTI DTI;
};

class uShlMgcArrow : public uShlHoming
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
    const cShlParamMgcArrow* getShlParam() const;
    uShlMgcArrow();
    virtual ~uShlMgcArrow();
    virtual void updateSub();  // vtable slot 175
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
private:
    void hitShlCreate(cHitInfo* pHitInfo);
public:
    void setMgcChargeLv(nHumanBow::MGC_BOW_CHARGE_LV lv);
    f32 getCustomSkillLevelScale();
    s32 getCheckHitShlIndex();
    s32 getScrHitShlIndex();
    s32 getCheckHitUndeadShlIndex();
    s32 getCheckHitCoreShlIndex();
private:
    bool mIsNextCreate;  // offset: 0x2bdc
    nHumanBow::MGC_BOW_CHARGE_LV mMgcChargeLv;  // offset: 0x2be0
public:
    static MyDTI DTI;
};

class cShlParamJob08CS13 : public cShlParamMgcArrow
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
    cShlParamJob08CS13();
    virtual ~cShlParamJob08CS13();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 checkColForLockOnTarget;  // offset: 0x2d8
    static MyDTI DTI;
};

class uShlJob08CS13 : public uShlMgcArrow
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
    const cShlParamJob08CS13* getShlParam() const;
    uShlJob08CS13();
    virtual ~uShlJob08CS13();
    virtual void setup();  // vtable slot 6
private:
    void setupLockOnInfo();
public:
    static MyDTI DTI;
};

inline void* cShlParamJob08CS13::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob08CS13::cShlParamJob08CS13() : checkColForLockOnTarget(1065353216) {
}

inline void* cShlParamMgcArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMgcArrow::cShlParamMgcArrow() : isHitCheckNextShl(false), isHitScrSameShl(false), hitcheckShl_charge0(-1), hitcheckShl_charge1(-1), hitcheckShl_charge2(-1), hitcheckShl_just(-1), mgcArrowhitAttr(0u), isHitScrNextShl(false), hitScrShl_charge0(-1), hitScrShl_charge1(-1), hitScrShl_charge2(-1), hitScrShl_just(-1), isUndeadShl(false), undeadShl_charge0(-1), undeadShl_charge1(-1), undeadShl_charge2(-1), undeadShl_just(-1), isCoreShl(false), coreShl_charge0(-1), coreShl_charge1(-1), coreShl_charge2(-1), coreShl_just(-1), isLevelScale(false), scale1(1.0f), scale2(1.0f), scale3(1.0f), scale4(1.0f), scale5(1.0f), scale6(1.0f), scale7(1.0f), scale8(1.0f), scale9(1.0f), scale10(1.0f), isCs11(false), epvNoCs11Miss(-1), seNoCs11Success(-1), seNoCs11Miss(-1) {
}

inline void* uShlJob08CS13::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob08CS13::uShlJob08CS13() {
}

inline void* uShlMgcArrow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlMgcArrow::uShlMgcArrow() {
    this->mIsNextCreate = false;
    this->mMgcChargeLv = static_cast<nHumanBow::MGC_BOW_CHARGE_LV>(0);
}
