// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSoundTrigger.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtCollisionDefine.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/cZoneContents.h"
#include "../../XFramework/cZoneLayout.h"
#include "../../XFramework/cZoneListener.h"
#include "../../generated/shared/nSoundZone.h"
#include "../../XFramework/nZone.h"
#include "../../XFramework/rSoundCurveSet.h"
#include "../../XFramework/rSoundDirectionalSet.h"
#include "../../XFramework/rSoundEQ.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSoundReverb.h"
#include "rSoundSequenceSe.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "rSoundSubMixer.h"
#include "../../XFramework/rZone.h"
#include "sPlayerManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sSoundManager.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/sZone.h"
#include "../../XFramework/uCoord.h"
#include "uPlayer.h"
#include "uSoundSequenceSe.h"
#include "uSoundZoneBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* nSoundTrigger::cFreeWorkContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cFreeWorkContents::DTI)->memAlloc(sz, align, ::nSoundTrigger::cFreeWorkContents::DTI.getID());
}
inline nSoundTrigger::cFreeWorkContents::cFreeWorkContents() {
    setContentsName("FreeWork");
    for (u32 i = 0; i < 4; i++) {
        mFreeWorkA[i] = 0;
        mFreeWorkB[i] = 0;
    }
}

inline void* nSoundTrigger::cReverbContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cReverbContents::DTI)->memAlloc(sz, align, ::nSoundTrigger::cReverbContents::DTI.getID());
}
inline nSoundTrigger::cReverbContents::cReverbContents() {
    setContentsName("Reverb");
    mReverbIdA = 0;
    mReverbIdB = 0;
    mEffectNoA = 0;
    mEffectNoB = 0;
    mFadeTimeA = 0;
    mFadeTimeB = 0;
    mpReverbA = nullptr;
    mpReverbB = nullptr;
}

inline void* nSoundTrigger::cStreamContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cStreamContents::DTI)->memAlloc(sz, align, ::nSoundTrigger::cStreamContents::DTI.getID());
}
inline nSoundTrigger::cStreamContents::cStreamContents() {
    setContentsName("Stream");
    mStreamRequestNoA = 0;
    mStreamRequestNoB = 0;
    mpStreamRequestB = nullptr;
    mpStreamRequestA = nullptr;
}

inline void* nSoundTrigger::cSeContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cSeContents::DTI)->memAlloc(sz, align, ::nSoundTrigger::cSeContents::DTI.getID());
}
inline nSoundTrigger::cSeContents::cSeContents() {
    setContentsName("Se");
    mRequestNoA = 0;
    mRequestNoB = 0;
    mpRequestB = nullptr;
    mpRequestA = nullptr;
}

inline void* nSoundTrigger::cBaseContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cBaseContents::DTI)->memAlloc(sz, align, ::nSoundTrigger::cBaseContents::DTI.getID());
}
inline nSoundTrigger::cBaseContents::cBaseContents() {
    setContentsName("Base");
    mFlgUse = true;
    setAttribute(0x4000u, true);
    mOption = 0;
}

const MtDTI& cSoundTriggerLayoutInfo::getDTI() const {
    return cSoundTriggerLayoutInfo::DTI;
}

inline void* cSoundTriggerLayoutInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundTriggerLayoutInfo::DTI)->memAlloc(sz, align, cSoundTriggerLayoutInfo::DTI.getID());
}

inline void cSoundTriggerLayoutInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundTriggerLayoutInfo::DTI)->memFree(p_addr);
}

