// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShakeCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cHitGeom.h"
#include "cHitInfoAfter.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpObjCollision.h"
#include "cpOcdCtrl.h"
#include "rShakeCtrl.h"
#include "uCnsShakeCtrl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpShakeCtrl::getDTI() const {
    return cpShakeCtrl::DTI;
}

void* cpShakeCtrl::operator new(size_t sz, u32 align) {
    return cpShakeCtrl::getAllocator()->memAlloc(sz, align, cpShakeCtrl::DTI.getID());
}

cpShakeCtrl::cpShakeCtrl() {
    mpIKCtrl = nullptr;
    mpBank[3] = nullptr;
    mpBank[2] = nullptr;
    mpBank[1] = nullptr;
    mpBank[0] = nullptr;
    mpResource = nullptr;
    mCurrentResNo = -1;
    mpModel = nullptr;
    mIgnorOST = 0x780000;
    mIgnorBadOCD = 4;
    mDir.pad_ = 0.0f;
    mDir.x = 0.57735026f;
    mDir.y = 0.57735026f;
    mDir.z = 0.57735026f;
}

__attribute__((noinline)) cpShakeCtrl::~cpShakeCtrl() {
    if (mCnsShakeCtrlArray.mLength != 0) {
        u32 v0_0 = mCnsShakeCtrlArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCnsShakeCtrlArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<uCnsShakeCtrl*>(mCnsShakeCtrlArray.mpArray[i0_3])->remove();
                v1_0 = mCnsShakeCtrlArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 != 0) {
            u32 v3_0 = v1_0;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mCnsShakeCtrlArray.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    delete mCnsShakeCtrlArray.mpArray[i3_3];
                    v4_0 = mCnsShakeCtrlArray.mLength;
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
    if (mCnsShakeCtrlArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCnsShakeCtrlArray.mpArray));
    }
    mCnsShakeCtrlArray.mpArray = nullptr;
    mCnsShakeCtrlArray.mBufsiz = 0;
    mCnsShakeCtrlArray.mLength = 0;
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
    initShakeCtrl();
    if (mpBank[0] != nullptr) {
        mpBank[0]->cResource::release();
        mpBank[0] = nullptr;
    }
    if (mpBank[1] != nullptr) {
        mpBank[1]->cResource::release();
        mpBank[1] = nullptr;
    }
    if (mpBank[2] != nullptr) {
        mpBank[2]->cResource::release();
        mpBank[2] = nullptr;
    }
    if (mpBank[3] != nullptr) {
        mpBank[3]->cResource::release();
        mpBank[3] = nullptr;
    }
}

void cpShakeCtrl::setup() {
    this->cpComponent::setup();
}

__attribute__((weak)) void cpShakeCtrl::move() {
}

__attribute__((weak)) void cpShakeCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
}

void cpShakeCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpShakeCtrl::setupComponentPtr() {
}

__attribute__((weak)) void cpShakeCtrl::setResource(rShakeCtrl* pRes, u32 bank) {
    DDON_STUB("cpShakeCtrl::setResource")
    /* stub */
}

__attribute__((weak)) void cpShakeCtrl::initShakeCtrl() {
    DDON_STUB("cpShakeCtrl::initShakeCtrl")
    /* stub */
}

