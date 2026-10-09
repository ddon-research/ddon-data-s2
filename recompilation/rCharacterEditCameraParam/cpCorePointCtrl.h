#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cpComponent.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cChildRegionStatus;
class cCorePointMsg;
class cEfcHandle;
class cParentRegionStatus;
class cpHpDamageCtrl;
namespace nRegionStatus { struct stCorePointSlaveMsg; }
class uEnemy;

// Declarations
class cCorePointInfo;
class cCorePointReqestInfo;
class cpCorePointCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cReqesutCashArray = nDDOUtility::cArray<cCorePointReqestInfo, 8>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class cCorePointInfo : public MtObject
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
    cCorePointInfo();
    void updatePtr();
    void updateEfcHandle();
    void init();
    void move();
    void final();
    void requestErase();
    void executeErase();
    void eraseMyMsgFromContext();
    s32 findMyIndexFromContext();
public:
    cEfcHandle* mpEfcHandle;  // offset: 0x8
    cpCorePointCtrl* mpCorePointCtrl;  // offset: 0x10
    uEnemy* mpEnemy;  // offset: 0x18
    s32 mRegionNo;  // offset: 0x20
    s32 mCorePointID;  // offset: 0x24
    f32 mActiveTimer;  // offset: 0x28
    f32 mActiveTimerMax;  // offset: 0x2c
    nRegionStatus::CORE_POINT_TYPE mCorePointType;  // offset: 0x30
    u32 mParentRegionNo;  // offset: 0x34
    t64 mCreatedTime;  // offset: 0x38
    bool mEraseFlag;  // offset: 0x40
    static MyDTI DTI;
};

class cCorePointReqestInfo : public MtObject
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
    cCorePointReqestInfo();
    void copy(const cCorePointReqestInfo& info);
    void clear();
public:
    s32 mRegionNo;  // offset: 0x8
    f32 mActiveTime;  // offset: 0xc
private:
    s32 mCorePointID;  // offset: 0x10
    t64 mCreatedTime;  // offset: 0x18
    bool mIsReceive;  // offset: 0x20
public:
    static MyDTI DTI;
};

