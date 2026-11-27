// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cLayoutSet.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cResource.h"
#include "cSetInfo.h"
#include "cSetInfoCoord.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "rLayout.h"
#include "rLayoutGroupParam.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sFlag.h"
#include "sGame.h"
#include "sSetManager.h"
#include "uDDOModel.h"
#include "uStageField.h"
#include "uStageJoint.h"
#include "uStageParts.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cLayoutSet::getDTI() const {
    return cLayoutSet::DTI;
}

cLayoutSet::cLayoutSet() {
    DDON_STUB("cLayoutSet::cLayoutSet")
    /* stub */
}

cLayoutSet::~cLayoutSet() {
    kill();
}

__attribute__((weak)) void cLayoutSet::init(MT_CTSTR path, bool isBlocking) {
    DDON_STUB("cLayoutSet::init")
    /* stub */
}

__attribute__((weak)) void cLayoutSet::update() {
    DDON_STUB("cLayoutSet::update")
    /* stub */
}

__attribute__((weak)) void cLayoutSet::kill() {
    finish();
    if (isUseUnitData()) {
        if (mUnitDataArray.mLength != 0) {
            u32 v0_0 = mUnitDataArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mUnitDataArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mUnitDataArray.mpArray[i0_3];
                    v1_0 = mUnitDataArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mUnitDataArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mUnitDataArray.mpArray));
        }
        mUnitDataArray.mpArray = nullptr;
        mUnitDataArray.mBufsiz = 0;
        mUnitDataArray.mLength = 0;
    }
    if (mpRsrc != nullptr) {
        mpRsrc->release();
        mpRsrc = nullptr;
    }
    mUnitSetResourceComplete = false;
    mUnitScrollSbcComplete = false;
}

void cLayoutSet::setup() {
    mIsSetup = true;
}

__attribute__((weak)) void cLayoutSet::move() {
    DDON_STUB("cLayoutSet::move")
    /* stub */
}

void cLayoutSet::setRequest() {
    if (mIsNoSet) {
        return;
    }
    if (!mIsSetup) {
        return;
    }
    moveSetUnit();
}

MtObject* cLayoutSet::getUnit(u32 id) {
    u32 i = 0;
    if (mUnitArray.mLength != 0) {
        do {
            uDDOModel* pCB = static_cast<uDDOModel*>(mUnitArray.mpArray[i]);
            if (pCB != nullptr) {
                if (id == static_cast<unsigned int>(pCB->getSetNo())) {
                    return pCB;
                }
            }
            i += 1u;
        } while (i < mUnitArray.mLength);
    }
    return nullptr;
}

bool cLayoutSet::deleteAllUnit() {
    return true;
}

__attribute__((weak)) void cLayoutSet::updateUnitPtrArray(bool isErase) {
    DDON_STUB("cLayoutSet::updateUnitPtrArray")
    /* stub */
}

__attribute__((weak)) bool cLayoutSet::canSetUnit() const {
    DDON_STUB("cLayoutSet::canSetUnit")
    return {};
}

bool cLayoutSet::isSplitSbc(s32 areaNo) {
    if (areaNo > -1) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageJointCtrl() != nullptr) {
            return static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageJointCtrl()->isSbc(areaNo);
        } else {
            if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageFieldCtrl() != nullptr) {
                return static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageFieldCtrl()->isSetup();
            } else {
                return true;
            }
        }
    } else {
        return true;
    }
}

bool cLayoutSet::isUpdateArea() {
    s32 old_area = mAreaNo;
    uStageJointCtrl* pjnt = static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStageJointCtrl();
    if (pjnt != nullptr) {
        s32 t0 = pjnt->getPlayerCurrentAreaNo();
        mAreaNo = t0;
        return old_area != t0;
    } else {
        uStagePartsCtrl* ppts = static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getStagePartsCtrl();
        if (ppts != nullptr) {
            s32 t1 = ppts->getNowZ();
            mAreaNo = t1;
            return old_area != t1;
        } else {
            return false;
        }
    }
}

bool cLayoutSet::isUseUnitData() const {
    return true;
}

bool cLayoutSet::isLoadAreaChangeSet() const {
    return false;
}

