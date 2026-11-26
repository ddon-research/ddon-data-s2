// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cContextInstance.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContext.h"
#include "cContextPlayerInfo.h"
#include "cCorePointMsg.h"
#include "cEquipData.h"
#include "cPlayerLoadManager.h"
#include "../../XFramework/cResource.h"
#include "nActionManager.h"
#include "nCharacterData.h"
#include "../../generated/shared/nDDOGame.h"
#include "nDDOUtility.h"
#include "nNetMsgData.h"
#include "nObjCondition.h"
#include "nOcdMsg.h"
#include "rCharacterEdit.h"
#include "sArchiveManager.h"
#include "../../XFramework/sMain.h"
#include "sObjCondition.h"
#include "sWorldOffset.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cContextInstChar::getDTI() const {
    return cContextInstChar::DTI;
}

inline void cContextInstChar::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInstChar::DTI)->memFree(p_addr);
}

cContextInstChar::~cContextInstChar() {
}

__attribute__((weak)) void cContextInstChar::createProperty(MtPropertyList& s) {
    this->cContextInstance::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsDead", reinterpret_cast<MT_MFUNC>(&::cContextInstChar::isDead), reinterpret_cast<MT_MFUNC>(&::cContextInstChar::setIsDead), 161u, reinterpret_cast<MT_MFUNC>(&::cContextInstChar::getPRegionNum), reinterpret_cast<MT_MFUNC>(&::cContextInstChar::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), "mIsInjured", &mIsInjured, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLost", &mIsLost, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsRescue", &mIsRescue, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsReturnTerritory", &mIsReturnTerritory, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\241\214\345\213\225\347\225\252\345\217\267", &mActNo[0], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\247\273\345\213\225\351\200\237\345\272\246", &mMoveSpeed, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\247\273\345\213\225\346\226\271\345\220\221", &mMoveAngle, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetUid", &mTargetUid, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos.x", &mTargetPos.x, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos.y", &mTargetPos.y, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos.z", &mTargetPos.z, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\205\261\351\200\232\343\203\257\343\203\274\343\202\257", &mCommonWork, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PL,\346\225\265\347\224\250\350\207\252\347\224\261\343\203\257\343\203\274\343\202\257", &mCustomWork, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\250\343\203\263\343\203\201\343\203\243\343\203\263\343\203\210\345\200\215\347\216\207", &mEnchantRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\212\266\346\205\213\347\225\260\345\270\270\345\200\244", &mAilmentDamage, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\224\237\346\255\273\343\202\271\343\203\206\343\203\274\343\203\210", &mStateLive, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "LV", reinterpret_cast<MT_MFUNC>(&::cContextInstChar::getLv), reinterpret_cast<MT_MFUNC>(&::cContextInstChar::setLv), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\242\343\203\263\343\202\277\343\203\274\343\202\270\343\203\245\345\233\272\345\256\232\347\225\252\345\217\267", &mMontageFixNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\242\343\203\263\343\202\277\343\203\274\343\202\270\343\203\245\343\203\251\343\203\263\343\203\200\343\203\240\345\200\244", &mMontageRandom, 1u, 0u);
}

MtUI* cContextInstChar::createUI(MtProperty& prop) {
    return this->cContext::createUI(prop);
}

__attribute__((weak)) void cContextInstChar::reset() {
    DDON_STUB("cContextInstChar::reset")
    /* stub */
}

MtVector3 cContextInstChar::getCliffPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mCliffPos);
}

__attribute__((weak)) void cContextInstChar::setCliffPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setCliffPos")
    /* stub */
}

MtVector3 cContextInstChar::getCliffStartPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mCliffStartPos);
}

__attribute__((weak)) void cContextInstChar::setCliffStartPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setCliffStartPos")
    /* stub */
}

MtVector3 cContextInstChar::getCliffStartOldPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mCliffStartOldPos);
}

__attribute__((weak)) void cContextInstChar::setCliffStartOldPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setCliffStartOldPos")
    /* stub */
}

