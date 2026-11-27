// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlGeneErosionTentacle.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cpErosionEnemy.h"
#include "cpShlShotCtrl.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamGeneErosionTentacle::getDTI() const {
    return cShlParamGeneErosionTentacle::DTI;
}

MtDTI& cShlParamGeneErosionTentacle::getShlDTI() const {
    return uShlGeneErosionTentacle::DTI;
}

__attribute__((noinline)) cShlParamGeneErosionTentacle::~cShlParamGeneErosionTentacle() {
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

void cShlParamGeneErosionTentacle::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitTime", &mWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartWaitTime", &mStartWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlList", static_cast<MtObject*>(&shlList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgReqTentacleNoticeSe", &mFlgReqTentacleNoticeSe, 0u, 0u);
}

void cShlParamGeneErosionTentacle::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
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
    addShlList(static_cast<const cShlParamGeneErosionTentacle*>(pParamBase));
    const cShlParamGeneErosionTentacle* pParam = static_cast<const cShlParamGeneErosionTentacle*>(pParamBase);
    mWaitTime = pParam->mWaitTime;
    mStartWaitTime = pParam->mStartWaitTime;
    mFlgReqTentacleNoticeSe = static_cast<bool>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(pParamBase) + 392));
}

__attribute__((weak)) void cShlParamGeneErosionTentacle::addShlList(const cShlParamGeneErosionTentacle* pParam) {
    DDON_STUB("cShlParamGeneErosionTentacle::addShlList")
    /* stub */
}

inline cShlParamGeneErosionTentacle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGeneErosionTentacle::MyDTI cShlParamGeneErosionTentacle::DTI("cShlParamGeneErosionTentacle", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamGeneErosionTentacle::MyDTI::newInstance() const {
    return new (16u) cShlParamGeneErosionTentacle;
}

const MtDTI& cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::getDTI() const {
    return cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::DTI;
}

void cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlPawnNoticeNo", &shlPawnNoticeNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\263\343\202\242\343\203\235\343\202\244\343\203\263\343\203\210\343\202\277\343\202\244\343\203\227", &coretype, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "constJointNo", &constJointNo, 0u, 0u);
}

inline cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::MyDTI cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::DTI("cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::MyDTI::newInstance() const {
    return new (16u) cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle;
}

const MtDTI& uShlGeneErosionTentacle::getDTI() const {
    return uShlGeneErosionTentacle::DTI;
}

uShlGeneErosionTentacle::~uShlGeneErosionTentacle() {
}

void uShlGeneErosionTentacle::setup() {
    this->uShlBase::setup();
}

__attribute__((weak)) void uShlGeneErosionTentacle::initSub() {
    DDON_STUB("uShlGeneErosionTentacle::initSub")
    /* stub */
}

__attribute__((weak)) void uShlGeneErosionTentacle::updateSub() {
    DDON_STUB("uShlGeneErosionTentacle::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlGeneErosionTentacle::setShlOrg(u32 shlNo, s32 jointNo) {
    DDON_STUB("uShlGeneErosionTentacle::setShlOrg")
    /* stub */
}

inline uShlGeneErosionTentacle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlGeneErosionTentacle::MyDTI uShlGeneErosionTentacle::DTI("uShlGeneErosionTentacle", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlGeneErosionTentacle::MyDTI::newInstance() const {
    return new (16u) uShlGeneErosionTentacle;
}

