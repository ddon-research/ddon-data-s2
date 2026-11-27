// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "cZoneListenerMulti.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cZoneLayout.h"
#include "../../XFramework/cZoneListener.h"
#include "cZoneUnitCtrl.h"
#include "nDDOUtility.h"
#include "../../XFramework/nZone.h"
#include "../../XFramework/rZone.h"
#include "res_ptr.h"
#include "../../XFramework/sZone.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cZoneContactInfo::getDTI() const {
    return cZoneContactInfo::DTI;
}

void cZoneContactInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHandle", &mHandle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupId", &mGroupId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset", &mOffset, 0u, 0u);
}

inline cZoneContactInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneContactInfo::MyDTI cZoneContactInfo::DTI("cZoneContactInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cZoneContactInfo::MyDTI::newInstance() const {
    return new (16u) cZoneContactInfo;
}

const MtDTI& cZoneContactInfoList::getDTI() const {
    return cZoneContactInfoList::DTI;
}

cZoneContactInfoList::~cZoneContactInfoList() {
    initList();
}

void cZoneContactInfoList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mContactPairListStart", static_cast<MtObject*>(&mContactPairListStart), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContactPairListEnd", static_cast<MtObject*>(&mContactPairListEnd), 0u, 0u);
}

__attribute__((weak)) void cZoneContactInfoList::initList() {
    if (mContactPairListStart.mLength != 0) {
        u32 v0_0 = mContactPairListStart.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContactPairListStart.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContactPairListStart.mpArray[i0_3];
                v1_0 = mContactPairListStart.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContactPairListStart.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mContactPairListStart.mpArray));
    }
    mContactPairListStart.mpArray = nullptr;
    mContactPairListStart.mBufsiz = 0;
    mContactPairListStart.mLength = 0;
    if (mContactPairListEnd.mLength != 0) {
        u32 v3_0 = mContactPairListEnd.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mContactPairListEnd.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mContactPairListEnd.mpArray[i3_3];
                v4_0 = mContactPairListEnd.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContactPairListEnd.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mContactPairListEnd.mpArray));
    }
    mContactPairListEnd.mpArray = nullptr;
    mContactPairListEnd.mBufsiz = 0;
    mContactPairListEnd.mLength = 0;
}

__attribute__((weak)) bool cZoneContactInfoList::isContactStart(cZoneContactPairInfo* pData) {
    DDON_STUB("cZoneContactInfoList::isContactStart")
    return {};
}

__attribute__((weak)) bool cZoneContactInfoList::isContactEnd(cZoneContactPairInfo* pData) {
    DDON_STUB("cZoneContactInfoList::isContactEnd")
    return {};
}

inline cZoneContactInfoList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneContactInfoList::MyDTI cZoneContactInfoList::DTI("cZoneContactInfoList", &::MtObject::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneContactInfoList::MyDTI::newInstance() const {
    DDON_STUB("cZoneContactInfoList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneContactPairInfo::getDTI() const {
    return cZoneContactPairInfo::DTI;
}

void cZoneContactPairInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBasic", static_cast<MtObject*>(&mBasic), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mObject", static_cast<MtObject*>(&mObject), 0u, 0u);
}

