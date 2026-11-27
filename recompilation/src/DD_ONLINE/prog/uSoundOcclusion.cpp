// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSoundOcclusion.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtCollisionDefine.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cZoneContents.h"
#include "../../XFramework/cZoneLayout.h"
#include "../../XFramework/cZoneListener.h"
#include "../../generated/shared/nSoundZone.h"
#include "../../XFramework/nZone.h"
#include "../../XFramework/rZone.h"
#include "../../XFramework/sZone.h"
#include "uSoundZoneBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cSoundOcclusionLayoutInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cSoundOcclusionLayoutInfo::DTI)->memAlloc(sz, align, ::cSoundOcclusionLayoutInfo::DTI.getID());
}
inline cSoundOcclusionLayoutInfo::cSoundOcclusionLayoutInfo() {
    mUseType = 0;
    mBoundingBoxIndex = 0;
    mHollowManagerIndex = -1;
    mContentsIndex[0] = -1;
    mContentsIndex[1] = -1;
}

inline void* nSoundOcclusion::cBaseContents::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nSoundOcclusion::cBaseContents::DTI)->memAlloc(sz, align, ::nSoundOcclusion::cBaseContents::DTI.getID());
}
inline nSoundOcclusion::cBaseContents::cBaseContents() {
    setContentsName("Base");
    mFlgUse = true;
    setAttribute(0x4000u, true);
    mOption = static_cast<nSoundOcclusion::OPTION>(0);
    mHollowId = -1;
    mHollowPriority = 0;
    mVolumeRate = 1.0f;
    for (u32 i = 0; i < 4; i++) {
        mSurroundDist[i] = 0.0f;
    }
}

inline nSoundOcclusion::cCategory::cCategory() {
    setCategoryName("SoundOcclusion");
    setExtendObjectDTI(::cSoundOcclusionLayoutInfo::DTI);
    setAttribute(0x1200u);
    setDefaultShapeType(9u);
    setBroadPhaseSearchMode(0u);
    setAttribute(0x10000u, true);
}

const MtDTI& cSoundOcclusionLayoutInfo::getDTI() const {
    return cSoundOcclusionLayoutInfo::DTI;
}

cSoundOcclusionLayoutInfo::~cSoundOcclusionLayoutInfo() {
}

MtUI* cSoundOcclusionLayoutInfo::createUI(MtProperty& prop) {
    return this->cSoundLayoutInfo::createUI(prop);
}

void cSoundOcclusionLayoutInfo::createProperty(MtPropertyList& s) {
    this->cSoundLayoutInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUseType", &mUseType, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBoundingBoxIndex", &mBoundingBoxIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHollowManagerIndex", &mHollowManagerIndex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContentsIndex", &mContentsIndex[0], 33u, 2u);
}

void cSoundOcclusionLayoutInfo::setContentsIndex(nZone::cLayoutElement* pLayout) {
    if (pLayout == nullptr) {
        return;
    }
    mContentsIndex[0] = static_cast<int>(pLayout->getContentsIndex(nSoundOcclusion::cBaseContents::DTI, 0u));
    mContentsIndex[1] = static_cast<int>(pLayout->getContentsIndex(nSoundOcclusion::cFreeWorkContents::DTI, 0u));
}

s32 cSoundOcclusionLayoutInfo::getContentsIndex(u32 index) {
    if (index <= 1u) {
        return mContentsIndex[index];
    } else {
        return -1;
    }
}

inline cSoundOcclusionLayoutInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundOcclusionLayoutInfo::MyDTI cSoundOcclusionLayoutInfo::DTI("cSoundOcclusionLayoutInfo", &::cSoundLayoutInfo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cSoundOcclusionLayoutInfo::MyDTI::newInstance() const {
    return new (16u) ::cSoundOcclusionLayoutInfo;
}

const MtDTI& cSoundOcclusionListener::getDTI() const {
    return cSoundOcclusionListener::DTI;
}

cSoundOcclusionListener::~cSoundOcclusionListener() {
}

__attribute__((weak)) void cSoundOcclusionListener::notified(const nZone::cLayoutElement& e) {
}

inline cSoundOcclusionListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundOcclusionListener::MyDTI cSoundOcclusionListener::DTI("cSoundOcclusionListener", &::cSoundZoneListener::DTI, 64ul, 0u, 0u);

MtObject* cSoundOcclusionListener::MyDTI::newInstance() const {
    return new (16u) cSoundOcclusionListener;
}

const MtDTI& nSoundOcclusion::cBaseContents::getDTI() const {
    return nSoundOcclusion::cBaseContents::DTI;
}

nSoundOcclusion::cBaseContents::~cBaseContents() {
}

MtUI* nSoundOcclusion::cBaseContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundOcclusion::cBaseContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "HollowID", &mHollowId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "HollowPriority", &mHollowPriority, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Option", reinterpret_cast<u32*>(&mOption), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Line [0 - 1]", &mSurroundDist[0], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Line [0 - 3]", &mSurroundDist[1], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Line [1 - 2]", &mSurroundDist[2], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Line [2 - 3]", &mSurroundDist[3], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "VolumeRate", &mVolumeRate, 0u, 0u);
}

