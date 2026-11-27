// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarPopItemList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIAnnounce.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarPopItemList::getDTI() const {
    return uGUIBazaarPopItemList::DTI;
}

void* uGUIBazaarPopItemList::operator new(size_t sz, u32 align) {
    return uGUIBazaarPopItemList::getAllocator()->memAlloc(sz, align, uGUIBazaarPopItemList::DTI.getID());
}

uGUIBazaarPopItemList::~uGUIBazaarPopItemList() {
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

void uGUIBazaarPopItemList::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\347\265\202\344\272\206", static_cast<MT_MFUNC>(&::uGUIBazaarPopItemList::hide), 10u);
}

bool uGUIBazaarPopItemList::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_ITEMLIST_GUI"), 129u, 1430185370l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarPopItemList::move() {
    mIsCancel = false;
    mIsDecide = false;
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarPopItemList::setup() {
    DDON_STUB("uGUIBazaarPopItemList::setup")
    /* stub */
}

void uGUIBazaarPopItemList::kill() {
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUIBazaarPopItemList::updatePtr() {
    if (mpAnnounce == nullptr) {
        return;
    }
    if (mpAnnounce->isEnable()) {
        return;
    }
    mpAnnounce = nullptr;
}

void uGUIBazaarPopItemList::begin(u32 itemId) {
    replacePriority(11u);
    mFocus = true;
    mpPriceListCtrl->setFocus(true);
    mpPageCtrl->setFocus(true);
    (&mNumPageBtn)->setFocus(true);
    (&mCloseButton)->setFocus(true);
    mCloseButton.mEnable = true;
    mIsBegin = true;
    mItemId = itemId;
    setWindowActive(true);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopItemList::updateInit);
}

__attribute__((weak)) void uGUIBazaarPopItemList::hide() {
    DDON_STUB("uGUIBazaarPopItemList::hide")
    /* stub */
}

void uGUIBazaarPopItemList::stay() {
    setWindowActive(false);
    mFocus = false;
    mpPriceListCtrl->setFocus(false);
    mpPageCtrl->setFocus(false);
    (&mNumPageBtn)->setFocus(false);
    (&mCloseButton)->setFocus(false);
    mCloseButton.mEnable = false;
    mStay = true;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopItemList::updateWait);
}

