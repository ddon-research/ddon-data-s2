// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rVertices.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rVertices::usage() {
}

const MtDTI& rVertices::getDTI() const {
    return rVertices::DTI;
}

MT_CTSTR rVertices::getExt() const {
    return "vts";
}

bool rVertices::load(MtStream& in) {
    u32 fileSize = in.getLength();
    if (fileSize != 0) {
        u8* pTempBuff = static_cast<u8*>(MtMemory::mpAllocatorType[7]->memAlloc(fileSize, 16u));
        if (pTempBuff != nullptr) {
            u32 readSize = in.read(static_cast<void*>(pTempBuff), fileSize);
            if (fileSize == readSize) {
                if (reinterpret_cast<VTS_HEADER*>(pTempBuff)->Magic == 0x535456) {
                    if (reinterpret_cast<VTS_HEADER*>(pTempBuff)->Version == 0x20080811) {
                        mVertexNum = reinterpret_cast<VTS_HEADER*>(pTempBuff)->VertexNum;
                        u32 t0 = reinterpret_cast<VTS_HEADER*>(pTempBuff)->ParamBuffSize;
                        if (t0 != 0) {
                            if (mpParamBuff != nullptr) {
                                MtMemoryAllocator::getAllocator(rVertices::DTI)->memFree(static_cast<void*>(mpParamBuff));
                                mpParamBuff = nullptr;
                                mParamBuffSize = 0;
                                void* t1 = MtMemoryAllocator::getAllocator(rVertices::DTI)->memAlloc(t0, 16u);
                                if ((mpParamBuff = static_cast<u8*>(t1)) != nullptr) {
                                    memset(t1, 0, t0);
                                    mParamBuffSize = t0;
                                    memcpy(static_cast<void*>(mpParamBuff), static_cast<const void*>(&pTempBuff[16]), t0);
                                    MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                                    return true;
                                } else {
                                    MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                                    return false;
                                }
                            } else {
                                mParamBuffSize = 0;
                                void* t1 = MtMemoryAllocator::getAllocator(rVertices::DTI)->memAlloc(t0, 16u);
                                if ((mpParamBuff = static_cast<u8*>(t1)) != nullptr) {
                                    memset(t1, 0, t0);
                                    mParamBuffSize = t0;
                                    memcpy(static_cast<void*>(mpParamBuff), static_cast<const void*>(&pTempBuff[16]), t0);
                                    MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                                    return true;
                                } else {
                                    MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                                    return false;
                                }
                            }
                        } else {
                            MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                            return false;
                        }
                    } else {
                        MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                        return false;
                    }
                } else {
                    MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                    return false;
                }
            } else {
                MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool rVertices::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    if (mpParamBuff != nullptr) {
        u32 t0 = mParamBuffSize;
        u8* pTempBuff = static_cast<u8*>(MtMemory::mpAllocatorType[7]->memAlloc(t0 + 16u, 16u));
        if (pTempBuff != nullptr) {
            reinterpret_cast<VTS_HEADER*>(pTempBuff)->Magic = 0x535456;
            reinterpret_cast<VTS_HEADER*>(pTempBuff)->Version = 0x20080811;
            u32 t1 = mParamBuffSize;
            reinterpret_cast<VTS_HEADER*>(pTempBuff)->ParamBuffSize = t1;
            reinterpret_cast<VTS_HEADER*>(pTempBuff)->VertexNum = mVertexNum;
            memcpy(static_cast<void*>(&pTempBuff[16]), static_cast<const void*>(mpParamBuff), t1);
            u32 writeSize = out.write(static_cast<const void*>(pTempBuff), t0 + 16u);
            MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(pTempBuff));
            return writeSize == (t0 + 16u);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void rVertices::clear() {
    if (mpParamBuff != nullptr) {
        MtMemoryAllocator::getAllocator(rVertices::DTI)->memFree(static_cast<void*>(mpParamBuff));
        mpParamBuff = nullptr;
    }
    mParamBuffSize = 0;
    mVertexNum = 0;
    mpParamBuff = nullptr;
    mAttr = 22;
}

void rVertices::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mResourceSize", reinterpret_cast<MT_MFUNC>(&::rVertices::getResourceSize), reinterpret_cast<MT_MFUNC>(&::rVertices::setDummyU32), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mVertexNum", reinterpret_cast<MT_MFUNC>(&::rVertices::getVertexNum), reinterpret_cast<MT_MFUNC>(&::rVertices::setDummyU32), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* rVertices::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

static auto ddon_emit_0x01b95760 __attribute__((used)) = &rVertices::getVertexNum;

static auto ddon_emit_0x01b95740 __attribute__((used)) = &rVertices::getResourceSize;

__attribute__((weak)) void rVertices::setDummyU32(u32) {
}

rVertices::~rVertices() {
    if (mpParamBuff != nullptr) {
        MtMemoryAllocator::getAllocator(rVertices::DTI)->memFree(static_cast<void*>(mpParamBuff));
        mpParamBuff = nullptr;
    }
    mParamBuffSize = 0;
}

inline rVertices::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rVertices::MyDTI rVertices::DTI("rVertices", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rVertices::MyDTI::newInstance() const {
    return new (16u) rVertices;
}

