// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rGUIIconInfo.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGUIIconInfo::getDTI() const {
    return rGUIIconInfo::DTI;
}

MT_CTSTR rGUIIconInfo::getExt() const {
    return "gii";
}

rGUIIconInfo::~rGUIIconInfo() {
    MT_CHAR* t0 = mpNameBuffer;
    if (t0 != nullptr) {
        MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t0));
        mpNameBuffer = nullptr;
        nGUI::ICON_INFO* t1 = mpIconInfo;
        if (t1 != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t1));
            mpIconInfo = nullptr;
        }
    } else {
        nGUI::ICON_INFO* t1 = mpIconInfo;
        if (t1 != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t1));
            mpIconInfo = nullptr;
        }
    }
}

__attribute__((weak)) bool rGUIIconInfo::load(MtStream& in) {
    clear();
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x494947u) {
        return false;
    }
    mVersion = r.readU32();
    if (mVersion != VERSION) {
        return false;
    }
    u32 infoNum = r.readU32();
    if (infoNum == 0) {
        mpIconInfo = static_cast<nGUI::ICON_INFO*>(MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memAlloc(sizeof(nGUI::ICON_INFO), 16u));
        if (mpIconInfo == nullptr) {
            return false;
        }
        mpIconInfo->iconName = nullptr;
        mpIconInfo->code = 0;
        return true;
    }
    u32 infoSize = (infoNum + 1u) * static_cast<u32>(sizeof(nGUI::ICON_INFO));
    mpIconInfo = static_cast<nGUI::ICON_INFO*>(MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memAlloc(infoSize, 16u));
    if (mpIconInfo == nullptr) {
        return false;
    }
    u32 codeBufSize = infoNum * static_cast<u32>(sizeof(u32));
    u32* pCodeBuffer = static_cast<u32*>(MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memAlloc(codeBufSize, 16u));
    if (pCodeBuffer == nullptr) {
        if (mpIconInfo != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(mpIconInfo));
            mpIconInfo = nullptr;
        }
        return false;
    }
    r.read(pCodeBuffer, codeBufSize);
    u32 nameBufSize = r.readU32();
    if (nameBufSize == 0) {
        if (mpIconInfo != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(mpIconInfo));
            mpIconInfo = nullptr;
        }
        MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(pCodeBuffer));
        return false;
    }
    mpNameBuffer = static_cast<MT_CHAR*>(MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memAlloc(nameBufSize, 16u));
    if (mpNameBuffer == nullptr) {
        if (mpIconInfo != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(mpIconInfo));
            mpIconInfo = nullptr;
        }
        MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(pCodeBuffer));
        return false;
    }
    r.read(mpNameBuffer, nameBufSize);
    nGUI::ICON_INFO* pInfo = mpIconInfo;
    MT_CHAR* pStr = mpNameBuffer;
    for (u32 i = 0; i < infoNum; ++i) {
        pInfo[i].iconName = pStr;
        pInfo[i].code = pCodeBuffer[i];
        while (*pStr++ != '\0') {
        }
    }
    pInfo[infoNum].iconName = nullptr;
    pInfo[infoNum].code = 0;
    MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(pCodeBuffer));
    return true;
}

__attribute__((weak)) bool rGUIIconInfo::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    w.writeU32(0x494947u);
    w.writeU32(mVersion);
    u32 nameBufSize = 0;
    u32 infoNum = 0;
    nGUI::ICON_INFO* pInfo = mpIconInfo;
    if (pInfo != nullptr) {
        while (pInfo->iconName != nullptr) {
            ++infoNum;
            nameBufSize += static_cast<u32>(strlen(pInfo->iconName)) + 1u;
            ++pInfo;
        }
    }
    w.writeU32(infoNum);
    if (infoNum > 0) {
        for (pInfo = mpIconInfo; pInfo->iconName != nullptr; ++pInfo) {
            w.writeU32(pInfo->code);
        }
        w.writeU32(nameBufSize);
        w.write(mpNameBuffer, nameBufSize);
    }
    return true;
}

void rGUIIconInfo::clear() {
    MT_CHAR* t0 = mpNameBuffer;
    if (t0 != nullptr) {
        MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t0));
        mpNameBuffer = nullptr;
        nGUI::ICON_INFO* t1 = mpIconInfo;
        if (t1 != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t1));
            mpIconInfo = nullptr;
        }
    } else {
        nGUI::ICON_INFO* t1 = mpIconInfo;
        if (t1 != nullptr) {
            MtMemoryAllocator::getAllocator(rGUIIconInfo::DTI)->memFree(static_cast<void*>(t1));
            mpIconInfo = nullptr;
        }
    }
}

__attribute__((weak)) bool rGUIIconInfo::createIconInfo(nGUI::ICON_INFO* * ppIconInfo, MT_CHAR* * ppNameBuffer, MtAllocator* pAllocator) {
    DDON_STUB("rGUIIconInfo::createIconInfo")
    return {};
}

inline rGUIIconInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGUIIconInfo::MyDTI rGUIIconInfo::DTI("rGUIIconInfo", &::cResource::DTI, 136ul, 0u, 0u);

MtObject* rGUIIconInfo::MyDTI::newInstance() const {
    return new (16u) rGUIIconInfo;
}

