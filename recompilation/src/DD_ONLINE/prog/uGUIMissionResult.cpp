// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMissionResult.h"
#include "Protocol/PacketData/Common.h"
#include "../../generated/shared/GpCourseEffect.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sMain.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIPopDetail01.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMissionResult::getDTI() const {
    return uGUIMissionResult::DTI;
}

void* uGUIMissionResult::operator new(size_t sz, u32 align) {
    return uGUIMissionResult::getAllocator()->memAlloc(sz, align, uGUIMissionResult::DTI.getID());
}

__attribute__((noinline)) uGUIMissionResult::~uGUIMissionResult() {
    DDON_STUB("uGUIMissionResult::~uGUIMissionResult")
    /* stub */
}

bool uGUIMissionResult::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MISSION_RESULT_GUI"), 129u, 1442307639l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_MISSIONRESULT_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIMissionResult::setup() {
    DDON_STUB("uGUIMissionResult::setup")
    /* stub */
}

void uGUIMissionResult::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    if (mpGUIPopDetail != nullptr) {
        mpGUIPopDetail->kill();
        mpGUIPopDetail = nullptr;
    }
    if (mResultData.mResPointList.mLength != 0) {
        u32 v0_0 = mResultData.mResPointList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mResultData.mResPointList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mResultData.mResPointList.mpArray[i0_3];
                v1_0 = mResultData.mResPointList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mResultData.mResPointList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResultData.mResPointList.mpArray));
    }
    mResultData.mResPointList.mpArray = nullptr;
    mResultData.mResPointList.mBufsiz = 0;
    mResultData.mResPointList.mLength = 0;
    if (mResultData.mRewardList.mLength != 0) {
        u32 v3_0 = mResultData.mRewardList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mResultData.mRewardList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mResultData.mRewardList.mpArray[i3_3];
                v4_0 = mResultData.mRewardList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mResultData.mRewardList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResultData.mRewardList.mpArray));
    }
    mResultData.mRewardList.mpArray = nullptr;
    mResultData.mRewardList.mBufsiz = 0;
    mResultData.mRewardList.mLength = 0;
    if (mChargeEffectEnableList.mLength != 0) {
        u32 v6_0 = mChargeEffectEnableList.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mChargeEffectEnableList.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mChargeEffectEnableList.mpArray[i6_3];
                v7_0 = mChargeEffectEnableList.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChargeEffectEnableList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mChargeEffectEnableList.mpArray));
    }
    mChargeEffectEnableList.mpArray = nullptr;
    mChargeEffectEnableList.mBufsiz = 0;
    mChargeEffectEnableList.mLength = 0;
}

__attribute__((weak)) void uGUIMissionResult::move() {
    DDON_STUB("uGUIMissionResult::move")
    /* stub */
}

void uGUIMissionResult::updatePtr() {
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mpGUIPopDetail == nullptr) {
        return;
    }
    if (mpGUIPopDetail->isEnable()) {
        return;
    }
    mpGUIPopDetail = nullptr;
}

