#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "CharacterEdit.h"
#include "Community.h"
#include "GP.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterListElement;
class CDataEditInfo;
class CDataEquipItemInfo;
class CDataGPCourseValid;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataCharacterLevelParam;
class CDataCharacterListInfo;
class CDataCharacterMessage;
class CDataCharacterMsgSet;
class CDataCharacterSearchParam;
class CDataCommunicationShortCut;
class CDataItemStorageIndicateNum;
class CDataMasterInfo;
class CDataMatchingProfile;
class CDataShortCut;
class CDataUpdateWalletPoint;
class CDataWalletPoint;

namespace nCharacter {
    enum E_EDIT_BODY_TYPE
    {
        EDIT_BODY_TYPE_NONE = 0,
        EDIT_BODY_TYPE_MALE = 1,
        EDIT_BODY_TYPE_FEMALE = 2,
    };
}  // namespace nCharacter

namespace nCharacter {
    enum E_ONLINE_STATUS
    {
        ONLINE_STATUS_NONE = 0,
        ONLINE_STATUS_ONLINE = 1,
        ONLINE_STATUS_OFFLINE = 2,
        ONLINE_STATUS_LEAVING = 3,
        ONLINE_STATUS_BUSY = 4,
        ONLINE_STATUS_ENTRY_BOARD = 5,
        ONLINE_STATUS_QUICK_MATCH = 6,
        ONLINE_STATUS_EVENT = 7,
        ONLINE_STATUS_CONTENTS = 8,
        ONLINE_STATUS_PT_LEADER = 9,
        ONLINE_STATUS_PT_MEMBER = 10,
        ONLINE_STATUS_LOST = 11,
        ONLINE_STATUS_SERVER_MOVE = 12,
        ONLINE_STATUS_NUM = 13,
    };
}  // namespace nCharacter

namespace nCharacter {
    enum E_WALLET_POINT_TYPE
    {
        WALLET_POINT_TYPE_INVALID = 0,
        WALLET_POINT_TYPE_TOP = 1,
        WALLET_POINT_TYPE_GOLD = 1,
        WALLET_POINT_TYPE_RIM = 2,
        WALLET_POINT_TYPE_ORB = 3,
        WALLET_POINT_TYPE_TICKET = 4,
        WALLET_POINT_TYPE_GP = 5,
        WALLET_POINT_TYPE_SUPPORT = 6,
        WALLET_POINT_TYPE_JP_RESET = 7,
        WALLET_POINT_TYPE_CP_RESET = 8,
        WALLET_POINT_TYPE_MAX = 9,
        WALLET_POINT_TYPE_NUM = 8,
    };
}  // namespace nCharacter

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CEditInfo = CDataEditInfo;
using CMatchingProfile = CDataMatchingProfile;
using CWalletPoint = CDataWalletPoint;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataCharacterLevelParam : public CPacketDataBase
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
    explicit CDataCharacterLevelParam();
    explicit CDataCharacterLevelParam(u16, u16, u16, u16, u16, u16, u16, u16, u16, u16);
public:
    u16 m_usAttack;  // offset: 0x8
    u16 m_usMagAttack;  // offset: 0xa
    u16 m_usDefence;  // offset: 0xc
    u16 m_usMagDefence;  // offset: 0xe
    u16 m_usStrength;  // offset: 0x10
    u16 m_usDownPower;  // offset: 0x12
    u16 m_usShakePower;  // offset: 0x14
    u16 m_usStunPower;  // offset: 0x16
    u16 m_usConstitution;  // offset: 0x18
    u16 m_usGuts;  // offset: 0x1a
    static MyDTI DTI;
};

class CDataCharacterMessage : public CPacketDataBase
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
    explicit CDataCharacterMessage();
    explicit CDataCharacterMessage(u32, const char*, u32, b8);
public:
    u32 m_unMessageNo;  // offset: 0x8
    MtString m_wstrMessage;  // offset: 0x10
    u32 m_unEmotion;  // offset: 0x18
    b8 m_bEmotoChat;  // offset: 0x1c
    static MyDTI DTI;
};

class CDataCharacterMsgSet : public CPacketDataBase
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
    explicit CDataCharacterMsgSet();
    explicit CDataCharacterMsgSet(u32, const char*, const MtTypedArray<CDataCharacterMessage>&);
public:
    u32 m_unSetNo;  // offset: 0x8
    MtString m_wstrMsgSetName;  // offset: 0x10
    MtTypedArray<CDataCharacterMessage> m_CharacterMessageList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataCharacterSearchParam : public CPacketDataBase
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
    explicit CDataCharacterSearchParam();
    explicit CDataCharacterSearchParam(const char*, const char*);
