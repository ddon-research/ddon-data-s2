// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpDDMrlMgr.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cComponentManager.h"
#include "cDDMaterialCtrl.h"
#include "cpComponent.h"
#include "cpEquip.h"
#include "../../XFramework/nDrawMaterial.h"
#include "rOutlineParamList.h"
#include "sEffectExt.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOActorModel.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "uHumanEnemy.h"
#include "uPlayer.h"
#include "uWeapon.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpDDMrlMgr::getDTI() const {
    return cpDDMrlMgr::DTI;
}

void* cpDDMrlMgr::operator new(size_t sz, u32 align) {
    return cpDDMrlMgr::getAllocator()->memAlloc(sz, align, cpDDMrlMgr::DTI.getID());
}

cpDDMrlMgr::cpDDMrlMgr() {
    DDON_STUB("cpDDMrlMgr::cpDDMrlMgr")
    /* stub */
}

__attribute__((noinline)) cpDDMrlMgr::~cpDDMrlMgr() {
    if (mNowMARD.mLength != 0) {
        u32 v0_0 = mNowMARD.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNowMARD.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNowMARD.mpArray[i0_3];
                v1_0 = mNowMARD.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNowMARD.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNowMARD.mpArray));
    }
    mNowMARD.mpArray = nullptr;
    mNowMARD.mBufsiz = 0;
    mNowMARD.mLength = 0;
    if (mOldMARD.mLength != 0) {
        u32 v3_0 = mOldMARD.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mOldMARD.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mOldMARD.mpArray[i3_3];
                v4_0 = mOldMARD.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mOldMARD.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mOldMARD.mpArray));
    }
    mOldMARD.mpArray = nullptr;
    mOldMARD.mBufsiz = 0;
    mOldMARD.mLength = 0;
}

void cpDDMrlMgr::setup() {
    mpDDMrlCtrl.mControlEnable = 0xFFFFFFFF;
}

__attribute__((weak)) void cpDDMrlMgr::move() {
    DDON_STUB("cpDDMrlMgr::move")
    /* stub */
}

