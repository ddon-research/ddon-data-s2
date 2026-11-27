// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSwing.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "nDrawResource.h"
#include "rSwingModel.h"
#include "rTexture.h"
#include "sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSwing::getDTI() const {
    return cSwing::DTI;
}

cSwing::cSwing() {
    mWindMask = 0xFFFFFFFF;
    mWindGroup = 1;
    mFrequencyFactor = 1.0f;
    mWeight = 1.0f;
}

cSwing::~cSwing() {
}

__attribute__((weak)) void cSwing::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mWindMask", reinterpret_cast<MT_MFUNC>(&::cSwing::getWindMask), reinterpret_cast<MT_MFUNC>(&::cSwing::setWindMask), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mWindGroup", reinterpret_cast<MT_MFUNC>(&::cSwing::getWindGroup), reinterpret_cast<MT_MFUNC>(&::cSwing::setWindGroup), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFrequencyFactor", &mFrequencyFactor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeight", &mWeight, 0u, 0u);
}

MtUI* cSwing::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

MtUI* cSwing::getUI(MtProperty& prop) {
    return nullptr;
}

void cSwing::applyWind(cDraw* p_draw, MtAABB& boundary, u32 max_wind) {
    sScene* t0 = sScene::mpInstance;
    u32 t1 = mWindMask;
    u32 t2 = mWindGroup;
    f32 t3 = getFrequencyFactor();
    f32 t4 = getWeight();
    t0->setWindState(p_draw, max_wind, boundary, t1, t2, t3, t4, getWeight());
}

void cSwing::setWindMask(u32 mask) {
    mWindMask = mask;
}

void cSwing::setWindGroup(u32 group) {
    mWindGroup = group;
}

u32 cSwing::getWindMask() const {
    return mWindMask;
}

u32 cSwing::getWindGroup() const {
    return mWindGroup;
}

f32 cSwing::getFrequencyFactor() const {
    return mFrequencyFactor;
}

f32 cSwing::getWeight() const {
    return mWeight;
}

inline cSwing::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSwing::MyDTI cSwing::DTI("cSwing", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cSwing::MyDTI::newInstance() const {
    return new (16u) cSwing;
}

const MtDTI& cSwingModel::getDTI() const {
    return cSwingModel::DTI;
}

cSwingModel::cSwingModel() {
    DDON_STUB("cSwingModel::cSwingModel")
    /* stub */
}

cSwingModel::~cSwingModel() {
    if (mpSwing != nullptr) {
        mpSwing->release();
        mpSwing = nullptr;
    }
    if (mpAfterSwing != nullptr) {
        mpAfterSwing->release();
        mpAfterSwing = nullptr;
    }
    if (mpDepthBiasTexture == nullptr) {
        return;
    }
    mpDepthBiasTexture->release();
    mpDepthBiasTexture = nullptr;
}

void cSwingModel::createProperty(MtPropertyList& s) {
    this->cSwing::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpSwing", "resource", reinterpret_cast<MT_MFUNC>(&::cSwingModel::getSwing), reinterpret_cast<MT_MFUNC>(&::cSwingModel::setSwing), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpAfterSwing", "resource", reinterpret_cast<MT_MFUNC>(&::cSwingModel::getAfterSwing), reinterpret_cast<MT_MFUNC>(&::cSwingModel::setAfterSwing), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mShadowDepthBias", &mShadowDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthBiasTexture", "resource", static_cast<void*>(&mpDepthBiasTexture), 0u, 0u);
}

MtUI* cSwingModel::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

MtUI* cSwingModel::getUI(MtProperty& prop) {
    return nullptr;
}

void cSwingModel::setDepthBias(f32 depth_bias) {
    mShadowDepthBias = depth_bias;
}

__attribute__((weak)) void cSwingModel::setDepthBiasTexture(rTexture* p_depth_bias_texture) {
    DDON_STUB("cSwingModel::setDepthBiasTexture")
    /* stub */
}

__attribute__((weak)) void cSwingModel::setSwing(rSwingModel* p_resource) {
    DDON_STUB("cSwingModel::setSwing")
    /* stub */
}

rSwingModel* cSwingModel::getSwing() {
    return mpSwing;
}

