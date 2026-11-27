// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTexDetailEdit.h"
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
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rTexDetailEdit::getDTI() const {
    return rTexDetailEdit::DTI;
}

rTexDetailEdit::~rTexDetailEdit() {
    if (mEditList.mLength != 0) {
        u32 v0_0 = mEditList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mEditList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mEditList.mpArray[i0_3];
                v1_0 = mEditList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mEditList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEditList.mpArray));
    }
    mEditList.mpArray = nullptr;
    mEditList.mBufsiz = 0;
    mEditList.mLength = 0;
}

void rTexDetailEdit::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEditList", static_cast<MtObject*>(&mEditList), 0u, 0u);
}

MtUI* rTexDetailEdit::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rTexDetailEdit::create() {
    clear();
    return true;
}

void rTexDetailEdit::clear() {
    if (mEditList.mLength != 0) {
        u32 v0_0 = mEditList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mEditList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mEditList.mpArray[i0_3];
                v1_0 = mEditList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mEditList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEditList.mpArray));
    }
    mEditList.mpArray = nullptr;
    mEditList.mBufsiz = 0;
    mEditList.mLength = 0;
}

bool rTexDetailEdit::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(6), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rTexDetailEdit::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(6), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rTexDetailEdit::DTI));
}

MT_CTSTR rTexDetailEdit::getExt() const {
    return "tde";
}

rTexDetailEdit::DetailParam* rTexDetailEdit::getEditWork(u32 idx) {
    if (idx < mEditList.mLength) {
        return static_cast<DetailParam*>(mEditList.mpArray[idx]);
    } else {
        return nullptr;
    }
}

inline rTexDetailEdit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTexDetailEdit::MyDTI rTexDetailEdit::DTI("rTexDetailEdit", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rTexDetailEdit::MyDTI::newInstance() const {
    return new (16u) rTexDetailEdit;
}

const MtDTI& rTexDetailEdit::DetailParam::getDTI() const {
    return rTexDetailEdit::DetailParam::DTI;
}

void rTexDetailEdit::DetailParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mPath", reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::getPath), reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::setPath), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mForm", reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::getForm), reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::setForm), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mType", reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::getType), reinterpret_cast<MT_MFUNC>(&::rTexDetailEdit::DetailParam::setType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* rTexDetailEdit::DetailParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

MT_CTSTR rTexDetailEdit::DetailParam::getPath() {
    return mPath.ptr();
}

__attribute__((weak)) void rTexDetailEdit::DetailParam::setPath(const MtString& n) {
    mPath = n;
}

static auto ddon_emit_0x01ab6120 __attribute__((used)) = &rTexDetailEdit::DetailParam::getForm;

static auto ddon_emit_0x01ab6130 __attribute__((used)) = &rTexDetailEdit::DetailParam::setForm;

static auto ddon_emit_0x01ab6140 __attribute__((used)) = &rTexDetailEdit::DetailParam::getType;

static auto ddon_emit_0x01ab6150 __attribute__((used)) = &rTexDetailEdit::DetailParam::setType;

inline rTexDetailEdit::DetailParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTexDetailEdit::DetailParam::MyDTI rTexDetailEdit::DetailParam::DTI("rTexDetailEdit::DetailParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rTexDetailEdit::DetailParam::MyDTI::newInstance() const {
    return new (16u) rTexDetailEdit::DetailParam;
}

