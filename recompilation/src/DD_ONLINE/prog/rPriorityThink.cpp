// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rPriorityThink.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCRC.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "aStage.h"
#include "cAIGrid.h"
#include "../../XFramework/cAIObject.h"
#include "cAITargetInfo.h"
#include "cContextInterface.h"
#include "cEquipData.h"
#include "cEvaluation.h"
#include "cGeneralPoint.h"
#include "cOcdBase.h"
#include "cOmComponent.h"
#include "../../XFramework/cUnit.h"
#include "cpAIPawnEmChecker.h"
#include "cpComponent.h"
#include "cpCorePointCtrl.h"
#include "cpHugeble.h"
#include "cpInput.h"
#include "cpJob02.h"
#include "cpJob03.h"
#include "cpJob04.h"
#include "cpJob05.h"
#include "cpJob09.h"
#include "cpOcdCtrl.h"
#include "cpPathFinding.h"
#include "cpjob10.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nPawn.h"
#include "nShlStick.h"
#include "rAIPawnOrder.h"
#include "rPawnAI.h"
#include "rTbl2.h"
#include "sAIPawnSys.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sContextManager.h"
#include "sGeneralPoint.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sShlManager.h"
#include "sTalkManager.h"
#include "sWorldOffset.h"
#include "uCharacter.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "uOmModel.h"
#include "uShlBakuensen.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cPrioThkCode>::allocData(unsigned int);
#endif

const MtDTI& cPrioThkCmd::getDTI() const {
    return cPrioThkCmd::DTI;
}

cPrioThkCmd::~cPrioThkCmd() {
}

u32 cPrioThkCmd::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return 0;
}

__attribute__((weak)) void cPrioThkCmd::load(MtDataReader&) {
}

__attribute__((weak)) void cPrioThkCmd::save(MtDataWriter&) {
}

__attribute__((weak)) void cPrioThkCmd::addEnableActID(cPrioThkIO& io, uDDOModel& owner, cPrioThkCmd::cTmpResultIO& dst, cPawnAIAction* pAct, cGeneralPoint* pTarget, s32 prio, const cAIPawnActionGroupFlag* pFlag) {
    DDON_STUB("cPrioThkCmd::addEnableActID")
    /* stub */
}

__attribute__((weak)) void cPrioThkCmd::calcDoAction(cPrioThkIO& io, uCharacter& owner, cPrioThkCmd::cTmpResultIO& dst, MtTypedArray<cPawnAIAction>& actTbl, bool isSupport) {
    DDON_STUB("cPrioThkCmd::calcDoAction")
    /* stub */
}

__attribute__((weak)) void cPrioThkCmd::searchPartyOtherPlayer(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst) {
    DDON_STUB("cPrioThkCmd::searchPartyOtherPlayer")
    /* stub */
}

__attribute__((weak)) void cPrioThkCmd::searchPartyPawn(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst) {
    DDON_STUB("cPrioThkCmd::searchPartyPawn")
    /* stub */
}

__attribute__((weak)) bool cPrioThkCmd::isEnablePrioThkStatusFlag(const cPrioThkStatusFlag& flag, uDDOModel& target) {
    DDON_STUB("cPrioThkCmd::isEnablePrioThkStatusFlag")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportPre(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportPre")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportNearEm(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportNearEm")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportPartyNoEnchant(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportPartyNoEnchant")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportPartyNoElmC(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportPartyNoElmC")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportSameElemWithOrder(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportSameElemWithOrder")
    return {};
}

__attribute__((weak)) bool cPrioThkCmd::isEnableActInterSupportAfter(cPrioThkIO& io, uCharacter& owner, cPawnAIAction* pPwAct, uCharacter* pTarget) const {
    DDON_STUB("cPrioThkCmd::isEnableActInterSupportAfter")
    return {};
}

__attribute__((weak)) void cPrioThkCmd::getProperTarget(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst, cPawnAIAction* pAct, bool isSupport) {
    DDON_STUB("cPrioThkCmd::getProperTarget")
    /* stub */
}

__attribute__((weak)) void cPrioThkCmd::getProperTargetTarget(cPrioThkIO& io, uCharacter& owner, MtTypedArray<uCharacter>& dst, bool(*checkFunc)(uCharacter&)) {
    DDON_STUB("cPrioThkCmd::getProperTargetTarget")
    /* stub */
}

inline cPrioThkCmd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmd::MyDTI cPrioThkCmd::DTI("cPrioThkCmd", &::cAIResource::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmd::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmd;
}

const MtDTI& cPrioThkCmd::cTmpResult::getDTI() const {
    return cPrioThkCmd::cTmpResult::DTI;
}

inline cPrioThkCmd::cTmpResult::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmd::cTmpResult::MyDTI cPrioThkCmd::cTmpResult::DTI("cPrioThkCmdRetEnemyTable::cTmpResult", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmd::cTmpResult::MyDTI::newInstance() const {
        return new (16u) cTmpResult;
}

const MtDTI& cPrioThkCmdAddAnimalCoop::getDTI() const {
    return cPrioThkCmdAddAnimalCoop::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddAnimalCoop::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddAnimalCoop::check")
    return {};
}

inline cPrioThkCmdAddAnimalCoop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddAnimalCoop::MyDTI cPrioThkCmdAddAnimalCoop::DTI("cPrioThkCmdAddAnimalCoop", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddAnimalCoop::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddAnimalCoop;
}

const MtDTI& cPrioThkCmdAddAnimalProtect::getDTI() const {
    return cPrioThkCmdAddAnimalProtect::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddAnimalProtect::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddAnimalProtect::check")
    return {};
}

inline cPrioThkCmdAddAnimalProtect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddAnimalProtect::MyDTI cPrioThkCmdAddAnimalProtect::DTI("cPrioThkCmdAddAnimalProtect", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddAnimalProtect::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddAnimalProtect;
}

const MtDTI& cPrioThkCmdAddBase::getDTI() const {
    return cPrioThkCmdAddBase::DTI;
}

u32 cPrioThkCmdAddBase::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return 1;
}

__attribute__((weak)) void cPrioThkCmdAddBase::addResultAllEnemy(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddBase::addResultAllEnemy")
    /* stub */
}

void cPrioThkCmdAddBase::load(MtDataReader& r) {
    nDDOIO::readData(r, mFilter);
}

inline cPrioThkCmdAddBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddBase::MyDTI cPrioThkCmdAddBase::DTI("cPrioThkCmdAddBase", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddBase::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddBase;
}

const MtDTI& cPrioThkCmdAddBreakTarget::getDTI() const {
    return cPrioThkCmdAddBreakTarget::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddBreakTarget::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddBreakTarget::check")
    return {};
}

void cPrioThkCmdAddBreakTarget::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
        } else {
            mFilter = false;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
    }
}

inline cPrioThkCmdAddBreakTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddBreakTarget::MyDTI cPrioThkCmdAddBreakTarget::DTI("cPrioThkCmdAddBreakTarget", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddBreakTarget::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddBreakTarget;
}

const MtDTI& cPrioThkCmdAddCoreNearTarget::getDTI() const {
    return cPrioThkCmdAddCoreNearTarget::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddCoreNearTarget::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddCoreNearTarget::check")
    return {};
}

void cPrioThkCmdAddCoreNearTarget::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetType = t6;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetType = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetType = t6;
    }
}

inline cPrioThkCmdAddCoreNearTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddCoreNearTarget::MyDTI cPrioThkCmdAddCoreNearTarget::DTI("cPrioThkCmdAddCoreNearTarget", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddCoreNearTarget::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddCoreNearTarget;
}

const MtDTI& cPrioThkCmdAddEnemy::getDTI() const {
    return cPrioThkCmdAddEnemy::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddEnemy::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddEnemy::check")
    return {};
}

void cPrioThkCmdAddEnemy::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            f32 t6 = r.readF32();
            mHpRateMin = t6;
            f32 t7 = r.readF32();
            mHpRateMax = t7;
            f32 t8 = r.readF32();
            mLenXZMin = t8;
            f32 t9 = r.readF32();
            mLenXZMax = t9;
            u32 t10 = r.readU32();
            mAddSortType = t10;
        } else {
            mFilter = false;
            f32 t6 = r.readF32();
            mHpRateMin = t6;
            f32 t7 = r.readF32();
            mHpRateMax = t7;
            f32 t8 = r.readF32();
            mLenXZMin = t8;
            f32 t9 = r.readF32();
            mLenXZMax = t9;
            u32 t10 = r.readU32();
            mAddSortType = t10;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        f32 t6 = r.readF32();
        mHpRateMin = t6;
        f32 t7 = r.readF32();
        mHpRateMax = t7;
        f32 t8 = r.readF32();
        mLenXZMin = t8;
        f32 t9 = r.readF32();
        mLenXZMax = t9;
        u32 t10 = r.readU32();
        mAddSortType = t10;
    }
}

inline cPrioThkCmdAddEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddEnemy::MyDTI cPrioThkCmdAddEnemy::DTI("cPrioThkCmdAddEnemy", &::cPrioThkCmdAddBase::DTI, 32ul, 0u, 0u);

MtObject* cPrioThkCmdAddEnemy::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddEnemy;
}

const MtDTI& cPrioThkCmdAddEnemyClimb::getDTI() const {
    return cPrioThkCmdAddEnemyClimb::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddEnemyClimb::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddEnemyClimb::check")
    return {};
}

inline cPrioThkCmdAddEnemyClimb::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddEnemyClimb::MyDTI cPrioThkCmdAddEnemyClimb::DTI("cPrioThkCmdAddEnemyClimb", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddEnemyClimb::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddEnemyClimb;
}

const MtDTI& cPrioThkCmdAddEnemyHp::getDTI() const {
    return cPrioThkCmdAddEnemyHp::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddEnemyHp::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddEnemyHp::check")
    return {};
}

__attribute__((weak)) void cPrioThkCmdAddEnemyHp::load(MtDataReader& r) {
    DDON_STUB("cPrioThkCmdAddEnemyHp::load")
    /* stub */
}

inline cPrioThkCmdAddEnemyHp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddEnemyHp::MyDTI cPrioThkCmdAddEnemyHp::DTI("cPrioThkCmdAddEnemyHp", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddEnemyHp::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddEnemyHp;
}

