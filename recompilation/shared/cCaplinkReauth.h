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
namespace nCaplink { class ReauthAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

namespace nCaplink {
    class ReauthAns : public nCaplink::ContextListener
    {
    public:
        ReauthAns();
        virtual void init();  // vtable slot 6
        const nCaplink::cUserBaseInfo* getMyInfo() const;
        MT_CTSTR getSystemMessage() const;
        void setMyInfo(nCaplink::cUserBaseInfo my_info);
        void setMessage(MtString message);
    private:
        nCaplink::cUserBaseInfo mMyInfo;  // offset: 0x20
        MtString mMessage;  // offset: 0x2a0
    };
}  // namespace nCaplink
