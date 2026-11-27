// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rScenario.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "cAreaHit.h"
#include "../../XFramework/cResource.h"
#include "cScenario.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cScenarioData::getDTI() const {
    return cScenarioData::DTI;
}

cScenarioData::~cScenarioData() {
    if (mpParam != nullptr) {
        delete mpParam;
        mpParam = nullptr;
    }
    if (mpShape != nullptr) {
        delete mpShape;
        mpShape = nullptr;
    }
    if (mpArg == nullptr) {
        return;
    }
    delete mpArg;
    mpArg = nullptr;
}

void cScenarioData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Param", reinterpret_cast<MtObject* *>(&mpParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Shape", reinterpret_cast<MtObject* *>(&mpShape), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Arg", reinterpret_cast<MtObject* *>(&mpArg), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 1u, 0u);
}

inline cScenarioData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cScenarioData::MyDTI cScenarioData::DTI("cScenarioData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cScenarioData::MyDTI::newInstance() const {
    return new (16u) cScenarioData;
}

const MtDTI& rScenario::getDTI() const {
    return rScenario::DTI;
}

rScenario::~rScenario() {
    if (mArray.mLength != 0) {
        u32 v0_0 = mArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArray.mpArray[i0_3];
                v1_0 = mArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
    }
    mArray.mpArray = nullptr;
    mArray.mBufsiz = 0;
    mArray.mLength = 0;
}

MT_CTSTR rScenario::getExt() const {
    return "sce";
}

MT_CTSTR rScenario::getName() const {
    return "rScenario";
}

void rScenario::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

MtUI* rScenario::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rScenario::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(6), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rScenario::save(MtStream& out) {
    MtSerializer sz(65536);
    sz.serializeBinary(out, static_cast<u16>(6), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
    return true;
}

void rScenario::clear() {
    if (mArray.mLength != 0) {
        u32 v0_0 = mArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArray.mpArray[i0_3];
                v1_0 = mArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
    }
    mArray.mpArray = nullptr;
    mArray.mBufsiz = 0;
    mArray.mLength = 0;
}

inline rScenario::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rScenario::MyDTI rScenario::DTI("rScenario", &::cResource::DTI, 144ul, 0u, 0u);

MT_CTSTR rScenario::mSubExt[4] = {
    "sce",
    "door",
    "fsm",
    "custom",
};

MtObject* rScenario::MyDTI::newInstance() const {
    return new (16u) rScenario;
}

