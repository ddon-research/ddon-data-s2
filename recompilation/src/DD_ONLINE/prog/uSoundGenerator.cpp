// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSoundGenerator.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/cZoneContents.h"
#include "../../XFramework/cZoneLayout.h"
#include "../../XFramework/cZoneListener.h"
#include "../../generated/shared/nSoundZone.h"
#include "../../XFramework/nZone.h"
#include "../../XFramework/rSoundRequest.h"
#include "rSoundSequenceSe.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "../../XFramework/rZone.h"
#include "sGame.h"
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

inline void* nSoundGenerator::cFreeWorkContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cFreeWorkContents::DTI)->memAlloc(sz, align, ::nSoundGenerator::cFreeWorkContents::DTI.getID());
}
inline nSoundGenerator::cFreeWorkContents::cFreeWorkContents() {
    setContentsName("FreeWork");
    for (u32 i = 0; i < 4; i++) {
        mFreeWork[i] = 0;
    }
}

inline void* nSoundGenerator::cSeqSeContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeqSeContents::DTI)->memAlloc(sz, align, ::nSoundGenerator::cSeqSeContents::DTI.getID());
}
inline nSoundGenerator::cSeqSeContents::cSeqSeContents() {
    setContentsName("SequenceSe");
    mpSequenceSe = nullptr;
}

inline void* nSoundGenerator::cStreamContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cStreamContents::DTI)->memAlloc(sz, align, ::nSoundGenerator::cStreamContents::DTI.getID());
}
inline nSoundGenerator::cStreamContents::cStreamContents() {
    setContentsName("Stream");
    mStreamRequestNo = 0;
    mpStreamRequest = nullptr;
}

inline void* nSoundGenerator::cSeContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeContents::DTI)->memAlloc(sz, align, ::nSoundGenerator::cSeContents::DTI.getID());
}
inline nSoundGenerator::cSeContents::cSeContents() {
    setContentsName("Se");
    mRequestNo = 0;
    mpRequest = nullptr;
}

inline void* nSoundGenerator::cBaseContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cBaseContents::DTI)->memAlloc(sz, align, ::nSoundGenerator::cBaseContents::DTI.getID());
}
inline nSoundGenerator::cBaseContents::cBaseContents() {
    setContentsName("Base");
    mFlgUse = true;
    setAttribute(0x4000u, true);
    mStopDist = 0.0f;
}

const MtDTI& cSoundGeneratorLayoutInfo::getDTI() const {
    return cSoundGeneratorLayoutInfo::DTI;
}

inline void* cSoundGeneratorLayoutInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundGeneratorLayoutInfo::DTI)->memAlloc(sz, align, cSoundGeneratorLayoutInfo::DTI.getID());
}

inline void cSoundGeneratorLayoutInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundGeneratorLayoutInfo::DTI)->memFree(p_addr);
}

cSoundGeneratorLayoutInfo::~cSoundGeneratorLayoutInfo() {
}

MtUI* cSoundGeneratorLayoutInfo::createUI(MtProperty& prop) {
    return this->cSoundLayoutInfo::createUI(prop);
}

void cSoundGeneratorLayoutInfo::createProperty(MtPropertyList& s) {
    this->cSoundLayoutInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mContentsIndex", &mContentsIndex[0], 32u, 5u);
}

void cSoundGeneratorLayoutInfo::setContentsIndex(nZone::cLayoutElement* pLayout) {
    if (pLayout == nullptr) {
        return;
    }
    mContentsIndex[0] = static_cast<int>(pLayout->getContentsIndex(nSoundGenerator::cBaseContents::DTI, 0u));
    mContentsIndex[1] = static_cast<int>(pLayout->getContentsIndex(nSoundGenerator::cSeContents::DTI, 0u));
    mContentsIndex[2] = static_cast<int>(pLayout->getContentsIndex(nSoundGenerator::cStreamContents::DTI, 0u));
    mContentsIndex[3] = static_cast<int>(pLayout->getContentsIndex(nSoundGenerator::cSeqSeContents::DTI, 0u));
    mContentsIndex[4] = static_cast<int>(pLayout->getContentsIndex(nSoundGenerator::cFreeWorkContents::DTI, 0u));
}

