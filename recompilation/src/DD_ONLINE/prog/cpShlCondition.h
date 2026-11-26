#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpShlBase.h"
#include "uShlCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlConditionInfo;
class cShlParamComponent;

// Declarations
class cShlParamCompCondition;
class cShlParamCompCustomCondition;
class cpShlCondition;
class cpShlCustomCondition;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompCondition : public cShlParamComponent
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompCondition();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
    bool getIsCondition();
public:
    bool isCondition;  // offset: 0x8
    bool isAdd;  // offset: 0x9
    u32 goodStatus;  // offset: 0xc
    u32 badStatus;  // offset: 0x10
    u32 HumanOriginalStatus;  // offset: 0x14
    cShlConditionInfo mInfo;  // offset: 0x18
    static MyDTI DTI;
};

class cShlParamCompCustomCondition : public cShlParamCompCondition
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompCustomCondition();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    f32 mHosei[10];  // offset: 0x38
    s32 mMyCustomSkillId;  // offset: 0x60
    static MyDTI DTI;
};

class cpShlCondition : public cpShlBase
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
protected:
    cShlConditionInfo mInfo;  // offset: 0x58
public:
    static MyDTI DTI;
};

class cpShlCustomCondition : public cpShlCondition
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
    cpShlCustomCondition();
    virtual void initSub();  // vtable slot 15
public:
    u32 mOwnerSkillLv;  // offset: 0x78
    static MyDTI DTI;
};

inline void* cShlParamCompCondition::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompCondition::cShlParamCompCondition() {
    this->isCondition = false;
    this->isAdd = false;
    this->goodStatus = 0;
    this->badStatus = 0;
    this->HumanOriginalStatus = 0;
    this->mInfo.mIsSetActiveTime = false;
    this->mInfo.mActiveTime = 0.0f;
    this->mInfo.mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}

inline void* cShlParamCompCustomCondition::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompCustomCondition::cShlParamCompCustomCondition() {
    this->mHosei[0] = 1.0f;
    this->mHosei[1] = 1.0f;
    this->mHosei[2] = 1.0f;
    this->mHosei[3] = 1.0f;
    this->mHosei[4] = 1.0f;
    this->mHosei[5] = 1.0f;
    this->mHosei[6] = 1.0f;
    this->mHosei[7] = 1.0f;
    this->mHosei[8] = 1.0f;
    this->mHosei[9] = 1.0f;
    this->mMyCustomSkillId = -1;
}

inline void* cpShlCondition::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpShlCustomCondition::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
