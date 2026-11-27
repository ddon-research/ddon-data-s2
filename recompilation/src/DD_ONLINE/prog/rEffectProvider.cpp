// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEffectProvider.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "nDDOUtility.h"
#include "../../XFramework/rEffect2D.h"
#include "../../XFramework/rEffectList.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rEffectProvider::getDTI() const {
    return rEffectProvider::DTI;
}

rEffectProvider::~rEffectProvider() {
}

MT_CTSTR rEffectProvider::getExt() const {
    return "epv";
}

__attribute__((weak)) bool rEffectProvider::load(MtStream& in) {
        f32 ReaderF32;
        u32 ReaderU32;
        MtDataReader r(in, 0x1000u);
        nDDOIO::readData(r, ReaderU32);
        if (ReaderU32 != 0x767065u) {
            return false;
        }
        nDDOIO::readData(r, ReaderU32);
        if (ReaderU32 != EP_VERSION) {
            return false;
        }
        rEffectProvider::INFO_EFFECT* pInfoEffect = &mInfo.mEffectInfo;
        u32 indexNum;
        nDDOIO::readData(r, indexNum);
        pInfoEffect->setEffectIndexNum(indexNum);
        if (indexNum != 0) {
            pInfoEffect->setEffectIndex(static_cast<rEffectProvider::EffectIndex*>(rEffectProvider::INFO_EFFECT::getAllocator()->memAlloc(sizeof(rEffectProvider::EffectIndex) * indexNum, 16u)));
            for (u32 idx = 0; idx < indexNum; idx++) {
                rEffectProvider::EffectIndex* pIndex = pInfoEffect->getEffectIndex(idx);
                new (pIndex) rEffectProvider::EffectIndex();
                if (pIndex == nullptr) continue;
                u32 elementNum;
                nDDOIO::readData(r, elementNum);
                pIndex->setEffectElementNum(elementNum);
                if (elementNum == 0) continue;
                pIndex->setEffectElement(static_cast<rEffectProvider::EffectElement*>(rEffectProvider::INFO_EFFECT::getAllocator()->memAlloc(sizeof(rEffectProvider::EffectElement) * elementNum, 16u)));
                for (u32 elm = 0; elm < elementNum; elm++) {
                    rEffectProvider::EffectElement* pElement = pIndex->getEffectElement(elm);
                    new (pElement) rEffectProvider::EffectElement;
                    if (pElement == nullptr) continue;
                    u32 ReleaseVer;
                    nDDOIO::readData(r, ReleaseVer);
                    for (u32 i = 0; i < EFC_LIST_MAX; i++) {
                        MT_CHAR path[64] = {};
                        nDDOIO::readData(r, path, 64u);
                        if (ReleaseVer <= 0x2020u && path[0] != 0) {
                            rEffectList* pResource = static_cast<rEffectList*>(sResource::getInstance()->create(rEffectList::DTI, path, 1u));
                            pElement->setEffectList(pResource, i);
                            if (pResource != nullptr) {
                                pResource->release();
                            }
                        }
                    }
                    for (u32 i = 0; i < EFC_2D_MAX; i++) {
                        MT_CHAR path[64] = {};
                        nDDOIO::readData(r, path, 64u);
                        if (ReleaseVer <= 0x2020u && path[0] != 0) {
                            rEffect2D* pResource = static_cast<rEffect2D*>(sResource::getInstance()->create(rEffect2D::DTI, path, 1u));
                            pElement->setEffect2D(pResource, i);
                            if (pResource != nullptr) {
                                pResource->release();
                            }
                        }
                    }
                    nDDOIO::readData(r, ReaderU32);
                    pElement->setResourceType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pElement->setEffectType(ReaderU32);
                    rEffectProvider::EffectParam* pParam = pElement->getEffectParam();
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setSetType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setEndType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setGroupFlag(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setMaterialFlag(ReaderU32);
                    MtVector3 vec;
                    nDDOIO::readData(r, vec.x);
                    nDDOIO::readData(r, vec.y);
                    nDDOIO::readData(r, vec.z);
                    pParam->setPosition(vec);
                    nDDOIO::readData(r, vec.x);
                    nDDOIO::readData(r, vec.y);
                    nDDOIO::readData(r, vec.z);
                    pParam->setCamOfs(vec);
                    nDDOIO::readData(r, vec.x);
                    nDDOIO::readData(r, vec.y);
                    nDDOIO::readData(r, vec.z);
                    pParam->setDirection(vec);
                    nDDOIO::readData(r, vec.x);
                    nDDOIO::readData(r, vec.y);
                    nDDOIO::readData(r, vec.z);
                    pParam->setDirectionAmp(vec);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setAxisType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setOrder(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setParentNo(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setJointNo(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setPosType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setRotType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setDefaultColor(ReaderU32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setDefaultColorRate(ReaderF32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setDefaultColorMode(ReaderU32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setAlphaScale(ReaderF32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setLightPriority(ReaderU32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setScale(ReaderF32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setScaleAmp(ReaderF32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setDeltaTimeCoef(ReaderF32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setIncidenceAngleEnable(ReaderU32 != 0);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setLandSetEnable(ReaderU32 != 0);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setLandDirEnable(ReaderU32 != 0);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setOMMaterialEnable(ReaderU32 != 0);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setZoneCorrectType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setLoopFrame(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setE2DType(ReaderU32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setLandLength(ReaderF32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setCustomFlag(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setParentRelationFlagFlag(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setAdhesionDivideMax(ReaderU32);
                    nDDOIO::readData(r, pParam->WeatherOnBit());
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setZoneOnBit(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setQuakeType(ReaderU32);
                    nDDOIO::readData(r, ReaderU32);
                    pParam->setCreateCost(ReaderU32);
                    nDDOIO::readData(r, ReaderF32);
                    pParam->setFinishFadeOutFrame(ReaderF32);
                }
            }
        }
        u32 motSyncNum;
        nDDOIO::readData(r, motSyncNum);
        pInfoEffect->setMotSyncListNum(motSyncNum);
        if (motSyncNum != 0) {
            rEffectProvider::EffectMotSyncParam* pEffectMotSyncParam = static_cast<rEffectProvider::EffectMotSyncParam*>(rEffectProvider::INFO_EFFECT::getAllocator()->memAlloc(sizeof(rEffectProvider::EffectMotSyncParam) * motSyncNum, 16u));
            pInfoEffect->setMotSyncList(pEffectMotSyncParam);
            for (u32 i = 0; i < motSyncNum; i++) {
                rEffectProvider::EffectMotSyncParam* pParam = new (pInfoEffect->getMotSyncList(i)) rEffectProvider::EffectMotSyncParam;
                if (pParam == nullptr) continue;
                nDDOIO::readData(r, ReaderU32);
                pParam->setMotionNo(ReaderU32);
                nDDOIO::readData(r, ReaderU32);
                pParam->setBlendIndex(ReaderU32);
                nDDOIO::readData(r, ReaderF32);
                pParam->setStartFrame(ReaderF32);
                nDDOIO::readData(r, ReaderF32);
                pParam->setEndFrame(ReaderF32);
                nDDOIO::readData(r, ReaderF32);
                pParam->setInterval(ReaderF32);
                nDDOIO::readData(r, ReaderU32);
                pParam->setLeaveFlag(ReaderU32 != 0);
                nDDOIO::readData(r, ReaderU32);
                pParam->setSetOnceFlag(ReaderU32 != 0);
                nDDOIO::readData(r, ReaderU32);
                pParam->setEfcIndexNo(ReaderU32);
                nDDOIO::readData(r, ReaderU32);
                pParam->setEfcElementNo(ReaderU32);
            }
        }
        u32 eventNum;
        nDDOIO::readData(r, eventNum);
        pInfoEffect->setEventListNum(eventNum);
        if (eventNum != 0) {
            rEffectProvider::EffectEventParam* pEffectEventParam = static_cast<rEffectProvider::EffectEventParam*>(rEffectProvider::INFO_EFFECT::getAllocator()->memAlloc(sizeof(rEffectProvider::EffectEventParam) * eventNum, 16u));
            pInfoEffect->setEventList(pEffectEventParam);
            for (u32 i = 0; i < eventNum; i++) {
                rEffectProvider::EffectEventParam* pParam = new (pInfoEffect->getEventList(i)) rEffectProvider::EffectEventParam;
                if (pParam == nullptr) continue;
                nDDOIO::readData(r, ReaderU32);
                pParam->setEventWorkNo(ReaderU32);
                nDDOIO::readData(r, ReaderU32);
                pParam->setEfcIndexNo(ReaderU32);
                nDDOIO::readData(r, ReaderU32);
                pParam->setEfcElementNo(ReaderU32);
            }
        }
        return true;
}

__attribute__((weak)) bool rEffectProvider::save(MtStream& out) {
    MtDataWriter w(out, 0x1000u, 0x1000u);
    nDDOIO::writeData(w, 0x767065u);
    nDDOIO::writeData(w, EP_VERSION);
    rEffectProvider::INFO_EFFECT* pInfoEffect = &mInfo.mEffectInfo;
    nDDOIO::writeData(w, pInfoEffect->getEffectIndexNum());
    for (u32 idx = 0; idx < pInfoEffect->getEffectIndexNum(); idx++) {
        rEffectProvider::EffectIndex* pIndex = pInfoEffect->getEffectIndex(idx);
        if (pIndex == nullptr) continue;
        nDDOIO::writeData(w, pIndex->getEffectElementNum());
        for (u32 elm = 0; elm < pIndex->getEffectElementNum(); elm++) {
            rEffectProvider::EffectElement* pElement = pIndex->getEffectElement(elm);
            if (pElement == nullptr) continue;
            nDDOIO::writeData(w, pElement->getEffectReleaseVer());
            for (u32 i = 0; i < EFC_LIST_MAX; i++) {
                rEffectList* pResource = pElement->getEffectList(i);
                nDDOIO::writeData(w, pResource == nullptr ? "" : pResource->getPath());
            }
            for (u32 i = 0; i < EFC_2D_MAX; i++) {
                rEffect2D* pResource = pElement->getEffect2D(i);
                nDDOIO::writeData(w, pResource == nullptr ? "" : pResource->getPath());
            }
            nDDOIO::writeData(w, pElement->getResourceType());
            nDDOIO::writeData(w, pElement->getEffectType());
            rEffectProvider::EffectParam* pParam = pElement->getEffectParam();
            nDDOIO::writeData(w, pParam->getSetType());
            nDDOIO::writeData(w, pParam->getEndType());
            nDDOIO::writeData(w, pParam->getGroupFlag());
            nDDOIO::writeData(w, pParam->getMaterialFlag());
            nDDOIO::writeData(w, pParam->getPosition().x);
            nDDOIO::writeData(w, pParam->getPosition().y);
            nDDOIO::writeData(w, pParam->getPosition().z);
            nDDOIO::writeData(w, pParam->getCamOfs().x);
            nDDOIO::writeData(w, pParam->getCamOfs().y);
            nDDOIO::writeData(w, pParam->getCamOfs().z);
            nDDOIO::writeData(w, pParam->getDirection().x);
            nDDOIO::writeData(w, pParam->getDirection().y);
            nDDOIO::writeData(w, pParam->getDirection().z);
            nDDOIO::writeData(w, pParam->getDirectionAmp().x);
            nDDOIO::writeData(w, pParam->getDirectionAmp().y);
            nDDOIO::writeData(w, pParam->getDirectionAmp().z);
            nDDOIO::writeData(w, pParam->getAxisType());
            nDDOIO::writeData(w, pParam->getOrder());
            nDDOIO::writeData(w, pParam->getParentNo());
            nDDOIO::writeData(w, pParam->getJointNo());
            nDDOIO::writeData(w, pParam->getPosType());
            nDDOIO::writeData(w, pParam->getRotType());
            nDDOIO::writeData(w, pParam->getDefaultColor());
            nDDOIO::writeData(w, pParam->getDefaultColorRate());
            nDDOIO::writeData(w, pParam->getDefaultColorMode());
            nDDOIO::writeData(w, pParam->getAlphaScale());
            nDDOIO::writeData(w, pParam->getLightPriority());
            nDDOIO::writeData(w, pParam->getScale());
            nDDOIO::writeData(w, pParam->getScaleAmp());
            nDDOIO::writeData(w, pParam->getDeltaTimeCoef());
            nDDOIO::writeData(w, static_cast<u32>(pParam->getIncidenceAngleEnable()));
            nDDOIO::writeData(w, static_cast<u32>(pParam->getLandSetEnable()));
            nDDOIO::writeData(w, static_cast<u32>(pParam->getLandDirEnable()));
            nDDOIO::writeData(w, static_cast<u32>(pParam->getOMMaterialEnable()));
            nDDOIO::writeData(w, pParam->getZoneCorrectType());
            nDDOIO::writeData(w, pParam->getLoopFrame());
            nDDOIO::writeData(w, pParam->getE2DType());
            nDDOIO::writeData(w, pParam->getLandLength());
            nDDOIO::writeData(w, pParam->getCustomFlag());
            nDDOIO::writeData(w, pParam->getParentRelationFlag());
            nDDOIO::writeData(w, pParam->getAdhesionDivideMax());
            nDDOIO::writeData(w, pParam->WeatherOnBit());
            nDDOIO::writeData(w, pParam->getZoneOnBit());
            nDDOIO::writeData(w, pParam->getQuakeType());
            nDDOIO::writeData(w, pParam->getCreateCost());
            nDDOIO::writeData(w, pParam->getFinishFadeOutFrame());
        }
    }
    nDDOIO::writeData(w, pInfoEffect->getMotSyncListNum());
    for (u32 i = 0; i < pInfoEffect->getMotSyncListNum(); i++) {
        rEffectProvider::EffectMotSyncParam* pParam = pInfoEffect->getMotSyncList(i);
        if (pParam == nullptr) continue;
        nDDOIO::writeData(w, pParam->getMotionNo());
        nDDOIO::writeData(w, pParam->getBlendIndex());
        nDDOIO::writeData(w, pParam->getStartFrame());
        nDDOIO::writeData(w, pParam->getEndFrame());
        nDDOIO::writeData(w, pParam->getInterval());
        nDDOIO::writeData(w, static_cast<u32>(pParam->getLeaveFlag()));
        nDDOIO::writeData(w, static_cast<u32>(pParam->getSetOnceFlag()));
        nDDOIO::writeData(w, pParam->getEfcIndexNo());
        nDDOIO::writeData(w, pParam->getEfcElementNo());
    }
    nDDOIO::writeData(w, pInfoEffect->getEventListNum());
    for (u32 i = 0; i < pInfoEffect->getEventListNum(); i++) {
        rEffectProvider::EffectEventParam* pParam = pInfoEffect->getEventList(i);
        if (pParam == nullptr) continue;
        nDDOIO::writeData(w, pParam->getEventWorkNo());
        nDDOIO::writeData(w, pParam->getEfcIndexNo());
        nDDOIO::writeData(w, pParam->getEfcElementNo());
    }
    return true;
}

void rEffectProvider::clear() {
    mInfo.mEffectInfo.clear();
}

inline rEffectProvider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::MyDTI rEffectProvider::DTI("rEffectProvider", &::cResource::DTI, 176ul, 0u, 0u);

MtObject* rEffectProvider::MyDTI::newInstance() const {
    return new (16u) rEffectProvider;
}

const MtDTI& rEffectProvider::INFO_PROV::getDTI() const {
    return rEffectProvider::INFO_PROV::DTI;
}

inline rEffectProvider::INFO_PROV::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::INFO_PROV::MyDTI rEffectProvider::INFO_PROV::DTI("rEffectProvider::INFO_PROV", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* rEffectProvider::INFO_PROV::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::INFO_PROV;
}

const MtDTI& rEffectProvider::INFO_EFFECT::getDTI() const {
    return rEffectProvider::INFO_EFFECT::DTI;
}

rEffectProvider::INFO_EFFECT::~INFO_EFFECT() {
    clear();
}

__attribute__((weak)) void rEffectProvider::INFO_EFFECT::clear() {
        for (u32 i = 0; i < mEffectIndexNum; i++) {
            mpEffectIndex[i].~EffectIndex();
        }
        MtMemoryAllocator::getAllocator(rEffectProvider::INFO_EFFECT::DTI)->memFree(mpEffectIndex);
        mpEffectIndex = nullptr;
        mEffectIndexNum = 0;
        for (u32 i = 0; i < mMotSyncListNum; i++) {
            mpMotSyncList[i].~EffectMotSyncParam();
        }
        MtMemoryAllocator::getAllocator(rEffectProvider::INFO_EFFECT::DTI)->memFree(mpMotSyncList);
        mpMotSyncList = nullptr;
        mMotSyncListNum = 0;
        for (u32 i = 0; i < mEventListNum; i++) {
            mpEventList[i].~EffectEventParam();
        }
        MtMemoryAllocator::getAllocator(rEffectProvider::INFO_EFFECT::DTI)->memFree(mpEventList);
        mpEventList = nullptr;
        mEventListNum = 0;
}

rEffectProvider::EffectElement* rEffectProvider::INFO_EFFECT::getEffectElement(s32 IndexNo, s32 ElementNo) const {
    if ((IndexNo | ElementNo) > -1) {
        if (IndexNo < static_cast<int>(mEffectIndexNum)) {
            if ((&mpEffectIndex[IndexNo]) != nullptr) {
                if (ElementNo > -1) {
                    if (ElementNo < static_cast<int>(mpEffectIndex[IndexNo].mEffectElementNum)) {
                        return &mpEffectIndex[IndexNo].mpEffectElement[ElementNo];
                    }
                }
            }
        }
    }
    return nullptr;
}

rEffectProvider::EffectParam* rEffectProvider::INFO_EFFECT::getEffectParam(s32 IndexNo, s32 ElementNo) const {
    if ((IndexNo | ElementNo) > -1) {
        if (IndexNo < static_cast<int>(mEffectIndexNum)) {
            if ((&mpEffectIndex[IndexNo]) != nullptr) {
                if (ElementNo > -1) {
                    if (ElementNo < static_cast<int>(mpEffectIndex[IndexNo].mEffectElementNum)) {
                        return ((&mpEffectIndex[IndexNo].mpEffectElement[ElementNo]) == nullptr) ? static_cast<rEffectProvider::EffectParam*>(nullptr) : (&mpEffectIndex[IndexNo].mpEffectElement[ElementNo].mEffectParam);
                    }
                }
            }
        }
    }
    return nullptr;
}

inline rEffectProvider::INFO_EFFECT::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::INFO_EFFECT::MyDTI rEffectProvider::INFO_EFFECT::DTI("rEffectProvider::INFO_EFFECT", &::rEffectProvider::INFO_BASE::DTI, 56ul, 0u, 0u);

MtObject* rEffectProvider::INFO_EFFECT::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::INFO_EFFECT;
}

const MtDTI& rEffectProvider::INFO_BASE::getDTI() const {
    return rEffectProvider::INFO_BASE::DTI;
}

bool rEffectProvider::INFO_BASE::toNative(rEffectProvider::INFO_BASE* pInfo) {
    return false;
}

bool rEffectProvider::INFO_BASE::fromNative() {
    return false;
}

inline rEffectProvider::INFO_BASE::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::INFO_BASE::MyDTI rEffectProvider::INFO_BASE::DTI("rEffectProvider::INFO_BASE", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* rEffectProvider::INFO_BASE::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::INFO_BASE;
}

const MtDTI& rEffectProvider::EffectIndex::getDTI() const {
    return rEffectProvider::EffectIndex::DTI;
}

rEffectProvider::EffectIndex::~EffectIndex() {
    unsigned int i3 = 0;
    if (mEffectElementNum != 0) {
        do {
            mpEffectElement[i3].~EffectElement();
            i3 += 1u;
        } while (i3 < mEffectElementNum);
    }
    MtMemoryAllocator::getAllocator(rEffectProvider::EffectIndex::DTI)->memFree(static_cast<void*>(mpEffectElement));
    mpEffectElement = nullptr;
    mEffectElementNum = 0;
}

inline rEffectProvider::EffectIndex::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::EffectIndex::MyDTI rEffectProvider::EffectIndex::DTI("rEffectProvider::EffectIndex", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rEffectProvider::EffectIndex::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::EffectIndex;
}

const MtDTI& rEffectProvider::EffectElement::getDTI() const {
    return rEffectProvider::EffectElement::DTI;
}

__attribute__((noinline)) rEffectProvider::EffectElement::~EffectElement() {
        for (u32 i = 0; i < EFC_LIST_MAX; i++) {
            if (mpEffectList[i] != nullptr) {
                mpEffectList[i]->release();
                mpEffectList[i] = nullptr;
            }
        }
        for (u32 i = 0; i < EFC_2D_MAX; i++) {
            if (mpEffect2D[i] != nullptr) {
                mpEffect2D[i]->release();
                mpEffect2D[i] = nullptr;
            }
        }
}

void rEffectProvider::EffectElement::setEffectList(rEffectList* pEffectList, u32 no) {
    if (no <= 7u) {
        if (pEffectList != mpEffectList[no]) {
            if (mpEffectList[no] != nullptr) {
                mpEffectList[no]->cResource::release();
                mpEffectList[no] = nullptr;
            }
            if (pEffectList != nullptr) {
                if (pEffectList->isIntermediate()) {
                    cResource* t0 = sResource::getInstance()->createNative(static_cast<cResource*>(pEffectList), 1u);
                    if ((mpEffectList[no] = static_cast<rEffectList*>(t0)) != nullptr) {
                        t0->addRef();
                        t0->release();
                    }
                } else {
                    pEffectList->addRef();
                    mpEffectList[no] = pEffectList;
                    pEffectList->addRef();
                    pEffectList->release();
                }
            } else {
                mpEffectList[no] = nullptr;
            }
        }
    }
}

inline rEffectProvider::EffectElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::EffectElement::MyDTI rEffectProvider::EffectElement::DTI("rEffectProvider::EffectElement", &::MtObject::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* rEffectProvider::EffectElement::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::EffectElement;
}

const MtDTI& rEffectProvider::EffectParam::getDTI() const {
    return rEffectProvider::EffectParam::DTI;
}

rEffectProvider::EffectParam::~EffectParam() {
}

inline rEffectProvider::EffectParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::EffectParam::MyDTI rEffectProvider::EffectParam::DTI("rEffectProvider::EffectParam", &::MtObject::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* rEffectProvider::EffectParam::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::EffectParam;
}

const MtDTI& rEffectProvider::EffectMotSyncParam::getDTI() const {
    return rEffectProvider::EffectMotSyncParam::DTI;
}

inline rEffectProvider::EffectMotSyncParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::EffectMotSyncParam::MyDTI rEffectProvider::EffectMotSyncParam::DTI("rEffectProvider::EffectMotSyncParam", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* rEffectProvider::EffectMotSyncParam::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::EffectMotSyncParam;
}

const MtDTI& rEffectProvider::EffectEventParam::getDTI() const {
    return rEffectProvider::EffectEventParam::DTI;
}

inline rEffectProvider::EffectEventParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEffectProvider::EffectEventParam::MyDTI rEffectProvider::EffectEventParam::DTI("rEffectProvider::EffectEventParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rEffectProvider::EffectEventParam::MyDTI::newInstance() const {
    return new (16u) rEffectProvider::EffectEventParam;
}