MtVector3 cContextInstChar::getTargetPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mTargetPos);
}

__attribute__((weak)) void cContextInstChar::setTargetPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setTargetPos")
    /* stub */
}

MtVector3 cContextInstChar::getWallClimbPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mWallClimbPos);
}

__attribute__((weak)) void cContextInstChar::setWallClimbPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setWallClimbPos")
    /* stub */
}

MtVector3 cContextInstChar::getWallClimbLandPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mWallClimbLandPos);
}

__attribute__((weak)) void cContextInstChar::setWallClimbLandPos(const MtVector3& pos) {
    DDON_STUB("cContextInstChar::setWallClimbLandPos")
    /* stub */
}

const nObjCondition::stOcdActiveMsg& cContextInstChar::getOcdActiveMsg(u32 index) const {
    return mOcdActiveMsgArray[index];
}

__attribute__((weak)) void cContextInstChar::makeOcdMsgArray() {
    DDON_STUB("cContextInstChar::makeOcdMsgArray")
    /* stub */
}

__attribute__((weak)) const nObjCondition::stOcdActiveData& cContextInstChar::getOcdActiveData(u32 OcdUID) const {
    DDON_STUB("cContextInstChar::getOcdActiveData")
    __builtin_unreachable();
}

__attribute__((weak)) const nObjCondition::stOcdActiveData& cContextInstChar::getOcdActiveData(u32 bank, u32 index) const {
    DDON_STUB("cContextInstChar::getOcdActiveData")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInstChar::setOcdActiveData(u32 OcdUID, const nObjCondition::stOcdActiveData& data, bool isTimerReset) {
        u32 bank = (OcdUID >> 12) & 0xF;
        u32 index = (OcdUID & 0xffff0fff) - 1;
        mOcdActiveData[bank][index].mActiveLv = data.mActiveLv;
        mOcdActiveData[bank][index].mImmuneLv = data.mImmuneLv;
        if (isTimerReset) {
            mOcdTimerResetBit[bank] |= 1 << index;
        } else {
            mOcdTimerResetBit[bank] &= ~(1 << index);
        }
}

__attribute__((weak)) void cContextInstChar::setOcdActiveData(u32 bank, u32 index, const nObjCondition::stOcdActiveData& data, bool isTimerReset) {
    DDON_STUB("cContextInstChar::setOcdActiveData")
    /* stub */
}

__attribute__((weak)) void cContextInstChar::resetOcdActiveDataAll(bool isImmuneReset) {
    DDON_STUB("cContextInstChar::resetOcdActiveDataAll")
    /* stub */
}

__attribute__((weak)) void cContextInstChar::resetOcdActiveDataGoodStatus() {
    DDON_STUB("cContextInstChar::resetOcdActiveDataGoodStatus")
    /* stub */
}

__attribute__((weak)) bool cContextInstChar::isOcdActive(u32 OcdUID) const {
    DDON_STUB("cContextInstChar::isOcdActive")
    return {};
}

__attribute__((weak)) f32 cContextInstChar::getOcdActiveTimer(u32 OcdUID) const {
    DDON_STUB("cContextInstChar::getOcdActiveTimer")
    return {};
}

__attribute__((weak)) void cContextInstChar::setOcdActiveTimer(u32 OcdUID, f32 timer) {
    DDON_STUB("cContextInstChar::setOcdActiveTimer")
    /* stub */
}

__attribute__((weak)) void cContextInstChar::setOcdActiveTimer(u32 bank, u32 index, f32 timer) {
    DDON_STUB("cContextInstChar::setOcdActiveTimer")
    /* stub */
}

void cContextInstChar::setOcdAllTimerResetFlag(bool flag) {
    mOcdAllTimerResetFlag = flag;
}

bool cContextInstChar::isOcdAllTimerReset() const {
    return mOcdAllTimerResetFlag;
}

bool cContextInstChar::isOcdTimerReset(u32 OcdUID) const {
    return ((static_cast<unsigned long>(mOcdTimerResetBit[(OcdUID >> 12) & 15u]) >> static_cast<unsigned long>((OcdUID - 1u) & 31u)) & 1ul) != 0;
}

void cContextInstChar::resetOcdTimerReset() {
    mOcdTimerResetBit[6] = 0;
    mOcdTimerResetBit[4] = 0;
    mOcdTimerResetBit[5] = 0;
    mOcdTimerResetBit[2] = 0;
    mOcdTimerResetBit[3] = 0;
    mOcdTimerResetBit[0] = 0;
    mOcdTimerResetBit[1] = 0;
}

bool cContextInstChar::isDead(u32 i) const {
    return mIsDead_pri[i];
}

void cContextInstChar::setIsDead(bool isDead, u32 i) {
    mIsDead_pri[i] = isDead;
    mIsDeadCheatCheck_pri[i] = mIsDead_pri[i];
}

__attribute__((weak)) void cContextInstChar::setHp(HP_DATATYPE hp, u32 i) {
    DDON_STUB("cContextInstChar::setHp")
    /* stub */
}

__attribute__((weak)) void cContextInstChar::setHpMax(HP_DATATYPE hpMax, u32 i) {
    DDON_STUB("cContextInstChar::setHpMax")
    /* stub */
}

bool cContextInstChar::getIsDeadCheatCheck(u32 i) const {
    return mIsDeadCheatCheck_pri[i];
}

__attribute__((weak)) HP_DATATYPE cContextInstChar::getHpCheatCheck(u32 i) const {
    DDON_STUB("cContextInstChar::getHpCheatCheck")
    return {};
}

__attribute__((weak)) HP_DATATYPE cContextInstChar::getHpMaxCheatCheck(u32 i) const {
    DDON_STUB("cContextInstChar::getHpMaxCheatCheck")
    return {};
}

s32 cContextInstChar::getLv() const {
    return mLv_pri;
}

void cContextInstChar::setLv(s32 lv) {
    mLv_pri = lv;
}

__attribute__((weak)) void cContextInstChar::addCorePointMsg(const cCorePointMsg* pSrc) {
    DDON_STUB("cContextInstChar::addCorePointMsg")
    /* stub */
}

__attribute__((weak)) u32 cContextInstChar::getUnSendedCorePointMsgNum() const {
    DDON_STUB("cContextInstChar::getUnSendedCorePointMsgNum")
    return {};
}

cCorePointMsg* cContextInstChar::getUnSendedTopCorePointMsg() const {
    if (mCorePointMsgArray.mLength != 0) {
        u32 i = 0;
        do {
            if (mCorePointMsgArray.mpArray[i] != nullptr) {
                if (!static_cast<cCorePointMsg*>(mCorePointMsgArray.mpArray[i])->isSended()) {
                    return static_cast<cCorePointMsg*>(mCorePointMsgArray.mpArray[i]);
                }
            }
            i += 1u;
        } while (i < mCorePointMsgArray.mLength);
    }
    return nullptr;
}

u32 cContextInstChar::getCorePointMsgNum() const {
    return mCorePointMsgArray.mLength;
}

cCorePointMsg* cContextInstChar::getCorePointMsg(u32 index) const {
    if (mCorePointMsgArray.mLength >= index) {
        return static_cast<cCorePointMsg*>(mCorePointMsgArray.mpArray[index]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void cContextInstChar::eraseCorePointMsg(u32 index) {
    DDON_STUB("cContextInstChar::eraseCorePointMsg")
    /* stub */
}

u32 cContextInstChar::getPRegionNum() const {
    return 10;
}

__attribute__((weak)) void cContextInstChar::setDummyU32(u32) {
}

inline cContextInstChar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInstChar::MyDTI cContextInstChar::DTI("cContextInstChar", &::cContextInstance::DTI, 2976ul, 0x50060000u, 0u);

__attribute__((weak)) MtObject* cContextInstChar::MyDTI::newInstance() const {
    DDON_STUB("cContextInstChar::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cContextInstEm::getDTI() const {
    return cContextInstEm::DTI;
}

inline void cContextInstEm::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInstEm::DTI)->memFree(p_addr);
}

cContextInstEm::~cContextInstEm() {
}

void cContextInstEm::createProperty(MtPropertyList& s) {
    this->cContextInstChar::createProperty(s);
}

MtUI* cContextInstEm::createUI(MtProperty& prop) {
    return this->cContext::createUI(prop);
}

void cContextInstEm::reset() {
    this->cContextInstChar::reset();
}

inline cContextInstEm::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInstEm::MyDTI cContextInstEm::DTI("cContextInstEm", &::cContextInstChar::DTI, 3008ul, 0x50090000u, 0u);

__attribute__((weak)) MtObject* cContextInstEm::MyDTI::newInstance() const {
    DDON_STUB("cContextInstEm::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cContextInstHm::getDTI() const {
    return cContextInstHm::DTI;
}

void* cContextInstHm::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cContextInstHm::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInstHm::DTI)->memFree(p_addr);
}

cContextInstHm::cContextInstHm() {
    DDON_STUB("cContextInstHm::cContextInstHm")
    /* stub */
}

cContextInstHm::~cContextInstHm() {
    if (mpCharacterEdit == nullptr) {
        return;
    }
    mpCharacterEdit->release();
    mpCharacterEdit = nullptr;
}

__attribute__((weak)) void cContextInstHm::createProperty(MtPropertyList& s) {
    this->cContextInstChar::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "HumanType", &mHumanType, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PawnType", &mPawnType, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CharId", &mCharId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PawnId", &mPawnId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PlLoadWep", &mPlayerLoadWeapon, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PlLoadStatus", &mPlayerLoadStatus, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\255\343\202\271\343\203\210\346\231\202\351\226\223", &mLostTime, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\271\343\203\206\343\203\274\343\202\270", &mStageNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\210\235\346\234\237\345\272\247\346\250\231Index", &mStartPosNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\200\247\345\210\245", &mSex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\253\343\203\251\343\203\274\343\202\277\343\202\244\343\203\227", &mColor, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\203\247\343\203\226", &mJob, 1u, 0u);
    mEquip.cEquipData::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\344\275\215\347\275\256\345\272\247\346\250\231", &mPosFreeMarker[0], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\271\343\203\206\343\203\274\343\202\270No.", &mStageNoFreeMarker[0], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\260\343\203\253\343\203\274\343\203\227No.", &mGroupNoFreeMarker[0], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\344\275\215\347\275\256\345\272\247\346\250\231", &mPosFreeMarker[1], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\271\343\203\206\343\203\274\343\202\270No.", &mStageNoFreeMarker[1], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\260\343\203\253\343\203\274\343\203\227No.", &mGroupNoFreeMarker[1], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\344\275\215\347\275\256\345\272\247\346\250\231", &mPosFreeMarker[2], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\271\343\203\206\343\203\274\343\202\270No.", &mStageNoFreeMarker[2], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\203\343\203\227\343\201\256\343\203\225\343\203\252\343\203\274\343\203\236\343\203\274\343\202\253\343\203\274\343\202\260\343\203\253\343\203\274\343\203\227No.", &mGroupNoFreeMarker[2], 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ability099", &mIsAbility098, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Guts", &mIsGutsDisable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ability370", &mIsAbility370, 1u, 0u);
}

MtUI* cContextInstHm::createUI(MtProperty& prop) {
    return this->cContext::createUI(prop);
}

__attribute__((weak)) void cContextInstHm::reset() {
    DDON_STUB("cContextInstHm::reset")
    /* stub */
}

void cContextInstHm::entryParty() {
    mOldGaugeContextType = 0;
}

void cContextInstHm::removeParty() {
    mIsValid = mIsValid & 247;
}

__attribute__((weak)) void cContextInstHm::subLostTime() {
    DDON_STUB("cContextInstHm::subLostTime")
    /* stub */
}

MtVector3 cContextInstHm::getLastSafePos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mSafePos);
}

