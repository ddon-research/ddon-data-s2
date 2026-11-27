// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cObjHitCache.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cHitNode.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cObjHitCache::getDTI() const {
    return cObjHitCache::DTI;
}

cObjHitCache::cObjHitCache() {
    mPri = 0xFFFFFFFFFFFFFFFFul;
    mpDfdModel = nullptr;
    mpAtkModel = nullptr;
    mpDfdGeom = nullptr;
    mpAtkGeom = nullptr;
    mpDfdNode = nullptr;
    mpAtkNode = nullptr;
    mAtkAttr = 0;
    mDfdAttr = 0;
    mAge = 0.0f;
    mLinkID = 0;
    mUID = 0;
    mTimer = 0.0f;
}

void cObjHitCache::clear() {
    mPri = 0xFFFFFFFFFFFFFFFFul;
    mpDfdModel = nullptr;
    mpAtkModel = nullptr;
    mpDfdGeom = nullptr;
    mpAtkGeom = nullptr;
    mpDfdNode = nullptr;
    mpAtkNode = nullptr;
    mAtkAttr = 0;
    mDfdAttr = 0;
    mAge = 0.0f;
    mLinkID = 0;
    mUID = 0;
    mTimer = 0.0f;
}

void cObjHitCache::copy(const cObjHitCache* pSrc, bool copy_node) {
    if (pSrc == nullptr) {
        return;
    }
    mPri = pSrc->mPri;
    mUID = pSrc->mUID;
    mTimer = pSrc->mTimer;
    mAge = pSrc->mAge;
    mAtkAttr = pSrc->mAtkAttr;
    mDfdAttr = pSrc->mDfdAttr;
    if (copy_node) {
        mpAtkNode = pSrc->mpAtkNode;
        mpDfdNode = pSrc->mpDfdNode;
        mpAtkGeom = pSrc->mpAtkGeom;
        mpDfdGeom = pSrc->mpDfdGeom;
    } else {
        mpAtkGeom = nullptr;
        mpDfdNode = nullptr;
        mpAtkNode = nullptr;
        mpDfdGeom = nullptr;
    }
    mpAtkModel = pSrc->mpAtkModel;
    mpDfdModel = pSrc->mpDfdModel;
}

void cObjHitCache::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mUID", &mUID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTimer", &mTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAge", &mAge, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLinkID", &mLinkID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAtkAttr", &mAtkAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDfdAttr", &mDfdAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAtkModel", reinterpret_cast<MtObject* *>(&mpAtkModel), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDfdModel", reinterpret_cast<MtObject* *>(&mpDfdModel), 0u, 0u);
}

void cObjHitCache::resetHitCache() {
    if (mpAtkNode == nullptr) {
        return;
    }
    mpAtkNode->resetHitNode();
}

inline cObjHitCache::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cObjHitCache::MyDTI cObjHitCache::DTI("cObjHitCache", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* cObjHitCache::MyDTI::newInstance() const {
    return new (16u) cObjHitCache;
}

