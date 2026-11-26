// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cFSMUnit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "aStage.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cAIUserProcess.h"
#include "../../XFramework/cArea.h"
#include "cComponentManager.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cFSMBase.h"
#include "cFSMCore.h"
#include "cFSMOrderParam.h"
#include "cNetGameServer.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "cpEffectProvider.h"
#include "cpEmMontageCtrl.h"
#include "cpEnemyThink.h"
#include "cpEquip.h"
#include "cpFsmCtrl.h"
#include "cpIKCtrl.h"
#include "cpInput.h"
#include "cpMotionSe.h"
#include "cpScrCollision.h"
#include "nCastUtility.h"
#include "../../generated/shared/nDDOMath.h"
#include "nLayout.h"
#include "rDDOModelMontageEm.h"
#include "rEffectProvider.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "../../XFramework/sCollision.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sEnemyManager.h"
#include "sEventManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "sSoundManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "uCharacter.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uNpc.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFSMUnit::getDTI() const {
    return cFSMUnit::DTI;
}

inline MtAllocator* cFSMUnit::getAllocator() {
    return MtMemoryAllocator::getAllocator(cFSMUnit::DTI);
}

void* cFSMUnit::operator new(size_t sz, u32 align) {
    return cFSMUnit::getAllocator()->memAlloc(sz, align, cFSMUnit::DTI.getID());
}

inline void cFSMUnit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cFSMUnit::callbackUpdate() {
    DDON_STUB("cFSMUnit::callbackUpdate")
    /* stub */
}

