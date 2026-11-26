// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlAlchemCol.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cComponentManager.h"
#include "cEfcHandle.h"
#include "cpJob09.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlAlchemyTrap.h"
#include "uShlBase.h"
#include "uShlEnchant.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::DTI)->memAlloc(sz, align, cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::DTI.getID());
}

inline void cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::getDTI() const {
    return cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::DTI;
}

void cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::createProperty(MtPropertyList& s) {
    this->::cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAttackShlNo", &mAttackShlNo, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyShlOption", &mAlchemyShlOption, 0, 0);
}

void cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::createPropertyEffect(MtPropertyList& s) {
    this->::cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseAreaEffect", &mFlgUseAreaEffect, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaEffectTime", &mAreaEffectTime, 0, 0);
}

inline cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::MyDTI cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::DTI("cShlParamAlchemColBase", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>;
}

inline void* cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::DTI)->memAlloc(sz, align, cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::DTI.getID());
}

inline void cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::getDTI() const {
    return cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::DTI;
}

void cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::createProperty(MtPropertyList& s) {
    this->::cShlParamEnchant::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAttackShlNo", &mAttackShlNo, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyShlOption", &mAlchemyShlOption, 0, 0);
}

void cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::createPropertyEffect(MtPropertyList& s) {
    this->::cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseAreaEffect", &mFlgUseAreaEffect, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaEffectTime", &mAreaEffectTime, 0, 0);
}

inline cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::MyDTI cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::DTI("cShlParamAlchemColEnchant", &::cShlParamEnchant::DTI, 480ul, 0u, 0u);

MtObject* cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>;
}

inline void* cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::DTI)->memAlloc(sz, align, cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::DTI.getID());
}

inline void cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::getDTI() const {
    return cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::DTI;
}

void cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::createProperty(MtPropertyList& s) {
    this->::cShlParamAlchemyTrapAttack::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAttackShlNo", &mAttackShlNo, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAlchemyShlOption", &mAlchemyShlOption, 0, 0);
}

void cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::createPropertyEffect(MtPropertyList& s) {
    this->::cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseAreaEffect", &mFlgUseAreaEffect, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaEffectTime", &mAreaEffectTime, 0, 0);
}

inline cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::MyDTI cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::DTI("cShlParamAlchemColTrapAttack", &::cShlParamAlchemyTrapAttack::DTI, 368ul, 0u, 0u);

MtObject* cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>;
}

