// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rAIConditionTree.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "../MT/MtString.h"
#include "cAIConditionTree.h"
#include "cAIObject.h"
#include "cResource.h"
#include "nAI.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIDEnum::getDTI() const {
    return cAIDEnum::DTI;
}

cAIDEnum::~cAIDEnum() {
}

void cAIDEnum::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mElementName", &mElementName, 8192u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
}

inline cAIDEnum::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIDEnum::MyDTI cAIDEnum::DTI("cAIDEnum", &::cAIObject::DTI, 24ul, 0u, 0u);

MtObject* cAIDEnum::MyDTI::newInstance() const {
    return new (16u) cAIDEnum;
}

const MtDTI& rAIConditionTree::getDTI() const {
    return rAIConditionTree::DTI;
}

rAIConditionTree::~rAIConditionTree() {
    if (mpTreeList != nullptr) {
        if (mTreeNum != 0) {
            u32 v0_0 = mTreeNum;
            TreeInfo* * v0_1 = mpTreeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpTreeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mTreeNum) {
                            break;
                        }
                        v0_0 = mTreeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpTreeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memFree(static_cast<void*>(mpTreeList));
    }
    mTreeNum = 0;
    mpTreeList = nullptr;
}

void rAIConditionTree::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTreeList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTree::getTree), reinterpret_cast<MT_MFUNC>(&::rAIConditionTree::setTree), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTree::getTreeNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTree::setTreeNum));
}

MT_CTSTR rAIConditionTree::getExt() const {
    return "cdt";
}

bool rAIConditionTree::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(2), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

void rAIConditionTree::clear() {
    if (mpTreeList != nullptr) {
        if (mTreeNum != 0) {
            u32 v0_0 = mTreeNum;
            TreeInfo* * v0_1 = mpTreeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpTreeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mTreeNum) {
                            break;
                        }
                        v0_0 = mTreeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpTreeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memFree(static_cast<void*>(mpTreeList));
    }
    mTreeNum = 0;
    mpTreeList = nullptr;
}

__attribute__((weak)) void rAIConditionTree::copy(rAIConditionTree* pResource) {
    DDON_STUB("rAIConditionTree::copy")
    /* stub */
}

void rAIConditionTree::move(rAIConditionTree* pResource) {
    if (mpTreeList != nullptr) {
        if (mTreeNum != 0) {
            u32 v0_0 = mTreeNum;
            TreeInfo* * v0_1 = mpTreeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpTreeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mTreeNum) {
                            break;
                        }
                        v0_0 = mTreeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpTreeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memFree(static_cast<void*>(mpTreeList));
    }
    mTreeNum = 0;
    mpTreeList = nullptr;
    if (createTreeList(pResource->mTreeNum)) {
        u32 v3_0 = pResource->mTreeNum;
        u32 v6_0;
        if (v3_0 != 0) {
            u32 v3_1 = mTreeNum;
            for (unsigned int i3_2 = 0;;) {
                if (i3_2 < v3_1) {
                    mpTreeList[i3_2] = pResource->mpTreeList[i3_2];
                }
                if (i3_2 < v3_0) {
                    pResource->mpTreeList[i3_2] = nullptr;
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    break;
                }
            }
            v6_0 = v3_0;
        } else {
            v6_0 = 0;
        }
        if (pResource->mpTreeList != nullptr) {
            if (v6_0 != 0) {
                u32 v7_0 = v6_0;
                TreeInfo* * v7_1 = pResource->mpTreeList;
                for (unsigned int i7_3 = 1;;) {
                    if (v7_1 != nullptr) {
                        if (v7_1[i7_3 - 1u] != nullptr) {
                            delete v7_1[i7_3 - 1u];
                            pResource->mpTreeList[i7_3 - 1u] = nullptr;
                            if (i7_3 >= pResource->mTreeNum) {
                                break;
                            }
                            v7_0 = pResource->mTreeNum;
                        } else {
                            if (i7_3 >= v7_0) {
                                break;
                            }
                        }
                    } else {
                        if (i7_3 >= v7_0) {
                            break;
                        }
                    }
                    v7_1 = pResource->mpTreeList;
                    i7_3 += 1u;
                }
            }
            MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memFree(static_cast<void*>(pResource->mpTreeList));
        }
        pResource->mTreeNum = 0;
        pResource->mpTreeList = nullptr;
    }
}

