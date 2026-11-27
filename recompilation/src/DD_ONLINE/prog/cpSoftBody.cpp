// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpSoftBody.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "sBakingJointOrder.h"
#include "../../XFramework/sUnit.h"
#include "uDDOActorModelPl.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uSimSoftBody.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpSoftBody::getDTI() const {
    return cpSoftBody::DTI;
}

void* cpSoftBody::operator new(size_t sz, u32 align) {
    return cpSoftBody::getAllocator()->memAlloc(sz, align, cpSoftBody::DTI.getID());
}

cpSoftBody::cpSoftBody() {
    mCollisionGroup = 0;
    mprSoundPhysicsSoftBody = nullptr;
    mprDeformWeightMap = nullptr;
    mpOwnerDDOModel = nullptr;
    mpOwnerModel = nullptr;
    mpSimSoftBody = nullptr;
    mMaxIterate = 3;
    mColliderType = 4;
    mNCGlobalWeight = 0.0f;
    mWorldCoeffTrans = 1.0f;
    mWorldCoeffRot = 1.0f;
    mBaseJointNo = -1;
    mIsUpdateFrame = true;
    mIsScrCollision = false;
    mIsResetRestart = true;
    mIsApproxScrCollision = false;
    mIsGrassWind = false;
    mIsNCollision = false;
    mIsObjCollision = false;
    mIsISCollision = false;
    mIsSimCulling = true;
    mIsUse8Weight = false;
    mIsActive = false;
    mIsCreateSoftBodyResource = false;
    mIsCreateCollisionResource = false;
    mIsStop = false;
    mIsStopOld = false;
    mIsCollisionActive = false;
    mIsCollisionDisp = false;
    mIsResetRestartSave = true;
    mIsFirstUpdate = false;
    mIsSameFrameFirstUpdateLimit = false;
}

cpSoftBody::~cpSoftBody() {
    DDON_STUB("cpSoftBody::~cpSoftBody")
    /* stub */
}

void cpSoftBody::move() {
    if (!mActive) {
        return;
    }
    update();
}

void cpSoftBody::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpOwnerModel != nullptr) {
        if (!mpOwnerModel->isEnable()) {
            mpOwnerModel = nullptr;
        }
    }
    if (mpOwnerDDOModel == nullptr) {
        return;
    }
    if (mpOwnerDDOModel->isEnable()) {
        return;
    }
    mpOwnerDDOModel = nullptr;
}

void cpSoftBody::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsActive", &mIsActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsStop", &mIsStop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCollisionActive", &mIsCollisionActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCollisionGroup", &mCollisionGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUpdateFrame", &mIsUpdateFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxIterate", &mMaxIterate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsGrassWind", &mIsGrassWind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColliderType", &mColliderType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsScrCollision", &mIsScrCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsObjCollision", &mIsObjCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsResetRestart", &mIsResetRestart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNCollision", &mIsNCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNCGlobalWeight", &mNCGlobalWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsISCollision", &mIsISCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsApproxScrCollision", &mIsApproxScrCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSimCulling", &mIsSimCulling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUse8Weight", &mIsUse8Weight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpSimSoftBody", reinterpret_cast<MT_MFUNC>(&::cpSoftBody::getSimSoftBody), reinterpret_cast<MT_MFUNC>(&::cpSoftBody::setSimSoftBody), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mWorldCoeffTrans", &mWorldCoeffTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldCoeffRot", &mWorldCoeffRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBaseJointNo", &mBaseJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mprDeformWeightMap", "resource", reinterpret_cast<MT_MFUNC>(&::cpSoftBody::getSoftBodyResource), reinterpret_cast<MT_MFUNC>(&::cpSoftBody::setSoftBodyResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Release", static_cast<MT_MFUNC>(&::cpSoftBody::release), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Reset Simulation", static_cast<MT_MFUNC32>(&::cpSoftBody::restartSimulation), 0u, 10u);
}

__attribute__((weak)) void cpSoftBody::update() {
    DDON_STUB("cpSoftBody::update")
    /* stub */
}

void cpSoftBody::release() {
        if (mpSimSoftBody) {
            mpSimSoftBody->kill();
            mpSimSoftBody = nullptr;
        }
        if (mprSoundPhysicsSoftBody) {
            reinterpret_cast<cResource*>(mprSoundPhysicsSoftBody)->release();
            mprSoundPhysicsSoftBody = nullptr;
        }
        if (mprDeformWeightMap) {
            reinterpret_cast<cResource*>(mprDeformWeightMap)->release();
            mprDeformWeightMap = nullptr;
        }
}

