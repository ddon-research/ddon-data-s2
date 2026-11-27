// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uDDOActorModelPl.h"
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
#include "cEditParam.h"
#include "cEquipData.h"
#include "cItemParam.h"
#include "cPlayerLoadManager.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpBakeJoint.h"
#include "cpBakeJointHuman.h"
#include "cpCharacterEdit.h"
#include "cpComponent.h"
#include "cpEquip.h"
#include "cpJointEx2.h"
#include "cpJointOrder.h"
#include "cpMotionFilter.h"
#include "cpRootComponent.h"
#include "cpTinyChain.h"
#include "nCharacterData.h"
#include "../../XFramework/nDrawMaterial.h"
#include "rArchiveListArray.h"
#include "rCharacterEdit.h"
#include "rItemList.h"
#include "rJointOrder.h"
#include "rNpcEditData.h"
#include "rNpcLedgerList.h"
#include "sArchiveManager.h"
#include "sContextManager.h"
#include "sEventManager.h"
#include "sItemManager.h"
#include "sNpcManager.h"
#include "sPlayerManager.h"
#include "uArmor.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOActorModel.h"
#include "../../XFramework/uFullbodyIKHuman2.h"
#include "../../XFramework/uModel.h"
#include "uWeapon.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uDDOActorModelPl::getDTI() const {
    return uDDOActorModelPl::DTI;
}

uDDOActorModelPl::uDDOActorModelPl() {
    DDON_STUB("uDDOActorModelPl::uDDOActorModelPl")
    /* stub */
}

uDDOActorModelPl::~uDDOActorModelPl() {
    if (mpFBIK != nullptr) {
        delete mpFBIK;
        mpFBIK = nullptr;
    }
    if (mpNpcEquipRes == nullptr) {
        return;
    }
    mpNpcEquipRes->release();
    mpNpcEquipRes = nullptr;
}

