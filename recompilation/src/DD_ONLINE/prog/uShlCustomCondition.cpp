// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlCustomCondition.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "nHumanMsg.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlCondition.h"
#include "uShlFollowMove.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCustomConditionBase::getDTI() const {
    return cShlParamCustomConditionBase::DTI;
}

inline void cShlParamCustomConditionBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCustomConditionBase::DTI)->memFree(p_addr);
}

MtDTI& cShlParamCustomConditionBase::getShlDTI() const {
    return uShlCustomConditionBase::DTI;
}

__attribute__((weak)) void cShlParamCustomConditionBase::createProperty(MtPropertyList& proplist) {
    this->::cShlParamConditionBase::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mMyCustomSkillId", &mMyCustomSkillId, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[0]", &mHosei[0], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[1]", &mHosei[1], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[2]", &mHosei[2], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[3]", &mHosei[3], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[4]", &mHosei[4], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[5]", &mHosei[5], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[6]", &mHosei[6], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[7]", &mHosei[7], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[8]", &mHosei[8], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[9]", &mHosei[9], 0, 0);
}

__attribute__((weak)) void cShlParamCustomConditionBase::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamCustomConditionBase::copy")
    /* stub */
}

inline cShlParamCustomConditionBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCustomConditionBase::MyDTI cShlParamCustomConditionBase::DTI("cShlParamCustomConditionBase", &::cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI, 448ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamCustomConditionBase::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamCustomConditionBase::DTI)->memAlloc(sizeof(cShlParamCustomConditionBase), 16u, cShlParamCustomConditionBase::DTI.getID())) cShlParamCustomConditionBase;
}

const MtDTI& cShlParamCustomConditionFollowMove::getDTI() const {
    return cShlParamCustomConditionFollowMove::DTI;
}

inline void cShlParamCustomConditionFollowMove::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCustomConditionFollowMove::DTI)->memFree(p_addr);
}

MtDTI& cShlParamCustomConditionFollowMove::getShlDTI() const {
    return uShlCustomConditionFollowMove::DTI;
}

__attribute__((weak)) void cShlParamCustomConditionFollowMove::createProperty(MtPropertyList& proplist) {
    this->::cShlParamConditionFollowMove::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mMyCustomSkillId", &mMyCustomSkillId, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[0]", &mHosei[0], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[1]", &mHosei[1], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[2]", &mHosei[2], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[3]", &mHosei[3], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[4]", &mHosei[4], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[5]", &mHosei[5], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[6]", &mHosei[6], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[7]", &mHosei[7], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[8]", &mHosei[8], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHosei[9]", &mHosei[9], 0, 0);
}

__attribute__((weak)) void cShlParamCustomConditionFollowMove::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamCustomConditionFollowMove::copy")
    /* stub */
}

inline cShlParamCustomConditionFollowMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCustomConditionFollowMove::MyDTI cShlParamCustomConditionFollowMove::DTI("cShlParamCustomConditionFollowMove", &::cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI, 496ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamCustomConditionFollowMove::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamCustomConditionFollowMove::DTI)->memAlloc(sizeof(cShlParamCustomConditionFollowMove), 16u, cShlParamCustomConditionFollowMove::DTI.getID())) cShlParamCustomConditionFollowMove;
}

const MtDTI& uShlCustomConditionBase::getDTI() const {
    return uShlCustomConditionBase::DTI;
}

inline void uShlCustomConditionBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlCustomConditionBase::DTI)->memFree(p_addr);
}

__attribute__((weak)) void uShlCustomConditionBase::initSub() {
    DDON_STUB("uShlCustomConditionBase::initSub")
    /* stub */
}

__attribute__((weak)) MtObject* uShlCustomConditionBase::MyDTI::newInstance() const {
    DDON_STUB("uShlCustomConditionBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uShlCustomConditionFollowMove::getDTI() const {
    return uShlCustomConditionFollowMove::DTI;
}

inline void uShlCustomConditionFollowMove::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlCustomConditionFollowMove::DTI)->memFree(p_addr);
}

__attribute__((weak)) void uShlCustomConditionFollowMove::initSub() {
    DDON_STUB("uShlCustomConditionFollowMove::initSub")
    /* stub */
}

__attribute__((weak)) MtObject* uShlCustomConditionFollowMove::MyDTI::newInstance() const {
    DDON_STUB("uShlCustomConditionFollowMove::MyDTI::newInstance")
    return nullptr;
}