__attribute__((weak)) void cSwingModel::setAfterSwing(rSwingModel* p_resource) {
    DDON_STUB("cSwingModel::setAfterSwing")
    /* stub */
}

rSwingModel* cSwingModel::getAfterSwing() {
    return mpAfterSwing;
}

__attribute__((weak)) void cSwingModel::setup(cDraw* pdraw, const MtAABB& aabb) {
    DDON_STUB("cSwingModel::setup")
    /* stub */
}

void cSwingModel::initContext(cSwingModel::SWING_CONTEXT& context) {
    context.p_depth_bias_texture = nullptr;
    context.state[1].use_high_precision = false;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&context) + 73) = 0;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&context) + 77) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&context) + 79) = 0;
    context.state[1].current_base = 0;
    context.state[1].current_stride = 0;
    context.state[1].p_current_quant = nullptr;
    context.state[1].p_quant = nullptr;
    context.state[1].p_vb = nullptr;
    context.state[0].use_high_precision = false;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&context) + 33) = 0;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&context) + 37) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&context) + 39) = 0;
    context.state[0].current_base = 0;
    context.state[0].current_stride = 0;
    context.state[0].p_current_quant = nullptr;
    context.state[0].p_quant = nullptr;
    context.state[0].p_vb = nullptr;
    rSwingModel* p_swing = mpSwing;
    if (p_swing != nullptr) {
        context.state[0].p_vb = p_swing->mpVertexBuffer;
        context.state[0].p_quant = p_swing->mpPrimQuantInfo;
        context.state[0].use_high_precision = p_swing->mHighPrecisionMode;
        rSwingModel* p_after_swing = mpAfterSwing;
        if (p_after_swing != nullptr) {
            context.state[1].p_vb = p_after_swing->mpVertexBuffer;
            context.state[1].p_quant = p_after_swing->mpPrimQuantInfo;
            context.state[1].use_high_precision = p_after_swing->mHighPrecisionMode;
        }
    } else {
        rSwingModel* p_after_swing = mpAfterSwing;
        if (p_after_swing != nullptr) {
            context.state[1].p_vb = p_after_swing->mpVertexBuffer;
            context.state[1].p_quant = p_after_swing->mpPrimQuantInfo;
            context.state[1].use_high_precision = p_after_swing->mHighPrecisionMode;
        }
    }
}

void cSwingModel::updateQuant(cSwingModel::SWING_CONTEXT& context, u32 prim) {
    if (context.state[0].p_quant != nullptr) {
        context.state[0].p_current_quant = &context.state[0].p_quant[prim];
    } else {
        context.state[0].p_current_quant = nullptr;
    }
    if (context.state[1].p_quant != nullptr) {
        context.state[1].p_current_quant = &context.state[1].p_quant[prim];
    } else {
        context.state[1].p_current_quant = nullptr;
    }
}

__attribute__((weak)) void cSwingModel::apply(cDraw* p_draw, cSwingModel::SWING_CONTEXT& context) {
    DDON_STUB("cSwingModel::apply")
    /* stub */
}

__attribute__((weak)) void cSwingModel::applyWind(cDraw* p_draw, MtAABB& boundary, cSwingModel::SWING_CONTEXT& context) {
    DDON_STUB("cSwingModel::applyWind")
    /* stub */
}

__attribute__((weak)) f32 cSwingModel::getFrequencyFactor() const {
    DDON_STUB("cSwingModel::getFrequencyFactor")
    return {};
}

f32 cSwingModel::getWeight() const {
    return mWeight;
}

__attribute__((weak)) void cSwingModel::setBillboardEnable(cDraw* pdraw, bool use_billboard, bool rotation, bool fix_y_axis, bool default_swing) {
    DDON_STUB("cSwingModel::setBillboardEnable")
    /* stub */
}

__attribute__((weak)) void cSwingModel::setupBillboard(cDraw* pdraw) {
    DDON_STUB("cSwingModel::setupBillboard")
    /* stub */
}

inline cSwingModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSwingModel::MyDTI cSwingModel::DTI("cSwingModel", &::cSwing::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cSwingModel::MyDTI::newInstance() const {
    DDON_STUB("cSwingModel::MyDTI::newInstance")
    return nullptr;
}

