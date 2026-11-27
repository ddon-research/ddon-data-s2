// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAISvFSM.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cAIService.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAISvFSM::getDTI() const {
    return cAISvFSM::DTI;
}

cAISvFSM::~cAISvFSM() {
    if (mpFSMTop != nullptr) {
        for (FSMInfo* v0_5 = mpFSMTop;;) {
            FSMInfo* t0 = v0_5->mpNext;
            delete v0_5;
            if (t0 != nullptr) {
                v0_5 = t0;
            } else {
                break;
            }
        }
    }
}

MtUI* cAISvFSM::createUI(MtProperty& prop) {
    return nullptr;
}

void cAISvFSM::createProperty(MtPropertyList& s) {
    this->cAIService::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mFSMList", reinterpret_cast<MT_MFUNC>(&::cAISvFSM::getFSMInfo), reinterpret_cast<MT_MFUNC>(&::cAISvFSM::setFSMInfo), 1184u, reinterpret_cast<MT_MFUNC>(&::cAISvFSM::getFSMInfoNum), reinterpret_cast<MT_MFUNC>(&::cAISvFSM::setFSMInfoNum));
}

__attribute__((weak)) void cAISvFSM::reset() {
}

__attribute__((weak)) void cAISvFSM::move() {
}

__attribute__((weak)) void cAISvFSM::drawDebug() {
}

__attribute__((weak)) void cAISvFSM::entryFSM(cAIFSM* pFSM) {
    DDON_STUB("cAISvFSM::entryFSM")
    /* stub */
}

void cAISvFSM::removeFSM(cAIFSM* pFSM) {
    lock();
    if (pFSM != nullptr) {
        for (FSMInfo* v0_4 = mpFSMTop;;) {
            if (v0_4 == nullptr) {
                break;
            } else {
                if (pFSM == v0_4->mpFSM) {
                    FSMInfo* t0 = v0_4->mpPrev;
                    FSMInfo* t1 = v0_4->mpNext;
                    if (t0 != nullptr) {
                        t0->mpNext = t1;
                        if (t1 != nullptr) {
                            t1->mpPrev = t0;
                        } else {
                            mpFSMBottom = t0;
                        }
                    } else {
                        mpFSMTop = t1;
                        if (mpFSMTop != nullptr) {
                            t1->mpPrev = t0;
                        } else {
                            mpFSMBottom = t0;
                        }
                    }
                    delete v0_4;
                    break;
                } else {
                    v0_4 = v0_4->mpNext;
                }
            }
        }
    }
    unlock();
}

cAISvFSM::FSMInfo* cAISvFSM::getFSMInfo(u32 index) {
    if (mpFSMTop != nullptr) {
        FSMInfo* pFSM = mpFSMTop;
        for (u32 v0_1 = index + 1u;;) {
            if ((v0_1 - 1u) == 0) {
                return pFSM;
            } else {
                if (pFSM->mpNext != nullptr) {
                    pFSM = pFSM->mpNext;
                    v0_1 += 0xFFFFFFFFu;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

u32 cAISvFSM::getFSMInfoNum() {
    unsigned int i0_0 = 0;
    for (FSMInfo* pFSM = mpFSMTop;;) {
        if (pFSM == nullptr) {
            break;
        } else {
            i0_0 += 1u;
            pFSM = pFSM->mpNext;
        }
    }
    return i0_0;
}

__attribute__((weak)) void cAISvFSM::setFSMInfo(cAISvFSM::FSMInfo*, u32) {
}

__attribute__((weak)) void cAISvFSM::setFSMInfoNum(u32) {
}

inline cAISvFSM::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvFSM::MyDTI cAISvFSM::DTI("cAISvFSM", &::cAIService::DTI, 64ul, 0u, 0u);

MtObject* cAISvFSM::MyDTI::newInstance() const {
    return new (16u) cAISvFSM;
}

const MtDTI& cAISvFSM::FSMInfo::getDTI() const {
    return cAISvFSM::FSMInfo::DTI;
}

cAISvFSM::FSMInfo::~FSMInfo() {
    mpOwner = nullptr;
}

void cAISvFSM::FSMInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U64, "mInfoID", reinterpret_cast<MT_MFUNC>(&::cAISvFSM::FSMInfo::getInfoID), reinterpret_cast<MT_MFUNC>(&::cAISvFSM::FSMInfo::setInfoID), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpFSM", reinterpret_cast<MtObject* *>(&mpFSM), 0u, 0u);
}

MtUI* cAISvFSM::FSMInfo::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) uintptr cAISvFSM::FSMInfo::getInfoID() {
    DDON_STUB("cAISvFSM::FSMInfo::getInfoID")
    return {};
}

__attribute__((weak)) void cAISvFSM::FSMInfo::setInfoID(uintptr) {
}

inline cAISvFSM::FSMInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAISvFSM::FSMInfo::MyDTI cAISvFSM::FSMInfo::DTI("cAISvFSM::FSMInfo", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cAISvFSM::FSMInfo::MyDTI::newInstance() const {
    DDON_STUB("cAISvFSM::FSMInfo::MyDTI::newInstance")
    return nullptr;
}

