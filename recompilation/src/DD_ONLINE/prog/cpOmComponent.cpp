// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpOmComponent.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtGeomOBB.h"
#include "../../MT/MtGeometry3D.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cAISvPathFinding.h"
#include "../../XFramework/cArea.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cDelegate.h"
#include "cHitNode.h"
#include "cItemParam.h"
#include "cOmControl.h"
#include "cTalkMsgData.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpObjCollision.h"
#include "../../generated/shared/nDDOModel.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sAI.h"
#include "sAIExt.h"
#include "../../XFramework/sArea.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "uDDOModel.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#include "../../XFramework/uModel.h"
#include "uOmModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpOmBase::getDTI() const {
    return cpOmBase::DTI;
}

cpOmBase::cpOmBase() {
    DDON_STUB("cpOmBase::cpOmBase")
    /* stub */
}

cpOmBase::~cpOmBase() {
    if (mpModel != nullptr) {
        mpModel->uDDOModel::requestReleaseTouch(mpTouchUnit, nDDOModel::TOUCH_RELEASE_NONE);
    }
    mpTouchUnit = nullptr;
    if (mpGUISingleton != nullptr) {
        if (mpGUISingleton == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
            static_cast<sGUIExt*>(sGUI::getInstance())->killSingletonMenu();
        }
    }
    mpGUISingleton = nullptr;
}

void cpOmBase::move() {
    uOmModel* puom = mpModel;
    if (puom == nullptr) {
        return;
    }
    cOmControl* pctrl = puom->getOmCtrl();
    if (pctrl == nullptr) {
        return;
    }
    setLinkNavExt(mbLinkNav, false, false);
    if (pctrl->mLot.mAreaMasterNo == 0) {
        return;
    }
    mbAreaMaster = sQuestManagerExt::getInstance()->isAreaRelease(static_cast<unsigned short>(pctrl->mLot.mAreaMasterNo));
}

__attribute__((weak)) void cpOmBase::kill() {
    DDON_STUB("cpOmBase::kill")
    /* stub */
}

void cpOmBase::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel != nullptr) {
        if (!mpModel->isEnable()) {
            mpModel = nullptr;
        }
    }
    if (mpTouchUnit != nullptr) {
        if (!mpTouchUnit->isEnable()) {
            mpTouchUnit = nullptr;
        }
    }
    if (mpGUISingleton == nullptr) {
        return;
    }
    if (mpGUISingleton->isEnable()) {
        return;
    }
    mpGUISingleton = nullptr;
}

void cpOmBase::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uOmModel*>(pOwner);
}

void cpOmBase::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mbLinkNav", reinterpret_cast<MT_MFUNC>(&::cpOmBase::getLinkNav), reinterpret_cast<MT_MFUNC>(&::cpOmBase::setLinkNav), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mNavOBB", static_cast<MtObject*>(&mNavOBB), 0u, 0u);
}

__attribute__((weak)) void cpOmBase::setTouch(uDDOModel* pUnit) {
}

__attribute__((weak)) void cpOmBase::finishTouch(nDDOModel::TOUCH_RELEASE_TYPE type) {
}

__attribute__((weak)) void cpOmBase::cancelTouch() {
}

__attribute__((weak)) bool cpOmBase::isCanTouch(uDDOModel* pu) {
    DDON_STUB("cpOmBase::isCanTouch")
    return {};
}

__attribute__((weak)) bool cpOmBase::isUIOpen() {
    DDON_STUB("cpOmBase::isUIOpen")
    return {};
}

