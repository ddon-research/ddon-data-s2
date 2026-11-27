// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNamedParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cNamedParam::getDTI() const {
    return cNamedParam::DTI;
}

void* cNamedParam::operator new(size_t sz, u32 align) {
    return cNamedParam::getAllocator()->memAlloc(sz, align, cNamedParam::DTI.getID());
}

cNamedParam::cNamedParam() {
    this->mID = 0;
    this->mType = NAMED_TYPE_NONE;
    this->mHpRate = 100;
    this->mExperience = 100;
    this->mAttackBasePhys = 100;
    this->mAttackWepPhys = 100;
    this->mDefenceBasePhys = 100;
    this->mDefenceWepPhys = 100;
    this->mAttackBaseMagic = 100;
    this->mAttackWepMagic = 100;
    this->mDefenceBaseMagic = 100;
    this->mDefenceWepMagic = 100;
    this->mPower = 100;
    this->mGuardDefenceBase = 100;
    this->mGuardDefenceWep = 100;
    this->mShrinkEnduranceMain = 100;
    this->mBlowEnduranceMain = 100;
    this->mDownEnduranceMain = 100;
    this->mShakeEnduranceMain = 100;
    this->mHpSub = 100;
    this->mShrinkEnduranceSub = 100;
    this->mBlowEnduranceSub = 100;
    this->mOcdEndurance = 100;
    this->mAilmentDamage = 100;
}

void cNamedParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mID", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getID), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setID), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mType", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getType), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mHpRate", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getHpRate), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setHpRate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mExperience", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getExperience), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setExperience), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mAttackBasePhys", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getAttackBasePhys), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setAttackBasePhys), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mAttackWepPhys", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getAttackWepPhys), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setAttackWepPhys), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mDefenceBasePhys", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getDefenceBasePhys), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setDefenceBasePhys), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mDefenceWepPhys", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getDefenceWepPhys), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setDefenceWepPhys), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mAttackBaseMagic", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getAttackBaseMagic), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setAttackBaseMagic), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mAttackWepMagic", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getAttackWepMagic), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setAttackWepMagic), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mDefenceBaseMagic", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getDefenceBaseMagic), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setDefenceBaseMagic), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mDefenceWepMagic", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getDefenceWepMagic), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setDefenceWepMagic), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mPower", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getPower), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setPower), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mGuardDefenceBase", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getGuardDefenceBase), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setGuardDefenceBase), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mGuardDefenceWep", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getGuardDefenceWep), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setGuardDefenceWep), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mShrinkEnduranceMain", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getShrinkEnduranceMain), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setShrinkEnduranceMain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mBlowEnduranceMain", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getBlowEnduranceMain), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setBlowEnduranceMain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mDownEnduranceMain", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getDownEnduranceMain), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setDownEnduranceMain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mShakeEnduranceMain", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getShakeEnduranceMain), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setShakeEnduranceMain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mHpSub", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getHpSub), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setHpSub), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mShrinkEnduranceSub", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getShrinkEnduranceSub), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setShrinkEnduranceSub), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mBlowEnduranceSub", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getBlowEnduranceSub), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setBlowEnduranceSub), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mOcdEndurance", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getOcdEndurance), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setOcdEndurance), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mAilmentDamage", reinterpret_cast<MT_MFUNC>(&::cNamedParam::getAilmentDamage), reinterpret_cast<MT_MFUNC>(&::cNamedParam::setAilmentDamage), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

static auto ddon_emit_0x01a9dca0 __attribute__((used)) = &cNamedParam::getID;

static auto ddon_emit_0x01a9db20 __attribute__((used)) = &cNamedParam::setID;

static auto ddon_emit_0x01a9dcb0 __attribute__((used)) = &cNamedParam::getType;

static auto ddon_emit_0x01a9db30 __attribute__((used)) = &cNamedParam::setType;

