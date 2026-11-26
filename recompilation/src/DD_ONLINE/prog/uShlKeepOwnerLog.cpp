// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlKeepOwnerLog.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlLogNode::getDTI() const {
    return cShlLogNode::DTI;
}

inline void cShlLogNode::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlLogNode::DTI)->memFree(p_addr);
}

cShlLogNode::cShlLogNode() {
    DDON_STUB("cShlLogNode::cShlLogNode")
    /* stub */
}

cShlLogNode::~cShlLogNode() {
}

__attribute__((weak)) void cShlLogNode::createProperty(MtPropertyList& s) {
}

void cShlLogNode::updatePtr() {
    if (mpModel != nullptr) {
        if (!mpModel->isEnable()) {
            mpModel = nullptr;
        }
    }
    if (mpOwnerShl == nullptr) {
        return;
    }
    if (mpOwnerShl->isEnable()) {
        return;
    }
    mpOwnerShl = nullptr;
}

__attribute__((weak)) void cShlLogNode::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cShlLogNode::applyWorldOffset")
    /* stub */
}

void cShlLogNode::init() {
    keepLog();
}

__attribute__((weak)) void cShlLogNode::final() {
}

void cShlLogNode::keepLog() {
    if (mpModel == nullptr) {
        return;
    }
    mPos.x = mpModel->mPos.x;
    mPos.y = mpModel->mPos.y;
    mPos.z = mpModel->mPos.z;
    mPos.pad_ = 0.0f;
    const MtMatrix& t0 = mpModel->getWorldMatrix(-1);
    mDir.x = t0.m[2].x;
    mDir.y = t0.m[2].y;
    mDir.z = t0.m[2].z;
    mDir.pad_ = 0.0f;
}

inline cShlLogNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlLogNode::MyDTI cShlLogNode::DTI("cShlLogNode", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlLogNode::MyDTI::newInstance() const {
    DDON_STUB("cShlLogNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cShlParamKeepLog::getDTI() const {
    return cShlParamKeepLog::DTI;
}

inline void* cShlParamKeepLog::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamKeepLog::DTI)->memAlloc(sz, align, cShlParamKeepLog::DTI.getID());
}

MtDTI& cShlParamKeepLog::getShlDTI() const {
    return uShlKeepOwnerLog::DTI;
}

cShlParamKeepLog::cShlParamKeepLog() {
    mWaitObjStatus = 0;
    mExeLogDistance = 0.0f;
    mWaitAttrFlag = 0;
    mExecuteAttrFlag = 0;
    mExeLogTime = 0.0f;
    mLogOptionFlag = 0;
    mLogNodeNumMax = 0;
}

void cShlParamKeepLog::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLogOptionFlag", &mLogOptionFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLogNodeNumMax", &mLogNodeNumMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExecuteAttrFlag", &mExecuteAttrFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExeLogTime", &mExeLogTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExeLogDistance", &mExeLogDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitAttrFlag", &mWaitAttrFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitObjStatus", &mWaitObjStatus, 0u, 0u);
}

void cShlParamKeepLog::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamKeepLog* pParam = static_cast<const cShlParamKeepLog*>(pParamBase);
    mLogOptionFlag = pParam->mLogOptionFlag;
    mLogNodeNumMax = pParam->mLogNodeNumMax;
    mExecuteAttrFlag = pParam->mExecuteAttrFlag;
    mExeLogTime = pParam->mExeLogTime;
    mExeLogDistance = pParam->mExeLogDistance;
    mWaitAttrFlag = pParam->mWaitAttrFlag;
    mWaitObjStatus = pParam->mWaitObjStatus;
}

inline cShlParamKeepLog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamKeepLog::MyDTI cShlParamKeepLog::DTI("cShlParamKeepLog", &::cShlParamBase::DTI, 384ul, 0u, 0u);

MtObject* cShlParamKeepLog::MyDTI::newInstance() const {
    return new (16u) cShlParamKeepLog;
}

const MtDTI& uShlKeepOwnerLog::getDTI() const {
    return uShlKeepOwnerLog::DTI;
}

inline void uShlKeepOwnerLog::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlKeepOwnerLog::DTI)->memFree(p_addr);
}

inline const cShlParamKeepLog* uShlKeepOwnerLog::getShlParam() const {
    return static_cast<const cShlParamKeepLog*>(mpShlParam2);
}

