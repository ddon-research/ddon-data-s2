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
class MtVector2;
class cEfcHandle;
class cMagicCommandWord;
class cpChargeCtrl;
class cpInput;
class rMagicCommandList;
class rMagicCommandWord;
class uDDOModel;

// Declarations
class cpChantCommand;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpChantCommand : public cpComponent
{
public:
    enum
    {
        PAWN_CHANT_SPEED_FAST = 0,
        PAWN_CHANT_SPEED_USUALLY = 1,
        PAWN_CHANT_SPEED_SLOW = 2,
    };
    enum
    {
        CHANT_STEP_NONE = -1,
        CHANT_STEP_MAX = 32,
    };
    enum
    {
        CHANT_COMMAND_EASY = 0,
        CHANT_COMMAND_NORMAL = 1,
        CHANT_COMMAND_HARD = 2,
    };
    enum
    {
        CHANT_POINT_NONE = -1,
        CHANT_POINT_MAX = 32,
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
    cpChantCommand();
    virtual ~cpChantCommand();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    u32 getChantSuccessCnt() const;
    void setChantSuccessCnt(u32 NewValue);
    u32 getOldChantSuccessCnt() const;
    void setOldChantSuccessCnt(u32 NewValue);
    bool checkPointJudge(f32 degree);
    void pawnMove();
    void setBeginCommandEffectPos(cEfcHandle* phand);
    void pawnChantDifficultySelect();
    void calcPawnChantInterval();
    void requestChantCommand(const u32 difficulty, u32 MagicNo);
    void endCheckCommand();
    bool checkBegin();
    bool isCrafty();
    bool isReqReset();
    void clearReqReset();
    bool isChantMode();
    void setChantMode(bool mode);
    bool isCheckCommand();
    MtVector2 getInputLS();
    void setChantData();
    f32 getBounusAtkRate();
    void cleanBounusAtkRate();
    virtual void updateEfcHandle();  // vtable slot 10
    void successCut(f32 bairitu);
    f32 getPoint(s32 wordIndex, s32 pos);
    s32 getPointNum();
    s32 getPointNumNext();
    s32 getNowPointNo();
    s32 getNowWord();
    s32 getNextWord();
    s32 getWordNum();
    s32 getNowWordNo();
    cMagicCommandWord* getWords(u32 No);
    u32 getNowDifficult();
    bool isPointSuccess();
    bool isWordSuccess();
    bool isCommandPose();
    void setCommandPose(bool flg);
    bool isEndCommand();
    void setEndCommand(bool);
    bool isBeginCommand();
    void setIsBeginCommand(bool flg);
    f32 getBounusAtkRateForGui();
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    cpInput* mpInput;  // offset: 0x58
    cpChargeCtrl* mpChargeCtrl;  // offset: 0x60
    f32 mSuccessWait;  // offset: 0x68
    f32 mStartWait;  // offset: 0x6c
    f32 mFailedWait;  // offset: 0x70
    f32 mChantAddSpeed;  // offset: 0x74
    u32 mChantDifficulty;  // offset: 0x78
    u32 mChantSuccessCnt_Gi;  // offset: 0x7c
    u32 mOldChantSuccessCnt_Gi;  // offset: 0x80
public:
    f32 mOldInputAngle;  // offset: 0x84
    f32 mVeryOldInputAngle;  // offset: 0x88
    f32 mCraftyCount;  // offset: 0x8c
    bool mIsCrafty;  // offset: 0x90
    bool mIsReqReset;  // offset: 0x91
    f32 mSpelingLockTiemr;  // offset: 0x94
    f32 mFailRecoverTimer;  // offset: 0x98
    f32 mFailTimer;  // offset: 0x9c
    s32 mMagicWordList[32];  // offset: 0xa0
    s32 mMagicWordsNum;  // offset: 0x120
    s32 mWordsLoopNum;  // offset: 0x124
    s32 mNowWord;  // offset: 0x128
    s32 mCommandPointNum;  // offset: 0x12c
    f32 mCommandPointList[32];  // offset: 0x130
    u32 mChantType;  // offset: 0x1b0
    u32 mCommandNum;  // offset: 0x1b4
    s32 mCommandNowPos;  // offset: 0x1b8
    cEfcHandle* mpChantFilterEfcHandle;  // offset: 0x1c0
    cEfcHandle* mpChantBeginEfcHandle;  // offset: 0x1c8
    u32 mPawnChantSpeed;  // offset: 0x1d0
    f32 mPawnChantInterval;  // offset: 0x1d4
    f32 mPawnChantCmdTime;  // offset: 0x1d8
    bool mIsChantMode;  // offset: 0x1dc
    bool mIsWordSuccess;  // offset: 0x1dd
    bool mIsPointSuccess;  // offset: 0x1de
    bool mIsCheckCommand;  // offset: 0x1df
    bool mIsBeginCommand;  // offset: 0x1e0
    bool mIsEnd;  // offset: 0x1e1
    bool mIsEndAfterCanMoveCamera;  // offset: 0x1e2
    bool mReqCommandPoseFlg;  // offset: 0x1e3
    rMagicCommandWord* mprMagicWords;  // offset: 0x1e8
    rMagicCommandList* mprMagicCommandList;  // offset: 0x1f0
    static MyDTI DTI;
};
