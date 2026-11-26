// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpJob04.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "cEvaluation.h"
#include "cHitNode.h"
#include "cHumanActId.h"
#include "cNetGameServer.h"
#include "cStaminaCtrl.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpComponent.h"
#include "cpInput.h"
#include "cpJobBase.h"
#include "cpKeyCommand.h"
#include "cpShlShotCtrl.h"
#include "cpStateManager.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "nKeyCommand.h"
#include "rCollNode.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sContextManager.h"
#include "sEnemyManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sSetManager.h"
#include "sShlManager.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uCharacter.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nKeyCommand::stKeyCommand Job04BaseActCommand[36] = {
    {4294967295, 4294967295, 31, 1, 0, 0, 0, 5, 6, 4, 78, 0, 255, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 80, 0, 1, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 81, 0, 2, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 82, 0, 7, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 83, 0, 8, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 84, 0, 9, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 87, 0, 13, false},
    {4294967295, 4294967295, 3, 1, 0, 0, 0, 65535, 65535, 4, 88, 0, 14, false},
    {0, 8192, 10, 1, 0, 1, 0, 3, 4, 0, 0, 0, 255, false},
    {8192, 4294967295, 2, 1, 0, 1, 0, 1, 2, 0, 0, 0, 255, false},
    {8193, 8192, 2, 5, 0, 1, 0, 9, 65535, 0, 75, 0, 255, true},
    {8194, 8192, 2, 5, 0, 1, 0, 9, 65535, 0, 76, 0, 255, true},
    {8195, 8192, 2, 5, 0, 1, 0, 9, 65535, 0, 77, 0, 255, true},
    {8196, 4294967295, 2, 1, 0, 2, 0, 1, 2, 0, 0, 0, 255, false},
    {8201, 4294967295, 1, 1, 0, 1, 0, 1, 2, 0, 79, 0, 255, false},
    {8198, 4294967295, 1, 1, 0, 1, 0, 1, 2, 0, 8, 0, 255, false},
    {8202, 12, 1, 1, 0, 2, 0, 1, 2, 0, 79, 0, 255, false},
    {8202, 11, 1, 1, 0, 2, 0, 1, 2, 0, 79, 0, 255, false},
    {8202, 25, 1, 1, 0, 2, 0, 1, 2, 0, 79, 0, 255, false},
    {8198, 4294967295, 1, 1, 0, 2, 0, 1, 2, 0, 8, 0, 255, false},
    {8205, 11, 10, 1, 0, 2, 0, 3, 4, 0, 89, 0, 255, false},
    {8206, 4294967295, 10, 1, 0, 2, 0, 3, 4, 0, 89, 0, 255, false},
    {25, 8205, 10, 4, 0, 2, 0, 3, 65535, 0, 0, 0, 255, true},
    {25, 8206, 10, 4, 0, 2, 0, 3, 65535, 0, 0, 0, 255, true},
    {8211, 4294967295, 27, 1, 0, 1, 0, 1, 2, 0, 86, 0, 255, false},
    {8208, 4294967295, 27, 1, 0, 1, 0, 1, 2, 0, 8, 0, 255, false},
    {8212, 12, 27, 1, 0, 2, 0, 1, 2, 0, 86, 0, 255, false},
    {8212, 11, 27, 1, 0, 2, 0, 1, 2, 0, 86, 0, 255, false},
    {8212, 25, 27, 1, 0, 2, 0, 1, 2, 0, 86, 0, 255, false},
    {4294967295, 4294967295, 27, 1, 0, 2, 0, 65535, 65535, 4, 86, 0, 255, false},
    {4294967295, 4294967295, 27, 1, 0, 0, 0, 65535, 65535, 4, 86, 0, 255, false},
    {8208, 4294967295, 27, 1, 0, 2, 0, 1, 2, 0, 8, 0, 255, false},
    {8213, 4294967295, 28, 1, 0, 1, 0, 1, 2, 0, 90, 0, 255, false},
    {8203, 4294967295, 1, 1, 0, 32, 0, 1, 2, 1, 8, 0, 255, false},
    {8204, 4294967295, 27, 1, 0, 32, 0, 1, 2, 1, 8, 0, 255, false},
    {4294967295, 4294967295, 0, 0, 0, 0, 0, 65535, 65535, 0, 0, 0, 255, false},
};

