#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtString.h"
#include "httpPatch.h"
#include "httpPatchTypes.h"

// Forward declarations
class MtString;
namespace via { namespace module { namespace http_patch { class ParallelsListenerManager; } } }

namespace via {
namespace module {
namespace http_patch {
    enum RedirectPolicy
    {
        RedirectPolicy_Never = 0,
        RedirectPolicy_Always = 1,
        RedirectPolicy_DisallowHttpsToHttp = 2,
        RedirectPolicy_NoSchemeChanges = 3,
    };
}  // namespace http_patch
}  // namespace module
}  // namespace via

// Declarations
namespace via { namespace module { namespace http_patch { class ClientManager; } } }
namespace via { namespace module { namespace http_patch { class RequestParam; } } }
namespace via { namespace module { namespace http_patch { class RequestParamCore; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using httpdl_array_MtStringExURL = MtCollisionUtil::MtArrayTemplateEx<MtStringEx<256>, true, 1>;
using httpdl_array_s32 = MtCollisionUtil::MtArrayTemplateEx<int, false, 1>;
using size_t = _Sizet;
using u32 = unsigned int;

namespace via {
    namespace module {
        namespace http_patch {
            class ClientManager
            {
            public:
                ClientManager();
                ~ClientManager();
                void setParam(const via::module::http_patch::RequestParamCore& param);
                via::module::http_patch::Result request(via::module::http_patch::ParallelsListenerManager* listener_ptr, const size_t task_max, const httpdl_array_MtStringExURL* uri_path_str_tbl, const httpdl_array_s32* affinity_tbl);
                via::module::http_patch::Result request(via::module::http_patch::ParallelsListenerManager* listener_ptr, MT_CTSTR uri_path_str_ptr);
                u32 getTaskNum() const;
                MT_CTSTR getVersionListName() const;
                MT_CTSTR getFileListName() const;
                MT_CTSTR getExeVersionFileName() const;
                MT_CTSTR getUriAuthority() const;
                MT_CTSTR getURLDirectory() const;
                MT_CTSTR getmSaveDirectoryName() const;
                u32 getExecuteThreadNum() const;
            private:
                void setupCommon();
            private:
                MtStringEx<1024> mAuthorityURL;  // offset: 0x0
                MtStringEx<1024> mURLDirectory;  // offset: 0x404
                MtStringEx<128> mUserAgent;  // offset: 0x808
                MtStringEx<128> mProxyServer;  // offset: 0x88c
                MtStringEx<128> mVersionListName;  // offset: 0x910
                MtStringEx<128> mFileListName;  // offset: 0x994
                MtStringEx<128> mExeVersionFileName;  // offset: 0xa18
                MtStringEx<128> mSaveDirectoryName;  // offset: 0xa9c
                via::module::http_patch::RedirectPolicy mRedirectPolicy;  // offset: 0xb20
                u32 mExecThreadNum;  // offset: 0xb24
                u32 mSecurityFlags;  // offset: 0xb28
                bool mAllowInsecure;  // offset: 0xb2c
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class RequestParamCore
            {
            public:
                RequestParamCore(const via::module::http_patch::RequestParamCore&);
                RequestParamCore();
                const via::module::http_patch::RequestParamCore& operator=(const via::module::http_patch::RequestParamCore&);
                void copy(const via::module::http_patch::RequestParamCore&);
            public:
                MtString mAuthorityURL;  // offset: 0x0
                MtString mURLDirectory;  // offset: 0x8
                MtString mUserAgent;  // offset: 0x10
                MtString mProxyServer;  // offset: 0x18
                MtString mVersionListName;  // offset: 0x20
                MtString mFileListName;  // offset: 0x28
                MtString mExeVersionFileName;  // offset: 0x30
                MtString mSaveDirectoryName;  // offset: 0x38
                u32 mFileIORequestQueueSize;  // offset: 0x40
                u32 mFileIOBlockSize;  // offset: 0x44
                u32 mRedirectPolicy;  // offset: 0x48
                u32 mExecThreadNum;  // offset: 0x4c
                u32 mSecurityFlags;  // offset: 0x50
                u32 mRetryCount;  // offset: 0x54
                bool mAllowInsecure;  // offset: 0x58
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class RequestParam
            {
            protected:
                const MtString& getParamUriAuthorityStr() const;
                const MtString& getParamURLDirectoryStr() const;
                const MtString& getParamUserAgentStr() const;
                const MtString& getParamProxyServerStr() const;
                const MtString& getParamDownloadFileListNameStr() const;
                const MtString& getParamDownloadVersionListNameStr() const;
                const MtString& getParamExeVersionFileNameStr() const;
                const MtString& getParamSaveDirectoryNameStr() const;
                u32 getParamFileIORequestQueueSize() const;
                u32 getParamFileIOBlockSize() const;
                u32 getParamSecurityFlags() const;
                u32 getParamExecuteThreadNum() const;
                u32 getParamRetryCount() const;
                bool getParamAllowInsecure() const;
                via::module::http_patch::RedirectPolicy getParamRedirectPolicy() const;
            public:
                void setParamUriAuthorityStr(const MtString& str);
                void setParamURLDirectoryStr(const MtString& str);
                void setParamUserAgentStr(const MtString& str);
                void setParamProxyServerStr(const MtString& str);
                void setParamDownloadFileListNameStr(const MtString& str);
                void setParamDownloadVersionListNameStr(const MtString& str);
                void setParamExeVersionFileNameStr(const MtString& str);
                void setParamSaveDirectoryNameStr(const MtString& str);
                void setParamFileIORequestQueueSize(const u32 size = 128);
                void setParamFileIOBlockSize(const u32 size = 131072);
                void setParamSecurityFlags(const u32 flags = 0);
                void setParamExecuteThreadNum(const u32 num);
                void setParamRetryCount(const u32 count);
                void setParamAllowInsecure(const bool flag = false);
                void setParamRedirectPolicy(const via::module::http_patch::RedirectPolicy rpolicy);
                RequestParam();
                virtual ~RequestParam();
                void setUserAgent(MT_CTSTR);
                void setUriAuthorityStr(MT_CTSTR str_ptr);
                void setProxyServer(MT_CTSTR);
                void setAllowInsecure(bool);
                bool isAllowInsecure() const;
                void setSecurityFlags(u32);
                u32 getSecurityFlags();
                void setRedirectPolicy(via::module::http_patch::RedirectPolicy);
                via::module::http_patch::RedirectPolicy getRedirectPolicy();
                void setDownloadFileListName(MT_CTSTR);
                MT_CTSTR getDownloadFileListName();
                void setDownloadVersionListName(MT_CTSTR);
                MT_CTSTR getDownloadVersionListName();
                void setExeVersionFileName(MT_CTSTR);
                MT_CTSTR getExeVersionFileName();
                void setSaveDirectoryName(MT_CTSTR);
                MT_CTSTR getSaveDirectoryName();
                void setExecuteThreadNum(const u32);
                void setFileIORequestQueueSize(const u32);
                void setFileIOBlockSize(const u32);
                void setRetryCount(const u32);
                const via::module::http_patch::RequestParamCore& getRequestParam() const;
            private:
                via::module::http_patch::RequestParamCore mParam;  // offset: 0x8
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline void via::module::http_patch::RequestParam::setParamFileIORequestQueueSize(const u32 size) {
    this->mParam.mFileIORequestQueueSize = 128;
}

inline void via::module::http_patch::RequestParam::setParamFileIOBlockSize(const u32 size) {
    this->mParam.mFileIOBlockSize = 0x20000;
}

inline void via::module::http_patch::RequestParam::setParamSecurityFlags(const u32 flags) {
    this->mParam.mSecurityFlags = 0;
}

inline void via::module::http_patch::RequestParam::setParamAllowInsecure(const bool flag) {
    this->mParam.mAllowInsecure = false;
}

inline const via::module::http_patch::RequestParamCore& via::module::http_patch::RequestParam::getRequestParam() const {
    return this->mParam;
}
