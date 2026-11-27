// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundSequenceSe.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundSequenceSe::getDTI() const {
    return rSoundSequenceSe::DTI;
}

__attribute__((noinline)) rSoundSequenceSe::~rSoundSequenceSe() {
    if (mSeqSe.mLength != 0) {
        u32 v0_0 = mSeqSe.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSeqSe.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSeqSe.mpArray[i0_3];
                v1_0 = mSeqSe.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSeqSe.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSeqSe.mpArray));
    }
    mSeqSe.mpArray = nullptr;
    mSeqSe.mBufsiz = 0;
    mSeqSe.mLength = 0;
    if (mpRequest != nullptr) {
        mpRequest->release();
        mpRequest = nullptr;
    }
}

void rSoundSequenceSe::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "SE Resource", "resource", reinterpret_cast<MT_MFUNC>(&::rSoundSequenceSe::getSoundRequest), reinterpret_cast<MT_MFUNC>(&::rSoundSequenceSe::setSoundRequest), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mPauseStatus", &mPauseStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSeqSe", static_cast<MtObject*>(&mSeqSe), 0u, 0u);
    this->cResource::createProperty(s);
}

MtUI* rSoundSequenceSe::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rSoundSequenceSe::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr) {
        rSoundRequest* t0 = mpRequest;
        if (t0 != nullptr) {
            if (t0->isIntermediate()) {
                mpRequest = static_cast<rSoundRequest*>(sResource::getInstance()->createNative(static_cast<cResource*>(t0), 1u));
                t0->release();
            }
        }
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rSoundSequenceSe::getExt() const {
    return "ssqr";
}

rSoundSequenceSe::SequenceSe* rSoundSequenceSe::getSequenceSe(u32 index) {
    if (mSeqSe.mLength != 0) {
        if (index < mSeqSe.mLength) {
            return static_cast<SequenceSe*>(mSeqSe.getBuffer()[static_cast<int>(index)]);
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01ab3660 __attribute__((used)) = &rSoundSequenceSe::getSoundRequest;

void rSoundSequenceSe::setSoundRequest(rSoundRequest* pRes) {
    if (pRes == nullptr) {
        return;
    }
    if (mpRequest != nullptr) {
        mpRequest->release();
        mpRequest = nullptr;
    }
    pRes->addRef();
    mpRequest = pRes;
}

inline rSoundSequenceSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSequenceSe::MyDTI rSoundSequenceSe::DTI("rSoundSequenceSe", &::cResource::DTI, 168ul, 0u, 0u);

MtObject* rSoundSequenceSe::MyDTI::newInstance() const {
    return new (16u) rSoundSequenceSe;
}

const MtDTI& rSoundSequenceSe::SequenceSe::getDTI() const {
    return rSoundSequenceSe::SequenceSe::DTI;
}

rSoundSequenceSe::SequenceSe::~SequenceSe() {
    if (mCommand.mLength != 0) {
        u32 v0_0 = mCommand.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCommand.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCommand.mpArray[i0_3];
                v1_0 = mCommand.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCommand.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCommand.mpArray));
    }
    mCommand.mpArray = nullptr;
    mCommand.mBufsiz = 0;
    mCommand.mLength = 0;
}

void rSoundSequenceSe::SequenceSe::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "RequestNo", &mRequestNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Command", static_cast<MtObject*>(&mCommand), 0u, 0u);
}

MtUI* rSoundSequenceSe::SequenceSe::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

rSoundSequenceSe::SequenceSe::Command* rSoundSequenceSe::SequenceSe::getCommand(u32 index) {
    if (mCommand.mLength != 0) {
        if (index < mCommand.mLength) {
            return static_cast<Command*>(mCommand.getBuffer()[static_cast<int>(index)]);
        }
    }
    return nullptr;
}

inline rSoundSequenceSe::SequenceSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSequenceSe::SequenceSe::MyDTI rSoundSequenceSe::SequenceSe::DTI("rSoundSequenceSe::SequenceSe", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* rSoundSequenceSe::SequenceSe::MyDTI::newInstance() const {
    return new (16u) rSoundSequenceSe::SequenceSe;
}

const MtDTI& rSoundSequenceSe::SequenceSe::Command::getDTI() const {
    return rSoundSequenceSe::SequenceSe::Command::DTI;
}

rSoundSequenceSe::SequenceSe::Command::~Command() {
}

void rSoundSequenceSe::SequenceSe::Command::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCommand", &mCommand, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mValue1", &mValue[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mValue2", &mValue[1], 0u, 0u);
}

MtUI* rSoundSequenceSe::SequenceSe::Command::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rSoundSequenceSe::SequenceSe::Command::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSequenceSe::SequenceSe::Command::MyDTI rSoundSequenceSe::SequenceSe::Command::DTI("rSoundSequenceSe::SequenceSe::Command", &::MtObject::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundSequenceSe::SequenceSe::Command::MyDTI::newInstance() const {
    return new (16u) rSoundSequenceSe::SequenceSe::Command;
}

template MtTypedArray<rSoundSequenceSe::SequenceSe::Command>::~MtTypedArray();

template MtTypedArray<rSoundSequenceSe::SequenceSe>::~MtTypedArray();