void cpDDMrlMgr::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpDDMrlMgr::setOwner(MtObject* pOwner) {
    mOwnerModelKind = 0;
    mpOwner = pOwner;
    const MtDTI& t0 = pOwner->getDTI();
    MT_CTSTR v0_1 = uBaseModel::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 != v0_0->mName) {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        } else {
            mpDDMrlCtrl.mpOwner = static_cast<uBaseModel*>(pOwner);
            break;
        }
    }
    const MtDTI& t1 = pOwner->getDTI();
    MT_CTSTR v2_1 = uDDOModel::DTI.mName;
    for (const MtDTI* v2_0 = &t1;;) {
        if (v2_1 != v2_0->mName) {
            if (v2_0->mpParent != nullptr) {
                v2_0 = v2_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 1u;
            break;
        }
    }
    const MtDTI& t2 = pOwner->getDTI();
    MT_CTSTR v4_1 = uPlayer::DTI.mName;
    for (const MtDTI* v4_0 = &t2;;) {
        if (v4_1 != v4_0->mName) {
            if (v4_0->mpParent != nullptr) {
                v4_0 = v4_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 2u;
            break;
        }
    }
    const MtDTI& t3 = pOwner->getDTI();
    MT_CTSTR v6_1 = uEnemy::DTI.mName;
    for (const MtDTI* v6_0 = &t3;;) {
        if (v6_1 != v6_0->mName) {
            if (v6_0->mpParent != nullptr) {
                v6_0 = v6_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 4u;
            break;
        }
    }
    const MtDTI& t4 = pOwner->getDTI();
    MT_CTSTR v8_1 = uHumanEnemy::DTI.mName;
    for (const MtDTI* v8_0 = &t4;;) {
        if (v8_1 != v8_0->mName) {
            if (v8_0->mpParent != nullptr) {
                v8_0 = v8_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 8u;
            break;
        }
    }
    const MtDTI& t5 = pOwner->getDTI();
    MT_CTSTR v10_1 = uDDOActorModel::DTI.mName;
    for (const MtDTI* v10_0 = &t5;;) {
        if (v10_1 != v10_0->mName) {
            if (v10_0->mpParent != nullptr) {
                v10_0 = v10_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 16u;
            break;
        }
    }
    const MtDTI& t6 = pOwner->getDTI();
    MT_CTSTR v12_1 = uHuman::DTI.mName;
    for (const MtDTI* v12_0 = &t6;;) {
        if (v12_1 != v12_0->mName) {
            if (v12_0->mpParent != nullptr) {
                v12_0 = v12_0->mpParent;
            } else {
                break;
            }
        } else {
            mOwnerModelKind = mOwnerModelKind | 32u;
            break;
        }
    }
    const MtDTI& t7 = pOwner->getDTI();
    MT_CTSTR v14_1 = uWeapon::DTI.mName;
    for (const MtDTI* v14_0 = &t7;;) {
        if (v14_1 == v14_0->mName) {
            u32 t8 = mOwnerModelKind;
            mOwnerModelKind = t8 | 64u;
            mpDDMrlCtrl.mOwnerModelKind = (t8 | mpDDMrlCtrl.mOwnerModelKind) | 64u;
            return;
        } else {
            if (v14_0->mpParent != nullptr) {
                v14_0 = v14_0->mpParent;
            } else {
                break;
            }
        }
    }
    if (mOwnerModelKind == 0) {
        mOwnerModelKind = 0x80000000;
        mpDDMrlCtrl.mOwnerModelKind = mpDDMrlCtrl.mOwnerModelKind | 0x80000000u;
    } else {
        mpDDMrlCtrl.mOwnerModelKind = mOwnerModelKind | mpDDMrlCtrl.mOwnerModelKind;
    }
}

static auto ddon_emit_0x01a58930 __attribute__((used)) = &cpDDMrlMgr::getDDMrlCtrl;

void cpDDMrlMgr::setDDMrlCtrlEquip(cDDMaterialCtrl* set) {
    u32 i = 0;
    cDDMaterialCtrl* * p1 = &mpDDMrlCtrlEquip[0];
    do {
        if ((*p1) == nullptr) {
            *p1 = set;
            return;
        }
        i += 1u;
        p1 += static_cast<int>(1);
    } while (i <= 15u);
}

void cpDDMrlMgr::releaseDDMrlCtrlEquip(cDDMaterialCtrl* set) {
    u32 i = 0;
    cDDMaterialCtrl* * p1 = &mpDDMrlCtrlEquip[0];
    do {
        if (set == (*p1)) {
            *p1 = nullptr;
            return;
        }
        i += 1u;
        p1 += static_cast<int>(1);
    } while (i <= 15u);
}

void cpDDMrlMgr::setCommonStateMrlCtrl() {
    if (mbDirty) {
        if (mpOwner != nullptr) {
            mpDDMrlCtrl.setCommonState();
            for (unsigned int i0_3 = 0; i0_3 != 16; i0_3 = i0_3 + 1u) {
                if (mpDDMrlCtrlEquip[i0_3] != nullptr) {
                    mpDDMrlCtrlEquip[i0_3]->cDDMaterialCtrl::setCommonState();
                }
            }
        }
    }
}

__attribute__((weak)) void cpDDMrlMgr::getTargetModelArray(MtTypedArray<uDDOModel>* pTargetArray, bool isAddThis) {
    DDON_STUB("cpDDMrlMgr::getTargetModelArray")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::getTargetModelArray(MtTypedArray<uDDOModel>* pTargetArray, cpEquip* pEquip) {
    DDON_STUB("cpDDMrlMgr::getTargetModelArray")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::requestOutline(sEffectExt::OUTLINE type) {
    DDON_STUB("cpDDMrlMgr::requestOutline")
    /* stub */
}

void cpDDMrlMgr::requestOutlineMode(u32 mode) {
    mpDDMrlCtrl.setOutlineMode(mode);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setOutlineMode(mode);
        }
    }
}

__attribute__((weak)) void cpDDMrlMgr::setOutlineColor(MtVector4& endOCol, MtVector4& endICol) {
    DDON_STUB("cpDDMrlMgr::setOutlineColor")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::setOutlineParam(u32 mode, u32 blendT, u32 colT, MtVector4& colO, MtVector4& colI, f32 balanceOffset, f32 balanceScale, f32 balance) {
    DDON_STUB("cpDDMrlMgr::setOutlineParam")
    /* stub */
}

void cpDDMrlMgr::setOutlineTypeSdl(u32 type) {
    mSdlOutlineRequestNo = type;
    if (type <= 39u) {
        requestOutline(static_cast<sEffectExt::OUTLINE>(type));
    }
}

static auto ddon_emit_0x01a58970 __attribute__((used)) = &cpDDMrlMgr::getOutlineTypeSdl;

void cpDDMrlMgr::requestDeadShader() {
    mbDirtyMrlMode = true;
    mbDirtyBaseShaderMode = true;
    MtObject* v0_9 = getOwner();
    u32 v2_9;
    if (v0_9 == nullptr) {
        v2_9 = mOwnerModelKind >> 2;
    } else {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 304)) == 0) {
            v2_9 = mOwnerModelKind >> 2;
        } else {
            unsigned int i0_3 = 0;
            for (u32 v0_8 = mOwnerModelKind >> 2;;) {
                nDraw::Material* t0 = static_cast<uBaseModel*>(v0_9)->getMaterial(i0_3);
                if (t0->getAnimationData() != nullptr) {
                    if (t0->getAnimationData()->getNo("Death") != -1) {
                        if ((v0_8 & 1u) != 0) {
                            mpDDMrlCtrl.setBaseShaderMode(0u);
                        }
                        requestMaterialAnimation("Death", 0u, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
                        return;
                    }
                }
                if ((i0_3 + 1u) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 304))) {
                    i0_3 += 1u;
                } else {
                    v2_9 = v0_8;
                    break;
                }
            }
        }
    }
    mpDDMrlCtrl.setMaterialMode(2u);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(2u);
        }
    }
    if ((v2_9 & 1u) != 0) {
        mpDDMrlCtrl.setBaseShaderMode(2u);
    }
}

