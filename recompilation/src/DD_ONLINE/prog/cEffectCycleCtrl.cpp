// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cEffectCycleCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCyclePartInfo::getDTI() const {
    return cCyclePartInfo::DTI;
}

cCyclePartInfo::~cCyclePartInfo() {
    if (mpEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEfcHandle, 1u);
    mpEfcHandle = nullptr;
}

__attribute__((weak)) void cCyclePartInfo::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void cCyclePartInfo::partInit() {
    DDON_STUB("cCyclePartInfo::partInit")
    /* stub */
}

__attribute__((weak)) void cCyclePartInfo::partEnd() {
    DDON_STUB("cCyclePartInfo::partEnd")
    /* stub */
}

inline cCyclePartInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCyclePartInfo::MyDTI cCyclePartInfo::DTI("cCyclePartInfo", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* cCyclePartInfo::MyDTI::newInstance() const {
    return new (16u) cCyclePartInfo;
}

const MtDTI& cCyclePartReqInfo::getDTI() const {
    return cCyclePartReqInfo::DTI;
}

inline cCyclePartReqInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCyclePartReqInfo::MyDTI cCyclePartReqInfo::DTI("cCyclePartReqInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cCyclePartReqInfo::MyDTI::newInstance() const {
    return new (16u) cCyclePartReqInfo;
}

const MtDTI& cEffectCycleCtrl::getDTI() const {
    return cEffectCycleCtrl::DTI;
}

cEffectCycleCtrl::cEffectCycleCtrl() {
    DDON_STUB("cEffectCycleCtrl::cEffectCycleCtrl")
    /* stub */
}

cEffectCycleCtrl::~cEffectCycleCtrl() {
}

__attribute__((weak)) void cEffectCycleCtrl::createProperty(MtPropertyList& s) {
}

void cEffectCycleCtrl::updatePtr() {
    if (mpModel != nullptr) {
        if (!mpModel->isEnable()) {
            mpModel = nullptr;
        }
    }
    u32 v0_0 = mEffectPartArray.size();
    if (v0_0 != 0) {
        for (unsigned int i0_1 = 0;;) {
            if (mEffectPartArray.getBuffer()[static_cast<int>(i0_1)] != nullptr) {
                if (static_cast<cCyclePartInfo*>(mEffectPartArray.getBuffer()[static_cast<int>(i0_1)])->mpModel != nullptr) {
                    if (!static_cast<cCyclePartInfo*>(mEffectPartArray.getBuffer()[static_cast<int>(i0_1)])->mpModel->isEnable()) {
                        static_cast<cCyclePartInfo*>(mEffectPartArray.getBuffer()[static_cast<int>(i0_1)])->mpModel = nullptr;
                    }
                }
            }
            if ((i0_1 + 1u) < v0_0) {
                i0_1 += 1u;
            } else {
                break;
            }
        }
    }
}

void cEffectCycleCtrl::updateEfcHandle() {
    if (mEffectPartArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t0 = mEffectPartArray.getBuffer()[static_cast<int>(i0_3)];
            if (t0 != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)) != 0) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(reinterpret_cast<cEfcHandle*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)))) {
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)) + 96) = 0;
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48) = 0;
                    }
                }
            }
            if ((i0_3 + 1u) < mEffectPartArray.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void cEffectCycleCtrl::update() {
    DDON_STUB("cEffectCycleCtrl::update")
    /* stub */
}

void cEffectCycleCtrl::kill() {
    if (static_cast<int>(mEffectPartArray.mLength) > 0) {
        u32 v0_0 = mEffectPartArray.mLength;
        s32 i = 0;
        u32 v1_0;
        for (;;) {
            MtObject* t0 = mEffectPartArray.getBuffer()[i];
            if (t0 == nullptr) {
                v1_0 = v0_0;
            } else {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)) == 0) {
                    v1_0 = v0_0;
                } else {
                    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(reinterpret_cast<cEfcHandle*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)), 1u);
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48) = 0;
                    v1_0 = mEffectPartArray.mLength;
                }
            }
            if ((i + 1) < static_cast<int>(v1_0)) {
                v0_0 = v1_0;
                i = i + 1;
            } else {
                break;
            }
        }
    }
}

void cEffectCycleCtrl::setOwner(uDDOModel* pModel) {
    mpModel = pModel;
}

__attribute__((weak)) void cEffectCycleCtrl::requestInsertCyclePart(cCyclePartReqInfo& reqInfo, s32 Order) {
    DDON_STUB("cEffectCycleCtrl::requestInsertCyclePart")
    /* stub */
}

__attribute__((weak)) void cEffectCycleCtrl::reqestKillCyclePart(s32 Order) {
    DDON_STUB("cEffectCycleCtrl::reqestKillCyclePart")
    /* stub */
}

