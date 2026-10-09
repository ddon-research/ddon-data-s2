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
class rJointEx2;
class uModel;

// Declarations
class cpJointEx2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJointEx2 : public cpComponent
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
    cpJointEx2();
    virtual ~cpJointEx2();
    virtual void setup();  // vtable slot 6
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setupComponentPtr();  // vtable slot 12
    void update();
    void setResource(rJointEx2* pRes);
    rJointEx2* getResource();
public:
    uModel* mpModel;  // offset: 0x50
    rJointEx2* mpResource;  // offset: 0x58
    static MyDTI DTI;
};
