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
class cShlParamJob10CS07;
class uShlJob10CS07;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob10CS07 : public cShlParamBase
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
    cShlParamJob10CS07();
    virtual ~cShlParamJob10CS07();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 mCheckShl;  // offset: 0x160
    s32 mCheckShlCorePoint;  // offset: 0x164
    s32 mCheckShlUndead;  // offset: 0x168
    s32 mConstShlCondition;  // offset: 0x16c
    u32 mCustomSkillId;  // offset: 0x170
    f32 mAddTime[10];  // offset: 0x174
    static MyDTI DTI;
};

class uShlJob10CS07 : public uShlBase
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
    const cShlParamJob10CS07* getShlParam() const;
    uShlJob10CS07();
    virtual ~uShlJob10CS07();
    virtual void initSub();  // vtable slot 177
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    f32 getExtendTimer();
    virtual void updateSub();  // vtable slot 175
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void kill();  // vtable slot 16
private:
    u32 mSkillLv;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

inline void* cShlParamJob10CS07::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob10CS07::cShlParamJob10CS07() {
    this->mCheckShlUndead = -1;
    this->mConstShlCondition = -1;
    this->mCheckShl = -1;
    this->mCheckShlCorePoint = -1;
    this->mAddTime[9] = 0.0f;
    this->mAddTime[7] = 0.0f;
    this->mAddTime[8] = 0.0f;
    this->mAddTime[5] = 0.0f;
    this->mAddTime[6] = 0.0f;
    this->mAddTime[3] = 0.0f;
    this->mAddTime[4] = 0.0f;
    this->mAddTime[1] = 0.0f;
    this->mAddTime[2] = 0.0f;
    this->mCustomSkillId = 0;
    this->mAddTime[0] = 0.0f;
}

inline void* uShlJob10CS07::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob10CS07::uShlJob10CS07() {
    this->mSkillLv = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamJob10CS07::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamJob10CS07::DTI)->memAlloc(sz, align, ::cShlParamJob10CS07::DTI.::MtDTI::getID());
}

inline void* uShlJob10CS07::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob10CS07::DTI)->memAlloc(sz, align, ::uShlJob10CS07::DTI.::MtDTI::getID());
}

inline void uShlJob10CS07::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob10CS07::DTI)->memFree(p_addr);
}