class cpCorePointCtrl : public cpComponent
{
public:
    enum SLAVE_MSG_MODE
    {
        MODE_INVALID = 0,
        MODE_NONE = 1,
        MODE_REQUEST = 2,
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
    cpCorePointCtrl();
    virtual ~cpCorePointCtrl();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    void before();
    void update();
    void compMoveAfter();
    bool isCorePoint(u32 regionNo, nRegionStatus::CORE_POINT_TYPE coreType) const;
    bool isCorePoint(const cChildRegionStatus* pRegion, nRegionStatus::CORE_POINT_TYPE coreType) const;
    bool isCorePointActive(u32 regionNo, nRegionStatus::CORE_POINT_TYPE coreType) const;
    bool isCorePointActive(nRegionStatus::CORE_POINT_TYPE coreType) const;
    u32 getCorePointNum(nRegionStatus::CORE_POINT_TYPE coreType) const;
    u32 getCorePointActiveNum(nRegionStatus::CORE_POINT_TYPE coreType) const;
    const cCorePointInfo* getActiveCorePointFromIndex(u32 index) const;
    u32 getActiveCorePointArrayNum() const;
    MtVector3 getActiveCorePointPos(const cCorePointInfo* pInfo) const;
    void requestCorePointActive(const cCorePointReqestInfo& info);
    void reqCorePointAllActive(f32 times, nRegionStatus::CORE_POINT_TYPE coreType);
    void requestCorePointAddTime(u32 regionNo, f32 addTime);
    const MtTypedArray<cCorePointInfo>& getCorePointActiveArray() const;
    MtTypedArray<cCorePointInfo>& getCorePointActiveArray();
    u32 getCorePointColNum(nRegionStatus::CORE_POINT_TYPE coreType);
    void corePpointActiveReqOff();
private:
    cpHpDamageCtrl* findHpDamageCtrl() const;
    cChildRegionStatus* findChildRegion(u32 regionNo) const;
    cParentRegionStatus* findParentRegion(u32 regionNo) const;
    bool isEnableCorePointActive(nRegionStatus::CORE_POINT_TYPE coreType) const;
    void registActiveCorePoint(const cCorePointReqestInfo& info, bool isSend);
    void registActiveCorePoint(const cCorePointReqestInfo& info, s32 corePointID, nRegionStatus::CORE_POINT_TYPE coreType, bool isSend);
    void reNewActiveCorePoint(cCorePointInfo* pOldInfo, const cCorePointReqestInfo& info, bool isSend);
    s32 findActiveCorePointIndex(s32 regionNo);
    cCorePointInfo* findActiveCorePoint(u32 regionNo);
    cCorePointInfo* findActiveCorePointFromIndex(s32 index);
    void eraseActiveCorePoint(u32 regionNo);
    void eraseActiveCorePointFromIndex(s32 index);
    void eraseActiveCorePointErosion();
    void checkCorePointID();
    void checkOwnerStatus();
    void checkErase();
    void checkSlaveMsg();
    void checkRequest();
    void checkRequestCore(const cCorePointReqestInfo& info, bool isSend);
    void clearReqestInfo();
    void callUpdate();
public:
    void receiveCorePointMsg(bool recvFlag);
    void receiveCorePointSlaveMsg(const nRegionStatus::stCorePointSlaveMsg& msg);
private:
    u32 makeRegionMask() const;
    void checkReceiveMsg();
    void addCorePointMsgToCotext(const cCorePointInfo* pInfo);
    void receiveCorePointMsgSub(cCorePointMsg* pMsg);
    void composeCorePointInfo(const cCorePointInfo* pInfo, cCorePointMsg* pMsg);
    void decomposeCorePointInfo(const cCorePointMsg* pMsg, cCorePointReqestInfo& info);
    f32 calcActiveTime(const cCorePointMsg* pMsg) const;
    void composeToSlaveMsg(const cCorePointReqestInfo& info, nRegionStatus::stCorePointSlaveMsg* pMsg);
    void decomposeSlaveMsgToReq(const nRegionStatus::stCorePointSlaveMsg& msg, cCorePointReqestInfo& info);
private:
    uEnemy* mpEnemy;  // offset: 0x50
    MtTypedArray<cCorePointInfo> mActiveCorePointArray;  // offset: 0x58
    cReqesutCashArray mReqCashArray;  // offset: 0x78
    u32 mCorePointReqestNum;  // offset: 0x1b8
    bool mIsEnableCorePointReq;  // offset: 0x1bc
    bool mIsEnableCorePointReqOld;  // offset: 0x1bd
    bool mIsReceiveMsg;  // offset: 0x1be
    cReqesutCashArray mReceiveCashArray;  // offset: 0x1c0
    SLAVE_MSG_MODE mSlaveMsgMode;  // offset: 0x300
    bool mIsWaitTimerActive;  // offset: 0x304
    f32 mSlaveMsgWaitTimer;  // offset: 0x308
    f32 mSlaveMsgWaitTimeMax;  // offset: 0x30c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCorePointInfo::cCorePointInfo() {
    this->mRegionNo = static_cast<s32>(-1);
    this->mCorePointID = static_cast<s32>(-1);
    this->mCorePointType = static_cast<nRegionStatus::CORE_POINT_TYPE>(1);
    this->mActiveTimer = 0.0f;
    this->mActiveTimerMax = 0.0f;
    this->mEraseFlag = false;
    this->mCreatedTime = static_cast<t64>(0);
    this->mpEnemy = static_cast<uEnemy*>(nullptr);
    this->mpCorePointCtrl = static_cast<cpCorePointCtrl*>(nullptr);
    this->mpEfcHandle = static_cast<cEfcHandle*>(nullptr);
    this->mParentRegionNo = static_cast<u32>(11);
}

// Inline, no code of its own: checked where it is inlined.
inline cCorePointReqestInfo::cCorePointReqestInfo() {
    this->mRegionNo = static_cast<s32>(-1);
    this->mActiveTime = 0.0f;
    this->mCorePointID = static_cast<s32>(-1);
    this->mIsReceive = false;
    this->mCreatedTime = static_cast<t64>(0);
}