__attribute__((weak)) bool rAIConditionTree::createTreeList(u32 num) {
    if (mpTreeList != nullptr) {
        if (mTreeNum != 0) {
            u32 v0_0 = mTreeNum;
            TreeInfo* * v0_1 = mpTreeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpTreeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mTreeNum) {
                            break;
                        }
                        v0_0 = mTreeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpTreeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memFree(static_cast<void*>(mpTreeList));
    }
    mTreeNum = 0;
    mpTreeList = nullptr;
    if (num != 0) {
        void* t0 = MtMemoryAllocator::getAllocator(rAIConditionTree::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
        if ((mpTreeList = static_cast<TreeInfo* *>(t0)) != nullptr) {
            mTreeNum = num;
            memset(t0, 0, static_cast<size_t>(num) * 8);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

void rAIConditionTree::setTree(rAIConditionTree::TreeInfo* pTree, u32 index) {
    if (index < mTreeNum) {
        mpTreeList[index] = pTree;
    }
}

rAIConditionTree::TreeInfo* rAIConditionTree::getTree(u32 index) {
    if (index < mTreeNum) {
        return mpTreeList[index];
    } else {
        return nullptr;
    }
}

static auto ddon_emit_0x01bd9300 __attribute__((used)) = &rAIConditionTree::getTreeNum;

static auto ddon_emit_0x01bd9310 __attribute__((used)) = &rAIConditionTree::setTreeNum;

inline rAIConditionTree::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::MyDTI rAIConditionTree::DTI("rAIConditionTree", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rAIConditionTree::MyDTI::newInstance() const {
    return new (16u) rAIConditionTree;
}

const MtDTI& rAIConditionTree::TreeInfo::getDTI() const {
    return rAIConditionTree::TreeInfo::DTI;
}

rAIConditionTree::TreeInfo::~TreeInfo() {
    delete mpRootNode;
    mpRootNode = nullptr;
}

void rAIConditionTree::TreeInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mName", static_cast<MtObject*>(&mName), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRootNode", reinterpret_cast<MtObject* *>(&mpRootNode), 0u, 0u);
}

inline rAIConditionTree::TreeInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::TreeInfo::MyDTI rAIConditionTree::TreeInfo::DTI("rAIConditionTree::TreeInfo", &::MtObject::DTI, 40ul, 0u, 0u);

inline rAIConditionTree::TreeInfo::TreeInfo() {
    mpRootNode = nullptr;
}

__attribute__((weak)) MtObject* rAIConditionTree::TreeInfo::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rAIConditionTree::TreeInfo::DTI)->memAlloc(sizeof(rAIConditionTree::TreeInfo), 16u, rAIConditionTree::TreeInfo::DTI.getID())) rAIConditionTree::TreeInfo;
}

const MtDTI& rAIConditionTree::OperationNode::getDTI() const {
    return rAIConditionTree::OperationNode::DTI;
}

__attribute__((noinline)) rAIConditionTree::OperationNode::~OperationNode() {
}

void rAIConditionTree::OperationNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mOperator", &mOperator, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::OperationNode::getValueType() {
    return VTYPE_STATE;
}

__attribute__((weak)) void rAIConditionTree::OperationNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::OperationNode::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::OperationNode::getWorkNodeClassDTI() const {
    return cAIConditionTree::OperationWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::OperationNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Expression";
}

inline rAIConditionTree::OperationNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::OperationNode::MyDTI rAIConditionTree::OperationNode::DTI("rAIConditionTree::OperationNode", &::rAIConditionTreeNode::DTI, 72ul, 0u, 0u);

inline rAIConditionTreeNode::rAIConditionTreeNode() {
    mChildNum = 0;
    mpChildList = nullptr;
    mpParent = nullptr;
}

inline rAIConditionTree::OperationNode::OperationNode() {
    mOperator = 0;
}

__attribute__((weak)) MtObject* rAIConditionTree::OperationNode::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rAIConditionTree::OperationNode::DTI)->memAlloc(sizeof(rAIConditionTree::OperationNode), 16u, rAIConditionTree::OperationNode::DTI.getID())) rAIConditionTree::OperationNode;
}

const MtDTI& rAIConditionTree::StateNode::getDTI() const {
    return rAIConditionTree::StateNode::DTI;
}

