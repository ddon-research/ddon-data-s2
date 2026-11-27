// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sBazaarManager.h"
#include "Protocol/PacketData/Bazaar.h"
#include "Protocol/PacketData/Character.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "Protocol/UserSession/S2C.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "cNetGameServer.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sBazaarManager::getDTI() const {
    return sBazaarManager::DTI;
}

void* sBazaarManager::operator new(size_t sz, u32 align) {
    return sBazaarManager::getAllocator()->memAlloc(sz, align, sBazaarManager::DTI.getID());
}

sBazaarManager::sBazaarManager() {
    DDON_STUB("sBazaarManager::sBazaarManager")
    /* stub */
}

__attribute__((noinline)) sBazaarManager::~sBazaarManager() {
    DDON_STUB("sBazaarManager::~sBazaarManager")
    /* stub */
}

void sBazaarManager::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

void sBazaarManager::move() {
    switch (mBazaarCharListTaskRno - 1u) {
        case 0:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarExhibitPossibleNum()) {
                mBazaarCharListTaskRno = 2;
            } else {
                mBazaarCharListTaskRno = 5;
            }
            break;
        }
        case 1:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[440] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[440] == sNetworkExt::NET_STAT_ERROR) {
                    mBazaarCharListTaskRno = 5;
                } else {
                    mBazaarCharListTaskRno = 3;
                }
            }
            break;
        }
        case 2:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarCharacterInfo()) {
                mBazaarCharListTaskRno = 4;
            } else {
                mBazaarCharListTaskRno = 5;
            }
            break;
        }
        case 3:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[430] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[430] == sNetworkExt::NET_STAT_ERROR) {
                    mBazaarCharListTaskRno = 5;
                } else {
                    mBazaarCharListTaskRno = 6;
                }
            }
            break;
        }
        case 4:
        {
            mBazaarCharListTaskRno = 0;
            break;
        }
        case 5:
        {
            mBazaarCharListTaskRno = 0;
            break;
        }
        default:
        {
            break;
        }
    }
    if ((mGetAnExhibitItemReqResult - 2u) <= 1u) {
        mGetAnExhibitItemReqResult = 0;
    } else {
        if (mGetAnExhibitItemReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[431] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[431] == sNetworkExt::NET_STAT_ERROR) {
                    mGetAnExhibitItemReqResult = 3;
                } else {
                    mGetAnExhibitItemReqResult = 2;
                }
            }
        }
    }
    if ((mGetAnExhibitItemInfoReqResult - 2u) <= 1u) {
        mGetAnExhibitItemInfoReqResult = 0;
    } else {
        if (mGetAnExhibitItemInfoReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[432] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[432] == sNetworkExt::NET_STAT_ERROR) {
                    mGetAnExhibitItemInfoReqResult = 3;
                } else {
                    mGetAnExhibitItemInfoReqResult = 2;
                }
            }
        }
    }
    if ((mGetAnExhibitItemHistoryReqResult - 2u) <= 1u) {
        mGetAnExhibitItemHistoryReqResult = 0;
    } else {
        if (mGetAnExhibitItemHistoryReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[433] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[433] == sNetworkExt::NET_STAT_ERROR) {
                    mGetAnExhibitItemHistoryReqResult = 3;
                } else {
                    mGetAnExhibitItemHistoryReqResult = 2;
                }
            }
        }
    }
    if (mGetAnExhibitItemProceedsReqResult == 1) {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[437] != sNetworkExt::NET_STAT_REQ) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[437] == sNetworkExt::NET_STAT_ERROR) {
                mGetAnExhibitItemProceedsReqResult = 3;
            } else {
                mGetAnExhibitItemProceedsReqResult = 2;
            }
        }
    }
    if ((mGetPrimLimitReqResult - 2u) <= 1u) {
        mGetPrimLimitReqResult = 0;
    } else {
        if (mGetPrimLimitReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[439] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[439] == sNetworkExt::NET_STAT_ERROR) {
                    mGetPrimLimitReqResult = 3;
                } else {
                    mGetPrimLimitReqResult = 2;
                }
            }
        }
    }
    if ((mStartExhibitReqResult - 2u) <= 1u) {
        mStartExhibitReqResult = 0;
    } else {
        if (mStartExhibitReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[434] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[434] == sNetworkExt::NET_STAT_ERROR) {
                    mStartExhibitReqResult = 3;
                } else {
                    mStartExhibitReqResult = 2;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->requestAward(6);
                }
            }
        }
    }
    if ((mReStartExhibitReqResult - 2u) <= 1u) {
        mReStartExhibitReqResult = 0;
    } else {
        if (mReStartExhibitReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[435] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[435] == sNetworkExt::NET_STAT_ERROR) {
                    mReStartExhibitReqResult = 3;
                } else {
                    mReStartExhibitReqResult = 2;
                }
            }
        }
    }
    if ((mCancelExhibitReqResult - 2u) <= 1u) {
        mCancelExhibitReqResult = 1;
    } else {
        if (mCancelExhibitReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[436] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[436] == sNetworkExt::NET_STAT_ERROR) {
                    mCancelExhibitReqResult = 3;
                } else {
                    mCancelExhibitReqResult = 2;
                }
            }
        }
    }
    if ((mGetBazaarProceedsReqResult - 2u) <= 1u) {
        mGetBazaarProceedsReqResult = 0;
    } else {
        if (mGetBazaarProceedsReqResult == 1) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[438] != sNetworkExt::NET_STAT_REQ) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[438] == sNetworkExt::NET_STAT_ERROR) {
                    mGetBazaarProceedsReqResult = 3;
                } else {
                    mGetBazaarProceedsReqResult = 2;
                }
            }
        }
    }
}

