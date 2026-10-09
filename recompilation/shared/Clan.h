#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterListElement;
class CDataCharacterName;
class CDataCommonU32;
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataBattleResultInfo;
class CDataClanConciergeInfo;
class CDataClanConciergeNpc;
class CDataClanDungeonInfo;
class CDataClanFunctionInfo;
class CDataClanHistoryElement;
class CDataClanJoinRequest;
class CDataClanMemberInfo;
class CDataClanParam;
class CDataClanPartnerPawnInfo;
class CDataClanScoutEntryInviteInfo;
class CDataClanScoutEntryParam;
class CDataClanScoutEntrySearchResult;
class CDataClanSearchParam;
class CDataClanSearchResult;
class CDataClanServerParam;
class CDataClanShopBuffInfo;
class CDataClanShopBuffItem;
class CDataClanShopConciergeItem;
class CDataClanShopFunctionInfo;
class CDataClanShopFunctionItem;
class CDataClanShopInfo;
class CDataClanShopLineupName;
class CDataClanUserParam;
class CDataClanValueInfo;
class CDataPawnExpeditionClanSallySpotInfo;
class CDataPawnExpeditionInformation;

namespace nClan {
    enum E_CLAN_PERMISSION
    {
        CLAN_PERMISSION_NONE = 0,
        CLAN_PERMISSION_JOIN_REQUEST_OK = 1,
        CLAN_PERMISSION_JOIN_REQUEST_NG = 2,
        CLAN_PERMISSION_SCOUT_ENTRY_INVITE = 3,
        CLAN_PERMISSION_MEMBER_KICK = 4,
        CLAN_PERMISSION_MASTER_NEGOTIATE = 5,
        CLAN_PERMISSION_STATUS_CHANGE = 6,
        CLAN_PERMISSION_POSITION_SET = 7,
        CLAN_PERMISSION_INVITE = 8,
        CLAN_PERMISSION_SHOP_BUY = 9,
        CLAN_PERMISSION_CONCIERGE_CHANGE = 10,
        CLAN_PERMISSION_BASE_RELEASE = 11,
    };
}  // namespace nClan

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CCharacterName = CDataCharacterName;
using CClanMemberInfo = CDataClanMemberInfo;
using CClanServerParam = CDataClanServerParam;
using CClanUserParam = CDataClanUserParam;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using b8 = bool;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataBattleResultInfo : public CPacketDataBase
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
    explicit CDataBattleResultInfo();
    explicit CDataBattleResultInfo(u32, u32, u32);
public:
    u32 m_unEnemyId;  // offset: 0x8
    u32 m_unEnemyNum;  // offset: 0xc
    u32 m_unEnemyLevel;  // offset: 0x10
    static MyDTI DTI;
};

class CDataClanConciergeNpc : public CPacketDataBase
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
    explicit CDataClanConciergeNpc();
    explicit CDataClanConciergeNpc(u32, u32, b8, u32);
public:
    u32 m_unNpcId;  // offset: 0x8
    u32 m_unPrice;  // offset: 0xc
    b8 m_bIsInit;  // offset: 0x10
    u32 m_unSortId;  // offset: 0x14
    static MyDTI DTI;
};

class CDataClanDungeonInfo : public CPacketDataBase
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
    explicit CDataClanDungeonInfo();
    explicit CDataClanDungeonInfo(const MtTypedArray<CDataCommonU32>&);
public:
    MtTypedArray<CDataCommonU32> m_ReleaseIdList;  // offset: 0x8
    static MyDTI DTI;
};

class CDataClanFunctionInfo : public CPacketDataBase
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
    explicit CDataClanFunctionInfo();
    explicit CDataClanFunctionInfo(const MtTypedArray<CDataCommonU32>&);
public:
    MtTypedArray<CDataCommonU32> m_ReleaseIdList;  // offset: 0x8
    static MyDTI DTI;
};

class CDataClanHistoryElement : public CPacketDataBase
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
    explicit CDataClanHistoryElement();
    explicit CDataClanHistoryElement(s64 in_Date, u8 in_Type, const CCharacterName& in_CharacterName, u32 in_Value1, u32 in_Value2, u32 in_Value3, const char* in_strFreeText);
