// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <kernel.h>
#include <stdlib.h>
#include "sMain.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPerformance.h"
#include "../MT/MtProfiler.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cResource.h"
#include "cSystem.h"
#include "nSyncPoint.h"
#include "sApp.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sMain::getDTI() const {
    return sMain::DTI;
}

sMain::~sMain() {
    DDON_STUB("sMain::~sMain")
    /* stub */
}

__attribute__((weak)) void sMain::move() {
    DDON_STUB("sMain::move")
    /* stub */
}

bool sMain::close() {
    return true;
}

void sMain::exit() {
    mExit = true;
}

__attribute__((weak)) void sMain::final() {
    DDON_STUB("sMain::final")
    /* stub */
}

__attribute__((weak)) void sMain::createProperty(MtPropertyList& s) {
    DDON_STUB("sMain::createProperty")
    /* stub */
}

MtUI* sMain::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sMain::createMenu(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mPause", reinterpret_cast<MT_MFUNC>(&::sMain::isPausePrivate), reinterpret_cast<MT_MFUNC>(&::sMain::setPausePrivate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Skip", static_cast<MT_MFUNC>(&::sMain::skip), 10u);
    if ((sApp::mpInstance) != nullptr) {
        (sApp::mpInstance)->createMenu(s);
    }
    s << MtProperty(static_cast<MtObject*>(this), "Exit", static_cast<MT_MFUNC>(&::sMain::exit), 10u);
}

__attribute__((weak)) JOBHANDLE sMain::addDelayJob(MtObject* pthis, MT_MFUNC32 pfunc, u32 param) {
    DDON_STUB("sMain::addDelayJob")
    return {};
}

__attribute__((weak)) void sMain::executeJob(sMain::JOB_MODE mode) {
    DDON_STUB("sMain::executeJob")
    /* stub */
}

__attribute__((weak)) u32 sMain::getJobThreadIndex() {
    DDON_STUB("sMain::getJobThreadIndex")
    return {};
}

__attribute__((weak)) void sMain::setJobThreadNum(u32 n) {
    DDON_STUB("sMain::setJobThreadNum")
    /* stub */
}

__attribute__((weak)) u32 sMain::getDelayJobThreadIndex() {
    DDON_STUB("sMain::getDelayJobThreadIndex")
    return {};
}

void sMain::setFrameWait(bool f) {
    mFrameWait = f;
    mIdealCounter = mRealCounter;
    mPrevCounter = 0;
    mDeltaTime = 1.0f;
    mDelayFrame = 0.0f;
}

static auto ddon_emit_0x01b9fe60 __attribute__((used)) = &sMain::isFrameWait;

static auto ddon_emit_0x01b9fe70 __attribute__((used)) = &sMain::getDeltaTime;

static auto ddon_emit_0x01b9fe40 __attribute__((used)) = &sMain::setDeltaTime;

void sMain::resetFrame() {
    mIdealCounter = mRealCounter;
    mPrevCounter = 0;
    mDeltaTime = 1.0f;
    mDelayFrame = 0.0f;
}

__attribute__((weak)) void sMain::resetTimer() {
    DDON_STUB("sMain::resetTimer")
    /* stub */
}

bool sMain::isPausePrivate() const {
    return mPause;
}

void sMain::setPausePrivate(bool NewValue) {
    mPause = NewValue;
}

bool sMain::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeXML(out, "XFramework Scene 1.0", static_cast<MtObject*>(this), MtSerializer::MODE_STATE, MtSerializer::ENCODING_AUTO);
}

bool sMain::load(MtStream& in) {
    if (in.isReadable()) {
        MtSerializer sz(65536);
        return sz.deserializeXML(in, "XFramework Scene 1.0", static_cast<MtObject*>(this), MtSerializer::MODE_STATE, MtSerializer::ENCODING_AUTO) != nullptr;
    } else {
        return false;
    }
}

bool sMain::saveConfig(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeXML(out, "XFramework Config 1.0", static_cast<MtObject*>(this), MtSerializer::MODE_CONFIG, MtSerializer::ENCODING_AUTO);
}

bool sMain::loadConfig(MtStream& in) {
    if (in.isReadable()) {
        MtSerializer sz(65536);
        return sz.deserializeXML(in, "XFramework Config 1.0", static_cast<MtObject*>(this), MtSerializer::MODE_CONFIG, MtSerializer::ENCODING_AUTO) != nullptr;
    } else {
        return false;
    }
}

