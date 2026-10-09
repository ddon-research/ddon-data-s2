#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cUnit.h"
#include "rSoundSequenceSe.h"
#include "sUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class rSoundRequest;
class rSoundSequenceSe;
class uCoord;
class uModel;

// Declarations
class uSoundSequenceSe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class uSoundSequenceSe : public cUnit
{
public:
    enum
    {
        STATE_NONE = 0,
        STATE_PLAY = 1,
        STATE_STOP = 2,
        STATE_PAUSE = 3,
        STATE_RESET = 4,
    };
    enum
    {
        MODE_NORMAL = 0,
        MODE_JOINT = 1,
        MODE_JOINT_ATTACH = 2,
        MODE_WORLD_POS = 3,
    };
public:
    class MyDTI;
    struct SoundSeqWork;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SoundSeqWork
    {
    public:
        void reset();
    public:
        bool IsEnd;  // offset: 0x0
        u16 CommandIndexNow;  // offset: 0x2
        f32 Timer;  // offset: 0x4
        f32 NowVolume;  // offset: 0x8
        s8 LoopIndex;  // offset: 0xc
        s8 LoopStartIndex[4];  // offset: 0xd
        s16 LoopCount[4];  // offset: 0x12
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
    uSoundSequenceSe();
    virtual ~uSoundSequenceSe();
    virtual void move();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void playSoundSequenceSe(rSoundSequenceSe* pReq);
    void stopSoundSequenceSe();
    void resetSequenceSeWork();
    void setSequenceSe(rSoundSequenceSe* pRes);
    void setSeqState(s8 state);
    void setCallPos(const MtVector3& pos);
    void setRequestMode(s8 mode);
    void setIsSetCallPos(bool flag);
    rSoundSequenceSe* getSequenceSe();
    void setTgtModel(uModel* pUnit);
    void setJointNo(u32 jntNo);
    void setIsAutoDelete(bool);
    virtual MOVE_LINE getSeqSeUnitMoveLine();  // vtable slot 24
private:
    void UpdatePtr(uModel* * ppUnit);
protected:
    virtual void requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId);  // vtable slot 25
    virtual void requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId, const MtVector3& pos);  // vtable slot 26
    virtual void requestSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jntNo);  // vtable slot 27
    virtual void keyOffSe(rSoundRequest* pSrq, u32 reqNo, u32 thisId);  // vtable slot 28
    virtual void setSeVolumeRatio(rSoundRequest* pSrq, u32 reqNo, u32 thisId, f32 volume);  // vtable slot 29
    virtual void setSePosition(rSoundRequest* pSrq, u32 reqNo, u32 thisId, const MtVector3& pos);  // vtable slot 30
    virtual bool isPause();  // vtable slot 31
    void playSequenceSe(rSoundSequenceSe* pRes);
    void requestSe(rSoundRequest* pSrq, rSoundSequenceSe::SequenceSe* pSeqSe);
    void controlVolume();
    void controlSePos();
    void createSequenceSeWork(rSoundSequenceSe* pRes);
protected:
    s8 mSeqState;  // offset: 0x48
    s8 mSeqStateOld;  // offset: 0x49
    s8 mRequestMode;  // offset: 0x4a
    s16 mJointNo;  // offset: 0x4c
    f32 mVolume;  // offset: 0x50
    bool mIsSetCallPos;  // offset: 0x54
    bool mIsAutoDelete;  // offset: 0x55
    rSoundSequenceSe* mpSequenceSe;  // offset: 0x58
    SoundSeqWork* mpSeqSeWork;  // offset: 0x60
    uModel* mpTgtModel;  // offset: 0x68
    MtVector3 mCallPos;  // offset: 0x70
public:
    static MyDTI DTI;
};
