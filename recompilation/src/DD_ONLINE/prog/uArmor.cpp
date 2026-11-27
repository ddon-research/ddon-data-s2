// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uArmor.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpSoftBody.h"
#include "../../XFramework/nDrawMaterial.h"
#include "rArchiveListArray.h"
#include "rDDOModelMontage.h"
#include "../../XFramework/rDeformWeightMap.h"
#include "../../XFramework/rModel.h"
#include "rWeaponResTable.h"
#include "sArchiveManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHumanEnemy.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uSimSoftBody.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uArmor::getDTI() const {
    return uArmor::DTI;
}

uArmor::~uArmor() {
    if (mpModelRes != nullptr) {
        mpModelRes->release();
        mpModelRes = nullptr;
    }
    if (mpDwmRes != nullptr) {
        mpDwmRes->release();
        mpDwmRes = nullptr;
    }
    if (mpMontage == nullptr) {
        return;
    }
    mpMontage->release();
    mpMontage = nullptr;
}

void uArmor::setup() {
    this->uDDOModel::setup();
    if (mpModelRes != nullptr) {
        setModel(mpModelRes);
    }
    if (mpOwner != nullptr) {
        setParent(static_cast<uCoord*>(mpOwner), -1);
        if (mpOwner != nullptr) {
            mLightGroup = mpOwner->getLightGroup();
            mDrawMode = mpOwner->mDrawMode;
        }
    }
    if (mpDwmRes != nullptr) {
        if (mpSoftBody != nullptr) {
            mpSoftBody->setSoftBody(static_cast<uModel*>(this), mpDwmRes, 1u);
        }
    }
    if (mUseHumanEnemyMontage) {
        if (mpMontage != nullptr) {
            mpMontage->applyMontage(static_cast<uModel*>(this), mPartsPatern);
        }
    } else {
        setParts(mPartsPatern);
        setColor(mColorPatern);
    }
}

void uArmor::createProperty(MtPropertyList& s) {
    this->uDDOModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpOwner", reinterpret_cast<MtObject* *>(&mpOwner), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSimSoftBody", reinterpret_cast<MtObject* *>(&mpSimSoftBody), 0u, 0u);
}

__attribute__((weak)) void uArmor::move() {
    DDON_STUB("uArmor::move")
    /* stub */
}

__attribute__((weak)) void uArmor::moveAfter() {
    DDON_STUB("uArmor::moveAfter")
    /* stub */
}

void uArmor::draw(cDraw* pDraw) {
    this->uDDOModel::draw(pDraw);
}

void uArmor::kill() {
    setModel(static_cast<rModel*>(nullptr));
    mpOwner = nullptr;
    if (mpSimSoftBody != nullptr) {
        mpSimSoftBody->kill();
        mpSimSoftBody = nullptr;
    }
    this->uDDOModel::kill();
}

void uArmor::updatePtr() {
    this->uDDOModel::updatePtr();
    if (mpOwner != nullptr) {
        if (!mpOwner->isEnable()) {
            mpOwner = nullptr;
        }
    }
    if (mpSimSoftBody == nullptr) {
        return;
    }
    if (mpSimSoftBody->isEnable()) {
        return;
    }
    mpSimSoftBody = nullptr;
}

__attribute__((weak)) void uArmor::createComponent() {
    DDON_STUB("uArmor::createComponent")
    /* stub */
}

