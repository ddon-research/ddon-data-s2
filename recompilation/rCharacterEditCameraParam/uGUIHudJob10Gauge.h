#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/nGUIHudJob10.h"
#include "uGUIBaseExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIObjChildAnimationRoot;
class cGUIObjNull;
namespace nGUIBaseExt { struct ResInfo; }

// Declarations
class uGUIHudJob10Gauge;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class uGUIHudJob10Gauge : public uGUIBaseExtHud
{
public:
    enum MODE
    {
        MODE_NORMAL = 0,
        MODE_NORMAL_FULL = 1,
        MODE_BOOST_START = 2,
        MODE_BOOST = 3,
        MODE_INVALID = -1,
    };
public:
    class MyDTI;
    struct State;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct State
    {
    public:
        State();
        void set(nGUIHudJob10::GAUGE_MODE gaugeMode, f32 gaugeValue, f32 gaugeValueMax);
        void set(f32 gaugeValue, f32 gaugeValueMax);
    public:
        nGUIHudJob10::GAUGE_MODE mGaugeMode;  // offset: 0x0
        f32 mGaugeValue;  // offset: 0x4
        f32 mGaugeValueMax;  // offset: 0x8
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
    uGUIHudJob10Gauge();
    virtual ~uGUIHudJob10Gauge();
    void updateState(nGUIHudJob10::GAUGE_MODE gaugeMode, f32 gaugeValue, f32 gaugeValueMax);
    void updateState(nGUIHudJob10::GAUGE_MODE gaugeMode);
    void updateState(f32 gaugeValue, f32 gaugeValueMax);
protected:
    virtual MT_CTSTR getLoadArcTagName(u32 arcIndex) const;  // vtable slot 91
    virtual const nGUIBaseExt::ResInfo* getGuiResInfo() const;  // vtable slot 93
    virtual t64 getGuiResUpdateTime() const;  // vtable slot 94
    virtual void onSetupAfterLoad();  // vtable slot 113
    virtual void onShow();  // vtable slot 106
    virtual void onUpdateShow();  // vtable slot 110
    void setupObjects();
    MODE getNextMode() const;
    void applyMode(MODE mode);
    void applyGaugeMode(nGUIHudJob10::GAUGE_MODE gaugeMode);
    void applyGaugeValue(f32 gaugeValue, f32 gaugeValueMax);
protected:
    MODE mMode;  // offset: 0x904
    cGUIInstAnimation* mpINST_fix_job10;  // offset: 0x908
    cGUIObjChildAnimationRoot* mpOBJ_fix_job10_fix_icon01;  // offset: 0x910
    cGUIObjChildAnimationRoot* mpOBJ_fix_job10_fix_icon02;  // offset: 0x918
    cGUIObjChildAnimationRoot* mpOBJ_fix_job10_fix_gauge00;  // offset: 0x920
    cGUIObjNull* mpOBJ_fix_gauge00_Null_root;  // offset: 0x928
    cGUIObjNull* mpOBJ_fix_gauge00_Null_gauge;  // offset: 0x930
    cGUIObjChildAnimationRoot* mpOBJ_fix_gauge00_gauge_light;  // offset: 0x938
    State mState;  // offset: 0x940
    State mNextState;  // offset: 0x94c
public:
    static MyDTI DTI;
};