inline cSoundTriggerLayoutInfo::cSoundTriggerLayoutInfo() {
    mPanelType = 0;
    mpUSequenceSe[1] = nullptr;
    mpUSequenceSe[0] = nullptr;
    mPanelNormal[0].x = MtVector3::Zero.x;
    mPanelNormal[0].y = MtVector3::Zero.y;
    mPanelNormal[0].z = MtVector3::Zero.z;
    mPanelNormal[0].pad_ = 0.0f;
    mPanelNormal[1].x = MtVector3::Zero.x;
    mPanelNormal[1].y = MtVector3::Zero.y;
    mPanelNormal[1].z = MtVector3::Zero.z;
    mPanelNormal[1].pad_ = 0.0f;
    mContentsIndex[10] = -1;
    mContentsIndex[8] = -1;
    mContentsIndex[9] = -1;
    mContentsIndex[6] = -1;
    mContentsIndex[7] = -1;
    mContentsIndex[4] = -1;
    mContentsIndex[5] = -1;
    mContentsIndex[2] = -1;
    mContentsIndex[3] = -1;
    mContentsIndex[0] = -1;
    mContentsIndex[1] = -1;
}

cSoundTriggerLayoutInfo::~cSoundTriggerLayoutInfo() {
    if (mpUSequenceSe[0] != nullptr) {
        mpUSequenceSe[0]->kill();
        mpUSequenceSe[0] = nullptr;
    }
    if (mpUSequenceSe[1] == nullptr) {
        return;
    }
    mpUSequenceSe[1]->kill();
    mpUSequenceSe[1] = nullptr;
}

MtUI* cSoundTriggerLayoutInfo::createUI(MtProperty& prop) {
    return this->cSoundLayoutInfo::createUI(prop);
}

void cSoundTriggerLayoutInfo::createProperty(MtPropertyList& s) {
    this->cSoundLayoutInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpUSequenceSe", reinterpret_cast<MtObject* *>(&mpUSequenceSe[0]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPanelNormal", &mPanelNormal[0], 35u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "mPanelType", &mPanelType, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContentsIndex", &mContentsIndex[0], 33u, 11u);
}

void cSoundTriggerLayoutInfo::setContentsIndex(nZone::cLayoutElement* pLayout) {
    if (pLayout == nullptr) {
        return;
    }
    mContentsIndex[0] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cBaseContents::DTI, 0u));
    mContentsIndex[1] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cSeContents::DTI, 0u));
    mContentsIndex[2] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cStreamContents::DTI, 0u));
    mContentsIndex[3] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cPlaySeqSeContents::DTI, 0u));
    mContentsIndex[4] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cStopSeqSeContents::DTI, 0u));
    mContentsIndex[5] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cCurveSetContents::DTI, 0u));
    mContentsIndex[6] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cDirectionalSetContents::DTI, 0u));
    mContentsIndex[7] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cReverbContents::DTI, 0u));
    mContentsIndex[8] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cEQContents::DTI, 0u));
    mContentsIndex[9] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cSubMixerContents::DTI, 0u));
    mContentsIndex[10] = static_cast<int>(pLayout->getContentsIndex(nSoundTrigger::cFreeWorkContents::DTI, 0u));
}

s32 cSoundTriggerLayoutInfo::getContentsIndex(u32 index) {
    if (index <= 10u) {
        return mContentsIndex[index];
    } else {
        return -1;
    }
}

__attribute__((weak)) void cSoundTriggerLayoutInfo::checkPanelVsLine(const nZone::ShapeInfoPanel& panel, const MtLineSegment& line) {
    DDON_STUB("cSoundTriggerLayoutInfo::checkPanelVsLine")
    /* stub */
}

__attribute__((weak)) void cSoundTriggerLayoutInfo::calcPanelNormal(nZone::ShapeInfoPanel* pShape) {
    DDON_STUB("cSoundTriggerLayoutInfo::calcPanelNormal")
    /* stub */
}

__attribute__((weak)) void cSoundTriggerLayoutInfo::checkSetPanelType(nZone::cLayoutElement* pLayout) {
    DDON_STUB("cSoundTriggerLayoutInfo::checkSetPanelType")
    /* stub */
}

inline cSoundTriggerLayoutInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundTriggerLayoutInfo::MyDTI cSoundTriggerLayoutInfo::DTI("cSoundTriggerLayoutInfo", &::cSoundLayoutInfo::DTI, 128ul, 0u, 0u);

MtObject* cSoundTriggerLayoutInfo::MyDTI::newInstance() const {
    return new (16u) cSoundTriggerLayoutInfo;
}

