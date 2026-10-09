#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
namespace nCaplink { class cAchievementRelationInfo; }

// Declarations
namespace nCaplink { class ContentAchievementRelationGetAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class ContentAchievementRelationGetAns : public nCaplink::ContextListener
    {
    public:
        ContentAchievementRelationGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setCount(s32 count);
        void addAchievementList(nCaplink::cAchievementRelationInfo* pAddInfo);
        s32 getTotal() const;
        s32 getCount() const;
        const MtTypedArray<nCaplink::cAchievementRelationInfo>& getAchievementList() const;
    private:
        s32 mTotal;  // offset: 0x20
        s32 mCount;  // offset: 0x24
        MtTypedArray<nCaplink::cAchievementRelationInfo> mAchievementList;  // offset: 0x28
    };
}  // namespace nCaplink
