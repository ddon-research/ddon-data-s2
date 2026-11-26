// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cAIUserProcess.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cAIObject.h"
#include "cAISvUserProcess.h"
#include "sAI.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAICopiableParameter::getDTI() const {
    return cAICopiableParameter::DTI;
}

inline void cAICopiableParameter::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAICopiableParameter::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cAICopiableParameter::copy(cAICopiableParameter* pParam) {
    DDON_STUB("cAICopiableParameter::copy")
    /* stub */
}

inline cAICopiableParameter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAICopiableParameter::MyDTI cAICopiableParameter::DTI("cAICopiableParameter", &::cAIResource::DTI, 8ul, 0u, 0u);

__attribute__((weak)) MtObject* cAICopiableParameter::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cAICopiableParameter::DTI)->memAlloc(sizeof(cAICopiableParameter), 16u, cAICopiableParameter::DTI.getID())) cAICopiableParameter;
}

const MtDTI& cAIUserProcess::getDTI() const {
    return cAIUserProcess::DTI;
}

inline void cAIUserProcess::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIUserProcess::DTI)->memFree(p_addr);
}

cAIUserProcess::~cAIUserProcess() {
    DDON_STUB("cAIUserProcess::~cAIUserProcess")
    /* stub */
}

void cAIUserProcess::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
}

s32 cAIUserProcess::callProcessWithExamine(MtObject* pOwner, MtObject* pParam, MtObject* pCaller, bool permitsCaller) {
    EXAMINE_RESULT t0 = examine(pOwner, pParam, pCaller, permitsCaller);
    if (t0 == EXR_FAIL) {
        return 0;
    } else {
        if (t0 == EXR_PASS_CALLER) {
            return process(pCaller, pParam, pCaller);
        } else {
            return process(pOwner, pParam, pCaller);
        }
    }
}

s32 cAIUserProcess::process(MtObject* pOwner, MtObject* pParam, MtObject* pCaller) {
    return 0;
}

cAIUserProcess::EXAMINE_RESULT cAIUserProcess::examine(MtObject* pOwner, MtObject* pParam, MtObject* pCaller, bool permitsCaller) {
    if (pOwner != nullptr) {
        if (pCaller != nullptr) {
            if (permitsCaller) {
                if (pCaller->getDTI().mID != mpOwnerDTI->mID) {
                    if (pParam != nullptr) {
                        if (mpParamDTI == nullptr) {
                            return EXR_FAIL;
                        } else {
                            return EXR_PASS;
                        }
                    } else {
                        if (mpParamDTI == nullptr) {
                            return EXR_PASS;
                        } else {
                            return EXR_FAIL;
                        }
                    }
                } else {
                    if (pParam != nullptr) {
                        if (mpParamDTI == nullptr) {
                            return EXR_FAIL;
                        } else {
                            return EXR_PASS_CALLER;
                        }
                    } else {
                        if (mpParamDTI == nullptr) {
                            return EXR_PASS_CALLER;
                        } else {
                            return EXR_FAIL;
                        }
                    }
                }
            } else {
                if (pParam != nullptr) {
                    if (mpParamDTI == nullptr) {
                        return EXR_FAIL;
                    } else {
                        return EXR_PASS;
                    }
                } else {
                    if (mpParamDTI == nullptr) {
                        return EXR_PASS;
                    } else {
                        return EXR_FAIL;
                    }
                }
            }
        } else {
            if (pParam != nullptr) {
                if (mpParamDTI == nullptr) {
                    return EXR_FAIL;
                } else {
                    return EXR_PASS;
                }
            } else {
                if (mpParamDTI == nullptr) {
                    return EXR_PASS;
                } else {
                    return EXR_FAIL;
                }
            }
        }
    } else {
        if (mpOwnerDTI == nullptr) {
            if (pParam != nullptr) {
                if (mpParamDTI == nullptr) {
                    return EXR_FAIL;
                } else {
                    return EXR_PASS;
                }
            } else {
                if (mpParamDTI == nullptr) {
                    return EXR_PASS;
                } else {
                    return EXR_FAIL;
                }
            }
        } else {
            return EXR_FAIL;
        }
    }
}

inline cAIUserProcess::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIUserProcess::MyDTI cAIUserProcess::DTI("cAIUserProcess", &::cAIObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIUserProcess::MyDTI::newInstance() const {
    DDON_STUB("cAIUserProcess::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIUserProcessCallback::getDTI() const {
    return cAIUserProcessCallback::DTI;
}

void* cAIUserProcessCallback::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIUserProcessCallback::DTI)->memAlloc(sz, align, cAIUserProcessCallback::DTI.mID);
}

inline void cAIUserProcessCallback::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIUserProcessCallback::DTI)->memFree(p_addr);
}

cAIUserProcessCallback::~cAIUserProcessCallback() {
    DDON_STUB("cAIUserProcessCallback::~cAIUserProcessCallback")
    /* stub */
}

void cAIUserProcessCallback::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
}

s32 cAIUserProcessCallback::process(MtObject* pOwner, MtObject* pParam, MtObject* pCaller) {
    if (mpFunc != static_cast<cAIUserProcessCallback::CALLBACK_FUNC>(0)) {
        return static_cast<s32>((pOwner->*mpFunc)(pParam, pCaller));
    } else {
        return 0;
    }
}

