#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "cAIObject.h"
#include "cResource.h"
#include "nAI.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
namespace nAI { class EnumProp; }

// Declarations
class cAIDEnum;
class rAIConditionTree;
class rAIConditionTreeNode;

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

class cAIDEnum : public cAIObject
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
    cAIDEnum();
    cAIDEnum(MT_CTSTR, u32);
    virtual ~cAIDEnum();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setElementName(MT_CTSTR);
    MtString& getElementName();
    void setId(u32);
    u32 getId();
    const cAIDEnum& operator=(const cAIDEnum& id);
private:
    MtString mElementName;  // offset: 0x8
    u32 mId;  // offset: 0x10
public:
    static MyDTI DTI;
};

class rAIConditionTreeNode : public cAIResource
{
public:
    enum VALUE_TYPE
    {
        VTYPE_UNDEFINED = 0,
        VTYPE_BOOL = 1,
        VTYPE_S32 = 2,
        VTYPE_F32 = 3,
        VTYPE_BITNO = 4,
        VTYPE_STRING = 5,
        VTYPE_STATE = 6,
        VTYPE_S64 = 7,
        VTYPE_F64 = 8,
    };
    enum OPERATOR
    {
        OP_NONE = 0,
        OP_IS_TRUE = 1,
        OP_IS_FALSE = 2,
        OP_EQ = 3,
        OP_NEQ = 4,
        OP_LT = 5,
        OP_LE = 6,
        OP_GT = 7,
        OP_GE = 8,
        OP_BIT_ON_AND = 9,
        OP_BIT_ON_OR = 10,
        OP_0B = 11,
        OP_0C = 12,
        OP_0D = 13,
        OP_0E = 14,
        OP_0F = 15,
        OP_AND = 16,
        OP_OR = 17,
        OPERATOR_NUM = 18,
    };
    enum STATE_TYPE
    {
        STATE_FALSE = 0,
        STATE_TRUE = 1,
    };
public:
    class MyDTI;
    struct OPERATOR_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct OPERATOR_INFO
    {
    public:
        MT_CTSTR mName[2];  // offset: 0x0
        u32 mAttribute;  // offset: 0x10
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
    rAIConditionTreeNode();
    virtual ~rAIConditionTreeNode();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool createChildList(u32 num);
    void setChildNum(u32 num);
    u32 getChildNum();
    void destroyChildList();
    void clearChildList();
    void setChild(rAIConditionTreeNode* pNode, u32 index);
    rAIConditionTreeNode* getChild(u32 index);
    void eraseChildAll();
    void eraseChild(u32 index);
    void addChildXml(rAIConditionTreeNode* pNode);
    void setChildXml(rAIConditionTreeNode* pNode, u32 index);
    rAIConditionTreeNode* getChildXml(u32 index);
    void eraseChildXml(rAIConditionTreeNode* pNode);
    void removeChildXml(rAIConditionTreeNode* pNode);
    void replaceChildXml(rAIConditionTreeNode* pOldNode, rAIConditionTreeNode* pNewNode);
    MT_CTSTR getOperatorEditName(u32 ope, u32 style);
    u32 getOperatorEditAttribute(u32 ope);
    virtual VALUE_TYPE getValueType();  // vtable slot 6
    virtual bool getBool();  // vtable slot 7
    virtual s32 getS32();  // vtable slot 8
    virtual s64 getS64();  // vtable slot 9
    virtual f32 getF32();  // vtable slot 10
    virtual f64 getF64();  // vtable slot 11
    virtual s32 getBitNo();  // vtable slot 12
    virtual MT_CTSTR getString();  // vtable slot 13
    virtual s32 getState();  // vtable slot 14
    virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
    virtual bool openEdit();  // vtable slot 16
    virtual bool closeEdit();  // vtable slot 17
    virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
    virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
    // Address: 0x01bd96b0 - 0x01bd96b1 (1 bytes)
    virtual void createEditProperty(MtPropertyList& s) {}  // vtable slot 20
protected:
    void destroyChildListXml();
protected:
    u32 mChildNum;  // offset: 0x8
    rAIConditionTreeNode* * mpChildList;  // offset: 0x10
    MtArray mChildListXml;  // offset: 0x18
    rAIConditionTreeNode* mpParent;  // offset: 0x38
public:
    static MyDTI DTI;
protected:
    static const OPERATOR_INFO mOperatorEditInfo[];
};

class rAIConditionTree : public cResource
{
public:
    class MyDTI;
    class TreeInfo;
    class OperationNode;
    class StateNode;
    class VariableNode;
    class ConstS32Node;
    class ConstS64Node;
    class ConstF32Node;
    class ConstF64Node;
    class ConstStringNode;
    class ConstEnumNode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class TreeInfo : public MtObject
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
        virtual ~TreeInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void destroyRootNode();
        const rAIConditionTree::TreeInfo& operator=(const rAIConditionTree::TreeInfo& tree);
        bool openEdit();
        bool closeEdit();
        void setTreeName(MT_CTSTR);
        MtString& getTreeName();
        u32 getTreeId();
        void setRootNode(rAIConditionTreeNode*);
        rAIConditionTreeNode* getRootNode();
    public:
        cAIDEnum mName;  // offset: 0x8
        rAIConditionTreeNode* mpRootNode;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class OperationNode : public rAIConditionTreeNode
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
        OperationNode();
        virtual ~OperationNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setOperator(u32);
        u32 getOperator();
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
    protected:
        u32 mOperator;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
public:
    class StateNode : public rAIConditionTreeNode
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
        StateNode(s32 s);
        virtual ~StateNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual s32 getState();  // vtable slot 14
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
    protected:
        s32 mState;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
public:
    class VariableNode : public rAIConditionTreeNode
    {
    public:
        class MyDTI;
        class VariableInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class VariableInfo : public MtObject
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
            VariableInfo();
            virtual ~VariableInfo();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            const rAIConditionTree::VariableNode::VariableInfo& operator=(const rAIConditionTree::VariableNode::VariableInfo& v);
            bool operator==(const rAIConditionTree::VariableNode::VariableInfo&);
            bool operator!=(const rAIConditionTree::VariableNode::VariableInfo&);
        public:
            MtString mPropertyName;  // offset: 0x8
            MtString mOwnerName;  // offset: 0x10
            bool mIsSingletonOwner;  // offset: 0x18
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
        VariableNode();
        virtual ~VariableNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setVariable(MT_CTSTR, bool, MT_CTSTR);
        void setArray(u32);
        void setArray(MT_CTSTR, bool, MT_CTSTR);
        void setBitNoMode(bool);
        bool isBitNo();
        VariableInfo& getVariable();
        bool isArray();
        bool isDynamicIndex();
        u32 getIndex();
        VariableInfo& getIndexVariable();
        bool useEnumIndex();
        nAI::EnumProp& getIndexEnum();
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
        virtual bool openEdit();  // vtable slot 16
        virtual bool closeEdit();  // vtable slot 17
    protected:
        VariableInfo mVariable;  // offset: 0x40
        bool mIsBitNo;  // offset: 0x60
        bool mIsArray;  // offset: 0x61
        bool mIsDynamicIndex;  // offset: 0x62
        u32 mIndex;  // offset: 0x64
        VariableInfo mIndexVariable;  // offset: 0x68
        bool mUseEnumIndex;  // offset: 0x88
        nAI::EnumProp mIndexEnum;  // offset: 0x90
        MtObject* mpOwnerInstance;  // offset: 0xb8
        MtString mOwnerIndexName;  // offset: 0xc0
    public:
        static MyDTI DTI;
    };
public:
    class ConstS32Node : public rAIConditionTreeNode
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
        ConstS32Node();
        virtual ~ConstS32Node();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setBitNoMode(bool);
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual s32 getS32();  // vtable slot 8
        virtual s64 getS64();  // vtable slot 9
        void setS32(s32);
        virtual s32 getBitNo();  // vtable slot 12
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
    public:
        s32 mValue;  // offset: 0x40
        bool mIsBitNo;  // offset: 0x44
        MtString mNeighborPropName;  // offset: 0x48
        static MyDTI DTI;
    };
public:
    class ConstS64Node : public rAIConditionTreeNode
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
        ConstS64Node();
        virtual ~ConstS64Node();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setBitNoMode(bool);
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual s32 getS32();  // vtable slot 8
        virtual s64 getS64();  // vtable slot 9
        void setS64(s64);
        virtual s32 getBitNo();  // vtable slot 12
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
    public:
        s64 mValue;  // offset: 0x40
        bool mIsBitNo;  // offset: 0x48
        MtString mNeighborPropName;  // offset: 0x50
        static MyDTI DTI;
    };
