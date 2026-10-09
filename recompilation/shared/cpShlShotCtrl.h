#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtSynchronize.h"
#include "cpComponent.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "rShotReqInfo2.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cpObjCollisionBase;
namespace nHuman { struct stShellRequestInfo; }
namespace nHuman { struct stShellRequestMsg; }
class rShlParamList;
class rShotReqInfo;
class rShotReqInfo2;
class uDDOModel;
class uShlBase;

// Declarations
class cpShlShotCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpShlShotCtrl : public cpComponent
{
public:
    enum SHL_NET_STS
    {
        SHL_NET_STS_NONE = 0,
        SHL_NET_STS_POS = 1,
        SHL_NET_STS_TARGET_POS = 2,
        SHL_NET_STS_TARGET_UID = 4,
        SHL_NET_STS_DIR = 8,
        SHL_NET_STS_DIR_CALC = 16,
        SHL_NET_STS_NO_ACTION = 32,
        SHL_NET_STS_CONTROLER = 64,
        SHL_NET_STS_COMMON_SHL = 128,
        SHL_NET_STS_LOCKON_ID = 256,
        SHL_NET_FILTER_TARGET = 19,
        SHL_NET_FILTER_DIR = 9,
        SHL_NET_FILTER_UID = 13,
        SHL_NET_FILTER_LOCKON = 269,
    };
    enum
    {
        MAX_SAME_SHOT_NUM = 8,
    };
public:
    class MyDTI;
    class cShlShotReqInfo;
public:
    using cShlReqArray = nDDOUtility::cArray<nHuman::stShellRequestInfo, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShlShotReqInfo : public MtObject
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
        cShlShotReqInfo();
        virtual ~cShlShotReqInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        s32 getShotStsPrivate() const;
        void setShotStsPrivate(s32 NewValue);
    public:
        void copyParam(const cpShlShotCtrl::cShlShotReqInfo& info);
        void setShotSts(cpShlShotCtrl::SHL_NET_STS sts);
        void addShotSts(cpShlShotCtrl::SHL_NET_STS sts);
        void subShotSts(cpShlShotCtrl::SHL_NET_STS sts);
        bool isShotSts(cpShlShotCtrl::SHL_NET_STS sts);
        void setNotifyDelete(bool isNotify, s32 work);
        bool isNotifyDelete();
        s32 getWork();
        void copySharedUID(cpObjCollisionBase* pSrc);
        void copySharedUIDToObjCollision(cpObjCollisionBase* pDst);
    public:
        uDDOModel* mpTarget;  // offset: 0x8
        MtVector3 mPos;  // offset: 0x10
        MtVector3 mDirection;  // offset: 0x20
        MtVector3 mTargetPos;  // offset: 0x30
        MtMatrix mShlMatrix;  // offset: 0x40
        u32 mTargetUId;  // offset: 0x80
        s32 mLockOnIndex;  // offset: 0x84
        u32 mShlUId;  // offset: 0x88
        s32 mShotGroup;  // offset: 0x8c
        s32 mShotIndex;  // offset: 0x90
        f32 mShotTimer;  // offset: 0x94
        bool mIsCalcDirTargetPos;  // offset: 0x98
        bool mIsInherit;  // offset: 0x99
        bool mIsUseShotCoordMatrix;  // offset: 0x9a
        bool mIsConst;  // offset: 0x9b
        u32 mConstUId;  // offset: 0x9c
        s32 mConstJoint;  // offset: 0xa0
        u32 mSharedUID[8];  // offset: 0xa4
    private:
        s32 mShotSts_Guard;  // offset: 0xc4
        bool mIsNotifyDelete;  // offset: 0xc8
        s32 mWork;  // offset: 0xcc
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
    cpShlShotCtrl();
    virtual ~cpShlShotCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    void after();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    uShlBase* shotShell(cShlShotReqInfo* pInfo);
public:
    void clearLockonInfo();
    u32 getTargetUId();
    void setTargetUId(u32 id);
    s32 getLockOnIndex();
    void setLockOnIndex(s32 index);
    u32 getPawnTargetUId();
    void setPawnTargetUId(u32 id);
    s32 getPawnLockOnIndex();
    void setPawnLockOnIndex(s32 index);
    void updateTargetFromPawnTarget();
    void requestShotShellFromResource(u32 index);
    bool requestShotShellFromResource2(u32 index);
    bool selectShotInfo(u32 index, cShotReqInfo2::SHOT_REQ_INFO* info);
    void setShotReqInfo2(rShotReqInfo2* pParam);
    uShlBase* requestShotShell(cShlShotReqInfo& info, bool isNow);
    void setShlOwner(uDDOModel* pOwner);
    void setShlParamList(rShlParamList* pParam);
    void setCommonShlParamList(rShlParamList* pParam);
    void setShotReqInfo(rShotReqInfo* pParam);
    void registShellRequestMsg(const nHuman::stShellRequestMsg& srcMsg);
private:
    void checkShellRequest();
    void clearShellRequestArray();
private:
    rShlParamList* mprShlParamList;  // offset: 0x50
    rShlParamList* mpCommonShlParamList;  // offset: 0x58
    rShotReqInfo* mprShotReqInfo;  // offset: 0x60
    rShotReqInfo2* mprShotReqInfo2;  // offset: 0x68
    uDDOModel* mpModel;  // offset: 0x70
    uDDOModel* mpShlOwner;  // offset: 0x78
    MtTypedArray<cShlShotReqInfo> mShlShotReqArray;  // offset: 0x80
    u32 mShotCnt;  // offset: 0xa0
    u32 mFastShotCnt;  // offset: 0xa4
    u32 mTargetUId;  // offset: 0xa8
    s32 mLockOnIndex;  // offset: 0xac
    u32 mPawnTargetUId;  // offset: 0xb0
    s32 mPawnLockOnIndex;  // offset: 0xb4
    MtCriticalSection mCS;  // offset: 0xb8
    cShlReqArray mShlReqArray;  // offset: 0xc0
public:
    static MyDTI DTI;
};
