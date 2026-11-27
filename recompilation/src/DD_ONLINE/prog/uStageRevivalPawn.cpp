// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uStageRevivalPawn.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cEfcHandle.h"
#include "cNetGameServer.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpMotionSe.h"
#include "rEffectProvider.h"
#include "../../XFramework/rGUIMessage.h"
#include "rStageInfo.h"
#include "res_ptr.h"
#include "../../XFramework/sArea.h"
#include "sChat.h"
#include "sControlManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sSetManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uBaseModel.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uGUISystemMsg.h"
#include "uHuman.h"
#include "uNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uStageRevivalPawn::getDTI() const {
    return uStageRevivalPawn::DTI;
}

void* uStageRevivalPawn::operator new(size_t sz, u32 align) {
    return uStageRevivalPawn::getAllocator()->memAlloc(sz, align, uStageRevivalPawn::DTI.getID());
}

uStageRevivalPawn::uStageRevivalPawn() {
    DDON_STUB("uStageRevivalPawn::uStageRevivalPawn")
    /* stub */
}

uStageRevivalPawn::~uStageRevivalPawn() {
}

__attribute__((weak)) void uStageRevivalPawn::setup() {
    DDON_STUB("uStageRevivalPawn::setup")
    /* stub */
}

__attribute__((weak)) void uStageRevivalPawn::move() {
    DDON_STUB("uStageRevivalPawn::move")
    /* stub */
}

void uStageRevivalPawn::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    if (mpHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpHandle, 2u);
        mpHandle = nullptr;
    }
    for (u32 i = 0; i != 11; i = i + 1u) {
        if (mpRevHandle[i] != nullptr) {
            static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpRevHandle[i], 2u);
            mpRevHandle[i] = nullptr;
        }
    }
    cNetGameServer* v3_8 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v3_8->mLostPawnList.mLength != 0) {
        u32 v3_0 = v3_8->mLostPawnList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (v3_8->mLostPawnList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete v3_8->mLostPawnList.mpArray[i3_3];
                v4_0 = v3_8->mLostPawnList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v3_8->mLostPawnList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v3_8->mLostPawnList.mpArray));
    }
    v3_8->mLostPawnList.mpArray = nullptr;
    v3_8->mLostPawnList.mBufsiz = 0;
    v3_8->mLostPawnList.mLength = 0;
}

void uStageRevivalPawn::updatePtr() {
    u32 i = 0;
    sEffect* v0_5 = sEffect::getInstance();
    sEffect* v2_5;
    for (;;) {
        if (mpRevHandle[i] != nullptr) {
            if (static_cast<sEffectExt*>(v0_5)->isInvalidHandle(mpRevHandle[i])) {
                mpRevHandle[i]->mpOwner = nullptr;
                mpRevHandle[i] = nullptr;
            }
        }
        v2_5 = sEffect::getInstance();
        if ((i + 1u) != 11) {
            i = i + 1u;
            v0_5 = v2_5;
        } else {
            break;
        }
    }
    if (mpHandle != nullptr) {
        if (static_cast<sEffectExt*>(v2_5)->isInvalidHandle(mpHandle)) {
            mpHandle->mpOwner = nullptr;
            mpHandle = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
}

__attribute__((weak)) void uStageRevivalPawn::createProperty(MtPropertyList& s) {
}

bool uStageRevivalPawn::isReviveFinish() {
    if (mRno1 == 0) {
        if (mKillNpc[mIndex] != 0) {
            if (mKillNpc[mIndex] != 7) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void uStageRevivalPawn::getLostPawnInfo() {
    DDON_STUB("uStageRevivalPawn::getLostPawnInfo")
    /* stub */
}

__attribute__((weak)) void uStageRevivalPawn::watchLostPawnNpc() {
    DDON_STUB("uStageRevivalPawn::watchLostPawnNpc")
    /* stub */
}

__attribute__((weak)) void uStageRevivalPawn::moveRevivalLostPawn() {
    DDON_STUB("uStageRevivalPawn::moveRevivalLostPawn")
    /* stub */
}

inline uStageRevivalPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uStageRevivalPawn::MyDTI uStageRevivalPawn::DTI("uStageRevivalPawn", &::cUnit::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* uStageRevivalPawn::MyDTI::newInstance() const {
    DDON_STUB("uStageRevivalPawn::MyDTI::newInstance")
    return nullptr;
}

