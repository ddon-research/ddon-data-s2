// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sOmManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "Protocol/PacketData/Stage.h"
#include "aStage.h"
#include "cArcLoader.h"
#include "../../XFramework/cArea.h"
#include "cAreaHit.h"
#include "cComponentManager.h"
#include "cOmControl.h"
#include "../../XFramework/cResource.h"
#include "cScenario.h"
#include "cScenarioElement.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpOmComponent.h"
#include "../../generated/shared/nDDOMath.h"
#include "nLayout.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rCollision.h"
#include "rEffectProvider.h"
#include "rEventParam.h"
#include "rGatheringItem.h"
#include "rObjCollision.h"
#include "rOmKey.h"
#include "rOmLoadList.h"
#include "rOmParam.h"
#include "../../XFramework/rRenderTargetTexture.h"
#include "rShlParamList.h"
#include "../../XFramework/rSoundRequest.h"
#include "rTable.h"
#include "res_ptr.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sResource.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sUnitManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCamera.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uOmInstancing.h"
#include "uOmModel.h"
#include "uPlayer.h"
#include "../../XFramework/uScreenSpace.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const u32 keyTypeTbl[86] = {
    511000,
    522413,
    511001,
    522413,
    511002,
    522413,
    511050,
    522413,
    511051,
    522413,
    511052,
    522413,
    511070,
    522403,
    511071,
    522403,
    511072,
    522403,
    511080,
    522403,
    511150,
    522413,
    511090,
    522403,
    511120,
    522403,
    511121,
    522413,
    510272,
    522413,
    510273,
    522400,
    510320,
    522400,
    510321,
    522403,
    510350,
    522400,
    510351,
    522413,
    510370,
    522403,
    510371,
    522403,
    510372,
    522413,
    510353,
    522413,
    510410,
    522400,
    510411,
    522410,
    510412,
    522403,
    510413,
    522413,
    510280,
    522400,
    510281,
    522410,
    510282,
    522400,
    510283,
    522410,
    510290,
    522403,
    510291,
    522413,
    510292,
    522403,
    510293,
    522413,
    510294,
    522403,
    510295,
    522413,
    511053,
    522410,
    511223,
    522410,
    511233,
    522413,
    511181,
    522413,
    511250,
    522413,
};

static const u32 keyColorTbl[42] = {
    1027,
    2,
    1028,
    2,
    1029,
    2,
    1030,
    2,
    1031,
    2,
    1032,
    2,
    1033,
    2,
    1034,
    2,
    1035,
    2,
    1038,
    2,
    1040,
    2,
    1047,
    2,
    1048,
    2,
    7578,
    2,
    1048,
    2,
    1037,
    0,
    1041,
    0,
    1042,
    0,
    7589,
    0,
    7590,
    0,
    7591,
    0,
};

static const s32 sOmManager__BadPicth[5] = {
    -200,
    -100,
    0,
    100,
    200,
};

static u32 sOmManager__OmParamTblNum[64];

static u32 sOmManager__OmParamTbl[64][64][2];

const MtDTI& sOmManager::getDTI() const {
    return sOmManager::DTI;
}

void* sOmManager::operator new(size_t sz, u32 align) {
    return sOmManager::getAllocator()->memAlloc(sz, align, sOmManager::DTI.getID());
}

__attribute__((weak)) bool sOmManager::addOmArcLoader(s32 omID, u32 thisID, f32 len, u32 prio, bool bOmIns) {
    DDON_STUB("sOmManager::addOmArcLoader")
    return {};
}

__attribute__((weak)) bool sOmManager::isEnableArc(s32 omID) {
    DDON_STUB("sOmManager::isEnableArc")
    return {};
}

void sOmManager::addOmArcLoaderLock(s32 omID, u32 thisID, f32 len, u32 prio, bool bOmIns) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (addOmArcLoader(omID, u32(), len, prio, false)) {
            mbSortLoader = true;
        }
    } else {
        if (addOmArcLoader(omID, thisID, len, prio, false)) {
            mbSortLoader = true;
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sOmManager::releaseOmArcLoaderLock(s32 omID, u32 thisID) {
    DDON_STUB("sOmManager::releaseOmArcLoaderLock")
    /* stub */
}

__attribute__((weak)) void sOmManager::releaseOmArcLoaderAll() {
    if (mArcLoader.mAutoDelete) {
        u32 v3_0;
        if (mArcLoader.mLength != 0) {
            u32 v0_0 = mArcLoader.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mArcLoader.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mArcLoader.mpArray[i0_3];
                    v1_0 = mArcLoader.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mArcLoader.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mArcLoader.mLength = 0;
    if (mbLoadNyoro) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        mbLoadNyoro = false;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        (sOmManager::mpInstance)->mArcNyoro.cArcLoaderBase::releaseArc();
    }
}

__attribute__((weak)) cOmControl* sOmManager::createOmCtrl(s32 omID, bool isQuest, u32 questNo, s32 stageNo) {
    DDON_STUB("sOmManager::createOmCtrl")
    return nullptr;
}

__attribute__((weak)) void sOmManager::releaseOmCtrl(cOmControl* pctrl) {
    DDON_STUB("sOmManager::releaseOmCtrl")
    /* stub */
}

cOmControl* sOmManager::getOmCtrl(u32 uniqueId) {
    if (mRefOmCtrlArray.mLength != 0) {
        u32 i = 0;
        do {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i)]) + 224)) == uniqueId) {
                    return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i)]);
                }
            }
            i += 1u;
        } while (i < mRefOmCtrlArray.mLength);
    }
    return nullptr;
}

