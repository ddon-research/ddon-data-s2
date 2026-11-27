// Reconstructed from the game's DWARF debug information.
#include <new>
#include "JobOrbTree.h"
#include "Common.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataJobOrbDevoteElement::getDTI() const {
    return CDataJobOrbDevoteElement::DTI;
}

void* CDataJobOrbDevoteElement::operator new(size_t sz, u32 align) {
    return CDataJobOrbDevoteElement::getAllocator()->memAlloc(sz, align, CDataJobOrbDevoteElement::DTI.getID());
}

__attribute__((weak)) void CDataJobOrbDevoteElement::operator delete(void* p_addr) {
    CDataJobOrbDevoteElement::getAllocator()->memFree(p_addr);
}

inline CDataJobOrbDevoteElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataJobOrbDevoteElement::MyDTI CDataJobOrbDevoteElement::DTI("CDataJobOrbDevoteElement", &::CPacketDataBase::DTI, 112ul, 0u, 0u);

MtObject* CDataJobOrbDevoteElement::MyDTI::newInstance() const {
    return new (16u) CDataJobOrbDevoteElement;
}

const MtDTI& CDataJobOrbTreeStatus::getDTI() const {
    return CDataJobOrbTreeStatus::DTI;
}

void* CDataJobOrbTreeStatus::operator new(size_t sz, u32 align) {
    return CDataJobOrbTreeStatus::getAllocator()->memAlloc(sz, align, CDataJobOrbTreeStatus::DTI.getID());
}

__attribute__((weak)) void CDataJobOrbTreeStatus::operator delete(void* p_addr) {
    CDataJobOrbTreeStatus::getAllocator()->memFree(p_addr);
}

inline CDataJobOrbTreeStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataJobOrbTreeStatus::MyDTI CDataJobOrbTreeStatus::DTI("CDataJobOrbTreeStatus", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataJobOrbTreeStatus::MyDTI::newInstance() const {
    return new (16u) CDataJobOrbTreeStatus;
}