public:
    MtString m_wstrFirstName;  // offset: 0x8
    MtString m_wstrLastName;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCommunicationShortCut : public CPacketDataBase
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
    explicit CDataCommunicationShortCut();
    explicit CDataCommunicationShortCut(u32, u32, u8, u8, u32);
public:
    u32 m_unPageNo;  // offset: 0x8
    u32 m_unButtonNo;  // offset: 0xc
    u8 m_ucType;  // offset: 0x10
    u8 m_ucCategory;  // offset: 0x11
    u32 m_unId;  // offset: 0x14
    static MyDTI DTI;
};

class CDataItemStorageIndicateNum : public CPacketDataBase
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
    explicit CDataItemStorageIndicateNum();
    explicit CDataItemStorageIndicateNum(u32 in_ItemNum, u8 in_StorageType);
public:
    u32 m_unItemNum;  // offset: 0x8
    u8 m_ucStorageType;  // offset: 0xc
    static MyDTI DTI;
};

class CDataMasterInfo : public CPacketDataBase
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
    explicit CDataMasterInfo();
    explicit CDataMasterInfo(u32, s8);
public:
    u32 m_unUniqueID;  // offset: 0x8
    s8 m_cMasterIndex;  // offset: 0xc
    static MyDTI DTI;
};

class CDataMatchingProfile : public CPacketDataBase
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
    explicit CDataMatchingProfile();
    explicit CDataMatchingProfile(u8, u32, u8, u32, u32, u32, u32, const char*, b8);
public:
    u8 m_ucEntryJob;  // offset: 0x8
    u32 m_unEntryJobLevel;  // offset: 0xc
    u8 m_ucCurrentJob;  // offset: 0x10
    u32 m_unCurrentJobLevel;  // offset: 0x14
    u32 m_unObjectiveType1;  // offset: 0x18
    u32 m_unObjectiveType2;  // offset: 0x1c
    u32 m_unPlayStyle;  // offset: 0x20
    MtString m_wstrComment;  // offset: 0x28
    b8 m_bIsJoinParty;  // offset: 0x30
    static MyDTI DTI;
};

class CDataShortCut : public CPacketDataBase
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
    explicit CDataShortCut();
    explicit CDataShortCut(u32, u32, u32, u32, u32, u8);
public:
    u32 m_unPageNo;  // offset: 0x8
    u32 m_unButtonNo;  // offset: 0xc
    u32 m_unShortcutID;  // offset: 0x10
    u32 m_unU32Data;  // offset: 0x14
    u32 m_unF32Data;  // offset: 0x18
    u8 m_ucExexType;  // offset: 0x1c
    static MyDTI DTI;
};

class CDataWalletPoint : public CPacketDataBase
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
    explicit CDataWalletPoint();
    explicit CDataWalletPoint(u8, u32);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unValue;  // offset: 0xc
    static MyDTI DTI;
};

class CDataCharacterListInfo : public CPacketDataBase
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
    explicit CDataCharacterListInfo();
    explicit CDataCharacterListInfo(const CCharacterListElement&, const CEditInfo&, const CMatchingProfile&, const MtTypedArray<CDataEquipItemInfo>&, const MtTypedArray<CDataGPCourseValid>&, u8, const char*, const char*, b8);
public:
    CCharacterListElement m_CharacterListElement;  // offset: 0x8
    CEditInfo m_EditInfo;  // offset: 0x70
    CMatchingProfile m_MatchingProfile;  // offset: 0xf8
    MtTypedArray<CDataEquipItemInfo> m_EquipList;  // offset: 0x130
    MtTypedArray<CDataGPCourseValid> m_GpCourseValidList;  // offset: 0x150
    u8 m_ucNextFlowType;  // offset: 0x170
    MtString m_wstrClanName;  // offset: 0x178
    MtString m_wstrClanShortName;  // offset: 0x180
    b8 m_bIsClanMemberNotice;  // offset: 0x188
    static MyDTI DTI;
};

class CDataUpdateWalletPoint : public CPacketDataBase
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
    explicit CDataUpdateWalletPoint();
    explicit CDataUpdateWalletPoint(const CWalletPoint&, s32, u32);
public:
    CWalletPoint m_PointParam;  // offset: 0x8
    s32 m_nAddPoint;  // offset: 0x18
    u32 m_unExtraBonusPoint;  // offset: 0x1c
    static MyDTI DTI;
};
