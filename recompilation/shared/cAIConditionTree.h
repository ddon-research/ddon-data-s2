#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtString.h"
#include "cAIObject.h"
#include "rAIConditionTree.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class cAIDEnum;
class rAIConditionTree;
class rAIConditionTreeNode;

// Declarations
class cAIConditionTree;
class cAIConditionTreeNode;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIConditionTreeNode : public cAIObject
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cAIConditionTreeNode();
    virtual ~cAIConditionTreeNode();
    bool createChildList(u32 num);
    void setChildNum(u32);
    u32 getChildNum();
    void destroyChildList();
    void clearChildList();
    void setChild(cAIConditionTreeNode* pNode, u32 index);
    cAIConditionTreeNode* getChild(u32 index);
    void eraseChildAll();
    void eraseChild(u32 index);
    void setResource(rAIConditionTreeNode* pRes);
    // Address: 0x01bc70b0 - 0x01bc70b1 (1 bytes)
    virtual void setup() {}  // vtable slot 6
    virtual bool operate(cAIConditionTree* pOwner);  // vtable slot 7
    virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 8
    virtual bool getBool();  // vtable slot 9
    virtual s32 getS32();  // vtable slot 10
    virtual s64 getS64();  // vtable slot 11
    virtual f32 getF32();  // vtable slot 12
    virtual f64 getF64();  // vtable slot 13
    virtual s32 getBitNo();  // vtable slot 14
    virtual MT_CTSTR getString();  // vtable slot 15
    virtual s32 getState();  // vtable slot 16
protected:
    bool operateChild(cAIConditionTree* pOwner);
protected:
    rAIConditionTreeNode* mpResource;  // offset: 0x8
    u32 mChildNum;  // offset: 0x10
    cAIConditionTreeNode* * mpChildList;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cAIConditionTree : public cAIObject
{
public:
    class MyDTI;
    class TreeInfo;
    class OperationWorkNode;
    class ConstWorkNode;
    class ConstEnumWorkNode;
    class VariableWorkNode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class TreeInfo : public cAIObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        TreeInfo();
    public:
        cAIDEnum mName;  // offset: 0x8
        cAIConditionTreeNode* mpRootNode;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class OperationWorkNode : public cAIConditionTreeNode
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        OperationWorkNode();
        virtual ~OperationWorkNode();
        virtual bool operate(cAIConditionTree* pOwner);  // vtable slot 7
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 8
        virtual s32 getState();  // vtable slot 16
    protected:
        rAIConditionTreeNode::STATE_TYPE compare(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR, u32 ope);
        bool compareBoolean(cAIConditionTreeNode* pNodeL);
        bool compareEqual(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareLess(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareGreater(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareBitOnAnd(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareBitOnOr(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareAnd(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
        bool compareOr(cAIConditionTreeNode* pNodeL, cAIConditionTreeNode* pNodeR);
    protected:
        u32 mResult;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class ConstWorkNode : public cAIConditionTreeNode
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        ConstWorkNode();
        virtual ~ConstWorkNode();
        // Address: 0x01bc78a0 - 0x01bc78a1 (1 bytes)
        virtual void setup() {}  // vtable slot 6
        virtual bool operate(cAIConditionTree* pOwner);  // vtable slot 7
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 8
        virtual bool getBool();  // vtable slot 9
        virtual s32 getS32();  // vtable slot 10
        virtual s64 getS64();  // vtable slot 11
        virtual f32 getF32();  // vtable slot 12
        virtual f64 getF64();  // vtable slot 13
        virtual s32 getBitNo();  // vtable slot 14
        virtual MT_CTSTR getString();  // vtable slot 15
        virtual s32 getState();  // vtable slot 16
    public:
        static MyDTI DTI;
    };
public:
    class ConstEnumWorkNode : public cAIConditionTreeNode
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        ConstEnumWorkNode();
        virtual ~ConstEnumWorkNode();
        virtual void setup();  // vtable slot 6
        virtual bool operate(cAIConditionTree* pOwner);  // vtable slot 7
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 8
        virtual s32 getS32();  // vtable slot 10
    public:
        s32 mValue;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class VariableWorkNode : public cAIConditionTreeNode
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        VariableWorkNode();
        virtual ~VariableWorkNode();
        virtual void setup();  // vtable slot 6
        virtual bool operate(cAIConditionTree* pOwner);  // vtable slot 7
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 8
        virtual bool getBool();  // vtable slot 9
        virtual s32 getS32();  // vtable slot 10
        virtual s64 getS64();  // vtable slot 11
        virtual f32 getF32();  // vtable slot 12
        virtual f64 getF64();  // vtable slot 13
        virtual s32 getBitNo();  // vtable slot 14
        virtual MT_CTSTR getString();  // vtable slot 15
        virtual s32 getState();  // vtable slot 16
    protected:
        bool getVariableProperty(MtProperty& prop, const rAIConditionTree::VariableNode::VariableInfo& val, cAIConditionTree* pOwner);
    protected:
        rAIConditionTreeNode::VALUE_TYPE mValueType;  // offset: 0x20
        bool mBoolean;  // offset: 0x24
        s32 mS32;  // offset: 0x28
        f32 mF32;  // offset: 0x2c
        s64 mS64;  // offset: 0x30
        f64 mF64;  // offset: 0x38
        MtString mString;  // offset: 0x40
        MtProperty mProperty;  // offset: 0x48
        bool mHasProperty;  // offset: 0xb8
        u32 mIndexFromEnum;  // offset: 0xbc
    public:
        static MyDTI DTI;
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cAIConditionTree();
    virtual ~cAIConditionTree();
    void setReferenceObject(MtObject* pObj);
    MtPropertyList& getReferenceObjectProperty();
    bool setResource(rAIConditionTree* pResource);
    u32 getResultType();
    bool getBool();
    s32 getS32();
    s64 getS64();
    f32 getF32();
    f64 getF64();
    s32 getBitNo();
    MtString& getString();
    s32 getState();
    bool getResultByBool();
    bool operate(MT_CTSTR n);
    bool operate(u32 id);
    bool operate(TreeInfo* pTree);
    void setOwnerObject(MtObject*);
    MtObject* getOwnerObject();
protected:
    bool createTreeList(u32 num);
    void destroyTreeList();
    TreeInfo* searchTree(MT_CTSTR n);
    TreeInfo* searchTree(u32 id);
    cAIConditionTreeNode* createWorkNode(rAIConditionTreeNode* pResNode);
protected:
    rAIConditionTree* mpResource;  // offset: 0x8
    u32 mResultType;  // offset: 0x10
    bool mResultBool;  // offset: 0x14
    s32 mResultS32;  // offset: 0x18
    s64 mResultS64;  // offset: 0x20
    f32 mResultF32;  // offset: 0x28
    f64 mResultF64;  // offset: 0x30
    MtString mResultString;  // offset: 0x38
    u32 mTreeNum;  // offset: 0x40
    TreeInfo* mTreeList;  // offset: 0x48
    MtObject* mpReferenceObject;  // offset: 0x50
    MtObject* mpOwnerObject;  // offset: 0x58
    MtPropertyList mReferenceObjectProperty;  // offset: 0x60
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK20cAIConditionTreeNode5MyDTI11newInstanceEv at 0x01321cf0-0x01321d25, code DWARF attributes to no inlined copy
inline cAIConditionTreeNode::cAIConditionTreeNode() {
    this->mChildNum = static_cast<u32>(0);
    this->mpChildList = static_cast<cAIConditionTreeNode* *>(nullptr);
    this->mpResource = static_cast<rAIConditionTreeNode*>(nullptr);
}
