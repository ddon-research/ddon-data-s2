// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uLight.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cLightVolume.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawResource.h"
#include "rTexture.h"
#include "sRender.h"
#include "sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uLight::getDTI() const {
    return uLight::DTI;
}

uLight::~uLight() {
    (sScene::mpInstance)->sScene::detach(static_cast<cUnit*>(this));
    (sScene::mpInstance)->sScene::detachNode(mNode);
    if (mpProjectionTexture != nullptr) {
        mpProjectionTexture->release();
        mpProjectionTexture = nullptr;
    }
    if (mplightVolume == nullptr) {
        return;
    }
    delete mplightVolume;
    mplightVolume = nullptr;
}

__attribute__((weak)) void uLight::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAttr", reinterpret_cast<MT_MFUNC>(&::uLight::getAttr), reinterpret_cast<MT_MFUNC>(&::uLight::setAttr), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mPriority", reinterpret_cast<MT_MFUNC>(&::uLight::getPriority), reinterpret_cast<MT_MFUNC>(&::uLight::setPriority), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mColor", reinterpret_cast<MT_MFUNC>(&::uLight::getColor), reinterpret_cast<MT_MFUNC>(&::uLight::setColor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mApproximateDisable", reinterpret_cast<MT_MFUNC>(&::uLight::getApproximateDisable), reinterpret_cast<MT_MFUNC>(&::uLight::setApproximateDisable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMode", reinterpret_cast<s32*>(&mMode), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPS3Disable", reinterpret_cast<MT_MFUNC>(&::uLight::getPS3DisableMode), reinterpret_cast<MT_MFUNC>(&::uLight::setPS3DisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPS4Disable", reinterpret_cast<MT_MFUNC>(&::uLight::getPS4DisableMode), reinterpret_cast<MT_MFUNC>(&::uLight::setPS4DisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPCDisable", reinterpret_cast<MT_MFUNC>(&::uLight::getPCDisableMode), reinterpret_cast<MT_MFUNC>(&::uLight::setPCDisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uLight::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

u64 uLight::getSystemUnitGroup() const {
    return 4;
}

__attribute__((weak)) void uLight::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uLight::applyWorldOffset")
    /* stub */
}

void uLight::move() {
    mWbFlag = mWbFlag ^ 1u;
}

__attribute__((weak)) void uLight::moveAfter() {
    DDON_STUB("uLight::moveAfter")
    /* stub */
}

void uLight::draw(cDraw* pdraw) {
    if ((mUnitAttr & 16u) == 0) {
        return;
    }
    if (mplightVolume == nullptr) {
        return;
    }
    mplightVolume->draw(pdraw, this);
}

static auto ddon_emit_0x01b62b20 __attribute__((used)) = &uLight::getColor;

void uLight::setColor(const MtVector3& v) {
    mColor.x = v.x;
    mColor.y = v.y;
    mColor.z = v.z;
    mColor.pad_ = 0.0f;
}

bool uLight::getSHFactor(cDraw* pdraw, const MtSphere& sphere, uLight::SHFACTOR* pfactor) const {
    return false;
}

__attribute__((weak)) void uLight::setState(cDraw* pdraw, u32 slot, bool approx_enable) {
    DDON_STUB("uLight::setState")
    /* stub */
}

static auto ddon_emit_0x01b62b80 __attribute__((used)) = &uLight::getApproximateDisable;

static auto ddon_emit_0x01b62b90 __attribute__((used)) = &uLight::setApproximateDisable;

static auto ddon_emit_0x01b62ae0 __attribute__((used)) = &uLight::getAttr;

void uLight::setAttr(u32 attr) {
    if (mType == 0) {
        mAttr = attr & 247u;
    } else {
        mAttr = attr;
    }
}

static auto ddon_emit_0x01b62af0 __attribute__((used)) = &uLight::getPriority;

static auto ddon_emit_0x01b62b00 __attribute__((used)) = &uLight::setPriority;

bool uLight::getBoundary(MtSphere* pdst) {
    if ((mBound & 1u) != 0) {
        pdst->pos.x = mBoundingSphere.pos.x;
        pdst->pos.y = mBoundingSphere.pos.y;
        pdst->pos.z = mBoundingSphere.pos.z;
        pdst->r = mBoundingSphere.r;
        return true;
    } else {
        return false;
    }
}

bool uLight::isLimitRangeEnable() const {
    return static_cast<bool>(mAttr >> 7);
}

void uLight::setLimitRangeEnable(bool enable) {
    mAttr = !enable ? ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 72)) & 127u) : (((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 72)) & 127u) + 128u);
}

