#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtNetObject.h"
#include "../../../../MT/MtString.h"
#include "../../../../MT/MtSynchronize.h"
#include "../../../../MT/MtThread.h"
#include "../../../../XFramework/cHttpClient.h"
#include "../modules/httpPatch/httpPatch.h"

// Forward declarations
class MtCriticalSection;
struct MtNetError;
class MtObject;
class MtSemaphore;
class MtString;
class MtThread;
namespace via { namespace module { namespace network { namespace utility { class HttpDownloadManager; } } } }

// Declarations
class HttpClient;
class MtNetSubObject;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using SceHttpEpollHandle = void*;
using SceSslCert = void;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtNetSubObject
{
    friend class via::module::network::utility::HttpDownloadManager;
public:
    class ScopedLock;
public:
    class ScopedLock
    {
    public:
        ScopedLock(MtNetSubObject* objPtr);
        ~ScopedLock();
    private:
        MtNetSubObject* mObjPtr;  // offset: 0x0
    };
public:
    MtNetSubObject();
    ~MtNetSubObject();
    bool isFatal() const;
    void getFatal(MtNetError*);
protected:
    void lock();
    void unlock();
    s32 getLockCount();
    void clearFatal();
    void setFatal(const MtNetError*);
    void setFatal(s32, s32, s32);
private:
    MtCriticalSection mCS;  // offset: 0x0
    bool mIsThreadSafe;  // offset: 0x8
    s32 mLockCount;  // offset: 0xc
    MtNetError mFatal;  // offset: 0x10
};

class HttpClient : public cHttpClient, private MtNetSubObject
{
public:
    enum RedirectPolicy
    {
        RedirectPolicy_Never = 0,
        RedirectPolicy_Always = 1,
        RedirectPolicy_DisallowHttpsToHttp = 2,
        RedirectPolicy_NoSchemeChanges = 3,
        RedirectPolicy_Max = 4,
    };
    enum Method
    {
        Method_Get = 0,
        Method_Post = 1,
        Method_Put = 2,
        Method_Delete = 3,
    };
    enum Error
    {
        Error_Pending = -1,
        Error_None = 0,
    };
    enum Security
    {
        Security_IgnoreUnknownCA = 1,
        Security_IgnoreCertCnInvalid = 2,
        Security_IgnoreCertDateInvalid = 4,
        Security_IgnoreCertWrongUsage = 8,
        Security_AllowRejectedCert = 16,
        Security_IgnoreValidationCache = 32,
    };
public:
    class Listener;
    struct ResponseHeader;
    struct RecvBuf;
    struct RequestArg;
    class MtThread_HttpReqTaskProcessThread;
public:
    using RequestCallback = void(MtObject::*)(void*);
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onReceiveHeader(const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf);  // vtable slot 2
        virtual void onReceiveData(const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);  // vtable slot 3
        virtual void onErrorEncounterd(s32 error);  // vtable slot 4
        virtual void onSucceed();  // vtable slot 5
        virtual void onFail(HPDErrCategory ecType, s32 error);  // vtable slot 6
        virtual void onWait();  // vtable slot 7
        virtual void setProgressDL1File(f32 per);  // vtable slot 8
        virtual void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);  // vtable slot 9
        virtual void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 10
        virtual void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 11
        virtual bool isAbortFlagInCB();  // vtable slot 12
        virtual u32 getCbContentLength();  // vtable slot 13
    };
public:
    struct ResponseHeader
    {
    public:
        s32 mStatusCode;  // offset: 0x0
        s32 mContentLength;  // offset: 0x4
        MtString mHeaderStr;  // offset: 0x8
        MtString mLocation;  // offset: 0x10
    };
public:
    struct RecvBuf
    {
    public:
        void* ptr;  // offset: 0x0
        size_t size;  // offset: 0x8
    };
public:
    struct RequestArg
    {
    public:
        bool isKeepalive;  // offset: 0x0
        MT_CTSTR uriAuthStrPtr;  // offset: 0x8
        MT_CTSTR uriPathStrPtr;  // offset: 0x10
        HttpClient::Method method;  // offset: 0x18
        MT_CTSTR headerStrPtr;  // offset: 0x20
        const void* dataPtr;  // offset: 0x28
        size_t dataSize;  // offset: 0x30
    };
public:
    class MtThread_HttpReqTaskProcessThread : public MtThread
    {
    public:
        MtThread_HttpReqTaskProcessThread(HttpClient* ptr, u32 stack_size, void* context, MT_CTSTR name);
        virtual ~MtThread_HttpReqTaskProcessThread() {}
        virtual void execute(void* pcontext);  // vtable slot 6
    public:
        HttpClient* mpHttpClient;  // offset: 0x70
    };
