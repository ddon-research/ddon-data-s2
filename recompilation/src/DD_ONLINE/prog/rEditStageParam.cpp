// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "rEditStageParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rArchiveListArray.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rEditStageParam::getDTI() const {
    return rEditStageParam::DTI;
}

inline void* rEditStageParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEditStageParam::DTI)->memAlloc(sz, align, rEditStageParam::DTI.getID());
}

inline void rEditStageParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEditStageParam::DTI)->memFree(p_addr);
}

inline rEditStageParam::rEditStageParam() {
    setAttribute(18u);
    this->cResource::clear();
    mpArrayInfo = nullptr;
    mArrayInfoNum = 0;
    mpArrayList = nullptr;
    mArrayListNum = 0;
}

rEditStageParam::~rEditStageParam() {
    destruct();
}

MT_CTSTR rEditStageParam::getExt() const {
    return "esp";
}

__attribute__((weak)) void rEditStageParam::destruct() {
    for (u32 i = 0; i < mArrayInfoNum; ++i) {
        mpArrayInfo[i].~Info();
    }
    getAllocator()->memFree(mpArrayInfo);
    mpArrayInfo = nullptr;
    mArrayInfoNum = 0;
    
    for (u32 i = 0; i < mArrayListNum; ++i) {
        mpArrayList[i].~List();
    }
    getAllocator()->memFree(mpArrayList);
    mpArrayList = nullptr;
    mArrayListNum = 0;
}

__attribute__((weak)) bool rEditStageParam::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x707365u) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    
    const u32 nArrayInfo = r.readU32();
    void* pArrayInfo = nullptr;
    if (nArrayInfo != 0) {
        pArrayInfo = getAllocator()->memAlloc(sizeof(Info) * nArrayInfo, 16u);
        for (u32 i = 0; i < nArrayInfo; ++i) {
            Info* pInfo = new (static_cast<Info*>(pArrayInfo) + i) Info;
            pInfo->load(r);
        }
    }
    mpArrayInfo = static_cast<Info*>(pArrayInfo);
    mArrayInfoNum = nArrayInfo;
    
    const u32 nArrayList = r.readU32();
    void* pArrayList = nullptr;
    if (nArrayList != 0) {
        pArrayList = getAllocator()->memAlloc(sizeof(List) * nArrayList, 16u);
        for (u32 i = 0; i < nArrayList; ++i) {
            List* pList = new (static_cast<List*>(pArrayList) + i) List;
            pList->load(r);
        }
    }
    mpArrayList = static_cast<List*>(pArrayList);
    mArrayListNum = nArrayList;
    
    return true;
}

__attribute__((weak)) bool rEditStageParam::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    w.writeU32(0x707365u);
    w.writeU32(DATA_VERSION);
    
    w.writeU32(mArrayInfoNum);
    for (u32 i = 0; i < mArrayInfoNum; ++i) {
        Info* pInfo = &mpArrayInfo[i];
        pInfo->save(w);
    }
    
    w.writeU32(mArrayListNum);
    for (u32 i = 0; i < mArrayListNum; ++i) {
        List* pList = &mpArrayList[i];
        pList->save(w);
    }
    
    return true;
}

rEditStageParam::Info* rEditStageParam::getInfo(u32 index) const {
    if (index < getNum()) {
        return &mpArrayInfo[index];
    } else {
        return nullptr;
    }
}

u32 rEditStageParam::getNum() const {
    return mArrayInfoNum;
}

rEditStageParam::List* rEditStageParam::getList(u32 index) const {
    if (index < getListNum()) {
        return &mpArrayList[index];
    } else {
        return nullptr;
    }
}

u32 rEditStageParam::getListNum() const {
    return mArrayListNum;
}

__attribute__((weak)) void rEditStageParam::getStageList(u32 type, MtArray& ar) {
    DDON_STUB("rEditStageParam::getStageList")
    /* stub */
}

__attribute__((weak)) s32 rEditStageParam::getStageListNo(u32 type, u32 index) {
    DDON_STUB("rEditStageParam::getStageListNo")
    return {};
}

u32 rEditStageParam::getStageListNum(u32 type) {
    unsigned int v1_3;
    if (type >= getListNum()) {
        v1_3 = 0;
    } else {
        List* p_list = getList(type);
        if (p_list == nullptr) {
            v1_3 = 0;
        } else {
            signed char* v0_0 = &p_list->mListTbl[0];
            for (unsigned int i0_3 = 0;;) {
                if ((*v0_0) <= -1) {
                    v1_3 = i0_3;
                    break;
                } else {
                    if ((i0_3 + 1u) <= 7u) {
                        v0_0 += 1;
                        i0_3 += 1u;
                    } else {
                        v1_3 = i0_3 + 1u;
                        break;
                    }
                }
            }
        }
    }
    return v1_3;
}

