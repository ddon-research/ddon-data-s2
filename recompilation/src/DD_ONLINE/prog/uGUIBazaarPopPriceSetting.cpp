// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarPopPriceSetting.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
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
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarPopPriceSetting::getDTI() const {
    return uGUIBazaarPopPriceSetting::DTI;
}

void* uGUIBazaarPopPriceSetting::operator new(size_t sz, u32 align) {
    return uGUIBazaarPopPriceSetting::getAllocator()->memAlloc(sz, align, uGUIBazaarPopPriceSetting::DTI.getID());
}

__attribute__((noinline)) uGUIBazaarPopPriceSetting::~uGUIBazaarPopPriceSetting() {
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

void uGUIBazaarPopPriceSetting::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\351\226\213\345\247\213", static_cast<MT_MFUNC>(&::uGUIBazaarPopPriceSetting::begin), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\265\202\344\272\206", static_cast<MT_MFUNC>(&::uGUIBazaarPopPriceSetting::hide), 10u);
}

bool uGUIBazaarPopPriceSetting::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_PRICESETTING_GUI"), 129u, 1449020412l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarPopPriceSetting::move() {
    mIsCancel = false;
    mIsDecide = false;
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::setup() {
    DDON_STUB("uGUIBazaarPopPriceSetting::setup")
    /* stub */
}

void uGUIBazaarPopPriceSetting::kill() {
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

__attribute__((weak)) void uGUIBazaarPopPriceSetting::updatePtr() {
}

void uGUIBazaarPopPriceSetting::begin() {
    replacePriority(11u);
    mFocus = true;
    mIsBegin = true;
    setWindowActive(true);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopPriceSetting::updateInit);
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::hide() {
    DDON_STUB("uGUIBazaarPopPriceSetting::hide")
    /* stub */
}

void uGUIBazaarPopPriceSetting::stay() {
    setWindowActive(false);
    mGoldBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
    mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
    mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
    mFocus = false;
    mStay = true;
    mIsBegin = false;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarPopPriceSetting::updateWait);
}

u32 uGUIBazaarPopPriceSetting::getItemNo() {
    if (mpItemParam != nullptr) {
        return mpItemParam->getItemId();
    } else {
        return 0;
    }
}

void uGUIBazaarPopPriceSetting::setFocus(bool isFocus) {
    mFocus = isFocus;
    if (isFocus) {
        mpMenuCtrl->setFocus(true);
        mpDecToCanCtrl->setFocus(true);
    } else {
        mpMenuCtrl->setFocus(false);
        mpDecToCanCtrl->setFocus(false);
    }
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::moveInput() {
    DDON_STUB("uGUIBazaarPopPriceSetting::moveInput")
    /* stub */
}

void uGUIBazaarPopPriceSetting::moveEvent() {
    if (getInputEvent() == 67) {
        mIsCancel = true;
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
    } else {
        if (getInputEvent() == 66) {
            mIsDecide = true;
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
        }
    }
    mGoldBoxBtn.moveEvent();
    mNumBoxBtn.moveEvent();
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::updateInit() {
    DDON_STUB("uGUIBazaarPopPriceSetting::updateInit")
    /* stub */
}

void uGUIBazaarPopPriceSetting::updateMove() {
    if (mGoldBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
        if (mGoldBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
            mpMenuCtrl->setFocus(true);
            mpDecToCanCtrl->setFocus(true);
            if (mpDecToCanCtrl != nullptr) {
                mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
            }
        }
        if (mNumBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
            if (mMode != 0) {
            }
            if (mNumBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
                mpMenuCtrl->setFocus(true);
                mpDecToCanCtrl->setFocus(true);
                if (mpDecToCanCtrl != nullptr) {
                    mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                }
            }
        }
        mBtnGuide.setDispBit(1u);
    } else {
        if (mNumBoxBtn.uGUIBase::cReferenceUINumBox::isFocus()) {
            if (mMode != 0) {
                if (mNumBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
                    mpMenuCtrl->setFocus(true);
                    mpDecToCanCtrl->setFocus(true);
                    if (mpDecToCanCtrl != nullptr) {
                        mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                    }
                }
                mBtnGuide.setDispBit(0u);
            } else {
                if (mNumBoxBtn.mMode == uGUIBase::cReferenceUINumBox::MODE_DEFAULT) {
                    mpMenuCtrl->setFocus(true);
                    mpDecToCanCtrl->setFocus(true);
                    if (mpDecToCanCtrl != nullptr) {
                        mpDecToCanCtrl->mCtrlF = mpDecToCanCtrl->mCtrlF | 8u;
                    }
                }
                mBtnGuide.setDispBit(1u);
            }
        } else {
            mBtnGuide.setDispBit(0u);
        }
    }
    mGoldBoxBtn.uGUIBase::cReferenceUINumBox::update();
    mNumBoxBtn.uGUIBase::cReferenceUINumBox::update();
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::updateWait() {
}

__attribute__((weak)) void uGUIBazaarPopPriceSetting::initialize() {
    DDON_STUB("uGUIBazaarPopPriceSetting::initialize")
    /* stub */
}

void uGUIBazaarPopPriceSetting::setItem() {
    if (mpItemParam == nullptr) {
        return;
    }
    cGUIObjMessage* t0 = mItemData.mpObjMsgItemName;
    setObjectMessage(static_cast<cGUIObject*>(t0), mpItemParam->getItemName(), 0u, false);
    setInstanceVisibleTree(mItemData.mpInstItemData, true);
    mItemData.mItemIcon.uGUIBase::cReferenceUIIconItem::setIconFromParam(mpItemParam);
    if (mItemData.mItemIcon.mpInstances.elems[0] != nullptr) {
        mItemData.mItemIcon.mpInstances.elems[0]->cGUIInstance::setVisible(true);
    }
    if (mItemData.mItemIcon.mpInstances.elems[1] != nullptr) {
        mItemData.mItemIcon.mpInstances.elems[1]->cGUIInstance::setVisible(true);
    }
    if (mItemData.mItemIcon.mpInstances.elems[2] == nullptr) {
        return;
    }
    mItemData.mItemIcon.mpInstances.elems[2]->cGUIInstance::setVisible(true);
}

__attribute__((weak)) u32 uGUIBazaarPopPriceSetting::evCtrlSelectMenu(cControl::Message* msg) {
    DDON_STUB("uGUIBazaarPopPriceSetting::evCtrlSelectMenu")
    return {};
}

u32 uGUIBazaarPopPriceSetting::evCtrlDecideMenu(cControl::Message* msg) {
    if (msg->pSender != mpDecToCanCtrl) {
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 2) {
                mpMenuCtrl->setFocus(false);
                mpDecToCanCtrl->setFocus(false);
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) != 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpDecToCanCtrl->getCurrentTag())) * 4)) + 0)) != 0) {
                        setInputEvent(67u);
                    } else {
                        setInputEvent(66u);
                    }
                } else {
                    if (mpDecToCanCtrl->getCurrentTag() != 0) {
                        setInputEvent(67u);
                    } else {
                        setInputEvent(66u);
                    }
                }
            }
        } else {
            if (msg->pSender->getCurrentTag() == 2) {
                mpMenuCtrl->setFocus(false);
                mpDecToCanCtrl->setFocus(false);
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) != 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpDecToCanCtrl->getCurrentTag())) * 4)) + 0)) != 0) {
                        setInputEvent(67u);
                    } else {
                        setInputEvent(66u);
                    }
                } else {
                    if (mpDecToCanCtrl->getCurrentTag() != 0) {
                        setInputEvent(67u);
                    } else {
                        setInputEvent(66u);
                    }
                }
            }
        }
        return 0;
    } else {
        mpMenuCtrl->setFocus(false);
        mpDecToCanCtrl->setFocus(false);
        mpMenuCtrl->setCurrentPos(2, false);
        mGoldBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
        mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
        cHorizontalList* t0 = mpDecToCanCtrl;
        if (t0 != nullptr) {
            t0->mCtrlF = t0->mCtrlF & 0xFFFFFFF7u;
        }
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 3120)) != 0) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 3120)) + (static_cast<long>(static_cast<int>(t0->getCurrentTag())) * 4)) + 0)) != 0) {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(true);
            } else {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(true);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            }
        } else {
            if (t0->getCurrentTag() != 0) {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(true);
            } else {
                mDecideBtn.uGUIBase::cReferenceUIButton::setFocus(true);
                mCancelBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            }
        }
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) != 0) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpDecToCanCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpDecToCanCtrl->getCurrentTag())) * 4)) + 0)) != 0) {
                setInputEvent(67u);
            } else {
                setInputEvent(66u);
            }
        } else {
            if (mpDecToCanCtrl->getCurrentTag() != 0) {
                setInputEvent(67u);
            } else {
                setInputEvent(66u);
            }
        }
        return 0;
    }
}

