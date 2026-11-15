// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkFriendListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFriendInfoTbl.mAutoDelete = true;
    if (mFriendInfoTbl.mLength != 0) {
        u32 v0_0 = mFriendInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFriendInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFriendInfoTbl.mpArray[i0_3];
                v1_0 = mFriendInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFriendInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFriendInfoTbl.mpArray));
    }
    mFriendInfoTbl.mpArray = nullptr;
    mFriendInfoTbl.mBufsiz = 0;
    mFriendInfoTbl.mLength = 0;
    mTotal = 0;
    mLimmit = 0;
}

