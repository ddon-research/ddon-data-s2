#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtString;
class sNetworkExt;
struct tm;

// Declarations
class MtTime;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint64_t = long unsigned int;
using uint64_t = __uint64_t;
using SceFiosDate = uint64_t;
using s32 = int;
using time_t = long int;
using t64 = time_t;

class MtTime
{
    // inferred: sNetworkExt::getClanIntervalRemainTime names MtTime::mTime
    friend class sNetworkExt;
public:
    MtTime();
    MtTime(t64 utc_time);
    static MtTime convertSceFiosDateToMtTime(SceFiosDate);
    MtTime(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 sec);
    ~MtTime();
    bool operator==(const MtTime&) const;
    bool operator!=(const MtTime&) const;
    bool operator<(const MtTime& s) const;
    bool operator<=(const MtTime&) const;
    bool operator>(const MtTime&) const;
    bool operator>=(const MtTime& s) const;
    static MtTime getCurrent();
    s32 getDay();
    s32 getHour();
    s32 getMinute();
    s32 getMonth();
    s32 getYear();
    s32 getSecond();
    s32 getDayOfWeek();
    t64 getTime() const;
    MtString format(MT_CTSTR fmt);
    MtString formatGmt(MT_CTSTR fmt);
    void trace();
private:
    void updateDate(t64 utc_time);
private:
    t64 mTime;  // offset: 0x0
    static tm mTm;
    static t64 mTmTime;
};