bool uLight::getLimitRangeOBB(MtOBB* obb) const {
    return false;
}

__attribute__((weak)) void uLight::getDrawUnitState(u32& type, u32& priority) const {
    DDON_STUB("uLight::getDrawUnitState")
    /* stub */
}

__attribute__((weak)) cUnit::cHardwareDispCtrl* uLight::createHardwareDispCtrl() {
    DDON_STUB("uLight::createHardwareDispCtrl")
    return nullptr;
}

void uLight::setPS3DisableMode(bool set) {
    mIsPS3Disable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 1u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFEu;
    }
}

void uLight::setPS4DisableMode(bool set) {
    mIsPS4Disable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 2u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFDu;
    }
}

void uLight::setPCDisableMode(bool set) {
    mIsPCDisable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 4u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFBu;
    }
}

static auto ddon_emit_0x01b62bb0 __attribute__((used)) = &uLight::getPS3DisableMode;

static auto ddon_emit_0x01b62bc0 __attribute__((used)) = &uLight::getPS4DisableMode;

static auto ddon_emit_0x01b62bd0 __attribute__((used)) = &uLight::getPCDisableMode;

inline uLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uLight::MyDTI uLight::DTI("uLight", &::cUnit::DTI, 992ul, 0u, 1u);

MtObject* uLight::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uLight::cHardwareDispCtrlLight::getDTI() const {
    return uLight::cHardwareDispCtrlLight::DTI;
}

void* uLight::cHardwareDispCtrlLight::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uLight::cHardwareDispCtrlLight::DTI)->memAlloc(sz, align, uLight::cHardwareDispCtrlLight::DTI.mID);
}

void uLight::cHardwareDispCtrlLight::update() {
    bool t0 = (sScene::mpInstance)->mLightRestrictPS4;
    bool t1 = (sScene::mpInstance)->mLightRestrictPC;
    if ((sScene::mpInstance)->mLightRestrictPS3) {
        mHard = 0;
    }
    if (t0) {
        mHard = 1;
    }
    if (t1) {
        mHard = 2;
    }
    this->cUnit::cHardwareDispCtrl::update();
}

inline uLight::cHardwareDispCtrlLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uLight::cHardwareDispCtrlLight::MyDTI uLight::cHardwareDispCtrlLight::DTI("uLight::cHardwareDispCtrlLight", &::cUnit::cHardwareDispCtrl::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* uLight::cHardwareDispCtrlLight::MyDTI::newInstance() const {
    DDON_STUB("uLight::cHardwareDispCtrlLight::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uPointLight::usage() {
}

const MtDTI& uPointLight::getDTI() const {
    return uPointLight::DTI;
}

uPointLight::uPointLight() {
    DDON_STUB("uPointLight::uPointLight")
    /* stub */
}

uPointLight::~uPointLight() {
}

__attribute__((weak)) void uPointLight::moveAfter() {
    DDON_STUB("uPointLight::moveAfter")
    /* stub */
}

void uPointLight::createProperty(MtPropertyList& s) {
    this->uLight::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup0", &mShadowAtten.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup1", &mShadowAtten.y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStart", &mStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnd", &mEnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpProjectionTexture", "resource", static_cast<void*>(&mpProjectionTexture), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mProjectionAngle", &mProjectionAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LimitRangeEnable", reinterpret_cast<MT_MFUNC>(&::uLight::isLimitRangeEnable), reinterpret_cast<MT_MFUNC>(&::uLight::setLimitRangeEnable), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB", &mRangeOBB, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB.extent", &mRangeOBB.extent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB.coord", &mRangeOBB.coord, 0u, 0u);
}

MtUI* uPointLight::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uPointLight::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uPointLight::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) bool uPointLight::getSHFactor(cDraw* pdraw, const MtSphere& sphere, uLight::SHFACTOR* pfactor) const {
    DDON_STUB("uPointLight::getSHFactor")
    return {};
}

