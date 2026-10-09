#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cOcdCustomReqInfo.h"
#include "nAction.h"
#include "nObjCollision.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cOcdBase;
class cOcdCustomReqInfo;
class cOcdImmuneParamRes;
class cOcdStatusParamRes;
class cpOcdCtrl;
class uDDOModel;

// Declarations
class cOcdActParam;
class cOcdInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cOcdActParam
{
public:
    u32 getInitLandActNo() const;
    void setInitLandActNo(u32 NewValue);
    nAction::ACT_PRIO getInitLandActPrio() const;
    void setInitLandActPrio(nAction::ACT_PRIO NewValue);
    u32 getInitActionNo() const;
    void setInitActionNo(u32 NewValue);
    nAction::ACT_PRIO getInitActPriority() const;
    void setInitActPriority(nAction::ACT_PRIO NewValue);
    u32 getInitFallActNo() const;
    void setInitFallActNo(u32 NewValue);
    nAction::ACT_PRIO getInitFallActPrio() const;
    void setInitFallActPrio(nAction::ACT_PRIO NewValue);
    u32 getInitDownActNo() const;
    void setInitDownActNo(u32 NewValue);
    nAction::ACT_PRIO getInitDownActPrio() const;
    void setInitDownActPrio(nAction::ACT_PRIO NewValue);
    u32 getEndActionNo() const;
    void setEndActionNo(u32 NewValue);
    nAction::ACT_PRIO getEndActPriority() const;
    void setEndActPriority(nAction::ACT_PRIO NewValue);
    u32 getMainActionNo() const;
    void setMainActionNo(u32 NewValue);
    nAction::ACT_PRIO getMainActPriority() const;
    void setMainActPriority(nAction::ACT_PRIO NewValue);
    u32 getResetActionNo() const;
    void setResetActionNo(u32 NewValue);
    nAction::ACT_PRIO getResetPrority() const;
    void setResetPrority(nAction::ACT_PRIO NewValue);
    u8 getReactionStartTiming() const;
    void setReactionStartTiming(u8 NewValue);
    u8 getTimerStartTiming() const;
    void setTimerStartTiming(u8 NewValue);
    cOcdActParam(u32 InitLandActNo, nAction::ACT_PRIO InitLandPrio, u32 InitActNo, nAction::ACT_PRIO InitPriority, u32 InitFallActNo, nAction::ACT_PRIO InitFallPrio, u32 InitDownActNo, nAction::ACT_PRIO InitDownPrio, u32 ResetActNo, nAction::ACT_PRIO ResetPriority, u32 EndActNo, nAction::ACT_PRIO EndPriority, u32 MainActNo, nAction::ACT_PRIO MainPriority, u8 ReactionStartTiming, u8 TimerStartTiming);
    const cOcdActParam& operator=(const cOcdActParam& src);
private:
    u32 mInitLandActNo;  // offset: 0x0
    nAction::ACT_PRIO mInitLandActPrio;  // offset: 0x4
    u32 mInitActionNo;  // offset: 0x8
    nAction::ACT_PRIO mInitActPriority;  // offset: 0xc
    u32 mInitFallActNo;  // offset: 0x10
    nAction::ACT_PRIO mInitFallActPrio;  // offset: 0x14
    u32 mInitDownActNo;  // offset: 0x18
    nAction::ACT_PRIO mInitDownActPrio;  // offset: 0x1c
    u32 mEndActionNo;  // offset: 0x20
    nAction::ACT_PRIO mEndActPriority;  // offset: 0x24
    u32 mMainActionNo;  // offset: 0x28
    nAction::ACT_PRIO mMainActPriority;  // offset: 0x2c
    u32 mResetActionNo;  // offset: 0x30
    nAction::ACT_PRIO mResetPrority;  // offset: 0x34
    u8 mReactionStartTiming;  // offset: 0x38
    u8 mTimerStartTiming;  // offset: 0x39
};

class cOcdInfo : public MtObject
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
    cOcdInfo();
    cOcdInfo(const MtDTI* pDTI, const cOcdActParam& param);
    virtual ~cOcdInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    void init();
    void setup();
