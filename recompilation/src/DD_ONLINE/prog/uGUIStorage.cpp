// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIStorage.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "cControl.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nGUIItem.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIItem01.h"
#include "uGUIPopDetail01.h"
#include "uGUIUseItemBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIStorage::getDTI() const {
    return uGUIStorage::DTI;
}

inline void uGUIStorage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIStorage::DTI)->memFree(p_addr);
}

uGUIStorage::~uGUIStorage() {
    if (mpShareUnit == nullptr) {
        return;
    }
    if (mIsShareSameUnit) {
        return;
    }
    mpShareUnit->kill();
    mpShareUnit = nullptr;
}

__attribute__((weak)) void uGUIStorage::setup() {
    DDON_STUB("uGUIStorage::setup")
    /* stub */
}

void uGUIStorage::kill() {
    this->uGUIItemBase01::kill();
    if (mpShareUnit == nullptr) {
        return;
    }
    if (mIsShareSameUnit) {
        return;
    }
    mpShareUnit->kill();
    mpShareUnit = nullptr;
}

void uGUIStorage::moveInput() {
    if (mIsExeCtrl) {
        mRefToggle.uGUIBase::cReferenceUIToggleBtn::setFocus(mCtrlFocus == 1);
        mRefToggle.uGUIBase::cReferenceUIToggleBtn::update();
        mRefToggle.execute();
    }
    this->uGUIItemBase01::moveInput();
}

void uGUIStorage::moveEvent() {
    this->uGUIItemBase01::moveEvent();
    if (!mRefToggle.isSwitch()) {
        return;
    }
    if (mStorageType == nCharacterData::ITEM_BAG_TYPE_EX_STORAGE) {
        mStorageType = nCharacterData::ITEM_BAG_TYPE_STORAGE;
        mServerStorageTypeOld = mServerStorageType;
        mServerStorageType = nItem::STORAGE_TYPE_STORAGE_ALL;
        mRefToggle.setTxt(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 80u));
        mIsResetTab = true;
        mIsForceUpdate = true;
    } else {
        if (mStorageType == nCharacterData::ITEM_BAG_TYPE_STORAGE) {
            mStorageType = nCharacterData::ITEM_BAG_TYPE_EX_STORAGE;
            mServerStorageTypeOld = mServerStorageType;
            mServerStorageType = nItem::STORAGE_TYPE_STORAGE_EX1_ALL;
            mRefToggle.setTxt(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 79u));
            if (!sGame::getInstance()->isChargeEffect(nGpCourse::GP_COURSE_EFFECT_STRAGE_EXTEND)) {
                if (!mIsBoxErrAna) {
                    sGUI* t0 = sGUI::getInstance();
                    static_cast<sGUIExt*>(t0)->requestAnnounce(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(static_cast<sGUIExt*>(t0)->getMsgCommonDialog(), 306u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                    mIsBoxErrAna = true;
                    mIsResetTab = true;
                    mIsForceUpdate = true;
                } else {
                    mIsResetTab = true;
                    mIsForceUpdate = true;
                }
            } else {
                mIsResetTab = true;
                mIsForceUpdate = true;
            }
        } else {
            mIsResetTab = true;
            mIsForceUpdate = true;
        }
    }
}

__attribute__((weak)) void uGUIStorage::move() {
    DDON_STUB("uGUIStorage::move")
    /* stub */
}

__attribute__((weak)) void uGUIStorage::adjustScale() {
    DDON_STUB("uGUIStorage::adjustScale")
    /* stub */
}

__attribute__((weak)) u32 uGUIStorage::evCtrlCatch(cControl::Message* msg) {
    DDON_STUB("uGUIStorage::evCtrlCatch")
    return {};
}

u32 uGUIStorage::evCtrlDecide(cControl::Message* msg) {
    this->uGUIItemBase01::evCtrlDecide(msg);
    return 0;
}

__attribute__((weak)) u32 uGUIStorage::evCtrlToggle(cControl::Message* msg) {
    DDON_STUB("uGUIStorage::evCtrlToggle")
    return {};
}

