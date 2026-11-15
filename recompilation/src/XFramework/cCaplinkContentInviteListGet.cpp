// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContentInviteListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ContentInviteListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInviteUserInfoTbl.mAutoDelete = true;
    if (mContentInviteUserInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInviteUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInviteUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInviteUserInfoTbl.mpArray[i0_3];
                v1_0 = mContentInviteUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInviteUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInviteUserInfoTbl.mpArray));
    }
    mContentInviteUserInfoTbl.mpArray = nullptr;
    mContentInviteUserInfoTbl.mBufsiz = 0;
    mContentInviteUserInfoTbl.mLength = 0;
}

