// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlEmMultiLock.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cEvaluation.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpAISensor.h"
#include "cpComponent.h"
#include "cpOcdCtrl.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "res_ptr.h"
#include "sSetManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#include "uShlGenerator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamMultiLock::getDTI() const {
    return cShlParamMultiLock::DTI;
}

MtDTI& cShlParamMultiLock::getShlDTI() const {
    return uShlEmMultiLock::DTI;
}

void cShlParamMultiLock::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "生成するシェルの向きの計算をしない", &mNoCalcTgtDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ロックオン最大数", &mLockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "プレイヤー加算点数", &mPlayerPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ポーン加算点数", &mPawnPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ＮＰＣ加算点数", &mNpcPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "距離", static_cast<MtObject*>(&mDist[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "角度", static_cast<MtObject*>(&mAngle[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "評価値", static_cast<MtObject*>(&mEval[0]), 32u, 4u);
}

__attribute__((weak)) void cShlParamMultiLock::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamMultiLock::copy")
    /* stub */
}

__attribute__((weak)) void cShlParamMultiLock::addShlList(const cShlParamGenerator* pParam) {
    DDON_STUB("cShlParamMultiLock::addShlList")
    /* stub */
}

inline cShlParamMultiLock::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMultiLock::MyDTI cShlParamMultiLock::DTI("cShlParamMultiLock", &::cShlParamGenerator::DTI, 608ul, 0u, 0u);

MtObject* cShlParamMultiLock::MyDTI::newInstance() const {
    return new (16u) cShlParamMultiLock;
}

const MtDTI& cShlParamMultiLock::cRangePointTbl::getDTI() const {
    return cShlParamMultiLock::cRangePointTbl::DTI;
}

void cShlParamMultiLock::cRangePointTbl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "範囲", &mRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "点数", &mPoint, 0u, 0u);
}

MtUIList* cShlParamMultiLock::cRangePointTbl::createUIList(MtUIList* pList) {
    return pList;
}

MtUI* cShlParamMultiLock::cRangePointTbl::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cShlParamMultiLock::cRangePointTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMultiLock::cRangePointTbl::MyDTI cShlParamMultiLock::cRangePointTbl::DTI("cShlParamMultiLock::cRangePointTbl", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cShlParamMultiLock::cRangePointTbl::MyDTI::newInstance() const {
    return new (16u) cShlParamMultiLock::cRangePointTbl;
}

const MtDTI& cShlParamMultiLock::cShootCtrlParamMultiLock::getDTI() const {
    return cShlParamMultiLock::cShootCtrlParamMultiLock::DTI;
}

void cShlParamMultiLock::cShootCtrlParamMultiLock::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "グループ", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "セット位置", reinterpret_cast<s32*>(&mShlSetLocate), 0u, 0u);
    this->cShlParamGenerator::cShootCtrlParam::createProperty(s);
}

inline cShlParamMultiLock::cShootCtrlParamMultiLock::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMultiLock::cShootCtrlParamMultiLock::MyDTI cShlParamMultiLock::cShootCtrlParamMultiLock::DTI("cShlParamMultiLock::cShootCtrlParamMultiLock", &::cShlParamGenerator::cShootCtrlParam::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamMultiLock::cShootCtrlParamMultiLock::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamMultiLock::cShootCtrlParamMultiLock::DTI)->memAlloc(sizeof(cShlParamMultiLock::cShootCtrlParamMultiLock), 16u, cShlParamMultiLock::cShootCtrlParamMultiLock::DTI.getID())) cShlParamMultiLock::cShootCtrlParamMultiLock;
}

const MtDTI& uShlEmMultiLock::getDTI() const {
    return uShlEmMultiLock::DTI;
}

__attribute__((noinline)) uShlEmMultiLock::~uShlEmMultiLock() {
    if (mTargetArray.mLength != 0) {
        u32 v0_0 = mTargetArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTargetArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTargetArray.mpArray[i0_3];
                v1_0 = mTargetArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTargetArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTargetArray.mpArray));
    }
    mTargetArray.mpArray = nullptr;
    mTargetArray.mBufsiz = 0;
    mTargetArray.mLength = 0;
}