const MtDTI& cPrioThkCmdAddEnemyRange::getDTI() const {
    return cPrioThkCmdAddEnemyRange::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddEnemyRange::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddEnemyRange::check")
    return {};
}

__attribute__((weak)) void cPrioThkCmdAddEnemyRange::load(MtDataReader& r) {
    DDON_STUB("cPrioThkCmdAddEnemyRange::load")
    /* stub */
}

inline cPrioThkCmdAddEnemyRange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddEnemyRange::MyDTI cPrioThkCmdAddEnemyRange::DTI("cPrioThkCmdAddEnemyRange", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddEnemyRange::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddEnemyRange;
}

const MtDTI& cPrioThkCmdAddErosionRequest::getDTI() const {
    return cPrioThkCmdAddErosionRequest::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddErosionRequest::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddErosionRequest::check")
    return {};
}

void cPrioThkCmdAddErosionRequest::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
        } else {
            mFilter = false;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
    }
}

inline cPrioThkCmdAddErosionRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddErosionRequest::MyDTI cPrioThkCmdAddErosionRequest::DTI("cPrioThkCmdAddErosionRequest", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddErosionRequest::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddErosionRequest;
}

const MtDTI& cPrioThkCmdAddEvaluation::getDTI() const {
    return cPrioThkCmdAddEvaluation::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddEvaluation::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddEvaluation::check")
    return {};
}

void cPrioThkCmdAddEvaluation::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetType = t6;
            f32 t8 = r.readF32();
            mEveValueMin = t8;
            f32 t10 = r.readF32();
            mEveValueMax = t10;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetType = t6;
            f32 t8 = r.readF32();
            mEveValueMin = t8;
            f32 t10 = r.readF32();
            mEveValueMax = t10;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetType = t6;
        f32 t8 = r.readF32();
        mEveValueMin = t8;
        f32 t10 = r.readF32();
        mEveValueMax = t10;
    }
}

inline cPrioThkCmdAddEvaluation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddEvaluation::MyDTI cPrioThkCmdAddEvaluation::DTI("cPrioThkCmdAddEvaluation", &::cPrioThkCmdAddBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdAddEvaluation::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddEvaluation;
}

const MtDTI& cPrioThkCmdAddHiPrioEnemy::getDTI() const {
    return cPrioThkCmdAddHiPrioEnemy::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddHiPrioEnemy::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddHiPrioEnemy::check")
    return {};
}

void cPrioThkCmdAddHiPrioEnemy::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mRemoveFlgs = t6;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mRemoveFlgs = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mRemoveFlgs = t6;
    }
}

inline cPrioThkCmdAddHiPrioEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddHiPrioEnemy::MyDTI cPrioThkCmdAddHiPrioEnemy::DTI("cPrioThkCmdAddHiPrioEnemy", &::cPrioThkCmdAddBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdAddHiPrioEnemy::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddHiPrioEnemy;
}

const MtDTI& cPrioThkCmdAddParty::getDTI() const {
    return cPrioThkCmdAddParty::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddParty::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddParty::check")
    return {};
}

__attribute__((weak)) void cPrioThkCmdAddParty::checkSub(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, uCharacter* pChar) {
    DDON_STUB("cPrioThkCmdAddParty::checkSub")
    /* stub */
}

u32 cPrioThkCmdAddParty::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return 1;
}

void cPrioThkCmdAddParty::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
    }
}

inline cPrioThkCmdAddParty::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddParty::MyDTI cPrioThkCmdAddParty::DTI("cPrioThkCmdAddParty", &::cPrioThkCmdAddBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdAddParty::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddParty;
}

const MtDTI& cPrioThkCmdAddPartyAction::getDTI() const {
    return cPrioThkCmdAddPartyAction::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddPartyAction::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddPartyAction::checkEx")
    return {};
}

void cPrioThkCmdAddPartyAction::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            mDoActNo = t11;
            s32 t13 = r.readS32();
            mDoActNoJob = t13;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            mDoActNo = t11;
            s32 t13 = r.readS32();
            mDoActNoJob = t13;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        u32 t11 = r.readU32();
        mDoActNo = t11;
        s32 t13 = r.readS32();
        mDoActNoJob = t13;
    }
}

inline cPrioThkCmdAddPartyAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyAction::MyDTI cPrioThkCmdAddPartyAction::DTI("cPrioThkCmdAddPartyAction", &::cPrioThkCmdAddParty::DTI, 32ul, 0u, 0u);

MtObject* cPrioThkCmdAddPartyAction::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddPartyAction;
}

const MtDTI& cPrioThkCmdAddPartyHp::getDTI() const {
    return cPrioThkCmdAddPartyHp::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddPartyHp::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddPartyHp::checkEx")
    return {};
}

void cPrioThkCmdAddPartyHp::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mHpRateMin = t11;
            f32 t12 = r.readF32();
            mHpRateMax = t12;
            f32 t13 = r.readF32();
            mWhiteHpRateMin = t13;
            f32 t14 = r.readF32();
            mWhiteHpRateMax = t14;
            u32 t15 = r.mSeekPt;
            u32 t16 = r.mBufsiz;
            if (t15 >= t16) {
                if (r.refill()) {
                    u32 t18 = r.mSeekPt;
                    u8* t19 = r.mBuffer;
                    u8 t20 = t19[r.mSeekPt];
                    r.mSeekPt = t18 + 1u;
                    mWhiteNoZero = t20 != 0;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t23 = r.readF32();
                    mTargetDistanceY = t23;
                } else {
                    mWhiteNoZero = false;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t23 = r.readF32();
                    mTargetDistanceY = t23;
                }
            } else {
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t15 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t23 = r.readF32();
                mTargetDistanceY = t23;
            }
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mHpRateMin = t11;
            f32 t12 = r.readF32();
            mHpRateMax = t12;
            f32 t13 = r.readF32();
            mWhiteHpRateMin = t13;
            f32 t14 = r.readF32();
            mWhiteHpRateMax = t14;
            u32 t15 = r.mSeekPt;
            u32 t16 = r.mBufsiz;
            if (t15 >= t16) {
                if (r.refill()) {
                    u32 t18 = r.mSeekPt;
                    u8* t19 = r.mBuffer;
                    u8 t20 = t19[r.mSeekPt];
                    r.mSeekPt = t18 + 1u;
                    mWhiteNoZero = t20 != 0;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t23 = r.readF32();
                    mTargetDistanceY = t23;
                } else {
                    mWhiteNoZero = false;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t23 = r.readF32();
                    mTargetDistanceY = t23;
                }
            } else {
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t15 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t23 = r.readF32();
                mTargetDistanceY = t23;
            }
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        f32 t11 = r.readF32();
        mHpRateMin = t11;
        f32 t12 = r.readF32();
        mHpRateMax = t12;
        f32 t13 = r.readF32();
        mWhiteHpRateMin = t13;
        f32 t14 = r.readF32();
        mWhiteHpRateMax = t14;
        u32 t15 = r.mSeekPt;
        u32 t16 = r.mBufsiz;
        if (t15 >= t16) {
            if (r.refill()) {
                u32 t18 = r.mSeekPt;
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t18 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t23 = r.readF32();
                mTargetDistanceY = t23;
            } else {
                mWhiteNoZero = false;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t23 = r.readF32();
                mTargetDistanceY = t23;
            }
        } else {
            u8* t19 = r.mBuffer;
            u8 t20 = t19[r.mSeekPt];
            r.mSeekPt = t15 + 1u;
            mWhiteNoZero = t20 != 0;
            f32 t21 = r.readF32();
            mTargetDistanceMin = t21;
            f32 t23 = r.readF32();
            mTargetDistanceY = t23;
        }
    }
}

inline cPrioThkCmdAddPartyHp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyHp::MyDTI cPrioThkCmdAddPartyHp::DTI("cPrioThkCmdAddPartyHp", &::cPrioThkCmdAddParty::DTI, 56ul, 0u, 0u);

MtObject* cPrioThkCmdAddPartyHp::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddPartyHp;
}

const MtDTI& cPrioThkCmdAddPartyHpForShift::getDTI() const {
    return cPrioThkCmdAddPartyHpForShift::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddPartyHpForShift::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddPartyHpForShift::checkEx")
    return {};
}

