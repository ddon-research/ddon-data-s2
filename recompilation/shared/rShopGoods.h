#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTable.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class cShopGoods;
class rShopGoods;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cShopGoods : public MtObject
{
public:
    enum CATEGORY_TYPE
    {
        CATEGORY_ITEM = 0,
        CATEGORY_WEAPON = 1,
        CATEGORY_ARMOR = 2,
        CATEGORY_ELEMENT = 3,
        CATEGORY_JOB = 4,
        CATEGORY_NUM = 5,
    };
    enum SALE_TYPE
    {
        SALE_NORMAL = 0,
        SALE_LIMITED = 1,
        SALE_FAVORITE = 2,
        SALE_NUM = 3,
    };
    enum REPLENISH_TYPE
    {
        REPLENISH_GAME_DAYS = 0,
        REPLENISH_REAL_DATE = 1,
        REPLENISH_NUM = 2,
    };
public:
    class MyDTI;
    class rDate;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class rDate : public MtObject
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
        rDate();
        rDate(u16 year, u8 month, u8 day);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& in);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        u16 getYear();
        u8 getMonth();
        u8 getDay();
    private:
        u16 mYear;  // offset: 0x8
        u8 mMonth;  // offset: 0xa
        u8 mDay;  // offset: 0xb
    public:
        static MyDTI DTI;
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
    cShopGoods();
    // Address: 0x01ab0e60 - 0x01ab0e61 (1 bytes)
    virtual ~cShopGoods() {}
    u8 getStockNum();
    void setStockNum(u8);
    bool isInfiniteStock();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u8 mCategory;  // offset: 0x8
    u32 mID;  // offset: 0xc
    u64 mPrice;  // offset: 0x10
    u8 mGoldType;  // offset: 0x18
    u32 mGoodsIndex;  // offset: 0x1c
    u8 mSaleType;  // offset: 0x20
    u16 mRequiedFavorite;  // offset: 0x22
    rDate mStartDate;  // offset: 0x28
    rDate mEndDate;  // offset: 0x38
    u8 mStockNum;  // offset: 0x48
    u8 mMaxStockNum;  // offset: 0x49
    u8 mReplenishRate;  // offset: 0x4a
    u8 mReplenishType;  // offset: 0x4b
    u16 mInGameDays;  // offset: 0x4c
    rDate mRealDate;  // offset: 0x50
    static MyDTI DTI;
    static const u16 DATA_VERSION = 259;
};

class rShopGoods : public rTable
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
    rShopGoods();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u16 getDataVersion();  // vtable slot 18
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadData(MtDataReader& in);
    virtual bool save(MtStream& out);  // vtable slot 12
    bool saveData(MtDataWriter& out);
    bool loadData(MtDataReader& in, cShopGoods* pData);
    bool saveData(MtDataWriter& out, cShopGoods* pData);
    cShopGoods* getData(u32);
    void setData(MtObject*, u32);
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cShopGoods::rDate::rDate() {
    this->mYear = static_cast<u16>(2000);
    this->mMonth = static_cast<u8>(1);
    this->mDay = static_cast<u8>(1);
}