void sBazaarManager::reset() {
    finishBazaar();
}

void sBazaarManager::startBazaar() {
    finishBazaar();
    mBazaarCharListTaskRno = 0;
    mGetBazaarProceedsReqResult = 0;
    mBagType = 0;
    mExhibitItemPrice = 0;
    mPurchaseItemNum = 0;
    mPurchaseItemStorage = 0;
    mCancelExhibitReqResult = 0;
    mStartExhibitReqResult = 0;
    mReStartExhibitReqResult = 0;
    mGetAnExhibitItemProceedsReqResult = 0;
    mGetPrimLimitReqResult = 0;
    mGetAnExhibitItemInfoReqResult = 0;
    mGetAnExhibitItemHistoryReqResult = 0;
    mGetExhibitPossibleNumResult = 0;
    mGetAnExhibitItemReqResult = 0;
}

__attribute__((weak)) void sBazaarManager::finishBazaar() {
    if (mExhibitItemList.mLength != 0) {
        u32 v0_0 = mExhibitItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mExhibitItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mExhibitItemList.mpArray[i0_3];
                v1_0 = mExhibitItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExhibitItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mExhibitItemList.mpArray));
    }
    mExhibitItemList.mpArray = nullptr;
    mExhibitItemList.mBufsiz = 0;
    mExhibitItemList.mLength = 0;
    if (mGetAnExhibitItemList.mLength != 0) {
        u32 v3_0 = mGetAnExhibitItemList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mGetAnExhibitItemList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mGetAnExhibitItemList.mpArray[i3_3];
                v4_0 = mGetAnExhibitItemList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGetAnExhibitItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGetAnExhibitItemList.mpArray));
    }
    mGetAnExhibitItemList.mpArray = nullptr;
    mGetAnExhibitItemList.mBufsiz = 0;
    mGetAnExhibitItemList.mLength = 0;
    if (mPurchaseItemList.mLength != 0) {
        u32 v6_0 = mPurchaseItemList.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mPurchaseItemList.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mPurchaseItemList.mpArray[i6_3];
                v7_0 = mPurchaseItemList.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPurchaseItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPurchaseItemList.mpArray));
    }
    mPurchaseItemList.mpArray = nullptr;
    mPurchaseItemList.mBufsiz = 0;
    mPurchaseItemList.mLength = 0;
    if (mCharInfoCtrl.mData.mLength != 0) {
        u32 v9_0 = mCharInfoCtrl.mData.mLength;
        unsigned int i9_3 = 0;
        u32 v10_0;
        for (;;) {
            if (mCharInfoCtrl.mData.mpArray[i9_3] == nullptr) {
                v10_0 = v9_0;
            } else {
                delete mCharInfoCtrl.mData.mpArray[i9_3];
                v10_0 = mCharInfoCtrl.mData.mLength;
            }
            if ((i9_3 + 1u) < v10_0) {
                v9_0 = v10_0;
                i9_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCharInfoCtrl.mData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCharInfoCtrl.mData.mpArray));
    }
    mCharInfoCtrl.mData.mpArray = nullptr;
    mCharInfoCtrl.mData.mBufsiz = 0;
    mCharInfoCtrl.mData.mLength = 0;
    if (mItemListCtrl.mItemList.mLength != 0) {
        u32 v12_0 = mItemListCtrl.mItemList.mLength;
        unsigned int i12_3 = 0;
        u32 v13_0;
        for (;;) {
            if (mItemListCtrl.mItemList.mpArray[i12_3] == nullptr) {
                v13_0 = v12_0;
            } else {
                delete mItemListCtrl.mItemList.mpArray[i12_3];
                v13_0 = mItemListCtrl.mItemList.mLength;
            }
            if ((i12_3 + 1u) < v13_0) {
                v12_0 = v13_0;
                i12_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemListCtrl.mItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemListCtrl.mItemList.mpArray));
    }
    mItemListCtrl.mItemList.mpArray = nullptr;
    mItemListCtrl.mItemList.mBufsiz = 0;
    mItemListCtrl.mItemList.mLength = 0;
    mItemInfoCtrl.finish();
}

