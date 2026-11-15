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

inline void* rGUIMessage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rGUIMessage::DTI)->memAlloc(sz, align, rGUIMessage::DTI.mID);
}

inline void rGUIMessage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUIMessage::DTI)->memFree(p_addr);
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

bool rGUIMessage::load(MtStream& in) {
    clear();
    MtDataReader r(in, 4096u);
    bool b6_13;
    if (r.MtDataReader::readU32() != 0x444D47) {
        b6_13 = false;
        return b6_13;
    }
    u32 t5 = r.MtDataReader::readU32();
    mVersion = t5;
    if (mVersion != 0x10302) {
        b6_13 = false;
        return b6_13;
    }
    u32 t7 = r.MtDataReader::readU32();
    mLanguageId = t7;
    u64 t9 = r.MtDataReader::readU64();
    mUpdateTime = static_cast<t64>(t9);
    u32 t11 = r.MtDataReader::readU32();
    mIndexNum = t11;
    u32 t13 = r.MtDataReader::readU32();
    mMessageNum = t13;
    u32 t15 = r.MtDataReader::readU32();
    mIndexNameBufferSize = t15;
    u32 t17 = r.MtDataReader::readU32();
    mBufferSize = t17;
    u32 length = r.MtDataReader::readU32();
    u32 t20 = mIndexNum;
    u32 t21 = mMessageNum;
    u32 t22 = mBufferSize;
    u32 t23 = mIndexNameBufferSize;
    unsigned long t24 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0);
    const u32 PackageNameSize = length + 1u;
    const u32 spill4208 = (((t20 * 32u) + (t21 * 8u)) + length) + 1u;
    INDEX* pIndexBuffer = static_cast<INDEX*>(memAlloc((((((t20 * 32u) + (t21 * 8u)) + t22) + t23) + length) + 1u));
    u8* pBuffer = reinterpret_cast<u8*>(pIndexBuffer);
    u32 t26 = mIndexNameBufferSize;
    mPackageName = reinterpret_cast<MT_CTSTR>(&pBuffer[(t20 * 32u) + (t21 * 8u)]);
    const u32 t27 = PackageNameSize;
    r.MtDataReader::read(static_cast<void*>(&pBuffer[(t20 * 32u) + (t21 * 8u)]), t27);
    u32 t29 = mIndexNum;
    mpIndex = pIndexBuffer;
    if (t29 != 0) {
        r.MtDataReader::read(static_cast<void*>(pIndexBuffer), t29 * 32u);
        r.MtDataReader::read(static_cast<void*>(&mpHashTable[0]), 2048u);
        if (mIndexNameBufferSize != 0) {
            mIndexNameBuffer = reinterpret_cast<MT_CTSTR>(&pBuffer[spill4208]);
            r.MtDataReader::read(static_cast<void*>(&pBuffer[spill4208]), mIndexNameBufferSize);
        } else {
            mIndexNameBuffer = nullptr;
        }
    } else {
        u32 t32 = mIndexNameBufferSize;
        if (t32 != 0) {
            mIndexNameBuffer = reinterpret_cast<MT_CTSTR>(&pBuffer[spill4208]);
            r.MtDataReader::read(static_cast<void*>(&pBuffer[spill4208]), t32);
        } else {
            mIndexNameBuffer = nullptr;
        }
    }
    mBufferTop = reinterpret_cast<MT_STR>(&pBuffer[((((t20 * 32u) + (t21 * 8u)) + t26) + length) + 1u]);
    u32 t35 = mBufferSize;
    r.MtDataReader::read(static_cast<void*>(&pBuffer[((((t20 * 32u) + (t21 * 8u)) + t26) + length) + 1u]), t35);
    u32 v0_5 = mIndexNum;
    const u32 IndexSize = t20 * 32u;
    char* v5_9;
    char* v5_12;
    if (v0_5 == 0) {
        v5_9 = reinterpret_cast<char*>(&pBuffer[t20 * 32u]);
        v5_12 = reinterpret_cast<char*>(&pBuffer[((((t20 * 32u) + (t21 * 8u)) + t26) + length) + 1u]);
    } else {
        INDEX* pIndex = mpIndex;
        MT_CTSTR v0_2 = mIndexNameBuffer;
        INDEX* p0_1 = pIndex;
        unsigned int i0_3 = 0;
        char* v0_9 = reinterpret_cast<char*>(&pBuffer[t20 * 32u]);
        char* v0_12 = reinterpret_cast<char*>(&pBuffer[((((t20 * 32u) + (t21 * 8u)) + t26) + length) + 1u]);
        for (;;) {
            unsigned long t36 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(p0_1) + 16);
            p0_1->pName = &v0_2[t36];
            unsigned long t37 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(p0_1) + 24);
            if (t37 != 0) {
                INDEX* t38 = mpIndex;
                if (t37 != 0xFFFFFFFFFFFFFFFFul) {
                    p0_1->pLink = &t38[t37];
                } else {
                    p0_1->pLink = t38;
                }
            } else {
                p0_1->pLink = nullptr;
            }
            if ((i0_3 + 1u) < v0_5) {
                p0_1 += 1;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        for (unsigned int i3_0 = 0;;) {
            if (mpHashTable[i3_0].offset != 0) {
                INDEX* t40 = mpIndex;
                if (mpHashTable[i3_0].offset != 0xFFFFFFFFFFFFFFFFul) {
                    mpHashTable[i3_0].pIndex = &t40[mpHashTable[i3_0].offset];
                } else {
                    mpHashTable[i3_0].pIndex = t40;
                }
            }
            if ((i3_0 + 1u) != 256) {
                i3_0 = i3_0 + 1u;
            } else {
                v5_9 = v0_9;
                v5_12 = v0_12;
                break;
            }
        }
    }
    mpMessage = reinterpret_cast<MT_STR*>(v5_9);
    u32 v6_10 = mMessageNum;
    if (v6_10 == 0) {
        b6_13 = true;
    } else {
        MT_STR str = mBufferTop;
        unsigned int i6_3 = 0;
        MT_STR* pMessage = reinterpret_cast<MT_STR*>(&pBuffer[IndexSize]);
        b6_13 = true;
        for (;;) {
            pMessage[i6_3] = str;
            str = &str[static_cast<unsigned int>(strlen(str) + 1ul)];
            if ((i6_3 + 1u) < v6_10) {
                i6_3 = i6_3 + 1u;
            } else {
                break;
            }
        }
    }
    return b6_13;
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

