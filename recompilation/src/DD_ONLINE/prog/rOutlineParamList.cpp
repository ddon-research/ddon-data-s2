// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOutlineParamList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "cDDMaterialCtrl.h"
#include "../../XFramework/cResource.h"
#include "cpDDMrlMgr.h"
#include "nDDOUtility.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sWeatherManager.h"
#include "sWorkRate.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void cOutlineCtrl::request(sEffectExt::OUTLINE type) {
    if (type <= 39) {
        const cOutlineParam* pNew = static_cast<sEffectExt*>(sEffect::getInstance())->getOutlineParam(type);
        if (pNew != nullptr) {
            if (mpRequestParam != nullptr) {
                if (pNew->mPriority >= mpRequestParam->mPriority) {
                    mpRequestParam = pNew;
                }
            } else {
                mpRequestParam = pNew;
            }
        }
    }
}

__attribute__((weak)) void cOutlineCtrl::update(cpDDMrlMgr* pOwnerMrlMgr) {
    DDON_STUB("cOutlineCtrl::update")
    /* stub */
}

const MtDTI& cOutlineParam::getDTI() const {
    return cOutlineParam::DTI;
}

cOutlineParam::~cOutlineParam() {
    return;
}

void cOutlineParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrame", &mFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLoop", &mIsLoop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsOWAgain", &mIsOWAgain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndFrame", &mEndFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeatherRate", &mWeatherRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineBlendType", &mOutlineBlendType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineColorType", &mOutlineColorType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineOColor", static_cast<MtObject*>(&mOutlineOColor), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineIColor", static_cast<MtObject*>(&mOutlineIColor), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineBalanceOffset", &mOutlineBalanceOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineBalanceScale", &mOutlineBalanceScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutlineBalance", &mOutlineBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseShaderParam", &mIsUseShaderParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShaderMode", &mShaderMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShaderBlendRate", &mShaderBlendRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShaderBasePower", &mShaderBasePower, 0u, 0u);
}

inline cOutlineParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOutlineParam::MyDTI cOutlineParam::DTI("cOutlineParam", &::MtObject::DTI, 928ul, 0u, 0u);

__attribute__((weak)) MtObject* cOutlineParam::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cOutlineParam::DTI)->memAlloc(sizeof(cOutlineParam), 16u, cOutlineParam::DTI.getID())) cOutlineParam;
}

const MtDTI& rOutlineParamList::getDTI() const {
    return rOutlineParamList::DTI;
}

rOutlineParamList::~rOutlineParamList() {
    if (mParamList.mLength != 0) {
        u32 v0_0 = mParamList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mParamList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mParamList.mpArray[i0_3];
                v1_0 = mParamList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mParamList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamList.mpArray));
    }
    mParamList.mpArray = nullptr;
    mParamList.mBufsiz = 0;
    mParamList.mLength = 0;
}

void rOutlineParamList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mParamList", static_cast<MtObject*>(&mParamList), 0u, 0u);
}

__attribute__((weak)) void rOutlineParamList::clear() {
}

bool rOutlineParamList::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rOutlineParamList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rOutlineParamList::DTI));
}

MT_CTSTR rOutlineParamList::getExt() const {
    return "olp";
}

__attribute__((weak)) const cOutlineParam* const rOutlineParamList::getParam(sEffectExt::OUTLINE index) {
    DDON_STUB("rOutlineParamList::getParam")
    return nullptr;
}

inline rOutlineParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOutlineParamList::MyDTI rOutlineParamList::DTI("rOutlineParamList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rOutlineParamList::MyDTI::newInstance() const {
    return new (16u) rOutlineParamList;
}

