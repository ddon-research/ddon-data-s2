// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkFriendTagFreeListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendTagFreeListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFreeTagInfoTbl.mAutoDelete = true;
    if (mFreeTagInfoTbl.mLength != 0) {
        u32 v0_0 = mFreeTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFreeTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFreeTagInfoTbl.mpArray[i0_3];
                v1_0 = mFreeTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFreeTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFreeTagInfoTbl.mpArray));
    }
    mFreeTagInfoTbl.mpArray = nullptr;
    mFreeTagInfoTbl.mBufsiz = 0;
    mFreeTagInfoTbl.mLength = 0;
    mTotal = 0;
}

