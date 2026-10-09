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
class MtPropertyList;
class cEfcMotSync;
class rEffectProvider;

// Declarations
class cpEffectProvider;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEffectProvider : public cpComponent
{
public:
    enum EPV_TYPE
    {
        EPV_TYPE_COMMON = 0,
        EPV_TYPE_CATEGORY_COMMON = 1,
        EPV_TYPE_ORIGINAL = 2,
        EPV_TYPE_EVENT = 3,
        EPV_TYPE_ST_OM_MAX = 4,
        EPV_TYPE_MWEAPON = 4,
        EPV_TYPE_SWEAPON = 5,
        EPV_TYPE_ATTACK_00 = 6,
        EPV_TYPE_ATTACK_01 = 7,
        EPV_TYPE_SHELL = 8,
        EPV_TYPE_EM_MAX = 9,
        EPV_TYPE_CUSTOM_SKILL00 = 9,
        EPV_TYPE_CUSTOM_SKILL01 = 10,
        EPV_TYPE_CUSTOM_SKILL02 = 11,
        EPV_TYPE_CUSTOM_SKILL03 = 12,
        EPV_TYPE_CUSTOM_SKILL04 = 13,
        EPV_TYPE_CUSTOM_SKILL05 = 14,
        EPV_TYPE_PL_MAX = 15,
        EPV_TYPE_ORIGINAL2 = 15,
        EPV_TYPE_MAX = 16,
    };
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
    cpEffectProvider();
    virtual ~cpEffectProvider();
    virtual void setup();  // vtable slot 6
    void after();
    virtual void updatePtr();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setResource(rEffectProvider* pRes, EPV_TYPE Type);
    void setResource(MT_CTSTR Path, EPV_TYPE Type);
    void releaseResource(EPV_TYPE Type);
    rEffectProvider* getResource(EPV_TYPE type);
protected:
    void setMotSync(u32 Type);
    void resetMotSync(u32 Type);
    cEfcMotSync* getMotSync(u32 Type);
protected:
    rEffectProvider* mprResource[16];  // offset: 0x50
    cEfcMotSync* mpMotSync[16];  // offset: 0xd0
public:
    static MyDTI DTI;
};
