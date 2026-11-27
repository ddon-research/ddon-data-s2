// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIAnnounce.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cPlDeadFlow.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sQuestManagerExt.h"
#include "sWorkRate.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIAnnounce::getDTI() const {
    return uGUIAnnounce::DTI;
}

void* uGUIAnnounce::operator new(size_t sz, u32 align) {
    return uGUIAnnounce::getAllocator()->memAlloc(sz, align, uGUIAnnounce::DTI.getID());
}

uGUIAnnounce::~uGUIAnnounce() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIAnnounce::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIAnnounce::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ANOUNCE_GUI"), 129u, 1427764303l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIAnnounce::setup() {
    DDON_STUB("uGUIAnnounce::setup")
    /* stub */
}

__attribute__((weak)) void uGUIAnnounce::callbackAnimationEvent(u32 instanceID, u32 animationID, u32 eventNo) {
    DDON_STUB("uGUIAnnounce::callbackAnimationEvent")
    /* stub */
}

bool uGUIAnnounce::checkSameMsg(MT_CTSTR pMsg, MT_CTSTR pAnalyze0, MT_CTSTR pAnalyze1, u32 analyzeNum1, u32 analyzeNum2) {
    if (pMsg != (&mText.mStr[0])) {
        if (pMsg != nullptr) {
            if (strcmp(&mText.mStr[0], pMsg) == 0) {
                if (pAnalyze0 != nullptr) {
                    if (mMsgAnalyzerWork[0].mAnalyzeMsg.value != nullptr) {
                        if (strcmp(pAnalyze0, reinterpret_cast<const char*>(mMsgAnalyzerWork[0].mAnalyzeMsg.value->str)) == 0) {
                            if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                                if (pAnalyze1 != nullptr) {
                                    if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                        if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                            return false;
                                        }
                                    } else {
                                        if ((*pAnalyze1) != '\0') {
                                            return false;
                                        }
                                    }
                                }
                                return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                            }
                        }
                    } else {
                        if ((*pAnalyze0) == '\0') {
                            if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                                if (pAnalyze1 != nullptr) {
                                    if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                        if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                            return false;
                                        }
                                    } else {
                                        if ((*pAnalyze1) != '\0') {
                                            return false;
                                        }
                                    }
                                }
                                return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                            }
                        }
                    }
                } else {
                    if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                        if (pAnalyze1 != nullptr) {
                            if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                    return false;
                                }
                            } else {
                                if ((*pAnalyze1) != '\0') {
                                    return false;
                                }
                            }
                        }
                        return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                    }
                }
            }
        } else {
            if (mText.mLength == 0) {
                if (pAnalyze0 != nullptr) {
                    if (mMsgAnalyzerWork[0].mAnalyzeMsg.value != nullptr) {
                        if (strcmp(pAnalyze0, reinterpret_cast<const char*>(mMsgAnalyzerWork[0].mAnalyzeMsg.value->str)) == 0) {
                            if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                                if (pAnalyze1 != nullptr) {
                                    if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                        if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                            return false;
                                        }
                                    } else {
                                        if ((*pAnalyze1) != '\0') {
                                            return false;
                                        }
                                    }
                                }
                                return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                            }
                        }
                    } else {
                        if ((*pAnalyze0) == '\0') {
                            if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                                if (pAnalyze1 != nullptr) {
                                    if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                        if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                            return false;
                                        }
                                    } else {
                                        if ((*pAnalyze1) != '\0') {
                                            return false;
                                        }
                                    }
                                }
                                return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                            }
                        }
                    }
                } else {
                    if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                        if (pAnalyze1 != nullptr) {
                            if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                    return false;
                                }
                            } else {
                                if ((*pAnalyze1) != '\0') {
                                    return false;
                                }
                            }
                        }
                        return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                    }
                }
            }
        }
    } else {
        if (pAnalyze0 != nullptr) {
            if (mMsgAnalyzerWork[0].mAnalyzeMsg.value != nullptr) {
                if (strcmp(pAnalyze0, reinterpret_cast<const char*>(mMsgAnalyzerWork[0].mAnalyzeMsg.value->str)) == 0) {
                    if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                        if (pAnalyze1 != nullptr) {
                            if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                    return false;
                                }
                            } else {
                                if ((*pAnalyze1) != '\0') {
                                    return false;
                                }
                            }
                        }
                        return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                    }
                }
            } else {
                if ((*pAnalyze0) == '\0') {
                    if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                        if (pAnalyze1 != nullptr) {
                            if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                                if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                                    return false;
                                }
                            } else {
                                if ((*pAnalyze1) != '\0') {
                                    return false;
                                }
                            }
                        }
                        return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
                    }
                }
            }
        } else {
            if (mMsgAnalyzerWork[0].mAnalyzeNum == static_cast<int>(analyzeNum1)) {
                if (pAnalyze1 != nullptr) {
                    if (mMsgAnalyzerWork[1].mAnalyzeMsg.value != nullptr) {
                        if (strcmp(pAnalyze1, reinterpret_cast<const char*>(mMsgAnalyzerWork[1].mAnalyzeMsg.value->str)) != 0) {
                            return false;
                        }
                    } else {
                        if ((*pAnalyze1) != '\0') {
                            return false;
                        }
                    }
                }
                return mMsgAnalyzerWork[1].mAnalyzeNum == static_cast<int>(analyzeNum2);
            }
        }
    }
    return false;
}

