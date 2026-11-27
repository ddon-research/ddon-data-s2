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
class cShlParamDamageSync;
class cShlParamDamageSyncBreak;
class cShlParamDamageSyncCtrl;
class uShlDamageSync;
class uShlDamageSyncBreak;
class uShlDamageSyncCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamDamageSync : public cShlParamBase
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
    cShlParamDamageSync();
    virtual ~cShlParamDamageSync();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class cShlParamDamageSyncBreak : public cShlParamBase
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
    cShlParamDamageSyncBreak();
    virtual ~cShlParamDamageSyncBreak();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class cShlParamDamageSyncCtrl : public cShlParamBase
{
public:
    enum
    {
        SYNC_OPTION_KILL_WHEN_SYNC_ATTAK = 1,
        SYNC_OPTION_LOCKED_MAGIC = 2,
        SYNC_OPTION_PUSH_IGNORE_OWNER = 4,
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
    cShlParamDamageSyncCtrl();
    virtual ~cShlParamDamageSyncCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    u32 mShlNum;  // offset: 0x160
    f32 mIntervalTime;  // offset: 0x164
    u32 mSyncOption;  // offset: 0x168
    s32 mShlNo;  // offset: 0x16c
    s32 mShlNoBreak;  // offset: 0x170
    f32 mFirstIntervalTime;  // offset: 0x174
    s32 mPushCollisionNo;  // offset: 0x178
    u32 mPushGroup;  // offset: 0x17c
    static MyDTI DTI;
};

class uShlDamageSync : public uShlBase
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
    const cShlParamDamageSync* getShlParam() const;
    uShlDamageSync();
    virtual ~uShlDamageSync() {}
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    void setSyncParent(uShlDamageSyncCtrl* pShl);
protected:
    virtual void eventCreatedBreakShl(uShlBase& shl);  // vtable slot 184
private:
    uShlDamageSyncCtrl* mpShlParent;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

class uShlDamageSyncBreak : public uShlBase
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
    const cShlParamDamageSyncBreak* getShlParam() const;
    uShlDamageSyncBreak();
    virtual ~uShlDamageSyncBreak() {}
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    void setSyncParent(uShlDamageSyncCtrl* pShl);
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
private:
    uShlDamageSyncCtrl* mpShlParent;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

class uShlDamageSyncCtrl : public uShlBase
{
    friend class uShlDamageSyncBreak;
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
    const cShlParamDamageSyncCtrl* getShlParam() const;
    uShlDamageSyncCtrl();
    virtual ~uShlDamageSyncCtrl() {}
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    void callbackSyncAttack();
    void setChildBreak(uShlDamageSyncBreak* pShl);
private:
    void createSyncShl();
    void setAddCollision(s32 index);
private:
    uShlBase* mpShlChild;  // offset: 0x2ab0
    uShlDamageSyncBreak* mpShlChildBreak;  // offset: 0x2ab8
    u32 mCurrentNum;  // offset: 0x2ac0
    f32 mShlSetFrame;  // offset: 0x2ac4
    bool mSyncAttack;  // offset: 0x2ac8
public:
    static MyDTI DTI;
};

inline void* cShlParamDamageSync::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamDamageSync::cShlParamDamageSync() {
}

inline void* cShlParamDamageSyncBreak::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamDamageSyncBreak::cShlParamDamageSyncBreak() {
}

inline void* cShlParamDamageSyncCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamDamageSyncCtrl::cShlParamDamageSyncCtrl() {
    this->mShlNum = 1;
    this->mIntervalTime = 30.0f;
    this->mShlNo = -1;
    this->mSyncOption = 0;
    this->mShlNoBreak = -1;
    this->mFirstIntervalTime = 0.0f;
    this->mPushCollisionNo = -1;
    this->mPushGroup = 0;
}

inline void* uShlDamageSync::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlDamageSync::uShlDamageSync() {
    this->mpShlParent = nullptr;
}

inline void* uShlDamageSyncBreak::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlDamageSyncBreak::uShlDamageSyncBreak() {
    this->mpShlParent = nullptr;
}

inline void uShlDamageSyncBreak::setSyncParent(uShlDamageSyncCtrl* pShl) {
    this->mpShlParent = pShl;
}

inline void* uShlDamageSyncCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlDamageSyncCtrl::uShlDamageSyncCtrl() {
    this->mSyncAttack = false;
    this->mCurrentNum = 0;
    this->mShlSetFrame = 0.0f;
    this->mpShlChildBreak = nullptr;
    this->mpShlChild = nullptr;
}

inline void uShlDamageSyncCtrl::callbackSyncAttack() {
    this->mSyncAttack = true;
}

inline void uShlDamageSyncCtrl::setChildBreak(uShlDamageSyncBreak* pShl) {
    this->mpShlChildBreak = pShl;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamDamageSync::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamDamageSync::DTI)->memAlloc(sz, align, ::cShlParamDamageSync::DTI.::MtDTI::getID());
}

inline void* cShlParamDamageSyncBreak::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamDamageSyncBreak::DTI)->memAlloc(sz, align, ::cShlParamDamageSyncBreak::DTI.::MtDTI::getID());
}

inline void* cShlParamDamageSyncCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamDamageSyncCtrl::DTI)->memAlloc(sz, align, ::cShlParamDamageSyncCtrl::DTI.::MtDTI::getID());
}

inline void* uShlDamageSync::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlDamageSync::DTI)->memAlloc(sz, align, ::uShlDamageSync::DTI.::MtDTI::getID());
}

inline void uShlDamageSync::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlDamageSync::DTI)->memFree(p_addr);
}

inline void* uShlDamageSyncBreak::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlDamageSyncBreak::DTI)->memAlloc(sz, align, ::uShlDamageSyncBreak::DTI.::MtDTI::getID());
}

inline void uShlDamageSyncBreak::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlDamageSyncBreak::DTI)->memFree(p_addr);
}

inline void* uShlDamageSyncCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlDamageSyncCtrl::DTI)->memAlloc(sz, align, ::uShlDamageSyncCtrl::DTI.::MtDTI::getID());
}

inline void uShlDamageSyncCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlDamageSyncCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamDamageSyncCtrl* uShlDamageSyncCtrl::getShlParam() const {
    return static_cast<const cShlParamDamageSyncCtrl*>(this->::uShlBase::mpShlParam2);
}
