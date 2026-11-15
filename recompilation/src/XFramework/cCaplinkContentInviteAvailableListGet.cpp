// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContentInviteAvailableListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ContentInviteAvailableListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInviteInfoTbl.mAutoDelete = true;
    if (mContentInviteInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInviteInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInviteInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInviteInfoTbl.mpArray[i0_3];
                v1_0 = mContentInviteInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInviteInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInviteInfoTbl.mpArray));
    }
    mContentInviteInfoTbl.mpArray = nullptr;
    mContentInviteInfoTbl.mBufsiz = 0;
    mContentInviteInfoTbl.mLength = 0;
}

