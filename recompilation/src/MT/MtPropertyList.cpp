// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtPropertyList.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtProperty.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtPropertyList::getDTI() const {
    return MtPropertyList::DTI;
}

MtPropertyList::MtPropertyList() {
    mpElement = nullptr;
}

MtPropertyList::~MtPropertyList() {
    mCS.lock();
    MtProperty* pe = mpElement;
    while (pe != nullptr) {
        MtProperty* mpPrev = pe->mpPrev;
        if (mpEmpty != nullptr) {
            pe->mpPrev = mpEmpty;
            pe->mpNext = nullptr;
            mpEmpty->mpNext = pe;
        } else {
            pe->mpPrev = nullptr;
            pe->mpNext = nullptr;
        }
        mpEmpty = pe;
        pe = mpPrev;
    }
    mpElement = nullptr;
    mCS.unlock();
}

MtProperty* MtPropertyList::find(MtProperty::TYPE type, MT_CTSTR name) const {
    MtProperty* v3_8;
    if (mpElement == nullptr) {
        v3_8 = nullptr;
    } else {
        for (MtProperty* pe = mpElement;;) {
            if (pe->mType == static_cast<unsigned int>(type)) {
                if (strcmp(pe->mName, name) == 0) {
                    v3_8 = pe;
                    return v3_8;
                }
            }
            if (pe->mpPrev != nullptr) {
                pe = pe->mpPrev;
            } else {
                break;
            }
        }
        v3_8 = nullptr;
    }
    return v3_8;
}

MtProperty* MtPropertyList::find(MT_CTSTR name) const {
    MtProperty* v2_8;
    if (mpElement == nullptr) {
        v2_8 = nullptr;
    } else {
        for (MtProperty* pe = mpElement;;) {
            if (strcmp(pe->mName, name) != 0) {
                if (pe->mpPrev != nullptr) {
                    pe = pe->mpPrev;
                } else {
                    break;
                }
            } else {
                v2_8 = pe;
                return v2_8;
            }
        }
        v2_8 = nullptr;
    }
    return v2_8;
}

__attribute__((weak)) MtProperty* MtPropertyList::operator[](int index) {
        MtProperty* it = mpElement;
        for (;;) {
            if (it == nullptr) {
                return nullptr;
            }
            if (it->mpPrev == nullptr) {
                break;
            }
            it = it->mpPrev;
        }
        for (int i = 0; it != nullptr; it = it->mpNext, i++) {
            if (i == index) {
                return it;
            }
        }
        return nullptr;
}

__attribute__((weak)) void MtPropertyList::clear() {
    mCS.lock();
    MtProperty* pe = mpElement;
    while (pe != nullptr) {
        MtProperty* mpPrev = pe->mpPrev;
        if (mpEmpty != nullptr) {
            pe->mpPrev = mpEmpty;
            pe->mpNext = nullptr;
            mpEmpty->mpNext = pe;
        } else {
            pe->mpPrev = nullptr;
            pe->mpNext = nullptr;
        }
        mpEmpty = pe;
        pe = mpPrev;
    }
    mpElement = nullptr;
    mCS.unlock();
}

u32 MtPropertyList::length() {
    unsigned int i0_0 = 0;
    for (MtProperty* pe = mpElement;;) {
        if (pe == nullptr) {
            break;
        } else {
            i0_0 += 1u;
            pe = pe->mpPrev;
        }
    }
    return i0_0;
}

MtProperty* MtPropertyList::begin() const {
    MtProperty* v0_2 = mpElement;
    MtProperty* v1_0;
    for (;;) {
        if (v0_2 == nullptr) {
            v1_0 = nullptr;
            break;
        } else {
            if (v0_2->mpPrev != nullptr) {
                v0_2 = v0_2->mpPrev;
            } else {
                v1_0 = v0_2;
                break;
            }
        }
    }
    return v1_0;
}

__attribute__((weak)) MtProperty* MtPropertyList::insert(const MtProperty& prop, MtProperty* ptarget) {
    DDON_STUB("MtPropertyList::insert")
    return nullptr;
}

__attribute__((weak)) MtProperty* MtPropertyList::insert(MtPropertyList& ss, MtProperty* ptarget) {
    DDON_STUB("MtPropertyList::insert")
    return nullptr;
}

__attribute__((weak)) void MtPropertyList::releaseElementPool() {
    DDON_STUB("MtPropertyList::releaseElementPool")
    /* stub */
}

__attribute__((weak)) MtProperty* MtPropertyList::newElement() {
    MtProperty* pne = nullptr;
    mCS.lock();
    if (mpEmpty != nullptr) {
        MtProperty* pe = mpEmpty;
        pne = pe;
        if (pe->mpPrev != nullptr) {
            mpEmpty = pe->mpPrev;
            mpEmpty->mpNext = nullptr;
        } else {
            mpEmpty = nullptr;
        }
    } else {
        if (mpPool == nullptr) {
            mBaseChain.pPool = mBasePool;
            mBaseChain.poolPt = 0;
            mBaseChain.poolSize = MtPropertyList::BASE_ELEMENTPOOL;
            mBaseChain.pNext = nullptr;
            mBaseChain.pPrev = nullptr;
            mpPool = &mBaseChain;
        } else if (mpPool->poolPt == mpPool->poolSize) {
            poolChain* pc = allocateChain(MtPropertyList::INCR_ELEMENTPOOL);
            pc->pNext = mpPool;
            mpPool->pPrev = pc;
            mpPool = pc;
        }
        pne = &mpPool->pPool[mpPool->poolPt++];
    }
    ++mMaxUsed;
    mCS.unlock();
    return pne;
}

inline MtPropertyList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}
MtPropertyList::MyDTI MtPropertyList::DTI("MtPropertyList", &::MtObject::DTI, 16ul, 0u, 0u);

MtProperty* MtPropertyList::mpEmpty;

MtPropertyList::poolChain* MtPropertyList::mpPool;

MtProperty MtPropertyList::mBasePool[2048];

MtPropertyList::poolChain MtPropertyList::mBaseChain;

u32 MtPropertyList::mMaxUsed;

MtCriticalSection MtPropertyList::mCS;

__attribute__((weak)) MtObject* MtPropertyList::MyDTI::newInstance() const {
    DDON_STUB("MtPropertyList::MyDTI::newInstance")
    return nullptr;
}

