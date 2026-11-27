// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIArisenCard.h"
#include "Protocol/PacketData/Achievement.h"
#include "Protocol/PacketData/CharacterCommon.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cCharacterData.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cControl.h"
#include "cEquipData.h"
#include "cGUIControlMgr.h"
#include "cGUIExtNetMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "rAchievement.h"
#include "rArchiveListArray.h"
#include "rCharacterEdit.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIArisenCardPop.h"
#include "uGUIArisenCardPopPawn.h"
#include "uGUIBase.h"
#include "uGUIPopCmd01.h"
#include "uGUIPopDetail01.h"
#include "uGUIPopSkillInfo.h"
#include "uUIMockUp.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIArisenCard::getDTI() const {
    return uGUIArisenCard::DTI;
}

void* uGUIArisenCard::operator new(size_t sz, u32 align) {
    return uGUIArisenCard::getAllocator()->memAlloc(sz, align, uGUIArisenCard::DTI.getID());
}

u32 uGUIArisenCard::getMotionMaxFrame(u32 MotNo) {
    if (mpMockup != nullptr) {
        return static_cast<unsigned int>(static_cast<long>(mpMockup->getMotionMaxFrame(MotNo)));
    } else {
        return 0;
    }
}

void uGUIArisenCard::setMotion(u32 MotNo, u32 FrameNo, f32 Hokan) {
    uUIMockUp* t0 = mpMockup;
    if (t0 == nullptr) {
        return;
    }
    t0->setMotion(MotNo, rCharacterEdit::toF32(static_cast<unsigned short>(FrameNo), 0.01f), Hokan);
}

__attribute__((noinline)) uGUIArisenCard::~uGUIArisenCard() {
    DDON_STUB("uGUIArisenCard::~uGUIArisenCard")
    /* stub */
}

bool uGUIArisenCard::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISEN_CARD_GUI"), 129u, 1473138533l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISENCARD_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpAchieveRes == nullptr) && ((mpAchieveRes = static_cast<rAchievementHeader*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ACHIEVEMENTTOTALINFO_ACH"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpMenuCmnGMDRes == nullptr) && ((mpMenuCmnGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MENU_COMMON_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpParamGMDRes == nullptr) && ((mpParamGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PARAMETER_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIArisenCard::updatePtr() {
    if (mpMockup != nullptr) {
        if (!mpMockup->isEnable()) {
            mpMockup = nullptr;
        }
    }
    if (mpSubMenu != nullptr) {
        if (!mpSubMenu->isEnable()) {
            mpSubMenu = nullptr;
        }
    }
    if (mpCardPop != nullptr) {
        if (!mpCardPop->isEnable()) {
            mpCardPop = nullptr;
        }
    }
    if (mpItemDetail != nullptr) {
        if (!mpItemDetail->isEnable()) {
            mpItemDetail = nullptr;
        }
    }
    if (mpSkillDetail != nullptr) {
        if (!mpSkillDetail->isEnable()) {
            mpSkillDetail = nullptr;
        }
    }
}

__attribute__((weak)) void uGUIArisenCard::setup() {
    DDON_STUB("uGUIArisenCard::setup")
    /* stub */
}

void uGUIArisenCard::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpAchieveRes != nullptr) {
        mpAchieveRes->release();
        mpAchieveRes = nullptr;
    }
    if (mpMenuCmnGMDRes != nullptr) {
        mpMenuCmnGMDRes->release();
        mpMenuCmnGMDRes = nullptr;
    }
    if (mpParamGMDRes != nullptr) {
        mpParamGMDRes->release();
        mpParamGMDRes = nullptr;
    }
    if (mpMockup != nullptr) {
        mpMockup->kill();
        mpMockup = nullptr;
    }
    if (mpSubMenu != nullptr) {
        mpSubMenu->mEndType = 0;
        mpSubMenu->end();
    }
    mpSubMenu = nullptr;
    if (mpCardPop != nullptr) {
        mpCardPop->mEndType = 0;
        mpCardPop->end();
    }
    mpCardPop = nullptr;
    if (mpPawnProfile != nullptr) {
        mpPawnProfile->mEndType = 0;
        mpPawnProfile->end();
    }
    mpPawnProfile = nullptr;
    if (mpItemDetail != nullptr) {
        mpItemDetail->mEndType = 0;
        mpItemDetail->end();
    }
    mpItemDetail = nullptr;
    if (mpSkillDetail != nullptr) {
        mpSkillDetail->mEndType = 0;
        mpSkillDetail->end();
    }
    mpSkillDetail = nullptr;
}

void uGUIArisenCard::moveInput() {
    if (!manageEnv()) {
        return;
    }
    mClose.execute();
    if (mInputEventId == 0) {
        switch (mNowPage) {
            case 0:
            {
                mControls.moveInput();
                if (mpCtrl != nullptr) {
                    mpCtrl->execute();
                }
                break;
            }
            case 1:
            {
                mControls.moveInput();
                if (mpCtrl != nullptr) {
                    mpCtrl->execute();
                }
                break;
            }
            case 2:
            {
                mSKABControls.moveInput();
                if (mpCtrl != nullptr) {
                    mpCtrl->execute();
                }
                break;
            }
            case 3:
            {
                mHistoryScrollbar.executeCtrl();
                if (mpCtrl != nullptr) {
                    mpCtrl->execute();
                }
                break;
            }
            case 4:
            {
                if (mpPageCtrl != nullptr) {
                    mpPageCtrl->execute();
                    mPager.execute();
                    if (mpCtrl != nullptr) {
                        mpCtrl->execute();
                    }
                } else {
                    mPager.execute();
                    if (mpCtrl != nullptr) {
                        mpCtrl->execute();
                    }
                }
                break;
            }
            default:
            {
                if (mpCtrl != nullptr) {
                    mpCtrl->execute();
                }
                break;
            }
        }
    } else {
        if (mpCtrl != nullptr) {
            mpCtrl->execute();
        }
    }
}

__attribute__((weak)) void uGUIArisenCard::moveEvent() {
    DDON_STUB("uGUIArisenCard::moveEvent")
    /* stub */
}

__attribute__((weak)) bool uGUIArisenCard::manageEnv() {
    DDON_STUB("uGUIArisenCard::manageEnv")
    return {};
}

void uGUIArisenCard::updateMenuDispWait() {
    if (sMenu::getInstance()->mMenuDispStatus.mMenuRno[0] != 6) {
        return;
    }
    cContextInterface::getContextPlayerInfo(sMenu::getInstance()->mMenuDispStatus.getContext());
    setUseIGUIExtNetFunc(static_cast<sGUIExt*>(sGUI::getInstance())->requestGetJobChangeList(true));
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCard::updateServerWait);
}

