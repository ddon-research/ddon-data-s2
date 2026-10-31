#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class cGameMoonAge;
class cGameTime;
class cGameWeather;

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

class cGameMoonAge
{
public:
    cGameMoonAge();
    void updateGameMoonAge();
    void reqMoonAge(s32 age);
    s32 getMoonAge() const;
public:
    s32 mGameMoonAge;  // offset: 0x0
    s32 mReqMoonAge;  // offset: 0x4
    bool mReqOn;  // offset: 0x8
};

class cGameTime
{
public:
    cGameTime();
    void updateGameTime();
    void reqGameTime(u32 msec);
    void setGameTimePause(bool b);
    u32 getGameTimeMSec() const;
public:
    u32 mMSec;  // offset: 0x0
    u32 mReqMSec;  // offset: 0x4
    bool mReqOn;  // offset: 0x8
    bool mPause;  // offset: 0x9
};

class cGameWeather
{
public:
    cGameWeather();
    void updateGameWeather();
    void reqWeatherID(u32 id);
    u32 getWeatherID() const;
private:
    u32 mWeatherID;  // offset: 0x0
    u32 mReqWeatherID;  // offset: 0x4
    bool mReqOn;  // offset: 0x8
};
