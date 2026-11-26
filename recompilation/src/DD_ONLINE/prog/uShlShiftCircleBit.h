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
class uHuman;

// Declarations
class cShlParamShiftCircleBit;
class uShlShiftCircleBit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamShiftCircleBit : public cShlParamBase
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
    cShlParamShiftCircleBit();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mShiftCircleBitDistance;  // offset: 0x160
    f32 mShiftCircleBitPos;  // offset: 0x164
    f32 mTransparencyDistance;  // offset: 0x168
    f32 mTransparencyDistanceMax;  // offset: 0x16c
    f32 mTransparencyMax;  // offset: 0x170
    f32 mTransparencyMin;  // offset: 0x174
    static MyDTI DTI;
};

class uShlShiftCircleBit : public uShlBase
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
    const cShlParamShiftCircleBit* getShlParam() const;
    uShlShiftCircleBit();
    virtual ~uShlShiftCircleBit() {}
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    f32 getBitPos(uHuman& hm);
private:
    f32 mShiftCircleBitTimer;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

inline void* cShlParamShiftCircleBit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamShiftCircleBit::cShlParamShiftCircleBit() {
    this->mShiftCircleBitDistance = 100.0f;
    this->mShiftCircleBitPos = 0.0f;
    this->mTransparencyDistance = 100.0f;
    this->mTransparencyDistanceMax = 100.0f;
    this->mTransparencyMax = 1.0f;
    this->mTransparencyMin = 0.0f;
}

inline void* uShlShiftCircleBit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlShiftCircleBit::uShlShiftCircleBit() {
    this->mShiftCircleBitTimer = 0.0f;
}
