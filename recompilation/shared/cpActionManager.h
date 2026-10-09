#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cActList.h"
#include "cDelegate.h"
#include "cpComponent.h"
#include "nAction.h"
#include "nActionManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cActList;
class cActNetParam;
class cActParam;
class cAction;
class cHitInfoAfter;
class cHumanActSetNpcMotMyRoom;
class cHumanActSetNpcMotion;
namespace nActionManager { struct stActExParam; }
class rActionParam;
class uDDOModel;

// Declarations
class cpActionManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpActionManager : public cpComponent
{
    // inferred: cHumanActSetNpcMotMyRoom::getEmotion names cpActionManager::mActExParam.mUParam[3]
    friend class cHumanActSetNpcMotMyRoom;
    // inferred: cHumanActSetNpcMotion::getCategory names cpActionManager::mActExParam.mUParam[0]
    friend class cHumanActSetNpcMotion;
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
    cpActionManager();
    virtual ~cpActionManager();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void setID(s32 id);
    s32 getID();
    void addActionManager(cpActionManager* pActMgr);
    cpActionManager* getActionManager(u32 id);
    virtual void setup();  // vtable slot 6
    void update();
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void compMoveAfter();
    void setActionList(u32 bank, const cActList* pTbl, rActionParam* pActionParamRes);
    bool isCommuAction(u32 actNo);
    void callPreInit(u32 actNo);
    void setAction(u32 ActNo, bool replace_act_param, u32 uparam0, u32 uparam1, u32 uparam2, u32 uparam3, f32 fparam0, f32 fparam1, f32 fparam2, f32 fparam3);
    const nActionManager::stActExParam* getActExParam();
    void setActExParam(u32 no, u32 param);
    void setActExParam(u32 no, f32 param);
    cAction* getAction();
    u32 getActionNo();
    u32 getActionNoOld();
    u32 getRequestActionNo();
    void setActionNoOld(u32);
    const cActParam* getActParam();
    const cActParam* getActParam(u32 ActNo);
    const cActNetParam* getActNetParam();
    const cActNetParam* getActNetParam(u32 ActNo);
    u32 getActionNo_PreInit() const;
    u32 getActionNoOld_PreInit() const;
    const cActParam* getActParam_PreInit();
    const cActNetParam* getActNetParam_PreInit();
    const cActParam* getActParamOld_PreInit();
    const cActNetParam* getActNetParamOld_PreInit();
    void clearActPrio();
    void clearActReqPrio();
    nAction::ACT_PRIO getActPrio();
    void setActPrio(nAction::ACT_PRIO prio);
    nAction::ACT_PRIO getActReqPrio();
    void setActReqPrio(nAction::ACT_PRIO prio);
    bool checkPriority(nAction::ACT_PRIO prio, cHitInfoAfter* pHitInfo, bool eqFaild);
    const cActList* getActList(u32 bank) const;
    void setEndAction(bool end);
    bool isEndAction();
    void endAction();
    void endActionNoSend();
protected:
    bool isPreInit() const;
public:
    cDelegate_1<void, cpActionManager*> callbackEndAction;  // offset: 0x50
    cDelegate_1<void, cpActionManager*> callbackChangeAction;  // offset: 0x68
    cDelegate_1<void, int> setState;  // offset: 0x80
protected:
    const cActList* mpActList[16];  // offset: 0x98
    rActionParam* mpActionParam[16];  // offset: 0x118
    uDDOModel* mpModel;  // offset: 0x198
    u32 mActNo;  // offset: 0x1a0
    u32 mActNoOld;  // offset: 0x1a4
    nActionManager::stActExParam mActExParam;  // offset: 0x1a8
    bool mIsUseActExParam;  // offset: 0x1cc
    cActParam mActExParamActList;  // offset: 0x1d0
    nAction::ACT_PRIO mReqPrio;  // offset: 0x1f8
    nAction::ACT_PRIO mPrio;  // offset: 0x1fc
    u32 mRequestActNo;  // offset: 0x200
    cAction* mpAction;  // offset: 0x208
    bool mEndAction;  // offset: 0x210
    bool mIsSetAction;  // offset: 0x211
    u32 mID;  // offset: 0x214
    cpActionManager* mpTop;  // offset: 0x218
    cpActionManager* mpNext;  // offset: 0x220
    bool mIsPreinit;  // offset: 0x228
    u32 mActNo_PreInit;  // offset: 0x22c
    u32 mActNoOld_PreInit;  // offset: 0x230
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool cpActionManager::isEndAction() {
    return this->mEndAction;
}
