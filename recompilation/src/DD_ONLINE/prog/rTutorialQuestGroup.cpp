// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTutorialQuestGroup.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "nQuest.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rTutorialQuestGroup::getDTI() const {
    return rTutorialQuestGroup::DTI;
}

inline void* rTutorialQuestGroup::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTutorialQuestGroup::DTI)->memAlloc(sz, align, rTutorialQuestGroup::DTI.getID());
}

inline void rTutorialQuestGroup::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTutorialQuestGroup::DTI)->memFree(p_addr);
}

const rTutorialQuestGroup::cGroup* rTutorialQuestGroup::getGroup(u32 groupId) const {
    if (mGroups.mLength != 0) {
        u32 i = 0;
        do {
            if (mGroups.mpArray[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mGroups.mpArray[i]) + 40)) == groupId) {
                    return static_cast<const cGroup*>(mGroups.mpArray[i]);
                }
            }
            i += 1u;
        } while (i < mGroups.mLength);
    }
    return nullptr;
}

MT_CTSTR rTutorialQuestGroup::getExt() const {
    return "tqg";
}

inline rTutorialQuestGroup::rTutorialQuestGroup() {
    setAttribute(22u);
}

rTutorialQuestGroup::~rTutorialQuestGroup() {
    if (mGroups.mLength != 0) {
        u32 v0_0 = mGroups.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGroups.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mGroups.mpArray[i0_3];
                v1_0 = mGroups.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGroups.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroups.mpArray));
    }
    mGroups.mpArray = nullptr;
    mGroups.mBufsiz = 0;
    mGroups.mLength = 0;
}

void rTutorialQuestGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroups", static_cast<MtObject*>(&mGroups), 0u, 0u);
}

__attribute__((weak)) bool rTutorialQuestGroup::save(MtStream& out) {
        MtDataWriter w(out, 4096, 4096);
        (&w)->writeU32(0x475154);
        (&w)->writeU16(1);
        (&w)->writeU32(mGroups.mLength);
        for (u32 t1 = 0; t1 < mGroups.mLength; ++t1) {
            static_cast<cGroup*>(mGroups.mpArray[(s32)t1])->save(w);
        }
        return true;
}

bool rTutorialQuestGroup::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x475154) {
        if ((&r)->readU16() == 1) {
            nDDOIO::readMtArray(r, mGroups);
            return true;
        }
    }
    return false;
}

inline rTutorialQuestGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialQuestGroup::MyDTI rTutorialQuestGroup::DTI("rTutorialQuestGroup", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rTutorialQuestGroup::MyDTI::newInstance() const {
    return new (16u) rTutorialQuestGroup;
}

const MtDTI& rTutorialQuestGroup::cGroup::getDTI() const {
    return rTutorialQuestGroup::cGroup::DTI;
}

void* rTutorialQuestGroup::cGroup::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTutorialQuestGroup::cGroup::DTI)->memAlloc(sz, align, rTutorialQuestGroup::cGroup::DTI.getID());
}

inline void rTutorialQuestGroup::cGroup::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTutorialQuestGroup::cGroup::DTI)->memFree(p_addr);
}

u32 rTutorialQuestGroup::cGroup::getQuestIdNum() const {
    return mQuestIds.mLength;
}

__attribute__((weak)) u32 rTutorialQuestGroup::cGroup::getQuestId(u32 idx) const {
    DDON_STUB("rTutorialQuestGroup::cGroup::getQuestId")
    return {};
}

rTutorialQuestGroup::cGroup::~cGroup() {
    if (mQuestIds.mLength != 0) {
        u32 v0_0 = mQuestIds.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mQuestIds.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mQuestIds.mpArray[i0_3];
                v1_0 = mQuestIds.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mQuestIds.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestIds.mpArray));
    }
    mQuestIds.mpArray = nullptr;
    mQuestIds.mBufsiz = 0;
    mQuestIds.mLength = 0;
}

void rTutorialQuestGroup::cGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupId", &mGroupId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestIds", static_cast<MtObject*>(&mQuestIds), 0u, 0u);
}

__attribute__((weak)) void rTutorialQuestGroup::cGroup::save(MtDataWriter& w) {
    u32 t2 = mGroupId;
    w.writeU32(t2);
    w.writeU32(mQuestIds.mLength);
    for (u32 t1 = 0; t1 < mQuestIds.mLength; ++t1) {
        static_cast<cQuestId*>(mQuestIds.mpArray[t1])->save(w);
        }
}

void rTutorialQuestGroup::cGroup::load(MtDataReader& r) {
    nDDOIO::readData(r, mGroupId);
    nDDOIO::readMtArray(r, mQuestIds);
}

inline rTutorialQuestGroup::cGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialQuestGroup::cGroup::MyDTI rTutorialQuestGroup::cGroup::DTI("rTutorialQuestGroup::cGroup", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rTutorialQuestGroup::cGroup::MyDTI::newInstance() const {
    return new (16u) rTutorialQuestGroup::cGroup;
}

const MtDTI& rTutorialQuestGroup::cGroup::cQuestId::getDTI() const {
    return rTutorialQuestGroup::cGroup::cQuestId::DTI;
}

inline void rTutorialQuestGroup::cGroup::cQuestId::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTutorialQuestGroup::cGroup::cQuestId::DTI)->memFree(p_addr);
}

rTutorialQuestGroup::cGroup::cQuestId::~cQuestId() {
}

void rTutorialQuestGroup::cGroup::cQuestId::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
}

void rTutorialQuestGroup::cGroup::cQuestId::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mId);
}

void rTutorialQuestGroup::cGroup::cQuestId::load(MtDataReader& r) {
    nDDOIO::readData(r, mId);
}

inline rTutorialQuestGroup::cGroup::cQuestId::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialQuestGroup::cGroup::cQuestId::MyDTI rTutorialQuestGroup::cGroup::cQuestId::DTI("rTutorialQuestGroup::cGroup::cQuestId", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rTutorialQuestGroup::cGroup::cQuestId::MyDTI::newInstance() const {
    return new (16u) rTutorialQuestGroup::cGroup::cQuestId;
}

template MtTypedArray<rTutorialQuestGroup::cGroup::cQuestId>::~MtTypedArray();

template MtTypedArray<rTutorialQuestGroup::cGroup>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rTutorialQuestGroup::cGroup::cQuestId>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rTutorialQuestGroup::cGroup>&);

