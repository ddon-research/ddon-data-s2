// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uBaseModel.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawMaterial.h"
#include "nDrawMaterialNull.h"
#include "nDrawResource.h"
#include "rMaterial.h"
#include "rModel.h"
#include "sCamera.h"
#include "sMain.h"
#include "sRender.h"
#include "sScene.h"
#include "uCoord.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uBaseModel::usage() {
}

const MtDTI& uBaseModel::getDTI() const {
    return uBaseModel::DTI;
}

void* uBaseModel::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uBaseModel::DTI)->memAlloc(sz, align, uBaseModel::DTI.mID);
}

uBaseModel::uBaseModel() {
    DDON_STUB("uBaseModel::uBaseModel")
    /* stub */
}

__attribute__((noinline)) uBaseModel::~uBaseModel() {
    DDON_STUB("uBaseModel::~uBaseModel")
    /* stub */
}

MT_CTSTR uBaseModel::getName() {
    rModel* v0_0 = mpModel;
    unsigned int i0_1;
    int v0_3;
    if (v0_0 == nullptr) {
        return this->cUnit::getName();
    } else {
        i0_1 = 0;
        v0_3 = 0;
    }
    for (;;) {
        if (v0_0->mPath[i0_1] == 0) {
            break;
        } else {
            if (v0_0->mPath[i0_1] == 92) {
                v0_3 = static_cast<int>(i0_1 + 1u);
            }
            i0_1 = i0_1 + 1u;
        }
    }
    return &v0_0->mPath[v0_3];
}

u64 uBaseModel::getSystemUnitGroup() const {
    return 32;
}

void uBaseModel::move() {
    updateViewDraw();
    updateLocalMatrix();
    updateWorldMatrix();
    updateCommandCacheLevel();
}

__attribute__((weak)) void uBaseModel::setup() {
    DDON_STUB("uBaseModel::setup")
    /* stub */
}

