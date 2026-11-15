// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAbilityList.h"
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
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAbilityData::getDTI() const {
    return cAbilityData::DTI;
}

inline void* cAbilityData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAbilityData::DTI)->memAlloc(sz, align, cAbilityData::DTI.getID());
}

inline void cAbilityData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAbilityData::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cAbilityData::~cAbilityData() {
    if (mParamArray.mAutoDelete) {
        if (mParamArray.mLength != 0) {
            u32 v0_0 = mParamArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mParamArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mParamArray.mpArray[i0_3];
                    v1_0 = mParamArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    } else {
        if (mParamArray.mLength != 0) {
            u32 v3_0 = mParamArray.mLength;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mParamArray.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    mParamArray.mpArray[i3_3]->~MtObject();
                    v4_0 = mParamArray.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mParamArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamArray.mpArray));
    }
    mParamArray.mpArray = nullptr;
    mParamArray.mBufsiz = 0;
    mParamArray.mLength = 0;
}

__attribute__((weak)) void cAbilityData::createProperty(MtPropertyList& s) {
    DDON_STUB("cAbilityData::createProperty")
    /* stub */
}

bool cAbilityData::save(MtDataWriter& w) {
    w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16));
    if (mParamArray.mLength != 0) {
        unsigned int i0_11 = 0;
        unsigned int i1_3;
        for (;;) {
            unsigned long v1_10 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 32)) + (static_cast<unsigned long>(i0_11) * 8)) + 0);
            w.writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_10) + 8)));
            w.writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_10) + 12)));
            w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_10) + 24));
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_10) + 24)) != 0) {
                i1_3 = 0;
                for (;;) {
                    unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v1_10) + 40)) + (static_cast<unsigned long>(i1_3) * 8)) + 0);
                    w.writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 8)));
                    w.writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 12)));
                    if ((i1_3 + 1u) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_10) + 24))) {
                        i1_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
            if ((i0_11 + 1u) < mParamArray.mLength) {
                i0_11 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

__attribute__((weak)) bool cAbilityData::load(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer) {
    DDON_STUB("cAbilityData::load")
    return {};
}

const cAbilityParam* cAbilityData::getAbilityParam(s32 index) const {
    if (static_cast<unsigned int>(index) < mParamArray.mLength) {
        return static_cast<const cAbilityParam*>(mParamArray.mpArray[static_cast<unsigned int>(index)]);
    } else {
        return nullptr;
    }
}

inline cAbilityData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAbilityData::MyDTI cAbilityData::DTI("cAbilityData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cAbilityData::MyDTI::newInstance() const {
    return new (16u) cAbilityData;
}

const MtDTI& cAbilityParam::getDTI() const {
    return cAbilityParam::DTI;
}

inline void* cAbilityParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAbilityParam::DTI)->memAlloc(sz, align, cAbilityParam::DTI.getID());
}

inline void cAbilityParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAbilityParam::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cAbilityParam::~cAbilityParam() {
    if (mParamDataArray.mAutoDelete) {
        if (mParamDataArray.mLength != 0) {
            u32 v0_0 = mParamDataArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mParamDataArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mParamDataArray.mpArray[i0_3];
                    v1_0 = mParamDataArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    } else {
        if (mParamDataArray.mLength != 0) {
            u32 v3_0 = mParamDataArray.mLength;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mParamDataArray.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    mParamDataArray.mpArray[i3_3]->~MtObject();
                    v4_0 = mParamDataArray.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mParamDataArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamDataArray.mpArray));
    }
    mParamDataArray.mpArray = nullptr;
    mParamDataArray.mBufsiz = 0;
    mParamDataArray.mLength = 0;
}

__attribute__((weak)) void cAbilityParam::createProperty(MtPropertyList& s) {
    DDON_STUB("cAbilityParam::createProperty")
    /* stub */
}

__attribute__((weak)) bool cAbilityParam::load(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer) {
    DDON_STUB("cAbilityParam::load")
    return {};
}

