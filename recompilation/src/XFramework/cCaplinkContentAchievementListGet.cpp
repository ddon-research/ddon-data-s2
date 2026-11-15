// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContentAchievementListGet.h"
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

void nCaplink::ContentAchievementListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mCount = 0;
    mAchievementList.mAutoDelete = true;
    if (mAchievementList.mLength != 0) {
        u32 v0_0 = mAchievementList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAchievementList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAchievementList.mpArray[i0_3];
                v1_0 = mAchievementList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAchievementList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mAchievementList.mpArray));
    }
    mAchievementList.mpArray = nullptr;
    mAchievementList.mBufsiz = 0;
    mAchievementList.mLength = 0;
}