bool cpOmBase::reqDialog(s32 dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4) {
    uGUIBase* t0 = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(static_cast<const MtDTI*>(&uGUISystemMsg::DTI));
    bool b2_0;
    if ((mpGUISingleton = t0) != nullptr) {
        if (static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu != mpGUISingleton) {
            b2_0 = false;
        } else {
            const MtDTI& t1 = t0->getDTI();
            MT_CTSTR v0_1 = uGUISystemMsg::DTI.mName;
            for (const MtDTI* v0_0 = &t1;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    static_cast<uGUISystemMsg*>(mpGUISingleton)->setText(mainMsg, -1);
                    if (choice1 != nullptr) {
                        static_cast<uGUISystemMsg*>(mpGUISingleton)->addChoiceInfo(choice1, 0u, nHuman::JOB_ID_NONE, -1, true);
                        if (choice2 != nullptr) {
                            static_cast<uGUISystemMsg*>(mpGUISingleton)->addChoiceInfo(choice2, 0u, nHuman::JOB_ID_NONE, -1, true);
                            if (choice3 != nullptr) {
                                static_cast<uGUISystemMsg*>(mpGUISingleton)->addChoiceInfo(choice3, 0u, nHuman::JOB_ID_NONE, -1, true);
                                if (choice4 != nullptr) {
                                    static_cast<uGUISystemMsg*>(mpGUISingleton)->addChoiceInfo(choice4, 0u, nHuman::JOB_ID_NONE, -1, true);
                                    static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                                    static_cast<uGUISystemMsg*>(mpGUISingleton)->setCancelChoicePos(3, -1);
                                } else {
                                    static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                                    static_cast<uGUISystemMsg*>(mpGUISingleton)->setCancelChoicePos(2, -1);
                                }
                            } else {
                                static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                                static_cast<uGUISystemMsg*>(mpGUISingleton)->setCancelChoicePos(1, -1);
                            }
                        } else {
                            static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                            static_cast<uGUISystemMsg*>(mpGUISingleton)->setCancelChoicePos(0, -1);
                        }
                    } else {
                        static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                    }
                    b2_0 = true;
                    return b2_0;
                }
            }
            b2_0 = false;
        }
    } else {
        b2_0 = false;
    }
    return b2_0;
}

bool cpOmBase::reqDialogEx(MT_CTSTR title, s32 defPos, MT_CTSTR* pselect, u32 selectNum) {
    bool b4_0;
    if (pselect == nullptr) {
        b4_0 = false;
    } else {
        if (selectNum == 0) {
            b4_0 = false;
        } else {
            uGUIBase* t0 = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(static_cast<const MtDTI*>(&uGUISystemMsg::DTI));
            if ((mpGUISingleton = t0) != nullptr) {
                if (static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu != mpGUISingleton) {
                    b4_0 = false;
                } else {
                    const MtDTI& t1 = t0->getDTI();
                    MT_CTSTR v0_1 = uGUISystemMsg::DTI.mName;
                    const MtDTI* v0_0 = &t1;
                    MT_CTSTR* p2_3;
                    uGUIBase* v2_5;
                    u32 cnt;
                    uGUIBase* v3_5;
                    for (;;) {
                        if (v0_1 != v0_0->mName) {
                            if (v0_0->mpParent != nullptr) {
                                v0_0 = v0_0->mpParent;
                            } else {
                                b4_0 = false;
                                break;
                            }
                        } else {
                            p2_3 = pselect;
                            v2_5 = mpGUISingleton;
                            cnt = selectNum;
                            for (;;) {
                                static_cast<uGUISystemMsg*>(v2_5)->addChoiceInfo(*p2_3, 0u, nHuman::JOB_ID_NONE, -1, true);
                                v3_5 = mpGUISingleton;
                                if ((cnt - 1u) != 0) {
                                    p2_3 += 1;
                                    v2_5 = v3_5;
                                    cnt += 0xFFFFFFFFu;
                                } else {
                                    break;
                                }
                            }
                            static_cast<uGUISystemMsg*>(v3_5)->setText(title, -1);
                            static_cast<uGUISystemMsg*>(mpGUISingleton)->setDefaultChoicePos(defPos, -1);
                            static_cast<uGUISystemMsg*>(mpGUISingleton)->setCancelChoicePos(-1, -1);
                            b4_0 = true;
                            break;
                        }
                    }
                }
            } else {
                b4_0 = false;
            }
        }
    }
    return b4_0;
}

__attribute__((weak)) bool cpOmBase::reqText(u32 textType, u32 textNo, u32 questNo) {
    DDON_STUB("cpOmBase::reqText")
    return {};
}

__attribute__((weak)) cTalkMsgData* cpOmBase::getMsgData(u32 textType, u32 textNo, u32 questNo) {
    DDON_STUB("cpOmBase::getMsgData")
    return nullptr;
}

void cpOmBase::createGUISingleton(const MtDTI* pDTI) {
    mpGUISingleton = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(pDTI);
}

void cpOmBase::deleteGUISingleton() {
    if (mpGUISingleton != nullptr) {
        if (mpGUISingleton == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
            static_cast<sGUIExt*>(sGUI::getInstance())->killSingletonMenu();
        }
    }
    mpGUISingleton = nullptr;
}

bool cpOmBase::isMoveGUISingleton() {
    return (mpGUISingleton != nullptr) && (mpGUISingleton == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu);
}