public:
    static HttpClient* createInstance();
    static void deleteInstance(HttpClient* ptr);
    explicit HttpClient(u32 semaphore_init_count, u32 semaphore_max_count, MT_CTSTR semaphore_name);
    virtual ~HttpClient();
    Error request(Listener& listener, bool is_keepalive, MT_CTSTR uri_authority_str_ptr, MT_CTSTR uri_path_str_ptr, Method method, MT_CTSTR header_str_ptr, const void* data_ptr, s32 data_size);
    void abort();
    bool isInProgress() const;
    bool isWaiting() const;
    void endRequest();
    void setReceiveDataMaxSize(size_t data_size);
    void setUserAgent(MT_CTSTR str_ptr);
    void setProxyServer(MT_STR str_ptr);
    void setAllowInsecure(bool flag);
    u32 getSecurityFlags();
    void setSecurityFlags(u32 flags);
    RedirectPolicy getRedirectPolicy();
    void setRedirectPolicy(RedirectPolicy policy);
    void setCertificate(void* cert_data_ptr, u32 cert_data_size);
    void setCertificate(MT_CTSTR cert_name_ptr);
    void setSocketLib(s32);
    bool isDone();
    s32 getState();
    void setState(s32 state);
    s32 getPhase();
    void setPhase(s32);
    void final();
protected:
    bool initializeImpl(const RequestArg& arg);
    void finalizeImpl();
    void requestImpl(const RequestArg& arg);
    void abortImpl();
    void destructBefore();
    void cbReceiveHeader(const ResponseHeader& header, RecvBuf& next_buf);
    void cbReceiveData(const void* data_ptr, size_t data_size, RecvBuf& next_buf);
    void cbSucceed();
    void cbFail(HPDErrCategory ecType, s32 error);
    bool isAbortFlagInCB();
    void cbSetProgressDL1File(f32 per);
    void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);
    void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
    void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
private:
    void cbWait();
    void process(void* param_ptr);
    bool setupTaskThread(MtObject* object, RequestCallback callback, MT_CTSTR thread_name, void* argument_ptr);
    bool setupThread(MT_CTSTR thread_name, void* argument_ptr);
    void nativeConstructor();
    void nativeDestructor();
    void nativeFinal();
    void nativeWait();
    void nativeExecute();
    bool nativeInitialize(const RequestArg& arg);
    void nativeFinalize();
    void nativeRequest(const RequestArg& arg);
    void nativeRequestSleeping(HTTPDL_RETRY_STATUS* state, u32 wait);
    void nativeAbort();
    void clearWork();
    MT_CTSTR parseHeader(MtString& field_str, MtString& data_str, MT_CTSTR str_ptr);
    bool addUserHeaderParam(char* strHeader);
    static int cbSSL(int libsslCtxId, unsigned int verifyErr, SceSslCert* const * sslCert, int certNum, void* userArg);
public:
    MT_CHAR mRecvBuff[32768];  // offset: 0x80e4
    u32 mScheme;  // offset: 0x100e4
    Listener* mpListener;  // offset: 0x100e8
    s32 mRequestMethod;  // offset: 0x100f0
    MT_STR mpRequestUrl;  // offset: 0x100f8
    MT_CTSTR mpRequestData;  // offset: 0x10100
    u32 mRequestDataSize;  // offset: 0x10108
    u32 mRequestDataSent;  // offset: 0x1010c
    MT_CTSTR mpHeader;  // offset: 0x10110
    s32 mResponseHeaderSize;  // offset: 0x10118
    s32 mState;  // offset: 0x1011c
    s32 mPhase;  // offset: 0x10120
    bool mIsReceivedHeader;  // offset: 0x10124
    s32 mSocketLib;  // offset: 0x10128
protected:
    size_t mReceiveDataMaxSize;  // offset: 0x10130
    MT_STR mpProxyServerName;  // offset: 0x10138
    MT_CTSTR mpUserAgentString;  // offset: 0x10140
    u32 mSecurityFlags;  // offset: 0x10148
    RedirectPolicy mRedirectPolicy;  // offset: 0x1014c
    void* mpCertificateData;  // offset: 0x10150
    u32 mCertificateDataSize;  // offset: 0x10158
    MtString mCertificateName;  // offset: 0x10160
private:
    RequestCallback mCallback;  // offset: 0x10168
    MtObject* mObject;  // offset: 0x10178
    bool mExit;  // offset: 0x10180
    bool mResume;  // offset: 0x10181
    bool mIsProcess;  // offset: 0x10182
    MtThread* mThread;  // offset: 0x10188
    MtSemaphore mSemaphore;  // offset: 0x10190
    Listener* mListenerPtr;  // offset: 0x10198
    bool mIsInProgress;  // offset: 0x101a0
    bool mIsInitialized;  // offset: 0x101a1
    bool mIsWaiting;  // offset: 0x101a2
    bool mIsGoRequest;  // offset: 0x101a3
    bool mIsGoFinalize;  // offset: 0x101a4
    RequestArg mRequestArg;  // offset: 0x101a8
    MtCriticalSection mCS;  // offset: 0x101e0
    MtString mUrlStr;  // offset: 0x101e8
    char* mRecvBuf;  // offset: 0x101f0
    u64 mRecvBufSize;  // offset: 0x101f8
    int mTemplateId;  // offset: 0x10200
    int mConnectionId;  // offset: 0x10204
    int mRequestId;  // offset: 0x10208
    SceHttpEpollHandle mEpollHandle;  // offset: 0x10210
    MT_CTSTR mpData;  // offset: 0x10218
    u32 mcData;  // offset: 0x10220
    s32 mLastRequestRet;  // offset: 0x10224
    bool swHttpClientDisuse;  // offset: 0x10228
    int mHttpNetMemId;  // offset: 0x1022c
public:
    static MT_CTSTR mpDefaultUserAgent;
};

inline HttpClient::Listener::Listener() {
}