nKeyCommand::stKeyCommand Job04CustomSkillCommand[68] = {
    {8216, 4294967295, 31, 1, 0, 1, 0, 5, 6, 0, 78, 0, 255, false},
    {4294967295, 4294967295, 31, 1, 0, 0, 0, 65535, 65535, 4, 78, 0, 255, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 80, 0, 1, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 81, 0, 2, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 82, 0, 7, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 83, 0, 8, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 84, 0, 9, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 87, 0, 13, false},
    {4294967295, 4294967295, 3, 1, 0, 32, 0, 65535, 65535, 4, 88, 0, 14, false},
    {4096, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 1, false},
    {4099, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 80, 0, 1, false},
    {4100, 12, 3, 1, 0, 2, 0, 5, 6, 0, 80, 0, 1, false},
    {4100, 25, 3, 1, 0, 2, 0, 5, 6, 0, 80, 0, 1, false},
    {4100, 11, 3, 1, 0, 2, 0, 5, 6, 0, 80, 0, 1, false},
    {4097, 4096, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 1, true},
    {4101, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 2, false},
    {4104, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 81, 0, 2, false},
    {4105, 25, 3, 1, 0, 2, 0, 5, 6, 0, 81, 0, 2, false},
    {4105, 12, 3, 1, 0, 2, 0, 5, 6, 0, 81, 0, 2, false},
    {4105, 11, 3, 1, 0, 2, 0, 5, 6, 0, 81, 0, 2, false},
    {4102, 4101, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 2, true},
    {4106, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 3, false},
    {4107, 4106, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 3, true},
    {4109, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 4, false},
    {4110, 4109, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 4, true},
    {4112, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 5, false},
    {4113, 4112, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 5, true},
    {4115, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 6, false},
    {4116, 4115, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 6, true},
    {4118, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 7, false},
    {4119, 4118, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 7, true},
    {4121, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 82, 0, 7, false},
    {4122, 12, 3, 1, 0, 2, 0, 5, 6, 0, 82, 0, 7, false},
    {4122, 25, 3, 1, 0, 2, 0, 5, 6, 0, 82, 0, 7, false},
    {4122, 11, 3, 1, 0, 2, 0, 5, 6, 0, 82, 0, 7, false},
    {4123, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 8, false},
    {4124, 4123, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 8, true},
    {4126, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 83, 0, 8, false},
    {4127, 12, 3, 1, 0, 2, 0, 5, 6, 0, 83, 0, 8, false},
    {4127, 25, 3, 1, 0, 2, 0, 5, 6, 0, 83, 0, 8, false},
    {4127, 11, 3, 1, 0, 2, 0, 5, 6, 0, 83, 0, 8, false},
    {4128, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 9, false},
    {4131, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 84, 0, 9, false},
    {4132, 12, 3, 1, 0, 2, 0, 5, 6, 0, 84, 0, 9, false},
    {4132, 11, 3, 1, 0, 2, 0, 5, 6, 0, 84, 0, 9, false},
    {4132, 25, 3, 1, 0, 2, 0, 5, 6, 0, 84, 0, 9, false},
    {4129, 4128, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 9, true},
    {4133, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 10, false},
    {4134, 4133, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 10, true},
    {4136, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 11, false},
    {4137, 4136, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 11, true},
    {4139, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 0, 0, 12, false},
    {4140, 4139, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 12, true},
    {4142, 4141, 10, 1, 0, 1, 0, 9, 65535, 0, 0, 0, 12, false},
    {4142, 4141, 3, 1, 0, 1, 0, 9, 65535, 0, 0, 0, 12, false},
    {4143, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 13, false},
    {4146, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 87, 0, 13, false},
    {4147, 12, 3, 1, 0, 2, 0, 5, 6, 0, 87, 0, 13, false},
    {4147, 11, 3, 1, 0, 2, 0, 5, 6, 0, 87, 0, 13, false},
    {4147, 25, 3, 1, 0, 2, 0, 5, 6, 0, 87, 0, 13, false},
    {4144, 4143, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 13, true},
    {4148, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 8, 0, 14, false},
    {4149, 4148, 3, 6, 0, 1, 0, 65535, 65535, 0, 30, 0, 14, true},
    {4151, 4294967295, 3, 1, 0, 1, 0, 5, 6, 0, 88, 0, 14, false},
    {4152, 12, 3, 1, 0, 2, 0, 5, 6, 0, 88, 0, 14, false},
    {4152, 25, 3, 1, 0, 2, 0, 5, 6, 0, 88, 0, 14, false},
    {4152, 11, 3, 1, 0, 2, 0, 5, 6, 0, 88, 0, 14, false},
    {4294967295, 4294967295, 0, 0, 0, 0, 0, 65535, 65535, 0, 0, 0, 255, false},
};

