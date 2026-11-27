// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSkyWaterModel.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cDDMaterialCtrl.h"
#include "../../XFramework/cDraw.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/nDrawConstantTable.h"
#include "../../XFramework/nDrawMaterial.h"
#include "../../XFramework/nDrawScene.h"
#include "../../XFramework/nDrawTexture.h"
#include "../../XFramework/sRender.h"
#include "sRenderExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uScrModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSkyWaterModel::getDTI() const {
    return uSkyWaterModel::DTI;
}

uSkyWaterModel::uSkyWaterModel() {
    DDON_STUB("uSkyWaterModel::uSkyWaterModel")
    /* stub */
}

uSkyWaterModel::~uSkyWaterModel() {
    if (mpOrgDiffuseColor != nullptr) {
        MtMemoryAllocator::getAllocator(uSkyWaterModel::DTI)->memFree(static_cast<void*>(mpOrgDiffuseColor));
        mpOrgDiffuseColor = nullptr;
    }
    if (mpDDMaterialCtrl == nullptr) {
        return;
    }
    delete mpDDMaterialCtrl;
    mpDDMaterialCtrl = nullptr;
}

MtUI* uSkyWaterModel::createUI(MtProperty& prop) {
    return this->uBaseModel::createUI(prop);
}

void uSkyWaterModel::createProperty(MtPropertyList& s) {
    this->uScrBaseModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUseOriginalColor", &mUseOriginalColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseSkyColor", &mUseSkyColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSunColorHeight", &mSunColorHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSunColorScale", &mSunColorScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSaturationScale", &mSaturationScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIntensityScale", &mIntensityScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAmbColorHeight", &mAmbColorHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAmbColorScale", &mAmbColorScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDiffuseScale", &mDiffuseScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDiffuseScaleMin", &mDiffuseScaleMin, 0u, 0u);
}

__attribute__((weak)) void uSkyWaterModel::move() {
    DDON_STUB("uSkyWaterModel::move")
    /* stub */
}

void uSkyWaterModel::moveAfter() {
    this->uScrBaseModel::moveAfter();
    if (mMaterialNum != 0) {
        u32 v0_0 = mMaterialNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            cDDMaterialCtrl* t0 = mpDDMaterialCtrl;
            if (t0 == nullptr) {
                v1_0 = v0_0;
            } else {
                t0->setCommonState(getMaterial(i0_3), mpModel, i0_3);
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

bool uSkyWaterModel::isPrioAttrTransparency(cDraw* pDraw) {
    bool t0 = this->uBaseModel::isPrioAttrTransparency(pDraw);
    unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pDraw) + 560);
    bool t2 = static_cast<sRenderExt*>(sRender::getInstance())->isEnablePrioAttrExpand();
    if (t2) {
        return t0 || (!t0 && (((t1 & 31ul) ^ 16ul) == 0));
    } else {
        return t0;
    }
}

__attribute__((weak)) void uSkyWaterModel::draw(cDraw* pdraw) {
    DDON_STUB("uSkyWaterModel::draw")
    /* stub */
}

void uSkyWaterModel::setup() {
    this->uScrBaseModel::setup();
    sUnit::getInstance()->setUnitGroupBit(static_cast<cUnit*>(this), sUnitExt::GPT_SCR);
    cDDMaterialCtrl* t0 = mpDDMaterialCtrl;
    if (t0 == nullptr) {
        return;
    }
    t0->mpOwner = static_cast<uBaseModel*>(this);
    t0->init();
    mpDDMaterialCtrl->setMaterialMode(8u);
}

__attribute__((weak)) void uSkyWaterModel::setCommonState(cDraw* pdraw) {
    DDON_STUB("uSkyWaterModel::setCommonState")
    /* stub */
}

__attribute__((weak)) void uSkyWaterModel::setModel(rModel* pmod) {
    DDON_STUB("uSkyWaterModel::setModel")
    /* stub */
}

inline uSkyWaterModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSkyWaterModel::MyDTI uSkyWaterModel::DTI("uSkyWaterModel", &::uScrBaseModel::DTI, 4752ul, 0u, 0u);

__attribute__((weak)) MtObject* uSkyWaterModel::MyDTI::newInstance() const {
    DDON_STUB("uSkyWaterModel::MyDTI::newInstance")
    return nullptr;
}

