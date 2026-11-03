#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtUI;
class uDDOModel;

// Declarations
class cpMotionHistory;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpMotionHistory : public cpComponent
{
public:
    enum
    {
        MOT_TYPE_HISTORY_MAX = 4,
    };
public:
    class MyDTI;
    struct stHistoryMotData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stHistoryMotData
    {
    public:
        u32 motNo;  // offset: 0x0
        f32 frame;  // offset: 0x4
        f32 frameMax;  // offset: 0x8
        f32 speed;  // offset: 0xc
        u32 attr;  // offset: 0x10
        f32 blendRate;  // offset: 0x14
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
    cpMotionHistory();
    virtual ~cpMotionHistory();
    virtual void setup();  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    void calcHistoryBlend();
    void setMotionHistory();
    void setHistoryBlendMotion();
    void setParentUnit(uDDOModel* pParent);
    uDDOModel* getParentUnit();
    virtual void updatePtr();  // vtable slot 9
    void setIsSetHistory(bool flag);
    bool isSetHistory();
    void setHistoryMotType(u32 baseStart, u32 historyStart, u32 typeNum);
    u32 getBaseMotTypeStartNo();
    u32 getHistoryMotTypeStartNo();
    u32 getHistoryMotTypeNum();
    void setEnable(bool);
protected:
    uDDOModel* mpParentUnit;  // offset: 0x50
    bool mIsSetHistory;  // offset: 0x58
    f32 mBlendCalcSpeed[4];  // offset: 0x5c
    u32 mBaseMotTypeStartNo;  // offset: 0x6c
    u32 mHistoryMotTypeStartNo;  // offset: 0x70
    u32 mHistoryMotTypeNum;  // offset: 0x74
    f32 mBlendStartRate[4];  // offset: 0x78
    f32 mKeyFrameMax;  // offset: 0x88
    stHistoryMotData mHistoryMotData[4];  // offset: 0x8c
public:
    static MyDTI DTI;
};

inline void* cpMotionHistory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
