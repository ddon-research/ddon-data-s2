// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomPlane.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtDataReader.h"
#include "MtDataWriter.h"
#include "MtGeometry3D.h"
#include "MtMemoryAllocator.h"
#include "MtPrimitive3D.h"
#include "MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtGeomPlane::getDTI() const {
    return MtGeomPlane::DTI;
}

void* MtGeomPlane::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomPlane::DTI)->memAlloc(sz, align, MtGeomPlane::DTI.mID);
}

inline void MtGeomPlane::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtGeomPlane::DTI)->memFree(p_addr);
}

void MtGeomPlane::load(MtDataReader& fin) {
    mPlane.normal.x = fin.readF32();
    mPlane.normal.y = fin.readF32();
    mPlane.normal.z = fin.readF32();
    mPlane.dist = fin.readF32();
}

void MtGeomPlane::save(MtDataWriter& fout) {
    fout.writeF32(mPlane.normal.x);
    fout.writeF32(mPlane.normal.y);
    fout.writeF32(mPlane.normal.z);
    fout.writeF32(mPlane.dist);
}

__attribute__((weak)) void MtGeomPlane::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomPlane::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomPlane::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomPlane::copy")
    /* stub */
}

inline MtGeomPlane::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomPlane::MyDTI MtGeomPlane::DTI("MtGeomPlane", &::MtGeometry::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomPlane::MyDTI::newInstance() const {
    DDON_STUB("MtGeomPlane::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtGeomPlaneXZ::getDTI() const {
    return MtGeomPlaneXZ::DTI;
}

inline void MtGeomPlaneXZ::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtGeomPlaneXZ::DTI)->memFree(p_addr);
}

void MtGeomPlaneXZ::load(MtDataReader& fin) {
    mPlaneXZ.dist = fin.readF32();
}

void MtGeomPlaneXZ::save(MtDataWriter& fout) {
    fout.writeF32(mPlaneXZ.dist);
}

__attribute__((weak)) void MtGeomPlaneXZ::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomPlaneXZ::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomPlaneXZ::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomPlaneXZ::copy")
    /* stub */
}

inline MtGeomPlaneXZ::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomPlaneXZ::MyDTI MtGeomPlaneXZ::DTI("MtGeomPlaneXZ", &::MtGeometry::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomPlaneXZ::MyDTI::newInstance() const {
    DDON_STUB("MtGeomPlaneXZ::MyDTI::newInstance")
    return nullptr;
}