s32 cSoundGeneratorLayoutInfo::getContentsIndex(u32 index) {
    if (index <= 4u) {
        return mContentsIndex[index];
    } else {
        return -1;
    }
}

inline cSoundGeneratorLayoutInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundGeneratorLayoutInfo::MyDTI cSoundGeneratorLayoutInfo::DTI("cSoundGeneratorLayoutInfo", &::cSoundLayoutInfo::DTI, 40ul, 0u, 0u);

MtObject* cSoundGeneratorLayoutInfo::MyDTI::newInstance() const {
    return new (16u) cSoundGeneratorLayoutInfo;
}

const MtDTI& cSoundGeneratorListener::getDTI() const {
    return cSoundGeneratorListener::DTI;
}

inline void* cSoundGeneratorListener::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundGeneratorListener::DTI)->memAlloc(sz, align, cSoundGeneratorListener::DTI.getID());
}

inline void cSoundGeneratorListener::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundGeneratorListener::DTI)->memFree(p_addr);
}

cSoundGeneratorListener::~cSoundGeneratorListener() {
}

void cSoundGeneratorListener::notified(const nZone::cLayoutElement& e) {
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
                if (!static_cast<sSoundExt*>(sSound::getInstance())->mIsGlobalGeneratorZoneOut) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16)) | 1;
                }
                return;
            }
        }
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3) + 16)) | 1;
        static_cast<sSoundExt*>(sSound::getInstance())->mIsOtherGeneratorZoneIn = true;
    }
}

inline cSoundGeneratorListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundGeneratorListener::MyDTI cSoundGeneratorListener::DTI("cSoundGeneratorListener", &::cSoundZoneListener::DTI, 64ul, 0u, 0u);

MtObject* cSoundGeneratorListener::MyDTI::newInstance() const {
    return new (16u) cSoundGeneratorListener;
}

const MtDTI& nSoundGenerator::cBaseContents::getDTI() const {
    return nSoundGenerator::cBaseContents::DTI;
}

inline void nSoundGenerator::cBaseContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cBaseContents::DTI)->memFree(p_addr);
}

nSoundGenerator::cBaseContents::~cBaseContents() {
}

MtUI* nSoundGenerator::cBaseContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cBaseContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    createPropertyForUI(s);
}

void nSoundGenerator::cBaseContents::createPropertyForUI(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "StopDist", &mStopDist, 0u, 0u);
}

inline nSoundGenerator::cBaseContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cBaseContents::MyDTI nSoundGenerator::cBaseContents::DTI("nSoundGenerator::cBaseContents", &::nSoundGenerator::cCategory::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundGenerator::cBaseContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundGenerator::cBaseContents;
}

const MtDTI& nSoundGenerator::cCategory::getDTI() const {
    return nSoundGenerator::cCategory::DTI;
}

inline void nSoundGenerator::cCategory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cCategory::DTI)->memFree(p_addr);
}

inline nSoundGenerator::cCategory::cCategory() {
    setCategoryName("SoundGenerator");
    setExtendObjectDTI(::cSoundGeneratorLayoutInfo::DTI);
    setBroadPhaseSearchMode(2u);
    setAttribute(0x10000u, true);
}

nSoundGenerator::cCategory::~cCategory() {
}

MtUI* nSoundGenerator::cCategory::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cCategory::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
}

inline nSoundGenerator::cCategory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cCategory::MyDTI nSoundGenerator::cCategory::DTI("nSoundGenerator::cCategory", &::nSoundZoneBase::cSoundZoneContents::DTI, 32ul, 0u, 1u);

MtObject* nSoundGenerator::cCategory::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& nSoundGenerator::cFreeWorkContents::getDTI() const {
    return nSoundGenerator::cFreeWorkContents::DTI;
}

