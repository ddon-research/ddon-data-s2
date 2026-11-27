// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCraftSkill.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "rCraftSkillCost.h"
#include "rCraftSkillSpd.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftSkill::getDTI() const {
    return cCraftSkill::DTI;
}

cCraftSkill::cCraftSkill() {
    init();
}

cCraftSkill::~cCraftSkill() {
    if (mpSpdResource != nullptr) {
        mpSpdResource->release();
        mpSpdResource = nullptr;
    }
    if (mpCostResource == nullptr) {
        return;
    }
    mpCostResource->release();
    mpCostResource = nullptr;
}

void cCraftSkill::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpSpdResource", "resource", reinterpret_cast<MT_MFUNC>(&::cCraftSkill::getSpdResource), reinterpret_cast<MT_MFUNC>(&::cCraftSkill::setSpdResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpCostResource", "resource", reinterpret_cast<MT_MFUNC>(&::cCraftSkill::getCostResource), reinterpret_cast<MT_MFUNC>(&::cCraftSkill::setCostResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* cCraftSkill::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cCraftSkill::setSpdResource(rCraftSkillSpd* pResource) {
    if (mpSpdResource != nullptr) {
        mpSpdResource->release();
        mpSpdResource = nullptr;
    }
    if (pResource == nullptr) {
        return;
    }
    mpSpdResource = pResource;
    pResource->addRef();
}

rCraftSkillSpd* cCraftSkill::getSpdResource() {
    return mpSpdResource;
}

void cCraftSkill::releaseSpdResource() {
    if (mpSpdResource == nullptr) {
        return;
    }
    mpSpdResource->release();
    mpSpdResource = nullptr;
}

void cCraftSkill::setCostResource(rCraftSkillCost* pResource) {
    if (mpCostResource != nullptr) {
        mpCostResource->release();
        mpCostResource = nullptr;
    }
    if (pResource == nullptr) {
        return;
    }
    mpCostResource = pResource;
    pResource->addRef();
}

rCraftSkillCost* cCraftSkill::getCostResource() {
    return mpCostResource;
}

void cCraftSkill::releaseCostResource() {
    if (mpCostResource == nullptr) {
        return;
    }
    mpCostResource->release();
    mpCostResource = nullptr;
}

u32 cCraftSkill::getSpdRate(u32 type, u32 Lv) {
    if (mpSpdResource != nullptr) {
        u32 list = mpSpdResource->getDataNum();
        if (Lv < list) {
            cCraftSkillSpdData* pRes = mpSpdResource->getData(Lv);
            if (pRes != nullptr) {
                return pRes->getRate(type);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) f32 cCraftSkill::getCostRate(u32 Total, u32 Num) {
    DDON_STUB("cCraftSkill::getCostRate")
    return {};
}

inline cCraftSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftSkill::MyDTI cCraftSkill::DTI("cCraftSkill", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCraftSkill::MyDTI::newInstance() const {
    return new (16u) cCraftSkill;
}

