#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtProperty.h"
#include "../shared/cUnit.h"
#include "../shared/rScheduler.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class rScheduler;
class sEventManager;
class uFade;

// Declarations
class uScheduler;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uScheduler : public cUnit
{
    // inferred: sEventManager::callStartSubSdl names uScheduler::mLoop
    friend class sEventManager;
    // inferred: uFade::uFade names uScheduler::mpScheduler
    friend class uFade;
public:
    class MyDTI;
    struct TRACK_WORK;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TRACK_WORK
    {
    public:
        rScheduler::TRACK* ptrack;  // offset: 0x0
        u32 type : 8;  // offset: 0x8
        u32 curkey : 24;  // offset: 0x8
        MtObject* pobj;  // offset: 0x10
        MtProperty prop;  // offset: 0x18
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
    uScheduler();
    virtual ~uScheduler();
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    void setData(rScheduler* pr);
    rScheduler* getData();
    void setPause(bool pause);
    bool isPause();
    void setLoop(bool loop);
    bool isLoop();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setFrame(u32 frame);
    u32 getFrame() const;
    f32 getFrameF() const;
    void setFrameF(f32 v);
    u32 getNextFrame() const;
    u32 getPrevFrame();
    void setSpeed(f32);
    f32 getSpeed() const;
    u32 getMarkerNum() const;
    f32 getMarkerFrame() const;
    void setMarkerFrame(f32 frame);
    u32 getMarker() const;
    void setMarker(u32 marker);
    bool isMarkerAdjust() const;
    void setMarkerAdjust(bool);
    bool isAutoDelete() const;
    void setAutoDelete(bool);
    void mapping();
    void updateSelect();
    u32 getFrameMax() const;
    s32 getUnitIndex(const MtDTI& dti, MT_CTSTR track_name) const;
    cUnit* getUnit(u32 index) const;
    void setUnit(cUnit* punit, u32 index);
    u32 getUnitNum() const;
    void updateTrack(bool apply);
    bool isPauseToFullStop() const;
    void setPauseToFullStop(bool v);
    bool isPauseToFullStopMoved() const;
protected:
    f32 adjustFrame(f32 frame);
    void applyTrack(TRACK_WORK* pwk, u32 iframe, f32 frame, f32 prev_frame);
    void setUnitNum(u32);
    void deleteTrackWork(bool force);
public:
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    u32 mTrackNum;  // offset: 0x48
    f32 mFrame;  // offset: 0x4c
    f32 mPrevFrame;  // offset: 0x50
    f32 mSpeed;  // offset: 0x54
    bool mPause;  // offset: 0x58
    bool mLoop;  // offset: 0x59
    bool mFloorFrame;  // offset: 0x5a
    bool mMarkerAdjust;  // offset: 0x5b
    bool mAutoDelete;  // offset: 0x5c
    bool mPauseToFullStop;  // offset: 0x5d
    bool mPauseToFullStopMoved;  // offset: 0x5e
    TRACK_WORK* mTrackWork;  // offset: 0x60
    TRACK_WORK* * mpUnitTrack;  // offset: 0x68
    u32 mUnitTrackNum;  // offset: 0x70
    rScheduler* mpScheduler;  // offset: 0x78
public:
    static MyDTI DTI;
};