bool cpOmBase::isEndGUISingleton() {
    if (mpGUISingleton != nullptr) {
        if (mpGUISingleton == static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
            return mpGUISingleton->mResult == uGUIBase::RESULT_EXIT;
        }
    }
    return true;
}

void cpOmBase::reqTextDialog(cTalkMsgData* pMsgData) {
    if (pMsgData != nullptr) {
        uGUIBase* t0 = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(static_cast<const MtDTI*>(&uGUISystemMsg::DTI));
        if ((mpGUISingleton = t0) != nullptr) {
            if (static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu == mpGUISingleton) {
                const MtDTI& t1 = t0->getDTI();
                MT_CTSTR v0_1 = uGUISystemMsg::DTI.mName;
                const MtDTI* v0_0 = &t1;
                unsigned int i2_3;
                for (;;) {
                    if (v0_1 != v0_0->mName) {
                        if (v0_0->mpParent != nullptr) {
                            v0_0 = v0_0->mpParent;
                        } else {
                            return;
                        }
                    } else {
                        if (pMsgData->getDispPageNum() != 0) {
                            i2_3 = 0;
                            for (;;) {
                                if (pMsgData->getMessage() != nullptr) {
                                    uGUIBase* t2 = mpGUISingleton;
                                    MT_CTSTR t3 = pMsgData->getMessage();
                                    if (i2_3 != 0) {
                                        static_cast<uGUISystemMsg*>(t2)->addPageInfo(t3);
                                    } else {
                                        static_cast<uGUISystemMsg*>(t2)->setText(t3, -1);
                                    }
                                }
                                pMsgData->addDispPageNo();
                                if ((i2_3 + 1u) < pMsgData->getDispPageNum()) {
                                    i2_3 += 1u;
                                } else {
                                    goto loop_4e1e0d_end;
                                }
                            }
                        }
                        break;
                    }
                }
                loop_4e1e0d_end:;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpGUISingleton) + 7584) = 0;
            }
        }
    }
}

__attribute__((weak)) void cpOmBase::initAction(uOmModel* puom) {
}

__attribute__((weak)) bool cpOmBase::hasKeyNo(u32 keyNo, bool isUse) {
    DDON_STUB("cpOmBase::hasKeyNo")
    return {};
}

void cpOmBase::setPLAct(u32 actNo, bool isLoop) {
    uDDOModel* t0 = mpTouchUnit;
    if (t0 == nullptr) {
        return;
    }
    mbLoopAct = isLoop;
    u32 actNoNow = t0->getActMgrPtr()->getActionNo();
    if ((actNoNow - 196u) > 30u) {
        if (actNoNow > 10u) {
            if (actNoNow == 74) {
                t0->getActionRequestPtr()->mTouchAction = actNo;
                t0->getActionRequestPtr()->mTouchActionReq = actNo;
            }
        } else {
            t0->getActionRequestPtr()->mTouchAction = actNo;
            t0->getActionRequestPtr()->mTouchActionReq = actNo;
        }
    } else {
        t0->getActionRequestPtr()->mTouchAction = actNo;
        t0->getActionRequestPtr()->mTouchActionReq = actNo;
    }
}

bool cpOmBase::getLinkNav() {
    return mbLinkNav;
}

void cpOmBase::setLinkNav(bool islink) {
    setLinkNavExt(islink, false, false);
}

void cpOmBase::setLinkNavEnd(bool islink) {
    setLinkNavExt(islink, false, false);
    mbNavEnd = true;
}

__attribute__((weak)) void cpOmBase::setLinkNavExt(bool islink, bool update_obb, bool force_update) {
    DDON_STUB("cpOmBase::setLinkNavExt")
    /* stub */
}

inline cpOmBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOmBase::MyDTI cpOmBase::DTI("cpOmBase", &::cpComponent::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* cpOmBase::MyDTI::newInstance() const {
    DDON_STUB("cpOmBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpOmLadder::getDTI() const {
    return cpOmLadder::DTI;
}

void* cpOmLadder::operator new(size_t sz, u32 align) {
    return cpOmLadder::getAllocator()->memAlloc(sz, align, cpOmLadder::DTI.getID());
}

cpOmLadder::cpOmLadder() {
    mpuOm = nullptr;
    mbSetup = false;
    mHeight = 5;
    mpHitNode[2] = nullptr;
    mpHitNode[1] = nullptr;
    mpHitNode[0] = nullptr;
}

cpOmLadder::~cpOmLadder() {
}

void cpOmLadder::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpuOm == nullptr) {
        return;
    }
    if (mpuOm->isEnable()) {
        return;
    }
    mpuOm = nullptr;
}

