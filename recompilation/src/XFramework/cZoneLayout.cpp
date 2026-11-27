// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneLayout.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDynamicBVHCollision.h"
#include "cResource.h"
#include "nZone.h"
#include "rZone.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cZoneLayout::getDTI() const {
    return cZoneLayout::DTI;
}

void* cZoneLayout::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cZoneLayout::DTI)->memAlloc(sz, align, cZoneLayout::DTI.mID);
}

cZoneLayout::cZoneLayout(const MtDTI* pGroupManagerDTI) {
    DDON_STUB("cZoneLayout::cZoneLayout")
    /* stub */
}

__attribute__((noinline)) cZoneLayout::~cZoneLayout() {
    DDON_STUB("cZoneLayout::~cZoneLayout")
    /* stub */
}

void cZoneLayout::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHandle", &mIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpNativeResource", "resource", static_cast<void*>(&mpNativeResource), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpContentsPool", reinterpret_cast<MtObject* *>(&mpContentsPool), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASS, "mLayoutElementArray", reinterpret_cast<MT_MFUNC>(&::cZoneLayout::getLayoutElement), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cZoneLayout::getLayoutElementNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mGroupManagerArray", static_cast<MtObject*>(&mGroupManagerArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mWorldOffset", reinterpret_cast<MT_MFUNC>(&::cZoneLayout::getWorldOffsetForPropDynamic), reinterpret_cast<MT_MFUNC>(&::cZoneLayout::setWorldOffset), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mAngle", reinterpret_cast<MT_MFUNC>(&::cZoneLayout::getAngleForUI), reinterpret_cast<MT_MFUNC>(&::cZoneLayout::setAngleForUI), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_QUATERNION, "mQuaternion", reinterpret_cast<MT_MFUNC>(&::cZoneLayout::getQuaternionForPropDynamic), reinterpret_cast<MT_MFUNC>(&::cZoneLayout::setQuaternion), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mWorldMatrix", &mWorldMatrix, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldInverseMatrix", &mWorldInverseMatrix, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnableApplyOffset", &mFlgEnableApplyOffset, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnableQuaternion", &mFlgEnableQuaternion, 1u, 0u);
}