inline cAIUserProcessCallback::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIUserProcessCallback::MyDTI cAIUserProcessCallback::DTI("cAIUserProcessCallback", &::cAIUserProcess::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIUserProcessCallback::MyDTI::newInstance() const {
    DDON_STUB("cAIUserProcessCallback::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIUserProcessContainer::getDTI() const {
    return cAIUserProcessContainer::DTI;
}

cAIUserProcessContainer::~cAIUserProcessContainer() {
    DDON_STUB("cAIUserProcessContainer::~cAIUserProcessContainer")
    /* stub */
}

void cAIUserProcessContainer::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "ContainerList", reinterpret_cast<MT_MFUNC>(&::cAIUserProcessContainer::getProcess), reinterpret_cast<MT_MFUNC>(&::cAIUserProcessContainer::setProcess), 160u, reinterpret_cast<MT_MFUNC>(&::cAIUserProcessContainer::getProcessNum), reinterpret_cast<MT_MFUNC>(&::cAIUserProcessContainer::setProcessNum));
}

void cAIUserProcessContainer::addProcess(cAIUserProcess* pProc) {
    if (pProc == nullptr) {
        return;
    }
    if (mpProcessListTop != nullptr) {
        cAIUserProcess* t0 = mpProcessListBottom;
        t0->mpNext = pProc;
        pProc->mpPrev = t0;
        pProc->mpNext = nullptr;
        mpProcessListBottom = pProc;
    } else {
        mpProcessListTop = pProc;
        pProc->mpPrev = nullptr;
        pProc->mpNext = nullptr;
        mpProcessListBottom = pProc;
    }
}

void cAIUserProcessContainer::eraseProcessAll() {
    if (mpProcessListTop != nullptr) {
        for (cAIUserProcess* pdel = mpProcessListTop;;) {
            cAIUserProcess* t0 = pdel->mpNext;
            delete pdel;
            if (t0 != nullptr) {
                pdel = t0;
            } else {
                break;
            }
        }
    }
}

u32 cAIUserProcessContainer::getProcessNum() {
    unsigned int i0_0 = 0;
    for (cAIUserProcess* pc = mpProcessListTop;;) {
        if (pc == nullptr) {
            break;
        } else {
            i0_0 += 1u;
            pc = pc->mpNext;
        }
    }
    return i0_0;
}

__attribute__((weak)) void cAIUserProcessContainer::setProcessNum(u32 num) {
}

cAIUserProcess* cAIUserProcessContainer::getProcess(u32 index) {
    cAIUserProcess* v1_0;
    if (index == 0) {
        v1_0 = mpProcessListTop;
    } else {
        if (mpProcessListTop == nullptr) {
            v1_0 = mpProcessListTop;
        } else {
            cAIUserProcess* v0_0 = mpProcessListTop;
            for (unsigned int i0_1 = 1;;) {
                if (i0_1 >= index) {
                    v1_0 = v0_0->mpNext;
                    break;
                } else {
                    if (v0_0->mpNext != nullptr) {
                        v0_0 = v0_0->mpNext;
                        i0_1 += 1u;
                    } else {
                        v1_0 = v0_0->mpNext;
                        break;
                    }
                }
            }
        }
    }
    return v1_0;
}

cAIUserProcess* cAIUserProcessContainer::searchProcess(MT_CTSTR n) {
    cAIUserProcess* v2_8;
    if (mpProcessListTop == nullptr) {
        v2_8 = nullptr;
    } else {
        for (cAIUserProcess* pc = mpProcessListTop;;) {
            if (pc->mName.value != nullptr) {
                if (strcmp(n, reinterpret_cast<const char*>(pc->mName.value->str)) != 0) {
                    if (pc->mpNext != nullptr) {
                        pc = pc->mpNext;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = pc;
                    return v2_8;
                }
            } else {
                if ((*n) != '\0') {
                    if (pc->mpNext != nullptr) {
                        pc = pc->mpNext;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = pc;
                    return v2_8;
                }
            }
        }
        v2_8 = nullptr;
    }
    return v2_8;
}

__attribute__((weak)) void cAIUserProcessContainer::setProcess(cAIUserProcess* pc, u32 index) {
}

inline cAIUserProcessContainer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIUserProcessContainer::MyDTI cAIUserProcessContainer::DTI("cAIUserProcessContainer", &::cAIObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIUserProcessContainer::MyDTI::newInstance() const {
    DDON_STUB("cAIUserProcessContainer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIUserProcessReference::getDTI() const {
    return cAIUserProcessReference::DTI;
}

inline void* cAIUserProcessReference::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIUserProcessReference::DTI)->memAlloc(sz, align, cAIUserProcessReference::DTI.mID);
}

inline void cAIUserProcessReference::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIUserProcessReference::DTI)->memFree(p_addr);
}

cAIUserProcessReference::~cAIUserProcessReference() {
}

void cAIUserProcessReference::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mContainerName", &mContainerName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategoryName", &mCategoryName, 0u, 0u);
}

__attribute__((weak)) cAIUserProcessContainer* cAIUserProcessReference::getProcessContainer() {
    if (mCategoryName.ptr()[0] != '\0') {
        const MtDTI* pdti = MtDTI::from(mCategoryName.ptr(), cAIUserProcessContainer::DTI);
        if (pdti == nullptr) {
            return nullptr;
        }
        return static_cast<cAISvUserProcess*>(sAI::getInstance()->getService(cAISvUserProcess::DTI, nullptr))->searchContainer(mContainerName.ptr(), *pdti);
    }
    return static_cast<cAISvUserProcess*>(sAI::getInstance()->getService(cAISvUserProcess::DTI, nullptr))->searchContainer(mContainerName.ptr());
}

inline cAIUserProcessReference::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIUserProcessReference::MyDTI cAIUserProcessReference::DTI("cAIUserProcessReference", &::cAIResource::DTI, 24ul, 0u, 0u);

MtObject* cAIUserProcessReference::MyDTI::newInstance() const {
    return new (16u) cAIUserProcessReference;
}

