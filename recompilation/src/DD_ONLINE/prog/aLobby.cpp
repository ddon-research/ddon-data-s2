// Reconstructed from the game's DWARF debug information.
#include <new>
#include "aLobby.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "aStage.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "sArchiveManager.h"
#include "sClanKyoten.h"
#include "sDialogBase.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "sWeatherManager.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& aLobby::getDTI() const {
    return aLobby::DTI;
}

aLobby::~aLobby() {
}

bool aLobby::load() {
    sFlag::getInstance()->setFlag(6u, 0u, true, true, false);
    sFlag::getInstance()->setFlag(6u, 8u, true, true, false);
    if (this->aStage::load()) {
        if (((this->cArea::mRno >> 8) & 255u) == 2) {
            setRno1(static_cast<u8>(0), static_cast<u8>(0));
            return true;
        }
        if (((this->cArea::mRno >> 8) & 255u) == 0) {
            setRno1(static_cast<u8>(2), static_cast<u8>(0));
        }
    }
    return false;
}

void aLobby::init() {
    this->aStage::init();
    sGame::getInstance()->setGameTimePause(false);
    sWeatherManager::getInstance()->setSyncGame(true);
    sGame::getInstance()->updateLastBase(1u);
    sQuestManagerExt::getInstance()->initLobby();
    sClanKyoten::getInstance()->initLobby();
    static_cast<sGUIExt*>(sGUI::getInstance())->initEventBanner();
    sGame::getInstance()->mIsLobbyIn = false;
}

void aLobby::move() {
    this->aStage::move();
}

void aLobby::moveMain() {
    sClanKyoten::getInstance()->move();
    if (((this->cArea::mRno >> 8) & 254u) != 0) {
        if (sGame::getInstance()->isReqJumpStageFromLobby()) {
            sGame::getInstance()->mIsReqJumpStageFromLobby = false;
            setRno1(static_cast<u8>(3), static_cast<u8>(0));
        }
    }
    switch ((this->cArea::mRno >> 8) & 255u) {
        case 0:
        {
            setRno1(static_cast<u8>(1), static_cast<u8>(0));
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isCheckCreateParty()) {
                static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->createGameSessionRequest();
                if (sGame::getInstance()->isReqJumpStageFromLobby()) {
                    sGame::getInstance()->mIsReqJumpStageFromLobby = false;
                    setRno1(static_cast<u8>(3), static_cast<u8>(0));
                } else {
                    execGameMenuOpen();
                    if (!execGameMenuMsg()) {
                        execDbgGameMenu();
                    }
                }
            } else {
                if (sGame::getInstance()->isReqJumpStageFromLobby()) {
                    sGame::getInstance()->mIsReqJumpStageFromLobby = false;
                    setRno1(static_cast<u8>(3), static_cast<u8>(0));
                } else {
                    execGameMenuOpen();
                    if (!execGameMenuMsg()) {
                        execDbgGameMenu();
                    }
                }
            }
            break;
        }
        case 1:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isCheckCreateParty()) {
                static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->createGameSessionRequest();
                if (sGame::getInstance()->isReqJumpStageFromLobby()) {
                    sGame::getInstance()->mIsReqJumpStageFromLobby = false;
                    setRno1(static_cast<u8>(3), static_cast<u8>(0));
                } else {
                    execGameMenuOpen();
                    if (!execGameMenuMsg()) {
                        execDbgGameMenu();
                    }
                }
            } else {
                if (sGame::getInstance()->isReqJumpStageFromLobby()) {
                    sGame::getInstance()->mIsReqJumpStageFromLobby = false;
                    setRno1(static_cast<u8>(3), static_cast<u8>(0));
                } else {
                    execGameMenuOpen();
                    if (!execGameMenuMsg()) {
                        execDbgGameMenu();
                    }
                }
            }
            break;
        }
        case 2:
        {
            if ((sInputManager::mpInstance)->sInputManager::getKeyCommon(nKeyCustom::KEY_CUSTOM_UI_GAME_MENU, nKeyCustom::GET_TRG, nKeyCustom::MODE_CUSTOM, 0u) == 0) {
                if (sInputManager::getInstance()->getKeyCommon(nKeyCustom::KEY_CUSTOM_UI_CANCEL, nKeyCustom::GET_TRG, nKeyCustom::MODE_SYSTEM, 0u) != 0) {
                    sInputManager::getInstance()->setDisableInputGameByPauseMenu(false);
                    setRno1(static_cast<u8>(1), static_cast<u8>(0));
                }
            } else {
                sInputManager::getInstance()->setDisableInputGameByPauseMenu(false);
                setRno1(static_cast<u8>(1), static_cast<u8>(0));
            }
            break;
        }
        case 3:
        {
            if ((this->cArea::mRno & 0xFF0000u) == 0) {
                if (!sDialogBase::getInstance()->isDialogExecute()) {
                    mStageNo = sGame::getInstance()->getReqStageNo();
                    setRno(static_cast<u8>(6), static_cast<u8>(0));
                    mJumpToStageNo = sGame::getInstance()->getReqStageNo();
                    mJumpToPosNo = sGame::getInstance()->getReqStartPosNo();
                    mJumpSync = sGame::getInstance()->isStageJumpSync();
                    sGame::getInstance()->mIsReqSyncAreaJump = false;
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

__attribute__((weak)) void aLobby::execDbgGameMenu() {
}

void aLobby::final() {
    sClanKyoten::getInstance()->finalLobby();
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicket);
        mArcTicket = t0;
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->exitEventBanner();
    this->aStage::final();
}

void aLobby::createProperty(MtPropertyList& s) {
    this->aStage::createProperty(s);
}

MT_CTSTR aLobby::getShaderSegment() {
    return this->aStage::getShaderSegment();
}

inline aLobby::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

aLobby::MyDTI aLobby::DTI("aLobby", &::aStage::DTI, 1072ul, 0u, 0u);

MtObject* aLobby::MyDTI::newInstance() const {
    return new (16u) aLobby;
}

template MtTypedArray<uDDOModel>::~MtTypedArray();

