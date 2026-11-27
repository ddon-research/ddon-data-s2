// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sTalkManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cComponentManager.h"
#include "cNetBase.h"
#include "cQuestTask.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "cTalkMsgData.h"
#include "cTalkState.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpKeyCommand.h"
#include "cpRootComponent.h"
#include "cpTalk.h"
#include "cpTalkPawn.h"
#include "nCastUtility.h"
#include "nCharacterData.h"
#include "nFsm.h"
#include "nQuest.h"
#include "nTalk.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUIMessage.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sChat.h"
#include "sControlManager.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "sNpcManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "uDDOModel.h"
#include "uGUIBase.h"
#include "uHuman.h"
#include "uNpc.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sTalkManager::getDTI() const {
    return sTalkManager::DTI;
}

void* sTalkManager::operator new(size_t sz, u32 align) {
    return sTalkManager::getAllocator()->memAlloc(sz, align, sTalkManager::DTI.getID());
}

void sTalkManager::setNpcWindowText(cTalkMsgData& MsgData) {
    if (MsgData.getDispPageNum() != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (MsgData.getMessage() != nullptr) {
                sGUI* t0 = sGUI::getInstance();
                static_cast<sGUIExt*>(t0)->addNpcWindowText(MsgData.getMessage());
            }
            if (MsgData.getDispMsgType() != 0) {
                if (MsgData.getDispMsgType() == 1) {
                    break;
                }
            }
            MsgData.addDispPageNo();
            if ((i0_3 + 1u) < MsgData.getDispPageNum()) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    mDispPageIdx = -1;
    static_cast<sGUIExt*>(sGUI::getInstance())->setNpcWindowTimer(-1.0f);
}

MT_CTSTR sTalkManager::getTalkItemName(u32 Type) {
    if (mpTalkSelectItemName != nullptr) {
        if (Type < mpTalkSelectItemName->mMessageNum) {
            return mpTalkSelectItemName->getMessage(Type);
        }
    }
    return "";
}

void sTalkManager::notifyTalkStart(uDDOModel* pUnit) {
    mpTalkTarget = pUnit;
    mRno0 = 1;
}

__attribute__((weak)) void sTalkManager::updateDispPage() {
    DDON_STUB("sTalkManager::updateDispPage")
    /* stub */
}

uGUIBase* sTalkManager::createGUISingleton(const MtDTI* pDTI) {
    mpGUISingletonMenu = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(pDTI);
    return mpGUISingletonMenu;
}

uGUIBase* sTalkManager::setGUISingleton(uGUIBase* pGUI) {
    static_cast<sGUIExt*>(sGUI::getInstance())->setSingletonMenu(pGUI);
    mpGUISingletonMenu = pGUI;
    return pGUI;
}

void sTalkManager::deleteGUISingleton() {
    if (mpGUISingletonMenu != nullptr) {
        if (mpGUISingletonMenu == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
            static_cast<sGUIExt*>(sGUI::getInstance())->killSingletonMenu();
        }
    }
    mpGUISingletonMenu = nullptr;
}

bool sTalkManager::isMoveGUISingleton() {
    return (mpGUISingletonMenu != nullptr) && (mpGUISingletonMenu == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu);
}

bool sTalkManager::isEndGUISingleton() {
    if ((mpGUISingletonMenu != nullptr) && (mpGUISingletonMenu == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu)) {
        return mpGUISingletonMenu->mResult == uGUIBase::RESULT_EXIT;
    }
    return true;
}

__attribute__((weak)) void sTalkManager::notifyUpdatesQuestPurpose(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sTalkManager::notifyUpdatesQuestPurpose")
    /* stub */
}

void sTalkManager::notifyChangeLeader() {
    mSelectQuestScheduleId.mScheduleId = nQuest::INVALID_SCHEDULE_ID.mScheduleId;
}

uControl* sTalkManager::getNpcCtrl() const {
    if (mpTalkTarget != nullptr) {
        if ((mpTalkTarget->getCtrl() != nullptr) && mpTalkTarget->getCtrl()->isNpc()) {
            return mpTalkTarget->getCtrl();
        }
    }
    return nullptr;
}

s32 sTalkManager::getNpcId() const {
    if (mpTalkTarget != nullptr) {
        if (mpTalkTarget->mpTalk != nullptr) {
            return mpTalkTarget->mpTalk->getNpcId();
        }
    }
    return 0;
}

uDDOModel* sTalkManager::getTalkTarget() const {
    return mpTalkTarget;
}

cpTalk* sTalkManager::getTalkComponent() const {
    if (mpTalkTarget != nullptr) {
        return mpTalkTarget->mpTalk;
    } else {
        return nullptr;
    }
}

u32 sTalkManager::getNpcSex() const {
    uDDOModel* v0_3 = mpTalkTarget;
    u32 v2_8;
    if (v0_3 == nullptr) {
        v2_8 = 0;
    } else {
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = uNpc::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_8 = static_cast<uHuman*>(v0_3)->getSex();
                return v2_8;
            }
        }
        v2_8 = 0;
    }
    return v2_8;
}

