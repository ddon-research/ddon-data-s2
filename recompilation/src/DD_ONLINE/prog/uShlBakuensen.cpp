// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlBakuensen.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cComponentManager.h"
#include "cContextPlayerInfo.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpEffectProvider.h"
#include "cpRotateCtrl.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nHumanMsg.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlKeepOwnerLog.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlBakuensenLogNode::getDTI() const {
    return cShlBakuensenLogNode::DTI;
}

cShlBakuensenLogNode::~cShlBakuensenLogNode() {
}

void cShlBakuensenLogNode::keepLog() {
    this->cShlLogNode::keepLog();
    adjustGround();
}

__attribute__((weak)) void cShlBakuensenLogNode::adjustGround() {
    DDON_STUB("cShlBakuensenLogNode::adjustGround")
    /* stub */
}

inline cShlBakuensenLogNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlBakuensenLogNode::MyDTI cShlBakuensenLogNode::DTI("cShlBakuensenLogNode", &::cShlLogNode::DTI, 64ul, 0u, 0u);

MtObject* cShlBakuensenLogNode::MyDTI::newInstance() const {
    return new (16u) cShlBakuensenLogNode;
}

const MtDTI& cShlParamBakuensen::getDTI() const {
    return cShlParamBakuensen::DTI;
}

inline void cShlParamBakuensen::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamBakuensen::DTI)->memFree(p_addr);
}

MtDTI& cShlParamBakuensen::getShlDTI() const {
    return uShlBakuensen::DTI;
}

void cShlParamBakuensen::createProperty(MtPropertyList& s) {
    this->cShlParamKeepLog::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitDistance", &mLimitDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitTime", &mLimitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReverseSpeed", &mReverseSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShotWaitTime", &mShotWaitTime, 0u, 0u);
}

__attribute__((weak)) void cShlParamBakuensen::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamBakuensen::copy")
    /* stub */
}

inline cShlParamBakuensen::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamBakuensen::MyDTI cShlParamBakuensen::DTI("cShlParamBakuensen", &::cShlParamKeepLog::DTI, 400ul, 0u, 0u);

MtObject* cShlParamBakuensen::MyDTI::newInstance() const {
    return new (16u) cShlParamBakuensen;
}

const MtDTI& cShlParamBakuensenSpark::getDTI() const {
    return cShlParamBakuensenSpark::DTI;
}

inline void cShlParamBakuensenSpark::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamBakuensenSpark::DTI)->memFree(p_addr);
}

MtDTI& cShlParamBakuensenSpark::getShlDTI() const {
    return uBakuenseSpark::DTI;
}

inline cShlParamBakuensenSpark::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamBakuensenSpark::MyDTI cShlParamBakuensenSpark::DTI("cShlParamBakuensenSpark", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamBakuensenSpark::MyDTI::newInstance() const {
    return new (16u) cShlParamBakuensenSpark;
}

const MtDTI& uBakuenseSpark::getDTI() const {
    return uBakuenseSpark::DTI;
}

uBakuenseSpark::~uBakuenseSpark() {
}

void uBakuenseSpark::setup() {
    this->uShlBase::setup();
}

void uBakuenseSpark::update() {
    this->uShlBase::update();
    mRequestSetCollision = false;
}

void uBakuenseSpark::after() {
    this->uShlBase::after();
}

void uBakuenseSpark::updateMatrix() {
    updateLocalMatrix();
    updateWorldMatrix();
}

void uBakuenseSpark::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpOwner == nullptr) {
        return;
    }
    if (mpOwner->isEnable()) {
        return;
    }
    mpOwner = nullptr;
}

__attribute__((weak)) void uBakuenseSpark::createComponent() {
    DDON_STUB("uBakuenseSpark::createComponent")
    /* stub */
}