rAIConditionTree::StateNode::~StateNode() {
    DDON_STUB("rAIConditionTree::StateNode::~StateNode")
    /* stub */
}

void rAIConditionTree::StateNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mState", &mState, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::StateNode::getValueType() {
    return VTYPE_STATE;
}

s32 rAIConditionTree::StateNode::getState() {
    return mState;
}

__attribute__((weak)) void rAIConditionTree::StateNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::StateNode::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::StateNode::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::StateNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

inline rAIConditionTree::StateNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::StateNode::MyDTI rAIConditionTree::StateNode::DTI("rAIConditionTree::StateNode", &::rAIConditionTreeNode::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::StateNode::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::StateNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTree::VariableNode::getDTI() const {
    return rAIConditionTree::VariableNode::DTI;
}

__attribute__((noinline)) rAIConditionTree::VariableNode::~VariableNode() {
}

void rAIConditionTree::VariableNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mVariable", static_cast<MtObject*>(&mVariable), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsBitNo", &mIsBitNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsArray", &mIsArray, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsDynamicIndex", &mIsDynamicIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexVariable", static_cast<MtObject*>(&mIndexVariable), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseEnumIndex", &mUseEnumIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexEnum", static_cast<MtObject*>(&mIndexEnum), 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::VariableNode::getValueType() {
    return VTYPE_UNDEFINED;
}

__attribute__((weak)) void rAIConditionTree::VariableNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::VariableNode::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::VariableNode::getWorkNodeClassDTI() const {
    return cAIConditionTree::VariableWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::VariableNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

MtUI* rAIConditionTree::VariableNode::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

__attribute__((weak)) void rAIConditionTree::VariableNode::createEditProperty(MtPropertyList& s) {
    DDON_STUB("rAIConditionTree::VariableNode::createEditProperty")
    /* stub */
}

bool rAIConditionTree::VariableNode::openEdit() {
    return true;
}

bool rAIConditionTree::VariableNode::closeEdit() {
    return true;
}

inline rAIConditionTree::VariableNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::VariableNode::MyDTI rAIConditionTree::VariableNode::DTI("rAIConditionTree::VariableNode", &::rAIConditionTreeNode::DTI, 200ul, 0u, 0u);

inline rAIConditionTree::VariableNode::VariableNode() {
    mIsBitNo = false;
    mIsArray = false;
    mIsDynamicIndex = false;
    mIndex = 0;
    mUseEnumIndex = false;
    mpOwnerInstance = nullptr;
}

__attribute__((weak)) MtObject* rAIConditionTree::VariableNode::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rAIConditionTree::VariableNode::DTI)->memAlloc(sizeof(rAIConditionTree::VariableNode), 16u, rAIConditionTree::VariableNode::DTI.getID())) rAIConditionTree::VariableNode;
}

const MtDTI& rAIConditionTree::VariableNode::VariableInfo::getDTI() const {
    return rAIConditionTree::VariableNode::VariableInfo::DTI;
}

rAIConditionTree::VariableNode::VariableInfo::~VariableInfo() {
}

void rAIConditionTree::VariableNode::VariableInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPropertyName", &mPropertyName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerName", &mOwnerName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSingletonOwner", &mIsSingletonOwner, 0u, 0u);
}

inline rAIConditionTree::VariableNode::VariableInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::VariableNode::VariableInfo::MyDTI rAIConditionTree::VariableNode::VariableInfo::DTI("rAIConditionTree::VariableNode::VariableInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rAIConditionTree::VariableNode::VariableInfo::MyDTI::newInstance() const {
    return new (16u) rAIConditionTree::VariableNode::VariableInfo;
}

const MtDTI& rAIConditionTree::ConstS32Node::getDTI() const {
    return rAIConditionTree::ConstS32Node::DTI;
}

rAIConditionTree::ConstS32Node::~ConstS32Node() {
    DDON_STUB("rAIConditionTree::ConstS32Node::~ConstS32Node")
    /* stub */
}

MtUI* rAIConditionTree::ConstS32Node::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

void rAIConditionTree::ConstS32Node::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsBitNo", &mIsBitNo, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstS32Node::getValueType() {
    if (!mIsBitNo) {
        return VTYPE_S32;
    } else {
        return VTYPE_BITNO;
    }
}

