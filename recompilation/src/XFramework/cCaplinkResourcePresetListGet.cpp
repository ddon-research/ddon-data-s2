// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkResourcePresetListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ResourcePresetListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mResourceInfoTbl.mAutoDelete = true;
    if (mResourceInfoTbl.mLength != 0) {
        u32 v0_0 = mResourceInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mResourceInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mResourceInfoTbl.mpArray[i0_3];
                v1_0 = mResourceInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mResourceInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mResourceInfoTbl.mpArray));
    }
    mResourceInfoTbl.mpArray = nullptr;
    mResourceInfoTbl.mBufsiz = 0;
    mResourceInfoTbl.mLength = 0;
}

