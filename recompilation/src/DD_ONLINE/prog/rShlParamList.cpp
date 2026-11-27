// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rShlParamList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlGroupParam::getDTI() const {
    return cShlGroupParam::DTI;
}

__attribute__((noinline)) cShlGroupParam::~cShlGroupParam() {
    mShlList.deleteAll(true);
}

void cShlGroupParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "name", &name, 8192u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Num", reinterpret_cast<MT_MFUNC>(&::cShlGroupParam::getParamNum), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "epvPath", &epvPath[0], 32u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "sePath", &sePath[0], 32u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "colPath", &colPath, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ddoVersion", &ddoVersion, 8192u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seOption", &seOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isNoArc", &isNoArc, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlList", static_cast<MtObject*>(&mShlList), 0u, 0u);
}

const cShlParamBase* cShlGroupParam::getParam(u32 index) const {
    if (index < mShlList.mLength) {
        return static_cast<const cShlParamBase*>(mShlList.mpArray[index]);
    } else {
        return nullptr;
    }
}

static auto ddon_emit_0x01ab0d60 __attribute__((used)) = &cShlGroupParam::getParamNum;

inline cShlGroupParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlGroupParam::MyDTI cShlGroupParam::DTI("cShlGroupParam", &::MtObject::DTI, 104ul, 0u, 0u);

MtObject* cShlGroupParam::MyDTI::newInstance() const {
    return new (16u) cShlGroupParam;
}

const MtDTI& rShlParamList::getDTI() const {
    return rShlParamList::DTI;
}

__attribute__((noinline)) rShlParamList::~rShlParamList() {
    mParamList.deleteAll(true);
}

void rShlParamList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mParamList", static_cast<MtObject*>(&mParamList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCmnEpvPath", &mCmnEpvPath, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCmnSePath", &mCmnSePath, 0u, 0u);
}

__attribute__((weak)) void rShlParamList::clear() {
}

bool rShlParamList::load(MtStream& in) {
    MtSerializer sz(65536);
    bool b4_11;
    if (sz.deserializeBinary(in, static_cast<u16>(31), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) == nullptr) {
        b4_11 = false;
    } else {
        unsigned int v0_6 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 120);
        if (v0_6 == 0) {
            b4_11 = true;
        } else {
            unsigned long v0_1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 136);
            unsigned int i0_2 = 0;
            unsigned long v1_1;
            unsigned int v1_3;
            for (;;) {
                unsigned long v1_2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_1 + static_cast<unsigned long>(i0_2 * 8u)) + 0);
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_2) + 16)) != 0) {
                    v1_1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v1_2) + 32);
                    v1_3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_2) + 16);
                    for (;;) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v1_1) + 0)) != 0) {
                            *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v1_1) + 0)) + 344) = v1_2;
                        }
                        if ((v1_3 - 1u) != 0) {
                            v1_1 += 8ul;
                            v1_3 += 0xFFFFFFFFu;
                        } else {
                            break;
                        }
                    }
                }
                if (v0_6 != (i0_2 + 1u)) {
                    i0_2 = i0_2 + 1u;
                } else {
                    b4_11 = true;
                    break;
                }
            }
        }
    }
    return b4_11;
}

bool rShlParamList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(31), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rShlParamList::DTI));
}

MT_CTSTR rShlParamList::getExt() const {
    return "shl";
}

__attribute__((weak)) const cShlParamBase* rShlParamList::getParam(u32 group, u32 index) const {
    DDON_STUB("rShlParamList::getParam")
    return nullptr;
}

inline rShlParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShlParamList::MyDTI rShlParamList::DTI("rShlParamList", &::cResource::DTI, 160ul, 0u, 0u);

MtObject* rShlParamList::MyDTI::newInstance() const {
    return new (16u) rShlParamList;
}

