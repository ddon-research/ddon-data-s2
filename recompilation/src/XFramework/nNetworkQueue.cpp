// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkQueue.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "nNetworkCallback.h"
#include "nNetworkProtocol.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::BlockBuffer::getDTI() const {
    return nNetwork::BlockBuffer::DTI;
}

inline void* nNetwork::BlockBuffer::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::BlockBuffer::DTI)->memAlloc(sz, align, ::nNetwork::BlockBuffer::DTI.mID);
}

inline void nNetwork::BlockBuffer::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::BlockBuffer::DTI)->memFree(p_addr);
}

nNetwork::BlockBuffer::~BlockBuffer() {
    mHead = mTail;
    adjust(0u);
}

void nNetwork::BlockBuffer::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mBlockMax", &mBlockMax, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "Length", reinterpret_cast<MT_MFUNC>(&::nNetwork::BlockBuffer::length), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void nNetwork::BlockBuffer::init(nNetwork::BlockPool* pool, u32 block_max, void* * block_list) {
    DDON_STUB("nNetwork::BlockBuffer::init")
    /* stub */
}

__attribute__((weak)) u32 nNetwork::BlockBuffer::length() const {
    DDON_STUB("nNetwork::BlockBuffer::length")
    return {};
}

bool nNetwork::BlockBuffer::empty() const {
    return mHead == mTail;
}

__attribute__((weak)) bool nNetwork::BlockBuffer::adjust(u32 data_size) {
    DDON_STUB("nNetwork::BlockBuffer::adjust")
    return {};
}

inline nNetwork::BlockBuffer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::BlockBuffer::MyDTI nNetwork::BlockBuffer::DTI("nNetwork::BlockBuffer", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* nNetwork::BlockBuffer::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::BlockBuffer;
}

const MtDTI& nNetwork::BlockPool::getDTI() const {
    return nNetwork::BlockPool::DTI;
}

nNetwork::BlockPool::BlockPool() {
    DDON_STUB("nNetwork::BlockPool::BlockPool")
    /* stub */
}

nNetwork::BlockPool::~BlockPool() {
    DDON_STUB("nNetwork::BlockPool::~BlockPool")
    /* stub */
}

__attribute__((weak)) void nNetwork::BlockPool::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void nNetwork::BlockPool::init(MtAllocator* alloc, u32 pool_size) {
    DDON_STUB("nNetwork::BlockPool::init")
    /* stub */
}

void nNetwork::BlockPool::final() {
    if (mAutoFree) {
        mpPoolAllocator->memFree(mpPool);
    }
    mpPool = nullptr;
    mAutoFree = false;
    mHead = 0;
    mTail = 0;
    mPoolSize = 0;
    mPoolCount = 0;
    mpBlock = nullptr;
    mpPoolAllocator = nullptr;
}

__attribute__((weak)) void* nNetwork::BlockPool::allocate() {
    DDON_STUB("nNetwork::BlockPool::allocate")
    return nullptr;
}

__attribute__((weak)) void nNetwork::BlockPool::free(void* pblock) {
    DDON_STUB("nNetwork::BlockPool::free")
    /* stub */
}

inline nNetwork::BlockPool::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::BlockPool::MyDTI nNetwork::BlockPool::DTI("nNetwork::BlockPool", &::MtObject::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::BlockPool::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::BlockPool::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::BlockQueue::getDTI() const {
    return nNetwork::BlockQueue::DTI;
}

__attribute__((weak)) void nNetwork::BlockQueue::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::BlockQueue::DTI)->memFree(p_addr);
}

nNetwork::BlockQueue::BlockQueue() {
    DDON_STUB("nNetwork::BlockQueue::BlockQueue")
    /* stub */
}

nNetwork::BlockQueue::~BlockQueue() {
    DDON_STUB("nNetwork::BlockQueue::~BlockQueue")
    /* stub */
}

void nNetwork::BlockQueue::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mBlockMax", &mBlockMax, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "Length", reinterpret_cast<MT_MFUNC>(&::nNetwork::BlockBuffer::length), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mCount", &mCount, 1u, 0u);
}

__attribute__((weak)) bool nNetwork::BlockQueue::push(const void* data_ptr, u32 data_size) {
    DDON_STUB("nNetwork::BlockQueue::push")
    return {};
}

__attribute__((weak)) bool nNetwork::BlockQueue::shift(void* data_ptr, u32& data_size) {
    DDON_STUB("nNetwork::BlockQueue::shift")
    return {};
}

__attribute__((weak)) bool nNetwork::BlockQueue::shift() {
    DDON_STUB("nNetwork::BlockQueue::shift")
    return {};
}

__attribute__((weak)) s32 nNetwork::BlockQueue::seek(u32 index) {
    DDON_STUB("nNetwork::BlockQueue::seek")
    return {};
}

__attribute__((weak)) bool nNetwork::BlockQueue::peek(void* data_ptr, u32& data_size) const {
    DDON_STUB("nNetwork::BlockQueue::peek")
    return {};
}

__attribute__((weak)) bool nNetwork::BlockQueue::peek(MtStream& stream) const {
    DDON_STUB("nNetwork::BlockQueue::peek")
    return {};
}

__attribute__((weak)) bool nNetwork::BlockQueue::overwrite(const void* data_ptr, u32& data_size) {
    DDON_STUB("nNetwork::BlockQueue::overwrite")
    return {};
}

bool nNetwork::BlockQueue::adjust(u32 total, u32 num) {
    return this->::nNetwork::BlockBuffer::adjust(total + (num * 4u));
}

void nNetwork::BlockQueue::clear() {
    mCount = 0;
    mIndex = -1;
    mSeek = 0;
    mHead = mTail;
    this->::nNetwork::BlockBuffer::adjust(0u);
}

inline nNetwork::BlockQueue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::BlockQueue::MyDTI nNetwork::BlockQueue::DTI("nNetwork::BlockQueue", &::nNetwork::BlockBuffer::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::BlockQueue::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::BlockQueue::MyDTI::newInstance")
    return nullptr;
}

