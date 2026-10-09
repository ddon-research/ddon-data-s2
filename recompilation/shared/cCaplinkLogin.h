#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtString.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
class MtString;
namespace nCaplink { class cUserBaseInfo; }

// Declarations
namespace nCaplink { class LoginAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

namespace nCaplink {
    class LoginAns : public nCaplink::ContextListener
    {
    public:
        LoginAns();
        virtual void init();  // vtable slot 6
        bool isLogin() const;
        const nCaplink::cUserBaseInfo* getMyInfo() const;
        MT_CTSTR getSystemMessage() const;
        void setLogin(bool flag);
        void setMyInfo(nCaplink::cUserBaseInfo my_info);
        void setMessage(MtString message);
        void setContentId(MT_CTSTR content_id);
    private:
        bool mIsLogin;  // offset: 0x20
        nCaplink::cUserBaseInfo mMyInfo;  // offset: 0x28
        MtString mMessage;  // offset: 0x2a8
        MtString mContentId;  // offset: 0x2b0
    };
}  // namespace nCaplink
