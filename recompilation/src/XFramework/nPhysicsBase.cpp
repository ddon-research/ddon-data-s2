// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsBase.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::Base::getDTI() const {
    return nPhysics::Base::DTI;
}

nPhysics::Base::Base() {
}

nPhysics::Base::~Base() {
}

inline nPhysics::Base::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::Base::MyDTI nPhysics::Base::DTI("nPhysics::Base", &::MtObject::DTI, 8ul, 0u, 1u);

MtObject* nPhysics::Base::MyDTI::newInstance() const {
    return nullptr;
}

