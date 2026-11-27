#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlBase.h"
#include "uShlCondition.h"
#include "uShlFollowMove.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;
class cShlParamFollowMove;
class uShlBase;
class uShlFollowMove;

// Declarations
class cShlParamCustomConditionBase;
class cShlParamCustomConditionFollowMove;
class uShlCustomConditionBase;
class uShlCustomConditionFollowMove;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cShlParamConditionBase = cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>;
using cShlParamConditionFollowMove = cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uShlConditionBase = uShlCondition<uShlBase>;
using uShlConditionFollowMove = uShlCondition<uShlFollowMove>;

class cShlParamCustomConditionBase : public cShlParamConditionBase
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
    cShlParamCustomConditionBase();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mHosei[10];  // offset: 0x190
    s32 mMyCustomSkillId;  // offset: 0x1b8
    static MyDTI DTI;
};

class cShlParamCustomConditionFollowMove : public cShlParamConditionFollowMove
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
    cShlParamCustomConditionFollowMove();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mHosei[10];  // offset: 0x1c0
    s32 mMyCustomSkillId;  // offset: 0x1e8
    static MyDTI DTI;
};

class uShlCustomConditionBase : public uShlConditionBase
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
    uShlCustomConditionBase();
    virtual ~uShlCustomConditionBase() {}
    virtual void initSub();  // vtable slot 177
public:
    s32 mOwnerSkillLv;  // offset: 0x2ad0
    static MyDTI DTI;
};

class uShlCustomConditionFollowMove : public uShlConditionFollowMove
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
    uShlCustomConditionFollowMove();
    virtual ~uShlCustomConditionFollowMove() {}
    virtual void initSub();  // vtable slot 177
public:
    s32 mOwnerSkillLv;  // offset: 0x2ae0
    static MyDTI DTI;
};

inline void* cShlParamCustomConditionBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCustomConditionBase::cShlParamCustomConditionBase() {
    for (u32 i = 0; i < 10u; i++) {
        mHosei[i] = 1.0f;
    }
    mMyCustomSkillId = -1;
}

inline void* cShlParamCustomConditionFollowMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCustomConditionFollowMove::cShlParamCustomConditionFollowMove() {
    for (u32 i = 0; i < 10u; i++) {
        mHosei[i] = 1.0f;
    }
    mMyCustomSkillId = -1;
}

inline void* uShlCustomConditionBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlCustomConditionFollowMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uShlCustomConditionBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlCustomConditionBase::DTI)->memFree(p_addr);
}

inline void uShlCustomConditionFollowMove::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlCustomConditionFollowMove::DTI)->memFree(p_addr);
}
