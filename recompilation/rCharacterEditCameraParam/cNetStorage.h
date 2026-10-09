#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtNetObject.h"
#include "../shared/MtObject.h"
#include "../shared/sNetworkExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;

// Declarations
class cNetStorage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cNetStorage : public MtObject
{
public:
    enum STATE_ENUM
    {
        STATE_NONE = 0,
        STATE_DIALOG_WAIT = 1,
        STATE_LOAD_INIT = 2,
        STATE_LOAD_BUSY = 3,
        STATE_LOAD_END = 4,
        STATE_SAVE_INIT = 5,
        STATE_SAVE_BUSY = 6,
        STATE_SAVE_END = 7,
        STATE_REQ_ERROR = 8,
        STATE_OPEN_ERROR = 9,
        STATE_LOAD_ERROR = 10,
        STATE_SAVE_ERROR = 11,
    };
    enum STORAGE_TYPE
    {
        STORAGE_TYPE_WORLD = 0,
        STORAGE_TYPE_CHAR = 1,
        STORAGE_TYPE_TITLE = 2,
        STORAGE_TYPE_USER = 3,
    };
    enum
    {
        REQ_COMMAND_INIT = 0,
        REQ_COMMAND_SETUP = 1,
        REQ_COMMAND_MOVE = 2,
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
    cNetStorage();
    virtual ~cNetStorage();
    virtual void move();  // vtable slot 6
    bool loadStart();
    bool saveStart();
    void reset();
    bool isLoadComplete();
    bool isSaveComplete();
    bool isEnable();
    s32 getResultSize() const;
    void setReqCommand(s32 command, u32 param);
    void resetReqCommand();
    void endReqCommand();
    s32 getReqCommand();
    s32 getReqCommandState();
    void setReqCommandState(s32);
    u32 getReqCommandParam();
    bool loadNativeWorldStorage(bool errDialog);
    bool saveNativeWorldStorage(bool errDialog);
    bool loadNativeCharStorage(void* pBuf, s32 charId, bool errDialog);
    bool saveNativeCharStorage(void* pBuf, s32 charId, bool errDialog);
    bool isStorageAccessError(bool isDisp);
    sNetworkExt::NET_STAT getStatus(u32 comId);
private:
    void endState();
    bool open();
    bool load();
    bool save();
    void requestErrorDialog(s32 errNo);
    void setStorageType(u32 type);
    s32 getCharId();
    void setCharId(s32 charId);
    void setBuffer(void* pbuf, u32 size);
    u32 getComId();
    void setComId(u32 comId);
    void setErrorDialogFlag(bool flag);
    bool checkReqError();
private:
    u32 mState;  // offset: 0x8
    s32 mStorageType;  // offset: 0xc
    void* mpBuf;  // offset: 0x10
    u32 mSize;  // offset: 0x18
    MtNetError mErr;  // offset: 0x1c
    s32 mCharId;  // offset: 0x28
    u32 mComId;  // offset: 0x2c
    bool mErrorDialogFlag;  // offset: 0x30
    s32 mResultSize;  // offset: 0x34
    s32 mReqCommand[4];  // offset: 0x38
    s32 mReqCommandState[4];  // offset: 0x48
    u32 mReqCommandParam[4];  // offset: 0x58
public:
    static const u32 REQ_COMMAND_MAX = 4;
    static const s32 NO_REQ_COMMAND = -1;
    static const s32 DUMMY_REQ_COMMAND = 2147483647;
    static const u32 MAX_STORAGE_PATH = 64;
    static MyDTI DTI;
};