u32 cFSMUnit::stateUpdateSetWait(MtObject* pParam, MtObject* pCaller) {
    mStatus = 0;
    stateSetWait(pParam, pCaller);
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateSetWait(MtObject* pParam, MtObject* pCaller) {
    if (getOwner() == nullptr) {
        return 0;
    }
    MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
    const MtDTI& t0 = v0_3->getDTI();
    MT_CTSTR v0_1 = uNpc::DTI.mName;
    const MtDTI* v0_0 = &t0;
    const MtDTI* v2_0;
    for (;;) {
        if (v0_1 != v0_0->mName) {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                return 0;
            }
        } else {
            if (v0_3 == nullptr) {
                return 0;
            } else {
                if (static_cast<uDDOModel*>(v0_3)->isDead()) {
                    return 0;
                } else {
                    if (getOwner() != nullptr) {
                        MtObject* v2_10 = static_cast<cpComponent*>(getOwner())->getOwner();
                        const MtDTI& t1 = v2_10->getDTI();
                        MT_CTSTR v2_1 = uDDOModel::DTI.mName;
                        v2_0 = &t1;
                        for (;;) {
                            if (v2_1 != v2_0->mName) {
                                if (v2_0->mpParent != nullptr) {
                                    v2_0 = v2_0->mpParent;
                                } else {
                                    goto loop_1ef9da_end;
                                }
                            } else {
                                if (v2_10 != nullptr) {
                                    cParamSetWait* pParamSetWait = static_cast<cParamSetWait*>(v2_10);
                                    if (static_cast<cUnit*>(v2_10)->isEnable()) {
                                        cpInput* t2 = static_cast<uDDOModel*>(v2_10)->getInputPtr();
                                        if (t2 != nullptr) {
                                            t2->mMoveInfo.type = 0;
                                            t2->mMoveInfo.speed = 0.0f;
                                            mCanMove = false;
                                        }
                                    }
                                }
                                goto loop_1ef9da_end;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    loop_1ef9da_end:;
    if (pParam == nullptr) {
        return 0;
    }
    cParamSetWait* pParamSetWait = static_cast<cParamSetWait*>(pParam);
    bool t3 = pParamSetWait->mIsSetDir;
    mIsSetDir = t3;
    mDir.x = pParamSetWait->mDir.x;
    mDir.y = pParamSetWait->mDir.y;
    mDir.z = pParamSetWait->mDir.z;
    mDir.pad_ = 0.0f;
    if (!t3) {
        return 0;
    }
    if (getOwner() == nullptr) {
        return 0;
    }
    MtObject* v4_3 = static_cast<cpComponent*>(getOwner())->getOwner();
    const MtDTI& t4 = v4_3->getDTI();
    MT_CTSTR v4_1 = uNpc::DTI.mName;
    for (const MtDTI* v4_0 = &t4;;) {
        if (v4_1 != v4_0->mName) {
            if (v4_0->mpParent != nullptr) {
                v4_0 = v4_0->mpParent;
            } else {
                break;
            }
        } else {
            if (v4_3 != nullptr) {
                static_cast<uDDOModel*>(v4_3)->setFinalDir(pParamSetWait->mDir, pParamSetWait->mSpeed);
            }
            return 0;
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetGoto(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetGoto")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetGoto(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetGoto")
    return {};
}

u32 cFSMUnit::stateExitSetGoto(MtObject* pParam, MtObject* pCaller) {
    if (getOwner() != nullptr) {
        MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = uNpc::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (v0_3 != nullptr) {
                    if (static_cast<cUnit*>(v0_3)->isEnable()) {
                        if (mIsForceWarp) {
                            static_cast<uHuman*>(v0_3)->startChangeTrp(0.0f, 1.0f, 30.0f);
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetGotoTarget(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetGotoTarget")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetGotoTarget(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetGotoTarget")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetMotion(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetMotion")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetMotion(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetMotion")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetMotionGoto(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetMotionGoto")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetMotionGoto(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetMotionGoto")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetAction(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetAction")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetEffect(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetEffect")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetNeck(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetNeck")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetNeck(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetNeck")
    return {};
}

u32 cFSMUnit::stateExitSetNeck(MtObject* pParam, MtObject* pCaller) {
    const MtDTI& t0 = pParam->getDTI();
    MT_CTSTR v0_1 = cFSMUnit::cParamSetNeck::DTI.mName;
    if (v0_1 != t0.mName) {
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_0->mpParent == nullptr) {
                return 0;
            } else {
                if (v0_1 != v0_0->mpParent->mName) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
        if (pParam == nullptr) {
            return 0;
        }
    }
    if (getOwner() != nullptr) {
        MtObject* v3_9 = static_cast<cpComponent*>(getOwner())->getOwner();
        const MtDTI& t1 = v3_9->getDTI();
        MT_CTSTR v3_1 = uNpc::DTI.mName;
        for (const MtDTI* v3_0 = &t1;;) {
            if (v3_1 != v3_0->mName) {
                if (v3_0->mpParent != nullptr) {
                    v3_0 = v3_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (v3_9 != nullptr) {
                    cParamSetNeck* pParamSetNeck = static_cast<cParamSetNeck*>(pParam);
                    if (pParamSetNeck->mIsAutoOffCtrl) {
                        static_cast<uNpc*>(v3_9)->setHeadCtrlEnable(pParamSetNeck->mIsSetNeck, false);
                    }
                }
                break;
            }
        }
        if (getOwner() != nullptr) {
            MtObject* v5_3 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t2 = v5_3->getDTI();
            MT_CTSTR v5_1 = uEnemy::DTI.mName;
            for (const MtDTI* v5_0 = &t2;;) {
                if (v5_1 != v5_0->mName) {
                    if (v5_0->mpParent != nullptr) {
                        v5_0 = v5_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v5_3 != nullptr) {
                        if (static_cast<uEnemy*>(v5_3)->findcpEnemyThink() != nullptr) {
                            static_cast<uEnemy*>(v5_3)->findcpEnemyThink()->mIsFmsTarget = false;
                        }
                    }
                    break;
                }
            }
        }
    }
    sUnit::getInstance()->remove(static_cast<cUnit*>(mpEvHeadTarget));
    if (mpEvHeadTarget != nullptr) {
        delete mpEvHeadTarget;
        mpEvHeadTarget = nullptr;
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetEyeBall(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetEyeBall")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetEyeBall(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetEyeBall")
    return {};
}

u32 cFSMUnit::stateUpdateSetEmDie(MtObject* pParam, MtObject* pCaller) {
    mRno = 0;
    stateSetEmDie(pParam, pCaller);
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateSetEmDie(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetEmDie")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetWaypoint(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetWaypoint")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetWaypoint(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetWaypoint")
    return {};
}

u32 cFSMUnit::stateExitSetWaypoint(MtObject* pParam, MtObject* pCaller) {
    if (getOwner() != nullptr) {
        MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = uNpc::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (v0_3 != nullptr) {
                    if (static_cast<cUnit*>(v0_3)->isEnable()) {
                        if (mIsForceWarp) {
                            static_cast<uHuman*>(v0_3)->startChangeTrp(0.0f, 1.0f, 30.0f);
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateChangeThink(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateChangeThink")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetAdjScr(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetAdjScr")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetAttendNpc(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetAttendNpc")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetDisableTouchAction(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetDisableTouchAction")
    return {};
}

u32 cFSMUnit::stateUpdateSetOpenDoor(MtObject* pParam, MtObject* pCaller) {
    const MtDTI& t0 = pParam->getDTI();
    MT_CTSTR v0_1 = cFSMOrderParamSetOpenDoor::DTI.mName;
    if (v0_1 != t0.mName) {
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_0->mpParent == nullptr) {
                return 0;
            } else {
                if (v0_1 != v0_0->mpParent->mName) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
        if (pParam == nullptr) {
            return 0;
        }
    }
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        cFSMOrderParamSetOpenDoor* pParamSetOpenDoor = static_cast<cFSMOrderParamSetOpenDoor*>(pParam);
        if (pParamSetOpenDoor->mIsQuestSet) {
            u32 t1 = nLayout::createUniqueIDQuestSet(pParamSetOpenDoor->mQuestId, static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageNo(), pParamSetOpenDoor->mGroupNo, pParamSetOpenDoor->mSetNo);
            sOmManager::getInstance()->setOpenDoor(t1);
        } else {
            u32 t2 = nLayout::createUniqueID(nLayout::U_OM, pParamSetOpenDoor->mGroupNo, pParamSetOpenDoor->mSetNo, static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageNo());
            sOmManager::getInstance()->setOpenDoor(t2);
        }
    }
    return 0;
}

u32 cFSMUnit::stateUpdateSetDispWeapon(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_3->getDTI();
            MT_CTSTR v0_1 = uNpc::DTI.mName;
            const MtDTI* v0_0 = &t0;
            const MtDTI* v2_0;
            for (;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_3 != nullptr) {
                        uControl* pCtrl = static_cast<uDDOModel*>(v0_3)->getCtrl();
                        if (pCtrl != nullptr) {
                            const MtDTI& t2 = pCtrl->getDTI();
                            MT_CTSTR v2_1 = uControlNpc::DTI.mName;
                            v2_0 = &t2;
                            for (;;) {
                                if (v2_1 != v2_0->mName) {
                                    if (v2_0->mpParent != nullptr) {
                                        v2_0 = v2_0->mpParent;
                                    } else {
                                        break;
                                    }
                                } else {
                                    cParamSetDispWeapon* pParamSetDispWep = static_cast<cParamSetDispWeapon*>(pParam);
                                    uControlNpc* pCtrlNpc = static_cast<uControlNpc*>(pCtrl);
                                    pCtrlNpc->mIsDispWepMain = pParamSetDispWep->mIsDispWepMain;
                                    pCtrlNpc->mIsDispWepSub = pParamSetDispWep->mIsDispWepSub;
                                    goto loop_1f3993_end;
                                }
                            }
                        }
                    }
                    break;
                }
            }
            loop_1f3993_end:;
        }
    }
    return 0;
}

u32 cFSMUnit::stateUpdateSetShadowCast(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_9->getDTI();
            MT_CTSTR v0_1 = uDDOModel::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_9 != nullptr) {
                        cParamSetShadowCast* pParamSetShadowCast = static_cast<cParamSetShadowCast*>(pParam);
                        if (pParamSetShadowCast->mIsShadowCast) {
                            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 20) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 20)) | 520u;
                        } else {
                            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 20) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 20)) & 0xFFFFFDF7u;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetHaveThing(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetHaveThing")
    return {};
}

u32 cFSMUnit::stateUpdateSetCallSeUnit(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        mStartFrame = sMain::getInstance()->getFrameTimer();
        mRnoSE = 0;
    }
    return 0;
}

u32 cFSMUnit::stateSetCallSeUnit(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (mRnoSE == 0) {
            cParamSetCallSe* pParamSetCallSe = static_cast<cParamSetCallSe*>(pParam);
            if ((sMain::getInstance()->getFrameTimer() - mStartFrame) < pParamSetCallSe->mDelayFrame) {
            } else {
                if (getOwner() != nullptr) {
                    MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
                    const MtDTI& t0 = v0_9->getDTI();
                    MT_CTSTR v0_1 = uDDOModel::DTI.mName;
                    for (const MtDTI* v0_0 = &t0;;) {
                        if (v0_1 != v0_0->mName) {
                            if (v0_0->mpParent != nullptr) {
                                v0_0 = v0_0->mpParent;
                            } else {
                                break;
                            }
                        } else {
                            if (v0_9 != nullptr) {
                                sEventManager::getInstance()->callEventSe(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pParam) + 8), static_cast<uCoord*>(v0_9), static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pParam) + 12)));
                            }
                            break;
                        }
                    }
                }
                mRnoSE = mRnoSE + 1u;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetHakuryuStoneLevel(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetHakuryuStoneLevel")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetParts(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetParts")
    return {};
}

u32 cFSMUnit::stateUpdateSetVibUnit(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cParamSetVibUnit* pParamSetVibUnit = static_cast<cParamSetVibUnit*>(pParam);
        sEventManager::getInstance()->reqEventVib(pParamSetVibUnit->mVib);
        return 0;
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetEmMontage(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetEmMontage")
    return {};
}

u32 cFSMUnit::stateUpdateSetHeadCtrl(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_9->getDTI();
            MT_CTSTR v0_1 = uDDOModel::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_9 != nullptr) {
                        if (static_cast<uDDOModel*>(v0_9)->isNpc()) {
                            cParamSetHeadCtrl* pParamSetHeadCtrl = static_cast<cParamSetHeadCtrl*>(pParam);
                            static_cast<uNpc*>(v0_9)->setHeadCtrl(pParamSetHeadCtrl->mHeadCtrl);
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

u32 cFSMUnit::stateUpdateSetEyeClose(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_9->getDTI();
            MT_CTSTR v0_1 = uDDOModel::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_9 != nullptr) {
                        if (static_cast<uDDOModel*>(v0_9)->getCtrlNpc() != nullptr) {
                            uControlNpc* t1 = static_cast<uDDOModel*>(v0_9)->getCtrlNpc();
                            cParamSetEyeClose* pParamSetEyeClose = static_cast<cParamSetEyeClose*>(pParam);
                            t1->mIsEyeClose = pParamSetEyeClose->mEyeClose;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

u32 cFSMUnit::stateUpdateSetDispMiniMap(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_9->getDTI();
            MT_CTSTR v0_1 = uDDOModel::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_9 != nullptr) {
                        if (static_cast<uDDOModel*>(v0_9)->getCtrlNpc() != nullptr) {
                            uControlNpc* t1 = static_cast<uDDOModel*>(v0_9)->getCtrlNpc();
                            cParamSetDispMiniMap* pParamSetDispMiniMap = static_cast<cParamSetDispMiniMap*>(pParam);
                            t1->mIsDispMiniMap = pParamSetDispMiniMap->mIsDispMiniMap;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

u32 cFSMUnit::stateUpdateSetIK(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        if (getOwner() != nullptr) {
            MtObject* v0_9 = static_cast<cpComponent*>(getOwner())->getOwner();
            const MtDTI& t0 = v0_9->getDTI();
            MT_CTSTR v0_1 = uDDOModel::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v0_9 != nullptr) {
                        if (static_cast<uDDOModel*>(v0_9)->isNpc()) {
                            uNpc* pNpc = static_cast<uNpc*>(v0_9);
                            cParamSetIK* pParamSetIK = static_cast<cParamSetIK*>(pParam);
                            pNpc->mpIKCtrl->setActive(pParamSetIK->mActive);
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetGotoInitPos(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetGotoInitPos")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateSetGotoInitPos(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateSetGotoInitPos")
    return {};
}

__attribute__((weak)) u32 cFSMUnit::stateUpdateSetEnemyHP(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMUnit::stateUpdateSetEnemyHP")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isStop() {
    DDON_STUB("cFSMUnit::isStop")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isStop(const MtVector3& targetPos) {
    DDON_STUB("cFSMUnit::isStop")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isEndSetMotion() const {
    DDON_STUB("cFSMUnit::isEndSetMotion")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isLand() const {
    DDON_STUB("cFSMUnit::isLand")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isGoalWaypoint() const {
    DDON_STUB("cFSMUnit::isGoalWaypoint")
    return {};
}

u32 cFSMUnit::getHp() const {
    HP_DATATYPE v2_8;
    if (getOwner() == nullptr) {
        v2_8 = 0;
    } else {
        MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = uCharacter::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (v0_3 == nullptr) {
                    v2_8 = 0;
                } else {
                    v2_8 = static_cast<uDDOModel*>(v0_3)->getHp(0u);
                }
                return static_cast<unsigned int>(v2_8);
            }
        }
        v2_8 = 0;
    }
    return static_cast<unsigned int>(v2_8);
}

__attribute__((weak)) f32 cFSMUnit::getHpPercent() const {
    DDON_STUB("cFSMUnit::getHpPercent")
    return {};
}

__attribute__((weak)) f32 cFSMUnit::getDistanceToPlayer() const {
    DDON_STUB("cFSMUnit::getDistanceToPlayer")
    return {};
}

__attribute__((weak)) f32 cFSMUnit::getDistanceToLeader() const {
    DDON_STUB("cFSMUnit::getDistanceToLeader")
    return {};
}

bool cFSMUnit::isUpdateWaypoint() const {
    return sQuestManagerExt::getInstance()->isUpdateWaypoint();
}

__attribute__((weak)) f32 cFSMUnit::getDistanceToEnemy() const {
    DDON_STUB("cFSMUnit::getDistanceToEnemy")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isBattleStartMogock() {
    DDON_STUB("cFSMUnit::isBattleStartMogock")
    return {};
}

__attribute__((weak)) bool cFSMUnit::isDiedMogock() {
    DDON_STUB("cFSMUnit::isDiedMogock")
    return {};
}

bool cFSMUnit::isChangeMaster() const {
    return mIsChangeMaster;
}

bool cFSMUnit::isExistEnemyUnit() const {
    return sEnemyManager::getInstance()->mRefArray.mLength != 0;
}

bool cFSMUnit::isTouchActionFromPlayer() const {
    if (getOwner() != nullptr) {
        MtObject* v0_3 = static_cast<cpComponent*>(getOwner())->getOwner();
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = uCharacter::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                uPlayer* t1 = sPlayerManager::getInstance()->getMyPlayer();
                if (t1 != nullptr) {
                    if (v0_3 != nullptr) {
                        if (t1->isTouchNow()) {
                            if (v0_3 == t1->mpTouchSelectTarget) {
                                return true;
                            }
                        }
                    }
                }
                break;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) f32 cFSMUnit::getDistanceToInitPos() const {
    DDON_STUB("cFSMUnit::getDistanceToInitPos")
    return {};
}

__attribute__((weak)) void cFSMUnit::openDoor() {
    DDON_STUB("cFSMUnit::openDoor")
    /* stub */
}

__attribute__((weak)) bool cFSMUnit::setMoveInput(const MtVector3& targetPos, u8 moveType) {
    DDON_STUB("cFSMUnit::setMoveInput")
    return {};
}

__attribute__((weak)) void cFSMUnit::followNpcWarp(f32 distance, uNpc* pNpc) {
    DDON_STUB("cFSMUnit::followNpcWarp")
    /* stub */
}

__attribute__((weak)) void cFSMUnit::implStateUpdateSetMotionHuman(uHuman* pHuman, cFSMUnit::cParamSetMotion* pParam) {
    DDON_STUB("cFSMUnit::implStateUpdateSetMotionHuman")
    /* stub */
}

__attribute__((weak)) void cFSMUnit::implStateSetNeckNpc(uNpc* pNpc, cFSMUnit::cParamSetNeck* pParam) {
    DDON_STUB("cFSMUnit::implStateSetNeckNpc")
    /* stub */
}

__attribute__((weak)) void cFSMUnit::implStateUpdateSetMotionEnemy(uEnemy* pEnemy, cFSMUnit::cParamSetMotion* pParam) {
    DDON_STUB("cFSMUnit::implStateUpdateSetMotionEnemy")
    /* stub */
}

cFSMUnit::cFSMUnit() {
    DDON_STUB("cFSMUnit::cFSMUnit")
    /* stub */
}

__attribute__((weak)) void cFSMUnit::move() {
    DDON_STUB("cFSMUnit::move")
    /* stub */
}

__attribute__((weak)) void cFSMUnit::createPropertyFSM(MtPropertyList& s) {
    DDON_STUB("cFSMUnit::createPropertyFSM")
    /* stub */
}

inline cFSMUnit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::MyDTI cFSMUnit::DTI("cFSMUnit", &::cFSMBase::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMUnit::MyDTI::newInstance() const {
    DDON_STUB("cFSMUnit::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMUnit::uEvHeadTarget::getDTI() const {
    return cFSMUnit::uEvHeadTarget::DTI;
}

inline void* cFSMUnit::uEvHeadTarget::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::uEvHeadTarget::DTI)->memAlloc(sz, align, cFSMUnit::uEvHeadTarget::DTI.getID());
}

inline void cFSMUnit::uEvHeadTarget::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::uEvHeadTarget::DTI)->memFree(p_addr);
}

inline cFSMUnit::uEvHeadTarget::uEvHeadTarget() {
    mType = 0;
    mGroup = 0;
    mId = 0;
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mTargetOfsPos.x = MtVector3::Zero.x;
    mTargetOfsPos.y = MtVector3::Zero.y;
    mTargetOfsPos.z = MtVector3::Zero.z;
    mTargetOfsPos.pad_ = 0.0f;
    mTargetJointId = 0;
}

void cFSMUnit::uEvHeadTarget::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOfsPos", &mTargetOfsPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJointId", &mTargetJointId, 0u, 0u);
}

__attribute__((weak)) void cFSMUnit::uEvHeadTarget::setup() {
}

void cFSMUnit::uEvHeadTarget::move() {
    updateParam();
}

__attribute__((weak)) void cFSMUnit::uEvHeadTarget::kill() {
}

__attribute__((weak)) void cFSMUnit::uEvHeadTarget::updateParam() {
    DDON_STUB("cFSMUnit::uEvHeadTarget::updateParam")
    /* stub */
}

inline cFSMUnit::uEvHeadTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::uEvHeadTarget::MyDTI cFSMUnit::uEvHeadTarget::DTI("cFSMUnit::uEvHeadTarget", &::uCoord::DTI, 336ul, 0u, 0u);

MtObject* cFSMUnit::uEvHeadTarget::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::uEvHeadTarget;
}

const MtDTI& cFSMUnit::cParamSetMotion::getDTI() const {
    return cFSMUnit::cParamSetMotion::DTI;
}

inline void* cFSMUnit::cParamSetMotion::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetMotion::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetMotion::DTI.getID());
}

inline void cFSMUnit::cParamSetMotion::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetMotion::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetMotion::cParamSetMotion() {
    mBankNo = 8;
    mMotNo = 0;
    mHokan = 5.0f;
    mStartFrame = 0.0f;
    mEndFrame = 0.0f;
    mMotSpeed = 1.0f;
    mIsLoop = true;
    mIsSetDir = false;
    mIsDispItem = false;
    mIsSetEndFrame = false;
    mIsNullTransFix = false;
    mIsNullTransOff = false;
    mIsNullAngleFix = false;
    mDir.x = MtVector3::AxisX.x;
    mDir.y = MtVector3::AxisX.y;
    mDir.z = MtVector3::AxisX.z;
    mDir.pad_ = 0.0f;
    mSpeed = 0.087266475f;
    mIsCallVoice = true;
    mIsUseFingerMotion = false;
    mFingerMotionNo = 0;
    mFingerHokan = 5.0f;
    mFingerSpeed = 1.0f;
    mIsDisableFall = false;
    mMotionSeOffBank = -1;
}

__attribute__((weak)) void cFSMUnit::cParamSetMotion::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBankNo", &mBankNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMotNo", &mMotNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHokan", &mHokan, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartFrame", &mStartFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetEndFrame", &mIsSetEndFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndFrame", &mEndFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMotSpeed", &mMotSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLoop", &mIsLoop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNullTransFix", &mIsNullTransFix, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNullTransOff", &mIsNullTransOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNullAngleFix", &mIsNullAngleFix, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetDir", &mIsSetDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsDispItem", &mIsDispItem, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDir", &mDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeed", &mSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCallVoice", &mIsCallVoice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseFingerMotion", &mIsUseFingerMotion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFingerHokan", &mFingerHokan, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFingerSpeed", &mFingerSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFingerMotionNo", &mFingerMotionNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsDisableFall", &mIsDisableFall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMotionSeOffBank", &mMotionSeOffBank, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetMotion::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetMotion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetMotion::MyDTI cFSMUnit::cParamSetMotion::DTI("cFSMUnit::cParamSetMotion", &::cAICopiableParameter::DTI, 96ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetMotion::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetMotion;
}

const MtDTI& cFSMUnit::cParamSetAction::getDTI() const {
    return cFSMUnit::cParamSetAction::DTI;
}

inline void* cFSMUnit::cParamSetAction::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAction::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetAction::DTI.getID());
}

inline void cFSMUnit::cParamSetAction::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAction::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetAction::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mActionType", &mActionType, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetAction::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetAction::MyDTI cFSMUnit::cParamSetAction::DTI("cFSMUnit::cParamSetAction", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetAction::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetAction;
}

const MtDTI& cFSMUnit::cParamSetNeck::getDTI() const {
    return cFSMUnit::cParamSetNeck::DTI;
}

inline void* cFSMUnit::cParamSetNeck::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetNeck::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetNeck::DTI.getID());
}

inline void cFSMUnit::cParamSetNeck::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetNeck::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetNeck::cParamSetNeck() {
    mIsSetNeck = false;
    mTargetType = 0;
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mTargetGroup = 0;
    mTargetSetId = 0;
    mTargetJointId = -1;
    mDisableSequence = false;
    mIsAutoOffCtrl = true;
    mSpeedRate = 1.0f;
}

void cFSMUnit::cParamSetNeck::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetNeck", &mIsSetNeck, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetType", &mTargetType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetGroup", &mTargetGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetSetId", &mTargetSetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJointId", &mTargetJointId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableSequence", &mDisableSequence, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAutoOffCtrl", &mIsAutoOffCtrl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeedRate", &mSpeedRate, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetNeck::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetNeck::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetNeck::MyDTI cFSMUnit::cParamSetNeck::DTI("cFSMUnit::cParamSetNeck", &::cAICopiableParameter::DTI, 64ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetNeck::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetNeck;
}

const MtDTI& cFSMUnit::cParamSetWait::getDTI() const {
    return cFSMUnit::cParamSetWait::DTI;
}

inline void* cFSMUnit::cParamSetWait::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetWait::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetWait::DTI.getID());
}

inline void cFSMUnit::cParamSetWait::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetWait::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetWait::cParamSetWait() {
    mIsSetDir = false;
    mDir.x = MtVector3::AxisX.x;
    mDir.y = MtVector3::AxisX.y;
    mDir.z = MtVector3::AxisX.z;
    mDir.pad_ = 0.0f;
    mSpeed = 0.087266475f;
}

void cFSMUnit::cParamSetWait::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetDir", &mIsSetDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDir", &mDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeed", &mSpeed, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetWait::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetWait::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetWait::MyDTI cFSMUnit::cParamSetWait::DTI("cFSMUnit::cParamSetWait", &::cAICopiableParameter::DTI, 48ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetWait::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetWait;
}

const MtDTI& cFSMUnit::cParamSetGoto::getDTI() const {
    return cFSMUnit::cParamSetGoto::DTI;
}

inline void* cFSMUnit::cParamSetGoto::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetGoto::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetGoto::DTI.getID());
}

inline void cFSMUnit::cParamSetGoto::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetGoto::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetGoto::cParamSetGoto() {
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mRunType = 0;
    mStopBorder = 50.0f;
    mIsSetDir = false;
    mIsPathFinding = false;
    mDir.x = MtVector3::AxisX.x;
    mDir.y = MtVector3::AxisX.y;
    mDir.z = MtVector3::AxisX.z;
    mDir.pad_ = 0.0f;
    mSpeed = 0.087266475f;
}

void cFSMUnit::cParamSetGoto::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRunType", &mRunType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStopBorder", &mStopBorder, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetDir", &mIsSetDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsPathFinding", &mIsPathFinding, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDir", &mDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeed", &mSpeed, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetGoto::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetGoto::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetGoto::MyDTI cFSMUnit::cParamSetGoto::DTI("cFSMUnit::cParamSetGoto", &::cAICopiableParameter::DTI, 80ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetGoto::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetGoto;
}

const MtDTI& cFSMUnit::cParamSetGotoTarget::getDTI() const {
    return cFSMUnit::cParamSetGotoTarget::DTI;
}

inline void* cFSMUnit::cParamSetGotoTarget::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetGotoTarget::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetGotoTarget::DTI.getID());
}

inline void cFSMUnit::cParamSetGotoTarget::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetGotoTarget::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetGotoTarget::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetType", &mTargetType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetId", &mTargetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetBorder", &mIsSetBorder, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsPathFinding", &mIsPathFinding, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStopBorder", &mStopBorder, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRunType", &mRunType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseWarp", &mIsUseWarp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWarpDist", &mWarpDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableNoFall", &mEnableNoFall, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetGotoTarget::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetGotoTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetGotoTarget::MyDTI cFSMUnit::cParamSetGotoTarget::DTI("cFSMUnit::cParamSetGotoTarget", &::cAICopiableParameter::DTI, 40ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetGotoTarget::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetGotoTarget;
}