s32 rAIConditionTree::ConstS32Node::getS32() {
    if (mIsBitNo) {
        return static_cast<s32>(static_cast<unsigned int>(1ul << static_cast<unsigned long>(static_cast<unsigned char>(mValue) & 31)));
    } else {
        return mValue;
    }
}

s64 rAIConditionTree::ConstS32Node::getS64() {
    if (mIsBitNo) {
        return static_cast<s64>(1ul << static_cast<unsigned long>(static_cast<unsigned char>(mValue) & 63));
    } else {
        return mValue;
    }
}

s32 rAIConditionTree::ConstS32Node::getBitNo() {
    return mValue;
}

__attribute__((weak)) void rAIConditionTree::ConstS32Node::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstS32Node::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstS32Node::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstS32Node::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

void rAIConditionTree::ConstS32Node::createEditProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

inline rAIConditionTree::ConstS32Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstS32Node::MyDTI rAIConditionTree::ConstS32Node::DTI("rAIConditionTree::ConstS32Node", &::rAIConditionTreeNode::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::ConstS32Node::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::ConstS32Node::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTree::ConstS64Node::getDTI() const {
    return rAIConditionTree::ConstS64Node::DTI;
}

rAIConditionTree::ConstS64Node::~ConstS64Node() {
    DDON_STUB("rAIConditionTree::ConstS64Node::~ConstS64Node")
    /* stub */
}

MtUI* rAIConditionTree::ConstS64Node::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

__attribute__((weak)) void rAIConditionTree::ConstS64Node::createProperty(MtPropertyList& s) {
    DDON_STUB("rAIConditionTree::ConstS64Node::createProperty")
    /* stub */
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstS64Node::getValueType() {
    if (!mIsBitNo) {
        return VTYPE_S64;
    } else {
        return VTYPE_BITNO;
    }
}

s32 rAIConditionTree::ConstS64Node::getS32() {
    if (mIsBitNo) {
        return static_cast<s32>(static_cast<unsigned int>(1ul << static_cast<unsigned long>(static_cast<unsigned char>(mValue) & 31)));
    } else {
        return static_cast<s32>(static_cast<unsigned int>(mValue));
    }
}

s64 rAIConditionTree::ConstS64Node::getS64() {
    if (mIsBitNo) {
        return static_cast<s64>(1ul << static_cast<unsigned long>(static_cast<unsigned char>(mValue) & 63));
    } else {
        return mValue;
    }
}

s32 rAIConditionTree::ConstS64Node::getBitNo() {
    return static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 64));
}

__attribute__((weak)) void rAIConditionTree::ConstS64Node::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstS64Node::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstS64Node::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstS64Node::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

__attribute__((weak)) void rAIConditionTree::ConstS64Node::createEditProperty(MtPropertyList& s) {
    DDON_STUB("rAIConditionTree::ConstS64Node::createEditProperty")
    /* stub */
}

inline rAIConditionTree::ConstS64Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstS64Node::MyDTI rAIConditionTree::ConstS64Node::DTI("rAIConditionTree::ConstS64Node", &::rAIConditionTreeNode::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::ConstS64Node::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::ConstS64Node::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTree::ConstF32Node::getDTI() const {
    return rAIConditionTree::ConstF32Node::DTI;
}

__attribute__((noinline)) rAIConditionTree::ConstF32Node::~ConstF32Node() {
}

void rAIConditionTree::ConstF32Node::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstF32Node::getValueType() {
    return VTYPE_F32;
}

f32 rAIConditionTree::ConstF32Node::getF32() {
    return mValue;
}

f64 rAIConditionTree::ConstF32Node::getF64() {
    return static_cast<double>(mValue);
}

__attribute__((weak)) void rAIConditionTree::ConstF32Node::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstF32Node::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstF32Node::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstF32Node::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

void rAIConditionTree::ConstF32Node::createEditProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

inline rAIConditionTree::ConstF32Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstF32Node::MyDTI rAIConditionTree::ConstF32Node::DTI("rAIConditionTree::ConstF32Node", &::rAIConditionTreeNode::DTI, 72ul, 0u, 0u);

inline rAIConditionTree::ConstF32Node::ConstF32Node() {
    mValue = 0.0f;
}

__attribute__((weak)) MtObject* rAIConditionTree::ConstF32Node::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rAIConditionTree::ConstF32Node::DTI)->memAlloc(sizeof(rAIConditionTree::ConstF32Node), 16u, rAIConditionTree::ConstF32Node::DTI.getID())) rAIConditionTree::ConstF32Node;
}