__attribute__((weak)) void sBazaarManager::setBazaarExhibitPossibleNumToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarExhibitPossibleNumToServer")
    /* stub */
}

void sBazaarManager::reqBazaarCharList() {
    if (mBazaarCharListTaskRno == 0) {
        mBazaarCharListTaskRno = 1;
        if (mCharInfoCtrl.mData.mLength != 0) {
            u32 v0_0 = mCharInfoCtrl.mData.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mCharInfoCtrl.mData.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mCharInfoCtrl.mData.mpArray[i0_3];
                    v1_0 = mCharInfoCtrl.mData.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mCharInfoCtrl.mData.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCharInfoCtrl.mData.mpArray));
        }
        mCharInfoCtrl.mData.mpArray = nullptr;
        mCharInfoCtrl.mData.mBufsiz = 0;
        mCharInfoCtrl.mData.mLength = 0;
        mCharInfoCtrl.mSelectNo = -1;
        mCharInfoCtrl.mUpdateCnt = 0;
        mCharInfoCtrl.mPossibleNum = 0;
        mCharInfoCtrl.mAddNum = 0;
    }
}

__attribute__((weak)) void sBazaarManager::setBazaarCharListToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarCharListToServer")
    /* stub */
}

bool sBazaarManager::reqGetBazaarProceeds() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarProceeds()) {
        mGetBazaarProceedsReqResult = 1;
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void sBazaarManager::setBazaarProceedsToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarProceedsToServer")
    /* stub */
}

__attribute__((weak)) bool sBazaarManager::createExhibitItemList(MT_CTSTR UID, u32 num) {
    DDON_STUB("sBazaarManager::createExhibitItemList")
    return {};
}

__attribute__((weak)) bool sBazaarManager::createAnExhibitItemList(u32 itemId) {
    DDON_STUB("sBazaarManager::createAnExhibitItemList")
    return {};
}

void sBazaarManager::clearAnExhibitItemList() {
    if (mGetAnExhibitItemList.mLength != 0) {
        u32 v0_0 = mGetAnExhibitItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGetAnExhibitItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mGetAnExhibitItemList.mpArray[i0_3];
                v1_0 = mGetAnExhibitItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGetAnExhibitItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGetAnExhibitItemList.mpArray));
    }
    mGetAnExhibitItemList.mpArray = nullptr;
    mGetAnExhibitItemList.mBufsiz = 0;
    mGetAnExhibitItemList.mLength = 0;
}

