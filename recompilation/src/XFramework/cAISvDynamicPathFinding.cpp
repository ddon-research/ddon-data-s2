// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "cAISvDynamicPathFinding.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "cAIService.h"
#include "cResource.h"
#include "sCollision.h"
#include "sMain.h"
#include "uCoord.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAISvDynamicPathFinding::getDTI() const {
    return cAISvDynamicPathFinding::DTI;
}

void* cAISvDynamicPathFinding::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAISvDynamicPathFinding::DTI)->memAlloc(sz, align, cAISvDynamicPathFinding::DTI.mID);
}

cAISvDynamicPathFinding::~cAISvDynamicPathFinding() {
    DDON_STUB("cAISvDynamicPathFinding::~cAISvDynamicPathFinding")
    /* stub */
}

__attribute__((weak)) void cAISvDynamicPathFinding::reset() {
}

void cAISvDynamicPathFinding::move() {
    if (0.0f >= mGroup.mCurrentTime) {
        mGroup.GroupScanning();
        mGroup.mCurrentTime = mGroup.mDeltaTime;
    } else {
        mGroup.mCurrentTime = mGroup.mCurrentTime - (sMain::mpInstance)->mDeltaTime;
    }
}

void cAISvDynamicPathFinding::createProperty(MtPropertyList& s) {
    this->cAIService::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", static_cast<MtObject*>(&mGroup), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDynamicPath", "resource", static_cast<void*>(&mpDynamicPath), 0u, 0u);
}

MtUI* cAISvDynamicPathFinding::createUI(MtProperty& prop) {
    return this->cAIService::createUI(prop);
}

void cAISvDynamicPathFinding::setTrace(cAIPathTrace* pTrace) {
    if (scePthreadMutexLock(&mCs.mCSection) != 0) {
        abort();
    }
    mGroup.mTrace.addTrace(pTrace);
    if (scePthreadMutexUnlock(&mCs.mCSection) != 0) {
        abort();
    }
}

void cAISvDynamicPathFinding::removeTrace(cAIPathTrace* pTrace) {
    if (scePthreadMutexLock(&mCs.mCSection) != 0) {
        abort();
    }
    mGroup.mTrace.removeTrace(pTrace);
    if (scePthreadMutexUnlock(&mCs.mCSection) != 0) {
        abort();
    }
}

cAISvDynamicPathFinding::GroupManagement::Group* cAISvDynamicPathFinding::getGroupPath(u32 groupNum) {
    if (groupNum < mGroup.mNumberOfGroup) {
        return &mGroup.mpGroup[groupNum];
    } else {
        return nullptr;
    }
}

inline cAISvDynamicPathFinding::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::MyDTI cAISvDynamicPathFinding::DTI("cAISvDynamicPathFinding", &::cAIService::DTI, 448ul, 0u, 0u);

__attribute__((weak)) MtObject* cAISvDynamicPathFinding::MyDTI::newInstance() const {
    DDON_STUB("cAISvDynamicPathFinding::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAISvDynamicPathFinding::GroupManagement::getDTI() const {
    return cAISvDynamicPathFinding::GroupManagement::DTI;
}

__attribute__((noinline)) cAISvDynamicPathFinding::GroupManagement::~GroupManagement() {
    DDON_STUB("cAISvDynamicPathFinding::GroupManagement::~GroupManagement")
    /* stub */
}

void cAISvDynamicPathFinding::GroupManagement::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mRange", reinterpret_cast<MT_MFUNC>(&::cAISvDynamicPathFinding::GroupManagement::getRange), reinterpret_cast<MT_MFUNC>(&::cAISvDynamicPathFinding::GroupManagement::setRange), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTime", &mDeltaTime, 0u, 0u);
}

static auto ddon_emit_0x01b6b770 __attribute__((used)) = &cAISvDynamicPathFinding::GroupManagement::setRange;

static auto ddon_emit_0x01b6b760 __attribute__((used)) = &cAISvDynamicPathFinding::GroupManagement::getRange;