void uGUIArisenCard::updateServerWait() {
    const cContextPlayerInfo* pplinfo = cContextInterface::getContextPlayerInfo(sMenu::getInstance()->mMenuDispStatus.getContext());
    if (pplinfo == nullptr) {
        return;
    }
    const u8 t0 = pplinfo->mCurrentJob_pri;
    if (static_cast<sGUIExt*>(sGUI::getInstance())->getCustomSkillData(t0) == nullptr) {
        return;
    }
    if (static_cast<sGUIExt*>(sGUI::getInstance())->getNormalSkillData(t0) == nullptr) {
        return;
    }
    if (!static_cast<sGUIExt*>(sGUI::getInstance())->isCompleteMaintenanceRequest()) {
        return;
    }
    initDisp();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCard::updateWait1st);
}

__attribute__((weak)) void uGUIArisenCard::updateWait1st() {
    DDON_STUB("uGUIArisenCard::updateWait1st")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateWait() {
    DDON_STUB("uGUIArisenCard::updateWait")
    /* stub */
}

void uGUIArisenCard::updateMatching() {
    nMenu::MENU_RET t0 = sMenu::getInstance()->mMatchingProfile.moveMatchingProfile();
    if (t0 != nMenu::MENU_RET_SUCCESS) {
        if (t0 != nMenu::MENU_RET_CANCEL) {
            if (t0 == nMenu::MENU_RET_EXIT) {
                sMenu* t1 = sMenu::getInstance();
                cContextInterface::getContextPlayerInfo(t1->mMenuDispStatus.getContext());
                initMatchingProfile(static_cast<const cContextPlayerInfo*>(nullptr), t1->mMenuDispStatus.getCharData());
                mIsMoveMatchingProfile = false;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCard::updateWait);
            }
        } else {
            mIsMoveMatchingProfile = false;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCard::updateWait);
        }
    } else {
        sMenu* t1 = sMenu::getInstance();
        cContextInterface::getContextPlayerInfo(t1->mMenuDispStatus.getContext());
        initMatchingProfile(static_cast<const cContextPlayerInfo*>(nullptr), t1->mMenuDispStatus.getCharData());
        mIsMoveMatchingProfile = false;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCard::updateWait);
    }
}

u32 uGUIArisenCard::evCtrlCancel(cControl::Message* pMsg) {
    setInputEvent(66u);
    return 1;
}

u32 uGUIArisenCard::evCtrlDecide(cControl::Message* pMsg) {
    return 0;
}

u32 uGUIArisenCard::evCtrlTabLR(cControl::Message* pMsg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIArisenCard::evCtrlEquipMoveUD(cControl::Message* pMsg) {
    setInputEvent(70u);
    return 1;
}

u32 uGUIArisenCard::evCtrlEquipMouseClick(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        if (pMsg->click_vol <= 7) {
            mControls.setCurrentPos(0u, 0);
            mControls.setCurrentPos(1u, pMsg->mouse_hit_id);
        } else {
            mControls.setCurrentPos(0u, 1);
            mControls.setCurrentPos(2u, pMsg->mouse_hit_id);
        }
        setInputEvent(70u);
        pMsg->changeSE = 20;
        return 1;
    } else {
        return 0;
    }
}

u32 uGUIArisenCard::evCtrlEquipMoveLR(cControl::Message* pMsg) {
    setInputEvent(70u);
    return 1;
}

