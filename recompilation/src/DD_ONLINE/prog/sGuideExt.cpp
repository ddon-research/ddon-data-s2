// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sGuideExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtNetCom.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/sGuideBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sGuideExt::getDTI() const {
    return sGuideExt::DTI;
}

void* sGuideExt::operator new(size_t sz, u32 align) {
    return sGuideExt::getAllocator()->memAlloc(sz, align, sGuideExt::DTI.getID());
}

sGuideExt::sGuideExt() {
    DDON_STUB("sGuideExt::sGuideExt")
    /* stub */
}

sGuideExt::~sGuideExt() {
    DDON_STUB("sGuideExt::~sGuideExt")
    /* stub */
}

void sGuideExt::createProperty(MtPropertyList& s) {
    this->sGuideBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "内部文言の初期化", static_cast<MT_MFUNC>(&::sGuideExt::initInnerString), 10u);
}

__attribute__((weak)) void sGuideExt::initInnerString() {
}

void sGuideExt::moveEx() {
    if (mpRichPresence == nullptr) {
        return;
    }
    mpRichPresence->update();
}

__attribute__((weak)) void sGuideExt::onNotifyEvent(u32 notifyID, u32 param) {
}

inline sGuideExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sGuideExt::MyDTI sGuideExt::DTI("sGuideExt", &::cSystem::DTI, 64ul, 0u, 0u);

sGuideExt* sGuideExt::mpInstance;

__attribute__((weak)) MtObject* sGuideExt::MyDTI::newInstance() const {
    DDON_STUB("sGuideExt::MyDTI::newInstance")
    return nullptr;
}