__attribute__((weak)) void cEffectCycleCtrl::reqestForceKillCyclePart(s32 Order) {
    DDON_STUB("cEffectCycleCtrl::reqestForceKillCyclePart")
    /* stub */
}

bool cEffectCycleCtrl::isOrderExist(s32 Order) const {
    u32 v0_1 = mEffectPartArray.mLength;
    if (v0_1 != 0) {
        MtObject* * v0_4 = mEffectPartArray.mpArray;
        for (u32 i = 0;;) {
            if (v0_4[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 84)) == static_cast<unsigned int>(Order)) {
                    return true;
                }
            }
            if ((i + 1u) < v0_1) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

void cEffectCycleCtrl::setEffectFlag(bool flag) {
    u32 v0_0 = mEffectPartArray.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mEffectPartArray.getBuffer();
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[static_cast<int>(i0_2)] != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 24) = static_cast<unsigned char>(flag);
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
    }
}

void cEffectCycleCtrl::setEndEffectFlag(bool flag) {
    u32 v0_0 = mEffectPartArray.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mEffectPartArray.getBuffer();
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[static_cast<int>(i0_2)] != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 36) = static_cast<unsigned char>(flag);
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
    }
}

void cEffectCycleCtrl::setOutLineFlag(bool flag) {
    u32 v0_0 = mEffectPartArray.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mEffectPartArray.getBuffer();
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[static_cast<int>(i0_2)] != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 44) = static_cast<unsigned char>(flag);
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void cEffectCycleCtrl::updateEffectCycle() {
    DDON_STUB("cEffectCycleCtrl::updateEffectCycle")
    /* stub */
}