__attribute__((weak)) ARC_TAGID rEditStageParam::getStageArcTagId(u32 type, u32 index) {
    DDON_STUB("rEditStageParam::getStageArcTagId")
    return {};
}

inline rEditStageParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEditStageParam::MyDTI rEditStageParam::DTI("rEditStageParam", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rEditStageParam::MyDTI::newInstance() const {
    return new (16u) rEditStageParam;
}

const MtDTI& rEditStageParam::Info::getDTI() const {
    return rEditStageParam::Info::DTI;
}

inline void rEditStageParam::Info::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEditStageParam::Info::DTI)->memFree(p_addr);
}

void rEditStageParam::Info::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mModelSdl", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getModelName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setModelName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mFilterSdl", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getFilterName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setFilterName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mLightSdl", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getLightName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setLightName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mOmListSdl", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getOmListName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setOmListName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mReverb", &mReverb, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPlPos", &mPlPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPlRotY", &mPlRotY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mWeatherStageInfo", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getWeatherStageInfoName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setWeatherStageInfoName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mWeatherParamInfo", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::getWeatherParamInfoName), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::Info::setWeatherParamInfoName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mWeatherData", static_cast<MtObject*>(&mWeatherData[0]), 32u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlag", &mFlag, 0u, 0u);
}

MtUI* rEditStageParam::Info::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

bool rEditStageParam::Info::load(MtDataReader& r) {
    r.readString(&mModelSdl[0], 64u);
    r.readString(&mFilterSdl[0], 64u);
    r.readString(&mLightSdl[0], 64u);
    r.readString(&mOmListSdl[0], 64u);
    mReverb = r.readU32();
    mPlPos = r.readV3();
    nDDOIO::readData(r, mPlRotY);
    r.readString(&mWeatherStageInfo[0], 64u);
    r.readString(&mWeatherParamInfo[0], 64u);
    mWeatherData[0].mWeatherID = r.readU32();
    mWeatherData[0].mHour = r.readU32();
    mWeatherData[0].mMinite = r.readU32();
    mWeatherData[1].mWeatherID = r.readU32();
    mWeatherData[1].mHour = r.readU32();
    mWeatherData[1].mMinite = r.readU32();
    nDDOIO::readData(r, mpSkyWep);
    nDDOIO::readData(r, mpRoomWep);
    nDDOIO::readData(r, mpEpv);
    nDDOIO::readData(r, mEpvIndexAlways);
    nDDOIO::readData(r, mEpvIndexDay);
    nDDOIO::readData(r, mEpvIndexNight);
    nDDOIO::readData(r, mFlag);
    return true;
}

bool rEditStageParam::Info::save(MtDataWriter& w) {
    w.writeString(&mModelSdl[0]);
    w.writeString(&mFilterSdl[0]);
    w.writeString(&mLightSdl[0]);
    w.writeString(&mOmListSdl[0]);
    w.writeU32(mReverb);
    MtFloat3 frame56;
    frame56.x = mPlPos.x;
    frame56.y = mPlPos.y;
    frame56.z = mPlPos.z;
    w.writeV3(frame56);
    w.writeF32(mPlRotY);
    w.writeString(&mWeatherStageInfo[0]);
    w.writeString(&mWeatherParamInfo[0]);
    w.writeU32(mWeatherData[0].mWeatherID);
    w.writeU32(mWeatherData[0].mHour);
    w.writeU32(mWeatherData[0].mMinite);
    w.writeU32(mWeatherData[1].mWeatherID);
    w.writeU32(mWeatherData[1].mHour);
    w.writeU32(mWeatherData[1].mMinite);
    w.writeU64(mpSkyWep.mId);
    w.writeU64(mpRoomWep.mId);
    w.writeU64(mpEpv.mId);
    w.writeS32(mEpvIndexAlways);
    w.writeS32(mEpvIndexDay);
    w.writeS32(mEpvIndexNight);
    w.writeU32(mFlag);
    return true;
}

