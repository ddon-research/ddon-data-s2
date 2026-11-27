#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtString.h"
#include "../../xvia/atomic.h"
#include "../../xXFramework/cHttpClient_C.h"
#include "../httpPatch/httpPatch.h"

// Forward declarations
class HttpClient;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class via_atomic_bool;

// Declarations
namespace via { namespace module { namespace network { namespace utility { class HttpDownloadManager; } } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using httpdl_array_MtStringExURL = MtCollisionUtil::MtArrayTemplateEx<MtStringEx<256>, true, 1>;
using httpdl_array_s32 = MtCollisionUtil::MtArrayTemplateEx<int, false, 1>;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace via {
    namespace module {
        namespace network {
            namespace utility {
                class HttpDownloadManager : public ::MtNetSubObject
                {
                public:
                    class Task;
                    class Listener;
                    class UriTbl;
                public:
                    using httpdl_array_Task = MtCollisionUtil::MtArrayTemplateEx<via::module::network::utility::HttpDownloadManager::Task*, true, 1>;
                public:
                    class Task : public ::MtNetSubObject, public HttpClient::Listener
                    {
                    public:
                        Task();
                        virtual ~Task();
                        void clear();
                        void abort();
                        void dispatch(via::module::network::utility::HttpDownloadManager* ptr, size_t index);
                        bool isEnd();
                        void update();
                        virtual void onReceiveHeader(const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf);  // vtable slot 2
                        virtual void onReceiveData(const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);  // vtable slot 3
                        virtual void onSucceed();  // vtable slot 5
                        virtual void onFail(HPDErrCategory ecType, s32 error);  // vtable slot 6
                        virtual void onWait();  // vtable slot 7
                        virtual void setProgressDL1File(f32 per);  // vtable slot 8
                        virtual void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);  // vtable slot 9
                        virtual void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 10
                        virtual void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 11
                        virtual bool isAbortFlagInCB();  // vtable slot 12
                        virtual u32 getCbContentLength();  // vtable slot 13
                    private:
                        via::module::network::utility::HttpDownloadManager* mManagerPtr;  // offset: 0x28
                        size_t mIndex;  // offset: 0x30
                        HttpClient* mHttpPtr;  // offset: 0x38
                        size_t mUriIdx;  // offset: 0x40
                        MtString mUriStr;  // offset: 0x48
                        bool mIsEnd;  // offset: 0x50
                        HPDErrCategory mCbEcType;  // offset: 0x54
                        size_t mCbStatusCode;  // offset: 0x58
                        size_t mCbContentLength;  // offset: 0x60
                        size_t mCbReceiveLength;  // offset: 0x68
                    };
                public:
                    class Listener
                    {
                    public:
                        Listener();
                        virtual ~Listener() {}
                        virtual void onSucceedAll();  // vtable slot 2
                        virtual void onFailAll(s32 error);  // vtable slot 3
                        virtual void onStart(size_t task_index, size_t uri_index, const MtString& uri_path_str);  // vtable slot 4
                        virtual void onReceiveHeader(size_t task_index, size_t uri_index, const MtString& uri_path_str, const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf);  // vtable slot 5
                        virtual void onReceiveData(size_t task_index, size_t uri_index, const MtString& uri_path_str, const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);  // vtable slot 6
                        virtual void onSucceed(size_t task_index, size_t uri_index, const MtString& uri_path_str);  // vtable slot 7
                        virtual void onFail(size_t task_index, size_t uri_index, const MtString& uri_path_str, HPDErrCategory ecType, s32 error);  // vtable slot 8
                        virtual bool isAbortFlagInCB();  // vtable slot 9
                        virtual void setProgressDL1File(f32 per);  // vtable slot 10
                        virtual void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);  // vtable slot 11
                        virtual void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 12
                        virtual void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 13
                        const via::module::network::utility::HttpDownloadManager::Listener& operator=(const via::module::network::utility::HttpDownloadManager::Listener&);
                    };
                public:
                    class UriTbl : public ::MtNetSubObject
                    {
                    public:
                        class Uri;
                    public:
                        using httpdl_array_Uri = MtCollisionUtil::MtArrayTemplateEx<via::module::network::utility::HttpDownloadManager::UriTbl::Uri, true, 1>;
                    public:
                        class Uri : public ::MtObject
                        {
                        public:
                            class MyDTI;
                        public:
                            class MyDTI : public ::MtDTI
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
                            via::module::network::utility::HttpDownloadManager::UriTbl::Uri& operator=(const via::module::network::utility::HttpDownloadManager::UriTbl::Uri& obj);
                        public:
                            MtString mStr;  // offset: 0x8
                            u8 mFailCount;  // offset: 0x10
                            u8 mIsStart;  // offset: 0x11
                            u8 mIsEnd;  // offset: 0x12
                            s32 mLastError;  // offset: 0x14
                            HPDErrCategory mEcType;  // offset: 0x18
                            s32 mAffinity;  // offset: 0x1c
                            static MyDTI DTI;
                        };
                    public:
                        UriTbl();
                        void clear();
                        void abort();
                        void import(const httpdl_array_MtStringExURL* tbl, const httpdl_array_s32* affinity_tbl);
                        s32 next(const size_t task_index, MtString* & ptr);
                        void succeed(const MtString& str);
                        void fail(const MtString& str, HPDErrCategory ecType, s32 error);
                        bool isFail(s32& error);
                    private:
                        httpdl_array_Uri mTbl;  // offset: 0x20
                        bool mIsAbort;  // offset: 0x40
                        bool mIsFail;  // offset: 0x41
                        s32 mLastError;  // offset: 0x44
                        HPDErrCategory mEcType;  // offset: 0x48
                    };
                public:
                    static via::module::network::utility::HttpDownloadManager* createInstance();
                    static void deleteInstance();
                    static via::module::network::utility::HttpDownloadManager* instance();
                    explicit HttpDownloadManager();
                    virtual ~HttpDownloadManager();
                    void update();
                    HttpClient::Error request(Listener& listener, MT_CTSTR uri_authority_str_ptr, MT_CTSTR uri_path_str_ptr, const int affinity);
                    HttpClient::Error request(Listener& listener, size_t task_num, MT_CTSTR uri_authority_str_ptr, const httpdl_array_MtStringExURL* uri_path_str_tbl, const httpdl_array_s32* affinity_tbl);
                    void abortAll();
                    bool isInProgress() const;
                    void setReceiveDataMaxSize(size_t data_size);
                    void setUserAgent(MT_CTSTR str_ptr);
                    void setProxyServer(MT_CTSTR str_ptr);
                    void setAllowInsecure(bool flag);
                    u32 getSecurityFlags();
                    void setSecurityFlags(u32 flags);
                    HttpClient::RedirectPolicy getRedirectPolicy();
                    void setRedirectPolicy(HttpClient::RedirectPolicy policy);
                    void taskInit(HttpClient* ptr);
                    s32 taskNext(const size_t task_index, MtString* & ptr);
                    MT_CTSTR taskGetAuthStr();
                    void taskStart(size_t task_index, size_t uri_index, const MtString& uri_path_str);
                    void taskReceiveHeader(size_t task_index, size_t uri_index, const MtString& uri_path_str, const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf);
                    void taskReceiveData(size_t task_index, size_t uri_index, const MtString& uri_path_str, const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);
                    void taskSucceed(size_t task_index, size_t uri_index, const MtString& uri_path_str);
                    void taskFail(size_t task_index, size_t uri_index, const MtString& uri_path_str, HPDErrCategory ecType, s32 error);
                    bool isAbortFlagInCB();
                    void setProgressDL1File(f32 per);
                    void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);
                    void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                    void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                public:
                    size_t mReceiveDataMaxSize;  // offset: 0x28
                    MT_CTSTR mUserAgentStrPtr;  // offset: 0x30
                    MT_CTSTR mProxyNameStrPtr;  // offset: 0x38
                    u32 mSecurityFlags;  // offset: 0x40
                    HttpClient::RedirectPolicy mRedirectPolicy;  // offset: 0x44
                    httpdl_array_Task mTaskTbl;  // offset: 0x48
                    via_atomic_bool mIsInProgress;  // offset: 0x68
                    Listener* mListenerPtr;  // offset: 0x80
                    MT_CTSTR mAuthUriStrPtr;  // offset: 0x88
                    UriTbl mPathUriTbl;  // offset: 0x90
                    static via::module::network::utility::HttpDownloadManager* mpInstance;
                    static const size_t MaxNumTask = 4;
                    static const size_t MaxTimeFail = 3;
                };
            }  // namespace utility
        }  // namespace network
    }  // namespace module
}  // namespace via

inline via::module::network::utility::HttpDownloadManager* via::module::network::utility::HttpDownloadManager::instance() {
    return ::via::module::network::utility::HttpDownloadManager::mpInstance;
}

inline MT_CTSTR via::module::network::utility::HttpDownloadManager::taskGetAuthStr() {
    return this->mAuthUriStrPtr;
}

inline via::module::network::utility::HttpDownloadManager::Listener::Listener() {
}

inline void* via::module::network::utility::HttpDownloadManager::UriTbl::Uri::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
