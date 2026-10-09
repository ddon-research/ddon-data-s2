#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataEncounterPawnInfo;
class CDataGatheringItemElement;
class CDataGatheringItemGetRequest;
class CDataLayoutEnemyData;
class CDataOmData;
class CDataStageAttribute;
class CDataStageInfo;
class CDataStageLayoutEnemyPresetEnemyInfoClient;
class CDataStageLayoutID;

// Type aliases from DWARF
using CStageAttribute = CDataStageAttribute;
using CStageLayoutEnemyPresetEnemyInfoClient = CDataStageLayoutEnemyPresetEnemyInfoClient;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataEncounterPawnInfo : public CPacketDataBase
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
    explicit CDataEncounterPawnInfo();
    explicit CDataEncounterPawnInfo(u32, u32, u32);
public:
    u32 m_ulLv;  // offset: 0x8
    u32 m_ulLvBand;  // offset: 0xc
    u32 m_ulThinkID;  // offset: 0x10
    static MyDTI DTI;
};

class CDataGatheringItemElement : public CPacketDataBase
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
    explicit CDataGatheringItemElement();
    explicit CDataGatheringItemElement(u32, u32, u32);
public:
    u32 m_ulID;  // offset: 0x8
    u32 m_ulItemId;  // offset: 0xc
    u32 m_ulNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataGatheringItemGetRequest : public CPacketDataBase
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
    explicit CDataGatheringItemGetRequest();
    explicit CDataGatheringItemGetRequest(u32, u32);
public:
    u32 m_ulID;  // offset: 0x8
    u32 m_ulNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataOmData : public CPacketDataBase
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
    explicit CDataOmData();
    explicit CDataOmData(u32, u32);
public:
    u32 m_ulKey;  // offset: 0x8
    u32 m_ulValue;  // offset: 0xc
    static MyDTI DTI;
};

class CDataStageAttribute : public CPacketDataBase
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
    explicit CDataStageAttribute();
    explicit CDataStageAttribute(b8, b8, b8, b8, b8, b8, b8, b8, b8);
public:
    b8 m_bIsSolo;  // offset: 0x8
    b8 m_bIsEnablePartyFunc;  // offset: 0x9
    b8 m_bIsAdventureCountKeep;  // offset: 0xa
    b8 m_bIsEnableCraft;  // offset: 0xb
    b8 m_bIsEnableStorage;  // offset: 0xc
    b8 m_bIsEnableStorageInCharge;  // offset: 0xd
    b8 m_bIsNotSessionReturn;  // offset: 0xe
    b8 m_bIsEnableBaggage;  // offset: 0xf
    b8 m_bIsClanBase;  // offset: 0x10
    static MyDTI DTI;
};

class CDataStageInfo : public CPacketDataBase
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
    explicit CDataStageInfo();
    explicit CDataStageInfo(u32, u32, u32, u32, const CStageAttribute&, b8);
public:
    u32 m_ulID;  // offset: 0x8
    u32 m_ulStageNo;  // offset: 0xc
    u32 m_ulRandomStageGroupID;  // offset: 0x10
    u32 m_unType;  // offset: 0x14
    CStageAttribute m_StageAttribute;  // offset: 0x18
    b8 m_bIsAutoSetBloodEnemy;  // offset: 0x30
    static MyDTI DTI;
};

class CDataStageLayoutEnemyPresetEnemyInfoClient : public CPacketDataBase
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
    explicit CDataStageLayoutEnemyPresetEnemyInfoClient();
    explicit CDataStageLayoutEnemyPresetEnemyInfoClient(u32, u32, u32, u16, u16, u16, u8, u8, u8, u8, u8, u8, u8, b8, b8, b8, b8, b8);
public:
    u32 m_unEnemyID;  // offset: 0x8
    u32 m_unNamedEnemyParamsId;  // offset: 0xc
    u32 m_unRaidBossID;  // offset: 0x10
    u16 m_usScale;  // offset: 0x14
    u16 m_usLv;  // offset: 0x16
    u16 m_usHmPresetNo;  // offset: 0x18
    u8 m_ucStartThinkTblNo;  // offset: 0x1a
    u8 m_ucRepopNum;  // offset: 0x1b
    u8 m_ucRepopCount;  // offset: 0x1c
    u8 m_ucEnemyTargetTypesId;  // offset: 0x1d
    u8 m_ucMontageFixNo;  // offset: 0x1e
    u8 m_ucSetType;  // offset: 0x1f
    u8 m_ucInfectionType;  // offset: 0x20
    b8 m_bIsBossGauge;  // offset: 0x21
    b8 m_bIsBossBGM;  // offset: 0x22
    b8 m_bIsManualSet;  // offset: 0x23
    b8 m_bIsAreaBoss;  // offset: 0x24
    b8 m_bIsBloodEnemy;  // offset: 0x25
    static MyDTI DTI;
};

class CDataStageLayoutID : public CPacketDataBase
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
    explicit CDataStageLayoutID();
    explicit CDataStageLayoutID(u32 in_StageID, u8 in_LayerNo, u32 in_GroupID);
public:
    u32 m_unStageID;  // offset: 0x8
    u8 m_ucLayerNo;  // offset: 0xc
    u32 m_unGroupID;  // offset: 0x10
    static MyDTI DTI;
};

class CDataLayoutEnemyData : public CPacketDataBase
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
    explicit CDataLayoutEnemyData();
    explicit CDataLayoutEnemyData(u8, const CStageLayoutEnemyPresetEnemyInfoClient&);
public:
    u8 m_ucPositionIndex;  // offset: 0x8
    CStageLayoutEnemyPresetEnemyInfoClient m_EnemyInfo;  // offset: 0x10
    static MyDTI DTI;
};
