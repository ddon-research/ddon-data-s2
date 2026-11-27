// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNavigationMesh.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cAI.h"
#include "rAIPathBase.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rNavigationMesh::getDTI() const {
    return rNavigationMesh::DTI;
}

__attribute__((noinline)) rNavigationMesh::~rNavigationMesh() {
    if (mpPolygonVertex != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::DTI)->memFree(mpPolygonVertex);
    }
    if (mpNode != nullptr) {
        nodeData* t1 = mpNode;
        size_t t2 = *(reinterpret_cast<size_t*>(t1) - 1);
        for (nodeData* t3 = t1 + t2; t3 != t1;) {
            (--t3)->nodeData::~nodeData();
        }
        void* t4 = reinterpret_cast<char*>(t1) - 16;
        MtMemoryAllocator::getAllocator(rNavigationMesh::nodeData::DTI)->memFree(t4);
    }
    if (mpNodeInfo != nullptr) {
        void* t5 = reinterpret_cast<char*>(mpNodeInfo) - 16;
        MtMemoryAllocator::getAllocator(rNavigationMesh::nodeInfo::DTI)->memFree(t5);
    }
    if (mpQuadTree != nullptr) {
        delete mpQuadTree;
    }
    if (mpNodeBuffer != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::DTI)->memFree(mpNodeBuffer);
    }
    if (mpNearWall != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::DTI)->memFree(mpNearWall);
    }
    if (mpWallDistance != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::DTI)->memFree(mpWallDistance);
    }
}

MT_CTSTR rNavigationMesh::getExt() const {
    return "nav";
}

__attribute__((weak)) bool rNavigationMesh::save(MtStream& out) {
    MtDataWriter w(out, 0x1000, 0x1000);
    u32 Buffer;
    u32 i;
    w.writeU32(mCoreHeader.magic);
    w.writeU32(mCoreHeader.version);
    w.writeU32(mCoreHeader.type);
    Buffer = 0;
    for (i = 0; i < mNumberOfNode; ++i) {
        Buffer += mpNode[i].mNumberOfAttribute;
        Buffer += mpNode[i].mNumberOfCAttribute;
        Buffer += mpNode[i].mPolygonArea.mNumberOfIndex;
        Buffer += 6 * mpNode[i].mNumberOfLink;
    }
    w.writeU32(Buffer);
    saveNavigation(w);
    return true;
}

bool rNavigationMesh::load(MtStream& in) {
    u32 t0 = (sResource::mpInstance)->mRNavigationMeshDataReaderBufferSizeKB;
    u32 t1 = in.getLength();
    MtDataReader r(in, (t1 < (t0 * 1024u)) ? t1 : (t0 * 1024u));
    mCoreHeader.magic = r.MtDataReader::readU32();
    mCoreHeader.version = r.MtDataReader::readU32();
    mCoreHeader.type = r.MtDataReader::readU32();
    mCoreHeader.attributeBuffer = r.MtDataReader::readU32();
    if (mCoreHeader.magic == 0x56414E) {
        if (mCoreHeader.version == 33) {
            loadNavigation(r);
            return true;
        }
    }
    return false;
}

void rNavigationMesh::createProperty(MtPropertyList& s) {
    this->rAIPathBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCoreHeader.magic", &mCoreHeader.magic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCoreHeader.version", &mCoreHeader.version, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCoreHeader.type", &mCoreHeader.type, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpNode", reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::getNode), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::setNode), 160u, reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::getNumberOfNode), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::setNumberOfNode));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpNodeInfo", reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::getNodeInfo), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::setNodeInfo), 160u, reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::getNumberOfNodeInfo), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::setNumberOfNodeInfo));
}

