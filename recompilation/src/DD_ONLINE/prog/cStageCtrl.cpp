// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cStageCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rStageCustom.h"
#include "rStageCustomParts.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStageCtrl::getDTI() const {
    return cStageCtrl::DTI;
}

cStageCtrl::cStageCtrl() {
    DDON_STUB("cStageCtrl::cStageCtrl")
    /* stub */
}

cStageCtrl::~cStageCtrl() {
    if (mAreaArray.mLength != 0) {
        u32 v0_0 = mAreaArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaArray.mpArray[i0_3];
                v1_0 = mAreaArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaArray.mpArray));
    }
    mAreaArray.mpArray = nullptr;
    mAreaArray.mBufsiz = 0;
    mAreaArray.mLength = 0;
}

void cStageCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaArray", static_cast<MtObject*>(&mAreaArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPartsDungeonNo", &mPartsDungeonNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsInit", &mIsInit, 0u, 0u);
}

void cStageCtrl::clear() {
    if (mAreaArray.mLength != 0) {
        u32 v0_0 = mAreaArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaArray.mpArray[i0_3];
                v1_0 = mAreaArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaArray.mpArray));
    }
    mAreaArray.mpArray = nullptr;
    mAreaArray.mBufsiz = 0;
    mAreaArray.mLength = 0;
    mPartsDungeonNo = -1;
    mIsInit = false;
}

cStageCtrl::Area* cStageCtrl::getArea(u32 idx) {
    if (idx < mAreaArray.mLength) {
        return static_cast<Area*>(mAreaArray.getBuffer()[static_cast<int>(idx)]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void cStageCtrl::createCustomArea(rStageCustom* pRes) {
    DDON_STUB("cStageCtrl::createCustomArea")
    /* stub */
}

inline cStageCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStageCtrl::MyDTI cStageCtrl::DTI("cStageCtrl", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cStageCtrl::MyDTI::newInstance() const {
    DDON_STUB("cStageCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cStageCtrl::Area::getDTI() const {
    return cStageCtrl::Area::DTI;
}

void cStageCtrl::Area::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDepth", &mDepth, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
}

inline cStageCtrl::Area::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStageCtrl::Area::MyDTI cStageCtrl::Area::DTI("cStageCtrl::Area", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cStageCtrl::Area::MyDTI::newInstance() const {
    return new (16u) cStageCtrl::Area;
}

template MtTypedArray<cStageCtrl::Area>::~MtTypedArray();

