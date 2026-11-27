// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIEntryBoardRecruit.h"
#include "Protocol/PacketData/EntryBoard.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cContextInterface.h"
#include "cControl.h"
#include "cEquipData.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuEntryBoard.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sMenu.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIEntryBoardRecruit::getDTI() const {
    return uGUIEntryBoardRecruit::DTI;
}

__attribute__((noinline)) uGUIEntryBoardRecruit::~uGUIEntryBoardRecruit() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIEntryBoardRecruit::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ENTRYBOARD_RECRUIT_GUI"), 129u, 1465387047l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(rArchiveListArray::convTagId("uGUIEntryBoard"), "RES_ID_ENTRY_BOARD_GMD", 0u);
}

__attribute__((weak)) void uGUIEntryBoardRecruit::setup() {
    DDON_STUB("uGUIEntryBoardRecruit::setup")
    /* stub */
}

void uGUIEntryBoardRecruit::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIEntryBoardRecruit::iconRefresh() {
    DDON_STUB("uGUIEntryBoardRecruit::iconRefresh")
    /* stub */
}

void uGUIEntryBoardRecruit::cancelTextBox() {
    if (sMenu::getInstance()->mMenuEntryBoardItem.mMenuRno[0] == 3) {
        mRefTextBoxs.elems[0].setMessage("");
        mRefTextBoxs.elems[0].closeKeyboard(true);
    }
    if (sMenu::getInstance()->mMenuEntryBoardItem.mMenuRno[0] != 5) {
        return;
    }
    mRefTextBoxs.elems[1].setMessage("");
    mRefTextBoxs.elems[1].closeKeyboard(true);
}

__attribute__((weak)) bool uGUIEntryBoardRecruit::isEndTextBox() {
    DDON_STUB("uGUIEntryBoardRecruit::isEndTextBox")
    return {};
}

__attribute__((weak)) void uGUIEntryBoardRecruit::updatePopRecruit() {
    DDON_STUB("uGUIEntryBoardRecruit::updatePopRecruit")
    /* stub */
}

void uGUIEntryBoardRecruit::updateInit() {
    updateWait();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIEntryBoardRecruit::updateWait);
}

__attribute__((weak)) void uGUIEntryBoardRecruit::updateWait() {
    DDON_STUB("uGUIEntryBoardRecruit::updateWait")
    /* stub */
}

s32 uGUIEntryBoardRecruit::getSMenuCursorX() {
    return uGUIBase::DISABLE_IDX;
}

__attribute__((weak)) s32 uGUIEntryBoardRecruit::getSMenuCursorY() {
    DDON_STUB("uGUIEntryBoardRecruit::getSMenuCursorY")
    return {};
}

