// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cParticleGeneratorPolygon.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cDraw.h"
#include "cParticle.h"
#include "cParticleGenerator.h"
#include "cParticleManager.h"
#include "cPrim.h"
#include "rCollisionHeightField.h"
#include "rEffectList.h"
#include "sCollision.h"
#include "sEffect.h"
#include "sMain.h"
#include "sPrimitive.h"
#include "sUnit.h"
#include "uBaseEffect.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cParticleGeneratorAdhesion::getDTI() const {
    return cParticleGeneratorAdhesion::DTI;
}

void* cParticleGeneratorAdhesion::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cParticleGeneratorAdhesion::DTI)->memAlloc(sz, align, cParticleGeneratorAdhesion::DTI.mID);
}

cParticleGeneratorAdhesion::cParticleGeneratorAdhesion() {
    DDON_STUB("cParticleGeneratorAdhesion::cParticleGeneratorAdhesion")
    /* stub */
}

cParticleGeneratorAdhesion::~cParticleGeneratorAdhesion() {
}

__attribute__((weak)) void cParticleGeneratorAdhesion::initParam() {
    DDON_STUB("cParticleGeneratorAdhesion::initParam")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorAdhesion::update() {
    DDON_STUB("cParticleGeneratorAdhesion::update")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorAdhesion::draw(cDraw* pDraw, s32 Transparency, u8* pDrawBuff) {
}

__attribute__((weak)) bool cParticleGeneratorAdhesion::initParticle(cParticle* pParticle, cParticleGenerator::ParticleParam& Param) {
    DDON_STUB("cParticleGeneratorAdhesion::initParticle")
    return {};
}

__attribute__((weak)) bool cParticleGeneratorAdhesion::moveParticleLoop() {
    DDON_STUB("cParticleGeneratorAdhesion::moveParticleLoop")
    return {};
}

__attribute__((weak)) uSynchroAdhesion* cParticleGeneratorAdhesion::getSynchroAdhesion(cPolygon* pPolygon) {
    DDON_STUB("cParticleGeneratorAdhesion::getSynchroAdhesion")
    return nullptr;
}

inline cParticleGeneratorAdhesion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cParticleGeneratorAdhesion::MyDTI cParticleGeneratorAdhesion::DTI("cParticleGeneratorAdhesion", &::cParticleGeneratorPolygon::DTI, 560ul, 0u, 0u);

__attribute__((weak)) MtObject* cParticleGeneratorAdhesion::MyDTI::newInstance() const {
    DDON_STUB("cParticleGeneratorAdhesion::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cParticleGeneratorPolygon::getDTI() const {
    return cParticleGeneratorPolygon::DTI;
}

void* cParticleGeneratorPolygon::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cParticleGeneratorPolygon::DTI)->memAlloc(sz, align, cParticleGeneratorPolygon::DTI.mID);
}

cParticleGeneratorPolygon::cParticleGeneratorPolygon() {
}

cParticleGeneratorPolygon::~cParticleGeneratorPolygon() {
}

bool cParticleGeneratorPolygon::constructParam(uEffect* pOwner, u32 ListNo, u32 ManagerNo) {
    if (this->cParticleGenerator::constructParam(pOwner, ListNo, ManagerNo)) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpParticleParam) + 424)) != 0) {
            return constructParticleMapping(288u, 32u);
        } else {
            return constructParticleMapping(288u, 0u);
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void cParticleGeneratorPolygon::initParam() {
    DDON_STUB("cParticleGeneratorPolygon::initParam")
    /* stub */
}

void cParticleGeneratorPolygon::applyWorldOffset(const MtVector3& Offset) {
    this->cParticleGenerator::applyWorldOffset(Offset);
    applyParticleWorldOffsetLoop(Offset);
}

void cParticleGeneratorPolygon::updateConst() {
    this->cParticleGenerator::updateConst();
    updateConstParticleMatrixLoop();
}

void cParticleGeneratorPolygon::draw(cDraw* pDraw, s32 Transparency, u8*) {
    if (mDrawType == 27) {
        drawParticleCullingPolygonLoop(pDraw, Transparency);
    } else {
        if (mDrawType == 2) {
            drawParticlePolygonLoop(pDraw, Transparency);
        }
    }
}

__attribute__((weak)) bool cParticleGeneratorPolygon::initParticle(cParticle* pParticle, cParticleGenerator::ParticleParam& Param) {
    DDON_STUB("cParticleGeneratorPolygon::initParticle")
    return {};
}

__attribute__((weak)) bool cParticleGeneratorPolygon::moveParticleLoop() {
    DDON_STUB("cParticleGeneratorPolygon::moveParticleLoop")
    return {};
}

__attribute__((weak)) bool cParticleGeneratorPolygon::moveParticlePolygon(cParticle* pParticle) {
    DDON_STUB("cParticleGeneratorPolygon::moveParticlePolygon")
    return {};
}

__attribute__((weak)) void cParticleGeneratorPolygon::moveParticlePolygonCullingLoop() {
    DDON_STUB("cParticleGeneratorPolygon::moveParticlePolygonCullingLoop")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorPolygon::drawParticlePolygonLoop(cDraw* pDraw, s32 Transparency) {
    DDON_STUB("cParticleGeneratorPolygon::drawParticlePolygonLoop")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorPolygon::drawParticleCullingPolygonLoop(cDraw* pDraw, s32 Transparency) {
    DDON_STUB("cParticleGeneratorPolygon::drawParticleCullingPolygonLoop")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorPolygon::setPolygonVertex(cPolygon* pPolygon, nPrim::Vertex* pVertex, const MtMatrix& Wmat, const cPolygonDrawParam& DrawParam) {
    DDON_STUB("cParticleGeneratorPolygon::setPolygonVertex")
    /* stub */
}

__attribute__((weak)) void cParticleGeneratorPolygon::drawDividePolygon(cPrim* pPrim, cPolygon* pPolygon, nPrim::Vertex* pVertex, s32 Zofs, s32 OtDepth, u32 DivideNum) {
    DDON_STUB("cParticleGeneratorPolygon::drawDividePolygon")
    /* stub */
}

inline cParticleGeneratorPolygon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cParticleGeneratorPolygon::MyDTI cParticleGeneratorPolygon::DTI("cParticleGeneratorPolygon", &::cParticleGenerator::DTI, 560ul, 0u, 0u);

MtObject* cParticleGeneratorPolygon::MyDTI::newInstance() const {
    return new (16u) cParticleGeneratorPolygon;
}