const MtDTI& cFSMUnit::cParamSetMotionGoto::getDTI() const {
    return cFSMUnit::cParamSetMotionGoto::DTI;
}

inline void* cFSMUnit::cParamSetMotionGoto::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetMotionGoto::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetMotionGoto::DTI.getID());
}

inline void cFSMUnit::cParamSetMotionGoto::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetMotionGoto::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetMotionGoto::cParamSetMotionGoto() {
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mStopBorder = 50.0f;
    mIsSetVelocity = false;
    mVelocity.x = MtVector3::Zero.x;
    mVelocity.y = MtVector3::Zero.y;
    mVelocity.z = MtVector3::Zero.z;
    mVelocity.pad_ = 0.0f;
    mAcceleration.x = MtVector3::Zero.x;
    mAcceleration.y = MtVector3::Zero.y;
    mAcceleration.z = MtVector3::Zero.z;
    mIsHover = false;
    mAccelerationScalar = 0.0f;
    mAcceleration.pad_ = 0.0f;
    mVelocityScalar = 0.0f;
    mIsPosHokan = true;
    mBankNo = 5;
}

void cFSMUnit::cParamSetMotionGoto::createProperty(MtPropertyList& s) {
    this->cFSMUnit::cParamSetMotion::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStopBorder", &mStopBorder, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSetVelocity", &mIsSetVelocity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVelocityScalar", &mVelocityScalar, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAccelerationScalar", &mAccelerationScalar, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsHover", &mIsHover, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsPosHokan", &mIsPosHokan, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetMotionGoto::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetMotionGoto::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetMotionGoto::MyDTI cFSMUnit::cParamSetMotionGoto::DTI("cFSMUnit::cParamSetMotionGoto", &::cFSMUnit::cParamSetMotion::DTI, 176ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetMotionGoto::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetMotionGoto;
}

const MtDTI& cFSMUnit::cParamSetEffect::getDTI() const {
    return cFSMUnit::cParamSetEffect::DTI;
}

inline void* cFSMUnit::cParamSetEffect::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEffect::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEffect::DTI.getID());
}

