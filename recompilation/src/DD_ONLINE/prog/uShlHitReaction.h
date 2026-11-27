#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlCondition.h"
#include "uShlSpline.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;
class cShlParamBase;
class cShlParamStick;
class uDDOModel;
class uShlStick;

// Declarations
class cHitReaction;
class cShlParamHitReactionConditionStick;
class cShlParamHitReactionSpline;
class cShlParamHitReactionStick;
class uShlHitReactionConditionStick;
class uShlHitReactionSpline;
class uShlHitReactionStick;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cShlParamConditionStick = cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uShlConditionStick = uShlCondition<uShlStick>;

class cHitReaction
{
public:
    enum
    {
        SHL_CHECK_IN_EFC_MAX = 8,
    };
public:
    struct efcInControl;
public:
    struct efcInControl
    {
    public:
        u32 uId;  // offset: 0x0
        f32 clearTimer;  // offset: 0x4
    };
public:
    cHitReaction();
    ~cHitReaction();
    void initOwner(uDDOModel* pddomod);
    void update(f32 deltaTime);
    bool isCallEffect(cHitInfo* pHitInfo, f32 coolDown);
public:
    f32 mReactionCooldown;  // offset: 0x0
    efcInControl mCheckHitEfcCtrl[8];  // offset: 0x4
};

class cShlParamHitReactionConditionStick : public cShlParamConditionStick
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
    cShlParamHitReactionConditionStick();
    virtual ~cShlParamHitReactionConditionStick();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mCanChangeFrame;  // offset: 0x198
    s32 mChangeEffectNo;  // offset: 0x19c
    static MyDTI DTI;
};

class cShlParamHitReactionSpline : public cShlParamSpline
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
    cShlParamHitReactionSpline();
    virtual ~cShlParamHitReactionSpline() {}
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mCanChangeFrame;  // offset: 0x1f8
    s32 mChangeEffectNo;  // offset: 0x1fc
    static MyDTI DTI;
};

class cShlParamHitReactionStick : public cShlParamStick
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
    cShlParamHitReactionStick();
    virtual ~cShlParamHitReactionStick();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mCanChangeFrame;  // offset: 0x164
    s32 mChangeEffectNo;  // offset: 0x168
    static MyDTI DTI;
};

class uShlHitReactionConditionStick : public uShlConditionStick
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
    const cShlParamHitReactionConditionStick* getShlParam() const;
    uShlHitReactionConditionStick();
    virtual ~uShlHitReactionConditionStick();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
private:
    cHitReaction mHitReaction;  // offset: 0x2ad0
public:
    static MyDTI DTI;
};

class uShlHitReactionSpline : public uShlSpline
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
    const cShlParamHitReactionSpline* getShlParam() const;
    uShlHitReactionSpline();
    virtual ~uShlHitReactionSpline();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
private:
    cHitReaction mHitReaction;  // offset: 0x2cc0
public:
    static MyDTI DTI;
};

class uShlHitReactionStick : public uShlStick
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
    const cShlParamHitReactionStick* getShlParam() const;
    uShlHitReactionStick();
    virtual ~uShlHitReactionStick();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
private:
    cHitReaction mHitReaction;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

inline cHitReaction::~cHitReaction() {
}

inline void* cShlParamHitReactionConditionStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamHitReactionConditionStick::cShlParamHitReactionConditionStick() : mCanChangeFrame(0.0f), mChangeEffectNo(0) {
}

inline void* cShlParamHitReactionSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamHitReactionSpline::cShlParamHitReactionSpline() {
    this->mCanChangeFrame = 0.0f;
    this->mChangeEffectNo = 0;
}

inline void* cShlParamHitReactionStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamHitReactionStick::cShlParamHitReactionStick() {
    this->mCanChangeFrame = 0.0f;
    this->mChangeEffectNo = 0;
}

inline void* uShlHitReactionConditionStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlHitReactionSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlHitReactionStick::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamHitReactionSpline::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamHitReactionSpline::DTI)->memAlloc(sz, align, ::cShlParamHitReactionSpline::DTI.::MtDTI::getID());
}

inline void cShlParamHitReactionSpline::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamHitReactionSpline::DTI)->memFree(p_addr);
}

inline void* cShlParamHitReactionStick::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamHitReactionStick::DTI)->memAlloc(sz, align, ::cShlParamHitReactionStick::DTI.::MtDTI::getID());
}

inline void uShlHitReactionConditionStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlHitReactionConditionStick::DTI)->memFree(p_addr);
}

inline const cShlParamHitReactionConditionStick* uShlHitReactionConditionStick::getShlParam() const {
    return static_cast<const cShlParamHitReactionConditionStick*>(this->::uShlBase::mpShlParam2);
}

inline void uShlHitReactionSpline::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlHitReactionSpline::DTI)->memFree(p_addr);
}

inline const cShlParamHitReactionSpline* uShlHitReactionSpline::getShlParam() const {
    return static_cast<const cShlParamHitReactionSpline*>(this->::uShlBase::mpShlParam2);
}

inline void uShlHitReactionStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlHitReactionStick::DTI)->memFree(p_addr);
}

inline const cShlParamHitReactionStick* uShlHitReactionStick::getShlParam() const {
    return static_cast<const cShlParamHitReactionStick*>(this->::uShlBase::mpShlParam2);
}
