// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContext.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtString.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nCaplink::ContextListener::getDTI() const {
    return nCaplink::ContextListener::DTI;
}

inline void* nCaplink::ContextListener::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContextListener::DTI)->memAlloc(sz, align, ::nCaplink::ContextListener::DTI.mID);
}

__attribute__((weak)) void nCaplink::ContextListener::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ContextListener::DTI)->memFree(p_addr);
}

nCaplink::ContextListener::ContextListener() {
    mStatus = 0;
}

nCaplink::ContextListener::~ContextListener() {
    DDON_STUB("nCaplink::ContextListener::~ContextListener")
    /* stub */
}

void nCaplink::ContextListener::init() {
    mStatus = 0;
    mErrorType = 0;
    mErrorCode = 0;
    if (mDetailMessage.value == nullptr) {
        return;
    }
    if (static_cast<const void*>("") == static_cast<const void*>(&mDetailMessage.value->str)) {
        return;
    }
    if (::__atomic_fetch_add(&mDetailMessage.value->ref, -1, __ATOMIC_SEQ_CST) == 1) {
        (::MtString::mpAllocator)->memFree(static_cast<void*>(mDetailMessage.value));
    }
    mDetailMessage.value = nullptr;
}

inline nCaplink::ContextListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContextListener::MyDTI nCaplink::ContextListener::DTI("ContextListener", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nCaplink::ContextListener::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContextListener;
}

