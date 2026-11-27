// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUICaplinkProfile.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cCaplinkContext.h"
#include "../../XFramework/cCaplinkDataDef.h"
#include "../../XFramework/cCaplinkUserProfileContentListGet.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIObjTextureRef.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "cUIObject.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "sCaplinkManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

cCaplinkProfIconLoader::~cCaplinkProfIconLoader() {
    clear();
}

void cCaplinkProfIconLoader::setup(cGUIObject* pObjTex) {
    if (pObjTex == nullptr) {
        return;
    }
    mpObjTex = static_cast<cGUIObjTextureRef*>(pObjTex);
    pObjTex->setVisible(false);
}

__attribute__((weak)) void cCaplinkProfIconLoader::request(u32 icon_index) {
    if (mpObjTex != nullptr) {
        mpObjTex->setReferenceTexture(static_cast<rTexture*>(nullptr));
        if (mpObjTex != nullptr) {
            mpObjTex->setVisible(false);
            mIconIndex = 255;
            mIsUpdate = false;
            if (mpObjTex != nullptr) {
                if (icon_index != 255) {
                    mIconIndex = icon_index;
                    mIsUpdate = true;
                    const sCaplinkManager::cIconUrl* pUrl = sCaplinkManager::getInstance()->getIconUrlFromIndex(icon_index);
                    if (pUrl != nullptr) {
                        mId = pUrl->mId;
                    }
                    if (static_cast<sGUIExt*>(sGUI::getInstance())->getCaplinkIcon(mIconIndex) != nullptr) {
                        update();
                    }
                }
            }
        } else {
            mIconIndex = 255;
            mIsUpdate = false;
        }
    } else {
        mIconIndex = 255;
        mIsUpdate = false;
    }
}

void cCaplinkProfIconLoader::request(MT_CTSTR url) {
    if (url == nullptr) {
        return;
    }
    if ((*url) == 0) {
        return;
    }
    request(sCaplinkManager::getInstance()->getIconIndex(url));
}

__attribute__((weak)) void cCaplinkProfIconLoader::update() {
    if (!mIsUpdate) {
        return;
    }
    if (mpObjTex != nullptr) {
        mpObjTex->setVisible(false);
    }
    if (sCaplinkManager::getInstance()->isLoadingProfIcon(mId)) {
        return;
    }
    if (mpObjTex != nullptr) {
        rTexture* pTex = static_cast<sGUIExt*>(sGUI::getInstance())->getCaplinkIcon(mIconIndex);
        if (pTex != nullptr) {
            mpObjTex->setReferenceTexture(pTex);
            if (mpObjTex != nullptr) {
                mpObjTex->setVisible(true);
            }
        }
        mIsUpdate = false;
    } else {
        mIsUpdate = false;
    }
}

__attribute__((weak)) void cCaplinkProfIconLoader::clear() {
    if (mpObjTex != nullptr) {
        mpObjTex->setReferenceTexture(static_cast<rTexture*>(nullptr));
        if (mpObjTex != nullptr) {
            mpObjTex->setVisible(false);
        }
    }
    mIconIndex = 255;
    mIsUpdate = false;
}

const MtDTI& uGUICaplinkProfile::getDTI() const {
    return uGUICaplinkProfile::DTI;
}

void* uGUICaplinkProfile::operator new(size_t sz, u32 align) {
    return uGUICaplinkProfile::getAllocator()->memAlloc(sz, align, uGUICaplinkProfile::DTI.getID());
}

__attribute__((noinline)) uGUICaplinkProfile::~uGUICaplinkProfile() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUICaplinkProfile::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUICaplinkProfile::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CAP_PROFILE_GUI"), 129u, 1429754302l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CAPLINK_RES_GMD", 0u);
}

__attribute__((weak)) void uGUICaplinkProfile::setup() {
    DDON_STUB("uGUICaplinkProfile::setup")
    /* stub */
}

void uGUICaplinkProfile::kill() {
    this->uGUIBase::kill();
}

void uGUICaplinkProfile::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUICaplinkProfile::updatePtr() {
}

void uGUICaplinkProfile::draw(cDraw* pDraw) {
    this->uGUIBase::draw(pDraw);
}

