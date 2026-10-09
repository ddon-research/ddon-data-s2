#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "Pawn.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterName;
class CDataPawnCraftSkill;
class CDataPawnName;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataCharacterSearchParameter;
class CDataPartySearchParameter;
class CDataPawnSearchParameter;
class CDataQuickMatchSearchParameter;

// Type aliases from DWARF
using CCharacterName = CDataCharacterName;
using CCharacterSearchParameter = CDataCharacterSearchParameter;
using CPawnName = CDataPawnName;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataCharacterSearchParameter : public CPacketDataBase
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
    explicit CDataCharacterSearchParameter();
    explicit CDataCharacterSearchParameter(u32, u32, u32, u8, u8, u16, u16);
public:
    u32 m_unJob;  // offset: 0x8
    u32 m_unExpMin;  // offset: 0xc
    u32 m_unExpMax;  // offset: 0x10
    u8 m_ucLevelMin;  // offset: 0x14
    u8 m_ucLevelMax;  // offset: 0x15
    u16 m_usItemRankMin;  // offset: 0x16
    u16 m_usItemRankMax;  // offset: 0x18
    static MyDTI DTI;
};

class CDataPartySearchParameter : public CPacketDataBase
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
    explicit CDataPartySearchParameter();
    explicit CDataPartySearchParameter(u32, u32, const CCharacterSearchParameter&);
public:
    u32 m_unObjectiveType1;  // offset: 0x8
    u32 m_unPlayStyle;  // offset: 0xc
    CCharacterSearchParameter m_CharacterParam;  // offset: 0x10
    static MyDTI DTI;
};

class CDataPawnSearchParameter : public CPacketDataBase
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
    explicit CDataPawnSearchParameter();
    explicit CDataPawnSearchParameter(u8, u8, const MtTypedArray<CDataPawnCraftSkill>&, u8, const CCharacterName&, const CPawnName&, const CCharacterSearchParameter&, b8, b8);
public:
    u8 m_ucCraftRankMin;  // offset: 0x8
    u8 m_ucCraftRankMax;  // offset: 0x9
    MtTypedArray<CDataPawnCraftSkill> m_CraftSkillList;  // offset: 0x10
    u8 m_ucSex;  // offset: 0x30
    CCharacterName m_OwnerCharacterName;  // offset: 0x38
    CPawnName m_PawnName;  // offset: 0x50
    CCharacterSearchParameter m_CharacterParam;  // offset: 0x60
    b8 m_bIsFriend;  // offset: 0x80
    b8 m_bIsClan;  // offset: 0x81
    static MyDTI DTI;
};

class CDataQuickMatchSearchParameter : public CPacketDataBase
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
    explicit CDataQuickMatchSearchParameter();
    explicit CDataQuickMatchSearchParameter(u32, u32, b8, b8, b8);
public:
    u32 m_unObjectiveType1;  // offset: 0x8
    u32 m_unObjectiveType2;  // offset: 0xc
    b8 m_bIsPawnJoin;  // offset: 0x10
    b8 m_bIsPartyBalance;  // offset: 0x11
    b8 m_bIsLevelBalance;  // offset: 0x12
    static MyDTI DTI;
};
