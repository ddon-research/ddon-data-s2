// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFieldAreaList.h"
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
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rFieldAreaList::getDTI() const {
    return rFieldAreaList::DTI;
}

inline void* rFieldAreaList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memAlloc(sz, align, rFieldAreaList::DTI.getID());
}

inline void rFieldAreaList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memFree(p_addr);
}

__attribute__((weak)) u32 rFieldAreaList::getDispFieldAreaNum(u32 landId, u32 areaId) const {
    DDON_STUB("rFieldAreaList::getDispFieldAreaNum")
    return {};
}

u32 rFieldAreaList::getDispFieldAreaId(u32 landId, u32 areaId, u32 idx) const {
    u32 v0_1 = mArrayNum;
    if (v0_1 != 0) {
        cFieldAreaInfo* v0_2 = mpArray;
        cFieldAreaInfo* p0_0 = v0_2;
        u32 i = 0;
        unsigned int i0_4 = 0;
        unsigned int v1_1;
        for (;;) {
            if (p0_0->mLandId == landId) {
                if (p0_0->mAreaId != 0) {
                    if (p0_0->mAreaId == areaId) {
                        if (idx == i0_4) {
                            return v0_2[i].mFieldAreaId;
                        } else {
                            v1_1 = i0_4 + 1u;
                        }
                    } else {
                        v1_1 = i0_4;
                    }
                } else {
                    if (idx == i0_4) {
                        return v0_2[i].mFieldAreaId;
                    } else {
                        v1_1 = i0_4 + 1u;
                    }
                }
            } else {
                v1_1 = i0_4;
            }
            if ((i + 1u) < v0_1) {
                p0_0 += 1;
                i = i + 1u;
                i0_4 = v1_1;
            } else {
                break;
            }
        }
    }
    return 0;
}

const rFieldAreaList::cFieldAreaInfo* rFieldAreaList::getFieldAreaInfo(u32 fieldAreaId) const {
    u32 v0_0 = mArrayNum;
    cFieldAreaInfo* v2_0;
    if (v0_0 == 0) {
        v2_0 = nullptr;
    } else {
        cFieldAreaInfo* v0_3 = mpArray;
        u32 i = 0;
        for (cFieldAreaInfo* p0_2 = v0_3;;) {
            if (p0_2->mFieldAreaId != fieldAreaId) {
                if ((i + 1u) < v0_0) {
                    i = i + 1u;
                    p0_2 += 1;
                } else {
                    break;
                }
            } else {
                v2_0 = &v0_3[i];
                return v2_0;
            }
        }
        v2_0 = nullptr;
    }
    return v2_0;
}

const rFieldAreaList::cFieldAreaInfo* rFieldAreaList::getFieldAreaInfoFromStageNo(s32 stageNo) const {
    u32 v0_3 = mArrayNum;
    cFieldAreaInfo* v5_0;
    if (v0_3 == 0) {
        v5_0 = nullptr;
    } else {
        cFieldAreaInfo* v0_4 = mpArray;
        unsigned int i0_5 = 0;
        unsigned int i1_0;
        for (;;) {
            const u32 stageNum = v0_4[i0_5].mStageNoList.mLength;
            if (stageNum != 0) {
                MtObject* * v1_3 = v0_4[i0_5].mStageNoList.getBuffer();
                i1_0 = 0;
                for (;;) {
                    if (v1_3[static_cast<int>(i1_0)] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_3[static_cast<int>(i1_0)]) + 8)) == static_cast<unsigned int>(stageNo)) {
                            v5_0 = &v0_4[i0_5];
                            return v5_0;
                        }
                    }
                    if ((i1_0 + 1u) < stageNum) {
                        i1_0 += 1u;
                    } else {
                        break;
                    }
                }
            }
            if ((i0_5 + 1u) < v0_3) {
                i0_5 += 1u;
            } else {
                break;
            }
        }
        v5_0 = nullptr;
    }
    return v5_0;
}

const rFieldAreaList::cFieldAreaInfo* rFieldAreaList::getFieldAreaInfoFromLandArea(u32 landId, u32 areaId, u32 idx) const {
    u32 v0_1 = mArrayNum;
    cFieldAreaInfo* v3_0;
    if (v0_1 == 0) {
        v3_0 = nullptr;
    } else {
        cFieldAreaInfo* v0_3 = mpArray;
        cFieldAreaInfo* p0_0 = v0_3;
        unsigned int i0_2 = 0;
        u32 i = 0;
        unsigned int v1_1;
        for (;;) {
            if (p0_0->mLandId != landId) {
                v1_1 = i0_2;
            } else {
                if (p0_0->mAreaId != 0) {
                    if (p0_0->mAreaId != areaId) {
                        v1_1 = i0_2;
                    } else {
                        if (idx != i0_2) {
                            v1_1 = i0_2 + 1u;
                        } else {
                            v3_0 = &v0_3[i];
                            return v3_0;
                        }
                    }
                } else {
                    if (idx != i0_2) {
                        v1_1 = i0_2 + 1u;
                    } else {
                        v3_0 = &v0_3[i];
                        return v3_0;
                    }
                }
            }
            if ((i + 1u) < v0_1) {
                p0_0 += 1;
                i0_2 = v1_1;
                i = i + 1u;
            } else {
                break;
            }
        }
        v3_0 = nullptr;
    }
    return v3_0;
}