u32 uGUIArisenCard::evCtrlStartSubMenu(cControl::Message* pMsg) {
    if (mpSubMenu == nullptr) {
        if (mNowPage == 0) {
            if (mIsPlayer) {
                if (!mIsMyData) {
                    return 0;
                } else {
                    setInputEvent(73u);
                    return 1;
                }
            } else {
                if (sMenu::getInstance()->mMenuDispStatus.isMyPawn()) {
                    setInputEvent(73u);
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

u32 uGUIArisenCard::evCtrlSKABMoveLR(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        if (pMsg->reason == nGUIExt::TRG_LEFT) {
            s32 t0 = mSKABControls.getOldPos(0u);
            if (t0 != 2) {
                if (t0 != 1) {
                    if (t0 != 0) {
                        return 0;
                    }
                }
            } else {
                mSKABControls.setCurrentPos(2u, mSKABControls.getCurrentPos(3u));
            }
            setInputEvent(69u);
            return 1;
        } else {
            if (pMsg->reason == nGUIExt::TRG_RIGHT) {
                s32 t1 = mSKABControls.getOldPos(0u);
                if (t1 != 2) {
                    if (t1 == 1) {
                        s32 t2 = mSKABControls.getCurrentPos(2u);
                        if (t2 < static_cast<int>(mSKABControls.mControl[3].mItemNum)) {
                            mSKABControls.setCurrentPos(3u, mSKABControls.getCurrentPos(2u));
                        } else {
                            mSKABControls.setCurrentPos(0u, 1);
                        }
                        setInputEvent(69u);
                        return 1;
                    } else {
                        if (t1 == 0) {
                            if (mAbilityNum == 0) {
                                mSKABControls.setCurrentPos(0u, 0);
                                setInputEvent(68u);
                            } else {
                                setInputEvent(69u);
                            }
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    setInputEvent(69u);
                    return 1;
                }
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
}

u32 uGUIArisenCard::evCtrlOrbPage(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        pMsg->changeSE = 2;
    }
    setInputEvent(74u);
    return 1;
}

__attribute__((weak)) void uGUIArisenCard::initMockup() {
    DDON_STUB("uGUIArisenCard::initMockup")
    /* stub */
}

void uGUIArisenCard::initItemDetail() {
    cGUIInstance* t0 = getInstance(264u, false);
    mpItemDetailNull = static_cast<cGUIInstNull*>(t0);
    uGUIPopDetail01* t2 = mpItemDetail;
    if (t2 != nullptr) {
        t2->mEndType = 0;
        t2->end();
    }
    mpItemDetail = nullptr;
    if ((mpItemDetail = new (16u) uGUIPopDetail01(static_cast<uGUIBase*>(this), mIsChatSubMenu)) == nullptr) {
        return;
    }
    cGUIInstNull* t8 = mpItemDetailNull;
    MtVector4 frame56(getInstancePositionRoot(static_cast<cGUIInstance*>(t8), static_cast<MtVector3*>(nullptr)));
    uGUIPopDetail01* t9 = mpItemDetail;
    f32 t10 = frame56.x;
    f32 t11 = frame56.y;
    f32 t12 = frame56.z;
    t9->mPos.x = t10;
    t9->mPos.y = t11;
    t9->mPos.z = t12;
    t9->mPos.pad_ = 0.0f;
    unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t9) + 5320);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t9) + 5320) = t13 | 5;
    sUnit* t14 = sUnit::getInstance();
    unsigned int t15 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16);
    u32 t16 = t14->getNextMoveLineId(mMoveLine);
    uGUIPopDetail01* t18 = mpItemDetail;
    u64 t19 = getUnitGroup();
    t14->addBottom(static_cast<MOVE_LINE>(t16), static_cast<cUnit*>(t18), t19);
    uGUIPopDetail01* t21 = mpItemDetail;
    if (t21 == nullptr) {
        return;
    }
    t21->mIsDraw = false;
}

__attribute__((weak)) void uGUIArisenCard::initDisp() {
    DDON_STUB("uGUIArisenCard::initDisp")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initHeader(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, u32 ValidInfo) {
    DDON_STUB("uGUIArisenCard::initHeader")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initHeaderPawn(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const cCharacterData::stPawnData* pPawn, u32 ValidInfo) {
    DDON_STUB("uGUIArisenCard::initHeaderPawn")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initEquip(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo) {
    DDON_STUB("uGUIArisenCard::initEquip")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initProfile(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const cCharacterData* pData) {
    DDON_STUB("uGUIArisenCard::initProfile")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initMatchingProfile(const cContextPlayerInfo* pPlInfo, const cCharacterData* pData) {
    DDON_STUB("uGUIArisenCard::initMatchingProfile")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initPawnInfo(const cCharacterData::stPawnData* pPawn, u32 PawnType) {
    DDON_STUB("uGUIArisenCard::initPawnInfo")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initHpStamina(const cContextInstHm* pContext) {
    DDON_STUB("uGUIArisenCard::initHpStamina")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initStatus(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const nJobParam::cJobInfo* pJobInfo, bool IsExpDisp) {
    DDON_STUB("uGUIArisenCard::initStatus")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initSkill(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo) {
    DDON_STUB("uGUIArisenCard::initSkill")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initAbility(const cContextPlayerInfo* pPlInfo, u32 AbilityMaxCost) {
    DDON_STUB("uGUIArisenCard::initAbility")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initAchievement(const cCharacterData* pData) {
    DDON_STUB("uGUIArisenCard::initAchievement")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initHistory(const cCharacterData* pData) {
    DDON_STUB("uGUIArisenCard::initHistory")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initHistoryPawn(const cCharacterData::stPawnData* pPawn) {
    DDON_STUB("uGUIArisenCard::initHistoryPawn")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initDevoteOrb(const cCharacterData::stCardDogmaOrb& Orb, const cCharacterData::stCardJobOrbTree& jobOrb, bool isDispJobOrb) {
    DDON_STUB("uGUIArisenCard::initDevoteOrb")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initRentalInfo(const cCharacterData::stCardPawnTotalValue& PawnValue) {
    DDON_STUB("uGUIArisenCard::initRentalInfo")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updatePageDisp() {
    DDON_STUB("uGUIArisenCard::updatePageDisp")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateSkillAbility() {
    DDON_STUB("uGUIArisenCard::updateSkillAbility")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::setElementIcon(cGUIInstAnimation* pIcon, f32 PosX, const cContextPlayerInfo* pPlInfo, s32 Id) {
    DDON_STUB("uGUIArisenCard::setElementIcon")
    /* stub */
}

void uGUIArisenCard::setupCustomSkillIcon(u32 Index, cGUIInstance* pInst) {
    if (Index <= 9u) {
        if (Index != 0) {
            if (pInst != nullptr) {
                cGUIInstance* t0 = ManageDuplicate(pInst, pInst->getParent());
                if ((mSkillDispList[Index].mpInstBase = static_cast<cGUIInstNull*>(t0)) != nullptr) {
                    mSkillDispList[Index].mpPlate = static_cast<cGUIInstAnimation*>(t0->getDuplicateInstanceFromId(430u));
                    cGUIInstance* t1 = mSkillDispList[Index].mpInstBase->getDuplicateInstanceFromId(438u);
                    cGUIInstance* t2 = mSkillDispList[Index].mpInstBase->getDuplicateInstanceFromId(439u);
                    mSkillDispList[Index].mIcon.setup(static_cast<uGUIBase*>(this), t1, t2, mSkillDispList[Index].mpInstBase->getDuplicateInstanceFromId(440u));
                    mSkillDispList[Index].mpInstPointerTarget = mSkillDispList[Index].mpInstBase->getDuplicateInstanceFromId(437u);
                    if (mSkillDispList[Index].mpInstBase != nullptr) {
                        mSkillDispList[Index].mpInstBase->setVisible(false);
                        cGUIObject* t5 = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 152u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                            mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                            mSkillDispList[Index].mIcon.setLevelVisible(false);
                            mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                            mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                            u32 t6 = mSkillScrollbar.mItemArray.mLength;
                            u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                            if (t6 < t7) {
                                mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            } else {
                                void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                                memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                                memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                                mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                                mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                                u32 t9 = mSkillScrollbar.mItemArray.mLength;
                                mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            }
                        } else {
                            mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                            mSkillDispList[Index].mIcon.setLevelVisible(false);
                            mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                            mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                            u32 t6 = mSkillScrollbar.mItemArray.mLength;
                            u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                            if (t6 < t7) {
                                mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            } else {
                                void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                                memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                                memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                                mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                                mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                                u32 t9 = mSkillScrollbar.mItemArray.mLength;
                                mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            }
                        }
                    } else {
                        cGUIObject* t5 = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 152u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                            mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                            mSkillDispList[Index].mIcon.setLevelVisible(false);
                            mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                            mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                            u32 t6 = mSkillScrollbar.mItemArray.mLength;
                            u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                            if (t6 < t7) {
                                mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            } else {
                                void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                                memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                                memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                                mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                                mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                                u32 t9 = mSkillScrollbar.mItemArray.mLength;
                                mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            }
                        } else {
                            mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                            mSkillDispList[Index].mIcon.setLevelVisible(false);
                            mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                            mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                            u32 t6 = mSkillScrollbar.mItemArray.mLength;
                            u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                            if (t6 < t7) {
                                mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            } else {
                                void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                                memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                                memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                                mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                                mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                                u32 t9 = mSkillScrollbar.mItemArray.mLength;
                                mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                                mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                            }
                        }
                    }
                }
            } else {
                mSkillDispList[Index].mpInstBase = nullptr;
            }
        } else {
            mSkillDispList[Index].mpInstBase = static_cast<cGUIInstNull*>(pInst);
            mSkillDispList[Index].mpPlate = static_cast<cGUIInstAnimation*>(getInstance(430u, false));
            cGUIInstance* t3 = getInstance(438u, false);
            cGUIInstance* t4 = getInstance(439u, false);
            mSkillDispList[Index].mIcon.setup(static_cast<uGUIBase*>(this), t3, t4, getInstance(440u, false));
            mSkillDispList[Index].mpInstPointerTarget = getInstance(437u, false);
            setInstanceExecuteTree(static_cast<cGUIInstance*>(mSkillDispList[Index].mpInstBase), false);
            if (mSkillDispList[Index].mpInstBase != nullptr) {
                mSkillDispList[Index].mpInstBase->setVisible(false);
                cGUIObject* t5 = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 152u);
                if (t5 != nullptr) {
                    setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                    mSkillDispList[Index].mIcon.setLevelVisible(false);
                    mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                    mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                    u32 t6 = mSkillScrollbar.mItemArray.mLength;
                    u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                    if (t6 < t7) {
                        mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    } else {
                        void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                        memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                        memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                        mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                        mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                        u32 t9 = mSkillScrollbar.mItemArray.mLength;
                        mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    }
                } else {
                    mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                    mSkillDispList[Index].mIcon.setLevelVisible(false);
                    mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                    mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                    u32 t6 = mSkillScrollbar.mItemArray.mLength;
                    u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                    if (t6 < t7) {
                        mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    } else {
                        void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                        memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                        memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                        mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                        mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                        u32 t9 = mSkillScrollbar.mItemArray.mLength;
                        mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    }
                }
            } else {
                cGUIObject* t5 = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 152u);
                if (t5 != nullptr) {
                    setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                    mSkillDispList[Index].mIcon.setLevelVisible(false);
                    mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                    mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                    u32 t6 = mSkillScrollbar.mItemArray.mLength;
                    u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                    if (t6 < t7) {
                        mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    } else {
                        void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                        memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                        memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                        mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                        mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                        u32 t9 = mSkillScrollbar.mItemArray.mLength;
                        mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    }
                } else {
                    mSkillDispList[Index].mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_SKILL;
                    mSkillDispList[Index].mIcon.setLevelVisible(false);
                    mSkillDispList[Index].mpInstMouseCollision = static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate);
                    mSkillDispList[Index].mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(mSkillDispList[Index].mpPlate), 160u);
                    u32 t6 = mSkillScrollbar.mItemArray.mLength;
                    u32 t7 = mSkillScrollbar.mItemArray.mBufsiz;
                    if (t6 < t7) {
                        mSkillScrollbar.mItemArray.mLength = t6 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t6] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    } else {
                        void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                        memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                        memcpy(t8, static_cast<const void*>(mSkillScrollbar.mItemArray.mpArray), static_cast<size_t>(mSkillScrollbar.mItemArray.mLength) * 8);
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSkillScrollbar.mItemArray.mpArray));
                        mSkillScrollbar.mItemArray.mpArray = static_cast<MtObject* *>(t8);
                        mSkillScrollbar.mItemArray.mBufsiz = t7 + 32u;
                        u32 t9 = mSkillScrollbar.mItemArray.mLength;
                        mSkillScrollbar.mItemArray.mLength = t9 + 1u;
                        mSkillScrollbar.mItemArray.mpArray[t9] = static_cast<MtObject*>(&mSkillDispList[Index]);
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIArisenCard::updateCustomSkillIcon(u32 Index, uGUIArisenCard::cScrollDispSkillList* pDispInfo, uGUIArisenCard::cScrollSkillList* pItemInfo) {
    DDON_STUB("uGUIArisenCard::updateCustomSkillIcon")
    /* stub */
}

void uGUIArisenCard::setupAbilityIcon(uGUIArisenCard::cScrollDispAbilityList& List, cGUIInstNull* pInst, f32 PosX, bool IsOrg) {
    List.mpInstPointerTarget = static_cast<cGUIInstance*>(pInst);
    if (pInst != nullptr) {
        pInst->setPositionX(PosX);
        if (IsOrg) {
            List.mpPlate = static_cast<cGUIInstAnimation*>(getInstance(431u, false));
            cGUIInstance* t0 = getInstance(447u, false);
            cGUIInstance* t1 = getInstance(448u, false);
            List.mIcon.setup(static_cast<uGUIBase*>(this), t0, t1, getInstance(449u, false));
            setInstanceVisibleTree(static_cast<cGUIInstance*>(pInst), false);
            setInstanceExecuteTree(static_cast<cGUIInstance*>(pInst), false);
            cGUIObject* t4 = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 132u);
            if (t4 != nullptr) {
                setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
            }
            List.mpInstMouseCollision = static_cast<cGUIInstance*>(List.mpPlate);
            List.mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 135u);
            List.mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_ABILITY;
            List.mIcon.setLevelVisible(false);
        } else {
            List.mpPlate = static_cast<cGUIInstAnimation*>(pInst->getDuplicateInstanceFromId(431u));
            cGUIInstance* t2 = pInst->getDuplicateInstanceFromId(447u);
            cGUIInstance* t3 = pInst->getDuplicateInstanceFromId(448u);
            List.mIcon.setup(static_cast<uGUIBase*>(this), t2, t3, pInst->getDuplicateInstanceFromId(449u));
            cGUIObject* t4 = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 132u);
            if (t4 != nullptr) {
                setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
            }
            List.mpInstMouseCollision = static_cast<cGUIInstance*>(List.mpPlate);
            List.mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 135u);
            List.mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_ABILITY;
            List.mIcon.setLevelVisible(false);
        }
    } else {
        if (IsOrg) {
            List.mpPlate = static_cast<cGUIInstAnimation*>(getInstance(431u, false));
            cGUIInstance* t0 = getInstance(447u, false);
            cGUIInstance* t1 = getInstance(448u, false);
            List.mIcon.setup(static_cast<uGUIBase*>(this), t0, t1, getInstance(449u, false));
            setInstanceVisibleTree(static_cast<cGUIInstance*>(pInst), false);
            setInstanceExecuteTree(static_cast<cGUIInstance*>(pInst), false);
            cGUIObject* t4 = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 132u);
            if (t4 != nullptr) {
                setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
            }
            List.mpInstMouseCollision = static_cast<cGUIInstance*>(List.mpPlate);
            List.mpObjMouseCollision = getObjectFromId(static_cast<cGUIInstance*>(List.mpPlate), 135u);
            List.mIcon.mType = uGUIBase::cReferenceUIIconSkill::TYPE_ABILITY;
            List.mIcon.setLevelVisible(false);
        }
    }
}

void uGUIArisenCard::updateSkillDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    if (pDispItem == nullptr) {
        return;
    }
    if (pListItem == nullptr) {
        return;
    }
    cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(pDispItem->mpInstBase), true);
    if (pDispItem->mpInstBase != nullptr) {
        pDispItem->mpInstBase->setVisible(true);
        if (pDispItem->mpInstBase != nullptr) {
            pDispItem->mpInstBase->setPositionY(pListItem->mMouseTopPos);
        }
    }
    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pListItem) + 37)) != 0) {
        updateCustomSkillIcon(Index, static_cast<cScrollDispSkillList*>(pDispItem), static_cast<cScrollSkillList*>(pListItem));
    } else {
        cScrollDispSkillList* pItem = static_cast<cScrollDispSkillList*>(pDispItem);
        if (pItem->mpPlate != nullptr) {
            cGUIObject* t0 = getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 131u);
            if (t0 != nullptr) {
                cScrollSkillList* pInfo = static_cast<cScrollSkillList*>(pListItem);
                setObjectMessage(t0, static_cast<sGUIExt*>(sGUI::getInstance())->getNormalSkillName(pInfo->mJobId, pInfo->mSkillNo), 0u, false);
                if (pInfo->mSkillNo != 0) {
                    pItem->mIcon.setImage(pInfo->mIconNo);
                }
            } else {
                cScrollSkillList* pInfo = static_cast<cScrollSkillList*>(pListItem);
                if (pInfo->mSkillNo != 0) {
                    pItem->mIcon.setImage(pInfo->mIconNo);
                }
            }
        } else {
            cScrollSkillList* pInfo = static_cast<cScrollSkillList*>(pListItem);
            if (pInfo->mSkillNo != 0) {
                pItem->mIcon.setImage(pInfo->mIconNo);
            }
        }
    }
}

void uGUIArisenCard::updateSkillHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    cScrollDispSkillList* pItem = static_cast<cScrollDispSkillList*>(pDispItem);
    setObjectMessage(getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 94u), "", 0u, false);
    setObjectMessage(getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 139u), "", 0u, false);
    setObjectMessage(getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 131u), "", 0u, false);
    setObjectMessage(getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 152u), "", 0u, false);
    setObjectMessage(getObjectFromId(static_cast<cGUIInstance*>(pItem->mpPlate), 153u), "", 0u, false);
    pItem->mIcon.setEmpty();
    if (pDispItem->mpInstBase != nullptr) {
        pDispItem->mpInstBase->setVisible(false);
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(pDispItem->mpInstBase), false);
    } else {
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(nullptr), false);
    }
}

