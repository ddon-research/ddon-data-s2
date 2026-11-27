// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nGUIItem.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cEquipData.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "cOmControl.h"
#include "cUIObject.h"
#include "../../XFramework/cUnit.h"
#include "cpOmGather.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "rItemList.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "sPlayerManager.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

ElementList::ElementList(const cCraftParam& craftParam) {
    DDON_STUB("ElementList::ElementList")
    /* stub */
}

const MtDTI& nGUIItem::cItem::getDTI() const {
    return nGUIItem::cItem::DTI;
}

nGUIItem::cItem::~cItem() {
}

void nGUIItem::cItem::init() {
    mSelect = false;
    mpParent = nullptr;
    mprItemParam = nullptr;
    mpParam = nullptr;
    mUseEnable = true;
    mIsPut = true;
    mCheckMode = false;
    mFirstSelect = false;
    mItemNo = 0;
    mSlotNo = 0;
    mLimitNum2 = 0;
    mLimitNum3 = 0;
    mNum = 0;
    mLimitNum = 0;
    mToSlotNo = -1;
    mOmId = 0;
    mLoadFrom = ::nGUIItem::LOAD_FROM_NONE;
    mBagType = ::nItem::STORAGE_TYPE_INVALID;
    mToBagType = ::nItem::STORAGE_TYPE_INVALID;
}

nGUIItem::cItem& nGUIItem::cItem::copy(const nGUIItem::cItem& item) {
    mNum = item.mNum;
    mLimitNum = item.mLimitNum;
    mLimitNum2 = item.mLimitNum2;
    mLimitNum3 = item.mLimitNum3;
    mSlotNo = item.mSlotNo;
    mItemNo = item.mItemNo;
    mOmId = item.mOmId;
    mpParam = item.mpParam;
    mprItemParam = item.mprItemParam;
    mpParent = item.mpParent;
    mSelect = item.mSelect;
    mUseEnable = item.mUseEnable;
    mIsPut = item.mIsPut;
    mFirstSelect = item.mFirstSelect;
    mLoadFrom = item.mLoadFrom;
    mBagType = item.mBagType;
    mToBagType = item.mToBagType;
    return *this;
}

void nGUIItem::cItem::setGlobalItem(uGUIBase* pBase) {
    static_cast<sGUIExt*>(::sGUI::getInstance())->setSendItemParameter(static_cast<cUnit*>(pBase), *this);
}

void nGUIItem::cItem::setItemParam(cItemParam* p) {
    mpParam = p;
}

void nGUIItem::cItem::setResourceParam(rItemList::rItemParam* p) {
    mprItemParam = p;
}

rItemList::ITEM_CATEGORY nGUIItem::cItem::getCategory() {
    if (mprItemParam != nullptr) {
        return static_cast<rItemList::ITEM_CATEGORY>(mprItemParam->mCategory);
    } else {
        return ::rItemList::CATEGORY_NONE;
    }
}

bool nGUIItem::cItem::isThrowItem() {
    return (mprItemParam != nullptr) && ((mprItemParam->mCategory == 1) && (mprItemParam->getUseType() == ::rItemList::USE_CATEGORY_THROW));
}

MT_CTSTR nGUIItem::cItem::getName() {
    if (mpParam != nullptr) {
        ::cGUIUtility::makeItemName(mItemNameTmp, mpParam);
        return mItemNameTmp.ptr();
    } else {
        if (mprItemParam != nullptr) {
            return mprItemParam->getItemName();
        } else {
            return nullptr;
        }
    }
}

u32 nGUIItem::cItem::getNum() const {
    if (mpParam != nullptr) {
        u16 t0 = mpParam->mItemParam.mItemNum_Guard;
        if (mprItemParam != nullptr) {
            if (static_cast<unsigned int>(mBagType) <= 31) {
                if (((0xE0038000ul >> (static_cast<unsigned long>(mBagType) & 31)) & 1ul) == 0) {
                    if (mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_PL) < t0) {
                        if ((static_cast<unsigned int>(mBagType) <= 31) && (((0xE0038000ul >> (static_cast<unsigned long>(mBagType) & 31)) & 1ul) != 0)) {
                            return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_STORAGE);
                        }
                        return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_PL);
                    }
                } else {
                    if (mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_STORAGE) < t0) {
                        if ((static_cast<unsigned int>(mBagType) <= 31) && (((0xE0038000ul >> (static_cast<unsigned long>(mBagType) & 31)) & 1ul) != 0)) {
                            return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_STORAGE);
                        }
                        return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_PL);
                    }
                }
            } else {
                if (mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_PL) < t0) {
                    if ((static_cast<unsigned int>(mBagType) <= 31) && (((0xE0038000ul >> (static_cast<unsigned long>(mBagType) & 31)) & 1ul) != 0)) {
                        return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_STORAGE);
                    }
                    return mprItemParam->getStackMax(::nCharacterData::ITEM_BAG_TYPE_PL);
                }
            }
            return mpParam->mItemParam.mItemNum_Guard;
        } else {
            return t0;
        }
    } else {
        return static_cast<u32>(mNum);
    }
}