inline cZoneContactPairInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneContactPairInfo::MyDTI cZoneContactPairInfo::DTI("cZoneContactPairInfo", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneContactPairInfo::MyDTI::newInstance() const {
    DDON_STUB("cZoneContactPairInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneListenerMulti::getDTI() const {
    return cZoneListenerMulti::DTI;
}

cZoneListenerMulti::~cZoneListenerMulti() {
    DDON_STUB("cZoneListenerMulti::~cZoneListenerMulti")
    /* stub */
}

inline cZoneListenerMulti::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneListenerMulti::MyDTI cZoneListenerMulti::DTI("cZoneListenerMulti", &::cZoneMultiListener::DTI, 1216ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneListenerMulti::MyDTI::newInstance() const {
    DDON_STUB("cZoneListenerMulti::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneMultiListener::getDTI() const {
    return cZoneMultiListener::DTI;
}

cZoneMultiListener::cZoneMultiListener() {
    DDON_STUB("cZoneMultiListener::cZoneMultiListener")
    /* stub */
}

__attribute__((weak)) void cZoneMultiListener::moveMultiListener(cZoneMultiStack* pStack) {
    DDON_STUB("cZoneMultiListener::moveMultiListener")
    /* stub */
}

void cZoneMultiListener::notified(const nZone::cLayoutElement& e) {
    if (mNotifiedStackNum <= 47u) {
        mNotifiedStack.elems[mNotifiedStackNum].pElement = &e;
        u32 t0 = mNotifiedStackNum;
        mNotifiedStack.elems[(t0 <= 47u) ? t0 : 0u].Handle = mCheckHandle;
        mNotifiedStackNum = t0 + 1u;
    }
}

MtVector3 cZoneMultiListener::myPos() {
    return mCheckPos;
}

__attribute__((weak)) MtLineSegment cZoneMultiListener::myLineSegment() {
    DDON_STUB("cZoneMultiListener::myLineSegment")
    __builtin_unreachable();
}

inline cZoneMultiListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneMultiListener::MyDTI cZoneMultiListener::DTI("cZoneMultiListener", &::cZoneListener::DTI, 1168ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneMultiListener::MyDTI::newInstance() const {
    DDON_STUB("cZoneMultiListener::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneMultiStack::getDTI() const {
    return cZoneMultiStack::DTI;
}

cZoneMultiStack::~cZoneMultiStack() {
    DDON_STUB("cZoneMultiStack::~cZoneMultiStack")
    /* stub */
}

__attribute__((weak)) u32 cZoneMultiStack::addZone(rZone* pZone, const MtVector3& pos) {
    DDON_STUB("cZoneMultiStack::addZone")
    return {};
}

__attribute__((weak)) u32 cZoneMultiStack::addZone(rZone* pZone, const MtVector3& pos, const MtQuaternion& quat) {
    DDON_STUB("cZoneMultiStack::addZone")
    return {};
}

__attribute__((weak)) void cZoneMultiStack::releaseZone(u32 handle) {
    DDON_STUB("cZoneMultiStack::releaseZone")
    /* stub */
}

void cZoneMultiStack::releaseZoneAll() {
    if (scePthreadMutexLock(&mCS.mCSection) == 0) {
        if (mNotifiedStack.mAutoDelete) {
            u32 v3_0;
            if (mNotifiedStack.mLength != 0) {
                u32 v0_0 = mNotifiedStack.mLength;
                unsigned int i0_3 = 0;
                u32 v1_0;
                for (;;) {
                    if (mNotifiedStack.mpArray[i0_3] == nullptr) {
                        v1_0 = v0_0;
                    } else {
                        delete mNotifiedStack.mpArray[i0_3];
                        v1_0 = mNotifiedStack.mLength;
                    }
                    if ((i0_3 + 1u) < v1_0) {
                        v0_0 = v1_0;
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
                v3_0 = v1_0;
            } else {
                v3_0 = 0;
            }
            memset(static_cast<void*>(mNotifiedStack.mpArray), 0, static_cast<size_t>(v3_0) * 8);
        }
        mNotifiedStack.mLength = 0;
        if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
            return;
        }
    }
    abort();
}

u32 cZoneMultiStack::getZoneNum() const {
    return mNotifiedStack.mLength;
}

__attribute__((weak)) u32 cZoneMultiStack::getZoneHandle(u32 idx) {
    DDON_STUB("cZoneMultiStack::getZoneHandle")
    return {};
}

__attribute__((weak)) void cZoneMultiStack::createZoneContactInfo(u32 BasicHandle, u32 ObjectHandle, u32 BasicIdx, u32 ObjectIdx) {
    DDON_STUB("cZoneMultiStack::createZoneContactInfo")
    /* stub */
}

__attribute__((weak)) bool cZoneMultiStack::createZoneContactInfo(const nZone::cLayoutElement* BasicLERes, u32 ObjectHandle, s32 ObjectLinkType, cZoneContactPairInfo* dst) {
    DDON_STUB("cZoneMultiStack::createZoneContactInfo")
    return {};
}

__attribute__((weak)) bool cZoneMultiStack::isContactShape(const nZone::ShapeInfoBase* pBasicShape, const nZone::ShapeInfoBase* pObjectShape, cZoneContactPairInfo* dst) {
    DDON_STUB("cZoneMultiStack::isContactShape")
    return {};
}

__attribute__((weak)) void cZoneMultiStack::updateZoneContactInfo() {
    DDON_STUB("cZoneMultiStack::updateZoneContactInfo")
    /* stub */
}

__attribute__((weak)) bool cZoneMultiStack::isZoneContact(u32 BasicHandle, u32 ObjectHandle, s8 BasicGroupNo, s32 ObjectGroupNo) {
    DDON_STUB("cZoneMultiStack::isZoneContact")
    return {};
}

inline cZoneMultiStack::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneMultiStack::MyDTI cZoneMultiStack::DTI("cZoneMultiStack", &::cAIObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneMultiStack::MyDTI::newInstance() const {
    DDON_STUB("cZoneMultiStack::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneMultiStackNode::getDTI() const {
    return cZoneMultiStackNode::DTI;
}

__attribute__((noinline)) cZoneMultiStackNode::~cZoneMultiStackNode() {
    DDON_STUB("cZoneMultiStackNode::~cZoneMultiStackNode")
    /* stub */
}

__attribute__((weak)) void cZoneMultiStackNode::setZone(rZone* pZone, const MtVector3& pos) {
    DDON_STUB("cZoneMultiStackNode::setZone")
    /* stub */
}

__attribute__((weak)) void cZoneMultiStackNode::setZone(rZone* pZone, const MtVector3& pos, const MtQuaternion& quat) {
    DDON_STUB("cZoneMultiStackNode::setZone")
    /* stub */
}

inline cZoneMultiStackNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneMultiStackNode::MyDTI cZoneMultiStackNode::DTI("cZoneMultiStackNode", &::cAIObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneMultiStackNode::MyDTI::newInstance() const {
    DDON_STUB("cZoneMultiStackNode::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cZoneContactPairInfo>::~MtTypedArray();

template MtTypedArray<cZoneMultiStackNode>::~MtTypedArray();

