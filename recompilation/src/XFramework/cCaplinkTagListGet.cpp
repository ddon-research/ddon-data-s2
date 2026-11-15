// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkTagListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::TagListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTagInfoTbl.mAutoDelete = true;
    if (mTagInfoTbl.mLength != 0) {
        u32 v0_0 = mTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTagInfoTbl.mpArray[i0_3];
                v1_0 = mTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mTagInfoTbl.mpArray));
    }
    mTagInfoTbl.mpArray = nullptr;
    mTagInfoTbl.mBufsiz = 0;
    mTagInfoTbl.mLength = 0;
    mTotal = 0;
}