public:
    const cOcdActParam& getOcdActParam() const;
    bool isActive() const;
    void reqChangeOcdMode(nObjCondition::OCD_REQ_MODE mode, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);
    bool isReqestAbleCustom(s32 priority) const;
    void setCustomReqest(const cOcdCustomReqInfo& reqInfo, s32 priority);
    bool isCustomRequest() const;
    const cOcdCustomReqInfo& getCustomRequest() const;
    void clearCustomReqInfo();
    nObjCondition::OCD_MODE getOcdMode() const;
    void setOcdMode(nObjCondition::OCD_MODE mode);
    nObjCondition::OCD_REQ_MODE getOcdModeReq() const;
    void setOcdModeReq(nObjCondition::OCD_REQ_MODE mode);
    nObjCondition::OCD_MODE_REQ_RESULT getOcdReqResult() const;
    void setOcdReqResult(nObjCondition::OCD_MODE_REQ_RESULT mode);
    void checkCheckOcd();
    void reportCheatOcd();
    u32 getOcdId();
private:
    void turnOffChengeRequest();
    void turnOffReqResult();
    void changeMode(nObjCondition::OCD_MODE mode);
    void setStatusParamRes(const cOcdStatusParamRes& data);
    void setImuuneParamRes(const cOcdImmuneParamRes& data);
    nObjCondition::OCD_MODE getOcdModeCheatCheck() const;
    void setModeCheatCheck(nObjCondition::OCD_MODE mode);
    nObjCondition::OCD_REQ_MODE getOcdModeReqCheatCheck() const;
    void setOcdModeReqCheatCheck(nObjCondition::OCD_REQ_MODE mode);
    nObjCondition::OCD_MODE_REQ_RESULT getOcdReqResultCheatCheck() const;
    void setOcdReqResultCheatCheck(nObjCondition::OCD_MODE_REQ_RESULT mode);
    const MtDTI* getDtiPtr() const;
    void setDtiPtr(const MtDTI* NewValue);
    nObjCondition::OCD_MODE getOcdModePrivate() const;
    void setOcdModePrivate(nObjCondition::OCD_MODE NewValue);
    nObjCondition::OCD_REQ_MODE getOcdModeReqPrivate() const;
    void setOcdModeReqPrivate(nObjCondition::OCD_REQ_MODE NewValue);
    nObjCondition::OCD_MODE_REQ_RESULT getOcdReqResultPrivate() const;
    void setOcdReqResultPrivate(nObjCondition::OCD_MODE_REQ_RESULT NewValue);
    u32 getOcdModeCheatCheckPrivate() const;
    void setOcdModeCheatCheckPrivate(u32 NewValue);
    u32 getOcdModeReqCheatCheckPrivate() const;
    void setOcdModeReqCheatCheckPrivate(u32 NewValue);
    u32 getOcdReqResultCheatCheckPrivate() const;
    void setOcdReqResultCheatCheckPrivate(u32 NewValue);
    bool isBadOcd() const;
private:
    cOcdBase* mpObjCondition;  // offset: 0x8
    u32 mOcdUID;  // offset: 0x10
    cOcdActParam mOcdActParam;  // offset: 0x14
    cOcdCustomReqInfo mOcdCustomReq;  // offset: 0x50
    const MtDTI* mpDTI_Guard;  // offset: 0x68
    cpOcdCtrl* mpOcdCtrl;  // offset: 0x70
    uDDOModel* mpModel;  // offset: 0x78
    nObjCondition::OCD_MODE mOcdMode;  // offset: 0x80
    nObjCondition::OCD_REQ_MODE mOcdModeReq;  // offset: 0x84
    nObjCondition::OCD_MODE_REQ_RESULT mOcdReqResult;  // offset: 0x88
    u32 mOcdModeCheatCheck;  // offset: 0x8c
    u32 mOcdModeReqCheatCheck;  // offset: 0x90
    u32 mOcdReqResultCheatCheck;  // offset: 0x94
public:
    static MyDTI DTI;
};
