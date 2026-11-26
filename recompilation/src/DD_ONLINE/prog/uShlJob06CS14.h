#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;

// Declarations
class cShlParamJob06CS14;
class uShlJob06CS14;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob06CS14 : public cShlParamBase
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
    cShlParamJob06CS14();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlJob06CS14 : public uShlBase
{
public:
    enum ICE_BARRETT_TYPE
    {
        ANCHOR_FIRST = 0,
        ANCHOR_ACTIVE_AFTER = 1,
        ANCHOR_ACTIVE = 2,
        ANCHOR_ACTIVE_LV2 = 3,
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
    const cShlParamJob06CS14* getShlParam() const;
    uShlJob06CS14();
    virtual ~uShlJob06CS14() {}
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    void reqAnchorEfType(ICE_BARRETT_TYPE type);
private:
    void reqFinishEfct();
    cEfcHandle* reqAnchorEffect(const MtVector3& pos, s32 no);
private:
    cEfcHandle* mFirstEfcHnd;  // offset: 0x2ab0
    cEfcHandle* mShotAfterEfcHnd;  // offset: 0x2ab8
    cEfcHandle* mEndEfcHnd;  // offset: 0x2ac0
    cEfcHandle* mChargeEfcHnd;  // offset: 0x2ac8
    cEfcHandle* mChargeShotEfcHnd;  // offset: 0x2ad0
    bool mAlreadyShot;  // offset: 0x2ad8
    bool mIsChargeShot;  // offset: 0x2ad9
public:
    static MyDTI DTI;
};

inline void* cShlParamJob06CS14::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob06CS14::cShlParamJob06CS14() {
}

inline void* uShlJob06CS14::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob06CS14::uShlJob06CS14() {
    this->mAlreadyShot = false;
    this->mIsChargeShot = false;
    this->mChargeShotEfcHnd = nullptr;
    this->mChargeEfcHnd = nullptr;
    this->mEndEfcHnd = nullptr;
    this->mShotAfterEfcHnd = nullptr;
    this->mFirstEfcHnd = nullptr;
}
