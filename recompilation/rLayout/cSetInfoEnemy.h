#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "cSetInfoCharacter.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class cSetInfo;
class cUnit;

// Declarations
class cSetInfoEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSetInfoEnemy : public cSetInfoCharacter
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
    cSetInfoEnemy();
    virtual ~cSetInfoEnemy();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual void copy(cSetInfo* p);  // vtable slot 11
    s32 getPresetKind() const;
    s32 getSubGroupNo() const;
public:
    s32 mPresetKind;  // offset: 0x44
    s32 mGroup;  // offset: 0x48
    u32 mEmReactNo;  // offset: 0x4c
    s32 mSubGroupNo;  // offset: 0x50
    bool mReturnPoint2nd;  // offset: 0x54
    static MyDTI DTI;
};