__attribute__((weak)) void uGUIArisenCard::updateAbilityDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIArisenCard::updateAbilityDisp")
    /* stub */
}

void uGUIArisenCard::updateAbilityHide(uGUIBase::cScrollListItemBase* pDispItem) {
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

__attribute__((weak)) void uGUIArisenCard::updateHistoryDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIArisenCard::updateHistoryDisp")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateHistoryHide(uGUIBase::cScrollListItemBase* pDispItem) {
    DDON_STUB("uGUIArisenCard::updateHistoryHide")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateHistoryPawnDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIArisenCard::updateHistoryPawnDisp")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateHistoryPawnHide(uGUIBase::cScrollListItemBase* pDispItem) {
    DDON_STUB("uGUIArisenCard::updateHistoryPawnHide")
    /* stub */
}

__attribute__((weak)) u32 uGUIArisenCard::startEditProfile(MtObject* pDummy, MtObject* pUnit) {
    DDON_STUB("uGUIArisenCard::startEditProfile")
    return {};
}

__attribute__((weak)) u32 uGUIArisenCard::startEditPawnProfile(MtObject* pDummy, MtObject* pUnit) {
    DDON_STUB("uGUIArisenCard::startEditPawnProfile")
    return {};
}

__attribute__((weak)) u32 uGUIArisenCard::startEditBG(MtObject* pDummy, MtObject* pUnit) {
    DDON_STUB("uGUIArisenCard::startEditBG")
    return {};
}

