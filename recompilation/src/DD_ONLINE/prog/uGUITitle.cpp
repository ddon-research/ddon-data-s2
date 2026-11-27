// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUITitle.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "aMenu.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cOpeningMovie.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUICredit.h"
#include "uGUIOption.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MT_CHAR gResourceVersion[64];

const MtDTI& uGUITitle::getDTI() const {
    return uGUITitle::DTI;
}

void* uGUITitle::operator new(size_t sz, u32 align) {
    return uGUITitle::getAllocator()->memAlloc(sz, align, uGUITitle::DTI.getID());
}

uGUITitle::uGUITitle() : uGUIBase(0u, false) {
    mpInstAnimLogoBack = nullptr;
    mpInstAnimFixLogo = nullptr;
    mpInstScr = nullptr;
    mpInstNull = nullptr;
    mpGUIRes = nullptr;
    mDistCursor = 0;
    mPosYCursorInit = 0.0f;
    mPosYCursorTgt = 0.0f;
    mpSeRes = nullptr;
    mpSoundRes = nullptr;
    mpCtrl = nullptr;
    mpOpeningMovie = nullptr;
    mpGUIMenuChild = nullptr;
    mAlpha = 1.0f;
    mpGMDRes = nullptr;
    mRno = 0;
    mIsEffectOff = false;
    mMenuNum = 0;
    mMenuTag[4] = 0;
    mMenuTag[5] = 0;
    mMenuTag[2] = 0;
    mMenuTag[3] = 0;
    mMenuTag[0] = 0;
    mMenuTag[1] = 0;
    mpInstMenu[5] = nullptr;
    mpInstMenu[4] = nullptr;
    mpInstMenu[3] = nullptr;
    mpInstMenu[2] = nullptr;
    mpInstMenu[1] = nullptr;
    mpInstMenu[0] = nullptr;
    mpObjMsg = nullptr;
    mpObjWindows[2] = nullptr;
    mpObjWindows[1] = nullptr;
    mpObjWindows[0] = nullptr;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUITitle"), 0u, false);
}

uGUITitle::~uGUITitle() {
    if (mpOpeningMovie != nullptr) {
        delete mpOpeningMovie;
        mpOpeningMovie = nullptr;
    }
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpSoundRes != nullptr) {
        mpSoundRes->release();
        mpSoundRes = nullptr;
    }
    if (mpSeRes != nullptr) {
        mpSeRes->release();
        mpSeRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

void uGUITitle::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUITitle::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_TITLE_00_GUI"), 129u, 1460692978l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_TITLE_MENU_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpSoundRes == nullptr) && ((mpSoundRes = static_cast<rSoundStreamRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_START_STQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_TITLE_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUITitle::setup() {
    DDON_STUB("uGUITitle::setup")
    /* stub */
}

void uGUITitle::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpSoundRes != nullptr) {
        mpSoundRes->release();
        mpSoundRes = nullptr;
    }
    if (mpSeRes != nullptr) {
        mpSeRes->release();
        mpSeRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGUIMenuChild != nullptr) {
        mpGUIMenuChild->kill();
        mpGUIMenuChild = nullptr;
    }
    if (mpOpeningMovie != nullptr) {
        delete mpOpeningMovie;
        mpOpeningMovie = nullptr;
    }
    if (sGame::getInstance() == nullptr) {
        return;
    }
    sGame::getInstance()->fadeIn(0.0f, 0u);
}

__attribute__((weak)) void uGUITitle::updatePtr() {
}

__attribute__((weak)) void uGUITitle::updateInit() {
    DDON_STUB("uGUITitle::updateInit")
    /* stub */
}

void uGUITitle::updateIn() {
    if (!mIsFlowEnd) {
        return;
    }
    setSequenceIdWithTexRect(mpCtrl->getCurrentPos(), 4u);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateWait);
}

void uGUITitle::updateWait() {
    updateDisp();
    if (mpGUIMenuChild != nullptr) {
        if (mpGUIMenuChild->mResult == RESULT_EXIT) {
            mpGUIMenuChild->kill();
            mpGUIMenuChild = nullptr;
            setSequenceIdWithTexRect(mpCtrl->getCurrentPos(), 4u);
        }
    } else {
        if (mpCtrl != nullptr) {
            mpCtrl->execute();
        }
    }
}

