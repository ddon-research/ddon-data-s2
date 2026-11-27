// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "sDialogBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "aTitle.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "cNetSessionManager.h"
#include "../../XFramework/cSystem.h"
#include "nDialog.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCommonDialog.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sDialogBase::getDTI() const {
    return sDialogBase::DTI;
}

void* sDialogBase::operator new(size_t sz, u32 align) {
    return sDialogBase::getAllocator()->memAlloc(sz, align, sDialogBase::DTI.getID());
}

sDialogBase::sDialogBase() {
    DDON_STUB("sDialogBase::sDialogBase")
    /* stub */
}

sDialogBase::~sDialogBase() {
}

__attribute__((weak)) void sDialogBase::reset() {
    DDON_STUB("sDialogBase::reset")
    /* stub */
}

__attribute__((weak)) void sDialogBase::move() {
    DDON_STUB("sDialogBase::move")
    /* stub */
}

void sDialogBase::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sDialogBase::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

bool sDialogBase::isDialogExecute() {
    return (mInfoOrderTbl[0] > -1) && ((mInfo[mInfoOrderTbl[0]].state != nDialog::STATE_NONE) && (mInfo[mInfoOrderTbl[0]].state != nDialog::STATE_END));
}

__attribute__((weak)) u32 sDialogBase::request(nDialog::MSG_NO msgNo, nDialog::DLOG_TYPE type, nDialog::DLOG_ATTR attr, nDialog::DLOG_PRIO prio, const MtNetError* pNetError, void(*pFuncYes)(), void(*pFuncNo)(), void(*pFuncOk)(), void(*pFuncSel0)(), void(*pFuncSel1)(), void(*pFuncSel2)()) {
    DDON_STUB("sDialogBase::request")
    return {};
}

void sDialogBase::setFreeMessage(u32 handle, MT_CTSTR str) {
    for (int i0_0 = 0; i0_0 <= 7; i0_0 = i0_0 + 1) {
        if (mInfo[i0_0].state != nDialog::STATE_NONE) {
            if (mInfo[i0_0].handle == handle) {
                strncpy(&mInfo[i0_0].str[0], str, 255ul);
                return;
            }
        }
    }
}

void sDialogBase::closeDialog(u32 handle) {
    for (int i0_0 = 0; i0_0 <= 7; i0_0 = i0_0 + 1) {
        if (mInfo[i0_0].state != nDialog::STATE_NONE) {
            if (mInfo[i0_0].handle == handle) {
                if (mInfo[i0_0].function == nDialog::FUNC_REQ) {
                    mInfo[i0_0].function = nDialog::FUNC_END;
                }
                return;
            }
        }
    }
}

__attribute__((weak)) void sDialogBase::callbackNativeMsgDialog(s32 buttonType, void* data) {
    DDON_STUB("sDialogBase::callbackNativeMsgDialog")
    /* stub */
}

__attribute__((weak)) s32 sDialogBase::reqNativeMsgDialog(nDialog::MSG_NO msgNo) {
    DDON_STUB("sDialogBase::reqNativeMsgDialog")
    return {};
}

__attribute__((weak)) void sDialogBase::callbackCommonDialog(s32 result) {
    DDON_STUB("sDialogBase::callbackCommonDialog")
    /* stub */
}

nDialog::stInfo* sDialogBase::getInfo(u32 handle) {
    s32 i = 0;
    nDialog::stInfo* p2 = &mInfo[0];
    do {
        if (p2->state != nDialog::STATE_NONE) {
            if (p2->handle == handle) {
                return p2;
            }
        }
        i += 1;
        p2 += static_cast<int>(1);
    } while ((i + 0) <= 7);
    return nullptr;
}

bool sDialogBase::isActiveInfo(const nDialog::stInfo& info) {
    return (info.state != nDialog::STATE_NONE) && (info.state != nDialog::STATE_END);
}

__attribute__((weak)) nDialog::stInfo* sDialogBase::pullInfo() {
    DDON_STUB("sDialogBase::pullInfo")
    return nullptr;
}

__attribute__((weak)) void sDialogBase::setOrderInfo(nDialog::stInfo& info) {
    DDON_STUB("sDialogBase::setOrderInfo")
    /* stub */
}

__attribute__((weak)) void sDialogBase::callbackReturnTitle() {
    DDON_STUB("sDialogBase::callbackReturnTitle")
    /* stub */
}

__attribute__((weak)) void sDialogBase::callbackReturnLauncher() {
    DDON_STUB("sDialogBase::callbackReturnLauncher")
    /* stub */
}

__attribute__((weak)) void sDialogBase::callbackOffline() {
    DDON_STUB("sDialogBase::callbackOffline")
    /* stub */
}

s32 sDialogBase::convReturnMsgNo(s32 msgNo) {
    u32 i = 0;
    do {
        if (i != 6) {
            if (sDialogBase::convReturnMsgNoTbl[i].srcMsgNo == msgNo) {
                return sDialogBase::convReturnMsgNoTbl[i].dstMsgNo;
            }
        } else {
            return msgNo;
        }
        i += 1u;
    } while (i <= 6u);
    return msgNo;
}

inline sDialogBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sDialogBase::MyDTI sDialogBase::DTI("sDialogBase", &::cSystem::DTI, 2960ul, 0u, 0u);

sDialogBase* sDialogBase::mpInstance;

alignas(4) unsigned char sDialogBase_convReturnMsgNoTbl_bytes[56] __asm__("_ZN11sDialogBase18convReturnMsgNoTblE") = {0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

__attribute__((weak)) MtObject* sDialogBase::MyDTI::newInstance() const {
    DDON_STUB("sDialogBase::MyDTI::newInstance")
    return nullptr;
}