void cLayoutSet::moveSetUnit() {
    if (mpRsrc != nullptr) {
        if (mpRsrc->isUsage()) {
            if (canSetUnit()) {
                if (mUnitArray.mLength != 0) {
                    for (unsigned int i0_3 = 0;;) {
                        if (mUnitArray.mpArray[i0_3] == nullptr) {
                            if (isUseUnitData()) {
                                if (static_cast<cUnitData*>(mUnitDataArray.getBuffer()[static_cast<int>(i0_3)])->mState == STATE_EMPTY) {
                                    rLayout::SetInfo* t0 = mpRsrc->getSetInfo(i0_3);
                                    if (t0 != nullptr) {
                                        if (t0->mpInfo != nullptr) {
                                            if (static_cast<cSetInfoCoord*>(t0->mpInfo)->getAreaHitNo() > -1) {
                                                if (((static_cast<unsigned long>(getAreaHitBit()) >> static_cast<unsigned long>(static_cast<cSetInfoCoord*>(t0->mpInfo)->getAreaHitNo() & 31)) & 1ul) != 0) {
                                                    MtObject* t1 = setLayoutUnit(mpRsrc, i0_3, false, 2u);
                                                    mUnitArray.mpArray[i0_3] = t1;
                                                }
                                            } else {
                                                MtObject* t1 = setLayoutUnit(mpRsrc, i0_3, false, 2u);
                                                mUnitArray.mpArray[i0_3] = t1;
                                            }
                                            if (mUnitArray.mpArray[i0_3] != nullptr) {
                                                mIsDeleted = false;
                                            }
                                        }
                                    }
                                }
                            } else {
                                rLayout::SetInfo* t0 = mpRsrc->getSetInfo(i0_3);
                                if (t0 != nullptr) {
                                    if (t0->mpInfo != nullptr) {
                                        if (static_cast<cSetInfoCoord*>(t0->mpInfo)->getAreaHitNo() > -1) {
                                            if (((static_cast<unsigned long>(getAreaHitBit()) >> static_cast<unsigned long>(static_cast<cSetInfoCoord*>(t0->mpInfo)->getAreaHitNo() & 31)) & 1ul) != 0) {
                                                MtObject* t1 = setLayoutUnit(mpRsrc, i0_3, false, 2u);
                                                mUnitArray.mpArray[i0_3] = t1;
                                            }
                                        } else {
                                            MtObject* t1 = setLayoutUnit(mpRsrc, i0_3, false, 2u);
                                            mUnitArray.mpArray[i0_3] = t1;
                                        }
                                        if (mUnitArray.mpArray[i0_3] != nullptr) {
                                            mIsDeleted = false;
                                        }
                                    }
                                }
                            }
                        }
                        if ((i0_3 + 1u) < mUnitArray.mLength) {
                            i0_3 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}

MtObject* cLayoutSet::setLayoutUnit(rLayout* pLayout, u32 no, bool isFroceSet, u32 mode) {
    return nullptr;
}

bool cLayoutSet::isUnitDataEmpty(u32 no) {
    if (isUseUnitData()) {
        return static_cast<cUnitData*>(mUnitDataArray.getBuffer()[static_cast<int>(no)])->mState == STATE_EMPTY;
    } else {
        return true;
    }
}

bool cLayoutSet::isValid() const {
    if (mpRsrc != nullptr) {
        return (mpRsrc->mState & 16u) == 0;
    }
    if (mUnitArray.mLength == 0) {
        return false;
    }
    u32 i = 0;
    do {
        if (mUnitArray.mpArray[i] != nullptr) {
            return true;
        }
        i += 1u;
    } while (i < mUnitArray.mLength);
    return false;
}

inline cLayoutSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLayoutSet::MyDTI cLayoutSet::DTI("cLayoutSet", &::MtObject::DTI, 136ul, 0u, 0u);

__attribute__((weak)) MtObject* cLayoutSet::MyDTI::newInstance() const {
    DDON_STUB("cLayoutSet::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cLayoutSet::cUnitData::getDTI() const {
    return cLayoutSet::cUnitData::DTI;
}

inline cLayoutSet::cUnitData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLayoutSet::cUnitData::MyDTI cLayoutSet::cUnitData::DTI("cLayoutSet::cUnitData", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cLayoutSet::cUnitData::MyDTI::newInstance() const {
    return new (16u) cLayoutSet::cUnitData;
}

template MtTypedArray<cLayoutSet::cUnitData>::~MtTypedArray();

