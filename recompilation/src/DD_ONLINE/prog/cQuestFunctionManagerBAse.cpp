// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestFunctionManagerBAse.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestFunctionManagerBase::getDTI() const {
    return cQuestFunctionManagerBase::DTI;
}

__attribute__((weak)) void cQuestFunctionManagerBase::release() {
}

cQuestFunctionManagerBase::cQuestFunctionManagerBase() {
}

cQuestFunctionManagerBase::~cQuestFunctionManagerBase() {
}

__attribute__((weak)) void cQuestFunctionManagerBase::createProperty(MtPropertyList& s) {
}

inline cQuestFunctionManagerBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestFunctionManagerBase::MyDTI cQuestFunctionManagerBase::DTI("cQuestFunctionManagerBase", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cQuestFunctionManagerBase::MyDTI::newInstance() const {
    return new (16u) cQuestFunctionManagerBase;
}

