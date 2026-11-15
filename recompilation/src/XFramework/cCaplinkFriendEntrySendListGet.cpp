// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkFriendEntrySendListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendEntrySendListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFriendEntryInfoTbl.mAutoDelete = true;
    if (mFriendEntryInfoTbl.mLength != 0) {
        u32 v0_0 = mFriendEntryInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFriendEntryInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFriendEntryInfoTbl.mpArray[i0_3];
                v1_0 = mFriendEntryInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFriendEntryInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFriendEntryInfoTbl.mpArray));
    }
    mFriendEntryInfoTbl.mpArray = nullptr;
    mFriendEntryInfoTbl.mBufsiz = 0;
    mFriendEntryInfoTbl.mLength = 0;
}

