// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkUserIgnoreListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::UserIgnoreListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mIgnoreUserInfoTbl.mAutoDelete = true;
    if (mIgnoreUserInfoTbl.mLength != 0) {
        u32 v0_0 = mIgnoreUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mIgnoreUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mIgnoreUserInfoTbl.mpArray[i0_3];
                v1_0 = mIgnoreUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mIgnoreUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mIgnoreUserInfoTbl.mpArray));
    }
    mIgnoreUserInfoTbl.mpArray = nullptr;
    mIgnoreUserInfoTbl.mBufsiz = 0;
    mIgnoreUserInfoTbl.mLength = 0;
    mTotal = 0;
}

