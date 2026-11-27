// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIServerSelect.h"
#include "Protocol/PacketData/Clan.h"
#include "Protocol/PacketData/Community.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Server.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuSupport.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIServerSelectBase::getDTI() const {
    return uGUIServerSelectBase::DTI;
}

__attribute__((noinline)) uGUIServerSelectBase::~uGUIServerSelectBase() {
    if (mpSE != nullptr) {
        mpSE->release();
        mpSE = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIServerSelectBase::createProperty(MtPropertyList& s) {
    this->uGUIsMenuBase::createProperty(s);
}

bool uGUIServerSelectBase::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_SERVER_SELECT_GUI"), 129u, 1448858338l))) == nullptr)) {
        return false;
    }
    if ((mpSE == nullptr) && ((mpSE = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_TITLE_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_SERVER_SELECT_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIServerSelectBase::setup() {
    DDON_STUB("uGUIServerSelectBase::setup")
    /* stub */
}

void uGUIServerSelectBase::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) bool uGUIServerSelectBase::changeFlow(u32 sw, bool force) {
    DDON_STUB("uGUIServerSelectBase::changeFlow")
    return {};
}

__attribute__((weak)) uGUIServerSelectBase::cName* uGUIServerSelectBase::addListName(MT_CTSTR str, MT_CTSTR info, u32 index, u32 nowNum, u32 maxNum) {
    DDON_STUB("uGUIServerSelectBase::addListName")
    return nullptr;
}

__attribute__((weak)) void uGUIServerSelectBase::setupArray() {
    DDON_STUB("uGUIServerSelectBase::setupArray")
    /* stub */
}

__attribute__((weak)) void uGUIServerSelectBase::setSleep(bool b) {
    DDON_STUB("uGUIServerSelectBase::setSleep")
    /* stub */
}

void uGUIServerSelectBase::playLobbySE() {
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSE, 103u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void uGUIServerSelectBase::setServerResult(uGUIBase* pBase, uGUIServerSelectBase::RESULT_SERVER result) {
    if (pBase == nullptr) {
        return;
    }
    uGUIServerSelectBase* pUnit = static_cast<uGUIServerSelectBase*>(pBase);
    pUnit->mServerResult = result;
}

__attribute__((weak)) void uGUIServerSelectBase::setListInfo() {
    DDON_STUB("uGUIServerSelectBase::setListInfo")
    /* stub */
}

__attribute__((weak)) void uGUIServerSelectBase::updateInit() {
    DDON_STUB("uGUIServerSelectBase::updateInit")
    /* stub */
}

void uGUIServerSelectBase::updateWait() {
    if (mpCtrl == nullptr) {
        return;
    }
    if (mSwitch != 0) {
        if (mpINST_Null_info != nullptr) {
            mpINST_Null_info->setVisible(false);
        }
        mRefBtnGuideMain.setVisible(true);
        mRefBtnGuideMain.uGUIBase::cReferenceUIBtnGuide::update();
        mRefBtnGuideSub.uGUIBase::cReferenceUIBtnGuide::update();
    } else {
        bool t0 = sMenu::getInstance()->mMenuServerList.isGetCommunityList();
        if (mpINST_Null_info != nullptr) {
            mpINST_Null_info->setVisible(t0);
        }
        mRefBtnGuideMain.setVisible(!t0);
        mRefBtnGuideMain.uGUIBase::cReferenceUIBtnGuide::update();
        mRefBtnGuideSub.uGUIBase::cReferenceUIBtnGuide::update();
    }
    mList.uGUIBase::cScrollList::update(getDeltaTime());
    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
    mIsUpdate = false;
    managedMember();
}

void uGUIServerSelectBase::updateExit() {
    if (!mIsFlowEnd) {
        return;
    }
    end();
}

__attribute__((weak)) void uGUIServerSelectBase::updateSleep() {
}

void uGUIServerSelectBase::updateWaitServer() {
    updateWait();
    if (mServerResult != RESULT_SERVER_ERROR) {
        return;
    }
    if (mpCtrl != nullptr) {
        mpCtrl->setFocus(true);
    }
    mList.setFocus(true);
    mServerResult = RESULT_SERVER_NONE;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerSelectBase::updateWait);
}

__attribute__((weak)) void uGUIServerSelectBase::managedMember() {
    DDON_STUB("uGUIServerSelectBase::managedMember")
    /* stub */
}

__attribute__((weak)) void uGUIServerSelectBase::updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIServerSelectBase::updateScrollListDisp")
    /* stub */
}

void uGUIServerSelectBase::updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    cScrollDistList* pDisp = static_cast<cScrollDistList*>(pDispItem);
    setObjectMessage(static_cast<cGUIObject*>(pDisp->mpMsgTitle), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pDisp->mpMsgNum), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pDisp->mpMsgInfo), "", 0u, false);
}

