// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sCommonDialog.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cSystem.h"
#include "sApp.h"
#include "sUserManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sCommonDialog::getDTI() const {
    return sCommonDialog::DTI;
}

void* sCommonDialog::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sCommonDialog::DTI)->memAlloc(sz, align, sCommonDialog::DTI.mID);
}

sCommonDialog::sCommonDialog() {
    DDON_STUB("sCommonDialog::sCommonDialog")
    /* stub */
}

__attribute__((noinline)) sCommonDialog::~sCommonDialog() {
    DDON_STUB("sCommonDialog::~sCommonDialog")
    /* stub */
}

void sCommonDialog::move() {
    if (mState == STATE_NONE) {
        createMessageDialog();
    }
    updateMessageDialog();
    updateImeDialog();
}

MtUI* sCommonDialog::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sCommonDialog::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mState", reinterpret_cast<s32*>(&mState), 1u, 0u);
}

sCommonDialog::STATE sCommonDialog::getState() const {
    return mState;
}

__attribute__((weak)) bool sCommonDialog::createUserMsgDialog(MT_CTSTR message, sCommonDialog::BUTTON_TYPE type, MtObject* owner, sCommonDialog::MSG_DIALOG_CALLBACK callback, u32 prio) {
    DDON_STUB("sCommonDialog::createUserMsgDialog")
    return {};
}

__attribute__((weak)) bool sCommonDialog::createErrorMsgDialog(s32 errorcode) {
    DDON_STUB("sCommonDialog::createErrorMsgDialog")
    return {};
}

__attribute__((weak)) s32 sCommonDialog::updateMessageDialog() {
    DDON_STUB("sCommonDialog::updateMessageDialog")
    return {};
}

__attribute__((weak)) s32 sCommonDialog::updateImeDialog() {
    DDON_STUB("sCommonDialog::updateImeDialog")
    return {};
}

__attribute__((weak)) bool sCommonDialog::addMsgDialogList(sCommonDialog::CommonDialogData* data) {
    DDON_STUB("sCommonDialog::addMsgDialogList")
    return {};
}

__attribute__((weak)) bool sCommonDialog::createMessageDialog() {
    DDON_STUB("sCommonDialog::createMessageDialog")
    return {};
}

inline sCommonDialog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCommonDialog::MyDTI sCommonDialog::DTI("sCommonDialog", &::cSystem::DTI, 4200ul, 0u, 0u);

sCommonDialog* sCommonDialog::mpInstance;

__attribute__((weak)) MtObject* sCommonDialog::MyDTI::newInstance() const {
    DDON_STUB("sCommonDialog::MyDTI::newInstance")
    return nullptr;
}

