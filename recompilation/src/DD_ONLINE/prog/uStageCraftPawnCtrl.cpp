// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uStageCraftPawnCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cArea.h"
#include "cNetGameServer.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/sArea.h"
#include "sControlManager.h"
#include "sCraftManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uControl.h"
#include "uControlNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uStageCraftPawnCtrl::getDTI() const {
    return uStageCraftPawnCtrl::DTI;
}

inline MtAllocator* uStageCraftPawnCtrl::getAllocator() {
    return MtMemoryAllocator::getAllocator(uStageCraftPawnCtrl::DTI);
}

void* uStageCraftPawnCtrl::operator new(size_t sz, u32 align) {
    return uStageCraftPawnCtrl::getAllocator()->memAlloc(sz, align, uStageCraftPawnCtrl::DTI.getID());
}

inline void uStageCraftPawnCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uStageCraftPawnCtrl::DTI)->memFree(p_addr);
}

uStageCraftPawnCtrl::uStageCraftPawnCtrl() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getMyPawnList();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getRentedPawnList();
    mUpdateTime = sMain::getInstance()->getFps() * 5.0f;
    mUpdateTimer = mUpdateTime;
}

uStageCraftPawnCtrl::~uStageCraftPawnCtrl() {
}

void uStageCraftPawnCtrl::setup() {
    memset(static_cast<void*>(&mMainPawnList[0]), 0, 640ul);
    sCraftManager::getInstance()->mCraftCtrl.reqCraftProgressList();
    this->cUnit::mRno = 0;
}

void uStageCraftPawnCtrl::move() {
    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 8)) == 1) {
        moveMain();
    } else {
        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 8)) == 0) {
            if (sArea::getInstance()->mpArea[2]->cArea::isInit()) {
                if (sCraftManager::getInstance()->mCraftCtrl.mIsCraftProgressComplete) {
                    updatePawnList();
                    updatePawnDisp();
                    this->cUnit::mRno = 1;
                } else {
                    updatePawnDisp();
                }
            }
        }
    }
}

void uStageCraftPawnCtrl::requestUpdatePawn() {
    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 8)) != 1) {
        return;
    }
    updatePawnList();
    updatePawnDisp();
}

__attribute__((weak)) void uStageCraftPawnCtrl::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void uStageCraftPawnCtrl::moveMain() {
    DDON_STUB("uStageCraftPawnCtrl::moveMain")
    /* stub */
}

__attribute__((weak)) void uStageCraftPawnCtrl::updatePawnList() {
    memset(static_cast<void*>(&mMainPawnList[0]), 0, 640ul);
    if (sCraftManager::getInstance()->getMyPawnNum() > 0) {
        for (int i0_3 = 0;;) {
            if (sCraftManager::getInstance()->getMyPawnState(static_cast<u32>(i0_3)) != 1) {
                mMainPawnList[i0_3] = sCraftManager::getInstance()->getMyPawnId(static_cast<u32>(i0_3));
            }
            if ((i0_3 + 1) < sCraftManager::getInstance()->getMyPawnNum()) {
                i0_3 = i0_3 + 1;
            } else {
                break;
            }
        }
    }
    if (sCraftManager::getInstance()->getRentalPawnNum() > 0) {
        for (int i3_3 = 0;;) {
            mRentalPawnList[i3_3] = sCraftManager::getInstance()->getRentalPawnId(static_cast<u32>(i3_3));
            if ((i3_3 + 1) < sCraftManager::getInstance()->getRentalPawnNum()) {
                i3_3 = i3_3 + 1;
            } else {
                break;
            }
        }
    }
    updateWorkPawnList();
    updateWaitPawnList();
}

__attribute__((weak)) void uStageCraftPawnCtrl::updateWorkPawnList() {
    DDON_STUB("uStageCraftPawnCtrl::updateWorkPawnList")
    /* stub */
}

__attribute__((weak)) void uStageCraftPawnCtrl::updateWaitPawnList() {
    DDON_STUB("uStageCraftPawnCtrl::updateWaitPawnList")
    /* stub */
}

inline void uStageCraftPawnCtrl::clearPawnList() {
    memset(static_cast<void*>(&mMainPawnList[0]), 0, 640ul);
}

__attribute__((weak)) void uStageCraftPawnCtrl::updatePawnDisp() {
    DDON_STUB("uStageCraftPawnCtrl::updatePawnDisp")
    /* stub */
}

__attribute__((weak)) void uStageCraftPawnCtrl::updateWaitPawnDispCore(u32* PawnList, const s32* NpcIdList, MtTypedArray<uControlNpc>& NpcList) {
    DDON_STUB("uStageCraftPawnCtrl::updateWaitPawnDispCore")
    /* stub */
}

__attribute__((weak)) void uStageCraftPawnCtrl::updateWorkPawnDispCore(u32(*PawnList)[4], const s32(*NpcIdList)[4], MtTypedArray<uControlNpc>& NpcList) {
    DDON_STUB("uStageCraftPawnCtrl::updateWorkPawnDispCore")
    /* stub */
}

void uStageCraftPawnCtrl::onDispPawn(uControlNpc* pCtrlNpc, u32 PawnId) {
    cNetGameServer* v1_0;
    if (pCtrlNpc == nullptr) {
        return;
    } else {
        cNetGameServer* v0_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
        u32 v0_1 = v0_0->mMyPawnList.mLength;
        if (v0_1 == 0) {
            v1_0 = v0_0;
        } else {
            MtObject* * v0_2 = v0_0->mMyPawnList.mpArray;
            for (unsigned int i0_3 = 0;;) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 8)) != PawnId) {
                    if ((i0_3 + 1u) < v0_1) {
                        i0_3 += 1u;
                    } else {
                        v1_0 = v0_0;
                        break;
                    }
                } else {
                    pCtrlNpc->setMyPawnSlotNo(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 12), true);
                    v1_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
                    break;
                }
            }
        }
    }
    u32 v2_1 = v1_0->mRentedPawnList.mLength;
    if (v2_1 != 0) {
        MtObject* * v2_0 = v1_0->mRentedPawnList.mpArray;
        for (unsigned int i2_2 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v2_0[static_cast<int>(i2_2)]) + 8)) != PawnId) {
                if ((i2_2 + 1u) < v2_1) {
                    i2_2 += 1u;
                } else {
                    break;
                }
            } else {
                pCtrlNpc->setRentalPawnSlotNo(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v2_0[static_cast<int>(i2_2)]) + 12), true);
                pCtrlNpc->mIsForceDispOff = false;
                pCtrlNpc->setNpcName(sCraftManager::getInstance()->getPawnName(PawnId));
                return;
            }
        }
    }
    pCtrlNpc->mIsForceDispOff = false;
    pCtrlNpc->setNpcName(sCraftManager::getInstance()->getPawnName(PawnId));
}

inline uStageCraftPawnCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uStageCraftPawnCtrl::MyDTI uStageCraftPawnCtrl::DTI("uStageCraftPawnCtrl", &::cUnit::DTI, 720ul, 0u, 0u);

MtObject* uStageCraftPawnCtrl::MyDTI::newInstance() const {
    return new (16u) uStageCraftPawnCtrl;
}

