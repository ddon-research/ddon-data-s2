// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rArchiveListArray.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCRC.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"

#include "../../MT/MtStream.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListTag.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rArchiveListArray::getDTI() const {
    return rArchiveListArray::DTI;
}

inline void* rArchiveListArray::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rArchiveListArray::DTI)->memAlloc(sz, align, rArchiveListArray::DTI.getID());
}

inline void rArchiveListArray::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rArchiveListArray::DTI)->memFree(p_addr);
}

inline rArchiveListArray::rArchiveListArray() {
    setAttribute(16u);
    mpDbgResDat = nullptr;
    mpHeader = nullptr;
}

rArchiveListArray::~rArchiveListArray() {
    if (mpHeader == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(rArchiveListArray::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

MT_CTSTR rArchiveListArray::getExt() const {
    return "ala";
}

__attribute__((weak)) bool rArchiveListArray::load(MtStream& in) {
    u32 len = in.getLength();
    allocMem(len);
    stHeader* p_header = mpHeader;
    if (p_header == nullptr) {
        return false;
    }
    if (len < HEADER_SIZE) {
        return false;
    }
    in.read(p_header, HEADER_SIZE);
    if (p_header->Version != DATA_VERSION) {
        freeMem();
        return false;
    }
    in.read(p_header->Tag, len - HEADER_SIZE);
    u32 tag_num = p_header->TagNum;
    for (u32 tag_idx = 0; tag_idx < tag_num; ++tag_idx) {
        cArchiveListTag& tag = p_header->Tag[tag_idx];
        tag.mpNodeArray = reinterpret_cast<cArchiveListNode*>(reinterpret_cast<u8*>(p_header) + reinterpret_cast<size_t>(tag.mpNodeArray));
        tag.mpArcPath = reinterpret_cast<MT_CHAR*>(p_header) + reinterpret_cast<size_t>(tag.mpArcPath);
        u32 node_num = tag.mNodeNum;
        for (u32 node_idx = 0; node_idx < node_num; ++node_idx) {
            cArchiveListNode& node = tag.mpNodeArray[node_idx];
            node.mpDbgResData = nullptr;
        }
    }
    return true;
}

__attribute__((weak)) cArchiveListTag* rArchiveListArray::searchListTag(u32 tagId) {
    DDON_STUB("rArchiveListArray::searchListTag")
    return nullptr;
}

__attribute__((weak)) cArchiveListNode* rArchiveListArray::searchListNode(u32 tagId, u32 searchId) {
    DDON_STUB("rArchiveListArray::searchListNode")
    return nullptr;
}

ARC_SEARCHID rArchiveListArray::convSearchId(MT_CTSTR name) {
    return MtCRC::getCRC(name, 0xFFFFFFFFu);
}

ARC_TAGID rArchiveListArray::convTagId(MT_CTSTR name) {
    if ((*name) != 0) {
        return MtCRC::getCRC(name, 0xFFFFFFFFu);
    } else {
        return 0;
    }
}

u32 rArchiveListArray::convTargetTagtNo(u32 tagId) {
    return tagId & 127u;
}

inline rArchiveListArray::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rArchiveListArray::MyDTI rArchiveListArray::DTI("rArchiveListArray", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rArchiveListArray::MyDTI::newInstance() const {
    return new (16u) rArchiveListArray;
}

