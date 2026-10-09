#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/cSystem.h"
#include "mouse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtUI;
struct SceMouseData;

// Declarations
class sMouse;

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

class sMouse : public cSystem
{
public:
    enum TYPE
    {
        TYPE_DEFAULT = 0,
        MAX_TYPE = 1,
    };
    enum BUTTON
    {
        BUTTON_0 = 1,
        BUTTON_1 = 2,
        BUTTON_2 = 4,
        BUTTON_3 = 8,
        BUTTON_4 = 16,
        BUTTON_5 = 32,
        BUTTON_6 = 64,
        BUTTON_7 = 128,
    };
public:
    class MyDTI;
    struct STATE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct STATE
    {
    public:
        MtPoint pos;  // offset: 0x0
        bool visible;  // offset: 0x8
        bool clip;  // offset: 0x9
        s32 ax;  // offset: 0xc
        s32 ay;  // offset: 0x10
        s32 az;  // offset: 0x14
        u32 on;  // offset: 0x18
        u32 old;  // offset: 0x1c
        u32 trg;  // offset: 0x20
        u32 release;  // offset: 0x24
        u32 change;  // offset: 0x28
        u32 rep;  // offset: 0x2c
        u64 rep_timer[8];  // offset: 0x30
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
    sMouse();
    virtual ~sMouse();
    virtual void move();  // vtable slot 7
    static sMouse* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setActive(bool);
    bool isActive();
    void setRepeatTime(u32, u32);
    u32 getOn(TYPE type) const;
    u32 getOld(TYPE type) const;
    u32 getTrigger(TYPE type) const;
    u32 getRelease(TYPE type) const;
    u32 getChange(TYPE type) const;
    u32 getRepeat(TYPE type) const;
    s32 getAxisX(TYPE type) const;
    s32 getAxisY(TYPE type) const;
    s32 getAxisZ(TYPE type) const;
    MtPoint getPosition(TYPE type);
    void setPosition(const MtPoint& pos, TYPE type);
    TYPE getCurrentType();
    bool isVisible(TYPE);
    void setVisible(bool v, TYPE type);
    bool isClip(TYPE type);
    void setClip(bool v, TYPE type);
    f32 getMouseBaseSpeed();
    void setMouseBaseSpeed(f32);
    bool isMouseConnected(s32 no);
    bool isSystemIntercepted();
protected:
    void updateState(STATE* pstate);
protected:
    STATE mState[1];  // offset: 0x18
    bool mCurrentVisible;  // offset: 0x88
    bool mCurrentClip;  // offset: 0x89
    bool mActive;  // offset: 0x8a
    u32 mRepeatStartTime;  // offset: 0x8c
    u32 mRepeatTime;  // offset: 0x90
    f32 mMouseBaseSpeed;  // offset: 0x94
    s32 mMouseHandle;  // offset: 0x98
    bool mIsConnected[1];  // offset: 0x9c
    SceMouseData m_mouseData[64];  // offset: 0xa0
    bool mIsSystemIntercepted;  // offset: 0xaa0
public:
    static MyDTI DTI;
    static const s32 BUTTON_L = 1;
    static const s32 BUTTON_R = 2;
    static const s32 BUTTON_M = 4;
protected:
    static const s32 MOUSE_MAX_NUM = 1;
    static const s32 MOUSE_MAX_CACHE = 64;
    static sMouse* mpInstance;
};
