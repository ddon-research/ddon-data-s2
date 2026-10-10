#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataEquipItemInfo;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataJobChangeInfo;
class CDataPawnJobChangeInfo;
class CDataReleaseElement;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataJobChangeInfo : public CPacketDataBase
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
    explicit CDataJobChangeInfo();
    explicit CDataJobChangeInfo(u8, const MtTypedArray<CDataEquipItemInfo>&);
public:
    u8 m_ucJobID;  // offset: 0x8
    MtTypedArray<CDataEquipItemInfo> m_EquipItemList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataPawnJobChangeInfo : public CPacketDataBase
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
    explicit CDataPawnJobChangeInfo();
    explicit CDataPawnJobChangeInfo(u8, u32, const MtTypedArray<CDataJobChangeInfo>&, const MtTypedArray<CDataJobChangeInfo>&);
public:
    u8 m_ucSlotNo;  // offset: 0x8
    u32 m_unPawnId;  // offset: 0xc
    MtTypedArray<CDataJobChangeInfo> m_JobChangeInfoList;  // offset: 0x10
    MtTypedArray<CDataJobChangeInfo> m_JobReleaseInfoList;  // offset: 0x30
    static MyDTI DTI;
};

class CDataReleaseElement : public CPacketDataBase
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
    explicit CDataReleaseElement();
    explicit CDataReleaseElement(u8, u32, u8);
public:
    u8 m_ucReleaseType;  // offset: 0x8
    u32 m_unReleaseID;  // offset: 0xc
    u8 m_ucReleaseLv;  // offset: 0x10
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataJobChangeInfo::CDataJobChangeInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJobID = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataReleaseElement::CDataReleaseElement() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucReleaseType = static_cast<u8>(0);
    this->m_unReleaseID = static_cast<u32>(0);
    this->m_ucReleaseLv = static_cast<u8>(0);
}