const MtDTI& rAIConditionTree::ConstF64Node::getDTI() const {
    return rAIConditionTree::ConstF64Node::DTI;
}

rAIConditionTree::ConstF64Node::~ConstF64Node() {
    DDON_STUB("rAIConditionTree::ConstF64Node::~ConstF64Node")
    /* stub */
}

void rAIConditionTree::ConstF64Node::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstF64Node::getValueType() {
    return VTYPE_F64;
}

f32 rAIConditionTree::ConstF64Node::getF32() {
    return static_cast<float>(mValue);
}

f64 rAIConditionTree::ConstF64Node::getF64() {
    return mValue;
}

__attribute__((weak)) void rAIConditionTree::ConstF64Node::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstF64Node::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstF64Node::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstF64Node::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

void rAIConditionTree::ConstF64Node::createEditProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

inline rAIConditionTree::ConstF64Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstF64Node::MyDTI rAIConditionTree::ConstF64Node::DTI("rAIConditionTree::ConstF64Node", &::rAIConditionTreeNode::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::ConstF64Node::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::ConstF64Node::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTree::ConstStringNode::getDTI() const {
    return rAIConditionTree::ConstStringNode::DTI;
}

rAIConditionTree::ConstStringNode::~ConstStringNode() {
    DDON_STUB("rAIConditionTree::ConstStringNode::~ConstStringNode")
    /* stub */
}

void rAIConditionTree::ConstStringNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstStringNode::getValueType() {
    return VTYPE_STRING;
}

__attribute__((weak)) MT_CTSTR rAIConditionTree::ConstStringNode::getString() {
    DDON_STUB("rAIConditionTree::ConstStringNode::getString")
    return {};
}

__attribute__((weak)) void rAIConditionTree::ConstStringNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstStringNode::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstStringNode::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstStringNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

void rAIConditionTree::ConstStringNode::createEditProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

inline rAIConditionTree::ConstStringNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstStringNode::MyDTI rAIConditionTree::ConstStringNode::DTI("rAIConditionTree::ConstStringNode", &::rAIConditionTreeNode::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::ConstStringNode::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::ConstStringNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTree::ConstEnumNode::getDTI() const {
    return rAIConditionTree::ConstEnumNode::DTI;
}

rAIConditionTree::ConstEnumNode::~ConstEnumNode() {
    DDON_STUB("rAIConditionTree::ConstEnumNode::~ConstEnumNode")
    /* stub */
}

MtUI* rAIConditionTree::ConstEnumNode::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

void rAIConditionTree::ConstEnumNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
    s << MtProperty(static_cast<MtObject*>(this), "mValue", static_cast<MtObject*>(&mValue), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsBitNo", &mIsBitNo, 0u, 0u);
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTree::ConstEnumNode::getValueType() {
    if (!mIsBitNo) {
        return VTYPE_S32;
    } else {
        return VTYPE_BITNO;
    }
}

s32 rAIConditionTree::ConstEnumNode::getS32() {
    if (mIsBitNo) {
        return static_cast<s32>(static_cast<unsigned int>(1ul << static_cast<unsigned long>(static_cast<unsigned char>(mValue.mValue) & 31)));
    } else {
        return mValue.mValue;
    }
}

s32 rAIConditionTree::ConstEnumNode::getBitNo() {
    return mValue.mValue;
}

__attribute__((weak)) void rAIConditionTree::ConstEnumNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTree::ConstEnumNode::copy")
    /* stub */
}

const MtDTI& rAIConditionTree::ConstEnumNode::getWorkNodeClassDTI() const {
    return cAIConditionTree::ConstEnumWorkNode::DTI;
}

MT_CTSTR rAIConditionTree::ConstEnumNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Parameter";
}

void rAIConditionTree::ConstEnumNode::createEditProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mValue", static_cast<MtObject*>(&mValue), 0u, 0u);
}

bool rAIConditionTree::ConstEnumNode::openEdit() {
    return true;
}

bool rAIConditionTree::ConstEnumNode::closeEdit() {
    return true;
}