public:
    s64 m_llDate;  // offset: 0x8
    u8 m_ucType;  // offset: 0x10
    CCharacterName m_CharacterName;  // offset: 0x18
    u32 m_unValue1;  // offset: 0x30
    u32 m_unValue2;  // offset: 0x34
    u32 m_unValue3;  // offset: 0x38
    MtString m_wstrFreeText;  // offset: 0x40
    static MyDTI DTI;
};

class CDataClanJoinRequest : public CPacketDataBase
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
    explicit CDataClanJoinRequest();
    explicit CDataClanJoinRequest(u32, const char*, const CCommunityCharacterBaseInfo&, s64);
public:
    u32 m_unClanID;  // offset: 0x8
    MtString m_wstrClanName;  // offset: 0x10
    CCommunityCharacterBaseInfo m_CommunityCharacterBaseInfo;  // offset: 0x18
    s64 m_llCreated;  // offset: 0x48
    static MyDTI DTI;
};

class CDataClanMemberInfo : public CPacketDataBase
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
    explicit CDataClanMemberInfo();
    explicit CDataClanMemberInfo(u32, s64, s64, s64, u32, const CCharacterListElement&);
public:
    u32 m_unRank;  // offset: 0x8
    s64 m_llCreated;  // offset: 0x10
    s64 m_llLastLoginTime;  // offset: 0x18
    s64 m_llLeaveTime;  // offset: 0x20
    u32 m_unPermission;  // offset: 0x28
    CCharacterListElement m_CharacterListElement;  // offset: 0x30
    static MyDTI DTI;
};

class CDataClanPartnerPawnInfo : public CPacketDataBase
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
    explicit CDataClanPartnerPawnInfo();
    explicit CDataClanPartnerPawnInfo(const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataCommonU32>&);
public:
    MtTypedArray<CDataCommonU32> m_MyPartnerPawnList;  // offset: 0x8
    MtTypedArray<CDataCommonU32> m_MemberPartnerPawnList;  // offset: 0x28
    static MyDTI DTI;
};

class CDataClanScoutEntryInviteInfo : public CPacketDataBase
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
    explicit CDataClanScoutEntryInviteInfo();
    explicit CDataClanScoutEntryInviteInfo(u32, u32, const char*, const CCommunityCharacterBaseInfo&, s64);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unClanID;  // offset: 0xc
    MtString m_wstrClanName;  // offset: 0x10
    CCommunityCharacterBaseInfo m_BaseInfo;  // offset: 0x18
    s64 m_llCreated;  // offset: 0x48
    static MyDTI DTI;
};

class CDataClanScoutEntryParam : public CPacketDataBase
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
    explicit CDataClanScoutEntryParam();
    explicit CDataClanScoutEntryParam(u16, u16, u32, u32, u32, u32, const char*);
public:
    u16 m_usLv;  // offset: 0x8
    u16 m_usMemberNum;  // offset: 0xa
    u32 m_unMotto;  // offset: 0xc
    u32 m_unActiveDays;  // offset: 0x10
    u32 m_unActiveTime;  // offset: 0x14
    u32 m_unCharacteristic;  // offset: 0x18
    MtString m_wstrComment;  // offset: 0x20
    static MyDTI DTI;
};

class CDataClanScoutEntrySearchResult : public CPacketDataBase
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
    explicit CDataClanScoutEntrySearchResult();
    explicit CDataClanScoutEntrySearchResult(const CCommunityCharacterBaseInfo&, const char*);
public:
    CCommunityCharacterBaseInfo m_CommunityCharacterBaseInfo;  // offset: 0x8
    MtString m_wstrComment;  // offset: 0x38
    static MyDTI DTI;
};

class CDataClanSearchParam : public CPacketDataBase
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
    explicit CDataClanSearchParam();
    explicit CDataClanSearchParam(u8, const char*, u16, u16, u32, u32, u32, u32);