void uBaseModel::moveAfter() {
    if (mpModel != nullptr) {
        if (mMaterialNum != 0) {
            u32 v0_0 = mMaterialNum;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mpMaterials[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    mpMaterials[i0_3]->update(mDeltaTime);
                    bool t0 = mpMaterials[i0_3]->nDraw::Material::isCBuffer();
                    mMaterialCBuffer = static_cast<u32>(static_cast<unsigned long>(mMaterialCBuffer) | static_cast<unsigned long>(t0));
                    v1_0 = mMaterialNum;
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
}

__attribute__((weak)) void uBaseModel::draw(cDraw* pdraw) {
    DDON_STUB("uBaseModel::draw")
    /* stub */
}

__attribute__((weak)) void uBaseModel::cancelState(cDraw* pdraw) {
    DDON_STUB("uBaseModel::cancelState")
    /* stub */
}

__attribute__((weak)) void uBaseModel::createProperty(MtPropertyList& s) {
    DDON_STUB("uBaseModel::createProperty")
    /* stub */
}

MtUI* uBaseModel::createUI(MtProperty& prop) {
    return this->uCoord::createUI(prop);
}

__attribute__((weak)) void uBaseModel::setModel(rModel* pmod) {
    DDON_STUB("uBaseModel::setModel")
    /* stub */
}

static auto ddon_emit_0x01b5d290 __attribute__((used)) = &uBaseModel::getModel;

__attribute__((weak)) void uBaseModel::setMaterialData(rMaterial* pmat) {
    DDON_STUB("uBaseModel::setMaterialData")
    /* stub */
}

static auto ddon_emit_0x01b5d2a0 __attribute__((used)) = &uBaseModel::getMaterialData;

__attribute__((weak)) void uBaseModel::updateWorldMatrix() {
    DDON_STUB("uBaseModel::updateWorldMatrix")
    /* stub */
}

__attribute__((weak)) void uBaseModel::updateBoundary() {
    DDON_STUB("uBaseModel::updateBoundary")
    /* stub */
}

bool uBaseModel::getBoundary(MtSphere* pdst) {
    if (mpModel != nullptr) {
        pdst->pos.x = mBoundingSphere.pos.x;
        pdst->pos.y = mBoundingSphere.pos.y;
        pdst->pos.z = mBoundingSphere.pos.z;
        pdst->r = mBoundingSphere.r;
        return true;
    } else {
        return false;
    }
}

bool uBaseModel::isPartsDisp(u32 no) const {
    return ((static_cast<unsigned long>(mPartsDisp[no >> 5]) >> static_cast<unsigned long>(no & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uBaseModel::setPartsDisp(bool disp, u32 no) {
    DDON_STUB("uBaseModel::setPartsDisp")
    /* stub */
}

void uBaseModel::setPartsDispAll(bool disp) {
    if (disp) {
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
    } else {
        mPartsDisp[14] = 0;
        mPartsDisp[15] = 0;
        mPartsDisp[12] = 0;
        mPartsDisp[13] = 0;
        mPartsDisp[10] = 0;
        mPartsDisp[11] = 0;
        mPartsDisp[8] = 0;
        mPartsDisp[9] = 0;
        mPartsDisp[6] = 0;
        mPartsDisp[7] = 0;
        mPartsDisp[4] = 0;
        mPartsDisp[5] = 0;
        mPartsDisp[2] = 0;
        mPartsDisp[3] = 0;
        mPartsDisp[0] = 0;
        mPartsDisp[1] = 0;
    }
}

static auto ddon_emit_0x01b5d4e0 __attribute__((used)) = &uBaseModel::setVFCullLevel;

__attribute__((weak)) uBaseModel::VFCULL_LEVEL uBaseModel::getVFCullLevel() const {
    DDON_STUB("uBaseModel::getVFCullLevel")
    return {};
}

static auto ddon_emit_0x01b5d550 __attribute__((used)) = &uBaseModel::getZPrepassDist;

static auto ddon_emit_0x01b5d560 __attribute__((used)) = &uBaseModel::setZPrepassDist;

static auto ddon_emit_0x01b5d570 __attribute__((used)) = &uBaseModel::getDrawPriority;

__attribute__((weak)) bool uBaseModel::isPrioAttrTransparency(cDraw* pDraw) {
    DDON_STUB("uBaseModel::isPrioAttrTransparency")
    return {};
}

u32 uBaseModel::getAddTransparentDrawPriority() {
    return 0;
}

static auto ddon_emit_0x01b5d580 __attribute__((used)) = &uBaseModel::setDrawPriority;

static auto ddon_emit_0x01b5d590 __attribute__((used)) = &uBaseModel::getPriorityBias;

static auto ddon_emit_0x01b5d5a0 __attribute__((used)) = &uBaseModel::setPriorityBias;

static auto ddon_emit_0x01b5d510 __attribute__((used)) = &uBaseModel::getLODType;

static auto ddon_emit_0x01b5d520 __attribute__((used)) = &uBaseModel::setLODType;

static auto ddon_emit_0x01b5d5d0 __attribute__((used)) = &uBaseModel::getShaderQuality;

static auto ddon_emit_0x01b5d5e0 __attribute__((used)) = &uBaseModel::setShaderQuality;

static auto ddon_emit_0x01b5d730 __attribute__((used)) = &uBaseModel::getMaterialNum;

nDraw::Material* uBaseModel::getMaterial(u32 index) {
    return mpMaterials[index];
}

__attribute__((weak)) void uBaseModel::resetMaterial(u32 index) {
    DDON_STUB("uBaseModel::resetMaterial")
    /* stub */
}

void uBaseModel::resetAllMaterial() {
    u32 i = 0;
    if (mMaterialNum != 0) {
        do {
            resetMaterial(i);
            i += 1u;
        } while (i < mMaterialNum);
    }
}

__attribute__((weak)) void uBaseModel::setMaterial(nDraw::Material* pmaterial, u32 index) {
    DDON_STUB("uBaseModel::setMaterial")
    /* stub */
}

static auto ddon_emit_0x01b5d260 __attribute__((used)) = &uBaseModel::setDissolveEnable;

static auto ddon_emit_0x01b5d650 __attribute__((used)) = &uBaseModel::getDissolveEnable;

static auto ddon_emit_0x01b5d670 __attribute__((used)) = &uBaseModel::setFixPosition;

static auto ddon_emit_0x01b5d660 __attribute__((used)) = &uBaseModel::isFixPosition;

static auto ddon_emit_0x01b5d6b0 __attribute__((used)) = &uBaseModel::setShaderAttributes;

static auto ddon_emit_0x01b5d6a0 __attribute__((used)) = &uBaseModel::isShaderAttributes;

static auto ddon_emit_0x01b5d620 __attribute__((used)) = &uBaseModel::setFlatTransparency;

static auto ddon_emit_0x01b5d610 __attribute__((used)) = &uBaseModel::isFlatTransparency;

__attribute__((weak)) void uBaseModel::clearCommandCache() {
    DDON_STUB("uBaseModel::clearCommandCache")
    /* stub */
}

static auto ddon_emit_0x01b5d6e0 __attribute__((used)) = &uBaseModel::getCacheMode;

__attribute__((weak)) void uBaseModel::setCacheMode(uBaseModel::CACHE_MODE v) {
    DDON_STUB("uBaseModel::setCacheMode")
    /* stub */
}

static auto ddon_emit_0x01b5d3d0 __attribute__((used)) = &uBaseModel::setLightAttr;

static auto ddon_emit_0x01b5d3c0 __attribute__((used)) = &uBaseModel::getLightAttr;

void uBaseModel::setMaxLightNum(u32 n) {
    mMaxLightNum = n;
}

static auto ddon_emit_0x01b5d3f0 __attribute__((used)) = &uBaseModel::getMaxLightNum;

__attribute__((weak)) s32 uBaseModel::setupShadow(cDraw* pdraw) {
    DDON_STUB("uBaseModel::setupShadow")
    return {};
}

static auto ddon_emit_0x01b5d440 __attribute__((used)) = &uBaseModel::setMultiShadowReceive;

static auto ddon_emit_0x01b5d430 __attribute__((used)) = &uBaseModel::isMultiShadowReceive;

static auto ddon_emit_0x01b5d470 __attribute__((used)) = &uBaseModel::setMaxNumGroup0MultiShadowReceive;

static auto ddon_emit_0x01b5d460 __attribute__((used)) = &uBaseModel::getMaxNumGroup0MultiShadowReceive;

static auto ddon_emit_0x01b5d4a0 __attribute__((used)) = &uBaseModel::setMaxNumGroup1MultiShadowReceive;

static auto ddon_emit_0x01b5d490 __attribute__((used)) = &uBaseModel::getMaxNumGroup1MultiShadowReceive;

u32 uBaseModel::getDebugFlags() const {
    return static_cast<signed char>((*reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(this) + 312)) >> 45);
}

static auto ddon_emit_0x01b5d700 __attribute__((used)) = &uBaseModel::setDebugFlags;

static auto ddon_emit_0x01b5d2b0 __attribute__((used)) = &uBaseModel::getViewDraw;

__attribute__((weak)) void uBaseModel::setCommonState(cDraw* pdraw) {
    DDON_STUB("uBaseModel::setCommonState")
    /* stub */
}

__attribute__((weak)) void uBaseModel::drawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask) {
    DDON_STUB("uBaseModel::drawModel")
    /* stub */
}

__attribute__((weak)) void uBaseModel::setPrimState(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp) {
    DDON_STUB("uBaseModel::setPrimState")
    /* stub */
}

__attribute__((weak)) void uBaseModel::cullingCommandCache(cDraw* pdraw, nDraw::CommandCache* pcache, rModel* pmod, s32 basecullmask, u32 lod) {
    DDON_STUB("uBaseModel::cullingCommandCache")
    /* stub */
}

__attribute__((weak)) MtVector3 uBaseModel::calcBaseCenterPos() {
    DDON_STUB("uBaseModel::calcBaseCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) s32 uBaseModel::cullingModel(cDraw* pdraw) {
    DDON_STUB("uBaseModel::cullingModel")
    return {};
}

__attribute__((weak)) s32 uBaseModel::cullingNonSkin(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, s32 basecullmask) {
    DDON_STUB("uBaseModel::cullingNonSkin")
    return {};
}

u32 uBaseModel::getLODLevel(s32 dist) {
    if (mLODType <= -1) {
        if (static_cast<float>(dist) > mLODLowDist) {
            return 4;
        } else {
            if (static_cast<float>(dist) > mLODMidDist) {
                return 2;
            } else {
                return 1;
            }
        }
    } else {
        return static_cast<u32>(mLODType);
    }
}

__attribute__((weak)) void uBaseModel::updateViewDraw() {
    DDON_STUB("uBaseModel::updateViewDraw")
    /* stub */
}

u32 uBaseModel::getPartsNum() {
    return 512;
}

__attribute__((weak)) void uBaseModel::setPartsNum(u32) {
}

__attribute__((weak)) void uBaseModel::setMaterialNum(u32) {
}

u32 uBaseModel::getUseCommandCacheNum() {
    return mUseCacheNum;
}

u32 uBaseModel::getUseMaxCommandCacheNum() {
    return mMsxUseCacheNum;
}

__attribute__((weak)) uBaseModel::CACHE_TYPE uBaseModel::getCommandCache(cDraw* pdraw) {
    DDON_STUB("uBaseModel::getCommandCache")
    return {};
}

__attribute__((weak)) void uBaseModel::updateCommandCacheLevel() {
    DDON_STUB("uBaseModel::updateCommandCacheLevel")
    /* stub */
}

u32 uBaseModel::getHitLightToModel() {
    return 4;
}

inline uBaseModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uBaseModel::MyDTI uBaseModel::DTI("uBaseModel", &::uCoord::DTI, 4528ul, 0u, 0u);

__attribute__((weak)) MtObject* uBaseModel::MyDTI::newInstance() const {
    DDON_STUB("uBaseModel::MyDTI::newInstance")
    return nullptr;
}