__attribute__((weak)) bool cpDDMrlMgr::isEndDeadShader() {
        mbDirty = true;
        bool ret = false;
        if ((mOwnerModelKind & 4) != 0) {
            ret = static_cast<cDDMaterialCtrl::cShaderDataDamage*>(mpDDMrlCtrl.mBaseShaderData.getBuffer()[2])->isEnd();
        }
        if ((mOwnerModelKind & 0x20) != 0) {
            ret = static_cast<cDDMaterialCtrl::cShaderDataMaterial*>(mpDDMrlCtrl.mMaterialData.getBuffer()[2])->isEnd();
        }
        return ret;
}

__attribute__((weak)) void cpDDMrlMgr::requestAilmentShader(u32 type, u32 prio) {
    DDON_STUB("cpDDMrlMgr::requestAilmentShader")
    /* stub */
}

void cpDDMrlMgr::requestMaterialMode(u32 set) {
    mbDirtyMrlMode = true;
    mpDDMrlCtrl.setMaterialMode(set);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(set);
        }
    }
}

void cpDDMrlMgr::resetMaterialMode() {
    mbDirtyMrlMode = true;
    mpDDMrlCtrl.setMaterialMode(0u);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(0u);
        }
    }
}

void cpDDMrlMgr::requestBlackModel() {
    mbDirtyMrlMode = true;
    mpDDMrlCtrl.setMaterialMode(1u);
    mpDDMrlCtrl.setDataMaterialDiffuseColor(MtVector4::Zero);
    mpDDMrlCtrl.setDataMaterialSpecularColor(MtVector4::Zero);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(1u);
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setDataMaterialDiffuseColor(MtVector4::Zero);
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setDataMaterialSpecularColor(MtVector4::Zero);
        }
    }
}

