#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlSpline.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;

// Declarations
class cShlParamCustomSpline;
class uShlCustomSpline;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCustomSpline : public cShlParamSpline
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
    cShlParamCustomSpline();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mCustomTime[10];  // offset: 0x1f8
    s32 mMyCustomSkillId;  // offset: 0x220
    static MyDTI DTI;
};

class uShlCustomSpline : public uShlSpline
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
    uShlCustomSpline();
    virtual ~uShlCustomSpline() {}
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
public:
    s32 mOwnerSkillLv;  // offset: 0x2cc0
    f32 mDieFrame;  // offset: 0x2cc4
    static MyDTI DTI;
};

inline void* cShlParamCustomSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCustomSpline::cShlParamCustomSpline() {
    this->mCustomTime[0] = 1.0f;
    this->mCustomTime[1] = 1.0f;
    this->mCustomTime[2] = 1.0f;
    this->mCustomTime[3] = 1.0f;
    this->mCustomTime[4] = 1.0f;
    this->mCustomTime[5] = 1.0f;
    this->mCustomTime[6] = 1.0f;
    this->mCustomTime[7] = 1.0f;
    this->mCustomTime[8] = 1.0f;
    this->mCustomTime[9] = 1.0f;
    this->mMyCustomSkillId = -1;
}

inline void* uShlCustomSpline::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlCustomSpline::uShlCustomSpline() {
    this->mOwnerSkillLv = 0;
    this->mDieFrame = 0.0f;
}
