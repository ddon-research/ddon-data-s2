// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include <string.h>
#include "uCharacterEdit.h"
#include "Protocol/PacketData/Character.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "cCharacterData.h"
#include "cComponentManager.h"
#include "cDelegate.h"
#include "cEditChargeInfoUpdator.h"
#include "cEditParam.h"
#include "cEfcHandle.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "../../XFramework/cResource.h"
#include "cStageEpvCtrl.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpCharacterEdit.h"
#include "cpComponent.h"
#include "cpEquip.h"
#include "nCharacterData.h"
#include "nCharacterEdit.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "../../generated/shared/nHuman.h"
#include "nHumanMsg.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "rCharacterEdit.h"
#include "rCharacterEditCameraParam.h"
#include "rEditStageParam.h"
#include "rEffectProvider.h"
#include "rEquipPreset.h"
#include "rEquipPresetPalette.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/rScheduler.h"
#include "rSndPitchLimit.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSoundReverb.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "rWeatherInfo.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sChat.h"
#include "sContextManager.h"
#include "sDialogBase.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "sItemManager.h"
#include "../../XFramework/sKeyboard.h"
#include "sLightExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sResource.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sUnitManager.h"
#include "sWeatherManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCamera.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEditSaveLoadFlow.h"
#include "../../XFramework/uFreeCamera.h"
#include "uGUIBase.h"
#include "uGUICharaEditPartsWrap.h"
#include "uGUICharacterEdit.h"
#include "uGUICharacterEditPopCard.h"
#include "uGUIGPShop.h"
#include "uGUIJobSelect.h"
#include "uGUISystemMsg.h"
#include "uGUIsMenuBase.h"
#include "uMockUpModel.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uScheduler.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const u32 reqPLTbl[7] = {
    3,
    13,
    23,
    33,
    53,
    63,
    73,
};

static const u32 reqPawnTbl[3] = {
    1,
    15,
    30,
};

const MtDTI& cEditParamList::getDTI() const {
    return cEditParamList::DTI;
}