__attribute__((weak)) u32 uGUIArisenCard::startEditPose(MtObject* pDummy, MtObject* pUnit) {
    DDON_STUB("uGUIArisenCard::startEditPose")
    return {};
}

__attribute__((weak)) u32 uGUIArisenCard::startEditTitle(MtObject* pDummy, MtObject* pUnit) {
    DDON_STUB("uGUIArisenCard::startEditTitle")
    return {};
}

__attribute__((weak)) void uGUIArisenCard::initOrb(cGUIInstAnimation* pInst, f32 PosY, const u16* pOrbRelease) {
    DDON_STUB("uGUIArisenCard::initOrb")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateOrbPage() {
    DDON_STUB("uGUIArisenCard::updateOrbPage")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateEquipCursor() {
    DDON_STUB("uGUIArisenCard::updateEquipCursor")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initRentalReview(cGUIInstNull* pNull, u32 Idx, f32 PosY, const cCharacterData::stCardPawnTotalValue& PawnValue) {
    DDON_STUB("uGUIArisenCard::initRentalReview")
    /* stub */
}

void uGUIArisenCard::initHistoryPawnList(cGUIInstAnimation* pInst, cGUIInstAnimation* pIcon, u32 Index) {
    mHistoryList[Index].mpIcon = pIcon;
    mHistoryList[Index].mpInstPointerTarget = static_cast<cGUIInstance*>(pInst);
    mHistoryList[Index].mpName = static_cast<cGUIObjMessage*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 131u));
    mHistoryList[Index].mpText = static_cast<cGUIObjMessage*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 202u));
    mHistoryList[Index].mpTime = static_cast<cGUIObjMessage*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 201u));
    mHistoryList[Index].mpStar[0] = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 2u));
    mHistoryList[Index].mpStar[1] = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 4u));
    mHistoryList[Index].mpStar[2] = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 5u));
    mHistoryList[Index].mpStar[3] = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 6u));
    mHistoryList[Index].mpStar[4] = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(pInst), 7u));
}

