// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkUserProfileContentListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::UserProfileContentListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mUserContentTagInfoTbl.mAutoDelete = true;
    if (mUserContentTagInfoTbl.mLength != 0) {
        u32 v0_0 = mUserContentTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mUserContentTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mUserContentTagInfoTbl.mpArray[i0_3];
                v1_0 = mUserContentTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUserContentTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mUserContentTagInfoTbl.mpArray));
    }
    mUserContentTagInfoTbl.mpArray = nullptr;
    mUserContentTagInfoTbl.mBufsiz = 0;
    mUserContentTagInfoTbl.mLength = 0;
    mTotal = 0;
}

