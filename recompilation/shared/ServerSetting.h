#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "Party.h"
#include "Server.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterItemSlotInfo;
class CDataCommonU32;
class CDataJewelryEquipLimit;
class CDataPartyMemberMaxNum;
class CDataURLInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataGameSetting;
class CDataLoginSetting;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataGameSetting : public CPacketDataBase
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
    explicit CDataGameSetting();
    explicit CDataGameSetting(u32, u32, u32, u32, u32, u32, u32, u32, u32, u8, const MtTypedArray<CDataCharacterItemSlotInfo>&, u32, u8, b8, u8, u32, u32, u32, u32, u32, u32, u32, const MtTypedArray<CDataURLInfo>&, const MtTypedArray<CDataPartyMemberMaxNum>&, u32, u32, u32, const char*, const char*, u32, u8, const MtTypedArray<CDataJewelryEquipLimit>&, u32, u32, u32, u32, u32, u32, const MtTypedArray<CDataCommonU32>&, u32);
public:
    u32 m_unMainPawnMax;  // offset: 0x8
    u32 m_unSupportPawnMax;  // offset: 0xc
    u32 m_unJobLevelMax;  // offset: 0x10
    u32 m_unCraftLevelMax;  // offset: 0x14
    u32 m_unCraftSkillLevelMax;  // offset: 0x18
    u32 m_unUserListMax;  // offset: 0x1c
    u32 m_unClanLvMax;  // offset: 0x20
    u32 m_unClanMemberMax;  // offset: 0x24
    u32 m_unClanLeaveIntervalTime;  // offset: 0x28
    u8 m_ucCharacterNumMax;  // offset: 0x2c
    MtTypedArray<CDataCharacterItemSlotInfo> m_GlobalItemSlotNumMaxList;  // offset: 0x30
    u32 m_unPawnCreateItemID;  // offset: 0x50
    u8 m_ucPawnCreateItemNum;  // offset: 0x54
    b8 m_bEnableVisualEquip;  // offset: 0x55
    u8 m_ucEquipColorChangeGrade;  // offset: 0x56
    u32 m_unFriendListMax;  // offset: 0x58
    u32 m_unRecentPlayerMax;  // offset: 0x5c
    u32 m_unBlackListMax;  // offset: 0x60
    u32 m_unHistoryListMax;  // offset: 0x64
    u32 m_unCharacterReviveGP;  // offset: 0x68
    u32 m_unPawnReviveGP;  // offset: 0x6c
    u32 m_unLostPawnReviveGP;  // offset: 0x70
    MtTypedArray<CDataURLInfo> m_UrlInfoList;  // offset: 0x78
    MtTypedArray<CDataPartyMemberMaxNum> m_PartyMemberMaxNumList;  // offset: 0x98
    u32 m_unGroupChatMemberMax;  // offset: 0xb8
    u32 m_unEventCodeInputLockFailNum;  // offset: 0xbc
    u32 m_unEventCodeLockTime;  // offset: 0xc0
    MtString m_wstrCapLinkServerVerion;  // offset: 0xc8
    MtString m_wstrCapLinkApiVerion;  // offset: 0xd0
    u32 m_unPawnPresentItemID;  // offset: 0xd8
    u8 m_ucPawnPresentItemNum;  // offset: 0xdc
    MtTypedArray<CDataJewelryEquipLimit> m_JewelryEquipLimitList;  // offset: 0xe0
    u32 m_unJobPointMax;  // offset: 0x100
    u32 m_unPlayPointMax;  // offset: 0x104
    u32 m_unPlayPointLevelMin;  // offset: 0x108
    u32 m_unBazaarSerchTime;  // offset: 0x10c
    u32 m_unBazaarSerchCautionTime;  // offset: 0x110
    u32 m_unBazaarSerchCautionCount;  // offset: 0x114
    MtTypedArray<CDataCommonU32> m_ClanBaseStageList;  // offset: 0x118
    u32 m_unMailCacheExpireTime;  // offset: 0x138
    static MyDTI DTI;
};

class CDataLoginSetting : public CPacketDataBase
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
    explicit CDataLoginSetting();
    explicit CDataLoginSetting(u32, u32, u8, b8, u32, const MtTypedArray<CDataURLInfo>&, u32);
public:
    u32 m_unJobLevelMax;  // offset: 0x8
    u32 m_unClanMemberMax;  // offset: 0xc
    u8 m_ucCharacterNumMax;  // offset: 0x10
    b8 m_bEnableVisualEquip;  // offset: 0x11
    u32 m_unFriendListMax;  // offset: 0x14
    MtTypedArray<CDataURLInfo> m_UrlInfoList;  // offset: 0x18
    u32 m_unNoOperationTimeOutTime;  // offset: 0x38
    static MyDTI DTI;
};
