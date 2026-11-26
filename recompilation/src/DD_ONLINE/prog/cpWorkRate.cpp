// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpWorkRate.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sUnit.h"
#include "sWorkRate.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpWorkRate::getDTI() const {
    return cpWorkRate::DTI;
}

inline MtAllocator* cpWorkRate::getAllocator() {
    return MtMemoryAllocator::getAllocator(cpWorkRate::DTI);
}

void* cpWorkRate::operator new(size_t sz, u32 align) {
    return cpWorkRate::getAllocator()->memAlloc(sz, align, cpWorkRate::DTI.getID());
}

inline void cpWorkRate::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpWorkRate::DTI)->memFree(p_addr);
}

cpWorkRate::cpWorkRate() {
    DDON_STUB("cpWorkRate::cpWorkRate")
    /* stub */
}

cpWorkRate::~cpWorkRate() {
}

void cpWorkRate::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpWorkRate::setup() {
    this->cpComponent::setup();
}

void cpWorkRate::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpWorkRate::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "HitStop", &mSpeed[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Slow", &mSpeed[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RATE2", &mSpeed[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RATE3", &mSpeed[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ASSASSIN_FINISH", &mSpeed[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\212\266\346\205\213\347\225\260\345\270\270\343\201\256\343\200\214\351\201\205\345\273\266\343\200\215\343\201\253\343\202\210\343\202\213\345\244\211\345\214\226", &mSpeed[5], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\212\266\346\205\213\347\225\260\345\270\270\343\201\256\345\201\234\346\255\242\347\263\273(\351\273\204\351\207\221\345\214\226,\347\237\263\345\214\226,\345\207\215\347\265\220)\343\201\253\343\202\210\343\202\213\345\244\211\345\214\226", &mSpeed[6], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\225\265\347\224\250\343\200\202\347\212\266\346\205\213\345\244\211\345\214\226\343\201\253\343\202\210\343\202\213\345\212\271\346\236\234", &mSpeed[7], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "STAMINA\345\210\207\343\202\214\343\202\254\343\203\274\343\203\211\343\203\226\343\203\254\343\202\244\343\202\257", &mSpeed[8], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\212\266\346\205\213\347\225\260\345\270\270\343\201\256\343\200\214\346\265\270\351\243\237\343\200\215\343\201\253\343\202\210\343\202\213\345\244\211\345\214\226", &mSpeed[9], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\212\266\346\205\213\347\225\260\345\270\270\343\201\256\346\200\222\343\202\212\343\201\256\343\201\221\343\201\236\343\202\212\343\201\253\343\202\210\343\202\213\345\212\271\346\236\234", &mSpeed[10], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRate", &mRate, 0u, 0u);
}

__attribute__((weak)) void cpWorkRate::update() {
    DDON_STUB("cpWorkRate::update")
    /* stub */
}

__attribute__((weak)) void cpWorkRate::reUpdateRate() {
    DDON_STUB("cpWorkRate::reUpdateRate")
    /* stub */
}

void cpWorkRate::setSpeed(f32 spd, cpWorkRate::RATE_INDEX Idx) {
    mSpeed[Idx] = spd;
}

void cpWorkRate::setTypeBit(u32 typeBit) {
    mTypeBit = typeBit;
}

u32 cpWorkRate::getTypeBit() const {
    return mTypeBit;
}

f32 cpWorkRate::getCollisionCacheRate() const {
    return mSpeed[0] * mSpeed[5];
}

f32 cpWorkRate::getSpeedAll() const {
    return mSpeed[10] * (mSpeed[9] * (mSpeed[8] * (mSpeed[7] * (mSpeed[6] * (mSpeed[5] * (mSpeed[4] * (mSpeed[3] * (mSpeed[2] * (mSpeed[0] * mSpeed[1])))))))));
}

f32 cpWorkRate::getSpeed(cpWorkRate::RATE_INDEX Idx) const {
    return mSpeed[Idx];
}

inline cpWorkRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpWorkRate::MyDTI cpWorkRate::DTI("cpWorkRate", &::cpComponent::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* cpWorkRate::MyDTI::newInstance() const {
    DDON_STUB("cpWorkRate::MyDTI::newInstance")
    return nullptr;
}