inline void cFSMUnit::cParamSetEffect::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEffect::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetEffect::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEfcId", &mEfcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHaveItem", &mHaveItem, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAct", &mAct, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmId", &mOmId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElement", &mElement, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetEffect::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEffect::MyDTI cFSMUnit::cParamSetEffect::DTI("cFSMUnit::cParamSetEffect", &::cAICopiableParameter::DTI, 32ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEffect::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEffect;
}

const MtDTI& cFSMUnit::cParamSetEyeBall::getDTI() const {
    return cFSMUnit::cParamSetEyeBall::DTI;
}

inline void* cFSMUnit::cParamSetEyeBall::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEyeBall::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEyeBall::DTI.getID());
}

inline void cFSMUnit::cParamSetEyeBall::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEyeBall::DTI)->memFree(p_addr);
}

inline cFSMUnit::cParamSetEyeBall::cParamSetEyeBall() {
    mTargetAngle.x = MtVector3::Zero.x;
    mTargetAngle.y = MtVector3::Zero.y;
    mTargetAngle.z = MtVector3::Zero.z;
    mTargetAngle.pad_ = 0.0f;
    mHokanFrame = 5;
    mDelayFrame = 0;
}

void cFSMUnit::cParamSetEyeBall::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTargetAngle", &mTargetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHokanFrame", &mHokanFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDelayFrame", &mDelayFrame, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetEyeBall::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetEyeBall::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEyeBall::MyDTI cFSMUnit::cParamSetEyeBall::DTI("cFSMUnit::cParamSetEyeBall", &::cAICopiableParameter::DTI, 48ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEyeBall::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEyeBall;
}

