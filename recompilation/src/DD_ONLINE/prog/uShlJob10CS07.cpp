// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob10CS07.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cUnit.h"
#include "cpShlShotCtrl.h"
#include "nHumanMsg.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlFollowMove.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob10CS07::getDTI() const {
    return cShlParamJob10CS07::DTI;
}

inline void cShlParamJob10CS07::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob10CS07::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob10CS07::getShlDTI() const {
    return uShlJob10CS07::DTI;
}

cShlParamJob10CS07::~cShlParamJob10CS07() {
}

void cShlParamJob10CS07::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckShl", &mCheckShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckShlCorePoint", &mCheckShlCorePoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckShlUndead", &mCheckShlUndead, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstShlCondition", &mConstShlCondition, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCustomSkillId", &mCustomSkillId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAddTime", &mAddTime[0], 32u, 10u);
}

void cShlParamJob10CS07::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
}

void cShlParamJob10CS07::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamJob10CS07* pParam = static_cast<const cShlParamJob10CS07*>(pParamBase);
    mCheckShl = pParam->mCheckShl;
    mCheckShlCorePoint = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 356);
    mCheckShlUndead = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 360);
    mConstShlCondition = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 364);
    mCustomSkillId = pParam->mCustomSkillId;
    mAddTime[0] = pParam->mAddTime[0];
    mAddTime[1] = pParam->mAddTime[1];
    mAddTime[2] = pParam->mAddTime[2];
    mAddTime[3] = pParam->mAddTime[3];
    mAddTime[4] = pParam->mAddTime[4];
    mAddTime[5] = pParam->mAddTime[5];
    mAddTime[6] = pParam->mAddTime[6];
    mAddTime[7] = pParam->mAddTime[7];
    mAddTime[8] = pParam->mAddTime[8];
    mAddTime[9] = pParam->mAddTime[9];
}

inline cShlParamJob10CS07::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob10CS07::MyDTI cShlParamJob10CS07::DTI("cShlParamJob10CS07", &::cShlParamBase::DTI, 416ul, 0u, 0u);

MtObject* cShlParamJob10CS07::MyDTI::newInstance() const {
    return new (16u) cShlParamJob10CS07;
}

const MtDTI& uShlJob10CS07::getDTI() const {
    return uShlJob10CS07::DTI;
}

uShlJob10CS07::~uShlJob10CS07() {
}

__attribute__((weak)) void uShlJob10CS07::initSub() {
    DDON_STUB("uShlJob10CS07::initSub")
    /* stub */
}

void uShlJob10CS07::callbackCheck(cHitInfo* pHitInfo) {
    this->uShlBase::callbackCheck(pHitInfo);
}

__attribute__((weak)) void uShlJob10CS07::updateSub() {
    DDON_STUB("uShlJob10CS07::updateSub")
    /* stub */
}

void uShlJob10CS07::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
}

void uShlJob10CS07::kill() {
    this->uShlBase::kill();
}

inline uShlJob10CS07::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob10CS07::MyDTI uShlJob10CS07::DTI("uShlJob10CS07", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlJob10CS07::MyDTI::newInstance() const {
    return new (16u) uShlJob10CS07;
}

