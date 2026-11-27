#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtDTI.h"
#include "../../cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataDropItemSetInfo;
class CDataEncounterPawnInfo;
class CDataGatheringItemElement;
class CDataGatheringItemGetRequest;
class CDataLayoutEnemyData;
class CDataLayoutItemData;
class CDataOmData;
class CDataRandomStageInfo;
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
using f32 = float;
using f64 = double;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataDropItemSetInfo : public CPacketDataBase
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
    explicit CDataDropItemSetInfo();
    explicit CDataDropItemSetInfo(u8, u8, f64, f32, f64);
public:
    u8 m_ucID;  // offset: 0x8
    u8 m_ucMdlType;  // offset: 0x9
    f64 m_dX;  // offset: 0x10
    f32 m_fY;  // offset: 0x18
    f64 m_dZ;  // offset: 0x20
    static MyDTI DTI;
};

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

class CDataLayoutItemData : public CPacketDataBase
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
    explicit CDataLayoutItemData();
    explicit CDataLayoutItemData(u8, b8, b8, b8, b8);
public:
    u8 m_ucPosID;  // offset: 0x8
    b8 m_bIsEmpty;  // offset: 0x9
    b8 m_bIsGathered;  // offset: 0xa
    b8 m_bIsAppearEnemy;  // offset: 0xb
    b8 m_bIsTreasurePoint;  // offset: 0xc
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

class CDataRandomStageInfo : public CPacketDataBase
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
    explicit CDataRandomStageInfo();
    explicit CDataRandomStageInfo(u32, u32);
public:
    u32 m_unLayerNo;  // offset: 0x8
    u32 m_unPartNo;  // offset: 0xc
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

inline void* CDataDropItemSetInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataDropItemSetInfo::CDataDropItemSetInfo() {
    this->m_ucID = 0;
    this->m_ucMdlType = 0;
    this->m_dX = 0.0;
    this->m_fY = 0.0f;
    this->m_dZ = 0.0;
}

inline void* CDataEncounterPawnInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataEncounterPawnInfo::CDataEncounterPawnInfo() {
    this->m_ulLv = 0;
    this->m_ulLvBand = 0;
    this->m_ulThinkID = 0;
}

inline void* CDataGatheringItemElement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataGatheringItemElement::CDataGatheringItemElement() {
    this->m_ulID = 0;
    this->m_ulItemId = 0;
    this->m_ulNum = 0;
}

inline void* CDataGatheringItemGetRequest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataGatheringItemGetRequest::CDataGatheringItemGetRequest() {
    this->m_ulID = 0;
    this->m_ulNum = 0;
}

inline void* CDataLayoutEnemyData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataLayoutEnemyData::CDataLayoutEnemyData() {
    this->m_ucPositionIndex = 0;
}

inline void* CDataLayoutItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataLayoutItemData::CDataLayoutItemData() {
    this->m_bIsTreasurePoint = false;
    this->m_ucPosID = 0;
    this->m_bIsEmpty = false;
    this->m_bIsGathered = false;
    this->m_bIsAppearEnemy = false;
}

inline void* CDataOmData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataOmData::CDataOmData() {
    this->m_ulKey = 0;
    this->m_ulValue = 0;
}

inline void* CDataRandomStageInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataRandomStageInfo::CDataRandomStageInfo() {
    this->m_unLayerNo = 0;
    this->m_unPartNo = 0;
}

inline void* CDataStageAttribute::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataStageAttribute::CDataStageAttribute() {
    this->m_bIsClanBase = false;
    this->m_bIsSolo = false;
    this->m_bIsEnablePartyFunc = false;
    this->m_bIsAdventureCountKeep = false;
    this->m_bIsEnableCraft = false;
    this->m_bIsEnableStorage = false;
    this->m_bIsEnableStorageInCharge = false;
    this->m_bIsNotSessionReturn = false;
    this->m_bIsEnableBaggage = false;
}

inline void* CDataStageInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataStageInfo::CDataStageInfo() {
    this->m_ulRandomStageGroupID = 0;
    this->m_unType = 0;
    this->m_ulID = 0;
    this->m_ulStageNo = 0;
    this->m_bIsAutoSetBloodEnemy = false;
}

inline void* CDataStageLayoutEnemyPresetEnemyInfoClient::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataStageLayoutEnemyPresetEnemyInfoClient::CDataStageLayoutEnemyPresetEnemyInfoClient() {
    this->m_bIsAreaBoss = false;
    this->m_bIsBloodEnemy = false;
    this->m_ucInfectionType = 0;
    this->m_bIsBossGauge = false;
    this->m_bIsBossBGM = false;
    this->m_bIsManualSet = false;
    this->m_usHmPresetNo = 0;
    this->m_ucStartThinkTblNo = 0;
    this->m_ucRepopNum = 0;
    this->m_ucRepopCount = 0;
    this->m_ucEnemyTargetTypesId = 0;
    this->m_ucMontageFixNo = 0;
    this->m_ucSetType = 0;
    this->m_unRaidBossID = 0;
    this->m_usScale = 0;
    this->m_usLv = 0;
    this->m_unEnemyID = 0;
    this->m_unNamedEnemyParamsId = 0;
}

inline void* CDataStageLayoutID::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataStageLayoutID::CDataStageLayoutID() {
    this->m_unStageID = 0;
    this->m_ucLayerNo = 0;
    this->m_unGroupID = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataDropItemSetInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataDropItemSetInfo::DTI);
}

inline MtAllocator* CDataEncounterPawnInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataEncounterPawnInfo::DTI);
}

inline void* CDataEncounterPawnInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataEncounterPawnInfo::DTI)->memAlloc(sz, align, ::CDataEncounterPawnInfo::DTI.::MtDTI::getID());
}

inline MtAllocator* CDataGatheringItemElement::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataGatheringItemElement::DTI);
}

inline MtAllocator* CDataGatheringItemGetRequest::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataGatheringItemGetRequest::DTI);
}

inline MtAllocator* CDataLayoutEnemyData::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataLayoutEnemyData::DTI);
}

inline MtAllocator* CDataLayoutItemData::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataLayoutItemData::DTI);
}

inline MtAllocator* CDataOmData::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataOmData::DTI);
}

inline MtAllocator* CDataRandomStageInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataRandomStageInfo::DTI);
}

inline MtAllocator* CDataStageAttribute::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataStageAttribute::DTI);
}

inline void* CDataStageAttribute::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataStageAttribute::DTI)->memAlloc(sz, align, ::CDataStageAttribute::DTI.::MtDTI::getID());
}

inline MtAllocator* CDataStageInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataStageInfo::DTI);
}

inline MtAllocator* CDataStageLayoutEnemyPresetEnemyInfoClient::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataStageLayoutEnemyPresetEnemyInfoClient::DTI);
}

inline void* CDataStageLayoutEnemyPresetEnemyInfoClient::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataStageLayoutEnemyPresetEnemyInfoClient::DTI)->memAlloc(sz, align, ::CDataStageLayoutEnemyPresetEnemyInfoClient::DTI.::MtDTI::getID());
}

inline MtAllocator* CDataStageLayoutID::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataStageLayoutID::DTI);
}

inline void* CDataStageLayoutID::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataStageLayoutID::DTI)->memAlloc(sz, align, ::CDataStageLayoutID::DTI.::MtDTI::getID());
}
