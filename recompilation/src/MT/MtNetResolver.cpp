// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtNetResolver.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtNetResolver::MtNetResolver(const MT_CTSTR name) {
    if (name != nullptr) {
        strncpy(&mName[0], name, 512ul);
        mName[511] = '\0';
    } else {
        memset(static_cast<void*>(&mName[0]), 0, 512ul);
    }
    mAddressNum = 0;
    mAddress[2].mData[0] = 0;
    mAddress[2].mData[1] = 0;
    mAddress[2].mData[2] = 0;
    mAddress[2].mData[3] = 0;
    mAddress[3].mData[0] = 0;
    mAddress[3].mData[1] = 0;
    mAddress[3].mData[2] = 0;
    mAddress[3].mData[3] = 0;
    mAddress[0].mData[0] = 0;
    mAddress[0].mData[1] = 0;
    mAddress[0].mData[2] = 0;
    mAddress[0].mData[3] = 0;
    mAddress[1].mData[0] = 0;
    mAddress[1].mData[1] = 0;
    mAddress[1].mData[2] = 0;
    mAddress[1].mData[3] = 0;
}

MtNetResolver::~MtNetResolver() {
    DDON_STUB("MtNetResolver::~MtNetResolver")
    /* stub */
}

void MtNetResolver::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
}

__attribute__((weak)) s32 MtNetResolver::check() {
    DDON_STUB("MtNetResolver::check")
    return {};
}

__attribute__((weak)) void MtNetResolver::get(s32 index, MtNetIpAddress* address) {
    DDON_STUB("MtNetResolver::get")
    /* stub */
}

