// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestSvNoticeManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestSvNotice.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSvNoticeManager::getDTI() const {
    return cQuestSvNoticeManager::DTI;
}

inline MtAllocator* cQuestSvNoticeManager::getAllocator() {
    return MtMemoryAllocator::getAllocator(cQuestSvNoticeManager::DTI);
}

void* cQuestSvNoticeManager::operator new(size_t sz, u32 align) {
    return cQuestSvNoticeManager::getAllocator()->memAlloc(sz, align, cQuestSvNoticeManager::DTI.getID());
}

inline void cQuestSvNoticeManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestSvNoticeManager::DTI)->memFree(p_addr);
}

cQuestSvNoticeCallback* cQuestSvNoticeManager::addCallbackFunc(const MtDTI& callbackClassDti, const MtDTI& noticeClassDti) {
    cQuestSvNoticeCallback* pCallback = static_cast<cQuestSvNoticeCallback*>(callbackClassDti.newInstance());
    pCallback->setNoticeDTI(noticeClassDti);
    sQuestManagerExt::getInstance()->getQuestSvNoticeMgr()->addCallbackFunc(pCallback);
    return pCallback;
}

bool cQuestSvNoticeManager::isEmpty() const {
    return mNoticeList.mLength == 0;
}

__attribute__((weak)) cQuestSvNoticeManager& cQuestSvNoticeManager::addCallbackFunc(cQuestSvNoticeCallback* pSvNotCallback) {
    DDON_STUB("cQuestSvNoticeManager::addCallbackFunc")
    __builtin_unreachable();
}

__attribute__((weak)) cQuestSvNoticeManager& cQuestSvNoticeManager::pushNotice(cQuestSvNotice* pSvNot) {
    DDON_STUB("cQuestSvNoticeManager::pushNotice")
    __builtin_unreachable();
}

__attribute__((weak)) void cQuestSvNoticeManager::updateNotice() {
    DDON_STUB("cQuestSvNoticeManager::updateNotice")
    /* stub */
}

void cQuestSvNoticeManager::release() {
    if (mNoticeList.mLength != 0) {
        u32 v0_0 = mNoticeList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNoticeList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNoticeList.mpArray[i0_3];
                v1_0 = mNoticeList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNoticeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoticeList.mpArray));
    }
    mNoticeList.mpArray = nullptr;
    mNoticeList.mBufsiz = 0;
    mNoticeList.mLength = 0;
}

__attribute__((weak)) void cQuestSvNoticeManager::popNotice(const MtDTI& popNoticeDti) {
    DDON_STUB("cQuestSvNoticeManager::popNotice")
    /* stub */
}

cQuestSvNoticeManager::cQuestSvNoticeManager() {
}

__attribute__((noinline)) cQuestSvNoticeManager::~cQuestSvNoticeManager() {
    if (mCallbackList.mLength != 0) {
        u32 v0_0 = mCallbackList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCallbackList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCallbackList.mpArray[i0_3];
                v1_0 = mCallbackList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCallbackList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCallbackList.mpArray));
    }
    mCallbackList.mpArray = nullptr;
    mCallbackList.mBufsiz = 0;
    mCallbackList.mLength = 0;
    if (mNoticeList.mLength != 0) {
        u32 v3_0 = mNoticeList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mNoticeList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mNoticeList.mpArray[i3_3];
                v4_0 = mNoticeList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNoticeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoticeList.mpArray));
    }
    mNoticeList.mpArray = nullptr;
    mNoticeList.mBufsiz = 0;
    mNoticeList.mLength = 0;
}

__attribute__((weak)) void cQuestSvNoticeManager::createProperty(MtPropertyList& s) {
}

inline cQuestSvNoticeManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvNoticeManager::MyDTI cQuestSvNoticeManager::DTI("cQuestSvNoticeManager", &::cQuestFunctionManagerBase::DTI, 72ul, 0u, 0u);

MtObject* cQuestSvNoticeManager::MyDTI::newInstance() const {
    return new (16u) cQuestSvNoticeManager;
}

template MtTypedArray<cQuestSvNotice>::~MtTypedArray();

template MtTypedArray<cQuestSvNoticeCallback>::~MtTypedArray();

