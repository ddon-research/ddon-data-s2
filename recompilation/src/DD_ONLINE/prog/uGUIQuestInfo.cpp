// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIQuestInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nGUIExt.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIPopDetail01.h"
#include "uGUIPopRmcQuestInfo.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIQuestInfo::getDTI() const {
    return uGUIQuestInfo::DTI;
}

void* uGUIQuestInfo::operator new(size_t sz, u32 align) {
    return uGUIQuestInfo::getAllocator()->memAlloc(sz, align, uGUIQuestInfo::DTI.getID());
}

__attribute__((noinline)) uGUIQuestInfo::~uGUIQuestInfo() {
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIQuestInfo::createProperty(MtPropertyList& s) {
}

bool uGUIQuestInfo::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_QUEST_INFO_GUI"), 129u, 1466062383l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIQuestInfo::setup() {
    DDON_STUB("uGUIQuestInfo::setup")
    /* stub */
}

void uGUIQuestInfo::kill() {
    if (mpPopDetail != nullptr) {
        mpPopDetail->kill();
        mpPopDetail = nullptr;
    }
    if (mpPopBonus != nullptr) {
        mpPopBonus->kill();
        mpPopBonus = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUIQuestInfo::move() {
    this->uGUIBase::move();
}

void uGUIQuestInfo::updatePtr() {
    if (mpPopDetail != nullptr) {
        if (!mpPopDetail->isEnable()) {
            mpPopDetail = nullptr;
        }
    }
    if (mpPopBonus == nullptr) {
        return;
    }
    if (mpPopBonus->isEnable()) {
        return;
    }
    mpPopBonus = nullptr;
}

__attribute__((weak)) void uGUIQuestInfo::setIndexData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("uGUIQuestInfo::setIndexData")
    /* stub */
}

void uGUIQuestInfo::setFocus(bool isFocus) {
    mIsMove = isFocus;
    mQuestInfoResult = 0;
    setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimWindowFrame), isFocus);
}

void uGUIQuestInfo::clearDetail() {
    setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimEmblem), false);
    setObjectMessage(static_cast<cGUIObject*>(mMain.mpObjMsgTitle), "", 0u, false);
    setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimPeriod), false);
    setObjectMessage(static_cast<cGUIObject*>(mMain.mpObjMsgPeriod), "", 0u, false);
    if (mMain.mpObjTexPeriod != nullptr) {
        mMain.mpObjTexPeriod->setVisible(false);
    }
    setInstanceVisible(static_cast<cGUIInstance*>(mDetail.mScrollCtrl.getInstNullScroll()), false);
    if (mDetail.mScrollCtrl.mBar.mpInstance != nullptr) {
        mDetail.mScrollCtrl.mBar.mpInstance->setVisible(false);
    }
    clearFocus();
    mIndexData.resetInfoData();
    mQuestInfoResult = 0;
    mIsCleared = true;
}

