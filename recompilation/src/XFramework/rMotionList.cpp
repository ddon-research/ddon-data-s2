// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMotionList.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#include "nMotion.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rMotionList::usage() {
}

const MtDTI& rMotionList::getDTI() const {
    return rMotionList::DTI;
}

MT_CTSTR rMotionList::getExt() const {
    return "lmt";
}

nMotion::MOTION_INFO* rMotionList::getMotionInfo(u32 no) const {
    if (mpHdr != nullptr) {
        if (no < mpHdr->motion_num) {
            return mpHdr->pmotion[no];
        }
    }
    return nullptr;
}

__attribute__((weak)) bool rMotionList::load(MtStream& in) {
        clear();
        u32 len = in.getLength();
        if (len == 0) {
            return false;
        }
        mpHdr = static_cast<MOTION_LIST_HDR*>(MtMemoryAllocator::getAllocator(rMotionList::DTI)->memAlloc(len, 16u));
        in.read(mpHdr, len);
        if (mpHdr->magic != 0x00544d4cu) {
            return false;
        }
        if (mpHdr->version != DATA_VERSION) {
            return false;
        }
        for (u32 i = 0; i < mpHdr->motion_num; ++i) {
            if (mpHdr->pmotion[i]) {
                mpHdr->pmotion[i] = reinterpret_cast<nMotion::MOTION_INFO*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(mpHdr->pmotion[i]));
                nMotion::MOTION_INFO* pmot = mpHdr->pmotion[i];
                pmot->param = reinterpret_cast<nMotion::MOTION_PARAM*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(pmot->param));
                if (!(pmot->duplicate & nMotion::MOTION_INFO::D_MOTION)) {
                    for (u32 j = 0; j < pmot->param_num; ++j) {
                        if (pmot->param[j].pparam) {
                            pmot->param[j].pparam = reinterpret_cast<void*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(pmot->param[j].pparam));
                        }
                        switch (pmot->param[j].type) {
                        case nMotion::MOTION_PARAM::T_UNKNOWN:
                        case nMotion::MOTION_PARAM::T_VECTOR3_CONST:
                        case nMotion::MOTION_PARAM::T_QUATERNION3_CONST:
                        case nMotion::MOTION_PARAM::T_LINEARKEY:
                        case nMotion::MOTION_PARAM::T_POLAR3KEY:
                        case nMotion::MOTION_PARAM::T_VECTOR3:
                        case nMotion::MOTION_PARAM::T_QUATERNION4:
                            break;
                        default:
                            if (pmot->param[j].pparamex) {
                                pmot->param[j].pparamex = reinterpret_cast<void*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(pmot->param[j].pparamex));
                            }
                            break;
                        }
                    }
                }
                if (pmot->seq_info) {
                    pmot->seq_info = reinterpret_cast<nMotion::SEQUENCE_INFO*>(reinterpret_cast<char*>(mpHdr) + reinterpret_cast<size_t>(pmot->seq_info));
                    if (!(pmot->duplicate & nMotion::MOTION_INFO::D_SEQUENCE)) {
                        for (s32 j = 0; j < MAX_SEQPAGE; ++j) {
                            pmot->seq_info[j].seq = reinterpret_cast<u32*>(reinterpret_cast<char*>(mpHdr) + reinterpret_cast<size_t>(pmot->seq_info[j].seq));
                        }
                    }
                }
                if (pmot->kf_num != 0) {
                    pmot->kf_info = pmot->kf_info ? reinterpret_cast<nMotion::KEYFRAME_INFO*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(pmot->kf_info)) : nullptr;
                    if (!(pmot->duplicate & nMotion::MOTION_INFO::D_KEYFRAME)) {
                        for (u32 j = 0; j < pmot->kf_num; ++j) {
                            pmot->kf_info[j].key = pmot->kf_info[j].key ? reinterpret_cast<nMotion::KEYINFO_U32*>(reinterpret_cast<size_t>(mpHdr) + reinterpret_cast<size_t>(pmot->kf_info[j].key)) : nullptr;
                        }
                    }
                }
            }
        }
        return true;
}

bool rMotionList::save(MtStream& out) {
    return false;
}

void rMotionList::clear() {
    MOTION_LIST_HDR* t0 = mpHdr;
    MtMemoryAllocator::getAllocator(rMotionList::DTI)->memFree(static_cast<void*>(t0));
    mpHdr = nullptr;
}

rMotionList::~rMotionList() {
    MOTION_LIST_HDR* t0 = mpHdr;
    MtMemoryAllocator::getAllocator(rMotionList::DTI)->memFree(static_cast<void*>(t0));
}

inline rMotionList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMotionList::MyDTI rMotionList::DTI("rMotionList", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rMotionList::MyDTI::newInstance() const {
    return new (16u) rMotionList;
}