inline void nSoundGenerator::cFreeWorkContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cFreeWorkContents::DTI)->memFree(p_addr);
}

nSoundGenerator::cFreeWorkContents::~cFreeWorkContents() {
}

MtUI* nSoundGenerator::cFreeWorkContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cFreeWorkContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    createPropertyForUI(s);
}

void nSoundGenerator::cFreeWorkContents::createPropertyForUI(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork0", &mFreeWork[0], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork1", &mFreeWork[1], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork2", &mFreeWork[2], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork3", &mFreeWork[3], 0u, 0u);
}

inline nSoundGenerator::cFreeWorkContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cFreeWorkContents::MyDTI nSoundGenerator::cFreeWorkContents::DTI("nSoundGenerator::cFreeWorkContents", &::nSoundGenerator::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundGenerator::cFreeWorkContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundGenerator::cFreeWorkContents;
}

const MtDTI& nSoundGenerator::cSeContents::getDTI() const {
    return nSoundGenerator::cSeContents::DTI;
}

inline void nSoundGenerator::cSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeContents::DTI)->memFree(p_addr);
}

nSoundGenerator::cSeContents::~cSeContents() {
    if (mpRequest == nullptr) {
        return;
    }
    mpRequest->release();
    mpRequest = nullptr;
}

MtUI* nSoundGenerator::cSeContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cSeContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    createPropertyForUI(s);
}

void nSoundGenerator::cSeContents::createPropertyForUI(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequest", "resource", static_cast<void*>(&mpRequest), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SeRequestNo", &mRequestNo, 0u, 0u);
}

inline nSoundGenerator::cSeContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cSeContents::MyDTI nSoundGenerator::cSeContents::DTI("nSoundGenerator::cSeContents", &::nSoundGenerator::cCategory::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundGenerator::cSeContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundGenerator::cSeContents;
}

const MtDTI& nSoundGenerator::cSeqSeContents::getDTI() const {
    return nSoundGenerator::cSeqSeContents::DTI;
}

inline void nSoundGenerator::cSeqSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeqSeContents::DTI)->memFree(p_addr);
}

nSoundGenerator::cSeqSeContents::~cSeqSeContents() {
    if (mpSequenceSe == nullptr) {
        return;
    }
    mpSequenceSe->release();
    mpSequenceSe = nullptr;
}

MtUI* nSoundGenerator::cSeqSeContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cSeqSeContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    createPropertyForUI(s);
}

void nSoundGenerator::cSeqSeContents::createPropertyForUI(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "SequenceSe", "resource", static_cast<void*>(&mpSequenceSe), 0u, 0u);
}

inline nSoundGenerator::cSeqSeContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cSeqSeContents::MyDTI nSoundGenerator::cSeqSeContents::DTI("nSoundGenerator::cSeqSeContents", &::nSoundGenerator::cCategory::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundGenerator::cSeqSeContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundGenerator::cSeqSeContents;
}

const MtDTI& nSoundGenerator::cStreamContents::getDTI() const {
    return nSoundGenerator::cStreamContents::DTI;
}

inline void nSoundGenerator::cStreamContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cStreamContents::DTI)->memFree(p_addr);
}

nSoundGenerator::cStreamContents::~cStreamContents() {
    if (mpStreamRequest == nullptr) {
        return;
    }
    mpStreamRequest->release();
    mpStreamRequest = nullptr;
}

MtUI* nSoundGenerator::cStreamContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundGenerator::cStreamContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    createPropertyForUI(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mStreamRequestNo", &mStreamRequestNo, 3u, 0u);
}

void nSoundGenerator::cStreamContents::createPropertyForUI(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequest", "resource", static_cast<void*>(&mpStreamRequest), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "StreamRequestNo", &mStreamRequestNo, 0u, 0u);
}

inline nSoundGenerator::cStreamContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundGenerator::cStreamContents::MyDTI nSoundGenerator::cStreamContents::DTI("nSoundGenerator::cStreamContents", &::nSoundGenerator::cCategory::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundGenerator::cStreamContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundGenerator::cStreamContents;
}

