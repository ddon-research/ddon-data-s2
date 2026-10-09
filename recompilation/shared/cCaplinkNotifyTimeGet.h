#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class NotifyTimeGetAns; }

// Type aliases from DWARF
using s8 = signed char;

namespace nCaplink {
    class NotifyTimeGetAns : public nCaplink::ContextListener
    {
    public:
        NotifyTimeGetAns();
        virtual void init();  // vtable slot 6
        void setParam(s8 morning, s8 afternoon, s8 midnight, s8 evening);
        s8 getMorning() const;
        s8 getAfternoon() const;
        s8 getMidnight() const;
        s8 getEvening() const;
    private:
        s8 mMorning;  // offset: 0x20
        s8 mAfternoon;  // offset: 0x21
        s8 mMidnight;  // offset: 0x22
        s8 mEvening;  // offset: 0x23
    };
}  // namespace nCaplink
