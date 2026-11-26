// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlConditionJob10.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cpShlCondition.h"
#include "cpjob10.h"
#include "nObjCondition.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlComponentCtrl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompConditionJob10Cs08::getDTI() const {
    return cShlParamCompConditionJob10Cs08::DTI;
}

inline void* cShlParamCompConditionJob10Cs08::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamCompConditionJob10Cs08::DTI)->memAlloc(sz, align, cShlParamCompConditionJob10Cs08::DTI.getID());
}

inline void cShlParamCompConditionJob10Cs08::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamCompConditionJob10Cs08::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCompConditionJob10Cs08::getComponentDTI() const {
    return cpShlConditionJob10Cs08::DTI;
}

MtUI* cShlParamCompConditionJob10Cs08::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cShlParamCompConditionJob10Cs08::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompConditionJob10Cs08::MyDTI cShlParamCompConditionJob10Cs08::DTI("cShlParamCompConditionJob10Cs08", &::cShlParamCompCustomCondition::DTI, 104ul, 0u, 0u);

MtObject* cShlParamCompConditionJob10Cs08::MyDTI::newInstance() const {
    return new (16u) cShlParamCompConditionJob10Cs08;
}

const MtDTI& cpShlConditionJob10Cs08::getDTI() const {
    return cpShlConditionJob10Cs08::DTI;
}

inline void* cpShlConditionJob10Cs08::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cpShlConditionJob10Cs08::DTI)->memAlloc(sz, align, cpShlConditionJob10Cs08::DTI.getID());
}

inline void cpShlConditionJob10Cs08::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpShlConditionJob10Cs08::DTI)->memFree(p_addr);
}

__attribute__((weak)) nObjCondition::IMMUNE_BOOST_LV cpShlConditionJob10Cs08::getBoostLv() const {
    DDON_STUB("cpShlConditionJob10Cs08::getBoostLv")
    return {};
}

inline cpShlConditionJob10Cs08::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlConditionJob10Cs08::MyDTI cpShlConditionJob10Cs08::DTI("cpShlConditionJob10Cs08", &::cpShlCustomCondition::DTI, 128ul, 0u, 0u);

MtObject* cpShlConditionJob10Cs08::MyDTI::newInstance() const {
    return new (16u) cpShlConditionJob10Cs08;
}

