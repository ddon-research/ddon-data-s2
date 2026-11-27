// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "rStageJoint.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtStlAllocator.h"
#include "../../MT/MtStlCustom.h"
#include "../../MT/MtString.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nZoneUnitCtrl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rStageJoint::getDTI() const {
    return rStageJoint::DTI;
}

__attribute__((noinline)) rStageJoint::~rStageJoint() {
    destruct();
}

MT_CTSTR rStageJoint::getExt() const {
    return "sja";
}

__attribute__((weak)) bool rStageJoint::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x616a73u) {
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
        pArrayInfo = getAllocator()->memAlloc(sizeof(Info) * nArrayInfo, 16u);
        for (u32 i = 0; i < nArrayInfo; i++) {
            Info* pInfo = new (static_cast<Info*>(pArrayInfo) + i) Info();
            pInfo->load(r);
        }
    }
    mPersistentInfo.load(r);
    mpArrayInfo = static_cast<Info*>(pArrayInfo);
    mArrayInfoNum = nArrayInfo;
    return true;
}

rStageJoint::Info* rStageJoint::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArrayInfo[index];
    } else {
        return nullptr;
    }
}

u32 rStageJoint::getInfoNum() const {
    return mArrayInfoNum;
}

inline rStageJoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageJoint::MyDTI rStageJoint::DTI("rStageJoint", &::cResource::DTI, 1064ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageJoint::MyDTI::newInstance() const {
    return new (16u) rStageJoint();
}

const MtDTI& rStageJoint::Param::getDTI() const {
    return rStageJoint::Param::DTI;
}

rStageJoint::Param::~Param() {
    if (mpArea != nullptr) {
        for (u32 i = 0; i < mAreaNumZ; i++) {
            getAllocator()->memFree(mpArea[i]);
        }
        getAllocator()->memFree(mpArea);
    }
    mpArea = nullptr;
    mAreaNumX = 0;
    mAreaNumZ = 0;
}

__attribute__((weak)) void rStageJoint::Param::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageJoint::Param::createProperty")
    /* stub */
}

MtUI* rStageJoint::Param::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rStageJoint::Param::load(MtDataReader& r) {
    u32 oldNumZ = mAreaNumZ;
    nDDOIO::readData(r, mStartX);
    nDDOIO::readData(r, mStartZ);
    nDDOIO::readData(r, mDeltaX);
    nDDOIO::readData(r, mDeltaZ);
    nDDOIO::readData(r, mAreaNumX);
    nDDOIO::readData(r, mAreaNumZ);
    // workaround
    u32 grid_size = mAreaNumX * mAreaNumX;
    if (grid_size != 0) {
        if (mpArea != nullptr) {
            for (u32 i = 0; i < oldNumZ; i++) {
                getAllocator()->memFree(mpArea[i]);
            }
            getAllocator()->memFree(mpArea);
        }
        mpArea = static_cast<s8**>(getAllocator()->memAlloc(sizeof(s8*) * mAreaNumZ, 16u));
        for (u32 i = 0; i < mAreaNumZ; i++) {
            mpArea[i] = static_cast<s8*>(getAllocator()->memAlloc(sizeof(s8) * mAreaNumX, 16u));
            memset(mpArea[i], -1, mAreaNumX);
        }
        for (u32 i = 0; i < mAreaNumZ; i++) {
            for (u32 j = 0; j < mAreaNumX; j++) {
                s8& t1 = mpArea[i][j];
                // workaround
                t1 = static_cast<s8>(r.readU8());
            }
        }
    } else {
        mpArea = nullptr;
    }
    return true;
}

__attribute__((weak)) void rStageJoint::Param::clear() {
    mStartX = 0.0f;
    mStartZ = 0.0f;
    mDeltaX = 100.0f;
    mDeltaZ = 100.0f;
    mAreaNumX = 1;
    mAreaNumZ = 1;
    if (mpArea != nullptr) {
        for (u32 i = 0; i < mAreaNumZ; i++) {
            getAllocator()->memFree(mpArea[i]);
        }
        getAllocator()->memFree(mpArea);
    }
    u32 size = mAreaNumX * mAreaNumZ;
    if (size != 0) {
        mpArea = static_cast<s8**>(getAllocator()->memAlloc(sizeof(s8*) * mAreaNumZ, 16u));
        for (u32 i = 0; i < mAreaNumZ; i++) {
            mpArea[i] = static_cast<s8*>(getAllocator()->memAlloc(sizeof(s8) * mAreaNumX, 16u));
            memset(mpArea[i], -1, mAreaNumX);
        }
    } else {
        mpArea = nullptr;
    }
}