__attribute__((weak)) void uGUIBazaarPopItemList::moveInput() {
    DDON_STUB("uGUIBazaarPopItemList::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopItemList::moveEvent() {
    DDON_STUB("uGUIBazaarPopItemList::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopItemList::updateInit() {
    DDON_STUB("uGUIBazaarPopItemList::updateInit")
    /* stub */
}

void uGUIBazaarPopItemList::updateMove() {
    mItemSelCursor.uGUIBase::cReferenceUIVlCursor::update();
    mNumPageBtn.uGUIBase::cReferenceUINumPager::update();
    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
    updateItemList();
}

void uGUIBazaarPopItemList::updateAnnounce() {
    if (mpAnnounce == nullptr) {
        mFocus = true;
        mpPriceListCtrl->setFocus(true);
        mpPageCtrl->setFocus(true);
        (&mNumPageBtn)->setFocus(true);
        (&mCloseButton)->setFocus(true);
        mCloseButton.mEnable = true;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopItemList::updateMove);
    }
    mItemSelCursor.uGUIBase::cReferenceUIVlCursor::update();
    mNumPageBtn.uGUIBase::cReferenceUINumPager::update();
    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
}

void uGUIBazaarPopItemList::updateWait() {
    mItemSelCursor.uGUIBase::cReferenceUIVlCursor::update();
}

__attribute__((weak)) void uGUIBazaarPopItemList::initialize() {
    DDON_STUB("uGUIBazaarPopItemList::initialize")
    /* stub */
}

u32 uGUIBazaarPopItemList::evCtrlSelectList(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIBazaarPopItemList::evCtrlDecideList(cControl::Message* msg) {
    if (sBazaarManager::getInstance()->mItemInfoCtrl.mItemInfo.mLength != 0) {
        setInputEvent(66u);
    }
    return 0;
}

u32 uGUIBazaarPopItemList::evCtrlCancelList(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBazaarPopItemList::evCtrlSelectPage(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

void uGUIBazaarPopItemList::evSelectPage() {
    u32 listNum = sBazaarManager::getInstance()->mItemInfoCtrl.mItemInfo.mLength;
    unsigned int v0_0;
    if (mpPageCtrl == nullptr) {
        v0_0 = 0;
    } else {
        v0_0 = mpPageCtrl->mCurrentPos * 10;
    }
    cVerticalList* v4_3 = mpPriceListCtrl;
    unsigned int v7_3;
    if ((listNum - v0_0) > 9u) {
        s32 v3_1;
        if (v4_3 == nullptr) {
            v3_1 = v4_3->getCurrentPos();
        } else {
            v4_3->resetItemNum(10, static_cast<const u32*>(nullptr), v4_3->getCurrentPos());
            for (unsigned int i1_11 = 0; i1_11 != 10; i1_11 = i1_11 + 1u) {
                mpPriceListCtrl->addMouseTouchList(static_cast<cGUIInstance*>(mItemPrice[i1_11].mpInstAnimMsgList), static_cast<cGUIObject*>(mItemPrice[i1_11].mpObjMouseOver), static_cast<s32>(i1_11), static_cast<cGUIObject*>(nullptr), 1u, 1u, -1);
            }
            v3_1 = mpPriceListCtrl->getCurrentPos();
        }
        v7_3 = v3_1;
    } else {
        s32 v4_1;
        if (v4_3->getCurrentPos() < static_cast<int>(listNum - v0_0)) {
            v4_1 = v4_3->getCurrentPos();
        } else {
            v4_1 = (static_cast<int>((listNum - v0_0) - 1u) <= -1) ? 0u : ((listNum - v0_0) - 1u);
        }
        listNum = listNum - v0_0;
        if (v4_3 != nullptr) {
            if (listNum <= 10u) {
                if (v0_0 == listNum) {
                    v4_3->resetItemNum(1, static_cast<const u32*>(nullptr), v4_1);
                } else {
                    v4_3->resetItemNum(static_cast<s32>(listNum), static_cast<const u32*>(nullptr), v4_1);
                    if (static_cast<int>(listNum) > 0) {
                        unsigned int v5_10 = listNum - v0_0;
                        for (unsigned int i5_11 = 0;;) {
                            mpPriceListCtrl->addMouseTouchList(static_cast<cGUIInstance*>(mItemPrice[i5_11].mpInstAnimMsgList), static_cast<cGUIObject*>(mItemPrice[i5_11].mpObjMouseOver), static_cast<s32>(i5_11), static_cast<cGUIObject*>(nullptr), 1u, 1u, -1);
                            if (v5_10 != (i5_11 + 1u)) {
                                i5_11 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
        v7_3 = mpPriceListCtrl->getCurrentPos();
    }
    mItemSelCursor.setCtrlPos(static_cast<s32>(v7_3), false);
}

__attribute__((weak)) void uGUIBazaarPopItemList::updateItemList() {
    DDON_STUB("uGUIBazaarPopItemList::updateItemList")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopItemList::updateItemIcon() {
    DDON_STUB("uGUIBazaarPopItemList::updateItemIcon")
    /* stub */
}

bool uGUIBazaarPopItemList::isAddBagNum(u32 itemNo, u32 num) {
    if (sGame::getInstance()->isChargeEffect(nGpCourse::GP_COURSE_EFFECT_STRAGE_EXTEND)) {
        sItemManager::cItemBag* pBag = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_EX_STORAGE);
        if (pBag != nullptr) {
            u32 t0 = pBag->getItemAddMaxNum(itemNo);
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_STORAGE);
            if (t1 != nullptr) {
                u32 t2 = t1->getItemAddMaxNum(itemNo);
                sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
                if (t3 != nullptr) {
                    u32 t4 = t3->getItemAddMaxNum(itemNo);
                    return ((t0 + t2) + t4) >= num;
                } else {
                    return (t0 + t2) >= num;
                }
            } else {
                sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
                if (t3 != nullptr) {
                    u32 t4 = t3->getItemAddMaxNum(itemNo);
                    return (t0 + t4) >= num;
                } else {
                    return t0 >= num;
                }
            }
        } else {
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_STORAGE);
            if (t1 != nullptr) {
                u32 t2 = t1->getItemAddMaxNum(itemNo);
                sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
                if (t3 != nullptr) {
                    u32 t4 = t3->getItemAddMaxNum(itemNo);
                    return (t2 + t4) >= num;
                } else {
                    return t2 >= num;
                }
            } else {
                sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
                if (t3 != nullptr) {
                    u32 t4 = t3->getItemAddMaxNum(itemNo);
                    return t4 >= num;
                } else {
                    return num <= 0u;
                }
            }
        }
    } else {
        sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_STORAGE);
        if (t1 != nullptr) {
            u32 t2 = t1->getItemAddMaxNum(itemNo);
            sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
            if (t3 != nullptr) {
                u32 t4 = t3->getItemAddMaxNum(itemNo);
                return (t2 + t4) >= num;
            } else {
                return t2 >= num;
            }
        } else {
            sItemManager::cItemBag* t3 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
            if (t3 != nullptr) {
                u32 t4 = t3->getItemAddMaxNum(itemNo);
                return t4 >= num;
            } else {
                return num <= 0u;
            }
        }
    }
}

__attribute__((weak)) void uGUIBazaarPopItemList::createAnnounce() {
    DDON_STUB("uGUIBazaarPopItemList::createAnnounce")
    /* stub */
}

inline uGUIBazaarPopItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopItemList::MyDTI uGUIBazaarPopItemList::DTI("uGUIBazaarPopItemList", &::uGUIBase::DTI, 4128ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBazaarPopItemList::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarPopItemList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBazaarPopItemList::cItemData::getDTI() const {
    return uGUIBazaarPopItemList::cItemData::DTI;
}

inline uGUIBazaarPopItemList::cItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopItemList::cItemData::MyDTI uGUIBazaarPopItemList::cItemData::DTI("uGUIBazaarPopItemList::cItemData", &::MtObject::DTI, 432ul, 0u, 0u);

MtObject* uGUIBazaarPopItemList::cItemData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarPopItemList::cItemData;
}

const MtDTI& uGUIBazaarPopItemList::cItemPrice::getDTI() const {
    return uGUIBazaarPopItemList::cItemPrice::DTI;
}

inline uGUIBazaarPopItemList::cItemPrice::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopItemList::cItemPrice::MyDTI uGUIBazaarPopItemList::cItemPrice::DTI("uGUIBazaarPopItemList::cItemPrice", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* uGUIBazaarPopItemList::cItemPrice::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarPopItemList::cItemPrice;
}

