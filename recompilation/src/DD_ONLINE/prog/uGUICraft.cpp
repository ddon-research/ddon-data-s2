// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICraft.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Craft.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Pawn.h"
#include "cCharacterData.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cControl.h"
#include "cCraftRecipe.h"
#include "cEquipData.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "cUIObject.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nGUIItem.h"
#include "rArchiveListArray.h"
#include "rCraftCapPass.h"
#include "rCraftRecipe.h"
#include "rEffectProvider.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/rSoundRequest.h"
#include "sChat.h"
#include "sContextManager.h"
#include "sCraftManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sWorkRate.h"
#include "../../XFramework/uCoord.h"
#include "uEffect2DExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIAnnounce.h"
#include "uGUIBase.h"
#include "uGUIPopCmd01.h"
#include "uGUIPopCraftDetail.h"
#include "uGUIPopDetail01.h"
#include "uGUIPopFilter.h"
#include "uGUIPopNumber01.h"
#include "uGUIPopTopSel.h"
#include "uGUIQueueAnnounce.h"
#include "uGUIQueueAnnounceLvUp.h"
#include "uGUISystemMsg.h"
#include "../../XFramework/uScreenSpace.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const s32 status_frame[7] = {
    0,
    0,
    1,
    2,
    3,
    4,
    5,
};

static const u32 wep_id_table[12] = {
    1,
    2,
    7,
    11,
    4,
    5,
    6,
    12,
    9,
    3,
    8,
    13,
};

static const u32 armor_id_table[10] = {
    3,
    4,
    6,
    7,
    5,
    8,
    9,
    11,
    10,
    12,
};

static const u32 upgrade_armor_id_table[8] = {
    3,
    4,
    6,
    7,
    5,
    8,
    9,
    12,
};

static const u32 crest_wep_id_table[10] = {
    1,
    7,
    11,
    4,
    6,
    12,
    9,
    3,
    8,
    13,
};

static const u32 crest_armor_id_table[5] = {
    3,
    4,
    6,
    7,
    12,
};

static const u32 color_category_table[7] = {
    2,
    3,
    7,
    6,
    5,
    4,
    8,
};

static const s32 sv_status_frame[7] = {
    0,
    3,
    2,
    5,
    5,
    4,
    0,
};

static const u32 skill_name[5] = {
    33,
    34,
    35,
    36,
    37,
};

static const u32 color_text_table[8] = {
    186,
    187,
    188,
    189,
    190,
    191,
    192,
    185,
};

static const u32 use_item_cate_name[7] = {
    164,
    165,
    166,
    167,
    168,
    169,
    170,
};

static const u32 material_cate_name[8] = {
    171,
    172,
    173,
    174,
    175,
    176,
    214,
    206,
};

const MtDTI& uGUICraft::getDTI() const {
    return uGUICraft::DTI;
}

inline void uGUICraft::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICraft::DTI)->memFree(p_addr);
}

__attribute__((noinline)) uGUICraft::~uGUICraft() {
    DDON_STUB("uGUICraft::~uGUICraft")
    /* stub */
}

