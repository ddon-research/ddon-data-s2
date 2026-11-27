// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpWaypoint.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpInput.h"
#include "cpPathFinding.h"
#include "../../generated/shared/nDDOMath.h"
#include "rWaypoint.h"
#include "rWaypoint2.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sMain.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpWaypoint::getDTI() const {
    return cpWaypoint::DTI;
}

void* cpWaypoint::operator new(size_t sz, u32 align) {
    return cpWaypoint::getAllocator()->memAlloc(sz, align, cpWaypoint::DTI.getID());
}

void cpWaypoint::setActive(bool active) {
    mActive = active;
}

__attribute__((weak)) void cpWaypoint::setGoalPointNo(s32 pointNo0, s32 pointNo1, s32 pointNo2) {
    DDON_STUB("cpWaypoint::setGoalPointNo")
    /* stub */
}

MtVector3 cpWaypoint::getNextPoint() const {
    if ((sArea::mpInstance)->mpArea[2] != nullptr) {
        if (static_cast<sAreaExt*>(sArea::mpInstance)->isStage()) {
            if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getWaypoint() != nullptr) {
                return static_cast<rWaypoint::cPoint*>(static_cast<aStage*>(sArea::getInstance()->mpArea[2])->getWaypoint()->mPointList.getBuffer()[mNextPointNo])->mPos;
            }
        }
    }
    return MtVector3::Zero;
}

__attribute__((weak)) void cpWaypoint::checkGoal() {
    DDON_STUB("cpWaypoint::checkGoal")
    /* stub */
}

void cpWaypoint::setMoveType(s32 moveType) {
    if (static_cast<unsigned int>(moveType - 1) <= 1) {
        mMoveType = moveType;
    }
}

__attribute__((weak)) void cpWaypoint::calcNextPoint() {
    DDON_STUB("cpWaypoint::calcNextPoint")
    /* stub */
}

__attribute__((weak)) void cpWaypoint::calcGotoPoint() {
    DDON_STUB("cpWaypoint::calcGotoPoint")
    /* stub */
}

__attribute__((weak)) void cpWaypoint::updateNextPoint() {
    DDON_STUB("cpWaypoint::updateNextPoint")
    /* stub */
}

__attribute__((weak)) void cpWaypoint::traceNaviMesh() {
    DDON_STUB("cpWaypoint::traceNaviMesh")
    /* stub */
}

__attribute__((weak)) void cpWaypoint::openDoor() {
    DDON_STUB("cpWaypoint::openDoor")
    /* stub */
}

cpWaypoint::cpWaypoint() {
    mNextPointNo = -1;
    mGotoPointNo = -1;
    mIsGoal = false;
    mGoalIndex = -1;
    mOpenDoorUID = 0;
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mMoveType = 2;
    mIsCheckScr = true;
    mGoalPointNo[2] = -1;
    mGoalPointNo[0] = -1;
    mGoalPointNo[1] = -1;
    mActive = false;
}

cpWaypoint::~cpWaypoint() {
    if (mWork.mLength != 0) {
        u32 v0_0 = mWork.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWork.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mWork.mpArray[i0_3];
                v1_0 = mWork.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWork.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mWork.mpArray));
    }
    mWork.mpArray = nullptr;
    mWork.mBufsiz = 0;
    mWork.mLength = 0;
}

void cpWaypoint::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGoalPointNo[GOAL_IDX_0]", &mGoalPointNo[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGoalPointNo[GOAL_IDX_1]", &mGoalPointNo[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGoalPointNo[GOAL_IDX_2]", &mGoalPointNo[2], 0u, 0u);
}

void cpWaypoint::move() {
    if (!isActive()) {
        return;
    }
    if (mOpenDoorUID != 0) {
        if (sOmManager::getInstance()->isOpenEndDoorHalf(mOpenDoorUID)) {
            mOpenDoorUID = 0;
            mIsGoal = false;
            updateNextPoint();
            traceNaviMesh();
            openDoor();
        }
    } else {
        mIsGoal = false;
        updateNextPoint();
        traceNaviMesh();
        openDoor();
    }
}

inline cpWaypoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpWaypoint::MyDTI cpWaypoint::DTI("cpWaypoint", &::cpComponent::DTI, 176ul, 0u, 0u);

MtObject* cpWaypoint::MyDTI::newInstance() const {
    return new (16u) cpWaypoint;
}

const MtDTI& cpWaypoint::cWork::getDTI() const {
    return cpWaypoint::cWork::DTI;
}

inline cpWaypoint::cWork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpWaypoint::cWork::MyDTI cpWaypoint::cWork::DTI("cpWaypoint::cWork", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cpWaypoint::cWork::MyDTI::newInstance() const {
    return new (16u) cpWaypoint::cWork;
}

template MtTypedArray<cpWaypoint::cWork>::~MtTypedArray();

