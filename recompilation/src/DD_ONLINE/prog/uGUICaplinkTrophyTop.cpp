// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICaplinkTrophyTop.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cCaplinkContentAchievementListGet.h"
#include "../../XFramework/cCaplinkContentAchievementRelationGet.h"
#include "../../XFramework/cCaplinkContext.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "sCaplinkManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUICaplinkProfile.h"
#include "uGUICaplinkTopMenu.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUICaplinkTrophyTop::getDTI() const {
    return uGUICaplinkTrophyTop::DTI;
}

void* uGUICaplinkTrophyTop::operator new(size_t sz, u32 align) {
    return uGUICaplinkTrophyTop::getAllocator()->memAlloc(sz, align, uGUICaplinkTrophyTop::DTI.getID());
}

uGUICaplinkTrophyTop::~uGUICaplinkTrophyTop() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUICaplinkTrophyTop::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUICaplinkTrophyTop::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CAP_TROPHY_TOP_GUI"), 129u, 1475461726l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CAPLINK_RES_GMD", 0u);
}

__attribute__((weak)) void uGUICaplinkTrophyTop::setup() {
    DDON_STUB("uGUICaplinkTrophyTop::setup")
    /* stub */
}

void uGUICaplinkTrophyTop::kill() {
    this->uGUIBase::kill();
}

void uGUICaplinkTrophyTop::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUICaplinkTrophyTop::updatePtr() {
}

__attribute__((weak)) void uGUICaplinkTrophyTop::setFlowId(u32 flow_id) {
    DDON_STUB("uGUICaplinkTrophyTop::setFlowId")
    /* stub */
}

void uGUICaplinkTrophyTop::moveInput() {
    if (mFlowId != 5) {
        return;
    }
    mMain.mClose.execute();
    if (mpDecideCtrl != nullptr) {
        mpDecideCtrl->execute();
    }
    if (mpCancelCtrl != nullptr) {
        mpCancelCtrl->execute();
    }
    mList.mListCtrl.executeCtrl();
}

__attribute__((weak)) void uGUICaplinkTrophyTop::moveEvent() {
    if (mList.mListCtrl.moveEvent()) {
        return;
    }
    switch (getInputEvent()) {
    case INPUTEVENT_DECIDE:
        if (uGUICaplinkTopMenu* t1 = mpOwner) {
            // workaround
            char* t2 = reinterpret_cast<char*>(&mList.mListCtrl);
            const u32 t3 = *reinterpret_cast<const u32*>(t2 + 0x26c);
            const cListInfo* t4 = static_cast<cListInfo*>(reinterpret_cast<MtTypedArray<cScrollListInfoBase>*>(t2 + 0x110)->at(t3));
            if (t4 != nullptr) {
                const char* t5 = reinterpret_cast<const char*>(&t4->mContentId);
                char* t6 = reinterpret_cast<char*>(t1);
                // workaround
                t6 += 0xb9c;
                if (t6 != t5) {
                    MT_CTSTR t7 = reinterpret_cast<const char*>(t4) + (0x28 + 0x4);
                    char* t8 = t6 + 0x4;
                    const s32 t9 = static_cast<s32>(strlen(t7));
                    const u32 t10 = t9 <= 32 ? t9 : 32;
                    *reinterpret_cast<u32*>(t6) = t10;
                    if (t10 != 0) {
                        memcpy(t8, t7, t10);
                        t8[t10] = 0;
                    } else {
                        *t8 = 0;
                    }
                }
            }
        }
        setFlowId(FLOW_END);
        break;
    case INPUTEVENT_CANCEL:
        if (uGUICaplinkTopMenu* t11 = mpOwner) {
            char* t12 = reinterpret_cast<char*>(t11);
            // workaround
            t12 += 0xb9c;
            char* t13 = t12 + 0x4;
            if (t13 != static_cast<MT_CTSTR>("")) {
                *reinterpret_cast<u32*>(t12) = 0;
                *t13 = 0;
            }
        }
        setFlowId(FLOW_END);
        break;
    }
}

__attribute__((weak)) void uGUICaplinkTrophyTop::updateMove() {
    DDON_STUB("uGUICaplinkTrophyTop::updateMove")
    /* stub */
}

void uGUICaplinkTrophyTop::updateExit() {
    end();
}

__attribute__((weak)) void uGUICaplinkTrophyTop::updateGetAchieveList() {
    DDON_STUB("uGUICaplinkTrophyTop::updateGetAchieveList")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyTop::updateGetAchieveRelation() {
    DDON_STUB("uGUICaplinkTrophyTop::updateGetAchieveRelation")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyTop::setupList() {
    DDON_STUB("uGUICaplinkTrophyTop::setupList")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyTop::setupListItem(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index) {
    DDON_STUB("uGUICaplinkTrophyTop::setupListItem")
    /* stub */
}

void uGUICaplinkTrophyTop::hideListItem(uGUIBase::cScrollListItemBase* pListItem) {
    if (pListItem == nullptr) {
        return;
    }
    cListItem* pItem = static_cast<cListItem*>(pListItem);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgTitle), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgComment), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgNum), "", 0u, false);
    if (pItem->mpInstAnimStamp != nullptr) {
        pItem->mpInstAnimStamp->setVisible(false);
    }
    if (pItem->mpInstAnimLoading != nullptr) {
        pItem->mpInstAnimLoading->setVisible(false);
    }
    pItem->mIcon.clear();
    cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(pListItem->mpInstBase), false);
}

inline void uGUICaplinkTrophyTop::eventCancel() {
    if (mpOwner == nullptr) {
        return;
    }
    if ("" == (&mpOwner->mContentId.mStr[0])) {
        return;
    }
    mpOwner->mContentId.mLength = 0;
    mpOwner->mContentId.mStr[0] = 0;
}

u32 uGUICaplinkTrophyTop::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUICaplinkTrophyTop::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

bool uGUICaplinkTrophyTop::evCtrlScrl(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            mList.mListCtrl.setListPos(false);
            setInputEvent(66u);
            return false;
        }
    }
    return true;
}

inline uGUICaplinkTrophyTop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyTop::MyDTI uGUICaplinkTrophyTop::DTI("uGUICaplinkTrophyTop", &::uGUIBase::DTI, 4544ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkTrophyTop::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkTrophyTop::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICaplinkTrophyTop::cListItem::getDTI() const {
    return uGUICaplinkTrophyTop::cListItem::DTI;
}

uGUICaplinkTrophyTop::cListItem::~cListItem() {
}

inline uGUICaplinkTrophyTop::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyTop::cListItem::MyDTI uGUICaplinkTrophyTop::cListItem::DTI("uGUICaplinkTrophyTop::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 160ul, 0u, 0u);

MtObject* uGUICaplinkTrophyTop::cListItem::MyDTI::newInstance() const {
    return new (16u) uGUICaplinkTrophyTop::cListItem;
}

const MtDTI& uGUICaplinkTrophyTop::cListInfo::getDTI() const {
    return uGUICaplinkTrophyTop::cListInfo::DTI;
}

inline uGUICaplinkTrophyTop::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyTop::cListInfo::MyDTI uGUICaplinkTrophyTop::cListInfo::DTI("uGUICaplinkTrophyTop::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkTrophyTop::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkTrophyTop::cListInfo::MyDTI::newInstance")
    return nullptr;
}

