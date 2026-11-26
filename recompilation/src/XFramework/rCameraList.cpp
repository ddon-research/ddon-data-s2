// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCameraList.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"

#include "../MT/MtStream.h"
#include "cResource.h"
#include "nMotion.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCameraList::getDTI() const {
    return rCameraList::DTI;
}

inline void* rCameraList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rCameraList::DTI)->memAlloc(sz, align, rCameraList::DTI.mID);
}

inline void rCameraList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rCameraList::DTI)->memFree(p_addr);
}

rCameraList::~rCameraList() {
    CAMERA_LIST_HDR* t0 = mpHdr;
    MtMemoryAllocator::getAllocator(rCameraList::DTI)->memFree(static_cast<void*>(t0));
    mpHdr = nullptr;
}

MT_CTSTR rCameraList::getExt() const {
    return "lcm";
}

__attribute__((weak)) bool rCameraList::load(MtStream& in) {
    u32 size = in.getLength();
    mpHdr = static_cast<CAMERA_LIST_HDR*>(MtMemoryAllocator::getAllocator(rCameraList::DTI)->memAlloc(size, 16));
    in.read(mpHdr, size);
    if (mpHdr->magic != 0x4d434c) {
        return false;
    }
    if (mpHdr->version != DATA_VERSION) {
        return false;
    }
    u32 n = mpHdr->camera_num;
    for (u32 i = 0; i < n; ++i) {
        if (mpHdr->pcamera[i] != nullptr) {
            mpHdr->pcamera[i] = reinterpret_cast<CAMERA_INFO*>(reinterpret_cast<u8*>(mpHdr) + reinterpret_cast<size_t>(mpHdr->pcamera[i]));
        }
    }
    for (u32 i = 0; i < n; ++i) {
        CAMERA_INFO* pinfo = mpHdr->pcamera[i];
        if (pinfo != nullptr) {
            nMotion::MOTION_PARAM* mot_param[3] = {&pinfo->mot_pos, &pinfo->mot_target, &pinfo->mot_quat};
            for (u32 n = 0; n < 3; ++n) {
                nMotion::MOTION_PARAM* pp = mot_param[n];
                if (pp->pparam != nullptr) {
                    pp->pparam = reinterpret_cast<u8*>(mpHdr) + reinterpret_cast<size_t>(pp->pparam);
                }
                if (pp->pparamex != nullptr) {
                    pp->pparamex = reinterpret_cast<u8*>(mpHdr) + reinterpret_cast<size_t>(pp->pparamex);
                }
            }
            nMotion::CURVE_PARAM* pp = &pinfo->mot_fov;
            if (pp->pparam != nullptr) {
                pp->pparam = reinterpret_cast<u8*>(mpHdr) + reinterpret_cast<size_t>(pp->pparam);
            }
        }
    }
    return true;
}

bool rCameraList::save(MtStream& out) {
    return false;
}

void rCameraList::clear() {
    CAMERA_LIST_HDR* t0 = mpHdr;
    MtMemoryAllocator::getAllocator(rCameraList::DTI)->memFree(static_cast<void*>(t0));
    mpHdr = nullptr;
}

inline rCameraList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCameraList::MyDTI rCameraList::DTI("rCameraList", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rCameraList::MyDTI::newInstance() const {
    return new (16u) rCameraList;
}

