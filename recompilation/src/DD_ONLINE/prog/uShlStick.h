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
class cHitInfo;

// Declarations
class cShlParamStick;
class cShlParamStickCtrl;
class uShlStick;
class uShlStickCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamStick : public cShlParamBase
{
public:
    enum
    {
        SSO_STICK_OWNER_DEAD_KILL = 1,
        SSO_HIT_STICK_OWNER_ONLY = 2,
        SSO_NO_HIT_STICK_OWNER = 4,
        SSO_DEFAULT = 1,
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
    cShlParamStick();
    virtual ~cShlParamStick();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    u32 stickOption;  // offset: 0x160
    static MyDTI DTI;
};

class cShlParamStickCtrl : public cShlParamBase
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
    cShlParamStickCtrl();
    virtual ~cShlParamStickCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    u32 stickShlNo;  // offset: 0x160
    s32 noConstShlNo;  // offset: 0x164
    bool isControl;  // offset: 0x168
    bool isInheritStickInfo;  // offset: 0x169
    bool isCallNotHitEndShl;  // offset: 0x16a
    static MyDTI DTI;
};

class uShlStick : public uShlBase
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
    const cShlParamStick* getShlParam() const;
    uShlStick();
    virtual ~uShlStick();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
protected:
    virtual void updateStickPos();  // vtable slot 186
    virtual void updateStickAngle();  // vtable slot 187
public:
    static MyDTI DTI;
};

class uShlStickCtrl : public uShlBase
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
    const cShlParamStickCtrl* getShlParam() const;
    uShlStickCtrl();
    virtual ~uShlStickCtrl();
    virtual void sync();  // vtable slot 11
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
private:
    bool mIsOnce;  // offset: 0x2ab0
    bool mIsAlreadyKill;  // offset: 0x2ab1
public:
    static MyDTI DTI;
};

inline void* cShlParamStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamStick::cShlParamStick() {
    this->stickOption = 1;
}

inline void* cShlParamStickCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamStickCtrl::cShlParamStickCtrl() {
    this->stickShlNo = 0;
    this->noConstShlNo = -1;
    this->isControl = false;
    this->isInheritStickInfo = false;
    this->isCallNotHitEndShl = false;
}

inline void* uShlStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlStick::uShlStick() {
}

inline void* uShlStickCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlStickCtrl::uShlStickCtrl() {
    this->mIsOnce = false;
    this->mIsAlreadyKill = false;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamStick::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamStick::DTI)->memAlloc(sz, align, ::cShlParamStick::DTI.::MtDTI::getID());
}

inline void* cShlParamStickCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamStickCtrl::DTI)->memAlloc(sz, align, ::cShlParamStickCtrl::DTI.::MtDTI::getID());
}

inline void* uShlStick::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlStick::DTI)->memAlloc(sz, align, ::uShlStick::DTI.::MtDTI::getID());
}

inline void uShlStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlStick::DTI)->memFree(p_addr);
}

inline const cShlParamStick* uShlStick::getShlParam() const {
    return static_cast<const cShlParamStick*>(this->::uShlBase::mpShlParam2);
}

inline void* uShlStickCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlStickCtrl::DTI)->memAlloc(sz, align, ::uShlStickCtrl::DTI.::MtDTI::getID());
}

inline void uShlStickCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlStickCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamStickCtrl* uShlStickCtrl::getShlParam() const {
    return static_cast<const cShlParamStickCtrl*>(this->::uShlBase::mpShlParam2);
}
