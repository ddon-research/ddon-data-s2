// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkWebsocketServerListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cCaplinkContext.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::WebsocketServerListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mWebsocketServerInfoTbl.mAutoDelete = true;
    if (mWebsocketServerInfoTbl.mLength != 0) {
        u32 v0_0 = mWebsocketServerInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWebsocketServerInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mWebsocketServerInfoTbl.mpArray[i0_3];
                v1_0 = mWebsocketServerInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWebsocketServerInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mWebsocketServerInfoTbl.mpArray));
    }
    mWebsocketServerInfoTbl.mpArray = nullptr;
    mWebsocketServerInfoTbl.mBufsiz = 0;
    mWebsocketServerInfoTbl.mLength = 0;
    mTotal = 0;
}

