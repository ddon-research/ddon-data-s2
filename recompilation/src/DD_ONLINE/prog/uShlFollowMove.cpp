// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlFollowMove.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "nShlBase.h"
#include "sControlManager.h"
#include "sSetManager.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamFollowMove::getDTI() const {
    return cShlParamFollowMove::DTI;
}

inline void cShlParamFollowMove::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamFollowMove::DTI)->memFree(p_addr);
}

MtDTI& cShlParamFollowMove::getShlDTI() const {
    return uShlFollowMove::DTI;
}

void cShlParamFollowMove::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "jointNo", &jointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offset", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isNoConstOwner", &isNoConstOwner, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "followLimitId", reinterpret_cast<s32*>(&followLimitId), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstOwnerType", reinterpret_cast<s32*>(&mConstOwnerType), 0u, 0u);
}

cShlParamFollowMove::~cShlParamFollowMove() {
}

void cShlParamFollowMove::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamFollowMove* pParam = static_cast<const cShlParamFollowMove*>(pParamBase);
    jointNo = pParam->jointNo;
    offset = pParam->offset;
    isNoConstOwner = pParam->isNoConstOwner;
    followLimitId = pParam->followLimitId;
    mConstOwnerType = pParam->mConstOwnerType;
}

inline cShlParamFollowMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamFollowMove::MyDTI cShlParamFollowMove::DTI("cShlParamFollowMove", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamFollowMove::MyDTI::newInstance() const {
    return new (16u) cShlParamFollowMove;
}

const MtDTI& uShlFollowMove::getDTI() const {
    return uShlFollowMove::DTI;
}

const cShlParamFollowMove* uShlFollowMove::getShlParam() const {
    return static_cast<const cShlParamFollowMove*>(getShlParamBase());
}

uShlFollowMove::uShlFollowMove() {
    mAliveOwnerStatus = 0;
    mpConstOwner = nullptr;
}

uShlFollowMove::~uShlFollowMove() {
}

__attribute__((weak)) void uShlFollowMove::setup() {
    DDON_STUB("uShlFollowMove::setup")
    /* stub */
}

__attribute__((weak)) void uShlFollowMove::updateSub() {
    DDON_STUB("uShlFollowMove::updateSub")
    /* stub */
}

void uShlFollowMove::kill() {
    if (mShotReqInfo.mIsConst) {
        if (getTarget() != nullptr) {
            uDDOModel* t0 = getTarget();
            mPos.x = t0->mPos.x;
            mPos.y = t0->mPos.y;
            mPos.z = t0->mPos.z;
            mPos.pad_ = 0.0f;
            this->uShlBase::kill();
        } else {
            this->uShlBase::kill();
        }
    } else {
        this->uShlBase::kill();
    }
}

void uShlFollowMove::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpConstOwner == nullptr) {
        return;
    }
    if (mpConstOwner->isEnable()) {
        return;
    }
    mpConstOwner = nullptr;
}

uDDOModel* uShlFollowMove::getConstOwner() const {
    if (mpConstOwner == nullptr) {
        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(getShlParamBase()) + 384)) == 0) {
            return mpOwner;
        } else {
            return nullptr;
        }
    } else {
        return mpConstOwner;
    }
}

inline uShlFollowMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlFollowMove::MyDTI uShlFollowMove::DTI("uShlFollowMove", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlFollowMove::MyDTI::newInstance() const {
    return new (16u) uShlFollowMove;
}

