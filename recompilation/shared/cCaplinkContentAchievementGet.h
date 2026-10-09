#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
namespace nCaplink { class cAchievementExtendedInfo; }

// Declarations
namespace nCaplink { class ContentAchievementGetAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

namespace nCaplink {
    class ContentAchievementGetAns : public nCaplink::ContextListener
    {
    public:
        ContentAchievementGetAns();
        virtual void init();  // vtable slot 6
        void setAchievement(MT_CTSTR achievement);
        void addExtended(nCaplink::cAchievementExtendedInfo* pAddInfo);
        MT_CTSTR getAchievement() const;
        const MtTypedArray<nCaplink::cAchievementExtendedInfo>& getExtended() const;
    private:
        char mAchievement[2732];  // offset: 0x20
        MtTypedArray<nCaplink::cAchievementExtendedInfo> mExtended;  // offset: 0xad0
    };
}  // namespace nCaplink
