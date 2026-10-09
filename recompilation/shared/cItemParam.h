#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "nCharacterData.h"
#include "rItemList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtString;
namespace nCharacterData { struct stItemParam; }
class uUIMockUp;

// Declarations
class cCraftParam;
class cItemParam;

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

class cCraftParam : public MtObject
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
    cCraftParam();
    virtual ~cCraftParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void init();
    void copyParam(const cCraftParam* pSrc, rItemList::rItemParam* pItemParam);
    void setElementItemNo(u32 no, u32 itemNo);
    u32 getElementItemNo(u32 no) const;
    void setElementItemParam(u32 no, u32 itemNo);
    rItemList::rItemParam* getElementParam(u32 no);
    void setPlusParam(u8 plus, rItemList::rItemParam* pItemParam);
    u8 getPlusParam() const;
    u32 getElementEquipNum() const;
private:
    u32 mCraftElementItemNo[4];  // offset: 0x8
    u8 mCraftPlusParam;  // offset: 0x18
    rItemList::rItemParam* mpElementParam[4];  // offset: 0x20
public:
    static MyDTI DTI;
};

class cItemParam : public MtObject
{
    // inferred: uUIMockUp::changeEquip names cItemParam::mColorNo
    friend class uUIMockUp;
public:
    enum
    {
        CHAR_TYPE_NONE = 0,
        CHAR_TYPE_PL = 1,
        CHAR_TYPE_PAWN = 2,
        CHAR_TYPE_MAX = 3,
    };
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
    cItemParam();
    void init(u32 key);
    void copyParam(const cItemParam* pSrc);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getItemNo() const;
    void setItemNo(u32 ItemNo);
    u32 getItemNum() const;
    void setItemNum(u32 ItemNum);
    u32 getItemLocalNum() const;
    void setItemLocalNum(u32 ItemNum);
    MT_CTSTR getUID() const;
    void setUID(MT_CTSTR UID);
    bool isInvalidUID() const;
    cCraftParam* getCraftParam();
    const cCraftParam* getCraftParam() const;
    u32 getCraftPlusParam() const;
    u8 getColorNo() const;
    void setColorNo(u8 no);
    u8 getColorSortNo() const;
    u16 getEquipPoint() const;
    void setEquipPoint(u16 point);
    u32 getElementEquipNum() const;
    bool isEquip() const;
    bool isPlayerEquip() const;
    bool isPawnEquip() const;
    u32 getEquipCharID();
    void setEquipCharID(u32 id);
    u8 getEquipCharType() const;
    void setEquipCharType(u8 type);
    u32 getSlotNo() const;
    void setSlotNo(u32 SlotNo);
    u8 getEquipSlotType() const;
    void setEquipSlotType(u8 slotType);
    rItemList::rItemParam* getItemParam();
    const rItemList::rItemParam* getItemParamConst() const;
    void setItemParam(rItemList::rItemParam* pParam);
    rItemList::ITEM_CATEGORY getItemCategory();
    u64 getItemPrice();
    MT_CTSTR getItemName();
    u8 getCustomSort() const;
    void setCustomSort(u8 sortParam);
    u8 getElementSlot();
    void setFlag(nCharacterData::FLAG_BIT flag);
    bool isFlag(nCharacterData::FLAG_BIT flag) const;
private:
    nCharacterData::stItemParam mItemParam;  // offset: 0x8
    MtString mWstrUID;  // offset: 0x18
    cCraftParam mCraftParam;  // offset: 0x20
    u32 mEquipCharID;  // offset: 0x60
    u16 mEquipPoint;  // offset: 0x64
    u8 mEquipCharType;  // offset: 0x66
    u8 mColorNo;  // offset: 0x67
    u8 mSlotType;  // offset: 0x68
    u8 mCustomSort;  // offset: 0x69
    rItemList::rItemParam* mpItemResParam;  // offset: 0x70
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cItemParam::getItemNo() const {
    return this->mItemParam.mItemNo;
}