void cpShakeCtrl::updateShakeCtrl() {
    if (mpModel != nullptr) {
        u32 v2_0;
        if (mCnsShakeCtrlArray.mLength == 0) {
            v2_0 = 0;
        } else {
            u32 v0_0 = mCnsShakeCtrlArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mCnsShakeCtrlArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    static_cast<uCnsShakeCtrl*>(mCnsShakeCtrlArray.mpArray[i0_3])->move();
                    v1_0 = mCnsShakeCtrlArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    v2_0 = v1_0;
                    break;
                }
            }
        }
        if (mpResource != nullptr) {
            if (mpResource->getDataNum() != 0) {
                for (unsigned int i3_3 = 0;;) {
                    cShakeCtrl* t0 = mpResource->getData(i3_3);
                    if (i3_3 < mCnsShakeCtrlArray.mLength) {
                        if (mCnsShakeCtrlArray.mpArray[i3_3] != nullptr) {
                            if (t0 != nullptr) {
                                static_cast<uCnsShakeCtrl*>(mCnsShakeCtrlArray.mpArray[i3_3])->mpShakeCtrlData = t0;
                            }
                        }
                    }
                    if ((i3_3 + 1u) < mpResource->getDataNum()) {
                        i3_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        } else {
            if (v2_0 != 0) {
                MtObject* * v6_1 = mCnsShakeCtrlArray.mpArray;
                for (unsigned int i6_2 = 0;;) {
                    if (v6_1[i6_2] != nullptr) {
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v6_1[i6_2]) + 216) = 0;
                    }
                    if ((i6_2 + 1u) < v2_0) {
                        i6_2 = i6_2 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

void cpShakeCtrl::shake(u32 JntNo, const MtVector3& shakeDir, s32 ResourceNo) {
    if (mpModel == nullptr) {
        return;
    }
    if ((mpModel->getObjStatus() & mIgnorOST) != 0) {
        return;
    }
    if (mpModel->getOcdCtrlPtr() != nullptr) {
        if ((mIgnorBadOCD & mpModel->getOcdCtrlPtr()->mOcdActiveBit[1]) == 0) {
            if ((mpModel->mObjStatus & 32ul) == 0) {
                if (mCurrentResNo != ResourceNo) {
                    rShakeCtrl* t0 = mpBank[ResourceNo];
                    if (mpResource != nullptr) {
                        mpResource->release();
                        mpResource = nullptr;
                    }
                    if (t0 != nullptr) {
                        mpResource = t0;
                        t0->addRef();
                        initShakeCtrl();
                        mCurrentResNo = ResourceNo;
                        mDir.x = shakeDir.x;
                        mDir.y = shakeDir.y;
                        mDir.z = shakeDir.z;
                        mDir.pad_ = 0.0f;
                        uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                        if (pShakeCtrl != nullptr) {
                            pShakeCtrl->shake(mDir);
                        }
                    } else {
                        initShakeCtrl();
                        mCurrentResNo = ResourceNo;
                        mDir.x = shakeDir.x;
                        mDir.y = shakeDir.y;
                        mDir.z = shakeDir.z;
                        mDir.pad_ = 0.0f;
                        uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                        if (pShakeCtrl != nullptr) {
                            pShakeCtrl->shake(mDir);
                        }
                    }
                } else {
                    mDir.x = shakeDir.x;
                    mDir.y = shakeDir.y;
                    mDir.z = shakeDir.z;
                    mDir.pad_ = 0.0f;
                    uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                    if (pShakeCtrl != nullptr) {
                        pShakeCtrl->shake(mDir);
                    }
                }
            }
        }
    } else {
        if ((mpModel->mObjStatus & 32ul) == 0) {
            if (mCurrentResNo != ResourceNo) {
                rShakeCtrl* t0 = mpBank[ResourceNo];
                if (mpResource != nullptr) {
                    mpResource->release();
                    mpResource = nullptr;
                }
                if (t0 != nullptr) {
                    mpResource = t0;
                    t0->addRef();
                    initShakeCtrl();
                    mCurrentResNo = ResourceNo;
                    mDir.x = shakeDir.x;
                    mDir.y = shakeDir.y;
                    mDir.z = shakeDir.z;
                    mDir.pad_ = 0.0f;
                    uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                    if (pShakeCtrl != nullptr) {
                        pShakeCtrl->shake(mDir);
                    }
                } else {
                    initShakeCtrl();
                    mCurrentResNo = ResourceNo;
                    mDir.x = shakeDir.x;
                    mDir.y = shakeDir.y;
                    mDir.z = shakeDir.z;
                    mDir.pad_ = 0.0f;
                    uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                    if (pShakeCtrl != nullptr) {
                        pShakeCtrl->shake(mDir);
                    }
                }
            } else {
                mDir.x = shakeDir.x;
                mDir.y = shakeDir.y;
                mDir.z = shakeDir.z;
                mDir.pad_ = 0.0f;
                uCnsShakeCtrl* pShakeCtrl = findNearestCnsShakeCtrl(static_cast<s32>(JntNo));
                if (pShakeCtrl != nullptr) {
                    pShakeCtrl->shake(mDir);
                }
            }
        }
    }
}

void cpShakeCtrl::shake(cHitInfo* pHitInfo, bool force_shake, s32 ResourceNo) {
    if (pHitInfo == nullptr) {
        return;
    }
    shake(pHitInfo->getAttackParam(), pHitInfo->mpDfdGeom->mpSrcGeom, pHitInfo->mpAtkModel, pHitInfo->mpDfdModel, force_shake, static_cast<u32>(ResourceNo));
}

void cpShakeCtrl::shake(cHitInfoAfter* pHitInfo, bool force_shake, s32 ResourceNo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpAtkModel == nullptr) {
        shake(pHitInfo->mCommonInfo.mpAttackParam, pHitInfo->mCommonInfo.mpDfdCollGeom, pHitInfo->mCommonInfo.mpShlOwnerModel, pHitInfo->mCommonInfo.mpDfdModel, force_shake, static_cast<u32>(ResourceNo));
    } else {
        shake(pHitInfo->mCommonInfo.mpAttackParam, pHitInfo->mCommonInfo.mpDfdCollGeom, pHitInfo->mCommonInfo.mpAtkModel, pHitInfo->mCommonInfo.mpDfdModel, force_shake, static_cast<u32>(ResourceNo));
    }
}

__attribute__((weak)) uCnsShakeCtrl* cpShakeCtrl::findNearestCnsShakeCtrl(s32 JntNo) {
    MtObject* v5_9;
    if (mpModel == nullptr) {
        v5_9 = nullptr;
    } else {
        if (mpModel->mJointTable[static_cast<unsigned char>(JntNo)] == 0xFF) {
            v5_9 = nullptr;
        } else {
            if ((&mpModel->mJoint[mpModel->mJointTable[static_cast<unsigned char>(JntNo)]]) == nullptr) {
                v5_9 = nullptr;
            } else {
                uModel::Joint* v0_9 = &mpModel->mJoint[mpModel->mJointTable[static_cast<unsigned char>(JntNo)]];
                unsigned int i1_3;
                for (;;) {
                    if (mpResource != nullptr) {
                        u32 v1_10 = v0_9->mNo;
                        if (mpResource->getDataNum() != 0) {
                            i1_3 = 0;
                            for (;;) {
                                if (i1_3 < mCnsShakeCtrlArray.mLength) {
                                    cShakeCtrl* t0 = mpResource->getData(i1_3);
                                    if (t0 != nullptr) {
                                        if (t0->mJntNo == static_cast<int>(v1_10)) {
                                            uCnsShakeCtrl* pCnsShakeCtrl = static_cast<uCnsShakeCtrl*>(mCnsShakeCtrlArray.mpArray[i1_3]);
                                            if (pCnsShakeCtrl != nullptr) {
                                                v5_9 = pCnsShakeCtrl;
                                                return static_cast<uCnsShakeCtrl*>(v5_9);
                                            }
                                        }
                                    }
                                }
                                if ((i1_3 + 1u) < mpResource->getDataNum()) {
                                    i1_3 += 1u;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                    uModel::Joint* pJnt = v0_9->getParentJoint();
                    if (pJnt != nullptr) {
                        v0_9 = pJnt;
                    } else {
                        break;
                    }
                }
                v5_9 = nullptr;
            }
        }
    }
    return static_cast<uCnsShakeCtrl*>(v5_9);
}

void cpShakeCtrl::enableConstraint(bool enable) {
    if (mCnsShakeCtrlArray.mLength != 0) {
        u32 v0_0 = mCnsShakeCtrlArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCnsShakeCtrlArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<uCnsShakeCtrl*>(mCnsShakeCtrlArray.mpArray[i0_3])->setConstraintEnable(enable);
                v1_0 = mCnsShakeCtrlArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void cpShakeCtrl::shake(const cAttackParam* pAttackParam, const cCollGeom* pDfdGeom, uDDOModel* pAtkModel, uDDOModel* pDfdModel, bool force_shake, u32 ResourceNo) {
    DDON_STUB("cpShakeCtrl::shake")
    /* stub */
}

inline cpShakeCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShakeCtrl::MyDTI cpShakeCtrl::DTI("cpShakeCtrl", &::cpComponent::DTI, 208ul, 0u, 0u);

MtObject* cpShakeCtrl::MyDTI::newInstance() const {
    return new (16u) cpShakeCtrl;
}

template MtTypedArray<uCnsShakeCtrl>::~MtTypedArray();