public:
    u8 m_ucNameSearchType;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u16 m_usLv;  // offset: 0x18
    u16 m_usMemberNum;  // offset: 0x1a
    u32 m_unMotto;  // offset: 0x1c
    u32 m_unActiveDays;  // offset: 0x20
    u32 m_unActiveTime;  // offset: 0x24
    u32 m_unCharacteristic;  // offset: 0x28
    static MyDTI DTI;
};

class CDataClanSearchResult : public CPacketDataBase
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
    explicit CDataClanSearchResult();
    explicit CDataClanSearchResult(u32, const char*, u16, u16, u32, u8, u8, u8, u8, u32, const CCharacterName&, s64);
public:
    u32 m_unClanID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u16 m_usLv;  // offset: 0x18
    u16 m_usMemberNum;  // offset: 0x1a
    u32 m_unMotto;  // offset: 0x1c
    u8 m_ucEmblemMarkType;  // offset: 0x20
    u8 m_ucEmblemBaseType;  // offset: 0x21
    u8 m_ucEmblemBaseMainColor;  // offset: 0x22
    u8 m_ucEmblemBaseSubColor;  // offset: 0x23
    u32 m_unMasterCharacterID;  // offset: 0x24
    CCharacterName m_MasterCharacterName;  // offset: 0x28
    s64 m_llCreated;  // offset: 0x40
    static MyDTI DTI;
};

class CDataClanServerParam : public CPacketDataBase
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
    explicit CDataClanServerParam();
    explicit CDataClanServerParam(u32, u16, u16, const CClanMemberInfo&, b8, b8, b8, u32, u32, u32);
public:
    u32 m_unID;  // offset: 0x8
    u16 m_usLv;  // offset: 0xc
    u16 m_usMemberNum;  // offset: 0xe
    CClanMemberInfo m_MasterInfo;  // offset: 0x10
    b8 m_bIsSystemRestriction;  // offset: 0xa8
    b8 m_bIsClanBaseRelease;  // offset: 0xa9
    b8 m_bCanClanBaseRelease;  // offset: 0xaa
    u32 m_unTotalClanPoint;  // offset: 0xac
    u32 m_unMoneyClanPoint;  // offset: 0xb0
    u32 m_unNextClanPoint;  // offset: 0xb4
    static MyDTI DTI;
};

class CDataClanShopBuffInfo : public CPacketDataBase
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
    explicit CDataClanShopBuffInfo();
    explicit CDataClanShopBuffInfo(u32, u8);
public:
    u32 m_unBuffID;  // offset: 0x8
    u8 m_ucBuffType;  // offset: 0xc
    static MyDTI DTI;
};

class CDataClanShopBuffItem : public CPacketDataBase
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
    explicit CDataClanShopBuffItem();
    explicit CDataClanShopBuffItem(u32, u32, u8, u32, const char*, const MtTypedArray<CDataClanShopBuffInfo>&, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unLineupId;  // offset: 0x8
    u32 m_unRequireClanPoint;  // offset: 0xc
    u8 m_ucRequiredLevel;  // offset: 0x10
    u32 m_unIconID;  // offset: 0x14
    MtString m_wstrName;  // offset: 0x18
    MtTypedArray<CDataClanShopBuffInfo> m_BuffInfo;  // offset: 0x20
    MtTypedArray<CDataCommonU32> m_RequireLineupId;  // offset: 0x40
    static MyDTI DTI;
};

class CDataClanShopConciergeItem : public CPacketDataBase
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
    explicit CDataClanShopConciergeItem();
    explicit CDataClanShopConciergeItem(u32, u32);
public:
    u32 m_unNpcId;  // offset: 0x8
    u32 m_unRequireClanPoint;  // offset: 0xc
    static MyDTI DTI;
};

class CDataClanShopFunctionInfo : public CPacketDataBase
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
    explicit CDataClanShopFunctionInfo();
    explicit CDataClanShopFunctionInfo(u32, u8);
public:
    u32 m_unFunctionID;  // offset: 0x8
    u8 m_ucFunctionType;  // offset: 0xc
    static MyDTI DTI;
};

