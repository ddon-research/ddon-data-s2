#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtVector3;
class kTHINKDATA;
class rkThinkData;

// Declarations
namespace cThinkMgrName { class cTargetLink; }
namespace cThinkMgrName { class cThinkMgr; }
namespace cThinkMgrName { class cThinkMgrTargetData; }
namespace cThinkMgrName { class cThinkMgrTargetMgr; }
namespace cThinkMgrName { class cThinkTblList; }
namespace cThinkMgrName { struct kTHINKCOUNT; }
namespace cThinkMgrName { struct kTHINKRETSET; }
namespace cThinkMgrName { struct kTHINKRETSET_CHK; }
namespace cThinkMgrName { struct kTHINKTIMER; }
namespace cThinkMgrName { struct kTHINK_ADD_IDX; }
namespace cThinkMgrName { struct kTHINK_FREE_WORK; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace cThinkMgrName {
    class cTargetLink : public ::MtObject
    {
    public:
        enum TARGETLINK_MODE
        {
            TARGETLINK_MODE_STOP = 0,
            TARGETLINK_MODE_REV = 1,
            TARGETLINK_MODE_LOOP = 2,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cTargetLink();
        // Address: 0x01a655b0 - 0x01a655b1 (1 bytes)
        virtual ~cTargetLink() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init();
        void setLinkIdxMax(u32 countmax);
        void addLinkIdxMax();
        void backLink();
        void nextLink();
        void setLinkID(u32 id);
        u32 getLinkID();
        void setLinkIDX(u32 idx);
        u32 getLinkIDX();
    private:
        void checkMoveMode();
    public:
        TARGETLINK_MODE getTargetLinkMode();
        void setTargetLinkMode(TARGETLINK_MODE mode);
        void setMode(bool downEnable);
        bool getMode();
    private:
        u32 mLinkID;  // offset: 0x8
        u32 mIdx;  // offset: 0xc
        u32 mIdxMax;  // offset: 0x10
        bool mIsDown;  // offset: 0x14
        TARGETLINK_MODE mMoveMode;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    class cThinkMgrTargetData : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cThinkMgrTargetData();
        // Address: 0x01a65490 - 0x01a65491 (1 bytes)
        virtual ~cThinkMgrTargetData() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setLinkID(u32 id);
        u32 getLinkID();
        void setLinkIDX(u32 idx);
        u32 getLinkIDX();
        cThinkMgrName::cThinkMgrTargetData* operator=(const cThinkMgrName::cThinkMgrTargetData& targetData);
        void init();
        bool isTargetData();
        void setTargetVectorData(MtObject* pTarget, MtVector3& myPos, MtVector3& targetPos, f32 myAngleYRad, f32 targetYAngleRad);
        void recalculationTargetVectorData(MtVector3& myPos, f32 myAngleYRad);
        void setTargetUniqID(u32 uniqId);
        void updatePtr();
        void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
        void setTargetPriorityData(f32 priority);
        void setTargetStatus(u64, u64);
        void setTargetHandlingType(u32 handlingType, u32 handlingTypeThink);
        void clrTargetHandlingTypeThink();
        void setTargetType(u32 type, u32 id);
        void setTargetType(u32);
        u32 getTargetTypeBit();
        u32 getTargetID();
        void setOrTargetType(u32);
        void setTargetId(u32);
    public:
        MtVector3 mMyPos;  // offset: 0x10
        MtVector3 mTargetPos;  // offset: 0x20
        f32 mTargetAngleY;  // offset: 0x30
        f32 mXyzLength;  // offset: 0x34
        f32 mXzLength;  // offset: 0x38
        f32 mYLength;  // offset: 0x3c
        f32 mAngle;  // offset: 0x40
        u64 mStatus;  // offset: 0x48
        u64 mStatusBefore;  // offset: 0x50
        f32 mPriority;  // offset: 0x58
        u32 mId;  // offset: 0x5c
        u32 mMotState;  // offset: 0x60
        MtObject* mpTargetChar;  // offset: 0x68
        u32 mIsTargetType;  // offset: 0x70
        u32 mTargetId;  // offset: 0x74
        union
        {
        public:
            u32 mIsTargetDataAll;  // offset: 0x0
            struct
            {
            public:
                unsigned int mIsTargetData : 1;  // offset: 0x0
                unsigned int mIsPriority : 1;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x78
        u32 mLinkID;  // offset: 0x7c
        u32 mLinkIdx;  // offset: 0x80
        u32 mTargetHandlingType;  // offset: 0x84
        u32 mTargetHandlingTypeThink;  // offset: 0x88
        static MyDTI DTI;
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    class cThinkMgrTargetMgr : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cThinkMgrTargetMgr();
        // Address: 0x01a65610 - 0x01a65611 (1 bytes)
        virtual ~cThinkMgrTargetMgr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void updatePtr();
        void initTargetHandlingData(u32 clridx);
        void setTargetHandlingDataIdx(u32 typeIdxBit, u8 idx);
        cThinkMgrName::cThinkMgrTargetData* getTargetHandlingData(u32, bool);
        cThinkMgrName::cThinkMgrTargetData* getpTargetData(u32 idx);
        bool setTargetData(MtObject* pTgt, u32 idx, u32 id, const MtVector3& myPos, const MtVector3& targetPos, f32 targetAngleY, f32 xyzlen, f32 xzlen, f32 degang, f32 height, bool isPri, u32 targetHandlingType, f32 pri, u64 status, u64 statusBefore, u32 motState, bool enable);
        void initTargetDataRealPosIdx();
        void initTargetDataRealPosIdxFree();
        void initTargetDataRealPosIdxPos();
        void initTargetDataRealPosIdx(u32 idx);
        u32 getTargetDataRealPosIdx();
        u32 getAndAddTargetDataRealPosIdx();
        void addTargetDataRealPosIdx();
        void initAllTargetData();
        void recalculationTargetData(MtVector3& myPos, f32 myAngleYRad);
        void clrTargetHandlingTypeThink();
        bool setTargetType(u32, u32, u32);
        u32 getTargetTypeBit(u32);
        u32 getTargetID(u32);
        void calcTargetData();
        u8 getPriorityOrder(u32 idx);
        u8* getpPriorityOrder();
        u8 getNearOrder(u32 idx);
        u8* getpNearOrder();
        u32 getSelectNewTargetIdx();
        void clrSelectNewTargetIdx();
        void setSelectNewTargetIdx(u32 targetDataIdx);
        cThinkMgrName::cThinkMgrTargetData* getpNewTarget();
        void setTargetOrderList(u32 targetDataIdx, bool setSelectNewTargetEnable, u32 idx);
        void clrTargetOrderList();
        u32 getTargetOrderList(u32 listIdx);
        bool setTargetOrderList(u32 listIdx, u32 dataIdx);
        u32 getNewTargetOderNum();
        void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
        void clrLinkID();
    private:
        cThinkMgrName::cThinkMgrTargetData mTargetData[23];  // offset: 0x10
        u32 mTargetDataRealTargetIdx;  // offset: 0xd00
        u8 mPriorityOrder[23];  // offset: 0xd04
        u8 mNearOrder[23];  // offset: 0xd1b
        u32 mTargetHandlingDataIdx[16];  // offset: 0xd34
        u32 mNewTargetOderList[23];  // offset: 0xd74
        u32 mSelectNewTargetIdx;  // offset: 0xdd0
        u32 mNewTargetOderNum;  // offset: 0xdd4
    public:
        cThinkMgrName::cTargetLink mTargetLink;  // offset: 0xdd8
        u32 mLinkID;  // offset: 0xdf8
        u32 mLinkIDIdx;  // offset: 0xdfc
        static MyDTI DTI;
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    class cThinkTblList : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cThinkTblList();
        virtual ~cThinkTblList();
        void init();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setThinkTblList(kTHINKDATA* * tblList, u32 tblCount);
        void setThinkTblList(rkThinkData* tblList);
        kTHINKDATA* getThinkTbl(s32 tblIdx);
        static u32 getThinkTblNum(kTHINKDATA* pThinkTbl);
        u32 getThinkTblNum(s32 tblIdx);
        u32 getThinkListNum();
    private:
        kTHINKDATA* * mpThinkTblList;  // offset: 0x8
        rkThinkData* mpThinkTblRes;  // offset: 0x10
        u32 mtblListNum;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINKCOUNT
    {
    public:
        s32 no;  // offset: 0x0
        s32 group;  // offset: 0x4
        s32 count;  // offset: 0x8
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINKTIMER
    {
    public:
        s32 no;  // offset: 0x0
        s32 group;  // offset: 0x4
        f32 timer;  // offset: 0x8
        union
        {
        public:
            u32 mIsTimerType;  // offset: 0x0
            struct
            {
            public:
                unsigned int mEnable : 1;  // offset: 0x0
                unsigned int mIsCountUp : 1;  // offset: 0x0
                unsigned int mIsCountDown : 1;  // offset: 0x0
                unsigned int mIsProgramReset : 1;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0xc
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINK_ADD_IDX
    {
    public:
        u32 offset_address;  // offset: 0x0
        u32 idx;  // offset: 0x4
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINK_FREE_WORK
    {
    public:
        u8 work_a;  // offset: 0x0
        u8 work_b;  // offset: 0x1
        u8 work_c;  // offset: 0x2
        u8 work_d;  // offset: 0x3
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINKRETSET
    {
    public:
        kTHINKDATA* pThinkTblRet;  // offset: 0x0
        cThinkMgrName::kTHINK_ADD_IDX uRetTbl;  // offset: 0x8
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    struct kTHINKRETSET_CHK
    {
    public:
        bool enable;  // offset: 0x0
        cThinkMgrName::kTHINKRETSET tbl;  // offset: 0x8
    };
}  // namespace cThinkMgrName

namespace cThinkMgrName {
    class cThinkMgr : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cThinkMgr();
        virtual ~cThinkMgr();
        void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
        void updatePtr();
        void NextThinkTimer(f32 rate);
        bool setThinkTbl(kTHINKDATA* thinktbl, bool chk);
        bool setThinkTbl(u8* thinktbl, bool chk);
        bool setThinkTbl(s32 thinktblIdx, bool chk);
        bool ResetThinkTbl(bool clrEnable);
        void setResetThinkTbl(u8* thinktbl);
        void setResetThinkTbl(kTHINKDATA*);
        bool setResetThinkTbl(s32 thinktblIdx);
        bool startMainThinkTbl();
        void setMainThinkTbl(u8*);
        void setMainThinkTbl(kTHINKDATA*);
        bool setMainThinkTbl(s32 thinktblIdx);
        void checkStartTbl();
        s32 GetActionNo(const MtVector3& myPos, const MtVector3& targetPos, f32 targetAngleY, u32 motState, f32 xyzleng, f32 leng, f32 degang, f32 height, f32 Lv, bool bnextback);
        s32 GetActionNo(cThinkMgrName::cThinkMgrTargetData* pTargetData, f32 Lv, bool bnextback);
        s32 GetActionNo(f32 Lv, bool bnextback);
        void setActionNo_NoGet();
        bool setTargetData(MtObject* pTgt, u32 idx, u32 id, const MtVector3& myPos, const MtVector3& targetPos, f32 targetAngleY, f32 xyzlen, f32 xzlen, f32 degang, f32 height, bool isPri, u32 targetHandlingType, f32 pri, u64 status, u64 statusBefore, u32 motState, bool enable);
        bool setTargetData(u32 idx, cThinkMgrName::cThinkMgrTargetData* pTargetData);
        void flgClr();
        bool isOlg_A();
        void clrComboFlg();
        void setComboFlg();
        bool isCombo();
        void clrOwFlg();
        void setOwFlg();
        bool isOw();
        bool isActTrue();
        void setActTrue(bool);
        bool isActEnd();
        bool setActEnd(bool enable);
        bool isStartTbl();
        void InitTimer();
        void InitTimerProgramReset();
        void InitTimer(s32 num, f32 group);
        void InitPassCount();
        void InitPassCount(s32 num, f32 group);
        f32 getUsrParam(u32);
        void setZeroUsrParam(u32);
        void setUserFlg(u32 idx, bool flg);
        bool getUserFlg(u32);
        void setUserFlgBit(u64 bit, bool flg);
        bool getUserFlgBit(u64 bit);
        void setWaitFlg(bool enable, f32 frame);
        void clrWaitFlg();
        bool setTableScale(f32 scale, bool enable);
        f32 getTableScale();
        f32 getTableScaleSmallOff();
        void initTableScale();
        virtual bool usrThinkCheck(const kTHINKDATA& tbl);  // vtable slot 6
        void setLen(f32);
        void setDegAng(f32);
        void setHeight(f32);
        void setLv(f32);
        void setMotStatus(u32);
        void setMtObj(MtObject* pMtObj);
        void* getUserFuncRet();
        u8* getThinkTbl();
        void setTempThinkTbl(u8*);
        u8* getTempThinkTbl();
        void clrNextFlg();
        bool isNext();
        bool setNextFlgTbl();
        void clrActNoPass();
        void copyBit(cThinkMgrName::cThinkMgr& think);
        void clrBit();
        u32 getBit();
        void setOnceBitOn(u32 onbitOnce);
        void setOnceBitOff(u32 offbitOnce);
        void setOnceBitOnNo(u32);
        void setOnceBitOffNo(u32);
        u32 getOnceBit();
        void setOnceBit(u32);
        void setFreeWork(u8, u8);
        s32 SetThinkTimer(s32 num, f32 timer, s32 group, bool enable, bool progReset, bool countUp, bool countDown, bool overwrite);
        s32 SetThinkPassCount(s32 num, s32 count, s32 group);
        f32 getGroupTimer(s32 groupNo);
        bool checkFreeWork(u32 work, u8 freeparam);
        u8 CalcFreeWork(u32 work, u8 freeparam);
        bool checkTargetData(u32 targetDataIdx);
        u8 getTargetType_Priority(u8* priorityIdx, u32 targetType);
        void firsttimeOrderCount(bool& loopscript);
        bool setOrder(u32 targetDataIdx, bool setSelectNewTargetEnable);
        bool checkOrderData(u32 targetDataIdx);
        bool checkSelectNewTargetIdx();
        bool checkSelectNewTargetIdxType(u32 type);
        bool checkSelectNewTargetIdxId(u32 id);
        bool setScriptTargetHandlingDataIdx(u32 targetDataIdx);
        bool setScriptTargetHandlingDataIdx(u32 targetDataIdx, u32 handtypeBit);
        void InitRetSet();
        cThinkMgrName::kTHINKRETSET_CHK checkRetSet();
        void InitRev();
        void pushRev(kTHINKDATA* top, u32 idx, u32 offset_add);
        void pushRev(cThinkMgrName::kTHINKRETSET tbl);
        cThinkMgrName::kTHINKRETSET popRev();
        cThinkMgrName::kTHINKRETSET_CHK checkRevFlg();
        void Init();
        s32 checkTimer(s32 chkActionNo, s32 chkGroupNo);
        s32 checkPassCount(s32 chkActionNo, s32 chkGroupNo);
        void startTimerCount();
        void NextThinkPassCount();
        s32 thinkCheck(const kTHINKDATA& tbl);
        s32 usrFlgCheck(u64 flg);
        bool thinkScriptFlgCheck(u8* tbladdr);
        bool thinkScriptCheck(kTHINKDATA& tbl, bool& loopscript, bool& restartScript);
        void setbackNextFlgTbl();
        void getbackNextFlgTbl();
        void saveNextFlgTbl(u8* rutetbl, u8* nowtbl, u32 idx, u32 idxno);
        u32 loadNextFlgTbl();
        cThinkMgrName::kTHINKRETSET rndIdxCnt(u8* pThinkTbl, u32 address, u32 idx, bool rndstart);
        s32 checkThinkMgrFunction(const kTHINKDATA& tbl, u32 functype, u32 funcno, u32 value);
        s32 setThinkMgrFunction(const kTHINKDATA& tbl, u32 functype, u32 funcno, u32 value, bool& loopScript);
        bool thinkScriptSet(const kTHINKDATA& tbl, u64 flg, u32 functype, u32 value, bool& loopscript, bool bOnceBit);
        bool thinkScriptFlgCheck_Sub(const kTHINKDATA& tbl, u64 flg, u32 functype, u32 value);
        s32 checkFunction(const kTHINKDATA& tbl, u32 functype, u32 funcno, u32 value);
        s32 checkFunctionExe(const kTHINKDATA& tbl, u32 functype, u32 funcno, u32 value);
        static u32 getNexOffsetAdd(u32 tbltype);
        cThinkMgrName::cThinkTblList* getThinkTblList();
    public:
        bool mbCheck[32];  // offset: 0x8
        f32 mfUserParam[5];  // offset: 0x28
        f32 mfSystemParam[3];  // offset: 0x3c
    private:
        f32 mTableScale;  // offset: 0x48
        bool mbTableScaleEnable;  // offset: 0x4c
    public:
        bool(*m_pUserChkFunc)(cThinkMgrName::cThinkMgr*, const kTHINKDATA&, u32, u32, MtObject*);  // offset: 0x50
        void* (*m_pUserFunc)(cThinkMgrName::cThinkMgr*, const kTHINKDATA&, u32, u32, MtObject*);  // offset: 0x58
        bool(*m_pSetFunc)(const kTHINKDATA&, MtObject*);  // offset: 0x60
        bool(*m_pTargetType)(cThinkMgrName::cThinkMgr*, MtObject*, u32);  // offset: 0x68
        bool(*m_pTargetFunc)(const kTHINKDATA&, MtObject*, cThinkMgrName::cThinkMgr*, u32);  // offset: 0x70
        cThinkMgrName::kTHINK_FREE_WORK mFreeWork;  // offset: 0x78
        u32 mTraceIdx;  // offset: 0x7c
        cThinkMgrName::cThinkMgrTargetMgr mTargetMgr;  // offset: 0x80
        bool mbTargetModeEnable;  // offset: 0xe80
        f32 mfLeng;  // offset: 0xe84
        f32 mfDegAng;  // offset: 0xe88
        f32 mfHeight;  // offset: 0xe8c
        u32 mMotState;  // offset: 0xe90
        f32 mLv;  // offset: 0xe94
        union
        {
        public:
            u32 mIsChangeStatus;  // offset: 0x0
            struct
            {
            public:
                unsigned int mIsChangLength : 1;  // offset: 0x0
                unsigned int mIsChangDegAng : 1;  // offset: 0x0
                unsigned int mIsChangHeight : 1;  // offset: 0x0
                unsigned int mIsChangLv : 1;  // offset: 0x0
                unsigned int mIsMotStatus : 1;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0xe98
        bool mbRndStart;  // offset: 0xe9c
        f32 mfRndProb;  // offset: 0xea0
        f32 mfRndSubProb;  // offset: 0xea4
        u8* mpThinkTbl;  // offset: 0xea8
        u8* mpThinkTblReset;  // offset: 0xeb0
        u8* mpThinkTblMain;  // offset: 0xeb8
        bool mbComboFlg;  // offset: 0xec0
        bool mbOwFlg;  // offset: 0xec1
        bool mbWaitEnable;  // offset: 0xec2
        f32 mfWaitTime;  // offset: 0xec4
        u8* mpTempThinkTbl;  // offset: 0xec8
        u32 mRetSetStackPush;  // offset: 0xed0
        cThinkMgrName::kTHINKRETSET mRetSetStack[16];  // offset: 0xed8
        bool mbRetEndEnable;  // offset: 0xfd8
        bool mbRevTopEnable;  // offset: 0xfd9
        bool mbRevRetEnable;  // offset: 0xfda
        u32 mRevCntN;  // offset: 0xfdc
        cThinkMgrName::kTHINKRETSET mRevTblDat[4];  // offset: 0xfe0
        cThinkMgrName::kTHINKTIMER mkTimer[32];  // offset: 0x1020
        cThinkMgrName::kTHINKCOUNT mkPassCount[8];  // offset: 0x1220
        u8 mbStartTableMode;  // offset: 0x1280
        bool mbNextFlg;  // offset: 0x1281
        bool mbUseNext;  // offset: 0x1282
        bool mbOlgFlag;  // offset: 0x1283
        bool mbActTrueFlg;  // offset: 0x1284
        bool mbActEndFlg;  // offset: 0x1285
        u8* mpOldSelectThinkTbl;  // offset: 0x1288
        u8* mpOldTopSelectThinkTbl;  // offset: 0x1290
        u8* mpTopSelectThinkTbl;  // offset: 0x1298
        u32 mOldSelectIdxNo;  // offset: 0x12a0
        u32 mOldSelectTraceIdxNo;  // offset: 0x12a4
        u8* mpTempOldSelectThinkTbl;  // offset: 0x12a8
        u8* mpTempOldTopSelectThinkTbl;  // offset: 0x12b0
        u32 mTempOldSelectIdxNo;  // offset: 0x12b8
        u32 mTempOldSelectTraceIdxNo;  // offset: 0x12bc
        bool mbTempNextFlg;  // offset: 0x12c0
        MtObject* m_pMtObj;  // offset: 0x12c8
        void* m_pUserFuncRet;  // offset: 0x12d0
        s32 mActPassNo;  // offset: 0x12d8
        bool mbActPassNoFlg;  // offset: 0x12dc
        u32 mTblBitCtrl;  // offset: 0x12e0
        u32 mTblBitOnceCtrl;  // offset: 0x12e4
    private:
        cThinkMgrName::cThinkTblList mcThinkTblList;  // offset: 0x12e8
    public:
        static MyDTI DTI;
        static const s32 THK_USER_FLG_NUM = 32;
    };
}  // namespace cThinkMgrName

// Inline, no code of its own: checked where it is inlined.
inline cThinkMgrName::cTargetLink::cTargetLink() {
    this->mIdx = static_cast<u32>(0);
    this->mLinkID = static_cast<u32>(0);
    this->mIdxMax = static_cast<u32>(0);
    this->mIsDown = true;
    this->mMoveMode = static_cast<cThinkMgrName::cTargetLink::TARGETLINK_MODE>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool cThinkMgrName::cThinkMgr::isActTrue() {
    return this->mbActTrueFlg;
}

// Inline, no code of its own: checked where it is inlined.
inline cThinkMgrName::cThinkTblList::cThinkTblList() {
    this->mtblListNum = static_cast<u32>(0);
    this->mpThinkTblRes = static_cast<rkThinkData*>(nullptr);
    this->mpThinkTblList = static_cast<kTHINKDATA* *>(nullptr);
}
