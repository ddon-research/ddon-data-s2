// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nCharacterEdit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nCharacterEdit::cPaletteParams::getDTI() const {
    return nCharacterEdit::cPaletteParams::DTI;
}

void* nCharacterEdit::cPaletteParams::operator new(size_t sz, u32 align) {
    return ::nCharacterEdit::cPaletteParams::getAllocator()->memAlloc(sz, align, ::nCharacterEdit::cPaletteParams::DTI.getID());
}

inline nCharacterEdit::cPaletteParams::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCharacterEdit::cPaletteParams::MyDTI nCharacterEdit::cPaletteParams::DTI("cPaletteParams", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* nCharacterEdit::cPaletteParams::MyDTI::newInstance() const {
    return new (16u) ::nCharacterEdit::cPaletteParams;
}

