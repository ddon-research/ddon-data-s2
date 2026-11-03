#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "CharacterCommon.h"
#include "Common.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"

// Forward declarations
class CDataCommonU32;
class CDataContextAcquirementData;
class CDataContextNormalSkillData;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataContextBase;
class CDataContextCrestData;
class CDataContextEquipData;
class CDataContextEquipJobItemData;
class CDataContextJobData;
class CDataContextPlayerInfo;
class CDataContextSetAdditional;
class CDataContextSetBase;
class CDataContextSetInfo;
class CDataNetPos;
class CDataOcdActive;
class CDataOcdImmuneLv;
class CDataVector3;

// Type aliases from DWARF
using CContextSetAdditional = CDataContextSetAdditional;
using CContextSetBase = CDataContextSetBase;
using CNetPos = CDataNetPos;
using CVector3 = CDataVector3;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using b8 = bool;
using f32 = float;
using f64 = double;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataContextCrestData : public CPacketDataBase
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
    explicit CDataContextCrestData();
    explicit CDataContextCrestData(u16);
public:
    u16 m_usItemID;  // offset: 0x8
    static MyDTI DTI;
};

class CDataContextEquipData : public CPacketDataBase
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
    explicit CDataContextEquipData();
    explicit CDataContextEquipData(u16, u8, u32, const MtTypedArray<CDataContextCrestData>&);
public:
    u16 m_usItemID;  // offset: 0x8
    u8 m_ucColorNo;  // offset: 0xa
    u32 m_unQualityParam;  // offset: 0xc
    MtTypedArray<CDataContextCrestData> m_CrestDataList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataContextEquipJobItemData : public CPacketDataBase
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
    explicit CDataContextEquipJobItemData();
    explicit CDataContextEquipJobItemData(u16, u8);
public:
    u16 m_usItemID;  // offset: 0x8
    u8 m_ucSlotNo;  // offset: 0xa
    static MyDTI DTI;
};

class CDataContextJobData : public CPacketDataBase
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
    explicit CDataContextJobData();
    explicit CDataContextJobData(u8, u16, u64, u64);
public:
    u8 m_ucJob;  // offset: 0x8
    u16 m_usLv;  // offset: 0xa
    u64 m_ullExp;  // offset: 0x10
    u64 m_ullJobPoint;  // offset: 0x18
    static MyDTI DTI;
};

class CDataContextSetBase : public CPacketDataBase
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
    explicit CDataContextSetBase();
    explicit CDataContextSetBase(u32, u32, s32, s32, s32);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unUniqueID;  // offset: 0xc
    s32 m_nStageNo;  // offset: 0x10
    s32 m_nEncountArea;  // offset: 0x14
    s32 m_nMasterIndex;  // offset: 0x18
    static MyDTI DTI;
};

class CDataNetPos : public CPacketDataBase
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
    explicit CDataNetPos();
    explicit CDataNetPos(f64, f32, f64);
public:
    f64 m_dx;  // offset: 0x8
    f32 m_fy;  // offset: 0x10
    f64 m_dz;  // offset: 0x18
    static MyDTI DTI;
};

class CDataOcdActive : public CPacketDataBase
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
    explicit CDataOcdActive();
    explicit CDataOcdActive(u8, u8);
public:
    u8 m_ucOcdUID;  // offset: 0x8
    u8 m_ucOcdActiveLv;  // offset: 0x9
    static MyDTI DTI;
};

class CDataOcdImmuneLv : public CPacketDataBase
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
    explicit CDataOcdImmuneLv();
    explicit CDataOcdImmuneLv(u8, u8);
public:
    u8 m_ucIndex;  // offset: 0x8
    u8 m_ucImmuneLv;  // offset: 0x9
    static MyDTI DTI;
};

class CDataVector3 : public CPacketDataBase
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
    explicit CDataVector3();
    explicit CDataVector3(f32, f32, f32);