const MtDTI& cFSMUnit::cParamSetEmDie::getDTI() const {
    return cFSMUnit::cParamSetEmDie::DTI;
}

inline void* cFSMUnit::cParamSetEmDie::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEmDie::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEmDie::DTI.getID());
}

inline void cFSMUnit::cParamSetEmDie::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEmDie::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetEmDie::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAct", &mAct, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetEmDie::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetEmDie::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEmDie::MyDTI cFSMUnit::cParamSetEmDie::DTI("cFSMUnit::cParamSetEmDie", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEmDie::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEmDie;
}

const MtDTI& cFSMUnit::cParamSetWaypoint::getDTI() const {
    return cFSMUnit::cParamSetWaypoint::DTI;
}

inline void* cFSMUnit::cParamSetWaypoint::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetWaypoint::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetWaypoint::DTI.getID());
}

inline void cFSMUnit::cParamSetWaypoint::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetWaypoint::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetWaypoint::~cParamSetWaypoint() {
}

void cFSMUnit::cParamSetWaypoint::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGotoPointNo", &mGotoPointNo, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetWaypoint::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetWaypoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetWaypoint::MyDTI cFSMUnit::cParamSetWaypoint::DTI("cFSMUnit::cParamSetWaypoint", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetWaypoint::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetWaypoint;
}

