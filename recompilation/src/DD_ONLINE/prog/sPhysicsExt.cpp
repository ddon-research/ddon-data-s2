// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sPhysicsExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/nPhysicsStruct.h"
#include "../../XFramework/nPhysicsSystem.h"
#include "../../XFramework/sCamera.h"
#include "../../XFramework/uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sPhysicsExt::getDTI() const {
    return sPhysicsExt::DTI;
}

void* sPhysicsExt::operator new(size_t sz, u32 align) {
    return sPhysicsExt::getAllocator()->memAlloc(sz, align, sPhysicsExt::DTI.getID());
}

sPhysicsExt::sPhysicsExt(const nPhysics::INITIALIZE_PARAMETER& parameter) : nPhysics::System(parameter) {
    mWorldCenterMode = 1;
    mContactArrayIndex = 0;
}

sPhysicsExt::~sPhysicsExt() {
}

void sPhysicsExt::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldCenterMode", &mWorldCenterMode, 0u, 0u);
}

void sPhysicsExt::move() {
    if (mWorldCenterMode != 1) {
        return;
    }
    moveWorldCenterCamera();
}

__attribute__((weak)) void sPhysicsExt::moveWorldCenterCamera() {
    DDON_STUB("sPhysicsExt::moveWorldCenterCamera")
    /* stub */
}

inline sPhysicsExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sPhysicsExt::MyDTI sPhysicsExt::DTI("sPhysicsExt", &::nPhysics::System::DTI, 38432ul, 0u, 0u);

__attribute__((weak)) MtObject* sPhysicsExt::MyDTI::newInstance() const {
    DDON_STUB("sPhysicsExt::MyDTI::newInstance")
    return nullptr;
}

