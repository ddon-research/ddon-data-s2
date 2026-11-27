#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlHoming.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;

// Declarations
class cShlParamReflectWall;
class uShlReflectWall;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamReflectWall : public cShlParamHoming
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
    cShlParamReflectWall();
    virtual ~cShlParamReflectWall();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool isReflectWall;  // offset: 0x248
    f32 reflectCheckRadius;  // offset: 0x24c
    u32 reflectCnt;  // offset: 0x250
    s32 shlNoReflectWall;  // offset: 0x254
    s32 epvNoReflectWall;  // offset: 0x258
    static MyDTI DTI;
};

class uShlReflectWall : public uShlHoming
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
    const cShlParamReflectWall* getShlParam() const;
    uShlReflectWall();
    virtual ~uShlReflectWall();
    virtual void updateSub();  // vtable slot 175
    void setWallReflectCnt(u32 cnt);
private:
    u32 mWallReflectCnt;  // offset: 0x2bdc
public:
    static MyDTI DTI;
};

inline void* cShlParamReflectWall::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamReflectWall::cShlParamReflectWall() : isReflectWall(false), reflectCheckRadius(0.0f), reflectCnt(0u), shlNoReflectWall(-1), epvNoReflectWall(0) {
}

inline void* uShlReflectWall::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlReflectWall::uShlReflectWall() {
    this->mWallReflectCnt = 0;
}

inline void uShlReflectWall::setWallReflectCnt(u32 cnt) {
    this->mWallReflectCnt = cnt;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* uShlReflectWall::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlReflectWall::DTI)->memAlloc(sz, align, ::uShlReflectWall::DTI.::MtDTI::getID());
}

inline void uShlReflectWall::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlReflectWall::DTI)->memFree(p_addr);
}

inline const cShlParamReflectWall* uShlReflectWall::getShlParam() const {
    return static_cast<const cShlParamReflectWall*>(this->::uShlBase::mpShlParam2);
}