u32 sBazaarManager::getAnExhibitItemListNum() {
    return mGetAnExhibitItemList.mLength;
}

bool sBazaarManager::reqGetAnExhibitItemList() {
    unsigned int v3_3;
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarItemList(mGetAnExhibitItemList)) {
        v3_3 = 0;
    } else {
        unsigned int v2_3;
        if (mItemListCtrl.mItemList.mLength == 0) {
            v2_3 = 0;
        } else {
            u32 v0_0 = mItemListCtrl.mItemList.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mItemListCtrl.mItemList.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mItemListCtrl.mItemList.mpArray[i0_3];
                    v1_0 = mItemListCtrl.mItemList.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    v2_3 = i0_3 + 1u;
                    break;
                }
            }
        }
        if (mItemListCtrl.mItemList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemListCtrl.mItemList.mpArray));
        }
        mItemListCtrl.mItemList.mpArray = nullptr;
        mItemListCtrl.mItemList.mBufsiz = 0;
        mItemListCtrl.mItemList.mLength = 0;
        mItemListCtrl.mSelectNo = -1;
        mGetAnExhibitItemReqResult = 1;
        v3_3 = (v2_3 & 0xFFFFFF00u) | 1u;
    }
    return static_cast<bool>(static_cast<unsigned char>(v3_3));
}

__attribute__((weak)) void sBazaarManager::setBazaarGetAnExhibitItemListToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarGetAnExhibitItemListToServer")
    /* stub */
}

bool sBazaarManager::reqGetAnExhibitItemInfo(u32 itemId) {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarItemInfo(itemId)) {
        mItemInfoCtrl.init();
        mGetAnExhibitItemInfoReqResult = 1;
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void sBazaarManager::setBazaarGetAnExhibitItemInfoToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarGetAnExhibitItemInfoToServer")
    /* stub */
}

bool sBazaarManager::reqGetAnExhibitItemHistory(u32 itemId) {
    unsigned int v3_3;
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarItemHistory(itemId)) {
        v3_3 = 0;
    } else {
        unsigned int v2_3;
        if (mItemInfoCtrl.mItemHistory.mLength == 0) {
            v2_3 = 0;
        } else {
            u32 v0_0 = mItemInfoCtrl.mItemHistory.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mItemInfoCtrl.mItemHistory.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mItemInfoCtrl.mItemHistory.mpArray[i0_3];
                    v1_0 = mItemInfoCtrl.mItemHistory.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    v2_3 = i0_3 + 1u;
                    break;
                }
            }
        }
        if (mItemInfoCtrl.mItemHistory.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemInfoCtrl.mItemHistory.mpArray));
        }
        mItemInfoCtrl.mItemHistory.mpArray = nullptr;
        mItemInfoCtrl.mItemHistory.mBufsiz = 0;
        mItemInfoCtrl.mItemHistory.mLength = 0;
        mGetAnExhibitItemHistoryReqResult = 1;
        v3_3 = (v2_3 & 0xFFFFFF00u) | 1u;
    }
    return static_cast<bool>(static_cast<unsigned char>(v3_3));
}

__attribute__((weak)) void sBazaarManager::setBazaarGetAnExhibitItemHistoryToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarGetAnExhibitItemHistoryToServer")
    /* stub */
}

__attribute__((weak)) bool sBazaarManager::createAnExhibitItemProceedsList(u32 itemNum, u8 storageType) {
    DDON_STUB("sBazaarManager::createAnExhibitItemProceedsList")
    return {};
}

void sBazaarManager::clearAnExhibitItemProceedsList() {
    if (mPurchaseItemList.mLength != 0) {
        u32 v0_0 = mPurchaseItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPurchaseItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPurchaseItemList.mpArray[i0_3];
                v1_0 = mPurchaseItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPurchaseItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPurchaseItemList.mpArray));
    }
    mPurchaseItemList.mpArray = nullptr;
    mPurchaseItemList.mBufsiz = 0;
    mPurchaseItemList.mLength = 0;
}