__attribute__((weak)) void uGUIAnnounce::updateInit() {
    DDON_STUB("uGUIAnnounce::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIAnnounce::updateWait() {
    DDON_STUB("uGUIAnnounce::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIAnnounce::updateKeyWait() {
    DDON_STUB("uGUIAnnounce::updateKeyWait")
    /* stub */
}

__attribute__((weak)) void uGUIAnnounce::updateInfinit() {
}

__attribute__((weak)) void uGUIAnnounce::updateNoLeader() {
    DDON_STUB("uGUIAnnounce::updateNoLeader")
    /* stub */
}

void uGUIAnnounce::updateEntryBoardReady() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isEntryBoardReadyWait()) {
        if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->mEntryBoardReady) {
            if (!static_cast<sAreaExt*>(sArea::getInstance())->isStage()) {
                mType = 0;
                mFrame = 0.0f;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
            }
        } else {
            mType = 0;
            mFrame = 0.0f;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
        }
    } else {
        mType = 0;
        mFrame = 0.0f;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
    }
}

void uGUIAnnounce::updateEntryBoardDepart() {
    u32 t0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->mMyBoardInfo.memberNumMin;
    s32 t1 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionMemberNum(true);
    nQuest::SCHEDULE_ID scid(sQuestManagerExt::getInstance()->getNowCallEntryBoardScheduleID());
    bool t2 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true);
    if (t0 != 0) {
        if (!!t2) {
            if (t1 >= static_cast<int>(t0)) {
                if (t1 != 0) {
                    s32 v0_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLeaderMemberIndex();
                    if (v0_0 != 0) {
                        u32 v0_1 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPartyMemberInfoVec.mLength;
                        if (v0_1 != 0) {
                            MtObject* * v0_2 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPartyMemberInfoVec.mpArray;
                            unsigned int i0_4 = 0;
                            MtObject* v1_3;
                            for (;;) {
                                v1_3 = v0_2[static_cast<int>(i0_4)];
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_3) + 24)) == static_cast<unsigned int>(v0_0)) {
                                    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v1_3) + 120)) > 3) {
                                        break;
                                    } else {
                                        if (((12ul >> static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v1_3) + 120)) & 15)) & 1ul) == 0) {
                                            break;
                                        }
                                    }
                                }
                                if ((i0_4 + 1u) < v0_1) {
                                    i0_4 += 1u;
                                } else {
                                    mType = 0;
                                    mFrame = 0.0f;
                                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
                                    return;
                                }
                            }
                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_3) + 116)) != 0xFFFFFFFFu) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(sArea::getInstance()->mpArea[2]) + 320)) == 0) {
                                    if (!static_cast<sGUIExt*>(sGUI::getInstance())->mIsEntryDepart) {
                                        if (sQuestManagerExt::getInstance()->isEnableEntryBoard()) {
                                            if (sQuestManagerExt::getInstance()->isDistributionSituation(scid)) {
                                                bool t3 = sQuestManagerExt::getInstance()->isCycleContentsPlayNow();
                                                if (!t3) {
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    mType = 0;
    mFrame = 0.0f;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
}

void uGUIAnnounce::updateEntryBoardReentry() {
    s32 minMember = static_cast<sNetworkExt*>(sNetwork::getInstance())->mMyBoardInfo.memberNumMin;
    s32 joinMember = static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionMemberNum(true);
    nQuest::SCHEDULE_ID scid(sQuestManagerExt::getInstance()->getNowCallEntryBoardScheduleID());
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        if (joinMember < minMember) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isEntryLeader()) {
                if (sQuestManagerExt::getInstance()->isEnableEntryBoard()) {
                    bool t0 = sQuestManagerExt::getInstance()->isDistributionSituation(scid);
                    if (!t0) {
                        mType = 0;
                        mFrame = 0.0f;
                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
                    }
                } else {
                    mType = 0;
                    mFrame = 0.0f;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
                }
            } else {
                mType = 0;
                mFrame = 0.0f;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
            }
        } else {
            mType = 0;
            mFrame = 0.0f;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
        }
    } else {
        mType = 0;
        mFrame = 0.0f;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
    }
}

void uGUIAnnounce::updateDisableContents() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        if (static_cast<sAreaExt*>(sArea::getInstance())->isLobby()) {
            if (sQuestManagerExt::getInstance()->isEnableEntryBoard()) {
                mType = 0;
                mFrame = 0.0f;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
            }
        } else {
            mType = 0;
            mFrame = 0.0f;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
        }
    } else {
        mType = 0;
        mFrame = 0.0f;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
    }
}

void uGUIAnnounce::updateNoSituation() {
    nQuest::SCHEDULE_ID scid(sQuestManagerExt::getInstance()->getNowCallEntryBoardScheduleID());
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        if (static_cast<sAreaExt*>(sArea::getInstance())->isLobby()) {
            bool t0 = sQuestManagerExt::getInstance()->isDistributionSituation(scid);
            if (t0) {
                mType = 0;
                mFrame = 0.0f;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
            }
        } else {
            mType = 0;
            mFrame = 0.0f;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
        }
    } else {
        mType = 0;
        mFrame = 0.0f;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateWait);
    }
}

void uGUIAnnounce::updateEndWait() {
    if (mpInstAnim != nullptr) {
        if (mpInstAnim->isAnimationEnd()) {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateExit);
        }
    } else {
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIAnnounce::updateExit);
    }
}

void uGUIAnnounce::updateExit() {
    end();
}

inline uGUIAnnounce::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIAnnounce::MyDTI uGUIAnnounce::DTI("uGUIAnnounce", &::uGUIBase::DTI, 2736ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIAnnounce::MyDTI::newInstance() const {
    DDON_STUB("uGUIAnnounce::MyDTI::newInstance")
    return nullptr;
}