void cPrioThkCmdAddPartyHpForShift::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mHpRateMin = t11;
            f32 t12 = r.readF32();
            mHpRateMax = t12;
            f32 t13 = r.readF32();
            mWhiteHpRateMin = t13;
            f32 t14 = r.readF32();
            mWhiteHpRateMax = t14;
            u32 t15 = r.mSeekPt;
            u32 t16 = r.mBufsiz;
            if (t15 >= t16) {
                if (r.refill()) {
                    u32 t18 = r.mSeekPt;
                    u8* t19 = r.mBuffer;
                    u8 t20 = t19[r.mSeekPt];
                    r.mSeekPt = t18 + 1u;
                    mWhiteNoZero = t20 != 0;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t22 = r.readF32();
                    mTargetDistanceY = t22;
                    f32 t23 = r.readF32();
                    mStaminaRateMin = t23;
                    f32 t25 = r.readF32();
                    mStaminaRateMax = t25;
                } else {
                    mWhiteNoZero = false;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t22 = r.readF32();
                    mTargetDistanceY = t22;
                    f32 t23 = r.readF32();
                    mStaminaRateMin = t23;
                    f32 t25 = r.readF32();
                    mStaminaRateMax = t25;
                }
            } else {
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t15 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t22 = r.readF32();
                mTargetDistanceY = t22;
                f32 t23 = r.readF32();
                mStaminaRateMin = t23;
                f32 t25 = r.readF32();
                mStaminaRateMax = t25;
            }
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mHpRateMin = t11;
            f32 t12 = r.readF32();
            mHpRateMax = t12;
            f32 t13 = r.readF32();
            mWhiteHpRateMin = t13;
            f32 t14 = r.readF32();
            mWhiteHpRateMax = t14;
            u32 t15 = r.mSeekPt;
            u32 t16 = r.mBufsiz;
            if (t15 >= t16) {
                if (r.refill()) {
                    u32 t18 = r.mSeekPt;
                    u8* t19 = r.mBuffer;
                    u8 t20 = t19[r.mSeekPt];
                    r.mSeekPt = t18 + 1u;
                    mWhiteNoZero = t20 != 0;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t22 = r.readF32();
                    mTargetDistanceY = t22;
                    f32 t23 = r.readF32();
                    mStaminaRateMin = t23;
                    f32 t25 = r.readF32();
                    mStaminaRateMax = t25;
                } else {
                    mWhiteNoZero = false;
                    f32 t21 = r.readF32();
                    mTargetDistanceMin = t21;
                    f32 t22 = r.readF32();
                    mTargetDistanceY = t22;
                    f32 t23 = r.readF32();
                    mStaminaRateMin = t23;
                    f32 t25 = r.readF32();
                    mStaminaRateMax = t25;
                }
            } else {
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t15 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t22 = r.readF32();
                mTargetDistanceY = t22;
                f32 t23 = r.readF32();
                mStaminaRateMin = t23;
                f32 t25 = r.readF32();
                mStaminaRateMax = t25;
            }
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        f32 t11 = r.readF32();
        mHpRateMin = t11;
        f32 t12 = r.readF32();
        mHpRateMax = t12;
        f32 t13 = r.readF32();
        mWhiteHpRateMin = t13;
        f32 t14 = r.readF32();
        mWhiteHpRateMax = t14;
        u32 t15 = r.mSeekPt;
        u32 t16 = r.mBufsiz;
        if (t15 >= t16) {
            if (r.refill()) {
                u32 t18 = r.mSeekPt;
                u8* t19 = r.mBuffer;
                u8 t20 = t19[r.mSeekPt];
                r.mSeekPt = t18 + 1u;
                mWhiteNoZero = t20 != 0;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t22 = r.readF32();
                mTargetDistanceY = t22;
                f32 t23 = r.readF32();
                mStaminaRateMin = t23;
                f32 t25 = r.readF32();
                mStaminaRateMax = t25;
            } else {
                mWhiteNoZero = false;
                f32 t21 = r.readF32();
                mTargetDistanceMin = t21;
                f32 t22 = r.readF32();
                mTargetDistanceY = t22;
                f32 t23 = r.readF32();
                mStaminaRateMin = t23;
                f32 t25 = r.readF32();
                mStaminaRateMax = t25;
            }
        } else {
            u8* t19 = r.mBuffer;
            u8 t20 = t19[r.mSeekPt];
            r.mSeekPt = t15 + 1u;
            mWhiteNoZero = t20 != 0;
            f32 t21 = r.readF32();
            mTargetDistanceMin = t21;
            f32 t22 = r.readF32();
            mTargetDistanceY = t22;
            f32 t23 = r.readF32();
            mStaminaRateMin = t23;
            f32 t25 = r.readF32();
            mStaminaRateMax = t25;
        }
    }
}

inline cPrioThkCmdAddPartyHpForShift::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyHpForShift::MyDTI cPrioThkCmdAddPartyHpForShift::DTI("cPrioThkCmdAddPartyHpForShift", &::cPrioThkCmdAddParty::DTI, 64ul, 0u, 0u);

MtObject* cPrioThkCmdAddPartyHpForShift::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddPartyHpForShift;
}

const MtDTI& cPrioThkCmdAddPartyOcd::getDTI() const {
    return cPrioThkCmdAddPartyOcd::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddPartyOcd::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddPartyOcd::checkEx")
    return {};
}

void cPrioThkCmdAddPartyOcd::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            mEnableOcd.elems[0] = t11;
            u32 t13 = r.readU32();
            mEnableOcd.elems[1] = t13;
            u32 t15 = r.readU32();
            mEnableOcd.elems[2] = t15;
            u32 t17 = r.readU32();
            mEnableOcd.elems[3] = t17;
            u32 t19 = r.readU32();
            mEnableOcd.elems[4] = t19;
            u32 t21 = r.readU32();
            mEnableOcd.elems[5] = t21;
            u32 t23 = r.readU32();
            mEnableOcd.elems[6] = t23;
            u32 t25 = r.readU32();
            mEnableOcd.elems[7] = t25;
            u32 t27 = r.readU32();
            mEnableOcd.elems[8] = t27;
            u32 t29 = r.readU32();
            mEnableOcd.elems[9] = t29;
            u32 t31 = r.readU32();
            mEnableOcd.elems[10] = t31;
            u32 t33 = r.readU32();
            mEnableOcd.elems[11] = t33;
            u32 t35 = r.readU32();
            mEnableOcd.elems[12] = t35;
            u32 t37 = r.readU32();
            mEnableOcd.elems[13] = t37;
            u32 t39 = r.readU32();
            mEnableOcd.elems[14] = t39;
            u32 t41 = r.readU32();
            mEnableOcd.elems[15] = t41;
            u32 t43 = r.readU32();
            mDisableOcd.elems[0] = t43;
            u32 t45 = r.readU32();
            mDisableOcd.elems[1] = t45;
            u32 t47 = r.readU32();
            mDisableOcd.elems[2] = t47;
            u32 t49 = r.readU32();
            mDisableOcd.elems[3] = t49;
            u32 t51 = r.readU32();
            mDisableOcd.elems[4] = t51;
            u32 t53 = r.readU32();
            mDisableOcd.elems[5] = t53;
            u32 t55 = r.readU32();
            mDisableOcd.elems[6] = t55;
            u32 t57 = r.readU32();
            mDisableOcd.elems[7] = t57;
            u32 t59 = r.readU32();
            mDisableOcd.elems[8] = t59;
            u32 t61 = r.readU32();
            mDisableOcd.elems[9] = t61;
            u32 t63 = r.readU32();
            mDisableOcd.elems[10] = t63;
            u32 t65 = r.readU32();
            mDisableOcd.elems[11] = t65;
            u32 t67 = r.readU32();
            mDisableOcd.elems[12] = t67;
            u32 t69 = r.readU32();
            mDisableOcd.elems[13] = t69;
            u32 t71 = r.readU32();
            mDisableOcd.elems[14] = t71;
            u32 t73 = r.readU32();
            mDisableOcd.elems[15] = t73;
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            mEnableOcd.elems[0] = t11;
            u32 t13 = r.readU32();
            mEnableOcd.elems[1] = t13;
            u32 t15 = r.readU32();
            mEnableOcd.elems[2] = t15;
            u32 t17 = r.readU32();
            mEnableOcd.elems[3] = t17;
            u32 t19 = r.readU32();
            mEnableOcd.elems[4] = t19;
            u32 t21 = r.readU32();
            mEnableOcd.elems[5] = t21;
            u32 t23 = r.readU32();
            mEnableOcd.elems[6] = t23;
            u32 t25 = r.readU32();
            mEnableOcd.elems[7] = t25;
            u32 t27 = r.readU32();
            mEnableOcd.elems[8] = t27;
            u32 t29 = r.readU32();
            mEnableOcd.elems[9] = t29;
            u32 t31 = r.readU32();
            mEnableOcd.elems[10] = t31;
            u32 t33 = r.readU32();
            mEnableOcd.elems[11] = t33;
            u32 t35 = r.readU32();
            mEnableOcd.elems[12] = t35;
            u32 t37 = r.readU32();
            mEnableOcd.elems[13] = t37;
            u32 t39 = r.readU32();
            mEnableOcd.elems[14] = t39;
            u32 t41 = r.readU32();
            mEnableOcd.elems[15] = t41;
            u32 t43 = r.readU32();
            mDisableOcd.elems[0] = t43;
            u32 t45 = r.readU32();
            mDisableOcd.elems[1] = t45;
            u32 t47 = r.readU32();
            mDisableOcd.elems[2] = t47;
            u32 t49 = r.readU32();
            mDisableOcd.elems[3] = t49;
            u32 t51 = r.readU32();
            mDisableOcd.elems[4] = t51;
            u32 t53 = r.readU32();
            mDisableOcd.elems[5] = t53;
            u32 t55 = r.readU32();
            mDisableOcd.elems[6] = t55;
            u32 t57 = r.readU32();
            mDisableOcd.elems[7] = t57;
            u32 t59 = r.readU32();
            mDisableOcd.elems[8] = t59;
            u32 t61 = r.readU32();
            mDisableOcd.elems[9] = t61;
            u32 t63 = r.readU32();
            mDisableOcd.elems[10] = t63;
            u32 t65 = r.readU32();
            mDisableOcd.elems[11] = t65;
            u32 t67 = r.readU32();
            mDisableOcd.elems[12] = t67;
            u32 t69 = r.readU32();
            mDisableOcd.elems[13] = t69;
            u32 t71 = r.readU32();
            mDisableOcd.elems[14] = t71;
            u32 t73 = r.readU32();
            mDisableOcd.elems[15] = t73;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        u32 t11 = r.readU32();
        mEnableOcd.elems[0] = t11;
        u32 t13 = r.readU32();
        mEnableOcd.elems[1] = t13;
        u32 t15 = r.readU32();
        mEnableOcd.elems[2] = t15;
        u32 t17 = r.readU32();
        mEnableOcd.elems[3] = t17;
        u32 t19 = r.readU32();
        mEnableOcd.elems[4] = t19;
        u32 t21 = r.readU32();
        mEnableOcd.elems[5] = t21;
        u32 t23 = r.readU32();
        mEnableOcd.elems[6] = t23;
        u32 t25 = r.readU32();
        mEnableOcd.elems[7] = t25;
        u32 t27 = r.readU32();
        mEnableOcd.elems[8] = t27;
        u32 t29 = r.readU32();
        mEnableOcd.elems[9] = t29;
        u32 t31 = r.readU32();
        mEnableOcd.elems[10] = t31;
        u32 t33 = r.readU32();
        mEnableOcd.elems[11] = t33;
        u32 t35 = r.readU32();
        mEnableOcd.elems[12] = t35;
        u32 t37 = r.readU32();
        mEnableOcd.elems[13] = t37;
        u32 t39 = r.readU32();
        mEnableOcd.elems[14] = t39;
        u32 t41 = r.readU32();
        mEnableOcd.elems[15] = t41;
        u32 t43 = r.readU32();
        mDisableOcd.elems[0] = t43;
        u32 t45 = r.readU32();
        mDisableOcd.elems[1] = t45;
        u32 t47 = r.readU32();
        mDisableOcd.elems[2] = t47;
        u32 t49 = r.readU32();
        mDisableOcd.elems[3] = t49;
        u32 t51 = r.readU32();
        mDisableOcd.elems[4] = t51;
        u32 t53 = r.readU32();
        mDisableOcd.elems[5] = t53;
        u32 t55 = r.readU32();
        mDisableOcd.elems[6] = t55;
        u32 t57 = r.readU32();
        mDisableOcd.elems[7] = t57;
        u32 t59 = r.readU32();
        mDisableOcd.elems[8] = t59;
        u32 t61 = r.readU32();
        mDisableOcd.elems[9] = t61;
        u32 t63 = r.readU32();
        mDisableOcd.elems[10] = t63;
        u32 t65 = r.readU32();
        mDisableOcd.elems[11] = t65;
        u32 t67 = r.readU32();
        mDisableOcd.elems[12] = t67;
        u32 t69 = r.readU32();
        mDisableOcd.elems[13] = t69;
        u32 t71 = r.readU32();
        mDisableOcd.elems[14] = t71;
        u32 t73 = r.readU32();
        mDisableOcd.elems[15] = t73;
    }
}

