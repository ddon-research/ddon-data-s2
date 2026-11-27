// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkCallback.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "nNetworkQueue.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nNetwork::Callback::Callback() {
    DDON_STUB("nNetwork::Callback::Callback")
    /* stub */
}

__attribute__((noinline)) nNetwork::Callback::~Callback() {
    DDON_STUB("nNetwork::Callback::~Callback")
    /* stub */
}

const MtDTI& nNetwork::Callback::getDTI() const {
    return nNetwork::Callback::DTI;
}

void nNetwork::Callback::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mBuffering", &mBuffering, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSmoothing", &mSmoothing, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSelfBuffering", &mSelfBuffering, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSelfDelay", &mSelfDelay, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSelfBufferSize", &mSelfBufferSize, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mQueue", static_cast<MtObject*>(&mQueue[0]), 32u, 16u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSelfQueue", static_cast<MtObject*>(&mSelfQueue), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mEntry", static_cast<MtObject*>(&mEntry[0]), 32u, 16u);
}

MtUI* nNetwork::Callback::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nNetwork::Callback::setup(nNetwork::Session* ps) {
    mpSession = ps;
}

__attribute__((weak)) bool nNetwork::Callback::receive(u32 callback_index, s32 route_index, s32 member_index, const void* data_ptr, u32 data_size) {
    DDON_STUB("nNetwork::Callback::receive")
    return {};
}

void nNetwork::Callback::set(s32 index, nNetwork::ReceiverBase* r, bool buffering, bool route) {
    if (r != nullptr) {
        ::__atomic_fetch_add(&r->mRefCount, 1, __ATOMIC_SEQ_CST);
    }
    mEntry[index].mpReceiver = r;
    mEntry[index].mBuffering = buffering;
    mEntry[index].mRoute = route;
}

void nNetwork::Callback::clear(s32 index) {
    if (mEntry[index].mpReceiver != nullptr) {
        ::__atomic_fetch_add(&mEntry[index].mpReceiver->mRefCount, -1, __ATOMIC_SEQ_CST);
    }
    mEntry[index].mpReceiver = nullptr;
    mEntry[index].mBuffering = false;
    mEntry[index].mRoute = false;
}

void nNetwork::Callback::removeRoute(s32 route_index) {
    mQueue[route_index].clear();
}

__attribute__((weak)) void nNetwork::Callback::begin() {
    DDON_STUB("nNetwork::Callback::begin")
    /* stub */
}

__attribute__((weak)) void nNetwork::Callback::move() {
    DDON_STUB("nNetwork::Callback::move")
    /* stub */
}

__attribute__((weak)) bool nNetwork::Callback::shift(nNetwork::Callback::Queue& queue) {
    DDON_STUB("nNetwork::Callback::shift")
    return {};
}

inline nNetwork::Callback::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Callback::MyDTI nNetwork::Callback::DTI("nNetwork::Callback", &::MtObject::DTI, 6120ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::Callback::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::Callback::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::Callback::Entry::getDTI() const {
    return nNetwork::Callback::Entry::DTI;
}

void nNetwork::Callback::Entry::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_CLASSREF, "Parent", reinterpret_cast<MT_MFUNC>(&::nNetwork::Callback::Entry::getClass), reinterpret_cast<MT_MFUNC>(&::nNetwork::Callback::Entry::setClass), 147u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mBuffering", &mBuffering, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRoute", &mRoute, 0u, 0u);
}

MtObject* nNetwork::Callback::Entry::getClass() {
    if (mpReceiver != nullptr) {
        return mpReceiver->mpObject;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void nNetwork::Callback::Entry::setClass(MtObject* pobj) {
}

inline nNetwork::Callback::Entry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Callback::Entry::MyDTI nNetwork::Callback::Entry::DTI("nNetwork::Callback::Entry", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* nNetwork::Callback::Entry::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::Callback::Entry;
}

const MtDTI& nNetwork::Callback::Queue::getDTI() const {
    return nNetwork::Callback::Queue::DTI;
}

void nNetwork::Callback::Queue::createProperty(MtPropertyList& s) {
    this->::nNetwork::BlockQueue::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRate", &mRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mCall", &mCall, 0u, 0u);
}

inline nNetwork::Callback::Queue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Callback::Queue::MyDTI nNetwork::Callback::Queue::DTI("nNetwork::Callback::Queue", &::nNetwork::BlockQueue::DTI, 336ul, 0u, 0u);

MtObject* nNetwork::Callback::Queue::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::Callback::Queue;
}

__attribute__((weak)) bool nNetwork::Callback::SelfQueue::push(const void* data_ptr, u32 data_size, const nNetwork::Callback::SelfHeader& header) {
    DDON_STUB("nNetwork::Callback::SelfQueue::push")
    return {};
}