__attribute__((weak)) bool sBazaarManager::reqGetAnExhibitItemProceeds() {
    DDON_STUB("sBazaarManager::reqGetAnExhibitItemProceeds")
    return {};
}

__attribute__((weak)) void sBazaarManager::setBazaarGetAnExhibitItemProceedsToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarGetAnExhibitItemProceedsToServer")
    /* stub */
}

bool sBazaarManager::reqGetPrimLimit(u32 itemId) {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getBazaarItemPrimLimit(itemId)) {
        mGetPrimLimitReqResult = 1;
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void sBazaarManager::setBazaarGetPrimLimitToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarGetPrimLimitToServer")
    /* stub */
}

__attribute__((weak)) bool sBazaarManager::reqStartExhibitItem() {
    DDON_STUB("sBazaarManager::reqStartExhibitItem")
    return {};
}

__attribute__((weak)) void sBazaarManager::setBazaarExhibitItemToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarExhibitItemToServer")
    /* stub */
}

__attribute__((weak)) void sBazaarManager::setExhibitItemPrice(u32 price) {
    DDON_STUB("sBazaarManager::setExhibitItemPrice")
    /* stub */
}

__attribute__((weak)) bool sBazaarManager::reqReStartExhibitItem() {
    DDON_STUB("sBazaarManager::reqReStartExhibitItem")
    return {};
}

__attribute__((weak)) void sBazaarManager::setBazaarReExhibitItemToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarReExhibitItemToServer")
    /* stub */
}

__attribute__((weak)) bool sBazaarManager::reqCancelExhibitItem() {
    DDON_STUB("sBazaarManager::reqCancelExhibitItem")
    return {};
}

__attribute__((weak)) void sBazaarManager::setBazaarCancelExhibitItemToServer(void* packet) {
    DDON_STUB("sBazaarManager::setBazaarCancelExhibitItemToServer")
    /* stub */
}

inline sBazaarManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::MyDTI sBazaarManager::DTI("sBazaarManager", &::cSystem::DTI, 472ul, 0u, 0u);

sBazaarManager* sBazaarManager::mpInstance;

__attribute__((weak)) MtObject* sBazaarManager::MyDTI::newInstance() const {
    DDON_STUB("sBazaarManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sBazaarManager::cBazaarCharListCtrl::getDTI() const {
    return sBazaarManager::cBazaarCharListCtrl::DTI;
}

sBazaarManager::cBazaarCharListCtrl::~cBazaarCharListCtrl() {
    if (mData.mLength != 0) {
        u32 v0_0 = mData.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mData.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mData.mpArray[i0_3];
                v1_0 = mData.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.mpArray));
    }
    mData.mpArray = nullptr;
    mData.mBufsiz = 0;
    mData.mLength = 0;
}

void sBazaarManager::cBazaarCharListCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mData", static_cast<MtObject*>(&mData), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSelectNo", &mSelectNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPossibleNum", &mPossibleNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAddNum", &mAddNum, 1u, 0u);
}

