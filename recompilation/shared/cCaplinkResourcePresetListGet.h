#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cResourceInfo; }

// Declarations
namespace nCaplink { class ResourcePresetListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ResourcePresetListGetAns : public nCaplink::ContextListener
    {
    public:
        ResourcePresetListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setResourceInfoTbl(MtArray& entry_list);
        s32 getTotal() const;
        u32 getCount() const;
        nCaplink::cResourceInfo* getResourceInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mResourceInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
