#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class uGUIEventSkip;
class uGUISystemMsg;
class uMovie;
class uScheduler;

// Declarations
class cOpeningMovie;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cOpeningMovie : public MtObject
{
public:
    enum
    {
        MOVE_R0_MOVIE_NONE = 0,
        MOVE_R0_MOVIE_INIT = 1,
        MOVE_R0_MOVIE_SYNC = 2,
        MOVE_R0_MOVIE_MOVE = 3,
        MOVE_R0_MOVIE_WAIT_FADE = 4,
        MOVE_R0_MOVIE_KILL = 5,
        MOVE_R0_MOVIE_END = 6,
    };
    enum
    {
        MOVE_R1_SKIP_CHECK = 0,
        MOVE_R1_SKIP_WAIT = 1,
    };
    enum TYPE_MOVIE
    {
        TYPE_FEMALE_VER = 0,
        TYPE_MALE_VER = 1,
        TYPE_NUM = 2,
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
    cOpeningMovie();
    virtual ~cOpeningMovie();
    void initMovie(u32 type);
    bool moveMovie();
    bool isPlayMovie();
    void setEndFadeType(u8 type = 0);
protected:
    bool syncMovie();
    bool checkSkipButton();
protected:
    u8 mRno0;  // offset: 0x8
    u8 mRno1;  // offset: 0x9
    u8 mEndFadeType;  // offset: 0xa
    uScheduler* mpScheduler;  // offset: 0x10
    uMovie* mpMovie;  // offset: 0x18
    u32 mMovieState;  // offset: 0x20
    uGUIEventSkip* mpGUIEventSkip;  // offset: 0x28
    uGUISystemMsg* mpGUIDialog;  // offset: 0x30
    f32 mMovieSyncTimer;  // offset: 0x38
    f32 mEventStreamReadyTimer;  // offset: 0x3c
public:
    static MyDTI DTI;
};

inline void* cOpeningMovie::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cOpeningMovie::setEndFadeType(u8 type) {
    this->mEndFadeType = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cOpeningMovie::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cOpeningMovie::DTI);
}

inline void cOpeningMovie::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cOpeningMovie::DTI)->memFree(p_addr);
}
