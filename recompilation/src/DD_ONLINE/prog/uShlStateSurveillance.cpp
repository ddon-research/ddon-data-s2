// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlStateSurveillance.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamStateSurveillance::getDTI() const {
    return cShlParamStateSurveillance::DTI;
}

inline void cShlParamStateSurveillance::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamStateSurveillance::DTI)->memFree(p_addr);
}

MtDTI& cShlParamStateSurveillance::getShlDTI() const {
    return uShlStateSurveillance::DTI;
}

__attribute__((noinline)) cShlParamStateSurveillance::~cShlParamStateSurveillance() {
    for (u32 i = 0; i < mArrayInfo.mLength; i++) {
        delete mArrayInfo.mpArray[i];
    }
    if (mArrayInfo.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mArrayInfo.mpArray));
    }
    mArrayInfo.mpArray = nullptr;
    mArrayInfo.mBufsiz = 0;
    mArrayInfo.mLength = 0;
}

void cShlParamStateSurveillance::createProperty(MtPropertyList& s) {
    this->cShlParamStick::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mArrayInfo", static_cast<MtObject*>(&mArrayInfo), 0u, 0u);
}

void cShlParamStateSurveillance::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    stickOption = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 352);
    if (mArrayInfo.mLength != 0) {
        u32 v0_0 = mArrayInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArrayInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArrayInfo.mpArray[i0_3];
                v1_0 = mArrayInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArrayInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArrayInfo.mpArray));
    }
    mArrayInfo.mpArray = nullptr;
    mArrayInfo.mBufsiz = 0;
    mArrayInfo.mLength = 0;
    addShlList(static_cast<const cShlParamStateSurveillance*>(pParamBase));
}

__attribute__((weak)) void cShlParamStateSurveillance::addShlList(const cShlParamStateSurveillance* pParam) {
    DDON_STUB("cShlParamStateSurveillance::addShlList")
    /* stub */
}

inline cShlParamStateSurveillance::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamStateSurveillance::MyDTI cShlParamStateSurveillance::DTI("cShlParamStateSurveillance", &::cShlParamStick::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamStateSurveillance::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamStateSurveillance::DTI)->memAlloc(sizeof(cShlParamStateSurveillance), 16u, cShlParamStateSurveillance::DTI.getID())) cShlParamStateSurveillance;
}

const MtDTI& uShlStateSurveillance::getDTI() const {
    return uShlStateSurveillance::DTI;
}

inline void uShlStateSurveillance::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlStateSurveillance::DTI)->memFree(p_addr);
}

inline const cShlParamStateSurveillance* uShlStateSurveillance::getShlParam() const {
    return static_cast<const cShlParamStateSurveillance*>(mpShlParam2);
}

uShlStateSurveillance::~uShlStateSurveillance() {
    if (mCheckArray.mLength != 0) {
        u32 v0_0 = mCheckArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCheckArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCheckArray.mpArray[i0_3];
                v1_0 = mCheckArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCheckArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCheckArray.mpArray));
    }
    mCheckArray.mpArray = nullptr;
    mCheckArray.mBufsiz = 0;
    mCheckArray.mLength = 0;
}

__attribute__((weak)) void uShlStateSurveillance::setup() {
    DDON_STUB("uShlStateSurveillance::setup")
    /* stub */
}

__attribute__((weak)) void uShlStateSurveillance::updateSub() {
    DDON_STUB("uShlStateSurveillance::updateSub")
    /* stub */
}

inline uShlStateSurveillance::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlStateSurveillance::MyDTI uShlStateSurveillance::DTI("uShlStateSurveillance", &::uShlStick::DTI, 10976ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlStateSurveillance::MyDTI::newInstance() const {
    DDON_STUB("uShlStateSurveillance::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uShlStateSurveillance::cStateSurveillanceInfo::getDTI() const {
    return uShlStateSurveillance::cStateSurveillanceInfo::DTI;
}

inline void* uShlStateSurveillance::cStateSurveillanceInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlStateSurveillance::cStateSurveillanceInfo::DTI)->memAlloc(sz, align, uShlStateSurveillance::cStateSurveillanceInfo::DTI.getID());
}

inline void uShlStateSurveillance::cStateSurveillanceInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlStateSurveillance::cStateSurveillanceInfo::DTI)->memFree(p_addr);
}

void uShlStateSurveillance::cStateSurveillanceInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCheckType", &mCheckType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckObjStatus", &mCheckObjStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResultCallSeNo", &mResultCallSeNo, 0u, 0u);
}

inline uShlStateSurveillance::cStateSurveillanceInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlStateSurveillance::cStateSurveillanceInfo::MyDTI uShlStateSurveillance::cStateSurveillanceInfo::DTI("uShlStateSurveillance::cStateSurveillanceInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* uShlStateSurveillance::cStateSurveillanceInfo::MyDTI::newInstance() const {
    return new (16u) uShlStateSurveillance::cStateSurveillanceInfo;
}

template MtTypedArray<uShlStateSurveillance::cStateSurveillanceInfo>::~MtTypedArray();

