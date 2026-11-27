// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rSoundAttributeSe.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundAttributeSe::getDTI() const {
    return rSoundAttributeSe::DTI;
}

rSoundAttributeSe::~rSoundAttributeSe() {
    if (mpAttributeSeData == nullptr) {
        return;
    }
    delete[] mpAttributeSeData;
    mpAttributeSeData = nullptr;
}

MT_CTSTR rSoundAttributeSe::getExt() const {
    return "aser";
}

void rSoundAttributeSe::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAttributeSeDataNum", &mAttributeSeDataNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpAttributeSeData", reinterpret_cast<MT_MFUNC>(&::rSoundAttributeSe::getAttributeSeData), reinterpret_cast<MT_MFUNC>(&::rSoundAttributeSe::setAttributeSeDataList), 1184u, reinterpret_cast<MT_MFUNC>(&::rSoundAttributeSe::getAttributeSeDataNum), reinterpret_cast<MT_MFUNC>(&::rSoundAttributeSe::createAttributeSeDataForProperty));
}

bool rSoundAttributeSe::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(3), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rSoundAttributeSe::save(MtStream& out) {
    return true;
}

s32 rSoundAttributeSe::getAttributeSeDataNum() {
    return mAttributeSeDataNum;
}

rSoundAttributeSe::cSoundAttributeSeData* rSoundAttributeSe::getAttributeSeData(s32 index) {
    if (mpAttributeSeData != nullptr) {
        if (index > -1) {
            if (index < mAttributeSeDataNum) {
                return &mpAttributeSeData[index];
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) u32 rSoundAttributeSe::getAttributeSeData_reqID(s32 index, u32 se_id) {
    DDON_STUB("rSoundAttributeSe::getAttributeSeData_reqID")
    return {};
}

void rSoundAttributeSe::setAttributeSeDataList(rSoundAttributeSe::cSoundAttributeSeData* pData, s32 index) {
    if (pData == nullptr) {
        return;
    }
    mpAttributeSeData[index].copy(pData);
}

bool rSoundAttributeSe::getUseFindIntersect(s32 index) {
    if (mpAttributeSeData != nullptr) {
        if (index > -1) {
            if (index < mAttributeSeDataNum) {
                return mpAttributeSeData[index].getUseFindIntersect();
            }
        }
    }
    return false;
}

void rSoundAttributeSe::requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pRequest, reqNo, thisId, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void rSoundAttributeSe::requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pRequest, reqNo, thisId, pos, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

void rSoundAttributeSe::requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jointId) {
    if (sSound::getInstance() == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(pRequest, reqNo, thisId, pCoord, jointId, 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
}

__attribute__((weak)) void rSoundAttributeSe::createAttributeSeDataForProperty(u32 num) {
    if (mpAttributeSeData != nullptr) {
        delete[] mpAttributeSeData;
        mpAttributeSeData = nullptr;
        mAttributeSeDataNum = 0;
    }
    mpAttributeSeData = new (16u) cSoundAttributeSeData[num];
    mAttributeSeDataNum = static_cast<s32>(num);
}

inline rSoundAttributeSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundAttributeSe::MyDTI rSoundAttributeSe::DTI("rSoundAttributeSe", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rSoundAttributeSe::MyDTI::newInstance() const {
    return new (16u) rSoundAttributeSe;
}

const MtDTI& rSoundAttributeSe::cSoundAttributeSeData::getDTI() const {
    return rSoundAttributeSe::cSoundAttributeSeData::DTI;
}

inline void* rSoundAttributeSe::cSoundAttributeSeData::operator new[](size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundAttributeSeData::DTI)->memAlloc(sz, align, cSoundAttributeSeData::DTI.getID());
}

inline rSoundAttributeSe::cSoundAttributeSeData::cSoundAttributeSeData() {
    memset(static_cast<void*>(&mReqType), 0, 133ul);
}

rSoundAttributeSe::cSoundAttributeSeData::~cSoundAttributeSeData() {
}

void rSoundAttributeSe::cSoundAttributeSeData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "UseFindIntersect", &mUseFindIntersect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReqType", &mReqType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_00", &mSeReqID_00, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_01", &mSeReqID_01, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_02", &mSeReqID_02, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_03", &mSeReqID_03, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_04", &mSeReqID_04, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_05", &mSeReqID_05, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_06", &mSeReqID_06, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_07", &mSeReqID_07, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_08", &mSeReqID_08, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_09", &mSeReqID_09, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_10", &mSeReqID_10, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_11", &mSeReqID_11, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_12", &mSeReqID_12, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_13", &mSeReqID_13, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_14", &mSeReqID_14, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_15", &mSeReqID_15, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_16", &mSeReqID_16, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_17", &mSeReqID_17, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_18", &mSeReqID_18, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_19", &mSeReqID_19, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_20", &mSeReqID_20, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_21", &mSeReqID_21, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_22", &mSeReqID_22, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_23", &mSeReqID_23, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_24", &mSeReqID_24, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_25", &mSeReqID_25, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_26", &mSeReqID_26, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_27", &mSeReqID_27, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_28", &mSeReqID_28, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_29", &mSeReqID_29, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_30", &mSeReqID_30, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqID_31", &mSeReqID_31, 0u, 0u);
}

MtUI* rSoundAttributeSe::cSoundAttributeSeData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void rSoundAttributeSe::cSoundAttributeSeData::copy(rSoundAttributeSe::cSoundAttributeSeData* p_src) {
    if (p_src == nullptr) {
        return;
    }
    mReqType = p_src->mReqType;
    mSeReqID_00 = p_src->mSeReqID_00;
    mSeReqID_01 = p_src->mSeReqID_01;
    mSeReqID_02 = p_src->mSeReqID_02;
    mSeReqID_03 = p_src->mSeReqID_03;
    mSeReqID_04 = p_src->mSeReqID_04;
    mSeReqID_05 = p_src->mSeReqID_05;
    mSeReqID_06 = p_src->mSeReqID_06;
    mSeReqID_07 = p_src->mSeReqID_07;
    mSeReqID_08 = p_src->mSeReqID_08;
    mSeReqID_09 = p_src->mSeReqID_09;
    mSeReqID_10 = p_src->mSeReqID_10;
    mSeReqID_11 = p_src->mSeReqID_11;
    mSeReqID_12 = p_src->mSeReqID_12;
    mSeReqID_13 = p_src->mSeReqID_13;
    mSeReqID_14 = p_src->mSeReqID_14;
    mSeReqID_15 = p_src->mSeReqID_15;
    mSeReqID_16 = p_src->mSeReqID_16;
    mSeReqID_17 = p_src->mSeReqID_17;
    mSeReqID_18 = p_src->mSeReqID_18;
    mSeReqID_19 = p_src->mSeReqID_19;
    mSeReqID_20 = p_src->mSeReqID_20;
    mSeReqID_21 = p_src->mSeReqID_21;
    mSeReqID_22 = p_src->mSeReqID_22;
    mSeReqID_23 = p_src->mSeReqID_23;
    mSeReqID_24 = p_src->mSeReqID_24;
    mSeReqID_25 = p_src->mSeReqID_25;
    mSeReqID_26 = p_src->mSeReqID_26;
    mSeReqID_27 = p_src->mSeReqID_27;
    mSeReqID_28 = p_src->mSeReqID_28;
    mSeReqID_29 = p_src->mSeReqID_29;
    mSeReqID_30 = p_src->mSeReqID_30;
    mSeReqID_31 = p_src->mSeReqID_31;
    mUseFindIntersect = p_src->mUseFindIntersect;
}

inline rSoundAttributeSe::cSoundAttributeSeData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundAttributeSe::cSoundAttributeSeData::MyDTI rSoundAttributeSe::cSoundAttributeSeData::DTI("rSoundAttributeSe::cSoundAttributeSeData", &::MtObject::DTI, 144ul, 0u, 0u);

MtObject* rSoundAttributeSe::cSoundAttributeSeData::MyDTI::newInstance() const {
    return new (16u) rSoundAttributeSe::cSoundAttributeSeData;
}