__attribute__((weak)) void cContextInstHm::setLastSafePos(const MtVector3& pos) {
    DDON_STUB("cContextInstHm::setLastSafePos")
    /* stub */
}

inline cContextInstHm::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInstHm::MyDTI cContextInstHm::DTI("cContextInstHm", &::cContextInstChar::DTI, 16784ul, 0x50070000u, 0u);

__attribute__((weak)) MtObject* cContextInstHm::MyDTI::newInstance() const {
    DDON_STUB("cContextInstHm::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cContextInstNpc::getDTI() const {
    return cContextInstNpc::DTI;
}

inline void cContextInstNpc::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInstNpc::DTI)->memFree(p_addr);
}

cContextInstNpc::~cContextInstNpc() {
}

void cContextInstNpc::createProperty(MtPropertyList& s) {
    this->cContextInstHm::createProperty(s);
}

MtUI* cContextInstNpc::createUI(MtProperty& prop) {
    return this->cContext::createUI(prop);
}

__attribute__((weak)) void cContextInstNpc::reset() {
    DDON_STUB("cContextInstNpc::reset")
    /* stub */
}

inline cContextInstNpc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInstNpc::MyDTI cContextInstNpc::DTI("cContextInstNpc", &::cContextInstHm::DTI, 16784ul, 0x500A0000u, 0u);

