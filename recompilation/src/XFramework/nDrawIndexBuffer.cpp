// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nDrawIndexBuffer.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "nDrawBuffer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::IndexBuffer::getDTI() const {
    return nDraw::IndexBuffer::DTI;
}

void* nDraw::IndexBuffer::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::IndexBuffer::DTI)->memAlloc(sz, align, ::nDraw::IndexBuffer::DTI.mID);
}

nDraw::IndexBuffer::IndexBuffer(u32 size, nDraw::USAGE_TYPE usage, const void* pinitvalues) : nDraw::Buffer(usage) {
    mBufSize = size;
    mpBuffer = nullptr;
    void* t0 = ::MtMemory::mpAllocatorType[6]->memAlloc(size, 4u);
    mpBuffer = t0;
    if (pinitvalues == nullptr) {
        return;
    }
    ::memcpy(t0, pinitvalues, size);
}

__attribute__((weak)) void nDraw::IndexBuffer::suspend() {
}

__attribute__((weak)) void nDraw::IndexBuffer::resume() {
}

void* nDraw::IndexBuffer::map(nDraw::MAP_TYPE type) {
    return mpBuffer;
}

__attribute__((weak)) void nDraw::IndexBuffer::unmap() {
}

nDraw::IndexBuffer::~IndexBuffer() {
    if (mpBuffer != nullptr) {
        ::MtMemory::mpAllocatorType[6]->memFree(mpBuffer);
    }
    mpBuffer = nullptr;
    mpIndexBuffer = nullptr;
}

inline nDraw::IndexBuffer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::IndexBuffer::MyDTI nDraw::IndexBuffer::DTI("nDraw::IndexBuffer", &::nDraw::Buffer::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::IndexBuffer::MyDTI::newInstance() const {
    DDON_STUB("nDraw::IndexBuffer::MyDTI::newInstance")
    return nullptr;
}

