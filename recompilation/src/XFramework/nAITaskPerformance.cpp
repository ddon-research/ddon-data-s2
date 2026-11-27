// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nAITaskPerformance.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nAI::TaskPerformanceInfo::getDTI() const {
    return nAI::TaskPerformanceInfo::DTI;
}

void* nAI::TaskPerformanceInfo::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nAI::TaskPerformanceInfo::DTI)->memAlloc(sz, align, ::nAI::TaskPerformanceInfo::DTI.mID);
}

void nAI::TaskPerformanceInfo::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nAI::TaskPerformanceInfo::DTI)->memFree(p_addr);
}

nAI::TaskPerformanceInfo::~TaskPerformanceInfo() {
    DDON_STUB("nAI::TaskPerformanceInfo::~TaskPerformanceInfo")
    /* stub */
}

void nAI::TaskPerformanceInfo::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_STRING, "mName", reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::getName), reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::setName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mPerformanceIndicator", &mPerformanceIndicator, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAllowTime", &mAllowTime, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOverloadManageType", &mOverloadManageType, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_CLASSREF, "LODList", reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::getLOD), reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::setLOD), 160u, reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::getLODNum), reinterpret_cast<MT_MFUNC>(&::nAI::TaskPerformanceInfo::setLODNum));
}

MtUI* nAI::TaskPerformanceInfo::createUI(MtProperty& prop) {
    return nullptr;
}

MT_CTSTR nAI::TaskPerformanceInfo::getName() {
    return mpDTI->mName;
}

nAI::TaskPerformanceInfo::LOD* nAI::TaskPerformanceInfo::getLOD(u32 level) {
    if (mLODList != nullptr) {
        if (level < mLODNum) {
            return &mLODList[level];
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01b829a0 __attribute__((used)) = &nAI::TaskPerformanceInfo::getLODNum;

__attribute__((weak)) void nAI::TaskPerformanceInfo::setName(MtString& s) {
}

__attribute__((weak)) void nAI::TaskPerformanceInfo::destroyLODList() {
    DDON_STUB("nAI::TaskPerformanceInfo::destroyLODList")
    /* stub */
}

__attribute__((weak)) void nAI::TaskPerformanceInfo::setLOD(nAI::TaskPerformanceInfo::LOD* pl, u32 level) {
}

__attribute__((weak)) void nAI::TaskPerformanceInfo::setLODNum(u32 n) {
}

inline nAI::TaskPerformanceInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nAI::TaskPerformanceInfo::MyDTI nAI::TaskPerformanceInfo::DTI("nAI::TaskPerformanceInfo", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* nAI::TaskPerformanceInfo::MyDTI::newInstance() const {
    return new (16u) ::nAI::TaskPerformanceInfo;
}

const MtDTI& nAI::TaskPerformanceInfo::LOD::getDTI() const {
    return nAI::TaskPerformanceInfo::LOD::DTI;
}

void nAI::TaskPerformanceInfo::LOD::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mEnablePerformanceManage", &mEnablePerformanceManage, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mPerformanceIndicator", &mPerformanceIndicator, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOverloadManageType", &mOverloadManageType, 0u, 0u);
}

MtUI* nAI::TaskPerformanceInfo::LOD::createUI(MtProperty& prop) {
    return nullptr;
}

inline nAI::TaskPerformanceInfo::LOD::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nAI::TaskPerformanceInfo::LOD::MyDTI nAI::TaskPerformanceInfo::LOD::DTI("nAI::TaskPerformanceInfo::LOD", &::MtObject::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* nAI::TaskPerformanceInfo::LOD::MyDTI::newInstance() const {
    DDON_STUB("nAI::TaskPerformanceInfo::LOD::MyDTI::newInstance")
    return nullptr;
}