void uGUIEntryBoardRecruit::setupRecruitMemberNum() {
    u32 v0_1;
    if (sMenu::getInstance()->mMenuEntryBoardItem.mpBoardInfo == nullptr) {
        v0_1 = 1;
    } else {
        v0_1 = sMenu::getInstance()->mMenuEntryBoardItem.mpBoardInfo->memberNum - 1u;
    }
    mRecruitNum = v0_1;
    if (mRefIconJob.elems[0].mpInstance != nullptr) {
        mRefIconJob.elems[0].mpInstance->setVisible(v0_1 != 0);
    }
    if (mRefJobButton.elems[0].mpInstance != nullptr) {
        mRefJobButton.elems[0].mpInstance->setVisible(v0_1 != 0);
    }
    u32 v3_7 = mRecruitNum;
    if (mRefIconJob.elems[1].mpInstance != nullptr) {
        mRefIconJob.elems[1].mpInstance->setVisible(v3_7 > 1u);
    }
    if (mRefJobButton.elems[1].mpInstance != nullptr) {
        mRefJobButton.elems[1].mpInstance->setVisible(v3_7 > 1u);
    }
    u32 v5_7 = mRecruitNum;
    if (mRefIconJob.elems[2].mpInstance != nullptr) {
        mRefIconJob.elems[2].mpInstance->setVisible(v5_7 > 2u);
    }
    if (mRefJobButton.elems[2].mpInstance != nullptr) {
        mRefJobButton.elems[2].mpInstance->setVisible(v5_7 > 2u);
    }
    u32 v7_7 = mRecruitNum;
    if (mRefIconJob.elems[3].mpInstance != nullptr) {
        mRefIconJob.elems[3].mpInstance->setVisible(v7_7 > 3u);
    }
    if (mRefJobButton.elems[3].mpInstance != nullptr) {
        mRefJobButton.elems[3].mpInstance->setVisible(v7_7 > 3u);
    }
    u32 v9_7 = mRecruitNum;
    if (mRefIconJob.elems[4].mpInstance != nullptr) {
        mRefIconJob.elems[4].mpInstance->setVisible(v9_7 > 4u);
    }
    if (mRefJobButton.elems[4].mpInstance != nullptr) {
        mRefJobButton.elems[4].mpInstance->setVisible(v9_7 > 4u);
    }
    u32 v11_7 = mRecruitNum;
    if (mRefIconJob.elems[5].mpInstance != nullptr) {
        mRefIconJob.elems[5].mpInstance->setVisible(v11_7 > 5u);
    }
    if (mRefJobButton.elems[5].mpInstance != nullptr) {
        mRefJobButton.elems[5].mpInstance->setVisible(v11_7 > 5u);
    }
    u32 v13_7 = mRecruitNum;
    if (mRefIconJob.elems[6].mpInstance != nullptr) {
        mRefIconJob.elems[6].mpInstance->setVisible(v13_7 > 6u);
    }
    if (mRefJobButton.elems[6].mpInstance != nullptr) {
        mRefJobButton.elems[6].mpInstance->setVisible(v13_7 > 6u);
    }
    if (mpVCtrl != nullptr) {
        if (mpHCtrl != nullptr) {
            if (mpVCtrl->mCurrentPos == 8) {
                mpHCtrl->resetItemNum(static_cast<s32>((static_cast<int>(mRecruitNum) <= 0) ? 1u : mRecruitNum), static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
                return;
            }
        }
    }
}

__attribute__((weak)) void uGUIEntryBoardRecruit::moveInput() {
    DDON_STUB("uGUIEntryBoardRecruit::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIEntryBoardRecruit::moveEvent() {
    DDON_STUB("uGUIEntryBoardRecruit::moveEvent")
    /* stub */
}

void uGUIEntryBoardRecruit::itemSizeReset() {
    switch (static_cast<unsigned int>(mpVCtrl->getCurrentPos() - 4)) {
        case 0:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
        case 2:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(3, static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
        case 4:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(static_cast<s32>((static_cast<int>(mRecruitNum) <= 0) ? 1u : mRecruitNum), static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
        case 5:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
        case 7:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
        default:
        {
            if (mpHCtrl != nullptr) {
                mpHCtrl->resetItemNum(1, static_cast<const u32*>(nullptr), mpHCtrl->getCurrentPos());
            }
            break;
        }
    }
}

__attribute__((weak)) void uGUIEntryBoardRecruit::onCloseTextBox(s32 textboxInputType) {
    DDON_STUB("uGUIEntryBoardRecruit::onCloseTextBox")
    /* stub */
}

__attribute__((weak)) void uGUIEntryBoardRecruit::evDecide() {
    DDON_STUB("uGUIEntryBoardRecruit::evDecide")
    /* stub */
}

void uGUIEntryBoardRecruit::evNumBoxMoveL() {
    if (mpVCtrl == nullptr) {
        return;
    }
    const s32 idxV = mpVCtrl->getCurrentPos();
    if (idxV != 5) {
        if (idxV == 3) {
            mRefNumBoxs.elems[1].pushLArrow(-1);
            nNet::stEntryBoardItemInfo* t0 = sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo();
            if (t0 != nullptr) {
                s32 t1 = mRefNumBoxs.elems[1].getNum();
                t0->jobLevelMax = static_cast<u32>(t1);
                if (t1 < mRefNumBoxs.elems[0].mCurrentNum) {
                    mRefNumBoxs.elems[0].setNum(t1);
                    t0->jobLevelMin = static_cast<u32>(t1);
                }
            }
        } else {
            if (idxV == 2) {
                mRefNumBoxs.elems[0].pushLArrow(-1);
                nNet::stEntryBoardItemInfo* t2 = sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo();
                if (t2 != nullptr) {
                    s32 t3 = mRefNumBoxs.elems[0].getNum();
                    t2->jobLevelMin = static_cast<u32>(t3);
                    if (mRefNumBoxs.elems[1].mCurrentNum < t3) {
                        mRefNumBoxs.elems[1].setNum(t3);
                        t2->jobLevelMax = static_cast<u32>(t3);
                    }
                }
            }
        }
    } else {
        mRefNumBox.pushLArrow(-1);
        if (sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo() != nullptr) {
            sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo()->requiredItemRank = (static_cast<int>(mItemRankMin) < mRefNumBox.getNum()) ? static_cast<unsigned short>(mItemRankMin) : static_cast<unsigned short>(mRefNumBox.getNum());
        }
    }
}

void uGUIEntryBoardRecruit::evNumBoxMoveR() {
    if (mpVCtrl == nullptr) {
        return;
    }
    const s32 idxV = mpVCtrl->getCurrentPos();
    if (idxV != 5) {
        if (idxV == 3) {
            mRefNumBoxs.elems[1].pushRArrow(1);
            nNet::stEntryBoardItemInfo* t0 = sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo();
            if (t0 != nullptr) {
                s32 t1 = mRefNumBoxs.elems[1].getNum();
                t0->jobLevelMax = static_cast<u32>(t1);
                if (t1 < mRefNumBoxs.elems[0].mCurrentNum) {
                    mRefNumBoxs.elems[0].setNum(t1);
                    t0->jobLevelMin = static_cast<u32>(t1);
                }
            }
        } else {
            if (idxV == 2) {
                mRefNumBoxs.elems[0].pushRArrow(1);
                nNet::stEntryBoardItemInfo* t2 = sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo();
                if (t2 != nullptr) {
                    s32 t3 = mRefNumBoxs.elems[0].getNum();
                    t2->jobLevelMin = static_cast<u32>(t3);
                    if (mRefNumBoxs.elems[1].mCurrentNum < t3) {
                        mRefNumBoxs.elems[1].setNum(t3);
                        t2->jobLevelMax = static_cast<u32>(t3);
                    }
                }
            }
        }
    } else {
        mRefNumBox.pushRArrow(1);
        if (sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo() != nullptr) {
            sMenu::getInstance()->mMenuEntryBoardItem.getBoardInfo()->requiredItemRank = (static_cast<int>(mItemRankMin) < mRefNumBox.getNum()) ? static_cast<unsigned short>(mItemRankMin) : static_cast<unsigned short>(mRefNumBox.getNum());
        }
    }
}

__attribute__((weak)) u32 uGUIEntryBoardRecruit::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIEntryBoardRecruit::evCtrlDecide")
    return {};
}

u32 uGUIEntryBoardRecruit::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

u32 uGUIEntryBoardRecruit::evCtrlUpDown(cControl::Message* msg) {
    sMenu* t0 = sMenu::getInstance();
    t0->mMenuEntryBoardItem.mRecruitNo = -1;
    mDrawRecruitNo = -1;
    mSelectRecruitNo = -1;
    if (mpVCtrl != nullptr) {
        if (mpVCtrl->mCurrentPos == 8) {
            const s32 idxH = mpHCtrl->getCurrentPos();
            mSelectRecruitNo = idxH + 1;
            mDrawRecruitNo = mSelectRecruitNo;
            t0->mMenuEntryBoardItem.mRecruitNo = mDrawRecruitNo;
            setInputEvent(1u);
            return 0;
        }
    }
    setInputEvent(1u);
    return 0;
}

u32 uGUIEntryBoardRecruit::evCtrlCursorLeft(cControl::Message* msg) {
    for (unsigned int i0_2 = 0; i0_2 <= 1u; i0_2 += 1u) {
        if (mRefNumBoxs.elems[i0_2].mMode == uGUIBase::cReferenceUINumBox::MODE_EDIT) {
            return 1;
        }
    }
    if (mpVCtrl != nullptr) {
        setInputEvent(66u);
        return 0;
    } else {
        return 1;
    }
}

u32 uGUIEntryBoardRecruit::evCtrlCursorRight(cControl::Message* msg) {
    for (unsigned int i0_2 = 0; i0_2 <= 1u; i0_2 += 1u) {
        if (mRefNumBoxs.elems[i0_2].mMode == uGUIBase::cReferenceUINumBox::MODE_EDIT) {
            return 1;
        }
    }
    if (mpVCtrl != nullptr) {
        setInputEvent(67u);
        return 0;
    } else {
        return 1;
    }
}

__attribute__((weak)) u32 uGUIEntryBoardRecruit::evCtrlClick(cControl::Message* msg) {
    DDON_STUB("uGUIEntryBoardRecruit::evCtrlClick")
    return {};
}

u32 uGUIEntryBoardRecruit::evCtrlOver(cControl::Message* msg) {
    return static_cast<unsigned int>(msg->mouse_hit_id - 5) > 6;
}

u32 uGUIEntryBoardRecruit::evCtrlOut(cControl::Message* msg) {
    return static_cast<unsigned int>(msg->mouse_hit_id - 5) > 6;
}

u32 uGUIEntryBoardRecruit::evCtrlStart(cControl::Message* msg) {
    if (mpVCtrl->getCurrentPos() != 5) {
        if (static_cast<unsigned int>(mpVCtrl->getCurrentPos() - 2) <= 1) {
            setInputEvent(69u);
        }
    } else {
        setInputEvent(72u);
    }
    return 1;
}

__attribute__((weak)) u32 uGUIEntryBoardRecruit::evCtrlNumBoxMoveL(cControl::Message* msg) {
    DDON_STUB("uGUIEntryBoardRecruit::evCtrlNumBoxMoveL")
    return {};
}

__attribute__((weak)) u32 uGUIEntryBoardRecruit::evCtrlNumBoxMoveR(cControl::Message* msg) {
    DDON_STUB("uGUIEntryBoardRecruit::evCtrlNumBoxMoveR")
    return {};
}

inline uGUIEntryBoardRecruit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIEntryBoardRecruit::MyDTI uGUIEntryBoardRecruit::DTI("uGUIEntryBoardRecruit", &::uGUIsMenuBase::DTI, 11408ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIEntryBoardRecruit::MyDTI::newInstance() const {
    DDON_STUB("uGUIEntryBoardRecruit::MyDTI::newInstance")
    return nullptr;
}