nKeyCommand::stKeyCommandForFunction Job04FuncCommandTbl[13] = {
    {12, 31, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(11), 255},
    {2, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(2), 1},
    {3, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(3), 2},
    {4, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(4), 7},
    {5, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(5), 8},
    {6, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(6), 9},
    {14, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(12), 13},
    {15, 3, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(13), 14},
    {7, 27, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(7), 255},
    {7, 27, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(8), 255},
    {1, 1, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(1), 255},
    {0, 1, 1, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(0), 255},
    {-1, 0, 0, static_cast<nKeyCommand::KEY_CMD_FUNC_SP>(4294967295), 255},
};

const MtDTI& cpJob04::getDTI() const {
    return cpJob04::DTI;
}

inline MtAllocator* cpJob04::getAllocator() {
    return MtMemoryAllocator::getAllocator(cpJob04::DTI);
}

void* cpJob04::operator new(size_t sz, u32 align) {
    return cpJob04::getAllocator()->memAlloc(sz, align, cpJob04::DTI.getID());
}

inline void cpJob04::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpJob04::DTI)->memFree(p_addr);
}

cpJob04::cpJob04() {
    DDON_STUB("cpJob04::cpJob04")
    /* stub */
}

cpJob04::~cpJob04() {
}

void cpJob04::setup() {
    this->cpJobBase::setup();
}

__attribute__((weak)) void cpJob04::setupJobData() {
    DDON_STUB("cpJob04::setupJobData")
    /* stub */
}

void cpJob04::before() {
    this->cpJobBase::before();
    if (!mClearFloating) {
        return;
    }
    mCanFloating = true;
    mAirChantCount = 0;
    mClearFloating = false;
}

__attribute__((weak)) void cpJob04::update() {
    DDON_STUB("cpJob04::update")
    /* stub */
}

__attribute__((weak)) void cpJob04::circleProc() {
    DDON_STUB("cpJob04::circleProc")
    /* stub */
}

void cpJob04::after() {
    this->cpJobBase::after();
}

void cpJob04::notifyDeleteShell(s32 work) {
    if (work <= 8199) {
        if (work <= 4102) {
            if (work == 4098) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
            }
        } else {
            if (work <= 4119) {
                if (work == 4103) {
                    mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
                }
            } else {
                if (work <= 4144) {
                    if (work != 4120) {
                        if (work != 4125) {
                            if (work == 4130) {
                                mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
                                mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
                                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
                            }
                        } else {
                            mpHuman->mLimitActCtrl.setLimitedActInfo(4123, false);
                            mCircleFlgs = mCircleFlgs & 0xFFFFFFF7u;
                        }
                    } else {
                        isCheckGuard = true;
                    }
                } else {
                    if (work == 4145) {
                        mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
                    } else {
                        if (work == 4150) {
                            mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
                            mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
                        }
                    }
                }
            }
        }
    } else {
        if (work <= 8209) {
            if (work != 8200) {
                if (work == 8203) {
                    mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
                    mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
                    if (work != 4120) {
                        if (work == 4125) {
                            mpHuman->mLimitActCtrl.setLimitedActInfo(4123, false);
                            mCircleFlgs = mCircleFlgs & 0xFFFFFFF7u;
                        } else {
                            if (work == 4150) {
                                mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
                                mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
                            }
                        }
                    } else {
                        isCheckGuard = true;
                    }
                } else {
                    if (work == 8204) {
                        mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
                        mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
                        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
                        if (work != 4120) {
                            if (work == 4125) {
                                mpHuman->mLimitActCtrl.setLimitedActInfo(4123, false);
                                mCircleFlgs = mCircleFlgs & 0xFFFFFFF7u;
                            } else {
                                if (work == 4150) {
                                    mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
                                    mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
                                }
                            }
                        } else {
                            isCheckGuard = true;
                        }
                    }
                }
            } else {
                mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
                mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
                if (work != 4120) {
                    if (work == 4125) {
                        mpHuman->mLimitActCtrl.setLimitedActInfo(4123, false);
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFF7u;
                    } else {
                        if (work == 4150) {
                            mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
                            mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
                        }
                    }
                } else {
                    isCheckGuard = true;
                }
            }
        } else {
            if (work == 8210) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
                mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
                if (work != 4120) {
                    if (work == 4125) {
                        mpHuman->mLimitActCtrl.setLimitedActInfo(4123, false);
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFF7u;
                    } else {
                        if (work == 4150) {
                            mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
                            mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
                        }
                    }
                } else {
                    isCheckGuard = true;
                }
            }
        }
    }
}

