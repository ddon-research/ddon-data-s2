// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMagicCommand.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMagicCommand::getDTI() const {
    return cMagicCommand::DTI;
}

inline void* cMagicCommand::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cMagicCommand::DTI)->memAlloc(sz, align, cMagicCommand::DTI.getID());
}

inline void cMagicCommand::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cMagicCommand::DTI)->memFree(p_addr);
}

cMagicCommand::~cMagicCommand() {
}

__attribute__((weak)) void cMagicCommand::createProperty(MtPropertyList& proplist) {
    DDON_STUB("cMagicCommand::createProperty")
    /* stub */
}

inline bool cMagicCommand::importBinary(MtDataReader& reader) {
    nDDOIO::readData(reader, mDegree);
    return true;
}

inline bool cMagicCommand::exportBinary(MtDataWriter& writer) {
    nDDOIO::writeData(writer, mDegree);
    return true;
}

inline cMagicCommand::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMagicCommand::MyDTI cMagicCommand::DTI("cMagicCommand", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cMagicCommand::MyDTI::newInstance() const {
    return new (16u) cMagicCommand;
}

const MtDTI& cMagicCommandList::getDTI() const {
    return cMagicCommandList::DTI;
}

inline void cMagicCommandList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cMagicCommandList::DTI)->memFree(p_addr);
}

cMagicCommandList::~cMagicCommandList() {
    clear();
}

__attribute__((weak)) void cMagicCommandList::createProperty(MtPropertyList& proplist) {
}

void cMagicCommandList::clear() {
    if (mMagicCommandListEasy.mLength != 0) {
        u32 v0_0 = mMagicCommandListEasy.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMagicCommandListEasy.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMagicCommandListEasy.mpArray[i0_3];
                v1_0 = mMagicCommandListEasy.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMagicCommandListEasy.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMagicCommandListEasy.mpArray));
    }
    mMagicCommandListEasy.mpArray = nullptr;
    mMagicCommandListEasy.mBufsiz = 0;
    mMagicCommandListEasy.mLength = 0;
    if (mMagicCommandListNormal.mLength != 0) {
        u32 v3_0 = mMagicCommandListNormal.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mMagicCommandListNormal.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mMagicCommandListNormal.mpArray[i3_3];
                v4_0 = mMagicCommandListNormal.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMagicCommandListNormal.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMagicCommandListNormal.mpArray));
    }
    mMagicCommandListNormal.mpArray = nullptr;
    mMagicCommandListNormal.mBufsiz = 0;
    mMagicCommandListNormal.mLength = 0;
    if (mMagicCommandListHard.mLength != 0) {
        u32 v6_0 = mMagicCommandListHard.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mMagicCommandListHard.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mMagicCommandListHard.mpArray[i6_3];
                v7_0 = mMagicCommandListHard.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMagicCommandListHard.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMagicCommandListHard.mpArray));
    }
    mMagicCommandListHard.mpArray = nullptr;
    mMagicCommandListHard.mBufsiz = 0;
    mMagicCommandListHard.mLength = 0;
}

__attribute__((weak)) bool cMagicCommandList::importBinary(MtDataReader& reader) {
    mMagicCommandListEasy.deleteAll(true);
    mMagicCommandListNormal.deleteAll(true);
    mMagicCommandListHard.deleteAll(true);
    
    u32 size1;
    nDDOIO::readData(reader, size1);
    mMagicCommandListEasy.reserve(size1);
    for (u32 i = 0; i < size1; i++) {
        cMagicCommand* param = new (16u) cMagicCommand;
        if (param != nullptr) {
            param->importBinary(reader);
            mMagicCommandListEasy.add(param);
        }
    }
    
    u32 size2;
    nDDOIO::readData(reader, size2);
    mMagicCommandListNormal.reserve(size2);
    for (u32 i = 0; i < size2; i++) {
        cMagicCommand* param = new (16u) cMagicCommand;
        if (param != nullptr) {
            param->importBinary(reader);
            mMagicCommandListNormal.add(param);
        }
    }
    
    u32 size3;
    nDDOIO::readData(reader, size3);
    mMagicCommandListHard.reserve(size3);
    for (u32 i = 0; i < size3; i++) {
        cMagicCommand* param = new (16u) cMagicCommand;
        if (param != nullptr) {
            param->importBinary(reader);
            mMagicCommandListHard.add(param);
        }
    }
    
    return true;
}