cOmControl* sOmManager::getOmCtrlFromIndex(u32 index) {
    if (index < mRefOmCtrlArray.mLength) {
        return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void sOmManager::moveControl() {
    DDON_STUB("sOmManager::moveControl")
    /* stub */
}

__attribute__((weak)) void sOmManager::linkControl(cOmControl* pctrl) {
    DDON_STUB("sOmManager::linkControl")
    /* stub */
}

__attribute__((weak)) void sOmManager::linkLink(cOmControl* pctrl) {
    DDON_STUB("sOmManager::linkLink")
    /* stub */
}

__attribute__((weak)) void sOmManager::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("sOmManager::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) cOmControl* sOmManager::createOmInsCtrl(s32 omID) {
    DDON_STUB("sOmManager::createOmInsCtrl")
    return nullptr;
}

void sOmManager::releaseOmInsCtrl(cOmControl* pctrl) {
    if (pctrl != nullptr) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        u32 v0_0 = mDelOmIns.mLength;
        if (v0_0 != 0) {
            MtObject* * v0_2 = mDelOmIns.mpArray;
            unsigned int i0_1 = 0;
            for (;;) {
                if (pctrl == v0_2[i0_1]) {
                    break;
                } else {
                    if ((i0_1 + 1u) < v0_0) {
                        i0_1 = i0_1 + 1u;
                    } else {
                        returnTicket(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pctrl) + 224));
                        u32 t0 = mDelOmIns.mLength;
                        u32 t1 = mDelOmIns.mBufsiz;
                        if (t0 < t1) {
                            mDelOmIns.mLength = t0 + 1u;
                            mDelOmIns.mpArray[t0] = static_cast<MtObject*>(pctrl);
                        } else {
                            void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
                            memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
                            memcpy(t2, static_cast<const void*>(mDelOmIns.mpArray), static_cast<size_t>(mDelOmIns.mLength) * 8);
                            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDelOmIns.mpArray));
                            mDelOmIns.mpArray = static_cast<MtObject* *>(t2);
                            mDelOmIns.mBufsiz = t1 + 32u;
                            u32 t3 = mDelOmIns.mLength;
                            mDelOmIns.mLength = t3 + 1u;
                            mDelOmIns.mpArray[t3] = static_cast<MtObject*>(pctrl);
                        }
                        pctrl->reqKillCtrl();
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                                return;
                            }
                        }
                        return;
                    }
                }
            }
            if (i0_1 != 0xFFFFFFFFu) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                        return;
                    }
                }
                return;
            }
        }
    } else {
        return;
    }
    returnTicket(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pctrl) + 224));
    u32 t0 = mDelOmIns.mLength;
    u32 t1 = mDelOmIns.mBufsiz;
    if (t0 < t1) {
        mDelOmIns.mLength = t0 + 1u;
        mDelOmIns.mpArray[t0] = static_cast<MtObject*>(pctrl);
    } else {
        void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
        memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
        memcpy(t2, static_cast<const void*>(mDelOmIns.mpArray), static_cast<size_t>(mDelOmIns.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDelOmIns.mpArray));
        mDelOmIns.mpArray = static_cast<MtObject* *>(t2);
        mDelOmIns.mBufsiz = t1 + 32u;
        u32 t3 = mDelOmIns.mLength;
        mDelOmIns.mLength = t3 + 1u;
        mDelOmIns.mpArray[t3] = static_cast<MtObject*>(pctrl);
    }
    pctrl->reqKillCtrl();
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

uOmSwingInstancing* sOmManager::getOmInsUnit(s32 omID) {
    if (mpuOmIns.mLength != 0) {
        u32 ucnt = 0;
        do {
            if (mpuOmIns.getBuffer()[static_cast<int>(ucnt)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpuOmIns.getBuffer()[static_cast<int>(ucnt)]) + 4800)) == static_cast<unsigned int>(omID)) {
                    return static_cast<uOmSwingInstancing*>(mpuOmIns.getBuffer()[static_cast<int>(ucnt)]);
                }
            }
            ucnt += 1u;
        } while (ucnt < mpuOmIns.mLength);
    }
    return nullptr;
}

__attribute__((weak)) uOmSwingInstancing* sOmManager::createOmInsUnit(s32 omID) {
    DDON_STUB("sOmManager::createOmInsUnit")
    return nullptr;
}

__attribute__((weak)) void sOmManager::deleteOmInsUnit(uOmSwingInstancing* puins) {
    DDON_STUB("sOmManager::deleteOmInsUnit")
    /* stub */
}

__attribute__((weak)) cOmTreeControl* sOmManager::createTreeInsCtrl(s32 omID) {
    DDON_STUB("sOmManager::createTreeInsCtrl")
    return nullptr;
}

void sOmManager::releaseTreeInsCtrl(cOmTreeControl* pctrl) {
    if (pctrl == nullptr) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    u32 v2_0 = mTreeIns.mLength;
    if (v2_0 != 0) {
        MtObject* * v2_1 = mTreeIns.mpArray;
        unsigned int i2_3 = 0;
        u32 v5_0;
        unsigned int v5_8;
        unsigned int v6_1;
        u32 v6_2;
        unsigned int v6_3;
        for (;;) {
            if (pctrl == v2_1[i2_3]) {
                if (!mTreeIns.mAutoDelete) {
                    v5_0 = v2_0;
                } else {
                    delete pctrl;
                    v5_0 = mTreeIns.mLength;
                }
                v5_8 = i2_3 + 1u;
                if (v5_8 < v5_0) {
                    v6_1 = v5_8;
                    v6_2 = v5_0;
                    v6_3 = i2_3;
                    for (;;) {
                        mTreeIns.mpArray[v6_3] = mTreeIns.mpArray[v6_1];
                        if (v6_2 != (v6_1 + 1u)) {
                            v6_3 = v6_1;
                            v6_1 = v6_1 + 1u;
                        } else {
                            break;
                        }
                    }
                }
                mTreeIns.mLength = v5_0 - 1u;
                break;
            } else {
                if ((i2_3 + 1u) < v2_0) {
                    i2_3 = i2_3 + 1u;
                } else {
                    break;
                }
            }
        }
    }
    delete pctrl;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

uOmSwingInstancing* sOmManager::getTreeInsUnit(s32 omID) {
    if (mpuTreeIns.mLength != 0) {
        u32 ucnt = 0;
        do {
            if (mpuTreeIns.getBuffer()[static_cast<int>(ucnt)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpuTreeIns.getBuffer()[static_cast<int>(ucnt)]) + 4800)) == static_cast<unsigned int>(omID)) {
                    return static_cast<uOmSwingInstancing*>(mpuTreeIns.getBuffer()[static_cast<int>(ucnt)]);
                }
            }
            ucnt += 1u;
        } while (ucnt < mpuTreeIns.mLength);
    }
    return nullptr;
}

__attribute__((weak)) uOmSwingInstancing* sOmManager::createTreeInsUnit(s32 omID) {
    DDON_STUB("sOmManager::createTreeInsUnit")
    return nullptr;
}

__attribute__((weak)) void sOmManager::deleteTreeInsUnit(uOmSwingInstancing* puins) {
    DDON_STUB("sOmManager::deleteTreeInsUnit")
    /* stub */
}

bool sOmManager::isCreatableUnit() {
    return sPlayerManager::getInstance()->mpMyPlayer != nullptr;
}

void sOmManager::fadeIn(f32 frame) {
    mbBell = false;
    mRnoFade = 1;
    mFadeFrame = frame;
    mBellTimer = 450.0f;
}

bool sOmManager::isDoor(u32 uniqueId) {
    if (mRefOmCtrlArray.mLength != 0) {
        unsigned int i0 = 0;
        do {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 224)) == uniqueId) {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 144)) != 0) {
                        return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 144)) + 16)) & 2) >> 1);
                    } else {
                        return false;
                    }
                }
            }
            i0 += 1u;
        } while (i0 < mRefOmCtrlArray.mLength);
    }
    return false;
}

bool sOmManager::isCanOpenDoor(u32 uniqueId) {
    if (mRefOmCtrlArray.mLength != 0) {
        unsigned int i0 = 0;
        do {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 224)) == uniqueId) {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 144)) != 0) {
                        return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 144)) + 16)) & 2) >> 1);
                    } else {
                        return false;
                    }
                }
            }
            i0 += 1u;
        } while (i0 < mRefOmCtrlArray.mLength);
    }
    return false;
}

__attribute__((weak)) bool sOmManager::isKeyDoor(u32 uniqueId) {
    DDON_STUB("sOmManager::isKeyDoor")
    return {};
}

