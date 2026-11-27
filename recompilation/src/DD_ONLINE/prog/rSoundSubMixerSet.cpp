// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundSubMixerSet.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#include "rSoundSubMixer.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundSubMixerSet::getDTI() const {
    return rSoundSubMixerSet::DTI;
}

rSoundSubMixerSet::~rSoundSubMixerSet() {
}

bool rSoundSubMixerSet::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr) {
        mSubMixerLists.mAutoDelete = true;
        return true;
    } else {
        return false;
    }
}

bool rSoundSubMixerSet::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rSoundSubMixerSet::DTI));
}

MT_CTSTR rSoundSubMixerSet::getExt() const {
    return "sms";
}

void rSoundSubMixerSet::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSubMixerLists", static_cast<MtObject*>(&mSubMixerLists), 0u, 0u);
}

rSoundSubMixerSet::BasicSubMixers* rSoundSubMixerSet::getBasicSubMixers(u32 index) const {
    if (mSubMixerLists.mLength >= index) {
        return static_cast<BasicSubMixers*>(mSubMixerLists.mpArray[index]);
    } else {
        return nullptr;
    }
}

void rSoundSubMixerSet::clear() {
    if (mSubMixerLists.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSubMixerLists.mpArray));
    }
    mSubMixerLists.mpArray = nullptr;
    mSubMixerLists.mLength = 0;
    mSubMixerLists.mBufsiz = 0;
}

inline rSoundSubMixerSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSubMixerSet::MyDTI rSoundSubMixerSet::DTI("rSoundSubMixerSet", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rSoundSubMixerSet::MyDTI::newInstance() const {
    return new (16u) rSoundSubMixerSet;
}

const MtDTI& rSoundSubMixerSet::BasicSubMixers::getDTI() const {
    return rSoundSubMixerSet::BasicSubMixers::DTI;
}

rSoundSubMixerSet::BasicSubMixers::~BasicSubMixers() {
    if (mpResource0 != nullptr) {
        mpResource0->release();
        mpResource0 = nullptr;
    }
    if (mpResource1 != nullptr) {
        mpResource1->release();
        mpResource1 = nullptr;
    }
    if (mpResource2 != nullptr) {
        mpResource2->release();
        mpResource2 = nullptr;
    }
    if (mpResource3 != nullptr) {
        mpResource3->release();
        mpResource3 = nullptr;
    }
    if (mpResource4 != nullptr) {
        mpResource4->release();
        mpResource4 = nullptr;
    }
    if (mpResource5 != nullptr) {
        mpResource5->release();
        mpResource5 = nullptr;
    }
    if (mpResource6 != nullptr) {
        mpResource6->release();
        mpResource6 = nullptr;
    }
    if (mpResource7 != nullptr) {
        mpResource7->release();
        mpResource7 = nullptr;
    }
}

MtUI* rSoundSubMixerSet::BasicSubMixers::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void rSoundSubMixerSet::BasicSubMixers::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResource0", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource0), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource0), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource1", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource1), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource1), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource2", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource2), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource2), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource3", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource3), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource3), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource4", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource4), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource4), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource5", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource5), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource5), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource6", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource6), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource6), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource7", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::getResource7), reinterpret_cast<MT_MFUNC>(&::rSoundSubMixerSet::BasicSubMixers::setResource7), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource0() const {
    return mpResource0;
}

void rSoundSubMixerSet::BasicSubMixers::setResource0(rSoundSubMixer* res) {
    if (res == mpResource0) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource0 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource0 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource1() const {
    return mpResource1;
}

void rSoundSubMixerSet::BasicSubMixers::setResource1(rSoundSubMixer* res) {
    if (res == mpResource1) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource1 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource1 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource2() const {
    return mpResource2;
}

void rSoundSubMixerSet::BasicSubMixers::setResource2(rSoundSubMixer* res) {
    if (res == mpResource2) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource2 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource2 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource3() const {
    return mpResource3;
}

void rSoundSubMixerSet::BasicSubMixers::setResource3(rSoundSubMixer* res) {
    if (res == mpResource3) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource3 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource3 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource4() const {
    return mpResource4;
}

void rSoundSubMixerSet::BasicSubMixers::setResource4(rSoundSubMixer* res) {
    if (res == mpResource4) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource4 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource4 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource5() const {
    return mpResource5;
}

void rSoundSubMixerSet::BasicSubMixers::setResource5(rSoundSubMixer* res) {
    if (res == mpResource5) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource5 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource5 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource6() const {
    return mpResource6;
}

void rSoundSubMixerSet::BasicSubMixers::setResource6(rSoundSubMixer* res) {
    if (res == mpResource6) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource6 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource6 = res;
        res->addRef();
    }
}

rSoundSubMixer* rSoundSubMixerSet::BasicSubMixers::getResource7() const {
    return mpResource7;
}

void rSoundSubMixerSet::BasicSubMixers::setResource7(rSoundSubMixer* res) {
    if (res == mpResource7) {
        return;
    }
    if (res == nullptr) {
        return;
    }
    if (res->isIntermediate()) {
        mpResource7 = static_cast<rSoundSubMixer*>(sResource::getInstance()->createNative(static_cast<cResource*>(res), 1u));
    } else {
        mpResource7 = res;
        res->addRef();
    }
}

inline rSoundSubMixerSet::BasicSubMixers::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSubMixerSet::BasicSubMixers::MyDTI rSoundSubMixerSet::BasicSubMixers::DTI("rSoundSubMixerSet::BasicSubMixers", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* rSoundSubMixerSet::BasicSubMixers::MyDTI::newInstance() const {
    return new (16u) rSoundSubMixerSet::BasicSubMixers;
}