static auto ddon_emit_0x01a9dcc0 __attribute__((used)) = &cNamedParam::getHpRate;

static auto ddon_emit_0x01a9db40 __attribute__((used)) = &cNamedParam::setHpRate;

static auto ddon_emit_0x01a9dcd0 __attribute__((used)) = &cNamedParam::getExperience;

static auto ddon_emit_0x01a9db50 __attribute__((used)) = &cNamedParam::setExperience;

static auto ddon_emit_0x01a9dce0 __attribute__((used)) = &cNamedParam::getAttackBasePhys;

static auto ddon_emit_0x01a9db60 __attribute__((used)) = &cNamedParam::setAttackBasePhys;

static auto ddon_emit_0x01a9dcf0 __attribute__((used)) = &cNamedParam::getAttackWepPhys;

static auto ddon_emit_0x01a9db70 __attribute__((used)) = &cNamedParam::setAttackWepPhys;

static auto ddon_emit_0x01a9dd00 __attribute__((used)) = &cNamedParam::getDefenceBasePhys;

static auto ddon_emit_0x01a9db80 __attribute__((used)) = &cNamedParam::setDefenceBasePhys;

static auto ddon_emit_0x01a9dd10 __attribute__((used)) = &cNamedParam::getDefenceWepPhys;

static auto ddon_emit_0x01a9db90 __attribute__((used)) = &cNamedParam::setDefenceWepPhys;

static auto ddon_emit_0x01a9dd20 __attribute__((used)) = &cNamedParam::getAttackBaseMagic;

static auto ddon_emit_0x01a9dba0 __attribute__((used)) = &cNamedParam::setAttackBaseMagic;

static auto ddon_emit_0x01a9dd30 __attribute__((used)) = &cNamedParam::getAttackWepMagic;

static auto ddon_emit_0x01a9dbb0 __attribute__((used)) = &cNamedParam::setAttackWepMagic;

static auto ddon_emit_0x01a9dd40 __attribute__((used)) = &cNamedParam::getDefenceBaseMagic;

static auto ddon_emit_0x01a9dbc0 __attribute__((used)) = &cNamedParam::setDefenceBaseMagic;

static auto ddon_emit_0x01a9dd50 __attribute__((used)) = &cNamedParam::getDefenceWepMagic;

static auto ddon_emit_0x01a9dbd0 __attribute__((used)) = &cNamedParam::setDefenceWepMagic;

static auto ddon_emit_0x01a9dd60 __attribute__((used)) = &cNamedParam::getPower;

static auto ddon_emit_0x01a9dbe0 __attribute__((used)) = &cNamedParam::setPower;

static auto ddon_emit_0x01a9dd70 __attribute__((used)) = &cNamedParam::getGuardDefenceBase;

static auto ddon_emit_0x01a9dbf0 __attribute__((used)) = &cNamedParam::setGuardDefenceBase;

static auto ddon_emit_0x01a9dd80 __attribute__((used)) = &cNamedParam::getGuardDefenceWep;

static auto ddon_emit_0x01a9dc00 __attribute__((used)) = &cNamedParam::setGuardDefenceWep;

static auto ddon_emit_0x01a9dd90 __attribute__((used)) = &cNamedParam::getShrinkEnduranceMain;

static auto ddon_emit_0x01a9dc10 __attribute__((used)) = &cNamedParam::setShrinkEnduranceMain;

static auto ddon_emit_0x01a9dda0 __attribute__((used)) = &cNamedParam::getBlowEnduranceMain;

static auto ddon_emit_0x01a9dc20 __attribute__((used)) = &cNamedParam::setBlowEnduranceMain;

static auto ddon_emit_0x01a9ddb0 __attribute__((used)) = &cNamedParam::getDownEnduranceMain;

static auto ddon_emit_0x01a9dc30 __attribute__((used)) = &cNamedParam::setDownEnduranceMain;

