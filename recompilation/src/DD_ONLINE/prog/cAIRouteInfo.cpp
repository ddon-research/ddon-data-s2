// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cAIRouteInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtCollisionDefine.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cAIPathTrace.h"
#include "../../XFramework/cAISvPathFinding.h"
#include "../../generated/shared/nDDOMath.h"
#include "sWorldOffset.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIRouteInfo::getDTI() const {
    return cAIRouteInfo::DTI;
}

inline void cAIRouteInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIRouteInfo::DTI)->memFree(p_addr);
}

cAIRouteInfo::cAIRouteInfo() {
    DDON_STUB("cAIRouteInfo::cAIRouteInfo")
    /* stub */
}

cAIRouteInfo::~cAIRouteInfo() {
}

void cAIRouteInfo::clearRouteInfo() {
    if (mPartsInfo.mAutoDelete) {
        u32 v3_0;
        if (mPartsInfo.mLength != 0) {
            u32 v0_0 = mPartsInfo.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mPartsInfo.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mPartsInfo.mpArray[i0_3];
                    v1_0 = mPartsInfo.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mPartsInfo.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mPartsInfo.mLength = 0;
}

__attribute__((weak)) void cAIRouteInfo::addRouteInfo(cAINavPathTrace* pNavPath, u32 startAttr, u32 endAttr, u32 routeInfoID, bool isDistance) {
    DDON_STUB("cAIRouteInfo::addRouteInfo")
    /* stub */
}

__attribute__((weak)) void cAIRouteInfo::endAddRouteInfo() {
    DDON_STUB("cAIRouteInfo::endAddRouteInfo")
    /* stub */
}

__attribute__((weak)) u32 cAIRouteInfo::getRouteInfoTiming(MtVector3* pDstOfsPos, f32* pDstDir, const MtVector3& ownerOfsPos, f32 distance, f32 climbHeight) const {
    DDON_STUB("cAIRouteInfo::getRouteInfoTiming")
    return {};
}

const cAIRouteInfoParts* cAIRouteInfo::searchTargetRoteInfo(u32 routeInfoID, u32 startNodeIdx) {
    if (mPartsInfo.mLength != 0) {
        u32 i = 0;
        do {
            if (mPartsInfo.getBuffer()[static_cast<int>(i)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mPartsInfo.getBuffer()[static_cast<int>(i)]) + 84)) == routeInfoID) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mPartsInfo.getBuffer()[static_cast<int>(i)]) + 64)) >= startNodeIdx) {
                        return static_cast<const cAIRouteInfoParts*>(mPartsInfo.getBuffer()[static_cast<int>(i)]);
                    }
                }
            }
            i += 1u;
        } while (i < mPartsInfo.mLength);
    }
    return nullptr;
}

inline cAIRouteInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIRouteInfo::MyDTI cAIRouteInfo::DTI("cAIRouteInfo", &::cAIObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIRouteInfo::MyDTI::newInstance() const {
    DDON_STUB("cAIRouteInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIRouteInfoParts::getDTI() const {
    return cAIRouteInfoParts::DTI;
}

inline void cAIRouteInfoParts::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIRouteInfoParts::DTI)->memFree(p_addr);
}

cAIRouteInfoParts::~cAIRouteInfoParts() {
}

inline cAIRouteInfoParts::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIRouteInfoParts::MyDTI cAIRouteInfoParts::DTI("cAIRouteInfoParts", &::cAIObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIRouteInfoParts::MyDTI::newInstance() const {
    DDON_STUB("cAIRouteInfoParts::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cAIRouteInfoParts>::~MtTypedArray();

