#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtString.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
class cHttpClient;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using SceHttpEpollHandle = void*;
using _Sizet = long unsigned int;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using uint32_t = __uint32_t;

class cHttpClient : public MtObject
{
public:
    enum
    {
        STATUS_DONE = 0,
        STATUS_WRITE = 1,
        STATUS_READ = 2,
        STATUS_WAIT = 3,
        STATUS_FINAL = 4,
    };
    enum
    {
        METHOD_GET = 0,
        METHOD_POST = 1,
        METHOD_PUT = 2,
        METHOD_DELETE = 3,
    };
    enum eRedirectPolicy
    {
        REDIRECT_POLICY_NEVER = 0,
        REDIRECT_POLICY_ALWAYS = 1,
        REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP = 2,
        REDIRECT_POLICY_NO_SCHEME_CHANGES = 3,
        REDIRECT_POLICY_MAX = 4,
    };
    enum
    {
        ERROR_GENERAL = -1,
    };
    enum
    {
        SECURITY_IGNORE_UNKNOWN_CA = 1,
        SECURITY_IGNORE_CERT_CN_INVALID = 2,
        SECURITY_IGNORE_CERT_DATE_INVALID = 4,
        SECURITY_IGNORE_CERT_WRONG_USAGE = 8,
        SECURITY_ALLOW_REJECTED_CERT = 16,
        SECURITY_IGNORE_VALIDATION_CACHE = 32,
    };
public:
    class MyDTI;
    class Listener;
    struct ResponseHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onReceiveHeader(const cHttpClient::ResponseHeader* pHeader);  // vtable slot 2
        virtual void onReceiveData(void* pData, s32 cData);  // vtable slot 3
        virtual void onErrorEncounterd(s32 error);  // vtable slot 4
    };
public:
    struct ResponseHeader
    {
    public:
        s32 mStatusCode;  // offset: 0x0
        s32 mContentLength;  // offset: 0x4
        MtString mLocation;  // offset: 0x8
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
    cHttpClient();
    virtual ~cHttpClient();
    s32 move();
    void setUserAgent(MT_CTSTR pUserAgentString);
    void setProxyServer(MT_CTSTR);
    s32 sendRequest(Listener* pListener, MT_CTSTR pUrn, MT_CTSTR pUrl, s32 method, MT_CTSTR pHeader, MT_CTSTR pData, s32 cData);
    void setAllowInsecure(bool flag);
    u32 getSecurityFlags();
    void setSecurityFlags(u32 flags);
    u32 getRedirectPolicy();
    void setRedirectPolicy(u32 policy);
    void setCertificate(void*, u32);
    void setCertificate(MT_CTSTR);
    void setSocketLib(s32);
    void setTimeout(MtNetTime::Total timeout);
    void cbErrorEncounterd(s32 error);
    bool isDone();
    s32 getState();
    void setState(s32 state);
    s32 getPhase();
    void setPhase(s32);
private:
    void final();
    void write();
    void read();
    void wait();
    void execute();
protected:
    void nativeConstructor();
    void nativeDestructor();
    s32 nativeSend(MT_CTSTR pUrn, MT_CTSTR pUrl, s32 method, MT_CTSTR pHeader, MT_CTSTR pData, s32 cData);
    void nativeFinal();
    void nativeWrite();
    void nativeRead();
    void nativeWait();
    void nativeExecute();
private:
    void clearWork();
    MT_CTSTR parseHeader(MtString& field_str, MtString& data_str, MT_CTSTR str_ptr);
private:
    MT_CHAR mRecvBuff[32768];  // offset: 0x8
    u32 mScheme;  // offset: 0x8008
    Listener* mpListener;  // offset: 0x8010
    s32 mRequestMethod;  // offset: 0x8018
    MT_STR mpRequestUrl;  // offset: 0x8020
    MT_CTSTR mpRequestData;  // offset: 0x8028
    u32 mRequestDataSize;  // offset: 0x8030
    u32 mRequestDataSent;  // offset: 0x8034
    MT_STR mpProxyServerName;  // offset: 0x8038
    MT_CTSTR mpUserAgentString;  // offset: 0x8040
    MT_CTSTR mpHeader;  // offset: 0x8048
    s32 mResponseHeaderSize;  // offset: 0x8050
    s32 mState;  // offset: 0x8054
    s32 mPhase;  // offset: 0x8058
    bool mIsReceivedHeader;  // offset: 0x805c
    u32 mSecurityFlags;  // offset: 0x8060
    u32 mRedirectPolicy;  // offset: 0x8064
    s32 mSocketLib;  // offset: 0x8068
    void* mpCertificateData;  // offset: 0x8070
    u32 mCertificateDataSize;  // offset: 0x8078
    MtString mCertificateName;  // offset: 0x8080
    MtNetTime::Total mTimeout;  // offset: 0x8088
    MtString mUrlStr;  // offset: 0x8090
    int mTemplateId;  // offset: 0x8098
    int mConnectionId;  // offset: 0x809c
    int mRequestId;  // offset: 0x80a0
    SceHttpEpollHandle mEpollHandle;  // offset: 0x80a8
    MT_CTSTR mpData;  // offset: 0x80b0
    u32 mcData;  // offset: 0x80b8
    s32 mLastRequestRet;  // offset: 0x80bc
    MtNetTime::Total mReadStartTime;  // offset: 0x80c0
public:
    static MyDTI DTI;
    static const s32 MAX_SIZE_RECV_BUFF = 32768;
    static const s32 MAX_HOSTNAME_LENGTH = 128;
private:
    static MT_CTSTR mpDefaultUserAgent;
    static const uint32_t TIMEOUT_CONNECT = 30000000;
    static const uint32_t TIMEOUT_SEND = 30000000;
    static const uint32_t TIMEOUT_RECV = 30000000;
    static const MtNetTime::Total TIMEOUT_READ = 20000;
};
