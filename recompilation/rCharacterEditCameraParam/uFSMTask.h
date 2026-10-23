#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class aStage;
class uFSMTask;

// Declarations
class cFSMTaskCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cFSMTaskCtrl : public MtObject
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
    bool isEnableFSMTask(MT_CTSTR name) const;
    uFSMTask* getFSMTask(MT_CTSTR name) const;
    uFSMTask* getFSMTask(u32 no) const;
    u32 getFSMTaskNum() const;
    bool isStopFSM() const;
    void setStopFSM(bool);
    bool isPlayCamEv() const;
    bool addFSMTaskOrderFromName(MT_CTSTR filePath, u32 starter);
    bool addFSMTaskEventFromName(MT_CTSTR filePath);
    bool addFSMTaskCamEvFromName(MT_CTSTR filePath);
protected:
    uFSMTask* createFSMTask();
    void deleteAllFSMTask();
public:
    void setStage(aStage* pStage);
    aStage* getStage() const;
    cFSMTaskCtrl();
    virtual ~cFSMTaskCtrl();
    virtual void move();  // vtable slot 6
private:
    bool mIsStopFSM;  // offset: 0x8
    bool mIsStopFSM_mix;  // offset: 0x9
    MtArray mFSMTaskList;  // offset: 0x10
protected:
    aStage* mpStage;  // offset: 0x30
public:
    static MyDTI DTI;
};
