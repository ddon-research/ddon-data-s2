// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestResourceManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cCycleQuestManagerBase.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestTask.h"
#include "../../XFramework/cResource.h"
#include "cTalkMsgData.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "rCycleQuestInfo.h"
#include "../../XFramework/rGUIMessage.h"
#include "rJobMasterCtrl.h"
#include "rJobTutorialQuestList.h"
#include "rPawnQuestTalk.h"
#include "rQuestSequenceList.h"
#include "rQuestTextData.h"
#include "rTutorialQuestGroup.h"
#include "sArchiveManager.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestResourceManager::getDTI() const {
    return cQuestResourceManager::DTI;
}

void* cQuestResourceManager::operator new(size_t sz, u32 align) {
    return cQuestResourceManager::getAllocator()->memAlloc(sz, align, cQuestResourceManager::DTI.getID());
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getQuestName(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getQuestName")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getRewardBoxQuestName(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getRewardBoxQuestName")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getOrderMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getOrderMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getPurposeMsg(nQuest::QUEST_ID questId, s32 purposeNo) const {
    DDON_STUB("cQuestResourceManager::getPurposeMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getFindInfoMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getFindInfoMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getFindInfoDetailMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getFindInfoDetailMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getSayPatternMsg(nQuest::QUEST_ID questId, s32 msgIdx) const {
    DDON_STUB("cQuestResourceManager::getSayPatternMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getContentsDetailMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getContentsDetailMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::getCycleContentsDetailMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getCycleContentsDetailMsg")
    return {};
}

__attribute__((weak)) cTalkMsgData* cQuestResourceManager::getMessageData(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getMessageData")
    return nullptr;
}

__attribute__((weak)) cTalkMsgData* cQuestResourceManager::getExmineData(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getExmineData")
    return nullptr;
}

__attribute__((weak)) rPawnQuestTalk* cQuestResourceManager::getPawnQuestTalk(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getPawnQuestTalk")
    return nullptr;
}

__attribute__((weak)) u32 cQuestResourceManager::getQuestSequence(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::getQuestSequence")
    return {};
}

MT_CTSTR cQuestResourceManager::getOrderCondition(u32 Idx) const {
    if (mpOrderCondition != nullptr) {
        if (Idx < mpOrderCondition->mMessageNum) {
            return mpOrderCondition->getMessage(Idx);
        }
    }
    return "";
}

MT_CTSTR cQuestResourceManager::getLightQuestPurpose(u32 Idx) const {
    if (mpLightQuestText != nullptr) {
        if (Idx < mpLightQuestText->mMessageNum) {
            return mpLightQuestText->getMessage(Idx);
        }
    }
    return "";
}

cJobMasterCtrl* cQuestResourceManager::getJobMasterCtrlData(u32 JobId) const {
    cJobMasterCtrl* v2_8;
    if (mpJobMasterCtrl == nullptr) {
        v2_8 = nullptr;
    } else {
        if (mpJobMasterCtrl->getDataNum() == 0) {
            v2_8 = nullptr;
        } else {
            for (unsigned int i0_3 = 0;;) {
                if (mpJobMasterCtrl->mpData[i0_3].mJobId != JobId) {
                    if ((i0_3 + 1u) < mpJobMasterCtrl->getDataNum()) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = &mpJobMasterCtrl->mpData[i0_3];
                    return v2_8;
                }
            }
            v2_8 = nullptr;
        }
    }
    return v2_8;
}

u32 cQuestResourceManager::getJobTutorialQuestNum() const {
    if (mpJobTutoQuestList != nullptr) {
        return mpJobTutoQuestList->getJobTutorialQuestNum();
    } else {
        return 0;
    }
}

__attribute__((weak)) nQuest::QUEST_ID cQuestResourceManager::getJobTutorialQuestId(u32 idx) const {
    DDON_STUB("cQuestResourceManager::getJobTutorialQuestId")
    __builtin_unreachable();
}

MT_CTSTR cQuestResourceManager::getCycleContentsName(u32 ContentType, u32 ContentSubType) {
    if (mpCycleQuestInfo != nullptr) {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 != 0) {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            unsigned int i0_0 = 0;
            unsigned int i3_0;
            for (;;) {
                rCycleQuestInfo::cCycleQuestInfo* pInfo = static_cast<rCycleQuestInfo::cCycleQuestInfo*>(v0_3[static_cast<int>(i0_0)]);
                if (pInfo->mCycleNo == ContentType) {
                    if (pInfo->mCycleSubNo == ContentSubType) {
                        if (pInfo != nullptr) {
                            u32 v2_3 = mContentResource.mLength;
                            if (v2_3 == 0) {
                                break;
                            } else {
                                u32 v3_3 = pInfo->mContentNameIdx;
                                MtObject* * v3_2 = mContentResource.mpArray;
                                i3_0 = 0;
                                for (;;) {
                                    if (v3_2[i3_0] != nullptr) {
                                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 24)) == ContentType) {
                                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 28)) == ContentSubType) {
                                                rGUIMessage* v4_2 = static_cast<cQuestResourceManager::cQuestContentResource*>(v3_2[i3_0])->getContentTextRes();
                                                if (v4_2 == nullptr) {
                                                    goto loop_1ba8f0_end;
                                                } else {
                                                    if (v3_3 < v4_2->mMessageNum) {
                                                        return v4_2->getMessage(v3_3);
                                                    } else {
                                                        break;
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if ((i3_0 + 1u) < v2_3) {
                                        i3_0 = i3_0 + 1u;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            loop_1ba8f0_end:;
        }
    }
    return "";
}

MT_CTSTR cQuestResourceManager::getCycleContentsInfo(u32 ContentType, u32 ContentSubType) {
    if (mpCycleQuestInfo != nullptr) {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 != 0) {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            unsigned int i0_0 = 0;
            unsigned int i3_0;
            for (;;) {
                MtObject* v1_1 = v0_3[static_cast<int>(i0_0)];
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == ContentType) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 12)) == ContentSubType) {
                        if (v1_1 != nullptr) {
                            u32 v2_3 = mContentResource.mLength;
                            if (v2_3 == 0) {
                                break;
                            } else {
                                rCycleQuestInfo::cCycleQuestInfo* pInfo = static_cast<rCycleQuestInfo::cCycleQuestInfo*>(v1_1);
                                unsigned int v3_3 = pInfo->mContentInfoIdx;
                                MtObject* * v3_2 = mContentResource.mpArray;
                                i3_0 = 0;
                                for (;;) {
                                    if (v3_2[i3_0] != nullptr) {
                                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 24)) == ContentType) {
                                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 28)) == ContentSubType) {
                                                rGUIMessage* v4_2 = static_cast<cQuestResourceManager::cQuestContentResource*>(v3_2[i3_0])->getContentTextRes();
                                                if (v4_2 == nullptr) {
                                                    goto loop_1ba9a0_end;
                                                } else {
                                                    if (v3_3 < v4_2->mMessageNum) {
                                                        return v4_2->getMessage(v3_3);
                                                    } else {
                                                        break;
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if ((i3_0 + 1u) < v2_3) {
                                        i3_0 = i3_0 + 1u;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            loop_1ba9a0_end:;
        }
    }
    return "";
}

MT_CTSTR cQuestResourceManager::getCycleContentsOrderPlace(u32 ContentType, u32 ContentSubType) {
    if (mpCycleQuestInfo != nullptr) {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 != 0) {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            unsigned int i0_0 = 0;
            unsigned int i3_0;
            for (;;) {
                rCycleQuestInfo::cCycleQuestInfo* pInfo = static_cast<rCycleQuestInfo::cCycleQuestInfo*>(v0_3[static_cast<int>(i0_0)]);
                if (pInfo->mCycleNo == ContentType) {
                    if (pInfo->mCycleSubNo == ContentSubType) {
                        if (pInfo != nullptr) {
                            u32 v2_3 = mContentResource.mLength;
                            if (v2_3 == 0) {
                                break;
                            } else {
                                u32 v3_3 = pInfo->mGatherInfoIdx;
                                MtObject* * v3_2 = mContentResource.mpArray;
                                i3_0 = 0;
                                for (;;) {
                                    if (v3_2[i3_0] != nullptr) {
                                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 24)) == ContentType) {
                                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[i3_0]) + 28)) == ContentSubType) {
                                                rGUIMessage* v4_2 = static_cast<cQuestResourceManager::cQuestContentResource*>(v3_2[i3_0])->getContentTextRes();
                                                if (v4_2 == nullptr) {
                                                    goto loop_1baa50_end;
                                                } else {
                                                    if (v3_3 < v4_2->mMessageNum) {
                                                        return v4_2->getMessage(v3_3);
                                                    } else {
                                                        break;
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if ((i3_0 + 1u) < v2_3) {
                                        i3_0 = i3_0 + 1u;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            loop_1baa50_end:;
        }
    }
    return "";
}

u32 cQuestResourceManager::getCycleContentsGatherStageNo(u32 ContentType, u32 ContentSubType) {
    unsigned int v3_0;
    if (mpCycleQuestInfo == nullptr) {
        v3_0 = 0;
    } else {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 == 0) {
            v3_0 = 0;
        } else {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            for (unsigned int i0_0 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 8)) == ContentType) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 12)) == ContentSubType) {
                        if (v0_3[static_cast<int>(i0_0)] == nullptr) {
                            v3_0 = 0;
                        } else {
                            v3_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 68);
                        }
                        return v3_0;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = 0;
        }
    }
    return v3_0;
}

u32 cQuestResourceManager::getCycleContentsGatherStartPos(u32 ContentType, u32 ContentSubType) {
    unsigned int v3_0;
    if (mpCycleQuestInfo == nullptr) {
        v3_0 = 0;
    } else {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 == 0) {
            v3_0 = 0;
        } else {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            for (unsigned int i0_0 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 8)) == ContentType) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 12)) == ContentSubType) {
                        if (v0_3[static_cast<int>(i0_0)] == nullptr) {
                            v3_0 = 0;
                        } else {
                            v3_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 72);
                        }
                        return v3_0;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = 0;
        }
    }
    return v3_0;
}