__attribute__((weak)) bool sOmManager::isCloseDoor(u32 uniqueId) {
    DDON_STUB("sOmManager::isCloseDoor")
    return {};
}

__attribute__((weak)) bool sOmManager::isOpenEndDoor(u32 uniqueId) {
    DDON_STUB("sOmManager::isOpenEndDoor")
    return {};
}

__attribute__((weak)) bool sOmManager::isOpenEndDoorHalf(u32 uniqueId) {
    DDON_STUB("sOmManager::isOpenEndDoorHalf")
    return {};
}

__attribute__((weak)) bool sOmManager::isOnMyPLElfSW(u32 uniqueId) {
    DDON_STUB("sOmManager::isOnMyPLElfSW")
    return {};
}

__attribute__((weak)) bool sOmManager::isOpenedElfSW(u32 uniqueId) {
    DDON_STUB("sOmManager::isOpenedElfSW")
    return {};
}

__attribute__((weak)) bool sOmManager::isBreakable(u32 uniqueId) {
    DDON_STUB("sOmManager::isBreakable")
    return {};
}

bool sOmManager::isUseItem(u32 uniqueID) {
    if (mRefOmCtrlArray.mLength != 0) {
        unsigned int i0 = 0;
        do {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 224)) == uniqueID) {
                    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0)]) + 169)) & 16) >> 4);
                }
            }
            i0 += 1u;
        } while (i0 < mRefOmCtrlArray.mLength);
    }
    return false;
}

__attribute__((weak)) void sOmManager::setOpenDoor(u32 uniqueId) {
    DDON_STUB("sOmManager::setOpenDoor")
    /* stub */
}

__attribute__((weak)) u32 sOmManager::getLadderHeight(u32 uniqueID) {
    DDON_STUB("sOmManager::getLadderHeight")
    return {};
}

__attribute__((weak)) bool sOmManager::isInsideGrp(u32 group, const MtSphere& sh, bool isall) {
    DDON_STUB("sOmManager::isInsideGrp")
    return {};
}

__attribute__((weak)) bool sOmManager::isInAtkOm(const MtVector3& realPos, f32 length) {
    DDON_STUB("sOmManager::isInAtkOm")
    return {};
}

u32 sOmManager::getAtkOmPosNum() {
    return mAtkOmPosNum;
}

const MtVector3& sOmManager::getAtkOmPosNum(u32 index) {
    if (index < mAtkOmPosNum) {
        return mAtkOmPos[index];
    } else {
        return MtVector3::Zero;
    }
}

cOmControl* sOmManager::getTarasuk() {
    if (mFastOmCtrlArray.mLength != 0) {
        u32 cnt = 0;
        do {
            if (mFastOmCtrlArray.getBuffer()[static_cast<int>(cnt)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mFastOmCtrlArray.getBuffer()[static_cast<int>(cnt)]) + 48)) != 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mFastOmCtrlArray.getBuffer()[static_cast<int>(cnt)]) + 136)) == 0x7FABC) {
                        return static_cast<cOmControl*>(mFastOmCtrlArray.getBuffer()[static_cast<int>(cnt)]);
                    }
                }
            }
            cnt += 1u;
        } while (cnt < mFastOmCtrlArray.mLength);
    }
    return nullptr;
}

void sOmManager::setTarasukSBCPartsOff(cOmControl* pctrl) {
    if (pctrl == nullptr) {
        return;
    }
    pctrl->setActiveAllSbcParts(false);
    pctrl->setActiveSbc(true, 0u, 0u, 0u);
    pctrl->setActiveSbc(true, 1u, 0u, 0u);
}

void sOmManager::setSBC(cOmControl* pctrl, bool sbc_on) {
    if (pctrl == nullptr) {
        return;
    }
    pctrl->setActiveAllSbcParts(sbc_on);
}

__attribute__((weak)) void sOmManager::setSBCPosAngle(cOmControl* pctrl, MtVector3& sbc_pos, MtVector3& sbc_angle) {
    DDON_STUB("sOmManager::setSBCPosAngle")
    /* stub */
}

__attribute__((weak)) bool sOmManager::getActiveSBC(cOmControl* pctrl, u32 partsNo) {
    DDON_STUB("sOmManager::getActiveSBC")
    return {};
}

bool sOmManager::isMoveFloorNow() {
    return mbMoveFloorNow;
}

MtVector3 sOmManager::getOmRealPos(u32 index) {
    if (index < mRefOmCtrlArray.mLength) {
        if (mRefOmCtrlArray.getBuffer()[static_cast<int>(index)] != nullptr) {
            return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mPos;
        }
    }
    return MtVector3::Zero;
}

u32 sOmManager::getOmMapIcon(u32 index) {
    if (index < mRefOmCtrlArray.mLength) {
        if (mRefOmCtrlArray.getBuffer()[static_cast<int>(index)] != nullptr) {
            if (!static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mbMapNone) {
                if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam != nullptr) {
                    if ((static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mUseComponent & 2u) != 0) {
                        return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                    } else {
                        if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID <= 522231) {
                            if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID <= 512123) {
                                if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID <= 510469) {
                                    switch (static_cast<unsigned int>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID - 510430)) {
                                        case 0:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 1:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 2:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 11:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 12:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 13:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 14:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 15:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 16:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 17:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        case 18:
                                        {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        }
                                        default:
                                        {
                                            return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mMapIcon;
                                        }
                                    }
                                } else {
                                    if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID != 510470) {
                                        if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID == 510471) {
                                            return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                        } else {
                                            return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mMapIcon;
                                        }
                                    } else {
                                        return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                    }
                                }
                            } else {
                                if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID == 512124) {
                                    return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                } else {
                                    if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID == 512126) {
                                        return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                                    } else {
                                        return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mMapIcon;
                                    }
                                }
                            }
                        } else {
                            if (static_cast<unsigned int>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mOmID - 522232) <= 4) {
                                return static_cast<u32>(static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mMapIcon);
                            } else {
                                return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mMapIcon;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) bool sOmManager::isClosedByCtrl(cOmControl* pctrl) {
    DDON_STUB("sOmManager::isClosedByCtrl")
    return {};
}

__attribute__((weak)) bool sOmManager::isCtrled(cOmControl* pctrl) {
    DDON_STUB("sOmManager::isCtrled")
    return {};
}

__attribute__((weak)) s32 sOmManager::isCtrledEM(uCharacter* puc) {
    DDON_STUB("sOmManager::isCtrledEM")
    return {};
}

__attribute__((weak)) void sOmManager::getOmMapErase(u32 index, MtVector3& out_pos, MtVector3& out_rot, MtVector3& out_scale) {
    DDON_STUB("sOmManager::getOmMapErase")
    /* stub */
}

