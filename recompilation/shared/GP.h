#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCommonU32;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataCAPtoGPChangeElement;
class CDataGPCourseAvailable;
class CDataGPCourseEffectParam;
class CDataGPCourseInfo;
class CDataGPCourseValid;
class CDataGPDetail;
class CDataGPPeriod;
class CDataGPShopBuyHistoryElement;
class CDataGPShopDisplayLineup;
class CDataGPShopDisplayType;
class CDataGPShopLineupElementBase;
class CDataGPShopLineupElementCourse;

// Type aliases from DWARF
using CGPShopLineupElementBase = CDataGPShopLineupElementBase;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataCAPtoGPChangeElement : public CPacketDataBase
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
    explicit CDataCAPtoGPChangeElement();
    explicit CDataCAPtoGPChangeElement(u32, u32, u32, const char*, u32, u32);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unCAP;  // offset: 0xc
    u32 m_unGP;  // offset: 0x10
    MtString m_wstrComment;  // offset: 0x18
    u32 m_unBackIconID;  // offset: 0x20
    u32 m_unFrameIconID;  // offset: 0x24
    static MyDTI DTI;
};

class CDataGPCourseAvailable : public CPacketDataBase
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
    explicit CDataGPCourseAvailable();
    explicit CDataGPCourseAvailable(u32, const char*, u64, u32, u32, u32, u32);
public:
    u32 m_unID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u64 m_ullUseLimitTime;  // offset: 0x18
    u32 m_unCourseID;  // offset: 0x20
    u32 m_unLineupID;  // offset: 0x24
    u32 m_unBackIconID;  // offset: 0x28
    u32 m_unFrameIconID;  // offset: 0x2c
    static MyDTI DTI;
};

class CDataGPCourseEffectParam : public CPacketDataBase
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
    explicit CDataGPCourseEffectParam();
    explicit CDataGPCourseEffectParam(u32, u32, u32, u32);
public:
    u32 m_unEffectUID;  // offset: 0x8
    u32 m_unEffectID;  // offset: 0xc
    u32 m_unParam0;  // offset: 0x10
    u32 m_unParam1;  // offset: 0x14
    static MyDTI DTI;
};

class CDataGPCourseInfo : public CPacketDataBase
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
    explicit CDataGPCourseInfo();
    explicit CDataGPCourseInfo(u32, const char*, b8, u8, u8, u8, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unCourseID;  // offset: 0x8
    MtString m_wstrCourseName;  // offset: 0x10
    b8 m_bDoubleCourseTarget;  // offset: 0x18
    u8 m_ucPrioGroup;  // offset: 0x19
    u8 m_ucPrioSameTime;  // offset: 0x1a
    u8 m_ucAnnounceType;  // offset: 0x1b
    MtTypedArray<CDataCommonU32> m_EffectUIDList;  // offset: 0x20
    static MyDTI DTI;
};

class CDataGPCourseValid : public CPacketDataBase
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
    explicit CDataGPCourseValid();
    explicit CDataGPCourseValid(u32, u32, const char*, u32, u64, u64);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unCourseID;  // offset: 0xc
    MtString m_wstrName;  // offset: 0x10
    u32 m_unIconID;  // offset: 0x18
    u64 m_ullStartTime;  // offset: 0x20
    u64 m_ullEndTime;  // offset: 0x28
    static MyDTI DTI;
};

class CDataGPDetail : public CPacketDataBase
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
    explicit CDataGPDetail();
    explicit CDataGPDetail(u32, u32, b8, u32, u64, u64);
public:
    u32 m_unGP;  // offset: 0x8
    u32 m_unMax;  // offset: 0xc
    b8 m_bIsFree;  // offset: 0x10
    u32 m_unGetType;  // offset: 0x14
    u64 m_ullExpire;  // offset: 0x18
    u64 m_ullCreated;  // offset: 0x20
    static MyDTI DTI;
};

class CDataGPPeriod : public CPacketDataBase
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
    explicit CDataGPPeriod();
    explicit CDataGPPeriod(u32, b8, u64);
public:
    u32 m_unGP;  // offset: 0x8
    b8 m_bIsFreeGP;  // offset: 0xc
    u64 m_ullPeriod;  // offset: 0x10
    static MyDTI DTI;
};

class CDataGPShopBuyHistoryElement : public CPacketDataBase
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
    explicit CDataGPShopBuyHistoryElement();
    explicit CDataGPShopBuyHistoryElement(u32, const char*, u32, u64);
public:
    u32 m_unID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u32 m_unPrice;  // offset: 0x18
    u64 m_ullAcquisitionTime;  // offset: 0x20
    static MyDTI DTI;
};

class CDataGPShopDisplayLineup : public CPacketDataBase
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
    explicit CDataGPShopDisplayLineup();
    explicit CDataGPShopDisplayLineup(u32 in_ID, u32 in_Category, u8 in_IconId, u32 in_GP, u32 in_DiscountType, u32 in_DiscountGP, const char* in_strName, const char* in_strComment, u32 in_LineupID, u32 in_BackIconID, u32 in_FrameIconID, u32 in_BehaviorAfterBuyingType);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unCategory;  // offset: 0xc
    u8 m_ucIconId;  // offset: 0x10
    u32 m_unGP;  // offset: 0x14
    u32 m_unDiscountType;  // offset: 0x18
    u32 m_unDiscountGP;  // offset: 0x1c
    MtString m_wstrName;  // offset: 0x20
    MtString m_wstrComment;  // offset: 0x28
    u32 m_unLineupID;  // offset: 0x30
    u32 m_unBackIconID;  // offset: 0x34
    u32 m_unFrameIconID;  // offset: 0x38
    u32 m_unBehaviorAfterBuyingType;  // offset: 0x3c
    static MyDTI DTI;
};

class CDataGPShopDisplayType : public CPacketDataBase
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
    explicit CDataGPShopDisplayType();
    explicit CDataGPShopDisplayType(u32, const char*, u32);
public:
    u32 m_unID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u32 m_unInGameUrlID;  // offset: 0x18
    static MyDTI DTI;
};

class CDataGPShopLineupElementBase : public CPacketDataBase
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
    explicit CDataGPShopLineupElementBase();
    explicit CDataGPShopLineupElementBase(u32, u32, u32, u32, u8, const char*, const char*, b8);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unGP;  // offset: 0xc
    u32 m_unInitialGP;  // offset: 0x10
    u32 m_unDiscountGP;  // offset: 0x14
    u8 m_ucIconId;  // offset: 0x18
    MtString m_wstrName;  // offset: 0x20
    MtString m_wstrComment;  // offset: 0x28
    b8 m_bIsInitialPrice;  // offset: 0x30
    static MyDTI DTI;
};

class CDataGPShopLineupElementCourse : public CPacketDataBase
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
    explicit CDataGPShopLineupElementCourse();
    explicit CDataGPShopLineupElementCourse(const CGPShopLineupElementBase&);
public:
    CGPShopLineupElementBase m_Base;  // offset: 0x8
    static MyDTI DTI;
};