inline nSoundOcclusion::cBaseContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundOcclusion::cBaseContents::MyDTI nSoundOcclusion::cBaseContents::DTI("nSoundOcclusion::cBaseContents", &::nSoundOcclusion::cCategory::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundOcclusion::cBaseContents::MyDTI::newInstance() const {
    return new (16u) ::nSoundOcclusion::cBaseContents;
}

const MtDTI& nSoundOcclusion::cCategory::getDTI() const {
    return nSoundOcclusion::cCategory::DTI;
}

nSoundOcclusion::cCategory::~cCategory() {
}

MtUI* nSoundOcclusion::cCategory::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundOcclusion::cCategory::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
}

inline nSoundOcclusion::cCategory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundOcclusion::cCategory::MyDTI nSoundOcclusion::cCategory::DTI("nSoundOcclusion::cCategory", &::nSoundZoneBase::cSoundZoneContents::DTI, 32ul, 0u, 1u);

MtObject* nSoundOcclusion::cCategory::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& nSoundOcclusion::cFreeWorkContents::getDTI() const {
    return nSoundOcclusion::cFreeWorkContents::DTI;
}

nSoundOcclusion::cFreeWorkContents::~cFreeWorkContents() {
}

MtUI* nSoundOcclusion::cFreeWorkContents::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nSoundOcclusion::cFreeWorkContents::createProperty(MtPropertyList& s) {
    this->::cZoneContents::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork0", &mFreeWork[0], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork1", &mFreeWork[1], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork2", &mFreeWork[2], 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "FreeWork3", &mFreeWork[3], 0u, 0u);
}

inline nSoundOcclusion::cFreeWorkContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nSoundOcclusion::cFreeWorkContents::MyDTI nSoundOcclusion::cFreeWorkContents::DTI("nSoundOcclusion::cFreeWorkContents", &::nSoundOcclusion::cCategory::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nSoundOcclusion::cFreeWorkContents::MyDTI::newInstance() const {
    DDON_STUB("nSoundOcclusion::cFreeWorkContents::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundOcclusion::getDTI() const {
    return uSoundOcclusion::DTI;
}

void* uSoundOcclusion::operator new(size_t sz, u32 align) {
    return uSoundOcclusion::getAllocator()->memAlloc(sz, align, uSoundOcclusion::DTI.getID());
}

uSoundOcclusion::uSoundOcclusion() {
    DDON_STUB("uSoundOcclusion::uSoundOcclusion")
    /* stub */
}

__attribute__((noinline)) uSoundOcclusion::~uSoundOcclusion() {
    DDON_STUB("uSoundOcclusion::~uSoundOcclusion")
    /* stub */
}

MtUI* uSoundOcclusion::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::createUI(prop);
}

void uSoundOcclusion::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mZoneListener", static_cast<MtObject*>(&mZoneListener), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseZoneSystemSpaceDivision", &mIsUseZoneSystemSpaceDivision, 0u, 0u);
    if (mpHollowManager == nullptr) {
        return;
    }
    s << MtProperty(static_cast<MtObject*>(this), "mpHollowManager", static_cast<MtObject*>(mpHollowManager), 36u, mHollowManagerNum);
}

void uSoundOcclusion::setup() {
    this->uSoundZoneBase::setup();
}

__attribute__((weak)) void uSoundOcclusion::move() {
    DDON_STUB("uSoundOcclusion::move")
    /* stub */
}

__attribute__((weak)) void uSoundOcclusion::draw(cDraw* pDraw) {
}

const MtDTI* uSoundOcclusion::getGroupManagerDTI() const {
    return &uSoundOcclusion::cOcclusionGroupManager::DTI;
}

