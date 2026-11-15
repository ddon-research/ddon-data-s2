// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkUserSearch.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::UserSearchAns::init() {
    this->::nCaplink::ContextListener::init();
    mUserInfoTbl.mAutoDelete = true;
    if (mUserInfoTbl.mLength != 0) {
        u32 v0_0 = mUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mUserInfoTbl.mpArray[i0_3];
                v1_0 = mUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mUserInfoTbl.mpArray));
    }
    mUserInfoTbl.mpArray = nullptr;
    mUserInfoTbl.mBufsiz = 0;
    mUserInfoTbl.mLength = 0;
}