void sOmManager::getOmBadStatus(u32 index, MtVector3& out_pos, f32& out_radius, f32& out_height) {
    if (index < mRefOmCtrlArray.mLength) {
        if (mRefOmCtrlArray.getBuffer()[static_cast<int>(index)] != nullptr) {
            if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam != nullptr) {
                if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mpOmParam->mMapIcon == 37) {
                    out_pos.x = static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mBadPos.x;
                    out_pos.y = static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mBadPos.y;
                    out_pos.z = static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mBadPos.z;
                    out_pos.pad_ = 0.0f;
                    out_radius = 100.0f * static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mBadRadius;
                    out_height = 100.0f * static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(index)])->mLot.mBadHeight;
                }
            }
        }
    }
}

__attribute__((weak)) void sOmManager::callBackUseItemReq(void* param) {
}

u32 sOmManager::getGatherGrp(cOmControl* pctrl) {
    if (pctrl != nullptr) {
        const cOmParam* pparam = pctrl->getOmParam();
        if (pparam != nullptr) {
            if ((pparam->mUseComponent & 0x80000u) == 0) {
                if ((pparam->mUseComponent & 0x100000u) != 0) {
                    return 2;
                } else {
                    return ((pparam->mUseComponent & 8u) == 0) ? (pparam->mUseComponent & 4u) : 3u;
                }
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void sOmManager::loadNyoro() {
    if (!mbLoadNyoro) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        mbLoadNyoro = true;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
            sOmManager* t0 = sOmManager::getInstance();
            t0->mArcNyoro.loadReqTag(rArchiveListArray::convTagId("EM011400"), static_cast<s16>(0));
        } else {
            sOmManager* t0 = sOmManager::getInstance();
            t0->mArcNyoro.loadReqTag(rArchiveListArray::convTagId("EM011400"), static_cast<s16>(0));
        }
    }
}

void sOmManager::releaseNyoro() {
    if (!mbLoadNyoro) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    mbLoadNyoro = false;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    (sOmManager::mpInstance)->mArcNyoro.cArcLoaderBase::releaseArc();
}

bool sOmManager::addBad(u32 omID, s32& pitch) {
    unsigned int i0_0;
    unsigned int* p0_1;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) == 0) {
            if (mBadNum > 4u) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return false;
            } else {
                i0_0 = 0;
                p0_1 = &mBadOmID[0];
            }
        } else {
            abort();
        }
    } else {
        if (mBadNum > 4u) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return false;
        } else {
            i0_0 = 0;
            p0_1 = &mBadOmID[0];
        }
    }
    for (;;) {
        if ((*p0_1) != 0) {
            if ((i0_0 + 1u) > 4u) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return false;
            } else {
                i0_0 += 1u;
                p0_1 += 1;
            }
        } else {
            if (i0_0 != 0xFFFFFFFFu) {
                mBadOmID[static_cast<int>(i0_0)] = omID;
                pitch = sOmManager__BadPicth[static_cast<int>(i0_0)];
                mBadNum = mBadNum + 1u;
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
                        return true;
                    } else {
                        break;
                    }
                } else {
                    return true;
                }
            } else {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return false;
            }
        }
    }
    abort();
}

void sOmManager::deleteBad(u32 omID) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mBadOmID[0] == omID) {
        mBadOmID[0] = 0;
    }
    if (mBadOmID[1] == omID) {
        mBadOmID[1] = 0;
    }
    if (mBadOmID[2] == omID) {
        mBadOmID[2] = 0;
    }
    if (mBadOmID[3] == omID) {
        mBadOmID[3] = 0;
    }
    if (mBadOmID[4] == omID) {
        mBadOmID[4] = 0;
    }
    mBadNum = mBadNum - 1u;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

void sOmManager::startCutscene(const MtTypedArray<cEventParam::cOmList>* pomlist) {
    mbCutscene = true;
    mpCutSceneOmList = pomlist;
    mCutsceneLoadFrame = 0;
    mCutsceneLoadOMIDNum = 0;
    mCutsceneMoveOMIDNum = 0;
    u32 num = pomlist->mLength;
    if (num != 0) {
        u32 v0_0 = 0;
        const MtTypedArray<cEventParam::cOmList>* v0_3 = pomlist;
        for (unsigned int i0_8 = 0;;) {
            MtObject* * t0 = v0_3->mpArray;
            MtObject* t1 = t0[i0_8];
            if (t1 != nullptr) {
                unsigned short t2 = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(t1) + 12);
                if (t2 == 4) {
                    if (v0_0 <= 63u) {
                        unsigned int t3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t1) + 8);
                        mCutsceneLoadOMID[v0_0] = static_cast<int>(t3);
                        bool t4 = cSystem::mJobSafe;
                        bool t5 = mThreadSafe;
                        if (t4 || t5) {
                            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                                abort();
                                return;
                            }
                            float t7 = 10000.0f;
                            if (addOmArcLoader(static_cast<s32>(t3), u32(), t7, 0u, false)) {
                                mbSortLoader = true;
                            }
                        } else {
                            float t7 = 10000.0f;
                            if (addOmArcLoader(static_cast<s32>(t3), t2, t7, 0u, false)) {
                                mbSortLoader = true;
                            }
                        }
                        bool t9 = cSystem::mJobSafe;
                        bool t10 = mThreadSafe;
                        if (t9 || t10) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                                return;
                            }
                        }
                        u32 t12 = mCutsceneLoadOMIDNum;
                        mCutsceneLoadOMIDNum = t12 + 1u;
                        if ((i0_8 + 1u) >= num) {
                            break;
                        } else {
                            v0_0 = t12 + 1u;
                            v0_3 = mpCutSceneOmList;
                            i0_8 = i0_8 + 1u;
                        }
                    } else {
                        break;
                    }
                } else {
                    if ((i0_8 + 1u) >= num) {
                        break;
                    } else {
                        v0_3 = mpCutSceneOmList;
                        i0_8 = i0_8 + 1u;
                    }
                }
            } else {
                if ((i0_8 + 1u) >= num) {
                    break;
                } else {
                    v0_3 = mpCutSceneOmList;
                    i0_8 = i0_8 + 1u;
                }
            }
        }
        if (num != 0) {
            for (unsigned int i2_0 = 0;;) {
                const MtTypedArray<cEventParam::cOmList>* t13 = mpCutSceneOmList;
                MtObject* * t14 = t13->mpArray;
                MtObject* t15 = t14[i2_0];
                if (t15 != nullptr) {
                    unsigned short t16 = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(t15) + 12);
                    if (t16 == 3) {
                        u32 t17 = mCutsceneLoadOMIDNum;
                        if (t17 > 63u) {
                            break;
                        } else {
                            unsigned int t18 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t15) + 8);
                            u32 t19 = mCutsceneMoveOMIDNum;
                            mCutsceneMoveOMID[t19] = static_cast<int>(t18);
                            u32 t20 = mCutsceneMoveOMIDNum;
                            mCutsceneMoveOMIDNum = t20 + 1u;
                        }
                    }
                }
                if ((i2_0 + 1u) < num) {
                    i2_0 = i2_0 + 1u;
                } else {
                    break;
                }
            }
        }
    }
}

void sOmManager::endCutscene() {
    mbCutscene = false;
    mpCutSceneOmList = nullptr;
    u32 cnt = 0;
    if (mCutsceneLoadOMIDNum != 0) {
        do {
            releaseOmArcLoaderLock(mCutsceneLoadOMID[cnt], 1u);
            cnt += 1u;
        } while (cnt < mCutsceneLoadOMIDNum);
    }
}

