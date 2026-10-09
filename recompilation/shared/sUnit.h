#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cDraw.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class cDraw;
class cGUIClanExecutor;
class cUnit;
class sRender;

// Declarations
class sUnit;

enum MOVE_LINE
{
    NOT_CHAINED = 127,
    LINE_0 = 0,
    LINE_1 = 1,
    LINE_2 = 2,
    LINE_3 = 3,
    LINE_4 = 4,
    LINE_5 = 5,
    LINE_6 = 6,
    LINE_7 = 7,
    LINE_8 = 8,
    LINE_9 = 9,
    LINE_10 = 10,
    LINE_11 = 11,
    LINE_12 = 12,
    LINE_13 = 13,
    LINE_14 = 14,
    LINE_15 = 15,
    LINE_16 = 16,
    LINE_17 = 17,
    LINE_18 = 18,
    LINE_19 = 19,
    LINE_20 = 20,
    LINE_21 = 21,
    LINE_22 = 22,
    LINE_23 = 23,
    LINE_24 = 24,
    LINE_25 = 25,
    LINE_26 = 26,
    LINE_27 = 27,
    LINE_28 = 28,
    LINE_29 = 29,
    LINE_30 = 30,
    LINE_31 = 31,
    LINE_32 = 32,
    LINE_33 = 33,
    LINE_34 = 34,
    LINE_35 = 35,
    LINE_36 = 36,
    LINE_37 = 37,
    LINE_38 = 38,
    LINE_39 = 39,
    LINE_40 = 40,
    LINE_41 = 41,
    LINE_42 = 42,
    LINE_43 = 43,
    LINE_44 = 44,
    LINE_45 = 45,
    LINE_46 = 46,
    LINE_47 = 47,
    LINE_48 = 48,
    LINE_49 = 49,
    LINE_50 = 50,
    LINE_51 = 51,
    LINE_52 = 52,
    LINE_53 = 53,
    LINE_54 = 54,
    LINE_55 = 55,
    LINE_56 = 56,
    LINE_57 = 57,
    LINE_58 = 58,
    LINE_59 = 59,
    LINE_60 = 60,
    LINE_61 = 61,
    LINE_62 = 62,
    LINE_63 = 63,
    MAX_MOVELINE = 64,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using MT_MFUNCPTRU32 = void(MtObject::*)(void*, u32);
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u64 = __uint64_t;

class sUnit : public cSystem
{
    // inferred: cGUIClanExecutor::~cGUIClanExecutor names sUnit::mpInstance
    friend class cGUIClanExecutor;
    // inferred: sRender::beforeMove names sUnit::mpInstance
    friend class sRender;
public:
    class MyDTI;
    class MoveLine;
    class UnitGroup;
public:
    using VALIDATE_RESULT_FUNC = void(MtObject::*)(MOVE_LINE, cUnit*, u64);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class MoveLine : public MtObject
    {
    public:
        enum ePhase
        {
            PHASE_NOP = 0,
            PHASE_MOVE = 1,
            PHASE_SYNC = 2,
            PHASE_MOVEAFTER = 3,
            PHASE_DRAW = 4,
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
        MoveLine();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        cUnit* getUnit(u32 index);
        void setUnit(cUnit* punit, u32 i);
        u32 getCount();
        void setCount(u32);
        bool isParallel();
        void setParallel(bool p);
        bool isPause();
        void setPause(bool pause);
        bool isDraw() const;
        void setDraw(bool t);
        f32 getDeltaTime() const;
        void setDeltaTime(f32 NewValue);
        void setCastDraw(bool b);
        bool getCastDraw() const;
        void setRecvDraw(bool b);
        bool getRecvDraw() const;
        ePhase getPhase() const;
        bool isInParallel() const;
    public:
        MT_CTSTR mName;  // offset: 0x8
        u32 mParallel : 1;  // offset: 0x10
        u32 mPause : 1;  // offset: 0x10
        u32 mDraw : 1;  // offset: 0x10
        u32 mLineType : 7;  // offset: 0x10
        u32 mPhase : 4;  // offset: 0x10
        u32 mIsInParallel : 1;  // offset: 0x10
        u32 mCastDraw : 1;  // offset: 0x10
        u32 mRecvDraw : 1;  // offset: 0x10
        cUnit* mpTop;  // offset: 0x18
        cUnit* mpBottom;  // offset: 0x20
        f32 mDeltaTime;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    class UnitGroup : public MtObject
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
        UnitGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        MT_CTSTR mName;  // offset: 0x8
        MtArray mUnits;  // offset: 0x10
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
    sUnit(u32 line_num, u32 group_num);
    virtual ~sUnit();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void moveAfter();  // vtable slot 10
    virtual void sync();  // vtable slot 11
    static sUnit* getInstance();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    u32 getCRC();
    u32 getLineNum();
    void setPause(MOVE_LINE, bool);
    bool isPause(MOVE_LINE n);
    void setDraw(MOVE_LINE, bool);
    bool isDraw(MOVE_LINE n) const;
    virtual MT_CTSTR getLineName(MOVE_LINE n);  // vtable slot 12
    bool isParallel(MOVE_LINE n);
    void setParralel(MOVE_LINE, bool);
    void setDeltaTime(MOVE_LINE, f32);
    f32 getDeltaTime(MOVE_LINE n);
    virtual void draw(cDraw* pdraw);  // vtable slot 13
    virtual void move(MOVE_LINE n);  // vtable slot 14
    virtual void moveAfter(MOVE_LINE n);  // vtable slot 15
    virtual void sync(MOVE_LINE n);  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, MOVE_LINE n, const MtVector3& absolute_offset);  // vtable slot 17
    bool remove(cUnit* punit);
    bool addTop(MOVE_LINE n, cUnit* punit, u64 groupbit);
    bool addTop(MOVE_LINE n, cUnit* punit, const cUnit* pSrcUnit);
    bool addBottom(MOVE_LINE n, cUnit* punit, u64 groupbit);
    bool addBottom(MOVE_LINE n, cUnit* punit, const cUnit* pSrcUnit);
    bool insertAfter(cUnit* ppos, cUnit* punit, u64 groupbit);
    bool insertBefore(cUnit* ppos, cUnit* punit, u64 groupbit);
    s32 getUnitNum(MOVE_LINE n);
    s32 getUnitNum();
    void killAll(MOVE_LINE n);
    void killAll();
    bool isEmpty(MOVE_LINE n);
    bool isEmpty();
    cUnit* getTopUnit(MOVE_LINE n);
    bool isChained(cUnit* punit);
    bool isDrawUnit(const cUnit* punit) const;
    virtual void forceFlushDrawCommandCache();  // vtable slot 18
    // Address: 0x01ba9490 - 0x01ba9491 (1 bytes)
    virtual void setForceFlushDrawCommandCacheCount(u32 set) {}  // vtable slot 19
    bool isDrawCommandCacheEnable() const;
    void setDrawCommandCacheEnable(bool b);
    void updateDrawCommandCache();
    u32 getGroupCount() const;
    void reserveUnitGroup(u32 group, u32 num);
    void setUnitGroupMove(u32 group, bool flag);
    void setUnitGroupDraw(u32 group, bool flag);
    virtual MT_CTSTR getGroupName(u32 group);  // vtable slot 20
    void setUnitGroupBit(cUnit* punit, u64 groupbit);
    virtual void setDefaultUnitGroup(cUnit* punit);  // vtable slot 21
    void setUnitGroup(cUnit* punit, u32 group);
    void removeUnitGroup(cUnit* punit);
    void removeUnitGroup(cUnit* punit, u32 group);
    void copyUnitGroup(cUnit* pDst, cUnit* pSrc);
    bool isGroupDraw(const cUnit* punit) const;
    bool isGroupMove(const cUnit* punit) const;
    bool isGroupDraw(u32 group) const;
    bool isGroupMove(u32 group) const;
    bool isGroupDraw(u64 groupbit) const;
    bool isGroupMove(u64 groupbit) const;
    const MtArray* getGroupArray(u32 group) const;
protected:
    MoveLine* getMoveLine(MOVE_LINE n);
    void removeUnitGroupAll(cUnit* punit);
    void updateDrawCommandCacheCore();
    // Address: 0x01ba94a0 - 0x01ba94a1 (1 bytes)
    virtual void evAddUnit(cUnit& unit) {}  // vtable slot 22
    // Address: 0x01ba94b0 - 0x01ba94b1 (1 bytes)
    virtual void evRemoveUnit(cUnit& unit) {}  // vtable slot 23
public:
    static void setValidateResultCallback(MtObject*, VALIDATE_RESULT_FUNC);
    MOVE_LINE getExecutingMoveLine() const;
    void resetDrawCommandCacheCount();
    void calcDrawCommandCacheRate();
    void incrementDrawCommandCacheCount();
    void incrementDrawCommandCacheFailedCount();
    void incrementDrawCommandCacheAll();
    void incrementDrawCommandCacheReCreate();
    u32 getInvolveSphereUnits(cDraw* pDraw, cUnit* * pUnitArray, u32 maxUnitNum, MtSphere& sphere);
    void drawInvolvingArray(cDraw* pdraw, cUnit* * pUnitArray, u32 unit_num);
private:
    void validateUnitChain(MOVE_LINE n, cUnit* pUnit, u64 groupbit);
public:
    void resetDrawHookCallback();
    void setDrawHookCallBack(MtObject* pparent, MT_MFUNCPTRU32 pcallback);
    void callDrawHookCallBack(cDraw* pDraw);
    void flipFlowCallBack(MtObject* pinstance, MT_MFUNC pcallback);
    void callFlipFlowCallBack();
    virtual u32 getMoveLineId(u32 i);  // vtable slot 24
    virtual u32 getNextMoveLineId(u32 i);  // vtable slot 25
    virtual u32 getPrevMoveLineId(u32 i);  // vtable slot 26
    virtual u32 getLastMoveLineId();  // vtable slot 27
    virtual u32 getMoveLineOrder(u32 i);  // vtable slot 28
    void updateHardwareDispCtrl();
private:
    MoveLine mMoveLine[64];  // offset: 0x18
    u32 mLineNum;  // offset: 0xc18
protected:
    u32 mCRC;  // offset: 0xc1c
private:
    UnitGroup mUnitGroup[64];  // offset: 0xc20
    u32 mGroupCount;  // offset: 0x1820
    u64 mGroupMoveFlag;  // offset: 0x1828
    u64 mGroupDrawFlag;  // offset: 0x1830
    cDraw mSubDraw[6];  // offset: 0x1838
    bool mbDrawCommandCacheEnable;  // offset: 0x372d58
    bool mbDrawCommandCacheEnableUpdate;  // offset: 0x372d59
public:
    bool mbLimitCastReceiver;  // offset: 0x372d5a
    MtObject* mpDrawHookInstance;  // offset: 0x372d60
    MT_MFUNCPTRU32 mpDrawHookCallBack;  // offset: 0x372d68
    MtObject* mpFlipFlowInstance;  // offset: 0x372d78
    MT_MFUNC mpFlipFlowCallBack;  // offset: 0x372d80
    static MyDTI DTI;
protected:
    static sUnit* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sUnit* sUnit::getInstance() {
    return ::sUnit::mpInstance;
}
