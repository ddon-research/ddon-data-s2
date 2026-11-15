// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContentListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ContentListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInfoTbl.mAutoDelete = true;
    if (mContentInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInfoTbl.mpArray[i0_3];
                v1_0 = mContentInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInfoTbl.mpArray));
    }
    mContentInfoTbl.mpArray = nullptr;
    mContentInfoTbl.mBufsiz = 0;
    mContentInfoTbl.mLength = 0;
    mTotal = 0;
}