inline cPrioThkCmdAddPartyOcd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyOcd::MyDTI cPrioThkCmdAddPartyOcd::DTI("cPrioThkCmdAddPartyOcd", &::cPrioThkCmdAddParty::DTI, 152ul, 0u, 0u);

MtObject* cPrioThkCmdAddPartyOcd::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddPartyOcd;
}

const MtDTI& cPrioThkCmdAddPartyStamina::getDTI() const {
    return cPrioThkCmdAddPartyStamina::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdAddPartyStamina::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdAddPartyStamina::checkEx")
    return {};
}

void cPrioThkCmdAddPartyStamina::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mStaminaRateMin = t11;
            f32 t12 = r.readF32();
            mStaminaRateMax = t12;
            u32 t13 = r.mSeekPt;
            u32 t14 = r.mBufsiz;
            if (t13 >= t14) {
                if (r.refill()) {
                    u32 t16 = r.mSeekPt;
                    u8* t17 = r.mBuffer;
                    u8 t18 = t17[r.mSeekPt];
                    r.mSeekPt = t16 + 1u;
                    mIgnoreTired = t18 != 0;
                } else {
                    mIgnoreTired = false;
                }
            } else {
                u8* t17 = r.mBuffer;
                u8 t18 = t17[r.mSeekPt];
                r.mSeekPt = t13 + 1u;
                mIgnoreTired = t18 != 0;
            }
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            f32 t11 = r.readF32();
            mStaminaRateMin = t11;
            f32 t12 = r.readF32();
            mStaminaRateMax = t12;
            u32 t13 = r.mSeekPt;
            u32 t14 = r.mBufsiz;
            if (t13 >= t14) {
                if (r.refill()) {
                    u32 t16 = r.mSeekPt;
                    u8* t17 = r.mBuffer;
                    u8 t18 = t17[r.mSeekPt];
                    r.mSeekPt = t16 + 1u;
                    mIgnoreTired = t18 != 0;
                } else {
                    mIgnoreTired = false;
                }
            } else {
                u8* t17 = r.mBuffer;
                u8 t18 = t17[r.mSeekPt];
                r.mSeekPt = t13 + 1u;
                mIgnoreTired = t18 != 0;
            }
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        f32 t11 = r.readF32();
        mStaminaRateMin = t11;
        f32 t12 = r.readF32();
        mStaminaRateMax = t12;
        u32 t13 = r.mSeekPt;
        u32 t14 = r.mBufsiz;
        if (t13 >= t14) {
            if (r.refill()) {
                u32 t16 = r.mSeekPt;
                u8* t17 = r.mBuffer;
                u8 t18 = t17[r.mSeekPt];
                r.mSeekPt = t16 + 1u;
                mIgnoreTired = t18 != 0;
            } else {
                mIgnoreTired = false;
            }
        } else {
            u8* t17 = r.mBuffer;
            u8 t18 = t17[r.mSeekPt];
            r.mSeekPt = t13 + 1u;
            mIgnoreTired = t18 != 0;
        }
    }
}

inline cPrioThkCmdAddPartyStamina::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyStamina::MyDTI cPrioThkCmdAddPartyStamina::DTI("cPrioThkCmdAddPartyStamina", &::cPrioThkCmdAddParty::DTI, 40ul, 0u, 0u);

MtObject* cPrioThkCmdAddPartyStamina::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdAddPartyStamina;
}

const MtDTI& cPrioThkCmdAddPartyStatus::getDTI() const {
    return cPrioThkCmdAddPartyStatus::DTI;
}

u32 cPrioThkCmdAddPartyStatus::checkEx(uCharacter* pChar, cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return isEnablePrioThkStatusFlag(mPrioThkStatusFlag, *pChar);
}

void cPrioThkCmdAddPartyStatus::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mFilter = t5 != 0;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            unsigned long t13 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t14 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t13) + 120);
            r.read(static_cast<void*>(&mPrioThkStatusFlag), t11 * 4u);
        } else {
            mFilter = false;
            u32 t6 = r.readU32();
            mTargetPartyFlag = t6;
            f32 t8 = r.readF32();
            mTargetRange = t8;
            u32 t9 = r.readU32();
            mAddSortType = t9;
            u32 t11 = r.readU32();
            unsigned long t13 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t14 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t13) + 120);
            r.read(static_cast<void*>(&mPrioThkStatusFlag), t11 * 4u);
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mFilter = t5 != 0;
        u32 t6 = r.readU32();
        mTargetPartyFlag = t6;
        f32 t8 = r.readF32();
        mTargetRange = t8;
        u32 t9 = r.readU32();
        mAddSortType = t9;
        u32 t11 = r.readU32();
        unsigned long t13 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
        unsigned long t14 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t13) + 120);
        r.read(static_cast<void*>(&mPrioThkStatusFlag), t11 * 4u);
    }
}

inline cPrioThkCmdAddPartyStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdAddPartyStatus::MyDTI cPrioThkCmdAddPartyStatus::DTI("cPrioThkCmdAddPartyStatus", &::cPrioThkCmdAddParty::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdAddPartyStatus::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdAddPartyStatus;
}

const MtDTI& cPrioThkCmdConCureSpot::getDTI() const {
    return cPrioThkCmdConCureSpot::DTI;
}

u32 cPrioThkCmdConCureSpot::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return 0;
}

inline cPrioThkCmdConCureSpot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConCureSpot::MyDTI cPrioThkCmdConCureSpot::DTI("cPrioThkCmdConCureSpot", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdConCureSpot::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConCureSpot;
}

const MtDTI& cPrioThkCmdConEventOmElf::getDTI() const {
    return cPrioThkCmdConEventOmElf::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdConEventOmElf::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdConEventOmElf::check")
    return {};
}

inline cPrioThkCmdConEventOmElf::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConEventOmElf::MyDTI cPrioThkCmdConEventOmElf::DTI("cPrioThkCmdConEventOmElf", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdConEventOmElf::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConEventOmElf;
}

const MtDTI& cPrioThkCmdConFollowArea::getDTI() const {
    return cPrioThkCmdConFollowArea::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdConFollowArea::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdConFollowArea::check")
    return {};
}

void cPrioThkCmdConFollowArea::load(MtDataReader& r) {
    nDDOIO::readData(r, mAreaType);
    nDDOIO::readData(r, mAreaPosType);
    nDDOIO::readData(r, mAreaPosOfsZ);
    nDDOIO::readData(r, mAreaEnable.mMinXZ);
    nDDOIO::readData(r, mAreaEnable.mMaxXZ);
    nDDOIO::readData(r, mAreaEnable.mMinY);
    nDDOIO::readData(r, mAreaEnable.mMaxY);
    nDDOIO::readData(r, mAreaEnable.mRadius);
    nDDOIO::readData(r, mNoContinue);
}

inline cPrioThkCmdConFollowArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConFollowArea::MyDTI cPrioThkCmdConFollowArea::DTI("cPrioThkCmdConFollowArea", &::cPrioThkCmd::DTI, 64ul, 0u, 0u);

MtObject* cPrioThkCmdConFollowArea::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConFollowArea;
}

const MtDTI& cPrioThkCmdConHealFountain::getDTI() const {
    return cPrioThkCmdConHealFountain::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdConHealFountain::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdConHealFountain::check")
    return {};
}

inline cPrioThkCmdConHealFountain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConHealFountain::MyDTI cPrioThkCmdConHealFountain::DTI("cPrioThkCmdConHealFountain", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdConHealFountain::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConHealFountain;
}

const MtDTI& cPrioThkCmdConHealSpot::getDTI() const {
    return cPrioThkCmdConHealSpot::DTI;
}

u32 cPrioThkCmdConHealSpot::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return 0;
}

inline cPrioThkCmdConHealSpot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConHealSpot::MyDTI cPrioThkCmdConHealSpot::DTI("cPrioThkCmdConHealSpot", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdConHealSpot::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConHealSpot;
}

const MtDTI& cPrioThkCmdConSpot::getDTI() const {
    return cPrioThkCmdConSpot::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdConSpot::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdConSpot::check")
    return {};
}

void cPrioThkCmdConSpot::load(MtDataReader& r) {
    nDDOIO::readData(r, mShlId);
    nDDOIO::readData(r, mLength);
    nDDOIO::readData(r, mFollowRange);
}

inline cPrioThkCmdConSpot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConSpot::MyDTI cPrioThkCmdConSpot::DTI("cPrioThkCmdConSpot", &::cPrioThkCmd::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdConSpot::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConSpot;
}

const MtDTI& cPrioThkCmdConSpotExt::getDTI() const {
    return cPrioThkCmdConSpotExt::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdConSpotExt::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdConSpotExt::check")
    return {};
}

void cPrioThkCmdConSpotExt::load(MtDataReader& r) {
    nDDOIO::readData(r, mShlId);
    nDDOIO::readData(r, mLength);
    nDDOIO::readData(r, mThroughLength);
    nDDOIO::readData(r, mFollowRange);
}

inline cPrioThkCmdConSpotExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdConSpotExt::MyDTI cPrioThkCmdConSpotExt::DTI("cPrioThkCmdConSpotExt", &::cPrioThkCmd::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdConSpotExt::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdConSpotExt;
}

const MtDTI& cPrioThkCmdFilTargetStatus::getDTI() const {
    return cPrioThkCmdFilTargetStatus::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdFilTargetStatus::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdFilTargetStatus::check")
    return {};
}

void cPrioThkCmdFilTargetStatus::load(MtDataReader& r) {
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mPrioThkStatusFlag), t0 * 4u);
}

inline cPrioThkCmdFilTargetStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdFilTargetStatus::MyDTI cPrioThkCmdFilTargetStatus::DTI("cPrioThkCmdFilTargetStatus", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdFilTargetStatus::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdFilTargetStatus;
}

const MtDTI& cPrioThkCmdIsAction::getDTI() const {
    return cPrioThkCmdIsAction::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsAction::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsAction::check")
    return {};
}

void cPrioThkCmdIsAction::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mActNo = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mActNo = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mActNo = t6;
    }
}

inline cPrioThkCmdIsAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsAction::MyDTI cPrioThkCmdIsAction::DTI("cPrioThkCmdIsAction", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsAction::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsAction;
}

const MtDTI& cPrioThkCmdIsAutoSituation::getDTI() const {
    return cPrioThkCmdIsAutoSituation::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsAutoSituation::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsAutoSituation::check")
    return {};
}

void cPrioThkCmdIsAutoSituation::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mAutoSituation = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mAutoSituation = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mAutoSituation = t6;
    }
}

inline cPrioThkCmdIsAutoSituation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsAutoSituation::MyDTI cPrioThkCmdIsAutoSituation::DTI("cPrioThkCmdIsAutoSituation", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsAutoSituation::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsAutoSituation;
}

const MtDTI& cPrioThkCmdIsBakuensen::getDTI() const {
    return cPrioThkCmdIsBakuensen::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsBakuensen::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsBakuensen::check")
    return {};
}

inline cPrioThkCmdIsBakuensen::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsBakuensen::MyDTI cPrioThkCmdIsBakuensen::DTI("cPrioThkCmdIsBakuensen", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsBakuensen::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsBakuensen;
}

const MtDTI& cPrioThkCmdIsBase::getDTI() const {
    return cPrioThkCmdIsBase::DTI;
}

u32 cPrioThkCmdIsBase::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return mIs;
}

void cPrioThkCmdIsBase::load(MtDataReader& r) {
    nDDOIO::readData(r, mIs);
}

inline cPrioThkCmdIsBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsBase::MyDTI cPrioThkCmdIsBase::DTI("cPrioThkCmdIsBase", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsBase::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsBase;
}

const MtDTI& cPrioThkCmdIsBattle::getDTI() const {
    return cPrioThkCmdIsBattle::DTI;
}

u32 cPrioThkCmdIsBattle::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return static_cast<u32>((static_cast<unsigned long>(io.mThinkBattleStatus == 1) ^ static_cast<unsigned long>(isRet())) ^ 1ul);
}

inline cPrioThkCmdIsBattle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsBattle::MyDTI cPrioThkCmdIsBattle::DTI("cPrioThkCmdIsBattle", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsBattle::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsBattle;
}

const MtDTI& cPrioThkCmdIsBattleAct::getDTI() const {
    return cPrioThkCmdIsBattleAct::DTI;
}

u32 cPrioThkCmdIsBattleAct::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    u32 t0 = io.mResultNowThinkID;
    if (t0 != MtCRC::getCRC("BTL_COM", 0xFFFFFFFFu)) {
        u32 t1 = io.mResultNowThinkID;
        if (t1 == MtCRC::getCRC("BTL_SUPPORT", 0xFFFFFFFFu)) {
            return !mIs;
        } else {
            return mIs;
        }
    } else {
        return !mIs;
    }
}

inline cPrioThkCmdIsBattleAct::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsBattleAct::MyDTI cPrioThkCmdIsBattleAct::DTI("cPrioThkCmdIsBattleAct", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsBattleAct::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsBattleAct;
}

const MtDTI& cPrioThkCmdIsCanErosionRescue::getDTI() const {
    return cPrioThkCmdIsCanErosionRescue::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsCanErosionRescue::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsCanErosionRescue::check")
    return {};
}

inline cPrioThkCmdIsCanErosionRescue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsCanErosionRescue::MyDTI cPrioThkCmdIsCanErosionRescue::DTI("cPrioThkCmdIsCanErosionRescue", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsCanErosionRescue::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsCanErosionRescue;
}

const MtDTI& cPrioThkCmdIsCanSetEmotion::getDTI() const {
    return cPrioThkCmdIsCanSetEmotion::DTI;
}

u32 cPrioThkCmdIsCanSetEmotion::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    if ((owner.mUnitId & 16u) != 0) {
        return static_cast<u32>((static_cast<unsigned long>(static_cast<uHuman*>(&owner)->isCanSetEmotion()) ^ static_cast<unsigned long>(isRet())) ^ 1ul);
    } else {
        return !isRet();
    }
}

inline cPrioThkCmdIsCanSetEmotion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsCanSetEmotion::MyDTI cPrioThkCmdIsCanSetEmotion::DTI("cPrioThkCmdIsCanSetEmotion", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsCanSetEmotion::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsCanSetEmotion;
}

const MtDTI& cPrioThkCmdIsDamage::getDTI() const {
    return cPrioThkCmdIsDamage::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsDamage::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsDamage::check")
    return {};
}

inline cPrioThkCmdIsDamage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsDamage::MyDTI cPrioThkCmdIsDamage::DTI("cPrioThkCmdIsDamage", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsDamage::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsDamage;
}

const MtDTI& cPrioThkCmdIsDanger::getDTI() const {
    return cPrioThkCmdIsDanger::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsDanger::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsDanger::check")
    return {};
}

__attribute__((weak)) bool cPrioThkCmdIsDanger::isDangerGridCheck(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cAIGrid* pGrid) {
    DDON_STUB("cPrioThkCmdIsDanger::isDangerGridCheck")
    return {};
}

void cPrioThkCmdIsDanger::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            f32 t7 = r.readF32();
            mRange = t7;
        } else {
            mIs = false;
            f32 t7 = r.readF32();
            mRange = t7;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        f32 t7 = r.readF32();
        mRange = t7;
    }
}

inline cPrioThkCmdIsDanger::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsDanger::MyDTI cPrioThkCmdIsDanger::DTI("cPrioThkCmdIsDanger", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsDanger::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsDanger;
}

const MtDTI& cPrioThkCmdIsEnableArea::getDTI() const {
    return cPrioThkCmdIsEnableArea::DTI;
}

u32 cPrioThkCmdIsEnableArea::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    bool t0 = io.mResultFollowAreaEnable.isEnableArea(owner, io.mResultFollowOfsPos, io.mResultFollowAngle);
    if (io.mThinkBattleStatus != 1) {
        if ((owner.mObjStatus & 32ul) != 0) {
            return !mIs;
        }
    }
    return mIs == t0;
}

inline cPrioThkCmdIsEnableArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsEnableArea::MyDTI cPrioThkCmdIsEnableArea::DTI("cPrioThkCmdIsEnableArea", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsEnableArea::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsEnableArea;
}

const MtDTI& cPrioThkCmdIsEvaluation::getDTI() const {
    return cPrioThkCmdIsEvaluation::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsEvaluation::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsEvaluation::check")
    return {};
}

void cPrioThkCmdIsEvaluation::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mTargetType = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mTargetType = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mTargetType = t6;
    }
}

inline cPrioThkCmdIsEvaluation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsEvaluation::MyDTI cPrioThkCmdIsEvaluation::DTI("cPrioThkCmdIsEvaluation", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsEvaluation::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsEvaluation;
}

const MtDTI& cPrioThkCmdIsFollowEnable::getDTI() const {
    return cPrioThkCmdIsFollowEnable::DTI;
}

u32 cPrioThkCmdIsFollowEnable::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return mIs;
}

inline cPrioThkCmdIsFollowEnable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsFollowEnable::MyDTI cPrioThkCmdIsFollowEnable::DTI("cPrioThkCmdIsFollowEnable", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsFollowEnable::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsFollowEnable;
}

const MtDTI& cPrioThkCmdIsGuardBit::getDTI() const {
    return cPrioThkCmdIsGuardBit::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsGuardBit::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsGuardBit::check")
    return {};
}

void cPrioThkCmdIsGuardBit::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mCheckGuardBitNum = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mCheckGuardBitNum = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mCheckGuardBitNum = t6;
    }
}

inline cPrioThkCmdIsGuardBit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsGuardBit::MyDTI cPrioThkCmdIsGuardBit::DTI("cPrioThkCmdIsGuardBit", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsGuardBit::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsGuardBit;
}

const MtDTI& cPrioThkCmdIsHp::getDTI() const {
    return cPrioThkCmdIsHp::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsHp::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsHp::check")
    return {};
}

void cPrioThkCmdIsHp::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            f32 t6 = r.readF32();
            mHpMin = t6;
            f32 t8 = r.readF32();
            mHpMax = t8;
        } else {
            mIs = false;
            f32 t6 = r.readF32();
            mHpMin = t6;
            f32 t8 = r.readF32();
            mHpMax = t8;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        f32 t6 = r.readF32();
        mHpMin = t6;
        f32 t8 = r.readF32();
        mHpMax = t8;
    }
}

inline cPrioThkCmdIsHp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsHp::MyDTI cPrioThkCmdIsHp::DTI("cPrioThkCmdIsHp", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdIsHp::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsHp;
}

const MtDTI& cPrioThkCmdIsImpactForce::getDTI() const {
    return cPrioThkCmdIsImpactForce::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsImpactForce::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsImpactForce::check")
    return {};
}

inline cPrioThkCmdIsImpactForce::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsImpactForce::MyDTI cPrioThkCmdIsImpactForce::DTI("cPrioThkCmdIsImpactForce", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsImpactForce::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsImpactForce;
}

const MtDTI& cPrioThkCmdIsLanternOff::getDTI() const {
    return cPrioThkCmdIsLanternOff::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsLanternOff::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsLanternOff::check")
    return {};
}

inline cPrioThkCmdIsLanternOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsLanternOff::MyDTI cPrioThkCmdIsLanternOff::DTI("cPrioThkCmdIsLanternOff", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsLanternOff::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsLanternOff;
}

const MtDTI& cPrioThkCmdIsLanternOn::getDTI() const {
    return cPrioThkCmdIsLanternOn::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsLanternOn::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsLanternOn::check")
    return {};
}

inline cPrioThkCmdIsLanternOn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsLanternOn::MyDTI cPrioThkCmdIsLanternOn::DTI("cPrioThkCmdIsLanternOn", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsLanternOn::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsLanternOn;
}

const MtDTI& cPrioThkCmdIsMasterDead::getDTI() const {
    return cPrioThkCmdIsMasterDead::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsMasterDead::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsMasterDead::check")
    return {};
}

inline cPrioThkCmdIsMasterDead::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsMasterDead::MyDTI cPrioThkCmdIsMasterDead::DTI("cPrioThkCmdIsMasterDead", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsMasterDead::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsMasterDead;
}

const MtDTI& cPrioThkCmdIsNotice::getDTI() const {
    return cPrioThkCmdIsNotice::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsNotice::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsNotice::check")
    return {};
}

void cPrioThkCmdIsNotice::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mNoticeFlag = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mNoticeFlag = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mNoticeFlag = t6;
    }
}

inline cPrioThkCmdIsNotice::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsNotice::MyDTI cPrioThkCmdIsNotice::DTI("cPrioThkCmdIsNotice", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsNotice::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsNotice;
}

const MtDTI& cPrioThkCmdIsOrder::getDTI() const {
    return cPrioThkCmdIsOrder::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsOrder::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsOrder::check")
    return {};
}

void cPrioThkCmdIsOrder::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
            r.read(static_cast<void*>(&mOrderFlag), t6 * 4u);
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
            r.read(static_cast<void*>(&mOrderFlag), t6 * 4u);
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
        unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
        r.read(static_cast<void*>(&mOrderFlag), t6 * 4u);
    }
}

inline cPrioThkCmdIsOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsOrder::MyDTI cPrioThkCmdIsOrder::DTI("cPrioThkCmdIsOrder", &::cPrioThkCmdIsBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdIsOrder::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsOrder;
}

const MtDTI& cPrioThkCmdIsOtherFlag::getDTI() const {
    return cPrioThkCmdIsOtherFlag::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsOtherFlag::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return (static_cast<u32>(*reinterpret_cast<const unsigned char*>(&mIs) != 0) ^
            static_cast<u32>((reinterpret_cast<const u32*>(&io)[0x144 / sizeof(u32)] &
                              reinterpret_cast<const u32&>(mCheckPrioThkOtherFlag)) != 0)) ^ 1U;
}

void cPrioThkCmdIsOtherFlag::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
            r.read(static_cast<void*>(&mCheckPrioThkOtherFlag), t6 * 4u);
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
            r.read(static_cast<void*>(&mCheckPrioThkOtherFlag), t6 * 4u);
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        unsigned long t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&r) + 0);
        unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 120);
        r.read(static_cast<void*>(&mCheckPrioThkOtherFlag), t6 * 4u);
    }
}

inline cPrioThkCmdIsOtherFlag::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsOtherFlag::MyDTI cPrioThkCmdIsOtherFlag::DTI("cPrioThkCmdIsOtherFlag", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdIsOtherFlag::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdIsOtherFlag;
}

const MtDTI& cPrioThkCmdIsPartyJob::getDTI() const {
    return cPrioThkCmdIsPartyJob::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsPartyJob::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsPartyJob::check")
    return {};
}

void cPrioThkCmdIsPartyJob::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
        } else {
            mIs = false;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
    }
}

inline cPrioThkCmdIsPartyJob::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsPartyJob::MyDTI cPrioThkCmdIsPartyJob::DTI("cPrioThkCmdIsPartyJob", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsPartyJob::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsPartyJob;
}

const MtDTI& cPrioThkCmdIsReleaseAlchemy::getDTI() const {
    return cPrioThkCmdIsReleaseAlchemy::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsReleaseAlchemy::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsReleaseAlchemy::check")
    return {};
}

inline cPrioThkCmdIsReleaseAlchemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsReleaseAlchemy::MyDTI cPrioThkCmdIsReleaseAlchemy::DTI("cPrioThkCmdIsReleaseAlchemy", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsReleaseAlchemy::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsReleaseAlchemy;
}

const MtDTI& cPrioThkCmdIsReload::getDTI() const {
    return cPrioThkCmdIsReload::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsReload::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsReload::check")
    return {};
}

void cPrioThkCmdIsReload::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            s32 t6 = r.readS32();
            mUnderNum = t6;
            f32 t9 = r.readF32();
            mUnderRate = t9;
        } else {
            mIs = false;
            s32 t6 = r.readS32();
            mUnderNum = t6;
            f32 t9 = r.readF32();
            mUnderRate = t9;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        s32 t6 = r.readS32();
        mUnderNum = t6;
        f32 t9 = r.readF32();
        mUnderRate = t9;
    }
}

inline cPrioThkCmdIsReload::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsReload::MyDTI cPrioThkCmdIsReload::DTI("cPrioThkCmdIsReload", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdIsReload::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsReload;
}

const MtDTI& cPrioThkCmdIsShl::getDTI() const {
    return cPrioThkCmdIsShl::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsShl::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsShl::check")
    return {};
}

void cPrioThkCmdIsShl::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mShlId = t6;
            f32 t8 = r.readF32();
            mLength = t8;
            u32 t9 = r.readU32();
            mChkType = t9;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mShlId = t6;
            f32 t8 = r.readF32();
            mLength = t8;
            u32 t9 = r.readU32();
            mChkType = t9;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mShlId = t6;
        f32 t8 = r.readF32();
        mLength = t8;
        u32 t9 = r.readU32();
        mChkType = t9;
    }
}

inline cPrioThkCmdIsShl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsShl::MyDTI cPrioThkCmdIsShl::DTI("cPrioThkCmdIsShl", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdIsShl::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsShl;
}

const MtDTI& cPrioThkCmdIsStageNo::getDTI() const {
    return cPrioThkCmdIsStageNo::DTI;
}

u32 cPrioThkCmdIsStageNo::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    aStage* p_stage = static_cast<sAreaExt*>(sArea::getInstance())->getCurrentStage();
    if (p_stage != nullptr) {
        return static_cast<u32>((static_cast<unsigned long>(mStageNo == p_stage->mTrueStageNo) ^ static_cast<unsigned long>(isRet())) ^ 1ul);
    } else {
        return !isRet();
    }
}

void cPrioThkCmdIsStageNo::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            s32 t6 = r.readS32();
            mStageNo = t6;
        } else {
            mIs = false;
            s32 t6 = r.readS32();
            mStageNo = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        s32 t6 = r.readS32();
        mStageNo = t6;
    }
}

inline cPrioThkCmdIsStageNo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStageNo::MyDTI cPrioThkCmdIsStageNo::DTI("cPrioThkCmdIsStageNo", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsStageNo::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStageNo;
}

const MtDTI& cPrioThkCmdIsStageType::getDTI() const {
    return cPrioThkCmdIsStageType::DTI;
}

u32 cPrioThkCmdIsStageType::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    aStage* p_stage = static_cast<sAreaExt*>(sArea::getInstance())->getCurrentStage();
    if (p_stage != nullptr) {
        switch (p_stage->mStageType - 1u) {
            case 0:
            {
                return static_cast<u32>((static_cast<unsigned long>(mIs) ^ static_cast<unsigned long>((mStageTypeFlag >> 1) & 1u)) ^ 1ul);
            }
            case 1:
            {
                return static_cast<u32>((static_cast<unsigned long>(mIs) ^ static_cast<unsigned long>((mStageTypeFlag >> 2) & 1u)) ^ 1ul);
            }
            case 2:
            {
                return static_cast<u32>((static_cast<unsigned long>(mIs) ^ static_cast<unsigned long>((mStageTypeFlag >> 3) & 1u)) ^ 1ul);
            }
            case 3:
            {
                return static_cast<u32>((static_cast<unsigned long>(mIs) ^ static_cast<unsigned long>((mStageTypeFlag >> 4) & 1u)) ^ 1ul);
            }
            default:
            {
                return !mIs;
            }
        }
    } else {
        return !mIs;
    }
}

void cPrioThkCmdIsStageType::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            u32 t6 = r.readU32();
            mStageTypeFlag = t6;
        } else {
            mIs = false;
            u32 t6 = r.readU32();
            mStageTypeFlag = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        u32 t6 = r.readU32();
        mStageTypeFlag = t6;
    }
}

inline cPrioThkCmdIsStageType::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStageType::MyDTI cPrioThkCmdIsStageType::DTI("cPrioThkCmdIsStageType", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsStageType::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStageType;
}

const MtDTI& cPrioThkCmdIsStamina::getDTI() const {
    return cPrioThkCmdIsStamina::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsStamina::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsStamina::check")
    return {};
}

void cPrioThkCmdIsStamina::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            f32 t6 = r.readF32();
            mStaminaMin = t6;
            f32 t8 = r.readF32();
            mStaminaMax = t8;
        } else {
            mIs = false;
            f32 t6 = r.readF32();
            mStaminaMin = t6;
            f32 t8 = r.readF32();
            mStaminaMax = t8;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        f32 t6 = r.readF32();
        mStaminaMin = t6;
        f32 t8 = r.readF32();
        mStaminaMax = t8;
    }
}

inline cPrioThkCmdIsStamina::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStamina::MyDTI cPrioThkCmdIsStamina::DTI("cPrioThkCmdIsStamina", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdIsStamina::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStamina;
}

const MtDTI& cPrioThkCmdIsStandOffTime::getDTI() const {
    return cPrioThkCmdIsStandOffTime::DTI;
}

u32 cPrioThkCmdIsStandOffTime::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return static_cast<u32>(static_cast<unsigned long>(mIs) ^ static_cast<unsigned long>(0.0f >= io.mStandOffTime));
}

inline cPrioThkCmdIsStandOffTime::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStandOffTime::MyDTI cPrioThkCmdIsStandOffTime::DTI("cPrioThkCmdIsStandOffTime", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsStandOffTime::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStandOffTime;
}