u32 rFieldAreaList::getFieldAreaIdFromBelongStage(s32 stageNo) const {
    u32 v0_3 = mArrayNum;
    if (v0_3 != 0) {
        cFieldAreaInfo* v0_4 = mpArray;
        unsigned int i0_5 = 0;
        unsigned int i1_0;
        unsigned int i3_0;
        for (;;) {
            const u32 stageNum = v0_4[i0_5].mStageNoList.mLength;
            if (stageNum != 0) {
                MtObject* * v1_2 = v0_4[i0_5].mStageNoList.getBuffer();
                i1_0 = 0;
                for (;;) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_2[static_cast<int>(i1_0)]) + 8)) == static_cast<unsigned int>(stageNo)) {
                        return v0_4[i0_5].mFieldAreaId;
                    } else {
                        if ((i1_0 + 1u) < stageNum) {
                            i1_0 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
            const u32 belongStageNum = v0_4[i0_5].mBelongStageNoList.mLength;
            if (belongStageNum != 0) {
                MtObject* * v3_2 = v0_4[i0_5].mBelongStageNoList.getBuffer();
                i3_0 = 0;
                for (;;) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_2[static_cast<int>(i3_0)]) + 8)) == static_cast<unsigned int>(stageNo)) {
                        return v0_4[i0_5].mFieldAreaId;
                    } else {
                        if ((i3_0 + 1u) < belongStageNum) {
                            i3_0 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
            if ((i0_5 + 1u) < v0_3) {
                i0_5 += 1u;
            } else {
                break;
            }
        }
    }
    return 0;
}

u32 rFieldAreaList::getFieldAreaIdFromStageList(s32 stageNo) const {
    u32 v0_3 = mArrayNum;
    if (v0_3 != 0) {
        cFieldAreaInfo* v0_4 = mpArray;
        unsigned int i0_5 = 0;
        unsigned int i1_0;
        for (;;) {
            const u32 stageNum = v0_4[i0_5].mStageNoList.mLength;
            if (stageNum != 0) {
                MtObject* * v1_2 = v0_4[i0_5].mStageNoList.getBuffer();
                i1_0 = 0;
                for (;;) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_2[static_cast<int>(i1_0)]) + 8)) == static_cast<unsigned int>(stageNo)) {
                        return v0_4[i0_5].mFieldAreaId;
                    } else {
                        if ((i1_0 + 1u) < stageNum) {
                            i1_0 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
            if ((i0_5 + 1u) < v0_3) {
                i0_5 += 1u;
            } else {
                break;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 rFieldAreaList::getStageNoFromFieldAreaId(u32 idx, u32 stageNo) const {
    DDON_STUB("rFieldAreaList::getStageNoFromFieldAreaId")
    return {};
}

MT_CTSTR rFieldAreaList::getExt() const {
    return "fal";
}

inline rFieldAreaList::rFieldAreaList() {
    mpArray = nullptr;
    mArrayNum = 0;
    setAttribute(22u);
}

rFieldAreaList::~rFieldAreaList() {
    if (mpArray == nullptr) {
        return;
    }
    if (mArrayNum == 0) {
        MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memFree(static_cast<void*>(mpArray));
        mpArray = nullptr;
        mArrayNum = 0;
        return;
    }
    mpArray->~cFieldAreaInfo();
    if (mArrayNum <= 1u) {
        MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memFree(static_cast<void*>(mpArray));
        mpArray = nullptr;
        mArrayNum = 0;
        return;
    }
    unsigned int i3 = 1;
    do {
        mpArray[i3].~cFieldAreaInfo();
        i3 += 1u;
    } while (i3 < mArrayNum);
    MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) bool rFieldAreaList::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    u32 header = r.readU32();
    if (header != 0x6c4146u) {
        return false;
    }
    u32 dataVersion = r.readU32();
    if (dataVersion != 2u) {
        return false;
    }
    u32 nArray = r.readU32();
    void* pArray = MtMemoryAllocator::getAllocator(rFieldAreaList::DTI)->memAlloc(sizeof(cFieldAreaInfo) * nArray, 16u);
    for (u32 i = 0; i < nArray; i++) {
        cFieldAreaInfo* pInfo = new (&static_cast<cFieldAreaInfo*>(pArray)[i]) cFieldAreaInfo();
        nDDOIO::readData(r, pInfo->mFieldAreaId);
        nDDOIO::readData(r, pInfo->mGmdIdx);
        nDDOIO::readData(r, pInfo->mLandId);
        nDDOIO::readData(r, pInfo->mAreaId);
        nDDOIO::readMtArray(r, pInfo->mStageNoList);
        nDDOIO::readMtArray(r, pInfo->mBelongStageNoList);
    }
    mpArray = static_cast<cFieldAreaInfo*>(pArray);
    mArrayNum = nArray;
    return true;
}

__attribute__((weak)) bool rFieldAreaList::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    nDDOIO::writeData(w, 0x6c4146u);
    nDDOIO::writeData(w, 2u);
    nDDOIO::writeData(w, mArrayNum);
    for (u32 i = 0; i < mArrayNum; i++) {
        cFieldAreaInfo* pInfo = &mpArray[i];
        nDDOIO::writeData(w, pInfo->mFieldAreaId);
        nDDOIO::writeData(w, pInfo->mGmdIdx);
        nDDOIO::writeData(w, pInfo->mLandId);
        nDDOIO::writeData(w, pInfo->mAreaId);
        nDDOIO::writeMtArray(w, pInfo->mStageNoList);
        nDDOIO::writeMtArray(w, pInfo->mBelongStageNoList);
    }
    return true;
}

inline rFieldAreaList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaList::MyDTI rFieldAreaList::DTI("rFieldAreaList", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rFieldAreaList::MyDTI::newInstance() const {
    return new (16u) rFieldAreaList;
}

const MtDTI& rFieldAreaList::cFieldAreaInfo::getDTI() const {
    return rFieldAreaList::cFieldAreaInfo::DTI;
}

inline void rFieldAreaList::cFieldAreaInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaList::cFieldAreaInfo::DTI)->memFree(p_addr);
}