__attribute__((weak)) void uGUIMissionResult::updateInit() {
    DDON_STUB("uGUIMissionResult::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateWaitRwdDialog() {
    DDON_STUB("uGUIMissionResult::updateWaitRwdDialog")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateRewardWait() {
    DDON_STUB("uGUIMissionResult::updateRewardWait")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateScoreWait() {
    DDON_STUB("uGUIMissionResult::updateScoreWait")
    /* stub */
}

void uGUIMissionResult::updateExit() {
    end();
}

__attribute__((weak)) void uGUIMissionResult::moveInput() {
    DDON_STUB("uGUIMissionResult::moveInput")
    /* stub */
}

void uGUIMissionResult::moveEvent() {
    switch (getInputEvent() - 52u) {
        case 0:
        {
            if (mpVLCmnCtrl != nullptr) {
                if (mNowTab == 1) {
                    mpVLCmnCtrl->setCurrentPos(0, false);
                    updateDisp();
                } else {
                    updateDisp();
                }
            } else {
                updateDisp();
            }
            break;
        }
        case 1:
        {
            if (mpVLCmnCtrl != nullptr) {
                if (mNowTab == 1) {
                    mpVLCmnCtrl->setCurrentPos(0, false);
                    updateDisp();
                } else {
                    updateDisp();
                }
            } else {
                updateDisp();
            }
            break;
        }
        case 14:
        {
            setControl();
            updateDisp();
            break;
        }
        case 15:
        {
            setControl();
            updateDisp();
            break;
        }
        case 16:
        {
            if (mpVLCmnCtrl != nullptr) {
                if (mNowTab == 1) {
                    mpVLCmnCtrl->setCurrentPos(0, false);
                    updateDisp();
                } else {
                    updateDisp();
                }
            } else {
                updateDisp();
            }
            break;
        }
        case 17:
        {
            updateDisp();
            break;
        }
        case 18:
        {
            evTabMove();
            break;
        }
        case 19:
        {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMissionResult::updateExit);
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void uGUIMissionResult::evTabMove() {
    DDON_STUB("uGUIMissionResult::evTabMove")
    /* stub */
}

u32 uGUIMissionResult::evVLCtrlMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 1;
}

__attribute__((weak)) u32 uGUIMissionResult::evVLCtrlToFinish(cControl::Message* msg) {
    DDON_STUB("uGUIMissionResult::evVLCtrlToFinish")
    return {};
}

u32 uGUIMissionResult::evHLPageMove(cControl::Message* msg) {
    if (mNowTab == 1) {
        setInputEvent(68u);
        return 1;
    } else {
        return 0;
    }
}

u32 uGUIMissionResult::evHLItemMove(cControl::Message* msg) {
    if (mNowTab == 0) {
        if (mpVLCmnCtrl != nullptr) {
            if (mpVLCmnCtrl->getCurrentPos() != 1) {
                if (mpVLCmnCtrl->getCurrentPos() == 0) {
                    setInputEvent(69u);
                    return 1;
                } else {
                    return 0;
                }
            } else {
                setInputEvent(69u);
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 uGUIMissionResult::evHLItemMoveMouse(cControl::Message* msg) {
    DDON_STUB("uGUIMissionResult::evHLItemMoveMouse")
    return {};
}

u32 uGUIMissionResult::evFinishCtrlExit(cControl::Message* msg) {
    setInputEvent(71u);
    return 0;
}

u32 uGUIMissionResult::evCtrlTabMove(cControl::Message* msg) {
    setInputEvent(70u);
    return 1;
}

__attribute__((weak)) void uGUIMissionResult::updateDisp() {
    DDON_STUB("uGUIMissionResult::updateDisp")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateRewardItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIMissionResult::updateRewardItemDisp")
    /* stub */
}

void uGUIMissionResult::updateRewardItemHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    if (pDispItem->mpInstBase == nullptr) {
        return;
    }
    pDispItem->mpInstBase->setVisible(false);
    pDispItem->mpInstBase->setExecute(false);
}

__attribute__((weak)) void uGUIMissionResult::updateCursor() {
    DDON_STUB("uGUIMissionResult::updateCursor")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateRewardTabCursor() {
    DDON_STUB("uGUIMissionResult::updateRewardTabCursor")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::updateDetail() {
    DDON_STUB("uGUIMissionResult::updateDetail")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::showDetail(u32 itemID) {
    DDON_STUB("uGUIMissionResult::showDetail")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::setupResultData() {
    DDON_STUB("uGUIMissionResult::setupResultData")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::addPointList(MtString name, MtString num, MtString numClass, MtString pt, MtString ptClass) {
    DDON_STUB("uGUIMissionResult::addPointList")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::initResultWindow() {
    DDON_STUB("uGUIMissionResult::initResultWindow")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::initResultController() {
    DDON_STUB("uGUIMissionResult::initResultController")
    /* stub */
}

void uGUIMissionResult::setRewardTab() {
    mTab.uGUIBase::cReferenceUITab::setFocus(0u, true, true);
    setPlayingFlow(getFlow(3u), true);
    setCommon();
    mpVLCmnCtrl->resetItemNum(3, static_cast<const u32*>(nullptr), 0);
    mpVLCmnCtrl->setCurrentPos(0, false);
    if (mpHLReward != nullptr) {
        mpHLReward->setCurrentPos(0, false);
    }
    setControl();
    mScrollList.setFocus(true);
    if (mResultData.mIsDestTarget) {
        if (mResultScrollItem[1].mpInstBase != nullptr) {
            mResultScrollItem[1].mpInstBase->setVisible(true);
        }
    }
    if (mScore.mpInst != nullptr) {
        mScore.mpInst->setSequenceId(0xF4241u);
    }
    u32 itemNum = mResultData.mRewardList.mLength;
    cReferenceUIIconItem* p0_3 = &mRewardIcon[0];
    for (unsigned int i0_11 = 0; i0_11 != 8; p0_3 += 1, i0_11 = i0_11 + 1u) {
        if (i0_11 < itemNum) {
            rItemList::rItemParam* t1 = sItemManager::getInstance()->getItemParam(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mResultData.mRewardList.getBuffer()[i0_11]) + 8));
            if (t1 != nullptr) {
                p0_3->setIconFromParam(t1);
                p0_3->setNum(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mResultData.mRewardList.getBuffer()[i0_11]) + 12));
                if (p0_3->mpInstances.elems[1] != nullptr) {
                    p0_3->mpInstances.elems[1]->cGUIInstance::setVisible(true);
                }
                if (p0_3->mpInstances.elems[0] != nullptr) {
                    p0_3->mpInstances.elems[0]->cGUIInstance::setVisible(true);
                }
                if (p0_3->mpInstances.elems[2] != nullptr) {
                    p0_3->mpInstances.elems[2]->cGUIInstance::setVisible(true);
                }
                p0_3->setVisible(true);
                p0_3->setExecuteTree(true, 3u);
            } else {
                p0_3->setEmpty();
                p0_3->setVisible(false);
                p0_3->setExecuteTree(false, 3u);
            }
        } else {
            p0_3->setEmpty();
            p0_3->setVisible(false);
            p0_3->setExecuteTree(false, 3u);
        }
    }
    cReferenceUIIconItem* p2_3 = &mRewardDestIcon[0];
    itemNum = mResultData.mDestRewardList.mLength;
    for (unsigned int i2_11 = 0; i2_11 != 8; p2_3 += 1, i2_11 = i2_11 + 1u) {
        if (i2_11 < itemNum) {
            rItemList::rItemParam* t8 = sItemManager::getInstance()->getItemParam(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mResultData.mDestRewardList.getBuffer()[i2_11]) + 8));
            if (t8 != nullptr) {
                p2_3->setIconFromParam(t8);
                p2_3->setNum(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mResultData.mDestRewardList.getBuffer()[i2_11]) + 12));
                if (p2_3->mpInstances.elems[1] != nullptr) {
                    p2_3->mpInstances.elems[1]->cGUIInstance::setVisible(true);
                }
                if (p2_3->mpInstances.elems[0] != nullptr) {
                    p2_3->mpInstances.elems[0]->cGUIInstance::setVisible(true);
                }
                if (p2_3->mpInstances.elems[2] != nullptr) {
                    p2_3->mpInstances.elems[2]->cGUIInstance::setVisible(true);
                }
                p2_3->setVisible(true);
                p2_3->setExecuteTree(true, 3u);
            } else {
                p2_3->setEmpty();
                p2_3->setVisible(false);
                p2_3->setExecuteTree(false, 3u);
            }
        } else {
            p2_3->setEmpty();
            p2_3->setVisible(false);
            p2_3->setExecuteTree(false, 3u);
        }
    }
    const u32 enableEffectNum = mChargeEffectEnableList.mLength;
    if (enableEffectNum != 0) {
        for (unsigned int i4_3 = 0;;) {
            MtObject* t15 = mChargeEffectEnableList.getBuffer()[static_cast<int>(i4_3)];
            mResultData.mIsCharge = true;
            mCharge.addData(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t15) + 12), 96u, static_cast<MT_CTSTR>(nullptr));
            if (enableEffectNum != (i4_3 + 1u)) {
                i4_3 += 1u;
            } else {
                break;
            }
        }
        if (mCharge.mpInstance != nullptr) {
            mCharge.mpInstance->setVisible(true);
        }
    }
    mCloseButton.execute();
    updateDisp();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMissionResult::updateRewardWait);
}

void uGUIMissionResult::setScoreTab() {
    mTab.uGUIBase::cReferenceUITab::setFocus(1u, true, true);
    setPlayingFlow(getFlow(5u), true);
    setCommon();
    mpVLCmnCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), 0);
    mpVLCmnCtrl->setCurrentPos(0, false);
    setControl();
    if (mScore.mpInst != nullptr) {
        if (isRanking()) {
            mScore.mpInst->setSequenceId(0xF4243u);
        } else {
            mScore.mpInst->setSequenceId(0xF4241u);
        }
    }
    mCloseButton.execute();
    updateDisp();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMissionResult::updateScoreWait);
}