const MtDTI& cFSMUnit::cParamSetChangeThink::getDTI() const {
    return cFSMUnit::cParamSetChangeThink::DTI;
}

inline void* cFSMUnit::cParamSetChangeThink::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetChangeThink::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetChangeThink::DTI.getID());
}

inline void cFSMUnit::cParamSetChangeThink::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetChangeThink::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetChangeThink::~cParamSetChangeThink() {
}

void cFSMUnit::cParamSetChangeThink::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mThink", &mThink, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsInvincible", &mIsInvincible, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetChangeThink::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetChangeThink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetChangeThink::MyDTI cFSMUnit::cParamSetChangeThink::DTI("cFSMUnit::cParamSetChangeThink", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetChangeThink::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetChangeThink;
}

const MtDTI& cFSMUnit::cParamSetAdjustScrHit::getDTI() const {
    return cFSMUnit::cParamSetAdjustScrHit::DTI;
}

inline void* cFSMUnit::cParamSetAdjustScrHit::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAdjustScrHit::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetAdjustScrHit::DTI.getID());
}

inline void cFSMUnit::cParamSetAdjustScrHit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAdjustScrHit::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetAdjustScrHit::~cParamSetAdjustScrHit() {
}

void cFSMUnit::cParamSetAdjustScrHit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsStop", &mIsStop, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetAdjustScrHit::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetAdjustScrHit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetAdjustScrHit::MyDTI cFSMUnit::cParamSetAdjustScrHit::DTI("cFSMUnit::cParamSetAdjustScrHit", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetAdjustScrHit::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetAdjustScrHit;
}

