// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uStageJoint.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtStlAllocator.h"
#include "../../MT/MtStlCustom.h"
#include "../../MT/MtSynchronize.h"
#include "aStage.h"
#include "cArcLoader.h"
#include "../../XFramework/cArea.h"
#include "cContextInterface.h"
#include "cOmControl.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "cScenario.h"
#include "cSplitBase.h"
#include "cStageEpvCtrl.h"
#include "../../XFramework/cUnit.h"
#include "cZoneIndoorHandle.h"
#include "../../XFramework/cZoneLayout.h"
#include "../../generated/shared/nDDOMath.h"
#include "nStage.h"
#include "../../generated/shared/nZoneUnitCtrl.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rCollision.h"
#include "rEffectProvider.h"
#include "../../XFramework/rNavigationMesh.h"
#include "rPlantTree.h"
#include "rScenario.h"
#include "../../XFramework/rScheduler.h"
#include "rSoundAreaInfo.h"
#include "rStageInfo.h"
#include "rStageJoint.h"
#include "../../XFramework/rZone.h"
#include "res_ptr.h"
#include "../../XFramework/sAI.h"
#include "sAIExt.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCollision.h"
#include "sContextManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGame.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sScenario.h"
#include "sSetManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "sWorldOffset.h"
#include "sZoneStatus.h"
#include "sZoneUnitCtrl.h"
#include "../../XFramework/uCoord.h"
#include "uLightExt.h"
#include "uPlayer.h"
#include "../../XFramework/uScheduler.h"
#include "uScrModel.h"
#include "../../XFramework/uScrollCollisionGeometry.h"
#include "uSkyWaterModel.h"
#include "uSoundGenerator.h"
#include "uSoundOcclusion.h"
#include "uSoundTrigger.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uStageJointCtrl::getDTI() const {
    return uStageJointCtrl::DTI;
}

void* uStageJointCtrl::operator new(size_t sz, u32 align) {
    return uStageJointCtrl::getAllocator()->memAlloc(sz, align, uStageJointCtrl::DTI.getID());
}

uStageJointCtrl::uStageJointCtrl() {
    DDON_STUB("uStageJointCtrl::uStageJointCtrl")
    /* stub */
}

uStageJointCtrl::~uStageJointCtrl() {
    DDON_STUB("uStageJointCtrl::~uStageJointCtrl")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::setup() {
    DDON_STUB("uStageJointCtrl::setup")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::move() {
    DDON_STUB("uStageJointCtrl::move")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uStageJointCtrl::kill() {
    DDON_STUB("uStageJointCtrl::kill")
    /* stub */
}

void uStageJointCtrl::updatePtr() {
    u32 v0_0 = mJointMdlAry.mLength;
    if (v0_0 != 0) {
        for (unsigned int i0_1 = 0;;) {
            if (mJointMdlAry.getBuffer()[static_cast<int>(i0_1)] != nullptr) {
                if (!static_cast<cUnit*>(mJointMdlAry.getBuffer()[static_cast<int>(i0_1)])->isEnable()) {
                    mJointMdlAry.getBuffer()[static_cast<int>(i0_1)] = nullptr;
                }
            }
            if ((i0_1 + 1u) < v0_0) {
                i0_1 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSplitLotAry.mLength != 0) {
        u32 v3_0 = mSplitLotAry.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mSplitLotAry.getBuffer()[static_cast<int>(i3_3)] == nullptr) {
                v4_0 = v3_0;
            } else {
                static_cast<cSplitLot*>(mSplitLotAry.getBuffer()[static_cast<int>(i3_3)])->updatePtr();
                v4_0 = mSplitLotAry.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void uStageJointCtrl::setResource(s32 stageNo) {
    DDON_STUB("uStageJointCtrl::setResource")
    /* stub */
}

bool uStageJointCtrl::calcJointArea(const MtVector3& pos, s32& outX, s32& outZ) {
    if (mpJointArea != nullptr) {
        if (mpJointArea->mParam.mStartX > pos.x) {
            outZ = 0;
            outX = 0;
            return false;
        } else {
            if (mpJointArea->mParam.mStartZ > pos.z) {
                outZ = 0;
                outX = 0;
                return false;
            } else {
                outX = static_cast<int>((pos.x - mpJointArea->mParam.mStartX) / mpJointArea->mParam.mDeltaX);
                outZ = static_cast<int>((pos.z - mpJointArea->mParam.mStartZ) / mpJointArea->mParam.mDeltaZ);
                return true;
            }
        }
    } else {
        return false;
    }
}

bool uStageJointCtrl::isSetup() {
    if (!mIsSetup) {
        return false;
    }
    if (mJointMdlAry.mLength == 0) {
        return false;
    }
    u32 idx = 0;
    do {
        if (mJointMdlAry.getBuffer()[static_cast<int>(idx)] != nullptr) {
            if (static_cast<uStageJointMdl*>(mJointMdlAry.getBuffer()[static_cast<int>(idx)])->isSetResource()) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mJointMdlAry.getBuffer()[static_cast<int>(idx)]) + 364)) != 2) {
                    return false;
                }
            } else {
                return false;
            }
        }
        idx += 1u;
    } while (idx < mJointMdlAry.mLength);
    return true;
}

__attribute__((weak)) void uStageJointCtrl::sbcSetMatrix() {
    DDON_STUB("uStageJointCtrl::sbcSetMatrix")
    /* stub */
}

__attribute__((weak)) bool uStageJointCtrl::isSbc(s32 x, s32 z) {
    DDON_STUB("uStageJointCtrl::isSbc")
    return {};
}

bool uStageJointCtrl::isSbc(s32 areaNo) {
    if (mJointMdlAry.mLength != 0) {
        u32 i = 0;
        do {
            if (mJointMdlAry.getBuffer()[static_cast<int>(i)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mJointMdlAry.getBuffer()[static_cast<int>(i)]) + 344)) == static_cast<unsigned int>(areaNo)) {
                    if (static_cast<uStageJointMdl*>(mJointMdlAry.getBuffer()[static_cast<int>(i)])->isSetResource()) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mJointMdlAry.getBuffer()[static_cast<int>(i)]) + 364)) == 2) {
                            return true;
                        }
                    }
                }
            }
            i += 1u;
        } while (i < mJointMdlAry.mLength);
    }
    return false;
}