public:
    f32 m_fx;  // offset: 0x8
    f32 m_fy;  // offset: 0xc
    f32 m_fz;  // offset: 0x10
    static MyDTI DTI;
};

class CDataContextBase : public CPacketDataBase
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
    explicit CDataContextBase();
    explicit CDataContextBase(int, u32, int, int, const CNetPos&, f32, u8, u8, const char*, const char*, const MtTypedArray<CDataContextEquipData>&, const MtTypedArray<CDataContextEquipData>&, const MtTypedArray<CDataContextEquipJobItemData>&, b8, b8, u8, u8, u32, b8, const MtTypedArray<CDataContextNormalSkillData>&, const MtTypedArray<CDataContextAcquirementData>&, const MtTypedArray<CDataContextAcquirementData>&, u32, u32);
public:
    int m_nMemberIndex;  // offset: 0x8
    u32 m_unPawnId;  // offset: 0xc
    int m_nStageNo;  // offset: 0x10
    int m_nStartPosNo;  // offset: 0x14
    CNetPos m_Pos;  // offset: 0x18
    f32 m_fAngleY;  // offset: 0x38
    u8 m_ucSex;  // offset: 0x3c
    u8 m_ucColor;  // offset: 0x3d
    MtString m_wstrFirstName;  // offset: 0x40
    MtString m_wstrLastName;  // offset: 0x48
    MtTypedArray<CDataContextEquipData> m_ContextEquipPerformanceList;  // offset: 0x50
    MtTypedArray<CDataContextEquipData> m_ContextEquipVisualList;  // offset: 0x70
    MtTypedArray<CDataContextEquipJobItemData> m_ContextEquipJobItemList;  // offset: 0x90
    b8 m_bHideEquipHead;  // offset: 0xb0
    b8 m_bHideEquipLantern;  // offset: 0xb1
    u8 m_ucHmType;  // offset: 0xb2
    u8 m_ucPawnType;  // offset: 0xb3
    u32 m_unCharacterId;  // offset: 0xb4
    b8 m_bSetWaitFlag;  // offset: 0xb8
    MtTypedArray<CDataContextNormalSkillData> m_ContextNormalSkillList;  // offset: 0xc0
    MtTypedArray<CDataContextAcquirementData> m_ContextSkillList;  // offset: 0xe0
    MtTypedArray<CDataContextAcquirementData> m_ContextAbilityList;  // offset: 0x100
    u32 m_unAbilityCostSum;  // offset: 0x120
    u32 m_unAbilityCostMax;  // offset: 0x124
    static MyDTI DTI;
};

class CDataContextPlayerInfo : public CPacketDataBase
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
    explicit CDataContextPlayerInfo();
    explicit CDataContextPlayerInfo(u8, f32, f32, f32, f32, f32, f32, u16, u64, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u64, u32, u32, u32, u32, u32, u32, u32, u8, u8, const MtTypedArray<CDataContextJobData>&, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataOcdActive>&, const CNetPos&, const CVector3&, const CNetPos&, const CNetPos&, u8, u8, u32, u16);
