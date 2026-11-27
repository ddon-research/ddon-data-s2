// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sKeyboardExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/sKeyboard.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sKeyboardExt::getDTI() const {
    return sKeyboardExt::DTI;
}

void* sKeyboardExt::operator new(size_t sz, u32 align) {
    return sKeyboardExt::getAllocator()->memAlloc(sz, align, sKeyboardExt::DTI.getID());
}

sKeyboardExt::sKeyboardExt() {
    mKeyStateClearNum = 0;
}

sKeyboardExt::~sKeyboardExt() {
}

void sKeyboardExt::move() {
    this->sKeyboard::move();
    if (mKeyStateClearNum != 0) {
        mKeyState[6] = 0;
        mKeyState[7] = 0;
        mKeyState[4] = 0;
        mKeyState[5] = 0;
        mKeyState[2] = 0;
        mKeyState[3] = 0;
        mKeyState[0] = 0;
        mKeyState[1] = 0;
        clearKeyState();
        mKeyStateClearNum = mKeyStateClearNum - 1u;
    }
    getCurrentType();
}

void sKeyboardExt::createProperty(MtPropertyList& s) {
    this->sKeyboard::createProperty(s);
}

MtUI* sKeyboardExt::createUI(MtProperty& prop) {
    return this->sKeyboard::createUI(prop);
}

__attribute__((weak)) bool sKeyboardExt::isKbGetOn() {
    DDON_STUB("sKeyboardExt::isKbGetOn")
    return {};
}

bool sKeyboardExt::isConnect() {
    return mIsConnected;
}

void sKeyboardExt::setKeyStateClearNum(u32 keyStateClearNum) {
    if (mKeyStateClearNum < keyStateClearNum) {
        mKeyStateClearNum = keyStateClearNum;
    }
}

inline sKeyboardExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sKeyboardExt::MyDTI sKeyboardExt::DTI("sKeyboardExt", &::sKeyboard::DTI, 2696ul, 0u, 0u);

MtObject* sKeyboardExt::MyDTI::newInstance() const {
    return new (16u) sKeyboardExt;
}

const MtDTI& sKeyboardExt::cKeyArray::getDTI() const {
    return sKeyboardExt::cKeyArray::DTI;
}

MtObject* sKeyboardExt::cKeyArray::MyDTI::newInstance() const {
    return new (16u) sKeyboardExt::cKeyArray;
}

