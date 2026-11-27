// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rQuestList.h"

#include "rLayout.h"
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
#include "cSetInfo.h"
#include "nLayout.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestGroup::getDTI() const {
    return cQuestGroup::DTI;
}

__attribute__((noinline)) cQuestGroup::~cQuestGroup() {
    mQusetSet.deleteAll(true);
}

void cQuestGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCondition", &mCondition, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEraseCondition", &mEraseCondition, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQusetSet", static_cast<MtObject*>(&mQusetSet), 0u, 0u);
}

s32 cQuestGroup::getCondition() const {
    return mCondition;
}

s32 cQuestGroup::getEraseCondition() const {
    return mEraseCondition;
}

inline cQuestGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestGroup::MyDTI cQuestGroup::DTI("cQuestGroup", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cQuestGroup::MyDTI::newInstance() const {
    return new (16u) cQuestGroup;
}

const MtDTI& cQuestSet::getDTI() const {
    return cQuestSet::DTI;
}

cQuestSet::~cQuestSet() {
    if (mpSetInfo == nullptr) {
        return;
    }
    delete mpSetInfo;
    mpSetInfo = nullptr;
}

void cQuestSet::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOmID", &mOmID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitNo", &mUnitNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKind", &mKind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSetInfo", reinterpret_cast<MtObject* *>(&mpSetInfo), 0u, 0u);
}

inline cQuestSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSet::MyDTI cQuestSet::DTI("cQuestSet", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cQuestSet::MyDTI::newInstance() const {
    return new (16u) cQuestSet;
}

const MtDTI& cQuestStage::getDTI() const {
    return cQuestStage::DTI;
}

cQuestStage::~cQuestStage() {
    if (mQuestGrp.mLength != 0) {
        u32 v0_0 = mQuestGrp.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mQuestGrp.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mQuestGrp.mpArray[i0_3];
                v1_0 = mQuestGrp.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mQuestGrp.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestGrp.mpArray));
    }
    mQuestGrp.mpArray = nullptr;
    mQuestGrp.mBufsiz = 0;
    mQuestGrp.mLength = 0;
}

void cQuestStage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestGrp", static_cast<MtObject*>(&mQuestGrp), 0u, 0u);
}

inline cQuestStage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestStage::MyDTI cQuestStage::DTI("cQuestStage", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cQuestStage::MyDTI::newInstance() const {
    return new (16u) cQuestStage;
}

const MtDTI& rQuestList::getDTI() const {
    return rQuestList::DTI;
}

rQuestList::~rQuestList() {
    if (!mbNoDelete) {
        if (mQuestStage.mLength != 0) {
            u32 v0_0 = mQuestStage.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mQuestStage.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mQuestStage.mpArray[i0_3];
                    v1_0 = mQuestStage.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mQuestStage.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestStage.mpArray));
        }
        mQuestStage.mpArray = nullptr;
        mQuestStage.mBufsiz = 0;
        mQuestStage.mLength = 0;
    }
}

void rQuestList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestStage", static_cast<MtObject*>(&mQuestStage), 0u, 0u);
}

MtUI* rQuestList::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

MT_CTSTR rQuestList::getExt() const {
    return "qst";
}

bool rQuestList::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<unsigned short>(rQuestList::DATA_VERSION), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rQuestList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<unsigned short>(rQuestList::DATA_VERSION), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
}

inline rQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestList::MyDTI rQuestList::DTI("rQuestList", &::cResource::DTI, 152ul, 0u, 0u);

const u32 rQuestList::DATA_VERSION = rLayout::DATA_VERSION;

MtObject* rQuestList::MyDTI::newInstance() const {
    return new (16u) rQuestList;
}

template MtTypedArray<cQuestGroup>::~MtTypedArray();

template MtTypedArray<cQuestSet>::~MtTypedArray();

template MtTypedArray<cQuestStage>::~MtTypedArray();

