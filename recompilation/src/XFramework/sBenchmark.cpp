// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sBenchmark.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cArea.h"
#include "cSystem.h"
#include "sArea.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sBenchmark::getDTI() const {
    return sBenchmark::DTI;
}

void* sBenchmark::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sBenchmark::DTI)->memAlloc(sz, align, sBenchmark::DTI.mID);
}

sBenchmark::sBenchmark() {
    DDON_STUB("sBenchmark::sBenchmark")
    /* stub */
}

sBenchmark::~sBenchmark() {
    sBenchmark::mpInstance = nullptr;
}

__attribute__((weak)) void sBenchmark::reset() {
}

void sBenchmark::move() {
    switch (mBenchmarkState - 2u) {
        case 0:
        {
            u32 t0 = mBenchmarkIndex;
            if (jumpArea(&mBenchmark[t0])) {
                mBenchmarkState = 3;
                mFrameTime = 0.0f;
                mMaxFrameTime = mBenchmark[t0].mMeasureFrame;
                mFrameCount = 0;
                mBenchmark[t0].mPrevAvgFPS = mBenchmark[t0].mAvgFPS;
            } else {
                mBenchmarkState = 1;
            }
            break;
        }
        case 1:
        {
            if (isAreaInitialized(&mBenchmark[mBenchmarkIndex])) {
                mBenchmarkState = 4;
                mFrameWait = (sMain::mpInstance)->mFrameWait;
                mMaxFps = (sMain::mpInstance)->mMaxFps;
                mToolVisible = false;
                mFrameCount = 0;
                (sMain::mpInstance)->sMain::setFrameWait(false);
                (sMain::mpInstance)->mMaxFps = 10000.0f;
            }
            break;
        }
        case 2:
        {
            (sMain::mpInstance)->mPause = true;
            mFrameCount = mFrameCount + 1u;
            if (mFrameCount > 20u) {
                mFrameCount = 0;
                (sMain::mpInstance)->mPause = false;
                mBenchmarkState = 5;
            }
            break;
        }
        case 3:
        {
            f32 t1 = (sMain::mpInstance)->mDeltaTime;
            f32 t2 = mFrameTime;
            mFrameTime = t1 + t2;
            u32 t3 = mFrameCount;
            mFrameCount = t3 + 1u;
            mBenchmark[mBenchmarkIndex].mAvgFPS = 1000.0f / (((t1 + t2) * (1000.0f / (sMain::mpInstance)->mFps)) / static_cast<float>(t3 + 1u));
            if ((t1 + t2) >= static_cast<float>(mMaxFrameTime)) {
                mBenchmarkState = 6;
            }
            break;
        }
        case 4:
        {
            if (mOAEnable) {
                mBenchmarkState = 0;
                (sMain::mpInstance)->sMain::setFrameWait(mFrameWait);
            } else {
                if (mBenchmarkAll) {
                    if ((mBenchmarkIndex + 1u) < mBenchmarkNum) {
                        mBenchmarkIndex = mBenchmarkIndex + 1u;
                        mBenchmarkState = 2;
                        (sMain::mpInstance)->sMain::setFrameWait(mFrameWait);
                    } else {
                        mBenchmarkState = 1;
                        (sMain::mpInstance)->sMain::setFrameWait(mFrameWait);
                    }
                } else {
                    mBenchmarkState = 1;
                    (sMain::mpInstance)->sMain::setFrameWait(mFrameWait);
                }
            }
            (sMain::mpInstance)->mMaxFps = mMaxFps;
            break;
        }
        default:
        {
            break;
        }
    }
}

void sBenchmark::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBenchmarkNum", &mBenchmarkNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBenchmarkIndex", &mBenchmarkIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBenchmarkAll", &mBenchmarkAll, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOAEnable", &mOAEnable, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBenchmarkState", &mBenchmarkState, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrameTime", &mFrameTime, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxFrameTime", &mMaxFrameTime, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrameCount", &mFrameCount, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "BenchmarkInfo", reinterpret_cast<MT_MFUNC>(&::sBenchmark::getBenchmarkInfo), reinterpret_cast<MT_MFUNC>(&::sBenchmark::setBenchmarkInfo), 163u, reinterpret_cast<MT_MFUNC>(&::sBenchmark::getBenchmarkNum), reinterpret_cast<MT_MFUNC>(&::sBenchmark::setBenchmarkNum));
}

MtUI* sBenchmark::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sBenchmark::createMenu(MtPropertyList& s) {
    DDON_STUB("sBenchmark::createMenu")
    /* stub */
}

__attribute__((weak)) s32 sBenchmark::addBenchmark(const MtDTI& area, u32 frame, MT_CTSTR name) {
    DDON_STUB("sBenchmark::addBenchmark")
    return {};
}

void sBenchmark::startBenchmark(s32 benchmark_index) {
    mBenchmarkState = 2;
    mBenchmarkIndex = (benchmark_index <= -1) ? 0u : static_cast<unsigned int>(benchmark_index);
    mBenchmarkAll = static_cast<bool>(static_cast<unsigned int>(benchmark_index) >> 31);
}

static auto ddon_emit_0x01b9e8a0 __attribute__((used)) = &sBenchmark::getBenchmarkNum;

static auto ddon_emit_0x01b9e880 __attribute__((used)) = &sBenchmark::getBenchmarkInfo;

bool sBenchmark::jumpArea(const sBenchmark::BenchmarkInfo* pinfo) {
    sArea* v0_3 = sArea::mpInstance;
    bool b2_0;
    if (v0_3 != nullptr) {
        const MtDTI* v0_2 = pinfo->mpArea;
        MT_CTSTR v0_0 = cArea::DTI.mName;
        if (v0_0 != v0_2->mName) {
            for (const MtDTI* v0_1 = v0_2;;) {
                if (v0_1->mpParent != nullptr) {
                    if (v0_0 != v0_1->mpParent->mName) {
                        v0_1 = v0_1->mpParent;
                    } else {
                        break;
                    }
                } else {
                    b2_0 = false;
                    return b2_0;
                }
            }
        }
        v0_3->jump(*v0_2);
        b2_0 = true;
    } else {
        b2_0 = false;
    }
    return b2_0;
}

__attribute__((weak)) bool sBenchmark::isAreaInitialized(const sBenchmark::BenchmarkInfo* pinfo) {
    DDON_STUB("sBenchmark::isAreaInitialized")
    return {};
}

__attribute__((weak)) void sBenchmark::setBenchmarkInfo(MtObject*, u32) {
}

__attribute__((weak)) void sBenchmark::setBenchmarkNum(u32) {
}

inline sBenchmark::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBenchmark::MyDTI sBenchmark::DTI("sBenchmark", &::cSystem::DTI, 10304ul, 0u, 0u);

sBenchmark* sBenchmark::mpInstance;

__attribute__((weak)) MtObject* sBenchmark::MyDTI::newInstance() const {
    DDON_STUB("sBenchmark::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sBenchmark::BenchmarkInfo::getDTI() const {
    return sBenchmark::BenchmarkInfo::DTI;
}

__attribute__((weak)) void sBenchmark::BenchmarkInfo::createProperty(MtPropertyList& s) {
    DDON_STUB("sBenchmark::BenchmarkInfo::createProperty")
    /* stub */
}

inline sBenchmark::BenchmarkInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBenchmark::BenchmarkInfo::MyDTI sBenchmark::BenchmarkInfo::DTI("sBenchmark::BenchmarkInfo", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* sBenchmark::BenchmarkInfo::MyDTI::newInstance() const {
    return new (16u) sBenchmark::BenchmarkInfo;
}

