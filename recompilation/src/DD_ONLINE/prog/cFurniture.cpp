// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cFurniture.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cNetGameServer.h"
#include "cOmControl.h"
#include "../../XFramework/cResource.h"
#include "rFurnitureData.h"
#include "rFurnitureItem.h"
#include "../../XFramework/sArea.h"
#include "sMyRoom.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sOmManager.h"
#include "uStageMyRoom.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFurniture::getDTI() const {
    return cFurniture::DTI;
}

void* cFurniture::operator new(size_t sz, u32 align) {
    return cFurniture::getAllocator()->memAlloc(sz, align, cFurniture::DTI.getID());
}

cFurniture::cFurniture() {
    DDON_STUB("cFurniture::cFurniture")
    /* stub */
}

cFurniture::~cFurniture() {
    release();
    if (mpFurnitureData != nullptr) {
        mpFurnitureData->release();
        mpFurnitureData = nullptr;
    }
    if (mpFurnitureItem != nullptr) {
        mpFurnitureItem->release();
        mpFurnitureItem = nullptr;
    }
    if (mpFurnitureLayout == nullptr) {
        return;
    }
    mpFurnitureLayout->release();
    mpFurnitureLayout = nullptr;
}

__attribute__((weak)) void cFurniture::init() {
    DDON_STUB("cFurniture::init")
    /* stub */
}

__attribute__((weak)) void cFurniture::move() {
    DDON_STUB("cFurniture::move")
    /* stub */
}

__attribute__((weak)) bool cFurniture::setFurnitureLayout(const MtTypedArray<CDataFurnitureLayout>& list) {
    DDON_STUB("cFurniture::setFurnitureLayout")
    return {};
}

__attribute__((weak)) bool cFurniture::changeFurniture(u32 item_id, bool onoff) {
    DDON_STUB("cFurniture::changeFurniture")
    return {};
}

__attribute__((weak)) bool cFurniture::sendFurniture() {
    DDON_STUB("cFurniture::sendFurniture")
    return {};
}

__attribute__((weak)) void cFurniture::updateFurniture() {
    DDON_STUB("cFurniture::updateFurniture")
    /* stub */
}

__attribute__((weak)) bool cFurniture::resetFurniture() {
    DDON_STUB("cFurniture::resetFurniture")
    return {};
}

__attribute__((weak)) void cFurniture::copyInfo(MtTypedArray<cFurniture::Info>& src, MtTypedArray<cFurniture::Info>& dst) {
    DDON_STUB("cFurniture::copyInfo")
    /* stub */
}

bool cFurniture::isSetOm(u32 om_id) {
    if (mInfoDisp.mLength != 0) {
        u32 i = 0;
        do {
            if (mInfoDisp.getBuffer()[static_cast<int>(i)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mInfoDisp.getBuffer()[static_cast<int>(i)]) + 16)) == om_id) {
                    return (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mInfoDisp.getBuffer()[static_cast<int>(i)]) + 9)) != 0;
                }
            }
            i += 1u;
        } while (i < mInfoDisp.mLength);
    }
    return false;
}

void cFurniture::setRoomWear() {
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isLogin()) {
        return;
    }
    sMyRoom::getInstance()->clearWearInfo();
    if (mInfoMaster.mLength == 0) {
        return;
    }
    u32 i = 0;
    do {
        if (mInfoMaster.getBuffer()[static_cast<int>(i)] != nullptr) {
            if (static_cast<Info*>(mInfoMaster.getBuffer()[static_cast<int>(i)])->mItemId != 0) {
                if (static_cast<Info*>(mInfoMaster.getBuffer()[static_cast<int>(i)])->mOnOff) {
                    sMyRoom::getInstance()->checkRoomWear(static_cast<Info*>(mInfoMaster.getBuffer()[static_cast<int>(i)])->mItemId);
                }
            }
        }
        i += 1u;
    } while (i < mInfoMaster.mLength);
}

void cFurniture::setRoomWearTrial() {
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isLogin()) {
        return;
    }
    sMyRoom::getInstance()->clearWearInfo();
    if (mInfoDisp.mLength == 0) {
        return;
    }
    u32 i = 0;
    do {
        if (mInfoDisp.getBuffer()[static_cast<int>(i)] != nullptr) {
            if (static_cast<Info*>(mInfoDisp.getBuffer()[static_cast<int>(i)])->mItemId != 0) {
                if (static_cast<Info*>(mInfoDisp.getBuffer()[static_cast<int>(i)])->mOnOff) {
                    sMyRoom::getInstance()->checkRoomWear(static_cast<Info*>(mInfoDisp.getBuffer()[static_cast<int>(i)])->mItemId);
                }
            }
        }
        i += 1u;
    } while (i < mInfoDisp.mLength);
}

__attribute__((weak)) void cFurniture::change(u32 item_id, bool onoff) {
    DDON_STUB("cFurniture::change")
    /* stub */
}

__attribute__((weak)) void cFurniture::release() {
    if (mInfoDisp.mLength != 0) {
        u32 v0_0 = mInfoDisp.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            MtObject* t0 = mInfoDisp.getBuffer()[static_cast<int>(i0_3)];
            if (t0 == nullptr) {
                v1_0 = v0_0;
            } else {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 24)) == 0) {
                    v1_0 = v0_0;
                } else {
                    sOmManager::getInstance()->releaseOmCtrl(reinterpret_cast<cOmControl*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 24)));
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 24) = 0;
                    v1_0 = mInfoDisp.mLength;
                }
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInfoMaster.mLength != 0) {
        u32 v3_0 = mInfoMaster.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mInfoMaster.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mInfoMaster.mpArray[i3_3];
                v4_0 = mInfoMaster.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInfoMaster.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInfoMaster.mpArray));
    }
    mInfoMaster.mpArray = nullptr;
    mInfoMaster.mBufsiz = 0;
    mInfoMaster.mLength = 0;
    if (mInfoDisp.mLength != 0) {
        u32 v6_0 = mInfoDisp.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mInfoDisp.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mInfoDisp.mpArray[i6_3];
                v7_0 = mInfoDisp.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInfoDisp.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInfoDisp.mpArray));
    }
    mInfoDisp.mpArray = nullptr;
    mInfoDisp.mBufsiz = 0;
    mInfoDisp.mLength = 0;
}

inline cFurniture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFurniture::MyDTI cFurniture::DTI("cFurniture", &::MtObject::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* cFurniture::MyDTI::newInstance() const {
    DDON_STUB("cFurniture::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFurniture::Info::getDTI() const {
    return cFurniture::Info::DTI;
}

cFurniture::Info::~Info() {
    if (mpOmCtrl == nullptr) {
        return;
    }
    sOmManager::getInstance()->releaseOmCtrl(mpOmCtrl);
    mpOmCtrl = nullptr;
}

__attribute__((weak)) void cFurniture::Info::createUnit() {
    DDON_STUB("cFurniture::Info::createUnit")
    /* stub */
}

inline cFurniture::Info::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFurniture::Info::MyDTI cFurniture::Info::DTI("cFurniture::Info", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cFurniture::Info::MyDTI::newInstance() const {
    return new (16u) cFurniture::Info;
}

template MtTypedArray<CDataFurnitureLayoutData>::~MtTypedArray();

template MtTypedArray<cFurniture::Info>::~MtTypedArray();

