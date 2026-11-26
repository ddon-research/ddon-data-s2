// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlCondition.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOGame.h"
#include "nObjCondition.h"
#include "uShlBase.h"
#include "uShlFollowMove.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlConditionInfo::getDTI() const {
    return cShlConditionInfo::DTI;
}

inline MtAllocator* cShlConditionInfo::getAllocator() {
    return MtMemoryAllocator::getAllocator(cShlConditionInfo::DTI);
}

inline void* cShlConditionInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlConditionInfo::DTI)->memAlloc(sz, align, cShlConditionInfo::DTI.getID());
}

__attribute__((weak)) void cShlConditionInfo::operator delete(void* p_addr) {
    cShlConditionInfo::getAllocator()->memFree(p_addr);
}

inline cShlConditionInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlConditionInfo::MyDTI cShlConditionInfo::DTI("cShlConditionInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cShlConditionInfo::MyDTI::newInstance() const {
    return new (16u) cShlConditionInfo;
}

inline void* cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI)->memAlloc(sz, align, cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI.getID());
}

inline void cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::getDTI() const {
    return cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI;
}

void cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::createProperty(MtPropertyList& proplist) {
    this->::cShlParamBase::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "isCondition", &isCondition, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "isAdd", &isAdd, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "goodStatus", &goodStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "badStatus", &badStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "HumanOriginalStatus", &HumanOriginalStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mIsSetActiveTime", &mInfo.mIsSetActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mActiveTime", &mInfo.mActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mBoostLv", reinterpret_cast<s32*>(&mInfo.mBoostLv), 0, 0);
}

inline cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::MyDTI cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::DTI("cShlParamConditionBase", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>::MyDTI::newInstance() const {
    return new (16u) cShlParamCondition<uShlCondition<uShlBase>, cShlParamBase>;
}

inline void* cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI)->memAlloc(sz, align, cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI.getID());
}

inline void cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::getDTI() const {
    return cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI;
}

void cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::createProperty(MtPropertyList& proplist) {
    this->::cShlParamFollowMove::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "isCondition", &isCondition, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "isAdd", &isAdd, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "goodStatus", &goodStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "badStatus", &badStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "HumanOriginalStatus", &HumanOriginalStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mIsSetActiveTime", &mInfo.mIsSetActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mActiveTime", &mInfo.mActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mBoostLv", reinterpret_cast<s32*>(&mInfo.mBoostLv), 0, 0);
}

inline cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::MyDTI cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::DTI("cShlParamConditionFollowMove", &::cShlParamFollowMove::DTI, 448ul, 0u, 0u);

MtObject* cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>::MyDTI::newInstance() const {
    return new (16u) cShlParamCondition<uShlCondition<uShlFollowMove>, cShlParamFollowMove>;
}

inline void* cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI)->memAlloc(sz, align, cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI.getID());
}

inline void cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::getDTI() const {
    return cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI;
}

void cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::createProperty(MtPropertyList& proplist) {
    this->::cShlParamStick::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "isCondition", &isCondition, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "isAdd", &isAdd, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "goodStatus", &goodStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "badStatus", &badStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "HumanOriginalStatus", &HumanOriginalStatus, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mIsSetActiveTime", &mInfo.mIsSetActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mActiveTime", &mInfo.mActiveTime, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mInfo.mBoostLv", reinterpret_cast<s32*>(&mInfo.mBoostLv), 0, 0);
}

inline cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::MyDTI cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::DTI("cShlParamConditionStick", &::cShlParamStick::DTI, 416ul, 0u, 0u);

MtObject* cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>::MyDTI::newInstance() const {
    return new (16u) cShlParamCondition<uShlCondition<uShlStick>, cShlParamStick>;
}