uShlKeepOwnerLog::uShlKeepOwnerLog() {
    DDON_STUB("uShlKeepOwnerLog::uShlKeepOwnerLog")
    /* stub */
}

uShlKeepOwnerLog::~uShlKeepOwnerLog() {
}

void uShlKeepOwnerLog::setup() {
    this->uShlBase::setup();
}

__attribute__((weak)) void uShlKeepOwnerLog::kill() {
    DDON_STUB("uShlKeepOwnerLog::kill")
    /* stub */
}

__attribute__((weak)) void uShlKeepOwnerLog::updatePtr() {
    DDON_STUB("uShlKeepOwnerLog::updatePtr")
    /* stub */
}

__attribute__((weak)) void uShlKeepOwnerLog::updateEfcHandle() {
    DDON_STUB("uShlKeepOwnerLog::updateEfcHandle")
    /* stub */
}

void uShlKeepOwnerLog::createProperty(MtPropertyList& s) {
    this->uDDOModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mKeepLogTimer", &mKeepLogTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKeepLogPosLast", &mKeepLogPosLast, 0u, 0u);
}

void uShlKeepOwnerLog::draw(cDraw* pDraw) {
    this->uDDOModel::draw(pDraw);
}

__attribute__((weak)) void uShlKeepOwnerLog::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlKeepOwnerLog::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlKeepOwnerLog::initSub() {
    DDON_STUB("uShlKeepOwnerLog::initSub")
    /* stub */
}

__attribute__((weak)) void uShlKeepOwnerLog::updateSub() {
    DDON_STUB("uShlKeepOwnerLog::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlKeepOwnerLog::addLogNode() {
    DDON_STUB("uShlKeepOwnerLog::addLogNode")
    /* stub */
}

cShlLogNode* uShlKeepOwnerLog::findLastNode() {
    if (static_cast<int>(mLogNodeArray.mLength - 1u) > -1) {
        return static_cast<cShlLogNode*>(mLogNodeArray.getBuffer()[static_cast<int>(mLogNodeArray.mLength - 1u)]);
    } else {
        return nullptr;
    }
}

void uShlKeepOwnerLog::eraseLastNode() {
    u32 t0 = mLogNodeArray.mLength;
    if (static_cast<int>(t0 - 1u) > -1) {
        int v0_1;
        u32 v0_2;
        u32 v0_5;
        u32 v1_5;
        if (mLogNodeArray.mAutoDelete) {
            if (mLogNodeArray.mpArray[static_cast<int>(t0 - 1u)] != nullptr) {
                delete mLogNodeArray.mpArray[static_cast<int>(t0 - 1u)];
                if (static_cast<int>(t0) >= static_cast<int>(mLogNodeArray.mLength)) {
                    v1_5 = mLogNodeArray.mLength;
                    goto region_cef26b;
                } else {
                    v0_1 = static_cast<int>(t0);
                    v0_2 = mLogNodeArray.mLength;
                    v0_5 = mLogNodeArray.mLength;
                }
            } else {
                if (static_cast<int>(t0) >= static_cast<int>(t0)) {
                    v1_5 = t0;
                    goto region_cef26b;
                } else {
                    v0_1 = static_cast<int>(t0);
                    v0_2 = t0;
                    v0_5 = t0;
                }
            }
        } else {
            if (static_cast<int>(t0) >= static_cast<int>(t0)) {
                v1_5 = t0;
                goto region_cef26b;
            } else {
                v0_1 = static_cast<int>(t0);
                v0_2 = t0;
                v0_5 = t0;
            }
        }
        for (;;) {
            mLogNodeArray.mpArray[v0_1 - 1] = mLogNodeArray.mpArray[v0_1];
            if (v0_2 != static_cast<unsigned int>(v0_1 + 1)) {
                v0_1 = v0_1 + 1;
            } else {
                v1_5 = v0_5;
                break;
            }
        }
        region_cef26b:;
        mLogNodeArray.mLength = v1_5 - 1u;
    }
}

inline uShlKeepOwnerLog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlKeepOwnerLog::MyDTI uShlKeepOwnerLog::DTI("uShlKeepOwnerLog", &::uShlBase::DTI, 11008ul, 0u, 1u);

MtObject* uShlKeepOwnerLog::MyDTI::newInstance() const {
    return nullptr;
}

template MtTypedArray<cShlLogNode>::~MtTypedArray();

