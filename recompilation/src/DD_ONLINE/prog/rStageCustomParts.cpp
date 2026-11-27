// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "rStageCustomParts.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nZoneUnitCtrl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rStageCustomParts::getDTI() const {
    return rStageCustomParts::DTI;
}

rStageCustomParts::rStageCustomParts() {
    mAttr = 18;
    mpArrayInfo = nullptr;
    mArrayInfoNum = 0;
    mpArrayFilter = nullptr;
    mArrayFilterNum = 0;
}

rStageCustomParts::~rStageCustomParts() {
    destruct();
}

MT_CTSTR rStageCustomParts::getExt() const {
    return "scp";
}

__attribute__((weak)) void rStageCustomParts::destruct() {
    if (mArrayInfoNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            mpArrayInfo[i0_3].~Info();
            if ((i0_3 + 1u) < mArrayInfoNum) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    MtMemoryAllocator::getAllocator(rStageCustomParts::DTI)->memFree(static_cast<void*>(mpArrayInfo));
    mpArrayInfo = nullptr;
    mArrayInfoNum = 0;
    if (mArrayFilterNum != 0) {
        for (unsigned int i2_3 = 0;;) {
            mpArrayFilter[i2_3].~Filter();
            if ((i2_3 + 1u) < mArrayFilterNum) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
    MtMemoryAllocator::getAllocator(rStageCustomParts::DTI)->memFree(static_cast<void*>(mpArrayFilter));
    mpArrayFilter = nullptr;
    mArrayFilterNum = 0;
}

__attribute__((weak)) bool rStageCustomParts::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x706373u) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    mParam.load(r);
    const u32 nArrayInfo = r.readU32();
    void* pArrayInfo = nullptr;
    if (nArrayInfo != 0) {
        pArrayInfo = MtMemoryAllocator::getAllocator(rStageCustomParts::DTI)->memAlloc(sizeof(Info) * nArrayInfo, 16u);
        for (u32 i = 0; i < nArrayInfo; i++) {
            Info* pInfo = new (static_cast<Info*>(pArrayInfo) + i) Info;
            pInfo->load(r);
        }
    }
    mpArrayInfo = static_cast<Info*>(pArrayInfo);
    mArrayInfoNum = nArrayInfo;
    const u32 nArrayFilter = r.readU32();
    void* pArrayFilter = nullptr;
    if (nArrayFilter != 0) {
        pArrayFilter = MtMemoryAllocator::getAllocator(rStageCustomParts::DTI)->memAlloc(sizeof(Filter) * nArrayFilter, 16u);
        for (u32 i = 0; i < nArrayFilter; i++) {
            Filter* pFilter = new (static_cast<Filter*>(pArrayFilter) + i) Filter;
            pFilter->load(r);
        }
    }
    mpArrayFilter = static_cast<Filter*>(pArrayFilter);
    mArrayFilterNum = nArrayFilter;
    return true;
}

bool rStageCustomParts::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.MtDataWriter::writeU32(0x706373u);
    w.MtDataWriter::writeU32(17u);
    (&w)->writeF32(mParam.mDelta);
    (&w)->writeF32(mParam.mOffsetY);
    w.MtDataWriter::writeU32(mArrayInfoNum);
    if (mArrayInfoNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            mpArrayInfo[i0_3].save(w);
            if ((i0_3 + 1u) < mArrayInfoNum) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    w.MtDataWriter::writeU32(mArrayFilterNum);
    if (mArrayFilterNum != 0) {
        for (unsigned int i2_3 = 0;;) {
            w.writeString(&mpArrayFilter[i2_3].mFilter[0]);
            if ((i2_3 + 1u) < mArrayFilterNum) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

rStageCustomParts::Info* rStageCustomParts::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArrayInfo[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomParts::getInfoNum() const {
    return mArrayInfoNum;
}

rStageCustomParts::Filter* rStageCustomParts::getFilter(u32 index) const {
    if (index < getFilterNum()) {
        return &mpArrayFilter[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomParts::getFilterNum() const {
    return mArrayFilterNum;
}

u32 rStageCustomParts::getAreaSize(u32 areaNo) {
    Info* pinfo = searchInfo(areaNo);
    if (pinfo != nullptr) {
        return pinfo->mSize;
    } else {
        return 0;
    }
}

MT_CTSTR rStageCustomParts::getFilterName(u32 index) {
    if (index < getFilterNum()) {
        return &getFilter(index)->mFilter[0];
    } else {
        return nullptr;
    }
}

rStageCustomParts::Info* rStageCustomParts::searchInfo(u32 areaNo) const {
    if (getInfoNum() != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (getInfo(i0_3)->mAreaNo == areaNo) {
                return getInfo(i0_3);
            } else {
                if ((i0_3 + 1u) < getInfoNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

inline rStageCustomParts::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomParts::MyDTI rStageCustomParts::DTI("rStageCustomParts", &::cResource::DTI, 160ul, 0u, 0u);

MtObject* rStageCustomParts::MyDTI::newInstance() const {
    return new (16u) rStageCustomParts;
}

const MtDTI& rStageCustomParts::Param::getDTI() const {
    return rStageCustomParts::Param::DTI;
}

void rStageCustomParts::Param::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDelta", &mDelta, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetY", &mOffsetY, 0u, 0u);
}

bool rStageCustomParts::Param::load(MtDataReader& r) {
    nDDOIO::readData(r, mDelta);
    nDDOIO::readData(r, mOffsetY);
    return true;
}

bool rStageCustomParts::Param::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mDelta);
    nDDOIO::writeData(w, mOffsetY);
    return true;
}

inline rStageCustomParts::Param::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomParts::Param::MyDTI rStageCustomParts::Param::DTI("rStageCustomParts::Param", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rStageCustomParts::Param::MyDTI::newInstance() const {
    return new (16u) rStageCustomParts::Param;
}

const MtDTI& rStageCustomParts::Info::getDTI() const {
    return rStageCustomParts::Info::DTI;
}

__attribute__((noinline)) rStageCustomParts::Info::Info() {
    clear();
}

rStageCustomParts::Info::~Info() {
}

void rStageCustomParts::Info::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mModel", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getModelName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setModelName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mScrSbc", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getScrSbcName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setScrSbcName), 160u, reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getScrSbcNameNum), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setScrSbcNameNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mEffSbc", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getEffSbcName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setEffSbcName), 160u, reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getEffSbcNameNum), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setEffSbcNameNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mLight", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getLightName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setLightName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mNaviMesh", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getNaviMeshName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setNaviMeshName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mEpv", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getEpvName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setEpvName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mOccluder", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::getOccluderName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Info::setOccluderName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSize", &mSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetZ", &mOffsetZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexAlways", &mEpvIndexAlways, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexDay", &mEpvIndexDay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexNight", &mEpvIndexNight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 0u, 0u);
}

MtUI* rStageCustomParts::Info::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rStageCustomParts::Info::load(MtDataReader& r) {
    r.readString(mModel, 64u);
    for (u32 i = 0; i < 3; i++) {
        r.readString(mScrSbc[i], 64u);
        r.readString(mEffSbc[i], 64u);
    }
    r.readString(mLight, 64u);
    r.readString(mNaviMesh, 64u);
    r.readString(mEpv, 64u);
    r.readString(mOccluder, 64u);
    mAreaNo = r.readU16();
    mType = r.readU16();
    nDDOIO::readData(r, mSize);
    mOffsetZ = r.readF32();
    mEpvIndexAlways = r.readS32();
    mEpvIndexDay = r.readS32();
    mEpvIndexNight = r.readS32();
    mColor.rgba = r.readU32();
    nDDOIO::readData(r, mEfcColorZone);
    nDDOIO::readData(r, mEfcCtrlZone);
    nDDOIO::readData(r, mIndoorZoneScr);
    nDDOIO::readData(r, mIndoorZoneEfc);
    nDDOIO::readData(r, mLightAndFogZone);
    nDDOIO::readData(r, mSoundAreaInfo);
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::readData(r, mZoneUnitCtrl[i]);
    }
    nDDOIO::readData(r, mZoneStatus);
    nDDOIO::readData(r, mComment);
    return true;
}

__attribute__((weak)) bool rStageCustomParts::Info::save(MtDataWriter& w) {
    w.writeString(&mModel[0]);
    w.writeString(&mScrSbc[0][0]);
    w.writeString(&mEffSbc[0][0]);
    w.writeString(&mScrSbc[1][0]);
    w.writeString(&mEffSbc[1][0]);
    w.writeString(&mScrSbc[2][0]);
    w.writeString(&mEffSbc[2][0]);
    w.writeString(&mLight[0]);
    w.writeString(&mNaviMesh[0]);
    w.writeString(&mEpv[0]);
    w.writeString(&mOccluder[0]);
    w.writeU16(mAreaNo);
    w.writeU16(mType);
    nDDOIO::writeData(w, mSize);
    w.writeF32(mOffsetZ);
    w.writeS32(mEpvIndexAlways);
    w.writeS32(mEpvIndexDay);
    w.writeS32(mEpvIndexNight);
    w.writeU32(mColor.rgba);
    w.writeU64(mEfcColorZone.mId);
    w.writeU64(mEfcCtrlZone.mId);
    w.writeU64(mIndoorZoneScr.mId);
    w.writeU64(mIndoorZoneEfc.mId);
    w.writeU64(mLightAndFogZone.mId);
    w.writeU64(mSoundAreaInfo.mId);
    w.writeU64(mZoneUnitCtrl[0].mId);
    w.writeU64(mZoneUnitCtrl[1].mId);
    w.writeU64(mZoneUnitCtrl[2].mId);
    nDDOIO::writeData(w, mZoneStatus);
    w.writeString(mComment.ptr());
    return true;
}

void rStageCustomParts::Info::clear() {
    mModel[0] = 0;
    for (u32 i = 0; i < 3; i++) {
        mScrSbc[i][0] = 0;
        mEffSbc[i][0] = 0;
    }
    mLight[0] = 0;
    mNaviMesh[0] = 0;
    mEpv[0] = 0;
    mOccluder[0] = 0;
    mAreaNo = 0;
    mSize = 1;
    mType = 0;
    mOffsetZ = 0.0f;
    mEpvIndexAlways = 0;
    mEpvIndexDay = 1;
    mEpvIndexNight = 2;
    mColor = MtColor::White;
    mComment = "";
}

void rStageCustomParts::Info::setModelName(const MtString& name) {
    snprintf(&mModel[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2cd0 __attribute__((used)) = &rStageCustomParts::Info::getModelName;

void rStageCustomParts::Info::setScrSbcName(const MtString& name, u32 idx) {
    snprintf(reinterpret_cast<char*>(mScrSbc[idx]), 64ul, "%s", name.ptr());
}

__attribute__((weak)) MT_CTSTR rStageCustomParts::Info::getScrSbcName(u32 idx) const {
    DDON_STUB("rStageCustomParts::Info::getScrSbcName")
    return {};
}

__attribute__((weak)) void rStageCustomParts::Info::setScrSbcNameNum(u32) {
}

static auto ddon_emit_0x01ab2cf0 __attribute__((used)) = &rStageCustomParts::Info::getScrSbcNameNum;

void rStageCustomParts::Info::setEffSbcName(const MtString& name, u32 idx) {
    snprintf(reinterpret_cast<char*>(mEffSbc[idx]), 64ul, "%s", name.ptr());
}

__attribute__((weak)) MT_CTSTR rStageCustomParts::Info::getEffSbcName(u32 idx) const {
    DDON_STUB("rStageCustomParts::Info::getEffSbcName")
    return {};
}

__attribute__((weak)) void rStageCustomParts::Info::setEffSbcNameNum(u32) {
}

static auto ddon_emit_0x01ab2d20 __attribute__((used)) = &rStageCustomParts::Info::getEffSbcNameNum;

void rStageCustomParts::Info::setLightName(const MtString& name) {
    snprintf(&mLight[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2d40 __attribute__((used)) = &rStageCustomParts::Info::getLightName;

void rStageCustomParts::Info::setNaviMeshName(const MtString& name) {
    snprintf(&mNaviMesh[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2d50 __attribute__((used)) = &rStageCustomParts::Info::getNaviMeshName;

void rStageCustomParts::Info::setEpvName(const MtString& name) {
    snprintf(&mEpv[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2d60 __attribute__((used)) = &rStageCustomParts::Info::getEpvName;

void rStageCustomParts::Info::setOccluderName(const MtString& name) {
    snprintf(&mOccluder[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2d70 __attribute__((used)) = &rStageCustomParts::Info::getOccluderName;

u64 rStageCustomParts::Info::getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type) const {
    if (static_cast<unsigned int>(type) <= 2) {
        return mZoneUnitCtrl[type].getResId();
    } else {
        return 0;
    }
}

inline rStageCustomParts::Info::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomParts::Info::MyDTI rStageCustomParts::Info::DTI("rStageCustomParts::Info", &::MtObject::DTI, 832ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageCustomParts::Info::MyDTI::newInstance() const {
    DDON_STUB("rStageCustomParts::Info::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rStageCustomParts::Filter::getDTI() const {
    return rStageCustomParts::Filter::DTI;
}

rStageCustomParts::Filter::Filter() {
    clear();
}

void rStageCustomParts::Filter::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mFilter", reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Filter::getFilterName), reinterpret_cast<MT_MFUNC>(&::rStageCustomParts::Filter::setFilterName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* rStageCustomParts::Filter::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

bool rStageCustomParts::Filter::load(MtDataReader& r) {
    r.readString(&mFilter[0], 64u);
    return true;
}

bool rStageCustomParts::Filter::save(MtDataWriter& w) {
    w.writeString(&mFilter[0]);
    return true;
}

void rStageCustomParts::Filter::setFilterName(const MtString& name) {
    snprintf(&mFilter[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab2d90 __attribute__((used)) = &rStageCustomParts::Filter::getFilterName;

inline rStageCustomParts::Filter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomParts::Filter::MyDTI rStageCustomParts::Filter::DTI("rStageCustomParts::Filter", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* rStageCustomParts::Filter::MyDTI::newInstance() const {
    return new (16u) rStageCustomParts::Filter;
}

