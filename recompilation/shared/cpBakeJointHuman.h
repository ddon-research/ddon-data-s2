#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpBakeJoint.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uModel;

// Declarations
class cpBakeJointHuman;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpBakeJointHuman : public cpBakeJoint
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
    cpBakeJointHuman();
    virtual ~cpBakeJointHuman();
    virtual void setup();  // vtable slot 6
    virtual void upadatePtr();  // vtable slot 18
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setupComponentPtr();  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void requestBake(u32 type, s32 timer);
    u32 getBakeType();
protected:
    virtual bool initBake();  // vtable slot 19
    bool initBake(u32 type);
    virtual void setBakeMotion(uModel* pBuildModel);  // vtable slot 15
    virtual bool setRenewalEnvelope();  // vtable slot 16
    virtual bool setOriginalEnvelope();  // vtable slot 17
protected:
    u32 mBakeType;  // offset: 0x44cc
    u32 mBakeRequestType;  // offset: 0x44d0
    s32 mTimer;  // offset: 0x44d4
public:
    static MyDTI DTI;
};
