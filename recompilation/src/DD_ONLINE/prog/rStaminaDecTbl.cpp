// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStaminaDecTbl.h"
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
#include "../../generated/shared/nStamina.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStaminaDecList::getDTI() const {
    return cStaminaDecList::DTI;
}

inline void* cStaminaDecList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cStaminaDecList::DTI)->memAlloc(sz, align, cStaminaDecList::DTI.getID());
}

inline void cStaminaDecList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cStaminaDecList::DTI)->memFree(p_addr);
}

cStaminaDecList::~cStaminaDecList() {
    if (mStaminaDecList.mLength != 0) {
        u32 v0_0 = mStaminaDecList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mStaminaDecList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mStaminaDecList.mpArray[i0_3];
                v1_0 = mStaminaDecList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mStaminaDecList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStaminaDecList.mpArray));
    }
    mStaminaDecList.mBufsiz = 0;
    mStaminaDecList.mLength = 0;
    mCType = nStamina::TYPE_ALWAYS;
    mExecuteType = nStamina::TYPE_DECREASE;
    mStaminaType = 0;
    mValueType = nStamina::TYPE_REAL;
    mStaminaDecList.mpArray = nullptr;
}

__attribute__((weak)) void cStaminaDecList::createProperty(MtPropertyList& proplist) {
}

__attribute__((weak)) bool cStaminaDecList::importBinary(MtDataReader& reader) {
    mStaminaDecList.deleteAll(true);
    u32 size = reader.readU32();
    mStaminaType = reader.readU32();
    mValueType = static_cast<nStamina::VALUE_TYPE>(reader.readS32());
    mCType = static_cast<nStamina::CONTINUATION_TYPE>(reader.readS32());
    mExecuteType = static_cast<nStamina::UPDATE_TYPE>(reader.readS32());
    mStaminaDecList.reserve(size);
    for (u32 i = 0; i < size; ++i) {
        cStaminaDecParam* param = new (16u) cStaminaDecParam;
        if (param != nullptr) {
            param->importBinary(reader);
            mStaminaDecList.add(param);
        }
    }
    return true;
}

inline cStaminaDecList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStaminaDecList::MyDTI cStaminaDecList::DTI("cStaminaDecList", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cStaminaDecList::MyDTI::newInstance() const {
    return new (16u) cStaminaDecList;
}

const MtDTI& cStaminaDecParam::getDTI() const {
    return cStaminaDecParam::DTI;
}

inline void* cStaminaDecParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cStaminaDecParam::DTI)->memAlloc(sz, align, cStaminaDecParam::DTI.getID());
}

inline void cStaminaDecParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cStaminaDecParam::DTI)->memFree(p_addr);
}

void cStaminaDecParam::createProperty(MtPropertyList& proplist) {
    proplist << MtProperty(static_cast<MtObject*>(this), "mStamina", &mStamina, 0u, 0u);
}

MtUI* cStaminaDecParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cStaminaDecParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStaminaDecParam::MyDTI cStaminaDecParam::DTI("cStaminaDecParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cStaminaDecParam::MyDTI::newInstance() const {
    return new (16u) cStaminaDecParam;
}

const MtDTI& rStaminaDecTbl::getDTI() const {
    return rStaminaDecTbl::DTI;
}

inline void* rStaminaDecTbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStaminaDecTbl::DTI)->memAlloc(sz, align, rStaminaDecTbl::DTI.getID());
}

inline void rStaminaDecTbl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStaminaDecTbl::DTI)->memFree(p_addr);
}

MT_CTSTR rStaminaDecTbl::getExt() const {
    return "sdt";
}

inline rStaminaDecTbl::rStaminaDecTbl() {
    setAttribute(18u);
    mDecTbl.mAutoDelete = true;
}

rStaminaDecTbl::~rStaminaDecTbl() {
    if (mDecTbl.mLength != 0) {
        u32 v0_0 = mDecTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDecTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDecTbl.mpArray[i0_3];
                v1_0 = mDecTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDecTbl.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDecTbl.mpArray));
    }
    mDecTbl.mpArray = nullptr;
    mDecTbl.mBufsiz = 0;
    mDecTbl.mLength = 0;
}

void rStaminaDecTbl::createProperty(MtPropertyList& proplist) {
    this->cResource::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mDecTbl", static_cast<MtObject*>(&mDecTbl), 0u, 0u);
}

MtUI* rStaminaDecTbl::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) bool rStaminaDecTbl::load(MtStream& in) {
    MtDataReader reader(in, 0x1000u);
    u32 magic = reader.readU32();
    if (magic != 0x746473u) {
        return false;
    }
    u32 version = reader.readU32();
    if (version != 5u) {
        return false;
    }
    u32 size = reader.readU32();
    mDecTbl.deleteAll(true);
    if (size > 0u) {
        mDecTbl.reserve(size);
    }
    for (u32 i = 0; i < size; ++i) {
        cStaminaDecList* pData = new (16u) cStaminaDecList;
        if (pData != nullptr) {
            pData->importBinary(reader);
            mDecTbl.add(pData);
        }
    }
    return true;
}

__attribute__((weak)) bool rStaminaDecTbl::save(MtStream& out) {
    MtDataWriter writer(out, 0x1000u, 0x1000u);
    writer.writeU32(0x746473u);
    writer.writeU32(5u);
    u32 size = mDecTbl.length();
    writer.writeU32(size);
    for (u32 i = 0; i < size; ++i) {
        static_cast<cStaminaDecList*>(mDecTbl.mpArray[i])->exportBinary(writer);
    }
    return true;
}

void rStaminaDecTbl::clear() {
    if (mDecTbl.mLength != 0) {
        u32 v0_0 = mDecTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDecTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDecTbl.mpArray[i0_3];
                v1_0 = mDecTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDecTbl.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDecTbl.mpArray));
    }
    mDecTbl.mpArray = nullptr;
    mDecTbl.mBufsiz = 0;
    mDecTbl.mLength = 0;
}

cStaminaDecList* rStaminaDecTbl::getStaminaDecList(u32 tblIndex) const {
    if (tblIndex < mDecTbl.mLength) {
        return static_cast<cStaminaDecList*>(mDecTbl.mpArray[tblIndex]);
    } else {
        return nullptr;
    }
}

inline rStaminaDecTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStaminaDecTbl::MyDTI rStaminaDecTbl::DTI("rStaminaDecTbl", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rStaminaDecTbl::MyDTI::newInstance() const {
    return new (16u) rStaminaDecTbl;
}

template MtTypedArray<cStaminaDecList>::~MtTypedArray();

template MtTypedArray<cStaminaDecParam>::~MtTypedArray();

