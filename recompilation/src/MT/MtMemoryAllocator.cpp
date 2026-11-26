// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtMemoryAllocator.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtMemory.h"
#include "MtObject.h"
#include "MtScalableAllocator.h"
#include "MtString.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void elf_v_Z21recursiveSetAllocatorP5MtDTIRKN17MtMemoryAllocator11InitializerE(MtDTI*, const MtMemoryAllocator::Initializer&) __asm__("_Z21recursiveSetAllocatorP5MtDTIRKN17MtMemoryAllocator11InitializerE");

static MT_STR gWorkBuffer;

MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti) {
    return MtMemory::mpAllocatorType[dti.mAllocatorIndex];
}

void MtMemoryAllocator::setMtMemoryAllocator(const MtMemoryAllocator::Initializer& init) {
    MT_CTSTR t0 = MtObject::DTI.mName;
    u32 idx = init.getAllocatorID(t0);
    if (idx != 0x7FFFFFFF) {
        unsigned int t2 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtObject::DTI) + 48);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtObject::DTI) + 48) = ((idx & 63u) * 0x800000u) | (t2 & 0xE07FFFFFu);
        MtObject::DTI.updateChildAlloc();
    }
    MtAllocator* t4 = *MtMemory::mpAllocatorType;
    void* t5 = t4->memAlloc(512ul, 16u);
    gWorkBuffer = static_cast<char*>(t5);
    MtDTI* t7 = MtObject::DTI.mpChild;
    void* v2_0;
    if (t7 == nullptr) {
        v2_0 = t5;
    } else {
        for (MtDTI* v0_3 = t7;;) {
            elf_v_Z21recursiveSetAllocatorP5MtDTIRKN17MtMemoryAllocator11InitializerE(v0_3, init);
            MtDTI* t9 = v0_3->mpNext;
            if (t9 != nullptr) {
                v0_3 = t9;
            } else {
                break;
            }
        }
        char* t10 = gWorkBuffer;
        v2_0 = t10;
    }
    MtAllocator* t11 = *MtMemory::mpAllocatorType;
    unsigned long t12 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t11) + 0);
    t11->memFree(v2_0);
    gWorkBuffer = nullptr;
}

__attribute__((weak)) void MtMemoryAllocator::setAvailableAllocatorType(u32 num) {
    DDON_STUB("MtMemoryAllocator::setAvailableAllocatorType")
    /* stub */
}

__attribute__((weak)) void MtMemoryAllocator::setDefaultAppAllocator() {
    DDON_STUB("MtMemoryAllocator::setDefaultAppAllocator")
    /* stub */
}

__attribute__((weak)) void MtMemoryAllocator::allocateDefaultMemory() {
    DDON_STUB("MtMemoryAllocator::allocateDefaultMemory")
    /* stub */
}

MtMemoryAllocator::Initializer::Initializer(u32 max_entry) {
    mMaxEntryNum = max_entry;
    mEntryNum = 0;
    mAllocIdTable = nullptr;
    mAllocIdTable = static_cast<MtMemoryAllocator::Initializer::Entry* *>((*::MtMemory::mpAllocatorType)->memAlloc(static_cast<size_t>(max_entry) * 8, 16u));
}

MtMemoryAllocator::Initializer::~Initializer() {
    if (mEntryNum != 0) {
        u32 v0_0 = mEntryNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            MtMemoryAllocator::Initializer::Entry* t0 = mAllocIdTable[i0_3];
            if (t0 == nullptr) {
                v1_0 = v0_0;
            } else {
                (*::MtMemory::mpAllocatorType)->memFree(static_cast<void*>(t0->obj_name));
                (*::MtMemory::mpAllocatorType)->memFree(static_cast<void*>(t0));
                v1_0 = mEntryNum;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    (*::MtMemory::mpAllocatorType)->memFree(static_cast<void*>(mAllocIdTable));
}

__attribute__((weak)) s32 MtMemoryAllocator::Initializer::createAllocatorInfo(u32 length, u32 alloc_id) {
    DDON_STUB("MtMemoryAllocator::Initializer::createAllocatorInfo")
    return {};
}

__attribute__((weak)) s32 MtMemoryAllocator::Initializer::addAllocatorInfo(MT_CTSTR name, u32 alloc_id) {
    DDON_STUB("MtMemoryAllocator::Initializer::addAllocatorInfo")
    return {};
}

u32 MtMemoryAllocator::Initializer::getAllocatorID(MT_CTSTR obj_name) const {
    u32 v0_8 = mEntryNum;
    u32 v2_0;
    if (v0_8 == 0) {
        v2_0 = 0x7FFFFFFF;
    } else {
        MtMemoryAllocator::Initializer::Entry* * v0_9 = mAllocIdTable;
        for (u32 ui = 0;;) {
            const MtMemoryAllocator::Initializer::Entry* p_entry = v0_9[ui];
            if (::strcmp(p_entry->obj_name, obj_name) != 0) {
                if ((ui + 1u) < v0_8) {
                    ui = ui + 1u;
                } else {
                    break;
                }
            } else {
                v2_0 = p_entry->alloc_id;
                return v2_0;
            }
        }
        v2_0 = 0x7FFFFFFF;
    }
    return v2_0;
}