inline cEditParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEditParamList::MyDTI cEditParamList::DTI("cEditParamList", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEditParamList::MyDTI::newInstance() const {
    return new (16u) cEditParamList;
}

const MtDTI& cUndoData::getDTI() const {
    return cUndoData::DTI;
}

cUndoData::~cUndoData() {
    if (mpEditParam == nullptr) {
        return;
    }
    delete mpEditParam;
    mpEditParam = nullptr;
}

inline cUndoData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUndoData::MyDTI cUndoData::DTI("cUndoData", &::MtObject::DTI, 168ul, 0u, 0u);

__attribute__((weak)) MtObject* cUndoData::MyDTI::newInstance() const {
    DDON_STUB("cUndoData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCharacterEdit::getDTI() const {
    return uCharacterEdit::DTI;
}

void* uCharacterEdit::operator new(size_t sz, u32 align) {
    return uCharacterEdit::getAllocator()->memAlloc(sz, align, uCharacterEdit::DTI.getID());
}

uCharacterEdit::uCharacterEdit() {
    DDON_STUB("uCharacterEdit::uCharacterEdit")
    /* stub */
}

__attribute__((noinline)) uCharacterEdit::~uCharacterEdit() {
    DDON_STUB("uCharacterEdit::~uCharacterEdit")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::createProperty(MtPropertyList& s) {
}

MtUI* uCharacterEdit::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uCharacterEdit::updatePtr() {
    this->uCharacterEditBase::updatePtr();
    if (mpGUIEdit != nullptr) {
        if (!mpGUIEdit->isEnable()) {
            mpGUIEdit = nullptr;
        }
    }
    if (mpGUIJob != nullptr) {
        if (!mpGUIJob->isEnable()) {
            mpGUIJob = nullptr;
        }
    }
    if (mpGUICard != nullptr) {
        if (!mpGUICard->isEnable()) {
            mpGUICard = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mpGUIGoldStonShop != nullptr) {
        if (!mpGUIGoldStonShop->isEnable()) {
            mpGUIGoldStonShop = nullptr;
        }
    }
    if (mpSaveLoadFlow != nullptr) {
        if (!mpSaveLoadFlow->isEnable()) {
            mpSaveLoadFlow = nullptr;
        }
    }
}

void uCharacterEdit::release() {
    if (mpGUIEdit != nullptr) {
        mpGUIEdit->mEndType = 0;
        mpGUIEdit->end();
    }
    mpGUIEdit = nullptr;
    if (mpGUIJob != nullptr) {
        mpGUIJob->mEndType = 0;
        mpGUIJob->end();
    }
    mpGUIJob = nullptr;
    if (mpGUICard != nullptr) {
        mpGUICard->mEndType = 0;
        mpGUICard->end();
    }
    mpGUICard = nullptr;
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->mEndType = 0;
        mpGUISystemMsg->end();
    }
    mpGUISystemMsg = nullptr;
    if (mpGUIGoldStonShop != nullptr) {
        mpGUIGoldStonShop->mEndType = 0;
        mpGUIGoldStonShop->end();
    }
    mpGUIGoldStonShop = nullptr;
    if (mpCompareEditParam != nullptr) {
        delete mpCompareEditParam;
        mpCompareEditParam = nullptr;
    }
    if (mpSaveLoadFlow != nullptr) {
        mpSaveLoadFlow->kill();
        mpSaveLoadFlow = nullptr;
    }
    if (mpEquipPresetPalette != nullptr) {
        mpEquipPresetPalette->release();
        mpEquipPresetPalette = nullptr;
    }
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicketEdit != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicketEdit);
        mArcTicketEdit = t0;
    }
    this->uCharacterEditBase::release();
}

void uCharacterEdit::setup() {
    this->cUnit::setup();
    static_cast<sUnitExt*>(sUnit::getInstance())->mIsUseCommandCache = false;
    sUnit::getInstance()->mbDrawCommandCacheEnableUpdate = false;
    sResource::getInstance()->mForceVramMemory = true;
    sRender::getInstance()->setRenderDetailControl(false);
    if (mEdit == nGUIExt::CHARA_EDIT_PLAYER) {
        sCamera::getInstance()->mBGColor.rgba = MtColor::White.rgba;
        sGame::getInstance()->fadeOut(0.0f, 1u);
    }
    u32 i = 0;
    u32 v1_0;
    unsigned int i1_9;
    u32 v2_0;
    for (;;) {
        if (mCategporyParamListArray.elems[i].mLength != 0) {
            v1_0 = mCategporyParamListArray.elems[i].mLength;
            i1_9 = 0;
            for (;;) {
                if (mCategporyParamListArray.elems[i].mpArray[i1_9] == nullptr) {
                    v2_0 = v1_0;
                } else {
                    delete mCategporyParamListArray.elems[i].mpArray[i1_9];
                    v2_0 = mCategporyParamListArray.elems[i].mLength;
                }
                if ((i1_9 + 1u) < v2_0) {
                    v1_0 = v2_0;
                    i1_9 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mCategporyParamListArray.elems[i].mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCategporyParamListArray.elems[i].mpArray));
        }
        mCategporyParamListArray.elems[i].mpArray = nullptr;
        mCategporyParamListArray.elems[i].mBufsiz = 0;
        mCategporyParamListArray.elems[i].mLength = 0;
        if ((i + 1u) != 17) {
            i = i + 1u;
        } else {
            break;
        }
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->reqChatNActive(true, true);
    mIsDefaultUseWindowActive = static_cast<sGUIExt*>(sGUI::getInstance())->isUseWindowActive();
    static_cast<sGUIExt*>(sGUI::getInstance())->mIsUseWindowActive = true;
}

void uCharacterEdit::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    release();
    static_cast<sUnitExt*>(sUnit::getInstance())->mIsUseCommandCache = true;
    sUnit::getInstance()->mbDrawCommandCacheEnableUpdate = true;
    sResource::getInstance()->mForceVramMemory = false;
    static_cast<sGUIExt*>(sGUI::getInstance())->setChatForbid(false);
    if (sChat::getInstance()->checkChatOk()) {
        static_cast<sGUIExt*>(sGUI::getInstance())->setChatAlpha(1.0f);
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->mIsUseWindowActive = mIsDefaultUseWindowActive;
}

bool uCharacterEdit::moveLoadArc() {
    bool t0 = this->uCharacterEditBase::moveLoadArc();
    if (mEditLoadRno != EDIT_LOAD_ARC_END) {
        if (mEditLoadRno == EDIT_LOAD_ARC_WAIT) {
            if (t0) {
                if (sArchiveManager::getInstance()->isTicketLoadFinish(mArcTicketEdit)) {
                    mEditLoadRno = EDIT_LOAD_ARC_END;
                }
            }
        } else {
            if (mEditLoadRno == EDIT_LOAD_ARC_INIT) {
                TICKET t1 = sArchiveManager::getInstance()->IssueTicket();
                mArcTicketEdit = t1;
                sArchiveManager* t2 = sArchiveManager::getInstance();
                t2->addTagEx(t1, rArchiveListArray::convTagId("character_edit"));
                sArchiveManager::getInstance()->attestationTicket(mArcTicketEdit);
                mEditLoadRno = EDIT_LOAD_ARC_WAIT;
                if (mEdit != nGUIExt::CHARA_EDIT_PLAYER) {
                    sFlag::getInstance()->setFlag(6u, 12u, true, true, false);
                }
                return false;
            }
        }
        if (mEdit != nGUIExt::CHARA_EDIT_PLAYER) {
            sFlag::getInstance()->setFlag(6u, 12u, true, true, false);
        }
        return false;
    } else {
        return true;
    }
}

__attribute__((weak)) void uCharacterEdit::moveLoadUnit() {
    DDON_STUB("uCharacterEdit::moveLoadUnit")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::moveMain() {
    DDON_STUB("uCharacterEdit::moveMain")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::moveEnd() {
}

__attribute__((weak)) uCharacterEdit::CHARA_REGIST_RESULT uCharacterEdit::charaRegistPlayer() {
    DDON_STUB("uCharacterEdit::charaRegistPlayer")
    return {};
}

uCharacterEdit::CHARA_REGIST_RESULT uCharacterEdit::charaRegistInGame() {
    switch (mCharaRegistRno) {
        case REGIST_ROUTINE_SETUP:
        {
            if (mpEditRes != nullptr) {
                if (mpEditRes->mpEditParam != nullptr) {
                    if (mpEditData != nullptr) {
                        mpEditRes->mpEditParam->copyToCharacterData(&mpEditData->mCharacterEdit);
                        cCharacterData::stPawnData* t0 = mpEditData;
                        t0->mCharacterEdit.mName.clearName();
                        snprintf(&t0->mCharacterEdit.mName.mFirstName[0], 13ul, "%s", &mName.mFirstName[0]);
                        snprintf(&t0->mCharacterEdit.mName.mLastName[0], 9ul, "%s", &mName.mLastName[0]);
                        cCharacterData::stPawnData* t1 = mpEditData;
                        t1->mCharacterEdit.mSex = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3648);
                        unsigned char t2 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 176);
                        t1->mCurrentJob = t2;
                        if (static_cast<unsigned int>(mEdit - 3) > 1) {
                            t1->mShareRange = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 624);
                            sItemManager::getInstance()->setJobEquip(t1->mEquipData, t2);
                            if (mEdit != nGUIExt::CHARA_EDIT_BEAUTY_PARLOR_PAWN) {
                                if (mEdit == nGUIExt::CHARA_EDIT_BEAUTY_PARLOR_PLAYER) {
                                    mCharaRegistRno = REGIST_ROUTINE_PLAYER_SALON_REQ_SV;
                                    return REGIST_RESULT_NONE;
                                } else {
                                    if (mEdit == nGUIExt::CHARA_EDIT_PAWN) {
                                        mCharaRegistRno = REGIST_ROUTINE_REQ_SV;
                                        return REGIST_RESULT_NONE;
                                    } else {
                                        return REGIST_RESULT_ERROR;
                                    }
                                }
                            } else {
                                mCharaRegistRno = REGIST_ROUTINE_PAWN_SALON_REQ_SV;
                                return REGIST_RESULT_NONE;
                            }
                        } else {
                            sItemManager::getInstance()->setJobEquip(t1->mEquipData, t2);
                            if (mEdit != nGUIExt::CHARA_EDIT_BEAUTY_PARLOR_PAWN) {
                                if (mEdit == nGUIExt::CHARA_EDIT_BEAUTY_PARLOR_PLAYER) {
                                    mCharaRegistRno = REGIST_ROUTINE_PLAYER_SALON_REQ_SV;
                                    return REGIST_RESULT_NONE;
                                } else {
                                    if (mEdit == nGUIExt::CHARA_EDIT_PAWN) {
                                        mCharaRegistRno = REGIST_ROUTINE_REQ_SV;
                                        return REGIST_RESULT_NONE;
                                    } else {
                                        return REGIST_RESULT_ERROR;
                                    }
                                }
                            } else {
                                mCharaRegistRno = REGIST_ROUTINE_PAWN_SALON_REQ_SV;
                                return REGIST_RESULT_NONE;
                            }
                        }
                    } else {
                        return REGIST_RESULT_ERROR;
                    }
                } else {
                    return REGIST_RESULT_ERROR;
                }
            } else {
                return REGIST_RESULT_ERROR;
            }
            break;
        }
        case REGIST_ROUTINE_REQ_SV:
        {
            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->createMyPawn(getSlotNo(), mpEditData);
            mCharaRegistRno = REGIST_ROUTINE_WAIT_SV;
            return REGIST_RESULT_NONE;
        }
        case REGIST_ROUTINE_WAIT_SV:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[58] != sNetworkExt::NET_STAT_ERROR) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[58] == sNetworkExt::NET_STAT_CANCEL) {
                    mCharaRegistRno = REGIST_ROUTINE_END;
                    return REGIST_RESULT_CANCEL;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[58] == sNetworkExt::NET_STAT_SUCCESS) {
                        mCharaRegistRno = REGIST_ROUTINE_END;
                        return REGIST_RESULT_SUCCESS;
                    } else {
                        return REGIST_RESULT_NONE;
                    }
                }
            } else {
                mCharaRegistRno = REGIST_ROUTINE_ERROR_DIALOG;
                return REGIST_RESULT_NONE;
            }
            break;
        }
        case REGIST_ROUTINE_PLAYER_SALON_REQ_SV:
        {
            if ((mSalonChargeFlag & 0x40000000u) == 0) {
                if ((((mSalonChargeFlag & 1u) == 0) ? (getSalonChargeFlag() & 2u) : static_cast<unsigned int>(((mSalonChargeFlag & 3u) == 3) ? 3 : 1)) != 0) {
                    if (mpEditRes != nullptr) {
                        if (mpEditRes->mpEditParam != nullptr) {
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->updateCharacterEditInfo(static_cast<unsigned char>(((mSalonChargeFlag & 1u) == 0) ? (getSalonChargeFlag() & 2u) : static_cast<unsigned int>(((mSalonChargeFlag & 3u) == 3) ? 3 : 1)), mpEditData->mCharacterEdit, *mpEditRes->mpEditParam);
                            mCharaRegistRno = REGIST_ROUTINE_PLAYER_SALON_WAIT_SV;
                            return REGIST_RESULT_NONE;
                        } else {
                            return REGIST_RESULT_ERROR;
                        }
                    } else {
                        return REGIST_RESULT_ERROR;
                    }
                } else {
                    mCharaRegistRno = REGIST_ROUTINE_END;
                    return REGIST_RESULT_SUCCESS;
                }
            } else {
                mCharaRegistRno = REGIST_ROUTINE_END;
                return REGIST_RESULT_SUCCESS;
            }
            break;
        }
        case REGIST_ROUTINE_PLAYER_SALON_WAIT_SV:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[477] != sNetworkExt::NET_STAT_ERROR) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[477] == sNetworkExt::NET_STAT_CANCEL) {
                    mCharaRegistRno = REGIST_ROUTINE_END;
                    return REGIST_RESULT_CANCEL;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[477] == sNetworkExt::NET_STAT_SUCCESS) {
                        mCharaRegistRno = REGIST_ROUTINE_END;
                        return REGIST_RESULT_SUCCESS;
                    } else {
                        return REGIST_RESULT_NONE;
                    }
                }
            } else {
                mCharaRegistRno = REGIST_ROUTINE_ERROR_DIALOG;
                return REGIST_RESULT_NONE;
            }
            break;
        }
        case REGIST_ROUTINE_PAWN_SALON_REQ_SV:
        {
            if ((mSalonChargeFlag & 0x40000000u) == 0) {
                if ((((mSalonChargeFlag & 1u) == 0) ? (getSalonChargeFlag() & 2u) : static_cast<unsigned int>(((mSalonChargeFlag & 3u) == 3) ? 3 : 1)) != 0) {
                    if (mpEditRes != nullptr) {
                        if (mpEditRes->mpEditParam != nullptr) {
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->updatePawnEditInfo(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5120), static_cast<unsigned char>(((mSalonChargeFlag & 1u) == 0) ? (getSalonChargeFlag() & 2u) : static_cast<unsigned int>(((mSalonChargeFlag & 3u) == 3) ? 3 : 1)), mpEditData->mCharacterEdit, *mpEditRes->mpEditParam);
                            mCharaRegistRno = REGIST_ROUTINE_PAWN_SALON_WAIT_SV;
                            return REGIST_RESULT_NONE;
                        } else {
                            return REGIST_RESULT_ERROR;
                        }
                    } else {
                        return REGIST_RESULT_ERROR;
                    }
                } else {
                    mCharaRegistRno = REGIST_ROUTINE_END;
                    return REGIST_RESULT_SUCCESS;
                }
            } else {
                mCharaRegistRno = REGIST_ROUTINE_END;
                return REGIST_RESULT_SUCCESS;
            }
            break;
        }
        case REGIST_ROUTINE_PAWN_SALON_WAIT_SV:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[478] != sNetworkExt::NET_STAT_ERROR) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[478] == sNetworkExt::NET_STAT_CANCEL) {
                    mCharaRegistRno = REGIST_ROUTINE_END;
                    return REGIST_RESULT_CANCEL;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[478] == sNetworkExt::NET_STAT_SUCCESS) {
                        mCharaRegistRno = REGIST_ROUTINE_END;
                        return REGIST_RESULT_SUCCESS;
                    } else {
                        return REGIST_RESULT_NONE;
                    }
                }
            } else {
                mCharaRegistRno = REGIST_ROUTINE_ERROR_DIALOG;
                return REGIST_RESULT_NONE;
            }
            break;
        }
        case REGIST_ROUTINE_ERROR_DIALOG:
        {
            if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
                mCharaRegistRno = REGIST_ROUTINE_END;
                return REGIST_RESULT_FAILED;
            } else {
                return REGIST_RESULT_NONE;
            }
            break;
        }
        default:
        {
            return REGIST_RESULT_NONE;
        }
    }
}