void cpOmLadder::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpuOm = static_cast<uOmModel*>(pOwner);
}

__attribute__((weak)) void cpOmLadder::setup() {
    DDON_STUB("cpOmLadder::setup")
    /* stub */
}

__attribute__((weak)) void cpOmLadder::move() {
}

__attribute__((weak)) void cpOmLadder::kill() {
}

void cpOmLadder::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "再設定", static_cast<MT_MFUNC>(&::cpOmLadder::setupModelUnit), 10u);
}

__attribute__((weak)) void cpOmLadder::compMoveAfter() {
}

__attribute__((weak)) void cpOmLadder::setupModelUnit() {
    DDON_STUB("cpOmLadder::setupModelUnit")
    /* stub */
}

inline cpOmLadder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOmLadder::MyDTI cpOmLadder::DTI("cpOmLadder", &::cpComponent::DTI, 216ul, 0u, 0u);

MtObject* cpOmLadder::MyDTI::newInstance() const {
    return new (16u) cpOmLadder;
}

const MtDTI& cpOmNav::getDTI() const {
    return cpOmNav::DTI;
}

void* cpOmNav::operator new(size_t sz, u32 align) {
    return cpOmNav::getAllocator()->memAlloc(sz, align, cpOmNav::DTI.getID());
}

cpOmNav::cpOmNav() {
    DDON_STUB("cpOmNav::cpOmNav")
    /* stub */
}

cpOmNav::~cpOmNav() {
}

void cpOmNav::move() {
    if (mpModel != nullptr) {
        cOmControl* t0 = mpModel->getOmCtrl();
        if (t0 != nullptr) {
            setLinkNavExt(mbLinkNav, false, false);
            if (t0->mLot.mAreaMasterNo != 0) {
                mbAreaMaster = sQuestManagerExt::getInstance()->isAreaRelease(static_cast<unsigned short>(t0->mLot.mAreaMasterNo));
            }
        }
        if (mRno == 0) {
            mRno = 1;
            setLinkNavExt(false, false, false);
        }
    } else {
        if (mRno == 0) {
            mRno = 1;
            setLinkNavExt(false, false, false);
        }
    }
}

inline cpOmNav::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOmNav::MyDTI cpOmNav::DTI("cpOmNav", &::cpOmBase::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* cpOmNav::MyDTI::newInstance() const {
    DDON_STUB("cpOmNav::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpOmSpa::getDTI() const {
    return cpOmSpa::DTI;
}

void* cpOmSpa::operator new(size_t sz, u32 align) {
    return cpOmSpa::getAllocator()->memAlloc(sz, align, cpOmSpa::DTI.getID());
}

cpOmSpa::cpOmSpa() {
    DDON_STUB("cpOmSpa::cpOmSpa")
    /* stub */
}

cpOmSpa::~cpOmSpa() {
}

void cpOmSpa::move() {
    if (mpModel == nullptr) {
        return;
    }
    if (mRno != 0) {
        return;
    }
    mRno = 1;
}

void cpOmSpa::setTouch(uDDOModel* pUnit) {
    if (pUnit == nullptr) {
        return;
    }
    if ((pUnit->mUnitId & 8u) == 0) {
        return;
    }
    mpTouchUnit = pUnit;
    mbLoopAct = false;
    u32 t0 = pUnit->getActMgrPtr()->getActionNo();
    if ((t0 - 196u) > 30u) {
        if (t0 > 10u) {
            if (t0 == 74) {
                pUnit->getActionRequestPtr()->mTouchAction = 208;
                pUnit->getActionRequestPtr()->mTouchActionReq = 208;
            }
        } else {
            pUnit->getActionRequestPtr()->mTouchAction = 208;
            pUnit->getActionRequestPtr()->mTouchActionReq = 208;
        }
    } else {
        pUnit->getActionRequestPtr()->mTouchAction = 208;
        pUnit->getActionRequestPtr()->mTouchActionReq = 208;
    }
}

void cpOmSpa::finishTouch(nDDOModel::TOUCH_RELEASE_TYPE type) {
    mpTouchUnit = nullptr;
}

inline cpOmSpa::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOmSpa::MyDTI cpOmSpa::DTI("cpOmSpa", &::cpOmBase::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* cpOmSpa::MyDTI::newInstance() const {
    DDON_STUB("cpOmSpa::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<nQuest::cGUIDeliveryData>::~MtTypedArray();

