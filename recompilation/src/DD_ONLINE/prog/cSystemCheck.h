#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class cSystemCheck;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cSystemCheck : public MtObject
{
public:
    enum RESULT
    {
        RESULT_WAIT = 0,
        RESULT_SUCCESS = 1,
        RESULT_ERROR = 2,
    };
    enum
    {
        MSG_FINISH_TYPE_NORMAL = 0,
        MSG_FINISH_TYPE_SELECT = 1,
        MSG_FINISH_TYPE_AUTO = 2,
        MSG_FINISH_TYPE_LOOP = 3,
        MSG_FINISH_TYPE_MANUAL = 4,
    };
    enum
    {
        EXEC_RNO1_HDD_SPACE_CHECK = 0,
        EXEC_RNO1_HDD_SPACE_CHECK_ERROR = 1,
        EXEC_RNO1_HDD_SPACE_NO_FREE = 2,
        EXEC_RNO1_TROPHY_INSTALL = 3,
        EXEC_RNO1_CHECK_SAVEDATA = 4,
        EXEC_RNO1_CHECK_SAVEDATA_ERROR = 5,
        EXEC_RNO1_LOAD_SAVEDATA = 6,
        EXEC_RNO1_LOAD_SAVEDATA_BROKEN = 7,
        EXEC_RNO1_LOAD_SAVEDATA_ANYONE = 8,
        EXEC_RNO1_LOAD_SAVEDATA_ERROR = 9,
        EXEC_RNO1_LOAD_SAVEDATA_FAIL = 10,
        EXEC_RNO1_CREATE_SAVEDATA = 11,
        EXEC_RNO1_CREATE_SAVEDATA_FAIL = 12,
        EXEC_RNO1_EXIT = 13,
    };
    enum
    {
        FLAG_SAVEDATA_NOTHING = 0,
        FLAG_EXIST_SAVEDATA_ERROR = 1,
        FLAG_HDD_SPACE_ERROR = 2,
        FLAG_HDD_NO_SPRACE = 3,
    };
public:
    class MyDTI;
public:
    typedef struct
    {
    public:
        u32 mMsgNo;  // offset: 0x0
        u8 mSelectType;  // offset: 0x4
        u8 mDefPos;  // offset: 0x5
        u8 mCanPos;  // offset: 0x6
    } SYSTEM_MSG_DATA;
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
private:
    bool createSystemWindow(u32 msgNo);
    bool isSystemWindowEnd();
    void setRno(u8 rno0, u8 rno1, u8 rno2);
    bool checkFreeSpace();
    void setValueParam(uGUISystemMsg* pMsg, s32 Val);
public:
    cSystemCheck();
    virtual ~cSystemCheck();
    void loadResource();
    void releaseResource();
    void init();
    void move();
    RESULT getResult();
private:
    rGUIMessage* mpSystemRes;  // offset: 0x8
    rGUIMessage* mpCommonRes;  // offset: 0x10
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x18
    u32 mFlag;  // offset: 0x20
    s32 mVal;  // offset: 0x24
    u8 mRno0;  // offset: 0x28
    u8 mRno1;  // offset: 0x29
    u8 mRno2;  // offset: 0x2a
    u8 mRno3;  // offset: 0x2b
    u8 mSelectType;  // offset: 0x2c
    u8 mChoiceNo;  // offset: 0x2d
    RESULT mResult;  // offset: 0x30
public:
    static MyDTI DTI;
    static const SYSTEM_MSG_DATA mSystemMsgTbl[];
    static const f32 AUTO_KILL_TIME;
};

inline void* cSystemCheck::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cSystemCheck::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cSystemCheck::DTI)->memAlloc(sz, align, ::cSystemCheck::DTI.::MtDTI::getID());
}

inline void cSystemCheck::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSystemCheck::DTI)->memFree(p_addr);
}