void uGUICraft::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUICraft::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CRAFT_GUI"), 129u, 1472801561l))) == nullptr) {
            return false;
        }
    }
    if (mpEffectRes == nullptr) {
        if ((mpEffectRes = static_cast<rEffectProvider*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_P_UI003_EPV"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpGUIResLvUp == nullptr) {
        if ((mpGUIResLvUp = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_JOB_LV_UP_GUI"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpGMDRes == nullptr) {
        if ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpGMDMenuRes == nullptr) {
        if ((mpGMDMenuRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MENU_COMMON_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpGMDParamRes == nullptr) {
        if ((mpGMDParamRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PARAMETER_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpSeRes == nullptr) {
        if ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_CRAFT_SRQR"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    return true;
}

__attribute__((weak)) void uGUICraft::setup() {
    DDON_STUB("uGUICraft::setup")
    /* stub */
}

void uGUICraft::kill() {
    static_cast<sGUIExt*>(sGUI::getInstance())->clearRequestPawnContext();
    if (mpGUIPopCmd != nullptr) {
        mpGUIPopCmd->kill();
        mpGUIPopCmd = nullptr;
    }
    if (mpNumSelect != nullptr) {
        mpNumSelect->kill();
        mpNumSelect = nullptr;
    }
    if (mpSystemMsg != nullptr) {
        mpSystemMsg->kill();
        mpSystemMsg = nullptr;
    }
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    if (mpLvUp != nullptr) {
        mpLvUp->kill();
        mpLvUp = nullptr;
    }
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpCraftDetail != nullptr) {
        mpCraftDetail->kill();
        mpCraftDetail = nullptr;
    }
    if (mpTopSel != nullptr) {
        mpTopSel->kill();
        mpTopSel = nullptr;
    }
    if (mpScreenSpace != nullptr) {
        mpScreenSpace->kill();
        mpScreenSpace = nullptr;
    }
    if (mpPopFilter != nullptr) {
        mpPopFilter->kill();
        mpPopFilter = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUICraft::updatePtr() {
    if (mpGUIPopCmd != nullptr) {
        if (!mpGUIPopCmd->isEnable()) {
            mpGUIPopCmd = nullptr;
        }
    }
    if (mpNumSelect != nullptr) {
        if (!mpNumSelect->isEnable()) {
            mpNumSelect = nullptr;
        }
    }
    if (mpSystemMsg != nullptr) {
        if (!mpSystemMsg->isEnable()) {
            mpSystemMsg = nullptr;
        }
    }
    if (mpAnnounce != nullptr) {
        if (!mpAnnounce->isEnable()) {
            mpAnnounce = nullptr;
        }
    }
    if (mpLvUp != nullptr) {
        if (!mpLvUp->isEnable()) {
            mpLvUp = nullptr;
        }
    }
    if (mpDetail != nullptr) {
        if (!mpDetail->isEnable()) {
            mpDetail = nullptr;
        }
    }
    if (mpCraftDetail != nullptr) {
        if (!mpCraftDetail->isEnable()) {
            mpCraftDetail = nullptr;
        }
    }
    if (mpTopSel != nullptr) {
        if (!mpTopSel->cUnit::isEnable()) {
            mpTopSel = nullptr;
        }
    }
    if (mpScreenSpace != nullptr) {
        if (!mpScreenSpace->isEnable()) {
            mpScreenSpace = nullptr;
        }
    }
    if (mpPopFilter != nullptr) {
        if (!mpPopFilter->isEnable()) {
            mpPopFilter = nullptr;
        }
    }
}

__attribute__((weak)) void uGUICraft::setFlowId(u32 flow_id) {
    DDON_STUB("uGUICraft::setFlowId")
    /* stub */
}

void uGUICraft::setEnableOrder(bool isEnable) {
    if (mRecipeType == 0) {
        if (mpCraftDetail != nullptr) {
            if (mpCraftDetail->isEnoughGold()) {
                if (!mpCraftDetail->mIsEnoughMaterial) {
                    if (!mOrder.mIsEnoughCraftCount) {
                    }
                    if (mOrder.mButton[0].mIsEnable) {
                        mOrder.mButton[0].setEnable(false);
                        (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                    }
                } else {
                    if (!mOrder.mIsEnoughCraftCount) {
                        if (mOrder.mButton[0].mIsEnable) {
                            mOrder.mButton[0].setEnable(false);
                            (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                        }
                    } else {
                        if (mOrder.mButton[0].mIsEnable != isEnable) {
                            mOrder.mButton[0].setEnable(isEnable);
                            (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                        }
                    }
                }
            } else {
                if (!mOrder.mIsEnoughCraftCount) {
                }
                if (mOrder.mButton[0].mIsEnable) {
                    mOrder.mButton[0].setEnable(false);
                    (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                }
            }
        } else {
            if (!mOrder.mIsEnoughCraftCount) {
                if (mOrder.mButton[0].mIsEnable) {
                    mOrder.mButton[0].setEnable(false);
                    (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                }
            } else {
                if (mOrder.mButton[0].mIsEnable != isEnable) {
                    mOrder.mButton[0].setEnable(isEnable);
                    (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
                }
            }
        }
    } else {
        if (mOrder.mButton[0].mIsEnable != isEnable) {
            mOrder.mButton[0].setEnable(isEnable);
            (&mOrder.mButton[0])->setFocus((&mOrder.mButton[0])->isFocus());
        }
    }
}

void uGUICraft::adjustScale() {
    float t0 = 1.0f;
    const f32 fScaleRate = getScaleForDefaultResolution(t0);
    cGUIInstNull* t1 = mpInstNullBase;
    if (t1 != nullptr) {
        t1->setScaleX(fScaleRate);
        t1->setScaleY(fScaleRate);
        t1->setScaleZ(fScaleRate);
        cGUIInstance* t3 = getInstance(5u, false);
        MtVector2 frame48(uGUIBase::getInstanceScreenPos(t3, mPos));
        f32 t5 = frame48.x;
        f32 t6 = frame48.y;
        uGUIPopCraftDetail* t7 = mpCraftDetail;
        if (t7 != nullptr) {
            t7->mPos.x = t5;
            t7->mPos.y = t6;
            t7->mPos.z = 0.0f;
            t7->mPos.pad_ = 0.0f;
            uGUIPopDetail01* t8 = mpDetail;
            if (t8 != nullptr) {
                t8->mPos.x = t5;
                t8->mPos.y = t6;
                t8->mPos.z = 0.0f;
                t8->mPos.pad_ = 0.0f;
            }
        } else {
            uGUIPopDetail01* t8 = mpDetail;
            if (t8 != nullptr) {
                t8->mPos.x = t5;
                t8->mPos.y = t6;
                t8->mPos.z = 0.0f;
                t8->mPos.pad_ = 0.0f;
            }
        }
    } else {
        cGUIInstance* t3 = getInstance(5u, false);
        MtVector2 frame48(uGUIBase::getInstanceScreenPos(t3, mPos));
        f32 t5 = frame48.x;
        f32 t6 = frame48.y;
        uGUIPopCraftDetail* t7 = mpCraftDetail;
        if (t7 != nullptr) {
            t7->mPos.x = t5;
            t7->mPos.y = t6;
            t7->mPos.z = 0.0f;
            t7->mPos.pad_ = 0.0f;
            uGUIPopDetail01* t8 = mpDetail;
            if (t8 != nullptr) {
                t8->mPos.x = t5;
                t8->mPos.y = t6;
                t8->mPos.z = 0.0f;
                t8->mPos.pad_ = 0.0f;
            }
        } else {
            uGUIPopDetail01* t8 = mpDetail;
            if (t8 != nullptr) {
                t8->mPos.x = t5;
                t8->mPos.y = t6;
                t8->mPos.z = 0.0f;
                t8->mPos.pad_ = 0.0f;
            }
        }
    }
}

__attribute__((weak)) void uGUICraft::moveInput() {
    DDON_STUB("uGUICraft::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUICraft::moveEvent() {
    DDON_STUB("uGUICraft::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUICraft::updateMove() {
    DDON_STUB("uGUICraft::updateMove")
    /* stub */
}

__attribute__((weak)) void uGUICraft::updateUpGradeResult() {
    DDON_STUB("uGUICraft::updateUpGradeResult")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setFlowIdSub(u32 flow_id) {
    DDON_STUB("uGUICraft::setFlowIdSub")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupTopMenu() {
    DDON_STUB("uGUICraft::setupTopMenu")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMainPawnStatus(bool isProgress) {
    DDON_STUB("uGUICraft::setupMainPawnStatus")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeItem() {
    DDON_STUB("uGUICraft::setupMakeItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeCategory() {
    DDON_STUB("uGUICraft::setupMakeCategory")
    /* stub */
}

__attribute__((weak)) void uGUICraft::initListCategory() {
    DDON_STUB("uGUICraft::initListCategory")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeItemRecipeList() {
    DDON_STUB("uGUICraft::setupMakeItemRecipeList")
    /* stub */
}

__attribute__((weak)) bool uGUICraft::checkFilter(rItemList::rItemParam* pParam) {
    DDON_STUB("uGUICraft::checkFilter")
    return {};
}

__attribute__((weak)) void uGUICraft::setupRequestRecipeCategory() {
    DDON_STUB("uGUICraft::setupRequestRecipeCategory")
    /* stub */
}

__attribute__((weak)) void uGUICraft::addListInfo(s32& pos, u32 type, u32 cate, u32 index, u32 rank, bool isHead, u32 exam_pawn_id) {
    DDON_STUB("uGUICraft::addListInfo")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeItemListControl() {
    DDON_STUB("uGUICraft::setupMakeItemListControl")
    /* stub */
}

void uGUICraft::setupMakeAddItem() {
    cGUIObjMessage* t0 = mMain.mpObjMsgGuide;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 135u), 0u, false);
    cGUIObjMessage* t1 = mMain.mpObjMsgHeader00;
    setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 151u), 0u, false);
    cGUIObjMessage* t2 = mMain.mpObjMsgHeader03;
    setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 136u), 0u, false);
    if (mMain.mpObjNullHeader != nullptr) {
        mMain.mpObjNullHeader->setVisible(true);
    }
    setupMakeAddItemList();
    mAddItem.mListCtrl.setEnableKey(true);
    if (mpDecideCtrl != nullptr) {
        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
        cGUIObjMessage* t3 = mStatus.mpObjMsgTitle;
        setObjectMessage(static_cast<cGUIObject*>(t3), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 17u), 0u, false);
        cGUIInstance* t4 = getInstance(340u, false);
        if (t4 != nullptr) {
            t4->setVisible(false);
        }
        adjustMakeAddItemCursor();
    } else {
        cGUIObjMessage* t3 = mStatus.mpObjMsgTitle;
        setObjectMessage(static_cast<cGUIObject*>(t3), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 17u), 0u, false);
        cGUIInstance* t4 = getInstance(340u, false);
        if (t4 != nullptr) {
            t4->setVisible(false);
        }
        adjustMakeAddItemCursor();
    }
}

__attribute__((weak)) void uGUICraft::setupMakeAddItemList() {
    DDON_STUB("uGUICraft::setupMakeAddItemList")
    /* stub */
}

__attribute__((weak)) bool uGUICraft::isMakedFurniture(const uGUICraft::cListInfo* pInfo) {
    DDON_STUB("uGUICraft::isMakedFurniture")
    return {};
}

__attribute__((weak)) void uGUICraft::setupResultExp(u32 add_exp, u32 bonus_exp) {
    DDON_STUB("uGUICraft::setupResultExp")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupSubMenu() {
    DDON_STUB("uGUICraft::setupSubMenu")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupCharaSelect() {
    DDON_STUB("uGUICraft::setupCharaSelect")
    /* stub */
}

void uGUICraft::updateCharaSelect() {
    if (mpSystemMsg != nullptr) {
        if (mpSystemMsg->mResult == RESULT_EXIT) {
            const s32 select = mpSystemMsg->getChoicePos(-1);
            if (select == 0) {
                mCompPawnId = 0;
                setFlowId(mReturnFlowId);
                if (mpSystemMsg != nullptr) {
                    mpSystemMsg->mEndType = 0;
                    mpSystemMsg->end();
                }
                mpSystemMsg = nullptr;
                static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
            } else {
                if (select != -1) {
                    if (static_cast<unsigned int>(select - 1) < static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mLength) {
                        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mpArray[static_cast<unsigned int>(select - 1)] != nullptr) {
                            unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mpArray[static_cast<unsigned int>(select - 1)]) + 8);
                            if (t0 != mCompPawnId) {
                                mCompPawnId = t0;
                                if (t0 == cContextInterface::getPawnId(&mPawnContext)) {
                                    setFlowId(mReturnFlowId);
                                } else {
                                    setFlowId(51u);
                                }
                            } else {
                                setFlowId(mReturnFlowId);
                            }
                            if (mpSystemMsg != nullptr) {
                                mpSystemMsg->mEndType = 0;
                                mpSystemMsg->end();
                            }
                            mpSystemMsg = nullptr;
                            static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
                        } else {
                            setFlowId(mReturnFlowId);
                            if (mpSystemMsg != nullptr) {
                                mpSystemMsg->mEndType = 0;
                                mpSystemMsg->end();
                            }
                            mpSystemMsg = nullptr;
                            static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
                        }
                    } else {
                        setFlowId(mReturnFlowId);
                        if (mpSystemMsg != nullptr) {
                            mpSystemMsg->mEndType = 0;
                            mpSystemMsg->end();
                        }
                        mpSystemMsg = nullptr;
                        static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
                    }
                } else {
                    setFlowId(mReturnFlowId);
                    if (mpSystemMsg != nullptr) {
                        mpSystemMsg->mEndType = 0;
                        mpSystemMsg->end();
                    }
                    mpSystemMsg = nullptr;
                    static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
                }
            }
        }
    } else {
        setFlowId(mReturnFlowId);
    }
}

__attribute__((weak)) void uGUICraft::setupFilter() {
    DDON_STUB("uGUICraft::setupFilter")
    /* stub */
}

__attribute__((weak)) void uGUICraft::updateFilter() {
    DDON_STUB("uGUICraft::updateFilter")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupGetChest() {
    DDON_STUB("uGUICraft::setupGetChest")
    /* stub */
}

__attribute__((weak)) void uGUICraft::updateAnalyze() {
    DDON_STUB("uGUICraft::updateAnalyze")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupCreateNumSelect() {
    DDON_STUB("uGUICraft::setupCreateNumSelect")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeItem() {
    DDON_STUB("uGUICraft::setupUpGradeItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeCategory() {
    DDON_STUB("uGUICraft::setupUpGradeCategory")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeItemRecipeList() {
    DDON_STUB("uGUICraft::setupUpGradeItemRecipeList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeOrder() {
    DDON_STUB("uGUICraft::setupUpGradeOrder")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeResultWait() {
    DDON_STUB("uGUICraft::setupUpGradeResultWait")
    /* stub */
}

void uGUICraft::setupUpGradeResult() {
    mResult.mButton[0].setEnable(true);
    (&mResult.mButton[0])->setFocus(true);
    if (mpDetail != nullptr) {
        mpDetail->resetPageType();
        cItemParam* pParam = cGUIUtility::getItemParamFromUID(sCraftManager::getInstance()->mCraftCtrl.mUpGradeUID.ptr(), sItemManager::STORAGE_FILLTER_TYPE_ALL);
        if (pParam != nullptr) {
            rItemList::rItemParam* pItemParam = sItemManager::getInstance()->getItemParam(pParam->getItemNo());
            setupItemDetail(true, false, pParam, pItemParam);
            cControl* t0 = mpDecideCtrl;
            if (t0 != nullptr) {
                cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
                t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
            }
        } else {
            setupItemDetail(true, false, pParam, static_cast<rItemList::rItemParam*>(nullptr));
            cControl* t0 = mpDecideCtrl;
            if (t0 != nullptr) {
                cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
                t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
            }
        }
    } else {
        cItemParam* pParam = cGUIUtility::getItemParamFromUID(sCraftManager::getInstance()->mCraftCtrl.mUpGradeUID.ptr(), sItemManager::STORAGE_FILLTER_TYPE_ALL);
        if (pParam != nullptr) {
            rItemList::rItemParam* pItemParam = sItemManager::getInstance()->getItemParam(pParam->getItemNo());
            setupItemDetail(true, false, pParam, pItemParam);
            cControl* t0 = mpDecideCtrl;
            if (t0 != nullptr) {
                cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
                t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
            }
        } else {
            setupItemDetail(true, false, pParam, static_cast<rItemList::rItemParam*>(nullptr));
            cControl* t0 = mpDecideCtrl;
            if (t0 != nullptr) {
                cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
                t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
            }
        }
    }
}

__attribute__((weak)) void uGUICraft::setupUpGradeParam() {
    DDON_STUB("uGUICraft::setupUpGradeParam")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupUpGradeResultItem(u32 item_id) {
    DDON_STUB("uGUICraft::setupUpGradeResultItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::popUpGradeItem() {
    DDON_STUB("uGUICraft::popUpGradeItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupCrestEquipRecipeList() {
    DDON_STUB("uGUICraft::setupCrestEquipRecipeList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupCrestOrder() {
    DDON_STUB("uGUICraft::setupCrestOrder")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupCrestResultWait() {
    DDON_STUB("uGUICraft::setupCrestResultWait")
    /* stub */
}

void uGUICraft::setupCrestResult() {
    mResult.mButton[0].setEnable(true);
    (&mResult.mButton[0])->setFocus(true);
    if (mpDetail != nullptr) {
        mpDetail->resetPageType();
        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        }
    } else {
        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        }
    }
}

__attribute__((weak)) void uGUICraft::setupColorOrder() {
    DDON_STUB("uGUICraft::setupColorOrder")
    /* stub */
}

void uGUICraft::setupColorItem() {
    cGUIObjMessage* t0 = mMain.mpObjMsgGuide;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 137u), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mMain.mpObjMsgHeader00), "", 0u, false);
    cGUIObjMessage* t1 = mMain.mpObjMsgHeader01;
    setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 151u), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mMain.mpObjMsgHeader02), "", 0u, false);
    cGUIObjMessage* t2 = mMain.mpObjMsgHeader03;
    setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 136u), 0u, false);
    if (mMain.mpObjNullHeader != nullptr) {
        mMain.mpObjNullHeader->setVisible(false);
    }
    mMakeItem.mUpGradeTab.setVisible(false);
    mMakeItem.mMakeTab.setVisible(false);
    mPawnSel.mTab.setVisible(false);
    setObjectMessage(static_cast<cGUIObject*>(mMakeItem.mpObjMsgNotice), "", 0u, false);
    setupColorItemCategory();
    if (mpDecideCtrl != nullptr) {
        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
    }
    if (mpCheckCtrl == nullptr) {
        return;
    }
    mpCheckCtrl->mCtrlF = mpCheckCtrl->mCtrlF & 0xFFFFFFF7u;
}

__attribute__((weak)) void uGUICraft::setupColorItemCategory() {
    initListCategory();
    if (mpCategoryCtrl != nullptr) {
        mpCategoryCtrl->resetItemNum(7, static_cast<const u32*>(nullptr), 0);
        mpCategoryCtrl->clearMouseTouchList();
        for (u32 i = 0; i != 7; i = i + 1u) {
            setInstanceVisible(static_cast<cGUIInstance*>(mMakeItem.mCategory[i].mpInstAnim), true);
            setInstanceVisible(static_cast<cGUIInstance*>(mMakeItem.mCategory[i].mpInstAnimColor), true);
            const unsigned int t0 = color_category_table[i];
            cGUIObjMessage* t1 = mMakeItem.mCategory[i].mpObjMsg;
            setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDParamRes, color_text_table[t0 - 1u]), 0u, false);
            cGUIObjTextureSet* t2 = mMakeItem.mCategory[i].mpObjTexColor;
            const MtColor& t3 = cGUIUtility::getColorFromCraftColorNo(t0);
            if (t2 != nullptr) {
                t2->setColor(t3, 0u);
                t2->setColor(t3, 1u);
                t2->setColor(t3, 2u);
                t2->setColor(t3, 3u);
            }
            mpCategoryCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(mMakeItem.mCategory[i].mpInstAnim), static_cast<cGUIObject*>(mMakeItem.mCategory[i].mpObjPolyCollision), static_cast<s32>(i), -1);
        }
        if (mpCategoryCtrl != nullptr) {
            mpCategoryCtrl->mCtrlF = mpCategoryCtrl->mCtrlF & 0xFFFFFFF7u;
        }
    }
    setupColorItemRecipeList();
}

__attribute__((weak)) void uGUICraft::setupColorItemRecipeList() {
    DDON_STUB("uGUICraft::setupColorItemRecipeList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUICraft::setupListItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUICraft::hideListItem")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupAddListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUICraft::setupAddListItem")
    /* stub */
}

void uGUICraft::hideAddListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    if (pItemBase == nullptr) {
        return;
    }
    cAddListItem* pItem = static_cast<cAddListItem*>(pItemBase);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgName), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(pItem->mpObjMsgNum), "", 0u, false);
}

__attribute__((weak)) void uGUICraft::setupPawnSelect() {
    DDON_STUB("uGUICraft::setupPawnSelect")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupPawnSelectList(u32 type) {
    DDON_STUB("uGUICraft::setupPawnSelectList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupOrderCommon() {
    DDON_STUB("uGUICraft::setupOrderCommon")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupOrder() {
    DDON_STUB("uGUICraft::setupOrder")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupOrderListCtrl(u32 list_num) {
    DDON_STUB("uGUICraft::setupOrderListCtrl")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupOrderPawnInfo(uGUICraft::stOrderListItem& order, u32 pawn_id) {
    DDON_STUB("uGUICraft::setupOrderPawnInfo")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupTotal() {
    DDON_STUB("uGUICraft::setupTotal")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupStatus(u32 pawn_id) {
    DDON_STUB("uGUICraft::setupStatus")
    /* stub */
}

void uGUICraft::setupProgress() {
    setObjectMessage(static_cast<cGUIObject*>(mMain.mpObjMsgGuide), "", 0u, false);
    cGUIObjMessage* t0 = mMain.mpObjMsgHeader00;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 28u), 0u, false);
    cGUIObjMessage* t1 = mMain.mpObjMsgHeader01;
    setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 29u), 0u, false);
    cGUIObjMessage* t2 = mMain.mpObjMsgHeader02;
    setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 151u), 0u, false);
    cGUIObjMessage* t3 = mMain.mpObjMsgHeader03;
    setObjectMessage(static_cast<cGUIObject*>(t3), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 150u), 0u, false);
    if (mMain.mpObjNullHeader != nullptr) {
        mMain.mpObjNullHeader->setVisible(true);
    }
    clearPawnSelectList();
    setInstanceVisible(static_cast<cGUIInstance*>(mPawnList.mpInstNull), false);
    setInstanceVisible(static_cast<cGUIInstance*>(mTotal.mpInstNull), false);
    setInstanceVisible(static_cast<cGUIInstance*>(mStatus.mpInstNull), false);
}

__attribute__((weak)) void uGUICraft::setupProgressPawnList() {
    DDON_STUB("uGUICraft::setupProgressPawnList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupProgressDetail() {
    DDON_STUB("uGUICraft::setupProgressDetail")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeResultWait() {
    DDON_STUB("uGUICraft::setupMakeResultWait")
    /* stub */
}

void uGUICraft::setupMakeResult() {
    if (mIsFurniture) {
        if (mpButtonCtrl != nullptr) {
            mpButtonCtrl->resetItemNum(1, static_cast<const u32*>(nullptr), 0);
            mpButtonCtrl->clearMouseTouchList();
            cHorizontalList* t0 = mpButtonCtrl;
            if (t0 != nullptr) {
                cGUIInstAnimation* t1 = mResult.mButton[0].mpInstance;
                t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                mResult.mButton[0].setEnable(true);
                cHorizontalList* t6 = mpButtonCtrl;
                if (t6 != nullptr) {
                    t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    } else {
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    }
                } else {
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                    }
                    (&mResult.mButton[0])->setFocus(false);
                    (&mResult.mButton[1])->setFocus(false);
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                }
            } else {
                mResult.mButton[0].setEnable(true);
                cHorizontalList* t6 = mpButtonCtrl;
                if (t6 != nullptr) {
                    t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    } else {
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    }
                } else {
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                    }
                    (&mResult.mButton[0])->setFocus(false);
                    (&mResult.mButton[1])->setFocus(false);
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                }
            }
        } else {
            mResult.mButton[0].setEnable(true);
            cHorizontalList* t6 = mpButtonCtrl;
            if (t6 != nullptr) {
                t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                    bool t7 = t6->getFocus();
                    s32 t8 = t6->getCurrentPos();
                    (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                    (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                } else {
                    bool t7 = t6->getFocus();
                    s32 t8 = t6->getCurrentPos();
                    (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                    (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                }
            } else {
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
                (&mResult.mButton[0])->setFocus(false);
                (&mResult.mButton[1])->setFocus(false);
                if (mpDetail != nullptr) {
                    mpDetail->resetPageType();
                }
                setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
            }
        }
    } else {
        if (mpButtonCtrl != nullptr) {
            mpButtonCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), 1);
            mpButtonCtrl->clearMouseTouchList();
            cHorizontalList* t2 = mpButtonCtrl;
            if (t2 != nullptr) {
                cGUIInstAnimation* t3 = mResult.mButton[0].mpInstance;
                t2->addMouseTouchListLight(static_cast<cGUIInstance*>(t3), static_cast<cGUIObject*>((&mResult.mButton[0])->getMouseOverObject()), 0, -1);
                cHorizontalList* t4 = mpButtonCtrl;
                if (t4 != nullptr) {
                    cGUIInstAnimation* t5 = mResult.mButton[1].mpInstance;
                    t4->addMouseTouchListLight(static_cast<cGUIInstance*>(t5), static_cast<cGUIObject*>((&mResult.mButton[1])->getMouseOverObject()), 1, -1);
                    mResult.mButton[0].setEnable(mIsEnableReceiveBag);
                    mResult.mButton[1].setEnable(mIsEnableReceiveBox);
                    cHorizontalList* t6 = mpButtonCtrl;
                    if (t6 != nullptr) {
                        t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                        if (mpDecideCtrl != nullptr) {
                            mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                            bool t7 = t6->getFocus();
                            s32 t8 = t6->getCurrentPos();
                            (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                            (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                            if (mpDetail != nullptr) {
                                mpDetail->resetPageType();
                            }
                            setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                        } else {
                            bool t7 = t6->getFocus();
                            s32 t8 = t6->getCurrentPos();
                            (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                            (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                            if (mpDetail != nullptr) {
                                mpDetail->resetPageType();
                            }
                            setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                        }
                    } else {
                        if (mpDecideCtrl != nullptr) {
                            mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                        }
                        (&mResult.mButton[0])->setFocus(false);
                        (&mResult.mButton[1])->setFocus(false);
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    }
                } else {
                    mResult.mButton[0].setEnable(mIsEnableReceiveBag);
                    mResult.mButton[1].setEnable(mIsEnableReceiveBox);
                    cHorizontalList* t6 = mpButtonCtrl;
                    if (t6 != nullptr) {
                        t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                        if (mpDecideCtrl != nullptr) {
                            mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                            bool t7 = t6->getFocus();
                            s32 t8 = t6->getCurrentPos();
                            (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                            (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                            if (mpDetail != nullptr) {
                                mpDetail->resetPageType();
                            }
                            setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                        } else {
                            bool t7 = t6->getFocus();
                            s32 t8 = t6->getCurrentPos();
                            (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                            (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                            if (mpDetail != nullptr) {
                                mpDetail->resetPageType();
                            }
                            setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                        }
                    } else {
                        if (mpDecideCtrl != nullptr) {
                            mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                        }
                        (&mResult.mButton[0])->setFocus(false);
                        (&mResult.mButton[1])->setFocus(false);
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    }
                }
            } else {
                mResult.mButton[0].setEnable(mIsEnableReceiveBag);
                mResult.mButton[1].setEnable(mIsEnableReceiveBox);
                cHorizontalList* t6 = mpButtonCtrl;
                if (t6 != nullptr) {
                    t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    } else {
                        bool t7 = t6->getFocus();
                        s32 t8 = t6->getCurrentPos();
                        (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                        (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                        if (mpDetail != nullptr) {
                            mpDetail->resetPageType();
                        }
                        setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                    }
                } else {
                    if (mpDecideCtrl != nullptr) {
                        mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                    }
                    (&mResult.mButton[0])->setFocus(false);
                    (&mResult.mButton[1])->setFocus(false);
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                }
            }
        } else {
            mResult.mButton[0].setEnable(mIsEnableReceiveBag);
            mResult.mButton[1].setEnable(mIsEnableReceiveBox);
            cHorizontalList* t6 = mpButtonCtrl;
            if (t6 != nullptr) {
                t6->mCtrlF = t6->mCtrlF & 0xFFFFFFF7u;
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                    bool t7 = t6->getFocus();
                    s32 t8 = t6->getCurrentPos();
                    (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                    (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                } else {
                    bool t7 = t6->getFocus();
                    s32 t8 = t6->getCurrentPos();
                    (&mResult.mButton[0])->setFocus(t7 && (t8 == 0));
                    (&mResult.mButton[1])->setFocus(t7 && (t8 == 1));
                    if (mpDetail != nullptr) {
                        mpDetail->resetPageType();
                    }
                    setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
                }
            } else {
                if (mpDecideCtrl != nullptr) {
                    mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
                }
                (&mResult.mButton[0])->setFocus(false);
                (&mResult.mButton[1])->setFocus(false);
                if (mpDetail != nullptr) {
                    mpDetail->resetPageType();
                }
                setupItemDetail(true, false, static_cast<cItemParam*>(nullptr), static_cast<rItemList::rItemParam*>(nullptr));
            }
        }
    }
}

__attribute__((weak)) void uGUICraft::setupLvUp() {
    DDON_STUB("uGUICraft::setupLvUp")
    /* stub */
}

void uGUICraft::setupExam() {
    setSequenceId(mExam.mpInstAnim, 2u, true);
    setupExamSub(sCraftManager::getInstance()->mCraftRankUp.getPawnId(), false);
    mExam.mButton.setMessage(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 141u));
    (&mExam.mButton)->setFocus(true);
    if (mExam.mButton.mpInstance != nullptr) {
        mExam.mButton.mpInstance->setVisible(true);
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mExam.mButton.mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mExam.mButton)->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 34u);
            sQuestManagerExt::getInstance()->notifyOpenCraftExam();
        } else {
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 34u);
            sQuestManagerExt::getInstance()->notifyOpenCraftExam();
        }
    } else {
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mExam.mButton.mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mExam.mButton)->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 34u);
            sQuestManagerExt::getInstance()->notifyOpenCraftExam();
        } else {
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 34u);
            sQuestManagerExt::getInstance()->notifyOpenCraftExam();
        }
    }
}

__attribute__((weak)) void uGUICraft::setupExamSub(u32 pawn_id, bool isCleared) {
    DDON_STUB("uGUICraft::setupExamSub")
    /* stub */
}

void uGUICraft::setupExamClear() {
    setInstanceVisible(static_cast<cGUIInstance*>(mExam.mpInstNull), true);
    setInstanceVisible(static_cast<cGUIInstance*>(mPoint.mpInstNull), false);
    setInstanceVisible(static_cast<cGUIInstance*>(mPawnList.mpInstNull), false);
    mExam.mButton.setMessage(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 139u));
    (&mExam.mButton)->setFocus(true);
    if (mExam.mButton.mpInstance != nullptr) {
        mExam.mButton.mpInstance->setVisible(true);
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mExam.mButton.mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mExam.mButton)->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        } else {
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        }
    } else {
        cControl* t0 = mpDecideCtrl;
        if (t0 != nullptr) {
            cGUIInstAnimation* t1 = mExam.mButton.mpInstance;
            t0->addMouseTouchListLight(static_cast<cGUIInstance*>(t1), static_cast<cGUIObject*>((&mExam.mButton)->getMouseOverObject()), 0, -1);
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        } else {
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->mCtrlF = mpCancelCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        }
    }
}

__attribute__((weak)) void uGUICraft::setupPointPawnSelect() {
    DDON_STUB("uGUICraft::setupPointPawnSelect")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupPointPawnSelectList() {
    DDON_STUB("uGUICraft::setupPointPawnSelectList")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupPawnPoint() {
    DDON_STUB("uGUICraft::setupPawnPoint")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupPointInput() {
    DDON_STUB("uGUICraft::setupPointInput")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustListCategoryCursor(bool isImmediate) {
    DDON_STUB("uGUICraft::adjustListCategoryCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustListItemCursor(bool isImmediate) {
    DDON_STUB("uGUICraft::adjustListItemCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustMakeOrderCursor() {
    DDON_STUB("uGUICraft::adjustMakeOrderCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustPawnListCursor(bool isImmediate) {
    DDON_STUB("uGUICraft::adjustPawnListCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustMakeAddItemCursor() {
    DDON_STUB("uGUICraft::adjustMakeAddItemCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::adjustPawnPointCursor() {
    DDON_STUB("uGUICraft::adjustPawnPointCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::clearPawnSelectList() {
    DDON_STUB("uGUICraft::clearPawnSelectList")
    /* stub */
}

void uGUICraft::clearStatus() {
    setObjectMessage(static_cast<cGUIObject*>(mStatus.mpObjMsgTitle), "", 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mStatus.mpObjMsgName), "", 0u, false);
    if (mStatus.mCraftLvIcon.mpInstance != nullptr) {
        mStatus.mCraftLvIcon.mpInstance->setVisible(false);
    }
    setObjectMessage(static_cast<cGUIObject*>(mStatus.mpObjMsgLevelVal), "", 0u, false);
    if (mStatus.mpObjTexExpGauge != nullptr) {
        mStatus.mpObjTexExpGauge->setVisible(false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mpObjMsgExp), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[0].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[0].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[1].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[1].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[2].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[2].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[3].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[3].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[4].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[4].mpObjMsgVal), "", 0u, false);
        cGUIInstance* t0 = getInstance(340u, false);
        if (t0 != nullptr) {
            t0->setVisible(true);
        }
    } else {
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mpObjMsgExp), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[0].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[0].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[1].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[1].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[2].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[2].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[3].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[3].mpObjMsgVal), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[4].mpObjMsg), "", 0u, false);
        setObjectMessage(static_cast<cGUIObject*>(mStatus.mParam[4].mpObjMsgVal), "", 0u, false);
        cGUIInstance* t0 = getInstance(340u, false);
        if (t0 != nullptr) {
            t0->setVisible(true);
        }
    }
}

__attribute__((weak)) void uGUICraft::clearProgressDetail() {
    DDON_STUB("uGUICraft::clearProgressDetail")
    /* stub */
}

__attribute__((weak)) void uGUICraft::initPawnPoint() {
    DDON_STUB("uGUICraft::initPawnPoint")
    /* stub */
}

__attribute__((weak)) void uGUICraft::callEffect(u32 element_no) {
    DDON_STUB("uGUICraft::callEffect")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setMakeOrderPointerPos() {
    DDON_STUB("uGUICraft::setMakeOrderPointerPos")
    /* stub */
}

inline void uGUICraft::resetItemDetailPage() {
    if (mpDetail == nullptr) {
        return;
    }
    mpDetail->resetPageType();
}

__attribute__((weak)) void uGUICraft::setupItemDetail(bool bDraw, bool bCraft, cItemParam* pParam, rItemList::rItemParam* pItemParam) {
    DDON_STUB("uGUICraft::setupItemDetail")
    /* stub */
}

__attribute__((weak)) u32 uGUICraft::getSelectedPawnId() {
    DDON_STUB("uGUICraft::getSelectedPawnId")
    return {};
}

__attribute__((weak)) void uGUICraft::watchCraftProgressTime() {
    DDON_STUB("uGUICraft::watchCraftProgressTime")
    /* stub */
}

__attribute__((weak)) void uGUICraft::setupMakeTime(cGUIObjMessage* pObj, s32 sec) {
    DDON_STUB("uGUICraft::setupMakeTime")
    /* stub */
}

__attribute__((weak)) bool uGUICraft::checkUseItemCategory(u32 item_id, u32 use_item_cate_index) {
    DDON_STUB("uGUICraft::checkUseItemCategory")
    return {};
}

__attribute__((weak)) cItemParam* uGUICraft::getItemParam(u32 recipe_type, u32 category, u32 index) {
    DDON_STUB("uGUICraft::getItemParam")
    return nullptr;
}

void uGUICraft::eventDecide() {
    mSMENUdecide = true;
    if (static_cast<int>(mFlowNow) <= 11) {
        if (mFlowNow != 0) {
            if (mFlowNow == 1) {
                setFlowId(2u);
                mSMENUdecide = false;
            } else {
                if (mFlowNow == 2) {
                    sCraftManager::getInstance()->mCraftCtrl.setCreateCount(static_cast<u8>(1));
                    rCraftRecipe::cCraftRecipe* pRecipe = sCraftManager::getInstance()->getCraftRecipe(mRecipeType)->getRecipeList(mRecipeId);
                    if (pRecipe != nullptr) {
                        rItemList::rItemParam* pParam = sItemManager::getInstance()->getItemParam(pRecipe->getItemId());
                        if (pParam != nullptr) {
                            if (static_cast<unsigned int>(pParam->mCategory - 1) > 1) {
                                mOrder.mSelect = static_cast<u32>((pParam->mCategory == 5) ? 2 : 1);
                            } else {
                                mOrder.mSelect = 2;
                            }
                        }
                    }
                }
            }
        } else {
            if (mpTopSel != nullptr) {
                if (mpTopSel->mpListCtrl != nullptr) {
                    if (mpTopSel->mpListCtrl->getCurrentPos() != 1) {
                        if (mpTopSel->mpListCtrl->getCurrentPos() == 2) {
                            mMenuType = 2;
                        } else {
                            if (mpTopSel->mpListCtrl->getCurrentPos() == 3) {
                                mMenuType = 3;
                            } else {
                                mMenuType = 0;
                            }
                        }
                    } else {
                        mMenuType = 1;
                    }
                } else {
                    mMenuType = 0;
                }
                mpTopSel->hide();
            }
        }
    } else {
        if (static_cast<int>(mFlowNow) <= 19) {
            if (mFlowNow == 12) {
                setFlowId(13u);
                mSMENUdecide = false;
            }
        } else {
            if (static_cast<int>(mFlowNow) <= 30) {
                if (mFlowNow == 20) {
                    setFlowId(21u);
                    mSMENUdecide = false;
                }
            } else {
                if (static_cast<int>(mFlowNow) <= 45) {
                    if (mFlowNow != 31) {
                        if (mFlowNow == 35) {
                            setFlowId(36u);
                            mSMENUdecide = false;
                        } else {
                            if (mFlowNow == 41) {
                                mIsEndAnim = true;
                            }
                        }
                    } else {
                        setFlowId(32u);
                        mSMENUdecide = false;
                    }
                } else {
                    if (mFlowNow == 46) {
                        if (mpListCtrl != nullptr) {
                            if (mpListCtrl->mCurrentPos != 5) {
                                setFlowId(47u);
                                mSMENUdecide = false;
                            }
                        } else {
                            setFlowId(47u);
                            mSMENUdecide = false;
                        }
                    }
                }
            }
        }
    }
}

void uGUICraft::eventCancel() {
    mSMENUcancel = false;
    switch (mFlowNow) {
        case 0:
        {
            mSMENUcancel = true;
            break;
        }
        case 1:
        {
            mSMENUcancel = true;
            break;
        }
        case 2:
        {
            setFlowId(1u);
            break;
        }
        case 3:
        {
            mSMENUcancel = true;
            break;
        }
        case 4:
        {
            mSMENUcancel = true;
            break;
        }
        case 5:
        {
            mSMENUcancel = true;
            break;
        }
        case 6:
        {
            mSMENUcancel = true;
            break;
        }
        case 10:
        {
            mSMENUcancel = true;
            break;
        }
        case 12:
        {
            mSMENUcancel = true;
            break;
        }
        case 13:
        {
            setFlowId(12u);
            break;
        }
        case 14:
        {
            mSMENUcancel = true;
            break;
        }
        case 15:
        {
            mSMENUcancel = true;
            break;
        }
        case 16:
        {
            mSMENUcancel = true;
            break;
        }
        case 20:
        {
            mSMENUcancel = true;
            break;
        }
        case 21:
        {
            setFlowId(20u);
            break;
        }
        case 22:
        {
            mSMENUcancel = true;
            break;
        }
        case 23:
        {
            mSMENUcancel = true;
            break;
        }
        case 24:
        {
            mSMENUcancel = true;
            break;
        }
        case 31:
        {
            mSMENUcancel = true;
            break;
        }
        case 32:
        {
            setFlowId(31u);
            break;
        }
        case 33:
        {
            mSMENUcancel = true;
            break;
        }
        case 34:
        {
            mSMENUcancel = true;
            break;
        }
        case 35:
        {
            if (mpDetail != nullptr) {
                mpDetail->resetPageType();
                mSMENUcancel = true;
            } else {
                mSMENUcancel = true;
            }
            break;
        }
        case 36:
        {
            setFlowId(35u);
            break;
        }
        case 41:
        {
            mIsEndAnim = true;
            break;
        }
        case 45:
        {
            mSMENUcancel = true;
            break;
        }
        case 46:
        {
            mSMENUcancel = true;
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void uGUICraft::eventCheck() {
    DDON_STUB("uGUICraft::eventCheck")
    /* stub */
}

__attribute__((weak)) void uGUICraft::eventAdjustCursor() {
    DDON_STUB("uGUICraft::eventAdjustCursor")
    /* stub */
}

__attribute__((weak)) void uGUICraft::eventAdjustTab() {
    DDON_STUB("uGUICraft::eventAdjustTab")
    /* stub */
}

__attribute__((weak)) u32 uGUICraft::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUICraft::evCtrlDecide")
    return {};
}

u32 uGUICraft::evCtrlCancel(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 0;
        if (mFlowNow <= 46u) {
            if (((0x401B8170741Eul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) != 0) {
                msg->changeSE = 5;
                setInputEvent(67u);
                return 1;
            } else {
                if (((0x220400818061ul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) != 0) {
                    setInputEvent(67u);
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        if (mFlowNow <= 46u) {
            if ((((0x401B8170741Eul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) == 0) && (((0x220400818061ul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) == 0)) {
                return 0;
            }
            setInputEvent(67u);
            return 1;
        } else {
            return 0;
        }
    }
}

u32 uGUICraft::evCtrlClose(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 0;
        if (mFlowNow <= 46u) {
            if (((0x401B8170741Eul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) != 0) {
                msg->changeSE = 5;
                setInputEvent(68u);
                return 1;
            } else {
                if (((0x200400818060ul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) != 0) {
                    setInputEvent(68u);
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        if (mFlowNow <= 46u) {
            if ((((0x401B8170741Eul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) == 0) && (((0x200400818060ul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) == 0)) {
                return 0;
            }
            setInputEvent(68u);
            return 1;
        } else {
            return 0;
        }
    }
}

u32 uGUICraft::evCtrlCheck(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 0;
        u32 t0 = mFlowNow;
        if (t0 <= 36u) {
            if (((0x1980303006ul >> static_cast<unsigned long>(t0 & 63u)) & 1ul) != 0) {
                msg->changeSE = 4;
                setInputEvent(70u);
                return 1;
            } else {
                if (((0x200404008ul >> static_cast<unsigned long>(t0 & 63u)) & 1ul) != 0) {
                    u32 t2 = mOrder.mSelect;
                    const u32 list_index = mOrder.mListIndex[t2];
                    if (static_cast<int>(t0) <= 13) {
                        if (t0 == 3) {
                            if ((list_index - 1u) > 4u) {
                                return 0;
                            } else {
                                msg->changeSE = 5;
                                setInputEvent(69u);
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (t0 != 14) {
                            if (t0 == 22) {
                                if ((list_index - 1u) > 4u) {
                                    return 0;
                                } else {
                                    msg->changeSE = 5;
                                    setInputEvent(69u);
                                    return 1;
                                }
                            } else {
                                if (t0 == 33) {
                                    if (list_index == 2) {
                                        msg->changeSE = 5;
                                        setInputEvent(69u);
                                        return 1;
                                    }
                                }
                                return 0;
                            }
                        } else {
                            if ((list_index - 2u) <= 3u) {
                                msg->changeSE = 5;
                                setInputEvent(69u);
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        u32 t0 = mFlowNow;
        if (t0 <= 36u) {
            if (((0x1980303006ul >> static_cast<unsigned long>(t0 & 63u)) & 1ul) != 0) {
                setInputEvent(70u);
                return 1;
            } else {
                if (((0x200404008ul >> static_cast<unsigned long>(t0 & 63u)) & 1ul) != 0) {
                    u32 t2 = mOrder.mSelect;
                    const u32 list_index = mOrder.mListIndex[t2];
                    if (static_cast<int>(t0) <= 13) {
                        if (t0 == 3) {
                            if ((list_index - 1u) > 4u) {
                                return 0;
                            } else {
                                setInputEvent(69u);
                                return 1;
                            }
                        } else {
                            return 0;
                        }
                    } else {
                        if (t0 != 14) {
                            if (t0 == 22) {
                                if ((list_index - 1u) > 4u) {
                                    return 0;
                                } else {
                                    setInputEvent(69u);
                                    return 1;
                                }
                            } else {
                                if (t0 == 33) {
                                    if (list_index == 2) {
                                        setInputEvent(69u);
                                        return 1;
                                    }
                                }
                                return 0;
                            }
                        } else {
                            if ((list_index - 2u) <= 3u) {
                                setInputEvent(69u);
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
}

u32 uGUICraft::evCtrlStart(cControl::Message* msg) {
    if (mFlowNow != 2) {
        if (mFlowNow == 13) {
            if (sGame::getInstance()->isChargeEffect(nGpCourse::GP_COURSE_EFFECT_CRAFT_BAGGAGE_EXTEND)) {
                rCraftRecipe::cCraftRecipe* pRecipe = sCraftManager::getInstance()->getCraftRecipe(mRecipeType)->getRecipeList(mRecipeId);
                if ((pRecipe != nullptr) && !pRecipe->mIsBaggage) {
                    if (msg != nullptr) {
                        msg->changeSE = 4;
                    }
                    setInputEvent(73u);
                    return 1;
                }
                if (msg != nullptr) {
                    msg->changeSE = 0;
                }
                setInputEvent(0u);
                return 0;
            } else {
                sGUI* t0 = sGUI::getInstance();
                static_cast<sGUIExt*>(t0)->requestAnnounce(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(mpGMDRes, 244u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                if (msg != nullptr) {
                    msg->changeSE = 20;
                }
                setInputEvent(2u);
                return 1;
            }
        } else {
            if (msg != nullptr) {
                msg->changeSE = 0;
            }
            setInputEvent(0u);
            return 0;
        }
    } else {
        if (sGame::getInstance()->isChargeEffect(nGpCourse::GP_COURSE_EFFECT_CRAFT_BAGGAGE_EXTEND)) {
            rCraftRecipe::cCraftRecipe* pRecipe = sCraftManager::getInstance()->getCraftRecipe(mRecipeType)->getRecipeList(mRecipeId);
            if ((pRecipe != nullptr) && !pRecipe->mIsBaggage) {
                if (msg != nullptr) {
                    msg->changeSE = 4;
                }
                setInputEvent(73u);
                return 1;
            }
            if (msg != nullptr) {
                msg->changeSE = 0;
            }
            setInputEvent(0u);
            return 0;
        } else {
            sGUI* t0 = sGUI::getInstance();
            static_cast<sGUIExt*>(t0)->requestAnnounce(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(mpGMDRes, 244u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
            if (msg != nullptr) {
                msg->changeSE = 20;
            }
            setInputEvent(2u);
            return 1;
        }
    }
}

u32 uGUICraft::evCtrlAdjustCursor(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->pSender != nullptr) {
            if (mFlowNow <= 33u) {
                if (((0x200404008ul >> static_cast<unsigned long>(mFlowNow & 63u)) & 1ul) == 0) {
                    if (msg->pSender->getCurrentPos() == msg->pSender->mOldPos) {
                        msg->changeSE = 0;
                    } else {
                        msg->changeSE = 2;
                        setInputEvent(76u);
                    }
                } else {
                    msg->changeSE = 2;
                    setInputEvent(76u);
                }
            } else {
                if (msg->pSender->getCurrentPos() == msg->pSender->mOldPos) {
                    msg->changeSE = 0;
                } else {
                    msg->changeSE = 2;
                    setInputEvent(76u);
                }
            }
        } else {
            msg->changeSE = 2;
            setInputEvent(76u);
        }
    } else {
        setInputEvent(76u);
    }
    return 0;
}

u32 uGUICraft::evCtrlAdjustTab(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            if ((msg->pSender != nullptr) && (msg->pSender->getCurrentPos() != msg->pSender->mOldPos)) {
                msg->changeSE = 3;
                setInputEvent(77u);
                return 1;
            }
            msg->changeSE = 0;
            setInputEvent(0u);
            return 0;
        }
        msg->changeSE = 3;
    }
    setInputEvent(77u);
    return 1;
}

__attribute__((weak)) u32 uGUICraft::evCtrlLeft(cControl::Message* msg) {
    DDON_STUB("uGUICraft::evCtrlLeft")
    return {};
}

u32 uGUICraft::evCtrlRight(cControl::Message* msg) {
    if (mFlowNow == 46) {
        if (mPoint.mHavePoint != 0) {
            if (msg != nullptr) {
                msg->changeSE = 2;
            }
            setInputEvent(79u);
        } else {
            if (msg != nullptr) {
                msg->changeSE = 20;
            }
            setInputEvent(2u);
        }
    } else {
        if (msg != nullptr) {
            msg->changeSE = 2;
        }
        setInputEvent(79u);
    }
    return 0;
}

__attribute__((weak)) u32 uGUICraft::evCtrlMouseClick(cControl::Message* msg) {
    DDON_STUB("uGUICraft::evCtrlMouseClick")
    return {};
}

u32 uGUICraft::callbackPopSel00(MtObject* pDummy, MtObject* pUnit) {
    if (pUnit != nullptr) {
        static_cast<uGUIBase*>(pUnit)->setInputEvent(71u);
    }
    return 0;
}

u32 uGUICraft::callbackPopSel01(MtObject* pDummy, MtObject* pUnit) {
    if (pUnit != nullptr) {
        static_cast<uGUIBase*>(pUnit)->setInputEvent(72u);
    }
    return 0;
}

u32 uGUICraft::getTopMenuPos() {
    if (mpTopSel != nullptr) {
        if (mpTopSel->mpListCtrl != nullptr) {
            return static_cast<u32>(mpTopSel->mpListCtrl->getCurrentPos());
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUICraft::getListPos() {
    DDON_STUB("uGUICraft::getListPos")
    return {};
}

__attribute__((weak)) u32 uGUICraft::getMenuNo() {
    DDON_STUB("uGUICraft::getMenuNo")
    return {};
}

__attribute__((weak)) s32 uGUICraft::getSMenuCursorY() {
    DDON_STUB("uGUICraft::getSMenuCursorY")
    return {};
}

inline uGUICraft::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::MyDTI uGUICraft::DTI("uGUICraft", &::uGUIBase::DTI, 0x10220ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::MyDTI::newInstance")
    return nullptr;
}

uGUICraft::stOrder::stOrder() {
    DDON_STUB("uGUICraft::stOrder::stOrder")
    /* stub */
}

uGUICraft::stMakeItem::stMakeItem() {
    DDON_STUB("uGUICraft::stMakeItem::stMakeItem")
    /* stub */
}

const MtDTI& uGUICraft::cListItem::getDTI() const {
    return uGUICraft::cListItem::DTI;
}

inline void uGUICraft::cListItem::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICraft::cListItem::DTI)->memFree(p_addr);
}

inline uGUICraft::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::cListItem::MyDTI uGUICraft::cListItem::DTI("uGUICraft::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 656ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::cListItem::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::cListItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICraft::cAddListItem::getDTI() const {
    return uGUICraft::cAddListItem::DTI;
}

inline void uGUICraft::cAddListItem::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICraft::cAddListItem::DTI)->memFree(p_addr);
}

inline uGUICraft::cAddListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::cAddListItem::MyDTI uGUICraft::cAddListItem::DTI("uGUICraft::cAddListItem", &::uGUIBase::cScrollListItemBase::DTI, 576ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::cAddListItem::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::cAddListItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICraft::cListInfo::getDTI() const {
    return uGUICraft::cListInfo::DTI;
}

inline void uGUICraft::cListInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICraft::cListInfo::DTI)->memFree(p_addr);
}

inline uGUICraft::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::cListInfo::MyDTI uGUICraft::cListInfo::DTI("uGUICraft::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::cListInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICraft::cCreateRecipeSort::getDTI() const {
    return uGUICraft::cCreateRecipeSort::DTI;
}

inline void uGUICraft::cCreateRecipeSort::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICraft::cCreateRecipeSort::DTI)->memFree(p_addr);
}

inline uGUICraft::cCreateRecipeSort::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::cCreateRecipeSort::MyDTI uGUICraft::cCreateRecipeSort::DTI("uGUICraft::cCreateRecipeSort", &::cUIObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::cCreateRecipeSort::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::cCreateRecipeSort::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICraft::cAddListInfo::getDTI() const {
    return uGUICraft::cAddListInfo::DTI;
}

uGUICraft::cAddListInfo::~cAddListInfo() {
}

inline uGUICraft::cAddListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICraft::cAddListInfo::MyDTI uGUICraft::cAddListInfo::DTI("uGUICraft::cAddListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICraft::cAddListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUICraft::cAddListInfo::MyDTI::newInstance")
    return nullptr;
}

