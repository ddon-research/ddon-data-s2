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
namespace nCaplink { class LoginCogKeyAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

namespace nCaplink {
    class LoginCogKeyAns : public nCaplink::ContextListener
    {
    public:
        LoginCogKeyAns();
        virtual void init();  // vtable slot 6
        bool isLogin() const;
        const nCaplink::cUserBaseInfo* getMyInfo() const;
        MT_CTSTR getSystemMessage() const;
        void setLogin(bool flag);
        void setMyInfo(nCaplink::cUserBaseInfo my_info);
        void setMessage(MtString message);
    private:
        bool mIsLogin;  // offset: 0x20
        nCaplink::cUserBaseInfo mMyInfo;  // offset: 0x28
        MtString mMessage;  // offset: 0x2a8
    };
}  // namespace nCaplink
