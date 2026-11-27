#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtDTI.h"
#include "../../cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataBazaarCharacterInfo;
class CDataBazaarItemBaseInfo;
class CDataBazaarItemHistoryInfo;
class CDataBazaarItemInfo;
class CDataBazaarItemNumOfExhibitionInfo;

// Type aliases from DWARF
using CBazaarItemBaseInfo = CDataBazaarItemBaseInfo;
using CBazaarItemInfo = CDataBazaarItemInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataBazaarItemBaseInfo : public CPacketDataBase
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
    explicit CDataBazaarItemBaseInfo();
    explicit CDataBazaarItemBaseInfo(u32, u16, u32);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    u32 m_unPrice;  // offset: 0x10
    static MyDTI DTI;
};

class CDataBazaarItemHistoryInfo : public CPacketDataBase
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
    explicit CDataBazaarItemHistoryInfo();
    explicit CDataBazaarItemHistoryInfo(const CBazaarItemBaseInfo&, s64);
public:
    CBazaarItemBaseInfo m_ItemBaseInfo;  // offset: 0x8
    s64 m_llBitDate;  // offset: 0x20
    static MyDTI DTI;
};

class CDataBazaarItemInfo : public CPacketDataBase
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
    explicit CDataBazaarItemInfo();
    explicit CDataBazaarItemInfo(u64, u16, const CBazaarItemBaseInfo&, s64);
public:
    u64 m_ullBazaarId;  // offset: 0x8
    u16 m_usSequence;  // offset: 0x10
    CBazaarItemBaseInfo m_ItemBaseInfo;  // offset: 0x18
    s64 m_llExhibitionTime;  // offset: 0x30
    static MyDTI DTI;
};

class CDataBazaarItemNumOfExhibitionInfo : public CPacketDataBase
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
    explicit CDataBazaarItemNumOfExhibitionInfo();
    explicit CDataBazaarItemNumOfExhibitionInfo(u32, u16);
public:
    u32 m_unItemId;  // offset: 0x8
    u16 m_usNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataBazaarCharacterInfo : public CPacketDataBase
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
    explicit CDataBazaarCharacterInfo();
    explicit CDataBazaarCharacterInfo(const CBazaarItemInfo&, u8, u32, s64);
public:
    CBazaarItemInfo m_ItemInfo;  // offset: 0x8
    u8 m_ucState;  // offset: 0x40
    u32 m_unProceeds;  // offset: 0x44
    s64 m_llExpire;  // offset: 0x48
    static MyDTI DTI;
};

inline void* CDataBazaarCharacterInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataBazaarCharacterInfo::CDataBazaarCharacterInfo() {
    this->m_ucState = 0;
    this->m_unProceeds = 0;
    this->m_llExpire = 0;
}

inline void* CDataBazaarItemBaseInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataBazaarItemBaseInfo::CDataBazaarItemBaseInfo() {
    this->m_unItemId = 0;
    this->m_usNum = 0;
    this->m_unPrice = 0;
}

inline void* CDataBazaarItemHistoryInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataBazaarItemHistoryInfo::CDataBazaarItemHistoryInfo() {
    this->m_llBitDate = 0;
}

inline void* CDataBazaarItemInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataBazaarItemInfo::CDataBazaarItemInfo() {
    this->m_ullBazaarId = 0;
    this->m_usSequence = 0;
    this->m_llExhibitionTime = 0;
}

inline void* CDataBazaarItemNumOfExhibitionInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataBazaarItemNumOfExhibitionInfo::CDataBazaarItemNumOfExhibitionInfo() {
    this->m_unItemId = 0;
    this->m_usNum = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataBazaarCharacterInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarCharacterInfo::DTI);
}

inline MtAllocator* CDataBazaarItemBaseInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarItemBaseInfo::DTI);
}

inline void* CDataBazaarItemBaseInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarItemBaseInfo::DTI)->memAlloc(sz, align, ::CDataBazaarItemBaseInfo::DTI.::MtDTI::getID());
}

inline MtAllocator* CDataBazaarItemHistoryInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarItemHistoryInfo::DTI);
}

inline MtAllocator* CDataBazaarItemInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarItemInfo::DTI);
}

inline MtAllocator* CDataBazaarItemNumOfExhibitionInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataBazaarItemNumOfExhibitionInfo::DTI);
}
