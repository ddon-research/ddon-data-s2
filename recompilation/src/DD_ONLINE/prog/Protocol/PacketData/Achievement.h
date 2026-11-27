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
class CDataAchieveCategoryStatus;
class CDataAchieveRewardCommon;
class CDataAchievementFurnitureReward;
class CDataAchievementIdentifier;
class CDataAchievementProgress;
class CDataAchievementRewardProgress;

// Type aliases from DWARF
using CAchievementIdentifier = CDataAchievementIdentifier;
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

class CDataAchieveCategoryStatus : public CPacketDataBase
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
    explicit CDataAchieveCategoryStatus();
    explicit CDataAchieveCategoryStatus(u8, u16, u16);
public:
    u8 m_ucCategoryID;  // offset: 0x8
    u16 m_usAchieveNum;  // offset: 0xa
    u16 m_usTargetNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataAchieveRewardCommon : public CPacketDataBase
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
    explicit CDataAchieveRewardCommon();
    explicit CDataAchieveRewardCommon(u8 in_Type, u32 in_RewardId);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unRewardId;  // offset: 0xc
    static MyDTI DTI;
};

class CDataAchievementIdentifier : public CPacketDataBase
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
    explicit CDataAchievementIdentifier();
    explicit CDataAchievementIdentifier(u32, u32);
public:
    u32 m_unUid;  // offset: 0x8
    u32 m_unIndex;  // offset: 0xc
    static MyDTI DTI;
};

class CDataAchievementProgress : public CPacketDataBase
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
    explicit CDataAchievementProgress();
    explicit CDataAchievementProgress(const CAchievementIdentifier&, u32, u32, s64);
public:
    CAchievementIdentifier m_AchieveIdenfier;  // offset: 0x8
    u32 m_unCurrentNum;  // offset: 0x18
    u32 m_unSeqence;  // offset: 0x1c
    s64 m_llCompleteDate;  // offset: 0x20
    static MyDTI DTI;
};

class CDataAchievementRewardProgress : public CPacketDataBase
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
    explicit CDataAchievementRewardProgress();
    explicit CDataAchievementRewardProgress(u32, u32, u32, b8);
public:
    u32 m_unRewardId;  // offset: 0x8
    u32 m_unCurrentNum;  // offset: 0xc
    u32 m_unTargetNum;  // offset: 0x10
    b8 m_bIsRecieved;  // offset: 0x14
    static MyDTI DTI;
};

class CDataAchievementFurnitureReward : public CPacketDataBase
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
    explicit CDataAchievementFurnitureReward();
    explicit CDataAchievementFurnitureReward(u32, u32, const CAchievementIdentifier&, u32, b8);
public:
    u32 m_unRewardId;  // offset: 0x8
    u32 m_unSortId;  // offset: 0xc
    CAchievementIdentifier m_AchieveIdenfier;  // offset: 0x10
    u32 m_unFurnitureItemId;  // offset: 0x20
    b8 m_bIsRecieved;  // offset: 0x24
    static MyDTI DTI;
};

inline void* CDataAchieveCategoryStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchieveCategoryStatus::CDataAchieveCategoryStatus() {
    this->m_ucCategoryID = 0;
    this->m_usAchieveNum = 0;
    this->m_usTargetNum = 0;
}

inline void* CDataAchieveRewardCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchieveRewardCommon::CDataAchieveRewardCommon() {
    this->m_ucType = 0;
    this->m_unRewardId = 0;
}

inline void* CDataAchievementFurnitureReward::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchievementFurnitureReward::CDataAchievementFurnitureReward() {
    this->m_unRewardId = 0;
    this->m_unSortId = 0;
    this->m_bIsRecieved = false;
    this->m_unFurnitureItemId = 0;
}

inline void* CDataAchievementIdentifier::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchievementIdentifier::CDataAchievementIdentifier() {
    this->m_unUid = 0;
    this->m_unIndex = 0;
}

inline void* CDataAchievementProgress::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchievementProgress::CDataAchievementProgress() {
    this->m_llCompleteDate = 0;
    this->m_unCurrentNum = 0;
    this->m_unSeqence = 0;
}

inline void* CDataAchievementRewardProgress::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataAchievementRewardProgress::CDataAchievementRewardProgress() {
    this->m_bIsRecieved = false;
    this->m_unTargetNum = 0;
    this->m_unRewardId = 0;
    this->m_unCurrentNum = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataAchieveCategoryStatus::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchieveCategoryStatus::DTI);
}

inline MtAllocator* CDataAchieveRewardCommon::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchieveRewardCommon::DTI);
}

inline MtAllocator* CDataAchievementFurnitureReward::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchievementFurnitureReward::DTI);
}

inline MtAllocator* CDataAchievementIdentifier::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchievementIdentifier::DTI);
}

inline void* CDataAchievementIdentifier::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataAchievementIdentifier::DTI)->memAlloc(sz, align, ::CDataAchievementIdentifier::DTI.::MtDTI::getID());
}

inline MtAllocator* CDataAchievementProgress::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchievementProgress::DTI);
}

inline MtAllocator* CDataAchievementRewardProgress::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataAchievementRewardProgress::DTI);
}
