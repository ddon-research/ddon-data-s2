#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cArea.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cArcLoaderBase;

// Declarations
class aGame;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class aGame : public cArea
{
public:
    enum MOVE_PROFILE
    {
        MOVE_PROFILE_000_MOVE_PLAYERMANAGER = 0,
        MOVE_PROFILE_010_MOVE_ENEMYMANAGER = 1,
        MOVE_PROFILE_020_MOVE_CONTROLMANAGER = 2,
        MOVE_PROFILE_030_MOVE_NPCMANAGER = 3,
        MOVE_PROFILE_040_MOVE_OMMANAGER = 4,
        MOVE_PROFILE_050_MOVE_SHELLMANAGER = 5,
        MOVE_PROFILE_055_MOVE_BAZAARMANAGER = 6,
        MOVE_PROFILE_060_MOVE_SOUNDMANAGER = 7,
        MOVE_PROFILE_070_MOVE_EVENTMANAGER = 8,
        MOVE_PROFILE_080_MOVE_TUTORIALGUIDEMANAGER = 9,
        MOVE_PROFILE_090_MOVE_FLAG = 10,
        MOVE_PROFILE_100_MOVE_SCREEN_SHOT = 11,
        MOVE_PROFILE_NUM = 12,
    };
    enum
    {
        LOAD_R0_INIT = 0,
        LOAD_R0_MOVE = 1,
        LOAD_R0_EXIT = 2,
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
    aGame();
    virtual ~aGame();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    void setupProfile();
    void beginProfile(MOVE_PROFILE phase);
    void endProfile();
private:
    TICKET mArcTicket;  // offset: 0x30
public:
    static MyDTI DTI;
};