u32 sMain::getNextJobThreadNum() {
    return mNextJobThreadNum;
}

__attribute__((weak)) void sMain::createThread() {
    DDON_STUB("sMain::createThread")
    /* stub */
}

__attribute__((weak)) void sMain::createDelayJobThread(u32 thread_num) {
    DDON_STUB("sMain::createDelayJobThread")
    /* stub */
}

void sMain::freeDefaultMemory() {
    (sApp::mpInstance)->sApp::finalAppInStableMem();
    MtPropertyList::releaseElementPool();
    MtMemory::terminateAllocator();
}

void sMain::initMemory() {
    MtAllocator* t0 = MtMemoryAllocator::getAllocator(cResource::DTI);
    t0->mAttr = MtMemoryAllocator::getAllocator(cResource::DTI)->mAttr | 2;
    MtAllocator* t1 = MtMemoryAllocator::getAllocator(cSystem::DTI);
    t1->mAttr = MtMemoryAllocator::getAllocator(cSystem::DTI)->mAttr | 2;
    MtMemory::mpAllocatorType[7]->mAttr = MtMemory::mpAllocatorType[7]->mAttr | 2;
    (MtString::mpAllocator)->mAttr = (MtString::mpAllocator)->mAttr | 2;
    MtAllocator* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI);
    t2->mAttr = MtMemoryAllocator::getAllocator(MtArray::DTI)->mAttr | 2;
    MtMemory::mpAllocatorType[1]->mAttr = MtMemory::mpAllocatorType[1]->mAttr | 2;
}

void sMain::skip() {
    mSkip = 2;
}

u32 sMain::jobLoop(sMain::JOB_THREAD* ph) {
    ph->active = true;
    const u64 wakeup_bit = 1ul << static_cast<unsigned long>(static_cast<unsigned char>(ph->job_index * 2u) & 63);
    for (const u64 sleep_bit = 1ul << static_cast<unsigned long>(static_cast<unsigned char>((ph->job_index * 2u) + 1u) & 63);;) {
        if (ph->exit) {
            break;
        } else {
            sceKernelWaitEventFlag(mJobThreadEventFlag, wakeup_bit, 33u, static_cast<uint64_t*>(nullptr), static_cast<SceKernelUseconds*>(nullptr));
            sMain::jobProc(ph);
            sceKernelSetEventFlag(mJobThreadEventFlag, sleep_bit);
        }
    }
    return 0;
}

__attribute__((weak)) u32 sMain::delayJobLoop(sMain::JOB_THREAD* ph) {
    DDON_STUB("sMain::delayJobLoop")
    return {};
}

__attribute__((weak)) void* sMain::jobHandler(void* pthis) {
    DDON_STUB("sMain::jobHandler")
    return nullptr;
}

__attribute__((weak)) void* sMain::delayJobHandler(void* pthis) {
    DDON_STUB("sMain::delayJobHandler")
    return nullptr;
}

__attribute__((weak)) void sMain::jobProc(const sMain::JOB_THREAD* ph) {
    DDON_STUB("sMain::jobProc")
    /* stub */
}

sMain::JOB_WORK_PARAM* sMain::getDelayJob(JOBHANDLE* phandle) {
    sceKernelWaitSema(mDelayJobSemaphore.mHandle, 1, static_cast<SceKernelUseconds*>(nullptr));
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        JOBHANDLE jobhandle = mDelayJobReadPt;
        if (mDelayJobWritePt == jobhandle) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (jobhandle < mDelayJobWritePt) {
                mDelayJobReadPt = jobhandle + 1ul;
                *phandle = jobhandle;
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return &mDelayJob[jobhandle & 4095ul];
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
        return nullptr;
    } else {
        JOBHANDLE jobhandle = mDelayJobReadPt;
        if (mDelayJobWritePt == jobhandle) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (jobhandle < mDelayJobWritePt) {
                mDelayJobReadPt = jobhandle + 1ul;
                *phandle = jobhandle;
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return &mDelayJob[jobhandle & 4095ul];
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
        return nullptr;
    }
}

inline sMain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sMain::MyDTI sMain::DTI("sMain", &::cSystem::DTI, 0x57AB8ul, 0u, 0u);

sMain* sMain::mpInstance;

MT_CTSTR sMain::mBuildVersion = "MasterRelease PS4 Dec 21 2016 13:39:53";

__attribute__((weak)) MtObject* sMain::MyDTI::newInstance() const {
    DDON_STUB("sMain::MyDTI::newInstance")
    return nullptr;
}

