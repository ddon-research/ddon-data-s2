#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cAIConditionTree.h"
#include "cAIObject.h"
#include "cAIUserProcess.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cAIConditionTree;
class cAICopiableParameter;
class cAIFSMCluster;
class cAIFSMNode;
class cFSMCore;
class rAIFSM;

// Declarations
class cAIFSM;
class cAIFSMData;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cAIFSMData : public cAIObject
{
public:
    class MyDTI;
    class Core;
    class Cluster;
    class ClusterLog;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Core : public MtObject
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
        Core();
        Core(const cAIFSMData::Core& c);
        virtual ~Core();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool createClusterList(u32 num);
        void destroyClusterList();
        u32 getClusterNum() const;
        void setClusterNum(u32 num);
        cAIFSMData::Cluster* getCluster(u32 index) const;
        void setCluster(cAIFSMData::Cluster* pCluster, u32 index);
        bool createClusterLogList(u32 num);
        void destroyClusterLogList();
        u32 getClusterLogNum() const;
        void setClusterLogNum(u32 num);
        cAIFSMData::ClusterLog* getClusterLog(u32 index) const;
        void setClusterLog(cAIFSMData::ClusterLog* pCluster, u32 index);
        u32 calcStreamDataSize();
        u32 covertToStreamData(u32* stream);
        u32 covertFromStreamData(const u32* stream);
        void copy(const cAIFSMData::Core& source);
    public:
        u64 mResourceId;  // offset: 0x8
        s32 mIFree[8];  // offset: 0x10
        f32 mFFree[8];  // offset: 0x30
        u32 mClusterNum;  // offset: 0x50
        cAIFSMData::Cluster* * mpCluster;  // offset: 0x58
        u32 mClusterLogNum;  // offset: 0x60
        cAIFSMData::ClusterLog* * mpClusterLog;  // offset: 0x68
        static MyDTI DTI;
    };
public:
    class Cluster : public MtObject
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
        Cluster();
        Cluster(const cAIFSMData::Cluster& c);
        // Address: 0x01b6abe0 - 0x01b6abe1 (1 bytes)
        virtual ~Cluster() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(const cAIFSMData::Cluster& source);
    public:
        u32 mId;  // offset: 0x8
        u32 mNextId;  // offset: 0xc
        u32 mStatus;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class ClusterLog : public MtObject
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
        ClusterLog();
        ClusterLog(const cAIFSMData::ClusterLog& c);
        virtual ~ClusterLog();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool createTransitionOnceStateList(u32 num);
        void destroyTransitionOnceStateList();
        u32 getTransitionOnceState(u32 index);
        void setTransitionOnceState(u32 id, u32 index);
        u32 getTransitionOnceStateNum() const;
        void setTransitionOnceStateNum(u32 num);
        void copy(const cAIFSMData::ClusterLog& source);
    public:
        u32 mClusterId;  // offset: 0x8
        u32 mTransitionOnceStateNum;  // offset: 0xc
        u32* mTransitionOnceStateList;  // offset: 0x10
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
    cAIFSMData();
    cAIFSMData(const cAIFSMData& c);
    virtual ~cAIFSMData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void clear();
    bool createCoreList(u32 num);
    void destroyCoreList();
    u32 covertToStreamData();
    bool covertFromStreamData(const u32* stream);
    void destroyStreamData();
    Core* getCore(u32 index) const;
    u32 getCoreNum() const;
    void setCoreNum(u32 num);
    void setCore(Core* pCore, u32 index);
    u32 getStreamDataSize() const;
    const u32* getStreamData();
    void copyStreamData(u32* buf);
    void copy(const cAIFSMData& source);
    const cAIFSMData& operator=(const cAIFSMData&);
public:
    s32 mIFree[8];  // offset: 0x8
    f32 mFFree[8];  // offset: 0x28
    u32 mCoreNum;  // offset: 0x48
    Core* * mpCore;  // offset: 0x50
    u32 mStreamDataSize;  // offset: 0x58
    u32* mStreamData;  // offset: 0x60
    static const u32 ST_TRANSITION_OCCUR = 1;
    static const u32 STRM_SIZE_BASE = 18;
    static const u32 STRM_SIZE_CORE_BASE = 3;
    static const u32 STRM_SIZE_CLUSTER = 3;
    static const u32 STRM_SIZE_TRANSITION_ONCE = 1;
    static MyDTI DTI;
};

