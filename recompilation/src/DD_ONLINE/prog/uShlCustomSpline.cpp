// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlCustomSpline.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "nHumanMsg.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlSpline.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCustomSpline::getDTI() const {
    return cShlParamCustomSpline::DTI;
}

MtDTI& cShlParamCustomSpline::getShlDTI() const {
    return uShlCustomSpline::DTI;
}

void cShlParamCustomSpline::createProperty(MtPropertyList& proplist) {
    this->cShlParamSpline::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mMyCustomSkillId", &mMyCustomSkillId, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[0]", &mCustomTime[0], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[1]", &mCustomTime[1], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[2]", &mCustomTime[2], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[3]", &mCustomTime[3], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[4]", &mCustomTime[4], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[5]", &mCustomTime[5], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[6]", &mCustomTime[6], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[7]", &mCustomTime[7], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[8]", &mCustomTime[8], 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomTime[9]", &mCustomTime[9], 0u, 0u);
}

void cShlParamCustomSpline::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpline::copy(pParamBase);
    const cShlParamCustomSpline* pParam = static_cast<const cShlParamCustomSpline*>(pParamBase);
    mCustomTime[0] = pParam->mCustomTime[0];
    mCustomTime[1] = pParam->mCustomTime[1];
    mCustomTime[2] = pParam->mCustomTime[2];
    mCustomTime[3] = pParam->mCustomTime[3];
    mCustomTime[4] = pParam->mCustomTime[4];
    mCustomTime[5] = pParam->mCustomTime[5];
    mCustomTime[6] = pParam->mCustomTime[6];
    mCustomTime[7] = pParam->mCustomTime[7];
    mCustomTime[8] = pParam->mCustomTime[8];
    mCustomTime[9] = pParam->mCustomTime[9];
    mMyCustomSkillId = pParam->mMyCustomSkillId;
}

inline cShlParamCustomSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCustomSpline::MyDTI cShlParamCustomSpline::DTI("cShlParamCustomSpline", &::cShlParamSpline::DTI, 560ul, 0u, 0u);

MtObject* cShlParamCustomSpline::MyDTI::newInstance() const {
    return new (16u) cShlParamCustomSpline;
}

const MtDTI& uShlCustomSpline::getDTI() const {
    return uShlCustomSpline::DTI;
}

__attribute__((weak)) void uShlCustomSpline::initSub() {
    DDON_STUB("uShlCustomSpline::initSub")
    /* stub */
}

void uShlCustomSpline::updateSub() {
    this->uShlSpline::updateSub();
    if (mTimer >= (mDieFrame * dieFrameRate)) {
        requestKill();
    }
}

inline uShlCustomSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlCustomSpline::MyDTI uShlCustomSpline::DTI("uShlCustomSpline", &::uShlSpline::DTI, 11472ul, 0u, 0u);

MtObject* uShlCustomSpline::MyDTI::newInstance() const {
    return new (16u) uShlCustomSpline;
}