__attribute__((weak)) u32 sTalkManager::getStatus() const {
    DDON_STUB("sTalkManager::getStatus")
    return {};
}

bool sTalkManager::isWait() const {
    if (mTalkType != 0) {
        return true;
    } else {
        return static_cast<unsigned char>(getRno() + 255) > 3;
    }
}

__attribute__((weak)) bool sTalkManager::isTalkNow() const {
    DDON_STUB("sTalkManager::isTalkNow")
    return {};
}

__attribute__((weak)) bool sTalkManager::isTalkExited() const {
    DDON_STUB("sTalkManager::isTalkExited")
    return {};
}

__attribute__((weak)) bool sTalkManager::isQuestTalkExited(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sTalkManager::isQuestTalkExited")
    return {};
}

bool sTalkManager::isFuncTalkNow(u32 funcId) const {
    if (mpTalkState != nullptr) {
        return funcId == nTalk::talkState2FuncId(mpTalkState->getState());
    } else {
        return false;
    }
}

u8 sTalkManager::getInnRno0() const {
    if (mpTalkState != nullptr) {
        return mpTalkState->getRno0();
    } else {
        return 0;
    }
}

void sTalkManager::setScheduleId(nQuest::SCHEDULE_ID scheduleId) {
    mSelectQuestScheduleId.mScheduleId = scheduleId.mScheduleId;
}

void sTalkManager::forceInterrupt() {
    mSelectQuestScheduleId.mScheduleId = nQuest::INVALID_SCHEDULE_ID.mScheduleId;
    mRno0 = 4;
}

void sTalkManager::killAllNpcMessage() {
    static_cast<sGUIExt*>(sGUI::getInstance())->finishNpcWindow();
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteTelop();
    if (mpTalkTarget == nullptr) {
        return;
    }
    mpTalkTarget->requestReleaseTouch(static_cast<uDDOModel*>(sPlayerManager::getInstance()->getMyPlayer()), nDDOModel::TOUCH_RELEASE_FINISH);
    mpTalkTarget = nullptr;
}

__attribute__((weak)) void sTalkManager::callFSMEventMsg(u32 MsgType, u32 QstNo, u32 GrpNo, f32 DispTime, f32 WaitTime, bool IsUseSerial, bool isHideMessage) {
    DDON_STUB("sTalkManager::callFSMEventMsg")
    /* stub */
}

__attribute__((weak)) void sTalkManager::callQuestEventMsg(u32 msgType, u32 questId, u32 grSerialNo, f32 dispTime, f32 waitTime) {
    DDON_STUB("sTalkManager::callQuestEventMsg")
    /* stub */
}

void sTalkManager::stopQuestEventMsg() {
    if (mTellQueue.mLength != 0) {
        u32 v0_0 = mTellQueue.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTellQueue.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTellQueue.mpArray[i0_3];
                v1_0 = mTellQueue.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTellQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTellQueue.mpArray));
    }
    mTellQueue.mpArray = nullptr;
    mTellQueue.mBufsiz = 0;
    mTellQueue.mLength = 0;
}

bool sTalkManager::isNormalTalk() const {
    if (mpTalkState != nullptr) {
        return mpTalkState->getState() == nTalk::TALK_STATE_BASE;
    } else {
        return false;
    }
}

void sTalkManager::setSendEventMsg(bool flag) {
    mSendEventMsg = flag;
}

