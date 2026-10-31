#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cScenario.h"
#include "../../XFramework/cSystem.h"

// Forward declarations
class AreaHitShape;
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cAreaHit;
class cScenario;
class cScenarioArg;
class cScenarioData;
class rScenario;
class uDDOModel;
class uGUISystemMsg;

// Declarations
class SCE_AH_LIST;
class sScenario;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SCENARIO_ACTION_FUNC_END = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_MAIN = SCENARIO_ACTION_RETURN(*)(cScenarioArg*);
using _Sizet = long unsigned int;
using f32 = float;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class SCE_AH_LIST : public MtObject
{
    friend class sScenario;
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
    SCE_AH_LIST();
    virtual ~SCE_AH_LIST();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    cScenario* getScenario(u32 no);
    void add(cScenario* pSce);
    void insert(u32 no, cScenario* pSce);
    bool clear(cScenario* pSce);
    bool erase(cScenario* pSce);
    MT_CTSTR getFileName();
    void setFileName(MT_CTSTR);
    bool isHit(u32 no);
    bool isDetect(u32 no);
    bool isDone(u32 no);
    bool isDetectPl(u32 no, s8 pl_no);
    bool isIn(u32 no, const MtVector3& pos, f32 ang);
    bool isInPl(u32 no, s8 pl_no);
    bool isInCharacter(u32 no, uDDOModel* pCharacter);
    bool isInCharacter2(u32 no, uDDOModel* pCharacter0, uDDOModel* pCharacter1);
    bool isInCharacter3(u32 no, uDDOModel* pCharacter0, uDDOModel* pCharacter1, uDDOModel* pCharacter2);
    cAreaHit* getAreaHit(u32 no);
    u32 getNum();
private:
    MtArray mArray;  // offset: 0x8
    MtString mFileName;  // offset: 0x28
public:
    static MyDTI DTI;
};

class sScenario : public cSystem
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
    sScenario();
    virtual ~sScenario();
    void init();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void final();
    static sScenario* getInstance();
    cScenario* create(SCENARIO_PRIO_ENUM prio);
    cScenario* addData(cScenarioData* pCopySrc);
    SCE_AH_LIST* addResource(rScenario* pr);
    SCE_AH_LIST* addResourceField(rScenario* pr, MtArray& ar);
    cScenario* addCustom(SCENARIO_ACTION_FUNC_MAIN fpMain, SCENARIO_ACTION_FUNC_END fpEnd, SCENARIO_BOOT_ENUM boottype, cScenarioArg* pArg, AreaHitShape* pRefShape, u32 detectTarget, SCENARIO_PRIO_ENUM prio);
    void release(cScenario* p);
    void releaseAccess(cScenario* p);
    SCE_AH_LIST* getAreaHitList(SCENARIO_TASK_ENUM tasktype);
    void evEventStart();
    void evEventFinish();
private:
    void clearEvent();
public:
    cScenario* getScenario(u32 type, u32 no);
    void createSystemMsg(u32 textNo);
    void deleteSystemMsg();
private:
    MtArray mArray[9];  // offset: 0x18
    SCE_AH_LIST* mAccessList[4];  // offset: 0x138
public:
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x158
private:
    static sScenario* mpInstance;
public:
    static MyDTI DTI;
};

inline sScenario* sScenario::getInstance() {
    return ::sScenario::mpInstance;
}
