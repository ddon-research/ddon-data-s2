#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlCustomSpline.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cShlParamBase;

// Declarations
class cShlParamJob06CS13;
class uShlJob06CS13;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob06CS13 : public cShlParamCustomSpline
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
    cShlParamJob06CS13();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlJob06CS13 : public uShlCustomSpline
{
public:
    enum ICE_BARRETT_TYPE
    {
        ICE_BARRETT_TYPE_NONE = 0,
        ICE_BARRETT_FIRST = 1,
        ICE_BARRETT_SHOT_AFTER = 2,
        ICE_BARRETT_CHARGE = 3,
        ICE_BARRETT_CHARGE_SHOT = 4,
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
    const cShlParamJob06CS13* getShlParam() const;
    uShlJob06CS13();
    virtual ~uShlJob06CS13() {}
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void movePos();  // vtable slot 186
    void reqIceBarrettEfType(ICE_BARRETT_TYPE type);
private:
    void reqFinishEfct();
    cEfcHandle* reqBarrettEffect(const MtVector3& pos, s32 no);
private:
    cEfcHandle* mFirstEfcHnd;  // offset: 0x2cc8
    cEfcHandle* mShotAfterEfcHnd;  // offset: 0x2cd0
    cEfcHandle* mEndEfcHnd;  // offset: 0x2cd8
    cEfcHandle* mChargeEfcHnd;  // offset: 0x2ce0
    cEfcHandle* mChargeShotEfcHnd;  // offset: 0x2ce8
    ICE_BARRETT_TYPE mReqType;  // offset: 0x2cf0
    bool mAlreadyShot;  // offset: 0x2cf4
    bool mIsChargeShot;  // offset: 0x2cf5
    bool mIsReqEnd;  // offset: 0x2cf6
public:
    static MyDTI DTI;
};

inline void* cShlParamJob06CS13::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob06CS13::cShlParamJob06CS13() {
}

inline void* uShlJob06CS13::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob06CS13::uShlJob06CS13() {
    this->mIsReqEnd = false;
    this->mAlreadyShot = false;
    this->mIsChargeShot = false;
    this->mReqType = static_cast<uShlJob06CS13::ICE_BARRETT_TYPE>(0);
    this->mChargeShotEfcHnd = nullptr;
    this->mChargeEfcHnd = nullptr;
    this->mEndEfcHnd = nullptr;
    this->mShotAfterEfcHnd = nullptr;
    this->mFirstEfcHnd = nullptr;
}
