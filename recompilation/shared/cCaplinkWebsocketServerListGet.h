#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cWebsocketServerInfo; }

// Declarations
namespace nCaplink { class WebsocketServerListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class WebsocketServerListGetAns : public nCaplink::ContextListener
    {
    public:
        WebsocketServerListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setWebsocketServerInfoTbl(MtArray* user_list);
        s32 getTotal() const;
        u32 getWebsocketServerInfoCount() const;
        nCaplink::cWebsocketServerInfo* getWebsocketServerInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mWebsocketServerInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
