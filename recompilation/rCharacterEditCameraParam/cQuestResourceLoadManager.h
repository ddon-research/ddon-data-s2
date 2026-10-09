#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cQuestFunctionManagerBAse.h"
#include "../shared/nQuest.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nQuest { class QUEST_ID; }

// Declarations
class cQuestResourceLoadManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nQuest { using QuestIdArray = MtTypedArray<nQuest::QUEST_ID>; }
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestResourceLoadManager : public cQuestFunctionManagerBase
{
public:
    class MyDTI;
    class cLoadTask;
public:
    using LoadTaskArray = MtTypedArray<cQuestResourceLoadManager::cLoadTask>;
    using PCALLBACK_FUNC = void(MtObject::*)(u32);
    using PCALLBACK_FUNC_WITH_LIST = void(MtObject::*)(u32, const nQuest::QuestIdArray&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLoadTask : public MtObject
    {
        // inferred: cQuestResourceLoadManager::setClass names cQuestResourceLoadManager::cLoadTask::mpClass
        friend class cQuestResourceLoadManager;
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
        void addQuestId(nQuest::QUEST_ID questId);
        bool isFinishedLoading() const;
        MtObject* getClass() const;
        void setClass(MtObject* pClass);
        void setCallbackFunc(cQuestResourceLoadManager::PCALLBACK_FUNC pCallbackFunc);
        void setCallbackFunc(cQuestResourceLoadManager::PCALLBACK_FUNC_WITH_LIST pCallbackFunc);
        bool hasStarted() const;
        void executeCallback(u32 arg);
        void startLoading();
        cLoadTask();
        virtual ~cLoadTask();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QuestIdArray mQuestIds;  // offset: 0x8
        MtObject* mpClass;  // offset: 0x28
        cQuestResourceLoadManager::PCALLBACK_FUNC mpCallbackFunc;  // offset: 0x30
        cQuestResourceLoadManager::PCALLBACK_FUNC_WITH_LIST mpCallbackFuncWithList;  // offset: 0x40
        bool mHasStarted;  // offset: 0x50
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
    void addQuestId(cLoadTask* pTask, nQuest::QUEST_ID questId);
    void setClass(cLoadTask* pTask, MtObject* pClass);
    void setCallbackFunc(cLoadTask* pTask, PCALLBACK_FUNC pCallbackFunc);
    void setCallbackFunc(cLoadTask* pTask, PCALLBACK_FUNC_WITH_LIST pCallbackFunc);
    cLoadTask* createNewTask();
    void startLoading(cLoadTask* pTask);
    void removeTask(const MtObject* pClass);
    void move();
    cQuestResourceLoadManager();
    virtual ~cQuestResourceLoadManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    LoadTaskArray mLoadTasks;  // offset: 0x8
public:
    static MyDTI DTI;
};
