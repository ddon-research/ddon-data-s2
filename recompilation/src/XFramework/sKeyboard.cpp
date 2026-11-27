// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "sKeyboard.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cSystem.h"
#include "../generated/shared/ime_types.h"
#include "sApp.h"
#include "sMain.h"
#include "sMouse.h"
#include "sUserManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sKeyboard::getDTI() const {
    return sKeyboard::DTI;
}

sKeyboard::sKeyboard() {
    DDON_STUB("sKeyboard::sKeyboard")
    /* stub */
}

__attribute__((noinline)) sKeyboard::~sKeyboard() {
    DDON_STUB("sKeyboard::~sKeyboard")
    /* stub */
}

__attribute__((weak)) void sKeyboard::move() {
    DDON_STUB("sKeyboard::move")
    /* stub */
}

void sKeyboard::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mRepeatStartTime", &mRepeatStartTime, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRepeatTime", &mRepeatTime, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mActive", &mActive, 2u, 0u);
}

MtUI* sKeyboard::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

sKeyboard::TYPE sKeyboard::getCurrentType() {
    return TYPE_DEFAULT;
}

void sKeyboard::clearKeyState() {
    memset(static_cast<void*>(&mState[0]), 0, 2240ul);
}

__attribute__((weak)) void sKeyboard::updateState(sKeyboard::STATE* pstate) {
    DDON_STUB("sKeyboard::updateState")
    /* stub */
}

__attribute__((weak)) void sKeyboard::keyboardEvent(void* arg, const SceImeEvent* e) {
    DDON_STUB("sKeyboard::keyboardEvent")
    /* stub */
}

inline sKeyboard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sKeyboard::MyDTI sKeyboard::DTI("sKeyboard", &::cSystem::DTI, 2688ul, 0u, 0u);

alignas(1) unsigned char sKeyboard_mKbAssign_bytes[144] __asm__("_ZN9sKeyboard9mKbAssignE") = {0x00, 0x00, 0x00, 0x00, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x0d, 0x1b, 0x08, 0x09, 0x20, 0xbd, 0xde, 0xc0, 0xdb, 0xdc, 0xdd, 0xbb, 0xba, 0x00, 0xbc, 0xbe, 0xbf, 0x00, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x2a, 0x91, 0x13, 0x2d, 0x24, 0x21, 0x2e, 0x23, 0x22, 0x27, 0x25, 0x28, 0x26, 0x90, 0x6f, 0x6a, 0x6d, 0x6b, 0x0d, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x60, 0x6e, 0x00, 0x5d, 0x00, 0x00, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe2, 0x00, 0xdc, 0x1c, 0x1d, 0x00, 0x00, 0x00, 0x00};

sKeyboard* sKeyboard::mpInstance;

__attribute__((weak)) MtObject* sKeyboard::MyDTI::newInstance() const {
    DDON_STUB("sKeyboard::MyDTI::newInstance")
    return nullptr;
}

