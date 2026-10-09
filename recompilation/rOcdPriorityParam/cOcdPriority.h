#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
class cOcdPriorityParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdPriorityParam : public MtObject
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
    cOcdPriorityParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getOcdUID() const;
    bool isMultiApply() const;
    bool isMultiNumLimit() const;
    u32 getMultiApplyNum() const;
    bool isAnnihilateOcd(u32 OcdUID) const;
    u32 getClass() const;
    u32 getLank() const;
private:
    u32 mOcdUID;  // offset: 0x8
    u32 mOcdClass;  // offset: 0xc
    u32 mOcdLank;  // offset: 0x10
    bool mIsMultiApply;  // offset: 0x14
    bool mIsMultiNumLimit;  // offset: 0x15
    u32 mMultiApplyNum;  // offset: 0x18
    bool mIsAnnihilateGoodOcd[27];  // offset: 0x1c
    bool mIsAnnihilateBadOcd[31];  // offset: 0x37
    bool mIsAnnihilateEnchantOcd[5];  // offset: 0x56
    bool mIsAnnihilateHumanOcd[9];  // offset: 0x5b
    bool mIsAnnihilateEnemyOcd[3];  // offset: 0x64
public:
    static MyDTI DTI;
};