public:
    class ConstF32Node : public rAIConditionTreeNode
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
        ConstF32Node();
        virtual ~ConstF32Node();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual f32 getF32();  // vtable slot 10
        virtual f64 getF64();  // vtable slot 11
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
    public:
        f32 mValue;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ConstF64Node : public rAIConditionTreeNode
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
        ConstF64Node();
        virtual ~ConstF64Node();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual f32 getF32();  // vtable slot 10
        virtual f64 getF64();  // vtable slot 11
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
    public:
        f64 mValue;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ConstStringNode : public rAIConditionTreeNode
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
        ConstStringNode();
        virtual ~ConstStringNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual MT_CTSTR getString();  // vtable slot 13
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
    public:
        MtString mValue;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ConstEnumNode : public rAIConditionTreeNode
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
        ConstEnumNode();
        virtual ~ConstEnumNode();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setBitNoMode(bool);
        virtual rAIConditionTreeNode::VALUE_TYPE getValueType();  // vtable slot 6
        virtual s32 getS32();  // vtable slot 8
        void setS32(s32);
        virtual s32 getBitNo();  // vtable slot 12
        virtual void copy(rAIConditionTreeNode* pNode);  // vtable slot 15
        virtual const MtDTI& getWorkNodeClassDTI() const;  // vtable slot 18
        virtual MT_CTSTR getUIClassName() const;  // vtable slot 19
        virtual void createEditProperty(MtPropertyList& s);  // vtable slot 20
        nAI::EnumProp& getEnumValue();
        virtual bool openEdit();  // vtable slot 16
        virtual bool closeEdit();  // vtable slot 17
    public:
        nAI::EnumProp mValue;  // offset: 0x40
        bool mIsBitNo;  // offset: 0x68
        MtString mNeighborPropName;  // offset: 0x70
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
    rAIConditionTree();
    virtual ~rAIConditionTree();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void clear();  // vtable slot 15
    virtual void copy(rAIConditionTree* pResource);  // vtable slot 16
    virtual void move(rAIConditionTree* pResource);  // vtable slot 17
    bool createTreeList(u32 num);
    void setTree(TreeInfo* pTree, u32 index);
    TreeInfo* getTree(u32 index);
    TreeInfo* searchTree(MT_CTSTR n);
    TreeInfo* searchTree(u32 id);
    u32 getTreeNum();
    void setTreeNum(u32 num);
protected:
    void destroyTreeList();
    void clearTreeList();
    void eraseTreeAll();
    void eraseTree(u32 index);
protected:
    u32 mTreeNum;  // offset: 0x70
    TreeInfo* * mpTreeList;  // offset: 0x78
public:
    static const u32 DATA_VERSION = 2;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK16rAIConditionTree5MyDTI11newInstanceEv at 0x0136cc70-0x0136cca4, code DWARF attributes to no inlined copy
inline rAIConditionTree::rAIConditionTree() {
    this->::cResource::mAttr = static_cast<u32>(18);
    this->mTreeNum = static_cast<u32>(0);
    this->mpTreeList = static_cast<rAIConditionTree::TreeInfo* *>(nullptr);
}