bool uPointLight::getLimitRangeOBB(MtOBB* obb) const {
    if ((mAttr & 128u) != 0) {
        if (obb != nullptr) {
            obb->extent.x = mRangeOBB.extent.x;
            obb->extent.y = mRangeOBB.extent.y;
            obb->extent.z = mRangeOBB.extent.z;
            obb->extent.pad_ = 0.0f;
            obb->coord.m[0].x = mRangeOBB.coord.m[0].x;
            obb->coord.m[0].y = mRangeOBB.coord.m[0].y;
            obb->coord.m[0].z = mRangeOBB.coord.m[0].z;
            obb->coord.m[0].w = mRangeOBB.coord.m[0].w;
            obb->coord.m[1].x = mRangeOBB.coord.m[1].x;
            obb->coord.m[1].y = mRangeOBB.coord.m[1].y;
            obb->coord.m[1].z = mRangeOBB.coord.m[1].z;
            obb->coord.m[1].w = mRangeOBB.coord.m[1].w;
            obb->coord.m[2].x = mRangeOBB.coord.m[2].x;
            obb->coord.m[2].y = mRangeOBB.coord.m[2].y;
            obb->coord.m[2].z = mRangeOBB.coord.m[2].z;
            obb->coord.m[2].w = mRangeOBB.coord.m[2].w;
            obb->coord.m[3].x = mRangeOBB.coord.m[3].x;
            obb->coord.m[3].y = mRangeOBB.coord.m[3].y;
            obb->coord.m[3].z = mRangeOBB.coord.m[3].z;
            obb->coord.m[3].w = mRangeOBB.coord.m[3].w;
            return true;
        }
    }
    return false;
}

void uPointLight::setLimitRangeOBB(const MtOBB& obb) {
    mRangeOBB.extent.x = obb.extent.x;
    mRangeOBB.extent.y = obb.extent.y;
    mRangeOBB.extent.z = obb.extent.z;
    mRangeOBB.extent.pad_ = 0.0f;
    mRangeOBB.coord.m[0].x = obb.coord.m[0].x;
    mRangeOBB.coord.m[0].y = obb.coord.m[0].y;
    mRangeOBB.coord.m[0].z = obb.coord.m[0].z;
    mRangeOBB.coord.m[0].w = obb.coord.m[0].w;
    mRangeOBB.coord.m[1].x = obb.coord.m[1].x;
    mRangeOBB.coord.m[1].y = obb.coord.m[1].y;
    mRangeOBB.coord.m[1].z = obb.coord.m[1].z;
    mRangeOBB.coord.m[1].w = obb.coord.m[1].w;
    mRangeOBB.coord.m[2].x = obb.coord.m[2].x;
    mRangeOBB.coord.m[2].y = obb.coord.m[2].y;
    mRangeOBB.coord.m[2].z = obb.coord.m[2].z;
    mRangeOBB.coord.m[2].w = obb.coord.m[2].w;
    mRangeOBB.coord.m[3].x = obb.coord.m[3].x;
    mRangeOBB.coord.m[3].y = obb.coord.m[3].y;
    mRangeOBB.coord.m[3].z = obb.coord.m[3].z;
    mRangeOBB.coord.m[3].w = obb.coord.m[3].w;
}

inline uPointLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uPointLight::MyDTI uPointLight::DTI("uPointLight", &::uLight::DTI, 1152ul, 0u, 0u);

__attribute__((weak)) MtObject* uPointLight::MyDTI::newInstance() const {
    DDON_STUB("uPointLight::MyDTI::newInstance")
    return nullptr;
}