__attribute__((weak)) uCharacterEdit::GOLD_STONE_RESULT uCharacterEdit::checkGoldStone() {
    DDON_STUB("uCharacterEdit::checkGoldStone")
    return {};
}

__attribute__((weak)) bool uCharacterEdit::checkGoldStoneSaveMove() {
    switch (mSaveLoadRno) {
        case EDIT_SAVE_LOAD_ROUTINE_INIT:
        {
            if (mpSaveLoadFlow != nullptr) {
                mpSaveLoadFlow->kill();
                mpSaveLoadFlow = nullptr;
            }
            mpSaveLoadFlow = new (16u) uEditSaveLoadFlow;
            if (mpSaveLoadFlow == nullptr) {
                return true;
            }
            const cEditParam* pEditParam = getEditParam();
            if (pEditParam == nullptr) {
                return true;
            }
            mpSaveLoadFlow->setCharacterEdit(this);
            mpSaveLoadFlow->setGmdDialog(mpGmdDialog);
            mpSaveLoadFlow->startSaveLoad(nEditSaveLoadFlow::MODE_SAVE);
            MT_CTSTR firstName = mName.mFirstName;
            MT_CTSTR lastName = mName.mLastName;
            s32 bodyType = pEditParam->mBodyType;
            mpSaveLoadFlow->setCharaInfo(bodyType, firstName, lastName);
            sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(sUnitExt::ML_UI_AREA1), mpSaveLoadFlow, sUnitExt::GPT_UI_SUB);
            mSaveLoadRno = EDIT_SAVE_LOAD_ROUTINE_WAIT;
            break;
        }
        case EDIT_SAVE_LOAD_ROUTINE_WAIT:
        {
            if (mpSaveLoadFlow == nullptr) {
                return true;
            }
            if (!mpSaveLoadFlow->isBusy()) {
                mSaveLoadRno = EDIT_SAVE_LOAD_ROUTINE_END;
            }
            break;
        }
        case EDIT_SAVE_LOAD_ROUTINE_END:
        {
            return true;
        }
        default:
        {
            break;
        }
    }
    return false;
}