void uGUICaplinkProfile::setUniqueId(uGUIBase* pParent, MT_CTSTR unique_id) {
    mpParent = pParent;
    if (unique_id != nullptr) {
        if (unique_id != (&mUniqueId.mStr[0])) {
            size_t t0 = strlen(unique_id);
            mUniqueId.mLength = (static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u;
            if (((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u) != 0) {
                memcpy(static_cast<void*>(&mUniqueId.mStr[0]), static_cast<const void*>(unique_id), static_cast<size_t>((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u));
                mUniqueId.mStr[(static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u] = 0;
            } else {
                mUniqueId.mStr[0] = 0;
            }
        }
    } else {
        mUniqueId.mStr[0] = 0;
        mUniqueId.mLength = 0;
    }
}

__attribute__((weak)) void uGUICaplinkProfile::setFlowId(u32 flow_id) {
    DDON_STUB("uGUICaplinkProfile::setFlowId")
    /* stub */
}

void uGUICaplinkProfile::moveInput() {
    if (mFlowId != 5) {
        if ((mFlowId - 3u) <= 1u) {
            if (mpPageCtrl != nullptr) {
                mpPageCtrl->execute();
            }
        }
    } else {
        mGame.mListCtrl.executeCtrl();
        if (mpDecideCtrl != nullptr) {
            mpDecideCtrl->execute();
        }
        if (mpCancelCtrl != nullptr) {
            mpCancelCtrl->execute();
        }
        mMain.mClose.execute();
    }
}

__attribute__((weak)) void uGUICaplinkProfile::moveEvent() {
    DDON_STUB("uGUICaplinkProfile::moveEvent")
    /* stub */
}

void uGUICaplinkProfile::updateMove() {
    switch (mFlowId - 1u) {
        case 0:
        {
            if (sCaplinkManager::getInstance()->mUserProfileGetAns.getStatus() != 0) {
                if (sCaplinkManager::getInstance()->mUserProfileGetAns.getStatus() != 3) {
                    if (sCaplinkManager::getInstance()->mUserProfileGetAns.getStatus() == 2) {
                        mFriendIndex = sCaplinkManager::getInstance()->getFriendIndex(&mUniqueId.mStr[0]);
                        setFlowId(2u);
                    }
                } else {
                    setFlowId(6u);
                }
            } else {
                setFlowId(6u);
            }
            break;
        }
        case 1:
        {
            if (sCaplinkManager::getInstance()->mUserProfileContentListGetAns.getStatus() != 0) {
                if (sCaplinkManager::getInstance()->mUserProfileContentListGetAns.getStatus() == 3) {
                    setFlowId(6u);
                } else {
                    if (sCaplinkManager::getInstance()->mUserProfileContentListGetAns.getStatus() == 2) {
                        setupList();
                        if (mMode != 0) {
                            setFlowId(5u);
                        } else {
                            setFlowId(3u);
                        }
                    }
                }
            } else {
                setFlowId(6u);
            }
            break;
        }
        case 2:
        {
            mMain.mGuide.uGUIBase::cReferenceUIBtnGuide::update();
            mGame.mListCtrl.uGUIBase::cScrollList::update(getDeltaTime());
            mInfo.mProfIcon.update();
            break;
        }
        case 3:
        {
            mMain.mGuide.uGUIBase::cReferenceUIBtnGuide::update();
            mGame.mListCtrl.uGUIBase::cScrollList::update(getDeltaTime());
            mInfo.mProfIcon.update();
            break;
        }
        case 4:
        {
            mMain.mClose.uGUIBase::cReferenceUICloseBtn::update();
            mMain.mGuide.uGUIBase::cReferenceUIBtnGuide::update();
            (&mMain.mButton)->update();
            mGame.mListCtrl.uGUIBase::cScrollList::update(getDeltaTime());
            mInfo.mProfIcon.update();
            break;
        }
        default:
        {
            break;
        }
    }
}

void uGUICaplinkProfile::updateExit() {
    end();
}

__attribute__((weak)) void uGUICaplinkProfile::setupList() {
    DDON_STUB("uGUICaplinkProfile::setupList")
    /* stub */
}

void uGUICaplinkProfile::setupInfo() {
    cGUIObjMessage* t0 = mInfo.mpObjMsgTitle;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 56u), 0u, false);
    cGUIObjMessage* t1 = mInfo.mpObjMsgNameTitle;
    setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 64u), 0u, false);
    cGUIObjMessage* t2 = mInfo.mpObjMsgIdTitle;
    setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 63u), 0u, false);
    cGUIObjMessage* t3 = mInfo.mpObjMsgCommentTitle;
    setObjectMessage(static_cast<cGUIObject*>(t3), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 62u), 0u, false);
    bool t4 = sCaplinkManager::getInstance()->isMyUniqueId(&mUniqueId.mStr[0]);
    sCaplinkManager* t5 = sCaplinkManager::getInstance();
    if (t4) {
        setObjectMessageFit(mInfo.mpObjMsgId, &t5->mMyProfile.mUniqueId.mStr[0], 33ul);
        setObjectMessageFit(mInfo.mpObjMsgComment, &t5->mMyProfile.mComment.mStr[0], 513ul);
        setObjectMessageFit(mInfo.mpObjMsgName, &t5->mMyProfile.mNickname.mStr[0], 81ul);
        mInfo.mProfIcon.request(t5->mMyProfile.mIconIndex);
    } else {
        setObjectMessageFit(mInfo.mpObjMsgId, &t5->mUserProfileGetAns.mUserProfile.mUniqueId[0], 33ul);
        setObjectMessageFit(mInfo.mpObjMsgComment, &t5->mUserProfileGetAns.mUserProfile.mComment[0], 513ul);
        setObjectMessageFit(mInfo.mpObjMsgName, &t5->mUserProfileGetAns.mUserProfile.mNickname[0], 81ul);
        if (t5->mUserProfileGetAns.mUserProfile.mIconNormalUrl[0] != 0) {
            mInfo.mProfIcon.request(sCaplinkManager::getInstance()->getIconIndex(&t5->mUserProfileGetAns.mUserProfile.mIconNormalUrl[0]));
        }
    }
    if (mpPageCtrl != nullptr) {
        mInfo.mDot.setCurrentPos(static_cast<u32>(mpPageCtrl->getCurrentPos()));
    } else {
        mInfo.mDot.setCurrentPos(0u);
    }
}