const MtDTI& cSoundTriggerListener::getDTI() const {
    return cSoundTriggerListener::DTI;
}

inline void* cSoundTriggerListener::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundTriggerListener::DTI)->memAlloc(sz, align, cSoundTriggerListener::DTI.getID());
}

inline void cSoundTriggerListener::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundTriggerListener::DTI)->memFree(p_addr);
}

cSoundTriggerListener::~cSoundTriggerListener() {
}

void cSoundTriggerListener::notified(const nZone::cLayoutElement& e) {
    MtObject* v0_3 = e.getExtendObj();
    if (v0_3 != nullptr) {
        const MtDTI& t0 = e.mpShapeInfo->getDTI();
        MT_CTSTR v0_1 = nZone::ShapeInfoGlobal::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (!static_cast<sSoundExt*>(sSound::getInstance())->mIsGlobalTriggerZoneOut) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16)) | 1;
                }
                return;
            }
        }
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16)) | 1;
        static_cast<sSoundExt*>(sSound::getInstance())->mIsOtherTriggerZoneIn = true;
    }
}

inline cSoundTriggerListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundTriggerListener::MyDTI cSoundTriggerListener::DTI("cSoundTriggerListener", &::cSoundZoneListener::DTI, 64ul, 0u, 0u);

MtObject* cSoundTriggerListener::MyDTI::newInstance() const {
    return new (16u) cSoundTriggerListener;
}

const MtDTI& nSoundTrigger::cBaseContents::getDTI() const {
    return nSoundTrigger::cBaseContents::DTI;
}

inline void nSoundTrigger::cBaseContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cBaseContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cBaseContents::~cBaseContents() {
}

MtUI* nSoundTrigger::cBaseContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cBaseContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "Option", &mOption, 0u, 0u);
}

inline nSoundTrigger::cBaseContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cBaseContents::MyDTI nSoundTrigger::cBaseContents::DTI("nSoundTrigger::cBaseContents", &::nSoundTrigger::cCategory::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cBaseContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundTrigger::cBaseContents;
}

const MtDTI& nSoundTrigger::cCategory::getDTI() const {
    return nSoundTrigger::cCategory::DTI;
}

inline void nSoundTrigger::cCategory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cCategory::DTI)->memFree(p_addr);
}

nSoundTrigger::cCategory::cCategory() {
    setCategoryName("SoundTrigger");
    setExtendObjectDTI(::cSoundTriggerLayoutInfo::DTI);
    setBroadPhaseSearchMode(2u);
    setAttribute(0x10000u, true);
}

nSoundTrigger::cCategory::~cCategory() {
}

MtUI* nSoundTrigger::cCategory::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cCategory::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
}

inline nSoundTrigger::cCategory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cCategory::MyDTI nSoundTrigger::cCategory::DTI("nSoundTrigger::cCategory", &::nSoundZoneBase::cSoundZoneContents::DTI, 32ul, 0u, 1u);

MtObject* nSoundTrigger::cCategory::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& nSoundTrigger::cCurveSetContents::getDTI() const {
    return nSoundTrigger::cCurveSetContents::DTI;
}

inline void nSoundTrigger::cCurveSetContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cCurveSetContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cCurveSetContents::~cCurveSetContents() {
    if (mpCurveSetA != nullptr) {
        mpCurveSetA->release();
        mpCurveSetA = nullptr;
    }
    if (mpCurveSetB == nullptr) {
        return;
    }
    mpCurveSetB->release();
    mpCurveSetB = nullptr;
}