__attribute__((weak)) void uCharacterEdit::setModel(bool isAction) {
    DDON_STUB("uCharacterEdit::setModel")
    /* stub */
}

void uCharacterEdit::requestVoice() {
    if (mpCharacterEdit == nullptr) {
        return;
    }
    if (mpEditRes == nullptr) {
        return;
    }
    if (mpEditRes->mpEditParam == nullptr) {
        return;
    }
    switch (static_cast<unsigned int>(mEdit - 1)) {
        case 0:
        {
            if (mpCharacterEdit->getVoiceRes() != nullptr) {
                if (mConThisId != 0) {
                    sSound::getInstance()->stopSe(mpCharacterEdit->getVoiceRes(), reqPLTbl[mVoiceReqNoOld], mConThisId, false);
                    mConThisId = 0;
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                } else {
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                }
            } else {
                mIsVoiceCallReq = true;
                mpCharacterEdit->requestArcLoad(8u);
            }
            break;
        }
        case 1:
        {
            if (mpCharacterEdit->getVoiceStreamRes() != nullptr) {
                if (mConThisId != 0) {
                    static_cast<sSoundExt*>(sSound::getInstance())->stopStream(mpCharacterEdit->getVoiceStreamRes(), reqPawnTbl[mVoiceReqNoOld], mConThisId, sSoundExt::STREAM_SEARCH_KEY_RESOURCE_REQNO);
                    mConThisId = 0;
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                } else {
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                }
            } else {
                mIsVoiceCallReq = true;
                mpCharacterEdit->requestArcLoad(8u);
            }
            break;
        }
        case 2:
        {
            if (mpCharacterEdit->getVoiceRes() != nullptr) {
                if (mConThisId != 0) {
                    sSound::getInstance()->stopSe(mpCharacterEdit->getVoiceRes(), reqPLTbl[mVoiceReqNoOld], mConThisId, false);
                    mConThisId = 0;
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                } else {
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                }
            } else {
                mIsVoiceCallReq = true;
                mpCharacterEdit->requestArcLoad(8u);
            }
            break;
        }
        case 3:
        {
            if (mpCharacterEdit->getVoiceStreamRes() != nullptr) {
                if (mConThisId != 0) {
                    static_cast<sSoundExt*>(sSound::getInstance())->stopStream(mpCharacterEdit->getVoiceStreamRes(), reqPawnTbl[mVoiceReqNoOld], mConThisId, sSoundExt::STREAM_SEARCH_KEY_RESOURCE_REQNO);
                    mConThisId = 0;
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                } else {
                    mIsVoiceCallReq = true;
                    mpCharacterEdit->requestArcLoad(8u);
                }
            } else {
                mIsVoiceCallReq = true;
                mpCharacterEdit->requestArcLoad(8u);
            }
            break;
        }
        default:
        {
            mIsVoiceCallReq = true;
            mpCharacterEdit->requestArcLoad(8u);
            break;
        }
    }
}