__attribute__((weak)) void rStageJoint::Param::setAreaNumX(u32 numX) {
    DDON_STUB("rStageJoint::Param::setAreaNumX")
    /* stub */
}

static auto ddon_emit_0x01ab3180 __attribute__((used)) = &rStageJoint::Param::getAreaNumX;

__attribute__((weak)) void rStageJoint::Param::setAreaNumZ(u32 numZ) {
    DDON_STUB("rStageJoint::Param::setAreaNumZ")
    /* stub */
}

static auto ddon_emit_0x01ab3190 __attribute__((used)) = &rStageJoint::Param::getAreaNumZ;

__attribute__((weak)) void rStageJoint::Param::setAreaData(s8 val, u32 idx) {
    DDON_STUB("rStageJoint::Param::setAreaData")
    /* stub */
}

__attribute__((weak)) s8 rStageJoint::Param::getAreaData(u32 idx) const {
    DDON_STUB("rStageJoint::Param::getAreaData")
    return {};
}

s8 rStageJoint::Param::getAreaData(u32 z, u32 x) const {
    if (mpArea != nullptr) {
        if (z < mAreaNumZ) {
            if (x < mAreaNumX) {
                return mpArea[z][x];
            }
        }
    }
    return -1;
}

__attribute__((weak)) void rStageJoint::Param::setAreaNum(u32) {
}

static auto ddon_emit_0x01ab31a0 __attribute__((used)) = &rStageJoint::Param::getAreaNum;

inline rStageJoint::Param::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageJoint::Param::MyDTI rStageJoint::Param::DTI("rStageJoint::Param", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageJoint::Param::MyDTI::newInstance() const {
    DDON_STUB("rStageJoint::Param::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rStageJoint::Info::getDTI() const {
    return rStageJoint::Info::DTI;
}

rStageJoint::Info::~Info() {
}

void rStageJoint::Info::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mModel", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getModelName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setModelName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mScrSbc", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getScrSbcName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setScrSbcName), 160u, reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getScrSbcNameNum), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setScrSbcNameNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mEffSbc", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getEffSbcName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setEffSbcName), 160u, reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getEffSbcNameNum), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setEffSbcNameNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mLight", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getLightName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setLightName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mNaviMesh", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getNaviMeshName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setNaviMeshName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mPlantTree", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getPlantTreeName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setPlantTreeName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint[0], 32u, 16u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mEpv", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getEpvName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setEpvName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexAlways", &mEpvIndexAlways, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexDay", &mEpvIndexDay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexNight", &mEpvIndexNight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mSndInfo", reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::getSndInfoName), reinterpret_cast<MT_MFUNC>(&::rStageJoint::Info::setSndInfoName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mVersion", &mVersion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 0u, 0u);
}

MtUI* rStageJoint::Info::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rStageJoint::Info::load(MtDataReader& r) {
    nDDOIO::readData(r, mModel, sizeof(mModel));
    for (u32 i = 0; i < 3u; i++) {
        nDDOIO::readData(r, mScrSbc[i], sizeof(mScrSbc[i]));
        nDDOIO::readData(r, mEffSbc[i], sizeof(mEffSbc[i]));
    }
    nDDOIO::readData(r, mLight, sizeof(mLight));
    nDDOIO::readData(r, mNaviMesh, sizeof(mNaviMesh));
    nDDOIO::readData(r, mPlantTree, sizeof(mPlantTree));
    nDDOIO::readData(r, mSndInfo, sizeof(mSndInfo));
    for (u32 i = 0; i < JOINT_AREA_MAX; i++) {
        // workaround
        mJoint[i] = static_cast<s8>(r.readU8());
    }
    mColor = MtColor(r.readU32());
    nDDOIO::readData(r, mEpv, sizeof(mEpv));
    nDDOIO::readData(r, mEpvIndexAlways);
    nDDOIO::readData(r, mEpvIndexDay);
    nDDOIO::readData(r, mEpvIndexNight);
    nDDOIO::readData(r, mEfcColorZone);
    nDDOIO::readData(r, mEfcCtrlZone);
    nDDOIO::readData(r, mIndoorZoneScr);
    nDDOIO::readData(r, mIndoorZoneEfc);
    nDDOIO::readData(r, mLightAndFogZone);
    for (u32 i = 0; i < ZONE_UNIT_CTRL_TYPE_NUM; i++) {
        nDDOIO::readData(r, mZoneUnitCtrl[i]);
    }
    nDDOIO::readData(r, mZoneStatus);
    MT_CHAR t1[256];
    nDDOIO::readData(r, t1, sizeof(t1));
    mComment = t1;
    return true;
}