const MtDTI& uSoundGenerator::getDTI() const {
    return uSoundGenerator::DTI;
}

inline MtAllocator* uSoundGenerator::getAllocator() {
    return MtMemoryAllocator::getAllocator(uSoundGenerator::DTI);
}

void* uSoundGenerator::operator new(size_t sz, u32 align) {
    return uSoundGenerator::getAllocator()->memAlloc(sz, align, uSoundGenerator::DTI.getID());
}

inline void uSoundGenerator::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundGenerator::DTI)->memFree(p_addr);
}

uSoundGenerator::uSoundGenerator() {
    DDON_STUB("uSoundGenerator::uSoundGenerator")
    /* stub */
}

uSoundGenerator::~uSoundGenerator() {
    sZone::getInstance()->removeListener(static_cast<cZoneListener*>(&mZoneListener));
}

MtUI* uSoundGenerator::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::createUI(prop);
}

void uSoundGenerator::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mZoneListener", static_cast<MtObject*>(&mZoneListener), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionMoveLine", &mOcclusionMoveLine, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "StopAll", static_cast<MT_MFUNC>(&::uSoundGenerator::allStopNowRequest), 10u);
}

__attribute__((weak)) void uSoundGenerator::move() {
    DDON_STUB("uSoundGenerator::move")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::sync() {
    DDON_STUB("uSoundGenerator::sync")
    /* stub */
}

const MtDTI* uSoundGenerator::getGroupManagerDTI() const {
    return &uSoundGenerator::cGeneratorGroupManager::DTI;
}

cSoundZoneListener* uSoundGenerator::getZoneListener() {
    return &mZoneListener;
}

MtVector3 uSoundGenerator::getZoneListenerPos() {
    return (&mZoneListener)->myPos();
}

void uSoundGenerator::setZoneListenerPos(const MtVector3& NewListenerPos) {
    (&mZoneListener)->setMyPos(NewListenerPos);
}

__attribute__((weak)) void uSoundGenerator::allStopNowRequest() {
    DDON_STUB("uSoundGenerator::allStopNowRequest")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::generateMain() {
    DDON_STUB("uSoundGenerator::generateMain")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::allStopNowRequestCommon(uSoundGenerator::cGeneratorGroupManager& TargetGroupManager, u32 PlayLayoutUniqueID) {
    DDON_STUB("uSoundGenerator::allStopNowRequestCommon")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::generate(cZoneLayout& MyZoneLayout, uSoundGenerator::cGeneratorGroupManager& TargetGroupManager, nZone::cLayoutElement& TargetLayoutElement, const MtVector3& pos) {
    DDON_STUB("uSoundGenerator::generate")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::playSequenceSe(nZone::cLayoutElement* pLayout, nSoundGenerator::cSeqSeContents* pContents, const MtVector3& pos) {
    DDON_STUB("uSoundGenerator::playSequenceSe")
    /* stub */
}

__attribute__((weak)) s32 uSoundGenerator::checkInLayout(uSoundGenerator::cGeneratorGroupManager* pGroupManager) {
    DDON_STUB("uSoundGenerator::checkInLayout")
    return {};
}

__attribute__((weak)) void uSoundGenerator::checkLayoutPosDist(uSoundGenerator::cGeneratorGroupManager* pGroupManager, const MtVector3& listenerPos, nZone::cLayoutElement* * ppLayout, MtVector3* pPos) {
    DDON_STUB("uSoundGenerator::checkLayoutPosDist")
    /* stub */
}

__attribute__((weak)) void uSoundGenerator::calcLayoutPosDistMain(const nZone::cLayoutElement& TargetLayout, const MtVector3& pos, MtVector3& NearPos, f32& Dist) {
    DDON_STUB("uSoundGenerator::calcLayoutPosDistMain")
    /* stub */
}

inline uSoundGenerator::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundGenerator::MyDTI uSoundGenerator::DTI("uSoundGenerator", &::uSoundZoneBase::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* uSoundGenerator::MyDTI::newInstance() const {
    DDON_STUB("uSoundGenerator::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundGenerator::cGeneratorGroupManager::getDTI() const {
    return uSoundGenerator::cGeneratorGroupManager::DTI;
}

inline void* uSoundGenerator::cGeneratorGroupManager::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundGenerator::cGeneratorGroupManager::DTI)->memAlloc(sz, align, uSoundGenerator::cGeneratorGroupManager::DTI.getID());
}

inline void uSoundGenerator::cGeneratorGroupManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundGenerator::cGeneratorGroupManager::DTI)->memFree(p_addr);
}

uSoundGenerator::cGeneratorGroupManager::~cGeneratorGroupManager() {
    DDON_STUB("uSoundGenerator::cGeneratorGroupManager::~cGeneratorGroupManager")
    /* stub */
}

MtUI* uSoundGenerator::cGeneratorGroupManager::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::cGroupManager::createUI(prop);
}

void uSoundGenerator::cGeneratorGroupManager::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::cGroupManager::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "PlayInfomation", reinterpret_cast<MT_MFUNC>(&::uSoundGenerator::cGeneratorGroupManager::getPlayInfomation), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::uSoundGenerator::cGeneratorGroupManager::getPlayInfomationNum), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) uSoundSequenceSe* uSoundGenerator::cGeneratorGroupManager::makeSequenceSeUnit(nZone::cLayoutElement& NowLayout) {
    DDON_STUB("uSoundGenerator::cGeneratorGroupManager::makeSequenceSeUnit")
    return nullptr;
}