__attribute__((weak)) bool cMagicCommandList::exportBinary(MtDataWriter& writer) {
    u32 size1 = mMagicCommandListEasy.size();
    nDDOIO::writeData(writer, size1);
    for (u32 i = 0; i < size1; i++) {
        cMagicCommand* param = mMagicCommandListEasy[i];
        if (param != nullptr) {
            param->exportBinary(writer);
        }
    }
    
    u32 size2 = mMagicCommandListNormal.size();
    nDDOIO::writeData(writer, size2);
    for (u32 i = 0; i < size2; i++) {
        cMagicCommand* param = mMagicCommandListNormal[i];
        if (param != nullptr) {
            param->exportBinary(writer);
        }
    }
    
    u32 size3 = mMagicCommandListHard.size();
    nDDOIO::writeData(writer, size3);
    for (u32 i = 0; i < size3; i++) {
        cMagicCommand* param = mMagicCommandListHard[i];
        if (param != nullptr) {
            param->exportBinary(writer);
        }
    }
    
    return true;
}

inline cMagicCommandList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMagicCommandList::MyDTI cMagicCommandList::DTI("cMagicCommandList", &::MtObject::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* cMagicCommandList::MyDTI::newInstance() const {
    return new (16u) cMagicCommandList;
}

const MtDTI& rMagicCommandList::getDTI() const {
    return rMagicCommandList::DTI;
}

inline void* rMagicCommandList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rMagicCommandList::DTI)->memAlloc(sz, align, rMagicCommandList::DTI.getID());
}

inline void rMagicCommandList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMagicCommandList::DTI)->memFree(p_addr);
}

inline rMagicCommandList::rMagicCommandList() {
    setAttribute(18u);
    mMagicCommandList.mAutoDelete = true;
}

rMagicCommandList::~rMagicCommandList() {
    if (mMagicCommandList.mLength != 0) {
        u32 v0_0 = mMagicCommandList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMagicCommandList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMagicCommandList.mpArray[i0_3];
                v1_0 = mMagicCommandList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMagicCommandList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMagicCommandList.mpArray));
    }
    mMagicCommandList.mpArray = nullptr;
    mMagicCommandList.mBufsiz = 0;
    mMagicCommandList.mLength = 0;
}

__attribute__((weak)) void rMagicCommandList::createProperty(MtPropertyList& proplist) {
    DDON_STUB("rMagicCommandList::createProperty")
    /* stub */
}

__attribute__((weak)) bool rMagicCommandList::load(MtStream& in) {
    MtDataReader reader(in, 4096u);
    u32 size1;
    nDDOIO::readData(reader, size1);
    mMagicCommandList.deleteAll(true);
    mMagicCommandList.reserve(size1);
    for (u32 i = 0; i < size1; i++) {
        cMagicCommandList* pData = new (16u) cMagicCommandList;
        if (pData != nullptr) {
            pData->importBinary(reader);
            mMagicCommandList.add(pData);
        }
    }
    return true;
}

bool rMagicCommandList::save(MtStream& out) {
    MtDataWriter writer(out, 4096u, 4096u);
    u32 size1 = mMagicCommandList.size();
    (&writer)->writeU32(size1);
    if (size1 != 0) {
        for (unsigned int i0_3 = 0;;) {
            static_cast<cMagicCommandList*>(mMagicCommandList.getBuffer()[static_cast<int>(i0_3)])->exportBinary(writer);
            if (size1 != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

MT_CTSTR rMagicCommandList::getExt() const {
    return "mgcc";
}

void rMagicCommandList::clear() {
    if (mMagicCommandList.mLength != 0) {
        u32 v0_0 = mMagicCommandList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMagicCommandList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMagicCommandList.mpArray[i0_3];
                v1_0 = mMagicCommandList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMagicCommandList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMagicCommandList.mpArray));
    }
    mMagicCommandList.mpArray = nullptr;
    mMagicCommandList.mBufsiz = 0;
    mMagicCommandList.mLength = 0;
}

cMagicCommandList* rMagicCommandList::getMagicCommandList(u32 tblIndex) const {
    if (tblIndex < mMagicCommandList.mLength) {
        return static_cast<cMagicCommandList*>(mMagicCommandList.mpArray[tblIndex]);
    } else {
        return nullptr;
    }
}

inline rMagicCommandList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMagicCommandList::MyDTI rMagicCommandList::DTI("rMagicCommandList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rMagicCommandList::MyDTI::newInstance() const {
    return new (16u) rMagicCommandList;
}

template MtTypedArray<cMagicCommand>::~MtTypedArray();

template MtTypedArray<cMagicCommandList>::~MtTypedArray();

