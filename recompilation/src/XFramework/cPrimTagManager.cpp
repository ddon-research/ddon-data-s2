// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cPrimTagManager.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cPrimObj.h"
#include "cPrimTagList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPrimTagManager::getDTI() const {
    return cPrimTagManager::DTI;
}

void* cPrimTagManager::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cPrimTagManager::DTI)->memAlloc(sz, align, cPrimTagManager::DTI.mID);
}

cPrimTagManager::cPrimTagManager(u32 size) {
    mpIndexTags = nullptr;
    mpPrimTags = nullptr;
    mSize = size;
    mNumOfTags = static_cast<u32>((static_cast<unsigned long>(size) * 0x38E38E39) >> 36);
    mpPrimTags = static_cast<cPrimTagList::PrimTag*>(MtMemoryAllocator::getAllocator(cPrimTagManager::DTI)->memAlloc(static_cast<size_t>(mNumOfTags) * 56, 16u, cPrimTagManager::DTI.mID));
    mpIndexTags = static_cast<cPrimTagList::IndexTag*>(MtMemoryAllocator::getAllocator(cPrimTagManager::DTI)->memAlloc(static_cast<size_t>(mNumOfTags) * 16, 16u, cPrimTagManager::DTI.mID));
}

cPrimTagManager::~cPrimTagManager() {
    if (mpPrimTags != nullptr) {
        MtMemoryAllocator::getAllocator(cPrimTagManager::DTI)->memFree(static_cast<void*>(mpPrimTags));
        mpPrimTags = nullptr;
    }
    if (mpIndexTags == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(cPrimTagManager::DTI)->memFree(static_cast<void*>(mpIndexTags));
    mpIndexTags = nullptr;
}

__attribute__((weak)) void cPrimTagManager::assignTags(cPrim* * p_prim, u32 prim_num) {
    DDON_STUB("cPrimTagManager::assignTags")
    /* stub */
}

inline cPrimTagManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrimTagManager::MyDTI cPrimTagManager::DTI("cPrimTagManager", &::cPrimObj::DTI, 32ul, 0u, 0u);

MtObject* cPrimTagManager::MyDTI::newInstance() const {
    return new (16u) cPrimTagManager;
}