__attribute__((weak)) u32 nGUIItem::cItem::getLimitNum() const {
    DDON_STUB("nGUIItem::cItem::getLimitNum")
    return {};
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItem::use() {
    DDON_STUB("nGUIItem::cItem::use")
    return {};
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItem::discard(u32 num) {
    DDON_STUB("nGUIItem::cItem::discard")
    return {};
}

nGUIItem::RET_TYPE nGUIItem::cItem::equip(u32 bagType, u32 equipSlot, nCharacterData::EQUIP_TYPE type) {
    if (mpParam != nullptr) {
        if (mprItemParam != nullptr) {
            if (static_cast<sGUIExt*>(::sGUI::getInstance())->mpEquipList == nullptr) {
                static_cast<sGUIExt*>(::sGUI::getInstance())->requestSE(0u, 10u);
                if (equipSlot == 0xFFFFFFFFu) {
                    nCharacterData::EQUIP_CATEGORY cate = static_cast<nCharacterData::EQUIP_CATEGORY>(mprItemParam->getEquipCategory());
                    nCharacterData::EQUIP_SLOT_TYPE t0 = ::cEquipData::convEquipCateToSlotType(cate);
                    static_cast<sGUIExt*>(::sGUI::getInstance())->setChangeEquipParam(static_cast<u32>(t0), mpParam);
                    static_cast<sGUIExt*>(::sGUI::getInstance())->requestChangeEquip(bagType, type, 0u);
                    return ::nGUIItem::RET_TYPE_NONE;
                } else {
                    static_cast<sGUIExt*>(::sGUI::getInstance())->setChangeEquipParam(equipSlot, mpParam);
                    static_cast<sGUIExt*>(::sGUI::getInstance())->requestChangeEquip(bagType, type, 0u);
                    return ::nGUIItem::RET_TYPE_NONE;
                }
            } else {
                return ::nGUIItem::RET_TYPE_ERROR;
            }
        } else {
            return ::nGUIItem::RET_TYPE_ERROR;
        }
    } else {
        return ::nGUIItem::RET_TYPE_ERROR;
    }
}

nGUIItem::RET_TYPE nGUIItem::cItem::equipOff(u32 bagType, u32 equipSlot, nCharacterData::EQUIP_TYPE type) {
    if (static_cast<sGUIExt*>(::sGUI::getInstance())->mpEquipList == nullptr) {
        static_cast<sGUIExt*>(::sGUI::getInstance())->setChangeEquipParam(equipSlot, static_cast<cItemParam*>(nullptr));
        static_cast<sGUIExt*>(::sGUI::getInstance())->requestChangeEquip(bagType, type, 0u);
        return ::nGUIItem::RET_TYPE_NONE;
    } else {
        return ::nGUIItem::RET_TYPE_ERROR;
    }
}

nGUIItem::RET_TYPE nGUIItem::cItem::equipPawn(u32 bagType, u32 pawnId, u32 equipSlot, nCharacterData::EQUIP_TYPE type) {
    if (mpParam != nullptr) {
        if (mprItemParam != nullptr) {
            if (static_cast<sGUIExt*>(::sGUI::getInstance())->mpEquipList == nullptr) {
                if (pawnId != 0) {
                    static_cast<sGUIExt*>(::sGUI::getInstance())->requestSE(0u, 10u);
                    static_cast<sGUIExt*>(::sGUI::getInstance())->setChangeEquipParam(equipSlot, mpParam);
                    static_cast<sGUIExt*>(::sGUI::getInstance())->requestChangeEquip(bagType, type, pawnId);
                    return ::nGUIItem::RET_TYPE_NONE;
                }
            }
        }
    }
    return ::nGUIItem::RET_TYPE_ERROR;
}

nGUIItem::RET_TYPE nGUIItem::cItem::equipPawnOff(u32 bagType, u32 pawnId, u32 equipSlot, nCharacterData::EQUIP_TYPE type) {
    if (static_cast<sGUIExt*>(::sGUI::getInstance())->mpEquipList == nullptr) {
        if (pawnId != 0) {
            static_cast<sGUIExt*>(::sGUI::getInstance())->setChangeEquipParam(equipSlot, static_cast<cItemParam*>(nullptr));
            static_cast<sGUIExt*>(::sGUI::getInstance())->requestChangeEquip(bagType, type, pawnId);
            return ::nGUIItem::RET_TYPE_NONE;
        }
    }
    return ::nGUIItem::RET_TYPE_ERROR;
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItem::sendItem(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to, u32 num, s32 slotNo) {
    DDON_STUB("nGUIItem::cItem::sendItem")
    return {};
}

rItemList::rParam* nGUIItem::cItem::getParam(rItemList::rParam::PARAM_KIND kind) {
    rItemList::rParam* v2_0;
    if (mprItemParam == nullptr) {
        v2_0 = nullptr;
    } else {
        if (mprItemParam->mParamNum == 0) {
            v2_0 = nullptr;
        } else {
            unsigned int i0_2 = 0;
            for (rItemList::rItemParam* v0_4 = mprItemParam;;) {
                rItemList::rParam* t0 = v0_4->getItemParam(i0_2);
                if (t0 != nullptr) {
                    if (static_cast<unsigned int>(kind) == static_cast<unsigned int>(t0->mKindType)) {
                        v2_0 = t0;
                        break;
                    }
                }
                if ((i0_2 + 1u) < mprItemParam->mParamNum) {
                    i0_2 += 1u;
                    v0_4 = mprItemParam;
                } else {
                    v2_0 = nullptr;
                    break;
                }
            }
        }
    }
    return v2_0;
}

bool nGUIItem::cItem::isEnableData() {
    if (mpParam != nullptr) {
        return mprItemParam != nullptr;
    } else {
        return false;
    }
}

__attribute__((weak)) bool nGUIItem::cItem::isSameData(const nGUIItem::cItem& item) {
    DDON_STUB("nGUIItem::cItem::isSameData")
    return {};
}

__attribute__((weak)) bool nGUIItem::cItem::isSameData(const cItemParam* pItemParam, rItemList::rItemParam* prItemParam) {
    DDON_STUB("nGUIItem::cItem::isSameData")
    return {};
}

__attribute__((weak)) bool nGUIItem::cItem::isUse() {
    DDON_STUB("nGUIItem::cItem::isUse")
    return {};
}

bool nGUIItem::cItem::isKeyItem() {
    if (mprItemParam != nullptr) {
        return mprItemParam->mCategory == 4;
    } else {
        return false;
    }
}

bool nGUIItem::cItem::isPut() {
    return mIsPut;
}

bool nGUIItem::cItem::isCheckMode() {
    return mCheckMode;
}

nCharacterData::ITEM_BAG_TYPE nGUIItem::cItem::getItemBagType() const {
    if (static_cast<unsigned int>(mBagType) <= 31) {
        if (((0xE0038000ul >> (static_cast<unsigned long>(mBagType) & 31)) & 1ul) == 0) {
            return ::nCharacterData::ITEM_BAG_TYPE_PL;
        } else {
            return ::nCharacterData::ITEM_BAG_TYPE_STORAGE;
        }
    } else {
        return ::nCharacterData::ITEM_BAG_TYPE_PL;
    }
}

inline nGUIItem::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nGUIItem::cItem::MyDTI nGUIItem::cItem::DTI("nGUIItem::cItem", &::cUIObject::DTI, 96ul, 0u, 0u);

MtObject* nGUIItem::cItem::MyDTI::newInstance() const {
    return new (16u) ::nGUIItem::cItem;
}

const MtDTI& nGUIItem::cItemList::getDTI() const {
    return nGUIItem::cItemList::DTI;
}

__attribute__((noinline)) nGUIItem::cItemList::~cItemList() {
    DDON_STUB("nGUIItem::cItemList::~cItemList")
    /* stub */
}

__attribute__((weak)) void nGUIItem::cItemList::loadList(nCharacterData::ITEM_BAG_TYPE from, const nGUIItem::cLoadCategory& category, const nGUIItem::cLoadOption& option, const nGUIItem::cSwitchStorage& switchStorage) {
    DDON_STUB("nGUIItem::cItemList::loadList")
    /* stub */
}

__attribute__((weak)) void nGUIItem::cItemList::loadList(cOmControl* pOmCtrl) {
    DDON_STUB("nGUIItem::cItemList::loadList")
    /* stub */
}

bool nGUIItem::cItemList::execSort(sItemManager::cItemBag::ITEM_CATEGORY cat, sItemManager::cSortParam::SORT_TYPE sortType, sItemManager::cSortParam::SORT_DIR sortDir) {
    sItemManager* t0 = ::sItemManager::getInstance();
    if (mTargetStorage != mChangeStorage) {
        nCharacterData::ITEM_BAG_TYPE t1 = t0->getItemBagType(mBagType);
        nItem::E_STORAGE_TYPE t2 = ::sItemManager::getInstance()->getItemNetStorageType(t1, cat);
        if (mTargetStorage == t2) {
            nCharacterData::ITEM_BAG_TYPE bagType = t0->getItemBagType(::sItemManager::getInstance()->getItemBagGroupeType(mChangeStorage));
            sItemManager::cItemBag* pItemBag = ::sItemManager::getInstance()->setLinkItem(bagType);
            if (pItemBag != nullptr) {
                pItemBag->sortStrageItem(cat, sortType, sortDir);
                return true;
            } else {
                return false;
            }
        } else {
            nCharacterData::ITEM_BAG_TYPE bagType = t0->getItemBagType(mBagType);
            sItemManager::cItemBag* pItemBag = ::sItemManager::getInstance()->setLinkItem(bagType);
            if (pItemBag != nullptr) {
                pItemBag->sortStrageItem(cat, sortType, sortDir);
                return true;
            } else {
                return false;
            }
        }
    } else {
        nCharacterData::ITEM_BAG_TYPE bagType = t0->getItemBagType(mBagType);
        sItemManager::cItemBag* pItemBag = ::sItemManager::getInstance()->setLinkItem(bagType);
        if (pItemBag != nullptr) {
            pItemBag->sortStrageItem(cat, sortType, sortDir);
            return true;
        } else {
            return false;
        }
    }
}

void nGUIItem::cItemList::deleteAll() {
    unsigned int i0_8 = 0;
    u32 v1_0;
    unsigned int i1_7;
    u32 v2_0;
    for (;;) {
        if (mItemArrays.elems[i0_8].mLength != 0) {
            v1_0 = mItemArrays.elems[i0_8].mLength;
            i1_7 = 0;
            for (;;) {
                if (mItemArrays.elems[i0_8].mpArray[i1_7] == nullptr) {
                    v2_0 = v1_0;
                } else {
                    delete mItemArrays.elems[i0_8].mpArray[i1_7];
                    v2_0 = mItemArrays.elems[i0_8].mLength;
                }
                if ((i1_7 + 1u) < v2_0) {
                    v1_0 = v2_0;
                    i1_7 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mItemArrays.elems[i0_8].mpArray != nullptr) {
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mItemArrays.elems[i0_8].mpArray));
        }
        mItemArrays.elems[i0_8].mpArray = nullptr;
        mItemArrays.elems[i0_8].mBufsiz = 0;
        mItemArrays.elems[i0_8].mLength = 0;
        if ((i0_8 + 1u) != 7) {
            i0_8 = i0_8 + 1u;
        } else {
            break;
        }
    }
    if (mExItemArrays.elems[0].mLength != 0) {
        u32 v6_0 = mExItemArrays.elems[0].mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mExItemArrays.elems[0].mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mExItemArrays.elems[0].mpArray[i6_3];
                v7_0 = mExItemArrays.elems[0].mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExItemArrays.elems[0].mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mExItemArrays.elems[0].mpArray));
    }
    mExItemArrays.elems[0].mpArray = nullptr;
    mExItemArrays.elems[0].mLength = 0;
    mExItemArrays.elems[0].mBufsiz = 0;
}

u32 nGUIItem::cItemList::sizeAll() {
    return (((((mItemArrays.elems[1].size() + mItemArrays.elems[0].mLength) + mItemArrays.elems[2].mLength) + mItemArrays.elems[3].mLength) + mItemArrays.elems[4].mLength) + mItemArrays.elems[5].mLength) + mItemArrays.elems[6].mLength;
}

__attribute__((weak)) nGUIItem::cItem* nGUIItem::cItemList::getItem(sItemManager::cItemBag::ITEM_CATEGORY cat, u32 idx) {
    DDON_STUB("nGUIItem::cItemList::getItem")
    return nullptr;
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItemList::sendItems(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to) {
    DDON_STUB("nGUIItem::cItemList::sendItems")
    return {};
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItemList::discard(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to) {
    DDON_STUB("nGUIItem::cItemList::discard")
    return {};
}

__attribute__((weak)) nGUIItem::RET_TYPE nGUIItem::cItemList::sell(nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to) {
    DDON_STUB("nGUIItem::cItemList::sell")
    return {};
}

nGUIItem::RET_TYPE nGUIItem::cItemList::exchange(nItem::E_STORAGE_TYPE from, MoveItemUIDFromToVec& itemArray) {
    if (itemArray.mLength != 0) {
        static_cast<sGUIExt*>(::sGUI::getInstance())->requestSE(0u, 10u);
        sItemManager::cItemBag* pItemBag = ::sItemManager::getInstance()->setLinkItem(from);
        if (static_cast<sGUIExt*>(::sGUI::getInstance())->reqExchangeItemFromUI(pItemBag, itemArray) != nullptr) {
            mWaitFlag = mWaitFlag | 2048u;
            return ::nGUIItem::RET_TYPE_NONE;
        } else {
            return ::nGUIItem::RET_TYPE_ERROR;
        }
    } else {
        return ::nGUIItem::RET_TYPE_ERROR;
    }
}

__attribute__((weak)) s32 nGUIItem::cItemList::getNum(rItemList::rItemParam* pParam) {
    DDON_STUB("nGUIItem::cItemList::getNum")
    return {};
}

nItem::E_STORAGE_TYPE nGUIItem::cItemList::getBagType(sItemManager::cItemBag::ITEM_CATEGORY cat) {
    if (mTargetStorage != mChangeStorage) {
        nCharacterData::ITEM_BAG_TYPE Type = ::sItemManager::getInstance()->getItemBagType(mBagType);
        nItem::E_STORAGE_TYPE eStorage = ::sItemManager::getInstance()->getItemNetStorageType(Type, cat);
        if (mTargetStorage == eStorage) {
            return ::sItemManager::getInstance()->getItemBagGroupeType(mChangeStorage);
        } else {
            return mBagType;
        }
    } else {
        return mBagType;
    }
}

nItem::E_STORAGE_TYPE nGUIItem::cItemList::getBagType(rItemList::ITEM_CATEGORY cat) {
    if (mTargetStorage == mChangeStorage) {
        return mBagType;
    } else {
        nCharacterData::ITEM_BAG_TYPE Type = ::sItemManager::getInstance()->getItemBagType(mBagType);
        sItemManager::cItemBag* pBag = ::sItemManager::getInstance()->setLinkItem(Type);
        if (pBag != nullptr) {
            sItemManager::cItemBag::ITEM_CATEGORY category = pBag->getStorageCategotyToItemCategory(cat);
            if (mTargetStorage != mChangeStorage) {
                nCharacterData::ITEM_BAG_TYPE t0 = ::sItemManager::getInstance()->getItemBagType(mBagType);
                nItem::E_STORAGE_TYPE t1 = ::sItemManager::getInstance()->getItemNetStorageType(t0, category);
                if (mTargetStorage == t1) {
                    return ::sItemManager::getInstance()->getItemBagGroupeType(mChangeStorage);
                } else {
                    return mBagType;
                }
            } else {
                return mBagType;
            }
        } else {
            return mBagType;
        }
    }
}

u32 nGUIItem::cItemList::convertIdx(sItemManager::cItemBag::ITEM_CATEGORY cat) {
    return ::sItemManager::cItemBag::getStorageCategoryIndex(cat);
}

inline nGUIItem::cItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nGUIItem::cItemList::MyDTI nGUIItem::cItemList::DTI("nGUIItem::cItemList", &::cUIObject::DTI, 376ul, 0u, 0u);

__attribute__((weak)) MtObject* nGUIItem::cItemList::MyDTI::newInstance() const {
    DDON_STUB("nGUIItem::cItemList::MyDTI::newInstance")
    return nullptr;
}

void nGUIItem::cLoadCategory::setEnableCategory(sItemManager::cItemBag::ITEM_CATEGORY cat, bool b) {
    s32 idx = ::sItemManager::cItemBag::getStorageCategoryIndex(cat);
    mEnableCategory.elems[(static_cast<unsigned int>(idx) <= 6) ? static_cast<unsigned int>(idx) : 0u] = b;
}

template MtTypedArray<nGUIItem::cItem>::~MtTypedArray();

