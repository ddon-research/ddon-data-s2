#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cHttpClient.h"
#include "../shared/cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cHttpClient;
class cNetGameServer;
class rGUIMessage;
class rTexture;
class rTextureJpeg;

// Declarations
class sScreenShot;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sScreenShot : public cSystem
{
    // inferred: cNetGameServer::getPhotoAuthAddressReq names sScreenShot::mIsAuthAddrReqSucces
    friend class cNetGameServer;
public:
    enum
    {
        RNO_REQ_WAIT = 0,
        RNO_START = 1,
        RNO_TRIGGER = 2,
        RNO_RESULT_WAIT = 3,
        RNO_JPG_OUT = 4,
        RNO_END = 5,
        RNO_EXPORT = 6,
        RNO_RELEASE_TEX = 7,
    };
    enum
    {
        TYPE_NONE = 0,
        TYPE_GET_KEY = 1,
        TYPE_UPLOAD = 2,
    };
    enum
    {
        RESULT_NONE = 0,
        RESULT_COMPLETE = 200,
        RESULT_PARAM_ERR = 400,
        RESULT_TOKEN_ERR = 401,
        RESULT_LOGIN_NG = 403,
        RESULT_UPLOAD_NG = 406,
        RESULT_ERROR = 500,
        RESULT_UNKNOWN = 999,
    };
    enum
    {
        RET_NONE = 0,
        RET_SUCCESS = 1,
        RET_NO_SSHOT = 2,
        RET_UPLOAD_NOW = 3,
        RET_FAILED = 4,
        RET_NOT_LOGIN = 5,
        RET_NOT_STAGE = 6,
        RET_NOT_GAME = 7,
        RET_NOT_CLIENT = 8,
        RET_NOT_BUFF = 9,
        RET_GET_TOKEN_NOW = 10,
        RET_NOT_GET_TOKEN = 11,
        RET_NG_UPLOAD_URL = 12,
    };
    enum
    {
        RESULT_BUF_SIZE = 4096,
    };
    enum
    {
        RESULT_KEY_NONE = 0,
        RESULT_KEY_COMPLETE = 200,
        RESULT_KEY_PARAM_ERR = 400,
        RESULT_KEY_TIMER = 403,
        RESULT_KEY_ERROR = 500,
        RESULT_KEY_MEMORY = 503,
        RESULT_KEY_UNKNOWN = 999,
    };
public:
    class MyDTI;
    struct JpegInfo;
    class HttpListener;
    class HttpResult;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct JpegInfo
    {
    public:
        MT_CHAR* mpDataBuf;  // offset: 0x0
        u32 mDataSize;  // offset: 0x8
    };
public:
    class HttpResult
    {
    public:
        HttpResult();
        void clear();
    public:
        bool mIsError;  // offset: 0x0
        u8 mResultBuf[4096];  // offset: 0x1
        s32 mResultSize;  // offset: 0x1004
    };
public:
    class HttpListener : public cHttpClient::Listener
    {
    public:
        virtual void onReceiveHeader(const cHttpClient::ResponseHeader* head_ptr);  // vtable slot 2
        virtual void onReceiveData(void* data_ptr, s32 data_size);  // vtable slot 3
        virtual void onErrorEncounterd(s32 error_code);  // vtable slot 4
    public:
        sScreenShot::HttpResult mHttpResult;  // offset: 0x8
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
    sScreenShot();
    virtual ~sScreenShot();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void move_main();
    void move_texture();
    void init();
    void releaseJpg();
    static sScreenShot* getInstance();
    void saveShotInfo();
    bool isSetup() const;
    void requestKill();
    void requestScreenShot();
    bool isRequest();
    bool isCapture();
    void startScreenShot();
    void finishScreenShot();
    void createScreenShot(void* ptr, u32 size);
    void releaseScreenShot();
    bool isCreateScreenShotTexture();
    bool createScreenShotTexture();
    void releaseScreenShotTexture();
    rTexture* getScreenShotTexture();
    bool isExistsScreenShot();
    s32 getShotStageNo();
    const MtVector3& getShotPos();
    void setShotCategory(u32 cate);
    void setShotComment(MT_CTSTR comm);
    void initUpload();
    void move_upload();
    bool analyzeMessage(MtString& dst, MtString key, u8* src, u32 size);
    void releaseUpload();
    void releaseUploadData();
    u32 uploadScreenShot();
    u32 uploadScreenShot(void* jpg_ptr, u32 jpg_size);
    bool isUpload();
    bool isGetToken();
    u32 getResult() const;
    MtString getResultMsg() const;
    bool isGetTokenKey() const;
    bool createScreenShotData(void* jpg_ptr, u32 jpg_size);
    void createTextData();
    u32 getTokenKey();
    void tokenSplit(MT_CTSTR in_key, MT_CTSTR in_addr);
    void setTokenParam(MtString key, MtString urn, MtString url);
    void setGetAuthAddr(bool flg);
    void setAuthAddrReqSucces(bool flg);
    bool isAuthAddrReqSucces();
private:
    bool mIsSetup;  // offset: 0x11
    u8 mRno;  // offset: 0x12
    void* mpJpg;  // offset: 0x18
    u32 mJpg_size;  // offset: 0x20
    u32 mCnt;  // offset: 0x24
    bool mIsSShotReq;  // offset: 0x28
    rGUIMessage* mpGMDRes;  // offset: 0x30
    void* mpScreenShotJpg;  // offset: 0x38
    u32 mScreenShotJpgSize;  // offset: 0x40
    JOBHANDLE mScreenShotHandle;  // offset: 0x48
    rTextureJpeg* mpScreenShotTexture;  // offset: 0x50
    bool mReqDeleteScreenShot;  // offset: 0x58
    s32 mShotStageNo;  // offset: 0x5c
    MtVector3 mShotPos;  // offset: 0x60
    u32 mShotTime;  // offset: 0x70
    u32 mShotWeather;  // offset: 0x74
    u32 mShotHard;  // offset: 0x78
    u32 mShotCategory;  // offset: 0x7c
    MtStringEx<512> mShotComment;  // offset: 0x80
    u32 mHttpType;  // offset: 0x284
    MtString mTokenKey;  // offset: 0x288
    MtString mDescription;  // offset: 0x290
    cHttpClient* mpHttpClient;  // offset: 0x298
    MtString mUserAgent;  // offset: 0x2a0
    MtString mUrnStr;  // offset: 0x2a8
    MtString mUrlStr;  // offset: 0x2b0
    MtString mHeader;  // offset: 0x2b8
    JpegInfo mJpegInfo;  // offset: 0x2c0
    MT_CHAR* mpContentData;  // offset: 0x2d0
    HttpListener mListener;  // offset: 0x2d8
    u32 mResult;  // offset: 0x12e8
    bool mIsGetTokenKey;  // offset: 0x12ec
    MtString mResultMsg;  // offset: 0x12f0
    MtString mGetToken;  // offset: 0x12f8
    MtString mGetUrnStr;  // offset: 0x1300
    MtString mGetUrlStr;  // offset: 0x1308
    bool mIsGetAuthAddr;  // offset: 0x1310
    bool mIsAuthAddrReqSucces;  // offset: 0x1311
    static sScreenShot* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sScreenShot* sScreenShot::getInstance() {
    return ::sScreenShot::mpInstance;
}