void uShlEmMultiLock::createProperty(MtPropertyList& s) {
    this->uDDOModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "シェルセット合計数", &mShlSetNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "グループ毎のシェルセット数", &mShlSetNumGrp[0], 32u, 6u);
    s << MtProperty(static_cast<MtObject*>(this), "ロックオン最大数", &mLockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "メインターゲットへの基準ベクトル", &mBaseVec, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTmpTargetArray", static_cast<MtObject*>(&mTmpTargetArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetArray", static_cast<MtObject*>(&mTargetArray), 0u, 0u);
}

MtUI* uShlEmMultiLock::createUI(MtProperty& prop) {
    return this->uModel::createUI(prop);
}

void uShlEmMultiLock::setup() {
    this->uShlGenerator::setup();
    if (getShlParamBase() != nullptr) {
        mNoCalcTgtDir = static_cast<bool>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(getShlParamBase()) + 396));
        mLockNum = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 400);
    }
    if (mpOwner == nullptr) {
        return;
    }
    if (mpOwner->isEnable()) {
        if (mpOwner->getOcdCtrlPtr() != nullptr) {
            if (mpOwner->getOcdCtrlPtr()->isOcdActive(4112u)) {
                mIsBlind = true;
            }
        }
        if (mpOwner->isMaster()) {
            registryTarget();
        } else {
            registryTargetSlave();
        }
    }
}

__attribute__((weak)) void uShlEmMultiLock::initSub() {
}

void uShlEmMultiLock::updatePtr() {
    this->uShlBase::updatePtr();
    u32 v0_0 = mTargetArray.mLength;
    if (v0_0 != 0) {
        for (u32 i = 0;;) {
            if (mTargetArray.mpArray[i] != nullptr) {
                if (static_cast<cTargetList*>(mTargetArray.mpArray[i])->mpTarget != nullptr) {
                    if (!static_cast<cTargetList*>(mTargetArray.mpArray[i])->mpTarget->isEnable()) {
                        static_cast<cTargetList*>(mTargetArray.mpArray[i])->mpTarget = nullptr;
                    }
                }
            }
            if (v0_0 != (i + 1u)) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
}

void uShlEmMultiLock::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
}

bool uShlEmMultiLock::sortTargetList(const uShlEmMultiLock::cTargetList* pListA, const uShlEmMultiLock::cTargetList* pListB, u32) {
    return pListB->mPrio >= pListA->getPrio();
}

__attribute__((weak)) void uShlEmMultiLock::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY) {
    DDON_STUB("uShlEmMultiLock::setShl")
    /* stub */
}

__attribute__((weak)) bool uShlEmMultiLock::registryTarget() {
    DDON_STUB("uShlEmMultiLock::registryTarget")
    return {};
}

__attribute__((weak)) bool uShlEmMultiLock::registryTargetSlave() {
    DDON_STUB("uShlEmMultiLock::registryTargetSlave")
    return {};
}

__attribute__((weak)) u32 uShlEmMultiLock::calcPriorityPoint(uDDOModel* pTgt) {
    DDON_STUB("uShlEmMultiLock::calcPriorityPoint")
    return {};
}

inline uShlEmMultiLock::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlEmMultiLock::MyDTI uShlEmMultiLock::DTI("uShlEmMultiLock", &::uShlGenerator::DTI, 11072ul, 0u, 0u);

MtObject* uShlEmMultiLock::MyDTI::newInstance() const {
    return new (16u) uShlEmMultiLock;
}

const MtDTI& uShlEmMultiLock::cTargetList::getDTI() const {
    return uShlEmMultiLock::cTargetList::DTI;
}

inline uShlEmMultiLock::cTargetList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlEmMultiLock::cTargetList::MyDTI uShlEmMultiLock::cTargetList::DTI("uShlEmMultiLock::cTargetList", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uShlEmMultiLock::cTargetList::MyDTI::newInstance() const {
    return new (16u) uShlEmMultiLock::cTargetList;
}

template MtTypedArray<uShlEmMultiLock::cTargetList>::~MtTypedArray();

