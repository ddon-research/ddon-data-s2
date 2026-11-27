// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sFile.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sFile::getDTI() const {
    return sFile::DTI;
}

void* sFile::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sFile::DTI)->memAlloc(sz, align, sFile::DTI.mID);
}

sFile::sFile(MT_CTSTR titlecode) {
    DDON_STUB("sFile::sFile")
    /* stub */
}

__attribute__((noinline)) sFile::~sFile() {
    DDON_STUB("sFile::~sFile")
    /* stub */
}

__attribute__((weak)) bool sFile::mountTemp() {
    DDON_STUB("sFile::mountTemp")
    return {};
}

__attribute__((weak)) void sFile::formatDownload() {
    DDON_STUB("sFile::formatDownload")
    /* stub */
}

__attribute__((weak)) void sFile::getDriveType(MT_CTSTR path, MtFile::DRIVETYPE& dst_dtype, u32& dst_srcprefixoffset, MT_STR dest_nativemountprefix) {
    DDON_STUB("sFile::getDriveType")
    /* stub */
}

void sFile::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Export Logs", static_cast<MT_MFUNC>(&::sFile::exportLogs), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Format /download0", static_cast<MT_MFUNC>(&::sFile::formatDownload), 10u);
}

__attribute__((weak)) void sFile::exportLogs() {
}

__attribute__((weak)) bool sFile::isDownloadFile(MT_CTSTR path) {
    DDON_STUB("sFile::isDownloadFile")
    return {};
}

inline sFile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sFile::MyDTI sFile::DTI("sFile", &::cSystem::DTI, 128ul, 0u, 0u);

sFile* sFile::mpInstance;

__attribute__((weak)) MtObject* sFile::MyDTI::newInstance() const {
    DDON_STUB("sFile::MyDTI::newInstance")
    return nullptr;
}

sFile::RealPath::RealPath(MT_CTSTR path) {
    DDON_STUB("sFile::RealPath::RealPath")
    /* stub */
}

