// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIServerUIDialog.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/ServerUI.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sUnit.h"
#include "uGUIBase.h"
#include "uGUIServerUIBase.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIServerUIDialog::getDTI() const {
    return uGUIServerUIDialog::DTI;
}

void* uGUIServerUIDialog::operator new(size_t sz, u32 align) {
    return uGUIServerUIDialog::getAllocator()->memAlloc(sz, align, uGUIServerUIDialog::DTI.getID());
}

bool uGUIServerUIDialog::loadResource() {
    return true;
}

void uGUIServerUIDialog::setup() {
    if (!setupBase()) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(12u), true);
    setPlay(true);
    initDialog();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateInit);
}

void uGUIServerUIDialog::kill() {
    this->uGUIBase::kill();
}

uGUIServerUIDialog::uGUIServerUIDialog(u32 mode) : uGUIServerUIBase(0u, false) {
    mMode = mode;
    mCancelPos = -1;
    mpDialog = nullptr;
    mBaseF = mBaseF | 80u;
    mEndType = 1;
}

uGUIServerUIDialog::~uGUIServerUIDialog() {
    if (mpDialog != nullptr) {
        mpDialog->mEndType = 0;
        mpDialog->end();
    }
    mpDialog = nullptr;
}

__attribute__((weak)) void uGUIServerUIDialog::initDialog() {
    DDON_STUB("uGUIServerUIDialog::initDialog")
    /* stub */
}

void uGUIServerUIDialog::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateWait);
}

void uGUIServerUIDialog::updateWait() {
    if (mpDialog != nullptr) {
        if (mpDialog->isStop()) {
            s32 t0 = mpDialog->getChoicePos(-1);
            if (mCancelPos == t0) {
                CDataUIListCommand* t1 = getCommnadInfo(3u);
                if (t1 != nullptr) {
                    mCommandInfo.mCommandId = t1->m_unCommand;
                    mCommandInfo.mEndType = t1->m_unCommandResult;
                    mCommandInfo.mpCallbackCommndFunc = static_cast<uGUIServerUIBase::CallbackCommnad>(0);
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2368) = 0;
                    if (!startRequest(3u)) {
                        end();
                    }
                } else {
                    end();
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateExit);
            } else {
                s32 t2 = mpDialog->getChoicePos(-1);
                CDataUIListCommand* t3 = getCommnadInfo(2u);
                if (t3 != nullptr) {
                    mCommandInfo.mCommandId = t3->m_unCommand;
                    mCommandInfo.mEndType = t3->m_unCommandResult;
                    mCommandInfo.mArgNum1 = static_cast<u32>(t2);
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 2388) = 0;
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2380) = 0;
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2372) = 0;
                    if (!startRequest(2u)) {
                        end();
                    }
                } else {
                    end();
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateExit);
            }
        }
    } else {
        end();
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateExit);
    }
}

void uGUIServerUIDialog::updateExit() {
    if (!isEnableServerUI()) {
        return;
    }
    mpDialog->restart();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIServerUIDialog::updateWait);
}

inline uGUIServerUIDialog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIServerUIDialog::MyDTI uGUIServerUIDialog::DTI("uGUIServerUIDialog", &::uGUIServerUIBase::DTI, 2416ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIServerUIDialog::MyDTI::newInstance() const {
    DDON_STUB("uGUIServerUIDialog::MyDTI::newInstance")
    return nullptr;
}

