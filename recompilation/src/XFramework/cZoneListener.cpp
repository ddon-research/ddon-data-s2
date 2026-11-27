// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneListener.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cZoneLayout.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cZoneListener::getDTI() const {
    return cZoneListener::DTI;
}

cZoneListener::cZoneListener() {
    mpZoneLayout = nullptr;
    mTargetZoneLayoutIndex = cZoneLayout::INVALID_INDEX;
    mTargetZoneLayoutHandle = cZoneLayout::INVALID_ID;
    mpGroupManager = nullptr;
    mTargetShapeType = 0xFFFFFFFF;
    mPriorityRuleType = 1;
    mFlgCallNotifiedFunction = true;
    mFlgCallContentsCallbackFunction = false;
    mFlgCallbackSingleCallContentsGroup = false;
}

cZoneListener::~cZoneListener() {
}

void cZoneListener::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpZoneLayout", reinterpret_cast<MtObject* *>(&mpZoneLayout), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetZoneLayoutIndex", &mTargetZoneLayoutIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetShapeType", &mTargetShapeType, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGroupManager", reinterpret_cast<MtObject* *>(&mpGroupManager), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriorityRuleType", &mPriorityRuleType, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetShapeType", &mTargetShapeType, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Call notified", &mFlgCallNotifiedFunction, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Call Contents Callback", &mFlgCallContentsCallbackFunction, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Call Single On Contents Group", &mFlgCallbackSingleCallContentsGroup, 3u, 0u);
}

MtVector3 cZoneListener::myPos() {
    return MtVector3::Zero;
}

__attribute__((weak)) MtLineSegment cZoneListener::myLineSegment() {
    DDON_STUB("cZoneListener::myLineSegment")
    __builtin_unreachable();
}

MtGeomConvex* cZoneListener::myConvex() {
    return nullptr;
}

const MtVector3& cZoneListener::getZoneLayoutWorldOffset() const {
    return *((mpZoneLayout == nullptr) ? (&MtVector3::Zero) : (&mpZoneLayout->mWorldOffset));
}

bool cZoneListener::isRotateZoneLayout() const {
    if (mpZoneLayout != nullptr) {
        return mpZoneLayout->mFlgEnableQuaternion;
    } else {
        return false;
    }
}

const MtMatrix& cZoneListener::getZoneLayoutWorldMatrix() const {
    return *((mpZoneLayout == nullptr) ? (&MtMatrix::Identity) : (&mpZoneLayout->mWorldMatrix));
}

const MtMatrix& cZoneListener::getZoneLayoutWorldInverseMatrix() const {
    return *((mpZoneLayout == nullptr) ? (&MtMatrix::Identity) : (&mpZoneLayout->mWorldInverseMatrix));
}

void cZoneListener::registerTargetZoneLayout(cZoneLayout& TargetZoneLayout, u32 TargetZoneLayoutIndex, u32 TargetZoneLayoutHandle) {
    mpZoneLayout = &TargetZoneLayout;
    mTargetZoneLayoutIndex = TargetZoneLayoutIndex;
    mTargetZoneLayoutHandle = TargetZoneLayoutHandle;
}

void cZoneListener::unregisterTargetZoneLayout() {
    mpZoneLayout = nullptr;
    mTargetZoneLayoutIndex = cZoneLayout::INVALID_INDEX;
    mTargetZoneLayoutHandle = cZoneLayout::INVALID_ID;
    mpGroupManager = nullptr;
}

inline cZoneListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneListener::MyDTI cZoneListener::DTI("cZoneListener", &::MtObject::DTI, 48ul, 0u, 1u);

MtObject* cZoneListener::MyDTI::newInstance() const {
    return nullptr;
}

