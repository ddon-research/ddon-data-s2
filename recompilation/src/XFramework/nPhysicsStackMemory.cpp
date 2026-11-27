// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsStackMemory.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "nPhysicsSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nPhysics::StackMemory::StackMemory() {
    mStackSize = 0;
    mCurrentMemoryBlock = nullptr;
    mMemoryBlock = nullptr;
    mMemorySize = 0;
    mUsedMemorySize = 0;
    mMemoryAddress = nullptr;
}

nPhysics::StackMemory::~StackMemory() {
    u8* t0 = mMemoryAddress;
    if (t0 == nullptr) {
        return;
    }
    ::MtMemoryAllocator::getAllocator(::nPhysics::System::DTI)->memFree(static_cast<void*>(t0));
    mMemoryAddress = nullptr;
}

__attribute__((weak)) void nPhysics::StackMemory::create(const u32 memory_size, const u32 stack_size) {
    DDON_STUB("nPhysics::StackMemory::create")
    /* stub */
}

__attribute__((weak)) void* nPhysics::StackMemory::push(const u32 size, const u32 alignment) {
    DDON_STUB("nPhysics::StackMemory::push")
    return nullptr;
}

__attribute__((weak)) void nPhysics::StackMemory::pop(void* address) {
    DDON_STUB("nPhysics::StackMemory::pop")
    /* stub */
}

