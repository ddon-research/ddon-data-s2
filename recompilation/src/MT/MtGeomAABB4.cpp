// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomAABB4.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtGeometry3D.h"
#include "MtMemoryAllocator.h"
#include "MtPrimitive3D.h"
#include "MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtGeomAABB4::getDTI() const {
    return MtGeomAABB4::DTI;
}

void* MtGeomAABB4::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomAABB4::DTI)->memAlloc(sz, align, MtGeomAABB4::DTI.mID);
}

inline void MtGeomAABB4::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtGeomAABB4::DTI)->memFree(p_addr);
}

__attribute__((weak)) void MtGeomAABB4::load(MtDataReader& fin) {
    DDON_STUB("MtGeomAABB4::load")
    /* stub */
}

__attribute__((weak)) void MtGeomAABB4::save(MtDataWriter& fout) {
    DDON_STUB("MtGeomAABB4::save")
    /* stub */
}

__attribute__((weak)) void MtGeomAABB4::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomAABB4::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomAABB4::getBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("MtGeomAABB4::getBoundingAABB")
    /* stub */
}

__attribute__((weak)) void MtGeomAABB4::getBoundingSphere(MtSphere& sphere) const {
    DDON_STUB("MtGeomAABB4::getBoundingSphere")
    /* stub */
}

__attribute__((weak)) void MtGeomAABB4::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomAABB4::copy")
    /* stub */
}

inline MtGeomAABB4::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomAABB4::MyDTI MtGeomAABB4::DTI("MtGeomAABB4", &::MtGeometry::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomAABB4::MyDTI::newInstance() const {
    DDON_STUB("MtGeomAABB4::MyDTI::newInstance")
    return nullptr;
}