MtUI* nSoundTrigger::cCurveSetContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cCurveSetContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "CurveSet:A", "resource", static_cast<void*>(&mpCurveSetA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223CurveSet AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cCurveSetContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221CurveSet BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cCurveSetContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "CurveSet:B", "resource", static_cast<void*>(&mpCurveSetB), 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cCurveSetContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cCurveSetContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cCurveSetContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cCurveSetContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cCurveSetContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cCurveSetContents::MyDTI nSoundTrigger::cCurveSetContents::DTI("nSoundTrigger::cCurveSetContents", &::nSoundTrigger::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cCurveSetContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cCurveSetContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nSoundTrigger::cDirectionalSetContents::getDTI() const {
    return nSoundTrigger::cDirectionalSetContents::DTI;
}

inline void nSoundTrigger::cDirectionalSetContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cDirectionalSetContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cDirectionalSetContents::~cDirectionalSetContents() {
    if (mpDirectionalSetA != nullptr) {
        mpDirectionalSetA->release();
        mpDirectionalSetA = nullptr;
    }
    if (mpDirectionalSetB == nullptr) {
        return;
    }
    mpDirectionalSetB->release();
    mpDirectionalSetB = nullptr;
}

MtUI* nSoundTrigger::cDirectionalSetContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cDirectionalSetContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "DirectionalSet:A", "resource", static_cast<void*>(&mpDirectionalSetA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223DirectionalSet AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cDirectionalSetContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221DirectionalSet BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cDirectionalSetContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "DirectionalSet:B", "resource", static_cast<void*>(&mpDirectionalSetB), 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cDirectionalSetContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cDirectionalSetContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cDirectionalSetContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cDirectionalSetContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cDirectionalSetContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cDirectionalSetContents::MyDTI nSoundTrigger::cDirectionalSetContents::DTI("nSoundTrigger::cDirectionalSetContents", &::nSoundTrigger::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cDirectionalSetContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cDirectionalSetContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nSoundTrigger::cEQContents::getDTI() const {
    return nSoundTrigger::cEQContents::DTI;
}

inline void nSoundTrigger::cEQContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cEQContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cEQContents::~cEQContents() {
    if (mpEQA != nullptr) {
        mpEQA->release();
        mpEQA = nullptr;
    }
    if (mpEQB == nullptr) {
        return;
    }
    mpEQB->release();
    mpEQB = nullptr;
}

MtUI* nSoundTrigger::cEQContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cEQContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "EQ:A", "resource", static_cast<void*>(&mpEQA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "EQID:A", &mEQIdA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FadeTime:A", &mFadeTimeA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223EQ AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cEQContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221EQ BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cEQContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "EQ:B", "resource", static_cast<void*>(&mpEQB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "EQID:B", &mEQIdB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FadeTime:B", &mFadeTimeB, 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cEQContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cEQContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cEQContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cEQContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cEQContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cEQContents::MyDTI nSoundTrigger::cEQContents::DTI("nSoundTrigger::cEQContents", &::nSoundTrigger::cCategory::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cEQContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cEQContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nSoundTrigger::cFreeWorkContents::getDTI() const {
    return nSoundTrigger::cFreeWorkContents::DTI;
}

inline void nSoundTrigger::cFreeWorkContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cFreeWorkContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cFreeWorkContents::~cFreeWorkContents() {
}

MtUI* nSoundTrigger::cFreeWorkContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cFreeWorkContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkA0", &mFreeWorkA[0], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkA1", &mFreeWorkA[1], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkA2", &mFreeWorkA[2], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkA3", &mFreeWorkA[3], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork \342\206\223AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cFreeWorkContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork \342\206\221BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cFreeWorkContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkB0", &mFreeWorkB[0], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkB1", &mFreeWorkB[1], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkB2", &mFreeWorkB[2], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWorkB3", &mFreeWorkB[3], 0u, 0u);
}

void nSoundTrigger::cFreeWorkContents::copyAToB() {
    mFreeWorkB[0] = mFreeWorkA[0];
    mFreeWorkB[1] = mFreeWorkA[1];
    mFreeWorkB[2] = mFreeWorkA[2];
    mFreeWorkB[3] = mFreeWorkA[3];
}

void nSoundTrigger::cFreeWorkContents::copyBToA() {
    mFreeWorkA[0] = mFreeWorkB[0];
    mFreeWorkA[1] = mFreeWorkB[1];
    mFreeWorkA[2] = mFreeWorkB[2];
    mFreeWorkA[3] = mFreeWorkB[3];
}

inline nSoundTrigger::cFreeWorkContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cFreeWorkContents::MyDTI nSoundTrigger::cFreeWorkContents::DTI("nSoundTrigger::cFreeWorkContents", &::nSoundTrigger::cCategory::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cFreeWorkContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundTrigger::cFreeWorkContents;
}

const MtDTI& nSoundTrigger::cPlaySeqSeContents::getDTI() const {
    return nSoundTrigger::cPlaySeqSeContents::DTI;
}

inline void nSoundTrigger::cPlaySeqSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cPlaySeqSeContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cPlaySeqSeContents::~cPlaySeqSeContents() {
    if (mpSequenceSeA != nullptr) {
        mpSequenceSeA->release();
        mpSequenceSeA = nullptr;
    }
    if (mpSequenceSeB == nullptr) {
        return;
    }
    mpSequenceSeB->release();
    mpSequenceSeB = nullptr;
}

MtUI* nSoundTrigger::cPlaySeqSeContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cPlaySeqSeContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "SequenceSe:A", "resource", static_cast<void*>(&mpSequenceSeA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223SequenceSe AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cPlaySeqSeContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221SequenceSe BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cPlaySeqSeContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SequenceSe:B", "resource", static_cast<void*>(&mpSequenceSeB), 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cPlaySeqSeContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cPlaySeqSeContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cPlaySeqSeContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cPlaySeqSeContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cPlaySeqSeContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cPlaySeqSeContents::MyDTI nSoundTrigger::cPlaySeqSeContents::DTI("nSoundTrigger::cPlaySeqSeContents", &::nSoundTrigger::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cPlaySeqSeContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cPlaySeqSeContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nSoundTrigger::cReverbContents::getDTI() const {
    return nSoundTrigger::cReverbContents::DTI;
}

inline void nSoundTrigger::cReverbContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cReverbContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cReverbContents::~cReverbContents() {
    if (mpReverbA != nullptr) {
        mpReverbA->release();
        mpReverbA = nullptr;
    }
    if (mpReverbB == nullptr) {
        return;
    }
    mpReverbB->release();
    mpReverbB = nullptr;
}

MtUI* nSoundTrigger::cReverbContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cReverbContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "Reverb:A", "resource", static_cast<void*>(&mpReverbA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "ReverbID:A", &mReverbIdA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "EffectNo:A", &mEffectNoA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FadeTime:A", &mFadeTimeA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223Reverb AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cReverbContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221Reverb BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cReverbContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Reverb:B", "resource", static_cast<void*>(&mpReverbB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "ReverbID:B", &mReverbIdB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "EffectNo:B", &mEffectNoB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FadeTime:B", &mFadeTimeB, 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cReverbContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cReverbContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cReverbContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cReverbContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cReverbContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cReverbContents::MyDTI nSoundTrigger::cReverbContents::DTI("nSoundTrigger::cReverbContents", &::nSoundTrigger::cCategory::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cReverbContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundTrigger::cReverbContents;
}

const MtDTI& nSoundTrigger::cSeContents::getDTI() const {
    return nSoundTrigger::cSeContents::DTI;
}

inline void nSoundTrigger::cSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cSeContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cSeContents::~cSeContents() {
    if (mpRequestA != nullptr) {
        mpRequestA->release();
        mpRequestA = nullptr;
    }
    if (mpRequestB == nullptr) {
        return;
    }
    mpRequestB->release();
    mpRequestB = nullptr;
}

MtUI* nSoundTrigger::cSeContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cSeContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequest:A", "resource", static_cast<void*>(&mpRequestA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequestNo:A", &mRequestNoA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223Se AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cSeContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221Se BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cSeContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequest:B", "resource", static_cast<void*>(&mpRequestB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequestNo:B", &mRequestNoB, 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cSeContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cSeContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cSeContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cSeContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cSeContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cSeContents::MyDTI nSoundTrigger::cSeContents::DTI("nSoundTrigger::cSeContents", &::nSoundTrigger::cCategory::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cSeContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundTrigger::cSeContents;
}

const MtDTI& nSoundTrigger::cStopSeqSeContents::getDTI() const {
    return nSoundTrigger::cStopSeqSeContents::DTI;
}

inline void nSoundTrigger::cStopSeqSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cStopSeqSeContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cStopSeqSeContents::~cStopSeqSeContents() {
}

MtUI* nSoundTrigger::cStopSeqSeContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cStopSeqSeContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "StopGroupID:A", &mStopGroupId[0][0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223StopGroupID AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cStopSeqSeContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221StopGroupID BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cStopSeqSeContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "StopGroupID:B", &mStopGroupId[1][0], 32u, 4u);
}

void nSoundTrigger::cStopSeqSeContents::copyAToB() {
    mStopGroupId[1][0] = mStopGroupId[0][0];
    mStopGroupId[1][1] = mStopGroupId[0][1];
    mStopGroupId[1][2] = mStopGroupId[0][2];
    mStopGroupId[1][3] = mStopGroupId[0][3];
}

void nSoundTrigger::cStopSeqSeContents::copyBToA() {
    mStopGroupId[0][0] = mStopGroupId[1][0];
    mStopGroupId[0][1] = mStopGroupId[1][1];
    mStopGroupId[0][2] = mStopGroupId[1][2];
    mStopGroupId[0][3] = mStopGroupId[1][3];
}

inline nSoundTrigger::cStopSeqSeContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cStopSeqSeContents::MyDTI nSoundTrigger::cStopSeqSeContents::DTI("nSoundTrigger::cStopSeqSeContents", &::nSoundTrigger::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cStopSeqSeContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cStopSeqSeContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nSoundTrigger::cStreamContents::getDTI() const {
    return nSoundTrigger::cStreamContents::DTI;
}

inline void nSoundTrigger::cStreamContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cStreamContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cStreamContents::~cStreamContents() {
    if (mpStreamRequestA != nullptr) {
        mpStreamRequestA->release();
        mpStreamRequestA = nullptr;
    }
    if (mpStreamRequestB == nullptr) {
        return;
    }
    mpStreamRequestB->release();
    mpStreamRequestB = nullptr;
}

MtUI* nSoundTrigger::cStreamContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cStreamContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequest:A", "resource", static_cast<void*>(&mpStreamRequestA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequestNo:A", &mStreamRequestNoA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223Stream AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cStreamContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221Stream BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cStreamContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequest:B", "resource", static_cast<void*>(&mpStreamRequestB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequestNo:B", &mStreamRequestNoB, 0u, 0u);
}

__attribute__((weak)) void nSoundTrigger::cStreamContents::copyAToB() {
    DDON_STUB("nSoundTrigger::cStreamContents::copyAToB")
    /* stub */
}

__attribute__((weak)) void nSoundTrigger::cStreamContents::copyBToA() {
    DDON_STUB("nSoundTrigger::cStreamContents::copyBToA")
    /* stub */
}

inline nSoundTrigger::cStreamContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cStreamContents::MyDTI nSoundTrigger::cStreamContents::DTI("nSoundTrigger::cStreamContents", &::nSoundTrigger::cCategory::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cStreamContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundTrigger::cStreamContents;
}

const MtDTI& nSoundTrigger::cSubMixerContents::getDTI() const {
    return nSoundTrigger::cSubMixerContents::DTI;
}

inline void nSoundTrigger::cSubMixerContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundTrigger::cSubMixerContents::DTI)->memFree(p_addr);
}

nSoundTrigger::cSubMixerContents::~cSubMixerContents() {
    if (mpSubMixerA != nullptr) {
        mpSubMixerA->release();
        mpSubMixerA = nullptr;
    }
    if (mpSubMixerB == nullptr) {
        return;
    }
    mpSubMixerB->release();
    mpSubMixerB = nullptr;
}

MtUI* nSoundTrigger::cSubMixerContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundTrigger::cSubMixerContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "SubMixer:A", "resource", static_cast<void*>(&mpSubMixerA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SubMixerID:A", &mSubMixerIdA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\223SubMixer AtoB\342\206\223", static_cast<MT_MFUNC>(&::nSoundTrigger::cSubMixerContents::copyAToB), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "\342\206\221SubMixer BtoA\342\206\221", static_cast<MT_MFUNC>(&::nSoundTrigger::cSubMixerContents::copyBToA), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SubMixer:B", "resource", static_cast<void*>(&mpSubMixerB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SubMixerID:B", &mSubMixerIdB, 0u, 0u);
}