bool cAISvDynamicPathFinding::GroupManagement::MergeToPos() {
    u32 v0_1 = mUnit.mNumberOfUnit;
    if (mAttribute) {
        if (v0_1 == 0) {
            return false;
        } else {
            unsigned int i0_2 = 0;
            for (UnitManagement::Unit* p0_3 = mUnit.mpUnits;;) {
                if (p0_3->mAttribute == 1) {
                    if (((((p0_3->mpUnit->mPos.x - p0_3->mPrevPos.x) * (p0_3->mpUnit->mPos.x - p0_3->mPrevPos.x)) + ((p0_3->mpUnit->mPos.y - p0_3->mPrevPos.y) * (p0_3->mpUnit->mPos.y - p0_3->mPrevPos.y))) + ((p0_3->mpUnit->mPos.z - p0_3->mPrevPos.z) * (p0_3->mpUnit->mPos.z - p0_3->mPrevPos.z))) > 1.0000001e-6f) {
                        return true;
                    }
                }
                if ((i0_2 + 1u) < v0_1) {
                    i0_2 += 1u;
                    p0_3 += 1;
                } else {
                    break;
                }
            }
        }
    } else {
        if (v0_1 == 0) {
            return false;
        } else {
            unsigned int i3_2 = 0;
            for (UnitManagement::Unit* p3_3 = mUnit.mpUnits;;) {
                if (((((p3_3->mpUnit->mPos.x - p3_3->mPrevPos.x) * (p3_3->mpUnit->mPos.x - p3_3->mPrevPos.x)) + ((p3_3->mpUnit->mPos.y - p3_3->mPrevPos.y) * (p3_3->mpUnit->mPos.y - p3_3->mPrevPos.y))) + ((p3_3->mpUnit->mPos.z - p3_3->mPrevPos.z) * (p3_3->mpUnit->mPos.z - p3_3->mPrevPos.z))) > 1.0000001e-6f) {
                    return true;
                } else {
                    if ((i3_2 + 1u) < v0_1) {
                        i3_2 += 1u;
                        p3_3 += 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) bool cAISvDynamicPathFinding::GroupManagement::GroupScanning() {
    DDON_STUB("cAISvDynamicPathFinding::GroupManagement::GroupScanning")
    return {};
}

__attribute__((weak)) void cAISvDynamicPathFinding::GroupManagement::GrahamScanning(cAISvDynamicPathFinding::GroupManagement::Group* pGroup, u32 axis, MtVector3* vertex, u32 num) {
    DDON_STUB("cAISvDynamicPathFinding::GroupManagement::GrahamScanning")
    /* stub */
}

inline cAISvDynamicPathFinding::GroupManagement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::GroupManagement::MyDTI cAISvDynamicPathFinding::GroupManagement::DTI("cAISvDynamicPathFinding::GroupManagement", &::MtObject::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cAISvDynamicPathFinding::GroupManagement::MyDTI::newInstance() const {
    DDON_STUB("cAISvDynamicPathFinding::GroupManagement::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAISvDynamicPathFinding::GroupManagement::Group::getDTI() const {
    return cAISvDynamicPathFinding::GroupManagement::Group::DTI;
}

cAISvDynamicPathFinding::GroupManagement::Group::~Group() {
    if (mpVertex != nullptr) {
        MtMemoryAllocator::getAllocator(cAISvDynamicPathFinding::DTI)->memFree(static_cast<void*>(mpVertex));
    }
    if (mpUnitIndex == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(cAISvDynamicPathFinding::DTI)->memFree(static_cast<void*>(mpUnitIndex));
}

inline cAISvDynamicPathFinding::GroupManagement::Group::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::GroupManagement::Group::MyDTI cAISvDynamicPathFinding::GroupManagement::Group::DTI("cAISvDynamicPathFinding::GroupManagement::Group", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cAISvDynamicPathFinding::GroupManagement::Group::MyDTI::newInstance() const {
    DDON_STUB("cAISvDynamicPathFinding::GroupManagement::Group::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAISvDynamicPathFinding::UnitManagement::getDTI() const {
    return cAISvDynamicPathFinding::UnitManagement::DTI;
}

cAISvDynamicPathFinding::UnitManagement::~UnitManagement() {
    DDON_STUB("cAISvDynamicPathFinding::UnitManagement::~UnitManagement")
    /* stub */
}

inline cAISvDynamicPathFinding::UnitManagement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::UnitManagement::MyDTI cAISvDynamicPathFinding::UnitManagement::DTI("cAISvDynamicPathFinding::UnitManagement", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cAISvDynamicPathFinding::UnitManagement::MyDTI::newInstance() const {
    return new (16u) cAISvDynamicPathFinding::UnitManagement;
}

const MtDTI& cAISvDynamicPathFinding::UnitManagement::Unit::getDTI() const {
    return cAISvDynamicPathFinding::UnitManagement::Unit::DTI;
}

inline cAISvDynamicPathFinding::UnitManagement::Unit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::UnitManagement::Unit::MyDTI cAISvDynamicPathFinding::UnitManagement::Unit::DTI("cAISvDynamicPathFinding::UnitManagement::Unit", &::MtObject::DTI, 128ul, 0u, 0u);

MtObject* cAISvDynamicPathFinding::UnitManagement::Unit::MyDTI::newInstance() const {
    return new (16u) cAISvDynamicPathFinding::UnitManagement::Unit;
}

const MtDTI& cAISvDynamicPathFinding::TraceManagement::getDTI() const {
    return cAISvDynamicPathFinding::TraceManagement::DTI;
}

cAISvDynamicPathFinding::TraceManagement::~TraceManagement() {
    DDON_STUB("cAISvDynamicPathFinding::TraceManagement::~TraceManagement")
    /* stub */
}

__attribute__((weak)) void cAISvDynamicPathFinding::TraceManagement::addTrace(cAIPathTrace* pTrace) {
    DDON_STUB("cAISvDynamicPathFinding::TraceManagement::addTrace")
    /* stub */
}

__attribute__((weak)) void cAISvDynamicPathFinding::TraceManagement::removeTrace(cAIPathTrace* pTrace) {
    DDON_STUB("cAISvDynamicPathFinding::TraceManagement::removeTrace")
    /* stub */
}

inline cAISvDynamicPathFinding::TraceManagement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::TraceManagement::MyDTI cAISvDynamicPathFinding::TraceManagement::DTI("cAISvDynamicPathFinding::TraceManagement", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cAISvDynamicPathFinding::TraceManagement::MyDTI::newInstance() const {
    return new (16u) cAISvDynamicPathFinding::TraceManagement;
}

const MtDTI& cAISvDynamicPathFinding::TraceManagement::Trace::getDTI() const {
    return cAISvDynamicPathFinding::TraceManagement::Trace::DTI;
}

cAISvDynamicPathFinding::TraceManagement::Trace::~Trace() {
    mpAddr = nullptr;
}

inline cAISvDynamicPathFinding::TraceManagement::Trace::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvDynamicPathFinding::TraceManagement::Trace::MyDTI cAISvDynamicPathFinding::TraceManagement::Trace::DTI("cAISvDynamicPathFinding::TraceManagement::Trace", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cAISvDynamicPathFinding::TraceManagement::Trace::MyDTI::newInstance() const {
    DDON_STUB("cAISvDynamicPathFinding::TraceManagement::Trace::MyDTI::newInstance")
    return nullptr;
}

