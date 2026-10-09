#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cAIObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPoint;
class MtPropertyList;
class MtStream;
class MtString;
class cAIFSM;
class cAIFSMLink;
class cAIFSMNodeProcess;
class rAIConditionTree;

// Declarations
class cAIFSMCluster;
class cAIFSMNode;
class rAIFSM;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cAIFSMCluster : public cAIResource
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
    cAIFSMCluster();
    virtual ~cAIFSMCluster();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void copy(cAIFSMCluster* pSource);  // vtable slot 7
    bool createNodeList(u32 num);
    void setNodeNum(u32 num);
    u32 getNodeNum();
    u32 getNodeNumWithSetting(u32 setting);
    void setNode(cAIFSMNode* pNode, u32 index);
    cAIFSMNode* getNode(u32 index);
    cAIFSMNode* searchNode(u32 id);
    cAIFSMNode* searchNodeByUniqueId(u32 id);
    void setInitialStateId(u32);
    u32 getInitialStateId();
    cAIFSMNode* getInitialStateNode();
    void setOwnerNodeUniqueId(u32);
    u32 getOwnerNodeUniqueId();
protected:
    void destroyNodeList();
    void clearNodeList();
    void eraseNodeAll();
    void eraseNode(u32 index);
private:
    u32 mId;  // offset: 0x8
    u32 mOwnerNodeUniqueId;  // offset: 0xc
    u32 mInitialStateId;  // offset: 0x10
    u32 mNodeNum;  // offset: 0x14
    cAIFSMNode* * mpNodeList;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cAIFSMNode : public cAIResource
{
    // inferred: cAIFSMCluster::searchNode names cAIFSMNode::mId
    friend class cAIFSMCluster;
public:
    enum SETTING
    {
        SET_AFTER_TRANSITION_CHECK = 1,
        SET_IMMEDIATE_NEXT_MOVE = 2,
        SET_GO_ON_BY_TRANSITION = 4,
        SET_TRANSITION_FROM_ALL_ONCE = 8,
        DEFAULT_SETTING = 1,
        NO_SETTING = 0,
    };
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
    cAIFSMNode();
    cAIFSMNode(MT_CTSTR nodeName);
    virtual ~cAIFSMNode();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void copy(cAIFSMNode* pSource);  // vtable slot 7
    u32 getId();
    void setUniqueId(u32);
    u32 getUniqueId();
    void setSubCluster(cAIFSMCluster*);
    cAIFSMCluster* getSubCluster();
    void setOwnerId(u32);
    u32 getOwnerId();
    bool createLinkList(u32 num);
    void destroyLinkList();
    void clearLinkList();
    void setLinkNum(u32 num);
    u32 getLinkNum();
    void setLink(cAIFSMLink* pLink, u32 index);
    cAIFSMLink* getLink(u32 index);
    bool createProcessList(u32 num);
    void setProcessNum(u32 num);
    u32 getProcessNum();
    void setProcess(cAIFSMNodeProcess* pProcess, u32 index);
    cAIFSMNodeProcess* getProcess(u32 index);
    void setUIPos(const MtPoint&);
    void setUIPos(s32, s32);
    s32 getUIPosX();
    s32 getUIPosY();
    void setColorType(u32);
    u32 getColorType();
    void setting(u32, bool);
    void setting(u32);
    u32 getSetting();
    u32 checkSetting(u32 s);
    void setUserAttribute(u32, bool);
    void setUserAttribute(u32);
    u32 checkUserAttribute(u32);
    bool existConditionTrainsitionFromAll();
    u32 getConditionTrainsitionFromAllId();
protected:
    void eraseLinkAll();
    void eraseLink(u32 index);
    void destroySubCluster();
    void destroyProcessList();
    void clearProcessList();
    void eraseProcessAll();
    void eraseProcess(u32 index);
private:
    void defaultInit();
protected:
    u32 mId;  // offset: 0x8
    u32 mUniqueId;  // offset: 0xc
    u32 mOwnerId;  // offset: 0x10
    u32 mLinkNum;  // offset: 0x14
    cAIFSMLink* * mpLinkList;  // offset: 0x18
    cAIFSMCluster* mpSubCluster;  // offset: 0x20
    u32 mProcessNum;  // offset: 0x28
    cAIFSMNodeProcess* * mpProcessList;  // offset: 0x30
    u32 mSetting;  // offset: 0x38
    u32 mUserAttribute;  // offset: 0x3c
    union
    {
    public:
        u32 mUIPos;  // offset: 0x0
        struct
        {
        public:
            u32 mUIPosX : 16;  // offset: 0x0
            u32 mUIPosY : 16;  // offset: 0x0
        };  // offset: 0x0
    };  // offset: 0x40
    u8 mColorType;  // offset: 0x44
    u8 mPad[3];  // offset: 0x45
    bool mExistConditionTrainsitionFromAll;  // offset: 0x48
    u32 mConditionTrainsitionFromAllId;  // offset: 0x4c
public:
    static const u32 SETTING_BIT_NUM = 4;
    static MyDTI DTI;
};

class rAIFSM : public cResource
{
    // inferred: cAIFSM::reset names rAIFSM::mpRootCluster
    friend class cAIFSM;
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
    rAIFSM();
    virtual ~rAIFSM();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void copy(rAIFSM* pSource);
    virtual void setup();  // vtable slot 16
    MT_CTSTR getName();
    void setOwnerObjectName(MT_CTSTR);
    MtString& getOwnerObjectName();
    bool createRootCluster();
    cAIFSMCluster* getRootCluster();
    rAIConditionTree* createConditionTree();
    rAIConditionTree* getConditionTree();
    u32 getHierarchyDepth(MtArray* pClusterList);
    void setFSMAttribute(u32, bool);
    u32 getFSMAttribute();
protected:
    void destroyRootCluster();
    void getHierarchyDepth(cAIFSMCluster* pCluster, u32& level, MtArray* pClusterList);
protected:
    MtString mOwnerObjectName;  // offset: 0x70
    cAIFSMCluster* mpRootCluster;  // offset: 0x78
    rAIConditionTree* mpConditionTree;  // offset: 0x80
    u32 mFSMAttribute;  // offset: 0x88
public:
    static const u32 DATA_VERSION = 2;
    static const u32 FSM_ATTR_UID_NODE = 1;
    static const u32 FSM_ATTR_UID_CLUSTER = 2;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK13cAIFSMCluster5MyDTI11newInstanceEv at 0x011e5d90-0x011e5dd2, code DWARF attributes to no inlined copy
inline cAIFSMCluster::cAIFSMCluster() {
    this->mId = static_cast<u32>(0);
    this->mOwnerNodeUniqueId = static_cast<u32>(0);
    this->mInitialStateId = static_cast<u32>(4294967295);
    this->mNodeNum = static_cast<u32>(0);
    this->mpNodeList = static_cast<cAIFSMNode* *>(nullptr);
}
