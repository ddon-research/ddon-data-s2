// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestMemoryPool.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestMemoryPool::getDTI() const {
    return cQuestMemoryPool::DTI;
}

void* cQuestMemoryPool::operator new(size_t sz, u32 align) {
    return cQuestMemoryPool::getAllocator()->memAlloc(sz, align, cQuestMemoryPool::DTI.getID());
}

__attribute__((weak)) nQuest::cQuestCommand* cQuestMemoryPool::allocQuestCommand(cQuestTask* pTask) {
    DDON_STUB("cQuestMemoryPool::allocQuestCommand")
    return nullptr;
}

__attribute__((weak)) void cQuestMemoryPool::freeQuestCommand(nQuest::cQuestCommand* pCommand) {
    DDON_STUB("cQuestMemoryPool::freeQuestCommand")
    /* stub */
}

__attribute__((weak)) void cQuestMemoryPool::release() {
    DDON_STUB("cQuestMemoryPool::release")
    /* stub */
}

cQuestMemoryPool::cQuestMemoryPool() {
    DDON_STUB("cQuestMemoryPool::cQuestMemoryPool")
    /* stub */
}

cQuestMemoryPool::~cQuestMemoryPool() {
    DDON_STUB("cQuestMemoryPool::~cQuestMemoryPool")
    /* stub */
}

__attribute__((weak)) void cQuestMemoryPool::createProperty(MtPropertyList& s) {
}

inline cQuestMemoryPool::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMemoryPool::MyDTI cQuestMemoryPool::DTI("cQuestMemoryPool", &::cQuestFunctionManagerBase::DTI, 0x1C210ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestMemoryPool::MyDTI::newInstance() const {
    DDON_STUB("cQuestMemoryPool::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestMemoryPool::cQuestMemoryCore::getDTI() const {
    return cQuestMemoryPool::cQuestMemoryCore::DTI;
}

cQuestMemoryPool::cQuestMemoryCore::~cQuestMemoryCore() {
}

__attribute__((weak)) void cQuestMemoryPool::cQuestMemoryCore::createProperty(MtPropertyList& s) {
}

inline cQuestMemoryPool::cQuestMemoryCore::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMemoryPool::cQuestMemoryCore::MyDTI cQuestMemoryPool::cQuestMemoryCore::DTI("cQuestMemoryPool::cQuestMemoryCore", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cQuestMemoryPool::cQuestMemoryCore::MyDTI::newInstance() const {
    return new (16u) cQuestMemoryPool::cQuestMemoryCore;
}

