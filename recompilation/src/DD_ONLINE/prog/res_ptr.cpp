// Reconstructed from the game's DWARF debug information.
#include <new>
#include "res_ptr.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void cResPtrBase::setPtr(cResource* & pDst, cResource* pRes) {
    if (pDst == pRes) {
        return;
    }
    if (pDst != nullptr) {
        pDst->cResource::release();
        pDst = nullptr;
    }
    pDst = pRes;
    if (pRes != nullptr) {
        pRes->addRef();
    }
}

void cResPtrBase::releasePtr(cResource* & pRes) {
    if ((pRes) == nullptr) {
        return;
    }
    (pRes)->cResource::release();
    pRes = nullptr;
}

