// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkSessionListener.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::SessionListener::getDTI() const {
    return nNetwork::SessionListener::DTI;
}

inline void* nNetwork::SessionListener::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::SessionListener::DTI)->memAlloc(sz, align, ::nNetwork::SessionListener::DTI.mID);
}

__attribute__((weak)) void nNetwork::SessionListener::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::SessionListener::DTI)->memFree(p_addr);
}

inline nNetwork::SessionListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::SessionListener::MyDTI nNetwork::SessionListener::DTI("nNetwork::SessionListener", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* nNetwork::SessionListener::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::SessionListener;
}