class cAIFSM : public cAIObject
{
    // inferred: cFSMCore::setupFSM names cFSMCore::mFSM.mpOwner
    friend class cFSMCore;
public:
    class MyDTI;
    class Core;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Core : public MtObject
    {
        // inferred: cAIFSM::reset names cAIFSM::Core::mClusterStackBottom
        friend class cAIFSM;
    public:
        enum STATUS
        {
            ST_WORK = 0,
            ST_SLEEP = 1,
        };
    public:
        class MyDTI;
        class ClusterDriveInfo;
        class ClusterWork;
        class ClearTransitionFromAllOnceParam;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class ClusterDriveInfo : public cAIObject
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
            ClusterDriveInfo();
            void clear();
            u32 getNodeIndex();
        public:
            cAIFSMCluster* mpCluster;  // offset: 0x8
            cAIFSM::Core::ClusterWork* mpClusterWork;  // offset: 0x10
            cAIFSMNode* mpNode;  // offset: 0x18
            cAIFSMNode* mpNextNode;  // offset: 0x20
            bool mOccurTransition;  // offset: 0x28
            bool mIsTransitionFromAll;  // offset: 0x29
            bool mPassTransitionCheck;  // offset: 0x2a
            bool mRequestUpdateProcess;  // offset: 0x2b
            bool mIsUpdated;  // offset: 0x2c
            s32 mConditionWaitFlag;  // offset: 0x30
            f32 mConditionWaitTime;  // offset: 0x34
            u32 mDepth;  // offset: 0x38
            u32 mCurrentProcessNo;  // offset: 0x3c
            static MyDTI DTI;
        };
    public:
        class ClusterWork : public cAIObject
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
            ClusterWork();
            virtual ~ClusterWork();
            void clear();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            bool setCluster(cAIFSMCluster* pCluster);
            cAIFSMCluster* getCluster();
            bool existsTransitionOnceState(u32 id);
            void registerTransitionOnceState(u32 id);
            bool clearTransitionOnceState(u32 id);
            void clearTransitionOnceStateAll();
            u32 getTransitionOnceStateNum();
            u32 getTransitionOnceState(u32 index);
        private:
            bool createTransitionOnceStateList(u32 len);
            void destroyTransitionOnceStateList();
        private:
            cAIFSMCluster* mpCluster;  // offset: 0x8
            u32 mTransitionOnceStateListLength;  // offset: 0x10
            u32 mTransitionOnceStateNum;  // offset: 0x14
            u32* mTransitionOnceStateList;  // offset: 0x18
        public:
            static MyDTI DTI;
        };
    public:
        class ClearTransitionFromAllOnceParam : public cAICopiableParameter
        {
        public:
            enum CLEAR_TYPE
            {
                CT_ALL = 0,
                CT_CLUSTER = 1,
                CT_CLUSTER_ALL = 2,
                CT_DIRECT = 3,
                CT_DIRECT_ALL = 4,
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
            ClearTransitionFromAllOnceParam();
            virtual ~ClearTransitionFromAllOnceParam();
            virtual void copy(cAICopiableParameter* pParam);  // vtable slot 6
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        public:
            u32 mType;  // offset: 0x8
            u32 mStateID;  // offset: 0xc
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
        Core(cAIFSM* pOwner);
        virtual ~Core();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createCoreProperty(MtPropertyList& s, bool withViewer);
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void reset();
        void exit();
        void move();
        void setResource(rAIFSM* pRes);
        rAIFSM* getResource();
        void releaseResource();
        bool isResourceUpdate();
        void reloadResource();
        void setReset(bool flag);
        bool isReset();
        void setUpdateNode(bool flag);
        bool isUpdateState();
        bool createClusterStack(u32 size);
        void setOwner(cAIFSM* po);
        cAIFSM* getOwner();
        void setId(u32 id);
        u32 getId();
        u32 getCurrentNodeList(cAIFSMNode* * pList, u32 listLength);
        cAIFSMNode* getCurrentNode();
        void setDefaultUpdateFunc(cAIUserProcessCallback::CALLBACK_FUNC f);
        void setConditionOperatorOwner(MtObject*);
        void waitConditionCheck();
        void permitConditionCheck();
        void setStatus(u32 st);
        u32 getStatus();
        void setAttribute(u32 attr, bool flg);
        void setIFree(s32 value, u32 index);
        s32 getIFree(u32 index);
        void setFFree(f32 value, u32 index);
        f32 getFFree(u32 index);
        s32 getCurrentActionNo();
        s32 getCurrentClusterDepth();
        bool exportWorkData(cAIFSMData::Core& outdata);
        bool importWorkData(const cAIFSMData::Core& indata);
        u32 queryCurrentNodeIDList(u32* list, u32 length);
        u32 queryCurrentNodeIndexList(u32* list, u32 length);
        u32 getCurrentNodeID();
        u32 getCurrentNodeIndex();
        void changeCurrentNode(u32 id);
        void changeCurrentNodeByIndex(u32 index);
        bool createClusterWorkList(u32 num);
        void clearClusterWork();
        u32 stateUpdate_ClearTransitionFromAllOnce(MtObject* pParam, MtObject* pCaller);
    protected:
        void createInfoFromResource(rAIFSM* pRes);
        bool checkTransition(ClusterDriveInfo* pInfo);
        cAIFSMNode* checkNodeTransition(cAIFSMCluster* pCluster, cAIFSMNode* pNode);
        void evStateUpdate(ClusterDriveInfo* pInfo);
        void evState(ClusterDriveInfo* pInfo);
        void evStateExit(u32 index);
        void evStatusChange();
        void evExport(ClusterDriveInfo* pInfo);
        void evImport(ClusterDriveInfo* pInfo);
        void callProcessUpdate(ClusterDriveInfo* pInfo);
        void callProcessState(ClusterDriveInfo* pInfo);
        void callProcessExit(ClusterDriveInfo* pInfo);
        void callProcessStatusChange(ClusterDriveInfo* pInfo);
        void callProcessExport(ClusterDriveInfo* pInfo);
        void callProcessImport(ClusterDriveInfo* pInfo);
        void destroyClusterStack();
        void clearClusterStack();
        bool pushCluster(cAIFSMCluster* pCluster);
        bool updateNodeInClusterStack(cAIFSMNode* pNode, u32 index, bool mustUpdate);
        u32 getCurrentClusterID();
        void destroyClusterWorkList();
        u32 getClusterWorkNum();
        void setClusterWorkNum(u32);
        ClusterWork* getClusterWork(u32 index);
        void setClusterWork(ClusterWork*, u32);
        ClusterWork* searchClusterWork(u32 id);
        void clearTransitionOnceStateAll();
        void clearTransitionOnceState(u32 clusterID, bool withSubCluster);
        void clearTransitionOnceState(u32 clusterID, u32 nodeID, bool withSubCluster);
        void clearTransitionOnceState(ClusterWork* pClusterWork, u32 nodeID, bool withSubCluster);
        void clearTransitionOnceStateByID(u32 stateID, bool withSubCluster);
    protected:
        u32 mId;  // offset: 0x8
        rAIFSM* mpResource;  // offset: 0x10
        bool mIsReset;  // offset: 0x18
        bool mIsUpdateNode;  // offset: 0x19
        bool mIsImported;  // offset: 0x1a
        u32 mClusterStackSize;  // offset: 0x1c
        ClusterDriveInfo* mClusterStack;  // offset: 0x20
        u32 mClusterStackBottom;  // offset: 0x28
        ClusterDriveInfo* mpCurrentClusterStack;  // offset: 0x30
        u32 mClusterWorkNum;  // offset: 0x38
        ClusterWork* mClusterWorkList;  // offset: 0x40
        cAIFSM* mpOwner;  // offset: 0x48
        cAIConditionTree mConditionOperator;  // offset: 0x50
        cAIUserProcessCallback::CALLBACK_FUNC mpDefaultUpdateFunc;  // offset: 0xc0
        u32 mStatus;  // offset: 0xd0
        u32 mAttribute;  // offset: 0xd4
        s32 mIFree[8];  // offset: 0xd8
        f32 mFFree[8];  // offset: 0xf8
    public:
        static const u32 ATTR_ENABLE_TRANSITION = 1;
        static const u32 ATTR_ENABLE_TRANSITION_FROM_ALL = 2;
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
    cAIFSM();
    virtual ~cAIFSM();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool createCore(u32 num);
    bool setResource(rAIFSM* pRes, u32 index);
    rAIFSM* getResource(u32 index);
    void releaseResource();
    void releaseResource(u32 index);
    bool isResourceUpdate(u32 index);
    bool isResourceUpdate();
    void reloadResource(u32 index);
    void reloadResource();
    void checkResourceUpdateAndReload();
    bool setup(MtObject* po, MT_CTSTR resPath, u32 index, u32 coreStatus);
    bool setup(MtObject* po, rAIFSM* pRes, u32 index, u32 coreStatus);
    u32 getCoreNum();
    Core* getCore(u32 index);
    void resetCore(u32 index);
    u32 getCurrentNodeList(cAIFSMNode* * pList, u32 listLength, u32 index);
    cAIFSMNode* getCurrentNode(u32 index);
    void setDefaultUpdateFunc(cAIUserProcessCallback::CALLBACK_FUNC func, u32 index);
    void setCoreStatus(u32 status, u32 index);
    u32 getCoreStatus(u32 index);
    void setCoreAttribute(u32 attr, bool flg, u32 index);
    void exit();
    void exit(u32 index);
    void setOwner(MtObject* po);
    MtObject* getOwner();
    void setConditionWaitTime(f32);
    f32 getConditionWaitTime();
    bool isConditionCheckWait();
    bool isConditionCheckWaitTimeOut();
    void clearConditionCheckWaitTimeOut();
    void setIFree(s32 value, u32 index);
    s32 getIFree(u32 index);
    void setFFree(f32 value, u32 index);
    f32 getFFree(u32 index);
    bool exportWorkData(cAIFSMData& outdata);
    bool importWorkData(const cAIFSMData& indata);
    u32 queryCurrentNodeIDList(u32* list, u32 length, u32 index);
    u32 getCurrentNodeID(u32 index);
    u32 getCurrentNodeIndex(u32 index);
    void changeCurrentNode(u32 id, u32 index);
    void changeCurrentNodeByIndex(u32 nodeIndex, u32 index);
    Core* getCurrentCore();
    virtual void reset();  // vtable slot 6
    virtual void reset(u32 index);  // vtable slot 7
    virtual void move();  // vtable slot 8
    static void registerSystemAction();
protected:
    void destroyCore();
    void resetCore();
    void moveCore();
    // Address: 0x01b6ae20 - 0x01b6ae21 (1 bytes)
    virtual void beginCore(Core* pCore) {}  // vtable slot 9
    // Address: 0x01b6ae30 - 0x01b6ae31 (1 bytes)
    virtual void endCore(Core* pCore) {}  // vtable slot 10
    void setCoreNum(u32 num);
    void setCore(Core* pc, u32 index);
    void setStatus(u32 status, bool flag);
protected:
    MtObject* mpOwner;  // offset: 0x8
    u32 mCoreNum;  // offset: 0x10
    Core* mCoreList;  // offset: 0x18
    Core* mpCurrentCore;  // offset: 0x20
    f32 mConditionWaitTime;  // offset: 0x28
    u32 mStatus;  // offset: 0x2c
    s32 mIFree[8];  // offset: 0x30
    f32 mFFree[8];  // offset: 0x50
public:
    static const u32 ST_CONDITION_CHECK_WAIT = 1;
    static const u32 ST_CONDITION_CHECK_WAIT_TIMEOUT = 2;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK10cAIFSMData5MyDTI11newInstanceEv at 0x010319d0-0x01031a4c, code DWARF attributes to no inlined copy; approximate: only approximate callers check this inline body
inline cAIFSMData::cAIFSMData() {
    this->mpCore = static_cast<cAIFSMData::Core* *>(nullptr);
    this->mStreamDataSize = static_cast<u32>(0);
    this->mStreamData = static_cast<u32*>(nullptr);
    this->mCoreNum = static_cast<u32>(0);
    this->mFFree[6] = 0.0f;
    this->mFFree[7] = 0.0f;
    this->mFFree[4] = 0.0f;
    this->mFFree[5] = 0.0f;
    this->mFFree[2] = 0.0f;
    this->mFFree[3] = 0.0f;
    this->mFFree[0] = 0.0f;
    this->mFFree[1] = 0.0f;
    this->mIFree[6] = static_cast<int>(0);
    this->mIFree[7] = static_cast<int>(0);
    this->mIFree[4] = static_cast<int>(0);
    this->mIFree[5] = static_cast<int>(0);
    this->mIFree[2] = static_cast<int>(0);
    this->mIFree[3] = static_cast<int>(0);
    this->mIFree[0] = static_cast<int>(0);
    this->mIFree[1] = static_cast<int>(0);
}