void uGUICaplinkProfile::setupGame() {
    setPlayingFlow(getFlow(20u), false);
    play(0.0f);
    if (mpPageCtrl != nullptr) {
        s32 t0 = mpPageCtrl->getCurrentPos();
        mGame.mListCtrl.clear();
        mGame.mListCtrl.setListPos(static_cast<u32>(t0 - 1), true);
        if (mGame.mListCtrl.mBar.mpInstance != nullptr) {
            mGame.mListCtrl.mBar.mpInstance->setVisible(false);
        }
        if (mpPageCtrl != nullptr) {
            mInfo.mDot.setCurrentPos(static_cast<u32>(mpPageCtrl->getCurrentPos()));
        } else {
            mInfo.mDot.setCurrentPos(0u);
        }
    } else {
        mGame.mListCtrl.clear();
        mGame.mListCtrl.setListPos(0xFFFFFFFFu, true);
        if (mGame.mListCtrl.mBar.mpInstance != nullptr) {
            mGame.mListCtrl.mBar.mpInstance->setVisible(false);
        }
        if (mpPageCtrl != nullptr) {
            mInfo.mDot.setCurrentPos(static_cast<u32>(mpPageCtrl->getCurrentPos()));
        } else {
            mInfo.mDot.setCurrentPos(0u);
        }
    }
}

__attribute__((weak)) void uGUICaplinkProfile::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUICaplinkProfile::setupListItem")
    /* stub */
}

void uGUICaplinkProfile::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    if (pItemBase == nullptr) {
        return;
    }
    cListItem* pItem = static_cast<cListItem*>(pItemBase);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgTitle), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgCharacter), "", 0u, false);
}

u32 uGUICaplinkProfile::evCtrlDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 4;
    }
    setInputEvent(66u);
    return 1;
}

u32 uGUICaplinkProfile::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUICaplinkProfile::evCtrlClose(cControl::Message* msg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUICaplinkProfile::evCtrlPage(cControl::Message* msg) {
    setInputEvent(76u);
    return 1;
}

u32 uGUICaplinkProfile::evCtrlMouseClick(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 4;
    }
    setInputEvent(66u);
    return 1;
}

inline uGUICaplinkProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkProfile::MyDTI uGUICaplinkProfile::DTI("uGUICaplinkProfile", &::uGUIBase::DTI, 7632ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkProfile::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkProfile::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICaplinkProfile::cListItem::getDTI() const {
    return uGUICaplinkProfile::cListItem::DTI;
}

inline uGUICaplinkProfile::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkProfile::cListItem::MyDTI uGUICaplinkProfile::cListItem::DTI("uGUICaplinkProfile::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 184ul, 0u, 0u);

MtObject* uGUICaplinkProfile::cListItem::MyDTI::newInstance() const {
    return new (16u) uGUICaplinkProfile::cListItem;
}

const MtDTI& uGUICaplinkProfile::cListInfo::getDTI() const {
    return uGUICaplinkProfile::cListInfo::DTI;
}

inline uGUICaplinkProfile::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkProfile::cListInfo::MyDTI uGUICaplinkProfile::cListInfo::DTI("uGUICaplinkProfile::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 832ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkProfile::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkProfile::cListInfo::MyDTI::newInstance")
    return nullptr;
}

