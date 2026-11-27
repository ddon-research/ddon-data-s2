// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundAreaInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "../../XFramework/rZone.h"
#include "res_ptr.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rSoundAreaInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundAreaInfo::DTI)->memAlloc(sz, align, rSoundAreaInfo::DTI.mID);
}

const MtDTI& rSoundAreaInfo::getDTI() const {
    return rSoundAreaInfo::DTI;
}

__attribute__((noinline)) rSoundAreaInfo::~rSoundAreaInfo() {
    clear();
}

void rSoundAreaInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAmb", &mIsAmb, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DayBgm", &mDayBgmNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NightBgm", &mNightBgmNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NoramlBgm", &mBgmNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BgmStqr", "resource", static_cast<void*>(&mpBgmSTQRes), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSecond", &mIsSecond, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAmb2", &mIsAmb2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DayBgm2", &mDayBgmNo2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NightBgm2", &mNightBgmNo2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NoramlBgm2", &mBgmNo2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\210\246\351\227\230", &mBtlBgmNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\242\343\202\246\343\203\210\343\203\255", &mBtlBgmOutroNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BattleBgmStqr", "resource", static_cast<void*>(&mpBtlBgmSTQRes), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCycle", &mIsCycle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CycleBgm", &mCycleBgmNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CycleBgmStqr", "resource", static_cast<void*>(&mpCycleBgmSTQRes), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "EqLength", &mEqLength[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneOcclusion", "resource", static_cast<void*>(&mpSndZoneRes[0]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneGenerator", "resource", static_cast<void*>(&mpSndZoneRes[1]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneTrigger", "resource", static_cast<void*>(&mpSndZoneRes[2]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsSoil", &mIsAttribute[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SoilRes", "resource", static_cast<void*>(&mpAttributeSTQRes[0]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsSand", &mIsAttribute[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SandRes", "resource", static_cast<void*>(&mpAttributeSTQRes[1]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsBog", &mIsAttribute[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BogRes", "resource", static_cast<void*>(&mpAttributeSTQRes[2]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsStone", &mIsAttribute[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "StoneRes", "resource", static_cast<void*>(&mpAttributeSTQRes[3]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsWood", &mIsAttribute[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "WoodRes", "resource", static_cast<void*>(&mpAttributeSTQRes[4]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsIron", &mIsAttribute[5], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IronRes", "resource", static_cast<void*>(&mpAttributeSTQRes[5]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsGrass", &mIsAttribute[6], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GrassRes", "resource", static_cast<void*>(&mpAttributeSTQRes[6]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsCloth", &mIsAttribute[7], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ClothRes", "resource", static_cast<void*>(&mpAttributeSTQRes[7]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsTree", &mIsAttribute[8], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TreeRes", "resource", static_cast<void*>(&mpAttributeSTQRes[8]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsCarpe", &mIsAttribute[9], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CarpeRes", "resource", static_cast<void*>(&mpAttributeSTQRes[9]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsRock", &mIsAttribute[10], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RockRes", "resource", static_cast<void*>(&mpAttributeSTQRes[10]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeadLeaf", &mIsAttribute[11], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeadLeafRes", "resource", static_cast<void*>(&mpAttributeSTQRes[11]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsBone", &mIsAttribute[12], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BoneRes", "resource", static_cast<void*>(&mpAttributeSTQRes[12]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsGrave", &mIsAttribute[13], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GraveRes", "resource", static_cast<void*>(&mpAttributeSTQRes[13]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsMud", &mIsAttribute[14], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "MudRes", "resource", static_cast<void*>(&mpAttributeSTQRes[14]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsWater", &mIsAttribute[15], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "WaterRes", "resource", static_cast<void*>(&mpAttributeSTQRes[15]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsStraw", &mIsAttribute[16], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "StrawRes", "resource", static_cast<void*>(&mpAttributeSTQRes[16]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsRoofTile", &mIsAttribute[17], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RoofTileRes", "resource", static_cast<void*>(&mpAttributeSTQRes[17]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsMagicSpa", &mIsAttribute[18], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "MagicSpaRes", "resource", static_cast<void*>(&mpAttributeSTQRes[18]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsPoisonBog", &mIsAttribute[19], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PoisonBogRes", "resource", static_cast<void*>(&mpAttributeSTQRes[19]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsTar", &mIsAttribute[20], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TarRes", "resource", static_cast<void*>(&mpAttributeSTQRes[20]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeepBog", &mIsAttribute[21], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeepBogRes", "resource", static_cast<void*>(&mpAttributeSTQRes[21]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeepWater", &mIsAttribute[22], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeepWaterRes", "resource", static_cast<void*>(&mpAttributeSTQRes[22]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeepMagicSpa", &mIsAttribute[23], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeepMagicSpaRes", "resource", static_cast<void*>(&mpAttributeSTQRes[23]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeepPoisonBog", &mIsAttribute[24], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeepPoisonBogRes", "resource", static_cast<void*>(&mpAttributeSTQRes[24]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsDeepTar", &mIsAttribute[25], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DeepTarRes", "resource", static_cast<void*>(&mpAttributeSTQRes[25]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra01", &mIsAttribute[26], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra01Res", "resource", static_cast<void*>(&mpAttributeSTQRes[26]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra02", &mIsAttribute[27], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra02Res", "resource", static_cast<void*>(&mpAttributeSTQRes[27]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra03", &mIsAttribute[28], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra03Res", "resource", static_cast<void*>(&mpAttributeSTQRes[28]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra04", &mIsAttribute[29], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra04Res", "resource", static_cast<void*>(&mpAttributeSTQRes[29]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra05", &mIsAttribute[30], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra05Res", "resource", static_cast<void*>(&mpAttributeSTQRes[30]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "IsExtra06", &mIsAttribute[31], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Extra06Res", "resource", static_cast<void*>(&mpAttributeSTQRes[31]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "AmbientRes", "resource", static_cast<void*>(&mpAmbientRes), 0u, 0u);
}

MT_CTSTR rSoundAreaInfo::getExt() const {
    return "sar";
}

__attribute__((weak)) bool rSoundAreaInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    u32 magic = r.readU32();
    u32 version = r.readU32();
    char t0[64];
    const MtDTI* t1;
    if (magic != 0x726173u || version != DATA_VERSION) {
        return false;
    }
    nDDOIO::readData(r, mStageNo);
    nDDOIO::readData(r, mAreaNo);
    nDDOIO::readData(r, mIsAmb);
    nDDOIO::readData(r, mBgmNo);
    nDDOIO::readData(r, mDayBgmNo);
    nDDOIO::readData(r, mNightBgmNo);
    nDDOIO::readData(r, mIsSecond);
    nDDOIO::readData(r, mIsAmb2);
    nDDOIO::readData(r, mBgmNo2);
    nDDOIO::readData(r, mDayBgmNo2);
    nDDOIO::readData(r, mNightBgmNo2);
    nDDOIO::readData(r, mIsCycle);
    nDDOIO::readData(r, mCycleBgmNo);
    nDDOIO::readData(r, mBtlBgmNo);
    nDDOIO::readData(r, mBtlBgmOutroNo);
    for (u32 i = 0; i < 4u; i++) {
        nDDOIO::readData(r, mEqLength[i]);
    }
    for (u32 i = 0; i < 3u; i++) {
        r.readString(t0, 64u);
        if (t0[0] != '\0') {
            t1 = MtDTI::from(t0, cResource::DTI);
            r.readString(t0, 64u);
            mpSndZoneRes[i].mpPtr = static_cast<rZone*>(sResource::getInstance()->create(*t1, t0, 1u));
        }
    }
    for (u32 i = 0; i < ATTRIBUTE_NUM_MAX; i++) {
        nDDOIO::readData(r, mIsAttribute[i]);
        r.readString(t0, 64u);
        if (t0[0] != '\0') {
            t1 = MtDTI::from(t0, cResource::DTI);
            r.readString(t0, 64u);
            mpAttributeSTQRes[i].mpPtr = static_cast<rSoundRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
        }
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpAmbientRes.mpPtr = static_cast<rSoundRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpBgmSTQRes.mpPtr = static_cast<rSoundStreamRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpCycleBgmSTQRes.mpPtr = static_cast<rSoundStreamRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpBtlBgmSTQRes.mpPtr = static_cast<rSoundStreamRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    return true;
}

__attribute__((weak)) bool rSoundAreaInfo::save(MtStream& out) {
    u32 version = DATA_VERSION;
    u32 magic = 0x726173u;
    MtDataWriter w(out, 4096u, 4096u);
    cResource* t0;
    nDDOIO::writeData(w, magic);
    nDDOIO::writeData(w, version);
    nDDOIO::writeData(w, mStageNo);
    nDDOIO::writeData(w, mAreaNo);
    nDDOIO::writeData(w, mIsAmb);
    nDDOIO::writeData(w, mBgmNo);
    nDDOIO::writeData(w, mDayBgmNo);
    nDDOIO::writeData(w, mNightBgmNo);
    nDDOIO::writeData(w, mIsSecond);
    nDDOIO::writeData(w, mIsAmb2);
    nDDOIO::writeData(w, mBgmNo2);
    nDDOIO::writeData(w, mDayBgmNo2);
    nDDOIO::writeData(w, mNightBgmNo2);
    nDDOIO::writeData(w, mIsCycle);
    nDDOIO::writeData(w, mCycleBgmNo);
    nDDOIO::writeData(w, mBtlBgmNo);
    nDDOIO::writeData(w, mBtlBgmOutroNo);
    for (u32 i = 0; i < 4u; i++) {
        nDDOIO::writeData(w, mEqLength[i]);
    }
    for (u32 i = 0; i < 3u; i++) {
        t0 = mpSndZoneRes[i].mpPtr;
        if (t0 != nullptr) {
            w.writeString(t0->getDTI().getName());
            w.writeString(t0->getPath());
        } else {
            w.writeString("");
        }
    }
    for (u32 i = 0; i < ATTRIBUTE_NUM_MAX; i++) {
        nDDOIO::writeData(w, mIsAttribute[i]);
        t0 = mpAttributeSTQRes[i].mpPtr;
        if (t0 != nullptr) {
            w.writeString(t0->getDTI().getName());
            w.writeString(t0->getPath());
        } else {
            w.writeString("");
        }
    }
    t0 = mpAmbientRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpBgmSTQRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpCycleBgmSTQRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpBtlBgmSTQRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    return true;
}

__attribute__((weak)) void rSoundAreaInfo::clear() {
    f32 EQTable[4] = {1200.0f, 2000.0f, 2800.0f, 4000.0f};
    mStageNo = -1;
    mAreaNo = -1;
    mIsAmb = false;
    mBgmNo = 0xFFFFFFFFu;
    mDayBgmNo = 0xFFFFFFFFu;
    mNightBgmNo = 0xFFFFFFFFu;
    mIsSecond = false;
    mIsAmb2 = false;
    mBgmNo2 = 0xFFFFFFFFu;
    mDayBgmNo2 = 0xFFFFFFFFu;
    mNightBgmNo2 = 0xFFFFFFFFu;
    mCycleBgmNo = 0xFFFFFFFFu;
    mBtlBgmNo = 0xFFFFFFFFu;
    mBtlBgmOutroNo = 0xFFFFFFFFu;
    mIsCycle = false;
    for (u32 i = 0; i < 4u; i++) {
        mEqLength[i] = EQTable[i];
    }
    for (u32 i = 0; i < 3u; i++) {
        mpSndZoneRes[i].releasePtr();
    }
    for (u32 i = 0; i < ATTRIBUTE_NUM_MAX; i++) {
        mIsAttribute[i] = false;
        mpAttributeSTQRes[i].releasePtr();
    }
    mpBgmSTQRes.releasePtr();
    mpCycleBgmSTQRes.releasePtr();
}

rSoundRequest* rSoundAreaInfo::getAttributeRes(u32 index) {
    if (index <= 31u) {
        return mpAttributeSTQRes[index].mpPtr;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) rSoundRequest* rSoundAreaInfo::getAttributeResToScrAttr(u32 scrAttr) {
    DDON_STUB("rSoundAreaInfo::getAttributeResToScrAttr")
    return nullptr;
}

inline rSoundAreaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundAreaInfo::MyDTI rSoundAreaInfo::DTI("rSoundAreaInfo", &::cResource::DTI, 528ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundAreaInfo::MyDTI::newInstance() const {
    return new (16u) rSoundAreaInfo;
}

