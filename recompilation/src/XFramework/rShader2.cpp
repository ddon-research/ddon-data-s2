// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rShader2.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#include "nDrawShader.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rShader2::usage() {
}

const MtDTI& rShader2::getDTI() const {
    return rShader2::DTI;
}

rShader2::~rShader2() {
    mpObjects = nullptr;
    this->rShader2::clear();
}

MT_CTSTR rShader2::getExt() const {
    return "mfx";
}

__attribute__((weak)) bool rShader2::load(MtStream& in) {
    DDON_STUB("rShader2::load")
    return {};
}

__attribute__((weak)) void rShader2::clear() {
    DDON_STUB("rShader2::clear")
    /* stub */
}

MtUI* rShader2::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rShader2::freeVariable(nDraw::VARIABLE* pval) {
    if (pval->annotation_num > 0u) {
        for (unsigned int i0_3 = 0;;) {
            freeVariable(&pval->annotations[i0_3]);
            if ((i0_3 + 1u) < pval->annotation_num) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    nDraw::VARIABLE* t0 = pval->annotations;
    MtMemoryAllocator::getAllocator(rShader2::DTI)->memFree(static_cast<void*>(t0));
    void* t1 = pval->pinitvalues;
    MtMemoryAllocator::getAllocator(rShader2::DTI)->memFree(t1);
}

__attribute__((weak)) void rShader2::freeStatement(void* pstt) {
    DDON_STUB("rShader2::freeStatement")
    /* stub */
}

__attribute__((weak)) void rShader2::mapVariables(nDraw::VARIABLE* vals, u32 num) {
    DDON_STUB("rShader2::mapVariables")
    /* stub */
}

__attribute__((weak)) void rShader2::mapStatement(void* pstt) {
    DDON_STUB("rShader2::mapStatement")
    /* stub */
}

__attribute__((weak)) void rShader2::mapInitValues(u32* pinitvalues, nDraw::VARIABLE* pval) {
    DDON_STUB("rShader2::mapInitValues")
    /* stub */
}

inline rShader2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShader2::MyDTI rShader2::DTI("rShader2", &::cResource::DTI, 136ul, 0u, 0u);

MtObject* rShader2::MyDTI::newInstance() const {
    return new (16u) rShader2;
}

