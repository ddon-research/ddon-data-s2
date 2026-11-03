#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtString.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cAIService;
class cAITask;
namespace nAI { struct TASK_PERFORMANCE_INFO; }
namespace nAI { class TaskPerformanceInfo; }
class rAI;
class uStagePartsMdl;

// Declarations
class sAI;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sAI : public cSystem
{
    friend class cAIService;
    friend class uStagePartsMdl;
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
    sAI();
    virtual ~sAI();
    static sAI* getInstance();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void moveAfter();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void addService(cAIService* pService, MT_CTSTR entryName);
    void addService(MT_CTSTR dtiName, MT_CTSTR entryName);
    u32 getServiceNum();
    cAIService* getService(const MtDTI& dti, MT_CTSTR n);
    cAIService* getService(MT_CTSTR n);
    cAIService* getServiceByID(u32 id);
    cAIService* getServiceByIndex(u32 index);
    bool hasService(cAIService* pService);
    void deleteAllService();
    void deleteService(const MtDTI& dti);
    void deleteService(MT_CTSTR n);
    void resetAllService();
    u32 createServiceID(const MtDTI& dti, MT_CTSTR name);
    void setupTaskPerformanceInfo(nAI::TASK_PERFORMANCE_INFO* pInfo);
    nAI::TaskPerformanceInfo* searchTaskPerformanceInfo(const MtDTI* pDTI);
    nAI::TaskPerformanceInfo* searchTaskPerformanceInfo(MT_CTSTR n);
    void setTaskPerformanceIndicator(f32);
    f32 getTaskPerformanceIndicator();
    void entryBackgroundTask(cAITask* pTask);
    void removeBackgroundTask(cAITask* pTask);
    u64 getPerformanceFrequency();
    u64 getPerformanceCount();
    f32 getPassageTimeBySec(u64, u64);
    u64 getPerformanceCountFromSec(f32 t);
    bool importSettingResource(rAI* pResource);
    u32 getFrameId();
protected:
    void removeService(cAIService* pService);
    void moveService(bool isAfter);
    void drawDebug();
    void setServiceNum(u32 num);
    void setServiceByIndex(cAIService* ps, u32 index);
    bool createTaskPerformanceInfoList(u32 num);
    void destroyTaskPerformanceInfoList();
    bool createTaskPerformanceInfoList();
    void countTaskClassChild(u32& num, const MtDTI* pDTI);
    void setDTIToTaskPerformanceInfo(u32& index, const MtDTI* pDTI);
    nAI::TaskPerformanceInfo* getTaskPerformanceInfo(u32 index);
    void setTaskPerformanceInfo(nAI::TaskPerformanceInfo* pi, u32 index);
    u32 getTaskPerformanceInfoNum();
    void setTaskPerformanceInfoNum(u32 num);
protected:
    u64 mPerformanceFrequency;  // offset: 0x18
    u32 mFrameId;  // offset: 0x20
    cAIService* mpServiceTop;  // offset: 0x28
    cAIService* mpServiceBottom;  // offset: 0x30
    cAITask* mpBackgroundTaskTop;  // offset: 0x38
    cAITask* mpBackgroundTaskBottom;  // offset: 0x40
    f32 mTaskPerformanceIndicator;  // offset: 0x48
    u32 mTaskPerformanceInfoNum;  // offset: 0x4c
    nAI::TaskPerformanceInfo* mTaskPerformanceInfoList;  // offset: 0x50
    MtString mSettingFileName;  // offset: 0x58
public:
    static const u32 TASK_QUEUE_SIZE = 1024;
    static MyDTI DTI;
protected:
    static sAI* mpInstance;
};

inline void* sAI::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sAI* sAI::getInstance() {
    return ::sAI::mpInstance;
}