void uArmor::callbackUpdateMatrix() {
    updateLocalMatrix();
    updateWorldMatrix();
    uModel* v0_8 = mpOwner;
    if (v0_8 != nullptr) {
        u32 v0_6 = v0_8->mJointNum;
        if (v0_6 != 0) {
            u32 v0_7 = mJointNum;
            if (v0_7 != 0) {
                Joint* p0_4 = mJoint;
                for (unsigned int i0_5 = 0;;) {
                    if (p0_4 != nullptr) {
                        const u8 t0 = v0_8->mJointTable[p0_4->mNo];
                        if (t0 != 0xFF) {
                            Joint* t1 = v0_8->mJoint;
                            if ((&t1[t0]) != nullptr) {
                                if (((static_cast<unsigned int>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(p0_4) + 160)) >> 8) & 255u) != 255) {
                                    if (((static_cast<unsigned int>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(p0_4) + 160)) >> 8) & 255u) < v0_6) {
                                        p0_4->mWmat.m[0].x = t1[t0].mWmat.m[0].x;
                                        p0_4->mWmat.m[0].y = t1[t0].mWmat.m[0].y;
                                        p0_4->mWmat.m[0].z = t1[t0].mWmat.m[0].z;
                                        p0_4->mWmat.m[0].w = t1[t0].mWmat.m[0].w;
                                        p0_4->mWmat.m[1].x = t1[t0].mWmat.m[1].x;
                                        p0_4->mWmat.m[1].y = t1[t0].mWmat.m[1].y;
                                        p0_4->mWmat.m[1].z = t1[t0].mWmat.m[1].z;
                                        p0_4->mWmat.m[1].w = t1[t0].mWmat.m[1].w;
                                        p0_4->mWmat.m[2].x = t1[t0].mWmat.m[2].x;
                                        p0_4->mWmat.m[2].y = t1[t0].mWmat.m[2].y;
                                        p0_4->mWmat.m[2].z = t1[t0].mWmat.m[2].z;
                                        p0_4->mWmat.m[2].w = t1[t0].mWmat.m[2].w;
                                        p0_4->mWmat.m[3].x = t1[t0].mWmat.m[3].x;
                                        p0_4->mWmat.m[3].y = t1[t0].mWmat.m[3].y;
                                        p0_4->mWmat.m[3].z = t1[t0].mWmat.m[3].z;
                                        p0_4->mWmat.m[3].w = t1[t0].mWmat.m[3].w;
                                    }
                                } else {
                                    p0_4->mWmat.m[0].x = t1[t0].mWmat.m[0].x;
                                    p0_4->mWmat.m[0].y = t1[t0].mWmat.m[0].y;
                                    p0_4->mWmat.m[0].z = t1[t0].mWmat.m[0].z;
                                    p0_4->mWmat.m[0].w = t1[t0].mWmat.m[0].w;
                                    p0_4->mWmat.m[1].x = t1[t0].mWmat.m[1].x;
                                    p0_4->mWmat.m[1].y = t1[t0].mWmat.m[1].y;
                                    p0_4->mWmat.m[1].z = t1[t0].mWmat.m[1].z;
                                    p0_4->mWmat.m[1].w = t1[t0].mWmat.m[1].w;
                                    p0_4->mWmat.m[2].x = t1[t0].mWmat.m[2].x;
                                    p0_4->mWmat.m[2].y = t1[t0].mWmat.m[2].y;
                                    p0_4->mWmat.m[2].z = t1[t0].mWmat.m[2].z;
                                    p0_4->mWmat.m[2].w = t1[t0].mWmat.m[2].w;
                                    p0_4->mWmat.m[3].x = t1[t0].mWmat.m[3].x;
                                    p0_4->mWmat.m[3].y = t1[t0].mWmat.m[3].y;
                                    p0_4->mWmat.m[3].z = t1[t0].mWmat.m[3].z;
                                    p0_4->mWmat.m[3].w = t1[t0].mWmat.m[3].w;
                                }
                            }
                        }
                    }
                    if ((i0_5 + 1u) < v0_7) {
                        p0_4 += 1;
                        i0_5 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    updateBoundary();
}

__attribute__((weak)) uArmor* uArmor::createArmorModel(cWeaponResTable* pWepResData, uModel* pParent, u8 partsPatern, s8 colorPatern) {
    DDON_STUB("uArmor::createArmorModel")
    return nullptr;
}

__attribute__((weak)) uArmor* uArmor::createArmorModel(uModel* pParent, rModel* pModelRes, rDeformWeightMap* pDwm) {
    DDON_STUB("uArmor::createArmorModel")
    return nullptr;
}

__attribute__((weak)) uArmor* uArmor::createArmorModelHumanEnemy(cWeaponResTable* pWepResData, uModel* pParent) {
    DDON_STUB("uArmor::createArmorModelHumanEnemy")
    return nullptr;
}

__attribute__((weak)) void uArmor::setParts() {
    DDON_STUB("uArmor::setParts")
    /* stub */
}

__attribute__((weak)) void uArmor::setParts(u8 partsPatern) {
    DDON_STUB("uArmor::setParts")
    /* stub */
}

__attribute__((weak)) void uArmor::setColor(s8 colorPatern) {
    DDON_STUB("uArmor::setColor")
    /* stub */
}

inline uArmor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uArmor::MyDTI uArmor::DTI("uArmor", &::uDDOModel::DTI, 9424ul, 0u, 0u);

__attribute__((weak)) MtObject* uArmor::MyDTI::newInstance() const {
    DDON_STUB("uArmor::MyDTI::newInstance")
    return nullptr;
}

