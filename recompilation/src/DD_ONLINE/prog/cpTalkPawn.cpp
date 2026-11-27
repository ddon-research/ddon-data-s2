// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpTalkPawn.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtFilePath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "../../XFramework/cResource.h"
#include "cTalkMsgData.h"
#include "cpComponent.h"
#include "cpTalk.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUIMessage.h"
#include "rMsgSet.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sTalkManager.h"
#include "uDDOModel.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpTalkPawn::getDTI() const {
    return cpTalkPawn::DTI;
}

void* cpTalkPawn::operator new(size_t sz, u32 align) {
    return cpTalkPawn::getAllocator()->memAlloc(sz, align, cpTalkPawn::DTI.getID());
}

__attribute__((weak)) void cpTalkPawn::loadMsgData() {
    DDON_STUB("cpTalkPawn::loadMsgData")
    /* stub */
}

__attribute__((weak)) void cpTalkPawn::chageMsgData() {
    DDON_STUB("cpTalkPawn::chageMsgData")
    /* stub */
}

__attribute__((weak)) bool cpTalkPawn::loadMsgArcStage(TICKET& ticket, u32 StageNo) {
    DDON_STUB("cpTalkPawn::loadMsgArcStage")
    return {};
}

__attribute__((weak)) bool cpTalkPawn::loadMsgData(cTalkMsgData& msgData, MT_CTSTR path, bool isLoadMsg) {
    DDON_STUB("cpTalkPawn::loadMsgData")
    return {};
}

__attribute__((weak)) cTalkMsgData& cpTalkPawn::setupMsgData() {
    DDON_STUB("cpTalkPawn::setupMsgData")
    __builtin_unreachable();
}

__attribute__((weak)) cTalkMsgData& cpTalkPawn::getTalkMsgData(u32 type) {
    if (type != 2) {
        if (type == 1) {
            return mTalkMsgDataStage[mMsgFeature];
        } else {
            return mTalkMsgData;
        }
    } else {
        return mTalkMsgDataArea;
    }
}

cTalkMsgData& cpTalkPawn::getTalkMsgData() {
    return this->cpTalkPawn::getTalkMsgData(mMsgType);
}

void cpTalkPawn::loadSoundData() {
    if (mprPawnTalkSoundStreamResource != nullptr) {
        mprPawnTalkSoundStreamResource->release();
        mprPawnTalkSoundStreamResource = nullptr;
    }
    if (mpOwner != nullptr) {
        const MtDTI& t0 = mpOwner->getDTI();
        MT_CTSTR v0_1 = uHuman::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                if (mpOwner != nullptr) {
                    cContextInstance* t1 = static_cast<uDDOModel*>(mpOwner)->getContextInst();
                    u32 t2 = cContextInterface::getSex(static_cast<const cContextInstHm*>(t1));
                    u8 t3 = cContextInterface::getVoice(static_cast<const cContextInstHm*>(t1));
                    mVoicePitch = cContextInterface::getVoicePitch(static_cast<const cContextInstHm*>(t1));
                    ARC_TAGID t4 = static_cast<sSoundExt*>(sSound::getInstance())->createPawnTalkVoiceArcTag(t2, t3);
                    sArchiveManager* t5 = sArchiveManager::getInstance();
                    cResource* t6 = t5->createRes(t4, rArchiveListArray::convSearchId("RES_ID_PW_TALK_VO"), 1u, false);
                    if (t6 != nullptr) {
                        t6->addRef();
                        mprPawnTalkSoundStreamResource = static_cast<rSoundStreamRequest*>(t6);
                        t6->release();
                    }
                }
                return;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) void cpTalkPawn::requestPawnTalkVoice() {
    DDON_STUB("cpTalkPawn::requestPawnTalkVoice")
    /* stub */
}

cpTalkPawn::cpTalkPawn() {
    DDON_STUB("cpTalkPawn::cpTalkPawn")
    /* stub */
}

__attribute__((noinline)) cpTalkPawn::~cpTalkPawn() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicketStage != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicketStage);
    }
    if (mprPawnTalkSoundStreamResource != nullptr) {
        mprPawnTalkSoundStreamResource->release();
        mprPawnTalkSoundStreamResource = nullptr;
    }
    if (t0 == mArcTicketArea) {
        return;
    }
    sArchiveManager::getInstance()->returnTicket(mArcTicketArea);
}

void cpTalkPawn::move() {
    this->cpTalk::move();
    if (mpTalkUnit == nullptr) {
        chageMsgData();
    }
}

void cpTalkPawn::setTouch(uDDOModel* pUnit) {
    if (sTalkManager::getInstance()->getStatus() != 0) {
        return;
    }
    if (!static_cast<sGUIExt*>(sGUI::getInstance())->isTelopFSMEnd()) {
        return;
    }
    MtObject* t0 = getOwner();
    if (t0 == nullptr) {
        return;
    }
    if (static_cast<uDDOModel*>(t0)->isHuman()) {
        if (!static_cast<uDDOModel*>(t0)->isDead()) {
            sTalkManager::getInstance()->notifyTalkStart(static_cast<uDDOModel*>(t0));
            mpTalkUnit = pUnit;
            setupMsgData();
        }
    } else {
        sTalkManager::getInstance()->notifyTalkStart(static_cast<uDDOModel*>(t0));
        mpTalkUnit = pUnit;
        setupMsgData();
    }
}

inline cpTalkPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpTalkPawn::MyDTI cpTalkPawn::DTI("cpTalkPawn", &::cpTalk::DTI, 1048ul, 0u, 0u);

__attribute__((weak)) MtObject* cpTalkPawn::MyDTI::newInstance() const {
    DDON_STUB("cpTalkPawn::MyDTI::newInstance")
    return nullptr;
}