cSoundZoneListener* uSoundOcclusion::getZoneListener() {
    return &mZoneListener;
}

MtVector3 uSoundOcclusion::getZoneListenerPos() {
    return (&mZoneListener)->myPos();
}

void uSoundOcclusion::setZoneListenerPos(const MtVector3& NewListenerPos) {
    (&mZoneListener)->setMyPos(NewListenerPos);
}

void uSoundOcclusion::setupFromResource(rZone* pRes) {
    this->uSoundZoneBase::setupFromResource(pRes);
    setUseTypeAll();
    mBoundingBox.createAllBoundingBox(getZoneLayout());
    createHollowManager(pRes);
    setMaxVolumeRateToHollowManagerAll(pRes);
}

void uSoundOcclusion::setupFromResource(rZone* pRes, const MtVector3& pos) {
    this->uSoundZoneBase::setupFromResource(pRes, pos);
    setUseTypeAll();
    mBoundingBox.createAllBoundingBox(getZoneLayout());
    createHollowManager(pRes);
    setMaxVolumeRateToHollowManagerAll(pRes);
}

__attribute__((weak)) f32 uSoundOcclusion::calcOcclusionVolumeRate(const MtVector3& listenerPos, const MtVector3& requestPos) {
    DDON_STUB("uSoundOcclusion::calcOcclusionVolumeRate")
    return {};
}

__attribute__((weak)) void uSoundOcclusion::errorCheckZoneLayout(cZoneLayout* pZone) {
}

__attribute__((weak)) f32 uSoundOcclusion::calcOcclusionVolumeRateSub(const MtLineSegment& line, uSoundOcclusion::cBoundingBox::BoundingWork* boundingArray, const u32 arrayNum, bool* pIsHit) {
    DDON_STUB("uSoundOcclusion::calcOcclusionVolumeRateSub")
    return {};
}

__attribute__((weak)) f32 uSoundOcclusion::occlusionSurrounding(nZone::ShapeInfoPanel* pPanel, nSoundOcclusion::cBaseContents* pContents, const uSoundOcclusion::HIT_PANEL_INFO& hitInfo) {
    DDON_STUB("uSoundOcclusion::occlusionSurrounding")
    return {};
}

__attribute__((weak)) u32 uSoundOcclusion::checkHitHollow(cZoneLayout* pZone, nZone::cLayoutElement* pHitLayout, cSoundOcclusionLayoutInfo* pHitLayoutInfo, nSoundOcclusion::cBaseContents* pHitContents, const MtLineSegment& line, uSoundOcclusion::HIT_PANEL_INFO* pHitInfo) {
    DDON_STUB("uSoundOcclusion::checkHitHollow")
    return {};
}

__attribute__((weak)) bool uSoundOcclusion::isHitPanelVsLine(const nZone::ShapeInfoPanel& Panel, const MtLineSegment& line, uSoundOcclusion::HIT_PANEL_INFO* pHitInfo) const {
    DDON_STUB("uSoundOcclusion::isHitPanelVsLine")
    return {};
}

__attribute__((weak)) bool uSoundOcclusion::followMatrixOcc() {
    DDON_STUB("uSoundOcclusion::followMatrixOcc")
    return {};
}

__attribute__((weak)) void uSoundOcclusion::createHollowManager(rZone* pRZone) {
    DDON_STUB("uSoundOcclusion::createHollowManager")
    /* stub */
}

__attribute__((weak)) void uSoundOcclusion::setMaxVolumeRateToHollowManagerAll(rZone* pRZone) {
    DDON_STUB("uSoundOcclusion::setMaxVolumeRateToHollowManagerAll")
    /* stub */
}

__attribute__((weak)) void uSoundOcclusion::setUseTypeAll() {
    DDON_STUB("uSoundOcclusion::setUseTypeAll")
    /* stub */
}

inline uSoundOcclusion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundOcclusion::MyDTI uSoundOcclusion::DTI("uSoundOcclusion", &::uSoundZoneBase::DTI, 384ul, 0u, 0u);

