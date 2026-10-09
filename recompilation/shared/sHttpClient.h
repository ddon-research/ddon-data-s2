#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtJsonReader.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtStream.h"
#include "MtString.h"
#include "cHttpClient.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMemoryStream;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
class cGameHttpClient;
class sHttpClient;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cGameHttpClient : public cHttpClient
{
public:
    enum
    {
        FLOW_INIT = 0,
        FLOW_REQ = 1,
        FLOW_WAIT = 2,
        FLOW_ANALYZE = 3,
        FLOW_ERROR = 4,
        FLOW_ABORT_REQ = 5,
        FLOW_ABORT = 6,
        FLOW_EXIT = 7,
        FLOW_SUSPEND = 8,
    };
public:
    class MyDTI;
    class cLoginBackDoorInfo;
    class MyListener;
    class cServerEnvironmentInfo;
    class hDDO;
    class hServerEnvironmentList;
    class hLoginBackDoor;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLoginBackDoorInfo : public MtObject
    {
    public:
        class MyDTI;
        struct stLoginServer;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stLoginServer
        {
        public:
            stLoginServer();
        public:
            MtString mHost;  // offset: 0x0
            u32 mPort;  // offset: 0x8
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
        cLoginBackDoorInfo();
        virtual ~cLoginBackDoorInfo();
    public:
        u32 mState;  // offset: 0x8
        u32 mMode;  // offset: 0xc
        MtString mOneTime;  // offset: 0x10
        stLoginServer mLoginServer;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    class MyListener : public cHttpClient::Listener
    {
    public:
        MyListener();
        // Address: 0x01ac5020 - 0x01ac5021 (1 bytes)
        virtual ~MyListener() {}
        virtual void onReceiveHeader(const cHttpClient::ResponseHeader* pHeader);  // vtable slot 2
        virtual void onReceiveData(void* pData, s32 cData);  // vtable slot 3
        virtual void onErrorEncounterd(s32 error);  // vtable slot 4
        cGameHttpClient* getOwner();
        void setOwner(cGameHttpClient* pOwner);
    private:
        cGameHttpClient* mpOwner;  // offset: 0x8
    };
public:
    class cServerEnvironmentInfo : public MtObject
    {
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
        cServerEnvironmentInfo();
        virtual ~cServerEnvironmentInfo();
    public:
        MtString mInfo;  // offset: 0x8
        MtString mUraguchiURN;  // offset: 0x10
        MtString mUraguchiURL;  // offset: 0x18
        u32 mRomVersion;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class hDDO : public MtJsonReader::Handler
    {
    public:
        hDDO();
        virtual void beginArray();  // vtable slot 2
        virtual void endArray();  // vtable slot 3
        virtual void beginObject();  // vtable slot 4
        virtual void endObject();  // vtable slot 5
        bool isArray();
    protected:
        MtString mFieldName;  // offset: 0x10
        MtString mObjectName;  // offset: 0x18
        MtString mArrayName;  // offset: 0x20
    };
public:
    class hServerEnvironmentList : public cGameHttpClient::hDDO
    {
    public:
        hServerEnvironmentList();
        virtual void beginObject();  // vtable slot 4
        virtual void fieldName(MT_CTSTR chars, const u32);  // vtable slot 6
        virtual void string(MT_CTSTR chars, const u32);  // vtable slot 7
        virtual void number(u64 num);  // vtable slot 8
        virtual void number(s64);  // vtable slot 9
        virtual void number(f64);  // vtable slot 10
    private:
        u32 mIndex;  // offset: 0x28
    };
public:
    class hLoginBackDoor : public cGameHttpClient::hDDO
    {
    public:
        hLoginBackDoor();
        hLoginBackDoor(u32 handle);
        virtual void beginObject();  // vtable slot 4
        virtual void fieldName(MT_CTSTR chars, const u32);  // vtable slot 6
        virtual void string(MT_CTSTR chars, const u32);  // vtable slot 7
        virtual void number(u64 num);  // vtable slot 8
        virtual void number(s64);  // vtable slot 9
        virtual void number(f64);  // vtable slot 10
    private:
        u32 mHandle;  // offset: 0x28
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
    cGameHttpClient();
    cGameHttpClient(u32 handle);
    virtual ~cGameHttpClient();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void reset();
    void init();
    void move();
    void final();
    void abort();
    void sendReq();
    s32 getLineNum();
    bool getDrawNext(MT_STR buf_ptr, s32 buf_size);
    void resetDraw();
    void separateURI(MT_CTSTR uri, MtString& urn, MtString& url);
    u32 getHandle();
    u32& getStatusCodeRef();
    void setStatusCode(u32 value);
    s32& getContentLengthRef();
    void setContentLength(s32 value);
    MtMemoryStream& getStreamRef();
    void setErrorCode(s32 error);
    void openingServerFlow();
    bool isExecOpeningServerFlow();
    void setServerEnvironmentList(u32 count);
    bool reqServerEnvironmentList(u32 count);
    s32 analyzeServerEnvironmentList();
    void setLoginBackDoor(MT_CTSTR pAccount, MT_CTSTR pHost);
    bool reqLoginBackDoor(MT_CTSTR pAccount, MT_CTSTR pHost);
    s32 analyzeLoginBackDoor();
    void setDownloadPic(MT_CTSTR addr, void* * ptr, u32* size);
    bool reqDownloadPic(MT_CTSTR addr, void* * ptr, u32* size);
    s32 analyzeDownloadPic();
    cLoginBackDoorInfo& getLoginBackDoorInfoRef();
public:
    cLoginBackDoorInfo mLoginBackDoorInfo;  // offset: 0x80c8
private:
    MyListener mListener;  // offset: 0x80f0
    MT_CHAR* mpAddHeader;  // offset: 0x8100
    u32 mUserIndex;  // offset: 0x8108
    bool mIsUseToken;  // offset: 0x810c
    bool mIsSaveToken;  // offset: 0x810d
    u32 mStatusCode;  // offset: 0x8110
    s32 mContentLength;  // offset: 0x8114
    s32 mVerb;  // offset: 0x8118
    MtNetTime::Total mReqStartTime;  // offset: 0x8120
    f32 mReqElapsedTime;  // offset: 0x8128
    MtString mUserAgent;  // offset: 0x8130
    MtString mUrn;  // offset: 0x8138
    MtString mUrl;  // offset: 0x8140
    MtString mServerUrn;  // offset: 0x8148
    MtString mStsAppliesToUri;  // offset: 0x8150
    u16 mPort;  // offset: 0x8158
    MtString mRequestData;  // offset: 0x8160
    MtString mRequestResult;  // offset: 0x8168
    MtMemoryStream mStream;  // offset: 0x8170
    MT_CTSTR mpCurrent;  // offset: 0x8198
    MtString mAddHeader;  // offset: 0x81a0
    s32 mRno;  // offset: 0x81a8
    u32 mHandle;  // offset: 0x81ac
    s32(cGameHttpClient::*pAnalyzeFunc)();  // offset: 0x81b0
    void* * mpOutputPtr;  // offset: 0x81c0
    u32* mpOutputSize;  // offset: 0x81c8
public:
    static MyDTI DTI;
};

class sHttpClient : public cSystem
{
public:
    class MyDTI;
    class cGameHttpClientInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGameHttpClientInfo
    {
    public:
        cGameHttpClientInfo();
        ~cGameHttpClientInfo();
        void release();
        void setErrorCode(s32 error);
        s32 getErrorCode();
        bool isError();
        cGameHttpClient* getClient();
        bool createClient(u32 handle);
    private:
        cGameHttpClient* mpHttp;  // offset: 0x0
        s32 mErrorCode;  // offset: 0x8
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
    static sHttpClient* getInstance();
    sHttpClient();
    virtual ~sHttpClient();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    void init();
    virtual void move();  // vtable slot 7
    void final();
    void startBrowser(MtString& url);
    u32 getConnectServerNo();
    void setErrorCode(u32 handle, s32 error);
    s32 getErrorCode(u32 handle);
    bool isError(u32 handle);
    void openingServerFlow(u32);
    bool isExecOpeningServerFlow(u32 handle);
    void abort(u32 handle);
    u32 reqServerEnvironmentList(u32 count);
    u32 reqLoginBackDoor(MT_CTSTR pAccount, MT_CTSTR pHost);
    u32 reqDownloadPic(MT_CTSTR addr, void* * ptr, u32* size);
    MtTypedArray<cGameHttpClient::cServerEnvironmentInfo>& getServerEnvironmentInfoListRef();
    void setServerEnvironmentIndex(u32);
    u32 getServerEnvironmentIndex();
    cGameHttpClient::cLoginBackDoorInfo& getLoginBackDoorInfoRef();
    cGameHttpClient* getClient(u32 handle);
    cGameHttpClientInfo* getClientInfo(u32 handle);
    u32 createClient();
public:
    MtTypedArray<cGameHttpClient::cServerEnvironmentInfo> mServerEnvironmentInfoList;  // offset: 0x18
    u32 mServerEnvironmentIndex;  // offset: 0x38
    cGameHttpClient::cLoginBackDoorInfo mLoginBackDoorInfo;  // offset: 0x40
private:
    cGameHttpClientInfo mClientList[9];  // offset: 0x68
public:
    static MyDTI DTI;
    static const u32 HTTP_CLIENT_MAX_NUM = 9;
    static sHttpClient* mpInstance;
};
