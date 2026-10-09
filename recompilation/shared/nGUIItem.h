#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cUIObject.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "rItemList.h"
#include "sItemManager.h"

// Forward declarations
class CDataMoveItemUIDFromTo;
class CDataStorageItemUIDList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cItemParam;
class cOmControl;
namespace nGUIItem { struct cLoadCategory; }
namespace nGUIItem { struct cLoadOption; }
namespace nGUIItem { struct cSwitchStorage; }
class uGUIBase;

// Declarations
namespace nGUIItem { class cItem; }
namespace nGUIItem { class cItemList; }

namespace nGUIItem {
    enum EQUIP_INFO
    {
        EQUIP_INFO_EQUIP = 0,
        EQUIP_INFO_CANT_EQUIP = 1,
        EQUIP_INFO_UNEQUIP = 2,
        EQUIP_INFO_ERROR = 3,
    };
}  // namespace nGUIItem

namespace nGUIItem {
    enum LOAD_FROM
    {
        LOAD_FROM_NONE = 0,
        LOAD_FROM_BAG = 1,
        LOAD_FROM_OM = 2,
        LOAD_FROM_TMP = 3,
    };
}  // namespace nGUIItem

namespace nGUIItem {
    enum RET_TYPE
    {
        RET_TYPE_NONE = 0,
        RET_TYPE_ERROR = 1,
        RET_TYPE_ALL_USE = 2,
        RET_TYPE_WAIT_SERVER = 3,
    };
}  // namespace nGUIItem

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MoveItemUIDFromToVec = MtTypedArray<CDataMoveItemUIDFromTo>;
using StorageItemUIDListVec = MtTypedArray<CDataStorageItemUIDList>;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nGUIItem {
    class cItem : public ::cUIObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cItem();
        virtual ~cItem();
        void init();
        nGUIItem::cItem& copy(const nGUIItem::cItem& item);
        bool isAddCheck(nCharacterData::ITEM_BAG_TYPE type);
        nGUIItem::cItem& operator=(const nGUIItem::cItem&);
        bool isSelect();
        void setSelect(bool);
        void setReverseSelect();
        u32 getItemNo() const;
        s8 getColorNo() const;
        u32 getOmId();
        s32 getSlotNo();
        s32 getToSlotNo();
        void setToSlotNo(s32 ToSlotNo);
        void setGlobalItem(uGUIBase* pBase);
        void setItemParam(cItemParam* p);
        cItemParam* getItemParam();
        void setResourceParam(rItemList::rItemParam* p);
        rItemList::rItemParam* getResourceParam();
        nCharacterData::EQUIP_CATEGORY getEquipCategory();
        rItemList::ITEM_CATEGORY getCategory();
        rItemList::USE_CATEGORY getUseType();
        bool isThrowItem();
        MT_CTSTR getName();
        u32 getNum() const;
        void setNum(s32);
        u32 getLimitNum() const;
        void setLimitNumToStorage(u32 num);
        void setLimitNumToStorageEx(u32 num);
        void setLimitNumToBag(u32 num);
        MT_CTSTR getUID() const;
        u32 getIconImageIdx();
        bool isArms();
        nGUIItem::RET_TYPE use();
        nGUIItem::RET_TYPE discard(u32 num);
        nGUIItem::RET_TYPE equip(u32 bagType, u32 equipSlot, nCharacterData::EQUIP_TYPE type);
        nGUIItem::RET_TYPE equipOff(u32 bagType, u32 equipSlot, nCharacterData::EQUIP_TYPE type);
        nGUIItem::RET_TYPE equipPawn(u32 bagType, u32 pawnId, u32 equipSlot, nCharacterData::EQUIP_TYPE type);
        nGUIItem::RET_TYPE equipPawnOff(u32 bagType, u32 pawnId, u32 equipSlot, nCharacterData::EQUIP_TYPE type);
        u32 getEquipCharID();
        nGUIItem::RET_TYPE sendItem(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to, u32 num, s32 slotNo);
        nGUIItem::EQUIP_INFO getEquipInfo();
        u64 getPrice() const;
        rItemList::rParam* getParam(rItemList::rParam::PARAM_KIND kind);
        nItem::E_STORAGE_TYPE getBagType() const;
        void setBagType(nItem::E_STORAGE_TYPE type);
        void setToBagType(nItem::E_STORAGE_TYPE type);
        nItem::E_STORAGE_TYPE getToBagType() const;
        bool isEnableData();
        bool isSamePtr(const nGUIItem::cItem& item);
        bool isSamePtr(const cItemParam*, rItemList::rItemParam*);
        bool isSameData(const nGUIItem::cItem& item);
        bool isSameData(const cItemParam* pItemParam, rItemList::rItemParam* prItemParam);
        bool isUse();
        bool isUseEnable(u32, u32);
        bool isEquip();
        bool isPlayerEquip();
        bool isPawnEquip();
        bool isKeyItem();
        bool isBazaar();
        bool isPut();
        void setPut(bool isPut);
        bool isCheckMode();
        void setCheckMode(bool isCheckMode);
        nCharacterData::ITEM_BAG_TYPE getItemBagType() const;
    protected:
        bool setupUseEnable(u32 jobId, u32 lv);
        bool isSameDataCore(cItemParam* pBaseItemParam, cItemParam* pItemParam);
    public:
        bool mFirstSelect;  // offset: 0x8
    private:
        s32 mNum;  // offset: 0xc
        u32 mLimitNum;  // offset: 0x10
        u32 mLimitNum2;  // offset: 0x14
        u32 mLimitNum3;  // offset: 0x18
        s32 mSlotNo;  // offset: 0x1c
        s32 mToSlotNo;  // offset: 0x20
        u32 mItemNo;  // offset: 0x24
        u32 mOmId;  // offset: 0x28
        cItemParam* mpParam;  // offset: 0x30
        rItemList::rItemParam* mprItemParam;  // offset: 0x38
        nGUIItem::cItemList* mpParent;  // offset: 0x40
        bool mSelect;  // offset: 0x48
        bool mUseEnable;  // offset: 0x49
        bool mIsPut;  // offset: 0x4a
        bool mCheckMode;  // offset: 0x4b
        nGUIItem::LOAD_FROM mLoadFrom;  // offset: 0x4c
        nItem::E_STORAGE_TYPE mBagType;  // offset: 0x50
        nItem::E_STORAGE_TYPE mToBagType;  // offset: 0x54
        MtString mItemNameTmp;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
}  // namespace nGUIItem