__attribute__((weak)) void uGUIArisenCard::updateBGDisp(u16 BgNo, bool IsSave, bool IsInit) {
    DDON_STUB("uGUIArisenCard::updateBGDisp")
    /* stub */
}

void uGUIArisenCard::updateAchievementDisp(u32 Uid, u32 Index, bool IsSave, bool IsInit) {
    if (!mIsPlayer) {
        return;
    }
    if (mEditData.m_Title.m_unUid == Uid) {
        if (IsInit) {
            if (IsSave) {
                mIsUpdateEditData = true;
                mEditData.m_Title.m_unUid = Uid;
                mEditData.m_Title.m_unIndex = Index;
                cGUIObjMessage* t0 = mpAchieveName;
                if (t0 != nullptr) {
                    if (Uid != 0) {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(Uid), 0u, false);
                    } else {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u), 0u, false);
                    }
                }
            } else {
                mEditData.m_Title.m_unUid = Uid;
                mEditData.m_Title.m_unIndex = Index;
                cGUIObjMessage* t0 = mpAchieveName;
                if (t0 != nullptr) {
                    if (Uid != 0) {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(Uid), 0u, false);
                    } else {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u), 0u, false);
                    }
                }
            }
        }
    } else {
        if (IsSave) {
            mIsUpdateEditData = true;
            mEditData.m_Title.m_unUid = Uid;
            mEditData.m_Title.m_unIndex = Index;
            cGUIObjMessage* t0 = mpAchieveName;
            if (t0 != nullptr) {
                if (Uid != 0) {
                    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(Uid), 0u, false);
                } else {
                    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u), 0u, false);
                }
            }
        } else {
            if (IsInit) {
                mEditData.m_Title.m_unUid = Uid;
                mEditData.m_Title.m_unIndex = Index;
                cGUIObjMessage* t0 = mpAchieveName;
                if (t0 != nullptr) {
                    if (Uid != 0) {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(Uid), 0u, false);
                    } else {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u), 0u, false);
                    }
                }
            } else {
                cGUIObjMessage* t0 = mpAchieveName;
                if (t0 != nullptr) {
                    if (Uid != 0) {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(Uid), 0u, false);
                    } else {
                        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u), 0u, false);
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIArisenCard::initCardEdit(const cCharacterData::stCardArisenInfo* pEditInfo) {
    DDON_STUB("uGUIArisenCard::initCardEdit")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::initSkillDetail() {
    DDON_STUB("uGUIArisenCard::initSkillDetail")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCard::updateSkillDetail() {
    DDON_STUB("uGUIArisenCard::updateSkillDetail")
    /* stub */
}

void uGUIArisenCard::mgrMockup() {
    if (mpMockup == nullptr) {
        return;
    }
    bool t0 = mpMockup->isComplete();
    if (mMockupState == 1) {
        mpMockup->setDisp(t0);
        if (mpLoadIcon != nullptr) {
            mpLoadIcon->setVisible(t0);
        }
        if (t0) {
            mMockupState = 0;
        }
    } else {
        if (mMockupState == 0) {
            mpMockup->setDisp(t0);
            if (mpLoadIcon != nullptr) {
                mpLoadIcon->setVisible(!t0);
            }
        }
    }
}

void uGUIArisenCard::startSubMenu() {
    f32 j0;
    f32 j1;
    if (mpSubMenu != nullptr) {
        mpSubMenu->mEndType = 0;
        mpSubMenu->end();
    }
    mpSubMenu = nullptr;
    uGUIPopCmd01* t0 = createPopCmd01(false);
    if ((mpSubMenu = t0) == nullptr) {
        return;
    }
    if (mpSubMenuNull != nullptr) {
        f32 t1 = mpSubMenuNull->mPosition.y;
        j0 = t1;
        j1 = mpSubMenuNull->mPosition.x;
    } else {
        j0 = 450.0f;
        j1 = 120.0f;
    }
    t0->mPos.x = j1;
    t0->mPos.y = j0;
    t0->mPos.z = 0.0f;
    t0->mPos.pad_ = 0.0f;
    if (mIsPlayer) {
        bool t2 = sQuestManagerExt::getInstance()->isEnableMenu_MatchingProf();
        uGUIPopCmd01* t3 = mpSubMenu;
        MT_CTSTR t4 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 68u);
        if (t2) {
            t3->_addItem(static_cast<uGUIBase*>(this), t4, static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditProfile), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
        } else {
            t3->_addItem(static_cast<uGUIBase*>(this), t4, static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditProfile), static_cast<MtObject*>(this), uGUIPopBase::MODE_DISABLE, 227);
        }
        uGUIPopCmd01* t8 = mpSubMenu;
        t8->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 69u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditBG), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
        uGUIPopCmd01* t9 = mpSubMenu;
        t9->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 70u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditPose), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
        uGUIPopCmd01* t10 = mpSubMenu;
        t10->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 71u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditTitle), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
    } else {
        uGUIPopCmd01* t5 = mpSubMenu;
        t5->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 68u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditPawnProfile), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
        uGUIPopCmd01* t6 = mpSubMenu;
        t6->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 69u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditBG), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
        uGUIPopCmd01* t7 = mpSubMenu;
        t7->_addItem(static_cast<uGUIBase*>(this), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 70u), static_cast<uGUIPopBase::DATA_FUNC>(&::uGUIArisenCard::startEditPose), static_cast<MtObject*>(this), uGUIPopBase::MODE_DEFAULT, -1);
    }
    if (mpItemDetail == nullptr) {
        return;
    }
    mpItemDetail->mIsDraw = false;
}

