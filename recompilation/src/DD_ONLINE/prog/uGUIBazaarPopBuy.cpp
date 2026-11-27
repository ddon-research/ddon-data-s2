// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarPopBuy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarPopBuy::getDTI() const {
    return uGUIBazaarPopBuy::DTI;
}

void* uGUIBazaarPopBuy::operator new(size_t sz, u32 align) {
    return uGUIBazaarPopBuy::getAllocator()->memAlloc(sz, align, uGUIBazaarPopBuy::DTI.getID());
}

uGUIBazaarPopBuy::~uGUIBazaarPopBuy() {
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

void uGUIBazaarPopBuy::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIBazaarPopBuy::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_SALE00_GUI"), 129u, 1469516269l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarPopBuy::move() {
    mIsCancel = false;
    mIsDecide = false;
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarPopBuy::setup() {
    DDON_STUB("uGUIBazaarPopBuy::setup")
    /* stub */
}

void uGUIBazaarPopBuy::kill() {
    this->uGUIBase::kill();
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

__attribute__((weak)) void uGUIBazaarPopBuy::updatePtr() {
}

void uGUIBazaarPopBuy::begin(bool isSelect) {
    replacePriority(11u);
    setFocus(true);
    mIsBegin = true;
    mIsSelect = isSelect;
    setWindowActive(true);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopBuy::updateInit);
}

__attribute__((weak)) void uGUIBazaarPopBuy::hide() {
    DDON_STUB("uGUIBazaarPopBuy::hide")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopBuy::setFocus(bool isFocus) {
    mFocus = isFocus;
    if (isFocus) {
        mpMenuCtrl->resetItemNum(3, uGUIBazaarPopBuy::mMenuTag, 0);
        mpDecToCanCtrl->resetItemNum(2, uGUIBazaarPopBuy::mDecideTag, 0);
        mpMenuCtrl->setFocus(true);
        mpDecToCanCtrl->setFocus(true);
        mpBagNumBoxCtrl->setFocus(true);
        mpStorageNumBoxCtrl->setFocus(true);
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) != 0) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) != 2) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) == 1) {
                    if (mpDecToCanCtrl != nullptr) {
                        mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                    }
                    if (mpBagNumBoxCtrl != nullptr) {
                        mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF | 8u;
                    }
                    if (mpStorageNumBoxCtrl != nullptr) {
                        mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF & 0xFFFFFFF7u;
                    }
                } else {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) == 0) {
                        if (mpDecToCanCtrl != nullptr) {
                            mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                        }
                        if (mpBagNumBoxCtrl != nullptr) {
                            mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF & 0xFFFFFFF7u;
                        }
                        if (mpStorageNumBoxCtrl != nullptr) {
                            mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF | 8u;
                        }
                    }
                }
            } else {
                if (mpDecToCanCtrl != nullptr) {
                    mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF & 0xFFFFFFF7u;
                }
                if (mpBagNumBoxCtrl != nullptr) {
                    mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF | 8u;
                }
                if (mpStorageNumBoxCtrl != nullptr) {
                    mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF | 8u;
                }
            }
        } else {
            if (mpMenuCtrl->getCurrentTag() != 2) {
                if (mpMenuCtrl->getCurrentTag() == 1) {
                    if (mpDecToCanCtrl != nullptr) {
                        mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                    }
                    if (mpBagNumBoxCtrl != nullptr) {
                        mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF | 8u;
                    }
                    if (mpStorageNumBoxCtrl != nullptr) {
                        mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF & 0xFFFFFFF7u;
                    }
                } else {
                    if (mpMenuCtrl->getCurrentTag() == 0) {
                        if (mpDecToCanCtrl != nullptr) {
                            mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                        }
                        if (mpBagNumBoxCtrl != nullptr) {
                            mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF & 0xFFFFFFF7u;
                        }
                        if (mpStorageNumBoxCtrl != nullptr) {
                            mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF | 8u;
                        }
                    }
                }
            } else {
                if (mpDecToCanCtrl != nullptr) {
                    mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF & 0xFFFFFFF7u;
                }
                if (mpBagNumBoxCtrl != nullptr) {
                    mpBagNumBoxCtrl->mCtrlF = mpBagNumBoxCtrl->mCtrlF | 8u;
                }
                if (mpStorageNumBoxCtrl != nullptr) {
                    mpStorageNumBoxCtrl->mCtrlF = mpStorageNumBoxCtrl->mCtrlF | 8u;
                }
            }
        }
    } else {
        mpMenuCtrl->setFocus(false);
        mpDecToCanCtrl->setFocus(false);
        mpBagNumBoxCtrl->setFocus(false);
        mpStorageNumBoxCtrl->setFocus(false);
    }
}

