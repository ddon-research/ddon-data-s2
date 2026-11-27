// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sToolExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/sTool.h"
#include "../../XFramework/sToolBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sToolExt::getDTI() const {
    return sToolExt::DTI;
}

void* sToolExt::operator new(size_t sz, u32 align) {
    return sToolExt::getAllocator()->memAlloc(sz, align, sToolExt::DTI.getID());
}

__attribute__((weak)) void sToolExt::operator delete(void* p_addr) {
    sToolExt::getAllocator()->memFree(p_addr);
}

inline sToolExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sToolExt::MyDTI sToolExt::DTI("sToolExt", &::sTool::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* sToolExt::MyDTI::newInstance() const {
    DDON_STUB("sToolExt::MyDTI::newInstance")
    return nullptr;
}

