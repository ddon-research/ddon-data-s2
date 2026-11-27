// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGeometry2Group.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDtiSelecter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "nCollision.h"
#include "rGeometry2Group.h"
#include "sMain.h"
#include "uGeometry2.h"
#include "uGeometry2Base.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uGeometry2Group::usage() {
}

const MtDTI& uGeometry2Group::getDTI() const {
    return uGeometry2Group::DTI;
}

void* uGeometry2Group::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uGeometry2Group::DTI)->memAlloc(sz, align, uGeometry2Group::DTI.mID);
}

uGeometry2Group::uGeometry2Group() {
    DDON_STUB("uGeometry2Group::uGeometry2Group")
    /* stub */
}

__attribute__((noinline)) uGeometry2Group::~uGeometry2Group() {
    DDON_STUB("uGeometry2Group::~uGeometry2Group")
    /* stub */
}

void uGeometry2Group::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "OwnerInfo", static_cast<MtObject*>(&mOwnerSystem), 6u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Resource", "resource", reinterpret_cast<MT_MFUNC>(&::uGeometry2Group::getResourceForUI), reinterpret_cast<MT_MFUNC>(&::uGeometry2Group::setResourceForUI), 2u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\346\217\217\347\224\273ON", static_cast<MT_MFUNC>(&::uGeometry2Group::setGeometryGroupDispAllON), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\217\217\347\224\273OFF", static_cast<MT_MFUNC>(&::uGeometry2Group::setGeometryGroupDispAllOFF), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\252\343\203\255\343\203\274\343\203\211", static_cast<MT_MFUNC>(&::uGeometry2Group::restoreGeometryFromResource), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\236\343\203\253\343\203\201\343\202\271\343\203\254\343\203\203\343\203\211ON/OFF", &mFlgMultiThread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\200\345\260\217\343\202\260\343\203\253\343\203\274\343\203\227\346\225\260", &mMultiThreadGroupNumMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GeometryGroup", static_cast<MtObject*>(&mGeometryGroupArray), 6u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGeometryGroupArray", static_cast<MtObject*>(&mGeometryGroupArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerSystem", static_cast<MtObject*>(&mOwnerSystem), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Resource", "resource", reinterpret_cast<MT_MFUNC>(&::uGeometry2Group::getResourceForUI), reinterpret_cast<MT_MFUNC>(&::uGeometry2Group::setResourceForUI), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MT_CTSTR uGeometry2Group::getName() {
    return uGeometry2Group::DTI.mName;
}

void uGeometry2Group::setup() {
    this->cUnit::setup();
}

__attribute__((weak)) void uGeometry2Group::move() {
    DDON_STUB("uGeometry2Group::move")
    /* stub */
}

__attribute__((weak)) void uGeometry2Group::sync() {
    DDON_STUB("uGeometry2Group::sync")
    /* stub */
}

__attribute__((weak)) void uGeometry2Group::moveAfter() {
    DDON_STUB("uGeometry2Group::moveAfter")
    /* stub */
}

__attribute__((weak)) void uGeometry2Group::draw(cDraw* pdraw) {
    DDON_STUB("uGeometry2Group::draw")
    /* stub */
}

void uGeometry2Group::registOwner(uModel* pOwner) {
    mOwnerSystem.registOwner(static_cast<MtObject*>(pOwner));
    if (mGeometryGroupArray.mLength != 0) {
        u32 v0_0 = mGeometryGroupArray.mLength;
        u32 i = 0;
        for (u32 v0_10 = mGeometryGroupArray.mLength - 1u;;) {
            if (i < v0_0) {
                if (mGeometryGroupArray.mpArray[i] != nullptr) {
                    static_cast<uGeometry2*>(mGeometryGroupArray.mpArray[i])->registOwner(pOwner);
                }
            }
            if (i == v0_10) {
                break;
            } else {
                v0_0 = mGeometryGroupArray.mLength;
                i = i + 1u;
            }
        }
    }
}

__attribute__((weak)) bool uGeometry2Group::loadResource(rGeometry2Group* pRGeometryGroup) {
    DDON_STUB("uGeometry2Group::loadResource")
    return {};
}

__attribute__((weak)) void uGeometry2Group::restoreGeometryFromResource() {
    DDON_STUB("uGeometry2Group::restoreGeometryFromResource")
    /* stub */
}

uGeometry2* uGeometry2Group::getGeometryGroup(u32 GroupIndex) {
    if (GroupIndex < mGeometryGroupArray.mLength) {
        return static_cast<uGeometry2*>(mGeometryGroupArray.mpArray[GroupIndex]);
    } else {
        return nullptr;
    }
}

u32 uGeometry2Group::getGeometryGroupNum() const {
    return mGeometryGroupArray.mLength;
}

void uGeometry2Group::setGeometryGroupDispAllON() {
    if (mGeometryGroupArray.mLength != 0) {
        u32 v0_0 = mGeometryGroupArray.mLength;
        unsigned int i0_3 = 0;
        for (u32 v0_8 = mGeometryGroupArray.mLength - 1u;;) {
            if (i0_3 < v0_0) {
                if (mGeometryGroupArray.mpArray[i0_3] != nullptr) {
                    static_cast<uGeometry2*>(mGeometryGroupArray.mpArray[i0_3])->setGeometryDraw(true);
                }
            }
            if (i0_3 == v0_8) {
                break;
            } else {
                v0_0 = mGeometryGroupArray.mLength;
                i0_3 = i0_3 + 1u;
            }
        }
    }
}

void uGeometry2Group::setGeometryGroupDispAllOFF() {
    if (mGeometryGroupArray.mLength != 0) {
        u32 v0_0 = mGeometryGroupArray.mLength;
        unsigned int i0_3 = 0;
        for (u32 v0_8 = mGeometryGroupArray.mLength - 1u;;) {
            if (i0_3 < v0_0) {
                if (mGeometryGroupArray.mpArray[i0_3] != nullptr) {
                    static_cast<uGeometry2*>(mGeometryGroupArray.mpArray[i0_3])->setGeometryDraw(false);
                }
            }
            if (i0_3 == v0_8) {
                break;
            } else {
                v0_0 = mGeometryGroupArray.mLength;
                i0_3 = i0_3 + 1u;
            }
        }
    }
}

void uGeometry2Group::evLoadResource() {
    restoreGeometryFromResource();
}

__attribute__((weak)) void uGeometry2Group::updateGeometry(u32 GeometryIndex) {
    DDON_STUB("uGeometry2Group::updateGeometry")
    /* stub */
}

void uGeometry2Group::setResourceForUI(cResource* pRGeometryGroup) {
    loadResource(static_cast<rGeometry2Group*>(pRGeometryGroup));
}

cResource* uGeometry2Group::getResourceForUI() {
    return mpRGeometryGroup;
}

inline uGeometry2Group::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2Group::MyDTI uGeometry2Group::DTI("uGeometry2Group", &::uGeometry2Base::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* uGeometry2Group::MyDTI::newInstance() const {
    DDON_STUB("uGeometry2Group::MyDTI::newInstance")
    return nullptr;
}

