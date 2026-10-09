#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;

// Declarations
class cpThinkBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpThinkBase : public cpComponent
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
    cpThinkBase();
    virtual ~cpThinkBase();
    virtual f32 getAngleY();  // vtable slot 15
    virtual f32 getAngleYActBegin(u32);  // vtable slot 16
    virtual f32 getMoveSpeed();  // vtable slot 17
    virtual u32 getMoveType();  // vtable slot 18
    virtual f32 getMoveLvLX();  // vtable slot 19
    virtual const MtVector3& getTargetPos();  // vtable slot 20
    virtual u32 getTargetUID();  // vtable slot 21
    virtual void setTargetPos(const MtVector3&);  // vtable slot 22
    virtual void setTargetUID(u32);  // vtable slot 23
public:
    static MyDTI DTI;
};