void uGUIBazaarPopBuy::moveInput() {
    mBagBoxBtn.moveInput();
    mStorageBoxBtn.moveInput();
    if (mpMenuCtrl != nullptr) {
        if (mpMenuCtrl->getFocus()) {
            mpMenuCtrl->execute();
        }
    }
    if (mpDecToCanCtrl != nullptr) {
        if (mpDecToCanCtrl->getFocus()) {
            mpDecToCanCtrl->execute();
        }
    }
    if (mpBagNumBoxCtrl != nullptr) {
        if (mpBagNumBoxCtrl->getFocus()) {
            mpBagNumBoxCtrl->execute();
        }
    }
    if (mpStorageNumBoxCtrl == nullptr) {
        return;
    }
    if (!mpStorageNumBoxCtrl->getFocus()) {
        return;
    }
    mpStorageNumBoxCtrl->execute();
}

__attribute__((weak)) void uGUIBazaarPopBuy::moveEvent() {
    DDON_STUB("uGUIBazaarPopBuy::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopBuy::updateInit() {
    DDON_STUB("uGUIBazaarPopBuy::updateInit")
    /* stub */
}

void uGUIBazaarPopBuy::updateMove() {
    if (mBagBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
        if (mBagBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
            mpMenuCtrl->setFocus(true);
            mpBagNumBoxCtrl->setFocus(true);
            mpStorageNumBoxCtrl->setFocus(true);
            mpDecToCanCtrl->setFocus(true);
        }
        mStorageBoxBtn.setNum(static_cast<unsigned short>(mpItemData->mNum + (mBagBoxBtn.mCurrentNum * 0xFFFF)));
        if (mStorageBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
            if (mStorageBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
                mpMenuCtrl->setFocus(true);
                mpBagNumBoxCtrl->setFocus(true);
                mpStorageNumBoxCtrl->setFocus(true);
                mpDecToCanCtrl->setFocus(true);
            }
            mBagBoxBtn.setNum(static_cast<unsigned short>(mpItemData->mNum + (mStorageBoxBtn.mCurrentNum * 0xFFFF)));
        }
        mBtnGuide.setDispBit(1u);
    } else {
        if (mStorageBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
            if (mStorageBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
                mpMenuCtrl->setFocus(true);
                mpBagNumBoxCtrl->setFocus(true);
                mpStorageNumBoxCtrl->setFocus(true);
                mpDecToCanCtrl->setFocus(true);
            }
            mBagBoxBtn.setNum(static_cast<unsigned short>(mpItemData->mNum + (mStorageBoxBtn.mCurrentNum * 0xFFFF)));
            mBtnGuide.setDispBit(1u);
        } else {
            mBtnGuide.setDispBit(0u);
        }
    }
    mBagBoxBtn.uGUIBase::cReferenceUINumBox::update();
    mStorageBoxBtn.uGUIBase::cReferenceUINumBox::update();
    (&mDecideBtn)->update();
    (&mCancelBtn)->update();
    mBtnGuide.uGUIBase::cReferenceUIBtnGuide::update();
}

__attribute__((weak)) void uGUIBazaarPopBuy::updateWait() {
}

__attribute__((weak)) void uGUIBazaarPopBuy::initialize() {
    DDON_STUB("uGUIBazaarPopBuy::initialize")
    /* stub */
}

u32 uGUIBazaarPopBuy::evCtrlSelectMenu(cControl::Message* msg) {
    if (msg->pSender != mpMenuCtrl) {
        if (msg->pSender != mpBagNumBoxCtrl) {
            if (msg->pSender == mpStorageNumBoxCtrl) {
                setInputEvent(69u);
                mpMenuCtrl->setCurrentPos(1, false);
                if (msg->reason != nGUIExt::MOUSE_LCLICK) {
                    if (msg->reason != nGUIExt::TRG_RIGHT) {
                        if (msg->reason == nGUIExt::TRG_LEFT) {
                            mStorageBoxBtn.pushLArrow(-1);
                        }
                    } else {
                        mStorageBoxBtn.pushRArrow(1);
                    }
                } else {
                    if (msg->click_vol != 2) {
                        if (msg->click_vol == 1) {
                            mStorageBoxBtn.pushRArrow(1);
                        } else {
                            if (msg->click_vol == 0) {
                                mStorageBoxBtn.pushLArrow(-1);
                            }
                        }
                    } else {
                        setInputEvent(70u);
                    }
                }
                if (mpItemData != nullptr) {
                    mBagBoxBtn.setNum(static_cast<unsigned short>(mpItemData->mNum + (mStorageBoxBtn.mCurrentNum * 0xFFFF)));
                    cHorizontalList* t2 = mpBagNumBoxCtrl;
                    t2->resetItemNum(mBagBoxBtn.getMaxNum(), static_cast<const u32*>(nullptr), mBagBoxBtn.getNum());
                    cHorizontalList* t3 = mpStorageNumBoxCtrl;
                    t3->resetItemNum(mStorageBoxBtn.getMaxNum(), static_cast<const u32*>(nullptr), mStorageBoxBtn.getNum());
                    mBagBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mStorageBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                    mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    return 0;
                }
                mBagBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                mStorageBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            }
        } else {
            setInputEvent(69u);
            mpMenuCtrl->setCurrentPos(0, false);
            if (msg->reason != nGUIExt::MOUSE_LCLICK) {
                if (msg->reason != nGUIExt::TRG_RIGHT) {
                    if (msg->reason == nGUIExt::TRG_LEFT) {
                        mBagBoxBtn.pushLArrow(-1);
                    }
                } else {
                    mBagBoxBtn.pushRArrow(1);
                }
            } else {
                if (msg->click_vol != 2) {
                    if (msg->click_vol == 1) {
                        mBagBoxBtn.pushRArrow(1);
                    } else {
                        if (msg->click_vol == 0) {
                            mBagBoxBtn.pushLArrow(-1);
                        }
                    }
                } else {
                    setInputEvent(70u);
                }
            }
            if (mpItemData != nullptr) {
                mStorageBoxBtn.setNum(static_cast<unsigned short>(mpItemData->mNum + (mBagBoxBtn.mCurrentNum * 0xFFFF)));
                cHorizontalList* t0 = mpBagNumBoxCtrl;
                t0->resetItemNum(mBagBoxBtn.getMaxNum(), static_cast<const u32*>(nullptr), mBagBoxBtn.getNum());
                cHorizontalList* t1 = mpStorageNumBoxCtrl;
                t1->resetItemNum(mStorageBoxBtn.getMaxNum(), static_cast<const u32*>(nullptr), mStorageBoxBtn.getNum());
                mBagBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                mStorageBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                return 0;
            }
            mBagBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
            mStorageBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
            mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
        }
    } else {
        setInputEvent(69u);
    }
    return 0;
}

__attribute__((weak)) u32 uGUIBazaarPopBuy::evCtrlDecideMenu(cControl::Message* msg) {
    DDON_STUB("uGUIBazaarPopBuy::evCtrlDecideMenu")
    return {};
}

u32 uGUIBazaarPopBuy::evCtrlCancelMenu(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBazaarPopBuy::evCtrlStartMenu(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

u32 uGUIBazaarPopBuy::evCtrlDecSelectMenu(cControl::Message* msg) {
    setInputEvent(68u);
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 1) {
            mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(true);
        } else {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 0) {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(true);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            }
        }
    } else {
        if (msg->pSender->getCurrentTag() == 1) {
            mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(true);
        } else {
            if (msg->pSender->getCurrentTag() == 0) {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(true);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            }
        }
    }
    return 0;
}

