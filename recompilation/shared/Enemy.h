#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"
#include "nEnemyID.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataNamedEnemyParamClient;
class CDataTraningRoomEnemyHeader;
namespace nEnemy { struct stRegionBreakActList; }
namespace nEnemy { struct EM_BASIC_INFO; }

namespace nEnemy {
    enum E_ENEMY_TARGET_TYPE
    {
        ENEMY_TARGET_TYPE_NONE = 1,
        ENEMY_TARGET_TYPE_AREA_BOSS = 6,
        ENEMY_TARGET_TYPE_STAGE_BOSS = 7,
        ENEMY_TARGET_TYPE_MAX = 8,
    };
}  // namespace nEnemy

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nEnemy {

    // Forward declarations
    struct stRegionBreakActList;
    struct EM_BASIC_INFO;

    struct stRegionBreakActList
    {
    public:
        u32 ActNo;  // offset: 0x0
    };

    struct EM_BASIC_INFO
    {
    public:
        u32 id;  // offset: 0x0
        nEnemy::EM_HANG_TYPE hangType;  // offset: 0x4
        nEnemy::EM_CLASS_TYPE classType;  // offset: 0x8
        u32 enemyFlag;  // offset: 0xc
    };

    ENEMY_ID findEnemyEnumID(u32 id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nEnemy.cpp:151
    bool isEnemyGroup(ENEMY_GROUP grp, ENEMY_ID enemyID);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nEnemyUtility.cpp:28
    bool checkEnemyGroup(ENEMY_ID startID, ENEMY_ID endID, ENEMY_ID targetID);
    MT_CTSTR makeAltPath(u32 enemyId, MT_CHAR* path);
    MT_CTSTR makeArcPath(u32 enemyId, MT_CHAR* path);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nEnemyUtility.cpp:183

}  // namespace nEnemy

class CDataNamedEnemyParamClient : public CPacketDataBase
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
    explicit CDataNamedEnemyParamClient();
    explicit CDataNamedEnemyParamClient(u32, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u8);
public:
    u32 m_unId;  // offset: 0x8
    u16 m_usRateHp;  // offset: 0xc
    u16 m_usRateHpPart;  // offset: 0xe
    u16 m_usRatePhyAttackBase;  // offset: 0x10
    u16 m_usRatePhyAttackEq;  // offset: 0x12
    u16 m_usRatePhyDefenceBase;  // offset: 0x14
    u16 m_usRatePhyDefenceEq;  // offset: 0x16
    u16 m_usRateMagAttackBase;  // offset: 0x18
    u16 m_usRateMagAttackEq;  // offset: 0x1a
    u16 m_usRateMagDefenceBase;  // offset: 0x1c
    u16 m_usRateMagDefenceEq;  // offset: 0x1e
    u16 m_usRateStr;  // offset: 0x20
    u16 m_usRateGuardAtk;  // offset: 0x22
    u16 m_usRateGuardDefBase;  // offset: 0x24
    u16 m_usRateGuardDefEq;  // offset: 0x26
    u16 m_usRateShrinkDef;  // offset: 0x28
    u16 m_usRateBlowDef;  // offset: 0x2a
    u16 m_usRateDownDef;  // offset: 0x2c
    u16 m_usRateShakeDef;  // offset: 0x2e
    u16 m_usRateShrinkDefPart;  // offset: 0x30
    u16 m_usRateBlowDefPart;  // offset: 0x32
    u16 m_usRateOcdDef;  // offset: 0x34
    u16 m_usRateOcdAtk;  // offset: 0x36
    u8 m_ucNameTypeId;  // offset: 0x38
    static MyDTI DTI;
};

class CDataTraningRoomEnemyHeader : public CPacketDataBase
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
    explicit CDataTraningRoomEnemyHeader();
    explicit CDataTraningRoomEnemyHeader(u32, const char*);
public:
    u32 m_unID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataNamedEnemyParamClient::CDataNamedEnemyParamClient() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucNameTypeId = static_cast<u8>(0);
    this->m_usRateShrinkDefPart = static_cast<u16>(0);
    this->m_usRateBlowDefPart = static_cast<u16>(0);
    this->m_usRateOcdDef = static_cast<u16>(0);
    this->m_usRateOcdAtk = static_cast<u16>(0);
    this->m_usRateShrinkDef = static_cast<u16>(0);
    this->m_usRateBlowDef = static_cast<u16>(0);
    this->m_usRateDownDef = static_cast<u16>(0);
    this->m_usRateShakeDef = static_cast<u16>(0);
    this->m_usRateStr = static_cast<u16>(0);
    this->m_usRateGuardAtk = static_cast<u16>(0);
    this->m_usRateGuardDefBase = static_cast<u16>(0);
    this->m_usRateGuardDefEq = static_cast<u16>(0);
    this->m_usRateMagAttackBase = static_cast<u16>(0);
    this->m_usRateMagAttackEq = static_cast<u16>(0);
    this->m_usRateMagDefenceBase = static_cast<u16>(0);
    this->m_usRateMagDefenceEq = static_cast<u16>(0);
    this->m_usRatePhyAttackBase = static_cast<u16>(0);
    this->m_usRatePhyAttackEq = static_cast<u16>(0);
    this->m_usRatePhyDefenceBase = static_cast<u16>(0);
    this->m_usRatePhyDefenceEq = static_cast<u16>(0);
    this->m_unId = static_cast<u32>(0);
    this->m_usRateHp = static_cast<u16>(0);
    this->m_usRateHpPart = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataTraningRoomEnemyHeader::CDataTraningRoomEnemyHeader() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unID = static_cast<u32>(0);
}
