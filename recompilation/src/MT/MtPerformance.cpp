// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_kernel.h>
#include "MtPerformance.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtPerformance::getDTI() const {
    return MtPerformance::DTI;
}

inline void* MtPerformance::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtPerformance::DTI)->memAlloc(sz, align, MtPerformance::DTI.mID);
}

inline void MtPerformance::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtPerformance::DTI)->memFree(p_addr);
}

__attribute__((weak)) void MtPerformance::start() {
    DDON_STUB("MtPerformance::start")
    /* stub */
}

__attribute__((weak)) void MtPerformance::peek() {
    DDON_STUB("MtPerformance::peek")
    /* stub */
}

inline MtPerformance::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtPerformance::MyDTI MtPerformance::DTI("MtPerformance", &::MtObject::DTI, 96ul, 0u, 0u);

MtObject* MtPerformance::MyDTI::newInstance() const {
    return new (16u) MtPerformance;
}

const MtDTI& MtPerformanceCounter::getDTI() const {
    return MtPerformanceCounter::DTI;
}

inline void* MtPerformanceCounter::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtPerformanceCounter::DTI)->memAlloc(sz, align, MtPerformanceCounter::DTI.mID);
}

inline void MtPerformanceCounter::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtPerformanceCounter::DTI)->memFree(p_addr);
}

s64 MtPerformanceCounter::getCurrent() {
    return static_cast<s64>(sceKernelReadTsc());
}

s64 MtPerformanceCounter::getFrequency() {
    if ((MtPerformanceCounter::mFrequency) == 0) {
        MtPerformanceCounter::mFrequency = static_cast<s64>(sceKernelGetTscFrequency());
    }
    return MtPerformanceCounter::mFrequency;
}

inline MtPerformanceCounter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtPerformanceCounter::MyDTI MtPerformanceCounter::DTI("MtPerformanceCounter", &::MtObject::DTI, 48ul, 0u, 0u);

s64 MtPerformanceCounter::mFrequency;

MtObject* MtPerformanceCounter::MyDTI::newInstance() const {
    return new (16u) MtPerformanceCounter;
}

const MtDTI& MtPerformanceTimer::getDTI() const {
    return MtPerformanceTimer::DTI;
}

__attribute__((weak)) void MtPerformanceTimer::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtPerformanceTimer::DTI)->memFree(p_addr);
}

__attribute__((weak)) void MtPerformanceTimer::start() {
    DDON_STUB("MtPerformanceTimer::start")
    /* stub */
}

__attribute__((weak)) void MtPerformanceTimer::end() {
    DDON_STUB("MtPerformanceTimer::end")
    /* stub */
}

inline MtPerformanceTimer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtPerformanceTimer::MyDTI MtPerformanceTimer::DTI("MtPerformanceTimer", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* MtPerformanceTimer::MyDTI::newInstance() const {
    DDON_STUB("MtPerformanceTimer::MyDTI::newInstance")
    return nullptr;
}

