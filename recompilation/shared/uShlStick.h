#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cShlParamStick;

// Declarations
class uShlStick;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

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

// Inline, no code of its own: checked where it is inlined.
inline uShlStick::uShlStick() {
}
