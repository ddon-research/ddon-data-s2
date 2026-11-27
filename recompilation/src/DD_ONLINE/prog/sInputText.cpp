// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sInputText.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cSystem.h"
#include "nInputText.h"
#include "../../XFramework/sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sInputText::getDTI() const {
    return sInputText::DTI;
}

sInputText::sInputText() {
    DDON_STUB("sInputText::sInputText")
    /* stub */
}

sInputText::~sInputText() {
    sInputText::mpInstance = nullptr;
}

__attribute__((weak)) void sInputText::move() {
}

void sInputText::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sInputText::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

bool sInputText::startInput(MT_CWSTR initText, u32 maxCharacterCount, sInputText::MODE mode, bool isImeOn, bool isPassword, cInputTextKeyboardHook* keyboardHook) {
    mMode = mode;
    mCharCountMax = (maxCharacterCount <= 1023u) ? maxCharacterCount : 1023u;
    mContext.mState = 0;
    mContext.mInputString.clear();
    if (initText != nullptr) {
        if ((*initText) != static_cast<wchar_t>(0)) {
            mContext.mInputString.copy(initText);
            mContext.mInputString.cut(mCharCountMax);
        }
    }
    mContext.mState = mContext.mState | 1u;
    mCaretReset = true;
    mPrevTimer = 0;
    mIsPassword = isPassword;
    mKeyboardHook = keyboardHook;
    return true;
}

void sInputText::endInput() {
    mKeyboardHook = nullptr;
    mContext.clear();
    mContextBackup.clear();
}

__attribute__((weak)) void sInputText::completeComposition() {
}

__attribute__((weak)) void sInputText::cancelComposition() {
}

void sInputText::forceBackupContext() {
    mContextBackup.copy(mContext);
}

u32 sInputText::getCaretBlinkTime() const {
    return 1000;
}

__attribute__((weak)) void sInputText::updateCaret() {
    DDON_STUB("sInputText::updateCaret")
    /* stub */
}

bool sInputText::processKeyEscape() {
    mContext.mState = mContext.mState | 4u;
    return true;
}

bool sInputText::processKeyEnter() {
    mContext.mState = mContext.mState | 2u;
    return true;
}

inline sInputText::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sInputText::MyDTI sInputText::DTI("sInputText", &::cSystem::DTI, 65200ul, 0u, 0u);

sInputText* sInputText::mpInstance;

__attribute__((weak)) MtObject* sInputText::MyDTI::newInstance() const {
    DDON_STUB("sInputText::MyDTI::newInstance")
    return nullptr;
}