__attribute__((weak)) void rNavigationMesh::saveNavigation(MtDataWriter& w) {
    u8 write;
    u32 MaxLink;
    u32 MaxAttr;
    u32 MaxIndex;
    u32 i;
    u32 j;
    rNavigationMesh::nodeData* ppNode;
    MtAABB aabb;
    cAITreeBase::Node* pNode;
    u32 param;
    u32 n;
    w.writeU32(mName.length());
    w.writeString(mName.ptr());
    w.writeU32(mNumberOfVertex);
    w.writeU32(mNumberOfNode);
    w.writeU32(mNumberOfNodeInfo);
    write = (mpNearWall != nullptr && mpWallDistance != nullptr);
    w.writeU8(write);
    if (write != 0) {
        for (i = 0; i < mNumberOfVertex; ++i) {
            w.writeF32(mpPolygonVertex[i].x);
            w.writeF32(mpPolygonVertex[i].y);
            w.writeF32(mpPolygonVertex[i].z);
            w.writeU8(mpNearWall[i] ? 1 : 0);
            w.writeU16(mpWallDistance[i]);
        }
    } else {
        for (i = 0; i < mNumberOfVertex; ++i) {
            w.writeF32(mpPolygonVertex[i].x);
            w.writeF32(mpPolygonVertex[i].y);
            w.writeF32(mpPolygonVertex[i].z);
        }
    }
    MaxLink = 0;
    MaxAttr = 0;
    MaxIndex = 0;
    for (i = 0; i < mNumberOfNode; ++i) {
        w.writeS32(mpNode[i].mIndex);
        w.writeU32(mpNode[i].mNumberOfAttribute);
        MaxAttr += mpNode[i].mNumberOfAttribute;
        for (j = 0; j < mpNode[i].mNumberOfAttribute; ++j) {
            w.writeU32(mpNode[i].mpAttribute[j]);
        }
        w.writeU8(mpNode[i].mConnect ? 1 : 0);
        w.writeV3(MtFloat3(mpNode[i].mDir));
        w.writeF32(mpNode[i].mLength);
        w.writeU8(static_cast<u8>(mpNode[i].mNumberOfCAttribute));
        for (j = 0; j < mpNode[i].mNumberOfCAttribute; ++j) {
            w.writeU32(mpNode[i].mpCAttribute[j]);
        }
        w.writeU32(mpNode[i].mPolygonArea.mNumberOfIndex);
        MaxIndex += mpNode[i].mPolygonArea.mNumberOfIndex;
        for (j = 0; j < mpNode[i].mPolygonArea.mNumberOfIndex; ++j) {
            w.writeS32(mpNode[i].mPolygonArea.mpVertexIndex[j]);
        }
        w.writeU32(mpNode[i].mNumberOfLink);
        n = mpNode[i].mNumberOfLink;
        for (j = 0; j < n; ++j) {
            if (mpNode[i].mpLinkInformation[j].mLinkNodeIndex > -2) {
                w.writeU32(mpNode[i].mpLinkInformation[j].mLinkNodeIndex);
                w.writeU32(mpNode[i].mpLinkInformation[j].mAttribute);
                w.writeU32(mpNode[i].mpLinkInformation[j].mPortalNumber);
                w.writeF32(mpNode[i].mpLinkInformation[j].mLinkCost);
                w.writeF32(mpNode[i].mpLinkInformation[j].mSize);
                w.writeF32(mpNode[i].mpLinkInformation[j].mHeight);
            } else {
                ++n;
            }
        }
        MaxLink += mpNode[i].mNumberOfLink;
    }
    this->rAIPathBase::save(&w);
    mNumberOfTotalLink = MaxLink;
    w.writeU32(mNumberOfTotalLink);
    mNumberOfTotalAttribute = MaxAttr;
    w.writeU32(mNumberOfTotalAttribute);
    mNumberOfTotalIndex = MaxIndex;
    w.writeU32(mNumberOfTotalIndex);
    for (i = 0; i < mNumberOfNodeInfo; ++i) {
        w.writeU32(mpNodeInfo[i].mNodeOffset);
        w.write(&mpNodeInfo[i].mAABB, 0x20);
    }
    w.writeU8(mpQuadTree->getNest());
    w.writeU32(mpQuadTree->getNumberOfNode());
    aabb = mpQuadTree->getRegion();
    w.write(&aabb, 0x20);
    for (i = 0; i < mpQuadTree->getNumberOfNode(); ++i) {
        pNode = mpQuadTree->getNode(i);
        w.writeU32(pNode->getNumberOfObject());
        for (j = 0; j < pNode->getNumberOfObject(); ++j) {
            w.writeU32(static_cast<nodeData*>(pNode->getObject(j, param))->getIndex());
            w.writeU32(param);
        }
    }
}

