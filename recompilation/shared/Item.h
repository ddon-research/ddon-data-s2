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
class CDataC2SChangeCharacterEquipInfo;
class CDataChangeEquipJobItem;
class CDataCharacterItemSlotInfo;
class CDataEquipElementParam;
class CDataEquipItemInfo;
class CDataEquipJobItem;
class CDataGameItemStorage;
class CDataGameItemStorageInfo;
class CDataItemEquipElement;
class CDataItemList;
class CDataItemUIDList;
class CDataItemUpdateResult;
class CDataJewelryEquipLimit;
class CDataMoveItemUIDFromTo;
class CDataS2CCharacterEquipInfo;
class CDataStorageItemUIDList;

namespace nItem {
    enum E_STORAGE_TYPE
    {
        STORAGE_TYPE_INVALID = 0,
        STORAGE_TYPE_TOP = 1,
        STORAGE_TYPE_BAG_USE = 1,
        STORAGE_TYPE_BAG_MATERIAL = 2,
        STORAGE_TYPE_BAG_EQUIP = 3,
        STORAGE_TYPE_NO_USE_0 = 4,
        STORAGE_TYPE_NO_USE_1 = 5,
        STORAGE_TYPE_NO_USE_2 = 6,
        STORAGE_TYPE_KEY = 7,
        STORAGE_TYPE_REWARD = 8,
        STORAGE_TYPE_NO_USE_3 = 9,
        STORAGE_TYPE_NO_USE_4 = 10,
        STORAGE_TYPE_CHAR_EQUIP = 11,
        STORAGE_TYPE_PAWN_EQUIP = 12,
        STORAGE_TYPE_BAG_JOB = 13,
        STORAGE_TYPE_NO_USE_5 = 14,
        STORAGE_TYPE_POST = 15,
        STORAGE_TYPE_STORAGE_ALL = 16,
        STORAGE_TYPE_STORAGE_EX1_ALL = 17,
        STORAGE_TYPE_NO_USE_6 = 18,
        STORAGE_TYPE_CHAR_VISUAL_EQUIP = 19,
        STORAGE_TYPE_PAWN_VISUAL_EQUIP = 20,
        STORAGE_TYPE_OLD_TEMPORARY_USE_BAG = 21,
        STORAGE_TYPE_CRAFT_RECIPE = 22,
        STORAGE_TYPE_TEMPORARY_USE_BAG = 23,
        STORAGE_TYPE_PROFILE_BG = 24,
        STORAGE_TYPE_EDIT_PARTS = 25,
        STORAGE_TYPE_EMOTION = 26,
        STORAGE_TYPE_ABILITY = 27,
        STORAGE_TYPE_PAWN_TALK = 28,
        STORAGE_TYPE_BAGGAGE = 29,
        STORAGE_TYPE_BAGGAGE_FREE = 30,
        STORAGE_TYPE_BAGGAGE_RENTAL01 = 31,
        STORAGE_TYPE_FURNITURE = 32,
        STORAGE_TYPE_BAGGAGE_RENTAL02 = 33,
        STORAGE_TYPE_MAX = 34,
        STORAGE_TYPE_NUM = 33,
        STORAGE_TYPE_GROUP_BAG = 220,
        STORAGE_TYPE_GROUP_STORAGE = 221,
        STORAGE_TYPE_GROUP_ASSETS = 222,
        STORAGE_TYPE_GROUP_USABLE = 223,
        STORAGE_TYPE_GROUP_ALL_USABLE = 224,
    };
}  // namespace nItem

// Type aliases from DWARF
using CGameItemStorage = CDataGameItemStorage;
using CItemList = CDataItemList;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataC2SChangeCharacterEquipInfo : public CPacketDataBase
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
    explicit CDataC2SChangeCharacterEquipInfo();
    explicit CDataC2SChangeCharacterEquipInfo(const char* in_strEquipItemUID, u8 in_EquipCategory, u8 in_EquipType);
public:
    MtString m_wstrEquipItemUID;  // offset: 0x8
    u8 m_ucEquipCategory;  // offset: 0x10
    u8 m_ucEquipType;  // offset: 0x11
    static MyDTI DTI;
};

class CDataChangeEquipJobItem : public CPacketDataBase
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
    explicit CDataChangeEquipJobItem();
    explicit CDataChangeEquipJobItem(const char* in_strEquipJobItemUID, u8 in_EquipSlotNo);
public:
    MtString m_wstrEquipJobItemUID;  // offset: 0x8
    u8 m_ucEquipSlotNo;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCharacterItemSlotInfo : public CPacketDataBase
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
    explicit CDataCharacterItemSlotInfo();
    explicit CDataCharacterItemSlotInfo(u8, u16);
public:
    u8 m_ucStorageType;  // offset: 0x8
    u16 m_usSlotMax;  // offset: 0xa
    static MyDTI DTI;
};

class CDataEquipElementParam : public CPacketDataBase
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
    explicit CDataEquipElementParam();
    explicit CDataEquipElementParam(u8 in_SlotNo, u32 in_ItemID);
public:
    u8 m_ucSlotNo;  // offset: 0x8
    u32 m_unItemID;  // offset: 0xc
    static MyDTI DTI;
};

class CDataEquipItemInfo : public CPacketDataBase
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
    explicit CDataEquipItemInfo();
    explicit CDataEquipItemInfo(u8, u8, u32, u8, u8, const MtTypedArray<CDataEquipElementParam>&);