u32 uGUIBazaarPopPriceSetting::evCtrlCancelMenu(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBazaarPopPriceSetting::evCtrlStartMenu(cControl::Message* msg) {
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) == 1) {
            mNumBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
            mpMenuCtrl->setFocus(false);
            mpDecToCanCtrl->setFocus(false);
        } else {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) == 0) {
                mGoldBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
                mpMenuCtrl->setFocus(false);
                mpDecToCanCtrl->setFocus(false);
            }
        }
    } else {
        if (mpMenuCtrl->getCurrentTag() == 1) {
            mNumBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
            mpMenuCtrl->setFocus(false);
            mpDecToCanCtrl->setFocus(false);
        } else {
            if (mpMenuCtrl->getCurrentTag() == 0) {
                mGoldBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
                mpMenuCtrl->setFocus(false);
                mpDecToCanCtrl->setFocus(false);
            }
        }
    }
    return 0;
}

u32 uGUIBazaarPopPriceSetting::evCtrlDecSelectMenu(cControl::Message* msg) {
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

inline uGUIBazaarPopPriceSetting::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopPriceSetting::MyDTI uGUIBazaarPopPriceSetting::DTI("uGUIBazaarPopPriceSetting", &::uGUIBase::DTI, 4384ul, 0u, 0u);

alignas(4) unsigned char uGUIBazaarPopPriceSetting_mMenuTag_bytes[12] __asm__("_ZN25uGUIBazaarPopPriceSetting8mMenuTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00};

alignas(4) unsigned char uGUIBazaarPopPriceSetting_mDecideTag_bytes[8] __asm__("_ZN25uGUIBazaarPopPriceSetting10mDecideTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* uGUIBazaarPopPriceSetting::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarPopPriceSetting::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBazaarPopPriceSetting::cItemData::getDTI() const {
    return uGUIBazaarPopPriceSetting::cItemData::DTI;
}

uGUIBazaarPopPriceSetting::cItemData::~cItemData() {
}

inline uGUIBazaarPopPriceSetting::cItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopPriceSetting::cItemData::MyDTI uGUIBazaarPopPriceSetting::cItemData::DTI("uGUIBazaarPopPriceSetting::cItemData", &::MtObject::DTI, 416ul, 0u, 0u);

MtObject* uGUIBazaarPopPriceSetting::cItemData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarPopPriceSetting::cItemData;
}

