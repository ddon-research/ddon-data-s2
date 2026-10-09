#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "CharacterCommon.h"
#include "CharacterEdit.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataArisenProfile;
class CDataCharacterEquipData;
class CDataCharacterItemSlotInfo;
class CDataCharacterJobData;
class CDataCharacterMsgSet;
class CDataCommunicationShortCut;
class CDataEditInfo;
class CDataEquipJobItem;
class CDataMatchingProfile;
class CDataOrbPageStatus;
class CDataShortCut;
class CDataStatusInfo;
class CDataWalletPoint;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataCharacterInfo;
class CDataJobPlayPoint;
class CDataJobValueShopItem;
class CDataPlayPointData;

// Type aliases from DWARF
using CArisenProfile = CDataArisenProfile;
using CEditInfo = CDataEditInfo;
using CMatchingProfile = CDataMatchingProfile;
using CPlayPointData = CDataPlayPointData;
using CStatusInfo = CDataStatusInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataJobValueShopItem : public CPacketDataBase
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
    explicit CDataJobValueShopItem();
    explicit CDataJobValueShopItem(u32, u32, u32, b8, b8, u8);
public:
    u32 m_unLineupId;  // offset: 0x8
    u32 m_unItemId;  // offset: 0xc
    u32 m_unPrice;  // offset: 0x10
    b8 m_bIsCountLimit;  // offset: 0x14
    b8 m_bCanSelectStorage;  // offset: 0x15
    u8 m_ucUnableReason;  // offset: 0x16
    static MyDTI DTI;
};

class CDataPlayPointData : public CPacketDataBase
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
    explicit CDataPlayPointData();
    explicit CDataPlayPointData(u8, u32);
public:
    u8 m_ucExpMode;  // offset: 0x8
    u32 m_unPlayPoint;  // offset: 0xc
    static MyDTI DTI;
};

class CDataJobPlayPoint : public CPacketDataBase
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
    explicit CDataJobPlayPoint();
    explicit CDataJobPlayPoint(u8, const CPlayPointData&);
public:
    u8 m_ucJob;  // offset: 0x8
    CPlayPointData m_Data;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCharacterInfo : public CPacketDataBase
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
    explicit CDataCharacterInfo();
    explicit CDataCharacterInfo(u32, u32, u32, const char*, const char*, const CEditInfo&, const CStatusInfo&, u8, const MtTypedArray<CDataCharacterJobData>&, const MtTypedArray<CDataJobPlayPoint>&, const MtTypedArray<CDataCharacterEquipData>&, const MtTypedArray<CDataCharacterEquipData>&, const MtTypedArray<CDataEquipJobItem>&, u8, const MtTypedArray<CDataCharacterItemSlotInfo>&, const MtTypedArray<CDataWalletPoint>&, u8, u8, const MtTypedArray<CDataOrbPageStatus>&, const MtTypedArray<CDataCharacterMsgSet>&, const MtTypedArray<CDataShortCut>&, const MtTypedArray<CDataCommunicationShortCut>&, const CMatchingProfile&, const CArisenProfile&, b8, b8, b8, b8, u8, u8);
public:
    u32 m_unCharacterId;  // offset: 0x8
    u32 m_unUserId;  // offset: 0xc
    u32 m_unVersion;  // offset: 0x10
    MtString m_wstrFirstName;  // offset: 0x18
    MtString m_wstrLastName;  // offset: 0x20
    CEditInfo m_EditInfo;  // offset: 0x28
    CStatusInfo m_StatusInfo;  // offset: 0xb0
    u8 m_ucJob;  // offset: 0xe8
    MtTypedArray<CDataCharacterJobData> m_CharacterJobDataList;  // offset: 0xf0
    MtTypedArray<CDataJobPlayPoint> m_PlayPointList;  // offset: 0x110
    MtTypedArray<CDataCharacterEquipData> m_CharacterEquipDataList;  // offset: 0x130
    MtTypedArray<CDataCharacterEquipData> m_CharacterEquipViewDataList;  // offset: 0x150
    MtTypedArray<CDataEquipJobItem> m_CharacterEquipJobItemList;  // offset: 0x170
    u8 m_ucJewelrySlotNum;  // offset: 0x190
    MtTypedArray<CDataCharacterItemSlotInfo> m_CharacterItemSlotInfoList;  // offset: 0x198
    MtTypedArray<CDataWalletPoint> m_WalletPointList;  // offset: 0x1b8
    u8 m_ucMyPawnSlotNum;  // offset: 0x1d8
    u8 m_ucRentalPawnSlotNum;  // offset: 0x1d9
    MtTypedArray<CDataOrbPageStatus> m_OrbStatusList;  // offset: 0x1e0
    MtTypedArray<CDataCharacterMsgSet> m_MsgSetList;  // offset: 0x200
    MtTypedArray<CDataShortCut> m_ShortCutList;  // offset: 0x220
    MtTypedArray<CDataCommunicationShortCut> m_CommunicationShortCutList;  // offset: 0x240
    CMatchingProfile m_MatchingProfile;  // offset: 0x260
    CArisenProfile m_ArisenProfile;  // offset: 0x298
    b8 m_bHideEquipHead;  // offset: 0x2c0
    b8 m_bHideEquipLantern;  // offset: 0x2c1
    b8 m_bHideEquipHeadPawn;  // offset: 0x2c2
    b8 m_bHideEquipLanternPawn;  // offset: 0x2c3
    u8 m_ucArisenProfileShareRange;  // offset: 0x2c4
    u8 m_ucOnlineStatus;  // offset: 0x2c5
    static MyDTI DTI;
};
