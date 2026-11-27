// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestSvNotice.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "Protocol/UserSession/S2C.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSvNotCycle04Phase::getDTI() const {
    return cQuestSvNotCycle04Phase::DTI;
}

void* cQuestSvNotCycle04Phase::getNoticePacket() const {
    return static_cast<void*>(mpPacket);
}

cQuestSvNotCycle04Phase::~cQuestSvNotCycle04Phase() {
    if (mpPacket == nullptr) {
        return;
    }
    delete mpPacket;
    mpPacket = nullptr;
}

inline cQuestSvNotCycle04Phase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNotCycle04Phase::MyDTI cQuestSvNotCycle04Phase::DTI("cQuestSvNotCycle04Phase", &::cQuestSvNotice::DTI, 16ul, 0u, 0u);

MtObject* cQuestSvNotCycle04Phase::MyDTI::newInstance() const {
    return new (16u) cQuestSvNotCycle04Phase;
}

const MtDTI& cQuestSvNotDecideDeliveryItem::getDTI() const {
    return cQuestSvNotDecideDeliveryItem::DTI;
}

void* cQuestSvNotDecideDeliveryItem::getNoticePacket() const {
    return static_cast<void*>(mpPacket);
}

cQuestSvNotDecideDeliveryItem::~cQuestSvNotDecideDeliveryItem() {
    if (mpPacket == nullptr) {
        return;
    }
    delete mpPacket;
    mpPacket = nullptr;
}

inline cQuestSvNotDecideDeliveryItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNotDecideDeliveryItem::MyDTI cQuestSvNotDecideDeliveryItem::DTI("cQuestSvNotDecideDeliveryItem", &::cQuestSvNotice::DTI, 16ul, 0u, 0u);

MtObject* cQuestSvNotDecideDeliveryItem::MyDTI::newInstance() const {
    return new (16u) cQuestSvNotDecideDeliveryItem;
}

const MtDTI& cQuestSvNotQuestPhase::getDTI() const {
    return cQuestSvNotQuestPhase::DTI;
}

void* cQuestSvNotQuestPhase::getNoticePacket() const {
    return static_cast<void*>(mpPacket);
}

cQuestSvNotQuestPhase::~cQuestSvNotQuestPhase() {
    if (mpPacket == nullptr) {
        return;
    }
    delete mpPacket;
    mpPacket = nullptr;
}

inline cQuestSvNotQuestPhase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNotQuestPhase::MyDTI cQuestSvNotQuestPhase::DTI("cQuestSvNotQuestPhase", &::cQuestSvNotice::DTI, 16ul, 0u, 0u);

MtObject* cQuestSvNotQuestPhase::MyDTI::newInstance() const {
    return new (16u) cQuestSvNotQuestPhase;
}

__attribute__((weak)) void cQuestSvNotice::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void cQuestSvNotice::move() {
}

inline cQuestSvNotice::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNotice::MyDTI cQuestSvNotice::DTI("cQuestSvNotice", &::MtObject::DTI, 8ul, 0u, 1u);

MtObject* cQuestSvNotice::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cQuestSvNoticeCallback::getDTI() const {
    return cQuestSvNoticeCallback::DTI;
}

const MtDTI& cQuestSvNoticeCallback::getNoticeClassDTI() const {
    return mNoticeClassDti;
}

cQuestSvNoticeCallback& cQuestSvNoticeCallback::setNoticeDTI(const MtDTI& noticeClassDti) {
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 56) = *reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(&noticeClassDti) + 48);
    mNoticeClassDti.mpLink = noticeClassDti.mpLink;
    mNoticeClassDti.mpParent = noticeClassDti.mpParent;
    mNoticeClassDti.mpChild = noticeClassDti.mpChild;
    const MT_CTSTR t0 = noticeClassDti.mName;
    mNoticeClassDti.mpNext = noticeClassDti.mpNext;
    mNoticeClassDti.mName = t0;
    return *this;
}

cQuestSvNoticeCallback& cQuestSvNoticeCallback::setFromClass(MtObject* pFrom) {
    mpFromClass = pFrom;
    return *this;
}

cQuestSvNoticeCallback& cQuestSvNoticeCallback::setCallbackFunc(cQuestSvNoticeCallback::PCallbackFunc pCallbackFunc) {
    mpCallbackFunc = pCallbackFunc;
    return *this;
}

__attribute__((weak)) void cQuestSvNoticeCallback::executeCallbackFunc(void* pPacket) {
    DDON_STUB("cQuestSvNoticeCallback::executeCallbackFunc")
    /* stub */
}

cQuestSvNoticeCallback::~cQuestSvNoticeCallback() {
}

__attribute__((weak)) void cQuestSvNoticeCallback::createProperty(MtPropertyList& s) {
}

inline cQuestSvNoticeCallback::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNoticeCallback::MyDTI cQuestSvNoticeCallback::DTI("cQuestSvNoticeCallback", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* cQuestSvNoticeCallback::MyDTI::newInstance() const {
    return new (16u) cQuestSvNoticeCallback;
}

