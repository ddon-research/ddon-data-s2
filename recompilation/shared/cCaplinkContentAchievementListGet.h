#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
namespace nCaplink { class cAchievementListInfo; }

// Declarations
namespace nCaplink { class ContentAchievementListGetAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class ContentAchievementListGetAns : public nCaplink::ContextListener
    {
    public:
        ContentAchievementListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setCount(s32 count);
        void addAchievementList(nCaplink::cAchievementListInfo* pAddInfo);
        s32 getTotal() const;
        s32 getCount() const;
        const MtTypedArray<nCaplink::cAchievementListInfo>& getAchievementList() const;
    private:
        s32 mTotal;  // offset: 0x20
        s32 mCount;  // offset: 0x24
        MtTypedArray<nCaplink::cAchievementListInfo> mAchievementList;  // offset: 0x28
    };
}  // namespace nCaplink