__attribute__((weak)) void cZoneLayout::move() {
    DDON_STUB("cZoneLayout::move")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::setValueFromResource(rZone* pSourceResource) {
    DDON_STUB("cZoneLayout::setValueFromResource")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::repairValueFromResource() {
    DDON_STUB("cZoneLayout::repairValueFromResource")
    /* stub */
}

nZone::cLayoutElement* cZoneLayout::getLayoutElement(u32 index) {
    if (index < mLayoutElementNum) {
        return &mpLayoutElementArray[index];
    } else {
        return nullptr;
    }
}

nZone::cLayoutElement* cZoneLayout::getLayoutElementFromUniqueID(u32 UniqueID) {
    if (mpNativeResource != nullptr) {
        const u32 TargetIndex = mpNativeResource->getLayoutIndexFromUniqueID(UniqueID);
        if (TargetIndex < mLayoutElementNum) {
            return &mpLayoutElementArray[TargetIndex];
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

u32 cZoneLayout::getLayoutElementNum() const {
    return mLayoutElementNum;
}

nZone::cLayoutElement* cZoneLayout::getGlobalLayoutElement(u32 GlobalShapeIndex) {
    if (mpNativeResource != nullptr) {
        if (GlobalShapeIndex < mpNativeResource->mGlobalLayoutIndexArrayNum) {
            const u32 GlobalLayoutIndex = mpNativeResource->getGlobalLayoutIndex(GlobalShapeIndex);
            if (GlobalLayoutIndex != 0xFFFFFFFFu) {
                if (GlobalLayoutIndex < mLayoutElementNum) {
                    return &mpLayoutElementArray[GlobalLayoutIndex];
                }
            }
            return nullptr;
        }
    }
    return nullptr;
}

u32 cZoneLayout::getGlobalLayoutElementNum() {
    if (mpNativeResource != nullptr) {
        return mpNativeResource->mGlobalLayoutIndexArrayNum;
    } else {
        return 0;
    }
}

nZone::cLayoutElement* cZoneLayout::getGlobalLayoutElement(cZoneLayout::cInGameGroupManager& TargetGroupManager, u32 GlobalShapeIndex) {
    const u32 GlobalShapeNum = TargetGroupManager.mpResourceGroupManager->getGroupGlobalLayoutIndexNum();
    if (GlobalShapeIndex < GlobalShapeNum) {
        const u32 GlobalLayoutIndex = TargetGroupManager.mpResourceGroupManager->getGroupGlobalLayoutIndex(GlobalShapeIndex);
        if (GlobalLayoutIndex != 0xFFFFFFFFu) {
            if (GlobalLayoutIndex < mLayoutElementNum) {
                return &mpLayoutElementArray[GlobalLayoutIndex];
            }
        }
        return nullptr;
    } else {
        return nullptr;
    }
}

u32 cZoneLayout::getGlobalLayoutElementNum(cZoneLayout::cInGameGroupManager& TargetGroupManager) {
    return TargetGroupManager.mpResourceGroupManager->getGroupGlobalLayoutIndexNum();
}

__attribute__((weak)) cZoneLayout::cInGameGroupManager* cZoneLayout::getGroupManagerFromLayout(nZone::cLayoutElement& src) {
    DDON_STUB("cZoneLayout::getGroupManagerFromLayout")
    return nullptr;
}

__attribute__((weak)) const cZoneLayout::cInGameGroupManager* cZoneLayout::getGroupManagerFromLayoutConst(const nZone::cLayoutElement& src) const {
    DDON_STUB("cZoneLayout::getGroupManagerFromLayoutConst")
    return nullptr;
}

__attribute__((weak)) cZoneLayout::cInGameGroupManager* cZoneLayout::getGroupManagerFromGroupID(s32 GroupID) {
    DDON_STUB("cZoneLayout::getGroupManagerFromGroupID")
    return nullptr;
}

cZoneLayout::cInGameGroupManager* cZoneLayout::getGroupManagerFromIndex(s32 GroupIndex) {
    if (GroupIndex < static_cast<int>(mGroupManagerArray.mLength)) {
        return static_cast<cInGameGroupManager*>(mGroupManagerArray.mpArray[static_cast<unsigned int>(GroupIndex)]);
    } else {
        return nullptr;
    }
}

u32 cZoneLayout::getGroupManagerNum() const {
    return mGroupManagerArray.mLength;
}

__attribute__((weak)) bool cZoneLayout::isEnableStopShapeAll() const {
    DDON_STUB("cZoneLayout::isEnableStopShapeAll")
    return {};
}

__attribute__((weak)) void cZoneLayout::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cZoneLayout::applyWorldOffset")
    /* stub */
}

MtVector3 cZoneLayout::getWorldOffsetForPropDynamic() const {
    return mWorldOffset;
}

MtQuaternion cZoneLayout::getQuaternionForPropDynamic() const {
    return mQuaternion;
}

__attribute__((weak)) MtVector3 cZoneLayout::getAngleForUI() const {
    DDON_STUB("cZoneLayout::getAngleForUI")
    __builtin_unreachable();
}

__attribute__((weak)) void cZoneLayout::setAngleForUI(const MtVector3& NewDegreeAngle) {
    DDON_STUB("cZoneLayout::setAngleForUI")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::setWorldOffset(const MtVector3& NewWorldOffset) {
    DDON_STUB("cZoneLayout::setWorldOffset")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::setQuaternion(const MtQuaternion& NewZoneQuaternion) {
    DDON_STUB("cZoneLayout::setQuaternion")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::requestUpdateDBVT(nZone::cLayoutElement& RequestData) {
    DDON_STUB("cZoneLayout::requestUpdateDBVT")
    /* stub */
}

inline cZoneLayout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneLayout::MyDTI cZoneLayout::DTI("cZoneLayout", &::MtObject::DTI, 272ul, 0u, 0u);

alignas(8) unsigned char cZoneLayout_INVALID_PATH_bytes[8] __asm__("_ZN11cZoneLayout12INVALID_PATHE") = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* cZoneLayout::MyDTI::newInstance() const {
    DDON_STUB("cZoneLayout::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneLayout::cInGameGroupManager::getDTI() const {
    return cZoneLayout::cInGameGroupManager::DTI;
}

cZoneLayout::cInGameGroupManager::cInGameGroupManager() {
    mIndex = 0x7FFFFFFF;
    mpResourceGroupManager = nullptr;
    mpSystemOwner = nullptr;
    mpUserOwner = nullptr;
    mFlgEnable = true;
    mpDynamicBvhMaster = nullptr;
}

cZoneLayout::cInGameGroupManager::~cInGameGroupManager() {
    if (mpDynamicBvhMaster == nullptr) {
        return;
    }
    delete mpDynamicBvhMaster;
}

void cZoneLayout::cInGameGroupManager::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnable", &mFlgEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpUserOwner", &mpUserOwner, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSystemOwner", reinterpret_cast<MtObject* *>(&mpSystemOwner), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResourceGroupManager", reinterpret_cast<MtObject* *>(&mpResourceGroupManager), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDynamicBvhMaster", reinterpret_cast<MtObject* *>(&mpDynamicBvhMaster), 2u, 0u);
}

void cZoneLayout::cInGameGroupManager::move() {
    if (mpDynamicBvhMaster == nullptr) {
        return;
    }
    mpDynamicBvhMaster->update();
}

nZone::cLayoutElement* cZoneLayout::cInGameGroupManager::getGroupLayoutElementFromIndex(u32 index) const {
    if (mpSystemOwner != nullptr) {
        const u32 LayoutIndex = mpResourceGroupManager->getGroupLayoutIndex(index);
        if (LayoutIndex < mpSystemOwner->mLayoutElementNum) {
            return &mpSystemOwner->mpLayoutElementArray[LayoutIndex];
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void cZoneLayout::cInGameGroupManager::setLayoutEnableAll(bool enable) {
    DDON_STUB("cZoneLayout::cInGameGroupManager::setLayoutEnableAll")
    /* stub */
}

bool cZoneLayout::cInGameGroupManager::isEnableStopShape() const {
    if (mpDynamicBvhMaster != nullptr) {
        if (mpResourceGroupManager != nullptr) {
            u32 t0 = mpDynamicBvhMaster->mDynamicBVH.getInsertLeafNum();
            u32 t1 = mpResourceGroupManager->getGroupLayoutIndexNum();
            return t0 >= t1;
        }
    }
    return true;
}

__attribute__((weak)) void cZoneLayout::cInGameGroupManager::requestUpdateDBVT(nZone::cLayoutElement& RequestData) {
    DDON_STUB("cZoneLayout::cInGameGroupManager::requestUpdateDBVT")
    /* stub */
}

inline cZoneLayout::cInGameGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneLayout::cInGameGroupManager::MyDTI cZoneLayout::cInGameGroupManager::DTI("cZoneLayout::cInGameGroupManager", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cZoneLayout::cInGameGroupManager::MyDTI::newInstance() const {
    return new (16u) cZoneLayout::cInGameGroupManager;
}

const MtDTI& cZoneLayout::cDynamicBVHMaster::getDTI() const {
    return cZoneLayout::cDynamicBVHMaster::DTI;
}

cZoneLayout::cDynamicBVHMaster::~cDynamicBVHMaster() {
    DDON_STUB("cZoneLayout::cDynamicBVHMaster::~cDynamicBVHMaster")
    /* stub */
}

void cZoneLayout::cDynamicBVHMaster::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDynamicBVH", static_cast<MtObject*>(&mDynamicBVH), 2u, 0u);
}

__attribute__((weak)) void cZoneLayout::cDynamicBVHMaster::update() {
    DDON_STUB("cZoneLayout::cDynamicBVHMaster::update")
    /* stub */
}

__attribute__((weak)) void cZoneLayout::cDynamicBVHMaster::requestUpdateDBVT(nZone::cLayoutElement& RequestData, u32 ThreadIndex) {
    DDON_STUB("cZoneLayout::cDynamicBVHMaster::requestUpdateDBVT")
    /* stub */
}

inline cZoneLayout::cDynamicBVHMaster::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneLayout::cDynamicBVHMaster::MyDTI cZoneLayout::cDynamicBVHMaster::DTI("cZoneLayout::cDynamicBVHMaster", &::MtObject::DTI, 320ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneLayout::cDynamicBVHMaster::MyDTI::newInstance() const {
    DDON_STUB("cZoneLayout::cDynamicBVHMaster::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cZoneLayout::cInGameGroupManager>::~MtTypedArray();

template MtTypedArray<nZone::cLayoutElement>::~MtTypedArray();

