#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cAIFSM.h"
#include "cAIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cAIFSM;

// Declarations
class cFSMCore;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cFSMCore : public cAIObject
{
public:
    class MyDTI;
public:
    using PROCESS_FUNC = u32(MtObject::*)(MtObject*, MtObject*);
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
    bool isEnable() const;
    void setEnable(bool isEnable);
    MtObject* getOwner() const;
    void setOwner(MtObject* pOwner);
    MT_CTSTR getFSMName();
    MT_CTSTR getFSMPath();
    virtual void move();  // vtable slot 6
    bool setupFSM(MT_CTSTR resourcePath);
protected:
    u32 stateDefUpdate(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateFinish(MtObject* pParam, MtObject* pCaller);
    void addFSMAction(MT_CTSTR toolName, MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, PROCESS_FUNC updateFunc, PROCESS_FUNC stateFunc);
    void addFSMAction(MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, PROCESS_FUNC updateFunc, PROCESS_FUNC stateFunc);
    void addFSMAction(MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, PROCESS_FUNC updateFunc, PROCESS_FUNC stateFunc, PROCESS_FUNC exitFunc);
    // Address: 0x0196deb0 - 0x0196deb1 (1 bytes)
    virtual void callbackUpdate() {}  // vtable slot 7
    // Address: 0x0196dec0 - 0x0196dec1 (1 bytes)
    virtual void callbackFinish() {}  // vtable slot 8
    f32 getCountState();
public:
    cFSMCore();
    virtual ~cFSMCore();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    virtual void createPropertyFSM(MtPropertyList& s);  // vtable slot 9
protected:
    cAIFSM mFSM;  // offset: 0x8
    MtObject* mpOwner;  // offset: 0x78
    bool mIsEnable;  // offset: 0x80
    f32 mCountState;  // offset: 0x84
    f32 mCountFSM;  // offset: 0x88
    f32 mChangeCountState;  // offset: 0x8c
public:
    static MyDTI DTI;
};