sBazaarManager::cBazaarCharListData* sBazaarManager::cBazaarCharListCtrl::getBazaarCharListData(u32 index) {
    if (index < mData.mLength) {
        return static_cast<cBazaarCharListData*>(mData.mpArray[index]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) u32 sBazaarManager::cBazaarCharListCtrl::getItemSlot() {
    DDON_STUB("sBazaarManager::cBazaarCharListCtrl::getItemSlot")
    return {};
}

bool sBazaarManager::cBazaarCharListCtrl::isUpdate() {
    if (mUpdateCnt == mUpdateCntOld) {
        return false;
    } else {
        mUpdateCntOld = mUpdateCnt;
        return true;
    }
}

inline sBazaarManager::cBazaarCharListCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarCharListCtrl::MyDTI sBazaarManager::cBazaarCharListCtrl::DTI("sBazaarManager::cBazaarCharListCtrl", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarCharListCtrl::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarCharListCtrl;
}

const MtDTI& sBazaarManager::cBazaarCharListData::getDTI() const {
    return sBazaarManager::cBazaarCharListData::DTI;
}

sBazaarManager::cBazaarCharListData::~cBazaarCharListData() {
}

void sBazaarManager::cBazaarCharListData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "出品状況", &mState, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "アイテムID", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "個数", &mNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "単価", &mPrice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "売上金", &mProceeds, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "バザーID", &mBazaarId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CharID", &mCharId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "シーケンスID", &mSequence, 0u, 0u);
}

__attribute__((weak)) void sBazaarManager::cBazaarCharListData::calcElapsedTime() {
    DDON_STUB("sBazaarManager::cBazaarCharListData::calcElapsedTime")
    /* stub */
}

inline sBazaarManager::cBazaarCharListData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarCharListData::MyDTI sBazaarManager::cBazaarCharListData::DTI("sBazaarManager::cBazaarCharListData", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarCharListData::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarCharListData;
}

const MtDTI& sBazaarManager::cBazaarProceedsCtrl::getDTI() const {
    return sBazaarManager::cBazaarProceedsCtrl::DTI;
}

sBazaarManager::cBazaarProceedsCtrl::~cBazaarProceedsCtrl() {
}

void sBazaarManager::cBazaarProceedsCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "売上金", &mProceeds, 0u, 0u);
}

inline sBazaarManager::cBazaarProceedsCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarProceedsCtrl::MyDTI sBazaarManager::cBazaarProceedsCtrl::DTI("sBazaarManager::cBazaarProceedsCtrl", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarProceedsCtrl::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarProceedsCtrl;
}

const MtDTI& sBazaarManager::cBazaarItemListCtrl::getDTI() const {
    return sBazaarManager::cBazaarItemListCtrl::DTI;
}

sBazaarManager::cBazaarItemListCtrl::~cBazaarItemListCtrl() {
    if (mItemList.mLength != 0) {
        u32 v0_0 = mItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mItemList.mpArray[i0_3];
                v1_0 = mItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemList.mpArray));
    }
    mItemList.mpArray = nullptr;
    mItemList.mBufsiz = 0;
    mItemList.mLength = 0;
}

void sBazaarManager::cBazaarItemListCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mItemList", static_cast<MtObject*>(&mItemList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "件数", reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemListCtrl::getListNum), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void sBazaarManager::cBazaarItemListCtrl::setSelectNo(s32 index) {
    if (mSelectNo != index) {
        sBazaarManager* v0_8 = sBazaarManager::getInstance();
        if (v0_8->mPurchaseItemList.mLength != 0) {
            u32 v0_0 = v0_8->mPurchaseItemList.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (v0_8->mPurchaseItemList.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete v0_8->mPurchaseItemList.mpArray[i0_3];
                    v1_0 = v0_8->mPurchaseItemList.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (v0_8->mPurchaseItemList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_8->mPurchaseItemList.mpArray));
        }
        v0_8->mPurchaseItemList.mpArray = nullptr;
        v0_8->mPurchaseItemList.mBufsiz = 0;
        v0_8->mPurchaseItemList.mLength = 0;
    }
    mSelectNo = index;
}

static auto ddon_emit_0x01abd1a0 __attribute__((used)) = &sBazaarManager::cBazaarItemListCtrl::getListNum;

__attribute__((weak)) u32 sBazaarManager::cBazaarItemListCtrl::getItemNo() {
    DDON_STUB("sBazaarManager::cBazaarItemListCtrl::getItemNo")
    return {};
}

inline sBazaarManager::cBazaarItemListCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemListCtrl::MyDTI sBazaarManager::cBazaarItemListCtrl::DTI("sBazaarManager::cBazaarItemListCtrl", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemListCtrl::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemListCtrl;
}

const MtDTI& sBazaarManager::cBazaarItemListData::getDTI() const {
    return sBazaarManager::cBazaarItemListData::DTI;
}

void sBazaarManager::cBazaarItemListData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "アイテムID", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemParam", reinterpret_cast<MtObject* *>(&mpItemParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "件数", &mEventNum, 0u, 0u);
}

inline sBazaarManager::cBazaarItemListData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemListData::MyDTI sBazaarManager::cBazaarItemListData::DTI("sBazaarManager::cBazaarItemListData", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemListData::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemListData;
}