void nSoundTrigger::cSubMixerContents::copyAToB() {
    mSubMixerIdB = mSubMixerIdA;
    mpSubMixerB = mpSubMixerA;
}

void nSoundTrigger::cSubMixerContents::copyBToA() {
    mSubMixerIdA = mSubMixerIdB;
    mpSubMixerA = mpSubMixerB;
}

inline nSoundTrigger::cSubMixerContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundTrigger::cSubMixerContents::MyDTI nSoundTrigger::cSubMixerContents::DTI("nSoundTrigger::cSubMixerContents", &::nSoundTrigger::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundTrigger::cSubMixerContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundTrigger::cSubMixerContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundTrigger::getDTI() const {
    return uSoundTrigger::DTI;
}

inline MtAllocator* uSoundTrigger::getAllocator() {
    return MtMemoryAllocator::getAllocator(uSoundTrigger::DTI);
}

void* uSoundTrigger::operator new(size_t sz, u32 align) {
    return uSoundTrigger::getAllocator()->memAlloc(sz, align, uSoundTrigger::DTI.getID());
}

inline void uSoundTrigger::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundTrigger::DTI)->memFree(p_addr);
}

uSoundTrigger::uSoundTrigger() {
    DDON_STUB("uSoundTrigger::uSoundTrigger")
    /* stub */
}

