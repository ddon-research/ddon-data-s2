// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlGenerator.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cpLockOn.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "sSetManager.h"
#include "sShlManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamGenerator::getDTI() const {
    return cShlParamGenerator::DTI;
}

inline void* cShlParamGenerator::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamGenerator::DTI)->memAlloc(sz, align, cShlParamGenerator::DTI.getID());
}

inline void cShlParamGenerator::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamGenerator::DTI)->memFree(p_addr);
}

MtDTI& cShlParamGenerator::getShlDTI() const {
    return uShlGenerator::DTI;
}

void cShlParamGenerator::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "isOwnerScaleOffset", &isOwnerScaleOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "generatorOption", &generatorOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlList", static_cast<MtObject*>(&shlList), 0u, 0u);
}

void cShlParamGenerator::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
}

__attribute__((noinline)) cShlParamGenerator::~cShlParamGenerator() {
    for (u32 i = 0; i < shlList.mLength; i++) {
        delete shlList.mpArray[i];
    }
    if (shlList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(shlList.mpArray));
    }
    shlList.mpArray = nullptr;
    shlList.mBufsiz = 0;
    shlList.mLength = 0;
}

void cShlParamGenerator::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamGenerator* pParam = static_cast<const cShlParamGenerator*>(pParamBase);
    isOwnerScaleOffset = pParam->isOwnerScaleOffset;
    generatorOption = pParam->generatorOption;
    if (shlList.mLength != 0) {
        u32 v0_0 = shlList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (shlList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete shlList.mpArray[i0_3];
                v1_0 = shlList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (shlList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(shlList.mpArray));
    }
    shlList.mpArray = nullptr;
    shlList.mBufsiz = 0;
    shlList.mLength = 0;
    addShlList(static_cast<const cShlParamGenerator*>(pParamBase));
}

__attribute__((weak)) void cShlParamGenerator::addShlList(const cShlParamGenerator* pParam) {
    DDON_STUB("cShlParamGenerator::addShlList")
    /* stub */
}

inline cShlParamGenerator::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGenerator::MyDTI cShlParamGenerator::DTI("cShlParamGenerator", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamGenerator::MyDTI::newInstance() const {
    return new (16u) cShlParamGenerator;
}

const MtDTI& cShlParamGenerator::cShootCtrlParam::getDTI() const {
    return cShlParamGenerator::cShootCtrlParam::DTI;
}

inline MtAllocator* cShlParamGenerator::cShootCtrlParam::getAllocator() {
    return MtMemoryAllocator::getAllocator(cShlParamGenerator::cShootCtrlParam::DTI);
}

void* cShlParamGenerator::cShootCtrlParam::operator new(size_t sz, u32 align) {
    return cShlParamGenerator::cShootCtrlParam::getAllocator()->memAlloc(sz, align, cShlParamGenerator::cShootCtrlParam::DTI.getID());
}

__attribute__((weak)) void cShlParamGenerator::cShootCtrlParam::operator delete(void* p_addr) {
    cShlParamGenerator::cShootCtrlParam::getAllocator()->memFree(p_addr);
}

void cShlParamGenerator::cShootCtrlParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "waitFrame", &waitFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offset", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offsetRnd", &offsetRnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degX", &degX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degY", &degY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degRndX", &degRndX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degRndY", &degRndY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "joint", &joint, 0u, 0u);
}

inline cShlParamGenerator::cShootCtrlParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGenerator::cShootCtrlParam::MyDTI cShlParamGenerator::cShootCtrlParam::DTI("cShlParamGenerator::cShootCtrlParam", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* cShlParamGenerator::cShootCtrlParam::MyDTI::newInstance() const {
    return new (16u) cShlParamGenerator::cShootCtrlParam;
}

const MtDTI& uShlGenerator::getDTI() const {
    return uShlGenerator::DTI;
}

inline void* uShlGenerator::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlGenerator::DTI)->memAlloc(sz, align, uShlGenerator::DTI.getID());
}

inline void uShlGenerator::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlGenerator::DTI)->memFree(p_addr);
}

uShlGenerator::uShlGenerator() {
    mInitDir.x = 0.0f;
    mInitDir.y = 0.0f;
    mIsLockon = false;
    mShlSetLimit = 0;
    mShlSetNum = 0;
    mShlSetFrame = 0.0f;
    mInitDir.z = 1.0f;
    mInitDir.pad_ = 0.0f;
}

uShlGenerator::~uShlGenerator() {
}

__attribute__((weak)) void uShlGenerator::setup() {
    DDON_STUB("uShlGenerator::setup")
    /* stub */
}

__attribute__((weak)) void uShlGenerator::initSub() {
    DDON_STUB("uShlGenerator::initSub")
    /* stub */
}

__attribute__((weak)) void uShlGenerator::updateSub() {
    DDON_STUB("uShlGenerator::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlGenerator::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY) {
    DDON_STUB("uShlGenerator::setShl")
    /* stub */
}

inline uShlGenerator::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlGenerator::MyDTI uShlGenerator::DTI("uShlGenerator", &::uShlBase::DTI, 10960ul, 0u, 0u);

MtObject* uShlGenerator::MyDTI::newInstance() const {
    return new (16u) uShlGenerator;
}