cSplitBgm* uStageJointCtrl::getSplitBgmInfo() {
    if (mpJointArea != nullptr) {
        s8 areaNo = mpJointArea->mParam.getAreaData(static_cast<u32>(mNowZ), static_cast<u32>(mNowX));
        return static_cast<sSoundExt*>(sSound::getInstance())->getSplitAreaBgmInfo(areaNo);
    } else {
        return nullptr;
    }
}

cSplitBgm* uStageJointCtrl::getSplitBgmInfo(const MtVector3& targetPos) {
    if (mpJointArea != nullptr) {
        MtVector3 frame56(sWorldOffset::getInstance()->getRealPos(targetPos));
        if (mpJointArea != nullptr) {
            if (mpJointArea->mParam.mStartX > frame56.x) {
                return nullptr;
            } else {
                if (mpJointArea->mParam.mStartZ > frame56.z) {
                    return nullptr;
                } else {
                    s8 areaNo = mpJointArea->mParam.getAreaData(static_cast<u32>(static_cast<int>((frame56.z - mpJointArea->mParam.mStartZ) / mpJointArea->mParam.mDeltaZ)), static_cast<u32>(static_cast<int>((frame56.x - mpJointArea->mParam.mStartX) / mpJointArea->mParam.mDeltaX)));
                    return static_cast<sSoundExt*>(sSound::getInstance())->getSplitAreaBgmInfo(areaNo);
                }
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uStageJointCtrl::setBlockArcLoad(s32 stageNo, MtVector3& plPos) {
    DDON_STUB("uStageJointCtrl::setBlockArcLoad")
    /* stub */
}

__attribute__((weak)) bool uStageJointCtrl::isBlockArcLoadOk() {
    DDON_STUB("uStageJointCtrl::isBlockArcLoadOk")
    return {};
}

s32 uStageJointCtrl::getInsideAreaNo(MtVector3& realPos) {
    if (mpJointArea != nullptr) {
        if (mpJointArea->mParam.mStartX > realPos.x) {
            return -1;
        } else {
            if (mpJointArea->mParam.mStartZ > realPos.z) {
                return -1;
            } else {
                return mpJointArea->mParam.getAreaData(static_cast<u32>(static_cast<int>((realPos.z - mpJointArea->mParam.mStartZ) / mpJointArea->mParam.mDeltaZ)), static_cast<u32>(static_cast<int>((realPos.x - mpJointArea->mParam.mStartX) / mpJointArea->mParam.mDeltaX)));
            }
        }
    } else {
        return -1;
    }
}

__attribute__((weak)) uSoundOcclusion* uStageJointCtrl::getSoundOcclusion() {
    DDON_STUB("uStageJointCtrl::getSoundOcclusion")
    return nullptr;
}

void uStageJointCtrl::stopMoveUnitLight(bool sleep) {
    if (mJointMdlAry.mLength != 0) {
        u32 v0_0 = mJointMdlAry.mLength;
        unsigned int i0_9 = 0;
        unsigned int i1_3;
        u32 v4_0;
        for (;;) {
            if (mJointMdlAry.getBuffer()[static_cast<int>(i0_9)] == nullptr) {
                v4_0 = v0_0;
            } else {
                uScheduler* pSchdl = static_cast<uStageJointMdl*>(mJointMdlAry.getBuffer()[static_cast<int>(i0_9)])->getLightSdl();
                if (pSchdl == nullptr) {
                    v4_0 = v0_0;
                } else {
                    if (pSchdl->getUnitNum() != 0) {
                        i1_3 = 0;
                        for (;;) {
                            cUnit* t0 = pSchdl->getUnit(i1_3);
                            if (t0 != nullptr) {
                                if (t0->isEnable()) {
                                    if (sleep) {
                                        sUnit::getInstance()->setUnitGroup(t0, 55u);
                                    } else {
                                        sUnit::getInstance()->removeUnitGroup(t0, 55u);
                                    }
                                }
                            }
                            if ((i1_3 + 1u) < pSchdl->getUnitNum()) {
                                i1_3 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    v4_0 = mJointMdlAry.mLength;
                }
            }
            if ((i0_9 + 1u) < v4_0) {
                v0_0 = v4_0;
                i0_9 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void uStageJointCtrl::releaseAllMdlInstancing() {
    DDON_STUB("uStageJointCtrl::releaseAllMdlInstancing")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::updateXZ() {
    DDON_STUB("uStageJointCtrl::updateXZ")
    /* stub */
}

__attribute__((weak)) bool uStageJointCtrl::createStageMdl(const MtVector3& pos, bool isBlocking) {
    DDON_STUB("uStageJointCtrl::createStageMdl")
    return {};
}

__attribute__((weak)) void uStageJointCtrl::removeJointMdlsOutsideLoadedArea(const MtStlVector<int, MtStlAllocator<int> >& loadedAreas) {
    DDON_STUB("uStageJointCtrl::removeJointMdlsOutsideLoadedArea")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::addJointMdlsInsideLoadedArea(const MtStlVector<int, MtStlAllocator<int> >& loadedAreas, bool isBlocking) {
    DDON_STUB("uStageJointCtrl::addJointMdlsInsideLoadedArea")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::updateNaviMesh(bool isBlocking, bool update) {
    DDON_STUB("uStageJointCtrl::updateNaviMesh")
    /* stub */
}

__attribute__((weak)) void uStageJointCtrl::updatePlayerCurrentArea() {
    DDON_STUB("uStageJointCtrl::updatePlayerCurrentArea")
    /* stub */
}

__attribute__((weak)) MtStlVector<int, MtStlAllocator<int> > uStageJointCtrl::getJointAreaList(s32 areaX, s32 areaZ) {
    DDON_STUB("uStageJointCtrl::getJointAreaList")
    __builtin_unreachable();
}

__attribute__((weak)) bool uStageJointCtrl::checkPlayerRange(s32 x, s32 z) {
    DDON_STUB("uStageJointCtrl::checkPlayerRange")
    return {};
}

__attribute__((weak)) bool uStageJointCtrl::checkPlayerRangePos(s32 x, s32 z, MtVector3& pos) const {
    DDON_STUB("uStageJointCtrl::checkPlayerRangePos")
    return {};
}

__attribute__((weak)) bool uStageJointCtrl::updateLot(bool isBlocking, bool update) {
    DDON_STUB("uStageJointCtrl::updateLot")
    return {};
}

__attribute__((weak)) bool uStageJointCtrl::updateArc(bool isBlocking, bool update) {
    DDON_STUB("uStageJointCtrl::updateArc")
    return {};
}

inline uStageJointCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uStageJointCtrl::MyDTI uStageJointCtrl::DTI("uStageJointCtrl", &::cUnit::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* uStageJointCtrl::MyDTI::newInstance() const {
    DDON_STUB("uStageJointCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uStageJointMdl::getDTI() const {
    return uStageJointMdl::DTI;
}

uStageJointMdl::~uStageJointMdl() {
}

__attribute__((weak)) void uStageJointMdl::setup() {
    DDON_STUB("uStageJointMdl::setup")
    /* stub */
}

__attribute__((weak)) void uStageJointMdl::move() {
    DDON_STUB("uStageJointMdl::move")
    /* stub */
}

void uStageJointMdl::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    if (mScrSbcHandle[0] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mScrSbcHandle[0]);
        mScrSbcHandle[0] = 0xFFFFFFFF;
    }
    if (mEffSbcHandle[0] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mEffSbcHandle[0]);
        mEffSbcHandle[0] = 0xFFFFFFFF;
    }
    if (mScrSbcHandle[1] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mScrSbcHandle[1]);
        mScrSbcHandle[1] = 0xFFFFFFFF;
    }
    if (mEffSbcHandle[1] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mEffSbcHandle[1]);
        mEffSbcHandle[1] = 0xFFFFFFFF;
    }
    if (mScrSbcHandle[2] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mScrSbcHandle[2]);
        mScrSbcHandle[2] = 0xFFFFFFFF;
    }
    if (mEffSbcHandle[2] != 0xFFFFFFFFu) {
        sCollision::getInstance()->reserveUnregistResource(mEffSbcHandle[2]);
        mEffSbcHandle[2] = 0xFFFFFFFF;
    }
    if (mpMdlRsrc != nullptr) {
        mpMdlRsrc->release();
        mpMdlRsrc = nullptr;
    }
    if (mpMdlSchdl != nullptr) {
        mpMdlSchdl->kill();
        mpMdlSchdl = nullptr;
    }
    if (mpLightSdlRsrc != nullptr) {
        mpLightSdlRsrc->release();
        mpLightSdlRsrc = nullptr;
    }
    if (mpLightSchdl != nullptr) {
        mpLightSchdl->kill();
        mpLightSchdl = nullptr;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->releaseEfcZone(mEfcColorHandle, 0u);
    u32 v11_9 = cZoneLayout::INVALID_HANDLE;
    mEfcColorHandle = v11_9;
    static_cast<sEffectExt*>(sEffect::getInstance())->releaseEfcZone(mEfcCtrlHandle, 2u);
    static_cast<sEffectExt*>(sEffect::getInstance())->eraseZoneEffectProvider(mEfcCtrlHandle);
    mEfcCtrlHandle = v11_9;
    if (mpEfcColorZone != nullptr) {
        mpEfcColorZone->release();
        mpEfcColorZone = nullptr;
    }
    if (mpEfcCtrlZone != nullptr) {
        mpEfcCtrlZone->release();
        mpEfcCtrlZone = nullptr;
    }
    sWeatherManager::getInstance()->eraseZoneIndoorRes(mIndoorZoneHandle);
    sWeatherManager::getInstance()->eraseLightZoneRes(mLightAndFogZoneHandle);
    mLightAndFogZoneHandle = v11_9;
    sZoneUnitCtrl::getInstance()->eraseZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE_OM, mZoneUnitCtrlHandle[0]);
    sZoneUnitCtrl::getInstance()->eraseZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE_LIGHT, mZoneUnitCtrlHandle[1]);
    sZoneUnitCtrl::getInstance()->eraseZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE_SCRL, mZoneUnitCtrlHandle[2]);
    sZoneStatus::getInstance()->eraseZoneStatus(mZoneStatusHandle);
    static_cast<sSoundExt*>(sSound::getInstance())->releaseBgmSplitAreaResource(reinterpret_cast<uintptr>(this));
    if (mpSoundAreaInfo != nullptr) {
        mpSoundAreaInfo->release();
        mpSoundAreaInfo = nullptr;
    }
    if (mpSoundTrigger != nullptr) {
        mpSoundTrigger->kill();
        mpSoundTrigger = nullptr;
    }
    if (mpSoundGenerator != nullptr) {
        mpSoundGenerator->kill();
        mpSoundGenerator = nullptr;
    }
    if (mpSoundOcclusion != nullptr) {
        mpSoundOcclusion->kill();
        mpSoundOcclusion = nullptr;
    }
    u32 v18_0;
    if (mOmCtrl.mLength == 0) {
        v18_0 = 0;
    } else {
        for (unsigned int i17_3 = 0;;) {
            sOmManager::getInstance()->releaseTreeInsCtrl(static_cast<cOmTreeControl*>(mOmCtrl.getBuffer()[static_cast<int>(i17_3)]));
            if ((i17_3 + 1u) < mOmCtrl.mLength) {
                i17_3 += 1u;
            } else {
                v18_0 = mOmCtrl.mLength;
                break;
            }
        }
    }
    if (mOmCtrl.mAutoDelete) {
        u32 v22_0;
        if (v18_0 != 0) {
            u32 v19_0 = v18_0;
            unsigned int i19_3 = 0;
            u32 v20_0;
            for (;;) {
                if (mOmCtrl.mpArray[i19_3] == nullptr) {
                    v20_0 = v19_0;
                } else {
                    delete mOmCtrl.mpArray[i19_3];
                    v20_0 = mOmCtrl.mLength;
                }
                if ((i19_3 + 1u) < v20_0) {
                    v19_0 = v20_0;
                    i19_3 += 1u;
                } else {
                    break;
                }
            }
            v22_0 = v20_0;
        } else {
            v22_0 = 0;
        }
        memset(static_cast<void*>(mOmCtrl.mpArray), 0, static_cast<size_t>(v22_0) * 8);
    }
    mOmCtrl.mLength = 0;
    if (mpPlantTree != nullptr) {
        mpPlantTree->release();
        mpPlantTree = nullptr;
    }
    cArcLoaderBase* v25_10;
    if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isKeepArchive()) {
        cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
        if (mArcTicket != t0) {
            if (mArcTicket->getArcPtr(0u) != nullptr) {
                sGame* t1 = sGame::getInstance();
                t1->keepArc(mArcTicket->getArcPtr(0u));
            }
            v25_10 = t0;
        } else {
            v25_10 = mArcTicket;
        }
    } else {
        v25_10 = sArchiveManager::INVALID_TICKET;
    }
    if (v25_10 != mArcTicket) {
        sArchiveManager::getInstance()->returnTicket(mArcTicket);
        mArcTicket = v25_10;
    }
    mStageEpvCtrl.releaseEpvCtrl();
    mpGrassReceiver = nullptr;
    if (mSceArray.mLength != 0) {
        u32 v27_0 = mSceArray.mLength;
        unsigned int i27_3 = 0;
        u32 v28_0;
        for (;;) {
            if (mSceArray.mpArray[i27_3] == nullptr) {
                v28_0 = v27_0;
            } else {
                sScenario::getInstance()->release(static_cast<cScenario*>(mSceArray.mpArray[i27_3]));
                mSceArray.mpArray[i27_3] = nullptr;
                v28_0 = mSceArray.mLength;
            }
            if ((i27_3 + 1u) < v28_0) {
                v27_0 = v28_0;
                i27_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSceArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSceArray.mpArray));
    }
    mSceArray.mpArray = nullptr;
    mSceArray.mBufsiz = 0;
    mSceArray.mLength = 0;
    if (mpSbcGeometry != nullptr) {
        mpSbcGeometry->kill();
        mpSbcGeometry = nullptr;
    }
}

void uStageJointMdl::updatePtr() {
    if (mpMdlSchdl != nullptr) {
        if (!mpMdlSchdl->isEnable()) {
            mpMdlSchdl = nullptr;
        }
    }
    if (mpLightSchdl != nullptr) {
        if (!mpLightSchdl->isEnable()) {
            mpLightSchdl = nullptr;
        }
    }
    if (mpSoundTrigger != nullptr) {
        if (!mpSoundTrigger->isEnable()) {
            mpSoundTrigger = nullptr;
        }
    }
    if (mpSoundGenerator != nullptr) {
        if (!mpSoundGenerator->isEnable()) {
            mpSoundGenerator = nullptr;
        }
    }
    if (mpSoundOcclusion != nullptr) {
        if (!mpSoundOcclusion->isEnable()) {
            mpSoundOcclusion = nullptr;
        }
    }
    mStageEpvCtrl.updatePtr();
}

__attribute__((weak)) void uStageJointMdl::loadResource() {
    DDON_STUB("uStageJointMdl::loadResource")
    /* stub */
}

__attribute__((weak)) void uStageJointMdl::setResource() {
    DDON_STUB("uStageJointMdl::setResource")
    /* stub */
}

__attribute__((weak)) void uStageJointMdl::updateGrassReceiver() {
    DDON_STUB("uStageJointMdl::updateGrassReceiver")
    /* stub */
}

void uStageJointMdl::movePlantTree() {
    if (mpPlantTree == nullptr) {
        return;
    } else {
        if (mpParent == nullptr) {
            return;
        } else {
            if (mTreeRno == 1) {
                initPlantTree(mpPlantTree);
                mIsSetTree = true;
            } else {
                u32 v1_0;
                if (mTreeRno != 0) {
                    return;
                } else {
                    if (mOmCtrl.mLength == 0) {
                        v1_0 = 0;
                    } else {
                        for (unsigned int i0_3 = 0;;) {
                            sOmManager::getInstance()->releaseTreeInsCtrl(static_cast<cOmTreeControl*>(mOmCtrl.getBuffer()[static_cast<int>(i0_3)]));
                            if ((i0_3 + 1u) < mOmCtrl.mLength) {
                                i0_3 += 1u;
                            } else {
                                v1_0 = mOmCtrl.mLength;
                                break;
                            }
                        }
                    }
                }
                if (mOmCtrl.mAutoDelete) {
                    u32 v5_0;
                    if (v1_0 != 0) {
                        u32 v2_0 = v1_0;
                        unsigned int i2_3 = 0;
                        u32 v3_0;
                        for (;;) {
                            if (mOmCtrl.mpArray[i2_3] == nullptr) {
                                v3_0 = v2_0;
                            } else {
                                delete mOmCtrl.mpArray[i2_3];
                                v3_0 = mOmCtrl.mLength;
                            }
                            if ((i2_3 + 1u) < v3_0) {
                                v2_0 = v3_0;
                                i2_3 += 1u;
                            } else {
                                break;
                            }
                        }
                        v5_0 = v3_0;
                    } else {
                        v5_0 = 0;
                    }
                    memset(static_cast<void*>(mOmCtrl.mpArray), 0, static_cast<size_t>(v5_0) * 8);
                }
                mOmCtrl.mLength = 0;
            }
        }
    }
    mTreeRno = static_cast<unsigned char>(mTreeRno + 1);
}

__attribute__((weak)) bool uStageJointMdl::initPlantTree(rPlantTree* pRes) {
    DDON_STUB("uStageJointMdl::initPlantTree")
    return {};
}

__attribute__((weak)) void uStageJointMdl::reserveSbcReposition() {
    DDON_STUB("uStageJointMdl::reserveSbcReposition")
    /* stub */
}

void uStageJointMdl::finishSbcReposition() {
    if (mScrSbcHandle[0] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mScrSbcHandle[0], true);
    }
    if (mEffSbcHandle[0] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mEffSbcHandle[0], true);
    }
    if (mScrSbcHandle[1] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mScrSbcHandle[1], true);
    }
    if (mEffSbcHandle[1] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mEffSbcHandle[1], true);
    }
    if (mScrSbcHandle[2] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mScrSbcHandle[2], true);
    }
    if (mEffSbcHandle[2] != 0xFFFFFFFFu) {
        sCollision::getInstance()->setActive(mEffSbcHandle[2], true);
    }
    if (mSbcStatus == 1) {
        mSbcStatus = 2;
    }
    if (mpSbcGeometry != nullptr) {
        mpSbcGeometry->kill();
        mpSbcGeometry = nullptr;
    }
}

inline uStageJointMdl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uStageJointMdl::MyDTI uStageJointMdl::DTI("uStageJointMdl", &::uCoord::DTI, 752ul, 0u, 0u);

__attribute__((weak)) MtObject* uStageJointMdl::MyDTI::newInstance() const {
    DDON_STUB("uStageJointMdl::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uStageJointMdl>::~MtTypedArray();