bool cAbilityParam::getParam(s32 Lv, s32& param) const {
    u32 v0_0 = mParamDataArray.mLength;
    u32 i;
    MtObject* * v0_3;
    if (v0_0 == 0) {
        return false;
    } else {
        v0_3 = mParamDataArray.mpArray;
        i = 0;
    }
    for (;;) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[i]) + 8)) == static_cast<unsigned int>(Lv)) {
            param = static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[i]) + 12));
            return true;
        } else {
            if ((i + 1u) < v0_0) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

inline cAbilityParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAbilityParam::MyDTI cAbilityParam::DTI("cAbilityParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cAbilityParam::MyDTI::newInstance() const {
    return new (16u) cAbilityParam;
}

const MtDTI& cAbilityParam::cParamData::getDTI() const {
    return cAbilityParam::cParamData::DTI;
}

inline void* cAbilityParam::cParamData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAbilityParam::cParamData::DTI)->memAlloc(sz, align, cAbilityParam::cParamData::DTI.getID());
}

inline void cAbilityParam::cParamData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAbilityParam::cParamData::DTI)->memFree(p_addr);
}

cAbilityParam::cParamData::~cParamData() {
}

__attribute__((weak)) void cAbilityParam::cParamData::createProperty(MtPropertyList& s) {
    DDON_STUB("cAbilityParam::cParamData::createProperty")
    /* stub */
}

inline cAbilityParam::cParamData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAbilityParam::cParamData::MyDTI cAbilityParam::cParamData::DTI("cAbilityParam::cParamData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cAbilityParam::cParamData::MyDTI::newInstance() const {
    return new (16u) cAbilityParam::cParamData;
}

const MtDTI& rAbilityList::getDTI() const {
    return rAbilityList::DTI;
}

inline void* rAbilityList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rAbilityList::DTI)->memAlloc(sz, align, rAbilityList::DTI.getID());
}

inline void rAbilityList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rAbilityList::DTI)->memFree(p_addr);
}

inline rAbilityList::rAbilityList() {
    setAttribute(18u);
    mDataList.mAutoDelete = true;
}

__attribute__((noinline)) rAbilityList::~rAbilityList() {
    if (mDataList.mAutoDelete) {
        if (mDataList.mLength != 0) {
            u32 v0_0 = mDataList.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mDataList.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mDataList.mpArray[i0_3];
                    v1_0 = mDataList.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mDataList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDataList.mpArray));
        }
        mDataList.mpArray = nullptr;
        mDataList.mBufsiz = 0;
        mDataList.mLength = 0;
    } else {
        MtObject* v6_8;
        if (mDataList.mLength != 0) {
            MtObject* v3_8 = *mDataList.mpArray;
            u32 v3_0 = mDataList.mLength;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mDataList.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    mDataList.mpArray[i3_3]->~MtObject();
                    v4_0 = mDataList.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
            v6_8 = v3_8;
        } else {
            v6_8 = nullptr;
        }
        if (mDataList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDataList.mpArray));
        }
        mDataList.mpArray = nullptr;
        mDataList.mBufsiz = 0;
        mDataList.mLength = 0;
        if (v6_8 != nullptr) {
            MtMemoryAllocator::getAllocator(rAbilityList::DTI)->memFree(static_cast<void*>(v6_8));
        }
    }
}

__attribute__((weak)) void rAbilityList::createProperty(MtPropertyList& s) {
    DDON_STUB("rAbilityList::createProperty")
    /* stub */
}

__attribute__((weak)) void rAbilityList::clear() {
}

__attribute__((weak)) bool rAbilityList::load(MtStream& in) {
    DDON_STUB("rAbilityList::load")
    return {};
}

__attribute__((weak)) bool rAbilityList::save(MtStream& out) {
    DDON_STUB("rAbilityList::save")
    return {};
}

MT_CTSTR rAbilityList::getExt() const {
    return "abl";
}

const cAbilityData* rAbilityList::getData(s32 index) {
    if (static_cast<unsigned int>(index) < mDataList.mLength) {
        return static_cast<const cAbilityData*>(mDataList.getBuffer()[index]);
    } else {
        return nullptr;
    }
}

inline rAbilityList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAbilityList::MyDTI rAbilityList::DTI("rAbilityList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rAbilityList::MyDTI::newInstance() const {
    return new (16u) rAbilityList;
}

template MtTypedArray<cAbilityData>::~MtTypedArray();

template MtTypedArray<cAbilityParam::cParamData>::~MtTypedArray();

template MtTypedArray<cAbilityParam>::~MtTypedArray();

