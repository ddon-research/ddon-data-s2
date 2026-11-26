// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nAI.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nAI::EnumProp::getDTI() const {
    return nAI::EnumProp::DTI;
}

nAI::EnumProp::~EnumProp() {
}

void nAI::EnumProp::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mEnumName", &mEnumName, 0u, 0u);
}

__attribute__((weak)) void nAI::EnumProp::open() {
    struct TABLE {
        MT_CTSTR name;
        s32 value;
    };
    mValue = 0;
    const MtDTI* pdti = MtDTI::from(mEnumName.ptr(), MtDTI::mDTI);
    if (pdti != nullptr) {
        MtObject* pEnum = pdti->newInstance();
        if (pEnum != nullptr) {
            MT_CTSTR n = mName.ptr();
            s32 num = 0;
            TABLE* pTable = (*reinterpret_cast<TABLE* (***)(MtObject*, s32&)>(pEnum))[6](pEnum, num);
            s32 value = 0;
            if (pTable != nullptr) {
                for (s32 i = 0; i < num; i++) {
                    if (strcmp(pTable[i].name, n) == 0) {
                        value = pTable[i].value;
                        break;
                    }
                }
            }
            mValue = value;
            delete pEnum;
        }
    }
}

__attribute__((weak)) nAI::EnumProp& nAI::EnumProp::operator=(nAI::EnumProp& p) {
    DDON_STUB("nAI::EnumProp::operator=")
    __builtin_unreachable();
}

inline nAI::EnumProp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nAI::EnumProp::MyDTI nAI::EnumProp::DTI("nAI::EnumProp", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nAI::EnumProp::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(::nAI::EnumProp::DTI)->memAlloc(sizeof(::nAI::EnumProp), 16u, ::nAI::EnumProp::DTI.getID())) ::nAI::EnumProp;
}