__attribute__((weak)) void rNavigationMesh::loadNavigation(MtDataReader& r) {
    MT_CHAR str[256];
    u32 len = r.readU32();
    r.readString(str, len + 1);
    mName.format(str);
    mNumberOfVertex = r.readU32();
    mNumberOfNode = r.readU32();
    mNumberOfNodeInfo = r.readU32();
    if (mpPolygonVertex) {
        MtMemoryAllocator::getAllocator(DTI)->memFree(mpPolygonVertex);
        mpPolygonVertex = nullptr;
    }
    if (mpNearWall) {
        MtMemoryAllocator::getAllocator(DTI)->memFree(mpNearWall);
        mpNearWall = nullptr;
    }
    if (mpWallDistance) {
        MtMemoryAllocator::getAllocator(DTI)->memFree(mpWallDistance);
        mpWallDistance = nullptr;
    }
    u8 read = r.readU8();
    mpPolygonVertex = static_cast<MtVector3*>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(MtVector3) * mNumberOfVertex, 16));
    mpNearWall = static_cast<bool*>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(bool) * mNumberOfVertex, 16));
    mpWallDistance = static_cast<u16*>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(u16) * mNumberOfVertex, 16));
    for (u32 i = 0; i < mNumberOfVertex; ++i) {
        mpPolygonVertex[i].x = r.readF32();
        mpPolygonVertex[i].y = r.readF32();
        mpPolygonVertex[i].z = r.readF32();
        if (read == 1) {
            mpNearWall[i] = r.readU8() == 1;
            mpWallDistance[i] = r.readU16();
        }
    }
    delete[] mpNode;
    mpNode = new (16) nodeData[mNumberOfNode];
    if (mpNodeBuffer) {
        MtMemoryAllocator::getAllocator(DTI)->memFree(mpNodeBuffer);
    }
    mpNodeBuffer = static_cast<u32*>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(u32) * mCoreHeader.attributeBuffer, 16));
    u32 count = 0;
    for (u32 i = 0; i < mNumberOfNode; ++i) {
        mpNode[i].mNoMemFree = true;
        mpNode[i].mIndex = r.readS32();
        mpNode[i].mNumberOfAttribute = r.readU32();
        for (u32 j = 0; j < mpNode[i].mNumberOfAttribute; ++j) mpNodeBuffer[count++] = r.readU32();
        mpNode[i].mConnect = r.readU8() == 1;
        mpNode[i].mDir = r.readV3();
        mpNode[i].mLength = r.readF32();
        mpNode[i].mNumberOfCAttribute = r.readU8();
        for (u32 j = 0; j < mpNode[i].mNumberOfCAttribute; ++j) mpNodeBuffer[count++] = r.readU32();
        mpNode[i].mPolygonArea.mNumberOfIndex = r.readU32();
        for (u32 j = 0; j < mpNode[i].mPolygonArea.mNumberOfIndex; ++j) mpNodeBuffer[count++] = r.readS32();
        mpNode[i].mNumberOfLink = r.readU32();
        for (u32 j = 0; j < mpNode[i].mNumberOfLink; ++j) {
            mpNodeBuffer[count++] = r.readU32();
            mpNodeBuffer[count++] = r.readU32();
            mpNodeBuffer[count++] = r.readU32();
            r.read(&mpNodeBuffer[count++], 4);
            r.read(&mpNodeBuffer[count++], 4);
            r.read(&mpNodeBuffer[count++], 4);
        }
    }
    count = 0;
    for (u32 i = 0; i < mNumberOfNode; ++i) {
        if (mpNode[i].mNumberOfAttribute) {
            mpNode[i].mpAttribute = &mpNodeBuffer[count];
            count += mpNode[i].mNumberOfAttribute;
        }
        if (mpNode[i].mNumberOfCAttribute) {
            mpNode[i].mpCAttribute = &mpNodeBuffer[count];
            count += mpNode[i].mNumberOfCAttribute;
        }
        mpNode[i].mPolygonArea.mpVertexIndex = reinterpret_cast<s32*>(&mpNodeBuffer[count]);
        count += mpNode[i].mPolygonArea.mNumberOfIndex;
        mpNode[i].mpLinkInformation = reinterpret_cast<nodeData::LinkInfo*>(&mpNodeBuffer[count]);
        count += 6 * mpNode[i].mNumberOfLink;
    }
    rAIPathBase::load(&r);
    mNumberOfTotalLink = r.readU32();
    mNumberOfTotalAttribute = r.readU32();
    mNumberOfTotalIndex = r.readU32();
    if (mpNodeInfo) {
        delete[] mpNodeInfo;
        mpNodeInfo = nullptr;
    }
    if (mNumberOfNodeInfo) {
        setNumberOfNodeInfo(mNumberOfNodeInfo);
        for (u32 i = 0; i < mNumberOfNodeInfo; ++i) {
            mpNodeInfo[i].mNodeOffset = r.readU32();
            r.read(&mpNodeInfo[i].mAABB, 0x20);
        }
    }
    u8 nest = r.readU8();
    u32 n = r.readU32();
    MtAABB aabb;
    r.read(&aabb, 0x20);
    if (mpQuadTree) delete mpQuadTree;
    mpQuadTree = new (16) cAIQuadTree();
    MtVector3 ext = aabb.getExtent().normalize();
    aabb.maxpos += ext;
    aabb.minpos -= ext;
    mpQuadTree->createNode(aabb, nest, n, true);
    for (u32 i = 0; i < mpQuadTree->getNumberOfNode(); ++i) {
        cAITreeBase::Node* pNode = mpQuadTree->getNode(i);
        u32 num = r.readU32();
        if (num) {
            pNode->setNumberOfObject(num);
            for (u32 j = 0; j < num; ++j) {
                u32 index = r.readU32();
                u32 param = r.readU32();
                pNode->addObject(&mpNode[index], j, param);
            }
        }
    }
}