__attribute__((weak)) void cpDDMrlMgr::requestBloodStainPhase(u32 phase) {
    DDON_STUB("cpDDMrlMgr::requestBloodStainPhase")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::requestHakuryuStonePhase(u32 phase) {
    DDON_STUB("cpDDMrlMgr::requestHakuryuStonePhase")
    /* stub */
}

void cpDDMrlMgr::requestEnchantMaterialAnimation(u32 elemType) {
    if (elemType <= 1u) {
        mbDirtyMrlMode = true;
        mpDDMrlCtrl.setMaterialMode(0u);
        for (unsigned int i0_3 = 0; i0_3 != 16; i0_3 = i0_3 + 1u) {
            if (mpDDMrlCtrlEquip[i0_3] != nullptr) {
                mpDDMrlCtrlEquip[i0_3]->cDDMaterialCtrl::setMaterialMode(0u);
            }
        }
    } else {
        mbDirtyMrlMode = true;
        mpDDMrlCtrl.setMaterialMode(elemType + 1u);
        for (u32 i = 0; i != 16; i = i + 1u) {
            if (mpDDMrlCtrlEquip[i] != nullptr) {
                mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(elemType + 1u);
            }
        }
    }
}

void cpDDMrlMgr::resetEnchantMaterialAnimation() {
    mbDirtyMrlMode = true;
    mpDDMrlCtrl.setMaterialMode(0u);
    for (u32 i = 0; i != 16; i = i + 1u) {
        if (mpDDMrlCtrlEquip[i] != nullptr) {
            mpDDMrlCtrlEquip[i]->cDDMaterialCtrl::setMaterialMode(0u);
        }
    }
}

__attribute__((weak)) void cpDDMrlMgr::requestAlchemyShellLevel(u32 level) {
    DDON_STUB("cpDDMrlMgr::requestAlchemyShellLevel")
    /* stub */
}

void cpDDMrlMgr::setDefaultMaterialMode(u32 set) {
    mpDDMrlCtrl.mDefMaterialMode = set;
}

__attribute__((weak)) void cpDDMrlMgr::setStonePassageFrame(f32 set) {
    DDON_STUB("cpDDMrlMgr::setStonePassageFrame")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::setGoldPassageFrame(f32 set) {
    DDON_STUB("cpDDMrlMgr::setGoldPassageFrame")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::setErosionLevel(s32 setLevel) {
    DDON_STUB("cpDDMrlMgr::setErosionLevel")
    /* stub */
}

__attribute__((weak)) void cpDDMrlMgr::setToDefaultFrame(u32 set) {
    DDON_STUB("cpDDMrlMgr::setToDefaultFrame")
    /* stub */
}

void cpDDMrlMgr::requestElementEmMode(u32 Element) {
    unsigned int i0_3;
    if (Element != 1) {
        mpDDMrlCtrl.setMaterialMode(Element + 17u);
        return;
    } else {
        mbDirtyMrlMode = true;
        mpDDMrlCtrl.setMaterialMode(0u);
        i0_3 = 0;
    }
    for (;;) {
        if (mpDDMrlCtrlEquip[i0_3] != nullptr) {
            mpDDMrlCtrlEquip[i0_3]->cDDMaterialCtrl::setMaterialMode(0u);
        }
        if ((i0_3 + 1u) != 16) {
            i0_3 = i0_3 + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) void cpDDMrlMgr::updateMaterialAnimation() {
    DDON_STUB("cpDDMrlMgr::updateMaterialAnimation")
    /* stub */
}

__attribute__((weak)) bool cpDDMrlMgr::isActionAnimation(MT_CTSTR name, u32 MaterialId) {
    DDON_STUB("cpDDMrlMgr::isActionAnimation")
    return {};
}

__attribute__((weak)) void cpDDMrlMgr::requestMaterialAnimation(MT_CTSTR name, u32 MaterialId, MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>* pTgtArray) {
    DDON_STUB("cpDDMrlMgr::requestMaterialAnimation")
    /* stub */
}

void cpDDMrlMgr::requestMaterialAnimation(u32 num, u32 MaterialId) {
    requestMaterialAnimation(cpDDMrlMgr::ANIM_NAME_TBL[num], MaterialId, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
}

void cpDDMrlMgr::requestMaterialAnimationWeakPoint(u32 num) {
    if (num != 3) {
        if (num == 2) {
            requestMaterialAnimation("Weakpoint2", 0u, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
        } else {
            if (num == 1) {
                requestMaterialAnimation("Weakpoint1", 0u, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
            }
        }
    } else {
        requestMaterialAnimation("Weakpoint3", 0u, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
    }
}

void cpDDMrlMgr::requestMaterialAnimationPartsbreak(u32 Id) {
    if (Id == 0) {
        return;
    }
    requestMaterialAnimation(cpDDMrlMgr::ANIM_NAME_TBL[(Id <= 9u) ? (Id + 7u) : 8u], 0u, static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
}

void cpDDMrlMgr::requestMaterialAnimationLevel(u32 PartsId, u32 LevelId) {
    if (PartsId <= 9u) {
        if (LevelId <= 4u) {
            requestMaterialAnimation(cpDDMrlMgr::ANIM_NAME_TBL[LevelId + 17u], PartsId + (cDDMaterialCtrl::cShaderDataAnimation::MRL_ANIM_LEVEL_START_MATERIAL_ID), static_cast<MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>*>(nullptr));
        }
    }
}

__attribute__((weak)) bool cpDDMrlMgr::isExistSameDataFromOld(MT_CTSTR name, u32 MaterialId) {
    DDON_STUB("cpDDMrlMgr::isExistSameDataFromOld")
    return {};
}

void cpDDMrlMgr::initDDMaterialCtrl() {
    mpDDMrlCtrl.init();
    mbDirtyMrlMode = true;
    mbDirty = true;
    mbDirtyAnim = true;
    mbDirtyBaseShaderMode = true;
    mbDirtyShaderMode = true;
    mbDirtyOutline = false;
}

void cpDDMrlMgr::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpDDMaterialCtrl", reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::getDDMrlCtrl), reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::setDDMrlCtrl), 160u, reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::getDDMrlCtrlNum), reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::setDDMrlCtrlNum));
    s << MtProperty(static_cast<MtObject*>(this), "SetToDefaultFrame", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::setToDefaultFrame), 0u, 20u);
    s << MtProperty(static_cast<MtObject*>(this), "RequestMaterialMode", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::requestMaterialMode), 0u, 12u);
    s << MtProperty(static_cast<MtObject*>(this), "RequestHakuryuStonePhase0", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::requestHakuryuStonePhase), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RequestHakuryuStonePhase1", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::requestHakuryuStonePhase), 0u, 1u);
    s << MtProperty(static_cast<MtObject*>(this), "RequestHakuryuStonePhase2", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::requestHakuryuStonePhase), 0u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "RequestHakuryuStonePhase3", static_cast<MT_MFUNC32>(&::cpDDMrlMgr::requestHakuryuStonePhase), 0u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mSdlOutlineRequestNo", reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::getOutlineTypeSdl), reinterpret_cast<MT_MFUNC>(&::cpDDMrlMgr::setOutlineTypeSdl), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void cpDDMrlMgr::setDDMrlCtrl(cDDMaterialCtrl* ptr, u32 set) {
}

static auto ddon_emit_0x01a58950 __attribute__((used)) = &cpDDMrlMgr::getDDMrlCtrlNum;

__attribute__((weak)) void cpDDMrlMgr::setDDMrlCtrlNum(u32 set) {
}

inline cpDDMrlMgr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpDDMrlMgr::MyDTI cpDDMrlMgr::DTI("cpDDMrlMgr", &::cpComponent::DTI, 5152ul, 0u, 0u);

__attribute__((weak)) MtObject* cpDDMrlMgr::MyDTI::newInstance() const {
    DDON_STUB("cpDDMrlMgr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpDDMrlMgr::cMaterialAnimationRequestData::getDTI() const {
    return cpDDMrlMgr::cMaterialAnimationRequestData::DTI;
}

cpDDMrlMgr::cMaterialAnimationRequestData::~cMaterialAnimationRequestData() {
}

inline cpDDMrlMgr::cMaterialAnimationRequestData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpDDMrlMgr::cMaterialAnimationRequestData::MyDTI cpDDMrlMgr::cMaterialAnimationRequestData::DTI("cpDDMrlMgr::cMaterialAnimationRequestData", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* cpDDMrlMgr::cMaterialAnimationRequestData::MyDTI::newInstance() const {
    DDON_STUB("cpDDMrlMgr::cMaterialAnimationRequestData::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cpDDMrlMgr::cMaterialAnimationRequestData>::~MtTypedArray();