void cEffectCycleCtrl::registCyclePart(cCyclePartInfo* pInfo) {
    u32 v0_2 = mEffectPartArray.mLength;
    MtObject* * v0_1;
    s32 i;
    u32 v5_0;
    u32 v5_1;
    if (static_cast<int>(v0_2) > 0) {
        v0_1 = mEffectPartArray.getBuffer();
        i = 0;
    } else {
        u32 t0 = mEffectPartArray.mBufsiz;
        if (v0_2 < t0) {
            mEffectPartArray.mLength = v0_2 + 1u;
            mEffectPartArray.mpArray[v0_2] = static_cast<MtObject*>(pInfo);
            v5_0 = v0_2 + 1u;
            v5_1 = v0_2 + 0u;
        } else {
            void* t1 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t0 + 32u) * 8, 16u);
            memset(t1, 0, static_cast<size_t>(t0 + 32u) * 8);
            memcpy(t1, static_cast<const void*>(mEffectPartArray.mpArray), static_cast<size_t>(mEffectPartArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEffectPartArray.mpArray));
            mEffectPartArray.mpArray = static_cast<MtObject* *>(t1);
            mEffectPartArray.mBufsiz = t0 + 32u;
            u32 t2 = mEffectPartArray.mLength;
            mEffectPartArray.mLength = t2 + 1u;
            mEffectPartArray.mpArray[t2] = static_cast<MtObject*>(pInfo);
            v5_0 = t2 + 1u;
            v5_1 = t2 + 0u;
        }
        if (mCurrentPartIndex > -1) {
            if (mCurrentPartIndex < static_cast<int>(v5_0)) {
                if (mCurrentPartIndex >= static_cast<int>(v5_1)) {
                    mCurrentPartIndex = static_cast<s32>(((mCurrentPartIndex + 1) < static_cast<int>(v5_0)) ? static_cast<unsigned int>(mCurrentPartIndex + 1) : 0u);
                }
            } else {
                mCurrentPartIndex = static_cast<s32>(v5_1);
            }
        } else {
            mCurrentPartIndex = static_cast<s32>(v5_1);
        }
        return;
    }
    for (;;) {
        if (v0_1[i] != nullptr) {
            if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i]) + 84)) < pInfo->mCycleOrder) {
                break;
            }
        }
        if ((i + 1) < static_cast<int>(v0_2)) {
            i = i + 1;
        } else {
            u32 t0 = mEffectPartArray.mBufsiz;
            if (v0_2 < t0) {
                mEffectPartArray.mLength = v0_2 + 1u;
                mEffectPartArray.mpArray[v0_2] = static_cast<MtObject*>(pInfo);
                v5_0 = v0_2 + 1u;
                v5_1 = v0_2 + 0u;
            } else {
                void* t1 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t0 + 32u) * 8, 16u);
                memset(t1, 0, static_cast<size_t>(t0 + 32u) * 8);
                memcpy(t1, static_cast<const void*>(mEffectPartArray.mpArray), static_cast<size_t>(mEffectPartArray.mLength) * 8);
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEffectPartArray.mpArray));
                mEffectPartArray.mpArray = static_cast<MtObject* *>(t1);
                mEffectPartArray.mBufsiz = t0 + 32u;
                u32 t2 = mEffectPartArray.mLength;
                mEffectPartArray.mLength = t2 + 1u;
                mEffectPartArray.mpArray[t2] = static_cast<MtObject*>(pInfo);
                v5_0 = t2 + 1u;
                v5_1 = t2 + 0u;
            }
            if (mCurrentPartIndex > -1) {
                if (mCurrentPartIndex < static_cast<int>(v5_0)) {
                    if (mCurrentPartIndex >= static_cast<int>(v5_1)) {
                        mCurrentPartIndex = static_cast<s32>(((mCurrentPartIndex + 1) < static_cast<int>(v5_0)) ? static_cast<unsigned int>(mCurrentPartIndex + 1) : 0u);
                    }
                } else {
                    mCurrentPartIndex = static_cast<s32>(v5_1);
                }
            } else {
                mCurrentPartIndex = static_cast<s32>(v5_1);
            }
            return;
        }
    }
    if ((static_cast<unsigned int>(i) < v0_2) && (v0_1[i & -1] == nullptr)) {
        v0_1[i & -1] = static_cast<MtObject*>(pInfo);
        v5_0 = v0_2;
        v5_1 = 1;
        if (mCurrentPartIndex > -1) {
            if (mCurrentPartIndex < static_cast<int>(v5_0)) {
                if (mCurrentPartIndex >= static_cast<int>(v5_1)) {
                    mCurrentPartIndex = static_cast<s32>(((mCurrentPartIndex + 1) < static_cast<int>(v5_0)) ? static_cast<unsigned int>(mCurrentPartIndex + 1) : 0u);
                }
            } else {
                mCurrentPartIndex = static_cast<s32>(v5_1);
            }
        } else {
            mCurrentPartIndex = static_cast<s32>(v5_1);
        }
        return;
    }
    u32 t3 = mEffectPartArray.mBufsiz;
    u32 v2_0;
    MtObject* * v2_1;
    u32 v2_6;
    u32 v3_0;
    if (v0_2 < t3) {
        mEffectPartArray.mLength = v0_2 + 1u;
        v0_1[v0_2] = nullptr;
        v2_1 = mEffectPartArray.getBuffer();
        if (v0_2 == static_cast<unsigned int>(i)) {
            v3_0 = v0_2 + 1u;
            goto region_a0ce8;
        } else {
            v2_0 = v0_2 + 1u;
            v2_6 = v0_2;
        }
    } else {
        void* t4 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
        memset(t4, 0, static_cast<size_t>(t3 + 32u) * 8);
        memcpy(t4, static_cast<const void*>(mEffectPartArray.mpArray), static_cast<size_t>(mEffectPartArray.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEffectPartArray.mpArray));
        mEffectPartArray.mpArray = static_cast<MtObject* *>(t4);
        mEffectPartArray.mBufsiz = t3 + 32u;
        u32 t5 = mEffectPartArray.mLength;
        mEffectPartArray.mLength = t5 + 1u;
        mEffectPartArray.mpArray[t5] = nullptr;
        v2_1 = mEffectPartArray.getBuffer();
        if (v0_2 == static_cast<unsigned int>(i)) {
            v3_0 = t5 + 1u;
            goto region_a0ce8;
        } else {
            v2_0 = t5 + 1u;
            v2_6 = v0_2;
        }
    }
    for (;;) {
        v2_1[v2_6] = v2_1[v2_6 - 1u];
        if (i != static_cast<int>(v2_6 - 1u)) {
            v2_6 += 0xFFFFFFFFu;
        } else {
            v3_0 = v2_0;
            break;
        }
    }
    region_a0ce8:;
    v2_1[i & -1] = static_cast<MtObject*>(pInfo);
    v5_0 = v3_0;
    v5_1 = 1;
    if (mCurrentPartIndex > -1) {
        if (mCurrentPartIndex < static_cast<int>(v5_0)) {
            if (mCurrentPartIndex >= static_cast<int>(v5_1)) {
                mCurrentPartIndex = static_cast<s32>(((mCurrentPartIndex + 1) < static_cast<int>(v5_0)) ? static_cast<unsigned int>(mCurrentPartIndex + 1) : 0u);
            }
        } else {
            mCurrentPartIndex = static_cast<s32>(v5_1);
        }
    } else {
        mCurrentPartIndex = static_cast<s32>(v5_1);
    }
}

__attribute__((weak)) bool cEffectCycleCtrl::erasetCyclePartFromIndex(s32 index) {
    DDON_STUB("cEffectCycleCtrl::erasetCyclePartFromIndex")
    return {};
}

inline cEffectCycleCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEffectCycleCtrl::MyDTI cEffectCycleCtrl::DTI("cEffectCycleCtrl", &::MtObject::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cEffectCycleCtrl::MyDTI::newInstance() const {
    DDON_STUB("cEffectCycleCtrl::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cCyclePartInfo>::~MtTypedArray();