void uGUIQuestInfo::adjustScale() {
    float t0 = 1.0f;
    const f32 fScaleRate = getScaleForDefaultResolution(t0);
    cGUIInstNull* t1 = mpInstNullBase;
    if (t1 != nullptr) {
        t1->setScaleX(fScaleRate);
        t1->setScaleY(fScaleRate);
        t1->setScaleZ(fScaleRate);
        f32 t2 = mDispPos.x;
        f32 t3 = mDispPos.y;
        f32 t4 = mDispPos.z;
        mPos.x = t2 * fScaleRate;
        mPos.y = t3 * fScaleRate;
        mPos.z = t4 * fScaleRate;
        mPos.pad_ = 0.0f;
        uGUIPopRmcQuestInfo* t5 = mpPopBonus;
        if (t5 != nullptr) {
            cGUIInstNull* t6 = mMain.mpInstNullBonus;
            MtVector2 frame48(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t6), mPos));
            uGUIPopRmcQuestInfo* t7 = mpPopBonus;
            f32 t8 = frame48.x;
            f32 t9 = frame48.y;
            t7->mPos.x = t8;
            t7->mPos.y = t9;
            t7->mPos.z = 0.0f;
            t7->mPos.pad_ = 0.0f;
            uGUIPopDetail01* t10 = mpPopDetail;
            if (t10 != nullptr) {
                cGUIInstNull* t11 = mMain.mpInstNullDetail;
                MtVector2 frame56(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t11), mPos));
                uGUIPopDetail01* t12 = mpPopDetail;
                f32 t13 = frame56.x;
                f32 t14 = frame56.y;
                t12->mPos.x = t13;
                t12->mPos.y = t14;
                t12->mPos.z = 0.0f;
                t12->mPos.pad_ = 0.0f;
            }
        } else {
            uGUIPopDetail01* t10 = mpPopDetail;
            if (t10 != nullptr) {
                cGUIInstNull* t11 = mMain.mpInstNullDetail;
                MtVector2 frame56(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t11), mPos));
                uGUIPopDetail01* t12 = mpPopDetail;
                f32 t13 = frame56.x;
                f32 t14 = frame56.y;
                t12->mPos.x = t13;
                t12->mPos.y = t14;
                t12->mPos.z = 0.0f;
                t12->mPos.pad_ = 0.0f;
            }
        }
    } else {
        f32 t2 = mDispPos.x;
        f32 t3 = mDispPos.y;
        f32 t4 = mDispPos.z;
        mPos.x = t2 * fScaleRate;
        mPos.y = t3 * fScaleRate;
        mPos.z = t4 * fScaleRate;
        mPos.pad_ = 0.0f;
        uGUIPopRmcQuestInfo* t5 = mpPopBonus;
        if (t5 != nullptr) {
            cGUIInstNull* t6 = mMain.mpInstNullBonus;
            MtVector2 frame48(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t6), mPos));
            uGUIPopRmcQuestInfo* t7 = mpPopBonus;
            f32 t8 = frame48.x;
            f32 t9 = frame48.y;
            t7->mPos.x = t8;
            t7->mPos.y = t9;
            t7->mPos.z = 0.0f;
            t7->mPos.pad_ = 0.0f;
            uGUIPopDetail01* t10 = mpPopDetail;
            if (t10 != nullptr) {
                cGUIInstNull* t11 = mMain.mpInstNullDetail;
                MtVector2 frame56(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t11), mPos));
                uGUIPopDetail01* t12 = mpPopDetail;
                f32 t13 = frame56.x;
                f32 t14 = frame56.y;
                t12->mPos.x = t13;
                t12->mPos.y = t14;
                t12->mPos.z = 0.0f;
                t12->mPos.pad_ = 0.0f;
            }
        } else {
            uGUIPopDetail01* t10 = mpPopDetail;
            if (t10 != nullptr) {
                cGUIInstNull* t11 = mMain.mpInstNullDetail;
                MtVector2 frame56(uGUIBase::getInstanceScreenPos(static_cast<cGUIInstance*>(t11), mPos));
                uGUIPopDetail01* t12 = mpPopDetail;
                f32 t13 = frame56.x;
                f32 t14 = frame56.y;
                t12->mPos.x = t13;
                t12->mPos.y = t14;
                t12->mPos.z = 0.0f;
                t12->mPos.pad_ = 0.0f;
            }
        }
    }
}

