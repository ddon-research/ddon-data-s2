// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkChatGroupListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ChatGroupListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mChatGroupInfoTbl.mAutoDelete = true;
    if (mChatGroupInfoTbl.mLength != 0) {
        u32 v0_0 = mChatGroupInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mChatGroupInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mChatGroupInfoTbl.mpArray[i0_3];
                v1_0 = mChatGroupInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChatGroupInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mChatGroupInfoTbl.mpArray));
    }
    mChatGroupInfoTbl.mpArray = nullptr;
    mChatGroupInfoTbl.mBufsiz = 0;
    mChatGroupInfoTbl.mLength = 0;
    mTotal = 0;
}

