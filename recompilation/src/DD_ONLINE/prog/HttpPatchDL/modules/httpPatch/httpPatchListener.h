#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtFile.h"
#include "../../../../../MT/MtStream.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../xXFramework/cHttpClient_C.h"
#include "utility/hash.h"
#include "httpPatch.h"
#include "httpPatchTypes.h"
#include "../network/networkHttpDownloadManager.h"

// Forward declarations
class MtCriticalSection;
class MtFile;
class MtFileStream;
class MtString;
namespace via { namespace module { namespace http_patch { class ClientManager; } } }
namespace via { namespace module { namespace http_patch { struct ExeFileInfo; } } }
namespace via { namespace module { namespace http_patch { class FileController; } } }

// Declarations
namespace via { namespace module { namespace http_patch { class ExeVersionListener; } } }
namespace via { namespace module { namespace http_patch { class FileListener; } } }
namespace via { namespace module { namespace http_patch { class ParallelsListenerManager; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
namespace via { namespace module { namespace http_patch { using exefileinfo_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::ExeFileInfo, true, 1>; } } }
namespace via { using sha256 = via::hash<via::HashType_SHA256>; }
namespace via { using sha256hash_t = via::hash<via::HashType_SHA256>::value_type; }

namespace via {
    namespace module {
        namespace http_patch {
            class FileListener
            {
                friend class via::module::http_patch::ParallelsListenerManager;
            public:
                enum Phase
                {
                    Phase_None = 0,
                    Phase_Request = 1,
                    Phase_Running = 2,
                    Phase_Finished = 3,
                    Phase_Failed = 4,
                    Phase_Abort = 5,
                };
            public:
                FileListener(via::module::http_patch::FileController* controller_ptr);
                virtual ~FileListener();
                Phase getPhase() const;
                via::module::http_patch::PacketSaveType getSaveType() const;
                size_t getDownloadSize() const;
                size_t getDownloadFileSize() const;
                void setDownloadFileSize(size_t size);
                size_t getMemoryStoreMaxSize() const;
                void setCopyBuffer(u8*, const size_t);
                const MtString& getCopyFileName() const;
                void setCopyFileName(MT_CTSTR dest_str, bool direct);
                MT_CTSTR getTempPath();
                bool isCopy() const;
                bool isDirectCopy() const;
                bool isDirectHash() const;
            protected:
                virtual bool secceedAfter();  // vtable slot 2
                virtual void reset();  // vtable slot 3
                virtual void onReceiveHeader(const HttpClient::ResponseHeader& header, const u32 attribute, HttpClient::RecvBuf& next_buf);  // vtable slot 4
                virtual void onReceiveData(const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);  // vtable slot 5
                virtual bool onSucceed();  // vtable slot 6
                virtual void onFail(HPDErrCategory ecType, s32 error);  // vtable slot 7
                bool isAppendFile() const;
                size_t getAppendFileSize() const;
                MtFile& getTempFileHandle();
                void setPhase(Phase Phase);
                void setErrorCode(HPDErrCategory ecType, s32 error);
                void setSaveType(via::module::http_patch::PacketSaveType type);
                void setDirectHash(bool bl);
                via::module::http_patch::FileController* getFileControllerPtr() const;
                const u8* getStoreBufferPtr() const;
                via::sha256hash_t& getHashDigest();
            private:
                Phase mPhase;  // offset: 0x8
                via::module::http_patch::PacketSaveType mSaveType;  // offset: 0xc
                bool mDirectHash;  // offset: 0x10
                HPDErrCategory mEcType;  // offset: 0x14
                s32 mErCode;  // offset: 0x18
                via::module::http_patch::FileController* mFileControllerPtr;  // offset: 0x20
                MtStringEx<256> mTempPath;  // offset: 0x28
                MtString mCopyFileName;  // offset: 0x130
                MtFile mhTempFile;  // offset: 0x138
                MtFileStream mhTempFileStream;  // offset: 0x580
                u8* mStoreBufferPtr;  // offset: 0x590
                size_t mStoreMaxSize;  // offset: 0x598
                size_t mStoreOffset;  // offset: 0x5a0
                bool mDownloadSplit;  // offset: 0x5a8
                size_t mDownloadSize;  // offset: 0x5b0
                size_t mDownloadFileSize;  // offset: 0x5b8
                void* mTempBufferBlockPtr;  // offset: 0x5c0
                size_t mDownloadSplitSize;  // offset: 0x5c8
                via::sha256 mHash;  // offset: 0x5d0
                via::sha256hash_t mHashDigest;  // offset: 0x660
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class ParallelsListenerManager : public via::module::network::utility::HttpDownloadManager::Listener
            {
                friend class via::module::http_patch::ClientManager;
            public:
                explicit ParallelsListenerManager(const u32 max_taskcount, s64 loaded_downloadsize, s64 loaded_filenum);
                explicit ParallelsListenerManager(via::module::http_patch::FileListener* listener_ptr);
                virtual ~ParallelsListenerManager();
                via::module::http_patch::FileListener::Phase getPhase() const;
                HPDErrCategory getResultDetailErrorCategory() const;
                s32 getResultDetailErrorCode() const;
                s32 getFailedCount() const;
                s64 getDownloadFileNum() const;
                s64 getDownloadSize() const;
            protected:
                virtual void onSucceedAll();  // vtable slot 2
                virtual void onFailAll(s32 error);  // vtable slot 3
                virtual void onStart(size_t task_index, size_t uri_index, const MtString& uri_path_str);  // vtable slot 4
                virtual void onReceiveHeader(size_t task_index, size_t uri_index, const MtString& uri_path_str, const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf);  // vtable slot 5
                void onReceiveHeader(size_t task_index, size_t uri_index, const MtString& uri_path_str, const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf, const u32 attribute);
                virtual void onReceiveData(size_t task_index, size_t uri_index, const MtString& uri_path_str, const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf);  // vtable slot 6
                virtual void onSucceed(size_t task_index, size_t uri_index, const MtString& uri_path_str);  // vtable slot 7
                virtual bool onSucceedCore(size_t task_index, size_t uri_index, const MtString& uri_path_str);  // vtable slot 14
                virtual void onFail(size_t task_index, size_t uri_index, const MtString& uri_path_str, HPDErrCategory ecType, s32 error);  // vtable slot 8
                virtual bool isAbortFlagInCB();  // vtable slot 9
                void setPhase(via::module::http_patch::FileListener::Phase phase);
                virtual void setProgressDL1File(f32 per);  // vtable slot 10
                void setResultDetail(HPDErrCategory, s32);
                virtual void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);  // vtable slot 11
                virtual void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 12
                virtual void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);  // vtable slot 13
                void deleteListener(const size_t task_index);
                via::module::http_patch::FileListener* createListener(const size_t task_index);
                via::module::http_patch::FileListener& getListener(const size_t task_index);
                via::module::http_patch::FileListener* getListenerPtr(const size_t task_index);
                static void addDownloadSizeProc(void* this_ptr, const s64 size);
                static void subDownloadSizeProc(void* this_ptr, const s64 size);
                static void incDownloadFileCountProc(void* this_ptr);
            public:
                const via::module::http_patch::ParallelsListenerManager& operator=(const via::module::http_patch::ParallelsListenerManager&);
            private:
                via::module::http_patch::FileListener* * mListenerPtr;  // offset: 0x8
                via::module::http_patch::FileListener::Phase mPhase;  // offset: 0x10
                HPDErrCategory mEcType;  // offset: 0x14
                s32 mErCode;  // offset: 0x18
                MtCriticalSection mCreateListenerEventMutex;  // offset: 0x20
                s32 mDownloadFileNum;  // offset: 0x28
                s64 mDownloadSize;  // offset: 0x30
                s32 mFailedCount;  // offset: 0x38
                const bool AuthorizationOutside;  // offset: 0x3c
                const u32 MaxTaskCount;  // offset: 0x40
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class ExeVersionListener : public via::module::http_patch::FileListener
            {
            public:
                ExeVersionListener(via::module::http_patch::FileController* controller_ptr);
                u32 getVersionLauncher();
                u32 getVersionGameApp();
            private:
                virtual bool secceedAfter();  // vtable slot 2
            public:
                const via::module::http_patch::exefileinfo_array_t& getExeFileInfo() const;
            private:
                void setExeFileInfo(const via::module::http_patch::exefileinfo_array_t&);
            private:
                u32 mVersionsLauncher;  // offset: 0x680
                u32 mVersionsGameApp;  // offset: 0x684
                via::module::http_patch::exefileinfo_array_t mExeFileInfo;  // offset: 0x688
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline via::module::http_patch::PacketSaveType via::module::http_patch::FileListener::getSaveType() const {
    return this->mSaveType;
}

inline size_t via::module::http_patch::FileListener::getDownloadSize() const {
    return this->mDownloadSize;
}

inline size_t via::module::http_patch::FileListener::getDownloadFileSize() const {
    return this->mDownloadFileSize;
}

inline const MtString& via::module::http_patch::FileListener::getCopyFileName() const {
    return this->mCopyFileName;
}

inline via::module::http_patch::FileListener& via::module::http_patch::ParallelsListenerManager::getListener(const size_t task_index) {
    return *this->mListenerPtr[task_index];
}

inline via::module::http_patch::FileListener* via::module::http_patch::ParallelsListenerManager::getListenerPtr(const size_t task_index) {
    return this->mListenerPtr[task_index];
}
