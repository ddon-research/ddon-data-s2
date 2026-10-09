#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uScheduler;

// Declarations
class uFade;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uFade : public cUnit
{
public:
    enum
    {
        TYPE_IN = 0,
        TYPE_FADE_IN = 0,
        TYPE_WHITE_IN = 1,
        TYPE_OUT = 2,
        TYPE_FADE_OUT = 2,
        TYPE_WHITE_OUT = 3,
        TYPE_NUM = 4,
        TYPE_INVALID = -1,
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
    uFade(s32 type, f32 time);
    virtual ~uFade();
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
private:
    bool createScheduler(s32 type);
public:
    bool isEnd();
    s32 getFadeType();
    bool isFadeIn();
    bool isFadeOut();
private:
    bool mIsEnd;  // offset: 0x48
    bool mIsStop;  // offset: 0x49
    bool mIsSetScreenLayer;  // offset: 0x4a
    f32 mFrameAdd;  // offset: 0x4c
    f32 mFrameNow;  // offset: 0x50
    s32 mFadeType;  // offset: 0x54
    uScheduler* mpScheduler;  // offset: 0x58
public:
    static MyDTI DTI;
private:
    static const MT_CTSTR mFadeSchedulerTbl[4];
};

// Inline, no code of its own: checked where it is inlined.
inline bool uFade::isEnd() {
    return this->mIsEnd;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uFade::isFadeIn() {
    return this->mFadeType <= static_cast<s32>(1);
}

// Inline, no code of its own: checked where it is inlined.
inline bool uFade::isFadeOut() {
    return this->mFadeType > static_cast<s32>(1);
}