inline rAIConditionTree::ConstEnumNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTree::ConstEnumNode::MyDTI rAIConditionTree::ConstEnumNode::DTI("rAIConditionTree::ConstEnumNode", &::rAIConditionTreeNode::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTree::ConstEnumNode::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTree::ConstEnumNode::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rAIConditionTreeNode::getDTI() const {
    return rAIConditionTreeNode::DTI;
}

__attribute__((noinline)) rAIConditionTreeNode::~rAIConditionTreeNode() {
    if (mpChildList != nullptr) {
        for (u32 i = 0; i < mChildNum; ++i) {
            if (mpChildList != nullptr && mpChildList[i] != nullptr) {
                delete mpChildList[i];
                mpChildList[i] = nullptr;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTreeNode::DTI)->memFree(mpChildList);
    }
    mChildNum = 0;
    mpChildList = nullptr;
}

void rAIConditionTreeNode::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpChildList", reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChild), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::getChildNum), reinterpret_cast<MT_MFUNC>(&::rAIConditionTreeNode::setChildNum));
}

__attribute__((weak)) bool rAIConditionTreeNode::createChildList(u32 num) {
    if (mpChildList != nullptr) {
        if (mChildNum != 0) {
            u32 v0_0 = mChildNum;
            rAIConditionTreeNode* * v0_1 = mpChildList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpChildList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mChildNum) {
                            break;
                        }
                        v0_0 = mChildNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpChildList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(rAIConditionTreeNode::DTI)->memFree(static_cast<void*>(mpChildList));
    }
    mChildNum = 0;
    mpChildList = nullptr;
    if (num != 0) {
        void* t0 = MtMemoryAllocator::getAllocator(rAIConditionTreeNode::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
        if ((mpChildList = static_cast<rAIConditionTreeNode* *>(t0)) != nullptr) {
            mChildNum = num;
            memset(t0, 0, static_cast<size_t>(num) * 8);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

static auto ddon_emit_0x01bd92e0 __attribute__((used)) = &rAIConditionTreeNode::setChildNum;

static auto ddon_emit_0x01bd92d0 __attribute__((used)) = &rAIConditionTreeNode::getChildNum;

void rAIConditionTreeNode::setChild(rAIConditionTreeNode* pNode, u32 index) {
    if (index < mChildNum) {
        mpChildList[index] = pNode;
    }
}

rAIConditionTreeNode* rAIConditionTreeNode::getChild(u32 index) {
    if (index < mChildNum) {
        return mpChildList[index];
    } else {
        return nullptr;
    }
}

rAIConditionTreeNode::VALUE_TYPE rAIConditionTreeNode::getValueType() {
    return VTYPE_UNDEFINED;
}

bool rAIConditionTreeNode::getBool() {
    return false;
}

s32 rAIConditionTreeNode::getS32() {
    return 0;
}

s64 rAIConditionTreeNode::getS64() {
    return 0;
}

f32 rAIConditionTreeNode::getF32() {
    return 0.0f;
}

f64 rAIConditionTreeNode::getF64() {
    return 0.0;
}

s32 rAIConditionTreeNode::getBitNo() {
    return 0;
}

MT_CTSTR rAIConditionTreeNode::getString() {
    return nullptr;
}

s32 rAIConditionTreeNode::getState() {
    return 0;
}

__attribute__((weak)) void rAIConditionTreeNode::copy(rAIConditionTreeNode* pNode) {
    DDON_STUB("rAIConditionTreeNode::copy")
    /* stub */
}

bool rAIConditionTreeNode::openEdit() {
    return true;
}

bool rAIConditionTreeNode::closeEdit() {
    return true;
}

const MtDTI& rAIConditionTreeNode::getWorkNodeClassDTI() const {
    return cAIConditionTreeNode::DTI;
}

MT_CTSTR rAIConditionTreeNode::getUIClassName() const {
    return "cAIConditionTreeExpressionFormBase::Component";
}

inline rAIConditionTreeNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIConditionTreeNode::MyDTI rAIConditionTreeNode::DTI("rAIConditionTreeNode", &::cAIResource::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIConditionTreeNode::MyDTI::newInstance() const {
    DDON_STUB("rAIConditionTreeNode::MyDTI::newInstance")
    return nullptr;
}

