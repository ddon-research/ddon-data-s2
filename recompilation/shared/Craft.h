#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataCraftColorant;
class CDataCraftElement;
class CDataCraftMaterial;
class CDataCraftPawnInfo;
class CDataCraftPawnList;
class CDataCraftProduct;
class CDataCraftProductInfo;
class CDataCraftProgress;
class CDataCraftSkillAnalyzeResult;
class CDataCraftSupportPawnID;
class CDataCraftTimeSaveCost;

namespace nCraft {
    enum E_CRAFT_RECIPE_CATEGORY_TYPE
    {
        CRAFT_RECIPE_CATEGORY_TYPE_NONE = 0,
        CRAFT_RECIPE_CATEGORY_TYPE_TOP = 1,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_SWORD = 1,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_SHIELD = 2,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_BOW = 3,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_WAND = 4,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_SHIELD_L = 5,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_MACE = 6,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_DAGGER = 7,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_WAND_DX = 8,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_BOW_MG = 9,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_GSWORD = 10,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_GUN = 11,
        CRAFT_RECIPE_CATEGORY_TYPE_WEP_LANCE = 12,
        CRAFT_RECIPE_CATEGORY_TYPE_ARMOR_HELM = 13,
        CRAFT_RECIPE_CATEGORY_TYPE_ARMOR_BODY = 14,
        CRAFT_RECIPE_CATEGORY_TYPE_ARMOR_ARM = 15,
        CRAFT_RECIPE_CATEGORY_TYPE_ARMOR_LEG = 16,
        CRAFT_RECIPE_CATEGORY_TYPE_WEAR_BODY = 17,
        CRAFT_RECIPE_CATEGORY_TYPE_WEAR_LEG = 18,
        CRAFT_RECIPE_CATEGORY_TYPE_OVER_WEAR = 19,
        CRAFT_RECIPE_CATEGORY_TYPE_JEWELRY = 20,
        CRAFT_RECIPE_CATEGORY_TYPE_LANTERN = 21,
        CRAFT_RECIPE_CATEGORY_TYPE_COSTUME = 22,
        CRAFT_RECIPE_CATEGORY_TYPE_USE = 23,
        CRAFT_RECIPE_CATEGORY_TYPE_JOB = 24,
        CRAFT_RECIPE_CATEGORY_TYPE_MATERIAL = 25,
        CRAFT_RECIPE_CATEGORY_TYPE_LIMIT_BREAK = 26,
        CRAFT_RECIPE_CATEGORY_TYPE_FURNITURE = 27,
        CRAFT_RECIPE_CATEGORY_TYPE_MAX = 28,
        CRAFT_RECIPE_CATEGORY_TYPE_NUM = 27,
    };
}  // namespace nCraft

namespace nCraft {
    enum E_CRAFT_TYPE
    {
        CRAFT_TYPE_CREATE = 1,
        CRAFT_TYPE_UPGRADE = 2,
        CRAFT_TYPE_ELEMENT = 3,
        CRAFT_TYPE_COLOR = 4,
    };
}  // namespace nCraft

// Type aliases from DWARF
using CCraftPawnInfo = CDataCraftPawnInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataCraftColorant : public CPacketDataBase
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
    explicit CDataCraftColorant();
    explicit CDataCraftColorant(const char* in_strItemUID, u8 in_ItemNum);
public:
    MtString m_wstrItemUID;  // offset: 0x8
    u8 m_ucItemNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftElement : public CPacketDataBase
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
    explicit CDataCraftElement();
    explicit CDataCraftElement(const char* in_strItemUID, u8 in_SlotNo);
public:
    MtString m_wstrItemUID;  // offset: 0x8
    u8 m_ucSlotNo;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftMaterial : public CPacketDataBase
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
    explicit CDataCraftMaterial();
    explicit CDataCraftMaterial(const char* in_strItemUID, u32 in_ItemNum);
public:
    MtString m_wstrItemUID;  // offset: 0x8
    u32 m_unItemNum;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftPawnInfo : public CPacketDataBase
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
    explicit CDataCraftPawnInfo();
    explicit CDataCraftPawnInfo(u32, const char*);
public:
    u32 m_unPawnID;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftPawnList : public CPacketDataBase
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
    explicit CDataCraftPawnList();
    explicit CDataCraftPawnList(u32, u32, u32, u32);
public:
    u32 m_unPawnID;  // offset: 0x8
    u32 m_unCraftExp;  // offset: 0xc
    u32 m_unCraftPoint;  // offset: 0x10
    u32 m_unCraftRankLimit;  // offset: 0x14
    static MyDTI DTI;
};

class CDataCraftProduct : public CPacketDataBase
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
    explicit CDataCraftProduct();
    explicit CDataCraftProduct(u32, u32, u8);
public:
    u32 m_unItemID;  // offset: 0x8
    u32 m_unItemNum;  // offset: 0xc
    u8 m_ucPlusValue;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftProductInfo : public CPacketDataBase
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
    explicit CDataCraftProductInfo();
    explicit CDataCraftProductInfo(u32, u32, u8, u32, u32, b8);
public:
    u32 m_unItemID;  // offset: 0x8
    u32 m_unItemNum;  // offset: 0xc
    u8 m_ucPlusValue;  // offset: 0x10
    u32 m_unExp;  // offset: 0x14
    u32 m_unExtraBonus;  // offset: 0x18
    b8 m_bIsGreatSuccess;  // offset: 0x1c
    static MyDTI DTI;
};

class CDataCraftProgress : public CPacketDataBase
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
    explicit CDataCraftProgress();
    explicit CDataCraftProgress(const CCraftPawnInfo&, const MtTypedArray<CDataCraftPawnInfo>&, u32, u32, s32, u32, u32, u32, b8, u32);
public:
    CCraftPawnInfo m_CraftMainPawnInfo;  // offset: 0x8
    MtTypedArray<CDataCraftPawnInfo> m_CraftSupportPawnInfoList;  // offset: 0x20
    u32 m_unRecipeID;  // offset: 0x40
    u32 m_unExp;  // offset: 0x44
    s32 m_nNpcActionID;  // offset: 0x48
    u32 m_unItemID;  // offset: 0x4c
    u32 m_unToppingID;  // offset: 0x50
    u32 m_unRemainTime;  // offset: 0x54
    b8 m_bExpBonus;  // offset: 0x58
    u32 m_unCreateCount;  // offset: 0x5c
    static MyDTI DTI;
};

class CDataCraftSkillAnalyzeResult : public CPacketDataBase
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
    explicit CDataCraftSkillAnalyzeResult();
    explicit CDataCraftSkillAnalyzeResult(u8, u8, u32, u32);
public:
    u8 m_ucSkillType;  // offset: 0x8
    u8 m_ucRate;  // offset: 0x9
    u32 m_unValue;  // offset: 0xc
    u32 m_unValue2;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCraftSupportPawnID : public CPacketDataBase
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
    explicit CDataCraftSupportPawnID();
    explicit CDataCraftSupportPawnID(u32 in_PawnID);
public:
    u32 m_unPawnID;  // offset: 0x8
    static MyDTI DTI;
};

class CDataCraftTimeSaveCost : public CPacketDataBase
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
    explicit CDataCraftTimeSaveCost();
    explicit CDataCraftTimeSaveCost(u8, u8, u32, u32);
public:
    u8 m_ucID;  // offset: 0x8
    u8 m_ucType;  // offset: 0x9
    u32 m_unPrice;  // offset: 0xc
    u32 m_unSec;  // offset: 0x10
    static MyDTI DTI;
};
