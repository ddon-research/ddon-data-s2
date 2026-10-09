#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cNpcCustomSkill;
class rNpcCustomSkill;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cNpcCustomSkill : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 5,
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
    cNpcCustomSkill();
    // Address: 0x01a9e7d0 - 0x01a9e7d1 (1 bytes)
    virtual ~cNpcCustomSkill() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getThinkId();
    u16 getCustomSkill1();
    u16 getCustomSkill2();
    u16 getCustomSkill3();
    u16 getCustomSkill4();
    u16 getCustomSkillLv1();
    u16 getCustomSkillLv2();
    u16 getCustomSkillLv3();
    u16 getCustomSkillLv4();
public:
    u32 mThinkId;  // offset: 0x8
    u16 mCustomSkill1;  // offset: 0xc
    u16 mCustomSkill2;  // offset: 0xe
    u16 mCustomSkill3;  // offset: 0x10
    u16 mCustomSkill4;  // offset: 0x12
    u16 mCustomSkillLv1;  // offset: 0x14
    u16 mCustomSkillLv2;  // offset: 0x16
    u16 mCustomSkillLv3;  // offset: 0x18
    u16 mCustomSkillLv4;  // offset: 0x1a
    u16 mNormalSkillBit;  // offset: 0x1c
    static MyDTI DTI;
};

class rNpcCustomSkill : public rTbl2<cNpcCustomSkill>
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
    virtual bool loadData(MtDataReader& in, cNpcCustomSkill* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cNpcCustomSkill::cNpcCustomSkill() {
    this->mThinkId = static_cast<u32>(0);
    this->mCustomSkill1 = static_cast<u16>(255);
    this->mCustomSkill2 = static_cast<u16>(255);
    this->mCustomSkill3 = static_cast<u16>(255);
    this->mCustomSkill4 = static_cast<u16>(255);
    this->mNormalSkillBit = static_cast<u16>(0);
    this->mCustomSkillLv1 = static_cast<u16>(0);
    this->mCustomSkillLv2 = static_cast<u16>(0);
    this->mCustomSkillLv3 = static_cast<u16>(0);
    this->mCustomSkillLv4 = static_cast<u16>(0);
}
