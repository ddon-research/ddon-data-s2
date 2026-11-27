// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sPlatformUtil.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cPlatformUtilCommon.h"
#include "cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sPlatformUtil::getDTI() const {
    return sPlatformUtil::DTI;
}

void* sPlatformUtil::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sPlatformUtil::DTI)->memAlloc(sz, align, sPlatformUtil::DTI.mID);
}

__attribute__((weak)) void sPlatformUtil::move() {
    DDON_STUB("sPlatformUtil::move")
    /* stub */
}

void sPlatformUtil::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpSystemService", reinterpret_cast<MtObject* *>(&mpSystemService), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRemotePlay", reinterpret_cast<MtObject* *>(&mpRemotePlay), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGameLiveStream", reinterpret_cast<MtObject* *>(&mpGameLiveStream), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpScreenshot", reinterpret_cast<MtObject* *>(&mpScreenshot), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVideoRecorder", reinterpret_cast<MtObject* *>(&mpVideoRecorder), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSharePlay", reinterpret_cast<MtObject* *>(&mpSharePlay), 0u, 0u);
}

MtUI* sPlatformUtil::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) nPlatformUtil::nSystemService::HANDLE sPlatformUtil::registrySystemServiceEvent(nPlatformUtil::nSystemService::EVENT_TYPE::TYPE type, MtObject* pobject, nPlatformUtil::nSystemService::OBJECTEVENT function) {
    DDON_STUB("sPlatformUtil::registrySystemServiceEvent")
    return {};
}

__attribute__((weak)) void sPlatformUtil::setSharePlayApproveMode(const nPlatformUtil::nSharePlay::APPROVE_MODE::TYPE type) {
    DDON_STUB("sPlatformUtil::setSharePlayApproveMode")
    /* stub */
}

__attribute__((weak)) void sPlatformUtil::setScreenshotOverlayImage(MT_CTSTR path, u32 offset_x, u32 offset_y) {
    DDON_STUB("sPlatformUtil::setScreenshotOverlayImage")
    /* stub */
}

__attribute__((weak)) void sPlatformUtil::setEnable(const bool enable, const u32 flags) {
    DDON_STUB("sPlatformUtil::setEnable")
    /* stub */
}

sPlatformUtil::sPlatformUtil() {
    DDON_STUB("sPlatformUtil::sPlatformUtil")
    /* stub */
}

__attribute__((noinline)) sPlatformUtil::~sPlatformUtil() {
    DDON_STUB("sPlatformUtil::~sPlatformUtil")
    /* stub */
}

__attribute__((weak)) void sPlatformUtil::onLiveStremingUpdate(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type) {
    DDON_STUB("sPlatformUtil::onLiveStremingUpdate")
    /* stub */
}

inline sPlatformUtil::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sPlatformUtil::MyDTI sPlatformUtil::DTI("sPlatformUtil", &::cSystem::DTI, 80ul, 0u, 0u);

sPlatformUtil* sPlatformUtil::mpInstance;

__attribute__((weak)) MtObject* sPlatformUtil::MyDTI::newInstance() const {
    DDON_STUB("sPlatformUtil::MyDTI::newInstance")
    return nullptr;
}

