// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsGroup.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsGroup::getDTI() const {
    return uCnsGroup::DTI;
}

uCnsGroup::uCnsGroup() {
    DDON_STUB("uCnsGroup::uCnsGroup")
    /* stub */
}

uCnsGroup::~uCnsGroup() {
    if (mGroupNum != 0) {
        u32 v0_0 = mGroupNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mppGroups[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mppGroups[i0_3];
                v1_0 = mGroupNum;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    MtMemoryAllocator::getAllocator(uCnsGroup::DTI)->memFree(static_cast<void*>(mppGroups));
    if (mpTmpResource != nullptr) {
        mpTmpResource->release();
        mpTmpResource = nullptr;
    }
}

void uCnsGroup::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsGroup::getResource), reinterpret_cast<MT_MFUNC>(&::uCnsGroup::setResourceNextMove), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uCnsGroup::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

void uCnsGroup::move() {
    this->uConstraint::move();
    mIsAdjustCalculated = false;
    if (mpTmpResource == nullptr) {
        return;
    }
    setResource(mpTmpResource);
    if (mpTmpResource != nullptr) {
        mpTmpResource->release();
        mpTmpResource = nullptr;
    }
    if (mGroupNum == 0) {
        return;
    }
    if (mpModel == nullptr) {
        return;
    }
    update();
}

__attribute__((weak)) void uCnsGroup::draw(cDraw* pDraw) {
}

cResource* uCnsGroup::getResource() {
    return nullptr;
}

void uCnsGroup::remove() {
    if (mGroupNum == 0) {
        removeConstraint();
        return;
    }
    u32 i = 0;
    do {
        mppGroups[i]->remove(false);
        i += 1u;
    } while (i < mGroupNum);
    removeConstraint();
}

void uCnsGroup::update() {
    remove();
    uModel* pModel = getModel();
    if (pModel != nullptr) {
        if (mGroupNum != 0) {
            if (!preupdate()) {
                return;
            } else {
                if (mGroupNum != 0) {
                    unsigned int i0_3 = 0;
                    u32 v1_0;
                    for (;;) {
                        mppGroups[i0_3]->update(false);
                        v1_0 = mGroupNum;
                        if ((i0_3 + 1u) < v1_0) {
                            i0_3 += 1u;
                        } else {
                            break;
                        }
                    }
                    if (v1_0 != 0) {
                        u32 v2_0 = v1_0;
                        unsigned int i2_3 = 0;
                        u32 v3_0;
                        for (;;) {
                            if (!mppGroups[i2_3]->mIsReady) {
                                v3_0 = v2_0;
                            } else {
                                setConstraint(pModel, static_cast<s32>((*mppGroups[i2_3]->mppNodes)->mJointNo));
                                v3_0 = mGroupNum;
                            }
                            if ((i2_3 + 1u) < v3_0) {
                                v2_0 = v3_0;
                                i2_3 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            return;
        }
    } else {
        return;
    }
    reset();
}

void uCnsGroup::setPri(u32 pri) {
    this->uConstraint::setPri(pri);
    u32 i = 0;
    if (mGroupNum != 0) {
        do {
            mppGroups[i]->setPri(pri + 1u);
            i += 1u;
        } while (i < mGroupNum);
    }
}

u32 uCnsGroup::getDependentJointNum() {
    return 0;
}

uModel::Joint* uCnsGroup::getDependentJoint(u32 idx) {
    return nullptr;
}

__attribute__((weak)) void uCnsGroup::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
}

__attribute__((weak)) void uCnsGroup::reset() {
}

void uCnsGroup::setModelUpdate(uModel* pModel) {
    setModel(pModel);
    if (mpModel != nullptr) {
        if (mGroupNum != 0) {
            update();
        } else {
            remove();
        }
    } else {
        remove();
    }
}

bool uCnsGroup::preupdate() {
    return true;
}

__attribute__((weak)) uCnsGroup::cGroup* uCnsGroup::createGroup(u32 idx) {
    DDON_STUB("uCnsGroup::createGroup")
    return nullptr;
}

__attribute__((weak)) void uCnsGroup::setGroupNum(u32 num) {
    DDON_STUB("uCnsGroup::setGroupNum")
    /* stub */
}

__attribute__((weak)) bool uCnsGroup::insertGroup(u32 idx) {
    DDON_STUB("uCnsGroup::insertGroup")
    return {};
}

__attribute__((weak)) bool uCnsGroup::deleteGroup(u32 idx) {
    DDON_STUB("uCnsGroup::deleteGroup")
    return {};
}

__attribute__((weak)) void uCnsGroup::setResourceNextMove(cResource* pRes) {
    DDON_STUB("uCnsGroup::setResourceNextMove")
    /* stub */
}

inline uCnsGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsGroup::MyDTI uCnsGroup::DTI("uCnsGroup", &::uConstraint::DTI, 176ul, 0u, 1u);

__attribute__((weak)) MtObject* uCnsGroup::MyDTI::newInstance() const {
    DDON_STUB("uCnsGroup::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsGroup::cGroup::getDTI() const {
    return uCnsGroup::cGroup::DTI;
}

uCnsGroup::cGroup::cGroup(uCnsGroup* pCnsGroup, u32 idx) {
    DDON_STUB("uCnsGroup::cGroup::cGroup")
    /* stub */
}

__attribute__((noinline)) uCnsGroup::cGroup::~cGroup() {
    DDON_STUB("uCnsGroup::cGroup::~cGroup")
    /* stub */
}

void uCnsGroup::cGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Update", static_cast<MT_MFUNC32>(&::uCnsGroup::cGroup::updateForProperty), 0u, 1u);
    s << MtProperty(static_cast<MtObject*>(this), "Remove", reinterpret_cast<MT_MFUNC32>(&::uCnsGroup::cGroup::remove), 0u, 1u);
    s << MtProperty(static_cast<MtObject*>(this), "Depend Reset", static_cast<MT_MFUNC>(&::uCnsGroup::cGroup::reset), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "NodeNum", &mNodeNum, 2051u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "Nodes", reinterpret_cast<MT_MFUNC>(&::uCnsGroup::cGroup::getNode), reinterpret_cast<MT_MFUNC>(&::uCnsGroup::cGroup::setNode), 160u, reinterpret_cast<MT_MFUNC>(&::uCnsGroup::cGroup::getNodeNum), reinterpret_cast<MT_MFUNC>(&::uCnsGroup::cGroup::setNodeNum));
}

MtUI* uCnsGroup::cGroup::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void uCnsGroup::cGroup::setPri(u32 pri) {
    u32 i = 0;
    if (mNodeNum != 0) {
        do {
            mpCnsChildlen[i].setPri(pri);
            i += 1u;
        } while (i < mNodeNum);
    }
}

bool uCnsGroup::cGroup::update(bool resetFlg) {
    mIsReady = false;
    uModel* pModel = mpCnsGroup->getModel();
    if (pModel != nullptr) {
        if (mNodeNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                cCnsChild* t0 = mpCnsChildlen;
                if (!t0[i0_3].setConstraint(pModel, static_cast<s32>(getNode(i0_3)->mJointNo))) {
                    remove(false);
                    return false;
                } else {
                    if ((i0_3 + 1u) < mNodeNum) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
            mIsReady = true;
            init();
        }
    }
    if (resetFlg) {
        mpCnsGroup->reset();
    }
    return mIsReady;
}

void uCnsGroup::cGroup::remove(bool resetFlg) {
    if (mNodeNum == 0) {
        mIsReady = false;
        if (resetFlg) {
            mpCnsGroup->reset();
        }
        return;
    }
    u32 i = 0;
    do {
        mpCnsChildlen[i].removeConstraint();
        i += 1u;
    } while (i < mNodeNum);
    mIsReady = false;
    if (resetFlg) {
        mpCnsGroup->reset();
    }
}

u32 uCnsGroup::cGroup::getDependentJointNum(u32 cnsIdx) {
    return mpCnsGroup->getDependentJointNum();
}

uModel::Joint* uCnsGroup::cGroup::getDependentJoint(u32 cnsIdx, u32 dependIdx) {
    return mpCnsGroup->getDependentJoint(dependIdx);
}

__attribute__((weak)) uCnsGroup::cNode* uCnsGroup::cGroup::createNode(u32 idx) {
    DDON_STUB("uCnsGroup::cGroup::createNode")
    return nullptr;
}

uCnsGroup::cNode* uCnsGroup::cGroup::getNode(u32 idx) {
    return mppNodes[idx];
}

__attribute__((weak)) void uCnsGroup::cGroup::setNodeNum(u32 num) {
    DDON_STUB("uCnsGroup::cGroup::setNodeNum")
    /* stub */
}

static auto ddon_emit_0x01bbd5c0 __attribute__((used)) = &uCnsGroup::cGroup::getNodeNum;

__attribute__((weak)) void uCnsGroup::cGroup::resizeCnsChildlen() {
    DDON_STUB("uCnsGroup::cGroup::resizeCnsChildlen")
    /* stub */
}

void uCnsGroup::cGroup::updateForProperty(u32 updateDepend) {
    update(updateDepend != 0);
}

inline uCnsGroup::cGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsGroup::cGroup::MyDTI uCnsGroup::cGroup::DTI("uCnsGroup::cGroup", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsGroup::cGroup::MyDTI::newInstance() const {
    DDON_STUB("uCnsGroup::cGroup::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsGroup::cNode::getDTI() const {
    return uCnsGroup::cNode::DTI;
}

uCnsGroup::cNode::cNode() {
    mJointNo = 255;
}

uCnsGroup::cNode::~cNode() {
}

void uCnsGroup::cNode::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
}

MtUI* uCnsGroup::cNode::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline uCnsGroup::cNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsGroup::cNode::MyDTI uCnsGroup::cNode::DTI("uCnsGroup::cNode", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsGroup::cNode::MyDTI::newInstance() const {
    DDON_STUB("uCnsGroup::cNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsGroup::cCnsChild::getDTI() const {
    return uCnsGroup::cCnsChild::DTI;
}

void uCnsGroup::cCnsChild::adjust(uModel::Joint* pjnt, uModel* pmod) {
    mpGroup->adjust(mIndex, pjnt, pmod);
}

cResource* uCnsGroup::cCnsChild::getResource() {
    return nullptr;
}

u32 uCnsGroup::cCnsChild::getDependentJointNum() {
    return mpGroup->getDependentJointNum(mIndex);
}

uModel::Joint* uCnsGroup::cCnsChild::getDependentJoint(u32 Idx) {
    return mpGroup->getDependentJoint(mIndex, Idx);
}

inline uCnsGroup::cCnsChild::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsGroup::cCnsChild::MyDTI uCnsGroup::cCnsChild::DTI("uCnsGroup::cCnsChild", &::uConstraint::DTI, 168ul, 0u, 2u);

__attribute__((weak)) MtObject* uCnsGroup::cCnsChild::MyDTI::newInstance() const {
    DDON_STUB("uCnsGroup::cCnsChild::MyDTI::newInstance")
    return nullptr;
}

