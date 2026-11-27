// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlHitReaction.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sMain.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlCondition.h"
#include "uShlSpline.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void cHitReaction::update(f32 deltaTime) {
    DDON_STUB("cHitReaction::update")
    /* stub */
}

const MtDTI& cShlParamHitReactionConditionStick::getDTI() const {
    return cShlParamHitReactionConditionStick::DTI;
}

inline void cShlParamHitReactionConditionStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamHitReactionConditionStick::DTI)->memFree(p_addr);
}

MtDTI& cShlParamHitReactionConditionStick::getShlDTI() const {
    return uShlHitReactionConditionStick::DTI;
}

__attribute__((weak)) void cShlParamHitReactionConditionStick::createProperty(MtPropertyList& s) {
    this->::cShlParamConditionStick::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCanChangeFrame", &mCanChangeFrame, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mChangeEffectNo", &mChangeEffectNo, 0, 0);
}

cShlParamHitReactionConditionStick::~cShlParamHitReactionConditionStick() {
}

__attribute__((weak)) void cShlParamHitReactionConditionStick::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamHitReactionConditionStick::copy")
    /* stub */
}

inline cShlParamHitReactionConditionStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamHitReactionConditionStick::MyDTI cShlParamHitReactionConditionStick::DTI("cShlParamHitReactionConditionStick", &::cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI, 416ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamHitReactionConditionStick::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamHitReactionConditionStick::DTI)->memAlloc(sizeof(cShlParamHitReactionConditionStick), 16u, cShlParamHitReactionConditionStick::DTI.getID())) cShlParamHitReactionConditionStick;
}

const MtDTI& cShlParamHitReactionSpline::getDTI() const {
    return cShlParamHitReactionSpline::DTI;
}

MtDTI& cShlParamHitReactionSpline::getShlDTI() const {
    return uShlHitReactionSpline::DTI;
}

void cShlParamHitReactionSpline::createProperty(MtPropertyList& s) {
    this->cShlParamSpline::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCanChangeFrame", &mCanChangeFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChangeEffectNo", &mChangeEffectNo, 0u, 0u);
}

void cShlParamHitReactionSpline::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpline::copy(pParamBase);
    const cShlParamHitReactionSpline* pParam = static_cast<const cShlParamHitReactionSpline*>(pParamBase);
    mCanChangeFrame = pParam->mCanChangeFrame;
    mChangeEffectNo = pParam->mChangeEffectNo;
}

inline cShlParamHitReactionSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamHitReactionSpline::MyDTI cShlParamHitReactionSpline::DTI("cShlParamHitReactionSpline", &::cShlParamSpline::DTI, 512ul, 0u, 0u);

MtObject* cShlParamHitReactionSpline::MyDTI::newInstance() const {
    return new (16u) cShlParamHitReactionSpline;
}

const MtDTI& cShlParamHitReactionStick::getDTI() const {
    return cShlParamHitReactionStick::DTI;
}

inline void cShlParamHitReactionStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamHitReactionStick::DTI)->memFree(p_addr);
}

MtDTI& cShlParamHitReactionStick::getShlDTI() const {
    return uShlHitReactionStick::DTI;
}

void cShlParamHitReactionStick::createProperty(MtPropertyList& s) {
    this->cShlParamStick::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCanChangeFrame", &mCanChangeFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChangeEffectNo", &mChangeEffectNo, 0u, 0u);
}

cShlParamHitReactionStick::~cShlParamHitReactionStick() {
}

void cShlParamHitReactionStick::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamHitReactionStick* pParam = static_cast<const cShlParamHitReactionStick*>(pParamBase);
    stickOption = pParam->stickOption;
    mCanChangeFrame = pParam->mCanChangeFrame;
    mChangeEffectNo = pParam->mChangeEffectNo;
}

inline cShlParamHitReactionStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamHitReactionStick::MyDTI cShlParamHitReactionStick::DTI("cShlParamHitReactionStick", &::cShlParamStick::DTI, 368ul, 0u, 0u);

MtObject* cShlParamHitReactionStick::MyDTI::newInstance() const {
    return new (16u) cShlParamHitReactionStick;
}

const MtDTI& uShlHitReactionConditionStick::getDTI() const {
    return uShlHitReactionConditionStick::DTI;
}

uShlHitReactionConditionStick::~uShlHitReactionConditionStick() {
}

void uShlHitReactionConditionStick::initSub() {
    this->uShlStick::initSub();
    if (getOwner() == nullptr) {
        return;
    }
    mHitReaction.mCheckHitEfcCtrl[0].uId = getOwner()->mUnitParam;
    mHitReaction.mCheckHitEfcCtrl[0].clearTimer = 2.0f;
}

void uShlHitReactionConditionStick::updateSub() {
    this->uShlStick::updateSub();
    mHitReaction.update(getDeltaTime());
}

__attribute__((weak)) void uShlHitReactionConditionStick::callbackCheck(cHitInfo* pHitInfo) {
    DDON_STUB("uShlHitReactionConditionStick::callbackCheck")
    /* stub */
}

__attribute__((weak)) MtObject* uShlHitReactionConditionStick::MyDTI::newInstance() const {
    DDON_STUB("uShlHitReactionConditionStick::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uShlHitReactionSpline::getDTI() const {
    return uShlHitReactionSpline::DTI;
}

uShlHitReactionSpline::~uShlHitReactionSpline() {
}

void uShlHitReactionSpline::initSub() {
    this->uShlSpline::initSub();
    if (getOwner() == nullptr) {
        return;
    }
    mHitReaction.mCheckHitEfcCtrl[0].uId = getOwner()->mUnitParam;
    mHitReaction.mCheckHitEfcCtrl[0].clearTimer = 2.0f;
}

void uShlHitReactionSpline::updateSub() {
    this->uShlSpline::updateSub();
    mHitReaction.update(getDeltaTime());
}

__attribute__((weak)) void uShlHitReactionSpline::callbackCheck(cHitInfo* pHitInfo) {
    DDON_STUB("uShlHitReactionSpline::callbackCheck")
    /* stub */
}

inline uShlHitReactionSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlHitReactionSpline::MyDTI uShlHitReactionSpline::DTI("uShlHitReactionSpline", &::uShlSpline::DTI, 11536ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlHitReactionSpline::MyDTI::newInstance() const {
    DDON_STUB("uShlHitReactionSpline::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uShlHitReactionStick::getDTI() const {
    return uShlHitReactionStick::DTI;
}

uShlHitReactionStick::~uShlHitReactionStick() {
}

void uShlHitReactionStick::initSub() {
    this->uShlStick::initSub();
    if (getOwner() == nullptr) {
        return;
    }
    mHitReaction.mCheckHitEfcCtrl[0].uId = getOwner()->mUnitParam;
    mHitReaction.mCheckHitEfcCtrl[0].clearTimer = 2.0f;
}

void uShlHitReactionStick::updateSub() {
    this->uShlStick::updateSub();
    mHitReaction.update(getDeltaTime());
}

__attribute__((weak)) void uShlHitReactionStick::callbackCheck(cHitInfo* pHitInfo) {
    DDON_STUB("uShlHitReactionStick::callbackCheck")
    /* stub */
}

inline uShlHitReactionStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlHitReactionStick::MyDTI uShlHitReactionStick::DTI("uShlHitReactionStick", &::uShlStick::DTI, 11008ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlHitReactionStick::MyDTI::newInstance() const {
    DDON_STUB("uShlHitReactionStick::MyDTI::newInstance")
    return nullptr;
}

