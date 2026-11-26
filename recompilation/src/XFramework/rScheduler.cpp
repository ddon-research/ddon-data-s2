// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rScheduler.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rScheduler::usage() {
}

const MtDTI& rScheduler::getDTI() const {
    return rScheduler::DTI;
}

inline MtAllocator* rScheduler::getAllocator() {
    return MtMemoryAllocator::getAllocator(rScheduler::DTI);
}

inline void* rScheduler::memAlloc(u32 size) {
    return getAllocator()->memAlloc(size, 16u);
}

inline void rScheduler::memFree(void* p_addr) {
    getAllocator()->memFree(p_addr);
}

inline void* rScheduler::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rScheduler::DTI)->memAlloc(sz, align, rScheduler::DTI.mID);
}

inline void rScheduler::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rScheduler::DTI)->memFree(p_addr);
}

MT_CTSTR rScheduler::getExt() const {
    return "sdl";
}

u32 rScheduler::getTrackNum() const {
    if (mpHeader != nullptr) {
        return mpHeader->track_num;
    } else {
        return 0;
    }
}

u32 rScheduler::getFrameMax() const {
    if (mpHeader != nullptr) {
        return mpHeader->frame_max;
    } else {
        return 0;
    }
}

rScheduler::TRACK* rScheduler::getBaseTrack() const {
    if (mpHeader != nullptr) {
        if (mpHeader->base_track != 0) {
            return &mpHeader->track[mpHeader->base_track];
        }
    }
    return nullptr;
}

bool rScheduler::isFloorFrame() const {
    if (mpHeader != nullptr) {
        return static_cast<bool>(mpHeader->floor_frame);
    } else {
        return false;
    }
}

__attribute__((weak)) bool rScheduler::load(MtStream& in) {
    u32 size = in.getLength();
    memFree(mpHeader);
    mpHeader = static_cast<HEADER*>(memAlloc(size));
    if (mpHeader == nullptr) {
        return false;
    }
    in.read(mpHeader, size);
    if (mpHeader->magic != 0x004c4453u || mpHeader->version != DATA_VERSION) {
        memFree(mpHeader);
        mpHeader = nullptr;
        return false;
    }
    mpHeader->meta_data = (mpHeader->meta_data != nullptr) ? (reinterpret_cast<u8*>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->meta_data)) : nullptr;
    
    u32 tnum = mpHeader->track_num;
    for (u32 i = 0; i < tnum; i++) {
        rScheduler::TRACK* pt = &mpHeader->track[i];
        switch (pt->track_type) {
        case rScheduler::TRACK::TYPE_ROOT:
            pt->track_name = (pt->track_name != nullptr) ? reinterpret_cast<MT_CTSTR>(mpHeader->meta_data + reinterpret_cast<uintptr>(pt->track_name)) : nullptr;
            break;
        case rScheduler::TRACK::TYPE_OBJECT:
            pt->track_name = (pt->track_name != nullptr) ? reinterpret_cast<MT_CTSTR>(mpHeader->meta_data + reinterpret_cast<uintptr>(pt->track_name)) : nullptr;
            break;
        case rScheduler::TRACK::TYPE_UNIT:
        case rScheduler::TRACK::TYPE_SYSTEM:
            pt->track_name = (pt->track_name != nullptr) ? reinterpret_cast<MT_CTSTR>(mpHeader->meta_data + reinterpret_cast<uintptr>(pt->track_name)) : nullptr;
            pt->pdti = MtDTI::from(pt->dti_id);
            break;
        case rScheduler::TRACK::TYPE_INT:
        case rScheduler::TRACK::TYPE_INT64:
        case rScheduler::TRACK::TYPE_VECTOR:
        case rScheduler::TRACK::TYPE_FLOAT:
        case rScheduler::TRACK::TYPE_FLOAT64:
        case rScheduler::TRACK::TYPE_BOOL:
        case rScheduler::TRACK::TYPE_REF:
        case rScheduler::TRACK::TYPE_RESOURCE:
        case rScheduler::TRACK::TYPE_STRING:
        case rScheduler::TRACK::TYPE_EVENT:
        case rScheduler::TRACK::TYPE_MATRIX:
            pt->prop_name = (pt->prop_name != nullptr) ? reinterpret_cast<MT_CTSTR>(mpHeader->meta_data + reinterpret_cast<uintptr>(pt->prop_name)) : nullptr;
            pt->key_frame = (pt->key_frame != nullptr) ? reinterpret_cast<rScheduler::KEY*>(reinterpret_cast<u8*>(mpHeader) + reinterpret_cast<uintptr>(pt->key_frame)) : nullptr;
            pt->key_value = (pt->key_value != nullptr) ? (reinterpret_cast<u8*>(mpHeader) + reinterpret_cast<uintptr>(pt->key_value)) : nullptr;
            break;
        default:
            break;
        }
        if (pt->track_type == rScheduler::TRACK::TYPE_RESOURCE) {
            uintptr* pv = reinterpret_cast<uintptr*>(pt->key_value);
            for (u32 j = 0; j < pt->key_num; j++) {
                if (pv[j] != 0) {
                    u32* pdata = reinterpret_cast<u32*>(mpHeader->meta_data + pv[j]);
                    const u32 dtiID = *pdata;
                    const MtDTI* pdti = MtDTI::from(dtiID);
                    if (pdti != nullptr) {
                        const MT_CTSTR pPath = reinterpret_cast<MT_CTSTR>(pdata + 1);
                        pv[j] = reinterpret_cast<uintptr>(sResource::getInstance()->create(*pdti, pPath, sResource::MODE_BLOCKING));
                    } else {
                        pv[j] = 0;
                    }
                }
            }
        }
        if (pt->track_type == rScheduler::TRACK::TYPE_STRING) {
            uintptr* pv = reinterpret_cast<uintptr*>(pt->key_value);
            for (u32 j = 0; j < pt->key_num; j++) {
                if (pv[j] != 0) {
                    pv[j] += reinterpret_cast<uintptr>(mpHeader->meta_data);
                }
            }
        }
    }
    return true;
}

__attribute__((noinline)) rScheduler::~rScheduler() {
        HEADER* pHeader = mpHeader;
        if (pHeader != nullptr) {
            u32 track_num = pHeader->track_num;
            for (u32 i = 0; i < track_num; i++) {
                TRACK* ptrack = &pHeader->track[i];
                if (ptrack->track_type == 13) {
                    cResource** pv = reinterpret_cast<cResource**>(ptrack->key_value);
                    for (u32 j = 0; j < ptrack->key_num; j++) {
                        if (pv[j] != nullptr) {
                            pv[j]->cResource::release();
                            pv[j] = nullptr;
                        }
                    }
                }
                pHeader = mpHeader;
            }
            MtMemoryAllocator::getAllocator(rScheduler::DTI)->memFree(pHeader);
            mpHeader = nullptr;
        }
}

inline rScheduler::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rScheduler::MyDTI rScheduler::DTI("rScheduler", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rScheduler::MyDTI::newInstance() const {
    return new (16u) rScheduler;
}

