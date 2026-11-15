// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestUnitManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextInterface.h"
#include "cOmControl.h"
#include "../../XFramework/cResource.h"
#include "cSetInfoCoord.h"
#include "cSetInfoNpc.h"
#include "cSetInfoOm.h"
#include "../../XFramework/cUnit.h"
#include "cpLayout.h"
#include "nLayout.h"
#include "nQuest.h"
#include "rOmParam.h"
#include "rQuestList.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "sGame.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "sQuestManagerExt.h"
#include "sSetManager.h"
#include "sWorldOffset.h"
#include "uControl.h"
#include "uControlNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestUnitGroup::getDTI() const {
    return cQuestUnitGroup::DTI;
}

inline void* cQuestUnitGroup::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cQuestUnitGroup::DTI)->memAlloc(sz, align, cQuestUnitGroup::DTI.getID());
}

inline void cQuestUnitGroup::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestUnitGroup::DTI)->memFree(p_addr);
}

cQuestUnitGroup::~cQuestUnitGroup() {
    release();
}

__attribute__((weak)) void cQuestUnitGroup::move() {
    DDON_STUB("cQuestUnitGroup::move")
    /* stub */
}

__attribute__((weak)) void cQuestUnitGroup::release() {
    if (mpGroup != nullptr) {
        if (mCtrlListOm.mLength != 0) {
            for (unsigned int i0_3 = 0;;) {
                MtObject* t0 = mCtrlListOm.getBuffer()[static_cast<int>(i0_3)];
                if (t0 != nullptr) {
                    if (static_cast<cOmControl*>(t0)->isEnableCtrl()) {
                        sOmManager::getInstance()->releaseOmCtrl(static_cast<cOmControl*>(t0));
                    }
                }
                mCtrlListOm.getBuffer()[static_cast<int>(i0_3)] = nullptr;
                if ((i0_3 + 1u) < mCtrlListOm.mLength) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mCtrlListNpc.mLength != 0) {
            u32 v3_0 = mCtrlListNpc.mLength;
            unsigned int i3_3 = 0;
            u32 v4_0;
            MtObject* * v4_1;
            for (;;) {
                if (mCtrlListNpc.getBuffer()[static_cast<int>(i3_3)] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    if (!static_cast<cUnit*>(mCtrlListNpc.getBuffer()[static_cast<int>(i3_3)])->isEnable()) {
                        v4_0 = v3_0;
                    } else {
                        sControlManager::getInstance()->releaseUnit(static_cast<uControl*>(mCtrlListNpc.getBuffer()[static_cast<int>(i3_3)]));
                        v4_0 = mCtrlListNpc.mLength;
                    }
                }
                v4_1 = mCtrlListNpc.getBuffer();
                v4_1[static_cast<int>(i3_3)] = nullptr;
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mCtrlListOm.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCtrlListOm.mpArray));
        }
        mCtrlListOm.mpArray = nullptr;
        mCtrlListOm.mBufsiz = 0;
        mCtrlListOm.mLength = 0;
        if (mCtrlListNpc.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCtrlListNpc.mpArray));
        }
        mCtrlListNpc.mpArray = nullptr;
        mCtrlListNpc.mBufsiz = 0;
        mCtrlListNpc.mLength = 0;
    }
}

__attribute__((weak)) void cQuestUnitGroup::updateOm(cQuestSet* pSet, u32 idx) {
    DDON_STUB("cQuestUnitGroup::updateOm")
    /* stub */
}

__attribute__((weak)) void cQuestUnitGroup::updateNpc(cQuestSet* pSet, u32 idx) {
    DDON_STUB("cQuestUnitGroup::updateNpc")
    /* stub */
}

__attribute__((weak)) cOmControl* cQuestUnitGroup::createOm(cQuestSet* pSet) {
    DDON_STUB("cQuestUnitGroup::createOm")
    return nullptr;
}