static auto ddon_emit_0x01a9ddc0 __attribute__((used)) = &cNamedParam::getShakeEnduranceMain;

static auto ddon_emit_0x01a9dc70 __attribute__((used)) = &cNamedParam::setShakeEnduranceMain;

static auto ddon_emit_0x01a9ddd0 __attribute__((used)) = &cNamedParam::getHpSub;

static auto ddon_emit_0x01a9dc40 __attribute__((used)) = &cNamedParam::setHpSub;

static auto ddon_emit_0x01a9dde0 __attribute__((used)) = &cNamedParam::getShrinkEnduranceSub;

static auto ddon_emit_0x01a9dc50 __attribute__((used)) = &cNamedParam::setShrinkEnduranceSub;

static auto ddon_emit_0x01a9ddf0 __attribute__((used)) = &cNamedParam::getBlowEnduranceSub;

static auto ddon_emit_0x01a9dc60 __attribute__((used)) = &cNamedParam::setBlowEnduranceSub;

static auto ddon_emit_0x01a9de00 __attribute__((used)) = &cNamedParam::getOcdEndurance;

static auto ddon_emit_0x01a9dc80 __attribute__((used)) = &cNamedParam::setOcdEndurance;

static auto ddon_emit_0x01a9de10 __attribute__((used)) = &cNamedParam::getAilmentDamage;

static auto ddon_emit_0x01a9dc90 __attribute__((used)) = &cNamedParam::setAilmentDamage;

inline cNamedParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cNamedParam::MyDTI cNamedParam::DTI("cNamedParam", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cNamedParam::MyDTI::newInstance() const {
    DDON_STUB("cNamedParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rNamedParam::getDTI() const {
    return rNamedParam::DTI;
}

bool rNamedParam::loadData(MtDataReader& in, cNamedParam* pData) {
    if (pData != nullptr) {
        pData->mID = in.readU32();
        pData->mType = in.readU32();
        pData->mHpRate = in.readU32();
        pData->mExperience = in.readU16();
        pData->mAttackBasePhys = in.readU16();
        pData->mAttackWepPhys = in.readU16();
        pData->mDefenceBasePhys = in.readU16();
        pData->mDefenceWepPhys = in.readU16();
        pData->mAttackBaseMagic = in.readU16();
        pData->mAttackWepMagic = in.readU16();
        pData->mDefenceBaseMagic = in.readU16();
        pData->mDefenceWepMagic = in.readU16();
        pData->mPower = in.readU16();
        pData->mGuardDefenceBase = in.readU16();
        pData->mGuardDefenceWep = in.readU16();
        pData->mShrinkEnduranceMain = in.readU16();
        pData->mBlowEnduranceMain = in.readU16();
        pData->mDownEnduranceMain = in.readU16();
        pData->mShakeEnduranceMain = in.readU16();
        pData->mHpSub = in.readU16();
        pData->mShrinkEnduranceSub = in.readU16();
        pData->mBlowEnduranceSub = in.readU16();
        pData->mOcdEndurance = in.readU16();
        pData->mAilmentDamage = in.readU16();
        if (pData->mHpRate == 0) {
            pData->mHpRate = 1;
        }
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rNamedParam::getExt() const {
    return "ndp";
}

u32 rNamedParam::getDataVersion() const {
    return 5;
}

inline rNamedParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNamedParam::MyDTI rNamedParam::DTI("rNamedParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rNamedParam::MyDTI::newInstance() const {
    return new (16u) rNamedParam;
}

template cNamedParam* rTbl2<cNamedParam>::getData(unsigned int);

template bool rTbl2<cNamedParam>::load(MtStream&);

template bool rTbl2<cNamedParam>::loadCore(MtDataReader&);

template const cNamedParam* rTbl2<cNamedParam>::getData(unsigned int) const;

template unsigned int rTbl2<cNamedParam>::getDataNum() const;

template rTbl2<cNamedParam>::~rTbl2();

