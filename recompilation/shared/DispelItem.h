#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataEquipElementParam;
class CDataWalletPoint;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataDispelBaseItem;
class CDataDispelBaseItemData;
class CDataDispelCategoryInfo;
class CDataDispelLotColor;
class CDataDispelLotCrest;
class CDataDispelLotData;
class CDataDispelLotItem;
class CDataDispelLotPlus;
class CDataDispelResultInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using b8 = bool;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataDispelBaseItemData : public CPacketDataBase
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
    explicit CDataDispelBaseItemData();
    explicit CDataDispelBaseItemData(u32, u8);
public:
    u32 m_unItemID;  // offset: 0x8
    u8 m_ucNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataDispelCategoryInfo : public CPacketDataBase
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
    explicit CDataDispelCategoryInfo();
    explicit CDataDispelCategoryInfo(u8, const char*);
public:
    u8 m_ucCategory;  // offset: 0x8
    MtString m_wstrCategoryName;  // offset: 0x10
    static MyDTI DTI;
};

class CDataDispelLotColor : public CPacketDataBase
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
    explicit CDataDispelLotColor();
    explicit CDataDispelLotColor(u8, u8);
public:
    u8 m_ucColor;  // offset: 0x8
    u8 m_ucColorRate;  // offset: 0x9
    static MyDTI DTI;
};

class CDataDispelLotCrest : public CPacketDataBase
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
    explicit CDataDispelLotCrest();
    explicit CDataDispelLotCrest(u32, u8);
public:
    u32 m_unCrestItemId;  // offset: 0x8
    u8 m_ucCrestItemRate;  // offset: 0xc
    static MyDTI DTI;
};

class CDataDispelLotItem : public CPacketDataBase
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
    explicit CDataDispelLotItem();
    explicit CDataDispelLotItem(u32, u8, u8, u32);
public:
    u32 m_unItemId;  // offset: 0x8
    u8 m_ucItemRate;  // offset: 0xc
    u8 m_ucCrestNum;  // offset: 0xd
    u32 m_unItemNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataDispelLotPlus : public CPacketDataBase
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
    explicit CDataDispelLotPlus();
    explicit CDataDispelLotPlus(u8, u8);
public:
    u8 m_ucPlus;  // offset: 0x8
    u8 m_ucPlusRate;  // offset: 0x9
    static MyDTI DTI;
};

class CDataDispelResultInfo : public CPacketDataBase
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
    explicit CDataDispelResultInfo();
    explicit CDataDispelResultInfo(u32, u32, u8, u8, const MtTypedArray<CDataEquipElementParam>&);
public:
    u32 m_unItemID;  // offset: 0x8
    u32 m_unItemNum;  // offset: 0xc
    u8 m_ucColor;  // offset: 0x10
    u8 m_ucPlus;  // offset: 0x11
    MtTypedArray<CDataEquipElementParam> m_EquipElementParamList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataDispelLotData : public CPacketDataBase
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
    explicit CDataDispelLotData();
    explicit CDataDispelLotData(u32, const CDataDispelLotItem&, const MtTypedArray<CDataDispelLotCrest>&, const MtTypedArray<CDataDispelLotColor>&, const MtTypedArray<CDataDispelLotPlus>&);
public:
    u32 m_unId;  // offset: 0x8
    CDataDispelLotItem m_ItemLot;  // offset: 0x10
    MtTypedArray<CDataDispelLotCrest> m_CrestLot;  // offset: 0x28
    MtTypedArray<CDataDispelLotColor> m_ColorLot;  // offset: 0x48
    MtTypedArray<CDataDispelLotPlus> m_PlusLot;  // offset: 0x68
    static MyDTI DTI;
};

class CDataDispelBaseItem : public CPacketDataBase
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
    explicit CDataDispelBaseItem();
    explicit CDataDispelBaseItem(u32, s64, s64, const MtTypedArray<CDataDispelBaseItemData>&, const MtTypedArray<CDataWalletPoint>&, b8, const MtTypedArray<CDataDispelLotData>&, u32, const char*, u8);
public:
    u32 m_unId;  // offset: 0x8
    s64 m_llBegin;  // offset: 0x10
    s64 m_llEnd;  // offset: 0x18
    MtTypedArray<CDataDispelBaseItemData> m_BaseItemId;  // offset: 0x20
    MtTypedArray<CDataWalletPoint> m_Cost;  // offset: 0x40
    b8 m_bIsHide;  // offset: 0x60
    MtTypedArray<CDataDispelLotData> m_LotItemList;  // offset: 0x68
    u32 m_unSortId;  // offset: 0x88
    MtString m_wstrLabel;  // offset: 0x90
    u8 m_ucCategory;  // offset: 0x98
    static MyDTI DTI;
};
