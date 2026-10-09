#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cNotifyAppInfo; }

// Declarations
namespace nCaplink { class NotifyAppListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class NotifyAppListGetAns : public nCaplink::ContextListener
    {
    public:
        NotifyAppListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setNotifyAppInfoTbl(MtArray& entry_list);
        u32 getNotifyAppTotal() const;
        u32 getNotifyAppCount() const;
        nCaplink::cNotifyAppInfo* getNotifyAppInfo(s32 index) const;
        const MtArray* getNotifyAppInfoList();
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mNotifyAppInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