public:
    u8 m_ucJob;  // offset: 0x8
    f32 m_fHP;  // offset: 0xc
    f32 m_fMaxHP;  // offset: 0x10
    f32 m_fWhiteHP;  // offset: 0x14
    f32 m_fStamina;  // offset: 0x18
    f32 m_fMaxStamina;  // offset: 0x1c
    f32 m_fWeight;  // offset: 0x20
    u16 m_usLv;  // offset: 0x24
    u64 m_ullExp;  // offset: 0x28
    u32 m_unAtk;  // offset: 0x30
    u32 m_unDef;  // offset: 0x34
    u32 m_unMAtk;  // offset: 0x38
    u32 m_unMDef;  // offset: 0x3c
    u32 m_unStrength;  // offset: 0x40
    u32 m_unDownPower;  // offset: 0x44
    u32 m_unShakePower;  // offset: 0x48
    u32 m_unStanPower;  // offset: 0x4c
    u32 m_unConstitution;  // offset: 0x50
    u32 m_unGuts;  // offset: 0x54
    u64 m_ullJobPoint;  // offset: 0x58
    u32 m_unGainHp;  // offset: 0x60
    u32 m_unGainStamina;  // offset: 0x64
    u32 m_unGainAttack;  // offset: 0x68
    u32 m_unGainDefense;  // offset: 0x6c
    u32 m_unGainMagicAttack;  // offset: 0x70
    u32 m_unGainMagicDefense;  // offset: 0x74
    u32 m_unActNo;  // offset: 0x78
    u8 m_ucRevivePoint;  // offset: 0x7c
    u8 m_ucCustomSkillGroup;  // offset: 0x7d
    MtTypedArray<CDataContextJobData> m_JobList;  // offset: 0x80
    MtTypedArray<CDataCommonU32> m_ChargeEffectList;  // offset: 0xa0
    MtTypedArray<CDataOcdActive> m_OcdActiveList;  // offset: 0xc0
    CNetPos m_CliffPos;  // offset: 0xe0
    CVector3 m_CliffNormal;  // offset: 0x100
    CNetPos m_CliffStartPos;  // offset: 0x118
    CNetPos m_CliffStartOldPos;  // offset: 0x138
    u8 m_ucCatchType;  // offset: 0x158
    u8 m_ucCatchJointNo;  // offset: 0x159
    u32 m_unCatchTargetUID;  // offset: 0x15c
    u16 m_usCustomWork;  // offset: 0x160
    static MyDTI DTI;
};

class CDataContextSetAdditional : public CPacketDataBase
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
    explicit CDataContextSetAdditional();
    explicit CDataContextSetAdditional(s32, b8, const CNetPos&, f32, f32, f32, u32, u8, u16, u32, u16, u64, u16, u16, const MtTypedArray<CDataOcdActive>&, const MtTypedArray<CDataOcdImmuneLv>&, f32, f32, const CNetPos&, const CVector3&, const CNetPos&, const CNetPos&, u32, s32, const CVector3&, u16, u16, u32, const CNetPos&, u32, u64, u8, u64, u64, u64, u64, u32, b8, b8, u64, const CNetPos&, const CVector3&, const CNetPos&, u32, u8, u8, u32, u32);
