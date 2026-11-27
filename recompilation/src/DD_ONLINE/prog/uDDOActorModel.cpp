// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uDDOActorModel.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cComponentManager.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "cpJointEx2.h"
#include "rDDOModelMontage.h"
#include "../../XFramework/sResource.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uModelEx.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uDDOActorModel::getDTI() const {
    return uDDOActorModel::DTI;
}

uDDOActorModel::uDDOActorModel() {
    mEditEnable = false;
    mMayaScale = true;
    mParentScale = false;
    mpEquipMontage = nullptr;
    mIsInit = false;
    mpDDMrlMgr = nullptr;
    mpResetCtrl = nullptr;
    mpJointEx2 = nullptr;
    mEquipMontageId = -1;
    mEquipColorId = -1;
    createComponent();
    mAnkleAdjust = false;
    mFootAdjust = false;
}

uDDOActorModel::~uDDOActorModel() {
    if (mpEquipMontage == nullptr) {
        return;
    }
    mpEquipMontage->release();
    mpEquipMontage = nullptr;
}

__attribute__((weak)) void uDDOActorModel::setup() {
    DDON_STUB("uDDOActorModel::setup")
    /* stub */
}

__attribute__((weak)) void uDDOActorModel::move() {
    DDON_STUB("uDDOActorModel::move")
    /* stub */
}

__attribute__((weak)) void uDDOActorModel::sync() {
}

void uDDOActorModel::moveAfter() {
    mComponentMgr.moveAfter();
    this->uBaseModel::moveAfter();
    if (mpJointEx2 != nullptr) {
        mpJointEx2->update();
    }
    if (!mIsInit) {
        return;
    }
    if (mpDDMrlMgr == nullptr) {
        return;
    }
    mpDDMrlMgr->setCommonStateMrlCtrl();
}

void uDDOActorModel::draw(cDraw* pDraw) {
    this->uModel::draw(pDraw);
}

void uDDOActorModel::kill() {
    mComponentMgr.kill();
    this->uActorModel::kill();
}

__attribute__((weak)) void uDDOActorModel::createComponent() {
    DDON_STUB("uDDOActorModel::createComponent")
    /* stub */
}

void uDDOActorModel::createProperty(MtPropertyList& s) {
    this->uActorModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mComponentMgr", static_cast<MtObject*>(&mComponentMgr), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEditEnable", &mEditEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMayaScale", &mMayaScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentScale", &mParentScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResetCtrl", reinterpret_cast<MtObject* *>(&mpResetCtrl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDDMrlMgr", reinterpret_cast<MtObject* *>(&mpDDMrlMgr), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEquipMontage", "resource", reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::getEquipMontage), reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::setEquipMontage), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mEquipMontageId", reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::getEquipMontageId), reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::setEquipMontageId), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mEquipColorId", reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::getEquipColorId), reinterpret_cast<MT_MFUNC>(&::uDDOActorModel::setEquipColorId), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void uDDOActorModel::setEquipMontage(rDDOModelMontage* pRes) {
    DDON_STUB("uDDOActorModel::setEquipMontage")
    /* stub */
}

static auto ddon_emit_0x01ad44d0 __attribute__((used)) = &uDDOActorModel::getEquipMontage;

void uDDOActorModel::setEquipMontageId(s32 id) {
    if (mpEquipMontage == nullptr) {
        return;
    }
    if (mEquipMontageId == id) {
        return;
    }
    mEquipMontageId = id;
    if (id > -1) {
        mpEquipMontage->applyParts(static_cast<uModel*>(this), static_cast<u32>(id));
    } else {
        mPartsDisp[14] = 0xFFFFFFFF;
        mPartsDisp[15] = 0xFFFFFFFF;
        mPartsDisp[12] = 0xFFFFFFFF;
        mPartsDisp[13] = 0xFFFFFFFF;
        mPartsDisp[10] = 0xFFFFFFFF;
        mPartsDisp[11] = 0xFFFFFFFF;
        mPartsDisp[8] = 0xFFFFFFFF;
        mPartsDisp[9] = 0xFFFFFFFF;
        mPartsDisp[6] = 0xFFFFFFFF;
        mPartsDisp[7] = 0xFFFFFFFF;
        mPartsDisp[4] = 0xFFFFFFFF;
        mPartsDisp[5] = 0xFFFFFFFF;
        mPartsDisp[2] = 0xFFFFFFFF;
        mPartsDisp[3] = 0xFFFFFFFF;
        mPartsDisp[0] = 0xFFFFFFFF;
        mPartsDisp[1] = 0xFFFFFFFF;
    }
}

static auto ddon_emit_0x01ad44e0 __attribute__((used)) = &uDDOActorModel::getEquipMontageId;

void uDDOActorModel::setEquipColorId(s32 id) {
    if (mpEquipMontage == nullptr) {
        return;
    }
    if (mEquipColorId == id) {
        return;
    }
    mEquipColorId = id;
    if (id > -1) {
        mpEquipMontage->applyColor(static_cast<uModel*>(this), static_cast<u32>(id), false);
    }
}

static auto ddon_emit_0x01ad44f0 __attribute__((used)) = &uDDOActorModel::getEquipColorId;

bool uDDOActorModel::isOkMrlCtrl() {
    return true;
}

bool uDDOActorModel::chkJointForEditDelete(u32 jntNo) {
    return true;
}

u32 uDDOActorModel::getHitLightToModel() {
    return 4;
}

inline uDDOActorModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uDDOActorModel::MyDTI uDDOActorModel::DTI("uDDOActorModel", &::uActorModel::DTI, 9696ul, 0u, 0u);

__attribute__((weak)) MtObject* uDDOActorModel::MyDTI::newInstance() const {
    DDON_STUB("uDDOActorModel::MyDTI::newInstance")
    return nullptr;
}

