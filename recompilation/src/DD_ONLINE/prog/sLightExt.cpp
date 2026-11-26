// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sLightExt.h"
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
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTable.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cActorLight::getDTI() const {
    return cActorLight::DTI;
}

s32 cActorLight::getStageNo() {
    return mStageNo;
}

void cActorLight::setStageNo(s32 no) {
    mStageNo = no;
}

void cActorLight::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mStageNo", reinterpret_cast<MT_MFUNC>(&::cActorLight::getStageNo), reinterpret_cast<MT_MFUNC>(&::cActorLight::setStageNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup0", &mShadowAtten.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup1", &mShadowAtten.y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStart", &mStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnd", &mEnd, 0u, 0u);
}

MtUI* cActorLight::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cActorLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cActorLight::MyDTI cActorLight::DTI("cActorLight", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cActorLight::MyDTI::newInstance() const {
    return new (16u) cActorLight;
}

const MtDTI& rActorLight::getDTI() const {
    return rActorLight::DTI;
}

inline void* rActorLight::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rActorLight::DTI)->memAlloc(sz, align, rActorLight::DTI.getID());
}

inline void rActorLight::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rActorLight::DTI)->memFree(p_addr);
}

inline rActorLight::rActorLight() {
    setAttribute(16u);
}

const MtDTI& rActorLight::getDataDTI() {
    return cActorLight::DTI;
}

MT_CTSTR rActorLight::getExt() const {
    return "ali";
}

u16 rActorLight::getDataVersion() {
    return 1;
}

bool rActorLight::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    return loadData(r);
}

__attribute__((weak)) bool rActorLight::loadData(MtDataReader& in) {
    bool ret = false;
    u32 magic = in.readU32();
    u32 version = in.readU16();
    if (magic == rTable::mMagic && version == cActorLight::DATA_VERSION) {
        u32 dmy = in.readU16();
        u32 Num = in.readU32();
        for (u32 i = 0; i < Num; i++) {
            cActorLight* pObj = new (16u) cActorLight;
            if (pObj != nullptr) {
                if (loadData(in, pObj)) {
                    mArray.add(pObj);
                }
            }
        }
        ret = true;
    }
    return ret;
}

__attribute__((weak)) bool rActorLight::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    return saveData(w);
}

inline rActorLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rActorLight::MyDTI rActorLight::DTI("rActorLight", &::rTable::DTI, 176ul, 0u, 0u);

MtObject* rActorLight::MyDTI::newInstance() const {
    return new (16u) rActorLight;
}