void cpJob04::callbackHitLand() {
    mClearFloating = true;
}

__attribute__((weak)) void cpJob04::callbackDamage(cHitInfo* pHitLocalInfo) {
    DDON_STUB("cpJob04::callbackDamage")
    /* stub */
}

__attribute__((weak)) void cpJob04::callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag) {
    DDON_STUB("cpJob04::callbackReqOcdAction")
    /* stub */
}

void cpJob04::callbackDie() {
    clearAllCircle();
}

void cpJob04::callbackOcdSeal() {
    clearCustomCircle();
}

__attribute__((weak)) void cpJob04::excuteSoulBomb() {
    DDON_STUB("cpJob04::excuteSoulBomb")
    /* stub */
}

__attribute__((weak)) void cpJob04::circleHateProc() {
    DDON_STUB("cpJob04::circleHateProc")
    /* stub */
}

bool cpJob04::checkFeildBitFlg(u32 bit) {
    return (bit & mCircleFlgs) != 0;
}

void cpJob04::setFeildBitFlg(u32 bit, bool flg) {
    mCircleFlgs = (bit | mCircleFlgs) ^ (!flg ? bit : 0u);
}

bool cpJob04::checkShiftBitFlg(u32 bit) {
    return (bit & mShiftFlgs) != 0;
}

__attribute__((weak)) void cpJob04::BeginCircleShift() {
    DDON_STUB("cpJob04::BeginCircleShift")
    /* stub */
}

__attribute__((weak)) void cpJob04::FinishCircleShift() {
    DDON_STUB("cpJob04::FinishCircleShift")
    /* stub */
}

__attribute__((weak)) void cpJob04::checkRangeCircleShiftAll() {
    DDON_STUB("cpJob04::checkRangeCircleShiftAll")
    /* stub */
}

__attribute__((weak)) s32 cpJob04::checkShortRangeProc(MtTypedArray<uShlBase> shl_array) {
    DDON_STUB("cpJob04::checkShortRangeProc")
    return {};
}

__attribute__((weak)) void cpJob04::setCirclePartyAll(u32 group, u32 index, u32 type) {
    DDON_STUB("cpJob04::setCirclePartyAll")
    /* stub */
}

__attribute__((weak)) void cpJob04::reqCircleBitShl(u32 group, u32 index, u32 id) {
    DDON_STUB("cpJob04::reqCircleBitShl")
    /* stub */
}

__attribute__((weak)) bool cpJob04::checkShiftConditions(uBaseModel* pUit, u32 shlId) {
    DDON_STUB("cpJob04::checkShiftConditions")
    return {};
}

void cpJob04::limitCircleAllAct(u32 act) {
    if (act == 8201) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(8201, true);
    if (act == 8211) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(8211, true);
    if (act == 4099) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4099, true);
    if (act == 4104) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4104, true);
    if (act == 4131) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4131, true);
    if (act == 4146) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4146, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4121, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4126, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4151, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8216, true);
}