__attribute__((weak)) MtObject* cContextInstNpc::MyDTI::newInstance() const {
    DDON_STUB("cContextInstNpc::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cContextInstance::getDTI() const {
    return cContextInstance::DTI;
}

inline void* cContextInstance::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cContextInstance::DTI)->memAlloc(sz, align, cContextInstance::DTI.getID());
}

inline void cContextInstance::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInstance::DTI)->memFree(p_addr);
}

cContextInstance::~cContextInstance() {
}

__attribute__((weak)) void cContextInstance::createProperty(MtPropertyList& s) {
    this->cContext::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUniqueId", &mUniqueId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\211\345\212\271\346\200\247", &mIsValid, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetWaitFlag", &mSetWaitFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PosX", &mNetPos.x, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PosY", &mNetPos.y, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PosZ", &mNetPos.z, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Dir", &mNetDir, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Stage", &mStageNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMasterIndex", &mMasterIndex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\250\343\203\263\343\202\253\343\202\246\343\203\263\343\203\210\343\202\250\343\203\252\343\202\242", &mMainEncountArea, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\216\264\343\201\277\343\202\277\343\202\244\343\203\227", &mCatchType, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\216\264\343\201\277\347\233\270\346\211\213UID", &mCatchTargetUid, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\216\264\343\201\277\343\202\263\343\203\263\343\202\271\343\203\210\351\226\242\347\257\200", &mCatchJointNo, 1u, 0u);
}

