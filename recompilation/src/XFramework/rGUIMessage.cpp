// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rGUIMessage.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCRC.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGUIMessage::getDTI() const {
    return rGUIMessage::DTI;
}

inline rGUIMessage::rGUIMessage() {
    mVersion = 0x10302;
    mLanguageId = 0xFFFFFFFF;
    mUpdateTime = 0;
    mIndexNum = 0;
    mpIndex = nullptr;
    mIndexNameBufferSize = 0;
    mIndexNameBuffer = nullptr;
    mMessageNum = 0;
    mPackageName = nullptr;
    mBufferSize = 0;
    mpMessage = nullptr;
    mBufferTop = nullptr;
    mAttr = 16;
    memset(static_cast<void*>(&mpHashTable[0]), 0, 2048ul);
}

rGUIMessage::~rGUIMessage() {
    this->rGUIMessage::clear();
}

__attribute__((weak)) bool rGUIMessage::load(MtStream& in) {
        clear();
        MtDataReader r(in, 4096u);
        if (r.readU32() != 0x444D47) {
            return false;
        }
        mVersion = r.readU32();
        if (mVersion != 0x10302) {
            return false;
        }
        mLanguageId = r.readU32();
        mUpdateTime = r.readU64();
        mIndexNum = r.readU32();
        mMessageNum = r.readU32();
        mIndexNameBufferSize = r.readU32();
        mBufferSize = r.readU32();
        u32 length = r.readU32();
        const u32 PackageNameSize = length + 1;
        const u32 IndexSize = sizeof(INDEX) * mIndexNum;
        const u32 MessageTblSize = sizeof(MT_STR) * mMessageNum;
        const u32 TotalAllocSize = IndexSize + MessageTblSize + PackageNameSize + mIndexNameBufferSize + mBufferSize;
        u8* pBuffer = static_cast<u8*>(memAlloc(TotalAllocSize));
        u32 NowPos = 0;
        INDEX* pIndexBuffer = reinterpret_cast<INDEX*>(pBuffer);
        NowPos += IndexSize;
        MT_STR* pMessageTable = reinterpret_cast<MT_STR*>(pBuffer + NowPos);
        NowPos += MessageTblSize;
        MT_STR pPackageName = reinterpret_cast<MT_STR>(pBuffer + NowPos);
        NowPos += PackageNameSize;
        MT_STR pIndexName = reinterpret_cast<MT_STR>(pBuffer + NowPos);
        NowPos += mIndexNameBufferSize;
        MT_STR pBufferTop = reinterpret_cast<MT_STR>(pBuffer + NowPos);
        mPackageName = pPackageName;
        r.read(pPackageName, PackageNameSize);
        mpIndex = pIndexBuffer;
        if (mIndexNum != 0) {
            r.read(pIndexBuffer, sizeof(INDEX) * mIndexNum);
            r.read(mpHashTable, sizeof(mpHashTable));
        }
        if (mIndexNameBufferSize != 0) {
            mIndexNameBuffer = pIndexName;
            r.read(pIndexName, mIndexNameBufferSize);
        } else {
            mIndexNameBuffer = nullptr;
        }
        mBufferTop = pBufferTop;
        r.read(pBufferTop, mBufferSize);
        if (mIndexNum != 0) {
            for (u32 i = 0; i < mIndexNum; i++) {
                INDEX* pIndex = &mpIndex[i];
                pIndex->pName = mIndexNameBuffer + pIndex->offset;
                if (pIndex->linkOffst != 0) {
                    INDEX* pTop = mpIndex;
                    if (pIndex->linkOffst != static_cast<size_t>(-1)) {
                        pTop += pIndex->linkOffst;
                    }
                    pIndex->pLink = pTop;
                } else {
                    pIndex->pLink = nullptr;
                }
            }
            for (u32 i = 0; i < 256; i++) {
                if (mpHashTable[i].offset != 0) {
                    INDEX* pTop = mpIndex;
                    if (mpHashTable[i].offset != static_cast<size_t>(-1)) {
                        pTop += mpHashTable[i].offset;
                    }
                    mpHashTable[i].pIndex = pTop;
                }
            }
        }
        mpMessage = pMessageTable;
        MT_STR str = mBufferTop;
        for (u32 i = 0; i < mMessageNum; i++) {
            pMessageTable[i] = str;
            str += static_cast<u32>(strlen(str) + 1);
        }
        return true;
}