void sTalkManager::requestPawnTalk(uDDOModel* pUnit) {
    u32 t0 = mTalkType;
    if (t0 == 0) {
        u8 t1 = getRno();
        if (static_cast<unsigned char>(t1 + 255) > 3) {
            sGUI* t2 = sGUI::getInstance();
            bool t3 = static_cast<sGUIExt*>(t2)->isTelopFSMEnd();
            if (t3) {
                if (pUnit != nullptr) {
                    if ((pUnit->mUnitId & 64u) != 0) {
                        sPlayerManager* t6 = sPlayerManager::getInstance();
                        uPlayer* pPl = t6->getMyPlayer();
                        if (pPl != nullptr) {
                            cpComponent* pComp = pUnit->mComponentMgr.getRootComponent();
                            if (pComp != nullptr) {
                                cpTalkPawn* pCp = static_cast<cpTalkPawn*>(pComp->find(cpTalkPawn::DTI, true, true));
                                if (pCp != nullptr) {
                                    unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pCp) + 0);
                                    unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 144);
                                    pCp->setTouch(static_cast<uDDOModel*>(pPl));
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        sGUI* t2 = sGUI::getInstance();
        bool t3 = static_cast<sGUIExt*>(t2)->isTelopFSMEnd();
        if (t3) {
            if (pUnit != nullptr) {
                if ((pUnit->mUnitId & 64u) != 0) {
                    sPlayerManager* t6 = sPlayerManager::getInstance();
                    uPlayer* pPl = t6->getMyPlayer();
                    if (pPl != nullptr) {
                        cpComponent* pComp = pUnit->mComponentMgr.getRootComponent();
                        if (pComp != nullptr) {
                            cpTalkPawn* pCp = static_cast<cpTalkPawn*>(pComp->find(cpTalkPawn::DTI, true, true));
                            if (pCp != nullptr) {
                                unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pCp) + 0);
                                unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 144);
                                pCp->setTouch(static_cast<uDDOModel*>(pPl));
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) bool sTalkManager::isPawnTalk(uDDOModel* pUnit) {
    DDON_STUB("sTalkManager::isPawnTalk")
    return {};
}

__attribute__((weak)) nQuest::QUEST_ID sTalkManager::getTargetQuestId() {
    DDON_STUB("sTalkManager::getTargetQuestId")
    __builtin_unreachable();
}

__attribute__((weak)) void sTalkManager::moveFSMEventMsg() {
    switch (static_cast<unsigned int>(mRno0 - 1)) {
        case 0:
        {
            moveFSMEventMsg_CreateWindow();
            break;
        }
        case 1:
        {
            updateDispPage();
            if (static_cast<sGUIExt*>(sGUI::getInstance())->isTelopFSMEnd()) {
                static_cast<sGUIExt*>(sGUI::getInstance())->setVisibleTelop(false);
                mEventMsgTimer = 0.0f;
                mRno0 = 3;
            }
            break;
        }
        case 2:
        {
            f32 t0 = nFsm::getDeltaSec();
            mEventMsgTimer = mEventMsgTimer + t0;
            if (mEventMsgTimer >= mEventMsgWaitTime) {
                mIsEndEventMsg = true;
                mRno0 = 4;
            }
            break;
        }
        case 3:
        {
            mTalkType = 0;
            mRno0 = 0;
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void sTalkManager::moveFSMEventMsg_CreateWindow() {
    DDON_STUB("sTalkManager::moveFSMEventMsg_CreateWindow")
    /* stub */
}

__attribute__((weak)) void sTalkManager::moveNormalMsg() {
    DDON_STUB("sTalkManager::moveNormalMsg")
    /* stub */
}

void sTalkManager::moveTalkExit() {
    if (sPlayerManager::getInstance()->getMyPlayer() != nullptr) {
        if (sPlayerManager::getInstance()->getMyPlayer()->mpKeyCommand != nullptr) {
            if (sPlayerManager::getInstance()->getMyPlayer()->mpKeyCommand->isActive()) {
                sPlayerManager::getInstance()->getMyPlayer()->mpKeyCommand->setActiveCheckCommand(true, cpKeyCommand::CHECK_CMD_PRI_SYS);
            }
        }
    }
    sQuestManagerExt* v1_4 = sQuestManagerExt::getInstance();
    s32 v1_3;
    if (mpTalkTarget == nullptr) {
        v1_3 = 0;
    } else {
        if (mpTalkTarget->mpTalk == nullptr) {
            v1_3 = 0;
        } else {
            v1_3 = mpTalkTarget->mpTalk->getNpcId();
        }
    }
    v1_4->notifyTalkEnd(static_cast<u32>(v1_3));
    static_cast<sGUIExt*>(sGUI::getInstance())->finishNpcWindow();
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteTelop();
    if (mpTalkTarget != nullptr) {
        mpTalkTarget->requestReleaseTouch(static_cast<uDDOModel*>(sPlayerManager::getInstance()->getMyPlayer()), nDDOModel::TOUCH_RELEASE_FINISH);
        mpTalkTarget = nullptr;
    }
    sControlManager::getInstance()->resetClanBaseManager();
    sFlag::getInstance()->setFlag(4u, 14u, false, true, false);
    if (mpTalkState != nullptr) {
        mpTalkState->finalize();
        if (mpTalkState != nullptr) {
            delete mpTalkState;
            mpTalkState = nullptr;
        }
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteQuestInfo();
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteDeliveryItem();
    if (mpGUISingletonMenu != nullptr) {
        if (mpGUISingletonMenu == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
            static_cast<sGUIExt*>(sGUI::getInstance())->killSingletonMenu();
        }
    }
    mpGUISingletonMenu = nullptr;
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteShopTitle();
    if (mSelectData.mLength != 0) {
        u32 v5_0 = mSelectData.mLength;
        unsigned int i5_3 = 0;
        u32 v6_0;
        for (;;) {
            if (mSelectData.mpArray[i5_3] == nullptr) {
                v6_0 = v5_0;
            } else {
                delete mSelectData.mpArray[i5_3];
                v6_0 = mSelectData.mLength;
            }
            if ((i5_3 + 1u) < v6_0) {
                v5_0 = v6_0;
                i5_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectData.mpArray));
    }
    mSelectData.mpArray = nullptr;
    mSelectData.mBufsiz = 0;
    mSelectData.mLength = 0;
    if (mSelectMember.mLength != 0) {
        u32 v9_0 = mSelectMember.mLength;
        unsigned int i9_3 = 0;
        u32 v10_0;
        for (;;) {
            if (mSelectMember.mpArray[i9_3] == nullptr) {
                v10_0 = v9_0;
            } else {
                delete mSelectMember.mpArray[i9_3];
                v10_0 = mSelectMember.mLength;
            }
            if ((i9_3 + 1u) < v10_0) {
                v9_0 = v10_0;
                i9_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectMember.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectMember.mpArray));
    }
    mSelectMember.mpArray = nullptr;
    mSelectMember.mBufsiz = 0;
    mSelectMember.mLength = 0;
    mRno0 = 0;
    mSelectQuestScheduleId.mScheduleId = nQuest::INVALID_SCHEDULE_ID.mScheduleId;
    mIsChangeClanManager = false;
}

__attribute__((weak)) void sTalkManager::requestVoice(cTalkMsgData& MsgData) {
    DDON_STUB("sTalkManager::requestVoice")
    /* stub */
}

__attribute__((weak)) void sTalkManager::requestMessageFromGroupSerial(u32 group_serial) {
    DDON_STUB("sTalkManager::requestMessageFromGroupSerial")
    /* stub */
}

__attribute__((weak)) void sTalkManager::requestMessageFromGroupType(u32 group_type) {
    DDON_STUB("sTalkManager::requestMessageFromGroupType")
    /* stub */
}

void sTalkManager::stopVoice() {
    if (mVoiceStreamHandle == 0) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->releaseRequestVoice(mVoiceStreamHandle);
    mVoiceStreamHandle = 0;
}

void sTalkManager::loadCommonResource() {
    if (mpTalkSelectItemName != nullptr) {
        mpTalkSelectItemName->release();
        mpTalkSelectItemName = nullptr;
    }
    mpTalkSelectItemName = static_cast<rGUIMessage*>(sArchiveManager::getInstance()->createRes("game_common", "RES_ID_TALK_SELECT_NAME", 1u, false));
    if (mpFuncSelectItemName != nullptr) {
        mpFuncSelectItemName->release();
        mpFuncSelectItemName = nullptr;
    }
    mpFuncSelectItemName = static_cast<rGUIMessage*>(sArchiveManager::getInstance()->createRes("game_common", "RES_ID_FUNC_SELECT_NAME", 1u, false));
}

void sTalkManager::releaseCommonResource() {
    if (mpFuncSelectItemName != nullptr) {
        mpFuncSelectItemName->release();
        mpFuncSelectItemName = nullptr;
    }
    if (mpTalkSelectItemName == nullptr) {
        return;
    }
    mpTalkSelectItemName->release();
    mpTalkSelectItemName = nullptr;
}

void sTalkManager::releaseTalkState() {
    if (mpTalkState == nullptr) {
        return;
    }
    mpTalkState->finalize();
    if (mpTalkState == nullptr) {
        return;
    }
    delete mpTalkState;
    mpTalkState = nullptr;
}

bool sTalkManager::isEndTellMsg() const {
    if (mTellRno != 0) {
        if (mTellRno != 3) {
            return false;
        }
    }
    return true;
}

__attribute__((weak)) void sTalkManager::moveTellMsg_Init() {
    DDON_STUB("sTalkManager::moveTellMsg_Init")
    /* stub */
}

__attribute__((weak)) void sTalkManager::moveTellMsg_Move() {
    DDON_STUB("sTalkManager::moveTellMsg_Move")
    /* stub */
}

__attribute__((weak)) void sTalkManager::moveTellMsg_End() {
    DDON_STUB("sTalkManager::moveTellMsg_End")
    /* stub */
}

const nTalk::cSelectData* sTalkManager::getSelectData(s32 index) const {
    if (index < static_cast<int>(mSelectData.mLength)) {
        if (index > -1) {
            return static_cast<const nTalk::cSelectData*>(mSelectData.mpArray[static_cast<unsigned int>(index)]);
        }
    }
    return nullptr;
}

const nTalk::cSelectMember* sTalkManager::getSelectMember(s32 index) const {
    if (index < static_cast<int>(mSelectMember.mLength)) {
        if (index > -1) {
            return static_cast<const nTalk::cSelectMember*>(mSelectMember.mpArray[static_cast<unsigned int>(index)]);
        }
    }
    return nullptr;
}

u32 sTalkManager::getSelectMemberNum() const {
    return mSelectMember.mLength;
}

MT_CTSTR sTalkManager::getFuncName(MT_CTSTR indexName) const {
    rGUIMessage* t0 = mpFuncSelectItemName;
    return t0->getMessage(t0->getIndexFromName(indexName));
}

__attribute__((weak)) void sTalkManager::addSelectData(u32 type, u32 param0, u32 param1) {
    DDON_STUB("sTalkManager::addSelectData")
    /* stub */
}

__attribute__((weak)) void sTalkManager::addSelectMember(u32 slot, CHAR_NAME name, u32 pawnId) {
    DDON_STUB("sTalkManager::addSelectMember")
    /* stub */
}

void sTalkManager::clearSelectData() {
    if (mSelectData.mLength != 0) {
        u32 v0_0 = mSelectData.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSelectData.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSelectData.mpArray[i0_3];
                v1_0 = mSelectData.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectData.mpArray));
    }
    mSelectData.mpArray = nullptr;
    mSelectData.mBufsiz = 0;
    mSelectData.mLength = 0;
}

void sTalkManager::clearSelectMember() {
    if (mSelectMember.mLength != 0) {
        u32 v0_0 = mSelectMember.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSelectMember.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSelectMember.mpArray[i0_3];
                v1_0 = mSelectMember.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectMember.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectMember.mpArray));
    }
    mSelectMember.mpArray = nullptr;
    mSelectMember.mBufsiz = 0;
    mSelectMember.mLength = 0;
}

__attribute__((weak)) ARC_TAGID sTalkManager::createPawnTalkArcTag(u32 type, u32 personality) {
    DDON_STUB("sTalkManager::createPawnTalkArcTag")
    return {};
}

sTalkManager::sTalkManager() : mpTalkSelectItemName(static_cast<rGUIMessage*>(nullptr)), mpFuncSelectItemName(static_cast<rGUIMessage*>(nullptr)), mpGUISingletonMenu(static_cast<uGUIBase*>(nullptr)), mpTalkTarget(static_cast<uDDOModel*>(nullptr)), mpTalkState(static_cast<cTalkState*>(nullptr)) {
    mTellMsgTimer = 0.0f;
    mTalkType = 0;
    mDispPageIdx = -1;
    mVoiceStreamHandle = 0;
    mCheckCylinderHeight = 400.0f;
    mCheckCylinderRadius = 1400.0f;
    mEventMsgTimer = 0.0f;
    mRno0 = 0;
    mTellRno = 0;
    mEventUseSerial = false;
    mIsHideMessage = false;
    mEventMsgDispTime = 0.0f;
    mEventMsgWaitTime = 0.0f;
    mEventMsgType = 0;
    mEventMsgGrpNo = 0;
    mIsEndEventMsg = true;
    mSendEventMsg = false;
    mIsChangeClanManager = false;
    sTalkManager::mpInstance = this;
}

__attribute__((noinline)) sTalkManager::~sTalkManager() {
    sTalkManager::mpInstance = nullptr;
    if (mpTalkState != nullptr) {
        delete mpTalkState;
        mpTalkState = nullptr;
    }
    if (mSelectData.mLength != 0) {
        u32 v0_0 = mSelectData.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSelectData.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSelectData.mpArray[i0_3];
                v1_0 = mSelectData.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectData.mpArray));
    }
    mSelectData.mpArray = nullptr;
    mSelectData.mBufsiz = 0;
    mSelectData.mLength = 0;
    if (mSelectMember.mLength != 0) {
        u32 v3_0 = mSelectMember.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mSelectMember.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mSelectMember.mpArray[i3_3];
                v4_0 = mSelectMember.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSelectMember.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSelectMember.mpArray));
    }
    mSelectMember.mpArray = nullptr;
    mSelectMember.mBufsiz = 0;
    mSelectMember.mLength = 0;
    if (mTellQueue.mLength != 0) {
        u32 v6_0 = mTellQueue.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mTellQueue.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mTellQueue.mpArray[i6_3];
                v7_0 = mTellQueue.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTellQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTellQueue.mpArray));
    }
    mTellQueue.mpArray = nullptr;
    mTellQueue.mBufsiz = 0;
    mTellQueue.mLength = 0;
}

void sTalkManager::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sTalkManager::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sTalkManager::move() {
    if (mpGUISingletonMenu != nullptr) {
        if (!mpGUISingletonMenu->isEnable()) {
            mpGUISingletonMenu = nullptr;
        }
    }
    if (mpTalkTarget != nullptr) {
        if (!mpTalkTarget->isEnable()) {
            mpTalkTarget = nullptr;
        }
    }
    if (mpTalkState != nullptr) {
        mpTalkState->updateUnitPtr();
    }
    if (mTalkType == 1) {
        moveFSMEventMsg();
    } else {
        if (mTellRno != 3) {
            if (mTellRno == 2) {
                moveTellMsg_Move();
            } else {
                if (mTellRno == 1) {
                    moveTellMsg_Init();
                }
            }
        } else {
            moveTellMsg_End();
        }
        moveNormalMsg();
    }
}

void sTalkManager::finalGame() {
    mIsChangeClanManager = false;
    mTellRno = 0;
    mTalkType = 0;
    if (mTellQueue.mLength != 0) {
        u32 v0_0 = mTellQueue.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTellQueue.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTellQueue.mpArray[i0_3];
                v1_0 = mTellQueue.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTellQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTellQueue.mpArray));
    }
    mTellQueue.mpArray = nullptr;
    mTellQueue.mBufsiz = 0;
    mTellQueue.mLength = 0;
}

inline sTalkManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sTalkManager::MyDTI sTalkManager::DTI("sTalkManager", &::cSystem::DTI, 248ul, 0u, 0u);

sTalkManager* sTalkManager::mpInstance;

__attribute__((weak)) MtObject* sTalkManager::MyDTI::newInstance() const {
    DDON_STUB("sTalkManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sTalkManager::cTellQueueNode::getDTI() const {
    return sTalkManager::cTellQueueNode::DTI;
}

sTalkManager::cTellQueueNode::~cTellQueueNode() {
}

__attribute__((weak)) void sTalkManager::cTellQueueNode::createProperty(MtPropertyList& s) {
}

inline sTalkManager::cTellQueueNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sTalkManager::cTellQueueNode::MyDTI sTalkManager::cTellQueueNode::DTI("sTalkManager::cTellQueueNode", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* sTalkManager::cTellQueueNode::MyDTI::newInstance() const {
    return new (16u) sTalkManager::cTellQueueNode;
}

template MtTypedArray<nTalk::cSelectData>::~MtTypedArray();

template MtTypedArray<nTalk::cSelectMember>::~MtTypedArray();

template MtTypedArray<sTalkManager::cTellQueueNode>::~MtTypedArray();