void uCharacterEdit::stopVoice() {
    switch (static_cast<unsigned int>(mEdit - 1)) {
        case 0:
        {
            if (mpCharacterEdit->getVoiceRes() != nullptr) {
                if (mConThisId != 0) {
                    sSound::getInstance()->stopSe(mpCharacterEdit->getVoiceRes(), reqPLTbl[mVoiceReqNoOld], mConThisId, false);
                    mConThisId = 0;
                }
            }
            break;
        }
        case 1:
        {
            if (mpCharacterEdit->getVoiceStreamRes() != nullptr) {
                if (mConThisId != 0) {
                    static_cast<sSoundExt*>(sSound::getInstance())->stopStream(mpCharacterEdit->getVoiceStreamRes(), reqPawnTbl[mVoiceReqNoOld], mConThisId, sSoundExt::STREAM_SEARCH_KEY_RESOURCE_REQNO);
                    mConThisId = 0;
                }
            }
            break;
        }
        case 2:
        {
            if (mpCharacterEdit->getVoiceRes() != nullptr) {
                if (mConThisId != 0) {
                    sSound::getInstance()->stopSe(mpCharacterEdit->getVoiceRes(), reqPLTbl[mVoiceReqNoOld], mConThisId, false);
                    mConThisId = 0;
                }
            }
            break;
        }
        case 3:
        {
            if (mpCharacterEdit->getVoiceStreamRes() != nullptr) {
                if (mConThisId != 0) {
                    static_cast<sSoundExt*>(sSound::getInstance())->stopStream(mpCharacterEdit->getVoiceStreamRes(), reqPawnTbl[mVoiceReqNoOld], mConThisId, sSoundExt::STREAM_SEARCH_KEY_RESOURCE_REQNO);
                    mConThisId = 0;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void uCharacterEdit::callbackSetupVoice() {
    DDON_STUB("uCharacterEdit::callbackSetupVoice")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeMotion(bool isActionEnd) {
    DDON_STUB("uCharacterEdit::changeMotion")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeSCR() {
    DDON_STUB("uCharacterEdit::changeSCR")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeCoordinate(bool force) {
    DDON_STUB("uCharacterEdit::changeCoordinate")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeEquip() {
    DDON_STUB("uCharacterEdit::changeEquip")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeBodyPreset() {
    DDON_STUB("uCharacterEdit::changeBodyPreset")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeTypeSex() {
    DDON_STUB("uCharacterEdit::changeTypeSex")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::changeFaceAnime(bool increment) {
    DDON_STUB("uCharacterEdit::changeFaceAnime")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::managedFaceAnime() {
    DDON_STUB("uCharacterEdit::managedFaceAnime")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::setCharName(CHAR_NAME& name) {
    DDON_STUB("uCharacterEdit::setCharName")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::setFirstName(MT_CTSTR str) {
    DDON_STUB("uCharacterEdit::setFirstName")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::setLastName(MT_CTSTR str) {
    DDON_STUB("uCharacterEdit::setLastName")
    /* stub */
}

cEditParam* uCharacterEdit::getEditParam() {
    if (mpEditRes != nullptr) {
        return mpEditRes->mpEditParam;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uCharacterEdit::registerRedoUndo(nCharacterEdit::EDIT_TYPE type) {
    DDON_STUB("uCharacterEdit::registerRedoUndo")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::resetRedoUndo() {
    DDON_STUB("uCharacterEdit::resetRedoUndo")
    /* stub */
}

void uCharacterEdit::applyRedoUndo(cUndoData& data, bool isUndo) {
    mBodyType = data.mBodyType;
    mNeedBodyPreset = data.mNeedBodyPreset;
    if (data.mEdit == nCharacterEdit::EDIT_TYPE_REDOUNDO_INIT) {
        initEdit(true);
        if (mpGUIEdit != nullptr) {
            mpGUIEdit->callbackApplyUndoRedo(data, isUndo);
        }
    } else {
        if (data.mEdit == nCharacterEdit::EDIT_TYPE_PRISET) {
            changeBodyPreset();
            if (mpGUIEdit != nullptr) {
                mpGUIEdit->callbackApplyUndoRedo(data, isUndo);
            }
        } else {
            cEditParam* t0 = data.mpEditParam;
            if (t0 != nullptr) {
                if (mpEditRes != nullptr) {
                    if (mpEditRes->mpEditParam != nullptr) {
                        mpEditRes->mpEditParam->copy(t0, true);
                        if (mpCompareEditParam != nullptr) {
                            if (cGUIUtility::isSalon(mEdit)) {
                                mpCompareEditParam->copy(t0, false);
                                searchDiffEditParam(mPalorParam.mpEditParam, true);
                            }
                        }
                    }
                }
            }
            if (mpGUIEdit != nullptr) {
                mpGUIEdit->callbackApplyUndoRedo(data, isUndo);
            }
        }
    }
}

__attribute__((weak)) void uCharacterEdit::execUndo() {
    DDON_STUB("uCharacterEdit::execUndo")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::execRedo() {
    DDON_STUB("uCharacterEdit::execRedo")
    /* stub */
}

bool uCharacterEdit::isAbleUndo() const {
    return mUndoNowMax > 1;
}

bool uCharacterEdit::isAbleRedo() const {
    return mUndoNowMax < mUndoMax;
}

void uCharacterEdit::lockCameraMove() {
    if (mpCamera == nullptr) {
        return;
    }
    mpCamera->mIsLock = true;
}

__attribute__((weak)) void uCharacterEdit::changeShape(nCharacterEdit::EDIT_TYPE type, f32 value, s32 ev, MtObject* pPartsPointer, bool isRegistRedoUndo) {
    DDON_STUB("uCharacterEdit::changeShape")
    /* stub */
}

__attribute__((weak)) void uCharacterEdit::loadEditData(const cStorageDataEdit& strageData) {
    DDON_STUB("uCharacterEdit::loadEditData")
    /* stub */
}

void uCharacterEdit::randamFace() {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->mpCharacterEdit == nullptr) {
        return;
    }
    if (mpEditRes != nullptr) {
        if (mpEditRes->mpEditParam != nullptr) {
            mpEditRes->mpEditParam->mRandomRangeFace = 0.0f;
        }
    }
    mpModel->mpCharacterEdit->randomFace();
    mpModel->mpCharacterEdit->mUpdateAllReq = true;
    if (mpEditRes != nullptr) {
        cEditParam* t0 = mpEditRes->mpEditParam;
        if (t0 != nullptr) {
            if (mpCompareEditParam != nullptr) {
                if (cGUIUtility::isSalon(mEdit)) {
                    mpCompareEditParam->copy(t0, false);
                    searchDiffEditParam(mPalorParam.mpEditParam, true);
                }
            }
        }
        registerRedoUndo(nCharacterEdit::EDIT_TYPE_REDOUNDO_RANDOM);
    } else {
        registerRedoUndo(nCharacterEdit::EDIT_TYPE_REDOUNDO_RANDOM);
    }
}

__attribute__((weak)) void uCharacterEdit::initEdit(bool isAction) {
    DDON_STUB("uCharacterEdit::initEdit")
    /* stub */
}

void uCharacterEdit::updatePartsAll() {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->mpCharacterEdit == nullptr) {
        return;
    }
    mpModel->mpCharacterEdit->mUpdateAllReq = true;
}

s32 uCharacterEdit::getEditParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam) {
    MtProperty prop(getPropertyEditParameter(type, pParam));
    if (prop.mType <= 12u) {
        if (((5184ul >> static_cast<unsigned long>(prop.mType & 31u)) & 1ul) != 0) {
            return prop.getS32();
        }
    }
    return -10;
}

__attribute__((weak)) MtProperty uCharacterEdit::getPropertyEditParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam) {
    DDON_STUB("uCharacterEdit::getPropertyEditParameter")
    __builtin_unreachable();
}

__attribute__((weak)) cEditValue* uCharacterEdit::getEditValueParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam) {
    DDON_STUB("uCharacterEdit::getEditValueParameter")
    return nullptr;
}

__attribute__((weak)) f32 uCharacterEdit::getEditValue(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam) {
    DDON_STUB("uCharacterEdit::getEditValue")
    return {};
}

void uCharacterEdit::setCharacterData(cCharacterData* pData) {
    mpCharData = pData;
}

__attribute__((weak)) void uCharacterEdit::setJobEquip(nCharacterData::stEquipData& Data, u8 job) {
    DDON_STUB("uCharacterEdit::setJobEquip")
    /* stub */
}

void uCharacterEdit::setSlotNo(s32 slotNo) {
    mSlotNo = slotNo;
}

void uCharacterEdit::setEditPawnData(cCharacterData::stPawnData* pData) {
    mpEditData = pData;
}

bool uCharacterEdit::isChargedVoiceData(u32 voiceType, u32 voiceUID) const {
    u32 length = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPawnVoiceList.mLength;
    if (length != 0) {
        MtObject* * v0_4 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPawnVoiceList.mpArray;
        for (u32 i = 0;;) {
            if (v0_4[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 8)) == voiceType) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 12)) == voiceUID) {
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_4[i]) + 16)) != 0) {
                            return true;
                        }
                    }
                }
            }
            if ((i + 1u) < length) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

void uCharacterEdit::setParlorEditParam(cEditParam* p) {
    if (p == nullptr) {
        return;
    }
    if (mPalorParam.mpEditParam == nullptr) {
        return;
    }
    mPalorParam.mpEditParam->copy(p, false);
}

__attribute__((weak)) nCharacterEdit::EDIT_UPDATE_FLAG uCharacterEdit::getChageNeed(nCharacterEdit::EDIT_TYPE type) const {
    DDON_STUB("uCharacterEdit::getChageNeed")
    return {};
}

void uCharacterEdit::saveStageIconInfo(const nCharacterEdit::stStageIconCash& info, u32 index) {
    mStageEquipChash.mStageIconCash.elems[(index <= 11u) ? index : 0u].mIsLeft = info.mIsLeft;
    mStageEquipChash.mIsSaved = true;
}

__attribute__((weak)) void uCharacterEdit::saveEquipIconInfo(nCharacterEdit::stEquipIconCash info, u32 index) {
    DDON_STUB("uCharacterEdit::saveEquipIconInfo")
    /* stub */
}

void uCharacterEdit::addCountInitWarn(nCharacterEdit::EDIT_WARN_TYPE category) {
    mInitWarnCount[category] = mInitWarnCount[category] + 1u;
}

__attribute__((weak)) bool uCharacterEdit::isRewardParts(nCharacterEdit::PALETTE palette, u32 partsID) const {
    DDON_STUB("uCharacterEdit::isRewardParts")
    return {};
}

__attribute__((weak)) void uCharacterEdit::loadPaletteNum() {
    DDON_STUB("uCharacterEdit::loadPaletteNum")
    /* stub */
}

__attribute__((weak)) MT_CTSTR uCharacterEdit::getSndPitchSearchName() const {
    DDON_STUB("uCharacterEdit::getSndPitchSearchName")
    return {};
}

__attribute__((weak)) s32 uCharacterEdit::searchDiffEditParam(cEditParam* pParam, bool isChangeReq) {
    DDON_STUB("uCharacterEdit::searchDiffEditParam")
    return {};
}

__attribute__((weak)) u32 uCharacterEdit::checkDiffEditParam(cEditParam* pEditParam, bool isChangeReq) {
    DDON_STUB("uCharacterEdit::checkDiffEditParam")
    return {};
}

__attribute__((weak)) void uCharacterEdit::registerCategoryParamList(s32 category, s32 editType) {
    DDON_STUB("uCharacterEdit::registerCategoryParamList")
    /* stub */
}

void uCharacterEdit::applyStageType() {
    if (static_cast<unsigned int>(mEdit - 3) <= 1) {
        mStageType = 2;
    } else {
        if (mEdit == nGUIExt::CHARA_EDIT_PAWN) {
            mStageType = 1;
        }
    }
}

__attribute__((weak)) uCharacterEditCameraBase* uCharacterEdit::createCamera() {
    DDON_STUB("uCharacterEdit::createCamera")
    return nullptr;
}

__attribute__((weak)) void uCharacterEdit::initEditCommon() {
    DDON_STUB("uCharacterEdit::initEditCommon")
    /* stub */
}

inline uCharacterEdit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterEdit::MyDTI uCharacterEdit::DTI("uCharacterEdit", &::uCharacterEditBase::DTI, 5216ul, 0u, 0u);

__attribute__((weak)) MtObject* uCharacterEdit::MyDTI::newInstance() const {
    DDON_STUB("uCharacterEdit::MyDTI::newInstance")
    return nullptr;
}

uCharacterEdit::cParlorParam::~cParlorParam() {
    if (mpEditParam == nullptr) {
        return;
    }
    delete mpEditParam;
    mpEditParam = nullptr;
}

const MtDTI& uCharacterEditBase::getDTI() const {
    return uCharacterEditBase::DTI;
}

uCharacterEditBase::uCharacterEditBase() {
    DDON_STUB("uCharacterEditBase::uCharacterEditBase")
    /* stub */
}

uCharacterEditBase::~uCharacterEditBase() {
    this->uCharacterEditBase::release();
}

void uCharacterEditBase::setup() {
    this->cUnit::setup();
    static_cast<sUnitExt*>(sUnit::getInstance())->mIsUseCommandCache = false;
    sUnit::getInstance()->mbDrawCommandCacheEnableUpdate = false;
    sResource::getInstance()->mForceVramMemory = true;
    sRender::getInstance()->setRenderDetailControl(false);
}

void uCharacterEditBase::move() {
    mIsComplete = true;
    switch (mMode) {
        case MODE_LOAD_ARC:
        {
            if (moveLoadArc()) {
                mMode = MODE_LOAD_UNIT;
                mProc = 0;
                if (mpModel != nullptr) {
                    mpModel->requestCommandCacheReset();
                }
            } else {
                if (mpModel != nullptr) {
                    mpModel->requestCommandCacheReset();
                }
            }
            break;
        }
        case MODE_LOAD_UNIT:
        {
            moveLoadUnit();
            if (mpModel != nullptr) {
                mpModel->requestCommandCacheReset();
            }
            break;
        }
        case MODE_MAIN:
        {
            moveMain();
            if (mpModel != nullptr) {
                mpModel->requestCommandCacheReset();
            }
            break;
        }
        case MODE_END:
        {
            moveEnd();
            if (mpModel != nullptr) {
                mpModel->requestCommandCacheReset();
            }
            break;
        }
        default:
        {
            if (mpModel != nullptr) {
                mpModel->requestCommandCacheReset();
            }
            break;
        }
    }
}

void uCharacterEditBase::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    release();
    static_cast<sUnitExt*>(sUnit::getInstance())->mIsUseCommandCache = true;
    sUnit::getInstance()->mbDrawCommandCacheEnableUpdate = true;
    sResource::getInstance()->mForceVramMemory = false;
}

__attribute__((weak)) void uCharacterEditBase::updatePtr() {
    if (mpCamera != nullptr) {
        if (!mpCamera->isEnable()) {
            mpCamera = nullptr;
        }
    }
    if (mpModel != nullptr) {
        if (!mpModel->isEnable()) {
            mpModel = nullptr;
        }
    }
    if (mpModelSchl != nullptr) {
        if (!mpModelSchl->isEnable()) {
            mpModelSchl = nullptr;
        }
    }
    if (mpFilterSchl != nullptr) {
        if (!mpFilterSchl->isEnable()) {
            mpFilterSchl = nullptr;
        }
    }
    if (mpLightSchl != nullptr) {
        if (!mpLightSchl->isEnable()) {
            mpLightSchl = nullptr;
        }
    }
    if (mpEffectHandle != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpEffectHandle)) {
            mpEffectHandle->mpOwner = nullptr;
            mpEffectHandle = nullptr;
        }
    }
    mStageEpvCtrl.updatePtr();
}

__attribute__((weak)) void uCharacterEditBase::release() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    cArcLoaderBase* v0_7;
    if (mArcTicketEditCommon != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicketEditCommon);
        mArcTicketEditCommon = t0;
        v0_7 = t0;
    } else {
        v0_7 = mArcTicketEditCommon;
    }
    if (v0_7 != mArcTicketStage) {
        sArchiveManager::getInstance()->returnTicket(mArcTicketStage);
        mArcTicketStage = v0_7;
    }
    if (mpEditStageParam != nullptr) {
        mpEditStageParam->release();
        mpEditStageParam = nullptr;
    }
    if (mpEditRes != nullptr) {
        mpEditRes->release();
        mpEditRes = nullptr;
    }
    if (mpWeatherParam != nullptr) {
        mpWeatherParam->release();
        mpWeatherParam = nullptr;
    }
    if (mpWeatherStage != nullptr) {
        mpWeatherStage->release();
        mpWeatherStage = nullptr;
    }
    if (mpEffectProv != nullptr) {
        mpEffectProv->release();
        mpEffectProv = nullptr;
    }
    if (mpSndReqEdit != nullptr) {
        mpSndReqEdit->release();
        mpSndReqEdit = nullptr;
    }
    if (mpSndPitchLimit != nullptr) {
        mpSndPitchLimit->release();
        mpSndPitchLimit = nullptr;
    }
    if (mpGmdDialog != nullptr) {
        mpGmdDialog->release();
        mpGmdDialog = nullptr;
    }
    if (mpModelSchl != nullptr) {
        mpModelSchl->kill();
        mpModelSchl = nullptr;
    }
    if (mpFilterSchl != nullptr) {
        mpFilterSchl->kill();
        mpFilterSchl = nullptr;
    }
    if (mpLightSchl != nullptr) {
        mpLightSchl->kill();
        mpLightSchl = nullptr;
    }
    if (mpOmListSchl != nullptr) {
        mpOmListSchl->kill();
        mpOmListSchl = nullptr;
    }
    if (mpModel != nullptr) {
        mpModel->kill();
        mpModel = nullptr;
    }
    if (mpCamera != nullptr) {
        mpCamera->kill();
        mpCamera = nullptr;
    }
    if (sSound::getInstance() != nullptr) {
        static_cast<sSoundExt*>(sSound::getInstance())->stopAllStream();
        static_cast<sSoundExt*>(sSound::getInstance())->stopAllSe();
    }
    if (sWeatherManager::getInstance() != nullptr) {
        sWeatherManager::getInstance()->releaseEnvMapTexture();
    }
    if (sArea::getInstance() != nullptr) {
        if (!static_cast<sAreaExt*>(sArea::getInstance())->isStage()) {
            if (sLightExt::getInstance() != nullptr) {
                sLightExt::getInstance()->stageFinal();
            }
        }
    }
    if (sWeatherManager::getInstance() != nullptr) {
        sWeatherManager::getInstance()->endQuestWeather();
        sWeatherManager::getInstance()->clearWeatherStageUnit();
        sWeatherManager::getInstance()->releaseWeatherStageInfo();
        sWeatherManager::getInstance()->releaseWeatherParamInfoTbl();
    }
    if (sWorldOffset::getInstance() != nullptr) {
        sWorldOffset::getInstance()->clear();
    }
    if (sLightExt::getInstance() != nullptr) {
        sLightExt::getInstance()->mbIsEditRoom = false;
        sLightExt::getInstance()->mpuTargetModel = nullptr;
    }
    if (sRender::getInstance() != nullptr) {
        sRender::getInstance()->setRenderDetailControl(true);
        return;
    }
}

__attribute__((weak)) bool uCharacterEditBase::moveLoadArc() {
    mDisableCameraMove = true;
    switch (mProc) {
        case 0:
        {
            TICKET t0 = sArchiveManager::getInstance()->IssueTicket();
            mArcTicketEditCommon = t0;
            sArchiveManager* t1 = sArchiveManager::getInstance();
            t1->addTagEx(t0, rArchiveListArray::convTagId("character_edit_select"));
            sArchiveManager::getInstance()->attestationTicket(mArcTicketEditCommon);
            mProc = 1;
            return false;
        }
        case 1:
        {
            if (sArchiveManager::getInstance()->isTicketLoadFinish(mArcTicketEditCommon)) {
                mProc = 2;
                return false;
            } else {
                return false;
            }
            break;
        }
        case 2:
        {
            if ((mpEditStageParam = static_cast<rEditStageParam*>(sArchiveManager::getInstance()->createRes("character_edit_select", "RES_ID_STG_PARAM", 1u, false))) != nullptr) {
                applyStageType();
                mpEditStageParam->getStageList(mStageType, mStageList);
                mArcTicketStage = sArchiveManager::getInstance()->IssueTicket();
                ARC_TAGID t2 = mpEditStageParam->getStageArcTagId(mStageType, static_cast<u32>(mStageIdx));
                sArchiveManager::getInstance()->addTagEx(mArcTicketStage, t2);
                sArchiveManager::getInstance()->attestationTicket(mArcTicketStage);
                mProc = 3;
                return false;
            } else {
                mProc = 3;
                return false;
            }
            break;
        }
        case 3:
        {
            if (sArchiveManager::getInstance()->isTicketLoadFinish(mArcTicketStage)) {
                mProc = 4;
                return false;
            } else {
                return false;
            }
            break;
        }
        case 4:
        {
            return sArchiveManager::getInstance()->isTicketLoadFinish(mArcTicketStage);
        }
        default:
        {
            return false;
        }
    }
}

__attribute__((weak)) void uCharacterEditBase::moveLoadUnit() {
    DDON_STUB("uCharacterEditBase::moveLoadUnit")
    /* stub */
}

__attribute__((weak)) void uCharacterEditBase::setScrScheduler(s32 scr_idx, s32 time_idx) {
    DDON_STUB("uCharacterEditBase::setScrScheduler")
    /* stub */
}

u32 uCharacterEditBase::getStageListNum() {
    if (mpEditStageParam != nullptr) {
        return mpEditStageParam->getStageListNum(mStageType);
    } else {
        return 0;
    }
}

u32 uCharacterEditBase::getStageListNo(u32 idx) {
    if (mpEditStageParam != nullptr) {
        return static_cast<u32>(mpEditStageParam->getStageListNo(mStageType, idx));
    } else {
        return 0;
    }
}

bool uCharacterEditBase::isStageChangeTime(u32 idx) const {
    if ((mStageList.mpArray[idx] != nullptr) && static_cast<rEditStageParam::Info*>(mStageList.mpArray[idx])->isChangeTime()) {
        return true;
    }
    return false;
}

void uCharacterEditBase::setAction(u32 ActNo, bool init) {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->getActMgrPtr() == nullptr) {
        return;
    }
    mpModel->getActMgrPtr()->setAction(ActNo, false, init, 0u, 0u, 0u, 0.0f, 0.0f, 0.0f, 0.0f);
}

void uCharacterEditBase::setFaceAnime(s32 idx, bool force) {
    if (mpModel == nullptr) {
        return;
    }
    u32 t0 = mpModel->getMotionNo(1u);
    bool t1 = mpModel->mMotion[1].isMotionEnd();
    if (idx == static_cast<int>(t0)) {
        if (!force) {
            if (t1) {
                mpModel->setMotionEx(1u, static_cast<u32>(idx), -1.0f, 0.0f, 1.0f, 4u);
            }
        } else {
            mpModel->setMotionEx(1u, static_cast<u32>(idx), -1.0f, 0.0f, 1.0f, 4u);
        }
    } else {
        mpModel->setMotionEx(1u, static_cast<u32>(idx), -1.0f, 0.0f, 1.0f, 4u);
    }
}

bool uCharacterEditBase::isMale() {
    if (mpModel != nullptr) {
        return mpModel->mpCharacterEdit->mpResource->mpEditParam->mBodyType == 0;
    } else {
        return true;
    }
}

MT_CTSTR uCharacterEditBase::getSndPitchSearchName() const {
    return "RES_ID_VOICE_PITCH";
}

inline uCharacterEditBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterEditBase::MyDTI uCharacterEditBase::DTI("uCharacterEditBase", &::cUnit::DTI, 624ul, 0u, 1u);

alignas(4) unsigned char uCharacterEditBase_ActListMale_bytes[24] __asm__("_ZN18uCharacterEditBase11ActListMaleE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00};

alignas(4) unsigned char uCharacterEditBase_ActListFemale_bytes[24] __asm__("_ZN18uCharacterEditBase13ActListFemaleE") = {0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00};

MtObject* uCharacterEditBase::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uCharacterEditCamera::getDTI() const {
    return uCharacterEditCamera::DTI;
}

uCharacterEditCamera::~uCharacterEditCamera() {
}

inline uCharacterEditCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterEditCamera::MyDTI uCharacterEditCamera::DTI("uCharacterEditCamera", &::uCharacterEditCameraBase::DTI, 768ul, 0u, 0u);

__attribute__((weak)) MtObject* uCharacterEditCamera::MyDTI::newInstance() const {
    DDON_STUB("uCharacterEditCamera::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCharacterEditCameraBase::getDTI() const {
    return uCharacterEditCameraBase::DTI;
}

uCharacterEditCameraBase::uCharacterEditCameraBase() {
    mWaitFrame = 0;
    mLength = 200.0f;
    mRotateLS = MtVector3::Zero;
    mRotateRS = MtVector3::Zero;
    mCameraMode = CAMERA_MOVE_NONE;
    mAngle = 0.0f;
    mAngleAdd = 0.0f;
    mpOldCameraParam = nullptr;
    mpNowCameraParam = nullptr;
    mpEditUnit = nullptr;
    mpModel = nullptr;
    mZoomSpeed = 15.0f;
    mRotateSpeed = 3.8f;
    mResetMaxSpeed = 0.16f;
    mCameraRiviseSpeed = 1.0f;
    mIsLSenableRotate = true;
    mpCameraParam = nullptr;
    mMode = MODE_DEFAULT;
    mIsLock = false;
}

uCharacterEditCameraBase::~uCharacterEditCameraBase() {
    if (mpCameraParam == nullptr) {
        return;
    }
    mpCameraParam->release();
    mpCameraParam = nullptr;
}

void uCharacterEditCameraBase::createProperty(MtPropertyList& s) {
    this->uFreeCamera::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCameraParam", "resource", static_cast<void*>(&mpCameraParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResetMaxSpeed", &mResetMaxSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateRS", &mRotateRS, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateLS", &mRotateLS, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLength", &mLength, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResetAngle", &mResetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mZoomSpeed", &mZoomSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateSpeed", &mRotateSpeed, 0u, 0u);
}

MtUI* uCharacterEditCameraBase::createUI(MtProperty& prop) {
    return this->uFreeCamera::createUI(prop);
}

__attribute__((weak)) void uCharacterEditCameraBase::setup() {
    DDON_STUB("uCharacterEditCameraBase::setup")
    /* stub */
}

void uCharacterEditCameraBase::move() {
    this->uFreeCamera::move();
    if (mWaitFrame > 0) {
        mWaitFrame = mWaitFrame - 1;
    } else {
        updateCameraParam();
        updateCameraData();
        updateInterPos();
        if (mIsLSenableRotate) {
            if (mpModel != nullptr) {
                if (mMode == MODE_DEFAULT) {
                    MtVector3 frame56(mpModel->getAngle());
                    mpModel->setAngle(frame56.y - mRotateLS.y);
                    mIsLock = false;
                } else {
                    mIsLock = false;
                }
            } else {
                mIsLock = false;
            }
        } else {
            mIsLock = false;
        }
    }
}

void uCharacterEditCameraBase::setResetMode() {
    mMode = MODE_RESET;
    mResetAngle.x = mRotateRS.x;
    mResetAngle.y = mRotateRS.y;
    mResetAngle.z = 0.0f;
    mCameraMode = CAMERA_MOVE_R;
}

cCharacterEditCameraParam* uCharacterEditCameraBase::getCameraParam(MT_CTSTR str) {
    cCharacterEditCameraParam* v1_8;
    if (str == nullptr) {
        v1_8 = nullptr;
    } else {
        if (mpCameraParam == nullptr) {
            v1_8 = nullptr;
        } else {
            if (mpCameraParam->getDataNum() == 0) {
                v1_8 = nullptr;
            } else {
                for (unsigned int i0_3 = 0;;) {
                    char tmpBuffer[128];
                    cGUIUtility::convSJIStoUTF8(mpCameraParam->getData(i0_3)->mName.ptr(), tmpBuffer, 128u);
                    if (strcmp(tmpBuffer, str) != 0) {
                        if ((i0_3 + 1u) < mpCameraParam->getDataNum()) {
                            i0_3 += 1u;
                        } else {
                            v1_8 = nullptr;
                            break;
                        }
                    } else {
                        v1_8 = mpCameraParam->getData(i0_3);
                        break;
                    }
                }
            }
        }
    }
    return v1_8;
}

__attribute__((weak)) void uCharacterEditCameraBase::updateCameraParam() {
    DDON_STUB("uCharacterEditCameraBase::updateCameraParam")
    /* stub */
}

__attribute__((weak)) void uCharacterEditCameraBase::updateCameraData() {
    DDON_STUB("uCharacterEditCameraBase::updateCameraData")
    /* stub */
}

__attribute__((weak)) void uCharacterEditCameraBase::updateInterPos() {
    DDON_STUB("uCharacterEditCameraBase::updateInterPos")
    /* stub */
}

__attribute__((weak)) void uCharacterEditCameraBase::moveKey() {
    DDON_STUB("uCharacterEditCameraBase::moveKey")
    /* stub */
}

__attribute__((weak)) void uCharacterEditCameraBase::initCameraParam() {
    DDON_STUB("uCharacterEditCameraBase::initCameraParam")
    /* stub */
}

inline uCharacterEditCameraBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterEditCameraBase::MyDTI uCharacterEditCameraBase::DTI("uCharacterEditCameraBase", &::uFreeCamera::DTI, 768ul, 0u, 0u);

MtObject* uCharacterEditCameraBase::MyDTI::newInstance() const {
    return new (16u) uCharacterEditCameraBase;
}

const MtDTI& uCharacterEditCameraBase::cLimit::getDTI() const {
    return uCharacterEditCameraBase::cLimit::DTI;
}

__attribute__((weak)) void uCharacterEditCameraBase::cLimit::operator delete(void* p_addr) {
    uCharacterEditCameraBase::cLimit::getAllocator()->memFree(p_addr);
}

void uCharacterEditCameraBase::cLimit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "max", &max, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "min", &min, 0u, 0u);
}

bool uCharacterEditCameraBase::cLimit::load(MtDataReader& r) {
    nDDOIO::readData(r, min);
    nDDOIO::readData(r, max);
    return true;
}

inline uCharacterEditCameraBase::cLimit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterEditCameraBase::cLimit::MyDTI uCharacterEditCameraBase::cLimit::DTI("uCharacterEditCameraBase::cLimit", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uCharacterEditCameraBase::cLimit::MyDTI::newInstance() const {
    return new (16u) uCharacterEditCameraBase::cLimit;
}

template MtTypedArray<cEditParamList>::~MtTypedArray();

template MtTypedArray<nCharacterEdit::cPaletteParams>::~MtTypedArray();