void rEditStageParam::Info::setModelName(const MtString& name) {
    snprintf(&mModelSdl[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a852c0 __attribute__((used)) = &rEditStageParam::Info::getModelName;

void rEditStageParam::Info::setFilterName(const MtString& name) {
    snprintf(&mFilterSdl[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a852d0 __attribute__((used)) = &rEditStageParam::Info::getFilterName;

void rEditStageParam::Info::setLightName(const MtString& name) {
    snprintf(&mLightSdl[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a852e0 __attribute__((used)) = &rEditStageParam::Info::getLightName;

void rEditStageParam::Info::setOmListName(const MtString& name) {
    snprintf(&mOmListSdl[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a852f0 __attribute__((used)) = &rEditStageParam::Info::getOmListName;

void rEditStageParam::Info::setWeatherStageInfoName(const MtString& name) {
    snprintf(&mWeatherStageInfo[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a85300 __attribute__((used)) = &rEditStageParam::Info::getWeatherStageInfoName;

void rEditStageParam::Info::setWeatherParamInfoName(const MtString& name) {
    snprintf(&mWeatherParamInfo[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01a85310 __attribute__((used)) = &rEditStageParam::Info::getWeatherParamInfoName;

u64 rEditStageParam::Info::getSkyWepResId() const {
    return mpSkyWep.getResId();
}

u64 rEditStageParam::Info::getRoomWepResId() const {
    return mpRoomWep.getResId();
}

u64 rEditStageParam::Info::getEpvResId() const {
    return mpEpv.getResId();
}

s32 rEditStageParam::Info::getEpvIndexAlways() const {
    return mEpvIndexAlways;
}

s32 rEditStageParam::Info::getEpvIndexDay() const {
    return mEpvIndexDay;
}

s32 rEditStageParam::Info::getEpvIndexNight() const {
    return mEpvIndexNight;
}

bool rEditStageParam::Info::isChangeTime() {
    return mWeatherData[0].mHour != mWeatherData[1].mHour;
}

inline rEditStageParam::Info::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEditStageParam::Info::MyDTI rEditStageParam::Info::DTI("rEditStageParam::Info", &::MtObject::DTI, 512ul, 0u, 0u);

__attribute__((weak)) MtObject* rEditStageParam::Info::MyDTI::newInstance() const {
    DDON_STUB("rEditStageParam::Info::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rEditStageParam::Info::WeatherData::getDTI() const {
    return rEditStageParam::Info::WeatherData::DTI;
}

inline void* rEditStageParam::Info::WeatherData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEditStageParam::Info::WeatherData::DTI)->memAlloc(sz, align, rEditStageParam::Info::WeatherData::DTI.getID());
}

inline void rEditStageParam::Info::WeatherData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEditStageParam::Info::WeatherData::DTI)->memFree(p_addr);
}

void rEditStageParam::Info::WeatherData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mWeatherID", &mWeatherID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHour", &mHour, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMinite", &mMinite, 0u, 0u);
}

MtUI* rEditStageParam::Info::WeatherData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rEditStageParam::Info::WeatherData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEditStageParam::Info::WeatherData::MyDTI rEditStageParam::Info::WeatherData::DTI("rEditStageParam::Info::WeatherData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rEditStageParam::Info::WeatherData::MyDTI::newInstance() const {
    return new (16u) rEditStageParam::Info::WeatherData;
}

const MtDTI& rEditStageParam::List::getDTI() const {
    return rEditStageParam::List::DTI;
}

inline void rEditStageParam::List::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEditStageParam::List::DTI)->memFree(p_addr);
}

void rEditStageParam::List::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S8, "mListTbl", reinterpret_cast<MT_MFUNC>(&::rEditStageParam::List::getListNo), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::List::setListNo), 160u, reinterpret_cast<MT_MFUNC>(&::rEditStageParam::List::getListNoNum), reinterpret_cast<MT_MFUNC>(&::rEditStageParam::List::setListNoNum));
}

static auto ddon_emit_0x01a85330 __attribute__((used)) = &rEditStageParam::List::getListNo;

static auto ddon_emit_0x01a85340 __attribute__((used)) = &rEditStageParam::List::setListNo;

static auto ddon_emit_0x01a85350 __attribute__((used)) = &rEditStageParam::List::getListNoNum;

__attribute__((weak)) void rEditStageParam::List::setListNoNum(u32) {
}

inline rEditStageParam::List::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEditStageParam::List::MyDTI rEditStageParam::List::DTI("rEditStageParam::List", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* rEditStageParam::List::MyDTI::newInstance() const {
    DDON_STUB("rEditStageParam::List::MyDTI::newInstance")
    return nullptr;
}

