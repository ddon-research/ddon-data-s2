// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rDDOModelMontage.h"

#include "../../MT/MtStream.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cBakeModel.h"
#include "cComponentManager.h"
#include "../../XFramework/cResource.h"
#include "cpEquip.h"
#include "../../XFramework/nDrawConstantTable.h"
#include "../../XFramework/nDrawMaterial.h"
#include "uArmor.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rDDOModelMontage::getDTI() const {
    return rDDOModelMontage::DTI;
}

inline MtAllocator* rDDOModelMontage::getAllocator() {
    return MtMemoryAllocator::getAllocator(rDDOModelMontage::DTI);
}

inline void* rDDOModelMontage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDDOModelMontage::DTI)->memAlloc(sz, align, rDDOModelMontage::DTI.getID());
}

inline void rDDOModelMontage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDDOModelMontage::DTI)->memFree(p_addr);
}

inline rDDOModelMontage::rDDOModelMontage() {
    setAttribute(16u);
    mpHeader = nullptr;
}

rDDOModelMontage::~rDDOModelMontage() {
    MtMemoryAllocator::getAllocator(rDDOModelMontage::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

void rDDOModelMontage::clear() {
    rDDOModelMontage::getAllocator()->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

__attribute__((weak)) bool rDDOModelMontage::load(MtStream& in) {
    u32 size = in.getLength();
    mpHeader = static_cast<HEADER*>(getAllocator()->memAlloc(size, 16u));
    in.read(mpHeader, size);
    if (mpHeader->magic != 0x00544d44u) {
        return false;
    }
    if (mpHeader->version != DATA_VERSION) {
        return false;
    }
    mpHeader->parts = reinterpret_cast<PARTS*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->parts));
    mpHeader->mindex = reinterpret_cast<MONTAGE**>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->mindex));
    mpHeader->montage = reinterpret_cast<MONTAGE*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->montage));
    mpHeader->color = reinterpret_cast<COLOR_INFO*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->color));
    mpHeader->hide = reinterpret_cast<HIDE_INFO*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->hide));
    mpHeader->se = reinterpret_cast<SE_INFO*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->se));
    mpHeader->body = reinterpret_cast<BODY_INFO*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->body));
    mpHeader->expression = reinterpret_cast<EXPRESSION_INFO*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->expression));
    for (u32 i = 0; i < mpHeader->montage_max; i++) {
        if (mpHeader->mindex[i] != nullptr) {
            mpHeader->mindex[i] = reinterpret_cast<MONTAGE*>(reinterpret_cast<uintptr>(mpHeader) + reinterpret_cast<uintptr>(mpHeader->mindex[i]));
        }
    }
    return true;
}

MT_CTSTR rDDOModelMontage::getExt() const {
    return "dmt";
}

__attribute__((weak)) u32 rDDOModelMontage::applyMontage(uModel* pmod, u32 no) {
    DDON_STUB("rDDOModelMontage::applyMontage")
    return {};
}

__attribute__((weak)) bool rDDOModelMontage::isModelTypeNP(u32 no) {
        if (!mpHeader) {
            return false;
        }
        if (mpHeader->montage_num == 0) {
            return false;
        }
        MONTAGE* pmtg = mpHeader->mindex[mpHeader->mindex[no % mpHeader->montage_max] ? (no % mpHeader->montage_max) : 0];
        if (!pmtg) {
            return false;
        }
        return mpHeader->modelType == MODEL_TYPE_NP;
}

__attribute__((weak)) u32 rDDOModelMontage::applyParts(uModel* pmod, u32 no) {
    DDON_STUB("rDDOModelMontage::applyParts")
    return {};
}

__attribute__((weak)) u32 rDDOModelMontage::applyPartsBJ(uModel* pmod, u32 no) {
    DDON_STUB("rDDOModelMontage::applyPartsBJ")
    return {};
}

__attribute__((weak)) u32 rDDOModelMontage::applyColor(uModel* pmod, u32 no, bool compel) {
    DDON_STUB("rDDOModelMontage::applyColor")
    return {};
}

__attribute__((weak)) u32 rDDOModelMontage::applyColorBJ(cBakeModel* pBakeModel, u32 no, bool compel) {
    DDON_STUB("rDDOModelMontage::applyColorBJ")
    return {};
}

__attribute__((weak)) u32 rDDOModelMontage::applyColorBJ_NPC(cBakeModel* pBakeModel, u32 no) {
    DDON_STUB("rDDOModelMontage::applyColorBJ_NPC")
    return {};
}

bool rDDOModelMontage::isBodyShakeBust(u32 no) {
    if (getModelType() <= 9u) {
        if (((658ul >> static_cast<unsigned long>(getModelType() & 31u)) & 1ul) != 0) {
            return static_cast<bool>(mpHeader->body[no].shakeBust);
        }
    }
    return true;
}

__attribute__((weak)) u32 rDDOModelMontage::getHideInfo(u32 no) {
    DDON_STUB("rDDOModelMontage::getHideInfo")
    return {};
}

bool rDDOModelMontage::isPlayExpression(u32 no) {
    if (getModelType() <= 9u) {
        if (((641ul >> static_cast<unsigned long>(getModelType() & 31u)) & 1ul) != 0) {
            return static_cast<bool>(mpHeader->expression[no].playExpression);
        }
    }
    return true;
}

u8 rDDOModelMontage::getSeType(u32 no) {
    return mpHeader->se[no].soundType;
}

__attribute__((weak)) void rDDOModelMontage::applyCoreParts(uModel* pmod, rDDOModelMontage::MONTAGE* pmtg) {
    DDON_STUB("rDDOModelMontage::applyCoreParts")
    /* stub */
}

__attribute__((weak)) void rDDOModelMontage::applyCoreColor(uModel* pmod, rDDOModelMontage::COLOR_INFO* pInfo) {
    DDON_STUB("rDDOModelMontage::applyCoreColor")
    /* stub */
}

__attribute__((weak)) void rDDOModelMontage::applyCoreColorBJ(cBakeModel* pBakeModel, rDDOModelMontage::COLOR_INFO* pInfo) {
    DDON_STUB("rDDOModelMontage::applyCoreColorBJ")
    /* stub */
}

inline rDDOModelMontage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDDOModelMontage::MyDTI rDDOModelMontage::DTI("rDDOModelMontage", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rDDOModelMontage::MyDTI::newInstance() const {
    return new (16u) rDDOModelMontage;
}