__attribute__((noinline)) uSoundTrigger::~uSoundTrigger() {
    DDON_STUB("uSoundTrigger::~uSoundTrigger")
    /* stub */
}

MtUI* uSoundTrigger::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::createUI(prop);
}

void uSoundTrigger::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mZoneListener", static_cast<MtObject*>(&mZoneListener), 0u, 0u);
}

void uSoundTrigger::setup() {
    this->uSoundZoneBase::setup();
    initPanel();
}

__attribute__((weak)) void uSoundTrigger::move() {
    DDON_STUB("uSoundTrigger::move")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::sync() {
    DDON_STUB("uSoundTrigger::sync")
    /* stub */
}

void uSoundTrigger::setupFromResource(rZone* pRes) {
    this->uSoundZoneBase::setupFromResource(pRes);
}

void uSoundTrigger::setupFromResource(rZone* pRes, const MtVector3& pos) {
    this->uSoundZoneBase::setupFromResource(pRes, pos);
}

const MtDTI* uSoundTrigger::getGroupManagerDTI() const {
    return &uSoundTrigger::cTriggerGroupManager::DTI;
}

cSoundZoneListener* uSoundTrigger::getZoneListener() {
    return &mZoneListener;
}

MtVector3 uSoundTrigger::getZoneListenerPos() {
    return (&mZoneListener)->myPos();
}

void uSoundTrigger::setZoneListenerPos(const MtVector3& NewListenerPos) {
    (&mZoneListener)->setMyPos(NewListenerPos);
}

void uSoundTrigger::clearZoneHit() {
    this->uSoundZoneBase::clearZoneHit();
    cZoneLayout* t0 = getZoneLayout();
    if (t0 != nullptr) {
        const u32 GroupManagerNum = t0->getGroupManagerNum();
        if (GroupManagerNum != 0) {
            if (getZoneLayout() != nullptr) {
                for (unsigned int i0_3 = 0;;) {
                    cZoneLayout* t1 = getZoneLayout();
                    if (t1 != nullptr) {
                        cZoneLayout::cInGameGroupManager* t2 = t1->getGroupManagerFromIndex(static_cast<s32>(i0_3));
                        if (t2 != nullptr) {
                            if (t2->isEnable()) {
                                static_cast<uSoundTrigger::cTriggerGroupManager*>(t2)->mHitCount = 0;
                            }
                        }
                    }
                    if (GroupManagerNum != (i0_3 + 1u)) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void uSoundTrigger::triggerMainInOut() {
    DDON_STUB("uSoundTrigger::triggerMainInOut")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::triggerMainThrough() {
    DDON_STUB("uSoundTrigger::triggerMainThrough")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::checkHitPanel() {
    DDON_STUB("uSoundTrigger::checkHitPanel")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::initPanel() {
    cZoneLayout* pZone = getZoneLayout();
    if (pZone != nullptr) {
        const u32 layoutNum = pZone->getLayoutElementNum();
        if (layoutNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                nZone::cLayoutElement* t0 = pZone->getLayoutElement(i0_3);
                if (t0 != nullptr) {
                    nZone::ShapeInfoBase* t2 = t0->mpShapeInfo;
                    if (t2 != nullptr) {
                        if (t2->getShapeType() == nZone::ShapeInfoBase::SHAPE_TYPE_PANEL) {
                            MtObject* t3 = t0->getExtendObj();
                            if (t3 != nullptr) {
                                static_cast<cSoundTriggerLayoutInfo*>(t3)->calcPanelNormal(static_cast<nZone::ShapeInfoPanel*>(t2));
                                static_cast<cSoundTriggerLayoutInfo*>(t3)->checkSetPanelType(t0);
                            }
                        }
                    }
                }
                if (layoutNum != (i0_3 + 1u)) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) void uSoundTrigger::successIn(nZone::cLayoutElement& ListenerInLayout) {
    DDON_STUB("uSoundTrigger::successIn")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::successOut(nZone::cLayoutElement& ListenerOutLayout) {
    DDON_STUB("uSoundTrigger::successOut")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::stopSequenceSeFlow(nSoundTrigger::cStopSeqSeContents& contents, nSoundTrigger::ARRAY_TYPE ArrayType) {
    DDON_STUB("uSoundTrigger::stopSequenceSeFlow")
    /* stub */
}

__attribute__((weak)) void uSoundTrigger::requestStream(rSoundStreamRequest* pRequest, u32 reqNo, s32 free0, s32 free1, s32 free2) {
    DDON_STUB("uSoundTrigger::requestStream")
    /* stub */
}

inline uSoundTrigger::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundTrigger::MyDTI uSoundTrigger::DTI("uSoundTrigger", &::uSoundZoneBase::DTI, 352ul, 0u, 0u);

__attribute__((weak)) MtObject* uSoundTrigger::MyDTI::newInstance() const {
    DDON_STUB("uSoundTrigger::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundTrigger::cTriggerGroupManager::getDTI() const {
    return uSoundTrigger::cTriggerGroupManager::DTI;
}

inline void* uSoundTrigger::cTriggerGroupManager::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundTrigger::cTriggerGroupManager::DTI)->memAlloc(sz, align, uSoundTrigger::cTriggerGroupManager::DTI.getID());
}

inline void uSoundTrigger::cTriggerGroupManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundTrigger::cTriggerGroupManager::DTI)->memFree(p_addr);
}

uSoundTrigger::cTriggerGroupManager::~cTriggerGroupManager() {
}

MtUI* uSoundTrigger::cTriggerGroupManager::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::cGroupManager::createUI(prop);
}

void uSoundTrigger::cTriggerGroupManager::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::cGroupManager::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mHitCount", &mHitCount, 1u, 0u);
}

inline uSoundTrigger::cTriggerGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundTrigger::cTriggerGroupManager::MyDTI uSoundTrigger::cTriggerGroupManager::DTI("uSoundTrigger::cTriggerGroupManager", &::uSoundZoneBase::cGroupManager::DTI, 64ul, 0u, 0u);

MtObject* uSoundTrigger::cTriggerGroupManager::MyDTI::newInstance() const {
    return new (16u) uSoundTrigger::cTriggerGroupManager;
}

