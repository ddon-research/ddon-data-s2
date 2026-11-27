// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlSelector.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpComponent.h"
#include "cpShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompList::getDTI() const {
    return cShlParamCompList::DTI;
}

const MtDTI& cShlParamCompList::getComponentDTI() const {
    return cpShlList::DTI;
}

cShlParamCompList::~cShlParamCompList() {
    if (mShlComponent.mLength != 0) {
        u32 v0_0 = mShlComponent.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mShlComponent.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mShlComponent.mpArray[i0_3];
                v1_0 = mShlComponent.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mShlComponent.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mShlComponent.mpArray));
    }
    mShlComponent.mpArray = nullptr;
    mShlComponent.mBufsiz = 0;
    mShlComponent.mLength = 0;
}

void cShlParamCompList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mShlComponent", static_cast<MtObject*>(&mShlComponent), 0u, 0u);
}

__attribute__((weak)) void cShlParamCompList::copy(const cShlParamComponent* pParamBase) {
    DDON_STUB("cShlParamCompList::copy")
    /* stub */
}

inline cShlParamCompList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompList::MyDTI cShlParamCompList::DTI("cShlParamCompList", &::cShlParamComponent::DTI, 40ul, 0u, 0u);

MtObject* cShlParamCompList::MyDTI::newInstance() const {
    return new (16u) cShlParamCompList;
}

const MtDTI& cShlParamCompSelector::getDTI() const {
    return cShlParamCompSelector::DTI;
}

__attribute__((weak)) void cShlParamCompSelector::operator delete(void* p_addr) {
    cShlParamCompSelector::getAllocator()->memFree(p_addr);
}

const MtDTI& cShlParamCompSelector::getComponentDTI() const {
    return cpShlSelector::DTI;
}

cShlParamCompSelector::~cShlParamCompSelector() {
    if (mShlComponent.mLength != 0) {
        u32 v0_0 = mShlComponent.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mShlComponent.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mShlComponent.mpArray[i0_3];
                v1_0 = mShlComponent.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mShlComponent.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mShlComponent.mpArray));
    }
    mShlComponent.mpArray = nullptr;
    mShlComponent.mBufsiz = 0;
    mShlComponent.mLength = 0;
}

void cShlParamCompSelector::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mShlComponent", static_cast<MtObject*>(&mShlComponent), 0u, 0u);
}

__attribute__((weak)) void cShlParamCompSelector::copy(const cShlParamComponent* pParamBase) {
    DDON_STUB("cShlParamCompSelector::copy")
    /* stub */
}

inline cShlParamCompSelector::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompSelector::MyDTI cShlParamCompSelector::DTI("cShlParamCompSelector", &::cShlParamComponent::DTI, 40ul, 0u, 1u);

MtObject* cShlParamCompSelector::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cpShlList::getDTI() const {
    return cpShlList::DTI;
}

__attribute__((weak)) void cpShlList::initSub() {
    DDON_STUB("cpShlList::initSub")
    /* stub */
}

inline cpShlList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlList::MyDTI cpShlList::DTI("cpShlList", &::cpShlBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlList::MyDTI::newInstance() const {
    DDON_STUB("cpShlList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpShlSelector::getDTI() const {
    return cpShlSelector::DTI;
}

__attribute__((weak)) void cpShlSelector::initSub() {
    DDON_STUB("cpShlSelector::initSub")
    /* stub */
}

u32 cpShlSelector::getSelectedIndex() const {
    return 0;
}

inline cpShlSelector::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlSelector::MyDTI cpShlSelector::DTI("cpShlSelector", &::cpShlBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlSelector::MyDTI::newInstance() const {
    DDON_STUB("cpShlSelector::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cShlParamComponent>::~MtTypedArray();