__attribute__((weak)) void uGUIQuestInfo::setFlowId(u32 flow_id) {
    DDON_STUB("uGUIQuestInfo::setFlowId")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::moveInput() {
    DDON_STUB("uGUIQuestInfo::moveInput")
    /* stub */
}

void uGUIQuestInfo::moveEvent() {
    if (getInputEvent() != 68) {
        if (getInputEvent() == 67) {
            if (mFlowId == 2) {
                if (mIsWaitOrderProgress) {
                    mIsWaitOrderProgress = false;
                    sQuestManagerExt* t0 = sQuestManagerExt::getInstance();
                    t0->cancelReqQuestOrder(mIndexData.getScheduleId());
                    mIsMove = false;
                    setFlowId(1u);
                    mQuestInfoResult = 2;
                    clearFocus();
                } else {
                    mIsMove = false;
                    setFlowId(1u);
                    mQuestInfoResult = 2;
                    clearFocus();
                }
            }
        } else {
            if (getInputEvent() == 66) {
                eventDecide();
            }
        }
    } else {
        if (mFlowId == 2) {
            adjustCursor();
        }
    }
}

__attribute__((weak)) void uGUIQuestInfo::updateMove() {
    DDON_STUB("uGUIQuestInfo::updateMove")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::updateExit() {
    DDON_STUB("uGUIQuestInfo::updateExit")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::setupDetail() {
    DDON_STUB("uGUIQuestInfo::setupDetail")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::addInfo(cGUIInstance* pInst, cGUIObject* pObj, s32& list_pos, s32& length, bool isReward) {
    DDON_STUB("uGUIQuestInfo::addInfo")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::setupItemIcon(u32& count, u32 id, u32 num, bool isRandom, bool isOffset) {
    DDON_STUB("uGUIQuestInfo::setupItemIcon")
    /* stub */
}

void uGUIQuestInfo::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    if (pItemBase == nullptr) {
        return;
    }
    if (pInfoBase == nullptr) {
        return;
    }
    cListInfo* pInfo = static_cast<cListInfo*>(pInfoBase);
    pItemBase->mpObjPointerTarget = pInfo->mpObjPointerTarget;
    pItemBase->mpInstPointerTarget = pInfo->mpInstPointerTarget;
}

__attribute__((weak)) void uGUIQuestInfo::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
}

__attribute__((weak)) void uGUIQuestInfo::order() {
    DDON_STUB("uGUIQuestInfo::order")
    /* stub */
}

void uGUIQuestInfo::cancelInfo() {
    mIsMove = false;
    setFlowId(1u);
    mQuestInfoResult = 2;
    clearFocus();
}

__attribute__((weak)) void uGUIQuestInfo::adjustCursor() {
    DDON_STUB("uGUIQuestInfo::adjustCursor")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::clearFocus() {
    mDetail.mReward.mReward[0].mIcon.uGUIBase::cReferenceUIIconItem::setFocus(false);
    mDetail.mReward.mReward[1].mIcon.uGUIBase::cReferenceUIIconItem::setFocus(false);
    mDetail.mReward.mReward[2].mIcon.uGUIBase::cReferenceUIIconItem::setFocus(false);
    mDetail.mReward.mReward[3].mIcon.uGUIBase::cReferenceUIIconItem::setFocus(false);
    mDetail.mReward.mReward[4].mIcon.uGUIBase::cReferenceUIIconItem::setFocus(false);
    (&mMain.mBtnYes)->setFocus(false);
    mMain.mBtnNo.uGUIBase::cReferenceUIButton::setFocus(false);
    if (mDetail.mScrollCtrl.mpOwner != nullptr) {
        mDetail.mScrollCtrl.mIsAutoDispPointer = false;
        mDetail.mScrollCtrl.mPointerPrio = mDetail.mScrollCtrl.mpOwner->getBasePointerPriority();
    } else {
        mDetail.mScrollCtrl.mIsAutoDispPointer = false;
        mDetail.mScrollCtrl.mPointerPrio = 10;
    }
}

__attribute__((weak)) void uGUIQuestInfo::setupItemDetail(u32 item_id) {
    DDON_STUB("uGUIQuestInfo::setupItemDetail")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::updateItemDetail() {
    DDON_STUB("uGUIQuestInfo::updateItemDetail")
    /* stub */
}

__attribute__((weak)) void uGUIQuestInfo::eventDecide() {
    if (mFlowId != 2) {
        return;
    }
    if (mIsWaitOrderProgress) {
        return;
    }
    mIsWaitOrderProgress = true;
    sQuestManagerExt* t0 = sQuestManagerExt::getInstance();
    t0->reqQuestOrder(mIndexData.getScheduleId());
    sQuestManagerExt* t2 = sQuestManagerExt::getInstance();
    bool t3 = t2->isQuestOrderProgress(mIndexData.getScheduleId());
    if (!t3) {
        return;
    }
    order();
    mIsWaitOrderProgress = false;
}

__attribute__((weak)) u32 uGUIQuestInfo::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIQuestInfo::evCtrlDecide")
    return {};
}

u32 uGUIQuestInfo::evCtrlCancel(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 0;
        if (mFlowId == 2) {
            msg->changeSE = 5;
            setInputEvent(67u);
            return 1;
        }
    } else {
        if (mFlowId == 2) {
            setInputEvent(67u);
            return 1;
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUIQuestInfo::evCtrlAdjustCursor(cControl::Message* msg) {
    DDON_STUB("uGUIQuestInfo::evCtrlAdjustCursor")
    return {};
}

__attribute__((weak)) u32 uGUIQuestInfo::evCtrlMouseClick(cControl::Message* msg) {
    DDON_STUB("uGUIQuestInfo::evCtrlMouseClick")
    return {};
}

inline uGUIQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuestInfo::MyDTI uGUIQuestInfo::DTI("uGUIQuestInfo", &::uGUIBase::DTI, 8032ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuestInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuestInfo::MyDTI::newInstance")
    return nullptr;
}

uGUIQuestInfo::stDetail::stDetail() {
    DDON_STUB("uGUIQuestInfo::stDetail::stDetail")
    /* stub */
}

const MtDTI& uGUIQuestInfo::cRewardItem::getDTI() const {
    return uGUIQuestInfo::cRewardItem::DTI;
}

inline uGUIQuestInfo::cRewardItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuestInfo::cRewardItem::MyDTI uGUIQuestInfo::cRewardItem::DTI("uGUIQuestInfo::cRewardItem", &::uGUIBase::cScrollListItemBase::DTI, 2096ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuestInfo::cRewardItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuestInfo::cRewardItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIQuestInfo::cListInfo::getDTI() const {
    return uGUIQuestInfo::cListInfo::DTI;
}

__attribute__((weak)) void uGUIQuestInfo::cListInfo::addMouseTouchList(cControl* pCtrl, s32 pos) {
    DDON_STUB("uGUIQuestInfo::cListInfo::addMouseTouchList")
    /* stub */
}

inline uGUIQuestInfo::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuestInfo::cListInfo::MyDTI uGUIQuestInfo::cListInfo::DTI("uGUIQuestInfo::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuestInfo::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuestInfo::cListInfo::MyDTI::newInstance")
    return nullptr;
}