void uGUIServerSelectBase::moveInput() {
    RESULT_SERVER t0 = mServerResult;
    if (t0 == RESULT_SERVER_WAIT) {
        unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2048);
        unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2056);
        if (t1 == 785) {
            if (!((mpCurrentFunc == static_cast<void(uGUIBase::*)()>(0)) || (t2 == 0))) {
                cControl* t3 = mpCtrl;
                if (t3 != nullptr) {
                    t3->setFocus(false);
                    mList.setFocus(false);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerSelectBase::updateWaitServer);
                    bool t7 = mSleep;
                    if (!t7) {
                        mList.executeCtrl();
                        cControl* t9 = mpCtrl;
                        t9->execute();
                        mCloseButton.execute();
                        cGUIInstNull* t12 = mpINST_Null_info;
                        if (t12 != nullptr) {
                            unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                            if ((t12->mAttr & 1u) != 0) {
                                mRefNumPager.execute();
                            }
                        }
                    }
                } else {
                    mList.setFocus(false);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerSelectBase::updateWaitServer);
                    bool t7 = mSleep;
                    if (!t7) {
                        mList.executeCtrl();
                        cControl* t9 = mpCtrl;
                        t9->execute();
                        mCloseButton.execute();
                        cGUIInstNull* t12 = mpINST_Null_info;
                        if (t12 != nullptr) {
                            unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                            if ((t12->mAttr & 1u) != 0) {
                                mRefNumPager.execute();
                            }
                        }
                    }
                }
            } else {
                bool t7 = mSleep;
                if (!t7) {
                    mList.executeCtrl();
                    cControl* t9 = mpCtrl;
                    t9->execute();
                    mCloseButton.execute();
                    cGUIInstNull* t12 = mpINST_Null_info;
                    if (t12 != nullptr) {
                        unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                        if ((t12->mAttr & 1u) != 0) {
                            mRefNumPager.execute();
                        }
                    }
                }
            }
        } else {
            cControl* t3 = mpCtrl;
            if (t3 != nullptr) {
                t3->setFocus(false);
                mList.setFocus(false);
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerSelectBase::updateWaitServer);
                bool t7 = mSleep;
                if (!t7) {
                    mList.executeCtrl();
                    cControl* t9 = mpCtrl;
                    t9->execute();
                    mCloseButton.execute();
                    cGUIInstNull* t12 = mpINST_Null_info;
                    if (t12 != nullptr) {
                        unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                        if ((t12->mAttr & 1u) != 0) {
                            mRefNumPager.execute();
                        }
                    }
                }
            } else {
                mList.setFocus(false);
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerSelectBase::updateWaitServer);
                bool t7 = mSleep;
                if (!t7) {
                    mList.executeCtrl();
                    cControl* t9 = mpCtrl;
                    t9->execute();
                    mCloseButton.execute();
                    cGUIInstNull* t12 = mpINST_Null_info;
                    if (t12 != nullptr) {
                        unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                        if ((t12->mAttr & 1u) != 0) {
                            mRefNumPager.execute();
                        }
                    }
                }
            }
        }
    } else {
        bool t7 = mSleep;
        if (!t7) {
            mList.executeCtrl();
            cControl* t9 = mpCtrl;
            t9->execute();
            mCloseButton.execute();
            cGUIInstNull* t12 = mpINST_Null_info;
            if (t12 != nullptr) {
                unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12) + 88);
                if ((t12->mAttr & 1u) != 0) {
                    mRefNumPager.execute();
                }
            }
        }
    }
}

void uGUIServerSelectBase::moveEvent() {
    mList.moveEvent();
    if (static_cast<int>(getInputEvent()) <= 65) {
        if (static_cast<int>(getInputEvent()) <= 51) {
            if (getInputEvent() != 4) {
                if (getInputEvent() != 5) {
                    if (getInputEvent() == 14) {
                        mIsDecide = true;
                        mIsCancel = true;
                    }
                } else {
                    mIsCancel = true;
                }
            } else {
                mIsDecide = true;
                mIsCancel = true;
            }
        } else {
            if (getInputEvent() == 52) {
                mRefNumPager.addNum(-1);
            } else {
                if (getInputEvent() == 53) {
                    mRefNumPager.addNum(1);
                }
            }
        }
    } else {
        if (getInputEvent() == 66) {
            mRefNumPager.addNum(1);
        }
    }
}

u32 uGUIServerSelectBase::evCtrlDecide(cControl::Message* msg) {
    if (mNameArray.mLength != 0) {
        setInputEvent(4u);
        mRefNumPager.mNum = 0;
        mRefNumPager.changeString();
    }
    return 0;
}

u32 uGUIServerSelectBase::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    mRefNumPager.mNum = 0;
    mRefNumPager.changeString();
    return 0;
}

