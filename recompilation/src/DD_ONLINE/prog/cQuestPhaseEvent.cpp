// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestPhaseEvent.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cQuestPhaseState.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestPhaseEvent::getDTI() const {
    return cQuestPhaseEvent::DTI;
}

inline MtAllocator* cQuestPhaseEvent::getAllocator() {
    return MtMemoryAllocator::getAllocator(cQuestPhaseEvent::DTI);
}

void* cQuestPhaseEvent::operator new(size_t sz, u32 align) {
    return cQuestPhaseEvent::getAllocator()->memAlloc(sz, align, cQuestPhaseEvent::DTI.getID());
}

inline void cQuestPhaseEvent::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestPhaseEvent::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool cQuestPhaseEvent::callPhaseEvent(cQuestPhaseState* pState, cQuestPhaseEvent* pEvent, const cQuestPhaseEvent::ParamArray& paramList) {
    DDON_STUB("cQuestPhaseEvent::callPhaseEvent")
    return {};
}

void cQuestPhaseEvent::callPhaseEventCancel(cQuestPhaseState* pState, cQuestPhaseEvent* pEvent, const cQuestPhaseEvent::ParamArray& paramList) {
    if (pEvent->getEventId() == 5) {
        cQuestPhaseState::resetReturnPlayerId(pState);
    } else {
        if (pEvent->getEventId() == 2) {
            cQuestPhaseState::resetWarpPlayerId(pState);
        }
    }
}

bool cQuestPhaseEvent::phaseEventDicideDividePlayer(cQuestPhaseState* pState, const cQuestPhaseEvent::ParamArray& paramList) {
    unsigned int v0_0 = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&paramList) + 8);
    if (v0_0 != 0) {
        unsigned long v0_1 = *reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(&paramList) + 24);
        for (unsigned int i0_2 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_1 + static_cast<unsigned long>(i0_2 * 8u)) + 0)) + 8)) == 1) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_1 + static_cast<unsigned long>(i0_2 * 8u)) + 0)) + 12)) == 0) {
                    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_1 + static_cast<unsigned long>(i0_2 * 8u)) + 0)) + 16);
                    cQuestPhaseState::setDivideSuccess(pState, t0, false);
                    if (t0 != 0) {
                        cQuestPhaseState::setWarpPlayerId(pState, t0);
                        cQuestPhaseState::setWarpPlayer(pState);
                        cQuestPhaseState::resetDivideSetup(pState);
                        return true;
                    } else {
                        return false;
                    }
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
    }
    cQuestPhaseState::setDivideSuccess(pState, 0u, false);
    return false;
}

bool cQuestPhaseEvent::phaseEventDicideDividePlayerEx(cQuestPhaseState* pState, const cQuestPhaseEvent::ParamArray& paramList) {
    u32 v0_0 = paramList.mLength;
    u32 v5_3;
    u32 v5_5;
    if (v0_0 == 0) {
        v5_3 = 0;
        v5_5 = 0;
    } else {
        MtObject* * v0_1 = paramList.mpArray;
        unsigned int i0_2 = 0;
        u32 v2_4;
        for (;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 1) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 12)) == 0) {
                    v2_4 = static_cast<cQuestPhaseEvent::cParam*>(v0_1[i0_2])->getValue();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = 0;
                break;
            }
        }
        for (unsigned int i3_2 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i3_2]) + 8)) == 1) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i3_2]) + 12)) == 1) {
                    v5_3 = static_cast<cQuestPhaseEvent::cParam*>(v0_1[i3_2])->getValue();
                    v5_5 = v2_4;
                    break;
                }
            }
            if ((i3_2 + 1u) < v0_0) {
                i3_2 = i3_2 + 1u;
            } else {
                v5_3 = 0;
                v5_5 = v2_4;
                break;
            }
        }
    }
    cQuestPhaseState::resetDivideSetup(pState);
    cQuestPhaseState::setDivideSuccess(pState, v5_5, false);
    cQuestPhaseState::setDivideSuccess(pState, v5_3, false);
    cQuestPhaseState::resetReturnPlayerId(pState);
    if (v5_5 != 0) {
        if (v5_3 != 0) {
            cQuestPhaseState::setDivideCharacterId(pState, v5_5, 0u);
            cQuestPhaseState::setDivideCharacterId(pState, v5_3, 1u);
        }
    }
    return true;
}

__attribute__((weak)) bool cQuestPhaseEvent::phaseEventReturnPlayer(cQuestPhaseState* pState, const cQuestPhaseEvent::ParamArray& paramList) {
    DDON_STUB("cQuestPhaseEvent::phaseEventReturnPlayer")
    return {};
}

const cQuestPhaseEvent::ParamArray& cQuestPhaseEvent::getParamList() const {
    return mParamList;
}

__attribute__((weak)) void cQuestPhaseEvent::addParam(u32 type, u32 idx, u32 value) {
    DDON_STUB("cQuestPhaseEvent::addParam")
    /* stub */
}

cQuestPhaseEvent::cQuestPhaseEvent(u32 eventId) {
    mEventId = eventId;
}

cQuestPhaseEvent::~cQuestPhaseEvent() {
    if (mParamList.mLength != 0) {
        u32 v0_0 = mParamList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mParamList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mParamList.mpArray[i0_3];
                v1_0 = mParamList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mParamList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamList.mpArray));
    }
    mParamList.mpArray = nullptr;
    mParamList.mBufsiz = 0;
    mParamList.mLength = 0;
}

__attribute__((weak)) void cQuestPhaseEvent::createProperty(MtPropertyList& s) {
}

inline cQuestPhaseEvent::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestPhaseEvent::MyDTI cQuestPhaseEvent::DTI("cQuestPhaseEvent", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cQuestPhaseEvent::MyDTI::newInstance() const {
    return new (16u) cQuestPhaseEvent;
}

const MtDTI& cQuestPhaseEvent::cParam::getDTI() const {
    return cQuestPhaseEvent::cParam::DTI;
}

inline void* cQuestPhaseEvent::cParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cQuestPhaseEvent::cParam::DTI)->memAlloc(sz, align, cQuestPhaseEvent::cParam::DTI.getID());
}

inline void cQuestPhaseEvent::cParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestPhaseEvent::cParam::DTI)->memFree(p_addr);
}

cQuestPhaseEvent::cParam::~cParam() {
}

__attribute__((weak)) void cQuestPhaseEvent::cParam::createProperty(MtPropertyList& s) {
}

inline cQuestPhaseEvent::cParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestPhaseEvent::cParam::MyDTI cQuestPhaseEvent::cParam::DTI("cQuestPhaseEvent::cParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cQuestPhaseEvent::cParam::MyDTI::newInstance() const {
    return new (16u) cQuestPhaseEvent::cParam;
}

template MtTypedArray<cQuestPhaseEvent::cParam>::~MtTypedArray();