public:
    u8 m_ucEquipType;  // offset: 0x8
    u8 m_ucEquipSlot;  // offset: 0x9
    u32 m_unItemID;  // offset: 0xc
    u8 m_ucColor;  // offset: 0x10
    u8 m_ucPlusValue;  // offset: 0x11
    MtTypedArray<CDataEquipElementParam> m_EquipElementParamList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataEquipJobItem : public CPacketDataBase
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
    explicit CDataEquipJobItem();
    explicit CDataEquipJobItem(u32, u8);
public:
    u32 m_unJobItemID;  // offset: 0x8
    u8 m_ucEquipSlotNo;  // offset: 0xc
    static MyDTI DTI;
};

class CDataGameItemStorage : public CPacketDataBase
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
    explicit CDataGameItemStorage();
    explicit CDataGameItemStorage(u8 in_StorageType);
public:
    u8 m_ucStorageType;  // offset: 0x8
    static MyDTI DTI;
};

class CDataGameItemStorageInfo : public CPacketDataBase
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
    explicit CDataGameItemStorageInfo();
    explicit CDataGameItemStorageInfo(const CGameItemStorage&, u16, u16);
public:
    CGameItemStorage m_GameItemStorage;  // offset: 0x8
    u16 m_usUsedSlotNum;  // offset: 0x18
    u16 m_usMaxSlotNum;  // offset: 0x1a
    static MyDTI DTI;
};

class CDataItemEquipElement : public CPacketDataBase
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
    explicit CDataItemEquipElement();
    explicit CDataItemEquipElement(const char*, const MtTypedArray<CDataEquipElementParam>&);
public:
    MtString m_wstrItemUID;  // offset: 0x8
    MtTypedArray<CDataEquipElementParam> m_EquipElementList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataItemList : public CPacketDataBase
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
    explicit CDataItemList();
    explicit CDataItemList(u8, u16, const char*, u32, u32, u32, u32, u32, u8, const MtTypedArray<CDataEquipElementParam>&, u8, b8);
public:
    u8 m_ucStorageType;  // offset: 0x8
    u16 m_usSlotNo;  // offset: 0xa
    MtString m_wstrUID;  // offset: 0x10
    u32 m_unItemID;  // offset: 0x18
    u32 m_unItemNum;  // offset: 0x1c
    u32 m_unEquipCharacterID;  // offset: 0x20
    u32 m_unEquipPawnID;  // offset: 0x24
    u32 m_unEquipPoint;  // offset: 0x28
    u8 m_ucColor;  // offset: 0x2c
    MtTypedArray<CDataEquipElementParam> m_EquipElementParamList;  // offset: 0x30
    u8 m_ucPlusValue;  // offset: 0x50
    b8 m_bBind;  // offset: 0x51
    static MyDTI DTI;
};

class CDataItemUIDList : public CPacketDataBase
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
    explicit CDataItemUIDList();
    explicit CDataItemUIDList(const char* in_strUID, u32 in_Num);
public:
    MtString m_wstrUID;  // offset: 0x8
    u32 m_unNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataItemUpdateResult : public CPacketDataBase
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
    explicit CDataItemUpdateResult();
    explicit CDataItemUpdateResult(const CItemList&, s32);
public:
    CItemList m_ItemInfo;  // offset: 0x8
    s32 m_nUpdateItemNum;  // offset: 0x60
    static MyDTI DTI;
};

class CDataJewelryEquipLimit : public CPacketDataBase
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
    explicit CDataJewelryEquipLimit();
    explicit CDataJewelryEquipLimit(u8, u8);
public:
    u8 m_ucJewelryType;  // offset: 0x8
    u8 m_ucEquipNumMax;  // offset: 0x9
    static MyDTI DTI;
};

class CDataMoveItemUIDFromTo : public CPacketDataBase
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
    explicit CDataMoveItemUIDFromTo();
    explicit CDataMoveItemUIDFromTo(const char*, u32, u8, u8, u16);
public:
    MtString m_wstrUID;  // offset: 0x8
    u32 m_unNum;  // offset: 0x10
    u8 m_ucSrcStorageType;  // offset: 0x14
    u8 m_ucDstStorageType;  // offset: 0x15
    u16 m_usSlotNo;  // offset: 0x16
    static MyDTI DTI;
};

class CDataS2CCharacterEquipInfo : public CPacketDataBase
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
    explicit CDataS2CCharacterEquipInfo();
    explicit CDataS2CCharacterEquipInfo(const char*, u8, u8);
public:
    MtString m_wstrEquipItemUID;  // offset: 0x8
    u8 m_ucEquipCategory;  // offset: 0x10
    u8 m_ucEquipType;  // offset: 0x11
    static MyDTI DTI;
};

class CDataStorageItemUIDList : public CPacketDataBase
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
    explicit CDataStorageItemUIDList();
    explicit CDataStorageItemUIDList(const char* in_strUID, u32 in_Num, u8 in_StorageType, u16 in_SlotNo);
public:
    MtString m_wstrUID;  // offset: 0x8
    u32 m_unNum;  // offset: 0x10
    u8 m_ucStorageType;  // offset: 0x14
    u16 m_usSlotNo;  // offset: 0x16
    static MyDTI DTI;
};