void sOmManager::callBackInsSync(const COmData& data) {
    mInstanceAreaData.mInsSyncUID[mInstanceAreaData.mInsSyncNum] = data.m_ulKey;
    mInsSyncVal[mInstanceAreaData.mInsSyncNum] = data.m_ulValue;
    mInstanceAreaData.mInsSyncNum = mInstanceAreaData.mInsSyncNum + 1u;
}

__attribute__((weak)) void sOmManager::callBackInsSyncExchange(const COmData& data, u32 valOld) {
    DDON_STUB("sOmManager::callBackInsSyncExchange")
    /* stub */
}

__attribute__((weak)) void sOmManager::callBackInsSyncAll(const MtTypedArray<CDataOmData>& omlist) {
    DDON_STUB("sOmManager::callBackInsSyncAll")
    /* stub */
}

__attribute__((weak)) void sOmManager::moveInsSync() {
    DDON_STUB("sOmManager::moveInsSync")
    /* stub */
}

__attribute__((weak)) bool sOmManager::isDoneGimmick(u32 in_uid) {
    DDON_STUB("sOmManager::isDoneGimmick")
    return {};
}

uBaseModel* sOmManager::getLayoutUnit(u32 uniqueId) {
    if (mRefOmCtrlArray.mLength != 0) {
        unsigned int i1 = 0;
        do {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i1)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i1)]) + 224)) == uniqueId) {
                    return static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i1)])->getUnit();
                }
            }
            i1 += 1u;
        } while (i1 < mRefOmCtrlArray.mLength);
    }
    return nullptr;
}

__attribute__((weak)) void sOmManager::moveAQC() {
    DDON_STUB("sOmManager::moveAQC")
    /* stub */
}