bool rGUIMessage::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.MtDataWriter::writeU32(0x444D47u);
    w.MtDataWriter::writeU32(mVersion);
    w.MtDataWriter::writeU32(mLanguageId);
    w.MtDataWriter::writeU64(static_cast<u64>(mUpdateTime));
    w.MtDataWriter::writeU32(mIndexNum);
    w.MtDataWriter::writeU32(mMessageNum);
    w.MtDataWriter::writeU32(mIndexNameBufferSize);
    w.MtDataWriter::writeU32(mBufferSize);
    w.MtDataWriter::writeU32(static_cast<unsigned int>(strlen(mPackageName)));
    w.writeString(mPackageName);
    if (mIndexNum != 0) {
        INDEX* v0_9 = static_cast<INDEX*>(memAlloc(mIndexNum * 32u));
        u32 v3_2;
        if (mIndexNum != 0) {
            unsigned int i0_0 = 0;
            INDEX* v0_3 = mpIndex;
            INDEX* v0_4 = v0_9;
            u32 v2_2;
            for (;;) {
                v0_4->index = v0_3[i0_0].index;
                v0_4->isSameHashDiffName = mpIndex[i0_0].isSameHashDiffName;
                INDEX* v1_2 = mpIndex;
                v0_4->hashA = v1_2[i0_0].hashA;
                v0_4->hashB = v1_2[i0_0].hashB;
                v0_4->offset = static_cast<size_t>(v1_2[i0_0].pName - mIndexNameBuffer);
                if (v1_2[i0_0].pLink != nullptr) {
                    if ((v1_2[i0_0].pLink - v1_2) != 0) {
                        v0_4->linkOffst = static_cast<size_t>(v1_2[i0_0].pLink - v1_2);
                    } else {
                        v0_4->linkOffst = 0xFFFFFFFFFFFFFFFFul;
                    }
                } else {
                    v0_4->linkOffst = 0;
                }
                v2_2 = mIndexNum;
                if ((i0_0 + 1u) < v2_2) {
                    i0_0 += 1u;
                    v0_3 = v1_2;
                    v0_4 += 1;
                } else {
                    break;
                }
            }
            v3_2 = v2_2 * 32u;
        } else {
            v3_2 = 0;
        }
        w.MtDataWriter::write(static_cast<const void*>(v0_9), v3_2);
        memFree(static_cast<void*>(v0_9));
        HASH_TABLE_NODE* pNodeTop = static_cast<HASH_TABLE_NODE*>(memAlloc(2048u));
        for (unsigned int i4_0 = 0; i4_0 != 256; i4_0 = i4_0 + 1u) {
            if (mpHashTable[i4_0].pIndex != nullptr) {
                if ((mpHashTable[i4_0].pIndex - mpIndex) != 0) {
                    pNodeTop[i4_0].offset = static_cast<size_t>(mpHashTable[i4_0].pIndex - mpIndex);
                } else {
                    pNodeTop[i4_0].offset = 0xFFFFFFFFFFFFFFFFul;
                }
            } else {
                pNodeTop[i4_0].offset = 0;
            }
        }
        w.MtDataWriter::write(static_cast<const void*>(pNodeTop), 2048u);
        memFree(static_cast<void*>(pNodeTop));
    }
    if (mIndexNameBufferSize != 0) {
        w.MtDataWriter::write(static_cast<const void*>(mIndexNameBuffer), mIndexNameBufferSize);
    }
    if (mBufferSize != 0) {
        w.MtDataWriter::write(static_cast<const void*>(mBufferTop), mBufferSize);
    }
    return true;
}

__attribute__((weak)) void rGUIMessage::clear() {
    this->cResource::clear();
    mLanguageId = 0xFFFFFFFF;
    mUpdateTime = 0;
    mMessageNum = 0;
    u32 t0 = mIndexNum;
    INDEX* t1 = mpIndex;
    MT_STR* t2 = mpMessage;
    memFree(static_cast<void*>(t1));
    mpIndex = nullptr;
    mIndexNameBufferSize = 0;
    if (static_cast<const void*>(t2) != static_cast<const void*>(&t1[t0])) {
        memFree(const_cast<char*>(mIndexNameBuffer));
        mIndexNameBuffer = nullptr;
        memFree(const_cast<char*>(mPackageName));
        mPackageName = nullptr;
        memFree(static_cast<void*>(mBufferTop));
        mBufferSize = 0;
        mBufferTop = nullptr;
        memFree(static_cast<void*>(mpMessage));
    } else {
        mIndexNameBuffer = nullptr;
        mPackageName = nullptr;
        mBufferSize = 0;
        mBufferTop = nullptr;
    }
    mIndexNum = 0;
    memset(static_cast<void*>(&mpMessage), 0, 2056ul);
}

MtUI* rGUIMessage::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rGUIMessage::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

MT_CTSTR rGUIMessage::getExt() const {
    return "gmd";
}

const rGUIMessage::INDEX* rGUIMessage::getIndex(u32 index) const {
    if (index < mIndexNum) {
        return &mpIndex[index];
    } else {
        return nullptr;
    }
}

const rGUIMessage::INDEX* rGUIMessage::getIndex(MT_CTSTR name) const {
    return static_cast<const rGUIMessage*>(this)->searchINDEXFromHashTable(name, 0u);
}

u32 rGUIMessage::getIndexFromName(MT_CTSTR name) const {
    const INDEX* pIndex = searchINDEXFromHashTable(name, 0u);
    if (pIndex != nullptr) {
        return pIndex->index;
    } else {
        return 0xFFFFFFFF;
    }
}

MT_CTSTR rGUIMessage::getMessage(u32 index) const {
    if (index < mMessageNum) {
        return mpMessage[index];
    } else {
        return "";
    }
}

void* rGUIMessage::memAlloc(u32 size) {
    return MtMemoryAllocator::getAllocator(rGUIMessage::DTI)->memAlloc(size, 16u);
}

void rGUIMessage::memFree(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUIMessage::DTI)->memFree(p_addr);
}

__attribute__((weak)) const rGUIMessage::INDEX* rGUIMessage::searchINDEXFromHashTable(MT_CTSTR name, u32 hashMode) const {
    DDON_STUB("rGUIMessage::searchINDEXFromHashTable")
    return nullptr;
}

inline rGUIMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGUIMessage::MyDTI rGUIMessage::DTI("rGUIMessage", &::cResource::DTI, 2248ul, 0u, 0u);

MtObject* rGUIMessage::MyDTI::newInstance() const {
    return new (16u) rGUIMessage;
}

