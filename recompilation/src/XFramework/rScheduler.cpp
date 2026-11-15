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
    DDON_STUB("rScheduler::load")
    return {};
}

__attribute__((noinline)) rScheduler::~rScheduler() {
        if (mpHeader != nullptr) {
            u32 tnum = mpHeader->track_num;
            for (u32 i = 0; i < tnum; i++) {
                rScheduler::TRACK* pt = &mpHeader->track[i];
                if (pt->track_type == rScheduler::TRACK::TYPE_RESOURCE) {
                    cResource** pv = reinterpret_cast<cResource**>(pt->key_value);
                    for (u32 j = 0; j < pt->key_num; j++) {
                        if (pv[j] != nullptr) {
                            pv[j]->release();
                            pv[j] = nullptr;
                        }
                    }
                }
            }
            MtMemoryAllocator::getAllocator(rScheduler::DTI)->memFree(mpHeader);
            mpHeader = nullptr;
        }
}

inline rScheduler::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rScheduler::MyDTI rScheduler::DTI("rScheduler", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rScheduler::MyDTI::newInstance() const {
    return new (16u) rScheduler;
}

