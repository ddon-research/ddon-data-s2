// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIServerUIBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/UserSession/S2C.h"
#include "Protocol/PacketData/ServerUI.h"
#include "cNetGameServer.h"
#include "cServerUIClientControl.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIServerUIBase::getDTI() const {
    return uGUIServerUIBase::DTI;
}

__attribute__((noinline)) uGUIServerUIBase::~uGUIServerUIBase() {
    DDON_STUB("uGUIServerUIBase::~uGUIServerUIBase")
    /* stub */
}

bool uGUIServerUIBase::setupBase() {
    this->uGUIBase::setup();
    return mIsEndLoadResource;
}

void uGUIServerUIBase::end() {
    mIsEnableServerUI = false;
    this->uGUIBase::end();
}

bool uGUIServerUIBase::isEnableServerUI() {
    if (mIsRequestCommand) {
        return false;
    } else {
        return mIsEnableServerUI;
    }
}

void uGUIServerUIBase::enableControl() {
    mIsEnableServerUI = true;
}

void uGUIServerUIBase::disableControl() {
    mIsEnableServerUI = false;
}

__attribute__((weak)) void uGUIServerUIBase::initServerUI(cServerUIClientControl* pControl, nUserSession::CPacket_S2C_OPEN_UI_NTC* packet) {
    DDON_STUB("uGUIServerUIBase::initServerUI")
    /* stub */
}

CDataUIListCommand* uGUIServerUIBase::getCommnadInfo(u32 commnadId) {
    if (mCommandList.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mCommandList.getBuffer()[static_cast<int>(i)]) + 8)) == commnadId) {
                return static_cast<CDataUIListCommand*>(mCommandList.getBuffer()[static_cast<int>(i)]);
            }
            i += 1u;
        } while (i < mCommandList.mLength);
    }
    return nullptr;
}

bool uGUIServerUIBase::startRequest(u32 serverUICommand) {
    if (mpServerUIControl != nullptr) {
        if ((mpServerUIControl->mState == 0) && !mIsRequestCommand) {
            mIsRequestCommand = true;
            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIServerUIBase::requestUICommand);
                mServerCommandStatusRsv = 502;
                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIServerUIBase::callbackUICommand);
                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
            } else {
                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIServerUIBase::requestUICommand);
                mServerCommandStatus = 502;
                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIServerUIBase::callbackUICommand);
                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                mServerRno = 0;
                mServerResult = 0;
            }
            return true;
        }
        return false;
    } else {
        if (mIsRequestCommand) {
            return false;
        } else {
            mIsRequestCommand = true;
            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIServerUIBase::requestUICommand);
                mServerCommandStatusRsv = 502;
                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIServerUIBase::callbackUICommand);
                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
            } else {
                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIServerUIBase::requestUICommand);
                mServerCommandStatus = 502;
                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIServerUIBase::callbackUICommand);
                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                mServerRno = 0;
                mServerResult = 0;
            }
            return true;
        }
    }
}

bool uGUIServerUIBase::requestUICommand() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqServerUICommand(mServerUIId, mCommandInfo.mCommandId, mCommandInfo.mArgNum1, mCommandInfo.mArgNum2);
    return true;
}

void uGUIServerUIBase::callbackUICommand() {
    if (mpServerUIControl != nullptr) {
        if (mCommandInfo.mEndType != 3) {
            if (mCommandInfo.mEndType == 2) {
                mpServerUIControl->closeServerUIAll();
            } else {
                if (mCommandInfo.mEndType == 1) {
                    mpServerUIControl->closeServerUI(this);
                }
            }
        } else {
            mpServerUIControl->closeServerUIChild();
        }
    }
    mIsRequestCommand = false;
}

inline uGUIServerUIBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerUIBase::MyDTI uGUIServerUIBase::DTI("uGUIServerUIBase", &::uGUIBase::DTI, 2400ul, 0u, 1u);

MtObject* uGUIServerUIBase::MyDTI::newInstance() const {
    return nullptr;
}

