// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkSharedMemory2.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStlAllocator.h"
#include "../MT/MtStlCustom.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "nNetworkCoder.h"
#include "nNetworkSession.h"
#include "nNetworkSessionListener.h"
#include "sNetwork.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::nSharedMemory2::CConsistentHash::getDTI() const {
    return nNetwork::nSharedMemory2::CConsistentHash::DTI;
}

nNetwork::nSharedMemory2::CConsistentHash::~CConsistentHash() {
    DDON_STUB("nNetwork::nSharedMemory2::CConsistentHash::~CConsistentHash")
    /* stub */
}

__attribute__((weak)) void nNetwork::nSharedMemory2::CConsistentHash::clear() {
    DDON_STUB("nNetwork::nSharedMemory2::CConsistentHash::clear")
    /* stub */
}

inline nNetwork::nSharedMemory2::CConsistentHash::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::nSharedMemory2::CConsistentHash::MyDTI nNetwork::nSharedMemory2::CConsistentHash::DTI("nNetwork::nSharedMemory2::CConsistentHash", &::MtObject::DTI, 18472ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::nSharedMemory2::CConsistentHash::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::nSharedMemory2::CConsistentHash::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::nSharedMemory2::CNode::getDTI() const {
    return nNetwork::nSharedMemory2::CNode::DTI;
}

inline nNetwork::nSharedMemory2::CNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::nSharedMemory2::CNode::MyDTI nNetwork::nSharedMemory2::CNode::DTI("nNetwork::nSharedMemory2::CNode", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::nSharedMemory2::CNode::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::nSharedMemory2::CNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::nSharedMemory2::CProtocol::getDTI() const {
    return nNetwork::nSharedMemory2::CProtocol::DTI;
}

void nNetwork::nSharedMemory2::CProtocol::get(s32 src_index, const void* data, u32 data_size) {
    if (!mInit) {
        return;
    }
    if (mpParent == nullptr) {
        return;
    }
    mpParent->receive(src_index, data, data_size);
}

inline nNetwork::nSharedMemory2::CProtocol::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::nSharedMemory2::CProtocol::MyDTI nNetwork::nSharedMemory2::CProtocol::DTI("nNetwork::nSharedMemory2::CProtocol", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* nNetwork::nSharedMemory2::CProtocol::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::nSharedMemory2::CProtocol;
}

const MtDTI& nNetwork::nSharedMemory2::CRecord::getDTI() const {
    return nNetwork::nSharedMemory2::CRecord::DTI;
}

inline nNetwork::nSharedMemory2::CRecord::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::nSharedMemory2::CRecord::MyDTI nNetwork::nSharedMemory2::CRecord::DTI("nNetwork::nSharedMemory2::CRecord", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nNetwork::nSharedMemory2::CRecord::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::nSharedMemory2::CRecord;
}

void nNetwork::nSharedMemory2::CSessionListener::onLeaveMember(s32 index, MtNetSession::Member* member) {
    if (mpParent->mRecordMap.mListNum != 0) {
        unsigned int i0_3 = 0;
        nNetwork::nSharedMemory2::Object* v0_5 = mpParent;
        const MtDTI* v1_0;
        for (;;) {
            MtObject* v1_9 = v0_5->mRecordMap.at(i0_3);
            const MtDTI& t0 = v1_9->getDTI();
            MT_CTSTR v1_1 = ::nNetwork::nSharedMemory2::CRecord::DTI.mName;
            v1_0 = &t0;
            for (;;) {
                if (v1_1 != v1_0->mName) {
                    if (v1_0->mpParent != nullptr) {
                        v1_0 = v1_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v1_9 != nullptr) {
                        nNetwork::nSharedMemory2::CRecord* pRecord = static_cast<nNetwork::nSharedMemory2::CRecord*>(v1_9);
                        if (pRecord->mLock == index) {
                            pRecord->mLock = -1;
                            mpParent->checkReqLockList();
                        }
                    }
                    break;
                }
            }
            if ((i0_3 + 1u) < mpParent->mRecordMap.mListNum) {
                i0_3 += 1u;
                v0_5 = mpParent;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void nNetwork::nSharedMemory2::CSessionListener::onHostMemberChange(s32 index, MtNetSession::Member* member) {
    DDON_STUB("nNetwork::nSharedMemory2::CSessionListener::onHostMemberChange")
    /* stub */
}

const MtDTI& nNetwork::nSharedMemory2::Object::getDTI() const {
    return nNetwork::nSharedMemory2::Object::DTI;
}

void* nNetwork::nSharedMemory2::Object::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::nSharedMemory2::Object::DTI)->memAlloc(sz, align, ::nNetwork::nSharedMemory2::Object::DTI.mID);
}

nNetwork::nSharedMemory2::Object::Object() {
    DDON_STUB("nNetwork::nSharedMemory2::Object::Object")
    /* stub */
}

__attribute__((noinline)) nNetwork::nSharedMemory2::Object::~Object() {
    DDON_STUB("nNetwork::nSharedMemory2::Object::~Object")
    /* stub */
}

void nNetwork::nSharedMemory2::Object::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mInit", &mInit, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mType", &mType, 1u, 0u);
}

MtUI* nNetwork::nSharedMemory2::Object::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) bool nNetwork::nSharedMemory2::Object::init(s32 type) {
    DDON_STUB("nNetwork::nSharedMemory2::Object::init")
    return {};
}

__attribute__((weak)) void nNetwork::nSharedMemory2::Object::final() {
    DDON_STUB("nNetwork::nSharedMemory2::Object::final")
    /* stub */
}

__attribute__((weak)) void nNetwork::nSharedMemory2::Object::mirror(s32 dst_index, MtString key, nNetwork::nSharedMemory2::CRecord* record) {
    DDON_STUB("nNetwork::nSharedMemory2::Object::mirror")
    /* stub */
}

__attribute__((weak)) void nNetwork::nSharedMemory2::Object::convert(MtMemoryStream& stream, MtString key, u32 req_seq, s32 msg_kind) {
    DDON_STUB("nNetwork::nSharedMemory2::Object::convert")
    /* stub */
}

__attribute__((weak)) void nNetwork::nSharedMemory2::Object::receive(s32 src_index, const void* data, u32 data_size) {
    DDON_STUB("nNetwork::nSharedMemory2::Object::receive")
    /* stub */
}

__attribute__((weak)) void nNetwork::nSharedMemory2::Object::checkReqLockList() {
    DDON_STUB("nNetwork::nSharedMemory2::Object::checkReqLockList")
    /* stub */
}

inline nNetwork::nSharedMemory2::Object::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::nSharedMemory2::Object::MyDTI nNetwork::nSharedMemory2::Object::DTI("nNetwork::nSharedMemory2::Object", &::MtObject::DTI, 37048ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::nSharedMemory2::Object::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::nSharedMemory2::Object::MyDTI::newInstance")
    return nullptr;
}

