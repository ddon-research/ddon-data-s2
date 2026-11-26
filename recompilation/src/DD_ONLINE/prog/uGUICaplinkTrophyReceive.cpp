// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICaplinkTrophyReceive.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUICaplinkProfile.h"
#include "uGUICaplinkTopMenu.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUICaplinkTrophyReceive::getDTI() const {
    return uGUICaplinkTrophyReceive::DTI;
}

inline MtAllocator* uGUICaplinkTrophyReceive::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUICaplinkTrophyReceive::DTI);
}

void* uGUICaplinkTrophyReceive::operator new(size_t sz, u32 align) {
    return uGUICaplinkTrophyReceive::getAllocator()->memAlloc(sz, align, uGUICaplinkTrophyReceive::DTI.getID());
}

inline void uGUICaplinkTrophyReceive::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICaplinkTrophyReceive::DTI)->memFree(p_addr);
}

uGUICaplinkTrophyReceive::~uGUICaplinkTrophyReceive() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUICaplinkTrophyReceive::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUICaplinkTrophyReceive::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CAP_TROPHY_DETAIL_GUI"), 129u, 1456988741l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CAPLINK_RES_GMD", 0u);
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setup() {
    DDON_STUB("uGUICaplinkTrophyReceive::setup")
    /* stub */
}

void uGUICaplinkTrophyReceive::kill() {
    if (mpSystemMsg != nullptr) {
        mpSystemMsg->mEndType = 0;
        mpSystemMsg->end();
    }
    mpSystemMsg = nullptr;
    static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
    this->uGUIBase::kill();
}

void uGUICaplinkTrophyReceive::move() {
    this->uGUIBase::move();
}