sItemManager::cItemBag::ITEM_CATEGORY uGUIStorage::getTab2Category() {
    return sItemManager::cItemBag::ITEM_CATEGORY_ALL_ITEM;
}

__attribute__((weak)) void uGUIStorage::setGuideBtn() {
    DDON_STUB("uGUIStorage::setGuideBtn")
    /* stub */
}

void uGUIStorage::setWindowMouseOver() {
    cControl* t0 = mpCtrlButton;
    t0->addMouseTouchList(getInstance(4u, false), 0, 0u, 1u);
}

bool uGUIStorage::isMatrixHeightLimitOver() {
    return true;
}

bool uGUIStorage::isChangeRow() {
    return false;
}

__attribute__((weak)) void uGUIStorage::loadItem() {
    DDON_STUB("uGUIStorage::loadItem")
    /* stub */
}

__attribute__((weak)) void uGUIStorage::loadItemEx() {
    DDON_STUB("uGUIStorage::loadItemEx")
    /* stub */
}

void uGUIStorage::updateInit() {
    this->uGUIItemBase01::updateInit();
    setFlowId(1u);
    if (mpShareUnit != nullptr) {
        if (!mIsShareSameUnit) {
            if (mpShareUnit->getFlowId() > 1u) {
                setWindowActive(true);
                setFlowId(2u);
            }
        } else {
            setFlowId(2u);
        }
    } else {
        setWindowActive(true);
        setFlowId(2u);
    }
}

void uGUIStorage::updateDetail() {
    if (mpDetail != nullptr) {
        if (isFocus()) {
            sItemManager::cItemBag::ITEM_CATEGORY t0 = getTab2Category();
            nGUIItem::cItem* t1 = mItemList.getItem(t0, static_cast<u32>(getSelectIdx()));
            mpDetail->setItemParam(t1, nCharacterData::EQUIP_SLOT_TYPE_START);
            mpDetail->mpOwner = static_cast<uGUIBase*>(this);
        } else {
            uGUIUseItemBase* v0_9 = mpShareUnit;
            if (v0_9 != nullptr) {
                const MtDTI& t2 = v0_9->getDTI();
                MT_CTSTR v0_1 = uGUIItemBase01::DTI.mName;
                for (const MtDTI* v0_0 = &t2;;) {
                    if (v0_1 != v0_0->mName) {
                        if (v0_0->mpParent != nullptr) {
                            v0_0 = v0_0->mpParent;
                        } else {
                            break;
                        }
                    } else {
                        uGUIPopDetail01* t3 = mpDetail;
                        t3->setItemParam(static_cast<uGUIItemBase01*>(v0_9)->getSelectItem(), nCharacterData::EQUIP_SLOT_TYPE_START);
                        mpDetail->mpOwner = static_cast<uGUIBase*>(v0_9);
                        return;
                    }
                }
            }
        }
    }
}

void uGUIStorage::setTitle() {
    MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 34u);
    setTitleCore(t0, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 10u));
}

__attribute__((weak)) void uGUIStorage::setupGuideBtn() {
    DDON_STUB("uGUIStorage::setupGuideBtn")
    /* stub */
}

u32 uGUIStorage::getToggleType() {
    return 2;
}

u32 uGUIStorage::getToggleSwitchMsg() {
    return 80;
}

__attribute__((weak)) uGUIItemBase01* uGUIStorage::createShareUnit() {
    DDON_STUB("uGUIStorage::createShareUnit")
    return nullptr;
}

u8 uGUIStorage::getRowEx() {
    return 8;
}

__attribute__((weak)) void uGUIStorage::setShareUnitStorageChange(nGUIItem::cItem* pItem) {
    DDON_STUB("uGUIStorage::setShareUnitStorageChange")
    /* stub */
}

inline uGUIStorage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIStorage::MyDTI uGUIStorage::DTI("uGUIStorage", &::uGUIItemBase01::DTI, 4464ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIStorage::MyDTI::newInstance() const {
    DDON_STUB("uGUIStorage::MyDTI::newInstance")
    return nullptr;
}

