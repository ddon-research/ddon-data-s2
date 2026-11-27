// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsMaterial.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::Material::getDTI() const {
    return nPhysics::Material::DTI;
}

void* nPhysics::Material::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nPhysics::Material::DTI)->memAlloc(sz, align, ::nPhysics::Material::DTI.mID);
}

nPhysics::Material::Material() {
    mStaticFriction = 2.0f;
    mKineticFriction = 1.4f;
    mRestitution = 0.0f;
    mDirection.x = ::MtVector3::Zero.x;
    mDirection.y = ::MtVector3::Zero.y;
    mDirection.z = ::MtVector3::Zero.z;
    mDirection.pad_ = 0.0f;
}

nPhysics::Material::~Material() {
}

inline nPhysics::Material::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::Material::MyDTI nPhysics::Material::DTI("nPhysics::Material", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* nPhysics::Material::MyDTI::newInstance() const {
    return new (16u) ::nPhysics::Material;
}