static auto ddon_emit_0x01b92f70 __attribute__((used)) = &rNavigationMesh::getNode;

static auto ddon_emit_0x01b92f80 __attribute__((used)) = &rNavigationMesh::getNumberOfNode;

__attribute__((weak)) MtVector3 rNavigationMesh::getNodePos(u32 index) {
    DDON_STUB("rNavigationMesh::getNodePos")
    __builtin_unreachable();
}

static auto ddon_emit_0x01b92f90 __attribute__((used)) = &rNavigationMesh::getNodeInfo;

static auto ddon_emit_0x01b92fb0 __attribute__((used)) = &rNavigationMesh::getNumberOfNodeInfo;

__attribute__((weak)) void rNavigationMesh::setNode(rNavigationMesh::nodeData& node, u32 i) {
    DDON_STUB("rNavigationMesh::setNode")
    /* stub */
}

__attribute__((weak)) void rNavigationMesh::setNumberOfNode(u32 size) {
    DDON_STUB("rNavigationMesh::setNumberOfNode")
    /* stub */
}

void rNavigationMesh::setNodeInfo(rNavigationMesh::nodeInfo& info, u32 i) {
    if (i < mNumberOfNodeInfo) {
        mpNodeInfo[i].mNodeOffset = info.mNodeOffset;
        mpNodeInfo[i].mAABB.minpos.x = info.mAABB.minpos.x;
        mpNodeInfo[i].mAABB.minpos.y = info.mAABB.minpos.y;
        mpNodeInfo[i].mAABB.minpos.z = info.mAABB.minpos.z;
        mpNodeInfo[i].mAABB.minpos.pad_ = 0.0f;
        mpNodeInfo[i].mAABB.maxpos.x = info.mAABB.maxpos.x;
        mpNodeInfo[i].mAABB.maxpos.y = info.mAABB.maxpos.y;
        mpNodeInfo[i].mAABB.maxpos.z = info.mAABB.maxpos.z;
        mpNodeInfo[i].mAABB.maxpos.pad_ = 0.0f;
    }
}

__attribute__((weak)) void rNavigationMesh::setNumberOfNodeInfo(u32 size) {
        if (size != 0) {
            if (mpNodeInfo != nullptr) {
                nodeInfo* info = new (16u) nodeInfo[mNumberOfNodeInfo];
                for (u32 i = 0; i < mNumberOfNodeInfo; i++) {
                    info[i].mNodeOffset = mpNodeInfo[i].mNodeOffset;
                    info[i].mAABB.minpos.x = mpNodeInfo[i].mAABB.minpos.x;
                    info[i].mAABB.minpos.y = mpNodeInfo[i].mAABB.minpos.y;
                    info[i].mAABB.minpos.z = mpNodeInfo[i].mAABB.minpos.z;
                    info[i].mAABB.minpos.pad_ = 0.0f;
                    info[i].mAABB.maxpos.x = mpNodeInfo[i].mAABB.maxpos.x;
                    info[i].mAABB.maxpos.y = mpNodeInfo[i].mAABB.maxpos.y;
                    info[i].mAABB.maxpos.z = mpNodeInfo[i].mAABB.maxpos.z;
                    info[i].mAABB.maxpos.pad_ = 0.0f;
                }
                if (mpNodeInfo != nullptr) {
                    delete[] mpNodeInfo;
                    mpNodeInfo = nullptr;
                }
                mpNodeInfo = new (16u) nodeInfo[size];
                u32 n = mNumberOfNodeInfo < size ? mNumberOfNodeInfo : size;
                for (u32 i = 0; i < n; i++) {
                    mpNodeInfo[i].mNodeOffset = info[i].mNodeOffset;
                    mpNodeInfo[i].mAABB.minpos.x = info[i].mAABB.minpos.x;
                    mpNodeInfo[i].mAABB.minpos.y = info[i].mAABB.minpos.y;
                    mpNodeInfo[i].mAABB.minpos.z = info[i].mAABB.minpos.z;
                    mpNodeInfo[i].mAABB.minpos.pad_ = 0.0f;
                    mpNodeInfo[i].mAABB.maxpos.x = info[i].mAABB.maxpos.x;
                    mpNodeInfo[i].mAABB.maxpos.y = info[i].mAABB.maxpos.y;
                    mpNodeInfo[i].mAABB.maxpos.z = info[i].mAABB.maxpos.z;
                    mpNodeInfo[i].mAABB.maxpos.pad_ = 0.0f;
                }
                delete[] info;
            } else {
                mpNodeInfo = new (16u) nodeInfo[size];
            }
        }
        mNumberOfNodeInfo = size;
}