void uGUITitle::updateOut() {
    updateDisp();
    if (!mIsFlowEnd) {
        return;
    }
    mIsEffectOff = true;
    sGame::getInstance()->fadeOut(0.0f, 0u);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateExit);
}

__attribute__((weak)) void uGUITitle::updateMovie() {
    DDON_STUB("uGUITitle::updateMovie")
    /* stub */
}

__attribute__((weak)) void uGUITitle::updateCredit() {
    DDON_STUB("uGUITitle::updateCredit")
    /* stub */
}

void uGUITitle::updateExit() {
    mIsEffectOff = true;
    end();
}

__attribute__((weak)) void uGUITitle::updateGameExit() {
    DDON_STUB("uGUITitle::updateGameExit")
    /* stub */
}

u32 uGUITitle::evCtrlDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
            switch ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) - 1u) {
                case 0:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateOut);
                    setFlowAndInit(4u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestStream(mpSoundRes, 1u, reinterpret_cast<const uintptr>(this), static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 1:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    setFlowAndInit(11u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestStream(mpSoundRes, 2u, reinterpret_cast<const uintptr>(this), static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    mRno = 1;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateMovie);
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 2:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mRno = 7;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateCredit);
                    setFlowAndInit(7u, false);
                    mpInstAnimFixLogo->setSequenceId(0xF4243u);
                    mpInstAnimLogoBack->setSequenceId(0xF4243u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 3:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mRno = 7;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateCredit);
                    setFlowAndInit(7u, false);
                    mpInstAnimFixLogo->setSequenceId(0xF4243u);
                    mpInstAnimLogoBack->setSequenceId(0xF4243u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 4:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateGameExit);
                    setFlowAndInit(4u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                default:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
            }
        } else {
            switch (msg->pSender->getCurrentTag() - 1u) {
                case 0:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateOut);
                    setFlowAndInit(4u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestStream(mpSoundRes, 1u, reinterpret_cast<const uintptr>(this), static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 1:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    setFlowAndInit(11u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestStream(mpSoundRes, 2u, reinterpret_cast<const uintptr>(this), static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    mRno = 1;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateMovie);
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 2:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mRno = 7;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateCredit);
                    setFlowAndInit(7u, false);
                    mpInstAnimFixLogo->setSequenceId(0xF4243u);
                    mpInstAnimLogoBack->setSequenceId(0xF4243u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 3:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mRno = 7;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateCredit);
                    setFlowAndInit(7u, false);
                    mpInstAnimFixLogo->setSequenceId(0xF4243u);
                    mpInstAnimLogoBack->setSequenceId(0xF4243u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                case 4:
                {
                    setSequenceIdWithTexRect(static_cast<s32>(msg->pSender->getCurrentTag()), 0xF4240u);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITitle::updateGameExit);
                    setFlowAndInit(4u, false);
                    mpInstAnimFixLogo->setSequenceId(3u);
                    mpInstAnimLogoBack->setSequenceId(3u);
                    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSeRes, 2u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
                default:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlMove(msg);
                        return 0;
                    } else {
                        updateDisp();
                        return 0;
                    }
                    break;
                }
            }
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 uGUITitle::evCtrlMove(cControl::Message* msg) {
    DDON_STUB("uGUITitle::evCtrlMove")
    return {};
}

__attribute__((weak)) void uGUITitle::updateDisp() {
    DDON_STUB("uGUITitle::updateDisp")
    /* stub */
}

__attribute__((weak)) void uGUITitle::createMenu() {
    DDON_STUB("uGUITitle::createMenu")
    /* stub */
}

__attribute__((weak)) void uGUITitle::setSequenceIdWithTexRect(s32 index, u32 seqId) {
    DDON_STUB("uGUITitle::setSequenceIdWithTexRect")
    /* stub */
}

inline uGUITitle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUITitle::MyDTI uGUITitle::DTI("uGUITitle", &::uGUIBase::DTI, 2640ul, 0u, 0u);

MtObject* uGUITitle::MyDTI::newInstance() const {
    return new (16u) uGUITitle;
}