const MtDTI& cPrioThkCmdIsStatus::getDTI() const {
    return cPrioThkCmdIsStatus::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsStatus::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsStatus::check")
    return {};
}

__attribute__((weak)) void cPrioThkCmdIsStatus::load(MtDataReader& r) {
    nDDOIO::readData(r, mIs);
    nDDOIO::readData(r, mPrioThkStatusFlag);
    nDDOIO::readData(r, mCheckTargetMaster);
}

inline cPrioThkCmdIsStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStatus::MyDTI cPrioThkCmdIsStatus::DTI("cPrioThkCmdIsStatus", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdIsStatus::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdIsStatus;
}

const MtDTI& cPrioThkCmdIsStatusCounter::getDTI() const {
    return cPrioThkCmdIsStatusCounter::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsStatusCounter::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsStatusCounter::check")
    return {};
}

void cPrioThkCmdIsStatusCounter::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            s32 t6 = r.readS32();
            mStateID = t6;
            f32 t9 = r.readF32();
            mStateTime = t9;
        } else {
            mIs = false;
            s32 t6 = r.readS32();
            mStateID = t6;
            f32 t9 = r.readF32();
            mStateTime = t9;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        s32 t6 = r.readS32();
        mStateID = t6;
        f32 t9 = r.readF32();
        mStateTime = t9;
    }
}

inline cPrioThkCmdIsStatusCounter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStatusCounter::MyDTI cPrioThkCmdIsStatusCounter::DTI("cPrioThkCmdIsStatusCounter", &::cPrioThkCmdIsBase::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdIsStatusCounter::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStatusCounter;
}

const MtDTI& cPrioThkCmdIsStatusEx::getDTI() const {
    return cPrioThkCmdIsStatusEx::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsStatusEx::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsStatusEx::check")
    return {};
}

void cPrioThkCmdIsStatusEx::load(MtDataReader& r) {
    u32 t0 = r.mSeekPt;
    u32 t1 = r.mBufsiz;
    if (t0 >= t1) {
        if (r.refill()) {
            u32 t3 = r.mSeekPt;
            u8* t4 = r.mBuffer;
            u8 t5 = t4[r.mSeekPt];
            r.mSeekPt = t3 + 1u;
            mIs = t5 != 0;
            s32 t6 = r.readS32();
            mCheckID = t6;
        } else {
            mIs = false;
            s32 t6 = r.readS32();
            mCheckID = t6;
        }
    } else {
        u8* t4 = r.mBuffer;
        u8 t5 = t4[r.mSeekPt];
        r.mSeekPt = t0 + 1u;
        mIs = t5 != 0;
        s32 t6 = r.readS32();
        mCheckID = t6;
    }
}

inline cPrioThkCmdIsStatusEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsStatusEx::MyDTI cPrioThkCmdIsStatusEx::DTI("cPrioThkCmdIsStatusEx", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsStatusEx::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsStatusEx;
}

const MtDTI& cPrioThkCmdIsTalkWithPl::getDTI() const {
    return cPrioThkCmdIsTalkWithPl::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdIsTalkWithPl::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdIsTalkWithPl::check")
    return {};
}

inline cPrioThkCmdIsTalkWithPl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsTalkWithPl::MyDTI cPrioThkCmdIsTalkWithPl::DTI("cPrioThkCmdIsTalkWithPl", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsTalkWithPl::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsTalkWithPl;
}

const MtDTI& cPrioThkCmdIsTarget::getDTI() const {
    return cPrioThkCmdIsTarget::DTI;
}

u32 cPrioThkCmdIsTarget::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    return static_cast<u32>((static_cast<unsigned long>(io.mResultTarget.mLength != 0) ^ static_cast<unsigned long>(isRet())) ^ 1ul);
}

inline cPrioThkCmdIsTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdIsTarget::MyDTI cPrioThkCmdIsTarget::DTI("cPrioThkCmdIsTarget", &::cPrioThkCmdIsBase::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdIsTarget::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdIsTarget;
}

const MtDTI& cPrioThkCmdRetActGoldBurst::getDTI() const {
    return cPrioThkCmdRetActGoldBurst::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetActGoldBurst::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetActGoldBurst::check")
    return {};
}

void cPrioThkCmdRetActGoldBurst::load(MtDataReader& r) {
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mRetActFlag), t0 * 4u);
}

inline cPrioThkCmdRetActGoldBurst::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetActGoldBurst::MyDTI cPrioThkCmdRetActGoldBurst::DTI("cPrioThkCmdRetActGoldBurst", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdRetActGoldBurst::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdRetActGoldBurst;
}

const MtDTI& cPrioThkCmdRetActGroup::getDTI() const {
    return cPrioThkCmdRetActGroup::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetActGroup::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetActGroup::check")
    return {};
}

void cPrioThkCmdRetActGroup::load(MtDataReader& r) {
    mActionInterfaceGroup = r.readU32();
    mReqTargetType = r.readU32();
    mReqTargetRealPos = r.readV3();
    nDDOIO::readData(r, mReqTargetFrameType);
    nDDOIO::readData(r, mReqTargetFrame);
    nDDOIO::readData(r, mReqUseEmChecker);
    u32 t2 = r.readU32();
    r.read(static_cast<void*>(&mRetActFlag), t2 * 4u);
}

inline cPrioThkCmdRetActGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetActGroup::MyDTI cPrioThkCmdRetActGroup::DTI("cPrioThkCmdRetActGroup", &::cPrioThkCmd::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdRetActGroup::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdRetActGroup;
}

const MtDTI& cPrioThkCmdRetActInter::getDTI() const {
    return cPrioThkCmdRetActInter::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetActInter::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetActInter::check")
    return {};
}

void cPrioThkCmdRetActInter::load(MtDataReader& r) {
    mActionInterfaceID = r.readU32();
    mReqTargetType = r.readU32();
    mReqTargetRealPos = r.readV3();
    mReqTargetFrameType = r.readU32();
    mReqTargetFrame = r.readF32();
    u32 t1 = r.readU32();
    r.read(static_cast<void*>(&mRetActFlag), t1 * 4u);
}

inline cPrioThkCmdRetActInter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetActInter::MyDTI cPrioThkCmdRetActInter::DTI("cPrioThkCmdRetActInter", &::cPrioThkCmd::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdRetActInter::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdRetActInter;
}

const MtDTI& cPrioThkCmdRetActInterTarget::getDTI() const {
    return cPrioThkCmdRetActInterTarget::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetActInterTarget::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetActInterTarget::check")
    return {};
}

void cPrioThkCmdRetActInterTarget::load(MtDataReader& r) {
    mActionInterfaceID = r.readU32();
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mRetActFlag), t0 * 4u);
}

inline cPrioThkCmdRetActInterTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetActInterTarget::MyDTI cPrioThkCmdRetActInterTarget::DTI("cPrioThkCmdRetActInterTarget", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdRetActInterTarget::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdRetActInterTarget;
}

const MtDTI& cPrioThkCmdRetCureAct::getDTI() const {
    return cPrioThkCmdRetCureAct::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetCureAct::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetCureAct::check")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetCureAct::checkCureSpot(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetCureAct::checkCureSpot")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetCureAct::checkCureArrow(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetCureAct::checkCureArrow")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetCureAct::checkJob10AreaSupport(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetCureAct::checkJob10AreaSupport")
    return {};
}

inline cPrioThkCmdRetCureAct::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetCureAct::MyDTI cPrioThkCmdRetCureAct::DTI("cPrioThkCmdRetCureAct", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetCureAct::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetCureAct;
}

const MtDTI& cPrioThkCmdRetDispersion::getDTI() const {
    return cPrioThkCmdRetDispersion::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetDispersion::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetDispersion::check")
    return {};
}

inline cPrioThkCmdRetDispersion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetDispersion::MyDTI cPrioThkCmdRetDispersion::DTI("cPrioThkCmdRetDispersion", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetDispersion::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetDispersion;
}

const MtDTI& cPrioThkCmdRetEnemyTable::getDTI() const {
    return cPrioThkCmdRetEnemyTable::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetEnemyTable::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetEnemyTable::check")
    return {};
}

void cPrioThkCmdRetEnemyTable::load(MtDataReader& r) {
    nDDOIO::readData(r, mPawnActionGroup);
}

inline cPrioThkCmdRetEnemyTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetEnemyTable::MyDTI cPrioThkCmdRetEnemyTable::DTI("cPrioThkCmdRetEnemyTable", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdRetEnemyTable::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetEnemyTable;
}

const MtDTI& cPrioThkCmdRetFollow::getDTI() const {
    return cPrioThkCmdRetFollow::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetFollow::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetFollow::check")
    return {};
}

void cPrioThkCmdRetFollow::load(MtDataReader& r) {
    nDDOIO::readData(r, mReqMoveType);
}

inline cPrioThkCmdRetFollow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetFollow::MyDTI cPrioThkCmdRetFollow::DTI("cPrioThkCmdRetFollow", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdRetFollow::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetFollow;
}

const MtDTI& cPrioThkCmdRetFreeParam::getDTI() const {
    return cPrioThkCmdRetFreeParam::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetFreeParam::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetFreeParam::check")
    return {};
}

void cPrioThkCmdRetFreeParam::load(MtDataReader& r) {
    mFreeParamF32.elems[0] = r.readF32();
    mFreeParamF32.elems[1] = r.readF32();
    mFreeParamF32.elems[2] = r.readF32();
    mFreeParamF32.elems[3] = r.readF32();
}

inline cPrioThkCmdRetFreeParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetFreeParam::MyDTI cPrioThkCmdRetFreeParam::DTI("cPrioThkCmdRetFreeParam", &::cPrioThkCmd::DTI, 24ul, 0u, 0u);

MtObject* cPrioThkCmdRetFreeParam::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetFreeParam;
}

const MtDTI& cPrioThkCmdRetGoto::getDTI() const {
    return cPrioThkCmdRetGoto::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetGoto::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetGoto::check")
    return {};
}

void cPrioThkCmdRetGoto::load(MtDataReader& r) {
    mReqTargetType = r.readU32();
    mReqTargetRealPos = r.readV3();
    nDDOIO::readData(r, mReqTargetRange);
    nDDOIO::readData(r, mReqMoveType);
}

