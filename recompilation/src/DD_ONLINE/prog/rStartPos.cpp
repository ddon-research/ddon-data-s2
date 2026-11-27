// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStartPos.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) MtVector3 cStartPos::getPos(u32 no) const {
    DDON_STUB("cStartPos::getPos")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 cStartPos::getAng(u32 no) const {
    DDON_STUB("cStartPos::getAng")
    __builtin_unreachable();
}

const MtDTI& rStartPos::getDTI() const {
    return rStartPos::DTI;
}

rStartPos::~rStartPos() {
    if (mInfoList.mLength != 0) {
        u32 v0_0 = mInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mInfoList.mpArray[i0_3];
                mInfoList.mpArray[i0_3] = nullptr;
                v1_0 = mInfoList.mLength;
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

MT_CTSTR rStartPos::getExt() const {
    return "stp";
}

MT_CTSTR rStartPos::getName() const {
    return "rStartPos";
}

void rStartPos::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "InfoList", static_cast<MtObject*>(&mInfoList), 1024u, 0u);
}

MtUI* rStartPos::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rStartPos::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(2), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rStartPos::save(MtStream& out) {
    MtSerializer sz(65536);
    sz.serializeBinary(out, static_cast<u16>(2), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
    return true;
}

__attribute__((weak)) void rStartPos::getData(cStartPos& data, u32 posNo) {
    DDON_STUB("rStartPos::getData")
    /* stub */
}

inline rStartPos::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStartPos::MyDTI rStartPos::DTI("rStartPos", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rStartPos::MyDTI::newInstance() const {
    return new (16u) rStartPos;
}

const MtDTI& rStartPos::Info::getDTI() const {
    return rStartPos::Info::DTI;
}

rStartPos::Info::~Info() {
}

void rStartPos::Info::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Pos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ang", &mAng, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "OfsPos", reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::getOfsPos), reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::setOfsPos), 160u, reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::getOfsPosNum), reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::setOfsPosNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "OfsAng", reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::getOfsAng), reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::setOfsAng), 160u, reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::getOfsAngNum), reinterpret_cast<MT_MFUNC>(&::rStartPos::Info::setOfsAngNum));
}

MtVector3 rStartPos::Info::getOfsPos(u32 idx) const {
    return mOfsPos[idx];
}

void rStartPos::Info::setOfsPos(MtVector3& ofs, u32 idx) {
    mOfsPos[idx] = ofs;
}

static auto ddon_emit_0x01ab3de0 __attribute__((used)) = &rStartPos::Info::getOfsPosNum;

__attribute__((weak)) void rStartPos::Info::setOfsPosNum(u32 num) {
}

static auto ddon_emit_0x01ab3e00 __attribute__((used)) = &rStartPos::Info::getOfsAng;

static auto ddon_emit_0x01ab3e10 __attribute__((used)) = &rStartPos::Info::setOfsAng;

static auto ddon_emit_0x01ab3e20 __attribute__((used)) = &rStartPos::Info::getOfsAngNum;

__attribute__((weak)) void rStartPos::Info::setOfsAngNum(u32 num) {
}

inline rStartPos::Info::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStartPos::Info::MyDTI rStartPos::Info::DTI("rStartPos::Info", &::MtObject::DTI, 192ul, 0u, 0u);

MtObject* rStartPos::Info::MyDTI::newInstance() const {
    return new (16u) rStartPos::Info;
}