void uGUIBazaarPopBuy::calcBagHaveNum(u32 itemNo) {
    sItemManager::cItemBag* pBag = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_STORAGE);
    if (pBag != nullptr) {
        mBagNum[0] = static_cast<int>(pBag->getItemAddMaxNum(itemNo));
        sItemManager::cItemBag* t0 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
        if (t0 != nullptr) {
            mBagNum[1] = static_cast<int>(t0->getItemAddMaxNum(itemNo));
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_EX_STORAGE);
            if (t1 != nullptr) {
                mBagNum[2] = static_cast<int>(t1->getItemAddMaxNum(itemNo));
            }
        } else {
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_EX_STORAGE);
            if (t1 != nullptr) {
                mBagNum[2] = static_cast<int>(t1->getItemAddMaxNum(itemNo));
            }
        }
    } else {
        sItemManager::cItemBag* t0 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_PL);
        if (t0 != nullptr) {
            mBagNum[1] = static_cast<int>(t0->getItemAddMaxNum(itemNo));
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_EX_STORAGE);
            if (t1 != nullptr) {
                mBagNum[2] = static_cast<int>(t1->getItemAddMaxNum(itemNo));
            }
        } else {
            sItemManager::cItemBag* t1 = sItemManager::getInstance()->setLinkItem(nCharacterData::ITEM_BAG_TYPE_EX_STORAGE);
            if (t1 != nullptr) {
                mBagNum[2] = static_cast<int>(t1->getItemAddMaxNum(itemNo));
            }
        }
    }
}

inline uGUIBazaarPopBuy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopBuy::MyDTI uGUIBazaarPopBuy::DTI("uGUIBazaarPopBuy", &::uGUIBase::DTI, 3920ul, 0u, 0u);

alignas(4) unsigned char uGUIBazaarPopBuy_mMenuTag_bytes[12] __asm__("_ZN16uGUIBazaarPopBuy8mMenuTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00};

alignas(4) unsigned char uGUIBazaarPopBuy_mDecideTag_bytes[8] __asm__("_ZN16uGUIBazaarPopBuy10mDecideTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* uGUIBazaarPopBuy::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarPopBuy::MyDTI::newInstance")
    return nullptr;
}