inline cPrioThkCmdRetGoto::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetGoto::MyDTI cPrioThkCmdRetGoto::DTI("cPrioThkCmdRetGoto", &::cPrioThkCmd::DTI, 48ul, 0u, 0u);

MtObject* cPrioThkCmdRetGoto::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetGoto;
}

const MtDTI& cPrioThkCmdRetHealAct::getDTI() const {
    return cPrioThkCmdRetHealAct::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetHealAct::check")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealArrow(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealArrow")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealArrow2(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealArrow2")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealArrowCS13(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealArrowCS13")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealingMe(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealingMe")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealingSpiritAreaMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealingSpiritAreaMiddle")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealingSpiritBitMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealingSpiritBitMiddle")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetHealAct::checkHealingPointMiddle(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetHealAct::checkHealingPointMiddle")
    return {};
}

void cPrioThkCmdRetHealAct::load(MtDataReader& r) {
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mPrioThkHealActFlag), t0 * 4u);
}

inline cPrioThkCmdRetHealAct::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetHealAct::MyDTI cPrioThkCmdRetHealAct::DTI("cPrioThkCmdRetHealAct", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCmdRetHealAct::MyDTI::newInstance() const {
        return new (16u) cPrioThkCmdRetHealAct;
}

const MtDTI& cPrioThkCmdRetNoMoveJump::getDTI() const {
    return cPrioThkCmdRetNoMoveJump::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetNoMoveJump::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetNoMoveJump::check")
    return {};
}

inline cPrioThkCmdRetNoMoveJump::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetNoMoveJump::MyDTI cPrioThkCmdRetNoMoveJump::DTI("cPrioThkCmdRetNoMoveJump", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetNoMoveJump::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetNoMoveJump;
}

const MtDTI& cPrioThkCmdRetOrder::getDTI() const {
    return cPrioThkCmdRetOrder::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetOrder::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetOrder::check")
    return {};
}

__attribute__((weak)) void cPrioThkCmdRetOrder::findPawnAIAction(cPrioThkIO& io, uDDOModel& owner, MtTypedArray<cPawnAIAction>& dst, const cAIPawnOrderParam* pPrm) {
    DDON_STUB("cPrioThkCmdRetOrder::findPawnAIAction")
    /* stub */
}

void cPrioThkCmdRetOrder::load(MtDataReader& r) {
    nDDOIO::readData(r, mOrderGroup);
}

inline cPrioThkCmdRetOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetOrder::MyDTI cPrioThkCmdRetOrder::DTI("cPrioThkCmdRetOrder", &::cPrioThkCmd::DTI, 16ul, 0u, 0u);

MtObject* cPrioThkCmdRetOrder::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetOrder;
}

const MtDTI& cPrioThkCmdRetRouteInfo::getDTI() const {
    return cPrioThkCmdRetRouteInfo::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetRouteInfo::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetRouteInfo::check")
    return {};
}

inline cPrioThkCmdRetRouteInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetRouteInfo::MyDTI cPrioThkCmdRetRouteInfo::DTI("cPrioThkCmdRetRouteInfo", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetRouteInfo::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetRouteInfo;
}

const MtDTI& cPrioThkCmdRetStaminaHealAct::getDTI() const {
    return cPrioThkCmdRetStaminaHealAct::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetStaminaHealAct::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetStaminaHealAct::check")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetStaminaHealAct::checkHealEnergySpot(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetStaminaHealAct::checkHealEnergySpot")
    return {};
}

__attribute__((weak)) u32 cPrioThkCmdRetStaminaHealAct::checkHealJob10NormalSup(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code, cGeneralPoint* pTarget) {
    DDON_STUB("cPrioThkCmdRetStaminaHealAct::checkHealJob10NormalSup")
    return {};
}

inline cPrioThkCmdRetStaminaHealAct::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetStaminaHealAct::MyDTI cPrioThkCmdRetStaminaHealAct::DTI("cPrioThkCmdRetStaminaHealAct", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetStaminaHealAct::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetStaminaHealAct;
}

const MtDTI& cPrioThkCmdRetSupport::getDTI() const {
    return cPrioThkCmdRetSupport::DTI;
}

__attribute__((weak)) u32 cPrioThkCmdRetSupport::check(cPrioThkIO& io, uDDOModel& owner, cPrioThkCode& code) {
    DDON_STUB("cPrioThkCmdRetSupport::check")
    return {};
}

inline cPrioThkCmdRetSupport::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCmdRetSupport::MyDTI cPrioThkCmdRetSupport::DTI("cPrioThkCmdRetSupport", &::cPrioThkCmd::DTI, 8ul, 0u, 0u);

MtObject* cPrioThkCmdRetSupport::MyDTI::newInstance() const {
    return new (16u) cPrioThkCmdRetSupport;
}

const MtDTI& cPrioThkCode::getDTI() const {
    return cPrioThkCode::DTI;
}

cPrioThkCode::~cPrioThkCode() {
}

__attribute__((weak)) u32 cPrioThkCode::check(cPrioThkIO& io, uDDOModel& owner) {
    DDON_STUB("cPrioThkCode::check")
    return {};
}

u32 cPrioThkCode::convID(MT_CTSTR name) {
    return MtCRC::getCRC(name, 0xFFFFFFFFu);
}

inline cPrioThkCode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkCode::MyDTI cPrioThkCode::DTI("cPrioThkCode", &::cAIResource::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkCode::MyDTI::newInstance() const {
    return new (16u) cPrioThkCode;
}

const MtDTI& cPrioThkIO::getDTI() const {
    return cPrioThkIO::DTI;
}

__attribute__((weak)) void cPrioThkIO::operator delete(void* p_addr) {
    cPrioThkIO::getAllocator()->memFree(p_addr);
}

cPrioThkIO::cPrioThkIO() {
    DDON_STUB("cPrioThkIO::cPrioThkIO")
    /* stub */
}

void cPrioThkIO::clearResultCode() {
    mResultType = 0;
    if (mResultTarget.mAutoDelete) {
        u32 v3_0;
        if (mResultTarget.mLength != 0) {
            u32 v0_0 = mResultTarget.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mResultTarget.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mResultTarget.mpArray[i0_3];
                    v1_0 = mResultTarget.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mResultTarget.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mResultTarget.mLength = 0;
    mResultTargetRealPos.x = MtVector3::Zero.x;
    mResultTargetRealPos.y = MtVector3::Zero.y;
    mResultTargetRealPos.z = MtVector3::Zero.z;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 380) = 0x42C8000000000000;
    mResultOrderAction = false;
    mResultActEndOrderClear = false;
    mResultActBreakDisableTime = 0.0f;
    mResultActInterID = 0;
    mResultTargetFrame = 0.0f;
    if (mResultFailedTarget.mAutoDelete) {
        u32 v8_0;
        if (mResultFailedTarget.mLength != 0) {
            u32 v5_0 = mResultFailedTarget.mLength;
            unsigned int i5_3 = 0;
            u32 v6_0;
            for (;;) {
                if (mResultFailedTarget.mpArray[i5_3] == nullptr) {
                    v6_0 = v5_0;
                } else {
                    delete mResultFailedTarget.mpArray[i5_3];
                    v6_0 = mResultFailedTarget.mLength;
                }
                if ((i5_3 + 1u) < v6_0) {
                    v5_0 = v6_0;
                    i5_3 += 1u;
                } else {
                    break;
                }
            }
            v8_0 = v6_0;
        } else {
            v8_0 = 0;
        }
        memset(static_cast<void*>(mResultFailedTarget.mpArray), 0, static_cast<size_t>(v8_0) * 8);
    }
    mResultFailedTarget.mLength = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 456) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 448) = 0;
    mResultReqFlag = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 444) = 0;
}

inline cPrioThkIO::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrioThkIO::MyDTI cPrioThkIO::DTI("cPrioThkIO", &::cAIObject::DTI, 608ul, 0u, 0u);

__attribute__((weak)) MtObject* cPrioThkIO::MyDTI::newInstance() const {
    DDON_STUB("cPrioThkIO::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rPriorityThink::getDTI() const {
    return rPriorityThink::DTI;
}

rPriorityThink::~rPriorityThink() {
}

bool rPriorityThink::loadData(MtDataReader& in, cPrioThkCode* pData) {
    nDDOIO::readMtArrayEx(in, pData->mCommands);
    pData->mPrio = in.readS32();
    pData->mID = in.readU32();
    cAIPawnOrderFlag* held0 = &pData->mDisableOrder;
    u32 t0 = in.readU32();
    cAIPawnOrderTypeFlag* held1 = &pData->mDisableTypeFlag;
    in.read(static_cast<void*>(held0), t0 * 4u);
    u32 t1 = in.readU32();
    in.read(static_cast<void*>(held1), t1 * 4u);
    nDDOIO::readData(in, pData->mCodeFlag);
    return true;
}

MT_CTSTR rPriorityThink::getExt() const {
    return "ptk";
}

u32 rPriorityThink::getDataVersion() const {
    return 47;
}

__attribute__((weak)) bool rPriorityThink::loadCore(MtDataReader& r) {
    u32 magic_act = r.readU32();
    return rTbl2<cPrioThkCode>::loadCore(r);
}

inline rPriorityThink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPriorityThink::MyDTI rPriorityThink::DTI("rPriorityThink", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPriorityThink::MyDTI::newInstance() const {
    return new (16u) rPriorityThink;
}

template MtTypedArray<cPrioThkCmd::cTmpResult>::~MtTypedArray();

template MtTypedArray<cPrioThkCmd>::~MtTypedArray();

template void nDDOIO::readMtArrayEx(MtDataReader&, MtTypedArray<cPrioThkCmd>&);

template cPrioThkCode* rTbl2<cPrioThkCode>::getData(unsigned int);

template bool rTbl2<cPrioThkCode>::load(MtStream&);

template bool rTbl2<cPrioThkCode>::loadCore(MtDataReader&);

template const cPrioThkCode* rTbl2<cPrioThkCode>::getData(unsigned int) const;

template unsigned int rTbl2<cPrioThkCode>::getDataNum() const;

template rTbl2<cPrioThkCode>::~rTbl2();