class CDataClanShopFunctionItem : public CPacketDataBase
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
    explicit CDataClanShopFunctionItem();
    explicit CDataClanShopFunctionItem(u32, u32, u8, u32, const char*, const MtTypedArray<CDataClanShopFunctionInfo>&, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unLineupId;  // offset: 0x8
    u32 m_unRequireClanPoint;  // offset: 0xc
    u8 m_ucRequiredLevel;  // offset: 0x10
    u32 m_unIconID;  // offset: 0x14
    MtString m_wstrName;  // offset: 0x18
    MtTypedArray<CDataClanShopFunctionInfo> m_FunctionInfo;  // offset: 0x20
    MtTypedArray<CDataCommonU32> m_RequireLineupId;  // offset: 0x40
    static MyDTI DTI;
};

class CDataClanShopInfo : public CPacketDataBase
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
    explicit CDataClanShopInfo();
    explicit CDataClanShopInfo(u32, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unClanPoint;  // offset: 0x8
    MtTypedArray<CDataCommonU32> m_CurrentFunctionList;  // offset: 0x10
    MtTypedArray<CDataCommonU32> m_CurrentBuffList;  // offset: 0x30
    static MyDTI DTI;
};

class CDataClanShopLineupName : public CPacketDataBase
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
    explicit CDataClanShopLineupName();
    explicit CDataClanShopLineupName(u32, const char*);
public:
    u32 m_unLineupID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    static MyDTI DTI;
};

class CDataClanUserParam : public CPacketDataBase
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
    explicit CDataClanUserParam();
    explicit CDataClanUserParam(const char*, const char*, u8, u8, u8, u8, u32, u32, u32, u32, b8, const char*, const char*, s64);
public:
    MtString m_wstrName;  // offset: 0x8
    MtString m_wstrShortName;  // offset: 0x10
    u8 m_ucEmblemMarkType;  // offset: 0x18
    u8 m_ucEmblemBaseType;  // offset: 0x19
    u8 m_ucEmblemBaseMainColor;  // offset: 0x1a
    u8 m_ucEmblemBaseSubColor;  // offset: 0x1b
    u32 m_unMotto;  // offset: 0x1c
    u32 m_unActiveDays;  // offset: 0x20
    u32 m_unActiveTime;  // offset: 0x24
    u32 m_unCharacteristic;  // offset: 0x28
    b8 m_bIsPublish;  // offset: 0x2c
    MtString m_wstrComment;  // offset: 0x30
    MtString m_wstrBoardMessage;  // offset: 0x38
    s64 m_llCreated;  // offset: 0x40
    static MyDTI DTI;
};

class CDataClanValueInfo : public CPacketDataBase
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
    explicit CDataClanValueInfo();
    explicit CDataClanValueInfo(u8, u32);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unValue;  // offset: 0xc
    static MyDTI DTI;
};

class CDataPawnExpeditionClanSallySpotInfo : public CPacketDataBase
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
    explicit CDataPawnExpeditionClanSallySpotInfo();
    explicit CDataPawnExpeditionClanSallySpotInfo(u32, u32, u32);
public:
    u32 m_unAreaID;  // offset: 0x8
    u32 m_unSpotID;  // offset: 0xc
    u32 m_unSallyNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataPawnExpeditionInformation : public CPacketDataBase
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
    explicit CDataPawnExpeditionInformation();
    explicit CDataPawnExpeditionInformation(u8, u8, u8);
public:
    u8 m_ucSallyStatus;  // offset: 0x8
    u8 m_ucGoldenSallyPrice;  // offset: 0x9
    u8 m_ucChargeSallyPrice;  // offset: 0xa
    static MyDTI DTI;
};

class CDataClanConciergeInfo : public CPacketDataBase
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
    explicit CDataClanConciergeInfo();
    explicit CDataClanConciergeInfo(u32, const MtTypedArray<CDataClanConciergeNpc>&);
public:
    u32 m_unNpcId;  // offset: 0x8
    MtTypedArray<CDataClanConciergeNpc> m_ClanConciergeNpcList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataClanParam : public CPacketDataBase
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
    explicit CDataClanParam();
    explicit CDataClanParam(const CClanUserParam&, const CClanServerParam&);
public:
    CClanUserParam m_ClanUserParam;  // offset: 0x8
    CClanServerParam m_ClanServerParam;  // offset: 0x50
    static MyDTI DTI;
};
