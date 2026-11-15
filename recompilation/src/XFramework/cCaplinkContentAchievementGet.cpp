// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentAchievementGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ContentAchievementGetAns::init() {
    this->::nCaplink::ContextListener::init();
    ::memset(static_cast<void*>(&mAchievement[0]), 0, 2732ul);
    mExtended.mAutoDelete = true;
    if (mExtended.mLength != 0) {
        u32 v0_0 = mExtended.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mExtended.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mExtended.mpArray[i0_3];
                v1_0 = mExtended.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExtended.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mExtended.mpArray));
    }
    mExtended.mpArray = nullptr;
    mExtended.mBufsiz = 0;
    mExtended.mLength = 0;
}

