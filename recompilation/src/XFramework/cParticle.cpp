// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cParticle.h"
#include "../MT/MtColor.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "cPrim.h"
#include "cUnit.h"
#include "nEffect.h"
#include "nPrim.h"
#include "rEffectAnim.h"
#include "rEffectList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

u32 cClothVertex::getParamBuffSize(u32 ClothType, u32 VertexNum) {
    if (ClothType != 2) {
        if (ClothType != 1) {
            if (ClothType == 0) {
                return VertexNum * 32u;
            }
        }
        return VertexNum * 16u;
    } else {
        return VertexNum * 32u;
    }
}

__attribute__((weak)) void cClothVertex::init(u8* pParamBuff, u32 ClothType, u32 VertexNum) {
    DDON_STUB("cClothVertex::init")
    /* stub */
}

__attribute__((weak)) void cClothVertex::initClothChainVertex(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate) {
    DDON_STUB("cClothVertex::initClothChainVertex")
    /* stub */
}

__attribute__((weak)) void cClothVertex::initClothChainVertexForce(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, const MtVector3& ForceVec) {
    DDON_STUB("cClothVertex::initClothChainVertexForce")
    /* stub */
}

__attribute__((weak)) void cClothVertex::updateClothStraightVertex(cClothStraight* pClothStraight, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate) {
    DDON_STUB("cClothVertex::updateClothStraightVertex")
    /* stub */
}

__attribute__((weak)) void cClothVertex::updateClothChainVertex(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, f32 Dt) {
    DDON_STUB("cClothVertex::updateClothChainVertex")
    /* stub */
}

__attribute__((weak)) void cClothVertex::updateClothChainVertexForce(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, f32 Dt, const MtVector3& ForceVec) {
    DDON_STUB("cClothVertex::updateClothChainVertexForce")
    /* stub */
}

__attribute__((weak)) void cClothVertex::updateClothCurveVertex(rEffectList::EFL_PARAM_CLOTH_CURVE* pClothCurveParam, cClothCurve* pClothCurve, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate) {
    DDON_STUB("cClothVertex::updateClothCurveVertex")
    /* stub */
}

__attribute__((weak)) void cClothVertex::updateClothZigzagVertex(rEffectList::EFL_PARAM_CLOTH_ZIGZAG* pClothZigzagParam, cClothZigzag* pClothZigzag, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate) {
    DDON_STUB("cClothVertex::updateClothZigzagVertex")
    /* stub */
}

void cClothVertex::applyWorldOffset(const MtVector3& Offset) {
    if (mVertexNum != 0) {
        MtVector3* v0_0 = mPos;
        for (unsigned int i0_1 = 0;;) {
            v0_0[i0_1].x = Offset.x + v0_0[i0_1].x;
            v0_0[i0_1].y = Offset.y + v0_0[i0_1].y;
            v0_0[i0_1].z = Offset.z + v0_0[i0_1].z;
            if ((i0_1 + 1u) < mVertexNum) {
                i0_1 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void cClothVertex::initClothChainVertexCommon(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate) {
    DDON_STUB("cClothVertex::initClothChainVertexCommon")
    /* stub */
}

__attribute__((weak)) void cEffectChain::initChain(rEffectList::EFL_PARAM_CHAIN* pChainParam, u32 DataIndex, f32 Length, const MtVector3& Vec, const MtVector3& ForceVec) {
    DDON_STUB("cEffectChain::initChain")
    /* stub */
}

__attribute__((weak)) void cEffectChain::initBlendChain(rEffectList::EFL_PARAM_CHAIN* pChainParam, u32 DataIndex, f32 Length, const MtVector3& Vec0, const MtVector3& Vec1, const MtVector3& ForceVec) {
    DDON_STUB("cEffectChain::initBlendChain")
    /* stub */
}

__attribute__((weak)) void cEffectChain::calcChain(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec, f32 Length) {
    DDON_STUB("cEffectChain::calcChain")
    /* stub */
}

__attribute__((weak)) void cEffectChain::calcChainForce(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec, f32 Length, const MtVector3& ForceVec) {
    DDON_STUB("cEffectChain::calcChainForce")
    /* stub */
}

__attribute__((weak)) void cEffectChain::calcBlendChain(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec0, const MtVector3& AccelerationVec1, f32 Length) {
    DDON_STUB("cEffectChain::calcBlendChain")
    /* stub */
}

__attribute__((weak)) void cEffectChain::calcBlendChainForce(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec0, const MtVector3& AccelerationVec1, f32 Length, const MtVector3& ForceVec) {
    DDON_STUB("cEffectChain::calcBlendChainForce")
    /* stub */
}

bool cParticle::updateSynchroEnable() {
    if (mpSynchroUnit != nullptr) {
        if ((mpSynchroUnit->mBeFlag - 1u) > 1u) {
            mpSynchroUnit = nullptr;
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void cParticle::kill() {
    mEnableFlag = 0;
    if (mpSynchroUnit == nullptr) {
        return;
    }
    if ((mpSynchroUnit->mBeFlag - 1u) <= 1u) {
        mpSynchroUnit->kill();
        mpSynchroUnit = nullptr;
    }
}

__attribute__((weak)) MtVector3 cParticleMoveSpin::getCirclePos(const MtVector3& Scale, u32 RotOrder) const {
    DDON_STUB("cParticleMoveSpin::getCirclePos")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 cParticleMoveSpin::getCirclePos(const MtVector3& Scale, u32 RotOrder, u32 RotAxisType) const {
    DDON_STUB("cParticleMoveSpin::getCirclePos")
    __builtin_unreachable();
}

__attribute__((weak)) bool cPolygon::initAnim(rEffectAnim* pAnim, const cParticleAnimParam& Param) {
    DDON_STUB("cPolygon::initAnim")
    return {};
}

__attribute__((weak)) void cPolygon::drawClothPolygon(cPrim* pPrim, MtVector3* pPosBuff, rEffectAnim::SEQ_PAT* pSeqPat, const cClothPolygonDrawParam& DrawParam) {
    DDON_STUB("cPolygon::drawClothPolygon")
    /* stub */
}