const MtDTI& sBazaarManager::cBazaarItemInfoCtrl::getDTI() const {
    return sBazaarManager::cBazaarItemInfoCtrl::DTI;
}

__attribute__((noinline)) sBazaarManager::cBazaarItemInfoCtrl::~cBazaarItemInfoCtrl() {
    if (mItemInfo.mLength != 0) {
        u32 v0_0 = mItemInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mItemInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mItemInfo.mpArray[i0_3];
                v1_0 = mItemInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemInfo.mpArray));
    }
    mItemInfo.mpArray = nullptr;
    mItemInfo.mBufsiz = 0;
    mItemInfo.mLength = 0;
    if (mItemHistory.mLength != 0) {
        u32 v3_0 = mItemHistory.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mItemHistory.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mItemHistory.mpArray[i3_3];
                v4_0 = mItemHistory.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemHistory.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemHistory.mpArray));
    }
    mItemHistory.mpArray = nullptr;
    mItemHistory.mBufsiz = 0;
    mItemHistory.mLength = 0;
}

__attribute__((weak)) void sBazaarManager::cBazaarItemInfoCtrl::init() {
    if (mItemInfo.mLength != 0) {
        u32 v0_0 = mItemInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mItemInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mItemInfo.mpArray[i0_3];
                v1_0 = mItemInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemInfo.mpArray));
    }
    mItemInfo.mpArray = nullptr;
    mItemInfo.mBufsiz = 0;
    mItemInfo.mLength = 0;
    if (mItemHistory.mLength != 0) {
        u32 v3_0 = mItemHistory.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mItemHistory.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mItemHistory.mpArray[i3_3];
                v4_0 = mItemHistory.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemHistory.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemHistory.mpArray));
    }
    mItemHistory.mpArray = nullptr;
    mItemHistory.mBufsiz = 0;
    mItemHistory.mLength = 0;
    mItemId = 0;
    mpItemParam = nullptr;
    mSelectNo = -1;
    mProceedsResult = -1;
}

__attribute__((weak)) void sBazaarManager::cBazaarItemInfoCtrl::finish() {
    if (mItemInfo.mLength != 0) {
        u32 v0_0 = mItemInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mItemInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mItemInfo.mpArray[i0_3];
                v1_0 = mItemInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemInfo.mpArray));
    }
    mItemInfo.mpArray = nullptr;
    mItemInfo.mBufsiz = 0;
    mItemInfo.mLength = 0;
    if (mItemHistory.mLength != 0) {
        u32 v3_0 = mItemHistory.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mItemHistory.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mItemHistory.mpArray[i3_3];
                v4_0 = mItemHistory.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItemHistory.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItemHistory.mpArray));
    }
    mItemHistory.mpArray = nullptr;
    mItemHistory.mBufsiz = 0;
    mItemHistory.mLength = 0;
}

void sBazaarManager::cBazaarItemInfoCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mItemInfo", static_cast<MtObject*>(&mItemInfo), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItemHistory", static_cast<MtObject*>(&mItemHistory), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItemId", &mItemId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemParam", reinterpret_cast<MtObject* *>(&mpItemParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSelectNo", &mSelectNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mProceedsResult", &mProceedsResult, 1u, 0u);
}

inline sBazaarManager::cBazaarItemInfoCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemInfoCtrl::MyDTI sBazaarManager::cBazaarItemInfoCtrl::DTI("sBazaarManager::cBazaarItemInfoCtrl", &::MtObject::DTI, 96ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemInfoCtrl::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemInfoCtrl;
}

const MtDTI& sBazaarManager::cBazaarItemInfoData::getDTI() const {
    return sBazaarManager::cBazaarItemInfoData::DTI;
}

sBazaarManager::cBazaarItemInfoData::~cBazaarItemInfoData() {
}

