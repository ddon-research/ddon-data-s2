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
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;

// Declarations
class cShlParamJob06CS12;
class uShlJob06CS12;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob06CS12 : public cShlParamBase
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
    cShlParamJob06CS12();
    virtual ~cShlParamJob06CS12();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 attackTimingFrame;  // offset: 0x160
    f32 finishTimingFrame;  // offset: 0x164
    s32 shotEffectElementNo;  // offset: 0x168
    s32 attackEffectElementNo;  // offset: 0x16c
    s32 endEffectElementNo;  // offset: 0x170
    s32 scrEffectElementNo;  // offset: 0x174
    s32 shotSoundElementNo;  // offset: 0x178
    s32 attackSoundElementNo;  // offset: 0x17c
    s32 attack2SoundElementNo;  // offset: 0x180
    s32 endSoundElementNo;  // offset: 0x184
    s32 effectSize;  // offset: 0x188
    static MyDTI DTI;
};

class uShlJob06CS12 : public uShlBase
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
    const cShlParamJob06CS12* getShlParam() const;
    uShlJob06CS12();
    virtual ~uShlJob06CS12();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
private:
    cEfcHandle* requestShotEffect(const MtVector3& pos, s32 no);
    cEfcHandle* requestLandEffect(const MtVector3& pos, s32 no);
    void requestShotSound(s32 no);
    void requestLoopSound(s32 no);
private:
    bool mIsAttacked;  // offset: 0x2ab0
    bool mIsEnded;  // offset: 0x2ab1
    f32 mEffectTimer;  // offset: 0x2ab4
    MtVector3 mGroundPos;  // offset: 0x2ac0
    cEfcHandle* mShotEfcHnd;  // offset: 0x2ad0
    cEfcHandle* mAttackEfcHnd;  // offset: 0x2ad8
    cEfcHandle* mEndEfcHnd;  // offset: 0x2ae0
    cEfcHandle* mScrEfcHnd;  // offset: 0x2ae8
public:
    static MyDTI DTI;
};

inline void* cShlParamJob06CS12::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob06CS12::cShlParamJob06CS12() {
    this->attackTimingFrame = 1.0f;
    this->finishTimingFrame = 1.0f;
    this->effectSize = -1;
    this->attack2SoundElementNo = -1;
    this->endSoundElementNo = -1;
    this->shotSoundElementNo = -1;
    this->attackSoundElementNo = -1;
    this->endEffectElementNo = -1;
    this->scrEffectElementNo = -1;
    this->shotEffectElementNo = -1;
    this->attackEffectElementNo = -1;
}

inline void* uShlJob06CS12::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamJob06CS12::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamJob06CS12::DTI)->memAlloc(sz, align, ::cShlParamJob06CS12::DTI.::MtDTI::getID());
}

inline void uShlJob06CS12::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob06CS12::DTI)->memFree(p_addr);
}