const MtDTI& cFSMUnit::cParamSetAttendNpc::getDTI() const {
    return cFSMUnit::cParamSetAttendNpc::DTI;
}

inline void* cFSMUnit::cParamSetAttendNpc::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAttendNpc::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetAttendNpc::DTI.getID());
}

inline void cFSMUnit::cParamSetAttendNpc::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetAttendNpc::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetAttendNpc::~cParamSetAttendNpc() {
}

void cFSMUnit::cParamSetAttendNpc::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsAttend", &mIsAttend, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetAttendNpc::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetAttendNpc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetAttendNpc::MyDTI cFSMUnit::cParamSetAttendNpc::DTI("cFSMUnit::cParamSetAttendNpc", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetAttendNpc::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetAttendNpc;
}

const MtDTI& cFSMUnit::cParamSetDisableTouchAction::getDTI() const {
    return cFSMUnit::cParamSetDisableTouchAction::DTI;
}

inline void* cFSMUnit::cParamSetDisableTouchAction::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDisableTouchAction::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetDisableTouchAction::DTI.getID());
}

inline void cFSMUnit::cParamSetDisableTouchAction::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDisableTouchAction::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetDisableTouchAction::~cParamSetDisableTouchAction() {
}

void cFSMUnit::cParamSetDisableTouchAction::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsDisableTouch", &mIsDisableTouch, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetDisableTouchAction::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetDisableTouchAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetDisableTouchAction::MyDTI cFSMUnit::cParamSetDisableTouchAction::DTI("cFSMUnit::cParamSetDisableTouchAction", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetDisableTouchAction::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetDisableTouchAction;
}

const MtDTI& cFSMUnit::cParamSetDispWeapon::getDTI() const {
    return cFSMUnit::cParamSetDispWeapon::DTI;
}

inline void* cFSMUnit::cParamSetDispWeapon::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDispWeapon::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetDispWeapon::DTI.getID());
}

inline void cFSMUnit::cParamSetDispWeapon::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDispWeapon::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetDispWeapon::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsDispWepMain", &mIsDispWepMain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsDispWepSub", &mIsDispWepSub, 0u, 0u);
}

inline cFSMUnit::cParamSetDispWeapon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetDispWeapon::MyDTI cFSMUnit::cParamSetDispWeapon::DTI("cFSMUnit::cParamSetDispWeapon", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetDispWeapon::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetDispWeapon;
}

const MtDTI& cFSMUnit::cParamSetShadowCast::getDTI() const {
    return cFSMUnit::cParamSetShadowCast::DTI;
}

inline void* cFSMUnit::cParamSetShadowCast::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetShadowCast::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetShadowCast::DTI.getID());
}

inline void cFSMUnit::cParamSetShadowCast::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetShadowCast::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetShadowCast::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsShadowCast", &mIsShadowCast, 0u, 0u);
}

inline cFSMUnit::cParamSetShadowCast::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetShadowCast::MyDTI cFSMUnit::cParamSetShadowCast::DTI("cFSMUnit::cParamSetShadowCast", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetShadowCast::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetShadowCast;
}

const MtDTI& cFSMUnit::cParamSetHaveThing::getDTI() const {
    return cFSMUnit::cParamSetHaveThing::DTI;
}

inline void* cFSMUnit::cParamSetHaveThing::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHaveThing::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetHaveThing::DTI.getID());
}

inline void cFSMUnit::cParamSetHaveThing::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHaveThing::DTI)->memFree(p_addr);
}

cFSMUnit::cParamSetHaveThing::~cParamSetHaveThing() {
}

void cFSMUnit::cParamSetHaveThing::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHaveThing", &mHaveThing, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetHaveThing::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetHaveThing::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetHaveThing::MyDTI cFSMUnit::cParamSetHaveThing::DTI("cFSMUnit::cParamSetHaveThing", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetHaveThing::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetHaveThing;
}

const MtDTI& cFSMUnit::cParamSetCallSe::getDTI() const {
    return cFSMUnit::cParamSetCallSe::DTI;
}

inline void* cFSMUnit::cParamSetCallSe::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetCallSe::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetCallSe::DTI.getID());
}

inline void cFSMUnit::cParamSetCallSe::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetCallSe::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetCallSe::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSeId", &mSeId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDelayFrame", &mDelayFrame, 0u, 0u);
}

inline cFSMUnit::cParamSetCallSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetCallSe::MyDTI cFSMUnit::cParamSetCallSe::DTI("cFSMUnit::cParamSetCallSe", &::cAICopiableParameter::DTI, 24ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetCallSe::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetCallSe;
}

const MtDTI& cFSMUnit::cParamSetHakuryuStoneLevel::getDTI() const {
    return cFSMUnit::cParamSetHakuryuStoneLevel::DTI;
}

inline void* cFSMUnit::cParamSetHakuryuStoneLevel::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHakuryuStoneLevel::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetHakuryuStoneLevel::DTI.getID());
}

