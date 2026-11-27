// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOccluderExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#include "sOccluderExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rOccluderEx::getDTI() const {
    return rOccluderEx::DTI;
}

rOccluderEx::~rOccluderEx() {
    if (mAreaList.mLength != 0) {
        u32 v0_0 = mAreaList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaList.mpArray[i0_3];
                v1_0 = mAreaList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaList.mpArray));
    }
    mAreaList.mpArray = nullptr;
    mAreaList.mBufsiz = 0;
    mAreaList.mLength = 0;
}

MT_CTSTR rOccluderEx::getExt() const {
    return "oce";
}

void rOccluderEx::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaList", static_cast<MtObject*>(&mAreaList), 0u, 0u);
}

MtUI* rOccluderEx::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rOccluderEx::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rOccluderEx::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
}

sOccluderEx::Area* rOccluderEx::getArea(u32 index) {
    if (index < mAreaList.mLength) {
        return static_cast<sOccluderEx::Area*>(mAreaList.mpArray[index]);
    } else {
        return nullptr;
    }
}

u32 rOccluderEx::getAreaNum() {
    return mAreaList.mLength;
}

sOccluderEx::Shape* rOccluderEx::getAreaShape(u32 areaIdx, u32 shapeIdx) {
    if (areaIdx < mAreaList.mLength) {
        if (mAreaList.mpArray[areaIdx] != nullptr) {
            return static_cast<sOccluderEx::Area*>(mAreaList.mpArray[areaIdx])->getShape(shapeIdx);
        }
    }
    return nullptr;
}

u32 rOccluderEx::getAreaShapeNum(u32 areaIdx) {
    if (areaIdx < mAreaList.mLength) {
        if (mAreaList.mpArray[areaIdx] != nullptr) {
            return static_cast<sOccluderEx::Area*>(mAreaList.mpArray[areaIdx])->getShapeNum();
        }
    }
    return 0;
}

inline rOccluderEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOccluderEx::MyDTI rOccluderEx::DTI("rOccluderEx", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rOccluderEx::MyDTI::newInstance() const {
    return new (16u) rOccluderEx;
}

