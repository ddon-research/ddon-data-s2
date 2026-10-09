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
using u32 = unsigned int;
using u8 = unsigned char;

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