u32 uGUIServerSelectBase::evCtrlTop(cControl::Message* msg) {
    if (mSwitch == 0) {
        if (!sMenu::getInstance()->mMenuServerList.isGetCommunityList()) {
            setInputEvent(7u);
        } else {
            setInputEvent(66u);
        }
    } else {
        if (mSwitch == 1) {
            setInputEvent(7u);
        } else {
            setInputEvent(66u);
        }
    }
    return 0;
}

inline uGUIServerSelectBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectBase::MyDTI uGUIServerSelectBase::DTI("uGUIServerSelectBase", &::uGUIsMenuBase::DTI, 5552ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIServerSelectBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIServerSelectBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIServerSelectBase::cScrollDistList::getDTI() const {
    return uGUIServerSelectBase::cScrollDistList::DTI;
}

inline uGUIServerSelectBase::cScrollDistList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectBase::cScrollDistList::MyDTI uGUIServerSelectBase::cScrollDistList::DTI("uGUIServerSelectBase::cScrollDistList", &::uGUIBase::cScrollListItemBase::DTI, 128ul, 0u, 0u);

MtObject* uGUIServerSelectBase::cScrollDistList::MyDTI::newInstance() const {
    return new (16u) uGUIServerSelectBase::cScrollDistList;
}

const MtDTI& uGUIServerSelectBase::cGUIMember::getDTI() const {
    return uGUIServerSelectBase::cGUIMember::DTI;
}

inline uGUIServerSelectBase::cGUIMember::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectBase::cGUIMember::MyDTI uGUIServerSelectBase::cGUIMember::DTI("uGUIServerSelectBase::cGUIMember", &::MtObject::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIServerSelectBase::cGUIMember::MyDTI::newInstance() const {
    DDON_STUB("uGUIServerSelectBase::cGUIMember::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIServerSelectBase::cName::getDTI() const {
    return uGUIServerSelectBase::cName::DTI;
}

inline uGUIServerSelectBase::cName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectBase::cName::MyDTI uGUIServerSelectBase::cName::DTI("uGUIServerSelectBase::cName", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* uGUIServerSelectBase::cName::MyDTI::newInstance() const {
    return new (16u) uGUIServerSelectBase::cName;
}

const MtDTI& uGUIServerSelectBase::cScrollInfoList::getDTI() const {
    return uGUIServerSelectBase::cScrollInfoList::DTI;
}

uGUIServerSelectBase::cScrollInfoList::~cScrollInfoList() {
}

inline uGUIServerSelectBase::cScrollInfoList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectBase::cScrollInfoList::MyDTI uGUIServerSelectBase::cScrollInfoList::DTI("uGUIServerSelectBase::cScrollInfoList", &::uGUIBase::cScrollListInfoBase::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIServerSelectBase::cScrollInfoList::MyDTI::newInstance() const {
    DDON_STUB("uGUIServerSelectBase::cScrollInfoList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIServerSelectSMENU::getDTI() const {
    return uGUIServerSelectSMENU::DTI;
}

__attribute__((weak)) void uGUIServerSelectSMENU::setup() {
    DDON_STUB("uGUIServerSelectSMENU::setup")
    /* stub */
}

s32 uGUIServerSelectSMENU::getSMenuCursorX() {
    return 0;
}

s32 uGUIServerSelectSMENU::getSMenuCursorY() {
    if (mList.mpVCtrl != nullptr) {
        return mList.mpVCtrl->getCurrentPos();
    } else {
        return 0;
    }
}

inline uGUIServerSelectSMENU::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectSMENU::MyDTI uGUIServerSelectSMENU::DTI("uGUIServerSelectSMENU", &::uGUIServerSelectBase::DTI, 5552ul, 0u, 0u);

MtObject* uGUIServerSelectSMENU::MyDTI::newInstance() const {
    return new (16u) uGUIServerSelectSMENU;
}

const MtDTI& uGUIServerSelectSMENUserver::getDTI() const {
    return uGUIServerSelectSMENUserver::DTI;
}

void uGUIServerSelectSMENUserver::updateInit() {
    this->uGUIServerSelectBase::updateInit();
}

__attribute__((weak)) void uGUIServerSelectSMENUserver::updateWait() {
    DDON_STUB("uGUIServerSelectSMENUserver::updateWait")
    /* stub */
}

inline uGUIServerSelectSMENUserver::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerSelectSMENUserver::MyDTI uGUIServerSelectSMENUserver::DTI("uGUIServerSelectSMENUserver", &::uGUIServerSelectSMENU::DTI, 5552ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIServerSelectSMENUserver::MyDTI::newInstance() const {
    DDON_STUB("uGUIServerSelectSMENUserver::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIServerSelectBase::cGUIMember>::~MtTypedArray();

template MtTypedArray<uGUIServerSelectBase::cName>::~MtTypedArray();

