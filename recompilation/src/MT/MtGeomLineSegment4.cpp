// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomLineSegment4.h"
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

const MtDTI& MtGeomLineSegment4::getDTI() const {
    return MtGeomLineSegment4::DTI;
}

void* MtGeomLineSegment4::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomLineSegment4::DTI)->memAlloc(sz, align, MtGeomLineSegment4::DTI.mID);
}

void MtGeomLineSegment4::load(MtDataReader& fin) {
    mLineSegment4.p0_4.x.v.x = fin.readF32();
    mLineSegment4.p1_4.x.v.x = fin.readF32();
    mLineSegment4.p0_4.x.v.y = fin.readF32();
    mLineSegment4.p1_4.x.v.y = fin.readF32();
    mLineSegment4.p0_4.x.v.z = fin.readF32();
    mLineSegment4.p1_4.x.v.z = fin.readF32();
    mLineSegment4.p0_4.x.v.w = fin.readF32();
    mLineSegment4.p1_4.x.v.w = fin.readF32();
    mLineSegment4.p0_4.x.v.x = fin.readF32();
    mLineSegment4.p1_4.x.v.x = fin.readF32();
    mLineSegment4.p0_4.x.v.y = fin.readF32();
    mLineSegment4.p1_4.x.v.y = fin.readF32();
    mLineSegment4.p0_4.x.v.z = fin.readF32();
    mLineSegment4.p1_4.x.v.z = fin.readF32();
    mLineSegment4.p0_4.x.v.w = fin.readF32();
    mLineSegment4.p1_4.x.v.w = fin.readF32();
    mLineSegment4.p0_4.x.v.x = fin.readF32();
    mLineSegment4.p1_4.x.v.x = fin.readF32();
    mLineSegment4.p0_4.x.v.y = fin.readF32();
    mLineSegment4.p1_4.x.v.y = fin.readF32();
    mLineSegment4.p0_4.x.v.z = fin.readF32();
    mLineSegment4.p1_4.x.v.z = fin.readF32();
    mLineSegment4.p0_4.x.v.w = fin.readF32();
    mLineSegment4.p1_4.x.v.w = fin.readF32();
}

void MtGeomLineSegment4::save(MtDataWriter& fout) {
    unsigned int i7 = 3;
    do {
        fout.writeF32(mLineSegment4.p0_4.x.v.x);
        fout.writeF32(mLineSegment4.p1_4.x.v.x);
        fout.writeF32(mLineSegment4.p0_4.x.v.y);
        fout.writeF32(mLineSegment4.p1_4.x.v.y);
        fout.writeF32(mLineSegment4.p0_4.x.v.z);
        fout.writeF32(mLineSegment4.p1_4.x.v.z);
        fout.writeF32(mLineSegment4.p0_4.x.v.w);
        fout.writeF32(mLineSegment4.p1_4.x.v.w);
        i7 += 0xFFFFFFFFu;
    } while (i7 != 0);
}

__attribute__((weak)) void MtGeomLineSegment4::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomLineSegment4::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomLineSegment4::getBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("MtGeomLineSegment4::getBoundingAABB")
    /* stub */
}

__attribute__((weak)) void MtGeomLineSegment4::getBoundingSphere(MtSphere& sphere) const {
    DDON_STUB("MtGeomLineSegment4::getBoundingSphere")
    /* stub */
}

__attribute__((weak)) void MtGeomLineSegment4::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomLineSegment4::copy")
    /* stub */
}

inline MtGeomLineSegment4::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomLineSegment4::MyDTI MtGeomLineSegment4::DTI("MtGeomLineSegment4", &::MtGeomConvex::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomLineSegment4::MyDTI::newInstance() const {
    DDON_STUB("MtGeomLineSegment4::MyDTI::newInstance")
    return nullptr;
}

