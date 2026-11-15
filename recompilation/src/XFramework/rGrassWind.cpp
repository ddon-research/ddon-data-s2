// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rGrassWind.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cResource.h"
#include "uGrassWind.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGrassWind::getDTI() const {
    return rGrassWind::DTI;
}

inline void rGrassWind::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGrassWind::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rGrassWind::~rGrassWind() {
        for (u32 t1 = 0u; t1 < mParamSetArray.length(); t1++) {
            MtObject* t0 = mParamSetArray.getBuffer()[t1];
            if (t0 != nullptr) {
                delete t0;
            }
        }
        mParamSetArray.clear(true);
}

__attribute__((weak)) void rGrassWind::createProperty(MtPropertyList& s) {
    DDON_STUB("rGrassWind::createProperty")
    /* stub */
}

MtUI* rGrassWind::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) bool rGrassWind::load(MtStream& in) {
    HEADER head;
    head.magic = HEADER_MAGIC;
    head.version = DATA_VERSION;
    in.read(&head, sizeof(HEADER));
    if (head.magic != HEADER_MAGIC || head.version != DATA_VERSION) {
        return false;
    }
    in.read(&mDTI, sizeof(u32));
    in.read(&mMaxFrame, sizeof(u32));
    in.read(&mPriority, sizeof(u32));
    in.read(&mLoop, sizeof(bool));
    in.read(&mAutoDeath, sizeof(bool));
    u32 length = 0;
    in.read(&length, sizeof(u32));
    for (u32 i = 0; i < length; i++) {
        cParamSet* p_params = new (16u) cParamSet(nullptr);
        p_params->load(in);
        mParamSetArray.add(p_params);
    }
    return true;
}

__attribute__((weak)) bool rGrassWind::save(MtStream& out) {
    HEADER head;
    head.magic = HEADER_MAGIC;
    head.version = DATA_VERSION;
    head.dummy = 0;
    out.write(&head, sizeof(HEADER));
    out.write(&mDTI, sizeof(u32));
    out.write(&mMaxFrame, sizeof(u32));
    out.write(&mPriority, sizeof(u32));
    out.write(&mLoop, sizeof(bool));
    out.write(&mAutoDeath, sizeof(bool));
    u32 length = 0;
    for (u32 i = 0; i < mParamSetArray.length(); i++) {
        cParamSet* p_params = static_cast<cParamSet*>(mParamSetArray.getBuffer()[i]);
        length += p_params->isEnable();
    }
    out.write(&length, sizeof(u32));
    for (u32 i = 0; i < mParamSetArray.length(); i++) {
        cParamSet* p_params = static_cast<cParamSet*>(mParamSetArray.getBuffer()[i]);
        if (p_params->isEnable()) {
            p_params->save(out);
        }
    }
    return true;
}

MT_CTSTR rGrassWind::getExt() const {
    return "grw";
}

inline rGrassWind::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrassWind::MyDTI rGrassWind::DTI("rGrassWind", &::cResource::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrassWind::MyDTI::newInstance() const {
    void* t0 = MtMemoryAllocator::getAllocator(rGrassWind::DTI)->memAlloc(sizeof(rGrassWind), 16u, rGrassWind::DTI.getID());
    return new (t0) rGrassWind;
}

const MtDTI& rGrassWind::cParamSet::getDTI() const {
    return rGrassWind::cParamSet::DTI;
}

__attribute__((noinline)) rGrassWind::cParamSet::~cParamSet() {
    if (mpParams != nullptr) {
        MtMemoryAllocator::getAllocator(cParamSet::DTI)->memFree(mpParams);
        mpParams = nullptr;
    }
}

__attribute__((weak)) void rGrassWind::cParamSet::createProperty(MtPropertyList& s) {
    DDON_STUB("rGrassWind::cParamSet::createProperty")
    /* stub */
}

MtUI* rGrassWind::cParamSet::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rGrassWind::cParamSet::save(MtStream& out) {
    u32 name_length = static_cast<u32>(strlen(mName.ptr()));
    out.write(&name_length, sizeof(u32));
    out.write(mName.ptr(), name_length + 1);
    out.write(&mMax, sizeof(f32));
    out.write(&mMin, sizeof(f32));
    out.write(&mParamNum, sizeof(u32));
    if (mParamNum != 0) {
        out.write(mpParams, static_cast<u32>(sizeof(cParams)) * mParamNum);
    }
    return true;
}

__attribute__((weak)) bool rGrassWind::cParamSet::load(MtStream& in) {
    MT_CHAR tmp[256];
    u32 length;
    in.read(&length, sizeof(u32));
    in.read(tmp, length + 1);
    mName = MtString(tmp);
    in.read(&mMax, sizeof(f32));
    in.read(&mMin, sizeof(f32));
    in.read(&mParamNum, sizeof(u32));
    mpParams = static_cast<cParams*>(MtMemoryAllocator::getAllocator(cParamSet::DTI)->memAlloc(sizeof(cParams) * mParamNum, 16u));
    if (mParamNum != 0) {
        in.read(mpParams, static_cast<u32>(sizeof(cParams)) * mParamNum);
    }
    return true;
}

bool rGrassWind::cParamSet::isEnable() const {
    return true;
}

__attribute__((weak)) f32 rGrassWind::cParamSet::getValue(f32 frame) {
    DDON_STUB("rGrassWind::cParamSet::getValue")
    return {};
}

inline rGrassWind::cParamSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrassWind::cParamSet::MyDTI rGrassWind::cParamSet::DTI("rGrassWind::cParamSet", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrassWind::cParamSet::MyDTI::newInstance() const {
    return new (16u) cParamSet(nullptr);
}

rGrassWind::cParamSetSync::cParamSetSync() {
    DDON_STUB("rGrassWind::cParamSetSync::cParamSetSync")
    /* stub */
}

rGrassWind::cParamSetSync::~cParamSetSync() {
}

__attribute__((weak)) void rGrassWind::cParamSetSync::play(f32 dt) {
    DDON_STUB("rGrassWind::cParamSetSync::play")
    /* stub */
}

__attribute__((weak)) void rGrassWind::cParamSetSync::synchronization(cUnit* p_unit, rGrassWind* p_resource) {
    DDON_STUB("rGrassWind::cParamSetSync::synchronization")
    /* stub */
}

inline rGrassWind::rGrassWind() {
    setAttribute(18u);
    mPriority = 127u;
    mMaxFrame = 100u;
    mDTI = uGrassWindDirection::DTI.getID();
    mLoop = false;
    mAutoDeath = false;
}