const rFieldAreaList::cFieldAreaInfo::StageNoArray& rFieldAreaList::cFieldAreaInfo::getStageNoList() const {
    return mStageNoList;
}

u32 rFieldAreaList::cFieldAreaInfo::getGMDIndex() const {
    return mGmdIdx;
}

__attribute__((noinline)) rFieldAreaList::cFieldAreaInfo::~cFieldAreaInfo() {
    if (mStageNoList.mLength != 0) {
        u32 v0_0 = mStageNoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mStageNoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mStageNoList.mpArray[i0_3];
                v1_0 = mStageNoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mStageNoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStageNoList.mpArray));
    }
    mStageNoList.mpArray = nullptr;
    mStageNoList.mBufsiz = 0;
    mStageNoList.mLength = 0;
    if (mBelongStageNoList.mLength != 0) {
        u32 v3_0 = mBelongStageNoList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mBelongStageNoList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mBelongStageNoList.mpArray[i3_3];
                v4_0 = mBelongStageNoList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mBelongStageNoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mBelongStageNoList.mpArray));
    }
    mBelongStageNoList.mpArray = nullptr;
    mBelongStageNoList.mBufsiz = 0;
    mBelongStageNoList.mLength = 0;
}

void rFieldAreaList::cFieldAreaInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mVersionId", &mVersionId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFieldAreaId", &mFieldAreaId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGmdIdx", &mGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLandId", &mLandId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNoList", static_cast<MtObject*>(&mStageNoList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBelongStageNoList", static_cast<MtObject*>(&mBelongStageNoList), 0u, 0u);
}

MtUI* rFieldAreaList::cFieldAreaInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rFieldAreaList::cFieldAreaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaList::cFieldAreaInfo::MyDTI rFieldAreaList::cFieldAreaInfo::DTI("rFieldAreaList::cFieldAreaInfo", &::MtObject::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* rFieldAreaList::cFieldAreaInfo::MyDTI::newInstance() const {
    DDON_STUB("rFieldAreaList::cFieldAreaInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rFieldAreaList::cFieldAreaInfo::cStageNo::getDTI() const {
    return rFieldAreaList::cFieldAreaInfo::cStageNo::DTI;
}

void* rFieldAreaList::cFieldAreaInfo::cStageNo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaList::cFieldAreaInfo::cStageNo::DTI)->memAlloc(sz, align, rFieldAreaList::cFieldAreaInfo::cStageNo::DTI.getID());
}

inline void rFieldAreaList::cFieldAreaInfo::cStageNo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaList::cFieldAreaInfo::cStageNo::DTI)->memFree(p_addr);
}

void rFieldAreaList::cFieldAreaInfo::cStageNo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
}

void rFieldAreaList::cFieldAreaInfo::cStageNo::load(MtDataReader& r) {
    mStageNo = r.readS32();
}

inline rFieldAreaList::cFieldAreaInfo::cStageNo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaList::cFieldAreaInfo::cStageNo::MyDTI rFieldAreaList::cFieldAreaInfo::cStageNo::DTI("rFieldAreaList::cFieldAreaInfo::cStageNo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rFieldAreaList::cFieldAreaInfo::cStageNo::MyDTI::newInstance() const {
    return new (16u) rFieldAreaList::cFieldAreaInfo::cStageNo;
}

template MtTypedArray<rFieldAreaList::cFieldAreaInfo::cStageNo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rFieldAreaList::cFieldAreaInfo::cStageNo>&);

