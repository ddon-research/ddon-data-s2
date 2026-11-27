// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlCondition.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cpComponent.h"
#include "cpShlBase.h"
#include "nHumanMsg.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlComponentCtrl.h"
#include "uShlCondition.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompCondition::getDTI() const {
    return cShlParamCompCondition::DTI;
}

const MtDTI& cShlParamCompCondition::getComponentDTI() const {
    return cpShlCondition::DTI;
}

__attribute__((weak)) void cShlParamCompCondition::createProperty(MtPropertyList& proplist) {
    proplist << MtProperty(static_cast<MtObject*>(this), "isCondition", &isCondition, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "isAdd", &isAdd, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "goodStatus", &goodStatus, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "badStatus", &badStatus, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "HumanOriginalStatus", &HumanOriginalStatus, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mIsSetActiveTime", &mInfo.mIsSetActiveTime, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mActiveTime", &mInfo.mActiveTime, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mBoostLv", reinterpret_cast<s32*>(&mInfo.mBoostLv), 0u, 0u);
}

void cShlParamCompCondition::copy(const cShlParamComponent* pParamBase) {
    this->cShlParamComponent::copy(pParamBase);
    const cShlParamCompCondition* pParam = static_cast<const cShlParamCompCondition*>(pParamBase);
    isCondition = pParam->isCondition;
    isAdd = pParam->isAdd;
    goodStatus = pParam->goodStatus;
    badStatus = pParam->badStatus;
    HumanOriginalStatus = pParam->HumanOriginalStatus;
    mInfo.mIsSetActiveTime = pParam->mInfo.mIsSetActiveTime;
    mInfo.mActiveTime = pParam->mInfo.mActiveTime;
    mInfo.mBoostLv = pParam->mInfo.mBoostLv;
}

inline cShlParamCompCondition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompCondition::MyDTI cShlParamCompCondition::DTI("cShlParamCompCondition", &::cShlParamComponent::DTI, 56ul, 0u, 0u);

MtObject* cShlParamCompCondition::MyDTI::newInstance() const {
    return new (16u) cShlParamCompCondition;
}

const MtDTI& cShlParamCompCustomCondition::getDTI() const {
    return cShlParamCompCustomCondition::DTI;
}

const MtDTI& cShlParamCompCustomCondition::getComponentDTI() const {
    return cpShlCustomCondition::DTI;
}

void cShlParamCompCustomCondition::createProperty(MtPropertyList& proplist) {
    this->cShlParamCompCondition::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mMyCustomSkillId", &mMyCustomSkillId, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[0]", &mHosei[0], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[1]", &mHosei[1], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[2]", &mHosei[2], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[3]", &mHosei[3], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[4]", &mHosei[4], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[5]", &mHosei[5], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[6]", &mHosei[6], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[7]", &mHosei[7], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[8]", &mHosei[8], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[9]", &mHosei[9], 0u, 0u);
}

__attribute__((weak)) void cShlParamCompCustomCondition::copy(const cShlParamComponent* pParamBase) {
    DDON_STUB("cShlParamCompCustomCondition::copy")
    /* stub */
}

inline cShlParamCompCustomCondition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompCustomCondition::MyDTI cShlParamCompCustomCondition::DTI("cShlParamCompCustomCondition", &::cShlParamCompCondition::DTI, 104ul, 0u, 0u);

MtObject* cShlParamCompCustomCondition::MyDTI::newInstance() const {
    return new (16u) cShlParamCompCustomCondition;
}

const MtDTI& cpShlCondition::getDTI() const {
    return cpShlCondition::DTI;
}

inline cpShlCondition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlCondition::MyDTI cpShlCondition::DTI("cpShlCondition", &::cpShlBase::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlCondition::MyDTI::newInstance() const {
    DDON_STUB("cpShlCondition::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpShlCustomCondition::getDTI() const {
    return cpShlCustomCondition::DTI;
}

cpShlCustomCondition::cpShlCustomCondition() {
    DDON_STUB("cpShlCustomCondition::cpShlCustomCondition")
    /* stub */
}

__attribute__((weak)) void cpShlCustomCondition::initSub() {
    DDON_STUB("cpShlCustomCondition::initSub")
    /* stub */
}

inline cpShlCustomCondition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlCustomCondition::MyDTI cpShlCustomCondition::DTI("cpShlCustomCondition", &::cpShlCondition::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlCustomCondition::MyDTI::newInstance() const {
    DDON_STUB("cpShlCustomCondition::MyDTI::newInstance")
    return nullptr;
}

