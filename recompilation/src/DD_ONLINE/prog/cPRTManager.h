#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cQuestFunctionManagerBAse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cQuestTask;

// Declarations
class cPRTManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cPRTManager : public cQuestFunctionManagerBase
{
    friend class cQuestTask;
public:
    enum
    {
        PRT_ST_IDLE = 0,
        PRT_ST_REQUEST = 1,
        PRT_ST_MOVE = 2,
        PRT_ST_STOP = 3,
    };
    enum
    {
        STATUS_NO_READY = 0,
        STATUS_READY_ALL = 1,
        STATUS_READY = 2,
        STATUS_READY_OK_ALL = 3,
    };
    enum
    {
        PRT_MAX = 30,
    };
    enum
    {
        OM_TYPE_NORMAL = 0,
        OM_TYPE_DOOR = 1,
    };
public:
    class MyDTI;
    struct PRTWork;
    struct PRTData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PRTData
    {
    public:
        u16 stageNo;  // offset: 0x0
        u16 questNo;  // offset: 0x2
        u8 blockNo;  // offset: 0x4
        u8 processNo;  // offset: 0x5
        MtVector3 pos;  // offset: 0x10
        f32 scale;  // offset: 0x20
    };
public:
    struct PRTWork
    {
    public:
        u8 status;  // offset: 0x0
        u8 mySet;  // offset: 0x1
        u32 uniqueId;  // offset: 0x4
        cPRTManager::PRTData data;  // offset: 0x10
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
    void reset();
    void init();
    void move();
    virtual void release();  // vtable slot 6
    bool requestPRT(const PRTData& data, bool isMySet);
    void releasePRT(const PRTData* pData, u8 status);
    u8 getSendPRTNum() const;
    u8 getSendPRT(u8 index) const;
    const PRTData* getPRTData(u8 index) const;
    bool isBootPRT() const;
    u32 getBootPRTUniqueId() const;
    void clearPRTInfo();
    void reqBootPRTUniqueId(u32 uniqueId);
    bool getReady() const;
    bool getReadyOK() const;
    bool getAdvanceFlag() const;
    void setAdvanceFlag();
    void resetAdvanceFlag();
    bool getReqAdvanceFlag() const;
    void reqAdvanceFlag();
    u32 getReadyStatus() const;
    bool getReqFinalAnswer() const;
    void reqFinalAnswer();
    bool getFinalAnswer() const;
    void setFinalAnswer();
    void resetFinalAnswer();
    void reqCancel();
    bool getCancel() const;
    void setReady();
    void resetReady();
    void setReadyBit(u32 index);
    void resetReadyBit(u32 index);
    bool checkReadyBit(u32 index);
    void setReadyOKBit(u32 index);
    void resetReadyOKBit(u32 index);
    bool checkReadyOKBit(u32 index);
    void resetReadyBitAll();
    void resetAdvancePRT();
    const PRTData* getAdvancePRTData() const;
    void entryParty(u32 index);
    void leaveParty(u32 index);
    u8 getAdvancePRTOMType();
    void releaseWithoutMySetPRT();
    void sendMySetPRTAll();
    void setReturnSession(bool isReturnSession, bool reqServer);
    bool isReturnSession();
protected:
    void updatePRT();
    bool setPRT(const PRTWork& work);
    u32 checkReady();
    void sendRequestPRTAll(s32 index);
    PRTWork* searchPRTWork(u16 stageNo, u16 questNo, u8 blockNo, u8 processNo);
    PRTWork* searchPRTWork(u32 uniqueId);
public:
    cPRTManager();
    virtual ~cPRTManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    u8 mPRTStatus;  // offset: 0x8
    u32 mReqBootPRTUniqueId;  // offset: 0xc
    u32 mBootPRTUniqueId;  // offset: 0x10
    u32 mReadyBit;  // offset: 0x14
    u32 mReadyOKBit;  // offset: 0x18
    u32 mReadyStatus;  // offset: 0x1c
    bool mIsReady;  // offset: 0x20
    bool mIsReadyOK;  // offset: 0x21
    PRTWork mPRTWork[30];  // offset: 0x30
    u8 mSendPRTNum;  // offset: 0x7b0
    u8 mSendPRT[30];  // offset: 0x7b1
    bool mReqCancel;  // offset: 0x7cf
    bool mReqFinalAnswer;  // offset: 0x7d0
    bool mFinalAnswer;  // offset: 0x7d1
    bool mReqAdvanceFlag;  // offset: 0x7d2
    bool mAdvanceFlag;  // offset: 0x7d3
    u8 mAdvancePRTOMType;  // offset: 0x7d4
    PRTData mAdvancePRT;  // offset: 0x7e0
    bool mIsReturnSession;  // offset: 0x810
public:
    static MyDTI DTI;
};

inline void* cPRTManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cPRTManager::getBootPRTUniqueId() const {
    return this->mBootPRTUniqueId;
}

inline void cPRTManager::reqBootPRTUniqueId(u32 uniqueId) {
    this->mReqBootPRTUniqueId = uniqueId;
}

inline bool cPRTManager::getReady() const {
    return this->mIsReady;
}

inline bool cPRTManager::getReadyOK() const {
    return this->mIsReadyOK;
}

inline bool cPRTManager::getAdvanceFlag() const {
    return this->mAdvanceFlag;
}

inline void cPRTManager::reqAdvanceFlag() {
    this->mReqAdvanceFlag = true;
}

inline u32 cPRTManager::getReadyStatus() const {
    return this->mReadyStatus;
}

inline void cPRTManager::reqFinalAnswer() {
    this->mReqFinalAnswer = true;
}

inline bool cPRTManager::getFinalAnswer() const {
    return this->mFinalAnswer;
}

inline void cPRTManager::reqCancel() {
    this->mReqCancel = true;
}

inline bool cPRTManager::getCancel() const {
    return this->mReqCancel;
}

inline void cPRTManager::setReady() {
    this->mIsReady = true;
}

inline void cPRTManager::resetReady() {
    this->mIsReady = false;
    this->mIsReadyOK = false;
}
