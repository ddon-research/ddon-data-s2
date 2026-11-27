// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlAlchemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cEfcHandle.h"
#include "cHitNode.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpDDMrlMgr.h"
#include "cpEffectProvider.h"
#include "cpJob09.h"
#include "cpObjCollision.h"
#include "nShlStick.h"
#include "rAttackParam.h"
#include "rCollNode.h"
#include "rObjCollision.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamAlchemy::getDTI() const {
    return cShlParamAlchemy::DTI;
}

inline void cShlParamAlchemy::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamAlchemy::DTI)->memFree(p_addr);
}

MtDTI& cShlParamAlchemy::getShlDTI() const {
    return uShlAlchemy::DTI;
}

__attribute__((weak)) void cShlParamAlchemy::createProperty(MtPropertyList& s) {
    this->cShlParamStick::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mReduceAlchemyValueTime", &mReduceAlchemyValueTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSubAlchemyValueOnce", &mSubAlchemyValueOnce, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSubAlchemyValueTime", &mSubAlchemyValueTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyEvaRate", &mAlchemyEvaRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyType", &mAlchemyType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChipScale", &mChipScale[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckedCollsiionIndexForCS13", &mCheckedCollsiionIndexForCS13, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyEvaMin", &mAlchemyEvaMin, 0u, 0u);
}

void cShlParamAlchemy::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxValueRequestSe", &mMaxValueRequestSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxValueLoopSe", &mMaxValueLoopSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxValueLoopStopSe", &mMaxValueLoopStopSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxPartsDownSe", &mMaxPartsDownSe, 0u, 0u);
}

cShlParamAlchemy::~cShlParamAlchemy() {
}

__attribute__((weak)) void cShlParamAlchemy::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamAlchemy::copy")
    /* stub */
}

inline cShlParamAlchemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemy::MyDTI cShlParamAlchemy::DTI("cShlParamAlchemy", &::cShlParamStick::DTI, 416ul, 0u, 0u);

MtObject* cShlParamAlchemy::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemy;
}

const MtDTI& cShlParamAlchemyCS03::getDTI() const {
    return cShlParamAlchemyCS03::DTI;
}

MtDTI& cShlParamAlchemyCS03::getShlDTI() const {
    return uShlAlchemyCS03::DTI;
}

__attribute__((noinline)) cShlParamAlchemyCS03::~cShlParamAlchemyCS03() {
    for (u32 i = 0; i < mArrDamageAlchemyInfo.mLength; i++) {
        delete mArrDamageAlchemyInfo.mpArray[i];
    }
    if (mArrDamageAlchemyInfo.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mArrDamageAlchemyInfo.mpArray));
    }
    mArrDamageAlchemyInfo.mpArray = nullptr;
    mArrDamageAlchemyInfo.mBufsiz = 0;
    mArrDamageAlchemyInfo.mLength = 0;
}

__attribute__((weak)) void cShlParamAlchemyCS03::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamAlchemyCS03::copy")
    /* stub */
}

void cShlParamAlchemyCS03::createProperty(MtPropertyList& s) {
    this->cShlParamAlchemy::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDamageAlchemyMaxTimer", &mDamageAlchemyMaxTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSlaveDispOffTimer", &mSlaveDispOffTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mArrDamageAlchemyInfo", static_cast<MtObject*>(&mArrDamageAlchemyInfo), 0u, 0u);
}

inline cShlParamAlchemyCS03::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyCS03::MyDTI cShlParamAlchemyCS03::DTI("cShlParamAlchemyCS03", &::cShlParamAlchemy::DTI, 464ul, 0u, 0u);

MtObject* cShlParamAlchemyCS03::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemyCS03;
}

const MtDTI& cShlParamAlchemyCS03::cDamageAlchemyValueInfo::getDTI() const {
    return cShlParamAlchemyCS03::cDamageAlchemyValueInfo::DTI;
}

void cShlParamAlchemyCS03::cDamageAlchemyValueInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mMinRate", &mMinRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxRate", &mMaxRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyValue", &mAlchemyValue, 0u, 0u);
}

inline cShlParamAlchemyCS03::cDamageAlchemyValueInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyCS03::cDamageAlchemyValueInfo::MyDTI cShlParamAlchemyCS03::cDamageAlchemyValueInfo::DTI("cShlParamAlchemyCS03::cDamageAlchemyValueInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cShlParamAlchemyCS03::cDamageAlchemyValueInfo::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemyCS03::cDamageAlchemyValueInfo;
}

const MtDTI& uShlAlchemy::getDTI() const {
    return uShlAlchemy::DTI;
}