namespace nGUIItem {
    class cItemList : public ::cUIObject
    {
    public:
        class MyDTI;
    public:
        using cItemArray = MtTypedArray<nGUIItem::cItem>;
    public:
        class MyDTI : public ::MtDTI
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
        cItemList();
        virtual ~cItemList();
        void loadList(nCharacterData::ITEM_BAG_TYPE from, const nGUIItem::cLoadCategory& category, const nGUIItem::cLoadOption& option, const nGUIItem::cSwitchStorage& switchStorage);
        void loadList(cOmControl* pOmCtrl);
        void loadListDebug();
        bool execSort(sItemManager::cItemBag::ITEM_CATEGORY cat, sItemManager::cSortParam::SORT_TYPE sortType, sItemManager::cSortParam::SORT_DIR sortDir);
        bool isAddCheckForMultiSelect(sItemManager::cItemBag::ITEM_CATEGORY cat, nCharacterData::ITEM_BAG_TYPE type);
        void initSelect();
        void deleteAll();
        cItemArray& get(sItemManager::cItemBag::ITEM_CATEGORY cat);
        u32 sizeArray();
        u32 size(sItemManager::cItemBag::ITEM_CATEGORY cat);
        u32 sizeAll();
        nGUIItem::cItem* getItem(sItemManager::cItemBag::ITEM_CATEGORY cat, u32 idx);
        nGUIItem::cItem* getItem(sItemManager::cItemBag::ITEM_CATEGORY cat, MT_CTSTR pUID);
        void setWaitFlag(u32 n);
        u32 getWaitFlag();
        void initWaitFlag();
        nGUIItem::RET_TYPE sendItems(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to);
        nGUIItem::RET_TYPE discard(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to);
        nGUIItem::RET_TYPE sell(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to);
        nGUIItem::RET_TYPE exchange(nItem::E_STORAGE_TYPE from, MoveItemUIDFromToVec& itemArray);
        MoveItemUIDFromToVec& getItemList();
        MtTypedArray<nGUIItem::cItem>& getCheckItemList();
        StorageItemUIDListVec& getDeleteItemList();
        s32 getNum(rItemList::rItemParam* pParam);
        nItem::E_STORAGE_TYPE getBagType();
        nItem::E_STORAGE_TYPE getBagType(sItemManager::cItemBag::ITEM_CATEGORY cat);
        nItem::E_STORAGE_TYPE getBagType(rItemList::ITEM_CATEGORY cat);
        void setBagType(nItem::E_STORAGE_TYPE type);
    private:
        u32 convertIdx(sItemManager::cItemBag::ITEM_CATEGORY cat);
    private:
        nDDOUtility::cArray<MtTypedArray<nGUIItem::cItem>, 7> mItemArrays;  // offset: 0x8
        nDDOUtility::cArray<MtTypedArray<nGUIItem::cItem>, 1> mExItemArrays;  // offset: 0xe8
        MoveItemUIDFromToVec mItemList;  // offset: 0x108
        StorageItemUIDListVec mDeleteItemList;  // offset: 0x128
        MtTypedArray<nGUIItem::cItem> mCheckList;  // offset: 0x148
        u32 mWaitFlag;  // offset: 0x168
        nItem::E_STORAGE_TYPE mBagType;  // offset: 0x16c
        nItem::E_STORAGE_TYPE mTargetStorage;  // offset: 0x170
        nItem::E_STORAGE_TYPE mChangeStorage;  // offset: 0x174
    public:
        static MyDTI DTI;
    };
}  // namespace nGUIItem

// Inline, no code of its own: checked where it is inlined.
inline cItemParam* nGUIItem::cItem::getItemParam() {
    return this->mpParam;
}

// Inline, no code of its own: checked where it is inlined.
inline rItemList::rItemParam* nGUIItem::cItem::getResourceParam() {
    return this->mprItemParam;
}
