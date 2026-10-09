#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class sWorkRate;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sWorkRate : public cSystem
{
public:
    enum
    {
        WR_GLOBAL = 0,
        WR_GAME = 1,
        WR_PLAYER = 2,
        WR_ENEMY = 3,
        WR_SET = 4,
        WR_PL_CUSTOM_SKILL = 5,
        WR_NUM = 6,
    };
    enum
    {
        WR_PRIO_NONE = -1,
        WR_PRIO_00 = 0,
        WR_PRIO_01 = 1,
        WR_PRIO_02 = 2,
        WR_PRIO_03 = 3,
        WR_PRIO_04 = 4,
        WR_PRIO_05 = 5,
        WR_PRIO_DEFAULT = 5,
        WR_PRIO_06 = 6,
        WR_PRIO_07 = 7,
        WR_PRIO_08 = 8,
        WR_PRIO_09 = 9,
        WR_PRIO_10 = 10,
    };
    enum
    {
        WRB_GLOBAL = 1,
        WRB_GAME = 2,
        WRB_PLAYER = 4,
        WRB_ENEMY = 8,
        WRB_SET = 16,
        WRB_PL_CUSTOM_SKILL = 32,
        WRB_WORLD = 35,
        WRB_PLAYER_DEFAULT = 39,
        WRB_ENEMY_DEFAULT = 43,
        WRB_NPC_DEFAULT = 43,
        WRB_OM_DEFAULT = 51,
        WRB_CAMERA_DEFAULT = 35,
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
    sWorkRate();
    virtual ~sWorkRate();
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static sWorkRate* getInstance();
    f32 calc(u32 bit);
    f32 calcRaw(u32 bit);
    void setWorkRate(s32 type, f32 rate, f32 frame, s32 prio);
    f32 getWorkRate(s32 type);
private:
    void initialize();
public:
    f32 getGameDeltaTime();
    f32 getGlobalDeltaTime();
private:
    f32 mRate[6];  // offset: 0x14
    f32 mMoveTimer[6];  // offset: 0x2c
    s32 mPrio[6];  // offset: 0x44
public:
    static MyDTI DTI;
private:
    static sWorkRate* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sWorkRate* sWorkRate::getInstance() {
    return ::sWorkRate::mpInstance;
}