void sOmManager::setUnitGroup(bool flag, s32 omNo, u32 setGroup) {
    u32 num = mRefOmCtrlArray.mLength;
    if (num != 0) {
        for (unsigned int i0_9 = 0;;) {
            if (mRefOmCtrlArray.getBuffer()[static_cast<int>(i0_9)] != nullptr) {
                if (static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0_9)])->mLot.mOmID == omNo) {
                    uBaseModel* t0 = static_cast<cOmControl*>(mRefOmCtrlArray.getBuffer()[static_cast<int>(i0_9)])->getUnit();
                    if (t0 != nullptr) {
                        bool t1 = t0->checkUnitGroup(setGroup);
                        if (flag) {
                            if (!t1) {
                                sUnit::getInstance()->setUnitGroup(static_cast<cUnit*>(t0), setGroup);
                            }
                        } else {
                            if (t1) {
                                sUnit::getInstance()->removeUnitGroup(static_cast<cUnit*>(t0), setGroup);
                            }
                        }
                    }
                }
            }
            if (num != (i0_9 + 1u)) {
                i0_9 += 1u;
            } else {
                break;
            }
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    if (mpuOmIns.mLength != 0) {
        unsigned int i3_3 = 0;
        num = mpuOmIns.mLength;
        for (;;) {
            MtObject* t2 = mpuOmIns.getBuffer()[static_cast<int>(i3_3)];
            if (t2 != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 4808)) != 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 4808)) + 216)) == static_cast<unsigned int>(omNo)) {
                        bool t3 = static_cast<cUnit*>(t2)->checkUnitGroup(setGroup);
                        if (flag) {
                            if (!t3) {
                                sUnit::getInstance()->setUnitGroup(static_cast<cUnit*>(t2), setGroup);
                            }
                        } else {
                            if (t3) {
                                sUnit::getInstance()->removeUnitGroup(static_cast<cUnit*>(t2), setGroup);
                            }
                        }
                    }
                }
            }
            if (num != (i3_3 + 1u)) {
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

void sOmManager::setUnitGroup(bool flag, uBaseModel* pMdl, u32 setGroup) {
    if (pMdl == nullptr) {
        return;
    }
    bool t0 = pMdl->checkUnitGroup(setGroup);
    if (flag) {
        if (!t0) {
            sUnit::getInstance()->setUnitGroup(static_cast<cUnit*>(pMdl), setGroup);
        }
    } else {
        if (t0) {
            sUnit::getInstance()->removeUnitGroup(static_cast<cUnit*>(pMdl), setGroup);
        }
    }
}

__attribute__((weak)) void sOmManager::setOMPResource(rOmParam* pr) {
    DDON_STUB("sOmManager::setOMPResource")
    /* stub */
}

__attribute__((weak)) void sOmManager::getKeyTypeColor(s32 omID, u32 keyNo, u32& out_type, u32& out_color, MtVector3& out_ofs) {
    DDON_STUB("sOmManager::getKeyTypeColor")
    /* stub */
}

__attribute__((weak)) void sOmManager::loadCommonRes() {
    DDON_STUB("sOmManager::loadCommonRes")
    /* stub */
}

__attribute__((weak)) void sOmManager::releasCommonRes() {
    DDON_STUB("sOmManager::releasCommonRes")
    /* stub */
}

__attribute__((weak)) cOmParam* sOmManager::findOmParam(s32 omID) {
    DDON_STUB("sOmManager::findOmParam")
    return nullptr;
}

sOmManager::sOmManager() {
    DDON_STUB("sOmManager::sOmManager")
    /* stub */
}

__attribute__((noinline)) sOmManager::~sOmManager() {
    DDON_STUB("sOmManager::~sOmManager")
    /* stub */
}

void sOmManager::init() {
    this->sUnitManager::init();
}

void sOmManager::reset() {
    this->sUnitManager::reset();
    mRnoFade = 0;
    releaseAllOmCtrlDirect();
    releaseWarpList();
}

void sOmManager::clear() {
    this->sUnitManager::clear();
    mRnoFade = 0;
    mLoadFrame = 0;
    mbLoadArc = false;
    mbLoadStart = false;
    mbLoadEnd = false;
    mbMoveFloorNow = false;
    mbMoveFloor[0] = false;
    mbMoveFloor[1] = false;
    mbMoveFloor[2] = false;
    mbMoveFloorReset = false;
    mBadOmID[3] = 0;
    mBadOmID[4] = 0;
    mBadOmID[1] = 0;
    mBadOmID[2] = 0;
    mBadNum = 0;
    mBadOmID[0] = 0;
    releaseAllOmCtrlDirect();
}

__attribute__((weak)) void sOmManager::move() {
    DDON_STUB("sOmManager::move")
    /* stub */
}

__attribute__((weak)) void sOmManager::releaseAllOmCtrlDirect() {
    mbDeleteAll = true;
    u32 num = mpuOmIns.mLength;
    if (num != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (mpuOmIns.getBuffer()[static_cast<int>(i0_3)] != nullptr) {
                static_cast<uOmSwingInstancing*>(mpuOmIns.getBuffer()[static_cast<int>(i0_3)])->kill();
                mpuOmIns.getBuffer()[static_cast<int>(i0_3)] = nullptr;
            }
            if (num != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mpuOmIns.mAutoDelete) {
        u32 v4_0;
        if (mpuOmIns.mLength != 0) {
            u32 v2_0 = mpuOmIns.mLength;
            unsigned int i2_3 = 0;
            u32 v3_0;
            for (;;) {
                if (mpuOmIns.mpArray[i2_3] != nullptr) {
                    delete mpuOmIns.mpArray[i2_3];
                    if ((i2_3 + 1u) < mpuOmIns.mLength) {
                        v2_0 = mpuOmIns.mLength;
                        i2_3 += 1u;
                    } else {
                        v3_0 = mpuOmIns.mLength;
                        break;
                    }
                } else {
                    if ((i2_3 + 1u) < v2_0) {
                        i2_3 += 1u;
                    } else {
                        v3_0 = v2_0;
                        break;
                    }
                }
            }
            v4_0 = v3_0;
        } else {
            v4_0 = 0;
        }
        memset(static_cast<void*>(mpuOmIns.mpArray), 0, static_cast<size_t>(v4_0) * 8);
    }
    mpuOmIns.mLength = 0;
    if (mDelOmIns.mAutoDelete) {
        u32 v8_0;
        if (mDelOmIns.mLength != 0) {
            u32 v6_0 = mDelOmIns.mLength;
            unsigned int i6_3 = 0;
            u32 v7_0;
            for (;;) {
                if (mDelOmIns.mpArray[i6_3] != nullptr) {
                    delete mDelOmIns.mpArray[i6_3];
                    if ((i6_3 + 1u) < mDelOmIns.mLength) {
                        v6_0 = mDelOmIns.mLength;
                        i6_3 += 1u;
                    } else {
                        v7_0 = mDelOmIns.mLength;
                        break;
                    }
                } else {
                    if ((i6_3 + 1u) < v6_0) {
                        i6_3 += 1u;
                    } else {
                        v7_0 = v6_0;
                        break;
                    }
                }
            }
            v8_0 = v7_0;
        } else {
            v8_0 = 0;
        }
        memset(static_cast<void*>(mDelOmIns.mpArray), 0, static_cast<size_t>(v8_0) * 8);
    }
    mDelOmIns.mLength = 0;
    if (mOmIns.mLength != 0) {
        u32 v10_0 = mOmIns.mLength;
        for (unsigned int i10_3 = 0;;) {
            if (mOmIns.mpArray[i10_3] != nullptr) {
                delete mOmIns.mpArray[i10_3];
                if ((i10_3 + 1u) < mOmIns.mLength) {
                    v10_0 = mOmIns.mLength;
                    i10_3 += 1u;
                } else {
                    break;
                }
            } else {
                if ((i10_3 + 1u) < v10_0) {
                    i10_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mOmIns.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mOmIns.mpArray));
    }
    mOmIns.mpArray = nullptr;
    mOmIns.mBufsiz = 0;
    mOmIns.mLength = 0;
    if (mpuTreeIns.mLength != 0) {
        unsigned int i12_3 = 0;
        num = mpuTreeIns.mLength;
        for (;;) {
            if (mpuTreeIns.getBuffer()[static_cast<int>(i12_3)] != nullptr) {
                static_cast<uOmSwingInstancing*>(mpuTreeIns.getBuffer()[static_cast<int>(i12_3)])->kill();
                mpuTreeIns.getBuffer()[static_cast<int>(i12_3)] = nullptr;
            }
            if (num != (i12_3 + 1u)) {
                i12_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mpuTreeIns.mAutoDelete) {
        u32 v16_0;
        if (mpuTreeIns.mLength != 0) {
            u32 v14_0 = mpuTreeIns.mLength;
            unsigned int i14_3 = 0;
            u32 v15_0;
            for (;;) {
                if (mpuTreeIns.mpArray[i14_3] != nullptr) {
                    delete mpuTreeIns.mpArray[i14_3];
                    if ((i14_3 + 1u) < mpuTreeIns.mLength) {
                        v14_0 = mpuTreeIns.mLength;
                        i14_3 += 1u;
                    } else {
                        v15_0 = mpuTreeIns.mLength;
                        break;
                    }
                } else {
                    if ((i14_3 + 1u) < v14_0) {
                        i14_3 += 1u;
                    } else {
                        v15_0 = v14_0;
                        break;
                    }
                }
            }
            v16_0 = v15_0;
        } else {
            v16_0 = 0;
        }
        memset(static_cast<void*>(mpuTreeIns.mpArray), 0, static_cast<size_t>(v16_0) * 8);
    }
    mpuTreeIns.mLength = 0;
    if (mTreeIns.mLength != 0) {
        u32 v18_0 = mTreeIns.mLength;
        for (unsigned int i18_3 = 0;;) {
            if (mTreeIns.mpArray[i18_3] != nullptr) {
                delete mTreeIns.mpArray[i18_3];
                if ((i18_3 + 1u) < mTreeIns.mLength) {
                    v18_0 = mTreeIns.mLength;
                    i18_3 += 1u;
                } else {
                    break;
                }
            } else {
                if ((i18_3 + 1u) < v18_0) {
                    i18_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mTreeIns.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTreeIns.mpArray));
    }
    mTreeIns.mpArray = nullptr;
    mTreeIns.mBufsiz = 0;
    mTreeIns.mLength = 0;
    if (mRefOmCtrlArray.mLength != 0) {
        u32 v20_0 = mRefOmCtrlArray.mLength;
        for (unsigned int i20_3 = 0;;) {
            if (mRefOmCtrlArray.mpArray[i20_3] != nullptr) {
                delete mRefOmCtrlArray.mpArray[i20_3];
                if ((i20_3 + 1u) < mRefOmCtrlArray.mLength) {
                    v20_0 = mRefOmCtrlArray.mLength;
                    i20_3 += 1u;
                } else {
                    break;
                }
            } else {
                if ((i20_3 + 1u) < v20_0) {
                    i20_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mRefOmCtrlArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mRefOmCtrlArray.mpArray));
    }
    mRefOmCtrlArray.mpArray = nullptr;
    mRefOmCtrlArray.mBufsiz = 0;
    mRefOmCtrlArray.mLength = 0;
    if (mAddOmCtrlArray.mLength != 0) {
        u32 v22_0 = mAddOmCtrlArray.mLength;
        for (unsigned int i22_3 = 0;;) {
            if (mAddOmCtrlArray.mpArray[i22_3] != nullptr) {
                delete mAddOmCtrlArray.mpArray[i22_3];
                if ((i22_3 + 1u) < mAddOmCtrlArray.mLength) {
                    v22_0 = mAddOmCtrlArray.mLength;
                    i22_3 += 1u;
                } else {
                    break;
                }
            } else {
                if ((i22_3 + 1u) < v22_0) {
                    i22_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mAddOmCtrlArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAddOmCtrlArray.mpArray));
    }
    mAddOmCtrlArray.mpArray = nullptr;
    mAddOmCtrlArray.mBufsiz = 0;
    mAddOmCtrlArray.mLength = 0;
    if (mDelOmCtrlArray.mAutoDelete) {
        u32 v26_0;
        if (mDelOmCtrlArray.mLength != 0) {
            u32 v24_0 = mDelOmCtrlArray.mLength;
            unsigned int i24_3 = 0;
            u32 v25_0;
            for (;;) {
                if (mDelOmCtrlArray.mpArray[i24_3] != nullptr) {
                    delete mDelOmCtrlArray.mpArray[i24_3];
                    if ((i24_3 + 1u) < mDelOmCtrlArray.mLength) {
                        v24_0 = mDelOmCtrlArray.mLength;
                        i24_3 += 1u;
                    } else {
                        v25_0 = mDelOmCtrlArray.mLength;
                        break;
                    }
                } else {
                    if ((i24_3 + 1u) < v24_0) {
                        i24_3 += 1u;
                    } else {
                        v25_0 = v24_0;
                        break;
                    }
                }
            }
            v26_0 = v25_0;
        } else {
            v26_0 = 0;
        }
        memset(static_cast<void*>(mDelOmCtrlArray.mpArray), 0, static_cast<size_t>(v26_0) * 8);
    }
    mDelOmCtrlArray.mLength = 0;
    releaseOmArcLoaderAll();
    mbDeleteAll = false;
}

__attribute__((weak)) void sOmManager::moveParallel(uintptr interlockAddr) {
    DDON_STUB("sOmManager::moveParallel")
    /* stub */
}

void sOmManager::startStageInit() {
    mLoadFrame = 0;
    mbLoadStart = true;
    mbLoadEnd = false;
    mbLoadArc = false;
    mDelayCount = 0;
}

__attribute__((weak)) bool sOmManager::isStageInitOK() {
    DDON_STUB("sOmManager::isStageInitOK")
    return {};
}

u32 sOmManager::getGatheringItem(u32 type, u32* buff, u32 buff_size) {
    unsigned int v2_7;
    if (mprGatheringItem == nullptr) {
        v2_7 = 0;
    } else {
        if (mprGatheringItem->getDataNum() == 0) {
            v2_7 = 0;
        } else {
            unsigned int i0_9 = 0;
            unsigned int i0_10 = 0;
            unsigned int v1_9;
            for (;;) {
                cGatheringItem* t0 = mprGatheringItem->getData(i0_10);
                if (t0 == nullptr) {
                    v1_9 = i0_9;
                } else {
                    if (t0->mType != type) {
                        v1_9 = i0_9;
                    } else {
                        if (buff != nullptr) {
                            if (i0_9 < buff_size) {
                                buff[i0_9] = t0->mItemNo;
                            }
                        }
                        v1_9 = i0_9 + 1u;
                    }
                }
                if ((i0_10 + 1u) < mprGatheringItem->getDataNum()) {
                    i0_9 = v1_9;
                    i0_10 += 1u;
                } else {
                    v2_7 = v1_9;
                    break;
                }
            }
        }
    }
    return v2_7;
}

bool sOmManager::isQuestFlag(cOmControl* pctrl, u32 flagNo) const {
    if (pctrl != nullptr) {
        if (pctrl->mLot.mbMyQuest) {
            return sQuestManagerExt::getInstance()->isMyQuestFlag(flagNo);
        } else {
            return sQuestManagerExt::getInstance()->isQuestFlag(flagNo);
        }
    } else {
        return false;
    }
}

bool sOmManager::isQuestFlag(cOmControl* pctrl, u32 flagNo, nQuest::QUEST_ID questId) const {
    if (pctrl != nullptr) {
        if (pctrl->mLot.mbMyQuest) {
            bool t0 = sQuestManagerExt::getInstance()->isMyQuestFlag(flagNo, questId);
            return t0;
        } else {
            bool t1 = sQuestManagerExt::getInstance()->isQuestFlag(flagNo, questId);
            return t1;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void sOmManager::setShell(const MtVector3& pos, uDDOModel* pudmg) {
    DDON_STUB("sOmManager::setShell")
    /* stub */
}

void sOmManager::add603000(cOmControl* pctrl) {
    if (pctrl == nullptr) {
        return;
    }
    if (m60300Num > 3u) {
        return;
    }
    cOmControl* * p0 = &mpCtrl603000[0];
    u32 cnt = 0;
    do {
        if ((*p0) == nullptr) {
            *p0 = pctrl;
            m60300Num = m60300Num + 1u;
            return;
        }
        p0 += static_cast<int>(1);
        cnt += 1u;
    } while (cnt <= 3u);
}

void sOmManager::remove603000(cOmControl* pctrl) {
    cOmControl* * p0 = &mpCtrl603000[0];
    u32 cnt = 0;
    if (pctrl != nullptr) {
        do {
            if (pctrl == (*p0)) {
                *p0 = nullptr;
                m60300Num = m60300Num - 1u;
                return;
            }
            p0 += static_cast<int>(1);
            cnt += 1u;
        } while (cnt <= 3u);
    }
}

__attribute__((weak)) void sOmManager::releaseWarpList() {
    if (mWarpList.mLength != 0) {
        u32 v0_0 = mWarpList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWarpList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mWarpList.mpArray[i0_3];
                v1_0 = mWarpList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWarpList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mWarpList.mpArray));
    }
    mWarpList.mpArray = nullptr;
    mWarpList.mBufsiz = 0;
    mWarpList.mLength = 0;
    if (mWarpArcLoader.mLength != 0) {
        u32 v3_0 = mWarpArcLoader.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mWarpArcLoader.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mWarpArcLoader.mpArray[i3_3];
                v4_0 = mWarpArcLoader.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWarpArcLoader.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mWarpArcLoader.mpArray));
    }
    mWarpArcLoader.mpArray = nullptr;
    mWarpArcLoader.mBufsiz = 0;
    mWarpArcLoader.mLength = 0;
    mpWarpNearest = nullptr;
    if (mpOmLoadList != nullptr) {
        mpOmLoadList->release();
        mpOmLoadList = nullptr;
    }
}

__attribute__((weak)) f32 sOmManager::getWarpDist(sOmManager::cWarpData* data, MtVector3& pos) {
    DDON_STUB("sOmManager::getWarpDist")
    return {};
}

__attribute__((weak)) void sOmManager::addWarpList(MtObject* owner) {
    DDON_STUB("sOmManager::addWarpList")
    /* stub */
}

__attribute__((weak)) void sOmManager::deleteWarpList(MtObject* owner) {
    DDON_STUB("sOmManager::deleteWarpList")
    /* stub */
}

__attribute__((weak)) void sOmManager::moveWarpList() {
    DDON_STUB("sOmManager::moveWarpList")
    /* stub */
}

void sOmManager::addWarpArcLoader(s32 stageNo, s32 startPos) {
    if (mpOmLoadList != nullptr) {
        cOmLoadList* pList = mpOmLoadList->searchData(stageNo, startPos);
        if (pList != nullptr) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                    return;
                }
            }
            if (pList->mOmList.mLength != 0) {
                unsigned int i0_3 = 0;
                const MtDTI* v1_0;
                for (;;) {
                    MtObject* v1_9 = pList->mOmList.mpArray[i0_3];
                    const MtDTI& t0 = v1_9->getDTI();
                    MT_CTSTR v1_1 = cOmLoadList::cOmList::DTI.mName;
                    v1_0 = &t0;
                    for (;;) {
                        if (v1_1 != v1_0->mName) {
                            if (v1_0->mpParent != nullptr) {
                                v1_0 = v1_0->mpParent;
                            } else {
                                break;
                            }
                        } else {
                            if (v1_9 != nullptr) {
                                cOmLoadList::cOmList* pData = static_cast<cOmLoadList::cOmList*>(v1_9);
                                addWarpArcLoaderSub(pData->mOmId);
                            }
                            break;
                        }
                    }
                    if ((i0_3 + 1u) < pList->mOmList.mLength) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        } else {
            return;
        }
    } else {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) void sOmManager::addWarpArcLoaderSub(u32 omID) {
    DDON_STUB("sOmManager::addWarpArcLoaderSub")
    /* stub */
}

__attribute__((weak)) void sOmManager::eraseWarpArcLoader() {
    DDON_STUB("sOmManager::eraseWarpArcLoader")
    /* stub */
}

inline sOmManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOmManager::MyDTI sOmManager::DTI("sOmManager", &::sUnitManager::DTI, 20816ul, 0u, 0u);

sOmManager* sOmManager::mpInstance;

__attribute__((weak)) MtObject* sOmManager::MyDTI::newInstance() const {
    DDON_STUB("sOmManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sOmManager::cOmArcLoader::getDTI() const {
    return sOmManager::cOmArcLoader::DTI;
}

sOmManager::cOmArcLoader::~cOmArcLoader() {
    mArc.releaseArc();
    mRnoArc = 0;
}

__attribute__((weak)) void sOmManager::cOmArcLoader::move() {
    DDON_STUB("sOmManager::cOmArcLoader::move")
    /* stub */
}

bool sOmManager::cOmArcLoader::sortFunc(const sOmManager::cOmArcLoader* pa, const sOmManager::cOmArcLoader* pb, u32) {
    if (pb->mLoadPrio >= pa->mLoadPrio) {
        return pa->mLoadLength > pb->mLoadLength;
    } else {
        return true;
    }
}

bool sOmManager::cOmArcLoader::isEnableArc() const {
    return mRnoArc == 3;
}

inline sOmManager::cOmArcLoader::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOmManager::cOmArcLoader::MyDTI sOmManager::cOmArcLoader::DTI("sOmManager::cOmArcLoader", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* sOmManager::cOmArcLoader::MyDTI::newInstance() const {
    DDON_STUB("sOmManager::cOmArcLoader::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sOmManager::cWarpData::getDTI() const {
    return sOmManager::cWarpData::DTI;
}

inline sOmManager::cWarpData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOmManager::cWarpData::MyDTI sOmManager::cWarpData::DTI("sOmManager::cWarpData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sOmManager::cWarpData::MyDTI::newInstance() const {
    return new (16u) sOmManager::cWarpData;
}

const MtDTI& sOmManager::cClanEmblemTextureCtrl::getDTI() const {
    return sOmManager::cClanEmblemTextureCtrl::DTI;
}

sOmManager::cClanEmblemTextureCtrl::~cClanEmblemTextureCtrl() {
    if (mpScreenSpace != nullptr) {
        mpScreenSpace->kill();
        mpScreenSpace = nullptr;
    }
    if (mpRenderTargetTexture == nullptr) {
        return;
    }
    mpRenderTargetTexture->release();
    mpRenderTargetTexture = nullptr;
}

void sOmManager::cClanEmblemTextureCtrl::setup() {
    rRenderTargetTexture* t0 = mpRenderTargetTexture;
    if (t0 != nullptr) {
        t0->release();
        mpRenderTargetTexture = nullptr;
        sArchiveManager* t2 = sArchiveManager::getInstance();
        cResource* t3 = t2->createRes("clankyoten", "RES_ID_CLAN_EMBLEM_TX", 1u, false);
        mpRenderTargetTexture = static_cast<rRenderTargetTexture*>(t3);
        bool t5 = createScreenSpace();
        rRenderTargetTexture* t7 = mpRenderTargetTexture;
        if (t7 != nullptr) {
            uScreenSpace* t8 = mpScreenSpace;
            if (t8 != nullptr) {
                rRenderTargetTexture* t9 = t8->mpRenderTarget;
                if (t9 != nullptr) {
                    t9->release();
                    t8->mpRenderTarget = nullptr;
                    t8->releaseTexture();
                    t8->mpRenderTarget = t7;
                    t7->addRef();
                    rRenderTargetTexture* t13 = t8->mpRenderTarget;
                    t8->createDepth(t13);
                } else {
                    t8->releaseTexture();
                    t8->mpRenderTarget = t7;
                    t7->addRef();
                    rRenderTargetTexture* t13 = t8->mpRenderTarget;
                    t8->createDepth(t13);
                }
            }
        }
    } else {
        sArchiveManager* t2 = sArchiveManager::getInstance();
        cResource* t3 = t2->createRes("clankyoten", "RES_ID_CLAN_EMBLEM_TX", 1u, false);
        mpRenderTargetTexture = static_cast<rRenderTargetTexture*>(t3);
        bool t5 = createScreenSpace();
        rRenderTargetTexture* t7 = mpRenderTargetTexture;
        if (t7 != nullptr) {
            uScreenSpace* t8 = mpScreenSpace;
            if (t8 != nullptr) {
                rRenderTargetTexture* t9 = t8->mpRenderTarget;
                if (t9 != nullptr) {
                    t9->release();
                    t8->mpRenderTarget = nullptr;
                    t8->releaseTexture();
                    t8->mpRenderTarget = t7;
                    t7->addRef();
                    rRenderTargetTexture* t13 = t8->mpRenderTarget;
                    t8->createDepth(t13);
                } else {
                    t8->releaseTexture();
                    t8->mpRenderTarget = t7;
                    t7->addRef();
                    rRenderTargetTexture* t13 = t8->mpRenderTarget;
                    t8->createDepth(t13);
                }
            }
        }
    }
}

__attribute__((weak)) bool sOmManager::cClanEmblemTextureCtrl::createScreenSpace() {
    DDON_STUB("sOmManager::cClanEmblemTextureCtrl::createScreenSpace")
    return {};
}

void sOmManager::cClanEmblemTextureCtrl::release() {
    if (mpScreenSpace != nullptr) {
        mpScreenSpace->kill();
        mpScreenSpace = nullptr;
    }
    if (mpRenderTargetTexture == nullptr) {
        return;
    }
    mpRenderTargetTexture->release();
    mpRenderTargetTexture = nullptr;
}

inline sOmManager::cClanEmblemTextureCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOmManager::cClanEmblemTextureCtrl::MyDTI sOmManager::cClanEmblemTextureCtrl::DTI("sOmManager::cClanEmblemTextureCtrl", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sOmManager::cClanEmblemTextureCtrl::MyDTI::newInstance() const {
    return new (16u) sOmManager::cClanEmblemTextureCtrl;
}