__attribute__((weak)) uControlNpc* cQuestUnitGroup::createNpc(cQuestSet* pSet) {
    DDON_STUB("cQuestUnitGroup::createNpc")
    return nullptr;
}

inline cQuestUnitGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestUnitGroup::MyDTI cQuestUnitGroup::DTI("cQuestUnitGroup", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* cQuestUnitGroup::MyDTI::newInstance() const {
    return new (16u) cQuestUnitGroup;
}

const MtDTI& cQuestUnitManager::getDTI() const {
    return cQuestUnitManager::DTI;
}

inline MtAllocator* cQuestUnitManager::getAllocator() {
    return MtMemoryAllocator::getAllocator(cQuestUnitManager::DTI);
}

void* cQuestUnitManager::operator new(size_t sz, u32 align) {
    return cQuestUnitManager::getAllocator()->memAlloc(sz, align, cQuestUnitManager::DTI.getID());
}

inline void cQuestUnitManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestUnitManager::DTI)->memFree(p_addr);
}

cQuestUnitManager::cQuestUnitManager() {
    mQuestId = 0;
    mStageNo = -1;
    mpQuestList = nullptr;
}

cQuestUnitManager::~cQuestUnitManager() {
    release();
}

__attribute__((weak)) void cQuestUnitManager::createProperty(MtPropertyList& s) {
    DDON_STUB("cQuestUnitManager::createProperty")
    /* stub */
}

__attribute__((weak)) void cQuestUnitManager::init(u32 questId, s32 stageNo, rQuestList* pRes) {
    DDON_STUB("cQuestUnitManager::init")
    /* stub */
}

void cQuestUnitManager::move() {
    u32 i = 0;
    if (mGroupList.mLength != 0) {
        do {
            if (mGroupList.getBuffer()[static_cast<int>(i)] != nullptr) {
                static_cast<cQuestUnitGroup*>(mGroupList.getBuffer()[static_cast<int>(i)])->move();
            }
            i += 1u;
        } while (i < mGroupList.mLength);
    }
}

__attribute__((weak)) void cQuestUnitManager::release() {
    mQuestId = 0;
    mStageNo = 0;
    if (mGroupList.mLength == 0) {
        if (mGroupList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroupList.mpArray));
        }
        mGroupList.mpArray = nullptr;
        mGroupList.mBufsiz = 0;
        mGroupList.mLength = 0;
        if (mpQuestList != nullptr) {
            mpQuestList->release();
            mpQuestList = nullptr;
        }
        return;
    } else {
        u32 v0_0 = mGroupList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGroupList.getBuffer()[static_cast<int>(i0_3)] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<cQuestUnitGroup*>(mGroupList.getBuffer()[static_cast<int>(i0_3)])->release();
                v1_0 = mGroupList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 == 0) {
            if (mGroupList.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroupList.mpArray));
            }
            mGroupList.mpArray = nullptr;
            mGroupList.mBufsiz = 0;
            mGroupList.mLength = 0;
            if (mpQuestList != nullptr) {
                mpQuestList->release();
                mpQuestList = nullptr;
            }
            return;
        } else {
            u32 v3_0 = v1_0;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mGroupList.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    delete mGroupList.mpArray[i3_3];
                    v4_0 = mGroupList.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
            if (mGroupList.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroupList.mpArray));
            }
            mGroupList.mpArray = nullptr;
            mGroupList.mBufsiz = 0;
            mGroupList.mLength = 0;
            if (mpQuestList != nullptr) {
                mpQuestList->release();
                mpQuestList = nullptr;
            }
            return;
        }
    }
}

inline cQuestUnitManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestUnitManager::MyDTI cQuestUnitManager::DTI("cQuestUnitManager", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cQuestUnitManager::MyDTI::newInstance() const {
    return new (16u) cQuestUnitManager;
}

template MtTypedArray<cOmControl>::~MtTypedArray();

template MtTypedArray<cQuestUnitGroup>::~MtTypedArray();

template MtTypedArray<uControlNpc>::~MtTypedArray();

