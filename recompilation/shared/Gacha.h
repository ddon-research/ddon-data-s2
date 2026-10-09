#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataGachaDrawGroupInfo;
class CDataGachaDrawInfo;
class CDataGachaInfo;
class CDataGachaItemInfo;
class CDataGachaSettlementInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using b8 = bool;
using f64 = double;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataGachaItemInfo : public CPacketDataBase
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
    explicit CDataGachaItemInfo();
    explicit CDataGachaItemInfo(u32, u32, u32, u32, f64);
public:
    u32 m_unItemId;  // offset: 0x8
    u32 m_unItemNum;  // offset: 0xc
    u32 m_unRank;  // offset: 0x10
    u32 m_unEffect;  // offset: 0x14
    f64 m_dProbability;  // offset: 0x18
    static MyDTI DTI;
};

class CDataGachaSettlementInfo : public CPacketDataBase
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
    explicit CDataGachaSettlementInfo();
    explicit CDataGachaSettlementInfo(u32, u32, u32, u32, u32, u32, u32, u32);
public:
    u32 m_unDrawGroupId;  // offset: 0x8
    u32 m_unId;  // offset: 0xc
    u32 m_unPrice;  // offset: 0x10
    u32 m_unBasePrice;  // offset: 0x14
    u32 m_unPurchaseNum;  // offset: 0x18
    u32 m_unPurchaseMaxNum;  // offset: 0x1c
    u32 m_unSpecialPriceNum;  // offset: 0x20
    u32 m_unSpecialPriceMaxNum;  // offset: 0x24
    static MyDTI DTI;
};

class CDataGachaDrawInfo : public CPacketDataBase
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
    explicit CDataGachaDrawInfo();
    explicit CDataGachaDrawInfo(u32, b8, const MtTypedArray<CDataGachaItemInfo>&);
public:
    u32 m_unNum;  // offset: 0x8
    b8 m_bIsBonus;  // offset: 0xc
    MtTypedArray<CDataGachaItemInfo> m_GachaItemInfo;  // offset: 0x10
    static MyDTI DTI;
};

class CDataGachaDrawGroupInfo : public CPacketDataBase
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
    explicit CDataGachaDrawGroupInfo();
    explicit CDataGachaDrawGroupInfo(const MtTypedArray<CDataGachaSettlementInfo>&, const MtTypedArray<CDataGachaDrawInfo>&);
public:
    MtTypedArray<CDataGachaSettlementInfo> m_GachaSettlementList;  // offset: 0x8
    MtTypedArray<CDataGachaDrawInfo> m_GachaDrawList;  // offset: 0x28
    static MyDTI DTI;
};

class CDataGachaInfo : public CPacketDataBase
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
    explicit CDataGachaInfo();
    explicit CDataGachaInfo(u32, s64, s64, const char*, const char*, const char*, u8, const char*, const char*, const char*, const char*, const MtTypedArray<CDataGachaDrawGroupInfo>&);
public:
    u32 m_unId;  // offset: 0x8
    s64 m_llBegin;  // offset: 0x10
    s64 m_llEnd;  // offset: 0x18
    MtString m_wstrName;  // offset: 0x20
    MtString m_wstrDescription;  // offset: 0x28
    MtString m_wstrDetail;  // offset: 0x30
    u8 m_ucWeightDispType;  // offset: 0x38
    MtString m_wstrWeightDispTitle;  // offset: 0x40
    MtString m_wstrWeightDispText;  // offset: 0x48
    MtString m_wstrListAddr;  // offset: 0x50
    MtString m_wstrImageAddr;  // offset: 0x58
    MtTypedArray<CDataGachaDrawGroupInfo> m_DrawGroups;  // offset: 0x60
    static MyDTI DTI;
};
