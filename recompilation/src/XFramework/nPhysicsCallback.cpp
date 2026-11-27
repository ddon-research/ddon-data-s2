// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nPhysicsCallback.h"
#include "../MT/MtAllocator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nPhysics::Callback::Callback() {
    Num = 0;
    Size = 0;
    Info = nullptr;
    Allocator = nullptr;
}

nPhysics::Callback::~Callback() {
    if (Info == nullptr) {
        return;
    }
    Allocator->memFree(static_cast<void*>(Info));
    Info = nullptr;
}

void nPhysics::Callback::initialize(MtAllocator* allocator) {
    Allocator = allocator;
}

void nPhysics::Callback::add(MtObject* object, MT_MFUNC function) {
    if (Size != 0) {
        if (Size == Num) {
            nPhysics::Callback::INFO* work = static_cast<nPhysics::Callback::INFO*>(Allocator->memAlloc(static_cast<size_t>(Size) * 48, 16u));
            ::memcpy(static_cast<void*>(work), static_cast<const void*>(Info), Num * 24u);
            Allocator->memFree(static_cast<void*>(Info));
            Size = Size * 2u;
            Info = work;
            u32 t2 = Num;
            work[t2].Object = object;
            work[t2].Function = function;
            Num = t2 + 1u;
        } else {
            nPhysics::Callback::INFO* t1 = Info;
            u32 t2 = Num;
            t1[t2].Object = object;
            t1[t2].Function = function;
            Num = t2 + 1u;
        }
    } else {
        Size = 10;
        void* t0 = Allocator->memAlloc(240ul, 16u);
        Info = static_cast<nPhysics::Callback::INFO*>(t0);
        u32 t2 = Num;
        Info[t2].Object = object;
        Info[t2].Function = function;
        Num = t2 + 1u;
    }
}

__attribute__((weak)) bool nPhysics::Callback::remove(MtObject* object, MT_MFUNC function) {
    DDON_STUB("nPhysics::Callback::remove")
    return {};
}