inline void cFSMUnit::cParamSetHakuryuStoneLevel::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHakuryuStoneLevel::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetHakuryuStoneLevel::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStoneLevel", &mStoneLevel, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetHakuryuStoneLevel::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetHakuryuStoneLevel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetHakuryuStoneLevel::MyDTI cFSMUnit::cParamSetHakuryuStoneLevel::DTI("cFSMUnit::cParamSetHakuryuStoneLevel", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetHakuryuStoneLevel::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetHakuryuStoneLevel;
}

const MtDTI& cFSMUnit::cParamSetParts::getDTI() const {
    return cFSMUnit::cParamSetParts::DTI;
}

inline void* cFSMUnit::cParamSetParts::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetParts::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetParts::DTI.getID());
}

inline void cFSMUnit::cParamSetParts::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetParts::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetParts::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParts", &mParts, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetParts::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetParts::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetParts::MyDTI cFSMUnit::cParamSetParts::DTI("cFSMUnit::cParamSetParts", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetParts::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetParts;
}

const MtDTI& cFSMUnit::cParamSetVibUnit::getDTI() const {
    return cFSMUnit::cParamSetVibUnit::DTI;
}

inline void* cFSMUnit::cParamSetVibUnit::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetVibUnit::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetVibUnit::DTI.getID());
}

inline void cFSMUnit::cParamSetVibUnit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetVibUnit::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetVibUnit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mVib", &mVib, 0u, 0u);
}

inline cFSMUnit::cParamSetVibUnit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetVibUnit::MyDTI cFSMUnit::cParamSetVibUnit::DTI("cFSMUnit::cParamSetVibUnit", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetVibUnit::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetVibUnit;
}

const MtDTI& cFSMUnit::cParamSetEmMontage::getDTI() const {
    return cFSMUnit::cParamSetEmMontage::DTI;
}

inline void* cFSMUnit::cParamSetEmMontage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEmMontage::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEmMontage::DTI.getID());
}

inline void cFSMUnit::cParamSetEmMontage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEmMontage::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetEmMontage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMontage", &mMontage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableMotSeq", &mDisableMotSeq, 0u, 0u);
}

MtUI* cFSMUnit::cParamSetEmMontage::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMUnit::cParamSetEmMontage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEmMontage::MyDTI cFSMUnit::cParamSetEmMontage::DTI("cFSMUnit::cParamSetEmMontage", &::cAICopiableParameter::DTI, 24ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEmMontage::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEmMontage;
}

const MtDTI& cFSMUnit::cParamSetHeadCtrl::getDTI() const {
    return cFSMUnit::cParamSetHeadCtrl::DTI;
}

inline void* cFSMUnit::cParamSetHeadCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHeadCtrl::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetHeadCtrl::DTI.getID());
}

inline void cFSMUnit::cParamSetHeadCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetHeadCtrl::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetHeadCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHeadCtrl", &mHeadCtrl, 0u, 0u);
}

inline cFSMUnit::cParamSetHeadCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetHeadCtrl::MyDTI cFSMUnit::cParamSetHeadCtrl::DTI("cFSMUnit::cParamSetHeadCtrl", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetHeadCtrl::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetHeadCtrl;
}

const MtDTI& cFSMUnit::cParamSetEyeClose::getDTI() const {
    return cFSMUnit::cParamSetEyeClose::DTI;
}

inline void* cFSMUnit::cParamSetEyeClose::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEyeClose::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEyeClose::DTI.getID());
}

inline void cFSMUnit::cParamSetEyeClose::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEyeClose::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetEyeClose::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEyeClose", &mEyeClose, 0u, 0u);
}

inline cFSMUnit::cParamSetEyeClose::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEyeClose::MyDTI cFSMUnit::cParamSetEyeClose::DTI("cFSMUnit::cParamSetEyeClose", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEyeClose::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEyeClose;
}

const MtDTI& cFSMUnit::cParamSetDispMiniMap::getDTI() const {
    return cFSMUnit::cParamSetDispMiniMap::DTI;
}

inline void* cFSMUnit::cParamSetDispMiniMap::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDispMiniMap::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetDispMiniMap::DTI.getID());
}

inline void cFSMUnit::cParamSetDispMiniMap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetDispMiniMap::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetDispMiniMap::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsDispMiniMap", &mIsDispMiniMap, 0u, 0u);
}

inline cFSMUnit::cParamSetDispMiniMap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetDispMiniMap::MyDTI cFSMUnit::cParamSetDispMiniMap::DTI("cFSMUnit::cParamSetDispMiniMap", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetDispMiniMap::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetDispMiniMap;
}

const MtDTI& cFSMUnit::cParamSetIK::getDTI() const {
    return cFSMUnit::cParamSetIK::DTI;
}

inline void* cFSMUnit::cParamSetIK::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetIK::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetIK::DTI.getID());
}

inline void cFSMUnit::cParamSetIK::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetIK::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetIK::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mActive", &mActive, 0u, 0u);
}

inline cFSMUnit::cParamSetIK::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetIK::MyDTI cFSMUnit::cParamSetIK::DTI("cFSMUnit::cParamSetIK", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetIK::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetIK;
}

const MtDTI& cFSMUnit::cParamSetEnemyHP::getDTI() const {
    return cFSMUnit::cParamSetEnemyHP::DTI;
}

inline void* cFSMUnit::cParamSetEnemyHP::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEnemyHP::DTI)->memAlloc(sz, align, cFSMUnit::cParamSetEnemyHP::DTI.getID());
}

inline void cFSMUnit::cParamSetEnemyHP::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMUnit::cParamSetEnemyHP::DTI)->memFree(p_addr);
}

void cFSMUnit::cParamSetEnemyHP::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mHPParcentage", &mHPParcentage, 0u, 0u);
}

inline cFSMUnit::cParamSetEnemyHP::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMUnit::cParamSetEnemyHP::MyDTI cFSMUnit::cParamSetEnemyHP::DTI("cFSMUnit::cParamSetEnemyHP", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

MtObject* cFSMUnit::cParamSetEnemyHP::MyDTI::newInstance() const {
    return new (16u) cFSMUnit::cParamSetEnemyHP;
}