void cpJob04::unLimitCircleAllAct() {
    mpHuman->mLimitActCtrl.setLimitedActInfo(8201, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8211, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4099, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4104, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4131, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4146, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4121, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4126, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4151, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8216, false);
}

void cpJob04::limitCircleAllActAir(u32 act) {
    if ((mCircleFlgs & 4u) != 0) {
        if (act == 8202) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
        }
        mpHuman->mLimitActCtrl.setLimitedActInfo(8202, true);
    }
    if ((mCircleFlgs & 32u) != 0) {
        if (act == 8212) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
        }
        mpHuman->mLimitActCtrl.setLimitedActInfo(8212, true);
    }
    if ((mCircleFlgs & 1u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4100, true);
    }
    if ((mCircleFlgs & 2u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4105, true);
    }
    if ((mCircleFlgs & 16u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4132, true);
    }
    if ((mCircleFlgs & 64u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4147, true);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4122, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4127, true);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4152, true);
}

void cpJob04::unLimitCircleAllActAir() {
    if ((mCircleFlgs & 4u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8202, false);
    }
    if ((mCircleFlgs & 32u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8212, false);
    }
    if ((mCircleFlgs & 1u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4100, false);
    }
    if ((mCircleFlgs & 2u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4105, false);
    }
    if ((mCircleFlgs & 16u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4132, false);
    }
    if ((mCircleFlgs & 64u) != 0) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4147, false);
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(4122, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4127, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(4152, false);
}

