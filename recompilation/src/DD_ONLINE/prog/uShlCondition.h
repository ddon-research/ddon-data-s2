#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOGame.h"
#include "nObjCondition.h"
#include "uShlBase.h"
#include "uShlFollowMove.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;
class uShlBase;
class uShlFollowMove;
class uShlStick;

// Declarations
class cShlConditionInfo;
template <typename shlclass, typename ParentClass> class cShlParamCondition;
template <typename ParentClass> class uShlCondition;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlConditionInfo : public MtObject
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
    cShlConditionInfo();
    virtual ~cShlConditionInfo() {}
    void copy(const cShlConditionInfo& src);
public:
    bool mIsSetActiveTime;  // offset: 0x8
    f32 mActiveTime;  // offset: 0xc
    f32 mAdjustParam0;  // offset: 0x10
    f32 mAdjustParam1;  // offset: 0x14
    nDDOGame::ELEMENT_TYPE mElementType;  // offset: 0x18
    nObjCondition::IMMUNE_BOOST_LV mBoostLv;  // offset: 0x1c
    static MyDTI DTI;
};

template <>
class cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase> : public cShlParamBase
{
public:
    class MyDTI;
public:
    using ThisClass = cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamCondition();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isCondition;  // offset: 0x160
    bool isAdd;  // offset: 0x161
    u32 goodStatus;  // offset: 0x164
    u32 badStatus;  // offset: 0x168
    u32 HumanOriginalStatus;  // offset: 0x16c
    cShlConditionInfo mInfo;  // offset: 0x170
    static MyDTI DTI;
};

template <>
class cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove> : public cShlParamFollowMove
{
public:
    class MyDTI;
public:
    using ThisClass = cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamCondition();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isCondition;  // offset: 0x18c
    bool isAdd;  // offset: 0x18d
    u32 goodStatus;  // offset: 0x190
    u32 badStatus;  // offset: 0x194
    u32 HumanOriginalStatus;  // offset: 0x198
    cShlConditionInfo mInfo;  // offset: 0x1a0
    static MyDTI DTI;
};

template <>
class cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick> : public cShlParamStick
{
public:
    class MyDTI;
public:
    using ThisClass = cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamCondition();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isCondition;  // offset: 0x164
    bool isAdd;  // offset: 0x165
    u32 goodStatus;  // offset: 0x168
    u32 badStatus;  // offset: 0x16c
    u32 HumanOriginalStatus;  // offset: 0x170
    cShlConditionInfo mInfo;  // offset: 0x178
    static MyDTI DTI;
};

template <>
class uShlCondition<uShlBase> : public uShlBase
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    uShlCondition();
    virtual ~uShlCondition();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void reCreateInfo();  // vtable slot 186
public:
    cShlConditionInfo mInfo;  // offset: 0x2ab0
    static MyDTI DTI;
};

template <>
class uShlCondition<uShlFollowMove> : public uShlFollowMove
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    uShlCondition();
    virtual ~uShlCondition();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void reCreateInfo();  // vtable slot 186
public:
    cShlConditionInfo mInfo;  // offset: 0x2ac0
    static MyDTI DTI;
};

template <>
class uShlCondition<uShlStick> : public uShlStick
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static MtDTI* getMyDTIPtr();
    uShlCondition();
    virtual ~uShlCondition();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void reCreateInfo();  // vtable slot 188
public:
    cShlConditionInfo mInfo;  // offset: 0x2ab0
    static MyDTI DTI;
};

inline void* cShlConditionInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::cShlParamCondition() {
    isCondition = false;
    isAdd = false;
    goodStatus = 0u;
    badStatus = 0u;
    HumanOriginalStatus = 0u;
    mInfo.mIsSetActiveTime = false;
    mInfo.mActiveTime = 0.0f;
    mInfo.mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}

inline cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::cShlParamCondition() {
    isCondition = false;
    isAdd = false;
    goodStatus = 0u;
    badStatus = 0u;
    HumanOriginalStatus = 0u;
    mInfo.mIsSetActiveTime = false;
    mInfo.mActiveTime = 0.0f;
    mInfo.mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}

inline cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::cShlParamCondition() {
    isCondition = false;
    isAdd = false;
    goodStatus = 0u;
    badStatus = 0u;
    HumanOriginalStatus = 0u;
    mInfo.mIsSetActiveTime = false;
    mInfo.mActiveTime = 0.0f;
    mInfo.mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}

inline cShlConditionInfo::cShlConditionInfo() {
    this->mActiveTime = 10.0f;
    this->mAdjustParam0 = 1.0f;
    this->mAdjustParam1 = 0.0f;
    this->mElementType = static_cast<nDDOGame::ELEMENT_TYPE>(2);
    this->mIsSetActiveTime = false;
    this->mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cShlConditionInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cShlConditionInfo::DTI);
}

inline void* cShlConditionInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlConditionInfo::DTI)->memAlloc(sz, align, ::cShlConditionInfo::DTI.::MtDTI::getID());
}
