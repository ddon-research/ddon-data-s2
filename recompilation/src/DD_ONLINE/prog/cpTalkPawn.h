#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cTalkMsgData.h"
#include "cpTalk.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cArcLoaderBase;
class cTalkMsgData;
class rSoundStreamRequest;
class uDDOModel;

// Declarations
class cpTalkPawn;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpTalkPawn : public cpTalk
{
public:
    enum
    {
        MSG_TYPE_COMMON = 0,
        MSG_TYPE_STAGE = 1,
        MSG_TYPE_AREA = 2,
        MSG_TYPE_NUM = 3,
    };
    enum
    {
        CHG_RNO_INIT = 0,
        CHG_RNO_LOAD_STAGE = 1,
        CHG_RNO_WAIT_STAGE = 2,
        CHG_RNO_FINISH = 3,
        CHG_RNO_CHECK_AREA = 4,
        CHG_RNO_LOAD_AREA = 5,
        CHG_RNO_WAIT_AREA = 6,
        CHG_RNO_END = 7,
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
    virtual void loadMsgData();  // vtable slot 16
    void chageMsgData();
    bool loadMsgArc(TICKET& ticket, MT_CTSTR name);
    bool loadMsgArcStage(TICKET& ticket, u32 StageNo);
    bool loadMsgData(cTalkMsgData& msgData, MT_CTSTR path, bool isLoadMsg);
    void resetMsgData(u32 type = 2);
    cTalkMsgData& setupMsgData();
    void setPersonality(s32 per);
    u32 getPersonality();
    void setSex(s32 sex);
    u32 getSex();
    cTalkMsgData& getTalkMsgData(u32 type);
    virtual cTalkMsgData& getTalkMsgData();  // vtable slot 15
    bool isExistTalkMsgData(u32);
    void loadSoundData();
    void requestPawnTalkVoice();
    cpTalkPawn();
    virtual ~cpTalkPawn();
    virtual void move();  // vtable slot 7
    virtual void setTouch(uDDOModel* pUnit);  // vtable slot 18
protected:
    u32 mMsgType;  // offset: 0x104
    u32 mMsgFeature;  // offset: 0x108
    s32 mPersonality;  // offset: 0x10c
    u32 mSex;  // offset: 0x110
    u32 mAreaNo;  // offset: 0x114
    f32 mChkTimer;  // offset: 0x118
    u32 mStageFeatureNum;  // offset: 0x11c
    cTalkMsgData mTalkMsgDataStage[8];  // offset: 0x120
    cTalkMsgData mTalkMsgDataArea;  // offset: 0x3a0
    u32 mRnoChange;  // offset: 0x3f0
    u32 mSetupMsgFlag;  // offset: 0x3f4
    TICKET mArcTicketStage;  // offset: 0x3f8
    TICKET mArcTicketArea;  // offset: 0x400
    rSoundStreamRequest* mprPawnTalkSoundStreamResource;  // offset: 0x408
    s32 mVoicePitch;  // offset: 0x410
public:
    static MyDTI DTI;
};

inline void* cpTalkPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpTalkPawn::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpTalkPawn::DTI);
}

inline void cpTalkPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpTalkPawn::DTI)->memFree(p_addr);
}

inline void cpTalkPawn::resetMsgData(u32 type) {
    this->mTalkMsgDataArea.::cTalkMsgData::reset();
    this->mSetupMsgFlag = this->mSetupMsgFlag & 0xFFFFFFFBu;
}
