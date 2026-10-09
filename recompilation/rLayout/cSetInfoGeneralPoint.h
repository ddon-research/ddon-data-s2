#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "cSetInfoCoord.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class cSetInfo;

// Declarations
class cSetInfoGeneralPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSetInfoGeneralPoint : public cSetInfoCoord
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
    cSetInfoGeneralPoint();
    virtual ~cSetInfoGeneralPoint();
    f32 getRadius() const;
    s32 getObjectID() const;
    s32 getGroup() const;
    void setGroup(s32);
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual void copy(cSetInfo* pScr);  // vtable slot 11
private:
    f32 mRadius;  // offset: 0x44
    s32 mObjectID;  // offset: 0x48
    s32 mGroup;  // offset: 0x4c
public:
    static MyDTI DTI;
};
