// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cPlDeadFlow.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cContextInterface.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cState.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpOcdCtrl.h"
#include "cpStateManager.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/rGUIMessage.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "sSoundManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPlDeadFlow::getDTI() const {
    return cPlDeadFlow::DTI;
}

cPlDeadFlow::cPlDeadFlow() {
    mRno = 0;
    mState = STATE_ALIVE;
    mpTouchPawn = nullptr;
    mItemResult = 1;
    mReviveMenuWait = false;
}

cPlDeadFlow::~cPlDeadFlow() {
}

bool cPlDeadFlow::move() {
    if (mpTouchPawn != nullptr) {
        if (!mpTouchPawn->isEnable()) {
            mpTouchPawn = nullptr;
        }
    }
    switch (mState) {
        case STATE_ALIVE:
        {
            moveAlive();
            return true;
        }
        case STATE_INJURED:
        {
            moveInjured();
            return true;
        }
        case STATE_LOST:
        {
            moveLost();
            return true;
        }
        case STATE_GAMEOVER:
        {
            return false;
        }
        default:
        {
            return true;
        }
    }
}

void cPlDeadFlow::moveWait() {
    if (mpTouchPawn != nullptr) {
        if (!mpTouchPawn->isEnable()) {
            mpTouchPawn = nullptr;
        }
    }
    if (mState != STATE_LOST) {
        if (mState == STATE_INJURED) {
            if (mRno == 1) {
                sMenu::getInstance()->updateMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mPlDeadMenu));
            }
        } else {
            if (mState == STATE_ALIVE) {
                if (mRno == 1) {
                    sMenu::getInstance()->updateMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mPawnRevive));
                }
            }
        }
    } else {
        if (mRno == 2) {
            sMenu::getInstance()->updateMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mPawnRevive));
        }
    }
}

bool cPlDeadFlow::isMovePwanReviveMenu() {
    return (mState == STATE_ALIVE) && (mRno == 1);
}

bool cPlDeadFlow::isMovePlDeadFlow() {
    return mState != STATE_ALIVE;
}

__attribute__((weak)) void cPlDeadFlow::moveAlive() {
    DDON_STUB("cPlDeadFlow::moveAlive")
    /* stub */
}

__attribute__((weak)) void cPlDeadFlow::moveInjured() {
    DDON_STUB("cPlDeadFlow::moveInjured")
    /* stub */
}

__attribute__((weak)) void cPlDeadFlow::moveLost() {
    DDON_STUB("cPlDeadFlow::moveLost")
    /* stub */
}

inline cPlDeadFlow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPlDeadFlow::MyDTI cPlDeadFlow::DTI("cPlDeadFlow", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cPlDeadFlow::MyDTI::newInstance() const {
    return new (16u) cPlDeadFlow;
}

