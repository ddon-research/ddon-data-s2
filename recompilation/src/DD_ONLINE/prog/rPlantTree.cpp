// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPlantTree.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rPlantTree::getDTI() const {
    return rPlantTree::DTI;
}

rPlantTree::~rPlantTree() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~Tree();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rPlantTree::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) void rPlantTree::clear() {
}

__attribute__((weak)) bool rPlantTree::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x746c70) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    const u32 nTreeXmlNum = r.readU32();
    const u32 nSizeBinary = r.readU32();
    void* pBinaryTreeXml = MtMemoryAllocator::getAllocator(rPlantTree::DTI)->memAlloc(nSizeBinary, 16);
    u8* pBinaryCursor = static_cast<u8*>(pBinaryTreeXml) + nTreeXmlNum * sizeof(Tree);
    pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
    for (u32 i = 0; i < nTreeXmlNum; ++i) {
        Tree* pBinary = new (&static_cast<Tree*>(pBinaryTreeXml)[i]) Tree;
        nDDOIO::readData(r, pBinary->mOmId);
        const u32 nPointNum = r.readU32();
        void* pPointTreeXml = pBinaryCursor;
        pBinaryCursor += nPointNum * sizeof(Tree::Point);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 e = 0; e < nPointNum; ++e) {
            Tree::Point* pBinary = new (&static_cast<Tree::Point*>(pPointTreeXml)[e]) Tree::Point;
            nDDOIO::readData(r, pBinary->mPosition);
            nDDOIO::readData(r, pBinary->mAngle);
            nDDOIO::readData(r, pBinary->mScale);
        }
        pBinary->mpPointList = static_cast<Tree::Point*>(pPointTreeXml);
        pBinary->mPointListNum = nPointNum;
    }
    mpArray = static_cast<Tree*>(pBinaryTreeXml);
    mArrayNum = nTreeXmlNum;
    return true;
}

__attribute__((weak)) bool rPlantTree::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x746c70);
    w.writeU32(DATA_VERSION);
    const u32 nTreeXmlNum = rPlantTree::getTreeNum();
    w.writeU32(nTreeXmlNum);
    u32 nSizeBinary = nTreeXmlNum * sizeof(Tree);
    nSizeBinary = (nSizeBinary + 15) & ~15;
    for (u32 i = 0; i < nTreeXmlNum; ++i) {
        Tree* p = rPlantTree::getTree(i);
        nSizeBinary += p->getPointListNum() * sizeof(Tree::Point);
        nSizeBinary = (nSizeBinary + 15) & ~15;
    }
    w.writeU32(nSizeBinary);
    for (u32 i = 0; i < nTreeXmlNum; ++i) {
        Tree* p = rPlantTree::getTree(i);
        nDDOIO::writeData(w, p->mOmId);
        const u32 nPointNum = p->getPointListNum();
        w.writeU32(nPointNum);
        for (u32 e = 0; e < nPointNum; ++e) {
            Tree::Point* pPoint = p->getPointList(e);
            nDDOIO::writeData(w, pPoint->mPosition);
            nDDOIO::writeData(w, pPoint->mAngle);
            nDDOIO::writeData(w, pPoint->mScale);
        }
    }
    return true;
}

MT_CTSTR rPlantTree::getExt() const {
    return "plt";
}

u32 rPlantTree::getTreeNum() {
    return mArrayNum;
}

rPlantTree::Tree* rPlantTree::getTree(u32 idx) {
    return &mpArray[idx];
}

inline rPlantTree::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlantTree::MyDTI rPlantTree::DTI("rPlantTree", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rPlantTree::MyDTI::newInstance() const {
    return new (16u) rPlantTree;
}

const MtDTI& rPlantTree::Tree::getDTI() const {
    return rPlantTree::Tree::DTI;
}

rPlantTree::Tree::~Tree() {
    for (u32 i = 0; i < mPointListNum; ++i) {
        mpPointList[i].~Point();
    }
    mpPointList = nullptr;
    mPointListNum = 0;
}

rPlantTree::Tree::Point* rPlantTree::Tree::getPointList(u32 index) {
    return &mpPointList[index];
}

u32 rPlantTree::Tree::getPointListNum() {
    return mPointListNum;
}

inline rPlantTree::Tree::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlantTree::Tree::MyDTI rPlantTree::Tree::DTI("rPlantTree::Tree", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rPlantTree::Tree::MyDTI::newInstance() const {
    return new (16u) rPlantTree::Tree;
}

const MtDTI& rPlantTree::Tree::Point::getDTI() const {
    return rPlantTree::Tree::Point::DTI;
}

void rPlantTree::Tree::Point::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPosition", &mPosition, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngle", &mAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScale", &mScale, 0u, 0u);
}

inline rPlantTree::Tree::Point::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlantTree::Tree::Point::MyDTI rPlantTree::Tree::Point::DTI("rPlantTree::Tree::Point", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* rPlantTree::Tree::Point::MyDTI::newInstance() const {
    return new (16u) rPlantTree::Tree::Point;
}

