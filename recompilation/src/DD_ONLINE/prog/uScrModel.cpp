// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScrModel.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cDraw.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/cZoneLayout.h"
#include "cZoneUnitCtrl.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uScrBaseModel::getDTI() const {
    return uScrBaseModel::DTI;
}

uScrBaseModel::uScrBaseModel() {
    mDisableZone = false;
    mOffsetPos = MtVector3::Zero;
    mMoveSkip = false;
}

uScrBaseModel::~uScrBaseModel() {
}

__attribute__((weak)) void uScrBaseModel::setup() {
    DDON_STUB("uScrBaseModel::setup")
    /* stub */
}

void uScrBaseModel::createProperty(MtPropertyList& s) {
    this->uBaseModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableZone", &mDisableZone, 0u, 0u);
    mZoneUnitCtrl.cZoneUnitCtrl::createPropertyForScrlModel(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mOffsetPos", reinterpret_cast<MT_MFUNC>(&::uScrBaseModel::getOffsetPos), reinterpret_cast<MT_MFUNC>(&::uScrBaseModel::setOffsetPos), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void uScrBaseModel::move() {
    DDON_STUB("uScrBaseModel::move")
    /* stub */
}

void uScrBaseModel::moveAfter() {
    if (mMoveSkip) {
        return;
    }
    this->uBaseModel::moveAfter();
    if (!mDisableZone) {
        return;
    }
    if (getDTI().getID() != uScrBaseModel::DTI.mID) {
        return;
    }
    mMoveSkip = true;
}

void uScrBaseModel::draw(cDraw* pDraw) {
    if (!isPossibleDrawFromDrawBuffer()) {
        return;
    }
    this->uBaseModel::draw(pDraw);
}

__attribute__((weak)) void uScrBaseModel::setCommonState(cDraw* pDraw) {
    DDON_STUB("uScrBaseModel::setCommonState")
    /* stub */
}

void uScrBaseModel::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uCoord::applyWorldOffset(offset, absolute_offset);
    mMoveSkip = false;
}

u32 uScrBaseModel::getHitLightToModel() {
    return 4;
}

void uScrBaseModel::resetZoneUnitCtrl(u32 zoneHandle) {
    mZoneUnitCtrl.initZoneUnitCtrlStg(zoneHandle, 1u);
}

static auto ddon_emit_0x01b0a770 __attribute__((used)) = &uScrBaseModel::getOffsetPos;

void uScrBaseModel::setOffsetPos(const MtVector3& ofs) {
    mOffsetPos = ofs;
    mMoveSkip = false;
}

u32 uScrBaseModel::getLODLevel(s32 dist) {
    if (mLODType <= -1) {
        if (static_cast<float>(dist) > (mLODLowDist * 3.0f)) {
            return 4;
        } else {
            return static_cast<u32>((static_cast<float>(dist) > (mLODMidDist * 3.0f)) + 1);
        }
    } else {
        return static_cast<u32>(mLODType);
    }
}

void uScrBaseModel::callbackChangeVisibleTrueToFalse() {
    clearCommandCache();
}

inline uScrBaseModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrBaseModel::MyDTI uScrBaseModel::DTI("uScrBaseModel", &::uBaseModel::DTI, 4592ul, 0u, 0u);

MtObject* uScrBaseModel::MyDTI::newInstance() const {
    return new (16u) uScrBaseModel;
}