public:
    s32 m_nMasterIndex;  // offset: 0x8
    b8 m_bMasterChangeFlag;  // offset: 0xc
    CNetPos m_Pos;  // offset: 0x10
    f32 m_fMoveSpeed;  // offset: 0x30
    f32 m_fMoveAngle;  // offset: 0x34
    f32 m_fAngleY;  // offset: 0x38
    u32 m_unActNo;  // offset: 0x3c
    u8 m_ucActReqPrio;  // offset: 0x40
    u16 m_usActAtkAdjustUniqueID;  // offset: 0x42
    u32 m_unActFreeWork;  // offset: 0x44
    u64 m_ullHp[10];  // offset: 0x48
    u16 m_usUseRegionBit;  // offset: 0x98
    u64 m_ullHpWhite;  // offset: 0xa0
    u16 m_usCommonWork;  // offset: 0xa8
    u16 m_usCustomWork;  // offset: 0xaa
    MtTypedArray<CDataOcdActive> m_OcdActiveList;  // offset: 0xb0
    MtTypedArray<CDataOcdImmuneLv> m_OcdImmuneLvList;  // offset: 0xd0
    f32 m_fEnchantRate;  // offset: 0xf0
    f32 m_fAilmentDamage;  // offset: 0xf4
    CNetPos m_CliffPos;  // offset: 0xf8
    CVector3 m_CliffNormal;  // offset: 0x118
    CNetPos m_CliffStartPos;  // offset: 0x130
    CNetPos m_CliffStartOldPos;  // offset: 0x150
    u32 m_unClimbEnemyID;  // offset: 0x170
    s32 m_nJointNo;  // offset: 0x174
    CVector3 m_JointOffset;  // offset: 0x178
    u16 m_usNodeIndex;  // offset: 0x190
    u16 m_usGeomIndex;  // offset: 0x192
    u32 m_unTargetUID;  // offset: 0x194
    CNetPos m_TargetPos;  // offset: 0x198
    s32 m_nEncountAreaBuff[3];  // offset: 0x1b8
    u32 m_unEnemyStatusGroupNoNum;  // offset: 0x1c4
    u32 m_unEnemyStatusGroupNo[16];  // offset: 0x1c8
    u32 m_unEnemyStatusSubGroupNo[16];  // offset: 0x208
    u64 m_ullEnemyBitCtrlCollision;  // offset: 0x248
    u8 m_ucEnemyCtrlRegionSelectNo;  // offset: 0x250
    u64 m_ullEnemyBitCtrlParts;  // offset: 0x258
    u64 m_ullEnemyBitCtrlWorkRate;  // offset: 0x260
    u64 m_ullEnemyBitCtrlScale;  // offset: 0x268
    u64 m_ullEnemyBitCtrlMontage;  // offset: 0x270
    u32 m_unEnemyBitCtrlSyncBit;  // offset: 0x278
    b8 m_bIsEnemyWaitting;  // offset: 0x27c
    b8 m_bIsEnemyStartWait;  // offset: 0x27d
    u64 m_ullAttackParamUIDForDmVec;  // offset: 0x280
    CNetPos m_WallClimbPos;  // offset: 0x288
    CVector3 m_WallClimbNormal;  // offset: 0x2a8
    CNetPos m_WallClimbLandPos;  // offset: 0x2c0
    u32 m_unStateLive;  // offset: 0x2e0
    u8 m_ucCatchType;  // offset: 0x2e4
    u8 m_ucCatchJointNo;  // offset: 0x2e5
    u32 m_unCatchTargetUID;  // offset: 0x2e8
    u32 m_unQuestID;  // offset: 0x2ec
    static MyDTI DTI;
};

class CDataContextSetInfo : public CPacketDataBase
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
    explicit CDataContextSetInfo();
    explicit CDataContextSetInfo(const CContextSetBase&, const CContextSetAdditional&);
public:
    CContextSetBase m_Base;  // offset: 0x8
    CContextSetAdditional m_Additional;  // offset: 0x28
    static MyDTI DTI;
};

inline void* CDataContextBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* CDataContextCrestData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataContextCrestData::CDataContextCrestData() {
    this->m_usItemID = 0;
}

inline void* CDataContextEquipData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* CDataContextEquipJobItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataContextEquipJobItemData::CDataContextEquipJobItemData() {
    this->m_usItemID = 0;
    this->m_ucSlotNo = 0;
}

inline void* CDataContextJobData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataContextJobData::CDataContextJobData() {
    this->m_ucJob = 0;
    this->m_usLv = 0;
    this->m_ullJobPoint = 0;
    this->m_ullExp = 0;
}

inline void* CDataContextPlayerInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* CDataContextSetAdditional::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* CDataContextSetBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataContextSetBase::CDataContextSetBase() {
    this->m_nMasterIndex = 0;
    this->m_nStageNo = 0;
    this->m_nEncountArea = 0;
    this->m_unID = 0;
    this->m_unUniqueID = 0;
}

inline void* CDataContextSetInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* CDataNetPos::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataNetPos::CDataNetPos() {
    this->m_dx = 0.0;
    this->m_fy = 0.0f;
    this->m_dz = 0.0;
}

inline void* CDataOcdActive::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataOcdActive::CDataOcdActive() {
    this->m_ucOcdUID = 0;
    this->m_ucOcdActiveLv = 0;
}

inline void* CDataOcdImmuneLv::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataOcdImmuneLv::CDataOcdImmuneLv() {
    this->m_ucIndex = 0;
    this->m_ucImmuneLv = 0;
}

inline void* CDataVector3::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataVector3::CDataVector3() {
    this->m_fx = 0.0f;
    this->m_fy = 0.0f;
    this->m_fz = 0.0f;
}
