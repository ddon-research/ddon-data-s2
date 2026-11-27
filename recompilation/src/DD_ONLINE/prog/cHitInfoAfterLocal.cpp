// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cHitInfoAfterLocal.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHitInfoAfterLocal::getDTI() const {
    return cHitInfoAfterLocal::DTI;
}

__attribute__((weak)) void cHitInfoAfterLocal::operator delete(void* p_addr) {
    cHitInfoAfterLocal::getAllocator()->memFree(p_addr);
}

inline cHitInfoAfterLocal::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHitInfoAfterLocal::MyDTI cHitInfoAfterLocal::DTI("cHitInfoAfterLocal", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cHitInfoAfterLocal::MyDTI::newInstance() const {
    return new (16u) cHitInfoAfterLocal;
}