void cpJob04::setHealSpotTimer(u32 skillLev) {
    switch (skillLev - 1u) {
        case 0:
        {
            f32 t0 = mpHuman->getJobAdjustParam(15u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 1:
        {
            f32 t0 = mpHuman->getJobAdjustParam(16u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 2:
        {
            f32 t0 = mpHuman->getJobAdjustParam(17u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 3:
        {
            f32 t0 = mpHuman->getJobAdjustParam(18u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 4:
        {
            f32 t0 = mpHuman->getJobAdjustParam(19u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 5:
        {
            f32 t0 = mpHuman->getJobAdjustParam(20u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 6:
        {
            f32 t0 = mpHuman->getJobAdjustParam(21u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 7:
        {
            f32 t0 = mpHuman->getJobAdjustParam(22u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 8:
        {
            f32 t0 = mpHuman->getJobAdjustParam(23u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        case 9:
        {
            f32 t0 = mpHuman->getJobAdjustParam(24u);
            if (t0 > 0.0f) {
                mHealSpotTimer = t0;
            }
            break;
        }
        default:
        {
            mHealSpotTimer = 1.0f;
            break;
        }
    }
}

void cpJob04::killHealSpot() {
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 2u;
    mIsHealSpot = false;
}

void cpJob04::setCureSpotTimer(u32 skillLev) {
    switch (skillLev - 1u) {
        case 0:
        {
            f32 t0 = mpHuman->getJobAdjustParam(25u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 1:
        {
            f32 t0 = mpHuman->getJobAdjustParam(26u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 2:
        {
            f32 t0 = mpHuman->getJobAdjustParam(27u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 3:
        {
            f32 t0 = mpHuman->getJobAdjustParam(28u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 4:
        {
            f32 t0 = mpHuman->getJobAdjustParam(29u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 5:
        {
            f32 t0 = mpHuman->getJobAdjustParam(30u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 6:
        {
            f32 t0 = mpHuman->getJobAdjustParam(31u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 7:
        {
            f32 t0 = mpHuman->getJobAdjustParam(32u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 8:
        {
            f32 t0 = mpHuman->getJobAdjustParam(33u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        case 9:
        {
            f32 t0 = mpHuman->getJobAdjustParam(34u);
            if (t0 > 0.0f) {
                mCureSpotTimer = t0;
            }
            break;
        }
        default:
        {
            mCureSpotTimer = 1.0f;
            break;
        }
    }
}

void cpJob04::killCureSpot() {
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 4u;
    mIsCureSpot = false;
}

void cpJob04::setEnergySpotTimer(u32 skillLev) {
    switch (skillLev - 1u) {
        case 0:
        {
            f32 t0 = mpHuman->getJobAdjustParam(36u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 1:
        {
            f32 t0 = mpHuman->getJobAdjustParam(37u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 2:
        {
            f32 t0 = mpHuman->getJobAdjustParam(38u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 3:
        {
            f32 t0 = mpHuman->getJobAdjustParam(39u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 4:
        {
            f32 t0 = mpHuman->getJobAdjustParam(40u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 5:
        {
            f32 t0 = mpHuman->getJobAdjustParam(41u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 6:
        {
            f32 t0 = mpHuman->getJobAdjustParam(42u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 7:
        {
            f32 t0 = mpHuman->getJobAdjustParam(43u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 8:
        {
            f32 t0 = mpHuman->getJobAdjustParam(44u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        case 9:
        {
            f32 t0 = mpHuman->getJobAdjustParam(45u);
            if (t0 > 0.0f) {
                mEnergySpotTimer = t0;
            }
            break;
        }
        default:
        {
            mEnergySpotTimer = 1.0f;
            break;
        }
    }
}

void cpJob04::KillEnergySpot() {
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16384u;
    mIsEnergySpot = false;
}

__attribute__((weak)) void cpJob04::createNormalCircle(const cpJob04::CIRCLE_PARAM& data) {
    DDON_STUB("cpJob04::createNormalCircle")
    /* stub */
}

__attribute__((weak)) void cpJob04::createCustomCircle(const cpJob04::CIRCLE_PARAM& data) {
    DDON_STUB("cpJob04::createCustomCircle")
    /* stub */
}

void cpJob04::deleteAtherNormalCircle(const cpJob04::CIRCLE_PARAM& data) {
    if (data.SkillID != 1) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
        if (data.SkillID != 2) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
            mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
        }
    } else {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
    }
}

void cpJob04::deleteAtherCustomCircle(const cpJob04::CIRCLE_PARAM& data) {
    if (data.SkillID != 1) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
        if (data.SkillID != 2) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
            if (data.SkillID != 9) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
                if (data.SkillID != 13) {
                    mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
                }
            } else {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            }
        } else {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
            if (data.SkillID != 13) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            }
        }
    } else {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
        if (data.SkillID != 9) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
            if (data.SkillID != 13) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            }
        } else {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
        }
    }
}

void cpJob04::circleEnd(u32 act) {
    if (static_cast<int>(act) <= 8210) {
        if (static_cast<int>(act) <= 8200) {
            if (static_cast<int>(act) <= 4145) {
                if (act != 4099) {
                    if (act == 4104) {
                        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
                    } else {
                        if (act == 4131) {
                            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
                            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
                        }
                    }
                } else {
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
                }
            } else {
                if (act == 4146) {
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                }
            }
        } else {
            if (act == 8201) {
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
                mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
            }
        }
    } else {
        if (act == 8211) {
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
            mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
        }
    }
}

void cpJob04::circleEndAir(u32 act) {
    if (static_cast<int>(act) <= 8211) {
        if (static_cast<int>(act) <= 8201) {
            if (static_cast<int>(act) <= 4146) {
                if (act != 4100) {
                    if (act == 4105) {
                        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
                        mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
                    } else {
                        if (act == 4132) {
                            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
                            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
                        }
                    }
                } else {
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
                }
            } else {
                if (act == 4147) {
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                }
            }
        } else {
            if (act == 8202) {
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
                mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
            }
        }
    } else {
        if (act == 8212) {
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
            mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
        }
    }
}

void cpJob04::normalCircleActionProc(u32 act) {
    if (act == 8200) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8198, true);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8203, true);
        mCircleFlgs = mCircleFlgs | 4u;
        mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
    } else {
        mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
        mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
        if (act == 8210) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(8208, true);
            mpHuman->mLimitActCtrl.setLimitedActInfo(8204, true);
            mCircleFlgs = mCircleFlgs | 32u;
        } else {
            mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
            mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
        }
    }
}

void cpJob04::customCircleActionProc(u32 act) {
    if (act == 4098) {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4096, true);
        mCircleFlgs = mCircleFlgs | 1u;
        mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
        if (act == 4130) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4128, true);
            mCircleFlgs = mCircleFlgs | 16u;
            mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
        } else {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
            if (act == 4145) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, true);
                mCircleFlgs = mCircleFlgs | 64u;
            } else {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            }
        }
    } else {
        mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
        if (act == 4103) {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4101, true);
            mCircleFlgs = mCircleFlgs | 2u;
            mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
            if (act == 4145) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, true);
                mCircleFlgs = mCircleFlgs | 64u;
            } else {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            }
        } else {
            mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
            mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
            mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
            if (act == 4130) {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4128, true);
                mCircleFlgs = mCircleFlgs | 16u;
                mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
            } else {
                mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
                mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
                mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
                if (act == 4145) {
                    mpHuman->mLimitActCtrl.setLimitedActInfo(4143, true);
                    mCircleFlgs = mCircleFlgs | 64u;
                } else {
                    mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
                    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
                    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
                }
            }
        }
    }
}

__attribute__((weak)) void cpJob04::climbCircleActionProc(u32 act) {
    DDON_STUB("cpJob04::climbCircleActionProc")
    /* stub */
}

void cpJob04::deleteHealingCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 1u;
}

void cpJob04::deleteAttackCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 16u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
}

void cpJob04::deleteDefenceCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
}

void cpJob04::deleteIronField() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 8192u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
}

void cpJob04::deleteSaintCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 32768u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
}

void cpJob04::deleteSolaceCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x400000u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
}

__attribute__((weak)) void cpJob04::deleteSoulFull() {
    DDON_STUB("cpJob04::deleteSoulFull")
    /* stub */
}

bool cpJob04::isGuardBits() {
    return mGuardBitFlgs != 0;
}

void cpJob04::setGuardBits(u32 isLv2) {
    if (isLv2 != 0) {
        mGuardBitFlgs = mGuardBitFlgs | 31;
    } else {
        mGuardBitFlgs = mGuardBitFlgs | 7;
    }
    mGuardBitProtectTimes = (isLv2 == 0) ? 3 : 5;
    mNowGuardTimes = mGuardBitProtectTimes;
}

__attribute__((weak)) void cpJob04::hitNoticeGuardBit() {
    DDON_STUB("cpJob04::hitNoticeGuardBit")
    /* stub */
}

__attribute__((weak)) u32 cpJob04::getGuardBitNum() const {
    DDON_STUB("cpJob04::getGuardBitNum")
    return {};
}

__attribute__((weak)) bool cpJob04::cheackIsLiveGuardBit(u32 id) {
    DDON_STUB("cpJob04::cheackIsLiveGuardBit")
    return {};
}

void cpJob04::deleteGuardBit() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 7936u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4118, false);
    isCheckGuard = false;
    mIsReadyKillBit = true;
    mGuardBitFlgs = 0;
}

void cpJob04::deleteBlastOption() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x1000000u;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
}

__attribute__((weak)) const uDDOModel* cpJob04::getOptionShl() {
    DDON_STUB("cpJob04::getOptionShl")
    return nullptr;
}

__attribute__((weak)) const uDDOModel* cpJob04::getOptionBigShl() {
    DDON_STUB("cpJob04::getOptionBigShl")
    return nullptr;
}

__attribute__((weak)) const uDDOModel* cpJob04::getOptionBigShlSecond() {
    DDON_STUB("cpJob04::getOptionBigShlSecond")
    return nullptr;
}

bool cpJob04::isCanFloating() {
    uHuman* t0 = mpHuman;
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376)) != 0) {
        nHuman::GROW_NORMAL_SKILL_ENUM t1 = cHumanActId::getNormalSkillId(8205u, static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376)) + 40)));
        unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376);
        if (t2 != 0) {
            if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)) + 255) > 9) {
                return false;
            } else {
                u32 t3 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)));
                u32 t4 = nHuman::getNormalSkillIdArrayIndex(t1);
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t2 + (static_cast<unsigned long>(t3) * 40)) + (static_cast<unsigned long>(t4) * 4)) + 3176)) != 0) {
                    return mCanFloating;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        nHuman::GROW_NORMAL_SKILL_ENUM t1 = cHumanActId::getNormalSkillId(8205u, nHuman::JOB_ID_NONE);
        unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376);
        if (t2 != 0) {
            if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)) + 255) > 9) {
                return false;
            } else {
                u32 t3 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)));
                u32 t4 = nHuman::getNormalSkillIdArrayIndex(t1);
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t2 + (static_cast<unsigned long>(t3) * 40)) + (static_cast<unsigned long>(t4) * 4)) + 3176)) != 0) {
                    return mCanFloating;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
}

