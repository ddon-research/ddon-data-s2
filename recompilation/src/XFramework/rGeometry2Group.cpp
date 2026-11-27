// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rGeometry2Group.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#include "rGeometry2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGeometry2Group::getDTI() const {
    return rGeometry2Group::DTI;
}

rGeometry2Group::~rGeometry2Group() {
    DDON_STUB("rGeometry2Group::~rGeometry2Group")
    /* stub */
}

MtUI* rGeometry2Group::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rGeometry2Group::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mMagic", &mMagic, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVersion", &mVersion, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGeometryResourceArray", static_cast<MtObject*>(&mGeometryResourceArray), 1u, 0u);
}

void rGeometry2Group::clear() {
    if (mGeometryResourceArray.mLength != 0) {
        u32 v0_0 = mGeometryResourceArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGeometryResourceArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mGeometryResourceArray.mpArray[i0_3];
                v1_0 = mGeometryResourceArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGeometryResourceArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGeometryResourceArray.mpArray));
    }
    mGeometryResourceArray.mpArray = nullptr;
    mGeometryResourceArray.mBufsiz = 0;
    mGeometryResourceArray.mLength = 0;
}

__attribute__((weak)) bool rGeometry2Group::load(MtStream& in) {
    DDON_STUB("rGeometry2Group::load")
    return {};
}

bool rGeometry2Group::save(MtStream& out) {
    out.write(static_cast<const void*>(&mMagic), 4u);
    out.write(static_cast<const void*>(&mVersion), 4u);
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
}

MT_CTSTR rGeometry2Group::getExt() const {
    return "geog";
}

rGeometry2* rGeometry2Group::getGeometryResource(u32 ResourceIndex) const {
    return static_cast<rGeometry2*>(mGeometryResourceArray.mpArray[ResourceIndex]);
}

u32 rGeometry2Group::getGeometryResourceNum() const {
    return mGeometryResourceArray.mLength;
}

inline rGeometry2Group::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGeometry2Group::MyDTI rGeometry2Group::DTI("rGeometry2Group", &::cResource::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* rGeometry2Group::MyDTI::newInstance() const {
    DDON_STUB("rGeometry2Group::MyDTI::newInstance")
    return nullptr;
}

