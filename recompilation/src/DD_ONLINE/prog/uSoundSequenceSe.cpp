// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSoundSequenceSe.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/rSoundRequest.h"
#include "rSoundSequenceSe.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSoundSequenceSe::getDTI() const {
    return uSoundSequenceSe::DTI;
}

void* uSoundSequenceSe::operator new(size_t sz, u32 align) {
    return uSoundSequenceSe::getAllocator()->memAlloc(sz, align, uSoundSequenceSe::DTI.getID());
}

uSoundSequenceSe::uSoundSequenceSe() {
    mSeqState = 0;
    mSeqStateOld = 0;
    mJointNo = 0;
    mVolume = 0.0f;
    mRequestMode = 0;
    mpTgtModel = nullptr;
    mpSeqSeWork = nullptr;
    mpSequenceSe = nullptr;
    mCallPos = MtVector3::Zero;
    mIsSetCallPos = false;
    mIsAutoDelete = false;
}

uSoundSequenceSe::~uSoundSequenceSe() {
    DDON_STUB("uSoundSequenceSe::~uSoundSequenceSe")
    /* stub */
}

__attribute__((weak)) void uSoundSequenceSe::move() {
    DDON_STUB("uSoundSequenceSe::move")
    /* stub */
}

void uSoundSequenceSe::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSeqState", &mSeqState, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestMode", &mRequestMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVolume", &mVolume, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCallPos", &mCallPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTgtModel", reinterpret_cast<MtObject* *>(&mpTgtModel), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SequenceSe", "resource", reinterpret_cast<MT_MFUNC>(&::uSoundSequenceSe::getSequenceSe), reinterpret_cast<MT_MFUNC>(&::uSoundSequenceSe::setSequenceSe), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uSoundSequenceSe::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uSoundSequenceSe::setSequenceSe(rSoundSequenceSe* pRes) {
    DDON_STUB("uSoundSequenceSe::setSequenceSe")
    /* stub */
}

static auto ddon_emit_0x01b257e0 __attribute__((used)) = &uSoundSequenceSe::getSequenceSe;

MOVE_LINE uSoundSequenceSe::getSeqSeUnitMoveLine() {
    return LINE_0;
}

void uSoundSequenceSe::requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pSrq, reqNo, thisId, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void uSoundSequenceSe::requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId, const MtVector3& pos) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pSrq, reqNo, thisId, pos, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void uSoundSequenceSe::requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jntNo) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pSrq, reqNo, thisId, pCoord, jntNo, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void uSoundSequenceSe::keyOffSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->keyOffSe(pSrq, reqNo, thisId, sSoundExt::SE_SEARCH_KEY_ALL);
}

__attribute__((weak)) void uSoundSequenceSe::setSeVolumeRatio(rSoundRequest* pSrq, u32 reqNo, u32 thisId, f32 volume) {
    DDON_STUB("uSoundSequenceSe::setSeVolumeRatio")
    /* stub */
}

void uSoundSequenceSe::setSePosition(rSoundRequest* pSrq, u32 reqNo, u32 thisId, const MtVector3& pos) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    sSound::getInstance()->setSePosition(pSrq, reqNo, thisId, pos, false);
}

bool uSoundSequenceSe::isPause() {
    return false;
}

__attribute__((weak)) void uSoundSequenceSe::playSequenceSe(rSoundSequenceSe* pRes) {
    DDON_STUB("uSoundSequenceSe::playSequenceSe")
    /* stub */
}

__attribute__((weak)) void uSoundSequenceSe::requestSe(rSoundRequest* pSrq, rSoundSequenceSe::SequenceSe* pSeqSe) {
    DDON_STUB("uSoundSequenceSe::requestSe")
    /* stub */
}

inline uSoundSequenceSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundSequenceSe::MyDTI uSoundSequenceSe::DTI("uSoundSequenceSe", &::cUnit::DTI, 128ul, 0u, 0u);

MtObject* uSoundSequenceSe::MyDTI::newInstance() const {
    return new (16u) uSoundSequenceSe;
}