u32 cQuestResourceManager::getCycleContentsGatherNpcId(u32 ContentType, u32 ContentSubType) {
    unsigned int v3_0;
    if (mpCycleQuestInfo == nullptr) {
        v3_0 = 0;
    } else {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 == 0) {
            v3_0 = 0;
        } else {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            for (unsigned int i0_0 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 8)) == ContentType) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 12)) == ContentSubType) {
                        if (v0_3[static_cast<int>(i0_0)] == nullptr) {
                            v3_0 = 0;
                        } else {
                            v3_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 64);
                        }
                        return v3_0;
                    }
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = 0;
        }
    }
    return v3_0;
}

u32 cQuestResourceManager::getCycleContentsCategory(u32 NpcId) {
    unsigned int v2_0;
    if (mpCycleQuestInfo == nullptr) {
        v2_0 = 0;
    } else {
        u32 v0_0 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_0 == 0) {
            v2_0 = 0;
        } else {
            MtObject* * v0_1 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            for (unsigned int i0_2 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 64)) != NpcId) {
                    if ((i0_2 + 1u) < v0_0) {
                        i0_2 += 1u;
                    } else {
                        break;
                    }
                } else {
                    v2_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 8);
                    return v2_0;
                }
            }
            v2_0 = 0;
        }
    }
    return v2_0;
}

