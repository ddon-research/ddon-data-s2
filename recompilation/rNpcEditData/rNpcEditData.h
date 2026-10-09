#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class rNpcEditData;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rNpcEditData : public cResource
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
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rNpcEditData();
    virtual ~rNpcEditData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    union
    {
    public:
        struct
        {
        public:
            u32 mEquipDummy;  // offset: 0x0
            u32 mWepMain;  // offset: 0x4
            u32 mWepSub;  // offset: 0x8
            u32 mArmorHelm;  // offset: 0xc
            u32 mArmorBody;  // offset: 0x10
            u32 mWearBody;  // offset: 0x14
            u32 mArmorArm;  // offset: 0x18
            u32 mArmorLeg;  // offset: 0x1c
            u32 mWearLeg;  // offset: 0x20
            u32 mAccessory;  // offset: 0x24
            u32 mJewelry1;  // offset: 0x28
            u32 mJewelry2;  // offset: 0x2c
            u32 mJewelry3;  // offset: 0x30
            u32 mJewelry4;  // offset: 0x34
            u32 mJewelry5;  // offset: 0x38
            u32 mLantern;  // offset: 0x3c
        };  // offset: 0x0
        u32 mEquip[16];  // offset: 0x0
    };  // offset: 0x70
    u32 mItem;  // offset: 0xb0
    static MyDTI DTI;
};