__attribute__((weak)) bool cpSoftBody::setSoftBody(uModel* pOwner, rDeformWeightMap* pDWM, u32 Mode) {
    DDON_STUB("cpSoftBody::setSoftBody")
    return {};
}

bool cpSoftBody::isSoftBodyDraw() {
    if (mprDeformWeightMap != nullptr) {
        if (mpSimSoftBody != nullptr) {
            if (mIsActive) {
                if (mpOwner != nullptr) {
                    if (!mpOwner->isKindOf(uHuman::DTI)) {
                        if (mpOwner != nullptr) {
                            if (!mpOwner->isKindOf(uDDOActorModelPl::DTI)) {
                                return true;
                            } else {
                                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpOwner) + 11032)) != 0) {
                                    return sBakingJointOrder::getInstance()->isBaked(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpOwner) + 11032)) + 17596));
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            return true;
                        }
                    } else {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpOwner) + 11032)) != 0) {
                            return sBakingJointOrder::getInstance()->isBaked(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpOwner) + 11032)) + 17596));
                        } else {
                            return false;
                        }
                    }
                } else {
                    return true;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void cpSoftBody::draw(cDraw* pDraw) {
    DDON_STUB("cpSoftBody::draw")
    /* stub */
}

rDeformWeightMap* cpSoftBody::getSoftBodyResource() {
    return mprDeformWeightMap;
}

void cpSoftBody::setSimSoftBody(uSimSoftBody* pUnit) {
    if (pUnit == nullptr) {
        return;
    }
    if (mpSimSoftBody != nullptr) {
        return;
    }
    if (pUnit == mpSimSoftBody) {
        return;
    }
    mpSimSoftBody = pUnit;
    pUnit->setTargetUnit(mpOwnerModel);
    pUnit->enableColliderCollision();
    pUnit->mColliderType = 4;
    if (mprDeformWeightMap == nullptr) {
        return;
    }
    mpSimSoftBody->setDeformWeightMap(mprDeformWeightMap);
}

__attribute__((weak)) void cpSoftBody::setSoftBodyResource(rDeformWeightMap* pRes) {
    DDON_STUB("cpSoftBody::setSoftBodyResource")
    /* stub */
}

void cpSoftBody::setActive(bool isFlag) {
    mIsActive = isFlag;
}

void cpSoftBody::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    const MtDTI& t0 = pOwner->getDTI();
    MT_CTSTR v0_1 = uModel::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 != v0_0->mName) {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        } else {
            mpOwnerModel = static_cast<uModel*>(pOwner);
            break;
        }
    }
    const MtDTI& t1 = pOwner->getDTI();
    MT_CTSTR v2_1 = uDDOModel::DTI.mName;
    const MtDTI* v2_0 = &t1;
    const MtDTI* v4_0;
    MT_CTSTR v4_1;
    for (;;) {
        if (v2_1 != v2_0->mName) {
            if (v2_0->mpParent != nullptr) {
                v2_0 = v2_0->mpParent;
            } else {
                return;
            }
        } else {
            const MtDTI& t2 = pOwner->getDTI();
            v4_1 = uDDOModel::DTI.mName;
            if (v4_1 == t2.mName) {
                mpOwnerDDOModel = static_cast<uDDOModel*>(pOwner);
                return;
            } else {
                v4_0 = &t2;
                break;
            }
        }
    }
    for (;;) {
        if (v4_0->mpParent == nullptr) {
            mpOwnerDDOModel = nullptr;
            return;
        } else {
            if (v4_1 != v4_0->mpParent->mName) {
                v4_0 = v4_0->mpParent;
            } else {
                break;
            }
        }
    }
    mpOwnerDDOModel = static_cast<uDDOModel*>(pOwner);
}

static auto ddon_emit_0x01a5fad0 __attribute__((used)) = &cpSoftBody::getSimSoftBody;

void cpSoftBody::restartSimulation(u32 LoopNum) {
    if (mpSimSoftBody == nullptr) {
        return;
    }
    mpSimSoftBody->restartSimulation(LoopNum);
}

inline cpSoftBody::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpSoftBody::MyDTI cpSoftBody::DTI("cpSoftBody", &::cpComponent::DTI, 168ul, 0u, 0u);

MtObject* cpSoftBody::MyDTI::newInstance() const {
    return new (16u) cpSoftBody;
}

