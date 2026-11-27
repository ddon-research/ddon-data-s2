// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cConstModelParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cConstModelParam::getDTI() const {
    return cConstModelParam::DTI;
}

void* cConstModelParam::operator new[](size_t sz, u32 align) {
    return cConstModelParam::getAllocator()->memAlloc(sz, align, cConstModelParam::DTI.getID());
}

void cConstModelParam::operator delete[](void* p_addr) {
    cConstModelParam::getAllocator()->memFree(p_addr);
}

inline cConstModelParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cConstModelParam::MyDTI cConstModelParam::DTI("cConstModelParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cConstModelParam::MyDTI::newInstance() const {
    return new (16u) cConstModelParam;
}