inline uBakuenseSpark::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uBakuenseSpark::MyDTI uBakuenseSpark::DTI("uBakuenseSpark", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uBakuenseSpark::MyDTI::newInstance() const {
    return new (16u) uBakuenseSpark;
}

const MtDTI& uShlBakuensen::getDTI() const {
    return uShlBakuensen::DTI;
}

const MtDTI* uShlBakuensen::getLogNodeDTI() {
    return &cShlBakuensenLogNode::DTI;
}

uShlBakuensen::~uShlBakuensen() {
    if (mpFireUnitDummy == nullptr) {
        return;
    }
    sUnit::getInstance()->remove(static_cast<cUnit*>(mpFireUnitDummy));
    if (mpFireUnitDummy == nullptr) {
        return;
    }
    delete mpFireUnitDummy;
    mpFireUnitDummy = nullptr;
}

void uShlBakuensen::setup() {
    this->uShlKeepOwnerLog::setup();
}

void uShlBakuensen::kill() {
    this->uShlKeepOwnerLog::kill();
    if (mpBakuenEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpBakuenEfcHandle, 1u);
    mpBakuenEfcHandle = nullptr;
}

void uShlBakuensen::updatePtr() {
    this->uShlKeepOwnerLog::updatePtr();
    if (mpFireUnitDummy == nullptr) {
        return;
    }
    if (mpFireUnitDummy->isEnable()) {
        return;
    }
    mpFireUnitDummy = nullptr;
}

void uShlBakuensen::updateEfcHandle() {
    this->uShlKeepOwnerLog::updateEfcHandle();
    if (mpBakuenEfcHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpBakuenEfcHandle)) {
        return;
    }
    mpBakuenEfcHandle->mpOwner = nullptr;
    mpBakuenEfcHandle = nullptr;
}

void uShlBakuensen::createProperty(MtPropertyList& s) {
    this->uShlKeepOwnerLog::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mReverseSpeed", &mReverseSpeed, 0u, 0u);
}

void uShlBakuensen::draw(cDraw* pDraw) {
    this->uShlKeepOwnerLog::draw(pDraw);
}

__attribute__((weak)) void uShlBakuensen::initSub() {
    DDON_STUB("uShlBakuensen::initSub")
    /* stub */
}

void uShlBakuensen::updateSub() {
    if (mpOwner == nullptr) {
        return;
    }
    this->uShlKeepOwnerLog::updateSub();
    switch (static_cast<unsigned int>(mBakuenPhase - 1)) {
        case 0:
        {
            traceWait();
            break;
        }
        case 1:
        {
            if (setupReverse()) {
                mBakuenPhase = nShlBakuensen::MODE_BAKUEN_REVERSE;
                updateReverse();
            }
            break;
        }
        case 2:
        {
            updateReverse();
            break;
        }
        case 3:
        {
            mShotWaitTimer = mShotWaitTimer - mDeltaTime;
            if (0.0f > mShotWaitTimer) {
                mBakuenPhase = nShlBakuensen::MODE_BAKUEN_SHOT;
            }
            break;
        }
        case 4:
        {
            shotBakuensen();
            break;
        }
        case 5:
        {
            requestKill();
            break;
        }
        default:
        {
            break;
        }
    }
}

void uShlBakuensen::requestIgnite() {
    mLogPhase = nShlKeepLog::MODE_STOP;
    mBakuenPhase = nShlBakuensen::MODE_BAKUEN_SET_UP_REVERSE;
}

__attribute__((weak)) void uShlBakuensen::traceWait() {
    DDON_STUB("uShlBakuensen::traceWait")
    /* stub */
}

__attribute__((weak)) bool uShlBakuensen::setupReverse() {
    DDON_STUB("uShlBakuensen::setupReverse")
    return {};
}

__attribute__((weak)) void uShlBakuensen::updateReverse() {
    DDON_STUB("uShlBakuensen::updateReverse")
    /* stub */
}

__attribute__((weak)) void uShlBakuensen::shotBakuensen() {
    DDON_STUB("uShlBakuensen::shotBakuensen")
    /* stub */
}

inline uShlBakuensen::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlBakuensen::MyDTI uShlBakuensen::DTI("uShlBakuensen", &::uShlKeepOwnerLog::DTI, 11040ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlBakuensen::MyDTI::newInstance() const {
    DDON_STUB("uShlBakuensen::MyDTI::newInstance")
    return nullptr;
}