__attribute__((weak)) void uSoundGenerator::cGeneratorGroupManager::evRegisterResource() {
    DDON_STUB("uSoundGenerator::cGeneratorGroupManager::evRegisterResource")
    /* stub */
}

uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation* uSoundGenerator::cGeneratorGroupManager::getPlayInfomation(u32 index) {
    if (mpPlayInfomation != nullptr) {
        if (mpResourceGroupManager->mGroupID == -1) {
            if (index < mpResourceGroupManager->getGroupLayoutIndexNum()) {
                return &mpPlayInfomation[index];
            }
        } else {
            if (index <= 0u) {
                return &mpPlayInfomation[index];
            }
        }
    }
    return nullptr;
}

u32 uSoundGenerator::cGeneratorGroupManager::getPlayInfomationNum() const {
    if (mpResourceGroupManager->mGroupID != -1) {
        return 1;
    } else {
        return mpResourceGroupManager->getGroupLayoutIndexNum();
    }
}

inline uSoundGenerator::cGeneratorGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundGenerator::cGeneratorGroupManager::MyDTI uSoundGenerator::cGeneratorGroupManager::DTI("uSoundGenerator::cGeneratorGroupManager", &::uSoundZoneBase::cGroupManager::DTI, 64ul, 0u, 0u);

MtObject* uSoundGenerator::cGeneratorGroupManager::MyDTI::newInstance() const {
    return new (16u) uSoundGenerator::cGeneratorGroupManager;
}

const MtDTI& uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::getDTI() const {
    return uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI;
}

inline void* uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI)->memAlloc(sz, align, uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI.getID());
}

inline void uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI)->memFree(p_addr);
}

inline uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::cSoundPlayInfomation() {
    mRequestPos = MtVector3::Zero;
    mLayoutUniqueId = -1;
    mpUSequenceSe = nullptr;
}

uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::~cSoundPlayInfomation() {
    if (mpUSequenceSe == nullptr) {
        return;
    }
    if ((mpUSequenceSe->mBeFlag - 3u) > 1u) {
        mpUSequenceSe->kill();
    }
}

MtUI* uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpUSequenceSe", reinterpret_cast<MtObject* *>(&mpUSequenceSe), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLayoutUniqueId", &mLayoutUniqueId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestPos", &mRequestPos, 1u, 0u);
}

inline uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::MyDTI uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI("uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::MyDTI::newInstance() const {
    return new (16u) uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation;
}