void sBazaarManager::cBazaarItemInfoData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "アイテムID", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemParam", reinterpret_cast<MtObject* *>(&mpItemParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "バザーID", &mBazaarId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "シーケンス", &mSequence, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "個数", &mNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "単価", &mPrice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "出品日時", reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemInfoData::getExhibitTimeStr), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) MT_CTSTR sBazaarManager::cBazaarItemInfoData::getExhibitTimeStr() {
    DDON_STUB("sBazaarManager::cBazaarItemInfoData::getExhibitTimeStr")
    return {};
}

inline sBazaarManager::cBazaarItemInfoData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemInfoData::MyDTI sBazaarManager::cBazaarItemInfoData::DTI("sBazaarManager::cBazaarItemInfoData", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemInfoData::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemInfoData;
}

const MtDTI& sBazaarManager::cBazaarItemHistoryData::getDTI() const {
    return sBazaarManager::cBazaarItemHistoryData::DTI;
}

void sBazaarManager::cBazaarItemHistoryData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "アイテムID", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemParam", reinterpret_cast<MtObject* *>(&mpItemParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "個数", &mNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "単価", &mPrice, 0u, 0u);
}

inline sBazaarManager::cBazaarItemHistoryData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemHistoryData::MyDTI sBazaarManager::cBazaarItemHistoryData::DTI("sBazaarManager::cBazaarItemHistoryData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemHistoryData::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemHistoryData;
}

const MtDTI& sBazaarManager::cBazaarItemPrimLimit::getDTI() const {
    return sBazaarManager::cBazaarItemPrimLimit::DTI;
}

void sBazaarManager::cBazaarItemPrimLimit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mItemId", reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::getItemIdPrivate), reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::setItemIdPrivate), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLow", reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::getLowPrivate), reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::setLowPrivate), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mHigh", reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::getHighPrivate), reinterpret_cast<MT_MFUNC>(&::sBazaarManager::cBazaarItemPrimLimit::setHighPrivate), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

u32 sBazaarManager::cBazaarItemPrimLimit::getItemIdPrivate() const {
    return mItemId_pri;
}

void sBazaarManager::cBazaarItemPrimLimit::setItemIdPrivate(u32 NewValue) {
    mItemId_pri = NewValue;
}

u32 sBazaarManager::cBazaarItemPrimLimit::getLowPrivate() const {
    return mLow_pri;
}

void sBazaarManager::cBazaarItemPrimLimit::setLowPrivate(u32 NewValue) {
    mLow_pri = NewValue;
}

u32 sBazaarManager::cBazaarItemPrimLimit::getHighPrivate() const {
    return mHigh_pri;
}

void sBazaarManager::cBazaarItemPrimLimit::setHighPrivate(u32 NewValue) {
    mHigh_pri = NewValue;
}

inline sBazaarManager::cBazaarItemPrimLimit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarItemPrimLimit::MyDTI sBazaarManager::cBazaarItemPrimLimit::DTI("sBazaarManager::cBazaarItemPrimLimit", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarItemPrimLimit::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarItemPrimLimit;
}

const MtDTI& sBazaarManager::cBazaarExhibitItemCtrl::getDTI() const {
    return sBazaarManager::cBazaarExhibitItemCtrl::DTI;
}

void sBazaarManager::cBazaarExhibitItemCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBazaarId", &mBazaarId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResult", &mResult, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mErrorType", &mErrorType, 1u, 0u);
}

inline sBazaarManager::cBazaarExhibitItemCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBazaarManager::cBazaarExhibitItemCtrl::MyDTI sBazaarManager::cBazaarExhibitItemCtrl::DTI("sBazaarManager::cBazaarExhibitItemCtrl", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* sBazaarManager::cBazaarExhibitItemCtrl::MyDTI::newInstance() const {
    return new (16u) sBazaarManager::cBazaarExhibitItemCtrl;
}

template MtTypedArray<sBazaarManager::cBazaarCharListData>::~MtTypedArray();

template MtTypedArray<sBazaarManager::cBazaarItemHistoryData>::~MtTypedArray();

template MtTypedArray<sBazaarManager::cBazaarItemInfoData>::~MtTypedArray();

template MtTypedArray<sBazaarManager::cBazaarItemListData>::~MtTypedArray();

