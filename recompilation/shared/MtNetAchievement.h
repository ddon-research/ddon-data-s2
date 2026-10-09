#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "MtThread.h"
#include "np_trophy.h"

// Forward declarations
struct MtNetError;
class MtNetRequest;
class MtNetRequestController;
class MtPropertyList;
class MtThread;
struct SceNpTrophyFlagArray;
namespace nNetwork { namespace nAchievement { class Object; } }

// Declarations
class MtNetAchievement;

// Type aliases from DWARF
using __int32_t = int;
using int32_t = __int32_t;
using SceNpTrophyContext = int32_t;
using SceUserServiceUserId = int32_t;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uint32_t = __uint32_t;

class MtNetAchievement : public MtNetObject, public MtNetRequestController::Listener
{
    // inferred: nNetwork::nAchievement::Object::start names MtNetAchievement::mpInstance
    friend class nNetwork::nAchievement::Object;
public:
    enum TrophyState
    {
        TrophyState_None = 0,
        TrophyState_CreateContext = 1,
        TrophyState_RegisterContextReq = 2,
        TrophyState_RegisterContextWait = 3,
        TrophyState_Available = 4,
        TrophyState_DestroyContext = 5,
        TrophyState_NotAvailable = 6,
    };
public:
    class Listener;
    struct TrophyUserInfo;
    struct IdList;
    class cTrophyRegisterContextThread;
    class cTrophyWriteThread;
    class cTrophyReadThread;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onAnsInitSucceed(u32 req_seq, u64 option);  // vtable slot 3
        virtual void onAnsInitFail(u32 req_seq, MtNetError* net_err);  // vtable slot 4
        virtual void onAnsStartSucceed(u32 req_seq);  // vtable slot 5
        virtual void onAnsStartFail(u32 req_seq, MtNetError* net_err);  // vtable slot 6
        virtual void onAnsGetInfoSucceed(u32 req_seq, s32 user_index, s32 id, bool is_award);  // vtable slot 7
        virtual void onAnsGetInfoFail(u32 req_seq, MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 8
        virtual void onAnsAwardSucceed(u32 req_seq, s32 user_index, s32 id);  // vtable slot 9
        virtual void onAnsAwardFail(u32 req_seq, MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 10
        virtual void onNtcGetInfoListSucceed(s32 user_index, s32 id, bool is_award);  // vtable slot 11
        virtual void onNtcGetInfoListFail(MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 12
        virtual void onAnsGetInfoList(u32 req_seq, s32 user_index);  // vtable slot 13
        virtual void onNtcAwardListSucceed(s32 user_index, s32 id);  // vtable slot 14
        virtual void onNtcAwardListFail(MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 15
        virtual void onAnsAwardList(u32 req_seq, s32 user_index);  // vtable slot 16
    };
public:
    struct TrophyUserInfo
    {
    public:
        bool isValid;  // offset: 0x0
        bool isRemove;  // offset: 0x1
        bool isRequest;  // offset: 0x2
        SceUserServiceUserId sceUserId;  // offset: 0x4
        MtNetAchievement::TrophyState state;  // offset: 0x8
        SceNpTrophyContext npContext;  // offset: 0xc
        uint32_t unlockNum;  // offset: 0x10
        SceNpTrophyFlagArray unlockCache;  // offset: 0x14
        s32 trophyRequestNum;  // offset: 0x24
        u8 trophyRequestTbl[128];  // offset: 0x28
        s32 trophyResultTbl[128];  // offset: 0xa8
        MtThread* threadPtr;  // offset: 0x2a8
        s32 threadResult;  // offset: 0x2b0
    };
public:
    struct IdList
    {
    public:
        s32 mNum;  // offset: 0x0
        s32 mId[128];  // offset: 0x4
    };
public:
    class cTrophyRegisterContextThread : public MtThread
    {
    public:
        cTrophyRegisterContextThread(void* pcontext);
        virtual ~cTrophyRegisterContextThread();
    protected:
        virtual void execute(void* pcontext);  // vtable slot 6
    };
public:
    class cTrophyWriteThread : public MtThread
    {
    public:
        cTrophyWriteThread(void* pcontext);
        virtual ~cTrophyWriteThread();
    protected:
        virtual void execute(void* pcontext);  // vtable slot 6
    };
public:
    class cTrophyReadThread : public MtThread
    {
    public:
        cTrophyReadThread(void* pcontext);
        virtual ~cTrophyReadThread();
    protected:
        virtual void execute(void* pcontext);  // vtable slot 6
    };
public:
    static MtNetAchievement* getInstance();
    MtNetAchievement();
    virtual ~MtNetAchievement();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    void move();
    void reqInit(u32* req_seq);
    void reqStart(u32* req_seq);
    void reqGetInfo(u32* req_seq, s32 user_index, s32 id);
    void reqAward(u32* req_seq, s32 user_index, s32 id);
    void reqGetInfoList(u32* req_seq, s32 user_index, IdList* list);
    void reqAwardList(u32* req_seq, s32 user_index, IdList* list);
private:
    void cbAnsInitSucceed(MtNetRequest* req, u64 option);
    void cbAnsInitFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsStartSucceed(MtNetRequest* req);
    void cbAnsStartFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsGetInfoSucceed(MtNetRequest* req, s32 user_index, s32 id, bool is_award);
    void cbAnsGetInfoFail(MtNetRequest* req, MtNetError* net_err, s32 user_index, s32 id);
    void cbAnsAwardSucceed(MtNetRequest* req, s32 user_index, s32 id);
    void cbAnsAwardFail(MtNetRequest* req, MtNetError* net_err, s32 user_index, s32 id);
    void cbNtcGetInfoListSucceed(s32 user_index, s32 id, bool is_award);
    void cbNtcGetInfoListFail(MtNetError* net_err, s32 user_index, s32 id);
    void cbAnsGetInfoList(MtNetRequest* req, s32 user_index);
    void cbNtcAwardListSucceed(s32 user_index, s32 id);
    void cbNtcAwardListFail(MtNetError* net_err, s32 user_index, s32 id);
    void cbAnsAwardList(MtNetRequest* req, s32 user_index);
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 11
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 12
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 13
    virtual void endRequest(MtNetRequest* req);  // vtable slot 14
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 15
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
    s32 moveInit(MtNetRequest* req);
    s32 moveStart(MtNetRequest* req);
    s32 moveGetInfo(MtNetRequest* req);
    s32 moveAward(MtNetRequest* req);
    s32 moveGetInfoList(MtNetRequest* req);
    s32 moveAwardList(MtNetRequest* req);
    void nativeConstructor();
    void nativeDestructor();
    void nativeCreateProperty(MtPropertyList& s);
    void nativeMove();
    void clearUser(TrophyUserInfo& info);
    void addUser(SceUserServiceUserId user_id);
    void removeUser(SceUserServiceUserId user_id);
    TrophyUserInfo* getUser(SceUserServiceUserId user_id);
    void updateUser(TrophyUserInfo& info);
private:
    MtNetRequestController mRequestController;  // offset: 0x30
    Listener* mpListener;  // offset: 0xa8
    TrophyUserInfo mUserInfoTbl[4];  // offset: 0xb0
public:
    static const s32 MAX_NUM_ID = 128;
private:
    static const s32 REQUEST_ID_INIT = 1025;
    static const s32 REQUEST_ID_START = 1026;
    static const s32 REQUEST_ID_GET_INFO = 1027;
    static const s32 REQUEST_ID_AWARD = 1028;
    static const s32 REQUEST_ID_GET_INFO_LIST = 1029;
    static const s32 REQUEST_ID_AWARD_LIST = 1030;
    static MtNetAchievement* mpInstance;
    static const s32 MAX_NUM_TROPHY = 128;
    static const s32 MAX_NUM_USER_INFO = 4;
};
