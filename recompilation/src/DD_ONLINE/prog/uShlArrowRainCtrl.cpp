// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlArrowRainCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cpOcdCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nHumanMsg.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlGenerator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamArrowRainCtrl::getDTI() const {
    return cShlParamArrowRainCtrl::DTI;
}

MtDTI& cShlParamArrowRainCtrl::getShlDTI() const {
    return uShlArrowRainCtrl::DTI;
}

void cShlParamArrowRainCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::createProperty(s);
}

void cShlParamArrowRainCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    isOwnerScaleOffset = static_cast<bool>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(pParamBase) + 352));
    generatorOption = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 392);
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

__attribute__((weak)) void cShlParamArrowRainCtrl::addShlList(const cShlParamGenerator* pParam) {
    DDON_STUB("cShlParamArrowRainCtrl::addShlList")
    /* stub */
}

inline cShlParamArrowRainCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamArrowRainCtrl::MyDTI cShlParamArrowRainCtrl::DTI("cShlParamArrowRainCtrl", &::cShlParamGenerator::DTI, 400ul, 0u, 0u);

MtObject* cShlParamArrowRainCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamArrowRainCtrl;
}

const MtDTI& cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::getDTI() const {
    return cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::DTI;
}

void cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::cShootCtrlParam::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "underArrowNum", &underArrowNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "explodeShlNo", &explodeShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "radiusRate", &radiusRate, 0u, 0u);
}

inline cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::MyDTI cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::DTI("cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl", &::cShlParamGenerator::cShootCtrlParam::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::DTI)->memAlloc(sizeof(cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl), 16u, cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::DTI.getID())) cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl;
}

const MtDTI& uShlArrowRainCtrl::getDTI() const {
    return uShlArrowRainCtrl::DTI;
}

uShlArrowRainCtrl::~uShlArrowRainCtrl() {
}

void uShlArrowRainCtrl::setup() {
    this->uShlGenerator::setup();
    uDDOModel* t0 = mpOwner;
    if (t0 == nullptr) {
        return;
    }
    if (t0->isEnable()) {
        if ((t0->mUnitId & 16u) != 0) {
            if (t0->getOcdCtrlPtr()->isOcdActive(12292u)) {
                unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376);
                if (t1 != 0) {
                    if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)) + 255) > 9) {
                        mIsExplosion = false;
                    } else {
                        u32 t2 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)));
                        mIsExplosion = static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t1 + (static_cast<unsigned long>(t2) * 80)) + (static_cast<unsigned long>(nHuman::getCustomSkillIdArrayIndex(nHuman::CUSTOM_SKILL_ID_07)) * 4)) + 2376)) > 0;
                    }
                } else {
                    mIsExplosion = false;
                }
            }
        }
    }
}

__attribute__((weak)) void uShlArrowRainCtrl::initSub() {
}

__attribute__((weak)) void uShlArrowRainCtrl::updateSub() {
    DDON_STUB("uShlArrowRainCtrl::updateSub")
    /* stub */
}

void uShlArrowRainCtrl::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
}

__attribute__((weak)) void uShlArrowRainCtrl::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY) {
    DDON_STUB("uShlArrowRainCtrl::setShl")
    /* stub */
}

inline uShlArrowRainCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlArrowRainCtrl::MyDTI uShlArrowRainCtrl::DTI("uShlArrowRainCtrl", &::uShlGenerator::DTI, 10976ul, 0u, 0u);

MtObject* uShlArrowRainCtrl::MyDTI::newInstance() const {
    return new (16u) uShlArrowRainCtrl;
}

