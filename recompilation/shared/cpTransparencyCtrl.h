#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uDDOModel;

// Declarations
class cpTransparencyCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpTransparencyCtrl : public cpComponent
{
public:
    enum
    {
        RNO_CAM_FADE_NOTHING = 0,
        RNO_CAM_FADE_FADEOUT_WAIT = 1,
        RNO_CAM_FADE_FADEOUT = 2,
        RNO_CAM_FADE_FADEIN_WAIT = 3,
        RNO_CAM_FADE_FADEIN = 4,
        RNO_CAM_EM_FADE_START_WAIT = 5,
        RNO_CAM_EM_FADE_FADEOUT = 6,
        RNO_CAM_EM_FADE_FADEIN_WAIT = 7,
        RNO_CAM_EM_FADE_FADEIN = 8,
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
    cpTransparencyCtrl();
    virtual ~cpTransparencyCtrl();
    virtual void setup();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void before();
    void update();
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void startChangeTrp(f32 initTrp, f32 endTrp, f32 frame);
    void startChangeTrp(f32 endTrp, f32 frame);
    void stopChangeTrp();
    f32 getCameraRate();
    void setCameraFade(f32 start, f32 end);
    void setTrp(f32 trp);
    void setClimbEnemy();
    uDDOModel* getDDOModel() const;
    bool isActive() const;
private:
    bool checkFadeBellyVector();
    bool checkFadeInput();
    f32 getClimbFadeRadius() const;
    f32 getClimbFadeRate() const;
    f32 getClimbFadeInWait() const;
    f32 getClimbFadeOutWait() const;
    f32 getClimbFadeDist() const;
private:
    f32 mBaseTrp;  // offset: 0x50
    f32 mStartTrp;  // offset: 0x54
    f32 mEndTrp;  // offset: 0x58
    u32 mCamFadeRno;  // offset: 0x5c
    f32 mCamFadeTimer;  // offset: 0x60
    f32 mCamFadeStart;  // offset: 0x64
    f32 mCamFadeEnd;  // offset: 0x68
    f32 mWaitTimer;  // offset: 0x6c
    bool mIsClimbEnemy;  // offset: 0x70
    bool mIsActive;  // offset: 0x71
    f32 mSpeed;  // offset: 0x74
    uDDOModel* mpModel;  // offset: 0x78
public:
    static MyDTI DTI;
    static const u32 ENEMY_APPEAR_FRAME = 30;
    static const u32 UNIT_APPEAR_FRAME = 30;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpTransparencyCtrl::isActive() const {
    return this->mIsActive;
}
