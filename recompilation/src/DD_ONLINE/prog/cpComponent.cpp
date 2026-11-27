// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpComponent.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpComponent::getDTI() const {
    return cpComponent::DTI;
}

cpComponent::cpComponent() {
    mActive = true;
    mpOwner = nullptr;
    mpNext = nullptr;
    mpPrev = nullptr;
    mpChildBottom = nullptr;
    mpChildTop = nullptr;
    mpParent = nullptr;
    mpRootComponent = this;
}

cpComponent::~cpComponent() {
}

void cpComponent::setup() {
    getDTI();
}

__attribute__((weak)) void cpComponent::updatePtr() {
}

void cpComponent::setActive(bool active) {
    mActive = active;
}

void cpComponent::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mActive", &mActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mName", reinterpret_cast<MT_MFUNC>(&::cpComponent::getName), reinterpret_cast<MT_MFUNC>(&::cpComponent::setName), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpChildTop", reinterpret_cast<MtObject* *>(&mpChildTop), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpChildBottom", reinterpret_cast<MtObject* *>(&mpChildBottom), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpNext", reinterpret_cast<MtObject* *>(&mpNext), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPrev", reinterpret_cast<MtObject* *>(&mpPrev), 0u, 0u);
}

__attribute__((weak)) cpComponent* cpComponent::find(const MtDTI& DTI, bool IsKindOf, bool from_root) {
    DDON_STUB("cpComponent::find")
    return nullptr;
}

__attribute__((weak)) cpComponent* cpComponent::find(MT_CTSTR name, bool from_root) {
    DDON_STUB("cpComponent::find")
    return nullptr;
}

MT_CTSTR cpComponent::getName() {
    return mName.ptr();
}

__attribute__((weak)) void cpComponent::setName(const MtString& name) {
    DDON_STUB("cpComponent::setName")
    /* stub */
}

void cpComponent::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
}

void cpComponent::setParent(cpComponent* pParent) {
    if (pParent == mpParent) {
        return;
    }
    if (mpParent != nullptr) {
        if (this != mpParent->mpChildTop) {
            if (this != mpParent->mpChildBottom) {
                mpPrev->mpNext = mpNext;
                mpNext->mpPrev = mpPrev;
                mpNext = nullptr;
            } else {
                mpParent->mpChildBottom = mpPrev;
                mpPrev->mpNext = nullptr;
            }
            mpPrev = nullptr;
        } else {
            if (this != mpParent->mpChildBottom) {
                mpParent->mpChildTop = mpNext;
                mpNext->mpPrev = nullptr;
                mpNext = nullptr;
            } else {
                mpParent->mpChildBottom = nullptr;
                mpParent->mpChildTop = nullptr;
            }
        }
        mpParent = nullptr;
        mpRootComponent = this;
    }
    if (pParent == nullptr) {
        return;
    }
    mpParent = pParent;
    mpRootComponent = pParent->mpRootComponent;
    if (pParent->mpChildTop != nullptr) {
        if (pParent->mpChildBottom != nullptr) {
            pParent->mpChildBottom->mpNext = this;
            mpPrev = pParent->mpChildBottom;
            pParent->mpChildBottom = this;
        }
    } else {
        if (pParent->mpChildBottom != nullptr) {
            pParent->mpChildBottom->mpNext = this;
            mpPrev = pParent->mpChildBottom;
        } else {
            pParent->mpChildTop = this;
        }
        pParent->mpChildBottom = this;
    }
}

inline cpComponent::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpComponent::MyDTI cpComponent::DTI("cpComponent", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* cpComponent::MyDTI::newInstance() const {
    return new (16u) cpComponent;
}

void cpComponent::Iterator::begin(cpComponent* pBegin) {
    mpRoot = pBegin;
    mpCurrent = pBegin;
    mEnd = false;
    mDepth = 0;
    mIndex = 0;
}

void cpComponent::Iterator::next() {
    if (mpCurrent != nullptr) {
        if (mpCurrent->getChildTop() == nullptr) {
            cpComponent* v1_1;
            if (mpCurrent->getNext() != nullptr) {
                if (mpCurrent == mpRoot) {
                    mEnd = true;
                    mpCurrent = nullptr;
                    mIndex = 0;
                    return;
                } else {
                    v1_1 = mpCurrent->getNext();
                }
            } else {
                for (cpComponent* v0_0 = mpCurrent;;) {
                    cpComponent* t0 = v0_0->getParent();
                    mpCurrent = t0;
                    mDepth = mDepth - 1;
                    if (mpCurrent != nullptr) {
                        if (mpCurrent == mpRoot) {
                            mEnd = true;
                            mpCurrent = nullptr;
                            return;
                        } else {
                            if (t0->getNext() == nullptr) {
                                v0_0 = t0;
                            } else {
                                v1_1 = t0->getNext();
                                break;
                            }
                        }
                    } else {
                        mEnd = true;
                        mpCurrent = nullptr;
                        return;
                    }
                }
            }
            mpCurrent = v1_1;
        } else {
            mpCurrent = mpCurrent->getChildTop();
            mDepth = mDepth + 1;
        }
        mIndex = mIndex + 1;
    }
}

bool cpComponent::Iterator::isEnd() {
    return mEnd;
}