__attribute__((weak)) void uDDOActorModelPl::setup() {
    DDON_STUB("uDDOActorModelPl::setup")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::move() {
    DDON_STUB("uDDOActorModelPl::move")
    /* stub */
}

void uDDOActorModelPl::moveAfter() {
    this->uDDOActorModel::moveAfter();
}

void uDDOActorModelPl::draw(cDraw* pDraw) {
    if (!mEnable) {
        return;
    }
    if (mpBakeJoint != nullptr) {
        if (mpBakeJoint->isBaked()) {
            if (mpBakeJoint != nullptr) {
                if (1.0f > mTransparency) {
                    mDissolveEnable = 1;
                } else {
                    mDissolveEnable = 0;
                }
                mpBakeJoint->drawBake(pDraw);
            } else {
                this->uDDOActorModel::draw(pDraw);
            }
        } else {
            this->uDDOActorModel::draw(pDraw);
        }
    } else {
        this->uDDOActorModel::draw(pDraw);
    }
}

__attribute__((weak)) void uDDOActorModelPl::createComponent() {
    DDON_STUB("uDDOActorModelPl::createComponent")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::initCharacterEdit() {
    DDON_STUB("uDDOActorModelPl::initCharacterEdit")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::initWeapon() {
    DDON_STUB("uDDOActorModelPl::initWeapon")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::initEquip() {
    DDON_STUB("uDDOActorModelPl::initEquip")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::createGunUnit() {
    DDON_STUB("uDDOActorModelPl::createGunUnit")
    /* stub */
}

__attribute__((weak)) s32 uDDOActorModelPl::getArmorIndex(nCharacterData::EQUIP_SLOT_TYPE category) {
    DDON_STUB("uDDOActorModelPl::getArmorIndex")
    return {};
}

bool uDDOActorModelPl::isOkMrlCtrl() {
    cpCharacterEdit* pedit = static_cast<cpCharacterEdit*>(mComponentMgr.getRootComponent()->find(cpCharacterEdit::DTI, true, true));
    if (pedit != nullptr) {
        if (pedit->isLoading()) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void uDDOActorModelPl::createProperty(MtPropertyList& s) {
    this->uDDOActorModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEnable", &mEnable, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitType", &mUnitType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitNo", &mUnitNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsMyPlayer", &mIsMyPlayer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPlayerNo", &mPlayerNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeaponHold", &mWeaponHold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeaponCategory", &mWeaponCategory, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWpnDispOff", &mWpnDispOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBakeJointType", &mBakeJointType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCharacterEdit", reinterpret_cast<MtObject* *>(&mpCharacterEdit), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpFBIK", reinterpret_cast<MtObject* *>(&mpFBIK), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NpcEquip", "resource", reinterpret_cast<MT_MFUNC>(&::uDDOActorModelPl::getNpcEquipRes), reinterpret_cast<MT_MFUNC>(&::uDDOActorModelPl::setNpcEquipRes), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAlbedoCtrl", static_cast<MtObject*>(&mAlbedoCtrl[0]), 32u, 24u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlbedoBlendCtrl", static_cast<MtObject*>(&mAlbedoBlendCtrl[0]), 32u, 24u);
    s << MtProperty(static_cast<MtObject*>(this), "mEmissionCtrl", static_cast<MtObject*>(&mEmissionCtrl[0]), 32u, 24u);
}

__attribute__((weak)) void uDDOActorModelPl::setCommonState(cDraw* pdraw) {
    DDON_STUB("uDDOActorModelPl::setCommonState")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::updateWorldMatrix() {
    DDON_STUB("uDDOActorModelPl::updateWorldMatrix")
    /* stub */
}

void uDDOActorModelPl::calcWMat(uModel::Joint* pwk) {
    this->uModel::calcWMat(pwk);
}

void uDDOActorModelPl::calcWMatScaleInherit(uModel::Joint* pwk) {
    this->uModel::calcWMatScaleInherit(pwk);
}

void uDDOActorModelPl::calcWMatScaleGlobal(uModel::Joint* pwk) {
    this->uModel::calcWMatScaleGlobal(pwk);
}

void uDDOActorModelPl::calcWMatNoScale(uModel::Joint* pwk) {
    this->uModel::calcWMatNoScale(pwk);
}

__attribute__((weak)) void uDDOActorModelPl::updateJointWorldMatrixEx(const u8* jointTable, const u32 jointNum, const u32 updateWorldMode) {
    DDON_STUB("uDDOActorModelPl::updateJointWorldMatrixEx")
    /* stub */
}

__attribute__((weak)) void uDDOActorModelPl::setWeaponDisp(uWeapon* pWpn) {
    DDON_STUB("uDDOActorModelPl::setWeaponDisp")
    /* stub */
}

rNpcEditData* uDDOActorModelPl::getNpcEquipRes() const {
    return mpNpcEquipRes;
}

void uDDOActorModelPl::setNpcEquipRes(rNpcEditData* pRes) {
    if (pRes == mpNpcEquipRes) {
        return;
    }
    if (mpNpcEquipRes != nullptr) {
        mpNpcEquipRes->release();
        mpNpcEquipRes = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    mpNpcEquipRes = pRes;
    pRes->addRef();
    initWeapon();
    initEquip();
}

inline uDDOActorModelPl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uDDOActorModelPl::MyDTI uDDOActorModelPl::DTI("uDDOActorModelPl", &::uDDOActorModel::DTI, 12144ul, 0u, 0u);

__attribute__((weak)) MtObject* uDDOActorModelPl::MyDTI::newInstance() const {
    DDON_STUB("uDDOActorModelPl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uDDOActorModelPl::cColorCtrl::getDTI() const {
    return uDDOActorModelPl::cColorCtrl::DTI;
}

void uDDOActorModelPl::cColorCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "MaterialID", &mMatNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Color", &mColor, 0u, 0u);
}

inline uDDOActorModelPl::cColorCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uDDOActorModelPl::cColorCtrl::MyDTI uDDOActorModelPl::cColorCtrl::DTI("uDDOActorModelPl::cColorCtrl", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* uDDOActorModelPl::cColorCtrl::MyDTI::newInstance() const {
    DDON_STUB("uDDOActorModelPl::cColorCtrl::MyDTI::newInstance")
    return nullptr;
}

