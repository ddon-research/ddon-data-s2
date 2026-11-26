#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cScenario.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cScenario;
class cScenarioArg;

// Declarations
class cScenarioArg_AreaJump;
class cScenarioArg_BootFSM;
class cScenarioElement;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SCENARIO_ACTION_FUNC_END = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_INIT = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_MAIN = SCENARIO_ACTION_RETURN(*)(cScenarioArg*);
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cScenarioArg_AreaJump : public cScenarioArg
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
    cScenarioArg_AreaJump(cScenario* pSce);
    virtual ~cScenarioArg_AreaJump();
    virtual cScenarioArg& operator=(const cScenarioArg& s);  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    static void callback(MtObject* pOwner, s32 pl_no, u32, s32, f32);
    static SCENARIO_ACTION_RETURN actionMain(cScenarioArg* _pArg);
public:
    u32 mStageNo;  // offset: 0x38
    s32 mPosNo;  // offset: 0x3c
    static MyDTI DTI;
};

class cScenarioArg_BootFSM : public cScenarioArg
{
public:
    enum
    {
        TCH_INVESTIGATE = 0,
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
    cScenarioArg_BootFSM(cScenario* pSce);
    virtual cScenarioArg& operator=(const cScenarioArg& s);  // vtable slot 6
    virtual ~cScenarioArg_BootFSM();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    static void callback(MtObject* pOwner, s32 pl_no, u32 starter, s32, f32);
    static SCENARIO_ACTION_RETURN actionMain(cScenarioArg* _pArg);
public:
    MtArray mFSMList;  // offset: 0x38
    u32 mTouchType;  // offset: 0x58
    static MyDTI DTI;
};

class cScenarioElement
{
public:
    static SCENARIO_ACTION_FUNC_INIT getActionInit(SCENARIO_TASK_ENUM task);
    static SCENARIO_ACTION_FUNC_MAIN getActionMain(SCENARIO_TASK_ENUM task);
    static SCENARIO_ACTION_FUNC_END getActionEnd(SCENARIO_TASK_ENUM task);
};

inline void* cScenarioArg_AreaJump::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cScenarioArg_BootFSM::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