__attribute__((weak)) MtObject* uSoundOcclusion::MyDTI::newInstance() const {
    DDON_STUB("uSoundOcclusion::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundOcclusion::cBoundingBox::getDTI() const {
    return uSoundOcclusion::cBoundingBox::DTI;
}

uSoundOcclusion::cBoundingBox::~cBoundingBox() {
    if (mpStaticBoundingArray != nullptr) {
        MtMemory::mpAllocatorType[14]->memFree(static_cast<void*>(mpStaticBoundingArray));
        mpStaticBoundingArray = nullptr;
    }
    if (mpDynamicBoundingArray == nullptr) {
        return;
    }
    MtMemory::mpAllocatorType[14]->memFree(static_cast<void*>(mpDynamicBoundingArray));
    mpDynamicBoundingArray = nullptr;
}

MtUI* uSoundOcclusion::cBoundingBox::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void uSoundOcclusion::cBoundingBox::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void uSoundOcclusion::cBoundingBox::createAllBoundingBox(cZoneLayout* pZone) {
    DDON_STUB("uSoundOcclusion::cBoundingBox::createAllBoundingBox")
    /* stub */
}

__attribute__((weak)) uSoundOcclusion::cBoundingBox::PairWork* uSoundOcclusion::cBoundingBox::createPairWork(cZoneLayout* pZone, bool isDynamic, u32* pPairWorkNum) {
    DDON_STUB("uSoundOcclusion::cBoundingBox::createPairWork")
    return nullptr;
}

__attribute__((weak)) uSoundOcclusion::cBoundingBox::BoundingWork* uSoundOcclusion::cBoundingBox::createBoundingBox(cZoneLayout* pZone, uSoundOcclusion::cBoundingBox::PairWork* pairWork, const u32 pairWorkNum, u16* pBoundingNum) {
    DDON_STUB("uSoundOcclusion::cBoundingBox::createBoundingBox")
    return nullptr;
}

__attribute__((weak)) void uSoundOcclusion::cBoundingBox::calcSetAABB(cZoneLayout* pZone, uSoundOcclusion::cBoundingBox::BoundingWork* pBoundingWork) {
    DDON_STUB("uSoundOcclusion::cBoundingBox::calcSetAABB")
    /* stub */
}

inline uSoundOcclusion::cBoundingBox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundOcclusion::cBoundingBox::MyDTI uSoundOcclusion::cBoundingBox::DTI("uSoundOcclusion::cBoundingBox", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* uSoundOcclusion::cBoundingBox::MyDTI::newInstance() const {
    return new (16u) uSoundOcclusion::cBoundingBox;
}

const MtDTI& uSoundOcclusion::cHollowManager::getDTI() const {
    return uSoundOcclusion::cHollowManager::DTI;
}

uSoundOcclusion::cHollowManager::~cHollowManager() {
    if (mpIndexArray == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(uSoundOcclusion::cHollowManager::DTI)->memFree(static_cast<void*>(mpIndexArray));
}

MtUI* uSoundOcclusion::cHollowManager::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void uSoundOcclusion::cHollowManager::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHollowId", &mHollowId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexArrayNum", &mIndexArrayNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpIndexArray", mpIndexArray, 33u, mIndexArrayNum);
}

inline uSoundOcclusion::cHollowManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundOcclusion::cHollowManager::MyDTI uSoundOcclusion::cHollowManager::DTI("uSoundOcclusion::cHollowManager", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* uSoundOcclusion::cHollowManager::MyDTI::newInstance() const {
    return new (16u) uSoundOcclusion::cHollowManager;
}

const MtDTI& uSoundOcclusion::cOcclusionGroupManager::getDTI() const {
    return uSoundOcclusion::cOcclusionGroupManager::DTI;
}

uSoundOcclusion::cOcclusionGroupManager::~cOcclusionGroupManager() {
}

MtUI* uSoundOcclusion::cOcclusionGroupManager::createUI(MtProperty& prop) {
    return this->uSoundZoneBase::cGroupManager::createUI(prop);
}

void uSoundOcclusion::cOcclusionGroupManager::createProperty(MtPropertyList& s) {
    this->uSoundZoneBase::cGroupManager::createProperty(s);
}

inline uSoundOcclusion::cOcclusionGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundOcclusion::cOcclusionGroupManager::MyDTI uSoundOcclusion::cOcclusionGroupManager::DTI("uSoundOcclusion::cOcclusionGroupManager", &::uSoundZoneBase::cGroupManager::DTI, 56ul, 0u, 0u);

MtObject* uSoundOcclusion::cOcclusionGroupManager::MyDTI::newInstance() const {
    return new (16u) uSoundOcclusion::cOcclusionGroupManager;
}

