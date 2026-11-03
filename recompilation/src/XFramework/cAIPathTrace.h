#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "cAI.h"
#include "cAISvPathFinding.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cAISvPathFinding;
class cAITaskJobPrimList;

// Declarations
class cAINavPathTrace;
class cAIPathTrace;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cAIPathTrace : public cAIAStar
{
public:
    enum COMPARE_ATTRIBUTE
    {
        COMPARE_AND = 1,
        COMPARE_OR = 2,
        COMPARE_CURRENT = 16,
        COMPARE_FRONT = 32,
        COMPARE_BACK = 64,
    };
    enum INTERRUPTION_ATTR
    {
        INTERRUPTION_LINK = 1,
        INTERRUPTION_TIMEOUT = 2,
    };
    enum TRACE_STATE
    {
        TRACE_NONE = 0,
        TRACE_INTERRUPTION = 1,
        TRACE_SEARCH = 2,
        TRACE_CONTINUE = 3,
        TRACE_END = 4,
    };
public:
    class MyDTI;
    class TracePoint;
public:
    using NODE_CALLBACK = void(MtObject::*)(cAISvPathFinding::Node&, f32&);
    using LINK_CALLBACK = bool(MtObject::*)(cAISvPathFinding::Node&, cAISvPathFinding::Node&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class TracePoint : public MtObject
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
        TracePoint();
        virtual ~TracePoint() {}
    public:
        u32* mpData;  // offset: 0x8
        u32 mLinkAttribute;  // offset: 0x10
        MtVector3 mPos;  // offset: 0x20
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
    cAIPathTrace();
    virtual ~cAIPathTrace();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool setNode(const MtVector3& sPos, const MtVector3& ePos, bool f);  // vtable slot 7
    void setNode(cAIGraph::Node* startNode, cAIGraph::Node* endNode);
    void setPathFinding(cAISvPathFinding* pPath, s32 index);
    void setEvaluationFunc(NODE_CALLBACK, MtObject*);
    void setLinkEvaluationFunc(LINK_CALLBACK func, MtObject* obj);
    virtual u32 trace(MtVector3& dest, const MtVector3& pos, f32 r, bool f);  // vtable slot 8
    cAIGraph::Node* getStartNode();
    cAIGraph::Node* getEndNode();
    cAISvPathFinding* getPathFinding();
    virtual cAISvPathFinding::Node* getResultNode(u32 index);  // vtable slot 9
    u32 getResultNodeAttribute(u32 id, u32 index);
    s32 isCompareAttributeOfResultNode(u32 param, u32 attr, s32 index, u32 num);
    u32 getTargetNode();
    u32 getCurrentNode();
    void setCurrentNode(u32);
    u32 getNumberOfTracePoint();
    TracePoint* getTracePoint(u32);
    virtual MtVector3 getTracePos(u32 index);  // vtable slot 10
    f32 getLength();
    u32 getSearchState();
    bool isSearch();
    bool isSearch(cAIGraph::Node* startNode, cAIGraph::Node* endNode);
    void clear();
    bool isDynamicPath();
    void setInterrupte(bool f);
    void setDynamicPath(bool f);
    bool isCurvePath();
    void setCurve(bool);
    void setAxisY(bool);
    void setWeight(f32);
    void setNumberOfCurvePoint(u32);
    void setWall(f32);
    void setPathRevision(bool f);
    void setSizeEnable(bool f);
    void setLinkSize(f32);
    void setLinkHeight(f32);
    void setLinkOffset(f32);
    void setBackCheck(bool f);
    void setInterruptionCheck(bool f, u32 attr);
    void setTimeOut(f32);
protected:
    virtual void reset(bool f);  // vtable slot 11
    void createCurve();
    virtual void setCurveNode(u32 index0, u32 index1, u32 num, MtArray* pA) {}  // vtable slot 12
    bool isCompareAttribute(cAISvPathFinding::Node* pNode, u32 param, u32 attr, s32 index);
    bool isInterruption(cAISvPathFinding* pFind);
    bool isInterruption(cAIGraph::Node* pCurrent, cAIGraph::Node* pNext);
public:
    u32 getCurrentGroup();
protected:
    bool DynamicPathJudge(const MtLineSegment& line, u32& gIndex);
    bool DynamicPathJudge(const MtVector3& pos);
    u32 pathComposition(u32 sIndex, u32 gIndex, const MtVector3& pos);
    virtual bool intersectRegion(MtVector3& p, u32& index, const MtAABB& aabb);  // vtable slot 13
    virtual bool getProjectionPos(const MtVector3& pos, MtVector3& tPos);  // vtable slot 14
    virtual bool isNode(const MtVector3& pos);  // vtable slot 15
    virtual void EvaluateFunc(MtObject* adr1, f32& cost);  // vtable slot 16
    virtual bool LinkEvaluateFunc(MtObject* adr1, MtObject* adr2);  // vtable slot 17
    virtual f32 HeuristicFunc(MtObject* adr1, MtObject* adr2);  // vtable slot 18
    virtual bool AreaRegionFunc(MtObject*, MtObject*, bool&, bool&, MtObject*);  // vtable slot 19
    virtual void AreaStatusFunc(u8* statusFlag, MtObject* result, u32 rnum) {}  // vtable slot 20
    virtual bool SizeEvaluateFunc(MtObject* adr1, u32 index);  // vtable slot 21
protected:
    u32 mIndex;  // offset: 0x1d0
    MtArray mTracePoint;  // offset: 0x1d8
    f32 mAmountOfMovement;  // offset: 0x1f8
    u32 mSearchState;  // offset: 0x1fc
    cAIGraph::Node* mpStartNode;  // offset: 0x200
    cAIGraph::Node* mpEndNode;  // offset: 0x208
    MtVector3 mStartPos;  // offset: 0x210
    MtVector3 mEndPos;  // offset: 0x220
    f32 mLength;  // offset: 0x230
    cAISvPathFinding* mpPath;  // offset: 0x238
    s32 mMatrixIndex;  // offset: 0x240
    MtObject* mpNCOwner;  // offset: 0x248
    NODE_CALLBACK mpNodeCallback;  // offset: 0x250
    MtObject* mpLCOwner;  // offset: 0x260
    LINK_CALLBACK mpLinkCallback;  // offset: 0x268
    bool mPathRevision;  // offset: 0x278
    bool mSizeEnable;  // offset: 0x279
    f32 mLinkSize;  // offset: 0x27c
    f32 mLinkHeight;  // offset: 0x280
    f32 mLinkOffset;  // offset: 0x284
    u16 mPreFrontIndex;  // offset: 0x288
    u16 mPreBackIndex;  // offset: 0x28a
    bool mBackCheck;  // offset: 0x28c
    bool mSearchOnly;  // offset: 0x28d
    bool mDynamicPathEnable;  // offset: 0x28e
    bool mPathType;  // offset: 0x28f
    bool mInterrupte;  // offset: 0x290
    bool mUpdate;  // offset: 0x291
    u32 mGIndex;  // offset: 0x294
    MtArray mDynamicTracePoint;  // offset: 0x298
    u32 mNumberOfGroup;  // offset: 0x2b8
    u32* mpGroupIndex;  // offset: 0x2c0
    s32 mCurrentGroup;  // offset: 0x2c8
    f32 mOffset;  // offset: 0x2cc
    bool mEnableCurve;  // offset: 0x2d0
    bool mEnableAxisY;  // offset: 0x2d1
    f32 mWeight;  // offset: 0x2d4
    u32 mNumberOfCurvePoint;  // offset: 0x2d8
    f32 mSlope;  // offset: 0x2dc
    bool mInterruption;  // offset: 0x2e0
    u8 mInterruptionAttribute;  // offset: 0x2e1
    f32 mCurrentTime;  // offset: 0x2e4
    f32 mTimeOut;  // offset: 0x2e8
public:
    static MyDTI DTI;
};

class cAINavPathTrace : public cAIPathTrace
{
public:
    enum AXIS
    {
        AXISX = 0,
        AXISY = 1,
        AXISZ = 2,
    };
public:
    class MyDTI;
public:
    using AREA_CALLBACK = void(MtObject::*)(cAISvNavPathFinding::NavArea&, f32&);
    using AREA_LINK_CALLBACK = bool(MtObject::*)(cAISvNavPathFinding::NavArea&, cAISvNavPathFinding::NavArea&);
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
    cAINavPathTrace();
    virtual ~cAINavPathTrace();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createJobList(cAITaskJobPrimList& list);  // vtable slot 6
    virtual bool setNode(const MtVector3& sPos, const MtVector3& ePos, bool f);  // vtable slot 7
    void setUnder(f32 h);
    f32 getUnder();
    void setOver(f32 o);
    f32 getOver();
    void setPreStraightCheck(bool);
    void setPreStraightCheckSecurity(bool);
    virtual u32 trace(MtVector3& dest, const MtVector3& pos, f32 r, bool f);  // vtable slot 8
    void setAreaEvaluationFunc(AREA_CALLBACK, MtObject*);
    void setAreaLinkEvaluationFunc(AREA_LINK_CALLBACK, MtObject*);
    virtual cAISvPathFinding::Node* getResultNode(u32 index);  // vtable slot 9
    bool isStraightLine(const MtLineSegment& ls, cAIGraph::Node* pStart, cAIGraph::Node* pEnd, s32 prePortal);
    void setEndPointRevision(bool f);
    void setStartPointRevision(bool);
    void preSearchNodeJob();
    void searchAreaJob();
    void searchNodeJob();
    void straightJob();
protected:
    void createStraightPath(const MtVector3& startPos);
    void createStraightPathToRandom(const MtVector3& startpos);
    bool crossLine(const MtLineSegment& ls0, const MtLineSegment& ls1, u32 axis);
    virtual bool getProjectionPos(const MtVector3& pos, MtVector3& tPos);  // vtable slot 14
    virtual bool isNode(const MtVector3& pos);  // vtable slot 15
    virtual void setCurveNode(u32 index0, u32 index1, u32 num, MtArray* pA);  // vtable slot 12
    virtual void EvaluateFunc(MtObject* adr1, f32& cost);  // vtable slot 16
    virtual bool LinkEvaluateFunc(MtObject* adr1, MtObject* adr2);  // vtable slot 17
    virtual bool AreaRegionFunc(MtObject* adr1, MtObject* adr2, bool& start, bool& end, MtObject* adr3);  // vtable slot 19
    virtual void AreaStatusFunc(u8* statusFlag, MtObject* result, u32 rnum);  // vtable slot 20
protected:
    f32 mHeight;  // offset: 0x2ec
    MtObject* mpAOwner;  // offset: 0x2f0
    AREA_CALLBACK mpAreaCallback;  // offset: 0x2f8
    MtObject* mpALOwner;  // offset: 0x308
    AREA_LINK_CALLBACK mpAreaLinkCallback;  // offset: 0x310
    bool mEnableSPointRevision;  // offset: 0x320
    bool mEnableEPointRevision;  // offset: 0x321
    bool mPreStraightExamination;  // offset: 0x322
    bool mPreStraightSec;  // offset: 0x323
    bool mEnableWidthRev;  // offset: 0x324
    f32 mWidthRev;  // offset: 0x328
public:
    static MyDTI DTI;
};

inline void* cAINavPathTrace::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIPathTrace::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cAIPathTrace::getNumberOfTracePoint() {
    return this->mTracePoint.mLength;
}

inline void cAIPathTrace::clear() {
    this->reset(false);
}

inline void* cAIPathTrace::TracePoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