void uGUICaplinkTrophyReceive::updatePtr() {
    if (mpSystemMsg == nullptr) {
        return;
    }
    if (mpSystemMsg->isEnable()) {
        return;
    }
    mpSystemMsg = nullptr;
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setFlowId(u32 flow_id, bool is_init) {
    DDON_STUB("uGUICaplinkTrophyReceive::setFlowId")
    /* stub */
}

void uGUICaplinkTrophyReceive::moveInput() {
    if ((mFlowId & 0xFFFFFFFEu) != 2) {
        return;
    }
    mMain.mClose.execute();
    if (mpDecideCtrl != nullptr) {
        mpDecideCtrl->execute();
    }
    if (mpCancelCtrl != nullptr) {
        mpCancelCtrl->execute();
    }
    if (mpButtonCtrl != nullptr) {
        mpButtonCtrl->execute();
    }
    mList.mListCtrl.executeCtrl();
}

void uGUICaplinkTrophyReceive::moveEvent() {
    if (mList.mListCtrl.moveEvent()) {
        if (mFlowId == 2) {
            setupDetail();
        }
    } else {
        if (getInputEvent() != 68) {
            if (getInputEvent() == 67) {
                if (mFlowId == 3) {
                    setFlowId(2u, false);
                } else {
                    if (mFlowId == 2) {
                        setFlowId(6u, false);
                    }
                }
            } else {
                if (getInputEvent() == 66) {
                    if (mFlowId == 3) {
                        setFlowId(4u, false);
                    } else {
                        if (mFlowId == 2) {
                            setFlowId(3u, false);
                        }
                    }
                }
            }
        } else {
            setFlowId(6u, false);
        }
    }
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::updateMove() {
    DDON_STUB("uGUICaplinkTrophyReceive::updateMove")
    /* stub */
}

void uGUICaplinkTrophyReceive::updateExit() {
    end();
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupCompleteNum() {
    DDON_STUB("uGUICaplinkTrophyReceive::setupCompleteNum")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupList() {
    DDON_STUB("uGUICaplinkTrophyReceive::setupList")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupDetail() {
    DDON_STUB("uGUICaplinkTrophyReceive::setupDetail")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupListItem(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index) {
    DDON_STUB("uGUICaplinkTrophyReceive::setupListItem")
    /* stub */
}

void uGUICaplinkTrophyReceive::hideListItem(uGUIBase::cScrollListItemBase* pListItem) {
    if (pListItem == nullptr) {
        return;
    }
    cListItem* pItem = static_cast<cListItem*>(pListItem);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgTrophyName), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgStatus), "", 0u, false);
    if (pItem->mpInstAnimStatusIcon != nullptr) {
        pItem->mpInstAnimStatusIcon->setVisible(false);
    }
    (&pItem->mItemIcon[0])->setVisible(false);
    (&pItem->mItemIcon[1])->setVisible(false);
    (&pItem->mItemIcon[2])->setVisible(false);
    cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(pListItem->mpInstBase), false);
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupConfirm() {
    DDON_STUB("uGUICaplinkTrophyReceive::setupConfirm")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::updateConfirm() {
    DDON_STUB("uGUICaplinkTrophyReceive::updateConfirm")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkTrophyReceive::setupNotice() {
    DDON_STUB("uGUICaplinkTrophyReceive::setupNotice")
    /* stub */
}

u32 uGUICaplinkTrophyReceive::evCtrlDecide(cControl::Message* msg) {
    if (mpOwner != nullptr) {
        if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
            if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                const cCaptrophyRelationData* pData = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                if (pData != nullptr) {
                    if (mFlowId == 3) {
                        if (pData->mTrophy.mComplete == 1) {
                            setInputEvent(66u);
                            return 1;
                        }
                    } else {
                        if (mFlowId == 2) {
                            if (pData->mTrophy.mReceive == 0) {
                                setInputEvent(66u);
                                return 1;
                            }
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

u32 uGUICaplinkTrophyReceive::evCtrlCancel(cControl::Message* msg) {
    if ((mFlowId & 0xFFFFFFFEu) == 2) {
        setInputEvent(67u);
    }
    return 0;
}

u32 uGUICaplinkTrophyReceive::evCtrlClose(cControl::Message* msg) {
    if ((mFlowId & 0xFFFFFFFEu) == 2) {
        setInputEvent(68u);
    }
    return 0;
}

u32 uGUICaplinkTrophyReceive::evCtrlButton(cControl::Message* msg) {
    if (mFlowId != 3) {
        if (mFlowId == 2) {
            setFlowId(3u, false);
            if (mpOwner != nullptr) {
                if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
                    if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                        cCaptrophyRelationData* t0 = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                        if (t0 != nullptr) {
                            if (mFlowId == 3) {
                                if (t0->mTrophy.mComplete == 1) {
                                    setInputEvent(66u);
                                    return 1;
                                }
                            } else {
                                if (mFlowId == 2) {
                                    if (t0->mTrophy.mReceive == 0) {
                                        setInputEvent(66u);
                                        return 1;
                                    }
                                }
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    } else {
        if (mpOwner != nullptr) {
            if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
                if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                    cCaptrophyRelationData* t0 = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                    if (t0 != nullptr) {
                        if (mFlowId == 3) {
                            if (t0->mTrophy.mComplete == 1) {
                                setInputEvent(66u);
                                return 1;
                            }
                        } else {
                            if (mFlowId == 2) {
                                if (t0->mTrophy.mReceive == 0) {
                                    setInputEvent(66u);
                                    return 1;
                                }
                            }
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

bool uGUICaplinkTrophyReceive::evCtrlScrl(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_MCLICK) {
            if (mFlowId == 3) {
                setFlowId(2u, false);
            }
            return true;
        } else {
            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                if (mFlowId == 3) {
                    setFlowId(2u, false);
                    mList.mListCtrl.setListPos(false);
                    if (mFlowId == 2) {
                        setupDetail();
                    }
                    if (mpOwner != nullptr) {
                        if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
                            if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                                cCaptrophyRelationData* t0 = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                                if (t0 != nullptr) {
                                    if (mFlowId == 3) {
                                        if (t0->mTrophy.mComplete == 1) {
                                            setInputEvent(66u);
                                        }
                                    } else {
                                        if (mFlowId == 2) {
                                            if (t0->mTrophy.mReceive == 0) {
                                                setInputEvent(66u);
                                            }
                                        }
                                    }
                                }
                                return false;
                            }
                        }
                    }
                    return false;
                } else {
                    if (mFlowId == 2) {
                        mList.mListCtrl.setListPos(false);
                        if (mFlowId == 2) {
                            setupDetail();
                        }
                        if (mpOwner != nullptr) {
                            if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
                                if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                                    cCaptrophyRelationData* t1 = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                                    if (t1 != nullptr) {
                                        if (mFlowId == 3) {
                                            if (t1->mTrophy.mComplete == 1) {
                                                setInputEvent(66u);
                                            }
                                        } else {
                                            if (mFlowId == 2) {
                                                if (t1->mTrophy.mReceive == 0) {
                                                    setInputEvent(66u);
                                                }
                                            }
                                        }
                                    }
                                    return false;
                                }
                            }
                        }
                        return false;
                    } else {
                        return true;
                    }
                }
            } else {
                return true;
            }
        }
    } else {
        return true;
    }
}

__attribute__((weak)) bool uGUICaplinkTrophyReceive::requestReceiveReward() {
    DDON_STUB("uGUICaplinkTrophyReceive::requestReceiveReward")
    return {};
}

void uGUICaplinkTrophyReceive::callbackReceiveReward() {
    if (mpOwner != nullptr) {
        if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
            if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                cCaptrophyRelationData* pData = mpOwner->getCaptrophyRelationData(reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 2272))), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)));
                if (pData != nullptr) {
                    pData->mTrophy.mReceive = 1;
                }
                mRequestFlag = mRequestFlag & 0xFFFFFFFEu;
                setFlowId(mFlowIdNext, false);
            } else {
                mRequestFlag = mRequestFlag & 0xFFFFFFFEu;
                setFlowId(mFlowIdNext, false);
            }
        } else {
            mRequestFlag = mRequestFlag & 0xFFFFFFFEu;
            setFlowId(mFlowIdNext, false);
        }
    } else {
        mRequestFlag = mRequestFlag & 0xFFFFFFFEu;
        setFlowId(mFlowIdNext, false);
    }
}

inline uGUICaplinkTrophyReceive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyReceive::MyDTI uGUICaplinkTrophyReceive::DTI("uGUICaplinkTrophyReceive", &::uGUIBase::DTI, 16864ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkTrophyReceive::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkTrophyReceive::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICaplinkTrophyReceive::cListItem::getDTI() const {
    return uGUICaplinkTrophyReceive::cListItem::DTI;
}

inline void uGUICaplinkTrophyReceive::cListItem::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICaplinkTrophyReceive::cListItem::DTI)->memFree(p_addr);
}

uGUICaplinkTrophyReceive::cListItem::~cListItem() {
}

inline uGUICaplinkTrophyReceive::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyReceive::cListItem::MyDTI uGUICaplinkTrophyReceive::cListItem::DTI("uGUICaplinkTrophyReceive::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 1280ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkTrophyReceive::cListItem::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkTrophyReceive::cListItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICaplinkTrophyReceive::cListInfo::getDTI() const {
    return uGUICaplinkTrophyReceive::cListInfo::DTI;
}

inline void uGUICaplinkTrophyReceive::cListInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICaplinkTrophyReceive::cListInfo::DTI)->memFree(p_addr);
}

inline uGUICaplinkTrophyReceive::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkTrophyReceive::cListInfo::MyDTI uGUICaplinkTrophyReceive::cListInfo::DTI("uGUICaplinkTrophyReceive::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkTrophyReceive::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkTrophyReceive::cListInfo::MyDTI::newInstance")
    return nullptr;
}

