// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpPathFinding.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "aStage.h"
#include "../../XFramework/cAI.h"
#include "../../XFramework/cAIPathTrace.h"
#include "cAIRouteInfo.h"
#include "../../XFramework/cAISvPathFinding.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/sAI.h"
#include "sAIExt.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sMain.h"
#include "sWorldOffset.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uStageParts.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpPathFinding::getDTI() const {
    return cpPathFinding::DTI;
}

void* cpPathFinding::operator new(size_t sz, u32 align) {
    return cpPathFinding::getAllocator()->memAlloc(sz, align, cpPathFinding::DTI.getID());
}

cpPathFinding::cpPathFinding() {
    DDON_STUB("cpPathFinding::cpPathFinding")
    /* stub */
}

cpPathFinding::~cpPathFinding() {
    if (mpNavTrace == nullptr) {
        return;
    }
    delete mpNavTrace;
    mpNavTrace = nullptr;
}

void cpPathFinding::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpPathFinding::setup() {
    DDON_STUB("cpPathFinding::setup")
    /* stub */
}

void cpPathFinding::move() {
    sAI* t0 = sAI::getInstance();
    MtVector3 frame72(sWorldOffset::getInstance()->getOffsetPos(mOldOwnerRealPos));
    MtVector3 frame88(sWorldOffset::getInstance()->getOffsetPos(mOldTargetRealPos));
    cAISvNavPathFinding* p_nav_path = static_cast<sAIExt*>(t0)->getNavigationMeshService(frame72, frame88);
    if (p_nav_path == nullptr) {
        return;
    }
    u32 now_uid = static_cast<sAIExt*>(sAI::getInstance())->getNavigationMeshUID(p_nav_path);
    if (mUseMeshUID == now_uid) {
        return;
    }
    mForceUpdate = true;
    mUseMeshUID = now_uid;
    mpNavTrace->reset(false);
}

__attribute__((weak)) void cpPathFinding::kill() {
}

void cpPathFinding::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cpPathFinding::setTraceRange(f32 range) {
    DDON_STUB("cpPathFinding::setTraceRange")
    /* stub */
}

u32 cpPathFinding::trace(const MtVector3& TargetPos, MtVector3& NextPos, f32& NextDir) {
    mTraceResult = traceCore(TargetPos, NextPos, NextDir);
    return mTraceResult;
}

__attribute__((weak)) u32 cpPathFinding::traceCore(const MtVector3& TargetPos, MtVector3& NextPos, f32& NextDir) {
    DDON_STUB("cpPathFinding::traceCore")
    return {};
}

__attribute__((weak)) u32 cpPathFinding::getRouteInfo(MtVector3* pDstOfsPos, f32* pDstDir, f32 dis) const {
    DDON_STUB("cpPathFinding::getRouteInfo")
    return {};
}

__attribute__((weak)) const cAIRouteInfoParts* cpPathFinding::searchTargetRoteInfo(u32 routeInfoID) {
    DDON_STUB("cpPathFinding::searchTargetRoteInfo")
    return nullptr;
}

bool cpPathFinding::isRouteInfo() const {
    return mRouteInfo.mPartsInfo.mLength != 0;
}

__attribute__((weak)) bool cpPathFinding::isTraceLink(const MtVector3& pos) {
    DDON_STUB("cpPathFinding::isTraceLink")
    return {};
}

inline cpPathFinding::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpPathFinding::MyDTI cpPathFinding::DTI("cpPathFinding", &::cpComponent::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* cpPathFinding::MyDTI::newInstance() const {
    DDON_STUB("cpPathFinding::MyDTI::newInstance")
    return nullptr;
}

