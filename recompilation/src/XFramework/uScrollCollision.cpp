// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScrollCollision.h"
#include "../MT/MtDTI.h"
#include "cUnit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uScrollCollision::getDTI() const {
    return uScrollCollision::DTI;
}

uScrollCollision::uScrollCollision() {
}

uScrollCollision::~uScrollCollision() {
}

inline uScrollCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrollCollision::MyDTI uScrollCollision::DTI("uScrollCollision", &::cUnit::DTI, 72ul, 0u, 1u);

MtObject* uScrollCollision::MyDTI::newInstance() const {
    return nullptr;
}