void rStageJoint::Info::setModelName(const MtString& name) {
    snprintf(&mModel[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab30f0 __attribute__((used)) = &rStageJoint::Info::getModelName;

void rStageJoint::Info::setScrSbcName(const MtString& name, u32 idx) {
    snprintf(reinterpret_cast<char*>(mScrSbc[idx]), 64ul, "%s", name.ptr());
}

__attribute__((weak)) MT_CTSTR rStageJoint::Info::getScrSbcName(u32 idx) const {
    DDON_STUB("rStageJoint::Info::getScrSbcName")
    return {};
}

__attribute__((weak)) void rStageJoint::Info::setScrSbcNameNum(u32) {
}

static auto ddon_emit_0x01ab30b0 __attribute__((used)) = &rStageJoint::Info::getScrSbcNameNum;

void rStageJoint::Info::setEffSbcName(const MtString& name, u32 idx) {
    snprintf(reinterpret_cast<char*>(mEffSbc[idx]), 64ul, "%s", name.ptr());
}

__attribute__((weak)) MT_CTSTR rStageJoint::Info::getEffSbcName(u32 idx) const {
    DDON_STUB("rStageJoint::Info::getEffSbcName")
    return {};
}

__attribute__((weak)) void rStageJoint::Info::setEffSbcNameNum(u32) {
}

static auto ddon_emit_0x01ab30d0 __attribute__((used)) = &rStageJoint::Info::getEffSbcNameNum;

void rStageJoint::Info::setLightName(const MtString& name) {
    snprintf(&mLight[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab3100 __attribute__((used)) = &rStageJoint::Info::getLightName;

void rStageJoint::Info::setNaviMeshName(const MtString& name) {
    snprintf(&mNaviMesh[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab3110 __attribute__((used)) = &rStageJoint::Info::getNaviMeshName;

void rStageJoint::Info::setPlantTreeName(const MtString& name) {
    snprintf(&mPlantTree[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab3120 __attribute__((used)) = &rStageJoint::Info::getPlantTreeName;

void rStageJoint::Info::setEpvName(const MtString& name) {
    snprintf(&mEpv[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab3130 __attribute__((used)) = &rStageJoint::Info::getEpvName;

void rStageJoint::Info::setSndInfoName(const MtString& name) {
    snprintf(&mSndInfo[0], 64ul, "%s", name.ptr());
}

static auto ddon_emit_0x01ab3140 __attribute__((used)) = &rStageJoint::Info::getSndInfoName;

u64 rStageJoint::Info::getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type) const {
    if (static_cast<unsigned int>(type) <= 2) {
        return mZoneUnitCtrl[type].getResId();
    } else {
        return 0;
    }
}

bool rStageJoint::Info::hasInfo() const {
    const char* v0_1 = &mScrSbc[0][0];
    unsigned int i0_2 = 0;
    bool b1_0;
    for (;;) {
        if ((*v0_1) != 0) {
            b1_0 = true;
            return b1_0;
        } else {
            if ((i0_2 + 1u) <= 2u) {
                v0_1 += 64;
                i0_2 += 1u;
            } else {
                b1_0 = true;
                break;
            }
        }
    }
    const char* v2_1 = &mEffSbc[0][0];
    for (unsigned int i2_2 = 0; i2_2 <= 2u; v2_1 += 64, i2_2 += 1u) {
        if ((*v2_1) != 0) {
            return b1_0;
        }
    }
    if (mModel[0] == 0) {
        if (mLight[0] == 0) {
            if (mNaviMesh[0] == 0) {
                if (mPlantTree[0] == 0) {
                    if (mEpv[0] == 0) {
                        if (mSndInfo[0] == 0) {
                            if (mEfcColorZone.mId == 0) {
                                if (mEfcCtrlZone.mId == 0) {
                                    if (mIndoorZoneScr.mId == 0) {
                                        if (mIndoorZoneEfc.mId == 0) {
                                            if (mLightAndFogZone.mId == 0) {
                                                if (mZoneStatus.mId == 0) {
                                                    unsigned int i4_1 = 0;
                                                    for (const cResPathEx* p4_3 = &mZoneUnitCtrl[0]; i4_1 <= 2u; i4_1 += 1u, p4_3 += 1) {
                                                        if (p4_3->mId != 0) {
                                                            return b1_0;
                                                        }
                                                    }
                                                    b1_0 = false;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return b1_0;
}

inline rStageJoint::Info::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageJoint::Info::MyDTI rStageJoint::Info::DTI("rStageJoint::Info", &::MtObject::DTI, 896ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageJoint::Info::MyDTI::newInstance() const {
    DDON_STUB("rStageJoint::Info::MyDTI::newInstance")
    return nullptr;
}