MtUI* cContextInstance::createUI(MtProperty& prop) {
    return this->cContext::createUI(prop);
}

void cContextInstance::reset() {
    mIsValid = 0;
    mNetPos.x = 0.0;
    mNetPos.y = 0.0f;
    mNetDir = 0.0f;
    mStageNo = 0;
    mNetPos.z = 0.0;
    mMasterIndex = -1;
    mMainEncountArea = -1;
    mMasterChangeFlag = false;
    mSendChangeMaster = false;
    mSetWaitFlag = false;
    mCatchType = 0;
    mCatchTargetUid = 0;
    mCatchJointNo = 0xFF;
    mQuestId = 0;
}

MtVector3 cContextInstance::getNetPos() const {
    return sWorldOffset::getInstance()->getOffsetNetPos(mNetPos);
}

__attribute__((weak)) void cContextInstance::setNetPos(const MtVector3& pos) {
    DDON_STUB("cContextInstance::setNetPos")
    /* stub */
}

inline cContextInstance::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInstance::MyDTI cContextInstance::DTI("cContextInstance", &::cContext::DTI, 104ul, 0x50050000u, 0u);

MtObject* cContextInstance::MyDTI::newInstance() const {
    return new (16u) cContextInstance;
}

template MtTypedArray<cCorePointMsg>::~MtTypedArray();