u32 cQuestResourceManager::getCycleContentsSubCategory(u32 NpcId) {
    unsigned int v2_0;
    if (mpCycleQuestInfo == nullptr) {
        v2_0 = 0;
    } else {
        u32 v0_0 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_0 == 0) {
            v2_0 = 0;
        } else {
            MtObject* * v0_1 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            for (unsigned int i0_2 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 64)) != NpcId) {
                    if ((i0_2 + 1u) < v0_0) {
                        i0_2 += 1u;
                    } else {
                        break;
                    }
                } else {
                    v2_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 12);
                    return v2_0;
                }
            }
            v2_0 = 0;
        }
    }
    return v2_0;
}

u32 cQuestResourceManager::getCycleContentsSubCategory(u32 NpcId, u32 Id) {
    if (mpCycleQuestInfo != nullptr) {
        u32 v0_2 = mpCycleQuestInfo->mCycleQuestInfo.mLength;
        if (v0_2 != 0) {
            MtObject* * v0_3 = mpCycleQuestInfo->mCycleQuestInfo.getBuffer();
            unsigned int i0_0 = 0;
            unsigned int i0_1 = 0;
            unsigned int v1_1;
            for (;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 64)) == NpcId) {
                    if (Id == i0_1) {
                        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_0)]) + 12);
                    } else {
                        v1_1 = i0_1 + 1u;
                    }
                } else {
                    v1_1 = i0_1;
                }
                if ((i0_0 + 1u) < v0_2) {
                    i0_0 += 1u;
                    i0_1 = v1_1;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cQuestResourceManager::getCycleContentsSubCategoryNum(u32 NpcId) {
    DDON_STUB("cQuestResourceManager::getCycleContentsSubCategoryNum")
    return {};
}

const rTutorialQuestGroup::cGroup* cQuestResourceManager::getTutorialQuestGroup(u32 groupId) const {
    if (mpTutoQuestGroup != nullptr) {
        return mpTutoQuestGroup->getGroup(groupId);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) bool cQuestResourceManager::isFinishedLoading(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::isFinishedLoading")
    return {};
}

__attribute__((weak)) bool cQuestResourceManager::isFinishedLoadingRewardBox(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::isFinishedLoadingRewardBox")
    return {};
}

__attribute__((weak)) bool cQuestResourceManager::hasRequest(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestResourceManager::hasRequest")
    return {};
}

__attribute__((weak)) void cQuestResourceManager::setFlagContentRelease(u32 ContentCategory, u32 ContentSubCategory, bool isContentRelease) {
    DDON_STUB("cQuestResourceManager::setFlagContentRelease")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::setFlagOpenNewspaper(bool isOpen) {
    DDON_STUB("cQuestResourceManager::setFlagOpenNewspaper")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::requestLoadResource(nQuest::QUEST_ID questId) {
    DDON_STUB("cQuestResourceManager::requestLoadResource")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::requestLoadResourceRewardBox(nQuest::QUEST_ID questId) {
    DDON_STUB("cQuestResourceManager::requestLoadResourceRewardBox")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::initContentCategory(u32 ContentCategory, u32 ContentSubCategory) {
    DDON_STUB("cQuestResourceManager::initContentCategory")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::move() {
    DDON_STUB("cQuestResourceManager::move")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::release() {
    DDON_STUB("cQuestResourceManager::release")
    /* stub */
}

void cQuestResourceManager::releaseRewardBox() {
    if (mRewardBoxResource.mLength != 0) {
        u32 v0_0 = mRewardBoxResource.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mRewardBoxResource.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mRewardBoxResource.mpArray[i0_3];
                v1_0 = mRewardBoxResource.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRewardBoxResource.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mRewardBoxResource.mpArray));
    }
    mRewardBoxResource.mpArray = nullptr;
    mRewardBoxResource.mBufsiz = 0;
    mRewardBoxResource.mLength = 0;
}

void cQuestResourceManager::initGame() {
    if (mpQuestSequence != nullptr) {
        mpQuestSequence->release();
        mpQuestSequence = nullptr;
    }
    cResource* t0 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_QST_SEQ", 1u, false);
    if (t0 != nullptr) {
        mpQuestSequence = static_cast<rQuestSequenceList*>(t0);
        t0->addRef();
        t0->release();
    }
    if (mpJobTutoQuestList != nullptr) {
        mpJobTutoQuestList->release();
        mpJobTutoQuestList = nullptr;
    }
    cResource* t1 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_JOB_TUTORIAL_QUEST_LIST", 1u, false);
    if (t1 != nullptr) {
        mpJobTutoQuestList = static_cast<rJobTutorialQuestList*>(t1);
        t1->addRef();
        t1->release();
    }
    if (mpOrderCondition != nullptr) {
        mpOrderCondition->release();
        mpOrderCondition = nullptr;
    }
    cResource* t2 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_ORDER_CONDITION_TEXT", 1u, false);
    if (t2 != nullptr) {
        mpOrderCondition = static_cast<rGUIMessage*>(t2);
        t2->addRef();
        t2->release();
    }
    if (mpLightQuestText != nullptr) {
        mpLightQuestText->release();
        mpLightQuestText = nullptr;
    }
    cResource* t3 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_LIGHT_QUEST_TEXT", 1u, false);
    if (t3 != nullptr) {
        mpLightQuestText = static_cast<rGUIMessage*>(t3);
        t3->addRef();
        t3->release();
    }
    if (mpJobMasterCtrl != nullptr) {
        mpJobMasterCtrl->release();
        mpJobMasterCtrl = nullptr;
    }
    cResource* t4 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_JOBMASTER_CTRL", 1u, false);
    if (t4 != nullptr) {
        mpJobMasterCtrl = static_cast<rJobMasterCtrl*>(t4);
        t4->addRef();
        t4->release();
    }
    if (mpCycleQuestInfo != nullptr) {
        mpCycleQuestInfo->release();
        mpCycleQuestInfo = nullptr;
    }
    cResource* t5 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_CYCLE_QUEST_INFO", 1u, false);
    if (t5 != nullptr) {
        mpCycleQuestInfo = static_cast<rCycleQuestInfo*>(t5);
        t5->addRef();
        t5->release();
    }
    if (mpTutoQuestGroup != nullptr) {
        mpTutoQuestGroup->release();
        mpTutoQuestGroup = nullptr;
    }
    cResource* t6 = sArchiveManager::getInstance()->createRes("game_common", "RES_ID_TUTO_QUEST_GROUP", 1u, false);
    if (t6 != nullptr) {
        mpTutoQuestGroup = static_cast<rTutorialQuestGroup*>(t6);
        t6->addRef();
        t6->release();
        return;
    }
}

__attribute__((weak)) void cQuestResourceManager::releaseQuestResource() {
    DDON_STUB("cQuestResourceManager::releaseQuestResource")
    /* stub */
}

cQuestResourceManager::cQuestResourceManager() {
    DDON_STUB("cQuestResourceManager::cQuestResourceManager")
    /* stub */
}

__attribute__((noinline)) cQuestResourceManager::~cQuestResourceManager() {
    DDON_STUB("cQuestResourceManager::~cQuestResourceManager")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::createProperty(MtPropertyList& s) {
}

inline cQuestResourceManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestResourceManager::MyDTI cQuestResourceManager::DTI("cQuestResourceManager", &::cQuestFunctionManagerBase::DTI, 1744ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestResourceManager::MyDTI::newInstance() const {
    DDON_STUB("cQuestResourceManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestResourceManager::cQuestResource::getDTI() const {
    return cQuestResourceManager::cQuestResource::DTI;
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::cQuestResource::getRewardName() const {
    DDON_STUB("cQuestResourceManager::cQuestResource::getRewardName")
    return {};
}

__attribute__((weak)) MT_CTSTR cQuestResourceManager::cQuestResource::getOrderMsg() const {
    DDON_STUB("cQuestResourceManager::cQuestResource::getOrderMsg")
    return {};
}

__attribute__((weak)) u32 cQuestResourceManager::cQuestResource::getPriority() const {
    DDON_STUB("cQuestResourceManager::cQuestResource::getPriority")
    return {};
}

__attribute__((weak)) void cQuestResourceManager::cQuestResource::init(nQuest::QUEST_ID questId) {
    DDON_STUB("cQuestResourceManager::cQuestResource::init")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::cQuestResource::loadResource() {
    DDON_STUB("cQuestResourceManager::cQuestResource::loadResource")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::cQuestResource::loadMessageData() {
    DDON_STUB("cQuestResourceManager::cQuestResource::loadMessageData")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::cQuestResource::loadExmineData() {
    DDON_STUB("cQuestResourceManager::cQuestResource::loadExmineData")
    /* stub */
}

__attribute__((noinline)) cQuestResourceManager::cQuestResource::~cQuestResource() {
    if (mpQuestText != nullptr) {
        mpQuestText->release();
        mpQuestText = nullptr;
    }
    if (mpQuestTextDetail != nullptr) {
        mpQuestTextDetail->release();
        mpQuestTextDetail = nullptr;
    }
    if (mpPawnQuestTalk != nullptr) {
        mpPawnQuestTalk->release();
        mpPawnQuestTalk = nullptr;
    }
    if (mpQuestMessageData != nullptr) {
        delete mpQuestMessageData;
        mpQuestMessageData = nullptr;
    }
    if (mpQuestExmineData != nullptr) {
        delete mpQuestExmineData;
        mpQuestExmineData = nullptr;
        cArcLoaderBase* const t4 = sArchiveManager::INVALID_TICKET;
        if (mArcTicket != t4) {
            sArchiveManager::getInstance()->returnTicket(mArcTicket);
            mArcTicket = t4;
        }
    } else {
        cArcLoaderBase* const t4 = sArchiveManager::INVALID_TICKET;
        if (mArcTicket != t4) {
            sArchiveManager::getInstance()->returnTicket(mArcTicket);
            mArcTicket = t4;
        }
    }
}

__attribute__((weak)) void cQuestResourceManager::cQuestResource::createProperty(MtPropertyList& s) {
}

inline cQuestResourceManager::cQuestResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestResourceManager::cQuestResource::MyDTI cQuestResourceManager::cQuestResource::DTI("cQuestResourceManager::cQuestResource", &::MtObject::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestResourceManager::cQuestResource::MyDTI::newInstance() const {
    DDON_STUB("cQuestResourceManager::cQuestResource::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestResourceManager::cQuestContentResource::getDTI() const {
    return cQuestResourceManager::cQuestContentResource::DTI;
}

__attribute__((weak)) void cQuestResourceManager::cQuestContentResource::initContentCategory(u32 ContentCategory, u32 ContentSubCategory) {
    DDON_STUB("cQuestResourceManager::cQuestContentResource::initContentCategory")
    /* stub */
}

__attribute__((weak)) void cQuestResourceManager::cQuestContentResource::loadResource() {
    DDON_STUB("cQuestResourceManager::cQuestContentResource::loadResource")
    /* stub */
}

cQuestResourceManager::cQuestContentResource::~cQuestContentResource() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicket);
        mArcTicket = t0;
    }
    if (mpCycleQuestInfo == nullptr) {
        return;
    }
    mpCycleQuestInfo->release();
    mpCycleQuestInfo = nullptr;
}

__attribute__((weak)) void cQuestResourceManager::cQuestContentResource::createProperty(MtPropertyList& s) {
}

inline cQuestResourceManager::cQuestContentResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestResourceManager::cQuestContentResource::MyDTI cQuestResourceManager::cQuestContentResource::DTI("cQuestResourceManager::cQuestContentResource", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cQuestResourceManager::cQuestContentResource::MyDTI::newInstance() const {
    return new (16u) cQuestResourceManager::cQuestContentResource;
}

template MtTypedArray<cQuestResourceManager::cQuestContentResource>::~MtTypedArray();

template MtTypedArray<cQuestResourceManager::cQuestResource>::~MtTypedArray();