const cShlParamAlchemy* uShlAlchemy::getShlParam() const {
    return static_cast<const cShlParamAlchemy*>(getShlParamBase());
}

uShlAlchemy::~uShlAlchemy() {
}

__attribute__((weak)) void uShlAlchemy::setup() {
    DDON_STUB("uShlAlchemy::setup")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::updateSub() {
    DDON_STUB("uShlAlchemy::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::initSub() {
    DDON_STUB("uShlAlchemy::initSub")
    /* stub */
}

void uShlAlchemy::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpAlchemyMaxEfcHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpAlchemyMaxEfcHandle)) {
        return;
    }
    mpAlchemyMaxEfcHandle->mpOwner = nullptr;
    mpAlchemyMaxEfcHandle = nullptr;
}

void uShlAlchemy::kill() {
    if (mpAlchemyMaxEfcHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpAlchemyMaxEfcHandle, 4u);
        mpAlchemyMaxEfcHandle = nullptr;
    }
    if (mMaxLvGrow) {
        if (getShlParamBase() != nullptr) {
            requestSE(static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 404)), static_cast<uCoord*>(this));
            mFlgMaxGrowLoopSeRequest = false;
        }
    }
    this->uShlBase::kill();
}

__attribute__((weak)) void uShlAlchemy::addAlchemyValue(f32 value, bool flg_add_value) {
    DDON_STUB("uShlAlchemy::addAlchemyValue")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::resetReduceTime() {
    DDON_STUB("uShlAlchemy::resetReduceTime")
    /* stub */
}

void uShlAlchemy::evAlchemyValueZero() {
    requestKill();
}

__attribute__((weak)) void uShlAlchemy::updateStickAngle() {
    DDON_STUB("uShlAlchemy::updateStickAngle")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::updateAlchemyModel(bool flg_add_value) {
    DDON_STUB("uShlAlchemy::updateAlchemyModel")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::eventMaxLvGrow() {
    DDON_STUB("uShlAlchemy::eventMaxLvGrow")
    /* stub */
}

__attribute__((weak)) void uShlAlchemy::callbackChecked(cHitInfo* pHitInfo) {
    DDON_STUB("uShlAlchemy::callbackChecked")
    /* stub */
}

inline uShlAlchemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlAlchemy::MyDTI uShlAlchemy::DTI("uShlAlchemy", &::uShlStick::DTI, 10960ul, 0u, 0u);

MtObject* uShlAlchemy::MyDTI::newInstance() const {
    return new (16u) uShlAlchemy;
}

const MtDTI& uShlAlchemyCS03::getDTI() const {
    return uShlAlchemyCS03::DTI;
}

__attribute__((weak)) void uShlAlchemyCS03::setup() {
    DDON_STUB("uShlAlchemyCS03::setup")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyCS03::updateSub() {
    DDON_STUB("uShlAlchemyCS03::updateSub")
    /* stub */
}

void uShlAlchemyCS03::callbackDamage(cHitInfo* pHitInfo) {
    this->uShlBase::callbackDamage(pHitInfo);
    checkDamageAlchemy(pHitInfo);
}

__attribute__((weak)) void uShlAlchemyCS03::checkDamageAlchemy(cHitInfo* pHitInfo) {
    DDON_STUB("uShlAlchemyCS03::checkDamageAlchemy")
    /* stub */
}

void uShlAlchemyCS03::evAlchemyValueZero() {
    mPartsDisp[14] = 0;
    mPartsDisp[15] = 0;
    mPartsDisp[12] = 0;
    mPartsDisp[13] = 0;
    mPartsDisp[10] = 0;
    mPartsDisp[11] = 0;
    mPartsDisp[8] = 0;
    mPartsDisp[9] = 0;
    mPartsDisp[6] = 0;
    mPartsDisp[7] = 0;
    mPartsDisp[4] = 0;
    mPartsDisp[5] = 0;
    mPartsDisp[2] = 0;
    mPartsDisp[3] = 0;
    mPartsDisp[0] = 0;
    mPartsDisp[1] = 0;
}

__attribute__((weak)) void uShlAlchemyCS03::initSub() {
    DDON_STUB("uShlAlchemyCS03::initSub")
    /* stub */
}

inline uShlAlchemyCS03::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlAlchemyCS03::MyDTI uShlAlchemyCS03::DTI("uShlAlchemyCS03", &::uShlAlchemy::DTI, 10976ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlAlchemyCS03::MyDTI::newInstance() const {
    DDON_STUB("uShlAlchemyCS03::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cShlParamAlchemyCS03::cDamageAlchemyValueInfo>::~MtTypedArray();

