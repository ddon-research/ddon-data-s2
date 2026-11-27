// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include "nDrawResource.h"
#include "../MT/MtCRC.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "sRender.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::Resource::getDTI() const {
    return nDraw::Resource::DTI;
}

nDraw::Resource::Resource() {
    mRefFrame = -1;
    mRefCount = 1;
    mCRC = 0;
}

__attribute__((weak)) bool nDraw::Resource::addRef() {
    s32 t1 = mRefCount;
    while (t1 >= 0) {
        s32 t2 = sceAtomicCompareAndSwap32(&mRefCount, t1, t1 + 1);
        if (t2 == t1) {
            return true;
        }
        t1 = mRefCount;
    }
    return false;
}

__attribute__((weak)) void nDraw::Resource::release() {
    s32 t0;
    do {
        t0 = mRefCount;
    } while (sceAtomicCompareAndSwap32(&mRefCount, t0, t0 - 1) != t0);
    const s32 rc = t0 - 1;
    if (rc != 0) {
        return;
    }
    if (mRefFrame >= mRenderFrame) {
        sRender::getInstance()->addProtectResource(this);
    } else {
        delete this;
    }
}

void nDraw::Resource::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "RefCount", &mRefCount, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRefFrame", &mRefFrame, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mCRC", &mCRC, 3u, 0u);
}

__attribute__((weak)) void nDraw::Resource::calcCRC(const void* pbuf, u32 bytes) {
    DDON_STUB("nDraw::Resource::calcCRC")
    /* stub */
}

__attribute__((weak)) void nDraw::Resource::setDmyU32(u32) {
}

__attribute__((weak)) void nDraw::Resource::setDmyBool(bool) {
}

__attribute__((weak)) bool nDraw::Resource::incRefCount() {
    s32 rc = mRefCount;
    while (rc >= 0) {
        s32 rrc = sceAtomicCompareAndSwap32(&mRefCount, rc, rc + 1);
        if (rrc == rc) {
            return true;
        }
        rc = mRefCount;
    }
    return false;
}

__attribute__((weak)) s32 nDraw::Resource::decRefCount() {
    s32 rc;
    do {
        rc = mRefCount;
    } while (sceAtomicCompareAndSwap32(&mRefCount, rc, rc - 1) != rc);
    return rc - 1;
}

__attribute__((weak)) bool nDraw::Resource::terminate(s32 destruction_seed) {
    return sceAtomicCompareAndSwap32(&mRefCount, destruction_seed, INVALID_REF) == destruction_seed;
}

inline nDraw::Resource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Resource::MyDTI nDraw::Resource::DTI("nDraw::Resource", &::MtObject::DTI, 24ul, 0u, 1u);

s32 nDraw::Resource::mRenderFrame;

s32 nDraw::Resource::mProtectFrame;

MtObject* nDraw::Resource::MyDTI::newInstance() const {
    return nullptr;
}