__attribute__((weak)) void uGUIMissionResult::setCommon() {
    DDON_STUB("uGUIMissionResult::setCommon")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::setControl() {
    DDON_STUB("uGUIMissionResult::setControl")
    /* stub */
}

__attribute__((weak)) void uGUIMissionResult::setChargeEffect() {
    DDON_STUB("uGUIMissionResult::setChargeEffect")
    /* stub */
}

inline uGUIMissionResult::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::MyDTI uGUIMissionResult::DTI("uGUIMissionResult", &::uGUIBase::DTI, 11488ul, 0u, 0u);

alignas(4) unsigned char uGUIMissionResult_mChargeEffectTable_bytes[12] __asm__("_ZN17uGUIMissionResult18mChargeEffectTableE") = {0x18, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* uGUIMissionResult::MyDTI::newInstance() const {
    DDON_STUB("uGUIMissionResult::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMissionResult::cChargeEffectInfo::getDTI() const {
    return uGUIMissionResult::cChargeEffectInfo::DTI;
}

inline uGUIMissionResult::cChargeEffectInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::cChargeEffectInfo::MyDTI uGUIMissionResult::cChargeEffectInfo::DTI("uGUIMissionResult::cChargeEffectInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uGUIMissionResult::cChargeEffectInfo::MyDTI::newInstance() const {
    return new (16u) uGUIMissionResult::cChargeEffectInfo;
}

uGUIMissionResult::stResultData::stResultData() {
    DDON_STUB("uGUIMissionResult::stResultData::stResultData")
    /* stub */
}

const MtDTI& uGUIMissionResult::cPointList::getDTI() const {
    return uGUIMissionResult::cPointList::DTI;
}

__attribute__((noinline)) uGUIMissionResult::cPointList::~cPointList() {
    DDON_STUB("uGUIMissionResult::cPointList::~cPointList")
    /* stub */
}

inline uGUIMissionResult::cPointList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::cPointList::MyDTI uGUIMissionResult::cPointList::DTI("uGUIMissionResult::cPointList", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* uGUIMissionResult::cPointList::MyDTI::newInstance() const {
    return new (16u) uGUIMissionResult::cPointList;
}

const MtDTI& uGUIMissionResult::cItemList::getDTI() const {
    return uGUIMissionResult::cItemList::DTI;
}

inline uGUIMissionResult::cItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::cItemList::MyDTI uGUIMissionResult::cItemList::DTI("uGUIMissionResult::cItemList", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uGUIMissionResult::cItemList::MyDTI::newInstance() const {
    return new (16u) uGUIMissionResult::cItemList;
}

const MtDTI& uGUIMissionResult::cResultScrollItem::getDTI() const {
    return uGUIMissionResult::cResultScrollItem::DTI;
}

inline uGUIMissionResult::cResultScrollItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::cResultScrollItem::MyDTI uGUIMissionResult::cResultScrollItem::DTI("uGUIMissionResult::cResultScrollItem", &::uGUIBase::cScrollListItemBase::DTI, 104ul, 0u, 0u);

MtObject* uGUIMissionResult::cResultScrollItem::MyDTI::newInstance() const {
    return new (16u) uGUIMissionResult::cResultScrollItem;
}

const MtDTI& uGUIMissionResult::cResultScrollInfo::getDTI() const {
    return uGUIMissionResult::cResultScrollInfo::DTI;
}

inline uGUIMissionResult::cResultScrollInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMissionResult::cResultScrollInfo::MyDTI uGUIMissionResult::cResultScrollInfo::DTI("uGUIMissionResult::cResultScrollInfo", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMissionResult::cResultScrollInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMissionResult::cResultScrollInfo::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIMissionResult::cChargeEffectInfo>::~MtTypedArray();

template MtTypedArray<uGUIMissionResult::cItemList>::~MtTypedArray();

template MtTypedArray<uGUIMissionResult::cPointList>::~MtTypedArray();

