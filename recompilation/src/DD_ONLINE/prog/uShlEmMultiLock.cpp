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

inline void* cShlParamMultiLock::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamMultiLock::DTI)->memAlloc(sz, align, cShlParamMultiLock::DTI.getID());
}

inline void cShlParamMultiLock::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamMultiLock::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMultiLock::getShlDTI() const {
    return uShlEmMultiLock::DTI;
}

void cShlParamMultiLock::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\347\224\237\346\210\220\343\201\231\343\202\213\343\202\267\343\202\247\343\203\253\343\201\256\345\220\221\343\201\215\343\201\256\350\250\210\347\256\227\343\202\222\343\201\227\343\201\252\343\201\204", &mNoCalcTgtDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\255\343\203\203\343\202\257\343\202\252\343\203\263\346\234\200\345\244\247\346\225\260", &mLockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\227\343\203\254\343\202\244\343\203\244\343\203\274\345\212\240\347\256\227\347\202\271\346\225\260", &mPlayerPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\235\343\203\274\343\203\263\345\212\240\347\256\227\347\202\271\346\225\260", &mPawnPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\357\274\256\357\274\260\357\274\243\345\212\240\347\256\227\347\202\271\346\225\260", &mNpcPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\267\235\351\233\242", static_cast<MtObject*>(&mDist[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\247\222\345\272\246", static_cast<MtObject*>(&mAngle[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\251\225\344\276\241\345\200\244", static_cast<MtObject*>(&mEval[0]), 32u, 4u);
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

inline void* cShlParamMultiLock::cRangePointTbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamMultiLock::cRangePointTbl::DTI)->memAlloc(sz, align, cShlParamMultiLock::cRangePointTbl::DTI.getID());
}

inline void cShlParamMultiLock::cRangePointTbl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamMultiLock::cRangePointTbl::DTI)->memFree(p_addr);
}

void cShlParamMultiLock::cRangePointTbl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\347\257\204\345\233\262", &mRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\202\271\346\225\260", &mPoint, 0u, 0u);
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

inline void cShlParamMultiLock::cShootCtrlParamMultiLock::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamMultiLock::cShootCtrlParamMultiLock::DTI)->memFree(p_addr);
}

void cShlParamMultiLock::cShootCtrlParamMultiLock::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\260\343\203\253\343\203\274\343\203\227", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\273\343\203\203\343\203\210\344\275\215\347\275\256", reinterpret_cast<s32*>(&mShlSetLocate), 0u, 0u);
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

inline void* uShlEmMultiLock::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlEmMultiLock::DTI)->memAlloc(sz, align, uShlEmMultiLock::DTI.getID());
}

inline void uShlEmMultiLock::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlEmMultiLock::DTI)->memFree(p_addr);
}

inline uShlEmMultiLock::uShlEmMultiLock() {
    mNoCalcTgtDir = false;
    mIsBlind = false;
    mShlSetNumGrp[4] = 0;
    mShlSetNumGrp[5] = 0;
    mShlSetNumGrp[2] = 0;
    mShlSetNumGrp[3] = 0;
    mShlSetNumGrp[0] = 0;
    mShlSetNumGrp[1] = 0;
    mLockNum = 1;
    mBaseVec = MtVector3::Zero;
    mTmpTargetArray.mpArray = nullptr;
    mTmpTargetArray.mBufsiz = 0;
    mTmpTargetArray.mLength = 0;
    mTargetArray.mpArray = nullptr;
    mTargetArray.mLength = 0;
    mTargetArray.mBufsiz = 0;
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
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\267\343\202\247\343\203\253\343\202\273\343\203\203\343\203\210\345\220\210\350\250\210\346\225\260", &mShlSetNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\260\343\203\253\343\203\274\343\203\227\346\257\216\343\201\256\343\202\267\343\202\247\343\203\253\343\202\273\343\203\203\343\203\210\346\225\260", &mShlSetNumGrp[0], 32u, 6u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\255\343\203\203\343\202\257\343\202\252\343\203\263\346\234\200\345\244\247\346\225\260", &mLockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\241\343\202\244\343\203\263\343\202\277\343\203\274\343\202\262\343\203\203\343\203\210\343\201\270\343\201\256\345\237\272\346\272\226\343\203\231\343\202\257\343\203\210\343\203\253", &mBaseVec, 0u, 0u);
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
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mTargetArray.mpArray[i]) + 8)) != 0) {
                    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mTargetArray.mpArray[i]) + 8)) + 16)) & 7u) - 1u) > 1u) {
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mTargetArray.mpArray[i]) + 8) = 0;
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

inline void* uShlEmMultiLock::cTargetList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlEmMultiLock::cTargetList::DTI)->memAlloc(sz, align, uShlEmMultiLock::cTargetList::DTI.getID());
}

inline void uShlEmMultiLock::cTargetList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlEmMultiLock::cTargetList::DTI)->memFree(p_addr);
}

inline uShlEmMultiLock::cTargetList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlEmMultiLock::cTargetList::MyDTI uShlEmMultiLock::cTargetList::DTI("uShlEmMultiLock::cTargetList", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uShlEmMultiLock::cTargetList::MyDTI::newInstance() const {
    return new (16u) uShlEmMultiLock::cTargetList;
}

template MtTypedArray<uShlEmMultiLock::cTargetList>::~MtTypedArray();

