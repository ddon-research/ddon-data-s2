// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCameraParamList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/rCameraList.h"
#include "sArchiveManager.h"
#include "uCameraGame.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCameraParamList::getDTI() const {
    return rCameraParamList::DTI;
}

inline void* rCameraParamList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rCameraParamList::DTI)->memAlloc(sz, align, rCameraParamList::DTI.getID());
}

inline void rCameraParamList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rCameraParamList::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rCameraParamList::~rCameraParamList() {
    mParamList.deleteAll(true);
    if (mprCameraList != nullptr) {
        mprCameraList->release();
        mprCameraList = nullptr;
    }
}

void rCameraParamList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mParamList", static_cast<MtObject*>(&mParamList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraListPath", &mCameraListPath, 0u, 0u);
}

__attribute__((weak)) void rCameraParamList::clear() {
}

__attribute__((weak)) bool rCameraParamList::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, DATA_VERSION, this, MtSerializer::MODE_STATE) == nullptr) {
        return false;
    }
    if (mprCameraList != nullptr) {
        mprCameraList->release();
        mprCameraList = nullptr;
    }
    mprCameraList = static_cast<rCameraList*>(sArchiveManager::getInstance()->createRes(rCameraList::DTI, mCameraListPath.ptr(), sArchiveManager::ARC_LOAD_MODE_ONCE, false));
    for (u32 i = 0; i < mParamList.mLength; i++) {
        cCamExParam* pParam = static_cast<cCamExParam*>(mParamList.mpArray[i]);
        if (pParam != nullptr) {
            pParam->mprCameraParamList = this;
            pParam->mCameraParamListIndex = i;
        }
    }
    return true;
}

bool rCameraParamList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(6), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rCameraParamList::DTI));
}

MT_CTSTR rCameraParamList::getExt() const {
    return "cpl";
}

const cCamExParam* rCameraParamList::getParam(u32 index) const {
    if (index < mParamList.mLength) {
        return static_cast<const cCamExParam*>(mParamList.mpArray[index]);
    } else {
        return nullptr;
    }
}

void rCameraParamList::addPriority(u32 add) {
    u32 v0_0 = mParamList.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mParamList.mpArray;
        for (u32 i = 0;;) {
            if (v0_1[i] != nullptr) {
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i]) + 28) = add + (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i]) + 28));
            }
            if ((i + 1u) < v0_0) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
}

inline rCameraParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCameraParamList::MyDTI rCameraParamList::DTI("rCameraParamList", &::cResource::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* rCameraParamList::MyDTI::newInstance() const {
    return new(16u) rCameraParamList();
}