void cpJob04::killAllCircle() {
    if (!mpHuman->checkEnableMenuUIAct()) {
        return;
    }
    mpHuman->mLimitActCtrl.setLimitedActInfo(8198, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8203, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFBu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x10001u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFFBu;
    mpHuman->mLimitActCtrl.setLimitedActInfo(8208, false);
    mpHuman->mLimitActCtrl.setLimitedActInfo(8204, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFDFu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x108000u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFDFu;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4096, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFEu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x20010u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFFEu;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4101, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFFDu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x40020u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFFDu;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4128, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFEFu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x82000u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFEFu;
    mpHuman->mLimitActCtrl.setLimitedActInfo(4143, false);
    mCircleFlgs = mCircleFlgs & 0xFFFFFFBFu;
    mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0xC00000u;
    mShiftFlgs = mShiftFlgs & 0xFFFFFFBFu;
    deleteSoulFull();
    if (mpHuman->checkEnableMenuUIAct()) {
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 7936u;
        mpHuman->mLimitActCtrl.setLimitedActInfo(4118, false);
        isCheckGuard = false;
        mIsReadyKillBit = true;
        mGuardBitFlgs = 0;
    }
    if (mpHuman->checkEnableMenuUIAct()) {
        mpHuman->mShlDeleteBit = mpHuman->mShlDeleteBit | 0x1000000u;
        mpHuman->mLimitActCtrl.setLimitedActInfo(4148, false);
        mCircleFlgs = mCircleFlgs & 0xFFFFFF7Fu;
    }
    mCircleFlgs = 0;
    mShiftFlgs = 0;
}

__attribute__((weak)) void cpJob04::clearAllCircle() {
    DDON_STUB("cpJob04::clearAllCircle")
    /* stub */
}

__attribute__((weak)) void cpJob04::clearCustomCircle() {
    DDON_STUB("cpJob04::clearCustomCircle")
    /* stub */
}

void cpJob04::shlHitCountTutorialFlg(s32 id) {
    uHuman* t0 = mpHuman;
    if (!t0->isMaster()) {
        return;
    }
    if ((t0->uDDOModel::mUnitId & 8u) == 0) {
        return;
    }
    if (id != 36) {
        if (id == 17) {
            if ((mpHuman->mObjStatus & 32ul) == 0) {
                nDDOUtility::requestOnTutorialFlg(18);
            }
        } else {
            if (id == 14) {
                s32 t1 = tutorialSkillCount01;
                tutorialSkillCount01 = t1 + 1;
                if (t1 > 1) {
                    nDDOUtility::requestOnTutorialFlg(16);
                }
            }
        }
    } else {
        nDDOUtility::requestOnTutorialFlg(70);
    }
}

__attribute__((weak)) bool cpJob04::canEndureInClimb() {
    DDON_STUB("cpJob04::canEndureInClimb")
    return {};
}

bool cpJob04::isCanCircleShiftAct() {
    mpHuman->getStateActionPtr()->getStateNo();
    return (mpHuman->uDDOModel::mUnitId & 1024u) == 0;
}

__attribute__((weak)) bool cpJob04::isActiveShiftNormalCircle() {
    DDON_STUB("cpJob04::isActiveShiftNormalCircle")
    return {};
}

bool cpJob04::isActiveShiftCustomCircle() {
    u16 work = cContextInterface::getCustomWork(mpHuman->mContextInterface.mpContextInstance, mpHuman->mContextInterface.mpContextCharacter);
    if (((static_cast<unsigned long>(work) >> 8) & 112ul) == 0) {
        return static_cast<bool>(static_cast<unsigned long>(work) >> 15);
    } else {
        return true;
    }
}

inline cpJob04::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpJob04::MyDTI cpJob04::DTI("cpJob04", &::cpJobBase::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* cpJob04::MyDTI::newInstance() const {
    DDON_STUB("cpJob04::MyDTI::newInstance")
    return nullptr;
}

