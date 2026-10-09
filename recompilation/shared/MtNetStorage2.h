#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetBuffer.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "MtTime.h"

// Forward declarations
class MtNetContext;
struct MtNetError;
class MtNetRequest;
class MtNetRequestController;
class MtNetUniqueId;
class MtTime;

// Declarations
class MtNetStorage2;
class MtNetStorageInfo;
class MtNetStorageList;

// Type aliases from DWARF
using MT_CHAR = char;
using SceNpTusSlotId = int;
using s32 = int;
using u32 = unsigned int;

class MtNetStorage2 : public MtNetObject, public MtNetRequestController::Listener
{
public:
    enum
    {
        PHASE_AUTO_FINALIZE_NONE = 0,
        PHASE_AUTO_FINALIZE_DROP = 1,
        PHASE_AUTO_FINALIZE_WAIT = 2,
        PHASE_AUTO_FINALIZE_END = 3,
    };
public:
    class Listener;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onNtcFinalize();  // vtable slot 3
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 4
        virtual void onAnsGetListSucceed(u32 req_seq, MtNetStorageList* storage_list);  // vtable slot 5
        virtual void onAnsGetListFail(u32 req_seq, MtNetError* net_err);  // vtable slot 6
        virtual void onAnsUnlinkSucceed(u32 req_seq);  // vtable slot 7
        virtual void onAnsUnlinkFail(u32 req_seq, MtNetError* net_err);  // vtable slot 8
        virtual void onAnsOpenSucceed(u32 req_seq);  // vtable slot 9
        virtual void onAnsOpenFail(u32 req_seq, MtNetError* net_err);  // vtable slot 10
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 11
        virtual void onAnsWriteSucceed(u32 req_seq);  // vtable slot 12
        virtual void onAnsWriteFail(u32 req_seq, MtNetError* net_err);  // vtable slot 13
        virtual void onAnsReadSucceed(u32 req_seq, s32 data_size);  // vtable slot 14
        virtual void onAnsReadFail(u32 req_seq, MtNetError* net_err);  // vtable slot 15
    };
public:
    MtNetStorage2(MtNetContext* context);
    virtual ~MtNetStorage2();
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    virtual void move() = 0;  // vtable slot 11
    virtual bool isEnable() = 0;  // vtable slot 12
    virtual const MtNetStorageList& getList() = 0;  // vtable slot 13
    void reqGetList(u32* req_seq, s32 max_num);
    void reqUnlink(u32* req_seq, const MtNetStorageInfo* info);
    void reqOpen(u32* req_seq, const MtNetStorageInfo* info);
    void reqFinalize(u32* req_seq);
    void reqWrite(u32* req_seq, void* data_ptr, s32 data_size);
    void reqRead(u32* req_seq, void* buf_ptr, s32 buf_size);
    void abortRequest(u32 req_seq);
protected:
    void beginDestruct();
    void beginMove();
    void endMove();
    void cbAnsGetListSucceed(MtNetRequest* req, MtNetStorageList* storage_list);
    void cbAnsGetListFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsUnlinkSucceed(MtNetRequest* req);
    void cbAnsUnlinkFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsOpenSucceed(MtNetRequest* req);
    void cbAnsOpenFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsFinalize(MtNetRequest* req);
    void cbAnsWriteSucceed(MtNetRequest* req);
    void cbAnsWriteFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsReadSucceed(MtNetRequest* req, s32 data_size);
    void cbAnsReadFail(MtNetRequest* req, MtNetError* net_err);
    virtual s32 moveGetList(MtNetRequest*) = 0;  // vtable slot 14
    virtual s32 moveUnlink(MtNetRequest*) = 0;  // vtable slot 15
    virtual s32 moveOpen(MtNetRequest*) = 0;  // vtable slot 16
    virtual s32 moveFinalize(MtNetRequest*) = 0;  // vtable slot 17
    virtual s32 moveWrite(MtNetRequest*) = 0;  // vtable slot 18
    virtual s32 moveRead(MtNetRequest*) = 0;  // vtable slot 19
private:
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 20
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 21
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 22
    virtual void endRequest(MtNetRequest* req);  // vtable slot 23
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 24
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
protected:
    MtNetContext* mpContext;  // offset: 0x30
    MtNetRequestController mRequestController;  // offset: 0x38
    bool mIsDestructor;  // offset: 0xb0
private:
    Listener* mpListener;  // offset: 0xb8
    s32 mPhaseAutoFinalize;  // offset: 0xc0
    bool mIsNeedFinalize;  // offset: 0xc4
protected:
    static const s32 REQUEST_ID_GET_LIST = 1281;
    static const s32 REQUEST_ID_UNLINK = 1282;
    static const s32 REQUEST_ID_OPEN = 1283;
    static const s32 REQUEST_ID_FINALIZE = 1284;
    static const s32 REQUEST_ID_WRITE = 1285;
    static const s32 REQUEST_ID_READ = 1286;
};

class MtNetStorageInfo
{
public:
    MtNetStorageInfo();
    virtual ~MtNetStorageInfo();
    void clear();
    MtNetStorageInfo& operator=(const MtNetStorageInfo& info);
public:
    MT_CHAR mFileName[256];  // offset: 0x8
    MtNetUniqueId mUniqueId;  // offset: 0x108
    MtTime mLastModified;  // offset: 0x180
    SceNpTusSlotId mSlotNo;  // offset: 0x188
    static const s32 MAX_SIZE_BUF_FILENAME = 256;
};

class MtNetStorageList
{
public:
    MtNetStorageList();
    virtual ~MtNetStorageList();
    void clear();
public:
    s32 mNum;  // offset: 0x8
    MtNetStorageInfo mInfo[64];  // offset: 0x10
    static const s32 MAX_NUM_INFO = 64;
};
