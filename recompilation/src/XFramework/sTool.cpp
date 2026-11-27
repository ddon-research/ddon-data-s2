// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sTool.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive2D.h"
#include "sToolBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sTool::getDTI() const {
    return sTool::DTI;
}

__attribute__((weak)) void sTool::load(MT_CTSTR path, MtPoint spt) {
}

MT_CTSTR sTool::getPageGroupName(u32 page) {
    return "";
}

MT_CTSTR sTool::getPageName(u32 page) {
    return "";
}

inline sTool::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sTool::MyDTI sTool::DTI("sTool", &::sToolBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* sTool::MyDTI::newInstance() const {
    DDON_STUB("sTool::MyDTI::newInstance")
    return nullptr;
}

