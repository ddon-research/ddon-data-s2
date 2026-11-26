// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rBowActParamList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#include "nHumanBow.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rBowActParamList::getDTI() const {
    return rBowActParamList::DTI;
}

inline void* rBowActParamList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rBowActParamList::DTI)->memAlloc(sz, align, rBowActParamList::DTI.getID());
}

inline void rBowActParamList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rBowActParamList::DTI)->memFree(p_addr);
}

inline rBowActParamList::rBowActParamList() {
    setAttribute(18u);
    mParamList.mAutoDelete = true;
}

rBowActParamList::~rBowActParamList() {
    if (mParamList.mLength != 0) {
        u32 v0_0 = mParamList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mParamList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mParamList.mpArray[i0_3];
                v1_0 = mParamList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mParamList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamList.mpArray));
    }
    mParamList.mpArray = nullptr;
    mParamList.mBufsiz = 0;
    mParamList.mLength = 0;
}

void rBowActParamList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mParamList", static_cast<MtObject*>(&mParamList), 0u, 0u);
}

__attribute__((weak)) void rBowActParamList::clear() {
}

bool rBowActParamList::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(20), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rBowActParamList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(20), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rBowActParamList::DTI));
}

MT_CTSTR rBowActParamList::getExt() const {
    return "bap";
}

const nHumanBow::cBowActParam* rBowActParamList::getParam(u32 index) {
    if (index < mParamList.mLength) {
        return static_cast<const nHumanBow::cBowActParam*>(mParamList.mpArray[index]);
    } else {
        return nullptr;
    }
}

inline rBowActParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rBowActParamList::MyDTI rBowActParamList::DTI("rBowActParamList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rBowActParamList::MyDTI::newInstance() const {
    return new (16u) rBowActParamList;
}

