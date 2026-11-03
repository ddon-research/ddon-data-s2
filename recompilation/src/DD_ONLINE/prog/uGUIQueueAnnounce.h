#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cDraw;
class rGUI;

// Declarations
class uGUIQueueAnnounce;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQueueAnnounce : public uGUIBase
{
public:
    enum TYPE
    {
        TYPE_MAIN = 0,
        TYPE_SUB = 1,
        TYPE_BOARD = 2,
        TYPE_CLAN = 3,
        TYPE_GROUND = 4,
        TYPE_END = 5,
        TYPE_TUTORIAL = 6,
        TYPE_NUM = 7,
        TYPE_NONE = 7,
    };
    enum STATE
    {
        STATE_ACCEPT = 0,
        STATE_CANCEL = 1,
        STATE_CLEAR = 2,
        STATE_FAILED = 3,
        STATE_UPDATE = 4,
        STATE_DISCOVER = 5,
        STATE_PARTY_REWARD = 6,
        STATE_ALL_CLEAR = 7,
        STATE_START = 8,
        STATE_EX_UPDATE = 9,
        STATE_END = 10,
        STATE_CAUTION = 11,
        STATE_CLEAR_CAUTION = 12,
        STATE_WARNING = 13,
        STATE_CLEAR_WARNING = 14,
        STATE_PAWN_RESCUE_START = 15,
        STATE_PAWN_RESURRECTION = 16,
        STATE_PAWN_RESCUE_CLEAR = 17,
        STATE_PAWN_RESCUE_FAILED = 18,
        STATE_PAWN_LOST = 19,
        STATE_STAGE_START = 20,
        STATE_STAGE_CLEAR = 21,
        STATE_NEXT_STAGE = 22,
        STATE_JOB_LVUP = 23,
        STATE_CRAFT_LVUP = 24,
        STATE_NUM = 25,
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
    uGUIQueueAnnounce();
    virtual ~uGUIQueueAnnounce();
    void setType(u32 uType);
    void setState(u32 uState);
    void setName(MT_CTSTR str);
    void setInfo(MT_CTSTR str);
    void setNumber(s32 number);
    void setScheduleId(u32 ScheduleId);
    bool isFadeOut() const;
    virtual void kill();  // vtable slot 16
protected:
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void updateExit();
    void requestSE();
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    TYPE mType;  // offset: 0x8d0
    STATE mState;  // offset: 0x8d4
    MtStringEx<256> mName;  // offset: 0x8d8
    MtStringEx<256> mInfo;  // offset: 0x9dc
    s32 mNumber;  // offset: 0xae0
    u32 mScheduleId;  // offset: 0xae4
    f32 mFadeCount;  // offset: 0xae8
    f32 mFadeCountChk;  // offset: 0xaec
    bool mIsFadeOut;  // offset: 0xaf0
public:
    static MyDTI DTI;
};

inline void* uGUIQueueAnnounce::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