inline rNavigationMesh::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNavigationMesh::MyDTI rNavigationMesh::DTI("rNavigationMesh", &::rAIPathBase::DTI, 240ul, 0u, 0u);

MtObject* rNavigationMesh::MyDTI::newInstance() const {
    return new (16u) rNavigationMesh;
}

const MtDTI& rNavigationMesh::nodeData::getDTI() const {
    return rNavigationMesh::nodeData::DTI;
}

rNavigationMesh::nodeData::~nodeData() {
    if (mNoMemFree) {
        return;
    }
    if (mpAttribute != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::nodeData::DTI)->memFree(static_cast<void*>(mpAttribute));
    }
    if (mpCAttribute != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::nodeData::DTI)->memFree(static_cast<void*>(mpCAttribute));
    }
    if (mPolygonArea.mpVertexIndex != nullptr) {
        MtMemoryAllocator::getAllocator(rNavigationMesh::nodeData::DTI)->memFree(static_cast<void*>(mPolygonArea.mpVertexIndex));
    }
    if (mpLinkInformation == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(rNavigationMesh::nodeData::DTI)->memFree(static_cast<void*>(mpLinkInformation));
}

void rNavigationMesh::nodeData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfAttribute", &mNumberOfAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mpAttribute", reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::nodeData::getNodeAttribute), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::nodeData::setNodeAttribute), 160u, reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::nodeData::getNumberOfAttribute), reinterpret_cast<MT_MFUNC>(&::rNavigationMesh::nodeData::setNumberOfAttribute));
}

MtUI* rNavigationMesh::nodeData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

s32 rNavigationMesh::nodeData::getNodeArea(u32 index) {
    if (index < mPolygonArea.mNumberOfIndex) {
        return mPolygonArea.mpVertexIndex[index];
    } else {
        return -1;
    }
}

static auto ddon_emit_0x01b92f20 __attribute__((used)) = &rNavigationMesh::nodeData::getNodeAttribute;

static auto ddon_emit_0x01b92f30 __attribute__((used)) = &rNavigationMesh::nodeData::getNumberOfAttribute;

void rNavigationMesh::nodeData::setNodeAttribute(u32 attr, u32 index) {
    if (index < mNumberOfAttribute) {
        mpAttribute[index] = attr;
    }
}

__attribute__((weak)) void rNavigationMesh::nodeData::setNumberOfAttribute(u32 num) {
    DDON_STUB("rNavigationMesh::nodeData::setNumberOfAttribute")
    /* stub */
}

inline rNavigationMesh::nodeData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNavigationMesh::nodeData::MyDTI rNavigationMesh::nodeData::DTI("rNavigationMesh::nodeData", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* rNavigationMesh::nodeData::MyDTI::newInstance() const {
    DDON_STUB("rNavigationMesh::nodeData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rNavigationMesh::nodeInfo::getDTI() const {
    return rNavigationMesh::nodeInfo::DTI;
}

void rNavigationMesh::nodeInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mNodeOffset", &mNodeOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAABB", &mAABB, 0u, 0u);
}

MtUI* rNavigationMesh::nodeInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rNavigationMesh::nodeInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNavigationMesh::nodeInfo::MyDTI rNavigationMesh::nodeInfo::DTI("rNavigationMesh::nodeInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rNavigationMesh::nodeInfo::MyDTI::newInstance() const {
    return new (16u) rNavigationMesh::nodeInfo;
}

inline void rNavigationMesh::nodeInfo::operator delete[](void* p_addr) {
    MtMemoryAllocator::getAllocator(rNavigationMesh::nodeInfo::DTI)->memFree(p_addr);
}

inline void* rNavigationMesh::nodeInfo::operator new[](size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNavigationMesh::nodeInfo::DTI)->memAlloc(sz, align, rNavigationMesh::nodeInfo::DTI.getID());
}