void uGUIArisenCard::reactiveWindowCallBack() {
    if (mNowPage != 0) {
        return;
    }
    if (!mIsMoveInitFunc) {
        updateEquipCursor();
    }
}

inline uGUIArisenCard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::MyDTI uGUIArisenCard::DTI("uGUIArisenCard", &::uGUIBase::DTI, 26752ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCard::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCard::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIArisenCard::cScrollHistoryDispList::getDTI() const {
    return uGUIArisenCard::cScrollHistoryDispList::DTI;
}

inline uGUIArisenCard::cScrollHistoryDispList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollHistoryDispList::MyDTI uGUIArisenCard::cScrollHistoryDispList::DTI("uGUIArisenCard::cScrollHistoryDispList", &::uGUIBase::cScrollListItemBase::DTI, 168ul, 0u, 0u);

MtObject* uGUIArisenCard::cScrollHistoryDispList::MyDTI::newInstance() const {
    return new (16u) uGUIArisenCard::cScrollHistoryDispList;
}

const MtDTI& uGUIArisenCard::cScrollDispSkillList::getDTI() const {
    return uGUIArisenCard::cScrollDispSkillList::DTI;
}

uGUIArisenCard::cScrollDispSkillList::~cScrollDispSkillList() {
}

inline uGUIArisenCard::cScrollDispSkillList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollDispSkillList::MyDTI uGUIArisenCard::cScrollDispSkillList::DTI("uGUIArisenCard::cScrollDispSkillList", &::uGUIBase::cScrollListItemBase::DTI, 288ul, 0u, 0u);

MtObject* uGUIArisenCard::cScrollDispSkillList::MyDTI::newInstance() const {
    return new (16u) uGUIArisenCard::cScrollDispSkillList;
}

const MtDTI& uGUIArisenCard::cScrollDispAbilityList::getDTI() const {
    return uGUIArisenCard::cScrollDispAbilityList::DTI;
}

uGUIArisenCard::cScrollDispAbilityList::~cScrollDispAbilityList() {
}

inline uGUIArisenCard::cScrollDispAbilityList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollDispAbilityList::MyDTI uGUIArisenCard::cScrollDispAbilityList::DTI("uGUIArisenCard::cScrollDispAbilityList", &::uGUIBase::cScrollListItemBase::DTI, 288ul, 0u, 0u);

MtObject* uGUIArisenCard::cScrollDispAbilityList::MyDTI::newInstance() const {
    return new (16u) uGUIArisenCard::cScrollDispAbilityList;
}

const MtDTI& uGUIArisenCard::cScrollSkillList::getDTI() const {
    return uGUIArisenCard::cScrollSkillList::DTI;
}

inline uGUIArisenCard::cScrollSkillList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollSkillList::MyDTI uGUIArisenCard::cScrollSkillList::DTI("uGUIArisenCard::cScrollSkillList", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCard::cScrollSkillList::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCard::cScrollSkillList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIArisenCard::cScrollAbilityList::getDTI() const {
    return uGUIArisenCard::cScrollAbilityList::DTI;
}

inline uGUIArisenCard::cScrollAbilityList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollAbilityList::MyDTI uGUIArisenCard::cScrollAbilityList::DTI("uGUIArisenCard::cScrollAbilityList", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCard::cScrollAbilityList::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCard::cScrollAbilityList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIArisenCard::cScrollHistoryInfoList::getDTI() const {
    return uGUIArisenCard::cScrollHistoryInfoList::DTI;
}

inline uGUIArisenCard::cScrollHistoryInfoList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCard::cScrollHistoryInfoList::MyDTI uGUIArisenCard::cScrollHistoryInfoList::DTI("uGUIArisenCard::cScrollHistoryInfoList", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCard::cScrollHistoryInfoList::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCard::cScrollHistoryInfoList::MyDTI::newInstance")
    return nullptr;
}

